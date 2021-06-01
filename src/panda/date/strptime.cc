
#line 1 "src/panda/date/strptime.rl"
#include "Date.h"
#include <string.h>

#define NSAVE(dest) { dest = acc; acc = 0; }

namespace panda { namespace date {

struct MetaConsume {
    int cs;
    int consumed;
};


#line 85 "src/panda/date/strptime.rl"



#line 21 "src/panda/date/strptime.cc"
static const int parser_start = 160;
static const int parser_first_final = 160;
static const int parser_error = 0;

static const int parser_en_p_ampm = 1;
static const int parser_en_p_sec = 4;
static const int parser_en_p_min = 6;
static const int parser_en_p_hour = 8;
static const int parser_en_p_hour_min = 10;
static const int parser_en_p_hms = 15;
static const int parser_en_p_hmsampm = 23;
static const int parser_en_p_mdy = 35;
static const int parser_en_p_mdyhms = 43;
static const int parser_en_p_day = 60;
static const int parser_en_p_day3 = 62;
static const int parser_en_p_day_void = 65;
static const int parser_en_p_wday = 67;
static const int parser_en_p_wname = 68;
static const int parser_en_p_month = 103;
static const int parser_en_p_mname = 105;
static const int parser_en_p_year = 151;
static const int parser_en_p_yr = 155;
static const int parser_en_p_cent = 157;
static const int parser_en_p_perc = 159;
static const int parser_en_p_space = 160;


#line 88 "src/panda/date/strptime.rl"

static inline int _parse_str(int cs, const char* p, const char* pe, datetime& _date)  {
    // printf("_parse_str cs=%d\n", cs);
    const char* pb  = p;
    const char* eof = pe;
    uint64_t    acc = 0;

    
#line 58 "src/panda/date/strptime.cc"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
	if ( (*p) == 32 )
		goto st160;
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
#line 31 "src/panda/date/strptime.rl"
	{ {p++; cs = 161; goto _out;} }
	goto st161;
tr4:
#line 26 "src/panda/date/strptime.rl"
	{ _date.hour += 12;  }
#line 31 "src/panda/date/strptime.rl"
	{ {p++; cs = 161; goto _out;} }
	goto st161;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
#line 101 "src/panda/date/strptime.cc"
	goto st0;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
	if ( (*p) == 77 )
		goto tr4;
	goto st0;
case 4:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr5;
	goto st0;
tr5:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st5;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
#line 125 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr6;
	goto st0;
tr6:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 23 "src/panda/date/strptime.rl"
	{ NSAVE(_date.sec);  }
#line 31 "src/panda/date/strptime.rl"
	{ {p++; cs = 162; goto _out;} }
	goto st162;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
#line 144 "src/panda/date/strptime.cc"
	goto st0;
case 6:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr7;
	goto st0;
tr7:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st7;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
#line 161 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr8;
	goto st0;
tr8:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 24 "src/panda/date/strptime.rl"
	{ NSAVE(_date.min);  }
#line 31 "src/panda/date/strptime.rl"
	{ {p++; cs = 163; goto _out;} }
	goto st163;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
#line 180 "src/panda/date/strptime.cc"
	goto st0;
case 8:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr9;
	goto st0;
tr9:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st9;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
#line 197 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr10;
	goto st0;
tr10:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 25 "src/panda/date/strptime.rl"
	{ NSAVE(_date.hour); }
#line 31 "src/panda/date/strptime.rl"
	{ {p++; cs = 164; goto _out;} }
	goto st164;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
#line 216 "src/panda/date/strptime.cc"
	goto st0;
case 10:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr11;
	goto st0;
tr11:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st11;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
#line 233 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr12;
	goto st0;
tr12:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 25 "src/panda/date/strptime.rl"
	{ NSAVE(_date.hour); }
	goto st12;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
#line 250 "src/panda/date/strptime.cc"
	if ( (*p) == 58 )
		goto st13;
	goto st0;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr14;
	goto st0;
tr14:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st14;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
#line 272 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr15;
	goto st0;
tr15:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 24 "src/panda/date/strptime.rl"
	{ NSAVE(_date.min);  }
#line 31 "src/panda/date/strptime.rl"
	{ {p++; cs = 165; goto _out;} }
	goto st165;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
#line 291 "src/panda/date/strptime.cc"
	goto st0;
case 15:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr16;
	goto st0;
tr16:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st16;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
#line 308 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr17;
	goto st0;
tr17:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 25 "src/panda/date/strptime.rl"
	{ NSAVE(_date.hour); }
	goto st17;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
#line 325 "src/panda/date/strptime.cc"
	if ( (*p) == 58 )
		goto st18;
	goto st0;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr19;
	goto st0;
tr19:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st19;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
#line 347 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr20;
	goto st0;
tr20:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 24 "src/panda/date/strptime.rl"
	{ NSAVE(_date.min);  }
	goto st20;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
#line 364 "src/panda/date/strptime.cc"
	if ( (*p) == 58 )
		goto st21;
	goto st0;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr22;
	goto st0;
tr22:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st22;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
#line 386 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr23;
	goto st0;
tr23:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 23 "src/panda/date/strptime.rl"
	{ NSAVE(_date.sec);  }
#line 31 "src/panda/date/strptime.rl"
	{ {p++; cs = 166; goto _out;} }
	goto st166;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
#line 405 "src/panda/date/strptime.cc"
	goto st0;
case 23:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr24;
	goto st0;
tr24:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st24;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
#line 422 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr25;
	goto st0;
tr25:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 25 "src/panda/date/strptime.rl"
	{ NSAVE(_date.hour); }
	goto st25;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
#line 439 "src/panda/date/strptime.cc"
	if ( (*p) == 58 )
		goto st26;
	goto st0;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr27;
	goto st0;
tr27:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st27;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
#line 461 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr28;
	goto st0;
tr28:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 24 "src/panda/date/strptime.rl"
	{ NSAVE(_date.min);  }
	goto st28;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
#line 478 "src/panda/date/strptime.cc"
	if ( (*p) == 58 )
		goto st29;
	goto st0;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr30;
	goto st0;
tr30:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st30;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
#line 500 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr31;
	goto st0;
tr31:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 23 "src/panda/date/strptime.rl"
	{ NSAVE(_date.sec);  }
	goto st31;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
#line 517 "src/panda/date/strptime.cc"
	if ( (*p) == 32 )
		goto st32;
	goto st0;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
	switch( (*p) ) {
		case 32: goto st32;
		case 65: goto st33;
		case 80: goto st34;
	}
	goto st0;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
	if ( (*p) == 77 )
		goto tr35;
	goto st0;
tr35:
#line 31 "src/panda/date/strptime.rl"
	{ {p++; cs = 167; goto _out;} }
	goto st167;
tr36:
#line 26 "src/panda/date/strptime.rl"
	{ _date.hour += 12;  }
#line 31 "src/panda/date/strptime.rl"
	{ {p++; cs = 167; goto _out;} }
	goto st167;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
#line 552 "src/panda/date/strptime.cc"
	goto st0;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
	if ( (*p) == 77 )
		goto tr36;
	goto st0;
case 35:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr37;
	goto st0;
tr37:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st36;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
#line 576 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr38;
	goto st0;
tr38:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 30 "src/panda/date/strptime.rl"
	{ _date.mon = acc - 1; acc = 0; }
	goto st37;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
#line 593 "src/panda/date/strptime.cc"
	if ( (*p) == 47 )
		goto st38;
	goto st0;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr40;
	goto st0;
tr40:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st39;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
#line 615 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr41;
	goto st0;
tr41:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 27 "src/panda/date/strptime.rl"
	{ NSAVE(_date.mday); }
	goto st40;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
#line 632 "src/panda/date/strptime.cc"
	if ( (*p) == 47 )
		goto st41;
	goto st0;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr43;
	goto st0;
tr43:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st42;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
#line 654 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr44;
	goto st0;
tr44:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 33 "src/panda/date/strptime.rl"
	{
        if (acc <= 50) _date.year = 2000 + acc;
        else           _date.year = 1900 + acc;
        acc = 0;
    }
#line 31 "src/panda/date/strptime.rl"
	{ {p++; cs = 168; goto _out;} }
	goto st168;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
#line 677 "src/panda/date/strptime.cc"
	goto st0;
case 43:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr45;
	goto st0;
tr45:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st44;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
#line 694 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr46;
	goto st0;
tr46:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 30 "src/panda/date/strptime.rl"
	{ _date.mon = acc - 1; acc = 0; }
	goto st45;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
#line 711 "src/panda/date/strptime.cc"
	if ( (*p) == 47 )
		goto st46;
	goto st0;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr48;
	goto st0;
tr48:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st47;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
#line 733 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr49;
	goto st0;
tr49:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 27 "src/panda/date/strptime.rl"
	{ NSAVE(_date.mday); }
	goto st48;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
#line 750 "src/panda/date/strptime.cc"
	if ( (*p) == 47 )
		goto st49;
	goto st0;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr51;
	goto st0;
tr51:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st50;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
#line 772 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr52;
	goto st0;
tr52:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 33 "src/panda/date/strptime.rl"
	{
        if (acc <= 50) _date.year = 2000 + acc;
        else           _date.year = 1900 + acc;
        acc = 0;
    }
	goto st51;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
#line 793 "src/panda/date/strptime.cc"
	if ( (*p) == 32 )
		goto st52;
	goto st0;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
	if ( (*p) == 32 )
		goto st52;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr54;
	goto st0;
tr54:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st53;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
#line 817 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr55;
	goto st0;
tr55:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 25 "src/panda/date/strptime.rl"
	{ NSAVE(_date.hour); }
	goto st54;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
#line 834 "src/panda/date/strptime.cc"
	if ( (*p) == 58 )
		goto st55;
	goto st0;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr57;
	goto st0;
tr57:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st56;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
#line 856 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr58;
	goto st0;
tr58:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 24 "src/panda/date/strptime.rl"
	{ NSAVE(_date.min);  }
	goto st57;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
#line 873 "src/panda/date/strptime.cc"
	if ( (*p) == 58 )
		goto st58;
	goto st0;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr60;
	goto st0;
tr60:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st59;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
#line 895 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr61;
	goto st0;
tr61:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 23 "src/panda/date/strptime.rl"
	{ NSAVE(_date.sec);  }
#line 31 "src/panda/date/strptime.rl"
	{ {p++; cs = 169; goto _out;} }
	goto st169;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
#line 914 "src/panda/date/strptime.cc"
	goto st0;
case 60:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr62;
	goto st0;
tr62:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st61;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
#line 931 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr63;
	goto st0;
tr63:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 27 "src/panda/date/strptime.rl"
	{ NSAVE(_date.mday); }
#line 31 "src/panda/date/strptime.rl"
	{ {p++; cs = 170; goto _out;} }
	goto st170;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
#line 950 "src/panda/date/strptime.cc"
	goto st0;
case 62:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr64;
	goto st0;
tr64:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st63;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
#line 967 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr65;
	goto st0;
tr65:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st64;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
#line 982 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr66;
	goto st0;
tr66:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 29 "src/panda/date/strptime.rl"
	{ NSAVE(_date.mday); }
#line 31 "src/panda/date/strptime.rl"
	{ {p++; cs = 171; goto _out;} }
	goto st171;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
#line 1001 "src/panda/date/strptime.cc"
	goto st0;
case 65:
	if ( (*p) == 32 )
		goto st66;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr68;
	goto st0;
tr68:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st66;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
#line 1020 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr69;
	goto st0;
tr69:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 27 "src/panda/date/strptime.rl"
	{ NSAVE(_date.mday); }
#line 31 "src/panda/date/strptime.rl"
	{ {p++; cs = 172; goto _out;} }
	goto st172;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
#line 1039 "src/panda/date/strptime.cc"
	goto st0;
case 67:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr70;
	goto st0;
tr70:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 28 "src/panda/date/strptime.rl"
	{ NSAVE(_date.wday)  }
#line 31 "src/panda/date/strptime.rl"
	{ {p++; cs = 173; goto _out;} }
	goto st173;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
#line 1060 "src/panda/date/strptime.cc"
	goto st0;
case 68:
	switch( (*p) ) {
		case 70: goto st69;
		case 77: goto st73;
		case 83: goto st77;
		case 84: goto st86;
		case 87: goto st96;
	}
	goto st0;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
	if ( (*p) == 114 )
		goto st70;
	goto st0;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
	if ( (*p) == 105 )
		goto tr77;
	goto st0;
tr77:
#line 46 "src/panda/date/strptime.rl"
	{ _date.wday = 5; }
	goto st174;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
#line 1093 "src/panda/date/strptime.cc"
	if ( (*p) == 100 )
		goto st71;
	goto st0;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
	if ( (*p) == 97 )
		goto st72;
	goto st0;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
	if ( (*p) == 121 )
		goto tr79;
	goto st0;
tr79:
#line 46 "src/panda/date/strptime.rl"
	{ _date.wday = 5; }
	goto st175;
tr83:
#line 42 "src/panda/date/strptime.rl"
	{ _date.wday = 1; }
	goto st175;
tr90:
#line 47 "src/panda/date/strptime.rl"
	{ _date.wday = 6; }
	goto st175;
tr93:
#line 48 "src/panda/date/strptime.rl"
	{ _date.wday = 0; }
	goto st175;
tr100:
#line 45 "src/panda/date/strptime.rl"
	{ _date.wday = 4; }
	goto st175;
tr104:
#line 43 "src/panda/date/strptime.rl"
	{ _date.wday = 2; }
	goto st175;
tr111:
#line 44 "src/panda/date/strptime.rl"
	{ _date.wday = 3; }
	goto st175;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
#line 1143 "src/panda/date/strptime.cc"
	goto st0;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
	if ( (*p) == 111 )
		goto st74;
	goto st0;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
	if ( (*p) == 110 )
		goto tr81;
	goto st0;
tr81:
#line 42 "src/panda/date/strptime.rl"
	{ _date.wday = 1; }
	goto st176;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
#line 1167 "src/panda/date/strptime.cc"
	if ( (*p) == 100 )
		goto st75;
	goto st0;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
	if ( (*p) == 97 )
		goto st76;
	goto st0;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
	if ( (*p) == 121 )
		goto tr83;
	goto st0;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
	switch( (*p) ) {
		case 97: goto st78;
		case 117: goto st83;
	}
	goto st0;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
	if ( (*p) == 116 )
		goto tr86;
	goto st0;
tr86:
#line 47 "src/panda/date/strptime.rl"
	{ _date.wday = 6; }
	goto st177;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
#line 1209 "src/panda/date/strptime.cc"
	if ( (*p) == 117 )
		goto st79;
	goto st0;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
	if ( (*p) == 114 )
		goto st80;
	goto st0;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
	if ( (*p) == 100 )
		goto st81;
	goto st0;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
	if ( (*p) == 97 )
		goto st82;
	goto st0;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
	if ( (*p) == 121 )
		goto tr90;
	goto st0;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
	if ( (*p) == 110 )
		goto tr91;
	goto st0;
tr91:
#line 48 "src/panda/date/strptime.rl"
	{ _date.wday = 0; }
	goto st178;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
#line 1256 "src/panda/date/strptime.cc"
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
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
	switch( (*p) ) {
		case 104: goto st87;
		case 117: goto st92;
	}
	goto st0;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
	if ( (*p) == 117 )
		goto tr96;
	goto st0;
tr96:
#line 45 "src/panda/date/strptime.rl"
	{ _date.wday = 4; }
	goto st179;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
#line 1298 "src/panda/date/strptime.cc"
	if ( (*p) == 114 )
		goto st88;
	goto st0;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
	if ( (*p) == 115 )
		goto st89;
	goto st0;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
	if ( (*p) == 100 )
		goto st90;
	goto st0;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
	if ( (*p) == 97 )
		goto st91;
	goto st0;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
	if ( (*p) == 121 )
		goto tr100;
	goto st0;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
	if ( (*p) == 101 )
		goto tr101;
	goto st0;
tr101:
#line 43 "src/panda/date/strptime.rl"
	{ _date.wday = 2; }
	goto st180;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
#line 1345 "src/panda/date/strptime.cc"
	if ( (*p) == 115 )
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
	if ( (*p) == 101 )
		goto st97;
	goto st0;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
	if ( (*p) == 100 )
		goto tr106;
	goto st0;
tr106:
#line 44 "src/panda/date/strptime.rl"
	{ _date.wday = 3; }
	goto st181;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
#line 1392 "src/panda/date/strptime.cc"
	if ( (*p) == 110 )
		goto st98;
	goto st0;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
	if ( (*p) == 101 )
		goto st99;
	goto st0;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
	if ( (*p) == 115 )
		goto st100;
	goto st0;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
	if ( (*p) == 100 )
		goto st101;
	goto st0;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
	if ( (*p) == 97 )
		goto st102;
	goto st0;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
	if ( (*p) == 121 )
		goto tr111;
	goto st0;
case 103:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr112;
	goto st0;
tr112:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st104;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
#line 1446 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr113;
	goto st0;
tr113:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 30 "src/panda/date/strptime.rl"
	{ _date.mon = acc - 1; acc = 0; }
#line 31 "src/panda/date/strptime.rl"
	{ {p++; cs = 182; goto _out;} }
	goto st182;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
#line 1465 "src/panda/date/strptime.cc"
	goto st0;
case 105:
	switch( (*p) ) {
		case 65: goto st106;
		case 68: goto st112;
		case 70: goto st118;
		case 74: goto st124;
		case 77: goto st130;
		case 78: goto st133;
		case 79: goto st139;
		case 83: goto st144;
	}
	goto st0;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
	switch( (*p) ) {
		case 112: goto st107;
		case 117: goto st109;
	}
	goto st0;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
	if ( (*p) == 114 )
		goto tr124;
	goto st0;
tr124:
#line 53 "src/panda/date/strptime.rl"
	{ _date.mon = 3; }
	goto st183;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
#line 1503 "src/panda/date/strptime.cc"
	if ( (*p) == 105 )
		goto st108;
	goto st0;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
	if ( (*p) == 108 )
		goto tr125;
	goto st0;
tr125:
#line 53 "src/panda/date/strptime.rl"
	{ _date.mon = 3; }
	goto st184;
tr128:
#line 57 "src/panda/date/strptime.rl"
	{ _date.mon = 7; }
	goto st184;
tr134:
#line 61 "src/panda/date/strptime.rl"
	{ _date.mon = 11;}
	goto st184;
tr140:
#line 51 "src/panda/date/strptime.rl"
	{ _date.mon = 1; }
	goto st184;
tr146:
#line 50 "src/panda/date/strptime.rl"
	{ _date.mon = 0; }
	goto st184;
tr193:
#line 56 "src/panda/date/strptime.rl"
	{ _date.mon = 6; }
	goto st184;
tr194:
#line 55 "src/panda/date/strptime.rl"
	{ _date.mon = 5; }
	goto st184;
tr152:
#line 52 "src/panda/date/strptime.rl"
	{ _date.mon = 2; }
	goto st184;
tr151:
#line 54 "src/panda/date/strptime.rl"
	{ _date.mon = 4; }
	goto st184;
tr158:
#line 60 "src/panda/date/strptime.rl"
	{ _date.mon = 10;}
	goto st184;
tr163:
#line 59 "src/panda/date/strptime.rl"
	{ _date.mon = 9; }
	goto st184;
tr170:
#line 58 "src/panda/date/strptime.rl"
	{ _date.mon = 8; }
	goto st184;
st184:
	if ( ++p == pe )
		goto _test_eof184;
case 184:
#line 1566 "src/panda/date/strptime.cc"
	goto st0;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
	if ( (*p) == 103 )
		goto tr126;
	goto st0;
tr126:
#line 57 "src/panda/date/strptime.rl"
	{ _date.mon = 7; }
	goto st185;
st185:
	if ( ++p == pe )
		goto _test_eof185;
case 185:
#line 1583 "src/panda/date/strptime.cc"
	if ( (*p) == 117 )
		goto st110;
	goto st0;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
	if ( (*p) == 115 )
		goto st111;
	goto st0;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
	if ( (*p) == 116 )
		goto tr128;
	goto st0;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
	if ( (*p) == 101 )
		goto st113;
	goto st0;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
	if ( (*p) == 99 )
		goto tr130;
	goto st0;
tr130:
#line 61 "src/panda/date/strptime.rl"
	{ _date.mon = 11;}
	goto st186;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
#line 1623 "src/panda/date/strptime.cc"
	if ( (*p) == 101 )
		goto st114;
	goto st0;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
	if ( (*p) == 109 )
		goto st115;
	goto st0;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
	if ( (*p) == 98 )
		goto st116;
	goto st0;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
	if ( (*p) == 101 )
		goto st117;
	goto st0;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
	if ( (*p) == 114 )
		goto tr134;
	goto st0;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
	if ( (*p) == 101 )
		goto st119;
	goto st0;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
	if ( (*p) == 98 )
		goto tr136;
	goto st0;
tr136:
#line 51 "src/panda/date/strptime.rl"
	{ _date.mon = 1; }
	goto st187;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
#line 1677 "src/panda/date/strptime.cc"
	if ( (*p) == 114 )
		goto st120;
	goto st0;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
	if ( (*p) == 117 )
		goto st121;
	goto st0;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
	if ( (*p) == 97 )
		goto st122;
	goto st0;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
	if ( (*p) == 114 )
		goto st123;
	goto st0;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
	if ( (*p) == 121 )
		goto tr140;
	goto st0;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
	switch( (*p) ) {
		case 97: goto st125;
		case 117: goto st129;
	}
	goto st0;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
	if ( (*p) == 110 )
		goto tr143;
	goto st0;
tr143:
#line 50 "src/panda/date/strptime.rl"
	{ _date.mon = 0; }
	goto st188;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
#line 1733 "src/panda/date/strptime.cc"
	if ( (*p) == 117 )
		goto st126;
	goto st0;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
	if ( (*p) == 97 )
		goto st127;
	goto st0;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
	if ( (*p) == 114 )
		goto st128;
	goto st0;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
	if ( (*p) == 121 )
		goto tr146;
	goto st0;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	switch( (*p) ) {
		case 108: goto tr147;
		case 110: goto tr148;
	}
	goto st0;
tr147:
#line 56 "src/panda/date/strptime.rl"
	{ _date.mon = 6; }
	goto st189;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
#line 1775 "src/panda/date/strptime.cc"
	if ( (*p) == 121 )
		goto tr193;
	goto st0;
tr148:
#line 55 "src/panda/date/strptime.rl"
	{ _date.mon = 5; }
	goto st190;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
#line 1787 "src/panda/date/strptime.cc"
	if ( (*p) == 101 )
		goto tr194;
	goto st0;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
	if ( (*p) == 97 )
		goto st131;
	goto st0;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
	switch( (*p) ) {
		case 114: goto tr150;
		case 121: goto tr151;
	}
	goto st0;
tr150:
#line 52 "src/panda/date/strptime.rl"
	{ _date.mon = 2; }
	goto st191;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
#line 1815 "src/panda/date/strptime.cc"
	if ( (*p) == 99 )
		goto st132;
	goto st0;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
	if ( (*p) == 104 )
		goto tr152;
	goto st0;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
	if ( (*p) == 111 )
		goto st134;
	goto st0;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
	if ( (*p) == 118 )
		goto tr154;
	goto st0;
tr154:
#line 60 "src/panda/date/strptime.rl"
	{ _date.mon = 10;}
	goto st192;
st192:
	if ( ++p == pe )
		goto _test_eof192;
case 192:
#line 1848 "src/panda/date/strptime.cc"
	if ( (*p) == 101 )
		goto st135;
	goto st0;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
	if ( (*p) == 109 )
		goto st136;
	goto st0;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
	if ( (*p) == 98 )
		goto st137;
	goto st0;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
	if ( (*p) == 101 )
		goto st138;
	goto st0;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
	if ( (*p) == 114 )
		goto tr158;
	goto st0;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
	if ( (*p) == 99 )
		goto st140;
	goto st0;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
	if ( (*p) == 116 )
		goto tr160;
	goto st0;
tr160:
#line 59 "src/panda/date/strptime.rl"
	{ _date.mon = 9; }
	goto st193;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
#line 1902 "src/panda/date/strptime.cc"
	if ( (*p) == 111 )
		goto st141;
	goto st0;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
	if ( (*p) == 98 )
		goto st142;
	goto st0;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
	if ( (*p) == 101 )
		goto st143;
	goto st0;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
	if ( (*p) == 114 )
		goto tr163;
	goto st0;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
	if ( (*p) == 101 )
		goto st145;
	goto st0;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
	if ( (*p) == 112 )
		goto tr165;
	goto st0;
tr165:
#line 58 "src/panda/date/strptime.rl"
	{ _date.mon = 8; }
	goto st194;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
#line 1949 "src/panda/date/strptime.cc"
	if ( (*p) == 116 )
		goto st146;
	goto st0;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
	if ( (*p) == 101 )
		goto st147;
	goto st0;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
	if ( (*p) == 109 )
		goto st148;
	goto st0;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
	if ( (*p) == 98 )
		goto st149;
	goto st0;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
	if ( (*p) == 101 )
		goto st150;
	goto st0;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
	if ( (*p) == 114 )
		goto tr170;
	goto st0;
case 151:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr171;
	goto st0;
tr171:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st152;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
#line 2003 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr172;
	goto st0;
tr172:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st153;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
#line 2018 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr173;
	goto st0;
tr173:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st154;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
#line 2033 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr174;
	goto st0;
tr174:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 22 "src/panda/date/strptime.rl"
	{ NSAVE(_date.year); }
#line 31 "src/panda/date/strptime.rl"
	{ {p++; cs = 195; goto _out;} }
	goto st195;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
#line 2052 "src/panda/date/strptime.cc"
	goto st0;
case 155:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr175;
	goto st0;
tr175:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st156;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
#line 2069 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr176;
	goto st0;
tr176:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 33 "src/panda/date/strptime.rl"
	{
        if (acc <= 50) _date.year = 2000 + acc;
        else           _date.year = 1900 + acc;
        acc = 0;
    }
#line 31 "src/panda/date/strptime.rl"
	{ {p++; cs = 196; goto _out;} }
	goto st196;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
#line 2092 "src/panda/date/strptime.cc"
	goto st0;
case 157:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr177;
	goto st0;
tr177:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
	goto st158;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
#line 2109 "src/panda/date/strptime.cc"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr178;
	goto st0;
tr178:
#line 16 "src/panda/date/strptime.rl"
	{
        acc *= 10;
        acc += (*p) - '0';
    }
#line 21 "src/panda/date/strptime.rl"
	{ _date.year += acc * 100; acc = 0; }
#line 31 "src/panda/date/strptime.rl"
	{ {p++; cs = 197; goto _out;} }
	goto st197;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
#line 2128 "src/panda/date/strptime.cc"
	goto st0;
case 159:
	if ( (*p) == 37 )
		goto tr179;
	goto st0;
tr179:
#line 31 "src/panda/date/strptime.rl"
	{ {p++; cs = 198; goto _out;} }
	goto st198;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
#line 2142 "src/panda/date/strptime.cc"
	goto st0;
	}
	_test_eof160: cs = 160; goto _test_eof; 
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof161: cs = 161; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof162: cs = 162; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof163: cs = 163; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof164: cs = 164; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof165: cs = 165; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 
	_test_eof22: cs = 22; goto _test_eof; 
	_test_eof166: cs = 166; goto _test_eof; 
	_test_eof24: cs = 24; goto _test_eof; 
	_test_eof25: cs = 25; goto _test_eof; 
	_test_eof26: cs = 26; goto _test_eof; 
	_test_eof27: cs = 27; goto _test_eof; 
	_test_eof28: cs = 28; goto _test_eof; 
	_test_eof29: cs = 29; goto _test_eof; 
	_test_eof30: cs = 30; goto _test_eof; 
	_test_eof31: cs = 31; goto _test_eof; 
	_test_eof32: cs = 32; goto _test_eof; 
	_test_eof33: cs = 33; goto _test_eof; 
	_test_eof167: cs = 167; goto _test_eof; 
	_test_eof34: cs = 34; goto _test_eof; 
	_test_eof36: cs = 36; goto _test_eof; 
	_test_eof37: cs = 37; goto _test_eof; 
	_test_eof38: cs = 38; goto _test_eof; 
	_test_eof39: cs = 39; goto _test_eof; 
	_test_eof40: cs = 40; goto _test_eof; 
	_test_eof41: cs = 41; goto _test_eof; 
	_test_eof42: cs = 42; goto _test_eof; 
	_test_eof168: cs = 168; goto _test_eof; 
	_test_eof44: cs = 44; goto _test_eof; 
	_test_eof45: cs = 45; goto _test_eof; 
	_test_eof46: cs = 46; goto _test_eof; 
	_test_eof47: cs = 47; goto _test_eof; 
	_test_eof48: cs = 48; goto _test_eof; 
	_test_eof49: cs = 49; goto _test_eof; 
	_test_eof50: cs = 50; goto _test_eof; 
	_test_eof51: cs = 51; goto _test_eof; 
	_test_eof52: cs = 52; goto _test_eof; 
	_test_eof53: cs = 53; goto _test_eof; 
	_test_eof54: cs = 54; goto _test_eof; 
	_test_eof55: cs = 55; goto _test_eof; 
	_test_eof56: cs = 56; goto _test_eof; 
	_test_eof57: cs = 57; goto _test_eof; 
	_test_eof58: cs = 58; goto _test_eof; 
	_test_eof59: cs = 59; goto _test_eof; 
	_test_eof169: cs = 169; goto _test_eof; 
	_test_eof61: cs = 61; goto _test_eof; 
	_test_eof170: cs = 170; goto _test_eof; 
	_test_eof63: cs = 63; goto _test_eof; 
	_test_eof64: cs = 64; goto _test_eof; 
	_test_eof171: cs = 171; goto _test_eof; 
	_test_eof66: cs = 66; goto _test_eof; 
	_test_eof172: cs = 172; goto _test_eof; 
	_test_eof173: cs = 173; goto _test_eof; 
	_test_eof69: cs = 69; goto _test_eof; 
	_test_eof70: cs = 70; goto _test_eof; 
	_test_eof174: cs = 174; goto _test_eof; 
	_test_eof71: cs = 71; goto _test_eof; 
	_test_eof72: cs = 72; goto _test_eof; 
	_test_eof175: cs = 175; goto _test_eof; 
	_test_eof73: cs = 73; goto _test_eof; 
	_test_eof74: cs = 74; goto _test_eof; 
	_test_eof176: cs = 176; goto _test_eof; 
	_test_eof75: cs = 75; goto _test_eof; 
	_test_eof76: cs = 76; goto _test_eof; 
	_test_eof77: cs = 77; goto _test_eof; 
	_test_eof78: cs = 78; goto _test_eof; 
	_test_eof177: cs = 177; goto _test_eof; 
	_test_eof79: cs = 79; goto _test_eof; 
	_test_eof80: cs = 80; goto _test_eof; 
	_test_eof81: cs = 81; goto _test_eof; 
	_test_eof82: cs = 82; goto _test_eof; 
	_test_eof83: cs = 83; goto _test_eof; 
	_test_eof178: cs = 178; goto _test_eof; 
	_test_eof84: cs = 84; goto _test_eof; 
	_test_eof85: cs = 85; goto _test_eof; 
	_test_eof86: cs = 86; goto _test_eof; 
	_test_eof87: cs = 87; goto _test_eof; 
	_test_eof179: cs = 179; goto _test_eof; 
	_test_eof88: cs = 88; goto _test_eof; 
	_test_eof89: cs = 89; goto _test_eof; 
	_test_eof90: cs = 90; goto _test_eof; 
	_test_eof91: cs = 91; goto _test_eof; 
	_test_eof92: cs = 92; goto _test_eof; 
	_test_eof180: cs = 180; goto _test_eof; 
	_test_eof93: cs = 93; goto _test_eof; 
	_test_eof94: cs = 94; goto _test_eof; 
	_test_eof95: cs = 95; goto _test_eof; 
	_test_eof96: cs = 96; goto _test_eof; 
	_test_eof97: cs = 97; goto _test_eof; 
	_test_eof181: cs = 181; goto _test_eof; 
	_test_eof98: cs = 98; goto _test_eof; 
	_test_eof99: cs = 99; goto _test_eof; 
	_test_eof100: cs = 100; goto _test_eof; 
	_test_eof101: cs = 101; goto _test_eof; 
	_test_eof102: cs = 102; goto _test_eof; 
	_test_eof104: cs = 104; goto _test_eof; 
	_test_eof182: cs = 182; goto _test_eof; 
	_test_eof106: cs = 106; goto _test_eof; 
	_test_eof107: cs = 107; goto _test_eof; 
	_test_eof183: cs = 183; goto _test_eof; 
	_test_eof108: cs = 108; goto _test_eof; 
	_test_eof184: cs = 184; goto _test_eof; 
	_test_eof109: cs = 109; goto _test_eof; 
	_test_eof185: cs = 185; goto _test_eof; 
	_test_eof110: cs = 110; goto _test_eof; 
	_test_eof111: cs = 111; goto _test_eof; 
	_test_eof112: cs = 112; goto _test_eof; 
	_test_eof113: cs = 113; goto _test_eof; 
	_test_eof186: cs = 186; goto _test_eof; 
	_test_eof114: cs = 114; goto _test_eof; 
	_test_eof115: cs = 115; goto _test_eof; 
	_test_eof116: cs = 116; goto _test_eof; 
	_test_eof117: cs = 117; goto _test_eof; 
	_test_eof118: cs = 118; goto _test_eof; 
	_test_eof119: cs = 119; goto _test_eof; 
	_test_eof187: cs = 187; goto _test_eof; 
	_test_eof120: cs = 120; goto _test_eof; 
	_test_eof121: cs = 121; goto _test_eof; 
	_test_eof122: cs = 122; goto _test_eof; 
	_test_eof123: cs = 123; goto _test_eof; 
	_test_eof124: cs = 124; goto _test_eof; 
	_test_eof125: cs = 125; goto _test_eof; 
	_test_eof188: cs = 188; goto _test_eof; 
	_test_eof126: cs = 126; goto _test_eof; 
	_test_eof127: cs = 127; goto _test_eof; 
	_test_eof128: cs = 128; goto _test_eof; 
	_test_eof129: cs = 129; goto _test_eof; 
	_test_eof189: cs = 189; goto _test_eof; 
	_test_eof190: cs = 190; goto _test_eof; 
	_test_eof130: cs = 130; goto _test_eof; 
	_test_eof131: cs = 131; goto _test_eof; 
	_test_eof191: cs = 191; goto _test_eof; 
	_test_eof132: cs = 132; goto _test_eof; 
	_test_eof133: cs = 133; goto _test_eof; 
	_test_eof134: cs = 134; goto _test_eof; 
	_test_eof192: cs = 192; goto _test_eof; 
	_test_eof135: cs = 135; goto _test_eof; 
	_test_eof136: cs = 136; goto _test_eof; 
	_test_eof137: cs = 137; goto _test_eof; 
	_test_eof138: cs = 138; goto _test_eof; 
	_test_eof139: cs = 139; goto _test_eof; 
	_test_eof140: cs = 140; goto _test_eof; 
	_test_eof193: cs = 193; goto _test_eof; 
	_test_eof141: cs = 141; goto _test_eof; 
	_test_eof142: cs = 142; goto _test_eof; 
	_test_eof143: cs = 143; goto _test_eof; 
	_test_eof144: cs = 144; goto _test_eof; 
	_test_eof145: cs = 145; goto _test_eof; 
	_test_eof194: cs = 194; goto _test_eof; 
	_test_eof146: cs = 146; goto _test_eof; 
	_test_eof147: cs = 147; goto _test_eof; 
	_test_eof148: cs = 148; goto _test_eof; 
	_test_eof149: cs = 149; goto _test_eof; 
	_test_eof150: cs = 150; goto _test_eof; 
	_test_eof152: cs = 152; goto _test_eof; 
	_test_eof153: cs = 153; goto _test_eof; 
	_test_eof154: cs = 154; goto _test_eof; 
	_test_eof195: cs = 195; goto _test_eof; 
	_test_eof156: cs = 156; goto _test_eof; 
	_test_eof196: cs = 196; goto _test_eof; 
	_test_eof158: cs = 158; goto _test_eof; 
	_test_eof197: cs = 197; goto _test_eof; 
	_test_eof198: cs = 198; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 160: 
	case 174: 
	case 175: 
	case 176: 
	case 177: 
	case 178: 
	case 179: 
	case 180: 
	case 181: 
	case 183: 
	case 184: 
	case 185: 
	case 186: 
	case 187: 
	case 188: 
	case 189: 
	case 190: 
	case 191: 
	case 192: 
	case 193: 
	case 194: 
#line 31 "src/panda/date/strptime.rl"
	{ {p++; cs = 0; goto _out;} }
	break;
#line 2352 "src/panda/date/strptime.cc"
	}
	}

	_out: {}
	}

#line 96 "src/panda/date/strptime.rl"


    // printf("_parse_str %s -> cs=%d, consumed=%d\n", pb, cs, p - pb);
    return p - pb;
}


#line 130 "src/panda/date/strptime.rl"



#line 2371 "src/panda/date/strptime.cc"
static const int meta_parser_start = 1;
static const int meta_parser_first_final = 3;
static const int meta_parser_error = 0;

static const int meta_parser_en_m_main = 1;


#line 133 "src/panda/date/strptime.rl"

static inline MetaConsume _parse_meta(const char* p, const char* pe)  {
    const char* pb     = p;
    const char* eof    = pe;
    int         cs     = meta_parser_en_m_main;
    int         p_cs   = 0;

    
#line 2388 "src/panda/date/strptime.cc"
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
#line 124 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_space; {p++; cs = 3; goto _out;} }
	goto st3;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
#line 2412 "src/panda/date/strptime.cc"
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
		case 77: goto tr9;
		case 82: goto tr10;
		case 83: goto tr11;
		case 84: goto tr12;
		case 88: goto tr12;
		case 89: goto tr13;
		case 97: goto tr4;
		case 98: goto tr5;
		case 99: goto tr14;
		case 100: goto tr15;
		case 104: goto tr5;
		case 106: goto tr16;
		case 109: goto tr17;
		case 110: goto tr18;
		case 112: goto tr19;
		case 114: goto tr20;
		case 116: goto tr18;
		case 119: goto tr21;
		case 120: goto tr7;
		case 121: goto tr22;
	}
	if ( 72 <= (*p) && (*p) <= 73 )
		goto tr8;
	goto st0;
tr3:
#line 122 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_perc;      {p++; cs = 4; goto _out;} }
	goto st4;
tr4:
#line 111 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_wname; {p++; cs = 4; goto _out;} }
	goto st4;
tr5:
#line 114 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_mname;     {p++; cs = 4; goto _out;} }
	goto st4;
tr6:
#line 107 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_cent;      {p++; cs = 4; goto _out;} }
	goto st4;
tr7:
#line 121 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_mdy;       {p++; cs = 4; goto _out;} }
	goto st4;
tr8:
#line 112 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_hour;      {p++; cs = 4; goto _out;} }
	goto st4;
tr9:
#line 115 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_min;       {p++; cs = 4; goto _out;} }
	goto st4;
tr10:
#line 117 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_hour_min;  {p++; cs = 4; goto _out;} }
	goto st4;
tr11:
#line 116 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_sec;       {p++; cs = 4; goto _out;} }
	goto st4;
tr12:
#line 120 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_hms;       {p++; cs = 4; goto _out;} }
	goto st4;
tr13:
#line 106 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_year;      {p++; cs = 4; goto _out;} }
	goto st4;
tr14:
#line 118 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_mdyhms;    {p++; cs = 4; goto _out;} }
	goto st4;
tr15:
#line 108 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_day;       {p++; cs = 4; goto _out;} }
	goto st4;
tr16:
#line 109 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_day3;      {p++; cs = 4; goto _out;} }
	goto st4;
tr17:
#line 113 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_month;     {p++; cs = 4; goto _out;} }
	goto st4;
tr18:
#line 123 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_space;  {p++; cs = 4; goto _out;} }
	goto st4;
tr19:
#line 105 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_ampm;      {p++; cs = 4; goto _out;} }
	goto st4;
tr20:
#line 119 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_hmsampm;       {p++; cs = 4; goto _out;} }
	goto st4;
tr21:
#line 110 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_wday;      {p++; cs = 4; goto _out;} }
	goto st4;
tr22:
#line 104 "src/panda/date/strptime.rl"
	{ p_cs = parser_en_p_yr;        {p++; cs = 4; goto _out;} }
	goto st4;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
#line 2536 "src/panda/date/strptime.cc"
	goto st0;
	}
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 

	_test_eof: {}
	_out: {}
	}

#line 141 "src/panda/date/strptime.rl"

    auto consumed = p - pb;
    // printf("_parse_meta '%s' p_cs=%d, c=%d, cs=%d\n", pb, p_cs, consumed, cs);
    return MetaConsume { p_cs, (int)consumed };
}

void Date::strptime (string_view str, string_view format) {
    memset(&_date, 0, sizeof(_date)); // reset all values
    _date.mday = 1;
    _error = errc::ok;
    _mksec = 0;

    const char* m_p = format.data();
    const char* m_e = m_p + format.length();
    const char* s_p = str.data();
    const char* s_e = s_p + str.length();

    while((m_p != m_e) && (s_p != s_e)) {
        // printf("cycle, meta='%s', str='%s'\n", m_p, s_p);
        auto meta_result = _parse_meta(m_p, m_e);
        if (meta_result.cs) {
            int consumed = _parse_str(meta_result.cs, s_p, s_e, _date);
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
}

}}
