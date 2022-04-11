/*
 *      Projet  : ABAL                  Copyright Amenesik / Sologic s.a. (c) 1990, 1995
 *      Module  : ATR
 *      Fichier : EXPR1.C
 *      Version : 2.2b
 *      Date    : 21/11/95
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Traitement des expressions 1/2]
 *
 */

 /*
 * Mises a jour :
 * ------------
 * 18/07/90 : Mise en conformite avec les versions 1.2e / 1.3a / 1.4a
 * 24/10/90 : Introduction EVENTADR HOTKEY et SYSERROR
 * 07/12/90 : Correction anomalie nombre d'argument de fonction
 *            utilisateur nul
 * ---------- Sortie 1.2f / 1.3c / 1.4a -----------------------------
 * 20/08/91 : Modif mineure du style d'ecriture
 *	------------------------------------------------------------------
 * 16/04/93 : FM : probleme lie au nouveau type ptr
 *	----------- Sortie 2.1b ------------------------------------------
 * 04/03/94 : Exception lors de l'utilisation de CODE comme variable
 *	----------- 2.1c -------------------------------------------------
 *	31/05/94 : Conversion pour tansfert en retour de fonction exitexpr()
 *	02/06/94 : En retour de fonction proc mettre a jour tres : fnt_proc()
 *	07/06/94 : ProblŠme de division avec procedure/resultat : fnt_proc()
 *	08/06/94 : expression() efface argexp. dans le cas p1(t(i+1))
 *		   il faut qu'il reste present.
 *	20/06/94 : test de bcd_priority pour conversion CBIN en CBCD
 *	11/07/94 : relocation sur No de procedure et segment dans module
 *	11/07/94 : correction probleme VPTR sur expression dans d'instruction
 *		   NGF (adr_verrue). A valider...
 *	17/08/94 : correction DIT 3363 sauvegarde index R0 sur affectation 
 *	26/10/94 : Test si pointeur de procedure ($=5)
 *	------------ 2.1d -------------------------------------------------
 *	21/11/95 : version dediee 2.1
 *	------------ 2.2a -------------------------------------------------
 * 07/03/97 : Prototype de findvar() modifie, reprise de tous les appels
 *
 * 20/04/99 : (#AT) Enhancement ATR 24: Check of types into procedure header 
 *            (forward, implementation and call)
 *
 * 13/09/99 : (#AT) Bug ATR 6 fixed: Prohibit to pass integer parameters to 
 *            procedure if formal parameters has type ptr.
 *
 * 22/11/99 : (#AT) Enhancement ATR. BINARY function.
 * 09/03/00 : (#OK) Bug ATR 48 fixed. Procedure return code in array variable.
 * 17/03/00 : (#AT) Bug ATR ?? fixed. Exception in zlibrary.
 * 21/03/00 : (#OK) Bug ATR 33 fixed. Utilisation de pointeurs sur procedures. 
 * 05/06/02 : (#SP) Bug ATR 74 fixed.
 * 18/06/02 : (#OK) Bug ATR 71 fixed. Incorrect format in function PRINT.
 *	------------ 2.2b -------------------------------------------------
 */

/*
 *      INITIALISATION DU MODULE
 *      ------------------------
 */

/* #AT: 22/11/99 (begin)*/
#ifdef __ATR22__
char getcar();
#endif
/* #AT: 22/11/99 (fin)*/

void initexp()

/*      initialisation du traitement des expressions
 */
{                                                       /* initexp */
        ind_verrue = arg_verrue = adr_verrue = argexp = FALSE;
        diez_verrue = FALSE;
        adrref_verrue = FALSE;
        oper_verrue = logic_verrue = FALSE;
        aff_verrue  = 0;
        vptr_verrue = FALSE;
}                                                       /* initexp */

/*
 *      AFFECTATION et REFERENCE A UNE VARIABLE
 *      ---------------------------------------
 */
BOOL exitexpr(typret)		/* Suppression advar et adesc !!! */
BYTE typret;	/* type de retour de la procedure */
{                                       /* exitexpr */
        int  fnt,nbargs;
        BYTE typ,tres,tdem[4],targ[4],*pdesc;
        BINAIRE vres,varg[4],reg;

	lexical();
        if (usc.code != PAG) {  /* erreur : '(' attendue */
       	        erreur(USUAL,ersynt19); sfdln(); return(FALSE);
       	} else {

	typ = typret;

        libreg = firstreg;
	lexical();
        switch (usc.code) {     /* cas des fonctions speciales */
        case INSERT:
                fnt = 63; goto incins;  /* meme syntaxe que INCLUD */
        case INCLUD:
                fnt = 21;
incins:
                if (!tststrres(&typ)) {
                        sfdln(); return (FALSE);
                }
                lexical(); nbargs = 2;
                if (usc.code != PAG) {
                        erreur(USUAL,erexp7); sfdln(); return (FALSE);
                }
                lexical();
                tdem[0] = TBIN;
                if (!expression(&tdem[0],&targ[0],&varg[0])) {
                        sfdln(); return (FALSE);
                }
                if (usc.code != VIG) {
                        erreur(USUAL,erexp9); sfdln(); return (FALSE);
                }
                lexical(); tdem[1] = TSTR;
                if (!expression(&tdem[1],&targ[1],&varg[1])) {
                        sfdln(); return (FALSE);
                }
                if (usc.code == VIG) {  /* 3eme argument explicite */
                        nbargs = 3;
                        lexical(); tdem[2] = TBIN;
                        if (!expression(&tdem[2],&targ[2],&varg[2])) {
                                sfdln(); return (FALSE);
                        }
                }
                if (usc.code != PAD) {
                        erreur(USUAL,erexp8); sfdln(); return (FALSE);
                }
                genclf(FALSE,fnt,nbargs,2,0,targ,varg,GenericNULL(BYTE)); /* advar=0*/
                lexical(); break;
        case SWAP:
                fnt = 64; goto sw_mov;
        case MOVE:
                fnt = 34;
sw_mov:
                lexical();
                nbargs = 3; tdem[0] = T_ANY; tdem[1] = tdem[2] = TBIN;
                adr_verrue = TRUE;
                if (!recargs(nbargs,tdem,targ,varg)) {
                        sfdln(); return (FALSE);
                }
                lexical();
                genclf(FALSE,fnt,nbargs,2,0/*advar*/,targ,varg,GenericNULL(BYTE));
                break;
        case FM:        /* format d'edition ou de saisie */
                lexical();
                if (usc.code != PAG) {
                        erreur(USUAL,erexp7); sfdln(); return (FALSE);
                }
                fmt_verrue = TRUE;
                lexical();
                fmt_verrue = FALSE;

                if (usc.code == PAG) { /* reference par une variable */
                        lexical();
                        reg = getreg();
                        if (!reference(reg,&pdesc,&varg[0],&targ[0],&typ)) {
                                sfdln(); return (FALSE);
                        }
                        if ( ! IS_TSTR(typ) ) {
                                erreur(USUAL,erexp3); sfdln(); return (FALSE);
                        }
                        genffm(0/*advar*/,targ[0],varg[0],GenericNULL(char));
                        lexical();
                        if (usc.code != PAD) {
                                erreur(USUAL,erexp8); sfdln(); return (FALSE);
                        }
                }
                else if (usc.code != CSTR) { /* erreur : format incorrect */
                        erreur(USUAL,erexp13); sfdln(); return (FALSE);
                     }
                     else
                        genffm(0/*advar*/,0,0,usc.v.pval);
                lexical();
                if (usc.code != PAD) {
                        erreur(USUAL,erexp8); sfdln(); return (FALSE);
                }
                lexical(); /* avaler la parenthese */
                break;
        case PRINT:     /* PRINT dans une variable */
                if (!tststrres(&typ)) {
                        sfdln(); return (FALSE);
                }				
                if (!trfnprn(0/*advar*/)) {
                        sfdln(); return (FALSE);
                }
                break;
        case TRAN:
                if (!tststrres(&typ)) {
                        sfdln(); return (FALSE);
                }
                lexical();
                nbargs = 4; tdem[0] = tdem[1] = tdem[3] = TSTR; tdem[2] = TBIN;
                if (!recargs(nbargs,tdem,targ,varg)) {
                        sfdln(); return (FALSE);
                }
                lexical();
                genclf(FALSE,54,nbargs,2,0 /*advar*/,targ,varg,GenericNULL(BYTE));
                break;
        default:
                /* prevoir un simple appel de fonction */
		typ = typret;
                /* laisser la possibilite aux autres de faire l'affectation */
                aff_is_done = FALSE;
                vptreg = 0;

                regrecep=maxregs+3;

                /* prevoir une affectation simple avec CONV */
                conv_verrue = FALSE;
                if (!expression(&typ,&tres,&vres))
                        return (FALSE);
	        if (aff_is_done == FALSE) {     /* affectation reste a faire */
			if ( tres == 2 ) { /* variable */
				if ( ((vres & ISLOCAL) != 0) && (typret & 0x02) ) {
					putadr(regrecep,vres);
					genconv(typret,3,regrecep);	
				} else {
	                       		putreg(regrecep,tres,vres);
				}
			} else {
                       		putreg(regrecep,tres,vres);
				if ( (typ == TSTR) || (typ == TBCD) ) 
					genconv(typret,3,regrecep);	
			}
	        	aff_verrue = 0;
		}
	}
	}
        return (TRUE);
}                                       /* exitexpr */

BOOL affectation(adesc,advar)

/*      instruction d'affectation : adesc et advar concernent la
 *      variable de reception
 */
BYTE *adesc;
BINAIRE advar;
{                                       /* affectation */
        int  fnt,nbargs;
        BYTE typ,tres,tdem[4],targ[4],*pdesc;
        BINAIRE vres,varg[4],reg;
        ExpMemb *op;
        char adr[LGIDENT];

        if (adesc == GenericNULL(BYTE)) {
                erreur(USUAL,erexp6); sfdln(); return (FALSE);
        }
	typ = typdesc(adesc);

        if ((*adesc & PRIMARY_INDEX) != 0) {      /* il y a des dimensions */
                /* creer le noeud "membre d'expression" */
                op = All_ExpMemb();
                if (op == GenericNULL(ExpMemb)) {
                        erreur(FATALE,errmem);
                }
                op->g = op->d = GenericNULL(ExpMemb);
                op->ap = GenericNULL(ArgList);
                if (!tr_dim(op,adesc)) {
                        Free_ExpMemb(op); sfdln(); return (FALSE);
                }
                libreg = firstreg;

                /* Traite le cas du FOR..NEXT avec variable de
                 * controle de boucle indicee
                 */
                if (verrue_for) {
                        cretiq(adr);
                        gengoto(adr);
                        cretiq(gletiq);
                        defetiq(gletiq,(BINAIRE)adrimpl);
                        ev_indices(0,op->ap);
                        genret();
                        defetiq(adr,(BINAIRE)adrimpl);
                        gengosb(gletiq);
                }
                else
                        ev_indices(0,op->ap);
                Free_ExpMemb(op);
        }
        lexical();
        
		/*
		if (usc.code == SPT) {
           lexical();		   
      	   if (findvar(usc.v.pval,GenericNULL(BYTE),&advar,GenericNULL(TabSymb *),TRUE) == GenericNULL(BYTE))
			  return(GenericNULL(BYTE));
		}
        else
		*/

        if (usc.code != EGAL) {
                erreur(USUAL,erexp2); sfdln(); return (FALSE);
        }
        lexical();      /* avaler l'operateur d'affectation */
        libreg = firstreg;
        switch (usc.code) {     /* cas des fonctions speciales */
        case INSERT:
                fnt = 63; goto incins;  /* meme syntaxe que INCLUD */
        case INCLUD:
                fnt = 21;
incins:
                if (!tststrres(&typ)) {
                        sfdln(); return (FALSE);
                }
                lexical(); nbargs = 2;
                if (usc.code != PAG) {
                        erreur(USUAL,erexp7); sfdln(); return (FALSE);
                }
                lexical();
                tdem[0] = TBIN;
                if (!expression(&tdem[0],&targ[0],&varg[0])) {
                        sfdln(); return (FALSE);
                }
                if (usc.code != VIG) {
                        erreur(USUAL,erexp9); sfdln(); return (FALSE);
                }
                lexical(); tdem[1] = TSTR;
                if (!expression(&tdem[1],&targ[1],&varg[1])) {
                        sfdln(); return (FALSE);
                }
                if (usc.code == VIG) {  /* 3eme argument explicite */
                        nbargs = 3;
                        lexical(); tdem[2] = TBIN;
                        if (!expression(&tdem[2],&targ[2],&varg[2])) {
                                sfdln(); return (FALSE);
                        }
                }
                if (usc.code != PAD) {
                        erreur(USUAL,erexp8); sfdln(); return (FALSE);
                }
                genclf(FALSE,fnt,nbargs,2,advar,targ,varg,GenericNULL(BYTE));
                lexical(); break;
        case SWAP:
                fnt = 64; goto sw_mov;
        case MOVE:
                fnt = 34;
sw_mov:
                lexical();
                nbargs = 3; tdem[0] = T_ANY; tdem[1] = tdem[2] = TBIN;
                adr_verrue = TRUE;
                if (!recargs(nbargs,tdem,targ,varg)) {
                        sfdln(); return (FALSE);
                }
                lexical();
                genclf(FALSE,fnt,nbargs,2,advar,targ,varg,GenericNULL(BYTE));
                break;
        case FM:        /* format d'edition ou de saisie */
                lexical();
                if (usc.code != PAG) {
                        erreur(USUAL,erexp7); sfdln(); return (FALSE);
                }
                fmt_verrue = TRUE;
                lexical();
                fmt_verrue = FALSE;

                if (usc.code == PAG) { /* reference par une variable */
                        lexical();
                        reg = getreg();
                        if (!reference(reg,&pdesc,&varg[0],&targ[0],&typ)) {
                                sfdln(); return (FALSE);
                        }
                        if ( ! IS_TSTR(typ) ) {
                                erreur(USUAL,erexp3); sfdln(); return (FALSE);
                        }
                        genffm(advar,targ[0],varg[0],GenericNULL(char));
                        lexical();
                        if (usc.code != PAD) {
                                erreur(USUAL,erexp8); sfdln(); return (FALSE);
                        }
                }
                else if (usc.code != CSTR) { /* erreur : format incorrect */
                        erreur(USUAL,erexp13); sfdln(); return (FALSE);
                     }
                     else
                        genffm(advar,0,0,usc.v.pval);
                lexical();
                if (usc.code != PAD) {
                        erreur(USUAL,erexp8); sfdln(); return (FALSE);
                }
                lexical(); /* avaler la parenthese */
                break;
        case PRINT:     /* PRINT dans une variable */
                if (!tststrres(&typ)) {
                        sfdln(); return (FALSE);
                }
				/* #OK: 18/06/02 (begin) */
				printToVariable = TRUE;
                if (!trfnprn(advar)) {
                        sfdln(); 
						printToVariable = FALSE;
						return (FALSE);
                }
				printToVariable = FALSE;
				/* #OK: 18/06/02 (end) */                
                break;
        case TRAN:
                if (!tststrres(&typ)) {
                        sfdln(); return (FALSE);
                }
                lexical();
                nbargs = 4; tdem[0] = tdem[1] = tdem[3] = TSTR; tdem[2] = TBIN;
                if (!recargs(nbargs,tdem,targ,varg)) {
                        sfdln(); return (FALSE);
                }
                lexical();
                genclf(FALSE,54,nbargs,2,advar,targ,varg,GenericNULL(BYTE));
                break;
        default:
				/* prevoir un simple appel de fonction */
				adrecep = advar;
				typrecep = typ;
				/* laisser la possibilite aux autres de faire l'affectation */
				aff_is_done = FALSE;
				vptreg = 0;

				aff_verrue = 1;
				regrecep = 0;

				/* prevoir une affectation simple avec CONV */
				conv_verrue = FALSE;
				if (!expression(&typ,&tres,&vres))
					return (FALSE);
				if (aff_is_done == FALSE)
				{     
					/* affectation reste a faire */
					if (aff_verrue == 1)
					{ 
						/* pas un simple appel de fonction */
						if ( (flg_opt) 
							&& ( IS_TBIN2(typ) || IS_TBIN1(typ) )
							&& ((*adesc & PRIMARY_INDEX) == 0) 
							&& (ismemglobale(*(adesc+1))==TRUE)
							&& (tres == 3) 
							&& (conv_verrue == FALSE)
							)
						{
							adrecep = bytetobin(adesc+2);
							fnt = 0;
							if ((advar & (BINAIRE) ISLOCAL) != 0)
								fnt = 1;        /* var locale */
							if ( IS_TBIN2(typ) )
								fnt += 2;       /* type % */
							stobin(fnt,adrecep,vres,advar);
						}
						else if ( verrue_retour_ptr )
						{
							/* Genere un ALIAS */
							genclf(FALSE,86,1,2,advar,&tres,&vres,GenericNULL(BYTE));
							verrue_retour_ptr = FALSE;
						}
						else
						{
							genpopreg(0);	/* R0 est le registre implicite utilisé pour les variables indicées */
							putvar(tres,vres,advar);	/* Genere un STI */
							Nettoyer_lreg_used(3, 0);	/*#FC+BG 03/12/02 */
						}

						/* #FC+BG 03/12/02 Begin
							On suppose que le nettoyage de lreg_used doit être fait dans les 3 cas 
						   Fait pour stobin(), donc on suppose qu'il faut le faire pour putvar().
						*/
						Nettoyer_lreg_used(tres, vres);
						/* #FC+BG 03/12/02 End */
					}
				}
				aff_verrue = 0;
			}

	return (TRUE);
}                                       /* affectation */

BOOL reference(reg,adesc,advar,tvar,typ)

/*      recherche, et traite une reference a une variable
 *      retourne la valeur 'FALSE' si incorrect.
 *      'adesc', 'advar' et 'typ' sont mis a jour au retour, avec le pointeur
 *      sur le descripteur, l'adresse du descripteur, et le type de donnee.
 *      si la variable est dimensionnee, sa reference est mise dans le registre
 *      donne par 'reg', sauf si reg vaut 0, auquel cas on retourne bien
 *      l'adresse du descripteur dans 'advar', les dimensions etant chargees
 *      dans les registres 0 (IX et AX)
 *      enfin, si la variable est associee a un registre en permanence,
 *      le numero de ce registre est retourne dans 'nrgvar' et 'tvar' vaut 4.
 */
BYTE    **adesc,*tvar,*typ;
BINAIRE reg,*advar;
{                                       /* reference */
        ExpMemb *op;

        if (usc.code != IDENT) {
                erreur(USUAL,erexp1); return (FALSE);
        }
        *adesc = findvar(usc.v.pval,GenericNULL(BYTE),advar,GenericNULL(TabSymb *),TRUE);
        if (*adesc == GenericNULL(BYTE)) {
                erreur(USUAL,erexp6); return (FALSE);
        }
        *typ = typdesc(*adesc);
        if ( IS_TBIN1(*typ) || IS_TBIN2(*typ) )
                *typ = TBIN;

            if ((**adesc & PRIMARY_INDEX) != 0) {        /* il y a des dimensions */				    
                /* creer le noeud "membre d'expression" */
                op = All_ExpMemb();
                if (op == GenericNULL(ExpMemb)) {
                        erreur(FATALE,errmem);
                }
                op->g = op->d = GenericNULL(ExpMemb);
                op->ap = GenericNULL(ArgList);
                if (!tr_dim(op,*adesc)) {
                        Free_ExpMemb(op);
                        return (FALSE);
                }
                ev_indices(reg,op->ap);					 
                if (reg == 0) { /* reference directe */
                        *tvar = 2;
                }
                else {  /* reference par un registre */
						 
 		   	    if ((!adrref_verrue) && IS_TBIN(*typ) )
                                putreg(reg,2,*advar);
                        else
                                putadr(reg,*advar);
                /* #OK: 09/03/00 (begin) */
                if (!nextArray) {               
                        *tvar = 3; *advar = reg;	
                      }
                else  *tvar = 2; 
                /* #OK: 09/03/00 (end) */
                }
                Free_ExpMemb(op); 
        }
        else    /* variable simple */
                *tvar = 2;
        return (TRUE);
}                                       /* reference */

/*
 *      EXPRESSIONS
 *      -----------
 */
/* #AT: 20/04/99 (begin) */
#ifdef __ATR22__

BYTE GetActualType(ExpMemb * pTree);

BYTE GetIFuncRetType(ExpMemb * pTree)
{
	BYTE bFuncRetType;
	switch(pTree->vl) {
	case 6:  // COL  /* position colonne courante */
	case 7:  // CONF /* parametres de configuration */
	case 75: // LANG /* lecture du code langue */
	case 13: // DEC  /* conversion d'une chaine hexa */
	case 22: // INDEX /* recherche posit d'un caractere */
	case 23: // INSTR /* recherche presence d'une sous-chaine */
	case 30: // LEN   /* longueur d'une chaine */
	case 31: // LIN   /* position ligne courante */
	case 65: // ERRADR /* lecture adresse interne derniere erreur */
	case 70: // EVENTADR /* lecture adresse interne dernier evenement */
	case 69: // HOTKEY   /* lecture touche dernier debranchement */
	case 56: // MASK     /* lecture masque de saisie courant */
	case 38: // PROCESS  /* numero de poste courant */
	case 67: // RESTORE  /* numero de dernier data lu */
	case 40: // RND      /* generation d'un nombre aleatoire */
	case 42: // SGN      /* signe d'un numerique */
	case 66: // VPTR     /* adresse d'une variable */
	case 78: // POWER    /* puissance de 10 d'un BCD */
	case 90: // VALIDPTR /* Verification de l'etat d'un pointeur */
	case 92: // EVENT    /* Recuperation des evenements externes */
	case 94: // HASH     /* fonction de HASH-CODING */
		return 1; // result type is "%"
	case 0:  // ABS    /* valeur absolue d'un numerique */
		return GetActualType(pTree->ap->va);
	case 86: // ALIAS  /* adresse d'une variable alloue ou statique */
		if ((bFuncRetType=GetActualType(pTree->ap->va)) == T_ANY) return 3; // STRING
		else return bFuncRetType;
	default: return (-1); // Not integer type
	}
}


BYTE GetActualType(ExpMemb * pTree)
{
	switch(pTree->tp) {
	case 0: /* Immediate value */
	case 1: /* Constant */

	case 2: /* Variable */
	case 12: /* Parameter variable modifiable (probably not appears) */

	case 3: /* Variable in register */
	case 13: /* Parameter variable in register modifiable (probably not appears) */

	case 4: /* Operator */

	case 8: /* NEG operation */

	case 9:  /* Variable with 1 dimension */
	case 10: /* Variable with 2 dimensions */
		return pTree->na;

	case 5: /* Call of internal function (index, vptr and so on) */
		return GetIFuncRetType(pTree);

	case 6: /* Call of conv function */
	/* Success of conversion operation will be knows only at run-time */
		return (-1);

	case 7: /* User function */
		return ((Tbusr *)((AppFct *)pTree->desc)->fct)->tres;

	case 11: {/* Procedure result */
/* #AT : 17/03/00 (begin) */
		TabProc * pTabProc;
		 /* return (((TabProc *)pTree->desc)->nba >> 12);	Commented by #AT */
		if (pTabProc=(TabProc *)pTree->desc)
			return pTabProc->nba >> 12;
      else return (-1);
/* #AT and #OK: 17/03/00 ATR-24 (end)*/
		}
	}
}

#endif
/* #AT: 20/04/99 (end) */

/* #AT: 13/09/99 (begin) */
#ifdef __ATR22__

BOOL GetActParAdmissibility(ExpMemb * pTree)
//   Admissibility of actual parameter type, if we suppose that formal 
// parameter type = ABAL-pointer
{
  switch(pTree->tp) {
  case 0: /* Immediate value */
  case 1: /* Constant */

  case 4: /* Operator */

  case 5: /* Call of internal function (index, vptr and so on) */
  case 6: /* Call of conv function */
  case 7: /* User function */

  case 8: /* NEG operation */

  case 11: /* Procedure result */
return FALSE;

  case 2: /* Variable */
  case 12: /* Parameter variable modifiable (probably not appears) */

  case 3: /* Variable in register */
  case 13: /* Parameter variable in register modifiable (probably not appears) */

  case 9:  /* Variable with 1 dimension */
  case 10: /* Variable with 2 dimensions */
return TRUE;
  }; // switch
} // GetActParAdmissibility

#endif
/* #AT: 13/09/99 (end)*/

BOOL expression(tres,aout,vout)

/*      traitement d'une expression, en entree 'tres' indique le type de
 *      resultat attendu.
 *      si 'tres' vaut T_ANY, le type attendu est quelconque, et est mis a
 *      jour au retour.
 *      la fonction retourne FALSE si il y a une erreur, et TRUE si Ok
 *      dans ce dernier cas :
 *      - aout = code du retour ( 0 valeur, 1 adcst , 2 advar , 3 registre)
 *      - vout = valeur a accorder suivant aout
 *      de plus, le flag 'simplexp' est mis a 'TRUE' si le resultat est une
 *      expression simple (reduite a un facteur), et a 'FALSE' sinon.
 *      enfin, si le flag 'argexp' est vrai en entree, le nom d'une variable
 *      dimensionnee, sans ses dimensions est acceptee, a condition que ce
 *      soit le seul element de l'expression.
 */
BYTE *tres, *aout;
BINAIRE *vout;
{                                       /* expression */
        ExpMemb *arbre;
	BOOL sv_argexp;		/* Sauvegarde pour l'appel de type p1(t(i+1)?) */
        BYTE tout;

	sv_argexp = argexp;
        arg_verrue = argexp;
        simplexp = TRUE;        /* expression simple a priori */
        arbre = tr_exp(tres);
        if (arbre == GenericNULL(ExpMemb))
                return (FALSE);

		argexp = sv_argexp;

/* #AT: 20/04/99 (begin) */
#ifdef __ATR22__
	if (gboolIsCallProc) {
		// To call only if expression(....) was called from callproc(....)
		*tres = GetActualType(arbre);

/* #AT: 13/09/99 (begin) */
	if (IS_TBIN(*tres))
		gboolIsActParAdmissible = GetActParAdmissibility(arbre);
/* #AT: 13/09/99 (end) */
   }
/* #AT: 20/04/99 (end) */
#endif


/* 11/07/94 */	/* Dans le cas ou une expression n'est pas simple */
		/* Pas de adr_verrue */

#ifdef _110794
		if ( (arbre != GenericNULL(ExpMemb)) && adr_verrue ) {
			if ( arbre->tp != 2 )
				adr_verrue = FALSE;
		}
#endif /* _110794 */

                eval_exp(arbre,aout,vout,&tout);
        return (TRUE);
}                                       /* expression */

/*
 *      CONSTRUCTION D'UNE REPRESENTATION ARBORESCENTE POUR UNE EXPRESSION
 *      ------------------------------------------------------------------
 */
/* #AT: 20/04/99 (begin) */
#ifdef __ATR22__

void SetRootType(ExpMemb * op1,ExpMemb * op2,ExpMemb * racine)
{
  BYTE bTypeOp1 = GetActualType(op1);
  BYTE bTypeOp2 = GetActualType(op2);
  if (bTypeOp1 != bTypeOp2)
		if (IS_TBCD(bTypeOp1)||IS_TBCD(bTypeOp2)) {
			racine->na = TBCD; return;
		}
		else if (IS_TBIN2(bTypeOp1)||IS_TBIN2(bTypeOp2)) {
			racine->na = TBIN2; return;
		}
  racine->na = bTypeOp1;
}
#endif
/* #AT: 20/04/99 (end) */

static ExpMemb *tr_exp(tres)

/*      production d'un arbre d'evaluation d'expression
 *      en entree '*tres' indique le type attendu (ou T_ANY si quelconque)
 *      la valeur de retour est un pointeur sur le debut de l'abre,
 *      ou NULL si une erreur est survenue.
 */
BYTE *tres;
{                                       /* tr_exp */
        ExpMemb *op1,*op2,*racine;      /* ss-arbres operandes */
        BINAIRE opr;
        Code_Synt oper;

        if ((op1 = tr_terme(tres)) == GenericNULL(ExpMemb)) {
                /* abandon si 1er terme incorrect */
                sfdln(); return (GenericNULL(ExpMemb));
        }
        oper = usc.code;
        while ((oper == PLUS) || (oper == MOINS) || (oper == OR)) {
                if (forcesimple) {
                        erreur(USUAL,erexp3);
                        lib_exp(op1);
                        return(GenericNULL(ExpMemb));
                }
                simplexp = FALSE;       /* pas une expression simple */
                /* et ne peut donc plus etre une variable dimensionnee */
                /* sans la mention explicite de ses dimensions */
                argexp = FALSE;
		if ( IS_TSTR(*tres) ) {
                   if (oper != PLUS) {
                        erreur(USUAL,erexp5); sfdln();
                        lib_exp(op1); /* pas d'arithmetique sur chaines ! */
                        return(GenericNULL(ExpMemb));
                   }
                   oper = CONC; /* mais seulement des concatenations */
                }
                if ( IS_TBCD(*tres) && (oper == OR)) {
                        erreur(USUAL,erexp10); sfdln();
                        lib_exp(op1);   /* pas de logique sur les BCD ! */
                        return(GenericNULL(ExpMemb));
                }
                lexical();      /* avaler l'operateur */
                if ((op2 = tr_terme(tres)) == GenericNULL(ExpMemb)) {
                        /* recherche 2eme terme a echoue --> abandon */
                        sfdln(); return (GenericNULL(ExpMemb));
                }
                /* creer nouveau noeud de l'arbre */
                opr = valeur(oper);
                racine = All_ExpMemb();
                if (racine == GenericNULL(ExpMemb)) { /* debordement memoire */
                        lib_exp(op1); lib_exp(op2); erreur(FATALE,errmem);
                }
                racine->g = op1; racine->d = op2;

/* #AT: 20/04/99 (begin) */
#ifndef __ATR22__
                if ((op1->na != op2->na) && ( IS_TBCD(op2->na)))
                        racine->na = TBCD;
                else
                        racine->na = op1->na;
#else
					 SetRootType(op1,op2,racine);
#endif
/* #AT: 20/04/99 (end) */

                racine->tp = 4; racine->vl = opr;
                racine->ap = GenericNULL(ArgList);
                /* qui devient le premier operande suivant */
                op1 = racine;
                /* passer a la suite */
                oper = usc.code;
        }
        /* le resultat final est le premier terme courant */
        return (op1);
}                                       /* tr_exp */

static ExpMemb *tr_terme(tres)

/*      construction d'un ss-arbre 'terme' dans une expression,
 *       en entree 'tres' indique le type de resultat attendu.
 *      si 'tres' vaut T_ANY, le type attendu est quelconque, et est mis a
 *      jour au retour.
 *      la fonction retourne NULL si il y a une erreur, un pointeur sur
 *      le ss-arbre sinon.
 */
BYTE *tres;
{                                       /* tr_terme */
        ExpMemb   *op1,*op2,*racine;
        BINAIRE   opr;
        Code_Synt oper;

        /* commencer par rechercher le premier facteur */
        op1 = tr_facteur(tres);
        if (op1 == GenericNULL(ExpMemb))
                return (GenericNULL(ExpMemb));   /* et abandon si erreur */
        oper = usc.code;
        while ((oper == MUL) || (oper == DIV) || (oper == AND) ||
               (oper == OX) || (oper == EXCLAM)) {
                if (oper == EXCLAM) {
			if ( ! IS_TSTR(*tres) ) break;
                        oper = MOD;
                }
                if (forcesimple) {
                        erreur(USUAL,erexp3); lib_exp(op1);
                        return(GenericNULL(ExpMemb));
                }
                simplexp = FALSE;       /* pas une expression simple */
                /* et ne peut donc plus etre une variable dimensionnee */
                /* sans la mention explicite de ses dimensions */
                argexp = FALSE;
	           if ( IS_TSTR(*tres) && (oper != MOD)) {
                        /* pas d'arithmetique sur les chaines ! */
                        erreur(USUAL,erexp5); lib_exp(op1);
                        return(GenericNULL(ExpMemb));
                }
                if ( IS_TBCD(*tres) && ((oper == AND) || (oper == OX))) {
                        /* pas de logique sur les BCD ! */
                        erreur(USUAL,erexp10); sfdln(); lib_exp(op1);
                        return(GenericNULL(ExpMemb));
                }
                lexical();      /* avaler l'operateur */
                /* et recherche du deuxieme facteur */
                op2 = tr_facteur(tres);
                if (op2 == GenericNULL(ExpMemb)) {
                        /* et abandon si erreur */
                        lib_exp(op1); return(GenericNULL(ExpMemb));
                }
                /* creer nouveau noeud de l'arbre */
                opr = valeur(oper);
                racine = All_ExpMemb();
                if (racine == GenericNULL(ExpMemb)) { /* debordement memoire */
                        lib_exp(op1); lib_exp(op2); erreur(FATALE,errmem);
                }
                racine->g = op1; racine->d = op2;
/* #AT: 20/04/99 (begin) */
#ifndef __ATR22__
                if ((op1->na != op2->na) && IS_TBCD(op2->na))
                        racine->na = TBCD;
                else
                        racine->na = op1->na;
#else
        SetRootType(op1,op2,racine);
#endif
/* #AT: 20/04/99 (end) */
                racine->tp = 4; racine->vl = opr;
                racine->ap = GenericNULL(ArgList);
                /* qui devient le premier operande suivant */
                op1 = racine;
                /* passer a la suite */
                oper = usc.code;
        }
        /* le resultat final est le premier facteur courant */
        return (op1);
}                                       /* tr_terme */

/* #AT: 20/04/99 (begin) */
#ifdef __ATR22__

void SetIntType(ExpMemb * op,BYTE * tres)
{
//  if (IS_TBIN1(*tres)) 
  if ((unsigned short int)op->vl > 255) op->na = TBIN2;
  else op->na = TBIN1;
}

#endif
/* #AT: 20/04/99 (end) */

static ExpMemb *tr_facteur(tres)

/*      construction d'un ss-arbre facteur dans une expression,
 *      en entree 'tres' indique le type de resultat attendu.
 *      si 'tres' vaut T_ANY, le type attendu est quelconque, et est mis a
 *      jour au retour.
 *      la fonction retourne NULL si il y a une erreur, un pointeur vers
 *      le ss-arbre sinon.
 *      cette fonction utilise la variable globale 'pdop' comme pointeur
 *      vers le descripteur du facteur trouve
 */
BYTE *tres;
{                                       /* tr_facteur */
        ExpMemb *op,*ag;
        BOOL    sgn = FALSE, stay_pad = FALSE;
        BOOL    old_simplexp;
        BYTE    t, typ;
        BINAIRE adr;
	TabProc *adproc;		/* Pointeur sur le descripteur d'une fonction */
	BYTE tconv;			/* Type de conversion */
	BOOL flag_tab_ptr = FALSE; 	/* Est ce un tableau de pointeur de proc ? */
	BOOL sv_div_verrue;		/* sauvegarde de verrue division pour memolex */	

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\ntr_facteur():debut");
#endif /* ATR_DEBUG */

        forcesimple = FALSE;            /* a priori pas de facteur unique */
        if (usc.code == PLUS) {         /* operateur unaire PLUS */
                if ( IS_TSTR(*tres) ) { /* pas sur une chaine */
                        erreur(USUAL,erexp5);
                        return (GenericNULL(ExpMemb));
                }
                lexical();                      /* by-pass pur et simple */                
				/* #SP: 05/06/02 (begin) */
                gwSign = PLUS;
                /* #SP: 05/06/02 (end) */
        }
        else if (usc.code == MOINS) {   /* operateur unaire MOINS */
                if ( IS_TSTR(*tres) ) { /* pas sur une chaine */
                        erreur(USUAL,erexp5);
                        return (GenericNULL(ExpMemb));
                }
                lexical(); sgn = TRUE; 
                /* #SP: 05/06/02 (begin) */
                gwSign = MOINS;
                /* #SP: 05/06/02 (end) */				
        }
        /* creer le noeud "membre d'expression" */
        op = All_ExpMemb();
        if (op == GenericNULL(ExpMemb)) {
                erreur(FATALE,errmem);
        }
        op->g = op->d = GenericNULL(ExpMemb);
        op->ap = GenericNULL(ArgList);
        switch (usc.code) {
	  case CALL:
                old_simplexp = simplexp;
       		Free_ExpMemb(op);       /* car appelle expression */

		adproc = GenericNULL(TabProc);
                op = fnt_proc(adproc,tres);

                simplexp = old_simplexp;
      		if (op == GenericNULL(ExpMemb)) {
               		return (GenericNULL(ExpMemb));
       		}
       		stay_pad = TRUE; /* derniere usc du facteur est deja avalee */
		break;
          case IDENT:                   /* variable ou constante */
                t = findcst(usc.v.pval,&pdop,&adr);
                if (t == 0) {           /* doit etre une variable */
#ifdef ATR_DEBUG2
	sprintf(debug_view,"\ntr_facteur():usc.v.pval =%s",usc.v.pval);	
	dbgprint(ATRACE,debug_view);
#endif /* ATR_DEBUG */
                   pdop = findvar(usc.v.pval,GenericNULL(BYTE),&adr,GenericNULL(TabSymb *),TRUE);
#ifdef ATR_DEBUG2
	sprintf(debug_view,"\ntr_facteur():pdop =%lx",pdop);	
	dbgprint(ATRACE,debug_view);
#endif /* ATR_DEBUG */
                   if (pdop != GenericNULL(BYTE)) {
                        if (argexp) {
                        }
                        typ = typdesc(pdop);
                        if ( masqueptr(typ) != masqueptr(*tres) ) {
			/* controle typage */
                                if (*tres == T_ANY) { /* type quelconque : */
                                        *tres = typ;   /* ce sera celui ci  */
                                }
                                else if ( (IS_TSTR(typ)) || (IS_TSTR(*tres)) ) {
                                        erreur(USUAL,erexp3);
                                        Free_ExpMemb(op);
                                        return (GenericNULL(ExpMemb));
                                }
                                else if ( IS_TBCD(typ) || IS_TBCD(*tres) ) {
                                        if (ind_verrue) { /* laisser passer */
                                                erreur(WARNING,erexp4);
                                        }
                                        else
                                                erreur(USUAL,erexp4);
                                }
                        }
			/* Si c'est un pointeur de procedure		 */
			/* gestion des pointeurs de tableau de procedure */
                        if ( ((*pdop & PRIMARY_INDEX) != 0) && (typ == (TSTR+8)) ) {
				DCLInfo dcl;
				/* Est ce un pointeur de proc (chaine de 5) ? */
				dcl.adrdesc = adr;
				GetDCLTable(&dcl);
/* 21/10/94 : ptlongueur au lieu de longueur */
				if ( dcl.ptlongueur == 5 ) {
					sv_div_verrue = div_verrue;
					div_verrue = TRUE;		
					memolex();
					lexical();
					if ( usc.code != PAG ) {
						flag_tab_ptr = TRUE;	
					}
					resumelex();
					div_verrue = sv_div_verrue;
				}
			}
                        if (((*pdop & PRIMARY_INDEX) != 0) && (!flag_tab_ptr) ) {
			/* variable dimensionnee */
                                if (!tr_dim(op,pdop)) {
                                        Free_ExpMemb(op);
                                        return (GenericNULL(ExpMemb));
                                }
                                op->vl = adr;
                        }
                        else {  /* pas de dimensions : directe avec variable */
                                op->vl = adr;
                                op->tp = 2; op->vr = 0;
                        }
                        /* garder le type de la variable */
                        op->na = typ;
                        /* garder le descripteur */
                        op->desc = pdop;
                   }
                   else { 
	                adproc = findproc(0,usc.v.pval);
			if ( adproc != GenericNULL(TabProc) ) {
				/* c'est une procedure */
		
		                old_simplexp = simplexp;
                		Free_ExpMemb(op);       /* car appelle expression */

		                op = fnt_proc(adproc,tres);

		                simplexp = old_simplexp;
                		if (op == GenericNULL(ExpMemb)) {
                        		return (GenericNULL(ExpMemb));
                		}
                		stay_pad = TRUE; /* derniere usc du facteur est deja avalee */

			} else { /* variable non declaree ou procedure inconnue */
                      		erreur(USUAL,erexp6); Free_ExpMemb(op);
                        	return (GenericNULL(ExpMemb));
			}
                   }
                }
                else if (t == 1) {      /* c'est une constante binaire */
                        if (!tstbinres(tres)) {
                            Free_ExpMemb(op); return (GenericNULL(ExpMemb));
                        }
/* #AT: 20/04/99 (begin) */
#ifndef __ATR22__
							op->tp = 0; op->vl = adr; op->na = TBIN2;
#else
							op->tp = 0; op->vl = adr;
							SetIntType(op,tres);
#endif
/* #AT: 20/04/99 (end) */
                        if (sgn) {
                                op->vl = -(op->vl); sgn = FALSE;
                        }
                }
                else {  /* c'est une constante chaine ou BCD */
                        if (*pdop == 0) { /* BCD */
                                if (!tstbcdres(tres)) {
                                        Free_ExpMemb(op);
                                        return (GenericNULL(ExpMemb));
                                }
                                op->na = TBCD;
                                /* traiter l'eventuelle negation */
                                if (sgn) {
                                   t = *(pdop + 2);
                                   *(pdop + 2) &= (BYTE) 0x000F;
                                   if ((t & (BYTE) BCD_PLUS)==(BYTE) BCD_PLUS)
                                        *(pdop + 2) |= (BYTE) BCD_MOINS;
                                   else
                                        *(pdop + 2) |= (BYTE) BCD_PLUS;
                                   adr = newbcd(pdop + 1);
                                   *(pdop + 2) = t; sgn = FALSE;
                                }
                        }
                        else {  /* constante chaine */
                                if (!tststrres(tres)) {
                                        Free_ExpMemb(op);
                                        return (GenericNULL(ExpMemb));
                                }
                                op->na = TSTR;
                        }
                        op->tp = 1; op->vl = adr;
                }
                break;
	  case XNULL:			/* pointeur null pour ALIAS(NULL) */
					/* mais aussi CBIN 0 */
		op->tp = 0; op->vl = 0; op->na = TBIN2;
                break;
          case CBIN:                    /* constante binaire */
                if ( IS_TSTR(*tres) ) {
                        erreur(USUAL,erexp3);
                        Free_ExpMemb(op); return (GenericNULL(ExpMemb));
                }
                else if ( IS_TBCD(*tres) ) { /* convertir la valeur en BCD */
                        op->tp = 1; op->na = TBCD;
                        op->vl = cvbintobcd(usc.v.val,sgn); sgn = FALSE;
                }
                else if ((*tres == T_ANY) &&
			 (not_a_call_var == TRUE) &&
			 (bcd_priority == TRUE)) {
                        /* convertir la valeur en BCD */
       	                *tres = TBCD; op->tp = 1; op->na = TBCD;
               	        op->vl = cvbintobcd(usc.v.val,sgn); sgn = FALSE;
                }
                else {
                
/* #AT: 20/04/99 (begin) */
#ifndef __ATR22__
								op->tp = 0; op->vl = usc.v.val; op->na = TBIN2;
#else
								op->tp = 0; op->vl = usc.v.val;
								SetIntType(op,tres);
#endif
/* #AT: 20/04/99 (end) */
                        if (sgn) {
                                op->vl = -(op->vl); sgn = FALSE;
                        }
                }
                break;
          case CBCD:                    /* constante BCD */
                if (!tstbcdres(tres)) {
                        Free_ExpMemb(op); return (GenericNULL(ExpMemb));
                }
                /* traiter l'eventuelle negation */
                if (sgn) {
                        *(usc.v.pbcd + 1) &= (BYTE) 0x000F;
                        *(usc.v.pbcd + 1) |= (BYTE) BCD_MOINS;
                        sgn = FALSE;
                }
                op->tp = 1; op->vl = newbcd(usc.v.pbcd); op->na = TBCD;
                break;
          case CSTR:                    /* constante chaine */
                if (!tststrres(tres)) {
                        Free_ExpMemb(op);
                        return (GenericNULL(ExpMemb));
                }
                op->tp = 1; op->vl = newstr(usc.v.pval); op->na = TSTR;
                break;
          case PAG:                     /* sous expression */
                lexical();      /* avaler la parenthese */
                Free_ExpMemb(op);       /* car appelle expression */
                op = tr_exp(tres);
                if (op == GenericNULL(ExpMemb)) {
                         return (GenericNULL(ExpMemb));
                }
                if (usc.code != PAD)
                        if (cond_verrue) {
                                nb_pad++; stay_pad = TRUE;
                        }
                        else {
                                erreur(USUAL,erexp8); lib_exp(op);
                                return (GenericNULL(ExpMemb));
                        }
                break;
          case MOD:     /* modulo entre deux numeriques */
                if ( IS_TSTR(*tres) ) { /* resultat chaine : impossible */
                        erreur(USUAL,erexp3); Free_ExpMemb(op);
                        return (GenericNULL(ExpMemb));
                }
                /* cette fonction est tranformee en une operation */
                /* a = MOD(b,c) --> a = b MOD c */
                lexical();
                if (usc.code != PAG) {
                        erreur(USUAL,erexp7); Free_ExpMemb(op);
                        return (GenericNULL(ExpMemb));
                }
                lexical(); typ = *tres;
                if ((op->g = tr_exp(&typ)) == GenericNULL(ExpMemb)) {
                        Free_ExpMemb(op);
                        return (GenericNULL(ExpMemb));
                }
                if (IS_TSTR(typ)) {
                        erreur(USUAL,erexp3); lib_exp(op);
                        return (GenericNULL(ExpMemb));
                }
                if (usc.code != VIG) {
                        erreur(USUAL,erexp9); lib_exp(op);
                        return (GenericNULL(ExpMemb));
                }
                lexical();
                if ((op->d = tr_exp(&typ)) == GenericNULL(ExpMemb)) {
                        lib_exp(op);
                        return (GenericNULL(ExpMemb));
                }
                if (IS_TSTR(typ)) {
                        erreur(USUAL,erexp3); lib_exp(op);
                        return (GenericNULL(ExpMemb));
                }
                if (usc.code != PAD) {
                        erreur(USUAL,erexp8); Free_ExpMemb(op);
                        return (GenericNULL(ExpMemb));
                }
                op->tp = 4; op->vl = valeur(MOD); op->na = op->g->na;
                simplexp = FALSE;
                break;
          case CONV:    /* cas particulier de la fonction CONV */
                lexical();
		switch ( usc.code ) {
			case STR:
				tconv=TSTR;
				break;
			case PCENT:
				tconv=TBIN2;
				break;
			case DIESE:
				tconv=TBIN1;
				break;
			case PAG:
				tconv=T_ANY;
				break;
			default:
	                        erreur(USUAL,erexp7); Free_ExpMemb(op);
        	                return (GenericNULL(ExpMemb));
		}
		if ( tconv != T_ANY ) {
			lexical();
	                if (usc.code != PAG) {
               	        	erreur(USUAL,erexp7); Free_ExpMemb(op);
                       		return (GenericNULL(ExpMemb));
               		}
		}
                lexical(); typ = T_ANY; /* pas de warnings */
                old_simplexp = simplexp;        /* 19/04/89 : CONV(X+0) */
                simplexp = TRUE;
                ag = tr_exp(&typ);
                simplexp = old_simplexp;
                if (ag == GenericNULL(ExpMemb)) {
                        Free_ExpMemb(op);
                        return (GenericNULL(ExpMemb));
                }
		if ( tconv != T_ANY ) {
			*tres = tconv;
		} else {
	                if (*tres == T_ANY)     /* par defaut convertir */
        	                *tres = TBCD;   /* en type BCD ... */
		}
                if (usc.code != PAD) {
                        erreur(USUAL,erexp8); Free_ExpMemb(op);
                        lib_exp(ag);
                        return (GenericNULL(ExpMemb));
                }
                op->g = ag; op->tp = 6; op->na = *tres;
                break;
          case STRN:    /* conversion d'un numerique en chaine */
                if (!tststrres(tres)) {
                        Free_ExpMemb(op);
                        return (GenericNULL(ExpMemb));
                }
                lexical();
                if (usc.code != PAG) {
                        erreur(USUAL,erexp7); Free_ExpMemb(op);
                        return (GenericNULL(ExpMemb));
                }
                lexical(); typ = TBCD;
                old_simplexp = simplexp;        /* 18/04/89 : STRN(X+0) */
                simplexp = TRUE;
                ag = tr_exp(&typ);
                simplexp = old_simplexp;
                if (ag == GenericNULL(ExpMemb)) {
                        Free_ExpMemb(op);
                        return (GenericNULL(ExpMemb));
                }
                if (usc.code != PAD) {
                        erreur(USUAL,erexp8); Free_ExpMemb(op);
                        lib_exp(ag);
                        return (GenericNULL(ExpMemb));
                }
                op->g = ag; op->tp = 6; op->na = (BYTE) 0x00FF;
                break;

          case FUSER :                  /* appel d'une fonction utilisateur */
                old_simplexp = simplexp;
                Free_ExpMemb(op);       /* car appelle expression */

                op = fnt_usr(usc.v.ptusr,tres);

                simplexp = old_simplexp;
                if (op == GenericNULL(ExpMemb)) {
                        return (GenericNULL(ExpMemb));
                }
                stay_pad = TRUE; /* derniere usc du facteur est deja avalee */
                break;

          default:                      /* doit etre un appel de fonction */
                old_simplexp = simplexp;
                Free_ExpMemb(op);       /* car appelle expression */
/* #AT: 22/11/99 (begin)*/
#ifdef __ATR22__
            gwSign = (sgn) ? MOINS : PLUS;
#endif
/* #AT: 22/11/99 (end)*/
                op = tr_fnt(tres);
                simplexp = old_simplexp;
                if (op == GenericNULL(ExpMemb)) {
                        return (GenericNULL(ExpMemb));
                }
                stay_pad = TRUE; /* derniere usc du facteur est deja avalee */
        }

/* #AT: 22/11/99 (begin)*/
#ifdef __ATR22__
			if (!gwSign)
				sgn = FALSE;
#endif
/* #AT: 22/11/99 (end)*/


        if (sgn) {      /* enregistrer la negation */
           if ( IS_TSTR(*tres) ) { /* qui est refusee si resultat = chaine */
                erreur(USUAL,erexp5); lib_exp(op);
                return (GenericNULL(ExpMemb));
           }
           ag = All_ExpMemb();
           if (ag == GenericNULL(ExpMemb)) {
                erreur(FATALE,errmem);
           }
           ag->g = op; ag->d = GenericNULL(ExpMemb);
           ag->tp = 8; ag->na = op->na; op = ag;
           ag->ap = GenericNULL(ArgList);
           simplexp = FALSE;
        }
        if (!stay_pad) {
                div_verrue = TRUE;      /* prevoir l'operateur DIV */
                lexical();      /* avaler la derniere usc du facteur */
                div_verrue = FALSE;
        }
        return (op);
}                                       /* tr_facteur */

static BOOL tr_dim(op,adesc)

/*      recuperation des dimensions pour une variable decrite par 'adesc',
 *      et qui est pointee par 'op' dans l'arbre courant.
 *      le fait qu'un indice de tableau ne soit pas une expression simple
 *      ne remet pas en cause le signal 'simplexp' qui concerne la reference
 *      a la variable dimensionnee
 */
ExpMemb *op;
BYTE *adesc;
{                                               /* tr_dim */
        BYTE    tr;
        ExpMemb *ag1,*ag2;
        BOOL    old_simplexp;

        lexical();
        if (usc.code != PAG) {
                erreur(USUAL,erexp7); return (FALSE);
        }
        lexical(); /* avaler la parenthese */
        tr = TBIN;
        ind_verrue = TRUE;
        old_simplexp = simplexp;
        ag1 = tr_exp(&tr);
        simplexp = old_simplexp;
        ind_verrue = FALSE;
        if (ag1 == GenericNULL(ExpMemb)) return (FALSE);
        if ( IS_TSTR(tr) ) {       /* une chaine ne peut pas servir d'indice */
                erreur(USUAL,erexp3); lib_exp(ag1);
                return (FALSE);
        }
        op->tp = 9;
        if ((*adesc & SECOND_INDEX) != 0) { /* il y a une 2eme dimension */
           if (usc.code != VIG) {
                erreur(USUAL,erexp9); lib_exp(ag1); return (FALSE);
           }
           tr = TBIN;
           lexical(); /* avaler la virgule */
           ind_verrue = TRUE;
           old_simplexp = simplexp;
           ag2 = tr_exp(&tr);
           simplexp = old_simplexp;
           ind_verrue = FALSE;
           if (ag2 == GenericNULL(ExpMemb)) return (FALSE);
           if (IS_TSTR(tr)) {    /* une chaine ne peut pas servir d'indice */
                erreur(USUAL,erexp3); lib_exp(ag1); lib_exp(ag2);
                return (FALSE);
           }
           op->tp = 10;
        }
        if (usc.code != PAD) {
                erreur(USUAL,erexp8); lib_exp(ag1);
                if (op->tp == 10)
                        lib_exp(ag2);
                return (FALSE);
        }
        op->ap = All_ArgList();
        if (op->ap == GenericNULL(ArgList)) {
                erreur(FATALE,errmem);
        }
        op->ap->va = ag1;
        if (op->tp == 10) {
                op->ap->suiv = All_ArgList();
                if (op->ap->suiv == GenericNULL(ArgList)) {
                        erreur(FATALE,errmem);
                }
                op->ap->suiv->va = ag2;
                op->ap->suiv->suiv = GenericNULL(ArgList);
        }
        else {
                op->ap->suiv = GenericNULL(ArgList);
        }
        return (TRUE);
}                                               /* tr_dim */

/*
 *      TRAITEMENT DES APPELS AUX FONCTIONS QUI SONT ACCEPTEES
 *                      DANS LES EXPRESSIONS
 *      ------------------------------------------------------
 */

static ExpMemb *fnt_usr(fct,tres)

/*      Traitement des appels aux fonctions utilisateur
 *      'fct' est un pointeur vers le descripteur de la
 *      fonction utilisateur invoquee.
 */

Tbusr   *fct;
BYTE *tres;
{                                               /* fnt_usr */
        ExpMemb *ret;
        ArgList *args;
        BINAIRE nbargs;
        AppFct *desapp;
        BOOL *lsimpl;

        nbargs = fct->nba;

        /* Controle le type de resultat de la fonction.
         * Jusqu'a la version 1.3 incluse, la fonction doit avoir
         * un resultat de type %. A partir de la version 1.4, elle
         * peut aussi avoir un resultat chaine ou BCD
         */

        if ((fct->tres == TVOID) || ((*tres != T_ANY) && ((BYTE)(*tres & typ_in_desc) != fct->tres))) {
                erreur(USUAL,errfu14);
                return(GenericNULL(ExpMemb));
        }

        desapp = All_AppFct();  /* alloue descripteur fonction */
        if (desapp == GenericNULL(AppFct))
                erreur(FATALE,errmem);

        /* alloue une liste de types d'arguments (de lgr utile + 1) */

        lsimpl = (BOOL *) Xmalloc((MXARGS+1) * sizeof(BOOL));

        if (lsimpl == GenericNULL(BOOL))
                erreur(FATALE,errmem);

        desapp->simple = lsimpl;        /* identifie la fonction */
        desapp->fct = fct;

        ret = All_ExpMemb();    /* alloue un membre d'expression */
        if (ret == GenericNULL(ExpMemb))
                erreur(FATALE,errmem);

        ret->tp = 7;            /* identifie ce membre */

        ret->na = (BYTE)0;

        ret->vl = fct->nofct;
        ret->vr = fct->nort;
        ret->desc = (BYTE *)desapp;
        ret->g = ret->d = GenericNULL(ExpMemb);
        ret->ap = GenericNULL(ArgList);

        lexical();

        /* Traite les arguments d'appel de la fonction */

        if ((nbargs != 0) || fct->nbavar) {
                args = tr_argfu(&nbargs,fct->typa,fct->moda,desapp->simple,fct->nbavar);

                if (args == GenericNULL(ArgList)) {
                        Free_BOOL(lsimpl);
                        Free_AppFct(desapp);
                        Free_ExpMemb(ret);
                        return(GenericNULL(ExpMemb));
                }
                ret->ap = args;
                ret->na = (BYTE) nbargs;
        }
        else {
                lexical();
                if (usc.code == PAD)
                        lexical();
        }

        if ((nbargs != 0) && (usc.code == PAD)) {
                /* on est reste sur la ')' */
                div_verrue = TRUE;  /* prevoir le DIV */
                lexical();          /* pour avaler la derniere usc */
                div_verrue = FALSE; /* du facteur */
        }
        return (ret);
}                                               /* fnt_usr */

static ExpMemb *fnt_proc(fct,tres)

/*      Traitement des appels aux procedures fonctions
 *      'fct' est un pointeur vers le descripteur de la
 *      procedure invoquee.
 */

TabProc   *fct;
BYTE *tres;
{                                               /* fnt_proc */
        ExpMemb *ret;
        ArgList *args;

        ExpMemb *ptfct=GenericNULL(ExpMemb);

        BINAIRE nbargs; /* */

	BOOL nbavar = FALSE;
	BYTE *ptyp;
	
	BYTE typeretour;

	if ( fct != GenericNULL(TabProc) ) {
	       nbargs = fct->nba & 0x07FF; /* Masque sans retour fonction */

	        /* Controle le type de resultat de la fonction. */
		/* 1er cas : pas une fonction !!!! */
		if ( ( fct->nba & 0x0800 ) == 0 ) {
                	erreur(USUAL,errfu14);
                	return(GenericNULL(ExpMemb));
		}
		/* 2eme cas : type de retour incorrect */
		typeretour = ( (fct->nba & 0xF000) >> 12 );
		if ( *tres != T_ANY ) {
			BYTE t;
			t = ( (fct->nba & 0xF000) >> 12 );
			if ( t >= 8 ) {
				if ( t != *tres ) {
				/* retour pointeur */
		                	erreur(USUAL,errfu14);
                			return(GenericNULL(ExpMemb));
				}
			} else {
				if ( t != (BYTE)(*tres &07) ) {
		                	erreur(USUAL,errfu14);
                			return(GenericNULL(ExpMemb));
				}
			}
		} else {
			*tres = typeretour;
		}
	} else {

		lexical();
		if ( usc.code == PAG ) {
			BYTE typ;
		 	typ=TSTR;

		        arg_verrue = argexp;
        		simplexp = TRUE;        /* expression simple a priori */
        		ptfct = tr_exp(&typ);
		        if (ptfct == GenericNULL(ExpMemb)) {
               			sfdln();
                                return (GenericNULL(ExpMemb));
			}

		       	if (usc.code != PAG) {  /* erreur : '(' attendue */
        		       	erreur(USUAL,erexp6); sfdln();
                                return (GenericNULL(ExpMemb));
       			}
		} else {
       		       	erreur(USUAL,erexp6); sfdln();
                        return (GenericNULL(ExpMemb));
		}
		nbargs = 1;
		nbavar = TRUE;
	}

        ret = All_ExpMemb();    /* alloue un membre d'expression */
        if (ret == GenericNULL(ExpMemb))
                erreur(FATALE,errmem);

        ret->tp = 11;            /* identifie ce membre */

        ret->na = (BYTE)nbargs;
        ret->ap = GenericNULL(ArgList);

	/* Utilisation de ces 2 variables pour garder les references au
	   pointeur de fonction */

        ret->vl = (BINAIRE) 0;
        ret->vr = 0;

        ret->desc = (BYTE *)fct;

        ret->g = ptfct;
        ret->d = GenericNULL(ExpMemb);

        ret->ap = GenericNULL(ArgList);

	if ( ! nbavar ) {
	        lexical();
		ptyp = fct->adta;
	} else {
	        ptyp = (BYTE *) Xmalloc((MXARGS+1) * sizeof(BYTE));
	        if (ptyp == GenericNULL(BYTE)) {
        	       erreur(FATALE,errmem);
		}
	}

        /* Traite les arguments d'appel de la fonction */

        if ( nbargs != 0 ) {

                args = tr_args(&nbargs, ptyp, nbavar);

                if (args == GenericNULL(ArgList)) {
			if ( nbargs != 0 ) {
	                        Free_ExpMemb(ret);
        	                return(GenericNULL(ExpMemb));
			} else {
				lexical();
			}
                }
                ret->ap = args;
                ret->na = (BYTE) nbargs;
        }
        else {
                lexical();
                if (usc.code == PAD) {
			div_verrue = TRUE; /* prevoir le DIV */
                        lexical();	   /* pour avaler la derniere usc */
			div_verrue = FALSE;/* du facteur */
		}
        }

        if ((nbargs != 0) && (usc.code == PAD)) {
                /* on est reste sur la ')' */
                div_verrue = TRUE;  /* prevoir le DIV */
                lexical();          /* pour avaler la derniere usc */
                div_verrue = FALSE; /* du facteur */
        }

	/* 05/10/93 : liberation si allocation dans fnt_proc */
	if ( nbavar )
		Xfree(ptyp);

        return (ret);
}                                               /* fnt_proc */

/* #AT: 22/11/99 (begin)*/
#ifdef __ATR22__

BINAIRE GetBINARYval()
{
	char chCurr;
	int iBinNumb = 0, iResult = 0;
	const ciMaxBinNumb = 16; /* Max length of a bit sequence = 16 bit */

	if ((chCurr = getcar()) != '(') { /* '(' expected */
		erreur(USUAL,erexp7); return 0;
		}
	while(iBinNumb++ < ciMaxBinNumb+1) {
		switch(chCurr = getcar()) {
			case '0': case '1': iResult <<= 1; iResult |= chCurr-'0' & 0x1; break;
			case ')':          
				if (gwSign == MOINS) { gwSign=0; return (BINAIRE)-iResult;}  
				return (BINAIRE)iResult;
			default: /* ')' expected */
				erreur(USUAL,erexp8); return 0;
		}
	}
	erreur(USUAL,erexp14); /* The number is too long */
	return 0;
}


void Remettre()
{ 
  lptr--; clncur--; 
}


int TreatCond(char chCurr)
{
  switch(getcar()){
  case '>': return (chCurr == '<') ? DIFF : 0;
  case '=': return (chCurr=='<') ? INFE : SUPE;
  default:  Remettre(); return (chCurr=='<') ? INF : SUP;
  }
}


void TreatOpEnd()
{
  int iCode;
  char chCurr;

  switch(chCurr=getcar()){
	  case '\n': iCode = FDLN; break;
	  case ':':  
			if (getcar() == ':') { iCode = FDLN; break;}
			Remettre(); iCode = DPT; 
			break;
	  case ')': iCode = PAD;  break;
	  case ',': iCode = VIG;  break;
	  case '=': iCode = EGAL; break;
	  case '<': case '>': iCode = TreatCond(chCurr); break;
	  case '+': iCode = PLUS;  break;
	  case '-': iCode = MOINS; break;
	  case '*': iCode = MUL;   break;
	  case '/': iCode = DIV;   break;
	  default: Remettre(); iCode = PAD;
	}
	usc.code = iCode;
}

#endif
/* #AT: 22/11/99 (end)*/

static ExpMemb *tr_fnt(tres)

/*      traitement d'un appel de fonction standard de l'A.B.A.L.
 *      en entree, tres indique le type attendu pour le resultat.
 *      si tres vaut T_ANY, le type attendu est quelconque, et est mis a
 *      jour au retour.
 *      la fonction retourne un pointeur sur un membre d'expression si Ok,
 *      ou NULL si il y a eu une erreur.
 *      en entree, simple signale que l'appel est le premier facteur,
 *                 et sgn signale un facteur devant etre signe (negation).
 */
BYTE *tres;
{                                               /* tr_fnt */
        BYTE    typ[4],aux;
        ExpMemb *ret,*cnv;
        ArgList *args;
	BINAIRE nbargs;

        /* commencer par verifier la validite de l'appel suivant le typage */
        /* --------------------------------------------------------------- */
        switch (usc.code) {     /* chercher la fonction */

                /* celles qui rendent une valeur binaire */
                /* ------------------------------------- */
                case COL:       /* position colonne courante */
                case CONF:      /* parametres de configuration */
                case LANG:      /* lecture du code langue */
                case DEC:       /* conversion d'une chaine hexa */
                case INDEX:     /* recherche posit d'un caractere */
                case INSTR:     /* recherche presence d'une sous-chaine */
                case LEN:       /* longueur d'une chaine */
                case LIN:       /* position ligne courante */
                case ERRADR:    /* lecture adresse interne derniere erreur */
                case EVENTADR:  /* lecture adresse interne dernier evenement */
                case HOTKEY:    /* lecture touche dernier debranchement */
                case MASK:      /* lecture masque de saisie courant */
                case PROCESS:   /* numero de poste courant */
                case RESTORE:   /* numero de dernier data lu */
                case RND:       /* generation d'un nombre aleatoire */
                case SGN:       /* signe d'un numerique */
                case VPTR:      /* adresse d'une variable */
                case POWER:     /* puissance de 10 d'un BCD */
		case VALIDPTR:	/* Verification de l'etat d'un pointeur */
		case EVENT:	/* Recuperation des evenements externes */
		case HASH:	/* fonction de HASH-CODING */
                        if (tstbinres(tres)) break;
                        return (GenericNULL(ExpMemb));

                /* celles qui rendent une valeur BCD */
                /* --------------------------------- */
                case ATN:       /* arctangente d'un BCD */
                case COS:       /* cosinus d'un BCD */
                case EXP:       /* exponentielle d'un BCD */
                case FIX:       /* cadrage d'un BCD */
                case FP:        /* partie decimale d'un BCD */
                case INT:       /* partie entiere d'un BCD */
                case LOG:       /* logarithme Neperien d'un BCD */
                case ROUN:      /* arrondi d'un BCD */
                case SIN:       /* sinus d'un BCD */
                case SQR:       /* racine carree d'un BCD */
                case TAN:       /* tangente d'un BCD */
                case VAL:       /* conversion d'une chaine en numerique */
                case SYSERROR:  /* code erreur systeme */
                case STDFORM:   /* mantisse d'un BCD */
                case REAL:      /* elevation a 10 puissance x */
                        if (tstbcdres(tres)) break;
                        return (GenericNULL(ExpMemb));

                /* celles qui rendent une valeur chaine */
                /* ------------------------------------ */
                case CHR:       /* conversion numerique en caractere */
                case CURDIR:    /* lecture repertoire courant */
                case CURVOL:    /* lecture volume courant */
                case DATE:      /* lecture date systeme */
                case ENV:       /* lecture variable environnement */
                case GENER:     /* generation de caractere */
                case HEX:       /* conversion en hexa */
                case INV:       /* inversion d'une chaine */
                case KBF:       /* lecture d'une touche */
                case LARGE:     /* mise en majuscule */
                case LEFT:      /* partie gauche d'une chaine */
                case RIGHT:     /* partie droite d'une chaine */
                case SHL:       /* cadrage a gauche d'une chaine */
                case SHR:       /* cadrage a droite d'une chaine */
                case SMALL:     /* mise en minuscules */
                case SPACE:     /* generation d'une chaine a blanc */
                case SUBSTR:    /* extraction d'une sous-chaine */
                case PARSE:     /* decoupage d'un nom de fichier */
		case PROC:	/* Pointeur sur une procedure */
		case USER:	/* Pointeur sur une fonction bib dyn */
		case SEGMENT:	/* Pointeur sur un segment */
		case CODE:	/* Macro-fonction (PROC | USER | SEGMENT) */
                        if (tststrres(tres)) break;
                        return (GenericNULL(ExpMemb));


/* #AT: 22/11/99 (begin)*/
#ifdef __ATR22__
    case BINARY:  /* Bit sequence to a number */
      *tres = 1; /* TBIN2 type (%)*/
      if ((ret = All_ExpMemb()) == GenericNULL(ExpMemb)) erreur(FATALE,errmem);
      ret->vl = GetBINARYval(); 
      ret->tp = 0; /* Immediate value */ 
      ret->na = 1; /* It isn't function call but a simple variable */
      ret->vr = 0; ret->desc = 0; ret->ap = 0; ret->g = ret->d = 0;
      TreatOpEnd();
      return ret;
#endif
/* #AT: 22/11/99 (end)*/

                /* autres cas */
                /* ---------- */
                case ABS:       /* valeur absolue d'un numerique */
                        if (IS_TSTR(*tres)) { /* resultat chaine : impossible */
                            erreur(USUAL,erexp3);
                            return (GenericNULL(ExpMemb));
                        }
                        break;
		case ALIAS:	/* adresse d'une variable alloue ou statique */
			/* resultat != pointeur : impossible */
			/* sauf si type chaine */
                        if ( *tres < TPTR ) {
				if ( *tres != TSTR ) {
		         		erreur(USUAL,erexp3);
                            		return (GenericNULL(ExpMemb));
				}
                        }
			break; 
                default:        /* fonction inconnue : une erreur de syntaxe */
                        erreur(USUAL,erexp6); return (GenericNULL(ExpMemb));
        }
        /* allouer un noeud pour mettre la fonction dans l'arbre */
        /* ----------------------------------------------------- */

        ret = All_ExpMemb();
        if (ret == GenericNULL(ExpMemb))
                erreur(FATALE,errmem);
        ret->tp = 5;
        ret->g = ret->d = GenericNULL(ExpMemb);
        ret->ap = GenericNULL(ArgList);

        /* recuperation des arguments suivant chaque fonction */
        /* -------------------------------------------------- */
        switch (usc.code) {     /* chercher la fonction */

                /* celles qui rendent une valeur binaire */
                case COL:       /* position colonne courante */
                        ret->vl = 6;    /* code de la fonction COL */
_arg1:                  /* un argument binaire optionnel */
                        div_verrue = TRUE;      /* prevoir l'operateur DIV */
                        lexical();
                        div_verrue = FALSE;
                        if (usc.code == PAG) { /* l'argument existe */
                                typ[0] = TBIN; lexical(); /*avaler parenthese*/
                                args = All_ArgList();
                                if (args == GenericNULL(ArgList))
                                        erreur(FATALE,errmem);
                                args->suiv = GenericNULL(ArgList);
                                args->va = tr_exp(&typ[0]);
                                if (args->va == GenericNULL(ExpMemb)) {
                                        Free_ArgList(args); Free_ExpMemb(ret);
                                        return (GenericNULL(ExpMemb));
                                }
                                if (usc.code != PAD) {
                                        erreur(USUAL,erexp8);
                                        Free_ArgList(args); Free_ExpMemb(ret);
                                        return (GenericNULL(ExpMemb));
                                }
                                ret->na = 1;
                                ret->ap = args;
                        }
                        else    /* pas d'argument */
                                ret->na = 0;
                        break;

                case CONF:      /* parametres de configuration */
                        ret->vl = 7;    /* code de la fonction CONF */
_arg2:                  /* un argument binaire */
                        typ[0] = TBIN;
unarg:                  /* entree generique pour un argument */
                        lexical();
unarg2:                 /* cas particulier ou avance dans source deja faite */
                        ret->na = 1;
nargs:                  /* entree generique pour decodage des arguments */
			nbargs = (BINAIRE) ret->na;
                        args = tr_args(&nbargs,typ,FALSE);
			ret->na = (BYTE) nbargs;
                        if (args == GenericNULL(ArgList)) {
                            Free_ExpMemb(ret); return (GenericNULL(ExpMemb));
                        }
			/* 86:ALIAS controle de type */
			if ( ret->vl == 86 ) {
				if ( (*tres != T_ANY) && (*tres != TSTR) && (masqueptr(*tres) != masqueptr(typ[0])) ) {
			  	/* erreur si pas pointeur */
                		erreur(USUAL,erexp3);
                                Free_ExpMemb(ret); lib_arg(args);
                                return (GenericNULL(ExpMemb));
				}
			}
			/* 90:VALIDPTR argument pointeur seulement et chaine pour PTR PROC */
			if ( (ret->vl == 90) && (typ[0] < TPTR) && (typ[0] != TSTR) ) {
			  	/* erreur si pas pointeur */
                		erreur(USUAL,erexp3);
                                Free_ExpMemb(ret); lib_arg(args);
                                return (GenericNULL(ExpMemb));
			}

                        if ((ret->vl == 0) || (ret->vl == 42) || (ret->vl == 78)) {
                           /* ABS ou SGN ou POWER : verif validite argument */
                           if ( IS_TSTR(typ[0]) ) {
                                erreur(USUAL,erexp3);
                                Free_ExpMemb(ret); lib_arg(args);
                                return (GenericNULL(ExpMemb));
                           }
                           if ( (ret->vl == 42) && (!IS_TBCD(typ[0]))) {
                                /* SGN : convertir si arg n'est pas BCD */
                                erreur(WARNING,erexp4);
                                cnv = All_ExpMemb();
                                if (cnv == GenericNULL(ExpMemb)) {
                                        Free_ExpMemb(ret); lib_arg(args);
                                        erreur(FATALE,errmem);
                                }
                                cnv->tp = 6;
                                cnv->na = TBCD;
                                cnv->d = GenericNULL(ExpMemb);
                                cnv->ap = GenericNULL(ArgList);
                                cnv->g = args->va; args->va = cnv;
                           }
                        }
                        else if (ret->vl == 66) { /* VPTR : variable imposee */
                                aux = args->va->tp;
                                if ((aux != 2) && (aux != 9) && (aux != 10) &&
                                    (aux != 3)) {
                                        erreur(USUAL,erexp3);
                                        Free_ExpMemb(ret); lib_arg(args);
                                        return (GenericNULL(ExpMemb));
                                }
                        }
                        ret->ap = args;
                        break;
                case DEC:       /* conversion d'une chaine hexa */
                        ret->vl = 13;
_arg5:                  /* une chaine et un binaire */
                        ret->na = 2; lexical(); typ[0] = TSTR; typ[1] = TBIN;
                        goto nargs;
                case INDEX:     /* recherche posit d'un caractere */
                        ret->vl = 22;
                        /* deux arguments de type chaine */
                        ret->na = 2; lexical(); typ[0] = TSTR; typ[1] = TSTR;
                        goto nargs;
                case INSTR:     /* recherche presence d'une sous-chaine */
                        ret->vl = 23;
                        /* deux arguments de type chaine et un binaire */
                        ret->na = 3; lexical(); typ[0] = TSTR; typ[1] = TSTR;
                        typ[2] = TBIN; goto nargs;
                case LEN:       /* longueur d'une chaine */
                        ret->vl = 30;   /* LEN$ a priori */
                        lexical();
                        if (usc.code != STR) { /* cas de LEN tout seul */
                                ret->vl = 29;
				typ[0] = T_ANY; goto unarg2;
                        }
_arg3:                  /* un argument chaine */
                        typ[0] = TSTR; goto unarg;
                case LIN:       /* position ligne courante */
                        ret->vl = 31;   /* code de la fonction LIN */
                        goto _arg1;     /* un argument binaire optionnel */
                case ERRADR: /* lecture adresse interne derniere erreur */
                        ret->vl = 65;
                        goto _noarg;
                case EVENTADR: /* lecture adresse interne dernier evenement */
                        ret->vl = 70;
                        goto _noarg;
                case HOTKEY: /* lecture touche dernier debranchement */
                        ret->vl = 69;
                        goto _noarg;
                case SYSERROR: /* lecture code erreur systeme etendu */
                        ret->vl = 71;
                        goto _noarg;
                case MASK:      /* lecture masque de saisie courant */
                        ret->vl = 56;
                        goto _noarg;
                case LANG:      /* lecture du code langue */
                        ret->vl = 75;
_noarg:
                        div_verrue = TRUE;      /* prevoir l'operateur DIV */
                        lexical();
                        div_verrue = FALSE;
                        ret->na = 0; break;
                case PROCESS:   /* numero de poste courant */
                        ret->vl = 38;
                        goto _noarg;
                case RESTORE:   /* numero dernier data lu */
                        ret->vl = 67;
                        goto _noarg;
                case RND:       /* generation d'un nombre aleatoire */
                        ret->vl = 40;   /* code de la fonction RND */
                        goto _arg1;     /* un argument binaire optionnel */
                case SGN:       /* signe d'un numerique */
                        ret->vl = 42;
                        typ[0] = T_ANY; goto unarg;
                case POWER:     /* calcul de la puissance de 10 d'un BCD */
                        ret->vl = 78;
                        typ[0] = T_ANY; goto unarg;
                case VALIDPTR:     /* verification de l'etat d'un pointeur */
                        ret->vl = 90;
                        typ[0] = T_ANY; goto unarg;
                case EVENT:     /* etat d'un evenement externe */
                        ret->vl = 92;
                        typ[0] = T_ANY; goto _arg2;

                /* celles qui rendent une valeur BCD */
                case ATN:       /* arctangente d'un BCD */
                        ret->vl = 2;
_arg4:                  /* un argument BCD */
                        typ[0] = TBCD; goto unarg;
                case COS:       /* cosinus d'un BCD */
                        ret->vl = 9; goto _arg4; /* un argument BCD */
                case EXP:       /* exponentielle d'un BCD */
                        ret->vl = 14; goto _arg4; /* un argument BCD */
                case FIX:       /* cadrage d'un BCD */
                        ret->vl = 15; ret->na = 1; lexical();
                        /* un argument BCD et un eventuel binaire */
                        if (usc.code != PAG) {
                                erreur(USUAL,erexp7); Free_ExpMemb(ret);
                                return (GenericNULL(ExpMemb));
                        }
                        lexical(); typ[0] = TBCD; typ[1] = TBIN;
                        args = All_ArgList();
                        if (args == GenericNULL(ArgList))
                                erreur(FATALE,errmem);
                        args->suiv = GenericNULL(ArgList);
                        args->va = tr_exp(&typ[0]);
                        if (args->va == GenericNULL(ExpMemb)) {
                                Free_ArgList(args); Free_ExpMemb(ret);
                                return (GenericNULL(ExpMemb));
                        }
                        ret->na = 1;
                        if (usc.code == VIG) { /* 2eme argument explicite */
                                ret->na = 2;
                                lexical(); /* avaler la virgule */
                                args->suiv = All_ArgList();
                                if (args->suiv == GenericNULL(ArgList))
                                        erreur(FATALE,errmem);
                                args->suiv->suiv = GenericNULL(ArgList);
                                args->suiv->va = tr_exp(&typ[1]);
                                if (args->suiv->va == GenericNULL(ExpMemb)) {
                                        lib_arg(args); Free_ExpMemb(ret);
                                        return (GenericNULL(ExpMemb));
                                }
                        }
                        if (usc.code != PAD) {
                                erreur(USUAL,erexp8);
                                lib_arg(args); Free_ExpMemb(ret);
                                return (GenericNULL(ExpMemb));
                        }
                        ret->ap = args;
                        break;
                case FP:        /* partie decimale d'un BCD */
                        ret->vl = 17; goto _arg4; /* un argument BCD */
                case INT:       /* partie entiere d'un BCD */
                        ret->vl = 24; goto _arg4; /* un argument BCD */
                case STDFORM:   /* Conversion d'un BCD en standard form */
                        ret->vl = 79; goto _arg4; /* un argument BCD */
                case LOG:       /* logarithme Neperien d'un BCD */
                        ret->vl = 32; goto _arg4; /* un argument BCD */
                case ROUN:      /* arrondi d'un BCD */
                        ret->vl = 41;
                        /* un argument BCD et un binaire */
                        ret->na = 2; lexical(); typ[0] = TBCD; typ[1] = TBIN;
                        goto nargs;
                case REAL:      /* Augmentation ou diminution d'une puissance de 10 */
                        ret->vl = 80;
                        /* un argument BCD et un binaire */
                        ret->na = 2; lexical(); typ[0] = TBCD; typ[1] = TBIN;
                        goto nargs;
                case SIN:       /* sinus d'un BCD */
                        ret->vl = 45; goto _arg4; /* un argument BCD */
                case SQR:       /* racine carree d'un BCD */
                        ret->vl = 48; goto _arg4; /* un argument BCD */
                case TAN:       /* tangente d'un BCD */
                        ret->vl = 53; goto _arg4; /* un argument BCD */
                case VAL:       /* conversion d'une chaine en numerique */
                        ret->vl = 55; goto _arg5; /* une chaine, un binaire */

                /* celles qui rendent une valeur chaine */
                case CHR:       /* conversion numerique en caractere */
                        ret->vl = 4;    /* code de la fonction CHR$ */
                        goto _arg2;     /* un argument binaire */
                case CURDIR:    /* lecture repertoire courant */
                        ret->vl = 10;
                        goto _noarg;
                case CURVOL:    /* lecture volume courant */
                        ret->vl = 11;
                        goto _noarg;
                case DATE:      /* lecture date systeme */
                        ret->vl = 12;   /* code de la fonction DATE */
                        goto _arg2;     /* un argument binaire */
                case ENV:       /* lecture variable environnement */
                        ret->vl = 68; goto _arg3; /* un argument chaine */
                case GENER:     /* generation de caractere */
                        ret->vl = 18;   /* code de la fonction GENER */
                        /* un argument binaire et une chaine */
                        ret->na = 2; lexical(); typ[0] = TBIN; typ[1] = TSTR;
                        goto nargs;
                case HASH:     /* fonction de HASHCODING */
                        ret->vl = 94;   /* code de la fonction HASH */
                        /* un argument binaire et une chaine */
                        ret->na = 2; lexical(); typ[0] = TSTR; typ[1] = TBIN;
                        goto nargs;
                case HEX:       /* conversion en hexa */
                        ret->vl = 19;   /* code de la fonction HEX */
                        goto _arg2;     /* un argument binaire */
                case INV:       /* inversion d'une chaine */
                        ret->vl = 25; goto _arg3; /* un argument chaine */
                case KBF:       /* lecture d'une touche */
                        ret->vl = 26;   /* code de la fonction KBF */
                        goto _arg2;     /* un argument binaire */
                case LARGE:     /* mise en majuscule */
                        ret->vl = 27; goto _arg3; /* un argument chaine */
                case LEFT:      /* partie gauche d'une chaine */
                        ret->vl = 28; goto _arg5; /* une chaine, un binaire */
                case PARSE:     /* Extraction d'une partie de nom de fichier */
                        ret->vl = 72; /* position dans la table */
                        goto _arg5; /* une chaine, un binaire */

		case PROC:	/* Pointeur de procedure */
			tr_proc_seg_user(97,ret);			
/* 2.1b:AW */		if ( ret->vl == 0 ) {
				erreur(USUAL,erexp3);
                        	Free_ExpMemb(ret);
                                return (GenericNULL(ExpMemb));
			}
			break;
		case USER:	/* Pointeur de fonction de bib dyn */
			tr_proc_seg_user(99,ret);			
/* 2.1b:AW */		if ( ret->vl == 0 ) {
				erreur(USUAL,erexp3);
                                Free_ExpMemb(ret);
                                return (GenericNULL(ExpMemb));
			}
			break;
		case SEGMENT:	/* Pointeur de segment */
			tr_proc_seg_user(100,ret);			
/* 2.1b:AW */		if ( ret->vl == 0 ) {
				erreur(USUAL,erexp3);
                                Free_ExpMemb(ret);
                                return (GenericNULL(ExpMemb));
			}
			break;
		case CODE:	/* Pointeur ambigue */
			tr_proc_seg_user(0,ret);
/* 2.1b:AW */		if ( ret->vl == 0 ) {
				erreur(USUAL,erexp3);
                                Free_ExpMemb(ret);
                                return (GenericNULL(ExpMemb));
			}
			break;
                case RIGHT:     /* partie droite d'une chaine */
                        ret->vl = 39; goto _arg5; /* une chaine, un binaire */
                case SHL:       /* cadrage a gauche d'une chaine */
                        ret->vl = 43; goto _arg3; /* un argument chaine */
                case SHR:       /* cadrage a droite d'une chaine */
                        ret->vl = 44; goto _arg3; /* un argument chaine */
                case SMALL:     /* mise en minuscules */
                ret->vl = 46; goto _arg3; /* un argument chaine */
                case SPACE:     /* generation d'une chaine a blanc */
                        ret->vl = 47;   /* code de la fonction SPACE */
                        goto _arg2;     /* un argument binaire */
                case SUBSTR:    /* extraction d'une sous-chaine */
                        ret->vl = 50;
                        /* une chaine et deux binaires */
                        ret->na = 3; lexical(); typ[0] = TSTR;
                        typ[1] = TBIN; typ[2] = TBIN;
                        goto nargs;
                /* cas particulier de ABS qui accepte tout numerique */
                case ABS:       /* valeur absolue d'un numerique */
                        ret->vl = 0; typ[0] = *tres;
                        goto unarg;
                case VPTR:      /* cas particulier de la fonction VPTR */
                        ret->vl = 66; typ[0] = T_ANY;
                        goto unarg;
                case ALIAS:       /* adresse d'une variable ou pointeur */
                        ret->vl = 86;
			if ( *tres == TSTR )
				typ[0] = T_ANY;
			else
				typ[0] = *tres;
                        goto unarg;
        }
        if ((ret->na != 0) && (usc.code == PAD)) {
                /* on est reste sur la ')' */
                div_verrue = TRUE;  /* prevoir le DIV */
                lexical();          /* pour avaler la derniere usc */
                div_verrue = FALSE; /* du facteur */
        }
        return (ret);
}                                               /* tr_fnt */

static void tr_proc_seg_user(type,ret)
BINAIRE type;
ExpMemb *ret;
{						/* tr_proc_seg_user */
ArgList *args = GenericNULL(ArgList);
ExpMemb *m;

BINAIRE old_aff_verrue;
BYTE typ;

old_aff_verrue = aff_verrue; aff_verrue = 0;


lexical();
if ( usc.code == PTR ) {
	lexical();
} else {
	ret->vl = 0;	/* Erreur de syntaxe */ /* 2.1b:AW */
	return;
}

switch (type) {
	case 0:
	case 97:	/* PROC */
      /* #OK: 21/03/00 (begin) */
      if ( usc.code == PROC ) lexical(); // PROC PTR PROC ...
      /* #OK: 21/03/00 (end) */
		ret->vl = 97; /* position dans la table CLF */

		if ( usc.code == IDENT ) {
			TabProc *tp;
			tp = findproc(0,usc.v.pval);
			if ( tp != GenericNULL(TabProc) ) {
				/* 1er cas : Identificateur de procedure */

				/* Creation de l'argument */
				m = All_ExpMemb();
				if (m == GenericNULL(ExpMemb))
					erreur(FATALE,errmem);

				m->tp = 0; m->na = TBIN2;
				if ( tp->ext ) {
					m->vl = 0xFFFF;
					m->desc = (BYTE *) tp;
				} else {
					if (notaprog) {
						m->desc = (BYTE *) tp;
					} else {
						m->desc = GenericNULL(BYTE);
					}
					m->vl = tp->ads;
				}

				/* Creation de la liste des arguments */
				args = All_ArgList();
				if (args == GenericNULL(ArgList))
					erreur(FATALE,errmem);

				args->va = m; args->suiv = GenericNULL(ArgList);
			
				ret->na = 1;	/* un argument */
				ret->ap = args;
				aff_verrue = old_aff_verrue;
				lexical();
				return;
			} else {
				/* Erreur : Pas d'identificateur de variable */
				/* dans cette 1 ere version */
				ret->vl = 0;
				return;
			}
		}
		break;

	case 99:	/* USER */

		ret->vl = type; /* position dans la table CLF */
		if ( usc.code == FUSER ) {
			/* Creation du 1er argument : numero de fct */
			m = All_ExpMemb();
			if (m == GenericNULL(ExpMemb))
				erreur(FATALE,errmem);
			m->tp = 0;
		 	m->vl = usc.v.ptusr->nofct; m->na = TBIN2;
				
			/* Creation de la liste des arguments */
			args = All_ArgList();
			if (args == GenericNULL(ArgList))
				erreur(FATALE,errmem);

			args->va = m; args->suiv = GenericNULL(ArgList);
			
			/* Creation du 2eme argument : numero de runtime */
			m = All_ExpMemb();
			if (m == GenericNULL(ExpMemb))
				erreur(FATALE,errmem);
			m->tp = 0;
		 	m->vl = usc.v.ptusr->nort; m->na = TBIN2;
				
			/* Creation de la liste des arguments */
			args->suiv = All_ArgList();
			if (args->suiv == GenericNULL(ArgList))
				erreur(FATALE,errmem);

			args->suiv->va = m; args->suiv->suiv = GenericNULL(ArgList);
			

			ret->na = 2;	/* deux arguments : fonction, runtime */
			ret->ap = args;
			aff_verrue = old_aff_verrue;
			lexical();
			return;
		} else {
			/* 2eme cas : Pointeur de User ($=5)		*/
			/*	      || expression chaine ... decoder 	*/

			typ = TSTR;
			if ( (m = tr_exp(&typ)) == GenericNULL(ExpMemb) ) {
				aff_verrue = old_aff_verrue;
				sfdln();return;
			}
			/* Creation de la liste des arguments */
			args = All_ArgList();
			if (args == GenericNULL(ArgList))
				erreur(FATALE,errmem);
			args->va = m; args->suiv = GenericNULL(ArgList);
			
			ret->na = 1;	/* un argument */
			ret->ap = args;
			aff_verrue = old_aff_verrue;
			return;
		}
		break;
	case 100:	/* SEGMENT */
		{
			TabSeg *ts;
			BYTE tres;
			BINAIRE vres;

			ret->vl = type; /* position dans la table CLF */

			if ( is_var_or_seg(FALSE,&ts,&tres,&vres) ) {
				/* 1er cas : expression numerique de segment 	*/
				/* 	|| pointeur de segment ($=5)		*/
				/*	|| expression sous forme de chaine	*/
				/* Creation de l'argument */
				m = All_ExpMemb();
				if (m == GenericNULL(ExpMemb))
					erreur(FATALE,errmem);
				m->tp = tres; m->vl = vres; m->na = TBIN2;
				
				/* Creation de la liste des arguments */
				args = All_ArgList();
				if (args == GenericNULL(ArgList))
					erreur(FATALE,errmem);

				args->va = m; args->suiv = GenericNULL(ArgList);
			
				ret->na = 1;	/* un argument */
				ret->ap = args;
				aff_verrue = old_aff_verrue;
				return;
			} else {
				/* 2eme cas : Identificateur de segment */
				/* Creation de l'argument */
				m = All_ExpMemb();
				if (m == GenericNULL(ExpMemb))
					erreur(FATALE,errmem);
				if ( ts == GenericNULL(TabSeg) ) {
					/* Segment Forward */
					m->tp = tres; m->vl = vres; m->na = TBIN2;
				} else {
					m->tp = 0; m->na = TBIN2;
					if ( ts->ext ) {
						m->vl = 0xFFFF;
						m->desc = (BYTE *) ts;
					} else {
						if (notaprog) {
							m->desc = (BYTE *) ts;
						}
						m->vl = ts->num;
					}
				}
				/* Creation de la liste des arguments */
				args = All_ArgList();
				if (args == GenericNULL(ArgList))
					erreur(FATALE,errmem);
				args->va = m; args->suiv = GenericNULL(ArgList);
			
				ret->na = 1;	/* un argument */
				ret->ap = args;
				aff_verrue = old_aff_verrue;
				lexical();
				return;
			}
		}
		break;
	case 1:		/* CODE */
		ret->vl = 0;
		return;
		if ( usc.code == IDENT ) {
			if (findproc(0,usc.v.pval) != GenericNULL(TabProc)) {
				TabProc *tp;

				tp = findproc(0,usc.v.pval);
				ret->vl = 97;
				/* 1er cas : Identificateur de procedure */
				/* Creation de l'argument */
				m = All_ExpMemb();
				if (m == GenericNULL(ExpMemb))
					erreur(FATALE,errmem);
				m->tp = 0; m->vl = tp->ads; m->na = TBIN2;
			
				/* Creation de la liste des arguments */
				args = All_ArgList();
				if (args == GenericNULL(ArgList))
					erreur(FATALE,errmem);
				args->va = m; args->suiv = GenericNULL(ArgList);
	
				ret->na = 1;	/* un argument */
				ret->ap = args;
				aff_verrue = old_aff_verrue;
				lexical();
				return;
				
			} else if (findseg(0,usc.v.pval) != GenericNULL(TabSeg)) {
				TabSeg *ts;

				ts = findseg(0,usc.v.pval);
				ret->vl = 100;					
				/* 2eme cas : Identificateur de segment */

				/* Creation de l'argument */
				m = All_ExpMemb();
				if (m == GenericNULL(ExpMemb))
					erreur(FATALE,errmem);
				m->tp = 0; m->vl = ts->num; m->na = TBIN2;
				
				/* Creation de la liste des arguments */
				args = All_ArgList();
				if (args == GenericNULL(ArgList))
					erreur(FATALE,errmem);

				args->va = m; args->suiv = GenericNULL(ArgList);
			
				ret->na = 1;	/* un argument */
				ret->ap = args;
				aff_verrue = old_aff_verrue;
				lexical();
                		return;
			} else {
				/* 2eme cas : Pointeur de Proc ($=5)		*/
				/*	      || expression chaine ... decoder 	*/

				typ = TSTR;
				if ( (m = tr_exp(&typ)) == GenericNULL(ExpMemb) ) {
		                        erreur(USUAL,erexp8);
					aff_verrue = old_aff_verrue;
					sfdln();return;
				}
				/* Creation de la liste des arguments */
				args = All_ArgList();
				if (args == GenericNULL(ArgList))
					erreur(FATALE,errmem);
				args->va = m; args->suiv = GenericNULL(ArgList);
			
				ret->na = 1;	/* un argument */
				ret->ap = args;
				aff_verrue = old_aff_verrue;
				return;
			}
		} else {
			if ( usc.code == FUSER ) {
				ret->vl = 99;
				/* Creation du 1er argument : numero de fct */
				m = All_ExpMemb();
				if (m == GenericNULL(ExpMemb))
					erreur(FATALE,errmem);
				m->tp = 0;
		 		m->vl = usc.v.ptusr->nofct; m->na = TBIN2;
				
				/* Creation de la liste des arguments */
				args = All_ArgList();
				if (args == GenericNULL(ArgList))
					erreur(FATALE,errmem);

				args->va = m; args->suiv = GenericNULL(ArgList);
				
				/* Creation du 2eme argument : numero de runtime */
				m = All_ExpMemb();
				if (m == GenericNULL(ExpMemb))
					erreur(FATALE,errmem);
				m->tp = 0;
		 		m->vl = usc.v.ptusr->nort; m->na = TBIN2;
				
				/* Creation de la liste des arguments */
				args->suiv = All_ArgList();
				if (args->suiv == GenericNULL(ArgList))
					erreur(FATALE,errmem);

				args->suiv->va = m; args->suiv->suiv = GenericNULL(ArgList);
			

				ret->na = 2;	/* deux arguments : fonction, runtime */
				ret->ap = args;
				aff_verrue = old_aff_verrue;
				lexical();
                		return;
			} else {
	                        erreur(USUAL,erexp8);
				sfdln(); return;
			}
		}
		break;
}
}						/* tr_proc_seg_user */


