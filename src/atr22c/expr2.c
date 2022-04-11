/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1990, 1996
 *	Module  : ATR
 *	Fichier : EXPR2.C
 *	Version : 2.2b
 *	Date    : 08/02/96
 *	Systeme : DOS / PRL / UNIX / VMS
 *
 *	Traducteur ABAL
 *
 *	[Traitement des expressions 2/2]
 *
 */

 /*
 * Mises a jour :
 * ------------
 *	18/07/90 : Mise en conformite avec les versions 1.2e / 1.3a / 1.4a
 *	03/09/90 : Genere un CLF (0 bcd) pour les fonctions utilisateur
 *		   a resultat bcd.
 *	05/10/90 : Extension du 0 bcd precedent a 12 octets
 *	11/10/90 : Suppression modif 05/10/90 : balance avec EXA
 *	---------- Sortie 1.2f / 1.3c / 1.4a -------------------------------
 *	19/08/91 : Admet un nombre d'argument variable nul pour une fonction
 *		   externe
 *	07/11/91 : Correction manque SGN dans X%=0 Or v#(1+1)
 *	--------------------------------------------------------------------
 *	06/09/93 : Correction eval_exp : (11) traitement des fonctions pas
 *		        de TRAP ERROR (OLE) 
 *	11/07/94 : si dans module donner une valeur ... psuc_desc (PROC et SEGMENT PTR)
 *	17/08/94 : correction DIT 3363 sauvegarde du registre R0 index affectation
 *	26/08/94 : sauvegarde du registre resultat d'une fonction ABAL 
 *	12/09/94 : autorisation des parametres en modif (?) dans proc fonction
 *		        tr_args() et eval_exp() voir aussi expr.hs
 *	15/11/94 : probleme sur argument simple mais indice
 *		        argexp reste positionne mais VPT seulement dans le + bas niveau
 *	17/10/95 : liberation de pointeur (eval_oper)
 *	------------ 2.1d -------------------------------------------------
 *	21/11/95 : version dediee 2.1
 *	27/11/95 : DIT 3765 : var externe : ne pas optimiser en GIL...
 *	15/01/96 : recherche de bug
 *	08/02/96 : DIT 3830 : SGN sur eval_exp en optimise harmonise 
 *		        avec le code traitant le cas non optimise
 *
 * 20/04/99 : (#AT) Enhancement ATR 24: Check of types into procedure header 
 *            (forward, implementation and call)
 * 24/11/99 : (#OK) Enhancement ATR 20: Add warning message: "Size of argument can't
 *            be verified".
 *	------------ 2.2b -------------------------------------------------
 * 03/12/02 : (#FC+#BG) On utilise ins_lreg() pour la liste lreg_used qui n'est pas ordonnée
 *             et push_lreg() pour la liste lreg_pushed qui est ordonnée.
 */

static ArgList *tr_argfu(nbargs,typ,mod,lsimpl,nbavar)

/*	recuperation des arguments pour l'appel a une fonction utilisateur
 *	retourne un pointeur sur une liste d'arguments (chacun etant
 *	un arbre d'expression) ou NULL en cas d'erreur.
 *	le tableau 'typ' indique le type attendu pour chaque argument,
 *	le tableau 'mod' indique le mode de passage de chaque argument.
 */
BINAIRE  *nbargs;
BYTE typ[];
BOOL mod[];
BOOL lsimpl[];
BOOL nbavar;
{						/* tr_argfu */
	BINAIRE i = 0;
	ArgList *p = GenericNULL(ArgList),*q,*r;
	ExpMemb *m;
	BINAIRE old_aff_verrue;
	BOOL old_simplexp,scrmod;

	if (usc.code != PAG) {
		erreur(USUAL,erexp7); return (GenericNULL(ArgList));
	}
	old_aff_verrue = aff_verrue; aff_verrue = 0;
	old_simplexp = simplexp;
	lexical(); 	/*avaler la parenthese*/

	/* Traitement des arguments.
	 * A partir de la version 1.4 une fonction peut etre appelee
	 * avec un nombre d'arguments variable.
	 * Seuls les arguments decrits sont controles (type et mode de
	 * passage); les suivants sont tous traites de la meme maniere :
	 * le type est quelconque et le mode de passage precise par le
	 * fichier de definition.
	 * Le lexical a genere une description des arguments dans laquelle
	 * le n+1 eme argument decrit tous les arguments variables.
	 */
	while ((i < *nbargs) || (nbavar && (i < MXARGS))) {
		if (i >= *nbargs)
			typ[i] = T_ANY;
		if (i > *nbargs)		/* propage le mode de passage */
			mod[i] = scrmod;
		scrmod = mod[i];

		/* Admet un nombre d'argument variable nul */
		if ((i == 0) && (nbavar) && (usc.code == PAD))
			goto skgen;
		simplexp = TRUE;
		m = tr_exp(&typ[i]);
		lsimpl[i] = simplexp;

		/* elimine le cas du passage par adresse d'une expression */
		if ( m == GenericNULL(ExpMemb) ||
		     (mod[i] && !simplexp)) { 	/* && typ[i] == TBIN */
			aff_verrue = old_aff_verrue;
			simplexp = old_simplexp;
			erreur(USUAL,errfu17);
			lib_arg(p);
			return (GenericNULL(ArgList));
		}
		if (i == 0) {	/* premier argument : debut de liste */
			p = All_ArgList();
			if (p == GenericNULL(ArgList))
				erreur(FATALE,errmem);
			p->va = m; p->suiv = GenericNULL(ArgList); q = p;
		}
		else {	/* autres arguments : suite de la liste */
			r = All_ArgList();
			if (r == GenericNULL(ArgList))
				erreur(FATALE,errmem);
			q->suiv = r; q = r;
			q->va = m; q->suiv = GenericNULL(ArgList);
		}
		adr_verrue = FALSE;	/* patch de la verrue pour MOVE */
		i++;

		if (i < *nbargs) {	/* reste des arguments */

			if (usc.code != VIG) {
				aff_verrue = old_aff_verrue;
				simplexp = old_simplexp;
				erreur(USUAL,erexp9);
				lib_arg(p);
				return (GenericNULL(ArgList));
			}
			lexical(); /* avaler la virgule */
		}

		else {
			switch(usc.code) {
				case VIG : lexical(); break;
				case PAD : goto skgen;
				default  : aff_verrue = old_aff_verrue;
					   simplexp = old_simplexp;
					   erreur(USUAL,erexp9);
					   lib_arg(p);
					   return (GenericNULL(ArgList));
			}
		}
	}
skgen:	aff_verrue = old_aff_verrue;
	simplexp = old_simplexp;
	if (usc.code != PAD) {
		erreur(USUAL,erexp8);
		lib_arg(p);
		return (GenericNULL(ArgList));
	}

	*nbargs = i;

	return (p);
}						/* tr_argfu */


static ArgList *tr_args(nbargs,typ,nbavar)

/*	recuperation des arguments pour l'appel a une fonction
 *	retourne un pointeur sur une liste d'arguments (chacun etant
 *	un arbre d'expression) ou NULL en cas d'erreur.
 *	le tableau 'typ' indique le type attendu pour chaque argument.
 */
BINAIRE  *nbargs;
BYTE typ[];
BOOL nbavar;
{						/* tr_args */
	BINAIRE i;
	ArgList *p = GenericNULL(ArgList),*q,*r;
	ExpMemb *m;
	BINAIRE old_aff_verrue;
	BOOL para;

	if (usc.code != PAG) {
		erreur(USUAL,erexp7); return (GenericNULL(ArgList));
	}
	old_aff_verrue = aff_verrue; aff_verrue = 0;

	lexical(); /*avaler la parenthese*/

	if ( nbavar ) {
		para = TRUE;
		for ( i=0; i < MXARGS; i++ )
			typ[i] = T_ANY;
		if ( usc.code == PAD ) {
			para = FALSE;				
			*nbargs = 0;
		}
	}
	i=0;
	while ((i < *nbargs) || (nbavar && (i < MXARGS) && (para))) {

		if ( (m = tr_exp(&typ[i])) == GenericNULL(ExpMemb) ) {
			aff_verrue = old_aff_verrue;
			return (GenericNULL(ArgList));
		}
/* 12/09/94 */
		if ( usc.code == INTERRO ) {
			if ( m->tp >= 2 ) {
				m->tp += 10;
/* #OK: 24/11/99 (begin)*/
#ifdef __ATR22__
        if (IS_TSTR(typ[i]) || IS_TBCD(typ[i])) 
            err2(WARNING,ersymb10,usc.v.pval);
#endif
/* #OK: 24/11/99 (end)*/
			} else {
				erreur(USUAL,ersynt18);
				aff_verrue = old_aff_verrue;
				return (GenericNULL(ArgList));
			}
			lexical();
		} 
		if (i == 0) {	/* premier argument */
			p = All_ArgList();
			if (p == GenericNULL(ArgList))
				erreur(FATALE,errmem);
			p->va = m; p->suiv = GenericNULL(ArgList); q = p;
		}
		else {
			r = All_ArgList();
			if (r == GenericNULL(ArgList))
				erreur(FATALE,errmem);
			q->suiv = r; q = r;
			q->va = m; q->suiv = GenericNULL(ArgList);
		}
/*		adr_verrue = FALSE;*/	/* patch de la verrue pour MOVE */
		i++;
		if ((i < *nbargs) || (nbavar && (i < MXARGS))) {
			if ( nbavar && (usc.code == PAD) ) {
				*nbargs = i;
				break;
			} else {
				if (usc.code != VIG) {
					aff_verrue = old_aff_verrue;
					erreur(USUAL,erexp9);
					lib_arg(p);
					return (GenericNULL(ArgList));
				}
				lexical(); /* avaler la virgule */
			}
		}
	}
	aff_verrue = old_aff_verrue;
	if (usc.code != PAD) {
		erreur(USUAL,erexp8);
		lib_arg(p);
		return (GenericNULL(ArgList));
	}
	return (p);
}						/* tr_args */

/*
 *	FONCTIONS DIVERSES POUR LE TRAITEMENT DES EXPRESSIONS
 *	-----------------------------------------------------
 */

static BOOL recargs(nbargs,typ,targ,varg)

/*	recuperation des arguments pour l'appel a une fonction
 *	MOVE, SWAP ou TRAN
 */
int  nbargs;
BYTE typ[],targ[];
BINAIRE varg[];
{						/* recargs */
	int i = 0;
	BINAIRE old_aff_verrue;

	if (usc.code != PAG) {
		erreur(USUAL,erexp7); return (FALSE);
	}
	old_aff_verrue = aff_verrue; aff_verrue = 0;
	lexical(); /*avaler la parenthese*/
	while (i < nbargs) {
		if (!expression(&typ[i],&targ[i],&varg[i])) {
			aff_verrue = old_aff_verrue;
			return (FALSE);
		}
		adr_verrue = FALSE;	/* patch de la verrue pour MOVE */
		i++;
		if (i < nbargs) {	/* reste des arguments */
			if (usc.code != VIG) {
				aff_verrue = old_aff_verrue;
				erreur(USUAL,erexp9); return (FALSE);
			}
			lexical(); /* avaler la virgule */
		}
	}
	aff_verrue = old_aff_verrue;
	if (usc.code != PAD) {
		erreur(USUAL,erexp8); return (FALSE);
	}
	return (TRUE);
}						/* recargs */

static BOOL tstbinres(tres)

/*	verification qu'une donnee de type binaire est 
 *	compatible avec l'expression en cours de traitement 
 */
BYTE *tres;
{					/* tstbinres */
	if ( IS_TSTR(*tres) ) {
		erreur(USUAL,erexp3); return(FALSE);
	}
	else if (*tres == T_ANY) {
		*tres = TBIN;
	}
	return (TRUE);
}					/* tstbinres */

static BOOL tststrres(tres)

/*	verification qu'une donnee de type chaine est 
 *	compatible avec l'expression en cours de traitement 
 */
BYTE *tres;
{					/* tststrres */
	if (*tres == T_ANY) {
		*tres = TSTR;
	}
	else if ( ! IS_TSTR(*tres) ) {
		erreur(USUAL,erexp3); return(FALSE);
	}
	return (TRUE);
}					/* tststrres */

static BOOL tstbcdres(tres)

/*	verification qu'une donnee de type BCD est 
 *	compatible avec l'expression en cours de traitement 
 */
BYTE *tres;
{					/* tstbcdres */
	if (IS_TSTR(*tres)) {
		erreur(USUAL,erexp3); return(FALSE);
	}
	else if (*tres == T_ANY) {
		*tres = TBCD;
	}
	else if ( ! IS_TBCD(*tres) ) {
		if (ind_verrue) {	/* laisser passer dans ce cas */
			erreur(WARNING,erexp4);
		}
		else
			erreur(USUAL,erexp4);
	}
	return (TRUE);
}					/* tstbcdres */

static BINAIRE cvbintobcd(val,sgn)

/*	conversion d'une valeur binaire en BCD
 */
BINAIRE val;
BOOL	sgn;
{					/* cvbintobcd */
	int	i = 1,j = 4;
	BINAIRE vres;
	BOOL	full = FALSE;
	BYTE	bufbcd[4];	/* un binaire = 5 chiffres + un signe */
	BYTE	oct[5];

	bufbcd[i] = (sgn) ? (BYTE) BCD_MOINS : (BYTE) BCD_PLUS;
	do {
		oct[j--] = (BYTE) (val % 10);
	}
	while ((val /= 10) > 0);
	j++;
	do {
		if (full) {
			i++; bufbcd[i] = (oct[j++] << 4); full = FALSE;
		}
		else  {
			bufbcd[i] |= oct[j++]; full = TRUE;
		}
	}
	while (j < 5);
	if (!full)
		bufbcd[i] |= (BYTE) BCD_FIN;
	bufbcd[0] = (BYTE) i;
	vres = newbcd(&bufbcd[0]);
	return (vres);
}					/* cvbintobcd */


static BINAIRE valeur(oper)

/*	retourne la valeur codee d'un operateur arithmetique
 */
Code_Synt oper;
{						/* valeur */
	BINAIRE v;

	switch (oper) {
	  case PLUS:	v = 0; break;
	  case MOINS:	v = 1; break;
	  case MUL:	v = 2; break;
	  case DIV:	v = 3; break;
	  case MOD:	v = 4; break;
	  case AND:	v = 5; break;
	  case OR:	v = 6; break;
	  case OX:	v = 7; break;
 	  case CONC:	v = 8;
	}
	return (v);
}						/* valeur */

static void lib_exp(p)

/*	liberation de l'arbre d'evaluation d'expression
 *	pointe par le parametre 'p'
 */
ExpMemb *p;
{					/* lib_exp */
	if (p->g != GenericNULL(ExpMemb))
		lib_exp(p->g);
	if (p->d != GenericNULL(ExpMemb))
		lib_exp(p->d);
	if (p->ap != GenericNULL(ArgList))
		lib_arg(p->ap);
	if ((p->desc != GenericNULL(BYTE)) && (p->tp == 7))
		lib_AppFct((AppFct *)p->desc);
	Free_ExpMemb(p);
}					/* lib_exp */

static void lib_AppFct(p)

/*	liberation de l'arbre d'evaluation d'expression
 *	pointe par le parametre 'p'
 */
AppFct *p;
{					/* lib_AppFct */
	if (p->simple != GenericNULL(BOOL))
		Free_BOOL(p->simple);
	Free_AppFct(p);
}					/* lib_AppFct */

static void lib_arg(a)

/*	liberation d'une liste d'arguments
 *	pointe par le parametre 'a'
 */
ArgList *a;
{					/* lib_arg */
	ArgList *s;
	
	while (a != GenericNULL(ArgList)) {
	if (a->va != GenericNULL(ExpMemb))
		lib_exp(a->va);
		s = a->suiv; Free_ArgList(a); a = s;
	}
}					/* lib_arg */

/*
 *	EVALUATION D'UNE EXPRESSION A PARTIR D'UNE ARBORESCENCE
 *	-------------------------------------------------------
 *	version 1.5
 */

/* #AT: 20/04/99 (begin)*/
#ifdef __ATR22__
BOOL IsIntType(BYTE bType)
{
  return (IS_TBIN1(bType)||IS_TBIN2(bType));
}
#endif
/* #AT: 20/04/99 (end)*/

static void eval_exp(p,t,v,to)

/*	evaluation/production de code d'une expression
 *	representee par l'arbre pointe par 'p', qui est libere pendant
 *	son parcours.
 */
ExpMemb *p;
BYTE	*t;
BINAIRE *v;
BYTE *to; 
{						/* eval_exp */
	BYTE	top[MXARGS+1];
	BINAIRE	vop[MXARGS+1];
	BYTE tto[MXARGS+1];
	BINAIRE reg,i,old_affverrue,deb;
	ArgList	*l,*q;
	Tbusr	*fct;
	AppFct	*desapp;
	BOOL	*lsimpl,old_simplexp;
	BOOL	old_diez_verrue,old_argexp,old_logic_verrue;
	
	TabProc *ptproc;
	BYTE *psuc_desc = GenericNULL(BYTE);

#ifdef VERSION_XX
	TabProc *dproc = GenericNULL(TabProc);
	BINAIRE ivarbreg;
#endif

	verrue_retour_ptr = FALSE;

	switch (p->tp) {

	   /* ----------------------------
	    * VALEUR IMMEDIATE / CONSTANTE
	    * ---------------------------- */
	   case 0:	/* valeur immediate */
	   case 1:	/* valeur constante (chaine ou BCD) */
		*t = p->tp; *v = p->vl;
		*to = p->na;
		break;

	   /* ----------------------------------------
	    * VARIABLE / PARAMETRE VARIABLE MODIFIABLE
	    * ---------------------------------------- */
	   case 2:	/* variable */
	   case 12:	/* parametre variable modifiable */
		if ( IS_TBIN1(p->na) &&
		    ((ind_verrue && oper_verrue) || logic_verrue) ) {
			/* cas particulier d'une variable # non signee */
#ifdef CR_LOGIC_DEBUG
			printf("\r\ni=%d o=%d l=%d",ind_verrue,oper_verrue,logic_verrue);
#endif
			putsgn(); reg = getreg(); putreg(reg,2,p->vl);
			if (p->tp == 12)	*t = 7;
			else			*t = 3;
			*v  = reg;
			*to = p->na;
			break;
		}

		if (p->tp == 12)	*t = 6;
		else 			*t = p->tp;
		*v  = p->vl;
		*to = p->na;
		break;

	   /* ----------------------------------------
	    * REGISTRE / PARAMETRE REGISTRE MODIFIABLE
	    * ---------------------------------------- */
	   case 3:	/* variable "registre" */
	   case 13:	/* parametre registre modifiable */
		if (p->tp == 13)	*t = 7;
		else			*t = 3;
		*v  = p->vr;
		*to = p->na;
		break;

	   /* -----------------------
	    * OPERATEUR A 2 OPERANDES
	    * ----------------------- */
	   case 4:	/* operateur */
		if ((ind_verrue) || (arg_verrue)) {
		/* variables registres ne doivent pas etre modifiees !!
		 */
		  if (p->g->tp == 3) {
			if (IS_TBIN2(p->g->na)) {
				reg = getreg(); putreg(reg,3,p->g->vr);
				p->g->vr = reg;
			}
			else {	p->g->tp = 2;	}
		  }
		  else if (commutatif(p->vl) && (p->d->tp == 3)) {
			if (IS_TBIN2(p->d->na)) {
				reg = getreg(); putreg(reg,3,p->d->vr);
				p->d->vr = reg;
			}
			else {	p->d->tp = 2;	}
		  }
		}

		/* Va evaluer l'expression G/D/OPER */
		oper_verrue = TRUE;
		if ((p->vl >= 5) && (p->vl <= 7))
			logic_verrue = TRUE;

		if (flg_opt) {
			eval_oper(p,t,v,to);
			oper_verrue = logic_verrue = FALSE;
		} else {
			eval_exp(p->g,&top[0],&vop[0],&tto[0]);
			if (top[0] == 3) {
	 			ins_lreg(&lreg_used,vop[0]);
				oper_verrue = logic_verrue = FALSE;
			}
			eval_exp(p->d,&top[1],&vop[1],&tto[1]);
			if (top[1] == 3)
	 			ins_lreg(&lreg_used,vop[1]);
			oper_verrue = logic_verrue = FALSE;
			*t = 3;
			*v = genoper(p->vl,top[0],vop[0],top[1],vop[1],p->na);
			*to = tto[0];
			/* #FC+BG 03/12/02
			if (top[0] == 3)
	 			oter_lreg(&lreg_used,vop[0]);
			if (top[1] == 3)
	 			oter_lreg(&lreg_used,vop[1]);
			*/
			Nettoyer_multi_lreg_used(2, top, vop);	/* #FC+BG 03/12/02 */
			ins_lreg(&lreg_used,*v);
		}
		break;

	   /* -----------------
	    * APPEL DE FONCTION
	    * ----------------- */
	   case 5:	/* appel de fonction */
		l = p->ap; arg_verrue = TRUE;
		old_affverrue = aff_verrue; aff_verrue = 0;

		/* Traitement pour les fonctions PROC PTR, SEGMENT PTR, USER PTR */
		/* ------------------------------------------------------------- */
		switch ( p->vl ) {
			case 97: /* PROC PTR */
			case 100: /* SEGMENT PTR */
				if (p->vl == 66)	vptr_verrue = TRUE;
				eval_exp(l->va,&top[0],&vop[0],&tto[0]);
				vptr_verrue = FALSE;

				/* Pour relocation dans module et si
				 procedure ou segment externe */
				if ( notaprog ||
				     ((top[0] == 0) && (vop[0] == 0xFFFF)) ) {
					psuc_desc = l->va->desc;
				}
				Free_ArgList(l);
				break;
			case 99: /* USER PTR */
			default:
				for (i = 0; i < p->na; i++) {
					if (p->vl == 66)
						vptr_verrue = TRUE;
					eval_exp(l->va,&top[i],&vop[i],&tto[i]);
					vptr_verrue = FALSE;
					q = l->suiv; Free_ArgList(l); l = q;
				}
		}		
		/* ------------------------------------------------------------- */

		arg_verrue = argexp; aff_verrue = old_affverrue;
		if ((aff_verrue != 0) && simplexp) {
			/* cas particulier d'une affectation ou la variable
			 * de reception peut etre utilisee comme resultat
			 */
			if (aff_verrue == 1)
				genclf(FALSE,p->vl,p->na,2,adrecep,top,vop,psuc_desc);
			aff_verrue = 0; /* signal affectation deja faite */
		}
		else {	/* cas general de l'appel d'une fonction */
			*t = 3; *v = getreg();
			*to = p->na;
			genclf(FALSE,p->vl,p->na,*t,*v,top,vop,psuc_desc);

			Nettoyer_multi_lreg_used(p->na, top, vop);	/* #FC+BG 03/12/02 */

			ins_lreg(&lreg_used,*v);
		}
		break;

	   /* ------------------
	    * OPERATEURS UNAIRES
	    * ------------------ */
	   case 6:	/* fonction CONV ou STRN */
		if (p->g->tp == 3) {
		/* ne pas modifier les variables registres ici !!! 
		 */
			if (IS_TBIN2(p->g->na)) {
				reg = getreg(); putreg(reg,3,p->g->vr);
				top[0] = 3; vop[0] = reg; tto[0] = p->g->na;
			}
			else {
				top[0] = 2; vop[0] = p->g->vl;
				tto[0] = p->g->na;
			}
		}
		else {
			old_affverrue = aff_verrue; aff_verrue = 0;
			eval_exp(p->g,&top[0],&vop[0],&tto[0]);
			aff_verrue = old_affverrue;
			if ((aff_verrue != 0) && simplexp &&
			    (p->na != (BYTE) 0x00FF)) {	/* CONV inutile */
				conv_verrue = TRUE;
				*t = top[0]; *v = vop[0]; *to = tto[0]; break;
			}
		}
		*t = 3;
		if (p->na != (BYTE) 0x00FF) {	/* CONV */
			*v = genconv(p->na,top[0],vop[0]);
			*to = p->na;
		}
		else { /* STRN : generer CLF "var" lorsqu'on trouve
				 X = STRN (Y) */
			if ((aff_verrue!=0) && (!ind_verrue) && (simplexp)) {
				*t = 2;
				*to = p->na;
				genclf(FALSE,49,1,*t,adrecep,top,vop,psuc_desc);
				aff_is_done = TRUE;
			}
			else {
				*v = getreg();
				*to = p->na;
				genclf(FALSE,49,1,*t,*v,top,vop,psuc_desc);
			}
		}
		break;

	   /* --------------------
	    * FONCTION UTILISATEUR
	    * -------------------- */
	   case 7:	/* fonction utilisateur */
		desapp = (AppFct *)p->desc;
		fct = desapp->fct;
		deb = 0;
		lsimpl = desapp->simple;
		l = p->ap; arg_verrue = TRUE;
		old_affverrue = aff_verrue; aff_verrue = 0;

		/* Si le resultat est de type chaine ou BCD, celui-ci
		 * est passe comme premier argument modifiable a la
		 * fonction
		 */
		if (IS_TBCD(fct->tres)) {
			*t = 3; *v = getreg(); *to = p->na;
			/* Genere un CLF ABS (0 bcd) */ /* (0.000...000 bcd) */
			top[0] = 1;
			vop[0] = cvbintobcd(0,FALSE);
			genclf(FALSE,0,1,3,*v,top,vop,psuc_desc);
			deb = 1;
			top[0] = *t | 0x4;
			vop[0] = *v;
		} else if (IS_TSTR(fct->tres)) {
			*t = 3; *v = getreg();
			*to = p->na;

			/* Genere un CLF SPACE(255) */
			top[0] = 0; vop[0] = 255;
			genclf(FALSE,47,1,3,*v,top,vop,psuc_desc);
			deb = 1;
			top[0] = *t | 0x4;
			vop[0] = *v;
		}

		for (i = deb; i < p->na+deb; i++) {
			/* evalue un argument dans son contexte particulier */
			old_argexp = argexp;
			argexp = TRUE;
			old_simplexp = simplexp;
			simplexp = *(lsimpl + i - deb);
			eval_exp(l->va,&top[i],&vop[i],&tto[i]);
			argexp = old_argexp;
			simplexp = old_simplexp;

			if (fct->moda[i-deb] != 0) {
				if (fct->moda[i-deb] == 1) {
					/* Passage par adresse */
					if (((top[i] != 2) && (top[i] != 3)) ||
					    ((top[i] == 3) && (!simplexp))) {
						/* ni variable ni registre ou */
						/* reg mais expression composee : erreur */
						Free_BOOL(lsimpl);
						Free_AppFct(desapp);
						erreur(USUAL,errfu17);
						sfdln();
						return;
					}
				}
				/* Passage par adresse ou par valeur ? */
				if ((top[i] == 2) || ((top[i] == 3) && (simplexp)))
					top[i] |= 0x4;
			}
			q = l->suiv; Free_ArgList(l); l = q;
		}

		arg_verrue = argexp; aff_verrue = old_affverrue;
		Free_BOOL(lsimpl);
		Free_AppFct(desapp);

		/* Si la fonction a un resultat de type %, il faut
		 * le placer dans un registre
		 */
		if (deb == 0) {
			*t = 3; *v = getreg(); *to = 1;
		}
		genfuser(fct,*t,*v,top,vop,i);
		break;


	   /* -----------------------------------
	    * NEGATION SUR VARIABLE OU EXPRESSION
	    * ----------------------------------- */
	   case 8:	/* negation (seulement sur variable ou expression) */
		if (p->g->tp == 2) { /* variable */
			*t = 3; *v = negvar(p->g->vl); Free_ExpMemb(p->g);
			*to = p->na;	
		}
		else if (p->g->tp == 3) { /* variable "registre" */
			if (IS_TBIN2(p->g->na)) {
				*v = getreg(); putreg(*v,3,p->g->vr);
				*t = 3; negreg(*v);
				*to = p->na;
			}
			else {
				*t = 3; *v = negvar(p->g->vl);
				*to = p->na;
			}
			Free_ExpMemb(p->g);
		}
		else {	/* sous-expression -> produit un registre */
			eval_exp(p->g,&top[0],v,to);
			*t = 3; negreg(*v);
		}
		break;


	   /* ------------------
	    * INDICES DE TABLEAU
	    * ------------------ */
	   case 9:	/* variable dimensionnee */
	   case 10:
		reg = getreg();

		/* Sauvegarde du contexte avant l'appel de l'evaluation
		 * des indices en raison de la salete de conception du
		 * traducteur au niveau de la gestion des "verrues".
		 */
		old_diez_verrue = diez_verrue;
		old_logic_verrue = logic_verrue;
		logic_verrue = FALSE;
		diez_verrue = TRUE;
		ev_indices(reg,p->ap);
		logic_verrue = old_logic_verrue;
		diez_verrue = old_diez_verrue;

		/* Patch pour VPTR(TABLEAU(ELT)) */
		if (vptr_verrue) {
			putadr(reg,p->vl);
			*t = 3; *v = reg; *to = p->na;
			break;
		}
		if ( (!adr_verrue) && (!IS_TSTR(p->na)) && (!IS_TBCD(p->na)) ) {
			if (argexp && simplexp) {
/* 15/11/94 : avant juste putreg() dans ce cas d'ou erreur */
				if (IS_TBIN1(p->na) &&
				    ((ind_verrue && oper_verrue) || logic_verrue ||
				     diez_verrue)) {
					/* cas particulier d'une variable # non signee */
					putsgn();
			  	}
				if (!ind_verrue)	putadr(reg,p->vl);
				else 			putreg(reg,2,p->vl);
/* Fin 15/11/94 */
			} else {
			  if (IS_TBIN1(p->na) &&
			      ((ind_verrue && oper_verrue) || logic_verrue ||
				diez_verrue)) {
				/* cas particulier d'une variable # non signee */
				putsgn();
			  }
			  putreg(reg,2,p->vl);
			}
		}
		else	putadr(reg,p->vl);
		*t = 3; *v = reg; *to = p->na;
		break;

	   /* ---------------------------
	    * APPEL DE FONCTION/PROCEDURE
	    * --------------------------- */
	   case 11:	/* appel de fonction/procedure */
		l = p->ap; arg_verrue = TRUE;
		old_affverrue = aff_verrue; aff_verrue = 0;

		if (p->g != GenericNULL(ExpMemb))
			eval_exp(p->g,&top[(p->na)+1],&vop[(p->na)+1],&tto[(p->na)+1]);

		for (i = 0; i < p->na; i++) {
			if (p->vl == 66)	vptr_verrue = TRUE;
			eval_exp(l->va,&top[i],&vop[i],&tto[i]);
			vptr_verrue = FALSE;
			q = l->suiv; Free_ArgList(l); l = q;
		}
		arg_verrue = argexp; aff_verrue = old_affverrue;

		/* cas general de l'appel d'une fonction */
		*t = 3; *v = getreg();
		*to = p->na;

		top[p->na]=0;
		vop[p->na]=0;

		/* traitement pointeur de fonction */
		if (p->desc == GenericNULL(BYTE)) {
		} else {
			/* traitement des retours de pointeur */
			ptproc = (TabProc *) p->desc;			
			if ( (ptproc->nba & 0xF000) >> 15 ) {
				verrue_retour_ptr = TRUE;
			}
		}

/* #FC+BG 03/12/02 Begin */
		Transferer_lreg_used_to_puhed(p->na+1,top,vop);
/* #FC+BG 03/12/02 End */

#ifdef VERSION_XX
		dproc = (TabProc *) p->desc;
		if (!dproc || !(dproc->ivarb))
		{
#endif
			genclp((TabProc *)p->desc,p->na,top,vop,GenericNULL(char));

#ifdef VERSION_XX
		}
		else
		{
			ivarbreg = ev_indirection(dproc->ivarb,dproc->vitem);
			vop[p->na+1] = ivarbreg; /* dproc->ivarb; */
			top[p->na+1] = 3; /* was 2 means var for now */
			genclsuc(p->na,top,vop,GenericNULL(char));
		}
#endif

		Nettoyer_multi_lreg_used(p->na+2, top, vop);	/* #FC+BG 03/12/02 */

		putreg(*v,*t,maxregs+3);

		/* le registre de retour est candidat */
		if (*t == 3)	ins_lreg(&lreg_used,*v);		// A virer!!!???
		break;

	}
	Free_ExpMemb(p);
}						/* eval_exp */


#ifdef VERSION_XX
BINAIRE	ev_indirection(ivarb,vitem)
BINAIRE ivarb;
BINAIRE vitem;
{
	BINAIRE	reg=0;

	reg = getreg();
	putrix(reg,0,vitem,0);
	ins_lreg(&lreg_used,reg);
	putadr(reg,ivarb);
	return(reg);
}
#endif


static void ev_indices(reg,pind)

/*	evaluation des indices pour une variable dimensionnee,
 *	'reg' est le numero de registre associe (qui peut etre 0
 *	en cas de reference a la variable.
 */
BINAIRE reg;
ArgList *pind;
{						/* ev_indices */
	BYTE	top;
	BINAIRE	vop;
	BOOL	old_adrverrue, old_indverrue;
	BINAIRE	old_affverrue;
	BYTE to;

	old_indverrue = ind_verrue; ind_verrue = TRUE;
	old_adrverrue = adr_verrue; adr_verrue = FALSE;
	old_affverrue = aff_verrue; aff_verrue = 0;
	eval_exp(pind->va,&top,&vop,&to);
	putrix(reg,top,vop,to);
	/* #BG+FC 03/12/02 if (top == 3)	oter_lreg(&lreg_used,vop); */
	Nettoyer_lreg_used(top, vop);	/* #BG+FC 03/12/02 */
	ins_lreg(&lreg_used,reg);

	if (pind->suiv != GenericNULL(ArgList)) { /* 2eme indice */
		eval_exp(pind->suiv->va,&top,&vop,&to);
		putrax(reg,top,vop,to);
		/* #BG+FC 03/12/02 if (top == 3)	oter_lreg(&lreg_used,vop); */
		Nettoyer_lreg_used(top, vop);	/* #BG+FC 03/12/02 */
		ins_lreg(&lreg_used,reg);
		Free_ArgList(pind->suiv);
	}

	Free_ArgList(pind);
	ind_verrue = old_indverrue; adr_verrue = old_adrverrue;
	aff_verrue = old_affverrue;
}						/* ev_indices */

static void eval_oper(p,t,v,to)

/*	evaluation/production de code optimisee pour une operation
 *	representee par l'arbre pointe par 'p', qui est libere pendant
 *	son parcours.
 */
ExpMemb *p;
BYTE	*t;
BINAIRE *v;
BYTE *to;
{						/* eval_oper */
	BYTE	top1,top2;
	BINAIRE	vop1,vop2,reg;
	int	fnt;
	BYTE to1,to2;

#ifdef CR_DEBUG
	printf("\r\nEval_oper : G:%d D:%d",p->g->tp,p->d->tp);
#endif

	/* --------------------------------------------------
	 * Cas particulier ou les deux operandes sont des
	 * valeurs immediates ... on peut faire le calcul ici
	 * -------------------------------------------------- */
	if ((p->g->tp == 0) && (p->d->tp == 0)) {
		*t = 0; *v = calcul(p->vl,p->g->vl,p->d->vl); *to=1;
		Free_ExpMemb(p->g); Free_ExpMemb(p->d);
		return;
	}

	/* ----------------------------------------------------
	 * Cas ou la premiere operande est une variable binaire
	 * non dimensionnee, en memoire et pas externe...
	 * putbin vaut mieux que putreg
	 * ---------------------------------------------------- */
	if ((p->g->tp == 2) && IS_TBIN(p->g->na) &&
	    (*((p->g->desc)+1) == 0) && (p->g->vl & IS_EXTERN != IS_EXTERN)) {
#ifdef CR_DEBUG
		printf(" Cas1 Descr:%0.2X%0.2X-%0.4X Vl:%0.4X",*((p->g->desc)+1),*(p->g->desc),
			*(BINAIRE *)((p->g->desc)+2),p->g->vl);
#endif
		reg = getreg(); fnt = 0;
		if ((p->g->vl & (BINAIRE) ISLOCAL) != 0) {
			fnt = 1;	/* variable locale */
		}
		if (IS_TBIN2(p->g->na)) {
			fnt += 2;	/* var binaire type % */
		}
		else if (ind_verrue || ((p->vl >= 5) && (p->vl <= 7))) {
			/* variable du type # qui ne doit pas etre signee */
			putsgn();
		}
#ifdef CR_LOGIC_DEBUG
		printf("\r\nOPT1 i=%d o=%d l=%d",ind_verrue,oper_verrue,logic_verrue);
#endif
		vop1 = bytetobin((p->g->desc)+2);
		putbin(fnt,reg,vop1,p->g->vl);

		Free_ExpMemb(p->g);
		ins_lreg(&lreg_used,reg);
		eval_exp(p->d,&top2,&vop2,&to2);

		if ( top2 == 3 )
			ins_lreg(&lreg_used,vop2);

		*t = 3; *v = genoper(p->vl,3,reg,top2,vop2,p->na);
		*to = to2;
	 	oter_lreg(&lreg_used,reg);
		/* #BG+FC 03/12/02 if ( top2 == 3 ) oter_lreg(&lreg_used,vop2);*/
		Nettoyer_lreg_used(top2, vop2);	/* #BG+FC 03/12/02 */
		ins_lreg(&lreg_used,*v);
		return;
	}

	/* ------------------------------------------------------
	 * Evaluer le premier operande puisque pas d'optimisation
	 * evidente en ce qui le concerne ...
	 * ------------------------------------------------------ */
#ifdef CR_DEBUG
	printf(" Cas2");
#endif
	eval_exp(p->g,&top1,&vop1,&to1);
	if ( top1 == 3 )
		ins_lreg(&lreg_used,vop1);
	if ( top1 == 3 ) { oper_verrue = logic_verrue = FALSE; }

	/* --------------------------------------------------------
	 * Cas ou l'operation est commutative, la premiere operande
	 * n'est pas en registre, et la deuxieme operande est une 
	 * variable binaire non dimensionnee en memoire et pas
	 * externe... putbin vaut mieux que putreg
	 * -------------------------------------------------------- */
	if ( (commutatif(p->vl)) && (top1 != 3) &&
	     (p->d->tp == 2) && IS_TBIN(p->d->na) &&
	     (*((p->d->desc)+1) == 0) && (p->d->vl & IS_EXTERN != IS_EXTERN)) {
		reg = getreg(); fnt = 0;
		if (((p->d->vl) & (BINAIRE) ISLOCAL) != 0) {
			fnt = 1;	/* variable locale */
		}
		if (IS_TBIN2(p->d->na)) {
			fnt += 2;	/* var binaire type % */
		}
		else if (ind_verrue || ((p->vl >= 5) && (p->vl <= 7))) {
			/* variable du type # qui ne doit pas etre signee */
			putsgn();
		}
#ifdef CR_LOGIC_DEBUG
		printf("\r\nOPT2 i=%d o=%d l=%d",ind_verrue,oper_verrue,logic_verrue);
#endif
		vop2 = bytetobin((p->d->desc)+2); Free_ExpMemb(p->d);

		putbin(fnt,reg,vop2,p->d->vl);

		*t = 3; *v = genoper(p->vl,3,reg,top1,vop1,p->na);
		*to = to1;
		/* #BG+FC 03/12/02if ( top1 == 3 ) oter_lreg(&lreg_used,vop1); */
		Nettoyer_lreg_used(top1, vop1);	/* #BG+FC 03/12/02 */
		ins_lreg(&lreg_used,*v);
		return;
	}

	/* --------------------------------------------------------------
	 * Cas general ...
	 * Attention : si on est en cours d'optimisation d'une expression
	 * chaine ou BCD, il ne faut pas optimiser de la meme maniere
	 * les sous-arbres de droite (regles de parenthesage).
	 * -------------------------------------------------------------- */
#ifdef CR_DEBUG
	printf(" Cas3");
#endif
#ifdef CR_LOGIC_DEBUG
	printf("\r\nOPT3 i=%d o=%d l=%d",ind_verrue,oper_verrue,logic_verrue);
#endif

	eval_exp(p->d,&top2,&vop2,&to2);
	if ( top2 == 3 )
		ins_lreg(&lreg_used,vop2);

	if ((top1 == 0) && (top2 == 0)) {
		/* cas particulier ou les deux operandes sont des
		 * valeurs immediates ... on peut faire le calcul ici
		 */
		*t = 0; *v = calcul(p->vl,vop1,vop2); *to=1;
		return;
	}

	oper_verrue = logic_verrue = FALSE;
	*t = 3;
	*v = genoper(p->vl,top1,vop1,top2,vop2,p->na);
	*to = to2;
	/* #BG+FC 03/12/02
	if ( top1 == 3 ) oter_lreg(&lreg_used,vop1);
	if ( top2 == 3 ) oter_lreg(&lreg_used,vop2); */
	Nettoyer_lreg_used(top1, vop1);	/* #BG+FC 03/12/02 */
	Nettoyer_lreg_used(top2, vop2);	/* #BG+FC 03/12/02 */
	ins_lreg(&lreg_used,*v);
}						/* eval_oper */

static BINAIRE calcul(oper,vx,vy)

/*	calcule la valeur d'une operation arithmetique ou logique
 *	simple entre deux valeurs binaires ABAL : "vx oper vy"
 */
BINAIRE oper,vx,vy;
{						/* calcul */
	BINAIRE v;

	switch (oper) {
	  case 0:	v = vx + vy; break;
	  case 1:	v = vx - vy; break;
	  case 2:	v = vx * vy; break;
	  case 3:	v = vx / vy; break;
	  case 4:	v = vx % vy; break;
	  case 5:	v = vx & vy; break;
	  case 6:	v = vx | vy; break;
	  case 7:	v = vx ^ vy;
	}
	return (v);
}						/* calcul */

static BOOL commutatif(opr)

/*	retourne la valeur 'TRUE' si l'operateur de code 'opr'
 *	est commutatif, et la valeur 'FALSE' sinon.
 */
BINAIRE opr;
{						/* commutatif */
	switch (opr) {
	  case 0:	return (TRUE);	/* addition */
	  case 1:	break;		/* soustraction */
	  case 2:	return (TRUE);	/* multiplication */
	  case 3:			/* division */
	  case 4:	break;		/* reste de division entiere */
	  case 5:			/* et logique */
	  case 6:			/* ou logique */
	  case 7:	return (TRUE);	/* ou exclusif */
	  case 8:	break;		/* concatenation */
	}
	return (FALSE);
}						/* commutatif */


/*
 *	TRAITEMENT DES EXPRESSIONS CONDITIONNELLES
 *	------------------------------------------
 */
CdMemb *expcond()
{
CdMemb *arbre;

	libreg = firstreg;  nb_pad = 0;
	lexical();
	arbre = tr_cond();	
	return(arbre);
}

CdMemb *tr_cond()
{
        CdMemb *op1,*op2,*racine;      /* ss-arbres operandes */
        BINAIRE opr;
        Code_Synt oper;

        if ((op1 = tr_relat()) == GenericNULL(CdMemb)) {
                /* abandon si 1er terme incorrect */
                sfdln(); return (GenericNULL(CdMemb));
        }
        oper = usc.code;
        while ((oper == AND) || (oper == OR)) {
                lexical();      /* avaler l'operateur */
                if ((op2 = tr_relat()) == GenericNULL(CdMemb)) {
                        /* recherche 2eme terme a echoue --> abandon */
                        sfdln(); return (GenericNULL(CdMemb));
                }
                /* creer nouveau noeud de l'arbre */
                opr = valeur(oper);
                racine = All_CdMemb();
                if (racine == GenericNULL(CdMemb)) { /* debordement memoire */
                        libcond(op1); libcond(op2); erreur(FATALE,errmem);
                }

		racine->g = op1; racine->d = op2; racine->tmb = 4;
		if (oper == OR)
			racine->vmb = 1;
		else /* AND */
			racine->vmb = 0;

		/* continuer avec la racine comme sous-arbre gauche */
		op1 = racine; oper = usc.code;
        }
        /* le resultat final est le premier terme courant */
        return (op1);
}


void poslex(long s, BYTE* l, int c, long n)
{ 
	seekcur=s; 
	Xfseek(input,seekcur,0); 
	lptr=Xfgets(ligne, LGLIGNE, input); 
	posinsce=s+((long int)(Xstrlen(lptr)-1))+LgCRLF; 
	clncur=c; lptr=l; 
	poslgn=n; 
}


CdMemb *tr_relat()
/*      construction d'un ss-arbre 'terme' dans une expression,
 *       en entree 'tres' indique le type de resultat attendu.
 *      si 'tres' vaut T_ANY, le type attendu est quelconque, et est mis a
 *      jour au retour.
 *      la fonction retourne NULL si il y a une erreur, un pointeur sur
 *      le ss-arbre sinon.
 */
{                                       /* tr_terme */
        CdMemb *op;
        BOOL    sgn = FALSE, stay_pad = FALSE;

	long int tseek;
	BYTE *tptr;
	int tcln;
	BYTE tusc;
	long int tnum;

	/* Sauvegarde de l'etat de l'analyse */
	tnum = numlgn;
	tseek = seekcur;
	tptr = lptr;
	tcln = clncur;
	tusc = usc.code;

	op=condition();
	if ( (op == GenericNULL(CdMemb)) && (tusc == PAG) ) 
	{
		if ( nb_pad != 0 ) 
		{
			poslex(tseek,tptr,tcln,tnum);

			usc.code= tusc;
			if ( usc.code == PAG ) 
			{
				lexical();      /* avaler la parenthese */
				op = tr_cond();
				if (op == GenericNULL(CdMemb)) 
					return (GenericNULL(CdMemb));

				if ( (usc.code != PAD) ) 
				{
					erreur(USUAL,erexp8); libcond(op);
 					return (GenericNULL(CdMemb));
				} 
				else 
				{
					lexical();
					return(op);
				}
			} 
			else 
			{
				erreur(USUAL,erexp8);
				return (op);
			}
		} 
		else 
		{
			erreur(USUAL,erexp8);
			return (op);
		}
	} 
	else 
	{
		/* le resultat final est le premier facteur courant */
		return(op);
	}
}

static CdMemb *condition()

/* 	cette fonction construit le sous-arbre d'evaluation d'une condition,
 *	qui est insere a partir de la branche 'p'.
 *	elle retourne la valeur 'TRUE' si Ok, et 'FALSE' en cas d'erreur
 */
{					/* condition */
	BYTE		t,texp;
	BINAIRE		vexp,relat;
	CdMemb		*p1 = GenericNULL(CdMemb);
	CdMemb		*p2 = GenericNULL(CdMemb);
	CdMemb		*racine = GenericNULL(CdMemb);

	ExpMemb	*arbre = GenericNULL(ExpMemb);
	BYTE 		tout;

	/* condition = expression, relation, expression */

	t = T_ANY; /* recherche d'une 1ere expression quelconque */
	cond_verrue = TRUE;
	arg_verrue = argexp;
	simplexp = TRUE;
	nb_pad = 0;
	arbre = tr_exp(&t);
	if ( arbre != GenericNULL(ExpMemb) ) {
		if ( nb_pad != 0 ) {
			lib_exp(arbre);
			return(p1);
		} else {
			eval_exp(arbre,&texp,&vexp,&tout);

		cond_verrue = FALSE;
		p1 = All_CdMemb();
		if (p1 == GenericNULL(CdMemb)) /* debordement memoire ? */
			erreur(FATALE,errmem);
		p1->tmb = texp; p1->vmb = vexp;
		if (texp == 2) {	/* variable ! */
			p1->tvar = typdesc(pdop);
			p1->adr = bytetobin(pdop+2);
		}
		p1->g = p1->d = GenericNULL(CdMemb);
		
		if (isrelation(usc.code,&relat)) {
		    if ( (!IS_TSTR(t)) &&
			 ((usc.code == EQSTR) || (usc.code == NIN)) ) {
			  erreur(USUAL,erexp11); libcond(p1);
		 	  racine = GenericNULL(CdMemb);
			  lexical();	/* avaler l'operateur */
		    }
		    else {
			if ((IS_TSTR(t)) && (usc.code == EGAL)) 
				relat = 6; /* '=' -> 'IN' pour chaines */
			lexical();	/* avaler l'operateur */
			if (!expression(&t,&texp,&vexp)) {
				libcond(p1); racine = GenericNULL(CdMemb);
			}
			else {
				p2 = All_CdMemb();
				if (p2 == GenericNULL(CdMemb))
					erreur(FATALE,errmem); /* deb. mem */
				p2->tmb = texp; p2->vmb = vexp;
				if (texp == 2) {	/* variable ! */
					p2->tvar = typdesc(pdop);
					p2->adr = bytetobin(pdop+2);
				}
				p2->g = p2->d = GenericNULL(CdMemb);
				racine = All_CdMemb();
				if (racine == GenericNULL(CdMemb))
					erreur(FATALE,errmem); /* deb. mem */
				racine->g = p1; racine->d = p2;
				racine->tmb = 5; racine->vmb = relat;
			}
		    }
		}
		else { /* operateur de relation attendu et non trouve */
			erreur(USUAL,erexp12); libcond(p1);
			racine = GenericNULL(CdMemb);
		}
		}
	} else {
		cond_verrue = FALSE;
	/* le resultat final est la racine */
	}
	return (racine);
}					/* condition */

static BOOL isrelation (code,r)

/*	teste si le code donne en argument est un operateur relationnel
 *	et si oui, met a jour le parametre 'r' suivant la regle :
 *	'=' : 0 , '<>' : 1 , '>=' : 2 , '<=' : 3 , '>' : 4 , '<' : 5
 *	'IN' : 6 , 'NIN' : 7
 */
Code_Synt code;
BINAIRE	  *r;
{					/* isrelation */
	switch (code) {
	  case EGAL:
	  case EQSTR:
		*r = 0; break;
	  case DIFF:
		*r = 1; break;
	  case SUPE:
		*r = 2; break;
	  case INFE:
		*r = 3; break;
	  case SUP:
		*r = 4; break;
	  case INF:
		*r = 5; break;
	  case NIN:
		*r = 7; break;
	  default:
		return (FALSE);
	}
	return (TRUE);
}					/* isrelation */

void evalcond(BOOL sens, CdMemb* p, char* adr)

/*	evaluation d'une expression conditionnelle relative a l'etiquette 'adr'
 *	en produisant le code a partir de l'arbre pointe par 'p',
 *	et en sens direct si 'sens' = TRUE, ou inverse si 'sens' = FALSE.
 *	l'arbre est libere pendant son evaluation.
 */
{					/* evalcond */
	char	adraux[LGIDENT];
	BYTE	top;
	BINAIRE vop;

	/* Traitement d'une liaison entre deux conditions */
	if (p->tmb == 4) 
	{
		if (p->vmb == 0) 
		{	/* AND */
		   if (sens) 
			{
				cretiq(adraux);
				evalcond(FALSE,p->g,adraux); 
				evalcond(TRUE,p->d,adr);
				defetiq(adraux,(BINAIRE) adrimpl);
		   }
		   else 
			{
				evalcond(FALSE,p->g,adr); 
				evalcond(FALSE,p->d,adr);
		   }
		}
		else 
		{			/* OR */
			if (sens) 
			{
				evalcond(TRUE,p->g,adr); 
				evalcond(TRUE,p->d,adr);
			}
			else 
			{
				cretiq(adraux);
				evalcond(TRUE,p->g,adraux); 
				evalcond(FALSE,p->d,adr);
				defetiq(adraux,(BINAIRE) adrimpl);
			}
		}
		Free_CdMemb(p);
	}
	/* traitement d'une relation entre deux operandes */
	else if (p->tmb == 5) 
	{
		if (p->g->tmb == 2) 
		{
			top = 3; 
			vop = getreg();	/* passer par un registre */
			
			if (! IS_TBIN(p->g->tvar) ) 
			{
				/* 1ere operande = variable chaine ou BCD */
				putadr(vop,p->g->vmb);
			}
			else 
			{ 
				/* 1ere operande = variable binaire */
				putreg(vop,2,p->g->vmb);
			}
		}
		else 
		{ 
			/* 1ere operande n'est pas une variable */
			top = p->g->tmb; 
			vop = p->g->vmb;
		}

		Free_CdMemb(p->g);
		genrelat(sens,p->vmb,top,vop,p->d->tmb,p->d->vmb,adr);

		Nettoyer_lreg_used(top, vop); /* #FC+BG 03/12/02 */
		Nettoyer_lreg_used(p->d->tmb, p->d->vmb); /* #FC+BG 03/12/02 */

		Free_CdMemb(p->d); 
		Free_CdMemb(p);
	}
}					/* evalcond */

void libcond(p)

/*	liberation de l'arbre d'evaluation d'expression conditionnelle
 *	pointe par le parametre 'p'
 */
CdMemb *p;
{					/* libcond */
	if (p->g != GenericNULL(CdMemb))
		libcond(p->g);
	if (p->d != GenericNULL(CdMemb))
		libcond(p->d);
	Free_CdMemb(p);
}					/* libcond */



static void init_lreg(RegList** ptlreg)
{
	if ( *ptlreg != GenericNULL(RegList) )
		lib_lreg(ptlreg);
}

static void lib_lreg(ptlreg)
RegList **ptlreg;
{
RegList *lreg2;
	lreg2 = *ptlreg;
	while ( lreg2 != GenericNULL(RegList) ) {
		*ptlreg = lreg2->suiv;
		Free_RegList(lreg2);
		lreg2 = *ptlreg;
	}
	*ptlreg = GenericNULL(RegList);
	return;
}

static void push_lreg(ptlreg,reg)
RegList **ptlreg;
BINAIRE reg;
{
RegList *lreg2;

	if ( *ptlreg == GenericNULL(RegList) ) {
		if ( (*ptlreg = All_RegList()) == GenericNULL(RegList) )
			erreur(FATALE,errmem); /* deb. mem */
		(*ptlreg)->reg = reg;
		(*ptlreg)->suiv = GenericNULL(RegList);		
	} else { 
		lreg2 = *ptlreg;
		if ( (*ptlreg = All_RegList()) == GenericNULL(RegList) )
			erreur(FATALE,errmem); /* deb. mem */
		(*ptlreg)->reg = reg;
		(*ptlreg)->suiv = lreg2;		
	}
}

BOOL find_lreg(lreg,reg)
RegList *lreg;
BINAIRE reg;
{
BOOL trouve = FALSE;

	while ( lreg != GenericNULL(RegList) ) {
		if ( lreg->reg == reg ) {
			trouve = TRUE;
			break;
		}
		lreg = lreg->suiv;
	}
	return(trouve);
}

void oter_lreg(ptlreg,reg)
RegList **ptlreg;
BINAIRE reg;
{
RegList *lreg;
RegList *lregp;
BOOL trouve = FALSE;

	lregp = GenericNULL(RegList);
	lreg = *ptlreg;
	while ( lreg != GenericNULL(RegList) ) {
		if ( lreg->reg == reg ) {
			trouve = TRUE;
			break;
		}
		lregp = lreg;
		lreg = lreg->suiv;
	}
	if ( trouve ) {
		if ( lregp == GenericNULL(RegList) ) {
			*ptlreg = lreg->suiv;
		} else {
			lregp->suiv = lreg->suiv;
		}
		Free_RegList(lreg);
	}	
}

void ins_lreg(ptlreg,reg)
RegList **ptlreg;
BINAIRE reg;
{
RegList *lregp; 
RegList *lreg;

	if ( ! find_lreg(*ptlreg,reg) ) {
		/* insertion en queue */
		lregp = GenericNULL(RegList);
		lreg = *ptlreg;
		while ( lreg != GenericNULL(RegList) ) {
			lregp = lreg;
			lreg = lreg->suiv;
		}
		if ( lregp == GenericNULL(RegList) ) {
			if ( (*ptlreg = All_RegList()) == GenericNULL(RegList) )
				erreur(FATALE,errmem); /* deb. mem */
			(*ptlreg)->reg = reg;
			(*ptlreg)->suiv = GenericNULL(RegList);		
		} else {
			if ( (lreg = All_RegList()) == GenericNULL(RegList) )
				erreur(FATALE,errmem); /* deb. mem */
			lreg->reg = reg;
			lreg->suiv = GenericNULL(RegList);
			lregp->suiv = lreg;		
		}
	}
}

static BINAIRE pop_lreg(ptlreg)
RegList **ptlreg;
{
BINAIRE reg = 0xFFFF;
RegList *lreg2;
	
	if ( *ptlreg == GenericNULL(RegList) ) {
		return (reg);
	}

	reg = (*ptlreg)->reg;

	lreg2 = (*ptlreg)->suiv;

	Free_RegList(*ptlreg);

	*ptlreg = lreg2;

	return(reg);
}


static RegList *lreg_cursor=GenericNULL(RegList);

/* #FC+BG 03/12/02 
static BINAIRE debut_lreg(lreg)
RegList *lreg;
{
BINAIRE reg = 0xFFFF;
		
	lreg_cursor = lreg;

	reg = suivant_lreg();

	return(reg);
}

static BINAIRE suivant_lreg()
{
BINAIRE reg = 0xFFFF;

	
	if ( lreg_cursor == GenericNULL(RegList) ) {
		return (reg);
	}

	reg = lreg_cursor->reg;

	lreg_cursor = lreg_cursor->suiv;

	return(reg);
}
*/
static BOOL findreg(nb,top,vop,reg)
BINAIRE nb;
BYTE top[];
BINAIRE vop[];
BINAIRE reg;
{
BOOL trouve = FALSE;
BINAIRE i;

	i = 0;
/* #FC+BG 03/12/02	while ( i < nb ) {*/
	while ( i <= nb ) {
		if ( (top[i] == 3) && (vop[i] == reg) ) {
			trouve = TRUE;
			break;
		}
		i++;
	}
	return(trouve);	
}

void init_suivi_registre()
{
	init_lreg(& lreg_pushed);
	init_lreg(& lreg_used);	
}

/* #FC+BG 03/12/02 Begin */
void init_contexte_registre(BINAIRE* psav_libreg, RegList** psav_lreg_used, RegList** psav_lreg_pushed)
{
	if (psav_libreg)
		*psav_libreg = libreg;
	if (psav_lreg_used)
		*psav_lreg_used = lreg_used;
	if (psav_lreg_pushed)
		*psav_lreg_pushed = lreg_pushed;

	libreg = firstreg;
	lreg_pushed = NULL;
	lreg_used = NULL;	
}


void restitue_contexte_registre(BINAIRE sav_libreg, RegList* sav_lreg_used, RegList* sav_lreg_pushed)
{
	init_lreg(&lreg_pushed);
	init_lreg(&lreg_used);	

	libreg = sav_libreg;
	lreg_used = sav_lreg_used;
	lreg_pushed = sav_lreg_pushed;
}
/* #FC+BG 03/12/02 End */


void genpopreg(reg)
BINAIRE reg;
{
	BINAIRE reg2;

	if ( find_lreg(lreg_pushed,reg))
	{
		do
		{
			reg2 = pop_lreg(&lreg_pushed);
			/* On utilise ins_lreg() et non push_lreg() pour insérer ds lreg_used qui n'est pas ordonnée.*/
			ins_lreg(&lreg_used,reg2);
			popreg(reg2);
		}
		while ( reg2 != reg );
	}

/* #FC+BG 03/12/02 Original code
BINAIRE marque;
		marque = reg2;
		while ( reg2 != reg ) {
			popreg(reg2);
			push_lreg(&lreg_used,reg2);
			reg2 = pop_lreg(&lreg_pushed);
		}
		popreg(reg2);
	}	
*/
}

void genpopall()
{
	BINAIRE p_reg;

	p_reg = pop_lreg(&lreg_pushed);
	while ( p_reg != 0xFFFF )
	{
		popreg(p_reg);
		p_reg = pop_lreg(&lreg_pushed);
	}
}



/*	#FC+BG 03/12/02 Begin */
void Nettoyer_multi_lreg_used(BINAIRE nbargs, BYTE top[], BINAIRE vop[])
{
	/* Ces registres ne sont plus utilisés, donc il faut les ôter de la liste des registres utilisés
	   pour qu'ils ne soient pas pushés plus loin.
	*/
	BINAIRE i;

	for(i = 0; i <nbargs; i++)
		if (top[i] == 3)
			oter_lreg(&lreg_used, vop[i]);	
}


void Nettoyer_lreg_used(BYTE top, BINAIRE vop)
{
	/* Ce registre n'est plus utilisé, donc il faut l'ôter de la liste des registres utilisés
	   pour qu'il ne soit pas pushé plus loin.
	*/

	if (top == 3)
		oter_lreg(&lreg_used, vop);	
}

/* Cette fonction devrait remplacer tous les appels directs à ins_lreg(). A faire ultérieurement! */
void Inserrer_lreg_used(BYTE top, BINAIRE vop)
{
	if (top == 3)
		ins_lreg(&lreg_used, vop);	
}


void Transferer_lreg_used_to_puhed(BINAIRE nbargs, BYTE top[], BINAIRE vop[])
{
	RegList*	pUsed = lreg_used;
	RegList*	pUsedPrev = GenericNULL(RegList);

	while (pUsed)
	{
		if (findreg(nbargs, top, vop, pUsed->reg))
		{
			pUsedPrev = pUsed;
			pUsed = pUsed->suiv;
		}
		else
		{
			pushreg(pUsed->reg);

			if (pUsedPrev == GenericNULL(RegList))
			{
				lreg_used = pUsed->suiv;
				pUsed->suiv = lreg_pushed;
				lreg_pushed = pUsed;
				pUsed = lreg_used;
			}
			else
			{
				pUsedPrev->suiv = pUsed->suiv;
				pUsed->suiv = lreg_pushed;
				lreg_pushed = pUsed;
				pUsed = pUsedPrev->suiv;
			}
		}
	}
}

/* #FC+BG 03/12/02 End */
