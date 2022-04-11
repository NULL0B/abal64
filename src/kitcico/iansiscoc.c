/*
 *	CICO - Interface ECRAN / CLAVIER / IMPRIMANTE
 *	---------------------------------------------
 *
 *	Copyright (c) 1988 Amenesik / Sologic s.a.
 *
 *	iansicsco.c - fichier parametre pour terminal SCO ENIX Couleur
 *
 *	$Header:   iansiscoc.c   1.4   23 Aug 1990 14:35:28   NS  $
 *
 */


/*
 *	nom du fichier
 *	--------------
 */

char *fichier = "iansiscoc";


/*
 *	nom du terminal decrit
 *	----------------------
 */

char *nom = "emulation type sco unix/xenix avec imprimante (26 09 94  14:35:28  $)";


/*
 *	table des nombres
 *	-----------------
 */

int tab_nb[] = {
	25,			/* nombre de lignes	*/
	80,			/* nombre de colonnes	*/
	8,			/* bits par caractere	*/

	-1,			/* FIN DES NOMBRES	*/
};


/*
 *	table des chaines
 *	-----------------
 */

char *tab_str[] = {

	/* parametrage visu */

	"",                     /* initialisation               */
	"\033[J",                     /* retour a l'etat initial      */

	/* attributs ecran */

	"\033[0m",	        /* fin d'attributs              */
	"\033[7m",              /* attribut preferentiel        */
	"\033[7m",              /* inversion video              */
	"\033[5m",              /* clignotant                   */
	"\033[4m",              /* souligne                     */
	"",                     /* sous-brillance               */
	"\033[1m",              /* sur-brillance                */

	/* couleurs du caractere */

	"\033[=0F\033[0m",                     /* noir                         */
	"\033[=4F\033[0m",                     /* rouge                        */
	"\033[=2F\033[0m",                     /* vert                         */
	"\033[=6F\033[0m",                     /* marron / jaune fonce         */
	"\033[=1F\033[0m",                     /* bleu                         */
	"\033[=5F\033[0m",                     /* magenta                      */
	"\033[=3F\033[0m",                     /* cyan                         */
	"\033[=7F\033[0m",                     /* gris clair / blanc           */
	"\033[=8F\033[0m",                     /* gris fonce                   */
	"\033[=12F\033[0m",                     /* rouge clair                  */
	"\033[=10F\033[0m",                     /* vert clair                   */
	"\033[=14F\033[0m",                     /* jaune                        */
	"\033[=9F\033[0m",                     /* bleu clair                   */
	"\033[=13F\033[0m",                     /* magenta clair                */
	"\033[=11F\033[0m",                     /* cyan clair                   */
	"\033[=15F\033[0m",                     /* blanc brillant               */

	/* couleurs de fond du caractere */

	"\033[=0G\033[0m",                     /* noir                         */
	"\033[=4G\033[0m",                     /* rouge                        */
	"\033[=2G\033[0m",                     /* vert                         */
	"\033[=6G\033[0m",                     /* marron / jaune fonce         */
	"\033[=1G\033[0m",                     /* bleu                         */
	"\033[=5G\033[0m",                     /* magenta                      */
	"\033[=3G\033[0m",                     /* cyan                         */
	"\033[=7G\033[0m",                     /* gris clair / blanc           */

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

	"\033[=32;32C",         /* extinction curseur           */
	"\033[=10;11C",         /* reactivation curseur         */

	/* jeu de caracteres secondaire */

	"",                     /* entree dans jeu secondaire   */
	"",                     /* retour au jeu primaire       */
	"",                     /* car. demandant le jeu sec.   */

	/* touches accent */

	"\261",                 /* accent trema                 */
	"\260",                 /* accent circonflexe           */
	"~",                    /* accent tilde                 */
	"`",                    /* accent grave                 */
	"",                     /* accent aigu                  */
	"\370",                 /* accent rond                  */
	"",                     /* cedille                      */

	/* touches non programmables */

	"\033[w",               /* 1    Ctrl Maj F1             */
	"\033[x",               /* 2    Ctrl Maj F2             */
	"\033[y",               /* 3    Ctrl Maj F3             */
	"\033[z",               /* 4    Ctrl Maj F4             */
	"\033[@",               /* 5    Ctrl Maj F5             */
	"\033[[",               /* 6    Ctrl Maj F6             */
	"\033[\\",              /* 7    Ctrl Maj F7             */
	"\033[]",               /* 8    Ctrl Maj F8             */
	"\033[^",               /* 9    Ctrl Maj F9             */
	"\033[_",               /* 10   Ctrl Maj F10            */
	"\033[`",               /* 11   Ctrl Maj F11            */
	"\033[{",               /* 12   Ctrl Maj F12            */
	"\033[E",               /* 13   5 keypad                */
	"",			/* 14   */
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
	"\033[H",               /* touche home                  */
	"",                     /* touche clear                 */
	"",                     /* touche annulation            */
	"",                     /* touche break                 */

	"\033[M",               /* touche f1                    */
	"\033[N",               /* touche f2                    */
	"\033[O",               /* touche f3                    */
	"\033[P",               /* touche f4                    */
	"\033[Q",               /* touche f5                    */
	"\033[R",               /* touche f6                    */
	"\033[S",               /* touche f7                    */
	"\033[T",               /* touche f8                    */
	"\033[U",               /* touche f9                    */
	"\033[V",               /* touche f10                   */
	"\033[W",               /* touche f11                   */
	"\033[X",               /* touche f12                   */
	"\033[Y",               /* touche f13                   */
	"\033[Z",               /* touche f14                   */
	"\033[a",               /* touche f15                   */
	"\033[b",               /* touche f16                   */
	"\033[c",               /* touche f17                   */
	"\033[d",               /* touche f18                   */
	"\033[e",               /* touche f19                   */
	"\033[f",               /* touche f20                   */
	"\033[g",               /* touche f21                   */
	"\033[h",               /* touche f22                   */
	"\033[i",               /* touche f23                   */
	"\033[j",               /* touche f24                   */
	"\033[k",               /* touche f25                   */
	"\033[l",               /* touche f26                   */
	"\033[m",               /* touche f27                   */
	"\033[n",               /* touche f28                   */
	"\033[o",               /* touche f29                   */
	"\033[p",               /* touche f30                   */
	"\033[q",               /* touche f31                   */
	"\033[r",               /* touche f32                   */
	"\033[s",               /* touche f33                   */
	"\033[t",               /* touche f34                   */
	"\033[u",               /* touche f35                   */
	"\033[v",               /* touche f36                   */
	"",                     /* touche f37                   */
	"",                     /* touche f38                   */
	"",                     /* touche f39                   */
	"",                     /* touche f40                   */
	"\033[I",               /* touche f41 (page up)         */
	"\033[F",               /* touche f42 (end)             */
	"\033[G",               /* touche f43 (page down)       */
	"\033[L",               /* touche f44 (insert)          */
	"\177",                 /* touche f45 (delete)          */
	"",                     /* touche f46 (ctrl page up)    */
	"",                     /* touche f47 (ctrl end)        */
	"",                     /* touche f48 (ctrl page down)  */
	"",                     /* touche f49 (ctrl left)       */
	"",                     /* touche f50 (ctrl right)      */

	/* chaines de retour des touches non programmables */

	"",                     /* 1    */
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

	"\033[5i",		/* ouverture imprimante locale  */
	"\033[4i",		/* fermeture imprimante locale  */


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
	0x5e, 0xd1, 0xd2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 	/* b */
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
	'x',  'y',  'z',  '{',  '|',  '}',  '~',  0x7f, /*14' ',*/
	0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 	/* 8 */
	0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
	0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 	/* 9 */
	0x98, 0x99, 0x9a, 'c',  0x9c, 0x9d, 0x9e, 0x9f,
	0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 	/* a */
	0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf,
	0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 	/* b */
	0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf,
	0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 	/* c */
	0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf,
	0xd0, 0xd1, 0x9f /*14d2*/, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 	/* d */
	0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf,
	0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 	/* e */
	0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xd2 /*14ef*/,
	0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 	/* f */
	0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff,
};


/* fin de fichier */
