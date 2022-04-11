/************************************
* Fenetrage - Infos console         *
*-----------------------------------*
* Source : WINFO.C                  *
*-----------------------------------*
* Version : 1.1b                    *
* Creation    le : 18/07/1989  llb  *
* Mise a jour le : 15/06/1990   sb  *
*************************************
* Fonctions                         *
*                                   *
* - winfo      infos console        *
*              pour emulation co    *
*************************************/

#include "fundef.h"

/* variables globales */


extern  BYTE    fen_ini;
extern  WORD 	fimpl;		/* fenetre implicite */

extern	WITEM*   WLOG[MAXFUN];

extern	WORD	MAXCOL;
extern  WORD    MAXLIG;

/* fonctions externes */

extern WORD cons_cur();

/****************************************
* 	fonction WINFO()		*
*****************************************
WINFO est appelee par Run_Info (EMCO.ASM)

colonne courante = winfo(1)
ligne   courante = winfo(2)
nombre  colonnes = winfo(3)
nombre  lignes   = winfo(4)

Ces information concernent la fenetre implicite, ou l'ecran
s'il n'y a pas de fenetre implicite
*/ 


WORD winfo(arg)
int	arg;
{
 WDESC_PTR wd;
 WITEM	*wi;

 if (fen_ini == 0)   			/* test winit() */
    return(NULL);

 if ( fimpl == 0 )			/* pas de fenetre implicite */
  switch (arg)
   {
    case 1: return(cons_cur(1));	/* colonne courante ecran */
    case 2: return(cons_cur(2)); 	/* ligne courante ecran */
    case 3: return(MAXCOL);		/* nbre colonnes ecran */
    case 4: return(MAXLIG);		/* nbre lignes ecran */
    default: return(NULL);
   }	
 else
  {
    wi = WLOG[fimpl-1];
    wd = wi->wdesc_ptr;
    switch(arg)
     {
       case 1: return(wd->cur_col);
       case 2: return(wd->cur_lig);	
       case 3: return(wd->nb_col);
       case 4: return(wd->nb_lig);
       default: return(NULL);
     }
   }/* else */	
 } /* winfo */

/* fin de fichier */
