#define COULEUR
char *fichier="xfree424";
char *nom ="(Console Driver Version 2.2 : Linux Colour ($Date: 03 Nov 2006 11:58:00 ijm/bg $)";

int tab_nb[] = {
	24,
	80,
	8,
	9,
	-1
};

char *tab_str[] = {

	/* terminal control */
	/* ---------------- */
	"",		/* open  terminal 		*/
	"\033[0m",	/* close terminal		*/

	/* screen atributs */
	/* --------------- */
	"\033[0m",	/* ESC a (reset atributs)	*/
	"\033[7m",	/* ESC p (preferential)		*/
	"\033[7m",	/* ESC b (inverse video)	*/
	"\033[5m",	/* ESC c (blinking)		*/
	"\033[4m",	/* ESC d (underlined)		*/
	"",		/* ESC e (dim/lowlight)		*/
	"\033[1m",	/* ESC h (bright/highlight)	*/

	/* Character Paint Foreground Colours */
	/* ---------------------------------- */
	"\033[22;30m",	/* 0 Black			*/
	"\033[22;31m",	/* 1 Red			*/
	"\033[22;32m",	/* 2 Green 			*/
	"\033[22;33m",  /* 3 Brown/Yellow 		*/
	"\033[22;34m",	/* 4 Blue			*/
	"\033[22;35m",  /* 5 Magenta/Purple		*/
	"\033[22;36m",	/* 6 Cyan (Pale Light Blue)	*/
	"\033[22;37m",	/* 7 Light Grey/Whitish		*/
	"\033[30;1m",	/* 8 Dark Grey			*/
	"\033[31;1m",	/* 9 Pinkish			*/
	"\033[32;1m",	/* 10 Lime Green		*/
	"\033[33;1m",	/* 11 Frightning Yellow		*/
	"\033[34;1m",	/* 12 Bright Blue		*/
	"\033[35;1m",	/* 13 Startling Purple		*/
	"\033[36;1m",	/* 14 Sky Blue			*/
	"\033[37;1m",	/* 15 Dazzling White (OMO)	*/

	/* Background Paint Colours */
	/* ------------------------ */
	"\033[40m",	/* 0 Black as Hell		*/
	"\033[41m",	/* 1 Red Devil			*/
	"\033[42m",	/* 2 Seasickness Green 		*/
	"\033[43m",	/* 3 Shit Brown			*/
	"\033[44m",	/* 4 Bullfrog Blue	 	*/ 
	"\033[45m",	/* 5 Royal Purple		*/
	"\033[46m",	/* 6 Cyanure			*/
	"\033[47m",	/* 7 Dull White			*/


	/* Screen Functions */
	/* ---------------- */
	"\033[",	/* cursor position : start	*/
	"L+\001D",	/* cursor position : p1		*/
	";",		/* cursor position : middle	*/
	"C+\001D",	/* cursor position : p2		*/
	"H",		/* cursor position : end	*/

	"\033[C",	/* cursor right			*/
	"\033[D",	/* cursor left			*/
	"\033[A",	/* cursor up			*/
	"\033[B",	/* cursor down			*/
	"\033[H\033[2J",/* clear screen			*/
	"\033[K",	/* clear to end of line		*/
	"\033[J",	/* clear to end of screen	*/
	"\033[L",	/* insert line			*/
	"\033[M",	/* delete line 			*/
	"\033[@",	/* Insert character		*/
	"\033[P",	/* Delete character		*/
	"\033[?25l",	/* Hide curser			*/
	"\033[?25h",	/* Show curser			*/

	/* Secondary Character Table Management */

	"\033(0",	/* Enter Second Table		*/
	"\033(B",	/* Return to Primary		*/

	/* The List of Characters requiring Secondary Table */
	/* ------------------------------------------------ */
	"\260\261\262\263\264\265\266\267\270\271\272\273\274\275\276\277\011\040\300\301\302\303\304\305\306\307\310\311\312\313\314\315\316\317\011\040\320\321\323\324\325\326\327\330\331\332\333\334\335\336\337\357\362\363\376",


	/* Accent characters */
	/* ----------------- */

	"",		/* trema				*/
	"",		/* circonflexe				*/
	"",		/* tilde				*/
	"",		/* grave				*/
	"",		/* acute				*/
	"\260",		/* round				*/
	"",		/* cedile				*/

	/* Unprogrammable Keys */
	/* ------------------- */
	"",		/* 1 Print Screen			*/
	"",		/* 2 Ctrl Home				*/
	"",		/* 3 Shift Tab				*/
	"",		/* 4 Ctrl Backspace			*/
	"",		/* 5					*/
	"",		/* 6		*/
	"",		/* 7		*/
	"",		/* 8		*/
	"",		/* 9		*/
	"",		/* 10		*/
	"",		/* 11		*/
	"",		/* 12		*/
	"",		/* 13		*/
	"",		/* 14		*/
	"",		/* 15		*/
	"",		/* 16		*/
	"",		/* 17		*/
	"",		/* 18		*/
	"",		/* 19		*/
	"",		/* 20		*/
	"",		/* 21		*/
	"",		/* 22		*/
	"",		/* 23		*/
	"",		/* 24		*/
	"",		/* 25		*/
	"",		/* 26		*/
	"",		/* 27		*/
	"",		/* 28		*/
	"",		/* 29		*/
	"",		/* 30		*/
	"",		/* 31		*/
	"",		/* 32		*/
	"",		/* 33		*/
	"",		/* 34		*/
	"",		/* 35		*/
	"",		/* 36		*/
	"",		/* 37		*/
	"",		/* 38		*/
	"",		/* 39		*/
	"",		/* 40		*/
	
	/* Programmable Keys */
	/* ----------------- */

	"\033[C",	/* right arrow key		*/
	"\033[D",	/* left arrow key		*/
	"\033[A",	/* up arrow key			*/
	"\033[B",	/* down arrow key		*/
	"\033[H",	/* home key			*/
	"",		/* clear key			*/
	"",		/* Cancel Key			*/
	"",		/* Break Key			*/

	/* Function Keys 1 to 20 */
	/* --------------------- */
	"\033OP",	/* function key 1		*/
	"\033OQ",	/* function key 2		*/
	"\033OR",	/* function key 3		*/
	"\033OS",	/* function key 4		*/
	"\033[15~",	/* function key 5		*/
	"\033[17~",	/* function key 6		*/
	"\033[18~",	/* function key 7		*/
	"\033[19~",	/* function key 8		*/
	"\033[20~",	/* function key 9		*/
	"\033[21~",	/* function key 10		*/
	"\033[23~",	/* function key 11		*/
	"\033[24~",	/* function key 12		*/
	"\033[25~",	/* function key 13		*/
	"\033[26~",	/* function key 14		*/
	"\033[27~",	/* function key 15		*/
	"\033[28~",	/* function key 16		*/
	"\033[29~",	/* function key 17		*/
	"\033[2A~",	/* function key 18		*/
	"\033[2B~",	/* function key 19		*/
	"\033[2C~",	/* function key 20		*/

	/* Function Keys 21 to 40 */
	/* ---------------------- */	
	"",		/* function key 21		*/
	"",		/* function key 22		*/
	"",		/* function key 23		*/
	"",		/* function key 24		*/
	"",		/* function key 25		*/
	"",		/* function key 26		*/
	"",		/* function key 27		*/
	"",		/* function key 28		*/
	"",		/* function key 29		*/
	"",		/* function key 30		*/
	"",		/* function key 31		*/
	"",		/* function key 32		*/
	"",		/* function key 33		*/
	"",		/* function key 34		*/
	"",		/* function key 35		*/
	"",		/* function key 36		*/
	"",		/* function key 37		*/
	"",		/* function key 38		*/
	"",		/* function key 39		*/
	"",		/* function key 40		*/

	"\033[5~",	/* key 41 : page up		*/
	"\033[F", 	/* key 42 : end			*/
	"\033[6~",	/* key 43 : page down		*/
	"\033[2~",	/* key 44 : insert		*/
	"\033[3~",	/* key 45 : delete		*/

	"",		/* Ctrl Page Up			*/
	"",		/* Ctrl End			*/
	"",		/* Ctrl Page Up			*/
	"",		/* Ctrl Left			*/
	"",		/* Ctrl Right			*/

	/* Return Strings */
	"\010",
	"/",
	"*",
	"-",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"\2335i",
	"\2334i",

	"",
	"",

	"",
	"",

	"",
	"",

  	"\033[M",	/* Mouse Event Prefix		*/
	"\033[?9h\033[?1000h",	/* Mouse ON Sequence  		*/
	"\033[?9l\033[?1000l",	/* Mouse OFF Sequence  		*/


	(char *) 0
};
char  tab_in[256] = {
	0x0,0x1,0x2,0x3,0x4,0x5,0x6,0x7,
	0x8,0x9,0xa,0xb,0xc,0xd,0xe,0xf,
	0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,
	0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f,
	0x20,'!','"','#','$','%','&',0x27,
	'(',')','*','+',',','-','.','/',
	'0','1','2','3','4','5','6','7',
	'8','9',':',';','<','=','>','?',
	'@','A','B','C','D','E','F','G',
	'H','I','J','K','L','M','N','O',
	'P','Q','R','S','T','U','V','W',
	'X','Y','Z','[',0x5c,']','^','_',
	'`','a','b','c','d','e','f','g',
	'h','i','j','k','l','m','n','o',
	'p','q','r','s','t','u','v','w',
	'x','y','z','{','|','}','~',0xf7,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0xad,0x96,0x9c,0x0,0x9d,0x0,0xd2,
	0x0,0x0,0x0,0xae,0x0,0x0,0x0,0x0,
	0xf8,0xf1,0xfd,0x0,0x0,0xe6,0xe3,0xfa,
	0x0,0x0,0x0,0xaf,0xac,0xab,0x0,0xa8,
	0xb5,0xb6,0xb7,0xb8,0x9e,0x8f,0x92,0x80,
	0xb9,0x90,0xba,0xbb,0xbc,0xbd,0xbe,0xc6,
	0x0,0xa5,0xc7,0xc8,0xc9,0xca,0x99,0xd7,
	0xd0,0xcb,0xcc,0xcd,0x9a,0x0,0x0,0xe1,
	0x85,0xa0,0x83,0xce,0x84,0x86,0x91,0x87,
	0x8a,0x82,0x88,0x89,0x8d,0xa1,0x8c,0x8b,
	0x0,0xa4,0x95,0xa2,0x93,0xcf,0x94,0xd6,
	0xed,0x97,0xa3,0x96,0x81,0x98,0x0,0x0
};
char  tab_out[256] = {
	0x0,0x1,0x2,0x3,0x4,0x5,0x6,0x7,
	0x8,0x9,0xa,0xb,0xc,0xd,0xe,0xf,
	0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,
	0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f,
	0x20,'!','"','#','$','%','&',0x27,
	'(',')','*','+',',','-','.','/',
	'0','1','2','3','4','5','6','7',
	'8','9',':',';','<','=','>','?',
	'@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O',
	'P','Q','R','S','T','U','V','W','X','Y','Z','[',0x5c,']','^','_',
	'`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o',
	'p','q','r','s','t','u','v','w','x','y','z','{','|','}','~',0xf7,

	0xc7,0xfc,0xe9,0xe2,0xe4,0xe0,0xe5,0xe7,
	0xea,0xeb,0xe8,0xef,0xee,0xec,0xc4,0xc5,
	0xc9,0xe6,0xc6,0xf4,0xf6,0xf2,0xfb,0xf9,
	0xfd,0xd6,0xdc,0xa2,0xa3,0xa5,0x20,0x20,
	0xe1,0xcd,0xf3,0xfa,0xf1,0xd1,0xaa,0xba,
	0xbf,0x20,0x20,0xbd,0xbc,0xa1,0xab,0xbb,
/* B0 */	'a','a','a','x','u','u','u','k',
		'k','u','x','k','j','j','j','k',
/* C0 */	'm','v','w','t','q','n','t','t',
		'm','l','v','w','t','q','n','v',
/* D0 */	'v','w',0xa7,'m','m','l','l','n',
/* D8 */	'n','j','l','a','a','a','a','a',

 	0x2E,0xdf,0x2E,0x2E,0x2E,0x2E,0xb5,0x2E,
	0x2E,0x2E,0x2E,0x2E,0x2E,0xf8,0x2E,'w',
	0x2E,0xb1,'z','y',0x2E,0x2E,0x2E,0x2E,
	0xb0,0x2E,0x2E,'>',0x2E,0xb2,0xb0,0x2E
};
/* end of file */


