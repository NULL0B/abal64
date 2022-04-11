/*
 *      Projet  : ABAL                  Copyright Amenesik / Sologic s.a. (c) 1990, 1995
 *      Module  : ATR
 *      Fichier : SYMBOLES.C
 *      Version : 2.2b
 *      Date    : 10/08/86
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Gestion des tables de symboles]
 * 
 */

 /*
 * Mises a jour :
 * ------------
 * 18/07/90 : Mise en conformite avec les versions 1.2e / 1.3a / 1.4a
 * 28/08/90 : Introduction de l'appel depuis l'ensemble integre 1.4
 * 14/09/90 : Interdit les declarations de procedures avec passage de tableaux
 * 24/10/90 : Autorise 65535 elements de tableau
 * 14/01/91 : Evite la double fermeture en cas d'erreur fatale
 * ---------- Sortie 1.2g / 1.3d --------------------------------------
 * 26/12/91 : Suppression minuscules accentuees dans les sources
 * 02/03/92 : Detection et transformation des constantes BCD -0
 * --------------------------------------------------------------------
 * 16/04/93 : Modification de typdesc() Pb Collision FIELD=E,PTR  
 * 05/05/93 : Modification de inmod() Avant pas d'erreur sur nom de 
 *                 module == mot reserve
 *	02/09/93 : modif like sur type
 * 06/09/93 : modif like sur position longueur type pointeur 90(+4),
 *		A0(+4), B0(+6) : newdcl newdclarg
 *	24/09/93 : erreur lors de redefinition d'un pt sur longueur
 *	30/09/93 : pas de declaration de pointeur en field=E ou no
 *	07/04/94 : Ignore la definition de Field=E en local (Warning)
 *		   pour APLUS.
 *	25/04/94 : Probleme remontee d'erreur mauvais para sur extern proc
 *	05/05/94 : Declaration de procedures sans parametres et sans ()
 *		   newargs
 * --------------- 2.1c ------------------------------------------
 *	20/06/94 : Exception lorsqu'une variable externe etait deja declaree
 *	25/10/94 : cohabitation des constantes globales et locales
 *	22/11/94 : mise a niveau constante locale
 *	23/11/94 : modification gestion des extern field 
 *		   on autorise le decoupage d'extern field  en plusieurs
 *		   morceaux.
 * --------------- 2.1d ------------------------------------------
 *	09/12/94 : retour a la normale FIELD=no log apres redef PTR
 *	21/12/94 : pb lexical() : ldgo.seg mod.idseg pas de reinit usc.excode
 *	22/11/95 : version dediee 2.1
 *	10/08/96 : adaptations Windows
 * --------------- 2.2a ------------------------------------------
 * 17/02/97 : Debut revision 2.2a
 * 17/02/97 : Nouveau mot cle : STRUCT
 *				  Nouvelles fonctions : new_struct(), newdcl_struct(), newvar_noeud(),
 *												get_noeud_size(), get_struct_size()
 *												get_last_struct(), findstruct(), trouve_var(),
 *												complete_dcl()
 *				  Fonctions modifiees :	initsymb(), newdcl(), newvar(), findvar(),
 *												newargs()
 * 07/03/97 : Prototype de findvar() modifie, reprise de tous les appels
 * 29/04/97 : Protype de newproc() modifie pour pouvoir ne pas effectuer
 *				  la creation du descripteur dans la fonction	
 * 02/07/97 : Modifications de newvar_noeud(), new_struct(), newdcl() pour l'optimisation des
 *			  variables.
 * 26/11/98 : Correction du bug "var in mod1"-> var.mod1 : conflit avec les structures
 * 19/03/99 : Optimisation des FIELD=E, FIELD=no
 * 13/09/99 : (#AT) Bug ATR 6 fixed: "Type d'operande incorrect"
 *            (Prohibit to pass integer parameters to procedure if formal parameters has type ptr).
 * 09/07/99 : (#SP) Bug ATR ?? fixed: Modification of newargs() proc.
 *            The result of the allocated descriptor for the variable was analysed
 *            after first access to this descriptor (NULL when the local parameter
 *            has the same name as one of the constants because the descriptor is
 *            not allocated in this case).
 *            So we must check the return value before accessing to the descriptor.
 * 08/10/99 : (#OK) Bug ATR 42 fixed: "segment 0 absent in program".
 * 11/10/99 : (#SP) Enhancement ATR 23: Local named constants.
 *            - initlcst(): modified to initialise the local named constants lists deb_bincst_local and deb_bcdcst_local
 *            - finlcst(): now has one more parameter: the new parameter is an indicator
 *             of debug info (option) used to save symbols (names of the local named constants)
 *             to the wdg/dbg file. These names are token from the local named constants lists: deb_bincst_local and deb_bcdcst_local.
 *             Also these two list should be released in this function.
 *            - new_local_cst(): a new function, add a new local named constant.
 *            - findcst(): there were 2 passes to find the constant: for deb_bincst and deb_bcdcst
 *            Now there are 4 passes and first of all we are looking for the local constants in 
 *            the deb_bincst_local and bcd_cst_local lists.
 *            - newconst_local(): a new function, adds description of the local named constant to the list.
 * 09/12/99 : (#OK) Bug ATR 6 fixed. "Type d'operande incorrect".
 * 04/02/00 : (#SP) Bug ATR 41 fixed. Modified functions newdcl(), newdclarg().
 *            For the members of FIELD=m,... the length of variable must be taken from 6-th byte but not 4-th.
 *            There two possible cases for the type of FIELD MEMBER - 0xA0 (common) and
 *            0xB0 (pointer), so before: only 0xB0 analysed, now: both.
 * 22/02/00 : (#OK)  Bug ATR 44 (EXA 66) fixed. "Debordement espace de donnees", because
 *            allocation memory for the variable in the "extern proc(var$=...)"
 * 21/07/00 : (#OK) ATR NR. Bug fixed. Overflow description table. Add new error messages.
 * 26/06/01 : (#OK) Bug fixed. Exception in ATR was occured on the program const2.s.
 * --------------- 2.2b ------------------------------------------
 *	06/11/02 : (#IJM) : Various modifications for the EXTERN CALL mechanisms and many
 *	           other stupid bug fixes.
 */

/* Fichier de definition */
/* --------------------- */
#include "tr.h"
#include "fuser.h"
#include "syntaxe.h"
#include "tsymb.h"
#include "tcode.h"
#include "codes.h"
#include "abal.h"		/* #IJM 06/11/02 */

#define _SYMBOLES
#include "symboles.hs"
#include "symboles.he"

		/*-----------------------------------*
		 *      primitives globales
		 *-----------------------------------*/
/* #OK: 09/12/99 (begin) */
#ifdef __ATR22__
#define ALLOC_TABSYMB_ITM (TabSymb *) XNmalloc("Symb",sizeof(TabSymb))
//#define ALLOC_EXTREF_ITM (ExtRef *) XNmalloc("Ref",sizeof(ExtRef))
//#define ALLOC_TYPE_ITM (Type *) XNmalloc("Type",sizeof(Type))
#endif
/* #OK: 09/12/99 (end) */

void initsymb()

/*      initialisation : tables vides           */
{                               /* initsymb */
	int k;

	deb_glbsymb=deb_lclsymb=deb_bincst=deb_bcdcst=GenericNULL(TabSymb);
	deb_extsymb=GenericNULL(TabSymb);
	deb_tproc = GenericNULL(TabProc);
	deb_tetiq = GenericNULL(TabEtiq);
	/* structure ... partir de la 2.2a */
	deb_struct = GenericNULL(TabStruct);
	/* Clause with ... partir de la 2.2a */
	deb_with = GenericNULL(TabWith);
	/* 2.2 : Recherche des variables dans le source pour outil an 2000 */

	RacTbusr = GenericNULL(Tbusr);          /* init ptr tables fct util */
	RacTabRt = GenericNULL(TabRt);
	TusrRef = GenericNULL(TabuRef);

	TvarRef = TcstRef = GenericNULL(RelRef);

	for (k = 0; k < MAXTDESC; k++)
      	pr_tdesc[k] = seg_tdesc[k] = glb_tdesc[k] = lcl_tdesc[k] = GenericNULL(BYTE);

	for (k = 0; k < MAXCDESC; k++)
		cst_tdesc[k] = GenericNULL(BYTE);

	nb_refpext = 0;

	nb_refsext = 0;

	size_dcl = 0; size_xtm = 0L;

	/* Initialisation de la table des relocs de var externes */
	initextref();
	
	modextcr = 0xFFFF;

	psuc_lst = GenericNULL(PSUCInfo);

	symbinit = TRUE;
}                               /* initsymb */


void finsymb(integre)

/*      liberation de la memoire allouee par le module
 *      en fin de traduction
 *      (cas de l'ensemble integre ou de la demande de warnings)
 */
BOOL integre;
{                               /* finsymb */
	int     k;

	if (!symbinit)
		return;

	/* Liberartion de la table des reloc de var externes */
	libextref();

	if (integre) {
		/* liberer la table des procedures */
		if (deb_tproc != GenericNULL(TabProc))
			libproc(deb_tproc);
		/* liberer la table des segments externes */
		if (deb_tseg != GenericNULL(TabSeg))
			libseg(deb_tseg);
	}
	if (integre || (!nowarn)) {
		TabStruct *s1, *s2;
		TabWith *w1, *w2;

		/* liberer les tables au niveau global */
		if (deb_glbsymb != GenericNULL(TabSymb))
			libnoeud(deb_glbsymb);
		if (deb_bincst != GenericNULL(TabSymb))
			libnoeud(deb_bincst);
		if (deb_bcdcst != GenericNULL(TabSymb))
			libnoeud(deb_bcdcst);
		if (deb_extsymb != GenericNULL(TabSymb))
			libnoeud(deb_extsymb);
		freelocal();
		/* Tableau des structures ... partir de la 2.2a */
		s1 = deb_struct;
		while (s1 != GenericNULL(TabStruct)) {
			s2 = s1;
			s1 = s1->suiv;
			Free_Struct(s2);
		}
	  /* Tableau des with ... partir de la 2.2a */
		w1 = deb_with;
		while (w1 != GenericNULL(TabWith)) {
			w2 = w1;
			w1 = w1->suiv;
			Free_With(w2);
		}
	}
	if (integre) {
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
	   libtabref(TvarRef); libtabref(TcstRef);
	}

	/* liberation tables fct utilisateur et autres */
	if (integre) {
		libfusr();
		librlien();
		if (deb_tetiq != GenericNULL(TabEtiq))
			libetiq(deb_tetiq);
	}

	LibPSUCTable(PSUC_ALL);

	/* Signale que la fermeture a deja eu lieu pour ne pas la refaire */
	symbinit = FALSE;
}                               /* finsymb */


void initlcst()
{
int k;
	/* Initialisation des tables des constantes locales */

	flg_lcst_code = TRUE;

/* #SP: 11/10/99 (begin) */
#ifndef __ATR22__
	if ( flglcst == TRUE ) {
		ladscst=0;      /* Pas de constantes locales a priori */

		for (k = 0; k < MAXCDESC; k++)
			lcst_tdesc[k] = GenericNULL(BYTE);
	}

#else
	/* Initialize to supply local named constants */
	deb_bincst_local = GenericNULL(TabSymb);
	deb_bcdcst_local = GenericNULL(TabSymb);
	ladscst=0;      /* Pas de constantes locales a priori */

	for (k = 0; k < MAXCDESC; k++)
		lcst_tdesc[k] = GenericNULL(BYTE);
#endif
/* #SP: 11/10/99 (end) */
}


/* #SP: 11/10/99 (begin) */
#ifndef __ATR22__
void finlcst(k,pcode)
#else
void finlcst(k,pcode,WithDebugInfo)
#endif
/* #SP: 11/10/99 (end) */
BINAIRE k;
BYTE *pcode;
/* #SP: 11/10/99 (begin) */
#ifdef __ATR22__
BOOL WithDebugInfo;
#endif
/* #SP: 11/10/99 (end) */
{
	flg_lcst_code = FALSE;

/* #SP: 11/10/99 (begin) */
#ifndef __ATR22__
	if ( flglcst == TRUE ) {

		/* Sauvegarde des infos de la table des constantes locales */
		/* Sauvegarde dans le fichier traduit de la table des constantes */
		/* locales */

		if ((ladscst != 0) && (pcode != GenericNULL(BYTE))) {
			k = vid_tcst(NOAT,ladscst,lcst_tdesc);
		}

		patchreftab(k);

		if ((ladscst != 0) && (pcode != GenericNULL(BYTE))) {
			bintobyte(pcode,k);
			bintobyte(pcode+2,ladscst);
		}

		for (k = 0; k < MAXCDESC; k++) {
			if (lcst_tdesc[k] != GenericNULL(BYTE)) Free_Tabdesc(lcst_tdesc[k]);
		}
	}
#else

	if ((WithDebugInfo)) {
		if ( deb_bincst_local != GenericNULL(TabSymb) ) {
			vid_tncstbin(NODBG,deb_bincst_local);
		}
		if ( deb_bcdcst_local != GenericNULL(TabSymb) ) {
			vid_tncstbcd(NODBG,deb_bcdcst_local);
		}
	}

	if (flglcst == TRUE ){
		if ((ladscst != 0) && (pcode != GenericNULL(BYTE))) {
			k = vid_tcst(NOAT,ladscst,lcst_tdesc);
		}

		patchreftab(k);

		if ((ladscst != 0) && (pcode != GenericNULL(BYTE))) {
			bintobyte(pcode,k);
			bintobyte(pcode+2,ladscst);
		}
	}

	if (deb_bincst_local != GenericNULL(TabSymb))	libnoeud(deb_bincst_local);
	if (deb_bcdcst_local != GenericNULL(TabSymb))	libnoeud(deb_bcdcst_local);

	for (k = 0; k < MAXCDESC; k++) {
		if (lcst_tdesc[k] != GenericNULL(BYTE)) Free_Tabdesc(lcst_tdesc[k]);
	}

	/* #OK: 26/06/01 (begin) */
	deb_bincst_local = GenericNULL(TabSymb);
	deb_bcdcst_local = GenericNULL(TabSymb);
	/* #OK: 26/06/01 (end) */

#endif
/* #SP: 11/10/99 (end) */

} 


/*
	Cette fonction recupere le type d'une variable dans un descripteur
	et indique si c'est un pointeur.
	0 : #, 1 : %, 2 : BCD, 3 : STR ->>> + 8 pointeur sur ...
*/
BYTE typdesc(adesc)
BYTE *adesc;
{                               /* typdesc */
BYTE t;

	t = ( *(adesc+1) & 0x80 ? *(adesc+1) & is_typ_ptr : 0 );

	if ( t != 0 )
		t = 8 + ( *adesc & typ_in_desc );
	else
		t = *adesc & typ_in_desc;

	return(t);
}                               /* typdesc */


/*
	Cette fonction permet de recuperer le type
	en supprimant la composante pointeur
*/
BYTE masqueptr(typ)
BYTE typ;
{                               /* masqueptr */
	return (typ & 0x07);
}                               /* masqueptr */


BOOL ismemglobale(t)
BYTE t;
{
	if ( t != 0 ) {
		if ( t & 0x7F )
			return(FALSE);
	} 
	return(TRUE);   
}


BINAIRE newdclarg(niv,pasptr,ptadesc,ptadvar)

/*      declaration d'une variable, niv est vrai pour le niveau global
 */
BOOL niv;
BOOL pasptr;
BYTE **ptadesc;
BINAIRE *ptadvar;
{                                       /* newdclarg */
	register BYTE t;
	BINAIRE l,d1,d2,ld;
	BINAIRE nb_dcl = 0;
	BOOL    flg;
	Type		*type;

	char nom[LGIDENT];

if (usc.code == IDENT) {

	Xstrcpy(nom,usc.v.pval);
	t = getype(TRUE);

	if (t == TLIKE) {
BYTE *adesc;
BINAIRE advar;
		if (usc.code != IDENT)
			goto errdecl;

		/* Recuperation de l'adresse du descripteur de la variable */

		adesc = findvar( usc.v.pval,GenericNULL(BYTE),&advar,GenericNULL(TabSymb *),TRUE);

		if ( adesc == GenericNULL(BYTE) ) {
			goto errdecl;
		}
		t = typdesc(adesc) & 0x03;
		if ( IS_TSTR(t) ) {
/* #SP: 04/02/00 (begin) */
			/*if ( *(adesc+1) == 0xB0) {	Commented by #SP */
			if ( *(adesc+1) == 0xB0 || *(adesc+1) == 0xA0) {
/* #SP: 04/02/00 (end) */
				l = bytetobin(adesc+6);
			} else {
				l = bytetobin(adesc+4);
			}
		} else {
			goto errdecl;
		}

		d1 = 0; d2 = 0;

		if ( *adesc & PRIMARY_INDEX )
			d1 = bytetobin(adesc+6);

		if ( *adesc & SECOND_INDEX )
			d2 = bytetobin(adesc+8);

	} else {

		if (t == TSTR) {
			if (usc.code == EGAL) {
				lexical();
				if (recbincst(&l)) {    /* constante numerique entiere */
					if (negbin(l) || (l == 0))
						l=0; /* long. negative interdite */
					if (l > LGSTR)
						l=0;
				} else {
					l=0;
				}
			} else {
				l = LGSTDSTR;   /* lg standard chaine */
			}
		} else {
			l=0;
		}
		if (l == 0) goto errdecl;
	}
	d1 = d2 = 0;

	ld = mkdcldesc(niv,FALSE,pasptr,t,l,d1,d2, declext, fldptr, lgptrfld, adrptr); /* construire le descripteur */
	flg = FALSE;

	/* nouvelle variable */
	type = All_Type();
	type->type = t;
	type->l = l;
	type->d1 = d1;
	type->d2 = d2;
	type->pStruct = GenericNULL(TabStruct);
	type->pasptr = pasptr;


	/* #BG	if (!newvar(niv ? &deb_glbsymb : &deb_lclsymb, niv, FALSE,nom,flg,FALSE,FALSE,type))*/
	if (!newvar(niv ? &deb_glbsymb : &deb_lclsymb, niv, FALSE,nom,flg,FALSE,FALSE,type,FALSE))
		erreur(USUAL,ersymb2); /* deja declare ! */
	else {

		/* mise a jour adr descripteur dans tvar */
		if (niv) adsdcl_glb += ld; 
		else adsdcl += ld;
		nb_dcl++;
		*ptadesc = findvar(nom,GenericNULL(BYTE),ptadvar,GenericNULL(TabSymb *),TRUE);
	}

} else {                        /* erreur de declaration */
errdecl:
		erreur(USUAL,ersymb1); sfdln();
}
	return (nb_dcl);
}                                       /* newdclarg */

BOOL newvar_noeud(pTabSymb,pSymbStruct,niv,ext,bArgs,pNbrDcl)

/**********************************************************************
 *		Declaration d'un noeud.
 *		La fonction est appelee par new_struct pour enregistrer les
 *		informations relatives aux donnees membres d'une structure.
 *		A partir de la 2.2a
 *		pTabSymb		(OUT)	Pointeur sur un pointeur de liste type TabSymb
 *								pointeur next de la structure TabSymb
 *		pSymbStruct	(IN)	Pointeur sur TabSymb, point d'entree sur les
 *								donnees membres de la structure
 *		niv			(IN)	TRUE pour une variable globale
 *		ext			(IN)	TRUE pour une variable externe
 *		bArgs			(IN)	TRUE si utilise pour le traitement d'arguments
 *								... une procedure
 *		pNbrDcl		(OUT)	Nombre de variables declarees
 *
 *						(RET) TRUE si au moins une variable declaree
 **********************************************************************/
TabSymb 		**pTabSymb, *pSymbStruct;
BOOL 			niv,ext,bArgs;
BINAIRE			*pNbrDcl;
{
	Type		*pType, *pType2;
	long int	adrimpl_avant;

	
	if (pSymbStruct!= GenericNULL(TabSymb)){

	pType = pSymbStruct->type;

	/* La donnee membre est une structure instanciee mais pas par pointeur
		car dans le cas d'une liste chainee, on se mord la queue (risque
		egalement hors pointeur mais non contr"le ce jour */
	if ( (pType->pStruct != GenericNULL(TabStruct)) && pType->pasptr) {
		TabStruct	*pStruct;

		pStruct = (TabStruct *)pType->pStruct;
		new_struct(pTabSymb,pSymbStruct->pid,niv,ext,FALSE,pType->pasptr,bArgs,pStruct,pNbrDcl,pType);
	}

	/* La donnee membre est d'un type elementaire */
	else {
		BINAIRE	ld;

		/* Pointeur sur structure, la taille est nulle si pointeur
			sur lui meme (liste chaŒnee) */
		if ( (pType->pStruct != GenericNULL(TabStruct)) && !pType->pasptr &&
			  !pType->l ) {
			TabStruct	*pStruct;

			pStruct = (TabStruct *)pType->pStruct;
			pType->l = pStruct->l;
		}

		/* En version 2.2a, le descripteur n'est plus construit au
			moment de la declaration */
		adrimpl_avant = adrimpl;
		ld = mkdcldesc(niv,ext,pType->pasptr, pType->type, pType->l, pType->d1, pType->d2 , declext, fldptr, lgptrfld, adrptr);

		if ( ext && (modextcr == 0xFFFF) ) {
			BYTE *advar;
			BINAIRE i;
			advar = findvar(pSymbStruct->pid,GenericNULL(BYTE),&i,GenericNULL(TabSymb *),TRUE); /* 20/06/94 */
			if ( advar != GenericNULL(BYTE) )
				erreur(USUAL,ersymb2); /* deja declare ! */
		}
		/* Ajouter la donnee membre dans les symboles */
		pType2 = All_Type();
		pType2->type = pType->type;
		pType2->l = pType->l;
		pType2->d1 = pType->d1;
		pType2->d2 = pType->d2;
		pType2->pStruct = GenericNULL(TabStruct);
		pType2->pasptr = pType->pasptr;
		pType2->adrimpl = adrimpl_avant;

		if (!newvar(pTabSymb, niv, ext, pSymbStruct->pid, FALSE, FALSE, FALSE, pType2, optimise_tables))
			return FALSE;
		else {
			if (! ext) {
				/* Dans le cas d'une optimisation, pas d'increment */
				if (!optimise_tables || bArgs)
				{
					if (niv) {
						adsdcl_glb += ld; //999999
						nb_dcl_global++;
					}
					else adsdcl += ld;
				}
			}
			else
				adsdclextcr +=ld;

			(*pNbrDcl)++;
		}
	}
	if (pSymbStruct->d != GenericNULL(TabSymb))
		newvar_noeud(pTabSymb, pSymbStruct->d, niv, ext, bArgs, pNbrDcl);

	if (pSymbStruct->g != GenericNULL(TabSymb))
		newvar_noeud(pTabSymb, pSymbStruct->g, niv, ext, bArgs, pNbrDcl);
	}
	return TRUE;
}

BOOL newdcl_struct(niv,ext,bStruct,pTabStruct,pNbrDcl)

/**********************************************************************
 *		Declaration d'une structure instanciee, analyse du source.
 *		A partir de la 2.2a
 *		niv			(IN)	TRUE pour une variable globale
 *		ext			(IN)	TRUE pour une variable externe
 *		bStruct		(IN)	Donnee membre d'une structure en mode apprentissage
 *		pTabStruct	(IN)	Reference ... un element de la
 *								liste deb_struct
 *		pNbrDcl		(OUT)	Nombre de variables declarees
 *
 *						(RET) TRUE si OK
 **********************************************************************/
BOOL 			niv, ext,bStruct;
TabStruct	*pTabStruct;
BINAIRE		*pNbrDcl;
{
	BOOL			bPtr = FALSE;
	Type			*pType;
	BINAIRE		d1, d2;
    
	do	{
   		/* #OK: 11/07/00 (begin) */
	    char*   save_pval;
	    BYTE*   save_pbcd;
		BINAIRE save_val;
		Tbusr*  save_ptusr;
        /* #OK: 11/07/00 (end) */

		lexical();
		/* Pointeur sur structure */
		if ((usc.code == PTR) || bPtr) {
			/* bPtr utilise pour la declaration de plusieurs
				pointeurs separes par des ',' */
			if (!bPtr)
				lexical();
			bPtr = TRUE;
		}
		pType = All_Type();
		d1 = d2 = 0;
		
		/* #OK: 11/07/00 (begin) */				
        save_pval=usc.v.pval; 
        save_pbcd=usc.v.pbcd; 
        save_val=usc.v.val; 
		save_ptusr=usc.v.ptusr;
        /* #OK: 11/07/00 (end) */

	  	lexical();
		if (usc.code == PAG) {  /* dimensions */			
			d1 = getdim();
			if (d1 == 0)
				return(FALSE);
			if (usc.code == VIG) {
				d2 = getdim();
				if (d2 == 0)
					return(FALSE);
			}
			if (usc.code != PAD)
				return FALSE;
			lexical();
            
			/* #OK: 11/07/00 (begin) */ 
			usc.v.pval=save_pval;
			usc.v.pbcd=save_pbcd; 
            usc.v.val=save_val; 
            usc.v.ptusr=save_ptusr; 			
            /* #OK: 11/07/00 (end) */
		}

		if (pType == GenericNULL(Type))
			erreur(FATALE,errmem);
		else {
			pType->type = TSTR;
			pType->l = pTabStruct->l;
			pType->d1 = d1;
			pType->d2 = d2;
			pType->pasptr = !bPtr;
			pType->pStruct = pTabStruct;
		}

			/* Pointeur sur structure, lgptrfld va etre teste
				dans mkdcldesc() en redefinition de zone pointee */
		if (bPtr) {
			lgptrfld = pTabStruct->l;
			//adrptr = ext ? adsdclextcr : niv ? adsdcl : (adsdcl | 0x8000);
			adrptr = ext ? adsdclextcr : niv ? adsdcl_glb : (adsdcl | 0x8000)  ;
		}
		if (!new_struct(niv ? ext ? &deb_extsymb : &deb_glbsymb : &deb_lclsymb,
							usc.v.pval,niv,ext,bStruct,!bPtr,FALSE,pTabStruct,pNbrDcl,pType)) {
	   	
			return(FALSE);
		}

	  	if ((usc.code != FDLN) && (usc.code != VIG)) {
			return(FALSE);
		}
	}
	while (usc.code == VIG);
}

BOOL new_struct(pTabSymb,nom,niv,ext,bStruct,pasptr,bArgs,pTabStruct,pNbrDcl,pType)

/**********************************************************************
 *		Declaration finale d'une structure instanciee.
 *		A partir de la 2.2a
 *		pTabSymb		(OUT)	Pointeur sur un pointeur de liste type TabSymb
 *								deb_glbsymb, deb_lclsymb, deb_extsymb ou autre
 *		nom			(IN)	Nom de l'instance
 *		niv			(IN)	TRUE pour une variable globale
 *		ext			(IN)	TRUE pour une variable externe
 *		bStruct		(IN)	Donnee membre d'une structure en mode apprentissage
 *		pasptr		(IN)	TRUE si variable non pointee
 *		bArgs			(IN)	TRUE si utilise pour le traitement d'arguments
 *								... une procedure
 *		pTabStruct	(IN)	Reference ... un element de la
 *								liste deb_struct
 *		pNbrDcl		(OUT)	Nombre de variables declarees
 *		pType			(IN)	Reference ... une structure Type utilisee uniquement
 *								si bStruct=TRUE
 *
 *						(RET) TRUE si au moins une variable declaree
 **********************************************************************/
TabSymb 		**pTabSymb;
char			*nom;
BOOL 			niv, ext,bStruct,pasptr,bArgs;
TabStruct	*pTabStruct;
BINAIRE		*pNbrDcl;
Type			*pType;
{
	BINAIRE 		ld;
	long int		adrimpl_avant, adrimpl_apres;
	TabSymb 		*pNewTabSymb;
	Type			*pType2;

	/* toutes les declarations en FIELD=E sont ignorees en LOCAL */
	if ( ! niv ) {
		if ( ! declext )
			flg_FEL = FALSE;
		if ( flg_FEL ) {
			sfdln();
			return (FALSE);
		}
	}

	/* Pas de pointeur en Field=E ou Field=no */
	if ( (declext != 0) && (! pasptr) ) {
		erreur(USUAL,ersymb1); sfdln();return(FALSE);
	}

	/* Mode apprentissage, imbrication de structures */
	if (bStruct) {
		TabSymb		*pTabSymb;

		if (!newvar(&pTabSymb, niv, FALSE, nom, FALSE, TRUE, TRUE, GenericNULL(Type), optimise_tables))
			erreur(USUAL, ersymb2);

		pTabSymb->type = pType;
	}
	else {
		/* Sauvegarde de l'adresse d'implantation courante */
		adrimpl_avant = adrimpl;

		/* En version 2.2a, le descripteur n'est plus construit au
			moment de la declaration */
		ld = mkdcldesc(niv,ext,pasptr,pType->type,pType->l,pType->d1,pType->d2, declext, fldptr, lgptrfld,adrptr);
		if ( ext && (modextcr == 0xFFFF) ) {
			BYTE *advar;
			BINAIRE i;
			advar = findvar(nom,GenericNULL(BYTE),&i,GenericNULL(TabSymb *),TRUE); /* 20/06/94 */
			if ( advar != GenericNULL(BYTE) )
				erreur(USUAL,ersymb2); /* deja declare ! */
		}

		/* Ajouter l'instance de la structure dans les symboles
			On demande ... ce que le contenu de pNewTabSymb soit modifie pour
			etre utilise plus loin lors de l'appel ... newvar_noeud(). */
		pNewTabSymb = *pTabSymb;
		pType2 = All_Type();
		pType2->type = pType->type;
		pType2->l = pType->l;
		pType2->d1 = pType->d1;
		pType2->d2 = pType->d2;
		pType2->pStruct = /*GenericNULL(TabStruct);*/pType->pStruct;
		pType2->pasptr = pasptr;
		pType2->adrimpl = adrimpl_avant;

		if (!newvar(&pNewTabSymb,niv,ext,nom,FALSE,TRUE,FALSE,pType2,optimise_tables))
			erreur(USUAL,ersymb2); /* deja declare ! */
		else {
			/* pTabSymb passe en parametre est nul (cas d'un 1er argument
				d'une procedure de type structure) */
			if (*pTabSymb == GenericNULL(TabSymb))
				*pTabSymb = pNewTabSymb;

			/* mise a jour adr descripteur dans tvar
				Dans le cas des variables externes
				pas d'incrementation */
			if (! ext) {
				/* Dans le cas d'une optimisation, pas d'increment */
				if (!optimise_tables || bArgs){
					if (niv){
						adsdcl_glb += ld; //999999
						nb_dcl_global++;
					}
					else adsdcl += ld;
				}
			}
			else
				adsdclextcr +=ld;

			(*pNbrDcl)++;

			/* l'adresse d'implantation est modifiee pour redefinir la
				zone occupee par la structure */
			adrimpl_apres = adrimpl;

			/* Ajouter dans les symboles les donnees membres de la
				structure, si la fonction n'est pas utilisee pour le
				traitement des arguments ... une procedure */
	  		if (!bArgs) {
				BOOL		svfldptr;

				/* Si la structure est pointee, adrimpl repart de 0
					Si pasptr vaut FALSE, l'instance de la structure est
					creee dynamiquement, il faut effectuer	dans la table
					de descripteurs une redefinition de zone pointee */
				svfldptr = fldptr;
				if (!pasptr)
					fldptr = TRUE;

				adrimpl = pasptr ? adrimpl_avant : 0;
				if (!newvar_noeud(&pNewTabSymb->next, pTabStruct->Symb, niv, ext,
									  bArgs, pNbrDcl))
					erreur(USUAL,ersymb2);

				/* on place le lien montant */
				if (pNewTabSymb->next) set_prev(pNewTabSymb->next, pNewTabSymb);
				fldptr = svfldptr;
				adrimpl = adrimpl_apres;
			}
		}
	}
	return (TRUE);
}

BINAIRE newdcl(niv,ext,bStruct,pasptr)

/**********************************************************************
 *    Declaration d'une ou plusieurs variables separees par des ','
 *		niv			(IN)	TRUE pour une variable globale
 *		ext			(IN)	TRUE pour une variable externe
 *		bStruct		(IN)	Donnee membre d'une structure en mode apprentissage
 *		pasptr		(IN)	TRUE si variable non pointee
 *
 *						(RET)	Nombre de variables declarees
 *
 *		Modifications :
 *			Structures a partir de la 2.2a, parametre bStruct
 **********************************************************************/
BOOL niv;
BOOL ext;
BOOL bStruct;
BOOL pasptr;

{                                       /* newdcl */
	register BYTE t;
	BINAIRE l,d1,d2,ld;
	BINAIRE nb_dcl = 0;
	BOOL    flg;
	BINAIRE tp=0; /* type de pointeur de Proc,segment,code,user */
	Type		*type;
	long int	adrimpl_avant;
	char nom[LGIDENT];

	/* toutes les declarations en FIELD=E sont ignorees en LOCAL */
	if ( ! niv ) {
		if ( ! declext )
			flg_FEL = FALSE;
		if ( flg_FEL ) {
			sfdln();
			return ( 0 );
		}
	}

	/* Pas de pointeur en Field=E ou Field=no */
	if ( (declext != 0) && (! pasptr) ) {
		erreur(USUAL,ersymb1); sfdln();return(0);
	}

	do {
	   lexical();
	   if ( (usc.code == PROC) || (usc.code == USER) || (usc.code == SEGMENT ) || (usc.code == CODE ) || (usc.code == IDENT) ) {

		if ( (usc.code == PROC) || (usc.code == USER) || (usc.code == SEGMENT) || (usc.code == CODE) ) {
			tp=usc.code;
			lexical();
			if (usc.code == IDENT) {
				Xstrcpy(nom,usc.v.pval);
				t=TSTR;
				l=5;
				d1=0; d2=0;
				lexical();
				if ( (tp == PROC) || (tp == SEGMENT) || (tp == USER) || (tp == CODE) ) {
					if (usc.code == PAG) {  /* dimensions */
						d1 = getdim();
						if (d1 == 0) goto errdecl;
						if (usc.code == VIG) {
							d2 = getdim();
							if (d2 == 0) goto errdecl;
						}
						if (usc.code != PAD) goto errdecl;
						lexical();
					}
				}
			} else {
				goto errdecl;
			}

		} else { /* ! PROC/USER/SEGMENT/CODE */
			if (usc.code == IDENT) {

				Xstrcpy(nom,usc.v.pval);
				t = getype(TRUE);
				if (t == TLIKE) {
BYTE *adesc;
BINAIRE advar;
					if (usc.code != IDENT)
						goto errdecl;

			/* Recuperation de l'adresse du descripteur de la variable */

					adesc = findvar(usc.v.pval,GenericNULL(BYTE),&advar,GenericNULL(TabSymb *),TRUE);

				       if ( adesc == GenericNULL(BYTE) ) {
						goto errdecl;
					}
					t = typdesc(adesc) & 0x03; /* 02/09/93 */
					if ((IS_TBCD(t)) || (IS_TSTR(t))) {
/* #SP: 04/02/00 (begin) */
						/*if ( *(adesc+1) == 0xB0) {	Commented by #SP */
						if ( *(adesc+1) == 0xB0 || *(adesc+1) == 0xA0) {
/* #SP: 04/02/00 (end) */
							l = bytetobin(adesc+6);
						} else {
							l = bytetobin(adesc+4);
						}
						ld=2;
					} else {
						ld=0;
					}

					d1 = 0; d2 = 0;

					if ( *adesc & PRIMARY_INDEX )
						d1 = bytetobin(adesc+4+ld);

					if ( *adesc & SECOND_INDEX )
						d2 = bytetobin(adesc+6+ld);

					lexical();

				} else { /* ! TLIKE */
					l = 0;		/* ajoute pour la version 2.2a */
					if ((t == TBCD) || (t == TSTR)) {
						l = getlong(t);
						if (l == 0) goto errdecl;
					}
					d1 = d2 = 0;
					if (usc.code == PAG) {  /* dimensions */
						d1 = getdim();
						if (d1 == 0) goto errdecl;
						if (usc.code == VIG) {
							d2 = getdim();
							if (d2 == 0) goto errdecl;
						}
						if (usc.code != PAD) goto errdecl;
						lexical();
					}
				} /* Fin TLIKE */
			} /* Fin traitement IDENT */
		} /* Fin traitement PROC/USER/PROCUSER */
#ifdef DEBUG
	printf("\nDCL/PTR:%s",nom);
#endif /* DEBUG */

		type = All_Type();
		if (type == GenericNULL(Type))
			erreur(FATALE,errmem);
		else {
			//if (!pasptr) l=5;
			type->type = t;
			type->l = l;
			type->d1 = d1;
			type->d2 = d2;
			type->pasptr = pasptr;
			type->pStruct = GenericNULL(TabStruct);
		}

		
		/* A partir de la 2.2a, newdcl() peut etre appele pour definir
			une structure */
		if (bStruct) {
			TabSymb		*pTabSymb;

			if (!newvar(&pTabSymb, niv, FALSE, nom, FALSE, TRUE, TRUE, type, optimise_tables))
				erreur(USUAL, ersymb2);

		}

		else {

			/* En version 2.2a, le descripteur n'est plus construit au
				moment de la declaration */
			adrimpl_avant = adrimpl;
			ld = mkdcldesc(niv,ext,pasptr,t,l,d1,d2,declext,fldptr,lgptrfld,adrptr); /* construire le descripteur */
			flg = FALSE;
			if ( ext && (modextcr == 0xFFFF) ) {
				BYTE *advar;
				BINAIRE i;
				advar = findvar(nom,GenericNULL(BYTE),&i,GenericNULL(TabSymb *),TRUE); /* 20/06/94 */
				if ( advar != GenericNULL(BYTE) )
					erreur(USUAL,ersymb2); /* deja declare ! */
			}
			type->adrimpl = adrimpl_avant;
			/* Pas d'optimisation des dcl Proc : cas des overlays */
			if (!newvar(ext ? &deb_extsymb : niv ? &deb_glbsymb : &deb_lclsymb, niv, ext,nom,flg,FALSE,FALSE,type,(tp == PROC)? FALSE : optimise_tables))
				erreur(USUAL,ersymb2); /* deja declare ! */
			else {
				/* mise a jour adr descripteur dans tvar */
				/* Dans le cas des variables externes */
				/* pas d'incrementation */
				if (! ext) {
					/* Dans le cas d'une optimisation, pas d'increment */
					if ((!optimise_tables)||(tp == PROC)){ /* On n'optimise pas les dcl PROC */
						if (niv) {									/* cas des overlays*/
							adsdcl_glb += ld; 
							nb_dcl_global++;
						}
						else 
						{
							adsdcl += ld;
 						    /* #OK: 21/07/00 (begin) */
							if (adsdcl >= 0x4000)
                               erreur(FATALE,ersymb12);
							/* #OK: 21/07/00 (end) */

						}
					}
				}
				else {
					adsdclextcr +=ld;
				}

				if ( tp != 0 ) {
					PSUCInfo psuc;

						if (! ext) {
							if ( niv )
								psuc.adr = (adsdcl_glb - ld);
							else
								psuc.adr = ((adsdcl - ld) | ISLOCAL);
							} 
						else	{
							psuc.adr = (IS_EXTERN | (adsdclextcr -ld));
							}

						switch (tp) {
							case PROC:
								psuc.type = PSUC_PROC;
								break;
							case SEGMENT:
								psuc.type = PSUC_SEGMENT;
								break;
							case USER:
								psuc.type = PSUC_USER;
								break;
							case CODE:
								psuc.type = PSUC_CODE;
						}
						MakePSUCTable(&psuc);
				}
				nb_dcl++;
			}
		}

	   }    /* Fin Traitement PROC/USER/IDENT */

	   else if (usc.code == FILLER) {
		lexical();
		if (usc.code != EGAL)   goto errdecl;
		lexical();
		if (!recbincst(&l))     goto errdecl;
		if ( ! ext ) {
			adrimpl += bintolong(l);
			if (declext == 0) {	/* variable en memoire */
				if (adrimpl >= MXSEG) {
					erreur(USUAL,ersymb3); adrimpl = 0L;
				}
				if ( (fldptr == FALSE) && (size_dcl < (BINAIRE) adrimpl) ) {
					size_dcl = (BINAIRE) adrimpl;
					erreur(WARNING,ersymb5);
				}
			}
			else if (declext == MEMEXT) { /* var. en memoire etendue */
				if (adrimpl >= MXEXT) {
					erreur(USUAL,ersymb3); adrimpl = 0L;
				}
				if (size_xtm < adrimpl) {
					size_xtm = adrimpl;
					erreur(WARNING,ersymb5);
				}
			}
		}
		lexical();

	   }
	  else {                        /* erreur de declaration */
errdecl:
		erreur(USUAL,ersymb1); sfdln();
	  }
	  if ((usc.code != FDLN) && (usc.code != VIG)) {
		erreur(USUAL,errfdln); sfdln();
	  }
	}
	while (usc.code == VIG);
	return (nb_dcl);
}                                       /* newdcl */


BINAIRE newcst()

/*      declaration d'une nouvelle constante
 */
{                                       /* newcst */
	register BYTE t;
	BOOL signe=FALSE;
	BINAIRE ld;
	char nom[LGIDENT];
	BINAIRE nb_cst = 0;

	if (/*(adrimpl < bintolong(size_dcl)) ||*/ (declext != 0)) {
		/* pas de constante pendant un FIELD */
		erreur(USUAL,ersymb1); sfdln(); return (0);
	}
	do {
	  lexical();
	  if (usc.code == IDENT) {
		Xstrcpy(nom,usc.v.pval);
		t = getype(TRUE);
		if (usc.code != EGAL)                     goto errcst;
		/* const. BCD : prevenir le lexical */
		if (t == TBCD) cstbcd_verrue = TRUE;
		lexical();
		if (t != TSTR) {  /* pour les numeriques : signe eventuel */
			if (usc.code == PLUS) lexical();
			else if (usc.code == MOINS) {
				lexical(); signe=TRUE;
			}
		}
		cstbcd_verrue = FALSE;
		switch (t) {
		   case TBIN1:
		   case TBIN2:
			if (usc.code != CBIN)             goto errcst;
			if ((t == TBIN1) && (usc.v.val > 255)) goto errcst;
			if (signe) usc.v.val = -usc.v.val;
			if(!newconst(TRUE,nom,usc.v.val)) goto errcst;
			nb_cst++;
			break;
		   case TBCD:
			if (usc.code != CBCD)             goto errcst;
			if (signe) {
				*(usc.v.pbcd + 1) &= 0x0F;
				*(usc.v.pbcd + 1) |= BCD_MOINS;
			}
			ld = mkcstbcd(2,&adscst,usc.v.pbcd);
			goto crecst;
		   case TSTR:
			if (usc.code != CSTR)             goto errcst;
			ld = mkcststr(2,&adscst,usc.v.pval);
crecst:
			/* Traitement constante aliassees */
			if (ld == 0) {
				if (!newconst(FALSE,nom,glob_desc))
					erreur(USUAL,ersymb2);
				else
					nb_cst++;
				break;
			}
			if (!newconst(FALSE,nom,adscst))
				erreur(USUAL,ersymb2);
			else { /* m.a.j. adresse descripteur dans tconst */
				adscst += ld; nb_cst++;
			}
		}
		lexical();
	  }
	  else {                        /* erreur de declaration */
errcst:
		erreur(USUAL,ersymb1); sfdln();
	  }
	  if ((usc.code != FDLN) && (usc.code != VIG)) {
		erreur(USUAL,errfdln); sfdln();
	  }
	}
	while (usc.code == VIG);
	return (nb_cst);
}                                       /* newcst */

/* #SP: 11/10/99 (begin)*/
#ifdef __ATR22__

BINAIRE new_local_cst()
{                                       /* new_local_cst */
	register BYTE t;
	BOOL signe=FALSE;
	BINAIRE ld;
	char nom[LGIDENT];
	BINAIRE nb_cst = 0;

	do {
	  lexical();
	  if (usc.code == IDENT) {
		Xstrcpy(nom,usc.v.pval);
		t = getype(TRUE);
		if (usc.code != EGAL)                     goto errcst;
		/* const. BCD : prevenir le lexical */
		if (t == TBCD) cstbcd_verrue = TRUE;
		lexical();
		if (t != TSTR) {  /* pour les numeriques : signe eventuel */
			if (usc.code == PLUS) lexical();
			else if (usc.code == MOINS) {
				lexical(); signe=TRUE;
			}
		}
		cstbcd_verrue = FALSE;
		switch (t) {
		   case TBIN1:
		   case TBIN2:
			if (usc.code != CBIN)             goto errcst;
			if ((t == TBIN1) && (usc.v.val > 255)) goto errcst;
			if (signe) usc.v.val = -usc.v.val;
			if(!newconst_local(TRUE,nom,usc.v.val)) goto errcst;
			nb_cst++;
			break;
		   case TBCD:
			if (usc.code != CBCD)             goto errcst;
			if (signe) {
				*(usc.v.pbcd + 1) &= 0x0F;
				*(usc.v.pbcd + 1) |= BCD_MOINS;
			}
			if (!flglcst)
				ld = mkcstbcd(2,&adscst,usc.v.pbcd); //###SAP  10/4/99
			else ld = mkcstbcd(4,&ladscst,usc.v.pbcd); //###SAP  10/4/99
			goto crecst;
		   case TSTR:
			if (usc.code != CSTR)             goto errcst;
			if (!flglcst)
				ld = mkcststr(2,&adscst,usc.v.pval);
			else ld = mkcststr(4,&ladscst,usc.v.pval); //###SAP  10/4/99
crecst:
			/* Traitement constante aliassees */
			if (ld == 0) {
				if (!newconst_local(FALSE,nom,glob_desc))
					erreur(USUAL,ersymb2);
				else
					nb_cst++;
				break;
			}

			//if (!newconst_local(FALSE,nom,adscst)) //###SAP  10/4/99
			if (!newconst_local(FALSE,nom,flglcst ? ladscst:adscst)) //###SAP  10/4/99
				erreur(USUAL,ersymb2);
			else { /* m.a.j. adresse descripteur dans tconst */
				if (!flglcst) adscst += ld;
				else ladscst += ld; nb_cst++; //###SAP  10/4/99
			}
		}
		lexical();
	  }
	  else {                        /* erreur de declaration */
errcst:
		erreur(USUAL,ersymb1); sfdln();
	  }
	  if ((usc.code != FDLN) && (usc.code != VIG)) {
		erreur(USUAL,errfdln); sfdln();
	  }
	}
	while (usc.code == VIG);
	return (nb_cst);
}                                       /* new_local_cst */

#endif
/* #SP: 11/10/99 (end)*/

BINAIRE newstr(p)

/*      nouvelle constante chaine, en direct dans le source
 */
char *p;
{                                       /* newstr */
	BINAIRE adr,ld;

	if ( flglcst == TRUE ) {
		ld = mkcststr(4,&ladscst,p);
		/* Traitement constantes aliassees */
		if (ld == 0)
			return(glob_desc);
		adr = ladscst; ladscst += ld;
	} else {
		ld = mkcststr(2,&adscst,p);
		/* Traitement constantes aliassees */
		if (ld == 0)
			return(glob_desc);
		adr = adscst; adscst += ld;
	}
	return (adr);
}                                       /* newstr */


BINAIRE newbcd(p)

/*      nouvelle constante BCD, en direct dans le source
 */
BYTE *p;
{                                       /* newbcd */
	BINAIRE adr,ld;

	if ( flglcst == TRUE ) {
		ld = mkcstbcd(4,&ladscst,p);
		/* Traitement constantes aliassees */
		if (ld == 0)
			return(glob_desc);
		adr = ladscst; ladscst += ld;
	} else {
		ld = mkcstbcd(2,&adscst,p);
		/* Traitement constantes aliassees */
		if (ld == 0)
			return(glob_desc);
		adr = adscst; adscst += ld;
	}
	return (adr);
}                                       /* newbcd */


void newfld(glb,mod)

/*      changement de l'emplacement des variables "memoire" ou "fichier"
 *      'glb' est vrai pour le niveau global et faux sinon;
 *      'mod' est vrai pour un module et faux pour un programme.
 */
BOOL glb;
BOOL mod;
{                                       /* newfld */
	BYTE *advar;
	BINAIRE i;
	long int depl;

	DCLInfo dcl;

	lexical();
	if (usc.code == EGAL) {
	   lexical();

	/* Teste le type de declaration de variable.
	 * Jusqu'a la version 1.3, FIELD=<constante> est interdit.
	 * A partir de la 1.4, c'est autorise sauf pour M et E
	 * qui designe la memoire.
	 * De plus, FIELD=<no log> est accepte dans les procedures
	 */
	if ((usc.code == IDENT) && (Xstrlen(usc.v.pval) == 1) &&
	    ((*usc.v.pval == 'M') || (*usc.v.pval == 'E'))) {
		fldptr=FALSE;
		if (*usc.v.pval == 'M') {
			/* Retour a la normale pour les FIELD=E */
			if (!glb)
				flg_FEL = FALSE;

			declext = 0;    /* implanter en memoire */
			adrimpl = (long) size_dcl;
		}
		else if (*usc.v.pval == 'E') {
			/* En version 2.1b : on permet la declaration des   */
			/* FIELD=E en local pour remedier a un BUG de APLUS */
			/* Affichage d'un WARNING et on ignore les 	    */
			/* declarations pendant le FIELD=E		    */
			if (!glb) {
				flg_FEL = TRUE;
				declext = MEMEXT;
				erreur(WARNING,ersymb1);
				sfdln();
				return;
			}
			declext = MEMEXT; /* implanter en memoire etendue */
			adrimpl = size_xtm;
		}
		else goto errfld;
	   }
	else {                  /* FIELD=numlog ? */
		if (!recbincst(&i))             goto errfld;
		if ((i == 0) || negbin(i) || (i >= MXNLOG))     goto errfld;
		fldptr=FALSE;
		declext = (BYTE) i;
		adrimpl = 0L;
	   }
	   lexical();
	   if (usc.code == FDLN) 
		   local_niv_field--; /*SG211197*/
	   else {
		if (usc.code != VIG)            goto errfld;    /* illegal */
		lexical();
		if (usc.code != IDENT)          goto errfld;    /* illegal */
		/* recouvrement d'une variable  = une utilisation */
		etat_tr = S_PARS;
		local_niv_field++;
#ifdef DEBUG
	printf("\nFIELD=M,%s",usc.v.pval);
#endif /* DEBUG */
		advar = findvar(usc.v.pval,GenericNULL(BYTE),&i,GenericNULL(TabSymb *),TRUE);
		etat_tr = S_DECL;
		if (advar == GenericNULL(BYTE)) goto errfld;    /* illegal */
		if (!glb)
         if ((i & ISLOCAL) == 0) {
			/* what a shame ! we could redefine a global pointer */
			goto errfld;
			}

		/* Est ce la redefinition d'un pointeur ? */
		fldptr = ( ( *(advar+1) & typ_special ) ? TRUE : FALSE );
		if ( fldptr == TRUE) {

			dcl.adrdesc = i;
			GetDCLTable(&dcl);

			/* Si c'est une redef de Ptr en dcl */
			if ( dcl.ptr && (dcl.tptr == 2) ) {
				adrptr = dcl.adredefptr;
			} else {
				adrptr = i;
			}
			dcl.adrdesc = adrptr;
			GetDCLTable(&dcl);
			if ( dcl.tptr == 0x02 ) {
				dcl.adrdesc = dcl.adredefptr;
				GetDCLTable(&dcl);
			}
			lgptrfld = dcl.ptlongueur;

			if ( (*(advar+1) & msk_ptr) != declext) goto errfld;    /* illegal */
		} else {
			if (*(advar+1) != declext)      goto errfld;    /* illegal */
		}
#ifdef DEBUG
		dcl.adrdesc = adrptr;
		GetDCLTable(&dcl);           
#endif /* DEBUG */
		/* Si ref ptr : offset par rapport a son debut */
		if ( fldptr != TRUE ) {
			i = bytetobin(advar+2);
			adrimpl = bintolong(i);
		} else {
			/* Si c'est une redef de Ptr */
			if ( (*(advar+1) & SECOND_INDEX) && !(*(advar+1) & 0x10) ) {
				/* L'implantation est ... l'offset */
				i = bytetobin(advar+4);
				adrimpl = bintolong(i);
			} else {        
				adrimpl = 0;    
			}
		}               
		if (declext != 0) {
			i = bytetobin(advar+4);
			depl = (bintolong(i) << 16);
			adrimpl += depl;
		}
		if ((*advar & PRIMARY_INDEX) != 0) {     /* recuperer les dimensions */
			if (!rec_depl(advar,&depl)) goto errfld;
			adrimpl += depl;
		}
		tfdln();
	   }
	   
	}
	else { //usc.code != EGAL

errfld:         /* erreur de declaration */
		erreur(USUAL,ersymb1); sfdln();
	}
}                                       /* newfld */

BINAIRE complete_dcl(pTabSymb)

/**********************************************************************
 *		Completer la liste des symboles locals deb_lclsymb avec les donnees
 *		membres des structures.
 *		Cette fonction est utilisee apres newargs() et deb_lclsymb ne
 *		contient alors que des parametres
 *
 *		pTabSymb	(IN)	Symbole dabs deb_lclsymb
 *
 *				(RET)	Nombre de variables declarees
 *
 **********************************************************************/

TabSymb		*pTabSymb;
{
	Type			*pType;
	TabStruct	*pStruct;
	long int		sv_adrimpl;
	BOOL			bRet;
	BINAIRE		NbrDcl = 0;
	BOOL		svfldptr;

	if (pTabSymb != GenericNULL(TabSymb)) {
		/* le noeud contient de ramifications */
		if (pTabSymb->g)	NbrDcl += complete_dcl(pTabSymb->g);
		if (pTabSymb->d)	NbrDcl += complete_dcl(pTabSymb->d);
		if (pTabSymb->type != GenericNULL(Type)) {
			pType = pTabSymb->type;

			/* Une structure passee en parametre */
			if (pType->pStruct != GenericNULL(TabStruct)) {
				pStruct = pType->pStruct;
				/* On repositionne l'adresse d'implantation */
				sv_adrimpl = adrimpl;
				adrimpl = pType->adrimpl;
				/* la structure est passee par adresse */
				if (!pType->pasptr) {
					svfldptr = fldptr;
					fldptr = TRUE;
					lgptrfld = pType->l;
					adrimpl = 0; //SG211197
					adrptr = pTabSymb->ads | 0x8000;
				}

				bRet = newvar_noeud(&pTabSymb->next, pStruct->Symb, FALSE,
										 FALSE, FALSE, &NbrDcl);

				if (!pType->pasptr)
					fldptr = svfldptr;

				/* on place le lien montant */
				set_prev(pTabSymb->next, pTabSymb);
				adrimpl = sv_adrimpl;
				if (!bRet)
					return(NbrDcl);
			}
		pTabSymb = pTabSymb->next;
		}
	}
	return (NbrDcl);
}

BINAIRE newargs(eif,targs,nmod)

/**********************************************************************
 *		Declaration des arguments d'une procedure
 *		Dans le cas ou une structure est passee en parametre, il manque
 *		apres le traitement effectue par newargs
 *		eif	(IN)	Type de la procedure
 *						0 ----> procedure externe
 *						1 ----> procedure interne
 *						2 ----> procedure forward
 *		targs	(OUT)	Type des differents arguments
 *		nmod	(OUT)	Numero de module
 *
 *				(RET)	Nombre d'arguments
 *
 *		en version 2.2a :
 *			Un parametre peut etre du type structure, idem pour la valeur
 *			de retour
 **********************************************************************/

BYTE eif;
BYTE *targs;
BINAIRE *nmod;
{                                       /* newargs */

	BOOL pasptr;    /* ver15 : argument non pointeur par defaut */

	register BYTE	t;
	BINAIRE 			l,d1,d2,ld;
	BINAIRE 			nb_args = 0;    /* en ver15 : les 5 bits de poids forts sont pour le type de retour !!! */
	BYTE 				*pds;
	char 				nom[LGIDENT];
	BOOL 				bStruct;
	TabStruct		*pTabStruct;
	BINAIRE			rt=0;   /* type de retour */
	Type				*type;
	/* #OK: 09/12/99 (begin) */
#ifdef __ATR22__
	int i;
#endif
	/* #OK: 09/12/99 (end) */

	*nmod=0;        /* initialisation du numero de module */

	fldptr = FALSE;	/* 04/06/93 */
	pTabStruct = GenericNULL(TabStruct); /*SG 21/10/97*/ 

	lexical();
	if (usc.code != PAG) {  /* il n'y a pas d'argument */
		if ( usc.code == DPT ) goto trtretour;
		if (usc.code != FDLN) goto errargs;
		if ( eif == 0 ) {	/* 05/05/94 */
			if ( inmod(nmod) == TRUE ) {
				if ( usc.code != FDLN )
					erreur(USUAL,ersynt4);
			}
		} else
			*nmod = NIL;
		return (0);
	}
	do {
		pasptr = TRUE;       /* argument non ptr par defaut */
	   	lexical();
	   	/* Passage par pointeur ? */
	   	if (usc.code == PTR) {
			pasptr = FALSE;
			lexical();
	   	}
		if ( (usc.code == PROC) || (usc.code == SEGMENT) || 
		     (usc.code == USER) || (usc.code == CODE) ||
		     (usc.code == IDENT) ) {
			if ( usc.code != IDENT ) {
				lexical();
				if ( usc.code != IDENT ) goto errargs;
				Xstrcpy(nom,usc.v.pval);
				t=TSTR;
				l=5;
				d1=0; d2=0;
				lexical();
			} else {
				BINAIRE		NbrDcl = 0;

				bStruct = FALSE;

				Xstrcpy(nom,usc.v.pval);
				/* A partir de la 2.2a, le parametre peut etre
					un element de type structure */
				if ((pTabStruct = findstruct(usc.v.pval)) != GenericNULL(TabStruct)) {
					lexical();
	   			/* Passage par pointeur ? */
	   			if (usc.code == PTR) {
						pasptr = FALSE;
						lexical();
	   			}
					bStruct = TRUE;
					/* On considere la structure comme une chaine de caractere */
					t = TSTR;
					l = pTabStruct->l;
					Xstrcpy(nom,usc.v.pval);
					lexical();
				}
				else {
					t = getype(TRUE);
					if ((t == TBCD) || (t == TSTR)) {
						l = getlong(t);
						if (l == 0) goto errargs;
					}
				}
				d1 = d2 = 0;
				if (usc.code == PAG) {  /* dimension */
					goto errargs;
				}
			}
			/* #OK: 22/02/00 (begin) */
			/* if ( eif != 2) { /* Procedure Interne / Externe Commented by #OK */
			if ( eif != 2 && eif != 0) { /* Procedure Interne */
			/* #OK: 22/02/00 (end) */
				BOOL		bRet;
				TabSymb	*pTabSymb;
				long int	sv_adrimpl = adrimpl;

				ld = mkdcldesc(FALSE,FALSE,pasptr,t,l,d1,d2,declext,fldptr,lgptrfld,adrptr); /* construire descripteur */

				type = All_Type();
				if (type == GenericNULL(Type)) {
					erreur(FATALE,errmem); sfdln();
					return (nb_args);
				}
				else {
					type->type = t;
					type->l = l;
					type->d1 = d1;
					type->d2 = d2;
					type->pStruct = pTabStruct;
					type->pasptr = pasptr;
					type->adrimpl = sv_adrimpl;
				}

				pTabSymb = deb_lclsymb;

				/* #OK: 09/12/99 (begin) */
#ifdef __ATR22__
				bProcParam = TRUE;
#endif
				/* #OK: 09/12/99 (end) */

				/* Nouvelle variable, modification de pTabSymb demandee */
				bRet = newvar(&pTabSymb,FALSE, FALSE,nom,FALSE,TRUE,FALSE,type,optimise_tables);

				/* #OK: 09/12/99 (begin) */
#ifdef __ATR22__
				bProcParam = FALSE;
#endif
				/* #OK: 09/12/99 (end) */

				/* #SP: 09/07/99 (begin) */
				if (!bRet){
					erreur(USUAL,ersymb2);
					goto errargs;
				}
				/* #SP: 09/07/99 (end) */

				/* Les arguements d'une procedure sont forcement ajoutes
					aux descripteurs */
				pTabSymb->opt &= (BYTE) ~OPT_USE; //utilisee
				pTabSymb->opt &= (BYTE) ~OPT_NOT_DECLARE; //declaree

				/* deb_lclsymb est nul dans le cas d'un 1er argument */
				if (deb_lclsymb == GenericNULL(TabSymb))
					deb_lclsymb = pTabSymb;

				/* #OK: 09/12/99 (begin) */
#ifdef __ATR22__
				/* new_deb_lclsymb - list for procedure parametrs */
				if (new_deb_lclsymb == GenericNULL(TabSymb))
					{                
					/* Add list element for parametrs in the procedure */
					new_deb_lclsymb = ALLOC_TABSYMB_ITM;
					for (i=0; i < LGIDENT; i++)
						new_deb_lclsymb->pid[i] = pTabSymb->pid[i];
					new_deb_lclsymb->mod = pTabSymb->mod;
					new_deb_lclsymb->lref = pTabSymb->lref;
					new_deb_lclsymb->adsloc = pTabSymb->adsloc;
					new_deb_lclsymb->opt = pTabSymb->opt;
					new_deb_lclsymb->ads = pTabSymb->ads;
					new_deb_lclsymb->g = GenericNULL(TabSymb); /* left reference already = 0 */
					new_deb_lclsymb->d = pTabSymb->d;
					new_deb_lclsymb->prev = pTabSymb->prev;
					new_deb_lclsymb->next = pTabSymb->next;     
					new_deb_lclsymb->type = pTabSymb->type;           
					new_deb_lclsymb->declext = pTabSymb->declext;
					new_deb_lclsymb->fldptr = pTabSymb->fldptr;
					new_deb_lclsymb->lgptrfld = pTabSymb->lgptrfld;
					new_deb_lclsymb->adrptr = pTabSymb->adrptr;

					old_deb_lclsymb = new_deb_lclsymb; /* Save pointer on the first element */
					}
#endif
					/* #OK: (end) 09/12/99 */

				if (!bRet)
					erreur(USUAL,ersymb2); /* deja declare ! */

				else {  /* mise a jour adr descripteur dans tvar */
					/* et mise a jour chaine des arguments */
					if ((nb_args + 1) == MXARGS) goto errargs;
						adsdcl += ld;
					if (d1 != 0) t |= PRIMARY_INDEX;
					if (d2 != 0) t |= SECOND_INDEX;
					if ( ! eif )
						etat_tr = S_PARS;
					pds = findvar(nom,GenericNULL(BYTE),&d1,GenericNULL(TabSymb *),TRUE);
					if ( ! eif )
						etat_tr = S_DECL;
					*pds |= 0x08;
					*targs++ = t;
					nb_args++;
				}
			} else { /* Procedure Forward */
				 /* et mise a jour chaine des arguments */
				if ((nb_args + 1) == MXARGS) goto errargs;
				if (d1 != 0) t |= PRIMARY_INDEX;
				if (d2 != 0) t |= SECOND_INDEX;
				*targs++ = t;
				nb_args++;
			}
		} 
	  else if (usc.code != PAD) {           /* erreur de declaration */
errargs:
		erreur(USUAL,ersymb1); sfdln();
		return (nb_args);
	  }
	  if ((usc.code != PAD) && (usc.code != VIG)) {
		erreur(USUAL,errfdln); sfdln();
	  }
	}
	while (usc.code == VIG);

	lexical();
	/* Traitement Type de retour si fonction */
	if ( usc.code == DPT ) {
trtretour:
		lexical();
		if ( (usc.code == PROC) || (usc.code == SEGMENT) ||
		     (usc.code == USER) || (usc.code == CODE) ) {
			t=TSTR;
			l=5;
		} else {
			TabStruct	*pTabStruct;

			/* cas d'une structure */
			if ((pTabStruct = findstruct(usc.v.pval)) != GenericNULL(TabStruct)) {
				t = TSTR;
				l = pTabStruct->l;
			}
			else {
				t = getype(FALSE);
				if (( (t & typ_in_desc) == TBCD) || ( (t & typ_in_desc) == TSTR)) {
					l = getlong((BYTE)(t & typ_in_desc));
					if (l == 0) goto errargs;
				}
			}
		}
		rt = ( ( t << DEPTYPNBA ) | ISFCT );
	}
	
	if ( eif == 0 ) {
		if ( inmod(nmod) == TRUE ) {
			if ( usc.code != FDLN )
				erreur(USUAL,ersynt4);
		}
	} else
		*nmod = NIL;

	if ((eif != 1) && (usc.code != FDLN))
		tfdln();
	
	/* #OK: 09/12/99 (begin) */   
#ifdef __ATR22__
	bProcParam = FALSE;
#endif
	/* #OK: 09/12/99 (end) */

	return ( ((nb_args) & MNBARG) | rt );
}                                       /* newargs */

/**********************************************************************
 *		Nouvelle procedure
 *		nom			(IN)	Nom de la procedure
 *		ext			(IN)	La procedure est externe
 *		fwd			(IN)	Fonction appelee pour protyper la procedure
 *								("FORWARD PROC Proc1()")
 *		acode			(IN)	Bloc ou se trouve le t-code de la procedure
 *		lcode			(IN)	Longueur du t-code
 *		avar			(IN)	Bloc ou se trouve la description des variables
 *		lvar			(IN)	Longueyr de la table de description des variables
 *		narg			(IN)	Nbr d'arguments
 *		parg			

 *		optres		(IN)	option : chargement en differe de la procedure
 *								par exemple ("PROC Proc1(), D")
 *		nmod			(IN)	Numero du module
 *		ps				(OUT)	Reference ... une structure TabProc creee pour la
 *								procedure
 *		nb_fwd		(OUT)
 *		build_desc	(IN)	A partir de 2.2a : Construire le descripteur dans
 *								la fonction
 *		ptfwd			(OUT)	prototype de la fonction dej... rencontre
 *
 *						(RET) TRUE si au moins une variable declaree
 **********************************************************************/
BYTE *newproc(nom,ext,fwd,acode,lcode,avar,lvar,narg,parg,optres,nmod,ps,nb_fwd,build_desc,ptfwd
#ifdef	VERSION_XX
		,ivarb,vitem
#endif
		)

/*      Allocation et insertion dans la table des procedures
 */
char *nom;
BOOL ext;
BOOL fwd;
BINAIRE acode,lcode,avar,lvar,narg;
BYTE *parg;
BINAIRE optres,nmod;
TabProc * *ps;
BINAIRE *nb_fwd;
BOOL build_desc;
BOOL	*ptfwd;
#ifdef	VERSION_XX
BINAIRE ivarb;
BINAIRE vitem;
#endif

{                                       /* newproc */
	register int i;
	BINAIRE j;
	register TabProc *s;
	TabProc *f = GenericNULL(TabProc);
	BYTE *t,*ptlcode;

	/* Dans le cas ou la procedure a deja ete declare en FORWARD
	 * on la trouve dans la table des procedures
	 * m a j de la table
	 */
	 BOOL tfwd = FALSE;     /* forward pas dans la table */

	/* Recherche d'un emplacement dans la table des procedure :
	 * celle-ci est triee sous forme d'un arbre.
	 * Le critere de tri est le nom de la procedure
	 * + numero de module pour les procedure externes.
	 */
	s = deb_tproc;
	while (s != GenericNULL(TabProc)) {
		i = Xstrcmp(nom,s->pid);

		if (i < 0)
			f = s, s = s->g;
		else if (i > 0)
			f = s, s = s->d;
		else {
			if ( s->mod < nmod )
				f = s, s = s->g;
			else if ( s->mod > nmod )
				f = s, s = s->d;
			else if ( ext )
				return (GenericNULL(BYTE));
				/* Procedure deja existante */
			else if ( s->ext == FALSE ) {
				tfwd = TRUE; /* Procedure forward */
				if (ptfwd != GenericNULL(BOOL))
						*ptfwd = TRUE;
				break;
			} else {
				return (GenericNULL(BYTE));
				/* Procedure deja existante */
			}
		}
	}

	/* Allocation d'un noeud de l'arbre pour y placer
	 * la description de la nouvelle procedure
	 */
	if ( tfwd == FALSE ) { /* Pas d'allocation si forward trouve */

		s = All_Proc();                 /* alloc nouveau symbole */
/* #AT: 13/09/99 (begin)*/
#ifdef __ATR22__
		s->pFormalParams = GenericNULL(TabSymb);
#endif
/* #AT: 13/09/99 (end)*/
		if (s == GenericNULL(TabProc))  /* mais debordement memoire */
			erreur(FATALE,errmem);

	/* Insertion du noeud dans l'arbre (qui doit demeurer trie,
	 * meme s'il n'est pas equilibre !!!)
	 */
		if (f != GenericNULL(TabProc))
			if (i < 0)
				f->g = s;
			else if ( i > 0 )
				f->d = s;
			else { 
				if ( f->mod < nmod )
					f->g = s;
				else
					f->d = s;
			}
		else
			deb_tproc = s;

	/* Mise a jour du noeud avec la description de
	 * la nouvelle procedure :
	 *      - nom de la procedure
	 *      - pointeur sur les types d'arguments
	 *      - autres indicateurs
	 */
		Xstrcpy(s->pid,nom);
		s->nba = narg;

		if ( narg & ISFCT ) {
			narg = narg & MNBARG;
		}

		if (narg != 0) {
			t = (BYTE *) Xmalloc(narg);
			if (t == GenericNULL(BYTE))
				erreur(FATALE,errmem);
			s->adta = t;
			for (j=0; j<narg; j++)
				*t++ = *parg++;
		} else
			s->adta = GenericNULL(BYTE);

		/* Elle n'a jamais ete encore utilise !!! */
		s->util = FALSE;

	} else {
		/* verification des parametres dans le cas du FORWARD */
		if ( s->nba == narg ) {
			if ( narg & ISFCT ) {
				narg = narg & MNBARG;
			}
			if (narg != 0) {
				t = s->adta;
				for (j=0; j<narg; j++)
					if ( *t++ != *parg++ ) {
						/* mauvais type */
						erreur(USUAL,ersynt18);
						break;
					}
			}
		} else {
			if ( s->nba > narg ) /* parenthese attendue */
				erreur(USUAL,ersynt21);
			else /* virgule attendue */
				erreur(USUAL,ersynt20);
		}
		(*nb_fwd) --;
	}

	s->lref = GenericNULL(ExtRef);

	if ( fwd ) {
		s->forward = TRUE;
		s->implemented = FALSE;		/* #IJM 06/11/02 */
		}
	else {
		s->forward = FALSE;
		s->implemented = TRUE;		/* #IJM 06/11/02 */
		}

	s->mod = nmod;
	
	if (ext) {      /* procedure externe */
		s->ext = TRUE;
#ifdef VERSION_XX
		s->ivarb = ivarb;
		s->vitem = vitem;
#endif
	}
	else {
#ifdef	VERSION_XX
		s->ivarb = 0;
		s->vitem = 0;
#endif
		s->ext = FALSE;
		/* A partir de 2.2a, le descripteur est construit sur demande */
		if (build_desc)
			ptlcode = mkprocdesc(s,tfwd,acode,lcode,avar,lvar,optres);
	}

	if ( tfwd == FALSE )
		s->g = s->d = GenericNULL(TabProc);

	if ( ps != GenericNULL(TabProc *) )
		*ps = s;

	return (ptlcode);
}                                       /* newproc */


void newseg(ext,fwd,nom,nseg,nmod,acode,lcode,avar,lvar,optres,blien,adsc,lgcst,adtc,lgtc)
/*      Allocation et insertion dans la table d'un descripteur de segment
 */
BOOL ext,fwd;   /* TRUE si segment externe */
char *nom;
BINAIRE nseg,nmod,acode,lcode,avar,lvar;
BINAIRE optres,blien;
BINAIRE adsc,lgcst;
BINAIRE adtc,lgtc;
{                                       /* newseg */
        register int i;
        register TabSeg *s;
        TabSeg *f = GenericNULL(TabSeg);
	BYTE *ptlcode;

        /* Recherche d'un emplacement dans la table des segments :
         * celle-ci est triee sous forme d'une liste.
         * Le critere de tri est le numero de segment croissant
         * puis le nom de la procedure.
         */

        s = deb_tseg;
        while (s != GenericNULL(TabSeg)) {
                if ( s->num < nseg) {
                        f = s; s = s->suiv;
                } else {
                        if ( s->num > nseg) {
                                break;
                        } else {
                                if ( nseg == 0xFFFF ) {
                                        i = Xstrcmp(nom,s->nom);
                                        if ( i < 0 ) {
                                                break;
                                        } else {
                                                if ( i==0 ) {
							if ( nmod < s->mod )
								break;
							else if ( nmod > s->mod ) {
								f=s; s = s->suiv;
							} else {
                                                        	erreur(USUAL,ersynt18);
	                                                        break;
							}
                                                } else {
                                                        f=s; s = s->suiv;
                                                }
                                        }
                                } else {
                                        erreur(USUAL,ersynt18);
                                        break;
                                }
                        }
                }
        }

        /* Allocation d'un noeud de l'arbre pour y placer
         * la description du nouveau segment
         */
                s = All_Tseg();                 /* alloc nouveau segment */
                if (s == GenericNULL(TabSeg))   /* mais debordement memoire */
                        erreur(FATALE,errmem);

        /* Insertion du noeud dans la liste
         */
                if (f != GenericNULL(TabSeg)) {
                        s->suiv=f->suiv;
                        f->suiv = s;
                } else {
                        s->suiv = deb_tseg;
                        deb_tseg = s;
                }

        /* Mise a jour du noeud avec la description du
         * nouveau segment :
         *      - nom du segment
         *      - autres indicateurs
         */
        Xstrcpy(s->nom,nom);
        s->lref = GenericNULL(ExtRef);
        s->num = nseg;

        s->mod = nmod;
        s->adc = acode;
        s->lgc = lcode;
        s->adv = avar;
        s->lgv = lvar;
        s->fwd = fwd;

	s->adcst = adsc;
	s->lgcst = lgcst;

	s->adtc = adtc;
	s->lgtc = lgtc;

        /* Pose options de residence / reentrance */
        s->opt = optres;

        s->blien=blien;

        if (ext) {      /* segment externe */
                s->ext = TRUE;
        } else {
                s->ext = FALSE;
                s->ads = adsseg;
		ptlcode = mksegdesc(s,FALSE,nseg,acode,lcode,avar,lvar,adsc,lgcst,optres);
        }

   /* #OK: 08/10/99 (begin) */
   if (nseg == 0) presentSegment0 = TRUE;
   /* #OK: 08/10/99 (end) */

	return;
}                                       /* newseg */

BOOL newwith()
/**********************************************************************
 *    Declaration d'une clause "with"
 *		La variable globale deb_withest organisee sequentiellement
 *		et alimentee ... chaque fois que l'on rencontre un "with"
 *		le 1er element correspond au dernier "with" rencontre
 **********************************************************************/
{
	TabWith 		*s = GenericNULL(TabWith);
	TabWith 		*f = GenericNULL(TabWith);
	BINAIRE			ads;
	TabSymb		*pTabSymb;
	BYTE 			*adesc;
	BYTE			passe;

	/* #OK: 11/07/00 (begin) */
    pTabSymb=GenericNULL(TabSymb);
	adesc=0;
	/* #OK: 11/07/00 (end) */

   lexical();
	if (usc.code == IDENT) {

		/* 1er with, on recherche le symbole partout */
		if ( deb_with == GenericNULL(TabWith)) {
			pTabSymb = GenericNULL(TabSymb);
			passe = 0;
		}

		/* with imbrique, on repart du with existant */
		else {
			pTabSymb = deb_with->Symb->next;
			passe = deb_with->passe;
		}

		/* On recherche le symbole */
		adesc = findvar(usc.v.pval,&passe,&ads, &pTabSymb,FALSE);
		if ( adesc == GenericNULL(BYTE) ) {
			erreur(USUAL,ersymb1);
			return (FALSE);
		}

		s = All_With();         /* alloc nouveau symbole */

		if (s == GenericNULL(TabWith)) {          /* mais debordement memoire */
			erreur(FATALE,errmem);
			return (FALSE);
		}

		s->suiv = deb_with;
		if (deb_with != GenericNULL(TabWith))
			deb_with->prec = s;

		deb_with = s;

		Xstrcpy(s->pid, usc.v.pval);
		s->prec = GenericNULL(TabWith);
		s->Symb = pTabSymb;
		s->passe = passe;
   	lexical();
	}
	return (TRUE);
}

BOOL endwith()

/**********************************************************************
 *    Fin de declaration d'une clause "with"
 *		On enleve le dernier le 1er element de la liste deb_with
 **********************************************************************/
{
	TabWith	*s;

	s = deb_with;
	if (s == GenericNULL(TabWith)) {
		/* #OK: 11/07/00 (begin) */
		// erreur(USUAL,errlex17); // commented by #OK
		erreur(USUAL,ersynt50);
		/* #OK: 11/07/00 (end) */
		return(FALSE);
	}
	deb_with = s->suiv;
	Free_With(s);
	return(TRUE);
}

BOOL newstruct()

/**********************************************************************
 *    Declaration d'une nouvelle structure.
 *		La variable globale deb_struct est une liste chainee de toutes
 *		les declarations des structures rencontrees pendant la traduction.
 *		Elles sont organisees sequentiellement dans l'ordre ou elles sont
 *		recontrees dans le source.
 **********************************************************************/
{
	TabStruct 		*s = GenericNULL(TabStruct);
	TabStruct 		*f = GenericNULL(TabStruct);
	register int	i;	

   lexical();
	if (usc.code == IDENT) {

		s = deb_struct;

		while (s != GenericNULL(TabStruct)) {
			i = Xstrcmp(usc.v.pval,s->pid);
			if (i)
				f = s, s = s->suiv;
			else 
            /* #OK: 11/07/00 (begin) */
			{
                erreur(USUAL,ersymb2);                 
				return (FALSE); /* symbole deja existant */
			}
			/* #OK: 11/07/00 (end) */
		}

		s = All_Struct();         /* alloc nouveau symbole */

		if (s == GenericNULL(TabStruct)) {         /* mais debordement memoire */
			erreur(FATALE,errmem);
			return (FALSE);
		}

		if (f != GenericNULL(TabStruct)) {
			f->suiv = s;
			s->prec = f;
			}
		else {
		 	deb_struct = s;
			s->prec = GenericNULL(TabStruct);
			}

		Xstrcpy(s->pid, usc.v.pval);
		s->suiv = GenericNULL(TabStruct);
		s->Symb = GenericNULL(TabSymb);
		s->l = 0;
   	lexical();
	}
    /* #OK: 11/07/00 (begin) */
	else
	{
		erreur(USUAL,ersynt4); /* declaration incorrect: name of structure absent */
		return (FALSE);
	}
    /* #OK: 11/07/00 (end) */
	return (TRUE);
}

BINAIRE get_noeud_size(pTabSymb)

/**********************************************************************
 *		Calcul de la taille d'un noeud TabSymb.
 *		pTabSymb	(IN)	Reference ... un symbole (TabSymb)
 *		
 *					(RET)	Taille du noeud complet
 **********************************************************************/
TabSymb *pTabSymb;
{
	BINAIRE	size = 0;
	BINAIRE currentSize = 0;
	BINAIRE totalSize = 0;
	BINAIRE dim1 = 0;  /* SG ajoute la gestion des tableaux 13/03/98 */
	BINAIRE dim2 = 0;
	Type		*pType;

	if (pTabSymb->g != GenericNULL(TabSymb))
		size += get_noeud_size(pTabSymb->g);
	if (pTabSymb->d != GenericNULL(TabSymb))
		size += get_noeud_size(pTabSymb->d);
	pType = pTabSymb->type;
	if (pType == GenericNULL(Type))
		return size;
	if ( pType->pStruct != GenericNULL(TabStruct)) {//Structure....
		/* pointeur sur structure */
		if (!pType->pasptr)
			size += LGSTDPTR;
		else {
			TabStruct	*pStruct;

			pStruct = (TabStruct *)pType->pStruct;
			size += get_noeud_size(pStruct->Symb);
		}
	}
	else {//Pas structure ...
		BINAIRE	Taille;
		/* on calcul la taille de l'element elemenaire */
		dim1 = pType->d1;
		dim2 = pType->d2;

		if (IS_TBCD(pType->type)) Taille = pType->l;
		if (IS_TBIN1(pType->type)) Taille = 1;
		if (IS_TBIN2(pType->type)) Taille = 2;
		if (IS_TSTR(pType->type)) Taille = pType->l;

		if (!pType->pasptr)
			Taille = LGSTDPTR;

		if (dim1) Taille*=dim1;
		if (dim2) Taille*=dim2;

		size += Taille;

	}

	return(size);
}

BINAIRE get_struct_size(pTabStruct)

/**********************************************************************
 *		Calcul de la taille d'une structure.
 *		(IN)	Reference ... une structure dans la liste globale
 *				deb_struct
 *		
 *		(RET)	Taille de la structure ou 0 si erreur
 **********************************************************************/
TabStruct *pTabStruct;
{
	BINAIRE	size=0;
	TabSymb	*pTabSymb;

	pTabSymb = pTabStruct->Symb;
	if (pTabSymb) size = get_noeud_size(pTabSymb);
	return(size);
}

TabStruct *get_last_struct(void)

/**********************************************************************
 *		Recherche du dernier element de la liste globale deb_struct.
 *		
 *		(RET)	Reference au dernier element de la liste ou 0 si erreur
 **********************************************************************/
{
	TabStruct	*pTabStr1, *pTabStr2;

	pTabStr1 = pTabStr2 = deb_struct;
	if (pTabStr1 == GenericNULL(TabStruct))
		return GenericNULL(TabStruct);

	while (pTabStr1 != GenericNULL(TabStruct)) {
		pTabStr2 = pTabStr1;
		pTabStr1 = pTabStr1->suiv;
	}
	return pTabStr2;
}

TabStruct *findstruct(char *n)

/**********************************************************************
 *      Recherche d'une structure dans la table deb_struct
 *      retourne la valeur 0 si elle n'est pas trouvee
 *									<> 0 sinon
 **********************************************************************/
{
	register TabStruct	*s;
	register int			i;	

	s = deb_struct;
	while (s != GenericNULL(TabStruct))
		{
		i = Xstrcmp(n,s->pid);
		if (i)
			s = s->suiv;
		else
			/* la structure existe */
			return s;
		}
	return(GenericNULL(TabStruct));
}

BYTE findcst(n,a,v)

/*      recherche d'une constante dans les tables
 *      retourne la valeur 0 si elle n'est pas trouvee, la valeur
 *      1 pour une constante binaire (*v contient alors sa valeur) ou
 *      2 pour une constante chaine ou BCD (*a contient alors le pointeur
 *      sur la description de la constante, et *v l'adresse de son descripteur)
 */
char *n;
BYTE **a;
BINAIRE *v;
{                               /* findcst */
	register TabSymb *s;
	register int i;
/* #SP: 11/10/99 (begin)*/
#ifndef __ATR22__
	int passe = 2;
#else
	int passe = 4;
#endif
/* #SP: 11/10/99 (end)*/
	BINAIRE d;

	/* test si la constante est un nom de module !!! */
	/* Syntaxe : <IDENT><.> */
	if ( usc.excode == MODULE ) 
		return(0);              

/* #SP: 11/10/99 (begin)*/
#ifndef __ATR22__
	s = deb_bincst; /* commencer avec les constantes binaires */
#else
	s = deb_bincst_local; /* commencer avec les constantes binaires */
#endif
/* #SP: 11/10/99 (end)*/
	do {
	   while (s != GenericNULL(TabSymb)) {
		i = Xstrcmp(n,s->pid);
		if (i < 0)
			s = s->g;
		else if (i > 0)
			s = s->d;
		else {  /* TROUVE ! */
		     	if (etat_tr != S_DECL)
			    s->opt &= (BYTE) ~OPT_USE; /* constante utilisee ! */
/* #SP: 11/10/99 (begin)*/
#ifndef __ATR22__
				if ( flglcst && flg_lcst_code && (passe != 2) ) {
#else
				if ((flglcst && flg_lcst_code && (passe != 2)) && (passe!=4)) {
#endif
/* #SP: 11/10/99 (end)*/
				if ( s->adsloc != 0xFFFF ) {
					*v = s->adsloc;
				} else {
					BINAIRE lg;
					/* creation du descripteur local */
					lg = mkcstgloloc(s->ads,&ladscst);
					/* relocation de cette constante globale */
	                                reftab(s->ads,ladscst);
					s->adsloc = ladscst;
					ladscst += lg;
					*v = s->adsloc;
				}
			} else		     
		     		*v = s->ads;

/* #SP: 11/10/99 (begin)*/
#ifndef __ATR22__
		     	if (passe == 2) {  /* retourner la valeur */
#else
				if (passe == 2 || passe==4) {  /* retourner la valeur */
#endif
/* #SP: 11/10/99 (end)*/
					return (1);
				}
		     	else {  /* retourner pointeur sur descripteur */
				/* l'acces est toujours sur la constante globale */
				/* car le descripteur local n'est qu'un descripteur */
				/* de redirection !!! */
					i = s->ads / SIZETDESC; /* i = num ss-table desc */
					d = s->ads % SIZETDESC; /* d = depl ss-table desc */
/* #SP: 11/10/99 (begin)*/
#ifdef __ATR22__
					if (passe==3 && flglcst) *a = lcst_tdesc[i] + d;
					else
#endif
/* #SP: 11/10/99 (end)*/
					*a = cst_tdesc[i] + d;
					return (2);
		     	}
		}
	   }
/* #SP: 11/10/99 (begin)*/
#ifndef __ATR22__
	   s = deb_bcdcst;	/* continuer avec les constantes chaines / BCD */
#else
	   if (passe==4) s = deb_bcdcst_local;
	   else if (passe==3)
			s = deb_bincst; /* commencer avec les constantes binaires */
	   else
			s = deb_bcdcst;  /* continuer avec les constantes chaines / BCD */
#endif
/* #SP: 11/10/99 (end)*/
	}
	while (--passe);
	return (0);     /* recherche n'aboutit pas ... */
}                               /* findcst */

BYTE *trouve_var(s,ext,passe,n,ads)

/**********************************************************************
 *		Fontion appelee uniquement par findvar().
 *		Les parametres sont les memes que ceux de findvar()
 *		evec en plus des parametres locals ... findvar()
 **********************************************************************/
TabSymb	*s;
BOOL		ext;
int		passe;
char		*n;
BINAIRE	*ads;
{
	register int i;
	BINAIRE d, ld;
	BYTE *pds;

    /* #OK: 11/07/00 (begin) */
	pds=0;
	/* #OK: 11/07/00 (end) */

	if (etat_tr != S_DECL) {
		/* 1ere utilisation de la variable et optimisation, il faut
			creer un descripteur */


	//	if (s->opt & (BYTE) OPT_NOT_DECLARE) { //non declaree*/

			/*Optimisation + var non utilisee + var en memoire */

		/*if (
				((!optimise_tables) && (s->opt & (BYTE) OPT_NOT_DECLARE))
				||
				((optimise_tables) && (s->opt & (BYTE) OPT_USE)) )
			)*/
		if (s->opt & (BYTE) OPT_NOT_DECLARE) /*non declaree dans la table, il faut mettre le descripteur*/
			{
			Type		*type;
			long int	svadrimpl = adrimpl;
			int		svlgptrfld = lgptrfld;
			BINAIRE	svadrptr = adrptr;
			BOOL		svfldptr = fldptr;

			type = s->type;
			adrimpl = type->adrimpl;

			/* membre d'une structure allouee dynamiquement */
			if (s->prev != GenericNULL(TabSymb)) {
				TabSymb	*s1;

				/* on remonte au niveau le plus haut (structures imbriquees) */
				s1 = s->prev;
				while (s1->prev != GenericNULL(TabSymb))
					s1 = s1->prev;

				if (!s1->type->pasptr) {
					lgptrfld = s1->type->l;
					adrptr = ext ? adsdclextcr : (passe == 3) ? (s1->ads | 0x8000) : s1->ads;
					fldptr = TRUE;
				}
			}

			ld = mkdcldesc((passe == 3) ? FALSE:TRUE,ext,type->pasptr,
								type->type,type->l,type->d1,type->d2,s->declext,s->fldptr,s->lgptrfld,s->adrptr);
			lgptrfld = svlgptrfld;
			adrptr = svadrptr;
			fldptr = svfldptr;
			adrimpl = svadrimpl;
			if (!ext) {
				if (passe == 3) {
					s->ads = adsdcl;
					adsdcl += ld;
					nb_dcl_local++;
				}
				else {
					s->ads = adsdcl_glb;
					adsdcl_glb += ld;
					nb_dcl_global++;
				}
			}
			else {
				s->ads = adsdclextcr;
				adsdclextcr +=ld;
			}
		}
		s->opt &= (BYTE) ~OPT_USE; /* variable utilisee ! */
		s->opt &= (BYTE) ~OPT_NOT_DECLARE; /* variable declaree */
	}
	*ads = s->ads;

	i = s->ads / SIZETDESC; /* i = num ss-table desc */
	d = s->ads % SIZETDESC; /* d = depl ss-table desc */
	if (ext) {
		/* externe */
		usc.excode = 0;
		pds = ext_tdesc[i] + d;
		*ads |= IS_EXTERN;         /* Variable externe */
		if ( s->lref == GenericNULL(ExtRef) )
			createextref(*ads,&(s->lref));
	} else 
	if (passe == 2) {
		pds = glb_tdesc[i] + d;
	} else
	if ( passe == 3 ) {
		pds = lcl_tdesc[i] + d; *ads |= 0x8000;
	}

	return (pds);
}

BYTE *findvar(n,pPasse,ads,pTabSymb,bWith)

/**********************************************************************
 *		Recherche d'une variable dans les tables
 *		n			(IN)		Nom de la variable ... rechercher
 *		pPasse	(IN/OUT)	Passe de recherche, le pointeur peut etre nul.
 *									3 : variable locale
 *									2 : variable globale
 *									1 : variable externe
 *								Si *pPasse <> 0, le contenu ne doit pas en etre
 *								modifie
 *		ads		(OUT)		Adresse du descripteur de la variable si Ok.
 *								avec la convention : 1er bit a 1
 *								si local, 0 si global.
 *		pTabSymb	(IN/OUT)	Reference ... la structure TabSymb ou la variable
 *								vient d'etre trouvee
 *								Si en entree, pTabSymb est non nul, la recherche
 *								commence sur un symbole particulier
 *		bWith		(IN)		Recherche des variables dans l'espace "With"
 *		
 *					(RET)		Pointeur vers le descripteur du symbole si Ok,
 *    						et NULL sinon.
 *
 *    en version 1.5 :
 *			recherche des variables externes
 *       syntaxe <nom de module>.<nom de variable>
 *		en version 2.2a :
 *			On trouve en plus de la syntaxe 1.5 la syntaxe pour les
 *			structures.
 *			Les 2 syntaxes peuvents se cumuler :
 *			<nom de module>.<structure>.<membre>
 *			Le parametre pTabSymb permet de reprendre une recherche.
 *			Exemple :
 *					MyAdresse.a.b = 2
 *					Lors d'un 1er appel ... findvar(), on a determine
 *					l'emplacement de 'MyAdresse' (variables globales
 *					deb_glbsymb, locales ou externes).
 *					On poursuit ensuite pour 'a' dans le meme arbre en changeant
 *					de niveau (pointeur next)
 *			findvar() est appelee avec le parametre pTabSymb <> 0 uniquement
 *			lorsqu'elle est appelee par elle meme.
 **********************************************************************/
char		*n;
BYTE	*pPasse;
BINAIRE	*ads;
TabSymb	**pTabSymb;
BOOL		bWith;
{                               /* findvar */
	register TabSymb *s;
	register TabMod *table;
	BINAIRE d,num;
	BYTE	passe;
	BYTE *pds;
	register int i;
	BOOL ext=FALSE;
	TabSymb	*pMyTabSymb1;
	BYTE		*padesc;

    /* #OK: 11/07/00 (begin) */
	s=GenericNULL(TabSymb);
	table=GenericNULL(TabMod);	
	pds=0;
	pMyTabSymb1=GenericNULL(TabSymb);
	padesc=0;
	/* #OK: 11/07/00 (end) */
	
	/* La recherche du symbole n'est pas globale, elle reprend une
		recherche precedante dans le cas des structures */
	if ((pTabSymb != GenericNULL(TabSymb *)) && (*pTabSymb != GenericNULL(TabSymb))) {
		s = *pTabSymb;
		passe = 1;
	}
	else {
		TabWith	*w;
		TabSymb	*pMyTabSymb2;

		/* 3 passes pour variable externe */
		passe = 3;

		/* Avec la clause "With", on peut avoir ... chercher dans des
			symboles existants */
		if (bWith) {
			BINAIRE d1;

			d1 = usc.excode;
			w = deb_with;
			while (w != GenericNULL(TabWith)) {
				/* le w->passe passe correspond ... l'endroit de la variable
					auquelle le "With" se refere */
				pMyTabSymb2 = w->Symb->next;
				if ((padesc = findvar(n,&w->passe,ads,&pMyTabSymb2,FALSE)) != GenericNULL(BYTE)) {					
					return padesc;					
				}
				w = w->suiv;
			}
			usc.excode = d1;
		}
	}

	/* Pour les variables externes : */

	if ( usc.excode == MODULE ) {
		d = usc.excode;         

		/* variable externe referencee par le module */

		/* Correction to avoid conflict between structure and module syntaxe*/
		/* <structure>.<member> and <module>.<variable>*/

		/*SG261198 Add begin*/
		table = deb_tnmod;
		num = NIL;
		while (table != GenericNULL(TabMod)) {
			if ( Xstrcmp(n,table->nom) == 0 ) {
				num = table->num;
				/* TROUVE */
				break;
			} else {
				table = table->suiv;
			}
		}
		/*SG261198 Add End*/

//		if (findcst(n,&pds,&modextcr) == 0) { /*BEFORE 261198*/
		if ((findcst(n,&pds,&modextcr) == 0)&&(num == NIL)) 
			{
			BYTE	passe1;

			/* il ne s'agit pas d'une reference ... une variable externe
				On verifie que l'on trouve la variable */
			usc.excode = 0;
			pMyTabSymb1 = (pTabSymb != GenericNULL(TabSymb *)) ? (*pTabSymb != GenericNULL(TabSymb)) ? *pTabSymb : GenericNULL(TabSymb) : GenericNULL(TabSymb);
			/* On doit savoir ou la variable est trouvee (globale, locale
				ou externe), on founie donc un pointeur sur passe1 */

			passe1 = 0;
			if (findvar(n,(pPasse && *pPasse) ? pPasse : &passe1,
							ads,&pMyTabSymb1,FALSE) == GenericNULL(BYTE))
				return(GenericNULL(BYTE));
			do	{
				BINAIRE	d1;

				usc.excode = 0;
				lexical();
				pMyTabSymb1 = pMyTabSymb1->next;
				d1 = usc.excode;
				usc.excode = 0;
                
				/* on recherche tant qu'un '.' suit */
				if (findvar(n,&passe1,ads,
								&pMyTabSymb1,FALSE) == GenericNULL(BYTE))
//				if (findvar(n,GenericNULL(BYTE),ads,
//								&pMyTabSymb1,FALSE) == GenericNULL(BYTE))
					return(GenericNULL(BYTE));							

				usc.excode = d1;
			} while (usc.excode == MODULE);

			/* *pPasse n'est pas modifie si non nul */
			if ((pPasse != GenericNULL(BYTE)) && !*pPasse)
				*pPasse = passe;
			/* la donnee membre finale est trouvee mais l'espace d'allocation
				est determine par la recherche de la structure instanciee
				(plus haut) */
			return (trouve_var(pMyTabSymb1, ext,
									 (pPasse && *pPasse) ? *pPasse : passe1,
									 n, ads));
		}
		modextcr = num;/*SG261198 Adds*/
		usc.excode = d;
		lexical();
		if ( usc.code == IDENT )
			n = usc.v.pval;
		ext = TRUE;
		passe = 1;
		s = deb_extsymb;        
	}
	else {
		if ( verrue_findvar == FALSE ) {
			modextcr = 0xFFFF;
		}
		/* 3 passes demandees, on commence par les variables locales */
		if (passe == 3)
			s = deb_lclsymb; /* commencer avec la table du niveau local */
	}

	do {
	   while (s != GenericNULL(TabSymb)) {
			i = Xstrcmp(n,s->pid);
			if (i < 0)
				s = s->g;
			else if (i > 0)
				s = s->d;
			else {  
				/* Critere suplementaire : numero de module */
				if (s->mod < modextcr)
					s = s->g;
				else if (s->mod > modextcr)
					s = s->d;
				else {  /* TROUVE ! */
					/* Version 2.2a, on renseigne pTabSymb si <> 0 */
					if (pTabSymb != GenericNULL(TabSymb *))
						*pTabSymb = s;
					/* *pPasse n'est pas modifie si non nul */
					if ((pPasse != GenericNULL(BYTE)) && !*pPasse)
						*pPasse = passe;

					return (trouve_var(s, ext,
											 (pPasse != GenericNULL(BYTE)) ? *pPasse : passe,
											 n, ads));
				}
			}
	   }
	if ( passe == 3 )       
	   s = deb_glbsymb;     /* si pas local, essayer table niveau global */
	else {
	   ext=TRUE; s = deb_extsymb;   /* si pas local, pas global essayer externe */
	}
	}
	while (--(passe));
	return (GenericNULL(BYTE));     /* recherche n'aboutit pas ... */
}                               /* findvar */


TabProc *findproc(nmod,n)

/*      recherche d'une procedure dans la table
 *      retourne le pointeur vers le descripteur si Ok,
 *      et NULL sinon.
 */
BINAIRE nmod;
char *n;
{                               /* findproc */
	register TabProc *s;
	register int i;

	/* Pour les procedures externes */

	BYTE *pds;
	BOOL ext = FALSE;

	if ( usc.excode == MODULE ) {
		ext = TRUE;
		if ( nmod != 0 ) {
			usc.excode = 0;
			if (findcst(n,&pds,&modextcr) == 0) {
				return(GenericNULL(TabProc));
			}
			lexical();
			if ( usc.code == IDENT )
				n = usc.v.pval;
		} else  
			nmod = modextcr;
	} else {
		if ( nmod )
			ext = TRUE;
		else
			nmod = NIL;
	}

	s = deb_tproc;
	while (s != GenericNULL(TabProc)) {
		i = Xstrcmp(n,s->pid);
		if (i < 0)
			s = s->g;
		else if (i > 0)
			s = s->d;
		else { 
			if ( s->mod < nmod )
			/*if ( (s->mod < nmod) && (s->mod != NIL) && (nmod != NIL)) Don't produce ATR error message */
				s = s->g;
			else if ( s->mod > nmod )
			/*else if ( (s->mod > nmod) && (s->mod != NIL) && (nmod != NIL)) Don't produce ATR error message */
				s = s->d;
			else {
				usc.excode = 0;
				break;
			}                       
		}
	}
	return (s);
}                               /* findproc */


TabSeg *findseg(nmod,n)

/*      recherche d'un segment dans la table
 *      retourne le pointeur vers le descripteur si Ok,
 *      et NULL sinon.
 */
BINAIRE nmod;
char *n;
{                               /* findseg */
	register TabSeg *s;
	
	/* Pour les segments externes */

	BYTE *pds;

	if ( usc.excode == MODULE ) {
		if ( nmod != 0 ) {
			usc.excode = 0;
			if (findcst(n,&pds,&modextcr) == 0) {
				return(GenericNULL(TabSeg));
			}
			lexical();
			if ( usc.code == IDENT )
				n = usc.v.pval;
		} else  {
			usc.excode = 0; /* 21/12/94 */
			nmod = modextcr;
		}
	} else {
		if ( nmod == 0 )
			nmod = 0xFFFF;
	}
	s = deb_tseg;
	while (s != GenericNULL(TabSeg)) {
		if ( nmod == s->mod ) {
			if ( Xstrcmp(n,s->nom) == 0 ) {
				/* TROUVE */
				break;
			} else
				s = s->suiv;
		} else
			s = s->suiv;
	}
	return (s);
}                               /* findseg */


BINAIRE findmod(n)

/*      recherche d'un nom de module dans la table
 *      retourne le numero de ce nom s'il existe et le cree s'il n'existe pas
 */
char *n;
{                               /* findmod */
	register TabMod *s;
	BINAIRE num = NIL;

	s = deb_tnmod;
	while (s != GenericNULL(TabMod)) {
		if ( Xstrcmp(n,s->nom) == 0 ) {
			num = s->num;
			/* TROUVE */
			break;
		} else {
			s = s->suiv;
		}
	}
	if ( num == NIL ) {
		/* Allouer ce nouveau nom de module */
		s = All_Tnmod();                /* alloc nouveau nom */
		if (s == GenericNULL(TabMod))   /* mais debordement memoire */
			erreur(FATALE,errmem);

		/* recopie du nouveau nom */
		if ( deb_tnmod == GenericNULL(TabMod) ) {
			s->num = 1;
		} else {
			s->num = deb_tnmod->num+1;
		}
		Xstrcpy(s->nom,n);

		/* insertion dans la liste en tete */
		s->suiv = deb_tnmod;
		deb_tnmod = s;

		/* retour du numero */
		num = s->num;
	}

	return (num);
}                               /* findmod */


BINAIRE findsrc(n)

/*      recherche d'un nom de source dans la table
 *      retourne le numero de ce nom s'il existe et le cree s'il n'existe pas
 */
char *n;
{                               /* findsrc */
	register TabSrc *s;
	BINAIRE num=NIL; /* BINAIRE */

	s = deb_tnsrc;
	while (s != GenericNULL(TabSrc)) {
		if ( Xstrcmp(n,s->nom) == 0 ) {
			num = s->num;
			/* TROUVE */
			break;
		} else {
			s = s->suiv;
		}
	}
	if ( num == NIL ) {
		/* Allouer ce nouveau nom de source */
		s = All_Tnsrc();                /* alloc nouveau nom */
		if (s == GenericNULL(TabSrc))   /* mais debordement memoire */
			erreur(FATALE,errmem);

		/* recopie du nouveau nom */
		if ( deb_tnsrc == GenericNULL(TabSrc) ) {
			s->num = 1;
		} else {
			s->num = deb_tnsrc->num+1;
		}
		if ((s->nom = Xmalloc(Xstrlen(n)+1)) == GenericNULL(char)) 
		/* mais debordement memoire */
			erreur(FATALE,errmem);

		Xstrcpy(s->nom,n);

		/* insertion dans la liste en tete */
		s->suiv = deb_tnsrc;
		deb_tnsrc = s;

		/* retour du numero */
		num = s->num;
	}

	return (num);
}                               /* findsrc */


BOOL recbincst(valeur)

/*      recherche une constante binaire, et retourne TRUE si c'est le cas,
 *      avec en plus la valeur dans l'argument
 */
BINAIRE *valeur;
{                                       /* recbincst */
	BYTE *a = GenericNULL(BYTE);
	BOOL signe = FALSE;

	if (usc.code == PLUS) lexical();
	else if (usc.code == MOINS) {
		signe = TRUE; lexical();
	}
	if (usc.code == CBIN) {
		if (signe) usc.v.val = -usc.v.val;
		*valeur = usc.v.val; return (TRUE);
	}
	if ((usc.code == IDENT) && (findcst(usc.v.pval,&a,valeur) == 1)) {
		if (signe) *valeur = -(*valeur);
		return (TRUE);
	}
	return (FALSE);
}                                       /* recbincst */


void defetiq(nom,adr)

/*      definition d'une etiquette designee par 'nom' a l'adresse 'adr'
 */
char *nom;
BINAIRE adr;
{                               /* defetiq */
	register TabEtiq *p;
	register int i;
	TabEtiq  *s = GenericNULL(TabEtiq);

	p = deb_tetiq;          /* recherche emplacement dans la table */
	while (p != GenericNULL(TabEtiq)) {
		i = Xstrcmp(nom,p->pid);
		if (i < 0)
			s = p, p = p->g;
		else if (i > 0)
			s = p, p = p->d;
		else            /* etiquette deja presente */
			if (p->adef != (BINAIRE) 0xFFFF) {
			   erreur(USUAL,ersymb6); return; /* deja definie */
			}
			else {
			   p->adef = adr;
			   return;
			}
	};
	p = All_Etiq();                 /* allouer une nouvelle etiquette */
	if (p == GenericNULL(TabEtiq))  /* mais debordement memoire */
		erreur(FATALE,errmem);
	if (s == GenericNULL(TabEtiq))  /* premiere etiquette ? */
		deb_tetiq = p;
	else
	   if (i < 0)
		s->g = p;
	   else
		s->d = p;
	p->g = p->d = GenericNULL(TabEtiq);
	p->lref = (BINAIRE) 0xFFFF;
	Xstrcpy(p->pid,nom);

/* #ifdef WIN1632
	{ extern BINAIRE glseg;
	  if ((glseg == 113) && (adr > 0x0600)) {
		BYTE buf[128];
		extern void _far _pascal OutputDebugString(char *);
		sprintf(buf,"\r\nDef: %s : %0.4X",p->pid,adr);
		OutputDebugString(buf);
	  }
	}
#endif
*/
	p->adef = adr;
	p->opt = 0;     /* inutilisee */
}                               /* defetiq */


BINAIRE refetiq(nom,adr)

/*      reference a une etiquette designee par 'nom' a l'adresse 'adr'
 *      retourne la valeur d'adressage, ou l'adresse de la derniere reference
 *      si l'etiquette est indefinie, la reference ayant alors ete chainee
 */
char *nom;
BINAIRE adr;
{                               /* refetiq */
	register TabEtiq *p;
	register int i;
	BINAIRE  lr;
	TabEtiq  *s = GenericNULL(TabEtiq);

	p = deb_tetiq;          /* recherche emplacement dans la table */
	while (p != GenericNULL(TabEtiq)) {
		i = Xstrcmp(nom,p->pid);
		if (i < 0)
			s = p, p = p->g;
		else if (i > 0)
			s = p, p = p->d;
		else {
			/* etiquette deja presente */
			p->opt = 1;     /* signaler son utilisation */
			if (p->adef != (BINAIRE) 0xFFFF) { /* et definie ! */
/*#ifdef WIN1632
	{ extern BINAIRE glseg;
	  if ((glseg == 113) && (adr > 0x0600)) {
		BYTE buf[128];
		extern void _far _pascal OutputDebugString(char *);
		sprintf(buf,"\r\nRefDef: %s : %0.4X is %0.4X",nom,adr,p->adef);
		OutputDebugString(buf);
	  }
	}
#endif
*/
				return(p->adef);
			}
			else {  /* sinon ajouter la nouvelle reference */
				lr = p->lref;
				p->lref = adr;
				return (lr);
			}
		}
	};

/*#ifdef WIN1632
	{ extern BINAIRE glseg;
	  if ((glseg == 113) && (adr > 0x0600)) {
		BYTE buf[128];
		extern void _far _pascal OutputDebugString(char *);
		sprintf(buf,"\r\nRefNouv: %s : %0.4X",nom,adr);
		OutputDebugString(buf);
	  }
	}
#endif
*/
	p = All_Etiq();                 /* allouer une nouvelle etiquette */
	if (p == GenericNULL(TabEtiq))  /* mais debordement memoire */
		erreur(FATALE,errmem);
	if (s == GenericNULL(TabEtiq))  /* premiere etiquette ? */
		deb_tetiq = p;
	else
	   if (i < 0)
		s->g = p;
	   else
		s->d = p;
	p->g = p->d = GenericNULL(TabEtiq);
	p->lref = adr;
	Xstrcpy(p->pid,nom);
	p->adef = (BINAIRE) 0xFFFF;  /* pas encore d'adresse de definition */
	p->opt = 1;     /* signaler l'utilisation */
	return ((BINAIRE) 0xFFFF);
}                               /* refetiq */


void refproc(dproc,bloc,ofst)

/*      Reference a une procedure externe dont le descripteur est pointe
 *      par 'dproc', et a la position 'bloc','ofst' dans le traduit
 */
TabProc *dproc;
BINAIRE bloc,ofst;
{                               /* refproc */
	ExtRef  *r;

	r = All_Ref();
	if (r == GenericNULL(ExtRef))
		erreur(FATALE,errmem);
	r->suiv = dproc->lref;
	r->bloc = bloc; r->ofst = ofst;
	dproc->lref = r; nb_refpext++;
}                               /* refproc */


void refseg(dseg,bloc,ofst)

/*      Reference a un segment externe dont le descripteur est pointe
 *      par 'dseg', et a la position 'bloc','ofst' dans le traduit
 */
TabSeg *dseg;
BINAIRE bloc,ofst;
{                               /* refseg */
	ExtRef  *r;

	r = All_Ref();
	if (r == GenericNULL(ExtRef))
		erreur(FATALE,errmem);
	r->suiv = dseg->lref;
	r->bloc = bloc; r->ofst = ofst;
	dseg->lref = r; nb_refsext++;

}                               /* refseg */


void lienseg(dseg,bloc,ofst)

/*      Reference dans le segment en cours d'analyse
 *      a la procedure dont le descripteur est pointe par
 *      'dproc', et a la position 'bloc','ofst' dans le traduit
 */

TabSeg *dseg;
BINAIRE bloc,ofst;
{                                       /* lienseg */
	LienRef  *r;

	r = All_LienR();
	if (r == GenericNULL(LienRef))
		erreur(FATALE,errmem);

	r->suiv = lienc;        /* chainage par l'arriere */
	lienc = r;

	r->proc_or_seg = FALSE;
	r->desc.dseg = dseg;

	r->bloc = bloc;
	r->ofst = ofst;
}                                       /* lienseg */


void lienproc(dproc,bloc,ofst)

/*      Reference dans la procedure en cours d'analyse
 *      a la procedure dont le descripteur est pointe par
 *      'dproc', et a la position 'bloc','ofst' dans le traduit
 */

TabProc *dproc;
BINAIRE bloc,ofst;
{                                       /* lienproc */
	LienRef  *r;

	r = All_LienR();
	if (r == GenericNULL(LienRef))
		erreur(FATALE,errmem);

	r->suiv = lienc;        /* chainage par l'arriere */
	lienc = r;

	r->proc_or_seg = TRUE;
	r->desc.dproc = dproc;

	r->bloc = bloc;
	r->ofst = ofst;
}                                       /* lienproc */

static void set_prev(pTabSymb, pValPrev)

/**********************************************************************
 *    Initialisation de tous les pointeur prev d'un noeud de symboles
 *		La fonction est utilisee quand un nouveau noeud accessible par ->next
 *		est completement cree.
 *		Chaque element doit conserver une reference au niveau superieur
 *		pTabSymb		(OUT)	1er element de la grappe
 *		pValPrev		(IN)	Valeur ... mettre dans le ->prev de tous les
 *								elements
 **********************************************************************/

TabSymb	*pTabSymb;
TabSymb	*pValPrev;

{
	if (pTabSymb->g != GenericNULL(TabSymb))
		set_prev(pTabSymb->g, pValPrev);
	if (pTabSymb->d != GenericNULL(TabSymb))
		set_prev(pTabSymb->d, pValPrev);
	pTabSymb->prev = pValPrev;
}

static void reftab(adsglo,adsloc)
/*      reference a une constante globale en vue de sa relogeabilite
 * 	dans le cas de l'utilisation des constantes locales.
 *	Cette liste des constantes sera patchee lors de la recopie de
 *	cette liste sur disque (fin de segment ou de procedure).
 */
BINAIRE adsglo,adsloc;
{                               /* reftab */
	RelRef  *p;
	ExtRef  *r;

	r = All_Ref();
	if (r == GenericNULL(ExtRef))
		erreur(FATALE,errmem);

	/* cette refference devra etre convertie en bloc/ofst */
	r->bloc = 0xFFFF; r->ofst = adsloc+2;

	p = TcstRef;    /* balayer la table des constantes */

	while (p != GenericNULL(RelRef)) {
		if (p->ads == adsglo) {  /* objet deja reference */
			r->suiv = p->lref; p->lref = r; return;
		}
		p = p->suiv;
	}
	/* premiere reference a cet objet */
	p = All_Lref();
	if (p == GenericNULL(RelRef))
		erreur(FATALE,errmem);
	p->ads = adsglo;
	p->lref = r;
	r->suiv = GenericNULL(ExtRef);
	p->suiv = TcstRef; TcstRef = p;

}                               /* reftab */


static void patchreftab(no)
/*	remplacement de l'adresse descripteur local en couple
 *	(bloc,offset)
 */
BINAIRE no;
{                               /* patchreftab */
	RelRef  *p;
	ExtRef  *r;

	/* remise ... 0xFFFF de toutes les adresses adsloc de la table 	*/
	/* des constantes locales str et bcd 				*/
	initadsloc(deb_bcdcst);

	p = TcstRef;    /* balayer la table des constantes */

	while (p != GenericNULL(RelRef)) {
		r = p->lref;
		while ( r != GenericNULL(ExtRef) ) {
			if ( r->bloc != 0xFFFF )
				break;
			r->bloc = no + (r->ofst / 256);
			r->ofst = r->ofst % 256;			
			r = r->suiv;
		}
		p = p->suiv;
	}
}                               /* patchreftab */


static void initadsloc(s)
TabSymb *s;
{				/* initadsloc */
	if ( s != GenericNULL(TabSymb) ) {
		initadsloc(s->g);
		s->adsloc = 0xFFFF;
		initadsloc(s->d);
	}
}				/* initadsloc */


void refobj(isavar,adesc,bloc,ofst)

/*      reference a un objet global en vue de sa relogeabilite, 'isavar'
 *      vaut TRUE pour le cas d'une variable, et FALSE pour une constante,
 *      la reference etant a la position 'bloc','ofst' dans le traduit.
 */
BOOL    isavar;
BINAIRE adesc,bloc,ofst;
{                               /* refobj */
	RelRef  *p;
	ExtRef  *r;

	if ( (isavar == TRUE) && ((adesc & IS_EXTERN) == IS_EXTERN) ) {
	/* Variable externe */
		insextref(adesc,bloc,ofst);
	} else {
		/* Dans le cas du traitement des constantes locales	*/
		/* les adresses des constantes ne sont pas relogees 	*/
		/* dans le code. Par contre, il faut reloger les 	*/
		/* adresses des constantes dans la table des constantes */
		/* locales.						*/
		if ( (isavar == TRUE) || (flglcst == FALSE) ) {

	r = All_Ref();
	if (r == GenericNULL(ExtRef))
		erreur(FATALE,errmem);
	r->bloc = bloc; r->ofst = ofst;
	if (isavar)
		p = TvarRef;    /* balayer la table des variables */
	else
		p = TcstRef;    /* balayer la table des constantes */
	while (p != GenericNULL(RelRef)) {
		if (p->ads == adesc) {  /* objet deja reference */
			r->suiv = p->lref; p->lref = r; return;
		}
		p = p->suiv;
	}
	/* premiere reference a cet objet */
	p = All_Lref();
	if (p == GenericNULL(RelRef))
		erreur(FATALE,errmem);
	p->ads = adesc;
	p->lref = r;
	r->suiv = GenericNULL(ExtRef);
	if (isavar) {
		p->suiv = TvarRef; TvarRef = p;
	}
	else {
		p->suiv = TcstRef; TcstRef = p;
	}
	} /* 25/10/94 */
	}
}                               /* refobj */


void refrt(nort,bloc,offst)

/*      Reference a la runtime de numero 'nort', situee dans
 *      le bloc 'bloc' a l'offset 'offst'.
 */

BYTE nort;
BINAIRE bloc;
BINAIRE offst;
{                               /* refrt */
	TabuRef *t;

	t = All_TabuRef();
	if (t == GenericNULL(TabuRef))
		erreur(FATALE,errmem);

	t->suiv = TusrRef;              /* chainage inverse */
	t->nort = nort;
	t->bloc = bloc;
	t->offst = offst;
	TusrRef = t;
}                               /* refrt */


void freelocal()

/*      liberation des tables de symboles au niveau local
 */
{                               /* freelocal */
	/* liberer la table des variables locales */
	if (deb_lclsymb != GenericNULL(TabSymb)) {
		libnoeud(deb_lclsymb);
		deb_lclsymb = GenericNULL(TabSymb);
	}
}                               /* freelocal */


	/*      --------------------    *
	 *      Primitives internes     *
	 *      --------------------    */

static BOOL rec_depl(ads,depl)

/*      traitement des dimensions d'un tableau, retourne le deplacement
 *      en octets par rapport au debut d'implantation.
 *      les dimensions doivent etre des constantes binaires.
 */
BYTE *ads;
long int *depl;
{                                       /* rec_depl */
	BINAIRE d1,v1,d2,v2;
	int k=4;        /* offset min 1ere dimension dans descripteur */
	BYTE t;

	lexical(); if (usc.code != PAG) return(FALSE);
	lexical(); if (!recbincst(&v1)) return(FALSE);
	t = typdesc(ads);
	if ((IS_TBCD(t)) || (IS_TSTR(t))) k += 2;
	if (*(ads + 1) != 0) k += 2;            /* *(ads+k) = 1ere dimension */
	d1 = bytetobin(ads+k);
	if (negbin(v1) || (v1 == 0)) return (FALSE);
	if (bincmp(v1,d1) > 0) return (FALSE); /* out of range ! */
	*depl = bintolong(v1) - 1L;
	if ((*ads & SECOND_INDEX) != 0) {       /* il y a une 2eme dimension */
		lexical(); if (usc.code != VIG) return(FALSE);
		lexical(); if (!recbincst(&v2)) return(FALSE);
		d2 = bytetobin(ads+k+2);
		if (negbin(v2) || (v2 == 0)) return (FALSE);
		if (bincmp(v2,d2) > 0) return (FALSE); /* out of range */
		*depl = (bintolong(v2) - 1L) * bintolong(d1);
		*depl += (bintolong(v1) - 1L);
	}
	lexical(); if (usc.code != PAD) return(FALSE);
	/* a ce stade : depl contient le nombre de dimensions,
	   si redefinition a partir de 1 ... ca fera toujours 0 ... */
	if (*depl != 0L) {
	    /* sinon, il faut tenir compte de la longueur de chaque
	       element du tableau concerne ... */
	    switch (t) {
		case TBIN1: v1 = 1; break;
		case TBIN2: v1 = 2; break;
		default:
			k = 4;
			if (*(ads + 1) != 0) k += 2; /* adresse sur 4 octets */
			v1 = bytetobin(ads+k);
			break;
	    }
	    *depl = *depl * bintolong(v1);
	}

	return (TRUE);
}                                       /* rec_depl */


static BYTE getype(b)
BOOL b;
/*      avance dans le source a la recherche d'un type de donnee, et
 *      retourne le code correspondant.
 *
 *      ver15 : ajout du type LIKE idem une autre variable
 *              ajout du type PTR
 */
{                                       /* getype */
	BYTE res=0;
	if ( b )
		lexical();
	if ( usc.code == PTR ) {
		res=0x008;
		lexical();
	}
	switch (usc.code) {
		case LIKE:
			lexical(); return (res+TLIKE);
		case DIESE:
			lexical(); return (res+TBIN1);
		case PCENT:
			lexical(); return (res+TBIN2);
		case STR:
			lexical(); return (res+TSTR);
		default:
			return (res+TBCD);
	}
}                                       /* getype */


/*static*/ BINAIRE getlong(t)

/*      recherche une longueur pour une variable chaine ou BCD
 *      retourne la valeur 0 si erreur.
 */
BYTE t;
{                                       /* getlong */
	BINAIRE l;

	if (usc.code == EGAL) {
		lexical();
		if (recbincst(&l)) {    /* constante numerique entiere */
			lexical();
			if (negbin(l) || (l == 0))
				return (0); /* long. negative interdite */
			if ( ((t == TBCD) && (l <= LGBCD)) ||
			     ((t == TSTR) && (l <= LGSTR)) )
				return (l);
		}
		return (0);     /* erreur */
	}
	else if (t == TBCD)
		return (LGSTDBCD);      /* lg standard BCD */
	else
		return (LGSTDSTR);      /* lg standard chaine */
}                                       /* getlong */


static BINAIRE getdim()

/*      recherche d'une dimension de tableau
 *      retourne la valeur 0 si erreur.
 */
{                                       /* getdim */
	BINAIRE l;

	lexical();
	if (recbincst(&l)) {
		lexical();
		if (l == 0) erreur(USUAL,ersymb3);
	}
	else
		l = 0;
	return (l);
}                                       /* getdim */


static BOOL newvar(pTabSymb,niv, ext,n,flg,bModifpTabSymb,bStructApprend,pType,bOptimiseTable)

/**********************************************************************
 *		Version 2.2a, nouvelle fonction.
 *		Rechercher une place pour une nouvelle variable dans la liste des
 *		variables globales, externe, locales ou autre.
 *		pTabSymb			(OUT)	Pointeur sur un pointeur de liste type TabSymb
 *									deb_glbsymb, deb_lclsymb, deb_extsymb ou autre
 *									Le contenu pointe n'est modifie que si
 *									sa valeur etait nulle
 *		ext				(IN)	Variable externe
 *		n					(IN)	Nom de la nouvelle variable
 *		flg				(IN)	La variable peut etre un registre
 *		bModifpTabSymb	(IN)	Le pointeur pointe par pTabSymb et modifie (TRUE)
 *									ou non modifie (FALSE)
 *		bStructApprend	(IN)	Mode apprentissage de la declaration d'un
 *									membre de structure
 *		pType				(IN)	Reference a une structure Type du type de
 *									la variable
 *
 *		(RET)	TRUE si symbole cree.
 *      si retour Ok, l'identificateur est deja recopie dans la table.
 *      peut arreter la traduction si il y a debordement de memoire.
 **********************************************************************/
BOOL niv, ext,flg,bModifpTabSymb,bStructApprend;
char *n;
TabSymb **pTabSymb;
Type *pType;
BOOL bOptimiseTable;
{                               /* newvar */
	register int i;
	register TabSymb *s;
	TabSymb *f = GenericNULL(TabSymb);
	BINAIRE v;
	BYTE *a = GenericNULL(BYTE);
	TabStruct	*pTabStr;

	/* 2.2a : si il sagit d'un membre de structure, on ne verifie pas
		la presence d'une constante de meme non */
	if (!bStructApprend && (findcst(n,&a,&v) != 0))
		return (FALSE);

	s = *pTabSymb;

	/* cas des structures en mode apprentissage a partir de la 2.2a */
  if (bStructApprend) {
		/* On recherche la structure courante soit la derniere de la
			liste de deb_struct */
		pTabStr = get_last_struct();
		if (pTabStr == GenericNULL(TabStruct))
			return (FALSE);
		s = pTabStr->Symb;
	}

	/*      recherche emplacement du nouveau symbole */
	while (s != GenericNULL(TabSymb)) {
		i = Xstrcmp(n,s->pid);
		if (i < 0)
			f = s, s = s->g;
		else if (i > 0)
			f = s, s = s->d;
/* ver15 : nouveau critere numero de module */
		else { 
			if ( ext ) {
				if ( s->mod < modextcr )
					f = s, s = s->g;
				else if ( s->mod > modextcr )
					f = s, s = s->d;
				else
					return (FALSE); /* symbole deja existant */
			} else {
				return (FALSE); /* symbole deja existant */
			}       
		}
	}
	s = All_Symb();         /* alloc nouveau symbole */

	if (s == GenericNULL(TabSymb))          /* mais debordement memoire */
		erreur(FATALE,errmem);

	if (f != GenericNULL(TabSymb))
	{
		if (i < 0)      /* inserer le nouveau symbole dans la table */
			f->g = s;
		else if ( i > 0 )
			f->d = s;
		else {
			if ( f->mod < modextcr )
				f->g = s;
			else
				f->d = s;
		}
	/* #OK: 09/12/99 (begin) */
#ifdef __ATR22__
		if (bProcParam)
		{
			new_deb_lclsymb->d = ALLOC_TABSYMB_ITM;
			new_deb_lclsymb = new_deb_lclsymb->d; // go to next element of the list
		}
#endif
	/* #OK: 09/12/99 (end) */
	}
	else {
		if (bStructApprend)
			pTabStr->Symb = s;
		*pTabSymb = s;
		}

	if (bModifpTabSymb)
		*pTabSymb = s;

	Xstrcpy(s->pid,n);      /* recopie de l'ident */
	if ( ext ) {
		s->mod = modextcr;
		s->lref = GenericNULL(ExtRef); 
		s->ads = adsdclextcr;           
		insxvar(ptancr,s);
	} else {
		s->mod = 0xFFFF;
		s->lref = GenericNULL(ExtRef);
		s->ads = (niv) ? adsdcl_glb : adsdcl; //99999       /* conserver le descripteur */
	}       
	s->opt = (BYTE) OPT_USE; /* variable non encore utilisee */
	/* Le descripteur de la variable est ajoute en fonction
		du pragma "optimise tables" */
	if (bOptimiseTable)
	{
		s->opt |= OPT_NOT_DECLARE;
		s->declext = declext; /*rajout SG 19/03/99 Optimisation des FIELD=E, FIELD=no*/
		s->fldptr = fldptr;	/* id */
		s->lgptrfld = lgptrfld; /* id */
		s->adrptr = adrptr; /* id */
	}
	s->g = s->d = s->next = GenericNULL(TabSymb);
	s->type = pType;
	s->prev = GenericNULL(TabSymb);

	/* #OK: 09/12/99 (begin) */
#ifdef __ATR22__
	if (bProcParam && (!new_deb_lclsymb == GenericNULL(TabSymb)))
		{			  
		/* Add list element for parametrs in the procedure */
		for (i=0; i < LGIDENT; i++)
			new_deb_lclsymb->pid[i] = s->pid[i];
		new_deb_lclsymb->mod = s->mod;
		new_deb_lclsymb->lref = s->lref;
		new_deb_lclsymb->adsloc = s->adsloc;
		new_deb_lclsymb->opt = s->opt;
		new_deb_lclsymb->ads = s->ads;
		new_deb_lclsymb->g = GenericNULL(TabSymb);
		new_deb_lclsymb->d = s->d;
		new_deb_lclsymb->prev = s->prev;
		new_deb_lclsymb->next = s->next;
		new_deb_lclsymb->type = s->type;
		new_deb_lclsymb->declext = s->declext;
		new_deb_lclsymb->fldptr = s->fldptr;
		new_deb_lclsymb->lgptrfld = s->lgptrfld;
		new_deb_lclsymb->adrptr = s->adrptr;           
		}
#endif
	/* #OK: 09/12/99 (end) */


	return (TRUE);
}                               /* newvar */


static BOOL newconst(bin,n,a)

/*      recherche une place pour une nouvelle constante 'n', de type binaire
 *      si bin est vrai, chaine ou BCD sinon.
 *      retourne TRUE si OK, et FALSE sinon (symbole deja present).
 *      si retour Ok, l'identificateur est deja recopie dans la table.
 *      peut arreter la traduction si il y a debordement de memoire.
 */
BOOL bin;
char *n;
BINAIRE a;
{                               /* newconst */
	register int i;
	register TabSymb *s;
	TabSymb *f = GenericNULL(TabSymb);
	BINAIRE v;
	BYTE  *ad = GenericNULL(BYTE);

	if (findvar(n,GenericNULL(BYTE),&v,GenericNULL(TabSymb *),TRUE) != GenericNULL(BYTE)) /* deja declare variable */
		return (FALSE);
	if (findcst(n,&ad,&v) != 0)     /* deja declare comme constante */
		return (FALSE);
	/*      selection de la table concernee suivant le contexte */
	if (bin)
		s = deb_bincst;
	else
		s = deb_bcdcst;
	/*      recherche emplacement du nouveau symbole */
	while (s != GenericNULL(TabSymb)) {
		i = Xstrcmp(n,s->pid);
		if (i < 0)
			f = s, s = s->g;
		else if (i > 0)
			f = s, s = s->d;
	}
	s = All_Symb();         /* alloc nouveau symbole */
	if (s == GenericNULL(TabSymb))          /* mais debordement memoire */
		erreur(FATALE,errmem);
	if (f != GenericNULL(TabSymb))
	   if (i < 0)           /* inserer le nouveau symbole dans la table */
		f->g = s;
	   else
		f->d = s;
	else
	   if (bin)             /* nouveau symbole = debut de table */
		deb_bincst = s;
	   else
		deb_bcdcst = s;
	Xstrcpy(s->pid,n);      /* recopie de l'ident */
	s->ads = a;             /* conserver le descripteur */

	s->adsloc = 0xFFFF;

	s->opt = (BYTE) OPT_USE; /* constante non encore utilisee */
	s->lref = GenericNULL(ExtRef);
	s->g = s->d = s->next = s->prev = GenericNULL(TabSymb);
	s->type = GenericNULL(Type);
	
	return (TRUE);
}                               /* newconst */

/* #SP: 11/10/99 (begin) */
#ifdef __ATR22__

static BOOL newconst_local(bin,n,a)

/*      recherche une place pour une nouvelle constante 'n', de type binaire
 *      si bin est vrai, chaine ou BCD sinon.
 *      retourne TRUE si OK, et FALSE sinon (symbole deja present).
 *      si retour Ok, l'identificateur est deja recopie dans la table.
 *      peut arreter la traduction si il y a debordement de memoire.
 */
BOOL bin;
char *n;
BINAIRE a;
{
	register int i;
	register TabSymb *s;
	TabSymb *f = GenericNULL(TabSymb);
	BINAIRE v;
	BYTE  *ad = GenericNULL(BYTE);

	if (findvar(n,GenericNULL(BYTE),&v,GenericNULL(TabSymb *),TRUE) != GenericNULL(BYTE)) /* deja declare variable */
		return (FALSE);
	if (findcst(n,&ad,&v) != 0)     /* deja declare comme constante */
		return (FALSE);
	/*      selection de la table concernee suivant le contexte */
	if (bin)
		s = deb_bincst_local;//deb_lclsymb;//deb_bincst;
	else
		s = deb_bcdcst_local;
	/*      recherche emplacement du nouveau symbole */
	while (s != GenericNULL(TabSymb)) {
		i = Xstrcmp(n,s->pid);
		if (i < 0)
			f = s, s = s->g;
		else if (i > 0)
			f = s, s = s->d;
	}
	s = All_Symb();         /* alloc nouveau symbole */
	if (s == GenericNULL(TabSymb))          /* mais debordement memoire */
		erreur(FATALE,errmem);
	if (f != GenericNULL(TabSymb))
	   if (i < 0)           /* inserer le nouveau symbole dans la table */
		f->g = s;
	   else
		f->d = s;
	else
	   if (bin)             /* nouveau symbole = debut de table */
		deb_bincst_local = s;
	   else
		deb_bcdcst_local = s;
	Xstrcpy(s->pid,n);      /* recopie de l'ident */
	s->ads = a;             /* conserver le descripteur */

	if (!flglcst) s->adsloc = 0xFFFF;
	else s->adsloc = ladscst;
	s->opt = (BYTE) OPT_USE; /* constante non encore utilisee */
	s->lref = GenericNULL(ExtRef);
	s->g = s->d = s->next = s->prev = GenericNULL(TabSymb);
	s->type = GenericNULL(Type);
	
	return (TRUE);
}

#endif                               /* newconst */
/* #SP: 11/10/99 (end) */

static void libproc(s)

/*      liberation de la table des procedures
 *      en commencant par celle pointee par s
 */
TabProc *s;
{                               /* libproc */

	if (s->g != GenericNULL(TabProc))
		libproc(s->g);
	if (s->d != GenericNULL(TabProc))
		libproc(s->d);

	libref(s->lref);

	if (s->adta != GenericNULL(BYTE))
		Free_BYTE(s->adta);
	Free_Proc(s);
}                               /* libproc */


/* #IJM 02/10/2002
 *	This function has been implemented to check the procedure table
 *	to be sure that all FORWARD procedures have been instanced if they 
 *	have been accessed ! The consequences of the previous laxist 
 *	attitude is unpredictable and beyond belief.
 */
static int  chkproc(s)

TabProc *s;
{                               /* libproc */
	int	nombre=0;

	if (s->g != GenericNULL(TabProc)) 
		nombre += chkproc(s->g);

	if (s->d != GenericNULL(TabProc))
		nombre += chkproc(s->d);

	if ((s->forward) && (!(s->implemented)))
	{
		BOOL	nowarn_sav = nowarn;
		/* On considère que c'est une erreur.
		err2(USUAL,ersynt17,s->pid);
		nombre++;
		*/
		/* On considère que c'est un warning forcé. */
		nowarn = FALSE;
		err2(WARNING,ersynt17,s->pid);
		nowarn = nowarn_sav;
	}

	return( nombre );

}                               /* chkproc */


/* #IJM 02/10/2002
 *	C H E C K  F O R W A R D ( ) 
 *	----------------------------
 *	Called from programme() and module() prior to flushing
 *	the procedure table to disk to ensure that all used 
 *	forward preocedures have in fact been instanced.
 */
int	checkforward()
{
	if (deb_tproc != GenericNULL(TabProc))
		return( chkproc( deb_tproc ) );
	else
		return( 0 );
}


static void libseg(s)

/*      liberation de la table des segments
 *      en commencant par celle pointee par s
 */
TabSeg *s;
{                               /* libseg */
TabSeg *q;

	while (s != GenericNULL(TabSeg)) {
		if ( s->fwd == TRUE ) {
			err2(USUAL,ersynt3,s->nom);
		}
		q = s->suiv;
		libref(s->lref);
		Free_Tseg(s);
		s = q;
	}
}                               /* libseg */


static void libetiq(s)

/*      liberation de la table des etiquettes
 *      en commencant par celle pointee par s
 */
TabEtiq *s;
{                               /* libetiq */
	TabEtiq *p,*q,*x,*r;

	p = s; q = s->g; s->pid[0] = (char) 0x00FF;
	if (q == GenericNULL(TabEtiq)) {
		q = s->d;
		if (q == GenericNULL(TabEtiq)) {
			Free_Etiq(s); return;
		}
	}
	/* liberation des ss-arbres a partir du noeud courant */
	while (TRUE) {  /* sortie par BREAK */
	   if ((q->g != GenericNULL(TabEtiq))&&(q->pid[0] != (char) 0x00FF)) {
		/* traiter le ss-arbre gauche */
		q->pid[0] = (char) 0x00FF; x = q->g;
		q->g = p; p = q; q = x;
	   }
	   else {       /* traiter l'eventuel ss-arbre droite */
		if (q->d != GenericNULL(TabEtiq)) {
			/* il y en a un !! */
			if (q->pid[0] != (char) 0x00FF) {
				/* maintenir le chainage */
				q->pid[0] = (char) 0x00FF; q->g = p;
			}
			x = q->d; q->d = GenericNULL(TabEtiq);
			p = q; q = x;
		}
		else { /* ni gauche ni droite : supprimer cette feuille */
			if (q == s) break;      /* sauf si racine : out ... */
			Free_Etiq(q);
			r = q;
			/* et remonter a son pere pour la suite */
			q = p; p = q->g;
			/* et detruire le lien vers la feuille supprimee */
			if (r == q->d)
				q->d = GenericNULL(TabEtiq);
		}
	   }
	}
	/* fin de l'arbre : on est revenu au noeud initial */
	Free_Etiq(s);
}                               /* libetiq */


static void libnoeud(s)

/*      liberation de la table des symboles au niveau local
 *      en commencant par le symbole pointe par s
 *
 *		Modifications :
 *			A partir de la 2.2a, liberation du type
 */
TabSymb *s;
{                               /* libnoeud */

if (s) {

	if (s->g != GenericNULL(TabSymb))
		libnoeud(s->g);
	if (s->d != GenericNULL(TabSymb))
		libnoeud(s->d);
	if ((s->opt & (BYTE) OPT_USE) != 0)
		if (s->adsloc != 0xFFFF) //SG111197
		err2(WARNING,ersymb7,s->pid);
		else
		err2(WARNING,ersymb9, s->pid);
	libref(s->lref);

	/* A partir de la 2.2a, une structure Type peut etre rattachee */
	if (s->type != GenericNULL(Type))
		Free_Type(s->type);
	Free_Symb(s);
}
}                               /* libnoeud */


static void libtabref(p)

/*      liberation d'une table de reference
 */
RelRef *p;
{                               /* libtabref */
	RelRef  *q;

	while (p != GenericNULL(RelRef)) {
		q = p->suiv;
		libref(p->lref);
		Free_Lref(p); p = q;
	}

}                               /* libtabref */


static void libref(r)

/*      liberation d'une table de reference
 */
ExtRef *r;
{                               /* libref */
ExtRef *s;

	while (r != GenericNULL(ExtRef)) {
		s = r->suiv;
		Free_Ref(r); r = s;
	}
}                               /* libref */


void librlien()

/*      Libere la liste des liens d'une procedure d'un module
 *      avec les procedures qu'elle appelle.
 */

{                                               /* librlien */
	LienRef *lien,*olien;

	lien = lienc;                   /* debute a la liste en cours */

	while (lien != GenericNULL(LienRef)) {
		olien = lien->suiv;
		Free_LienR(lien);       /* libere le lien courant */
		lien = olien;           /* et passe au suivant */
	}

	lienc = GenericNULL(LienRef);   /* detruit la liste en cours */
}                                               /* librlien */


static void libfusr()

/*      Liberation des tables relatives aux fonctions utilisateur
 */

{                                       /* libfusr */
	TabRt   *s,*so;
	TabuRef *t,*to;

	/* liberer la table des run-times */
	s = RacTabRt;
	while (s != GenericNULL(TabRt)) {
		so = s->suiv;
		Free_TabRt(s);
		s = so;
	}

	/* liberer la table de relogeabilite */
	t = TusrRef;
	while (t != GenericNULL(TabuRef)) {
		to = t->suiv;
		Free_TabuRef(t);
		t = to;
	}

	/* liberer la table des fonctions utilisateur */
	if (RacTbusr != GenericNULL(Tbusr))
		libnfusr(RacTbusr);
}                                       /* libfusr */


static void libnfusr(noeud)

/*      Libere un noeud de la table des fonctions utilisateur
 *      on utilise un algorithme recursif
 */

Tbusr   *noeud;
{                                       /* libnfusr */
	if (noeud->g != GenericNULL(Tbusr))
		libnfusr(noeud->g);
	if (noeud->d != GenericNULL(Tbusr))
		libnfusr(noeud->d);

	if (noeud->typa != GenericNULL(BYTE))
		Free_BYTE(noeud->typa);
	if (noeud->moda != GenericNULL(BOOL))
		Free_BOOL(noeud->moda);
	Free_Tbusr(noeud);
}                                       /* libnfusr */


BOOL inmod(nmod)
BINAIRE *nmod;
{                                       /* inmod */
	*nmod=0xFFFF;
	if ( usc.code == IN_KEYWORD ) {
		lexical();
		if ( (usc.code == ANY) ) {
			lexical();
		} else {
			if ( (usc.code == IDENT) || (usc.code ==CSTR) ) {
				BYTE *pt;
				/* mise en maj */
				pt = usc.v.pval;
				while ( *pt != '\0' ) {
					*pt=toupper(*pt);
					pt++;
				}
				if ( usc.code == CSTR ) {
					/* sauvegarde du nom de module */
					*nmod = findmod(usc.v.pval);
					/* creation de la constante associee */
					if ( ! newconst(TRUE,usc.v.pval,*nmod) ) {
					}
					lexical();
				} else {
					BYTE *a;
					BINAIRE v;
					if ( findcst(usc.v.pval,&a,&v) == 1 ) {
						*nmod = v;
					} else {
						/* creation de la constante associee */
						*nmod = findmod(usc.v.pval);
						if ( ! newconst(TRUE,usc.v.pval,*nmod) ) {
							erreur(USUAL,ersynt4); sfdln();
							return(FALSE);
						}
					}
					lexical();
				}
			} else {
				erreur(USUAL,ersynt4); sfdln();
				return(FALSE);
			}
		}
	} else {
		if ( usc.code != FDLN ) {
			erreur(USUAL,ersynt4); sfdln();
			return(FALSE);
		}
	}
	return(TRUE);
}                                       /* inmod */


BOOL extfldm(ptadesc,ptadvar)
BYTE **ptadesc;
BINAIRE *ptadvar;
{                                       /* extfldm */
BOOL ret=TRUE;
char tmem;
BINAIRE nmod;
char *nom;


	/* Debut d'un nouveau champ externe : remise ... NULL de ptancr */
	ptancr = GenericNULL(LstAncr);

	*ptadesc = GenericNULL(BYTE);
	*ptadvar = 0;
	if (usc.code == EGAL) {
		lexical();
		if ((usc.code == IDENT) && (Xstrlen(usc.v.pval) == 1) &&
		    ((*usc.v.pval == 'M') || (*usc.v.pval == 'E') || (*usc.v.pval == 'A')) ) {
			tmem = *usc.v.pval;
			switch ( tmem ) {
				case 'A':
				case 'M':
					declext = 0;
					break;
				case 'E':
					declext = MEMEXT;
					break;
			}
			lexical();
			if ( usc.code == VIG ) {
				/* Redeclaration de zone */
				lexical();
				if (usc.code == IDENT) {
					*ptadesc = findvar(usc.v.pval,GenericNULL(BYTE),ptadvar,GenericNULL(TabSymb *),TRUE);
					if ( *ptadesc == GenericNULL(BYTE) ) {
						erreur(USUAL,ersynt4); sfdln();
						ret=FALSE;
					} else {
						nom = Xmalloc(Xstrlen(usc.v.pval)+1);
						Xstrcpy(nom,usc.v.pval);
						lexical();
						/* creation de l'ancrage redef */
						/* a voir... */
						/* l'adresse d'implantation de la variable utile */
						/* Mode recouvrement */
						/* Memoire etendue / Memoire standard */
						/* Attention verifier pas en local !!! */
						if ( inmod(&nmod) == TRUE ) {
							DCLInfo dcl;
							tmem |= 0x80; /* mode recouvrement */
							dcl.adrdesc = *ptadvar;
							GetDCLTable(&dcl);
							ptancr = insptancr(nmod,nom,tmem,dcl.adrvar);
							if ( ptancr == GenericNULL(LstAncr) ) {
								erreur(USUAL,ersynt4); sfdln();
								ret=FALSE;
							} else {
								adrbaseextcr = ptancr->ads;
								modextcr = ptancr->mod;
								if ( usc.code != FDLN )
									erreur(USUAL,ersynt4);
								sfdln();
							}
						} else {
							Xfree(nom);
						}
					}
				} else {
					if (usc.code == ETIQ) {
					/* recherche du point d'ancrage */
						ptancr = findptancr(0,usc.v.pval,tmem);
						if ( ptancr == GenericNULL(LstAncr) ) {
							erreur(USUAL,ersynt4); sfdln();
							ret=FALSE;
						} else {
							adrbaseextcr = ptancr->ads;
							modextcr = ptancr->mod;
							sfdln();
						}
					} else {
						erreur(USUAL,ersynt4); sfdln();
						ret=FALSE;
					}
				}
			} else {
				/* cas des extern field */
				if ( inmod(&nmod) == TRUE ) {
					modextcr=nmod;
					/* 1er cas : EXTERN FIELD= [ M | E | * ] */
					/* Module : ANY, Ref : NO */
					nom = Xmalloc(1);
					*nom='\0';
					ptancr = insptancr(modextcr,nom,(char)(tmem | SECOND_INDEX),adrbaseextcr);
					if ( ptancr == GenericNULL(LstAncr) ) {
						erreur(USUAL,ersynt4);
						ret = FALSE;
					}
					if ( usc.code != FDLN )
						erreur(USUAL,ersynt4);
					sfdln();
				}
			}
		} else {
			erreur(USUAL,ersynt4); sfdln();
			ret = FALSE;
		}
	} else {
		erreur(USUAL,ersynt4); sfdln();
		ret=FALSE;
	}
	return(ret);
}                                       /* extfldm */


BOOL newextfld()
{                                       /* newextfld */
BYTE *adesc;
BINAIRE advar;

	/* Initialisations */   
	adrbaseextcr = 0xFFFFFFFF;
	modextcr = 0xFFFF;

	return( extfldm(&adesc,&advar) );
}                                       /* newextfld */

/*
Penser a modifier :
	EXTERN FIELD=M,&toto !!!
	M et E dans extfld !!!!
	init des var;
	...
*/

BOOL newetiqvar()
{                       /* newetiqvar */
char tmem;
char *nom;
long adrmem;

	/* Recopie du nom de l'etiquette */
	if ( (nom=Xmalloc(Xstrlen(usc.v.pval)+1)) == GenericNULL(char) )
		erreur(FATALE,errmem);
	Xstrcpy(nom,usc.v.pval);

	lexical();
	if (usc.code == EGAL) {
		lexical();

		if ((usc.code == IDENT) && (Xstrlen(usc.v.pval) == 1) &&
		    ((*usc.v.pval == 'M') || (*usc.v.pval == 'E'))) {
			tmem = *usc.v.pval;             
			if ( ((tmem == 'M') && (declext == 0)) ||
			     ((tmem == 'E') && (declext == MEMEXT)) ) {
				adrmem = (long) adrimpl; 
			}
			else goto errfld;
			memolex();
			lexical();
			if ( usc.code == DCL ) 
				resumelex();
			else
				standardlex();      
			return(insetiqvar(nom,tmem,adrmem));
		}
	}
errfld:         /* erreur de declaration */
	erreur(USUAL,ersymb1);
	sfdln();
	return(FALSE);
}                       /* newetiqvar */


BOOL insetiqvar(n,t,a)
char *n;
char t;
long a;
{                       /* insetiqvar */
LstEtiqvar *s;

	s = deb_tetiqvar;
	while (s != GenericNULL(LstEtiqvar)) {
		if ( Xstrcmp(n,s->nom) == 0 ) {
			Xfree(n);
			erreur(USUAL,ersymb1);
			return(FALSE);
		} else {
			s = s->suiv;
		}
	}

	/* Allouer ce nouvelle etiquette */
	s = All_Etiqvar();              /* alloc nouvelle etiquette */
	if (s == GenericNULL(LstEtiqvar)) {     /* mais debordement memoire */
		Xfree(n);
		erreur(FATALE,errmem);
	}

	/* recopie de la nouvelle etiquette */
	s->nom = n;
	s->type = t;
	s->adr = a;

	/* insertion dans la liste en tete */
	s->suiv = deb_tetiqvar;
	deb_tetiqvar = s;
	nbetiqvar++;

	return (TRUE);
}                       /* insetiqvar */


void libetiqvar(void)
{                       /* libetiqvar */
LstEtiqvar *p2;
		p2 = deb_tetiqvar;
		while (p2 != GenericNULL(LstEtiqvar)) {
			deb_tetiqvar = p2->suiv;
			Xfree(p2->nom);
			Free_Etiqvar(p2);
			p2 = deb_tetiqvar;
		}
}                       /* libetiqvar */


BOOL newptancr()
{                       /* newptancr */
char tmem;
char *nom;
long adrmem;
BINAIRE nmod=0xFFFF;

	/* Recopie du nom du point d'ancrage */
	if ( (nom=Xmalloc(Xstrlen(usc.v.pval)+1)) == GenericNULL(char) )
		erreur(FATALE,errmem);
	Xstrcpy(nom,usc.v.pval);

	lexical();
	if (usc.code == EGAL) {
		lexical();

		if ((usc.code == IDENT) && (Xstrlen(usc.v.pval) == 1) &&
		((*usc.v.pval == 'M') || (*usc.v.pval == 'E'))) {
			tmem = *usc.v.pval;             
			if ( ((tmem == 'M') && (declext == 0)) ||
			     ((tmem == 'E') && (declext == MEMEXT)) ) {
				adrmem = (long) adrimpl;
			}
			else goto errfld;
			lexical();
			if ( inmod(&nmod) == TRUE ) {
				if ( usc.code != FDLN )
						erreur(USUAL,ersynt4);
				/* Maj du module */
				sfdln();
			}
			if ( insptancr(nmod,nom,tmem,adrmem) == GenericNULL(LstAncr) )
				return(FALSE);
			else
				return(TRUE);
		}
	}
errfld:         /* erreur de declaration */
	erreur(USUAL,ersymb1);
	sfdln();
	return(FALSE);
}                       /* newptancr */


LstAncr *findptancr(m,n,t)
BINAIRE m;
char *n;
char t;
{                       /* findptancr */
LstAncr *s;
BOOL testmodule;

	testmodule = (t & 0x80 ? TRUE : FALSE);

	s = deb_tptancr;
	while (s != GenericNULL(LstAncr)) {
		/* Cle : TYPE + MOD + REF */
		if ( (t == s->type) && (testmodule ? (m == s->mod) : TRUE) && (Xstrcmp(n,s->nom) == 0) ) {
			return(s);
		} else {
			s = s->suiv;
		}
	}
	return(s);
}                       /* findptancr */


LstAncr *insptancr(m,n,t,a)
BINAIRE m;
char *n;
char t;
long a;
{                       /* insptancr */
LstAncr *s;

	s = deb_tptancr;
	while (s != GenericNULL(LstAncr)) {
		/* Cle : TYPE + MOD + REF */
		if ( (t == s->type) && (m == s->mod) && (Xstrcmp(n,s->nom) == 0) ) {
		/* l'extern field existe deja : 23/11/94 */
		/* plus d'erreur mais utilisation de l'extern field trouve */
			Xfree(n);
			return(s);
		} else {
			s = s->suiv;
		}
	}

	/* Allouer ce nouveau ancrage */
	s = All_Ancr();         /* alloc nouveau ancrage */
	if (s == GenericNULL(LstAncr)) {        /* mais debordement memoire */
		Xfree(n);
		erreur(FATALE,errmem);
	}

	/* recopie de la nouveau ancrage */
	s->mod = m;
	s->nom = n;
	s->type = t;
	s->ads = a;
	s->nbxvar = 0;
	s->adrxvar = 0;
	s->xvar = GenericNULL(LstXvar);

	/* insertion dans la liste en tete */
	s->suiv = deb_tptancr;
	deb_tptancr = s;
	nbptancr++;

	return (s);
}                       /* insptancr */


void libptancr(void)
{                       /* libptancr */
LstAncr *p2;
LstXvar *x2;
	p2 = deb_tptancr;
	while (p2 != GenericNULL(LstAncr)) {
		deb_tptancr = p2->suiv;
		Xfree(p2->nom);
		while ( p2->xvar != GenericNULL(LstXvar) ) {
			x2 = p2->xvar->suiv;
			Free_Xvar(p2->xvar);
			p2->xvar = x2;
		}       
		Free_Ancr(p2);
		p2 = deb_tptancr;
	}
}                       /* libptancr */


BOOL insxvar(pa,xv)
LstAncr *pa;
TabSymb *xv;
{                       /* insxvar */
LstXvar *s;

	/* Allouer cette nouvelle var externe */
	s = All_Xvar();         /* alloc nouvelle var ext */
	if (s == GenericNULL(LstXvar))  /* mais debordement memoire */
		erreur(FATALE,errmem);

	/* recopie de la nouvelle variable externe */
	s->info = xv;

	/* insertion dans la liste en tete */
	s->suiv = pa->xvar;
	pa->xvar = s;
	pa->nbxvar++;

	return(TRUE);
}                       /* insxvar */


static void initextref()
{                       /* initextref */
int i;
	for (i=0; i<HASHCODE; i++)
		hlstextref[i] = GenericNULL(RelRef);

}                       /* initextref */


static void createextref(ads,ptref)
BINAIRE ads;
ExtRef **ptref;
{                       /* createextref */
BINAIRE hc;
RelRef *pt;
	hc = EvalHC(ads);
	if ( (pt = All_Lref()) == GenericNULL(RelRef) )
		erreur(FATALE,errmem);
	pt->ads = ads;

	/* Allocation de la tete fixe */
	if ( (pt->lref = All_Ref()) == GenericNULL(ExtRef) )
		erreur(FATALE,errmem);
	pt->lref->bloc = 0xFFFF;
	pt->lref->ofst = 0xFFFF;
	pt->lref->suiv = GenericNULL(ExtRef);
	
	/* Chainage */
	pt->suiv = hlstextref[hc];
	hlstextref[hc] = pt;

	*ptref = pt->lref;
 
}                       /* createextref */


static void insextref(ads,bloc,offset)
BINAIRE ads,bloc,offset;
{                       /* insextref */
BINAIRE hc;
RelRef *ptl;
ExtRef *pt;
	hc = EvalHC(ads);
	ptl = hlstextref[hc];
	while ( ptl != GenericNULL(RelRef) ) {
		if ( ptl->ads == ads )
			break;
		ptl = ptl->suiv;
	}
	/* Allocation de la nouvelle ref */
	if ( (pt = All_Ref()) == GenericNULL(ExtRef) )
		erreur(FATALE,errmem);
	pt->bloc = bloc;
	pt->ofst = offset;

	/* Chainage en 2eme position */
	pt->suiv = ptl->lref->suiv;
	ptl->lref->suiv = pt;
		
}                       /* insextref */


static void libextref()
{                       /* libextref */
RelRef *pt;
int i;
	for ( i=0; i<HASHCODE; i++) {
		while ( hlstextref[i] != GenericNULL(RelRef) ) {
			pt = hlstextref[i]->suiv;
			Free_Lref(hlstextref[i]);
			hlstextref[i]=pt;
		}
	}       
}                       /* libextref */


BOOL createEmptyStructure (void)
{
	Type				*type;
	TabSymb				*pTabSymb;


	/* On crée une structure vide avec un paramètre*/

	type = All_Type();
	if (type == GenericNULL(Type))
			erreur(FATALE,errmem);
		else {
			type->type = TSTR;
			type->l = 1;
			type->d1 = 0;
			type->d2 = 0;
			type->pasptr = 1;
			type->pStruct = GenericNULL(TabStruct);
		}

	
			if (!newvar(&pTabSymb, 0, FALSE, "FILLEMPTYSTRUCT", FALSE, TRUE, TRUE, type, optimise_tables))
				erreur(USUAL, ersymb2);

	return TRUE;

}
