/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1995
 *	Module  : EXA
 *	Fichier : EXMAMC.C
 *	Version : 1.1b
 *	Date    : 22/10/95
 *	Systeme : Windows 3 / NT / MS-DOS / Unix
 *
 *	Executeur ABAL
 *
 *	[Interface methodes d'acces - Code (suite)]
 *
 */

/*T-------------------------------------------------------------------------
 *
 *	On implemente ici les fonctions proprement dites d'acces a
 *	CRITERIA : acces multicriteres.
 *
 * ------------------------------------------------------------------------- */


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			ACCES MULTICRITERES				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

int NOTFASTCALL EeE_IsamInfo(BPTR filename,BPTR pinfo)
{
	BPTR	eptr;
	if (!( eptr = getenv("EXALONGNAMES")))
		return(IsamInfo(filename,pinfo));
	else if ( *eptr == '1' )
		return(1);
	else if ( *eptr == '0' )
		return(0);
	else	return(0);
}

/***********************************************************************/
/*MC************ CREATE ************************************************/
/************************************************************************ 
; EX_FILE_HANDLE EeEmc_create(nom, perm, lcle, ldata, cadrage, lvar, perr);
; BPTR nom;	- nom du fichier, path complet, termine par un 0	;
; WORD perm;	- 	bit 0 = WR (1 = R/W, 0 = R/O : non exploite)	;
;			bit 1 = EX (1 = exclusif, 0 = partageable)	;
;			bit 2 = C  (1 = mode securite, 0 = mode copie)	;
;			bit 3 = DF (non exploite)			;
; WORD lcle;	- taille demandee pour la cle				;
; WORD ldata;	- taille demandee pour les donnees			;
; WORD cadrage;	- 0 pas de cadrage / 1 cadrage a gauche / 2 a droite	;
; WORD lvar;	- 0 lg fixe / 1 lg var					;
; WPTR perr;	- erreur						;
;	-->> le handle si OK, 0 sinon, perr positionnee			;
*************************************************************************/

EX_FILE_HANDLE NOTFASTCALL EeEmc_create(nom, perm, lcle, ldata, cadrage, lvar, perr)
	BPTR nom;
	WORD perm;
	WORD lcle;
	WORD ldata;
	WORD cadrage;
	WORD lvar;
	WPTR perr;
{
EHANDLE h;
int erreur, lgcle, lgdata;
WORD ex, cp;

	*perr=0;

	ex=(perm & 0x0002) ? (WORD)1 : (WORD)0;
	cp=(perm & 0x0004) ? (WORD)1 : (WORD)0;
	lgcle=(int)lcle; lgdata=(int)ldata;

	h=McIsamCreate((LPSTR)nom, (LPINT)&lgcle, (LPINT)&lgdata, (int)ex, (int)cp, (int)cadrage, (int)lvar, (LPINT)&erreur);

	if (h)
		{
		fidinfo1=(WORD)lgdata; fidinfo2=(WORD)lgcle;
		}
	else
		{ *perr=(WORD)erreur; }
		
	return((EX_FILE_HANDLE)h);
}

/***********************************************************************/
/*MC************ RENAME ************************************************/
/************************************************************************ 
; WORD EeEmc_rename(hfic, newname)					;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; BPTR newname		- nouveau nom					;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEmc_rename(hfic, newname)
	EX_FILE_HANDLE hfic;
	BPTR newname;
{
	while ((*newname==' ') || (*newname=='\t'))
		{ newname++; }
	if (*newname=='\0')	{ return(30); }

	return((WORD)McIsamRename((EHANDLE)hfic, (LPSTR)newname));
}

/***********************************************************************/
/*MC************ UNLINK ************************************************/
/************************************************************************ 
; WORD EeEmc_unlink(nom)						;
; BPTR nom		- nom du fichier a supprimer			;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEmc_unlink(nom)
	BPTR nom;
{
	return((WORD)McIsamUnlink((LPSTR)nom));
}

/***********************************************************************/
/*MC************ OPEN **************************************************/
/************************************************************************
; EX_FILE_HANDLE EeEmc_open(nom, perm, perr)				;
; BPTR nom;	- nom du fichier, path complet, termine par un 0	;
; WORD perm;	- 	bit 0 = WR (1 = R/W, 0 = R/O : non exploite)	;
;			bit 1 = EX (1 = exclusif, 0 = partageable)	;
;			bit 2 = C  (1 = mode securite, 0 = mode copie)	;
;			bit 3 = DF (non exploite)			;
; WPTR perr;	- erreur						;
;	-->> le handle si OK, 0 sinon, perr positionnee			;
*************************************************************************/

EX_FILE_HANDLE NOTFASTCALL EeEmc_open(nom, perm, perr)
	BPTR nom;
	WORD perm;
	WPTR perr;
{
EHANDLE h;
int erreur, lcle, ldata;
WORD ex, cp, wr;

	*perr=0;

	wr=(perm & 0x0001) ? (WORD)1 : (WORD)0;
	ex=(perm & 0x0002) ? (WORD)1 : (WORD)0;
	cp=(perm & 0x0004) ? (WORD)1 : (WORD)0;

	h=McIsamOpen((LPSTR)nom, (int)ex, (int)cp, (int)wr, (LPINT)&lcle, (LPINT)&ldata, (LPINT)&erreur);

	if (h)
		{
		fidinfo1=(WORD)ldata;
		fidinfo2=(WORD)lcle;
		return((EX_FILE_HANDLE)h);
		}
	else	{ 
		*perr=(WORD)erreur; return((EX_FILE_HANDLE)0);
		};
}

/***********************************************************************/
/*MC************ MATB **************************************************/
/************************************************************************
; WORD EeEmc_matb(hfic, perm)						;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; WORD perm;	- 	bit 0 = WR (1 = R/W, 0 = R/O : non exploite)	;
;			bit 1 = EX (1 = exclusif, 0 = partageable)	;
;			bit 2 = C  (1 = mode securite, 0 = mode copie)	;
;	-->> le code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEmc_matb(hfic, perm)
	EX_FILE_HANDLE hfic;
	WORD perm;
{
WORD ex, cp;
int erreur;

	ex=(perm & 0x0002) ? (WORD)1 : (WORD)0;
	cp=(perm & 0x0004) ? (WORD)1 : (WORD)0;

	/* si erreur lors du second atb, on ne peut defaire le premier	*/
	/* car on ne sait pas s'il etait necessaire			*/
	if (!(erreur=McIsamAtbOpen((HCRIT)hfic, (int)ex, 0)))
		erreur=McIsamAtbOpen((HCRIT)hfic, (int)cp, 1);

	return((WORD)erreur);
}

/***********************************************************************/
/*MC************ CLOSE *************************************************/
/************************************************************************ 
; WORD EeEmc_close(hfic)						;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEmc_close(hfic)
	EX_FILE_HANDLE hfic;
{
	return((WORD)McIsamClose((HCRIT)hfic));
}

/***********************************************************************/
/*MC************ INSERT ************************************************/
/************************************************************************ 
; WORD EeEmc_insert(hfic, pcle, marq, pdata, lg)			;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; BPTR pcle		- cle						;
; BYTE marq		- marqueur					;
; BPTR pdata		- donnees					;
; WORD lg		- lg de pdata					;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEmc_insert(hfic, pcle, marq, pdata, lg)
	EX_FILE_HANDLE hfic;
	BPTR pcle;
	BYTE marq;
	BPTR pdata;
	WORD lg;
{
	return((WORD)McIsamInsert((HCRIT)hfic, (CPTR)pcle, (int)marq, (CPTR)pdata, (int)lg));
}

/***********************************************************************/
/*MC************ DELETE ************************************************/
/************************************************************************
; WORD EeEmc_delete(hfic, pcle, marq)					;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; BPTR pcle		- cle						;
; BYTE marq		- marqueur					;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEmc_delete(hfic, pcle, marq)
	EX_FILE_HANDLE hfic;
	BPTR pcle;
	BYTE marq;
{
	return((WORD)McIsamDelete((HCRIT)hfic, (CPTR)pcle, (int)marq));
}

/***********************************************************************/
/*MC************ MODIF *************************************************/
/************************************************************************ 
; WORD EeEmc_modif(hfic, pcle, marq, pdata, lg)				;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; BPTR pcle		- cle						;
; BYTE marq		- marqueur					;
; BPTR pdata		- donnees					;
; WORD lg		- lg de pdata					;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEmc_modif(hfic, pcle, marq, pdata, lg)
	EX_FILE_HANDLE hfic;
	BPTR pcle;
	BYTE marq;
	BPTR pdata;
	WORD lg;
{
	return((WORD)McIsamModif((HCRIT)hfic, (CPTR)pcle, (int)marq, (CPTR)pdata, (int)lg));
}

/***********************************************************************/
/*MC************ SEARCH ************************************************/
/************************************************************************ 
; WORD EeEmc_search(hfic, lock, reslg, pcle, marq, pdon, lgr)		;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; WORD lock		- cf code exa					;
; WORD reslg		- cf code exa					;
; BPTR pcle		- cle						;
; BYTE marq		- marqueur					;
; BPTR pdata		- donnees					;
; WORD lgr		- lg de pdata					;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEmc_search(hfic, lock, reslg, pcle, marq, pdata, lgr)
	EX_FILE_HANDLE hfic;
	WORD lock;
	WORD reslg;
	BPTR pcle;
	BYTE marq;
	BPTR pdata;
	WORD lgr;
{
	return((WORD)EeEsimcbf_search(2, hfic, lock, reslg, pcle, marq, pdata, lgr));
}

/***********************************************************************/
/*MC************ DOWN **************************************************/
/************************************************************************ 
; WORD EeEmc_down(hfic, lock, reslg, marq, pdon, lgr)			;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; WORD lock		- cf code exa					;
; WORD reslg		- cf code exa					;
; BYTE marq		- marqueur					;
; BPTR pdata		- donnees					;
; WORD lgr		- lg de pdata					;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEmc_down(hfic, lock, reslg, marq, pdata, lgr)
	EX_FILE_HANDLE hfic;
	WORD lock;
	WORD reslg;
	BYTE marq;
	BPTR pdata;
	WORD lgr;
{
	return((WORD)EeEsimcbf_updown(1, 2, hfic, lock, reslg, marq, pdata, lgr));
}

/***********************************************************************/
/*MC************ UP ****************************************************/
/************************************************************************ 
; WORD EeEmc_up(hfic, lock, reslg, marq, pdon, lgr)			;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; WORD lock		- cf code exa					;
; WORD reslg		- cf code exa					;
; BYTE marq		- marqueur					;
; BPTR pdata		- donnees					;
; WORD lgr		- lg de pdata					;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEmc_up(hfic, lock, reslg, marq, pdata, lgr)
	EX_FILE_HANDLE hfic;
	WORD lock;
	WORD reslg;
	BYTE marq;
	BPTR pdata;
	WORD lgr;
{
	return((WORD)EeEsimcbf_updown(-1, 2, hfic, lock, reslg, marq, pdata, lgr));
}

/*--- CREATION KEY -----------------------------------------------------*/
/* WORD EeEmc_ckey(lFd, nom, taille, type)				*/
/* EX_FILE_HANDLE lFd	- handle du fichier				*/
/* BPTR nom		- nom de la rubrique padde a blancs sur 16	*/
/* WORD taille		- taille de la rubrique				*/
/* WORD type		- 1 si numerique, 0 sinon			*/
/*	-->> renvoie l'erreur						*/
/*----------------------------------------------------------------------*/
WORD NOTFASTCALL EeEmc_ckey(lFd, nom, taille, type)
	EX_FILE_HANDLE lFd;
	BPTR nom;
	WORD taille;
	WORD type;
{
	return((WORD)McIsamCkey((HCRIT)lFd, (CPTR)nom, (int)taille, (int)type));
}

/*--- MODIFICATION NOM RUBRIQUE ----------------------------------------*/
/* WORD EeEmc_nkey(lFd, anc, new)					*/
/* EX_FILE_HANDLE lFd	- handle du fichier				*/
/* BPTR anc		- ancien nom sur 16 padde a blancs		*/
/* BPTR new		- nouveau nom sur 16 padde a blancs		*/
/*	-->> renvoie l'erreur						*/
/*----------------------------------------------------------------------*/
WORD NOTFASTCALL EeEmc_nkey(lFd, anc, new)
	EX_FILE_HANDLE lFd;
	BPTR anc;
	BPTR new;
{
	return((WORD)McIsamNkey((HCRIT)lFd, (CPTR)anc, (CPTR)new));
}

/*--- REDEFINITION RUBRIQUE --------------------------------------------*/
/* WORD EeEmc_fkey(lFd, mere, fille, lg_fille, t_fille, o_fille)	*/
/* EX_FILE_HANDLE lFd	- handle du fichier				*/
/* BPTR mere		- nom de la mere (16 car paddes a blancs)	*/
/* BPTR fille		- nom de la fille (idem)			*/
/* WORD lg_fille		- taille fille				*/
/* WORD type_fille	- 0 alpha, 1 numerique				*/
/* WORD offset_fille	- offset fille dans mere			*/
/*	-->> renvoie l'erreur						*/
/*----------------------------------------------------------------------*/

WORD NOTFASTCALL EeEmc_fkey(lFd, mere, fille, lg_fille, t_fille, o_fille)
	EX_FILE_HANDLE lFd;
	BPTR mere;
	BPTR fille;
	WORD lg_fille;
	WORD t_fille;
	WORD o_fille;
{
	return((WORD)McIsamFkey((HCRIT)lFd, (CPTR)mere, (CPTR)fille, (int)lg_fille, (int)t_fille, (int)o_fille));
}

/*--- MISE A JOUR DES INDEX --------------------------------------------*/
/* WORD EeEmc_updndx(lFd)						*/
/* EX_FILE_HANDLE lFd	- handle du fichier				*/
/*	-->> renvoie l'erreur						*/
/*----------------------------------------------------------------------*/

WORD NOTFASTCALL EeEmc_updndx(lFd)
	EX_FILE_HANDLE lFd;
{
	return((WORD)McIsamUpdndx((HCRIT)lFd));
}

/*--- CREATION D'UN INDEX ----------------------------------------------*/
/* WORD EeEmc_cndx(lFd, desc, lg)					*/
/* EX_FILE_HANDLE lFd	- handle du fichier				*/
/* BPTR desc		- descripteur compatible PRL			*/
/* WORD lg		- taille du descripteur				*/
/*	-->> renvoie l'erreur						*/
/*----------------------------------------------------------------------*/

WORD NOTFASTCALL EeEmc_cndx(lFd, desc, lg)
	EX_FILE_HANDLE lFd;
	BPTR desc;
	WORD lg;
{
	return((WORD)McIsamCndx((HCRIT)lFd, (CPTR)desc, (int)lg));
}

/*--- SUPPRESSION D'UN INDEX -------------------------------------------*/
/* WORD EeEmc_dndx(lFd, desc, lg)					*/
/* EX_FILE_HANDLE lFd	- handle du fichier				*/
/* BPTR desc		- descripteur compatible PRL			*/
/* WORD lg		- taille du descripteur				*/
/*	-->> renvoie l'erreur						*/
/*----------------------------------------------------------------------*/

WORD NOTFASTCALL EeEmc_dndx(lFd, desc, lg)
	EX_FILE_HANDLE lFd;
	BPTR desc;
	WORD lg;
{
	return((WORD)McIsamDndx((HCRIT)lFd, (CPTR)desc, (int)lg));
}

/*--- PREPA CREATION D'UN INDEX ----------------------------------------*/
/* WORD EeEmc_dcndx(lFd, desc, lg)					*/
/* EX_FILE_HANDLE lFd	- handle du fichier				*/
/* BPTR desc		- descripteur compatible PRL			*/
/* WORD lg		- taille du descripteur				*/
/*	-->> renvoie l'erreur						*/
/*----------------------------------------------------------------------*/

WORD NOTFASTCALL EeEmc_dcndx(lFd, desc, lg)
	EX_FILE_HANDLE lFd;
	BPTR desc;
	WORD lg;
{
	return((WORD)McIsamDCndx((HCRIT)lFd, (CPTR)desc, (int)lg));
}

/*--- PREPA SUPPRESSION D'UN INDEX -------------------------------------*/
/* WORD EeEmc_ddndx(lFd, desc, lg)					*/
/* EX_FILE_HANDLE lFd	- handle du fichier				*/
/* BPTR desc		- descripteur compatible PRL			*/
/* WORD lg		- taille du descripteur				*/
/*	-->> renvoie l'erreur						*/
/*----------------------------------------------------------------------*/

WORD NOTFASTCALL EeEmc_ddndx(lFd, desc, lg)
	EX_FILE_HANDLE lFd;
	BPTR desc;
	WORD lg;
{
	return((WORD)McIsamDDndx((HCRIT)lFd, (CPTR)desc, (int)lg));
}

/*--- LISTE DES KEY ----------------------------------------------------*/
/* WORD EeEmc_lkey(lFd, desc, lg, type)					*/
/* EX_FILE_HANDLE lFd	- handle du fichier				*/
/* BPTR desc		- descripteur compatible PRL			*/
/* WORD lg		- lg du descripteur				*/
/* WORD type		- 0 : premier, 1 : suivant			*/
/*	-->> renvoie l'erreur						*/
/*----------------------------------------------------------------------*/

WORD NOTFASTCALL EeEmc_lkey(lFd, desc, lg, type)
	EX_FILE_HANDLE lFd;
	BPTR desc;
	WORD lg;
	WORD type;
{
	return((WORD)McIsamLkey((HCRIT)lFd, (CPTR)desc, (int)lg, (int)type));
}

/*--- LISTE DES INDEX --------------------------------------------------*/
/* WORD EeEmc_lndx(lFd, desc, lg, type)					*/
/* EX_FILE_HANDLE lFd	- handle du fichier				*/
/* BPTR desc		- descripteur compatible PRL			*/
/* WORD lg			- lg du descripteur			*/
/* WORD type		- 0 : premier, 1 : suivant			*/
/*	-->> renvoie l'erreur						*/
/*----------------------------------------------------------------------*/

WORD NOTFASTCALL EeEmc_lndx(lFd, desc, lg, type)
	EX_FILE_HANDLE lFd;
	BPTR desc;
	WORD lg;
	WORD type;
{
	return((WORD)McIsamLndx((HCRIT)lFd, (CPTR)desc, (int)lg, (int)type));
}

/*--- INFOS ------------------------------------------------------------*/
/* WORD EeEmc_info(lFd, desc, lg)					*/
/* EX_FILE_HANDLE lFd	- handle du fichier				*/
/* BPTR desc 		- descripteur SF du stat			*/
/* WORD lg		- longueur du buffer de transfert		*/
/*	-->> renvoie l'erreur						*/
/*----------------------------------------------------------------------*/

WORD NOTFASTCALL EeEmc_info(lFd, desc, lg)
	EX_FILE_HANDLE lFd;
	BPTR desc;
	WORD lg;
{
	return((WORD)McIsamInfo((HCRIT)lFd, (CPTR)desc, (int)lg));
}


/*--- COUNT ------------------------------------------------------------*/
/* WORD EeEmc_count(lFd, desc, ssdb, seq, lg, res)			*/
/* EX_FILE_HANDLE lFd	- handle du fichier				*/
/* BPTR desc		- descripteur de la requete PRL			*/
/* WORD ssdb		- 1 : sans les doublons				*/
/* WORD seq		- 1 : recherche sequent. si pas d'index		*/
/* WORD lg		- longueur du descripteur			*/
/* LONG SPTR res	- nombre de records selectionnes		*/
/*	-->> renvoie l'erreur						*/
/*----------------------------------------------------------------------*/

WORD NOTFASTCALL EeEmc_count(lFd, desc, ssdb, seq, lg, res)
	EX_FILE_HANDLE lFd;
	BPTR desc;
	WORD ssdb;
	WORD seq;
	WORD lg;
	LONG SPTR res;
{
LONG resultat;
WORD retour;
	retour=(WORD)McIsamCount((HCRIT)lFd, (CPTR)desc, (int)ssdb, (int)seq, (int)lg, (LPLONG)&resultat);
	if (!retour)	*res=(LONG)resultat;
	return(retour);
}

/*--- POSIT ------------------------------------------------------------*/
/* WORD EeEmc_posit(lFd, desc, ssdb, seq, dernier, lg, res)		*/
/* EX_FILE_HANDLE lFd	- handle du fichier				*/
/* BPTR desc		- descripteur de la requete PRL			*/
/* WORD ssdb		- 1 : sans les doublons				*/
/* WORD seq		- 1 : recherche sequentielle si pas d'index	*/
/* WORD dernier		- 1 : a partir de la derniere reponse		*/
/* WORD lg		- longueur du descripteur			*/
/* WPTR res		- 0 si pas de reponse,  sinon			*/
/* LPTR res		- why not a long pointer ijm 11/12/2002		*/
/*	-->> renvoie l'erreur						*/
/*----------------------------------------------------------------------*/

WORD NOTFASTCALL EeEmc_posit(lFd, desc, ssdb, seq, dernier, lg, res)
	EX_FILE_HANDLE lFd;
	BPTR desc;
	WORD ssdb;
	WORD seq;
	WORD dernier;
	WORD lg;
	LPINT res;
{
int resultat;
WORD retour;

	retour=(WORD)McIsamPosit((HCRIT)lFd, (CPTR)desc, (int)ssdb, (int)seq, (int)dernier, (int)lg, (LPINT) res /*&resultat */);
/*	if (!retour)	*res=(WORD)resultat; */
	return(retour);
}

#ifdef	CRIVER40
/*--- COLLECT ------------------------------------------------------------------------	*/
/* WORD EeEmc_collect(lFd, desc,lg, ssdb,seq,mode,dernier,lgcle,clebuf,lgused,nombre)	*/
/* EX_FILE_HANDLE lFd	- handle du fichier						*/
/* BPTR desc		- descripteur de la requete PRL					*/
/* WORD lg		- length ofthe descripteur					*/
/* WORD ssdb		- 1 : sans les doublons						*/
/* WORD seq		- 1 : recherche sequentielle si pas d'index			*/
/* WORD mode		- 0 first , 1 next 						*/
/* WORD dernier		- 1 : a partir de la derniere reponse				*/
/* LPTR lgcle		- longueur des colonnes  					*/
/* BPTR buf		- buffer containing columns  					*/
/* LPTR maxbuf		- size of buffer available and used 				*/
/* LPTR nombre		- number of rows in all 	 				*/
/*	-->> renvoie l'erreur								*/
/*----------------------------------------------------------------------		*/

WORD NOTFASTCALL EeEmc_collect(lFd, desc, lg, ssdb, seq, mode, dernier, lgcle, clebuf, lgused, nombre)
	EX_FILE_HANDLE lFd;
	BPTR desc;
	WORD lg;
	WORD ssdb;
	WORD seq;
	WORD mode;
	WORD dernier;
	LPINT lgcle;
	BPTR  clebuf;
	LPINT lgused;
	LPINT nombre;
{
	LONG resultat=0;
	WORD retour;
	retour=(WORD)McIsamCollect(
				(HCRIT)lFd, 
				(CPTR)desc,(int) lg, 
				(int)ssdb, (int)seq,(int) mode, (int)dernier, 
				(LPINT) lgcle, (BPTR) clebuf, (LPINT) lgused, (LPLONG) &resultat);
	if (!retour) *nombre=(WORD)resultat; 
	return(retour);
}

#endif

