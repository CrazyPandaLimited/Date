cmake_minimum_required(VERSION 3.0)
project(panda-date VERSION 2.1.1 LANGUAGES CXX)
enable_testing()

set(LIB_TYPE STATIC)

file(GLOB_RECURSE libSource RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/panda/*.cc")
add_library(date ${LIB_TYPE} ${libSource})
target_include_directories(date PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:include>
)
set_target_properties(date PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

find_program(ragel_bin ragel)
if (ragel_bin)
    foreach(fpath src/panda/date/parse-date src/panda/date/parse-relative)
        add_custom_command(
            OUTPUT  ${CMAKE_CURRENT_SOURCE_DIR}/${fpath}.cc
            COMMAND ragel -C -G2 ${fpath}.rl -o ${fpath}.cc
            DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${fpath}.rl
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        )
    endforeach()
endif()

find_package(panda-lib REQUIRED)
target_link_libraries(date panda::panda-lib)

add_library(panda::date ALIAS date)

########################tests#######################################
file(GLOB_RECURSE testSource RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "tests/*.cc")
list(FILTER testSource EXCLUDE REGEX "tests/main.cc")

add_library(tests STATIC EXCLUDE_FROM_ALL ${testSource})
target_link_libraries(tests PUBLIC date)

find_package(Catch2)
target_link_libraries(tests PUBLIC Catch2::Catch2)

########################ctests######################################
enable_testing()
add_executable(runtests ${testSource} "tests/main.cc")
target_link_libraries(runtests tests)
add_test(test-all runtests)

########################install#####################################
install(DIRECTORY src/ DESTINATION include FILES_MATCHING PATTERN "*.h")
install(TARGETS date EXPORT date-targets ARCHIVE DESTINATION lib)

install(EXPORT date-targets
    FILE panda-date-targets.cmake
    NAMESPACE panda::
    DESTINATION lib/cmake/panda-date
)

install(FILES panda-date-config.cmake DESTINATION lib/cmake/panda-date)
