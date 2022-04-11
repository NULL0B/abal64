/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1995
 *	Module  : EXA
 *	Fichier : EXMAFL.C
 *	Version : 1.1b
 *	Date    : 28/10/95
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
 *	FLFILE : acces direct et sequentiel.
 *
 * ------------------------------------------------------------------------- */

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			ACCES DIRECT					     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/***********************************************************************/
/*AD************ CREATE ************************************************/
/************************************************************************
; EX_FILE_HANDLE EeEad_create(nom, perm, perr)				;
; BPTR nom;	- nom du fichier, path complet, termine par un 0	;
; WORD perm;	- 	bit 0 = WR (1 = R/W, 0 = R/O : non exploite)	;
;			bit 1 = EX (1 = exclusif, 0 = partageable)	;
;			bit 2 = C  (1 = mode securite, 0 = mode copie)	;
;			bit 3 = DF (non exploite)			;
; WPTR perr;	- erreur
;		attention : mode copie 'oublie' dans l'api AD/SQ	;
;		attention : mode WR 'oublie' dans l'api AD/SQ		;
;	-->> le handle si OK, 0 sinon, perr positionnee			;
*************************************************************************/

EX_FILE_HANDLE NOTFASTCALL EeEad_create(nom, perm, perr)
	BPTR nom;
	WORD perm;
	WPTR perr;
{
EHANDLE h;
int erreur;
WORD ex, cp;
	ex=(perm & 0x0002) ? (WORD)1 : (WORD)0;
	cp=(perm & 0x0004) ? (WORD)1 : (WORD)0;
	cp |= (perm & 0x0001) ? (WORD)2 : (WORD)0;

	h=FFcreate((LPSTR)nom, (int)ex, (int)cp, (LPINT)&erreur);
	*perr=(WORD)erreur;

	return((EX_FILE_HANDLE)h);
}

/***********************************************************************/
/*AD************ RENAME ************************************************/
/************************************************************************ 
; WORD EeEad_rename(hfic, newname)					;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; BPTR newname		- nouveau nom					;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEad_rename(hfic, newname)
	EX_FILE_HANDLE hfic;
	BPTR newname;
{
	/* pour que meme les c..s soient contents, on saute les	*/
	/* eventuels espaces en tete du nouveau nom		*/
	while ((*newname==' ') || (*newname=='\t'))
		{ newname++; }
	if (*newname=='\0')	{ return(30); }

	return((WORD)FFrename((EHANDLE)hfic, (LPSTR)newname));
}

/***********************************************************************/
/*AD************ UNLINK ************************************************/
/************************************************************************
; WORD EeEad_unlink(nom)						;
; BPTR nom		- nom du fichier a supprimer			;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEad_unlink(nom)
	BPTR nom;
{
#ifdef LINUX
	int err;
	err = FFunlink((LPSTR)nom);
	if (err == 2) err = 40;
	return( (WORD) err);
#else
	return((WORD)FFunlink((LPSTR)nom));
#endif
}

/***********************************************************************/
/*AD************ OPEN **************************************************/
/************************************************************************ 
; EX_FILE_HANDLE EeEad_open(nom, perm, perr)					;
; BPTR nom;	- nom du fichier, path complet, termine par un 0	;
; WORD perm;	- 	bit 0 = WR (1 = R/W, 0 = R/O : non exploite)	;
;			bit 1 = EX (1 = exclusif, 0 = partageable)	;
;			bit 2 = C  (1 = mode securite, 0 = mode copie)	;
;			bit 3 = DF (non exploite)			;
; WPTR perr;	- erreur
;		attention : mode copie 'oublie' dans l'api AD/SQ	;
;		attention : mode WR 'oublie' dans l'api AD/SQ		;
;	-->> le handle si OK, 0 sinon, perr positionnee			;
*************************************************************************/

EX_FILE_HANDLE NOTFASTCALL EeEad_open(nom, perm, perr)
	BPTR nom;
	WORD perm;
	WPTR perr;
{
EHANDLE h;
int erreur;
WORD ex, cp, wr;

	ex=(perm & 0x0002) ? (WORD)1 : (WORD)0;
	cp=(perm & 0x0004) ? (WORD)1 : (WORD)0;
	cp |= ((perm & 0x0001) == 0 ? (WORD)2 : (WORD)0);

	h=FFopen((LPSTR)nom, (int)ex, (int)cp, (LPINT)&erreur);
	*perr=(WORD)erreur;

	return((EX_FILE_HANDLE)h);
}

/***********************************************************************/
/*AD************ READ **************************************************/
/************************************************************************
; WORD EeEad_read(hfic, buffer, nboctets)				;
; EX_FILE_HANDLE hfic;	- handle du fichier				;
; BPTR buffer;		- buffer de lecture				;
; WORD nboctets;	- nombre d'OCTETS				;
;	-->> un code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEad_read(hfic, buffer, nboctets)
	EX_FILE_HANDLE hfic;
	BPTR buffer;
	WORD nboctets;
{
unsigned int lu;
WORD err;

	err=(WORD)FFread((EHANDLE)hfic, fidseek, (CPTR)buffer, (int)nboctets, (LPINT)&lu);
	if ((err == 48) || (err == 0))	fidseek+=(LONG)lu;
	return((WORD)err);
}

/***********************************************************************/
/*AD************ WRITE *************************************************/
/************************************************************************
; WORD EeEad_write(hfic, buffer, nboctets)				;
; EX_FILE_HANDLE hfic;	- handle du fichier				;
; BPTR buffer;		- buffer de lecture				;
; WORD nboctets;	- nombre d'OCTETS				;
;	-->> un code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEad_write(hfic, buffer, nboctets)
	EX_FILE_HANDLE hfic;
	BPTR buffer;
	WORD nboctets;
{
unsigned int ecrit;
WORD err;

	if (err=(WORD)FFwrite((EHANDLE)hfic, fidseek, (CPTR)buffer, (int)nboctets, (LPINT)&ecrit))
		return(err);
	fidseek+=(LONG)ecrit;
	return((WORD)0);
}

/***********************************************************************/
/*AD************ EXTEND ************************************************/
/************************************************************************ 
; WORD EeEad_extend(hfic, nbs)						;
; EX_FILE_HANDLE hfic;	- handle du fichier				;
; WORD nbs;	- nombre de secteurs					;
;	-->> un code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEad_extend(hfic, nbs)
	EX_FILE_HANDLE hfic;
	WORD nbs;
{
	return(FFextend((EHANDLE)hfic, ((LSEEKTYPE)nbs) * 256L));
}

/***********************************************************************/
/*AD************ ACCESS ************************************************/
/************************************************************************
; WORD EeEad_access(nom, perm)						;
; BPTR nom;	- handle du fichier					;
; WORD perm;	- bit 1 = EX (1 = exclusif, 0 = partageable)		;
;	-->> un code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEad_access(nom, perm)
	BPTR nom;
	WORD perm;
{
WORD ex;

	ex=(perm & 0x0002) ? (WORD)1 : (WORD)0;

	return(FFaccess((CPTR)nom, (int)ex));
}

/***********************************************************************/
/*AD************ MATB **************************************************/
/************************************************************************ 
; WORD EeEad_matb(hfic, perm)						;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; WORD perm;	- 	bit 0 = WR (1 = R/W, 0 = R/O : non exploite)	;
;			bit 1 = EX (1 = exclusif, 0 = partageable)	;
;			bit 2 = C  (1 = mode securite, 0 = mode copie)	;
;		attention : mode copie 'oublie' dans l'api AD/SQ	;
;	-->> le code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEad_matb(hfic, perm)
	EX_FILE_HANDLE hfic;
	WORD perm;
{
WORD ex;

	ex=(perm & 0x0002) ? (WORD)1 : (WORD)0;

	return(FFatbopen((EHANDLE)hfic, (int)ex, (int)0));
}

/***********************************************************************/
/*AD************ CLOSE *************************************************/
/************************************************************************
; WORD EeEad_close(hfic)						;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEad_close(hfic)
	EX_FILE_HANDLE hfic;
{
WORD res;
	res=(WORD)FFclose((EHANDLE)hfic);
	return(res);
}



/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			ACCES SEQUENTIEL PUR				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/***********************************************************************/
/*SQ************ CREATE ************************************************/
/************************************************************************ 
; EX_FILE_HANDLE EeEsq_create(nom, len, perm, perr)			;
; BPTR nom;	- nom du fichier, path complet, termine par un 0	;
; WORD len;	- longueur du record					;
; WORD perm;	- 	bit 0 = WR (1 = R/W, 0 = R/O : non exploite)	;
;			bit 1 = EX (1 = exclusif, 0 = partageable)	;
;			bit 2 = C  (1 = mode securite, 0 = mode copie)	;
;			bit 3 = DF (non exploite)			;
; WPTR perr;	- erreur
;		attention : mode copie 'oublie' dans l'api AD/SQ	;
;		attention : mode WR 'oublie' dans l'api AD/SQ		;
;	-->> le handle si OK, 0 sinon, perr positionnee			;
*************************************************************************/

EX_FILE_HANDLE NOTFASTCALL EeEsq_create(nom, len, perm, perr)
	BPTR nom;
	WORD len;
	WORD perm;
	WPTR perr;
{
EHANDLE h;
int erreur;
WORD ex, cp;

	*perr=0;
	ex=(perm & 0x0002) ? (WORD)1 : (WORD)0;
	cp=(perm & 0x0004) ? (WORD)1 : (WORD)0;

	h=SQcreate((LPSTR)nom, (int)ex, (int)cp, (int)len, (LPINT)&erreur);

	if (h)	{
		fidinfo1=len; fidinfo2=0;
		}
	else	
		{ *perr=(WORD)erreur; }
		
	return((EX_FILE_HANDLE)h);
}

/***********************************************************************/
/*SQ************ RENAME ************************************************/
/************************************************************************
; WORD EeEsq_rename(hfic, newname)					;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; BPTR newname		- nouveau nom					;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEsq_rename(hfic, newname)
	EX_FILE_HANDLE hfic;
	BPTR newname;
{
	while ((*newname==' ') || (*newname=='\t'))
		{ newname++; }
	if (*newname=='\0')	{ return(30); }

	return((WORD)SQrename((EHANDLE)hfic, (LPSTR)newname));
}

/***********************************************************************/
/*SQ************ UNLINK ************************************************/
/************************************************************************ 
; WORD EeEsq_unlink(nom)						;
; BPTR nom		- nom du fichier a supprimer			;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEsq_unlink(nom)
	BPTR nom;
{
	return((WORD)SQunlink((LPSTR)nom));
}

/***********************************************************************/
/*SQ************ OPEN **************************************************/
/************************************************************************
; EX_FILE_HANDLE EeEsq_open(nom, perm, perr)				;
; BPTR nom;	- nom du fichier, path complet, termine par un 0	;
; WORD perm;	- 	bit 0 = WR (1 = R/W, 0 = R/O : non exploite)	;
;			bit 1 = EX (1 = exclusif, 0 = partageable)	;
;			bit 2 = C  (1 = mode securite, 0 = mode copie)	;
;			bit 3 = DF (non exploite)			;
;		attention : mode copie 'oublie' dans l'api AD/SQ	;
;		attention : mode WR 'oublie' dans l'api AD/SQ		;
;		attention, fidbuff, fidinfo1, ... inutiles		;
; WPTR perr;	- erreur						;
;	-->> le handle si OK, 0 sinon, perr positionnee			;
*************************************************************************/

EX_FILE_HANDLE NOTFASTCALL EeEsq_open(nom, perm, perr)
	BPTR nom;
	WORD perm;
	WPTR perr;
{
EHANDLE h;
int erreur;
WORD ex, cp, wr;
int len;

	*perr=0;

	wr=(perm & 0x0001) ? (WORD)1 : (WORD)0;
	ex=(perm & 0x0002) ? (WORD)1 : (WORD)0;
	cp=(perm & 0x0004) ? (WORD)1 : (WORD)0;

	h=SQopen((LPSTR)nom, (int)ex, (int)cp, (LPINT)&len, (LPINT)&erreur);

	if (h)
		{
		/* recupere les caracteristiques de l'enregistrement	*/
		fidinfo1=len;
		fidinfo2=0;
		return((EX_FILE_HANDLE)h);
		}
	else	{ *perr=(WORD)erreur; return((EX_FILE_HANDLE)0); };
}

/***********************************************************************/
/*SQ************ MATB **************************************************/
/************************************************************************
; WORD EeEsq_matb(hfic, perm)						;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; WORD perm;	- 	bit 0 = WR (1 = R/W, 0 = R/O : non exploite)	;
;			bit 1 = EX (1 = exclusif, 0 = partageable)	;
;			bit 2 = C  (1 = mode securite, 0 = mode copie)	;
;		attention : mode copie 'oublie' dans l'api AD/SQ	;
;	-->> le code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEsq_matb(hfic, perm)
	EX_FILE_HANDLE hfic;
	WORD perm;
{
WORD ex;

	ex=(perm & 0x0002) ? (WORD)1 : (WORD)0;

	return((WORD)SQatbopen((EHANDLE)hfic, (int)ex, (int)0));
}

/***********************************************************************/
/*SQ************ READ **************************************************/
/************************************************************************
; WORD EeEsq_read(hfic, buffer, blen)					;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; BPTR buffer		- buffer					;
; WORD blen		- longueur					;
;	-->> le code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEsq_read(hfic, buffer, blen)
	EX_FILE_HANDLE hfic;
	BPTR buffer;
	WORD blen;
{
	return((WORD)SQread((EHANDLE)hfic, (CPTR)buffer, (int)blen));
}

/***********************************************************************/
/*SQ************ WRITE *************************************************/
/************************************************************************
; WORD EeEsq_write(hfic, buffer, blen)					;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; BPTR buffer		- buffer					;
; WORD blen		- longueur					;
;	-->> le code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEsq_write(hfic, buffer, blen)
	EX_FILE_HANDLE hfic;
	BPTR buffer;
	WORD blen;
{
	return((WORD)SQwrite((EHANDLE)hfic, (CPTR)buffer, (int)blen));
}

/***********************************************************************/
/*SQ************ MODIF *************************************************/
/************************************************************************
; WORD EeEsq_modif(hfic, buffer, blen)					;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; BPTR buffer		- buffer					;
; WORD blen		- longueur					;
;	-->> le code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEsq_modif(hfic, buffer, blen)
	EX_FILE_HANDLE hfic;
	BPTR buffer;
	WORD blen;
{
	return((WORD)SQmodif((EHANDLE)hfic, (CPTR)buffer, (int)blen));
}

/***********************************************************************/
/*SQ************ REWIND ************************************************/
/************************************************************************
; WORD EeEsq_rewind(hfic)						;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEsq_rewind(hfic)
	EX_FILE_HANDLE hfic;
{
	return((WORD)SQrewind((EHANDLE)hfic));
}

/***********************************************************************/
/*SQ************ CLOSE *************************************************/
/************************************************************************
; WORD EeEsq_close(hfic)						;
; EX_FILE_HANDLE hfic	- handle du fichier				;
; 	-->> code erreur						;
*************************************************************************/

WORD NOTFASTCALL EeEsq_close(hfic)
	EX_FILE_HANDLE hfic;
{
WORD res;
	res=(WORD)SQclose((EHANDLE)hfic);
	return(res);
}
