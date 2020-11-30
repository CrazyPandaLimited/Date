#include <cstdlib>
#include <panda/time.h>
#include <panda/date.h>
#include <catch2/catch.hpp>

using namespace panda;
using namespace panda::date;
using namespace panda::time;

static int _init () {
    tzset("Europe/Moscow");
    return 0;
}
static int __init = _init();

#define TEMPZONE(name) TempZone tmpz(name); (void) tmpz;

struct TempZone {
    TimezoneSP old;

    TempZone (string_view name) {
        old = tzlocal();
        tzset(name);
    }

    ~TempZone () {
        tzset(old);
    }
};

static inline void is_approx (double testv, double v) {
    CHECK(abs(testv - v) < (double)0.000001);
}
