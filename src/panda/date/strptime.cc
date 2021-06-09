
#line 1 "src/panda/date/strptime.rl"
#include "Date.h"
#include <string.h>

#define NSAVE(dest) { dest = acc; acc = 0; }

enum class WeekInterpretation { none = 2, iso = 1, monday = 0, sunday = -7 };

namespace panda { namespace date {

struct MetaConsume {
    int cs;
    int consumed;
};


#line 92 "src/panda/date/strptime.rl"



#line 23 "src/panda/date/strptime.cc"
static const int parser_start = 175;
static const int parser_first_final = 175;
static const int parser_error = 0;

static const int parser_en_p_AMPM = 1;
static const int parser_en_p_ampm = 4;
static const int parser_en_p_sec = 7;
static const int parser_en_p_min = 9;
static const int parser_en_p_hour = 11;
static const int parser_en_p_hour_min = 13;
static const int parser_en_p_hms = 18;
static const int parser_en_p_hmsAMPM = 26;
static const int parser_en_p_mdy = 38;
static const int parser_en_p_ymd = 46;
static const int parser_en_p_mdyhms = 56;
static const int parser_en_p_day = 73;
static const int parser_en_p_day3 = 75;
static const int parser_en_p_day_void = 78;
static const int parser_en_p_wday = 80;
static const int parser_en_p_wname = 81;
static const int parser_en_p_wnum = 116;
static const int parser_en_p_month = 118;
static const int parser_en_p_mname = 120;
static const int parser_en_p_year = 166;
static const int parser_en_p_yr = 170;
static const int parser_en_p_cent = 172;
static const int parser_en_p_perc = 174;
static const int parser_en_p_space = 175;


#line 95 "src/panda/date/strptime.rl"

static inline int _parse_str(int cs, const char* p, const char* pe, int& week, datetime& _date)  {
    // printf("_parse_str cs=%d\n", cs);
    const char* pb  = p;
    const char* eof = pe;
    uint64_t    acc = 0;

    
#line 63 "src/panda/date/strptime.cc"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
	if ( (*p) == 32 )
		goto st175;
	goto st0;
st0:
cs = 0;
	goto _out;
case 1:
	switch( (*p) ) {
		case 65: goto st2;
		case 80: goto st3;
	}
	goto st0;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
	if ( (*p) == 77 )
		goto tr3;
	goto st0;
tr3:
#line 34 "src/panda/date/strptime.rl"
	{ {p++; cs = 176; goto _out;} }
	goto st176;
tr4:
#line 28 "src/panda/date/strptime.rl"
	{ _date.hour += 12;  }
#line 34 "src/panda/date/strptime.rl"
	{ {p++; cs = 176; goto _out;} }
	goto st176;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
#line 106 "src/panda/date/strptime.cc"
	goto st0;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
	if ( (*p) == 77 )
		goto tr4;
	goto st0;
case 4:
	switch( (*p) ) {
		case 97: goto st5;
		case 112: goto st6;
	}
	goto st0;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
	if ( (*p) == 109 )
		goto tr7;
	goto st0;
tr7:
#line 34 "src/panda/date/strptime.rl"
	{ {p++; cs = 177; goto _out;} }
	goto st177;
tr8:
#line 28 "src/panda/date/strptime.rl"
	{ _date.hour += 12;  }
#line 34 "src/panda/date/strptime.rl"
	{ {p++; cs = 177; goto _out;} }
	goto st177;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
#line 142 "src/panda/date/strptime.cc"
	goto st0;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
	if ( (*p) == 109 )
		goto tr8;
	goto st0;
case 7:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr9;
	goto st0;
tr9:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st8;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
#line 166 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr10;
	goto st0;
tr10:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 25 "src/panda/date/strptime.rl"
	{ NSAVE(_date.sec);  }
#line 34 "src/panda/date/strptime.rl"
	{ {p++; cs = 178; goto _out;} }
	goto st178;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
#line 185 "src/panda/date/strptime.cc"
	goto st0;
case 9:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr11;
	goto st0;
tr11:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st10;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
#line 202 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr12;
	goto st0;
tr12:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 26 "src/panda/date/strptime.rl"
	{ NSAVE(_date.min);  }
#line 34 "src/panda/date/strptime.rl"
	{ {p++; cs = 179; goto _out;} }
	goto st179;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
#line 221 "src/panda/date/strptime.cc"
	goto st0;
case 11:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr13;
	goto st0;
tr13:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st12;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
#line 238 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr14;
	goto st0;
tr14:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 27 "src/panda/date/strptime.rl"
	{ NSAVE(_date.hour); }
#line 34 "src/panda/date/strptime.rl"
	{ {p++; cs = 180; goto _out;} }
	goto st180;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
#line 257 "src/panda/date/strptime.cc"
	goto st0;
case 13:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr15;
	goto st0;
tr15:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st14;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
#line 274 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr16;
	goto st0;
tr16:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 27 "src/panda/date/strptime.rl"
	{ NSAVE(_date.hour); }
	goto st15;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
#line 291 "src/panda/date/strptime.cc"
	if ( (*p) == 58 )
		goto st16;
	goto st0;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr18;
	goto st0;
tr18:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st17;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
#line 313 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr19;
	goto st0;
tr19:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 26 "src/panda/date/strptime.rl"
	{ NSAVE(_date.min);  }
#line 34 "src/panda/date/strptime.rl"
	{ {p++; cs = 181; goto _out;} }
	goto st181;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
#line 332 "src/panda/date/strptime.cc"
	goto st0;
case 18:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr20;
	goto st0;
tr20:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st19;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
#line 349 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr21;
	goto st0;
tr21:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 27 "src/panda/date/strptime.rl"
	{ NSAVE(_date.hour); }
	goto st20;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
#line 366 "src/panda/date/strptime.cc"
	if ( (*p) == 58 )
		goto st21;
	goto st0;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr23;
	goto st0;
tr23:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st22;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
#line 388 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr24;
	goto st0;
tr24:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 26 "src/panda/date/strptime.rl"
	{ NSAVE(_date.min);  }
	goto st23;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
#line 405 "src/panda/date/strptime.cc"
	if ( (*p) == 58 )
		goto st24;
	goto st0;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr26;
	goto st0;
tr26:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st25;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
#line 427 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr27;
	goto st0;
tr27:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 25 "src/panda/date/strptime.rl"
	{ NSAVE(_date.sec);  }
#line 34 "src/panda/date/strptime.rl"
	{ {p++; cs = 182; goto _out;} }
	goto st182;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
#line 446 "src/panda/date/strptime.cc"
	goto st0;
case 26:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr28;
	goto st0;
tr28:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st27;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
#line 463 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr29;
	goto st0;
tr29:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 27 "src/panda/date/strptime.rl"
	{ NSAVE(_date.hour); }
	goto st28;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
#line 480 "src/panda/date/strptime.cc"
	if ( (*p) == 58 )
		goto st29;
	goto st0;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr31;
	goto st0;
tr31:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st30;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
#line 502 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr32;
	goto st0;
tr32:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 26 "src/panda/date/strptime.rl"
	{ NSAVE(_date.min);  }
	goto st31;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
#line 519 "src/panda/date/strptime.cc"
	if ( (*p) == 58 )
		goto st32;
	goto st0;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr34;
	goto st0;
tr34:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st33;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
#line 541 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr35;
	goto st0;
tr35:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 25 "src/panda/date/strptime.rl"
	{ NSAVE(_date.sec);  }
	goto st34;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
#line 558 "src/panda/date/strptime.cc"
	if ( (*p) == 32 )
		goto st35;
	goto st0;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
	switch( (*p) ) {
		case 32: goto st35;
		case 65: goto st36;
		case 80: goto st37;
	}
	goto st0;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
	if ( (*p) == 77 )
		goto tr39;
	goto st0;
tr39:
#line 34 "src/panda/date/strptime.rl"
	{ {p++; cs = 183; goto _out;} }
	goto st183;
tr40:
#line 28 "src/panda/date/strptime.rl"
	{ _date.hour += 12;  }
#line 34 "src/panda/date/strptime.rl"
	{ {p++; cs = 183; goto _out;} }
	goto st183;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
#line 593 "src/panda/date/strptime.cc"
	goto st0;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
	if ( (*p) == 77 )
		goto tr40;
	goto st0;
case 38:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr41;
	goto st0;
tr41:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st39;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
#line 617 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr42;
	goto st0;
tr42:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 33 "src/panda/date/strptime.rl"
	{ _date.mon = acc - 1; acc = 0; }
	goto st40;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
#line 634 "src/panda/date/strptime.cc"
	if ( (*p) == 47 )
		goto st41;
	goto st0;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr44;
	goto st0;
tr44:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st42;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
#line 656 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr45;
	goto st0;
tr45:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 29 "src/panda/date/strptime.rl"
	{ NSAVE(_date.mday); }
	goto st43;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
#line 673 "src/panda/date/strptime.cc"
	if ( (*p) == 47 )
		goto st44;
	goto st0;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr47;
	goto st0;
tr47:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st45;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
#line 695 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr48;
	goto st0;
tr48:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 36 "src/panda/date/strptime.rl"
	{
        if (acc <= 50) _date.year = 2000 + acc;
        else           _date.year = 1900 + acc;
        acc = 0;
    }
#line 34 "src/panda/date/strptime.rl"
	{ {p++; cs = 184; goto _out;} }
	goto st184;
st184:
	if ( ++p == pe )
		goto _test_eof184;
case 184:
#line 718 "src/panda/date/strptime.cc"
	goto st0;
case 46:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr49;
	goto st0;
tr49:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st47;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
#line 735 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr50;
	goto st0;
tr50:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st48;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
#line 750 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr51;
	goto st0;
tr51:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st49;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
#line 765 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr52;
	goto st0;
tr52:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 24 "src/panda/date/strptime.rl"
	{ NSAVE(_date.year); }
	goto st50;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
#line 782 "src/panda/date/strptime.cc"
	if ( (*p) == 45 )
		goto st51;
	goto st0;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr54;
	goto st0;
tr54:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st52;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
#line 804 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr55;
	goto st0;
tr55:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 33 "src/panda/date/strptime.rl"
	{ _date.mon = acc - 1; acc = 0; }
	goto st53;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
#line 821 "src/panda/date/strptime.cc"
	if ( (*p) == 45 )
		goto st54;
	goto st0;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr57;
	goto st0;
tr57:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st55;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
#line 843 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr58;
	goto st0;
tr58:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 29 "src/panda/date/strptime.rl"
	{ NSAVE(_date.mday); }
#line 34 "src/panda/date/strptime.rl"
	{ {p++; cs = 185; goto _out;} }
	goto st185;
st185:
	if ( ++p == pe )
		goto _test_eof185;
case 185:
#line 862 "src/panda/date/strptime.cc"
	goto st0;
case 56:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr59;
	goto st0;
tr59:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st57;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
#line 879 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr60;
	goto st0;
tr60:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 33 "src/panda/date/strptime.rl"
	{ _date.mon = acc - 1; acc = 0; }
	goto st58;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
#line 896 "src/panda/date/strptime.cc"
	if ( (*p) == 47 )
		goto st59;
	goto st0;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr62;
	goto st0;
tr62:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st60;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
#line 918 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr63;
	goto st0;
tr63:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 29 "src/panda/date/strptime.rl"
	{ NSAVE(_date.mday); }
	goto st61;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
#line 935 "src/panda/date/strptime.cc"
	if ( (*p) == 47 )
		goto st62;
	goto st0;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr65;
	goto st0;
tr65:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st63;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
#line 957 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr66;
	goto st0;
tr66:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 36 "src/panda/date/strptime.rl"
	{
        if (acc <= 50) _date.year = 2000 + acc;
        else           _date.year = 1900 + acc;
        acc = 0;
    }
	goto st64;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
#line 978 "src/panda/date/strptime.cc"
	if ( (*p) == 32 )
		goto st65;
	goto st0;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
	if ( (*p) == 32 )
		goto st65;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr68;
	goto st0;
tr68:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st66;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
#line 1002 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr69;
	goto st0;
tr69:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 27 "src/panda/date/strptime.rl"
	{ NSAVE(_date.hour); }
	goto st67;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
#line 1019 "src/panda/date/strptime.cc"
	if ( (*p) == 58 )
		goto st68;
	goto st0;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr71;
	goto st0;
tr71:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st69;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
#line 1041 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr72;
	goto st0;
tr72:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 26 "src/panda/date/strptime.rl"
	{ NSAVE(_date.min);  }
	goto st70;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
#line 1058 "src/panda/date/strptime.cc"
	if ( (*p) == 58 )
		goto st71;
	goto st0;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr74;
	goto st0;
tr74:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st72;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
#line 1080 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr75;
	goto st0;
tr75:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 25 "src/panda/date/strptime.rl"
	{ NSAVE(_date.sec);  }
#line 34 "src/panda/date/strptime.rl"
	{ {p++; cs = 186; goto _out;} }
	goto st186;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
#line 1099 "src/panda/date/strptime.cc"
	goto st0;
case 73:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr76;
	goto st0;
tr76:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st74;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
#line 1116 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr77;
	goto st0;
tr77:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 29 "src/panda/date/strptime.rl"
	{ NSAVE(_date.mday); }
#line 34 "src/panda/date/strptime.rl"
	{ {p++; cs = 187; goto _out;} }
	goto st187;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
#line 1135 "src/panda/date/strptime.cc"
	goto st0;
case 75:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr78;
	goto st0;
tr78:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st76;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
#line 1152 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr79;
	goto st0;
tr79:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st77;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
#line 1167 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr80;
	goto st0;
tr80:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 31 "src/panda/date/strptime.rl"
	{ NSAVE(_date.mday); }
#line 34 "src/panda/date/strptime.rl"
	{ {p++; cs = 188; goto _out;} }
	goto st188;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
#line 1186 "src/panda/date/strptime.cc"
	goto st0;
case 78:
	if ( (*p) == 32 )
		goto st79;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr82;
	goto st0;
tr82:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st79;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
#line 1205 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr83;
	goto st0;
tr83:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 29 "src/panda/date/strptime.rl"
	{ NSAVE(_date.mday); }
#line 34 "src/panda/date/strptime.rl"
	{ {p++; cs = 189; goto _out;} }
	goto st189;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
#line 1224 "src/panda/date/strptime.cc"
	goto st0;
case 80:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr84;
	goto st0;
tr84:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 30 "src/panda/date/strptime.rl"
	{ NSAVE(_date.wday)  }
#line 34 "src/panda/date/strptime.rl"
	{ {p++; cs = 190; goto _out;} }
	goto st190;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
#line 1245 "src/panda/date/strptime.cc"
	goto st0;
case 81:
	switch( (*p) ) {
		case 70: goto st82;
		case 77: goto st86;
		case 83: goto st90;
		case 84: goto st99;
		case 87: goto st109;
	}
	goto st0;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
	if ( (*p) == 114 )
		goto st83;
	goto st0;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
	if ( (*p) == 105 )
		goto tr91;
	goto st0;
tr91:
#line 50 "src/panda/date/strptime.rl"
	{ _date.wday = 5; }
	goto st191;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
#line 1278 "src/panda/date/strptime.cc"
	if ( (*p) == 100 )
		goto st84;
	goto st0;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
	if ( (*p) == 97 )
		goto st85;
	goto st0;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
	if ( (*p) == 121 )
		goto tr93;
	goto st0;
tr93:
#line 50 "src/panda/date/strptime.rl"
	{ _date.wday = 5; }
	goto st192;
tr97:
#line 46 "src/panda/date/strptime.rl"
	{ _date.wday = 1; }
	goto st192;
tr104:
#line 51 "src/panda/date/strptime.rl"
	{ _date.wday = 6; }
	goto st192;
tr107:
#line 52 "src/panda/date/strptime.rl"
	{ _date.wday = 0; }
	goto st192;
tr114:
#line 49 "src/panda/date/strptime.rl"
	{ _date.wday = 4; }
	goto st192;
tr118:
#line 47 "src/panda/date/strptime.rl"
	{ _date.wday = 2; }
	goto st192;
tr125:
#line 48 "src/panda/date/strptime.rl"
	{ _date.wday = 3; }
	goto st192;
st192:
	if ( ++p == pe )
		goto _test_eof192;
case 192:
#line 1328 "src/panda/date/strptime.cc"
	goto st0;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
	if ( (*p) == 111 )
		goto st87;
	goto st0;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
	if ( (*p) == 110 )
		goto tr95;
	goto st0;
tr95:
#line 46 "src/panda/date/strptime.rl"
	{ _date.wday = 1; }
	goto st193;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
#line 1352 "src/panda/date/strptime.cc"
	if ( (*p) == 100 )
		goto st88;
	goto st0;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
	if ( (*p) == 97 )
		goto st89;
	goto st0;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
	if ( (*p) == 121 )
		goto tr97;
	goto st0;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
	switch( (*p) ) {
		case 97: goto st91;
		case 117: goto st96;
	}
	goto st0;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
	if ( (*p) == 116 )
		goto tr100;
	goto st0;
tr100:
#line 51 "src/panda/date/strptime.rl"
	{ _date.wday = 6; }
	goto st194;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
#line 1394 "src/panda/date/strptime.cc"
	if ( (*p) == 117 )
		goto st92;
	goto st0;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
	if ( (*p) == 114 )
		goto st93;
	goto st0;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
	if ( (*p) == 100 )
		goto st94;
	goto st0;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
	if ( (*p) == 97 )
		goto st95;
	goto st0;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
	if ( (*p) == 121 )
		goto tr104;
	goto st0;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
	if ( (*p) == 110 )
		goto tr105;
	goto st0;
tr105:
#line 52 "src/panda/date/strptime.rl"
	{ _date.wday = 0; }
	goto st195;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
#line 1441 "src/panda/date/strptime.cc"
	if ( (*p) == 100 )
		goto st97;
	goto st0;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
	if ( (*p) == 97 )
		goto st98;
	goto st0;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
	if ( (*p) == 121 )
		goto tr107;
	goto st0;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
	switch( (*p) ) {
		case 104: goto st100;
		case 117: goto st105;
	}
	goto st0;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
	if ( (*p) == 117 )
		goto tr110;
	goto st0;
tr110:
#line 49 "src/panda/date/strptime.rl"
	{ _date.wday = 4; }
	goto st196;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
#line 1483 "src/panda/date/strptime.cc"
	if ( (*p) == 114 )
		goto st101;
	goto st0;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
	if ( (*p) == 115 )
		goto st102;
	goto st0;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
	if ( (*p) == 100 )
		goto st103;
	goto st0;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
	if ( (*p) == 97 )
		goto st104;
	goto st0;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
	if ( (*p) == 121 )
		goto tr114;
	goto st0;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
	if ( (*p) == 101 )
		goto tr115;
	goto st0;
tr115:
#line 47 "src/panda/date/strptime.rl"
	{ _date.wday = 2; }
	goto st197;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
#line 1530 "src/panda/date/strptime.cc"
	if ( (*p) == 115 )
		goto st106;
	goto st0;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
	if ( (*p) == 100 )
		goto st107;
	goto st0;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
	if ( (*p) == 97 )
		goto st108;
	goto st0;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
	if ( (*p) == 121 )
		goto tr118;
	goto st0;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
	if ( (*p) == 101 )
		goto st110;
	goto st0;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
	if ( (*p) == 100 )
		goto tr120;
	goto st0;
tr120:
#line 48 "src/panda/date/strptime.rl"
	{ _date.wday = 3; }
	goto st198;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
#line 1577 "src/panda/date/strptime.cc"
	if ( (*p) == 110 )
		goto st111;
	goto st0;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
	if ( (*p) == 101 )
		goto st112;
	goto st0;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
	if ( (*p) == 115 )
		goto st113;
	goto st0;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
	if ( (*p) == 100 )
		goto st114;
	goto st0;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
	if ( (*p) == 97 )
		goto st115;
	goto st0;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
	if ( (*p) == 121 )
		goto tr125;
	goto st0;
case 116:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr126;
	goto st0;
tr126:
#line 84 "src/panda/date/strptime.rl"
	{ week = 0;}
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st117;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
#line 1633 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr127;
	goto st0;
tr127:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 32 "src/panda/date/strptime.rl"
	{ NSAVE(week); }
#line 34 "src/panda/date/strptime.rl"
	{ {p++; cs = 199; goto _out;} }
	goto st199;
st199:
	if ( ++p == pe )
		goto _test_eof199;
case 199:
#line 1652 "src/panda/date/strptime.cc"
	goto st0;
case 118:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr128;
	goto st0;
tr128:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st119;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
#line 1669 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr129;
	goto st0;
tr129:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 33 "src/panda/date/strptime.rl"
	{ _date.mon = acc - 1; acc = 0; }
#line 34 "src/panda/date/strptime.rl"
	{ {p++; cs = 200; goto _out;} }
	goto st200;
st200:
	if ( ++p == pe )
		goto _test_eof200;
case 200:
#line 1688 "src/panda/date/strptime.cc"
	goto st0;
case 120:
	switch( (*p) ) {
		case 65: goto st121;
		case 68: goto st127;
		case 70: goto st133;
		case 74: goto st139;
		case 77: goto st145;
		case 78: goto st148;
		case 79: goto st154;
		case 83: goto st159;
	}
	goto st0;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
	switch( (*p) ) {
		case 112: goto st122;
		case 117: goto st124;
	}
	goto st0;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
	if ( (*p) == 114 )
		goto tr140;
	goto st0;
tr140:
#line 57 "src/panda/date/strptime.rl"
	{ _date.mon = 3; }
	goto st201;
st201:
	if ( ++p == pe )
		goto _test_eof201;
case 201:
#line 1726 "src/panda/date/strptime.cc"
	if ( (*p) == 105 )
		goto st123;
	goto st0;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
	if ( (*p) == 108 )
		goto tr141;
	goto st0;
tr141:
#line 57 "src/panda/date/strptime.rl"
	{ _date.mon = 3; }
	goto st202;
tr144:
#line 61 "src/panda/date/strptime.rl"
	{ _date.mon = 7; }
	goto st202;
tr150:
#line 65 "src/panda/date/strptime.rl"
	{ _date.mon = 11;}
	goto st202;
tr156:
#line 55 "src/panda/date/strptime.rl"
	{ _date.mon = 1; }
	goto st202;
tr162:
#line 54 "src/panda/date/strptime.rl"
	{ _date.mon = 0; }
	goto st202;
tr209:
#line 60 "src/panda/date/strptime.rl"
	{ _date.mon = 6; }
	goto st202;
tr210:
#line 59 "src/panda/date/strptime.rl"
	{ _date.mon = 5; }
	goto st202;
tr168:
#line 56 "src/panda/date/strptime.rl"
	{ _date.mon = 2; }
	goto st202;
tr167:
#line 58 "src/panda/date/strptime.rl"
	{ _date.mon = 4; }
	goto st202;
tr174:
#line 64 "src/panda/date/strptime.rl"
	{ _date.mon = 10;}
	goto st202;
tr179:
#line 63 "src/panda/date/strptime.rl"
	{ _date.mon = 9; }
	goto st202;
tr186:
#line 62 "src/panda/date/strptime.rl"
	{ _date.mon = 8; }
	goto st202;
st202:
	if ( ++p == pe )
		goto _test_eof202;
case 202:
#line 1789 "src/panda/date/strptime.cc"
	goto st0;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
	if ( (*p) == 103 )
		goto tr142;
	goto st0;
tr142:
#line 61 "src/panda/date/strptime.rl"
	{ _date.mon = 7; }
	goto st203;
st203:
	if ( ++p == pe )
		goto _test_eof203;
case 203:
#line 1806 "src/panda/date/strptime.cc"
	if ( (*p) == 117 )
		goto st125;
	goto st0;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
	if ( (*p) == 115 )
		goto st126;
	goto st0;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
	if ( (*p) == 116 )
		goto tr144;
	goto st0;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
	if ( (*p) == 101 )
		goto st128;
	goto st0;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
	if ( (*p) == 99 )
		goto tr146;
	goto st0;
tr146:
#line 65 "src/panda/date/strptime.rl"
	{ _date.mon = 11;}
	goto st204;
st204:
	if ( ++p == pe )
		goto _test_eof204;
case 204:
#line 1846 "src/panda/date/strptime.cc"
	if ( (*p) == 101 )
		goto st129;
	goto st0;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	if ( (*p) == 109 )
		goto st130;
	goto st0;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
	if ( (*p) == 98 )
		goto st131;
	goto st0;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
	if ( (*p) == 101 )
		goto st132;
	goto st0;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
	if ( (*p) == 114 )
		goto tr150;
	goto st0;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
	if ( (*p) == 101 )
		goto st134;
	goto st0;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
	if ( (*p) == 98 )
		goto tr152;
	goto st0;
tr152:
#line 55 "src/panda/date/strptime.rl"
	{ _date.mon = 1; }
	goto st205;
st205:
	if ( ++p == pe )
		goto _test_eof205;
case 205:
#line 1900 "src/panda/date/strptime.cc"
	if ( (*p) == 114 )
		goto st135;
	goto st0;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
	if ( (*p) == 117 )
		goto st136;
	goto st0;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
	if ( (*p) == 97 )
		goto st137;
	goto st0;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
	if ( (*p) == 114 )
		goto st138;
	goto st0;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
	if ( (*p) == 121 )
		goto tr156;
	goto st0;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
	switch( (*p) ) {
		case 97: goto st140;
		case 117: goto st144;
	}
	goto st0;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
	if ( (*p) == 110 )
		goto tr159;
	goto st0;
tr159:
#line 54 "src/panda/date/strptime.rl"
	{ _date.mon = 0; }
	goto st206;
st206:
	if ( ++p == pe )
		goto _test_eof206;
case 206:
#line 1956 "src/panda/date/strptime.cc"
	if ( (*p) == 117 )
		goto st141;
	goto st0;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
	if ( (*p) == 97 )
		goto st142;
	goto st0;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
	if ( (*p) == 114 )
		goto st143;
	goto st0;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
	if ( (*p) == 121 )
		goto tr162;
	goto st0;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
	switch( (*p) ) {
		case 108: goto tr163;
		case 110: goto tr164;
	}
	goto st0;
tr163:
#line 60 "src/panda/date/strptime.rl"
	{ _date.mon = 6; }
	goto st207;
st207:
	if ( ++p == pe )
		goto _test_eof207;
case 207:
#line 1998 "src/panda/date/strptime.cc"
	if ( (*p) == 121 )
		goto tr209;
	goto st0;
tr164:
#line 59 "src/panda/date/strptime.rl"
	{ _date.mon = 5; }
	goto st208;
st208:
	if ( ++p == pe )
		goto _test_eof208;
case 208:
#line 2010 "src/panda/date/strptime.cc"
	if ( (*p) == 101 )
		goto tr210;
	goto st0;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
	if ( (*p) == 97 )
		goto st146;
	goto st0;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
	switch( (*p) ) {
		case 114: goto tr166;
		case 121: goto tr167;
	}
	goto st0;
tr166:
#line 56 "src/panda/date/strptime.rl"
	{ _date.mon = 2; }
	goto st209;
st209:
	if ( ++p == pe )
		goto _test_eof209;
case 209:
#line 2038 "src/panda/date/strptime.cc"
	if ( (*p) == 99 )
		goto st147;
	goto st0;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
	if ( (*p) == 104 )
		goto tr168;
	goto st0;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
	if ( (*p) == 111 )
		goto st149;
	goto st0;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
	if ( (*p) == 118 )
		goto tr170;
	goto st0;
tr170:
#line 64 "src/panda/date/strptime.rl"
	{ _date.mon = 10;}
	goto st210;
st210:
	if ( ++p == pe )
		goto _test_eof210;
case 210:
#line 2071 "src/panda/date/strptime.cc"
	if ( (*p) == 101 )
		goto st150;
	goto st0;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
	if ( (*p) == 109 )
		goto st151;
	goto st0;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
	if ( (*p) == 98 )
		goto st152;
	goto st0;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
	if ( (*p) == 101 )
		goto st153;
	goto st0;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
	if ( (*p) == 114 )
		goto tr174;
	goto st0;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
	if ( (*p) == 99 )
		goto st155;
	goto st0;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
	if ( (*p) == 116 )
		goto tr176;
	goto st0;
tr176:
#line 63 "src/panda/date/strptime.rl"
	{ _date.mon = 9; }
	goto st211;
st211:
	if ( ++p == pe )
		goto _test_eof211;
case 211:
#line 2125 "src/panda/date/strptime.cc"
	if ( (*p) == 111 )
		goto st156;
	goto st0;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
	if ( (*p) == 98 )
		goto st157;
	goto st0;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
	if ( (*p) == 101 )
		goto st158;
	goto st0;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
	if ( (*p) == 114 )
		goto tr179;
	goto st0;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
	if ( (*p) == 101 )
		goto st160;
	goto st0;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
	if ( (*p) == 112 )
		goto tr181;
	goto st0;
tr181:
#line 62 "src/panda/date/strptime.rl"
	{ _date.mon = 8; }
	goto st212;
st212:
	if ( ++p == pe )
		goto _test_eof212;
case 212:
#line 2172 "src/panda/date/strptime.cc"
	if ( (*p) == 116 )
		goto st161;
	goto st0;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
	if ( (*p) == 101 )
		goto st162;
	goto st0;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
	if ( (*p) == 109 )
		goto st163;
	goto st0;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
	if ( (*p) == 98 )
		goto st164;
	goto st0;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
	if ( (*p) == 101 )
		goto st165;
	goto st0;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
	if ( (*p) == 114 )
		goto tr186;
	goto st0;
case 166:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr187;
	goto st0;
tr187:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st167;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
#line 2226 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr188;
	goto st0;
tr188:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st168;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
#line 2241 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr189;
	goto st0;
tr189:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st169;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
#line 2256 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr190;
	goto st0;
tr190:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 24 "src/panda/date/strptime.rl"
	{ NSAVE(_date.year); }
#line 34 "src/panda/date/strptime.rl"
	{ {p++; cs = 213; goto _out;} }
	goto st213;
st213:
	if ( ++p == pe )
		goto _test_eof213;
case 213:
#line 2275 "src/panda/date/strptime.cc"
	goto st0;
case 170:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr191;
	goto st0;
tr191:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st171;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
#line 2292 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr192;
	goto st0;
tr192:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 36 "src/panda/date/strptime.rl"
	{
        if (acc <= 50) _date.year = 2000 + acc;
        else           _date.year = 1900 + acc;
        acc = 0;
    }
#line 34 "src/panda/date/strptime.rl"
	{ {p++; cs = 214; goto _out;} }
	goto st214;
st214:
	if ( ++p == pe )
		goto _test_eof214;
case 214:
#line 2315 "src/panda/date/strptime.cc"
	goto st0;
case 172:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr193;
	goto st0;
tr193:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st173;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
#line 2332 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr194;
	goto st0;
tr194:
#line 18 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 23 "src/panda/date/strptime.rl"
	{ _date.year += acc * 100; acc = 0; }
#line 34 "src/panda/date/strptime.rl"
	{ {p++; cs = 215; goto _out;} }
	goto st215;
st215:
	if ( ++p == pe )
		goto _test_eof215;
case 215:
#line 2351 "src/panda/date/strptime.cc"
	goto st0;
case 174:
	if ( (*p) == 37 )
		goto tr195;
	goto st0;
tr195:
#line 34 "src/panda/date/strptime.rl"
	{ {p++; cs = 216; goto _out;} }
	goto st216;
st216:
	if ( ++p == pe )
		goto _test_eof216;
case 216:
#line 2365 "src/panda/date/strptime.cc"
	goto st0;
	}
	_test_eof175: cs = 175; goto _test_eof; 
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof176: cs = 176; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof177: cs = 177; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof178: cs = 178; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof179: cs = 179; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof180: cs = 180; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof181: cs = 181; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 
	_test_eof22: cs = 22; goto _test_eof; 
	_test_eof23: cs = 23; goto _test_eof; 
	_test_eof24: cs = 24; goto _test_eof; 
	_test_eof25: cs = 25; goto _test_eof; 
	_test_eof182: cs = 182; goto _test_eof; 
	_test_eof27: cs = 27; goto _test_eof; 
	_test_eof28: cs = 28; goto _test_eof; 
	_test_eof29: cs = 29; goto _test_eof; 
	_test_eof30: cs = 30; goto _test_eof; 
	_test_eof31: cs = 31; goto _test_eof; 
	_test_eof32: cs = 32; goto _test_eof; 
	_test_eof33: cs = 33; goto _test_eof; 
	_test_eof34: cs = 34; goto _test_eof; 
	_test_eof35: cs = 35; goto _test_eof; 
	_test_eof36: cs = 36; goto _test_eof; 
	_test_eof183: cs = 183; goto _test_eof; 
	_test_eof37: cs = 37; goto _test_eof; 
	_test_eof39: cs = 39; goto _test_eof; 
	_test_eof40: cs = 40; goto _test_eof; 
	_test_eof41: cs = 41; goto _test_eof; 
	_test_eof42: cs = 42; goto _test_eof; 
	_test_eof43: cs = 43; goto _test_eof; 
	_test_eof44: cs = 44; goto _test_eof; 
	_test_eof45: cs = 45; goto _test_eof; 
	_test_eof184: cs = 184; goto _test_eof; 
	_test_eof47: cs = 47; goto _test_eof; 
	_test_eof48: cs = 48; goto _test_eof; 
	_test_eof49: cs = 49; goto _test_eof; 
	_test_eof50: cs = 50; goto _test_eof; 
	_test_eof51: cs = 51; goto _test_eof; 
	_test_eof52: cs = 52; goto _test_eof; 
	_test_eof53: cs = 53; goto _test_eof; 
	_test_eof54: cs = 54; goto _test_eof; 
	_test_eof55: cs = 55; goto _test_eof; 
	_test_eof185: cs = 185; goto _test_eof; 
	_test_eof57: cs = 57; goto _test_eof; 
	_test_eof58: cs = 58; goto _test_eof; 
	_test_eof59: cs = 59; goto _test_eof; 
	_test_eof60: cs = 60; goto _test_eof; 
	_test_eof61: cs = 61; goto _test_eof; 
	_test_eof62: cs = 62; goto _test_eof; 
	_test_eof63: cs = 63; goto _test_eof; 
	_test_eof64: cs = 64; goto _test_eof; 
	_test_eof65: cs = 65; goto _test_eof; 
	_test_eof66: cs = 66; goto _test_eof; 
	_test_eof67: cs = 67; goto _test_eof; 
	_test_eof68: cs = 68; goto _test_eof; 
	_test_eof69: cs = 69; goto _test_eof; 
	_test_eof70: cs = 70; goto _test_eof; 
	_test_eof71: cs = 71; goto _test_eof; 
	_test_eof72: cs = 72; goto _test_eof; 
	_test_eof186: cs = 186; goto _test_eof; 
	_test_eof74: cs = 74; goto _test_eof; 
	_test_eof187: cs = 187; goto _test_eof; 
	_test_eof76: cs = 76; goto _test_eof; 
	_test_eof77: cs = 77; goto _test_eof; 
	_test_eof188: cs = 188; goto _test_eof; 
	_test_eof79: cs = 79; goto _test_eof; 
	_test_eof189: cs = 189; goto _test_eof; 
	_test_eof190: cs = 190; goto _test_eof; 
	_test_eof82: cs = 82; goto _test_eof; 
	_test_eof83: cs = 83; goto _test_eof; 
	_test_eof191: cs = 191; goto _test_eof; 
	_test_eof84: cs = 84; goto _test_eof; 
	_test_eof85: cs = 85; goto _test_eof; 
	_test_eof192: cs = 192; goto _test_eof; 
	_test_eof86: cs = 86; goto _test_eof; 
	_test_eof87: cs = 87; goto _test_eof; 
	_test_eof193: cs = 193; goto _test_eof; 
	_test_eof88: cs = 88; goto _test_eof; 
	_test_eof89: cs = 89; goto _test_eof; 
	_test_eof90: cs = 90; goto _test_eof; 
	_test_eof91: cs = 91; goto _test_eof; 
	_test_eof194: cs = 194; goto _test_eof; 
	_test_eof92: cs = 92; goto _test_eof; 
	_test_eof93: cs = 93; goto _test_eof; 
	_test_eof94: cs = 94; goto _test_eof; 
	_test_eof95: cs = 95; goto _test_eof; 
	_test_eof96: cs = 96; goto _test_eof; 
	_test_eof195: cs = 195; goto _test_eof; 
	_test_eof97: cs = 97; goto _test_eof; 
	_test_eof98: cs = 98; goto _test_eof; 
	_test_eof99: cs = 99; goto _test_eof; 
	_test_eof100: cs = 100; goto _test_eof; 
	_test_eof196: cs = 196; goto _test_eof; 
	_test_eof101: cs = 101; goto _test_eof; 
	_test_eof102: cs = 102; goto _test_eof; 
	_test_eof103: cs = 103; goto _test_eof; 
	_test_eof104: cs = 104; goto _test_eof; 
	_test_eof105: cs = 105; goto _test_eof; 
	_test_eof197: cs = 197; goto _test_eof; 
	_test_eof106: cs = 106; goto _test_eof; 
	_test_eof107: cs = 107; goto _test_eof; 
	_test_eof108: cs = 108; goto _test_eof; 
	_test_eof109: cs = 109; goto _test_eof; 
	_test_eof110: cs = 110; goto _test_eof; 
	_test_eof198: cs = 198; goto _test_eof; 
	_test_eof111: cs = 111; goto _test_eof; 
	_test_eof112: cs = 112; goto _test_eof; 
	_test_eof113: cs = 113; goto _test_eof; 
	_test_eof114: cs = 114; goto _test_eof; 
	_test_eof115: cs = 115; goto _test_eof; 
	_test_eof117: cs = 117; goto _test_eof; 
	_test_eof199: cs = 199; goto _test_eof; 
	_test_eof119: cs = 119; goto _test_eof; 
	_test_eof200: cs = 200; goto _test_eof; 
	_test_eof121: cs = 121; goto _test_eof; 
	_test_eof122: cs = 122; goto _test_eof; 
	_test_eof201: cs = 201; goto _test_eof; 
	_test_eof123: cs = 123; goto _test_eof; 
	_test_eof202: cs = 202; goto _test_eof; 
	_test_eof124: cs = 124; goto _test_eof; 
	_test_eof203: cs = 203; goto _test_eof; 
	_test_eof125: cs = 125; goto _test_eof; 
	_test_eof126: cs = 126; goto _test_eof; 
	_test_eof127: cs = 127; goto _test_eof; 
	_test_eof128: cs = 128; goto _test_eof; 
	_test_eof204: cs = 204; goto _test_eof; 
	_test_eof129: cs = 129; goto _test_eof; 
	_test_eof130: cs = 130; goto _test_eof; 
	_test_eof131: cs = 131; goto _test_eof; 
	_test_eof132: cs = 132; goto _test_eof; 
	_test_eof133: cs = 133; goto _test_eof; 
	_test_eof134: cs = 134; goto _test_eof; 
	_test_eof205: cs = 205; goto _test_eof; 
	_test_eof135: cs = 135; goto _test_eof; 
	_test_eof136: cs = 136; goto _test_eof; 
	_test_eof137: cs = 137; goto _test_eof; 
	_test_eof138: cs = 138; goto _test_eof; 
	_test_eof139: cs = 139; goto _test_eof; 
	_test_eof140: cs = 140; goto _test_eof; 
	_test_eof206: cs = 206; goto _test_eof; 
	_test_eof141: cs = 141; goto _test_eof; 
	_test_eof142: cs = 142; goto _test_eof; 
	_test_eof143: cs = 143; goto _test_eof; 
	_test_eof144: cs = 144; goto _test_eof; 
	_test_eof207: cs = 207; goto _test_eof; 
	_test_eof208: cs = 208; goto _test_eof; 
	_test_eof145: cs = 145; goto _test_eof; 
	_test_eof146: cs = 146; goto _test_eof; 
	_test_eof209: cs = 209; goto _test_eof; 
	_test_eof147: cs = 147; goto _test_eof; 
	_test_eof148: cs = 148; goto _test_eof; 
	_test_eof149: cs = 149; goto _test_eof; 
	_test_eof210: cs = 210; goto _test_eof; 
	_test_eof150: cs = 150; goto _test_eof; 
	_test_eof151: cs = 151; goto _test_eof; 
	_test_eof152: cs = 152; goto _test_eof; 
	_test_eof153: cs = 153; goto _test_eof; 
	_test_eof154: cs = 154; goto _test_eof; 
	_test_eof155: cs = 155; goto _test_eof; 
	_test_eof211: cs = 211; goto _test_eof; 
	_test_eof156: cs = 156; goto _test_eof; 
	_test_eof157: cs = 157; goto _test_eof; 
	_test_eof158: cs = 158; goto _test_eof; 
	_test_eof159: cs = 159; goto _test_eof; 
	_test_eof160: cs = 160; goto _test_eof; 
	_test_eof212: cs = 212; goto _test_eof; 
	_test_eof161: cs = 161; goto _test_eof; 
	_test_eof162: cs = 162; goto _test_eof; 
	_test_eof163: cs = 163; goto _test_eof; 
	_test_eof164: cs = 164; goto _test_eof; 
	_test_eof165: cs = 165; goto _test_eof; 
	_test_eof167: cs = 167; goto _test_eof; 
	_test_eof168: cs = 168; goto _test_eof; 
	_test_eof169: cs = 169; goto _test_eof; 
	_test_eof213: cs = 213; goto _test_eof; 
	_test_eof171: cs = 171; goto _test_eof; 
	_test_eof214: cs = 214; goto _test_eof; 
	_test_eof173: cs = 173; goto _test_eof; 
	_test_eof215: cs = 215; goto _test_eof; 
	_test_eof216: cs = 216; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 175: 
	case 191: 
	case 192: 
	case 193: 
	case 194: 
	case 195: 
	case 196: 
	case 197: 
	case 198: 
	case 201: 
	case 202: 
	case 203: 
	case 204: 
	case 205: 
	case 206: 
	case 207: 
	case 208: 
	case 209: 
	case 210: 
	case 211: 
	case 212: 
#line 34 "src/panda/date/strptime.rl"
	{ {p++; cs = 0; goto _out;} }
	break;
#line 2590 "src/panda/date/strptime.cc"
	}
	}

	_out: {}
	}

#line 103 "src/panda/date/strptime.rl"


    // printf("_parse_str %s -> cs=%d, consumed=%d\n", pb, cs, p - pb);
    return p - pb;
}


#line 143 "src/panda/date/strptime.rl"



#line 2609 "src/panda/date/strptime.cc"
static const int meta_parser_start = 1;
static const int meta_parser_first_final = 3;
static const int meta_parser_error = 0;

static const int meta_parser_en_m_main = 1;


#line 146 "src/panda/date/strptime.rl"

static inline MetaConsume _parse_meta(const char* p, const char* pe, WeekInterpretation& week_interptetation)  {
    const char* pb     = p;
    const char* eof    = pe;
    int         cs     = meta_parser_en_m_main;
    int         p_cs   = 0;

    
#line 2626 "src/panda/date/strptime.cc"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
case 1:
	switch( (*p) ) {
		case 9: goto tr0;
		case 32: goto tr0;
		case 37: goto st2;
	}
	goto st0;
st0:
cs = 0;
	goto _out;
tr0:
#line 136 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_space; {p++; cs = 3; goto _out;} }
	goto st3;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
#line 2650 "src/panda/date/strptime.cc"
	switch( (*p) ) {
		case 9: goto tr0;
		case 32: goto tr0;
	}
	goto st0;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
	switch( (*p) ) {
		case 37: goto tr3;
		case 65: goto tr4;
		case 66: goto tr5;
		case 67: goto tr6;
		case 68: goto tr7;
		case 70: goto tr8;
		case 77: goto tr10;
		case 80: goto tr11;
		case 82: goto tr12;
		case 83: goto tr13;
		case 85: goto tr15;
		case 86: goto tr16;
		case 87: goto tr17;
		case 89: goto tr18;
		case 97: goto tr4;
		case 98: goto tr5;
		case 99: goto tr19;
		case 100: goto tr20;
		case 104: goto tr5;
		case 106: goto tr21;
		case 109: goto tr22;
		case 110: goto tr23;
		case 112: goto tr24;
		case 114: goto tr25;
		case 116: goto tr23;
		case 119: goto tr26;
		case 120: goto tr7;
		case 121: goto tr27;
	}
	if ( (*p) > 73 ) {
		if ( 84 <= (*p) && (*p) <= 88 )
			goto tr14;
	} else if ( (*p) >= 72 )
		goto tr9;
	goto st0;
tr3:
#line 134 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_perc;      {p++; cs = 4; goto _out;} }
	goto st4;
tr4:
#line 119 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_wname; {p++; cs = 4; goto _out;} }
	goto st4;
tr5:
#line 125 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_mname;     {p++; cs = 4; goto _out;} }
	goto st4;
tr6:
#line 115 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_cent;      {p++; cs = 4; goto _out;} }
	goto st4;
tr7:
#line 133 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_mdy;       {p++; cs = 4; goto _out;} }
	goto st4;
tr8:
#line 131 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_ymd;       {p++; cs = 4; goto _out;} }
	goto st4;
tr9:
#line 123 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_hour;      {p++; cs = 4; goto _out;} }
	goto st4;
tr10:
#line 126 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_min;       {p++; cs = 4; goto _out;} }
	goto st4;
tr11:
#line 113 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_ampm;      {p++; cs = 4; goto _out;} }
	goto st4;
tr12:
#line 128 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_hour_min;  {p++; cs = 4; goto _out;} }
	goto st4;
tr13:
#line 127 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_sec;       {p++; cs = 4; goto _out;} }
	goto st4;
tr14:
#line 132 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_hms;       {p++; cs = 4; goto _out;} }
	goto st4;
tr15:
#line 122 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_wnum; week_interptetation = WeekInterpretation::sunday; {p++; cs = 4; goto _out;} }
	goto st4;
tr16:
#line 120 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_wnum; week_interptetation = WeekInterpretation::iso;    {p++; cs = 4; goto _out;} }
	goto st4;
tr17:
#line 121 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_wnum; week_interptetation = WeekInterpretation::monday; {p++; cs = 4; goto _out;} }
	goto st4;
tr18:
#line 114 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_year;      {p++; cs = 4; goto _out;} }
	goto st4;
tr19:
#line 129 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_mdyhms;    {p++; cs = 4; goto _out;} }
	goto st4;
tr20:
#line 116 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_day;       {p++; cs = 4; goto _out;} }
	goto st4;
tr21:
#line 117 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_day3;      {p++; cs = 4; goto _out;} }
	goto st4;
tr22:
#line 124 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_month;     {p++; cs = 4; goto _out;} }
	goto st4;
tr23:
#line 135 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_space;  {p++; cs = 4; goto _out;} }
	goto st4;
tr24:
#line 112 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_AMPM;      {p++; cs = 4; goto _out;} }
	goto st4;
tr25:
#line 130 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_hmsAMPM;       {p++; cs = 4; goto _out;} }
	goto st4;
tr26:
#line 118 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_wday;      {p++; cs = 4; goto _out;} }
	goto st4;
tr27:
#line 111 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_yr;        {p++; cs = 4; goto _out;} }
	goto st4;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
#line 2800 "src/panda/date/strptime.cc"
	goto st0;
	}
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 

	_test_eof: {}
	_out: {}
	}

#line 154 "src/panda/date/strptime.rl"

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
