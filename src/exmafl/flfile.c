/*
 *      Projet  : ABAL                  Copyright Amenesik / Sologic software (c) 1992, 1997
 *      Module  : EXA
 *      Fichier : FLFILE.C
 *      Version : 1.1d
 *      Date    : 15/04/97
 *      Systeme : Windows 3 / NT / MS-DOS / Unix
 *
 *      Methodes d'acces
 *
 *      [DLL acces direct + sequentiel - Code]
 *
 */

/* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 *  12/09/94 : Debut du codage
 *  17/10/94 : mise en conformite avec les nouvelles bannieres
 *  24/10/94 : comptage des connexions
 *  27/10/94 : adaptations mineures a NT
 *  02/11/94 : adaptation pour Netware
 *  04/11/94 : modifications mineures : pas Netware par defaut
 *  05/11/94 : modification attributs ouverture sur partageabilite
 *  17/02/95 : modifications en vue de portages DOS et UNIX
 *  17/02/95 : portage DOS Etendu (Dll PharLap)
 *  24/02/95 : portage UNIX (SCO) (linke avec EXA ou avec le Serveur)
 *  24/02/95 : abandon du SQFORM passe en parametre car inutile pour EXA
 *  18/04/95 : passage en 1.1b = nettoyage pour W16 / W32 et DOS
 *  18/05/95 : passage en 1.1c = indice de compatibilite 3
 *  18/10/95 : consolidation Unix / Dos / Windows
 *  23/10/95 : mention "active connections" + renforcement robustesse
 *  29/12/95 : fusion avec adaptations Windows 32 bits +
 *                detection erreur 43/44 sous DOS sur suppression fichier
 *  16/02/96 : Modif sur flw1632.c -> casts sur FFread et FFwrite
 *  19/02/96 : Utilisation de Malloc-Free bib. standard pour version 32 bits
 *  29/02/96 : Fusion des sources 32 bits + ajout des MUTEX
 *  06/03/96 : Rename Unix et NT lors d'appel via un redirecteur
 *  29/03/96 : Support des noms de fichiers longs
 *  30/09/96 : Fnct Rename : Modif gestion erreur (renvoi 41 au lieu de 50)
 *  01/10/96 : Passage de Prolgue S.A. a Amenesik / Sologic  
 *  05/02/97 : Modification de fl_xopen sous Windows : open ReadWrite => open ReadWrite + open Read
 *  12/02/97 : Correction bug Ffend en 32 bits => pack(1) des structures
 *  13/02/97 : Ajout de la gestion des fichiers par contexte => fermeture de tous
 *             les fichiers ouverts par la session.
 *  20/02/97 : Correction bug _FFatbopen -> double appel a ErrConv (dans Xopen et apres)
 *                              retire code d'appel a Errconv dans _FFatbopen
 *  28/02/97 : Modif de fn sq_ctrl() pour lock 1 Go sous NETWARE  
 *  10/04/97 : Merge des sources avec version NETWARE
 *  11/04/97 : Ajout du patch IsVMSCompatible pour corriger Pb AGF
 *				SQRead avec buffer + grand que Taille enregistrement => err 63
 *				Comportement <> d' ABAL VMS (AM)
 *  15/04/97 : Modif pour generation version UNIX - Pas de IsVMSCompatible (AM)
 *
 */

/*T-------------------------------------------------------------------------
 *
 * FLFILE : implemente des methodes d'acces direct et sequentiel pur
 * locales et pour reseau point a point (deport de disque), sous reserve
 * de la disponibilite des fonctions de locking au travers du reseau.
 * Un document de specification de l'API et d'analyse-conception de cette
 * DLL existe (ref :  ). On s'y reportera pour toute information generale.
 *
 * ------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------
 *
 * Options de compilation conditionnelle :
 *      __DEBUG__               trace tous les appels de fonction
 *      __WIN_DEBUG__           sortie de la trace sur terminal DBWIN
 *      WIN16                   Windows 16 bits (3.x / WoW)
 *      WIN32                   Windows 32 bits (NT natif)
 *      DOS                     MS-DOS + Phar Lap 286 v2.1
 *      ISUNIX                  Unix : attention si pas SCO !!!
 *
 * ------------------------------------------------------------------------- */

/*#define __DEBUG__*/                     /*Normal debug */
/*#define __VERBOSE_DEBUG__*/             /*verbose  debug */


#include "flfile.h"             /* definitions generales */
#include "flstruct.h"

/* Inclusions des sources systeme-dependant : a garder
 * avant les autres inclusions a cause des redefinitions de
 * fonctions en macros
 */

#ifdef WIN16
#include "flw1632.c"
#include "flw16.c"
#endif
#ifdef WIN32
#include "flw1632.c"
#include "flw32.c"
#endif
#ifdef DOS
#include "fldos.c"
#endif
#ifdef ISUNIX
#include "flunix.c"
#endif
#ifdef NETWARE
#include "flNetWar.c"
#endif

/* Inclusions des sources independants de l'OS */

#include "flfiled.c"            /* fonctions de debug */


static	void	TraitFilError(int nlsi, int coder)
{
	/* RAZ des conditions d'erreur */
	/* --------------------------- */
	errno = 0;

	switch (coder) {
	
	case EPERM	:	/* Not super-user */
		errno = 58; break;
#ifdef	EBADSLT
	case EBADSLT	:	/* C-Isam .idx read error in isopen() */
				/* ---------------------------------- */ 
#endif
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

	default	     	: 
		if ( coder == 0 ) { errno = 58;    }
		else		 { errno = coder; }
		
	}
	return;
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*              OUVERTURE/FERMETURE/IDENTIFICATION DE LA DLL                 */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* --------------------------------------------------------------------------
 *
 * FCT _FFbegin
 *
 *      Ouverture des methodes d'acces.
 *
 *      E/ pointeur sur une structure d'informations sur la DLL
 *         pointeur sur une CALLBACK d'appel de la boucle des messages
 *      S/ compte-rendu d'erreur : 0 si Ok
 *
 * Notes :
 *      On est oblige de conserver l'adresse de la CALLBACK et
 *      le repertoire courant pour chaque client de la DLL,
 *      L'appelant doit conserver le handle de connexion.
 *
 */
int WINAPI _FFbegin(flconf,lpABQT)
	FLCONF SPTR flconf;
	FARPROC lpABQT;
{
	BYTE *	bufptr;
	TASKENVIRON SPTR EnEnv;
#ifdef WIN32
	BYTE Current[LMAXF];
#endif
#ifdef  NETWARE
	S16     NumPID;
	BYTE    Current[LMAXF];

	/* Ecriture interdite dans la table pendant l'init. */
	WaitOnLocalSemaphore( SEM_ISAMBEGINEND );
		
	NumPID = NWGetNumPID(); 
	ConnecTableClients[NumPID]->NbrConnectFF++;
#endif /* NETWARE */

	/* Alloue un nouvel environnement pour la tache appelante,
	 * et le positionne comme environnement courant.
	 */
	EnEnv = NewEnviron();
	if (EnEnv == (TASKENVIRON SPTR)NULL) {
#ifdef  NETWARE
		ConnecTableClients[NumPID]->NbrConnectFF--;
#endif /* NETWARE */
		return(-1);
	}

	/* Recupere le repertoire courant : attention, dans une
	 * variable automatique a cause du modele memoire, puis
	 * le conserve dans l'environnement de l'appelant.
	 */
#ifdef WIN32
	GetCurrentDirectory((U32)LMAXF-3L,(LPSTR)Current);
	Current[LMAXF-3] = '\0';
	fl_xstrcpy((LPSTR)&(EnEnv->CurDir[0]),(LPSTR)Current);
#endif
#ifdef WIN16
	_getcwd(Current,LMAXF-3);
	Current[LMAXF-3] = '\0';
	fl_xstrcpy((LPSTR)&(EnEnv->CurDir[0]),(LPSTR)Current);
#endif
#ifdef  NETWARE
	getcwd(Current,LMAXF-3);
	Current[LMAXF-3] = '\0';
	fl_xstrcpy((LPSTR)&(EnEnv->CurDir[0]),(LPSTR)(strchr(Current,'/')+1));
#endif  /* NETWARE */


	/* Complete l'environnement avec la callback de gestion des ABQT */
	EnEnv->lpABQT = lpABQT;

	/* Remplit la structure d'informations sur la DLL */

	if ((bufptr = (BYTE *) flconf) != (BYTE *) NULL) {

		*(bufptr + FL_ver) 	 = FL_VERSION;		
		*(bufptr + FL_release) 	 = FL_RELEASE;		
		*(bufptr + FL_indice) 	 = FL_INDICE;		
		*(bufptr + FL_compatible)= FL_COMPATIBLE;

		memcpy((bufptr+FL_cnx),&EnEnv,sizeof(U32));

#ifdef	ON_GARDE_POUR_MONTRER_COMMENT_PAS_FAIRE
		flconf->version    = FL_VERSION;
		flconf->release    = FL_RELEASE;
		flconf->indice     = FL_INDICE;
		flconf->compatible = FL_COMPATIBLE;
#ifdef SPARC
		memcpy(&(flconf->hCnx),&(EnEnv),sizeof(U32));
#else
		flconf->hCnx       = (U32)EnEnv;
#endif
#endif

	}

#ifdef __DEBUG__
		{ BYTE b[128];

		fl_xsprintf((LPSTR)b,"\n\tInitial FLCONF=%c.%c%c-%d hcnx=%0.8lX",
			 flconf->version,flconf->release,flconf->indice,
			 flconf->compatible,flconf->hCnx);
		ReqTrace((LPSTR)b);
		fl_xsprintf((LPSTR)b,"\n\tdedicat=%0.4X IdPart1=%0.8lX IdPart2=%0.8lX",
			 flconf->dedicat,flconf->IdPart1,flconf->IdPart2);
		ReqTrace((LPSTR)b);
#ifdef WIN32
		fl_xsprintf((LPSTR)b,"\n\tGetCurrentThreadId = %0.8lX",(U32)GetCurrentThreadId());
		ReqTrace((LPSTR)b);
#endif
		}
#endif

#ifdef  NETWARE
	SignalLocalSemaphore(SEM_ISAMBEGINEND); /* Ecriture disponible dans la table */
#endif  /* NETWARE */

	return(0);
}

/* --------------------------------------------------------------------------
 *
 * FCT _FFend
 *
 *      Fermeture des methodes d'acces.
 *
 *      E/ handle de connexion
 *      S/ compte-rendu d'erreur : 0 si Ok
 *
 */
int WINAPI _FFend(cnx)
EHANDLE cnx;
{ TASKENVIRON SPTR EnEnv;
#ifdef  NETWARE
	S16     NumPID;

	WaitOnLocalSemaphore( SEM_ISAMBEGINEND ); /* Ecriture interdite dans la table pendant ce temps ! */
	NumPID = NWGetNumPID(); 
#endif  /* NETWARE */

	/* Controle la demande l'appelant en comparant le handle
	 * de connexion transmis avec l'environnement conserve
	 * pour la tache appelante.
	 */
#ifdef __VERBOSE_DEBUG__
		ReqTrace((LPSTR)"\n\t_FFend -> Avant GetEnviron");
#endif
	EnEnv = GetEnviron();

#ifdef __DEBUG__
		{ BYTE b[128];
		fl_xsprintf((LPSTR)b,"\n\t_FFend(%0.8lX) :GetEnviron= %0.8lX",cnx,EnEnv);
		ReqTrace((LPSTR)b);
#ifdef WIN32
		fl_xsprintf((LPSTR)b,"\n\t GetCurrentThreadId()=%0.8lX",(U32)GetCurrentThreadId());
		ReqTrace((LPSTR)b);
#endif
		}
#endif
	if (EnEnv != (TASKENVIRON SPTR)cnx)
#ifndef NETWARE
		return(136);
#else
	{
		ConnecTableClients[NumPID]->NbrConnectFF--;
	    SignalLocalSemaphore (SEM_ISAMBEGINEND); /* Ecriture disponible dans la table */
		return(136);
	}
#endif  /* NETWARE */

	CloseAllFiles(EnEnv);

	/* Libere l'environnement de la tache appelante */
	if (EnEnv != (TASKENVIRON SPTR)NULL){
		DropEnviron(EnEnv);
		}

#ifdef  NETWARE
	ConnecTableClients[NumPID]->NbrConnectFF--;
    SignalLocalSemaphore (SEM_ISAMBEGINEND); /* Ecriture disponible dans la table */
#endif  /* NETWARE */

	return(0);
}

/* Il n'y a pas de DLL sous NetWare... */
#ifndef NETWARE

/* --------------------------------------------------------------------------
 *
 * FCT ModuleIdentification
 *
 *      Identification des methodes d'acces.
 *
 *      E/ pointeur sur le nom du fichier de rapport
 *         niveau de lien
 *      S/ compte-rendu d'erreur : 0 si Ok
 *
 */
int WINAPI ModuleIdentification(FileName,Level)
LPSTR FileName;
int Level;
{ 
  HNLOG hBan;
  BYTE buf[128];
  U16 i;
  U16 nuser;
  S16 err;


	/* Ouvre le fichier de rapport */
	hBan = fl_xopen(FileName,1,0,(S16PTR)&err);

	if (hBan == HNLOG_ERROR)
		return(1);

	/* se positionner a la fin      */
	if (fl_xlseek(hBan, (LSEEKTYPE)0, (S16)SEEK_END) == (LSEEKTYPE)-1) {
		(void) fl_xclose(hBan);
#ifdef ISUNIX
		liberlox(FileName);
#endif
		return(1);
	}
	
	/* Ecrit le nom du module et son libelle dans le fichier de rapport */
	FILE_TAB(((S16)Level));
#ifdef WIN32
	FILE_OUT("1:FLFILE32\n");
#endif
#ifdef WIN16
	FILE_OUT("1:FLFILE16\n");
#endif
#ifdef DOS
	FILE_OUT("1:FLFILDOS\n");
#endif
#ifdef ISUNIX
	FILE_OUT("1:FLUNIX\n");
#endif
#ifdef  NETWARE
	FILE_OUT("1:FLNetWare\n");
#endif  /* NETWARE */

	FILE_TAB((S16)Level);
	fl_xsprintf((CPTR)buf,"2:%s\n",(CPTR)FL_LABEL);
	FILE_OUT(buf);

	/* Puis les mentions de version, provisoire et copyright */
	FILE_TAB((S16)Level);
	fl_xsprintf((CPTR)buf,"3:Version %c.%c%c\n",FL_VERSION,FL_RELEASE,FL_INDICE);
	FILE_OUT(buf);
	if (FL_PROVISOIRE != 0) {
		FILE_TAB((S16)Level);
		fl_xsprintf((CPTR)buf,"3:Provisoire du %s\n",(CPTR)FL_DATE);
		FILE_OUT(buf);
	}
	FILE_TAB((S16)Level);
	FILE_OUT("3:Copyright (c) 1994, 2006 Amenesik / Sologic \n");

	/* Compte les utilisateurs */
	for (nuser = 0,i = 0 ; i < MAX_TASK ; i++) {
		if((EnvTable[i]!=(TASKENVIRON SPTR)NULL) && (EnvTable[i]->TaskId!=0L))
			 nuser++;
	}
	FILE_TAB((S16)Level);
	fl_xsprintf((CPTR)buf,"4:Active connections = %d\n",nuser);
	FILE_OUT(buf);

#ifdef WIN1632
	/* Indique au besoin qu'il s'agit d'un usage sous Netware */
	if (IsNetware[7] == '1') {
		FILE_TAB((S16)Level);
		FILE_OUT((CPTR)"4:Netware environment\n");
	}
#ifdef WIN32
	if (IsVMSCompatible[14] == '1') {
		FILE_TAB((S16)Level);
		FILE_OUT((CPTR)"4:Version AGF\n");
	}
#endif
#endif

	/* Et enfin le marqueur de fin de module */
	FILE_OUT("\n");

	/* Puis ferme le fichier */
	(void) fl_xclose(hBan);
#ifdef ISUNIX
	liberlox(FileName);
#endif
	return(0);
}
#endif  /* NETWARE */


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*        GESTION DES FICHIERS OUVERTS PAR ENVIRONNEMENT                     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* --------------------------------------------------------------------------
 *
 * FNCT CloseAllFiles
 *
 *      Ferme tous les fichiers ouverts pour un environnement donne
 *
 *      E/ EnEnv     : Pointeur sur l'environnement
 *      S/ O si Ok, sinon renvoi 0xFFFFh
 *
 */                              
static U16 CloseAllFiles(EnEnv)
TASKENVIRON SPTR        EnEnv;
{
	U16 col,lig;
	EHANDLE Fh=0;
	int err;

#ifdef __VERBOSE_DEBUG__
	ReqTrace((LPSTR)"\n\t<CloseAllFiles> = ");
#endif
	for(lig=0;lig<MAXFILE;lig++){
		if(EnEnv->FileOwned[lig]!=(U8PTR)NULL){
			for(col=0;col<MAXFILE;col++){
				fl_xmemcpy((CPTR)&Fh, (CPTR)&(EnEnv->FileOwned[lig][col*EHANDLESIZE]), EHANDLESIZE);
				if(Fh!=(EHANDLE)NULL){
					err=FFclose(Fh);
					/* Il se peut que ce soit le seul fichier de la table
					 *   Dans ce cas, FFclose desalloue la table d'ou le test
					 */
					if(EnEnv->FileOwned[lig]==(U8PTR)NULL)
						break;                  /* On passe a la ligne suivante */      
					}

				}
			}
		}

#ifdef __VERBOSE_DEBUG__
	ReqTrace((LPSTR)"\n\t<Ret Val CloseAllFiles> = 0");
#endif
	return 0;
}




/* --------------------------------------------------------------------------
 *
 * FNCT ConnectFileToEnviron
 *
 *      memorise le handle de fichier dans la table des handles de
 *  l'environnement concerne.
 *
 *      E/ EnEnv     : Pointeur sur l'environnement
 *     FileHandle : Handle du fichier
 *      S/ U16 avec Poids Fort contenant l'indice en colne dans la table
 *              Poids Faible contenant l'indice en colonne dans la table
 *     Si echec, renvoi 0xFFFFh
 *                      Si FileHandle->PosInOwnerFileTable=0xFFFFh => plus de place dans la table
 *                      Sinon, probleme d'allocation memoire
 *
 */                              
static U16 ConnectFileToEnviron(EnEnv, FileHandle)
TASKENVIRON SPTR        EnEnv;
EHANDLE                         FileHandle;
{
	U16 col,lig;
	EHANDLE Fh;
#ifdef __VERBOSE_DEBUG__
	U8 b[256];
	fl_xsprintf((LPSTR)b,"\n\t<ConnectFileToEnviron(EnEnv=%0.8lX, FileHandle=%0.8lX)=",EnEnv,FileHandle);
	ReqTrace((LPSTR)b);
#endif

	/* On cherche un emplacement libre pour memoriser le handle du fichier. 
	 * Lors de la scrutation soit
	 *  -> L'emplacement EnEnv->FileOwned[lig][col*EHANDLESIZE] est libre 
	 *      => OK
	 *  -> Aucun emplacement libre dans la table EnEnv->FileOwned[lig] 
	 *              => On passe a la ligne suivante. 
	 *  -> La ligne courante n'est pas allouee 
	 *      => Il faut allouer une nouvelle serie de MAXFILE emplacements
	 *         EnEnv->FileOwned[lig]=fl_xmalloc(MAXFILE * EHANDLESIZE)
	 *             handle du fichier est stocke en EnEnv->FileOwned[lig][0]
	 */
	for(lig=0;lig<MAXFILE;lig++){
		if(EnEnv->FileOwned[lig]!=(U8PTR)NULL){
			for(col=0;col<MAXFILE;col++){
				fl_xmemcpy((CPTR)&Fh,(CPTR)&(EnEnv->FileOwned[lig][col*EHANDLESIZE]), EHANDLESIZE);
				if(Fh==(EHANDLE)NULL)
					break;
				}
			if(col>=MAXFILE)
				continue;       /* plus de place dans cette table => table suivante*/
			else{
				/*L'emplacement EnEnv->FileOwned[lig][col*EHANDLESIZE] est libre*/
				if( (lig==(MAXFILE-1)) && (col==(MAXFILE-1)) ){
#ifdef __VERBOSE_DEBUG__
					ReqTrace((LPSTR)"0xFFFF (Plus de place)>");
#endif
					/* On est sur le dernier emplacement qui est inutilisable */
					return (FileHandle->PosInOwnerFileTable=0xFFFF);
					}

				/* l'emplacement est utilisable */
				fl_xmemcpy((CPTR)&(EnEnv->FileOwned[lig][col*EHANDLESIZE]), (CPTR)&FileHandle, EHANDLESIZE);
#ifdef __VERBOSE_DEBUG__
				fl_xsprintf((LPSTR)b,"%0.4X>",lig*MAXFILE+col);
				ReqTrace((LPSTR)b);
#endif
				return (FileHandle->PosInOwnerFileTable=(U16)(lig*MAXFILE+col));        
				/* poids_fort=lig poids_faible=col*/
				}
			}
		else 
			break;
		}

	if(lig>=MAXFILE){       /* plus aucun emplacements libres */
#ifdef __VERBOSE_DEBUG__
		ReqTrace((LPSTR)"0xFFFF (Plus de place)>");
#endif
		return (FileHandle->PosInOwnerFileTable=0xFFFF);
		}

	/* Si on est ici c'est qu'il faut allouer EnEnv->FileOwned[lig]*/
	EnEnv->FileOwned[lig]=(U8PTR)fl_xmalloc(MAXFILE*EHANDLESIZE);
	if(EnEnv->FileOwned[lig]==(U8PTR)NULL){
		/* Probleme d'allocation */
#ifdef __VERBOSE_DEBUG__
		ReqTrace((LPSTR)"0xFFFF (Pb Allocation)>");
#endif
		FileHandle->PosInOwnerFileTable=(U16)(lig*MAXFILE);
		return 0xFFFF;
		}

	/* Initialise le buffer */
	fl_xmemset(EnEnv->FileOwned[lig],0,MAXFILE*EHANDLESIZE);

	/*Allocation correcte */
	fl_xmemcpy((CPTR)&(EnEnv->FileOwned[lig][0]), (CPTR)&FileHandle, EHANDLESIZE);
#ifdef __VERBOSE_DEBUG__
	fl_xsprintf((LPSTR)b,"%0.4X>",lig*MAXFILE);
	ReqTrace((LPSTR)b);
#endif
	return (U16)(FileHandle->PosInOwnerFileTable=(U16)(lig*MAXFILE));
}



/* --------------------------------------------------------------------------
 *
 * FNCT DisconnectFileToEnviron
 *
 *      memorise le handle de fichier dans la table des handles de
 *  l'environnement concerne.
 *
 *      E/ EnEnv     : Pointeur sur l'environnement
 *     FileHandle : Handle du fichier
 *      S/ Si echec, renvoi 0xFFFF
 *         Sinon renvoi 0       
 *
 */                              
static U16 DisconnectFileToEnviron(EnEnv, FileHandle)
TASKENVIRON SPTR        EnEnv;
EHANDLE                         FileHandle;
{
	U16 col,lig,i;
	EHANDLE Fh;
#ifdef __VERBOSE_DEBUG__
	U8 b[256];
	fl_xsprintf((LPSTR)b,"\n\t<DisconnectFileToEnviron(EnEnv=%0.8lX, FileHandle=%0.8lX)=",EnEnv,FileHandle);
	ReqTrace((LPSTR)b);
#endif


	/* Recupere la position du handle dans la table des handles*/
	col = (FileHandle->PosInOwnerFileTable) & 0x00FF;                 /* byte de poids faible */    
	lig = ((FileHandle->PosInOwnerFileTable) >> 8) & 0x00FF; /* byte de poids fort */       

	/* On verifie que l'emplacement est correct */
	if(EnEnv->FileOwned[lig]!=(U8PTR)NULL)
		fl_xmemcpy((CPTR)&Fh,(CPTR)&(EnEnv->FileOwned[lig][col*EHANDLESIZE]), EHANDLESIZE);
	else
		Fh=(EHANDLE)NULL;

	if(Fh != (EHANDLE)FileHandle){
#ifdef __VERBOSE_DEBUG__
		fl_xsprintf((LPSTR)b,"0xFFFF(Pos=%0.4X => Fh=%0.8lX)>",FileHandle->PosInOwnerFileTable,Fh);
		ReqTrace((LPSTR)b);
#endif
		return 0xFFFF;
		}

	/* Le handle est correct - On supprime cette entree*/
	fl_xmemset((CPTR)&(EnEnv->FileOwned[lig][col*EHANDLESIZE]),0,EHANDLESIZE);

	/* On supprime la table si necessaire */
	for(i=0;i<EHANDLESIZE*MAXFILE;i++)
		if(EnEnv->FileOwned[lig][i] != 0)
			break;

	if(i>=EHANDLESIZE*MAXFILE){     /* si oui => table vide a desallouer*/
		fl_xfree((CPTR)EnEnv->FileOwned[lig]);
		EnEnv->FileOwned[lig]=(CPTR)NULL;
		}


#ifdef __VERBOSE_DEBUG__
		fl_xsprintf((LPSTR)b,"0(Pos=%0.4X => Fh=%0.8lX)>",FileHandle->PosInOwnerFileTable,Fh);
		ReqTrace((LPSTR)b);
#endif

	
	return 0;
}



/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*          GESTION DES ENVIRONNEMENTS                                       */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* --------------------------------------------------------------------------
 *
 * FCT NewEnviron
 *
 *      Allocation d'un nouvel environnement.
 *
 *      E/ rien
 *      S/ pointeur sur cet environnement, NULL si impossible
 *
 */                              
static TASKENVIRON SPTR NewEnviron(void)
{ U32 TaskId;
  U16 i;
  U16 j;

#ifdef WIN32  
  U32 cpdu;

#ifdef __VERBOSE_DEBUG__
	ReqTrace((LPSTR)"\nNewEnviron");
#endif
	cpdu = (U32)WaitForSingleObject(MutexHandle,INFINITE);
	if (cpdu == (U32)0xFFFFFFFFL) 
		return((TASKENVIRON SPTR)NULL);/* On ne peut pas posseder le MUTEX */

	/* On possede le mutex et on recupere l'identifiant 
	   de la tache appelante */
#ifdef __VERBOSE_DEBUG__
		ReqTrace((LPSTR)"\nNewEnviron - on possede MutexHandle");
#endif
	TaskId = (U32)GetCurrentThreadId();
#endif
#ifdef WIN16
	TaskId = (U32)GetCurrentTask();
#endif
#ifdef DOS
	TaskId = (U32)getpid();
#endif
#ifdef ISUNIX
	TaskId = (U32)1;
#endif
#ifdef  NETWARE
	U8	NWtab[4];

	/* Numéro de connection */
	TaskId = (U32)NWGetNumPID();
	fl_xmemcpy( NWtab, &TaskId, 4);
	/* + Numéro d'environnement */
	NWtab[3] = ConnecTableClients[TaskId]->NbrConnectFF;
	fl_xmemcpy( &TaskId, NWtab, 4);

	/* yp080497 Cette solution récupére le N° de tâche de Windows appelant MAIS il est possible */
	/* 			que deux stations Windows différentes puissent avoir le même N° (cf Murphy) */
	/* Recupere l'identifiant de la tache appelante : Pour NetWare le N° de connection */
/*	TaskId = ConnecTableClients[(U32)NWGetNumPID()]->TaskIDNW;*/
#endif  /* NETWARE */

	/* Recherche d'une place libre dans la table des environnements */
	for (i = 0 ; i < MAX_TASK ; i++) {
		if (EnvTable[i]==(TASKENVIRON SPTR)NULL)
			break;
	}
	if (i >= MAX_TASK){
#ifdef WIN32
		(void) ReleaseMutex(MutexHandle);
#ifdef __VERBOSE_DEBUG__
		ReqTrace((LPSTR)"\nNewEnviron - on a libere MutexHandle");
#endif
#endif
		return((TASKENVIRON SPTR)NULL);
		}

	/* On renseigne ensuite cet environnement avec l'identifiant
	 * de la tache appelante. Il devient alors occupe.
	 */
	EnvTable[i]=(TASKENVIRON SPTR)fl_xmalloc((U16)sizeof(TASKENVIRON));
	if(EnvTable[i]==(TASKENVIRON SPTR)NULL){
#ifdef __VERBOSE_DEBUG__
		ReqTrace((LPSTR)"\nNewEnviron - ERROR Unable to allocate EnEnv");
#endif
		return((TASKENVIRON SPTR)NULL);
		}
	EnvTable[i]->TaskId = TaskId;
	EnvTable[i]->CurDir[0] = '\0';
	EnvTable[i]->lpABQT    = (FARPROC)NULL;
	for(j=0;j<MAXFILE;j++)
		EnvTable[i]->FileOwned[j]=(U8PTR)NULL;

#ifdef WIN32
	(void) ReleaseMutex(MutexHandle);
#ifdef __VERBOSE_DEBUG__
		ReqTrace((LPSTR)"\nNewEnviron - on a libere MutexHandle");
#endif
#endif

	return((TASKENVIRON SPTR)(EnvTable[i]));
}

/* --------------------------------------------------------------------------
 *
 * FCT DropEnviron
 *
 *      Liberation d'un environnement.
 *
 *      E/ pointeur sur l'environnement a liberer
 *      S/ rien
 *
 */
static void DropEnviron(Environ)
TASKENVIRON SPTR Environ;
{
  U16 i;
#ifdef WIN32  
  U32 cpdu;
	
#ifdef __VERBOSE_DEBUG__
	ReqTrace((LPSTR)"\nDropEnviron");
#endif
	cpdu = (U32)WaitForSingleObject(MutexHandle,INFINITE);
	if (cpdu == 0xFFFFFFFFL) 
		return;         /* On ne peut pas posseder le MUTEX */
#ifdef __VERBOSE_DEBUG__
		ReqTrace((LPSTR)"\nDropEnviron - on possede MutexHandle");
#endif
#endif
	/* Il suffit de liberer l'identifiant de tache
	 * de l'environnement.
	 */
	for (i = 0 ; i < MAX_TASK ; i++) 
		if((EnvTable[i]!=(TASKENVIRON SPTR)NULL) && (EnvTable[i]==Environ) )
			break;
	fl_xfree((CPTR)Environ);
	EnvTable[i]=(TASKENVIRON SPTR)NULL;

#ifdef WIN32
	(void) ReleaseMutex(MutexHandle);
#ifdef __VERBOSE_DEBUG__
		ReqTrace((LPSTR)"\nDropEnviron - on a libere MutexHandle");
#endif
#endif

}

/* --------------------------------------------------------------------------
 *
 * FCT GetEnviron
 *
 *      Retrouve l'environnement d'une tache.
 *
 *      E/ rien
 *      S/ pointeur sur l'environnement de la tache
 *
 */
static TASKENVIRON SPTR GetEnviron(void)
{ U32 TaskId;
  U16 i;
#ifdef WIN32  
  U32 cpdu;
#ifdef __VERBOSE_DEBUG__
		ReqTrace((LPSTR)"\nGetEnviron");
#endif
	
	cpdu = (U32)WaitForSingleObject(MutexHandle,INFINITE);
	if (cpdu == 0xFFFFFFFFL) 
		return((TASKENVIRON SPTR)NULL);  /* On ne peut pas posseder le MUTEX */

#ifdef __VERBOSE_DEBUG__
		ReqTrace((LPSTR)"\nGetEnviron - on possede MutexHandle");
#endif

	/* On possede le mutex et on recupere l'identifiant 
	   de la tache appelante */
	TaskId = (U32)GetCurrentThreadId();
#endif

#ifdef WIN16
	TaskId = (U32)GetCurrentTask();
#endif
#ifdef DOS
	TaskId = (U32)getpid();
#endif
#ifdef ISUNIX
	TaskId = (U32)1;
#endif

#ifdef  NETWARE
	U8	NWtab[4];

	/* Numéro de connection */
	TaskId = (U32)NWGetNumPID();
	fl_xmemcpy( NWtab, &TaskId, 4);
	/* + Numéro d'environnement */
	NWtab[3] = ConnecTableClients[TaskId]->NbrConnectFF;
	fl_xmemcpy( &TaskId, NWtab, 4);

	/* yp080497 Cette solution récupére le N° de tâche de Windows appelant MAIS il est possible */
	/* 			que deux stations Windows différentes puissent avoir le même N° (cf Murphy) */
	/* Recupere l'identifiant de la tache appelante : Pour NetWare le N° de connection */
/*	TaskId = ConnecTableClients[(U32)NWGetNumPID()]->TaskIDNW;*/
#endif  /* NETWARE */

	/* Recherche de l'environnement dans la table des environnements */
	for (i = 0 ; i < MAX_TASK ; i++) {
		if((EnvTable[i]!=(TASKENVIRON SPTR)NULL) && (EnvTable[i]->TaskId == TaskId))
				break;
		}
			
	if (i >= MAX_TASK){
#ifdef WIN32
		(void) ReleaseMutex(MutexHandle);
#ifdef __VERBOSE_DEBUG__
		ReqTrace((LPSTR)"\nGetEnviron - on a libere MutexHandle");
#endif
#endif
		return((TASKENVIRON SPTR)NULL);
		}

#ifdef WIN32
	(void) ReleaseMutex(MutexHandle);
#ifdef __VERBOSE_DEBUG__
		ReqTrace((LPSTR)"\nGetEnviron - on a libere MutexHandle");
#endif
#endif

	return((TASKENVIRON SPTR)(EnvTable[i]));
}


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*                      ACCES DIRECT                                         */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* --------------------------------------------------------------------------
 *
 * FCT _FFopen
 *
 *      Ouverture de fichier.
 *
 *      E/ pointeur sur le nom du fichier, termine par \0
 *         attribut d'ouverture : 1 = exclusif, 0 = partageable
 *         attribut de securite : 1 = mode copie, 0 = mode securite
 *         pointeur sur variable de reception d'erreur
 *      S/ handle du fichier, NULL si fichier non ouvert
 *
 */
EHANDLE WINAPI _FFopen(nom,ex,cop,erreur)
LPSTR nom;
int ex;
int cop;
LPINT erreur;
{
  HNLOG h;
  CPTR p;
  U8 Cnom[LMAXF];
  EHANDLE ExternalHandle;
  TASKENVIRON SPTR EnEnv;
  S16 err;
#ifdef __VERBOSE_DEBUG__
  BYTE b[256];
#endif
  U16 RetConnect;

#ifdef __VERBOSE_DEBUG__
		ReqTrace((LPSTR)"\n\t_FFopen -> Avant getEnviron");
#endif
	/* Repositionne l'environnement courant */
	EnEnv = GetEnviron();
	if (EnEnv == (TASKENVIRON SPTR)NULL) {
		*erreur = 136;
		return((EHANDLE)0);
	}
#ifdef __VERBOSE_DEBUG__
	fl_xsprintf((LPSTR)b,"\t\n_FFopen -> Apres getEnviron=%0.8lX",EnEnv);
	ReqTrace((LPSTR)b);
#endif

	/* Rend le nom du fichier non ambigu */
	if (err = MakeCompleteName(EnEnv,nom,(CPTR)&Cnom[0])) {
		*erreur = err;
		return((EHANDLE)0);
	}

#ifdef __VERBOSE_DEBUG__
	fl_xsprintf((LPSTR)b,"\t\n_FFopen -> Apres MakeCompleteName EnEnv=%0.8lX",EnEnv);
	ReqTrace((LPSTR)b);
#endif


	/* Effectue l'ouverture proprement dite */
	h = fl_xopen((CPTR)&Cnom[0],(S16)ex,(S16)cop,(S16PTR)&err);
	if (h == HNLOG_ERROR) {
		*erreur = (int)err;
		return((EHANDLE)0);
	}

	/* Alloue une structure FILEHANDLE */
	ExternalHandle = (EHANDLE)fl_xmalloc(sizeof(FILEHANDLE));
	if (ExternalHandle == (EHANDLE)NULL) {
		*erreur = 27;
		(void) fl_xclose(h);
#ifdef ISUNIX
		liberlox((CPTR)&Cnom[0]);
#endif
		return((EHANDLE)0);
	}

	/* Puis de quoi stocker le nom du fichier */
	p = (CPTR)fl_xmalloc((U16)(fl_xstrlen((LPSTR)&Cnom[0])+1));
	if (p == (CPTR)NULL) {
		*erreur = 27;
		ExternalHandle->MagicNumber = 0L;
		fl_xfree((CPTR)ExternalHandle);
		(void) fl_xclose(h);
#ifdef ISUNIX
		liberlox((CPTR)&Cnom[0]);
#endif
		return((EHANDLE)0);
	}

	/* On stocke le handle de description dans l'environnement */
#ifdef __VERBOSE_DEBUG__
	fl_xsprintf((LPSTR)b,"\t\t\nAvant ConnectFileToEnviron(%0.8lX,%0.8lX)",EnEnv,ExternalHandle);
	ReqTrace((LPSTR)b);
#endif
	RetConnect=ConnectFileToEnviron(EnEnv,ExternalHandle);
	if(RetConnect==0xFFFF){
		*erreur = 27;
		ExternalHandle->MagicNumber = 0L;
		fl_xfree((CPTR)ExternalHandle);
		(void) fl_xclose(h);
#ifdef ISUNIX
		liberlox((CPTR)&Cnom[0]);
#endif
		return((EHANDLE)0);
		}

	/* Renseigne cette structure avec les informations :
	 *      - handle original
	 *      - nom du fichier
	 *      - attributs d'ouverture
	 *      - pointeur sur l'environnement de la tache
	 */
	ExternalHandle->OriginalHandle = h;
	ExternalHandle->FileName       = p;
	ExternalHandle->ExclAttr       = ex;
	ExternalHandle->CopyAttr       = cop;
	ExternalHandle->Owner          = EnEnv;
	ExternalHandle->MagicNumber    = MAGICHANDLE;
	fl_xstrcpy((CPTR)p,(CPTR)&Cnom[0]);

	*erreur = 0;
	return(ExternalHandle);
}

#ifdef	ISUNIX
/* ------------------------------------ */
/*   flfile configuration information 	*/
/*          IJM : 13/02/2004 		*/
/* ------------------------------------ */
#include "flconfig.c"
#endif

/* --------------------------------------------------------------------------
 *
 * FCT old_FFcreate
 *
 *      Creation de fichier.
 *
 *      E/ pointeur sur le nom du fichier, termine par \0
 *         attribut d'ouverture : 1 = exclusif, 0 = partageable
 *         attribut de securite : 1 = mode copie, 0 = mode securite
 *         pointeur sur variable de reception d'erreur
 *      S/ handle du fichier, NULL si fichier non cree
 *
 */
EHANDLE WINAPI old_FFcreate(nom,ex,cop,erreur)
LPSTR nom;
int ex;
int cop;
LPINT erreur;
{
  S16 err;
  HNLOG h;
  CPTR p;
  BYTE Cnom[LMAXF];
  EHANDLE ExternalHandle;
  TASKENVIRON SPTR EnEnv;

  U16 RetConnect;

  /* Repositionne l'environnement courant */
#ifdef __VERBOSE_DEBUG__
		ReqTrace((LPSTR)"\n\t_FFCreate -> Avant GetEnviron");
#endif
	EnEnv = GetEnviron();
	if (EnEnv == (TASKENVIRON SPTR)NULL) {
		*erreur = 136;
		return((EHANDLE)0);
		}

	/* Rend le nom du fichier non ambigu */
	if (err = MakeCompleteName(EnEnv,nom,(CPTR)&Cnom[0])) {
		*erreur = (int)err;
		return((EHANDLE)0);
		}
	
	/* Alloue une structure FILEHANDLE */
	ExternalHandle = (EHANDLE)fl_xmalloc(sizeof(FILEHANDLE));
	if (ExternalHandle == (EHANDLE)NULL) {
		*erreur = 27;
		return((EHANDLE)0);
		}

	/* Puis de quoi stocker le nom du fichier */
	p = (CPTR)fl_xmalloc((U16)(fl_xstrlen((CPTR)&Cnom[0])+1));
	if (p == (CPTR)NULL) {
		ExternalHandle->MagicNumber = 0L;
		fl_xfree((CPTR)ExternalHandle);
		*erreur = 27;
		return((EHANDLE)0);
		}

	/* Effectue la creation du fichier */
	err = (U32)0;
	h = fl_xcreate((CPTR)&Cnom[0],(S16)ex,(S16)cop,(S16PTR)&err);
	*erreur = (int)err;
	if (h == HNLOG_ERROR) {
		fl_xfree(p);
		ExternalHandle->MagicNumber = 0L;
		fl_xfree((CPTR)ExternalHandle);
		return((EHANDLE)0);
		}

#ifdef	ISUNIX
	/* Set these two now */
	/* ----------------- */
	flfile_set_permissions(Cnom);
	flfile_set_owner_group(Cnom);
#endif


	/* Si version Netware ou mode partageable, rendre le fichier
	 * partageable (la creation ignore les flags de partage).
	 */
#ifdef WIN1632
	if ((ex == 0) || (IsNetware[7] == '1')) {
		/* Commencer par fermer le fichier */
		(void) fl_xclose(h);

		/* Appeler CRNW.DLL pour partager le fichier */
		if (IsNetware[7] == '1') {
			(void)(*NetFn)((LPSTR)&Cnom[0]);
		}

		/* Et enfin, on doit re-ouvrir le fichier */
		h = fl_xopen((LPSTR)&Cnom[0],(S16)ex,(S16)cop,(S16PTR)&err);
		if (h == HNLOG_ERROR) {
			fl_xfree(p);
			ExternalHandle->MagicNumber = 0L;
			fl_xfree((CPTR)ExternalHandle);
			*erreur = (int)err;
			return((EHANDLE)0);
			}
		}
#endif  /* WIN1632      */

	/* On stocke le handle de description dans l'environnement */
	RetConnect=ConnectFileToEnviron(EnEnv,ExternalHandle);
	if(RetConnect==0xFFFF) {
		*erreur = 27;
		ExternalHandle->MagicNumber = 0L;
		fl_xfree((CPTR)ExternalHandle);
		(void) fl_xclose(h);
#ifdef ISUNIX
		liberlox((CPTR)&Cnom[0]);
#endif
		return((EHANDLE)0);
		}



	/* Renseigne la structure allouee avec les informations :
	 *      - handle original
	 *      - nom du fichier
	 *      - attributs d'ouverture
	 *      - pointeur sur l'environnement de la tache
	 */
	ExternalHandle->OriginalHandle = h;
	ExternalHandle->FileName       = p;
	ExternalHandle->ExclAttr       = ex;
	ExternalHandle->CopyAttr       = cop;
	ExternalHandle->Owner          = EnEnv;
	ExternalHandle->MagicNumber    = MAGICHANDLE;
	fl_xstrcpy((CPTR)p,(CPTR)&Cnom[0]);

	*erreur = 0;
	return(ExternalHandle);
}

/* --------------------------------------------------------------------------
 *
 * FCT _FFcreate
 *
 *      Creation de fichier.
 *
 *      E/ pointeur sur le nom du fichier, termine par \0
 *         attribut d'ouverture : 1 = exclusif, 0 = partageable
 *         attribut de securite : 1 = mode copie, 0 = mode securite
 *         pointeur sur variable de reception d'erreur
 *      S/ handle du fichier, NULL si fichier non cree
 *
 */
EHANDLE WINAPI _FFcreate(nom,ex,cop,erreur)
LPSTR nom;
int ex;
int cop;
LPINT erreur;
{
	S16 err;
	HNLOG h;
	CPTR p;
	BYTE Cnom[LMAXF];
	EHANDLE ExternalHandle;
	TASKENVIRON SPTR EnEnv;
	U16 RetConnect;

	/* Repositionne l'environnement courant */
	/* ------------------------------------ */
	if (!(EnEnv=GetEnviron())) {
		*erreur = 136;
		return((EHANDLE)0);
		}

	/* Rend le nom du fichier non ambigu */
	/* --------------------------------- */
	else if ((err = MakeCompleteName(EnEnv,nom,(CPTR)&Cnom[0]))!= 0) {
		*erreur = (int)err;
		return((EHANDLE)0);
		}
	
	/* Alloue une structure FILEHANDLE */
	/* ------------------------------- */
	else if (!( ExternalHandle = (EHANDLE)fl_xmalloc(sizeof(FILEHANDLE)))) {
		*erreur = 27;
		return((EHANDLE)0);
		}

	/* Puis de quoi stocker le nom du fichier */
	/* -------------------------------------- */
	else if (!( p = (CPTR)fl_xmalloc((U16)(fl_xstrlen((CPTR)&Cnom[0])+1)))) {
		ExternalHandle->MagicNumber = 0L;
		fl_xfree((CPTR)ExternalHandle);
		*erreur = 27;
		return((EHANDLE)0);
		}

	/* Effectue la creation du fichier */
	/* ------------------------------- */
	else if ((h = fl_xcreate((CPTR)Cnom,(S16)ex,(S16)cop,(S16PTR)&err)) == HNLOG_ERROR) {
		*erreur = (int)err;
		ExternalHandle->MagicNumber = 0L;
		fl_xfree(p);
		fl_xfree((CPTR)ExternalHandle);
		return((EHANDLE)0);
		}

	/* On stocke le handle de description dans l'environnement */
	/* ------------------------------------------------------- */
	else if ((RetConnect=ConnectFileToEnviron(EnEnv,ExternalHandle)) == 0xFFFF) {
		*erreur = 27;
		ExternalHandle->MagicNumber = 0L;
		fl_xfree((CPTR)ExternalHandle);
		(void) fl_xclose(h);
		return((EHANDLE)0);
		}


	/* Renseigne la structure allouee avec les informations :
	 *      - handle original
	 *      - nom du fichier
	 *      - attributs d'ouverture
	 *      - pointeur sur l'environnement de la tache
	 */
	else	{
		*erreur = 0;
		ExternalHandle->OriginalHandle = h;
		ExternalHandle->FileName       = p;
		ExternalHandle->ExclAttr       = ex;
		ExternalHandle->CopyAttr       = cop;
		ExternalHandle->Owner          = EnEnv;
		ExternalHandle->MagicNumber    = MAGICHANDLE;
		fl_xstrcpy((CPTR)p,(CPTR)&Cnom[0]);
		return(ExternalHandle);
		}
}

/* --------------------------------------------------------------------------
 *
 * FCT _FFclose
 *
 *      Fermeture de fichier.
 *
 *      E/ handle du fichier
 *      S/ compte-rendu d'erreur, 0 si Ok
 *
 */

void	fl_xclose(int h)
{
	if ( h > 2 )
		close(h);
	return;
}



int WINAPI _FFclose(ExternalHandle)
EHANDLE ExternalHandle;
{ TASKENVIRON SPTR EnEnv;

	/* soyons pas trop con */
	if (!( ExternalHandle )) { return(0); }
	/* Repositionne l'environnement courant */
	xcheckhandle(ExternalHandle);
	EnEnv = ExternalHandle->Owner;

	(void) fl_xclose((HNLOG)ExternalHandle->OriginalHandle);

	/* supprime le lien Fichier <-> Environnement*/
	DisconnectFileToEnviron(EnEnv,ExternalHandle);

#ifdef ISUNIX
	liberlox(ExternalHandle->FileName);
#endif

	/* Libere le nom du fichier et le descripteur lui-meme */
	fl_xfree((CPTR)(ExternalHandle->FileName));
	ExternalHandle->MagicNumber = 0L;
	fl_xfree((CPTR)ExternalHandle);
	return(0);
}

/* --------------------------------------------------------------------------
 *
 * FCT _FFaccess
 *
 *      Test d'existence d'un fichier.
 *
 *      E/ pointeur sur le nom du fichier, termine par \0
 *         attributs d'ouverture : 1 = exclusif, 0 = partageable
 *      S/ indicateur d'existence : 0 si Ok, -1 si inexistant
 *
 */
int WINAPI _FFaccess(nom,ex)
LPSTR nom;
int ex;
{ HNLOG h;
#ifdef WIN1632
  OFSTRUCT of;
#endif
  S16 err;
  U8 Cnom[LMAXF];
  TASKENVIRON SPTR EnEnv;

	/* Repositionne l'environnement courant */
#ifdef __VERBOSE_DEBUG__
		ReqTrace((LPSTR)"\n\t_FFacces -> Avant GetEnviron");
#endif
	EnEnv = GetEnviron();
	if (EnEnv == (TASKENVIRON SPTR)NULL)
		return(-1);

	/* Rend le nom du fichier non ambigu */
	if (err = MakeCompleteName(EnEnv,nom,(CPTR)&Cnom[0]))
		return(-1);

	/* Regarde si le fichier existe et peut etre ouvert */
#ifdef WIN1632
	h = OpenFile((LPSTR)&Cnom[0],(OFSTRUCT FAR *)&of,OF_EXIST);
	if (h == HNLOG_ERROR) {
		/* Determine la cause de non ouverture */
		err = ErrorConv((S16)of.nErrCode);

		/* Ne remonte une erreur que si le fichier n'existe pas */
		return((err == 40) ? -1 : 0);
	}
#endif
#ifdef DOSUNIX
#ifdef DOS
	h = fl_xopen((CPTR)&Cnom[0],0,0,(S16PTR)&err);
#else
	h = fl_xopen((CPTR)&Cnom[0],-1,0,(S16PTR)&err);
#endif
	if (h == HNLOG_ERROR) {
		/* Determine la cause de non ouverture */
		/* Ne remonte une erreur que si le fichier n'existe pas */
		return((err == 40) ? -1 : 0);
		}
	else 	{
		fl_xclose(h);
		return(0);
		}
#endif  /* DOSUNIX      */

#ifdef NETWARE
	/* Effectue l'ouverture proprement dite */
	h = fl_xopen((CPTR)&Cnom[0],0,0,(S16PTR)&err);
	if (h == HNLOG_ERROR) {
		/* Determine la cause de non ouverture */
		/* Ne remonte une erreur que si le fichier n'existe pas */
		return((err == 40) ? -1 : 0);
	}
	else {
		fl_xclose(h);
		return(0);
	}
#endif

	return(0);
}

/* --------------------------------------------------------------------------
 *
 * FCT _FFunlink
 *
 *      Suppression d'un fichier.
 *
 *      E/ pointeur sur le nom du fichier, termine par \0
 *      S/ compte-rendu d'erreur : 0 si Ok
 *
 */
int WINAPI _FFunlink(nom)
LPSTR nom;
{ U8 Cnom[LMAXF];
  TASKENVIRON SPTR EnEnv;
  S16 err;

	/* Repositionne l'environnement courant */
#ifdef __VERBOSE_DEBUG__
		ReqTrace((LPSTR)"\n\t_FfUnlink -> Avant GetEnviron");
#endif
	EnEnv = GetEnviron();
	if (EnEnv == (TASKENVIRON SPTR)NULL)
		return(136);

	/* Rend le nom du fichier non ambigu */
	if (err = MakeCompleteName(EnEnv,nom,(CPTR)&Cnom[0]))
		return((int)err);
#ifdef LINUX_BEFORE_THE_FLOOD
	if (!( unlinklox( (CPTR) &Cnom[0] ) ))
		return(0);
	else	return(errno);
#else
	return(fl_xunlink((CPTR)&Cnom[0]));
#endif
	/* Attention, il faudrait gerer l'erreur 43 */
}

/* --------------------------------------------------------------------------
 *
 * FCT _FFatbopen
 *
 *      Changement des attributs d'ouverture d'un fichier.
 *
 *      E/ handle du fichier
 *         valeur a positionner : 1 = exclusif/copie, 0 = partageable/securite
 *         type d'attribut : 1 = securite, 0 = partage
 *      S/ compte-rendu d'erreur : 0 si Ok
 *
 */
int WINAPI _FFatbopen(ExternalHandle,val,type)
EHANDLE ExternalHandle;
int val;
int type;
{ HNLOG Handle;
  S16 err;
  U8 Cnom[LMAXF];
  TASKENVIRON SPTR EnEnv;

	/* On ne change pas l'attribut securite en cours */
	if (type == 1)  return(0);

	/* Repositionne l'environnement courant */
	xcheckhandle(ExternalHandle);
	EnEnv = ExternalHandle->Owner;

	/* Il faut fermer le fichier et le re-ouvrir si
	 * l'attribut de partageabilite a change.
	 */

	if (ExternalHandle->ExclAttr != (U16)val) {

		/* Rend le nom du fichier non ambigu */
		if (err = MakeCompleteName(EnEnv,ExternalHandle->FileName,
					   (CPTR)&Cnom[0])) {
			return((int)err);
			}

#ifdef	ISUNIX

		/* Use the Access equivalent you twat */
		/* ---------------------------------- */
		if ((err = matb( Cnom, val, type, 0 )) == 0) 
			ExternalHandle->ExclAttr       = val;
		else	return( errno );

#else	/* other systems suffer this shit */

		/* Ferme le fichier */
		(void) fl_xclose((HNLOG)ExternalHandle->OriginalHandle);
#ifdef ISUNIX
		liberlox(ExternalHandle->FileName);
#endif
		ExternalHandle->OriginalHandle = (HNLOG)0;

		/* Effectue l'ouverture proprement dite */
		Handle = fl_xopen((CPTR)&Cnom[0],(S16)val,ExternalHandle->CopyAttr,
			       (S16PTR)&err);
		if (Handle == HNLOG_ERROR) {
			return((int)err);
			}

		ExternalHandle->OriginalHandle = Handle;
		ExternalHandle->ExclAttr       = val;
#endif
		}
	return(0);
}

/* --------------------------------------------------------------------------
 *
 * FCT _FFread
 *
 *      Lecture dans un fichier.
 *
 *      E/ handle du fichier
 *         position absolue de lecture
 *         pointeur sur le tampon d'echange
 *         longueur en octets de ce tampon
 *         pointeur sur zone de reception de la longueur echangee
 *      S/ compte-rendu d'erreur : 0 si Ok
 *
 */
int WINAPI _FFread(ExternalHandle,position,buffer,buflen,lu)
EHANDLE ExternalHandle;
LSEEKTYPE position;
CPTR buffer;
int buflen;
LPINT lu;
{ TASKENVIRON SPTR EnEnv;

	/* Repositionne l'environnement courant */
	xcheckhandle(ExternalHandle);
	EnEnv = ExternalHandle->Owner;

#ifdef	PREAD64
	(*lu) = pread64(ExternalHandle->OriginalHandle,buffer,buflen,position);
#else
	/* Effectue le positionnement dans le fichier */
	if (fl_xlseek((HNLOG)ExternalHandle->OriginalHandle,(LSEEKTYPE)position,SEEK_SET) == (LSEEKTYPE)-1) {
		return(53);
	}

	/* Effectue la lecture proprement dite */
	(*lu) = fl_xread(ExternalHandle->OriginalHandle,buffer,buflen);
#endif
	if ((*lu) == HNLOG_ERROR) {
		(*lu) = 0;
		return(50);
	}

	/* Controle la longueur lue et la fin du fichier */
	if ((*lu) != (int)(U16)buflen) {
		if ((*lu) == 0)
			return(53);
		else
			return(48);
	}

	return(0);
}

/* --------------------------------------------------------------------------
 *
 * FCT _FFwrite
 *
 *      Ecriture dans un fichier.
 *
 *      E/ handle du fichier
 *         position absolue d'ecriture
 *         pointeur sur le tampon d'echange
 *         longueur en octets de ce tampon
 *         pointeur sur zone de reception de la longueur echangee
 *      S/ compte-rendu d'erreur : 0 si Ok
 *
 */
int WINAPI _FFwrite(ExternalHandle,position,buffer,buflen,ecrit)
EHANDLE ExternalHandle;
LSEEKTYPE position;
CPTR buffer;
int buflen;
LPINT ecrit;
{ TASKENVIRON SPTR EnEnv;

	/* Repositionne l'environnement courant */
	xcheckhandle(ExternalHandle);
	EnEnv = ExternalHandle->Owner;

#ifdef	PWRITE64
	(*ecrit) = pwrite64((HNLOG)ExternalHandle->OriginalHandle,buffer,buflen,position);
#else

	/* Effectue le positionnement dans le fichier */
	if (fl_xlseek(ExternalHandle->OriginalHandle,(LSEEKTYPE)position,SEEK_SET) == (LSEEKTYPE)-1) {
		return(53);
	}

	/* Effectue l'ecriture proprement dite */
	(*ecrit) = fl_xwrite((HNLOG)ExternalHandle->OriginalHandle,buffer,buflen);
#endif
	if ((*ecrit) == HNLOG_ERROR) {
		(*ecrit) = 0;
		return(50);
	}

	/* Controle la longueur ecrite pour detecter le
	 * debordement de volume.
	 */
	if ((buflen != 0) && ((*ecrit) < (int)(U16)buflen)) {
		return(46);
	}

	return(0);
}

/* --------------------------------------------------------------------------
 *
 * FCT _FFextend
 *
 *      Extension d'un fichier.
 *
 *      E/ handle du fichier
 *         nombre d'octets a ajouter en fin de fichier
 *      S/ compte-rendu d'erreur : 0 si Ok
 *
 */
int WINAPI _FFextend(ExternalHandle,len)
EHANDLE ExternalHandle;
U32	len;
{ U16 ecrit,aecrire;
  U32 nbsect;
  U8 buffer[256];
  U16 i;
  TASKENVIRON SPTR EnEnv;

	/* Repositionne l'environnement courant */
	xcheckhandle(ExternalHandle);
	EnEnv = ExternalHandle->Owner;

	/* Effectue le positionnement en fin de fichier */
	if (fl_xlseek(ExternalHandle->OriginalHandle,(LSEEKTYPE)0,SEEK_END) == (LSEEKTYPE)-1) {
		return(53);
	}

	/* Remise a zero du buffer */
	fl_xmemset((CPTR)buffer,0,256);
	nbsect = (len + 255L) / 256L;

	/* Effectue l'extension proprement dite par ecriture
	 * de secteurs de 256 octets a nul.
	 */
	for (i = 0 ; i < nbsect ; i++) {
		aecrire = (len > (U32)256) ? (U16)256 : (U16)len;
		ecrit = fl_xwrite(ExternalHandle->OriginalHandle,(LPSTR)buffer,aecrire);
		if (ecrit == HNLOG_ERROR) {
			return(50);
		}
		if (ecrit != aecrire) {
			return(46);
		}
		len -= (U32)aecrire;
	}

	return(0);
}
/* --------------------------------------------------------------------------
 *
 * FCT _FFrename
 *
 *      Renommage d'un fichier.
 *
 *      E/ handle du fichier
 *         pointeur sur le nouveau nom de fichier, termine par \0
 *      S/ compte-rendu d'erreur : 0 si Ok
 *
 */

int WINAPI _FFrename(ExternalHandle,NewName)
EHANDLE ExternalHandle;
LPSTR NewName;
{ 
	int	status;
	CPTR	tptr;

	/* Repositionne l'environnement courant */
	xcheckhandle(ExternalHandle);

	/* Ensure Exclusive Assigned Opening */
	/* --------------------------------- */
	if (ExternalHandle->ExclAttr == 0) {
		return(44);
		}

	/* Step over leading white space */
	/* ---------------------------- */
	while ((*NewName == ' ') || (*NewName == '\t'))
		NewName++;

	/* Check resulting name is valid */
	/* ----------------------------- */
	if (!(*NewName)) 
		return(30);

	/* Allocate a zone for storage now */
	/* ------------------------------- */
	else if (!(tptr = fl_xmalloc(fl_xstrlen(NewName)+1)))
		return(27);

	/* Attempt the Rename Transaction */
	/* ------------------------------ */
	else  if ((status = renamelox( ExternalHandle->FileName, NewName )) != 0) {
		fl_xfree(tptr);
		return(errno);
		}
	/* Store the new name to the Handle */
	/* -------------------------------- */
	else	{
		fl_xstrcpy(tptr,NewName);
		fl_xfree(ExternalHandle->FileName);
		ExternalHandle->FileName = tptr;
		return(0);
		}
}


/* --------------------------------------------------------------------------
 *
 * FCT _FFrename
 *
 *      Renommage d'un fichier.
 *
 *      E/ handle du fichier
 *         pointeur sur le nouveau nom de fichier, termine par \0
 *      S/ compte-rendu d'erreur : 0 si Ok
 *
 */

int WINAPI old_FFrename(ExternalHandle,NewName)
EHANDLE ExternalHandle;
LPSTR NewName;
{ CPTR tmp;
  HNLOG Handle;
  TASKENVIRON SPTR EnEnv;
  S16 err;
#ifdef __VERBOSE_DEBUG__
	BYTE b[512];
#endif

#ifdef WIN32
  BYTE OldName[LMAXF];
  BYTE NewN[LMAXF];
  LSEEKTYPE ErrRename;
#endif
#ifdef DOS
  BYTE OldName[LMAXF];
  BYTE NewN[LMAXF];
#endif
#ifdef WIN16
#define OldName Path1
#define NewN    Path2
#endif
#ifdef ISUNIX
  BYTE OldName[LMAXF];
  BYTE NewN[LMAXF];
#endif
#ifdef  NETWARE
  U8 OldName[LMAXF/*256*/];
  U8 NewN[LMAXF/*256*/];
  U16 lenom; //Nouveau
#endif  /* NETWARE */
#ifdef UNIXWARE
  HNLOG svOriginalHandle;
#endif

	/* Repositionne l'environnement courant */
	xcheckhandle(ExternalHandle);
	EnEnv = ExternalHandle->Owner;

	/* Pour que meme les c..s soient contents, on saute les
	 * eventuels espaces en tete du nouveau nom.
	 */
	while ((*NewName == ' ') || (*NewName == '\t')) {
		NewName++;
		}
	if (*NewName == '\0') {
		return(30);
		}

	/* Verifier que le fichier est ouvert en exclusif */
	if (ExternalHandle->ExclAttr == 0) {
		return(44);
		}

	/* Recopie les noms dans une zone temporaire :
	 *      - le nouveau a cause de rename et du modele memoire
	 *        (on en profite pour lever l'ambiguite du nom)
	 *      - l'ancien nom car sa reference pourrait etre detruite
	 * NB: solution pour eviter les limites des redirecteurs Criteria :
	 *      - si le nouveau nom est prefixe par un BYTE … 1 binaire
	 *        on suppose qu'il ne comporte qu'une mention de nom. Dans
	 *        ce cas, la recomposition du nom final est differente et
	 *        consiste a coller ce nom a la fin du path conserve avec
	 *        le handle du fichier. Ce faisant on interdit les MOVE
	 *        inter-repertoires implicites.
	 *      - sinon, on travaille comme avant.
	 */

#ifdef WIN32_UNIX
	if (*NewName == (BYTE)1) {
#ifdef UNIXWARE
		S16 lenom;
#else
		U16 lenom;
#endif
		/* Recupere l'ancien nom de fichier */
		fl_xstrcpy((CPTR)NewN,(CPTR)ExternalHandle->FileName);

		/* Remonte a partir de la fin a la recherche d'un
		 * separateur de repertoire, en s'arretant au debut !
		 */
		lenom = fl_xstrlen((CPTR)NewN);
		while (lenom != 0) {
#ifdef ISUNIX
			if (NewN[lenom-1] == '/')       break;
#else
			if ((NewN[lenom-1] == '\\') ||
			    (NewN[lenom-1] == ':'))     break;
#endif
			lenom--;
			}

		/* Verifie qu'il reste assez de place pour poser le nom */
		if (fl_xstrlen(NewName+1)+lenom+1 > LMAXF-1)    return(30);

		/* Copie le nom au bout du chemin */
		fl_xstrcpy((CPTR)NewN+lenom,(CPTR)NewName+1);
		}
	else 	{
		/* Faire comme a l'accoutumee */
		if (err = MakeCompleteName(EnEnv,(CPTR)NewName,(CPTR)NewN))
			return((int)err);
		}
#else

#ifndef NETWARE
	if (err = MakeCompleteName(EnEnv,(CPTR)NewName,(CPTR)NewN))
		return((int)err);
#else   /* NETWARE */
	if (*NewName == (BYTE)1) {

		/* Recupere l'ancien nom de fichier */
		fl_xstrcpy((CPTR)NewN,(CPTR)ExternalHandle->FileName);

		/* Remonte a partir de la fin a la recherche d'un
		 * separateur de repertoire, en s'arretant au debut !
		 */
		lenom = fl_xstrlen((CPTR)NewN);
		while (lenom != 0) {
			if ((NewN[lenom-1] == '\\') ||
			    (NewN[lenom-1] == ':'))     break;
			lenom--;
			}

		/* Verifie qu'il reste assez de place pour poser le nom */
		if (fl_xstrlen(NewName+1)+lenom+1 > LMAXF-1)    return(30);

		/* Copie le nom au bout du chemin */
		fl_xstrcpy((CPTR)NewN+lenom,(CPTR)NewName+1);
		}
	else 	{
		/* Faire comme a l'accoutumee */
		if (err = MakeCompleteName(EnEnv,(CPTR)NewName,(CPTR)NewN))
			return((int)err);
		}
#endif  /* NETWARE */

#endif	/* WIN32_UNIX */

#ifdef	ISUNIX

	/* Test for File Existance */
	/* ----------------------- */
	if ((Handle = open(NewN,O_RDWR)) != HNLOG_ERROR) {
		close( Handle );
		return(41);
	  	};
	/* Allocate for new name storage */
	/* ----------------------------- */
	if (!(tmp = fl_xmalloc(fl_xstrlen(NewN)+1))) {
		return(27);
		}
	else	fl_xstrcpy((LPSTR)tmp,(LPSTR)NewN);

	/* Collect old file name */
	/* --------------------- */
	fl_xstrcpy((CPTR)OldName,(CPTR)ExternalHandle->FileName);

	/* And rename the old as the new */
	/* ----------------------------- */
	if ( link( OldName, NewN ) == -1 ) {
		TraitFilError(-1,errno);
		fl_xfree(tmp);
		return( errno );
		}
	else if ( unlink( OldName ) == -1 ) {
		TraitFilError(-1,errno);
		fl_xfree(tmp);
		return( errno );
		}

	/* Store the new name prior to the return */
	/*--------------------------------------- */
	fl_xfree(ExternalHandle->FileName);
	ExternalHandle->FileName = tmp;

#else	/* ! ISUNIX */
	/* -------- */

#if defined(RT_AIX) || defined(UNIXWARE)

	/* Test for File Existance */
	/* ----------------------- */
	if ((Handle = open(NewN,O_RDWR)) != HNLOG_ERROR) {
		close( Handle );
		return(41);
	  	};
#endif

	fl_xstrcpy((CPTR)OldName,(CPTR)ExternalHandle->FileName);

	/* Pour ne pas avoir de conflit avec SHARE, il faut refermer
	 * puis re-ouvrir le fichier. Pour cela, on effectue :
	 *      - recuperation du handle systeme du fichier
	 *      - fermeture du fichier
	 *      - renommage
	 *      - reouverture
	 *      - conservation du nouveau handle systeme
	 */
	(void) fl_xclose(ExternalHandle->OriginalHandle);

#ifdef ISUNIX
	liberlox(OldName);
#endif
#ifdef UNIXWARE
	svOriginalHandle =ExternalHandle->OriginalHandle;
#endif

	ExternalHandle->OriginalHandle = (HNLOG)0;
	/* On renomme */
#ifndef WIN32
	if (rename((char *)OldName,(char *)NewN) != 0) {
#if defined(UNIXWARE) || defined(RT_AIX)
	        ExternalHandle->OriginalHandle=svOriginalHandle ;
		if (errno != 0)
		  return( (S16) ErrorConvBib( (S16) errno));
#endif
		return(41);
		}
#else
#ifdef __VERBOSE_DEBUG__
	ReqTrace((LPSTR)"\n FFrename:\n");
	fl_xsprintf((LPSTR)b,"\t\tOldName:'%s'\n\t\tNewName:'%s'\n",
	 (LPCSTR)OldName,(LPCSTR)NewN);
	ReqTrace((LPSTR)b);

#endif

#ifndef NETWARE

	/* AM300996 : Modif de la gestion d'erreur */
	if (MoveFile((LPCSTR)OldName,(LPCSTR)NewN) == FALSE) {
		ErrRename=GetLastError();
		if (ErrRename==0)       err=41;         /* bug MoveFile */
		else    err=conv_nt_error(ErrRename); 

		return((int)err);
		}
#else   /* NETWARE */
	if (rename((char *)OldName,(char *)NewN) != 0) {
		return(50);
	}
#endif  /* NETWARE */

#endif

	/* et ou re-ouvre */
	Handle = fl_xopen((CPTR)NewN,1,ExternalHandle->CopyAttr,(S16PTR)&err);
	if (Handle == HNLOG_ERROR) {
		return((int)err);
	}

	/* Conserve le nom du nouveau fichier */
	fl_xfree((CPTR)(ExternalHandle->FileName));
	tmp = (CPTR)fl_xmalloc((U16)(fl_xstrlen((CPTR)NewN)+1));
	if (tmp == (CPTR)NULL) {
		(void) fl_xclose(Handle);
#ifdef ISUNIX
		liberlox(NewN);
#endif
		return(27);
	}

	fl_xstrcpy((LPSTR)tmp,(LPSTR)NewN);
	ExternalHandle->FileName = tmp;

	/* Et le nouveau handle du fichier */
	ExternalHandle->OriginalHandle = Handle;

#endif	/* ISUNIX */

	return(0);
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*                      ACCES SEQUENTIEL                                     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* --------------------------------------------------------------------------
 *
 * FCT _SQopen
 *
 *      Ouverture de fichier.
 *
 *      E/ pointeur sur le nom du fichier, termine par \0
 *         attribut d'ouverture : 1 = exclusif, 0 = partageable
 *         attribut de securite : 1 = mode copie, 0 = mode securite
 *         pointeur sur longueur de l'enregistrement
 *         pointeur sur variable de reception d'erreur
 *      S/ handle du fichier, NULL si fichier non ouvert
 *
 */
EHANDLE WINAPI _SQopen(nom,ex,cop,ldata,erreur)
CPTR nom;
int ex;
int cop;
LPINT ldata;
LPINT erreur;
{ EHANDLE ExternalHandle;
  TASKENVIRON SPTR EnEnv;
  S16 err;
  SQFORM SPTR sqform;

	/* Repositionne l'environnement courant */
#ifdef __VERBOSE_DEBUG__
		ReqTrace((LPSTR)"\n\t_SQopen -> Avant getEnviron");
#endif
	EnEnv = GetEnviron();
	if (EnEnv == (TASKENVIRON SPTR)NULL) {
		*erreur = 136;
		return((EHANDLE)0);
	}

	/* Ouvre le fichier en mode acces direct */
	ExternalHandle = _FFopen(nom,ex,cop,erreur);
	if (ExternalHandle == (EHANDLE)0)
		return((EHANDLE)0);

	/* Recupere la structure d'informations sur le fichier */
	sqform = (SQFORM SPTR)&(ExternalHandle->sqform);

	/* Lit le secteur d'entete du fichier sequentiel */
	if (sq_ctrl(EnEnv,ExternalHandle,GET_SQFCB,sqform,(S16PTR)&err) != 0) {
		*erreur = (int)err;
		release_locks(ExternalHandle);
		return((EHANDLE)0);
	}

	/* Met a jour la structure d'informations sur le fichier */
	sqform->SQrd_rec = 0;
	sqform->SQwr_rec = sqform->SQnb_rec;
	release_locks(ExternalHandle);

	/* Puis longueur enregistrement et compte-rendu */
	*ldata  = (int) sqform->SQsz_rec;
	*erreur = 0;

	return(ExternalHandle);
}

/* --------------------------------------------------------------------------
 *
 * FCT _SQcreate
 *
 *      Creation de fichier.
 *
 *      E/ pointeur sur le nom du fichier, termine par \0
 *         attribut d'ouverture : 1 = exclusif, 0 = partageable
 *         attribut de securite : 1 = mode copie, 0 = mode securite
 *         longueur de l'enregistrement
 *         pointeur sur variable de reception d'erreur
 *      S/ handle du fichier, NULL si fichier non cree
 *
 */
EHANDLE WINAPI _SQcreate(nom,ex,cop,len,erreur)
LPSTR nom;
int ex;
int cop;
int len;
LPINT erreur;
{ EHANDLE ExternalHandle;
  TASKENVIRON SPTR EnEnv;
  S16 err;
  SQFORM SPTR sqform;

	/* Repositionne l'environnement courant */
#ifdef __VERBOSE_DEBUG__
		ReqTrace((LPSTR)"\n\t_SQcreate -> Avant GetEnviron");
#endif
	EnEnv = GetEnviron();
	if (EnEnv == (TASKENVIRON SPTR)NULL) {
		*erreur = 136;
		return((EHANDLE)0);
	}

	/* Cree le fichier en mode acces direct */
	ExternalHandle = _FFcreate(nom,ex,cop,erreur);
	if (ExternalHandle == (EHANDLE)0)
		return((EHANDLE)0);

	/* Recupere la structure d'informations sur le fichier */
	sqform = (SQFORM SPTR)&(ExternalHandle->sqform);

	/* Cree le secteur d'entete du fichier */
	sqform->SQsz_rec = len;         /* Record Length        */
	sqform->SQnb_rec = 0;           /* Number of Records    */
	sqform->SQrd_rec = 0;           /* Current Read index   */
	sqform->SQwr_rec = 0;           /* Current Write index  */

	/* Effectue l'ecriture du secteur d'entete */
	if (sq_ctrl(EnEnv,ExternalHandle,MAJ_SQFCB,sqform,(S16PTR)&err) != 0) {
		*erreur = (int)err;
		return((EHANDLE)0);
	}

	return(ExternalHandle);
}

/* --------------------------------------------------------------------------
 *
 * FCT _SQclose
 *
 *      Fermeture de fichier.
 *
 *      E/ handle du fichier
 *      S/ compte-rendu d'erreur, 0 si Ok
 *
 */
int WINAPI _SQclose(ExternalHandle)
EHANDLE ExternalHandle;
{
	/* Fermeture du fichier au niveau acces direct */
	return(_FFclose(ExternalHandle));
}

/* --------------------------------------------------------------------------
 *
 * FCT _SQunlink
 *
 *      Suppression d'un fichier.
 *
 *      E/ pointeur sur le nom du fichier, termine par \0
 *      S/ compte-rendu d'erreur : 0 si Ok
 *
 */
int WINAPI _SQunlink(nom)
CPTR nom;
{
	/* Suppression du fichier au niveau acces direct */
	return(_FFunlink(nom));
}

/* --------------------------------------------------------------------------
 *
 * FCT _SQatbopen
 *
 *      Changement des attributs d'ouverture d'un fichier.
 *
 *      E/ handle du fichier
 *         valeur a positionner : 1 = exclusif/copie, 0 = partageable/securite
 *         type d'attribut : 1 = securite, 0 = partage
 *      S/ compte-rendu d'erreur : 0 si Ok
 *
 */
int WINAPI _SQatbopen(ExternalHandle,val,type)
EHANDLE ExternalHandle;
int val;
int type;
{
	/* Changement d'attributs au niveau acces direct */
	return(_FFatbopen(ExternalHandle,val,type));
}

/* --------------------------------------------------------------------------
 *
 * FCT _SQread
 *
 *      Lecture d'un enregistrement.
 *
 *      E/ handle du fichier
 *         pointeur sur le tampon d'echange
 *         longueur en octets de ce tampon
 *      S/ compte-rendu d'erreur : 0 si Ok
 *
 */
int WINAPI _SQread(ExternalHandle,buffer,buflen)
EHANDLE ExternalHandle;
CPTR buffer;
int buflen;
{ 
	LSEEKTYPE	fidseek;
	int 		cpdu;
	int 		lu;
	TASKENVIRON SPTR EnEnv;
	S16 		err;
	SQFORM SPTR 	sqform;

	/* Repositionne l'environnement courant */
	xcheckhandle(ExternalHandle);
	EnEnv = ExternalHandle->Owner;

	/* Recupere la structure d'informations sur le fichier */
	sqform = (SQFORM SPTR)&(ExternalHandle->sqform);

	/* Controle la longueur du tampon de reception */
	/* AM110497 : Modif pour Compatibilite VMS */
#ifdef WIN32
	if(IsVMSCompatible[14]=='0'){
#endif
		if (buflen != (int)sqform->SQsz_rec)
			return(63);
#ifdef WIN32
		}
	else{
		if (buflen < (int)sqform->SQsz_rec)
			return(63);
		}
#endif

	/* Lecture du secteur d'entete sans verrouillage */
	if (sq_ctrl(EnEnv,ExternalHandle,GET_SQFCB,sqform,(S16PTR)&err) != 0) {
		return((int)err);
	}

	/* Verifie que l'enregistrement a lire est situe avant la
	 * fin du fichier.
	 */
	if (sqform->SQrd_rec >= sqform->SQnb_rec) {
		release_locks(ExternalHandle);
		return(48);
	}

	/* Calcule la position absolue de l'enregistrement */
	fidseek = (LSEEKTYPE) ((((LSEEKTYPE)sqform->SQrd_rec) * ((LSEEKTYPE)sqform->SQsz_rec))
			+ 256L);

	/* Effectue la lecture proprement dite */
	cpdu = _FFread(ExternalHandle,fidseek,buffer,(int)sqform->SQsz_rec,(LPINT)&lu);
	release_locks(ExternalHandle);

	/* Controle la lecture */
	if (cpdu != 0)
		return(cpdu);
	if (lu < (int)sqform->SQsz_rec)
		return(4);

	/* Met a jour le numero du prochain enregistrement a lire */
	sqform->SQrd_rec++;
	return(0);
}

/* --------------------------------------------------------------------------
 *
 * FCT _SQwrite
 *
 *      Ecriture d'un nouvel enregistrement.
 *
 *      E/ handle du fichier
 *         pointeur sur le tampon d'echange
 *         longueur en octets de ce tampon
 *      S/ compte-rendu d'erreur : 0 si Ok
 *
 */
int WINAPI _SQwrite(ExternalHandle,buffer,buflen)
EHANDLE ExternalHandle;
CPTR buffer;
int buflen;
{ 
	LSEEKTYPE fidseek;
	int cpdu;
	int ecrit;
	TASKENVIRON SPTR EnEnv;
	S16 err;
	SQFORM SPTR sqform;

	/* Repositionne l'environnement courant */
	xcheckhandle(ExternalHandle);
	EnEnv = ExternalHandle->Owner;

	/* Recupere la structure d'informations sur le fichier */
	sqform = (SQFORM SPTR)&(ExternalHandle->sqform);

	/* Controle la longueur du tampon a emettre */
	if (buflen != (int)sqform->SQsz_rec)
		return(62);

	/* Lecture du secteur d'entete avec verrouillage */
	if (sq_ctrl(EnEnv,ExternalHandle,GET_SQFCB | LCK_SQFCB,sqform,(S16PTR)&err) != 0)
		return((int)err);

	/* Calcule la position absolue de l'enregistrement */
	fidseek = (LSEEKTYPE) ((((LSEEKTYPE)sqform->SQnb_rec) * ((LSEEKTYPE)sqform->SQsz_rec))
			    + 256L);

	/* Effectue l'ecriture proprement dite */
	cpdu = _FFwrite(ExternalHandle,fidseek,buffer,buflen,(LPINT)&ecrit);

	/* Controle l'ecriture */
	if (cpdu != 0) {
		release_locks(ExternalHandle);
		return(cpdu);
	}
	if (ecrit != (int)sqform->SQsz_rec) {
		release_locks(ExternalHandle);
		return(46);
	}

	/* Met a jour le nombre d'enregistrements et la position
	 * du prochain enregistrement a lire.
	 */
	sqform->SQrd_rec = sqform->SQnb_rec;
	sqform->SQnb_rec++;
	sqform->SQwr_rec = sqform->SQnb_rec;

	/* Met a jour le secteur d'entete dans le fichier lui-meme */
	if (sq_ctrl(EnEnv,ExternalHandle,MAJ_SQFCB,sqform,(S16PTR)&err) != 0)
		return((int)err);

	return(0);
}

/* --------------------------------------------------------------------------
 *
 * FCT _SQmodif
 *
 *      Modification d'un enregistrement.
 *
 *      E/ handle du fichier
 *         pointeur sur le tampon d'echange
 *         longueur en octets de ce tampon
 *      S/ compte-rendu d'erreur : 0 si Ok
 *
 */
int WINAPI _SQmodif(ExternalHandle,buffer,buflen)
EHANDLE ExternalHandle;
CPTR buffer;
int buflen;
{ 
	LSEEKTYPE	fidseek;
	S16 		err;
	int 		cpdu;
	int 		ecrit;
	TASKENVIRON SPTR EnEnv;
	SQFORM SPTR 	sqform;

	/* Repositionne l'environnement courant */
	xcheckhandle(ExternalHandle);
	EnEnv = ExternalHandle->Owner;

	/* Recupere la structure d'informations sur le fichier */
	sqform = (SQFORM SPTR)&(ExternalHandle->sqform);

	/* Controle la longueur du tampon a emettre */
	if (buflen != (int)sqform->SQsz_rec)
		return(62);

	/* Lecture du secteur d'entete sans verrouillage */
	if (sq_ctrl(EnEnv,ExternalHandle,GET_SQFCB,sqform,(S16PTR)&err) != 0)
		return((int)err);

	/* Verifie que le pointeur de lecture n'est pas au-dela
	 * de la fin du fichier.
	 */
	if (sqform->SQrd_rec >= sqform->SQnb_rec) {
		release_locks(ExternalHandle);
		return(48);
	}

	/* Calcule la position absolue de l'enregistrement */
	fidseek = (LSEEKTYPE) ((((LSEEKTYPE)sqform->SQrd_rec) * ((LSEEKTYPE)sqform->SQsz_rec))
			    + 256L);

	/* Effectue l'ecriture proprement dite */
	cpdu = _FFwrite(ExternalHandle,fidseek,buffer,buflen,(LPINT)&ecrit);
	release_locks(ExternalHandle);

	/* Controle l'ecriture */
	if (cpdu != 0)
		return(cpdu);
	if (ecrit != (int)sqform->SQsz_rec)
		return(46);

	return(0);
}

/* --------------------------------------------------------------------------
 *
 * FCT _SQrewind
 *
 *      Positionnement sur le premier enregistrement.
 *
 *      E/ handle du fichier
 *      S/ compte-rendu d'erreur : 0 si Ok
 *
 */
int WINAPI _SQrewind(ExternalHandle)
EHANDLE ExternalHandle;
{ SQFORM SPTR sqform;

	/* Recupere la structure d'informations sur le fichier */
	xcheckhandle(ExternalHandle);
	sqform = (SQFORM SPTR)&(ExternalHandle->sqform);

	/* Verifie que l'on n'essaie pas de revenir avant le
	 * debut du fichier.
	 */
	if (sqform->SQrd_rec > 0) {
		sqform->SQrd_rec--;
		return(0);
	}
	else {
		return(64);
	}
}

/* --------------------------------------------------------------------------
 *
 * FCT _SQrename
 *
 *      Renommage d'un fichier.
 *
 *      E/ handle du fichier
 *         pointeur sur le nouveau nom de fichier, termine par \0
 *      S/ compte-rendu d'erreur : 0 si Ok
 *
 */
int WINAPI _SQrename(ExternalHandle,nom)
EHANDLE ExternalHandle;
LPSTR nom;
{
	/* Renommage de fichier au niveau acces direct */
	return(_FFrename(ExternalHandle,nom));
}

/* --------------------------------------------------------------------------
 *
 * FCT release_locks
 *
 *      Enleve le verrouillage exclusif du secteur d'entete.
 *
 *      E/ handle externe du fichier
 *      S/ rien
 *
 */
static void release_locks(ExternalHandle)
EHANDLE ExternalHandle;
{
	/* Demande la liberation du verrouillage du secteur d'entete */
	(void)AbalUnlock(ExternalHandle,LCK_58_STA,1L);
}

/* --------------------------------------------------------------------------
 *
 * FCT sq_ctrl
 *
 *      Gestion du secteur d'entete d'un fichier sequentiel pur.
 *
 *      E/ pointeur sur l'environnement courant
 *         handle externe du fichier
 *         mode de gestion (read lock, read no lock, write)
 *         pointeur sur structure d'informations sur le fichier
 *         pointeur sur une variable de reception d'erreur
 *      S/ compte-rendu de la fonction : 0 si Ok, 0xFFFF si pas Ok
 *
 */
static U16 sq_ctrl(EnEnv,ExternalHandle,mode,sqform,erreur)
TASKENVIRON SPTR EnEnv;
EHANDLE ExternalHandle;
U16 mode;
SQFORM SPTR sqform;
S16PTR erreur;
{
  U8 buf[256];
  U16 lockstate;
  int cpdu;
  int ech;

	/* Pas d'erreur par defaut */
	*erreur = 0;

	/* S'agit-il d'une commande de lecture du secteur d'entete ? */
	if ((mode & GET_SQFCB) != 0) {
		/* En lecture, on verrouille le secteur d'entete */
		while(1) {
			fl_xabqt(EnEnv);
			lockstate = AbalLock(ExternalHandle,LCK_58_STA,1L);

			/* Selon le cas, on boucle, c'est verrouille ou bien
			 * encore on remonte l'erreur a l'appelant.
			 */
			if (lockstate == 0)
				break;
			else if (lockstate == 74) {
				continue;
			}
			else {
				*erreur = lockstate;
				return(0xFFFF);
			}
		}

		/* Lecture du secteur d'entete */
		cpdu = _FFread(ExternalHandle,(LSEEKTYPE)0,(CPTR)buf,8,(LPINT)&ech);

		/* Traite les cas d'erreurs */
		if (cpdu != 0) {
			release_locks(ExternalHandle);
			*erreur = (S16)cpdu;
			return(0xFFFF);
		}
		if (ech < 8) {
			release_locks(ExternalHandle);
			*erreur = 48;
			return(0xFFFF);
		}

		/* Transfere les informations interessantes */
		sqform->SQnb_rec = (U32)U32INVread((U8PTR)buf+4);
		sqform->SQsz_rec = (U16)U16INVread((U8PTR)buf+2);

		return(0);
	}
	else {
		/* En ecriture, on libere le verrouillage apres s'etre
		 * assure du bon deroulement de l'ecriture.
		 * On commence par transferer les informations interessantes
		 */

		/* On complete le secteur avec des zeros binaires */
		fl_xmemset((CPTR)buf, 0, 256);

		U32INVwrite(sqform->SQnb_rec,(U8PTR)buf+4);
		U16INVwrite(sqform->SQsz_rec,(U8PTR)buf+2);

		/* Et on l'ecrit effectivement */
		cpdu = _FFwrite(ExternalHandle,(LSEEKTYPE)0,(CPTR)buf,256,(LPINT)&ech);
		release_locks(ExternalHandle);

		/* Traite les cas d'erreurs */
		if (cpdu != 0) {
			*erreur = cpdu;
			return(0xFFFF);
		}
		if (ech != 256) {
			*erreur = 46;
			return(0xFFFF);
		}

		return(0);
	}
}


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*                      ASSURE LA PORTABILITE                                */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

union iu
{       U16 i;
	U8 p[2];
};


static U16 U16INVread( s )                       /* create a long from an MIF */
U8PTR s;
{ union iu x;

	x.i = 0;

#ifdef ISINTEL
	*( x.p     ) = *( s     );
	*( x.p + 1 ) = *( s + 1 );
#else
	*( x.p     ) = *( s + 1 );
	*( x.p + 1 ) = *( s     );
#endif

	return( x.i );
}


static void U16INVwrite( i,d )
U16 i;
U8PTR d;
{ union iu x;

	x.i = i;

#ifdef ISINTEL
	*( d     ) = *( x.p     );
	*( d + 1 ) = *( x.p + 1 );
#else
	*( d     ) = *( x.p + 1 );
	*( d + 1 ) = *( x.p     );
#endif
}


union lu
{       U32 l;
	U8 p[4];
};

static U32 U32INVread( s )                       /* create a long from an MIF */
U8PTR s;
{ union lu x;

	x.l = 0L;

#ifdef ISINTEL
	*( x.p     ) = *( s     );
	*( x.p + 1 ) = *( s + 1 );
	*( x.p + 2 ) = *( s + 2 );
	*( x.p + 3 ) = *( s + 3 );
#else
	*( x.p     ) = *( s + 3 );
	*( x.p + 1 ) = *( s + 2 );
	*( x.p + 2 ) = *( s + 1 );
	*( x.p + 3 ) = *( s     );
#endif

	return( x.l );
}

static void U32INVwrite( l,d )
U32 l;
U8PTR d;
{ union lu x;

	x.l = l;

#ifdef ISINTEL
	*( d     ) = *( x.p     );
	*( d + 1 ) = *( x.p + 1 );
	*( d + 2 ) = *( x.p + 2 );
	*( d + 3 ) = *( x.p + 3 );
#else
	*( d     ) = *( x.p + 3 );
	*( d + 1 ) = *( x.p + 2 );
	*( d + 2 ) = *( x.p + 1 );
	*( d + 3 ) = *( x.p     );
#endif
}

FILEHANDLE CopyHandle;

int	FFcopy_file_handle( ExternHandle )
	EHANDLE ExternHandle;
{
	memcpy(&CopyHandle,ExternHandle,sizeof( FILEHANDLE ));
	return(0);
}

int	FFcheck_file_handle( ExternHandle )
	EHANDLE ExternHandle;
{
	return( memcmp(&CopyHandle,ExternHandle,sizeof( FILEHANDLE ) ) );
}


