/*---------------------------------------------------------------EDNOY.C -----
 *
 *	Editeur de textes ABAL	  -	Copyright Amenesik / Sologic s.a. (c) 1989, 1996
 *
 *		   	      Noyau
 *
 * Corrections :
 *	20/09/95 : 2.1c/Unix : reactive la creation des fichiers .bak
 *	05/01/96 : fusion avec DOS/Amenesik / Sologic
 * 13/10/97 : Gestion de plus de 65000 lignes (YT131097)
 * 23/02/98 :	On ajoute un ^Z a la fin du fichier s'il n'y en a pas deja 
 *					un. Ceci est utile quand on supprime le ^Z dans un autre 
 *					editeur (Notepad par exemple) et qu'on reedite le fichier 
 *					dans AED. La modif n'est faite que sous DOS.
 *
 *
 *--------------------------------------------------------------------------*/

#include "ed.h"
#include "edmsg.h"
#include "ednoy.h"

BPTR	Mstrcpy(char *, const char *);
public	void	horizontal_rule( int atlin, int atcol, int nbcol );
public	void	editorOnTrace();
public	void	window_messages();
void	draw_editor_scrollbar();
static	void	draw_editor_screen();
	WORD	screen_characteristics(int mode);
static	void	xcopy( char * sn, char * rn );
BOOL	confirme_lose();
BOOL	confirme_save();


int	env_mouse;
int	dragfactor=0;
int	bell_control=1;

unsigned long maxnumlgn=0L;	/* nombre totale de lignes */

LONG arglig;

int	UseEdMain=0;
int	UseEdExit=0;
jmp_buf Ed_Exit;

int argcol;
FILE XPTR fhzoom;
BOOL EXTEND_AED;

		/*---------------------------------------*/



#ifdef	ver2Kalloc


#ifndef	UNIX
static	char	*	fontz="is\\fonts\\aed0.fmf";
static	char	*	fontn="is\\fonts\\aedn.fmf";
#endif

void	editor_bell()
{
	if ( bell_control )
		x_bell();
	return;
}

int	set_editor_bell( int v )
{
	int	h = bell_control;
	bell_control = v;
	return( h );
}


VOID fin2000()
{
	if ( curerr != GenericNULL(BYTE) ) {
		liberate( curerr );
		curerr = 0;
		}
	if ( lgntemp != GenericNULL(BYTE) ) {
		liberate(lgntemp);
		lgntemp = 0;
		}
	if ( AedMemory != GenericNULL(BYTE) ) {
		liberate(AedMemory);
		AedMemory = 0;
		}
	return;
}
#endif

#include "edsing.c"
#include "edtabmes.c"

#ifdef	VERSION666
#include "edwindow.c"
#endif

static BOOL initgene (SWORD argc, BYTE XPTR argv[])

/*	initialisation generale
 */
{					/* initgene */
#ifdef	WIN32_QUOTE_BUG_FIX
	BYTE	*w;
#endif
	BYTE	*p,c;
	SWORD 	j;
	BOOL	flg_ext = FALSE;
	SWORD	nb;

	traceon = FALSE;	/* pas de mode trace a priori */

	/* pas de tampon */
#ifdef	ver2Kalloc
	AedMemory = lgntemp = (BYTE *) 0;
#endif
	tampon = GenericNULL(MemTemp);

	/* init des extentions */

#ifdef msdos 
	Xstrcpy(EXTS,(BYTE XPTR) "s");
	Xstrcpy(EXTE,(BYTE XPTR) "err");
	Xstrcpy(EXTSAV,(BYTE XPTR) "bak");
#endif
#ifdef unix
	Xstrcpy(EXTS,"s");
	Xstrcpy(EXTE,"err");
	Xstrcpy(EXTSAV,"bak");
#endif
#ifdef prologue
	Xstrcpy(EXTS,"S");
	Xstrcpy(EXTE,"E");
	Xstrcpy(EXTSAV,"A");
#endif
#ifdef vms
	Xstrcpy(EXTS,"S");
	Xstrcpy(EXTE,"ERR");
	Xstrcpy(EXTSAV,"BAK");
#endif


#ifndef integre
	tete  = FNIL;
	boolcor = 0;
	deblgn = 0;
	finlgn = 0;
#endif
#ifdef ver21
	boolbest = 0;
	flg_insert = TRUE;
	flg_indent = FALSE;
	flg_affnbln = FALSE;
#endif
	/* fichiers non encore initialises */
	fs = fdest = fret = GenericNULL(TFILE);
	ftrace = GenericNULL(FILE);
	/* pas de chainage */
	deb_chnfic = GenericNULL(ChnFic);
	
	ligarg[0] = EOSTR;
	nomargu[0] = EOSTR;

	vcomed[0] = 0;

	lg_tabul = 8;		/* longueur tabulation */
	initecran(); 		/* avant les fichiers a cause de Access */

	p = (BYTE XPTR) *(++argv);
	arglig = 0;
	argcol = 0;	
#ifdef ver14
	if ((*p == DELIMOPT) && ((char) toupper(*(p+1)) == (char) 'F')) {
		/* la ligne de commande se trouve dans un fichier */
		if (!init_arg((BYTE *) p+2)) return (FALSE);
		}
	else	{
#endif
		ligarg[0] = EOSTR;
#ifdef	WIN32_QUOTE_BUG_FIX
		w = ligarg;
#endif
		while (argc--) {
			if (Xstrlen((BYTE XPTR) (&ligarg[0]) + Xstrlen(p)) >= 254) {
				Xerreur(FATALE,errcom);
				}
			else	{
#ifdef	WIN32_QUOTE_BUG_FIX
				sprintf(w," %c%s%c",0x0022,p,0x0022); w += Xtrlen( w );
#else
	 			Xstrcat(&ligarg[0]," "); 
				Xstrcat(&ligarg[0],p);
#endif
				p = (BYTE XPTR) *(++argv);
				}
			}
#ifdef ver14
		}
#endif
	p = &ligarg[0];	/* p pointe sur la ligne d'argument */
	nextindice = &ligarg[0];	/* pointe sur le premier element */
	NextOpt(&p);

#ifdef ver14
#ifdef unix
	if (*p == '-') {
#else
	if (*p == '-' || *p == '/') {
#endif
		if ((BYTE) toupper(*(p+1))  == (BYTE) 'C') {
			if (!(BOOL) (lecconf(p+2))) {
				Xerreur(FATALE,errcfg);
				}
			NextOpt(&p);
			}
			
		}
#endif
#ifdef unix
	if (*p == '-') {
#else
	if ((*p == '-' ) || (*p == '/')) {	/* pas une edition "classique" */
#endif
		p++; c = (BYTE) toupper(*p); p++;
		if (c == 'T') {	/* passer en mode trace */

			if (!initrace(p))
#ifndef ver14
				return (FALSE);
#else
				{
				/* on continue d'editer meme sans erreur */
				if (*p != EOSTR) flg_ext = getnomfic(p,nomsrce,EXTS);
				Xstrcpy(firstedit, nomsrce);
				}
			else 
#endif
			Xstrcpy(firstedit, p); /* ex nomtrace */
			}
		else if (c == 'C') {	/* passer en mode configuration */
			Xerreur(FATALE,errcom);
			}
		else	{	/* commande erronee */
#if prologue || unix
			/* le / peut etre un nom de fichier */
			flg_ext = getnomfic(p-2, nomsrce,EXTS);
#else
			Xerreur(FATALE,errcom);
#endif
			}
		}
	else	{
		/* construire le nom du fichier a editer */
		if (*p != EOSTR) {
			flg_ext = getnomfic(p,nomsrce,EXTS);
			}
		}
	/* valeurs par defaut des options eventuelles */
	flg_def_dest = FALSE;
	APU = 2;	/* attribut preferentiel utilisateur */
	BOOLBAK = 0;	/* Bool si pas de .bak */
	SAVE_NOBAK = FALSE;
	txtcons    = FALSE;
	/* traiter les eventuelles options complementaires */

	while (*p != ' ' && *p != EOSTR) p++; /* au suivant */

	while (NextOpt(&p)) {
#ifdef unix
		if (*p == '-') {
#else
		if (*p == '-' || *p == '/') {
#endif
			p++;
			c = (BYTE) toupper(*p); 
			p++;
			switch (c) {
#ifdef ver14
				case 'R':
					if (*p != EOSTR && *p != ' ')
						Xerreur(FATALE,errcom);
					txtcons = TRUE;
					BOOLBAK = 1;
					break;
#endif
				case 'D':
					if (traceon)
						Xerreur(FATALE,errcom);
					getnomfic(p,nomdef,EXTS);
					flg_def_dest = TRUE;
					while (*p != EOSTR && *p != ' ') p++;
					break;
				case 'X':	/* tabulation speciale */
					nb = (SWORD) (cartoint(*p)); p++;
					if (*p != EOSTR && *p != ' ')
						Xerreur(FATALE,errcom);
					if (((nb % 2) != 0) || (nb == 0))
						Xerreur(FATALE,errcom);
					lg_tabul = nb;
					break;
				case 'U':	/* pas d'inversion video */
					if (*p != EOSTR && *p != ' ')
						Xerreur(FATALE,errcom);
					APU = 1; break;

#ifdef	VERSION666
				case 'W': 
					if (!( nb = editor_window_connection(p) ))
						break;
					else	Xerreur(FATALE,errcom);
#endif
				case 'L':
					arglig = atol(p);
					break;

				case 'C':
					argcol = atoi(p);
					break;
#ifdef ver14
				case 'B' : 	/* pas de .bak */
					if (*p != EOSTR && *p != ' ')
						Xerreur(FATALE,errcom);
					BOOLBAK = 1;
					break;
#endif
#ifdef	ver2Kalloc
				case 'N' : /* font name  */
				case 'M' : /* Biso mode  */
					break;
#endif
				case '+' : /* extend AED */
					EXTEND_AED = TRUE;
					break;
				default:
					Xerreur(FATALE,errcom);
				}
			}
		else	{
			Xerreur(FATALE,errcom);
			}
		}
		
	if (traceon) {
		x_bstart();
		LGINIT = 5;
		NBLIG = (SWORD) ((MXLIG+1) - LGINIT);
		ligne = LGINIT;
		pos( 3, 1); Xatb(APU); x_putch(' '); 
		x_cprintf((BYTE FPTR)curerr);
		horizontal_rule(4,1,MXCOL);
		Xatb(0);
		x_bflush();
		}

	init_fic(TRUE,flg_ext);

	return (TRUE);
}					/* initgene */
 

void	showfilename()
{
	SWORD	j;
	BYTE	nomfic[LGMXNOM];
	/* Affichage du nom de fichier */
	Xatb(0); pos(1,1); Xatb(21);
	x_cprintf((BYTE FPTR)edit_msg[msgfic]);
  	designation(nomfic);
	show_filename( nomfic );
	horizontal_rule(2,1,MXCOL);
	return;
}


#ifdef ver14
void init_fic ( first, flg_ext)
BOOL first;
BOOL flg_ext;
/*	initialisation en vue des acces aux fichiers 	 */
{					/* init_fic */

#ifdef unix
	struct stat buf;
#endif
#ifdef prologue
	SWORD gdd;
	BYTE buffer[256];
#endif
	SWORD i;
	BYTE	nomfic[LGMXNOM];
#ifdef vms
	BYTE nomtmp[LGMXNOM];
#endif

	BYTE inc;

	inc = 0;	/* numero d'ordre pour les noms de fichier */

	txtchg = FALSE; /* Bool a TRUE des que le source est modifie */


	/* fichier destination = meme nom que source avec extension DEST */
	if (BOOLBAK) {
		Xfn_parser((BYTE FPTR) nomsrce, (BYTE FPTR) nomdest,8);
		makenom(nomdest,inc);	/* generateur de nom alleatoire */
		}
	else	{
		Xfn_parser((BYTE FPTR) nomsrce, (BYTE FPTR) nomdest, 1 + 2 + 4 + 8);

		nomdest[Xstrlen( nomdest ) + 1] = EOSTR;
		nomdest[Xstrlen( nomdest )] = SEPTYP;
		Xstrcat(nomdest,EXTDEST);
#ifdef prologue
/*
		Xfn_parser((BYTE FPTR) nomsrce, (BYTE FPTR) &nomdest[Xstrlen(nomdest)], 32); 
*/
#endif
		}
	/* fichier retour = meme nom que source avec extension RET */
	if (BOOLBAK) {
		Xfn_parser((BYTE FPTR) nomsrce, (BYTE FPTR) nomret,8);
		makenom(nomret,inc);
			
		while (Xstrcmp(nomret,nomdest) == 0) { /* test si nom identique */
			inc++;
			makenom(nomret, inc);
			}
		}
	else	{
		Xfn_parser((BYTE FPTR) nomsrce, (BYTE FPTR) nomret, 1+2+4+8);
		nomret[Xstrlen( nomret ) + 1] = EOSTR;
		nomret[Xstrlen( nomret )] = SEPTYP;
		Xstrcat(nomret,EXTRET);
		}

	/* fichier sauvegarde = meme nom que source avec extension SAV */
	if (!BOOLBAK) {
		Xfn_parser((BYTE FPTR) nomsrce, (BYTE FPTR) nombak, 1+2+4+8);
		nombak[Xstrlen( nombak ) + 1] = EOSTR;
		nombak[Xstrlen( nombak )] = SEPTYP;
		Xstrcat(nombak,EXTSAV);
		}

	if (first) {
		/* creer les descripteurs des fichiers */
		fs = (TFILE *) allocate(sizeof(TFILE));
		if (fs == GenericNULL(TFILE)) {
				Xerreur(FATALE,ernoy03);
			}
		fdest = (TFILE *) allocate(sizeof(TFILE));
		if (fdest == GenericNULL(TFILE)) {
			Xerreur(FATALE,ernoy03);
			}
		fret = (TFILE *) allocate(sizeof(TFILE));
		if (fret == GenericNULL(TFILE)) {
			Xerreur(FATALE,ernoy03);
			}
		}
	fs->nl = fdest->nl = fret->nl = EOF;

	/* creation du fichier retour  En premier car il sert de semaphore */
	fret->nl = Xcreat(nomret);
	if (fret->nl == EOF) {
		Xerreur(FATALE,ernoy02);
		}

	/* ouverture / controle du programme original -> fsrce */
	errno = 0;
#ifdef unix 

	if ( BOOLBAK ) {
		i = Xaccess(nomsrce,0);
		}
	else	{
		i = Xaccess(nomsrce,1);
		}

	if ((i != 0) && (errno != ENOENT)) { Xerreur(FATALE, ernoy00); }
	
#else
	i = (SWORD) (Xaccess(nomsrce, 0));
#endif
	if (i == 0) {
#ifdef vms
		fs->nl = XRDopen(nomsrce);
#else
		if ( BOOLBAK )
			fs->nl = XRDopen(nomsrce);
		else	fs->nl = Xopen(nomsrce);
#endif
		if (fs->nl == EOF)   
			Xerreur(FATALE, ernoy01);
		fs->Feof = FALSE; flgcreat = FALSE;
		}
	else	{  /* source n'existe pas  */
#ifdef unix
		liberlox(nomsrce);
#endif
		if (BOOLBAK) {
			Xerreur(FATALE,ernoy00);
			}

		if (flg_ext) { /* voir si on a ajoute l'extension par defaut */
#ifndef ver14
#ifndef vms
		       *(Xstrrchr(nomsrce,SEPTYP)) = EOSTR;
#else
		       *(Xstrrchr(nomsrce,SEPTYP) + 1) = EOSTR; 	
#endif
#else
			Xfn_parser((BYTE FPTR) nomsrce,(BYTE FPTR) nomfic, 1+2+4+8+32);
#ifdef vms
			nomtmp[0] = EOSTR;
			Xfn_parser((BYTE FPTR) nomfic, (BYTE FPTR) nomtmp, 16+32);
			if (! nomtmp[0]) {
				/* extention vide , on force le point */
				Xstrcat(nomfic,".");
				}
#endif


			Xstrcpy(nomsrce, nomfic);
#endif
#ifdef unix
			i = Xaccess(nomsrce,1);
			if (i != 0 && errno != ENOENT) Xerreur(FATALE, ernoy00);
#else
			i = (SWORD) (Xaccess(nomsrce, 0));
#endif
			if (i == 0) {

#ifdef vms
				fs->nl = XRDopen(nomsrce);
#else
				fs->nl = Xopen(nomsrce);
#endif
				if (fs->nl == EOF)   
					Xerreur(FATALE, ernoy01);
				fs->Feof = FALSE; flgcreat = FALSE;
				}

			else	{
				fs->nl = (SWORD) (Topen(nomsrce));
				if (fs->nl == EOF)
					Xerreur(FATALE,ernoy01);
				Xclose(fs->nl);Xunlink(nomsrce);
				fs->Feof = TRUE; flgcreat = TRUE;
				}
		   	}
		   else {
			fs->nl = (SWORD) (Topen(nomsrce));
			if (fs->nl == EOF)
				Xerreur(FATALE,ernoy01);
			Xclose(fs->nl); Xunlink(nomsrce);
			fs->Feof = TRUE; flgcreat = TRUE;
		   	}
		}
#ifdef unix
	/* Recuperation des droits d'accces du source */

	if (stat(nomsrce,&buf) != 0) 
		fdest->nl = Xcreat(nomdest); /* New fichier */
	else
		fdest->nl = Xcreat_mode(nomdest);
#else
	fdest->nl = Xcreat(nomdest);
#endif
	if (fdest->nl == EOF) {
		Xerreur(FATALE,ernoy02);
		}


	fs->pbuf = fs->fbuf = &fs->buf[0];

 	fdest->pbuf = &fdest->buf[0]; 
	fdest->Feof = TRUE; 
	fdest->curofst = 0L;
	fret->pbuf = &fret->buf[0]; fret->Feof = TRUE; fret->curofst = 0L;
	fs->nblgn = fdest->nblgn = fret->nblgn = 0;
#ifdef prologue
	fs->curofst = 0L;
	/* recuperer la longeur exacte si elle existe */

	gdd = ngffh((SWORD) fs->nl);

	Xgetdd( gdd, &_ngf_dd[0]);

	nsect = _ngf_dd[6];
	nsect = (nsect << 8) | _ngf_dd[5];

	lgexacte = (long int) nsect * LGBLOC + (long int) _ngf_dd[4];
#endif
	/* Affichage du nom de fichier */

	designation(nomfic);
	set_filename_buffer(nomfic);
	determine_syntax_control( nomfic );
}					/* init_fic */
#else

void init_fic ( first, flg_ext)
BOOL first;
BOOL flg_ext;

/*	initialisation en vue des acces aux fichiers 	*/
{					/* init_fic */

#ifdef unix
	struct stat buf;
#endif
	SWORD i;
	BYTE	nomfic[LGMXNOM];
	BYTE s[LGMXNOM];

	/* fichier destination = meme nom que source avec extension DEST */
	Xstrcpy(nomdest,nomsrce);
	*(Xstrrchr(nomdest,SEPTYP)+1) = EOSTR;
	Xstrcat(nomdest,EXTDEST);
	/* fichier retour = meme nom que source avec extension RET */
	Xstrcpy(nomret,nomsrce);
	*(Xstrrchr(nomret,SEPTYP)+1) = EOSTR;
	Xstrcat(nomret,EXTRET);
	/* fichier sauvegarde = meme nom que source avec extension SAV */
	Xstrcpy(nombak,nomsrce);
	*(Xstrrchr(nombak,SEPTYP)+1) = EOSTR;
	Xstrcat(nombak,EXTSAV);
	if (first) {
		/* creer les descripteurs des fichiers */
		fs = (TFILE *) allocate(sizeof(TFILE));
		if (fs == GenericNULL(TFILE))
				Xerreur(FATALE,ernoy03);
		fdest = (TFILE *) allocate(sizeof(TFILE));
		if (fdest == GenericNULL(TFILE))
			Xerreur(FATALE,ernoy03);
		fret = (TFILE *) allocate(sizeof(TFILE));
		if (fret == GenericNULL(TFILE))
			Xerreur(FATALE,ernoy03);
		}	

	fs->nl = fdest->nl = fret->nl = EOF;

	/* creation du fichier retour  En premier car il sert de semaphore */
	fret->nl = Xcreat(nomret);
	if (fret->nl == EOF) 
		{
		Xerreur(FATALE,ernoy02);
		}

	/* ouverture / controle du programme original -> fsrce */
	errno = 0;
#ifdef unix 
	i = Xaccess(nomsrce,1);
	if ((i != 0) && (errno != ENOENT)) Xerreur(FATALE, ernoy00);
#else
	i = Xaccess(nomsrce, 0);
#endif
	if (i == 0) {
		fs->nl = Xopen(nomsrce);
		if (fs->nl == EOF)   
			Xerreur(FATALE, ernoy01);
		fs->Feof = FALSE; flgcreat = FALSE;
		}
	else	{  
		/* source n'existe pas  */
#ifdef unix
		liberlox(nomsrce);
#endif
		if (flg_ext) { /* voir si on a ajoute l'extension par defaut */
#ifndef vms
		       *(Xstrrchr(nomsrce,SEPTYP)) = EOSTR;
#else
		       *(Xstrrchr(nomsrce,SEPTYP) + 1) = EOSTR; 	
#endif
#ifdef unix
			i = Xaccess(nomsrce,1);
			if (i != 0 && errno != ENOENT) Xerreur(FATALE, ernoy00);
#else
			i = Xaccess(nomsrce,0);
#endif
			if (i == 0) {
				fs->nl = Xopen(nomsrce);
				if (fs->nl == EOF)   
					Xerreur(FATALE, ernoy01);
				fs->Feof = FALSE; flgcreat = FALSE;
				}
			else	{
				fs->nl = Topen(nomsrce);
				if (fs->nl == EOF)
					Xerreur(FATALE,ernoy01);
				Xclose(fs->nl);Xunlink(nomsrce);
				fs->Feof = TRUE; flgcreat = TRUE;
				}
		   	}
		   else {
			fs->nl = Topen(nomsrce);
			if (fs->nl == EOF)
				Xerreur(FATALE,ernoy01);
                        Xclose(fs->nl); Xunlink(nomsrce);
			fs->Feof = TRUE; flgcreat = TRUE;
		   	}
		}
#ifdef unix
	/* Recuperation des droits d'accces du source */

	if (stat(nomsrce,&buf) != 0) 
		fdest->nl = Xcreat(nomdest); /* New fichier */
	else
		fdest->nl = Xcreat_mode(nomdest);
#else
	fdest->nl = Xcreat(nomdest);
#endif
	if (fdest->nl == EOF) {
		Xerreur(FATALE,ernoy02);
		}

	fs->pbuf = fs->fbuf = &fs->buf[0];

	fdest->pbuf = &fdest->buf[0]; fdest->Feof = TRUE; fdest->curofst = 0L;
	fret->pbuf = &fret->buf[0]; fret->Feof = TRUE; fret->curofst = 0L;
	fs->nblgn = fdest->nblgn = fret->nblgn = 0;

}					/* init_fic */
#endif


#ifdef	ver2Kalloc
static	VOID	initcurerr()
{
	if ( curerr == GenericNULL(BYTE)) {
		curerr = (BYTE *) allocate( LGLIGNE );
		if (curerr == GenericNULL(BYTE))
			Xerreur(FATALE,ernoy03);
		}
	return;
}
#endif


static BOOL initrace (BYTE XPTR p)

/*	initialisations en vue de la gestion du mode TRACE
 *	a partir du fichier designe par la chaine 'p'
 */
{					/* initrace */

#ifndef ver14
	BYTE *r, *q;
#endif

#ifdef ver21
	TRACEPTR pt_err;
	WORD nb;
#else
	BYTE Ligne[256];
	SWORD pt;
	BYTE *tmp;
	BYTE c;
#endif

#ifdef	ver2Kalloc
	initcurerr();
#endif

#ifdef ver14
	trace_err = FALSE;

	Xfn_parser((BYTE FPTR) p, (BYTE FPTR) nomtrace,1+2+4+8);
	Xstrcat(nomtrace,".");
	Xstrcat(nomtrace, EXTE);

#else
	q = (BYTE *) Xstrrchr(p, DELIMREP);
	if (q != GenericNULL(BYTE)) {
		q++;
		}
	else	{
		q = p;
		}
	r = (BYTE *) Xstrrchr(q, SEPTYP);
	if (r != GenericNULL(BYTE)) {
		*r = EOSTR;
		}
	
	getnomfic(p,nomtrace,EXTE);

#endif

#ifndef ver21
	ftrace = (FILE XPTR) (Xfopen(nomtrace,(BYTE XPTR) "r"));
	if (ftrace == GenericNULL(FILE)) {
#ifndef ver14
		Xerreur(FATAL,ernoy04);
#else
		traceon = TRUE; err_ecart = 0;

		Xstrcpy(curerr,edit_msg[ernoy04]);
		plerr     = 1;
		clerr     = 0;

		trace_err = TRUE;
		return(FALSE);
#endif
		}
	/* 1er acces donne le nom du source a editer */
	Xfgets(&Ligne[0], 256,ftrace);
	if (Ligne[0] == EOSTR) {
#ifndef ver14
		Xerreur(FATAL,ernoy05);
#else
		traceon = TRUE; err_ecart = 0;

		Xstrcpy(curerr,edit_msg[ernoy05]);
		plerr     = 1;
		clerr     = 0;

		trace_err = TRUE;
		return(FALSE);
#endif
		}

/* binaire offset dans la ligne  a 0 */

	pt = 0;
	tmp = nomsrce;
	while ((c = Ligne[pt++]) != ' ') {
		(*tmp++) = c;
		}
	*tmp = EOSTR;
	XscanfForLong(&Ligne[0], &pt, &plerr);
	Xscanf(&Ligne[0], &pt, &clerr);
	Xstrcpy(curerr, &Ligne[pt]);

#else

	if ((nb = initialise_trace_controller( (BYTE FPTR) nomtrace )) == 0) {

#ifndef ver14
		Xerreur(FATAL,ernoy04);
#else
		traceon = TRUE; err_ecart = 0;

		Xstrcpy(curerr,edit_msg[ernoy04]);
		plerr     = 1;
		clerr     = 0;

		trace_err = TRUE;
		return(FALSE);
#endif
		}

	pt_err = position_to_first( ANYTYPE );
	Mstrcpy((BYTE FPTR) nomsrce, (BYTE FPTR) pt_err->filename);
	plerr = pt_err->ligne;
	clerr = pt_err->colonne;

	Mstrcpy((BYTE FPTR) curerr, (BYTE FPTR) pt_err->message);

#endif
	traceon = TRUE; err_ecart = 0;

	return (TRUE);
}					/* initrace */


static BOOL init_arg(BYTE XPTR p)

/*	initialisations de la ligne de commande dans un fichier 
 *	a partir du fichier designe par la chaine 'p'
 */
{					/* init_arg */
	BYTE XPTR lptr;

	nomargu[0] = EOSTR;
	Xstrcpy(nomargu,(BYTE *) p);
	farg = (FILE XPTR) (Xfopen(nomargu,(BYTE XPTR) "r"));
	if (farg == GenericNULL(FILE)) {
		Xerreur(FATALE,ernoy04);
		}

	lptr = (BYTE XPTR) (XXfgets((BYTE *) ligarg,(SWORD) 256,(FILE XPTR) farg));
	if (lptr == GenericNULL(BYTE))
		Xerreur(FATALE,ernoy05);

	/* enlever le dernier 0a */
	ligarg[Xstrlen(ligarg) - 1] = EOSTR;
	return (TRUE);
}					/* init_arg */

static BOOL NextOpt(BYTE XPTR XPTR pp)
{
	BYTE XPTR lptr;

	*pp = nextindice;	/* commence sur le prochain token */

	while (1) {
		while (*(*pp) == ' ') {
			(*pp) ++; /* Padding des blancs */
			}
		if ((BYTE) *(*pp) ==  (BYTE) EOSTR) {
  		   	if (nomargu[0] != EOSTR) { 
				lptr = (BYTE XPTR) (XXfgets(ligarg,(SWORD) 256,(FILE XPTR) farg));
				if (lptr == GenericNULL(BYTE)) {
					if (Xfeof(farg)) {
						Xfclose(farg); return (FALSE);
						}
					else	{
						editor_bell(); Xfclose(farg);
						Xerreur(USUAL,ficnread); return (FALSE);
						}
					}
				else	{
					ligarg[Xstrlen(ligarg) - 1] = EOSTR;
					}
				/* p pointe sur une nouvelle ligne */
				*pp =  &ligarg[0];
		 		}
		   	else	return(FALSE);	/* fin de la ligne de commande */
			}
		else	{

			/* termine les tokens par un zero */

			nextindice = *pp;
			while (*nextindice != ' ' && *nextindice != EOSTR) 
				nextindice ++;
			if (*nextindice == ' ') *nextindice++ = EOSTR;

			return(TRUE);

			}
		}
}

#include "edinit.c"
#include "edend.c"


#ifndef integre
int	show_editor_error(int gravite, char * msg, char * nptr )
{
	if (!flg_cico) {
		if (gravite == USUAL)
			printf("\n%s %s\n",edit_msg[msgerr],msg);
		else	printf("\n%s %s\n",edit_msg[msgerr],msg,edit_msg[msgabort]);
		}
	else	{
		pos(LGERR, COLERR);
		Xatb(2);
#ifdef ver14
 		if (gravite == FATALE) {		
			x_putch('(');

#ifndef prologue

			if (errno != 0) {
				outbin(LGERR, (SWORD) (COLERR + 1) , (SWORD) (errno));
				}
#else
			if (_prlerrno != 0) {
				outbin(LGERR, COLERR + 1 , _prlerrno);
				}
#endif

			x_putch(')');
			x_putch(' ');
			}
#endif
		x_cprintf((BYTE FPTR) msg);
		if (gravite == FATALE) {
			x_cprintf((BYTE FPTR)edit_msg[msgabort]);
			}
		Xatb(0);
		if (gravite == FATALE) {
			on_cursor();
			finecran();
			}
		}
	return(0);
}


VOID Xerreur( gravite, numes)
BYTE gravite; 
SWORD numes;
#else
static VOID Xerreur(BYTE gravite, SWORD numes)
#endif
/*	signale une erreur en cours d'edition, avec la possibilite
 *	d'arreter le programme si cette erreur est fatale.
 */
{				/* erreur */

	ChnFic	XPTR p, XPTR q;

	editorOnError(gravite,edit_msg[numes],edit_msg[msgerr] );

	if (gravite == FATALE) {
		if (fs != GenericNULL(TFILE)) {
			if ((fs->nl != EOF) && (!flgcreat))
				Xclose(fs->nl);
			liberate(fs);
			}
		if (fret != GenericNULL(TFILE)) {
			if (fret->nl != EOF) {
				Xclose(fret->nl); Xunlink(nomret);
				}
			liberate(fret);
			}
		if (fdest != GenericNULL(TFILE)) {
			if (fdest->nl != EOF) {
				Xclose(fdest->nl); 
#ifdef ver14
				if (SAVE_NOBAK == TRUE) 
					printf("\n   %s %s",edit_msg[msgsau],nomdest);	
				else	Xunlink(nomdest); /* en cas de non .bak
							  je ne detruit pas
							  le noveau fichier */
#endif
				}
			liberate(fdest);
			}
		if (ftrace != GenericNULL(FILE)) Xfclose(ftrace);
		if (tampon != GenericNULL(MemTemp))
			libtampon();
		p = deb_chnfic;
		while (p != GenericNULL(ChnFic)) {
			q = p->suiv; liberate(p); p = q;
			}
#ifdef ver14
		purge();
#endif

#ifdef ver21
		if (traceon) terminate_trace_controller();
#endif


#ifndef vms
		VAL_RET = 1;
#else
		VAL_RET = 0;	/* code retour PAIR -> erreur */
#endif
		if ( UseEdExit ) {
			Xlongjmp(Ed_Exit,1);
			}
		else	{
			printf("\n** erreur : aed cannot long jump ** \n");
			}
		}
}				/* erreur */

#ifdef ver14
static BOOL getnomfic(BYTE XPTR s, BYTE XPTR buf, BYTE XPTR ext)
/*	construit la designation d'un fichier en tenant compte de l'extension
 *	fournie par 'ext'. retourne 'TRUE' si cette extension a ete ajoutee.
 */
{					/* getnomfic */
	register BYTE *p = buf;
	BYTE tmp[LGREP];			/* pour l'extension */
	BYTE vmstmp[LGREP];			/* pour search liste */

	tmp[0] = EOSTR;
	buf[0] = EOSTR;
	vmstmp[0] = 0;
#ifdef vms
/*
	vms$sliste(s);
	vms$nliste(vmstmp);
*/
	Xstrcpy(vmstmp,s);
#else
	Xstrcpy(vmstmp,s);
#endif
	Xfn_parser((BYTE FPTR) vmstmp, (BYTE FPTR) tmp,16);
	Xfn_parser((BYTE FPTR) vmstmp,(BYTE FPTR) buf,8+4+2);

	if (tmp[0] == EOSTR) {	/* pas d'extension */
		tmp[0] = SEPTYP;
		tmp[1] = EOSTR;
		Xstrcat(tmp,ext);
		Xstrcat(buf,tmp);
		Xfn_parser((BYTE FPTR) vmstmp,(BYTE FPTR) &buf[Xstrlen(buf)],32 | 64);
		return(TRUE);
		}
	
	if (tmp[0] != SEPTYP) tmp[0] = SEPTYP;	/* le . en tiret sous prl */
	Xstrcat(buf,tmp);

	p = &tmp[1]; /* on se positionne sur l'extention */
	/* interdire les extensions EXTDEST, EXTRET et EXTSAV */
	if (striEq(p,(BYTE XPTR) EXTDEST) || striEq(p, (BYTE XPTR) EXTRET) || striEq(p,(BYTE XPTR) EXTSAV))
		Xerreur(FATALE,errcom);
	Xfn_parser((BYTE FPTR) vmstmp,(BYTE FPTR) &buf[Xstrlen(buf)],(SWORD) 32|64);
	/* retour normal */
	return (FALSE);
}					/* getnomfic */
#endif

static BOOL striEq(BYTE XPTR s, BYTE XPTR p)

/*	teste si les chaines s et p sont identiques, sans tenir compte
 *	des majuscules ou minuscules
 */
{					/* striEq */
	BYTE c1,c2;
	while (*s != EOSTR) {
		c1 = (BYTE) toupper(*s); c2 = (BYTE) toupper(*p);
		if (c1 != c2) return (FALSE);
		s++; p++;
	}
	if (*p != EOSTR) return (FALSE);
	return (TRUE);
}					/* striEq */

static VOID designation (BYTE XPTR pn)

/*	remplit la zone pointee par 'pn' avec la designation "simple"
 *	du fichier source, contenu dans 'nomsrce', sur une longueur de
 *	16 caracteres au maximum.
 */
{					/* designation */
	SWORD	nb = 0;
	BYTE	XPTR pc;
	BYTE    XPTR pf;


	pc  = &nomsrce[0];
	pf  = &nomsrce[0];


#ifdef ver14
	Xfn_parser((BYTE FPTR)nomsrce, (BYTE FPTR)pn, 8 + 16);
#else
	*pn++ = ' ';
#ifdef prologue
	while ((nb < 16) && (*pc != EOSTR) && (*pc != ':')) {
		*pn++ = (BYTE) toupper(*pc); pc++; nb++;
		}
#endif
#ifdef msdos
	while (*pc != EOSTR) {
		if (*pc == '\\')
			pf = pc + 1;
		pc++;
		}
	while ((nb < 16) && (*pf != EOSTR)) {
		*pn++ = (BYTE) toupper(*pf); pf++; nb++;
		}
#endif
#ifdef unix
	while (*pc != EOSTR) {
		if (*pc == '/')
			pf = pc + 1;
		pc++;
		}
	while ((nb < 16) && (*pf != EOSTR)) {
		*pn++ = *pf; pf++; nb++;
		}
#endif
#ifdef vms
	while (*pc != EOSTR) {
		if (*pc == ']')
			pf = pc + 1;
		pc++;
		}
	while ((nb < 16) && (*pf != EOSTR)) {
		*pn++ = (BYTE) toupper(*pf); pf++; nb++;
		}
#endif
	*pn++ = ' '; *pn = EOSTR;

#endif
}					/* designation */

static VOID xrename(BYTE XPTR ancnom, BYTE XPTR nouvnom)

/*	renommer un fichier, en detruisant si necessaire le fichier
 *	portant le nom definitif. Le fichier reste ouvert.
 */
{					/* xrename */

/*printf("\r\nRENAME %s en %s",ancnom,nouvnom); getch();*/

#ifdef prologue
	Xunlink(nouvnom);
	if (rename(ancnom,nouvnom) != 0) {
		Xerreur(FATALE,ernoy02);
		}
#endif
#ifdef msdos
	Xunlink((BYTE XPTR) nouvnom);
	if ((SWORD) (rename((char *) ancnom, (char *) nouvnom)) != (SWORD) 0)
		{
		Xerreur(FATALE,ernoy02);
		}
#endif
#ifdef unix
	Xunlink(nouvnom);
	if (link(ancnom,nouvnom) != 0)
		{
		Xerreur(FATALE,ernoy02);
		}
	Xunlink(ancnom); 
#endif
#ifdef vms
	if ((SWORD) (rename((char *) ancnom, (char *) nouvnom)) != (SWORD) 0)
		{
		Xerreur(FATALE,ernoy02);
		}
#endif
}					/* xrename */

SWORD Lgnlen(BYTE XPTR lgn)

/*	calcul de la longueur logique d'une ligne de texte
 */
{					/* Lgnlen */
	SWORD lg;
	BOOL	flg_tab = TRUE;

	if (*lgn == EOSTR || *lgn == LIMLIG)	/* ligne vide -> longueur 0 */
		lg = 0;
	else	{
		lg = 1;
		do 	{
			if (*lgn == TABUL) {
				/* cas particulier de la tabulation */
				LgNextTab(lg,(SWORD) 0); flg_tab = (BOOL) TRUE;
				}
			else	{	/* tout autre caractere = longueur de un */
				if (!flg_tab)
					lg++;
				flg_tab = FALSE;
				}
			lgn++;
			}
		while (*lgn != EOSTR && *lgn != LIMLIG);
		}
	return (lg);
}					/* Lgnlen */

	/*	Fonctions d'ouverture des fichiers	*/
	/*	----------------------------------	*/

FILE *XAfopen(BYTE XPTR nomfic, BYTE XPTR typ)

/*	Ouverture d'un fichier par 'fopen', en demandant son exclusivite
 *	pour une exploitation 'multi-utilisateurs' sans suppression
 *	sauf si ouverture en mode lecture seule sous Amenesik / Sologic.
 */
{					/* XAfopen */
	FILE	XPTR fh;

#ifdef	pilote
#ifdef	unix
	SWORD resac;

	/* Teste le fichier en mode partageable.
	 * Si l'acces est possible, c'est que le fichier existe
	 * et n'est pas bloque en mode exclusif.
	 */
	if (strEq(typ,"r")) {
		resac = Xaccess(nomfic,0);
		return(resac == 0 ? fopen(nomfic,"r") : GenericNULL(FILE));
		}

	/* Teste le fichier en mode exclusif.
	 * Si l'acces est possible, le fichier existe et n'est pas
	 * ouvert (ni en mode partageable ni en mode exclusif).
	 * Si l'access n'est pas possible, soit le fichier existe
	 * et ne peut pas passer en mode exclusif, soit le fichier
	 * n'existe pas et il faut le creer puis le bloquer en exclusif.
	 */
	else	{
		resac = Xaccess(nomfic,0);
		if (resac != 0) {
			if (errno != ENOENT)
				return(GenericNULL(FILE));

			/* cree le fichier puisqu'inexistant */
			fh = fopen(nomfic,typ);
			if (fh == GenericNULL(FILE))
				return(GenericNULL(FILE));

			/* retente un blocage du fichier */
			resac = Xaccess(nomfic,1);
			if (resac != 0) {
				fclose(fh);
				return(GenericNULL(FILE));
				}
			else	return(fh);
			}
		}
#endif
#endif

	fh = (FILE XPTR) (fopen((char *) nomfic,(char *) typ));

#ifdef msdos
/*	pas d'exclusivite sous DOS	*/
#endif

#ifdef anc_bib
	if (fh != GenericNULL(FILE) && !strEq(typ,"r")) {
		if (fmatb(fh,1,0) != 0) {	/* demande exclusif et copie */
			Xfclose(fh);
			fh = GenericNULL(FILE);	/* refuse */
			}
		}
#endif

#ifdef vms
	if (fh == GenericNULL(FILE)) {
		traitfilerror(0, errno);
		if (errno == 44) {
			Xerreur(FATALE, ernoy00);
			}
		fh = GenericNULL(FILE);
		}
#endif

	return (fh);
}					/* XAfopen */



/*global*/ SWORD XTopen(BYTE XPTR nomfic,SWORD typ, SWORD mod)

/*	Ouverture d'un fichier par 'open', en demandant son exclusivite
 *	pour une exploitation 'multi-utilisateurs' sans suppression
 *	sauf si ouverture en mode lecture seule sous Amenesik / Sologic.
 */
{					/* XTopen */
	SWORD fh;

#ifdef	unix
	SWORD resac;

	/* Teste le fichier en mode partageable.
	 * Si l'acces est possible, c'est que le fichier existe
	 * et n'est pas bloque en mode exclusif.
	 */

	if (typ == O_RDONLY) {
		resac = Xaccess(nomfic,0);
		return((resac == 0) ? (SWORD) open(nomfic,typ,mod) : EOF);
	}

	/* Teste le fichier en mode exclusif.
	 * Si l'acces est possible, le fichier existe et n'est pas
	 * ouvert (ni en mode partageable ni en mode exclusif).
	 * Si l'access n'est pas possible, soit le fichier existe
	 * et ne peut pas passer en mode exclusif, soit le fichier
	 * n'existe pas et il faut le creer puis le bloquer en exclusif.
	 */
	else {
		resac = Xaccess(nomfic,1);
		if (resac != 0) {
			if (errno != ENOENT)
				return(EOF);

			errno = 0;
			/* cree le fichier puisqu'inexistant */
			fh = (SWORD) open(nomfic, typ, mod);
			if (fh == EOF)
				return(EOF);

			/* retente un blocage du fichier */
			resac = Xaccess(nomfic,1);
			if (resac != 0) {
				Xclose(fh);
				return(EOF);
			}
			else
				return(fh);
		}
	}
#endif

#ifndef vms
	fh = (SWORD) open((char *) nomfic,(int) typ, (int) mod);
#else
	if (mod == 1) {
		/* fichier source en lecture */
		fh = (SWORD) open(nomfic, O_RDONLY, 0, "shr=nil");
	}
	else {
		fh = (SWORD) open(nomfic,typ,0);
	}
#endif

#ifdef msdos
/*	pas d'exclusivite sous DOS	*/
#endif

#ifdef anc_bib
	if (fh != EOF && !(typ == O_RDONLY)) {
		if (matb(fh,1,0) != 0) {	/* demande exclusif et copie */
			Xclose(fh);
			fh = EOF;	/* refuse */
		}

	}
#endif

#ifdef vms
	if (fh == -1) {
		traitfilerror(0, errno);
		if (errno == 44) {
			Xerreur(FATALE, ernoy00);
		}
		fh = EOF;
	}

#endif

	return (fh);
}					/* XTopen */



/* ---------------------------------------------------- */
/*							*/
/*	Gestion des acces aux fichiers			*/
/*							*/
/* ---------------------------------------------------- */

BOOL tstfinsource ()

/*	teste si le fichier source est vide en entree
 */
{					/* tstfinsource */
	SWORD	lglue;
	
	if (fs->Feof) {	/* fichier vide ! */
		return (TRUE);
	}
	if (fs->pbuf == fs->fbuf) {	/* buffer vide */
		/* alimenter par lecture bloc suivant */
		lglue = (SWORD) (Xread(fs->nl,fs->buf, LGBUF));
		if (lglue == 0) { /* fin de fichier en entree */
			fs->Feof = TRUE; 
#ifndef unix
			flgcreat = TRUE;
#endif
			return (TRUE);
		}
		fs->pbuf = &fs->buf[0]; fs->fbuf = &fs->buf[lglue];

#if prologue 
		if (lgexacte != 0 || flgcreat ) {
			if (fs->curofst >= lgexacte) {
				/* on depasse la fin de fichier */
				fs->Feof = TRUE; return(TRUE);
			}
			else if (fs->curofst + (long int) LGBUF > lgexacte) {
				/* fin de fichier sans 1A */
				fs->fbuf = &fs->buf[(SWORD) lgexacte - fs->curofst];
				fs->curofst = lgexacte;
			}
			else {	/* on avance tranquillement dans le source */
				fs->curofst += LGBUF;
			}				
		}
#endif
	}
	return (FALSE);	/* fichier non vide */
}					/* tstfinsource */

BOOL getsource (BYTE XPTR pl)

/*	lecture ligne suivante dans le fichier source
 *	si la fin de fichier est atteinte, retourne aussi la valeur FALSE.
 */

{					/* getsource */
	BYTE 	*sauvpl;
	SWORD lglue,lgmise;

#ifndef LGEXACTE
	BOOL	deblgn = TRUE;	/* en debut de ligne ? */
#endif
	
	sauvpl = pl; 	/* sauvegarde de l'adresse de debut */

	if (fs->Feof) 
		{	/* fichier vide ! */
		*pl = EOSTR; return (FALSE);
		}

	lgmise = 0; fs->nblgn++;
	while (TRUE) 
		{	/* boucle perpetuelle */
		if (fs->pbuf == fs->fbuf) 
			{	/* buffer vide */

#if prologue 
			if ((fs->curofst == lgexacte) && (lgexacte != 0)) 
				{
				*pl = EOSTR;
				fs->Feof = TRUE; return(FALSE);
				}
#endif
			/* alimenter par lecture bloc suivant */
			lglue = (SWORD) (Xread(fs->nl,fs->buf,LGBUF));

#ifdef YT230298
/* Ajoute un ^Z a la fin du fichier s'il n'y en a pas deja un.
   Ceci est utile quand on supprime le ^Z dans un autre editeur
	(Notepad par exemple) et qu'on reedite le fichier dans AED.
	La modif n'est faite que sous DOS.
 */
#ifdef msdos
			if (eof(fs->nl))
				{
				/* fin du fichier */
				/* force rajout d'une fin de fichier */
				fs->buf[lglue++]=EOTXT;
				}
#endif
#endif /* YT230298 */

			if (lglue == 0) 
				{ /* fin de fichier en entree */
				*pl = EOSTR; fs->Feof = TRUE;
#ifndef unix
				flgcreat = TRUE;
#endif
				return (FALSE);
				}
			fs->pbuf = &fs->buf[0]; fs->fbuf = &fs->buf[lglue];

/* attention au ver14 pour microsoft */
#if prologue 
			if (lgexacte != 0 || flgcreat ) 
				{
				if (fs->curofst + (long int) LGBUF > lgexacte) 
					{
					/* fin de fichier sans 1A */
					fs->fbuf = &fs->buf[(SWORD) lgexacte - fs->curofst];
					fs->curofst = lgexacte;
					}
				else 
					{	/* on avance tranquillement dans le source */
					fs->curofst += LGBUF;
					}				
				}
#endif
			}
#ifndef LGEXACTE
		if ( *(fs->pbuf) == EOTXT) 
			{	/* marqueur de fin */
			*pl = EOSTR; fs->Feof = TRUE;
			if (deblgn) /* fin de fichier si en debut de ligne */
				 return (FALSE);
			else 
				{	   /* fin de la ligne courante sinon */
				if (Lgnlen(sauvpl) >= LGLIGNE) 
					{
					Xerreur(FATALE,errlng);
					}
				return (TRUE);
				}
			}
#endif
		if ( *(fs->pbuf) != NL ) 
			{	/* pas en fin de ligne */
			if ( *(fs->pbuf) != CR ) 
				{ /* by-pass du CR */
				lgmise++;
				if (lgmise == LGLIGNE) 
					{
					Xerreur(FATALE,errlng);
					}
				*pl++ = *(fs->pbuf);
				}
			fs->pbuf++;
			}
		else 
			{	/* fin de ligne */
			fs->pbuf++; *pl = EOSTR; 
			if (Lgnlen(sauvpl) >= LGLIGNE) 
				{
				Xerreur(FATALE,errlng);
				}
			return (TRUE);
			}
#ifndef LGEXACTE
		deblgn = FALSE;	/* plus en debut de ligne */
#endif

		}
}					/* getsource */

BOOL getfic (TFILE XPTR fd, BYTE XPTR pl)

/*	lecture de la ligne precedente dans le fichier designe par fd
 *	retourne FALSE si l'on est en debut de fichier
 */

{					/* getfic */
	BYTE	XPTR pt = pl;
	BYTE	c;
	SWORD	i,j;

	if (fd->pbuf == &fd->buf[0]) { /* deja en debut de fichier */
		*pl = EOSTR; fd->Feof = TRUE; return (FALSE);
	}
	/* on enleve une ligne du fichier */
	fd->nblgn--;
	/* se positionner en fin de ligne precedente en reculant de 2 octets */
	fd->pbuf--;
	if (fd->pbuf == &fd->buf[0]) { /* on est en debut de buffer */
		if (fd->curofst == 0L) {
			/* debut de fichier atteint la ligne est vide */
			*pl = EOSTR; fd->Feof = TRUE; 
#ifndef unix
			flgcreat = TRUE;
#endif
			return(TRUE);
		}
		fd->curofst -= (long) LGBUF;
		Xseek(fd->nl,fd->curofst);
		if (Xread(fd->nl,fd->buf,LGBUF) != LGBUF)
			{
			Xerreur(FATALE,ernoy02);
			}
		/* remettre le pointeur a la position courante */
		Xseek(fd->nl,fd->curofst);
/*		fd->pbuf = &fd->buf[LGBUF-1]; */
		fd->pbuf = &fd->buf[LGBUF];
	}
	fd->pbuf--;
	while (TRUE) {	/* sortie par BREAK */
		if ( *(fd->pbuf) != CR ) { /* by-pass du CR */
			if ( *(fd->pbuf) != NL )
				*pl++ = *(fd->pbuf);
			else {
				/* remettre le pointeur / acces suivants */
				fd->pbuf++;
				*pl = EOSTR; break;
			}
		}
		if (fd->pbuf == &fd->buf[0]) { /* on est en debut de buffer */
			if (fd->curofst == 0L) {
				/* debut de fichier atteint */
				*pl = EOSTR; fd->Feof = TRUE; break;
			}
			fd->curofst -= (long) LGBUF;
			Xseek(fd->nl,fd->curofst);
			if (Xread(fd->nl,fd->buf,LGBUF) != LGBUF)
				{
				Xerreur(FATALE,ernoy02);
				}
			/* remettre le pointeur a la position courante */
			Xseek(fd->nl,fd->curofst);
			fd->pbuf = &fd->buf[LGBUF-1];
		}
		else 
			fd->pbuf--;	/* caractere precedent */
	}
	/* inverser la ligne en retour */
	for (i = 0, j = (SWORD) (Xstrlen(pt)-1); i < j; i++ , j--) {
		c = pt[i]; pt[i] = pt[j]; pt[j] = c;
	}
	return (TRUE);
}					/* getfic */

VOID putfic (TFILE XPTR fd, BYTE XPTR pl)

/*	ecriture de la ligne suivante dans le fichier designe par fd
 */


{					/* putfic */
#ifndef	unix
	BOOL	not_yet_CR;
#ifdef	ONNLCR
	not_yet_CR = TRUE;
#else
	not_yet_CR = FALSE;
#endif
#endif
	fd->Feof = FALSE;	/* forcement plus en debut de fichier */
	fd->nblgn++;		/* on ajoute une ligne au fichier */
	while (TRUE) {	/* sortie par BREAK */
		if (fd->pbuf == &fd->buf[LGBUF]) { /* buffer plein */
			/* purge par ecriture dans le fichier */
			if (Xwrite(fd->nl,fd->buf,LGBUF) != LGBUF)
				{
				Xerreur(FATALE,ernoy02);
				}
			fd->curofst += (long) LGBUF; fd->pbuf = &fd->buf[0];
		}
		if (*pl != EOSTR)
			*(fd->pbuf++) = *pl++;
		else {
#ifndef	unix
			if (not_yet_CR) {
				*(fd->pbuf++) = CR; not_yet_CR = FALSE;
				}
			else	{
				*(fd->pbuf++) = NL; break;
				}
#else
			*(fd->pbuf++) = NL; break;
#endif
			}
		}
}					/* putfic */

public	void	editorOnTrace()
{
	/* afficher la ligne correspondante */
	poslgn(0,(LONG) plerr); colcur = (SWORD) clerr;
	/* positionner sur le caractere correspondant */
	if (poscol()) { editorOnShow(); }
	return;
}

/*	----------------------------------------------- */
/*		I N I T M E M ()			*/
/*	----------------------------------------------- */
/*	initialiser le contenu de la memoire lors du 	*/
/*	lancement de l'editeur ou la reprise d'une	*/
/*	autre fichier en mode trace ou la commande 'O'	*/
/*							*/
/*	This function no longer displays the screen	*/
/*	the caller must perform this job after calling	*/
/*	this function					*/
/*	----------------------------------------------- */

static VOID initmem ()

{
	SWORD i = 0,j;

	/* zone tampon vide au depart */
#ifdef	ver2Kalloc
	if ( AedMemory == GenericNULL(BYTE)) {
		AedMemory = (BYTE *) allocate( (unsigned) ( ((unsigned) LGLIGNE) * ((unsigned) NBMXLIG)) );
		if (AedMemory == GenericNULL(BYTE))
			Xerreur(FATALE,ernoy03);
		}
	if ( lgntemp == GenericNULL(BYTE)) {
		lgntemp = (BYTE *) allocate( LGLIGNE );
		if (lgntemp == GenericNULL(BYTE))
			Xerreur(FATALE,ernoy03);
		}
	initcurerr();
#endif
	if (tampon == GenericNULL(MemTemp)) {
		tampon = (MemTemp *) allocate(sizeof(MemTemp));

		if (tampon == GenericNULL(MemTemp))
			Xerreur(FATALE,ernoy03);
		tampon->suiv = GenericNULL(MemTemp);
		}

	off_cursor();
	if (fs->Feof) { /* fichier source est vide / n'existe pas */
		putmemchar(0,0,EOSTR);
		}
	else	{
		/* ---------------------------------------------------- */
	   	/* remplir la memoire avec le contenu du fichier source */
		/* this function used to display at the same time	*/
		/* but this has been remove for a better architecture	*/
		/* for use within visual factory sing			*/
		/* ijm 02/04/2003					*/
		/* ---------------------------------------------------- */
	   	firstcol = 0;
	   	while ( ligne <= MXLIG) {
			if (!(getsource(adrmemlin(i))))
				break;
			ligne++; i++;
		   	}
		}
	if (i != 0)
		lastligne = (SWORD) (i - 1);
	else	lastligne = 0;
	numlgn = 1;

	ligcur = colcur = firstcol = 0;
	ligne = LGINIT; colonne = CLINIT;

	if (traceon) { 	editorOnTrace();	}

	else	{
		if (arglig) {
			poslgn(0, arglig);
			if (argcol) {
				colcur = argcol;
				if (poscol()) {
					editorOnShow();
					}
				}
			}
		}
	pos(ligne,colonne); 
	on_cursor();
	return;
}					/* initmem */

static VOID purgedest()

/*	fin de travail : purger le contenu du fichier retour
 *	et le reste du source dans le fichier destination
 */

{					/* purgedest */
SWORD i,lg;
#ifdef prologue
	SWORD gdd;
	ULONG   tmp_lg;
	BYTE tmp[80];
#endif
#ifdef	UNIX
	BYTE	eof=EOTXT;
	BYTE *  eptr;
	WORD	puteof=0;
#endif
	/* commencer par vider la memoire */
	for (i = 0; i <= lastligne; i++) {
		putdest(adrmemlin(i));
		}
	/* continuer avec le contenu du fichier retour */
	while (getret(adrmemlin(0))) {
		putdest(adrmemlin(0));
		}
	/* et completer avec le reste eventuel du source */
	while (getsource(adrmemlin(0))) {
		putdest(adrmemlin(0));
		}

	/* purger le fichier destination si une ecriture est necessaire */
#ifdef LGEXACTE

	/* l'environnement accepte des fichiers de longueur exacte */
	if (fdest->pbuf != &fdest->buf[0]) { /* buffer non vide */
		lg = (SWORD) (fdest->pbuf - &fdest->buf[0]); /* lg a ecrire */
		if (Xwrite(fdest->nl,fdest->buf,lg) != lg)
			{
			Xerreur(FATALE,ernoy02);
			}
	}
#ifdef	UNIX
#ifdef	VERSION666
	puteof=1;
	eof=0x001A;
#else
	if (!(eptr = getenv("AEDEOF")))
		puteof=0;
	else if ( *eptr != '0' )
		puteof=1;
	else	puteof = 0;
#endif
	if ( puteof ) {
		/* put an end of file mark anyway ! */
		/* ------------------------------- */
		if (Xwrite(fdest->nl,&eof,(lg=1)) != lg) {
			Xerreur(FATALE,ernoy02);
			}
		}
#endif
#else

	/* il faut une marque speciale de fin de fichier */
	if (fdest->pbuf == &fdest->buf[LGBUF]) { /* buffer plein */
		if (Xwrite(fdest->nl,fdest->buf,LGBUF) != LGBUF)
			{
			Xerreur(FATALE,ernoy02);
			}
		fdest->pbuf = &fdest->buf[0];
#ifdef ver14
		fdest->curofst += (long) LGBUF;
#endif
	}

	*fdest->pbuf++ = EOTXT;
#ifdef msdos
	/* l'environnement accepte des fichiers de longueur exacte */
	if (fdest->pbuf != &fdest->buf[0]) { /* buffer non vide */
		lg = (SWORD) (fdest->pbuf - &fdest->buf[0]); /* lg a ecrire */
		if ((SWORD) Xwrite(fdest->nl,fdest->buf,lg) != lg)
			{
			Xerreur(FATALE,ernoy02);
			}
	}
#else

	lg = i = (fdest->pbuf - &fdest->buf[0]); 

	/* Correction 14.a */
	if (lgexacte || flgcreat) {
		lgexacte  = fdest->curofst + (ULONG) lg;
	}

	lg = (lg / LGBLOC) * LGBLOC;
	if ((i % LGBLOC) != 0) lg += LGBLOC;

	while (fdest->pbuf <= &fdest->buf[LGBUF])
		*(fdest->pbuf++) = EOSTR;
	if (Xwrite(fdest->nl,fdest->buf,lg) != lg)
		{
		Xerreur(FATALE,ernoy02);
		}

	/* on remet a jour le descripteur fichier de prl */
#ifdef ver14
	if (lgexacte || flgcreat ) {

	 	gdd = ngffh((SWORD) fdest->nl);
		Xgetdd( gdd, &_ngf_dd[0]);	/* lecture du dd prl */

		/* retour d'erreur */

		nsect = lgexacte / LGBLOC ; /* Nombre de secteur */
		tmp_lg = (ULONG) nsect * (ULONG) LGBLOC;

		tmp_lg = (ULONG) lgexacte - tmp_lg;

		_ngf_dd[4] = (BYTE) tmp_lg;
		_ngf_dd[5] = (BYTE) (nsect & 0x00FF);	/* poids faible */
		_ngf_dd[6] = (BYTE) (nsect >> 8) & 0xFF; /* poids fort */

		Xputdd( gdd ,_ngf_dd);	

	}
#endif
#endif 
#endif
}					/* purgedest */

static VOID purgesrce()

/*	fin de travail : purger le contenu du fichier retour
 *	et le reste du source dans le fichier destination
 */
{					/* purgedest */
	SWORD i,lg;
#ifdef prologue
	SWORD gdd;
	ULONG   tmp_lg;
#endif

	SAVE_NOBAK = TRUE;	/* debut de la sauvgarde dans le fichier origine
					pour le cas d'erreur dans getsource
					et putdest. la fonction Xerreur en
					tiendra compte pour sortir son message
				*/

	/* se positionne au debut du fichier source */
	Xclose(fs->nl);	/* on ferme le fichier courant */

	/* On transfert la structure fdest -> fs 
		afin de garder la fonction getsource */

	fs->nl = fdest->nl;
	fs->curofst = 0L;
	fs->Feof = fdest->Feof;
	fs->nblgn = 0;
	fs->pbuf = fs->fbuf = &fs->buf[0];
	Xseek(fs->nl,0L);	/* se repositionne au debut du fichier */
	
#ifdef unix 
	liberlox(nomsrce);
	i = 0;
#else
	i = (SWORD) (Xaccess(nomsrce,0));
#endif
	if (i == 0) {
		fdest->nl = Xcreat(nomsrce);
		if (fdest->nl == EOF)   
			Xerreur(FATALE, ernoy01);
		fdest->Feof = FALSE; flgcreat = FALSE;

	}
	else {
		/* on imprime le message d'impuissance */
#ifdef ver14
		Xerreur(FATALE, errsau);
#else
		{
		Xerreur(FATALE,ernoy02);
		}
#endif
	}

	/* on remet a zero les compteurs */
	
	fdest->curofst = 0L;
	fdest->pbuf = fdest->fbuf = &fdest->buf[0];
	fdest->nblgn = 0;	

	/* et on y va pour les transferts */
	while(getsource(adrmemlin(0)))
		putdest(adrmemlin(0));

	/* purger le fichier destination si une ecriture est necessaire */
#ifdef LGEXACTE
	/* l'environnement accepte des fichiers de longueur exacte */
	if (fdest->pbuf != &fdest->buf[0]) { /* buffer non vide */
		lg = (fdest->pbuf - &fdest->buf[0]); /* lg a ecrire */
		if (Xwrite(fdest->nl,fdest->buf,lg) != lg)
#ifdef ver14
			Xerreur(FATALE, errsau);
#else
		{
		Xerreur(FATALE,ernoy02);
		}
#endif
	}
#else

	/* il faut une marque speciale de fin de fichier */
	if (fdest->pbuf == &fdest->buf[LGBUF]) { /* buffer plein */
		if (Xwrite(fdest->nl,fdest->buf,LGBUF) != LGBUF)
#ifdef ver14
			Xerreur(FATALE, errsau);
#else
		{
		Xerreur(FATALE,ernoy02);
		}
#endif
		fdest->pbuf = &fdest->buf[0];
#ifdef ver14
		/* modif 14b */
		fdest->curofst += (long) LGBUF;
#endif
	}

	*fdest->pbuf++ = EOTXT;

#ifdef msdos
	/* l'environnement accepte des fichiers de longueur exacte */
	if (fdest->pbuf != &fdest->buf[0]) { /* buffer non vide */
		lg = (SWORD) (fdest->pbuf - &fdest->buf[0]); /* lg a ecrire */
		if ((SWORD) (Xwrite(fdest->nl,fdest->buf,lg)) != lg)
#ifdef ver14
			Xerreur(FATALE, errsau);
#else
		{
		Xerreur(FATALE,ernoy02);
		}
#endif
	}
#else
	lg = i = (fdest->pbuf - &fdest->buf[0]); 

	lgexacte  = fdest->curofst + (long int) lg;

	lg = (lg / LGBLOC) * LGBLOC;
	if ((i % LGBLOC) != 0) lg += LGBLOC;
	while (fdest->pbuf <= &fdest->buf[LGBUF])
		*(fdest->pbuf++) = EOSTR;
	if (Xwrite(fdest->nl,fdest->buf,lg) != lg)
#ifdef ver14
		Xerreur(FATALE, errsau);
#else
		{
		Xerreur(FATALE,ernoy02);
		}
#endif

	/* on remet a jour le descripteur fichier de prl */
#ifdef ver14
	if (lgexacte || flgcreat) {	
		gdd = ngffh((SWORD) fdest->nl);
		Xgetdd( gdd, _ngf_dd);	

		nsect = lgexacte / LGBLOC ; /* Nombre de secteur */

		nsect = (SWORD) (lgexacte / LGBLOC) ; /* Nombre de secteur */
		tmp_lg = (unsigned long int) nsect * (unsigned long int) LGBLOC;
		tmp_lg = lgexacte - tmp_lg;

		_ngf_dd[4] = (BYTE) tmp_lg;
		_ngf_dd[5] = (BYTE) (nsect & 0x00FF);	/* poids faible */
		_ngf_dd[6] = (BYTE) (nsect >> 8) & (BYTE) 0xFF;/* poids fort */


		Xputdd(  gdd, _ngf_dd);	
	}
#endif
#endif 
#endif
}					/* purgesrce */

/*	---------------------------------	*/
/*	W I Z Z A R D   OF    O Z ( )		*/
/*	-----------------------------		*/
/*	This function provides a cleanup	*/
/*	of the old 'O' and 'O-' functions	*/
/*	prior to the 'eclatement' for use	*/
/*	by the new :				*/
/*		HyperFunkZonetions		*/
/*	or					*/
/*		HyperZoneFunctions		*/
/*	whichever you choose			*/
/*	---------------------------------	*/

int	WizzardStop( BPTR pcom, ULONG * go_ligne, BPTR autrefic )
{
#ifdef ver21
	TRACEPTR pt_err;
#endif
	int	i;
	int	flg_ext;
	int	otiret;
	int	retvideo;
	BYTE    comtmp[LGCOM];
	BYTE	*paf;

	otiret 		= FALSE;		
	paf 		= autrefic; 
	retvideo	= FALSE; 
	*go_ligne 	= 0;

	if (*pcom == '-' || *pcom == '&' ) {
		if (*pcom == '&') {
			/* sauvegarde de la position */
			/* histo du dernier fichier */
			Xstrcpy(comtmp,"O-");
			diff_repfich(n_path, nomsrce, &comtmp[2]);
			Xstrcat(comtmp,"!");
			sprintf(&comtmp[Xstrlen(comtmp)], "%d", numlgn);
			maj_histo(comtmp);
			}
		otiret = TRUE;
		pcom ++;
		while (*pcom != EOSTR && *pcom != '!') {
			*paf++ = *pcom++;
			}
		*paf = EOSTR;
		if (*pcom == '!') {
			pcom++;
			*go_ligne = atol( pcom );
			}
		*pcom = EOSTR;
		}
	else	{
		if (traceon) {
			Xstrcpy(autrefic, firstedit);
			}
		else	{
			Xstrcpy(autrefic,nomsrce);
			}
		}

	if (*pcom == EOSTR) {

		if (txtchg) {
	      		if (!(confirme_lose() )) {
				editor_bell(); 
				return(FALSE);
				}				
			}
		/* fermeture des fichiers */
		if (!flgcreat) { Xclose(fs->nl); }

		Xclose(fdest->nl); Xunlink(nomdest);
		/* Liberation du semaphore */
		Xclose(fret->nl); Xunlink(nomret);
#ifdef	UNIX
	        PurgeLox();
#endif
		if (fs != GenericNULL(TFILE)) 	{ liberate(fs);   }
		if (fret != GenericNULL(TFILE)) { liberate(fret); }
		if (fdest != GenericNULL(TFILE)){ liberate(fdest);}

		retvideo = TRUE;
	
		}
	return( retvideo );
}	

int	WizzardStart( BPTR pcom, ULONG * go_ligne, BPTR autrefic )
{
#ifdef ver21
	TRACEPTR pt_err;
#endif
	int	i;
	int	flg_ext;
	int	otiret=FALSE;
	int	retvideo;
	BYTE    comtmp[LGCOM];
	BYTE 	*paf;

	if (traceon) {
	 	if (otiret == TRUE ) {
			terminate_trace_controller();
			if (! initrace(autrefic)) {
			 	flg_ext = getnomfic(autrefic,nomsrce,EXTS);
				}
			}	
		else	{
			if ( ftrace != GenericNULL( FILE ) ) {
				pt_err = position_to_first( ANYTYPE );
				Mstrcpy((BYTE FPTR) nomsrce, (BYTE FPTR) pt_err->filename);
				plerr = pt_err->ligne;
				clerr = pt_err->colonne;
				Mstrcpy((BYTE FPTR) curerr, (BYTE FPTR) pt_err->message);
				}
			}
		if (!( is_window_editor() )) {
			x_bstart();
			pos(3,1); atb(22); Xatb(APU); x_putch(' '); 
			x_cprintf((BYTE FPTR) curerr);
			horizontal_rule(4,1,MXCOL);
			Xatb(0);
			x_bflush();
			}
		}
	 else	{
		flg_ext = getnomfic(autrefic,nomsrce,EXTS);
	 	}					 
	if (!( is_window_editor() )) {
		 pos(LGINIT,CLINIT); atb(22);
		 if (flg_help) {
			x_bstart();
			horizontal_rule((MXLIG+1),CLINIT,MXCOL);
			x_bflush();
			aff_help();
		 	}
		}
	 /* reconstruire le fichier */
	 init_fic(TRUE,flg_ext);
	 ligne = LGINIT;
	 colonne = CLINIT;
	 firstcol = 0;
	 deblgn = 0; finlgn = 0;
	 initmem();
 	 posfin();
	 maxnumlgn = numlgn;
	 if (traceon) { editorOnTrace(); }
	 else	      { 
		posdeb();	 
		editorOnShow();
		}
	if (!( is_window_editor() )) {
		 draw_editor_screen();
		 wipe_indent_message();
		 show_indent_message();
		 show_insert_message();
		 show_line_numbering();
		 Xatb(0);
		}
	 if (*go_ligne) { poslgn( 0, go_ligne);  }
	 return(( retvideo = TRUE ));
}

int	WizzardOfOz( BPTR pcom, ULONG * go_ligne, BPTR autrefic )
{
	int	retvideo;
	if ((retvideo = WizzardStop(pcom,  go_ligne,autrefic))!=0)
		(void) WizzardStart(pcom,  go_ligne,autrefic);
	return( retvideo );
}



public	void	editorOnQuit()
{
	/* fermeture des fichiers */
	/* ---------------------- */
	if (!flgcreat)
		Xclose(fs->nl);

	Xclose(fdest->nl); 
	Xunlink(nomdest);

	if (traceon) {
#ifdef ver21
		terminate_trace_controller();
#else
		Xfclose(ftrace);
#endif
	    }

	/* Liberation du semaphore */
	/* ----------------------- */
	Xclose(fret->nl); 
	Xunlink(nomret);
	
	return;
}


public	void	editorOnUpdate(char * pcom)
{
	BYTE    comtmp[LGCOM];
	BOOL    otiret;
	BYTE 	autrefic[LGMXNOM], *paf;
	BYTE 	nomtarget[LGMXNOM];
	BOOL	flg_ext = FALSE;
	BOOL	NewName=FALSE;
/*
	int	holdc=colcur;
	int	holdl=ligcur;
 */
	paf = autrefic;
	otiret = FALSE;
	Xstrcpy(nomtarget,nomsrce);
	if ((*pcom == '-') || (*pcom == '&' )) {
		/* holdl = holdc = 0; */
		if (*pcom == '&') {
			/* sauvegarde de la position */
			/* histo du dernier fichier */
			Xstrcpy(comtmp,"O-");
			diff_repfich(n_path, nomsrce, &comtmp[2]);
			Xstrcat(comtmp,"!");
			sprintf(&comtmp[Xstrlen(comtmp)], "%d", mlig);
			maj_histo(comtmp);
			}
		pcom ++;
		while (*pcom != EOSTR) {
			*paf++ = *pcom++;
			}
		*paf = EOSTR;
		otiret = TRUE;
		}
	else if ( *pcom != 0 ) {
		/* save as ... */
		Xstrcpy(nomtarget,pcom);
		NewName = TRUE;
		while ( *pcom != 0 )
			pcom++;
		}
#ifndef ver21
	if (first && (*pcom == EOSTR)) { 
#endif
		purgedest();
		/* fermeture des fichiers */
		if (!flgcreat) {
			Xclose(fs->nl);
			}
		Xclose(fdest->nl);
		if (!flg_def_dest) {
			/* if we SaveAs, we can keep the others */
			/* ------------------------------------ */
			if (!( NewName )) {
				if (!flgcreat) {
				  	 xrename(nomsrce,nombak);
					}
		
#ifdef	VERSION666
				xcopy(nomdest,nomsrce);
#else
				xrename(nomdest,nomsrce);
#endif
				}
			else	{
				/* printf("Editor Save As : %s \r\n",nomtarget); */
#ifdef	VERSION666
				xcopy(nomdest,nomtarget);
#else
				xrename(nomdest,nomtarget);
#endif
				}
			}
		else	{
			xrename(nomdest,nomdef);
			}
		if (traceon) {
#ifndef ver21
			Xfclose(ftrace);
#else
			commit_trace_adjustment();
#endif	
			Xunlink(nomtrace);
			}

		/* Liberation du semaphore */

		Xclose(fret->nl);
		Xunlink(nomret); 
	
		if (fs != GenericNULL(TFILE)) {
			liberate(fs);
			}

		if (fret != GenericNULL(TFILE)) {
		   	liberate(fret);
			}
		if (fdest != GenericNULL(TFILE)) {
			liberate(fdest);
			}		
#ifdef unix
		PurgeLox();
#endif

#ifdef ver21
		if (otiret == FALSE) Xstrcpy(autrefic,nomsrce);
#else
		Xstrcpy(autrefic,nomsrce);
#endif
		flg_ext = getnomfic(autrefic, nomsrce, EXTS);

		init_fic(TRUE,flg_ext);
		ligne = LGINIT;
		colonne = CLINIT;
		pos(LGINIT,CLINIT);
		if (!( is_window_editor() ))
			atb(22);
		firstcol = 0;
		initmem();
		editorOnShow();
#ifndef ver21
		}
	else	{
		noerr = FALSE; editor_bell();
		}
#endif
/*
	ligcur = holdl;
	colcur = holdc;
 */
	return;
}

/*
 *	C O M M A N D E ( )
 *	-------------------
 *	gestion du mode commande, retourne TRUE si la fin
 *	de l'edition a ete demandee, les fichiers etant alors fermes
 */

void	set_maj_min(int v)
{
	MAJMIN = v;
	return;
}

int	get_maj_min()
{
	return(MAJMIN);
}

BOOL commande()
{					/* commande */
	BYTE    comtmp[LGCOM];
	BYTE 	autrefic[LGMXNOM], *paf;
	ULONG go_ligne;

	BYTE	*pcom,*nom,*nom2,rep,curcar;
	BOOL	retvideo = FALSE,coderet = FALSE;
	BOOL	first,keep,noerr = TRUE,flg_esc;
	LONG nb;
	SWORD	atbcurcar;
	SWORD i,j;
	SWORD sens;
	BYTE 	c;
#ifdef ver21
	TRACEPTR pt_err;
#endif
	SWORD   flg_n;
	SWORD   cmdsyst;
	SWORD	inhibitXQ=0;
	BOOL	flg_ext = FALSE;

	sens = 0;
	mlig = numlgn;		/* Sauvegarde de la position courrante */
	mcol = colcur;
	mfirstcol = firstcol;
	mcolr = colonne; 	/* colonne reelle sur l'ecan */
	cmdsyst = 0;
	go_ligne = 0;

	curcar = getmemchar(ligcur,colcur); atbcurcar = 0;
	if (curcar < 0x0020) {
		if ((curcar == EOSTR) || (curcar == TABUL))
			curcar = ' ';
		else 	{
			curcar += 0x0040; atbcurcar = 2;
			}
		}
	pos(ligne,colonne); Xatb(2); putch(curcar); Xatb(0);
	flg_n = 0;
	do 	{
#ifdef ver14
		JOKER = FALSE;
		set_maj_min(FALSE);
#endif
		if (!( is_window_editor() )) {
			inhibitXQ=0;
			pos(1,30); Xatb(21); putch('*');
			get_saisie (com,LGCOM); 
			pcom = &com[0];
			Xatb(0);
			if (!noerr) {
				x_bstart();
				horizontal_rule(LGERR,COLERR,MXCOL);
				x_bflush();
				}
			}
		else	{
			inhibitXQ=1;
			if ( editorOnCommand(com,LGCOM) == 27 )
				break;
			else	pcom = &com[0];
			}
		first = noerr = TRUE; nb = 0; flg_esc = FALSE;
#ifdef BRUNO
		if (flg_n) {
			/* remettre en etat */

			i = 0;
			Xatb(0);
			pos(ligne,colonne);
			while (*(nom+i)) 
				x_putch(*(nom+(i++)));
			pos(ligne,colonne);

			flg_n = 0;
			}
#endif
		do 	{
			rep = (BYTE) toupper(*pcom); pcom++;
			switch (rep) {
			case '?':
#ifdef ver14
				Memento(*pcom);
				if (*pcom != EOSTR) pcom++;
#else
				memento();
#endif
				break;
#ifdef ver12

			case 'M':  	/* affichage du memento  Ctrl */
#ifdef ver14
				Memento(*pcom);
				if (*pcom != EOSTR) pcom++;
#else
				memento();
#endif
				break;
#endif
#ifdef ver14
#ifdef ver21
			case ';' :
				pcom--;
				break;
#endif

			case 0x1b:
				if (first) pcom--;
				break;

			case '*' :
				JOKER = TRUE;
				break;

			case '!' :
				set_maj_min(TRUE);
				break;

			case ':':
				if (*pcom == EOSTR || toupper(*pcom) == 'V' || (EXTEND_AED == FALSE)) {
					break;
					}

				pos(3,1),atb(22);
				Xstrcpy(comtmp,pcom);
				rep = Xsystemd((BYTE FPTR) comtmp,3,conf(1),1);
				x_cprintf((BYTE FPTR) "\r\n");
				nedpause();
				maj_taille(0,0);
				x_bstart();

				pos(1,1);
				x_cprintf((BYTE FPTR)edit_msg[msgfic]);
				for (i=(SWORD)(Xstrlen(edit_msg[msgfic])); i < MXCOL; i++)
					x_putch(' ');
				horizontal_rule(2,1,MXCOL);
				x_bflush();

				if (traceon) {
					x_bstart();
					pos( 3, 1); 
					Xatb(APU); 
					x_putch(' '); 
					x_cprintf((BYTE FPTR)curerr);
					horizontal_rule(4,1,MXCOL);
					Xatb(0);
					x_bflush();
					}
				pos(1,11); Xatb(21); 
				Xatb(102);
				x_cprintf((BYTE FPTR) nomsrce);
				Xatb(0);
				noerr = FALSE;
				break;
#ifdef	VERSION666
			case	'I' :
#endif
			case TABUL : 	/* changer la tabulation */
				if ((*pcom < '1') || (*pcom > '9') || (*(pcom+1) != EOSTR)) {
					noerr = FALSE; editor_bell();
					}
				else	{
					lg_tabul = (SWORD) cartoint(*pcom);
					editorOnShow();
					}
				break;

			case 'F' :	/* affiche le nom de fichier */
#ifdef ver21
				if ((first) && (*pcom == EOSTR || toupper(*pcom) == 'H' )) {
#else
				if ((first) && *pcom == EOSTR) {
#endif
					pos(LGINIT,CLINIT); atb(22);
					 if (flg_help) {
						x_bstart();
						horizontal_rule((SWORD) (MXLIG+1),CLINIT,MXCOL);
						x_bflush();
						aff_help();
						 }

					if (*pcom == EOSTR) {
						aff_file(nomsrce);
						}
					else	{
						aff_histo();
						if (traceon) {
							x_bstart();
							pos(3,1); atb(22); Xatb(APU); x_putch(' '); 
							x_cprintf((BYTE FPTR)curerr);
							horizontal_rule(4,1,MXCOL);
							Xatb(0);
							x_bflush();
							}
						pcom ++;
						}

					editorOnShow();
					}
				else editor_bell();

				break;

			  case '(':	/* Nombre de ligne / nombre de colonne */
					/* format (nl,nc) */

					if (*pcom == ')' && *(pcom+1) == EOSTR) {
						/* retour au format standard */
						maj_taille(0,0);
						}

					else if ((*(pcom+2) == ',') && (*(pcom+5) == ')')) {
						i = (SWORD) ((*(pcom) - '0') * 10 + (*(pcom+1) - '0'));
						j = (SWORD) ((*(pcom+3)-'0') * 10 + (*(pcom+4) - '0'));

						maj_taille(i,j);
						}					
					else	{
						editor_bell();
						break;
						}

					break;

			case '>':	/* saisie d'une chaine non asci */
				pos(ligne,colonne);
				if ((*(pcom+2) == EOSTR) && (isxdigit(*pcom)) && (isxdigit(*(pcom+1)) ) ){
					if ((BYTE) (isdigit(*pcom))) c = (BYTE) (*pcom - '0');
					else c = (BYTE) (toupper(*pcom) - 'A'+10);
					pcom++;

					c <<= 4;

					if (isdigit(*pcom)) c |= *pcom - '0';
					else c |= (BYTE) toupper(*pcom) - 'A'+10;
					pcom++;

					saisie(c);
					}
				else	editor_bell();
				break;
#endif
#ifdef	VERSION666
			case 'S' :
				switch ( sens ) {
					case	1 : set_editor_bell(1); break;
					case	0 :
					case	-1: set_editor_bell(0); break;
					}
				break;					

			case 'Z' :	/* Hyper Funk Zone */	
				UseHyperFunkPath( pcom );
				retvideo = TRUE;
				noerr = TRUE;
				break;
#endif
			case 'O':	/* Retour au fichier initial */

				if ((retvideo = WizzardOfOz( pcom, &go_ligne,autrefic)) != 0)
					noerr = TRUE;
				else	noerr = FALSE;
				break;

			case 'H':	/* Sauvegarde en en cours */
#ifndef ver21
				if (txtcons || !txtchg) {
					noerr = FALSE; editor_bell(); break;
					}				
#else
				if (txtcons) {
					noerr = FALSE; editor_bell(); break;
					}
				if (!txtchg) editor_bell();
#endif
				editorOnUpdate(pcom);
#ifndef ver21

				if (*pcom == ESCAPE) {
					flg_esc = TRUE;				
					}
#endif

				break;
				


			case 'X': 		/* Retour a l'endroit */
				reposit(mlig,mcol,mfirstcol,mcolr);
				break;
#ifdef	_GRAPHIX_EXTENSION
			case 'G' : /* Graphics Commande */

				rep = (BYTE) toupper(*pcom); pcom++;
				switch ( rep ) {
					case	'M'	:
						finecran();
						set_bios_mode( pcom );
						initecran();
						break;
					case	'F'	:
						if (( change_font( pcom )      != 0 )
						&&  ( window_characteristics() != 0 )) {
							showfilename();
							colonne = CLINIT;
							ligne   = LGINIT;
							editorOnShow();
							colonne = CLINIT;
							ligne   = LGINIT;
							pos(ligne,colonne);
							}
						break;
					default		:
						editor_bell();
						break;
					}
				break;
#endif
			case 'V':		/* retour a l'edition */
				if (*pcom == EOSTR) {
					wipe_indent_message();
					show_indent_message();
					show_insert_message();
					show_line_numbering();
					Xatb(0); retvideo = TRUE; break;
					}
				else	{
					noerr = FALSE; editor_bell();
					}
				break;

			case 'E':		/* fin normale de l'edition */
				if ( inhibitXQ ) { break; }
#ifdef ver14
				if (txtcons) {
					noerr = FALSE; editor_bell(); break;
					}				
#endif
				if (first && ((*pcom == EOSTR) || (*pcom == '$') || (*pcom == '#') )) {
					if (*pcom == '#') {
						Xfn_parser((BYTE FPTR) nomsrce, (BYTE FPTR) comtmp, 1 + 2 + 4 + 8);
						Xstrcat( comtmp, ".zoo");
						fhzoom = Xfopen( comtmp, "w" );

						fprintf(fhzoom,"%d %d %s ", numlgn, colcur, nomsrce);
						get_token();
						fprintf(fhzoom,"%s\n",buf_getch);

						Xfclose( fhzoom);

						*pcom = EOSTR;
						}
					if (*pcom == '$') {
						pcom++;
						getnomfic(pcom,nomdef,EXTS);
						flg_def_dest = TRUE;
						*pcom = EOSTR;	
						}
					purgedest();

					if ((BOOLBAK)  && (!flgcreat)) {
						purgesrce();
						Xclose(fs->nl);
						Xclose(fret->nl);
						Xclose(fdest->nl);
						if (flg_def_dest) 
							xrename(nomsrce, nomdef);
						
						Xunlink(nomdest);
						}
					else	{
						/* fermeture des fichiers */
						if (!flgcreat)
							Xclose(fs->nl);
						Xclose(fdest->nl);
						if (!flg_def_dest) {
							if (!flgcreat)
							   xrename(nomsrce,nombak);
#ifdef	VERSION666
						        xcopy(nomdest,nomsrce);
#else
						        xrename(nomdest,nomsrce);
#endif
							}
						else	{
							xrename(nomdest,nomdef);
							}
						}

					if (traceon) {

#ifdef ver21
						terminate_trace_controller();

#else
						Xfclose(ftrace);
#endif

						Xunlink(nomtrace);
						}
					/* Liberation du semaphore */
					Xclose(fret->nl); Xunlink(nomret);
					retvideo = TRUE;
					coderet  = TRUE;
#ifndef vms
					VAL_RET  = 0;
#else
					VAL_RET = 1;
#endif

					}
				else	{
					noerr = FALSE; editor_bell();
					}

				break;

			case 'Q':

				if ((first) && (*pcom == EOSTR)) {

					/* commands X and Q are legal ? */
					/* ---------------------------- */
					if ( inhibitXQ ) { break; }
#ifdef ver14
					if (txtchg) {
						if (!( confirme_lose() ))
							break;
				   		}
#else
					if (!( confirme_lose() ))
				 		break;

#endif
					/* abandon edition */
					editorOnQuit();
					retvideo = TRUE;
					coderet = TRUE;
#ifndef vms
					VAL_RET = 0;
#else
					VAL_RET = 1;
#endif
					ligne = LGINIT;
					colonne = 1;
					on_cursor();
					}
				else	{
					/* -------------------- */
					/* manip dans le tampon */
					/* EDVists 666QP$666QGV */
					/* -------------------- */
					if (sens != 0) {
						noerr = FALSE; editor_bell(); break;
						}
					if (nb == 0) nb = 1;
					Debut();
					pos(ligne,colonne); atb(atbcurcar);
					putch(curcar); Xatb(0); off_cursor();
					rep = (BYTE) toupper(*pcom); pcom++;
					if (rep == 'G') {
#ifdef ver14
						if (txtcons) {
							editor_bell();
							noerr = FALSE;
							}
						else	{
							noerr = getampon((SWORD)nb);
							if (noerr == TRUE) 
								txtchg = TRUE;
							}
#else
						noerr = getampon((SWORD)nb);
#endif
						}
					else if ((rep == 'P') || (rep == 'A')){
					     	keep = FALSE;
					     	if (*pcom == '$') {
							keep = TRUE;
							pcom++;
					     		}
#ifdef ver14
					     	else	{
							if (txtcons) {
								noerr = FALSE; editor_bell();
								on_cursor();
								break;
								}
					     		}
#endif
					     	if (rep == 'P')
							noerr = putampon(TRUE,keep,(SWORD)nb);
						else /* rep == 'A' */
					       		noerr = putampon(FALSE,keep,(SWORD)nb);
#ifdef ver14
					     	if (noerr == TRUE && keep == FALSE) 
							txtchg = TRUE;
#endif
						}
					else	{
						noerr = FALSE; editor_bell();
						}
					on_cursor();
					}
				break;
			case 'B':	/* posit en debut/fin de fichier */
				pos(ligne,colonne); atb(atbcurcar);
				putch(curcar); Xatb(0); off_cursor();
				if (sens == -1) 
					posfin();
				else	posdeb();
				on_cursor(); break;
			case 'L':	/* posit sur une ligne donnee */
				if (nb == 0) {
					noerr = FALSE; editor_bell();
					}
				else	{
					pos(ligne,colonne);
					atb(atbcurcar); putch(curcar);
					editorOnSeek(sens,nb);
					Xatb(0); 
					}
				break;
			case 'W':	/* ecriture d'un fichier */
				if (sens != 0) {
					noerr = FALSE; editor_bell(); break;
					}
				keep = TRUE;

				if ((*pcom =='*') && (*(pcom + 1) == '!')) {
					keep = 2;
					pcom += 2;
					}
				else if (*pcom == '!') {
					keep = FALSE; pcom++;
					}
				nom = pcom;
				if (*nom == EOSTR) {
					editor_bell();
					break;
					}
#ifdef prl3
				while ((*pcom != ESCAPE) && (*pcom != EOSTR) && (*pcom != '\\'))
#else
				while ((*pcom != ESCAPE) && (*pcom != EOSTR))
#endif
					pcom++;

				if (*pcom == ESCAPE) {
					*pcom = EOSTR; flg_esc = TRUE;
					}
				if (nb == 0) nb = 1;
				pos(ligne,colonne);
				atb(atbcurcar); putch(curcar); Xatb(0);
				off_cursor(); noerr = ecrfic(keep,nb,nom);
#ifdef unix
				liberlox(nom);
#endif
				on_cursor();
				break;

#ifndef integre
			case 'C':	/* ecriture d'une corbeille */
				keep = TRUE;

#ifdef ver14
				if ((*pcom == '*') && (*(pcom+1) == '!')) {
					keep = 2;
					pcom += 2;	
					}
				else 
#endif
				  if (*pcom == '!') {
					keep = FALSE; pcom++;
					}
				nom = pcom;
#ifdef prl3
				while ((*pcom != ESCAPE) && (*pcom != EOSTR) && (*pcom != '\\'))
#else
				while ((*pcom != ESCAPE) && (*pcom != EOSTR))
#endif
					pcom++;

				if (*pcom == ESCAPE) {
					*pcom = EOSTR; flg_esc = TRUE;
					}
				pos(ligne,colonne);
				atb(atbcurcar); putch(curcar); Xatb(0);
				off_cursor(); noerr = ecrcor(keep,nom);
#ifdef unix
				liberlox(nom);
#endif
				on_cursor();
				break;
#endif
			case 'Y':	/* lecture d'un fichier */

#ifdef ver14
				if (txtcons) {
					noerr = FALSE; editor_bell(); break;
					}				
#endif
				if (!first) {
					noerr = FALSE; editor_bell(); break;
					}
				nom = pcom;
#ifdef prl3
				while ((*pcom != ESCAPE) && (*pcom != EOSTR) && (*pcom != '\\'))
#else
				while ((*pcom != ESCAPE) && (*pcom != EOSTR))
#endif
					pcom++;

				if (*pcom == ESCAPE) {
					*pcom = EOSTR; flg_esc = TRUE;
					}
				pos(ligne,colonne);
				atb(atbcurcar); putch(curcar); Xatb(0);
				off_cursor(); noerr = lirefic(nom);
#ifdef unix
				liberlox(nom);
#endif

#ifdef ver14				
				if (noerr == TRUE) txtchg = TRUE;
#endif

				on_cursor();
				break;
			case 'N':	/* recherche */
				if (nb == 0) nb = 1;
				nom = pcom;
				if (*pcom == EOSTR || *pcom == ESCAPE) {
					/* recherche chaine vide */

					if (*pcom == EOSTR) editor_bell();
					break;
					}
				while ((*pcom != ESCAPE) && (*pcom != EOSTR))
					pcom++;
				if (*pcom == ESCAPE) {
					*pcom = EOSTR; flg_esc = TRUE;
					}

				pos(ligne,colonne);
				atb(atbcurcar); putch(curcar); Xatb(0);
				pos( ligne, colonne );

				off_cursor(); 
				if (sens == -1) {
					noerr = brecher((SWORD)nb,nom);
					sens = 1; /* Retour Dans le sens */
					}
				else 	{
					noerr = recherche((SWORD)nb,nom);
					}
#ifdef BRUNO
				if (noerr == TRUE) {
					flg_n = 1;

					if (EXTEND_AED) {
						pos(ligne,colonne);
						Xatb(2);
						x_putch(nom[0]);
						Xatb(0);
						}
					pos(ligne,colonne);
					Xatb(0);
					}

#endif
				on_cursor();
				break;
			case 'R':	/* substitution */
#ifdef ver14
				if (txtcons) {
					noerr = FALSE; editor_bell(); break;
					}				
#endif
				if (sens != 0) {
#ifdef ver14
					sens = 0;
#else
					noerr = FALSE; editor_bell(); break;
#endif
					}
				if (nb == 0) nb = 1;
				nom = pcom;

				if (*pcom == EOSTR || *pcom == ESCAPE) {
					/* recherche chaine vide */
					if (*pcom == EOSTR) editor_bell();
					break;
					}

				while ((*pcom != ESCAPE) && (*pcom != EOSTR))
					pcom++;
				if (*pcom == EOSTR) {
					noerr = FALSE; editor_bell(); break;
					}
				*pcom++ = EOSTR; nom2 = pcom;
				while ((*pcom != ESCAPE) && (*pcom != EOSTR))
					pcom++;
				if (*pcom == ESCAPE) {
					*pcom = EOSTR; flg_esc = TRUE;
					}

				pos(ligne,colonne);
				atb(atbcurcar); putch(curcar); Xatb(0);

				off_cursor(); noerr = replace((SWORD)nb,nom,nom2);
#ifdef ver14
				if (noerr == TRUE) txtchg = TRUE;
#endif			
				on_cursor();
				*(nom2 - 1) = ESCAPE;

				break;


			case 'A':	/* substitution */
#ifdef ver14
				if (txtcons || (EXTEND_AED == FALSE)) {
					noerr = FALSE; editor_bell(); break;
					}
#endif
				if (sens != 0) {
#ifdef ver14
					sens = 0;
#else
					noerr = FALSE; editor_bell(); break;
#endif
					}
				if (nb == 0) nb = 1;
				nom = pcom;

				if (*pcom == EOSTR || *pcom == ESCAPE) {
					/* recherche chaine vide */
					if (*pcom == EOSTR) editor_bell();
					break;
					}

				while ((*pcom != ESCAPE) && (*pcom != EOSTR))
					pcom++;
				if (*pcom == EOSTR) {
					noerr = FALSE; editor_bell(); break;
					}
				*pcom++ = EOSTR; nom2 = pcom;
				while ((*pcom != ESCAPE) && (*pcom != EOSTR))
					pcom++;
				if (*pcom == ESCAPE) {
					*pcom = EOSTR; flg_esc = TRUE;
					}
				pos(ligne,colonne);
				atb(atbcurcar); putch(curcar); 
				off_cursor(); 
				/* recherche */
				
				while (nb--) {
					noerr = recherche(1, nom);

					/* confirme */
					if (noerr == TRUE) {
						/* trouve */
						/* BackWord(); */

						/* active le token trouve */
						curcar = getmemchar(ligcur,colcur); 

						if (curcar < 0x0020) {
							if ((curcar == EOSTR) || (curcar == TABUL))
								curcar = ' ';
							else	{
								curcar += 0x0040; atbcurcar = 2;
								}
							}

						pos(ligne,colonne); Xatb(2); 
						putch(curcar);
						pos(ligne, colonne);

						noerr = confirme_lose();
						pos(1,58); atb(21);							

						pos(ligne,colonne);

						/* raz du dernier token */

						i = 0;
						Xatb(0);
						pos(ligne,colonne);

						/* active le token trouve */
						curcar = nom[0];

						if (curcar < 0x0020) {
							if ((curcar == EOSTR) || (curcar == TABUL))
								x_putch(' ');
							else	{
								Xatb(102);
								curcar += 0x0040; atbcurcar = 2;
								x_putch(curcar);
								Xatb(0);
								}
							}
						else	x_putch(curcar);
						pos(ligne, colonne);

					      	if ( noerr == 2) nb = 0;
						else if (noerr == 1 ) {	/* remplace */
							noerr = replace(1,nom,nom2);
						      	}
						}
					else	break;
				 	}
#ifdef ver14
				if (noerr == TRUE) 
					txtchg = TRUE;
#endif			
				on_cursor();
				*(nom2 - 1) = ESCAPE;
				break;

			case 'K':
#ifdef ver14
				if (txtcons) {
					noerr = FALSE; editor_bell(); break;
					}				
#endif
#ifndef ver14
				if (sens != 0) {
					noerr = FALSE; editor_bell(); break;
					}
#else
				sens = 0;
#endif
				if (nb == 0) nb = 1;
				off_cursor(); suplines(nb); on_cursor();
#ifdef ver14
				txtchg = TRUE;
#endif
				break;
#ifdef	VERSION666
			case '=':
				toggle_colour_control(*(pcom++));
				editorOnShow();
				break;
#endif
			case '+':
#ifdef ver21
				if (!first) {
					noerr = FALSE; editor_bell();
					}
				else 
#endif
					sens = 1;
				break;
			case '-':
#ifdef ver21
				if (!first) {
					noerr = FALSE; editor_bell();
					}
				else 
#endif
					sens = (SWORD)	-1;
				break;
			case '$':
#ifdef ver14
				if (!first) {
					noerr = FALSE; editor_bell();
					}
				else
#endif
					nb = MOINS_UN;
				break;

			case EOSTR:
				break;

			default:
				if (isdigit(rep)) {
					nb = (LONG) (cartoint(rep));
					while (isdigit(*pcom)) {
						nb = (LONG) (nb * 10 + cartoint(*pcom));
						pcom++;
						}
					if (nb == 0) {
						noerr = FALSE; /*editor_bell();*/
						}

					if (*pcom == EOSTR) {
						Xstrcat(pcom,"lv");

						}

					}
				else	{
					noerr = FALSE; /*editor_bell();*/
					}
		   	}
		   if (flg_esc) {
			*pcom++ = ESCAPE; flg_esc = FALSE;
			   }
		   if (first == TRUE) {
#ifdef ver21
			if (*pcom == ';' || *pcom == ESCAPE) {
#else
			if (*pcom == ESCAPE) {
#endif
				pcom ++;
				}
			else	{
				first = FALSE;
				}
		   	}

		if (cmdsyst == 0 && coderet == FALSE ) {
		   	curcar = getmemchar(ligcur,colcur); atbcurcar = 0;
		   	if (curcar < 0x0020) {
			   	if ((curcar == EOSTR) || (curcar == TABUL)) {
					curcar = ' ';
			   		}
			   	else	{
					curcar += 0x0040; atbcurcar = 2;
				   	}
			   	}	

		   	if (curcar >= 0x0020) {	
				pos(ligne,colonne);
				Xatb(2); 
				putch(curcar);
				Xatb(0);
		   		}
			}

		}
		while ((*pcom != EOSTR) && noerr);
	}
	while (!retvideo);

	pos(ligne,colonne); 
	atb(atbcurcar); putch(curcar); Xatb(0);
	pos(ligne,colonne);

	return (coderet);
}					/* commande */

void	editorCommandWindow()
{
	commande();
	return;
}

/* Fin du 1 er source */
#ifdef ver14
#ifdef prologue
/* remplace _ngffh */
/*global*/ ngffh(c)
int c;
{
	return(_fcb[c-5].no_logique);
}
#endif
#endif

#include "ednoy2.c"

