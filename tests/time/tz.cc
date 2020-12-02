#include "../test.h"

#define TEST(name) TEST_CASE("time-tz: " name, "[time-tz]")

TEST("available timezones(embed)") {
    auto list = available_timezones();
    CHECK(list.size() == 1212);
}

TEST("available timezones(system)") {
    if (!getenv("TEST_FULL")) return;
    auto old = tzdir();
    use_system_timezones();

    auto list = available_timezones();
    CHECK(list.size() > 0);

    tzdir(old);
}
