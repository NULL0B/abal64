#define COULEUR
char *fichier="xcico";
char *nom ="(Console Driver Version 2.2 : Amenesik / Sologic Cico Colour/Mouse ($Date: 15 May 2002 13:30:00 ijm $)";


int tab_nb[] = {
	24,			/* nombre de lignes			*/
	80,			/* nombre de colonnes			*/
	8,			/* bits par caractere			*/
	9,			/* nombre de chaines supplementaires	*/	
	-1,			/* FIN DES NOMBRES			*/
};


/*
 *	table des chaines
 *	-----------------
 */

char *tab_str[] = {

	/* parametrage visu */

	"",                     /* initialisation               */
	"",                     /* retour a l'etat initial      */

	/* attributs ecran */

	"\033a",                /* fin d'attributs              */
	"\033p",                /* attribut preferentiel        */
	"\033b",                /* inversion video              */
	"\033c",                /* clignotant                   */
	"\033d",                /* souligne                     */
	"\033e",                /* sous-brillance               */
	"\033h",                /* sur-brillance                */

	/* couleurs du caractere */

#ifdef COULEUR
	"\033r0",               /* 0                            */
	"\033r1",               /* 1                            */
	"\033r2",               /* 2                            */
	"\033r3",               /* 3                            */
	"\033r4",               /* 4                            */
	"\033r5",               /* 5                            */
	"\033r6",               /* 6                            */
	"\033r7",               /* 7                            */
	"\033r8",               /* 8                            */
	"\033r9",               /* 9                            */
	"\033rA",               /* 10                           */
	"\033rB",               /* 11                           */
	"\033rC",               /* 12                           */
	"\033rD",               /* 13                           */
	"\033rE",               /* 14                           */
	"\033rF",               /* 15                           */
#else
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
#endif /* COULEUR */

	/* couleurs de fond du caractere */

#ifdef COULEUR
	"\033s0",               /* 0    */
	"\033s1",               /* 1    */
	"\033s2",               /* 2    */
	"\033s3",               /* 3    */
	"\033s4",               /* 4    */
	"\033s5",               /* 5    */
	"\033s6",               /* 6    */
	"\033s7",               /* 7    */
#else
	"",                     /* 0    */
	"",                     /* 1    */
	"",                     /* 2    */
	"",                     /* 3    */
	"",                     /* 4    */
	"",                     /* 5    */
	"",                     /* 6    */
	"",                     /* 7    */
#endif /* COULEUR */

	/* fonctions ecran */

	"\033f",                /* positionnement curseur deb.  */
	"C+ ",                  /* positionnement curseur p1    */
	"",                     /* positionnement curseur mil.  */
	"L+ ",                  /* positionnement curseur p2    */
	"",                     /* positionnement curseur fin   */
	"\006",                 /* curseur vers droite          */
	"\010",                 /* curseur vers gauche          */
	"\013",                 /* curseur vers haut            */
	"\005",                 /* curseur vers bas             */
	"\014",                 /* effacement ecran             */
	"\033K",                /* effac. fin de ligne          */
	"\033J",                /* effac. fin d'ecran           */
	"\033L",                /* insertion ligne              */
	"\033M",                /* suppression ligne            */

	"\033@",                /* insertion caractere          */
	"\033P",                /* suppress. caractere          */

	"\033w",                /* extinction curseur           */
	"\033v",                /* reactivation curseur         */

	/* jeu de caracteres secondaire */

	"",                     /* entree dans jeu secondaire   */
	"",                     /* retour au jeu primaire       */
	"",                     /* car. demandant le jeu sec.   */

	/* touches accent */

	"\321",                 /* accent trema                 */
	"^",                    /* accent circonflexe           */
	"~",                    /* accent tilde                 */
	"`",                    /* accent grave                 */
	"",                     /* accent aigu                  */
	"\370",                 /* accent rond                  */
	"",                     /* cedille                      */

	/* touches non programmables */

	"\033P",                /* 1    print screen    */
	"\037\352",             /* 2    ctrl home       */
	"\037\000",             /* 3    shift tab       */
	"\177",                 /* 4    ctrl backspace  */
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

	/* touches programmables */

	"\006",             /* touche curseur droit         */
	"\010",             /* touche curseur gauche        */
	"\013",             /* touche curseur haut          */
	"\005",             /* touche curseur bas           */
	"\034",             /* touche home                  */
	"\014",             /* touche clear                 */
	"\001",             /* touche annulation            */
	"",                 /* touche break                 */

	"\033]a",             /* touche f1                    */
	"\033]b",             /* touche f2                    */
	"\033]c",             /* touche f3                    */
	"\033]d",             /* touche f4                    */
	"\033]e",             /* touche f5                    */
	"\033]f",             /* touche f6                    */
	"\033]g",             /* touche f7                    */
	"\033]h",             /* touche f8                    */
	"\033]i",             /* touche f9                    */
	"\033]j",             /* touche f10                   */
	"\033]k",             /* touche f11                   */
	"\033]l",             /* touche f12                   */
	"\033]m",             /* touche f13                   */
	"\033]n",             /* touche f14                   */
	"\033]o",             /* touche f15                   */
	"\033]p",             /* touche f16                   */
	"\033]q",             /* touche f17                   */
	"\033]r",             /* touche f18                   */
	"\033]s",             /* touche f19                   */
	"\033]t",             /* touche f20                   */
	"\033]A",             /* touche f21                   */
	"\033]B",             /* touche f22                   */
	"\033]C",             /* touche f23                   */
	"\033]D",             /* touche f24                   */
	"\033]E",             /* touche f25                   */
	"\033]F",             /* touche f26                   */
	"\033]G",             /* touche f27                   */
	"\033]H",             /* touche f28                   */
	"\033]I",             /* touche f29                   */
	"\033]J",             /* touche f30                   */
	"\033]K",             /* touche f31                   */
	"\033]L",             /* touche f32                   */
	"\033]M",             /* touche f33                   */
	"\033]N",             /* touche f34                   */
	"\033]O",             /* touche f35                   */
	"\033]P",             /* touche f36                   */
	"\033]Q",             /* touche f37                   */
	"\033]R",             /* touche f38                   */
	"\033]S",             /* touche f39                   */
	"\033]T",             /* touche f40                   */
	"\037\022",             /* touche f41 (page up)         */
	"\002",             /* touche f42 (end)             */
	"\037\004",             /* touche f43 (page down)       */
	"\017",             /* touche f44 (insert)          */
	"\177",             /* touche f45 (delete)          */
	"\037\250",             /* touche f46 (ctrl page up)    */
	"\037\251",             /* touche f47 (ctrl end)        */
	"\037\252",             /* touche f48 (ctrl page down)  */
	"\037\253",             /* touche f49 (ctrl left)       */
	"\037\254",             /* touche f50 (ctrl right)      */

	/* chaines de retour des touches non programmables */

	"\033O",                /* 1    hard copy       */
	"",                     /* 2    */
	"",                     /* 3    */
	"",                     /* 4    */
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

	"\033*",	/* ouverture imprimante locale  */
	"\033+",	/* fermeture imprimante locale  */

	/* fonctions supplementaires version 2.2	*/

	"\033t",	/* mode page			*/
	"\033u",	/* mode scroll			*/
	"\033V",	/* status bar on		*/
	"\033W",	/* status bar off		*/
	"\033j",	/* read function key		*/
	"\033k",	/* write function key		*/
	"\033m",	/* Mouse Event Prefix		*/
	"\033m2",	/* Mouse ON Sequence  		*/
	"\033m0",	/* Mouse OFF Sequence  		*/

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
	0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 	/* 8 */
	0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
	0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 	/* 9 */
	0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
	0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 	/* a */
	0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf,
	0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 	/* b */
	0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf,
	0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 	/* c */
	0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf,
	0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 	/* d */
	0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf,
	0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 	/* e */
	0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
	0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 	/* f */
	0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff,
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
	'x',  'y',  'z',  '{',  '|',  '}',  '~',  ' ',
	0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 	/* 8 */
	0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
	0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 	/* 9 */
	0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
	0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 	/* a */
	0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf,
	0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 	/* b */
	0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf,
	0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 	/* c */
	0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf,
	0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 	/* d */
	0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf,
	0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 	/* e */
	0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
	0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 	/* f */
	0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff,
};

