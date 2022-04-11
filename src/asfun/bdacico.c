
/*
 *	-------------------------------------------------------------------
 *	PROJECT	:	ABAL for USE IT		or 	USE IT for ABAL	
 *	------------------------------------------------------------------- 
 *
 * 	FILE	:	BDACICO.C
 *
 *	DATE	:	04/10/2001	
 *
 *	BY	:	Iain James Marshall
 *
 *	WHY	:	This file has been created to normalise the CICO
 *			recurring nightmare code into something that most
 *			regular zombies will be able to handle.
 *			No offence meant, Zombie mode is active !
 *
 *	HOW	:	The ABAL tools all use the standard 
 *			CICO function interface calls for the
 *			activation of the corresponding console input
 *			output function.
 *			The idea is quite simple :
 *
 *				- the operational CICO function must be
 *				made available to the ABAL tool, and to
 *				any cooperating bits of code, dynamic
 *				libraries etc.
 *
 *				- The initiating tool will instance a
 *				CICO access controller and the usual
 *				standard CICO interface functions.
 *
 *				- These interface functions will simply
 *				activate the relevant relay in the CICO
 *				access controller.
 *
 *				- The redirection controller of a dynamic
 *				library will exchange its offered relays for
 *				those of the hosting tool.
 *
 *	WHAT	:	This file is to be used by Dynamic Libraries which
 *			require to receive redirected CICO/MIMO/GIGO
 *
 */

#ifndef	_bdacico_c
#define	_bdacico_c

#include "bda.h"
#include "bdacico.h"
#include "_ecran.h"

#define	max_ligne asfun_max_ligne
#define max_colonne asfun_max_colonne

/*	Global Variables that might interest MV		*/
/*	---------------------------------------		*/
EXAWORD	max_ligne=24;
EXAWORD	max_colonne=80;
EXAWORD	flag_couleur=1;


ecran_st BdaCicoScreen;

ecran_st * courant=&BdaCicoScreen;

#include "redcico.c"

/*	The CICO Interface functions 		*/
/*	----------------------------		*/
/*	These functions simply call through	*/
/*	on the corresponding relay		*/
/*	These relays will have been set by	*/
/*	the initialisation code, or the		*/
/*	redirection code.			*/

EXAWORD	x_getch() 
{ 
	return( (CicoAccessController.FunctionRelay[CICO_CI])() ); 
}

EXAWORD	x_kbhit() 
{ 
	return( (CicoAccessController.FunctionRelay[CICO_TPCI])() ); 
}

EXAWORD	x_putch(EXAWORD c) 
{
	return( (CicoAccessController.FunctionRelay[CICO_CO])(c) ); 
}

EXAWORD	lcfo(EXAWORD n, BYTE * buffer, EXAWORD blen) 
{ 
	return( (CicoAccessController.FunctionRelay[CICO_LCFO])(n,buffer,blen) ); 
} 

EXAWORD	prfo(EXAWORD n, BYTE * buffer, EXAWORD blen) 
{ 
	return( (CicoAccessController.FunctionRelay[CICO_PRFO])(n,buffer,blen) ); 
}

EXAWORD	conf(EXAWORD item)
{
	return( (CicoAccessController.FunctionRelay[CICO_CONF])(item) );
}
	
EXAWORD	x_cprintf(BYTE * mptr)
{
	return( (CicoAccessController.FunctionRelay[CICO_MES])(mptr) );
}

EXAWORD	x_bstart()
{
	return( (CicoAccessController.FunctionRelay[CICO_START])() ); 
}

EXAWORD	x_bflush()
{
	return( (CicoAccessController.FunctionRelay[CICO_FLUSH])() ); 
}

EXAWORD	x_event(EXAWORD n)
{
	return( (CicoAccessController.FunctionRelay[CICO_EVENT])(n) ); 
}

EXAWORD	x_col()
{
	return( (CicoAccessController.FunctionRelay[CICO_COLONNE])() ); 
}
EXAWORD	x_lin()
{
	return( (CicoAccessController.FunctionRelay[CICO_LIGNE])() ); 
}

EXAWORD	_lo(EXAWORD c)
{
	return( (CicoAccessController.FunctionRelay[CICO_LO])() ); 
}

EXAWORD	mima(EXAWORD c,EXAWORD mode)
{
	return( (CicoAccessController.FunctionRelay[CICO_MIMA])(c,mode) ); 
}

EXAWORD	x_bell()
{
	return( x_putch( 7 ) );
}

EXAWORD	x_pos(EXAWORD ligne, EXAWORD colonne)
{
	x_putch(ESC);
	x_putch('f');
	x_putch(colonne + 0x0020);
	x_putch(ligne + 0x0020);
	return(0);
}

EXAWORD 	x_backgr(EXAWORD couleur)
{
	couleur &= 0x0007;
	x_putch(ESC);
	x_putch('s');
	x_putch(couleur + '0');
	return(0);
}


EXAWORD 	x_foregr(EXAWORD couleur)
{
	if ((couleur >= 0) && (couleur <= 9))
		{
		x_putch(ESC);
		x_putch('r');
		x_putch(couleur + '0');
		}
	else if ((couleur >= 10) && (couleur <= 15))
		{
		x_putch(ESC);
		x_putch('r');
		x_putch(couleur - 10 + 'A');
		}
	return(0);
}


EXAWORD	x_atb( EXAWORD attribut )
{
	switch (attribut) {
	case 0: 		/* visualisation normale */
		attribut = 'a';
		break;
	case 1: 		/* attribut preferentiel */
		attribut = 'p';
		break;
	case 2: 		/* inversion video */
		attribut = 'b';
		break;
	case 3: 		/* clignotement */
		attribut = 'c';
		break;
	case 4: 		/* soulignement */
		attribut = 'd';
		break;
	case 5: 		/* sous-brillance */
		attribut = 'e';
		break;
	case 6: 		/* sur-brillance */
		attribut = 'h';
		break;
	case 7: 		/* lettres forcees majuscules */
		attribut = 'i';
		break;
	case 8: 		/* lettres forcees minuscules */
		attribut = 'j';
		break;
	case 9: 		/* hard copy */
		attribut = 'O';
		break;
	case 10:		/* caracteres penches */
		attribut = 'y';
		break;
	case 11:		/* double largeur */
		attribut = 'z';
		break;
	case 12:
		attribut = 'k';
		break;
	case 13:
		attribut = 'l';
		break;
	case 14:
		attribut = 'm';
		break;
	case 15:
		attribut = 'n';
		break;
	case 16:
		attribut = 'q';
		break;
	case 17:
		attribut = 'r';
		break;
	case 18:
		attribut = 's';
		break;
	case 19:		/* double hauteur */
		attribut = 't';
		break;
	case 20:
		attribut = 'Q';
		break;
	case 21:		/* effacement fin de ligne */
		attribut = 'K';
		break;
	case 22:		/* effacement fin de page */
		attribut = 'J';
		break;
	case 23:		/* insertion de ligne */
		attribut = 'L';
		break;
	case 24:		/* suppression de ligne */
		attribut = 'M';
		break;
	case 25:		/* extinction curseur */
		attribut = 'w';
		break;
	case 26:		/* allumage curseur */
		attribut = 'v';
		break;
	case 27:
		attribut = '*';
		break;
	case 28:
		attribut = '#';
		break;
	case 29:		/* caracteres compactes */
		attribut = 'x';
		break;
	case 30:		/* indice ou push ecran */
/* DLR:18/02/93 */
		attribut = '>';
		break;
	case 31:		/* exposant ou pop ecran */
/* DLR:18/02/93 */
		attribut = '<';
		break;
	default:
		return;
	}
	x_putch(ESC);
	x_putch(attribut);

	return(0);
}


/*	The ACCESS Controller Constructor	*/
/*	---------------------------------	*/
/*	This function will be called by the 	*/
/*	ixcico::x_redir() through the relay	*/
/*	CICO_INIT, with the descriptor and the	*/
/*	pointer to the screen controller	*/
/*						*/


void  *	connect_access_controller( BDA_INIT * iptr, ecran_st * eptr )
{
	int	i;
	void *	vptr;
	char *  nptr;
	
	if (!( iptr ))
		return;
	for (i=0; i < CICO_NOMBRE; i++ ) {
		vptr = iptr->cico.fonction[i];
		if ( i != CICO_INIT )
			(void) redirect_access_controller(i,vptr);
		}
	/* Do we really need this ? 	*/
	/* perhaps not courant = eptr; 	*/
	max_colonne = (conf(2)-1);
	max_ligne   = (conf(1)-1);
	flag_couleur= conf(14);
#ifndef	HX
	(void) wlangue(16);
	(void) wlangue(conf(5));
#endif
	return;
}



#endif	/* _bdacico_c */
	/* ---------- */



