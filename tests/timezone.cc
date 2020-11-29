#include "test.h"

#define TEST(name) TEST_CASE("timezone: " name, "[timezone]")

TEST("local") {
    for (auto& date : std::vector<Date>{Date("2014-01-01 00:00:00"), Date("2014-01-01 00:00:00", nullptr), Date("2014-01-01 00:00:00", tzget(""))}) {
        CHECK(date.timezone() == tzlocal());
    }
}

TEST("with zone") {
    Date date("2014-01-01 00:00:00", tzget("America/New_York"));
    CHECK(date.timezone() == tzget("America/New_York"));
    CHECK(date.timezone()->name == "America/New_York");
    Date b = Date("2014-01-01 00:00:00");
    CHECK(date.epoch() > b.epoch());
    CHECK(date > b);
    CHECK(date != b);
    CHECK(date.to_string() == b.to_string());
}

TEST("clone with tz") {
    Date src("2014-01-01 00:00:00", tzget("America/New_York"));
    SECTION("with local") {
        auto date = src.clone(-1, -1, -1, -1, -1, -1, -1, -1, tzget(""));
        CHECK(date.timezone() == tzlocal());
        CHECK(date == Date("2014-01-01 00:00:00"));
        CHECK(date != src);
        CHECK(date.to_string() == "2014-01-01 00:00:00");
    }
    SECTION("with other") {
        Date date = src.clone(-1, -1, -1, -1, -1, -1, -1, -1, tzget("Europe/Kiev"));
        CHECK(date.timezone()->name == "Europe/Kiev");
        CHECK(date.to_string(Date::Format::iso8601) == "2014-01-01T00:00:00+02");
    }
}

TEST("to_timezone") {
    SECTION("local") {
        Date src("2014-01-01 00:00:00", tzget("America/New_York"));
        auto date = src;
        date.to_timezone(tzlocal());
        CHECK(date.timezone() == tzlocal());
        CHECK(date.epoch() == src.epoch());
    }
    SECTION("other") {
        Date src("2014-01-01 00:00:00", tzget("America/New_York"));
        auto date = src;
        date.to_timezone(tzget("Australia/Melbourne"));
        CHECK(date.epoch() == src.epoch());
        CHECK(date.to_string() != src.to_string());
    }
}

TEST("timezone()") {
    Date src("2014-01-01 00:00:00", tzget("America/New_York"));
    auto date = src;
    date.timezone(tzget("Australia/Melbourne"));
    CHECK(date.epoch() != src.epoch());
    CHECK(date.to_string() == src.to_string());
}
