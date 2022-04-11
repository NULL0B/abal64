/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1995
 *	Module  : EXA
 *	Fichier : EXMABD.C
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
 *	CRITERIA : acces base de donnees relationnelle.
 *
 * ------------------------------------------------------------------------- */


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			ACCES BASE DE DONNEES				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/***********************************************************************/
/*BD************ CREATE DICO *******************************************/
/************************************************************************ 
; EX_FILE_HANDLE EeEbd_create(nom, perm, perr)				;
; BPTR nom;	- nom du fichier, path complet, termine par un 0	;
; WORD perm;	- 	bit 0 = WR (1 = R/W, 0 = R/O : non exploite)	;
;			bit 1 = EX (1 = exclusif, 0 = partageable)	;
;			bit 2 = C  (1 = mode securite, 0 = mode copie)	;
;			bit 3 = DF (non exploite)			;
; WPTR perr;	- erreur						;
;	-->> le handle si OK, 0 sinon, perr positionnee			;
*************************************************************************/
EX_FILE_HANDLE NOTFASTCALL EeEbd_create(nom, perm, perr)
	BPTR nom;
	WORD perm;
	WPTR perr;
{
EHANDLE h;
int erreur;
WORD ex, cp;

	ex=(perm & 0x0002) ? (WORD)1 : (WORD)0;
	cp=(perm & 0x0004) ? (WORD)1 : (WORD)0;

	h=BdIsamCreate((LPSTR)nom, (int)ex, (int)cp, (LPINT)&erreur);
	*perr=(WORD)erreur;

	return((EX_FILE_HANDLE)h);
}

/***********************************************************************/
/*BD************ RENAME DICO *******************************************/
/************************************************************************ 
; WORD EeEbd_rename(hfic, newname)					;
; EX_FILE_HANDLE hfic	- handle du dico   				;
; BPTR newname		- nouveau nom					;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEbd_rename(hfic, newname)
	EX_FILE_HANDLE hfic;
	BPTR newname;
{
	while ((*newname==' ') || (*newname=='\t'))
		{ newname++; }
	if (*newname=='\0')	{ return(30); }

	return((WORD)BdIsamRename((EHANDLE)hfic, (LPSTR)newname));
}

/***********************************************************************/
/*BD************ UNLINK DICO *******************************************/
/************************************************************************ 
; WORD EeEbd_unlink(nom)						;
; BPTR nom		- nom du fichier a supprimer			;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEbd_unlink(nom)
	BPTR nom;
{
	return((WORD)BdIsamUnlink((LPSTR)nom));
}

/***********************************************************************/
/*BD************ OPEN DICO *********************************************/
/************************************************************************
; EX_FILE_HANDLE EeEbd_open(nom, perm, perr)				;
; BPTR nom;	- nom du fichier, path complet, termine par un 0	;
; WORD perm;	- 	bit 0 = WR (1 = R/W, 0 = R/O : non exploite)	;
;			bit 1 = EX (1 = exclusif, 0 = partageable)	;
;			bit 2 = C  (1 = mode securite, 0 = mode copie)	;
;			bit 3 = DF (non exploite)			;
; WPTR perr;	- erreur						;
;	-->> le handle si OK, 0 sinon, perr positionnee			;
*************************************************************************/

EX_FILE_HANDLE NOTFASTCALL EeEbd_open(nom, perm, perr)
	BPTR nom;
	WORD perm;
	WPTR perr;
{
EHANDLE h;
int erreur;
WORD ex, cp, wr;

	wr=(perm & 0x0001) ? (WORD)1 : (WORD)0;
	ex=(perm & 0x0002) ? (WORD)1 : (WORD)0;
	cp=(perm & 0x0004) ? (WORD)1 : (WORD)0;

	h=BdIsamOpen((LPSTR)nom, (int)ex, (int)cp, (int)wr, (LPINT)&erreur);
	*perr=(WORD)erreur;
	
	return((EX_FILE_HANDLE)h);
}

/***********************************************************************/
/*BD************ MATB **************************************************/
/************************************************************************ 
; WORD EeEbd_matb(hfic, perm)						;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; WORD perm;	- 	bit 0 = WR (1 = R/W, 0 = R/O : non exploite)	;
;			bit 1 = EX (1 = exclusif, 0 = partageable)	;
;			bit 2 = C  (1 = mode securite, 0 = mode copie)	;
;	-->> le code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEbd_matb(hfic, perm)
	EX_FILE_HANDLE hfic;
	WORD perm;
{
WORD ex, cp;
int erreur;

	ex=(perm & 0x0002) ? (WORD)1 : (WORD)0;
	cp=(perm & 0x0004) ? (WORD)1 : (WORD)0;

	/* si erreur lors du second atb, on ne peut defaire le premier	*/
	/* car on ne sait pas s'il etait necessaire			*/
	if (!(erreur=BdIsamAtbOpen((HCRIT)hfic, (int)ex, 0)))
		erreur=BdIsamAtbOpen((HCRIT)hfic, (int)cp, 1);

	return((WORD)erreur);
}

/***********************************************************************/
/*BD************ CLOSE DICO ********************************************/
/************************************************************************
; WORD EeEbd_close(hfic)						;
; EX_FILE_HANDLE hfic	- handle du dico   				;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEbd_close(hfic)
	EX_FILE_HANDLE hfic;
{
	return((WORD)BdIsamClose((HCRIT)hfic));
}

/***********************************************************************/
/*BD************ CREATE FILE *******************************************/
/************************************************************************ 
; EX_FILE_HANDLE EeEbf_create(nom, perm, lcle, ldata, cadrage, lvar, hdico, perr);
; BPTR nom;	- nom du fichier, path complet, termine par un 0	;
; WORD perm;	- 	bit 0 = WR (1 = R/W, 0 = R/O : non exploite)	;
;			bit 1 = EX (1 = exclusif, 0 = partageable)	;
;			bit 2 = C  (1 = mode securite, 0 = mode copie)	;
;			bit 3 = DF (non exploite)			;
; WORD lcle;	- taille demandee pour la cle				;
; WORD ldata;	- taille demandee pour les donnees			;
; WORD cadrage;	- 0 pas de cadrage / 1 cadrage a gauche / 2 a droite	;
; WORD lvar;	- 0 lg fixe / 1 lg var					;
; EX_FILE_HANDLE hdico;	- handle du dico				;
; WPTR perr;	- erreur						;
;	-->> le handle si OK, 0 sinon, perr positionnee			;
*************************************************************************/

EX_FILE_HANDLE NOTFASTCALL EeEbf_create(nom, perm, lcle, ldata, cadrage, lvar, hdico, perr)
	BPTR nom;
	WORD perm;
	WORD lcle;
	WORD ldata;
	WORD cadrage;
	WORD lvar;
	EX_FILE_HANDLE hdico;
	WPTR perr;
{
EHANDLE h;
int erreur, lgcle, lgdata;
WORD ex, cp;

	*perr=0;

	ex=(perm & 0x0002) ? (WORD)1 : (WORD)0;
	cp=(perm & 0x0004) ? (WORD)1 : (WORD)0;
	lgcle=(int)lcle; lgdata=(int)ldata;

	h=BdIsamCreateFile((LPSTR)nom, (HCRIT)hdico, (LPINT)&lgcle, (LPINT)&lgdata, (int)ex, (int)cp, (int)cadrage, (int)lvar, (LPINT)&erreur);

	if (h)
		{
		fidinfo1=(WORD)lgdata; fidinfo2=(WORD)lgcle;
		}
	else
		{ *perr=(WORD)erreur; }
		
	return((EX_FILE_HANDLE)h);
}

/***********************************************************************/
/*BD************ RENAME FILE *******************************************/
/************************************************************************ 
; WORD EeEbf_rename(hfic, newname)					;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; BPTR newname		- nouveau nom					;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEbf_rename(hfic, newname)
	EX_FILE_HANDLE hfic;
	BPTR newname;
{
	while ((*newname==' ') || (*newname=='\t'))
		{ newname++; }
	if (*newname=='\0')	{ return(30); }

	return((WORD)BdIsamRenameFile((EHANDLE)hfic, (LPSTR)newname));
}

/***********************************************************************/
/*BD************ UNLINK FILE *******************************************/
/************************************************************************
; WORD EeEbf_unlink(nom, hdico, type)					;
; BPTR nom		- nom du fichier a supprimer			;
; EX_FILE_HANDLE hdico	- handle du dictionnaire			;
; WORD type		- 0 : BD vers MC /// 1 : BD vers BD ///		;
;				2 : BD vers rien			;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEbf_unlink(nom, hdico, type)
	BPTR nom;
	EX_FILE_HANDLE hdico;
	WORD type;
{
#ifdef AIX_VERS
#ifdef UNIXWARE
	WORD ret;
	ret = (WORD)BdIsamUnlinkFile((LPSTR)nom, (HCRIT)hdico, (int)type);
	return(ret);
#else
	return((WORD)BdIsamUnlinkFile((LPSTR)nom, (HCRIT)hdico, (int)type));
#endif
#else  /* AIX_VERS */
	return((WORD)BdIsamUnlinkFile((LPSTR)nom, (HCRIT)hdico, (int)type));
#endif /* AIX_VERS */
}

/***********************************************************************/
/*BD************ OPEN FILE *********************************************/
/************************************************************************ 
; EX_FILE_HANDLE EeEbf_open(nom, perm, hdico, perr)				;
; BPTR nom;	- nom du fichier, path complet, termine par un 0	;
; WORD perm;	- 	bit 0 = WR (1 = R/W, 0 = R/O : non exploite)	;
;			bit 1 = EX (1 = exclusif, 0 = partageable)	;
;			bit 2 = C  (1 = mode securite, 0 = mode copie)	;
;			bit 3 = DF (non exploite)			;
; EX_FILE_HANDLE hdico		- handle du dico			;
; WPTR perr;	- erreur						;
;	-->> le handle si OK, 0 sinon, perr positionnee			;
*************************************************************************/

EX_FILE_HANDLE NOTFASTCALL EeEbf_open(nom, perm, hdico, perr)
	BPTR nom;
	WORD perm;
	EX_FILE_HANDLE hdico;
	WPTR perr;
{
EHANDLE h;
int erreur, lcle, ldata;
WORD ex, cp, wr;

	*perr=0;

	wr=(perm & 0x0001) ? (WORD)1 : (WORD)0;
	ex=(perm & 0x0002) ? (WORD)1 : (WORD)0;
	cp=(perm & 0x0004) ? (WORD)1 : (WORD)0;

	h=BdIsamOpenFile((LPSTR)nom, (HCRIT)hdico, (int)ex, (int)cp, (int)wr, (LPINT)&lcle, (LPINT)&ldata, (LPINT)&erreur);

	if (h)
		{
		fidinfo1=(WORD)ldata;
		fidinfo2=(WORD)lcle;
		return((EX_FILE_HANDLE)h);
		}
	else	{ *perr=(WORD)erreur; return((EX_FILE_HANDLE)0);};
}

/***********************************************************************/
/*MC************ CLOSE FICHIER *****************************************/
/************************************************************************ 
; WORD EeEbf_close(hfic)						;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEbf_close(hfic)
	EX_FILE_HANDLE hfic;
{
	return(BdIsamCloseFile((HCRIT)hfic));
}

/***********************************************************************/
/*BD************ INSERT DANS FICHIER ***********************************/
/************************************************************************ 
; WORD EeEbf_insert(hfic, pcle, marq, pdata, lg)			;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; BPTR pcle		- cle						;
; BYTE marq		- marqueur					;
; BPTR pdata		- donnees					;
; WORD lg		- lg de pdata					;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEbf_insert(hfic, pcle, marq, pdata, lg)
	EX_FILE_HANDLE hfic;
	BPTR pcle;
	BYTE marq;
	BPTR pdata;
	WORD lg;
{
	return((WORD)BdIsamInsert((HCRIT)hfic, (CPTR)pcle, (int)marq, (CPTR)pdata, (int)lg));
}

/***********************************************************************/
/*BD************ DELETE DANS FICHIER ***********************************/
/************************************************************************ 
; WORD EeEbf_delete(hfic, pcle, marq)					;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; BPTR pcle		- cle						;
; BYTE marq		- marqueur					;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEbf_delete(hfic, pcle, marq)
	EX_FILE_HANDLE hfic;
	BPTR pcle;
	BYTE marq;
{
	return((WORD)BdIsamDelete((HCRIT)hfic, (CPTR)pcle, (int)marq));
}

/***********************************************************************/
/*BD************ MODIF DANS FICHIER ************************************/
/************************************************************************ 
; WORD EeEbf_modif(hfic, pcle, marq, pdata, lg)				;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; BPTR pcle		- cle						;
; BYTE marq		- marqueur					;
; BPTR pdata		- donnees					;
; WORD lg		- lg de pdata					;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEbf_modif(hfic, pcle, marq, pdata, lg)
	EX_FILE_HANDLE hfic;
	BPTR pcle;
	BYTE marq;
	BPTR pdata;
	WORD lg;
{
	return((WORD)BdIsamModif((HCRIT)hfic, (CPTR)pcle, (int)marq, (CPTR)pdata, (int)lg));
}

/***********************************************************************/
/*BD************ SEARCH FICHIER*****************************************/
/************************************************************************ 
; WORD EeEbf_search(hfic, lock, reslg, pcle, marq, pdon, lgr)		;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; WORD lock		- cf code exa					;
; WORD reslg		- cf code exa					;
; BPTR pcle		- cle						;
; BYTE marq		- marqueur					;
; BPTR pdata		- donnees					;
; WORD lgr		- lg de pdata					;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEbf_search(hfic, lock, reslg, pcle, marq, pdata, lgr)
	EX_FILE_HANDLE hfic;
	WORD lock;
	WORD reslg;
	BPTR pcle;
	BYTE marq;
	BPTR pdata;
	WORD lgr;
{
	return((WORD)EeEsimcbf_search(3, hfic, lock, reslg, pcle, marq, pdata, lgr));
}

/***********************************************************************/
/*BD************ DOWN FICHIER ******************************************/
/************************************************************************
; WORD EeEbf_down(hfic, lock, reslg, marq, pdon, lgr)			;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; WORD lock		- cf code exa					;
; WORD reslg		- cf code exa					;
; BYTE marq		- marqueur					;
; BPTR pdata		- donnees					;
; WORD lgr		- lg de pdata					;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEbf_down(hfic, lock, reslg, marq, pdata, lgr)
	EX_FILE_HANDLE hfic;
	WORD lock;
	WORD reslg;
	BYTE marq;
	BPTR pdata;
	WORD lgr;
{
	return((WORD)EeEsimcbf_updown(1, 3, hfic, lock, reslg, marq, pdata, lgr));
}

/***********************************************************************/
/*BD************ UP FICHIER ********************************************/
/************************************************************************ 
; WORD EeEbf_up(hfic, lock, reslg, marq, pdon, lgr)			;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; WORD lock		- cf code exa					;
; WORD reslg		- cf code exa					;
; BYTE marq		- marqueur					;
; BPTR pdata		- donnees					;
; WORD lgr		- lg de pdata					;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEbf_up(hfic, lock, reslg, marq, pdata, lgr)
	EX_FILE_HANDLE hfic;
	WORD lock;
	WORD reslg;
	BYTE marq;
	BPTR pdata;
	WORD lgr;
{
	return((WORD)EeEsimcbf_updown(-1, 3, hfic, lock, reslg, marq, pdata, lgr));
}

/*--- CREATION D'UNE RUBRIQUE ------------------------------------------*/
/* WORD EeEbd_ckey(lFd, nom, taille, type)				*/
/* Idem McIsamCkey							*/
/*----------------------------------------------------------------------*/
WORD NOTFASTCALL EeEbd_ckey(lFd, nom, taille, type)
	EX_FILE_HANDLE lFd;
	BPTR nom;
	WORD taille;
	WORD type;
{
	return((WORD)BdIsamCkey((HCRIT)lFd, (CPTR)nom, (int)taille, (int)type));
}

/*--- MODIFICATION NOM RUBRIQUE ----------------------------------------*/
/* WORD EeEbd_nkey(lFd, anc, new)					*/
/* EX_FILE_HANDLE lFd	- handle du fichier				*/
/* BPTR anc		- ancien nom sur 16 padde a blancs		*/
/* BPTR new		- nouveau nom sur 16 padde a blancs		*/
/*	-->> renvoie l'erreur						*/
/*----------------------------------------------------------------------*/
WORD NOTFASTCALL EeEbd_nkey(lFd, anc, new)
	EX_FILE_HANDLE lFd;
	BPTR anc;
	BPTR new;
{
	return((WORD)BdIsamNkey((HCRIT)lFd, (CPTR)anc, (CPTR)new));
}

/*--- REDEFINITION RUBRIQUE --------------------------------------------*/
/* WORD EeEbd_fkey(lFd, mere, fille, lg_fille, t_fille, o_fille)	*/
/* EX_FILE_HANDLE lFd	- handle du fichier				*/
/* BPTR mere		- nom de la mere (16 car paddes a blancs)	*/
/* BPTR fille		- nom de la fille (idem)			*/
/* WORD lg_fille		- taille fille				*/
/* WORD type_fille	- 0 alpha, 1 numerique				*/
/* WORD offset_fille	- offset fille dans mere			*/
/*	-->> renvoie l'erreur						*/
/*----------------------------------------------------------------------*/

WORD NOTFASTCALL EeEbd_fkey(lFd, mere, fille, lg_fille, t_fille, o_fille)
	EX_FILE_HANDLE lFd;
	BPTR mere;
	BPTR fille;
	WORD lg_fille;
	WORD t_fille;
	WORD o_fille;
{
	return((WORD)BdIsamFkey((HCRIT)lFd, (CPTR)mere, (CPTR)fille, (int)lg_fille, (int)t_fille, (int)o_fille));
}

/*--- MISE A JOUR DES INDEX --------------------------------------------*/
/* WORD EeEbd_updndx(lFd)						*/
/* EX_FILE_HANDLE lFd	- handle du fichier				*/
/*	-->> renvoie l'erreur						*/
/*----------------------------------------------------------------------*/

WORD NOTFASTCALL EeEbd_updndx(lFd)
	EX_FILE_HANDLE lFd;
{
	return((WORD)BdIsamUpdndx((HCRIT)lFd));
}

/*--- CREATION D'UN INDEX ----------------------------------------------*/
/* WORD EeEbd_cndx(lFd, desc, lg)					*/
/* EX_FILE_HANDLE lFd	- handle du fichier				*/
/* BPTR desc		- descripteur compatible PRL			*/
/* WORD lg		- taille du descripteur				*/
/*	-->> renvoie l'erreur						*/
/*----------------------------------------------------------------------*/

WORD NOTFASTCALL EeEbd_cndx(lFd, desc, lg)
	EX_FILE_HANDLE lFd;
	BPTR desc;
	WORD lg;
{
	return((WORD)BdIsamCndx((HCRIT)lFd, (CPTR)desc, (int)lg));
}

/*--- SUPPRESSION D'UN INDEX -------------------------------------------*/
/* WORD EeEbd_dndx(lFd, desc, lg)					*/
/* EX_FILE_HANDLE lFd	- handle du fichier				*/
/* BPTR desc		- descripteur compatible PRL			*/
/* WORD lg		- taille du descripteur				*/
/*	-->> renvoie l'erreur						*/
/*----------------------------------------------------------------------*/

WORD NOTFASTCALL EeEbd_dndx(lFd, desc, lg)
	EX_FILE_HANDLE lFd;
	BPTR desc;
	WORD lg;
{
	return((WORD)BdIsamDndx((HCRIT)lFd, (CPTR)desc, (int)lg));
}

/*--- PREPA CREATION D'UN INDEX ----------------------------------------*/
/* WORD EeEbd_dcndx(lFd, desc, lg)					*/
/* EX_FILE_HANDLE lFd	- handle du fichier				*/
/* BPTR desc		- descripteur compatible PRL			*/
/* WORD lg		- taille du descripteur				*/
/*	-->> renvoie l'erreur						*/
/*----------------------------------------------------------------------*/

WORD NOTFASTCALL EeEbd_dcndx(lFd, desc, lg)
	EX_FILE_HANDLE lFd;
	BPTR desc;
	WORD lg;
{
	return((WORD)BdIsamDCndx((HCRIT)lFd, (CPTR)desc, (int)lg));
}

/*--- PREPA SUPPRESSION D'UN INDEX -------------------------------------*/
/* WORD EeEbd_ddndx(lFd, desc, lg)					*/
/* EX_FILE_HANDLE lFd	- handle du fichier				*/
/* BPTR desc		- descripteur compatible PRL			*/
/* WORD lg		- taille du descripteur				*/
/*	-->> renvoie l'erreur						*/
/*----------------------------------------------------------------------*/

WORD NOTFASTCALL EeEbd_ddndx(lFd, desc, lg)
	EX_FILE_HANDLE lFd;
	BPTR desc;
	WORD lg;
{
	return((WORD)BdIsamDDndx((HCRIT)lFd, (CPTR)desc, (int)lg));
}

/*--- DESCRIPTION JOINTURE ---------------------------------------------*/
/* WORD EeEbd_join(lBd, desc, lg)					*/
/* EX_FILE_HANDLE lBd	- handle du dictionnaire			*/
/* BPTR desc		- descripteur compatible PRL			*/
/*		cb950217 : les deux premiers octets sont ignores par	*/
/*			CRITERIA et par les redirecteurs		*/
/*			(pour problemes de redirection TWinServer)	*/
/* WORD lg		- taille du descripteur				*/
/*	-->> renvoie un code erreur					*/
/*----------------------------------------------------------------------*/

WORD NOTFASTCALL EeEbd_join(lBd, desc, lg)
	EX_FILE_HANDLE lBd;
	BPTR desc;
	WORD lg;
{
	return((WORD)BdIsamJoin((HCRIT)lBd, (CPTR)desc, (int)lg));
}

/*--- CREATION JOINTURE ------------------------------------------------*/
/* WORD EeEbd_cjoin(lBd, desc, lg, type)				*/
/* EX_FILE_HANDLE lBd	- handle du dictionnaire			*/
/* BPTR desc		- descripteur compatible PRL			*/
/* WORD lg		- taille du descripteur				*/
/* WORD type		- 0: creation de toutes les joWORDures		*/
/*			  1 : creation de la joWORDure identifiee dans le*/
/*			descripteur					*/
/*	-->> renvoie un code erreur					*/
/*----------------------------------------------------------------------*/

WORD NOTFASTCALL EeEbd_cjoin(lBd, desc, lg, type)
	EX_FILE_HANDLE lBd;
	BPTR desc;
	WORD lg;
	WORD type;
{
	return((WORD)BdIsamCjoin((HCRIT)lBd, (CPTR)desc, (int)lg, (int)type));
}

/*--- SUPPRIMER JOINTURE -----------------------------------------------*/
/* WORD EeEbd_djoin(lBd, name)						*/
/* EX_FILE_HANDLE lBd	- handle du dictionnaire			*/
/* BPTR name		- filename ([path+]name[.ext]+\0)		*/
/*		cb950217 : le path doit etre present et celui de la base*/
/*			(pour problemes de redirection TWinServer)	*/
/*	-->> renvoie un code erreur					*/
/*----------------------------------------------------------------------*/

WORD NOTFASTCALL EeEbd_djoin(lBd, name)
	EX_FILE_HANDLE lBd;
	BPTR name;
{
	return((WORD)BdIsamDjoin((HCRIT)lBd, (CPTR)name));
}

/*--- RENOMMER UNE JOINTURE --------------------------------------------*/
/* WORD EeEbd_rjoin(lBd, desc, lg)					*/
/* EX_FILE_HANDLE lBd	- handle du dictionnaire			*/
/* BPTR desc		- descripteur compatible PRL			*/
/* WORD lg		- taille du descripteur				*/
/*	-->> renvoie un code erreur					*/
/*----------------------------------------------------------------------*/

WORD NOTFASTCALL EeEbd_rjoin(lBd, desc, lg)
	EX_FILE_HANDLE lBd;
	BPTR desc;
	WORD lg;
{
	return((WORD)BdIsamRjoin((HCRIT)lBd, (CPTR)desc, (int)lg));
}

/*--- STATISTIQUES SUR LA BASE DE DONNEES ------------------------------*/
/* WORD EeEbd_info(lBd, desc, lg)					*/
/* EX_FILE_HANDLE lBd	- handle du dictionnaire			*/
/* BPTR desc		- descripteur PRL de STAT			*/
/* WORD lg		- longueur du buffer de transfert		*/
/*	-->> renvoie un code erreur					*/
/*----------------------------------------------------------------------*/

WORD NOTFASTCALL EeEbd_info(lBd, desc, lg)
	EX_FILE_HANDLE lBd;
	BPTR desc;
	WORD lg;
{
	return((WORD)BdIsamInfo((HCRIT)lBd, (CPTR)desc, (int)lg));
}

/*--- STATISTIQUES SUR UN FICHIER DE LA BASE ---------------------------*/
/* WORD EeEbf_info(lBd, desc, lg)					*/
/* EX_FILE_HANDLE lFd	- handle du fichier				*/
/* BPTR desc		- descripteur PRL de STAT			*/
/* WORD lg		- longueur du buffer de transfert		*/
/*	-->> renvoie un code erreur					*/
/*----------------------------------------------------------------------*/

WORD NOTFASTCALL EeEbf_info(lFd, desc, lg)
	EX_FILE_HANDLE lFd;
	BPTR desc;
	WORD lg;
{
	return((WORD)BdIsamInfoFile((HCRIT)lFd, (CPTR)desc, (int)lg));
}

/*--- LISTE DES FICHIERS DE LA BASE ------------------------------------*/
/* WORD EeEbd_lfile(lBd, desc, lg, type)				*/
/* EX_FILE_HANDLE lBd	- handle du dictionnaire			*/
/* BPTR desc		- descripteur compatible PRL			*/
/* WORD lg		- longueur du descripteur			*/
/* WORD type		- 0 : premier appel, 1 : appel suivant		*/
/*	-->> renvoie un code erreur					*/
/*----------------------------------------------------------------------*/

WORD NOTFASTCALL EeEbd_lfile(lBd, desc, lg, type)
	EX_FILE_HANDLE lBd;
	BPTR desc;
	WORD lg;
	WORD type;
{
	return((WORD)BdIsamLfile((HCRIT)lBd, (CPTR)desc, (int)lg, (int)type));
}

/*--- LISTE DES JOINTURES DE LA BASE -----------------------------------*/
/* WORD EeEbd_ljoin(lBd, desc, lg, type)				*/
/* EX_FILE_HANDLE lBd	- handle du dictionnaire			*/
/* BPTR desc		- descripteur compatible PRL			*/
/* WORD lg		- longueur du descripteur			*/
/* WORD type		- 0 : premier appel, 1 : appel suivant		*/
/*	-->> renvoie un code erreur					*/
/*----------------------------------------------------------------------*/

WORD NOTFASTCALL EeEbd_ljoin(lBd, desc, lg, type)
	EX_FILE_HANDLE lBd;
	BPTR desc;
	WORD lg;
	WORD type;
{
	return((WORD)BdIsamLjoin((HCRIT)lBd, (CPTR)desc, (int)lg, (int)type));
}

/*--- LISTE DES RUBRIQUES DE LA BASE OU D'UN FICHIER DE LA BASE --------*/
/* WORD EeEbd_lkey(lBd, desc, lg, type)					*/
/* EX_FILE_HANDLE lBd	- handle de la base ou du fichier		*/
/* BPTR desc		- descripteur compatible PRL			*/
/* WORD lg		- longueur du descripteur			*/
/* WORD type		- 0 : premier appel, 1 : appel suivant		*/
/*	-->> renvoie un code erreur					*/
/*----------------------------------------------------------------------*/

WORD NOTFASTCALL EeEbd_lkey(lBd, desc, lg, type)
	EX_FILE_HANDLE lBd;
	BPTR desc;
	WORD lg;
	WORD type;
{
	return((WORD)BdIsamLkey((HCRIT)lBd, (CPTR)desc, (int)lg, (int)type));
}

/*--- LISTE DES LIENS DE LA BASE OU D'UN FICHIER DE LA BASE ------------*/
/* WORD EeEbd_llink(lBd, desc, lg, type)				*/
/* EX_FILE_HANDLE lBd		- handle de la base ou du fichier	*/
/* BPTR desc		- descripteur compatible PRL			*/
/* WORD lg		- longueur du descripteur			*/
/* WORD type		- 0 : premier appel, 1 : appel suivant		*/
/*	-->> renvoie un code erreur					*/
/*----------------------------------------------------------------------*/

WORD NOTFASTCALL EeEbd_llink(lBd, desc, lg, type)
	EX_FILE_HANDLE lBd;
	BPTR desc;
	WORD lg;
	WORD type;
{
	return((WORD)BdIsamLlink((HCRIT)lBd, (CPTR)desc, (int)lg, (int)type));
}

/*--- COUNT ------------------------------------------------------------*/
/* WORD EeEbd_count(lFd, desc, ssdb, seq, lg, res)			*/
/* EX_FILE_HANDLE lFd	- handle du fichier ou du dictionnaire		*/
/* BPTR desc		- descripteur de la requete PRL			*/
/* WORD ssdb		- 1 : sans les doublons				*/
/* WORD seq		- 1 : recherche sequent. si pas d'index		*/
/* WORD lg		- longueur du descripteur			*/
/* LONG SPTR res	- nombre de records selectionnes		*/
/*	-->> renvoie l'erreur						*/
/*----------------------------------------------------------------------*/

WORD NOTFASTCALL EeEbd_count(lFd, desc, ssdb, seq, lg, res)
	EX_FILE_HANDLE lFd;
	BPTR desc;
	WORD ssdb;
	WORD seq;
	WORD lg;
	LONG SPTR res;
{
LONG resultat;
WORD retour;
	retour=(WORD)BdIsamCount((HCRIT)lFd, (CPTR)desc, (int)ssdb, (int)seq, (int)lg, (LPLONG)&resultat);
	if (!retour)	*res=(LONG)resultat;
	return(retour);
}

/*--- POSIT ------------------------------------------------------------*/
/* WORD EeEbd_posit(lFd, desc, ssdb, seq, dernier, lg, res)		*/
/* EX_FILE_HANDLE lFd	- handle du fichier ou du dictionnaire		*/
/* BPTR desc		- descripteur de la requete PRL			*/
/* WORD ssdb		- 1 : sans les doublons				*/
/* WORD seq		- 1 : recherche sequentielle si pas d'index	*/
/* WORD dernier		- 1 : a partir de la derniere reponse		*/
/* WORD lg		- longueur du descripteur			*/
/* WPTR res		- 0 si pas de reponse,  sinon			*/
/*	-->> renvoie l'erreur						*/
/*----------------------------------------------------------------------*/

WORD NOTFASTCALL EeEbd_posit(lFd, desc, ssdb, seq, dernier, lg, res)
	EX_FILE_HANDLE lFd;
	BPTR desc;
	WORD ssdb;
	WORD seq;
	WORD dernier;
	WORD lg;
	LPINT /* WPTR */ res;
{
int resultat;
WORD retour;

	retour=(WORD)BdIsamPosit((HCRIT)lFd, (CPTR)desc, (int)ssdb, (int)seq, (int)dernier, (int)lg, (LPINT) res /* &resultat */);
/*	if (!retour)	*res=(WORD)resultat;	*/
	return(retour);
}

/*--- UP/DOWN SUR LA BASE ----------------------------------------------*/
/* WORD EeEbd_updown(lBd, sens, lock, pmarq, buffer, lg)		*/
/* EX_FILE_HANDLE lBd		- handle de la base 			*/
/* WORD sens		- -1 : Up / 1 : Down				*/
/* WORD lock		- 1 si blocage demande, 0 sinon			*/
/* WPTR pmarq		- marqueur					*/
/* BPTR buffer	- le descripteur compatible PRL mais avec des		*/
/*			handles (4 octets) au lieu de numeros logiques  */
/*			sur 1 octet					*/
/*	x : 		nombre de fichiers				*/
/*	xxxx : 		handle logique fichier 1 (ordre fort faible)	*/
/*	xx : 		offset zone 1					*/
/*	xx : 		base zone 1					*/
/*	xx : 		longueur 1					*/
/*	x :		handle fichier 2				*/
/*	...								*/
/* WORD lg		- longueur du buffer				*/
/*	-->> renvoie un code erreur, si il y a une erreur, le descripteur*/
/*	     passe dans buffer est errone				*/
/*----------------------------------------------------------------------*/

WORD NOTFASTCALL EeEbd_updown(lBd, sens, lock, pmarq, buffer, lg)
	EX_FILE_HANDLE lBd;
	WORD sens;
	WORD lock;
	WPTR pmarq;
	BPTR buffer;
	WORD lg;
{
WORD resultat;
int marq;

	marq=*pmarq;
	resultat=(WORD)BdIsamUpDown((HCRIT)lBd, (int)sens, (int)lock, (LPINT)&marq, (CPTR)buffer, (int)lg);
	if (!resultat)	*pmarq=(WORD)marq;
	return(resultat);
}
