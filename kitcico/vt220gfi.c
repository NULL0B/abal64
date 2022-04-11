/*
 *	CICO - Interface ECRAN / CLAVIER / IMPRIMANTE
 *	---------------------------------------------
 *
 *	Copyright (c) 1989 Prologue s.a.
 *
 *	vt220.c - fichier parametre pour DEC vt220
 *
 *	$Header:   C:/cico/fp/vt220.c@@   1.0   14 Sep 1989 15:53:40   NS  $
 *
 */


/*
 *	nom du fichier
 *	--------------
 */

char *fichier = "vt220gfi";


/*
 *	nom du terminal decrit
 *	----------------------
 */

char *nom = "DEC vt220 ($Date:   14 Sep 1989 15:53:40  $)";


/*
 *	table des nombres
 *	-----------------
 */

int tab_nb[] = {
	24,			/* nombre de lignes	*/
	80,			/* nombre de colonnes	*/
	8,			/* bits par caractere	*/
	9,			/* nombre de chaines sup*/
	-1,			/* FIN DES NOMBRES	*/
};


/*
 *	table des chaines
 *	-----------------
 */

char *tab_str[] = {

	/* parametrage visu */

				/* initialisation		*/
				/*				*/
				/* vt200 mode, 7 bits controls	*/
				/* 80 column			*/
				/* cursor key cursor mode	*/
				/* keypad numeric mode		*/
				/* multinational character set	*/
				/* text cursor on		*/
	"\033[62;1\"p\033[?3l\033[?1l\033>\033[?42l\033[?25h",
				/* retour a l'etat initial      */
				/*				*/
				/* vt100 mode			*/
	"\033[61\"p",

	/* attributs ecran */

	"\033[0m",              /* fin d'attributs              */
	"\033[7m",              /* attribut preferentiel        */
	"\033[7m",              /* inversion video              */
	"\033[5m",              /* clignotant                   */
	"\033[4m",              /* souligne                     */
	"",                     /* sous-brillance               */
	"\033[1m",              /* sur-brillance                */

	/* couleurs du caractere */

	"",                     /* 0                            */
	"",                     /* 1                            */
	"",                     /* 2                            */
	"",                     /* 3                            */
	"",                     /* 4                            */
	"",                     /* 5                            */
	"",                     /* 6                            */
	"",                     /* 7                            */
	"",                     /* 8                            */
	"",                     /* 9                            */
	"",                     /* 10                           */
	"",                     /* 11                           */
	"",                     /* 12                           */
	"",                     /* 13                           */
	"",                     /* 14                           */
	"",                     /* 15                           */

	/* couleurs de fond du caractere */

	"",                     /* 0    */
	"",                     /* 1    */
	"",                     /* 2    */
	"",                     /* 3    */
	"",                     /* 4    */
	"",                     /* 5    */
	"",                     /* 6    */
	"",                     /* 7    */

	/* fonctions ecran */

	"\033[",                /* positionnement curseur deb.  */
	"L+\001D",              /* positionnement curseur p1    */
	";",                    /* positionnement curseur mil.  */
	"C+\001D",              /* positionnement curseur p2    */
	"H",                    /* positionnement curseur fin   */
	"\033[C",               /* curseur vers droite          */
	"\033[D",               /* curseur vers gauche          */
	"\033[A",               /* curseur vers haut            */
	"\033[B",               /* curseur vers bas             */
	"\033[H\033[2J",        /* effacement ecran             */

	"\033[K",               /* effac. fin de ligne          */
	"\033[J",               /* effac. fin d'ecran           */
	"\033[L",               /* insertion ligne              */
	"\033[M",               /* suppression ligne            */

	"\033[@",               /* insertion caractere          */
	"\033[P",               /* suppress. caractere          */

	"\033[?25l",            /* extinction curseur           */
	"\033[?25h",            /* reactivation curseur         */

	/* jeu de caracteres secondaire */

	"\033(0",               /* entree dans jeu secondaire   */
	"\033(B",               /* retour au jeu primaire       */
				/* car. demandant le jeu sec.	*/
	"\260\261\262\263\264\265\266\267\
	 \270\271\272\273\274\275\276\277\
	 \300\301\302\303\304\305\306\307\
	 \310\311\312\313\314\315\316\317\
	 \320\321\323\324\325\326\327\
	 \330\331\332\357\362\363",
/*
	"\304\332\302\277\303\305\264\263\300\301\331\362\363\260\261\262",
*/
	/* touches accent */

	"",                     /* accent trema                 */
	"",                     /* accent circonflexe           */
	"",                     /* accent tilde                 */
	"",                     /* accent grave                 */
	"",                     /* accent aigu                  */
	"\260",                 /* accent rond                  */
	"",                     /* cedille                      */

	/* touches non programmables */

	"\033[23~",             /* 1    touche escape (f11)     */
	"\033[24~",             /* 2    touche backspace (f12)  */
	"\033[25~",             /* 3    touche line feed (f13)  */
	"\177",                 /* 4    touche backspace (del)  */
	"\033[28~",             /* 5    touche aide             */
	"\033[29~",             /* 6    touche executer         */
	"\033[1~",              /* 7    touche rech.            */
	"\033[4~",              /* 8    touche select           */
	"",                     /* 9    */
	"",                     /* 10   */
	"",                     /* 11   */
	"",                     /* 12   */
	"",                     /* 13   */
	"",                     /* 14   */
	"",                     /* 15   */
	"",                     /* 16   */
	"",                     /* 17   */
	"",                     /* 18   */
	"",                     /* 19   */
	"",                     /* 20   */
	"",                     /* 21   */
	"",                     /* 22   */
	"",                     /* 23   */
	"",                     /* 24   */
	"",                     /* 25   */
	"",                     /* 26   */
	"",                     /* 27   */
	"",                     /* 28   */
	"",                     /* 29   */
	"",                     /* 30   */
	"",                     /* 31   */
	"",                     /* 32   */
	"",                     /* 33   */
	"",                     /* 34   */
	"",                     /* 35   */
	"",                     /* 36   */
	"",                     /* 37   */
	"",                     /* 38   */
	"",                     /* 39   */
	"",                     /* 40   */

	/* touches programmables */

	"\033[C",               /* touche curseur droit         */
	"\033[D",               /* touche curseur gauche        */
	"\033[A",               /* touche curseur haut          */
	"\033[B",               /* touche curseur bas           */
	"\033[1~",              /* touche home                  */
	"",                     /* touche clear                 */
	"",                     /* touche annulation            */
	"",                     /* touche break                 */

	"\033OP",               /* touche f1                    */
	"\033OQ",               /* touche f2                    */
	"\033OR",               /* touche f3                    */
	"\033OS",               /* touche f4                    */
	"\033[16~",             /* touche f5                    */
	"\033[17~",             /* touche f6                    */
	"\033[18~",             /* touche f7                    */
	"\033[19~",             /* touche f8                    */
	"\033[20~",             /* touche f9                    */
	"\033[21~",             /* touche f10                   */
	"\033[22~",             /* touche f11                   */
	"\033[23~",             /* touche f12                   */
	"",                     /* touche f13                   */
	"\033[26~",             /* touche f14                   */
	"",                     /* touche f15                   */
	"",                     /* touche f16                   */
	"\033[31~",             /* touche f17                   */
	"\033[32~",             /* touche f18                   */
	"\033[33~",             /* touche f19                   */
	"\033[34~",             /* touche f20                   */
	"\033OP",               /* touche f21                   */
	"\033OQ",               /* touche f22                   */
	"\033OR",               /* touche f23                   */
	"\033OS",               /* touche f24                   */
	"",                     /* touche f25                   */
	"",                     /* touche f26                   */
	"",                     /* touche f27                   */
	"",                     /* touche f28                   */
	"",                     /* touche f29                   */
	"",                     /* touche f30                   */
	"",                     /* touche f31                   */
	"",                     /* touche f32                   */
	"",                     /* touche f33                   */
	"",                     /* touche f34                   */
	"",                     /* touche f35                   */
	"",                     /* touche f36                   */
	"",                     /* touche f37                   */
	"",                     /* touche f38                   */
	"",                     /* touche f39                   */
	"",                     /* touche f40                   */
	"\033[5~",              /* touche f41 (page up)         */
	"",                     /* touche f42 (end)             */
	"\033[6~",              /* touche f43 (page down)       */
	"\033[2~",              /* touche f44 (insert)          */
	"\033[3~",              /* touche f45 (delete)          */
	"",                     /* touche f46 (ctrl page up)    */
	"",                     /* touche f47 (ctrl end)        */
	"",                     /* touche f48 (ctrl page down)  */
	"",                     /* touche f49 (ctrl left)       */
	"",                     /* touche f50 (ctrl right)      */

	/* chaines de retour des touches non programmables */

	"\033",                 /* 1    touche escape (f11)     */
	"\010",                 /* 2    touche backspace (f12)  */
	"\012",                 /* 3    touche line feed (f13)  */
	"\010",                 /* 4    touche backspace (del)  */
	"",                     /* 5    */
	"",                     /* 6    */
	"",                     /* 7    */
	"",                     /* 8    */
	"",                     /* 9    */
	"",                     /* 10   */
	"",                     /* 11   */
	"",                     /* 12   */
	"",                     /* 13   */
	"",                     /* 14   */
	"",                     /* 15   */
	"",                     /* 16   */
	"",                     /* 17   */
	"",                     /* 18   */
	"",                     /* 19   */
	"",                     /* 20   */
	"",                     /* 21   */
	"",                     /* 22   */
	"",                     /* 23   */
	"",                     /* 24   */
	"",                     /* 25   */
	"",                     /* 26   */
	"",                     /* 27   */
	"",                     /* 28   */
	"",                     /* 29   */
	"",                     /* 30   */
	"",                     /* 31   */
	"",                     /* 32   */
	"",                     /* 33   */
	"",                     /* 34   */
	"",                     /* 35   */
	"",                     /* 36   */
	"",                     /* 37   */
	"",                     /* 38   */
	"",                     /* 39   */
	"",                     /* 40   */

	/* chaines d'affichage des caracteres composes */

	"", "", "", "", "", "", "", "",                 /* 0 */
	"", "", "", "", "", "", "", "",
	"", "", "", "", "", "", "", "",                 /* 1 */
	"", "", "", "", "", "", "", "",
	"", "", "", "", "", "", "", "",                 /* 2 */
	"", "", "", "", "", "", "", "",
	"", "", "", "", "", "", "", "",                 /* 3 */
	"", "", "", "", "", "", "", "",
	"", "", "", "", "", "", "", "",                 /* 4 */
	"", "", "", "", "", "", "", "",
	"", "", "", "", "", "", "", "",                 /* 5 */
	"", "", "", "", "", "", "", "",
	"", "", "", "", "", "", "", "",                 /* 6 */
	"", "", "", "", "", "", "", "",
	"", "", "", "", "", "", "", "",                 /* 7 */
	"", "", "", "", "", "", "", "",
	"", "", "", "", "", "", "", "",                 /* 8 */
	"", "", "", "", "", "", "", "",
	"", "", "", "", "", "", "", "",                 /* 9 */
	"", "", "", "", "", "", "", "",
	"", "", "", "", "", "", "", "",                 /* a */
	"", "", "", "", "", "", "", "",
	"", "", "", "", "", "", "", "",                 /* b */
	"", "", "", "", "", "", "", "",
	"", "", "", "", "", "", "", "",                 /* c */
	"", "", "", "", "", "", "", "",
	"", "", "", "", "", "", "", "",                 /* d */
	"", "", "", "", "", "", "", "",
	"", "", "", "", "", "", "", "",                 /* e */
	"", "", "", "", "", "", "", "",
	"", "", "", "", "", "", "", "",                 /* f */
	"", "", "", "", "", "", "", "",


	/* sequences d'ouverture et fermeture d'imprimante locale */

	"\233\065i",		/* ouverture imprimante locale  */
	"\233\064i",		/* fermeture imprimante locale  */

	/* fonctions supplementaires version 2.2	*/

	"",	/* mode page			*/
	"",	/* mode scroll			*/
	"",	/* status bar on		*/
	"",	/* status bar off		*/
	"",	/* read function key		*/
	"",	/* write function key		*/
	"",	/* Mouse Event Prefix		*/
	"",	/* Mouse ON Sequence  		*/
	"",	/* Mouse OFF Sequence  		*/

	/* fin de table */

	(char *)0,
};


/*
 *	table de conversion clavier
 *	---------------------------
 */

char tab_in[256] = {
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 	/* 0 */
	0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
	0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 	/* 1 */
	0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
	' ',  '!',  '"',  '#',  '$',  '%',  '&',  '\'',         /* 2 */
	'(',  ')',  '*',  '+',  ',',  '-',  '.',  '/',
	'0',  '1',  '2',  '3',  '4',  '5',  '6',  '7',          /* 3 */
	'8',  '9',  ':',  ';',  '<',  '=',  '>',  '?',
	'@',  'A',  'B',  'C',  'D',  'E',  'F',  'G',          /* 4 */
	'H',  'I',  'J',  'K',  'L',  'M',  'N',  'O',
	'P',  'Q',  'R',  'S',  'T',  'U',  'V',  'W',          /* 5 */
	'X',  'Y',  'Z',  '[',  '\\', ']',  '^',  '_',
	'`',  'a',  'b',  'c',  'd',  'e',  'f',  'g',          /* 6 */
	'h',  'i',  'j',  'k',  'l',  'm',  'n',  'o',
	'p',  'q',  'r',  's',  't',  'u',  'v',  'w',          /* 7 */
	'x',  'y',  'z',  '{',  '|',  '}',  '~',  0xf7,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 	/* 8 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 	/* 9 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xad, 0x96, 0x9c, 0x00, 0x9d, 0x00, 0xd2, 	/* a */
	0x00, 0x00, 0x00, 0xae, 0x00, 0x00, 0x00, 0x00,
	0xf8, 0xf1, 0xfd, 0x00, 0x00, 0xe6, 0xe3, 0xfa, 	/* b */
	0x00, 0x00, 0x00, 0xaf, 0xac, 0xab, 0x00, 0xa8,
	0xb5, 0xb6, 0xb7, 0xb8, 0x9e, 0x8f, 0x92, 0x80, 	/* c */
	0xb9, 0x90, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xc6,
	0x00, 0xa5, 0xc7, 0xc8, 0xc9, 0xca, 0x99, 0xd7, 	/* d */
	0xd0, 0xcb, 0xcc, 0xcd, 0x9a, 0x00, 0x00, 0xe1,
	0x85, 0xa0, 0x83, 0xce, 0x84, 0x86, 0x91, 0x87, 	/* e */
	0x8a, 0x82, 0x88, 0x89, 0x8d, 0xa1, 0x8c, 0x8b,
	0x00, 0xa4, 0x95, 0xa2, 0x93, 0xcf, 0x94, 0xd6, 	/* f */
	0xed, 0x97, 0xa3, 0x96, 0x81, 0x98, 0x00, 0x00,
};


/*
 *	table de conversion ecran
 *	-------------------------
 */

char tab_out[256] = {
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 	/* 0 */
	0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
	0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 	/* 1 */
	0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
	' ',  '!',  '"',  '#',  '$',  '%',  '&',  '\'',         /* 2 */
	'(',  ')',  '*',  '+',  ',',  '-',  '.',  '/',
	'0',  '1',  '2',  '3',  '4',  '5',  '6',  '7',          /* 3 */
	'8',  '9',  ':',  ';',  '<',  '=',  '>',  '?',
	'@',  'A',  'B',  'C',  'D',  'E',  'F',  'G',          /* 4 */
	'H',  'I',  'J',  'K',  'L',  'M',  'N',  'O',
	'P',  'Q',  'R',  'S',  'T',  'U',  'V',  'W',          /* 5 */
	'X',  'Y',  'Z',  '[',  '\\', ']',  '^',  '_',
	'`',  'a',  'b',  'c',  'd',  'e',  'f',  'g',          /* 6 */
	'h',  'i',  'j',  'k',  'l',  'm',  'n',  'o',
	'p',  'q',  'r',  's',  't',  'u',  'v',  'w',          /* 7 */
	'x',  'y',  'z',  '{',  '|',  '}',  '~',  0xf7,
	0xc7, 0xfc, 0xe9, 0xe2, 0xe4, 0xe0, 0xe5, 0xe7, 	/* 8 */
	0xea, 0xeb, 0xe8, 0xef, 0xee, 0xec, 0xc4, 0xc5,
	0xc9, 0xe6, 0xc6, 0xf4, 0xf6, 0xf2, 0xfb, 0xf9, 	/* 9 */
	0xfd, 0xd6, 0xdc, 0xa2, 0xa3, 0xa5, ' ',  ' ',
	0xe1, 0xcd, 0xf3, 0xfa, 0xf1, 0xd1, 0xaa, 0xba, 	/* a */
	0xbf, ' ',  ' ',  0xbd, 0xbc, 0xa1, 0xab, 0xbb,
	'a',  'a',  'a',  'x',  'u',  'u',  'u', 'k',           /* b */
	'k',  'u',  'x',  'k',  'j',  'j',  'j', 'k',
	'm',  'v',  'w',  't',  'q',  'n',  't', 't',         /* c */
	'm',  'l',  'v',  'w',  't',  'q',  'n', 'v',
	'v',  'w',  0xa7, 'm',  'm',  'l',  'l', 'n',         /* d */
	'n',  'j',  'l',  ' ',  ' ',  ' ',  ' ',  ' ',
	' ',  0xdf, ' ',  ' ',  ' ',  ' ',  0xb5, ' ',          /* e */
	' ',  ' ',  ' ',  ' ',  ' ',  0xf8, ' ',  'w',
	' ',  0xb1, 'z',  'y',  ' ',  ' ',  ' ',  ' ',          /* f */
	0xb0, ' ',  ' ',  '>',  ' ',  0xb2, ' ',  ' ',
};

/* fin de fichier */
