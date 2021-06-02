#include "../test.h"

#define TEST(name) TEST_CASE("strptime: " name, "[strptime]")

static void test (string name, string_view str, string_view format,  string_view expected) {
    SECTION(name) {
        Date d1(str, format);
        Date d2(expected);
        CHECK(d1 == d2);
        CHECK(d1.epoch() == d2.epoch());
    }
}

static void test_err(string name, string_view str, string_view format) {
    SECTION(name) {
        Date d(str, format);
        CHECK(d.error());
    }
}

TEST("parse") {
    test("simple", "03:04:00 2019-02-02", "%H:%M:%S %Y-%m-%d" ,"2019-02-02 03:04:00");
    test("simple/am", "03:04:00 AM 2019-02-02", "%H:%M:%S %p %Y-%m-%d" ,"2019-02-02 03:04:00");
    test("simple/pm", "03:04:00 PM 2019-02-02", "%H:%M:%S %p %Y-%m-%d" ,"2019-02-02 15:04:00");
    test("simple/space", "03:04:00 2019-02-02", "%H:%M:%S%n%Y-%m-%d" ,"2019-02-02 03:04:00");
    test("simple/no-spaces", "03:04:002019-02-02", "%H:%M:%S%Y-%m-%d" ,"2019-02-02 03:04:00");
    test("simple/multi-spaces", "03:04:00    2019-02-02", "%H:%M:%S %Y-%m-%d" ,"2019-02-02 03:04:00");
    test_err("simple/error", "aaa", "bbb");
    test("percent", "%03:04:00 2019-02-02", "%%%H:%M:%S %Y-%m-%d" ,"2019-02-02 03:04:00");
    test("%R aka %H:%M", "03:04:00 2019-02-02", "%R:%S %Y-%m-%d" ,"2019-02-02 03:04:00");
    test("%T aka %H:%M:%S and %y", "03:04:00 99-02-02", "%T %y-%m-%d" ,"1999-02-02 03:04:00");
    test("%D aka %m/%d/%y", "03:04:00 02/02/99", "%T %D" ,"1999-02-02 03:04:00");
    test("%c aka %m/%d/%y %H:%M:%S", "02/02/99 03:04:00", "%c" ,"1999-02-02 03:04:00");
    test("%r aka %I:%M:%S %p", "02/02/99 03:04:00 PM", "%D %r" ,"1999-02-02 15:04:00");
    test("%C century", "15 02-03", "%C %m-%d" ,"1500-02-03");
    test("%j day of the year", "032 99", "%j %y" ,"1999-02-01");
    test("%w week day", "2-06-99", "%w-%m-%y" ,"1999-06-01");
    test("%A week name", "Tue-06-99", "%A-%m-%y" ,"1999-06-01");
    //test("%A week name/2", "Wed-06-99", "%A-%m-%y" ,"1999-06-02");
    test("%b month name", "02-March-99", "%d-%b-%y" ,"1999-03-02");
    test("%W week number", "2014-W02-5", "%Y-W%W-%w" ,"2014-01-10");
    //test("%U shifted week number", "2014-W02-4", "%Y-W%W-%w" ,"2014-01-10");
}
