#ifndef	_editeur_c
#define	_editeur_c

	/* 	l'editeur est une fonction de l'ensemble integre 	*/

int editeur(fic,optrace,lgtab)
char	*fic;
BOOL	optrace;
SWORD	lgtab;
{					/* editeur */
	BOOL	flg_ext = FALSE;
	ChnFic	*p,*q;
	BYTE 	buf[10];


	if (Xsetjmp(Ed_Exit) != 0) {
#ifdef unix
		PurgeLox();
#endif
		return (-1);
		}
	else	UseEdExit=1;
	initabmes();

#ifdef vms
	/* Jeux de caractere prologue */
	if (getenv("PROLOGUE") != GenericNULL(char) ) {
		TRAIT =	(BYTE) 0x00C4;	/* ligne horizontale */
		}
#endif

	/*	initialiser les extentions */

	nballoc = 0;

	/* prevoir les erreurs en cours d'intialisation */
	LGERR = 5; COLERR = 1;
	/* pas de tampon */
#ifdef	ver2Kalloc
	mem = lgntemp = (BYTE *) 0;
#endif
	tampon = GenericNULL(MemTemp);
	/* fichiers non encore initialises */
	fs = fdest = fret = GenericNULL(TFILE);
	ftrace = GenericNULL(FILE);
	/* pas de chainage */
	deb_chnfic = GenericNULL(ChnFic);
	flg_cico = TRUE; /* ecran deja initialise */
	flg_def_dest = FALSE;
	/* initialisation generale a partir des arguments */
	APU = 2; lg_tabul = lgtab;

	if (optrace) {	/* demande du mode trace */
		if (!initrace(fic)) 
			return (FALSE);
		Xstrcpy(firstedit, nomtrace);
		}		

	else 	{
		traceon = FALSE;	/* pas de mode trace */
		/* construire le nom du fichier a editer */
		flg_ext = getnomfic(fic,nomsrce,EXTS);
		}

	/* initialiser l'ecran */
	initecran(); 
	/* initialiser la gestion des fichiers */
	init_fic(TRUE,flg_ext);
	/* initialiser le contenu de la memoire */
	initmem();
	/* passer en mode video */
	video();

	/* liberation de la memoire */

	if (fs != GenericNULL(TFILE)) {
		liberate(fs);
		}
	if (fret != GenericNULL(TFILE)) {
		liberate(fret);
		}
	if (fdest != GenericNULL(TFILE)) {
		liberate(fdest);
		}	

	p = deb_chnfic;
	while (p != GenericNULL(ChnFic)) {
		q = p->suiv; liberate(p); p = q;
		}

	libtampon();

	/* retour a l'appelant */
#ifdef unix
	PurgeLox();
#endif
	x_clear(); 
	
	return (0);
}		

#endif	/* _editeur_c */
	/* ---------- */

