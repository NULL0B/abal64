/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1991
 *	Module  : TTY
 *	Fichier : UTTY.C
 *	Version : 1.2a
 *	Date    : 06/04/92
 *	Systeme : UNIX
 *
 *	Procedure TTY sous UNIX
 *
 *	[Corps de la bibliotheque dynamique]
 *
 */

#include	<stdio.h>
#include	<stdlib.h>
#include	<termio.h>
#include	<malloc.h>
#include	<string.h>
#include	<fcntl.h>
#include	<time.h>
#include	<errno.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<sys/ipc.h>
#include	<sys/sem.h>
#include	<sys/shm.h>
#include	<signal.h>

#include	"bda.h"
#include	"utty.h"
#include 	"abal.h"

#include 	"xsignal.c"

/* Variables globales de la bibliotheque */

DVOIE tnlog[MAXNLOG];		/* table de description des connexions */
BDA desrt;			/* description de la bibliotheque */
WORD sig;			/* indicateur de signal recu */
WORD encours;			/* numero voie courante (pour un fils) */


/* Fonctions de traitement du signal SIGHUP */

static VOID (*TCatchsighup[MAXNLOG])() = {
	Catchsighup0,
	Catchsighup1,
	Catchsighup2,
	Catchsighup3,
	Catchsighup4,
	Catchsighup5,
	Catchsighup6,
	Catchsighup7,
	Catchsighup8,
	Catchsighup9,
};


/* Fonctions de traitement du signal SIGINT */

static VOID (*TCatchsigint[MAXNLOG])() = {
	Catchsigint0,
	Catchsigint1,
	Catchsigint2,
	Catchsigint3,
	Catchsigint4,
	Catchsigint5,
	Catchsigint6,
	Catchsigint7,
	Catchsigint8,
	Catchsigint9,
};

extern BDA_INIT FAR PTR rt_init;	/* signature de la bibliotheque */
extern BDA_ARG rt_arg;			/* description des arguments */


/* ------------------------------------------------------------------
 * ------------------------------------------------------------------
 * Fonctions externes 
 * ------------------------------------------------------------------
 * ------------------------------------------------------------------
 */

/* -----------------------------------------------------------------------
 *
 * Initialisation de la bibliotheque dynamique.
 *
 *	E/ rien
 *	S/ compte-rendu :
 *		ptr sur la structure de description de la bibliotheque
 *
 * -----------------------------------------------------------------------
 */
VOID FAR PTR InitRelais()
{ 
	WORD i;

	/* Mise en place de la signature de la bibliotheque */
	if (rt_init != (VOID FAR PTR) 0L)
		rt_init->ordinaire.signature = BDA_ORDINAIRE;


	/* Description des caracteristiques de la bibliotheque */
	desrt.banniere = (VOID (FAR PTR)()) banniere;
	desrt.fin = (VOID (FAR PTR)()) cloture;
	desrt.nombre = 9;

	/* Mise en place des relais de l'edition de liens dynamiques */
#ifdef vms					/***** VMS *****/
	desrt.nom[0] = (BYTE FAR PTR) "_ttyopen";
	desrt.nom[1] = (BYTE FAR PTR) "_ttyclose";
	desrt.nom[2] = (BYTE FAR PTR) "_ttyconnect";
	desrt.nom[3] = (BYTE FAR PTR) "_ttydcn";
	desrt.nom[4] = (BYTE FAR PTR) "_ttywrite";
	desrt.nom[5] = (BYTE FAR PTR) "_ttyread";
	desrt.nom[6] = (BYTE FAR PTR) "_ttybreak";
	desrt.nom[7] = (BYTE FAR PTR) "_ttyconfig";
	desrt.nom[8] = (BYTE FAR PTR) "_ttyselmode";
#else /* vms */
	desrt.reserve = (VOID FAR PTR) 0L;
#ifdef FCT_ENTETE				/***** UNIX *****/
	desrt.fonction[0] = (WORD (FAR PTR)()) _ttyopen;
	desrt.fonction[1] = (WORD (FAR PTR)()) _ttyclose;
	desrt.fonction[2] = (WORD (FAR PTR)()) _ttyconnect;
	desrt.fonction[3] = (WORD (FAR PTR)()) _ttydcn;
	desrt.fonction[4] = (WORD (FAR PTR)()) _ttywrite;
	desrt.fonction[5] = (WORD (FAR PTR)()) _ttyread;
	desrt.fonction[6] = (WORD (FAR PTR)()) _ttybreak;
	desrt.fonction[7] = (WORD (FAR PTR)()) _ttyconfig;
	desrt.fonction[8] = (WORD (FAR PTR)()) _ttyselmode;
#else  /* FCT_ENTETE */				/***** PROLOGUE et MS/DOS *****/
	desrt.fonction[0] = (WORD (FAR PTR)()) ttyopen;
	desrt.fonction[1] = (WORD (FAR PTR)()) ttyclose;
	desrt.fonction[2] = (WORD (FAR PTR)()) ttyconnect;
	desrt.fonction[3] = (WORD (FAR PTR)()) ttydcn;
	desrt.fonction[4] = (WORD (FAR PTR)()) ttywrite;
	desrt.fonction[5] = (WORD (FAR PTR)()) ttyread;
	desrt.fonction[6] = (WORD (FAR PTR)()) ttybreak;
	desrt.fonction[7] = (WORD (FAR PTR)()) ttyconfig;
	desrt.fonction[8] = (WORD (FAR PTR)()) ttyselmode;
#endif /* FCT_ENTETE */
#endif /* vms */

	/* Initialisations diverses */
	for (i=0 ; i<MAXNLOG ; i++) {
		tnlog[i].attach = FALSE;
		tnlog[i].reserve = FALSE;
		tnlog[i].connex = FALSE;
		tnlog[i].open = FALSE;
		tnlog[i].device = GN(BYTE);
		tnlog[i].journal = 0xffff;
		tnlog[i].anticipation = FALSE;
	}

	/* Controle de la protection anti-copie pirate :
	 * en cas de violation, on ne declare plus aucune fonction
	 * dans la bibliotheque dynamique. D'ou une erreur 139 systematique.
	 */
	if (VerifProtect() == FALSE)
		desrt.nombre = 0;

	/* Regarde si le mode debug est positionne. */
	ModeDebug = ((getenv("PTTYDEBUG") == GN(char)) ? FALSE : TRUE);

	//return((VOID FAR PTR) &desrt);
	return( (VOID FAR PTR) &desrt);
}

/* -----------------------------------------------------------------------
 *
 * Fonctions d'entete eventuelle (UNIX et VMS).
 *
 * -----------------------------------------------------------------------
 */
#ifdef FCT_ENTETE
WORD _ttyopen(a)
VOID PTR a[];
{
	return (ttyopen((WORD PTR)a[0], (BYTE PTR)a[1]));
}

WORD _ttyclose(a)
VOID PTR a[];
{
	return (ttyclose(GetParaWord(0)));
}

WORD _ttyconnect(a)
VOID PTR a[];
{
	return (ttyconnect(GetParaWord(0), (BYTE PTR)a[1] ));
}

WORD _ttydcn(a)
VOID PTR a[];
{
	return (ttydcn(GetParaWord(0)));
}

WORD _ttywrite(a)
VOID PTR a[];
{
	return (ttywrite(GetParaWord(0),GetParaByte(1), (BYTE PTR)a[2] ));
}

WORD _ttyread(a)
VOID PTR a[];
{
	return (ttyread(GetParaWord(0), (BYTE PTR)a[1] ));
}

WORD _ttybreak(a)
VOID PTR a[];
{
	return (ttybreak(GetParaWord(0)));
}

WORD _ttyconfig(a)
VOID PTR a[];
{
	return (ttyconfig(GetParaWord(0), GetParaWord(1) ));
}

WORD _ttyselmode(a)
VOID PTR a[];
{
	return (ttyselmode(GetParaWord(0),GetParaByte(1)));
}
#endif /* FCT_ENTETE */


/* -----------------------------------------------------------------------
 *
 * Fonction de reservation.
 *
 *	E/ ptr sur le nom du device
 *	   ptr sur le numero logique a attribuer
 *	S/ compte-rendu :
 *		 0 : OK
 *		27 : plus de place en memoire
 *		40 : device inexistant
 *		51 : table des numeros logiques saturee
 *		56 : fonction non supportee (access inactif)
 *		!8 : droits d'acces insuffisants
 *		84 : unite deja utilisee
 *		85 : nom de device incorrect
 *
 * La reservation procede en deux temps :
 *	- verification de l'existence du device
 *	- blocage en exclusif au niveau de access
 *
 * -----------------------------------------------------------------------
 */
static WORD FAR ttyopen(ComId,device)
WORD FAR PTR ComId;
BYTE FAR PTR device;
{ BYTE FAR PTR locdevice;
  WORD i,len;
  int handle,resac;
  struct stat buf;
  int mode;
  WORD locComId;

	/* Verifie la coherence du nom du device */

	len = rt_arg.l[1];
	if ((len < 2) || (len > MAXNOM-1))
		return(85);

	/* ------------------------------------------------- */
	/* Copy the device name and eliminate trailing space */
	/* ------------------------------------------------- */
	if ((locdevice = (BYTE FAR PTR) Xmalloc(len+1)) == GN(BYTE))
		return(27);

	Xmemcpy(locdevice,device,len);
	i = len;
	while (--i) {
		if (locdevice[i] != ' ')
			break;
		}
	if (i == 0) {
		Xfree(locdevice);
		return(85);
		}
	locdevice[++i] = EOSTR;

	/* -------------------------------------------------------------------- */
	/* To start with : if the user handle is no good : lookfor a better one */
	/* -------------------------------------------------------------------- */
	if ((i = GetAbalWord( ComId )) >= MAXNLOG ) 
		locComId = 0xFFFF;

	/* ----------------------------------------------------------------------- */
	/* Otherwise if its ok attached, not reserved connected and the right name */
	/*		USE IT 							   */
	/* ----------------------------------------------------------------------- */
	else if ((tnlog[i].attach  == TRUE) 
	     &&  (tnlog[i].reserve == FALSE) 
	     &&  (tnlog[i].connex  == TRUE) 
	     &&  (!Xstrcmp(locdevice,tnlog[i].device))) 
		    locComId = i;

	/* ------------------------------ */
	/* Otherwise if it's not attached */
	/*		USE IT 		  */	
	/* ------------------------------ */
	else if (tnlog[i].attach == FALSE) 
		locComId = i;

	/* --------------------------- */
	/* Otherwise find a better one */
	/* --------------------------- */
	else	locComId = 0xFFFF;


	/* --------------------------- */
	/* Should we find a better one */
	/* --------------------------- */
	if ( locComId == 0xffff ) {
		for (i=0 ; i<MAXNLOG ; i++) {
			if ((tnlog[i].attach == TRUE) &&
			    (tnlog[i].reserve == FALSE) &&
			    (tnlog[i].connex == TRUE) &&
			    (!Xstrcmp(locdevice,tnlog[i].device))) {
				    locComId = i;
				    break;
				}
			}
		}

	/* ---------------------------------------------- */
	/* Should we try again to find an even better one */
	/* ---------------------------------------------- */
	if (locComId == 0xffff) {
		for (i=0 ; i<MAXNLOG ; i++) {
			if (tnlog[i].attach == FALSE) {
				locComId = i;
				break;
				}
			}
		if (i > MAXNLOG) {
			Xfree(locdevice);
			return(51);
			}
		}


	/* ---------------------------------------------------------- */
	/* I suppose if we got here we have a resonable handle to use */
	/* So lets try and lock it now : not later 		      */
	/* ---------------------------------------------------------- */
	if ((resac = Access(locdevice,0,1)) != 0) {

		if (ModeDebug) { perror("Access device"); }

		Xfree(locdevice);

		/* Access non actif */
		if ((errno == 666) || (errno == 667)) {
			return(56);
			}

		/* Device deja reserve */
		return(84);
		}

	/* ---------------------------------------------------------------------------  */
	/* 	Open the Device Driver Correction Giminiez : POSIX 			*/
	/* ---------------------------------------------------------------------------  */
	/* The extra options require that the tty not be associated with this terminal  */
	/* correction of the problem concerning the interaction with PPP		*/
	/* ---------------------------------------------------------------------------  */
	if ((handle = Xopen(locdevice,(O_RDWR | O_NOCTTY | O_NDELAY))) == -1) {
		liberlox(locdevice);
		Xfree(locdevice);
		switch (errno) {
			/* Droits d'acces insuffisants */
			case EACCES : return(58);

			/* Non existence du device */
			case ENOENT : return(40);

			/* Autres */
			default : return(85);
			}
		}
	else	{
		/* ------------------------------------------------------- */
		/* The O_NDELAY has made the handle non-blocking : rectify */
		/* ------------------------------------------------------- */
		fcntl(handle, F_SETFL, 0 );
		}

	/* -------------------------------------------- */
	/* Ensure that the device is a character device */
	/* -------------------------------------------- */
	if (fstat(handle,&buf) == -1) {
		Xclose(handle);
		liberlox(locdevice);
		Xfree(locdevice);
		return(56);
		}
	else if ((mode = (buf.st_mode & S_IFMT)) != S_IFCHR) {
		Xclose(handle);
		liberlox(locdevice);
		Xfree(locdevice);
		return(85);
		}

	/* ---------------------------------------------- */
	/* All information can now be stored to the table */
	/* ---------------------------------------------- */
	if (tnlog[locComId].attach == FALSE)
		tnlog[locComId].connex = FALSE;

	tnlog[locComId].attach = TRUE;
	tnlog[locComId].reserve = TRUE;
	tnlog[locComId].handle = handle;
	tnlog[locComId].device = locdevice;
	tnlog[locComId].open = TRUE;
	tnlog[locComId].journal = 0xffff;

	/* ------------------------------- */
	/* Store the Handle for the Caller */
	/* ------------------------------- */
	PutAbalWord( ComId, locComId );

	return(0);
}


/* -----------------------------------------------------------------------
 *
 * Fonction de liberation.
 *
 *	E/ numero logique
 *	S/ compte-rendu :
 *		 0 : OK
 *		42 : fichier ferme
 *		50 : numero logique incorrect
 *
 * La liberation ne provoque pas de deconnexion.
 * Si la voie est deja deconnectee, il y a liberation du numero logique.
 * Sinon, le numero logique n'est pas libere. Seule la reservation est
 * annulee.
 *
 * -----------------------------------------------------------------------
 */
static WORD FAR ttyclose(ComId)
WORD ComId;
{
	/* Verifie que le numero logique est possible */
	if (ComId > MAXNLOG)
		return(50);

	/* Controle la validite du numero logique */
	if (tnlog[ComId].attach == FALSE)
		return(50);

	/* Enregistre la requete dans le journal */
	//OLD TRACE	mess_time(ComId,"TTYCLOSE");

	/* Controle l'etat de la voie */
	if (tnlog[ComId].reserve == FALSE)
		return(42);

	/* Leve le verrou exclusif sur le device */
	liberlox(tnlog[ComId].device);

	/* Indique que le device n'est plus reserve */
	tnlog[ComId].reserve = FALSE;

	/* Libere eventuellement le numero logique si la
	 * voie a ete prealablement deconnectee.
	 */
	if (tnlog[ComId].connex == FALSE) {
//OLD TRACE		mess(ComId," + libere no logique");
		Xfree(tnlog[ComId].device);
		tnlog[ComId].device = GN(BYTE);
		tnlog[ComId].attach = FALSE;

		/* Fermeture du fichier journal */
		if (tnlog[ComId].journal != 0xffff) {
			Xclose(tnlog[ComId].journal);
			tnlog[ComId].journal = 0xffff;
		}
	}

	return(0);
}

/* -----------------------------------------------------------------------
 *
 * Fonction de connexion.
 *
 *	E/ numero logique
 *	   buffer contenant les parametres de connexion
 *	S/ compte-rendu :
 *		 0 : OK
 *		42 : voie non reservee
 *		50 : numero logique incorrect
 *		84 : voie deja connectee
 *		85 : descripteur incorrect
 *		86 : voie non initialisable
 *
 * -----------------------------------------------------------------------
 */
static WORD FAR ttyconnect(ComId,tampon)
WORD ComId;
BYTE FAR PTR tampon;
{ BYTE vitesse;
  BYTE format;
  BYTE finenr;
  BYTE finfich;
  WORD timeout;
  BYTE transp;
  BYTE liaison;
  WORD cpdu;
  WORD len;
  int handle;

	/* Verifie que le numero logique est possible */
	if (ComId > MAXNLOG)
		return(50);

	/* Controle la validite du numero logique */
	if (tnlog[ComId].attach == FALSE)
		return(50);

	/* Enregistre la requete dans le journal */
//OLD TRACE	mess_time(ComId,"TTYCONNECT");

	/* Controle l'etat de la voie */
	if (tnlog[ComId].reserve == FALSE)
		return(42);

	/* Controle de la deconnexion */
	if (tnlog[ComId].connex == TRUE)
		return(84);

	/* Recuperation des parametres de connexion */
	if (rt_arg.c > 1) {
		/* Un tampon de parametres existe */
		len = rt_arg.l[1];
		if (len < 6)
			return(85);

		vitesse = *(tampon);
		format = *(tampon+1);
		finenr = *(tampon+2);
		finfich = *(tampon+3);
		timeout = GetAbalWord((tampon+4));

		/* Traite les parametres optionnels */
		if (len > 6) {
			transp = *(tampon+6);
			if (len > 7) {
				liaison = *(tampon+7);
				}
			else 	{
				liaison = 0;
				}
			}
		else 	{
			transp = 0;
			liaison = 0;
			}
	}
	else {
		len = 0;

		/* Absence de tampon -> parametrage par defaut :
		 *	2400 bauds
		 *	8 bits, sans parite, 1 stop
		 *	Fin d'enregistrement : 0D
		 *	Fin de fichier : 1A
		 *	Time-out de 2 sec
		 *	Semi-duplex
		 */
		vitesse = 10;
		format = 0x004c;
		finenr = 0x000d;
		finfich = 0x001a;
		timeout = 200;
		transp = 0;
		liaison = 0;
	}


	/* Controle et initialisation de la vitesse de transmission */
	switch(vitesse) {
		case 0 : tnlog[ComId].vitesse = B50;
			 break;
		case 1 : tnlog[ComId].vitesse = B75;
			 break;
		case 2 : tnlog[ComId].vitesse = B110;
			 break;
		case 3 : tnlog[ComId].vitesse = B134;
			 break;
		case 4 : tnlog[ComId].vitesse = B150;
			 break;
		case 5 : tnlog[ComId].vitesse = B300;
			 break;
		case 6 : tnlog[ComId].vitesse = B600;
			 break;
		case 7 : tnlog[ComId].vitesse = B1200;
			 break;
		case 8 : tnlog[ComId].vitesse = B1800;
			 break;
		case 10 : tnlog[ComId].vitesse = B2400;
			  break;
		case 12 : tnlog[ComId].vitesse = B4800;
			  break;
		case 14 : tnlog[ComId].vitesse = B9600;
			  break;
		case 15 : tnlog[ComId].vitesse = B19200;
			  break;
		case 16 : tnlog[ComId].vitesse = B38400;
			  break;
		case 17 : tnlog[ComId].vitesse = B57600;
			  break;

		/* Autres valeurs et 2000, 3600 et 7200 bauds non supportes */
		default : return(85);
	}

	/* Controle et initialisation format caractere */
	switch ((format >> 2) & 0x03) {
		case 0 : tnlog[ComId].nbits = CS5;
			 break;
		case 1 : tnlog[ComId].nbits = CS6;
			 break;
		case 2 : tnlog[ComId].nbits = CS7;
			 break;
		case 3 : tnlog[ComId].nbits = CS8;
			 break;
	}
	tnlog[ComId].oparite = (format & 0x10) ? PARENB : 0;
	tnlog[ComId].iparite = (format & 0x10) ? (INPCK) : 0;
	tnlog[ComId].typeparite = (format & 0x20) ? 0 : PARODD;

	switch ((format >> 6) & 0x03) {
		case 1 : tnlog[ComId].nstops = 0;
			 break;
		case 3 : tnlog[ComId].nstops = CSTOPB;
			 break;

		/* Autres valeurs et 1,5 bits non supportes */
		default : return(85);
	}

	/* Initialisation autres champs : why bother its all approximate anyway ! (sic) */
	tnlog[ComId].finenr = finenr;
	tnlog[ComId].finfich = finfich;
	tnlog[ComId].timeout = timeout/10;
	tnlog[ComId].transp = (transp == 1) ? TRUE : FALSE;
	/* this is great too : in fact we never use the flag duplex */
	tnlog[ComId].duplex = ((liaison & 1) == 1) ? TRUE : FALSE;
#ifdef	CLAUDE_ROBLEZ
	/* original stupid expression */
	/* tnlog[ComId].modem = ((liaison & 2) == 2) ? (CTSFLOW | RTSFLOW) : (CLOCAL | CTSFLOW | RTSFLOW); */
#else
	/* -------------------------------------------------------------------------------------------- */
	/* This is the bit that is UNIX specific : other systems are the opposite : thanks a lot claude */
	/* The definitions are correct, defined in the file modem.h (11/09/2003 : IJM et JS)		*/
	/* -------------------------------------------------------------------------------------------- */
	tnlog[ComId].modem = ((liaison & 2) == 2) ? (HARDWARE) : (RIEN);
#endif

	/* Reouverture eventuelle du device */
	if (tnlog[ComId].open == FALSE) {
		handle = Xopen(tnlog[ComId].device,O_RDWR);
		if (handle == -1)
			return(86);

		tnlog[ComId].handle = handle;
		tnlog[ComId].open = TRUE;
		}

	/* Initialisation de la voie serie */
	cpdu = initvoie(&tnlog[ComId]);
	if (cpdu != 0)
		return(cpdu);

	tnlog[ComId].connex = TRUE;

	/* Interception du signal SIGHUP, provoque par une erreur
	 * modem.
	 */
	tnlog[ComId].sigmodem = FALSE;
	signal(SIGHUP,TCatchsighup[ComId]);

	/* Interception du signal SIGINT, provoque par un break */
	tnlog[ComId].sigint = FALSE;
	signal(SIGINT,TCatchsigint[ComId]);

	/* Creation du process d'alimentation du tampon d'anticipation */
	if (tnlog[ComId].anticipation == TRUE) {
		cpdu = Pcreat(ComId);
		if (cpdu != 0)
			return(cpdu);
		}

	return(0);
}

/* -----------------------------------------------------------------------
 *
 * Fonction de deconnexion.
 *
 *	E/ numero logique
 *	S/ compte-rendu :
 *		 0 : OK
 *		42 : voie non reservee
 *		50 : numero logique incorrect
 *		83 : voie non connectee
 *
 * -----------------------------------------------------------------------
 */
static WORD FAR ttydcn(ComId)
WORD ComId;
{ WORD cpdu;

	/* Verifie que le numero logique est possible */
	if (ComId > MAXNLOG)
		return(50);

	/* Controle la validite du numero logique */
	if (tnlog[ComId].attach == FALSE)
		return(50);

	/* Enregistre la requete dans le journal */
//OLD TRACE	mess_time(ComId,"TTYDCN");

	/* Controle l'etat de la voie */
	if (tnlog[ComId].reserve == FALSE)
		return(42);

	/* Controle de la deconnexion */
	if (tnlog[ComId].connex == FALSE)
		return(83);

	/* Provoque la suppression eventuelle du processus d'alimentation
	 * du tampon d'anticipation.
	 */
	if (tnlog[ComId].anticipation == TRUE) {
		cpdu = Pdelete(ComId);
		if (cpdu != 0)
			return(cpdu);
		}

	/* Deconnecte physiquement la ligne */
	tnlog[ComId].vitesse = B0;
	cpdu = initvoie(&tnlog[ComId]);

	/* Ferme le device associe a la voie */
	(void) Xclose(tnlog[ComId].handle);
	tnlog[ComId].open = FALSE;

	/* Indique voie deconnectee */
	tnlog[ComId].connex = FALSE;

	return(0);
}

/* -----------------------------------------------------------------------
 *
 * Fonction d'emission de donnees.
 *
 *	E/ numero logique
 *	   indicateur d'echo
 *	   tampon
 *	S/ compte-rendu :
 *		 0 : OK
 *		42 : voie non reservee
 *		50 : numero logique incorrect
 *		83 : voie non connectee
 *		85 : parametre incorrect
 *		87 : echo incorrect en emission
 *		88 : erreur modem
 *		89 : detection d'un break
 *		91 : time-out expire
 *		99 : erreur d'emission (parite)
 *
 * -----------------------------------------------------------------------
 */
static WORD FAR ttywrite(ComId,echo,tampon)
WORD ComId;
BYTE echo;
BYTE FAR PTR tampon;
{ WORD len;
  BYTE buf[128];
  BYTE car,carlu;
  WORD i;
  WORD cpdu;

	/* Verifie que le numero logique est possible */
	if (ComId > MAXNLOG)
		return(50);

	/* Controle la validite du numero logique */
	if (tnlog[ComId].attach == FALSE)
		return(50);

	/* Enregistre la requete dans le journal */
//OLD TRACE	mess_time(ComId,"TTYWRITE");

	/* Controle l'etat de la voie */
	if (tnlog[ComId].reserve == FALSE)
		return(42);

	/* Controle de la connexion */
	if (tnlog[ComId].connex == FALSE)
		return(83);

	/* Recupere la longueur du tampon a emettre */
	len = rt_arg.l[2];
	if (rt_arg.c > 3) {
		WORD ltampon;

		/* Selon le type, recupere la valeur du parametre longueur */
		switch(rt_arg.t[3]) {
			/* parametre numerique 2 octets */
			case TYPE_POURCENT :
				ltampon = GetAbalWord((rt_arg.v[3]));
				break;

			/* parametre numerique 1 octet */
			case TYPE_DIESE :
				ltampon = GetAbalByte((rt_arg.v[3]));
				break;

			/* parametre numerique BCD */
			case TYPE_BCD :
				ltampon = bcd2word(rt_arg.v[3],rt_arg.l[3]);
				break;

			/* Autre cas : parametre incorrect */
			default : return(85);
		}

		/* Controle de la longueur */
		if (len < ltampon)
			return(85);
		len = ltampon;
	}


	/* Enregistre la longueur dans le journal */
//OLD TRACE	(void) sprintf(&buf[0]," Lgr:%0.5d",len);
//OLD TRACE	mess(ComId,&buf[0]);

	/* Effectue l'ecriture proprement dite */
	if (echo == 0) {
		/* Sans echo */
		if (Xwrite(tnlog[ComId].handle,tampon,len) != len) {
			/* Est-ce une erreur modem ? */
			if (tnlog[ComId].sigmodem == TRUE)
				return(88);

			/* Est-ce du a un break ? */
			if (tnlog[ComId].sigint == TRUE)
				return(89);

			/* Autres erreurs : A COMPLETER */
			return(99);
			}
		}
	else 	{
		/* Avec echo */
		for (i=0 ; i<len ; i++) {

			car = *(tampon+i);

			/* Emet un caractere */
			if (Xwrite(tnlog[ComId].handle,&car,1) != 1) {
				/* Est-ce une erreur modem ? */
				if (tnlog[ComId].sigmodem == TRUE)
					return(88);

				/* Est-ce du a un break ? */
				if (tnlog[ComId].sigint == TRUE)
					return(89);

				/* Autres erreurs : A COMPLETER */
				return(99);
				}

			/* Attend son echo en retour */
			cpdu = Aread(ComId,&carlu);
			if (cpdu != 0)
				return(cpdu);

			/* Compare le caractere emis et le caractere recu */
			if (car != carlu)
				return(87);
			}
		}

	return(0);
}

/* -----------------------------------------------------------------------
 *
 * Fonction de reception de donnees.
 *
 *	E/ numero logique
 *	   tampon
 *	S/ compte-rendu :
 *		 0 : OK
 *		42 : voie non reservee
 *		50 : numero logique incorrect
 *		63 : tampon de reception sature
 *		83 : voie non connectee
 *		85 : descripteur incorrect
 *		88 : erreur modem
 *		89 : detection d'un break
 *		90 : overrun en reception
 *		91 : time-out
 *		93 : fin de fichier
 *
 * -----------------------------------------------------------------------
 */
static WORD FAR ttyread(ComId,tampon)
WORD ComId;
BYTE FAR PTR tampon;
{ WORD len,i;
  BOOL end;
  WORD err;
  BYTE car;
  BYTE buf[128];
  WORD cpdu;

	/* Verifie que le numero logique est possible */
	if (ComId > MAXNLOG)
		return(50);

	/* Controle la validite du numero logique */
	if (tnlog[ComId].attach == FALSE)
		return(50);

	/* Enregistre la requete dans le journal */
//OLD TRACE	mess_time(ComId,"TTYREAD");

	/* Controle l'etat de la voie */
	if (tnlog[ComId].reserve == FALSE)
		return(42);

	/* Controle de la connexion */
	if (tnlog[ComId].connex == FALSE)
		return(83);

	/* Controle de la longueur du tampon a recevoir */
	len = rt_arg.l[1];
	if (rt_arg.c > 2) {
		WORD ltampon;
		/* Selon le type, recupere la valeur du parametre longueur */
		switch(rt_arg.t[2]) { 
			/* parametre numerique 2 octets */
			case TYPE_POURCENT :
				ltampon = GetAbalWord((rt_arg.v[2]));
				break;

			/* parametre numerique 1 octet */
			case TYPE_DIESE :
				ltampon = GetAbalByte((rt_arg.v[2]));
				break;

			/* parametre numerique BCD */
			case TYPE_BCD :
				ltampon = bcd2word(rt_arg.v[2],rt_arg.l[2]);
				break;

			/* Autre cas : parametre incorrect */
			default : return(85);
			}

		/* Controle du parametre longueur */
		if (len < ltampon)
			return(85);
		len = ltampon;
		}

	if (len < 2) {
		return(85);
		}

	/* Enregistre la longueur maximale dans le journal */
	//OLD TRACE	(void) sprintf(&buf[0]," Max:%0.5d",len-2);
	//OLD TRACE	mess(ComId,&buf[0]);

	/* Mise a blanc du tampon de reception */
	for (i = 2 ; i < len ; i++) {
		*(tampon+i) = ' ';
		}

	/* Boucle de lecture caractere a caractere jusqu'a
	 * l'un des evenements suivants :
	 *	- reception d'une fin d'enregistrement
	 *	- reception d'une fin de fichier
	 *	- saturation du tampon de reception
	 *	- detection d'une erreur
	 */
	end = FALSE;
	err = 0;
	i = 2;

	while (!end) {
		cpdu = Aread(ComId,&car);
		/* Diagnostic de l'erreur */
		if (cpdu != 0) {
			if (err == 90) {
				/* Des caracteres ont deja ete perdus :
				 * tant qu'il en reste dans le tampon
				 * d'anticipation, on les retourne a l'appli.
				 */
				if (cpdu != 90) {
					end = TRUE;
					break;
					}
				}
			else 	{
				err = cpdu;
				/* S'il ne s'agit pas d'une erreur de perte de
				 * caracteres, on retourne immediatement le
				 * compte-rendu d'erreur a l'appli.
				 */
				if (err != 90) {
					end = TRUE;
					break;
					}
				}
			}

		/* Post-traitement des caracteres */
		if (tnlog[ComId].transp == FALSE) {
			/* Caractere fin d'enregistrement */
			if (car == tnlog[ComId].finenr) {
				end = TRUE;
				break;
				}
			/* Caractere fin de fichier */
			else if (car == tnlog[ComId].finfich) {
				*(tampon+i) = car;
				err = 93;
				end = TRUE;
				i++;
				break;
				}
			/* Caractere normal */
			else 	{
				*(tampon+i) = car;
				i++;
				if (i >= len) {
					/* Tampon sature */
					err = 63;
					end = TRUE;
					break;
					}
				}
			}

		/* Pas de post-traitement des caracteres */
		else 	{
			*(tampon+i) = car;
			i++;
			if (i >= len) {
				/* Tampon sature : pas de remontee
				 * d'erreur si pas de post-traitement
				 */
				end = TRUE;
				break;
				}
			}
	}

	/* Pose la longueur recue dans l'en-tete du tampon */

	len = i-2;

	PutAbalWord(tampon,len);

	/* Enregistre la longueur lue dans le journal */
//OLD TRACE	(void) sprintf(&buf[0]," Lu:%0.5d",len);
//OLD TRACE	mess(ComId,&buf[0]);

	return(err);
}

/* -----------------------------------------------------------------------
 *
 * Fonction d'envoi d'un break
 *
 *	E/ numero logique
 *	S/ compte-rendu :
 *		 0 : OK
 *		42 : voie non reservee
 *		50 : numero logique incorrect
 *		83 : voie non connectee
 *
 * -----------------------------------------------------------------------
 */
static WORD FAR ttybreak(ComId)
WORD ComId;
{
	/* Verifie que le numero logique est possible */
	if (ComId > MAXNLOG)
		return(50);

	/* Controle la validite du numero logique */
	if (tnlog[ComId].attach == FALSE)
		return(50);

	/* Enregistre la requete dans le journal */
//OLD TRACE	mess_time(ComId,"TTYBREAK");

	/* Controle l'etat de la voie */
	if (tnlog[ComId].reserve == FALSE)
		return(42);

	/* Controle de la connexion */
	if (tnlog[ComId].connex == FALSE)
		return(83);

	/* Envoi d'un break sur la ligne pendant une
	 * duree comprise en 0.25 et 0.5 sec
	 */
/*	(void) tcsendbreak(tnlog[ComId].handle,0); */
	(void) ioctl(tnlog[ComId].handle,TCSBRK,0);

	return(0);
}

/* -----------------------------------------------------------------------
 *
 * Fonction de configuration du tampon d'anticipation.
 *
 *	E/ numero logique de la voie
 *	   taille du tampon d'anticipation (0 si pas de tampon)
 *	S/ compte-rendu :
 *		 0 : OK
 *		42 : fichier ferme
 *		50 : numero logique incorrect
 *		84 : voie deja connectee
 *		85 : longueur tampon incorrecte
 *
 * -----------------------------------------------------------------------
 */
static WORD FAR ttyconfig(ComId,ltampon)
WORD ComId;
WORD ltampon;
{ BYTE buf[128];

	/* Verifie que le numero logique est possible */
	if (ComId > MAXNLOG)
		return(50);

	/* Controle la validite du numero logique */
	if (tnlog[ComId].attach == FALSE)
		return(50);

	/* Controle l'etat de la voie */
	if (tnlog[ComId].reserve == FALSE)
		return(42);

	/* Controle de la deconnexion */
	if (tnlog[ComId].connex == TRUE)
		return(84);

	/* Enregistre la requete dans le journal */
//OLD TRACE	mess_time(ComId,"TTYCONFIG");

	/* et la longueur demandee du tampon */
//OLD TRACE	(void) sprintf(&buf[0]," Lgr:%0.5d",ltampon);
//OLD TRACE	mess(ComId,&buf[0]);

	/* Y-a-t-il besoin d'un tampon d'anticipation ? */
	if (ltampon == 0) {
		/* Pas de tampon d'anticipation */
		tnlog[ComId].anticipation = FALSE;
	}
	else {
		/* Controle de la longueur demandee du tampon */
		if ((ltampon > MAXTAMPON) || (ltampon < 256))
			return(85);

		/* Conservation de la longueur du tampon */
		tnlog[ComId].anticipation = TRUE;
		tnlog[ComId].ltampon = ltampon;
	}

	return(0);
}

/* -----------------------------------------------------------------------
 *
 * Fonction de configuration du mode debug.
 *
 *	E/ numero logique
 *	   indicateur de selection
 *		0 : passage en mode normal
 *		1 : passage en mode debug
 *	S/ compte-rendu :
 *		 0 : OK
 *		40 : acces fichier impossible
 *		42 : voie non reservee
 *		50 : numero logique incorrect
 *
 *	Lorsque 'indicateur' vaut 1, la fonction provoque la creation
 *	d'un fichier journal des actions effectuees et compte-rendus.
 *	Lorsque 'indicateur' vaut 0, la fonction provoque la fermeture
 *	eventuelle du fichier journal.
 *	La voie doit etre reservee avant l'appel a la fonction.
 *
 * -----------------------------------------------------------------------
 */
static WORD FAR ttyselmode(ComId,indicateur)
WORD ComId;
BYTE indicateur;
{
/*OLD TRACE
  int handle;
  BYTE nomjournal[64];

	// Verifie que le numero logique est possible 
	if (ComId > MAXNLOG)
		return(50);

	// Controle la validite du numero logique 
	if (tnlog[ComId].attach == FALSE)
		return(50);

	// Controle l'etat de la voie 
	if (tnlog[ComId].reserve == FALSE)
		return(42);

	if (indicateur = 0) {
		// Passage en mode normal 
		if (tnlog[ComId].journal != 0xffff) {
			// Enregistrement demande de fermeture 
			mess_time(ComId,"TTYSELMODE(0)");
			// Fermeture du fichier journal 
			Xclose(tnlog[ComId].journal);
			tnlog[ComId].journal = 0xffff;
		}
	}
	else {
		// Passage en mode debug 
		if (tnlog[ComId].journal != 0xffff) {
			// Enregistrement demande de passage en mode debug 
			mess_time(ComId,"TTYSELMODE(1)");
		}
		else {
			// Creation du fichier journal 
			(void) sprintf(&nomjournal[0],"/tmp/journal.%0.4X",ComId);
			handle = Xcreat(&nomjournal[0],0666);
			if (handle == -1) {
				return(40);
			}

			// Enregistrement de la creation du journal 
			tnlog[ComId].journal = handle;
			mess_time(ComId,"TTYSELMODE(1)");
		}
	}
*/
	return(0);
}



/* ------------------------------------------------------------------
 * ------------------------------------------------------------------
 * Fonctions internes 
 * ------------------------------------------------------------------
 * ------------------------------------------------------------------
 */




/* -----------------------------------------------------------------------
 *
 * Fonctions d'interception du signal "hang-up".
 *
 * Il existe une fonction par voie possible
 *
 *	E/ rien
 *	S/ rien
 *
 * -----------------------------------------------------------------------
 */
static VOID Catchsighup0()
{ Catchsighup(0); }

static VOID Catchsighup1()
{ Catchsighup(1); }

static VOID Catchsighup2()
{ Catchsighup(2); }

static VOID Catchsighup3()
{ Catchsighup(3); }

static VOID Catchsighup4()
{ Catchsighup(4); }

static VOID Catchsighup5()
{ Catchsighup(5); }

static VOID Catchsighup6()
{ Catchsighup(6); }

static VOID Catchsighup7()
{ Catchsighup(7); }

static VOID Catchsighup8()
{ Catchsighup(8); }

static VOID Catchsighup9()
{ Catchsighup(9); }

/* -----------------------------------------------------------------------
 *
 * Interception du signal "hang-up".
 *
 * Ce signal est genere lors de la detection d'une deconnexion d'une
 * liaison etablie au travers d'un modem.
 *
 *	E/ numero logique de la voie
 *	S/ rien
 *
 * -----------------------------------------------------------------------
 */
static VOID Catchsighup(ComId)
WORD ComId;
{
	/* Indique que le signal est arrive */
	tnlog[ComId].sigmodem = TRUE;
	signal(SIGHUP,TCatchsighup[ComId]);
}

/* -----------------------------------------------------------------------
 *
 * Fonctions d'interception du signal SIGINT.
 *
 * Il existe une fonction par voie possible
 *
 *	E/ rien
 *	S/ rien
 *
 * -----------------------------------------------------------------------
 */
static VOID Catchsigint0()
{ Catchsigint(0); }

static VOID Catchsigint1()
{ Catchsigint(1); }

static VOID Catchsigint2()
{ Catchsigint(2); }

static VOID Catchsigint3()
{ Catchsigint(3); }

static VOID Catchsigint4()
{ Catchsigint(4); }

static VOID Catchsigint5()
{ Catchsigint(5); }

static VOID Catchsigint6()
{ Catchsigint(6); }

static VOID Catchsigint7()
{ Catchsigint(7); }

static VOID Catchsigint8()
{ Catchsigint(8); }

static VOID Catchsigint9()
{ Catchsigint(9); }

/* -----------------------------------------------------------------------
 *
 * Interception du signal SIGINT.
 *
 * Ce signal est genere lors de la detection d'un break.
 *
 *	E/ numero logique de la voie
 *	S/ rien
 *
 * -----------------------------------------------------------------------
 */
static VOID Catchsigint(ComId)
WORD ComId;
{
	/* Indique que le signal est arrive */
	tnlog[ComId].sigint = TRUE;
	signal(SIGINT,TCatchsigint[ComId]);
}

/* -----------------------------------------------------------------------
 *
 * Initialisation de la voie serie.
 *
 *	E/ ptr sur la structure decrivant la voie serie
 *	S/ compte-rendu :
 *		 0 : OK
 *		86 : voie non initialisable
 *
 * On commence par recuperer l'etat actuel de la voie serie et
 * on change les parametres qui nous interesse.
 *
 * -----------------------------------------------------------------------
 */
static WORD initvoie(voie)
DVOIE PTR voie;
{
#ifdef CXOPEN
	struct termios param;
#else
	struct termio param;
#endif

	/* Recupere les parametres actuels */
#ifdef CXOPEN
	if (tcgetattr(voie->handle,&param) != 0)
#else
	if (ioctl(voie->handle,TCGETA,&param) == -1)
#endif
		return(86);

	/* Mise a jour input modes */
	param.c_iflag = param.c_iflag
		& ~BRKINT	/* pas d'interruption sur break */
		& ~ICRNL	/* pas de transformation CR en NL */
		& ~IGNBRK	/* ne pas ignorer le break */
		& ~IGNCR	/* ne pas ignorer CR */
		& ~IGNPAR	/* ne pas ignorer les caracteres avec
				 * erreur de parite */
		& ~INLCR	/* pas de transformation NL en CR */
		| INPCK		/* controle de la parite en entree */
		& ~ISTRIP	/* pas de strip des caracteres */
		& ~IXOFF	/* pas de XON/XOFF en entree */
		& ~IXON		/* pas de XON/XOFF en sortie */
		& ~IXANY
		| PARMRK	/* coder FF 00 xx les erreurs de parite */
		| voie->iparite
		& ~IUCLC	/* pas de tranformation en minuscules */
		;

	/* Mise a jour output modes */
	param.c_oflag = param.c_oflag & ~OPOST;	/* pas de traitement
						 * en sortie */

	/* Mise a jour control modes */
	param.c_cflag =
		voie->vitesse		/* vitesse de transmission */
		& ~CSIZE
		| voie->nbits		/* nombre de bits */
		& ~CSTOPB
		| voie->nstops		/* nombre de stops */
		| CREAD			/* autorise la reception */
		& ~PARENB
		| voie->oparite		/* presence d'un controle de parite */
		& ~PARODD
		| voie->typeparite      /* type de parite */
		| HUPCL			/* force deconnexion sur fermeture */
		& ~CLOCAL
		| voie->modem;		/* gestion des signaux modem */

	/* Mise a jour local modes */
	param.c_lflag = param.c_lflag
		& ~ECHO		/* pas d'echo */
		& ~ECHOE	/* pas d'echo du caractere d'effacement */
		& ~ECHOK	/* pas d'echo de kill */
		& ~ECHONL	/* pas d'echo de NL */
		& ~ICANON	/* entree en mode direct */
		& ~IEXTEN	/* pas de traitement en entree */
		& ~ISIG		/* pas de signal */
		& ~NOFLSH	/* vider apres kill ou interruption */
		& ~TOSTOP;	/* ignorer les backgrounds */

	/* Mise a jour de la table des caracteres speciaux */
	param.c_cc[VINTR] = 0xff;		/* inutilise */
	param.c_cc[VMIN] = 0;			/* caractere a caractere */
	param.c_cc[VEOF] = 0;			/* idem */
	param.c_cc[VQUIT] = 0xff;		/* inutilise */
	param.c_cc[VTIME] = 1;			/* time-out de reception minimal */
#ifdef CXOPEN
	param.c_cc[VSUSP] = 0xff;		/* inutilise */
	param.c_cc[VSTART] = 0xff;		/* inutilise */
	param.c_cc[VSTOP] = 0xff;		/* inutilise */
#endif

	/* Modifie les parametres de la voie serie */
#ifdef CXOPEN
	if (tcsetattr(voie->handle,TCSADRAIN,&param) != 0)
#else
	if (ioctl(voie->handle,TCSETAW,&param) == -1)
#endif
		return(86);

	return(0);
}

/* -----------------------------------------------------------------------
 *
 * Creation du processus d'alimentation d'un tampon d'anticipation.
 *
 *	E/ numero logique
 *	S/ compte-rendu :
 *		 0 : OK
 *		58 : droits insuffisants
 *
 * -----------------------------------------------------------------------
 */
static WORD Pcreat(ComId)
WORD ComId;
{ WORD i;
  int shmid,semid;
  char PTR shm;
  int child,father;
  WORD semval[1];
#ifdef CXOPEN
  sigset_t set;
#endif

	/* Interception du signal utilisateur 2 qui servira a synchroniser
	 * les processus pere et fils,
	 * et le signal utilisateur 1 qui servira a signaler les problemes
	 * d'initialisation du fils.
	 */
	sig = 0;
	signal(SIGUSR2,fathersigusr2);

#ifdef CXOPEN
	sigfillset(&set);
	sigdelset(&set,SIGUSR1);
	sigdelset(&set,SIGUSR2);
#endif

	/* Creation du processus fils.
	 * La repartition des taches entre processus pere et fils est :
	 *	- le pere (bibliotheque utty) est connecte a l'applicatif
	 *	- le fils alimente le tampon d'anticipation
	 */
	child = fork();
	if (child == -1)
		return(58);

	if (child == 0) {
		/******************/
		/* Processus fils */
		/******************/

		/* Interception du signal utilisateur 1 qui sert au pere
		 * pour provoquer la mort du fils.
		 */
		encours = ComId;
		signal(SIGUSR1,childsigusr1);

		/* Recuperation des numeros de processus respectifs */
		child = getpid();
		father = getppid();
		tnlog[ComId].child = child;
		tnlog[ComId].father = father;

		/* Creation d'un segment de memoire partagee qui contiendra
		 * le tampon d'anticipation.
		 */
		shmid = shmget(child,tnlog[ComId].ltampon+256,0777 | IPC_CREAT);
		if (shmid == -1) {
			kill(father,SIGUSR1);
			exit(1);
		}

		/* Attachement du segment de memoire partagee */
		shm = (char PTR)shmat(shmid,(VOID PTR)0L,0);
		if (shm == (char PTR)-1L) {
			shmctl(shmid,IPC_RMID,GN(struct shmid_ds));
			kill(father,SIGUSR1);
			exit(1);
		}

		/* Creation du set de semaphores de synchronisation */
		semid = semget(child,1,0777 | IPC_CREAT);
		if (semid == -1) {
			shmctl(shmid,IPC_RMID,GN(struct shmid_ds));
			kill(father,SIGUSR1);
			exit(1);
		}

		/* Initialisation du set de semaphores */
		semval[0] = 1;
		if ((semctl(semid,1,SETALL,&semval[0]) == -1)) {
			semctl(semid,1,IPC_RMID,0);
			shmctl(shmid,IPC_RMID,GN(struct shmid_ds));
			kill(father,SIGUSR1);
			exit(1);
		}

		/* Validation des informations */
		tnlog[ComId].shmid = shmid;
		tnlog[ComId].shm = (struct SHM PTR)shm;
		tnlog[ComId].semid = semid;

		/* Initialisation de la memoire partagee */
		for (i=0 ; i<tnlog[ComId].ltampon+256 ; i++)
			*(shm+i) = 0;
		tnlog[ComId].shm->pdebut = 0;
		tnlog[ComId].shm->pfin = 0;
		tnlog[ComId].shm->erreur = 0;
		tnlog[ComId].shm->echec = 0;

		/* Interception du signal SIGHUP, provoque par une erreur
		 * modem.
		 */
		tnlog[ComId].sigmodem = FALSE;
		signal(SIGHUP,TCatchsighup[ComId]);

		/* Interception du signal SIGINT, provoque par un break */
		tnlog[ComId].sigint = FALSE;
		signal(SIGINT,TCatchsigint[ComId]);

		/* Signale le bon deroulement au pere */
		kill(father,SIGUSR2);

		/* Alimente le tampon d'anticipation */
		alimente(ComId);
	}
	else {
		/******************/
		/* Processus pere */
		/******************/

		/* Interception du signal utilisateur 1 qui sert au fils
		 * pour signaler au pere qu'il ne peut pas s'initialiser.
		 */
		signal(SIGUSR1,fathersigusr1);

		/* Recuperation des numeros de processus respectifs */
		father = getpid();
		tnlog[ComId].child = child;
		tnlog[ComId].father = father;

		/* Attente du signal du processus fils */
		if (sig == 0) {
#ifdef CXOPEN
			sigsuspend(&set);
#else
			wait(NULL);
#endif
		}

		/* Abandonne si le fils n'a pu se derouler correctement */
		if (sig == 2)
			return(58);

		/* Recuperation du segment de memoire partagee cree par
		 * le processus fils.
		 */
		shmid = shmget(child,tnlog[ComId].ltampon+256,0777);
		if (shmid == -1) {
			kill(child,SIGUSR1);
			wait(NULL);
			return(58);
		}

		/* Attachement du segment de memoire partagee */
		shm = (char PTR)shmat(shmid,(VOID PTR)0L,0);
		if (shm == (char PTR)-1L) {
			kill(child,SIGUSR1);
			wait(NULL);
			return(58);
		}

		/* Recuperation identite du set de semaphores de synchronisation */
		semid = semget(child,1,0777);
		if (semid == -1) {
			kill(child,SIGUSR1);
			wait(NULL);
			return(58);
		}

		/* Validation des informations */
		tnlog[ComId].shmid = shmid;
		tnlog[ComId].shm = (struct SHM PTR)shm;
		tnlog[ComId].semid = semid;
	}

	return(0);
}

/* -----------------------------------------------------------------------
 *
 * Interception du signal utilisateur 2 pour le pere.
 *
 * Ce signal est utilise par le processus fils pour signaler a son
 * pere que les initialisations se sont bien deroulees.
 *
 *	E/ rien
 *	S/ rien
 *
 * -----------------------------------------------------------------------
 */
static VOID fathersigusr2()
{
	/* Indique que le signal est arrive et que tout est dans l'ordre */
	sig = 1;
	signal(SIGUSR2,fathersigusr2);
}

/* -----------------------------------------------------------------------
 *
 * Interception du signal utilisateur 1 pour le pere.
 *
 * Ce signal est utilise par le processus fils pour signaler a son
 * pere qu'il ne peut pas s'initialiser correctement.
 *
 *	E/ rien
 *	S/ rien
 *
 * -----------------------------------------------------------------------
 */
static VOID fathersigusr1()
{
	/* Indique que le signal est arrive et qu'il y a un probleme */
	sig = 2;
	signal(SIGUSR1,fathersigusr1);
}

/* -----------------------------------------------------------------------
 *
 * Interception du signal utilisateur 1 pour le fils.
 *
 * Ce signal est utilise par le processus pere pour provoquer la
 * mort du fils.
 *
 *	E/ rien
 *	S/ rien
 *
 * -----------------------------------------------------------------------
 */
static VOID childsigusr1()
{
	/* Detache le segment de memoire partagee */
	(VOID)shmdt((char PTR)tnlog[encours].shm);

	/* Et se termine... */
	exit(1);
}

/* -----------------------------------------------------------------------
 *
 * Processus fils d'alimentation d'un tampon d'anticipation.
 *
 *	E/ numero logique
 *	S/ rien
 *
 * -----------------------------------------------------------------------
 */
static VOID alimente(ComId)
WORD ComId;
{ WORD pfin,npfin;
  BYTE car;
  WORD cpdu;

	while(TRUE) {
		/* Boucle infernale de lecture de caracteres.
		 * Sortie par signal 1 emis par le pere.
		 */
		cpdu = Xread(tnlog[ComId].handle,&car,1);

		/* Demande l'acces exclusif a la memoire partagee */
		(VOID) getsem(ComId);

		if (cpdu == 1) {
			/* Range le caractere lu */
			pfin = tnlog[ComId].shm->pfin;
			tnlog[ComId].shm->tampon[pfin] = car;

			/* Avance le pointeur d'ecriture */
			npfin = (pfin == tnlog[ComId].ltampon) ? 0 : pfin+1;

			/* Detecte les conditions d'overrun */
			if (npfin != tnlog[ComId].shm->pdebut)
				tnlog[ComId].shm->pfin = npfin;
			else 	{
				tnlog[ComId].shm->erreur = 90;
				}

			/* Remise a zero du compteur d'echecs */
			tnlog[ComId].shm->echec = 0;
			}
		else 	{
			/* Comptabilise les echecs par time-out */
			if (cpdu == 0) {
				tnlog[ComId].shm->echec++;
			}
		}

		/* Traite les erreurs modems eventuelles */
		if (tnlog[ComId].sigmodem == TRUE) {
			tnlog[ComId].shm->erreur = 88;
		}

		/* Traite les detections de break eventuelles */
		if (tnlog[ComId].sigint == TRUE) {
			tnlog[ComId].shm->erreur = 89;
		}

		/* Relache l'acces a la memoire partagee */
		(VOID) relsem(ComId);
	}
}

/* -----------------------------------------------------------------------
 *
 * Suppression du processus d'alimentation du tampon d'anticipation.
 *
 *	E/ numero logique
 *	S/ compte-rendu :
 *		 0 : OK
 *		58 : droits insuffisants
 *
 * -----------------------------------------------------------------------
 */
static WORD Pdelete(ComId)
WORD ComId;
{ WORD cpdu;

	/* Tue le processus fils et attend sa mort */
	kill(tnlog[ComId].child,SIGUSR1);
	wait(NULL);

	/* Detache le segment de memoire partagee */
	(VOID) shmdt((char PTR)tnlog[ComId].shm);

	/* Supprime le segment de memoire partagee */
	(VOID) shmctl(tnlog[ComId].shmid,IPC_RMID,GN(struct shmid_ds));

	/* Supprime le semaphore */
	(VOID) semctl(tnlog[ComId].semid,1,IPC_RMID,0);

	return(0);
}

/* -----------------------------------------------------------------------
 *
 * Demande l'acces exclusif a la voie serie
 *
 *	E/ numero logique
 *	S/ compte-rendu :
 *		 0 : OK
 *		58 : droits insuffisants
 *
 * -----------------------------------------------------------------------
 */
static WORD getsem(ComId)
WORD ComId;
{ WORD cpdu;

	tnlog[ComId].psem.sem_num = 0;
	tnlog[ComId].psem.sem_op = -1;
	tnlog[ComId].psem.sem_flg = SEM_UNDO;
	return((semop(tnlog[ComId].semid,&(tnlog[ComId].psem),1) == -1) ? 58 : 0);
}

/* -----------------------------------------------------------------------
 *
 * Relache l'acces exclusif a la voie serie
 *
 *	E/ numero logique
 *	S/ compte-rendu :
 *		 0 : OK
 *		58 : droits insuffisants
 *
 * -----------------------------------------------------------------------
 */
static WORD relsem(ComId)
WORD ComId;
{ WORD cpdu;

	tnlog[ComId].psem.sem_num = 0;
	tnlog[ComId].psem.sem_op = 1;
	tnlog[ComId].psem.sem_flg = SEM_UNDO;
	return((semop(tnlog[ComId].semid,&(tnlog[ComId].psem),1) == -1) ? 58 : 0);
}

/* -----------------------------------------------------------------------
 *
 * Fonction de conversion de BCD vers entier.
 *
 *	E/ pointeur sur le BCD
 *	   longueur du BCD
 *	S/ entier converti
 *
 * -----------------------------------------------------------------------
 */
static WORD bcd2word(var,lg)
BYTE FAR PTR var;
WORD lg;
{ BYTE buf[50];
  WORD x;
  BYTE c;
  BYTE FAR PTR p1;
  WORD flag,p2;

#ifdef DEBUG
#define fonconv(x) ((x < 10) ? (x+'0') : (x-10+'A'))
	printf("\r\n\n\n");
	printf("\nLGR=%d",lg);
	{ WORD i;
	  char cc;

		printf("\r\nENT=");
		for (i=0 ; i<lg*2 ; i++) {
			cc = *(var+i);
			printf("%c%c",fonconv(((cc & 0xf0)>>4)),fonconv((cc & 0x0f)));
		}
	}
#endif

	/* Initialisations */
	p1 = var;
	c = *p1++;

	/* Pose le signe */
	buf[0] = ((c & 0xf0) == BCD_MOINS) ? '-' : '+';

	/* Detecte le separateur decimal */
	c = (c & 0x0f);
	if (c == BCD_SEP) {
		return(0xFFFF);
	}
	else {
		buf[1] = c + '0';
		p2 = 2;
	}
	lg--;

	/* Traite la fin du nombre */
	flag = 0;
	while ((c != BCD_FIN) && (lg)) {
		if (!flag) {
			c = *p1;
			flag = 1;
			c = (c & 0xf0) >> 4;
		}
		else {
			c = *p1++;
			flag = 0;
			c = c & 0x0f;
			lg--;
		}

		switch (c) {
			case BCD_SEP :
				return(0xFFFF);

			case BCD_FIN :
				buf[p2] = '\0';
				break;

			default :
				buf[p2] = c + '0';
				break;
		}
		p2++;
	}
	buf[p2] = '\0';

	/* Convertit la chaine ainsi produite en numerique */
	x = atoi(&buf[0]);

#ifdef DEBUG
	printf("\r\nBUF=%s\r\n  D=%-+d\n",&buf[0],x);
	sleep(1);
#endif

	return(x);
}

/* -----------------------------------------------------------------------
 *
 * Fonction de lecture d'un caractere sur la voie serie
 * avec interpretation des sequences break et erreur de parite
 *
 *	E/ numero logique
 *	   pointeur sur le caractere a lire
 *	S/ compte-rendu :
 *		 0 : OK
 *		88 : erreur modem
 *		89 : break ou erreur de framing
 *		90 : overrun en reception
 *		91 : time-out expire en lecture
 *		99 : erreur de parite en reception
 *
 * -----------------------------------------------------------------------
 */
static WORD Aread(ComId,car)
WORD ComId;
BYTE PTR car;
{ WORD cpdu;

	/* Principe de l'interpretation :
	 *	- un caractere normalement recu est lu tel quel
	 *	- le caractere FF est lu comme la sequence FF FF
	 *	- une erreur de parite est lue comme la sequence FF 00 xx
	 *	- un break est lu comme la sequence FF 00 00
	 */

	cpdu = LLread(ComId,car);

	/* Est-ce une erreur ou une sequence a interpreter ? */
	if (((cpdu != 0) && (cpdu != 90)) || ((*car) != 0x00FF))
		return(cpdu);

	cpdu = LLread(ComId,car);

	/* Est-ce une erreur ou un caractere FF double ? */
	if (((cpdu != 0) && (cpdu != 90)) || ((*car) == 0x00FF))
		return(cpdu);

	/* Est-ce une sequence incomprehensible ? */
	if ((*car) != 0)
		return(90);

	cpdu = LLread(ComId,car);
	if ((cpdu != 0) && (cpdu != 90))
		return(cpdu);

	/* On ne sait pas distinguer une erreur de parite sur un caractere
	 * nul d'un break. On suppose dans ce cas qu'il s'agit toujours
	 * d'un break.
	 */
	return(((*car) == 0) ? 89 : 99);
}

/* -----------------------------------------------------------------------
 *
 * Fonction de lecture d'un caractere brut
 *
 *	E/ numero logique
 *	   pointeur sur le caractere a lire
 *	S/ compte-rendu :
 *		 0 : OK
 *		88 : erreur modem
 *		89 : detection d'un break
 *		90 : overrun en reception
 *		91 : time-out expire en lecture
 *
 * -----------------------------------------------------------------------
 */
static WORD LLread(ComId,car)
WORD ComId;
BYTE PTR car;
{
  WORD err;
  BOOL end;
  WORD echec;
  BYTE buf[256];

	if (tnlog[ComId].anticipation == TRUE) {
		/* Un tampon d'anticipation est gere : la lecture
		 * se fait au travers d'une fonction de lecture dans
		 * le segment de memoire partagee.
		 */
		end = FALSE;
		while (end == FALSE) {
			err = LLAread(ComId,car);
			if (err == 1) {
				/* Le tampon est vide, mais il faut s'assurer
				 * que le timeout utilisateur est expire.
				 */
				(VOID) getsem(ComId);
				if (tnlog[ComId].shm->echec >= tnlog[ComId].timeout) {
					tnlog[ComId].shm->echec = 0;
					err = 91;
					end = TRUE;
					}
				(VOID) relsem(ComId);
				}
			else 	{
				end = TRUE;
				}
			}
		return(err);
		}
	else 	{
		/* S'il n'y a pas de gestion de tampon d'anticipation,
		 * la lecture se fait directement sur la voie serie.
		 */
		end = FALSE;
		echec = 0;
		while (end == FALSE) {
			err = Xread(tnlog[ComId].handle,car,1);
			if (err == 1) {
				/* Un caractere a ete normalement lu */
				return(0);
				}
			else 	{
				/* Aucun caractere n'a ete lu :
				 *	- soit un signal a interrompu la lecture
				 *	- soit il s'agit d'un time-out
				 *
				 * Est-ce une erreur modem ?
				 */
				if (tnlog[ComId].sigmodem == TRUE) {
					err = 88;
					end = TRUE;
					}
				else 	{
					/* Est-ce une erreur due a un break ? */
					if (tnlog[ComId].sigint == TRUE) {
						err = 89;
						end = TRUE;
						}
					else 	{
						/* Le delai est-il suffisant pour
						 * un time-out utilisateur ?
						 */
						echec++;
						if (echec >= tnlog[ComId].timeout) {
							err = 91;
							end = TRUE;
							}
						}
					}
				}
			}
		return(err);
	}
}

/* -----------------------------------------------------------------------
 *
 * Fonction de lecture d'un caractere brut dans un tampon d'anticipation
 *
 *	E/ numero logique
 *	   pointeur sur le caractere a lire
 *	S/ compte-rendu :
 *		 0 : OK
 *		 1 : time-out anticipation expire en lecture
 *		88 : erreur modem
 *		89 : detection d'un break
 *		90 : overrun en reception
 *
 * -----------------------------------------------------------------------
 */
static WORD LLAread(ComId,car)
WORD ComId;
BYTE PTR car;
{ WORD pdebut;
  WORD pfin;
  WORD err;
  WORD cpdu;
  BYTE buf[256];

	/* Demande l'acces exclusif a la memoire partagee */
	(VOID) getsem(ComId);

	pdebut = tnlog[ComId].shm->pdebut;
	pfin = tnlog[ComId].shm->pfin;
	err = tnlog[ComId].shm->erreur;

	/* Traite les cas d'erreurs detectees par le processus fils :
	 *	- les pertes de caracteres donnent lieu a un diagnostic
	 *	  retarde, apres epuisement du tampon d'anticipation
	 *	- les autres erreurs provoquent une purge du tampon
	 *	  et un diagnostic immediat.
	 */
	if ((err != 0) && (err != 90)) {
		tnlog[ComId].shm->pdebut = 0;
		tnlog[ComId].shm->pfin = 0;
		tnlog[ComId].shm->erreur = 0;
		(VOID) relsem(ComId);
		return(err);
	}

	/* Un tampon d'anticipation est gere pour cette voie :
	 *	- pdebut pointe le premier caractere a lire
	 *	- pfin pointe le prochain caractere a ecrire
	 *	- il s'agit d'un tampon circulaire : lorsque pdebut et
	 *	  pfin sont egaux, le tampon est vide.
	 */
	if (pdebut != pfin) {
		/* Le tampon est renseigne, y chercher le caractere */
		(*car) = tnlog[ComId].shm->tampon[pdebut];

		/* Avancer le pointeur de lecture */
		pdebut = (pdebut == tnlog[ComId].ltampon) ? 0 : pdebut+1;
		tnlog[ComId].shm->pdebut = pdebut;
	}
	else {
		/* Elimine le cas du diagnostic a retardement de
		 * l'erreur de perte de caracteres en reception.
		 */
		if (err == 90) {
			/* Il est inutile de lire sur la voie puisque
			 * l'on a deja perdu des caracteres.
			 */
			tnlog[ComId].shm->erreur = 0;
			err = 91;
		}
		else {
			/* Aucun caractere n'est disponible :
			 * on remonte un compte-rendu de time-out fils
			 * de facon a ce que le pere boucle dessus pendant
			 * la duree du time-out utilisateur.
			 */
			err = 1;
		}
	}

	/* Relache l'acces a la memoire partagee */
	(VOID) relsem(ComId);

	return(err);
}

/* -----------------------------------------------------------------------
 *
 * Fermeture de la bibliotheque.
 *
 *
 *	Cette fonction a pour objet de deconnecter
 *	toutes les voies utilisees, et de fermer tous les
 *	eventuels fichiers journal associes.
 *	Deverrouille tout ce qui aurait pu l'etre par la bibliotheque.
 *
 * -----------------------------------------------------------------------
 */
static VOID FAR cloture()
{ WORD i;
  BOOL reserve;

	/* Balayage de la table des numeros logiques */
	for (i=0 ; i<MAXNLOG ; i++) {

		/* Ne traite que les numeros logiques alloues */
		if (tnlog[i].attach == TRUE) {

			reserve = tnlog[i].reserve;

			/* Deconnecte si voie encore connectee */
			if (tnlog[i].connex == TRUE) {
				tnlog[i].reserve = TRUE;
				(void) ttydcn(i);
			}

			/* Libere si voie encore reservee */
			if (reserve == TRUE)
				(void) ttyclose(i);
		}
	}

	/* Deverouille tout ! */
	PurgeLox();
}


/* -----------------------------------------------------------------------
 *
 * Identification de la bibliotheque.
 *
 * -----------------------------------------------------------------------
 */
static VOID FAR banniere()
{ (void) printf("\n   Procedure TTY sous UNIX");
  (void) printf("\n   Version 1.2a");
#ifdef pilote
  (void) printf(" Provisoire du 30/06/99");
#endif
  (void) printf("\n   Copyright (c) 1991, 2006  Amenesik / Sologic ");
  (void) printf("\n");
}

/* -----------------------------------------------------------------------
 *
 * Verification de la protection anti-copie pirate.
 *
 *	E/ rien
 *	S/ compte-rendu :
 *		FALSE : protection invalide
 *		TRUE  : protection valide
 *
 * -----------------------------------------------------------------------
 */
static BOOL VerifProtect()
{ struct stat statwork;

#ifdef DEBUG
printf("\nControle de la protection");
#endif 

	/* Controle s'il s'agit d'une version de test */
	if ((*((LONG PTR) &ControlZone[CONTROLNODE])) == 0L)
		return(TRUE);

#ifdef DEBUG
printf("\nPas version de test");
#endif 

	/* Il s'agit d'une version installee :
	 * effectue un stat sur le fichier access dont
	 * le chemin d'acces est conserve dans ControlZone.
	 */
	if (stat(&ControlZone[CONTROLPATH],&statwork) != 0)
		return(FALSE);

#ifdef DEBUG
printf("\nAccess trouve");
#endif 

	/* Compare les numeros d'I-node et de D-node lus
	 * par stat et conserves dans ControlZone.
	 */
	if ((*((LONG PTR)(ControlZone+CONTROLNODE)) != statwork.st_ino) ||
	    (*((LONG PTR)(ControlZone+CONTROLUNIT)) != statwork.st_dev))
		return(FALSE);

#ifdef DEBUG
printf("\nAccess inode+dnode corrects");
#endif 

	return(TRUE);
}




/* -----------------------------------------------------------------------
 *
 * Enregistrement d'un message dans le journal,
 * avec indication de l'heure.
 *
 *	E/ numero logique
 *	   ptr sur le message
 *
 * -----------------------------------------------------------------------
 */
/*OLD TRACE
static VOID FAR mess_time(ComId,message)
WORD ComId;
BYTE PTR message;
{ struct tm PTR now;
  time_t secnow;
  BYTE ligne[256];

	// Controle le mode debug 
	if (tnlog[ComId].journal == 0xffff)
		return;

	// Recupere l'heure actuelle 
	secnow = time(NULL);
	now = gmtime(&secnow);

	// Prepare la ligne du journal 
	(void) sprintf(&ligne[0],"\n%0.2d/%0.2d/%0.4d-%0.2d:%0.2d:%0.2d (%0.2d) -> %s",
		now->tm_mday,
		now->tm_mon,
		now->tm_year+1900,
		now->tm_hour,
		now->tm_min,
		now->tm_sec,
		ComId,
		message);

	// Effectue l'ecriture de la ligne 
	(void) Xwrite(tnlog[ComId].journal,&ligne[0],Xstrlen(&ligne[0]));
}
*/
/* -----------------------------------------------------------------------
 *
 * Enregistrement d'un message simple dans le journal.
 *
 *	E/ numero logique
 *	   ptr sur le message
 *
 * -----------------------------------------------------------------------
 */
/*OLD TRACE
static VOID FAR mess(ComId,message)
WORD ComId;
BYTE PTR message;
{
	// Controle le mode debug 
	if (tnlog[ComId].journal == 0xffff)
		return;

	// Ecrit le message dans le fichier journal
	(void) Xwrite(tnlog[ComId].journal,message,Xstrlen(message));
}
*/
