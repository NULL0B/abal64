/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1990, 1999
 *	Module  : ATR
 *	Fichier : PARSE2.C
 *	Version : 2.2b
 *	Date    : 21/11/95
 *	Systeme : DOS / PRL / UNIX / VMS
 *
 *	Traducteur ABAL
 *
 *	[Analyseur syntaxique 2/2]
 *
 */

 /*
 * Mises a jour :
 * ------------
 *	18/07/90 : Mise en conformite avec les versions 1.2e / 1.3a / 1.4a
 *	03/12/90 : Autorise ASK avec debranchement sur valeur de constante
 *	14/05/91 : Correction SELECT expression avec expression constante
 *	-------------------------------------------------------------------
 *	06/09/93 : Modification ON LOCAL ERROR
 *	07/09:93 : Parenthese obligatoire sur l'instruction ERROR 
 *	07/09/93 : ON EXTERN EVENT ...
 *	-------------- 2.1c -----------------------------------------------
 *	05/05/94 : T=(&...),X=(&...) et E=(&...) autorise
 *	24/05/94 : Apres chaque gennew() un init_suivi_registre !
 *	------------ 2.1d -------------------------------------------------
 *	21/11/95 : version dediee 2.1
 *	------------ 2.1e -------------------------------------------------
 *	07/03/97 : Prototype de findvar() modifie, reprise de tous les appels
 *	------------ 2.1f -------------------------------------------------
 *	23/07/99 : Assignation du registre dans TrPause() pour éviter l'utilisation
 *            le Registre particulier 0 (évite une erreur si Pause est la 1ère 
 *            instruction d'une Proc ou Segment avec une expression en paramètre).
 *
 *	25/08/99 : (#SP) Enhancement ATR 25: "OP BREAK".
 *	24/10/00 : (#OK) Add error message: Instruction MASK without parameters.
 * 02/04/01 : (#OK) Bug ATR-68 fixed. Label in the beginning of the procedure or segment.
 *	------------ 2.2b -------------------------------------------------
 * 20/11/02 : (#BG) Révision du END.USER.
 * 22/11/02 : (#SP) Bug with "select" when the case value is a result of the function.
 */

static BOOL trepeat(seg)

/*	traitement de l'iteration REPEAT ... UNTIL
 */
BOOL seg;
{					/* trepeat */
	char 	adr[LGIDENT],adr2[LGIDENT],*ptradr,*adrpile;
	BOOL	flg = TRUE;

	adr2[0] = EOSTR;
	ptradr = &adr2[0];
	/* REPEAT = simple definition d'une etiquette */
	tfdln();
	cretiq(adr);
	defetiq(adr,(BINAIRE) adrimpl);
	pushfin(&ptradr,&adrpile);
	
	/* un bloc d'instruction doit suivre */
	do 
	{
		debut_instruction();
	}
	while ((usc.code != UNTIL) && (instruction(seg)));
	
	popfin(&adrpile);
	if (usc.code == UNTIL)
	{
		gennew();	/* delimiteur de ligne dans le code */

		/* #FC+BG 03/12/02 init_suivi_registre();*/

		/* fin de l'iteration : remonter sur condition fausse */
		deb_expcond = expcond();
		if (deb_expcond == GenericNULL(CdMemb))
		{
			gengoto(adr); sfdln();
		}
		else
		{
			evalcond(FALSE,deb_expcond,adr);
			if (usc.code != FDLN)
			{
				erreur(USUAL,errfdln);
				sfdln();
			}
		}
		/* si necessaire : definir l'adresse de sortie des BREAK */
		if (adr2[0] != EOSTR)
		{
			defetiq(adr2,(BINAIRE) adrimpl);
		}
	}
	else 
	{	
		/* fin de segment ou de procedure */
		erreur(USUAL,ersynt27); flg = FALSE;
	}
	return (flg);
}					/* trepeat */


static BOOL twhile(seg)

/*	traitement de l'iteration WHILE ... WEND
 */
BOOL seg;
{					/* twhile */
	char 	adr[LGIDENT],adr2[LGIDENT],*ptradr,*adrpile;
	BOOL	flg = TRUE;

	/* creer et definir l'etiquette pour remonter du WEND */
	cretiq(adr);
	defetiq(adr,(BINAIRE) adrimpl);
	deb_expcond = expcond();
	if (deb_expcond == GenericNULL(CdMemb))
	{
		sfdln();
	}
	else
	{
		if (usc.code != FDLN)
		{
			erreur(USUAL,errfdln); sfdln();
		}
		/* brancher derriere le WEND sur condition fausse */
		cretiq(adr2);
		evalcond(FALSE,deb_expcond,adr2); 
		ptradr = &adr2[0];
		pushfin(&ptradr,&adrpile);

		/* traiter le bloc d'instructions qui doit suivre */
		do 
		{
			debut_instruction();
		}
		while ((usc.code != WEND) && (instruction(seg)));

		popfin(&adrpile);
		/* fin de l'iteration : remonter au WHILE */
		gennew();	/* delimiteur de ligne dans le code */

		/* #FC+BG 03/12/02 init_suivi_registre(); */

		gengoto(adr);
		/* et definir l'adresse de sortie de la boucle */
		defetiq(adr2,(BINAIRE) adrimpl);
		if (usc.code == WEND)
		{
			tfdln();
		}
		else
		{
			/* fin de segment ou de procedure : anormal */
			erreur(USUAL,ersynt28); flg = FALSE;
		}
	}
	return (flg);
}					/* twhile */


static BOOL trfor(BOOL seg)

/*	traitement de l'iteration FOR ... NEXT
 *	en etant compatible "au mieux" avec le B.A.L. ....
 */
{					/* trfor */
	BOOL	flag = TRUE;
	char	adr[LGIDENT],adr2[LGIDENT],adr3[LGIDENT],adr4[LGIDENT];
	char	*ptradr,*adrpile;
	BINAIRE advar,bfin,bpas,res;
	BYTE	*adesc,tvar,tfin,tpas;
	int	fnt = -1;
	char	locetiq[LGIDENT];
	BYTE	i;
	BINAIRE adrmem;

	/* affectation initiale de l'indice de la boucle */
	lexical();
	if (usc.code != IDENT)
	{ /* erreur : on attend une variable */
		erreur(USUAL,ersynt6);
		sfdln();
		return (TRUE);
	}
	adesc = findvar(usc.v.pval,GenericNULL(BYTE),&advar,GenericNULL(TabSymb *),TRUE);
	verrue_for = TRUE;
	if (!affectation(adesc,advar))
	{
		verrue_for = FALSE;
		return (TRUE);
	}
	verrue_for = FALSE;

	for (i = 0 ; i < lentokmax ; i++)
		locetiq[i] = gletiq[i];

	tvar = typdesc(adesc);
	if ( IS_TSTR(tvar) )
	{
		/* chaine interdite comme indice */
		erreur(USUAL,ersynt31);
		sfdln();
		return (TRUE);
	}

	/* chercher la borne de fin d'iteration */
	if (usc.code != TO)
	{
		/* erreur de syntaxe */
		erreur(USUAL,ersynt1);
		sfdln();
		return (TRUE);
	}

	lexical();	/* avaler le 'TO' */
	/* brancher sur le debut du corps d'iteration */
	cretiq(adr);
	gengoto(adr);
	/* etiquette de l'evaluation de la borne de fin et du pas */
	cretiq(adr2);
	defetiq(adr2,(BINAIRE) adrimpl);
	/* evaluation de la borne de fin d'iteration */
	libreg = firstreg + 1;
	if (!expression(&tvar,&tfin,&bfin))
	{
		/* prendre une borne fictive de 1 */
		tfin = 0; bfin = 1;
	}
	if (tfin == 3)
	{
		/* borne de fin = expression ?? */
		putreg(firstreg,tfin,bfin);
		bfin = firstreg; /* ranger en 1er registre banalise */
	}
	if (usc.code == STEP)
	{	/* pas explicite ? */
		libreg = firstreg + 2;
		lexical(); /* avaler le 'STEP' */
		if (!expression(&tvar,&tpas,&bpas))
		{
			tpas = 0;
			bpas = 1;	/* prendre le pas implicite */
		}
		else if (tpas == 3)
		{ /* pas = expression ?? */
			putreg(firstreg+1,(BINAIRE) tpas,bpas);
			bpas = firstreg+1; /* en 2eme registre banalise */
		}
	}
	else
	{
		tpas = 0;
		bpas = 1;	  /* valeur immediate +1 */
	}

/* #FC+BG 03/12/02 Begin */
	if (tfin == 3)
		genpopreg(bfin);
/* #FC+BG 03/12/02 End */

	if ((tfin == 3) || (tpas == 3))   /* si expressions, alors */
		genret();		  /* preparer un retour d'appel */

	/* liberer registres */
	libreg = firstreg;
	/* Nettoyer les registres */
	Nettoyer_lreg_used(tfin, bfin);	/* #FC+BG 03/12/02 */
	Nettoyer_lreg_used(tpas, bpas);	/* #FC+BG 03/12/02 */

	/* fin de la ligne FOR ... */
	if (usc.code != FDLN)
	{
		erreur(USUAL,errfdln);
		sfdln();
	}

	/* definir l'etiquette de relance de la boucle */
	defetiq(adr,(BINAIRE) adrimpl);
	/* prevoir les eventuels instructions BREAK */
	adr4[0] = EOSTR;
	ptradr = &adr4[0];
	pushfin(&ptradr,&adrpile);

	/* traiter les instructions du corps de la boucle */
	do
	{
		debut_instruction();
	}
	while ((usc.code != NEXT) && (instruction(seg)));

	popfin(&adrpile);
	if (usc.code == NEXT)
	{ /* on doit retrouver l'indice de la boucle */
		gennew();	/* delimiteur de ligne dans le code */

		/* #FC+BG 03/12/02 init_suivi_registre();*/

		lexical();
		if (usc.code != IDENT)  /* erreur : on attend une variable */
			erreur(USUAL,ersynt6);
		if (adesc != findvar(usc.v.pval,GenericNULL(BYTE),&advar,GenericNULL(TabSymb *),TRUE))
			erreur(USUAL,ersynt1);
		/* le reste de la ligne ne nous interesse pas ... */
		sfdln(); /* et tant pis pour les erreurs eventuelles */
		if ((tfin == 3) || (tpas == 3))
		{
			/* si expressions, alors */
			/* GOSUB sur l'evaluation de borne de fin et du pas */
			gengosb(adr2);
		}

		/* mettre la variable dans le 3eme registre banalise */
		if ((*adesc & 0x40) != 0)
		{
			/* avec les indices si variable dimensionnee */
			/*putreg(firstreg+2,3,firstreg-1);*/
			pushreg(0); /* R0 est le registre implicite utilisé pour les variables indicées, utilité de cePUSH ?? */
			gengosb(locetiq);
			putreg(firstreg+2,3,0);
			popreg(0);	/* #FC+BG 03/12/02 Utilité de ce POP ?? */
		}

		if ( (flg_opt) && ((*adesc & 0x40) == 0) && (ismemglobale(*(adesc+1)) == TRUE) )
		{
			if ( IS_TBIN(typdesc(adesc)) )
			{
				/* optimisation : variable binaire sans dimension
				* et en memoire : putbin vaut mieux que putreg
				*/
				fnt = 0;
				if ((advar & (BINAIRE) ISLOCAL) != 0)
					fnt = 1;	/* variable locale */
				if ( IS_TBIN2(typdesc(adesc)) )
					fnt += 2;	/* type % */
				adrmem = bytetobin(adesc+2);
				putbin(fnt,firstreg+2,adrmem,advar);
			}
			else
			{
				/* optimisation : variable BCD sans dimension et en memoire : addition sur elle meme */
				putadr(firstreg+2,advar);
				fnt = -2;
				opt_oper = 1;
			}
		}
		else if ( IS_TBCD(typdesc(adesc)) )
			putadr(firstreg+2,advar);
		else
			putreg(firstreg+2,2,advar);
		
		libreg = firstreg+3;
		/* additionner avec le pas de la boucle */
		res = genoper(0,3,firstreg+2,tpas,bpas,tvar);
		/* ranger ce resultat dans la variable */
		if ((*adesc & 0x40) != 0)
		{
			/* avec les indices si variable dimensionnee */
			/*pushreg(firstreg-1);
			popreg(0);*/
			gengosb(locetiq);
		}

		if (fnt == -1)
			putvar(3,res,advar);
		else 
		{
			if (fnt == -2) 
			{ /* optimisation BCD */
				opt_oper = 0; res = firstreg+2;
			}
			else 
			{
				/* optimisation : stobin plutot que putvar */
				stobin(fnt,adrmem,res,advar);
			}
		}

		if (tfin == 4)
			tfin = 3; /* retablir registre */

		if (tpas != 0)
		{
			/* le pas n'est pas une valeur immediate */
			if (tpas == 4)
				tpas = 3; /* retablir registre */
			/* distinguer le cas d'un pas negatif ... */
			cretiq(adr2);
			genrelat(TRUE,5,tpas,bpas,0,0,adr2);
			/* reboucler si variable <= borne de fin */
			genrelat(TRUE,3,3,res,tfin,bfin,adr);
			/* sinon sortir de la boucle */
			cretiq(adr3); gengoto(adr3);
			defetiq(adr2,(BINAIRE) adrimpl);
			/* reboucler si variable >= borne de fin */
			genrelat(TRUE,2,3,res,tfin,bfin,adr);
			/* definir la sortie de la boucle */
			defetiq(adr3,(BINAIRE) adrimpl);
		}
		else
		{
			/* le pas est une valeur immediate */
			if (negbin(bpas))
				 /* si il est negatif : reboucler si variable >= borne de fin */
				genrelat(TRUE,2,3,res,tfin,bfin,adr);
			else
				/* si il est positif : reboucler si variable <= borne de fin */
				genrelat(TRUE,3,3,res,tfin,bfin,adr);
		}

		/* si necessaire : definir l'adresse de sortie des BREAK */
		if (adr4[0] != EOSTR)
			defetiq(adr4,(BINAIRE) adrimpl);
	}
	else
	{	/* erreur : NEXT etait attendu avant la fin du code */
		erreur(USUAL,ersynt30); flag = FALSE;
	}
	
	return (flag);
}					/* trfor */


static void pushfin(adr,ptr_old)

/*	memorise une nouvelle adresse de fin d'iteration courante
 *	pour le traitement des instructions BREAK
 */
char **adr,**ptr_old;
{					/* pushfin */
	if (flg_itere)  /* deja une iteration en cours : il faut empiler */
		*ptr_old = fin_itere;
	else {
		*ptr_old = GenericNULL(char); flg_itere = TRUE;
	}
	fin_itere = *adr;
}					/* pushfin */


static void popfin(ptr_old)

/*	depile la derniere adresse de fin d'iteration
 */
char **ptr_old;
{					/* popfin */
	if (*ptr_old == GenericNULL(char))
		flg_itere = FALSE;
	else 
		fin_itere = *ptr_old;
}					/* popfin */


static BOOL traitsel(seg)

/*	traitement de l'enonce SELECT ... CASE ... DEFAULT ... ENDSEL
 */
BOOL seg;
{					/* traitsel */
	BOOL	flg = TRUE, selencours = TRUE;
	BOOL	deb = TRUE, mult = FALSE, def = FALSE;
	char	adrsuite[LGIDENT],adrbloc[LGIDENT],adrfin[LGIDENT];
	BYTE	tvar,tcas,typ;
	BINAIRE	advar,vcas;

	lexical();	/* avaler le SELECT */

	/* Evalue la variable (jusqu'a la version 1.3) ou
	 * l'expression (a partir de la 1.4) qui va determiner
	 * l'aiguillage
	 */
	libreg = firstreg + 1;
	typ = T_ANY;

	if (!expression(&typ,&tvar,&advar)) 
	{
		erreur(USUAL,ersynt18);
		sfdln();
		/* par defaut : prendre le 1er registre banalise */
		tvar = 3;
		advar = firstreg;
		typ = T_ANY;
		sfdln();
	}
	else
	{
		/* Si le resultat de l'evaluation de l'expression n'est
		 * pas deja dans un registre, charger le premier registre
		 * banalise avec cette valeur.
		 * Si le type est chaine ou BCD, et que l'expression se
		 * limite a une variable, utiliser VPT au lieu de LDV.
		 */
		if (tvar != 3) 
		{
			if ( IS_TBIN(typ) ) 
			{
				typ = TBIN;
				putreg(firstreg,tvar,advar);
			}
			else 
			{
				if ((tvar == 2) && ( IS_TBCD(typ) || IS_TSTR(typ) ))
					putadr(firstreg,advar);
				else
					putreg(firstreg,tvar,advar);
			}
			advar = firstreg;
			tvar = 3;
		}
		else 
		{
			/* Le resultat de l'evaluation de l'expression est dans
			 * un registre, le passer dans le premier registre banalise.
			 */
			putreg(firstreg,tvar,advar);
			advar = firstreg;
			tvar = 3;
		}
		if (usc.code != FDLN) 
		{
			erreur(USUAL,errfdln);
			sfdln();
		}
	}

	/* Traite les options */
	cretiq(adrfin);
	do
	{
	   debut_instruction();
	   switch(usc.code)
		{
		case CASE:
			if (deb)
				deb = FALSE;
			else
			{
				if (def)
				{
					/* clause default deja definie */
					erreur(USUAL,ersynt36);
					sfdln();
					break;
				}
				mult = TRUE;
				gengoto(adrfin);
				defetiq(adrsuite,(BINAIRE) adrimpl);
			}

			cretiq(adrbloc);

			do
			{
				cretiq(adrsuite);
				lexical();
				libreg = firstreg + 1;

				if (!expression(&typ,&tcas,&vcas))
				{
					tcas = 0;
					vcas = 0; /* prendre 0 par defaut */
				}

				/* la variable est deja en registre */
				/* Si c'est une chaine, inclusion */
				/* sinon stricte egalite */
				if ( IS_TSTR(typ) )
					genrelat(TRUE,6,tvar,advar,tcas,vcas,adrbloc);
				else
				{
				if (usc.code == FDLN)
					genrelat(FALSE,0,tvar,advar,tcas,vcas,adrsuite);
				else
					genrelat(TRUE,0,tvar,advar,tcas,vcas,adrbloc);
				}
				
				Nettoyer_lreg_used(tcas, vcas);	/*	#FC+BG 03/12/02 */
			}
			while (usc.code == VIG);

			if (usc.code != FDLN)
			{
				/* on doit etre en fin de ligne */
				erreur(USUAL,errfdln); sfdln();
			}
			if ( IS_TSTR(typ) )
				gengoto(adrsuite);

			defetiq(adrbloc,(BINAIRE) adrimpl);
			/* force adresse implantation dans fichier liste */
			ALadrimpl = adrimpl;
			break;

		case DEFAULT:
			if (def)
			{
				/* clause default deja definie */
				erreur(USUAL,ersynt36); sfdln(); break;
			}
			def = TRUE;
			if (deb)
				deb = FALSE;
			else
			{
				mult = TRUE;
				gengoto(adrfin);
				defetiq(adrsuite,(BINAIRE) adrimpl);
			}
			tfdln();
			/* force adresse implantation dans fichier liste */
			ALadrimpl = adrimpl;
			break;

		case ENDSEL:
			if (!deb)
			{
				if (!def)
					defetiq(adrsuite,(BINAIRE) adrimpl);
				if (mult)
					defetiq(adrfin,(BINAIRE) adrimpl);
			}

			Nettoyer_lreg_used(tvar, advar);	/*	#FC+BG 03/12/02 */

			tfdln();
			selencours = FALSE;
			break;

		default:
			if (deb)
			{
				erreur(USUAL,ersynt35);
				sfdln();
			}
			else if (!instruction(seg))
			{
				/* arret sur fin proc ou seg */
				erreur(USUAL,ersynt35);
				flg = selencours = FALSE;
			}
	   }
	}
	while (selencours);

	return (flg);
}					/* traitsel */


static void debut_instruction()

/*	traiter le debut d'une instruction, qui peut etre une etiquette
 */
{					/* debut_instruction */
	do {
	   lexical();
	   if (usc.code == ETIQ) {
		
		/* #OK: 02/04/01 (begin)*/	
	    if (beginProcOrSegm)
			defetiq(usc.v.pval,(BINAIRE) 0);
		else
		/* #OK: 02/04/01 (end)*/	
		defetiq(usc.v.pval,(BINAIRE) adrimpl);
		lexical();
	   }
	}
	while (usc.code == FDLN);
}					/* debut_instruction */


static void trfnspe(fnt)

/*	traitement des instructions WAIT, MASK et RESTORE
 *	en entree, 'fnt' distingue l'une des trois fonctions.
	ver15 : HOTKEY en saisie, INITGLOBAL, INITLOCAL
		ASKCOLOR 2 parametres
		ASKATB
		END.SEG END.PROC END.USER
 */
int fnt;
{					/* trfnspe */
	BYTE	typ,top[2];
	BINAIRE	vop[2];
	BINAIRE n=1;

	libreg = firstreg;

	lexical();
	if ( usc.code == FDLN) {
		if (fnt == 62) { /* RESTORE */
			top[0] = 0; vop[0] = 1;	/* val. immediate 1 par defaut */
		} else if ( fnt == 89 ) { /* END.SEG */
			geneds(); return;
		} else if ( fnt == 88 ) { /* END.PROC */
			genedp(); return;
		} else 	if ( (fnt == 76) || (fnt == 77) ) {
			top[0] = 0; vop[0] = (BYTE) (fnt-76);
			/* val immediate 0 (GLOBAL) , 1 (LOCAL) */
		}
		/* #OK 24/10/00 (begin) */
        else if ( fnt == 60)
	        erreur(USUAL,erexp6); /* variable */		
        /* #OK 24/10/00 (end) */
	} else {
		if ( fnt == 88 ) { /* END.PROC [ <nom de proc> | <pointeur de Proc> ] */
			if ( usc.code == IDENT ) {
				TabProc *dproc;
				if ( (dproc = findproc(0,usc.v.pval)) != GenericNULL(TabProc)) {
					genlibproc(dproc,0,0);
				}
				else {
					typ = TSTR;
					if (!expression(&typ,&top[0],&vop[0])) {
						erreur(USUAL,ersynt17); sfdln();
					}
					else {
						/* Test variable pointeur de Proc */
						if ( simplexp && (top[0] == 2 ) ) {
							genlibproc(GenericNULL(TabProc),top[0],vop[0]);		
						}
						else {
							erreur(USUAL,ersynt17); sfdln();
						}
					}
				}
			}
			else	{
				erreur(USUAL,ersynt17); sfdln();
			}
			return;
		} 
		else if (fnt == 87) { /* END.USER <nom de biblio> | <ident> */
			BYTE no = 0xFF;

			if ( usc.code == IDENT ) {
				TabRt *trt;
				trt = RacTabRt;
				while ( trt != GenericNULL(TabRt) ) {
/* #BG 20/11/02					if ( Xstrcmp(usc.v.pval,trt->ident) == 0 ) {
Attention: Le nom de la RT ds le .DEF (RUNTIME = "TOTO") doit etre en majuscules!!!
*/
					if ( (Xstrcmp(usc.v.pval, trt->ident) == 0) || (Xstrcmp(usc.v.pval, trt->nom) == 0)) {
						no = (BYTE)trt->nort;
						break;
					}
					trt = trt->suiv;	

				}
			} else {
//				verrue_findvar = TRUE;
				typ = TBIN;
				if (!expression(&typ,top,vop)) {
					*top = 0; *vop = 0; /* prendre 0 par defaut */
				}
//				verrue_findvar = FALSE;

				if ((*top == 0) && (*vop > 254))
					*vop = 0;
				else
					no = *vop;
			}

			if ( no != 0xFF) {
				genlibuser(no);
			} else {
				erreur(USUAL,ersynt1); sfdln();
			}

			return;
		} else if ( fnt == 89 ) { /* END.SEG [<expression> | <ident>] */
			TabSeg *ps;
			if ( is_var_or_seg(TRUE,&ps,&top[0],&vop[0]) ) {
				genlibseg(GenericNULL(TabSeg),top[0],vop[0]);
			} else {
				genlibseg(ps,0,0);
			}
			return;
		} else {
		        if ((usc.code != PAG) && (fnt == 93)) {
				/* erreur : '(' attendue */
       	        		erreur(USUAL,ersynt19); sfdln(); return;
       			} 
			typ = TBIN;
			if (!expression(&typ,&top[0],&vop[0])) {
				sfdln(); return;
			}
			if ( fnt == 82 ) { /* Traitement ASKCOLOR : couleur de fond */
				if ( usc.code != VIG ) {
					erreur(USUAL,errfdln); sfdln(); return;
				}
				lexical();
				typ = TBIN;
				if (!expression(&typ,&top[1],&vop[1])) {
					sfdln(); return;
				}
				n=2;
			} else if ( fnt == 93 ) { /* traitement EVENT */
				if ( usc.code != EGAL ) {
					erreur(USUAL,errfdln); sfdln(); return;
				}
				lexical();
				typ = TBIN;
				if (!expression(&typ,&top[1],&vop[1])) {
					sfdln(); return;
				}
				n=2;
			}

			if (usc.code != FDLN) {
				erreur(USUAL,errfdln); sfdln(); return;
			}
		}
	}

	genclf(TRUE,fnt,n,0,0,top,vop,GenericNULL(BYTE));
}					/* trfnspe */


static void trerreur()

/*	traitement de ERROR <expression>
 */
{					/* trerreur */
	BYTE	typ,top;
	BINAIRE	vop;

	libreg = firstreg;
	lexical();
        if (usc.code != PAG) {  /* erreur : '(' attendue */
       	        erreur(USUAL,ersynt19); sfdln(); return;
       	} else {
		typ = TBIN;
		if (!expression(&typ,&top,&vop)) {
			sfdln(); return;
		}
	}
	generreur(top,vop);
}					/* trerreur */


static void traffn(fnt)

/*	traitement des instructions
 *		DATE(i) 	= chaine,
 *		KBF(i)  	= chaine,
 *	et	LOADUSER(i)	= chaine,
 */
int fnt;
{					/* traffn */
	BYTE typ,top1,top2;
	BINAIRE vop1,vop2;

	libreg = firstreg;
	lexical();	/* avaler le mot cle */
	if (usc.code != PAG) {
		erreur(USUAL,ersynt19); sfdln(); return;
	}
	lexical(); typ = TBIN;
	if (!expression(&typ,&top1,&vop1)) {
		sfdln(); return;
	}
	/* #IJM 06/11/02
		Two forms are accepted :
		OLD FORM	keyword(n) = string	
		NEW FORM	keyword(n,string)
	 */
	switch ( usc.code ) {
		case	PAD	:
			lexical();
			if (usc.code != EGAL) {
				erreur(USUAL,ersynt40); sfdln(); return;
			}
			lexical(); typ = TSTR;
			if (!expression(&typ,&top2,&vop2)) {
				sfdln(); return;
			}
			if (usc.code != FDLN) {
				erreur(USUAL,errfdln); sfdln(); return;
			}
			break;

		case	VIG	:
			lexical(); typ = TSTR;
			if (!expression(&typ,&top2,&vop2)) {
				sfdln(); return;
				}
			if (usc.code != PAD) {
		                erreur(USUAL,ersynt20); 
				sfdln(); return;
				}
			lexical();
		        if (usc.code != FDLN) {
				erreur(USUAL,errfdln); sfdln(); return;
	        		}
			break;

		default		:
			erreur(USUAL,ersynt20); 
			sfdln(); 
			return;
		}

	genaffn(fnt,top1,top2,vop1,vop2);
}					/* traffn */


static void trpause()

/*	traitement de l'instruction PAUSE
 */
{					/* trpause */
	BYTE	typ,top;
	BINAIRE	vop;

	libreg = firstreg;
	lexical();	/* avaler le 'PAUSE' */
	typ = T_ANY;
	if ((usc.code == FDLN) || (!expression(&typ,&top,&vop))) {
		top = 0; vop = 0;	/* val. immediate 0 par defaut */
	}
	if (usc.code != FDLN) {
		erreur(USUAL,errfdln); sfdln();
	}
	genpause(top,vop);
}					/* trpause */


static void tradop()

/*	traitement de l'intruction 'OP'
 */
{					/* tradop */
	BINAIRE advar;
	BYTE	tvar;
	char	adr[LGIDENT];

	libreg = firstreg;
	if (errbranch(FALSE,&tvar,&advar,adr)) {
		genop(tvar,advar,adr);
		if (usc.code != FDLN)
			tfdln();
	}
	else
		sfdln();
}					/* tradop */


#ifdef _KEYWORD_TRACE
static BOOL trtraceonoff(int f)
{
	BYTE	typ=TBIN;
	BYTE	targ=0;
	BINAIRE	varg=0;
	lexical();
	if ( usc.code != PAG ) {
                erreur(USUAL,erexp7); return (FALSE);
	       }
        lexical(); /*avaler la parenthese*/
	if (!(expression(&typ,&targ,&varg)))
		return (FALSE);
	if ( usc.code != PAD ) {
                erreur(USUAL,erexp7); return (FALSE);
	       }
        lexical(); /*avaler la parenthese*/
	return( gentrace( f, 1, &targ, &varg, 0 ) );
}

static BOOL trtraceprint(int f)
{
	BYTE	typ[8];
	BYTE	targ[8];
	BINAIRE	varg[8];
	BINAIRE	maxarg;
	BINAIRE	i;
	BINAIRE channel=0;

	lexical();
	if ( usc.code != PAG ) {
                erreur(USUAL,erexp7); return (FALSE);
	       }
        lexical(); /*avaler la parenthese*/
	typ[0] = TBIN;
	typ[1] = TBIN;
	typ[2] = TSTR;
	typ[3] = TSTR;
	typ[4] = TSTR;
	if ( f == 104 )
		maxarg = 4;
	else	maxarg = 5;

	/* collect channel ID : must be an integer constant */
	if (!(expression(&typ[0],&targ[0],&varg[0])))
		return (FALSE);
	else if ( usc.code != VIG ) {
                erreur(USUAL,erexp7); 
		return(FALSE);
		}
	else if ( targ[0] != 0 )
		return (FALSE);
	else	{
		channel = varg[0];
		lexical();
		}
	for ( i=0; i < maxarg; i++ ) {
		if (!(expression(&typ[i],&targ[i],&varg[i])))
			return (FALSE);
		else if ( usc.code == PAD )
			break;
		else if ( usc.code != VIG ) {
	                erreur(USUAL,erexp7); 
			return (FALSE);
			}
		else	{
			lexical(); /*avaler la parenthese*/
			}
		}
	
	return( gentrace( f, maxarg, targ, varg, channel ) );
}

static BOOL trtrace()
{
        lexical();
	switch ( usc.code ) {
		case	ON	:
			trtraceonoff( 102 );  break;
		case	OFF	:
			trtraceonoff( 103 ); 
			break;
		case	PRINT	:
			trtraceprint( 104 ); 
			break;
		case	HEX	:
			trtraceprint( 105 ); 
			break;
		}
	
}
#endif	// _KEYWORD_TRACE


static BOOL tradon(seg)

/*	traitement d'une instruction commencant par 'ON'
 */
BOOL seg;
{					/* tradon */
	BYTE	typ,tres;
	BINAIRE advar,vres;
	char	adr[LGIDENT],adr2[LGIDENT];
	int	tfn;
	BOOL	flg_do, flg_ret = TRUE;
	BOOL	flg_local = FALSE;
        TabProc *dproc=GenericNULL(TabProc);
        BYTE *adesc;

	lexical();

	if (usc.code == TIMER) {
		lexical();
		typ = T_ANY; libreg = firstreg;
		if (!expression(&typ,&tres,&vres)) {
			sfdln(); return(TRUE);
		}
		if (IS_TSTR(typ)) {
			erreur(USUAL,ersynt31); sfdln(); return(TRUE);
		}
		if (usc.code == GOTO)
			tfn = 1;
		else if (usc.code == GOSUB)
			tfn = 2;
		else {
			erreur(USUAL,ersynt1); sfdln(); return (TRUE);
		}
		if (!recadr()) {
			sfdln(); return(TRUE);
		}
		gentim(tfn,tres,vres,usc.v.pval);
		tfdln(); return(TRUE);
	}
	else if (usc.code == EVENT) {
		cretiq(adr); cretiq(adr2);
		genwhen(TRUE,1,adr); gengoto(adr2);
		defetiq(adr,(BINAIRE) adrimpl);

		deb_expcond = expcond();
		if (deb_expcond == GenericNULL(CdMemb)) {
			sfdln(); return (TRUE);
		}
		cretiq(adr); evalcond(TRUE,deb_expcond,adr);
		genwhen(FALSE,2,GenericNULL(char));
		defetiq(adr,(BINAIRE) adrimpl);
	
		if (usc.code != FDLN) {
			erreur(USUAL,errfdln); sfdln();
		}

		lexical();
		if (usc.code == DO) {
			genwhen(FALSE,8,GenericNULL(char)); flg_do = TRUE;
		}
		else if (usc.code == THEN) {
			genwhen(FALSE,4,GenericNULL(char)); flg_do = FALSE;
		}
		else {
			erreur(USUAL,ersynt1); sfdln(); flg_do = FALSE;
		}
		lexical();
		if (usc.code != FDLN) {
			erreur(USUAL,errfdln); sfdln();
		}
		/* traiter le bloc d'instructions qui doit suivre */
		do {
			debut_instruction();
		}
		while ((usc.code != END) && (instruction(seg)));
		if (flg_do)
			genwhen(FALSE,16,GenericNULL(char));
		defetiq(adr2,(BINAIRE) adrimpl);
		if (usc.code == END) {	
			lexical();
			if (usc.code != EVENT) {
				erreur(USUAL,ersynt1); sfdln();
			}
			else
				tfdln();
		}
		else {
			erreur(USUAL,ersynt47); flg_ret = FALSE;
		}
		return (flg_ret);
	}
	else if ( (usc.code != ERROR) && (usc.code != LOCAL) ) {
		if (usc.code == EXTERN) {
			/* ON EXTERN EVENT */
			lexical();
			if (usc.code != EVENT) {
				erreur(USUAL,ersynt1); sfdln(); return(TRUE);
			}
			lexical();
			switch ( usc.code ) {
				case GOTO:
					lexical();
					switch (usc.code) {
						case ETIQ:
							Xstrcpy(adr,usc.v.pval);
							break;
						case NEXT:
							cretiq(adr);
							break;
						case BREAK:
					                if (!flg_itere) {
							/* pas d'iteration en cours */
                        					erreur(USUAL,ersynt45); sfdln();
                					} else {
					                        if (*fin_itere == EOSTR) {
                                					cretiq(fin_itere);
                                					/* creer l'etiquette */
                        					}
					                        Xstrcpy(adr,fin_itere);
								genwhen(TRUE,0x60,adr);
								sfdln(); return(TRUE);
					                }
					                break;
						default:
					                erreur(USUAL,ersynt10); sfdln(); return(TRUE);
					}
					genwhen(FALSE,0x60,adr);
					sfdln(); return(TRUE);
				case GOSUB:
				        if (recadr()) {
						genwhen(FALSE,0x61,usc.v.pval);
						sfdln(); return(TRUE);
					}
				case CALL:
				{
				BINAIRE i;
				BYTE fct;
					lexical();
				        if (usc.code != IDENT) {
						if ( usc.code != PAG ) {
					        /* erreur : il faut un nom de proc */
	        	        			erreur(USUAL,ersynt16); sfdln(); return(TRUE);
						} else {
							lexical();
							if ( usc.code != IDENT ) {
		        	        			erreur(USUAL,ersynt17); sfdln(); return(TRUE);
							} else {
								adesc = findvar(usc.v.pval,GenericNULL(BYTE),&advar,GenericNULL(TabSymb *),TRUE);
								if ( adesc == GenericNULL(BYTE) ) {
	                						erreur(USUAL,ersynt17); sfdln(); return(TRUE);
								} else {
									DCLInfo dcl;
									dcl.adrdesc = advar;
									GetDCLTable(&dcl);
									if ( (dcl.type == TSTR) && (dcl.longueur == 5) ) {
										fct = 0x63;
										if ( dcl.dim1 ) {
											lexical();
											if ( usc.code != PAG ) {
	                									erreur(USUAL,ersynt17); sfdln(); return(TRUE);
											} else {
												/* expression */
												if ( dcl.dim2 ) {
													lexical();
													if ( usc.code == VIG ) {
														/* expression */
														lexical();
														if ( usc.code != PAD ) {
	                												erreur(USUAL,ersynt17); sfdln(); return(TRUE);
														}
													} else {		
	                											erreur(USUAL,ersynt17); sfdln(); return(TRUE);
													}
												} else {
												}
											}
										} else {
											lexical();
											if ( usc.code != PAD ) {
	                									erreur(USUAL,ersynt17); sfdln(); return(TRUE);
											}
										}
									} else {
		                						erreur(USUAL,ersynt17); sfdln(); return(TRUE);
									}
								}
							}
						}
        				} else {
						i=0;
						advar=0;
						if ( usc.excode == MODULE ) {
							i=1;
						}
					        dproc = findproc(i, usc.v.pval);
				        	if (dproc == GenericNULL(TabProc)) {
						/* procedure inconnue */
						/* mais peut etre un pointeur de proc */
					                adesc = findvar(usc.v.pval,GenericNULL(BYTE),&advar,GenericNULL(TabSymb *),TRUE);
					                if ( adesc == GenericNULL(BYTE) ) {
	                					erreur(USUAL,ersynt17); sfdln(); return(TRUE);
							} else {
								DCLInfo dcl;
								dcl.adrdesc = advar;
								GetDCLTable(&dcl);
								if ( (dcl.type == TSTR) && (dcl.longueur == 5) ) {
									fct = 0x63;
								} else {
		                					erreur(USUAL,ersynt17); sfdln(); return(TRUE);
								}
							}
       						} else {
							fct = 0x62;
							adesc = (char *) dproc;
						}
					}
					genwhen(advar,fct,adesc);
					sfdln(); return(TRUE);
				}
				default:
					erreur(USUAL,ersynt1);
					sfdln(); return(TRUE);
			}
		} else {
		/* peut etre le ON .. GOTO */
		typ = T_ANY; libreg = firstreg;
		if (!expression(&typ,&tres,&vres)) {
			sfdln(); return(TRUE);
		}
		if (IS_TSTR(typ)) {
			erreur(USUAL,ersynt31); sfdln(); return(TRUE);
		}
		if (usc.code != GOTO) {
			erreur(USUAL,ersynt1); sfdln(); return(TRUE);
		}
		if (!recadr()) {
			sfdln(); return(TRUE);
		}
		genrelat(TRUE,5,tres,vres,0,0,usc.v.pval);
		lexical();
		if (usc.code != VIG) {
			erreur(USUAL,ersynt1); sfdln(); return(TRUE);
		}
		if (!recadr()) {
			sfdln(); return(TRUE);
		}
		genrelat(TRUE,0,tres,vres,0,0,usc.v.pval);
		lexical();
		if (usc.code != VIG) {
			erreur(USUAL,ersynt1); sfdln(); return(TRUE);
		}
		if (!recadr()) {
			sfdln(); return(TRUE);
		}
		gengoto(usc.v.pval); tfdln();
		}
	} else {
		if ( usc.code == LOCAL ) {
			flg_local = TRUE;
			lexical();
			if ( usc.code != ERROR ) {
				erreur(USUAL,ersynt1); sfdln();
			}
		}
		lexical();
		if ( (usc.code == ABORT) && (flg_local == FALSE) ) {
			/* ON ERROR ABORT */
			geneab(); tfdln();
		}
		else if (usc.code == GOTO) {	/* ON ERROR GOTO */
			libreg = firstreg;
			if (errbranch(TRUE,&tres,&advar,adr)) {
				generg(flg_local,tres,advar,adr);
				tfdln();
			}
			else
				sfdln();
		}
		else {
			erreur(USUAL,ersynt1); sfdln();
		}
		return (TRUE);
	}
	return(TRUE);
}					/* tradon */


static void tradof()

/*	traitement d'une instruction commencant par 'OF'
 */
{					/* tradof */
    BYTE	typ,tres;
    BINAIRE	vres,n;
    char	adr[LGIDENT], adrfin[LGIDENT];

    typ = T_ANY; libreg = firstreg; lexical();
    if (!expression(&typ,&tres,&vres)) {
	sfdln(); return;
    }
    if (IS_TSTR(typ)) {
	erreur(USUAL,ersynt31); sfdln(); return;
    }
    if (tres < 2) {
	erreur(USUAL,ersynt38); sfdln(); return;
    }
    if (! IS_TBCD(typ)) {
	/* cas particulier : utilisation de JMR/GSR */
	if (tres != 3) {	/* mettre l'expression dans le 1er registre */
		putreg(firstreg,tres,vres); vres = firstreg;
	}
	if (usc.code == GOTO)	n = 0;
	else if (usc.code == GOSUB) n = 1;
	else {
		erreur(USUAL,ersynt1); sfdln(); return;
	}
	cretiq(adr); gendebjmr(n,vres,adr);
	n = 0;
	do {
		if (!recadr()) {
			sfdln(); return;
		}
		genetqjmr(usc.v.pval);
		n++; lexical();
	}
	while (usc.code == VIG);
	if (usc.code != FDLN) {
		erreur(USUAL,errfdln); sfdln();
	}
	defetiq(adr,n);
    }
    else { /* cas general */
	if (tres != 3) { /* mettre l'expression dans le 1er registre */
		putadr(firstreg,vres);
		tres = 3; vres = firstreg;
	}
	n = 1;
	if (usc.code == GOTO) {
	   do {
		if (!recadr()) {
			sfdln(); return;
		}
		genrelat(TRUE,0,tres,vres,0,n,usc.v.pval);
		n++;
		lexical();
	   }
	   while (usc.code == VIG);
	   if (usc.code != FDLN) {
		erreur(USUAL,errfdln); sfdln();
	   }
	}
	else if (usc.code == GOSUB) {
	   cretiq(adrfin);
	   do {
		if (!recadr()) {
			sfdln(); return;
		}
		lexical();
		if (usc.code == VIG) {
			cretiq(adr); genrelat(TRUE,1,tres,vres,0,n,adr);
		}
		else 
			genrelat(TRUE,1,tres,vres,0,n,adrfin);
		gengosb(usc.v.pval);
		if (usc.code == VIG) {
			gengoto(adrfin);
			defetiq(adr,(BINAIRE) adrimpl);
		}
		n++;
	   }
	   while (usc.code == VIG);
	   if (usc.code != FDLN) {
		erreur(USUAL,errfdln); sfdln();
	   }
	   defetiq(adrfin,(BINAIRE) adrimpl);
	}
	else {
		erreur(USUAL,ersynt1); sfdln();
	}
    }
}					/* tradof */


static BOOL errbranch(must,tvar,advar,adr)

/*	traitement d'un debranchement d'erreur : 'etiq,var'
 *	si 'must' est VRAI, la presence de la variable est imposee
 *	car on est dans le cas d'un ON ERROR GOTO, sinon la variable
 *	est optionnelle car on est dans le cas d'un OP. Dans ce dernier
 *	cas, l'etiquette peut egalement etre remplacee par 'NEXT'.

 *	#SP: 25/08/99 :
 *	Modification of "errbranch" instruction to support "OP BREAK" construction.
 *	It works at the same way as "OP NEXT" but the used label name=fin_itere
 *	must be defined later after the end of parsing loop.
 */

BOOL must;
BYTE *tvar;
BINAIRE *advar;
char *adr;
{						/* errbranch */
	BYTE *adesc,typ;
/* #SP: 25/08/99 (begin) */
#ifdef __ATR22__
	BYTE is_break=0;
#endif
/* #SP: 25/08/99 (end) */


	if (must) {	/* cas du ON ERROR GOTO */
		if (!recadr()) { 
			return (FALSE);
		}
		Xstrcpy(adr,usc.v.pval);
	}
	else {		/* cas du OP, NEXT est possible ... */
		lexical();
		if (usc.code == NEXT) {
			cretiq(adr);	/* etiquette speciale */
		}
/* #SP: 25/08/99 (begin) */
#ifdef __ATR22__
		else if (usc.code == BREAK) {
			is_break=1;
			if (!flg_itere) {// pas d'iteration en cours 
				erreur(USUAL,ersynt45); sfdln();
    }else{
				if (*fin_itere == EOSTR) cretiq(fin_itere);	// creer l'etiquette 
				Xstrcpy(adr,fin_itere);
			}
		}
#endif
/* #SP: 25/08/99 (end) */
		
		else {	/* il faut une etiquette */
			if (usc.code == ETIQ) {
				Xstrcpy(adr,usc.v.pval);
			}
			else {
				erreur(USUAL,ersynt10); sfdln(); return(FALSE);
			}
		}
	}
	lexical();
	if (usc.code != FDLN) {
		if (usc.code != VIG) {
			erreur(USUAL,ersynt1); sfdln(); return (FALSE);
		}
		lexical(); /* avaler la parenthese */
		if (!reference(0,&adesc,advar,tvar,&typ))
			return (FALSE);	/* il faut une variable de reception */
		else if ( IS_TSTR(typ) || IS_TBCD(typ) )
			erreur(USUAL,ersynt31);
	}
	else {	/* pas de variable de reception : mettre 0 par defaut */
		if (must) {	/* sauf si interdit par appelant */
			erreur(USUAL,ersynt6); return (FALSE);
		}
		*tvar = 0; *advar = 0;
	}
	return (TRUE);
}						/* errbranch */


/*	----------------------------------------	*/
/*	traitement des instructions PRINT et ASK	*/
/*	----------------------------------------	*/

BOOL trfnprn (advar)

/*	traduction de la FONCTION PRINT dans une variable 
 */
BINAIRE	advar;
{						/* trfnprn */
	BYTE typ,top;
	BINAIRE vop;

	lexical();	/* avaler le mot cle */
	if (usc.code != PAG) {
		erreur(USUAL,ersynt19); return (FALSE);
	}
	geniof(2,advar);
	lexical();
	do {
		switch (usc.code) {
			case HOME:
				genhome(); lexical(); break;
			case BELL:
				genbell(); lexical(); break;
			case CLEAR:
			case PAGE:
				genclear(); lexical(); break;
			case ATB:
				if (!trudir(2)) libiof();
				break;
			case PAINT:
				if (!trddir(2)) libiof();
				break;
			case PAG:
				if (!trfmt()) libiof();
				break;
			case PAD:
				break;
			case CSTR:
				/* Si cste chaine est suivie de '+' ou '!'
				   ca devient une expression */
				if (!lookexpstr()) {
					geniprn(usc.v.pval);
					lexical();
					break;
				}
			default: /* doit etre une expression */
				typ = T_ANY;
				if (!expression(&typ,&top,&vop)) {
				   	sfdln(); libiof(); return (FALSE);
				}
				genprn(top,vop); break;
		}
		if (usc.code != PAD) {
			if (usc.code != VIG) {
				erreur(USUAL,ersynt1); sfdln(); libiof();
				return (FALSE);
			}
			lexical();
			if (usc.code == FDLN) {
				erreur(USUAL,errfdln); libiof();
				return (FALSE);
			}
		}
	}
	while (usc.code != PAD);
	genfio();	/* fin de l'edition */
	lexical();	/* reste = fin de la ligne d'affectation */
	return(TRUE);
}						/* trfnprn */


static void trprnt()

/*	traduction de l'instruction PRINT
 */
{						/* trprnt */
	BYTE typ,top;
	BINAIRE vop;

	libreg = firstreg;
	lexical();
	if (usc.code != EGAL) {
		erreur(USUAL,ersynt1); sfdln(); return;
	}
	lexical();
	typ = TBIN;	/* recuperer le numero logique */
	if (!expression(&typ,&top,&vop)) {
		sfdln(); return;
	}
	geniof(top,vop);
	if (usc.code == VIG) {	/* reference a un format externe */
		lexical();
		if (usc.code == ETIQ) {	/* reference par etiquette */
			genrefmt(0,usc.v.pval,0,0);
		}
		else {
			erreur(USUAL,ersynt10); sfdln(); libiof(); return;
		}
		lexical();
	}
	if (usc.code != DPT) {	/* syntaxe ':' attendu */
		erreur(USUAL,ersynt37); sfdln();
		libiof(); return;
	}
	lexical();
	do {
		switch (usc.code) {
			case HOME:
				genhome(); lexical(); break;
			case BELL:
				genbell(); lexical(); break;
			case CLEAR:
			case PAGE:
				genclear(); lexical(); break;
			case TAB:
				if (!trddir(1)) libiof();
				break;
			case TABV:
				if (!trudir(1)) libiof();
				break;
			case ATB:
				if (!trudir(2)) libiof();
				break;
			case PAINT:
				if (!trddir(2)) libiof();
				break;
			case PAG:
				if (!trfmt()) libiof();
				break;
			case CSTR:
				/* Si cste chaine est suivie de '+' ou '!'
				   ca devient une expression */
				if (!lookexpstr()) {
					geniprn(usc.v.pval);
					lexical();
					break;
				}
			default: /* doit etre une expression */
				typ = T_ANY;
				if (!expression(&typ,&top,&vop)) {
				   	sfdln(); libiof(); return;
				}
				genprn(top,vop); break;
		}
		if (usc.code != FDLN) {
			if (usc.code != VIG) {
				erreur(USUAL,ersynt1); sfdln(); libiof();
				return;
			}
			lexical();
			if (usc.code == FDLN) {
				erreur(USUAL,errfdln); libiof();
				return;
			}
		}
	}
	while (usc.code != FDLN);
	genfio();	/* fin de l'edition */
}						/* trprnt */


static void trask()

/*	traduction de l'instruction ASK
 */
{						/* trask */
	BYTE	typ,top,*pdesc;
	BINAIRE vop;
	BOOL	saisvar = FALSE, saisie = FALSE;

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\ntrask():debut");
#endif /* ATR_DEBUG */

	libreg = firstreg;
	lexical();
	if (usc.code != EGAL) {
		erreur(USUAL,ersynt1); sfdln(); return;
	}
	lexical();
	typ = TBIN;	/* recuperer le numero logique */
	if (!expression(&typ,&top,&vop)) {
		sfdln(); return;
	}
	geniof(top,vop);
	while (usc.code == VIG) {	/* table de debranchements */
		if (!askbranch()) {
			libiof(); sfdln(); return;
		}
	}
	if (usc.code != DPT) {	/* syntaxe ':' attendu */
		erreur(USUAL,ersynt37); sfdln(); return;
	}
	lexical();
	if (usc.code == EGAL) { /* saisie immediatement */
		saisie = TRUE; lexical();
	}
	do {
		switch (usc.code) {
			case HOME:
				genhome(); lexical(); break;
			case BELL:
				genbell(); lexical(); break;
			case CLEAR:
			case PAGE:
				genclear(); lexical(); break;
			case TAB:
				if (!trddir(1)) libiof();
				break;
			case TABV:
				if (!trudir(1)) libiof();
				break;
			case ATB:
				if (!trudir(2)) libiof();
				break;
			case PAINT:
				if (!trddir(2)) libiof();
				break;
			case PAG:
				if (!trfmt()) libiof();
				break;
			case CSTR:
				/* Si cste chaine est suivie de '+' ou '!'
				   ca devient une expression */
				if (!lookexpstr()) {
					geniprn(usc.v.pval);
					lexical();
					break;
				}
			default:
				if (!saisie) {
					/* doit etre une expression */
					typ = T_ANY;
					if (!expression(&typ,&top,&vop)) {
					   	sfdln(); libiof(); return;
					}
					genprn(top,vop);
				}
				else { /* doit etre la variable a saisir */
				   saisvar = TRUE;
				   if (!reference(0,&pdesc,&vop,&top,&typ)) {
				   	sfdln(); libiof(); return;
				   }
				   genask(top,vop);
				   lexical();
				   if (usc.code != FDLN) {
					erreur(USUAL,errfdln); libiof();
					sfdln();
				   }
				}
				break;
		}
		if (usc.code != FDLN) {
			if (usc.code != VIG) {
			   if (usc.code != EGAL) {
				erreur(USUAL,ersynt1); sfdln(); libiof();
				return;
			   }
			   else
				saisie = TRUE;
			}
			lexical();
		}

	}
	while (usc.code != FDLN);
	if (saisvar)
		genfio();	/* fin du ASK */
	else {
		erreur(USUAL,errfdln); libiof();
	}
#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\ntrask():fin");
#endif /* ATR_DEBUG */
}						/* trask */


static BOOL trddir(sel)

/*	traduction d'une directive avec deux arguments dans un ASK ou un PRINT
 *	en entree, sel = 1 pour TAB, 2 pour PAINT
 */
int sel;
{					/* trddir */
	BYTE typ,top,top1;
	BINAIRE vop,vop1;

	lexical(); 
	if (usc.code != PAG) {
		erreur(USUAL,ersynt19); sfdln();
		return (FALSE);
	}
	typ = TBIN; lexical();
	if (!expression(&typ,&top,&vop)) {
		sfdln(); return (FALSE);
	}
	if (sel == 1) {
		top1 = top; vop1 = vop;
	}
	else /* sel == 2 */
		genfor(top,vop);
	if (usc.code == VIG) {
		lexical(); typ = TBIN;
		if (!expression(&typ,&top,&vop)) {
		   	sfdln(); return (FALSE);
		}
		if (sel == 1) {
			genltab(top,vop); genctab(top1,vop1);
		}
		else /* sel == 2 */
			genbak(top,vop);
	}
	else if (sel == 1)
			genctab(top1,vop1);
	if (usc.code != PAD) {
		erreur(USUAL,ersynt20); sfdln(); return (FALSE);
	}
	lexical(); return (TRUE);
}					/* trddir */


static BOOL trudir(sel)

/*	traduction d'une directive avec un argument dans un ASK ou un PRINT
 *	en entree, sel = 1 pour TABV, 2 pour ATB
 */
int sel;
{					/* trudir */
	BYTE typ,top;
	BINAIRE vop;

	lexical(); 
	if (usc.code != PAG) {
		erreur(USUAL,ersynt19); sfdln(); return (FALSE);
	}
	typ = TBIN; lexical();
	if (!expression(&typ,&top,&vop)) {
		sfdln(); return (FALSE);
	}
	if (sel == 1)
		genvtab(top,vop);
	else /* sel == 2 */
		genatb(top,vop);
	if (usc.code != PAD) {
		erreur(USUAL,ersynt20); sfdln(); return (FALSE);
	}
	lexical(); return (TRUE);
}					/* trudir */


static BOOL askbranch()

/*	traduction d'un debranchement sur un ASK
 */
{					/* askbranch */
	char	c;
	BYTE	typ,top,*pdesc;
	BINAIRE reg,vop;
	BOOL	flg, flg_E = FALSE;

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\naskbranch():debut");
#endif /* ATR_DEBUG */

	lexical();
	switch (usc.code) {
	  case PAG:	/* variable ou constante chaine attendue */
		lexical();
		if (usc.code == IDENT) {
		    typ = findcst(usc.v.pval,&pdesc,&vop);
		    if (typ == 0) {	/* doit etre une variable */
			reg = getreg();
			if (!reference(reg,&pdesc,&vop,&top,&typ)) {
			   	sfdln(); return (FALSE);
			}
			if ((! IS_TSTR(typ)) && (! IS_TBIN(typ))) {
				erreur(USUAL,ersynt38);
				sfdln(); return (FALSE);
			}
			if (top != 3) { /* pas besoin de registre */
				ungetreg();
			}
			else  {
				top = 3; vop = reg;
			}
		    }
		    else if ((typ == 2) && (*pdesc != 0)) {
			top = 1;
		    }
		    else {
			erreur(USUAL,ersynt1); sfdln(); return (FALSE);
		    }
		}
		else if (usc.code == CSTR) {
			top = 1; vop = newstr(usc.v.pval);
		}
		else {
			erreur(USUAL,ersynt1); sfdln(); return (FALSE);
		}
		lexical();
		if (usc.code != PAD) {
			erreur(USUAL,ersynt20); sfdln(); return (FALSE);
		}
		break;

	  case CSTR:	/* chaine */
		top = 1; vop = newstr(usc.v.pval); break;

	  case CBIN:	/* valeur de touche */
		top = 0; vop = usc.v.val; break;

	  case IDENT:	/* caractere special ? */
			/* On autorise les constantes de plus de un
			 * caracteres comme valeur de debranchement
			 */
		if (Xstrlen(usc.v.pval) != 1) {
			top = findcst(usc.v.pval,&pdesc,&vop);
			switch(top) {
				/* Constante non trouvee */
				case 0 : erreur(USUAL,ersynt42);
					 sfdln();
					 return(FALSE);

				/* Constante binaire */
				case 1 : top = 0;
					 break;

				/* Constante chaine ou BCD */
				case 2 : if (*pdesc == 0) {
						/* Refuse constante BCD */
						erreur(USUAL,ersynt1);
						sfdln();
						return(FALSE);
					 }
					 top = 1;
					 break;
			}
		}
		else {
			c = *usc.v.pval; top = 100;
			switch (c) {
				case 'X': top++; /* 05/05/94 */
				case 'T': top++;
				case 'E': top++;
				case 'D': top++;
				case 'U': top++;
				case 'L': top++;
				case 'I': break;
				default : erreur(USUAL,ersynt1);
					  sfdln();
					  return (FALSE);
			}
		}
		break;

	  default :
		erreur(USUAL,ersynt1); sfdln(); return (FALSE);
	}
	lexical();
	if (usc.code != EGAL) {
		erreur(USUAL,ersynt1); sfdln(); return (FALSE);
	}
	lexical();
	if (usc.code == NEXT) {
		flg = FALSE; cretiq(usc.v.pval);
	}
	else if (usc.code == BREAK) {
                if (!flg_itere) {
		/* pas d'iteration en cours */
			erreur(USUAL,ersynt45); sfdln(); return (FALSE);
                } else {
			if (*fin_itere == EOSTR) {
                        	cretiq(fin_itere);
                        }
			Xstrcpy(usc.v.pval,fin_itere);
                }
		flg = FALSE;
	}
	else if (usc.code != ETIQ) {
		if ((usc.code != PAG) || (flg_E)) {
			erreur(USUAL,ersynt10); sfdln(); return(FALSE);
		}
		lexical();
		if (usc.code == NEXT) {
			cretiq(usc.v.pval);
		}
		else if (usc.code == BREAK) {
                	if (!flg_itere) {
			/* pas d'iteration en cours */
				erreur(USUAL,ersynt45); sfdln(); return (FALSE);
                	} else {
				if (*fin_itere == EOSTR) {
                        		cretiq(fin_itere);
                        	}
				Xstrcpy(usc.v.pval,fin_itere);
                	}
		}
		else if (usc.code != ETIQ) {
			erreur(USUAL,ersynt10); sfdln(); return(FALSE);
		}
		flg = TRUE;
	}
	else
		flg = FALSE;
	genbranch(flg,top,vop,usc.v.pval);
	if (flg) {
		lexical();
		if (usc.code != PAD) {
			erreur(USUAL,ersynt20); sfdln(); return(FALSE);
		}
	}
	lexical();
#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\naskbranch():fin");
#endif /* ATR_DEBUG */
	return (TRUE);
}					/* askbranch */


static BOOL trfmt()

/*	traitement/decodage d'un format de saisie ou d'edition
 *	ecrit en direct dans un ASK ou dans un PRINT
 */
{					/* trfmt */
	BYTE typ,top,*pdesc;
	BINAIRE vop,reg;


	fmt_verrue = TRUE;
	lexical();
	fmt_verrue = FALSE;

	if (usc.code == PAG) { /* reference par une variable */
		lexical();
/*
		reg = getreg();
		typ=T_ANY;
		if (!expression(&typ,&top,&vop)) {
			sfdln(); return (FALSE);
		}
		if (top == 4) {
			top = 3; vop = nrgvar; 
		}
*/
		reg = getreg();
		if (!reference(reg,&pdesc,&vop,&top,&typ)) {
			sfdln(); return (FALSE);
		}
		if (top == 4) {
			top = 3; vop = nrgvar; /* variable "registre" */
		}
		genrefmt(1,GenericNULL(char),top,vop);
		lexical();
		if (usc.code != PAD) {
			erreur(USUAL,ersynt20); sfdln(); return (FALSE);
		}
	}
	else if (usc.code != CSTR) { /* erreur : format incorrect */
		erreur(USUAL,ersynt39); sfdln(); return (FALSE);
	     }
	     else
		genfmt(0,usc.v.pval);
	lexical();
	if (usc.code != PAD) {
		erreur(USUAL,ersynt20); sfdln(); return (FALSE);
	}
	lexical(); return (TRUE);
}					/* trfmt */


static void tradfmt()

/*	traduction de la directive FMT
 */
{					/* tradfmt */
	

	lexical();
	if (usc.code != PAG) {
		erreur(USUAL,ersynt19); sfdln(); return;
	}
	fmt_verrue = TRUE;
	lexical();
	fmt_verrue = FALSE;
	if (usc.code != CSTR) { /* erreur : format incorrect */
		erreur(USUAL,ersynt39); sfdln(); return;
	}
	genfmt(1,usc.v.pval);
	lexical();
	if (usc.code != PAD) {
		erreur(USUAL,ersynt20); sfdln(); return;
	}
	tfdln();
}					/* tradfmt */


/*	-------------------------------------------	*/
/*	traitement des DATAs et de leur utilisation	*/
/*	-------------------------------------------	*/

static void trread()

/*	traitement de l'instruction 'READMEM'
 */
{					/* trread */
	BYTE *adesc,tvar,typ;
	BINAIRE advar;

	lexical();
	if (usc.code != DPT) {	/* syntaxe ':' attendu */
		erreur(USUAL,ersynt37); sfdln(); return;
	}
	lexical();
	do {
		libreg = firstreg;
		if (!reference(0,&adesc,&advar,&tvar,&typ)) {
			sfdln(); return;
		}
		if (tvar == 4)
			tvar = 3;	/* remettre 'registre' */
		genreadmem(tvar,advar);
		lexical();
		if (usc.code != FDLN) {
		   if (usc.code != VIG) {
			erreur(USUAL,ersynt21); sfdln(); return;
		   }
		   else {
			lexical();
			if (usc.code == FDLN) {
				erreur(USUAL,errfdln); sfdln(); return;
			}
		   }
		}
	}
	while (usc.code != FDLN);
}					/* trread */


static BOOL isdata(seg)

/*	traitement d'une directive DATA, en entree 'seg' est vrai pour
 *	le cas d'un segment, et faux pour le cas d'une procedure
 */
BOOL seg;
{					/* isdata */
	BOOL	flag = TRUE, sgn;

	if (usc.code == DATA) {
	   cstbcd_verrue = TRUE;
	   do {
		lexical(); sgn = FALSE;
		if (usc.code == PLUS)
			lexical();
		else if (usc.code == MOINS) {
			lexical(); sgn = TRUE;
		}
		switch (usc.code) {
		  case CSTR:
		     if (sgn) {
			erreur(USUAL,ersynt38); sfdln(); return (TRUE);
		     }
		     gendata(1,usc.v.pval,GenericNULL(BYTE));
		     nbre_datas++; break;
		  case CBCD:
		     if (sgn) {
			*(usc.v.pbcd + 1) &= (BYTE) 0x000F;
			*(usc.v.pbcd + 1) |= (BYTE) BCD_MOINS;
		     }
		     gendata(2,GenericNULL(char),usc.v.pbcd);
		     nbre_datas++; break;
		  default:
		     erreur(USUAL,ersynt42); sfdln(); return (TRUE);
		}
		lexical();
	   }
	   while (usc.code == VIG);
	   cstbcd_verrue = FALSE;
	   if (usc.code != FDLN) {
		erreur(USUAL,errfdln); sfdln();
	   }
	   if (adrimpl >= MXSEG) {	/* debordement */
		erreur(USUAL,ersynt11); adrimpl = 0L;
	   }
	}
	else {
	   switch (usc.code) {
	     case ESEG:		/* fin de segment */
		if (seg) flag = FALSE;
		else {
			erreur(USUAL,ersynt8); sfdln();
		}
		break;
	     case ENDPROC:	/* fin de procedure */
		if (!seg) flag = FALSE;
		else {
			erreur(USUAL,ersynt9); sfdln();
		}
		break;
	     default:
		erreur(USUAL,ersynt41); sfdln();
	   }
	}
	return (flag);
}					/* isdata */

