/*
 *      Projet  : ABAL                  Copyright Amenesik / Sologic s.a. (c) 1990, 1995
 *      Module  : ATR
 *      Fichier : GENCODE.C
 *      Version : 2.2b
 *      Date    : 21/11/95
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Generation du T-code]
 *
 */

 /*
 * Mises a jour :
 * ------------
 * 18/07/90 : Mise en conformite avec les versions 1.2e / 1.3a / 1.4a
 * 10/09/90 : Mise en place definitive des formats I et H
 * 24/10/90 : Introduction de END.SEG
 * 12/12/90 : Remplacement du format I par le qualifieur I
 * ---------- Sortie 1.2g / 1.3d --------------------------------------
 * 26/12/91 : Suppression minuscules accentuees dans les sources
 * 02/03/92 : Genere une reference aux constantes sur ON TIMER
 *            Accepte des espaces dans les formats. Ex : (NZ 2)
 *	06/05/93 : Mise en place relocation variable externe dans les print
 *		        et ask
 *	07/06/93 : Correction code d'appel Pointeur de proc genclp	
 *	06/09/93 : Correction genaffectptfct : plus2 pour adresse descripteur
 *		        variable
 *	06/09/93 : genfmt ESC-FE desactive pour le moment
 *	06/09/93 : Prise en compte du ON LOCAL ERROR generg	
 * --------------------- 2.1c ------------------------------------
 *	27/05/94 : Relocation sur variable externe dans call indirect
 *		        adrimpl++ au lieu adrimpl += 2L
 *	01/06/94 : Segment nommes forward ESGW et non ESG voir gensgt()
 *	11/07/94 : sur PROC PTR et SEGMENT PTR : mettre une relocation sur ID	
 *	26/08/94 : correction suivi de registre sur genoper qui utilise +s
 *		        registres.
 *	--------------------- 2.1d -------------------------------------
 *	02/03/95 : Probleme sur format variable genffm : t est le type du
 *		        2eme argument pas de la variable a affecter
 *	21/11/95 : version dediee 2.1
 *  --------------------- 2.1f -------------------------------------
 *	17/12/98 : modification de gencreate, pour la syntaxe create a,b,c,d
 *
 *	25/08/99 : (#SP) Enhancement ATR 25: "OP BREAK".
 *	08/12/99 : (#OK) Bug ATR ?? fixed: bug in function OP.
 * 18/06/02 : (#OK) Bug ATR 71 fixed. Incorrect format in function PRINT.
 *	------------ 2.2b -------------------------------------------------
 * 20/11/02 : (#BG) Révision du END.USER et du END.PROC.
 */

/* Fichier de definition */
/* --------------------- */
#include "tr.h"
#include "fuser.h"
#include "syntaxe.h"
#include "tsymb.h"
#include "codes.h"
#include "tcode.h"
#include "abal.h"

#define SUIVI_REG
#define _GENCODE
#include "gencode.he"
#include "gencode.hs"



/*      generation d'instructions simples du langage    */
/*      --------------------------------------------    */

void gennew() { flg_new = (BYTE) 0x0080; }

void gen1tc(tc)
BYTE tc;
{ pcode(tc); adrimpl++; }


void genesc0(tc)
BYTE tc;
{ pcode(F_ESC); pcode(tc); adrimpl += 2L; }


void gengtogsb(tc,adr)

/*      branchement inconditionnel sur l'etiquette 'adr'
 */
BYTE tc;
char *adr;
{                                               /* gengoto */
        BINAIRE adref;

        pcode(tc); adrimpl++;
        adref = refetiq(adr,(BINAIRE) adrimpl);
        pbin(NOAT,adref); adrimpl += 2L;
}                                               /* gengoto */


void gendebjmr(gto,reg,adr)

/*      debut de generation de code pour un ON .. GOTO / GOSUB
 *      avec utilisation d'un registre d'index sur les etiquettes
 */
BINAIRE gto,reg;
char    *adr;
{                                               /* gendebjmr */
        BYTE codop;
        BINAIRE adref;

	genpopreg(reg);
        pcode(F_ESC);
        if (gto == 0)
                codop = F_JMR;
        else
                codop = F_GSR;
        pcode(codop); pbyte(NOAT,(BYTE) reg); adrimpl += 3L;
        adref = refetiq(adr,(BINAIRE) adrimpl);
        pbin(NOAT,adref); adrimpl += 2L;
}                                               /* gendebjmr */


void genetqjmr(adr)

/*      mise en place d'une adresse de reference pour un ON .. GOTO / GOSUB
 *      avec utilisation d'un registre d'index sur les etiquettes
 */
char    *adr;
{                                               /* genetqjmr */
        BINAIRE adref;

        adref = refetiq(adr,(BINAIRE) adrimpl);
        pbin(NOAT,adref); adrimpl += 2L;
}                                               /* genetqjmr */


void genres(flgetiq,adr)

/*      fin de traitement d'erreur : instruction RESUME avec une
 *      etiquette de branchement facultative.
 */
BOOL flgetiq;
char *adr;
{                                               /* genres */
        BYTE code;
        BINAIRE adref;

        code = F_RES;
        if (flgetiq) code += 7;
        pcode(code); adrimpl++;
        if (flgetiq) {
                adref = refetiq(adr,(BINAIRE) adrimpl);
                pbin(NOAT,adref); adrimpl += 2L;
        }
}                                               /* genres */


void gentim(fn,tdel,vdel,adr)

/*      generation du code pour la gestion du TIMER
 *      en entree :     fn = 0 pour TIMER OFF
 *                      fn = 1 pour ON TIMER GOTO
 *                      fn = 2 pour ON TIMER GOSUB
 *                      (tdel,vdel) decrit la valeur du delai
 *                      adr est l'etiquette de branchement associee
 */
int     fn;
BYTE    tdel;
BINAIRE vdel;
char    *adr;
{                                               /* gentim */
        BYTE    arg;
        BINAIRE adref;

	if ( tdel == 3 )
		genpopreg(vdel);

        pcode(F_TIM); adrimpl++;
        if (fn == 0) {
                pbyte(NOAT,0); adrimpl++;
        }
        else {
                arg = (tdel << 5) | ((BYTE) fn);
                pbyte(NOAT,arg); adrimpl++;
                switch (tdel) {
                   case 0:      /* valeur immediate */
                   case 1:      /* constante */
                        if (notaprog) refobj(FALSE,vdel,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                        pbin(NOAT,vdel); adrimpl += 2L; break;
                   case 2:      /* variable */
                        if ( (notaprog && (!islocal(vdel))) || IsExtVar(2,vdel) ) 	
                                refobj(TRUE,vdel,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                        pbin(NOAT,vdel); adrimpl += 2L; break;
                   case 3:      /* registre */
                        pbyte(NOAT,(BYTE) vdel); adrimpl++;
                }
                adref = refetiq(adr,(BINAIRE) adrimpl);
                pbin(NOAT,adref); adrimpl += 2L;
        }
}                                               /* gentim */


void genwhen (brk,typ,adr)

/*      generation du code pour un enonce WHEN
 *      typ = 0 / RAZ, 1 / DCL, 2 / FALSE, 4 / STOP, 8 / HALT, 16 / START
 *	      40 / ABORT, 60 / GOTO, 61 / GOSUB, 62 / CALL ID, 63 / CALL PT
 */
BINAIRE brk;
int typ;
char *adr;
{                                               /* genwhen */
	TabProc *dproc;
        BINAIRE adref;

        pcode(F_WHN); adrimpl++;
        pbyte(NOAT,(BYTE) typ); adrimpl++;
	switch ( typ ) {
		case 0x60:
		case 0x61:
		case 1:
	                adref = refetiq(adr,(BINAIRE) adrimpl);
        	        pbin(NOAT,adref); adrimpl += 2L;
			break;
		case 0x62:
			dproc = (TabProc *)adr;
			//Pour reloger le extern eventcall
			if (dproc->ext || notaprog)
				refproc(dproc,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);

			lienproc(dproc,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
		        pbin(NOAT,dproc->ads); /* adresse descripteur proc*/
			adrimpl += 2L;
			break;
		case 0x63:
			if ( (notaprog) || IsExtVar(2,brk) )
				refobj(TRUE,brk,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
		        pbin(NOAT,brk); /* adresse descripteur var*/
			adrimpl += 2L;
			break;
        }
        if ((adr != GenericNULL(char)) && (*adr == '$') && (brk == FALSE)) {
                /* etiquette speciale => NEXT */
                defetiq(adr,(BINAIRE) adrimpl);
	}
}                                               /* genwhen */


void gensgt(seg,t,v)

/*      generation du code d'appel d'un segment
 */
TabSeg *seg;
BYTE t;
BINAIRE v;
{                               /* gensgt */
        BYTE codop;

	if ( t == 3 )
		genpopreg(v);

        if ( (seg == GenericNULL(TabSeg)) && ((t != 0) || (v <= 255))  ) {

        pcode(F_ESC);
        codop = F_SGT;
        switch(t) {
           case 0:      /* valeur immediate */
                pcode(codop); pbyte(NOAT,(BYTE) v); adrimpl += 3L; break;
           case 2:      /* variable */
                codop |= 0x40; pcode(codop); adrimpl += 2L;
                if ( (notaprog && (!islocal(v))) ||
		     IsExtVar(2,v) )
			refobj(TRUE,v,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                pbin(NOAT,v); adrimpl += 2L; break;
           case 3:      /* registre */
                codop |= 0x20; pcode(codop); pbyte(NOAT,(BYTE) v); adrimpl += 3L;
        }
        } else {
                pcode(F_ESC);
                if ( v == 0xFFFF ) {
                        codop = F_SGW;
                        pcode(F_SGW);

                        if (seg->ext)   /* reference a un segment externe */
                                refseg(seg,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                        if (notaprog)
                                lienseg(seg,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                        pbin(NOAT,v);
                        adrimpl += 4L;
                } else {
                        if ( v < 255 ) {
                                codop = F_SGT;
                                pcode(F_SGT);
                                pbyte(NOAT, (BYTE)v);
                                adrimpl += 3L;
                        } else {
                                codop = F_SGW;
                                pcode(F_SGW);
                                pbin(NOAT,v);
                                adrimpl += 4L;
                        }
			if (seg != GenericNULL(TabSeg)) {
                        	if (seg->ext)   /* reference a une procedure externe */
                                	nb_refsext++; /* pas de reloc dans ce cas */
			}
                }
        }
}                               /* gensgt */


void generreur(t,v)

/*      generation du code remontee d'erreur
 */
BYTE t;
BINAIRE v;
{                               /* generreur */
        BYTE codop;

	if ( t == 3 )
		genpopreg(v);

        pcode(F_ESC);
        codop = F_RTE;
        switch(t) {
           case 0:      /* valeur immediate */
                pcode(codop); pbin(NOAT, v); adrimpl += 4L; break;
           case 2:      /* variable */
                codop |= 0x04; pcode(codop); adrimpl += 2L;
                if ( (notaprog && (!islocal(v))) ||
		     IsExtVar(2,v) )
			 refobj(TRUE,v,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                pbin(NOAT,v); adrimpl += 2L; break;
           case 3:      /* registre */
                codop |= 0x06; pcode(codop); pbyte(NOAT,(BYTE) v); adrimpl += 3L;
        }
}                               /* generreur */


void	gentrace( BINAIRE f, BINAIRE nbarg, BYTE targ[], BINAIRE  varg[], BINAIRE channel )
{
        BYTE desc=0;
	BINAIRE	i;
	BINAIRE	pending=0;
	BINAIRE	argjmp=0;

        pcode(F_CLF); pbyte(NOAT,NumFn[f]);	adrimpl += 2L;

	if (( f == 104 ) || ( f == 105 )) {
		/* Trace function accelerator */
		/* -------------------------- */
		pbin(NOAT,channel);
		for( i=0; i < nbarg; i++ ) {
			if ( targ[i] == 3 )
				argjmp++;
			else	argjmp+= 2;
			}
		argjmp+=((nbarg/2)+(nbarg % 2 ? 1 : 0 ));
		pbin(NOAT,argjmp);
		adrimpl += 4L;
		}

	for( i=0; i < nbarg; i++ ) {
		if (!( i & 1 )) {
			if ((i+1) < nbarg)
			        desc = ((targ[i] << 5) | 0x0010);
			else	desc = ((targ[i] << 5));
			pending=1;
			}
		else 	{
			if ((i+1) < nbarg)
				desc |= ((targ[i] << 1) | 0x0001);
			else	desc |= ((targ[i] << 1));
		        pbyte(NOAT,desc); adrimpl += 1L;
			pending = 0;
			}
		}

	if ( pending ) {
	        pbyte(NOAT,desc); adrimpl += 1L;
		pending = 0;
		}
	for (i=0; i < nbarg; i++ ) {
		if ( targ[i]  == 3 ) {
			pbyte(NOAT,(BYTE) varg[i]); adrimpl++;
			}
		else if (notaprog && (targ[i] == 1)) {
			/* constante */
			refobj(FALSE,varg[i],fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
			}
		else if ((notaprog && (targ[i] == 2) 
			&& (!islocal(varg[i]))) 
                        || IsExtVar(targ[i],varg[i]) ) {
			refobj(TRUE,varg[i],fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
			}
                pbin(NOAT,varg[i]); 
		adrimpl += 2L;
        	}
	return;
}


/*      generation du code pour une instruction WAIT, MASK, READMEM ou RESTORE
 *      qui sont en fait des fonctions "cachees" de l'executeur dont la
 *      particularite est de ne pas avoir de resultat explicite (VOID)
 *      ver15 : HOTKEY, LANG, INITGLOBAL, INITLOCAL en plus
 *              ASKCOLOR et EVENT necessite 2 parametres !!!
 *		et ASKATB
 *	genfnspe : voir genclf(FALSE,...
 */

void genaffn(fnt,t1,t2,v1,v2)

/*      generation du code pour une instruction DATE()= ... ou KBF()= ...
 *      qui sont en fait des fonctions "cachees" de l'executeur dont la
 *      particularite est de ne pas avoir de resultat explicite (VOID)
 *      mais qui ont deux arguments en entree.
 */
int fnt;
BYTE t1,t2;
BINAIRE v1,v2;
{                                               /* genaffn */
        BYTE desc;

	if ( t1 == 3 )
		genpopreg(v1);
	if ( t2 == 3 )
		genpopreg(v2);

        pcode(F_CLF); pbyte(NOAT,NumFn[fnt]);

        desc = ((t1 << 5) | 0x10) | (t2 << 1);
        pbyte(NOAT,desc); adrimpl += 3L;
        if (t1 == 3) { /* operande registre */
                pbyte(NOAT,(BYTE) v1); adrimpl++;
        }
        else {
                        if (notaprog && (t1 == 1)) /* constante */
                                refobj(FALSE,v1,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
   	             	else if ( (notaprog && (t1 == 2) && (!islocal(v1))) || /* variable */
	     			IsExtVar(t1,v1) )
		 		refobj(TRUE,v1,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                pbin(NOAT,v1); adrimpl += 2L;
        }
        if (t2 == 3) { /* operande registre */
                pbyte(NOAT,(BYTE) v2); adrimpl++;
        }
        else {
                        if (notaprog && (t2 == 1)) /* constante */
                                refobj(FALSE,v2,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
   	             	else if ( (notaprog && (t2 == 2) && (!islocal(v2))) || /* variable */
	     			IsExtVar(t2,v2) )
		 		refobj(TRUE,v2,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                pbin(NOAT,v2); adrimpl += 2L;
        }
}                                               /* genaffn */


void genffm(v,t,f,adfmt)

/*      generation du code pour un appel a la fonction FM
 */
BINAIRE v,f;
BYTE t;
char *adfmt;
{                                               /* genffm */
        BYTE fnt;

	if ( t == 3 )
		genpopreg(v);

        pcode(F_CLF);
        if (t == 0) fnt = 0x7A;         /* fonction FM immediate */
        else if (t == 2) fnt = 0x5A;    /* fonction FM sur variable */
        else if (t == 3) fnt = 0x6A;    /* fonction FM sur registre */
        pbyte(NOAT,fnt); adrimpl += 2L;
	if ( (notaprog && (!islocal(v))) || /* variable */
		IsExtVar(2,v) )		/* 02/03/95 : remplacer t par 2 */
		refobj(TRUE,v,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
        pbin(NOAT,v);
        adrimpl += 2L;
        if (t == 0)             /* format "direct" */
                genfmt(1,adfmt);
        else if (t == 2) {      /* argument variable */
		if ( (notaprog && (!islocal(f))) || /* variable */
			IsExtVar(t,f) )
			refobj(TRUE,f,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                pbin(NOAT,f); adrimpl += 2L;
        }
        else if (t == 3) {      /* argument registre */
                pbyte(NOAT,(BYTE) f); adrimpl++;
        }
}                                               /* genffm */


void genesc1(tc,t,v)

/*      generation du code d'une instruction PAUSE
 */
BYTE tc;
BYTE t;
BINAIRE v;
{                                               /* genpause */
        BYTE codop;

	if ( t == 3 )
		genpopreg(v);

        pcode(F_ESC);
        codop = tc;
        switch(t) {
           case 0:      /* valeur immediate */
                pcode(codop); pbin(NOAT,v); adrimpl += 4L; break;
           case 1:      /* constante */
                codop |= 0x20; pcode(codop); adrimpl += 2L;
                if (notaprog) refobj(FALSE,v,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                pbin(NOAT,v); adrimpl += 2L; break;
           case 2:      /* variable */
                codop |= 0x40; pcode(codop); adrimpl += 2L;
		if ( (notaprog && (!islocal(v))) || /* variable */
			IsExtVar(2,v) )
			refobj(TRUE,v,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                pbin(NOAT,v); adrimpl += 2L; break;
           case 3:      /* registre */
                codop |= 0x60; pcode(codop); pbyte(NOAT,(BYTE) v); adrimpl += 3L;
        }

}                                               /* genesc1 */


void genop(top,vop,adr)

/*      generation du code pour une instruction OP
 *      si adr est une etiquette speciale, c'est que le branchement se
 *      fait sur l'instruction suivante (cas du NEXT).
 */
BYTE top;
BINAIRE vop;
char *adr;
{                                               /* genop */
		BINAIRE adref;
#ifdef __ATR22__
/* #SP: 25/08/99 (begin) */
		BYTE	is_break=0;
/* #SP: 25/08/99 (end) */
	
/* #OK: 08/12/99 (begin) */
	if (fin_itere != 0)
/* #OK: 08/12/99 (end) */
/* #SP: 25/08/99 (begin) */
		if (!Xstrcmp(fin_itere,adr)) is_break=1;
/* #SP: 25/08/99 (end) */
#endif

	if ( top == 3 )
		genpopreg(vop);

        if (top != 0) { /* il y a une reception !! */
                if (top == 2) { /* reception = variable */
                        pcode(F_TPC); adrimpl++;
		if ( (notaprog && (!islocal(vop))) || /* variable */
			IsExtVar(top,vop) )
			refobj(TRUE,vop,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                        pbin(NOAT,vop); adrimpl += 2L;
                }
                else { /* reception = registre */
                        pcode(F_TPCR); pbyte(NOAT,(BYTE) vop); adrimpl += 2L;
                }
        }
        else {
                pcode(F_TPC); pbin(NOAT,0); adrimpl += 3L;
        }
        adref = refetiq(adr,(BINAIRE) adrimpl);
        pbin(NOAT,adref); adrimpl += 2L;
/* #SP: 25/08/99 (begin) */
#ifndef __ATR22__
if (*adr == '$') {
#else
if (*adr == '$' && !is_break) {
#endif
    /* Do not define label address for "OP break" */
/* #SP: 25/08/99 (end) */
                /* etiquette speciale => NEXT */
                defetiq(adr,(BINAIRE) adrimpl);
        }
}                                               /* genop */


void generg(local,top,vop,adr)

/*      generation du code pour un 'ON ERROR GOTO'
	et ON LOCAL ERROR GOTO
 */
BOOL local;
BYTE top;
BINAIRE vop;
char *adr;
{                                               /* generg */
        BINAIRE adref;

	if ( top == 3 )
		genpopreg(vop);

        if (top == 2) {         /* reception = variable */
		if ( local == TRUE ) {
                	pcode(F_LERG);
		} else	{
                	pcode(F_ERG);
		}
		adrimpl++;
		if ( (notaprog && (!islocal(vop))) || /* variable */
			IsExtVar(top,vop) )
			refobj(TRUE,vop,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                pbin(NOAT,vop); adrimpl += 2L;
        }
        else { /* reception = registre */
		if ( local == TRUE ) {
                	pcode(F_LERGR);
		} else {
                	pcode(F_ERGR);
		}
		pbyte(NOAT,(BYTE) vop); adrimpl += 2L;
        }
        adref = refetiq(adr,(BINAIRE) adrimpl);
        pbin(NOAT,adref); adrimpl += 2L;
}                                               /* generg */


void genclp(dproc,nbargs,top,vop,aderr)

/*      generation du code d'appel a une procedure, dont l'adresse du
 *      descripteur est 'adesc', le nombre d'arguments est 'nbargs',
 *      et les arguments effectifs sont donnes par top[i]-vop[i]
 *	
 *	si dproc == NULL --> Appel call variable
 *	top[nbargs],vop[nbargs] : reference variable d'erreur
 *	top[nbargs+1,vop[nbargs+1] : reference a l'adresse pointeur de proc
 */
TabProc *dproc;
BINAIRE nbargs,vop[];
BYTE    top[];
char *aderr;
{                                               /* genclp */
        BINAIRE i;
        BOOL    full;
        BYTE    typ;
	BINAIRE adref;


	/* Arguments */
	for ( i=0; i < nbargs; i++ ) {
		if ( top[i] == 3 )
			genpopreg(vop[i]);
	}
	/* Erreur */
	if ( (top[nbargs] != 0) && (top[nbargs]==3) )
		genpopreg(vop[nbargs]);
	/* CLP variable */
	if ( (dproc == GenericNULL(TabProc)) && (top[nbargs+1]==3) )
		genpopreg(vop[nbargs+1]);

	if ( top[nbargs] != 0 ) {
		/* Suivi erreur */

	        pcode(F_OLE);
		adrimpl++;

		/* variable ou registre */
		i = nbargs;
		if ( top[i] == 3 ) {
                        pbyte(NOAT,(BYTE) vop[i]); adrimpl++;
		} else {
			if ( (notaprog && (top[i] == 2) && (!islocal(vop[i])) )
 			   || IsExtVar(top[i],vop[i]) )
				refobj(TRUE,vop[i],fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                        pbin(NOAT,vop[i]); adrimpl += 2L;
		}

		/* Etiquette */
		if (aderr != GenericNULL(char)) {
	               adref = refetiq(aderr,(BINAIRE) adrimpl);
	               pbin(NOAT,adref); adrimpl += 2L;
		} else {
			pbin(NOAT,0); adrimpl += 2L;
		}

		/* Si etiquette NEXT : generation d'un STI var,0 */
	        if ((aderr != GenericNULL(char)) && (*aderr == '$')) {
			putvar(0,0,vop[i]);
        	}
	}

	if ( dproc != GenericNULL(TabProc) ) {
		pcode(F_ESC);
		pcode(F_CLP);
		adrimpl += 2L;
		/* Direct Integer Procedure Adresse */
		/* -------------------------------- */
		typ = 0;
		}
	else {
		pcode(F_ESC);
		pcode(F_CLP);
		adrimpl += 2L;
		typ = top[nbargs+1] << 5;
		/*
		 *  This is utter rubbish (#ijm 11/07/2002)
		 *  --------------------------------------
		 * Cas appel autre que Proc : User, Code, Segment
		 * pcode(F_EDF);
		 * adrimpl++;
		 */
	}

	full = FALSE;


        if (nbargs != 0) {      /* chaine descriptive des arguments */

           for (i = 0; i < nbargs; i++) {
                if (full) {
                        typ |= 1; pbyte(NOAT,typ); adrimpl++;
                        typ = (top[i] << 5); full = FALSE;
                }
                else {
                        typ |= (top[i] << 1)  | 0x0010;
                        full = TRUE;
                }
                top[i] &= 3; /* annuler le flag 'modification' */
           }
        }
        pbyte(NOAT,typ); adrimpl++;

	if ( dproc != GenericNULL(TabProc) ) {
	        if (dproc->ext)         /* reference a une procedure externe */
        	        refproc(dproc,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                	lienproc(dproc,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);

	        pbin(NOAT,dproc->ads); /* adresse descripteur */
	} else {
	        /* Attention reference a un objet variable */
		/* traitement a faire */

		if ( top[nbargs+1] == 2 ) { /* variable */
/* 27/05/94 */		if ( (notaprog && (!islocal(vop[nbargs+1]))) ||
			     IsExtVar(top[nbargs+1],vop[nbargs+1]) )
				refobj(TRUE,vop[nbargs+1],fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
		        pbin(NOAT,vop[nbargs+1]); /* adresse descripteur */
		} else {
		        pbyte(NOAT,(BYTE)vop[nbargs+1]); /* adresse registre */
			adrimpl--;
		}
	}
	adrimpl += 2L;

        for (i = 0; i < nbargs; i++) { /* mise en place des arguments */
                if (top[i] != 3) {
                        /* valeur immediate , constante ou variable */
                                if (notaprog && (top[i] == 1)) /* constante */
                                        refobj(FALSE,vop[i],fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
				else if ( (notaprog && (top[i] == 2) && (!islocal(vop[i]))) || /* variable */
					IsExtVar(top[i],vop[i]) )
					refobj(TRUE,vop[i],fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                        pbin(NOAT,vop[i]); adrimpl += 2L;
                }
                else {  /* registre */
                        pbyte(NOAT,(BYTE) vop[i]); adrimpl++;
                }
        }

        if ((aderr != GenericNULL(char)) && (*aderr == '$')) {
                /* etiquette speciale => NEXT */
                defetiq(aderr,(BINAIRE) adrimpl);
	        pcode(F_LEP | 0x80); adrimpl++;
	} else {
		if ( top[nbargs] != 0 ) {
		        pcode(F_LEP); adrimpl++;
		}
	}
}                                               /* genclp */


void genclsuc(nbargs,top,vop,aderr)

/* generation du code d'appel indirect a un segment, une fct B.D.A,
   et un espace de code quelconque : PROC, SEGMENT, USER, CODE
   generation du code d'appel a une procedure, dont le nombre d'arguments
   est 'nbargs', et les arguments effectifs sont donnes par top[i]-vop[i]
   top[nbargs],vop[nbargs] : reference variable d'erreur
   top[nbargs+1,vop[nbargs+1] : reference a l'adresse pointeur de proc
 */
BINAIRE nbargs,vop[];
BYTE    top[];
char *aderr;
{                                               /* genclsuc */
        BINAIRE i;
        BOOL    full;
        BYTE    typ;
	BINAIRE adref;


	/* Arguments */
	for ( i=0; i < nbargs; i++ ) {
		if ( top[i] == 3 )
			genpopreg(vop[i]);
	}
	/* Erreur */
	if ( (top[nbargs] != 0) && (top[nbargs]==3) )
		genpopreg(vop[nbargs]);

	/* Passage par registre : le registre est il disponible ? */
	if ( top[nbargs+1] == 3 )
		genpopreg(vop[nbargs+1]);

	if ( top[nbargs] != 0 ) {
		/* Suivi erreur */

	        pcode(F_OLE);
		adrimpl++;

		/* variable ou registre */
		i = nbargs;
		if ( top[i] == 3 ) {
                        pbyte(NOAT,(BYTE) vop[i]); adrimpl++;
		} else {
			if ( (notaprog && (top[i] == 2) && (!islocal(vop[i])) )
 			   || IsExtVar(top[i],vop[i]) )
				refobj(TRUE,vop[i],fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                        pbin(NOAT,vop[i]); adrimpl += 2L;
		}

		/* Etiquette */
		if (aderr != GenericNULL(char)) {
	               adref = refetiq(aderr,(BINAIRE) adrimpl);
	               pbin(NOAT,adref); adrimpl += 2L;
		} else {
			pbin(NOAT,0); adrimpl += 2L;
		}

		/* Si etiquette NEXT : generation d'un STI var,0 */
	        if ((aderr != GenericNULL(char)) && (*aderr == '$')) {
			putvar(0,0,vop[i]);
        	}
	}

	pcode(F_EDF);
	adrimpl++; /* 27/05/94 */

	/* Descripteur de code : variable ou constante ou registre */
	typ = top[nbargs+1] << 5;

	full = FALSE;


        if (nbargs != 0) {      /* chaine descriptive des arguments */

           for (i = 0; i < nbargs; i++) {
                if (full) {
                        typ |= 1; pbyte(NOAT,typ); adrimpl++;
                        typ = (top[i] << 5); full = FALSE;
                }
                else {
                        typ |= (top[i] << 1)  | 0x0010;
                        full = TRUE;
                }
                top[i] &= 3; /* annuler le flag 'modification' */
           }
        }
        pbyte(NOAT,typ); adrimpl++;

        /* Attention reference a un objet variable */
	/* traitement a faire */

	if ( top[nbargs+1] == 2 ) {
		if ( (notaprog && (top[nbargs+1] == 2) && (!islocal(vop[nbargs+1]))) || /* variable */
					IsExtVar(top[nbargs+1],vop[nbargs+1]) )
			refobj(TRUE,vop[nbargs+1],fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
	        pbin(NOAT,vop[nbargs+1]); /* adresse descripteur */
	} else {
	        pbyte(NOAT,(BYTE)vop[nbargs+1]); /* adresse registre */
		adrimpl--;
	}
	adrimpl += 2L;

        for (i = 0; i < nbargs; i++) { /* mise en place des arguments */
                if (top[i] != 3) {
                        /* valeur immediate , constante ou variable */
                                if (notaprog && (top[i] == 1)) /* constante */
                                        refobj(FALSE,vop[i],fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
				else if ( (notaprog && (top[i] == 2) && (!islocal(vop[i]))) || /* variable */
					IsExtVar(top[i],vop[i]) )
					refobj(TRUE,vop[i],fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                        pbin(NOAT,vop[i]); adrimpl += 2L;
                }
                else {  /* registre */
                        pbyte(NOAT,(BYTE) vop[i]); adrimpl++;
                }
        }

        if ((aderr != GenericNULL(char)) && (*aderr == '$')) {
                /* etiquette speciale => NEXT */
                defetiq(aderr,(BINAIRE) adrimpl);
	        pcode(F_LEP | 0x80); adrimpl++;
	} else {
		if ( top[nbargs] != 0 ) {
		        pcode(F_LEP); adrimpl++;
		}
	}
}                                               /* genclsuc */


void genlibproc(dproc,top,vop)

/*      generation du code d'appel de liberation d'une procedure
 */
TabProc *dproc;
BYTE    top;
BINAIRE vop;
{                                               /* genlibproc */

	if ( top == 3 )
		genpopreg(vop);

	if ( top == 0 ) {
		pbyte(NOAT,0x00); adrimpl++;	/* #BG 20/11/02 au lieu de adrimpl += 3L */
		if (dproc->ext)         /* reference a une procedure externe */
			refproc(dproc,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);

		lienproc(dproc,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);

		pbin(NOAT,dproc->ads); adrimpl += 2L; /* adresse descripteur */
	} else {
		pbyte(NOAT,(BYTE)(top << 5)); adrimpl++;	/* #BG 20/11/02 au lieu de adrimpl += 3L */
		if (top == 3) { /* operande registre */
			pbyte(NOAT,(BYTE) vop); adrimpl++;
		}
		else {
			if (notaprog && (top == 1)) /* constante */
				refobj(FALSE,vop,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
			else if ( (notaprog && (top == 2) &&
				(!islocal(vop))) || IsExtVar(top,vop) ) /* variable */
			refobj(TRUE,vop,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
			pbin(NOAT,vop); adrimpl += 2L;
		}
	}
}                                               /* genlibproc */


void genlibseg(dseg,top,vop)

/*      generation du code d'appel de liberation d'une procedure
 */
TabSeg *dseg;
BYTE    top;
BINAIRE vop;
{                                               /* genlibseg */
	if ( top == 3 )
		genpopreg(vop);

	pcode(F_CLF); pbyte(NOAT,NumFn[89]);

	if ( dseg != GenericNULL(TabSeg) ) {
		pbyte(NOAT,0x20); adrimpl += 3L;
		if (dseg->ext)         /* reference a un seg externe */
			refseg(dseg,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);

		lienseg(dseg,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);

		pbin(NOAT,dseg->ads); adrimpl += 2L; /* adresse descripteur */
	} else {
		pbyte(NOAT,(BYTE)(top << 5)); adrimpl += 3L;
		if (top == 3) {
			/* operande registre */
			pbyte(NOAT,(BYTE) vop); adrimpl++;
		} else if (top == 0) {
			/* valeur immediate */
			pbin(NOAT,vop); adrimpl += 2L;
		}
		else {
			if (notaprog && (top == 1)) /* constante */
				refobj(FALSE,vop,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
			else if ( (notaprog && (top == 2) && (!islocal(vop))) || IsExtVar(top,vop) ) /* variable */
				refobj(TRUE,vop,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
			pbin(NOAT,vop); adrimpl += 2L;
		}
	}
}                                               /* genlibseg */


void genlibuser(no)

/*      generation du code d'appel de liberation d'une bibliotheque
 */
BYTE no;
{                                               /* genlibuser */

        /* Pose le code fonction et le numero de bibliotheque
         * et genere une carte de relocation pour ce numero
         * afin de permettre une fusion des biblis communes
         * a l'edition des liens
         */
        pcode(F_CLF); pbyte(NOAT,NumFn[87]);
        pbyte(NOAT,0x00); adrimpl += 3L;
        refrt(no,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
        pbin(NOAT,(BINAIRE) no);
        adrimpl += 2L;	/* #BG 20/11/02 au lieu de adrimpl++ */
}                                               /* genlibuser */


void genaffectptsegnum(top,vop,adrvar)
BYTE top;
BINAIRE vop;
BINAIRE adrvar;
{						/* genaffectptsegnum */
DCLInfo dcl;
BINAIRE plus = 0;
BINAIRE plus2 = 0;

	if ( top == 3 )
		genpopreg(vop);

	dcl.adrdesc = adrvar;
	/* calcul de la longueur de la variable de desc :vop */
	GetDCLTable(&dcl);

	if ( (dcl.ptr) && (!(dcl.tptr & 0x02)))
		plus2 = 2;

	if ( dcl.tptr & 0x02 )
		plus = 2;

        pcode(F_STO); adrimpl++;
       	pbin(NOAT,9); adrimpl += 2L;		/* type */
       	pbin(NOAT,adrvar+6+plus); adrimpl += 2L;

        pcode(F_STO); adrimpl++;
       	pbin(NOAT,0); adrimpl += 2L;		/* high */
       	pbin(NOAT,adrvar+10+plus*2+plus2); adrimpl += 2L;

	putvar(top,vop,adrvar+14+plus*3+plus2*2); /* low */

}						/* genaffectptsegnum */


void genaffectptfct(ptdesc,type,high,low,adrvar)
BYTE *ptdesc;
BINAIRE type;
BINAIRE high;
BINAIRE low;
BINAIRE adrvar;
{						/* genaffectptfct */
DCLInfo dcl;
BINAIRE plus = 0;
BINAIRE plus2 = 0;

	dcl.adrdesc = adrvar;
	/* calcul de la longueur de la variable de desc :vop */
	GetDCLTable(&dcl);

	if ( (dcl.ptr) && (!(dcl.tptr & 0x02)))
		plus2 = 2;

	if ( dcl.tptr & 0x02 )
		plus = 2;



	if ( type != 5 ) {
	        pcode(F_STO); adrimpl++;
        	pbin(NOAT,type); adrimpl += 2L;
        	pbin(NOAT,adrvar+6+plus); adrimpl += 2L;

	        pcode(F_STO); adrimpl++;
        	pbin(NOAT,high); adrimpl += 2L;
        	pbin(NOAT,adrvar+10+plus*2+plus2); adrimpl += 2L;

	        pcode(F_STO); adrimpl++;
	}

	switch ( type ) {
		case 5: /* Proc ptr */
			{ TabProc *dproc;
			  BYTE top;
			  BINAIRE vop;
				top = 0;
				vop = low;
				genclf(FALSE,97,1,2,adrvar,&top,&vop,GenericNULL(BYTE));
				dproc = ( TabProc *) ptdesc;
				/* reference a une procedure externe */
			        if (dproc->ext)   
			                refproc(dproc,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
		                lienproc(dproc,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
			}
			break;
		case 9: /* Segment ptr */
			{ TabSeg *dseg;
				dseg = ( TabSeg *) ptdesc;
				/* reference a un segment externe */
				if ( low == 0xFFFF ) {
	                        	if (dseg->ext)
                                		refseg(dseg,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
	                        	if (notaprog)
        	                        	lienseg(dseg,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
				}
			}
			break;
		case 11: /* User ptr */
			{ Tbusr * dusr;
				dusr = ( Tbusr *) ptdesc;
				/* A priori probleme :  car prevu pour un BYTE */
			        refrt((BYTE)dusr->nort,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
			}
			break;
	}
	/* Procedure externe / Segment externe */
	/* Relocation */
	/* Fonction user */
	if ( type != 5 ) {
		pbin(NOAT,low); adrimpl += 2L;
        	pbin(NOAT,adrvar+14+plus*3+plus2*2); adrimpl += 2L;
	}
}						/* genaffectptfct */


void genfuser(fct,tres,vres,top,vop,nbreel)

/*      generation du code d'appel a une fonction utilisateur, dont
 *      le descripteur est pointe par 'fct',
 *      les arguments effectifs sont donnes par top[i]-vop[i], et le resultat
 *      est range dans tres-vres.
 *      Le nombre d'arguments reel est donne par nbreel
 */
Tbusr   *fct;
BYTE    tres,top[];
BINAIRE vres,vop[];
BINAIRE nbreel;
{                                               /* genfuser */
        BINAIRE i,nbargs;
        BOOL    full;
        BYTE    typ;
        BYTE    topc;

	for (i=0; i<nbreel; i++ ) {
		topc = top[i] & 0x3;
		if ( topc == 3 )
			genpopreg(vop[i]);
	}

        /* Pose le code fonction et le numero de bibliotheque
         * et genere une carte de relocation pour ce numero
         * afin de permettre une fusion des biblis communes
         * a l'edition des liens
         */
        pcode(F_LDF); adrimpl++;
        refrt((BYTE)fct->nort,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
        pbyte(NOAT,(BYTE)fct->nort);
        adrimpl++;

        /* Les fonctions sans resultat, ou avec resultat de type
         * chaine ou BCD sont traitees de la meme maniere. Pour
         * les deux dernieres, le resultat est passe comme premier
         * argument
         */
        if ((fct->tres == TVOID) || (fct->tres == TSTR) ||
            (fct->tres == TBCD)) {
                typ = 0;
                full = FALSE;
        }
        else {
                typ = (tres << 5) | 0x0010 | 0x0080;
                full = TRUE;
        }

        nbargs = nbreel;

        /* Pose les descripteurs des arguments */
        if (nbargs != 0)
           for (i = 0; i < nbargs; i++) {
                if (full) {
                        typ |= 1; pbyte(NOAT,typ); adrimpl++;
                        typ = (top[i] << 5); full = FALSE;
                }
                else {
                        typ |= (top[i] << 1)  | 0x0010;
                        full = TRUE;
                }
           }
        pbyte(NOAT,typ); adrimpl++;

        /* Pose l'eventuel descripteur du resultat.
         * Si celui-ci existe, il s'agit obligatoirement
         * d'un registre ou d'une variable
         */
        if ((fct->tres != TVOID) && (fct->tres != TSTR)
            && (fct->tres != TBCD)) {
                if (tres != 3) {        /* forcement une variable */
			if ( (notaprog && (!islocal(vres))) || /* variable */
				IsExtVar(tres,vres) )
				refobj(TRUE,vres,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                        pbin(NOAT,vres); adrimpl += 2L;
                }
                else {
                        pbyte(NOAT,(BYTE) vres); adrimpl++; /* registre */
                }
        }

        /* Pose le numero de fonction */
        pbin(NOAT,fct->nofct); adrimpl+=2L;

        /* Met en place les arguments d'appel */
        for (i = 0; i < nbargs; i++) {
                topc = top[i] & 0x3;
                if (topc != 3) {
                        /* valeur immediate , constante ou variable */
                                if (notaprog && (topc == 1)) /* constante */
                                        refobj(FALSE,vop[i],fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
				else if ( (notaprog && (topc == 2) && (!islocal(vop[i]))) || /* variable */
					IsExtVar(topc,vop[i]) )
					refobj(TRUE,vop[i],fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                        pbin(NOAT,vop[i]); adrimpl += 2L;
                }
                else {  /* registre */
                        pbyte(NOAT,(BYTE) vop[i]); adrimpl++;
                }
        }
}                                               /* genfuser */


void genclf(nores,fnt,nbargs,tres,vres,top,vop,psuc_desc)

/*      generation du code d'appel a une fonction predefinie, dont
 *      le numero de code est 'fnt', le nombre d'arguments est 'nbargs',
 *      les arguments effectifs sont donnes par top[i]-vop[i], et le resultat
 *      est range dans tres-vres.
 *
 *	nores indique si la fonction a un resultat ( equivalent a genfnspe() )
 */
BOOL nores;
BINAIRE fnt,nbargs;
BYTE    tres,top[];
BINAIRE vres,vop[];
BYTE *psuc_desc;
{                                               /* genclf */
        BINAIRE i;
        BOOL    full;
        BYTE    typ;

	for (i=0; i<nbargs; i++ ) {
		if ( top[i] == 3 )
			genpopreg(vop[i]);
	}

        /* Cas du LANG en lecture : idem CONF(5) */
        if ( (! nores ) && (fnt == 75) /* LANG */ ) {
                nbargs=1;
                top[0]=0;
                vop[0]=5;
        }
	else if ( fnt == 29 /* LEN */ ) {
		if ( top[0] == 2 ) {
			DCLInfo dcl;
			dcl.adrdesc = vop[0];
			/* calcul de la longueur de la variable de desc :vop */
			GetDCLTable(&dcl);
			if ( ! dcl.ptr ) {
				if ( tres == 2 ) {
					putvar(0,dcl.longueur,vres);
				} else {
					putreg(vres,0,dcl.longueur);
				}
				return;
			}
		}
	}

        pcode(F_CLF); adrimpl++;
        pbyte(NOAT,NumFn[fnt]); adrimpl++;

	if ( nores ) {
		full = TRUE;
	} else {
	        typ = tres << 5; full = FALSE;
	}

        if (nbargs != 0)
           for (i = 0; i < nbargs; i++) {
                if (full) {
			if ( i != 0 ) {
                        	typ |= 1; pbyte(NOAT,typ); adrimpl++;
			}
                        typ = (top[i] << 5); full = FALSE;
                }
                else {
                        typ |= (top[i] << 1)  | 0x0010;
                        full = TRUE;
                }
           }

        pbyte(NOAT,typ); adrimpl++;

	if ( nores == FALSE ) {
	        /* decrire le resultat */
        	if (tres != 3) {        /* forcement une variable */
			if ( (notaprog && (!islocal(vres))) || /* variable */
				IsExtVar(tres,vres) )
				refobj(TRUE,vres,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                	pbin(NOAT,vres); adrimpl += 2L;
        	}
        	else {
                	pbyte(NOAT,(BYTE) vres); adrimpl++; /* registre */
        	}
	}

        /* mettre en place les arguments d'appel */
        for (i = 0; i < nbargs; i++) {
                if (top[i] != 3) {
                        /* valeur immediate , constante ou variable */
                                if (notaprog && (top[i] == 1)) /* constante */
                                        refobj(FALSE,vop[i],fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
				else if ( (notaprog && (top[i] == 2) && (!islocal(vop[i]))) || /* variable */
					IsExtVar(top[i],vop[i]) )
					refobj(TRUE,vop[i],fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
			if ( psuc_desc != GenericNULL(BYTE) ) {
				switch (fnt) {
					case 97:
						{ TabProc *dproc;
							dproc = ( TabProc *) psuc_desc;
						/* reference a une procedure externe */
			        			if ((dproc->ext) || notaprog) {
					                	refproc(dproc,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
							}
							if (notaprog)
				                		lienproc(dproc,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
						}
						break;
					case 99:
						break;
					case 100:
						{ TabSeg *dseg;
							dseg = ( TabSeg *) psuc_desc;
							/* reference a un segment externe */
	        		                	if (dseg->ext || notaprog)
                                				refseg(dseg,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
			                        	if (notaprog)
        			                        	lienseg(dseg,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
						}
						break;
				}
			}
                        pbin(NOAT,vop[i]); adrimpl += 2L;
                }
                else {  /* registre */
                        pbyte(NOAT,(BYTE) vop[i]); adrimpl++;
                }
        }
}                                               /* genclf */


void gencreate(tfn,aderr,i,nbargs,targs,vargs,terr,verr)

/*      generation du code d'appel de la fonction CREATE
 *      le numero de code est 'fnt', le nombre d'arguments est 'nbargs',
 *      l'etiquette de l'eventuel traitement d'erreur est 'aderr',
 *      les eventuelles options specifiques sont dans 'options' (acces SI).
 *      les arguments effectifs sont donnes par top[i]-vop[i].
 *      sachant que top[0]-vop[0] = l'eventuelle variable d'erreur,
 *      top[1]-vop[1] = le numero logique.
 */
int tfn;
char    *aderr;
int i;
BINAIRE nbargs[];
BYTE 	targs[20][4];
BINAIRE vargs[20][4];
BYTE	terr;
BINAIRE verr;
{                                               /* gencreate */
	int j;
        BINAIRE adref;
	BINAIRE max;
	BINAIRE max2;

        if (aderr != GenericNULL(char)) {
                /* il y a un traitement d'erreur */

		/* (i-1) : nb de create */
					/* Calcul du max */
		//	max = (i-1) * 5 + 3; 	/* nb d'OEV + 1 JMI */  
		
		//	for ( j=1; j < i; j++ ) { /* nb create */
		//		max = max + 5 + ( nbargs[j] - 1 ) * 2;
		//		if ( nbargs[j] > 2 )
		//			max++;
		//	}



		max2 = 0;

		for ( j=1; j < (i-1); j++ ) { /* nb remove */
			max2 = max2 + 5 + ( nbargs[j] - 1 ) * 2;
			if ( nbargs[j] > 2 )
				max2++;
		}
		//max = max + max2; SG

		j=1;

		while ( j < i ) {

					/* Calcul du max */
			max = 8;/*(i-1) * 5 + 3;*/ 	/* nb d'OEV + 1 JMI */  
		
			//for ( j=1; j < i; j++ ) { /* nb create */
				max = max + 5 + ( nbargs[j] - 1 ) * 2;
				if ( nbargs[j] > 2 )
					max++;
			//}

			/* generation d'un on error goto variable interne */
	                pcode(F_LERG); adrimpl++;
			if ( (notaprog && (!islocal(verr))) || /* variable */
				IsExtVar(terr,verr) )
				refobj(TRUE,verr,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                	pbin(NOAT,verr); adrimpl += 2L;

			/* Calcul de l'etiquette : OEV [var],&<adref> */
			adref = (BINAIRE)(adrimpl + max - 3);
			max = max - 5 - 2 * ( 5 + (nbargs[j]-1)*2 );
			if ( nbargs[j] > 2 )
				max -= 2;

        		pbin(NOAT,adref); adrimpl += 2L;

			/* generation d'un create */
			/* Attention CALCUL du create ... faire */
			genclf(TRUE,tfn,nbargs[j],0,0,targs[j],vargs[j],GenericNULL(BYTE));
			j++;
		//}SG  ------->				

		/* creation d'un jmp interne */
	        pcode(F_JMP); adrimpl++;
        	if ( *aderr == '$' ) {
	                /* etiquette speciale => NEXT */
			adref = (BINAIRE)(adrimpl + /*max2 +*/ 2);
        	} else {
			adref = (BINAIRE)(adrimpl + /*max2 +*/ 2 + 4);
		}
        	pbin(NOAT,adref); adrimpl += 2L;

		/* creation des remove associes au create */
		/* generation en sens inverse, pas de remove du dernier cree */
		//j=i-2;
		//while ( j != 0 ) {
			/* generation d'un remove */
		//	if ( tfn == 83 ) {
		//		genclf(TRUE,84,nbargs[j],0,0,targs[j],vargs[j],GenericNULL(BYTE));
		//	} else {
		//		genclf(TRUE,96,nbargs[j],0,0,targs[j],vargs[j],GenericNULL(BYTE));
		//	}
		//	j--;
		//}	

		/* generation d'un on error abort */
		geneab();
        	if ( *aderr != '$' ) {
	                /* etiquette speciale => NEXT */
			/* jmp a l'etiquette */
			gengoto(aderr);
			geneab();
		} else {	
	               /* etiquette speciale => NEXT */
    	       //defetiq(aderr,(BINAIRE) adrimpl); SG
		}
	}//SG <----------
	} else {
		/* pas de traitement d'erreur 		*/
		/* generation simple		 	*/
		j=1;
		while ( j < i ) {
			genclf(TRUE,tfn,nbargs[j],0,0,targs[j],vargs[j],GenericNULL(BYTE));
			j++;
		}
	}

}                                               /* gencreate */


void genngf(fnt,aderr,nbargs,options,top,vop)

/*      generation du code d'appel a une instruction d'acces aux fichiers, dont
 *      le numero de code est 'fnt', le nombre d'arguments est 'nbargs',
 *      l'etiquette de l'eventuel traitement d'erreur est 'aderr',
 *      les eventuelles options specifiques sont dans 'options' (acces SI).
 *      les arguments effectifs sont donnes par top[i]-vop[i].
 *      sachant que top[0]-vop[0] = l'eventuelle variable d'erreur,
 *      top[1]-vop[1] = le numero logique.
 */
int     fnt,nbargs;
char    *aderr;
BYTE    options,top[];
BINAIRE vop[];
{                                               /* genngf */
        int     i;
        BOOL    full;
        BYTE    typ;
        BINAIRE adref;

	for (i=0; i<nbargs; i++ ) {
		if ( top[i] == 3 )
			genpopreg(vop[i]);
	}

        pcode(F_NGF); adrimpl++;
        pbyte(NOAT,NumNGF[fnt]); adrimpl++;

        if (aderr != GenericNULL(char)) {
                /* il y a un traitement d'erreur */
                typ = (top[0] << 5) | 0x0080; i = 1;
        }
        else {  /* pas de traitement d'erreur */
                typ = (top[1] << 5); i = 2;
        }
        full = FALSE;
        while (i <= nbargs) {
                if (full) {
                        typ |= 1; pbyte(NOAT,typ); adrimpl++;
                        typ = (top[i] << 5); full = FALSE;
                }
                else {
                        typ |= (top[i] << 1)  | 0x0010;
                        full = TRUE;
                }
                i++;
        }
        pbyte(NOAT,typ); adrimpl++;
        /* reference a l'etiquette de l'enventuel traitement d'erreur */
        if (aderr != GenericNULL(char)) {
                adref = refetiq(aderr,(BINAIRE) adrimpl);
                pbin(NOAT,adref); adrimpl += 2L;
                if (top[0] != 3) {      /* forcement une variable */
			if ( (notaprog && (!islocal(vop[0]))) || /* variable */
				IsExtVar(top[0],vop[0]) )
				refobj(TRUE,vop[0],fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                        pbin(NOAT,vop[0]); adrimpl += 2L;
                }
                else {
                        pbyte(NOAT,(BYTE) vop[0]); adrimpl++; /* registre */
                }
        }
        /* mettre en place le numero logique */
        if (top[1] != 3) {
                /* valeur immediate , constante ou variable */
                        if (notaprog && (top[1] == 1)) /* constante */
                                refobj(FALSE,vop[1],fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
			else if ( (notaprog && (top[1] == 2) && (!islocal(vop[1]))) || /* variable */
				IsExtVar(top[1],vop[1]) )
				refobj(TRUE,vop[1],fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                pbin(NOAT,vop[1]); adrimpl += 2L;
        }
        else {  /* registre */
                pbyte(NOAT,(BYTE) vop[1]); adrimpl++;
        }
        /* cas particulier du descripteur suppl. des options (acces SI) */
        if (options != 0x00FF) {
                pbyte(NOAT,options); adrimpl++;
        }
        /* mettre en place les arguments suivants */
        i = 2;
        while (i <= nbargs) {
                typ = top[i] & 0x03;
                if (typ != 3) {
                        /* valeur immediate , constante ou variable */
                                if (notaprog && (typ == 1)) /* constante */
                                        refobj(FALSE,vop[i],fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
				else if ( (notaprog && (typ == 2) && (!islocal(vop[i]))) || /* variable */
					IsExtVar(typ,vop[i]) )
					refobj(TRUE,vop[i],fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                        pbin(NOAT,vop[i]); adrimpl += 2L;
                }
                else {  /* registre */
                        pbyte(NOAT,(BYTE) vop[i]); adrimpl++;
                }
                i++;
        }
        if ((aderr != GenericNULL(char)) && (*aderr == '$')) {
                /* etiquette speciale => NEXT */
                defetiq(aderr,(BINAIRE) adrimpl);
        }
}                                               /* genngf */


BINAIRE genconv(typ,top,vop)

/*      generation du code pour une conversion de type de donnee
 */
BYTE typ,top;
BINAIRE vop;
{                                               /* genconv */
        BINAIRE reg;

	if ( top == 3 )
		genpopreg(vop);

        if (top != 3) { /* si premiere operande n'est pas un registre */
                reg = getreg();         /* prendre un registre */
                putreg(reg,top,vop);
        }
        else            /* sinon c'est direct */
                reg = vop;
        pcode(F_CNV); adrimpl += 4L;
        pbyte(NOAT,(BYTE) reg);
        pbyte(NOAT,typ); pbyte(NOAT,0);
        return (reg);
}                                               /* genconv */


void geniof(tdev,vdev)

/*      debut de la generation du code pour une fonction PRINT ou ASK
 */
BYTE    tdev;
BINAIRE vdev;
{                                               /* geniof */
        ptabio = &tab_iof[0];
        ltabio = nbetq = nbcrel = nbvrel = 0;
        flgprint = TRUE;
        if ((tdev != 0) || (vdev != 1))         /* device explicite */
                genioctl(io_dev,tdev,vdev);
}                                               /* geniof */


void genfio()

/*      fin de la generation du code pour une fonction PRINT
 */
{                                               /* genfio */
        int     i,j,k,l;
        BINAIRE adref;

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\ngenfio():debut");
#endif /* ATR_DEBUG */

	genpopall();

        pcode(F_IOF); adrimpl++;
        ptabio = &tab_iof[0]; j = k = l = 0;

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\ngenfio():1er for");
#endif /* ATR_DEBUG */
        for (i = 0; i < ltabio; i++ ) {
                if ((j < nbetq) && (tabref[j] == i)) {
                        adref = refetiq(tabetq[j],(BINAIRE) adrimpl);
                        pbin(NOAT,adref); adrimpl += 2L; j++;
                }
                else {
                        if (notaprog && (k < nbcrel) && (cstrel[k] == i)) {
                                adref = bytetobin(ptabio); k++;
                                refobj(FALSE,adref,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                        }
                        if ((l < nbvrel) && (varel[l] == i)) {
                                adref = bytetobin(ptabio); l++;
                                refobj(TRUE,adref,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                        }
                }
                pbyte(NOAT,*ptabio++); adrimpl++;
        }

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\ngenfio():fin 1er for");
#endif /* ATR_DEBUG */

        if (flgprint) {
                pbyte(NOAT,io_fin); adrimpl++;
        }

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\ngenfio():2eme for");
#endif /* ATR_DEBUG */

        for (i = 0; i < nbetq; i++) {
		if (tabetq[i][0] == '$') {
			if ( fin_itere != GenericNULL(BYTE) ) {	
				if (Xstrcmp(tabetq[i],fin_itere) != 0) {
					/* etiquette speciale => NEXT et pas BREAK */
	        	                defetiq(tabetq[i],(BINAIRE) adrimpl);
				}
			} else {
				/* etiquette speciale => NEXT et pas BREAK */
        	                defetiq(tabetq[i],(BINAIRE) adrimpl);
			}
		}
        }

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\ngenfio():fin");
#endif /* ATR_DEBUG */
}                                               /* genfio */


void libiof()

/*      annulation de la generation du code pour une fonction PRINT ou ASK
 */
{                                               /* libiof */
}                                               /* libiof */


void genhome()

/*      generation du code pour un HOME dans une fonction PRINT ou ASK
 */
{                                               /* genhome */
        if (ltabio == MXARGPRN)         /* debordement */
                erreur(FATALE,ergen0);
        *ptabio++ = io_home; ltabio++;
}                                               /* genhome */


void genbell()

/*      generation du code pour un BELL dans une fonction PRINT ou ASK
 */
{                                               /* genbell */
        if (ltabio == MXARGPRN)         /* debordement */
                erreur(FATALE,ergen0);
        *ptabio++ = io_bell; ltabio++;
}                                               /* genbell */


void genclear()

/*      generation du code pour un CLEAR dans une fonction PRINT ou ASK
 */
{                                               /* genclear */
        if (ltabio == MXARGPRN)         /* debordement */
                erreur(FATALE,ergen0);
        *ptabio++ = io_clr; ltabio++;
}                                               /* genclear */


void genctab(top,vop)

BYTE top;
BINAIRE vop;
/*      generation du code pour un TAB/colonne dans une fonction PRINT ou ASK
 */
{                                               /* genctab */
        genioctl(io_ctab,top,vop);
}                                               /* genctab */


void genltab(top,vop)

BYTE top;
BINAIRE vop;
/*      generation du code pour un TAB/ligne dans une fonction PRINT ou ASK
 */
{                                               /* genltab */
        genioctl(io_ltab,top,vop);
}                                               /* genltab */


void genvtab(top,vop)

BYTE top;
BINAIRE vop;
/*      generation du code pour un TABV dans une fonction PRINT ou ASK
 */
{                                               /* genvtab */
        genioctl(io_vtab,top,vop);
}                                               /* genvtab */


void genfor(top,vop)

BYTE top;
BINAIRE vop;
/*      generation du code pour un PAINT/texte dans une fonction PRINT ou ASK
 */
{                                               /* genfor */
        genioctl(io_for,top,vop);
}                                               /* genfor */


void genbak(top,vop)

BYTE top;
BINAIRE vop;
/*      generation du code pour un PAINT/fond dans une fonction PRINT ou ASK
 */
{                                               /* genbak */
        genioctl(io_bak,top,vop);
}                                               /* genbak */


void genatb(top,vop)

BYTE top;
BINAIRE vop;
/*      generation du code pour un ATB dans une fonction PRINT ou ASK
 */
{                                               /* genatb */
        genioctl(io_atb,top,vop);
}                                               /* genatb */


void genprn(top,vop)

BYTE top;
BINAIRE vop;
/*      generation du code pour une edition dans une fonction PRINT ou ASK
 */
{                                               /* genprn */
        genioctl(io_prn,top,vop);
}                                               /* genprn */


void geniprn(ch)

char *ch;
/*      generation du code pour l'edition d'une chaine dans un PRINT ou un ASK
 */
{                                               /* geniprn */
        int lg;

        lg = Xstrlen(ch);
        ltabio += (lg + 2);
        if (ltabio >= MXARGPRN) /* debordement */
                erreur(FATALE,ergen0);
        *ptabio++ = io_iprn;
        while (*ch) *ptabio++ = *ch++;
        *ptabio++ = 0;
}                               /* geniprn */


void genask(top,vop)

BYTE top;
BINAIRE vop;
/*      generation du code pour une saisie dans une fonction ASK
 */
{                                               /* genask */
#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\ngenask():debut");
#endif /* ATR_DEBUG */

        flgprint = FALSE;
        genioctl(io_ask,top,vop);

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\ngenask():fin");
#endif /* ATR_DEBUG */
}                                               /* genask */


void genbranch(typ,top,vop,adr)

BOOL typ;
BYTE top;
BINAIRE vop;
char *adr;
/*      generation du code pour un debranchement dans une fonction ASK
 *      typ = TRUE pour un GOSUB, et FALSE pour un GOTO.
 */
{                                               /* genbranch */
        BYTE    iofn;

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\ngenbranch():debut");
#endif /* ATR_DEBUG */

        if (top < 100)
                if (typ)
                        genioctl(io_gsb,top,vop);
                else
                        genioctl(io_jmp,top,vop);
        else {  /* cas des debranchements speciaux */
                top -= 100;
                if (typ)
                        iofn = io_rbrc;
                else
                        iofn = io_brc;
                if (ltabio == MXARGPRN)         /* debordement */
                        erreur(FATALE,ergen0);
                switch (top) {
                  case 6: iofn += 0x10; /* sur EXTERN EVENT */
                  case 5: iofn += 0x10; /* sur TIMER */
                  case 4: iofn += 0x10; /* sur ERREUR */
                  case 3: iofn += 0x10; /* sur DOWN */
                  case 2: iofn += 0x10; /* sur UP */
                  case 1: iofn += 0x10; /* sur LEFT */
                  case 0: break;        /* sur ESCAPE */
                }
                *ptabio++ = iofn; ltabio++;
        }
        /* sauvegarder l'etiquette de reference */
        if (nbetq == MAXNBETQ)  /* debordement */
                erreur(FATALE,ergen0);
        tabref[nbetq] = ltabio; Xstrcpy(tabetq[nbetq],adr); nbetq++;

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\ngenbranch():fin");
#endif /* ATR_DEBUG */

}                                               /* genbranch */


void genfmt(typ,pf)

/*      codage d'un format de saisie ou d'edition en T-code
 *      a partir de sa representation chaine fournie par 'pf'
 *
 *      en entree, typ = 1 si le format doit etre directment mis dans le
 *      code (cas de FMT et de FM), et vaut 0 si il doit etre "bufferise"
 *      dans le tampon "IOF" (cas dans un PRINT ou un ASK)
 */
int typ;
char *pf;
{                                               /* genfmt */
     int lgfmt,i;

     if (typ == 0) {    /* bufferisation pendant un ASK ou un PRINT */

        if (ltabio == MXARGPRN)         /* debordement */
                erreur(FATALE,ergen0);
        *ptabio++ = (BYTE) (io_fmt | 0x80);     /* format "constante" */
        ltabio++;
        lgfmt = decfmt(pf,ptabio,(MXARGPRN-ltabio));
        if (lgfmt == 0) {
                erreur(USUAL,ergen1); return;
        }
        ltabio += lgfmt; ptabio += lgfmt;
        if (ltabio >= MXARGPRN)         /* debordement */
                erreur(FATALE,ergen0);
     }
     else {             /* generation directe dans le code pour FMT ou FM */
        ptabio = &tab_iof[0];
        lgfmt = decfmt(pf,ptabio,MXARGPRN);
        if (lgfmt == 0) {
                erreur(USUAL,ergen1); return;
        }
#ifdef ver21
	/* Entete de Format code dans le code pour lever Ambiguite du T-CODE */
	pbyte(NOAT,0);
	pbyte(NOAT,0xFE);
	adrimpl += 2L;
#endif /* ver15 */
        ptabio = &tab_iof[0];
        for (i = 0; i < lgfmt; i++) {
                pbyte(NOAT,*ptabio++); adrimpl++;
        }
     }
}                                               /* genfmt */


void genrefmt(typ,adr,top,vop)

/*      codage de la reference a un format dans un PRINT ou un ASK
 *      en entree, typ = 0 si c'est une etiquette decrite par adr,
 *      ou typ = 1 si c'est une variable decrite par top,vop
 */
int typ;
char *adr;
BYTE top;
BINAIRE vop;
{                                               /* genrefmt */
        if (typ == 0) { /* reference a une etiquette */
                if (ltabio == MXARGPRN)         /* debordement */
                        erreur(FATALE,ergen0);
                *ptabio++ = io_fmt; ltabio++;
                /* sauvegarder l'etiquette de reference */
                if (nbetq == MAXNBETQ)  /* debordement */
                        erreur(FATALE,ergen0);
                tabref[nbetq] = ltabio; Xstrcpy(tabetq[nbetq],adr); nbetq++;
        }
        else
                genioctl(io_fmt,top,vop);
}                                               /* genrefmt */


static int decfmt(fptr,nptr,lg)

/*      codage d'un format de saisie ou d'edition en T-code
 *      a partir de sa representation chaine fournie par 'fptr'
 *      le resultat est range dans le buffer pointe par 'nptr'
 *      sur une longueur max de 'lg'
 */
char    *fptr;
BYTE    *nptr;
int     lg;
{                                               /* decfmt */
        int     lgfmt = 0, flen;
        BINAIRE x,y;
        BYTE    *wptr,*hptr,c;
        int     fbcdv,fbcdc,fbcde;

		/* #OK: 18/06/02 (begin) */		
		int		stateOptionW = 0; 
		/* #OK: 18/06/02 (end) */

        flen = Xstrlen(fptr);
        wptr = nptr + 1;
        lgfmt++;
        if (lgfmt >= lg)        /* debordement */
                return (0);
        *(wptr++) = (BYTE) FMT_DEB;
        fbcdv = fbcdc = fbcde = 0;
        do {
                c = *(fptr++); flen--;

				/* #OK: 18/06/02 (begin) */		
				if ((c != ',') && (stateOptionW == 1) && (printToVariable) &&
					(c != ' ') && (c != '\t') && (c != 'L') && (c != 'R') )
					return (0);				
				/* #OK: 18/06/02 (end) */

                switch ( c )    {
                        case ' ':
                        case '\t':
                                fbcdv = fbcdc = fbcde = 0;
                                continue;
                        case 'V':
                                fbcdc |= 1;
                                continue;
                        case '"':
                                lgfmt += 2;
                                if (lgfmt >= lg)        /* debordement */
                                        return (0);
                                *(wptr++) = (BYTE) FMT_PR;
                                hptr = wptr; wptr++; x = 0;
                                while (( *fptr != '"' ) && (*fptr != EOSTR)) {
                                        lgfmt++;
                                        if (lgfmt >= lg) /* debordement */
                                                return (0);
                                        *(wptr++) = *(fptr++); flen--;
                                        x++;
                                }
                                if (*fptr == EOSTR)
                                        return (0);
                                *hptr = (BYTE) x; fptr++; flen--;
                                continue;
                        case ',':
								/* #OK: 18/06/02 (begin) */
								stateOptionW = 0; 
								/* #OK: 18/06/02 (end) */

                                if ( fbcdc & 1 ) {      /* FMT_V Waiting */
                                        y = fbcde - fbcdv;
                                        if (islocal(y)) y--;
                                        lgfmt += 2;
                                        if (lgfmt >= lg)/* debordement */
                                                return (0);
                                        *(wptr++) = (BYTE) FMT_V;
                                        *(wptr++) = (BYTE) ( y & 0x00FF);
                                }
                                fbcdv = fbcdc = fbcde = 0; /* Clear FMT_V */
                                lgfmt++;
                                if (lgfmt >= lg)        /* debordement */
                                        return (0);
                                *(wptr++) = FMT_SEP;
                                continue;
                        case 'L':
                                lgfmt++;
                                if (lgfmt >= lg)        /* debordement */
                                        return (0);
                                *(wptr++) = FMT_JL;
                                continue;
                        case 'R':
                                lgfmt++;
                                if (lgfmt >= lg)        /* debordement */
                                        return (0);
                                *(wptr++) = FMT_JR;
                                continue;
                        case 'H':
                                lgfmt++;
                                if (lgfmt >= lg)        /* debordement */
                                        return (0);
                                *(wptr++) = FMT_H;
                                continue;

                        case 'I':
                                lgfmt++;
                                if (lgfmt >= lg)        /* debordement */
                                        return (0);
                                *(wptr++) = FMT_I;
                                continue;
                        case '*':
                                if ( *fptr == '(' ) {
                                        lgfmt += 2;
                                        if (lgfmt >= lg) /* debordement */
                                                return (0);
                                        *(wptr++) = FMT_ZCH;
                                        fptr++; flen--;
                                        *(wptr++) = *(fptr++); flen--;
                                        fptr++; flen--;
                                }
                                else {
                                        lgfmt++;
                                        if (lgfmt >= lg) /* debordement */
                                                return (0);
                                        *(wptr++) = FMT_ZER;
                                }
                                continue;
                        case 'E':
                                lgfmt++;
                                if (lgfmt >= lg)        /* debordement */
                                        return (0);
                                *(wptr++) = FMT_STR;
                                continue;
                        case 'F':
                                lgfmt++;
                                if (lgfmt >= lg)        /* debordement */
                                        return (0);
                                *(wptr++) = FMT_CUT;
                                continue;
                        case '$':
                                if ( *fptr == '(' ) {
                                        lgfmt += 2;
                                        if (lgfmt >= lg) /* debordement */
                                                return (0);
                                        *(wptr++) = FMT_DCH;
                                        fptr++; flen--; /* Avaler parenthese */
                                        *(wptr++) = *(fptr++); flen--;
                                        if (*fptr != ')')
                                                return (0);
                                        fptr++; flen--; /* Avaler parenthese */
                                }
                                else {
                                        lgfmt++;
                                        if (lgfmt >= lg) /* debordement */
                                                return (0);
                                        *(wptr++) = FMT_DOL;
                                }
                                continue;
                        case '?':
                                lgfmt++;
                                if (lgfmt >= lg)        /* debordement */
                                        return (0);
                                *(wptr++) = FMT_DYN;
                                continue;
                        case 'S':
                                if ( *fptr == '(' ) {
                                        lgfmt += 2;
                                        if (lgfmt >= lg) /* debordement */
                                                return (0);
                                        *(wptr++) = FMT_MCH;
                                        fptr++; flen--; /* Avaler parenthese */
                                        *(wptr++) = *(fptr++); flen--;
                                        if (*fptr != ')')
                                                return (0);
                                        fptr++; flen--; /* Avaler parenthese */
                                }
                                else {
                                        lgfmt++;
                                        if (lgfmt >= lg) /* debordement */
                                                return (0);
                                        *(wptr++) = FMT_MIL;
                                }
                                continue;
                        case 'D':
                                x = FMT_D; break;
                        case 'A':
                                x = FMT_A; break;
                        case 'N':
                                x = FMT_N; break;
                        case 'Z':
                                x = FMT_Z; break;
                        case 'C':
                                x = FMT_C; break;
                        case 'B':
                                x = FMT_B; break;
                        case 'W':
								/* #OK: 18/06/02 (begin) */		
								stateOptionW = 1; 
								/* #OK: 18/06/02 (end) */	
                                x = FMT_W; break;
                        case 'U':
                                x = FMT_U; break;
                        case 'O':
                                x = FMT_O; break;
                        case '.':
                                if ( *fptr == '(' ) {
                                        lgfmt += 2;
                                        if (lgfmt >= lg) /* debordement */
                                                return (0);
                                        *(wptr++) = FMT_PCH;
                                        fptr++; flen--; /* Avaler parenthese */
                                        *(wptr++) = *(fptr++); flen--;
                                        if (*fptr != ')')
                                                return (0);
                                        fptr++; flen--; /* Avaler parenthese */
                                }
                                else {
	                                lgfmt++;
        	                        if (lgfmt >= lg)  /* debordement */
                	                        return (0);
                        	        *(wptr++) = FMT_P; fbcdc |= 2;
                                }
                                continue;
                        case '/':
                                x = FMT_LF;  break;
                        case '\\':
                                x = FMT_ATB; break;
                        case 'T':
                                x = FMT_TAB; break;
                        case 'X':
                                x = FMT_ESP; break;
                        case '+':
                                x = FMT_POS; break;
                        case '-':
                                x = FMT_NEG; break;
                        default :
                                return(0);
                }
                lgfmt++;
                if (lgfmt >= lg)        /* debordement */
                        return (0);
                *(wptr++) = (BYTE) x; y = 1;

                /* Saute les espaces prealables dans le decompte du nombre de
                 * specifications de format identiques.
                 */
                while ((flen != 0) && (*fptr == ' ')) {
                        fptr++;
                        flen--;
                }
                while ((flen !=0) && (*fptr == (char)c)) {
                        y++; fptr++; flen--;
                }
                if (isdigit(*fptr)) {
                        x = 0;
                        do {
                                x = (x * 10) + (BINAIRE) cartoint(*fptr);
                                fptr++; flen--;
                        }
                        while (isdigit(*fptr));
                        y += (x - 1);
                        if ( y > 256 )  return (0);
                        if ( y == 256)  y = 0;
                }
                if (( fbcdc & 1 ) == 0)  fbcdv += y;
                if (( fbcdc & 2 ) == 0)  fbcde += y;
                lgfmt++;
                if (lgfmt >= lg)        /* debordement */
                        return (0);
                *(wptr++) = (BYTE) y;
        }
        while (flen > 0 );
        if ( fbcdc & 1 ) {      /* FMT_V Waiting */
                y = fbcde - fbcdv;
                if (islocal(y))  y--;
                lgfmt += 2;
                if (lgfmt >= lg) /* debordement */
                        return (0);
                *(wptr++) = (BYTE) FMT_V;
                *(wptr++) = (BYTE) ( y & 0x00FF);
        }
        lgfmt++;
        if (lgfmt >= lg)        /* debordement */
                return (0);
        *(wptr++) = FMT_FIN;
        if (lgfmt > 255)        /* debordement */
                return (0);
        *nptr = (BYTE) lgfmt;
        return (lgfmt+1);
}                                               /* decfmt */


static void genioctl(iofn,top,vop)

/*      generique pour le codage d'une directive dans un ASK ou un PRINT
*/
BYTE iofn,top;
BINAIRE vop;
{                                               /* genioctl */

        switch (top) {
                case 0: /* valeur immediate */
                        ltabio += 3;
                        if (ltabio >= MXARGPRN)         /* debordement */
                                erreur(FATALE,ergen0);
                        *ptabio++ = iofn; ptabio = bintobyte(ptabio,vop);
                        break;
                case 1: /* constante */
                        iofn |= 0x20; ltabio += 3;
                        if (ltabio >= MXARGPRN)         /* debordement */
                                erreur(FATALE,ergen0);
                        *ptabio++ = iofn;
                        if (notaprog) {
                                if (nbcrel == MXRELARG)
                                        erreur(FATALE,ergen0);
                                cstrel[nbcrel++] = (ltabio - 2);
                        }
                        ptabio = bintobyte(ptabio,vop);
                        break;
                case 2: /* variable */
                        iofn |= 0x40; ltabio += 3;
                        if (ltabio >= MXARGPRN)         /* debordement */
                                erreur(FATALE,ergen0);
                        *ptabio++ = iofn;
                        if ((notaprog && (!islocal(vop))) || IsExtVar(top,vop) ) {
                                if (nbvrel == MXRELARG)
                                        erreur(FATALE,ergen0);
                                varel[nbvrel++] = (ltabio - 2);
                        }
                        ptabio = bintobyte(ptabio,vop);
                        break;
                case 3: /* registre */
                        iofn |= 0x60; ltabio += 2;
                        if (ltabio >= MXARGPRN)         /* debordement */
                                erreur(FATALE,ergen0);
                        *ptabio++ = iofn; *ptabio++ = (BYTE) vop;
                        break;
        }
}                                               /* genioctl */


void genreadmem(top,vop)

/*      generation d'un acces a une DATA par un READMEM
 */
BYTE top;
BINAIRE vop;
{                                               /* genreadmem */
	if ( top == 3 )
		genpopreg(vop);

        if (top == 2) { /* reception = variable */
                pcode(F_DTR); adrimpl++;
                if ( (notaprog && (!islocal(vop))) ||
			IsExtVar(top,vop) )
                        refobj(TRUE,vop,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                pbin(NOAT,vop); adrimpl += 2L;
        }
        else { /* reception = registre */
                pcode(F_DTRR); pbyte(NOAT,(BYTE) vop); adrimpl += 2L;
        }
}                                               /* genreadmem */


void gendata(typ,strval,bcdval)

/*      generation d'une DATA dans le code courant
 */
BINAIRE typ;
char *strval;
BYTE *bcdval;
{                                               /* gendata */
        BYTE lg,i;

        if (typ == 1) { /* chaine */
                        lg = (BYTE) Xstrlen(strval);
                        pbyte(NOAT,(BYTE) lg);
                        for (i = 0; i < lg; i++)  pbyte(NOAT,(BYTE) *strval++);
                        adrimpl += (long) (lg + 1);
        }
        else    {       /* BCD */
                        pbyte(NOAT,0); lg = *bcdval++; pbyte(NOAT,lg);
                        for (i = 0; i < lg; i++)  pbyte(NOAT,*bcdval++);
                        adrimpl += (long) (lg + 2);
        }
}                                               /* gendata */


void genfincode (seg,adr_datas,nb_datas)

/*      fin du code d'un segment (si seg est vrai) ou d'une procedure
 */
BOOL seg;
BINAIRE adr_datas,nb_datas;
{                                               /* genfincode */
        if (nb_datas == 0) {
                if (seg)
                        genstop();
                else
                        genretp();
                pbin(NOAT,(BINAIRE) 0xFFFF); adrimpl += 2L;


        }
        else {
                pbin(NOAT,0); pbin(NOAT,nb_datas); pbin(NOAT,adr_datas);
                adrimpl += 6L;
        }
}                                               /* genfincode */


/*      manipulation des objets de la machine fictive   */
/*      ---------------------------------------------   */

void pushreg (reg)

/*      sauvegarde d'un registre dans la pile de la machine fictive
 */
BINAIRE reg;
{                                       /* pushreg */
        pcode(F_PSH); pbyte(NOAT,(BYTE) reg); adrimpl += 2L;
}                                       /* pushreg */


void popreg (reg)

/*      reprendre un registre dans la pile de la machine fictive
 */
BINAIRE reg;
{                                       /* popreg */
        pcode(F_POP); pbyte(NOAT,(BYTE) reg); adrimpl +=2L;
}                                       /* popreg */


void increg (reg)

/*      generation du code pour l'incrementation du registre 'reg'
 */
BINAIRE reg;
{                                               /* increg */
	genpopreg(reg);
        pcode(F_INC); pbyte(NOAT,(BYTE) reg); adrimpl += 2L;
}                                               /* increg */


void decreg (reg)

/*      generation du code pour la decrementation du registre 'reg'
 */
BINAIRE reg;
{                                               /* decreg */
	genpopreg(reg);
        pcode(F_DEC); pbyte(NOAT,(BYTE) reg); adrimpl += 2L;
}                                               /* decreg */


BINAIRE negvar(adr)

/*      negation de la variable pointee par adr, en utilisant un registre
 */
BINAIRE adr;
{                                       /* negvar */
        BINAIRE reg;

        reg = getreg();
        putreg(reg,2,adr);
        negreg(reg);
        return (reg);
}                                       /* negvar */


void negreg(reg)

/*      negation du registre de numero reg
 */
BINAIRE reg;
{                                       /* negreg */
	genpopreg(reg);
        pcode(F_NGR); pbyte(NOAT,(BYTE) reg); adrimpl += 2L;
}                                       /* negreg */


BINAIRE genoper(oper,top1,vop1,top2,vop2,typ)

/*      generation du code d'une operation arithmetique
 *      en entree : oper = code numerique de l'operation
 *                  top1,vop1 = description de la 1ere operande
 *                  top2,vop2 = description de la 2eme operande
 *                  typ = type de l'expression
 *      en sortie : numero de registre resultat
 *
 *      Si 'opt_oper' est a 1 en entree, il faut traiter le cas special :
 *                      OPR #x , ... , #0
 */
BINAIRE oper;
BYTE top1,top2,typ;
BINAIRE vop1,vop2;
{                                       /* genoper */
        BINAIRE reg;
        BYTE codop;

	BINAIRE old_libreg; /* sauvegarde du prochain registre candidat */
	old_libreg = libreg;

	if ( top1 == 3 )
		genpopreg(vop1);
	if ( top2 == 3 )
		genpopreg(vop2);

        if (top1 != 3) {           /* si 1ere operande n'est pas un registre */
           if ((oper != 1) && (oper != 3) && (oper != 4) && (oper != 8)) {
                /* operateur commutatif : */
                if (top2 == 3) {        /* 2eme operande est un registre ! */
                        reg = vop2; top2 = top1; vop2 = vop1; /* inverser */
                }
                else if (top1 == 2) {   /* premiere operande = variable */
                        reg = getreg();         /* prendre un registre */
                        if ((typ == TBCD) || (typ == TSTR))
                                putadr(reg,vop1);
                        else
                                putreg(reg,top1,vop1);
                }
                else if (top2 == 2) {   /* 2eme operande = variable */
                        reg = getreg();         /* prendre un registre */
                        if ((typ == TBCD) || (typ == TSTR))
                                putadr(reg,vop2);
                        else
                                putreg(reg,top2,vop2);
                        top2 = top1; vop2 = vop1; /* et inverser */
                }
                else {  /* les deux operandes sont des constantes */
                        reg = getreg();         /* prendre un registre */
                        putreg(reg,top1,vop1);  /* et y mettre la premiere */
                }
           }
           else {       /* operateur n'est pas commutatif, dans ce cas :  */
                reg = getreg();         /* prendre un registre */
                if ((top1 == 2) && ((typ == TBCD) || (typ == TSTR)))
                        putadr(reg,vop1);
                else
                        putreg(reg,top1,vop1);
           }
        }
        else    /* premiere operande = registre : c'est direct ! */
                reg = vop1;

        switch (oper) {
          case 0:                                       /* PLUS */
                if ((typ != TBCD) && (top2 == 0) && (vop2 == 1)) {
                        /* INC vaut mieux que ADD */
                        increg(reg); return (reg);
                }
                codop = F_ADD; break;
          case 1:                                       /* MOINS */
                if ((typ != TBCD) && (top2 == 0) && (vop2 == 1)) {
                        /* DEC vaut mieux que ADD */
                        decreg(reg); return (reg);
                }
                codop = F_SUB; break;
          case 2:                                       /* MUL */
                codop = F_MUL; break;
          case 3:                                       /* DIV */
                codop = F_DIV; break;
          case 4:                                       /* MOD */
                codop = F_MOD; break;
          case 5:                                       /* AND */
                codop = F_AND; break;
          case 6:                                       /* OR */
                codop = F_OR;  break;
          case 7:                                       /* OX */
                codop = F_OX;  break;
          case 8:                                       /* ADD sur chaines */
                codop = F_ADD; break;
        }
        switch (top2) {
           case 0:      /* valeur immediate */
                break;
           case 1:      /* descripteur de constante */
                codop |= 0x20; break;
           case 2:      /* descripteur de variable */
                codop |= 0x40; break;
           case 3:      /* numero de registre */
                codop |= 0x60;
        }
        pcode(codop); pbyte(NOAT,(BYTE) reg); adrimpl += 2L;
        if (top2 != 3) {
                        if (notaprog && (top2 == 1)) /* constante */
                                refobj(FALSE,vop2,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
	                else if ( (notaprog && (top2 == 2) && (!islocal(vop2))) ||
				IsExtVar(top2,vop2) )
                	        refobj(TRUE,vop2,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                pbin(NOAT,vop2); adrimpl += 2L;
        }
        else {
                pbyte(NOAT,(BYTE) vop2); adrimpl++;
        }
        if (opt_oper == 0)
                reg = getreg();
        else if (opt_oper == 1)
                reg = 0;        /* cas d'une operation d'affectation */
        /* si opt_oper == 2 en entree : laisser reg a sa valeur !! */

        pbyte(NOAT,(BYTE) reg); adrimpl++;

	if ( reg > old_libreg )
		oter_lreg(&lreg_used,old_libreg);

        return (reg);
}                                       /* genoper */


BINAIRE getreg()

/*      obtention d'un numero de registre libre
 */
{                                       /* getreg */
        if (libreg >= maxregs)
                erreur(FATALE,ergen0);
        return (libreg++);
}                                       /* getreg */


void ungetreg()

/*      restitution du dernier registre attribue par getreg
 */
{                                       /* ungetreg */
        libreg--;
}                                       /* ungetreg */


void putadr(reg,adr)

/*      affectation d'un registre avec une adresse de descripteur
 */
BINAIRE reg,adr;
{                                       /* putadr */
        pcode(F_VPT); pbyte(NOAT,(BYTE) reg); adrimpl += 2L;
                if ( (notaprog && (!islocal(adr))) ||
			IsExtVar(2,adr) )
                        refobj(TRUE,adr,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
        pbin(NOAT,adr); adrimpl += 2L;
}                                       /* putadr */


void putreg(reg,top,vop)

/*      affectation d'un registre avec la valeur decrite par (top,vop)
 */
BINAIRE reg,top,vop;
{                                       /* putreg */
        BYTE codop;

	if ( top == 3 )
		genpopreg(vop);

        codop = F_LDR;
        switch (top) {
           case 0:      /* valeur immediate */
                break;
           case 1:      /* descripteur de constante */
                codop |= 0x20; break;
           case 2:      /* descripteur de variable */
                codop |= 0x40; break;
           case 3:      /* numero de registre */
                codop |= 0x60;
        }
        pcode(codop); pbyte(NOAT,(BYTE) reg); adrimpl += 2L;
        if (top != 3) {
                        if (notaprog && (top == 1)) /* constante */
                                refobj(FALSE,vop,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
	                else if ( (notaprog && (top == 2) && (!islocal(vop))) ||
				IsExtVar(top,vop) )
                        	refobj(TRUE,vop,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                pbin(NOAT,vop); adrimpl += 2L;
        }
        else {
                pbyte(NOAT,(BYTE) vop); adrimpl++;
        }
	/* le registre de retour est en cours d'utilisation */
	ins_lreg(&lreg_used,reg);
	/* le registre source ne l'est plus */
	if ( find_lreg(lreg_used,vop) )
		oter_lreg(&lreg_used,vop);
}                                       /* putreg */


void storeg(reg,top,vop)

/*      affectation d'un registre avec la valeur decrite par (top,vop)
 *      en faisant l'interpretation des operandes pour regler le cas
 *      d'un STORE dans un registre au lieu d'un LOAD.
 */
BINAIRE reg,top,vop;
{                                       /* storeg */
	if ( top == 3 )
		genpopreg(vop);

        if (top != 3) {
                if (top == 1) { /* constante -> registre */
                        pcode(F_RTC); adrimpl++;
                        if (notaprog)
                                refobj(FALSE,vop,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                }
		else if ((top == 2) && (!islocal(vop))) {
			/* variable -> registre */
                        pcode(F_RTV); adrimpl++;
                        if (notaprog || IsExtVar(top,vop))
                                refobj(TRUE,vop,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                }
                pbin(NOAT,vop); adrimpl += 2L;
        }
        else {  /* registre -> registre */
                pcode(F_RTR); pbyte(NOAT,(BYTE) vop); adrimpl += 2L;
        }
        pbyte(NOAT,(BYTE) reg); adrimpl++;
}                                       /* storeg */


void putbin(fnt,reg,adr,desc)

/*      chargement du registre 'reg' avec une valeur binaire, provenant
 *      d'une variable simple (# ou %) dont l'adresse en memoire est 'adr'.
 *      en entree, fnt = 0 si la variable globale,#
 *                       1                locale,#
 *                       2                globale,%
 *                       3                locale,%
 *
 *	version 1.5 :
 *	Relocation des adresses externes et des variables globales de 
 *	module
 */
int fnt;
BINAIRE reg,adr;
BINAIRE desc;
{                                       /* putbin */
        BYTE codop;

	if ( adr == 0xFFFF )	/* variable externe */
		fnt--;

        switch (fnt) {
                case 0: codop = F_LDGC; break;
                case 1: codop = F_LDLC; break;
                case 2: codop = F_LDGI; break;
                case 3: codop = F_LDLI; break;
        }
        pcode(codop); pbyte(NOAT,(BYTE) reg);
	adrimpl += 2L;

	if ( (adr == 0xFFFF) || ( notaprog && !(fnt%2)) )
	/* relocation des adresses externes */
	/* et des var glo de module */
		refobj(TRUE,desc,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst | 0xFF00 );

	pbin(NOAT,adr);
        adrimpl += 2L;
}                                       /* putbin */


void putcnv(reg,top,vop)

/*      Conversion du type si BCD en integer
 *      valeur decrite par (top,vop)
 */
BINAIRE reg,top,vop;
{                                       /* putcnv */
        BYTE codop;
        BINAIRE reg2;

	if ( top == 3 )
		genpopreg(vop);

        if ( (top==1) || (top==2) ) {

                codop = F_LDR;
                if ( top == 1 ) {
                        /* descripteur de constante */
                        codop |= 0x20;
                } else {
                        /* 2: descripteur de variable */
                        codop |= 0x40;
                }
                reg2=libreg;
                libreg++;
                pcode(codop); pbyte(NOAT,(BYTE) reg2); adrimpl += 2L;
                if (top != 3) {
                                if (notaprog && (top == 1)) /* constante */
                                        refobj(FALSE,vop,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                                else if ( (notaprog && (top == 2) && (!islocal(vop))) ||
					IsExtVar(top,vop) )
                                        refobj(TRUE,vop,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                        pbin(NOAT,vop); adrimpl += 2L;
                } else {
                        pbyte(NOAT,(BYTE) vop); adrimpl++;
                }
                libreg--;
        } else {
                codop |= 0x60;
                reg2=vop;
        }
        codop = F_CNV;
        pcode(codop); pbyte(NOAT,(BYTE) reg2); pbin(NOAT,1); adrimpl += 4L;

}                                       /* putcnv */


void putrix(reg,top,vop,to)

/*      affectation d'un 1er registre d'index avec la
 *      valeur decrite par (top,vop)
 */
BINAIRE reg,top,vop;
BYTE to;
{                                       /* putrix */
        BYTE codop;

	if ( top == 3 )
		genpopreg(vop);

        if (  top != 0 ) {
                if ( to == 2 ) {
                        putcnv(reg,top,vop);
                        if ( top != 3 )
                                vop=libreg;
                        top=3;
                }
        }

        codop = F_LIX;
        switch (top) {
           case 0:      /* valeur immediate */
                break;
           case 1:      /* descripteur de constante */
                codop |= 0x20;
                break;
           case 2:      /* descripteur de variable */
                codop |= 0x40;
                break;
           case 3:      /* numero de registre */
                codop |= 0x60;
        }
        pcode(codop); pbyte(NOAT,(BYTE) reg); adrimpl += 2L;
        if (top != 3) {
                        if (notaprog && (top == 1)) /* constante */
                                refobj(FALSE,vop,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
			else if ( (notaprog && (top == 2) && (!islocal(vop))) ||
				IsExtVar(top,vop) )
                                refobj(TRUE,vop,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                pbin(NOAT,vop); adrimpl += 2L;
        }
        else {
                pbyte(NOAT,(BYTE) vop); adrimpl++;
        }
}                                       /* putrix */


void putrax(reg,top,vop,to)

/*      affectation d'un registre d'index auxilliaire avec
 *      la valeur decrite par (top,vop)
 */
BINAIRE reg,top,vop;
BYTE to;
{                                       /* putrax */
        BYTE codop;

	if ( top == 3 )
		genpopreg(vop);

        codop = F_AIX;
        switch (top) {
           case 0:      /* valeur immediate */
                break;
           case 1:      /* descripteur de constante */
                codop |= 0x20; break;
           case 2:      /* descripteur de variable */
                codop |= 0x40; break;
           case 3:      /* numero de registre */
                codop |= 0x60;
        }
        pcode(codop); pbyte(NOAT,(BYTE) reg); adrimpl += 2L;
        if (top != 3) {
                        if (notaprog && (top == 1)) /* constante */
                                refobj(FALSE,vop,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                        else if ( (notaprog && (top == 2) && (!islocal(vop))) ||
				IsExtVar(top,vop) )
                                refobj(TRUE,vop,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                pbin(NOAT,vop); adrimpl += 2L;
        }
        else {
                pbyte(NOAT,(BYTE) vop); adrimpl++;
        }
}                                       /* putrax */


void putvar(top,vop,var)

/*      rangement dans une variable
 */
BYTE top;
BINAIRE vop,var;
{                                       /* putvar */
        BYTE codop;

	if ( top == 3 )
		genpopreg(vop);

        codop = F_STO;
        switch (top) {
           case 0:      /* valeur immediate */
                break;
           case 1:      /* descripteur de constante */
                codop |= 0x20; break;
           case 2:      /* descripteur de variable */
                codop |= 0x40; break;
           case 3:      /* numero de registre */
                codop |= 0x60;
        }

        pcode(codop); adrimpl++;
        if (top != 3) {
                        if (notaprog && (top == 1)) /* constante */
                                refobj(FALSE,vop,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                        else if ( (notaprog && (top == 2) && (!islocal(vop))) ||
				IsExtVar(top,vop) )
                                refobj(TRUE,vop,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                pbin(NOAT,vop); adrimpl += 2L;
        }
        else {
                pbyte(NOAT,(BYTE) vop); adrimpl++;
        }
        if ( (notaprog && (!islocal(var))) ||
		IsExtVar(2,var) )
		refobj(TRUE,var,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
        pbin(NOAT,var); adrimpl += 2L;
}                                       /* putvar */


void stobin(fnt,adr,reg,desc)

/*      rangement a l'offset 'adr' d'une variable de type binaire,
 *      d'une valeur contenue dans le registre reg.
 *      en entree, fnt = 0 si la variable de reception est globale,#
 *                       1                                 locale,#
 *                       2                                 globale,%
 *                       3                                 locale,%
 *
 *	version 1.5 :
 *	relocation des GIS LIS
 */
int fnt;
BINAIRE adr,reg;
BINAIRE desc;
{                                       /* stobin */
        BYTE codop;

	genpopreg(reg);

	if ( adr == 0xFFFF ) /* variable externe idem global */
		fnt--;

        switch (fnt) {
                case 0: codop = F_STGC; break;
                case 1: codop = F_STLC; break;
                case 2: codop = F_STGI; break;
                case 3: codop = F_STLI; break;
        }
        pcode(codop); pbyte(NOAT,(BYTE) reg);
        adrimpl += 2L;

	if ( (adr == 0xFFFF) || ( notaprog && !(fnt % 2)))
	/* relocation des adresses externes 	*/
	/* et des var.glo de module 		*/
		refobj(TRUE,desc,fic[NOAT].cur_bloc, fic[NOAT].cur_ofst | 0xFF00 );
		
	pbin(NOAT,adr);
        adrimpl += 2L;
}                                       /* stobin */


void genrelat(sens,oper,top1,vop1,top2,vop2,adr)

/*      production du code pour un branchement conditionnel
 *      avec l'operateur 'oper' et les operandes 'vop1' et 'vop2'
 *      sur l'adresse adr. (top1 et top2 sont les types des operandes).
 *      l'operation est inversee si 'sens' est 'FALSE' en entree.
 */
BOOL    sens;
BINAIRE oper,vop1,vop2;
BYTE    top1,top2;
char    *adr;
{                                       /* genrelat */
        BINAIRE refadr;
        BINAIRE reg;
        BYTE codop;

	if ( top1 == 3 )
		genpopreg(vop1);
	if ( top2 == 3 )
		genpopreg(vop2);

        if (top1 != 3) {           /* si 1ere operande n'est pas un registre */
                reg = getreg();         /* en prendre un ... */
                putreg(reg,top1,vop1);  /* pour l'y mettre */
        }
        else                    /* sinon c'est direct ! */
                reg = vop1;

        switch (oper) {
          case 0:
                if (sens) {
                        codop = F_JEQ;
                }
                else {
                        codop = F_JNE;
                }
                break;
          case 1:
                if (sens) {
                        codop = F_JNE;
                }
                else {
                        codop = F_JEQ;
                }
                break;
          case 2:
                if (sens) {
                        codop = F_JGE;
                }
                else {
                        codop = F_JLS;
                }
                break;
          case 3:
                if (sens) {
                        codop = F_JLE;
                }
                else {
                        codop = F_JGR;
                }
                break;
          case 4:
                if (sens) {
                        codop = F_JGR;
                }
                else {
                        codop = F_JLE;
                }
                break;
          case 5:
                if (sens) {
                        codop = F_JLS;
                }
                else {
                        codop = F_JGE;
                }
                break;
          case 6:
                if (sens) {
                        codop = F_JIN;
                }
                else {
                        codop = F_JNI;
                }
                break;
          case 7:
                if (sens) {
                        codop = F_JNI;
                }
                else {
                        codop = F_JIN;
                }
                break;
        }
        switch (top2) {
           case 0:      /* valeur immediate */
                break;
           case 1:      /* descripteur de constante */
                codop |= 0x20; break;
           case 2:      /* descripteur de variable */
                codop |= 0x40; break;
           case 3:      /* numero de registre */
                codop |= 0x60;
        }
        pcode(codop); pbyte(NOAT,(BYTE) reg); adrimpl += 2L;
        if (top2 != 3) {
                        if (notaprog && (top2 == 1)) /* constante */
                                refobj(FALSE,vop2,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                        else if ( (notaprog && (top2 == 2) && (!islocal(vop2))) ||
				IsExtVar(top2,vop2) )
                                refobj(TRUE,vop2,fic[NOAT].cur_bloc,fic[NOAT].cur_ofst);
                pbin(NOAT,vop2); adrimpl += 2L;
        }
        else {
                pbyte(NOAT,(BYTE) vop2); adrimpl++;
        }
        refadr = refetiq(adr,(BINAIRE) adrimpl);
        pbin(NOAT,refadr); adrimpl += 2L;
}                                       /* genrelat */


