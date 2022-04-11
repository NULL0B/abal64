/*
 *      Projet  : ABAL                  Copyright Amenesik / Sologic s.a. (c) 1993, 1995
 *      Module  : ATR
 *      Fichier : TABLE.C
 *      Version : 2.2b
 *      Date    : 22/11/95
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Module de gestion des tables ( DCL, CST, PROC, SEG )
 *	
 *	07/07/93 : variable FIELD=no pas de memoire etendue REZZNNNN E=0
 * 	25/10/94 : cohabitation des tables constantes locales et globales
 *	22/11/94 : mise a niveau constante locale (matchcst)
 *	------------------ 2.1d ----------------------------------------
 *	03/01/95 : arg et trou dans GetDCLTable()
 *	22/11/95 : version dediee 2.1
 *	------------ 2.2a -------------------------------------------------
 * 04/04/97 :	Modification de mkdcldesc() pour une differente pendant la
 *				  	phase de definition et la phase d'utilisation
 * 21/07/00 :  (#OK) Bug fixed. Overflow description table. Add new error messages.
 *	------------ 2.2b -------------------------------------------------
 */

/* Fichier de definition */
/* --------------------- */
#include "tr.h"
#include "tsymb.h"
#include "tcode.h"
#include "abal.h"		/* #IJM 06/11/02 */

/* #OK: 21/07/00 (begin) */	
extern BINAIRE nb_dcl_global;
extern Entete  hd_tcode;
/* #OK: 21/07/00 (end) */

extern BOOL optimise_tables;

#define _TABLE
#include "table.he"
#include "table.hs"

/* ---------------------------------------------------------------------- */
/*									  */
/* NOM		: INITTABLE 						  */
/*									  */
/* FONCTION	: Initialisation des structures du module pour la gestion */
/*		  d'une table memoire (DCL,CST,PROC,SEG).		  */
/*									  */
/* SYNTAXE	: InitTable(table);					  */
/*			TABLEInfo *table;				  */		
/*									  */
/* ARGUMENTS	: table	: TABLEInfo : 					  */
/*		: -> 							  */
/*									  */
/* RETOUR	: BINAIRE : 0 Ok					  */
/*									  */
/* COMMENTAIRES	: sans							  */
/* ---------------------------------------------------------------------- */

BINAIRE InitTable(table)
TABLEInfo *table;
{
	int k;

	for (k = 0; k < MAXTDESC; k++)
           pr_tdesc[k] = seg_tdesc[k] = glb_tdesc[k] = lcl_tdesc[k] = GenericNULL(BYTE);

	for (k = 0; k < MAXCDESC; k++)
		cst_tdesc[k] = GenericNULL(BYTE);

	size_dcl = 0; size_xtm = 0L;

	psuc_lst = GenericNULL(PSUCInfo);

	return(0);
}

/* ---------------------------------------------------------------------- */
/*									  */
/* NOM		: ENDTABLE 						  */
/*									  */
/* FONCTION	: Liberation des structures du module pour la gestion 	  */
/*		  d'une table memoire (DCL,CST,PROC,SEG).		  */
/*									  */
/* SYNTAXE	: EndTable(table);					  */
/*			TABLEInfo *table;				  */		
/*									  */
/* ARGUMENTS	: table	: TABLEInfo : 					  */
/*		: -> 							  */
/*									  */
/* RETOUR	: BINAIRE : 0 Ok					  */
/*									  */
/* COMMENTAIRES	: sans							  */
/* ---------------------------------------------------------------------- */

BINAIRE EndTable(table)
TABLEInfo *table;
{
	int     k;
	PSUCInfo *pt;

	/* Initialisation des tables des constantes locales */
	for (k = 0; k < MAXCDESC; k++)
		lcst_tdesc[k] = GenericNULL(BYTE);
	for (k = 0; k < MAXCDESC; k++) {
		if (lcst_tdesc[k] != GenericNULL(BYTE)) Free_Tabdesc(lcst_tdesc[k]);
	}

	for (k = 0; k < MAXTDESC; k++) {
	        if (pr_tdesc[k] != GenericNULL(BYTE)) Free_Tabdesc(pr_tdesc[k]); 		
	     	if (glb_tdesc[k] != GenericNULL(BYTE)) Free_Tabdesc(glb_tdesc[k]);
	     	if (lcl_tdesc[k] != GenericNULL(BYTE)) Free_Tabdesc(lcl_tdesc[k]);
	     	if (ext_tdesc[k] != GenericNULL(BYTE)) Free_Tabdesc(ext_tdesc[k]);
	     	if (seg_tdesc[k] != GenericNULL(BYTE)) Free_Tabdesc(seg_tdesc[k]);
	}

	for (k = 0; k < MAXCDESC; k++) {
		if (cst_tdesc[k] != GenericNULL(BYTE)) Free_Tabdesc(cst_tdesc[k]);
	}
	
	pt = psuc_lst;
	while ( pt != GenericNULL(PSUCInfo) ) {
		pt = psuc_lst->suiv;
		Free_PSUC(psuc_lst);
	}

	return(0);
}

/* ---------------------------------------------------------------------- */
/*									  */
/* NOM		: MAKEDCLTABLE 						  */
/*									  */
/* FONCTION	: creation d'un descripteur de DCL dans la table 	  */
/*		  DCL.							  */
/*									  */
/* SYNTAXE	: MakeDCLTable(dcl);					  */
/*			DCLInfo *dcl;					  */		
/*									  */
/* ARGUMENTS	: dcl	: DCLInfo : 					  */
/*		: -> 							  */
/*									  */
/* RETOUR	: BINAIRE : 0 Ok					  */
/*									  */
/* COMMENTAIRES	: voir la structure DCLInfo				  */
/* ---------------------------------------------------------------------- */

BINAIRE MakeDCLTable(dcl)
DCLInfo *dcl;
{
	return(0);
}

/* ---------------------------------------------------------------------- */
/*									  */
/* NOM		: GETDCLTABLE 						  */
/*									  */
/* FONCTION	: decodage d'un descripteur de DCL dans la table 	  */
/*		  memoire DCL.						  */
/*									  */
/* SYNTAXE	: GetDCLTable(dcl);					  */
/*			DCLInfo *dcl;					  */		
/*									  */
/* ARGUMENTS	: dcl	: DCLInfo : 					  */
/*		: -> adrdesc : adresse du dcl a extraire		  */
/*									  */
/* RETOUR	: BINAIRE : 0 Ok					  */
/*									  */
/* COMMENTAIRES	: voir la structure DCLInfo				  */
/* ---------------------------------------------------------------------- */

BINAIRE GetDCLTable(dcl)
DCLInfo *dcl;
{

BINAIRE i,d;
BYTE *pds;

	dcl->ext = ( ((dcl->adrdesc & IS_EXTERN) == IS_EXTERN) ? TRUE : FALSE );
	if ( dcl->ext ) {
		dcl->local = FALSE;
		/* variable locale */	
		dcl->adrdesc &= 0x3FFF;		
       		i = dcl->adrdesc / SIZETDESC; /* i = num ss-table desc */
               	d = dcl->adrdesc % SIZETDESC; /* d = depl ss-table desc */
               	pds = ext_tdesc[i] + d;
	} else {
		dcl->local = ( (dcl->adrdesc & ISLOCAL) ? TRUE : FALSE );
		if ( dcl->local ) {
		/* variable locale */	
			dcl->adrdesc &= TOGLOBAL;		
        		i = dcl->adrdesc / SIZETDESC; /* i = num ss-table desc */
                	d = dcl->adrdesc % SIZETDESC; /* d = depl ss-table desc */
                	pds = lcl_tdesc[i] + d;
		} else {
		/* variable globale */
			i = dcl->adrdesc / SIZETDESC; /* i = num ss-table desc */
                	d = dcl->adrdesc % SIZETDESC; /* d = depl ss-table desc */
                	pds = glb_tdesc[i] + d;
		}
	}

	/* 1er octet */
	dcl->type = *pds & 0x03;
	dcl->dim1 = ( (*pds & PRIMARY_INDEX) ? 1 : 0 );
	dcl->dim2 = ( (*pds & SECOND_INDEX) ? 1 : 0 );
	dcl->arg  = ( (*pds & 0x04) ? TRUE : FALSE );	/* 03/01/95 */
	dcl->trou = ( (*pds & 0x10) ? TRUE : FALSE );
	pds++;

	/* 2eme octet */
	dcl->ptr = ( (*pds & 0x80) ? ((dcl->tptr=((*pds & 0x30)>>4)),TRUE) : (dcl->tptr=0,FALSE));
	dcl->etendue = ( ((*pds & PRIMARY_INDEX) && !dcl->ptr && !(*pds & 0x3F)) ? TRUE : FALSE);
	dcl->virtuelle = ( (!dcl->ptr && (*pds & 0x3F)) ? (dcl->nologique=(*pds & 0x3f),TRUE) : FALSE);
	pds++;

	/* adr de redef des zones pointees : OPTION */	
	if ( dcl->tptr & 0x02 ) {
		dcl->adredefptr = bytetobin(pds);
		pds +=2;
	} else {
		dcl->adredefptr = 0;
	}

	/* adr de la variable */
	dcl->adrvar=bytetobin(pds);
	pds +=2;
	
	/* adr de variable en FIELD=E, NO : OPTION */
	if ( dcl->etendue || dcl->virtuelle ) {
		dcl->adrfield = bytetobin(pds);	
		pds += 2;
	} else {
		dcl->adrfield = 0;
	}

	/* longueur */
	if ( (dcl->ptr) && (dcl->tptr != 2) ) {
		dcl->longueur = LGSTDPTR;
		switch ( dcl->type ) {
			case TBCD:
				dcl->ptlongueur = bytetobin(pds);
				pds += 2;
				break;
			case TSTR:
				dcl->ptlongueur = bytetobin(pds);
				pds += 2; 
				break;
			case TBIN1:
				dcl->ptlongueur = 1;
				break;
			case TBIN2:
				dcl->ptlongueur = 2;
				break;
			default:
				dcl->ptlongueur = 0;
		}
	} else {
		switch ( dcl->type ) {
			case TBCD:
				dcl->longueur = bytetobin(pds);
				pds += 2;
				break;
			case TSTR:
				dcl->longueur = bytetobin(pds);
				pds += 2; 
				break;
			case TBIN1:
				dcl->longueur = 1;
				break;
			case TBIN2:
				dcl->longueur = 2;
				break;
			default:
				dcl->longueur = 0;
		}
		if ( (dcl->ptr) && (dcl->tptr == 2) ) {
				dcl->ptlongueur = dcl->longueur;
		} else {
			dcl->ptlongueur = 0;
		}
	}
	/* 1er dim */
	if ( dcl->dim1 ) {
		dcl->dim1 = bytetobin(pds);
		pds += 2;
	}

	/* 2 eme dim */
	if ( dcl->dim2 ) {
		dcl->dim2 = bytetobin(pds);
	}

	return(0);
}

/* ---------------------------------------------------------------------- */
/*									  */
/* NOM		: MODIFDCLTABLE						  */
/*									  */
/* FONCTION	: modification d'un descripteur de DCL dans la table 	  */
/*		  DCL.							  */
/*									  */
/* SYNTAXE	: ModifDCLTable(dcl);					  */
/*			DCLInfo *dcl;					  */		
/*									  */
/* ARGUMENTS	: dcl	: DCLInfo : 					  */
/*		: -> 							  */
/*									  */
/* RETOUR	: BINAIRE : 0 Ok					  */
/*									  */
/* COMMENTAIRES	: voir la structure DCLInfo				  */
/* ---------------------------------------------------------------------- */

BINAIRE ModifDCLTable(dcl)
DCLInfo *dcl;
{
	return(0);
}

/* ---------------------------------------------------------------------- */
/*									  */
/* NOM		: MAKEPSUCTABLE 						  */
/*									  */
/* FONCTION	: creation d'un descripteur de PSUC dans la table 	  */
/*		  PSUC.							  */
/*									  */
/* SYNTAXE	: MakePSUCTable(psuc);					  */
/*			PSUCInfo *psuc;					  */		
/*									  */
/* ARGUMENTS	: dcl	: PSUCInfo : 					  */
/*		: -> 							  */
/*									  */
/* RETOUR	: BINAIRE : 0 Ok					  */
/*									  */
/* COMMENTAIRES	: voir la structure PSUCInfo				  */
/* ---------------------------------------------------------------------- */

BINAIRE MakePSUCTable(psuc)
PSUCInfo *psuc;
{
PSUCInfo *pt;

	pt = All_PSUC();
	if ( pt == GenericNULL(PSUCInfo) )
		erreur(FATALE,errmem);  /* debordement memoire */

	if ( psuc_lst == GenericNULL(PSUCInfo) ) {
		psuc_lst = pt;
		psuc_lst->adr = psuc->adr;
		psuc_lst->ext = ( ((psuc->adr & IS_EXTERN) == IS_EXTERN) ? TRUE : FALSE );
		psuc_lst->type = psuc->type;
		psuc_lst->suiv = GenericNULL(PSUCInfo);
	} else {
		pt->adr = psuc->adr;
		pt->ext = ( ((psuc->adr & IS_EXTERN) == IS_EXTERN) ? TRUE : FALSE );
		pt->type = psuc->type;
		pt->suiv = psuc_lst;
		psuc_lst = pt;
	}
	return(0);
}

/* ---------------------------------------------------------------------- */
/*									  */
/* NOM		: GETPSUCTABLE 						  */
/*									  */
/* FONCTION	: decodage d'un descripteur de PSUC dans la liste 	  */
/*		  memoire PSUC.						  */
/*									  */
/* SYNTAXE	: GetPSUCTable(psuc);					  */
/*			PSUCInfo *psuc;					  */		
/*									  */
/* ARGUMENTS	: psuc	: PSUCInfo : 					  */
/*		: -> adr : adresse du psuc a extraire		  	  */
/*									  */
/* RETOUR	: BINAIRE : 0 Ok					  */
/*									  */
/* COMMENTAIRES	: voir la structure PSUCInfo				  */
/* ---------------------------------------------------------------------- */

BINAIRE GetPSUCTable(psuc)
PSUCInfo *psuc;
{
PSUCInfo *pt;
BOOL trouve=FALSE;

	pt = psuc_lst;
	while ( pt != GenericNULL(PSUCInfo) ) {
		if ( pt->adr == psuc->adr ) {
			trouve = TRUE;
			break;
		}		
		pt = pt->suiv;
	}
	if ( trouve ) {
		psuc->ext = pt->ext;
		psuc->type = pt->type;
		psuc->suiv = GenericNULL(PSUCInfo);
	} else
		return(0xFFFF);
	
	return(0);
}

/* ---------------------------------------------------------------------- */
/*									  */
/* NOM		: LIBPSUCTABLE 						  */
/*									  */
/* FONCTION	: liberation d'un descripteur de PSUC dans la liste 	  */
/*		  memoire PSUC.						  */
/*									  */
/* SYNTAXE	: LibPSUCTable(action);					  */
/*			BINAIRE action;					  */
/*									  */
/* ARGUMENTS	: psuc	: PSUCInfo : 					  */
/*		: -> adr : adresse du psuc a extraire		  	  */
/*									  */
/* RETOUR	: BINAIRE : 0 Ok					  */
/*									  */
/* COMMENTAIRES	: voir la structure PSUCInfo				  */
/* ---------------------------------------------------------------------- */

BINAIRE LibPSUCTable(action)
BINAIRE action;
{
PSUCInfo *pt,*pt2;
BOOL trouve=FALSE;

	pt = psuc_lst;
	while ( pt != GenericNULL(PSUCInfo) ) {
		if ( (pt->adr & action) && (! pt->ext) ) {
			pt2 = pt;
			pt = pt->suiv;
			Free_PSUC(pt2);			
		} else {
			break;
		}		
	}
	psuc_lst = pt;
	return(0);
}

/* ---------------------------------------------------------------------- */
/*									  */
/* NOM		: MODIFPSUCTABLE					  */
/*									  */
/* FONCTION	: modification d'un descripteur de pointeur de code 	  */
/*		  dans la liste des PSUC.				  */
/*									  */
/* SYNTAXE	: ModifPSUCTable(psuc);					  */
/*			PSUCInfo *psuc;					  */		
/*									  */
/* ARGUMENTS	: psuc	: PSUCInfo : 					  */
/*		: -> 							  */
/*									  */
/* RETOUR	: BINAIRE : 0 Ok					  */
/*									  */
/* COMMENTAIRES	: voir la structure PSUCInfo				  */
/* ---------------------------------------------------------------------- */

BINAIRE ModifPSUCTable(psuc)
PSUCInfo *psuc;
{
	return(0);
}

/* ---------------------------------------------------------------------- */
/*									  */
/* NOM		: MAKECSTTABLE 						  */
/*									  */
/* FONCTION	: creation d'un descripteur de CST dans la table 	  */
/*		  CST.							  */
/*									  */
/* SYNTAXE	: MakeCSTTable(cst);					  */
/*			CSTInfo *cst;					  */		
/*									  */
/* ARGUMENTS	: cst	: CSTInfo : 					  */
/*		: -> 							  */
/*									  */
/* RETOUR	: BINAIRE : 0 Ok					  */
/*									  */
/* COMMENTAIRES	: voir la structure CSTInfo				  */
/* ---------------------------------------------------------------------- */

BINAIRE MakeCSTTable(cst)
CSTInfo *cst;
{
	return(0);
}

/* ---------------------------------------------------------------------- */
/*									  */
/* NOM		: GETCSTTABLE 						  */
/*									  */
/* FONCTION	: decodage d'un descripteur de CST dans la table 	  */
/*		  memoire CST.						  */
/*									  */
/* SYNTAXE	: GetCSTTable(cst);					  */
/*			CSTInfo *cst;					  */		
/*									  */
/* ARGUMENTS	: cst	: CSTInfo : 					  */
/*		: -> 							  */
/*									  */
/* RETOUR	: BINAIRE : 0 Ok					  */
/*									  */
/* COMMENTAIRES	: voir la structure CSTInfo				  */
/* ---------------------------------------------------------------------- */

BINAIRE GetCSTTable(cst)
CSTInfo *cst;
{
	return(0);
}

/* ---------------------------------------------------------------------- */
/*									  */
/* NOM		: MODIFCSTTABLE						  */
/*									  */
/* FONCTION	: modification d'un descripteur de CST dans la table 	  */
/*		  CST.							  */
/*									  */
/* SYNTAXE	: ModifCSTTable(cst);					  */
/*			CSTInfo *cst;					  */		
/*									  */
/* ARGUMENTS	: cst	: CSTInfo : 					  */
/*		: -> 							  */
/*									  */
/* RETOUR	: BINAIRE : 0 Ok					  */
/*									  */
/* COMMENTAIRES	: voir la structure CSTInfo				  */
/* ---------------------------------------------------------------------- */

BINAIRE ModifCSTTable(cst)
CSTInfo *cst;
{
	return(0);
}

/* ---------------------------------------------------------------------- */
/*									  */
/* NOM		: MAKEPROCTABLE 						  */
/*									  */
/* FONCTION	: creation d'un descripteur de PROC dans la table 	  */
/*		  PROC.							  */
/*									  */
/* SYNTAXE	: MakePROCTable(proc);					  */
/*			PROCInfo *proc;					  */		
/*									  */
/* ARGUMENTS	: proc	: PROCInfo : 					  */
/*		: -> 							  */
/*									  */
/* RETOUR	: BINAIRE : 0 Ok					  */
/*									  */
/* COMMENTAIRES	: voir la structure PROCInfo				  */
/* ---------------------------------------------------------------------- */

#ifdef _ISUSED
BINAIRE MakePROCTable(proc)
PROCInfo *proc;
{
/*      Allocation et insertion dans la table des procedures
 */
BOOL fwd;
BINAIRE acode,lcode,avar,lvar;
BINAIRE optres;
register int i;
register TabProc *s;
TabProc *f = GenericNULL(TabProc);
BYTE *t,*ptlcode;

	/* Dans le cas ou la procedure a deja ete declare en FORWARD
	 * on la trouve dans la table des procedures
	 * m a j de la table
	 */
	BOOL tfwd = FALSE;     /* forward pas dans la table */

	t = All_Desc(3,16,&adsproc);
	if ( fwd ) {
		s->adesc = t;
		s->ads = adsproc;               /* conserver le descripteur */
		adsproc += 16;
	} else {
		t = s->adesc;
	}

		t = bintobyte(t,acode);
		ptlcode = t;
		t = bintobyte(t,lcode);
		t = bintobyte(t,avar);
		t = bintobyte(t,lvar);
		/* adresse de la table des constantes locales */
		t = bintobyte(t,0);
		/* longueur de la table des variables locales */
		t = bintobyte(t,0);
		/* completer avec 2 octets a zero pour l'executeur */
		for (i = 0; i < 2; i++)
			*t++ = 0;
		/* Pose le statut de la procedure RESIDENT / PUBLIC */
		t = bintobyte(t,optres);

	return(0);
}
#endif

/* ---------------------------------------------------------------------- */
/*									  */
/* NOM		: GETPROCTABLE 						  */
/*									  */
/* FONCTION	: decodage d'un descripteur de PROC dans la table 	  */
/*		  memoire PROC.						  */
/*									  */
/* SYNTAXE	: GetPROCTable(proc);					  */
/*			PROCInfo *proc;					  */		
/*									  */
/* ARGUMENTS	: proc	: PROCInfo : 					  */
/*		: -> 							  */
/*									  */
/* RETOUR	: BINAIRE : 0 Ok					  */
/*									  */
/* COMMENTAIRES	: voir la structure PROCInfo				  */
/* ---------------------------------------------------------------------- */

BINAIRE GetPROCTable(proc)
PROCInfo *proc;
{
	return(0);
}

/* ---------------------------------------------------------------------- */
/*									  */
/* NOM		: MODIFPROCTABLE						  */
/*									  */
/* FONCTION	: modification d'un descripteur de PROC dans la table 	  */
/*		  PROC.							  */
/*									  */
/* SYNTAXE	: ModifPROCTable(proc);					  */
/*			PROCInfo *proc;					  */		
/*									  */
/* ARGUMENTS	: proc	: PROCInfo : 					  */
/*		: -> 							  */
/*									  */
/* RETOUR	: BINAIRE : 0 Ok					  */
/*									  */
/* COMMENTAIRES	: voir la structure PROCInfo				  */
/* ---------------------------------------------------------------------- */

BINAIRE ModifPROCTable(proc)
PROCInfo *proc;
{
	return(0);
}


/* ---------------------------------------------------------------------- */
/*									  */
/* NOM		: MAKESEGTABLE 						  */
/*									  */
/* FONCTION	: creation d'un descripteur de SEG dans la table 	  */
/*		  SEG.							  */
/*									  */
/* SYNTAXE	: MakeSEGTable(seg);					  */
/*			SEGInfo *seg;					  */		
/*									  */
/* ARGUMENTS	: seg	: SEGInfo : 					  */
/*		: -> 							  */
/*									  */
/* RETOUR	: BINAIRE : 0 Ok					  */
/*									  */
/* COMMENTAIRES	: voir la structure SEGInfo				  */
/* ---------------------------------------------------------------------- */

BINAIRE MakeSEGTable(seg)
SEGInfo *seg;
{
	return(0);
}

/* ---------------------------------------------------------------------- */
/*									  */
/* NOM		: GETSEGTABLE 						  */
/*									  */
/* FONCTION	: decodage d'un descripteur de SEG dans la table 	  */
/*		  memoire SEG.						  */
/*									  */
/* SYNTAXE	: GetSEGTable(seg);					  */
/*			SEGInfo *seg;					  */		
/*									  */
/* ARGUMENTS	: seg	: SEGInfo : 					  */
/*		: -> 							  */
/*									  */
/* RETOUR	: BINAIRE : 0 Ok					  */
/*									  */
/* COMMENTAIRES	: voir la structure SEGInfo				  */
/* ---------------------------------------------------------------------- */

BINAIRE GetSEGTable(seg)
SEGInfo *seg;
{
	return(0);
}

/* ---------------------------------------------------------------------- */
/*									  */
/* NOM		: MODIFSEGTABLE						  */
/*									  */
/* FONCTION	: modification d'un descripteur de SEG dans la table 	  */
/*		  SEG.							  */
/*									  */
/* SYNTAXE	: ModifSEGTable(seg);					  */
/*			SEGInfo *seg;					  */		
/*									  */
/* ARGUMENTS	: seg	: SEGInfo : 					  */
/*		: -> 							  */
/*									  */
/* RETOUR	: BINAIRE : 0 Ok					  */
/*									  */
/* COMMENTAIRES	: voir la structure SEGInfo				  */
/* ---------------------------------------------------------------------- */

BINAIRE ModifSEGTable(seg)
SEGInfo *seg;
{
	return(0);
}


BINAIRE GetTABLETable(table)
TABLEInfo *table;
{
	return(0);
}

BINAIRE PutTable(fic,table)
Tabfic *fic;
TABLEInfo *table;
{
	return(0);
}


BINAIRE GetTable(fic,table)
Tabfic *fic;
TABLEInfo *table;
{
	return(0);
}


BYTE *mkprocdesc(s,tfwd,acode,lcode,avar,lvar,optres)
TabProc *s;
BOOL tfwd;	/* Vrai si Forward deja alloue */
BINAIRE acode,lcode;
BINAIRE avar,lvar;
BINAIRE optres;
{
int i;
BYTE *t,*ptlcode;

/* #OK: 21/07/00 (begin) */
t=0;
ptlcode=0;
/* #OK: 21/07/00 (end) */

		if ( ! tfwd ) {

			t = All_Desc(3,16,&adsproc);

			if ( s->forward )
				s->adesc = t;

			s->ads = adsproc; /* conserver le descripteur */
			adsproc += 16;

		} else {
			t = s->adesc;
		}

		t = bintobyte(t,acode);
		ptlcode = t;
		t = bintobyte(t,lcode);
		t = bintobyte(t,avar);
		t = bintobyte(t,lvar);
		/* adresse de la table des constantes locales */
		t = bintobyte(t,0);
		/* longueur de la table des variables locales */
		t = bintobyte(t,0);
		/* completer avec 2 octets a zero pour l'executeur */
		for (i = 0; i < 2; i++)
			*t++ = 0;
		/* Pose le statut de la procedure RESIDENT / PUBLIC */
		t = bintobyte(t,optres);

		return(ptlcode);
}
extern BINAIRE adsseg;


BYTE *mksegdesc(s,tfwd,numseg,acode,lcode,avar,lvar,acst,lcst,optres)
TabSeg *s;
BOOL tfwd;	/* Vrai si Forward deja alloue */
BINAIRE numseg;
BINAIRE acode,lcode;
BINAIRE avar,lvar;
BINAIRE acst,lcst;
BINAIRE optres;
{
int i;
BYTE *t,*ptlcode;

		if ( ! tfwd ) {
			t = All_Desc(6,24,&adsseg);
			if ( s->fwd )
				s->adesc = t;
			s->ads = adsseg;  /* conserver le descripteur */
			adsseg += 24;
		} else {
			t = s->adesc;
		}

		t = bintobyte(t,numseg);
		t = bintobyte(t,acode);
		ptlcode = t;
		t = bintobyte(t,lcode);
		t = bintobyte(t,avar);
		t = bintobyte(t,lvar);
		/* Pose le statut de la procedure RESIDENT / PUBLIC */
		t = bintobyte(t,optres);
		/* adresse de la table des constantes locales */
		t = bintobyte(t,acst);
		/* longueur de la table des variables locales */
		t = bintobyte(t,lcst);
		/* completer avec 8 octets a zero pour l'executeur */
		for (i = 0; i < 8; i++)
			*t++ = 0;

		return(ptlcode);
}


BINAIRE mkdcldesc(glb,ext,pasptr,t,l,d1,d2,svdeclext,svfldptr,svlgptrfld,svadrptr)

/**********************************************************************
 * 	Creation d'un descripteur.
 * 	Le descripteur est insere dans la table correspondante,
 * 	a l'adresse courante, si une sous-table doit etre allouee,
 * 	peut arreter la traduction en cas de debordement memoire.
 *
 * 	En ver15 :
 *          	Nouveau descripteur de DCL
 *          	3 nouveaux types PTR, REDEF PTR, PTR REDEF PTR
 *
 *		En version 2.2a :
 *					Pendant la phase de definition, le descripteur n'est pas
 *					construit, la fonction est appelee pour obtenir l'adresse
 *					d'implementation
 *
 *		glb		(IN)	Variable globale
 *		ext		(IN)	Variable externe
 *		pasptr	(IN)	TRUE si non pointeur
 *		t			(IN)	Type
 *		l			(IN)	Longueur
 *		d1			(IN)	Dimension 1
 *		d2			(IN)	Dimension 2
 *		svdeclext (IN)	FIELD=M->svdeclext=0, FIELD=E->svdeclext=MEMEXT, FIELD=no->svdeclext=no
 *							rajout pour l'optimisation: au moment de la premiere utilisation, la connaissance de 
 *							de la variable globale declext était perdue..., il a fallu la memoriser dans la table des symboles
 *							Avant le 19/03/99 svdeclext = declext (var globale)
 *    svfldptr (IN)	
 *		svlgptrfld (IN)
 *		svadrptr (IN)	
 **********************************************************************/
BOOL glb;
BOOL ext;
BOOL pasptr;
BYTE t;
BINAIRE l,d1,d2;
BYTE svdeclext;
BOOL svfldptr;
int svlgptrfld; /* longueur du pointeur redefinit par Field */
BINAIRE svadrptr;
{                                       /* mkdcldesc */
	register BYTE *desc;
	register BYTE *debug;
	register BINAIRE lgdesc;
	long int lgvar = 1L;
	int choix;

	lgdesc = 4;             /* longueur min d'un descripteur en octets */

	/* calcul longueur du descripteur suivant les caracteristiques */
	/* et en meme temps, calcul encombrement de la variable */

	if (t == TBIN2) lgvar = 2L;
	else if ((t == TBCD) || (t == TSTR)) {
		lgdesc += 2; lgvar = (long) l;
	}
	if (d1 != 0) {
		lgdesc += 2;
		lgvar = lgvar * bintolong(d1);
	}
	if (d2 != 0) {
		lgdesc += 2;
		lgvar = lgvar * bintolong(d2);
	}
	if ( svfldptr ) { /* redefinition de zone pointee */
		lgdesc +=2;
	}
	if (svdeclext != 0) lgdesc +=2;
	if (ext) {
		choix=5;
		desc = All_Desc(choix,lgdesc,&adsdclextcr); /* attrib. du descripteur */
	} else {
		choix = (glb) ? 0 : 1;
		desc = All_Desc(choix,lgdesc, (glb) ? &adsdcl_glb : &adsdcl); /* attrib. du descripteur */

	}
	debug = desc;
	/* Mise en forme 1er octet */
	*desc = t;                      /* type de donnee */
	if (d1 != 0) *desc |= PRIMARY_INDEX;     /* 1ere dimension */
	if (d2 != 0) *desc |= SECOND_INDEX;     /* 2eme dimension */
	desc++;

	/* Mise en forme 2eme octet */
	if ( pasptr == FALSE ) { /* C'est un pointeur !!! */
		if ( svfldptr == TRUE ) { /* redefinition d'un champ pointe */
			if ( svdeclext & 0x0F ) {
				/* erreur */
				erreur(USUAL,ersymb3); adrimpl = 0L;
			} else
				*desc++ = ( svdeclext & PRIMARY_INDEX ) + 0xB0;
		} else
			if ( svdeclext & 0x0F ) {
				/* erreur */
				erreur(USUAL,ersymb3); adrimpl = 0L;
			} else
				*desc++ = ( svdeclext & PRIMARY_INDEX ) + 0x90;
	} else {
		if ( svfldptr == TRUE ) { /* redefinition d'un champ pointe */
			if ( svdeclext & 0x0F ) {
				/* erreur */
				erreur(USUAL,ersymb3); adrimpl = 0L;
			} else
				*desc++ = ( svdeclext & PRIMARY_INDEX ) + 0xA0;
		} else
			*desc++ = svdeclext;      /* en memoire ou externe */
	}

	/* Dans le cas d'une redefinition de zone pointee
		on garde l'adresse du descripteur de ce pointeur
	*/
	if ( svfldptr == TRUE ) {
		desc = bintobyte(desc,(BINAIRE) svadrptr);
	}
	/* Mise en forme 3eme octet */

	/* mettre l'adresse d'implantation */
	if ( ! ext )
		desc = bintobyte(desc,(BINAIRE) adrimpl);
	else
		desc = bintobyte(desc,(BINAIRE) 0xFFFF);

	if (svdeclext != 0)
		if ( ! ext ) { 
			desc = bintobyte(desc,(BINAIRE) (adrimpl >> 16));
		} else {
			desc = bintobyte(desc,(BINAIRE) 0xFFFF);
		}

	/*
		Si c'est une variable externe :
			ne pas incrementer adrimpl et size_???
		Dans le cas d'un pointeur : le pointeur d'implantation avance de
		la taille du ptr !!! et non de la variable pointee

	*/
	if ( ! ext ) {
		if ( pasptr == FALSE )
			adrimpl += LGSTDPTR;
		else 
			adrimpl += lgvar;

		/* Test de depassement de zone pointee */
		if ( svfldptr == TRUE ) {
			if ( adrimpl > svlgptrfld ) { 
				erreur(USUAL,ersymb3); adrimpl = 0L; 
			}
		}

		if (svdeclext == 0) {             /* variable en memoire */
			if (adrimpl >= MXSEG) {
				erreur(USUAL,ersymb3); adrimpl = 0L;
			}
			if ((svfldptr == FALSE) && (size_dcl < (BINAIRE) adrimpl)) {
				size_dcl = (BINAIRE) adrimpl;
			}
		}
		else if (svdeclext == MEMEXT) {   /* variable en memoire etendue */
			if (adrimpl >= MXEXT) {
				erreur(USUAL,ersymb3); adrimpl = 0L;
			}
			if (size_xtm < adrimpl) {
				size_xtm = adrimpl;
			}
		}
	}

	if ((t == TBCD) || (t == TSTR)) /* longueur pour chaine ou BCD */
		desc = bintobyte(desc,l);
	if (d1 != 0)                    /* 1ere dimension */
		desc = bintobyte(desc,d1);
	if (d2 != 0)                    /* 2eme dimension */
		desc = bintobyte(desc,d2);


	return (lgdesc);
}                                       /* mkdcldesc */


BINAIRE mkcstgloloc(adsglo,ptadsloc)

/*      creation d'un descripteur de redirection de la table des 
 *	constantes locales vers la table des constantes globales
 */
BINAIRE adsglo;
BINAIRE *ptadsloc;
{                                       /* mkcstgloloc */
	register BYTE *desc;
	register BINAIRE lgdesc;

	lgdesc = 4;

	/* attribution du descripteur dans la table locale */
	desc = All_Desc(4,lgdesc,ptadsloc);

	*desc++ = (BYTE) 0; /* 0 en premier */
	*desc++ = (BYTE) 0x80; /* 80 en deuxieme */

	/* sauvegarde de l'adresse */
	*desc++ = (BYTE) ( adsglo % 256 );
	*desc++ = (BYTE) ( adsglo / 256	);

	return (lgdesc);
}                                       /* mkcstgloloc */


BINAIRE mkcststr(local,ptadsc,p)

/*      creation d'un descripteur pour une constante chaine,
 *      le descripteur est insere dans la table correspondante,
 *      a l'adresse courante, si une sous-table doit etre allouee,
 *      peut arreter la traduction en cas de debordement memoire.
 *      Si l'option est selectee, une recherche d'alias est effectuee.
 *
 *      si local vaut 2 : insertion dans la table des constantes globales
 *      si local vaut 4 : insertion dans la table des constantes locales
 */
BINAIRE local;
BINAIRE *ptadsc;
char *p;
{                                       /* mkcststr */
	register BYTE *desc;
	register BINAIRE lgdesc;

	lgdesc = (BINAIRE) Xstrlen(p);  /* longueur de la constante */
	if (flg_alias) {
		/* Detection d'identite (alias) des constantes */
		if ((glob_desc = matchcst(p,*(ptadsc),lgdesc,TRUE)) != 0xffff) {
			return(0);
		}
	}

	/* attribution du descripteur */
	desc = All_Desc(local,(lgdesc+1),ptadsc);

	*desc++ = (BYTE) lgdesc; /* longueur en premier */
	while (*p != EOSTR) *desc++ = (BYTE) *p++;
	return (lgdesc+1);
}                                       /* mkcststr */


BINAIRE mkcstbcd(local,ptadsc,p)

/*      creation d'un descripteur pour une constante BCD,
 *      le descripteur est insere dans la table correspondante,
 *      a l'adresse courante, si une sous-table doit etre allouee,
 *      peut arreter la traduction en cas de debordement memoire.
 *
 *      si local vaut 2 : insertion dans la table des constantes globales
 *      si local vaut 4 : insertion dans la table des constantes locales
 */
BINAIRE local;
BINAIRE *ptadsc;
BYTE *p;
{                                       /* mkcstbcd */
	BYTE *desc;
	BINAIRE i, lgbcd, lgdesc;

	lgbcd = ((BINAIRE) *p++); /* longueur de la donnee */
	lgdesc = lgbcd + 2;
	if (flg_alias) {
		/* Detection d'identite (alias) des constantes */
		if ((glob_desc = matchcst((char *)p,*(ptadsc),lgbcd,FALSE)) != 0xffff) {
			return(0);
		}
	}

	/* attribution du descripteur */
	desc = All_Desc(local,lgdesc,ptadsc);

	*desc++ = 0;            /* prefixer par 0 pour un BCD */
	*desc++ = (BYTE) lgbcd; /* mettre la longueur */

	/* Detection de la constante BCD -0 et transformation en +0,
	 * dans le cas contraire, recopie de la constante.
	 */
	if ((lgbcd == 1) && (*p == (BYTE) 0x00B0))
		*desc = (BYTE) 0x00C0;
	else {
		for (i = 0; i < lgbcd; i++)
			*desc++ = *p++;
	}
	return (lgdesc);
}                                       /* mkcstbcd */

/*
 *   Gestion des tables de symboles
 *------------------------------------*/

extern BOOL flglcst;
extern BOOL flg_lcst_code;

BINAIRE matchcst(p,adrmax,lgdesc,typstr)

/*      Recherche dans la table des constantes en cours de
 *      construction, une constante identique a celle pointee
 *      par 'p' et de longueur 'lgdesc'. La longueur de la table
 *      deja creee est de 'adrmax' octets. Si 'typstr' vaut TRUE
 *      la constante est de type chaine, sinon de type bcd.
 *      Si la constante est trouvee, on retourne son offset,
 *      sinon 0xffff.
 */

char *p;
BINAIRE adrmax;
BINAIRE lgdesc;
BOOL typstr;
{                                       /* matchcst */
	BINAIRE i,k,adrdeb,lim;
	register BINAIRE j;
	char *d; /* ver15 */
	BOOL found;

	for (i=0 ; i<MAXCDESC ; i++) {
		adrdeb = SIZETDESC * i;
		if ( flglcst && flg_lcst_code ) {
			d = lcst_tdesc[i];
		} else {
			d = cst_tdesc[i];
		}
		if (d == GenericNULL(BYTE)) {
			return(0xffff);
		}
		j = adrmax - adrdeb;
		j = (j > SIZETDESC) ? (SIZETDESC) : (j);
		lim = (typstr) ? (j-lgdesc) : (j-lgdesc-1);
		for (j=0 ; j<lim ; j++) {
			if (adrdeb+j == adrmax)
				return(0xffff);
			if (typstr) {
				if (*(d+j) == (char) lgdesc) {
					found = TRUE;
					for (k=0 ; k<lgdesc ; k++) {
						if (*(p+k) != *(d+j+k+1)) {
							found = FALSE;
							break;
						}
					}
					if (found)
						return(adrdeb+j);
				}
			}
			else {
				if ((*(d+j) == 0) && (*(d+j+1) == (char) lgdesc)) {
					found = TRUE;
					for (k=0 ; k<lgdesc ; k++) {
						if (*(p+k) != *(d+j+k+2)) {
							found = FALSE;
							break;
						}
					}
					if (found)
						return(adrdeb+j);
				}
			}
		}
	}

	return(0xffff);
}                                       /* matchcst */


static BYTE *All_Desc(choix,lg,adrdesc)

/*      Attribution/Allocation d'un descripteur de lg octets.
 *      Pour : une variable globale si choix vaut 0, une variable locale
 *      si choix vaut 1, une constante si choix vaut 2., ou une procedure
 *      si choix vaut 3.
 *
 *      en version 1.5 : si choix vaut 4 constante STR/BCD locale
 *                       si choix vaut 5 variable externe
 *			 si choix vaut 6 segment
 */
int choix;
BINAIRE lg;
BINAIRE *adrdesc;
{                               /* All_Desc */
	BINAIRE numtab,offset;
	BYTE *tdesc;

    /* #OK: 21/07/00 (begin) */	
	tdesc=0;
	/* In EXA allocate nb_dcl_global * 10 bytes =>
	   nb_dcl_global < (64Kb / 10) = 6554 */
	if (choix == 0)
	  {
	    if (nb_dcl_global >= 6553)
           erreur(FATALE,ersymb11);
	  }	  
	/* #OK: 21/07/00 (end) */

	numtab = *adrdesc / SIZETDESC;
	offset = *adrdesc % SIZETDESC;	

    /* #OK: 21/07/00 (begin) */
	/* Max number segments = 1360 - 1 = 1359 */
	if ((choix == 6) && (((*adrdesc) + 40) / SIZETDESC >= MAXTDESC)) 
		erreur(FATALE,ersymb17);
    /* #OK: 21/07/00 (end) */	

	/* Detecte le debordement de 64 Ko */
	if ((long)((long)*adrdesc+(long)lg) >= 65536L)
        /* #OK: 21/07/00 (begin) */	    
		// erreur(FATALE,ersymb4); // commented by #OK
		switch (choix) {
	    	case 0: erreur(FATALE,ersymb11); break;
            case 1: erreur(FATALE,ersymb12); break;
            case 2: erreur(FATALE,ersymb13); break;
            case 3: erreur(FATALE,ersymb14); break;
            case 4: erreur(FATALE,ersymb15); break;
            case 5: erreur(FATALE,ersymb16); break;
            case 6: erreur(FATALE,ersymb17); break;
	    }
        /* #OK: 21/07/00 (end) */				

	/* Traite le debordement des sous-tables :
	 * Pour les variables, padding a 0x0010 jusqu'a la fin de la
	 * sous-table correspondante
	 * Pour les procedures, jamais de padding (lgr multiple de 16)
	 * A partir de la version 1.4, padding a nul des constantes
	 * pour pouvoir analyser sequentiellement la table des constantes
	 * Padding de la table des segments : 00
	 */
	if ((offset + lg) > SIZETDESC) { /* debordement sous table courante */
		if ((choix == 0) || (choix == 1) || (choix == 5)) {
			if (choix == 0) tdesc = glb_tdesc[numtab];
			else if (choix == 1) tdesc = lcl_tdesc[numtab];
			else tdesc = ext_tdesc[numtab];
			tdesc += offset;
			while (offset < SIZETDESC) {
				*tdesc++ = (BYTE) 0x0010; offset++;
			}
		}
		else {
			if ((choix == 2) || (choix == 4)) {
		       /* constantes ou constantes locales */
				if (choix == 2)
					tdesc = cst_tdesc[numtab];
				else
					tdesc = lcst_tdesc[numtab];
				tdesc += offset;
				while (offset < SIZETDESC) {
					*tdesc++ = (BYTE) 0; offset++;
				}
			} else {
				if (choix == 6) {
		       		/* segment */
					tdesc = seg_tdesc[numtab];
					tdesc += offset;
					while (offset < SIZETDESC) {
						*tdesc++ = (BYTE) 0; offset++;
					}
				}
			}
		}

		numtab++; offset = 0;    /* donc passer a la suivante */
		*adrdesc = numtab * SIZETDESC;
	    /* #OK: 21/07/00 (begin) */		
		// Commented next lines:
		// if (numtab >= MAXTDESC) { /* debordement nb sous tables ..? */
		//	if ((choix != 2) && (choix !=4))
		//	/* repit pour les constantes ... */
		//		erreur(FATALE,ersymb4);
		//	else if (numtab >= MAXCDESC)
		//		erreur(FATALE,ersymb4);	    		
		// }
	    /* #OK: 21/07/00 (end) */
	}	

	switch (choix) {
	    /* #OK: 21/07/00 (begin) */		
		case 0: if (numtab >= MAXTDESC) erreur(FATALE,ersymb11);
			    tdesc = glb_tdesc[numtab]; break;
		case 1: if (numtab >= MAXTDESC) erreur(FATALE,ersymb12);
			    tdesc = lcl_tdesc[numtab]; break;
		case 2: if ((hd_tcode.flg_plus & 4) && (numtab >= MAXTDESC)) 
					erreur(FATALE,ersymb13);
			    else if (numtab >= MAXCDESC) 
					erreur(FATALE,ersymb13);
			    tdesc = cst_tdesc[numtab]; break;
		case 3: if (numtab >= MAXTDESC) erreur(FATALE,ersymb14);
			    tdesc = pr_tdesc[numtab]; break;
		case 4: if ((hd_tcode.flg_plus & 4) && (numtab >= MAXTDESC)) 
					erreur(FATALE,ersymb15);
			    else if (numtab >= MAXCDESC) 
					erreur(FATALE,ersymb15);
			    tdesc = lcst_tdesc[numtab]; break;
		case 5: if (numtab >= MAXTDESC) erreur(FATALE,ersymb16);
			    tdesc = ext_tdesc[numtab]; break;
		case 6: if (numtab >= MAXTDESC) erreur(FATALE,ersymb17);
			    tdesc = seg_tdesc[numtab]; break;
        /* #OK: 21/07/00 (end) */	
	}
	if (tdesc == GenericNULL(BYTE)) { /* sous table non encore allouee */
		tdesc = All_Tabdesc();
		if (tdesc == GenericNULL(BYTE))
			erreur(FATALE,errmem);  /* debordement memoire */
		switch (choix) {
			case 0: glb_tdesc[numtab] = tdesc; break;
			case 1: lcl_tdesc[numtab] = tdesc; break;
			case 2: cst_tdesc[numtab] = tdesc; break;
			case 3: pr_tdesc[numtab] = tdesc; break;
			case 4: lcst_tdesc[numtab] = tdesc; break;
			case 5: ext_tdesc[numtab] = tdesc; break;
			case 6: seg_tdesc[numtab] = tdesc; break;
		}
	}
	return ( (tdesc + offset) );
}                               /* All_Desc */

/* ----------------------- Fin du fichier : table.c ---------------------- */

