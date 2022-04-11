
/****************************************************************
* Services Fenetres                 				*
*---------------------------------------------------------------*
* Source : sfmouse.c                   				*
*---------------------------------------------------------------*
* Version : 1.1b                    				*
* Mise a jour le : 29/04/92  EDS (CERVIX)			*				*
*		   26/05/93  llb ms_inside			*
*****************************************************************
* Fonctions				                        *
*                                   				*
* - wait_event     attente d'un evenement (mouse ou keyboard)	*
*								*
****************************************************************/


#include "sfundef.h"
#include "bda.h"
#include "mouse.h"


/* les etats de la souris */

#define DOWN	1
#define UP	2




/* attente pour MOUSE_CLICK */

BYTE *rep1[] = {"MOUSE"};
#ifdef dosext
WORD TIME_CLICK = 30;
WORD TIME_D_CLICK = 30;
#else
WORD TIME_CLICK = 512;
WORD TIME_D_CLICK = 512;
#endif
BYTE *rep2[] = {"TIME"};



/* codes erreur */

#define No_err	0





/* Variables externes */

extern WITEM* *mapecran;
extern WITEM* WLOG[MAXFUN];
extern WORD mouse_item_list[];		/* le tableau des fenetres mouse_sensitives		*/
extern WORD MAXLIG, MAXCOL;
extern WORD mousson;

extern EVENT_STR	event;


/* globale */


static BYTE etat_souris = 0;		/* memo de l'etat souris pour lutter contre le temps	*/






/********************************************************
* Fonction SET_MOUSE_POSITION				*
*							*
* Fonction de positionnement du curseur de la souris	*
*							*
*********************************************************/

TYPF set_mouse_position(WORD plig, WORD pcol)
{

  if((plig > MAXLIG) || (pcol > MAXCOL))
    return(werr_desc);

  PositSouris((plig-1)*8, (pcol-1)*8);
  mousson = TRUE;
  return(No_err);
}




/********************************************************
* Fonction MOUSE_ON					*
*							*
* Curseur de la souris allume				*
*							*
*********************************************************/

TYPF mouse_on()
{

  PopSouris();
  mousson = TRUE;
  return(No_err);
}



/********************************************************
* Fonction MOUSE_OFF					*
*							*
* Curseur de la souris eteint				*
*							*
*********************************************************/

TYPF mouse_off()
{

  PushSouris();
  mousson = FALSE;
  return(No_err);
}





/********************************************************
* Fonction PUT_ITEM_MOUSE_LIST				*
*							*
* Ajout d'une fenetre mouse_sensitive a la liste	*
*							*
*							*
*********************************************************/

TYPF put_item_mouse_list(WORD nof)
{

  if((nof < fen_ini) || (nof >= MAXFUN))
    return(werr_desc);

  mouse_item_list[nof-1] = TRUE;

  return(No_err);
}




/*****************************2***************************
* Fonction DEL_ITEM_MOUSE_LIST				*
*							*
* Retrait d'une fenetre mouse_sensitive a la liste	*
*							*
*							*
*********************************************************/

TYPF del_item_mouse_list(WORD nof)
{

  WORD i;


  if((nof < fen_ini) || (nof >= MAXFUN))
    return(werr_desc);

  mouse_item_list[nof-1] = FALSE;

  return(No_err);
}





/********************************************************
* Fonction GET_ITEM_MOUSE_LIST				*
*							*
* Retourne le nø de la fenetre mouse_sensitive situ‚e	*
* sous la souris					*
*							*
*							*
*********************************************************/

TYPF get_item_mouse_list(WORD plig, WORD pcol)
{

  WORD nof;
  WITEM *wi;


  if((plig > MAXLIG) || (pcol > MAXCOL))
    return(0);

  if((wi = *(mapecran + (MAXCOL*(plig-1)) + (pcol-1))) != NULL)
    {
     /* recherche dans WLOG du nø de la fenetre */
     for(nof = 1; nof < MAXFUN; nof++)
       if(wi == WLOG[nof])
	 break;

     /* test si mouse_sensitive */
     if((nof != MAXFUN) && (mouse_item_list[nof] == TRUE))
       return(nof+1);
    }

  return(0);
}

/********************************************************
* Fonction MS_INSIDE					*
*							*
* Retourne VRAI si  PLIG ,PCOL appartient a Fun		*
*							*
*********************************************************/

TYPF ms_inside(WORD fun, WORD plig, WORD pcol)
{

  WORD nof;
  WITEM *wi;
  WDESC *wd;
  WORD bd;

     wi = WLOG[fun-1];
     wd = wi->wdesc_ptr;
     bd = wd->cad;
     if ( plig < wd->pos_lig-bd )
	return(FALSE);
     if ( pcol < wd->pos_col-bd )
	return(FALSE);
     if ( plig > wd->pos_lig+wd->nb_lig+bd )
	return(FALSE);
     if ( pcol > wd->pos_col+wd->nb_col+bd )
	return(FALSE);

  return(TRUE);
}






/********************************************************
* Fonction RECUP_EVENT	(Interne)			*
*							*
* Attente d'un evenement de base			*
*							*
*							*
*********************************************************/


VOID recup_event(WORD time, EVENT_PTR evnt)
{

  WORD ev, button, button_i;
  WORD lig_i, col_i, lig, col;
  WORD state_mouse, t;



  if((button_i = StateSouris(&col_i, &lig_i)) != 0)
    state_mouse = DOWN;
  else
    state_mouse = UP;

  if(etat_souris != state_mouse)
    if(etat_souris == 0)
      {
       ev = NO_EVENT;
       etat_souris = state_mouse;
      }
    else
      {
       ev = (state_mouse == DOWN) ? MOUSE_DOWN : MOUSE_UP;
       etat_souris = state_mouse;
       button = button_i;
       col = col_i;
       lig = lig_i;
      }
  else
    ev = NO_EVENT;


  evnt->event = NO_EVENT;
  t = time;

  while((!ev) && (t != 1))
    {
     /* test clavier */
     if(kbhit() != 0)
       ev = KEYBOARD;

     else
       {
	/* test mouse */
	button = StateSouris(&col, &lig);

	if(state_mouse == UP)
	  {
	   if(button != button_i)
	     {
	      etat_souris = DOWN;
	      ev = MOUSE_DOWN;
	     }

	   else
	     if((lig != lig_i) || (col != col_i))
	       ev = MOUSE_MOVE;
	  }

	else
	  {
	   if(state_mouse == DOWN)
	     if(button != button_i)
	       {
		if(button < button_i)
		  {
		   ev = MOUSE_UP;
		   etat_souris = UP;
		   button = (button == 0) ? button_i : (button_i - button);
		  }
		else
		  {
		   ev = MOUSE_DOWN;
		   etat_souris = DOWN;
		   button = button - button_i;
		  }
	       }
	     else
	       if((lig != lig_i) || (col != col_i))
		 ev = MOUSE_M_W_DOWN;
	       else
		 if(t == 2)
		   ev = MOUSE_IS_DOWN;
	  }
       }

     t -= (time == 0) ? 0 : 1;

    } /* while(!ev) */

  if(ev != NO_EVENT)
    {
     evnt->event = ev;
     evnt->arg = button;
     evnt->plig = (lig/8)+1;
     evnt->pcol = (col/8)+1;
    }

} /* GET_EVENT */





/********************************************************
* Fonction WAIT_EVENT					*
*							*
* Fonction d'attente d'un evenement 			*
*							*
*							*
*********************************************************/


TYPF wait_event(WORD masque, EVENT_PTR ev)
{

  WORD ret;

  /* Fonctions */

  TYPF wait_eventc();


  ret = wait_eventc(masque, (EVENT_PTR)&event);

  ev->event = Invint(event.event);
  ev->arg = Invint(event.arg);
  ev->plig = Invint(event.plig);
  ev->pcol = Invint(event.pcol);

  return(ret);
}



/**************
* APPEL C
**************/


TYPF wait_eventc(WORD masque, EVENT_PTR evnt)
{

  BYTE nb_click;    			/* compteur de click souris	*/
  WORD i, button, plig, pcol;



  /* Sauvegarde coordonnees souris */

  StateSouris(&pcol, &plig);
  plig = (plig/8)+1;
  pcol = (pcol/8)+1;

  nb_click = 0;

  /* on recupere les differents evenements */

  while(TRUE)
    {

     recup_event(((nb_click == 0) ? TIME_CLICK : TIME_D_CLICK), evnt);

     switch(evnt->event)
       {

	case KEYBOARD:
	  if((masque&KEYBOARD) || (masque&DIGIT) || (masque&LETTER))
	    {
	     evnt->arg = x_getc();
	     return(No_err);
	    }
	  else
	    x_getc();
	  break;

	case MOUSE_UP:
	  if(nb_click == 1)
	    {
	     evnt->event = MOUSE_UP; //MOUSE_CLICK;
	     return(No_err);
	    }

	  if(masque&MOUSE_UP)
	    return(No_err);
	  break;

	case MOUSE_DOWN:

	  if((masque&MOUSE_CLICK) || (masque&MOUSE_D_CLICK))
	    {
	     /* on doit recevoir un MOUSE_UP */
	     recup_event(TIME_CLICK, evnt);
	     if(evnt->event == MOUSE_UP)
	       {
		evnt->event = MOUSE_CLICK;
		if(masque&MOUSE_D_CLICK)
		  {
		   nb_click++;
		   if(nb_click == 2)
		     {
		      evnt->event = MOUSE_D_CLICK;
		      return(No_err);
		     }
		   break;
		  }
		else
		  return(No_err);
	       }
	    }

	  if(masque&MOUSE_DOWN)
	    {
	     evnt->event = MOUSE_DOWN;
	     return(No_err);
	    }
	  break;

	case MOUSE_MOVE:
	  if(nb_click == 1)
	    {
	     evnt->event = MOUSE_CLICK;
	     return(No_err);
	    }

	  if(masque&MOUSE_MOVE)
	    return(No_err);
	  break;

	case MOUSE_M_W_DOWN:
	  if(nb_click == 1)
	    {
	     evnt->event = MOUSE_CLICK;
	     return(No_err);
	    }

	  if(masque&MOUSE_M_W_DOWN)
	    {
	     /* calcul du sens */
	     if(plig > evnt->plig)
	       evnt->event += M_UP;
	     else
	       if(plig < evnt->plig)
		 evnt->event += M_DOWN;
	       else
		 if(pcol > evnt->pcol)
		   evnt->event += M_LEFT;
		 else
		   evnt->event += M_RIGHT;
	    }
	  return(No_err);

	case MOUSE_IS_DOWN:
	  if(nb_click == 1)
	    {
	     evnt->event = MOUSE_CLICK;
	     return(No_err);
	    }

	  if(masque&MOUSE_IS_DOWN)
	    return(No_err);
	  break;

	case NO_EVENT:
	  if(nb_click == 1)
	    {
	     evnt->event = MOUSE_CLICK;
	     return(No_err);
	    }
	  break;

       } /* switch(evnt) */

    } /* while(TRUE) */

} /* WAIT_EVENT */





/********************************************************
* Fonction FLUSH_EVENT					*
*							*
* Fonction de RAZ de la structure d'evenement		*
*							*
*							*
********************************************************/


TYPF flush_event(EVENT_PTR ev)
{

  WORD ret;

  /* Fonctions */

  TYPF flush_eventc();


  ret = flush_eventc((EVENT_PTR)&event);

  ev->event = Invint(event.event);

  return(ret);
}



/**************
* APPEL C
**************/


TYPF flush_eventc(EVENT_PTR evnt)
{

  evnt->event = NO_EVENT;

  return(No_err);

}




/********************************************************
* Fonction GET_EVENT					*
*							*
* Fonction de transfert de event ASFUN -> event APPLI 	*
*							*
*							*
*********************************************************/


TYPF get_event(EVENT_PTR ev)
{

  ev->event = Invint(event.event);
  ev->arg = Invint(event.arg);
  ev->plig = Invint(event.plig);
  ev->pcol = Invint(event.pcol);

  return(No_err);
}






/********************************************************
* Fonction PUT_EVENT					*
*							*
* Fonction de transfert de event APPLI -> event ASFUN 	*
*							*
*							*
*********************************************************/


TYPF put_event(EVENT_PTR ev)
{

  event.event = Invint(ev->event);
  event.arg = Invint(ev->arg);
  event.plig = Invint(ev->plig);
  event.pcol = Invint(ev->pcol);

  return(No_err);
}

