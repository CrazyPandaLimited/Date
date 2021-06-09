#include "Date.h"
#include <string.h>

#define NSAVE(dest) { dest = acc; acc = 0; }

enum class WeekInterpretation { none = 2, iso = 1, monday = 0, sunday = -7 };

namespace panda { namespace date {

struct MetaConsume {
    int cs;
    int consumed;
};

%%{
    machine parser;

    action digit {
        acc *= 10;
        acc += fc - '0';
    }

    action cent    { _date.year += acc * 100; acc = 0; }
    action year    { NSAVE(_date.year);        }
    action sec     { NSAVE(_date.sec);         }
    action min     { NSAVE(_date.min);         }
    action hour    { NSAVE(_date.hour);        }
    action hour_pm { _date.hour += 12;         }
    action day     { NSAVE(_date.mday);        }
    action wday    { NSAVE(_date.wday);        }
    action wday_s  { --acc; NSAVE(_date.wday); }
    action yday    { NSAVE(_date.mday);        }
    action week    { NSAVE(week);              }
    action month   { _date.mon = acc - 1; acc = 0; }
    action done    { fbreak; }

    action yr {
        if (acc <= 50) _date.year = 2000 + acc;
        else           _date.year = 1900 + acc;
        acc = 0;
    }

    nn         = digit{2} $digit;
    P_day_nn   = nn @day @done;
    P_AMPM     =  ('AM') | ('PM' @hour_pm);
    P_ampm     =  ('am') | ('pm' @hour_pm);
    P_wname    = ("Mon" | "Monday")    @{ _date.wday = 1; } |
                 ("Tue" | "Tuesday")   @{ _date.wday = 2; } |
                 ("Wed" | "Wednesday") @{ _date.wday = 3; } |
                 ("Thu" | "Thursday")  @{ _date.wday = 4; } |
                 ("Fri" | "Friday")    @{ _date.wday = 5; } |
                 ("Sat" | "Saturday")  @{ _date.wday = 6; } |
                 ("Sun" | "Sunday")    @{ _date.wday = 0; } ;

    P_mname  = ("Jan" | "January")   @{ _date.mon = 0; } |
               ("Feb" | "February")  @{ _date.mon = 1; } |
               ("Mar" | "March")     @{ _date.mon = 2; } |
               ("Apr" | "April")     @{ _date.mon = 3; } |
                "May"                @{ _date.mon = 4; } |
               ("Jun" | "June" )     @{ _date.mon = 5; } |
               ("Jul" | "July" )     @{ _date.mon = 6; } |
               ("Aug" | "August" )   @{ _date.mon = 7; } |
               ("Sep" | "September") @{ _date.mon = 8; } |
               ("Oct" | "October")   @{ _date.mon = 9; } |
               ("Nov" | "November")  @{ _date.mon = 10;} |
               ("Dec" | "December")  @{ _date.mon = 11;} ;


    p_AMPM     := P_AMPM @done;
    p_ampm     := P_ampm @done;
    p_sec      := nn @sec @done;
    p_min      := nn @min @done;
    p_hour     := nn @hour @done;
    p_hour_s   := (' ' | digit{1} $digit) digit{1} $digit @hour @done;
    p_hour_min := nn @hour ':' nn @min @done;
    p_hms      := nn @hour ':' nn @min ':' nn @sec @done;
    p_hmsAMPM  := nn @hour ':' nn @min ':' nn @sec ' '+ P_AMPM @done;
    p_mdy      := nn @month '/' nn @day '/' nn @yr @done;
    p_ymd      := digit{4} $digit @year '-' nn @month '-' nn @day @done;
    p_mdyhms   := nn @month '/' nn @day '/' nn @yr ' '+ nn @hour ':' nn @min ':' nn @sec @done;
    p_day      := nn @day @done;
    p_day3     := digit{3} $digit @yday @done;
    p_day_void := P_day_nn | (" " digit $digit) @day @done;
    p_wday     := digit{1} $digit @wday @done;
    p_wday_s   := digit{1} $digit @wday_s @done;
    p_wname    := P_wname %done;
    p_wnum     := nn >{ week = 0;} @week @done;
    p_month    := nn @month @done;
    p_mname    := P_mname %done;
    p_year     := digit{4} $digit @year @done;
    p_yr       := nn @yr @done;
    p_cent     := nn @cent @done;
    p_perc     := '%'  @done;
    p_space    := ' '*  %done;
}%%

%% write data;

static inline int _parse_str(int cs, const char* p, const char* pe, int& week, datetime& _date)  {
    // printf("_parse_str cs=%d\n", cs);
    const char* pb  = p;
    const char* eof = pe;
    uint64_t    acc = 0;

    %% write exec;


    // printf("_parse_str %s -> cs=%d, consumed=%d\n", pb, cs, p - pb);
    return p - pb;
}

%%{
    machine meta_parser;
    m_yr        = '%y' @{ p_cs = parser_en_p_yr;        fbreak; };
    m_AMPM      = '%p' @{ p_cs = parser_en_p_AMPM;      fbreak; };
    m_ampm      = '%P' @{ p_cs = parser_en_p_ampm;      fbreak; };
    m_year      = '%Y' @{ p_cs = parser_en_p_year;      fbreak; };
    m_cent      = '%C' @{ p_cs = parser_en_p_cent;      fbreak; };
    m_day       = '%d' @{ p_cs = parser_en_p_day;       fbreak; };
    m_day3      = '%j' @{ p_cs = parser_en_p_day3;      fbreak; };
    m_wday      = '%w' @{ p_cs = parser_en_p_wday;      fbreak; };
    m_wday_s    = '%u' @{ p_cs = parser_en_p_wday_s;    fbreak; };
    m_wname     = ('%a' | '%A') @{ p_cs = parser_en_p_wname; fbreak; };
    m_wnum_iso  = '%V' @{ p_cs = parser_en_p_wnum; week_interptetation = WeekInterpretation::iso;    fbreak; };
    m_wnum_mon  = '%W' @{ p_cs = parser_en_p_wnum; week_interptetation = WeekInterpretation::monday; fbreak; };
    m_wnum_sun  = '%U' @{ p_cs = parser_en_p_wnum; week_interptetation = WeekInterpretation::sunday; fbreak; };
    m_hour      = ('%H' | '%I') @{ p_cs = parser_en_p_hour;      fbreak; };
    m_hour_s    = ('%k' | '%l') @{ p_cs = parser_en_p_hour_s;    fbreak; };
    m_month     = '%m' @{ p_cs = parser_en_p_month;     fbreak; };
    m_mname     = ('%b' | '%B' | '%h')  @{ p_cs = parser_en_p_mname;     fbreak; };
    m_min       = '%M' @{ p_cs = parser_en_p_min;       fbreak; };
    m_sec       = '%S' @{ p_cs = parser_en_p_sec;       fbreak; };
    m_hour_min  = '%R' @{ p_cs = parser_en_p_hour_min;  fbreak; };
    m_mdyhms    = '%c' @{ p_cs = parser_en_p_mdyhms;    fbreak; };
    m_hmsAMPM   = '%r'  @{ p_cs = parser_en_p_hmsAMPM;       fbreak; };
    m_ymd       = '%F' @{ p_cs = parser_en_p_ymd;       fbreak; };
    m_hms       = ('%T' | '%X')  @{ p_cs = parser_en_p_hms;       fbreak; };
    m_mdy       = ('%D' | '%x')  @{ p_cs = parser_en_p_mdy;       fbreak; };
    m_perc      = '%%' @{ p_cs = parser_en_p_perc;      fbreak; };
    m_space_enc = ('%t' | '%n') @{ p_cs = parser_en_p_space;  fbreak; };
    m_space     = (' ' | '\t')+  @{ p_cs = parser_en_p_space; fbreak; };

    m_main := m_space | m_space_enc | m_perc | m_yr | m_AMPM | m_ampm | m_cent | m_day3 | m_mname |
              m_wnum_iso | m_wnum_mon | m_wnum_sun |
              m_year | m_month | m_day | m_wday | m_wday_s | m_wname | m_hour | m_hour_s | m_min | m_sec |
              m_hour_min | m_hms | m_mdy | m_mdyhms | m_hmsAMPM | m_ymd
           ;
}%%

%% write data;

static inline MetaConsume _parse_meta(const char* p, const char* pe, WeekInterpretation& week_interptetation)  {
    const char* pb     = p;
    const char* eof    = pe;
    int         cs     = meta_parser_en_m_main;
    int         p_cs   = 0;

    %% write exec;

    auto consumed = p - pb;
    // printf("_parse_meta '%s' p_cs=%d, c=%d, cs=%d\n", pb, p_cs, consumed, cs);
    return MetaConsume { p_cs, (int)consumed };
}

void Date::strptime (string_view str, string_view format) {
    memset(&_date, 0, sizeof(_date)); // reset all values
    _date.mday = 1;
    _error = errc::ok;
    _mksec = 0;

    int week = -1;
    WeekInterpretation week_interptetation = WeekInterpretation::none;

    const char* m_p = format.data();
    const char* m_e = m_p + format.length();
    const char* s_p = str.data();
    const char* s_e = s_p + str.length();

    while((m_p != m_e) && (s_p != s_e)) {
        // printf("cycle, meta='%s', str='%s'\n", m_p, s_p);
        auto meta_result = _parse_meta(m_p, m_e, week_interptetation);
        if (meta_result.cs) {
            int consumed = _parse_str(meta_result.cs, s_p, s_e, week, _date);
            if (consumed >= 0) {
                s_p += consumed;
            } else {
                _error = errc::parser_error;
                break;
            }
        } else {
            meta_result.consumed = 0;
            auto skip = *m_p == *s_p;
            // printf("...skip-char %d?\n", skip);
            if (*m_p++ != *s_p++) {
                // printf("char mismatch\n");
                _error = errc::parser_error;
                break;
            }
        }
        m_p += meta_result.consumed;
    }

    if (!(m_p == m_e && s_p == s_e)) { return; }
    switch (week_interptetation) {
        case WeekInterpretation::none: break;
        case WeekInterpretation::iso: _post_parse_week((unsigned)week); break;
        case WeekInterpretation::monday: ; /* fallthrough */
        case WeekInterpretation::sunday:
        if (!_date.wday) _date.wday = 1;
            auto days_since_christ = panda::time::christ_days(_date.year);
            int32_t beginning_weekday = days_since_christ % 7;

            //static constexpr const int32_t WEEK_DELTA[] = {6, 0, 1, 2, 3, 4, 5};
            //static constexpr const int32_t WEEK_DELTA[] = {-1, 0, 1, 2, 3, 4, 5};
            //auto delta = WEEK_DELTA[beginning_weekday];
            if (!beginning_weekday) beginning_weekday = (int)week_interptetation;   // for %U
            auto delta = ((beginning_weekday - 1) + 7) % 7;

            //printf("y = %d, wday = %d, delta = %d, beg = %d\n", _date.year, _date.wday, delta, beginning_weekday);
            _date.mday = week * 7  + (_date.wday - 1) - delta;
    }
}

}}
