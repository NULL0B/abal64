/*
 *      Projet  : ABAL                  Copyright Amenesik / Sologic s.a. (c) 1990, 1995
 *      Module  : ATR
 *      Fichier : TCASM.C
 *      Version : 2.1f
 *      Date    : 22/11/95
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Macro-assembleur de T-code]
 *
 */

/*
 * Mises a jour :
 * ------------
 *
 *	------------ 2.2a -------------------------------------------------
 * 07/03/97 : Prototype de findvar() modifie, reprise de tous les appels
 */

/* Fichier de definition */
/* --------------------- */
#include "tr.h"
#include "fuser.h"
#include "syntaxe.h"
#include "tsymb.h"
#include "tcode.h"
#include "codes.h"

#define _TCASM
#include "tcasm.hs"
#include "tcasm.he"


void masm(seg)

/*      Assemblage d'une ligne en T-Code, en entree seg est vrai pour
 *      le cas d'un segment en cours, et faux si c'est une procedure
 */
BOOL seg;
{                                               /* masm */
        BINAIRE mnem;
        BYTE    code;

        if ((usc.code != IDENT) && (usc.code != AND) && (usc.code != OR) &&
            (usc.code != OX) && (usc.code != MOD) && (usc.code != DEC)) {
                /* erreur : la ligne doit commencer par un mnemonique */
                erreur(USUAL,ermasm1); sfdln(); return;
        }
        if (strEq(usc.v.pval,"DB")) {
                defbytes(); return;
        }
        else if (strEq(usc.v.pval,"DL")) {
                deflabel(); return;
        }
        else if (strEq(usc.v.pval,"DV")) {
                defvar(); return;
        }
        else {
                mnem = recmnemo();      /* recuperer le mnemonique associe */
                if (mnem == MXCODES) {
                        /* erreur : mnmemonique incorrect */
                        sfdln(); return;
                }
        }
        code = _tc_code[mnem];  /* recuperer le code associe */
        if (seg) {      /* verif Ok pour Segment */
           if (code == F_RTP) {
                erreur(USUAL,ermasm3);
           }
        }
        else            /* verif Ok pour procedure */
           if ((code == F_SGT) || (code == F_RTS)) {
                erreur(USUAL,ermasm4);
           }
        rec_args(code,_tc_args[mnem]);  /* et recuperer les arguments */
}                                               /* masm */


/*      Primitives internes
 *      -------------------     */

static BINAIRE recmnemo()

/*      Recherche d'un mnemonique T-Code, en entree seg est vrai pour
 *      le cas d'un segment en cours, et faux si c'est une procedure
 */
{                                               /* recmnemo */
        register BINAIRE code = 0;

        do {
                if (Xstrcmp(usc.v.pval,_tc_mnem[code]) == 0)  /* trouve ! */
                        return (code);
        }
        while (++code < MXCODES);
        erreur(USUAL,ermasm2);
        return (code);
}                                               /* recmnemo */


static void defbytes()

/*      Traitement d'une definition d'octets
 */
{                                               /* defbytes */
        BINAIRE val;

        do {
                if (!getint(&val)) {
                        sfdln(); return;
                }
                if (val > 255) {
                        erreur(USUAL,ermasm14); sfdln(); return;
                }
                pcode((BYTE) val);
                lexical();
        }
        while (usc.code == VIG);
        if (usc.code != FDLN) {
                erreur(USUAL,errfdln); sfdln();
        }
}                                               /* defbytes */


static void deflabel()

/*      Traitement d'une reference a une etiquette dans une
 *      definition d'octets.
 */
{                                               /* deflabel */
        BINAIRE adr;

        if (getetq(&adr)) {
                padr(adr);
                lexical();
                if (usc.code != FDLN) {
                        erreur(USUAL,errfdln); sfdln();
                }
        }
        else
                sfdln();
}                                               /* deflabel */


static void defvar()

/*      Traitement d'une reference a une etiquette dans une
 *      definition d'octets.
 */
{                                               /* defvar */
        BINAIRE adr;

        if (getvar(&adr)) {
                padr(adr);
                lexical();
                if (usc.code != FDLN) {
                        erreur(USUAL,errfdln); sfdln();
                }
        }
        else
                sfdln();
}                                               /* defvar */


static void rec_args(code,targs)

/*      Traitement des arguments pour le code operation 'code'
 */
BYTE code;
BINAIRE targs;
{                                               /* recargs */
        BYTE    reg;
        BINAIRE adr;


        switch (targs) {
          case 0:               /* pas d'arguments */
                pcode(code);
sortie:
                tfdln(); break;
          case 1:               /* un registre */
                pcode(code)
                if (!getreg(&reg))              goto abandon;
                preg(reg);                      goto sortie;
          case 2:               /*  un suite variable, une variable */
                if (!gtsicvr(code))             goto abandon;
                if (!sep())                     goto abandon;
                if (!getvar(&adr))              goto abandon;
                padr(adr); goto sortie;
          case 3:               /* un registre une suite variable */
                if (!getreg(&reg))              goto abandon;
                if (!sep())                     goto abandon;
                if (!geticvr(code,reg))         goto abandon;
                goto sortie;
          case 4:       /* un registre , une suite variable , un registre */
                if (!getreg(&reg))              goto abandon;
                if (!sep())                     goto abandon;
                if (!geticvr(code,reg))         goto abandon;
                if (!sep())                     goto abandon;
                if (!getreg(&reg))              goto abandon;
                preg(reg);                      goto sortie;
          case 5:       /* un registre , une suite variable , une etiquette */
                if (!getreg(&reg))              goto abandon;
                if (!sep())                     goto abandon;
                if (!geticvr(code,reg))         goto abandon;
                if (!sep())                     goto abandon;
                if (!getetq(&adr))              goto abandon;
                padr(adr);                      goto sortie;
          case 6:       /* Immediat ou registre ou variable : SGT */
                if (!getirv(code))              goto abandon;
                goto sortie;
          case 7:       /* une suite variable (sans registre) */
                if (!gtsicvr(code))             goto abandon;
                goto sortie;
          case 8:       /* etiquette ou registre ou variable */
                if (!geterv(code))              goto abandon;
                goto sortie;
          case 9:       /* registre ou variable */
                if (!getrv(code))               goto abandon;
                goto sortie;
          case 10:      /* variable puis etiquette */
                pcode(code);
                if (!getvar(&adr))              goto abandon;
                padr(adr);
                if (!sep())                     goto abandon;
                if (!getetq(&adr))              goto abandon;
                padr(adr);                      goto sortie;
          case 11:      /* Special (CLF : bib std) */
                pcode(code);
                if (!tr_fnt())                  goto abandon;
                goto sortie;
          case 12:      /* Special (CLP : proc A.B.A.L.) */
                erreur(USUAL,ermasm5); goto abandon;
          case 13:      /* Special (NGF) */
          case 14:      /* Special (LDF) */
                erreur(USUAL,ermasm5); goto abandon;
          case 15:      /* special (ESC) */
                pcode(code);
                if (!getir())           goto abandon;
                if (!sep())             goto abandon;
                if (!getir())           goto abandon;
                goto sortie;
          case 16:      /* special CNV : registre + type sur 2 octets */
                pcode(code);
                if (!getreg(&reg))              goto abandon;
                preg(reg);
                if (!sep())                     goto abandon;
                if (!getint(&adr))              goto abandon;
                padr(adr);                      goto sortie;
          case 17:      /* special VPT : registre + adr.var */
                pcode(code);
                if (!getreg(&reg))              goto abandon;
                preg(reg);
                if (!sep())                     goto abandon;
                if (!getvar(&adr))              goto abandon;
                padr(adr);                      goto sortie;
          case 18:      /* special DTR : adr.var */
                pcode(code);
                if (!getvar(&adr))              goto abandon;
                padr(adr);                      goto sortie;
          default:
                erreur(USUAL,ermasm5);
abandon:
                sfdln(); break;
        }
}                                               /* recargs */


static BOOL tr_fnt()
/*      traitement d'une fonction standard
 *      PROVISOIRE POUR TESTS : ne traite que ASK et PRINT
 */
{                                       /* tr_fnt */
        BOOL flg = TRUE;
        BINAIRE v;

        lexical();
        if (usc.code == ASK) {
                pcode(FN_ASK);
                flg = getvar(&v);
                if (flg) padr(v);
        }
        else if (usc.code == PRINT)
                flg = gtsicvr(FN_PRN);
        else {
                erreur(USUAL,ermasm5); flg = FALSE;
        }
        return (flg);
}                                       /* tr_fnt */


static BOOL getreg(r)
/*      recherche d'un registre */
BYTE *r;
{                                       /* getreg */
        BINAIRE numreg;

        lexical();
        if (usc.code != DIESE) {
                erreur(USUAL,ermasm7); return (FALSE);
        }
        lexical();
        if (!recbincst(&numreg)) {
                erreur(USUAL,ermasm7); return (FALSE);
        }
        if (numreg > 255) {
                erreur(USUAL,ermasm8); return (FALSE);
        }
        *r = (BYTE) numreg;
        return (TRUE);
}                                       /* getreg */


static BOOL getint(v)
/*      recherche d'une constante binaire */
BINAIRE *v;
{                                       /* getint */
        BINAIRE valeur;

        lexical();
        if (!recbincst(&valeur)) {
                erreur(USUAL,ermasm9); return (FALSE);
        }
        *v = valeur;
        return (TRUE);
}                                       /* getint */


static BOOL getvar(v)
/*      recherche d'une variable */
BINAIRE *v;
{                                       /* getvar */
        BINAIRE adesc;

        lexical();
        if (usc.code != IDENT) {
                erreur(USUAL,ermasm11); return (FALSE);
        }
        if (findvar(usc.v.pval,GenericNULL(BYTE),&adesc,GenericNULL(TabSymb *),TRUE) == GenericNULL(BYTE),TRUE) {
                erreur(USUAL,ermasm12); return (FALSE);
        }
        *v = adesc;
        return (TRUE);
}                                       /* getvar */


static BOOL getetq(v)
/*      recherche d'une etiquette */
BINAIRE *v;
{                                       /* getetq */
        lexical();
        if (usc.code != ETIQ) {
                erreur(USUAL,ermasm13); return(FALSE);
        }
        *v = refetiq(usc.v.pval,(BINAIRE) adrimpl);
        return (TRUE);
}                                       /* getetq */


static BOOL geticvr(code,reg)
BYTE code,reg;
{                               /* geticvr */
        BYTE    reg2, c = code, *a = GenericNULL(BYTE);
        BINAIRE adr;

        lexical();
        if (recbincst(&adr)) goto icv;
        switch (usc.code) {
          case CBCD:
                adr = newbcd(usc.v.pbcd); c |= 0x0020; goto icv;
          case CSTR:
                adr = newstr(usc.v.pval); c |= 0x0020; goto icv;
          case IDENT:
                if (findcst(usc.v.pval,&a,&adr) == 2)
                        c |= 0x0020;
                else if (findvar(usc.v.pval,GenericNULL(BYTE),&adr,GenericNULL(TabSymb *),TRUE) == GenericNULL(BYTE),TRUE) {
                                erreur(USUAL,ermasm12); return (FALSE);
                     }
                     else c |= 0x0040;
icv:
                pcode(c); preg(reg); padr(adr); break;
          case DIESE:
                lexical();
                if (!recbincst(&adr)) {
                        erreur(USUAL,ermasm7); return (FALSE);
                }
                if (adr > 255) {
                        erreur(USUAL,ermasm8); return (FALSE);
                }
                reg2 = (BYTE) adr;
                c |= 0x0060; pcode(c); preg(reg); preg(reg2); break;
          default:
                erreur(USUAL,ermasm14); return (FALSE);
        }
        return (TRUE);
}                               /* geticvr */


static BOOL gtsicvr(code)
BYTE code;
{                               /* gtsicvr */
        BYTE    reg, c = code, *a = GenericNULL(BYTE);
        BINAIRE adr;

        lexical();
        if (recbincst(&adr)) goto icv;
        switch (usc.code) {
          case CBCD:
                adr = newbcd(usc.v.pbcd); c |= 0x0020; goto icv;
          case CSTR:
                adr = newstr(usc.v.pval); c |= 0x0020; goto icv;
          case IDENT:
                if (findcst(usc.v.pval,&a,&adr) == 2)
                        c |= 0x0020;
                else if (findvar(usc.v.pval,GenericNULL(BYTE),&adr,GenericNULL(TabSymb *),TRUE) == GenericNULL(BYTE)) {
                                erreur(USUAL,ermasm12); return (FALSE);
                     }
                     else c |= 0x0040;
icv:
                pcode(c); padr(adr); break;
          case DIESE:
                lexical();
                if (!recbincst(&adr)) {
                        erreur(USUAL,ermasm7); return (FALSE);
                }
                if (adr > 255) {
                        erreur(USUAL,ermasm8); return (FALSE);
                }
                reg = (BYTE) adr;
                c |= 0x0060; pcode(c); preg(reg); break;
          default:
                erreur(USUAL,ermasm14); return (FALSE);
        }
        return (TRUE);
}                               /* gtsicvr */


static BOOL getirv(code)
BYTE code;
{                               /* getirv */
        BYTE    reg, c = code;
        BINAIRE adr;

        lexical();
        if (recbincst(&adr)) {
                if (adr > 255) {
                        erreur(USUAL,ermasm14); return (FALSE);
                }
                pcode(code); pcode((BYTE) adr);
        }
        else switch (usc.code) {
          case IDENT:
                if (findvar(usc.v.pval,GenericNULL(BYTE),&adr,GenericNULL(TabSymb *),TRUE) == GenericNULL(BYTE)) {
                        erreur(USUAL,ermasm12); return (FALSE);
                }
                else c |= 0x0040;
                pcode(c); padr(adr); break;
          case DIESE:
                lexical();
                if (!recbincst(&adr)) {
                        erreur(USUAL,ermasm7); return (FALSE);
                }
                if (adr > 255) {
                        erreur(USUAL,ermasm8); return (FALSE);
                }
                reg = (BYTE) adr;
                c |= 0x0020; pcode(c); preg(reg); break;
          default:
                erreur(USUAL,ermasm14); return (FALSE);
        }
        return (TRUE);
}                               /* getirv */


static BOOL geterv(code)
BYTE code;
{                               /* geterv */
        BYTE    reg, c = code;
        BINAIRE adr;

        lexical();
        switch (usc.code) {
          case ETIQ:
                adr = refetiq(usc.v.pval,(((BINAIRE) adrimpl) + 1));
                goto ev;
          case IDENT:
                if (findvar(usc.v.pval,GenericNULL(BYTE),&adr,GenericNULL(TabSymb *),TRUE) == GenericNULL(BYTE)) {
                        erreur(USUAL,ermasm12); return (FALSE);
                }
                else c |= 0x0040;
ev:
                pcode(c); padr(adr); break;
          case DIESE:
                lexical();
                if (!recbincst(&adr)) {
                        erreur(USUAL,ermasm7); return (FALSE);
                }
                if (adr > 255) {
                        erreur(USUAL,ermasm8); return (FALSE);
                }
                reg = (BYTE) adr;
                c |= 0x0020; pcode(c); preg(reg); break;
          default:
                erreur(USUAL,ermasm14); return (FALSE);
        }
        return (TRUE);
}                               /* geterv */


static BOOL getrv(code)
BYTE code;
{                               /* getrv */
        BYTE    reg, c = code;
        BINAIRE adr;

        lexical();
        switch (usc.code) {
          case IDENT:
                if (findvar(usc.v.pval,GenericNULL(BYTE),&adr,GenericNULL(TabSymb *),TRUE) == GenericNULL(BYTE)) {
                        erreur(USUAL,ermasm12); return (FALSE);
                }
                else c |= 0x0010;
                pcode(c); padr(adr); break;
          case DIESE:
                lexical();
                if (!recbincst(&adr)) {
                        erreur(USUAL,ermasm7); return (FALSE);
                }
                if (adr > 255) {
                        erreur(USUAL,ermasm8); return (FALSE);
                }
                reg = (BYTE) adr; pcode(c); preg(reg); break;
          default:
                erreur(USUAL,ermasm14); return (FALSE);
        }
        return (TRUE);
}                               /* getrv */


static BOOL getir()
{                               /* getir */
        BINAIRE adr;

        lexical();
        if (recbincst(&adr)) {
                preg((BYTE) adr); return (TRUE);
        }
        else if (usc.code != DIESE) {
                erreur(USUAL,ermasm14); return (FALSE);
             }
             else {
                lexical();
                if (!recbincst(&adr)) {
                        erreur(USUAL,ermasm7); return (FALSE);
                }
                if (adr > 255) {
                        erreur(USUAL,ermasm8); return (FALSE);
                }
                preg((BYTE) adr);
             }
        return (TRUE);
}                               /* getir */


static BOOL sep()
/*      recherche du separateur d'arguments : virgule */
{                                       /* sep */
        lexical();
        if (usc.code != VIG) {
                erreur(USUAL,ermasm6); return (FALSE);
        }
        return (TRUE);
}                                       /* sep */

