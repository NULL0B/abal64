/*
 *      Projet  : ABAL                  Copyright Amenesik / Sologic s.a. (c) 1990, 1996
 *      Module  : ATR
 *      Fichier : IOFNT.C
 *      Version : 2.1f
 *      Date    : 23/02/96
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Traitement des instructions avec numero logique]
 *
 */

 /*
 * Mises a jour :
 * ------------
 * 03/09/90 : Mise en conformite avec les versions 1.2e / 1.3a / 1.4a
 * 26/02/91 : Invalide les informations Erreur,Buffer en cas d'assign
 *            autre que MC ou IM.
 * 27/03/91 : Reautorise l'information Erreur dans tous les assign.
 * 12/08/92 : Insertion de l'instruction NGF NAME version 15
 *	------------- 2.1c ----------------------------------------------
 *	03/06/94 : Mauvaise longueur de la zone d'echange si pointeur finio(...)
 *	------------ 2.1d -------------------------------------------------
 *	22/11/95 : version dediee 2.1
 *	23/02/96 : correction NAME sans longueur de buffer
 *	------------ 2.2a -------------------------------------------------
 * 07/03/97 : Prototype de findvar() modifie, reprise de tous les appels
 * -------------------------------------------------------------------------
 * 29/02/00 : (#AT) Amelioration EXA-57 - LOAD.GO modifications for ABAL v.2.2a
 * -------------------------------------------------------------------------
 * 17/08/00 : (#SP) Criteria long names support.
 * 08/03/01 : (#BG) Suppression d'une erreur anormale si le paramètre du LoadGo est un retour de fonction.
 *	------------ 2.2b -------------------------------------------------
 * 31/10/02 : (#OK) Bug in function "load.go=1, retVal, cmd" fixed.
 */

/* Fichier de definition */
/* --------------------- */

#include "tr.h"
#include "fuser.h"
#include "syntaxe.h"
#include "tsymb.h"
#include "tcode.h"
#include "codes.h"

#define _IOFNT
#include "iofnt.hs"
#include "iofnt.he"

void passign()

/*      traduction de l'instruction ASSIGN
 *
 *      syntaxe : ASSIGN = nl , nom [ , opt ] [ : erreur ]
 *      ou      : ASSIGN = nl , nom [ , opt ] : [ erreur , ] buf [ , lgbuf ]
 *      avec comme varg[3] 'opt' : SQ SI MC DB GR IM WR EX DF C IPC WO
 *      la deuxieme syntaxe n'etant possible que pour IM, MC, BD et IPC.
 *
 *	ver15 : 
 *		ASSIGN = nl , nom [ , word ] ....
 *		word contient toutes les options de l'assign
 */
{                                               /* passign */
	BYTE *adesc;
	BINAIRE advar;
        BYTE    typ;
        int     flgbuf = 0;     /* pas de zone d'echange a priori */

        flg_bufexpr = FALSE;    /* buffer doit etre une variable */

        lexical();      /* avaler le mot-cle */
        if (!recnumlog())       /* recup du numero logique concerne */
                return;
        if (usc.code != VIG) {  /* syntaxe ',' attendue et non trouvee */
                erreur(USUAL,eriof4); sfdln(); return;
        }
        lexical();
        typ = TSTR;             /* recup du nom du fichier */
        if (!expression(&typ,&targ[2],&varg[2])) {
                sfdln(); return;
        }
        targ[3] = 0;            /* les options sont une valeur immediate */
        varg[3] = DR_OPT;       /* acces direct a priori */
        while (usc.code == VIG) {       /* traiter les options */
                lexical();
                if (usc.code != IDENT) {
                        erreur(USUAL,eriof5); sfdln(); return;
                }
                if (strEq(usc.v.pval,"SQ"))             {
                        if ((varg[3] & MA_OPT) != 0) {
                                erreur(USUAL,eriof6); sfdln(); return;
                        }
                        varg[3] |= SQ_OPT;
                }
                else if (strEq(usc.v.pval,"SI"))        {
                        if ((varg[3] & MA_OPT) != 0) {
                                erreur(USUAL,eriof6); sfdln(); return;
                        }
                        varg[3] |= SI_OPT;
                }
                else if (strEq(usc.v.pval,"MC"))        {
                        if ((varg[3] & MA_OPT) != 0) {
                                erreur(USUAL,eriof6); sfdln(); return;
                        }
                        varg[3] |= MC_OPT; flgbuf = 2;
                }
                else if (strEq(usc.v.pval,"DB"))        {
                        if ((varg[3] & MA_OPT) != 0) {
                                erreur(USUAL,eriof6); sfdln(); return;
                        }
                        varg[3] |= DB_OPT; flgbuf = 2;
                }
                else if (strEq(usc.v.pval,"IM"))        {
                        if ((varg[3] & MA_OPT) != 0) {
                                erreur(USUAL,eriof6); sfdln(); return;
                        }
                        varg[3] |= IM_OPT; flgbuf = 2;
                }
                else if (strEq(usc.v.pval,"GR"))        {
                        if ((varg[3] & MA_OPT) != 0) {
                                erreur(USUAL,eriof6); sfdln(); return;
                        }
                        varg[3] |= GR_OPT;
                }
                else if (strEq(usc.v.pval,"DF"))        {
                        if ((((varg[3] & MA_OPT) != MC_OPT) &&
                             ((varg[3] & MA_OPT) != DB_OPT)) ||
                            ((varg[3] & DF_OPT) != 0)   ) {
                                erreur(USUAL,eriof6); sfdln(); return;
                        }
                        varg[3] |= DF_OPT;
                }
                else if (strEq(usc.v.pval,"C"))         {
                        if ((varg[3] & C_OPT) != 0) {
                                erreur(USUAL,eriof6); sfdln(); return;
                        }
                        varg[3] |= C_OPT;
                }
				/* #SP 17/08/2000 (begin) */
				else if (strEq(usc.v.pval,"L"))         {
                    if ((varg[3] & L_OPT) != 0) {
                            erreur(USUAL,eriof6); sfdln(); return;
                    }
                    varg[3] |= L_OPT;
            }
            /* #SP 17/08/2000 (end) */
                else if (strEq(usc.v.pval,"EX"))        {
                        if ((varg[3] & EX_OPT) != 0) {
                                erreur(USUAL,eriof6); sfdln(); return;
                        }
                        varg[3] |= EX_OPT;
                }
                else if (strEq(usc.v.pval,"WR"))        {
                        if ((varg[3] & WR_OPT) != 0) {
                                erreur(USUAL,eriof6); sfdln(); return;
                        }
                        varg[3] |= WR_OPT;
                }
                else if (strEq(usc.v.pval,"IPC"))       {
                        if ((varg[3] & MA_OPT) != 0) {
                                erreur(USUAL,eriof6); sfdln(); return;
                        }
                        varg[3] |= IPC_OPT;
                        flgbuf = 1;             /* buffer indispensable */
                        flg_bufexpr = TRUE;     /* buffer = expression */
                }
                else if (strEq(usc.v.pval,"WO"))        {
                        if ((varg[3] & (DF_OPT | WR_OPT)) != 0 ||
                            (varg[3] & MA_OPT) != 0) {
                                erreur(USUAL,eriof6); sfdln(); return;
                        }
                        varg[3] |= WR_OPT | DF_OPT;
                }
                else {
			/* Option WORD : nom de variable */
		        adesc = findvar(usc.v.pval,GenericNULL(BYTE),&advar,GenericNULL(TabSymb *),TRUE);
        		if (adesc == GenericNULL(char)) {
	                        erreur(USUAL,eriof5); sfdln(); return;
		        } else {
				/* Traitement a definir avec jamie */
				/* variable entiere */
				
                		if ( ! IS_TBIN2(typdesc(adesc)) ) {
		                        erreur(USUAL,eriof5); sfdln(); return;
				}
				targ[3] = 2;
	                        varg[3] = advar;
				lexical();
				break;
			}
               }
                lexical();
        }
        nbargs = 3;     /* 3 arguments jusqu'ici */
        if (!fininstio(flgbuf))
                return;

        /* Verifie que variable d'erreur et zone d'echange ne
         * s'appliquent qu'a des fichiers MC ou a des imprimantes.
         * Sinon, invalide ces informations.
         * NB: On laisse passer la syntaxe par souci de compatibilite
         * avec le BAL.
         */
        if (((varg[3] & MA_OPT) != MC_OPT) && ((varg[3] & MA_OPT) != IM_OPT)) {
                nbargs = 3;
/*              aderr = GenericNULL(char); */
        }

        /* generation du code */
        genngf(0,aderr,nbargs,0x00FF,targ,varg);
}                                               /* passign */

void pfile ()

/*      Traduction de l'instruction FILE
 */
{                                               /* pfile */
        BYTE    typ,tnlbd;
        BINAIRE vnlbd;

        flg_bufexpr = FALSE;    /* buffer doit etre une variable */

        lexical();      /* avaler le mot-cle */
        if (!recnumlog())       /* recup du numero logique concerne */
                return;
        if (usc.code != VIG) {  /* syntaxe ',' attendue et non trouvee */
                erreur(USUAL,eriof4); sfdln(); return;
        }
        lexical();
        typ = TSTR;             /* recup du nom du fichier */
        if (!expression(&typ,&targ[2],&varg[2])) {
                sfdln(); return;
        }
        targ[3] = 0;            /* option MC associe a une BD */
        varg[3] = MC_OPT | DB_OPT;
        if (usc.code != VIG) {  /* syntaxe ',' attendue et non trouvee */
                erreur(USUAL,eriof4); sfdln(); return;
        }
        lexical();
        if (usc.code != IDENT) {
                erreur(USUAL,eriof6); sfdln(); return;
        }
        if (!strEq(usc.v.pval,"MC")) {
                erreur(USUAL,eriof6); sfdln(); return;
        }
        lexical();
        if (usc.code != PAG) {
                erreur(USUAL,eriof11); sfdln(); return;
        }
        lexical();
        typ = TBIN;
        if (!expression(&typ,&tnlbd,&vnlbd)) {
                sfdln(); return;
        }
        if (IS_TSTR(typ)) {      /* chaine ne peut pas etre un numero logique */
                erreur(USUAL,eriof3); sfdln(); return;
        }
        if (usc.code != PAD) {
                erreur(USUAL,eriof12); sfdln(); return;
        }
        lexical();
        nbargs = 3;     /* 3 arguments jusqu'ici */
        if (!fininstio(2))      /* zone d'echange optionnelle */
                return;
        /* ajouter le numero logique de la base en fin des arguments */
        nbargs++; targ[nbargs] = tnlbd; varg[nbargs] = vnlbd;
        /* generation du code */
        genngf(18,aderr,nbargs,0x00FF,targ,varg);
}                                               /* pfile */

void pfind ()

/*      Traduction de l'instruction FIND
        ver15 : possibilite d'options cumulables ex : FDI
                1 parametre de plus a recopt indiquant le nombre
                maximum d'options
 */
{                                               /* pfind */
        lexical();      /* avaler le mot-cle */
        if (!recnumlog())       /* recup du numero logique concerne */
                return;
        if (!recopt(&targ[2],&varg[2],0,"FNDI",3))
                return;
        nbargs = 2;
        if (!fininstio(1))      /* zone d'echange obligatoire */
                return;
        /* generation du code */
        genngf(54,aderr,nbargs,0x00FF,targ,varg);
}                                               /* pfind */

void pcfile ()

/*      Traduction de l'instruction CFILE
 *      l'octet 'options' est utilise pour le cas du CFILE etendu,
 *      avec la valeur : 0 pour longueur de donnees fixe, 1 pour variable,
 *      le cadrage s'ajoutant avec le masque 0x2 pour cadrage a gauche,
 *      ou le masque 0x6 pour cadrage a droite.
 */
{                                               /* pcfile */
        BYTE    typ;
        BOOL    datas0 = FALSE;

        lexical();      /* avaler le mot-cle */
        if (!recnumlog())       /* recup du numero logique concerne */
                return;
        options = 0;            /* pas d'option a priori */
        if (usc.code == VIG) {  /* CFILE etendu */
                lexical();
                if (usc.code != IDENT) {
                        erreur(USUAL,eriof6); sfdln(); return;
                }
                if (strEq(usc.v.pval,"D"))  {
                        lexical();
                        if (usc.code != EGAL) {
                                erreur(USUAL,eriof2); sfdln(); return;
                        }
                        lexical(); typ = TBIN;
                        if (!expression(&typ,&targ[2],&varg[2])) {
                                sfdln(); return;
                        }
                }
                else if (strEq(usc.v.pval,"VD")) {
                        options = 1;    /* longueur variable */
                        lexical();
                        if (usc.code == EGAL) {
                                lexical(); typ = TBIN;
                                if (!expression(&typ,&targ[2],&varg[2])) {
                                        sfdln(); return;
                                }
                        }
                        else { /* lg recuperation par defaut = 6 */
                                targ[2] = 0; varg[2] = 6;
                        }
                }
                else {
                        /* peut etre D=0 implicite ... */
                        if ((strEq(usc.v.pval,"K"))
                           || (strEq(usc.v.pval,"RK"))
                           || (strEq(usc.v.pval,"LK")) ) {
                                datas0 = TRUE; targ[2] = 0; varg[2] = 0;
                        }
                        else {
                                erreur(USUAL,eriof6); sfdln(); return;
                        }
                }
                if ((usc.code == VIG) || (datas0)) {
                        if (usc.code == VIG) {
                                lexical();
                                if (usc.code != IDENT) {
                                        erreur(USUAL,eriof6); sfdln(); return;
                                }
                        }
                        if (strEq(usc.v.pval,"LK"))
                                options |= 0x0002;      /* cadrage a gauche */
                        else if (strEq(usc.v.pval,"RK"))
                                options |= 0x0006;      /* cadrage a droite */
                        else if (!strEq(usc.v.pval,"K")) {
                                erreur(USUAL,eriof6); sfdln(); return;
                        }
                        lexical();
                        if (usc.code != EGAL) {
                                erreur(USUAL,eriof2); sfdln(); return;
                        }
                        lexical(); typ = TBIN;
                        if (!expression(&typ,&targ[3],&varg[3])) {
                                sfdln(); return;
                        }
                        nbargs = 3;
                }
                else {
                        if (options == 1) { /* lg variable -> lg cles */
                                erreur(USUAL,eriof6); sfdln(); return;
                        }
                        nbargs = 2;
                }
        }
        else
                nbargs = 1;
        if (!fininstio(0))      /* pas de zone d'echange */
                return;
        genngf(5,aderr,nbargs,options,targ,varg);
}                                               /* pcfile */

void pdfile ()

/*      Traduction de l'instruction CFILE
 *      l'octet 'options' est utilise de la maniere suivante :
 *      0: fichier direct ou SQ, 1: option SI, 2: option MC
 *      3: options MC + SI.
 */
{                                               /* pdfile */
        lexical();      /* avaler le mot-cle */
        if (!recnumlog())       /* recup du numero logique concerne */
                return;
        options = 0;            /* pas d'option a priori */
        if (usc.code == VIG) {  /* DFILE etendu */
                lexical();
                if (usc.code != PAG) {
                        erreur(USUAL,eriof11); sfdln(); return;
                }
                lexical();
                if (usc.code != IDENT) {
                        erreur(USUAL,eriof6); sfdln(); return;
                }
                if (strEq(usc.v.pval,"MC"))
                        options = 1;
                else if (strEq(usc.v.pval,"SI"))
                        options = 2;
                else {
                        erreur(USUAL,eriof6); sfdln(); return;
                }
                lexical();
                if (usc.code != PAD) {
                        erreur(USUAL,eriof12); sfdln(); return;
                }
                lexical();
                if (usc.code == VIG) {
                        lexical();
                        if (usc.code != PAG) {
                                erreur(USUAL,eriof11); sfdln(); return;
                        }
                        lexical();
                        if (usc.code != IDENT) {
                                erreur(USUAL,eriof6); sfdln(); return;
                        }
                        if (strEq(usc.v.pval,"MC")) {
                                if (options == 2) {
                                        erreur(USUAL,eriof6); sfdln(); return;
                                }
                        }
                        else if (strEq(usc.v.pval,"SI")) {
                                if (options == 1) {
                                        erreur(USUAL,eriof6); sfdln(); return;
                                }
                        }
                        else {
                                erreur(USUAL,eriof6); sfdln(); return;
                        }
                        options = 3;
                        lexical();
                        if (usc.code != PAD) {
                                erreur(USUAL,eriof12); sfdln(); return;
                        }
                        lexical();
                }
        }
        if (!fininstio(0))      /* pas de zone d'echange */
                return;
        genngf(14,aderr,1,options,targ,varg);
}                                               /* pdfile */

void prename ()

/*      Traduction de l'instruction RENAME
 */
{                                               /* prename */
        BYTE    typ;

        lexical();      /* avaler le mot-cle */
        if (!recnumlog())       /* recup du numero logique concerne */
                return;
        if (usc.code != VIG) {  /* syntaxe ',' attendue et non trouvee */
                erreur(USUAL,eriof4); sfdln(); return;
        }
        lexical();
        typ = TSTR;             /* recup du nom du fichier */
        if (!expression(&typ,&targ[2],&varg[2])) {
                sfdln(); return;
        }
        if (!fininstio(0))      /* pas de zone d'echange */
                return;
        genngf(43,aderr,2,0x00FF,targ,varg);
}                                               /* prename */

void patb ()

/*      Traduction de l'instruction ATB
 *      l'octet 'options' est utilise de la maniere suivante :
 *      bit 0 : option EX oui/non, bit 1 : option C oui/non
 */
{                                               /* patb */
        lexical();      /* avaler le mot-cle */
        if (!recnumlog())       /* recup du numero logique concerne */
                return;
        options = 0;            /* pas d'option a priori */
        if (usc.code == VIG) {
                lexical();
                if (usc.code != IDENT) {
                        erreur(USUAL,eriof6); sfdln(); return;
                }
                if (strEq(usc.v.pval,"EX"))
                        options = 1;
                else if (strEq(usc.v.pval,"C"))
                        options = 2;
                else {
                        erreur(USUAL,eriof6); sfdln(); return;
                }
                lexical();
                if (usc.code == VIG) {
                        lexical();
                        if (usc.code != IDENT) {
                                erreur(USUAL,eriof6); sfdln(); return;
                        }
                        if (strEq(usc.v.pval,"EX")) {
                                if (options == 1) {
                                        erreur(USUAL,eriof6); sfdln(); return;
                                }
                        }
                        else if (strEq(usc.v.pval,"C")) {
                                if (options == 2) {
                                        erreur(USUAL,eriof6); sfdln(); return;
                                }
                        }
                        else {
                                erreur(USUAL,eriof6); sfdln(); return;
                        }
                        options = 3;
                        lexical();
                }
        }
        if (!fininstio(0))      /* pas de zone d'echange */
                return;
        genngf(2,aderr,1,options,targ,varg);
}                                               /* patb */

void pextend ()

/*      Traduction de l'instruction EXTEND
 */
{                                               /* pextend */
        BYTE    typ;

        lexical();      /* avaler le mot-cle */
        if (!recnumlog())       /* recup du numero logique concerne */
                return;
        if (usc.code != VIG) {  /* extension de 1 secteur par defaut */
                targ[2] = 0; varg[2] = 1;
        }
        else {
                lexical();
                typ = TBIN;             /* recup du nombre de secteurs */
                if (!expression(&typ,&targ[2],&varg[2])) {
                        sfdln(); return;
                }
        }
        if (!fininstio(0))      /* pas de zone d'echange */
                return;
        genngf(17,aderr,2,0x00FF,targ,varg);
}                                               /* pextend */

/*--------------------------------------------------------------*/
/*                                                              */
/*      Enchainements et appels entre programmes                */
/*                                                              */
/*--------------------------------------------------------------*/
/* #AT: 29/02/00, EXA-57 (begin)*/
#ifdef __ATR22__
#define  R_OPTION       0x1
#define  VAR_OPTION     0x2
#define  PARAMS_OPTION  0x4
//////////////////////////
int SetError(int iErrNumb)
{
  erreur(USUAL,iErrNumb); sfdln(); return 0;
}
///////////////////////////////////////////
int TreatOptionR(int isLoadGo,int * iFlags)
/* Treat (R) option. It returns 0 if were some errors or 1 otherwise.
*/
{
  if (!isLoadGo || *iFlags & R_OPTION) return SetError(eriof6);
  *iFlags |= R_OPTION;
  lexical();
  if (usc.code != IDENT) return SetError(eriof6);
  if (strEq(usc.v.pval,"R")){
    if (options == 1) return SetError(eriof6);
    options = 1;
  }
  else return SetError(eriof6);
  lexical();
  if (usc.code != PAD) return SetError(eriof12);
  lexical();
  return 1;
}
//////////////////////////////////////
int VarInt8(int isLoadGo,int * iFlags)
{
  if (!isLoadGo || *iFlags & VAR_OPTION) return SetError(eriof6);
  *iFlags |= VAR_OPTION;
  lexical();
  return 1;
}
////////////////////////
int VarStr(int * iFlags)
{
  if (*iFlags & PARAMS_OPTION) return SetError(eriof6);
  *iFlags |= PARAMS_OPTION;
  nbargs = 2;
  return 1;
}
/*
/////////////////////////////////////////////////////////////////
int TreatOptionResult(int isLoadGo,int * iFlags,BINAIRE * iDescr)
// Treat 'var' option. It returns 0 if were some errors or 1 otherwise.
{
  BYTE * pbDescr;
//  BINAIRE iDescr;
//  lexical();
  if (!(pbDescr=findvar(usc.v.pval,GenericNULL(BYTE),iDescr,GenericNULL(TabSymb *),TRUE)))
    return SetError(eriof6);
  switch (*pbDescr){
  case TBIN1: if (!VarInt8(isLoadGo,iFlags)) return 0; break;
  case TSTR:  if (!VarStr(iFlags)) return 0; break;
  default: return SetError(eriof3); // It's valid only for INT8 and STR type
  };
  lexical();
  return 1;
}
*/
/////////////////////////////////////////////////////////////////
int TreatOptionResult(int isLoadGo,int * iFlags,BINAIRE * iDescr)
// Treat 'var' option. Returns 0 if errors or 1 otherwise.
{
	BYTE * pbDescr;
	BYTE typ = TSTR;

	if (usc.code == IDENT)
	{
		pbDescr = findvar(usc.v.pval, GenericNULL(BYTE), iDescr, GenericNULL(TabSymb *), TRUE);
/* #BG 08/03/01 Begin */
		if (!pbDescr)
	        pbDescr = findproc(0, usc.v.pval);
/* #BG 08/03/01 End */

		if (!pbDescr)
			return 0;
		else if ((*pbDescr) == TBIN1)
			return VarInt8(isLoadGo, iFlags);
	}

	if (expression(&typ, &targ[2], &varg[2]))
		return VarStr(iFlags); 

	sfdln(); 
	return 0;
}
///////////////////////////////////
int TreatLoadGoParams(int * iFlags)
/* Treat parameters of Load.Go's call. It returns 0 if were some errors or 1 otherwise.
*/
{
  BYTE typ = TSTR;
  if (*iFlags & PARAMS_OPTION) return SetError(eriof6);
  *iFlags |= PARAMS_OPTION;
  if (!expression(&typ,&targ[2],&varg[2])) {sfdln(); return 0;}
  nbargs = 2;
  return 1;
}
////////////////////////
void pldgo(int isLoadGo)
/* New version of pldgo: it treats CHAIN and LOAD.GO ABAL-instructions */
{
  BINAIRE iDescr     = 0;
  BINAIRE iDescrSave = 0;	/* #OK 31/10/02 */

  int iFlags = 0; /* 0x1: R-option; 0x2: 'var'-option; 0x4: call parameters */
  options = (isLoadGo) ? 0 : 0x00FF;
  lexical();
/* Treat logical number:*/
  if (!recnumlog()) return;
  nbargs = 1; /* Parameter is absent a priory */
/* Treat arguments of the instruction:*/
  for(;;){
    if (usc.code != VIG) break;
    lexical();
    switch(usc.code){
  /*(R):*/
    case PAG:   if (!TreatOptionR(isLoadGo,&iFlags)) return; break;
  /* Var for result returned by Load.Go: */  
//    case IDENT: if (!TreatOptionResult(isLoadGo,&iFlags,&iDescr)) return; break;
  /* Parameters of Load.Go's call: */  
    case CSTR:  if (!TreatLoadGoParams(&iFlags)) return; break;
    default:
 	  iDescrSave = iDescr;	/* #OK 31/10/02 */

      if (!TreatOptionResult(isLoadGo,&iFlags,&iDescr)){  
        SetError(eriof6); return;
      }
    };
  }

  /* #OK 31/10/02 (begin) */
  if (iDescrSave)
	  iDescr = iDescrSave; 
  /* #OK 31/10/02 (end) */

/* Treat the end of the instruction:*/
  if (!fininstio(0)) return; /* pas de zone d'echange */
/* Generate ILGR instruction */
  if (isLoadGo && iFlags & VAR_OPTION) genesc0(F_ILGR);
  genngf((isLoadGo) ? 31 : 6,aderr,nbargs,options,targ,varg);
/* Generate LLGR instruction */
  if (isLoadGo && iFlags & VAR_OPTION) {
  // If upper bit is set, it is a local var
    (iDescr & 0x8000) ? genesc0(F_LLGRL) : genesc0(F_LLGRG); 
    pbin(0,iDescr); adrimpl += 2L;
  }
}
#undef  PARAMS_OPTION
#undef  VAR_OPTION
#undef  R_OPTION
/* COMMENTED BY AT: 29/02/00, EXA-57 */
/*
void pldgo (tfn)

//      Traduction de l'instruction CHAIN ou LOAD.GO
//      suivant la valeur de 'tfn'.
//
int tfn;
{ //                                              pldgo 
        BYTE    typ;

        if (tfn == 31)  // LOAD.GO => il y a une option possible : (R)
                options = 0;    // a priori absente 
        else
                options = 0x00FF;
        lexical();      // avaler le mot-cle 
        if (!recnumlog())      // recup du numero logique concerne 
                return;
//        pas de parametre a priori 
        nbargs = 1;
        if (usc.code == VIG) {  // parametre present 
                lexical();
                if (usc.code == PAG) {  // option (R) ? 
trRopt:
                        if (tfn != 31) { // seulement pour LOAD.GO !! 
                                erreur(USUAL,eriof6); sfdln(); return;
                        }
                        lexical();
                        if (usc.code != IDENT) {
                                erreur(USUAL,eriof6); sfdln(); return;
                        }
                        if (strEq(usc.v.pval,"R")) {
                                if (options == 1) {
                                        erreur(USUAL,eriof6); sfdln(); return;
                                }
                                options = 1;
                        }
                        else {
                                erreur(USUAL,eriof6); sfdln(); return;
                        }
                        lexical();
                        if (usc.code != PAD) {
                                erreur(USUAL,eriof12); sfdln(); return;
                        }
                        lexical();
                }
                else {
                        typ = TSTR;             // recup du parametre
                        if (!expression(&typ,&targ[2],&varg[2])) {
                                sfdln(); return;
                        }
                        nbargs = 2;
                        if (usc.code == VIG) { // option (R) ? 
                                lexical();
                                if (usc.code == PAG) goto trRopt;
                                erreur(USUAL,eriof11); sfdln(); return;
                        }
                }
        }
        if (!fininstio(0))      // pas de zone d'echange 
                return;
        genngf(tfn,aderr,nbargs,options,targ,varg);
}                                               // pldgo
*/
#endif
/* #AT: 29/02/00, EXA-57 (end)*/


/*--------------------------------------------------------------*/
/*                                                              */
/*      Instructions specifiques de l'acces sequentiel indexe   */
/*                                                              */
/*--------------------------------------------------------------*/

void pupdwn (tfn)

/*      Traduction des instructions UP et DOWN
 */
int tfn;
{                                               /* pupdwn */
        BYTE    typ;

        flg_bufexpr = FALSE;    /* buffer doit etre une variable */

        lexical();      /* avaler le mot-cle */
        if (usc.code == SPT) {  /* option .ML ? */
                lexical();
                if (usc.code != IDENT) {
                        erreur(USUAL,eriof6); sfdln(); return;
                }
                if (strEq(usc.v.pval,"M"))       options = 0x10;
                else if (strEq(usc.v.pval,"L"))  options = 0x20;
                else if (strEq(usc.v.pval,"ML"))  options = 0x30;
                else if (strEq(usc.v.pval,"LM"))  options = 0x30;
                else {
                        erreur(USUAL,eriof6); sfdln(); return;
                }
                lexical();
        }
        else
                options = 0;
        if (!recnumlog())       /* recup du numero logique concerne */
                return;
        if (usc.code == VIG) {  /* marqueur explicite */
                lexical();
                typ = TBIN;
                if (!expression(&typ,&targ[2],&varg[2])) {
                        sfdln(); return;
                }
        }
        else {  /* marqueur par defaut = valeur immediate 1 */
                targ[2] = 0; varg[2] = 1;
        }
        nbargs = 2; options |= 0x02;
        if (!fininstio(2))      /* zone d'echange facultative */
                return;
        if (nbargs > 2) {       /* zone d'echange presente */
                if (flg_lgexpl) options |= 0x00C;
                else            options |= 0x004;
        }
        genngf(tfn,aderr,nbargs,options,targ,varg);
}                                               /* pupdwn */

void pmodif ()

/*      Traduction de l'instruction MODIF
 */
{                                               /* pmodif */
        BOOL    sq_modif = FALSE;       /* MODIF SI a priori */
        BYTE    typ;
        int     flgbuf = 2;     /* zone d'echange optionnelle a priori */
        int     tfn = 32;       /* MODIF SI a priori */

        flg_bufexpr = TRUE;     /* buffer peut etre une expression */

        lexical();      /* avaler le mot-cle */
        if (!recnumlog())       /* recup du numero logique concerne */
                return;
        if (usc.code == VIG) {  /* MODIF sur un fichier SI */
                lexical();
                adr_verrue = TRUE; typ = T_ANY;         /* recup de la cle */
                if (!expression(&typ,&targ[2],&varg[2])) {
                        adr_verrue = FALSE; sfdln(); return;
                }
                adr_verrue = FALSE;
                if (usc.code == VIG) {  /* marqueur explicite */
                        lexical();
                        typ = TBIN;
                        if (!expression(&typ,&targ[3],&varg[3])) {
                                sfdln(); return;
                        }
                }
                else {  /* marqueur par defaut = valeur immediate 1 */
                        targ[3] = 0; varg[3] = 1;
                }
                nbargs = 3; options = 0x03;     /* cle, marqueur */
        }
        else {  /* modif sur un fichier SQ */
                /* mettre le code fonction "prologue" */
                targ[2] = 0; varg[2] = 0x00A1; tfn = 53;
                sq_modif = TRUE; nbargs = 2; options = 0x00FF;
                flgbuf = 1; /* zone d'echange obligatoire */
        }
        if (!fininstio(flgbuf))
                return;
        if (sq_modif) { /* secteur bidon pour le MODIF SQ */
                if (!flg_lgexpl) { /* cste T-code bidon si pas de lgr */
                        nbargs++; targ[nbargs]=0x04; varg[nbargs]=1;
                }
                nbargs++; targ[nbargs] = 0; varg[nbargs] = 0;
        }
        else {
                if (nbargs > 3) {
                        if (flg_lgexpl) options |= 0x0C;
                        else            options |= 0x04;
                }
        }
        genngf(tfn,aderr,nbargs,options,targ,varg);
}
                                        /* pmodif*/

void pname ()

/*      Traduction de l'instruction NAME
 */

{                                       /* pname */

        /* fonction NAME:55 */

        flg_bufexpr = FALSE;    /* buffer doit etre une variable */

        lexical();		/* avaler le mot-cle */

        if (!recnumlog())       /* recup du numero logique concerne */
                return;

        /* definir les parametres */

        nbargs = 1;

        if (!fininstio(1))      /* zone de reception obligatoire */
                return;

	/* cste T-code bidon si pas de lgr */
/*      if (!flg_lgexpl) {
                nbargs++; targ[nbargs]=0x04; varg[nbargs]=1;
        }
*/
        genngf(55,aderr,nbargs,0x00FF,targ,varg);
}                                               /* pname */


void psearch ()

/*      Traduction de l'instruction SEARCH
 */
{                                               /* psearch */
        BYTE    typ;

        flg_bufexpr = FALSE;    /* buffer doit etre une variable */

        lexical();      /* avaler le mot-cle */
        if (usc.code == SPT) {  /* option .ML ? */
                lexical();
                if (usc.code != IDENT) {
                        erreur(USUAL,eriof6); sfdln(); return;
                }
                if (strEq(usc.v.pval,"M"))       options = 0x30;
                else if (strEq(usc.v.pval,"L"))  options = 0x40;
                else if (strEq(usc.v.pval,"ML"))  options = 0x50;
                else if (strEq(usc.v.pval,"LM"))  options = 0x50;
                else {
                        erreur(USUAL,eriof6); sfdln(); return;
                }
                lexical();
        }
        else
                options = 0;
        if (!recnumlog())       /* recup du numero logique concerne */
                return;
        if (usc.code != VIG) {  /* syntaxe ',' attendue et non trouvee */
                erreur(USUAL,eriof4); sfdln(); return;
        }
        lexical();
        adr_verrue = TRUE; typ = T_ANY;         /* recup de la cle */
        if (!expression(&typ,&targ[2],&varg[2])) {
                adr_verrue = FALSE; sfdln(); return;
        }
        adr_verrue = FALSE;
        if (usc.code == VIG) {  /* marqueur explicite */
                lexical();
                typ = TBIN;
                if (!expression(&typ,&targ[3],&varg[3])) {
                        sfdln(); return;
                }
        }
        else {  /* marqueur par defaut = valeur immediate 1 */
                targ[3] = 0; varg[3] = 1;
        }
        nbargs = 3; options |= 0x03;
        if (!fininstio(2))      /* zone d'echange facultative */
                return;
        if (nbargs > 3) {       /* zone d'echange presente */
                if (flg_lgexpl) options |= 0x00C;
                else            options |= 0x004;
        }
        genngf(46,aderr,nbargs,options,targ,varg);
}                                               /* psearch */

//#ifdef _CRIEXT_
void pxcri ()

/*      Traduction de l'instruction XCRI
 */
{                                               /* pxcri */
	BYTE    *adesc, typ;
	BINAIRE reg;


	lexical();			/* avaler le mot-cle */
	options = 0;		/* pas d'options */

	if (!recnumlog())       /* recup du numero logique concerne */
		return;
	if (usc.code != VIG) {  /* syntaxe ',' attendue et non trouvee */
		erreur(USUAL,eriof4); sfdln(); return;
	}

	lexical();

	nbargs = 2;

	/* reference a la zone d'echange in */
	flg_bufexpr = FALSE;    /* zone d'echange in doit etre une variable */

	adrref_verrue = TRUE; reg = getreg();
	if (!reference(reg, &adesc, &varg[nbargs], &targ[nbargs], &typ))
	{
		adrref_verrue = FALSE;
		sfdln(); return;
	}
	adrref_verrue = FALSE;
	if (targ[nbargs] == 4)
	{ /* variable registre */
		ungetreg(); targ[nbargs] = 3; varg[nbargs] = nrgvar;
		erreur(WARNING,eriof14);
	}
	else if (*(adesc+1) != 0)
	{ /* variable externe refusee */
		if ( ( (*(adesc+1) & 0xC0) == 0 ) && (*(adesc+1) != MEMEXT) )
		{
			erreur(USUAL,eriof13); sfdln(); return ;
		}
	}
	lexical();

	nbargs++;

	/* longueur de la zone d'echange in */
	if (usc.code == DPT)
	{ /* la longueur de l'echange est absente */
		if ( targ[nbargs-1] == 2 )
		{
			DCLInfo dcl;
			dcl.adrdesc = varg[nbargs-1];
			GetDCLTable(&dcl);
			targ[nbargs] = 0; /* valeur immediate */
			if ( dcl.ptr )
				varg[nbargs] = dcl.ptlongueur;
			else
				varg[nbargs] = dcl.longueur;
		}
		else
		{
			targ[nbargs] = 0;       /* ce sera une valeur immediate */
			typ = typdesc(adesc);
			if (IS_TBIN1(typ))
				varg[nbargs] = 1;
			else
				if (IS_TBIN2(typ))
				varg[nbargs] = 2;
			else
			{
				/* chaine ou BCD : prendre la longueur dans le descr. */
				/* distingue variable en FIELD=E ou nl */
				if (*(adesc+1) == 0)
					varg[nbargs] = bytetobin(adesc+4);
				else
					varg[nbargs] = bytetobin(adesc+6);
			}
		}
	}
	else
	{  /* longueur d'echange explicite */
		if (usc.code != VIG)
		{
			erreur(USUAL, eriof4); sfdln(); return;
		}
		lexical(); typ = TBIN;
		if (!expression(&typ, &targ[nbargs], &varg[nbargs]))
		{
			sfdln(); return;
		}
	}

	
	flg_bufexpr = FALSE;    /* zone d'echange out doit etre une variable */

	if (!fininstio(2))      /* zone d'echange out */
		return;

	genngf(56,aderr,nbargs,0x00FF,targ,varg);
}                                               /* pxcri */
//#endif

void pinsdel (tfn)

/*      Traduction des instructions INSERT et DELETE
 */
int tfn;
{                                               /* pinsdel */
        int     flgbuf = 0;     /* pas de zone d'echange a priori */
        BYTE    typ;

        flg_bufexpr = TRUE;     /* buffer peut etre une expression */

        lexical();      /* avaler le mot-cle */
        if (!recnumlog())       /* recup du numero logique concerne */
                return;
        if (usc.code != VIG) {  /* syntaxe ',' attendue et non trouvee */
                erreur(USUAL,eriof4); sfdln(); return;
        }
        lexical();
        adr_verrue = TRUE; typ = T_ANY;         /* recup de la cle */
        if (!expression(&typ,&targ[2],&varg[2])) {
                adr_verrue = FALSE; sfdln(); return;
        }
        adr_verrue = FALSE;
        if (usc.code == VIG) {  /* marqueur explicite */
                lexical();
                typ = TBIN;
                if (!expression(&typ,&targ[3],&varg[3])) {
                        sfdln(); return;
                }
        }
        else {  /* marqueur par defaut = valeur immediate 1 */
                targ[3] = 0; varg[3] = 1;
        }
        nbargs = 3; options = 0x03;     /* cle et marqueur */
        if (tfn == 22) /* INSERT: zone d'echange facultative */
                flgbuf = 2;
        if (!fininstio(flgbuf))
                return;
        if (nbargs > 3) {       /* zone d'echange presente */
                if (flg_lgexpl) options |= 0x00C;
                else            options |= 0x004;
        }
        genngf(tfn,aderr,nbargs,options,targ,varg);
}                                               /* pinsdel */

/*--------------------------------------------------------------*/
/*                                                              */
/*      Instructions specifiques de l'acces MC ou BD            */
/*                                                              */
/*--------------------------------------------------------------*/

void pclpj(tfn)

/*      traduction des instructions :
 *      CJOIN, CLINK, COUNT, DJOIN, LINK, JOIN et POSIT
 *      'tfn' faisant la difference en entree.
 *      (8:CJOIN, 10:CLINK, 12:COUNT, 15:DJOIN, 27:LINK, 23:JOIN, 39:POSIT)
 */
int tfn;
{                                               /* pclpj */
        BYTE    topt;
        BINAIRE vopt;
        int     flgbuf = 0;     /* pas de zone d'echange a priori */

        flg_bufexpr = FALSE;    /* buffer doit etre une variable */

        lexical();      /* avaler le mot-cle */
        if ((tfn == 12) || (tfn == 39)) {
           /* COUNT ou POSIT : utiliser l'octet d'options complementaires */
           flgbuf = 1;  /* et une variable d'echange imposee */
           if ((tfn == 39) && (usc.code == SPT)) { /* option .D si POSIT */
                lexical();
                if (usc.code != IDENT) {
                        erreur(USUAL,eriof6); sfdln(); return;
                }
                if (!strEq(usc.v.pval,"D")) {
                        erreur(USUAL,eriof6); sfdln(); return;
                }
                options = 1; lexical();
           }
           else
                options = 0;
        }
        else
                options = 0x00FF;
        if (!recnumlog())       /* recup du numero logique concerne */
                return;
        if (((tfn == 23) || (tfn == 15)) && (usc.code != PAG)) {
                /* JOIN ou DJOIN : jointure imposee */
                erreur(USUAL,eriof11); sfdln(); return;
        }
        if (!recjoin(&targ[2],&varg[2]))
                return; /* erreur dans recup de la jointure */
        if ((tfn == 8) && (targ[2] == 0)) /* CJOIN sans plus ... */
                nbargs = 1;
        else
                nbargs = 2;
        if ((tfn != 8) && (tfn != 15)) { /* CJOIN,DJOIN: Ni liste ni option */
           if ((tfn == 23) && (usc.code != VIG)) {
                /* JOIN : interro imposee */
                erreur(USUAL,eriof4); sfdln(); return;
           }
           if ((tfn == 10) && (usc.code != VIG))
                /* CLINK : interro optionnelle */
                ;
           else {
                if (!recinterro(&targ[3],&varg[3]))
                        return; /* erreur dans recup de la liste / question */
                nbargs = 3;
                if (tfn != 23) {
                        /* JOIN : Pas d'option !! */
                        if ((tfn == 12) || (tfn == 39)) { /* COUNT ou POSIT */
                                if (!recopt(&topt,&vopt,0,"US",1))
                                        return; /* erreur */
                        }
                        else { /* LINK ou CLINK */
                                if (!recopt(&targ[4],&varg[4],0,"AD",1))
                                        return; /* erreur */
                                nbargs = 4;
                        }
                }
            }
        }
        if (!fininstio(flgbuf))
                return;
        if ((tfn == 12) || (tfn == 39)) {
                /* COUNT ou POSIT : patcher la longueur avec l'option .. */
                if (!flg_lgexpl)
                        nbargs++;
                targ[nbargs] = topt; varg[nbargs] = vopt;
        }
        /* generation du code */
        genngf(tfn,aderr,nbargs,options,targ,varg);
}                                               /* pclpj */

void pliste (tfn)

/*      traduction des instructions LKEY, LLINK, LFILE, LJOIN, RECORD ou STAT
 *      'tfn' faisant la difference en entree.
 *      (25:LFILE, 28:LJOIN, 29:LKEY, 30:LLINK, 42:RECORD, 47:STAT)
 */
int tfn;
{                                               /* pliste */
        int flgbuf = 1;

        flg_bufexpr = FALSE;    /* buffer doit etre une variable */

        lexical();      /* avaler le mot-cle */
        if (!recnumlog())       /* recup du numero logique concerne */
                return;
        if (tfn != 42) {        /* rien de plus si RECORD */
                if (tfn != 47) {        /* pas d'option si STAT */
                        if (!recopt(&targ[2],&varg[2],0,"F",1))
                                return; /* erreur */
                }
                else {
                        targ[2] = 0; varg[2] = 0;
                }
                nbargs = 2;
        }
        else {
                nbargs = 1; flgbuf = 2;
        }
        if (!fininstio(flgbuf))
                return;
        /* generation du code */
        genngf(tfn,aderr,nbargs,0x00FF,targ,varg);
}                                               /* pliste */

void prenkj(tfn)

/*      traduction d'une instruction NKEY ou RJOIN
 *      'tfn' faisant la difference en entree.
 *      (33: NKEY, 44: RJOIN)
 */
int tfn;
{                                               /* prenkj */
        BYTE    typ;

        lexical();      /* avaler le mot-cle */
        if (!recnumlog())       /* recup du numero logique concerne */
                return;
        if (tfn == 44) { /* RJOIN : chercher la premiere jointure */
                if (usc.code != PAG) { /* '(' attendue et non trouvee */
                        erreur(USUAL,eriof11); sfdln(); return;
                }
                if (!recjoin(&targ[2],&varg[2]))
                        return;
        }
        else  {
                if (usc.code != VIG) { /* ',' attendue et non trouvee */
                        erreur(USUAL,eriof4); sfdln(); return;
                }
                lexical();
                typ = TSTR;             /* recup de l'ancien nom */
                if (!expression(&typ,&targ[2],&varg[2])) {
                        sfdln(); return;
                }
        }
        if (usc.code != VIG) { /* syntaxe ',' attendue et non trouvee */
                erreur(USUAL,eriof4); sfdln(); return;
        }
        lexical();
        if (tfn == 44) { /* RJOIN : chercher la deuxieme jointure */
                if (usc.code != PAG) { /* '(' attendue et non trouvee */
                        erreur(USUAL,eriof11); sfdln(); return;
                }
                if (!recjoin(&targ[3],&varg[3]))
                        return;
        }
        else {
                typ = TSTR;             /* recup du nouveau nom */
                if (!expression(&typ,&targ[3],&varg[3])) {
                        sfdln(); return;
                }
        }
        if (!fininstio(0))      /* pas de zone d'echange */
                return;
        genngf(tfn,aderr,3,0x00FF,targ,varg);
}                                               /* prenkj */

void pfkey ()

/*      traduction de l'instruction FKEY
 */
{                                               /* pfkey */
        BYTE    typ;

        lexical();      /* avaler le mot-cle */
        if (!recnumlog())       /* recup du numero logique concerne */
                return;
        if (usc.code != VIG) {
                nbargs = 1;
        }
        else {
                lexical();
                typ = TSTR;
                if (!expression(&typ,&targ[2],&varg[2])) {
                        sfdln(); return;
                }
                nbargs = 2;
        }
        if (!fininstio(0))      /* pas de zone d'echange */
                return;
        genngf(19,aderr,nbargs,0x00FF,targ,varg);
}                                               /* pfkey */

void pkey ()

/*      traduction de l'instruction KEY
 */
{                                               /* pkey */
        BYTE    typ;
        char    opt;

        lexical();      /* avaler le mot-cle */
        if (!recnumlog())       /* recup du numero logique concerne */
                return;
        if (usc.code != VIG) {  /* syntaxe !! */
                erreur(USUAL,eriof4); sfdln(); return;
        }
        lexical(); typ = TSTR;
        if (!expression(&typ,&targ[2],&varg[2])) {      /* nom rubrique */
                sfdln(); return;
        }
        if (usc.code != VIG) {  /* syntaxe !! */
                erreur(USUAL,eriof4); sfdln(); return;
        }
        lexical(); typ = TBIN;                          /* lg. rubrique */
        if (!expression(&typ,&targ[3],&varg[3])) {
                sfdln(); return;
        }
        nbargs = 4; targ[4] = 0;
        if (usc.code == VIG) {  /* type de rubrique explicite */
                lexical();
                if (usc.code != IDENT) {
                        erreur(USUAL,eriof6); sfdln(); return;
                }
                if (Xstrlen(usc.v.pval) != 1) {
                        erreur(USUAL,eriof6); sfdln(); return;
                }
                opt = *usc.v.pval; lexical();
                switch (opt) {
                        case 'N':
                                varg[4] = 1; break;
                        case 'A':
                                varg[4] = 3; break;
                        case 'B':
                                varg[4] = 2;
                                if (usc.code == VIG) {  /* nb decimales */
                                   lexical(); nbargs = 5; typ = TBIN;
                                   if (!expression(&typ,&targ[5],&varg[5])) {
                                        sfdln(); return;
                                   }
                                }
                                break;
                        default:
                                erreur(USUAL,eriof6); sfdln(); return;
                }
        }
        else {
                varg[4] = 3;    /* type chaine par defaut */
        }
        if (!fininstio(0))      /* pas de zone d'echange */
                return;
        genngf(24,aderr,nbargs,0x00FF,targ,varg);
}                                               /* pkey */

/*--------------------------------------------------------------*/
/*                                                              */
/*      Instructions generales pour acces direct/sequentiel     */
/*                                                              */
/*--------------------------------------------------------------*/

void prdwr(tfn)

/*      traduction d'une instruction du type READ/WRITE
 *      'tfn' faisant la difference en entree.
 *      (41: READ, 53: WRITE)
 */
int tfn;
{                                               /* prdwr */
        BYTE    typ,tsect;
        BINAIRE vsect;

        if (tfn == 41)
                flg_bufexpr = FALSE;    /* buffer doit etre une variable */
        else
                flg_bufexpr = TRUE;     /* buffer peut etre une expression */

        lexical();      /* avaler le mot-cle */
        if (!recnumlog())       /* recup du numero logique concerne */
                return;
        if (usc.code == VIG) {  /* READ/WRITE etendu pour l'acces direct */
                lexical();
                typ = TBIN;             /* recup du code fonction */
                if (!expression(&typ,&targ[2],&varg[2])) {
                        sfdln(); return;
                }
                if (usc.code == VIG) {
                        lexical();
                        typ = T_ANY;
                        if (!expression(&typ,&tsect,&vsect)) {
                                sfdln(); return;
                        }
                        if (IS_TSTR(typ)) {  /* chaine ne peut pas convenir */
                                erreur(USUAL,eriof3); sfdln(); return;
                        }
                }
                else {  /* numero de secteur = 0 par defaut */
                        tsect = 0; vsect = 0;
                }
        }
        else {  /* READ/WRITE pour l'acces sequentiel */
                /* mettre le code fonction "prologue" */
                if (tfn == 41) {        /* READ */
                        targ[2] = 0; varg[2] = 0x0061;
                }
                else {                  /* WRITE */
                        targ[2] = 0; varg[2] = 0x00A5;
                }
                tsect = 0; vsect = 0;
        }
        nbargs = 2;
        if (!fininstio(1))
                return;
        /* si la longueur du buffer est absente : l'indiquer dans
           le descripteur de l'argument et mettre 0x1 0x0 dans le T-code */
        if (!flg_lgexpl) {
                nbargs++; targ[nbargs] = 0x04; varg[nbargs] = 1;
        /*      nbargs++; targ[nbargs] = 0   ; varg[nbargs] = 0;*/
        }
        /* mettre en place le numero de secteur */
        nbargs++; targ[nbargs] = tsect; varg[nbargs] = vsect;
        /* generation du code */
        genngf(tfn,aderr,nbargs,0x00FF,targ,varg);
}                                               /* prdwr */

void pngfnlog(fnt)

/*      traduction d'une instruction dont le seul argument est
 *      le numero logique.
 *      'fnt' est le numero de l'instruction NGF.
 */
int fnt;
{                                               /* pngfnlog */
        lexical();      /* avaler le mot-cle */
        if (!recnumlog())       /* recup du numero logique concerne */
                return;
        if (!fininstio(0))      /* zone d'echange refusee */
                return;
        /* generation du code avec un seul argument */
        genngf(fnt,aderr,1,0x00FF,targ,varg);
}                                               /* pngfnlog */

static BOOL recnumlog()

/*      recuperation du numero logique concernant un acces fichier
 *      au retour, la valeur 'TRUE' est rendue si Ok, et les variables
 *      globales 'varg[1]' et 'targ[1]' sont affectees,
 *      sinon la valeur 'FALSE' est rendue et la fin de ligne est by-passee
 */
{                                               /* recnumlog */
        BYTE typ;

        if (usc.code != EGAL) { /* caractere '=' attendu et non trouve */
                erreur(USUAL,eriof2); sfdln(); return (FALSE);
        }
        lexical();
        typ = TBIN; libreg = firstreg;
        if (!expression(&typ,&targ[1],&varg[1])) {
                sfdln(); return (FALSE);
        }
        if (IS_TSTR(typ)) {      /* chaine ne peut pas etre un numero logique */
                erreur(USUAL,eriof3); sfdln(); return (FALSE);
        }
        return (TRUE);
}                                               /* recnumlog */

static BOOL fininstio(flgbuf)

/*      Traitement de la fin d'une instruction sur numero logique, soit :
 *      - l'eventuel branchement en cas d'erreur
 *      en affectant dans ce cas les variables suivantes sont affectees :
 *      aderr <- GenericNULL(char) <- 0 si pas de branchement,
 *	sinon 'targ[0]' et 'varg[0]' <- type et adr variable d'erreur.
 *      - la zone d'echange, qui, est imposee si flgbuf vaut 1 en entree,
 *      est refusee si flgbuf vaut 0 en entree, et est optionnelle sinon.
 *      elle est rangee dans les variables :
 *      'targ[nbargs+1]' et 'varg[nbargs+1]' <- adresse de la zone d'echange
 *      'targ[nbargs+2]' et 'varg[nbargs+2]' <- longueur de la zone d'echange
 *      de plus, si 'flg_bufexpr' vaut TRUE en entree, une expression sera
 *      acceptee, alors que seule une variable est toleree sinon.
 *      dans ce cas, nbargs est augmente de 2 ...
 *
 */
int flgbuf;
{                                               /* fininstio */
        BYTE    *adesc,typ;
        BINAIRE reg;

        flg_lgexpl = TRUE;

        aderr = GenericNULL(char); /* pas de branchement d'erreur a priori */
        if (usc.code == FDLN) {
                if (flgbuf == 1) { /* zone d'echange attendue et non trouvee */
                        erreur(USUAL,eriof7); return (FALSE);
                }
                else    return (TRUE);
        }
        if (usc.code != DPT) {  /* ':' attendu et non trouve */
                erreur(USUAL,eriof8); sfdln(); return (FALSE);
        }
        /* avaler le ':' en prevoyant une etiquette */
        lexical();
        if ((usc.code == ETIQ) || (usc.code == NEXT)) {
                /* etiquette -> branchement d'erreur */
                aderr = &bufaderr[0];
                if (usc.code == ETIQ) /* etiquette explicite */
                        Xstrcpy(aderr,usc.v.pval);
                else
                        cretiq(aderr);
                lexical();
                if (usc.code != VIG) { /* syntaxe ... !!! */
                        erreur(USUAL,eriof4); sfdln(); return (FALSE);
                }
                lexical();
                /* reference a une variable de type numerique */
                reg = getreg(); adrref_verrue = TRUE;
                if (!reference(reg,&adesc,&varg[0],&targ[0],&typ)) {
                        adrref_verrue = FALSE; sfdln(); return (FALSE);
                }
                if (targ[0] == 4) {     /* variable 'registre' */
                        ungetreg(); targ[0] = 3; varg[0] = nrgvar;
                }
                adrref_verrue = FALSE;
                if (IS_TSTR(typ)) {
                        erreur(USUAL,eriof3); sfdln(); return (FALSE);
                }
                lexical();
                if (usc.code == FDLN) {
                        if (flgbuf == 1) {
                                erreur(USUAL,eriof7); return (FALSE);
                        }
                        return (TRUE);
                }
                if (usc.code != VIG) { /* syntaxe ... !!! */
                        erreur(USUAL,eriof4); sfdln(); return (FALSE);
/* BUG2 */      } else {
                        if (flgbuf == 0) { /* et elle est interdite !!! */
                                erreur(USUAL,eriof10); sfdln(); return (FALSE);
                        }
                }
                lexical();      /* avaler la virgule */
        }
        else {  /* pas de branchement d'erreur : variable d'echange */
                if (flgbuf == 0) { /* et elle est interdite !!! */
                        erreur(USUAL,eriof10); sfdln(); return (FALSE);
                }
        }

        /* reference a la zone d'echange */
        nbargs++;
        if (flg_bufexpr) { /* on accepte une expression */
                typ = T_ANY; adr_verrue = TRUE;
                if (!expression(&typ,&targ[nbargs],&varg[nbargs])) {
                        sfdln(); adr_verrue = FALSE; return (FALSE);
                }
                adr_verrue = FALSE;
                if (nrgvar != 0) { /* Z! : variable "registre" */
                        erreur(WARNING,eriof14);
                }
        }
        else { /* forcement une variable */
            adrref_verrue = TRUE; reg = getreg();
            if (!reference(reg,&adesc,&varg[nbargs],&targ[nbargs],&typ)) {
                adrref_verrue = FALSE;
                sfdln(); return (FALSE);
            }
            adrref_verrue = FALSE;
            if (targ[nbargs] == 4) { /* variable registre */
                ungetreg(); targ[nbargs] = 3; varg[nbargs] = nrgvar;
                erreur(WARNING,eriof14);
            }
            else if (*(adesc+1) != 0) { /* variable externe refusee */
                if ( ( (*(adesc+1) & 0xC0) == 0 ) && (*(adesc+1) != MEMEXT) ) {
                        erreur(USUAL,eriof13); sfdln(); return (FALSE);
                }
            }
            lexical();
        }

        nbargs++;
        if (usc.code == FDLN) { /* la longueur de l'echange est absente */
           if (flg_bufexpr) {   /* OK si expression ... */
                nbargs--; flg_lgexpl = FALSE;
           }
           else {
		if ( targ[nbargs-1] == 2 ) {
			DCLInfo dcl;
			dcl.adrdesc = varg[nbargs-1];
			GetDCLTable(&dcl);
			targ[nbargs] = 0; /* valeur immediate */
			if ( dcl.ptr )
				varg[nbargs] = dcl.ptlongueur;
			else
				varg[nbargs] = dcl.longueur;
		} else {
	                targ[nbargs] = 0;       /* ce sera une valeur immediate */
        	        typ = typdesc(adesc);
	                if (IS_TBIN1(typ)) varg[nbargs] = 1;
        	        else if (IS_TBIN2(typ)) varg[nbargs] = 2;
	                else {
        		        /* chaine ou BCD : prendre la longueur dans le descr. */
		                /* distingue variable en FIELD=E ou nl */
                		if (*(adesc+1) == 0)
		                        varg[nbargs] = bytetobin(adesc+4);
                		else
		                        varg[nbargs] = bytetobin(adesc+6);
                	}
		}
           }
        }
        else {  /* longueur d'echange explicite */
                if (usc.code != VIG) {
                        erreur(USUAL,eriof4); sfdln(); return (FALSE);
                }
                lexical(); typ = TBIN;
                if (!expression(&typ,&targ[nbargs],&varg[nbargs])) {
                        sfdln(); return (FALSE);
                }
                if (usc.code != FDLN)
                        tfdln();
        }
        return (TRUE);
}                                               /* fininstio */

static BOOL recopt(top,vop,vdef,psel,nbopt)
/*      recuperation d'une eventuelle option du type " ,(F) "
 *      les valeurs possibles sont donnees par 'psel' (en majuscules),
 *      la valeur par defaut est donnee par 'vdef'.
 *      retourne la valeur de l'option dans 'top,vop'.
 */
BYTE    *top;
BINAIRE *vop,vdef;
char    *psel;
BINAIRE nbopt;          /* Nombre max d'options cumulables ex: (FDI) =3 */
{                                                       /* recopt */
        BYTE    typ;
        char    opt;
        char *sv_psel;          /* sauvegarde de psel */
        if (usc.code == VIG) {  /* option explicite */
                lexical();
                if (usc.code != PAG) {
                        erreur(USUAL,eriof11); sfdln(); return (FALSE);
                }
                lexical();
                if (usc.code != PAG) {  /* valeur immediate */
                        if (usc.code != IDENT) {
                                erreur(USUAL,eriof6); sfdln(); return (FALSE);
                        }
                        if (Xstrlen(usc.v.pval) > nbopt) {
                                erreur(USUAL,eriof6); sfdln(); return (FALSE);
                        }

                        /* Creation d'une constante chaine contenant les options */
                        *vop = newstr(usc.v.pval);

                        /* verification des options */

                        opt = *usc.v.pval;
                        sv_psel = psel;

                        while (1) {     /* sortie par break ou return */

                                /* verification d'une option */
                                while (1) {
                                        if (opt == *psel) {
                                                break;
                                        }
                                        else if (*psel == EOSTR) {
                                                erreur(USUAL,eriof6); sfdln();
                                                return (FALSE);
                                        }
                                        psel++;
                                }
                                if (opt == EOSTR) {
                                        *top = 1;
                                        break;
                                }
                                opt = *(usc.v.pval++);
                                psel = sv_psel;
                        }
                }
                else {  /* option variable */
                        lexical(); typ = TSTR;
                        if (!expression(&typ,top,vop)) {
                                sfdln(); return (FALSE);
                        }
                        if (usc.code != PAD) {
                                erreur(USUAL,eriof12); sfdln(); return (FALSE);
                        }
                }
                lexical();
                if (usc.code != PAD) {
                        erreur(USUAL,eriof12); sfdln(); return (FALSE);
                }
                lexical();
        }
        else {                  /* option par defaut */
                *top = 0; *vop = vdef;
        }
        return (TRUE);
}                                                       /* recopt */

static BOOL recjoin (top,vop)

/*      recuperation d'un nom de jointure
 *      par defaut, donne la valeur immediate nulle.
 */
BYTE    *top;
BINAIRE *vop;
{                                                       /* recjoin */
        BYTE    typ;

        if (usc.code == PAG) {
                lexical(); typ = TSTR;
                if (!expression(&typ,top,vop)) {
                        sfdln(); return (FALSE);
                }
                if (usc.code != PAD) {
                        erreur(USUAL,eriof12); sfdln(); return (FALSE);
                }
                lexical();
        }
        else {
                *top = 0; *vop = 0;
        }
        return (TRUE);
}                                                       /* recjoin */

static BOOL recinterro (top,vop)

/*      recuperation d'une interrogation (liste / question)
 */
BYTE    *top;
BINAIRE *vop;
{                                                       /* recinterro */
        BYTE    typ;

        if (usc.code != VIG) {
                erreur(USUAL,eriof4); sfdln(); return (FALSE);
        }
        lexical(); typ = TSTR;
        if (!expression(&typ,top,vop)) {
                sfdln(); return (FALSE);
        }
        return (TRUE);
}                                                       /* recinterro */


/*      Gestion de la memoire   */
/*      ---------------------   */

void trcreate (tfn)
int tfn;
/*      Traduction de l'instruction CREATE
 */
{
	BYTE typ;                                            /* trcreate */
	int i;
	BINAIRE nbop[20];
	BYTE	top[20][4];
	BINAIRE vop[20][4];
	BYTE *adesc;
	BINAIRE advar;
	DCLInfo dcl;
	BINAIRE max;

	i=1;
        do {
		if ( i > 19 ) {
	                erreur(USUAL,ersynt6); sfdln(); return;
		}

		/* avaler le mot-cle, puis la virgule */
                lexical();
	        if (usc.code != IDENT) {
        	        erreur(USUAL,ersynt4); sfdln(); return;
        	}
		
		/* Est ce une variable ? */
        	adesc = findvar(usc.v.pval,GenericNULL(BYTE),&advar,GenericNULL(TabSymb *),TRUE);
        	if (adesc == GenericNULL(char)) {
	                erreur(USUAL,ersynt6); sfdln(); return;
		}

		dcl.adrdesc = advar;
		GetDCLTable(&dcl);

		/* Est ce un pointeur ? */
		if ( ! dcl.ptr ) {
                	erreur(USUAL,ersynt38); sfdln(); return;
		}
		
		/* Calcul du max */
		switch ( dcl.type ) {
			case TBCD:
			case TSTR:
				max=2;
				break;
			case TBIN1:
			case TBIN2:
				max=1;
				break;
			default:
				max=0;
		}
		if ( dcl.dim1 != 0 )
			max++;
		if ( dcl.dim2 != 0 )
			max++;
		
		/* variable */
		top[i][0]=2;
		vop[i][0]=advar;

		lexical();
		nbop[i] = 1;

		/* est une definition de dimension ? */
		if ( usc.code == PAG ) {
			do {
				/* avaler la parenthese, puis la virgule */
				lexical();

				if ( tfn == 95 ) /* Si c'est un ATTACH, pas de controle de type */
					typ = T_ANY;
				else
				        typ = TBIN;

			        if (!expression(&typ,&top[i][nbop[i]],&vop[i][nbop[i]])) {
	        		        erreur(USUAL,ersynt6); sfdln(); return;
        			}
				nbop[i]++;
				if ( nbop[i] == max ) break;
			} while ( usc.code == VIG );

			/* fin de la definition de dimension */
			if ( usc.code != PAD ) {
        		        erreur(USUAL,ersynt6); sfdln(); return;
			}

			lexical();
			/* le suivant */
			i++;

		} else {
			/* le suivant */
			i++;
		}		
        } while ( usc.code == VIG );

        if (!fininstio(0))      /* zone d'echange refusee */
                return;

	/* generation du code du create */

	gencreate(tfn,aderr,i,nbop,top,vop,targ[0],varg[0]);

}                                               /* trcreate */

void trforget (tfn)
/*      Traduction des instructions FORGET, REMOVE
 */
int tfn;
{                                               /* trforget */
	BYTE typ;                                           

	BINAIRE nbop;
	BYTE	top[4];
	BINAIRE vop[4];
	BYTE *adesc;
	BINAIRE advar;
	DCLInfo dcl;
	BINAIRE max;

        do {
		/* avaler le mot-cle, puis la virgule */
                lexical();
	        if (usc.code != IDENT) {
        	        erreur(USUAL,ersynt4); sfdln(); return;
        	}
		
		/* Est ce une variable ? */
        	adesc = findvar(usc.v.pval,GenericNULL(BYTE),&advar,GenericNULL(TabSymb *),TRUE);
        	if (adesc == GenericNULL(char)) {
	                erreur(USUAL,ersynt6); sfdln(); return;
		}

		dcl.adrdesc = advar;
		GetDCLTable(&dcl);

		/* Est ce un pointeur ? */
		if ( ! dcl.ptr ) {
                	erreur(USUAL,ersynt38); sfdln(); return;
		}
		
		/* Calcul du max */
		switch ( dcl.type ) {
			case TBCD:
			case TSTR:
				max=2;
				break;
			case TBIN1:
			case TBIN2:
				max=1;
				break;
			default:
				max=0;
		}
		if ( dcl.dim1 != 0 )
			max++;
		if ( dcl.dim2 != 0 )
			max++;
		
		/* variable */
		top[0]=2;
		vop[0]=advar;

		lexical();
		nbop = 1;

		/* est une definition de dimension ? */
		if ( usc.code == PAG ) {
			do {
				/* avaler la parenthese, puis la virgule */
				lexical();
			        typ = TBIN;
			        if (!expression(&typ,&top[nbop],&vop[nbop])) {
	        		        erreur(USUAL,ersynt6); sfdln(); return;
        			}
				nbop++;
				if ( nbop == max ) break;
			} while ( usc.code == VIG );

			/* fin de la definition de dimension */
			if ( usc.code != PAD ) {
        		        erreur(USUAL,ersynt6); sfdln(); return;
			}
			lexical();
		}
		genclf(TRUE,tfn,nbop,0,0,top,vop,GenericNULL(BYTE));
        } while ( usc.code == VIG );

}                                               /* trforget */

