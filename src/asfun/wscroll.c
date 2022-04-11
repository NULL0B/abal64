/********************************************************
* Services Fenetres - Gestion des scroll bars		*
*-------------------------------------------------------*
* Source : wscroll.c                  			*
*-------------------------------------------------------*
* Version : 1.1b                    			*
* Mise a jour le : 16/04/92 EDS (CERVIX)		*
*							*
*********************************************************
* Fonctions                         			*
*                                   			*
* - add_scroll_bar 	  Ajout d'une barre de scroll.	*
* - update_scroll_bar	  M.a.j afficahage scroll 	*
* - del_scroll_bar	  Suppression du scroll		*
* - get_scroll_bar_region Retourne la region d'un       *
*                         scroll cliquee		*
*							*
********************************************************/

#include "sfundef.h"

/* variables globales */

extern  BYTE     fen_ini;

extern	WITEM*   WLOG[MAXFUN];

/* les caractere de la barre de scroll */

#define C_SCROLL_UP	"-"
#define C_SCROLL_DOWN	"+"
#define C_SCROLL_LEFT	"-"
#define C_SCROLL_RIGHT	"+"

#define C_SCROLL_BAR_V	"±"		/*"±Û"*/
#define C_SCROLL_PAGE_V	" "		/*"°"*/
#define C_SCROLL_BAR_H	"Ü"		/*"ÛÜ""*/
#define C_SCROLL_PAGE_H	" "		/*"°"*/

/* les regions du scroll */

#define NO_SCROLL	0
#define SCROLL_UP	1
#define SCROLL_P_UP	2
#define SCROLL_P_DOWN	3
#define SCROLL_DOWN	4

/* ORIENTATION */

#define HORIZONTALE	1
#define VERTICALE	2


/* le marqueur de scroll bar */

#define SCROLLING_H	256
#define SCROLLING_V	512

void calc_scroll_region(WORD nb_it, WORD it_top, WORD nlig, WPTR bar, WPTR sup, WPTR inf);

/************************************************
*
* AJOUT D'UNE SCROLL_BAR SUR UNE FENETRE
*
*
* Input
*
*   nof   : nø fenetre
*   ori	  : orientation (VERTICALE/HORIZONTALE)
*
*
* Output
*
*   0 ou code erreur de descripteur
*
*************************************************/

TYPF add_scroll_bar(WORD nof, BYTE ori)
{

  WORD nlig, ncol, cur_lig, cur_col;
  WORD i;
  WORD sauv_atb;			/* sauvegarde attributs video	*/
  WORD sauv_fg;				/* sauvegarde RGB FG colour	*/
  WORD sauv_bg;				/* sauvegarde RGB BG colour	*/
  WDESC_PTR wd;
  WITEM	*wi;

  if(fen_ini == 0)   			/* test winit() */
     return(werr_ini);

  if((nof > MAXFUN) || (nof < 1))
    return(werr_inex);			/* fenetre inexistante */

  wi=WLOG[nof-1];
  if(wi->mere == (WITEM*)NULL)
    return(werr_inex);			/* fenetre inexistante */

  wd = wi->wdesc_ptr;

  nlig = wd->nb_lig;
  ncol = wd->nb_col;
  cur_lig = wd->cur_lig;
  cur_col = wd->cur_col;
  sauv_atb = wd->cur_atb;
  sauv_fg  = wd->cur_fg;
  sauv_bg  = wd->cur_bg;

  /* on verifie que la fenetre est assez grande */

  if(((ori == VERTICALE) && (nlig < 3)) ||
     ((ori == HORIZONTALE) && (ncol < 3)) ||
     (ori == 0) || (ori > 2))
    return(werr_desc);

  if(wd->control & ((ori == HORIZONTALE) ? SCROLLING_H : SCROLLING_V))
    return(OK);

  /* on teste si la fenetre possede deja une scroll, si oui on restaure l'affichage */
  if((wd->control & SCROLLING_H) || (wd->control & SCROLLING_V))
    {
     wposcur(nof, nlig, ncol);
     wwrite(nof, 1, (BPTR)" ");
    }

  wd->control += ((ori == HORIZONTALE) ? SCROLLING_H : SCROLLING_V);

  /* suivant le type, on dessine le scroll */

  wd->cur_atb = wd->cad_atb;
  wd->cur_fg  = wd->cad_fg;
  wd->cur_bg  = wd->cad_bg;

  switch(ori)
    {
     case VERTICALE:
       wposcur(nof, 1, ncol);
       wwrite(nof, 1, (BPTR)C_SCROLL_UP);
       for(i = 2; i < nlig-((wd->control & SCROLLING_H)?1:0); i++)
	 {
	  wposcur(nof, i, ncol);
	  wwrite(nof, 1, (BPTR)C_SCROLL_BAR_V);
	 }
       wposcur(nof, nlig-((wd->control & SCROLLING_H)?1:0), ncol);
       wwrite(nof, 1, (BPTR)C_SCROLL_DOWN);
       break;

     case HORIZONTALE:
       wposcur(nof, nlig, 1);
       wwrite(nof, 1, (BPTR)C_SCROLL_LEFT);
       for(i = 2; i < ncol-1; i++)
	 {
	  wposcur(nof, nlig, i);
	  wwrite(nof, 1, (BPTR)C_SCROLL_BAR_H);
	 }
       wposcur(nof, nlig, ncol-1);
       wwrite(nof, 1, (BPTR)C_SCROLL_RIGHT);
       break;
    }

  /* on restaure le cursor et les attributs */
  wposcur(nof, cur_lig, cur_col);
  wd->cur_atb = sauv_atb;
  wd->cur_fg  = sauv_fg;
  wd->cur_bg  = sauv_bg;

  return(OK);

}

/************************************************
*
* SUPPRESSION D'UNE SCROLL_BAR SUR UNE FENETRE
*
*
* Input
*
*   nof   : nø fenetre
*   ori	  : orientation (VERTICALE/HORIZONTALE)
*
*
* Output
*
*   0 ou code erreur de descripteur
*
*************************************************/

TYPF del_scroll_bar(WORD nof, BYTE ori)
{

  WORD nlig, ncol, cur_lig, cur_col;
  WORD i;
  WDESC_PTR wd;
  WITEM	*wi;

  if(fen_ini == 0)   			/* test winit() */
     return(werr_ini);

  if((nof > MAXFUN) || (nof < 1))
    return(werr_inex);			/* fenetre inexistante */

  wi=WLOG[nof-1];
  if(wi->mere == (WITEM*)NULL)
    return(werr_inex);			/* fenetre inexistante */

  wd = wi->wdesc_ptr;

  nlig = wd->nb_lig;
  ncol = wd->nb_col;
  cur_lig = wd->cur_lig;
  cur_col = wd->cur_col;


  if(!(wd->control & SCROLLING_H) && !(wd->control & SCROLLING_V))
    return(OK);

  wd->control -= ((ori == HORIZONTALE) ? SCROLLING_H : SCROLLING_V);


  /* on efface le scroll */

  switch(ori)
    {
     case VERTICALE:
       for(i = 1; i <= nlig-((wd->control & SCROLLING_H)?1:0); i++)
	 {
	  wposcur(nof, i, ncol);
	  wwrite(nof, 1, (BPTR)" ");
	 }
       break;

     case HORIZONTALE:
       for(i = 1; i <= ncol-((wd->control & SCROLLING_V)?1:0); i++)
	 {
	  wposcur(nof, nlig, i);
	  wwrite(nof, 1, (BPTR)" ");
	 }
       break;
    }

  /* on restaure le cursor */
  wposcur(nof, cur_lig, cur_col);

  return(OK);

}




/************************************************
*
* MISE A JOUR DE LA SCROLL_BAR SUR UNE FENETRE
*
*
* Input
*
*   nof   : nø fenetre
*   ori	  : orientation (VERTICALE/HORIZONTALE)
*   nb_it : nb d'item dans la fenetre
*   it_top: indice du premier item affiche
*
*
* Output
*
*   0 ou code erreur de descripteur
*
*************************************************/

TYPF update_scroll_bar(WORD nof, BYTE ori, WORD nb_it, WORD it_top)
{

  WORD nlig, ncol, cur_lig, cur_col;
  WORD i, sup, inf, bar;
  WORD sauv_atb;
  WORD sauv_fg;				/* sauvegarde RGB FG colour	*/
  WORD sauv_bg;				/* sauvegarde RGB BG colour	*/
  WDESC_PTR wd;
  WITEM	*wi;


  /* Fonctions */


  /* TRAITEMENT */
  /**************/


  if(fen_ini == 0)   			/* test winit() */
     return(werr_ini);

  if((nof > MAXFUN) || (nof < 1))
    return(werr_inex);			/* fenetre inexistante */

  wi=WLOG[nof-1];
  if(wi->mere == (WITEM*)NULL)
    return(werr_inex);			/* fenetre inexistante */

  wd = wi->wdesc_ptr;

  nlig = wd->nb_lig;
  ncol = wd->nb_col;
  cur_lig = wd->cur_lig;
  cur_col = wd->cur_col;
  sauv_atb = wd->cur_atb;
  sauv_fg  = wd->cur_fg;
  sauv_bg  = wd->cur_bg;

  if(((ori == HORIZONTALE) && !(wd->control & SCROLLING_H)) ||
     ((ori == VERTICALE) && !(wd->control & SCROLLING_V)))
    return(werr_desc);

  /* calcul des regions */
  calc_scroll_region(nb_it, it_top, ((ori == VERTICALE) ? nlig-((wd->control & SCROLLING_H)?1:0) : ncol-((wd->control & SCROLLING_V)?1:0)), (WPTR)&bar, (WPTR)&sup, (WPTR)&inf);

  /* on redessine le scroll */
  wd->cur_atb = wd->cad_atb;
  wd->cur_fg  = wd->cad_fg;
  wd->cur_bg  = wd->cad_bg;

  /* invisible souris */
  mouse_off();

  wposcur(nof, nlig, ncol);
  wwrite(nof, 1, (BPTR)" ");

  switch(ori)
    {
     case VERTICALE:
       wposcur(nof, 1, ncol);
       wwrite(nof, 1, (BPTR)C_SCROLL_UP);
       for(i = 2; i < sup+2; i++)
	 {
	  wposcur(nof, i, ncol);
	  wwrite(nof, 1, (BPTR)C_SCROLL_PAGE_V);
	 }
       for(i = sup+2; i < sup+2+bar; i++)
	 {
	  wposcur(nof, i, ncol);
	  wwrite(nof, 1, (BPTR)C_SCROLL_BAR_V);
	 }
       for(i = sup+2+bar; i < nlig-((wd->control & SCROLLING_H)?1:0); i++)
	 {
	  wposcur(nof, i, ncol);
	  wwrite(nof, 1, (BPTR)C_SCROLL_PAGE_V);
	 }
       wposcur(nof, nlig-((wd->control & SCROLLING_H)?1:0), ncol);
       wwrite(nof, 1, (BPTR)C_SCROLL_DOWN);
       break;

     case HORIZONTALE:
       wposcur(nof, nlig, 1);
       wwrite(nof, 1, (BPTR)C_SCROLL_LEFT);
       for(i = 2; i < sup+2; i++)
	 {
	  wposcur(nof, nlig, i);
	  wwrite(nof, 1, (BPTR)C_SCROLL_PAGE_H);
	 }
       for(i = sup+2; i < sup+2+bar; i++)
	 {
	  wposcur(nof, nlig, i);
	  wwrite(nof, 1, (BPTR)C_SCROLL_BAR_H);
	 }
       for(i = sup+2+bar; i < ncol-((wd->control & SCROLLING_V)?1:0); i++)
	 {
	  wposcur(nof, nlig, i);
	  wwrite(nof, 1, (BPTR)C_SCROLL_PAGE_H);
	 }
       wposcur(nof, nlig, ncol-((wd->control & SCROLLING_V)?1:0));
       wwrite(nof, 1, (BPTR)C_SCROLL_DOWN);
       break;
    }

  /* on restaure le cursor */
  wposcur(nof, cur_lig, cur_col);
  wd->cur_atb = sauv_atb;
  wd->cur_fg  = sauv_fg;
  wd->cur_bg  = sauv_bg;

  /* souris visible */
  mouse_on();

  return(OK);

}

/************************************************
*
* CACUL DE LA REGION D'UNE SCROLL BAR EN X, Y
*
*
* Input
*
*   nof   : nø fenetre
*   ori   : orientation (VERTICALE/HORIZONTALE)
*   nb_it : nb d'item dans la fenetre
*   it_top: indice du premier item affiche
*   lig   : ligne
*   col   : colonne
*
*
* Output
*
*   NO_SCROLL, SCROLL_UP, SCROLL_DOWN,
*   SCROLL_P_UP, SCROLL_P_DOWN
*
*************************************************/

TYPF get_scroll_bar_region(WORD nof, BYTE ori, WORD nb_it, WORD it_top, WORD lig, WORD col)
{

  WORD nlig, ncol;
  WORD i, sup, inf, bar;
  WDESC_PTR wd;
  WITEM	*wi;


  /* Fonctions */

  /* TRAITEMENT */
  /**************/


  if(fen_ini == 0)   			/* test winit() */
     return(werr_ini);

  if((nof > MAXFUN) || (nof < 1))
    return(werr_inex);			/* fenetre inexistante */

  wi=WLOG[nof-1];
  if(wi->mere == (WITEM*)NULL)
    return(werr_inex);			/* fenetre inexistante */

  wd = wi->wdesc_ptr;

  nlig = wd->nb_lig;
  ncol = wd->nb_col;

  /* test si inside window */
/*lllb*/
  if((lig == 0) || (col == 0) || (lig > nlig) || (col > ncol+1))
    return(NO_SCROLL);

  if(((ori == HORIZONTALE) && !(wd->control & SCROLLING_H)) ||
     ((ori == VERTICALE) && !(wd->control & SCROLLING_V)))
    return(NO_SCROLL);


  /* calcul des regions */
  calc_scroll_region(nb_it, it_top, ((ori == VERTICALE) ? nlig-((wd->control & SCROLLING_H)?1:0) : ncol-((wd->control & SCROLLING_V)?1:0)), (WPTR)&bar, (WPTR)&sup, (WPTR)&inf);

  switch(ori)
    {
     case VERTICALE:
/*llb
       if( col != ncol) *****/
	if ((col < ncol-1) || (col > ncol+1))
	 return(NO_SCROLL);
       /* test SCROLL_UP */
       if(lig == 1)
	 return(SCROLL_UP);

       /* test SCROLL_DOWN */
       if(lig == nlig-((wd->control & SCROLLING_H)?1:0))
	 return(SCROLL_DOWN);

       /* test SCROLL_P_UP */
       if((sup != 0) && (lig < sup+2))
	 return(SCROLL_P_UP);

       /* test SCROLL_P_DOWN */
       if((inf != 0) && (lig >= nlig-((wd->control & SCROLLING_H)?1:0)-inf))
	 return(SCROLL_P_DOWN);

     case HORIZONTALE:
       if(lig != nlig)
	 return(NO_SCROLL);
       /* test SCROLL_UP */
       if(col == 1)
	 return(SCROLL_UP);

       /* test SCROLL_DOWN */
       if(col == ncol-((wd->control & SCROLLING_V)?1:0))
	 return(SCROLL_DOWN);

       /* test SCROLL_P_UP */
       if((sup != 0) && (col < sup+2))
	 return(SCROLL_P_UP);

       /* test SCROLL_P_DOWN */
       if((inf != 0) && (col >= ncol-((wd->control & SCROLLING_V)?1:0)-inf))
	 return(SCROLL_P_DOWN);
    }

  return(NO_SCROLL);

}










/* CALCUL DES REGIONS DE LA SCROLL BAR 	*/
/* Fonction interne 			*/


void calc_scroll_region(WORD nb_it, WORD it_top, WORD nlig, WPTR bar, WPTR sup, WPTR inf)
{
  WORD nb, nb1, nb2;


  /* calcul des regions */
  if(nlig > 3)
    if(nb_it > nlig)
      {
       /* calcul taille de la barre */
       nb = nlig * (nlig-2);
       nb1 = nb/nb_it;
       nb2 = nb%nb_it;
       *bar = nb1 + (((nb2*2 >= nb_it) || (nb1 == 0)) ? 1 : 0);

       /* calcul taille sup */
       nb = ((((it_top>(nb_it-nlig+1)) ? (nb_it-nlig+1) : it_top)-1)*(nlig-2-*bar));
       nb1 = nb/(nb_it-nlig);
       nb2 = nb%(nb_it-nlig);
       *sup = nb1 + ((nb2*2 >= (nb_it-nlig)) ? 1 : 0);

       /* calcul taille inf */
       *inf = nlig-2-*bar-*sup;
      }
    else
      {
       *sup = 0;
       *bar = nlig-2;
       *inf = 0;
      }
  else
    {
     *sup = 0;
     *bar = 0;
     *inf = 0;
    }
}

