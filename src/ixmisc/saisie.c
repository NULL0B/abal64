#define XPTR * 
#if unix || vms
#define FPTR *
#else
#define FPTR far *
#endif

#ifndef prologue
#define buf_cico
#endif

#include "def.h"
#ifdef AIX_VERS
#ifdef AVIION
#define LINT_ARGS
#endif
#endif /* AIX_VERS */

#define LGMXNOM 320
#define EOSTR 0
#define TRUE 1
#define FALSE 0
#define CR '\r'
#define ESCAPE 	0x1b
#define CURD   	0x04
#define CURG	0x11
#define CURH  	0x05
#define CURB  	0x18
#define DELBACK 0x08
#define DELCAR  0x07
#define INSERT  0x0f
#define CTRLW   0x17
#define PDEBFIN 0x02
#define TABUL   0x09
#define T7F	0x7f
#define CTRLA   0x01
#define CTRLC   0x06	/* CTRLF */
#define CTRLP   0x10
#define CTRLJ   0x0a
#define HOME    0x1c



#ifdef souris

#define MOUSE   0xf0
extern int env_mouse;
extern BINAIRE mouse_col;
extern BINAIRE mouse_lin;
extern BINAIRE mouse_bouton;
BINAIRE s;

extern BINAIRE PositSouris(BINAIRE, BINAIRE);
extern SWORD mouse_getch();

#endif

/* Fonctions generiques */
#ifdef LINT_ARGS
extern VOID    pos(BINAIRE , BINAIRE);
extern VOID    Xatb(BINAIRE);
extern VOID    atb(BINAIRE);
extern VOID    x_bell(VOID);
extern BINAIRE x_getch(VOID);
extern VOID    x_cprintf(BYTE FPTR);
extern VOID    x_bstart(VOID);
extern VOID    x_bflush(VOID);
extern VOID    x_putch(BYTE);
#else
extern VOID    pos();
extern VOID    atb();
extern VOID    Xatb();
extern VOID    x_bell();
extern BINAIRE x_getch();
extern VOID    x_cprintf();
extern VOID    x_bstart();
extern VOID    x_bflush();
extern VOID    x_putch();
#endif

/* Declarations Privees */
 BYTE trav[LGMXNOM];
 BINAIRE nb_deb_gauche, nb_deb_droite;
 BINAIRE indice_actuel;
 BINAIRE taille_actuelle;
 BOOL bool_ins;
 BOOL first_car;
 BOOL bool_ctrlp;


/* Variables generiques a instancier au debut de la fonction */
 BINAIRE pos_lig;
 BINAIRE pos_col;
 BINAIRE lg_visu;
 BINAIRE lg_maxi;

/* Package saisie */
#ifndef sask

#ifdef LINT_ARGS
/* global*/ SWORD saisie(BINAIRE, BINAIRE, BINAIRE, BINAIRE, BYTE XPTR );
#else
/*global*/ SWORD saisie();
#endif

#else

#ifdef LINT_ARGS
/* global*/ SWORD ask(BINAIRE, BINAIRE, BINAIRE, BINAIRE, BYTE XPTR );
#else
/*global*/ SWORD ask();
#endif

#endif


/* Fonctions Privees */
#ifdef LINT_ARGS
static VOID f_droite(VOID);
static VOID f_gauche(VOID);
static VOID del_car(VOID);
static VOID del_back(VOID);
static VOID entree(BYTE);
static VOID Affiche(BINAIRE);
static VOID Init(BYTE XPTR , BINAIRE);
static VOID Recopie(BYTE XPTR , BINAIRE);
static VOID s_pos(BINAIRE);
static VOID deb_fin(VOID);
static VOID debfin_vue(VOID);
static VOID putch(BYTE);
static VOID raz(VOID);
#else
static  VOID f_droite();
static  VOID f_gauche();
static  VOID del_car();
static  VOID del_back();
static  VOID entree();
static  VOID Affiche();
static  VOID Init();
static  VOID Recopie();
static  VOID s_pos();
static  VOID deb_fin();
static  VOID debfin_vue();
static  VOID putch();
static  VOID raz();
#endif

/*********************/

/* Saisie body */

#ifndef sask
/* global */ SWORD saisie(BINAIRE in_lig, BINAIRE in_col, BINAIRE in_lvisu, BINAIRE in_lmax, BYTE XPTR inout_buf)
#else
/* global */ SWORD ask(BINAIRE in_lig, BINAIRE in_col, BINAIRE in_lvisu, BINAIRE in_lmax, BYTE XPTR inout_buf)
#endif

{


	BYTE c;
	
	bool_ctrlp 	= FALSE;
	bool_ins 	= FALSE;
	first_car 	= TRUE;

	Xatb(26); /* on_cursor */

	/* Instances de la partie generique */

	pos_lig = in_lig;
	pos_col = in_col;
	lg_visu = in_lvisu;
	lg_maxi = (BINAIRE) (in_lmax - 1); /* se reserve une place pour la fin de ligne */
	
	Init(inout_buf, in_lmax); /* Initialise le tableau trav sur une longueur de lmax */

	Xatb(0);
#ifndef sask
	deb_fin(); /* par defaut en fin de commande */
#endif
	Affiche(indice_actuel);
#ifdef souris
if (env_mouse) {
	s = PositSouris((BINAIRE) ((pos_col+1) * 8) ,(BINAIRE) ((in_lig-1) * 8) );
}
#endif
	while (1) {

		c = (BYTE) x_getch();
#ifdef souris
		if (c == MOUSE) {
			if ((mouse_lin == in_lig) && (mouse_col >= in_col) && (mouse_col <= (in_col + in_lvisu)) ) {
				switch (mouse_bouton) {
					case 0:
						c = CTRLJ;
						break;
					case 1:
						c = TABUL;
						break;
					case 2:
						c = ESCAPE;
						break;
					case 3:
						c = ESCAPE;
						break;
					default:
						break;
				};
			}
			else {
#ifndef sask
				Xatb(0);
				Affiche(nb_deb_gauche);
				Recopie(inout_buf,taille_actuelle);
				Xatb(25);
#else
				entree(c);
#endif
				return(c);
			}
		}
#endif
		if (c == ESCAPE) {
#ifndef sask	
			Xatb(0);
			Init(inout_buf, in_lmax); /* ReInitialise le tableau trav sur une longueur de lmax */
			Affiche(nb_deb_gauche);
			Xatb(25);
			return(-1);
#else
			entree(c);
#endif
		}
		else if (c == TABUL) {
#ifndef sask
			Xatb(0);
			Affiche(nb_deb_gauche);
			Recopie(inout_buf,taille_actuelle);
			Xatb(25);
			return(-2);	/* TABUL */
#else
			entree(c);
#endif
		}
		else if (c == CR) {
			Xatb(0);
			Affiche(nb_deb_gauche);

	 		if (indice_actuel != 0) {
				Recopie(inout_buf,indice_actuel);
				taille_actuelle = indice_actuel;
			}
			else {
				Recopie(inout_buf, taille_actuelle);
			}
			Affiche(indice_actuel);

#ifndef sask
			atb(25);
#endif
			return(taille_actuelle);
		}
		else if (c == CTRLJ) {
			/* prend tout */
			Xatb(0);
			Affiche(nb_deb_gauche);
		 	Recopie(inout_buf,taille_actuelle);
#ifndef sask
			atb(25);
#endif
			return(taille_actuelle);

		}
		else if (c == INSERT) {
			bool_ins = (BOOL) ! bool_ins;
			Xatb(2 * bool_ins); 	/* inverse video ==> mode normal */
			Affiche(nb_deb_gauche); /* mode normal   ==> mode insert */
		}
		else if (c == CURH) {
#ifndef sask
			Recopie(inout_buf,taille_actuelle); 
			atb(25);
#endif
			return(-3);
		}
		else if (c == CURB) {
#ifndef sask
			Recopie(inout_buf,taille_actuelle);
			atb(25);
#endif
			return(-4); 
		}
#ifndef sask
		else if (c == CTRLC)	{
			atb(25);
			return(-5);	/* integre */
		}
#endif
		else if (c == CURD) 	f_droite();	
		else if (c == CURG) 	f_gauche();
		else if (c == DELBACK)  del_back();
		else if (c == DELCAR)   del_car();
		else if (c == CTRLW) 	debfin_vue();
		else if (c == HOME)	{
				indice_actuel = taille_actuelle; /* force debut de ligne */
				deb_fin();
		}
		else if (c == PDEBFIN) 	deb_fin();
		else if (c == T7F)	del_car();
		else {
			if (first_car) {
				/* on ecrase toute la selection */
				raz();
				Affiche(indice_actuel);
			}

			/* entre n'importe quel caractere */
			if (c == CTRLP) { bool_ctrlp = TRUE; c = (BYTE) x_getch(); }
/* #else 
			if (c == CTRLA) { bool_ctrlp = TRUE; }
#endif*/

			entree(c);
/*#ifdef sask*/
			if (bool_ctrlp) bool_ctrlp = FALSE;	/* desactive le CTRL A */
/*#endif*/
		}
		if (first_car) first_car = FALSE;
	}
}

static VOID raz()
{
	BINAIRE indice = 0;

	/* on recopie la chaine dans le trableau de travail */

	indice = indice_actuel = taille_actuelle = 0;

	/* padding a blanc de la fin de chaine a la fin du tableau */
	while (indice < lg_maxi) {
		trav[indice ++] = ' ';
	}
	
	/* Calcul du nomre de caracteres qui deborde a droite et a gauche */
	nb_deb_gauche = 0;
	nb_deb_droite = (BINAIRE) (lg_visu-1);
}

static VOID deb_fin()
{
	if (indice_actuel != taille_actuelle) {
		indice_actuel = taille_actuelle;
		if (indice_actuel > lg_visu) {
			nb_deb_gauche = (BINAIRE) (indice_actuel - (lg_visu/2));
			nb_deb_droite = (BINAIRE) ((indice_actuel + (lg_visu/2)) - 1);
		}
	}
	else {
		indice_actuel = 0;
		nb_deb_gauche = 0;
		nb_deb_droite = (BINAIRE) (lg_visu - 1);
	}
	Affiche(nb_deb_gauche);  
}

static VOID debfin_vue()
{
	BINAIRE max_indice;


	(taille_actuelle > nb_deb_droite) ? (max_indice = nb_deb_droite) : (max_indice = taille_actuelle);
	(indice_actuel != max_indice) ? (indice_actuel = max_indice) : (indice_actuel = nb_deb_gauche);

	s_pos(indice_actuel);
}

static VOID f_droite()
{                                                                                                                 
	if (indice_actuel < taille_actuelle) {
		indice_actuel ++;
		if (indice_actuel > nb_deb_droite) {
			nb_deb_gauche ++;
			nb_deb_droite ++;
			Affiche(nb_deb_gauche);
		}
	}
	else x_bell();
	s_pos(indice_actuel);
}

static VOID f_gauche()
{
	if (indice_actuel > 0) {
		indice_actuel --;
		if (indice_actuel < nb_deb_gauche) {
			nb_deb_gauche --;
			nb_deb_droite --;
			Affiche(nb_deb_gauche);
		}

	}
	else x_bell();
	s_pos(indice_actuel);
}

static VOID del_car()
{
	BINAIRE i;	

	if (taille_actuelle > indice_actuel) {
		for (i = indice_actuel; i < taille_actuelle; i ++) {
			trav[i] = trav[i+1];
		}

		taille_actuelle --;
		Affiche(indice_actuel);
	}
	else 	x_bell();
}

static VOID del_back()
{
	if (indice_actuel > 0) {
		f_gauche();
		del_car();
		Affiche(indice_actuel);
	}
	else 	x_bell();
}

static VOID entree(BYTE c)
{
	BINAIRE i;


	if (!bool_ctrlp && (c < 0x20 && c != ESCAPE && c != TABUL)) {		/* caractere invalide */
		x_bell();
		return;
	}
	if (indice_actuel < lg_maxi) {
	   if (bool_ins) {
		if (taille_actuelle < lg_maxi) {
			for (i=taille_actuelle; i > indice_actuel; i --) {
				trav[i] = trav[i-1];
			}
		}
		else {
			x_bell();
			return;
		}
	   }
	}
	else {
		x_bell();
		return;
   	}

	if ((bool_ins || indice_actuel == taille_actuelle) && taille_actuelle < lg_maxi)
		taille_actuelle ++;

	trav[indice_actuel] = c;

	if (bool_ins) 
		Affiche(indice_actuel);
	else 	putch(c);	

	f_droite();
}


static VOID Affiche(BINAIRE indice)
{
#ifdef buf_cico
x_bstart();
#endif
	Xatb(25); 	/* extinction du curseur */

	pos(pos_lig,pos_col);
	if (nb_deb_gauche != 0) {
		putch('<');
		putch(trav[nb_deb_gauche-1]);
	}
	else 	x_cprintf((BYTE FPTR) "  ");


	s_pos(indice);

	while (indice <= nb_deb_droite) {
		if (indice < taille_actuelle)	
			putch(trav[indice]);
		else 	putch(' ');
		indice ++;
	}

	if (taille_actuelle > nb_deb_droite+1) {
		putch(trav[nb_deb_droite+1]);
		putch('>');
	}
	else	x_cprintf((BYTE FPTR)"  ");

	s_pos(indice_actuel);
	
	Xatb(26);	/* Re_apparition du curseur */
#ifdef buf_cico
x_bflush();
#endif
}


static VOID Init( BYTE XPTR in_buf, BINAIRE in_lmax)
{
	BINAIRE indice = 0;

	/* on recopie la chaine dans le trableau de travail */

	while (*in_buf != EOSTR && indice < in_lmax) {
		trav[indice++] = *in_buf++;
	}
	
	
	taille_actuelle = indice;

	/* padding a blanc de la fin de chaine a la fin du tableau */
	while (indice < in_lmax) {
		trav[indice ++] = ' ';
	}
	
	indice_actuel = 0;

	/* Calcul du nomre de caracteres qui deborde a droite et a gauche */
	nb_deb_gauche = 0;
	nb_deb_droite = (BINAIRE) (lg_visu-1);

}

static VOID Recopie(BYTE XPTR out_buf, BINAIRE in_lg)
{
	BINAIRE i;
	BINAIRE j;
	BOOL    debut;

	/* Suppression des blancs en debut de chaine */

	j = 0;
	debut = TRUE;

	for (i = 0; i < in_lg; i++) {
		if ( debut == TRUE ) {
			if ( trav[i] != ' ') {
				debut = FALSE;
				*(out_buf + j++) = trav[i];
			}
		}
		else *(out_buf + (j++)) = trav[i];
	}
	*(out_buf + j) = EOSTR;
}

static VOID s_pos(BINAIRE i)
{
	pos(pos_lig,pos_col+(i - nb_deb_gauche)+2);
}

static VOID putch(BYTE c)
{

	if (c < 0x0020) {
		if (bool_ins) 	Xatb(0);
		else 		Xatb(2);
		if (c == ESCAPE) x_putch('&');
		else  		 x_putch(0x0040+c);
		if (bool_ins)	Xatb(2);
		else 		Xatb(0);
	}
	else {
		x_putch(c);
	}
}

