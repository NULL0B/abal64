
/* -------------------------------------------------------------------- */
/*									*/
/*	Projet A.B.A.L.	  -   Copyright Amenesik / Sologic s.a. (c) 1988,1991	*/
/*	---------------	      -------------------------------------	*/
/*									*/
/*		 Gestion des fichiers sequentiels indexes		*/
/*			via C-Isam sous Unix				*/
/*									*/
/*			(Longueur Variable)				*/
/*									*/
/*		      Revision 1.1 du 16/09/1992			*/
/*									*/
/*		File	:	EXSILV.C				*/
/*									*/
/* -------------------------------------------------------------------- */

/*	Modified 21/09/1988	IJM	si_rename : now transactional	*/
/*	Modified 21/09/1988	IJM	fichierinf: now transactional	*/
/*	Modified 21/09/1988	IJM	si_open	  : now transactional	*/
/*	Modified 21/09/1988	IJM	si_create : now transactional	*/
/*	Modified 21/09/1988	IJM	si_unlink : semi transactional  */
/*	Modified 22/09/1988	IJM	Error 58 if SILV not defined	*/
/*	Modified 05/10/1988	IJM	isrename Err 0 ==> EEXIST	*/
/*	Modified 05/10/1988	IJM	Reorganisation of si_open ....	*/
/*					exsi_open(fnom,ex,cop,wr)	*/
/*					  si_open(fnom,ex,cop)  	*/
/*					llsi_open(args) common si_open	*/
/*									*/
/*	exsi_open allows O_RDONLY if not ASSIGN,WR !!!!			*/
/*	  si_open always O_RDWR	(for Multicritere Site Pilote !!!)	*/
/*									*/
/*	Modified 05/10/1988	IJM	Si_Create Nfic.idx Chmod 0666	*/
/*	Modified 06/10/1988	IJM	Si_Create : RK problems		*/
/*	Modified 06/10/1988	IJM	Si_Search : Search.L Error	*/
/*	Modified 06/10/1988	IJM	zcwork	  : No more getc() !!	*/
/*	Modified 07/11/1988	IJM	si_insert , si_search , up_down	*/
/*					si_modif to use STLONG LDLONG	*/
/*	Modified 07/11/1988	IJM	si_modif modified to reuse when */
/*					possible the old data space LV	*/
/*	Modified 26/09/1989	IJM	Correction of transactional 	*/
/*					opening error handling when	*/
/*					Fichier-I does not exist in	*/
/*					llsi_open since iserrno == 0	*/
/*					now sets iserrno to errno	*/
/*					if fichier_inf fails		*/
/*	Modified 19/09/1990	IJM	Now uses ACCESS to declare the	*/
/*					usage of SI file (.idx lock)	*/
/*	Modified 10/10/1990	IJM	Removal of calls to excl_chck()	*/
/*					Since access provides exclusive	*/
/*					access to files.		*/
/*					Capture and handle ENFILE and	*/
/*					EMFILE to allow clean up after	*/
/*					CISAM isbuild failure		*/
/*					Definition of SILV no longer is */
/*					needed since all versions offer	*/ 
/*					Variable length data files.	*/
/*	Modified 06/11/1990	IJM	Now affects value to System err */
/*					in traitfilerror()		*/
/*	Modified 18/01/1990	IJM	Correction in up_down to ensue	*/
/*					error detected when up or down	*/
/*					on a file with no records	*/
/*	Modified 03/05/1991	IJM	Corrections required for the	*/
/*					new C_ISAM R_ISAM_PLUS which	*/
/*					now uses 3 files idx dat and	*/
/*					.rcv . To activate this method	*/
/*					define the variable R_ISAM_PLUS	*/
/*	Modified 05/03/1992	IJM	Correction to ensure that the   */
/*					correct calls to access are     */
/*					performed by si_matb().	        */
/*      Modified 11/03/1992	IJM	Correction required for BULL    */
/*					C_ISAM Version 4.10UC1 04.01.01 */
/*					DOWN or UP which encounters an  */
/*					End of or Start of file error   */
/*					must inhibit further attempts   */
/*					to screw up the c_isam library  */
/*					and must, when required to get  */
/*					out of the unfortunate state by */
/*					the reverse action, seek the    */
/*					relevant FIRST or LAST Record.  */
/*					These modifications may be      */
/*					activated by the definition of  */
/*					C_ISAM_410 .			*/
/*	Modified 08/04/1992	IJM	CHMOD now performed on the .dat */
/*	Modified 19/06/1992	IJM	CHMOD now performed on the -I   */
/*		 06/07/1992	CR	Reprise dans la 1.4b de la	*/
/*					fonction mcbd_si_modif		*/
/*		13/11/1992	IJM	Down and Up which encounter	*/
/*					Error 74 now advance to next	*/
/*					record before returning ERR 74	*/
/* -------------------------------------------------------------------- */

#include <stdio.h>
#ifdef AIX_VERS
#ifndef UNIXWARE
#endif /* AIX_VERS */
#include <string.h>
#ifdef AIX_VERS
#endif
#endif /* AIX_VERS */
// #include <memory.h>
#include <isam.h> 
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "exsilv.h"

/*
 *	L E N U S E (  cp , lenmax  )
 *	-----------------------------
 */

unsigned short int LenUse(cp,lenmax)
char * cp;
unsigned short int lenmax;
{
register unsigned short int x,y;
	y = 0; x = 1;
	while ( x <= lenmax ) {
		if ( *(cp++) != ' ' ){ y = x; }
		x++;
		} 
	return(y);
}

/*
 *	R A Z _ E N T R Y ( nlsi )
 *	--------------------------
 *	Reset a table entry to zero and unused
 *
 */
	
void	raz_entry( nlsi )
int	nlsi;
{

	tabsi[nlsi].used = FALSE;	/* entree utilisee ? 		*/
	tabsi[nlsi].ex = FALSE;		/* exclusif oui/non 		*/
	tabsi[nlsi].modisam = 0;	/* ISINOUT, ...			*/	
	tabsi[nlsi].type = 0;		/* K,LK,RK			*/
	tabsi[nlsi].blocked = FALSE;	/* TRUE si dernier enr. bloque	*/
	tabsi[nlsi].fildes = -1;	/* Numero interne fildes isam	*/
	tabsi[nlsi].lgcle = 0;		/* Longueur des cles		*/
	tabsi[nlsi].lgdonnees = 0;	/* Longueur des donnees		*/
	tabsi[nlsi].lgtotale = 0;	/* Longueur enregistrement isam */
	tabsi[nlsi].flag_err = FALSE;	/* flag DOWN precedent a echoue */
	tabsi[nlsi].flag_posit = FALSE; /* Sem du posit sur 2eme Index	*/
	tabsi[nlsi].rec = (char * ) 0;	/* adresse zone tampon		*/
	tabsi[nlsi].lvfildes = -1;	/* numero interne fichier -LV 	*/
	tabsi[nlsi].fnomptr=(char *) 0;	/* Nom du fichier pour 44 Check */

	return;

}

/*----------------------------------------------------------------------------
 *  SI_INIT	: Initialisation de l'acces au fichiers
 *----------------------------------------------------------------------------
 *  Appel	: SI_INIT()
 *--------------------------------------------------------------------------*/

void	si_init()
{
	int  i;

	for (i=0; i<MAX_FILE_ASSIGN; i++)  { raz_entry(i); }
	return;
}

/*----------------------------------------------------------------------------
 *  SI_FIN 	: Fin de l'acces au fichiers
 *----------------------------------------------------------------------------
 *  Appel	: SI_FIN()
 *--------------------------------------------------------------------------*/
void	si_fin()
{
}

void abalstore (adr,val)
/*	affecte une valeur binaire (dependante du processeur),
 *	dans une zone pointee en octets, et suivant la notation
 *	directe qui est utilisee pour les % ABAL.
 */
unsigned char *adr;
unsigned short int val;
{
	unsigned char *p;
	unsigned short int tb;

	p = adr;
	tb = FIRST_BYTE(val); *p++ = (unsigned char) tb;
	tb = SECOND_BYTE(val); *p = (unsigned char) tb;

}

/*
 *	E X C L _ C H C K ( fnom )
 *	--------------------------
 *	Check file name  to see if already open elsewhere
 *
 */

int	excl_chck(nomfic)
char *nomfic;
{
	int ffildes;
	char fnwork[65];

	/* exclusivite demandee */
	/* -------------------- */
	strcpy(fnwork,nomfic); strcat(fnwork,ABAL_CISAM_IDX);
	if ( access(fnwork,0) != 0 ) { errno = 40; return(-1); }
	ffildes = open(fnwork,O_RDWR,0);
	if ( ffildes < SUCCESS) { errno = 44; return(-1); }
	if ( lockf(ffildes,F_TEST,0) != 0 ) {
		(void) close(ffildes); errno = 44; return(-1);
		}
	(void) close(ffildes);
	return(0);

}

/*
 *	S I _ R E S E R V A T I O N 	and	S I _ L I B E R A T I O N
 *	-----------------------------------------------------------------
 *	Utilisation d'ACCESS pour la declaration d'usage des fichier SI
 *	(a partir de ABAL 1.2e)
 */
 
int	si_reservation(nomfic,mode)
char * 		nomfic;
unsigned int 	mode;
{
	char	fnwork[65];

	/* Create .IDX filename */
	/* -------------------- */
	strcpy(fnwork,nomfic); strcat(fnwork,ABAL_CISAM_IDX);
	
	/* Perform ACCESS interfacing */
	/* -------------------------- */
	return ( Access(fnwork,0,mode) ) ;


}

int	si_access_exclusive( nomfic )
char	* nomfic;
{
	char	fnwork[65];

	/* Create .IDX filename */
	/* -------------------- */
	strcpy(fnwork,nomfic); strcat(fnwork,ABAL_CISAM_IDX);

	return( matb( fnwork, 1, 0, 1 ) );

}

int	si_access_shared( nomfic )
char	* nomfic;
{
	char	fnwork[65];

	/* Create .IDX filename */
	/* -------------------- */
	strcpy(fnwork,nomfic); strcat(fnwork,ABAL_CISAM_IDX);

	return( matb( fnwork, 0, 0, 1 ) );

}


int	si_liberation(nomfic)
char	* nomfic;
{
	char	fnwork[65];

	/* Create .IDX filename */
	/* -------------------- */
	strcpy(fnwork,nomfic); strcat(fnwork,ABAL_CISAM_IDX);

	/* Request ACCESS liberation */
	/* ------------------------- */
	liberlox( fnwork );

	return;
}


/*----------------------------------------------------------------------------
 *   SI_OPEN	: Ouverture d'un fichier
 *-----------------------------------------------------------------------------
 *   Appel  	: nlsi = SI_OPEN(nomfic,ex,cop)
 *   Entree 	: char *nomfic : nom du fichier
 *		  int  ex =  0 : ouverture partageable, 1 : exclusif
 *		  int  cop = 1 : exploitation en mode copie, 0 : mode securite
 *   Sortie 	: int nlsi : numero logique attribue au fichier
 *		             ou erreur si -1, la variable globale _errno
 *			     etant alors mise a jour avec le code d'erreur
 *
 *---------------------------------------------------------------------------*/
/*	REMARQUE	*/
/*	--------	*/
/*	exsi_open : Offers RD_ONLY or RD_WR opening mode
 *	  si_open : Offers only RD_WR Mode
 *	llsi_open : performs the actual open function for both headers
 */

short int llsi_open();

short int exsi_open(nomfic,ex,cop,wr)
char	*nomfic;
int	ex,cop,wr;
{
	short int nlsi;

	/*	Chercher une entree libre	*/
	/*	-------------------------	*/
	if ( (nlsi = getentry()) == -1 )	{ errno = 51; return ( -1 ); }

	/*	Establish Mode RD or RDWR	*/
	/*	-------------------------	*/
	if ( wr == 1 )	{ tabsi[nlsi].modisam = ISINOUT;  }
	else		{ tabsi[nlsi].modisam = ISINPUT; }

	/*	Perform LowLevel Open		*/
	/*	---------------------		*/
	return ( llsi_open(nomfic,ex,cop,nlsi) );
}

short int si_open(nomfic,ex,cop)
char *nomfic;
int  ex, cop;
{
	short int nlsi;		/* File handle allocated 	*/

	/*	chercher une entree libre dans tabsi	*/
	/* 	------------------------------------ 	*/
	if ( (nlsi = getentry()) == -1 ) 	{ errno = 51; return (-1); }

	/* toujours ouvert en lecture/ecriture */
	/* ----------------------------------- */
	tabsi[nlsi].modisam = ISINOUT;

	/*	Perform LowLevel OPEN		*/
	/*	---------------------		*/
	return( llsi_open(nomfic,ex,cop,nlsi) );
}

short int llsi_open(nomfic,ex,cop,nlsi)
char	*nomfic;
int	ex,cop;
short int nlsi;
{
	int ffildes;
	int lerr;

	/* Attempt Reservation of Index File */
	/* --------------------------------- */
	if ( si_reservation(nomfic,ex) !=  SUCCESS ) {
		if (errno != 44) traitfilerror(-1,errno);
		return(-1);
		}

	/* Etablir mode d'ouverture */
	/* ------------------------ */ 
	if (ex) {
/* -------------------------------------------------------------------- */
/*		Removed due to usage of ACCESS				*/
/*		------------------------------				*/
/*		if ( excl_chck(nomfic) != 0 ) { return(-1); }		*/
/* -------------------------------------------------------------------- */
		tabsi[nlsi].modisam += ISEXCLLOCK;
		}
	else 	{
		/* rester en partageable */
		/* --------------------- */
		tabsi[nlsi].modisam += ISMANULOCK;
		}

	if ( (ffildes = isopen(nomfic,tabsi[nlsi].modisam)) < SUCCESS) {
		(void)  si_liberation(nomfic);	
		traitfilerror(nlsi,iserrno); 
		return(-1);
		}
	if (isindexinfo(ffildes,&info,0) == SUCCESS) {

		if (isindexinfo(ffildes,&keybal,1) == SUCCESS) {

			/* init entree dans la table tabsi */
			/* ------------------------------- */
			tabsi[nlsi].fildes=ffildes;
			tabsi[nlsi].ex = ex;
			tabsi[nlsi].lgcle=keybal.k_part[0].kp_leng;
			tabsi[nlsi].lgtotale=info.di_recsize;
			tabsi[nlsi].lgdonnees=tabsi[nlsi].lgtotale - tabsi[nlsi].lgcle - 1;

			tabsi[nlsi].blocked=FALSE;
			tabsi[nlsi].flag_err=FALSE;

		 	/* pas de posit sur un autre index */
			/* ------------------------------- */
			tabsi[nlsi].flag_posit = FALSE ;

			if ((tabsi[nlsi].rec = malloc(tabsi[nlsi].lgtotale)) != (char *) 0) {
				if (fichier_inf(nomfic,nlsi,2) == SUCCESS) {
					/* reserver l'entree dans tabsi */
					/* ---------------------------- */
					tabsi[nlsi].used = TRUE;
					/* et se remettre au debut du fichier */
					/* ---------------------------------- */
					deblock(nlsi);
					tabsi[nlsi].flag_err = FALSE;
					tabsi[nlsi].blocked  = FALSE;
					isread (tabsi[nlsi].fildes,tabsi[nlsi].rec,ISFIRST);
#ifdef	C_ISAM_410
					tabsi[nlsi].flag_err = TRUE;
#else
#ifdef	R_ISAM_PLUS
					tabsi[nlsi].flag_err = TRUE;
#else
					isread (tabsi[nlsi].fildes,tabsi[nlsi].rec,ISPREV);
#endif
#endif
					/* +1 pour eviter numero 0 au retour */
					/* --------------------------------- */
					if ( (tabsi[nlsi].fnomptr = (char *) malloc( strlen( nomfic ) + 2 )) != (char *) 0 ) {
						strcpy(tabsi[nlsi].fnomptr,nomfic); 
						return (nlsi+1);
						}
					else	{ iserrno = 38; }
					}
				else	{
					iserrno = errno;
					}
				/* Liberate memory Here */
				/* -------------------- */
				free(tabsi[nlsi].rec);
				}
			else	{	/* Memory Alloc Fail */
					/* ----------------- */ 
				(void) isclose(ffildes);
				(void)  si_liberation(nomfic);	
				errno = 27; return (-1);
				}
			}	
		}
	/* Close the File to liberate File handles */
	/* --------------------------------------- */
	lerr  = iserrno;
	(void) 	isclose(ffildes);
	(void)  si_liberation(nomfic);	
	traitfilerror(nlsi,lerr);
	return (-1);
}

/*-----------------------------------------------------------------------------
 *   SI_MATB	: Modification des attributs d'ouverture
 *-----------------------------------------------------------------------------
 *   Appel	: err = SI_MATB(nlsi,ex,cop)
 *   Entree	: int nlsi : numero logique attribue au fichier
 *		  int  ex =  0 : demande partageable, 1 : exclusif
 *		  int  cop = 0 : demande mode copie,  1 : mode securite
 *   Sortie 	: int err :  erreur si -1, la variable globale _errno
 *			     etant alors mise a jour avec le code d'erreur
 *
 *---------------------------------------------------------------------------*/
int si_matb(nlsi,ex,cop)
short int nlsi;
int ex,cop;
{
	int locerr;
	int tempmode;	
	int ffildes;

	nlsi--;
	if (verif_nlsi(nlsi) < SUCCESS) { errno = 50; return(-1); }


	/* EXCLUSIVITY mode request (currently SHARED mode) */
	/* ------------------------------------------------ */	
	if (( ex != 0 ) && ( tabsi[nlsi].ex == FALSE )) {
/* -------------------------------------------------------------------- */
/*		Removed due to usage of ACCESS				*/
/*		------------------------------				*/
/* 	if ( excl_chck( tabsi[nlsi].fnomptr ) != 0 ) { return(-1); }	*/
/* -------------------------------------------------------------------- */
		if ((tabsi[nlsi].modisam & (ISINPUT | ISINOUT)) != ISINOUT ) {
			errno = 120; return(-1);
			}
		if (si_access_exclusive(tabsi[nlsi].fnomptr) != 0 ) {
			errno = 44;
			return(-1);
			}
		if (isclose(tabsi[nlsi].fildes) < SUCCESS) {
			si_liberation(tabsi[nlsi].fnomptr);
			traitfilerror(nlsi,iserrno);	return (-1);
			}
		tempmode = tabsi[nlsi].modisam;
		tabsi[nlsi].modisam = ((tabsi[nlsi].modisam & (ISINPUT | ISINOUT)) | ISEXCLLOCK);
		if ( (ffildes = isopen(tabsi[nlsi].fnomptr,tabsi[nlsi].modisam)) < SUCCESS) {
			locerr = iserrno;
			tabsi[nlsi].modisam = tempmode;
			si_access_shared(tabsi[nlsi].fnomptr);
			tabsi[nlsi].fildes = isopen(tabsi[nlsi].fnomptr,tabsi[nlsi].modisam);
			iserrno = locerr;
			traitfilerror(nlsi,iserrno); 
			return(-1);
			}
		tabsi[nlsi].fildes = ffildes;
		tabsi[nlsi].ex     = TRUE;
		}
	else	{
		/* SHARED mode request (Currently EXCLUSIVE mode) */
		/* ---------------------------------------------- */
		if (( ex == 0 ) && ( tabsi[nlsi].ex == TRUE )) {
			si_access_shared(tabsi[nlsi].fnomptr);
			if (isclose(tabsi[nlsi].fildes) < SUCCESS) {
				si_liberation(tabsi[nlsi].fnomptr);
				traitfilerror(nlsi,iserrno);	return (-1);
				}
			tabsi[nlsi].modisam = ((tabsi[nlsi].modisam & (ISINPUT | ISINOUT)) | ISMANULOCK);
			ffildes = isopen(tabsi[nlsi].fnomptr,tabsi[nlsi].modisam);	
			tabsi[nlsi].fildes = ffildes;
			tabsi[nlsi].ex = FALSE;
			}
		}
	deblock(nlsi);
	return(0);

}

int exsi_matb(nlsi,ex,cop)
short int nlsi;
int   ex,cop;
{
	int	lfid;
	nlsi--;
	if (verif_nlsi(nlsi) < SUCCESS)
		return (-1);
	/*
	 *	C_ISAM n'a qu'une fonction equivalente : ISLOCK; Mais
	 *	elle ne bloque les autres qu'en ecriture seulement
	 */
	if ((ex) && !(tabsi[nlsi].ex)) {	/* passer en exclusif */
		lfid = open(tabsi[nlsi].fnomptr,O_RDWR,0);
		if ( lfid < SUCCESS ) {
			errno = 44; return(-1);
			}
		if ( lockf(lfid,F_TEST,0) != 0 ) {
			(void) close(lfid); errno = 44; return(-1);
			}
		(void) close(lfid);
		if (islock(tabsi[nlsi].fildes) < SUCCESS) {
			traitfilerror(nlsi,iserrno); return (-1);
			}
		tabsi[nlsi].ex = FALSE;
	}
	else if (!(ex) && (tabsi[nlsi].ex)) {	/* passer en partageable */
		if (isunlock(tabsi[nlsi].fildes) < SUCCESS) {
		   traitfilerror(nlsi,iserrno); return (-1);
		}
		tabsi[nlsi].ex = TRUE;
	}
	/*
	 *	On force l'option C -copie- dans tous les cas sous UNIX.
	 */
	deblock(nlsi);
	/* Retour OK */
	return (0);
}

 
/*-----------------------------------------------------------------------------
 *   SI_CLOSE	: Fermeture d'un fichier
 *-----------------------------------------------------------------------------
 *   Appel	: err = SI_CLOSE(nlsi)
 *   Entree	: int nlsi : numero logique attribue au fichier
 *   Sortie 	: int err :  erreur si -1, la variable globale _errno
 *			     etant alors mise a jour avec le code d'erreur
 *
 *---------------------------------------------------------------------------*/
int si_close(nlsi)
short int nlsi;
{
	nlsi--;
	if (verif_nlsi(nlsi) < SUCCESS) {
		return (-1);
		}
	if (isclose(tabsi[nlsi].fildes) < SUCCESS) {
		traitfilerror(nlsi,iserrno);	return (-1);
		}
	if (tabsi[nlsi].flag_LV) {
		close(tabsi[nlsi].lvfildes);
		}
	free(tabsi[nlsi].rec);
	si_liberation(tabsi[nlsi].fnomptr);
	free(tabsi[nlsi].fnomptr);
	raz_entry( (int) nlsi );
	return (0);
}
/*-----------------------------------------------------------------------------
* repositionnement dans l'index primaire du fichier		
* appel    	: SI_reposit(nlsi)	
* Entree        : short int sinl  = no logique du fichier
* sortie        : 0 si ok sinon -1 et errno : code d'erreur
*----------------------------------------------------------------------------*/
int  SI_reposit(nlsi )
short int nlsi ;			/* no logique du fichier             */
{
 int lgcle,err ;
 lgcle = tabsi[nlsi].lgtotale - tabsi[nlsi].lgdonnees -1 ; /* lg de la cle    */
	
	keybal.k_flags=ISNODUPS;
	keybal.k_nparts=1;
	keybal.k_part[0].kp_start = 0;
	keybal.k_part[0].kp_leng = lgcle;
	keybal.k_part[0].kp_type = CHARTYPE;
err = isstart(tabsi[nlsi].fildes,&keybal,lgcle,tabsi[nlsi].rec,ISEQUAL);

tabsi[nlsi].flag_posit=FALSE ;
return(0);
}

/*
 *	B u i l d C h c k ( iserrno )
 *	-----------------------------
 *	This function is the first phase of the C-Isam File creation
 *	mess checking routines (see following function for more info)
 *
 */

int	buildchck()
{

	switch ( iserrno ) {
		case EEXIST : errno = 41; return(-1); 
		case EDEADLK:
		case ENOLCK : errno = 134; return(-2);
		case EISDIR :
		case EINVAL : errno = 30; return(-1);
		case ENOSPC : errno = 46; return(-2);
		case ENFILE :
		case EMFILE : errno = 51; return(-2);
		default	    : return(0);
		}
}

/*
 *	I S C B U G ( nomfic )
 *	----------------------
 *	This function is included to provide a clean exit for
 *	si_create when the C-Isam creates a file but cannot
 *	lock it due to insufficient systeme locks.
 *	unfortunatly if C-Isam has not correctly created a file
 *	then it cannot remove it either so we have to resort
 * 	to the messy buisness of a double file UNLINK operation
 *	oh la la c'est dure la vie sous Unix
 */

void	iscbug( nomfic , xerrno )
char * nomfic;
int    xerrno;
{
	char	lwzone[65];

	/*	Destroy the '.idx'	*/
	/*	------------------	*/
	strcpy(lwzone,nomfic); strcat(lwzone,ABAL_CISAM_IDX); unlink(lwzone);

	/*	Destroy the '.dat'	*/
	/*	------------------	*/
	strcpy(lwzone,nomfic); strcat(lwzone,".dat"); unlink(lwzone);

#ifdef	R_ISAM_PLUS
	/*	Destroy the '.rcv'	*/
	/*	------------------	*/
	strcpy(lwzone,nomfic); strcat(lwzone,".rcv"); unlink(lwzone);
#endif

	/*	Establish Error Code	*/
	/*	--------------------	*/
	errno = xerrno; return;
}

/*-----------------------------------------------------------------------------
 *   SI_CREATE	: Creation / ouverture d'un fichier
 *-----------------------------------------------------------------------------
 *   Appel  	: nlsi = SI_CREATE(nomfic,lcles,ldatas,ex,cop,cadrage,lvar)
 *   Entree 	: char *nomfic : nom du fichier
 *		  int lgcles = longueur des cles
 *		  int lgdatas = longueur des donnees, ou pas de donnees si 0,
 *				ou long min de recup si longueur variable.
 *		  int  ex =  0 : ouverture partageable, 1 : exclusif
 *		  int  cop = 1 : exploitation en mode copie, 0 : mode securite
 *		  int  cadrage = 0 : pas de cadrage des cles, 1 : cadrage a 
 *				     gauche, 2 : cadrage a droite
 *		  int  lvar = 0 : longueur fixe, 1 : longueur variable.
 *
 *   Sortie 	: int nlsi : numero logique attribue au fichier
 *		             ou erreur si -1, la variable globale _errno
 *			     etant alors mise a jour avec le code d'erreur
 *
 *---------------------------------------------------------------------------*/
short int si_create(nomfic,lcles,ldatas,ex,cop,cadrage,lvar)
char *nomfic;
int  lcles,ldatas,ex,cop,cadrage,lvar;
{
	short int nlsi;			/* Internal file handle		*/
	int	fildes;			/* Systeme file handle		*/
	int	lgtotale;		/* C-Isam Total record length	*/
	int	lerr;			/* Local error storage		*/
	char	fnwork[65];		/* File name .idx buffer	*/

	/*	chercher une entree libre dans tabsi	*/
	/*	------------------------------------	*/
	if ((nlsi = getentry()) == -1)	{ errno = 51; return (-1); }

	/*	controle longueur des cles	*/
	/* 	--------------------------	*/
	if (lcles < 2) 			{ errno = 70; return (-1); }
	if (lcles > 120) 		{ errno = 71; return (-1); }

	/* Initialise Creation Structure */
	/* ----------------------------- */
	keybal.k_flags=ISNODUPS;
	keybal.k_nparts=1;
	keybal.k_part[0].kp_start = 0;
	keybal.k_part[0].kp_leng = lcles;
	keybal.k_part[0].kp_type = CHARTYPE;

	/*  toujours en lecture / ecriture  */
	/*  ------------------------------  */
	tabsi[nlsi].modisam = ISINOUT;

	if ( si_reservation(nomfic,ex) == 0 ) {
		(void) si_liberation(nomfic);
		errno = 41;
		return(-1);
		}

	/* Establish Opening Mode */
	/* ---------------------- */
	if (ex) { tabsi[nlsi].modisam |= ISEXCLLOCK; }
	else	{ tabsi[nlsi].modisam |= ISMANULOCK; }

	tabsi[nlsi].ex = ex;

	/*	creation par C-Isam	*/
	/* 	-------------------	*/
	if (lvar == 1) {
		/* Total length = DPTR + CLE */
		/* ------------------------- */
		lgtotale = lcles + 7;
		tabsi[nlsi].flag_LV = TRUE;
		fildes=isbuild(nomfic,lcles+7,&keybal,tabsi[nlsi].modisam);
		}
	else 	{
		/* Total length = DATA + CLE + MQ */
		/* ------------------------------ */
		lgtotale = ldatas + lcles + 1;	
		tabsi[nlsi].flag_LV = FALSE;
		fildes=isbuild(nomfic,lgtotale,&keybal,tabsi[nlsi].modisam);
		}

	if (fildes < SUCCESS) { 
		switch ( buildchck() ) {
			case -2 : iscbug(nomfic,errno);
			case -1 : return(-1);
			}
		traitfilerror(nlsi,iserrno); return (-1); 
		}

	/* Force CHMOD +w user + Group Fnom.idx */
	/* ------------------------------------ */
	fnwork[0] = (char) 0; strcat(fnwork,nomfic); strcat(fnwork,ABAL_CISAM_IDX);
	(void) chmod(fnwork,SI_CREATE_PERM);

	/* Force CHMOD +w user + Group Fnom.idx */
	/* ------------------------------------ */
	fnwork[0] = (char) 0; strcat(fnwork,nomfic); strcat(fnwork,ABAL_CISAM_DAT);
	(void) chmod(fnwork,SI_CREATE_PERM);

	/*	 init entree dans tabsi	*/
	/*	 ---------------------- */
	tabsi[nlsi].fildes=fildes;
	tabsi[nlsi].lgcle=lcles;
	if (cadrage > 2 ) { cadrage = 2; }
	tabsi[nlsi].type=cadrage;
	tabsi[nlsi].lgdonnees=ldatas;
	tabsi[nlsi].lgtotale=lgtotale;
	tabsi[nlsi].blocked=FALSE;
	tabsi[nlsi].flag_err=FALSE;

	/* pas de posit sur un autre index */
	/* ------------------------------- */
	tabsi[nlsi].flag_posit= FALSE ; 

#ifdef RT_AIX
	liberfile(nomfic);
#endif
	/* Perform Reservation of Created file Now */
	/* --------------------------------------- */
	if ( si_reservation(nomfic,ex) == SUCCESS ) {

		/* Allocate DATA record buffer */
		/* --------------------------- */
		if ((tabsi[nlsi].rec = malloc (lgtotale)) != (char *) 0) {

			/* Create information file nomfic-I */
			/* -------------------------------- */
			if (fichier_inf(nomfic,nlsi,1) == SUCCESS) {
				if ( (tabsi[nlsi].fnomptr = (char *) malloc( strlen(nomfic) + 2 )) != (char * ) 0 ) {
					strcpy( tabsi[nlsi].fnomptr,nomfic); 

					/* Force CHMOD +w user + Group Fnom.idx */
					/* ------------------------------------ */
					fnwork[0] = (char) 0; strcat(fnwork,nomfic); strcat(fnwork,ABAL_TIRET_I);
					(void) chmod(fnwork,SI_CREATE_PERM);

					/* All Went well */
					/* ------------- */
					tabsi[nlsi].used = TRUE;
					return (nlsi+1);
					}
				else	{ errno = 38; }
				}

			/* Liberate buffer */
			/* --------------- */
			lerr = errno; 
			free(tabsi[nlsi].rec);
			}
		else	{ lerr = 27; }
		}

	/* Arrival here means : .dat .idx EXIST
	 * They must be closed and deleted !!!
	 */
	(void) isclose(fildes);
	(void) si_liberation(nomfic);
	(void) iserase(nomfic);
	traitfilerror(nlsi,lerr); 
	return (-1);
}

/*-----------------------------------------------------------------------------
 *   SI_UNLINK	: Destruction d'un fichier sequentiel indexe
 *-----------------------------------------------------------------------------
 *   Appel	: err = SI_UNLINK(nomfic)
 *   Entree	: char *nomfic : nom du fichier
 *   Sortie 	: int err :  erreur si -1, la variable globale _errno
 *			     etant alors mise a jour avec le code d'erreur
 *
 *---------------------------------------------------------------------------*/
int si_unlink(nomfic)
char *nomfic;
 {
	int	sinlog;		/* Local file handle		*/
	int	lerr;		/* Local Error code		*/

/* -------------------------------------------------------------------- */
/*		Removed due to usage of ACCESS				*/
/*		------------------------------				*/
/*	if ( excl_chck(nomfic) != 0 ) { return(-1); }			*/
/* -------------------------------------------------------------------- */

	/* OPEN the file EXCLUSIVE */
	/* ----------------------- */
	if ( (sinlog = si_open(nomfic,1,0)) < SUCCESS) 	{ return(-1); }

	/* CLOSE the file (keep parameters) */
	/* -------------------------------- */
	if ( si_close(sinlog) != 0 ) 			{ return(-1); }

	/* Delete the C-Isam files */
	/* ----------------------- */
	if (iserase(nomfic) < SUCCESS) {
		traitfilerror(-1,iserrno); return (-1);
		}

	sinlog--;

	/* Delete the Amenesik / Sologic Emulation files */
	/* ----------------------------------- */
	if (fichier_inf(nomfic,sinlog,3) < SUCCESS) {
		traitfilerror(-1,errno); return (-1);
		}
	return (0);
}

/*-----------------------------------------------------------------------------
 *   SI_RENAME	: Renommer un fichier sequentiel indexe
 *-----------------------------------------------------------------------------
 *   Appel	: err = RENAME(ancnom,nouvnom)
 *   Entree	: char *ancnom  : ancien nom du fichier
 *		  char *nouvnom : nouveau nom du fichier
 *   Sortie 	: int err :  erreur si -1, la variable globale _errno
 *			     etant alors mise a jour avec le code d'erreur
 *
 *---------------------------------------------------------------------------*/
int si_rename(ancnom,nouvnom)
char *ancnom,*nouvnom;
{
	int	renerr;		/* Local error storage		*/
	int	sinlog;		/* Numero logique transitoire 	*/
	int	transac;	/* Transaction stage flag	*/
	char	tmpzf1[64];	/* File name construction zone	*/
	char	tmpzf2[64];	/* File name construction zone	*/
	
/* -------------------------------------------------------------------- */
/*		Removed due to usage of ACCESS				*/
/*		------------------------------				*/
/*	if ( excl_chck( ancnom ) != 0 ) { return(-1); }			*/
/* -------------------------------------------------------------------- */
	/* Open File EXCLUSIVE to initialise Parameters */
	/* -------------------------------------------- */
	if ( (sinlog = si_open(ancnom,1,0)) < SUCCESS ) { return (-1); }

	/* Close File (but assumes parameters still OK) */
	/* -------------------------------------------- */
	if ( si_close(sinlog) != 0 ) 			{ return (-1); }
	
	/* Rename the INDEX and DATA files */
	/* ------------------------------- */
	if (isrename(ancnom,nouvnom) < SUCCESS) 	{
		if ( iserrno == 0 ) { iserrno = EEXIST; }
		traitfilerror(-1,iserrno); return (-1);
		}
	/* Initialise transaction stage flag */
	/* --------------------------------- */
	transac = 0; renerr = 0; errno = 0;

	/* Rename the '-I' file */
	/* -------------------- */

	(void) strcpy(tmpzf1,ancnom); (void) strcpy(tmpzf2,nouvnom);
	if ( link( strcat(tmpzf1,"-I") , strcat(tmpzf2,"-I") ) == 0 ) {
		transac |= 2;
		if ( unlink( tmpzf1 ) == 0 ) {
			transac |= 4;
			/* Check for SILV */
			/* -------------- */
			if (tabsi[--sinlog].flag_LV) {
				(void) strcpy(tmpzf1,ancnom); (void) strcpy(tmpzf2,nouvnom);
				if ( link( strcat(tmpzf1,"-LV") , strcat(tmpzf2,"-LV") ) == 0 ) {
					transac |= 8;
					if ( unlink( tmpzf1 ) == 0 ) {
						/* All Well .idx .dat -I -LV */
						/* ------------------------- */
						return (0);
						}
					}
				}
			/* All Went Well .idx .dat -I */
			/* -------------------------- */
			else	{	return (0);	}
			}
		}

	/* UNDO RENAME TRANSACTION
	 * -----------------------
	 * Arrival here means we must interpret the transaction flag
	 * to coherently (if at all possible) UNDO the transaction to
	 * restore the original file condition
	 *
	 * TRANSACTION FLAG 
	 * ----------------
	 *			SET				CLEAR
	 *
	 * Bit 0 	:	No significance
	 * Bit 1	:	LINK -I OK		Link -I Fail	
	 *	Action	: Must delete New-I		Rien a faire
	 * Bit 2	:	UNLINK -I OK		unlink -I fail
	 *	Action	: Must recreate Old-I		Rien a faire
	 * Bit 3	:	LINK -LV OK		Link -LV fail
	 *	Action	: Must delete New-LV		Rien a faire
	 * Rest unused	
	 * In all above case the .dat / .idx files must be reverse renamed
	 * to restore the original condition on entry
	 */

	/* Save the actual error which stopped the transaction */
	/* --------------------------------------------------- */
	renerr = errno;

	/* Delete New file -LV if needed */
	/* ----------------------------- */
	if ( (transac & 8 ) != 0 ) { (void) unlink( tmpzf2 ); }

	/* Check for -I status */
	/* ------------------- */
	if ( (transac & 6) != 0 ) {
		/* Recreate -I filenames */
		/* --------------------- */
		(void) strcpy(tmpzf1,ancnom); (void) strcpy(tmpzf2,nouvnom);
		(void) strcat(tmpzf1,"-I");   (void) strcat(tmpzf2,"-I");

		/* Check for Source DELETED OK */
		/* --------------------------- */
		if ( (transac & 4 ) != 0 ) { (void) link( tmpzf2 , tmpzf1 ); }
		if ( (transac & 2 ) != 0 ) { (void) unlink( tmpzf2 );	     }
		}

	/* Rename the INDEX and DATA files */
	/* ------------------------------- */
	(void) isrename(nouvnom,ancnom);
	traitfilerror(-1,renerr); return (-1);
}

/*-----------------------------------------------------------------------------
 *   SI_UP / SI_DOWN : Lecture sequentielle dans un fichier
 *-----------------------------------------------------------------------------
 *   Appels :
 *		  err = SI_UP(nlsi,lock,reslg,marq,buffer,lg)
 *             	  err = SI_DOWN(nlsi,lock,reslg,marq,buffer,lg)
 *
 *   Entree	: int nlsi : numero logique attribue au fichier
 *		  int lock : 1 si reservation de la cle, 0 sinon
 *		  int reslg : 1 si longueur attendue au retour, 0 sinon
 * 		  char marq : valeur de marqueur a selectionner
 *		  char *buffer : buffer de reception des donnees
 *		  int lg : longueur de l'change
 *   Sortie 	: int err :  erreur si -1, la variable globale _errno
 *			     etant alors mise a jour avec le code d'erreur
 *		  char *buffer, recoit :
 *
 *			si reslg = 0 en entree :
 *				cle,marqueur,donnees
 *			si reslg = 1 en entree :
 *				longueur des donnees,cle,marqueur,donnees
 *
 *---------------------------------------------------------------------------*/
int si_up(nlsi,lock,reslg,marq,buffer,lg)
short int nlsi;
int lock,reslg,lg;
char marq,*buffer;
{
	return( up_down(1,nlsi,lock,reslg,marq,buffer,lg));
}
int si_down(nlsi,lock,reslg,marq,buffer,lg)
short int nlsi;
int lock,reslg,lg;
char marq,*buffer;
{
	return( up_down(2,nlsi,lock,reslg,marq,buffer,lg) );
}

int up_down(psens,nlsi,lock,reslg,marqueur,ptdonnees,plongueur)
int psens;					/* 1 si UP, 2 si DOWN */
short int nlsi;
int lock,reslg,plongueur;
char marqueur,*ptdonnees;
{
	int	lgtotale;
	int	holdsens;
	long	seekvalue,seektampon;
	int	sens;
	int	longueur;

	nlsi--; longueur = plongueur; sens = psens;
	if (verif_nlsi(nlsi) < SUCCESS) { return (-1); }

	if (marqueur == 0) { errno = 73; return (-1); }

	if (reslg) { longueur -= 2; }	/* longueur */

	if (longueur < 0 ) { errno = 122; return (-1); }

	deblock(nlsi); 	/* debloquer enreg precedent */

	holdsens = (sens = (sens==1) ? ISPREV : ISNEXT);

#ifdef  C_ISAM_410
	switch ( tabsi[nlsi].last_error ) {
		case 48 : if ( sens == ISNEXT ) {
				errno = 48;
				return(-1);
				}
			  holdsens = sens;
			  sens = ISLAST;
			  tabsi[nlsi].flag_err = FALSE;
			  break;
		case 64 : if ( sens == ISPREV ) {
				errno = 64;
				return(-1);
				}
			  sens = ISFIRST;
			  tabsi[nlsi].flag_err = FALSE;
			  break;
		}
#endif
	/*================== 1ere lecture si flag_err ==============*/

	if (tabsi[nlsi].flag_err) {	/* l'acces precedent n'a pas abouti */
	   tabsi[nlsi].flag_err = FALSE;
	   if (isread(tabsi[nlsi].fildes,tabsi[nlsi].rec,ISGTEQ) < SUCCESS) {
		if (isread(tabsi[nlsi].fildes,tabsi[nlsi].rec,ISLAST) < SUCCESS) {
			if ((iserrno == EENDFILE) || (iserrno == ENFILE) ||
			    (iserrno == ENOCURR)) {
#ifndef	C_ISAM_410
				if (sens == ISPREV) { errno = 64; }
				else                { errno = 48; }
#else
				switch ( sens ) {
					case ISLAST  :
					case ISPREV  : errno = 64; break;
					case ISFIRST :
					case ISNEXT  : errno = 48; break;
					}
#endif
				}
			else    { traitfilerror(nlsi,iserrno); }
#ifdef  C_ISAM_410
			tabsi[nlsi].last_error = errno;
#endif
			return (-1);
			}
  		if (sens == ISNEXT) tabsi[nlsi].rec [tabsi[nlsi].lgcle] =0;
	   }
    	   else {
	        if (sens == ISPREV) tabsi[nlsi].rec [tabsi[nlsi].lgcle] =0;
	   }
	}				/* l'acces precedent avait abouti */
	else { tabsi[nlsi].rec [tabsi[nlsi].lgcle] =0; }
   
	while ((tabsi[nlsi].rec [tabsi[nlsi].lgcle] & marqueur)==0) {
					/* RECHERCHE ENREGISTREMENT */
	   if (isread(tabsi[nlsi].fildes,tabsi[nlsi].rec,sens) < SUCCESS) {
		if ((iserrno == EENDFILE) || (iserrno == ENFILE) ||
		    (iserrno == ENOCURR)) {
#ifndef	C_ISAM_410
			if (sens == ISPREV) 
				errno = 64;
			else	errno = 48;
#else
			switch ( sens ) {
				case ISLAST  :
				case ISPREV  : errno = 64; break;
				case ISFIRST :
				case ISNEXT  : errno = 48; break;
				}
#endif
			}
		else    { traitfilerror(nlsi,iserrno); }
#ifdef  C_ISAM_410
		tabsi[nlsi].last_error = errno;
#endif
		return (-1);
	   	}
#ifdef  C_ISAM_410
          sens = holdsens;
#endif
	}
#ifdef  C_ISAM_410
	tabsi[nlsi].last_error = 0;
#endif
	if (tabsi[nlsi].lgcle+1 > longueur) { errno = 122; return (-1); }
				/* BLOCAGE ENREGISTREMENT  */ 
	if (lock) {
	   if (isread(tabsi[nlsi].fildes,tabsi[nlsi].rec,ISCURR+ISLOCK) < SUCCESS) {
   		traitfilerror(nlsi,iserrno); 
		if ( errno == 74 ) {
			(void) up_down(psens,(nlsi+1),0,reslg,marqueur,ptdonnees,plongueur);
			errno = 74;
			}
		return (-1);
	   	}
	   tabsi[nlsi].blocked = TRUE;
	   }
	if (tabsi[nlsi].flag_LV) {
				/* LONGUEUR */
		lgtotale = WORDVALUE(&tabsi[nlsi].rec[(tabsi[nlsi].lgcle)+5]);
		if (reslg) {
			abalstore(ptdonnees,(short int) lgtotale);
			ptdonnees+=2;
			}
		lgtotale += tabsi[nlsi].lgcle + 1;

		/* si reception > enregistrement  padder de blancs  */
		/* -----------------------------------------------  */
		if (longueur > lgtotale) {
			memset(ptdonnees, 0x20,longueur);
			longueur = lgtotale;
			}
		seektampon = ldlong((&tabsi[nlsi].rec[(tabsi[nlsi].lgcle)+1]));
		memcpy (ptdonnees, tabsi[nlsi].rec, tabsi[nlsi].lgcle+1);

		if ((seekvalue = lseek(tabsi[nlsi].lvfildes,seektampon,SEEK_SET)) < SUCCESS) {
			errno = 53; return (-1);
			}
		if ((read(tabsi[nlsi].lvfildes,ptdonnees+tabsi[nlsi].lgcle+1,
			longueur-tabsi[nlsi].lgcle-1)) < SUCCESS) {
			errno = 53; return (-1);
			}

		if (lgtotale > longueur) {
			errno = 63; return (-1);
			}
	}
	else {
				/* LONGUEUR */
		if (reslg) {
			abalstore(ptdonnees,(short int) tabsi[nlsi].lgdonnees);
			ptdonnees+=2;
		}

		/* si reception > enregistrement  padder de blancs  */
		if (longueur > tabsi[nlsi].lgtotale) {
			memset(ptdonnees, 0x20,longueur);
			longueur = tabsi[nlsi].lgtotale;
		}
		memcpy (ptdonnees, tabsi[nlsi].rec, longueur);

		if (tabsi[nlsi].lgtotale > longueur) {
			errno = 63; return (-1);
		}
	}
	/* Retour OK */
	return (0);
}
 
/*-----------------------------------------------------------------------------
 *   SI_INSERT : Insertion d'une cle dans un fichier
 *-----------------------------------------------------------------------------
 *   Appel	: err = SI_INSERT(nlsi,cle,marq,buffer,long)
 *
 *   Entree	: int nlsi : numero logique attribue au fichier
 *		  char *cle : pointeur sur la cle
 * 		  char marq : valeur du marqueur
 *		  char *buffer : buffer contenant les donnees
 *		  int long : longueur de l'echange
 *   Sortie 	: int err :  erreur si -1, la variable globale _errno
 *			     etant alors mise a jour avec le code d'erreur
 *
 *---------------------------------------------------------------------------*/
int si_insert(nlsi,cle,marq,buffer,lg)
short int nlsi;
char *cle,marq,*buffer;
int lg;
{
	long int seekvalue;

	nlsi--;
	if (verif_nlsi(nlsi) < SUCCESS)
		return (-1);
#ifdef  C_ISAM_410
	tabsi[nlsi].last_error = 0;
#endif
	tabsi[nlsi].flag_err = FALSE;
	if (marq == 0) {
	    errno = 73; return (-1);
	}
	/* 	cadrage de la cle suivant la definition du fichier 	*/
	cadrer_cle(nlsi,cle);
	if (tabsi[nlsi].flag_LV) {
		/* debut exclusion mutuelle longueur variable */
		/* ------------------------------------------ */
		lseek(tabsi[nlsi].lvfildes,0L,SEEK_SET);
		lockf(tabsi[nlsi].lvfildes,F_LOCK,0L);
		if ((seekvalue = lseek(tabsi[nlsi].lvfildes,0L,SEEK_END)) < SUCCESS) {
			errno = 53; return (-1);
			}
		if (write(tabsi[nlsi].lvfildes,buffer,lg) < SUCCESS) {
			errno = 53; return (-1);
			}
		tabsi[nlsi].rec[tabsi[nlsi].lgcle] = marq;
		stlong(seekvalue,(&tabsi[nlsi].rec[(tabsi[nlsi].lgcle)+1]));
		WORDSTORE(&tabsi[nlsi].rec[(tabsi[nlsi].lgcle)+5],lg);

		/* fin exclusion mutuelle longueur variable */
		/* ---------------------------------------- */
		lseek(tabsi[nlsi].lvfildes,0L,SEEK_SET); 
		lockf(tabsi[nlsi].lvfildes,F_ULOCK,0L);
	}
	else {
					/*   INDEX  */
		tabsi[nlsi].rec [tabsi[nlsi].lgcle]= marq;
					/*   DONNEES  */
		if (lg != tabsi[nlsi].lgdonnees) {
	    		tabsi[nlsi].flag_err = TRUE; errno = 62; return (-1);
		}

		memcpy(&tabsi[nlsi].rec [(tabsi[nlsi].lgcle)+1],
			buffer,
			tabsi[nlsi].lgdonnees);
		if ( tabsi[nlsi].flag_posit != FALSE )
			SI_reposit(nlsi);
	}
	if (iswrcurr(tabsi[nlsi].fildes,tabsi[nlsi].rec) < SUCCESS) {
	    traitfilerror(nlsi,iserrno); return(-1);
	}
	/*      deblocage 	*/
	deblock(nlsi);
	/* Retour OK */
	return (0);
}
 
/*-----------------------------------------------------------------------------
 *   SI_MODIF : Modification du marqueur et des donnees associes a une cle
 *-----------------------------------------------------------------------------
 *   Appel	: err = SI_MODIF(nlsi,cle,marq,buffer,long)
 *
 *   Entree	: int nlsi : numero logique attribue au fichier
 *		  char *cle : pointeur sur la cle
 * 		  char marq : valeur du marqueur
 *		  char *buffer : buffer contenant les donnees
 *		  int long : longueur de l'echange
 *   Sortie 	: int err :  erreur si -1, la variable globale _errno
 *			     etant alors mise a jour avec le code d'erreur
 *
 *---------------------------------------------------------------------------*/
int si_modif(nlsi,cle,marq,buffer,lg)
short int nlsi;
char  *cle,marq,*buffer;
int lg;
{
	long int seekvalue;
	long int oldseekptr;
	int	 oldreksize;

	/* Controle de validity Numero logique */
	/* ----------------------------------- */
	nlsi--;
	if (verif_nlsi(nlsi) < SUCCESS) { return (-1); }

#ifdef  C_ISAM_410
	tabsi[nlsi].last_error = 0;
#endif
	tabsi[nlsi].flag_err = FALSE;

	/* verif validite du marqueur */
	/* -------------------------- */
	if (marq == 0) { errno = 73; return (-1); }
	
	if ( tabsi[nlsi].flag_posit == FALSE ) {

 		/* cadrage de la cle */
		/* ----------------- */
		cadrer_cle(nlsi,cle);

		/* recherche de la cle a modifier */
		/* ------------------------------ */
		if (isread(tabsi[nlsi].fildes,tabsi[nlsi].rec,ISEQUAL) < SUCCESS) {
			traitfilerror(nlsi,iserrno); return (-1);
			}
		}

	/* Operation MODIFY longeur variables ? */
	/* ------------------------------------ */
	if (tabsi[nlsi].flag_LV) {

		/* debut exclusion mutuelle longueur variable */
		/* ------------------------------------------ */
		lseek(tabsi[nlsi].lvfildes,0L,SEEK_SET);
		lockf(tabsi[nlsi].lvfildes,F_LOCK,0L);

		/* Collect Record offset and length infos */
		/* -------------------------------------- */
		oldseekptr = ldlong((&tabsi[nlsi].rec[(tabsi[nlsi].lgcle)+1]));
		oldreksize = WORDVALUE((&tabsi[nlsi].rec[(tabsi[nlsi].lgcle)+5]));
		
		/* Seek to Old Record if New length less or Equal to old */
		/* ----------------------------------------------------- */
		if ( lg <= oldreksize ) {
			seekvalue = lseek(tabsi[nlsi].lvfildes,oldseekptr,SEEK_SET);
			}
		else	{
			/* Must seek to End since new record is longer */
			/* ------------------------------------------- */
			if ((seekvalue = lseek(tabsi[nlsi].lvfildes,0L,SEEK_END)) < SUCCESS) {
				errno = 53; return (-1);
				}
			}
		/* Write the Data Record */
		/* --------------------- */
		if (write(tabsi[nlsi].lvfildes,buffer,lg) < SUCCESS) {
			errno = 53; return (-1);
			}

		/* Reconstruct the current ISAM record */
		/* ----------------------------------- */
		tabsi[nlsi].rec[tabsi[nlsi].lgcle] = marq;
		stlong(seekvalue,(&tabsi[nlsi].rec[(tabsi[nlsi].lgcle)+1]));
		WORDSTORE(&tabsi[nlsi].rec[(tabsi[nlsi].lgcle)+5],lg);

		/* ReWrite current record */
		/* ---------------------- */
		if (isrewcurr(tabsi[nlsi].fildes,tabsi[nlsi].rec) < SUCCESS) {
	    		traitfilerror(nlsi,iserrno); return (-1);
			}
		/* fin exclusion mutuelle longueur variable */
		/* ---------------------------------------- */
		lseek(tabsi[nlsi].lvfildes,0L,SEEK_SET);
		lockf(tabsi[nlsi].lvfildes,F_ULOCK,0L);
		}
	else {
        	/* Controle longueur enregistrement */
		/* -------------------------------- */
		if (tabsi[nlsi].lgdonnees != lg) { errno = 62; return (-1); }

		/* Exec du MODIF par C-Isam */
		/* ------------------------ */
		tabsi[nlsi].rec [tabsi[nlsi].lgcle] = marq;
		memcpy (&tabsi[nlsi].rec [tabsi[nlsi].lgcle +1],buffer,tabsi[nlsi].lgdonnees);
		if (isrewcurr(tabsi[nlsi].fildes,tabsi[nlsi].rec) < SUCCESS) {
	    		traitfilerror(nlsi,iserrno); return (-1);
			}
		}
	/* Deblocage eventuel */
	/* ------------------ */
	deblock(nlsi);

	/* Retour OK */
	/* --------- */
	return (0);
}	

/*-----------------------------------------------------------------------------
 *   SI_SEARCH : Recherche d'une cle dans un fichier
 *-----------------------------------------------------------------------------
 *   Appels	: err = SI_SEARCH(nlsi,lock,reslg,cle,marq,buffer,long)
 *
 *   Entree	: int nlsi : numero logique attribue au fichier
 *		  int lock : 1 si reservation de la cle, 0 sinon
 *		  int reslg : 1 si marqueur attendu au retour,
 *			      2 si longueur attendue au retour, 0 sinon
 *		  char *cle : pointeur sur la cle
 * 		  char marq : valeur du marqueur
 *		  char *buffer : buffer de reception des donnees
 *		  int long : longueur de l'change
 *   Sortie 	: int err :  erreur si -1, la variable globale _errno
 *			     etant alors mise a jour avec le code d'erreur
 *		  char *buffer, recoit :
 *
 *			si reslg = 0 en entree :
 *				donnees
 *			si reslg = 1 en entree :
 *				marqueur,donnees
 *			si reslg = 2 en entree :
 *				longueur des donnees,marqueur,donnees
 *
 *---------------------------------------------------------------------------*/
int si_search(nlsi,lock,reslg,cle,marq,buffer,lg)
short int nlsi;
int lock,reslg,lg;
char *cle,marq,*buffer;
{

	int	mode;
	int	lgtotale;
	long int seektampon,seekvalue;

	/* Correct for Search.L No Marquer !!! */
	/* ----------------------------------- */
	reslg |= lock;	

	nlsi--;
	if (verif_nlsi(nlsi) < SUCCESS) { return (-1); }

#ifdef  C_ISAM_410
	tabsi[nlsi].last_error = 0;
#endif
	tabsi[nlsi].flag_err = FALSE;

	/* verif validite du marqueur */
	/* -------------------------- */
	if (marq == 0) { errno = 73; return (-1); }

	/* Test for Error 122 due to memory tampon overflow */
	/* ------------------------------------------------ */
	if ((reslg & 0x0003) && ( lg < (reslg & 0x0003))) {
		errno = 122;
		return( -1 );
		}
 	
	/* preparation buffer de reception suivant option .M .ML .L ... */
	/* ------------------------------------------------------------ */
	if (reslg & 0x0002) { lg -=2; } 	/* longueur */
	if (reslg & 0x0001) { lg -=1; }		/* marqueur */

	/* verif validite longueur de l'echange */
	/* ------------------------------------ */
	/* Encore une teste debile qui traines  */
	/* ------------------------------------ */
/* 
 *	if (lg < 0 || (lg == 0 && tabsi[nlsi].lgdonnees)) {
 *		errno = 122; return (-1);
 *		}
 */

	/* deblocage eventuel */
	/* ------------------ */
	deblock(nlsi);

	/* cadrage de la cle suivant definition du fichier */
	/* ----------------------------------------------- */
	cadrer_cle(nlsi,cle);

	/* option de blocage de la cle */
	/* --------------------------- */
	if (lock == 1) 	{ mode = ISLOCK; tabsi[nlsi].blocked=TRUE;	}
	else 		{ mode = 0; tabsi[nlsi].blocked=FALSE;		}
	
	if ( tabsi[nlsi].flag_posit != FALSE ) { SI_reposit(nlsi); }

	/* exec de la recherche de la cle par C-Isam */
	/* ----------------------------------------- */
	if (isread(tabsi[nlsi].fildes,tabsi[nlsi].rec,mode+ISEQUAL) < SUCCESS) {
		traitfilerror(nlsi,iserrno); 
		if (isread(tabsi[nlsi].fildes,tabsi[nlsi].rec,ISEQUAL) == SUCCESS) {
			tabsi[nlsi].flag_err = FALSE;
			}
		return (-1);
		}

	/* verif valeur du marqueur */
	/* ------------------------ */
	if ((tabsi[nlsi].rec [tabsi[nlsi].lgcle] & marq) == 0) {
		errno = 79; return (-1);
		}
	if (tabsi[nlsi].flag_LV) {
		lgtotale = WORDVALUE(&tabsi[nlsi].rec[(tabsi[nlsi].lgcle)+5]);
		if (reslg & 2) {
			abalstore(buffer,(short int) lgtotale);
			buffer += 2;
			}
		if (reslg & 1) {
			*(buffer++) = tabsi[nlsi].rec[tabsi[nlsi].lgcle];
			}

		if (lg > lgtotale) { memset(buffer,0x20,lg); lg = lgtotale; }
		seektampon = ldlong( (&tabsi[nlsi].rec[(tabsi[nlsi].lgcle)+1]));

		if ((seekvalue = lseek(tabsi[nlsi].lvfildes,seektampon,SEEK_SET)) < SUCCESS) { 
			errno = 53; return (-1);
			}

		if (read(tabsi[nlsi].lvfildes,buffer,lg) < SUCCESS) {
			errno = 53; return (-1);
			}
		if (lgtotale > lg ) { errno = 63; return (-1); }
	}
	else {	
		/* mise en forme du buffer suivant option de lecture */
		/* ------------------------------------------------- */
		if (reslg & 2) { /* LONGUEUR */
			abalstore(buffer, (short int) tabsi[nlsi].lgdonnees);
			buffer+=2;
			}
		if (reslg & 1) { /* MARQUEUR */
			*(buffer++) = tabsi[nlsi].rec [tabsi[nlsi].lgcle];
			}

		/* si reception > enregistrement  padder de blancs  */
		/* -----------------------------------------------  */
		if (lg > tabsi[nlsi].lgdonnees ) {
			memset(buffer, 0x20,lg);
			lg = tabsi[nlsi].lgdonnees;
			}
		memcpy(buffer, &tabsi[nlsi].rec[tabsi[nlsi].lgcle + 1],lg);

		if (lg < tabsi[nlsi].lgdonnees ) { errno = 63; return (-1); }
	}
	return (0);
}	

/*-----------------------------------------------------------------------------
 *   SI_DELETE : Supprimer une cle ou des niveaux de marqueur dans un fichier
 *-----------------------------------------------------------------------------
 *   Appel	: err = SI_DELETE(nlsi,cle,marq)
 *
 *   Entree	: int nlsi : numero logique attribue au fichier
 *		  char *cle : pointeur sur la cle
 * 		  char marq : valeur du marqueur
 *   Sortie 	: int err :  erreur si -1, la variable globale _errno
 *			     etant alors mise a jour avec le code d'erreur
 *
 *---------------------------------------------------------------------------*/
int si_delete(nlsi,cle,marq)
short int nlsi;
char *cle,marq;
{
	nlsi--;
	if (verif_nlsi(nlsi) < SUCCESS)
		return (-1);
#ifdef  C_ISAM_410
	tabsi[nlsi].last_error = 0;
#endif
	tabsi[nlsi].flag_err = FALSE;
	/* verif validite du marqueur */
	if (marq == 0) {
		errno = 73; return (-1);
	}
#ifdef AVANT_230595	/* Pb de delete apres un posit mc/bd */


	/* cadrage de la cle suivant definition du fichier */
	cadrer_cle(nlsi,cle);
	/* recherche de la cle par C-Isam */
	if (isread(tabsi[nlsi].fildes,tabsi[nlsi].rec,ISEQUAL) < SUCCESS) {
		traitfilerror(nlsi,iserrno); return (-1);
	}
#else
	/* cadrage de la cle suivant definition du fichier */
	if ( tabsi[nlsi].flag_posit == FALSE ) {
	/* cadrage de la cle suivant definition du fichier */
	cadrer_cle(nlsi,cle);
	/* recherche de la cle par C-Isam */
	   if (isread(tabsi[nlsi].fildes,tabsi[nlsi].rec,ISEQUAL) < SUCCESS) {
		traitfilerror(nlsi,iserrno); return (-1);
	    }
        }

#endif
	marq = tabsi[nlsi].rec[tabsi[nlsi].lgcle] & ~marq;
	if (marq) {
		tabsi[nlsi].rec [tabsi[nlsi].lgcle] = marq;
		if (isrewcurr(tabsi[nlsi].fildes,tabsi[nlsi].rec) < SUCCESS){
			traitfilerror(nlsi,iserrno); return (-1);
		}
	}
	else {
		if (isdelcurr(tabsi[nlsi].fildes) < SUCCESS) {
			traitfilerror(nlsi,iserrno); return (-1);
		 }
	}
	deblock(nlsi);
	/* retour OK */
	return (0);
}
int	infexit( fid , retcode )
int	fid;
int	retcode;
{
	(void) close( fid );
	return( retcode );
}

int	zcwork( nomfic , buffer , lg , mode )
char *nomfic,*buffer;
unsigned short int lg;
int mode;
{

	int filedes,res;
	unsigned char finf[256];
	int x;

	strcpy(finf,nomfic); strcat(finf,"-I");
	switch ( mode ) {
		case 1 :
			if ( (x = open(finf,O_RDONLY,0)) == -1) { return(-1); }
			if ( lseek(x,256L,0) == -1L)          { return(infexit(x,-1)); }
			if ( read(x,finf,256) < 65 )          { return(infexit(x,-1)); }
			if ( lg > 0  ) {  (void) memcpy( buffer , (finf + 15) ,( lg > 50 ? 50 : lg )); }
			if ( lg > 50 ) { (void) memset( (buffer + 50), ' ' ,( lg - 50)); }
			break;
		case 2 :
			if ( (x = open(finf,O_RDWR,0)) == -1) { return(-1); }
			if ( lseek(x,256L,0) == -1L)          { return(infexit(x,-1)); }
			if ( read(x,finf,256) < 15 )          { return(infexit(x,-1)); }
			if ( lg > 0 ) {
				(void) memcpy( (finf + 15) , buffer ,(lg > 50 ? 50 : lg));
				if ( lseek(x,256L,0) == -1L  ) {return(infexit(x,-1)); }
				if ( write(x,finf,256) != 256) {return(infexit(x,-1)); }
				}
		}
	errno = 0; return(infexit(x,0));
}

/*-----------------------------------------------------------------------------
 *   SI_READZC : Lecture de la zone commune d'un fichier
 *-----------------------------------------------------------------------------
 *   Appel	: err = SI_READZC(nlsi,lock,buffer,long)
 *   Entree	: int nlsi : numero logique attribue au fichier
 *		  int lock : 1 si reservation demandee, 0 sinon
 *		  char *buffer : buffer d'entree/sortie
 *		  int long : longueur de l'change
 *   Sortie 	: int err :  erreur si -1, la variable globale _err_val
 *			     etant alors mise a jour avec le code d'erreur
 *
 *---------------------------------------------------------------------------*/
int si_readzc(nlsi,lock,nomfic,buffer,lg)
short int nlsi;
int lock,lg;
char *buffer,*nomfic;
{
	/* verif validite du numero logique */
	nlsi--;
	if (verif_nlsi(nlsi) < SUCCESS)
		return (-1);
	/* deblocage eventuel */
	deblock(nlsi);

	return(zcwork(nomfic,buffer,lg,1));
}

/*-----------------------------------------------------------------------------
 *   SI_WRITEZC : Ecriture de la zone commune d'un fichier
 *-----------------------------------------------------------------------------
 *   Appel	: err = SI_WRITEZC(nlsi,buffer,long)
 *   Entree	: int nlsi : numero logique attribue au fichier
 *		  char *buffer : buffer d'entree/sortie
 *		  int long : longueur de l'change
 *   Sortie 	: int err :  erreur si -1, la variable globale _err_val
 *			     etant alors mise a jour avec le code d'erreur
 *
 *---------------------------------------------------------------------------*/
int si_writezc(nlsi,nomfic,buffer,lg)
short int nlsi;
char *buffer;
int lg;
{
	/* verif validite du numero logique */
	nlsi--;
	if (verif_nlsi(nlsi) < SUCCESS)
		return (-1);
	/* deblocage eventuel */
	deblock(nlsi);
	return(zcwork(nomfic,buffer,lg,2));
}
      

/****************************************************************
*							      	*
*  traitfilerror(nlsi,iserrno): Traitement des erreurs fichiers	*
*								*
*****************************************************************/

void traitfilerror(nlsi,coder)
short int nlsi;
int coder;
{
	SystemError = (long) coder;

	/* RAZ des conditions d'erreur */
	/* --------------------------- */
	iserrno=0;	errno = 0;

	switch (coder) {
	
	case EPERM	:	/* Not super-user */
		errno = 58; break;
	case EBADSLT	:	/* C-Isam .idx read error in isopen() */
				/* ---------------------------------- */ 
	case ENOENT	:	/* No such file or directory */
		errno = 40; break; 
	case ESRCH	:	/* No such process */
		errno = 23; break; 
	case EINTR	:	/* interrupted system call */
		errno = 2; break; 
	case EIO	:	/* I/O error */
		errno = 2; break; 
	case ENXIO	:	/* No such device or address */
		errno = 53; break; 
	case E2BIG	:	/* Arg list too long */
		errno = 30; break; 
	case ENOEXEC	:	/* Exec format error */
		errno = 36; break; 
	case EBADF	:	/* Bad file number */
		errno = 50; break; 
	case ECHILD	:	/* No children	*/
		errno = 20; break; 
	case EAGAIN	:	/* No more processes */
		errno = 24; break; 
	case EACCES	:	/* Permission denied	*/
		errno = 58; break; 
	case EFAULT	:	/* Bad address	*/
		errno = 53; break; 
	case ENOTBLK	:	/* Block device required */
		errno = 60; break; 
	case EBUSY	:	/* Mount device busy */
		errno = 44; break; 
	case EEXIST	:	/* File exists	*/
		errno = 41; break; 
	case ENODEV	:	/* No such device */
		errno = 40; break; 
	case ENOTDIR	:	/* Not a directory */
		errno = 30; break; 
	case EISDIR	:	/* Is a directory */
		errno = 30; break; 
	case EINVAL	:	/* Invalid argument */
		errno = 20; break; 
	case EMFILE	:	/* Too many open files	*/
		errno = 51; break; 
	case ETXTBSY	:	/* Text file busy */
		errno = 44; break; 
	case EFBIG	:	/* File too large */
		errno = 45; break;
	case EDEADLK	:	/* Lockf DeadLock	 */
	case ENOLCK	:	/* No More Systeme Locks */
		errno = 134; break;
	case ENOSPC	:	/* No space left on device */
		errno = 46; break; 
	case ESPIPE	:	/* Illegal seek	*/
		errno = 53; break; 
	case EROFS	:	/* Read only file system */
		errno = 47; break; 
	case EDOM	:	/* Math arg out of domain of func */
		errno = 108; break; 
	case ERANGE	:	/* Math result not representable */
		errno = 108; break; 
	case ENFILE  	:
		errno = 72; break;

		/* Erreurs C-ISAM */

	case EDUPL  	: 
			  if (nlsi != -1) tabsi[nlsi].flag_err = TRUE;
			  errno = 81; break;
	case ENOTOPEN	: errno = 42; break;
	case EBADARG 	: errno = 55; break;
	case EBADKEY	: errno = 47; break;
	case ETOOMANY	: errno = 72; break;
	case EBADFILE	: errno = 76; break;
	case ELOCKED	: if (nlsi != -1) tabsi[nlsi].flag_err = TRUE;
			  errno = 74; break;
	case EKEXISTS	: if (nlsi != -1) tabsi[nlsi].flag_err = TRUE;
			  errno = 81; break;
	case ENOREC  	: if (nlsi != -1) tabsi[nlsi].flag_err = TRUE;
			  errno = 78; break;
	case EFLOCKED	: errno = 44; break;	
	case EFNAME	: errno = 30; break;


	default	     	: 
		if ( coder == 0 ) { errno = 58;    }
		else		 { errno = coder; }
		
	}
}

/****************************************************************
*								*
*   Cadrage des clefs selon K, LK, RK				*
*							      	*
*****************************************************************/

void cadrer_cle (nlsi,cle)
short int nlsi;
char *cle;
{
	int k;
	char *dest;

	dest = tabsi[nlsi].rec;

	switch (tabsi[nlsi].type) {

	case 0:					/*  K   */
		memcpy(dest,cle,tabsi[nlsi].lgcle); break;
	case 1:					/*  LK  */
		memset (dest,0x20,tabsi[nlsi].lgcle);
		for (k=0;cle[k] == ' ' && k < tabsi[nlsi].lgcle; k++);
		memcpy(dest,cle+k,tabsi[nlsi].lgcle-k);
		break;
	case 2:					/*  RK  */
		memset (dest,0x20,tabsi[nlsi].lgcle);
		k = LenUse(cle,tabsi[nlsi].lgcle);
		memcpy((dest + (tabsi[nlsi].lgcle - k)),cle,k);
		break;
	}
}

/****************************************************************
*			fichier_inf()				*
*	Ouverture ,lecture/ecriture ,suppression fichier .inf.	*
*								*
*		operation : 1 --> ecriture des parametres(cfile)*
*			    2 --> lecture du parametre  (open)	*
*			    3 --> suppression fichier	(dfile)	*
*								*
*							      	*
*****************************************************************/

fichier_inf(nomfic,nlsi,oper)
char *nomfic;
short int nlsi;
int oper;
{
	int fildes,res;
	unsigned char finf[256];
	unsigned int car;
	int x;

	(void) strcpy(finf,nomfic); (void) strcat(finf,"-I");

	switch (oper) {
	  case 0x01: 	/* Creation des fichiers '-I' et '-LV'	*/
			/* -----------------------------------	*/ 
		if ((x=open(finf,(O_EXCL|O_CREAT|O_RDWR),0666)) < SUCCESS) { 
			if (( errno = ENFILE ) || ( errno == EMFILE )) {
				x = errno;
				unlink( finf );
				errno = x;
				}
			return (-1);
	 		}
		(void) memset(finf,0,256);
		if ( write(x,finf,256) == 256)         { 
			finf[10] = (tabsi[nlsi].lgdonnees & 0x00FF);
			finf[11] = ((tabsi[nlsi].lgdonnees & 0xFF00) >> 8);
			finf[12] = 0x0022;	/* compatibilite */
			if (tabsi[nlsi].type == 1) {
				finf[12] |= 0x0080;	/* cadrage a gauche */
				}
			else if (tabsi[nlsi].type == 2) {
				finf[12] |= 0x00C0;	/* cadrage a droite */
				}
			if (tabsi[nlsi].flag_LV) {
				finf[12] |= 0x0010;	/* lg variable */
				}
			finf[13] = tabsi[nlsi].lgcle;
			for ( car = 15; car < 65; car++ ) { finf[car] = 0; }
			if ( write(x,finf,256) == 256)    { 
				if (tabsi[nlsi].flag_LV) {
					strcpy(finf,nomfic); strcat(finf,"-LV");
					if ((tabsi[nlsi].lvfildes = open(finf,(O_EXCL | O_CREAT | O_RDWR),0666)) != -1) {
						(void) close(x);
						return(0);
						}
					else	{

						if (( errno = ENFILE ) || ( errno == EMFILE )) {
							x = errno;
							unlink( finf );
							errno = x;
							}
						}
					}
				else	{
					(void) close(x);
					return(0);
					}
				}
			}
		/* Write errors (fichier - I) */
		/* -------------------------- */
		(void) close(x);
		(void) strcpy(finf,nomfic); 
		(void) strcat(finf,"-I");
		(void) unlink(finf);
		return(-1);
		
	  case 0x02:	/* Lecture en Ouverture */
			/* -------------------- */
		if ((fildes = open(finf,O_RDWR)) < SUCCESS) { 
			errno = ENOENT;
			return (-1);
			}

		/* caracteristiques fichier en position 12  sur un octet */
		/* ----------------------------------------------------- */
		if (lseek (fildes,256L,0) != 256L ) {
			close (fildes);
			errno = ENOENT;
			return (-1);
			}
		if ( read (fildes,finf,256 ) != 256 ) {
			close (fildes); 
			errno = ENOENT;
			return (-1);
			}
		car = finf[12];
		if ((car & 0x0022) != 0x0022) {
			/* compatibilite version site pilote */
			/* --------------------------------- */
			tabsi[nlsi].type = car;
			tabsi[nlsi].flag_LV = FALSE;
			}
		else 	{
			if ((car & 0x0080) == 0) {
				/* pas de cadrage */
				/* -------------- */
				tabsi[nlsi].type = 0;
				}
			else 	{
				if ((car & 0x0040) == 0) {
					/* cadrage gauche */
					/* -------------- */
					tabsi[nlsi].type = 1;
					}
				else	{
					/* cadrage droite */
					/* -------------- */
					tabsi[nlsi].type = 2;
					}
				}
			if ((car & 0x0010) != 0) {
				/* lg variable */
				/* ----------- */
				tabsi[nlsi].flag_LV = TRUE;
				}
			else	{
				/* lg fixe */
				/* ------- */
				tabsi[nlsi].flag_LV = FALSE;
				}
			}
		close (fildes);

		/* Check for Longeur Variable */
		/* -------------------------- */
		if (tabsi[nlsi].flag_LV) {
			(void) strcpy(finf,nomfic); 
			(void) strcat(finf,"-LV");
			if ((tabsi[nlsi].lvfildes = open(finf,O_RDWR,0666)) == -1) {
				errno = ENOENT;
				return (-1);
				}
			}
		break;

	  case 0x03 :	/* Supression du fichier */
			/* --------------------- */
		if (unlink(finf) < SUCCESS) { return (-1); }
		if (tabsi[nlsi].flag_LV) {
			strcpy(finf,nomfic); strcat(finf,"-LV");
			unlink(finf);
			}
		break;
	}
	errno = 0;
	return (0);
}

/****************************************************************
*								*
*		Deblocage enregistrement			*
*							      	*
*****************************************************************/

deblock(nlsi)
short int nlsi;
{
	if (tabsi[nlsi].blocked) {
		isrelease (tabsi[nlsi].fildes);
		tabsi[nlsi].blocked = FALSE;
	}
}

/****************************************************************
*								*
*      Recherche d'une entree libre dans la table tabsi	*
*								*
*****************************************************************/

int getentry()
{
	int	i;

	for (i=0; i < MAX_FILE_ASSIGN; ) {
		if (tabsi[i].used == FALSE) {
#ifdef  C_ISAM_410
			tabsi[i].last_error = 0;
#endif
			return (i);
		}
		i++;
	}
	return (-1);	/* pas d'entree libre */
}

/****************************************************************
*								*
*	verification de la validite d'un numero logique SI	*
*								*
*****************************************************************/

int verif_nlsi(nlsi)
short int nlsi;
{
	if ((nlsi < 0) || (nlsi >= MAX_FILE_ASSIGN)) {
		errno = 50; return (-1);
	}
	if (tabsi[nlsi].used == FALSE) {
		errno = 50; return (-1);
	}
	return (0);
}




/**************************************************************
*  		lecture longueur des cles		      *
**************************************************************/

unsigned short int si_lgcle(nlsi)
short int nlsi;

{

	nlsi--;
	return(tabsi[nlsi].lgcle);
}

/************************************************************
*		lecture type donnees et cles		    *
************************************************************/

unsigned short int si_type(nlsi)
short int nlsi;

{

	nlsi--;
	return((tabsi[nlsi].type | 2));
}

/************************************************************
*		lecture longueur des donnees		    *
************************************************************/

unsigned short int si_lgdata(nlsi)
short int nlsi;

{
	nlsi--;
	return(tabsi[nlsi].lgdonnees);
}


/*-----------------------------------------------------------------------------
 *  MCBD_SI_MODIF : Modification du marqueur et des donnees associes a une cle
 *-----------------------------------------------------------------------------
 *   Appel	: err = MCBDSI_MODIF(nlsi,cle,marq,buffer,long)
 *
 *   Entree	: int nlsi : numero logique attribue au fichier
 *		  char *cle : pointeur sur la cle
 * 		  char marq : valeur du marqueur
 *		  char *buffer : buffer contenant les donnees
 *		  int long : longueur de l'echange
 *   Sortie 	: int err :  erreur si -1, la variable globale _errno
 *			     etant alors mise a jour avec le code d'erreur
 *
 *---------------------------------------------------------------------------*/
int mcbd_si_modif(nlsi,cle,marq,buffer,lg)
short int nlsi;
char  *cle,marq,*buffer;
int lg;
{

	/* Controle de validity Numero logique */
	/* ----------------------------------- */
	nlsi--;
	if (verif_nlsi(nlsi) < SUCCESS) { return (-1); }

#ifdef  C_ISAM_410
	tabsi[nlsi].last_error = 0;
#endif
	tabsi[nlsi].flag_err = FALSE;

	/* verif validite du marqueur */
	/* -------------------------- */
	if (marq == 0) { errno = 73; return (-1); }

        	/* Controle longueur enregistrement */
		/* -------------------------------- */
		if (tabsi[nlsi].lgdonnees != lg) { errno = 62; return (-1); }

		/* Exec du MODIF par C-Isam */
		/* ------------------------ */
		tabsi[nlsi].rec [tabsi[nlsi].lgcle] = marq;
		memcpy (&tabsi[nlsi].rec [tabsi[nlsi].lgcle +1],buffer,tabsi[nlsi].lgdonnees);
		if (isrewrite(tabsi[nlsi].fildes,tabsi[nlsi].rec) < SUCCESS) {
	    		traitfilerror(nlsi,iserrno); return (-1);
			}
		
	/* Deblocage eventuel */
	/* ------------------ */
	deblock(nlsi);

	/* Retour OK */
	/* --------- */
	return (0);
}	

