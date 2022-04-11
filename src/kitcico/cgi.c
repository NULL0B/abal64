#define COULEUR
char *fichier="cgi";
char *nom ="(Console Driver Version 2.2 : cgi Cico Colour ($Date: 15 May 2002 13:30:00 ijm $)";


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

	"Content-type: text/plain\r\n\r\n",			/* initialisation               */
	"\r\n",		        				/* retour a l'etat initial      */

	/* attributs ecran */

	"",                /* fin d'attributs              */
	"",                /* attribut preferentiel        */
	"",                /* inversion video              */
	"",                /* clignotant                   */
	"",                /* souligne                     */
	"",                /* sous-brillance               */
	"",                /* sur-brillance                */

	/* couleurs du caractere */

#ifdef COULEUR
	"",               /* 0                            */
	"",               /* 1                            */
	"",               /* 2                            */
	"",               /* 3                            */
	"",               /* 4                            */
	"",               /* 5                            */
	"",               /* 6                            */
	"",               /* 7                            */
	"",               /* 8                            */
	"",               /* 9                            */
	"",               /* 10                           */
	"",               /* 11                           */
	"",               /* 12                           */
	"",               /* 13                           */
	"",               /* 14                           */
	"",               /* 15                           */
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
	"",               /* 0    */
	"",               /* 1    */
	"",               /* 2    */
	"",               /* 3    */
	"",               /* 4    */
	"",               /* 5    */
	"",               /* 6    */
	"",               /* 7    */
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

	"",                	/* positionnement curseur deb.  */
	"",                  	/* positionnement curseur p1    */
	"",                     /* positionnement curseur mil.  */
	"",                  	/* positionnement curseur p2    */
	"",                     /* positionnement curseur fin   */
	"",                 /* curseur vers droite          */
	"",                 /* curseur vers gauche          */
	"",                 /* curseur vers haut            */
	"",                 /* curseur vers bas             */
	"",                 /* effacement ecran             */
	"",                /* effac. fin de ligne          */
	"",                /* effac. fin d'ecran           */
	"",                /* insertion ligne              */
	"",                /* suppression ligne            */

	"",                /* insertion caractere          */
	"",                /* suppress. caractere          */

	"",                /* extinction curseur           */
	"",                /* reactivation curseur         */

	/* jeu de caracteres secondaire */

	"",                     /* entree dans jeu secondaire   */
	"",                     /* retour au jeu primaire       */
	"",                     /* car. demandant le jeu sec.   */

	/* touches accent */

	"",                 	/* accent trema                 */
	"",                    	/* accent circonflexe           */
	"",                    	/* accent tilde                 */
	"",                    	/* accent grave                 */
	"",                     /* accent aigu                  */
	"",    		        /* accent rond                  */
	"",                     /* cedille                      */

	/* touches non programmables */

	"",     	        /* 1    print screen    */
	"",     	        /* 2    ctrl home       */
	"",     	        /* 3    shift tab       */
	"", 	                /* 4    ctrl backspace  */
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

	"",             /* touche curseur droit         */
	"",             /* touche curseur gauche        */
	"",             /* touche curseur haut          */
	"",             /* touche curseur bas           */
	"",             /* touche home                  */
	"",             /* touche clear                 */
	"",             /* touche annulation            */
	"",                 /* touche break                 */

	"",             /* touche f1                    */
	"",             /* touche f2                    */
	"",             /* touche f3                    */
	"",             /* touche f4                    */
	"",             /* touche f5                    */
	"",             /* touche f6                    */
	"",             /* touche f7                    */
	"",             /* touche f8                    */
	"",             /* touche f9                    */
	"",             /* touche f10                   */
	"",             /* touche f11                   */
	"",             /* touche f12                   */
	"",             /* touche f13                   */
	"",             /* touche f14                   */
	"",             /* touche f15                   */
	"",             /* touche f16                   */
	"",             /* touche f17                   */
	"",             /* touche f18                   */
	"",             /* touche f19                   */
	"",             /* touche f20                   */
	"",             /* touche f21                   */
	"",             /* touche f22                   */
	"",             /* touche f23                   */
	"",             /* touche f24                   */
	"",             /* touche f25                   */
	"",             /* touche f26                   */
	"",             /* touche f27                   */
	"",             /* touche f28                   */
	"",             /* touche f29                   */
	"",             /* touche f30                   */
	"",             /* touche f31                   */
	"",             /* touche f32                   */
	"",             /* touche f33                   */
	"",             /* touche f34                   */
	"",             /* touche f35                   */
	"",             /* touche f36                   */
	"",             /* touche f37                   */
	"",             /* touche f38                   */
	"",             /* touche f39                   */
	"",             /* touche f40                   */
	"",             /* touche f41 (page up)         */
	"",             /* touche f42 (end)             */
	"",             /* touche f43 (page down)       */
	"",             /* touche f44 (insert)          */
	"",             /* touche f45 (delete)          */
	"",             /* touche f46 (ctrl page up)    */
	"",             /* touche f47 (ctrl end)        */
	"",             /* touche f48 (ctrl page down)  */
	"",             /* touche f49 (ctrl left)       */
	"",             /* touche f50 (ctrl right)      */

	/* chaines de retour des touches non programmables */

	"",                /* 1    hard copy       */
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

	"",	/* ouverture imprimante locale  */
	"",	/* fermeture imprimante locale  */

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

