
/*        

		Ensemble Integre Version 1.4a, 14b, 21a, 21b


* 24/02/1994 : Correction du bug "Generation Projet" il manquait
la ligne de dependance .s.at

*/
#include <signal.h>
#include "abal.h"
#include "abalmsg.hs"
#include "amouse.c"
#include "abaltool.h"

#define	ABAL_IS_GRAPHIC 2

static BOOL ModeCFG;
static BOOL ModeAPLUS;

static 	int 	boolexa=0;
static	int	flagcico=0;
static	int	fileposition=15;
static  int	projposition=48;
static	int	filecolumns=20;
static	int	projcolumns=20;

static	struct	abal_graphical_context	{
	int	gridfontwidth;
	int	gridfontheight;
	int	textfontwidth;
	int	textfontheight;
	int	textcolour;
	int	washcolour;
	int	backcolour;
	int	textfont;
	int	menufont;
	int	neutral;
	int	menuframe;
	char *	Font2;
	char *	Rgb;
	char *	BackDrop;
	} AGC = { 
		0 , 0, 0, 0,
		27, 28, 21,
		0 , 0, 
		21,
		11, 
		(char *) 0,
		(char *) 0, 
		(char *) 0 
		};


int	panic(int s)
{
	if ( s == SIGKILL )	 s = SIGTERM;
	exit(s);
	return(1);
}

int	cico_is_graphic()
{
	char * eptr;
	if (( eptr = getenv("ABALISTEXT")))
		return(0);
	else if ( flagcico == ABAL_IS_GRAPHIC )
		return(1);
	else	return(0);
}


void	ABAL_INIT_TERM()
{
	int	v;
#ifdef	UNIX
	set_desktop_name("Abal");
	set_desktop_icon("Abal");
#endif
	if ((flagcico = open_console()) == ABAL_IS_GRAPHIC) {
		if ( cico_is_graphic() ) {
			AGC.gridfontwidth  = cico_cell_width();
			AGC.gridfontheight = cico_cell_height();
			AGC.Font2="/home/abal3/fonts/arial2.fmf";
			AGC.Rgb="/home/abal3/images/standard.rgb";
			if (!( AGC.BackDrop = getenv("BACKDROP")))
				AGC.BackDrop="/home/abal3/images/logo.jpg";
			AGC.textfont = visual_font(AGC.Font2,Xstrlen(AGC.Font2));
			AGC.menufont = visual_font(AGC.Font2,Xstrlen(AGC.Font2));
			cicopalette(0,0);
			cicopalette(6,AGC.neutral);
			cicopalette(4,AGC.textcolour);
			cicopalette(15,AGC.washcolour);
			visual_palette(AGC.Rgb,Xstrlen(AGC.Rgb));
			v = guifontsize(AGC.menufont);
			AGC.textfontwidth = (v & 0x00FF);
			AGC.textfontheight= (v  >> 8  );
			}
		filecolumns = projcolumns = (((conf(2)-16)/2)-11);
		fileposition= 15;
		projposition= fileposition+filecolumns+13;
		}
	return;
}

void	ABAL_FIN_TERM()
{
	close_console();
}

static	void	textual_filzone(c,l,nc,nl,colour,mode)
int 	c;
int 	l;
int	nc;
int 	nl;
int 	colour;
int 	mode;
{
	int	atx;
	int	aty;
	int	nbx;
	int	nby;
	atx = (c * AGC.gridfontwidth)+(AGC.gridfontwidth/2);
	aty = (l * AGC.gridfontheight)+(AGC.gridfontheight/2);
	nbx = (nc * AGC.gridfontwidth);
	nby = (nl * AGC.gridfontheight);
	visual_filzone(atx,aty,nbx,nby,colour,mode);
	return;
}

static	void	textual_wilzone(c,l,nc,nl,colour,mode)
int 	c;
int 	l;
int	nc;
int 	nl;
int 	colour;
int 	mode;
{
	int	atx;
	int	aty;
	int	nbx;
	int	nby;
	atx = (c * AGC.gridfontwidth);
	aty = (l * AGC.gridfontheight);
	nbx = (nc * AGC.gridfontwidth);
	nby = (nl * AGC.gridfontheight);
	visual_filzone(atx,aty,nbx,nby,colour,mode);
	return;
}

static	void	textual_cadre(tc,tl,bc,bl)
int 	tc;
int 	tl;
int	bc;
int 	bl;
{
	int	atx;
	int	aty;
	int	nbx;
	int	nby;
	atx = ((tc-1) * AGC.gridfontwidth);
	aty = ((tl-1) * AGC.gridfontheight);
	nbx = (((bc-tc)+1) * AGC.gridfontwidth);
	nby = (((bl-tl)+1) * AGC.gridfontheight);
	visual_filzone(atx,aty,nbx,nby,0,AGC.menuframe);
	return;
}

static	void	textual_message(c,l,fid,fg,bg,mptr,mlen)
int 	c;
int 	l;
int	fid;
int	fg;
int	bg;
char *	mptr;
int	mlen;
{
	int	atx;
	int	aty;
	int	nbx;
	int	nby;
	atx = ((c-1) * AGC.gridfontwidth);
	aty = ((l-1) * AGC.gridfontheight);
	if (!( mlen )) mlen = Xstrlen(mptr);
	nbx = (mlen * AGC.gridfontwidth );
	nby = AGC.gridfontheight;
	visual_text(atx,aty,nbx,nby,fid,fg,bg,mptr,mlen,2);
	return;
}

static	void	textual_backwash(atlin)
int	atlin;
{
	int	atx;
	int	aty;
	int	nbx;
	int	nby;
	atx = 0;
	if ( atlin < 4 )
		atlin = 0;
	else	atlin=4;
	aty = (atlin * AGC.gridfontheight);
	nbx = cico_page_width();
	nby = cico_page_height();
	visual_image(atx,aty,nbx,nby,AGC.BackDrop,4|512);
	return;
}

static	void	textual_button(mptr,mlen,mode)
char *	mptr;
int	mlen;
int	mode;
{
	int	atx;
	int	aty;
	int	nbx;
	int	nby;
	int	c;
	int	l;
	int	fid;
	fid = AGC.menufont;
	c = x_col();
	l = x_lin();
	atx = ((c-1) * AGC.gridfontwidth);
	aty = ((l-1) * AGC.gridfontheight);
	if (!( mlen )) mlen = Xstrlen(mptr);
	nbx = (mlen * AGC.gridfontwidth );
	/* * textsizelen(fid,mptr,mlen); */
	nby = AGC.textfontheight;
	switch ( mode ) {
		case	0	: visual_text(atx,aty,nbx,nby,fid,AGC.textcolour,AGC.backcolour,mptr,mlen,3); break;
		case	1	: visual_text(atx,aty,nbx,nby,fid,AGC.washcolour,AGC.textcolour,mptr,mlen,3); break;
		case	2	: visual_text(atx,aty,nbx,nby,fid,AGC.textcolour,AGC.backcolour,mptr,mlen,1); break;
		case	3	: visual_text(atx,aty,nbx,nby,fid,AGC.washcolour,AGC.textcolour,mptr,mlen,1); break;
		}
	return;
}

static	void	textual_check(mptr,mlen,value,mode)
char *	mptr;
int	mlen;
int	value;
int	mode;
{
	int	atx;
	int	aty;
	int	nbx;
	int	nby;
	int	c;
	int	l;
	int	fid;
	fid = AGC.menufont;
	c = x_col();
	l = x_lin();
	atx = ((c-1) * AGC.gridfontwidth);
	aty = ((l-1) * AGC.gridfontheight);
	if (!( mlen )) mlen = Xstrlen(mptr);
	nbx = (mlen * AGC.gridfontwidth );
	nby = AGC.textfontheight;
	if ( value  )
	 	value = 1;
	else	value = 0;
	switch ( mode ) {
		case	0	: visual_check(atx,aty,nbx,nby,fid,AGC.textcolour,AGC.backcolour,mptr,mlen,value); break;
		case	1	: visual_check(atx,aty,nbx,nby,fid,AGC.washcolour,AGC.textcolour,mptr,mlen,value|2); break;
		}
	return;
}

BINAIRE	lendollar( sptr )
char * sptr;
{
	int	l=0;
	int	i;
	
	for ( i=0,l=0; *(sptr+i) != 0; i++ )
		if ( *(sptr+i) != ' ' )
			l=i+1;
	return(l);
}

static void Print(pt,fcar, maxlargeur)
BYTE XPTR  pt;
BINAIRE fcar;
BINAIRE maxlargeur;
{
	BINAIRE n,largeur;

	if ( cico_is_graphic() ) {
		textual_message( x_col(),x_lin(), AGC.textfont, AGC.textcolour, AGC.backcolour, pt, maxlargeur );
		}
	else	{

		largeur = Xstrlen(pt);

	     	for (n=0; n < largeur; n++) {
			if (*(pt+n) == fcar) {
				if (conf(14) )
					foregr(11);
				else 	Xatb(6);

				x_putch(*(pt+n));
				if (conf(14) )
					foregr(0);
				else 	Xatb(0);
				}
			else x_putch(*(pt+n));
			}
	
		for (; n < maxlargeur; n++) {
			x_putch(' ');
			}
		}
	return;
}

static void XPrint(pt, maxlargeur)
BYTE XPTR  pt;
BINAIRE maxlargeur;
{
	BINAIRE n,largeur;
	if ( cico_is_graphic() ) {
		textual_message( x_col(),x_lin(), AGC.textfont, AGC.backcolour, AGC.textcolour, pt, maxlargeur );
		}
	else	{

		Batb(2);

		largeur = Xstrlen( pt );

		x_cprintf( (BYTE FPTR) pt );

	     	for (n=largeur; n < maxlargeur; n++) {
			x_putch(' ');
			}
		Batb(0);

		}

}

static	void	HoPrint(pt,mode)
BYTE	XPTR	pt;
BYTE		mode;

{
	if ( cico_is_graphic() ) {
		textual_button(pt,0,mode);
		}
	else	{
		Xatb(2); x_cprintf(pt); Xatb(0);
		}
	return;
}

static	void	LoPrint(pt,truc,mode)
BYTE	XPTR	pt;
BYTE		truc;
BYTE		mode;
{
	if ( cico_is_graphic() ) {
		textual_button(pt,0,mode);
		}
	else	{
		Xatb(0); x_cprintf(pt); Xatb(0);
		}
	return;
}

static	void	HoCheck(pt,value,longeur)
BYTE	XPTR	pt;
BOOL		value;
BINAIRE		longeur;
{
	textual_check(pt,longeur,value,1);
}

static	void	LoCheck(pt,value,longeur)
BYTE	XPTR	pt;
BOOL		value;
BINAIRE		longeur;
{
	textual_check(pt,longeur,value,0);
}

main(argc,argv)
int argc;
char *argv[];
{
	BYTE XPTR	p;
#ifdef asfun
	BDA_INIT bdas;
#endif
	ModeCFG = FALSE;
	ModeAPLUS = FALSE;

	initabmes();

	definit();

	init();


#ifdef asfun
#define	OPT	0

  InitRunTime(0,"ASFUN4",OPT,&bdas,sizeof(bdas));

  sf_init("stf");

#endif


	if (argc-- < 2) {
		banniere();
		}


	ini_boite();
	lecconf(nomcfg);

	while (argc--) {
		p = *(++argv);
		if (*p == '-' || *p == '/') {
			if (toupper(*(p+1)) == 'C') {
				if (*(p+2) != EOSTR && *(p+2) != ' ') {
					Xstrcpy(nomcfg, p+2);
					if (!lecconf(nomcfg)) {
						/* erreur de cfg */
						msg_erreur(CFGTM);
					}
				}
				else {
					ModeCFG = TRUE;
					if (nomfic[0] != EOSTR) {
						Xfn_parser((BYTE FPTR) nomfic, (BYTE FPTR) nomcfg, 1 + 2 + 4 + 8);
						Xstrcat(nomcfg,".cfg");
						lecconf(nomcfg);
					}
				}

			}
			else if (toupper(*(p+1)) == 'O') {
/* #BG				ModeAPLUS = TRUE;
				vtropt[0] = TRUE; /* source issus d'aplus */
			}
#ifdef prologue
			else if (*(p+1) == EOSTR) Xstrcpy(nomfic, p);				
#endif
		}
		else {
			Xstrcpy(nomfic, p);
		}
	}

	menugene();

	fin_boite();

	Xunlink(cfgtmp);
#ifdef msdos
	Xunlink("atrtmp");
#endif

#ifdef asfun
	sf_end();
  	FinRunTime(0);
#endif

	final();

}

static void ini_boite()
{

	BINAIRE lgaffi;

	Xstrcpy(nomtmp,inte_msg[LSTFIC]);
	init_boite(&cfic, LGBNOM, 8, 3, 14, 16, 3*LGBNOM+1, 1, (BYTE XPTR) &nomtmp[0]);

	Xstrcpy(nomtmp,inte_msg[LSTREP]);
	init_boite(&crep, LGBNOM, 8, 1, 14, cfic.CB+2, LGBNOM, 1, (BYTE XPTR) &nomtmp[0]);

	lgaffi = crep.CB - 16;

	Xstrcpy(&nomtmp[0], inte_msg[LSTSRC]);
	init_boite(&hissrc, lgaffi, 8, 1, 14, 16, lgaffi,0, (BYTE XPTR) &nomtmp[0]);

	Xstrcpy(&nomtmp[0], inte_msg[LSTPRJ]);
	init_boite(&hismak, lgaffi, 8, 1, 14, 16, lgaffi,0, (BYTE XPTR) &nomtmp[0]);

	Xstrcpy(&nomtmp[0], inte_msg[LSTTRA]);
	init_boite(&histra, lgaffi, 8, 1, 14, 16, lgaffi,0, (BYTE XPTR) &nomtmp[0]);

	Xstrcpy(&nomtmp[0], inte_msg[LSTSYS]);
	init_boite(&hissys, lgaffi, 8, 1, 14, 16, lgaffi,0, (BYTE XPTR) &nomtmp[0]);
}

static void fin_boite()
{
	purge(&cfic);
	purge(&crep);

	purge(&hissrc);
	purge(&hismak);
	purge(&histra);
	purge(&hissys);
	
}

#ifdef HX

static void initabmes()

/*	Initialisation de la table des messages
 */

{					/* initabmes */
	char *p;
	int	i;
	BOOL	other;

	other = FALSE;

	p = &mentete[0][0];
	for (i = 0 ; i < 2 ; i++) {	/* saute en-tete GESMES et O/N */
		if (i == 1) {
			ryes = tolower(*p);
			rno = tolower(*(p+1));
			if (*(p+2) == '1') {
				other = TRUE;
				break;
				}
			}
		p += Xstrlen(p)+1;
		while (*p == EOSTR)
			p++;
		}
	if (other == TRUE) {
		p = &oentete[0][0];
		for (i = 0 ; i < 2 ; i++) {	/* saute en-tete GESMES et O/N */
			if (i == 1) {
				ryes = tolower(*p);
				rno = tolower(*(p+1));
				if (*(p+2) == '1') {
					other = TRUE;
					break;
					}
				}
			p += Xstrlen(p)+1;
			while (*p == EOSTR)
				p++;
			}
		}	

	for (i = 0 ; i < NBINTMES ; i++) {
		inte_msg[i] = p;
		p += Xstrlen(p) + 1;
		while (*p == EOSTR)
			p++;
		}
}					/* initabmes */

#else

static void initabmes()

/*	Initialisation de la table des messages
 */

{					/* initabmes */
	BYTE XPTR	p;
	int	i;
	BOOL	other;


	other = FALSE;

	p = &mentete[0];
	for (i = 0 ; i < 2 ; i++) {	/* saute en-tete GESMES et O/N */
		if (i == 1) {
			if (*(p+2) == '1') {
				other = TRUE;
				break;
			}
		}
		p += Xstrlen(p)+1;
		while (*p == EOSTR)
			p++;
	}

	if (other == TRUE) {
		p = &oentete[0];
		for (i = 0 ; i < 2 ; i++) {	/* saute en-tete GESMES et O/N */
			if (i == 1) {
				if (*(p+2) == '1') {
					other = TRUE;
				}
			}
			p += Xstrlen(p)+1;
			while (*p == EOSTR)
				p++;
		}
	}

	for (i = 0 ; i < NBINTMES ; i++) {
		inte_msg[i] = p;
		p += Xstrlen(p) + 1;
		while (*p == EOSTR)
			p++;
	}

	ryes = tolower(ouinon[0]);
	rno  = tolower(ouinon[1]);
}					/* initabmes */
#endif

static void banniere()

/*	edition de la banniere
 */
{					/* banniere */

#ifndef asfun

	BINAIRE i, j, li,lgn,atl,atc,nbc;
	BOOL wbool, wfin;
	BYTE	c;
	
	/* Nouvelle presentation */
	Xatb(0);
	atl = (conf(1)-14)/2;
	nbc = Xstrlen(copyright);
	atc = (conf(2)-nbc)/2;
	if( cico_is_graphic() ) {
		cadre(atl-1,atc-2,atl+14,atc+nbc+1);
		}
	lgn = (conf(2)-Xstrlen(ban[0])) / 2;
	wfin = 0;
	while (wfin < 2) {
		x_bstart();
		li = (atl+1); wbool = 1;

		pos(li++, lgn);
		for (i=0; i < NB_BAN; ) {
			for (j=0; j < LG_BAN; ) {
				if (ban[i][j] == ' ') {
					if (wbool == 1) {
						wbool = 0;
						c = CAR_FON;
#if unix || vms
						if (wfin == 0) 
							Xatb(0);
						else 
							Xatb(2);
#endif
						}
					}
				else 	{
					if (wbool == 0) {
						wbool = 1;
						c = CAR_DEV;
#if unix || vms
						if (wfin == 0) {
							Xatb(2);
							}
						else
							Xatb(0);
#endif
						}
					}
				x_putch((BYTE) c);
				j++;
				}
			pos(li++, lgn);
			i++;
			}
		x_bflush();
		wfin ++;
		}

	x_bstart();
	Xatb(0);
	atl+=10;
	nbc = Xstrlen(inte_msg[messages[titre]]);
	atc = (conf(2)-nbc)/2;
	pos(atl++, atc );
	x_cprintf((BYTE FPTR) inte_msg[messages[titre]]);
	pos(atl,atc); x_cprintf((BYTE FPTR)"                                   ");
	pos(atl++,atc+9); x_cprintf((BYTE FPTR)inte_msg[messages[vers]]); 
	x_putch(vabal); x_putch('.'); x_putch(iabal); x_putch(rabal); x_cprintf((BYTE FPTR)nabal);
	x_cprintf((BYTE FPTR)pabal);
	if( cico_is_graphic() ) {
		pos(atl,(conf(2) - Xstrlen(copyright))/2); x_cprintf((BYTE FPTR)copyright);
		}
	else	{
		pos(conf(1)-1,(conf(2) - Xstrlen(copyright))/2); x_cprintf((BYTE FPTR)copyright);
		}
	x_bflush();

#else 
#endif
	attendre();
	Xclear(4,1);
}					/* banniere */

static void attendre()
/*	afficher un message a la position 'l,c' , et attendre
 *	la frappe d'une touche au clavier
 */
{					/* attendre */
	int l,c,lg;
	int	ret;
	int	atl;
	x_bstart();
	lg = Xstrlen(inte_msg[messages[msgwait]]);
	if ( cico_is_graphic() ) {
		atl = (conf(1)-2);
		cadre(atl,1,atl+2,conf(2));
		pos(atl+1, (conf(2)-lg) / 2);
		}
	else	{
		pos(conf(1),1);
		Xatb(2);
		Xatb(21);
		pos(conf(1) , (conf(2)-lg) / 2);
		}
	x_cprintf((BYTE FPTR)inte_msg[messages[msgwait]]);
	x_bflush();
	ret = xx_getch();
	if (!( cico_is_graphic() )) {
		x_bstart();
		pos(conf(1) , 1); Xatb(21);
		Xatb(0);
		x_bflush();
		}
	else	Xclear(5,1);	
}					/* attendre */

static int pause()
/*	afficher un message a la position 'l,c' , et attendre
 *	la frappe d'une touche au clavier
 */
{					/* pause */
	int l,c,lg;
	int	atl;
	int ret;
	x_bstart();
	lg = Xstrlen(inte_msg[LIBPAU]);
	if ( cico_is_graphic() ) {
		atl = (conf(1)-2);
		cadre(atl,1,atl+2,conf(2));
		pos(atl+1, (conf(2)-lg) / 2);
		}
	else	{
		pos(conf(1),1);
		Xatb(2);
		Xatb(21);
		pos(conf(1) , (conf(2)-lg) / 2);
		}
	x_cprintf((BYTE FPTR) inte_msg[LIBPAU]);
	x_bflush();
	ret = xx_getch();
	if (!( cico_is_graphic() )) {
		x_bstart();
		pos(conf(1) , 1); Xatb(21);
		Xatb(0);
		x_bflush();
		}
	else	Xclear(5,1);	
	return(ret);	
}					/* attendre */

static void menugene ()

/*	menu general de l'ensemble integre
 *	cette fonction active le module concerne en fonction
 *	du choix de l'utilisateur
 */
{					/* menugene */
	BINAIRE	rep;
	int	next;
	BOOL	fini = FALSE,chaine = 4; /* 4 force l'enetete de hmenu */

	if (wrep == 0) {
		if (nomfic[0] == EOSTR) {
			rep = 0;
			}
		else 	{
			rep = 1;
			}
		}
	else 	{
		rep = wrep;
		}

	do 	{
		boolESC = 0;	/* Remise a 0 du boolean */
		switch((rep = hmenu(chaine,rep,&ogene[0],hgene))) {
			case 0:	/* Projet */
				next = projet(); break;
			case 1:	/* edition */
				next = edition(); break;
			case 2:	/* traduction */
				next = generer(); break;
			case 3:	/* Moniteur */
				next = executer(); break;
			case 4:	/* Utilitaires */
				next = util(); break;
			case 5:	/* Configuration */
				next = config(); break;
			case 6:	/* Fin */
				next = arreter();
				if (next == -2) {
					FILLOUT;	
					fini = TRUE;
					}
				break;
			}
		if (fini == FALSE) {
			switch (next) {
				case 0:	chaine = FALSE; break;
				case -1: chaine = TRUE;
					 if (rep != 0) rep--;
					 else	       rep = 6;
					 break;
				case 1: chaine = TRUE;
					 if (rep != 6) rep++;
					 else	       rep = 0;
					 break;
				case 2: chaine = 2; break;
				case 3: chaine = 3;
					if (rep != 6) rep ++;
					else 		rep = 0;
					break;
				case 5: chaine = 5; break;
				}
			}
		}
	while (fini == FALSE);
}					/* menugene */

static int projet()
{
	int rep;

	while (1) {
		rep = vmenu(5,tpos[0]-1,6,coprojet,oprojet,hprojet);
		if (rep == -1) {
			 Xclear(5,tpos[0]-1); 
			 return(0);
		}
		if (rep == -2) {
			Xclear(5,tpos[0]-1); 
			return (1);
		}
		if (rep == -3) {
			Xclear(5,tpos[0]-1); 
			return (MOINS_UN);
		}
		if (rep == -4) {

		}
		if (rep >= 20) {
			coprojet = (BINAIRE) rep - 20;
			Xbell(); /* tab n'a pas de sens */
		}
		else if (rep >= 0) {

			coprojet = (BINAIRE) rep;

			/* envoie la boite de selection */
			switch (rep) {
				case 0 : /*selection fichier courant */

					MakeNom(REPS,"*",EXTS,reptmp);
					rep = boite(10,16,nomfic,reptmp,&hissrc,&cfic,&crep,inte_msg[SELEC]);
					if (rep == -5) {
						Xclear(5,1); 
						boolESC = TRUE;
					}
					if (rep >= 0) {
						affnomfic();
						boolcfg = FALSE;
					}
					if ( ModeCFG == TRUE && rep >= 0 ) {
						Xfn_parser((BYTE FPTR) nomfic, (BYTE FPTR) tmp, 1+2+4+8);
						Xstrcat( tmp, ".cfg");
						FindFile( tmp, nomtmp);

						nomprj[0] = EOSTR;
						lstmod[0] = EOSTR;

						if ( nomtmp[0] != EOSTR) {
							Xstrcpy( nomtmp, nomfic);
							lecconf( tmp );
							Xstrcpy( nomfic, nomtmp );
						}

						Xstrcpy( nomcfg, tmp );

						Xfn_parser((BYTE FPTR) nomfic, (BYTE FPTR) tmp, 1+2+4+8);
						Xstrcat( tmp, EXTPRJ);
						Xstrcpy( nomprj , tmp );

						affprj();					

					}
					Xclear(5,1); 
					break;

				case 1 : /* liste module */
					liste_mod();
					break;

				case 2  : /* creation de projet */

					if ( nomprj[0] == EOSTR ) {
						Xfn_parser( (BYTE FPTR) nomfic, (BYTE FPTR) nomprj, 8 );
					}

					rep = ask(10,tpos[0]+1,LGAFF,LGARGU, nomprj);

					if (rep == -5) {
						Xclear(5,1); 
						boolESC = TRUE;
					}

					if ( rep >= 0 ) {
						create_prj();
						affprj();
					}

					/* cfg modifie */
					if (rep > 0) boolcfg = FALSE;

					break;

				case 3 :  /* ouverture projet */
					MakeNom(REPS,"*",EXTPRJ,reptmp);

					rep = boite(10,16,nomprj,reptmp,&hismak,&cfic,&crep,inte_msg[SELEC]);
					if (rep == -5) {
						Xclear(5,1);
						boolESC = TRUE;
					}

					affprj();

					/* cfg modifie */
					if (rep > 0) boolcfg = FALSE;

					break;


				case 4 : /* edition du projet */
					if (nomprj[0] == EOSTR) Xbell();
					else {
						MakeNom(&REPS[0], &nomprj[0], &EXTPRJ[0], &edittmp[0]);
						return(editer(vaedopt,edittmp));
					}	
					break;

				case 5 :  /* fermeture du projet */
					nomprj[0] = EOSTR;
					affprj();
					/* cfg modifie */
					boolcfg = FALSE;
					break;
			}
				
			Xclear(5,tpos[0]-1); 
		}
	}
}

static void liste_mod()
{
	int rep;

	BYTE XPTR pt;

	rep = ask(9,tpos[0]+1,LGAFF,LGARGU,lstmod);
	if (rep == -5) {
		Xclear(5,1); 
		boolESC = TRUE;
	}

	/* cfg modifie */
	if (rep > 0) boolcfg = FALSE;


	/* remplir l'historique avec les modules sans extentions  */
	

	pt = &lstmod[0];
	NextOpt( &pt, tmp );
	while ( tmp[0] ) {
		Xfn_parser((BYTE FPTR) tmp, (BYTE FPTR) nomtmp, 16);
		if (nomtmp[0] == EOSTR) {
			/* mettre le module dans l'historique des sources */
			MakeNom(&REPS[0], &tmp[0], &EXTS[0], &nomtmp[0]);
			liste_histo(&hissrc, &nomtmp[0]);
		}
		NextOpt( &pt, tmp );
	}

	Xclear(5,1); 

	return;
}


static int edition()
{
	int rep;

	while (1) {
		rep = vselect(5,tpos[1]-1,4,coedit,oedit,vaedopt,hedit);
		if (rep == -1) {
			Xclear(5,tpos[1]-1); return(0);
			}
		if (rep == -2) {
			Xclear(5,tpos[1]-1); return (1);
			}
		if (rep == -3) {
			Xclear(5,tpos[1]-1); return (MOINS_UN);
			}

		if (rep >= 0) {
			if (rep >= 20) { /* demande d'un autre fichier */
				rep -= 20;

				MakeNom(REPS,"*",EXTS,reptmp);
				rep = boite(10,16,&nomtmp[0],reptmp,&hissrc,&cfic,&crep,inte_msg[SELEC]);
				if (rep == -5) {
					Xclear(5,1); 
					boolESC = TRUE;
					}
				if (rep >= 0) {
/*
					boolcfg = FALSE;
*/
					
					MakeNom(&REPS[0], &nomtmp[0], &EXTS[0], &edittmp[0]);
					rep = editer(vaedopt, edittmp);

					if (rep != 5)
						return(rep);
					}
				}
			else 	{
				if (rep > 0) boolcfg = FALSE;
				MakeNom(&REPS[0], &nomfic[0], &EXTS[0], &edittmp[0]);
				rep = editer(vaedopt, edittmp);
				if (rep != 5)
					return(rep);
				}
			}
		}
}

static int editer(ledit,nomedit)
BOOL ledit[];
BYTE XPTR nomedit;
{
	char ret,i,j;
	BYTE XPTR p;

	if (nomedit[0] == EOSTR) {
		msg_erreur(NOSRC);
		return(5);
	}
	else {
		Xstrcpy(param," ");
		if (ledit[3]) {
			/* AED personnalise */
			Xstrcat(param,DELIMOPT);
			Xstrcat(param,"c");
			Xstrcat(param,cfgtmp);
			Xstrcat(param," ");
		}

		if (ledit[0]) {
			/* edition en mode trace */
			Xstrcat(param,DELIMOPT);
			Xstrcat(param,"t");

			Xfn_parser((BYTE FPTR) nomedit, (BYTE FPTR) &edit_tmp[0], 1+2+4+8+16+32);
			MakeNom(&REPS[0], &edit_tmp[0], &EXTS[0], &param[Xstrlen(param)]);
/*
			Xfn_parser((BYTE FPTR) nomedit,(BYTE FPTR) &param[Xstrlen(param)],1+2+4+8);
			MakeNom(&REPS[0], &edit_tmp[0], &EXTS[0], &param[Xstrlen(param)]);
*/
		}
		else {
/*
			Xfn_parser((BYTE FPTR) nomedit, (BYTE FPTR) &edit_tmp[0], 1+2+4+8+16+32);
			MakeNom(&REPS[0], nomedit, &EXTS[0], &param[Xstrlen(param)]);
*/
			Xstrcat(param,nomedit);

		}

		if (ledit[1]) {
			/* edition en read_only */
			Xstrcat(param," ");
			Xstrcat(param,DELIMOPT);
			Xstrcat(param,"r ");
		}
		if (!ledit[2]) {
			/* edition sans fichier de sauvegarde */
			Xstrcat(param," ");
			Xstrcat(param,DELIMOPT);
			Xstrcat(param,"b ");
		}

		MakeNom(REPB,AbalToolAed,"",&prog[0]);

#if msdos || prologue
		Xset_filler( FALSE );
#endif


		ret = run(prog,param);

#if msdos || prologue
	Xset_filler( TRUE );
#endif


		Xclear(1,1);

		if (ret == 5) {
			return(5);
		}
		else {
			return(2);
		}
	}
}

static generer()
{
	int rep,ret;

	BYTE modtmp[LGARGU];
	BYTE fictmp[LGARGU];
	BYTE XPTR pt;
	
	BOOL locoptobj[9];
	char vlocoptobj;

	BOOL locopttr[11];
	char vlocopt;


	int i;
	int debcol, lgopt;
	
	lgopt = Xstrlen(inte_msg[stropt[0]]) + 3;
/*
	debcol = (tpos[2] + Xstrlen(inte_msg[ogener[0]])/2) - lgopt/2;
*/
	debcol = (tpos[2] + Xstrlen(inte_msg[ogener[0]])/2) ;

	/* recupere les options globales pour les options locales de atr */
/* #BG	for (i=0; i < 11; i++) locopttr[i] = vtropt[i];*/
	for (i=0; i < 9; i++) locopttr[i] = vtropt[i];
	vlocopt = coptoptr;

	/* recupere les options globales pour les options locales de ao */
/* #BG	for (i=0; i < 4; i++) locoptao[i] = voptao[i];
	clocoptao = coptao;
*/
	/* recupere les options globales pour les options locales de aplus */
/* #BG	for (i=0; i < 10; i++) locoptobj[i] = vacti[i];
	vlocoptobj = eacti;
*/
	modtmp[0] = 0;

	while (1) {
/* #BG		rep = vmenu(5,tpos[2]-1,5,cogener,ogener,hgener);*/
		rep = vmenu(5,tpos[2]-1,3,cogener,ogener,hgener);
		if (rep == -1) {
			Xclear(5,tpos[2]-1); return(0);
		}
		if (rep == -2) {
			Xclear(5,tpos[2]-1); return (1);
		}
		if (rep == -3) {
			Xclear(5,tpos[2]-1);  return (-1);
		}
		if (rep >= 0) {
			if (rep >= 20) 	cogener = rep - 20;
			else 		cogener = (BINAIRE) rep;
			if (cogener == 0) {
				if (rep >= 20) {
					argtmp[0] = EOSTR;
					MakeNom(REPS,"*",EXTPRJ,reptmp);
					rep = boite(10,16,argtmp,reptmp,&hismak,&cfic,&crep,inte_msg[SELEC]);					
					if (rep == -5) {
						Xclear(5,1); 
						boolESC = TRUE;
					}
					if (rep >= 0) {
						
						rep = affmenu(5,tpos[2]-1,5,cogener,ogener,hgener);
						/* projet */
						do {
							rep  = vselect(5 + cogener + 2, tpos[2] + 2 ,6, coptam, loptam, voptam, hoptam);
				
						}
						while (rep == -2 || rep == -3 || rep >= 20);

						Xclear(5,1);
						if (rep >= 0) {
							coptam = rep;
							return(miseajour(argtmp));
						}
					}
				}
				else {
					/* projet */
					do {
						rep  = vselect(5 + cogener + 2, tpos[2] + 2 ,6, coptam, loptam, voptam, hoptam);
				
					}
					while (rep == -2 || rep == -3 || rep >= 20);

					Xclear(5,1);
					if (rep >= 0) {
						coptam = rep;
						return(miseajour(nomprj));
					}

				}
			}
/* #BG
			else if (cogener == 1) { 
				if (rep >= 20) {
					argtmp[0] = EOSTR;
					MakeNom(REPS,"*",EXTS,reptmp);
					rep = boite(10,16,argtmp,reptmp,&hissrc,&cfic,&crep,inte_msg[SELEC]);					
					if (rep == -5) {
						Xclear(5,1); 
						boolESC = TRUE;
					}
					if (rep >= 0) {
						// objet
						rep = affmenu(5,tpos[2]-1,5,cogener,ogener,hgener);
						do {
							rep  = vselect(5 + cogener + 2, tpos[2] + 2 ,10, eacti, lacti, locoptobj, hacti);
				
						}
						while (rep == -2 || rep == -3 || rep >= 20);

						Xclear(5,1);
						if (rep >= 0) {
							vlocoptobj = rep;
							rep = aplus( locoptobj, locopttr, locoptao, argtmp);


						}
					}
				}
				else {
					// objet
					do {
						rep  = vselect(5 + cogener + 2, tpos[2] + 2 ,10, eacti, lacti, locoptobj, hacti);
				
					}
					while (rep == -2 || rep == -3 || rep >= 20);

					Xclear(5,1);
					if (rep >= 0) {
						vlocoptobj = rep;
						rep = aplus( locoptobj, locopttr, locoptao, nomfic);
					}
				}
				if (rep == 2) return(rep);	// reafficher l'entete
			}
			else if (cogener == 2) { 
*/
			else if (cogener == 1) { 
				if (rep >= 20) {
					argtmp[0] = EOSTR;
					MakeNom(REPS,"*",EXTS,reptmp);
					rep = boite(10,16,argtmp,reptmp,&hissrc,&cfic,&crep,inte_msg[SELEC]);					
					if (rep == -5) {
						Xclear(5,1); 
						boolESC = TRUE;
					}
					if (rep >= 0) {
						/* options locales de atr */
						rep = affmenu(5,tpos[2]-1,5,cogener,ogener,hgener);
						do 	{
/* #BG							rep = vselect(5+cogener+2, tpos[2] + 2,11,vlocopt,stropt,locopttr,htropt);*/
							rep = vselect(5+cogener+2, tpos[2] + 2,9,vlocopt,stropt,locopttr,htropt);
							}
						while (rep == -2 || rep == -3 || rep >= 20);
						Xclear(5,1);
						if (rep >= 0) {
							vlocopt = rep;
							if (( rep = traduction(locopttr,argtmp)) >= 0 )
								if ( AbalToolVersion == 3 )
									rep=2;
							}
						}
					}
				else 	{
					/* options locales de atr */
					do {
/* #BG						rep = vselect(5+cogener+2, tpos[2] + 2,11,vlocopt,stropt,locopttr,htropt);*/
						rep = vselect(5+cogener+2, tpos[2] + 2,9,vlocopt,stropt,locopttr,htropt);
					}
					while (rep == -2 || rep == -3 || rep >= 20);
					Xclear(5,1);
					if (rep >= 0) {
						vlocopt = rep;
						rep = traduction(locopttr,nomfic);
					}
				}
				if (rep == 2) return(rep);	/* reafficher l'entete */
			}
/* #BG			else if (cogener == 3) {*/
			else if (cogener == 2) {
				/* message d'attente */
				if (rep >= 20) {

					argtmp[0] = EOSTR;
/*
#ifdef buf_cico
	x_bstart();
#endif

					cadre(5+cogener+2,tpos[2]+ 2, 5 + cogener + 2 + 2, tpos[2] + 2 + 2 + LGAFF + 2 + 1);
#ifdef buf_cico
	x_bflush();
#endif
*/
					rep = ask(5+cogener+3,tpos[2]+3,LGAFF,LGARGU, modtmp);

					if (rep == -5) {
						Xclear(5,1); 
						boolESC = TRUE;
					}
					
					if (rep >= 0) {
						/* le premier module est le nom de fichier */
						pt = &modtmp[0];
						fictmp[0] = EOSTR;
						NextOpt(&pt, &fictmp[0]);

						/* ald */
						rep = affmenu(5,tpos[2]-1,5,cogener,ogener,hgener);
						do {
							rep  = vselect(5 + cogener + 2, tpos[2] + 2 ,1, coptald, loptald, voptald, hoptald);
						}
						while (rep == -2 || rep == -3 || rep >= 20);

						Xclear(5,1);
						if (rep >= 0) {
							coptald = rep;
							rep = linker(fictmp, pt);
							Xclear(5,1);
						}
					}
					else {
						Xclear(5,1);
					}

				}
				else 	{
					/* ald */
					do {
						rep  = vselect(5 + cogener + 2, tpos[2] + 2 ,1, coptald, loptald, voptald, hoptald);
					}
					while (rep == -2 || rep == -3 || rep >= 20);

					Xclear(5,1);
					if (rep >= 0) {
						coptald = rep;
						rep = linker( nomfic, lstmod );
						Xclear(5,1); 
					}
				}
				if (rep == 2) return(rep);	/* #BG reafficher l'entete */
			}
/* #BG
			else if (cogener == 4) {
				// message d'attente
				if (rep >= 20) {
					argtmp[0] = EOSTR;
					MakeNom(REPT,"*",EXTT,reptmp);
					rep = boite(10,16,argtmp,reptmp,&histra,&cfic,&crep,inte_msg[SELEC]);					
					if (rep == -5) {
						Xclear(5,1); 
						boolESC = TRUE;
						return(0);
					}
					if (rep >= 0) {
						// ao
						rep = affmenu(5,tpos[2]-1,5,cogener,ogener,hgener);
						do {
							rep  = vselect(5 + cogener + 2 , tpos[2] + 2,4,coptao,loptao,voptao,hoptao);
						}
						while (rep == -2 || rep == -3 || rep >= 20);

						Xclear(5,1);
						if (rep >= 0) {
							clocoptao = rep;
							rep = ao(locoptao, argtmp );
						}
					}
					else Xclear(5,1);
				}
				else {
					// ao
					do {
						rep  = vselect(5 + cogener + 2 , tpos[2] + 2,4,coptao,loptao,voptao,hoptao);
					}
					while (rep == -2 || rep == -3 || rep >= 20);

					Xclear(5,1);
					if (rep >= 0) {
						clocoptao = rep;
						rep = ao(locoptao, nomfic);
					}
				}
				if (rep == 2) return(rep);	// reafficher l'entete
			}
*/
			else {
				attendre();
				Xclear(5,1);
				return(0);
			}
		}
	}
}
	
static int miseajour(nom)
BYTE XPTR nom;
{

	int ret;
	BYTE XPTR pt;

	if (nom[0] == EOSTR) {
		msg_erreur(NOSRC);
		return(5);
	}

	MakeNom(&REPB[0],AbalToolAmake,"",&prog[0]);
	MakeNom(&REPS[0],nom,&EXTPRJ[0],&nomtmp[0]);


	param[0] = EOSTR;
#ifdef essai
	MakeReper(&REPS[0], tmp);
	if (tmp[0] != EOSTR && Xstrlen(param) + Xstrlen(tmp) + 1 < LGREP) {
		Xstrcat(param,tmp);
	}
	else	Xstrcat(param,"\"\"");

	Xstrcat(param," ");

	MakeReper(&REPI[0], tmp);
	if (tmp[0] != EOSTR && Xstrlen(param) + Xstrlen(tmp) + 1 < LGREP)  {
		Xstrcat(param,tmp);
	}
	else	Xstrcat(param,"\"\"");

	Xstrcat(param," ");

	MakeReper(&REPM[0], tmp);
	if (tmp[0] != EOSTR && Xstrlen(param) + Xstrlen(tmp) + 1 < LGREP)  {
		Xstrcat(param,tmp);
	}
	else	Xstrcat(param,"\"\"");

	Xstrcat(param," ");

	MakeReper(&REPT[0], tmp);
	if (tmp[0] != EOSTR && Xstrlen(param) + Xstrlen(tmp) + 1 < LGREP)  {
		Xstrcat(param,tmp);
	}
	else	Xstrcat(param,"\"\"");
	Xstrcat(param," ");

	MakeReper(&REPB[0], tmp);
	if (tmp[0] != EOSTR && Xstrlen(param) + Xstrlen(tmp) + 1 < LGREP)  {
		Xstrcat(param,tmp);
	}
	else	Xstrcat(param,"\"\"");
	Xstrcat(param," ");

	pt = &lstdef[0];		
	NextOpt(&pt,&tmp[0]);
	if (tmp[0] != EOSTR) {
		/* liste des defines */
		while (1) {
			if (tmp[0] != EOSTR && Xstrlen(param) + Xstrlen(tmp) + 1 < LGREP) {
				Xstrcat(param,tmp);
				Xstrcat(param, " ");
			}
			NextOpt(&pt,&tmp[0]);
			if (tmp[0] == EOSTR) break;
		}
	}
#endif


	if (voptam[0]) Xstrcat(param,"b");
	if (voptam[1]) Xstrcat(param,"i");
	if (voptam[2]) Xstrcat(param,"d");
	if (voptam[3]) Xstrcat(param,"t");
	if (voptam[4]) Xstrcat(param,"n");
	if (voptam[5]) Xstrcat(param,"d");
	if ( param[0] ) {
		Xstrcat(prog," ");
		Xstrcat(prog, DELIMOPT);
		Xstrcat(prog,param);
	}

	if (nom[0] != EOSTR) {
		Xstrcat(prog," ");
		Xstrcat(prog, nomtmp);
	}

	if (Xstrlen(prog) >= LGCOM) prog[LGCOM] = EOSTR;

	Xclear(5,1);
#ifdef buf_cico
	x_bstart();
#endif
	 atb(0); atb(26);
#ifdef buf_cico
	x_bflush();
#endif

#ifdef prologue
	if (!ecrconf(cfgtmp)) {
		msg_erreur(CFGTM);
		return(2);
	}
#endif

	rest_tfp();

	Xclear(5,1);	
	FILLOUT;

	ret = Xsystemd((BYTE FPTR) prog,18,conf(1),1);
	if (ret != VAL_RET) {
#ifdef msdos
		if (ret == 40) ret = MOINS_UN;
#endif
#ifdef prologue
		if (Xsystemr()) ret = MOINS_UN;
#endif
		if (ret < VAL_RET) {
			msg_erreur(NOTFIND);
		}
		else	{
			msg_erreur(WARNI);
		}
	}
	else 	attendre();

	init_tfp();

	 Xatb(25);

	 FILLIN;

#ifdef prologue
	if (!lectfp(cfgtmp)) return(MOINS_UN);
#endif
	return(2);
}

#ifdef OBJET	/* #BG */
static int aplus(lobjopt, ltropt, laoopt, nom)
BOOL lobjopt[];
BOOL ltropt[];
BOOL laoopt[];
BYTE XPTR nom;
{
	FILE * fc;
	BOOL ledit[4];

	char ret;
	BYTE XPTR pt;

	if (nom[0] == EOSTR) {
		msg_erreur(NOSRC); //  pas la traduction
		return(5);
	}

	Xclear(5,1); 
	Xstrcpy(&param[0],DELIMOPT);
	Xstrcat(&param[0],"h1");

	if (!lobjopt[0] && ( lobjopt[7] == FALSE || lobjopt[8] == FALSE ) ) Xstrcat(param,"c");
	if (!lobjopt[1]) Xstrcat(param,"q");
	if (lobjopt[2]) Xstrcat(param,"g");
	if (lobjopt[3]) Xstrcat(param,"w");
	if (lobjopt[4]) Xstrcat(param,"e");
	if (lobjopt[5]) Xstrcat(param,"x");
	if (lobjopt[6]) Xstrcat(param,"y");


	/* recuperation du traducteur */
	if (lobjopt[0]) {
		if (ltropt[1]) Xstrcat(param,"m");
		if (ltropt[7]) Xstrcat(param,"a");
		if (ltropt[8]) Xstrcat(param,"b");

		if (laoopt[1]) Xstrcat(param,"o");
		if (laoopt[2]) Xstrcat(param,"2");
		else if (laoopt[3]) Xstrcat(param,"3");

		if (laoopt[0]) {
			Xstrcat(param, " ");
			Xstrcat(param, DELIMOPT );
			Xstrcat(param, "w ");
		}
	}

	/* nom device */
	if (swapunit[0] != EOSTR) {
		Xstrcat(param,DELIMOPT);
		Xstrcat(param,"u");
		Xstrcat(param, swapunit);
	}

	/* define */
	/*  liste des classes */
	if (lobjopt[8]) {
		Xstrcat(param,DELIMOPT);
		Xstrcat(param,"k");
		Xfn_parser((BYTE FPTR) nom, (BYTE FPTR) tmp, 1+2+4+8); 
		MakeNom(&REPS[0],tmp,".apc",&param[Xstrlen(param)]);
	}

	if ( REPB[0] ) {
		/* atr */
		Xstrcat(param," ");
		Xstrcat(param, DELIMOPT);
		Xstrcat(param,"tt");
		MakeReper(&REPB[0],&param[Xstrlen(param)]);
		Xstrcat(param,AbalToolAtr);

		/* ald */
		Xstrcat(param," ");
		Xstrcat(param, DELIMOPT);
		Xstrcat(param,"tl");
		MakeReper(&REPB[0],&param[Xstrlen(param)]);
		Xstrcat(param,AbalToolAld);

		/* aed */
		Xstrcat(param," ");
		Xstrcat(param, DELIMOPT);
		Xstrcat(param,"te");
		MakeReper(&REPB[0],&param[Xstrlen(param)]);
		Xstrcat(param,AbalToolAed);

		/* ao */
		Xstrcat(param," ");
		Xstrcat(param, DELIMOPT);
		Xstrcat(param,"to");
		MakeReper(&REPB[0],&param[Xstrlen(param)]);
		Xstrcat(param,AbalToolAo);

		Xstrcat(param," ");
	}


	if (ltropt[2]) {
		Xstrcat(param,DELIMOPT);
		Xstrcat(param,"l");
		MakeReper(&REPS[0], &param[Xstrlen(param)]);

		Xfn_parser((BYTE FPTR) nom,(BYTE FPTR) &param[Xstrlen(param)],8);
		Xstrcat(param,&EXTL[0]);
#ifdef prologue
		Xfn_parser((BYTE FPTR) nom,(BYTE FPTR) &param[Xstrlen(param)],32);
#endif
		Xstrcat(param," ");
	}

	/* repertoire de destination */
	
	if (REPT[0] != EOSTR) {
		Xstrcat(param," ");
		Xstrcat(param,DELIMOPT);
		Xstrcat(param,"d");

		MakeReper(&REPT[0], &param[Xstrlen(param)]);

		Xfn_parser((BYTE FPTR) nom,(BYTE FPTR) &param[Xstrlen(param)],8+32);
		Xstrcat(param," ");
	}

	/*  construction d'une librairie */
	if (lobjopt[9]) {
		/* c'est librairie ou pre-process */	
		/* on reconstruit la ligne d'options */
		Xstrcpy(&param[0],DELIMOPT);
		Xstrcat(&param[0],"h1");

		Xstrcat(param,DELIMOPT);
		Xstrcat(param,"p");

		Xfn_parser((BYTE FPTR) nom, (BYTE FPTR) tmp, 1+2+4+8); 
		MakeNom(&REPS[0],tmp,".apl",&param[Xstrlen(param)]);
	}	

	/* extension par defaut */
	if ( EXTS[1] ) {
		Xstrcat( param, DELIMOPT );
		Xstrcat( param, "s");
		Xstrcat( param, &EXTS[1]);
	}

	/* repertoire des includes */
	pt = &REPI[0];		
	NextOpt(&pt,&tmp[0]);

	/* liste des includes */
	while (tmp[0]) {
		Xstrcat(param,DELIMOPT);
		Xstrcat(param,"i");
		MakeReper(tmp, &param[Xstrlen(param)]);
		NextOpt(&pt,&tmp[0]);
	}

	pt = &lstdef[0];		
	NextOpt(&pt,&tmp[0]);
	if (tmp[0] != EOSTR) {
		/* liste des defines */
		while (1) {
			Xstrcat(param,DELIMOPT);
			Xstrcat(param,"n");
			Xstrcat(param,tmp);
			Xstrcat(param," ");
			NextOpt(&pt,&tmp[0]);
			if (tmp[0] == EOSTR) break;
		}
	}

	Xstrcat(param," ");

	MakeNom(&REPS[0],nom,&EXTS[0],&param[Xstrlen(param)]);


	MakeNom(&REPB[0],"aplus","",&prog[0]);

#if unix || vms
	flag_modterm = TRUE;
#endif
#ifdef msdos
	if (Xstrlen(param) > 100) {
		/* Creation du fichier de configuration */
		fc = Xfopen("atrtmp","w");
		if (fc == GenericNULL(FILE))
			return (5);
		fprintf(fc,"%s\n",param);
	
		Xfputc(VEOF,fc);

		Xfclose(fc);

		Xstrcpy(param," /f");
		Xstrcat(param,"atrtmp");
	}
#endif
	ret = run(prog,param);

#if unix || vms
	flag_modterm = FALSE;
#endif

	if (ret == 5) return(2);

	if (ret == VAL_RET) {
		if (lobjopt[0] == FALSE) {
			/* le fichier APS a ete genere sans erreur */
			/* insertion du fichier APS dans l'historique des sources */
			Xfn_parser((BYTE FPTR) nom, (BYTE FPTR) tmp, 1 + 2 + 4 + 8 );
			Xstrcat( tmp, ".aps");
			liste_histo(&hissrc, tmp);

		}
		attendre();
	}
	else {
		if (lobjopt[4]) { ; /* attente avant l'edition */
			if ((pause()) != ESCAPE) {			
				/* edition en mode trace */
				ledit[0] = TRUE;
				ledit[1] = FALSE;
				ledit[2] = vaedopt[2];
				ledit[3] = vaedopt[3];

				MakeNom(&REPS[0],nom,&EXTS[0],&edittmp[0]);

				ret = editer(ledit,edittmp);

				if (ret != 5) {
					Xclear(5,1);
					return(2);
				}
			}
		}
		else 	{
			attendre();
		}
	}
	Xclear(5,1); 
	return(2);

}

#endif /* #BG */


static int traduction(ltropt,nom)
BOOL ltropt[];
BYTE XPTR nom;
{
	FILE * fc;

	char ret;
	BOOL ledit[4];
	BYTE XPTR pt;

	if (nom[0] == EOSTR) {
		msg_erreur(NOSRC); /*  pas la traduction */
		return(5);
	}

	Xclear(5,1); 
	if ( AbalToolVersion == 3 ) {
		Xstrcpy(&param[0],DELIMOPT);Xstrcat(&param[0],"v ");
		if (ltropt[5]) {	Xstrcat(&param[0],DELIMOPT); Xstrcat(param,"g ");	}
		if (ltropt[0]) {	Xstrcat(&param[0],DELIMOPT); Xstrcat(param,"m ");	}
		if (ltropt[2]) {	Xstrcat(&param[0],DELIMOPT); Xstrcat(param,"x ");	}
		if (ltropt[4]) {	Xstrcat(&param[0],DELIMOPT); Xstrcat(param,"w ");	}
		if (ltropt[5]) {	Xstrcat(&param[0],DELIMOPT); Xstrcat(param,"o ");	}
		if (ltropt[6]) {	Xstrcat(&param[0],DELIMOPT); Xstrcat(param,"a ");	}
		if (ltropt[7]) {	Xstrcat(&param[0],DELIMOPT); Xstrcat(param,"b ");	}
		}
	else	{
		Xstrcpy(&param[0],DELIMOPT);
		Xstrcat(&param[0],"h1");
/* #BG
		if (ltropt[6]) Xstrcat(param,"g");
		if (ltropt[1]) Xstrcat(param,"m");
		if (ltropt[3]) Xstrcat(param,"x");
		if (ltropt[5]) Xstrcat(param,"w");
		if (ltropt[6]) Xstrcat(param,"o");
		if (ltropt[7]) Xstrcat(param,"a");
		if (ltropt[8]) Xstrcat(param,"b");
*/
		if (ltropt[5]) Xstrcat(param,"g");
		if (ltropt[0]) Xstrcat(param,"m");
		if (ltropt[2]) Xstrcat(param,"x");
		if (ltropt[4]) Xstrcat(param,"w");
		if (ltropt[5]) Xstrcat(param,"o");
		if (ltropt[6]) Xstrcat(param,"a");
		if (ltropt[7]) Xstrcat(param,"b");
		}

/* #BG	if (ltropt[4]) {*/
	if (ltropt[3]) {
		Xstrcat(param," ");
		Xstrcat(param,DELIMOPT);
		Xstrcat(param,"e");

		MakeReper(&REPS[0], &param[Xstrlen(param)]);
		Xfn_parser((BYTE FPTR) nom,(BYTE FPTR) &param[Xstrlen(param)],8);
		Xstrcat(param,&EXTE[0]);
#ifdef prologue
		Xfn_parser((BYTE FPTR) nom,(BYTE FPTR) &param[Xstrlen(param)],32);
#endif
		Xstrcat(param," ");

	}

/* #BG	if (ltropt[2]) {*/
	if (ltropt[1]) {
		Xstrcat(param," ");
		Xstrcat(param,DELIMOPT);
		Xstrcat(param,"l");
		MakeReper(&REPS[0], &param[Xstrlen(param)]);

		Xfn_parser((BYTE FPTR) nom,(BYTE FPTR) &param[Xstrlen(param)],8);
		Xstrcat(param,&EXTL[0]);
#ifdef prologue
		Xfn_parser((BYTE FPTR) nom,(BYTE FPTR) &param[Xstrlen(param)],32);
#endif
		Xstrcat(param," ");
	}

	/* extention du fichier */
	Xstrcat(param,DELIMOPT);
	Xstrcat(param,"s");
	
/* #BG	if (ltropt[0])	Xstrcat(param,"aps"); // source pre-processe
	else*/		Xstrcat(param,&EXTS[1]);
	
	/* repertoire de destination */
	
	pt = &lstmod[0];		/* liste des modules */
	NextOpt(&pt,&tmp[0]);

	if (tmp[0] == EOSTR) {
		/* pas de module donc tout dans at0 */
		if (REPT[0] != EOSTR) {
			Xstrcat(param," ");
			Xstrcat(param,DELIMOPT);
			Xstrcat(param,"d");

			MakeReper(&REPT[0], &param[Xstrlen(param)]);

			Xfn_parser((BYTE FPTR) nom,(BYTE FPTR) &param[Xstrlen(param)],8+32);
			Xstrcat(param," ");
		}
	}
	else {
		/* Il existe des modules donc dans le r‚pertoire des modules */
		if (REPM[0] != EOSTR) {
			Xstrcat(param," ");
			Xstrcat(param,DELIMOPT);
			Xstrcat(param,"d");

			MakeReper(&REPM[0], &param[Xstrlen(param)]);

			Xfn_parser((BYTE FPTR) nom,(BYTE FPTR) &param[Xstrlen(param)],8+32);
			Xstrcat(param," ");
		}
	}

	/* repertoire des includes */

	pt = &REPI[0];		
	NextOpt(&pt,&tmp[0]);

	/* liste des includes */
	while (tmp[0]) {
		Xstrcat(param,DELIMOPT);
		Xstrcat(param,"i");
		MakeReper(tmp, &param[Xstrlen(param)]);
		NextOpt(&pt,&tmp[0]);
	}


	pt = &lstdef[0];		
	NextOpt(&pt,&tmp[0]);
	if (tmp[0] != EOSTR/* #BG && ! ltropt[0]*/ ) { /* ne pas prendre en compte les define pour les APS */
		/* liste des defines */
		while (1) {
			Xstrcat(param,DELIMOPT);
			Xstrcat(param,"n");
			Xstrcat(param,tmp);
			Xstrcat(param," ");
			NextOpt(&pt,&tmp[0]);
			if (tmp[0] == EOSTR) break;
		}
	}

	Xstrcat(param," ");

/* #BG if (ltropt[0] == TRUE )	{
		Xfn_parser((BYTE FPTR) nom, (BYTE FPTR) &param[Xstrlen(param)], 1+2+4+8);
	}
	else*/
		MakeNom(&REPS[0],nom,&EXTS[0],&param[Xstrlen(param)]);


	MakeNom(&REPB[0],AbalToolAtr,"",&prog[0]);

#if unix || vms
	flag_modterm = TRUE;
#endif
#ifdef msdos
	if (Xstrlen(param) > 100) {
		/* Creation du fichier de configuration */
		fc = Xfopen("atrtmp","w");
		if (fc == GenericNULL(FILE))
			return (5);
		fprintf(fc,"%s\n",param);
	
		Xfputc(VEOF,fc);

		Xfclose(fc);

		Xstrcpy(param," /f");
		Xstrcat(param,"atrtmp");
	}
#endif

	ret = run(prog,param);
	
#if unix || vms
	flag_modterm = FALSE;
#endif

	if (ret == 5) return(5);
	if (ret == VAL_RET) {
		if ( lstmod[0] == EOSTR ) {
/* #BG			if (ltropt[10]) {
				ret = pause();
				Xfn_parser((BYTE FPTR) nom, (BYTE FPTR) tmp, 1+2+4+8);
				MakeNom(&REPT[0],tmp,&EXTT[0], edittmp );
				if (ret != ESCAPE) ao(locoptao, edittmp );
				if (ret != 5) {
					Xclear(5,1);
					return(2);
				}
			}
*/
		}
		else {
/* #BG			if ( ltropt[9] ) {*/
			if ( ltropt[8] ) {
				ret = pause();
				if (ret != ESCAPE) linker( nomfic, lstmod );
				if (ret == 5) {
					Xclear(5,1);
					return(2);
				}
/* #BG				if (ltropt[10]) {
					ret = pause();
					Xfn_parser((BYTE FPTR) nom, (BYTE FPTR) tmp, 1+2+4+8);
					MakeNom(&REPT[0],tmp,&EXTT[0], edittmp );
					if (ret != ESCAPE) ao(locoptao, edittmp );
					if (ret != 5) {
						Xclear(5,1);
						return(2);
					}
				}
*/
			}
		}

		attendre();
		Xclear(5,1); 
		return(5);
	}
	else {
/* #BG		if (ltropt[4]) { ; /* attente avant l'edition */
		if (ltropt[3]) { ; /* attente avant l'edition */
			if ((pause()) != ESCAPE) {			
				/* edition en mode trace */
				ledit[0] = TRUE;
				ledit[1] = FALSE;
				ledit[2] = vaedopt[2];
				ledit[3] = vaedopt[3];

/* #BG				if (ltropt[0])
					MakeNom(&REPS[0],nom,".aps",&edittmp[0]);
				else */
					MakeNom(&REPS[0],nom,&EXTS[0],&edittmp[0]);

				ret = editer(ledit,edittmp);

				if (ret != 5) {
					Xclear(5,1);
					return(2);
				}
			}
		}
		else 	{
			attendre();
		}
		Xclear(5,1); 
		return(5);
	}
}

static int linker( nom, liste )
BYTE XPTR nom;
BYTE XPTR liste;
{
#ifdef msdos
	FILE * fc;
#endif
	int ret;
	int rep;

	BYTE XPTR p;
	BYTE reptmp[LGREP];
	
/*
	if (liste[0]) {
		p = liste;
	}
	else 	p = &lstmod[0];	
*/

	p = nom;
	NextOpt(&p,&argtmp[0]);
	if (argtmp[0] == EOSTR) {
		msg_erreur(NOMOD);
		return(0);
	}
	else {
		Xstrcpy(param,DELIMOPT);
		Xstrcat(param,"h1 ");

		if (voptald[0]) {
			Xstrcat(param,DELIMOPT);
			Xstrcat(param,"i ");
		}
	
		reptmp[0] = EOSTR;
		MakeReper(&REPM[0], reptmp );
		if ( reptmp[0]) {
			Xstrcat(param," ");
			Xstrcat(param,DELIMOPT);
			Xstrcat(param,"r");
			Xstrcat(param, reptmp );
		}			

		reptmp[0] = EOSTR;
		MakeReper(&REPT[0], reptmp );
		if ( reptmp[0]) {
			Xstrcat(param," ");
			Xstrcat(param,DELIMOPT);
			Xstrcat(param,"d");
			Xstrcat(param, reptmp );
		}			

		Xstrcat(param," ");

		Xfn_parser((BYTE FPTR) nom,(BYTE FPTR) &param[Xstrlen(param)],1+2+4+8);


		if ( ! voptald[0] ) {
			Xstrcat(param," ");
			p = liste;
			while (NextOpt(&p,argtmp)) {
				Xstrcat(param," ");
				Xstrcat(param,argtmp);
			}
		}

		MakeNom(REPB,"ald","",prog);

		Xclear(5,1); 
		
#if unix || vms
		flag_modterm = TRUE;
#endif
#ifdef msdos
	if (Xstrlen(param) > 100) {
		/* Creation du fichier de configuration */
		fc = Xfopen(cfgtmp,"w");
		if (fc == GenericNULL(FILE))
			return (5);
		fprintf(fc,"%s\n",param);
	
		Xfputc(VEOF,fc);

		Xfclose(fc);
		Xstrcpy(param," /f");
		Xstrcat(param,cfgtmp);
	}
#endif
		ret = run(prog,param);
#if unix || vms
		flag_modterm = FALSE;
#endif

		if (ret != 5) {
#ifndef vms
			if (ret == 0) attendre();
#else
			if (ret == 1) attendre();
#endif
		}
		return(5);
	}
}

static int ao(opt, nom)
BOOL opt[];
BYTE XPTR nom;
{
	int ret;

	if (nom[0] == EOSTR) {
		msg_erreur(NOTRA); /*  pas la traduction */
		return(5);
	}

	Xclear(5,1); 

	Xstrcpy(param,DELIMOPT);
	if (opt[1]) Xstrcat(param,"o");
	Xstrcat(param,"h");
	if (opt[0]) Xstrcat(param,"w");
	if (opt[2]) Xstrcat(param,"2");
	if (opt[3]) Xstrcat(param,"3");


	Xstrcat(param," ");

	MakeReper(&REPT[0], &param[Xstrlen(param)]);
	Xfn_parser((BYTE FPTR) nom,(BYTE FPTR) &param[Xstrlen(param)],8);
	Xstrcat(param," ");

	MakeNom(REPB,"ao","",prog);

	Xclear(5,1); 
	
#if unix || vms
	flag_modterm = TRUE;
#endif

	ret = run(prog,param);

#if unix || vms
	flag_modterm = FALSE;
#endif

	if (ret != 5) {
#ifndef vms
		if (ret == 0) attendre();
#else
		if (ret == 1) attendre();
#endif

	}

	return(2);
}

static int executer()
{
	int rep;

	while (1) {
		rep = vmenu(5,tpos[3]-1,3,coexec,oexec,hexec);
		if (rep == -1) {
			Xclear(5,tpos[3]-1); return(0);
		}
		if (rep == -2) {
			Xclear(5,tpos[3]-1);  return (1);
		}
		if (rep == -3) {
			Xclear(5,tpos[3]-1);  return (MOINS_UN);
		}

		if (rep >= 0) {
			if (rep >= 20) 	coexec = rep - 20;
			else 		coexec = rep;

			if (coexec == 0 || coexec == 1) {
				if (rep >= 20) {
					argtmp[0] = EOSTR;
					MakeNom(REPT,"*",EXTT,reptmp);
					rep = boite(10,16,argtmp,reptmp,&histra,&cfic,&crep,inte_msg[SELEC]);					
					if (rep == -5) {
						Xclear(5,1); 
						boolESC = TRUE;
						return(0);
					}
					if (rep >= 0) {
						rep = runexa(coexec, argtmp);
					}
					else Xclear(5,1);
				}
				else 	{
					argtmp[0] = EOSTR;
					MakeReper(&REPT[0], &argtmp[0]);
					Xfn_parser((BYTE FPTR) nomfic,(BYTE FPTR) &argtmp[Xstrlen(argtmp)],8+32);
					rep = runexa(coexec,argtmp);
				}
				if (rep != 5) {
					attendre();
					FILLIN;

					Xclear(5,2);
					
					return(2);
				}
			}
			if (coexec == 2)  run_argu();
		}
	}
}

static int runexa(who,nom)
BYTE who;
BYTE XPTR nom;
{
	
	int ret;
	Xclear(5,2);
	if (nom[0] == EOSTR) {
		msg_erreur(NOTRA);
		return(5);
	}

	param[0] = EOSTR;

	Xfn_parser((BYTE FPTR) nom, (BYTE FPTR) nomtmp, 1+2+4+8);
	MakeNom(REPT, nomtmp, EXTT, &param[0]);
	Xfn_parser((BYTE FPTR) nom, (BYTE FPTR) &param[Xstrlen(param)], 32+64);
		
	if (nomargu[0] != EOSTR) {
		Xstrcat(param," ");
		Xstrcat(param, nomargu);	/* argument du programme */
	}

	Xclear(10,1); 

	if (who == 0) {
		MakeNom(REPB, AbalToolExa,"",prog);
	}
	else {
		MakeNom(REPB, AbalToolExadb, "", prog);
	}
	boolexa = 1;

	FILLOUT;
	ret = run(prog,param);


	boolexa = 0;
	return(ret);
}

static void run_argu()
{
	int rep;

	rep = ask(10,tpos[3]+1,LGAFF,LGARGU,nomargu);
	if (rep == -5) {
		Xclear(5,1); 
		boolESC = TRUE;
	}
	Xclear(9,tpos[3]-1); 
}

static int util()
{
	int rep;
char tmp[20];
 
	while (1) {
#ifdef ver21	
/* #BG		if (skipper_is_here) rep = vmenu(5,tpos[4]-1,10,coutil,outil2,hutil2);
		else 		rep = vmenu(5,tpos[4]-1,9,coutil,outil,hutil);*/
/*		if (skipper_is_here) rep = vmenu(5,tpos[4]-1,8,coutil,outil2,hutil2);
		else*/ 		rep = vmenu(5,tpos[4]-1,7,coutil,outil,hutil);
#else
/*#BG		rep = vmenu(5,tpos[4]-1,8,coutil,outil,hutil);*/
		rep = vmenu(5,tpos[4]-1,7,coutil,outil,hutil);
#endif
		if (rep == -1) {
			Xclear(5,tpos[4]-1); return(0);
		}
		if (rep == -2) {
			Xclear(5,tpos[4]-1); return (1);
		}
		if (rep == -3) {
 			Xclear(5,tpos[4]-1);  return (MOINS_UN);
		}
		if (rep >= 20) {
			coutil = rep - 20;
			if (rep != 28)  {
				Xbell(); /* tab n'a pas de sens sauf pur systeme */
			}
			else {
				nomtmp[0] = EOSTR;
				MakeNom(REPB,"*",EXTB,reptmp);
				rep = boite(10,16,nomtmp,reptmp,&hissys,&cfic,&crep,inte_msg[SELEC]);
				if (rep == -5) {
					Xclear(5,1); 
					boolESC = TRUE;
					return(0);
				}

				if  (rep >= 0) {
/* #BG					if (skipper_is_here) 	affmenu(5,tpos[4]-1,10, coutil,outil,hutil);
					else 	affmenu(5,tpos[4]-1,9, coutil,outil,hutil);		*/
					/* #BG if (skipper_is_here) 	affmenu(5,tpos[4]-1,8, coutil,outil,hutil);
					else*/ 	affmenu(5,tpos[4]-1,7, coutil,outil,hutil);		

					Xstrcpy(argsys, nomtmp);
					Xstrcat(argsys," ");

					rep = run_util(coutil);
					if (rep == 2) return(2); /* on a casse l'ecran */
					else {
						Xclear(6+coutil+1,tpos[4]); 
					}
				}
			}
		}
		else if (rep >= 0) {
			coutil = (BINAIRE) rep;

			rep = run_util(rep);			

			Xclear(6+coutil+1,tpos[4]); 

			if (rep == 2) return(2); /* on a casse l'ecran */
		}
	}
}

static int run_util(who)
BYTE who;
{
	BYTE XPTR p;
	int rep,srep;
	BYTE tmp[LGREP];
	BYTE exttmp[LGREP];

/* #BG	if (who != 8) {*/
	if (who != 6) {
		if (who == 0) {
			rep = ask(6+who+1+1,tpos[4]+1,LGAFF,LGARGU,argecran);
			if (rep == -5) {
				Xclear(5,1); 
				boolESC = TRUE;
				return(0);
			}
			if (rep < 0) return(0);
		
			MakeNom(REPB, "ecran ","",prog);
			param[0] = EOSTR;
			p = &argecran[0];

		}
		else if (who == 1) {
			rep = ask(6+who+1+1,tpos[4]+1,LGAFF,LGARGU,argtrans);
			if (rep == -5) {
				Xclear(5,1); 
				boolESC = TRUE;
				return(0);
			}
			if (rep < 0) return(0);

			MakeNom(REPB, "transbal ","",prog);
			param[0] = EOSTR;
			p = &argtrans[0];
		}
		else if (who > 1) {
			MakeNom(REPB, "exa ","",prog);
			MakeReper(REPB, param);
			if (who == 2) {
				rep = ask(6+who+1+1,tpos[4]+1,LGAFF,LGARGU,argtsf);
				if (rep == -5) {
					Xclear(5,1);
					boolESC = TRUE;
					return(0);
				}
				if (rep < 0) return(0);
				Xstrcat(param,"tsf ");
				p = &argtsf[0];
			}
			else if (who == 3) {
			rep = ask(6+who+1+1,tpos[4]+1,LGAFF,LGARGU,argsvam /*#BG argsvsi*/);
				if (rep == -5) {
					Xclear(5,1);
					boolESC = TRUE;
					return(0);
				}
				if (rep < 0) return(0);

				Xstrcat(param,"svam " /*#BG "svsi "*/);
				/*#BG p = &argsvsi[0];*/
				p = &argsvam[0];
			}
			else if (who == 4) {
			rep = ask(6+who+1+1,tpos[4]+1,LGAFF,LGARGU,argrtam /*#BG argrtsi*/);
				if (rep == -5) {
					Xclear(5,1);
					boolESC = TRUE;
					return(0);
				}
				if (rep < 0) return(0);

				Xstrcat(param,"rtam " /*#BG "rtsi "*/);
				/*#BG p = &argrtsi[0];*/
				p = &argrtam[0];
			}
/* #BG
			else if (who == 5) {
				rep = ask(6+who+1+1,tpos[4]+1,LGAFF,LGARGU,argfrmc);
				if (rep == -5) {
					Xclear(5,1); 
					boolESC = TRUE;
					return(0);
				}
				if (rep < 0) return(0);	
				Xstrcat(param,"frecupmc ");
				p = &argfrmc[0];
			}
			else if (who == 6) {
				rep = ask(6+who+1+1,tpos[4]+1,LGAFF,LGARGU,argfrbd);
				if (rep == -5) {	
					Xclear(5,1);
					boolESC = TRUE;
					return(0);
				}
				if (rep < 0) return(0);

				Xstrcat(param,"frecupbd ");
				p = &argfrbd[0];
			}
*/
/* #BG			else if (who == 7) {*/
			else if (who == 5) {
				objagr(6+who+1,tpos[4] + 2);
				rep = vselect(6+who+1+3,tpos[4]+1, 4, coptbr, loptbr, voptbr, hoptbr); 
				if (rep == -5) {	
					Xclear(5,1);
					boolESC = TRUE;
				}
				if ( rep < 0 ) return(0);

				MakeNom(REPB, "agr ","",prog);

				param[0] = EOSTR;

				if ( voptbr[0] ) {
					Xstrcat(param, " -");
					Xstrcat(param, "c");
				}
				if ( voptbr[1] ) {
					Xstrcat(param, " -");
					Xstrcat(param, "i");
				}
				if ( voptbr[3] ) {
					Xstrcat(param, " -");
					Xstrcat(param, "x");
				}
				if ( voptbr[2] == FALSE ) {
					Xstrcat(param, " -");
					Xstrcat(param, "v");
					Xstrcat(param, " -");
					Xstrcat(param, "l");
				}
				else {
					if ( REPB[0] ) {
						Xstrcat(param, " ");
						Xstrcat(param, " -");
						Xstrcat(param,"e");
						MakeNom(REPB, AbalToolAed, "", &param[Xstrlen(param)]); 
					}
				}


				/* les patterns a chercher */
				p = &epobjp[0][0];
				while (NextOpt(&p,&tmp[0])) {
						Xstrcat(param,  " -");
						Xstrcat(param, "s");
						Xstrcat(param, tmp);
				}

				/* les fichiers dans lesquels chercher */
				p = &epobjp[1][0];
				while (NextOpt(&p,&tmp[0])) {
						Xstrcat(param,  " ");
						Xstrcat(param, tmp);
				}
				Xstrcat(param," ");
			}
/* #BG
#ifdef ver21
			else if (who == 9) {
				rep = ask(6+who+1+1,tpos[4]+1,LGAFF,LGARGU,argskipp);
				if (rep == -5) {	
					Xclear(5,1);
					boolESC = TRUE;
					return(0);
				}
				if (rep < 0) return(0);

				MakeReper(REPPIKS, param);
				GetReper(REPTMP, LGREP);
				ChgDir(param);
				Xstrcat(param,"skipper ");
				p = &argskipp[0];

			}
			
#endif
*/
		}
		while (NextOpt(&p,&param[Xstrlen(param)])) {
			Xstrcat(param," ");
		}
		Xstrcat(prog, " ");
		Xstrcat(prog,param);
	}
	else {
		rep = ask(6+who+1+1,tpos[4]+1,LGAFF,LGARGU,argsys);
		if (rep == -1) return(0);
		if (rep == -5) {
			Xclear(5,1); 
			boolESC = TRUE;
			return(0);
		}
		p = &argsys[0];
		prog[0] = EOSTR;
		NextOpt(&p,&prog[Xstrlen(prog)]);		
		Xstrcat(prog," ");
		while (NextOpt(&p,&prog[Xstrlen(prog)])) {
			Xstrcat(prog," ");
		}			
	}		

	if (prog[0] == EOSTR) {
		Xclear(1,1); 
		return(5);
	}
	
	prog[Xstrlen(prog)-1] = EOSTR;

	liste_histo(&hissys, &prog[0]);

	rest_tfp();
#ifdef buf_cico
	x_bstart();
#endif
	atb(0); atb(26);
#ifdef buf_cico
	x_bflush();
#endif
	FILLOUT;

/* #BG	if (vsysopt[0] || (who != 8)) {*/
	if (vsysopt[0] || (who != 6)) { 
		/* plein ecran */
		pos(1,1);
		Xclear(1,1);
		finscreen(); 	

		rep = Xsysteme((BYTE FPTR) prog);

	/* initialisation du terminal */
#ifdef vms
		qio_usage_flag = 0;
#endif
		prndest = 1; err_val = 0;
		ABAL_INIT_TERM();
		Batb(25); Batb(0);
		
#ifdef vms
		if (rep == 0) rep = 1; /* impair -> pas d'erreur */
#endif
	}
	else {

		rest_tfp();
		Xclear(5,1);
		rep = Xsystemd((BYTE FPTR) prog,6,conf(1),1);

	}

	if (rep != VAL_RET) {
#ifdef msdos
		if (rep == 40) rep = MOINS_UN;
#endif
#ifdef prologue
		if (Xsystemr()) rep = MOINS_UN;
#endif
		/* erreur programme non trouve */
		if (rep < VAL_RET)
			msg_erreur(NOTFIND);
		else 	{
/* #BG			if (who == 7) */
			if (who == 5) 				
				/* ignorer le code retour de agr */
				/* qui retourne le nb occurrences trouve */
				attendre();
			else 	msg_erreur(WARNI);
		}
	}
	else {
		attendre();
	}

	reinit_tfp();

	FILLIN;

#ifdef ver21
/* #BG	if (who == 9) ChgDir(REPTMP);*/
	if (who == 7) ChgDir(REPTMP);
#endif
#ifdef prologue
	lectfp(nomcfg);
#endif	

	pos(5,1);

#ifdef buf_cico
	x_bstart();
#endif

	atb(25);

#ifdef buf_cico
	x_bflush();
#endif

/* #BG	if (vsysopt[0] || who != 8)	return(2);*/
	if (vsysopt[0] || who != 6)	return(2);
	else				return(2);
}

static void msg_erreur(nummsg)
BINAIRE nummsg;
{
	int lg;

#ifdef buf_cico
	x_bstart();
#endif

	Xatb(2);
	pos(conf(1),1); Xatb(21);
	lg = Xstrlen(inte_msg[nummsg]);
	pos(conf(1) , (conf(2)-lg) / 2);
	x_cprintf((BYTE FPTR) inte_msg[nummsg]);
#ifdef buf_cico
	x_bflush();
#endif

	xx_getch();

#ifdef buf_cico
	x_bstart();
#endif
	pos(conf(1) , 1); Xatb(21);
	Xatb(0);
#ifdef buf_cico
	x_bflush();
#endif
}

static int config()
{
	int rep;

	while (1) {
/* #BG		rep = vmenu(5,tpos[5]-1,10,coconf,oconf,hconf);*/
		rep = vmenu(5,tpos[5]-1,8,coconf,oconf,hconf);
		if (rep == MOINS_UN) {
			Xclear(5,tpos[5]-1);  return(0);
		}
		if (rep == -2) {
			Xclear(5,tpos[5]-1);  return (1);
		}
		if (rep == -3) {
			Xclear(5,tpos[5]-1);  return (MOINS_UN);
		}
		if (rep >= 20) Xbell(); /* tab n'a pas de sens */
		else if (rep >= 0) {
			coconf = (BINAIRE) rep;
			if (rep == 0) confsys();
/* #BG
			else if (rep == 1) confedit();
			else if (rep == 2) confobj();
			else if (rep == 3) conftrad();
			else if (rep == 4) confao();	    
			else if (rep == 5) confext();
			else if (rep == 6) confrep();
			else if (rep == 7) toufonc();
			else if (rep == 8) ecrcfg();
			else if (rep == 9) leccfg();	    
*/
			else if (rep == 1) confedit();
			else if (rep == 2) conftrad();
			else if (rep == 3) confext();
			else if (rep == 4) confrep();
			else if (rep == 5) toufonc();
			else if (rep == 6) ecrcfg();
			else if (rep == 7) leccfg();	    
			else 	{
				attendre();	
				Xclear(5,2); 
				}
			}
		Xclear(5,tpos[5]-1);
		}
	return(0);
}

static void confsys()
{
	int rep;

	int	mxcol,debcol;
	int	temp;

	mxcol = Xstrlen(inte_msg[strsys[0]])+3;
	temp  = Xstrlen(inte_msg[strsys[1]])+3;
	debcol = tpos[5] + Xstrlen(inte_msg[oconf[0]]) - mxcol - 2;

	rep  = vselect(7,debcol,2,coptsys,strsys,vsysopt,htrsys);
	if (rep >= 0) {
#ifdef	VERSION666
		if ( vsysopt[1] !=  0 )
			AbalToolVersion=3;
		else	AbalToolVersion=2;
#endif
		/* cfg modifie */
		boolcfg = FALSE;
		}
	Xclear(7,debcol); 
}



static void confext()   
{
	int rep,srep;
	BYTE c;
	char i;
	int	mxcol;
	int 	debcol;
	int 	lglib;

	lglib = Xstrlen(inte_msg[lext[0]]);

	mxcol = lglib +  1 + 1 + 2 + LGEXT-1 + 2 + 1;

	debcol = tpos[5] + Xstrlen(inte_msg[oconf[0]]) - mxcol;

#ifdef buf_cico
	x_bstart();
#endif
	if ( cico_is_graphic() ) {
		cadre(12,debcol+lglib+2,10+NBEXT+3,debcol+lglib+1+1+2+LGEXT-1+2);
		}
	else	{

		/* Premiere Ligne */
		/* -------------- */
		pos(12,debcol+lglib+1); 
		x_putch(C_CHG);
		for (i = 1; i < 1+2+LGEXT-1+2; i++) {
			x_putch(C_LNH);
			}
		x_putch(C_CHD);
		}

	for (i=0; i < NBEXT; i++) {

		if (!( cico_is_graphic() )) {
			pos(13+i, debcol + lglib + 1);
			x_putch(C_LNV);
			x_putch(' ');
			x_putch(' ');
			}
		else	pos(13+i, debcol + lglib + 1 + 2);
		aff_zone(tab_ext[i],LGEXT-1);
		if (!( cico_is_graphic() )) {
			x_putch(' ');
			x_putch(' ');
			x_putch(C_LNV);
			}
		}

	/* Derniere Ligne */
	/* -------------- */
	if (!( cico_is_graphic() )) {
		pos(12 + NBEXT + 1,debcol+lglib+1); 
		x_putch(C_CBG);
		for (i = 1; i < 1+2+LGEXT-1+2; i++) {
			x_putch(C_LNH);
			}
		x_putch(C_CBD);
		}
	x_bflush();

	while (1) {
		if (!( cico_is_graphic() ))
			rep = vmenu(12,debcol-1,NBEXT,iext,lext,hext);
		else	rep = wmenu(12,debcol-1,NBEXT,iext,lext,hext);
		if (rep == -1) {
			Xclear(5,1); 
			break;
			}
		if (rep >= 20) Xbell(); /* tab n'a pas de sens */
		else if (rep >= 0) {
			iext = rep;
			rep = saisie(13+rep,debcol+lglib+1+1,LGEXT-1,LGEXT-1,tab_ext[rep]);			
			if (rep == -5) {
				Xclear(5,1); 
				boolESC = TRUE;
				break;
				}
			/* cfg modifie */
			if (rep > 0) boolcfg = FALSE;
			}

		}
	Xclear(5,1);
	Batb(25); 
	return;
}

static void aff_zone(pt, lgaff)
BYTE XPTR pt;
int lgaff;
{
	int i;
	BOOL finlgn = FALSE;

	for (i=0; i < lgaff; i++) {
		if (!finlgn) 
			if (*pt == EOSTR) finlgn = TRUE;

		if (finlgn)
			x_putch(' ');
		else	{
			if (*pt < 0x20) {
				Xatb(2);
				if (*pt == ESCAPE) 	x_putch('&');
				else 			x_putch(0x40 + *pt);
				Xatb(0);
			}
			else {
				x_putch(*pt);
			}
		}
		pt++;

	}

}

static void confrep()    
{
	int rep,srep;
	BYTE c;
	char i;
	int	mxcol;
	int 	debcol;
	int 	lglib;

	lglib = Xstrlen(inte_msg[lrep[0]]);

	mxcol = lglib +  1 + 1 + 2 + LGAFF + 2 + 1;

	debcol = tpos[5] + Xstrlen(inte_msg[oconf[0]]) - mxcol;

	x_bstart();

	if ( cico_is_graphic() ) {
		cadre(13,debcol+lglib+1,11+NBREP+3,debcol+lglib+1+1+2+LGAFF+2);
		}
	else	{

		/* Premiere Ligne */	
		/* -------------- */
		pos(13,debcol+lglib+1); 
		x_putch(C_CHG);
		for (i = 1; i < 1+2+LGAFF+2; i++) {
			x_putch(C_LNH);
			}
		x_putch(C_CHD);
		}

	for (i=0; i < NBREP; i++) {
		if (!( cico_is_graphic() )) {
			pos(14+i, debcol + lglib + 1);
			x_putch(C_LNV);
			x_putch(' ');
			x_putch(' ');
			}
		else	pos(14+i, debcol + lglib + 1 + 2);
		aff_zone(tab_rep[i],LGAFF);
		if (!( cico_is_graphic() )) {
			x_putch(' ');
			x_putch(' ');
			x_putch(C_LNV);
			}
		}

	/* Derniere Ligne */
	/* -------------- */
	if (!( cico_is_graphic() )) {
		pos(13+ NBREP + 1,debcol+lglib+1); 
		x_putch(C_CBG);
		for (i = 1; i < 1+2+LGAFF+2; i++) {
			x_putch(C_LNH);
			}
		x_putch(C_CBD);
		}


	x_bflush();

	while (1) {
		if (!( cico_is_graphic() )) 
			rep = vmenu(13,debcol,NBREP,irep,lrep,hrep);
		else	rep = wmenu(13,debcol,NBREP,irep,lrep,hrep);
		if (rep == -1) {
			Xclear(5,1); 
			break;
			}
		if (rep >= 20) Xbell(); /* tab n'a pas de sens */
		else if (rep >= 0) {
			irep = rep;
			srep = saisie(14+rep,debcol+lglib+1+1,LGAFF,LGREP,tab_rep[rep]);			
			if (srep == -5) {
				Xclear(5,1); 
				boolESC = TRUE;
				break;
				}
			/* cfg modifie */
			if (srep > 0) boolcfg = FALSE;
/* #BG
#ifdef ver21
			if (rep == NBREP - 1) {
				// test la presence de skipper
				skipper_is_here = 0;
				MakeNom(REPPIKS, "skipper",".at",prog);
				if (Xaccess(prog,0)==0) skipper_is_here = 1;
				}
			
#endif
*/

			}
		}

	Xclear(11,1);  /* le premier cadre */
	Batb(25); 
	return;
}

/* #BG */
#ifdef OBJET
static void confobj()

/*	gestion de la configuration de aplus
 */
{					/* confobj */
	int	rep,majdef;
	int	mxcol,debcol,debopt,lgopt;
	int debswap;

	mxcol = Xstrlen(inte_msg[laplus[0]]);
	debcol = tpos[5] + Xstrlen(inte_msg[oconf[0]]) - mxcol - 2;

	lgopt = Xstrlen(inte_msg[lacti[0]]) + 2;
	debopt = debcol + mxcol - 2 - lgopt;
	
	debswap = debcol + mxcol - (LGAFF + 4);

	while (1) {		/* sortie par BREAK */
		rep = vmenu(9,debcol,2, eaplus, laplus,haplus);
		if (rep == -1)	/* annulation */
			break;
		else if ((rep == -2) || (rep == -3)) {
			/* menu suivant ou precedent : pas de sens ici */
			Xbell(); 
		}
		else if (rep == 0) { /* selection des options */
			eaplus = rep;
			do {
				rep  = vselect(11,debopt, 10, eacti, lacti, vacti, hacti);
				
			}
			while (rep == -2 || rep == -3 || rep >= 20);

			if (rep >= 0) {
				eacti = rep;
				/* cfg modifie */
				boolcfg = FALSE;
			}
			Xclear(9,debopt); 
			affmenu(5,tpos[5]-1,10,coconf,oconf,hconf);
		}
		else if (rep == 1) { /* definitions */
			eaplus = rep;
			rep = ask(13,debswap,LGAFF,LGARGU,swapunit);
			if (rep == -5) {
				Xclear(5,1); 
				boolESC = TRUE;
			}
			if ( rep >= 0 ) {
				boolcfg = FALSE;
			}	
			Xclear(9,debopt); 
			affmenu(5,tpos[5]-1,10,coconf,oconf,hconf);
		}
		else 	Xbell();
	}
	Xclear(5,debcol); 
}
#endif /* #BG */


static void objagr(l,c)
BINAIRE l;
BINAIRE c;
{
	int rep,srep;
	char i;
	int	mxcol;
	int 	debcol;
	int 	lglib;
	int	debopt;
	int	lgopt;

/*
	mxcol = Xstrlen(inte_msg[laplus[0]]);
	debcol = c + Xstrlen(inte_msg[oconf[0]]) - mxcol - 2;


	lgopt = Xstrlen(inte_msg[laplus[0]]) + 3;
	debopt = debcol - 2 + lgopt;


	mxcol = lglib +  1 + 1 + 2 + LGAFF + 2 + 1;
*/

	lglib = Xstrlen(inte_msg[lcon[0]]);
	debcol = c;

/*
	debcol = debcol - mxcol;
*/
#ifdef buf_cico
	x_bstart();
#endif

	/* Premiere Ligne */	
	/* -------------- */
	if ( cico_is_graphic() ) {
		cadre(l,debcol+lglib+3,l+4,debcol+lglib+1+14);
		}
	else	{
		pos(l, debcol + lglib + 1 ); 
		x_putch(C_CHG);
		for (i = 1; i < 1+2+10+2; i++) {
			x_putch(C_LNH);
			}
		x_putch(C_CHD);
		}

	for (i=0; i < 2; i++) {
		if (!( cico_is_graphic() )) {
			pos(l+1+i, debcol + lglib + 1);
			x_putch(C_LNV);
			x_putch(' ');
			x_putch(' ');
			}
		else	pos(l+1+i, debcol + lglib + 4);
		aff_zone(epobjp[i],10);
		if (!( cico_is_graphic() )) {
			x_putch(' ');
			x_putch(' ');
			x_putch(C_LNV);
			}
		}

	/* Derniere Ligne */
	/* -------------- */
	if (!( cico_is_graphic() )) {
		pos(l + 2 + 1, debcol + lglib +1); 
		x_putch(C_CBG);
		for (i = 1; i < 1+2+ 10 +2; i++) {
			x_putch(C_LNH);
			}
		x_putch(C_CBD);
		}

#ifdef buf_cico
	x_bflush();
#endif

	while (1) {
		rep = vmenu(l,debcol-1,2,eobjp,lcon,hcon);
		if (rep == -1) {
			break;
		}
		if (rep >= 20) Xbell(); /* tab n'a pas de sens */
		else if (rep >= 0) {
			eobjp = rep;
			srep = saisie(l+1+rep,debcol+lglib+1+1,10,LGREP,epobjp[rep]);			
			if (srep == -5) {
				boolESC = TRUE;
				break;
			}
			else { /* CR passe a la ligne suivante */
				if (eobjp == 1) eobjp = 0;
				else		eobjp = 1;
			}
		}
	}

	return;
}

/* #BG */
#ifdef OBJET
static void confao()
{
	int	rep,majdef;
	int	mxcol,debcol,debopt,lgopt;

	mxcol = Xstrlen(inte_msg[loptao[0]]) + 3;
	debcol = tpos[5] + Xstrlen(inte_msg[oconf[0]]) - mxcol - 2;

	while (1) {		/* sortie par BREAK */

		rep  = vselect(11,debcol,4,coptao,loptao,voptao,hoptao);

		if (rep == -1)	/* annulation */
			break;
		else if ((rep == -2) || (rep == -3)) {
			/* menu suivant ou precedent : pas de sens ici */
			Xbell(); 
		}
		else if (rep >= 0) { /* selection des options */
			coptao = rep;

			/* cfg modifie */
			boolcfg = FALSE;
			break;
		}
		else 	Xbell();
	}

/*clear(7,debcol); */
}
#endif /*#BG */


static void Xfgets(buf,lgr,fic)
BYTE XPTR buf;
BINAIRE lgr;
FILE XPTR fic;
{ BYTE XPTR p;

	if (fgets(buf,lgr,fic) == NULL) {
		*buf = '\0';
	}
	if (Xstrlen(buf) == 0)
		return;

	p = buf+Xstrlen(buf)-1;
	if ((*p == '\n') || (*p == '\r'))
		*p = '\0';
	p = buf+Xstrlen(buf)-1;
	if ((*p == '\n') || (*p == '\r'))
		*p = '\0';
}


/*	Lecture d'un entier dans le tampon 'buf', a partir
 *	de la position 'ptr', et resultat dans 'val'
 */
static void Xscanf(buf,ptr,val)
BYTE XPTR buf;
BINAIRE XPTR ptr;
BINAIRE XPTR val;
{ BINAIRE tmp;
  BYTE c;

  tmp = 0;
  while ((c = buf[*ptr]) != '\0' && (c != ' ')) {
	tmp = 10*tmp + (c - '0');
	(*ptr)++;
  }
  while ((c = buf[*ptr]) == ' ')
	(*ptr)++;

  *val = tmp;
}


static BOOL lecconf(nomcfg)

/*	lecture du fichier de configuration designe par 'nomcfg'
 */

BYTE XPTR nomcfg;
{					/* lecconf */
	FILE	*fc;
	int	i;
/*	char	buf[LGREP]; */
	char	buf[256];
	BYTE XPTR	p;
	BINAIRE	val;
	BINAIRE pt;


	/* on fait de la place memoire */
	purge(&cfic);

	/* Ouverture du fichier de configuration */

	fc = Xfopen(nomcfg,"r");
	if (fc == GenericNULL(FILE))
		return (FALSE);

	/* Controle la signature du fichier */
	Xfgets(&buf[0],LGREP,fc);

	if (Xstrcmp(verscfg,&buf[0]) != 0) {
		Xfclose(fc);
		return (FALSE);
	}

	/* Lecture des repertoires par defaut */
	Xfgets(&REPS[0],LGREP,fc);
	Xfgets(&REPI[0],LGREP,fc);
	Xfgets(&REPM[0],LGREP,fc);
	Xfgets(&REPT[0],LGREP,fc);
	Xfgets(&REPB[0],LGREP,fc);
	if (REPS[0] == '0') {
		REPS[0] = EOSTR;
	}
	if (REPI[0] == '0') {
		REPI[0] = EOSTR;
	}
	if (REPM[0] == '0') {
		REPM[0] = EOSTR;
	}
	if (REPT[0] == '0') {
		REPT[0] = EOSTR;
	}
	if (REPB[0] == '0') {
		REPB[0] = EOSTR;
	}

	/* Lecture de la designation du fichier courant */
	Xfgets(&buf[0],LGREP,fc);
	if (buf[0] != '0') {
		Xstrcpy(nomfic,buf);
	}
	else nomfic[0] = EOSTR;

	/* Lecture de la designation du projet courant */
	Xfgets(&buf[0],LGREP,fc);
	if (buf[0] != '0')
		Xstrcpy(nomprj,buf);
	else	nomprj[0] = EOSTR;

	/* Lecture de l'option d'aide */
	Xfgets(&buf[0],256,fc);
	pt = 0;
	Xscanf(&buf[0],&pt,&val);
	flg_help = (BOOL) val;

	/* Lecture du type d'ecran pour la commande systeme */
	Xscanf(&buf[0],&pt,&val);
	vsysopt[0] = (BOOL) val;
#ifdef	VERSION666
	vsysopt[1] = 1;
	AbalToolVersion=3;
#else
	vsysopt[1] = 0;
	AbalToolVersion=2;
#endif

	/* Lecture des extensions des fichiers */
	Xfgets(&EXTS[1], LGEXT,  fc);
	Xfgets(&EXTL[1], LGEXT,  fc);
	Xfgets(&EXTE[1], LGEXT, fc);
	Xfgets(&EXTSAV[1], LGEXT, fc);
	Xfgets(&EXTPRJ[1], LGEXT, fc);

	if (EXTS[1] == '0') {
		EXTS[1] = EOSTR;
	}
	if (EXTL[1] == '0') {
		EXTL[1] = EOSTR;
	}
	if (EXTE[1] == '0') {
		EXTE[1] = EOSTR;
	}
	if (EXTSAV[1] == '0') {
		EXTSAV[1] = EOSTR;
	}
	if (EXTPRJ[1] == '0') 
		EXTPRJ[1] = EOSTR;

	/* Lecture des options de l'editeur de textes */
	Xfgets(&buf[0],256,fc);
	pt = 0;
	for (i=0; i<4; i++) {
		Xscanf(&buf[0],&pt,&val);
		vaedopt[i] = (BOOL) val;
	}

	/* Lecture des valeurs par defaut des commandes d'edition */
	for (i = 0; i < 18; i++) {
		Xscanf(&buf[0],&pt,&val);
		vcomed[i] = (BYTE) val;
	}

	/* Lecture de la valeur de la tabulation */
	Xscanf(&buf[0],&pt,&val);
	lg_tab = (BINAIRE) val;

	/* Lecture des symboles de traduction predefinis */
	Xfgets(&buf[0],LGREP, fc); 
	if (buf[0] == '0') {
		lstdef[0] = EOSTR;
	}
	else {
		Xstrcpy(lstdef,buf);
		Xstrcat(lstdef,(BYTE XPTR) "  ");
		while (1) {
			Xfgets(&buf[0],LGREP,fc);
			if (buf[0] == '0') break;
			Xstrcat(lstdef,buf);	
			Xstrcat(lstdef,"  ");
		}
	}

	/* Lecture des options de traduction */
	Xfgets(&buf[0],256,fc);
	pt = 0;
/* #BG	for (i = 0; i < 11; i++) {*/
	for (i = 0; i < 9; i++) {
		Xscanf(&buf[0],&pt,&val);
		vtropt[i] = (BOOL) val;
	}

	/* Lecture de la liste des modules */
	coptcmed = coptcfed = coptcftr = coptoptr = 0;
	Xfgets(&buf[0],LGREP,fc); 
	if (buf[0] == '0') {
		lstmod[0] = EOSTR;
	}
	else {
		Xstrcpy(lstmod,buf);
		Xstrcat(lstmod,(BYTE XPTR) "  ");
		while (1) {
			Xfgets(&buf[0],LGREP,fc);
			if (buf[0] == '0') break;
			Xstrcat(lstmod,buf);	
			Xstrcat(lstmod,(BYTE XPTR) "  ");
		}
	}

	/* Lecture des touches de fonction de l'integre */
	for (i=0 ; i<10 ; ) {
		Xfgets(&buf[0],256,fc);
		pt = 0;
		p = pltfp[i];
		val = 0xff;
		while (val != 0) {
			Xscanf(&buf[0],&pt,&val);
			*p = (BYTE) val;
			p++;
		}
		prfo(128 + i,(BYTE FPTR) pltfp[i],(BYTE) Xstrlen(pltfp[i]));
		i++;
	}

	/* Lecture des touches de fonction de l'editeur de textes */
	for (i=0 ; i<10 ; ) {
		Xfgets(&buf[0],256,fc);
		pt = 0;
		p = epltfp[i];
		val = 0xff;
		while (val != 0) {
			Xscanf(&buf[0],&pt,&val);
			*p = val;
			p++;
		}
		i++;
	}

	Xfgets(&buf[0],256,fc);
	if (buf[0] != VEOF) {
		pt = 0;
		Xscanf(&buf[0],&pt,&val);
		/* recupere l'historique */
		if (hissrc.lg_liste > 1) 	purge(&hissrc);

		for ( i = 0; i < val; i ++) {
			Xfgets(&buf[0],256,fc);
			liste_histo(&hissrc, &buf[0]);
		}
	}

#ifdef ver21

/* #BG */
#ifdef OBJET

	Xfgets(&REPPIKS[0],LGREP,fc);
	if ( REPPIKS[0] == VEOF) {
		REPPIKS[0] = EOSTR;
		boolcfg = TRUE;
		Xfclose( fc );
		return( TRUE );
	}

	if (REPPIKS[0] == '0') {
		REPPIKS[0] = EOSTR;
	}
	/* test la presence de skipper */
	skipper_is_here = 0;
	MakeNom(REPPIKS, "skipper",".at",prog);
	if (Xaccess(prog,0)==0) skipper_is_here = 1;

	/* options ao,aplus */

	Xfgets(&buf[0],LGREP,fc);
	if ( buf[0] == VEOF) {
		boolcfg = TRUE;
		Xfclose( fc );
		return( TRUE );
	}

	pt = 0;
	for (i = 0; i < 4; i++) {
		Xscanf(&buf[0],&pt,&val);
		voptao[i] = (BOOL) val;
	}

	voptao[2] = (BOOL) FALSE;	/* Ces deux optimisations sont */
	voptao[3] = (BOOL) FALSE;	/* a expliciter par l'utilisateur */


	Xfgets(&buf[0],LGREP,fc);
	pt = 0;
	for (i = 0; i < 10; i++) {
		Xscanf(&buf[0],&pt,&val);
		vacti[i] = (BOOL) val;
	}
#endif /* #BG */
#endif
	Xfclose(fc);

	/* le cfg est a jour */
	boolcfg = TRUE;
	return (TRUE);	/* init OK */
}					/* lecconf */

static BOOL lectfp(nomcfg)

/*	lecture du fichier de configuration designe par 'nomcfg'
 */

BYTE XPTR nomcfg;
{					/* lecconf */
	FILE	*fc;
	int	i;
/*	char	buf[LGREP]; */
	char	buf[256];
	BYTE XPTR	p;
	BINAIRE	val;
	BINAIRE pt;

	/* Ouverture du fichier de configuration */
	fc = Xfopen(nomcfg,"r");
	if (fc == GenericNULL(FILE))
		return (FALSE);

	/* Controle la signature du fichier */
	Xfgets(&buf[0],LGREP,fc);
	if (Xstrcmp(verscfg,&buf[0]) != 0) {
		Xfclose(fc);
		return (FALSE);
	}

	/* Lecture des repertoires par defaut */
	Xfgets(buf,LGREP,fc);
	Xfgets(buf,LGREP,fc);
	Xfgets(buf,LGREP,fc);
	Xfgets(buf,LGREP,fc);
	Xfgets(buf,LGREP,fc);

	/* Lecture de la designation du fichier courant */
	Xfgets(&buf[0],LGREP,fc);

	/* Lecture de la designation du projet courant */
	Xfgets(&buf[0],LGREP,fc);

	/* Lecture de l'option d'aide */
	Xfgets(&buf[0],256,fc);
	pt = 0;
	Xscanf(&buf[0],&pt,&val);

	/* Lecture du type d'ecran pour la commande systeme */
	Xscanf(&buf[0],&pt,&val);

	/* Lecture des extensions des fichiers */
	Xfgets(buf, LGEXT,  fc);
	Xfgets(buf, LGEXT,  fc);
	Xfgets(buf, LGEXT, fc);
	Xfgets(buf, LGEXT, fc);
	Xfgets(buf, LGEXT, fc);

	/* Lecture des options de l'editeur de textes */
	Xfgets(&buf[0],256,fc);
	pt = 0;
	for (i=0; i<4; i++) {
		Xscanf(&buf[0],&pt,&val);
	}

	/* Lecture des valeurs par defaut des commandes d'edition */
	for (i = 0; i < 18; i++) {
		Xscanf(&buf[0],&pt,&val);
	}

	/* Lecture de la valeur de la tabulation */
	Xscanf(&buf[0],&pt,&val);

	/* Lecture des symboles de traduction predefinis */
	Xfgets(&buf[0],LGREP, fc); 
	pt = 0;
	if (buf[0] != '0') {
		while (1) {
			Xfgets(&buf[0],LGREP,fc);
			if (buf[0] == '0') break;
		}
	}

	/* Lecture des options de traduction */
	Xfgets(&buf[0],256,fc);
	pt = 0;
/* #BG	for (i = 0; i < 11; i++) {*/
	for (i = 0; i < 9; i++) {
		Xscanf(&buf[0],&pt,&val);
	}

	/* Lecture de la liste des modules */
	Xfgets(&buf[0],LGREP,fc); 
	if (buf[0] != '0') {
		while (1) {
			Xfgets(&buf[0],LGREP,fc);
			if (buf[0] == '0') break;
		}
	}

	/* Lecture des touches de fonction de l'integre */
	for (i=0 ; i<10 ; ) {
		Xfgets(&buf[0],256,fc);
		pt = 0;
		p = pltfp[i];
		val = 0xff;
		while (val != 0) {
			Xscanf(&buf[0],&pt,&val);
			*p = (BYTE) val;
			p++;
		}
		prfo(128 + i,(BYTE FPTR) pltfp[i],(BYTE) Xstrlen(pltfp[i]));
		i++;
	}

	/* Lecture des touches de fonction de l'editeur de textes */
	for (i=0 ; i<10 ; ) {
		Xfgets(&buf[0],256,fc);
		pt = 0;
		p = epltfp[i];
		val = 0xff;
		while (val != 0) {
			Xscanf(&buf[0],&pt,&val);
			*p = val;
			p++;
		}
		i++;
	}

	Xfclose(fc);

	return (TRUE);	/* init OK */
}					/* lecconf */

static BOOL ecrconf(nomcfg)
/*	ecriture de la configuration dans le fichier designe par 'nomcfg'
 */
BYTE XPTR	nomcfg;
{					/* ecrconf */
	FILE	*fc;
	BYTE XPTR   p;
	int	i;
	int err;
	BYTE buf[50];
	Liste XPTR p_node;

	/* on fait de la place memoire */
	purge(&cfic);

	/* Creation du fichier de configuration */
	fc = Xfopen(nomcfg,"w");
	if (fc == GenericNULL(FILE)) {
		return (FALSE);
		}

	errno = 0;
	/* Ecriture signature (no version) */
	fprintf(fc,"%s\n",verscfg);
	if (errno != 0) return(FALSE);

	/* repertoires par defaut */
/* ATTENTION A L'ECRITURE DE CHAINES VIDES  REPERTOIRES ET EXTENSIONS */

	p = REPS;			/* Repertoire des sources */
	NextOpt(&p,tmp);
	if (tmp[0] == EOSTR)
		fprintf(fc,"0\n");
	else
		fprintf(fc,"%s\n",tmp);
	if (errno != 0) return(FALSE);

	p = REPI;			/* Repertoire des includes */
	NextOpt(&p,tmp);
	if (tmp[0] == EOSTR)
		fprintf(fc,"0\n");
	else
		fprintf(fc,"%s\n",tmp);
	if (errno != 0) return(FALSE);

	p = REPM;			/* Repertoire des modules */
	NextOpt(&p,tmp);
	if (tmp[0] == EOSTR)
		fprintf(fc,"0\n");
	else
		fprintf(fc,"%s\n",tmp);
	if (errno != 0) return(FALSE);

	p = REPT;			/* Repertoire des traduits */
	NextOpt(&p,tmp);
	if (tmp[0] == EOSTR)
		fprintf(fc,"0\n");
	else
		fprintf(fc,"%s\n",tmp);
	if (errno != 0) return(FALSE);

	p = REPB;			/* Repertoire des binaires */
	NextOpt(&p,tmp);
	if (tmp[0] == EOSTR)
		fprintf(fc,"0\n");
	else
		fprintf(fc,"%s\n",tmp);
	if (errno != 0) return(FALSE);

	/* Designation du fichier courant */
	p = nomfic;
	NextOpt(&p, tmp);
	if (tmp[0] == EOSTR) {
		fprintf(fc,"0\n");
	}
	else {
		Xstrcpy(nomfic, tmp);
		Xfn_parser((BYTE FPTR) nomfic, (BYTE FPTR) tmp, 1+2+4+8+16);
		fprintf(fc,"%s\n",tmp);
	}
	if (errno != 0) return(FALSE);

	/* Designation du projet courant */
	p = nomprj;

	NextOpt(&p,tmp);

	if (tmp[0] == EOSTR) {
		fprintf(fc,"0\n");
	}
	else {
		Xstrcpy(nomprj, tmp);
		Xfn_parser((BYTE FPTR) nomprj, (BYTE FPTR) tmp, 1+2+4+8+16);
		fprintf(fc,"%s\n",tmp);
	}
	if (errno != 0) return(FALSE);

	/* Option d'affichage de l'aide ... */
	fprintf(fc,"%d ",flg_help);
	if (errno != 0) return(FALSE);
	
	/* Mode ecran pour la commande systeme */
	fprintf(fc,"%d\n",vsysopt[0]);
	if (errno != 0) return(FALSE);

	/* extensions par defaut des fichiers */
	p = &EXTS[1];
	NextOpt(&p,tmp);		/* extension fichiers sources */
	if (tmp[0] == EOSTR)
		fprintf(fc,"0\n");
	else
		fprintf(fc,"%s\n",tmp);
	if (errno != 0) return(FALSE);

	p = &EXTL[1];			/* extension fichiers listes */
	NextOpt(&p,tmp);
	if (tmp[0] == EOSTR)
		fprintf(fc,"0\n");
	else
		fprintf(fc,"%s\n",tmp);
	if (errno != 0) return(FALSE);

	p = &EXTE[1];			/* extension fichiers erreurs */
	NextOpt(&p,tmp);
	if (tmp[0] == EOSTR)
		fprintf(fc,"0\n");
	else
		fprintf(fc,"%s\n",tmp);
	if (errno != 0) return(FALSE);

	p = &EXTSAV[1];			/* extension fichiers sauvegarde */
	NextOpt(&p,tmp);
	if (tmp[0] == EOSTR)
		fprintf(fc,"0\n");
	else
		fprintf(fc,"%s\n",tmp);
	if (errno != 0) return(FALSE);

	p = &EXTPRJ[1];			/* extension fichiers projets */
	NextOpt(&p,tmp);
	if (tmp[0] == EOSTR) 
		fprintf(fc,"0\n");
	else
		fprintf(fc,"%s\n",tmp);
	if (errno != 0) return(FALSE);

	/* valeurs des options de aed */
	for (i=0; i < 4; i++) {
		fprintf(fc,"%d ",vaedopt[i]);
		if (errno != 0) return(FALSE);
	}

	/* valeurs par defaut des commandes d'edition */
	for (i = 0; i < 18; i++) {
		fprintf(fc,"%d ",vcomed[i]);
		if (errno != 0) return(FALSE);
	}

	/* valeur de la tabulation */
	fprintf(fc,"%d\n",lg_tab);
	if (errno != 0) return(FALSE);

	/* liste des symboles de traduction predefinis */
	p = lstdef;
	while (NextOpt(&p,tmp)) {
		if (tmp[0] == EOSTR) 
			fprintf(fc,"0\n");
		else
			fprintf(fc,"%s\n",tmp);
		if (errno != 0) return(FALSE);
	}
	fprintf(fc,"0\n");
	if (errno != 0) return(FALSE);

	/* Liste des options de traduction */
/* #BG	for (i = 0; i < 10; i++) {*/
	for (i = 0; i < 8; i++) {
		fprintf(fc,"%d ",vtropt[i]);
		if (errno != 0) return(FALSE);
	}
/* #BG	fprintf(fc,"%d\n",vtropt[10]);*/
	fprintf(fc,"%d\n",vtropt[8]);
	if (errno != 0) return(FALSE);

	/* Liste des modules a linker */
	p = &lstmod[0];
	while (NextOpt(&p,tmp)) {
		if (tmp[0] == EOSTR) 
			fprintf(fc,"0\n");
		else 
			fprintf(fc,"%s\n",tmp);
		if (errno != 0) return(FALSE);
		
	}
	fprintf(fc,"0\n");
	if (errno != 0) return(FALSE);

	/* Touches de fonction de l'ensemble integre */
	for (i=0; i < 10; i++) {
		p = pltfp[i];
		while (*p != EOSTR) {				
			fprintf(fc,"%d ",*p);
			if (errno != 0) return(FALSE);
			p++;
		};
		fprintf(fc,"0\n");
		if (errno != 0) return(FALSE);
	}

	/* Touches de fonction de l'editeur de textes */
	for (i=0; i < 10; i++) {
		p = epltfp[i];
		while (*p != EOSTR) {				
			fprintf(fc,"%d ",*p);
			if (errno != 0) return(FALSE);
			p++;
		};
		fprintf(fc,"0\n");
		if (errno != 0) return(FALSE);
	}

	/* Pose un caractere fin de fichier pour permettre l'edition
	 * du CFG au moyen de l'editeur
	 */

	if (hissrc.lg_liste > 1) {

		fprintf(fc,"%d \n",hissrc.lg_liste - 1);
		p_node = hissrc.lback;

		for ( i = 0; i < hissrc.lg_liste - 1; i ++) {
			Xfn_parser((BYTE FPTR) &p_node->ptfic->nom[0], (BYTE FPTR) tmp, 1+2+4+8+16);
			fprintf(fc,"%s\n",tmp);
#ifdef merde
#ifdef prologue
			Xfn_parser((BYTE FPTR) p_node->ptfic->nom, (BYTE FPTR) tmp, 1+2+4+8+16);
			fprintf(fc,"%s\n",tmp);
#else
			fprintf(fc,"%s\n",p_node->ptfic->nom);
#endif
#endif

			if (errno != 0) return(FALSE);
			p_node = p_node->back;
		}
	}
	else fprintf(fc,"%d \n",0);

#ifdef ver21

/* #BG */
#ifdef OBJET

	p = REPPIKS;			/* Repertoire des modules */
	NextOpt(&p,tmp);
	if (tmp[0] == EOSTR)
		fprintf(fc,"0\n");
	else
		fprintf(fc,"%s\n",tmp);

	if (errno != 0) return(FALSE);

	/* options ao */
	voptao[2] = FALSE;
	voptao[3] = FALSE;

	fprintf(fc,"%d ",voptao[0]);
	if (errno != 0) return(FALSE);

	fprintf(fc,"%d ",voptao[1]);
	if (errno != 0) return(FALSE);

	fprintf(fc,"%d ", voptao[2]);	/* Troisieme option toujours FAUSSE */
	if (errno != 0) return(FALSE); 

	fprintf(fc,"%d\n", voptao[3]);	/* Et la quatrieme pareille */
	if (errno != 0) return(FALSE);


	/* options d'aplus */
	for (i=0; i < 10; i++) {
		fprintf(fc,"%d ",vacti[i]);
		if (errno != 0) return(FALSE);
	}
	fprintf(fc,"%d\n",vacti[i]);
	if (errno != 0) return(FALSE);
#endif /* #BG */

#endif

#ifdef prologue
	Xfputc(VEOF,fc);
#endif
#ifdef msdos
	Xfputc(VEOF,fc);
#endif
#ifdef vms
	Xfputc(VEOF,fc);
#endif
	if (errno != 0) return(FALSE);

	Xfclose(fc);
	if (errno != 0) return(FALSE);

#ifdef unix
	liberlox(nomcfg);
#endif

	/* le cfg est a jour */
/*	boolcfg = TRUE;*/
	return (TRUE);	/* ecriture OK */
}					/* ecrconf */

static void ecrcfg()    
{

	int rep;
	
	int	mxcol,debcol,debopt,lgopt;

	mxcol = Xstrlen(inte_msg[ocftr[0]]);
	debcol = tpos[5] + Xstrlen(inte_msg[oconf[0]]) - mxcol - 1;

	lgopt = LGAFF+4;
	debopt = debcol + Xstrlen(inte_msg[ocftr[0]]) - lgopt;



	rep = ask(16,debopt,LGAFF,LGREP,nomcfg);
	while (1) {
		if (rep == -1) break;
		if (rep == -5) {
			Xclear(5,1);
			boolESC = TRUE;
			break;
		}
		if (rep >= 0) {
			if (ecrconf(nomcfg)) {
				boolcfg = TRUE;
				break;
			}
			else {
				Xbell();			
				msg_erreur(CFGTM);
			}
		}
		rep = saisie(16,debopt,LGAFF,LGREP,nomcfg);
	}

	if (!boolESC) {
		Xclear(13,1); Batb(25);
	}
}

static void leccfg()    
{

	int rep;

	int	mxcol,debcol,debopt,lgopt;

	mxcol = Xstrlen(inte_msg[ocftr[0]]);
	debcol = tpos[5] + Xstrlen(inte_msg[oconf[0]]) - mxcol - 1;

	lgopt = LGAFF+4;
	debopt = debcol + Xstrlen(inte_msg[ocftr[0]]) - lgopt;

	rep = ask(17,debopt,LGAFF,LGREP,nomcfg);
	while (1) {
		if (rep == -1) break;
		if (rep == -5) {
			Xclear(5,1); 
			boolESC = TRUE;
			break;
		}

		if (rep >= 0) {
			if (lecconf(nomcfg)) {
				affprj();
				affnomfic();
				break;
			}
			else Xbell();
		}
		rep = saisie(17,debopt,LGAFF,LGREP,nomcfg);
	}

	if (!boolESC) {
		Xclear(14,1); Batb(25);
	}
}

static int arreter()
/*	retour au systeme d'exploitation ?
 *	retourne -2 si l'utilisateur le confirme
 */
{					/* arreter */
	int	flgret;

	flgret = vmenu(5,tpos[6]-1,2,0,ofin,hfin);
	
	if (flgret == 0)
		flgret = -2;
	else if (flgret == -2)
		flgret = 1;
	else if (flgret == -3)
		flgret = MOINS_UN;
	else
		flgret = 0;

	
	Xclear(5,tpos[6]-1); 

	return (flgret);
}					/* arreter */

static BINAIRE xx_getch()
{
	BINAIRE c;

	if (boolESC) c = ESCAPE;
	else {
		c = x_getch();
		if (c == CTRLC) {
			Xclear(5,1); 
			boolESC = 1;
			c = ESCAPE;
		}	
	}
	return (c);
}

static void entete()

/*	edition de l'entete du menu principal
 */
{					/* entete */
#ifndef asfun
	Xclear(1,1);
#endif
	/* affiche ABAL V1.4a */
	
	Xatb(0); pos(1,1); 
#ifdef	VERSION666
	x_cprintf((BYTE FPTR) "abal"); 
#else
	x_cprintf((BYTE FPTR) "ABAL"); 
#endif
	x_putch(vabal); x_putch('.'); 
	x_putch(iabal); 
	x_putch(rabal); 
	x_cprintf((BYTE FPTR) nabal);
	x_putch(C_LNV); 
	affnomfic();
	x_putch(' ');	
	x_putch(C_LNV); 
	affprj();
	x_putch(' ');
	x_putch(' ');

}					/* entete */

static void affnomfic ()

/*	affichage de la designation du fichier courant
 */
{					/* affnomfic */
	pos(1,fileposition); 
	aff_zone((BYTE FPTR)inte_msg[messages[msgfic]],11);
	if (nomfic[0] == EOSTR) nomtmp[0] = EOSTR;
	else 	Xfn_parser((BYTE FPTR) nomfic,(BYTE FPTR) nomtmp,8+16);
	if (nomtmp[0] == EOSTR) {
		aff_zone((BYTE XPTR) " ? ", filecolumns);
		}
	else	{
		aff_zone(nomtmp,filecolumns);
		}
}					/* affnomfic */

static void affprj()

/*	affichage de la designation du fichier courant
 */
{					/* affnomprj */
	pos(1,projposition);
	aff_zone((BYTE FPTR)inte_msg[messages[msgprj]],11);
	if (nomprj[0] == EOSTR) nomtmp[0] = EOSTR;
	else 	Xfn_parser((BYTE FPTR) nomprj,(BYTE FPTR) nomtmp,8+16);
	if (nomtmp[0] == EOSTR)
		aff_zone(" ? ", projcolumns);
	else	{
		aff_zone(nomtmp, projcolumns);
		}
}					/* affnomprj */

/*
 *	---------------------------------
 *	h m e n u ( chaine, i, opt, hlp )
 *	---------------------------------
 *
 *	gestion du menu general / horizontal
 *	a mettre a partir de la position (2,1),
 *	il comporte 7 options designees par 'opt'.
 *	le choix possible commence par l'option i.
 *	retourne le numero de l'option choisie par l'utilisateur
 *	si 'chaine' vaut TRUE en entree, il est inutile de reffaire le
 *	menu, mais simplement de positionner sur l'option designee par 'i'.
 *
 */

static 	BINAIRE hmenu(chaine,i,opt,hlp)
BOOL 	chaine;
BINAIRE i;
int	opt[];
int	hlp[];
{					/* hmenu */
	BINAIRE	k,j,m,l;
	BINAIRE	fcar[7];
	BINAIRE largeur;

	x_bstart();
	Xatb(0);

/*	if ((chaine == 2) || (chaine == 4) || ( cico_is_graphic() )) {	*/
		entete();
		if ( conf(14) ) {
			hcadre(2,1,4,conf(2));
			}
		else 	cadre(2,2,4,conf(2));
		if (!( cico_is_graphic() )) {
			pos(2,fileposition-1); x_putch(REDEF1);
			pos(2,projposition-1); x_putch(REDEF1);
			}
		/* on rentre dans l'integre */
		if (chaine==4) chaine = 0;
/*		}	*/

	largeur = max_largeur( opt, 7 );


	j = 4; 

	if (!( cico_is_graphic() )) {
		pos(3,3);
		x_putch(' ');
		}

	for (k = 0; k < 7; k++) {
		fcar[k] = selopt(inte_msg[opt[k]]);
		tpos[k] = j;
		pos(3,j);
		if (k == i)
			HoPrint((BYTE FPTR)inte_msg[opt[k]],1); 
		else 	LoPrint((BYTE FPTR)inte_msg[opt[k]],fcar[k],0);
		j += Xstrlen(inte_msg[opt[k]]);
		}

	if (!( cico_is_graphic() )) {
		x_putch(' ');
		}

	x_bflush();

	if (chaine == 0) {
	   j = tpos[i];
	   while (1) {			/* sortie par BREAK */

		if (flg_help) { HPrint(inte_msg[hlp[i]]); }
		k = x_getch();
		if (k == 0x000A) {	/* bascule aide oui/non */
			if (flg_help) {
				if ( flg_help == 1 ) {
					flg_help = 2;
					}
				else 	flg_help = FALSE; Bpos(conf(1)-2,1); Batb(22);
				}
			else 	{
				flg_help = TRUE;
				}
			continue;
			}

		if ((k == CURD) || (k == 0x0020)) {	/* option suivante */
			x_bstart();
			Bpos(3,j); LoPrint(inte_msg[opt[i]],fcar[i],0);
			if (i < 6)
				i++;
			else	i=0;
			x_bflush();
			}

		else if (k == CURG) {	/* option precedente */
			x_bstart();
			Bpos(3,j); LoPrint(inte_msg[opt[i]],fcar[i], 0);
			if (i != 0)
				i--;
			else	i=6;
			x_bflush();
			}
		else if ((k == CR) || (k == CURB)) {
			/* valider l'option courante */
			break;
			}
		else if (k == ESCAPE) {	/* abandon */
			x_bstart();
			Bpos(3,j); 
			LoPrint(inte_msg[opt[i]],fcar[i], 0);
			i = 6;
			Bpos(3,tpos[6]);   
			HoPrint((BYTE FPTR)inte_msg[opt[6]],1); 
			x_bflush();
			}
		else if (k != CTRLC) {	/* peut etre acces direct a l'option */
			k = toupper(k);
			for (m = 0; m < 7; m++) {
				if (k == fcar[m]) {
					x_bstart();
					Bpos(3,j); LoPrint(inte_msg[opt[i]],fcar[i],0);
					i = m; j = tpos[i];
					Bpos(3,j); HoPrint((BYTE FPTR)inte_msg[opt[i]],1);
					if (flg_help) {
					    	HPrint(inte_msg[hlp[i]]);
						}
					x_bflush();
					break;
					}
				}
			if (m == 7) /* invalide */
				Xbell();
			else	break;
			}
		j = tpos[i];
		x_bstart();
		Bpos(3,j); HoPrint((BYTE FPTR)inte_msg[opt[i]],1);
		x_bflush();
	   	}
	}
	return (i);
}					/* hmenu */

static char selopt(p)
BYTE XPTR p;
{
	int i;
	for (i = 0; i < Xstrlen(p); i++) {
		if ((*(p + i) >= 'A' && *(p + i) <= 'Z') || (*(p+i) >= '0' && *(p+i) <= '9'))  {
			return(*(p + i));
		}
	}
	return(' ');
}

	/*	--------------------------------------		*/
	/*	Traitement des options du menu general		*/
	/*	--------------------------------------		*/


static int vmenu(l,c,nombre,i,opt,hlp)

/*	gestion d'un menu vertical, affiche a partir de la position (l,c),
 *	comportant 'n' options designees par 'opt', et en commencant par la
 *	'i'eme option.
 *	retourne la valeur -1 si il y a annulation.
 *	retourne la valeur -2 si saisie de fleche a droite
 *	retourne la valeur -3 si saisie de fleche a gauche
 *	retourne la valeur -4 si saisie de TABULATION     
 *	Rem:	le curseur est suppose eteint par l'appelant.
 *		le menu n'est pas efface au retour.
 *		le nombre max d'options d'un menu est limite a 10.
 */
BINAIRE l,c,nombre,i;
int	opt[], hlp[];
{						/* vmenu */
	BINAIRE	j,k,m,code;
	BINAIRE	largeur = 0;
	BINAIRE	fcar[10];
	BINAIRE n;

	BYTE buf[80];


	if (boolESC) return(MOINS_UN);
	
 	affmenu(l,c,nombre,i,opt,hlp);

	/* calcul largeur du menu */
	for (k = 0; k < nombre; k++) {
		j = Xstrlen(inte_msg[opt[k]]); fcar[k] = selopt(inte_msg[opt[k]]);
		if (j > largeur) largeur = j;
		}

	/* faire la saisie de l'option */
	j = l + 1 + i; k = i;
	while (1) {		/* sortie par return */
		Bpos(j,c+1); HoPrint(inte_msg[opt[k]], 3 ); 
		if (flg_help) { HPrint(inte_msg[hlp[k]]); }
		code = xx_getch();
		if (code == ESCAPE)	/* annulation */
			return (-1);
		else if (code == TABUL) { 	/* selection boite */
			return(k+20);		
		}
  		else if (code == 0x000A) {	/* bascule aide oui/non */
			if (flg_help) {
				if ( flg_help == 1 )  {
					flg_help = 2;
				}
				else {
					flg_help = FALSE; Bpos(conf(1)-1,1); Batb(22);
				}
			}
			else {
				flg_help = TRUE;
			}
		}
		else if (code == CR)	/* validation de l'option courante */
			return (k);
		else if (code == CURD)	/* passer au menu suivant */
			return (-2);
		else if (code == CURG)	/* passer au menu precedent */
			return (-3);
		else if ((code == CURB) || (code == 0x0020)) {
			/* option suivante */
			x_bstart();
			Bpos(j,c+1); LoPrint(inte_msg[opt[k]],fcar[k],2);
			if ((k + 1) == nombre)	{ k = 0; j = l + 1; }
			else			{ k++; j++; }
			x_bflush();
			}
		else if (code == CURH) {	/* option precedente */
			x_bstart();
			Bpos(j,c+1); LoPrint(inte_msg[opt[k]],fcar[k],2);
			if (k == 0)	{ k = nombre-1; j = l + nombre; }
			else		{ k--; j--; }
			x_bflush();
			}
		else 	{	/* acces direct */
			code = toupper(code);
			for (m = 0; m < nombre; m++) {
				if (code == fcar[m]) {
					x_bstart();
					if (flg_help) { HPrint(inte_msg[hlp[m]]);}
					Bpos(j,c+1); LoPrint(inte_msg[opt[k]],fcar[k],2);
					Bpos(l+m+1,c+1); HoPrint(inte_msg[opt[m]], 3);
					x_bflush();
					break;
					}
				}
			if (m == nombre) /* invalide */
				Xbell();
			else	return (m);
			}
		/* rafraichir l'affichage */
		Bpos(j,c+1); HoPrint(inte_msg[opt[k]], 3); 
		}
}						/* vmenu */


static int wmenu(l,c,nombre,i,opt,hlp)

/*	gestion d'un menu vertical, affiche a partir de la position (l,c),
 *	comportant 'n' options designees par 'opt', et en commencant par la
 *	'i'eme option.
 *	retourne la valeur -1 si il y a annulation.
 *	retourne la valeur -2 si saisie de fleche a droite
 *	retourne la valeur -3 si saisie de fleche a gauche
 *	retourne la valeur -4 si saisie de TABULATION     
 *	Rem:	le curseur est suppose eteint par l'appelant.
 *		le menu n'est pas efface au retour.
 *		le nombre max d'options d'un menu est limite a 10.
 */
BINAIRE l,c,nombre,i;
int	opt[], hlp[];
{						/* vmenu */
	BINAIRE	j,k,m,code;
	BINAIRE	largeur = 0;
	BINAIRE	fcar[10];
	BINAIRE n;

	BYTE buf[80];


	if (boolESC) return(MOINS_UN);
	
        waffmenu(l,c,nombre,i,opt,hlp);

	/* calcul largeur du menu */
	for (k = 0; k < nombre; k++) {
		j = Xstrlen(inte_msg[opt[k]]); fcar[k] = selopt(inte_msg[opt[k]]);
		if (j > largeur) largeur = j;
		}

	/* faire la saisie de l'option */
	j = l + 1 + i; k = i;
	while (1) {		/* sortie par return */
		Bpos(j,c+1); HoPrint(inte_msg[opt[k]], 3 ); 
		if (flg_help) { HPrint(inte_msg[hlp[k]]); }
		code = xx_getch();
		if (code == ESCAPE)	/* annulation */
			return (-1);
		else if (code == TABUL) { 	/* selection boite */
			return(k+20);		
			}
  		else if (code == 0x000A) {	/* bascule aide oui/non */
			if (flg_help) {
				if ( flg_help == 1 )  {
					flg_help = 2;
				}
				else {
					flg_help = FALSE; Bpos(conf(1)-1,1); Batb(22);
				}
			}
			else {
				flg_help = TRUE;
			}
		}
		else if (code == CR)	/* validation de l'option courante */
			return (k);
		else if (code == CURD)	/* passer au menu suivant */
			return (-2);
		else if (code == CURG)	/* passer au menu precedent */
			return (-3);
		else if ((code == CURB) || (code == 0x0020)) {
			/* option suivante */
			x_bstart();
			Bpos(j,c+1); LoPrint(inte_msg[opt[k]],fcar[k],2);
			if ((k + 1) == nombre)	{ k = 0; j = l + 1; }
			else			{ k++; j++; }
			x_bflush();
			}
		else if (code == CURH) {	/* option precedente */
			x_bstart();
			Bpos(j,c+1); LoPrint(inte_msg[opt[k]],fcar[k],2);
			if (k == 0)	{ k = nombre-1; j = l + nombre; }
			else		{ k--; j--; }
			x_bflush();
			}
		else 	{	/* acces direct */
			code = toupper(code);
			for (m = 0; m < nombre; m++) {
				if (code == fcar[m]) {
					x_bstart();
					if (flg_help) { HPrint(inte_msg[hlp[m]]);}
					Bpos(j,c+1); LoPrint(inte_msg[opt[k]],fcar[k],2);
					Bpos(l+m+1,c+1); HoPrint(inte_msg[opt[m]], 3);
					x_bflush();
					break;
					}
				}
			if (m == nombre) /* invalide */
				Xbell();
			else	return (m);
			}
		/* rafraichir l'affichage */
		Bpos(j,c+1); HoPrint(inte_msg[opt[k]], 3); 
		}
}						/* vmenu */


static int waffmenu(l,c,nombre,i,opt,hlp)

/*	affichage d'un menu vertical, affiche a partir de la position (l,c),
 *	comportant 'n' options designees par 'opt', et en commencant par la
 *	'i'eme option.
 *	retourne rien
 *	Rem:	le curseur est suppose eteint par l'appelant.
 *		le menu n'est pas efface au retour.
 *		le nombre max d'options d'un menu est limite a 10.
 */

BINAIRE l,c,nombre,i;
int	opt[], hlp[];
{						/* affmenu */
	BINAIRE	j,k,p,m,code;
	BINAIRE	largeur=0;
	BINAIRE	fcar[10];
	BINAIRE n;

	/* calcul largeur du menu */
	for (k = 0; k < nombre; k++) {
		j = lendollar(inte_msg[opt[k]]); 
		fcar[k] = selopt(inte_msg[opt[k]]);
		if (j > largeur) largeur = j;
		}


	/* ---------------------------------- */
	/* affichage du menu : mode graphique */
	/* ---------------------------------- */
	textual_wilzone(c-1,l-1,largeur+4,nombre+2,0,AGC.menuframe);

	for (k = 0; k < nombre; k++) {
		Bpos(l+k+1,c+1);
		LoPrint(inte_msg[opt[k]],fcar[k],2);
		}
	return(0);
}

static int affmenu(l,c,nombre,i,opt,hlp)

/*	affichage d'un menu vertical, affiche a partir de la position (l,c),
 *	comportant 'n' options designees par 'opt', et en commencant par la
 *	'i'eme option.
 *	retourne rien
 *	Rem:	le curseur est suppose eteint par l'appelant.
 *		le menu n'est pas efface au retour.
 *		le nombre max d'options d'un menu est limite a 10.
 */

BINAIRE l,c,nombre,i;
int	opt[], hlp[];
{						/* affmenu */
	BINAIRE	j,k,p,m,code;
	BINAIRE	largeur=0;
	BINAIRE	fcar[10];
	BINAIRE n;

	/* calcul largeur du menu */
	for (k = 0; k < nombre; k++) {
		j = lendollar(inte_msg[opt[k]]); 
		fcar[k] = selopt(inte_msg[opt[k]]);
		if (j > largeur) largeur = j;
		}


	if ( cico_is_graphic() ) { 

		/* ---------------------------------- */
		/* affichage du menu : mode graphique */
		/* ---------------------------------- */
		textual_filzone(c,l,largeur+4,nombre+2,19,12);
		textual_filzone(c-1,l-1,largeur+4,nombre+2,0,AGC.menuframe);

		for (k = 0; k < nombre; k++) {
			Bpos(l+k+1,c+1);
			LoPrint(inte_msg[opt[k]],fcar[k],2);
			}

		}
	else	{
		/* ------------------------------ */
		/* affichage du menu : mode texte */
		/* ------------------------------ */
		x_bstart();

		Xatb(0);

		cadre(l,c,l + nombre + 1,c + largeur+3); 

		j = l + 1;

		for (k = 0; k < nombre; k++) {

			/*------------ */
			/* 1 ere Col.  */
			/*------------ */
			pos(j,c+1);
			if (k == i) {
				XPrint(inte_msg[opt[k]], largeur );
				}
			else 	{
				Print(inte_msg[opt[k]],fcar[k], largeur);
				}
			j++;

		
			}
		x_bflush();
		}

	return(0);
}

static void HPrint(pt)
BYTE XPTR  pt;
{
	BINAIRE largeur, n,i;
	BYTE buf[10];
	BYTE out[80];
	int	nbc;
	if ( flg_help == 1 ) {
		x_bstart();
		Xatb(0);
		largeur = Xstrlen( pt );
		if ( cico_is_graphic() ) {
			nbc = (conf(2) - 2);
			textual_filzone(0,conf(1)-2,conf(2),2,0,AGC.menuframe);
			Bpos(conf(1),2);
			}
		else	{
			nbc = conf(2)-1;
			Bpos(conf(1),1);
			}
		x_cprintf( (BYTE FPTR) pt );

	     	for (n=largeur; n < nbc ; n++) {
			x_putch(' ');
			}
		x_bflush();
		}	

	if ( flg_help == 2 ) {
		/* affichage des touches de fonctions */
		Bpos(conf(1)-1,1);

		/* premiere ligne */
		out[0] = EOSTR;
		for (n=0; n < 5; n++ ) {
			sprintf(&out[Xstrlen(out)], "F%c :%s ", '1'+ n, &inte_msg[htfp[n]][1]);
		}		
		x_cprintf((BYTE FPTR) out );
		for (i=Xstrlen(out); i < 79; i++) {
			x_putch(' ');
		}
			
		/* deuxieme ligne */

		Bpos(conf(1),1);
		out[0] = EOSTR;
		for (; n < 9; n++ ) {
			itoh(buf, n);
			sprintf(&out[Xstrlen(out)], "F%c :%s ", '1'+n, &inte_msg[htfp[n]][1]);
		}		
		sprintf(&out[Xstrlen(out)], "F10:%s", &inte_msg[htfp[n]][1]);

		x_cprintf((BYTE FPTR) out );
		for (i=Xstrlen(out); i < 79; i++) {
			x_putch(' ');
		}
		
	}
}

/*
 *	-------------
 *	V S E L E C T
 *	-------------
 *	gestion d'un menu de selection vertical, affiche a partir de la
 *	position (l,c), comportant 'n' options designees par 'opt', et
 *	en commencant par la 'i'eme option.
 *	les options sont supposees avoir des valeurs booleenes (oui/non)
 *	le resultat est rendu dans le tableau 'vopt'
 *	Rem: le curseur est suppose eteint par l'appelant.
 *      retour de la fonction :
 *		ESC : - 1
 *		CURD : -2
 *              CURG : -3
 */

static int vselect(l,c,n,i,topt,vopt,hopt)

BINAIRE l,c,n,i;
int	topt[];
BOOL	vopt[];
int     hopt[];
{						/* vselect */
	BINAIRE	j,code,m;
	BINAIRE	largeur = 0;
	int k;
	BINAIRE	fcar[11];

#ifdef buf_cico
		x_bstart();
#endif

	Xatb(25);
	/* calcul largeur du menu */

	for (k = 0; k < n; k++) {
		fcar[k] = selopt(inte_msg[topt[k]]);
		j = Xstrlen(inte_msg[topt[k]]);
		if (j > largeur) largeur = j;
		}

	largeur += 4;	/* compter la bordure et les reponses (oui/non) */
	/* affichage du menu */


	j = l + 1;
	Xatb(0);

	/* ----------- */
	/* 1 ere Ligne */
	/* ----------- */
	if ( cico_is_graphic() ) {
		cadre(l,c,l + n + 1,c + largeur);

		for (k = 0; k < n; k++) {
			Bpos(l+k+1,c+1);
			if ( k == i )
				HoCheck(inte_msg[topt[k]],vopt[k],(largeur-4));
			else	LoCheck(inte_msg[topt[k]],vopt[k],(largeur-4));
			}
		}
	else	{
		cadre(l,c,l + n + 1,c + largeur);

		for (k = 0; k < n; k++) {
			if (k == i) {
				Bpos(j,c+1); HoPrint(inte_msg[topt[k]], 1 );
				}
			else 	{
				Bpos(j,c+1); LoPrint(inte_msg[topt[k]],fcar[k],2);
				}
			pos(j,c+1+largeur-4);
			if (vopt[k]) x_cprintf((BYTE FPTR)inte_msg[MSGoui]);
			else         x_cprintf((BYTE FPTR)inte_msg[MSGnon]);
			if (k == i) Xatb(0);
	
			j++;

			}

		}		


	x_bflush();
	j = l + 1 + i; k = i;
 	while (1) {		/* sortie par BREAK */
		if (flg_help) {
			 HPrint(inte_msg[hopt[k]]);  
			}
		code = xx_getch();
		if (code == ESCAPE)	{/* sortie */
			k = -1;
			break;
		}
  		else if (code == 0x000A) {	/* bascule aide oui/non */
			if (flg_help) {
				if (flg_help == 1 ) {
					flg_help = 2;
					}
				else 	{
					flg_help = FALSE; Bpos(conf(1)-2,1); Batb(22);
					}
				}
			else 	{
				flg_help = TRUE;
				}
			}
		else if (code == CURD) {
			k = -2;
			break;
			}
		else if (code == CURG) {
			k = -3;
			break;
			}
		else if (code == TABUL) {
			k += 20;
			break;
			}
		else if (code == CR) break;


		else if (code == 0x0020 || toupper(code) == fcar[k]) {
			/* changement de l'option courante */
			x_bstart();
			Xatb(2);
			if ( cico_is_graphic() ) {
				if (vopt[k]) 	{ 	vopt[k] = FALSE;  	}
				else 		{	vopt[k] = TRUE; 	}
				Bpos(l+k+1,c+1);
				LoCheck(inte_msg[topt[k]],vopt[k],(largeur-4));
				}
			else	{
				pos(j,(c + 1 + largeur - 4 ) );
				if (vopt[k]) {
					vopt[k] = FALSE; 
					x_cprintf((BYTE FPTR)inte_msg[MSGnon]);
					}
				else 	{
					vopt[k] = TRUE; 
					x_cprintf((BYTE FPTR)inte_msg[MSGoui]);
					}
				Xatb(0); 
				}
			continue;
			}
		else if (code == CURB) { /* option suivante */
			x_bstart();
			if ( cico_is_graphic() ) {
				Bpos(l+k+1,c+1);
				LoCheck(inte_msg[topt[k]],vopt[k],(largeur-4));
				}
			else	{
				pos(j,c+1); 
				Print(inte_msg[topt[k]],fcar[k],largeur-4);
				if (vopt[k]) x_cprintf((BYTE FPTR)inte_msg[MSGoui]);
				else         x_cprintf((BYTE FPTR)inte_msg[MSGnon]);
				}
			if ((k + 1) == n)	{ k = 0; j = l + 1; }
			else			{ k++; j++; }
			}
		else if (code == CURH) {	/* option precedente */
			x_bstart();
			if ( cico_is_graphic() ) {
				Bpos(l+k+1,c+1);
				LoCheck(inte_msg[topt[k]],vopt[k],(largeur-4));
				}
			else	{
				pos(j,c+1);
				Print(inte_msg[topt[k]],fcar[k],largeur - 4 );
				if (vopt[k]) x_cprintf((BYTE FPTR)inte_msg[MSGoui]);
				else         x_cprintf((BYTE FPTR)inte_msg[MSGnon]);
				}
			if (k == 0)	{ k = n-1; j = l + n; }
			else		{ k--; j--; }
			}
		else	{
			x_bstart();
			code = toupper(code);
			for (m = 0; m < n; m++) {
				if (code == fcar[m]) {
					if ( cico_is_graphic() ) {
						Bpos(l+k+1,c+1);
						LoCheck(inte_msg[topt[k]],vopt[k],(largeur-4));
						}
					else	{
						pos(j,c+1); 
						Print(inte_msg[topt[k]],fcar[k],largeur - 4);
						if (vopt[k]) {
							x_cprintf((BYTE FPTR)inte_msg[MSGoui]);
							}
						else 	{
							x_cprintf((BYTE FPTR)inte_msg[MSGnon]);
							}
						}
					if ( cico_is_graphic() ) {
						pos(l+m+1,c+1);
						if (vopt[m]) 	{ 	vopt[m] = FALSE;  	}
						else 		{	vopt[m] = TRUE; 	}
						LoCheck(inte_msg[topt[m]],vopt[m],(largeur-4));
						}
					else	{
						pos(l+m+1,c+1);
						XPrint(inte_msg[topt[m]], largeur - 4);
						Xatb(2);
						if (vopt[m]) {
							vopt[m] = FALSE; x_cprintf((BYTE FPTR)inte_msg[MSGnon]);
							}
						else 	{
							vopt[m] = TRUE; x_cprintf((BYTE FPTR)inte_msg[MSGoui]);
							}
						}
					Xatb(0); 
					break;
				}
			}
			if (m == n) Xbell();
			else 	{
				k = m;
				j = l+m+1;
				}
			}
		/* rafraichir l'affichage */
		x_bstart();
		if ( cico_is_graphic() ) {
			Bpos(l+k+1,c+1);
			HoCheck(inte_msg[topt[k]],vopt[k],(largeur-4));
			}
		else	{
			Xatb(2);
			pos(j,c+1); 
			XPrint(inte_msg[topt[k]], largeur - 4 );
			Xatb(0);
			pos(j,c+1+largeur-4);
			if (vopt[k]) x_cprintf((BYTE FPTR)inte_msg[MSGoui]);
			else         x_cprintf((BYTE FPTR)inte_msg[MSGnon]);
			}
		x_bflush();

		}
	return (k);
}						/* vselect */

/*****************/

static BOOL init()

/*	initialisation generale 
 */
{					/* init */
	int	i;

/*	booleen efface			*/
/* 	Si 1 pas d'Xatb(22) 		*/


	initscreen();  

	FILLIN;

	Xclear(0,1);

	/* init des variables par defaut */
	tab_ext[0] = &EXTS[1];
	tab_ext[1] = &EXTE[1];
	tab_ext[2] = &EXTL[1];
	tab_ext[3] = &EXTSAV[1];
	tab_ext[4] = &EXTPRJ[1];

	tab_rep[0] = &REPS[0];
	tab_rep[1] = &REPI[0];
	tab_rep[2] = &REPM[0];
	tab_rep[3] = &REPT[0];
	tab_rep[4] = &REPB[0];
#ifdef ver21
	if ( NBREP > 5 )
		tab_rep[5] = &REPPIKS[0];
	
#endif
	Xclear(1,1);

	return (TRUE);	/* init OK */
}					/* init */

static void initscreen()

/*	initialisation des acces au terminal
 */
{					/* initscreen */
	/* initialisation du terminal */
#ifdef vms
	qio_usage_flag = 0;
#endif
	prndest = 1; err_val = 0;

	ABAL_INIT_TERM();

	init_tfp();

	Batb(25); Batb(0);

}					/* initscreen */

static void final()
/*	fin d'execution
 */
{					/* final */
	finscreen();
}					/* final */

static void finscreen()
/*	remettre le terminal en etat "standard"
 */
{					/* finscreen */

	/* remettre les touches de foctions */
	rest_tfp();

	Batb(26); 
	atb(0);
	x_putch((BYTE) 0x0d);
	ABAL_FIN_TERM();
}					/* finscreen */

static void init_tfp() 
{
	BYTE i;
	BINAIRE nbtfp;


	ESCAPE = (BYTE) 0x001B;
	CURB = (BYTE) 0x0018;		/* ctrl-X */
	CURH = (BYTE) 0x0005;		/* ctrl-E */
	CURD = (BYTE) 0x0004;		/* ctrl-D */
	CURG = (BYTE) 0x0011;		/* ctrl-Q */

	CTRLH = (BYTE) 0x0008;		/* ctrl-H */

	lcfo(1,(BYTE FPTR) SAVCURD,32); prfo(1,(BYTE FPTR)&CURD,1);
	lcfo(4,(BYTE FPTR)SAVCURB,32); prfo(4,(BYTE FPTR)&CURB,1);
	lcfo(3,(BYTE FPTR)SAVCURH,32); prfo(3,(BYTE FPTR)&CURH,1);
	lcfo(2,(BYTE FPTR)SAVCURG,32); prfo(2,(BYTE FPTR)&CURG,1);

	lcfo(0x00AC,(BYTE FPTR)ST7F,32); T7F = (BYTE) 0x007f; prfo(0x00ac,(BYTE FPTR)&T7F,1); /*Annul */
	
	/* sauvegarde des touches fonction */
	nbtfp = conf(9);
	if (nbtfp >= 10) {
#ifdef prologue
		for (i=128; i < 138; i++) {
			lcfo(i,(BYTE FPTR)pstfp[i-128],LGTFP);
		}

#endif
		for (i=128; i < 138; i++) {
			Xstrcpy(pltfp[i-128], inte_msg[msg_tfp[i-128]]);
			prfo(i,(BYTE FPTR) pltfp[i-128], Xstrlen(pltfp[i-128]));
		}
		/* Alt-F1 */
		prfo(158, (BYTE FPTR) inte_msg[MTFP10], Xstrlen(inte_msg[MTFP10]));
	}

	
}

static void reinit_tfp() 
{
	BYTE i;
	BINAIRE nbtfp;


	ESCAPE = (BYTE) 0x001B;
	CURB = (BYTE) 0x0018;		/* ctrl-X */
	CURH = (BYTE) 0x0005;		/* ctrl-E */
	CURD = (BYTE) 0x0004;		/* ctrl-D */
	CURG = (BYTE) 0x0011;		/* ctrl-Q */

	CTRLH = (BYTE) 0x0008;		/* ctrl-H */

	lcfo(1,(BYTE FPTR) SAVCURD,32); prfo(1,(BYTE FPTR)&CURD,1);
	lcfo(4,(BYTE FPTR) SAVCURB,32); prfo(4,(BYTE FPTR)&CURB,1);
	lcfo(3,(BYTE FPTR) SAVCURH,32); prfo(3,(BYTE FPTR)&CURH,1);
	lcfo(2,(BYTE FPTR) SAVCURG,32); prfo(2,(BYTE FPTR)&CURG,1);

	lcfo(0x00AC,(BYTE FPTR) ST7F,32); T7F = (BYTE) 0x007f; prfo(0x00ac,(BYTE FPTR)&T7F,1); /*Annul */
	
	/* sauvegarde des touches fonction */
	nbtfp = conf(9);
	if (nbtfp >= 10) {

		for (i=128; i < 138; i++) {
#ifdef prologue
			lcfo(i,(BYTE FPTR)pstfp[i-128],LGTFP);
#endif
			prfo(i,(BYTE FPTR)pltfp[i-128], Xstrlen(pltfp[i-128])); /* Modif du 03/02/93 */
			}
		}
	FILLIN;
	pos(5,1);
	Xclear(5,1);
}

static void rest_tfp() 
{
	BYTE i;

#ifdef prologue
	for (i=128; i < 138; i++) {
		prfo(i,(BYTE FPTR)pstfp[i-128],LGTFP-1);
	}
#endif
	prfo(1,(BYTE FPTR)SAVCURD,(BYTE) Xstrlen(SAVCURD));
	prfo(4,(BYTE FPTR)SAVCURB,(BYTE) Xstrlen(SAVCURB));
	prfo(3,(BYTE FPTR)SAVCURH,(BYTE) Xstrlen(SAVCURH));
	prfo(2,(BYTE FPTR)SAVCURG,(BYTE) Xstrlen(SAVCURG));

	prfo(0x00AC,(BYTE FPTR)ST7F,Xstrlen(ST7F));

}

/*global*/ void cadre(ld,cd,lf,cf)

/*	dessin d'un 'cadre' avec les caracteres semi-graphiques
 *	qui a pour positions diagonales (ld,cd) et (lf,cf)
 */

BINAIRE	ld,cd,lf,cf;
{					/* cadre */

#ifdef merde

	BINAIRE i,j,lg,ht,k;

	Xatb(0);
	
	lg = cf - cd;
	pos(ld,cd); 

	x_putch(C_CHG);

	for (i = 1; i < lg; i++) {
		x_putch(C_LNH);

	}

	x_putch(C_CHD);

	ht = lf - ld;
	j = ld + 1;
	for (i = 1; i < ht; i++, j++) {
		pos(j,cd); x_putch(C_LNV);
		for (k=cd+1; k < cf; k++) x_putch(' ');
		pos(j,cf); x_putch(C_LNV);
	}
	pos(lf,cd); x_putch(C_CBG);
	for (i = 1; i < lg; i++)
		x_putch(C_LNH);
	x_putch(C_CBD);
*/
#else

	BINAIRE i,j,lg,ht,k;
	BINAIRE F;

	BYTE buf[30];

	if ( cico_is_graphic() ) {
		textual_cadre(cd,ld,cf,lf);
		}
	else	{
		Xatb(0);
	
		lg = cf - cd;
		pos(ld,cd); 

		x_putch(C_CHG);

		for (i = 1; i < lg; i++) {
			x_putch(C_LNH);
			}

		x_putch(C_CHD);

		ht = lf - ld;
		j = ld + 1;
		for (i = 1; i < ht; i++, j++) {

			pos(j,cd); x_putch(C_LNV);

			for (k=cd+1; k < cf; k++) x_putch(' ');

			pos(j,cf); x_putch(C_LNV);

			}

		pos(lf,cd); x_putch(C_CBG);
		for (i = 1; i < lg; i++)
			x_putch(C_LNH);
		x_putch(C_CBD);
		}
#endif
	return;
}					/* cadre */

/*global*/ void hcadre(ld,cd,lf,cf)

/*	dessin d'un 'cadre' avec les caracteres semi-graphiques
 *	qui a pour positions diagonales (ld,cd) et (lf,cf)
 */

BINAIRE	ld,cd,lf,cf;
{					/* cadre */


	BINAIRE i,j,lg,ht,k;
	BINAIRE F;

	BYTE buf[30];

	if ( cico_is_graphic() ) {
		textual_cadre(cd,ld,cf,lf);
		}
	else	{

		Xatb(0);
	
		lg = cf - cd;
		pos(ld,cd); 

		x_putch(C_LNH);

		for (i = 1; i < lg; i++) {
			x_putch(C_LNH);
			}
		x_putch(C_LNH);

		ht = lf - ld;
		j = ld + 1;
		for (i = 1; i < ht; i++, j++) {

			pos(j,cd); x_putch(' ');

			for (k=cd+1; k < cf; k++) x_putch(' ');

			pos(j,cf); x_putch(' ');

			}

		pos(lf,cd); x_putch(' ');
		for (i = 1; i < lg; i++)
			x_putch(' ');
		x_putch(' ');
		}
	return;

}					/* cadre */

/*global*/ void Xatb(c)
BINAIRE c;
{
	if (c == 2) {
	   if (conf(14) == 1) { 
		backgr(4);
		foregr(15);
		return;
	   }
	}
	if (c == 0) {
		if (conf(14) == 1) { 
			atb(0);
			backgr(6);
			foregr(0);
			return;
		}
	}

	atb(c);  	
}


static BOOL definit()
/*	initialisation par defaut en l'absence d'un fichier de configuration
 */
{					/* definit */
	BYTE XPTR	p;
	int i;

#if unix || vms
	flag_modterm = FALSE; /* par defaut initerm apres run d'une commande */
#endif

	/* par defaut le cfg n'est pas sauvegarde */
	boolcfg = FALSE;

	/* repertoires par defaut = repertoires courant */
	/* designation du fichier courant */
	nomfic[0] = EOSTR;

	/* designation d'utilitaire	*/
	argecran[0] = EOSTR;
	argtrans[0] = EOSTR;
	argtsf[0] = EOSTR;
	/* #BG argsvsi[0] = EOSTR;*/
	/* #BG argrtsi[0] = EOSTR;*/
	argrtam[0] = EOSTR;
	argsvam[0] = EOSTR;
	argfrmc[0] = EOSTR;
	argfrbd[0] = EOSTR;
	argsys[0] = EOSTR;


	/* affichage de l'aide en permanence */
	flg_help = TRUE;

	/* extensions par defaut des fichiers */

#ifdef prologue
	Xstrcpy(EXTS, SEPTYP);
	Xstrcat(EXTS, "S");
	Xstrcpy(EXTL, SEPTYP);
	Xstrcat(EXTL, "L");
	Xstrcpy(EXTE, SEPTYP);
	Xstrcat(EXTE, "E");
	Xstrcpy(EXTSAV, SEPTYP);
	Xstrcat(EXTSAV, "A");

	Xstrcpy(EXTPRJ, SEPTYP);
	Xstrcat(EXTPRJ, "MK");

	Xstrcpy(EXTT,SEPTYP);
	Xstrcat(EXTT,"AT");
	Xstrcpy(EXTB,SEPTYP);
	Xstrcat(EXTB,"XP");
#endif
#ifdef msdos
	Xstrcpy(EXTS, SEPTYP);
	Xstrcat(EXTS, "S");
	Xstrcpy(EXTL, SEPTYP);
	Xstrcat(EXTL, "LST");
	Xstrcpy(EXTE, SEPTYP);
	Xstrcat(EXTE, "ERR");
	Xstrcpy(EXTSAV, SEPTYP);
	Xstrcat(EXTSAV, "BAK");

	Xstrcpy(EXTPRJ, SEPTYP);
	Xstrcat(EXTPRJ, "MK");

	Xstrcpy(EXTT,SEPTYP);
	Xstrcat(EXTT,"AT");
	Xstrcpy(EXTB,SEPTYP);
	Xstrcat(EXTB,"EXE");
#endif
#ifdef unix

	Xstrcpy(EXTS, SEPTYP);
	Xstrcat(EXTS, "s");
	Xstrcpy(EXTL, SEPTYP);
	Xstrcat(EXTL, "lst");
	Xstrcpy(EXTE, SEPTYP);
	Xstrcat(EXTE, "err");
	Xstrcpy(EXTSAV, SEPTYP);
	Xstrcat(EXTSAV, "bak");

	Xstrcpy(EXTPRJ, SEPTYP);
	Xstrcat(EXTPRJ, "mf");

	Xstrcpy(EXTT,SEPTYP);
	Xstrcat(EXTT,"at");

	EXTB[0] = EOSTR;

#endif
#ifdef vms
	/* Jeux de caractere prologue */
	if (getenv("PROLOGUE") != GenericNULL(char) ) {
		C_CHG =	(BYTE) 0x00DA;	/* coin haut et gauche */
		C_LNH =	(BYTE) 0x00C4;	/* ligne horizontale */
		C_CHD =	(BYTE) 0x00BF;	/* coin haut et droit */
		C_CBG =	(BYTE) 0x00C0;	/* coin bas et gauche */
		C_CBD =	(BYTE) 0x00D9;	/* coin bas et droit */
		C_LNV = (BYTE) 0x00B3;	/* ligne verticale */
		REDEF1 = (BYTE) 0x00C1; /* intersection */
	}

	Xstrcpy(EXTS, SEPTYP);
	Xstrcat(EXTS, "S");
	Xstrcpy(EXTL, SEPTYP);
	Xstrcat(EXTL, "LST");
	Xstrcpy(EXTE, SEPTYP);
	Xstrcat(EXTE, "ERR");
	Xstrcpy(EXTSAV, SEPTYP);
	Xstrcat(EXTSAV, "BAK");

	Xstrcpy(EXTPRJ, SEPTYP);
	Xstrcat(EXTPRJ, "MK");

	Xstrcpy(EXTT,SEPTYP);
	Xstrcat(EXTT,"AT");
	EXTB[0] = EOSTR;

#endif

	/* valeurs par defaut des commandes d'edition */

	vcomed[0] = (BYTE) 0x0010;	/* ctrl-P */
	vcomed[1] = (BYTE) 0x0002;	/* ctrl-B */
	vcomed[2] = (BYTE) 0x0003;	/* ctrl-C */
	vcomed[3] = (BYTE) 0x0012;	/* ctrl-R */
	vcomed[4] = (BYTE) 0x000C;	/* ctrl-L */
	vcomed[5] = (BYTE) 0x0006;	/* ctrl-F */
	vcomed[6] = (BYTE) 0x0001;	/* ctrl-A */
	vcomed[7] = (BYTE) 0x000E;	/* ctrl-N */
	vcomed[8] = (BYTE) 0x0019;	/* ctrl-Y */
	vcomed[9] = (BYTE) 0x0007;	/* ctrl-G */
	vcomed[10] = (BYTE) 0x0008;	/* ctrl-H */
	vcomed[11] = (BYTE) 0x000B;	/* ctrl-K */
	vcomed[12] = (BYTE) 0x0015;	/* ctrl-U */
	vcomed[13] = (BYTE) 0x001A;	/* ctrl-Z */
	vcomed[14] = (BYTE) 0x000F;	/* ctrl-O */
	vcomed[15] = (BYTE) 0x0016;	/* ctrl-V */
	vcomed[16] = (BYTE) 0x000A;	/* ctrl-J */
	vcomed[17] = (BYTE) 0x0014;	/* ctrl-T */

	lg_tab = 8;

	/* valeurs par defaut des options de traduction */
	nbpredef = 0;

/* #BG
	if (ModeAPLUS == TRUE) 
		vtropt[0] = TRUE;	// presence de APLUS
	else	vtropt[0] = FALSE;
	vtropt[1] = TRUE;		// debug
	vtropt[2] = FALSE;		// fichier liste
	vtropt[3] = FALSE;
	vtropt[4] = TRUE;		// trace automatique d'erreur
	vtropt[5] = FALSE;
	vtropt[6] = FALSE;
	vtropt[7] = FALSE;
	vtropt[8] = TRUE;		// bibmath
	vtropt[9] = FALSE;		// ald enchaine
	vtropt[10] = FALSE;		// post optmiseur enchaine
*/
	vtropt[0] = TRUE;		// debug
	vtropt[1] = FALSE;		// fichier liste
	vtropt[2] = FALSE;
	vtropt[3] = TRUE;		// trace automatique d'erreur
	vtropt[4] = FALSE;
	vtropt[5] = FALSE;
	vtropt[6] = FALSE;
	vtropt[7] = TRUE;		// bibmath
	vtropt[8] = FALSE;		// ald enchaine

	/* valeur par defaut de aed */
	vaedopt[0] = vaedopt[1] = FALSE;
	vaedopt[2] = vaedopt[3] = TRUE;

	/* init de l'ecran systeme */
	coptsys = 0;
	vsysopt[0] = FALSE;	/* par def. mode fenetre */
#ifdef	VERSION666
	vsysopt[1] = 1;
	AbalToolVersion=3;
#else
	vsysopt[1] = 0;
	AbalToolVersion=2;
#endif

	coptao = 0;
	for (i=0; i<2; i++) {
		voptao[i] = TRUE;
	}
	for (i; i<4; i++) {
		voptao[i] = FALSE;
	}
	
	eacti = 0;
	for (i=0; i< 10; i++) {
		vacti[i] = FALSE;
	}
	vacti[0] = TRUE; /* atr enchaine */
	eacti = 0;

	for (i=0; i < 2; i++){
		epobjp[i][0] = EOSTR;
	}
	eobjp = 0;

	/* amake */
	for (i=0; i < 5; i++ ){
		voptam[i] = FALSE;
	}

	coptam = 0;

	/* browse */
	for (i=0; i < 4; i++) {
		voptbr[i] = FALSE;
	}
	
	argbrowse[0] = EOSTR;

	/* linker */

	voptald[0] = FALSE;

	
	/* init des options courantes des menus */
	
	nbmods = coptcmed = coptcfed = coptcftr = coptoptr = 0;

	iext = 0;

	/* init. presence argument / */
	wrep = 0;

	/* init du fichier cfg */
	Xstrcpy(nomcfg, nomficcfg);

	/* creation du fichier unique intermediaire */
	makenom(cfgtmp,0);

	valeur_in   = atoi( &inte_msg[MCOU01][4] );
#ifdef prologue
	valeur_out = x_get_filler();
#else
	valeur_out  = atoi(&inte_msg[MCOU02][4] );
#endif

	/* init liste des modules a linker */
	return (TRUE);	/* init OK */
}					/* definit */

static void conftrad()
/*	gestion de la configuration du traducteur	*/
{					/* conftrad */
	int	menu=0;
	int	rep,majdef;
	int	mxcol,debcol,debopt,lgopt;
/*
	mxcol = Xstrlen(inte_msg[ocftr[0]]);
	debcol = tpos[menu] + Xstrlen(inte_msg[oconf[0]]) - mxcol - 2;

	lgopt = Xstrlen(inte_msg[stropt[0]]) + 3;
	debopt = debcol + Xstrlen(inte_msg[ocftr[0]]) - lgopt - 1;
*/
	mxcol = Xstrlen(inte_msg[ocftr[0]]);
	debcol = tpos[5] + Xstrlen(inte_msg[oconf[0]]) - mxcol - 2;

	lgopt = Xstrlen(inte_msg[stropt[0]]) + 4;
	debopt = tpos[5] - lgopt - 3;
/*	debopt = debcol + Xstrlen(inte_msg[ocftr[0]]) - lgopt - 1;	*/

	while (1) {		/* sortie par BREAK */
		rep = vmenu(10,debcol,2,coptcftr,ocftr,hcftr);
		if (rep == -1)	/* annulation */
			break;
		else if ((rep == -2) || (rep == -3)) {
			/* menu suivant ou precedent : pas de sens ici */
			Xbell(); 
			}
		else if (rep == 0) { /* selection des options */
			coptcftr = rep;
			do 	{
/* #BG				rep  = vselect(10,debopt,11,coptoptr,stropt,vtropt,htropt);*/
				rep  = vselect(10,debopt,9,coptoptr,stropt,vtropt,htropt);
				
				}
			while (rep == -2 || rep == -3 || rep >= 20);

			if (rep >= 0) {
				coptoptr = rep;
				/* cfg modifie */
				boolcfg = FALSE;
				}
			Xclear(10,debopt); 
/* #BG			affmenu(5,tpos[5]-1,10,coconf,oconf,hconf);*/
			affmenu(5,tpos[5]-1,8,coconf,oconf,hconf);
			}
		else if (rep == 1) { /* selection des definitions */
			coptcftr = rep;
			getdefs();
/* #BG			affmenu(5,tpos[5]-1,10,coconf,oconf,hconf);*/
			affmenu(5,tpos[5]-1,8,coconf,oconf,hconf);
			}
		else 	Xbell();
	}
	Xclear(5,debcol); 
}					/* conftrad */

static void getdefs()
{					/* getdefs */
	int 	rep;
	int	mxcol,debcol,debopt,lgopt;

	mxcol = Xstrlen(inte_msg[ocftr[0]]);
	debcol = tpos[5] + Xstrlen(inte_msg[oconf[0]]) - mxcol - 2;

	lgopt = LGAFF+4;
	debopt = debcol + Xstrlen(inte_msg[ocftr[0]]) - lgopt;

	rep = ask(14,debopt,LGAFF,LGARGU,lstdef);			
	if (rep == -5) {
		Xclear(5,1); 
		boolESC = TRUE;
		}
	else {
		Xclear(12,1); Batb(25); 
		}
	/* cfg modifie */
	if (rep > 0) boolcfg = FALSE;
	
}					/* getdefs */

static void confedit()
/*	gestion de la configuration de l'editeur de textes
 */
{					/* confedit */
	int	rep;
	BINAIRE	i,k;
	int	mxcol;
	int 	debcol;

	mxcol = Xstrlen(inte_msg[ocfedit[0]]);
	debcol = tpos[5] + Xstrlen(inte_msg[oconf[0]]) - mxcol - 2;

	while (1) {		/* sortie par BREAK */
		do 	{
			rep = vmenu(8,debcol,3,coptcfed,ocfedit,hcfedit);
			}
		while (rep == -2 || rep == -3);

		if (rep == -1) {	/* annulation */
			break;
			}
/*		if ((rep == -2) || (rep == -3)) {
			Xbell(); 
			rep = vmenu(5,tpos[5]-1,8,coconf,oconf,hconf);
			}
*/
		if (rep == 0) { /* commandes de l'editeur */
			coptcfed = (BINAIRE) rep;
			cfcomedit(); 
/* #BG			affmenu(5,tpos[5]-1,10,coconf,oconf,hconf);*/
			affmenu(5,tpos[5]-1,8,coconf,oconf,hconf);
			}
		else if (rep == 1) { 
			coptcfed = (BINAIRE) rep;
			etoufonc(); 
/* #BG			affmenu(5,tpos[5]-1,10,coconf,oconf,hconf);*/
			affmenu(5,tpos[5]-1,8,coconf,oconf,hconf);
			}
		else if (rep >= 20) Xbell(); /* tab n'a pas de sens */
		else {	/* longueur de la tabulation */

			coptcfed = (BINAIRE) rep;
			x_bstart();
			cadre(13,58,15,62); k = lg_tab; pos(14,59);
			Xatb(2); x_putch(' '); x_putch((k + (BINAIRE) '0'));
			x_putch(' ');
			x_bflush();

			while (1) {
				pos(14,60); i = xx_getch();
				if (i == CR) {
					lg_tab = k; 
					boolcfg = FALSE;
					break;
				}
				else if (i == ESCAPE)
					break;
				else if (i == ' ') {
#ifdef buf_cico
			x_bstart();
#endif
					pos(14,60);
					k += 2; if (k == 10) k = 2;
					x_putch((k + (BINAIRE) '0'));
#ifdef buf_cico
			x_bflush();
#endif
				}
				else
					Xbell();
			}
			Xclear(13,58); Batb(0);
/* #BG			affmenu(5,tpos[5]-1,10,coconf,oconf,hconf);*/
			affmenu(5,tpos[5]-1,8,coconf,oconf,hconf);
		}
	}
	Xclear(8,debcol); 
}					/* confedit */

static void cfcomedit ()

/*	configuration des commandes d'edition
 *	met a jour le tableau 'vcomed', et refait eventuellement la
 *	programmation des touches du curseur.
 */
{					/* cfcomedit */
	BINAIRE	i,l,c,code,lv,cv,j,k,m;

#ifdef buf_cico
	x_bstart();
#endif

	pos(5,2);  Xclear(5,2); cadre(5,2,7,80); 

	pos(6,30); Xatb(2); x_cprintf((BYTE FPTR)inte_msg[MSGcomed]);  Xatb(0);

	cadre(8,2,18,80); 

	l = 9; c = 3;

	for (i = 0; i < 18; i++) {
		Xatb(0);
		pos(l,c);

		if (i == coptcmed) { lv = l; cv = c; Xatb(2); }
		x_cprintf((BYTE FPTR)inte_msg[ocfcmed[i]]);

		if (vcomed[i] != 0) {
			x_cprintf((BYTE FPTR)"Ctrl-"); x_putch(vcomed[i]+0x0040);
			if (i == coptcmed) {;
				x_putch(' '); 
				Xatb(0);
				}
			else 	x_putch(' ');
			if (c < 40) x_cprintf((BYTE FPTR)"       ");
			}
		else 	{
			x_cprintf((BYTE FPTR)"      ");
			}
		if (i == 8) {
			l = 9; c = 40;
			}
		else	l++;
		}

#ifdef buf_cico
x_bflush();
#endif

	i = coptcmed; l = lv; c = cv;
	while(1) {
		code = xx_getch();
		if (code == ESCAPE) {
			Xatb(0);
			break;
			}
		if (code == CR) {	/* modif valeur courante */
			/* cfg modifie */
			boolcfg = FALSE;

			if (c == 3) cv = 31; else cv = 78;
			Xatb(3); pos(l,cv);
			if (vcomed[i] != 0)
				x_putch(vcomed[i]+0x0040);
			else	x_putch(' ');

			lv = xx_getch(); lv = toupper(lv);
			atb(0);
			Xatb(0);
			if (!isalpha(lv)) {
				Xbell(); pos(l,cv); Xatb(2);
				if (vcomed[i] != 0)
					x_putch(vcomed[i]+0x0040);
				else
					x_putch(' ');
				Xatb(0);
				}
			else if ((lv == 'E') || (lv == 'X') || (lv == 'D') || (lv == 'W') ||
			         (lv == 'Q') || (lv == 'I') || (lv == 'M')) {
				  pos(23,19); Xatb(2); x_cprintf((BYTE FPTR)inte_msg[MSGreser]);
				  attendre(); pos(l,cv); Xatb(2);
				  if (vcomed[i] != 0)
					x_putch(vcomed[i]+0x0040);
				  else	x_putch(' ');
				  Xatb(0); pos(23,19); Xatb(22);
				}
			else 	{
			     lv -= 0x0040;
			     for (j = 0; j < 18; j++) {
				if ((i != j) && (vcomed[j] == (BYTE) lv)) {
					pos(22,18);x_cprintf((BYTE FPTR)inte_msg[MSGexcom]);
					code = rno; /* par defaut */
					do {
					    code = xx_getch();
				            if (code == ESCAPE) break;
					    code = tolower(code);
					    if ((code != ryes)&&(code != rno))
						Xbell();
					}
					while((code != ryes) && (code != rno));
					pos(22,18); Xatb(21);
					if (code == rno)
						lv = vcomed[i];
					else {
						vcomed[j] = 0; k = j + 9;
						if (j > 8) {
							m = 73; k -= 9;
						}
						else
							m = 25;
						pos(k,m); x_cprintf((BYTE FPTR)"      ");
						x_putch(' ');
					}
				}
			     }
			     Xatb(2);
			     if (vcomed[i] == 0) {
				pos(l,cv-5); x_cprintf((BYTE FPTR)"Ctrl-");

			     }
			     vcomed[i] = (BYTE) lv; Xatb(2);
			     pos(l,cv); x_putch(vcomed[i]+0x0040);
			}
			Xatb(0);
		}
		else {
		  pos(l,c); x_cprintf((BYTE FPTR)inte_msg[ocfcmed[i]]);
		  if (vcomed[i] != 0) {
			x_cprintf((BYTE FPTR)"Ctrl-"); x_putch(vcomed[i]+0x0040);
		  }
		  else
			x_cprintf((BYTE FPTR)"      ");
		  x_putch(' ');
		  if (code == CURD) {
			if (c == 40)	Xbell();
			else {
				c = 40; i += 9;
			}
		  }
		  else if (code == CURG) {
			if (c == 3)	Xbell();
			else {
				c = 3; i -= 9;
			}
		  }
		  else if (code == CURH) {
			if (l == 9)	Xbell();
			else {
				l--; i--;
			}
		  }
		  else if (code == CURB) {
			if (l == 17)	Xbell();
			else {
				l++; i++;
			}
		  }
		  else /* invalide */
			Xbell();
		  pos(l,c); Xatb(2); x_cprintf((BYTE FPTR)inte_msg[ocfcmed[i]]);
		  if (vcomed[i] != 0) {
			x_cprintf((BYTE FPTR)"Ctrl-"); x_putch(vcomed[i]+0x0040);
		  }
		  else
			x_cprintf((BYTE FPTR)"      ");
		  x_putch(' '); Xatb(0);
		}
	}
	coptcmed = i;
	Bpos(5,1); Xclear(5,1);
}					/* cfcomedit */

static void toufonc()
/* 	Programmation des touches de focntion */
{
	BYTE i;
	int d;	
	int rep;

	cadre(5,2,7,11 + LGTFP+ 5 ); pos(6,2 + ( ( 11 + LGTFP + 5) - Xstrlen(inte_msg[MSGfonct] ) ) /2  ); 
	Xatb(2); x_cprintf((BYTE FPTR)inte_msg[MSGfonct]); Xatb(0);
	efface = 1;
	cadre( 8, 11, 19, 11 + LGTFP + 5 ); 
#ifdef buf_cico
	x_bstart();
#endif

	/* Premiere Ligne */
	/* -------------- */
	if (!( cico_is_graphic() )) {
		pos(8,11); 
		x_putch(C_CHG);
		for (i = 1; i < LGTFP + 5 ; i++) {
			x_putch(C_LNH);
			}
		x_putch(C_CHD);
		}			

	for (i=0; i < 10; i++) {
		if (!( cico_is_graphic() )) {
			pos(9+ i, 11);
			x_putch(C_LNV);
			x_putch(' ');
			x_putch(' ');
			}
		else	pos(9+i,13+2);

		aff_zone(pltfp[i], LGTFP);

		if (!( cico_is_graphic() )) {
			x_putch(' ');
			x_putch(' ');
			x_putch(C_LNV);
			}
		}

	/* Derniere Ligne */
	/* -------------- */
	if (!( cico_is_graphic() )) {
		pos(19,11); 
		x_putch(C_CBG);
		for (i = 1; i < LGTFP + 5; i++) {
			x_putch(C_LNH);
			}
		x_putch(C_CBD);
		}		


#ifdef buf_cico
	x_bflush();
#endif
	while (1) {
		if (!( cico_is_graphic() ))
			rep = vmenu(8,2,10,ctfp,vtfp,htfp);
		else	rep = wmenu(8,2,10,ctfp,vtfp,htfp);
		if (rep == -1)	{/* annulation */
			Xclear(5,1);
			break;
			}
		else if (rep < 0 || rep >= 20) {
			/* menu suivant ou precedent : pas de sens ici */
			Xbell(); 
			}
			else {	
				ctfp = (BINAIRE) rep;
				while (1) {
					rep = saisie (9+ctfp,12,LGTFP,LGTFP,pltfp[ctfp]);
					if (rep == -5) {
						Xclear(5,1);
						boolESC = TRUE;
						break;
					}
					if (rep > 0) {
						/* cfg modifie */
						if (rep > 0) boolcfg = FALSE;
						/* reprise de l'option par defaut */
						if (pltfp[ctfp][0] == '?') {
							Xstrcpy( pltfp[ctfp], inte_msg[msg_tfp[ctfp]]);
						}
						else break;
					}
					else break;
				}

				prfo(128+ctfp,(BYTE FPTR) pltfp[ctfp],(BYTE) Xstrlen(pltfp[ctfp]));


				Xatb(0);
				}
		}
	efface = 0;
	Xclear(5,1); /* pour les deux cadres */
}

static void etoufonc()
/* 	Programmation des touches de fonction */
{
	BYTE i;
	int d;	
	int rep;
/*	pos(5,1); Xatb(22);	*/

	cadre(5,2,7,11 + LGTFP+ 5 ); pos(6,2 + ( ( 11 + LGTFP + 5) - Xstrlen(inte_msg[HELP44] ) ) /2  ); 
	Xatb(2); x_cprintf((BYTE FPTR)inte_msg[HELP44]); Xatb(0);
	cadre( 8, 11, 19, 11 + LGTFP + 5 ); 

	efface = 1;

	x_bstart();

	/* Premiere Ligne */
	/* -------------- */
	if (!( cico_is_graphic() )) {
		pos(8,11);  x_putch(C_CHG); for (i = 1; i < LGTFP + 5 ; i++) { x_putch(C_LNH); } x_putch(C_CHD);
		}			
	else 	cadre( 8, 11, 19, 11 + LGTFP + 5 ); 

	for (i=0; i < 10; i++) {

		if (!( cico_is_graphic() )) {
			Bpos(9+ i, 11);
			x_putch(C_LNV);
			x_putch(' ');
			x_putch(' ');
			}
		else	Bpos(9+i,13+2);

		aff_zone(epltfp[i], LGTFP);

		if (!( cico_is_graphic() )) {
			x_putch(' ');
			x_putch(' ');
			x_putch(C_LNV);
			}
		}

	/* Derniere Ligne */
	/* -------------- */
	if (!( cico_is_graphic() )) {
		pos(19,11);  x_putch(C_CBG); for (i = 1; i < LGTFP + 5; i++) { 	x_putch(C_LNH); } x_putch(C_CBD); 
		}

	x_bflush();
	while (1) {

		if (!( cico_is_graphic() ))
			rep = vmenu(8,2,10,ectfp,vtfp,htfp);
		else	rep = wmenu(8,2,10,ectfp,vtfp,htfp);
		
		if (rep == -1)	{
			/* annulation */
			Xclear(5,1); 
			break;
			}
		else if (rep < 0 || rep >= 20) {
			/* menu suivant ou precedent : pas de sens ici */
			Xbell(); 
			}
			else {	
				ectfp = (BINAIRE) rep;
				rep = saisie(9+ectfp,12,LGTFP,LGTFP,epltfp[ectfp]);
				if (rep == -5) {
					boolESC = TRUE;
					Xclear(5,1); 
					break;
				}
	
				/* cfg modifie */
				if (rep > 0) boolcfg = FALSE;
	
				Xatb(0);
			}

		/* Xclear(5,1); */
		}
	Xclear(5,1); 
	
}

static int run(prog,param)

/*	execution d'un utilitaire externe
 */
BYTE XPTR prog; 
BYTE XPTR param;
{						/* run */
	int	ret;
	char 	buf[LGCOM];
	char	drep[LGREP], frep[LGMXNOM];
	char	locext[1];
	BYTE XPTR	p;
	int i;

	pos(5,1);       /* positionne le curseur */

	if (!ecrconf(cfgtmp)) {
		msg_erreur(CFGTM);

		return(2);
	}

#if unix || vms
	if (flag_modterm == TRUE) {
		modterm(0);	
	}
#endif
	
	finscreen();	/* remettre le terminal en etat "standard" */

	/* Construit un nom avec chemin d'acces par defaut si non specifie
	 * et chemin d'acces specifie sinon; ne detruit pas l'extension
	 * si elle est specifiee; le chemin par defaut peut etre vide */


	/* Eclate le nom de fichier ainsi constitue en chemin d'acces
	  d'une part et nom d'utilitaire d'autre part */

	Xfn_parser((BYTE FPTR) prog,(BYTE FPTR) frep,8+16);
	Xfn_parser((BYTE FPTR) prog,(BYTE FPTR) drep,1+2+4);
	if (drep[0] == 0) { /* proposer le repertoire par defaut */
		MakeReper(REPB, drep);
	}		

	Xstrcpy(buf, drep);
	Xstrcat(buf,frep);
#ifndef small
	/* tronquer la ligne d'argument */

	if (Xstrlen(buf) + Xstrlen(param) + 1 >= LGCOM) {
		param[LGCOM] = EOSTR;
	}

	Xstrcat(buf," ");
	Xstrcat(buf,param);

#ifdef msdos
	ret = Xsystemdos((BYTE FPTR) buf, 1);
	if (ret == 40)	ret = MOINS_UN;
#else
	ret = Xsysteme((BYTE FPTR) buf);
#endif
#else
	ret = LoadGo(drep,frep,param); 
#endif

	initscreen();		/* re-init du terminal */

#if unix || vms
	if (flag_modterm == TRUE) {
		modterm(1);
	}
#endif

#ifdef vms
	if (ret == 0 && boolexa) ret = 1;	/* impair -> pas d'erreur */
#endif
	if (ret != VAL_RET) {

#ifdef prologue
		if (Xsystemr()) ret = MOINS_UN;
#endif
#ifdef unix
		if (errno == ENOENT) ret = MOINS_UN;
#endif
		if (ret == MOINS_UN) {
			ret = 2;
			msg_erreur(NOTFIND);
		}
		else	{
			ret = 2;
			msg_erreur(WARNI);
		}
	}

#ifdef prologue
	/* reprise en compte des options du cfg par defaut */
	/* en particulier les touches de fonction */
	/* if (!lectfp(nomcfg)) return(MOINS_UN); */
	if (!lectfp(cfgtmp)) return(MOINS_UN); 
#endif

	return(ret);
}						/* RUN */

Xclear(y,x)
int y,x;
{
	if ( cico_is_graphic() ) {
		textual_backwash(y);
		}
	else	{
		pos(y,x); 
		Xatb(22);
		}
}
Bpos(y,x)
int y,x;
{
		pos(y,x);
}

Batb(x)
int x;
{
		Xatb(x);
}

Xbell()
{
	if (! boolESC) x_bell();
}


	/*	Fonctions d'ouverture des fichiers	*/
	/*	----------------------------------	*/

FILE *XAfopen(nomfic,typ)

/*	Ouverture d'un fichier par 'fopen', en demandant son exclusivite
 *	pour une exploitation 'multi-utilisateurs' sans suppression
 *	sauf si ouverture en mode lecture seule sous Amenesik / Sologic.
 */
BYTE *nomfic;
BYTE *typ;
{					/* XAfopen */
	FILE	*fh;

#ifdef	unix
	int resac;

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
	else {
		resac = Xaccess(nomfic,1);
		if (resac != 0) {
			if (errno != ENOENT)
				/* fichier existant mais deja locke */
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
			else
				return(fh);
		}
	}
#endif

	fh = fopen(nomfic,typ);

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

static void makenom(pt, inc)
BYTE XPTR pt;
BYTE inc;
{
	FILE *fh;
	FILE *err;

	BYTE buf[4];	/* conversion du num. poste en chaine */
	BINAIRE numposte;

pt[0] = 'a';
while(1) {
#ifdef msdos
#ifndef BORLAND

	get_time(&_time);
	get_date(&_date);

	b32.hh = (BYTE) _time.hour & 0x001f;
	b32.ss = (BYTE) (_time.second >> 1) & 0x001f;
	b32.mm = (BYTE) _time.minute & 0x001f;
	b32.MM = (BYTE) (_date.month << 1) & 0x001f | (_time.minute >> 5) & 1;
	
	b32.DD = (BYTE) _date.day;
	b32.AA = (BYTE) (_date.year - 1970) & 0x001f;

#else 	/* BORLAND */
	get_date(&_date);
	get_time(&_time);

	b32.hh = (BYTE) _time.ti_hour & 0x001f;
	b32.ss = (BYTE) (_time.ti_sec >> 1) & 0x001f;
	b32.mm = (BYTE) _time.ti_min & 0x001f;
	b32.MM = (BYTE) (_date.da_mon << 1) & 0x001f | (_time.ti_min >> 5) & 1;
	
	b32.DD = (BYTE) _date.da_day;
	b32.AA = (BYTE) (_date.da_year - 1980) & 0x001f;

#endif
#else
	/* prologue */
	time(&gettime);
	pt_time = localtime(&gettime);

	b32.hh = (BYTE) pt_time->tm_hour & 0x001f;
	b32.ss = (BYTE) (pt_time->tm_sec >> 1) & 0x001f;
	b32.mm = (BYTE) pt_time->tm_min & 0x001f;
	b32.MM = (BYTE) (pt_time->tm_mon << 1) & 0x001f | (pt_time->tm_min >> 5) & 1;
	
	b32.DD = (BYTE) pt_time->tm_mday;
	b32.AA = (BYTE) (pt_time->tm_year - 1970) & 0x001f;
#endif


	/* on garde la premiere lettre du nom du fichier source */
	pt[1] = conv_base (b32.AA);
	pt[2] = conv_base (b32.DD);
	pt[3] = conv_base (b32.MM);
	pt[4] = conv_base (b32.mm);
	pt[5] = conv_base (b32.ss);
	pt[6] = conv_base (b32.hh);
	pt[7] = conv_base (inc);

	Xstrcat(pt,".tmp");
#ifdef old
#ifndef unix
	pt[8] = '.';	/* separateur */
	pt[9] = EOSTR;
#else
	pt[8] = EOSTR;	/* separateur */
	pt[9] = EOSTR;
#endif
#endif
#ifdef Msdos
/*	numposte = x_npos(); */
	numposte = 1;
	Xstrcat(pt, (char *) itoa(numposte, buf, 10));
#endif

	fh = Xfopen(pt,"r");
	if (fh == GenericNULL(FILE)) {
		/* je reserve le nom dans le catalogue */
		fh = Xfopen(pt,"w");
		if (fh != GenericNULL(FILE)) {
			Xfclose(fh);
#ifdef unix
			liberlox(pt);
#endif
			return;
		}
	
		return;
	}
	else {
		Xfclose(fh);
#ifdef unix
		liberlox(pt);
#endif
	}
	inc++;
	if (inc > 10) return;
}
#ifdef test
	Xstrcpy(pt, "abal");
	numposte = x_npos();
	conv_poste( (BYTE XPTR) &pt[Xstrlen(pt)], (BINAIRE) numposte );
	Xstrcat(pt,".cfg");	
#endif
}

static void conv_poste(chaine, val)
BYTE XPTR chaine;
BINAIRE   val;
{
	BYTE 	*p,*q,c,valeur[6],valcad[6];
	BINAIRE n;

	p = q = chaine; n = val;
	do {
		*p++ = inttocar(n % 10);
	}
	while ((n /= 10) != 0);
	*p = EOSTR;

/*
	while (q < --p) {
		c = *q; *q++ = *p; *p = c;
	}
	Xstrcpy(&valcad[0],"     ");
	Xstrcpy(&valcad[5-Xstrlen(&valeur[0])],&valeur[0]);
	Xstrcat( chaine, valcad);
*/

}

static char conv_base (c)
BYTE c;
{
	if (c < 10)
		return((char) '0' + c);
	else  	return((char) 'A' + c - 10);
}

static int ask(l, c, lgaff, lgbuf, buf)
BINAIRE l;
BINAIRE c;
BINAIRE lgaff;
BINAIRE lgbuf;
BYTE XPTR buf;
{
#ifdef buf_cico
	x_bstart();
#endif
	cadre( l-1, c-1, l + 1, c + 2 + lgaff + 2 );
#ifdef buf_cico
	x_bflush();
#endif
	return( saisie( l , c, lgaff, lgbuf, buf ) );

}

static void create_prj()
{

	FILE	*fc;
	BYTE XPTR   p;
	int	i;
	int err;
	BYTE buf[50];
	BYTE nom_tmp[LGREP];
	BYTE rep_def[LGREP];
	BYTE tmp[LGREP];
	BYTE exttmp[LGREP];
	BYTE ModArgu[LGARGU];
	int nb_include;
	int num_module;

	/* Creation du fichier de configuration */
#ifdef new
	rep_def[0] = EOSTR;
	Xfn_parser((BYTE FPTR) nomfic, (BYTE FPTR) rep_def, 2+4);
	if (REPS[0]) {
		Xstrcpy( rep_def, REPS );
	}
	else {
		Xfn_parser((BYTE FPTR) nomfic, (BYTE FPTR) rep_def, 2+4);
	}
#else
	Xstrcpy( rep_def, REPS);
#endif
	MakeNom(rep_def,nomprj,EXTPRJ,nomtmp);

	fc = Xfopen(nomtmp,"w");
	if (fc == GenericNULL(FILE)) {
		/* gestion d'erreur */

		return;
	}

	errno = 0;

	/* Ecriture signature (no version) */
	fprintf(fc,"\n# %s \n", inte_msg[MAKE01]);

	/* repertoires par defaut */
	/* ATTENTION A L'ECRITURE DE CHAINES VIDES  REPERTOIRES ET EXTENSIONS */

	fprintf( fc, "OBJ = .o\n");

/* #BG	if (vtropt[0] && vacti[9] ) 
		fprintf( fc, "EXE = .apl\n");
	else */
		fprintf( fc, "EXE = .at\n");

	MakeReper(REPM, tmp);			/* Repertoire des modules */
	if (tmp[0] == EOSTR)
		fprintf(fc,"POBJ = %s \n", rep_def);
	else
		fprintf(fc,"POBJ = %s\n",tmp);

	MakeReper(REPT, tmp );			/* Repertoire des traduits */
	if (tmp[0] == EOSTR)
		fprintf(fc,"PBIN = %s \n", rep_def);
	else
		fprintf(fc,"PBIN = %s\n",tmp);

	MakeReper(REPB, tmp);			/* Repertoire des binaires */
	if (tmp[0] == EOSTR)
		fprintf(fc,"RABAL = \n");
	else
		fprintf(fc,"RABAL = %s\n",tmp);
	
	/* Definition des executables */

/* #BG	fprintf(fc,"APLUS = $(RABAL)aplus \n",tmp);*/

	fprintf(fc,"ATR = $(RABAL)%s \n",AbalToolAtr);

	fprintf(fc,"ALD = $(RABAL)%s \n",AbalToolAld);

/* #BG	fprintf(fc,"AO = $(RABAL)ao \n",tmp);*/

	fprintf(fc,"GMAKE = $(RABAL)%s \n",AbalToolGenmake);

	fprintf(fc,"\n# %s \n", inte_msg[MAKE02]);

	/* creation des options des utilitires */

	/* aplus */
/* #BG
	tmp[0] = EOSTR;

	get_aplus_opt( tmp );

	fprintf(fc, "APLUSOPT = %s\n",tmp);
*/
	/* atr   */
	tmp[0] = EOSTR;
	get_atr_opt( tmp );
	fprintf(fc, "ATROPT = %s\n",tmp);

	/* ao    */
/* #BG
	tmp[0] = EOSTR;
	exttmp[0] = EOSTR;

	if (voptao[1]) Xstrcat(tmp,"o");

	if (voptao[2]) Xstrcat(tmp,"2");
	else if (voptao[3]) Xstrcat(tmp,"3");

	if ( tmp[0] ) {
		Xstrcpy( exttmp, DELIMOPT);
		Xstrcat( exttmp, tmp );
	}

	if (voptao[0]) {
		Xstrcat(exttmp, " ");
		Xstrcat(exttmp, DELIMOPT );
		Xstrcat(exttmp, "w ");
	}

	fprintf(fc,"AOOPT = %s\n",exttmp );	
*/

	/***************************************/

	MakeReper(rep_def, tmp );			/* Repertoire des sources */
	if (tmp[0] == EOSTR) {
		/* pour faire plaisir a Dominique L. */
		Xfn_parser((BYTE FPTR) nomfic, (BYTE FPTR) tmp, 2+4);
		fprintf(fc,"SP01 = %s\n", tmp);
	}
	else {
		fprintf(fc,"SP01 = %s\n",tmp);
	}
	p = REPI;			/* Repertoire des includes */
	nb_include = 2;
	while( NextOpt(&p,tmp) ) {
		itoh(buf, nb_include);
		if (tmp[0] == EOSTR)
			fprintf(fc,"SP%s = \n", buf);
		else {
			MakeReper(tmp, exttmp);
			fprintf(fc,"SP%s = %s\n", buf, exttmp);
		}
	}

	fprintf(fc," \n");

	/* Genmake Opt */
	if (REPI[0] != EOSTR )
		fprintf(fc, "GMOPT = -i$(SP02) \n");
	else
		fprintf(fc, "GMOPT = \n");

	num_module = 0;

	/* Designation du fichier courant */

	p = nomfic;
	NextOpt(&p, tmp);

	Xfn_parser((BYTE FPTR) nomfic, (BYTE FPTR) tmp, 8);

	itoh(buf, num_module);
	fprintf(fc,"MOD%s = %s\n", buf , tmp);

	num_module ++;

	/* designation des modules */

	Xstrcpy(ModArgu, lstmod);
	p = &ModArgu[0];
	while (LibNextOpt(&p,tmp)) {
		Xfn_parser((BYTE FPTR) tmp, (BYTE FPTR) exttmp, 16 );
		if ( Xstrcmp(exttmp, ".o") && Xstrcmp(exttmp,".O")  ) {
			/* ce n'est pas un module explicite */
			/* donc dependance sur le source */
			
			/* fichier de link -f */
			if ( Xstrcmp(exttmp, ".lk") && Xstrcmp(exttmp,".LK")  ) {
				/* ce n'est pas non plus un fichier link */

				Xfn_parser((BYTE FPTR) tmp, (BYTE FPTR) exttmp, 8);
	
				itoh( buf, num_module );
				fprintf(fc,"MOD%s = %s\n", buf, exttmp);
				num_module ++;		

			}
			else {
				/* la suite des dependances se trouve dans le fichier .lk */
				Xfn_parser( (BYTE FPTR) tmp, (BYTE FPTR) exttmp, 2+4);
				if (exttmp[0] == EOSTR) {
					/* Le fichier link se trouve dans le
					repertoire module */

					if (REPM[0] == EOSTR) 	
						MakeReper(rep_def, exttmp);
					else	MakeReper(REPM,exttmp);

					Xstrcat( exttmp, tmp );
					if ( LibInitArg(exttmp, ModArgu) ) 
						p = &ModArgu[0];
				}
				else if ( LibInitArg(tmp, ModArgu) ) 
					p = &ModArgu[0];
			}
		}
	}

	fprintf(fc,"\n# %s \n", inte_msg[MAKE03]);
	
	/* creation des dependances par defaut */
#ifdef prologue
	fprintf(fc,"\n.%s.gm,-%s.gm:\n",&EXTS[1],&EXTS[1]);
#else
	fprintf(fc,"\n.%s.gm:\n",&EXTS[1]);	
#endif

/* #BG	if (vtropt[0] ) {
			fprintf(fc,"\t$(GMAKE) $(GMOPT) -b -x -m$@ $* \n");
	}
	else {	/* source traduit */
		if (lstmod[0] != EOSTR )
			fprintf(fc,"\t$(GMAKE) $(GMOPT) -bo -x -m$@ $* \n");
		else	fprintf(fc,"\t$(GMAKE) $(GMOPT) -b -x -m$@ $* \n");
/* #BG	}*/

/* #BG
	if (vtropt[0]) {
		if (vacti[9]) {
			// generation d'un APL
#ifdef prologue
			fprintf(fc,"\n.%s.apl,-%s.apl:\n",&EXTS[1],&EXTS[1]);
#else
			fprintf(fc,"\n.%s.apl:\n",&EXTS[1]);	
#endif
			if ( vacti[4] ) 
				fprintf(fc,"\t$(APLUS) $(APLUSOPT) -e$(*R)%s -d$@ $* \n", EXTE);
			else	fprintf(fc,"\t$(APLUS) $(APLUSOPT) -d$@ $* \n");
		}
		else {
			// Je force les deux etapes
			// APLUS puis ATR avec APS
#ifdef prologue
			fprintf(fc,"\n.%s.at,-%s.at:\n",&EXTS[1],&EXTS[1]);
#else
			fprintf(fc,"\n.%s.at:\n",&EXTS[1]);	
#endif

			if ( vacti[4] ) 
				fprintf(fc,"\t$(APLUS) $(APLUSOPT) -c -e$(*R)%s -d$(*R).aps $* \n", EXTE);
			else	fprintf(fc,"\t$(APLUS) $(APLUSOPT) -c -d$(*R).aps $* \n");

			if ( vtropt[4] ) // Erreur
				if ( vtropt[2] ) // Erreur + fichier liste
					fprintf(fc,"\t$(ATR) $(ATROPT) -e$(*R)%s -l$(*R)%s -d$@ $(*R).aps \n", EXTE, EXTL);
				else	fprintf(fc,"\t$(ATR) $(ATROPT) -e$(*R)%s -d$@ $(*R).aps \n", EXTE);
			
				// Pas d'erreur , pas de liste
			else	fprintf(fc,"\t$(ATR) $(ATROPT) -d$@ $(*R).aps \n");
		}
	}
	else {
*/
		/* Source ABAL */
#ifdef prologue
		fprintf(fc,"\n.%s.at,-%s.at:\n",&EXTS[1],&EXTS[1]);
#else
		fprintf(fc,"\n.%s.at:\n",&EXTS[1]);	
#endif
/* #BG		if ( vtropt[4] ) /* Erreur */
		if ( vtropt[3] ) /* Erreur */
/* #BG			if ( vtropt[2] ) /* Erreur + fichier liste */
			if ( vtropt[1] ) /* Erreur + fichier liste */
				fprintf(fc,"\t$(ATR) $(ATROPT) -e$(*R)%s -l$(*R)%s -d$@ $* \n", EXTE, EXTL);
			else	fprintf(fc,"\t$(ATR) $(ATROPT) -e$(*R)%s -d$@ $* \n", EXTE);
		
			/* Pas d'erreur , pas de liste */
		else	fprintf(fc,"\t$(ATR) $(ATROPT) -d$@ $* \n");
/* #BG	}*/
/* #BG
	if (vtropt[10]) {
		fprintf(fc,"\t$(AO) $(AOOPT) $@ \n");
	}
*/
#ifdef prologue
	fprintf(fc,"\n.%s.o,-%s.o: \n",&EXTS[1],&EXTS[1]);
#else
	fprintf(fc,"\n.%s.o: \n",&EXTS[1]);	
#endif

/* #BG
	if (vtropt[0]) {
		if ( vacti[4] )
			fprintf(fc,"\t$(APLUS) $(APLUSOPT) -e$(*R)%s -d$@ $* \n", EXTE);
		else	fprintf(fc,"\t$(APLUS) $(APLUSOPT) -d$@ $* \n");

		if ( ! vacti[0] ) {
			if ( vtropt[4] ) // Erreur
				if ( vtropt[2] ) // Erreur + fichier liste
					fprintf(fc,"\t$(ATR) $(ATROPT) -e$(*R)%s -l$(*R)%s -d$@ $(*R).aps \n", EXTE, EXTL);
				else	fprintf(fc,"\t$(ATR) $(ATROPT) -e$(*R)%s -d$@ $(*R).aps \n", EXTE);
		
				// Pas d'erreur , pas de liste
			else	fprintf(fc,"\t$(ATR) $(ATROPT) -d$@ $(*R).aps \n");
		}
	}
	else 	{ */
/* #BG		if ( vtropt[4] ) /* Erreur */
		if ( vtropt[3] ) /* Erreur */
/* #BG			if ( vtropt[2] ) /* Erreur + fichier liste */
			if ( vtropt[1] ) /* Erreur + fichier liste */
				fprintf(fc,"\t$(ATR) $(ATROPT) -e$(*R)%s -l$(*R)%s -d$@ $* \n", EXTE, EXTL);
			else	fprintf(fc,"\t$(ATR) $(ATROPT) -e$(*R)%s -d$@ $* \n", EXTE);
		
			/* Pas d'erreur , pas de liste */
		else	fprintf(fc,"\t$(ATR) $(ATROPT) -d$@ $* \n");
/* #BG	}*/

#ifdef prologue
	fprintf(fc,"\n.o.at,-o.at: \n");
#else
	fprintf(fc,"\n.o.at: \n");	
#endif

	fprintf(fc,"\t$(ALD) -r$(POBJ) -d$(PBIN) ");
	/* fichier + modules declare dans lstmod */
	
	fprintf(fc,"$(MOD00) " );

	p = &lstmod[0];
	while( NextOpt(&p,tmp) ) {
		fprintf(fc,"%s ", tmp);
	}

	fprintf(fc,"\n");
/* #BG
	if (vtropt[10]) {
		fprintf(fc,"\t$(AO) $(AOOPT) $@\n");
	}
*/
	/* prise en compte des macros */

	fprintf(fc,"\n!MAKE \n");

	/* dependances explicites */
	
	fprintf(fc,"\n# %s \n", inte_msg[MAKE04]);

	/* mf */

	num_module = 0;

	MakeNom(rep_def,nomfic, EXTS, tmp);

	itoh(buf, num_module++);
	fprintf(fc,"\n$(SP01)$(MOD%s).gm: %s\n", buf, tmp );


	/* pour chaque module */	
	Xstrcpy(ModArgu, lstmod);
	p = &ModArgu[0];
	while (LibNextOpt(&p,tmp)) {
		Xfn_parser((BYTE FPTR) tmp, (BYTE FPTR) exttmp, 16);
		if ( Xstrcmp(exttmp, ".o") && Xstrcmp(exttmp,".O")  ) {
			/* ce n'est pas un module explicite */
			/* donc dependance sur le source */
			
			/* fichier de link -f */

			if ( Xstrcmp(exttmp, ".lk") && Xstrcmp(exttmp,".LK")  ) {
				MakeNom( rep_def, tmp, EXTS, exttmp);

				itoh(buf, num_module);
				fprintf(fc,"$(SP01)$(MOD%s).gm: %s \n", buf, exttmp ); 

				num_module ++;		
			}
			else {
				/* la suite des dependances se trouve dans le fichier .lk */
				Xfn_parser( (BYTE FPTR) tmp, (BYTE FPTR) exttmp, 2+4);
				if (exttmp[0] == EOSTR) {
					/* Le fichier link se trouve dans le
					repertoire module */

					MakeReper(REPM,exttmp);
					Xstrcat( exttmp, tmp );
					if ( LibInitArg(exttmp, ModArgu) ) 
						p = &ModArgu[0];
				}
				else if ( LibInitArg(tmp, ModArgu) ) 
					p = &ModArgu[0];
#ifdef old
				/* la suite des dependances se trouve dans le fichier .lk */
				if ( LibInitArg(tmp, ModArgu) )
					p = &ModArgu[0];
#endif
			}
		}
	}

	fprintf(fc,"\n!MAKE \n");


	for (i=0; i < num_module; i++) {

		itoh(buf, i);
		fprintf(fc,"!INCLUDE $(SP01)$(MOD%s).gm \n", buf);

	}

	
	fprintf(fc,"!MAKE \n");

	/* dependances sur les traduits */
	if ( lstmod[0] != EOSTR ) {
		/* utilisation de module */

		num_module = 0;

		itoh(buf, num_module ++ );
	
		fprintf(fc,"\n$(PBIN)$(MOD%s)$(EXE): $(POBJ)$(MOD%s)$(OBJ) %c \n", buf, buf,0x27 );

		/* pour chaque module */	
		Xstrcpy(ModArgu, lstmod);
		p = &ModArgu[0];
		while (LibNextOpt(&p,tmp)) {
			Xfn_parser((BYTE FPTR) tmp, (BYTE FPTR) exttmp, 16);
			if ( Xstrcmp(exttmp, ".o") && Xstrcmp(exttmp,".O")) {
				/* ce n'est pas un module explicite */
				/* donc dependance sur le source */
			
				/* fichier de link */
				if ( Xstrcmp( exttmp,".lk") && Xstrcmp( exttmp, ".LK") ) {
					itoh(buf, num_module );
					fprintf(fc,"   $(POBJ)$(MOD%s)$(OBJ) %c \n", buf ,0x27 ); 
					num_module ++;		
				}
				else  {
/*					fprintf(fc,"  %s %c \n", tmp,0x27 ); */
					/* la suite des dependances se trouve dans le fichier .lk */
					/* la suite des dependances se trouve dans le fichier .lk */

					Xfn_parser( (BYTE FPTR) tmp, (BYTE FPTR) exttmp, 2+4);
					if (exttmp[0] == EOSTR) {
					/* Le fichier link se trouve dans le
					repertoire module */

						MakeReper(REPM,exttmp);
						Xstrcat( exttmp, tmp );
						if ( LibInitArg(exttmp, ModArgu) ) 
							p = &ModArgu[0];
					}
					else if ( LibInitArg(tmp, ModArgu) ) 
						p = &ModArgu[0];
#ifdef old
					if ( LibInitArg(tmp, ModArgu) )
						p = &ModArgu[0];
#endif
				}
			}
			else {
				MakeNom(REPM, tmp, ".o", exttmp);
				fprintf(fc,"   %s %c \n", exttmp,0x27 ); 
			}
		}
	}


	fprintf(fc,"\n# %s \n", inte_msg[MAKE05]);
	
	/* dependance module */

	/* dependance  traduit */

	/* fermeture du fichier makefile cree */
	Xfputc(VEOF,fc);

	Xfclose(fc);

#ifdef unix
	liberlox(nomtmp);
#endif
}

void	itoh( bptr, wv )
BYTE XPTR bptr;
BINAIRE   wv;
{
/*
	if ((wv & 0xF000) > 0x9000)
		*(bptr++) = ((((wv & 0xF000) >> 12) - 10) + 'A');
	else	*(bptr++) = (((wv & 0xF000) >> 12) + '0');
	if ((wv & 0x0F00) > 0x0900)
		*(bptr++) = ((((wv & 0x0F00) >> 8) - 10) + 'A');
	else	*(bptr++) = (((wv & 0x0F00) >>  8) + '0');
*/

	if ((wv & 0x00F0) > 0x0090)
		*(bptr++) = ((((wv & 0x00F0) >> 4) - 10) + 'A');
	else	*(bptr++) = (((wv & 0x00F0) >>  4) + '0');
	if ((wv & 0x000F) > 0x0009)
		*(bptr++) = (((wv & 0x000F) - 10) + 'A');
	else	*(bptr++) = ((wv & 0x000F) + '0');
	*(bptr++) = 0;
	return;
}

static void get_atr_opt( param )
BYTE XPTR param;
{
	BYTE tmp[LGARGU];
	BYTE XPTR pt;

	tmp[0] = EOSTR;

/* #BG Options 0 et 10 supprimées (Preprocesseur et optimiseur).
	if (vtropt[6]) Xstrcat(tmp,"g");
	if (vtropt[1]) Xstrcat(tmp,"m");
	if (vtropt[3]) Xstrcat(tmp,"x");
	if (vtropt[5]) Xstrcat(tmp,"w");
	if (vtropt[6]) Xstrcat(tmp,"o");
	if (vtropt[7]) Xstrcat(tmp,"a");
	if (vtropt[8]) Xstrcat(tmp,"b");
*/
	if (vtropt[5]) Xstrcat(tmp,"g");
	if (vtropt[0]) Xstrcat(tmp,"m");
	if (vtropt[2]) Xstrcat(tmp,"x");
	if (vtropt[4]) Xstrcat(tmp,"w");
	if (vtropt[5]) Xstrcat(tmp,"o");
	if (vtropt[6]) Xstrcat(tmp,"a");
	if (vtropt[7]) Xstrcat(tmp,"b");


	if ( tmp[0] ) {
		Xstrcat( param, DELIMOPT);
		Xstrcat( param, tmp);

	}
#ifdef old
/* #BG	if (vtropt[4]) {*/
	if (vtropt[3]) {
		Xstrcat(param," ");
		Xstrcat(param,DELIMOPT);
		Xstrcat(param,"e");
		Xstrcat(param,"$(*R)");
		Xstrcat(param,&EXTE[0] );
		MakeReper(&REPS[0], &param[Xstrlen(param)]);

		Xfn_parser((BYTE FPTR) nomfic,(BYTE FPTR) &param[Xstrlen(param)],8);
		Xstrcat(param,&EXTE[0]);

#ifdef prologue
		Xfn_parser((BYTE FPTR) nomfic,(BYTE FPTR) &param[Xstrlen(param)],32);
#endif

		Xstrcat(param," ");
	}

/* #BG	if (vtropt[2]) {*/
	if (vtropt[1]) {
		Xstrcat(param," ");
		Xstrcat(param,DELIMOPT);
		Xstrcat(param,"l");
		
		MakeReper(&rep_def[0], &param[Xstrlen(param)]);

		Xfn_parser((BYTE FPTR) nomfic,(BYTE FPTR) &param[Xstrlen(param)],8);
		Xstrcat(param,&EXTL[0]);
#ifdef prologue
		Xfn_parser((BYTE FPTR) nomfic,(BYTE FPTR) &param[Xstrlen(param)],32);
#endif


		Xstrcat(param," ");
	}
#endif

	/* extention du fichier */
	Xstrcat(param,DELIMOPT);
	Xstrcat(param,"s");
/* #BG
	if (vtropt[0])	Xstrcat(param,"aps"); // source pre-processe
	else */		Xstrcat(param,&EXTS[1]);
	
	/* repertoire des includes */

	pt = &REPI[0];		
	NextOpt(&pt,&tmp[0]);

	/* liste des includes */
	while (tmp[0]) {
		Xstrcat(param,DELIMOPT);
		Xstrcat(param,"i");
		MakeReper(tmp, &param[Xstrlen(param)]);
		NextOpt(&pt,&tmp[0]);
	}

	pt = &lstdef[0];		
	NextOpt(&pt,&tmp[0]);
/* #BG	if (tmp[0] != EOSTR && ! vtropt[0] )  {*/
	if (tmp[0] != EOSTR)  {
		/* liste des defines */
		while (1) {
			Xstrcat(param,DELIMOPT);
			Xstrcat(param,"n");
			Xstrcat(param,tmp);
			Xstrcat(param," ");
			NextOpt(&pt,&tmp[0]);
			if (tmp[0] == EOSTR) break;
		}
	}

	Xstrcat(param," ");
}

/* #BG */
#ifdef OBJET
static void get_aplus_opt( param )
BYTE XPTR param;
{
	BYTE tmp[LGREP];
	BYTE XPTR pt;

	tmp[0] = EOSTR;

	if (!vacti[0]) Xstrcat(tmp,"c");
	if (!vacti[1]) Xstrcat(tmp,"q");
	if (vacti[2]) Xstrcat(tmp,"g");
	if (vacti[3]) Xstrcat(tmp,"w");
#ifdef old
	if (vacti[4]) Xstrcat(tmp,"e");
	if (vacti[5]) Xstrcat(tmp,"x");
#endif

	if (vacti[6]) Xstrcat(tmp,"y");
/* #BG
	if (vtropt[1]) Xstrcat(tmp,"m");
	if (vtropt[2]) Xstrcat(tmp,"l");
*/
	if (vtropt[0]) Xstrcat(tmp,"m");
	if (vtropt[1]) Xstrcat(tmp,"l");

	if ( tmp[0] ) {
		Xstrcat( param, DELIMOPT );
		Xstrcat( param, tmp);
	}
	if (vacti[9]) {
		Xstrcat( param, DELIMOPT );
		Xstrcat( param,"p ");
	}

	/* nom device */
	if (swapunit[0] != EOSTR) {
		Xstrcat(param,DELIMOPT);
		Xstrcat(param,"u");
		Xstrcat(param, swapunit);
	}

	/* repertoire des includes */
	pt = &REPI[0];		
	NextOpt(&pt,&tmp[0]);

	/* liste des includes */
	while (tmp[0]) {
		Xstrcat(param,DELIMOPT);
		Xstrcat(param,"i");
		MakeReper(tmp, &param[Xstrlen(param)]);
		NextOpt(&pt,&tmp[0]);
	}

	/* define */

	pt = &lstdef[0];		
	NextOpt(&pt,&tmp[0]);
	if (tmp[0] != EOSTR) {
		/* liste des defines */
		while (1) {
			Xstrcat(param,DELIMOPT);
			Xstrcat(param,"n");
			Xstrcat(param,tmp);
			Xstrcat(param," ");
			NextOpt(&pt,&tmp[0]);
			if (tmp[0] == EOSTR) break;
		}
	}

	/* extension par defaut */
	if ( EXTS[1] ) {
		Xstrcat( param, DELIMOPT );
		Xstrcat( param, "s");
		Xstrcat( param, &EXTS[1]);
	}

	Xstrcat(param," ");

	/* repertoire des binaires atr , aed */
}
#endif /* #BG */

static BINAIRE max_largeur( opt , nb )
BINAIRE opt[];
BINAIRE	nb;
{
	BINAIRE lg;
	BINAIRE len;
	BINAIRE i;

	lg = 0;
	for (i=0; i < nb; i++) {
		len = Xstrlen( inte_msg[opt[i]] );
		if ( len > lg )  lg = len;
	}
	return ( lg );
}

static void Xset_filler(on)
BOOL on;
{
#if msdos || prologue
	if ( conf(14) ) {
		if ( on == TRUE ) {
			x_set_filler(valeur_in);
		}
		else	
			x_set_filler(valeur_out);
	}
	pos(5,1);
	Xatb(22);
#endif

}

