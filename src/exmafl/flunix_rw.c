/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1997
 *	Module  : EXA
 *	Fichier : FLUNIX.C
 *	Version : 1.1b
 *	Date    : 10/04/97
 *	Systeme : Unix
 *
 *	Methodes d'acces
 *
 *	[DLL acces direct + sequentiel - Code]
 *
 */


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*		FONCTIONS IMPLEMENTEES EN MACROS			     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#define fl_xabqt(a)
#define fl_xsprintf		sprintf
#define fl_xstrlen		strlen
#define fl_xwrite		write
#define fl_xread		read
#ifdef	VERSION666
#define fl_xlseek		lseek64
#else
#define fl_xlseek		lseek
#endif
#define fl_xstrcpy		strcpy
#define fl_xmemcpy		memcpy
#define fl_xmemmove		cmemmove
#define fl_xmemset		memset
#define fl_xmalloc		malloc
#define fl_xfree		free

/* Controle de validite des handles */
#define xcheckhandle(x)	(void)0;


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*		FONCTIONS DE BAS NIVEAU DEPENDANT DU SYSTEME		     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* --------------------------------------------------------------------------
 *
 * FCT fl_xopen
 *
 *	Ouverture de fichier.
 *
 *	E/ pointeur sur le nom du fichier
 *	   indicateur de partageabilite
 *	   indicateur de securite  1=securite ; 0=copie
 *	   pointeur sur zone de reception de compte-rendu d'erreur
 *	S/ handle du fichier, HNLOG_ERROR si erreur
 *
 */
static HNLOG fl_xopen(FileName,ex,cop,err)
CPTR FileName;
S32 ex;
S32 cop;
S16PTR err;
{ HNLOG h;
  S16 oflag;

	*err = (S16)0;	

	if(cop == 1)	/* mode securite */
		oflag = O_RDWR | O_SYNC ;
	else		/* mode copie */
	  	oflag = O_RDWR ;

	h = open((CPTR)FileName,oflag);
	if (h == HNLOG_ERROR) {
		*err = (S16)ErrorConvBib((S16)errno);
		return(h);
	}

	if (ex == -1)	/* pas de gestion Access	*/
		return(h);

	/* gestion Access	*/
	if (Access((char *)FileName, 0, (int)ex)) {
	
		/* bidouille pour recuperer incoherence recup   */
		/* erreur de Access				*/
		if ((errno == 44) || (errno == 56) || (errno == 42) ||
		    (errno == 666) || (errno == 667))	*err=(S16)errno;
		else					*err=(S16)ErrorConvBib((S16)errno);
		fl_xclose(h);
		return(HNLOG_ERROR);
	}
	return(h);
}

/* --------------------------------------------------------------------------
 *
 * FCT fl_xcreate
 *
 *	Creation de fichier.
 *
 *	E/ pointeur sur le nom du fichier
 *	   indicateur de partageabilite
 *	   indicateur de securite
 *	   pointeur sur zone de reception de compte-rendu d'erreur
 *	S/ handle du fichier, HNLOG_ERROR si erreur
 *
 */
static HNLOG fl_xcreate(FileName,ex,cop,err)
CPTR FileName;
S32 ex;
S32 cop;
S16PTR err;
{ HNLOG h;
	
	*err = 0;

	/* Regarde si le fichier existe deja */
	if(access(FileName,F_OK) == 0) {
		*err = (S16)41;		/* fichier existe deja */
		return(HNLOG_ERROR);
	}

	if((h=creat((CPTR)FileName,0666)) == HNLOG_ERROR) {
		*err = ErrorConvBib((S16)errno);
		return(h);
	}
	fl_xclose(h);

	if ((h=fl_xopen(FileName, ex, cop, err)) == HNLOG_ERROR) {
		unlink((CPTR)FileName);
		return(h);
	}
	return(h);
}

/* --------------------------------------------------------------------------
 *
 * FCT fl_xunlink
 *
 *	Suppression de fichier.
 *
 *	E/ pointeur sur le nom du fichier
 *	S/ compte-rendu : 0 si Ok
 *
 */
static S16 fl_xunlink(nom)
CPTR nom;
{
#ifdef LINUX
	int h;
#else
	HNLOG h;
#endif

	h = unlink((CPTR)nom);
#ifdef LINUX
	if (h < 0) return(ErrorConvBib(errno));
	else			return(0);
#else		
	if (h == HNLOG_ERROR)	return(ErrorConvBib((S16)errno));
	else			return(0);
#endif
}
/* --------------------------------------------------------------------------
 *
 * FCT cmemmove
 *
 *	Copie memoire a memoire avec gestion des recouvrements.
 *
 *	E/ pointeur sur la zone de reception
 *	   pointeur sur la zone de depart
 *	   nombre d'octets a copier
 *	S/ rien
 *
 */
static void cmemmove(arriv, source, ln)
BPTR arriv;
BPTR source;
U16 ln;
{ U16 i;

	if (arriv < source) {
		for (i = 0 ; i < ln ; i++) {
			*(arriv+i) = *(source+i);
		}
	}
	else {
		for (i = ln ; i != 0 ; i--) {
			*(arriv+i-1) = *(source+i-1);
		}
	}
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			CONVERSION DES ERREURS				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* --------------------------------------------------------------------------
 *
 * FCT ErrorConvBib (DOS/UNIX)
 *
 *	Convertit une erreur Bib en erreur ABAL.
 *
 *	E/ numero d'erreur Bib
 *	S/ numero d'erreur ABAL (convention d'erreurs Amenesik / Sologic)
 *
 */
static S16 ErrorConvBib(erreur)
S16 erreur;
{ S16 err;

switch (erreur) {
	case EPERM	:	/* 001  Not super-user 			*/
		err = 58; break;	/* Fct interdite par la config	*/
#ifndef LINUX
	case EBADSLT	:	/* 055	Invalid slot			*/
#endif
	case ENOENT	:	/* 002	No such file or directory 	*/
		err = 40; break;	/* Fic non trouve ou acces impos*/
	case ESRCH	:	/* 003	No such process 		*/
		err = 23; break; 	/* ???				*/
	case EINTR	:	/* 004	Interrupted system call */
	case EIO	:	/* 005	I/O error 			*/
		err = 2; break; 	/* erreur de lecture ecriture	*/
	case ENXIO	:	/* 006	No such device or address 	*/
		err = 53; break; 	/* adresse fichier incorrecte	*/
	case E2BIG	:	/* 007	Arg list too long 		*/
	case ENAMETOOLONG:	/* 078  path arg length too long	*/
		err = 30; break; 	/* erreur de syntaxe		*/
	case ENOEXEC	:	/* 008  Exec format error 		*/
		err = 36; break; 	/* structure de fichier incorrec*/
	case EBADF	:	/* 009  Bad file number */
		err = 50; break; 	/* numero logique invalide	*/
	case ECHILD	:	/* 010	No children			*/
		err = 20; break; 	/* parametre d'appel incorrect	*/
	case EAGAIN	:	/* 011  No more processes 		*/
		err = 24; break; 	/* ???				*/
	case EACCES	:	/* 013 	Permission denied		*/
		err = 58; break; 	/* fonction interdite par config*/
	case EFAULT	:	/* 014	Bad address			*/
		err = 53; break; 	/* adresse fichier incorrecte	*/
	case ENOTBLK	:	/* 015	Block device required 		*/
		err = 60; break; 	/* type de fichier incorrect	*/
	case EBUSY	:	/* 016	Mount device busy 		*/
		err = 44; break; 	/* fichier deja ouvert non parta*/
	case EEXIST	:	/* 017 	File exists			*/
		err = 41; break; 	/* fichier deja existant	*/
	case ENODEV	:	/* 019	No such device */
		err = 40; break; 	/* fichier inex ou acces imposs */
	case ENOTDIR	:	/* 020	Not a directory */
	case EISDIR	:	/* 021	Is a directory */
		err = 30; break; 	/* erreur de syntaxe		*/
	case EINVAL	:	/* 022	Invalid argument 		*/
		err = 20; break; 	/* parametre d'appel incorrect	*/
	case EMFILE	:	/* 024	Too many open files		*/
		err = 51; break; 	/* trop de fichiers ouverts	*/
	case ETXTBSY	:	/* 026	Text file busy 			*/
		err = 44; break; 	/* fichier deja ouvert non parta*/
	case EFBIG	:	/* 027	File too large 			*/
		err = 45; break;	/* fichier trop grand		*/
	case EDEADLK	:	/* 045	Lockf DeadLock	 		*/
	case ENOLCK	:	/* 046	No More Systeme Locks 		*/
#ifndef LINUX
	case EDEADLOCK	:	/* 056  file locking deadlock error	*/
#endif
		err = 134; break;	/* saturation nb verrous	*/
	case ENOSPC	:	/* 028 	No space left on device 	*/
		err = 46; break; 	/* debordement de volume	*/
	case ESPIPE	:	/* 029	Illegal seek			*/
		err = 53; break; 	/* adresse fichier incorrecte	*/
	case EROFS	:	/* 030	Read only file system 		*/
		err = 47; break; 	/* droits d'acces incorrects	*/
	case EDOM	:	/* 033	Math arg out of domain of func 	*/
	case ERANGE	:	/* 034	Math result not representable 	*/
		err = 108; break; 	/* debordement arithmetique	*/
	case ENFILE  	:	/* 023	File table overflow		*/
		err = 72; break;	/* trop de fihiers ouverts (SI)	*/
	case ENOMEM	:	/* 012  memoire insuffisante  		*/
		err = 27; break;
	case ENOSYS	:	/* 089  functionality is not supported  */
		err = 56; break;	/* function non supportee	*/
	case ECOMM	:	/* 070  Communication error on send	*/
		err =224; break;	/* rupture de connexion		*/
#ifdef UNIXWARE
	case EXDEV	:
		err =56; break;		/*rename sur Cross device imposs */
#endif
	case EIDRM:
	case ENOMSG:
	default :
		err=erreur+1000;
	}
return(err);
}


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			VERROUILLAGE D'ENREGISTREMENT			     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* --------------------------------------------------------------------------
 *
 * FCT AbalLock (ISUNIX)
 *
 *	Verrouille une zone d'un fichier.
 *
 *	E/ handle externe du fichier
 *	   offset absolu de la zone a verrouiller
 *	   longueur de cette zone
 *	S/ compte-rendu d'erreur : 0 si Ok
 *
 */
static U16 AbalLock(ExternalHandle,offset,len)
EHANDLE ExternalHandle;
U32 offset;
U32 len;
{ U16 cpdu;

	/* Effectue le positionnement dans le fichier */
	if (fl_xlseek((HNLOG)ExternalHandle->OriginalHandle,(LSEEKTYPE)offset,SEEK_SET) == (S32)-1) {
		return(53);
	}

	/* Met en place le verrou */
	if (lockf(ExternalHandle->OriginalHandle,F_TLOCK,len) == 0)
		return(0);

	/* Traite le compte-rendu */
	if(errno == EACCES)
		cpdu = 74;
	else
		cpdu = ErrorConvBib((S16)errno);
	return(cpdu);
}

/* --------------------------------------------------------------------------
 *
 * FCT AbalUnlock (ISUNIX)
 *
 *	Deverrouille une zone d'un fichier.
 *
 *	E/ handle externe du fichier
 *	   offset absolu de la zone a deverrouiller
 *	   longueur de cette zone
 *	S/ compte-rendu d'erreur : 0 si Ok
 *
 */
static U16 AbalUnlock(ExternalHandle,offset,len)
EHANDLE ExternalHandle;
U32 offset;
U32 len;
{ U16 cpdu;

	/* Effectue le positionnement dans le fichier */
	if (fl_xlseek((HNLOG)ExternalHandle->OriginalHandle,(LSEEKTYPE)offset,SEEK_SET) == (S32)-1) {
		return(53);	
	}

	/* Enleve le verrou */
	if (lockf(ExternalHandle->OriginalHandle, F_ULOCK,len) == 0)
		return(0);

	/* Traite le compte-rendu */
	if(errno == EACCES)
		cpdu = 74;
	else
		cpdu = ErrorConvBib((S16)errno);
	return(cpdu);
}


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			MISCELLANEOUS					     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* --------------------------------------------------------------------------
 *
 * FCT MakeCompleteName
 *
 *	Cree un nom de fichier non ambigu (avec chemin).
 *
 *	E/ pointeur sur l'environnement courant
 *	   pointeur sur le nom a analyser
 *	   pointeur sur le buffer de reception du nom non ambigu
 *	S/ compte-rendu : 0 si Ok
 *
 * Notes :
 *	Sous Unix, on se contente de faire un strcpy.
 *
 */
static S16 MakeCompleteName(Env,Source,Dest)
TASKENVIRON SPTR Env;
CPTR Source;
CPTR Dest;
{
	/* Copie le nom du fichier : considere comme complet sous Unix */
	fl_xstrcpy(Dest,Source);
	return((S16)0);
}

#ifdef __DEBUG__
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			TRACE DES REQUETES				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* --------------------------------------------------------------------------
 *
 * FCT TraceBegin
 *
 *	Cree le fichier de trace des requetes AD et SQ.
 *
 *	E/ rien
 *	S/ rien
 *
 */
void TraceBegin(void)
{
  HNLOG TraceFile;
  S16 erreur;

	TraceFile= fl_xcreate((CPTR)"flfile.trc",0,0,(S16PTR)&erreur);
	if (TraceFile != HNLOG_ERROR)
	{
		fl_xclose(TraceFile);
		liberlox((char *)"flfile.trc");
	}
	return;
}
#endif 		/* __DEBUG__ */

