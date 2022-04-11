#ifndef	_ixutf8_c
#define	_ixutf8_c

/*
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <getopt.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
*/

/**
 @brief Data to save the utf8-to-unicode transcoding transition state
 @note it needs to be initialized before using
 */
struct Utf8Trancoder {
	u_char cvt_count_; // counter for convertion process
	u_short cvt_char_; // temporary variable for convertion process
};




/**
 @brief Function to initialise the utf8-to-unicode data
 @param tr - transcoder transition data pointer
 */
static void utf8trancoder_init( struct Utf8Trancoder* tr )
{
	tr->cvt_count_ = 0;
	tr->cvt_char_ = 0;
}

/**
 @brief Function to transcode one utf8 byte to unicodes
 @param tr - transcoder transition data pointer
 @param uc - pointer to the unicode reception area (pointer must be not zero)
 @param byte - input byte to transcode
 @return return 1 when the output unicode is ready or 0 when it is not ready
 */
static int utf8transcoder_putbyte( struct Utf8Trancoder* tr, u_short* uc, u_char byte )
{
	u_short data_uc = 0; // for translated character
	u_short data_byte = byte; // get the entry byte for transcode process

	if ( data_byte <= 0x7f ) {
		data_uc = data_byte;
		tr->cvt_count_ = 0;
	}
	else if ( tr->cvt_count_ > 0 && (data_byte&0xc0) == 0x80 ) {
		tr->cvt_char_ = (tr->cvt_char_<<6)|(data_byte&0x3f);
		tr->cvt_count_--;
		if ( tr->cvt_count_ )
			return 0; // unicode is not still ready

		data_uc = data_byte = tr->cvt_char_;
	}
	else {
		if ( (data_byte&0xe0) == 0xc0 ) {
			tr->cvt_count_ = 1; // will wait 1 byte to complete the transcoding
			tr->cvt_char_ = (data_byte&0x1f);
		}
		else if ( (data_byte&0xf0) == 0xe0 ) {
			tr->cvt_count_ = 2; // will wait 2 bytes to complete the transcoding
			tr->cvt_char_ = (data_byte&0x0f);
		}
		else if ( (data_byte&0xf8) == 0xf0 ) {
			tr->cvt_count_ = 3; // will wait 3 bytes to complete the transcoding
			tr->cvt_char_ = (data_byte&0x07);
		}
		else if ( (data_byte&0xfc) == 0xf8 ) {
			tr->cvt_count_ = 4; // will wait 4 bytes to complete the transcoding
			tr->cvt_char_ = (data_byte&0x03);
		}
		else if ( (data_byte&0xfe) == 0xfc ) {
			tr->cvt_count_ = 5; // will wait 5 bytes to complete the transcoding
			tr->cvt_char_ = (data_byte&0x01);
		}
		else
			tr->cvt_count_ = 0;

    return 0; // unicode is not still ready
	}

	if ( !data_uc || data_uc >= 0xfffe // not printable char
		|| data_uc == 0xfeff // zero-width space
		|| ( data_uc >= 0x200a && data_uc <= 0x200f ) )
		return 0; // unicode is not still ready

	// at this point we have in <data_uc> the unicode
	*uc = data_uc; // put unicode in the destination area (it considers the pointer not zero)
	return 1; // unicode is ready signal
}

/**
 @brief Function to transcode the unicode to the twin code
 @param uc - unicode to be transformed in twin code
 @return the twin code not zero on Ok or zero on error

 @note: the unicode names are from '/usr/share/misc/unicode.gz' file from 'miscfiles'
 package.

 @note: the semigraphic unicodes may be exluded from the table because it cannot
 be composed by keyboard input.
 
 @note: #BG 04/01/13: Ajout de caractères Unicodes UTF8 convertis selon
 la table de transcodage Unicode/MV2 utilisée par Termsys.
 */
static u_char trans_unicode_to_twnicode( u_short uc )
{
	struct UnicodeTwin {
		u_short uc_; // unicode
		u_char twin_; // twin code
	};

	static const struct UnicodeTwin tb[] = {
	{ uc_: 0x201d, twin_: 0x22 }, // #BG 04/01/13 Ajout...
	{ uc_: 0x2019, twin_: 0x27 },
	{ uc_: 0x201a, twin_: 0x2c },
	{ uc_: 0x0326, twin_: 0x2c },
	{ uc_: 0x2212, twin_: 0x2d },
	{ uc_: 0x2010, twin_: 0x2d },
	{ uc_: 0x2013, twin_: 0x2d },
	{ uc_: 0x2014, twin_: 0x2d },
	{ uc_: 0x2015, twin_: 0x2d },
	{ uc_: 0x2044, twin_: 0x2f },
	{ uc_: 0x00c0, twin_: 0x41 },
	{ uc_: 0x00c1, twin_: 0x41 },
	{ uc_: 0x00c2, twin_: 0x41 },
	{ uc_: 0x00c3, twin_: 0x41 },
	{ uc_: 0x00c8, twin_: 0x45 },
	{ uc_: 0x00ca, twin_: 0x45 },
	{ uc_: 0x00cb, twin_: 0x45 },
	{ uc_: 0x00cc, twin_: 0x49 },
	{ uc_: 0x00cd, twin_: 0x49 },
	{ uc_: 0x00ce, twin_: 0x49 },
	{ uc_: 0x00cf, twin_: 0x49 },
	{ uc_: 0x0300, twin_: 0x60 }, // #BG 04/01/13 ...Ajout
    { uc_: 0x00a2, twin_: 0x63 }, // unicode name: 'CENT SIGN' used as 0x63
	{ uc_: 0x00a6, twin_: 0x7c }, // #BG 04/01/13 Ajout...
	{ uc_: 0x02dc, twin_: 0x7e }, //
	{ uc_: 0x0303, twin_: 0x7e }, // #BG 04/01/13 ...Ajout

    { uc_: 0x00c7, twin_: 0x80 }, // 000 unicode name: 'LATIN CAPITAL LETTER C WITH CEDILLA'
    { uc_: 0x00fc, twin_: 0x81 }, // 001 unicode name: 'LATIN SMALL LETTER U WITH DIAERESIS'
    { uc_: 0x00e9, twin_: 0x82 }, // 002 unicode name: 'LATIN SMALL LETTER E WITH ACUTE'
    { uc_: 0x00e2, twin_: 0x83 }, // 003 unicode name: 'LATIN SMALL LETTER A WITH CIRCUMFLEX'
    { uc_: 0x00e4, twin_: 0x84 }, // 004 unicode name: 'LATIN SMALL LETTER A WITH DIAERESIS'
    { uc_: 0x00e0, twin_: 0x85 }, // 005 unicode name: 'LATIN SMALL LETTER A WITH GRAVE'
    { uc_: 0x00e5, twin_: 0x86 }, // 006 unicode name: 'LATIN SMALL LETTER A WITH RING ABOVE'
    { uc_: 0x00e7, twin_: 0x87 }, // 007 unicode name: 'LATIN SMALL LETTER C WITH CEDILLA'
    { uc_: 0x00ea, twin_: 0x88 }, // 008 unicode name: 'LATIN SMALL LETTER E WITH CIRCUMFLEX'
    { uc_: 0x00eb, twin_: 0x89 }, // 009 unicode name: 'LATIN SMALL LETTER E WITH DIAERESIS'
    { uc_: 0x00e8, twin_: 0x8a }, // 010 unicode name: 'LATIN SMALL LETTER E WITH GRAVE'
    { uc_: 0x00ef, twin_: 0x8b }, // 011 unicode name: 'LATIN SMALL LETTER I WITH DIAERESIS'
    { uc_: 0x00ee, twin_: 0x8c }, // 012 unicode name: 'LATIN SMALL LETTER I WITH CIRCUMFLEX'
    { uc_: 0x00ec, twin_: 0x8d }, // 013 unicode name: 'LATIN SMALL LETTER I WITH GRAVE'
    { uc_: 0x00c4, twin_: 0x8e }, // 014 unicode name: 'LATIN CAPITAL LETTER A WITH DIAERESI'
    { uc_: 0x00c5, twin_: 0x8f }, // 015 unicode name: 'LATIN CAPITAL LETTER A WITH RING ABOVE'
	{ uc_: 0x212b, twin_: 0x8f }, // 015 #BG 04/01/13 Ajout

    { uc_: 0x00c9, twin_: 0x90 }, // 016 unicode name: 'LATIN CAPITAL LETTER E WITH ACUTE'
    { uc_: 0x00e6, twin_: 0x91 }, // 017 unicode name: 'LATIN SMALL LETTER AE'
    { uc_: 0x00c6, twin_: 0x92 }, // 018 unicode name: 'LATIN CAPITAL LETTER AE'
    { uc_: 0x00f4, twin_: 0x93 }, // 019 unicode name: 'LATIN SMALL LETTER O WITH CIRCUMFLEX'
    { uc_: 0x00f6, twin_: 0x94 }, // 020 unicode name: 'LATIN SMALL LETTER O WITH DIAERESIS'
    { uc_: 0x00f2, twin_: 0x95 }, // 021 unicode name: 'LATIN SMALL LETTER O WITH GRAVE'
    { uc_: 0x00fb, twin_: 0x96 }, // 022 unicode name: 'LATIN SMALL LETTER U WITH CIRCUMFLEX'
    { uc_: 0x00f9, twin_: 0x97 }, // 023 unicode name: 'LATIN SMALL LETTER U WITH GRAVE'
    { uc_: 0x00ff, twin_: 0x98 }, // 024 unicode name: 'LATIN SMALL LETTER Y WITH DIAERESIS'
    { uc_: 0x00d6, twin_: 0x99 }, // 025 unicode name: 'LATIN CAPITAL LETTER O WITH DIAERESIS'
    { uc_: 0x00dc, twin_: 0x9a }, // 026 unicode name: 'LATIN CAPITAL LETTER U WITH DIAERESIS'
    { uc_: 0x20ac, twin_: 0x9b }, // 027 unicode name: 'EURO SIGN'
	{ uc_: 0x20a0, twin_: 0x9b }, // 027 unicode name: '' used as euro (version)
	{ uc_: 0x00a4, twin_: 0x9b }, // 027 unicode name: 'CURRENCY SIGN' used as euro (version)
	{ uc_: 0x00a3, twin_: 0x9c }, // 028 unicode name: 'POUND SIGN'
    { uc_: 0x00a5, twin_: 0x9d }, // 029 unicode name: 'YEN SIGN'
    { uc_: 0x20a7, twin_: 0x9e }, // 030 unicode name: 'PESETA SIGN'
    { uc_: 0x0192, twin_: 0x9f }, // 031 unicode name: 'LATIN SMALL LETTER F WITH HOOK'

    { uc_: 0x00e1, twin_: 0xa0 }, // 032 unicode name: 'LATIN SMALL LETTER A WITH ACUTE'
    { uc_: 0x00ed, twin_: 0xa1 }, // 033 unicode name: 'LATIN SMALL LETTER I WITH ACUTE'
    { uc_: 0x00f3, twin_: 0xa2 }, // 034 unicode name: 'LATIN SMALL LETTER O WITH ACUTE'
    { uc_: 0x00fa, twin_: 0xa3 }, // 035 unicode name: 'LATIN SMALL LETTER U WITH ACUTE'
    { uc_: 0x00f1, twin_: 0xa4 }, // 036 unicode name: 'LATIN SMALL LETTER N WITH TILDE'
    { uc_: 0x00d1, twin_: 0xa5 }, // 037 unicode name: 'LATIN CAPITAL LETTER N WITH TILD'
    { uc_: 0x00aa, twin_: 0xa6 }, // 038 unicode name: 'FEMININE ORDINAL INDICATOR'
    { uc_: 0x00ba, twin_: 0xa7 }, // 039 unicode name: 'MASCULINE ORDINAL INDICATOR'
    { uc_: 0x00bf, twin_: 0xa8 }, // 040 unicode name: 'INVERTED QUESTION MARK'
    { uc_: 0x2310, twin_: 0xa9 }, // 041 unicode name: 'REVERSED NOT SIGN'
    { uc_: 0x00ac, twin_: 0xaa }, // 042 unicode name: 'NOT SIGN'
    { uc_: 0x00bd, twin_: 0xab }, // 043 unicode name: 'VULGAR FRACTION ONE HALF'
    { uc_: 0x00bc, twin_: 0xac }, // 044 unicode name: 'VULGAR FRACTION ONE QUARTER'
    { uc_: 0x00a1, twin_: 0xad }, // 045 unicode name: 'INVERTED EXCLAMATION MARK'
    { uc_: 0x00ab, twin_: 0xae }, // 046 unicode name: 'LEFT-POINTING DOUBLE ANGLE QUOTATION MARK'
	{ uc_: 0x2039, twin_: 0xae }, // 046 #BG 04/01/13 Ajout
	{ uc_: 0x2018, twin_: 0xae }, // 046 #BG 04/01/13 Ajout
	{ uc_: 0x201c, twin_: 0xae }, // 046 #BG 04/01/13 Ajout
	{ uc_: 0x201e, twin_: 0xae }, // 046 #BG 04/01/13 Ajout
    { uc_: 0x00bb, twin_: 0xaf }, // 047 unicode name: 'RIGHT-POINTING DOUBLE ANGLE QUOTATION MARK'
	{ uc_: 0x203a, twin_: 0xaf }, // 047 #BG 04/01/13 Ajout

    { uc_: 0x2591, twin_: 0xb0 }, // 048 unicode name: 'LIGHT SHADE'
    { uc_: 0x2592, twin_: 0xb1 }, // 049 unicode name: 'MEDIUM SHADE'
    { uc_: 0x2593, twin_: 0xb2 }, // 050 unicode name: 'DARK SHADE'
    { uc_: 0x2502, twin_: 0xb3 }, // 051 unicode name: 'BOX DRAWINGS LIGHT VERTICAL'
    { uc_: 0x2524, twin_: 0xb4 }, // 052 unicode name: 'BOX DRAWINGS LIGHT VERTICAL AND LEFT'
    { uc_: 0x2561, twin_: 0xb5 }, // 053 unicode name: 'BOX DRAWINGS VERTICAL SINGLE AND LEFT DOUBLE'
    { uc_: 0x2562, twin_: 0xb6 }, // 054 unicode name: 'BOX DRAWINGS VERTICAL DOUBLE AND LEFT SINGLE'
    { uc_: 0x2556, twin_: 0xb7 }, // 055 unicode name: 'BOX DRAWINGS DOWN DOUBLE AND LEFT SINGLE'
    { uc_: 0x2555, twin_: 0xb8 }, // 056 unicode name: 'BOX DRAWINGS DOWN SINGLE AND LEFT DOUBLE'
    { uc_: 0x2563, twin_: 0xb9 }, // 057 unicode name: 'BOX DRAWINGS DOUBLE VERTICAL AND LEFT'
    { uc_: 0x2551, twin_: 0xba }, // 058 unicode name: 'BOX DRAWINGS DOUBLE VERTICAL'
    { uc_: 0x2557, twin_: 0xbb }, // 059 unicode name: 'BOX DRAWINGS DOUBLE DOWN AND LEFT'
    { uc_: 0x255d, twin_: 0xbc }, // 060 unicode name: 'BOX DRAWINGS DOUBLE UP AND LEFT'
    { uc_: 0x255c, twin_: 0xbd }, // 061 unicode name: 'BOX DRAWINGS UP DOUBLE AND LEFT SINGLE'
    { uc_: 0x255b, twin_: 0xbe }, // 062 unicode name: 'BOX DRAWINGS UP SINGLE AND LEFT DOUBLE'
    { uc_: 0x2510, twin_: 0xbf }, // 063 unicode name: 'BOX DRAWINGS LIGHT DOWN AND LEF'

    { uc_: 0x2514, twin_: 0xc0 }, // 064 unicode name: 'BOX DRAWINGS LIGHT UP AND RIGHT'
    { uc_: 0x2534, twin_: 0xc1 }, // 065 unicode name: 'BOX DRAWINGS LIGHT UP AND HORIZONTAL'
    { uc_: 0x252c, twin_: 0xc2 }, // 066 unicode name: 'BOX DRAWINGS LIGHT DOWN AND HORIZONTAL'
    { uc_: 0x251c, twin_: 0xc3 }, // 067 unicode name: 'BOX DRAWINGS LIGHT VERTICAL AND RIGHT'
    { uc_: 0x2500, twin_: 0xc4 }, // 068 unicode name: 'BOX DRAWINGS LIGHT HORIZONTAL'
    { uc_: 0x253c, twin_: 0xc5 }, // 069 unicode name: 'BOX DRAWINGS LIGHT VERTICAL AND HORIZONTAL'
    { uc_: 0x255e, twin_: 0xc6 }, // 070 unicode name: 'BOX DRAWINGS VERTICAL SINGLE AND RIGHT DOUBLE'
    { uc_: 0x255f, twin_: 0xc7 }, // 071 unicode name: 'BOX DRAWINGS VERTICAL DOUBLE AND RIGHT SINGLE'
    { uc_: 0x255a, twin_: 0xc8 }, // 072 unicode name: 'BOX DRAWINGS DOUBLE UP AND RIGHT'
    { uc_: 0x2554, twin_: 0xc9 }, // 073 unicode name: 'BOX DRAWINGS DOUBLE DOWN AND RIGHT'
    { uc_: 0x2569, twin_: 0xca }, // 074 unicode name: 'BOX DRAWINGS DOUBLE UP AND HORIZONTAL'
    { uc_: 0x2566, twin_: 0xcb }, // 075 unicode name: 'BOX DRAWINGS DOUBLE DOWN AND HORIZONTAL'
    { uc_: 0x2560, twin_: 0xcc }, // 076 unicode name: 'BOX DRAWINGS DOUBLE VERTICAL AND RIGHT'
    { uc_: 0x2550, twin_: 0xcd }, // 077 unicode name: 'BOX DRAWINGS DOUBLE HORIZONTAL'
    { uc_: 0x256c, twin_: 0xce }, // 078 unicode name: 'BOX DRAWINGS DOUBLE VERTICAL AND HORIZONTAL'
    { uc_: 0x2567, twin_: 0xcf }, // 079 unicode name: 'BOX DRAWINGS UP SINGLE AND HORIZONTAL DOUBLE'

    { uc_: 0x2568, twin_: 0xd0 }, // 080 unicode name: 'BOX DRAWINGS UP DOUBLE AND HORIZONTAL SINGLE'
    { uc_: 0x2564, twin_: 0xd1 }, // 081 unicode name: 'BOX DRAWINGS DOWN SINGLE AND HORIZONTAL DOUBLE'
    { uc_: 0x2565, twin_: 0xd2 }, // 082 unicode name: 'BOX DRAWINGS DOWN DOUBLE AND HORIZONTAL SINGL'
    { uc_: 0x2559, twin_: 0xd3 }, // 083 unicode name: 'BOX DRAWINGS UP DOUBLE AND RIGHT SINGLE'
    { uc_: 0x2558, twin_: 0xd4 }, // 084 unicode name: 'BOX DRAWINGS UP SINGLE AND RIGHT DOUBLE'
    { uc_: 0x2552, twin_: 0xd5 }, // 085 unicode name: 'BOX DRAWINGS DOWN SINGLE AND RIGHT DOUBLE'
    { uc_: 0x2553, twin_: 0xd6 }, // 086 unicode name: 'BOX DRAWINGS DOWN DOUBLE AND RIGHT SINGLE'
    { uc_: 0x256b, twin_: 0xd7 }, // 087 unicode name: 'BOX DRAWINGS VERTICAL DOUBLE AND HORIZONTAL SINGL'
    { uc_: 0x256a, twin_: 0xd8 }, // 088 unicode name: 'BOX DRAWINGS VERTICAL SINGLE AND HORIZONTAL DOUBLE'
    { uc_: 0x2518, twin_: 0xd9 }, // 089 unicode name: 'BOX DRAWINGS LIGHT UP AND LEFT'
    { uc_: 0x250c, twin_: 0xda }, // 090 unicode name: 'BOX DRAWINGS LIGHT DOWN AND RIGHT'
    { uc_: 0x2588, twin_: 0xdb }, // 091 unicode name: 'FULL BLOCK'
    { uc_: 0x2584, twin_: 0xdc }, // 092 unicode name: 'LOWER HALF BLOCK'
    { uc_: 0x258c, twin_: 0xdd }, // 093 unicode name: 'LEFT HALF BLOCK'
    { uc_: 0x2590, twin_: 0xde }, // 094 unicode name: 'RIGHT HALF BLOCK'
    { uc_: 0x2580, twin_: 0xdf }, // 095 unicode name: 'UPPER HALF BLOCK'

    { uc_: 0x03b1, twin_: 0xe0 }, // 096 unicode name: 'GREEK SMALL LETTER ALPHA'
    { uc_: 0x00df, twin_: 0xe1 }, // 097 unicode name: 'LATIN SMALL LETTER SHARP S'
	{ uc_: 0x03b2, twin_: 0xe1 }, // 097 #BG 04/01/13 Ajout
    { uc_: 0x0393, twin_: 0xe2 }, // 098 unicode name: 'GREEK CAPITAL LETTER GAMMA'
    { uc_: 0x03c0, twin_: 0xe3 }, // 099 unicode name: 'GREEK SMALL LETTER PI'
    { uc_: 0x03a3, twin_: 0xe4 }, // 100 unicode name: 'GREEK CAPITAL LETTER SIGMA'
    { uc_: 0x03c3, twin_: 0xe5 }, // 101 unicode name: 'GREEK SMALL LETTER SIGMA'
    { uc_: 0x03bc, twin_: 0xe6 }, // 102 unicode name: 'GREEK SMALL LETTER MU'
	{ uc_: 0x00b5, twin_: 0xe6 }, // 102 #BG 04/01/13 Ajout
    { uc_: 0x03c4, twin_: 0xe7 }, // 103 unicode name: 'GREEK SMALL LETTER TAU'
    { uc_: 0x03a6, twin_: 0xe8 }, // 104 unicode name: 'GREEK CAPITAL LETTER PHI'
    { uc_: 0x0398, twin_: 0xe9 }, // 105 unicode name: 'GREEK CAPITAL LETTER THETA'
    { uc_: 0x03a9, twin_: 0xea }, // 102 unicode name: 'GREEK CAPITAL LETTER OMEGA'
	{ uc_: 0x2126, twin_: 0xea }, // 102 #BG 04/01/13 Ajout
    { uc_: 0x03b4, twin_: 0xeb }, // 107 unicode name: 'GREEK SMALL LETTER DELTA'
    { uc_: 0x221e, twin_: 0xec }, // 108 unicode name: 'INFINITY'
    { uc_: 0x03c6, twin_: 0xed }, // 109 unicode name: 'GREEK SMALL LETTER PHI'
	{ uc_: 0x2205, twin_: 0xed }, // 109 #BG 04/01/13 Ajout
	{ uc_: 0x2300, twin_: 0xed }, // 109 #BG 04/01/13 Ajout
    { uc_: 0x03b5, twin_: 0xee }, // 110 unicode name: 'GREEK SMALL LETTER EPSILON'
	{ uc_: 0x2208, twin_: 0xee }, // 110 #BG 04/01/13 Ajout
    { uc_: 0x2229, twin_: 0xef }, // 111 unicode name: 'INTERSECTION'

    { uc_: 0x2261, twin_: 0xf0 }, // 112 unicode name: 'IDENTICAL TO'
    { uc_: 0x00b1, twin_: 0xf1 }, // 113 unicode name: 'PLUS-MINUS SIGN'
    { uc_: 0x2265, twin_: 0xf2 }, // 114 unicode name: 'GREATER-THAN OR EQUAL TO'
    { uc_: 0x2264, twin_: 0xf3 }, // 115 unicode name: 'LESS-THAN OR EQUAL TO'
    { uc_: 0x2320, twin_: 0xf4 }, // 116 unicode name: 'TOP HALF INTEGRAL'
    { uc_: 0x2321, twin_: 0xf5 }, // 117 unicode name: 'BOTTOM HALF INTEGRAL'
    { uc_: 0x00f7, twin_: 0xf6 }, // 118 unicode name: 'DIVISION SIGN'
    { uc_: 0x2248, twin_: 0xf7 }, // 119 unicode name: 'ALMOST EQUAL TO'
    { uc_: 0x00b0, twin_: 0xf8 }, // 120 unicode name: 'DEGREE SIGN'
	{ uc_: 0x02da, twin_: 0xf8 }, // 120 #BG 04/01/13 Ajout
	{ uc_: 0x030a, twin_: 0xf8 }, // 120 #BG 04/01/13 Ajout
    { uc_: 0x2219, twin_: 0xf9 }, // 121 unicode name: 'BULLET OPERATOR'
    { uc_: 0x00b7, twin_: 0xfa }, // 122 unicode name: 'MIDDLE DOT'
    { uc_: 0x221a, twin_: 0xfb }, // 123 unicode name: 'SQUARE ROOT'
    { uc_: 0x207f, twin_: 0xfc }, // 124 unicode name: 'SUPERSCRIPT LATIN SMALL LETTER N'
    { uc_: 0x00b2, twin_: 0xfd }, // 125 unicode name: 'SUPERSCRIPT TWO'
    { uc_: 0x25a0, twin_: 0xfe }, // 126 unicode name: 'BLACK SQUARE'
    { uc_: 0x00a0, twin_: 0xff }, // 127 unicode name: 'NO-BREAK SPACE'
	};

	u_int u;

	if ( ( uc & ~0x7f ) == 0 )
		return uc; // for ascii codes

	for ( u = 0; u < sizeof(tb)/sizeof(*tb); u++ ) {
		if ( tb[u].uc_ == uc )
			return tb[u].twin_;
	}

//	return 0; // unicode is non found in twin code table
//	return tb[126].twin_;	// Black square
	return 0xfe;	// Black square
}

int get_twin_code(char* c, int twin_codes, int with_gpm )
{
	struct Utf8Trancoder tr; // transcoder data struct

	char chbuf=*c;
	int flags = 0;
	u_char byte;
	u_short uc; // for unicode reception
	int cpt=1;

	utf8trancoder_init( &tr ); // transcoder struct initialisation

	byte = chbuf;
//	OUT( "byte(%02x)", byte );
#ifdef	_KEYB_TRACE
	if (KeybTrace == (FILE*)0)
		KeybTrace = fopen(KEYB_TRACE_FILE,"a");
	fprintf(KeybTrace,"Octet %d lu: %x\r\n", cpt, byte);
	fclose(KeybTrace);
	KeybTrace = (FILE*) 0;
#endif

	while ( utf8transcoder_putbyte( &tr, &uc, byte ) == 0 ) {
//		OUT( " --> unicode is not ready\n" );
		read( STDIN, &chbuf, sizeof(chbuf));
		byte = chbuf;
		cpt++;
#ifdef	_KEYB_TRACE
		if (KeybTrace == (FILE*)0)
			KeybTrace = fopen(KEYB_TRACE_FILE,"a");
		fprintf(KeybTrace,"Octet %d lu: %x\r\n", cpt, byte);
		fclose(KeybTrace);
		KeybTrace = (FILE*) 0;
#endif
#ifdef	_MOUSE_TRACE
// On ne passe pas ici avec des actions souris!
		if (MouseTrace == (FILE*)0)
			MouseTrace = fopen(MOUSE_TRACE_FILE,"a");
		fprintf(MouseTrace,"ixutf8.c 1: %d=read(STDIN,%x,N);\r\n", 1, byte);
		fclose(MouseTrace);
		MouseTrace = (FILE*) 0;
#endif
	}

//	OUT( " ==> unicode(U+%04x)", uc );
#ifdef	_KEYB_TRACE
	if (KeybTrace == (FILE*)0)
		KeybTrace = fopen(KEYB_TRACE_FILE,"a");
	fprintf(KeybTrace,"Car. UTF8 lu: (U+%04x)", uc);
	fclose(KeybTrace);
	KeybTrace = (FILE*) 0;
#endif
	if ( twin_codes ) {
		*c = trans_unicode_to_twnicode( uc );
//		OUT( " twincode(%02x)", twincode );
#ifdef	_KEYB_TRACE
		if (KeybTrace == (FILE*)0)
			KeybTrace = fopen(KEYB_TRACE_FILE,"a");
		fprintf(KeybTrace," => Car. Amenesik / Sologic: (%02x) %c\r\n", (unsigned char)*c), *c;
		fclose(KeybTrace);
		KeybTrace = (FILE*) 0;
#endif
	}

	return 1; // Ok
}

#endif	/* _ixutf8_c */
