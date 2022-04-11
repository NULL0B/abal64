/*	------------------------------------------------------------------ */
/*	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server */
/*	------------------------------------------------------------------ */
#ifndef	_iviewmsg_c
#define _iviewmsg_c

#include "iviewmsg.h"


#define	NBGESMES 74

#define	MSGQTY		3 + NBGESMES /* Standard Messages + Module Messages 	   */

#define MSGMAXLEN 	40

char *	message_table[MSGQTY];

#ifdef	_IS_FRENCH
char	message_buffer[MSGQTY+8][MSGMAXLEN] = {
#ifdef	_WORLD_WIDE_WEB
#ifdef	_NV11B
	"*STX*3NV      11b00",
#else
	"*STX*3NV      11a00",
#endif
#else
	"*STX*3NAVIG   11b00",
#endif
#else
static char *	french_message[ NBGESMES+ 1 ] = {
#endif

	"on",

	"Navigateur hypertexte",
	"Erreur",

/*	These Messages are Used to describe HTTP status	codes	*/
/*	-----------------------------------------------------	*/
	"OK",
	"Cr‚‚", 
	"Accept‚", 
	"Informations partielles", 
	"Pas de reponse", 
	"Deplac‚", 
	"Trouv‚", 
	"Methode", 
	"Non modifi‚", 
	"Requˆte incorrecte", 
	"Non-authoris‚", 
	"Paiement requise", 
	"Interdit", 
	"Non trouv‚", 
	"Erreur interne", 
	"Non implement‚", 
	"Service satur‚", 
	"GATEWAY TIMEOUT", 

/*	These Messages are Used by the Menu Options display	*/
/*	---------------------------------------------------	*/
	"Pr‚c",		/* Back		*/
	"Suiv",		/* Forward	*/
	"Vers",		/* Goto		*/
	"Charge",	/* Reload	*/
	"Imprime",	/* Print	*/
	"Options",	/* Options	*/
	"Halt",		/* Halt		*/
	"Nom",		/* New		*/
	"Rech",		/* Search	*/
	"Mode",		/* Head		*/
	"Quitter",	/* Exit		*/
	"Valider",	/* Validate	*/
	"Effacer",	/* Effacer	*/
	"Inserer",	/* Insert	*/
	"Supprimer",	/* Delete	*/
	"Quitter",	/* Quit		*/

/*	These iviewmsg are displayed by the Browser 	*/
/*	------------------------------------------- 	*/
	"Chargement du document",
	"Rechargement du document",
	"Impression du document",
	"Historique",
	"Impression de l'eran",
	"Ajout de racourcie",

	"Envoi",
	"Efface",
	"Page",

	"Compactage de la memoire",
	"Connexion",
	"Erreur fatale",

	"RC pour abandonner, ESC pour continuer",
	"Impression abandonn‚e",

/*	Distant Access Service State Messages	*/

	"Ligne connect‚e",
	"Num‚rotation en cours",
	"Connexion en cours",
	"Ligne d‚connect‚e",

	"PPP inactif",
	"PPP actif",
	"Etablissement PPP",
	"Authentification PPP",
	"Arrˆt du PPP",
	"Abandoner, Re‚ssayer, Continuer",

	"Utilisation",
	"Affichage de la banniŠre",
	"Affichage des options",
	"Activation de l'‚cho",
	"Mode texte forc‚",
	"Nom de fichier de configuration",
	"fichier",
	"erreur de cr‚ation de fichier",
	"erreur d'‚criture du fichier",
	"erreur d'allocation m‚moire",
	"Voulez vous quitter ? (O/N)",
	"Oui, je veux quitter",
	"Non, je ne veux pas quitter",
	"Zoom"
#ifdef	_IS_FRENCH
	,"*ETX*",

/*	Padding in case of GesMes Overflow during translation 	*/


	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#endif

	};

#ifdef	_IS_FRENCH
static	int	message_flag=1;
#else
static	int	message_flag=0;
#endif

#ifdef	_IS_ENGLISH
char	message_buffer[MSGQTY+8][MSGMAXLEN] = {
#ifdef	_WORLD_WIDE_WEB
#ifdef	_NV11B
	"*STX*3NV      11b00",
#else
	"*STX*3NV      11a00",
#endif
#else
	"*STX*3NAVIG   11b00",
#endif
#else
static char *	english_message[ NBGESMES+ 1 ] = {
#endif
	"yn",

	"Html Navigator",
	"Error",

	"OK",
	"Created", 
	"Accepted", 
	"Partial information", 
	"No response", 
	"Moved", 
	"Found", 
	"Method", 
	"Not modified", 
	"Bad request", 
	"Unauthorised", 
	"Payment required", 
	"Forbidden", 
	"Not found", 
	"Internal error", 
	"Not implemented", 
	"Service overloaded", 
	"Gateway timeout", 

	"Back",
	"Forward",
	"Goto",
	"Reload",
	"Print",
	"Options",
	"Halt",
	"New",
	"Search",
	"Mode",
	"Exit",
	"Validate",
	"Reset",
	"Insert",
	"Delete",
	"Quit",

/*	These iviewmsg are displayed by the Browser 	*/
/*	------------------------------------------- 	*/
	"Loading document",
	"Reloading document",
	"Printing document",
	"Browser History",
	"Printing Screen",
	"Bookmark Added",

	"Submit",
	"Reset",
	"Page",
	"Garbage Collection",
	"Connect",
	"Fatal error",
	"Abandon with ENTER or ESC to continue",
	"Print job aborted",

/*	Distant Access Service State Messages	*/

	"Line connected",
	"Dialing",
	"Connecting",
	"Line disconnected",

	"PPP offline",
	"PPP online",
	"PPP Connecting",
	"PPP Handshaking",
	"PPP Closure",
	"Abort, Retry, Continue",

	"Usage",
	"Display banner",
	"Display options",
	"Activate source echo",
	"Force text mode",
	"Configuration filename",
	"file",
	"error creating file",
	"error writing to file",
	"memory allocation error",
	"Do you really want to exit ? (Y/N) ",
	"Yes, exit now",
	"No, don't exit yet",
	"Zoom"

#ifdef	_IS_ENGLISH
	,"*ETX*",

/*	Padding in case of GesMes Overflow during translation 	*/


	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#endif

	};

void	initialise_iviewmsg()
{
	int	x;
	char *	wptr;
	wptr = 	& message_buffer[0][0];
	x = 0;

	do	{
		while ( *wptr )  wptr++;
		while (!(*wptr)) wptr++;
		message_table[x++] = wptr;
		}

	while ( x < MSGQTY );
	return;
}

char *	gesmessage( int n )
{
#ifdef	_IS_FRENCH
	if ( message_flag )
		return( message_table[n] );
	else	return( english_message[ n ] );
#else
	if (!( message_flag ))
		return( message_table[n] );
	else	return( french_message[ n ] );
#endif
}

void	setgesmeslang( int l )
{
	message_flag  = l;
	return;
}

int	getgesmeslang()
{
	return(message_flag);
}


#endif	/* _iviewmsg_c	*/


