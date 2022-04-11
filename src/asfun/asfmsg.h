/*---------------------------------------------------------------EDMSG.H -----
 *
 *	ASFUN	  -	Copyright Amenesik / Sologic s.a. (c) 1989
 *
 *		   	Messages de asfun
 *
 *		      Revision 1.0 du 11/09/1991
 *
 *--------------------------------------------------------------------------*/

#ifdef HX
#include "asfmsg.hx"
#else
BYTE * tabmes[] =
  {
	"*STX*2  SFUN  13a00",
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
	"                               ",
	"                               ",
	"                               ",
	"                               ",
	"                               ",
	"                               ",
	"                               ",
	"*ETX*",
	"fin"
	  };

#endif

BYTE * tablang0[] =	/* francais */

  {	"Confirmer",
	"Votre Choix",
	"vValider",
	"o  Oui  ",
	"n  Non  ",
	"aAbandon",
	"TAB pour le choix","Modification de texte ",
	"Lig:","Col:","Insertion","Aide",
	"Aide Chapitres","Aide Sous-Chapitres",
	"Oui","Non"
   };

BYTE * tablang1[] =	/* anglais */

  {	"Confirm",
	"Your Choice",
	"v Valid ",
	"y  Yes  ",
	"n  No   ",
	"a Abort ",
	"TAB for selection","Text modification",
	"Line:","Col:","Insertion","Help",
	"Help Chapter","Help Sub-Chapter",
	"Yes","No"
   };

BYTE * tablang2[] =	/* allemand */

  {	"Best„tigen",
	"Ihre Wahl",
	"e Enter ",
	"j  Ja   ",
	"n Nein  ",
	"aAbbruch"
	,"TAB fr Auswahl","Žndern des Textes",
	"Zeile:","Spalte:","Einfgen","HILFE",
	"HILFE Kapitel","HILFE Unterkapitel",
	"Ja","Nein"
   };

BYTE * tablang3[] =	/* espagnol */

  {	"Confirmar",
	"Opci¢n",
	"v Validar",
	"s   Si   ",
	"n   No   ",
	"aAbandono",
	"TAB para opci¢n","Modificaci¢n de texto",
	"Lin:","Col:","Inserci¢n","Ayuda",
	"Ayuda capitulos","Ayuda Subcapitulos",
	"Si","No"
   };

BYTE * tablang4[] =	/* italien */

  {	"Confermare",
	"Vostra Scelta",
	"vValidare",
	"s   Si   ",
	"n   No   ",
	"l Lascia ",
	"TAB per la scelta","Modifica del testo",
	"Riga:","Col:","Inserzione","Aiuto",
	"Aiuto Capitali","Auito Sotto-Capitali",
	"Si","No"
   };

BYTE * tablang5[] =	/* Hollandais */

  {	"Bevestigen",
	"Uw Keuze   ",
	"bBevestigen",
	"j  Ja   ",
	"n  Nee  ",
	"vVerlaten",
	"Voor Keuze ->TAB","Tekst Wijzigen",
	"Reg:","Kol:","Invoegen","Help",
	"Help Hoofstukken","Help Sub-Hoofdsuk",
	"Yes","No"
   };

/* Fin de fichier ---- asfmsg.h --------- */



