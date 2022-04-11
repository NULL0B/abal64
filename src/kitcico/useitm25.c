/*
($Date: 2002/04/04 13:42:43 $)
CICO=useit:/opt/prologue/lib/cico:1 
*/

#define COULEUR
char *fichier="useitm25";
char *nom ="(Console Driver Version 2.2 : Linux Colour ($Date: 2003/10/29 13:00:00 $)";

int tab_nb[] = 
{
    25,
    80,
    8,
    9,
    -1
};

char* tab_str[] = 
{
    // terminal control 
    "\033[s",	//+0. initialisation de terminal
    "\033[u",	//+1. retour etat initial

    // screen atributs 
    "\033[0m",	//+2. ESC a (reset atributs)
    "\033[7m",	//+3. ESC p (preferential)
    "\033[7m",	//+4. ESC b (inverse video)
    "\033[5m",	//+5. ESC c (blinking)
    "\033[4m",	//+6. ESC d (underlined)
    "",		//+7. ESC e (dim/lowlight)
    "\033[1m",	//+8. ESC h (bright/highlight)

    // Character Paint Foreground Colours 
    "\033[22;30m", //+9. 0 Black
    "\033[22;31m", //+10. 1 Red
    "\033[22;32m", //+11. 2 Green
    "\033[22;33m", //+12. 3 Brown/Yellow
    "\033[22;34m", //+13. 4 Blue
    "\033[22;35m", //+14. 5 Magenta/Purple
    "\033[22;36m", //+15. 6 Cyan (Pale Light Blue)
    "\033[22;37m", //+16. 7 Light Grey/Whitish
    "\033[30;1m",  //+17. 8 Dark Grey
    "\033[31;1m",  //+18. 9 Pinkish
    "\033[32;1m",  //+19. 10 Lime Green
    "\033[33;1m",  //+20. 11 Frightning Yellow
    "\033[34;1m",  //+21. 12 Bright Blue
    "\033[35;1m",  //+22. 13 Startling Purple
    "\033[36;1m",  //+23. Sky Blue
    "\033[37;1m",  //+24. Dazzling White (OMO)

    // Background Paint Colours 
    "\033[40m",	//+25. 0 Black as Hell
    "\033[41m",	//+26. 1 Red Devil
    "\033[42m",	//+27. 2 Seasickness Green
    "\033[43m",	//+28. 3 Shit Brown
    "\033[44m",	//+29. 4 Bullfrog Blue
    "\033[45m",	//+30. 5 Royal Purple
    "\033[46m",	//+31. 6 Cyanure
    "\033[47m",	//+32. 7 Dull White

    // Screen Functions 
    "\033[",	//+33. cursor position : start
    "L+\001D",	//+34. cursor position : p1	
    ";",	//+35. cursor position : middle
    "C+\001D",	//+36. cursor position : p2	
    "H",	//+37. cursor position : end

    "\033[C",       //+38. cursor right
    "\033[D",       //+39. cursor left
    "\033[A",       //+40. cursor up
    "\033[B",       //+41. cursor down
    "\033[H\033[2J",//+42. clear screen
    "\033[K",       //+43. clear to end of line
    "\033[J",       //+44. clear to end of screen
    "\033[L",       //+45. insert line	
    "\033[M",       //+46. delete line 
    "\033[@",       //+47. Insert character
    "\033[P",       //+48. Delete character
    "\033[?25l",    //+49. Hide curser	
    "\033[?25h",    //+50. Show curser	

    // Secondary Character Table Management 
    "", //+51. Enter Second Table
    "", //+52. Return to Primary
    "", //+53. The List of Characters requiring Secondary Table 

    // Accent characters (7 strings)
    "",		/* trema				*/
    "",		/* circonflexe				*/
    "",		/* tilde				*/
    "",		/* grave				*/
    "",		/* acute				*/
    "\260",	/* round				*/
    "",		/* cedile				*/

    // Unprogrammable Keys (40 strings)
    "\x7F",	/* 1 Print Screen			*/
    "\033OQ",	/* 2 Ctrl Home				*/
    "\033OR",	/* 3 Shift Tab				*/
    "\033OS",	/* 4 Ctrl Backspace			*/
    "\033OP",	/* 5					*/
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
	
    // Programmable Keys (8 strings)
    "\033[C",	/* right arrow key		*/
    "\033[D",	/* left arrow key		*/
    "\033[A",	/* up arrow key			*/
    "\033[B",	/* down arrow key		*/
    "\033[H",	/* home key			*/
    "",		/* clear key			*/
    "",		/* Cancel Key			*/
    "",		/* Break Key			*/

    // Function Keys 1 to 20 (50 strings)
    "\033[11~",	/* function key 1		*/
    "\033[12~",	/* function key 2		*/
    "\033[13~",	/* function key 3		*/
    "\033[14~",	/* function key 4		*/
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
    // Function Keys 21 to 40 
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
    "\033[F",   // was "\033[4~",  key 42 : end
    "\033[6~",	/* key 43 : page down		*/
    "\033[2~",	/* key 44 : insert		*/
    "\033[3~",	/* key 45 : delete		*/
    "",		/* Ctrl Page Up			*/
    "",		/* Ctrl End			*/
    "",		/* Ctrl Page Up			*/
    "",		/* Ctrl Left			*/
    "",		/* Ctrl Right			*/

    // Return Strings ()
    "\010", /* 1 */
    "/",	/* 2 */
    "*",	/* 3 */
    "-",	/* 4 */
    "",	/* 5 */
    "",	/* 6 */
    "",	/* 7 */
    "",	/* 8 */
    "",	/* 9 */
    "",	/* 10 */
    "",	/* 11 */
    "",	/* 12 */
    "",	/* 13 */
    "",	/* 14 */
    "",	/* 15 */
    "",	/* 16 */
    "",	/* 17 */
    "",	/* 18 */
    "",	/* 19 */
    "",	/* 20 */
    "",	/* 21 */
    "",	/* 22 */
    "",	/* 23 */
    "",	/* 24 */
    "",	/* 25 */
    "",	/* 26 */
    "",	/* 27 */
    "",	/* 28 */
    "",	/* 29 */
    "",	/* 30 */
    "",	/* 31 */
    "",	/* 32 */
    "",	/* 33 */
    "",	/* 34 */
    "",	/* 35 */
    "",	/* 36 */
    "",	/* 37 */
    "",	/* 38 */
    "",	/* 39 */
    "",	/* 40 */
	
    // chaines d'affichage des caracteres composes 
#define _EMPTY() ""
#define CP(a) "\x1b[11m" #a "\x1b[10m"
_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(), //0
_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),
_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(), //1
_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),
_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(), //2
_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),
_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(), //3
_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),
_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(), //4
_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),
_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(), //5
_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),
_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(), //6
_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),
_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(), //7
_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),CP(\x7F),
_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(), //8
_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),
_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(), //9
_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),CP(\x9E),CP(\x9F),
_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(), //A
_EMPTY(),CP(\xA9),CP(\xAA),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),_EMPTY(),
CP(\xB0),CP(\xB1),CP(\xB2),CP(\xB3),CP(\xB4),CP(\xB5),CP(\xB6),CP(\xB7), //B
CP(\xB8),CP(\xB9),CP(\xBA),CP(\xBB),CP(\xBC),CP(\xBD),CP(\xBE),CP(\xBF),
CP(\xC0),CP(\xC1),CP(\xC2),CP(\xC3),CP(\xC4),CP(\xC5),CP(\xC6),CP(\xC7), //C
CP(\xC8),CP(\xC9),CP(\xCA),CP(\xCB),CP(\xCC),CP(\xCD),CP(\xCE),CP(\xCF),
CP(\xD0),CP(\xD1),_EMPTY(),CP(\xD3),CP(\xD4),CP(\xD5),CP(\xD6),CP(\xD7), //D
CP(\xD8),CP(\xD9),CP(\xDA),CP(\xDB),CP(\xDC),CP(\xDD),CP(\xDE),CP(\xDF),
CP(\xE0),CP(\xE1),CP(\xE2),CP(\xE3),CP(\xE4),CP(\xE5),CP(\xE6),CP(\xE7), //E
CP(\xE8),CP(\xE9),CP(\xEA),CP(\xEB),CP(\xEC),CP(\xED),CP(\xEE),CP(\xEF),
CP(\xF0),CP(\xF1),CP(\xF2),CP(\xF3),CP(\xF4),CP(\xF5),CP(\xF6),CP(\xF7), //F
CP(\xF8),CP(\xF9),CP(\xFA),CP(\xFB),CP(\xFC),CP(\xFD),CP(\xFE),CP(\xFF),
#undef _EMPTY
#undef CP
	
    // sequences d'ecchapement de l'imprimante deportee 
    "\2335i",
    "\2334i",

    "", //?? enter page mode
    "", //?? leave page mode
    "", //?? show status bar
    "", //?? hide status bar
    "", //?? read function keys
    "", //?? write function keys
  	"\033[M",	/* Mouse Event Prefix		*/
	"\033[?9h\033[?1007h",	/* Mouse ON Sequence  		*/
	"\033[?9l\033[?1007l",	/* Mouse OFF Sequence  		*/

    (char *) 0
};

char  tab_in[256] = 
{
#define NO() 0x00
  0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, /* 0 */
  0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
  0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, /* 1 */
  0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
  0x20, '!' , '"' , '#' , '$' , '%' , '&' , 0x27, /* 2 */
  '(' , ')' , '*' , '+' , ',' , '-' , '.' , '/' ,
  '0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' , /* 3 */
  '8' , '9' , ':' , ';' , '<' , '=' , '>' , '?' ,
  '@' , 'A' , 'B' , 'C' , 'D' , 'E' , 'F' , 'G' , /* 4 */
  'H' , 'I' , 'J' , 'K' , 'L' , 'M' , 'N' , 'O' ,
  'P' , 'Q' , 'R' , 'S' , 'T' , 'U' , 'V' , 'W' , /* 5 */
  'X' , 'Y' , 'Z' , '[' , 0x5C, ']' , '^' , '_' ,
  '`' , 'a' , 'b' , 'c' , 'd' , 'e' , 'f' , 'g' , /* 6 */
  'h' , 'i' , 'j' , 'k' , 'l' , 'm' , 'n' , 'o' ,
  'p' , 'q' , 'r' , 's' , 't' , 'u' , 'v' , 'w' , /* 7 */
  'x' , 'y' , 'z' , '{' , '|' , '}' , '~' , 0xF7,
  NO(), NO(), NO(), NO(), NO(), NO(), NO(), NO(), /* 8 */
  NO(), NO(), NO(), NO(), NO(), NO(), NO(), NO(),
  NO(), NO(), NO(), NO(), NO(), NO(), NO(), NO(), /* 9 */
  NO(), NO(), NO(), NO(), NO(), NO(), NO(), NO(),
  NO(), 0xAD, NO(), 0x9C, 0x9B, 0x9D, NO(), 0xD2, /* A */
  NO(), NO(), NO(), 0xAE, NO(), NO(), NO(), NO(),
  0xF8, 0xF1, 0xFD, NO(), NO(), 0xE6, NO(), 0xFA, /* B */
  NO(), NO(), NO(), 0xAF, 0xAC, 0xAB, NO(), 0xA8,
  NO(), NO(), NO(), NO(), 0x8E, 0x8F, 0x92, 0x80, /* C */
  NO(), NO(), NO(), NO(), NO(), NO(), NO(), NO(),
  NO(), 0xA5, NO(), NO(), NO(), NO(), 0x99, NO(), /* D */
  NO(), NO(), NO(), NO(), 0x9A, NO(), NO(), 0xE1,
  0x85, 0xA0, 0x83, NO(), 0x84, 0x86, 0x91, 0x87, /* E */
  0x8A, 0x82, 0x88, 0x89, 0x8D, 0xA1, 0x8C, 0x8B,
  NO(), 0xA4, 0x95, 0xA2, 0x93, NO(), 0x94, 0xF6, /* F */
  0xED, 0x97, 0xA3, 0x96, 0x81, NO(), NO(), 0x98,
#undef NO
};

char tab_out[256] = 
{
#define CP() 0x00
  0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, /* 0 */
  0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
  0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, /* 1 */
  0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
  0x20, '!' , '"' , '#' , '$' , '%' , '&' , 0x27, /* 2 */
  '(' , ')' , '*' , '+' , ',' , '-' , '.' , '/' ,
  '0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' , /* 3 */
  '8' , '9' , ':' , ';' , '<' , '=' , '>' , '?' ,
  '@' , 'A' , 'B' , 'C' , 'D' , 'E' , 'F' , 'G' , /* 4 */
  'H' , 'I' , 'J' , 'K' , 'L' , 'M' , 'N' , 'O' ,
  'P' , 'Q' , 'R' , 'S' , 'T' , 'U' , 'V' , 'W' , /* 5 */
  'X' , 'Y' , 'Z' , '[' , 0x5C, ']' , '^' , '_' ,
  '`' , 'a' , 'b' , 'c' , 'd' , 'e' , 'f' , 'g' , /* 6 */
  'h' , 'i' , 'j' , 'k' , 'l' , 'm' , 'n' , 'o' ,
  'p' , 'q' , 'r' , 's' , 't' , 'u' , 'v' , 'w' , /* 7 */
  'x' , 'y' , 'z' , '{' , '|' , '}' , '~' , CP(),
  0xC7, 0xFC, 0xE9, 0xE2, 0xE4, 0xE0, 0xE5, 0xE7, /* 8 */
  0xEA, 0xEB, 0xE8, 0xEF, 0xEE, 0xEC, 0xC4, 0xC5,
  0xC9, 0xE6, 0xC6, 0xF4, 0xF6, 0xF2, 0xFB, 0xF9, /* 9 */
  0xFF, 0xD6, 0xDC, 0xA4, 0xA3, 0xA5, CP(), CP(),
  0xE1, 0xED, 0xF3, 0xFA, 0xF1, 0xD1, 0xAA, 0xBA, /* A */
  0xBF, CP(), CP(), 0xBD, 0xBC, 0xA1, 0xAB, 0xBB,
  CP(), CP(), CP(), CP(), CP(), CP(), CP(), CP(), /* B */
  CP(), CP(), CP(), CP(), CP(), CP(), CP(), CP(),
  CP(), CP(), CP(), CP(), CP(), CP(), CP(), CP(), /* C */
  CP(), CP(), CP(), CP(), CP(), CP(), CP(), CP(),
  CP(), CP(), 0xA7, CP(), CP(), CP(), CP(), CP(), /* D */
  CP(), CP(), CP(), CP(), CP(), CP(), CP(), CP(),
  CP(), CP(), CP(), CP(), CP(), CP(), CP(), CP(), /* E */
  CP(), CP(), CP(), CP(), CP(), CP(), CP(), CP(),
  CP(), CP(), CP(), CP(), CP(), CP(), CP(), CP(), /* F */
  CP(), CP(), CP(), CP(), CP(), CP(), CP(), CP(),
#undef CP
};
/* end of file */


