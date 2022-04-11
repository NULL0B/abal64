/*
 *	Bibliotheques Statiques ABAL
 *	----------------------------
 *
 *	Copyright (c) 2021 Amenesik / Sologic
 *
 *	bsa.c - code de demarrage d'une bibliotheque statique
 *
 *	Mises a jour :
 *	------------
 *
 */


/*
 *	IJM
 *
 *	This file has been modified 07/10/2001 to simplify the confusion that
 *	reigned on the interface : all interface functions use the standard
 *	macros GetAbalWord and GetParaByte to ensure parameter compatiblity.
 *
 */


#include <stdio.h>
#include <setjmp.h>
#include <sys/types.h>

#include "asfcico.h"
#include "bdacico.h"
#include "sfundef.h"

#if MSDOS || PRL
#include <conio.h>
#else
#include <stdio.h>
#endif

#include "bda.h"

/*
 *	contexte de retour brutal a l'executeur
 *	---------------------------------------
 */

static jmp_buf Jump;

#include "rle.c"


/*
 *	declaration des structures de la BDA
 *	------------------------------------
 */

extern BDA_INIT PTR rt_init;
static BDA PTR descripteur;
extern EXAWORD err_val;

void FAR * InitRelais();

VOID rt_error(EXAWORD);

/*
 *	definitions
 *	-----------
 */

#define FC_INIT		0
#define FC_KILL		1
#define FC_CALL		2
#define	BDA_SCRATCH	138
#define BDA_UNKNOWN	139



/* rt_error - retour brutal a l'executeur
 * --------------------------------------
 *
 * appel:	VOID rt_error(code);
 *		EXAWORD code = code erreur a retourner a l'executeur
 *
 * retour:	rien
 *
 */
VOID rt_error(EXAWORD code)
{
	longjmp(Jump, code);
}

/* -------------- Fin de Fichier : bsamf.c ---------------------------- */

/*
 	Bibliotheque Dynamique Multi-Fenetrage
 *	--------------------------------------
 *
 *	Copyright (c) 2021 Amenesik / Sologic
 *
 *	asfun.c - fonctions entete
 *
 *	$Header: /home/Produits/Abal3/asfun/bsamf.c,v 1.3 2006/05/18 16:00:12 jamie Exp $
 *
 ***************************************************
 *	MAJ llb		18.12.90
 *	    cr		18.03.91
 *	    llb		14.08.91	Boites dialogue
 *	    llb		11.10.91	wexit,wrefresh	
 *	    llb		16.10.91	menu_way
 *	    llb		21.01.92	swcreat
 *	    llb		03.02.92	wcadre,wtitre
 *	    llb		18.02.92	wmove
 *	    eds		23.04.92	set_tch_esc
 *	    llb		13.05.92	winfo...( Version 1.3)
 *	    eds		01.06.92	fct mouse( Version 1.4)
 * 	    llb	        01.04.93	get/set_style
 *	    llb	        07.04.93	wlangue
 *	    llb	        06.05.93	asfvers
 *	    llb	        27.09.93	read_event()
 *	    llb	        26.11.93	Relay_lo = Run_Mi (Mouse ABAL 2.1) 
 * Version  1.4d
 *	    llb		17.12.93	adapt TOP WINDOW	
 * Version  1.4e
 *	    llb 	21.02.94	Corr clear ecran sur initrelay
 *			27.09.94	fnc SCROLL_BAR accessibles en dosext
 */

#define	VERS	'1'
#define	INDICE	'4'
#define	RELEASE	'e'



#define		NB_WFONC	91 	/* nbre fonctions ASFUN */

/* Variable necessaire a CICO : 03/12/91 */

unsigned short int sicico=0;


/* *	Definitions evolutives
 *	----------------------
 */

#ifndef MENTION_PROVISOIRE
#if M_I8086 || M_I186 || M_I286 || __TURBOC__
#define MENTION_PROVISOIRE	"\n\r   PROVISOIRE ("__DATE__" "__TIME__")"
#else
#define MENTION_PROVISOIRE	"\n\r   PROVISOIRE"
#endif /* M_I8086 || M_I186 || M_I286 || __TURBOC__ */
#endif /* MENTION_PROVISOIRE */

#define VERSION 		"  Version 1.4e"
#define COPYRIGHT		"   Copyright (c) 2021 Amenesik / Sologic "

#ifdef PRL
#define prologue		/* adaptation "bda.h" 1.4a */
#endif


/*
 *	Fonctions externes
 *	------------------
 */


#include "bdacico.c"


#if PRL

extern void far Run_Co(EXAWORD);
extern EXAWORD far Run_Info(EXAWORD);
extern void far Run_Mes(BYTE far *,WORD);
extern void far Run_Str(BYTE far *);
extern EXAWORD Run_Mi(BYTE far *);

#else

extern void initerm();		/* initialisation CICO		*/
extern void finterm();		/* terminaison CICO		*/
extern EXAWORD x_getch();
extern EXAWORD x_kbhit();
extern void x_clear();
extern EXAWORD prfo();
extern EXAWORD lcfo();
extern EXAWORD Run_Conf();
extern EXAWORD Run_Co();
extern EXAWORD Run_Lin();
extern EXAWORD Run_Col();
extern void Run_Mes();
extern void Run_Str();
extern EXAWORD _lo();

#endif /* PRL */

/*
 *	Variables externes
 *	------------------
 */

#if !PRL

extern EXAWORD prndest;

#endif /* !PRL */


/*
 *	Variables utilisees
 *	-------------------
 */

static BDA Descripteur;		/* descripteur de bibliotheque	*/
extern BDA_INIT FAR * rt_init;


extern GLOBAL BDA_ARG rt_arg;




#if PRL

int _mem_res = 1;		/* chargement resident		*/
int _stkmin = 4096;		/* minimum reserve a la pile	*/
int _stklen = 40280;		/* taille pile + tas		*/

#endif /* PRL */


#if MSDOS || PRL || dosext	/* table des messages		*/
static char *message[] = {
	"*STX*2ASFUN   13a00",
#else
static char message[][42] = {
	"*STX*3ASFUN   11b00\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
#endif /* MSDOS || PRL */
	"   Gestionnaire multifenetres et Services",
	"                                         ",
	"*ETX*",
};

static char *provisoire = MENTION_PROVISOIRE;
static char *version = VERSION;
static char *copyright = COPYRIGHT;


/*
 *	Declarations des fonctions
 *	--------------------------
 */

static void FAR Banniere();
static void FAR FinRelais();
static void AfficheChaine();
static void NouvelleLigne();
static char *ChercheMessage();
EXAWORD   asfvers();

/*
 *	Fonctions entetes pour Unix ou VMS
 *	----------------------------------
 */

#if unix || M_XENIX || vms || dosext

/*
#include "abal.h"
 */

EXAWORD PASCAL FAR _winit(a)
void *a[];
{
#ifdef CPYFO
	EXAWORD ret;
	ret =  winit(	GetParaByte( 0 ),
			GetParaByte( 1 ),
			GetParaByte( 2 ),
			GetParaByte( 3 ),
			GetParaByte( 4 ) );
        cpyfo();			/* recopie des touches fonctions dans asfun.c */
	return(ret);
#else
	return(winit(	GetParaByte( 0 ),
			GetParaByte( 1 ),
			GetParaByte( 2 ),
			GetParaByte( 3 ),
			GetParaByte( 4 ) ) );
#endif /*CPYFO */
}

EXAWORD PASCAL FAR _wcreat(void *a[])
{
	return (wcreat((WORD *)a[0], (BYTE *)a[1]));
}

EXAWORD PASCAL FAR _wsup(void *a[])	{	return( wsup( GetParaByte( 0  ) ) );		}
EXAWORD PASCAL FAR _winv(void *a[])	{	return( winv( GetParaByte( 0  ) ) );		}
EXAWORD PASCAL FAR _wvis(void *a[])	{	return( wvis( GetParaByte( 0  ) ) );		}
EXAWORD PASCAL FAR _wselect(void *a[])	{	return( wselect( GetParaByte( 0  ) ) );	}
EXAWORD PASCAL FAR _wimpl(void *a[])	{	return( wimpl( GetParaByte( 0  ) ) );		}
EXAWORD PASCAL FAR _wgel(void *a[])	{	return( wgel( GetParaByte( 0  ) ) );		}
EXAWORD PASCAL FAR _wfend(void *a[])	{	return (wend());				}



EXAWORD PASCAL FAR _wwrite(void *a[])
{
	return( 
		wwrite( GetParaByte( 0  ),
			GetParaByte( 1  ),
			(BYTE*) a[2]	 ) );
}


EXAWORD PASCAL FAR _wfgen(void *a[])
{
	return( wfgen( 	GetParaByte( 0  ), 
			GetParaByte( 1 ) ) );
}

EXAWORD PASCAL FAR _watb(void *a[])
{
	return( watb( 	GetParaByte( 0   ),
			GetParaByte( 1  ),
			GetParaByte( 2  ),
			GetParaByte( 3  ) ) );
}

EXAWORD PASCAL FAR _wposcur(void *a[])
{
	return( 
		wposcur(GetParaByte( 0  ),
			GetParaByte( 1 ),
			GetParaByte( 2 ) ) );
}

EXAWORD PASCAL FAR _wsetatb(a)
void *a[];
{
	return (wsetatb(GetParaByte( 0  ),
			GetParaByte( 1 ),
			GetParaByte( 2 ),
			GetParaByte( 3 ),
			GetParaByte( 4 ),
			GetParaByte( 5 ),
			GetParaByte( 6 ),
			GetParaByte( 7 ) ));
}

EXAWORD PASCAL FAR _wgetimpl(a)
void *a[];
{
	return( wgetimpl( a[0] ) );
}

EXAWORD PASCAL FAR _sf_init(a)
void *a[];
{
#ifdef CPYFO
	EXAWORD ret;
	ret = sfinit((BYTE *)a[0]);
	cpyfo();
	return(ret);
#else
	return (sfinit((BYTE *)a[0]));
#endif /* CPYFO */
}

EXAWORD PASCAL FAR _lsacti(a)
void *a[];
{
	return (lsacti());
}

EXAWORD PASCAL FAR _lsmess(a)
void *a[];
{
	return (lsmess(	GetParaByte(0),
		 	GetParaByte(1),
			(BYTE*)   a[2] ) );
}

EXAWORD PASCAL FAR _lsclear(a)
void *a[];
{
	return (lsclear());
}

EXAWORD PASCAL FAR _lsdesac(a)
void *a[];
{
	return (lsdesac());
}

EXAWORD PASCAL FAR _menu_cre(a)
void *a[];
{
	return (md_creat(GetParaByte(0),
			 (BYTE *)    a[1] ) );
}

EXAWORD PASCAL FAR _menu_opt(a)
void *a[];
{
	return (mo_creat(
		GetParaByte(0),
		GetParaByte(1),
		(BYTE *)    a[2] ,
		(BYTE *)    a[3] ,
		(BYTE *)    a[4] ) );
}

EXAWORD PASCAL FAR _menu_sep(a)
void *a[];
{
	return (mo_sep(	GetParaByte(0),
			GetParaByte(1)) );
}

EXAWORD PASCAL FAR _menu_mod(a)
void *a[];
{
	return (mo_modif(
			GetParaByte(0),
			GetParaByte(1),
			GetParaByte(2),
			(BYTE *)    a[3] ,
			(BYTE *)    a[4] ,
			(BYTE *)    a[5] ) );
}

EXAWORD PASCAL FAR _menu_lat(a)
void *a[];
{
	return (mo_latt(GetParaByte(0),
			GetParaByte(1),
			(BYTE *)    a[2] ,
			(BYTE *)    a[3] ,
			(BYTE *)    a[4] ) );
}

EXAWORD PASCAL FAR _menu_mat(a)
void *a[];
{
	return (mo_matt(
			GetParaByte(0),
			GetParaByte(1),
			GetParaByte(2),
			GetParaByte(3),
			GetParaByte(4)) );
}

EXAWORD PASCAL FAR _menu_ann(a)
void *a[];
{
	return (mo_clear(
			GetParaByte(0),
			GetParaByte(1)) );
}

EXAWORD PASCAL FAR _menu_aff(a)
void *a[];
{
	return (md_aff(
			GetParaByte(0),
			GetParaByte(1),
			GetParaByte(2)) );
}

EXAWORD PASCAL FAR _menu_cho(a)
void *a[];
{
	return (md_opt(
			GetParaByte(0),
			GetParaByte(1),
			(BYTE *)    a[2] ,
			(BYTE *)    a[3] ,
			(BYTE *)    a[4] ,
			(BYTE *)    a[5] ) );
}

EXAWORD PASCAL FAR _menu_eff(a)
void *a[];
{
	return (md_clear(GetParaByte(0)));
}

EXAWORD PASCAL FAR _menu_sup(a)
void *a[];
{
	return (md_sup(GetParaByte(0)));
}

EXAWORD PASCAL FAR _list_cre(a)
void *a[];
{
	return (ld_creat(GetParaByte(0),
			 (BYTE *)    a[1] ) );
}

EXAWORD PASCAL FAR _lismul_c(a)
void *a[];
{
	return (lm_creat(GetParaByte(0),
			 (BYTE *)    a[1] ) );
}

EXAWORD PASCAL FAR _list_ele(a)
void *a[];
{
	return( le_creat(
			GetParaByte(0),
			(WORD *)    a[1] ,
			GetParaByte(2),
			GetParaByte(3),
			(BYTE *)    a[4] ,
			(BYTE *)    a[5] ) );
}

EXAWORD PASCAL FAR _list_lec(a)
void *a[];
{
	return (le_lect(GetParaByte(0),
			GetParaByte(  1 ),
			(BYTE *)    a[2] ,
			(BYTE *)    a[3] ,
			(BYTE *)    a[4] ) );
}

EXAWORD PASCAL FAR _list_sui(a)
void *a[];
{
	return( le_down(
			GetParaByte(0),
			(WORD *)    a[1] ,
			(BYTE *)    a[2] ,
			(BYTE *)    a[3] ,
			(BYTE *)    a[4] ) );
}

EXAWORD PASCAL FAR _list_pre(a)
void *a[];
{
	return( le_up(
			GetParaByte(0),
			(WORD *)    a[1] ,
			(BYTE *)    a[2] ,
			(BYTE *)    a[3] ,
			(BYTE *)    a[4] ) );
}

EXAWORD PASCAL FAR _list_mat(a)
void *a[];
{
	return (le_matt(
			GetParaByte(0),
			GetParaByte(  1 ),
			GetParaByte(2),
			GetParaByte(3),
			(BYTE*)     a[4] ,
			(BYTE*)     a[5] ) );
}

EXAWORD PASCAL FAR _list_fer(a)
void *a[];
{
	return (ld_close(GetParaByte(0)));
}

EXAWORD PASCAL FAR _list_aff(a)
void *a[];
{
	return (ld_aff(	GetParaByte(0),
			GetParaByte(1),
			GetParaByte(2)) );
}

EXAWORD PASCAL FAR _list_cho(a)
void *a[];
{
	return( ld_choix(	GetParaByte(0),
			(WORD *)    a[1] ,
			(WORD *)    a[2] ,
			(BYTE *)    a[3] ,
			(BYTE *)    a[4] ) );
}

EXAWORD PASCAL FAR _list_eff(a)
void *a[];
{
	return (ld_clear(GetParaByte(0)));
}

EXAWORD PASCAL FAR _list_sup(a)
void *a[];
{
	return (ld_sup(GetParaByte(0)));
}

EXAWORD PASCAL FAR _bvalid_s(a)
void *a[];
{
	return (bv_spc((BYTE *)a[0], (BYTE *)a[1], (BYTE *)a[2]));
}

EXAWORD PASCAL FAR _bvalid(a)
void *a[];
{
	return (bv_std(GetParaByte(0), (BYTE *)a[1]));
}

EXAWORD PASCAL FAR _sf_end(a)
void *a[];
{
	return (sfend());
}

EXAWORD PASCAL FAR _wfmod(a)
void *a[];
{
	return( sftxt_mod(
			GetParaByte(0),
			GetParaByte(1),
			(WORD *)    a[2] ,
			(BYTE *)    a[3] ,
			GetParaByte(4),
			(BYTE *)    a[5] ) );

}

EXAWORD PASCAL FAR _aid_acti(a)
void *a[];
{
	return (sa_activ(GetParaByte(0),(BYTE *) a[1]));
}

EXAWORD PASCAL FAR _aid(a)
void *a[];
{
	return (sa_aid((BYTE *)a[0]));
}

EXAWORD PASCAL FAR _aid_desa(a)
void *a[];
{
	return (sa_desac());
}

EXAWORD PASCAL FAR _aid_def(a)
void *a[];
{
	return (sa_aiddef((BYTE *)a[0]));
}

/* 1.3 */

/*			------------------------				*/
/*			The DIALOG BOX functions				*/
/*			------------------------				*/
/*	These functions collect their own arguments from the rt_args		*/
/*	structure so they look quite void when in fact they are not.		*/


EXAWORD PASCAL FAR _bd_creat(void *a[])		{	return (bd_creat()  );		}
EXAWORD PASCAL FAR _bd_insert(void *a[])	{	return (bd_insert() );		}
EXAWORD PASCAL FAR _bd_use(void *a[])		{	return (bd_use()    );		}
EXAWORD PASCAL FAR _bd_close(void *a[])		{	return (bd_close()  );		}
EXAWORD PASCAL FAR _bd_sup(void *a[])		{	return (bd_sup()    );		}
EXAWORD PASCAL FAR _bd_putdata(void *a[]) 	{ 	return (bd_putdata());		}
EXAWORD PASCAL FAR _bd_getdata(void *a[])	{	return (bd_getdata());		}
EXAWORD PASCAL FAR _wexit(void *a[])		{	return (wexit(GetParaByte(0)));	}
EXAWORD PASCAL FAR _wrefresh(void *a[])		{	return (wrefresh());		}
EXAWORD PASCAL FAR _md_way(void *a[])		{	return (md_way(	(BYTE *)a[0], 
								(BYTE *)a[1]));		}

EXAWORD PASCAL FAR _swcreat(void *a[])
{
	return (swcreat(
			(WORD *) a[0],
			GetParaByte(1),
			GetParaByte(2),
			GetParaByte(3),
			GetParaByte(4) ) );
}

EXAWORD PASCAL FAR _wcadre(a)
void *a[];
{
	return (wcadre(
			GetParaByte(0),
			GetParaByte(1) ));
}

EXAWORD PASCAL FAR _wtitre(a)
void *a[];
{
	return (wtitre(	GetParaByte(0),
			GetParaByte(1),
			GetParaByte(2),
			GetParaByte(3) ) );
}

EXAWORD PASCAL FAR _wmove(a)
void *a[];
{
	return (wmove(	GetParaByte(0),
			GetParaByte(1),
			GetParaByte(2) ) );

}

EXAWORD PASCAL FAR _le_delete(a)
void *a[];
{
	return (le_delete(
			GetParaByte(0),
			GetParaByte(1) ) );
}

EXAWORD PASCAL FAR _le_insert(a)
void *a[];
{
	return( le_insert(
			GetParaByte(0),
			(WORD *)    a[1] ,
			GetParaByte(2),
			GetParaByte(3),
			(BYTE *)    a[4] ,
			(BYTE *)    a[5] ) );
}

EXAWORD PASCAL FAR _sfset_tch_esc(a)
void *a[];
{
	return (sfset_tch_esc( GetParaByte(0), (BYTE *)a[1]));
}

EXAWORD PASCAL FAR _wfinfo(a)
void *a[];
{
	return (wfinfo(GetParaByte(0),(BYTE *) a[1]));
}

EXAWORD PASCAL FAR _get_style(void *a[])	{	return (get_style(GetParaByte(0),(BYTE *) a[1]));	}
EXAWORD PASCAL FAR _set_style(void *a[])	{	return (set_style(GetParaByte(0),(BYTE *) a[1]));	}
EXAWORD PASCAL FAR _wlangue(void *a[])	{	return (wlangue(GetParaByte(0)));			}
EXAWORD PASCAL FAR _asfvers(void *a[])	{	return(asfvers( (BYTE *)a[0]));				}

EXAWORD PASCAL FAR _who_is_there(a)
void *a[];
{
	return( who_is_there(
			GetParaByte(0),
			GetParaByte(1),
			(WORD *)    a[2] ,
			(WORD *)    a[3] ) );
}

EXAWORD PASCAL FAR _rlecomp(a)
void *a[];
{
	return( rlecomp(
			(BYTE *)    a[0] ,
			(BYTE *)    a[1] ,
			GetParaByte(2)) );
}

EXAWORD PASCAL FAR _rledcomp(a)
void *a[];
{
	return( rledcomp(
			(BYTE *)    a[0] ,
			(BYTE *)    a[1] ,
			GetParaByte(2)) );
}


EXAWORD PASCAL FAR _get_event(void *a[])	{	return (get_event( (BYTE *)a[0]));	}
EXAWORD PASCAL FAR _put_event(void *a[])	{	return (put_event( (BYTE *)a[0]));	}


/*			Scroll Bar Functions			*/
/*			--------------------			*/
/*	These functions were quite strange, since they were	*/
/*	colecting a byte from their byte pointer parameter	*/
/*	This looked like a bug before , but may bug now.	*/



EXAWORD PASCAL FAR _add_scroll_bar(void *a[])
{
	return (add_scroll_bar(GetParaByte(0),GetParaByte(1) ) );
}

EXAWORD PASCAL FAR _del_scroll_bar( void *a[] )
{
	return (add_scroll_bar(GetParaByte(0),GetParaByte(1) ) );
}

EXAWORD PASCAL FAR _update_scroll_bar( void *a[] )
{
	return (update_scroll_bar(
			GetParaByte(0),
			GetParaByte(1),
			GetParaByte(2),
			GetParaByte(3) ) );
}

EXAWORD PASCAL FAR _get_scroll_bar_region( void *a[] )
{
	return (get_scroll_bar_region(
			GetParaByte(0),
			GetParaByte(1),
			GetParaByte(2),
			GetParaByte(3), 
			GetParaByte(4),
			GetParaByte(5) ) );


}


#endif /* unix || M_XENIX || vms || dosext */



/*
 *	This file works in conjunction with the 
 *	file BSAMF1.C to describe the interface
 *	to the ABAL dynamic library ASFUN.
 *	
 *	These files have been extensivly reworked
 *	for improved readabillity and bug reduction.
 *
 *	IJM	09/10/2001
 *
 */

/* InitRelais - initialisation bibliotheque
 * ----------------------------------------
 *
 * appel:	void FAR *InitRelais(origine);
 *		char origine = origine de l'appel
 *			       0 = appel par InitRunTime()
 *			       1 = appel depuis l'interpreteur de commandes
 *
 * retour:	pointeur sur le descripteur de bibliotheque
 *
 */


void FAR * InitRelais()

{
	
	initialise_access_controller();

	Descripteur.banniere = (void (FAR *)())Banniere;
	Descripteur.fin = (void (FAR *)())FinRelais;
	Descripteur.nombre = NB_WFONC+15;

#if unix || M_XENIX || vms || dosext

	Descripteur.fonction[0] = (EXAWORD (FAR *)())_winit;
	Descripteur.fonction[1] = (EXAWORD (FAR *)())_wcreat;
	Descripteur.fonction[2] = (EXAWORD (FAR *)())_wsup;
	Descripteur.fonction[3] = (EXAWORD (FAR *)())_wwrite;
	Descripteur.fonction[4] = (EXAWORD (FAR *)())_wselect;
	Descripteur.fonction[5] = (EXAWORD (FAR *)())_winv;
	Descripteur.fonction[6] = (EXAWORD (FAR *)())_wvis;
	Descripteur.fonction[7] = (EXAWORD (FAR *)())_wfgen;
	Descripteur.fonction[8] = (EXAWORD (FAR *)())_watb;
	Descripteur.fonction[9] = (EXAWORD (FAR *)())_wposcur;
	Descripteur.fonction[10] = (EXAWORD (FAR *)())_wimpl;
	Descripteur.fonction[11] = (EXAWORD (FAR *)())_wgel;
	Descripteur.fonction[12] = (EXAWORD (FAR *)())_wfend;
	Descripteur.fonction[13] = (EXAWORD (FAR *)())_wsetatb;
	Descripteur.fonction[14] = (EXAWORD (FAR *)())_sf_init;
	Descripteur.fonction[15] = (EXAWORD (FAR *)())_lsacti;
	Descripteur.fonction[16] = (EXAWORD (FAR *)())_lsmess;
	Descripteur.fonction[17] = (EXAWORD (FAR *)())_lsclear;
	Descripteur.fonction[18] = (EXAWORD (FAR *)())_lsdesac;
	Descripteur.fonction[19] = (EXAWORD (FAR *)())_menu_cre;
	Descripteur.fonction[20] = (EXAWORD (FAR *)())_menu_opt;
	Descripteur.fonction[21] = (EXAWORD (FAR *)())_menu_sep;
	Descripteur.fonction[22] = (EXAWORD (FAR *)())_menu_mod;
	Descripteur.fonction[23] = (EXAWORD (FAR *)())_menu_lat;
	Descripteur.fonction[24] = (EXAWORD (FAR *)())_menu_mat;
	Descripteur.fonction[25] = (EXAWORD (FAR *)())_menu_ann;
	Descripteur.fonction[26] = (EXAWORD (FAR *)())_menu_aff;
	Descripteur.fonction[27] = (EXAWORD (FAR *)())_menu_cho;
	Descripteur.fonction[28] = (EXAWORD (FAR *)())_menu_eff;
	Descripteur.fonction[29] = (EXAWORD (FAR *)())_menu_sup;
	Descripteur.fonction[30] = (EXAWORD (FAR *)())_list_cre;
	Descripteur.fonction[31] = (EXAWORD (FAR *)())_lismul_c;
	Descripteur.fonction[32] = (EXAWORD (FAR *)())_list_ele;
	Descripteur.fonction[33] = (EXAWORD (FAR *)())_list_lec;
	Descripteur.fonction[34] = (EXAWORD (FAR *)())_list_sui;
	Descripteur.fonction[35] = (EXAWORD (FAR *)())_list_pre;
	Descripteur.fonction[36] = (EXAWORD (FAR *)())_list_mat;
	Descripteur.fonction[37] = (EXAWORD (FAR *)())_list_fer;
	Descripteur.fonction[38] = (EXAWORD (FAR *)())_list_aff;
	Descripteur.fonction[39] = (EXAWORD (FAR *)())_list_cho;
	Descripteur.fonction[40] = (EXAWORD (FAR *)())_list_eff;
	Descripteur.fonction[41] = (EXAWORD (FAR *)())_list_sup;
	Descripteur.fonction[42] = (EXAWORD (FAR *)())_bvalid_s;
	Descripteur.fonction[43] = (EXAWORD (FAR *)())_bvalid;
	Descripteur.fonction[44] = (EXAWORD (FAR *)())_sf_end;
	Descripteur.fonction[45] = (EXAWORD (FAR *)())_wfmod;
	Descripteur.fonction[46] = (EXAWORD (FAR *)())_aid_acti;
	Descripteur.fonction[47] = (EXAWORD (FAR *)())_aid;
	Descripteur.fonction[48] = (EXAWORD (FAR *)())_aid_desa;
	Descripteur.fonction[49] = (EXAWORD (FAR *)())_aid_def;
	Descripteur.fonction[50] = (EXAWORD (FAR *)())_wgetimpl;
/* 1.3 */

	Descripteur.fonction[51] = (EXAWORD (FAR *)())_bd_creat;
	Descripteur.fonction[52] = (EXAWORD (FAR *)())_bd_insert;
	Descripteur.fonction[53] = (EXAWORD (FAR *)())_bd_use;
	Descripteur.fonction[54] = (EXAWORD (FAR *)())_bd_close;
	Descripteur.fonction[55] = (EXAWORD (FAR *)())_bd_sup;
	Descripteur.fonction[56] = (EXAWORD (FAR *)())_bd_putdata;
	Descripteur.fonction[57] = (EXAWORD (FAR *)())_bd_getdata;
	Descripteur.fonction[58] = (EXAWORD (FAR *)())_wexit;
	Descripteur.fonction[59] = (EXAWORD (FAR *)())_wrefresh;
	Descripteur.fonction[60] = (EXAWORD (FAR *)())_md_way;
	Descripteur.fonction[61] = (EXAWORD (FAR *)())_swcreat;
	Descripteur.fonction[62] = (EXAWORD (FAR *)())_wcadre;
	Descripteur.fonction[63] = (EXAWORD (FAR *)())_wtitre;
	Descripteur.fonction[64] = (EXAWORD (FAR *)())_wmove;
	Descripteur.fonction[65] = (EXAWORD (FAR *)())_le_delete;
	Descripteur.fonction[66] = (EXAWORD (FAR *)())_le_insert;
	Descripteur.fonction[67] = (EXAWORD (FAR *)())_sfset_tch_esc;
	Descripteur.fonction[68] = (EXAWORD (FAR *)())_wfinfo;


/********************* 1.4 *****/

	Descripteur.fonction[69] = (EXAWORD (FAR *)())_get_style;
	Descripteur.fonction[70] = (EXAWORD (FAR *)())_set_style;
	Descripteur.fonction[71] = (EXAWORD (FAR *)())_wlangue;
	Descripteur.fonction[72] = (EXAWORD (FAR *)())_asfvers;
/*
	Descripteur.fonction[73] = (EXAWORD (FAR *)())set_mouse_position;
	Descripteur.fonction[74] = (EXAWORD (FAR *)())mouse_on;
	Descripteur.fonction[75] = (EXAWORD (FAR *)())mouse_off;
	Descripteur.fonction[76] = (EXAWORD (FAR *)())put_item_mouse_list;
	Descripteur.fonction[77] = (EXAWORD (FAR *)())del_item_mouse_list;
	Descripteur.fonction[78] = (EXAWORD (FAR *)())get_item_mouse_list;
	Descripteur.fonction[79] = (EXAWORD (FAR *)())wait_event;
	Descripteur.fonction[80] = (EXAWORD (FAR *)())flush_event;
	Descripteur.fonction[81] = (EXAWORD (FAR *)())_get_event;
*/
	Descripteur.fonction[82] = (EXAWORD (FAR *)())_put_event;
	Descripteur.fonction[83] = (EXAWORD (FAR *)())_add_scroll_bar;
	Descripteur.fonction[84] = (EXAWORD (FAR *)())_del_scroll_bar;
	Descripteur.fonction[85] = (EXAWORD (FAR *)())_update_scroll_bar;
	Descripteur.fonction[86] = (EXAWORD (FAR *)())_get_scroll_bar_region;
/*
	Descripteur.fonction[87] = (EXAWORD (FAR *)())read_event;
*/
	Descripteur.fonction[88] = (EXAWORD (FAR *)())_who_is_there;
	Descripteur.fonction[89] = (EXAWORD (FAR *)())_rlecomp;
	Descripteur.fonction[90] = (EXAWORD (FAR *)())_rledcomp;

	Descripteur.fonction[NB_WFONC+1] = (EXAWORD (FAR *)())0;		/* 1   */
	Descripteur.fonction[NB_WFONC+2] = (EXAWORD (FAR *)())0;		/* 2   */
	Descripteur.fonction[NB_WFONC+3] = (EXAWORD (FAR *)())0;		/* 4   */
	Descripteur.fonction[NB_WFONC+4] = (EXAWORD (FAR *)())0;		/* 8   */
	Descripteur.fonction[NB_WFONC+5] = (EXAWORD (FAR *)())Run_Conf;	/*  16 */
	Descripteur.fonction[NB_WFONC+6] = (EXAWORD (FAR *)())Run_Co; 	/*  32 */
	Descripteur.fonction[NB_WFONC+7] = (EXAWORD (FAR *)())Run_Str;	/*  64 */
	Descripteur.fonction[NB_WFONC+8] = (EXAWORD (FAR *)())Run_Lin;	/* 128 */
	Descripteur.fonction[NB_WFONC+9] = (EXAWORD (FAR *)())Run_Col;	/* 256 */
	Descripteur.fonction[NB_WFONC+10] = (EXAWORD (FAR *)())0;		/* 512 */
	Descripteur.fonction[NB_WFONC+11] = (EXAWORD (FAR *)())0;		/* 1024 */
	Descripteur.fonction[NB_WFONC+12] = (EXAWORD (FAR *)())0;		/* 2048 */
	Descripteur.fonction[NB_WFONC+13] = (EXAWORD (FAR *)())0;		/* 4096 */
	Descripteur.fonction[NB_WFONC+14] = (EXAWORD (FAR *)())0;		/* 8192 */
	/*16384 */
	Descripteur.fonction[NB_WFONC+15] = (EXAWORD (FAR *)())connect_access_controller; 


#else

	Descripteur.fonction[0] = (EXAWORD (FAR *)())winit;
	Descripteur.fonction[1] = (EXAWORD (FAR *)())wcreat;
	Descripteur.fonction[2] = (EXAWORD (FAR *)())wsup;
	Descripteur.fonction[3] = (EXAWORD (FAR *)())wwrite;
	Descripteur.fonction[4] = (EXAWORD (FAR *)())wselect;
	Descripteur.fonction[5] = (EXAWORD (FAR *)())winv;
	Descripteur.fonction[6] = (EXAWORD (FAR *)())wvis;
	Descripteur.fonction[7] = (EXAWORD (FAR *)())wfgen;
	Descripteur.fonction[8] = (EXAWORD (FAR *)())watb;
	Descripteur.fonction[9] = (EXAWORD (FAR *)())wposcur;
	Descripteur.fonction[10] = (EXAWORD (FAR *)())wimpl;
	Descripteur.fonction[11] = (EXAWORD (FAR *)())wgel;
	Descripteur.fonction[12] = (EXAWORD (FAR *)())wend;
	Descripteur.fonction[13] = (EXAWORD (FAR *)())wsetatb;
	Descripteur.fonction[14] = (EXAWORD (FAR *)())sfinit;
	Descripteur.fonction[15] = (EXAWORD (FAR *)())lsacti;
	Descripteur.fonction[16] = (EXAWORD (FAR *)())lsmess;
	Descripteur.fonction[17] = (EXAWORD (FAR *)())lsclear;
	Descripteur.fonction[18] = (EXAWORD (FAR *)())lsdesac;
	Descripteur.fonction[19] = (EXAWORD (FAR *)())md_creat;
	Descripteur.fonction[20] = (EXAWORD (FAR *)())mo_creat;
	Descripteur.fonction[21] = (EXAWORD (FAR *)())mo_sep;
	Descripteur.fonction[22] = (EXAWORD (FAR *)())mo_modif;
	Descripteur.fonction[23] = (EXAWORD (FAR *)())mo_latt;
	Descripteur.fonction[24] = (EXAWORD (FAR *)())mo_matt;
	Descripteur.fonction[25] = (EXAWORD (FAR *)())mo_clear;
	Descripteur.fonction[26] = (EXAWORD (FAR *)())md_aff;
	Descripteur.fonction[27] = (EXAWORD (FAR *)())md_opt;
	Descripteur.fonction[28] = (EXAWORD (FAR *)())md_clear;
	Descripteur.fonction[29] = (EXAWORD (FAR *)())md_sup;
	Descripteur.fonction[30] = (EXAWORD (FAR *)())ld_creat;
	Descripteur.fonction[31] = (EXAWORD (FAR *)())lm_creat;
	Descripteur.fonction[32] = (EXAWORD (FAR *)())le_creat;
	Descripteur.fonction[33] = (EXAWORD (FAR *)())le_lect;
	Descripteur.fonction[34] = (EXAWORD (FAR *)())le_down;
	Descripteur.fonction[35] = (EXAWORD (FAR *)())le_up;
	Descripteur.fonction[36] = (EXAWORD (FAR *)())le_matt;
	Descripteur.fonction[37] = (EXAWORD (FAR *)())ld_close;
	Descripteur.fonction[38] = (EXAWORD (FAR *)())ld_aff;
	Descripteur.fonction[39] = (EXAWORD (FAR *)())ld_choix;
	Descripteur.fonction[40] = (EXAWORD (FAR *)())ld_clear;
	Descripteur.fonction[41] = (EXAWORD (FAR *)())ld_sup;
	Descripteur.fonction[42] = (EXAWORD (FAR *)())bv_spc;
	Descripteur.fonction[43] = (EXAWORD (FAR *)())bv_std;
	Descripteur.fonction[44] = (EXAWORD (FAR *)())sfend;
	Descripteur.fonction[45] = (EXAWORD (FAR *)())sftxt_mod;
	Descripteur.fonction[46] = (EXAWORD (FAR *)())sa_activ;
	Descripteur.fonction[47] = (EXAWORD (FAR *)())sa_aid;
	Descripteur.fonction[48] = (EXAWORD (FAR *)())sa_desac;
	Descripteur.fonction[49] = (EXAWORD (FAR *)())sa_aiddef;
	Descripteur.fonction[50] = (EXAWORD (FAR *)())wgetimpl;
/* 1.3 */

	Descripteur.fonction[51] = (EXAWORD (FAR *)())bd_creat;
	Descripteur.fonction[52] = (EXAWORD (FAR *)())bd_insert;
	Descripteur.fonction[53] = (EXAWORD (FAR *)())bd_use;
	Descripteur.fonction[54] = (EXAWORD (FAR *)())bd_close;
	Descripteur.fonction[55] = (EXAWORD (FAR *)())bd_sup;
	Descripteur.fonction[56] = (EXAWORD (FAR *)())bd_putdata;
	Descripteur.fonction[57] = (EXAWORD (FAR *)())bd_getdata;
	Descripteur.fonction[58] = (EXAWORD (FAR *)())wexit;
	Descripteur.fonction[59] = (EXAWORD (FAR *)())wrefresh;
	Descripteur.fonction[60] = (EXAWORD (FAR *)())md_way;
	Descripteur.fonction[61] = (EXAWORD (FAR *)())swcreat;
	Descripteur.fonction[62] = (EXAWORD (FAR *)())wcadre;
	Descripteur.fonction[63] = (EXAWORD (FAR *)())wtitre;
	Descripteur.fonction[64] = (EXAWORD (FAR *)())wmove;
	Descripteur.fonction[65] = (EXAWORD (FAR *)())le_delete;
	Descripteur.fonction[66] = (EXAWORD (FAR *)())le_insert;
	Descripteur.fonction[67] = (EXAWORD (FAR *)())sfset_tch_esc;
	Descripteur.fonction[68] = (EXAWORD (FAR *)())wfinfo;

/* 1.4 */	

	Descripteur.fonction[69] = (EXAWORD (FAR *)())get_style;
	Descripteur.fonction[70] = (EXAWORD (FAR *)())set_style;
	Descripteur.fonction[71] = (EXAWORD (FAR *)())wlangue;
	Descripteur.fonction[72] = (EXAWORD (FAR *)())asfvers;


	Descripteur.fonction[73] = (EXAWORD (FAR *)())set_mouse_position;
	Descripteur.fonction[74] = (EXAWORD (FAR *)())mouse_on;
	Descripteur.fonction[75] = (EXAWORD (FAR *)())mouse_off;
	Descripteur.fonction[76] = (EXAWORD (FAR *)())put_item_mouse_list;
	Descripteur.fonction[77] = (EXAWORD (FAR *)())del_item_mouse_list;
	Descripteur.fonction[78] = (EXAWORD (FAR *)())get_item_mouse_list;
	Descripteur.fonction[79] = (EXAWORD (FAR *)())wait_event;
	Descripteur.fonction[80] = (EXAWORD (FAR *)())flush_event;
	Descripteur.fonction[81] = (EXAWORD (FAR *)())get_event;
	Descripteur.fonction[82] = (EXAWORD (FAR *)())put_event;
	Descripteur.fonction[83] = (EXAWORD (FAR *)())add_scroll_bar;
	Descripteur.fonction[84] = (EXAWORD (FAR *)())del_scroll_bar;
	Descripteur.fonction[85] = (EXAWORD (FAR *)())update_scroll_bar;
	Descripteur.fonction[86] = (EXAWORD (FAR *)())get_scroll_bar_region;
	Descripteur.fonction[87] = (EXAWORD (FAR *)())read_event;
	Descripteur.fonction[88] = (EXAWORD (FAR *)())who_is_there;
	Descripteur.fonction[89] = (EXAWORD (FAR *)())rlecomp;
	Descripteur.fonction[90] = (EXAWORD (FAR *)())rledcomp;

	/* The ASFUNN/CICO connection functions	*/
	/* ------------------------------------ */
	Descripteur.fonction[NB_WFONC+1] = (EXAWORD (FAR *)())0;
	Descripteur.fonction[NB_WFONC+2] = (EXAWORD (FAR *)())0;
	Descripteur.fonction[NB_WFONC+3] = (EXAWORD (FAR *)())0;
	Descripteur.fonction[NB_WFONC+4] = (EXAWORD (FAR *)())0;
	Descripteur.fonction[NB_WFONC+5] = (EXAWORD (FAR *)())Run_Conf;	/*  16 */
	Descripteur.fonction[NB_WFONC+6] = (EXAWORD (FAR *)())Run_Co; 	/*  32 */
	Descripteur.fonction[NB_WFONC+7] = (EXAWORD (FAR *)())Run_Str;	/*  64 */
	Descripteur.fonction[NB_WFONC+8] = (EXAWORD (FAR *)())Run_Lin;	/* 128 */
	Descripteur.fonction[NB_WFONC+9] = (EXAWORD (FAR *)())Run_Col;	/* 256 */
	Descripteur.fonction[NB_WFONC+10] = (EXAWORD (FAR *)())0;
	Descripteur.fonction[NB_WFONC+11] = (EXAWORD (FAR *)())0;
	Descripteur.fonction[NB_WFONC+12] = (EXAWORD (FAR *)())0;
	Descripteur.fonction[NB_WFONC+13] = (EXAWORD (FAR *)())0;
	Descripteur.fonction[NB_WFONC+14] = (EXAWORD (FAR *)())0;
	/* 16384 */
	Descripteur.fonction[NB_WFONC+15]= (EXAWORD (FAR *)())connect_access_controller; 

#endif /* unix || M_XENIX || vms */

	rt_init->cico.signature = BDA_ASFUN;

#if PRL
	rt_init->cico.Relay_Co = (void far *)Run_Co;
	rt_init->cico.Relay_Info = (void far *)Run_Info;
	rt_init->cico.Relay_Mes = (void far *)Run_Str;
	rt_init->cico.capacite = 0x000F;	
	rt_init->cico.Relay_Lo = (EXAWORD far *)Run_Mi;
#else
	rt_init->cico.numero = 16+32+64+128+256+16384;
	rt_init->cico.fonction[CICO_CI]     = Descripteur.fonction[NB_WFONC+1]; 
 	rt_init->cico.fonction[CICO_TPCI]   = Descripteur.fonction[NB_WFONC+2];
  	rt_init->cico.fonction[CICO_PRFO]   = Descripteur.fonction[NB_WFONC+3];  	
	rt_init->cico.fonction[CICO_LCFO]   = Descripteur.fonction[NB_WFONC+4];  	
	rt_init->cico.fonction[CICO_CONF]   = Descripteur.fonction[NB_WFONC+5]; 	
	rt_init->cico.fonction[CICO_CO]     = Descripteur.fonction[NB_WFONC+6]; 	
	rt_init->cico.fonction[CICO_MES]    = Descripteur.fonction[NB_WFONC+7]; 	
	rt_init->cico.fonction[CICO_LIGNE]  = Descripteur.fonction[NB_WFONC+8]; 	
	rt_init->cico.fonction[CICO_COLONNE]= Descripteur.fonction[NB_WFONC+9]; 	
	rt_init->cico.fonction[CICO_START]  = Descripteur.fonction[NB_WFONC+10]; 	
	rt_init->cico.fonction[CICO_FLUSH]  = Descripteur.fonction[NB_WFONC+11]; 	
	rt_init->cico.fonction[CICO_LO]     = Descripteur.fonction[NB_WFONC+12]; 	
	rt_init->cico.fonction[CICO_MIMA]   = Descripteur.fonction[NB_WFONC+13];   
	rt_init->cico.fonction[CICO_EVENT]  = Descripteur.fonction[NB_WFONC+14];
	rt_init->cico.fonction[CICO_INIT]   = Descripteur.fonction[NB_WFONC+15];

#endif /* PRL */

	return((void FAR *)&Descripteur);
}


/* FinRelais - terminaison de la bibliotheque
 * ------------------------------------------
 *
 * appel:	static void FinRelais(void);
 *
 * retour:	rien
 *
 */
static void FAR FinRelais()
{
	sfend();
#if !PRL
/* IJM	finterm(0);	*/
#if unix
/*	PurgeLox();	 */
#endif /* unix */
#endif /* !PRL */
}


/* banniere - banniere de la bibliotheque
 * --------------------------------------
 *
 * appel:	static void banniere(void);
 *
 * retour:	rien
 *
 */
static void FAR Banniere()
{
	NouvelleLigne();
	AfficheChaine(ChercheMessage(1));
	AfficheChaine(version);
#if PRL3
	AfficheChaine("-P3");
#endif
#if PROV
	AfficheChaine(provisoire);
#endif
	NouvelleLigne();
	AfficheChaine(copyright);
	NouvelleLigne();
}


/* AfficheChaine - affichage d'une chaine sur l'ecran
 * --------------------------------------------------
 *
 * appel:	static void AfficheChaine(chaine);
 *		char chaine = chaine a afficher
 *
 * retour:	rien
 *
 */
static void AfficheChaine(chaine)
char *chaine;
{
#if MSDOS || PRL || dosext
	cputs(chaine);
#else
	fputs(chaine, stdout);
#endif
}


/* NouvellLigne - passage a la ligne suivante sur l'ecran
 * ------------------------------------------------------
 *
 * appel:	static void NouvelleLigne(void);
 *
 * retour:	rien
 *
 */
static void NouvelleLigne()
{
#if MSDOS || PRL || dosext
	cputs("\r\n");
#else
	putchar('\n');
#endif
}


/* ChercheMessage - recherche d'un message dans la table
 * -----------------------------------------------------
 *
 * appel:	static void ChercheMessage(numero);
 *		int numero = numero de message
 *
 * retour:	pointeur sur le message
 *
 */
static char *ChercheMessage(numero)
int numero;
{
	char *p;

	p = message[0];
	while (numero) {
		while (*p++);
		while (!*p++);
		numero--;
	}
	return (--p);
}


EXAWORD asfvers( BPTR chaine)
{
	if(rt_arg.c != 1)
	    return(RT_err_arg);
	if(rt_arg.t[0] != (TYPE_CHAINE | MODIFIABLE))
	    return(RT_err_typ);

	chaine[0] = VERS;
	chaine[1] = INDICE;
	chaine[2] = RELEASE;
	return(0);
}

/* fin de fichier */
/* -------------- */






































