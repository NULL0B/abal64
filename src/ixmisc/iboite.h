	/* includes de definition */

#include "misc.h"
#ifndef unix
#ifdef vms
#include <alloc.h>
#else
#include <malloc.h>
#endif
#endif
	/* ----------------------- */

#define TRUE 1
#define FALSE 0
#define CR '\r'
#define PGUP 	0x12
#define PGDN	0x03
#define ESCAPE 	0x1b
#define CURD   	0x04
#define CURG  	0x11
#define CURH	0x05
#define CURB	0x18
#define DELBACK 0x08
#define DELCAR  0x07
#define INSERT  0x0f
#define CTRLW   0x17
#define PDEBFIN 0x02
#define TABUL   0x09
#define T7F	0x7f
#define HOME	0x01
#define CTRLF   0x06 /* fin extraordinaire */
#define CTRLY   0x19 /* Ctrl-Y */
#define RCH 48
#define RCB 60


/* Declarations des varialbles */

#define LMAXHIS 20
#define LGBNOM 13
#define LGVOL 3
#define PATH_LEN 50

#define rcol 1

#define MOINS '-'


 BYTE sel[LGREP];
 BYTE tmp[LGREP];
 BYTE nomtmp[LGREP];
 BYTE n_path[LGREP];
 BYTE buf_path[LGREP];
 BOOL bool_path;

BYTE sext[LGEXT]; 	/* Extention 	*/
BYTE sjoker[LGMXNOM];	/* nom		*/

BINAIRE ligne, colonne;

#define FileCat struct _Fic	/* Liste des procedures externes */

FileCat {
	BYTE nom[LGMXNOM];
	BYTE etat;
};
#define All_Cat()	 (FileCat FPTR ) allocate(sizeof(FileCat))
#define Free_Cat(p)	 liberate( (BYTE FPTR) p )

#define Liste struct _Lis	/* Liste de cfic */
Liste {
	FileCat FPTR ptfic;
	Liste XPTR next, XPTR back;
};
#define All_Lis()	 (Liste XPTR ) Xmalloc(sizeof(Liste))
#define Free_Lis(p)	 Xfree((BYTE XPTR ) p)

/* Structure generale des parties */
#define StrGen struct _Gen
StrGen {
	BINAIRE ncol,nlig;
	BINAIRE imax, jmax;

	BINAIRE deb_page,fin_page; /* Bornes de la page affiche */
	Liste XPTR adr_deb, XPTR adr_fin; /* Pointeur sur les bornes */
	
	BINAIRE LH,CH,LB,CB;
	BYTE cat_mod[LGREP];

	BYTE nom[LGMXNOM]; /* Nom de la liste */
	
	BINAIRE lg_liste;
	BOOL type_aff;  /* 0 affiche path+nom  1 affiche nom uniquement */
	Liste XPTR lnext;	/* pointe sur le prochain */
	Liste XPTR lback;   /* pointe sur le dernier */

	Liste XPTR adr_fic;		/* Sauvegarde de l'adresse du dernier cfic */
	BINAIRE num_fic;	/* point ainsi que son numero */
	
	BINAIRE LG_AFF;
};

StrGen XPTR pcfic;
StrGen XPTR pcrep;
StrGen XPTR pchis;


#ifdef unix
#define Xchdir(x)	chdir(x)
#endif

#ifdef souris
#define MOUSE 0x00f0
/* Souris */
extern BINAIRE mouse_col;
extern BINAIRE mouse_lin;
extern BINAIRE mouse_bouton;
BINAIRE s;
extern BINAIRE PositSouris(BINAIRE, BINAIRE);
extern BINAIRE mouse_getch(void);
#endif

/* Fonctions generiques */

#ifdef LINT_ARGS
extern VOID x_cprintf(BYTE FPTR);
extern VOID x_putch(BYTE);
extern VOID pos(BINAIRE , BINAIRE);
extern VOID cadre(BINAIRE,BINAIRE,BINAIRE,BINAIRE);
extern VOID Xatb(BINAIRE);
extern VOID fn_parser(BYTE FPTR, BYTE FPTR, BINAIRE);
extern SWORD FRep(BYTE XPTR, BYTE XPTR);
extern SWORD NRep(BYTE XPTR);
extern SWORD FFile(BYTE XPTR, BYTE XPTR);
extern SWORD NFile(BYTE XPTR);
extern VOID  diff_repfich(BYTE XPTR, BYTE XPTR, BYTE XPTR);
extern BOOL  NextOpt(BYTE XPTR XPTR, BYTE XPTR);
extern SWORD saisie(BINAIRE, BINAIRE, BINAIRE, BINAIRE, BYTE XPTR );
extern SWORD GetReper(BYTE XPTR XPTR, BINAIRE);
extern SWORD MakeReper(BYTE XPTR, BYTE XPTR);
extern VOID  x_bell(VOID);
extern SWORD SetDisk(BINAIRE);
#ifndef unix
extern SWORD Xchdir(BYTE XPTR);
#endif

#else
extern VOID pos();
extern VOID cadre();
extern VOID Xatb();
extern VOID fn_parser();
extern SWORD FRep();
extern SWORD NRep();
extern SWORD FFile();
extern SWORD NFile();
extern VOID diff_repfich();
extern VOID  diff_repfich();
extern BOOL  NextOpt();
extern SWORD saisie();
extern SWORD GetReper();
extern SWORD MakeReper();
extern VOID  x_bell();
extern SWORD SetDisk();
#ifndef unix
extern SWORD Xchdir();
#endif
#endif

/* Package iboite */
#ifdef LINT_ARGS
/*global*/ SWORD boite(BINAIRE, BINAIRE, BYTE XPTR , BYTE XPTR ,StrGen XPTR , StrGen XPTR, StrGen XPTR, BYTE XPTR);
/*global*/ VOID init_boite(StrGen XPTR , BINAIRE, BINAIRE,BINAIRE,BINAIRE,BINAIRE,BINAIRE,BINAIRE, BYTE XPTR);
/*global*/ VOID liste_histo(StrGen XPTR, BYTE XPTR);
#else
/*global*/ SWORD boite();
/*global*/ VOID  init_boite();
/*global*/ VOID  liste_histo();
#endif


/* Fonctions Privees */
#ifdef LINT_ARGS
/*global*/ VOID init_sel(VOID);
/*global*/ BINAIRE init_fic(VOID);
/*global*/ VOID init_aff(StrGen XPTR);
/*global*/ VOID affiche(StrGen XPTR);
/*global*/ VOID aff_liste(StrGen XPTR);
/*global*/ VOID next_pos(BINAIRE, BINAIRE);
/*global*/ VOID findliste(StrGen XPTR, BINAIRE, BINAIRE, BINAIRE);
/*global*/ VOID purge(StrGen XPTR);
/*global*/ BINAIRE init_rep(VOID);
/*global*/ VOID init_his(VOID);
/*global*/ SWORD chx(VOID);
/*global*/ VOID aff_path(BYTE XPTR);
/*global*/ BINAIRE joker(BYTE XPTR);
/*global*/ SWORD ChgDir(BYTE XPTR);
/*global*/ VOID maj_path(VOID);
/*global*/ SWORD selection(StrGen XPTR);
/*global*/ VOID Print(StrGen XPTR,BINAIRE, BINAIRE);
/*global*/ VOID maj_histo(BYTE XPTR);
/*global*/ SWORD saisie_sel(BYTE XPTR);
/*global*/ Liste XPTR new_node(BYTE XPTR);
/*global*/ SWORD ins_en_tete(StrGen XPTR ,BYTE XPTR);
/*global*/ SWORD ins_en_milieu(StrGen XPTR ,BYTE XPTR);
/*global*/ SWORD ins_en_fin(StrGen XPTR ,BYTE XPTR);
/*global*/ SWORD ins_en_ordre(StrGen XPTR ,BYTE XPTR);
/*global*/ VOID ins_item(StrGen XPTR ,BYTE XPTR);
/*global*/ VOID del_item(StrGen XPTR);
/*global*/ VOID del_en_tete(StrGen XPTR);
/*global*/ VOID del_en_fin(StrGen XPTR);
/*global*/ VOID del_en_milieu(StrGen XPTR);
/*global*/ VOID Posit(StrGen XPTR , BINAIRE);
/*global*/ BINAIRE Posit_car(StrGen XPTR , BYTE);
/*global*/ BINAIRE cmp_item(BYTE XPTR, FileCat FPTR);
/*global*/ BINAIRE Find_Item(StrGen XPTR, BYTE XPTR);
/*global*/ BINAIRE Mstrcmp( BYTE FPTR s, BYTE FPTR d);
#else
/*global*/ VOID init_sel();
/*global*/ BINAIRE init_fic();
/*global*/ VOID init_aff();
/*global*/ VOID affiche();
/*global*/ VOID aff_liste();
/*global*/ VOID next_pos();
/*global*/ VOID findliste();
/*global*/ VOID purge();
/*global*/ BINAIRE init_rep();
/*global*/ VOID init_his();
/*global*/ SWORD chx();
/*global*/ VOID aff_path();
/*global*/ BINAIRE joker();
/*global*/ SWORD ChgDir();
/*global*/ VOID maj_path();
/*global*/ SWORD selection();
/*global*/ VOID Print();
/*global*/ VOID maj_histo();
/*global*/ SWORD saisie_sel();
/*global*/ Liste XPTR new_node();
/*global*/ SWORD ins_en_tete();
/*global*/ SWORD ins_en_milieu();
/*global*/ SWORD ins_en_fin();
/*global*/ SWORD ins_en_ordre();
/*global*/ VOID ins_item();
/*global*/ VOID del_item();
/*global*/ VOID del_en_tete();
/*global*/ VOID del_en_fin();
/*global*/ VOID del_en_milieu();
/*global*/ VOID Posit();
/*global*/ BINAIRE Posit_car();
/*global*/ BINAIRE cmp_item();
/*global*/ BINAIRE Find_Item();
/*global*/ BINAIRE Mstrcmp();
#endif

/*********************/

