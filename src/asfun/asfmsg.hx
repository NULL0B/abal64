#define LGMEMAX 80

BYTE * tabmes[MAXMES+1];

static char mentete[][LGMEMAX] = { 

	"*STX*2  SFUN  11b00",
	"  ",
	"Confirmer",
	"Votre Choix",
	"vValider",
	"o  Oui  ",
	"n  Non  ",
	"aAbandon",
	"TAB pour le choix",
	"Modification de texte ",
	"Lig:",
	"Col:",
	"Insertion",
	"Aide",
	"Aide Chapitres",
	"Aide Sous-Chapitres",
	"Oui",
	"Non",

/*	Padding pour la traduction des messages */
/*	--------------------------------------- */

"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",

	"*ETX*",
	"fin"
};

/* Fin de fichier - asfmsg.hx ------ */


