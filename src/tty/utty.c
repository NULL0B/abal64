/*
 *	Projet  : ABAL		Copyright (c) 1991, 2005 Amenesik / Sologic Technologies
 *	Module  : TTY
 *	Fichier : UTTY.C
 *	Version : 1.3b.0.02
 *	Date    : 03/01/2005
 *	Systeme : Use IT et UNIX
 *
 *	Procedure TTY sous Use IT et UNIX
 *
 *	La bibliotheque tty est la reunion de itty.c + utty.c.
 *	Le source itty.c est construit automatiquement et ne doit pas etre
 *	modifie, il s'appuie sur le contenu de tty.def.
 */

#define	VERSION	"1.3b.0.02 - 03.01.2005"
#define	TYPE_POSIX 1
#define	LOCK_DIR "/var/lock"

#include <signal.h>

/*
 *	Remarques sur la gestion des signaux V24 (Chris) :
 *	------------------------------------------------
 *	1/ Les versions precedentes (avant 23/02/2004) utilisaient RIEN et
 *	HARDWARE a la place de CLOCAL et CRTSCTS. Il arrivait que CLOCAL soit
 *	utilise dans les modes 0 et 1 reputes fonctionner avec modem (c'est
 *	un bug). CLOCAL est utilise pour dire qu'il n'y a pas de gestion des
 *	signaux modem, c'est a dire que l'absence d'un signal ne provoque pas
 *	d'erreur, notamment l'absence de CD n'entrave pas le fonctionnement.
 *	CRTSCTS signifie regulation RTS-CTS qui est utilisee par les modems,
 *	il faut verifier que ce type de regulation est possible sur le
 *	systeme Linux/Unix sur lequel la bibliotheque s'execute (Ok pour
 *	Use IT avec TYPE_POSIX). Notamment, la perte de porteuse CD doit
 *	provoquer une erreur 88 sur ttywrite.
 *	2/ La gestion des signaux modem est plus rigoureuse sous Use IT que
 *	sous Twin Server. En cons‚quence, il est bien possible qu'une
 *	application qui fonctionne sous Twin Server ne voit pas les changements
 *	rapides de signaux alors que la mˆme application sous Use IT verra ces
 *	changements rapides avec des erreurs sur ttywrite et/ou ttyread. Par
 *	exemple, sous Twin Server, la pr‚sence de DSR n'est teste qu'a
 *	l'emission du premier caractere d'un ensemble de caracteres. Alors que
 *	sous Use IT, le test de presence du CD est permanent.
 */

/*
 *	Historique des modifications :
 *	----------------------------
 *
 *	3.1e.0.05	09/01/2007	Jamie
 *	-------------------------------------
 *	Correction to ensure that the RTSCTS is dropped when not required
 *	in the same was as performed for the CLOCAL flag. This has been 
 *	performed in coordination with David Rouseau of Lactilis who
 *	observed quite rightly that it was impossible to restore the
 *	line protocol after having raised the RTSCTS handling.
 *
 *	1.3c.0.01	08/03/2006	Jamie
 *	-------------------------------------
 *	Correction to ensure child death reception
 *	has been activated prior to system call and
 *	restitution of non reception of signal for exa
 *	on return in function exclusif().
 *	Exclusion of certain BAUD rate symbols when undefined under AIX/HPUX etc
 *
 *	1.3b.0.02	03/01/2005	Chris
 *	-------------------------------------
 *
 *	1/ initvoie : les donnees en cours d'emission sont purgees :
 *	   tcflush(voie->handle,TCIOFLUSH) (avant nous avions TCIFLUSH).
 *	   Cette modification evite de bloquer sur le Xclose du device quand
 *         des donnees sont presentes en emission au niveau du driver.
 *
 *	1.3b.0.01	25/10/2004	Chris
 *	-------------------------------------
 *
 *	1/ tty_close : l'enchainement ttyopen, ttyclose et ttyopen
 *	   retournait une erreur 84. En effet, le Xclose n'etait fait
 *	   qu'avec ttydcn. Desormais si la voie est ouverte ttyclose
 *	   provoque Xclose.
 *
 *	1.3a.0.01	10/03/2004	Chris
 *	-------------------------------------
 *
 *	1/ banniere() : ajout dans MAKEFILE des variables de compilation ABAL2
 *	et ABAL3 (-DABAL2 ou -DABAL3) pour distinguer tty.so et tty32.so et
 *	avoir des bannieres differenciees.
 *
 *
 *	1.3a.0.01	09/03/2004	Chris
 *	-------------------------------------
 *
 *	1/ ttyopen : gestion du code retour EACCES de la fonction Access qui
 *	avant de verrouiller l'acces fait une fonction fstat.
 *
 *
 *	1.3a.0.01	05/03/2004	Chris
 *	-------------------------------------
 *
 *	1/ Nouvelle description de la variable d'environnement BDATTYMODE :
 *	   0x0001 : gestion des anciens modes de liaison (permute 1 et 2)
 *	   0x0002 : creation du fichier /var/lock/LCK..device selon le standard
 *	            HDB UUCP (numero PID sur 10 caracteres cadre … droite+0x0a).
 *	   0x2000 : ne pas verifier le partage avec d'autres applications que
 *	            Abal (ne pas utiliser fuser) --> compatibilite 1.1 et 1.2.
 *	   0x4000 : non affichage de la banniere avec ttyopen(nlog," ")
 *	   0x8000 : reception en mode transparent du driver de device
 *	BDATTYMODE est un nombre code sur 16 bits.
 *	2/ Creation du fichier /var/lock/LCK..device selon la valeur de la
 *	variable d'environnement BDATTYMODE.
 *	3/ Xwrite impossible retourne l'erreur 88 a la place de 91 pour
 *	etre compatible avec Twin Server (en general CD absent).
 *
 *
 *	1.3a.0.01	02/03/2004	Chris
 *	-------------------------------------
 *
 *	1/ ttyopen : prise en compte de l'erreur 40, device inconnu, au retour
 *	d'appel de la fonction de reservation Access qui est realisee avant
 *	l'open du device (avant on avait une erreur 84 avec un device inconnu).
 *	2/ ttyopen : si le device n'est pas en mode caractere, retour de
 *	l'erreur 56 au lieu de l'erreur 85 (respect de la documentation).
 *
 *
 *	1.3a.0.01	25/02/2004	Chris
 *	-------------------------------------
 *
 *	1/ Copyright (c) Amenesik / Sologic Technologies
 *
 *
 *	1.3a.0.01	25/02/2004	Chris
 *	-------------------------------------
 *
 *	1/ Ajout de la variable d'environnement BDATTYMODE qui permet
 *	de permutter les modes de liaison a la connexion 1 et 2 comme cela
 *	etait fait avec les versions 1.1 et 1.2 de la bibliotheque.
 *	BDATTYMODE est une combinaison de valeurs :
 *		1 : gestion des anciens modes de liaison (permute 1 et 2)
 *		2 : non affichage de la banniere avec ttyopen(nlog," ")
 *		4 : reception en mode transparent du driver de device
 *	2/ La fonction ttyopen(nlog," ") permet d'afficher la banniere.
 *      Modification de la banniere qui ne fait plus reference a la
 *	procedure TTY.
 *	3/ Aread, la purge du 20/01/2004 sur erreur etait incorrecte et
 *	mangeait un caractere en cours de reception. En effet, l'erreur 91
 *	etait consideree comme une vraie erreur physique.
 *	4/ Modification des commentaires d'en-tete des fonctions pour
 *	n'indiquer que les codes erreur effectivement retournes.
 *	5/ Il est a noter que l'erreur 90 (overrun) n'exite pas ici.
 *
 *
 *	1.3a.0.01	23/02/2004	Chris
 *	-------------------------------------
 *
 *	1/ Revision complete de initvoie pour qu'il soit plus lisible.
 *	Utilisation de termios.h et definition des valeurs vitesse,
 *	nombre de bits, etc... 	en LONG. Suppression condition CXOPEN qui
 *	n'est jamais definie et est remplacee par TYPE_POSIX.
 *
 *
 *	1.3a.0.01	12/02/2004	Chris
 *	-------------------------------------
 *
 *	1/ le timeout est convertit de centiemes de secondes en dixiemes de
 *	secondes avec approximation majorante : (timeout + 9)/10. Un timeout
 *	a zero est accepte comme sous Twin Server.
 *
 *	2/ LLread : ajout de l'option de compilation WITH_SELECT. Si il y a
 *	#define WITH_SELECT, l'instruction select precede de read en evitant
 *	de boucler sur le read pour gerer l'erreur de time out 91.
 *
 *
 *	1.3a.0.01	09/02/2004	Chris
 *	-------------------------------------
 *
 *	1/ ttyconnect fait Xopen car le Xclose est fait par ttydcn (et non pas
 *	par ttyclose). Maintenant nous faisons la meme chose que ttyopen :
 *	Xopen(O_RDWR | O_NOCTTY | O_NDELAY), exclusif() et fcntl(F_SETFL,0).
 *
 *
 *	1.3a.0.01	06/02/2004	Chris
 *	-------------------------------------
 *
 *	1/ Suppression des include inutiles.
 *	2/ Suppression declaration buf[256] dans LLread inutile.
 *	3/ Verifier si le device est utilise par un autre utilisateur
 *	( utilitaire fuser /dev/tty... > tmpfile ).
 *
 *
 *	1.3a.0.01	03/02/2004	Chris
 *	-------------------------------------
 *
 *	1/ Ajout de la constante VERSION qui est le numero de version
 *	de la tty. Ce numero est ajoute a la trace binaire lors de la
 *	fonction ttyopen, pour cela nous notons la fonction 0 dans la
 *	trace binaire.
 *
 *
 *	1.3a.0.01	28/01/2004	Chris
 *	-------------------------------------
 *
 *	1/ ttyread : le tampon de reception doit etre au moins de trois octets,
 *	ce qui est conforme a la documentation. Avant on testait deux, ce qui
 *	devait bien planter.
 *
 *
 *	1.3a.0.01	23/01/2004	Chris
 *	-------------------------------------
 *
 *	1/ ttyopen : la verification du nom de device vide etait erronee
 *	et provoquait un core dump.
 *
 *
 *	1.3a.0.01	21/01/2004	Chris
 *	-------------------------------------
 *
 *	1/ L'octet mode de liaison a desormais les memes valeurs que sous
 *	Twin Server et Windows. Les modes 1 et 2 etaient permutes donc toutes
 *	applications modifiees pour passer du mode 1 en mode 2 doivent etre
 *	a nouveau modfiees pour respecter le standard Twin Server et Windows.
 *
 *
 *	1.3a.0.01	20/01/2004	Chris
 *	-------------------------------------
 *
 *	1/ En lecture (Aread) purge du buffer du controleur physique
 *	en cas d'erreur, ce qui evite a l'application d'avoir l'erreur
 *	plusieurs fois de suite des qu'un caractere errone est recu.
 *	Ce mecanisme respecte l'existant sous Twin Server qui en cas
 *	d'erreur purge son buffer d'anticipation.
 *
 *
 *	1.3a.0.01	14/01/2004	Chris
 *	-------------------------------------
 *
 *	1/ Suppression de la gestion du tampon d'anticipation car :
 *	- fait avec fork qui casse toute la mecanique exa+tty.so.
 *	- le process cree par fork n'est pas plus prioritaire que le programme
 *	  Abal.
 *	- le time-out de reception n'est pas respecte car il n'est pas tenu
 *	  compte du temps pendant lequel le process n'est pas actif.
 *	2/ La fonction ttybuffer est desormais sans effet sur le
 *	fonctionnement de la bibliotheque.
 *	3/ Suppression des declarations char buf[128] inutilisees dans les
 *	fonction ttyXXX, ce qui economise du stack donc de la memoire.
 *
 *
 *	1.3a.0.01	13/01/2004	Chris
 *	-------------------------------------
 *
 *	1/ ttyconfig devient ttybuffer, ce qui est conforme avec tty.def.
 *	2/ ttyselmode disparait, ce qui est conforme avec tty.def.
 *	3/ Ajout trace binaire declenchee avec la variable d'environement
 *	ayant pour nom celui du device. Elle contient le repertoire ou sera
 *	stocke le fichier .bin. Par exemple le device /dev/ttyS0 a besoin
 *	de la variable ttyS0. Le nom du fichier sera ttyS0_YYMMDD.bin ou
 *	YY est l'annee, MM pour le mois et DD pour le jour.
 *	4/ Dans la trace la fonction 5 est ttywrite sans echo alors que
 *	0x85 est ttywrite avec echo.
 *
 *
 *	1.3a.0.01	09/01/2004	Chris
 *	-------------------------------------
 *
 *	1/ Suppression de tout ce qui avait ete mis en commentaires entre
 *	**** Start Chris et **** Stop Chris de la version anterieure au
 *	18/12/2003.
 *	2/ Suppression de la gestion des signaux SIGHUP et SIGINT car
 *	il est indique dans init_voie qu'ils ne sont pas geres. La
 *	routine ErrFromSignal disparait.
 *	Ces signaux ne permettent pas la gestion multivoie car il n'existe
 *	qu'un signal par process pour toutes les voies donc piege a con.
 *	3/ Suppression de la trace MI_TRACE_* au profit d'une trace binaire
 *	qui construit un fichier de trace enormement moins volumineux.
 *
 *
 *	1.2a		18/12/2003	Chris
 *	-------------------------------------
 *
 *	1/ Force l'absence de tampon d'anticipation dans ttyopen
 *	(tnlog[ComId].anticipation = FALSE). Pour avoir un tampon
 *	d'anticipation, il faut toujours faire suivre ttyopen par ttybuffer.
 *	2/ Avec tampon d'anticipation, toutes les erreurs purgent le tampon,
 *	avant il y avait un traitement special pour l'erreur 90. En fait,
 *	l'algo est identique a celui de PTTY >= 1.7 de Twin Server.
 *	3/ La routine ErrFromSignal est ajoutee pour traiter les erreurs
 *	ayant pour origine les signaux SIGHUP (erreur modem ou 88) et
 *	SIGINT (break ou erreur 89). Dans ces cas les flags
 *	tnlog[ComId].sigmodem et tnlog[ComId].sigint positionnes a TRUE par
 *	les routines de gestion des signaux sont effaces a FALSE. Ce qui
 *	evite d'avoir des erreurs persistantes dans les cas ou l'application
 *	continue de faire ttyread ou ttywrite sans faire ttydcn.
 *	4/ ttywrite : si le Xwrite n'est pas possible sur toute sa longueur,
 *	on appelle ErrFromSignal, s'il n'y a pas de signal on retourne 91
 *	(emission impossible). Avant on retournait 99 qui n'est pas une erreur
 *	d'emission.
 *	5/ ttyread : si le tampon d'anticipation est sature, l'erreur 63
 *	(positionnee par la routine alimente qui tourne en tache de fond)
 *	est retournee a la place de l'erreur 90 pour etre conforme a la doc.
 *	6/ ttyread : le device driver peut retourner FF 00 xx (erreur 99)
 *	meme quand on n'a pas demande de verifier la parite. Dans ce cas
 *	l'erreur devient 89.
 *	7/ Si la fonction read device (Xread) retourne autre chose que 0 ou 1,
 *	par exemple -1, on retourne l'erreur 89.
 *
 *
 *	1.2a	30/06/1999	????
 *	----------------------------
 */

#include	<stdio.h>
#include	<stdlib.h>
#ifdef	TYPE_POSIX
#  include	<termios.h>
#else
#  include	<termio.h>
#endif
#include	<malloc.h>
#include	<string.h>
#include	<fcntl.h>
#include	<time.h>
#include	<errno.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<sys/file.h>
#ifdef	WITH_SELECT
#  include	<unistd.h>
#endif

#include	"bda.h"
#include	"utty.h"
#include 	"abal.h"

#ifndef	CRTSCTS
#ifdef	 MCTS
#define	CRTSCTS MCTS
#else
#define	CRTSCTS 0
#endif
#endif

static write_trace_handle(
	FILE *handle,
	TRACE_BIN point,
	BYTE FAR PTR buffer );

static write_trace(
	WORD ComId,
	TRACE_BIN point,
	BYTE FAR PTR buffer );

/* ------------------------------------- */
/* Variables globales de la bibliotheque */
/* ------------------------------------- */
/* Attention : si des variables de memes noms existent dans d'autres */
/* bibliotheques Abal type SHARED, cela peut poser des problemes sous */
/* Use IT (confusion des variables et casse memoire). Sympa le bug !! */

DVOIE tnlog[MAXNLOG];		/* table de description des connexions */
BDA desrt;			/* description de la bibliotheque */

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
	desrt.nombre = 8;	/* 12/01/2004 */

	/* Mise en place des relais de l'edition de liens dynamiques */
#ifdef vms					/***** VMS *****/
	desrt.nom[0] = (BYTE FAR PTR) "_ttyopen";
	desrt.nom[1] = (BYTE FAR PTR) "_ttyclose";
	desrt.nom[2] = (BYTE FAR PTR) "_ttyconnect";
	desrt.nom[3] = (BYTE FAR PTR) "_ttydcn";
	desrt.nom[4] = (BYTE FAR PTR) "_ttywrite";
	desrt.nom[5] = (BYTE FAR PTR) "_ttyread";
	desrt.nom[6] = (BYTE FAR PTR) "_ttybreak";
	desrt.nom[7] = (BYTE FAR PTR) "_ttybuffer";
#else /* vms */
	desrt.reserve = (VOID FAR PTR) 0L;
#  ifdef FCT_ENTETE				/***** UNIX *****/
	desrt.fonction[0] = (WORD (FAR PTR)()) _ttyopen;
	desrt.fonction[1] = (WORD (FAR PTR)()) _ttyclose;
	desrt.fonction[2] = (WORD (FAR PTR)()) _ttyconnect;
	desrt.fonction[3] = (WORD (FAR PTR)()) _ttydcn;
	desrt.fonction[4] = (WORD (FAR PTR)()) _ttywrite;
	desrt.fonction[5] = (WORD (FAR PTR)()) _ttyread;
	desrt.fonction[6] = (WORD (FAR PTR)()) _ttybreak;
	desrt.fonction[7] = (WORD (FAR PTR)()) _ttybuffer;
#  else  /* FCT_ENTETE */				/***** PROLOGUE et MS/DOS *****/
	desrt.fonction[0] = (WORD (FAR PTR)()) ttyopen;
	desrt.fonction[1] = (WORD (FAR PTR)()) ttyclose;
	desrt.fonction[2] = (WORD (FAR PTR)()) ttyconnect;
	desrt.fonction[3] = (WORD (FAR PTR)()) ttydcn;
	desrt.fonction[4] = (WORD (FAR PTR)()) ttywrite;
	desrt.fonction[5] = (WORD (FAR PTR)()) ttyread;
	desrt.fonction[6] = (WORD (FAR PTR)()) ttybreak;
	desrt.fonction[7] = (WORD (FAR PTR)()) ttybuffer;
#  endif /* FCT_ENTETE */
#endif /* vms */

	/* Initialisations diverses */
	for (i=0 ; i<MAXNLOG ; i++) {
		tnlog[i].handle = -1;	/* Protection contre nos propres bugs */
		tnlog[i].attach = FALSE;
		tnlog[i].reserve = FALSE;
		tnlog[i].connex = FALSE;
		tnlog[i].open = FALSE;
		tnlog[i].device = GN(BYTE);
		tnlog[i].trace_handle = (FILE *) 0;
	}

	/* Controle de la protection anti-copie pirate :
	 * en cas de violation, on ne declare plus aucune fonction
	 * dans la bibliotheque dynamique. D'ou une erreur 139 systematique.
	 */
	if (VerifProtect() == FALSE)
		desrt.nombre = 0;

	/* Regarde si le mode debug est positionne. */
	ModeDebug = ((getenv("PTTYDEBUG") == GN(char)) ? FALSE : TRUE);

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

WORD _ttybuffer(a)
VOID PTR a[];
{
	return (ttybuffer(GetParaWord(0), GetParaWord(1) ));
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
 *		58 : droits d'acces insuffisants
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
  WORD i,j,len;
  int handle,resac;
  struct stat buf;
  int mode;
  WORD locComId;
  TRACE_BIN trace;
  BOOL indic_trace;
  time_t temps;
  struct tm* heure;
  char * trace_name=(char*)0;
  FILE * trace_handle=(FILE*)0;
  char * bdattymode=(char*)0;
  WORD ttymode;
  BYTE FAR PTR ptr1;
  BYTE FAR PTR ptr2;
  char buffer[128];

	/* Lire la variable d'environnement BDATTYMODE */

	bdattymode = getenv("BDATTYMODE");
	ttymode = 0;
	if ( bdattymode != (char *) 0 )
	{
		ttymode = (WORD) atol(bdattymode);
	}

	/* Lire la taille de la variable nom de device */

	len = rt_arg.l[1];

	/* Afficher la banniere si device = " " sauf si BDATTYMODE=2 */

	if ( ( len == 1 ) && ( *device == ' ' ) )
	{
		if ( (ttymode & 0x4000) == 0 )
		{
			banniere();
		}
	}

	/* Verifier la longueur du nom de device */

	if ((len < 2) || (len > MAXNOM-1))
		return(85);

	/* ------------------------------------------------- */
	/* Copy the device name and eliminate trailing space */
	/* ------------------------------------------------- */
	if ((locdevice = (BYTE FAR PTR) Xmalloc(len+1)) == GN(BYTE))
		return(27);

	trace.maxlength = len ;
	Xmemcpy(locdevice,device,len);

	i = 0;
	while ( i < len)
	{
		if (locdevice[i] <= ' ') break;
		i++ ;
	}

	if (i == 0)
	{
		Xfree(locdevice);
		return(85);
	}
	trace.uselength = i ;
	locdevice[i] = EOSTR;

	/* -------------------------------------------------------- */
	/* Activation de la trace binaire si nom de device coherent */
	/* -------------------------------------------------------- */

	ptr1 = locdevice;
	if ( (ptr2 = strrchr(ptr1,'/')) != (char *) 0 )
	{
		ptr1 = ptr2 + 1;
	}

	trace_name = getenv(ptr1);

	/* Pour la trace binaire */

	if ( trace_name != (char *) 0 )
	{
		time(&temps);
		heure = localtime(&temps);
		sprintf(buffer,"%s/%s_%02d%02d%02d.bin",trace_name,ptr1,heure->tm_year-100, heure->tm_mon+1, heure->tm_mday);
		trace_handle=fopen(buffer,"a");
		if ( trace_handle != (FILE*) 0 )
		{
			indic_trace = TRUE;

			time(&trace.date);
			trace.nlog = 0;

			/* Note version of tty.so in binary trace */
			/* Note aussi la valeur de BDATTYMODE */

			trace.function = 0;
			trace.retcode = ttymode;
			i = trace.uselength; /* save */
			j = trace.maxlength; /* save */
			trace.uselength = sizeof(VERSION)-1; /* -1 to ignore null at end */
			trace.maxlength = sizeof(VERSION)-1;
			write_trace_handle(trace_handle,trace,VERSION);
			trace.uselength = i ; /* restore */
			trace.maxlength = j ; /* restore */

			/* Note function ttyopen */

			trace.function = 1;
		}
	}

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
			trace.retcode = 51;
			write_trace_handle(trace_handle,trace,device);
			return(51);
			}
		}

	/* ---------------------------------------------------------- */
	/* I suppose if we got here we have a resonable handle to use */
	/* So lets try and lock it now : not later 		      */
	/* ---------------------------------------------------------- */
	if ((resac = Access(locdevice,0,1)) != 0)
	{

		if (ModeDebug) { perror("Access device"); }

		Xfree(locdevice);
		switch (errno)
		{
			/* Droits d'acces insuffisants */
			case EACCES :
				trace.retcode = 58;
				write_trace_handle(trace_handle,trace,device);
				return(58);
			/* Non existence du device */
			case ENOENT :
				trace.retcode = 40;
				write_trace_handle(trace_handle,trace,device);
				return(40);
			/* Access non actif */
			case 666:
			case 667:
				trace.retcode = 56;
				write_trace_handle(trace_handle,trace,device);
				return(56);
			/* Device deja reserve */
			default:
				trace.retcode = 84;
				write_trace_handle(trace_handle,trace,device);
				return(84);
		}
	}

	/* ---------------------- */
	/* Open the Device Driver */
	/* ---------------------- */
	if ((handle = Xopen(locdevice,(O_RDWR | O_NOCTTY | O_NDELAY))) == -1)
	{
		liberlox(locdevice);
		Xfree(locdevice);
		switch (errno)
		{
			/* Droits d'acces insuffisants */
			case EACCES :
				trace.retcode = 58;
				write_trace_handle(trace_handle,trace,device);
				return(58);
			/* Non existence du device */
			case ENOENT :
				trace.retcode = 40;
				write_trace_handle(trace_handle,trace,device);
				return(40);
			/* Autres */
			default :
				trace.retcode = 85;
				write_trace_handle(trace_handle,trace,device);
				return(85);
		}
	}

	/* ------------------------------------------------------- */
	/* The O_NDELAY has made the handle non-blocking : rectify */
	/* ------------------------------------------------------- */
	fcntl(handle, F_SETFL, 0 );

	/* ------------------------------------------------------- */
	/* Verifier que nous sommes les seuls a utiliser le device */
	/* ------------------------------------------------------- */
	if ( (ttymode & 0x2000) == 0 )
	{
		if ( (i = exclusif(locdevice)) != 1 )
		{
			if ( i == 2 )
			{
				i = 84 ; /* au moins 2 utilisateurs, nous et autres */
			}
			else
			{
				i = 56 ; /* impossible de faire fuser... */
			}
			Xclose(handle);
			liberlox(locdevice);
			Xfree(locdevice);
			trace.retcode = i;
			write_trace_handle(trace_handle,trace,device);
			return(i);
		}
	}
	
	/* ---------------------------------------------------------- */
	/* Verouiller le device avec un fichier /var/lock/LCK..device */
	/* ---------------------------------------------------------- */

	i = dolock(ttymode,locdevice);
	if ( i != 1 )
	{
		Xclose(handle);
		liberlox(locdevice);
		Xfree(locdevice);
		trace.retcode = 56;
		write_trace_handle(trace_handle,trace,device);
		return(56);
	}

	/* -------------------------------------------- */
	/* Ensure that the device is a character device */
	/* -------------------------------------------- */
	if (fstat(handle,&buf) == -1)
	{
		Xclose(handle);
		liberlox(locdevice);
		unlock(ttymode,locdevice);
		Xfree(locdevice);
		trace.retcode = 56;
		write_trace_handle(trace_handle,trace,device);
		return(56);
	}
	if ((mode = (buf.st_mode & S_IFMT)) != S_IFCHR)
	{
		Xclose(handle);
		liberlox(locdevice);
		unlock(ttymode,locdevice);
		Xfree(locdevice);
		trace.retcode = 56;
		write_trace_handle(trace_handle,trace,device);
		return(56);
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
	tnlog[locComId].trace_handle = trace_handle ;
	tnlog[locComId].bdattymode = ttymode;

	/* ------------------------------- */
	/* Store the Handle for the Caller */
	/* ------------------------------- */
	PutAbalWord( ComId, locComId );

	if ( indic_trace == TRUE )
	{
		trace.nlog = locComId;
		trace.retcode = 0;
		write_trace_handle(trace_handle,trace,device);
	}

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
TRACE_BIN trace;

	/* Verifie que le numero logique est possible */
	if (ComId > MAXNLOG)
		return(50);

	/* Controle la validite du numero logique */
	if (tnlog[ComId].attach == FALSE)
		return(50);

	/* Pour la trace binaire */

	if ( tnlog[ComId].trace_handle != (FILE *) 0 )
	{
		time(&trace.date);
		trace.function = 2;
		trace.nlog = ComId;
		trace.maxlength = 0;
		trace.uselength = 0;
	}

	/* Controle l'etat de la voie */
	if (tnlog[ComId].reserve == FALSE)
	{
		trace.retcode = 42;
		write_trace(ComId,trace,0);
		return(42);
	}

	/* Ferme le device associe a la voie (1.1b.0.01 25/10/2004) */
	if (tnlog[ComId].open == TRUE)
	{
		(void) Xclose(tnlog[ComId].handle);
		tnlog[ComId].handle = -1;	/* Protection contre nos propres bugs */
		tnlog[ComId].open = FALSE;
	}

	/* Leve le verrou exclusif sur le device */
	liberlox(tnlog[ComId].device);

	/* Liberer le verrou de type /var/lock/LCK..device */
	unlock(tnlog[ComId].bdattymode,tnlog[ComId].device);

	/* Indique que le device n'est plus reserve */
	tnlog[ComId].reserve = FALSE;

	/* Libere eventuellement le numero logique si la
	 * voie a ete prealablement deconnectee.
	 */
	if (tnlog[ComId].connex == FALSE)
	{
		Xfree(tnlog[ComId].device);
		tnlog[ComId].device = GN(BYTE);
		tnlog[ComId].attach = FALSE;
	}

	trace.retcode = 0;
	write_trace(ComId,trace,0);

	if ( tnlog[ComId].trace_handle != (FILE *) 0 )
	{
		fclose(tnlog[ComId].trace_handle);
		tnlog[ComId].trace_handle = (FILE *) 0;
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
 *		56 : droits insuffisant pour fuser...
 *		84 : voie deja connectee
 *		85 : descripteur incorrect
 *		86 : voie non initialisable ou
 *		     device deja utilise par ailleurs
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
  TRACE_BIN trace;
  BYTE i;

	/* Verifie que le numero logique est possible */
	if (ComId > MAXNLOG)
		return(50);

	/* Controle la validite du numero logique */
	if (tnlog[ComId].attach == FALSE)
		return(50);

	/* Pour la trace binaire */

	if ( tnlog[ComId].trace_handle != (FILE *) 0 )
	{
		time(&trace.date);
		trace.function = 3;
		trace.nlog = ComId;
	}

	/* Recuperation des parametres de connexion */

	if (rt_arg.c > 1) {
		/* Un tampon de parametres existe */
		len = rt_arg.l[1];
		trace.maxlength = len;
		trace.uselength = len;
		if (len < 6)
		{
			trace.maxlength = len;
			trace.retcode = 85;
			write_trace(ComId,trace,tampon);
			return(85);
		}

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
		trace.maxlength = 0;
		trace.uselength = 0;
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


	/* Controle l'etat de la voie */
	if (tnlog[ComId].reserve == FALSE)
	{
		trace.retcode = 42;
		write_trace(ComId,trace,tampon);
		return(42);
	}

	/* Controle de la deconnexion */
	if (tnlog[ComId].connex == TRUE)
	{
		trace.retcode = 84;
		write_trace(ComId,trace,tampon);
		return(84);
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
#ifdef	B57600
		case 17 : tnlog[ComId].vitesse = B57600;
			  break;
#endif
		/* Autres valeurs et 2000, 3600 et 7200 bauds non supportes */
		default :
			trace.retcode = 85;
			write_trace(ComId,trace,tampon);
			return(85);
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
	tnlog[ComId].oparite = (format & 0x10) ? PARENB : 0;  /* enable parity output */
	tnlog[ComId].iparite = (format & 0x10) ? INPCK : 0; /* parity check input */
	tnlog[ComId].typeparite = (format & 0x20) ? 0 : PARODD; /* 0: even , 1: odd */

	switch ((format >> 6) & 0x03) {
		case 1 : tnlog[ComId].nstops = 0;
			 break;
		case 3 : tnlog[ComId].nstops = CSTOPB;
			 break;

		/* Autres valeurs et 1,5 bits non supportes */
		default :
			trace.retcode = 85;
			write_trace(ComId,trace,tampon);
			return(85);
	}

	/* Si la variable d'environnement BDATTYMODE=1 existe alors les */
	/* modes 1 et 2 sont permutes comme avec les versions 1.1 et 1.2 */

	if ( ( tnlog[ComId].bdattymode & 0x0001 ) != 0 )
	{
		switch ( liaison )
		{
			case 1 :
				liaison = 2;
				break ;
			case 2 :
				liaison = 1;
				break ;
		}
	}

	/* Controle et initialisation mode de liaison (idem a Twin Server) */
	/* Remarque : le mode duplex n'est pas gere (booleen duplex inutilise) */

	switch ( liaison )
	{
		case 0 :
			tnlog[ComId].duplex = FALSE;
			tnlog[ComId].modem = CRTSCTS;
			break;
		case 1 :
			tnlog[ComId].duplex = TRUE;
			tnlog[ComId].modem = CRTSCTS;
			break;
		case 2 :
			tnlog[ComId].duplex = TRUE;
			tnlog[ComId].modem = CLOCAL; /* ignore status modem */
			break;
		/* Autres valeurs non supportees */
		default :
			trace.retcode = 85;
			write_trace(ComId,trace,tampon);
			return(85);
	}

	/* Initialisation autres champs */

	tnlog[ComId].finenr = finenr;
	tnlog[ComId].finfich = finfich;
	timeout = (timeout+9)/10;	 /* Conversion centiemes-->dixiemes */
	tnlog[ComId].timeout = timeout;
	tnlog[ComId].transp = (transp == 1) ? TRUE : FALSE;

#ifdef	ANCIENNE_METHODE
	/* this is great too : in fact we never use the flag duplex */
	tnlog[ComId].duplex = ((liaison & 1) == 1) ? TRUE : FALSE;
#  ifdef	CLAUDE_ROBLEZ
	/* original stupid expression */
	/* tnlog[ComId].modem = ((liaison & 2) == 2) ? (CTSFLOW | RTSFLOW) : (CLOCAL | CTSFLOW | RTSFLOW); */
#  else
	/* -------------------------------------------------------------------------------------------- */
	/* This is the bit that is UNIX specific : other systems are the opposite : thanks a lot claude */
	/* The definitions are correct, defined in the file modem.h (11/09/2003 : IJM et JS)		*/
	/* -------------------------------------------------------------------------------------------- */
	tnlog[ComId].modem = ((liaison & 2) == 2) ? (HARDWARE) : (RIEN);
#  endif
#endif

	/* Gestion du cas ttyconnect qui suit ttydcn :
	 * 	- reouvrir le device
	 *	- verifier que le device est toujours disponible
	 *	- fcntl
	*/
	if (tnlog[ComId].open == FALSE)
	{
		handle = Xopen(tnlog[ComId].device,(O_RDWR | O_NOCTTY | O_NDELAY));
		if (handle == -1)
		{
			trace.retcode = 86;
			write_trace(ComId,trace,tampon);
			return(86);
		}
		/* The O_NDELAY has made the handle non-blocking : rectify */
		fcntl(handle, F_SETFL, 0 );
		/* Verifier que nous sommes les seuls a utiliser le device */
		if ( (tnlog[ComId].bdattymode & 0x2000) == 0 )
		{
			if ( (i = exclusif(tnlog[ComId].device)) != 1 )
			{
				if ( i == 2 )
				{
					i = 86 ; /* au moins 2 utilisateurs, nous et autres */
				}
				else
				{
					i = 56 ; /* impossible de faire fuser... */
				}
				Xclose(handle);
				trace.retcode = i;
				write_trace(ComId,trace,tampon);
				return(i);
			}
		}
		tnlog[ComId].handle = handle;
		tnlog[ComId].open = TRUE;
	}

	/* Initialisation de la voie serie */
	cpdu = initvoie(&tnlog[ComId]);
	if (cpdu != 0)
	{
		trace.retcode = cpdu;
		write_trace(ComId,trace,tampon);
		return(cpdu);
	}

	tnlog[ComId].connex = TRUE;
	trace.retcode = 0;
	write_trace(ComId,trace,tampon);
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
{
  WORD cpdu;
  TRACE_BIN trace;

	/* Verifie que le numero logique est possible */
	if (ComId > MAXNLOG)
		return(50);

	/* Controle la validite du numero logique */
	if (tnlog[ComId].attach == FALSE)
		return(50);

	/* Pour la trace binaire */

	if ( tnlog[ComId].trace_handle != (FILE *) 0 )
	{
		time(&trace.date);
		trace.function = 4;
		trace.nlog = ComId;
		trace.maxlength = 0;
		trace.uselength = 0;
	}

	/* Controle l'etat de la voie */
	if (tnlog[ComId].reserve == FALSE)
	{
		trace.retcode = 42;
		write_trace(ComId,trace,0);
		return(42);
	}

	/* Controle de la deconnexion */
	if (tnlog[ComId].connex == FALSE)
	{
		trace.retcode = 83;
		write_trace(ComId,trace,0);
		return(83);
	}

	/* Deconnecte physiquement la ligne */

	tnlog[ComId].vitesse = B0;	/* B0 = erase DTR */
	cpdu = initvoie(&tnlog[ComId]);

	/* Ferme le device associe a la voie */
	(void) Xclose(tnlog[ComId].handle);
	tnlog[ComId].handle = -1;	/* Protection contre nos propres bugs */
	tnlog[ComId].open = FALSE;

	/* Indique voie deconnectee */
	tnlog[ComId].connex = FALSE;

	trace.retcode = 0;
	write_trace(ComId,trace,0);
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
 *		88 : emission impossible (write)
 *		Avec echo :
 *		87 : echo incorrect en emission
 *		89 : detection d'un break recu en echo
 *		91 : time-out expire d'attente de l'echo
 *		99 : reception de l'echo avec une erreur de parite
 *
 * -----------------------------------------------------------------------
 */
static WORD FAR ttywrite(ComId,echo,tampon)
WORD ComId;
BYTE echo;
BYTE FAR PTR tampon;
{
  WORD len;
  BYTE car,carlu;
  WORD i;
  WORD cpdu;
  TRACE_BIN trace;

	/* Verifie que le numero logique est possible */
	if (ComId > MAXNLOG)
		return(50);

	/* Controle la validite du numero logique */
	if (tnlog[ComId].attach == FALSE)
		return(50);

	/* Pour la trace binaire */

	if ( tnlog[ComId].trace_handle != (FILE *) 0 )
	{
		time(&trace.date);
		if ( echo == 0 )
		{
			trace.function = 5;
		}
		else
		{
			trace.function = 0x85;
		}
		trace.nlog = ComId;
	}

	/* Recupere la longueur du tampon a emettre */
	len = rt_arg.l[2];
	trace.maxlength = len;
	trace.uselength = 0;
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
			default :
				trace.retcode = 85;
				write_trace(ComId,trace,0);
				return(85);
		}

		/* Controle de la longueur */
		if (len < ltampon)
		{
			trace.retcode = 85;
			write_trace(ComId,trace,0);
			return(85);
		}
		len = ltampon;
		trace.uselength = len;
	}

	trace.uselength = len;

	/* Controle l'etat de la voie */
	if (tnlog[ComId].reserve == FALSE)
	{
		trace.retcode = 42;
		write_trace(ComId,trace,tampon);
		return(42);
	}

	/* Controle de la connexion */
	if (tnlog[ComId].connex == FALSE)
	{
		trace.retcode = 83;
		write_trace(ComId,trace,tampon);
		return(83);
	}

	/* Effectue l'ecriture proprement dite */
	if (echo == 0)
	{
		/* Sans echo */
		if (Xwrite(tnlog[ComId].handle,tampon,len) != len)
		{
			trace.retcode = 88;
			write_trace(ComId,trace,tampon);
			return( 88 ); /* emission impossible */
		}
	}
	else
 	{
		/* Avec echo */
		for (i=0 ; i<len ; i++)
		{
			car = *(tampon+i);

			/* Emet un caractere */
			if (Xwrite(tnlog[ComId].handle,&car,1) != 1)
			{
				trace.retcode = 88;
				write_trace(ComId,trace,tampon);
				return( 88 ); /* emission impossible */
			}

			/* Attend son echo en retour */
			cpdu = Aread(ComId,&carlu);
			if (cpdu != 0)
			{
				trace.retcode = cpdu;
				write_trace(ComId,trace,tampon);
				return(cpdu);
			}

			/* Compare le caractere emis et le caractere recu */
			if (car != carlu)
			{
				trace.retcode = 87;
				write_trace(ComId,trace,tampon);
				return(87);
			}
		}
	}

	trace.retcode = 0;
	write_trace(ComId,trace,tampon);
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
 *		83 : voie non connectee
 *		85 : descripteur incorrect
 *		89 : detection d'un break
 *		91 : time-out
 *		En mode non transparent :
 *		 0 : fin d'enregistrement recue
 *		63 : tampon de reception sature, non reception ou
 *		     perte de fin d'enregistrement ou fin de fichier
 *		93 : fin de fichier recue
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
  WORD cpdu;
  TRACE_BIN trace;

	/* Verifie que le numero logique est possible */
	if (ComId > MAXNLOG)
		return(50);

	/* Controle la validite du numero logique */
	if (tnlog[ComId].attach == FALSE)
		return(50);

	/* Pour la trace binaire */

	if ( tnlog[ComId].trace_handle != (FILE *) 0 )
	{
		time(&trace.date);
		trace.function = 6;
		trace.nlog = ComId;
		trace.maxlength = 0xffff; /* unknown value */
		trace.uselength = 0;
	}

	/* Controle l'etat de la voie */
	if (tnlog[ComId].reserve == FALSE)
	{
		trace.retcode = 42;
		write_trace(ComId,trace,0);
		return(42);
	}

	/* Controle de la connexion */
	if (tnlog[ComId].connex == FALSE)
	{
		trace.retcode = 83;
		write_trace(ComId,trace,0);
		return(83);
	}

	/* Controle de la longueur du tampon a recevoir */
	len = rt_arg.l[1];
	if (rt_arg.c > 2)
	{
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
			default :
				trace.maxlength = ltampon;
				trace.retcode = 85;
				write_trace(ComId,trace,tampon);
				return(85);
			}

		/* Controle du parametre longueur */
		if (len < ltampon)
		{
			trace.maxlength = ltampon;
			trace.retcode = 85;
			write_trace(ComId,trace,tampon);
			return(85);
		}
		len = ltampon;
	}

	trace.maxlength = len;

	if (len < 3)
	{
		trace.retcode = 85;
		write_trace(ComId,trace,tampon);
		return(85);
	}

	/* Mise a blanc du tampon de reception */
	for (i = 2 ; i < len ; i++)
	{
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

	while (!end)
	{
		cpdu = Aread(ComId,&car);
		/* Diagnostic de l'erreur */
		if (cpdu != 0)
		{
			err = cpdu;
			end = TRUE;
			break;
		}

		/* Post-traitement des caracteres */
		if (tnlog[ComId].transp == FALSE)
		{
			/* Caractere fin d'enregistrement */
			if (car == tnlog[ComId].finenr)
			{
				end = TRUE;
				break;
			}
			/* Caractere fin de fichier */
			if (car == tnlog[ComId].finfich)
			{
				*(tampon+i) = car;
				err = 93;
				end = TRUE;
				i++;
				break;
			}
			/* Caractere normal */
			*(tampon+i) = car;
			i++;
			if (i >= len)
			{
				/* Tampon sature */
				err = 63;
				end = TRUE;
				break;
			}
		}
		/* Pas de post-traitement des caracteres */
		else
		{
			*(tampon+i) = car;
			i++;
			if (i >= len)
			{
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
	trace.uselength = i;
	trace.retcode = err;
	write_trace(ComId,trace,tampon);

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
  TRACE_BIN trace;

	/* Verifie que le numero logique est possible */
	if (ComId > MAXNLOG)
		return(50);

	/* Controle la validite du numero logique */
	if (tnlog[ComId].attach == FALSE)
		return(50);

	/* Pour la trace binaire */

	if ( tnlog[ComId].trace_handle != (FILE *) 0 )
	{
		time(&trace.date);
		trace.function = 7;
		trace.nlog = ComId;
		trace.maxlength = 0;
		trace.uselength = 0;
	}

	/* Controle l'etat de la voie */
	if (tnlog[ComId].reserve == FALSE)
	{
		trace.retcode = 42;
		write_trace(ComId,trace,0);
		return(42);
	}

	/* Controle de la connexion */
	if (tnlog[ComId].connex == FALSE)
	{
		trace.retcode = 83;
		write_trace(ComId,trace,0);
		return(83);
	}

	/* Envoi d'un break sur la ligne pendant une
	 * duree comprise en 0.25 et 0.5 sec
	 */

#ifdef TYPE_POSIX
	(void) tcsendbreak(tnlog[ComId].handle,0);
#else
	(void) ioctl(tnlog[ComId].handle,TCSBRK,0);
#endif


	trace.retcode = 0;
	write_trace(ComId,trace,0);
	return(0);
}

/* -----------------------------------------------------------------------
 *
 * Fonction de configuration du tampon d'anticipation.
 *
 *	E/ numero logique de la voie
 *	   taille du tampon d'anticipation
 *	S/ compte-rendu :
 *		 0 : OK
 *		42 : fichier ferme
 *		50 : numero logique incorrect
 *		84 : voie deja connectee
 *		85 : longueur tampon incorrecte
 *
 * -----------------------------------------------------------------------
 */
static WORD FAR ttybuffer(ComId,ltampon)
WORD ComId;
WORD ltampon;
{
  TRACE_BIN trace;

	/* Verifie que le numero logique est possible */
	if (ComId > MAXNLOG)
		return(50);

	/* Controle la validite du numero logique */
	if (tnlog[ComId].attach == FALSE)
		return(50);

	/* Pour la trace binaire */

	if ( tnlog[ComId].trace_handle != (FILE *) 0 )
	{
		time(&trace.date);
		trace.function = 7;
		trace.nlog = ComId;
		trace.maxlength = ltampon;	/* parameter value */
		trace.uselength = 0;
	}

	/* Controle l'etat de la voie */
	if (tnlog[ComId].reserve == FALSE)
	{
		trace.retcode = 42;
		write_trace(ComId,trace,0);
		return(42);
	}

	/* Controle de la deconnexion */
	if (tnlog[ComId].connex == TRUE)
	{
		trace.retcode = 84;
		write_trace(ComId,trace,0);
		return(84);
	}

	/* Controle de la longueur demandee du tampon */
	if ((ltampon > MAXTAMPON) || (ltampon < 80))
	{
		trace.retcode = 85;
		write_trace(ComId,trace,0);
		return(85);
	}

	trace.retcode = 0;
	write_trace(ComId,trace,0);
	return(0);
}

/* ------------------------------------------------------------------
 * ------------------------------------------------------------------
 *	FONCTIONS INTERNES 
 * ------------------------------------------------------------------
 * ------------------------------------------------------------------
 */

/* -----------------------------------------------------------------------
 *
 * initvoie : Initialisation de la voie serie.
 *
 *	E/ ptr sur la structure decrivant la voie serie
 *	S/ compte-rendu :
 *		 0 : OK
#ifdef TYPE_POSIX
 *		85 : vitesse non supportee par le driver du device
#endif
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
	char *	eptr;
#ifdef TYPE_POSIX
  struct termios param;
#else
  struct termio param;
#endif

	/* Recupere les parametres actuels */

#ifdef TYPE_POSIX
	if (tcgetattr(voie->handle,&param) != 0)
#else
	if (ioctl(voie->handle,TCGETA,&param) != 0)
#endif
		return(86);

	/* Mise a jour vitesse */
	/* ------------------- */

#ifdef TYPE_POSIX
	if (cfsetispeed(&param,voie->vitesse) !=0 ) /* vitesse input */
		return(85);
	if (cfsetospeed(&param,voie->vitesse) !=0 ) /* vitesse output */
		return(85);
#else
	param.c_cflag = voie->vitesse;		/* vitesse */
#endif

	/* ------------------------- */
	/* Mise a jour control modes */
	/* ------------------------- */
	/* --------------------------------------------------------------- */
	/* IJM : 09/01/2007						   */
	/* Modification for LACTALIS : Drop the RTSCTS otherwise it sticks */
	/* --------------------------------------------------------------- */
	if (((eptr = getenv("KEEP_RTS_CTS")) != (char *) 0) && ( *eptr == "1" )) {
		/* do it the old way */
		param.c_cflag &= ~CLOCAL;		/* efface le mode */	
		}
	if ( CRTSCTS ) {
		/* reset this signal if exists */
		param.c_cflag &= ~(CLOCAL | CRTSCTS);	/* efface le mode */
		}
	else	{
		/* otherwise just drop this one */
		param.c_cflag &= ~CLOCAL;		/* efface le mode */
		}
	/* --------------------------------------------------------------- */
	param.c_cflag |= (voie->modem|CREAD);	/* CLOCAL selon mode connexion */
	param.c_cflag &= ~CSIZE;		/* efface nombre de bits */
	param.c_cflag |= voie->nbits;		/* nombre de bits */
	param.c_cflag &= ~CSTOPB;		/* efface nombre de stop */
	param.c_cflag |= voie->nstops;		/* nombre de bits de STOP */
	param.c_cflag &= ~PARENB;		/* efface parite */
	param.c_cflag |= voie->oparite ;	/* declare parite */
	param.c_cflag &= ~PARODD;		/* efface parite */
	param.c_cflag |= voie->typeparite;	/* declare parite impaire */
	param.c_cflag |= HUPCL;			/* force deconnexion sur close */

	/* Mise a jour local modes */
	/* ----------------------- */

	/*	pas d'echo				*/
	/*	pas d'echo du caractere d'effacement	*/
	/*	pas d'echo de kill			*/
	/*	pas d'echo de NL			*/
	/*	entree en mode direct			*/
	/*	pas de traitement en entree		*/
	/*	pas de signal SIGHUP et SIGINT		*/
	/*	vider apres kill ou interruption	*/
	/*	ignorer les backgrounds			*/

	param.c_lflag &= ~(ECHO|ECHOE|ECHOK|ECHONL|ICANON|IEXTEN|ISIG|NOFLSH|TOSTOP);

	/* Mise a jour input modes */
	/* ----------------------- */

	/* pas d'interruption sur break */
	/* pas de transformation CR en NL */
	/* ne pas ignorer le break */
	/* ne pas ignorer CR */
	/* ne pas ignorer les caracteres avec erreur de parite */
	/* pas de transformation NL en CR */
	/* pas de strip des caracteres */
	/* pas de tranformation en minuscules */

	param.c_iflag &= ~(BRKINT|ICRNL|IGNBRK|IGNCR|IGNPAR|INLCR|ISTRIP|IUCLC);
	param.c_iflag &= ~INPCK;	/* efface controle parite */
	param.c_iflag |= voie->iparite;	/* ajoute type controle parite */
	param.c_iflag |= PARMRK;	/* coder FF 00 xx les erreurs de parite */
	param.c_iflag &= ~( IXON | IXOFF | IXANY );

	/* Mise a jour output modes */
	/* ------------------------ */

	param.c_oflag = param.c_oflag & ~OPOST;	/* pas de traitement en sortie */

	/* Mise a jour de la table des caracteres speciaux */
	/* ----------------------------------------------- */

	param.c_cc[VINTR] = 0xff;		/* inutilise, interrupt character */
	param.c_cc[VEOF] = 0xff;		/* inutilise */
	param.c_cc[VQUIT] = 0xff;		/* inutilise, quit character */
#ifdef TYPE_POSIX
	param.c_cc[VSUSP] = 0xff;		/* inutilise */
	param.c_cc[VSTART] = 0xff;		/* inutilise, valeur XON */
	param.c_cc[VSTOP] = 0xff;		/* inutilise, valeur XOFF */
#endif
	param.c_cc[VMIN] = 0;			/* caractere a caractere (a la place de EOF)*/
	param.c_cc[VTIME] = 1;			/* time-out de reception minimal (a la place de EOL) */

	/* Modifie les parametres de la voie serie */

#ifdef TYPE_POSIX
	if (tcflush(voie->handle,TCIOFLUSH) != 0)	/* 03/01/2005 */
		return(86);
	if (tcsetattr(voie->handle,TCSANOW,&param) != 0)
		return(86);
#else
	if (ioctl(voie->handle,TCSETAW,&param) != 0)
		return(86);
#endif

	return(0);
}


/* -----------------------------------------------------------------------
 *
 * Aread : Fonction de lecture d'un caractere sur la voie serie
 *         avec interpretation des sequences break et erreur de parite
 *
 *	E/ numero logique
 *	   pointeur sur le caractere a lire
 *	S/ compte-rendu :
 *		 0 : OK
 *		89 : break ou erreur de framing
 *		91 : time-out expire en lecture
 *		99 : erreur de parite en reception
 *
 * -----------------------------------------------------------------------
 */
static WORD Aread(ComId,car)
WORD ComId;
BYTE PTR car;
{
WORD cpdu;
WORD err;
WORD i;

	/* Principe de l'interpretation :
	 *	- un caractere normalement recu est lu tel quel
	 *	- le caractere FF est lu comme la sequence FF FF
	 *	- une erreur de parite est lue comme la sequence FF 00 xx
	 *	- un break est lu comme la sequence FF 00 00
	 */

	cpdu = LLread(ComId,car);

	/* Gestion du mode transparent vis a vis du driver de device */

	if ( (tnlog[ComId].bdattymode & 0x8000) != 0 )
	{
		return( cpdu );
	}

	/*	Translations :				*/
	/*		xx : character			*/
	/*		FF FF : character FF		*/
	/*		FF 00 00 : break, error 89	*/
	/*		FF 00 xx : parity, error 99	*/
	/*		FF xx : inconnu, erreur 89	*/

	if (cpdu == 0)
	{
		if (*car == 0xff)
		{
			cpdu = LLread(ComId,car); /* Read char after first FF */
			if (cpdu == 0)
			{
				switch (*car)
				{
					case 0xff :
						break;  /* *car<-0xff */
					case 0 :
						cpdu = LLread(ComId,car); /* Read char after FF 00 */
						if (cpdu == 0)
						{
							if (*car == 0)
							{
								cpdu = 89; /* FF 00 00 */
							}
							else
							{
								if (tnlog[ComId].iparite == INPCK)
								{
									cpdu = 99; /* FF 00 xx */
								}
								else
								{
									cpdu = 89; /* FF 00 xx */
								}
							}
						}
						break;
					default :
					/* C'est la merde car ce n'est pas FF ou 00 */
						cpdu = 89;
						break;
				}
			}
		}
	}

	/* Traitement des erreurs :
	 * lire tous les caracteres en attente pour purger le buffer
	 * du controleur physique, ce qui evite a l'application d'avoir
	 * plusieurs fois de suite la meme erreur
	 */

	if ( ( cpdu != 0 ) && ( cpdu != 91 ) )
	{
		i = 4096 ;	/* nombre maximum de la purge */
		while (i--)
		{
			err = Xread(tnlog[ComId].handle,car,1);
			if ( err != 1 ) break ;
		}
	}

	return( cpdu );
}

/* -----------------------------------------------------------------------
 *
 * LLread : Fonction de lecture d'un caractere brut
 *
 *	E/ numero logique
 *	   pointeur sur le caractere a lire
 *	S/ compte-rendu :
 *		 0 : OK
 *		89 : detection d'un break
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

#ifdef	WITH_SELECT
  fd_set readfs;
  struct timeval tv;

	FD_ZERO(&readfs);
	FD_SET(tnlog[ComId].handle,&readfs);
	tv.tv_sec = tnlog[ComId].timeout / 10;
	tv.tv_usec = 0;
	if ( tnlog[ComId].timeout > 10 )
	{
		tv.tv_usec = ( tnlog[ComId].timeout - (tv.tv_sec*10) ) * 10000;
	}
	err = select(tnlog[ComId].handle+1,&readfs,NULL,NULL,&tv);
	if ( err )
	{
		err = Xread(tnlog[ComId].handle,car,1);
		if ( err == 1 )		
		{
			/* Un caractere a ete lu */
			return(0);
		}
		else
		{
			return(89);
		}
	}
	else
	{
		return(91);
	}

#else	/* WITH_SELECT */

	/* Il n'y a pas de gestion de tampon d'anticipation,
	 * la lecture se fait directement sur la voie serie.
	 */
	end = FALSE;
	echec = 0;	/* erreur 91 quand echec = tnlog[ComId].timeout */

	while (end == FALSE)
	{
		err = Xread(tnlog[ComId].handle,car,1);
		if (err == 1)
		{
			/* Un caractere a ete lu */
			return(0);
		}
		else
		{
			/* Aucun caractere n'a ete lu :
			 *	- soit un signal a interrompu la lecture
			 *	- soit il s'agit d'un time-out
			 */
			/* Ajout chris */
			if ( err != 0 )	/* Peut etre "-1" */
			{
				err = 89;
			}
			if ( err == 0 )
			{
				echec++;
				if (echec >= tnlog[ComId].timeout)
				{
					err = 91;
				}
			}
			if ( err != 0 ) end = TRUE;
		}
	}
	return(err);

#endif	/* WITH_SELECT */

}

/* -----------------------------------------------------------------------
 *
 * exclusif : verifier si le device est utilise plus d'une fois
 *
 * Principe : utiliser "fuser -v /dev/ttyS.. | wc -w > /tmp/BdaTtyExPID"
 *            et verifier que le resultat est 5.
 *
 * appel : nom du device
 * retour : 1 si nous sommes le seul utilisateur ou 2 si plusieurs
 *         -1 pas assez de droits pour executer la commande fuser ....
 *            ou probleme d'acces au fichier temporaire
 *
 * -----------------------------------------------------------------------
 */

static SWORD exclusif(device)
BYTE FAR PTR device;
{
  char tmpfile[64];
  char buffer[129];	/* buffer de 128 caracteres (+1 de marge) */
  FILE * handle;
  WORD err;
  WORD lg;
  WORD i;
  int	sigchldhandler;

	sprintf(tmpfile,"/tmp/BdaTtyEx%d",getpid());
	sprintf(buffer,"/sbin/fuser %s | wc -w > %s",device,tmpfile);

	sigchldhandler = signal(SIGCHLD,SIG_DFL);
	err = system(buffer);			/* creation */
	(void) signal(SIGCHLD,sigchldhandler);

	if ( err  != 0 ) return(-1);

	/* resultat de fuser de la forme :
	   "/dev/ttyS0:  Pid_Abal Pid_Sh Pid_Fuser Pid_Wc"
	 */

	handle = fopen(tmpfile,"r");		/* ouverture */
	if ( handle == (FILE *) 0 ) return (-1);
	lg = fread(buffer,1,128,handle);	/* lecture */
	fclose(handle);				/* fermeture */
	unlink(tmpfile);			/* suppression */
	if ( lg < 1 ) return(-1);		/* lecture insuffisante */

	/* eliminer les espaces devant le nombre de mots */

	i = 0;
	while( 1 )
	{
		if ( buffer[i] != ' ' ) break ;
		if (i++ >= lg) return(-1);
	}

	/* Verifier qu'il y 5 mots pour un seul utilisateur */

	if ( (buffer[i] == '5') && (buffer[i+1] == 0x0a) )
	{
		return(1);
	}
	else
	{
		return(2);
	}
}


/* -----------------------------------------------------------------------
 *
 * dolock : creation du fichier verrou /var/lock/LCK..device
 *
 * -----------------------------------------------------------------------
 */
static WORD dolock(ttymode,device)
WORD ttymode;
BYTE FAR PTR device;
{
  BYTE FAR PTR ptr1;
  BYTE FAR PTR ptr2;
  FILE * file_lock;
  char buffer[128];
  WORD i=1;

	if ( (ttymode & 0x0002) != 0 )
	{
		ptr1 = device;
		if ( (ptr2 = strrchr(ptr1,'/')) != (char *) 0 )
		{
			ptr1 = ptr2 + 1;
		}
		sprintf(buffer,"%s/LCK..%s",LOCK_DIR,ptr1);
		unlink(buffer);
		i = 0;
		file_lock=fopen(buffer,"w");
		if ( file_lock != (FILE *) 0 )
		{
			sprintf(buffer,"%10d\n",getpid());
			i = fwrite(buffer,1,11,file_lock);
			fclose(file_lock);
		}
		if ( i == 11 ) i = 1;
	}

	return(i);
}


/* -----------------------------------------------------------------------
 *
 * unlock : suppression du fichier verrou /var/lock/LCK..device
 *
 * -----------------------------------------------------------------------
 */
static VOID unlock(ttymode,device)
WORD ttymode;
BYTE FAR PTR device;
{
  BYTE FAR PTR ptr1;
  BYTE FAR PTR ptr2;
  char buffer[128];

	if ( (ttymode & 0x0002) != 0 )
	{
		ptr1 = device;
		if ( (ptr2 = strrchr(ptr1,'/')) != (char *) 0 )
		{
			ptr1 = ptr2 + 1;
		}
		sprintf(buffer,"%s/LCK..%s",LOCK_DIR,ptr1);
		unlink(buffer);
	}
	return;
}


/* -----------------------------------------------------------------------
 *
 * write_trace_handle and write_trace : Ecriture d'un point de trace
 *                                      dans le fichier de trace binaire
 *
 * -----------------------------------------------------------------------
 */

static write_trace_handle(handle,point,buffer)
FILE *handle;
TRACE_BIN point;
BYTE FAR PTR buffer;
{
	if ( handle != ((FILE*) 0) )
	{
		fwrite((void *)&point,1,sizeof(TRACE_BIN),handle);
		if ( point.uselength != 0 )
		{
			fwrite(buffer,1,point.uselength,handle);
		}
		fflush(handle);
	}

	return;
}

static write_trace(ComId,point,buffer)
WORD ComId;
TRACE_BIN point;
BYTE FAR PTR buffer;
{
	if ( tnlog[ComId].trace_handle != (FILE *) 0 )
	{
		write_trace_handle(tnlog[ComId].trace_handle,point,buffer);
	}

	return;
}

/* -----------------------------------------------------------------------
 *
 * cloture : Fermeture de la bibliotheque.
 *
 *
 *	Cette fonction a pour objet de deconnecter
 *	toutes les voies utilisees, et de fermer tous les
 *	eventuels fichiers de trace ouverts (ttyclose).
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
 * banniere : Identification de la bibliotheque.
 *
 * -----------------------------------------------------------------------
 */
static VOID FAR banniere()
{
#ifdef ABAL2
	(void) printf("\r\ntty.so : Abal2, bibliotheque  TTY  pour Use IT et  UNIX");
	(void) printf("\r\ntty.so : Abal2, Dynamic Library TTY for Use IT and UNIX");
#else
#  ifdef ABAL3
	(void) printf("\r\ntty32.so : Abal3, bibliotheque  TTY  pour Use IT et  UNIX");
	(void) printf("\r\ntty32.so : Abal3, Dynamic Library TTY for Use IT and UNIX");
#  else
	(void) printf("\r\nAbal : Bibliotheque  TTY  pour Use IT et  UNIX");
	(void) printf("\r\nAbal : Dynamic Library TTY for Use IT and UNIX");
#  endif
#endif
	(void) printf("\r\nVersion %s",VERSION);
	(void) printf("\r\nCopyright (c) 1991, 2005 Amenesik / Sologic Technologies\r\n");
}

/* -----------------------------------------------------------------------
 *
 * bcd2word : Fonction de conversion de BCD vers entier.
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
#  define fonconv(x) ((x < 10) ? (x+'0') : (x-10+'A'))
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
 * VerifProtect : Verification de la protection anti-copie pirate.
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




