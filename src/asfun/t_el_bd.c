/***********************************************
* Service fenetre - Boite de dialogue     	*
*					  	*
* Traitement des elements de dialogue     	*
*   					  	*
*-----------------------------------------------*
* So6urce : T_EL_BD.C                     	*
*-----------------------------------------------*
* Version :                               	*
* Creation : 02/08/91   EDS/CERVIX        	*
*						*
* Modifications : 				*
*  - le 14/02/92 EDS				*
*    integration codage attributs fenetre dans  *
*    init_liste.				*
*  - le 16/04/92 EDS				*
*    integration saisie scroll			*
*  - le 24/04/92 EDS				*
*    prise en compte des touches d'echappement 	*
*  - le 18/05/92 EDS				*
*    traitement souris				*
*  - 01/07/93 llb				*
*    Radio et Check Interactif avec souris	*
*  - 02/09/93 llb				*
*    Corr RAZ Check 				*
*************************************************
* Fonctions 					*
* 						*
*	- init_message				*
*						*
*	- init_bouton				*
*	- trait_bouton				*
*						*
*	- init_r_bouton				*
*	- trait_r_bouton			*
*						*
*	- init_c_bouton				*
*	- trait_c_bouton			*
*						*
*	- init_liste				*
*	- trait_liste				*
*						*
*	- init_saisie				*
*	- trait_saisie				*
*                                         	*
*	- init_aide				*
*	- trait_aide				*
*                                         	*
************************************************/


/* includes specifiques boite de dialogue */

#include "sfbd.h"
#include "mouse.h"
#include <string.h>


/* Externes */

extern cof_tab co;
extern stf_desc stf[];
extern WORD MAXCOL;
extern BYTE a_mcd[9];		/* ptr sur clef d'aide			*/
extern BYTE *tabmes[MAXMES];
extern BYTE tc[MAX_TOUCHES];

extern	WITEM*	WLOG[MAXFUN];

extern EVENT_STR	event;


#define BOUTON_EVENTS		KEYBOARD+MOUSE_UP+MOUSE_DOWN+MOUSE_CLICK


SWORD calc_retour(DATA_ELEM_PTR dat, BYTE car_lu);
SWORD cherche_equi(EQUIV_PTR eq_ptr, BYTE code);
WORD get_bit(WORD mot_, BYTE rang);
WORD clear_bit(WORD mot_, BYTE rang);
WORD set_bit(WORD mot_, BYTE rang);
BYTE get_val_touche(BYTE touche);


/******************************* MESSAGE **********************************/


/*---------------------------------------------
   Fonction d'initialisation d'un message

    Entree :

	- f	 : nø logique de la fenetre
	- dat    : pointeur sur data element
	- w      : largeur du dialog
	- h      : hauteur du dialog
	- lib_m  : libelle du message


    Sortie :

	- code


    Traitement :


  ----------------------------------------------*/


WORD init_message(WORD f, DATA_ELEM_PTR dat, WORD w, WORD h, BYTE *lib_m)
{

  /* variables locales */

  WORD w_m, h_m;		/* longueur et hauteur du message 	*/


  /* TRAITEMENT */
  /**************/


  /* calcul de la taille du message et verification */

  w_m = (WORD)strlen(lib_m);
  h_m = 1;
  if((w_m + dat->x)-1 > w || (h_m + dat->y)-1 > h)
    return(Bd_err_pos);

  /* on memorise la description du message dans dat */

  dat->desc_elem = NULL;
  dat->w = w_m;
  dat->h = h_m;
  dat->etat = INACTIF;

  /* on affiche le message */

  wposcur(f, dat->y, dat->x);
  wwritec(f, (BPTR)lib_m);


  /* termine */

  return(No_err);

}/*init_message*/





/******************************* BOUTONS **********************************/





/*---------------------------------------------
   Fonction d'initialisation d'un bouton

    Entree :

	- f 	 : nø logique fenetre dialogue
	- dat    : pointeur sur data element
	- w      : largeur du dialog
	- h      : hauteur du dialog
	- lib_b  : libelle du bouton
	- code_b : code retour du bouton


    Sortie :

	- code


    Traitement :


  ----------------------------------------------*/


WORD init_bouton(WORD f, DATA_ELEM_PTR dat, WORD w, WORD h, BYTE *lib_b, WORD code_b)
{

  /* variables locales */

  BYTE nb;
  WORD w_b, h_b;		/* longueur et hauteur du bouton 	*/
  DESC_BOUTON_PTR bouton_ptr;	/* pointeur sur descripteur de bouton 	*/
  BYTE *lib;			/* ptr sur chaine			*/


  /* test si code retour bouton > 0, pour eviter les conflits ... */

  if(code_b <= 0)
    return(Bd_err_code_b);

  /* on initialise la structure du bouton */

  if((bouton_ptr = (DESC_BOUTON_PTR)f_allouer(sizeof(DESC_BOUTON))) == NULL)
    return(werr_mem);

  /* calcul de la taille du bouton et verification */

  w_b = (WORD)strlen(lib_b) + 2;
  h_b = 1;

  /* on recupere l'equiv caractere si existe et on modifie la taille du libelle */

  lib = NULL;
  for(nb = 0; nb < w_b - 2; nb++)
    if((lib_b[nb] == '~') && (lib_b[nb+2] == '~'))
      {
       if((lib = allouer(w_b)) == NULL)
	 return(werr_mem);
       strcpy(lib, lib_b);
       bouton_ptr->car_ex = lib_b[nb+1];
       bouton_ptr->car_ex_pos = nb;
       w_b -= 2;
       lib[nb] = 0;
       lib[nb+2] = 0;
       break;
      }

  if(nb == w_b -2)
    bouton_ptr->car_ex = 0;


  /* on verifie que le bouton entre dans le dialogue */

  if((w_b + dat->x)-1 > w || (h_b + dat->y)-1 > h)
    {
     f_libere(bouton_ptr);
     if(lib != NULL)
       libere(lib);
     return(Bd_err_pos);
    }


  /* sauvegarde du code retour du bouton */

  bouton_ptr->code = code_b;

  /* on memorise la description du bouton dans dat */

  dat->desc_elem = (BPTR)bouton_ptr;
  dat->w = w_b;
  dat->h = h_b;


  /* on affiche le libelle du bouton */

  wposcur(f, dat->y, (dat->x) + 1);

  if(bouton_ptr->car_ex == 0)
    wwritec(f, (BPTR)lib_b);
  else
    {
     wwritec(f, (BPTR)lib);
     wwritec(f, (BPTR)&lib[nb+1]);
     wwritec(f, (BPTR)&lib[nb+3]);
     libere(lib);
    }

  /* termine*/

  return(No_err);

}/*init_bouton*/






/*---------------------------------------------
   Fonction de traitement d'un bouton

    Entree :

	- f    : nø logique de la fenetre
	- flag : flag de traitement (INIT, TRAIT, ACTION, FIN, KILL)
	- dat  : pointeur sur data element


    Sortie :

	- code


    Traitement :


  ----------------------------------------------*/


SWORD trait_bouton(WORD f, BYTE flag, DATA_ELEM_PTR dat)
{

  /* variables locales */

  BYTE car_lu;			/* caractere saisi 			*/
  WORD x, y, w, h;		/* coordonnees et taille bouton		*/
  BPTR data_box_ptr;		/* ptr sur desc datat_box bouton	*/
  DESC_BOUTON_PTR bouton_ptr;	/* ptr sur description bouton		*/
  SWORD ret;			/* code retour fct			*/


  /* les fonctions */

  BYTE is_on_mouse();

  /* TRAITEMENT */
  /***************/


  x = dat->x; y = dat->y; w = dat->w; h = dat->h;

  data_box_ptr = dat->data_ptr;
  bouton_ptr = (DESC_BOUTON_PTR)dat->desc_elem;

  switch(flag)
    {
     case INIT:

       /* on positionne l'etat dans data_elem */

       dat->etat = data_box_ptr[I_etat_bouton];

       /* on dessine le bouton en fonction de son etat */
       /* par defaut, on le positionne INACTIF */

       if(dat->etat == ACTIF)
	 {
/*	  wsetatb(f, SURINT + VIDEO, BLANC_INT, BLANC, y ,x , h, w);*/
	  wsetatb(f, co.bout.atbc, co.bout.colc, co.bout.colf, y ,x , h, w);
	  if(bouton_ptr->car_ex != 0)
	    wsetatb(f, co.c_cle_bout.atbc, co.c_cle_bout.colc, co.bout.colf, y , bouton_ptr->car_ex_pos + x + 1, 1, 1);
	 }
       else
	 wsetatb(f, SOUSINT + VIDEO, GRIS, co.bout.colf, y ,x , h, w);

       return(No_err);


     case TRAIT:

       /* on positionne le curseur et on attend */

       wfgen(f, 10);
       wposcur(f, dat->y, dat->x);
       while(1)
	 {
	  car_lu = 0;
	  while(car_lu == 0)
	    {
	     if(event.event == NO_EVENT)
	       wait_eventc(BOUTON_EVENTS, (EVENT_PTR)&event);
	     if(event.event == KEYBOARD)
	       {
		 car_lu = get_val_touche(event.arg);
		 event.event = NO_EVENT;
	     }
	     switch(event.event)
	       {
		case MOUSE_DOWN:
		  if(is_on_mouse(dat, (EVENT_PTR)&event) == TRUE)
		    {
		     wfgen(f, 11);
		     /*mouse_off();*/
		     wsetatb(f, SOUSINT + VIDEO, GRIS, co.bout.colf, y ,x , h, w);
		     /*mouse_on();*/
		     event.event = NO_EVENT;
		    }
		  else
		    car_lu = T_TAB;
		  break;

		case MOUSE_UP:
		case MOUSE_IS_DOWN:

		  if(is_on_mouse(dat, (EVENT_PTR)&event) == TRUE)
		    {
		     car_lu = T_ENVOI;
		     event.event = NO_EVENT;
		    }
		  else
/*		    if(event.event == MOUSE_CLICK)
		      car_lu = T_TAB;
		    else
*/
		      event.event = NO_EVENT;

		  /*mouse_off();*/
		  wsetatb(f, co.bout.atbc, co.bout.colc, co.bout.colf, y ,x , h, w);
		  if(bouton_ptr->car_ex != 0)
		    wsetatb(f, co.c_cle_bout.atbc, co.c_cle_bout.colc, co.bout.colf, y , bouton_ptr->car_ex_pos + x + 1, 1, 1);
		  wfgen(f, 10);
		  wposcur(f, dat->y, dat->x);
		  /*mouse_on();*/
		  break;


		default:
		  event.event = NO_EVENT;
		  break;

	       }/* switch(event) */

	    }/* while(car_lu == 0) */

	  switch(car_lu)
	    {
	     case T_ENVOI:

	       wfgen(f, 11);
	       return(bouton_ptr->code);

	     case T_ESC:
	       wfgen(f, 11);
	       return(D_ESCAPE);

	     case T_AIDE:
	       wfgen(f, 11);
	       sa_aid((BPTR)a_mcd);
	       wposcur(f, dat->y, dat->x);
	       wfgen(f, 10);
	       break;

	     case T_TAB:
	     case SHIFT_TAB:
	     case F_GAUCHE:
	     case F_DROITE:
	     case F_HAUT:
	     case F_BAS:

	       if((ret = calc_retour(dat, car_lu)) != NO_RETOUR)
		 {
		  wfgen(f, 11);
		  return(ret);
		 }
	       break;

	     default:

	       /* on regarde si car_lu est une equivalence */

	       if((ret = cherche_equi(dat->equi_c, car_lu)) != NO_EQUIV)
		 {
		  wfgen(f, 11);
		  return(ret);
		 }
	       break;

	    }/*switch car_lu*/

	 }/*while*/


     case ACTION:
       return(bouton_ptr->code);


     case FIN:
       return(No_err);


     case KILL:
       f_libere(bouton_ptr);
       return(No_err);


     default:
       break;
    }


  /* termine */

  return(No_err);

}/*trait_bouton*/






/******************************* RADIO BOUTON *****************************/



/*---------------------------------------------
   Fonction d'initialisation d'un radio_bouton

    Entree :

	- f 	  : nø logique fenetre dialogue
	- style	  : style fenetre dialogue
	- dat     : pointeur sur data element
	- w       : largeur du dialog
	- h       : hauteur du dialog
	- nb_item : nb de boutons
	- tab_item: tableau des libelles des boutons


    Sortie :

	- code


    Traitement :


  ----------------------------------------------*/


WORD init_r_bouton(WORD f, stf_desc * style_f, DATA_ELEM_PTR dat, WORD w, WORD h, BYTE nb_item, BPTR tab_item[])
{

  /* variables locales */

  BYTE nb;
  WORD width, x, y;
  WORD w_b, h_b;		/* longueur et hauteur du radio_bouton 	*/
  DESC_R_BOUTON_PTR r_bouton_ptr;/* pointeur sur descripteur de r_bouton	*/
/*  stf_desc *style_f;*/		/* ptr sur descripteur de style		*/


  /* calcul de la taille du r_bouton et verification */

  /* on calcule le max de la longueur des radio_boutons */

  w_b = 0; width = 0;
  for(nb = 0; nb < nb_item; nb++)
    {
     for(width = 0; ((BPTR)tab_item[nb])[width] != 0; width++);
     if(width > w_b)
       w_b = width;
    }

  /* on verifie que le radio entre dans le dialogue */

  w_b += 3; /* on ajoute la longueur de "( )" */
  h_b = nb_item;
  if((w_b + dat->x)-1 > w || (h_b + dat->y)-1 > h)
    return(Bd_err_pos);

  /* on initialise la structure du radio_bouton */

  if((r_bouton_ptr = (DESC_R_BOUTON_PTR)f_allouer(sizeof(DESC_R_BOUTON))) == NULL)
    return(werr_mem);

  r_bouton_ptr->nb_elem = nb_item;

  /* on memorise la description du bouton dans dat */

  dat->desc_elem = (BPTR)r_bouton_ptr;
  dat->w = w_b;
  dat->h = h_b;

  /* on memorise les attributs video du dialogue */

  /*style_f = &(stf[style-1]);*/

  r_bouton_ptr->atb_v = style_f->f_fond.atbc;
  r_bouton_ptr->col_t = style_f->f_fond.colc;
  r_bouton_ptr->col_f = style_f->f_fond.colf;

  /* on dessine le radio_bouton */

  y = dat->y; x = dat->x;
  for(nb = 0; nb < nb_item; nb++)
    {
     wposcur(f, (y + nb), x);
     wwritec(f, (BPTR)"( )");
     wwritec(f, (BPTR)tab_item[nb]);
    }



  /* termine */

  return(No_err);

}/*init_r_bouton*/





/*---------------------------------------------
   Fonction de traitement d'un radio_bouton

    Entree :

	- f    : nø logique de la fenetre
	- flag : flag de traitement (INIT, TRAIT, FIN, KILL)
	- dat  : pointeur sur data element


    Sortie :

	- code


    Traitement :


  ----------------------------------------------*/


SWORD trait_r_bouton(WORD f, BYTE flag, DATA_ELEM_PTR dat, WPTR prov_exit)
{

  /* variables locales */

  BYTE nb;
  BYTE b_actif;			/* bouton actif				*/
  BYTE nb_elem;			/* le nb d'elements du radio_bouton	*/
  BYTE car_lu;			/* caractere saisi 			*/
  WORD x, y;			/* coordonnees du radio_bouton		*/
  BPTR data_box_ptr;		/* ptr sur desc datat_box radio_bouton	*/
  DESC_R_BOUTON_PTR r_bouton_ptr;/* ptr sur description radio_bouton	*/
  SWORD ret;			/* code retour fct			*/
  WORD val, sauv_val;		/* valeur et sauvegarde valeur radio	*/
  BPTR temp;


  /* les fonctions */

  BYTE is_on_mouse();


  /* TRAITEMENT */
  /***************/



  data_box_ptr = dat->data_ptr;
  x = dat->x; y = dat->y;
  r_bouton_ptr = (DESC_R_BOUTON_PTR)dat->desc_elem;
  nb_elem = r_bouton_ptr->nb_elem;

  temp = (BPTR)(&data_box_ptr[I_val_r_bouton]);
  val = (WORD)((*temp << 8) + *(temp + 1));

  switch(flag)
    {
     case INIT:

       /* on positionne l'etat dans data_elem */

       dat->etat = data_box_ptr[I_etat_r_bouton];

       /* on positionne le bouton actif en fonction de la valeur*/
       /* on arrete la balayage quand on trouve un bit a 1      */
       /* on force le bit 0 a 1 quand on ne trouve pas 		*/


 	/* effacer le bouton actif	*/
       for(nb = 0; nb < nb_elem; nb++) {
	       wposcur(f, y + nb, x + 1);
	       wwritec(f, (BPTR)" ");
	}


       for(nb = 0; nb < nb_elem; nb++)
	 if(get_bit(val, nb) == 1)
	   {
	    b_actif = nb;
	    break;
	   }
       if(nb == nb_elem)
	  b_actif = 0;

       val = set_bit(0, b_actif);

       temp = (BPTR)&val;
#ifdef IDIRECT
       data_box_ptr[I_val_r_bouton] = *(temp + 1);
       data_box_ptr[I_val_r_bouton + 1] = *temp;
#else
       data_box_ptr[I_val_r_bouton] = *temp;
       data_box_ptr[I_val_r_bouton + 1] = *(temp+1);
#endif /* IDIRECT */
       wposcur(f, y + b_actif, x + 1);
       wwritec(f, (BPTR)"*");

       /* on positionne les attributs video en fct de l'etat */
       /* INACTIF par defaut */

       if(dat->etat == ACTIF)
	  wsetatb(f, r_bouton_ptr->atb_v, r_bouton_ptr->col_t, r_bouton_ptr->col_f, y, x, dat->h, dat->w);
       else
	 wsetatb(f, co.el_bd_inact.atbc, co.el_bd_inact.colc, r_bouton_ptr->col_f, y, x, dat->h, dat->w);


       return(No_err);



     case TRAIT:

       /* on recherche le bouton positionne */

       for(nb = 0; nb < nb_elem; nb++)
	 if(get_bit(val, nb) == 1)
	   {
	    b_actif = nb;
	    break;
	   }
       if(nb == nb_elem)
	  b_actif = 0;

       /* on initialise val pour eviter les erreurs */

       val = set_bit(0, b_actif);
       sauv_val = val;

       /* on positionne le curseur et on attend */
       wfgen(f, 10);
       while(1)
	 {
	  wposcur(f, y + b_actif, x + 1);
	  car_lu = 0;
	  while(car_lu == 0)
	    {
	     if(event.event == NO_EVENT)
	       wait_eventc(BOUTON_EVENTS, (EVENT_PTR)&event);
	     if(event.event == KEYBOARD)
	       car_lu = get_val_touche(event.arg);

	     switch(event.event)
	       {
		case MOUSE_DOWN:
		  if(is_on_mouse(dat, (EVENT_PTR)&event) == TRUE)
		     event.event = NO_EVENT;
		  else
		    car_lu = T_TAB;
		  break;

		case MOUSE_CLICK:
		case MOUSE_UP:
		  if(is_on_mouse(dat, (EVENT_PTR)&event) == TRUE)
		    {
		     /* on recherche le bouton pointe puis  on le positionne */
		     /*mouse_off();*/
		     wwritec(f, (BPTR)" ");
		     val = clear_bit(val, b_actif);
		     b_actif = (event.plig+1) - dat->o_v - y;
		     wposcur(f, y + b_actif, x + 1);
		     wwritec(f, (BPTR)"*");
		     val = set_bit(val, b_actif);
		     wposcur(f, y + b_actif, x + 1);
		     event.event = NO_EVENT;
		     /*mouse_on();*/

		     if(   ((dat->mode_inter == ACTIF) && (val != sauv_val))
			 ||(dat->mode_inter == ACTIF2) )
		       {
		  	wfgen(f, 11);
                  	temp = (BPTR)&val;
		  	data_box_ptr[I_val_r_bouton] = *(temp + 1);
		  	data_box_ptr[I_val_r_bouton + 1] = *temp;
			*prov_exit = INTER_MOUSE;
		  	return(D_INTERACTION);
		     }
		     break;
		    }
		  else
		      event.event = NO_EVENT;
		  break;

		default:
		  event.event = NO_EVENT;
		  break;

	       }/* switch(event) */

	    }/* while(car_lu == 0) */

	  switch(car_lu)
	    {
	     case F_BAS:
	       wwritec(f, (BPTR)" ");
	       val = clear_bit(val, b_actif);
	       if(++b_actif >= nb_elem)
		 b_actif = 0;
	       wposcur(f, y + b_actif, x + 1);
	       wwritec(f, (BPTR)"*");
	       val = set_bit(val, b_actif);
	       break;

	     case F_HAUT:
	       wwritec(f, (BPTR)" ");
	       val = clear_bit(val, b_actif);
	       if(b_actif == 0)
		 b_actif = nb_elem -1;
	       else
		 b_actif--;
	       wposcur(f, y + b_actif, x + 1);
	       wwritec(f, (BPTR)"*");
	       val = set_bit(val, b_actif);
	       break;

	     case T_ESC:
	       wfgen(f, 11);
	       return(D_ESCAPE);

	     case T_AIDE:
	       wfgen(f, 11);
	       sa_aid((BPTR)a_mcd);
	       wfgen(f, 10);
	       break;

	     case T_TAB:
	     case SHIFT_TAB:
	     case T_ENVOI:

	       if((ret = calc_retour(dat, car_lu)) != NO_RETOUR)
		 {
		  /* sortie traitement : sauvegarde valeur */

		  temp = (BPTR)&val;
#ifdef IDIRECT
		  data_box_ptr[I_val_r_bouton] = *(temp + 1);
		  data_box_ptr[I_val_r_bouton + 1] = *temp;
#else
		  data_box_ptr[I_val_r_bouton] = *temp;
		  data_box_ptr[I_val_r_bouton + 1] = *(temp+1);
#endif /* IDIRECT

		  /* calcul retour */

		  wfgen(f, 11);
		  if(   ((dat->mode_inter == ACTIF) && (val != sauv_val))
		      ||(dat->mode_inter == ACTIF2) )
		    {
		     switch(car_lu) {
			case T_TAB:
				*prov_exit = INTER_NEXT;
				break;
			case SHIFT_TAB:
				*prov_exit = INTER_PREV;
				break;
			case T_ENVOI:
				*prov_exit = INTER_VALID;
				break;
		     }
		     return(D_INTERACTION);
		    }
		  return(ret);
		 }
	       break;

	     default:

	       /* on regarde si car_lu est une equivalence:
		  - si oui, on sauvegarde la valeur
		  - si non, on ignore l'entree			*/

	       if((ret = cherche_equi(dat->equi_c, car_lu)) != NO_EQUIV)
		 {

                  temp = (BPTR)&val;
#ifdef IDIRECT
		  data_box_ptr[I_val_r_bouton] = *(temp + 1);
		  data_box_ptr[I_val_r_bouton + 1] = *temp;
#else
		  data_box_ptr[I_val_r_bouton] = *temp;
		  data_box_ptr[I_val_r_bouton + 1] = *(temp+1);
#endif /* IDIRECT */
		  return(ret);
		 }

	       break;

	    }/*SWITCH*/
	 }


     case FIN:

       return(No_err);


     case KILL:

       f_libere(r_bouton_ptr);
       return(No_err);


     default:
       break;
    }


  /* termine */

  return(No_err);

}/*trait_r_bouton*/





/******************************* CHECK BOUTON *****************************/




#define TYPE_C_B_1	1		/* check_bouton de type [x]	*/
#define TYPE_C_B_2	2		/* chexk_bouton de type OUI/NON	*/




/*---------------------------------------------
   Fonction d'initialisation d'un check_bouton

    Entree :

	- f 	  : nø logique fenetre dialogue
	- dat     : pointeur sur data element
	- w       : largeur du dialog
	- h       : hauteur du dialog
	- tab_item: tableau des libelles des boutons
	- nb_item : nb de boutons
	- style   : style du check_bouton


    Sortie :

	- code


    Traitement :


  ----------------------------------------------*/


WORD init_c_bouton(WORD f, stf_desc * style_f, DATA_ELEM_PTR dat, WORD w, WORD h, BYTE type, BYTE nb_item, BPTR tab_item[])
{

  /* variables locales */

  BYTE nb;
  WORD width, width1, x, y;
  WORD w_b, h_b;			/* longueur et hauteur du check_bouton 	*/
  DESC_C_BOUTON_PTR c_bouton_ptr;	/* pointeur sur descripteur de c_bouton	*/
/*  stf_desc *style_f; */			/* ptr sur descripteur de style		*/
  BYTE *lib;



  /* on initialise la structure du check_bouton */

  if((c_bouton_ptr = (DESC_C_BOUTON_PTR)f_allouer(sizeof(DESC_C_BOUTON))) == NULL)
    return(werr_mem);

  /* calcul de la taille du c_bouton et verification */

  /* on calcule le max de la longueur des check_boutons */

  w_b = 0; width = 0;
  for(nb = 0; nb < nb_item; nb++)
    {
     for(width = 0; ((BPTR)tab_item[nb])[width] != 0; width++);
     if(width > w_b)
       w_b = width;
    }

  /* on verifie que le check entre dans le dialogue */

  /* on ajoute la longueur de "[ ]" ou OUI/NON */

  if(type == TYPE_C_B_1) {
     	w_b += 3;
     	c_bouton_ptr->pos_w = dat->x + 1;
    	}
  else	{
      	lib = tabmes[MES_O_CB];
     	for(width = 0; lib[width] != 0; width++);
     	lib = tabmes[MES_N_CB];
     	for(width1 = 0; lib[width1] != 0; width1++);
     	c_bouton_ptr->pos_w = dat->x + w_b;
     	w_b += max(width, width1);
       	}

  h_b = nb_item;
  if((w_b + dat->x)-1 > w || (h_b + dat->y)-1 > h)
    {
     f_libere(c_bouton_ptr);
     return(Bd_err_pos);
    }

  c_bouton_ptr->nb_elem = nb_item;
  c_bouton_ptr->type = type;

  /* on memorise la description du bouton dans dat */

  dat->desc_elem = (BPTR)c_bouton_ptr;
  dat->w = w_b;
  dat->h = h_b;

  /* on memorise les attributs video du dialogue */

/*  style_f = &(stf[style-1]);*/

  c_bouton_ptr->atb_v = style_f->f_fond.atbc;
  c_bouton_ptr->col_t = style_f->f_fond.colc;
  c_bouton_ptr->col_f = style_f->f_fond.colf;

  /* on dessine le check_bouton suivant son type */

  y = dat->y; x = dat->x;

  switch((WORD)type)
    {
     case TYPE_C_B_1:
      for(nb = 0; nb < nb_item; nb++)
	{
	 wposcur(f, y + nb, x);
	 wwritec(f, (BPTR)"[ ]");
	 wwritec(f, (BPTR)tab_item[nb]);
	}
      break;

     case TYPE_C_B_2:
       for(nb = 0; nb < nb_item; nb++)
	 {
	  wposcur(f, y + nb, x);
	  wwritec(f, (BPTR)tab_item[nb]);
	 }
     break;

     default:
     	f_libere(c_bouton_ptr);
       	return(Bd_err_type_c_b);

    }/*SWITCH*/

  /* termine */

  return(No_err);

}/*init_c_bouton*/





/*---------------------------------------------
   Fonction de traitement d'un check_bouton

    Entree :

	- f    : nø logique de la fenetre
	- flag : flag de traitement (INIT, TRAIT, FIN, KILL)
	- dat  : pointeur sur data element


    Sortie :

	- code


    Traitement :


  ----------------------------------------------*/


SWORD trait_c_bouton(WORD f, BYTE flag, DATA_ELEM_PTR dat, WPTR prov_exit)
{

  /* variables locales */

  BYTE nb;
  BYTE b_actif;			/* bouton actif				*/
  BYTE type;			/* type check_bouton			*/
  BYTE nb_elem;			/* le nb d'elements du check_bouton	*/
  BYTE car_lu;			/* caractere saisi 			*/
  WORD x, y;			/* coordonnees du check_bouton		*/
  WORD pos_cur;			/* position en x du curseur f(type)	*/
  BPTR data_box_ptr;		/* ptr sur desc datat_box check_bouton	*/
  DESC_C_BOUTON_PTR c_bouton_ptr;/* ptr sur description check_bouton	*/
  SWORD ret;			/* code retour fct			*/
  WORD val, sauv_val;		/* valeur est sauvegarde valeur check	*/
  BPTR temp;
  WORD interac;			/* flag pour sortie Interaction */

  /* les fonctions */

  BYTE is_on_mouse();

  /* TRAITEMENT */
  /***************/

  data_box_ptr = dat->data_ptr;
  c_bouton_ptr = (DESC_C_BOUTON_PTR)dat->desc_elem;

  x = dat->x; y = dat->y;
  type = c_bouton_ptr->type;
  pos_cur = c_bouton_ptr->pos_w;

  nb_elem = c_bouton_ptr->nb_elem;

  temp = (BPTR)(&data_box_ptr[I_val_r_bouton]);
  val = (WORD)((*temp << 8) + *(temp + 1));
  sauv_val = val;


  switch(flag)
    {
     case INIT:

       /* on positionne l'etat dans data_elem */

       dat->etat = data_box_ptr[I_etat_c_bouton];

       /* on positionne les boutons en fonction de la valeur */

       val = 0;
       for(nb = 0; nb < nb_elem; nb++)
	   switch(type)
	     {
	      case TYPE_C_B_1:
		wposcur(f, y + nb, pos_cur);
		if(get_bit(sauv_val, nb) == 1)
		  {
		   val = set_bit(val, nb);
		   wwritec(f, (BPTR)"x");
		 }
		 else {
		   val = clear_bit(val, nb);
		   wwritec(f, (BPTR)" ");
		 }
		break;

	      case TYPE_C_B_2:
		wposcur(f, y + nb, pos_cur);
		if(get_bit(sauv_val, nb) == 1)
		  {
		   val = set_bit(val, nb);
		   wwritec(f, (BPTR)tabmes[MES_O_CB]);
		  }
		else {
		   val = clear_bit(val, nb);
		   wwritec(f, (BPTR)tabmes[MES_N_CB]);
		}
		break;
	     }/*switch*/
       /* on initialise la valeur, en ignorant l'etat des bits non concernes */

       temp = (BPTR)&val;

#ifdef IDIRECT
       data_box_ptr[I_val_c_bouton] = *(temp + 1);
       data_box_ptr[I_val_c_bouton + 1] = *temp;
#else
       data_box_ptr[I_val_c_bouton] = *temp;
       data_box_ptr[I_val_c_bouton + 1] = *(temp+1);
#endif /* IDIRECT */

       /* on positionne les attributs video en fct de l'etat */
       /* INACTIF par defaut */

       if(dat->etat == ACTIF)
	 wsetatb(f, c_bouton_ptr->atb_v, c_bouton_ptr->col_t, c_bouton_ptr->col_f, y, x, dat->h, dat->w);
       else
	 wsetatb(f, co.el_bd_inact.atbc, co.el_bd_inact.colc, c_bouton_ptr->col_f, y, x, dat->h, dat->w);


       return(No_err);



     case TRAIT:

       interac = FALSE;
       
       /* on positionne le curseur sur le premier element et on attend */

       b_actif = 0;
       wfgen(f, 10);
       while(1)
	 {
	  wposcur(f, y + b_actif, pos_cur);
	  car_lu = 0;
	  while(car_lu == 0)
	    {
	     if(event.event == NO_EVENT)
	       wait_eventc(BOUTON_EVENTS, (EVENT_PTR)&event);
	     if(event.event == KEYBOARD)
	       car_lu = get_val_touche(event.arg);

	     switch(event.event)
	       {
		case MOUSE_DOWN:
		  if(is_on_mouse(dat, (EVENT_PTR)&event) == TRUE)
		     event.event = NO_EVENT;
		  else
		    car_lu = T_TAB;
		  break;

		case MOUSE_UP:

		  if(is_on_mouse(dat, (EVENT_PTR)&event) == TRUE)
		    {
		     /* on recherche le bouton pointe */
		     b_actif = (event.plig+1) - dat->o_v - y;
		     wposcur(f, y + b_actif, pos_cur);
		     car_lu = SPACE;
		     event.event = NO_EVENT;

		     /* calcul de la sortie */
		     if(   ((dat->mode_inter == ACTIF)) /*&& (val != sauv_val))*/
			 ||(dat->mode_inter == ACTIF2))
		       {
		  	wfgen(f, 11);
			interac = 1;
		      }
		     break;
		    }
		  else
		      event.event = NO_EVENT;

		  break;

		default:
		  event.event = NO_EVENT;
		  break;

	       }/* switch(event) */

	    }/* while(car_lu == 0) */

	  switch(car_lu)
	    {
	     case F_BAS:
	       if(++b_actif >= nb_elem)
		 b_actif = 0;
	       break;

	     case F_HAUT:
	       if(b_actif == 0)
		 b_actif = nb_elem - 1;
	       else
		 b_actif--;
	       break;

	     case T_ESC:
	       wfgen(f, 11);
	       return(D_ESCAPE);

	     case T_AIDE:
	       wfgen(f, 11);
	       sa_aid((BPTR)a_mcd);
	       wfgen(f, 10);
	       break;

	     case SPACE:
	       switch(type)
		 {
		  case TYPE_C_B_1:
		    /*mouse_off();*/
		    if(get_bit(val, b_actif) == 1)
		      {
		       val = clear_bit(val, b_actif);
		       wwritec(f, (BPTR)" ");
		      }
		    else
		      {
		       val = set_bit(val, b_actif);
		       wwritec(f, (BPTR)"x");
		      }
		    /*mouse_on();*/
		    break;

		  case TYPE_C_B_2:
		    /*mouse_off();*/
		    if(get_bit(val, b_actif) == 1)
		      {
		       val = clear_bit(val, b_actif);
		       for(nb = pos_cur; nb < (x + dat->w); nb++)
			 wwritec(f, (BPTR)" ");
		       wposcur(f, y + b_actif, pos_cur);
		       wwritec(f, (BPTR)tabmes[MES_N_CB]);
		      }
		    else
		      {
		       val = set_bit(val, b_actif);
		       for(nb = pos_cur; nb < (x + dat->w); nb++)
			 wwritec(f, (BPTR)" ");
		       wposcur(f, y + b_actif, pos_cur);
		       wwritec(f, (BPTR)tabmes[MES_O_CB]);
		      }
		    /*mouse_on();*/
		    break;
		 }/*type*/
/*llb02*/
		if (interac!=0)
		   {
		  	temp = (BPTR)&val;
		  	data_box_ptr[I_val_c_bouton] = *(temp + 1);
		  	data_box_ptr[I_val_c_bouton + 1] = *temp;
			*prov_exit = INTER_MOUSE;
		  	return(D_INTERACTION);
		   }
	       break;


	     case T_TAB:
	     case SHIFT_TAB:
	     case T_ENVOI:

	       if((ret = calc_retour(dat, car_lu)) != NO_RETOUR)
		 {
		  /* sortie traitement : sauvegarde valeur */

		  temp = (BPTR)&val;
		  data_box_ptr[I_val_c_bouton] = *(temp + 1);
		  data_box_ptr[I_val_c_bouton + 1] = *temp;

		  /* calcul de la sortie */
		  wfgen(f, 11);
		  if(   ((dat->mode_inter == ACTIF) && (val != sauv_val))
		      ||(dat->mode_inter == ACTIF2))
/*llb1609*/
		   {
		     switch(car_lu) {
			case T_TAB:
				*prov_exit = INTER_NEXT;
				break;
			case SHIFT_TAB:
				*prov_exit = INTER_PREV;
				break;
			case T_ENVOI:
				*prov_exit = INTER_VALID;
				break;
		     }
		    return(D_INTERACTION);
		  }
		  return(ret);
		 }
	       break;

	     default:

	       /* on regarde si car_lu est une equivalence:
		  - si oui, on sauvegarde la valeur
		  - si non, on ignore l'entree			*/

	       if((ret = cherche_equi(dat->equi_c, car_lu)) != NO_EQUIV)
		 {
                  temp = (BPTR)&val;
		  data_box_ptr[I_val_c_bouton] = *(temp + 1);
		  data_box_ptr[I_val_c_bouton + 1] = *temp;
		  return(ret);
		 }

	       break;

	    }/*SWITCH*/

	 }/*WHILE*/


     case FIN:

       return(No_err);

     case KILL:

       f_libere(c_bouton_ptr);
       return(No_err);


     default:
       break;

    }/*SWITCH*/


  /* termine */

  return(No_err);

}/*trait_c_bouton*/






/******************************* LISTE ************************************/


#define LISTE_FERMEE	128
#define BD_LS		0
#define LISTE_S_OK	NO_EFF + SOR_SI_TAB
#define BD_LM		1
#define LISTE_M_OK 	NO_EFF + SOR_SI_TAB + NO_BV

/* retours de la fonction ld_choixc */

#define VALID		1	/* sortie sur T_ENVOI */


/*---------------------------------------------
   Fonction d'initialisation d'une liste

    Entree :

	- f 	  : nø logique fenetre dialogue
	- dat     : pointeur sur data element
	- x	  : pcol dialog
	- y	  : plig dialog
	- w       : largeur du dialog
	- h       : hauteur du dialog
	- size	  : retour taille valeur element
	- nl	  : nø liste

    Sortie :

	- code


    Traitement :


  ----------------------------------------------*/


WORD init_liste(WORD f, DATA_ELEM_PTR dat, WORD x, WORD y, WORD w, WORD h, WORD *size, WORD nl)
{

  /* variables locales */

  WORD w_l, h_l;		/* longueur et hauteur de la liste     	*/
  DESC_LISTE_PTR liste_ptr;	/* pointeur sur descripteur de liste   	*/
  LD_INFO_PTR info_ptr;		/* ptr sur info liste			*/
  WORD cad;			/* indicateur de cadre de la liste	*/
  WORD ret;

  /* fonctions */

  TYPF list_info();


  /* TRAITEMENT */
  /**************/



  /* on initialise la structure de la liste */

  if((liste_ptr = (DESC_LISTE_PTR)f_allouer(sizeof(DESC_LISTE))) == NULL)
    return(werr_mem);


  /* on recupere les infos sur la liste */

  info_ptr = (LD_INFO_PTR)&(liste_ptr->info_l);
  if((ret = list_info((BYTE)nl, info_ptr)) != No_err)
    {
     f_libere(liste_ptr);
     return(Bd_err_l_open);
    }

  /* on verifie que la liste est conforme */
  info_ptr->ld_control &= ~TCH_ESC;
  info_ptr->ld_control &= ~6;			/* scroll bars */

/*llb120794  if(((info_ptr->ld_type & LISTE_FERMEE) != LISTE_FERMEE) ||*/

  if(((info_ptr->ld_type == LISTE_FERMEE + BD_LS) &&
      ((info_ptr->ld_control != LISTE_S_OK) && (info_ptr->ld_control != LISTE_M_OK))) ||
     ((info_ptr->ld_type == LISTE_FERMEE + BD_LM) && (info_ptr->ld_control != LISTE_M_OK)))

    return(Bd_err_l_open);

  /* on verifie que la liste entre dans le dialogue */

  w_l = info_ptr->ld_ncol;
  h_l = info_ptr->ld_nlig;
  if((w_l + dat->x)-1 > w || (h_l + dat->y)-1 > h)
    return(Bd_err_pos);


  /* on sauvegarde la position de la liste et son numero */
  cad = (info_ptr->ld_cad == 0) ? 0 : 1;
  liste_ptr->old_x = info_ptr->ld_pcol+cad;
  liste_ptr->old_y = info_ptr->ld_plig+cad;
  liste_ptr->nol = nl;

  liste_ptr->fl_aff = FALSE;

  /* on modifie la position de la liste */

  cad = (info_ptr->ld_cad == 0) ? 1 : 0;
  if((ret = wmove(info_ptr->ld_fun, dat->y + y - cad, dat->x + x - cad)) != No_err)
    return(ret);

  /* et on la rend invisible (ce qui normalement est deja fait ...) */

  winv(info_ptr->ld_fun);

  /* on memorise la description de la liste dans dat */

  dat->desc_elem = (BPTR)liste_ptr;
  dat->w = w_l;
  dat->h = h_l;



  /* on memorise la taille de la valeur d'un element */

  *size = info_ptr->ld_val;



  /* termine */

  return(No_err);

}/*init_liste*/








/*---------------------------------------------
   Fonction de traitement d'une liste

    Entree :

	- f    : nø logique de la fenetre
	- flag : flag de traitement (INIT, TRAIT, FIN, KILL)
	- dat  : pointeur sur data element


    Sortie :

	- code


    Traitement :


  ----------------------------------------------*/


SWORD trait_liste(WORD f, BYTE flag, DATA_ELEM_PTR dat, WPTR prov_exit)
{

  /* variables locales */

  WORD nof;			/* nø fenetre associe a la liste	*/
  WORD init_e, selec_e, sel_s;	/* premier element et elem selectionne	*/
  BYTE exit, ex;		/* mode de sortie de fct choix		*/
  BPTR data_box_ptr;		/* ptr sur desc datat_box liste		*/
  DESC_LISTE_PTR liste_ptr;	/* ptr sur description liste		*/
  LD_INFO_PTR info_ptr;		/* ptr sur info liste			*/
  SWORD ret;			/* code retour fct			*/
  BPTR temp;
  WORD nb;


  /* les fonctions */

  TYPF ld_afc();


  /* TRAITEMENT */
  /***************/

  data_box_ptr = dat->data_ptr;
  liste_ptr = (DESC_LISTE_PTR)dat->desc_elem;
  info_ptr = &liste_ptr->info_l;

  nof = info_ptr->ld_fun;
  temp = (BPTR)(&data_box_ptr[I_el_init]);
  init_e = (WORD)((*temp << 8) + *(temp + 1));
  temp = (BPTR)(&data_box_ptr[I_el_selec]);
  selec_e = (WORD)((*temp << 8) + *(temp + 1));
  sel_s = selec_e;

  switch(flag)
    {
     case INIT:

       /* on positionne l'etat dans data_elem */

       dat->etat = data_box_ptr[I_etat_liste];


       /* on affiche la liste */

	  if((ret = ld_afc(liste_ptr->nol, init_e, selec_e, 2)) != No_err)
	    return(ret);

	  wselect(nof);
	  if(dat->etat != ACTIF)
	    wsetatb(nof, co.el_bd_inact.atbc, co.el_bd_inact.colc, (BYTE)(info_ptr->ld_fatb>>4), 1, 2, dat->h - (2 * info_ptr->ld_cad), dat->w - (2 * info_ptr->ld_cad) - 1);

       return(No_err);



     case TRAIT:
       while(TRUE)
	 {
	  if((ret = ld_choixc((BYTE)liste_ptr->nol, &init_e, &selec_e, (BPTR)&exit, &data_box_ptr[I_val_liste], &ex)) != No_err)
	    return(ret);

	  temp = (BPTR)&init_e;
#ifdef IDIRECT
	  data_box_ptr[I_el_init] = *(temp + 1);
	  data_box_ptr[I_el_init + 1] = *temp;
	  temp = (BPTR)&selec_e;
	  data_box_ptr[I_el_selec] = *(temp + 1);
	  data_box_ptr[I_el_selec + 1] = *temp;
#else
	  data_box_ptr[I_el_init] = *temp;
	  data_box_ptr[I_el_init + 1] = *(temp+1);
	  temp = (BPTR)&selec_e;
	  data_box_ptr[I_el_selec] = *temp;
	  data_box_ptr[I_el_selec + 1] = *(temp+1);
#endif /* IDIRECT */

	  switch(exit)
	    {
	     case 2:
	       return(D_ESCAPE);

	     case 4:					/* TAB */
	     case 1:					/* RC */

		if (exit==1)
		   *prov_exit = INTER_VALID;
		else
		   if ( ex== tc[SHIFT_TAB])
			   *prov_exit = INTER_PREV;
		   else
			   *prov_exit = INTER_NEXT;

/*llb 03.09.93 if ( ((dat->mode_inter == ACTIF)||(dat->mode_inter == ACTIF2))*/
	       if   ((dat->mode_inter == ACTIF)
		    && (selec_e != sel_s))
		   return(D_INTERACTION);

/*	       if ( (dat->mode_inter == ACTIF2)&&(exit == 1) )*/
	       if (dat->mode_inter == ACTIF2)
		 return(D_INTERACTION);

	       if ( ex == tc[SHIFT_TAB-1])
		    return(D_PRECEDENT);
	       return(D_SUIVANT);

	     case 5:
	       /* on teste la frappe d'une touche d'echappement */
	       if((dat->mode_inter == ACTIF) && ((nb = sffind_tch(ex)) != 0))
		 return(D_TCH_ESC - nb);
	       else
		 break;

	     case 3:
	       /* fin liste atteinte */
	       if ( ex == tc[F_BAS-1])
		  *prov_exit = INTER_CURDOWN;
	       else
		  *prov_exit = INTER_PGDOWN;
	       return(D_INTERACTION);


	     case 6:
	       /* debut liste atteinte */
	       if ( ex == tc[F_HAUT-1])
		  *prov_exit = INTER_CURUP;
	       else
		  *prov_exit = INTER_PGUP;
	       return(D_INTERACTION);



	    } /* switch */

	 } /* while */


     case FIN:

       /* on efface la liste */

       return(winv(info_ptr->ld_fun));

     case KILL:

       /* on efface la liste et on restaure sa position */

       if((ret = winv(info_ptr->ld_fun)) != No_err)
	 return(ret);

       if((ret = wmove(info_ptr->ld_fun, liste_ptr->old_y, liste_ptr->old_x)) != No_err)
	 return(ret);

       f_libere(liste_ptr);

       return(No_err);


     default:

       break;

    }/*SWITCH*/


  /* termine */

  return(No_err);

}/*trait_liste*/






/******************************* SAISIE ***********************************/




/*---------------------------------------------
   Fonction d'initialisation d'une saisie

    Entree :

	- f 	  : nø logique fenetre dialogue
	- style	  : style du dialogue
	- dat     : pointeur sur data element
	- x	  : pcol dialog
	- y	  : plig dialog
	- w       : largeur du dialog
	- h       : hauteur du dialog
	- nbcol	  : longueur de la saisie
	- nbchar  : longueur du buffer de saisie

    Sortie :

	- code


    Traitement :


  ----------------------------------------------*/


WORD init_saisie(WORD f, stf_desc * style_f, DATA_ELEM_PTR dat, WORD x, WORD y, WORD w, WORD h, WORD nbcol, WORD nbchar)
{

  /* variables locales */

  WORD w_s, h_s;		/* longueur et hauteur de la saisie    	*/
  WORD x_s, y_s;		/* coordonnees locales saisie		*/
  DESC_SAISIE_PTR saisie_ptr;	/* pointeur sur descripteur de liste   	*/
  WDESC_APP df;			/* descripteur de fenetre de saisie	*/
  BPTR buff;			/* masque sur data_box			*/
/*  stf_desc *style_f;*/		/* ptr sur descripteur de style		*/
  WORD nb;
  SWORD ret;


  /* variables externes */

  extern stf_desc stf[MAXSTF+1];


  /* fonctions */



  /* TRAITEMENT */
  /**************/


  y_s = dat->y;
  x_s = dat->x;


  /* calcul de la taille de la saisie et verification */

  w_s = nbcol + 2;
  h_s = 1;

  /* on verifie que la saisie entre dans le dialogue */

  if((w_s + x_s) - 1 > w || (h_s + y_s) - 1 > h)
    return(Bd_err_pos);


  /* on initialise la structure de la saisie */

  if((saisie_ptr = (DESC_SAISIE_PTR)f_allouer(sizeof(DESC_SAISIE))) == NULL)
    return(werr_mem);
  saisie_ptr->size_buff = nbchar;


  /* creation de la fenetre de la saisie */


  /* initialisation du descripteur de la fenetre */

  df.Amere_nbr = 0;
  df.Apos_lig = y_s + y - 1;	/* plig dialogue + plig saisie	*/
  df.Apos_col = x_s + x;	/* pcol dialogue + pcol saisie	*/
  df.Anb_lig = 1;
  df.Anb_col = nbcol;
  strcpy(df.Atitre, "");
  df.Aln_tit = 0;


  /* initialisation du style */

  /*style_f = &(stf[style-1]);*/

  df.Aatb_vid = style_f->f_fond.atbc;
  df.Aatbcol_text = style_f->f_fond.colc;
  df.Aatbcol_fond = style_f->f_fond.colf;

  df.Acontrol = INVISIBLE + CURSEUR;



  /* creation fenetre de saisie */

  if((ret = wcreatc(&(saisie_ptr->nof), &df)) != No_err)
    {
     f_libere(saisie_ptr);
     return(ret);
    }

  /* on memorise la description de la saisie dans dat */

  dat->desc_elem = (BPTR)saisie_ptr;
  dat->w = w_s-2;
  dat->h = h_s;
  dat->x++;


  /* on memorise les attributs video de la fenetre de dialog */

  saisie_ptr->atb_v = style_f->f_fond.atbc;
  saisie_ptr->col_t = style_f->f_fond.colc;
  saisie_ptr->col_f = style_f->f_fond.colf;

  saisie_ptr->fl_aff = FALSE;

  /* on initialise le buffer dans data_box a blanc */

  buff = &((dat->data_ptr)[I_val_saisie]);
  for(nb = 0; nb < nbchar; nb++)
    buff[nb] = ' ';


  /* on affiche les delimiteurs de saisie */

  wposcur(f, y_s, x_s);
  wwritec(f, (BPTR)"[");
  wposcur(f, y_s, x_s + nbcol + 1);
  wwritec(f, (BPTR)"]");

  /* termine */

  return(No_err);

}/*init_saisie*/






/*---------------------------------------------
   Fonction de traitement d'une saisie

    Entree :

	- f    : nø logique de la fenetre
	- flag : flag de traitement (INIT, TRAIT, FIN, KILL)
	- dat  : pointeur sur data element


    Sortie :

	- code


    Traitement :


  ----------------------------------------------*/


SWORD trait_saisie(WORD f, BYTE flag, DATA_ELEM_PTR dat, WPTR prov_exit)
{

  /* variables locales */

  WORD nof;			/* nø fenetre saisie			*/
  BPTR data_box_ptr;		/* ptr sur desc datat_box saisie	*/
  DESC_SAISIE_PTR saisie_ptr;	/* ptr sur description saisie		*/
  BPTR buff1;
  SWORD nb, nb1;
  WORD taille_s;		/* retour size saisie			*/
  BPTR temp;
  BYTE exit;			/* type de sortie de fct de saisie	*/
  SWORD ret;			/* code retour fct			*/



  /* les fonctions */




  /* TRAITEMENT */
  /***************/

  data_box_ptr = dat->data_ptr;
  saisie_ptr = (DESC_SAISIE_PTR)dat->desc_elem;

  nof = saisie_ptr->nof;

  switch(flag)
    {
     case INIT:

       /* on positionne l'etat dans data_elem */

       dat->etat = data_box_ptr[I_etat_saisie];

       /* on initialise la saisie (Affichage + poscur) */
       sftxt_modc(nof, saisie_ptr->size_buff, &taille_s, (BPTR)(&data_box_ptr[I_val_saisie]), 9, (BPTR)&exit);

       /* on positionne les attributs video en fct de l'etat */

       if(dat->etat == ACTIF)
	 {
	  /* sur le dialogue */

/* attention <> asf 1.3 */
	  wsetatb(f, saisie_ptr->atb_v, saisie_ptr->col_t, saisie_ptr->col_f, dat->y, dat->x-1, 1, 1);
	  wsetatb(f, saisie_ptr->atb_v, saisie_ptr->col_t, saisie_ptr->col_f, dat->y, (dat->x + dat->w), 1, 1);

	  /* dans la fenetre de saisie */

	  wsetatb(nof, saisie_ptr->atb_v, saisie_ptr->col_t, saisie_ptr->col_f, 1, 1, 1, dat->w);
	 }
       else
	 {
	  /* sur le dialogue */

	  wsetatb(f, co.el_bd_inact.atbc, co.el_bd_inact.colc, saisie_ptr->col_f, dat->y, dat->x-1, 1, 1);
	  wsetatb(f, co.el_bd_inact.atbc, co.el_bd_inact.colc, saisie_ptr->col_f, dat->y, (dat->x + dat->w), 1, 1);

	  /* dans la fenetre de saisie */

	  wsetatb(nof, co.el_bd_inact.atbc, co.el_bd_inact.colc, saisie_ptr->col_f, 1, 1, 1, dat->w);
	 }

       /* on rend visible la fenetre et on en profite pour la decongeler */
       wfgen(nof, 11);
       wselect(nof);
       wvis(nof);
       /* affichage OK, on rend la saisie mouse_sensitive */
       put_item_mouse_list(nof);

       return(No_err);



     case TRAIT:

       wfgen(nof, 10);
       /* appel fct de saisie; si mode interactif -> prise en compte des tch esc */
       if((ret = sftxt_modc(nof, saisie_ptr->size_buff, &taille_s, (BPTR)(&data_box_ptr[I_val_saisie]), 1 + ((dat->mode_inter == ACTIF) ? 32 : 0), (BPTR)&exit)) != No_err)
	 return(ret);
       wfgen(nof, 11);

       /* on complete avec des blancs */

       for(nb = taille_s; nb < saisie_ptr->size_buff; nb++)
	 data_box_ptr[I_val_saisie + nb] = ' ';

       /* on met en forme la taille de la saisie */

       temp = (BPTR)&taille_s;
#ifdef IDIRECT
       data_box_ptr[I_size_saisie] = *(temp + 1);
       data_box_ptr[I_size_saisie + 1] = *temp;
#else
       data_box_ptr[I_size_saisie] = *temp;
       data_box_ptr[I_size_saisie + 1] = *(temp+1);
#endif /* IDIRECT */

       switch(exit)
	 {
	  case ESC:
	    return(D_ESCAPE);

	  case TAB:
	  case RC:
	  case SHIFT_TAB:
	    /* test si mode non-interactif */

	    if((dat->mode_inter != ACTIF)&&(dat->mode_inter != ACTIF2))
		if (exit == SHIFT_TAB) 
		    return(D_PRECEDENT);
		else
	            return(D_SUIVANT);

	    /* on compare la saisie et sa sauvegarde */

	    buff1 = &(data_box_ptr[I_val_saisie]);
	    for(nb = 0; nb < saisie_ptr->size_buff; nb++)
	    if(buff1[nb] != saisie_ptr->sauve_sais[nb])
	      break;

	    if((nb == saisie_ptr->size_buff)&&(dat->mode_inter != ACTIF2))
	      { 	
		if (exit == SHIFT_TAB) 
		    return(D_PRECEDENT);
		else
	            return(D_SUIVANT);
	    }  
	    else {
		switch(exit) {		
		    case TAB:
			*prov_exit = INTER_NEXT;
			break;
		    case SHIFT_TAB:
			*prov_exit = INTER_PREV;
			break;
		    case RC:
			*prov_exit = INTER_VALID;
			break;
		 }	
		 return(D_INTERACTION);
	     }

	  default:
	    /* on teste la frappe d'une touche d'echappement */
	    if((nb = sffind_tch(exit)) != 0)
	      return(D_TCH_ESC - nb);
	    else
	      return(D_SUIVANT);

	  }/*switch exit*/


     case FIN:

       /* on rend la saisie non mouse_sensitive */
       del_item_mouse_list(nof);

       /* puis on efface la fenetre de saisie */
       return(winv(saisie_ptr->nof));


     case KILL:

       /* on kill la fentre de saisie */

       if((ret = wsup(nof)) != No_err)
	 return(ret);

       f_libere(saisie_ptr);
       return(No_err);


     default:
       break;

    }/*SWITCH*/


  /* termine */

  return(No_err);

}/*trait_saisie*/







/******************************* AIDE ************************************/





/*---------------------------------------------
   Fonction d'initialisation d'un bouton d'aide

    Entree :

	- f 	 : nø logique fenetre dialogue
	- dat    : pointeur sur data element
	- w      : largeur du dialog
	- h      : hauteur du dialog
	- lib_b  : libelle du bouton


    Sortie :

	- code


    Traitement :


  ----------------------------------------------*/


WORD init_aide(WORD f, DATA_ELEM_PTR dat, WORD w, WORD h, BYTE *lib_b)
{

  /* variables locales */

  BYTE nb;
  WORD w_b, h_b;		/* longueur et hauteur du bouton 	*/
  DESC_AIDE_PTR aide_ptr;	/* pointeur sur descripteur de bouton 	*/
  BYTE *lib;			/* ptr sur chaine			*/


  /* on initialise la structure du bouton */

  if((aide_ptr = (DESC_AIDE_PTR)f_allouer(sizeof(DESC_AIDE))) == NULL)
    return(werr_mem);

  /* calcul de la taille du bouton et verification */

  w_b = (WORD)strlen(lib_b) + 2;
  h_b = 1;

  /* on recupere l'equiv caractere si existe et on modifie la taille du libelle */
  
  lib = NULL;
  for(nb = 0; nb < w_b - 2; nb++)
    if((lib_b[nb] == '~') && (lib_b[nb+2] == '~'))
      {
       if((lib = allouer(w_b)) == NULL)
	 return(werr_mem);
       strcpy(lib, lib_b);
       aide_ptr->car_ex = lib_b[nb+1];
       aide_ptr->car_ex_pos = nb;
       w_b -= 2;
       lib[nb] = 0;
       lib[nb+2] = 0;
       break;
      }

  if(nb == w_b -2)
    aide_ptr->car_ex = 0;


  /* on verifie que le bouton entre dans le dialogue */

  if((w_b + dat->x)-1 > w || (h_b + dat->y)-1 > h)
    {
     f_libere(aide_ptr);
     if(lib != NULL)
       libere(lib);
     return(Bd_err_pos);
    }

  /* on memorise la description du bouton dans dat */

  dat->desc_elem = (BPTR)aide_ptr;
  dat->w = w_b;
  dat->h = h_b;
  dat->etat = ACTIF;


  /* on affiche le libelle du bouton */

  wposcur(f, dat->y, (dat->x) + 1);

  if(aide_ptr->car_ex == 0)
    wwritec(f, (BPTR)lib_b);
  else
    {
     wwritec(f, (BPTR)lib);
     wwritec(f, (BPTR)&lib[nb+1]);
     wwritec(f, (BPTR)&lib[nb+3]);
     libere(lib);
    }

  /* termine */

  return(No_err);

}/*INIT_AIDE*/






/*---------------------------------------------
   Fonction de traitement d'un bouton d'aide

    Entree :

	- f    : nø logique de la fenetre
	- flag : flag de traitement (INIT, TRAIT, FIN, KILL)
	- dat  : pointeur sur data element


    Sortie :

	- code


    Traitement :


  ----------------------------------------------*/


SWORD trait_aide(WORD f, BYTE flag, DATA_ELEM_PTR dat)
{

  /* variables locales */

  BYTE car_lu;			/* caractere saisi 			*/
  WORD x, y, w, h;		/* coordonnees et taille bouton		*/
  DESC_AIDE_PTR aide_ptr;	/* ptr sur description aide		*/
  SWORD ret;			/* code retour fct			*/




  /* les fonctions */

  BYTE is_on_mouse();

  /* TRAITEMENT */
  /***************/


  x = dat->x; y = dat->y; w = dat->w; h = dat->h;

  aide_ptr = (DESC_AIDE_PTR)dat->desc_elem;

  switch(flag)
    {
     case INIT:

       /* on dessine le bouton d'aide (forcement actif) */
       
       wsetatb(f, co.bout.atbc, co.bout.colc, co.bout.colf, y ,x , h, w);
       if(aide_ptr->car_ex != 0)
	 wsetatb(f, co.c_cle_bout.atbc, co.c_cle_bout.colc, co.bout.colf, y , aide_ptr->car_ex_pos + x + 1, 1, 1);

       return(No_err);


     case TRAIT:

       /* on positionne le curseur et on attend */

       wfgen(f, 10);
       wposcur(f, dat->y, dat->x);
       while(1)
	 {
	  car_lu = 0;
	  while(car_lu == 0)
	    {
	     if(event.event == NO_EVENT)
	       wait_eventc(BOUTON_EVENTS, (EVENT_PTR)&event);
	     if(event.event == KEYBOARD)
	       car_lu = get_val_touche(event.arg);

	     switch(event.event)
	       {
		case MOUSE_DOWN:
		  if(is_on_mouse(dat, (EVENT_PTR)&event) == TRUE)
		    {
		     wfgen(f, 11);
		     /*mouse_off();*/
		     wsetatb(f, SOUSINT + VIDEO, GRIS, co.bout.colf, y ,x , h, w);
		     /*mouse_on();*/
		     event.event = NO_EVENT;
		    }
		  else
		    car_lu = T_TAB;
		  break;

		case MOUSE_UP:
		  if(is_on_mouse(dat, (EVENT_PTR)&event) == TRUE)
		    {
		     car_lu = T_ENVOI;
		     event.event = NO_EVENT;
		    }
		  else
		      event.event = NO_EVENT;

		  /*mouse_off();*/
		  wsetatb(f, co.bout.atbc, co.bout.colc, co.bout.colf, y ,x , h, w);
		  if(aide_ptr->car_ex != 0)
		    wsetatb(f, co.c_cle_bout.atbc, co.c_cle_bout.colc, co.bout.colf, y , aide_ptr->car_ex_pos + x + 1, 1, 1);
		  wfgen(f, 10);
		  wposcur(f, dat->y, dat->x);
		  /*mouse_on();*/

		  break;

		default:
		  event.event = NO_EVENT;
		  break;

	       }/* switch(event) */

	    }/* while(car_lu == 0) */


	  if((car_lu == aide_ptr->car_ex) || (car_lu == T_ENVOI))
	    {
	     /* affichage de l'aide */
	     sa_aid((BPTR)a_mcd);
	     wposcur(f, dat->y, dat->x);
	     wfgen(f, 10);
	    }
	  else
	    switch(car_lu)
	      {

               case T_ESC:
		 return(D_ESCAPE);

	       case T_AIDE:
		 sa_aid((BPTR)a_mcd);
		 wposcur(f, dat->y, dat->x);
		 wfgen(f, 10);
		 break;

	       case T_TAB:
	       case SHIFT_TAB:
	       case F_GAUCHE:
	       case F_DROITE:
	       case F_HAUT:
	       case F_BAS:
		 if((ret = calc_retour(dat, car_lu)) != NO_RETOUR)
		   return(ret);
		 break;

	       default:

		 /* on regarde si car_lu est une equivalence */

		 if((ret = cherche_equi(dat->equi_c, car_lu)) != NO_EQUIV)
		   return(ret);
		 break;

	      }/*switch*/

	 }/*while*/


     case ACTION:

       /* affichage de l'aide */

       sa_aid((BPTR)a_mcd);

       return(D_OLD);


     case FIN:

       return(No_err);


     case KILL:
       f_libere(aide_ptr);
       return(No_err);


     default:
       break;
    }


  /* termine */

  return(No_err);

}/*TRAIT_AIDE*/







/******************************* FUNFREE **********************************/



/*---------------------------------------------
   Fonction d'initialisation d'une fenetre

    Entree :

	- f 	  : nø logique fenetre dialogue
	- dat     : pointeur sur data element
	- x	  : pcol dialog
	- y	  : plig dialog
	- w       : largeur du dialog
	- h       : hauteur du dialog
	- nf	  : nø fenetre

    Sortie :

	- code


    Traitement :


  ----------------------------------------------*/


WORD init_fun(WORD f, DATA_ELEM_PTR dat, WORD x, WORD y, WORD w, WORD h, WORD nf)
{

  /* variables locales */

  WORD w_l, h_l;		/* longueur et hauteur de la liste     	*/
  DESC_FUN_PTR fun_ptr;		/* pointeur sur descripteur de liste   	*/
  WDESC_PTR wd;			/* ptr sur info liste			*/
  WORD cad;			/* indicateur de cadre de la fenetre	*/
  WORD ret;

  WITEM* wi;

  /* TRAITEMENT */
  /**************/

  if (( nf == 0)||(nf>MAXFUN))
	return(werr_desc);

  wi = WLOG[nf-1];
  if ( wi->mere == NULL)
	return(werr_desc);

  wd = wi->wdesc_ptr;

  /* on initialise la structure de la fenetre */

  if((fun_ptr = (DESC_FUN_PTR)f_allouer(sizeof(DESC_FUN))) == NULL)
    return(werr_mem);


  /* on verifie que la liste entre dans le dialogue */

  cad = wd->cad;
  w_l = wd->nb_col + (2*cad);
  h_l = wd->nb_lig + (2*cad);
  if((w_l + dat->x)-1 > w || (h_l + dat->y)-1 > h)
    return(Bd_err_pos);


  /* on sauvegarde la position de la liste et son numero */
  fun_ptr->old_x = wd->pos_col;
  fun_ptr->old_y = wd->pos_lig;
  fun_ptr->nof = nf;


  /* on la rend invisible (ce qui normalement est deja fait ...) */

  winv(nf);


  /* on modifie la position de la fenetre */
/*31.08.92 llb*/
  if((ret = wmove(nf, dat->y + y -1/*-cad*/, dat->x + x -1/*- cad*/)) != No_err)
    return(ret);


  /* on memorise la description de la fenetre dans dat */

  dat->desc_elem = (BPTR)fun_ptr;
  dat->w = w_l;
  dat->h = h_l;
  dat->etat = ACTIF;


  /* termine */

  return(No_err);

}/*init_liste*/




/*---------------------------------------------
   Fonction de traitement d'une fenetre

    Entree :

	- f    : nø logique de la fenetre
	- flag : flag de traitement (INIT, TRAIT, FIN, KILL)
	- dat  : pointeur sur data element


    Sortie :

	- code


    Traitement :


  ----------------------------------------------*/


SWORD trait_fun(WORD f, BYTE flag, DATA_ELEM_PTR dat, WPTR prov_exit)
{

  /* variables locales */

  WORD nof;			/* nø fenetre associe a la liste	*/
  BYTE exit, ex;		/* mode de sortie de fct choix		*/
  BPTR data_box_ptr;		/* ptr sur desc datat_box liste		*/
  DESC_FUN_PTR fun_ptr;		/* ptr sur description liste		*/
  SWORD ret;			/* code retour fct			*/
  WORD nb;



  /* TRAITEMENT */
  /***************/

  fun_ptr = (DESC_FUN_PTR)dat->desc_elem;
  data_box_ptr = dat->data_ptr;
  nof = fun_ptr->nof;

  switch(flag)
    {
     case INIT:

       /* on positionne l'etat dans data_elem */

       dat->etat = data_box_ptr[I_etat_f_free];


       /* on affiche la fenetre */

	  wselect(nof);
	  wvis(nof);
       return(No_err);



     case TRAIT:

	  event.event = NO_EVENT;
	  wselect(nof);
	return(D_INTERACTION);

     case FIN:

       /* on efface la liste */

       return(winv(nof));

     case KILL:

       /* on efface la fenetre et on restaure sa position */

       if((ret = winv(nof)) != No_err)
	 return(ret);

       if((ret = wmove(nof, fun_ptr->old_y, fun_ptr->old_x)) != No_err)
	 return(ret);

       f_libere(fun_ptr);

       return(No_err);


     default:

       break;

    }/*SWITCH*/


  /* termine */

  return(No_err);

}/*trait_liste*/






/* Calcul du retour pour fonctions de traitement des elements */

SWORD calc_retour(DATA_ELEM_PTR dat, BYTE car_lu)
{
  switch(car_lu)
    {
     case T_TAB:
     case T_ENVOI:
       return(D_SUIVANT);

     case SHIFT_TAB:
       return(D_PRECEDENT);

     case F_GAUCHE:
       if(dat->v_g != 0)
	 return(D_GAUCHE);
       break;

     case F_DROITE:
       if(dat->v_d != 0)
	 return(D_DROIT);
       break;

     case F_HAUT:
       if(dat->v_h != 0)
	 return(D_HAUT);
       break;

     case F_BAS:
       if(dat->v_b != 0)
	 return(D_BAS);
       break;

     default:
       break;
    }

  return(NO_RETOUR);

}/*CALC_RETOUR*/




/* fonction de recherche d'une equivalence clavier */

SWORD cherche_equi(EQUIV_PTR eq_ptr, BYTE code)
{
  BYTE i;
  BYTE elem, c;

  c = Maj(code);
  for(i = 0; i < eq_ptr->nb_eq; i++)
    if((eq_ptr->tab_eq[i]).car == c)
      {
       elem = (eq_ptr->tab_eq[i]).no_elem;
       if(((DATA_ELEM_PTR) ((((AIG_PTR)(eq_ptr->aig_bd_eq))[elem - 1]).dat_elem))->etat	== ACTIF)
	 return(D_EQUIV - elem);
       else
	return(NO_EQUIV);
      }
  return(NO_EQUIV);

}




/************************/
/* Fonctions de service */
/************************/



/* Retourne l'etat du bit "rang" de mot_ */

WORD get_bit(WORD mot_, BYTE rang)
{
  return((mot_ >> rang) & 1);
}




WORD clear_bit(WORD mot_, BYTE rang)
{
  return(mot_ & ~(1 << rang));
}




WORD set_bit(WORD mot_, BYTE rang)
{
  return(mot_ | (1 << rang));
}




BYTE is_on_mouse(DATA_ELEM_PTR dat, EVENT_PTR event)
{

  SWORD x_m, y_m;   	/* coordonnees souris (relatives)		*/


  /* on teste si la souris est sur l'element */

  y_m = event->plig - dat->o_v + 1;
  x_m = event->pcol - dat->o_h + 1;

  if((y_m >= dat->y) && (x_m >= dat->x) &&
     (y_m < (dat->y+dat->h)) && (x_m < (dat->x+dat->w)))

    return(TRUE);

  return(FALSE);

}





BYTE li_car()
{
  return(get_val_touche((BYTE)x_getc()));
}




BYTE get_val_touche(BYTE touche)
{
  BYTE val;
  WORD i;


  extern BYTE tc[MAX_TOUCHES];
  extern BYTE sa_touche;


  if(touche == sa_touche)
    return(T_AIDE);
  for (i = 0, val = touche; i<MAX_TOUCHES; ++i)
    if (tc[i] == touche)
      {
       val = i+1;
       break;
      }
  /* on filtre les touches speciales utilisees par les boŒtes de dialogue */

  switch(val)
    {
     case SPACE:
     case F_HAUT:
     case F_BAS:
     case F_GAUCHE:
     case F_DROITE:
     case T_ESC:
     case T_ENVOI:
     case T_TAB:
     case SHIFT_TAB:
     case T_AIDE:
       return(val);

     default:
       return(touche);
    }

}



