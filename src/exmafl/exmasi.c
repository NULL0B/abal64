/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1995
 *	Module  : EXA
 *	Fichier : EXMASI.C
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
 *	CRITERIA : acces sequentiel indexe et SEARCH / UP / DOWN
 *	communs a SI / MC et BD.
 *
 * ------------------------------------------------------------------------- */


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			TOUS ACCES A CRITERIA				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/***********************************************************************/
/*SIMCBD******** SEARCH FICHIER*****************************************/
/************************************************************************ 
; WORD EeEsimcbf_search(ma, hfic, lock, reslg, pcle, marq, pdon, lgr)	;
; int ma		- 1 : SI / 2 : MC / 3 : BD			;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; WORD  lock		- cf code exa					;
; WORD  reslg		- cf code exa					;
; BPTR pcle		- cle						;
; BYTE  marq		- marqueur					;
; BPTR pdon		- donnees					;
; WORD lgr		- lg de pdata					;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEsimcbf_search(ma, hfic, lock, reslg, pcle, marq, pdon, lgr)
	int ma;
	EX_FILE_HANDLE hfic;
	WORD  lock;
	WORD  reslg;
	CPTR pcle;
	BYTE  marq;
	CPTR pdon;
	WORD  lgr;
{
  WORD err;
  int  nmarq;
  int  nlgr;
  CPTR pdata;
  WORD ldata;
  WORD deplgr;

	/* Calcule les positions et longueurs en fonction du type
	 * de demande effectuee.
	 */
	reslg |= lock;
	switch(reslg) {
		case 0 :		/* donnees seules */
			pdata = pdon; ldata = lgr; break;
		case 1 :		/* marqueur + donnees */
			if (lgr < 1) return((WORD)122);
			pdata = pdon+1; ldata = lgr-1; break;
		case 2 :		/* longueur + donnees */
			if (lgr < 2) return((WORD)122);
			pdata = pdon+2; ldata = lgr-2; break;
		case 3 :		/* longueur + marqueur + donnees */
			if (lgr < 1+2) return((WORD)122);
			pdata = pdon+3; ldata = lgr-1-2; break;
	}

	/* Prepare les donnees a double sens */
	nmarq = (int)marq; nlgr  = ldata;

	/* Effectue la recherche proprement dite */
	switch(ma) {
		case 1 :
			err = (WORD)IsamSearch((HCRIT)hfic,(int)lock,(CPTR)pcle,(LPINT)&nmarq,
					 (CPTR)pdata,(int)ldata,(LPINT)&nlgr);
			break;
		case 2 :
			err = (WORD)McIsamSearch((HCRIT)hfic,(int)lock,(CPTR)pcle,(LPINT)&nmarq,
					 (CPTR)pdata,(int)ldata,(LPINT)&nlgr);
			break;
		case 3 :
			err = (WORD)BdIsamSearch((HCRIT)hfic,(int)lock,(CPTR)pcle,(LPINT)&nmarq,
					 (CPTR)pdata,(int)ldata,(LPINT)&nlgr);
			break;
	}

	/* Toute erreur sur le search, autre que l'erreur 63 ne doit
	 * pas modifier le contenu du buffer.
	 */
	if ((err != 0) && (err != 63)) { return((WORD)err); }

	/* Met en forme le buffer en fonction du type
	 * de demande effectuee.
	 */

	deplgr = ((WORD)nlgr > ldata) ? ldata : nlgr;
		/* lgr a deplacer */
	switch (reslg) {
		case 0 :		/* donnees seules */
			pdata = pdon+deplgr; break;
		case 1 :		/* marqueur + donnees */
			pdata = pdon+deplgr+1; *(pdon) = (BYTE)nmarq;
			break;
		case 2 :		/* longueur + donnees */
			pdata = pdon+deplgr+2;
			*(pdon) = (BYTE)   (   (WORD)nlgr >> 8);
			*(pdon+1) = (BYTE)((WORD)nlgr & 0x00FF);
			break;
		case 3 :		/* longueur + marqueur + donnees */
			pdata = pdon+deplgr+3;
			*(pdon+2) = (BYTE)nmarq;
			*(pdon)   = (BYTE)(((WORD)nlgr) >> 8);
			*(pdon+1) = (BYTE)(((WORD)nlgr) & 0x00FF);
			break;
	}

	/* Traite le cas particulier de l'erreur 63 */
	if (err == 63) { return((WORD)err); }

	/* S'il n'y a pas eu d'erreur, padder eventuellement la
	 * fin du buffer avec des blancs.
	 */
	if ((WORD)nlgr < ldata) {
		cmemset(pdata,0x20,ldata-nlgr);
	}

	return(0);
}

/***********************************************************************/
/*SIMCBD******** UP/DOWN FICHIER ***************************************/
/************************************************************************ 
; WORD EeEsimcbf_updown(sens, ma, hfic, lock, reslg, marq, pdon, lgr)	;
; int sens		- -1 : up / 1 : down				;
; int ma		- 1 : SI / 2 : MC / 3 : BD			;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; WORD lock		- cf code exa					;
; WORD reslg		- cf code exa					;
; BYTE marq		- marqueur					;
; BPTR pdon		- donnees					;
; WORD lgr		- lg de pdata					;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEsimcbf_updown(sens, ma, hfic, lock, reslg, marq, pdon, lgr)
	int sens;
	int ma;
	EX_FILE_HANDLE hfic;
	WORD lock;
	WORD reslg;
	BYTE marq;
	BPTR pdon;
	WORD lgr;
{
  int err;
  int nmarq;
  int nlgr;
  WORD deplgr;
  CPTR pdata;
  WORD ldata;
  WORD lcle;

	/* Calcule les positions et longueurs en fonction du type
	 * de demande effectuee.
	 */
	switch(reslg) {
		case 0 :		/* cle + marqueur + donnees */
			pdata = pdon;
			if (lgr < 1)	return((WORD)122);
			ldata = lgr-1;
			break;
		case 1 :		/* longueur + cle + marqueur + donnees */
			pdata = pdon+2;
			if (lgr < 1+2) return((WORD)122);
			ldata = lgr-1-2;
			break;
	}

	/* Prepare les donnees a double sens */
	nmarq = (int)marq;
	nlgr  = (int)ldata;

	/* Effectue la recherche proprement dite */
	switch(ma) {
		case 1 :
			err = IsamUpDown((HCRIT)hfic,(int)sens,(int)lock,(LPINT)&nmarq,
					 (CPTR)pdata,(int)ldata,(LPINT)&nlgr);
			break;
		case 2 :
			err = McIsamUpDown((HCRIT)hfic,(int)sens,(int)lock,(LPINT)&nmarq,
					 (CPTR)pdata,(int)ldata,(LPINT)&nlgr);
			break;
		case 3 :
			err = BdIsamUpDownFile((HCRIT)hfic,(int)sens,(int)lock,(LPINT)&nmarq,
					 (CPTR)pdata,(int)ldata,(LPINT)&nlgr);
			break;
	}


	/* Toute erreur sur le search, autre que l'erreur 63 ne doit
	 * pas modifier le contenu du buffer.
	 */
	if ((err != 0) && (err != 63)) { return((WORD)err); }

	/* Met en forme le buffer en fonction du type
	 * de demande effectuee.
	 */
	lcle = fidinfo2;

	switch(reslg) {
		case 0 :		/* cle + marqueur + donnees */
			deplgr = (nlgr+(int)lcle > (int)ldata) ? (WORD)(ldata-lcle) : (WORD)nlgr;
			pdata  = pdon+lcle+1+deplgr;
			if (deplgr != 0)
				cmemmove(pdon+lcle+1,pdon+lcle,deplgr);
			*(pdon+lcle) = (BYTE)nmarq;
			break;
		case 1 :		/* longueur + cle + marqueur + donnees */
			deplgr = (nlgr+lcle > ldata) ? ldata-lcle : nlgr;
			pdata  = pdon+lcle+3+deplgr;
			if (deplgr != 0)
				cmemmove(pdon+lcle+3,pdon+lcle+2,deplgr);
			*(pdon+lcle+2) = (BYTE)nmarq;
			*(pdon) = (BYTE)(((WORD)nlgr) >> 8);
			*(pdon+1) = (BYTE)(((WORD)nlgr) & 0x00FF);
			break;
	}

	/* Traite le cas particulier de l'erreur 63 */
	if (err == 63) { return((WORD)err); }

	/* S'il n'y a pas eu d'erreur, padder eventuellement la
	 * fin du buffer avec des blancs.
	 */
	if (nlgr+lcle < ldata)
		{ cmemset(pdata,0x20,ldata-nlgr-lcle);}

	return(0);
}


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			ACCES SEQUENTIEL INDEXE				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/***********************************************************************/
/*SI************ CREATE ************************************************/
/************************************************************************
; EX_FILE_HANDLE EeEsi_create(nom, perm, lcle, ldata, cadrage, lvar, perr);
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

EX_FILE_HANDLE NOTFASTCALL EeEsi_create(nom, perm, lcle, ldata, cadrage, lvar, perr)
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

	h=IsamCreate((LPSTR)nom, (LPINT)&lgcle, (LPINT)&lgdata, (int)ex, (int)cp, (int)cadrage, (int)lvar, (LPINT)&erreur);

	if (h)
		{
		fidinfo1=(WORD)lgdata; fidinfo2=(WORD)lgcle;
		}
	else
		{ *perr=(WORD)erreur; }

	return((EX_FILE_HANDLE)h);
}

/***********************************************************************/
/*SI************ RENAME ************************************************/
/************************************************************************ 
; WORD EeEsi_rename(hfic, newname)					;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; BPTR newname		- nouveau nom					;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEsi_rename(hfic, newname)
	EX_FILE_HANDLE hfic;
	BPTR newname;
{
	while ((*newname==' ') || (*newname=='\t'))
		{ newname++; }
	if (*newname=='\0')	{ return(30); }

	return((WORD)IsamRename((EHANDLE)hfic, (LPSTR)newname));
}

/***********************************************************************/
/*SI************ UNLINK ************************************************/
/************************************************************************ 
; WORD EeEsi_unlink(nom)						;
; BPTR nom		- nom du fichier a supprimer			;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEsi_unlink(nom)
	BPTR nom;
{
#ifdef LINUX
	WORD err;
	err = (WORD) IsamUnlink((LPSTR)nom);
	if (err == 2) err = 40;
	return ( (WORD) err);
#else
	return((WORD)IsamUnlink((LPSTR)nom));
#endif
}

/***********************************************************************/
/*SI************ OPEN **************************************************/
/************************************************************************
; EX_FILE_HANDLE EeEsi_open(nom, perm, perr)				;
; BPTR nom;	- nom du fichier, path complet, termine par un 0	;
; WORD perm;	- 	bit 0 = WR (1 = R/W, 0 = R/O : non exploite)	;
;			bit 1 = EX (1 = exclusif, 0 = partageable)	;
;			bit 2 = C  (1 = mode securite, 0 = mode copie)	;
;			bit 3 = DF (non exploite)			;
; WPTR perr;	- erreur						;
;	-->> le handle si OK, 0 sinon, perr positionnee			;
*************************************************************************/

EX_FILE_HANDLE NOTFASTCALL EeEsi_open(nom, perm, perr)
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

	h=IsamOpen((LPSTR)nom, (int)ex, (int)cp, (int)wr, (LPINT)&lcle, (LPINT)&ldata, (LPINT)&erreur);
	
	if (h)
		{
		fidinfo1=(WORD)ldata;
		fidinfo2=(WORD)lcle;
		return((EX_FILE_HANDLE)h);
		}
	else	{ *perr=(WORD)erreur; return((EX_FILE_HANDLE)0);}
}

/***********************************************************************/
/*SI************ MATB **************************************************/
/************************************************************************ 
; WORD EeEsi_matb(hfic, perm)						;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; WORD perm;	- 	bit 0 = WR (1 = R/W, 0 = R/O : non exploite)	;
;			bit 1 = EX (1 = exclusif, 0 = partageable)	;
;			bit 2 = C  (1 = mode securite, 0 = mode copie)	;
;	-->> le code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEsi_matb(hfic, perm)
	EX_FILE_HANDLE hfic;
	WORD perm;
{
WORD ex, cp;
int erreur;

	ex=(perm & 0x0002) ? (WORD)1 : (WORD)0;
	cp=(perm & 0x0004) ? (WORD)1 : (WORD)0;

	/* si erreur lors du second atb, on ne peut defaire le premier	*/
	/* car on ne sait pas s'il etait necessaire			*/
	if (!(erreur=IsamAtbOpen((HCRIT)hfic, (int)ex, 0)))
		erreur=IsamAtbOpen((HCRIT)hfic, (int)cp, 1);

	return((WORD)erreur);
}

/***********************************************************************/
/*SI************ CLOSE *************************************************/
/************************************************************************ 
; WORD EeEsi_close(hfic)						;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEsi_close(hfic)
	EX_FILE_HANDLE hfic;
{
	return((WORD)IsamClose((HCRIT)hfic));
}

/***********************************************************************/
/*SI************ WRITE ZC **********************************************/
/************************************************************************
; WORD EeEsi_writezc(hfic, pdata, lg)					;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; BPTR pdata		- donnees					;
; WORD lg		- lg de pdata					;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEsi_writezc(hfic, pdata, lg)
	EX_FILE_HANDLE hfic;
	BPTR pdata;
	WORD lg;
{
	return((WORD)IsamWriteZc((HCRIT)hfic, (CPTR)pdata, (int)lg));
}

/***********************************************************************/
/*SI************ READ ZC ***********************************************/
/************************************************************************
; WORD EeEsi_readzc(hfic, lock, pdata, lg)				;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; WORD lock		- type de lock					;
; BPTR pdata		- donnees					;
; WORD lg		- lg de pdata					;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEsi_readzc(hfic, lock, pdata, lg)
	EX_FILE_HANDLE hfic;
	WORD lock;
	BPTR pdata;
	WORD lg;
{
	return((WORD)IsamReadZc((HCRIT)hfic, (int)lock, (CPTR)pdata, (int)lg));
}

/***********************************************************************/
/*SI************ INSERT ************************************************/
/************************************************************************ 
; WORD EeEsi_insert(hfic, pcle, marq, pdata, lg)			;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; BPTR pcle		- cle						;
; BYTE marq		- marqueur					;
; BPTR pdata		- donnees					;
; WORD lg		- lg de pdata					;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEsi_insert(hfic, pcle, marq, pdata, lg)
	EX_FILE_HANDLE hfic;
	BPTR pcle;
	BYTE marq;
	BPTR pdata;
	WORD lg;
{
	return((WORD)IsamInsert((HCRIT)hfic, (CPTR)pcle, (int)marq, (CPTR)pdata, (int)lg));
}

/***********************************************************************/
/*SI************ DELETE ************************************************/
/************************************************************************ 
; WORD EeEsi_delete(hfic, pcle, marq)					;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; BPTR pcle		- cle						;
; BYTE marq		- marqueur					;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEsi_delete(hfic, pcle, marq)
	EX_FILE_HANDLE hfic;
	BPTR pcle;
	BYTE marq;
{
	return((WORD)IsamDelete((HCRIT)hfic, (CPTR)pcle, (int)marq));
}

/***********************************************************************/
/*SI************ MODIF *************************************************/
/************************************************************************ 
; WORD EeEsi_modif(hfic, pcle, marq, pdata, lg)				;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; BPTR pcle		- cle						;
; BYTE marq		- marqueur					;
; BPTR pdata		- donnees					;
; WORD lg		- lg de pdata					;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEsi_modif(hfic, pcle, marq, pdata, lg)
	EX_FILE_HANDLE hfic;
	BPTR pcle;
	BYTE marq;
	BPTR pdata;
	WORD lg;
{
	return((WORD)IsamModif((HCRIT)hfic, (CPTR)pcle, (int)marq, (CPTR)pdata, (int)lg));
}

/***********************************************************************/
/*SI************ SEARCH ************************************************/
/************************************************************************ 
; WORD EeEsi_search(hfic, lock, reslg, pcle, marq, pdon, lgr)		;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; WORD lock		- cf code exa					;
; WORD reslg		- cf code exa					;
; BPTR pcle		- cle						;
; BYTE marq		- marqueur					;
; BPTR pdata		- donnees					;
; WORD lgr		- lg de pdata					;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEsi_search(hfic, lock, reslg, pcle, marq, pdata, lgr)
	EX_FILE_HANDLE hfic;
	WORD lock;
	WORD reslg;
	BPTR pcle;
	BYTE marq;
	BPTR pdata;
	WORD lgr;
{
	return((WORD)EeEsimcbf_search(1, hfic, lock, reslg, (BPTR)pcle, marq, (BPTR)pdata, lgr));
}

/***********************************************************************/
/*SI************ DOWN **************************************************/
/************************************************************************ 
; WORD EeEsi_down(hfic, lock, reslg, marq, pdon, lgr)			;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; WORD lock		- cf code exa					;
; WORD reslg		- cf code exa					;
; BYTE marq		- marqueur					;
; BPTR pdata		- donnees					;
; WORD lgr		- lg de pdata					;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEsi_down(hfic, lock, reslg, marq, pdata, lgr)
	EX_FILE_HANDLE hfic;
	WORD lock;
	WORD reslg;
	BYTE marq;
	BPTR pdata;
	WORD lgr;
{
	return((WORD)EeEsimcbf_updown(1, 1, hfic, lock, reslg, marq, (BPTR)pdata, lgr));
}

/***********************************************************************/
/*SI************ UP ****************************************************/
/************************************************************************
; WORD EeEsi_up(hfic, lock, reslg, marq, pdon, lgr)			;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; WORD lock		- cf code exa					;
; WORD reslg		- cf code exa					;
; BYTE marq		- marqueur					;
; BPTR pdata		- donnees					;
; WORD lgr		- lg de pdata					;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEsi_up(hfic, lock, reslg, marq, pdata, lgr)
	EX_FILE_HANDLE hfic;
	WORD lock;
	WORD reslg;
	BYTE marq;
	BPTR pdata;
	WORD lgr;
{
	return((WORD)EeEsimcbf_updown(-1, 1, hfic, lock, reslg, marq, (BPTR)pdata, lgr));
}


/***********************************************************************/
/*SI************ CRIEXT ************************************************/
/************************************************************************
; WORD EeEsi_CriExt(hfic, pdata_in, lgr_in, pdata_out, plgr_out);
; EX_FILE_HANDLE hfic	- handle du fichier				;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEsi_criext(EX_FILE_HANDLE hfic, BPTR pdata_in, WORD lgr_in, BPTR pdata_out, WORD lgr_out)
{
	DWORD nlgr = lgr_out;
	WORD err;

	err = ((WORD)IsamCriExt(hfic, (BPTR)pdata_in, lgr_in, (BPTR)pdata_out, (LPINT)&nlgr));
	
	/* Toute erreur autre que l'erreur 94 ne doit pas modifier le contenu du buffer */
	if ((err != 0) && (err != 94))
		return err;

	/* Traite le cas particulier de l'erreur 94 */
	if (err == 94)
	{
		if (lgr_out >= 2)
		{
			*(pdata_out)   = (BYTE)(((WORD)nlgr) >> 8);
			*(pdata_out + 1) = (BYTE)(((WORD)nlgr) & 0x00FF);
			nlgr = 2;
		}
		else
		{
//			err = 94; /* Meme numero d'erreur si buffer trop court ou inferieur a 2 octets */
			nlgr = 0;
		}
	}

	/* Padder la fin du buffer avec des blancs */
	if ((WORD)nlgr < lgr_out)
		cmemset(pdata_out + nlgr,0x20,lgr_out - nlgr);

	return err;
}


