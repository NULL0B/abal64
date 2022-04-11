
/****************************************************************
* Services Fenetres                 				*
*---------------------------------------------------------------*
* Source : sfmouse.c                   				*
*---------------------------------------------------------------*
* Version : 1.1b                    				*
* Mise a jour le :						*
* 29/04/92  EDS (CERVIX)					*
* 25/05/93  LLB ms_inside		 			*
* 14/09/93  LLB trt perte evenement systeme			*
* 27/09/93  LLB read_event()					*
* 06/10/93  LLB pas d'evt KEYBOARD si bouton enfonce 		*	
* 23/10/93  LLB Run_Mouse(), whoisthere()
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

WORD TIME_CLICK = 512;
WORD TIME_D_CLICK = 512;

BYTE *rep2[] = {"TIME"};

/* codes erreur */

#define No_err	0





/* Variables externes */

extern WITEM* *mapecran;
extern WITEM* WLOG[MAXFUN];
extern WORD mouse_item_list[];		/* le tableau des fenetres mouse_sensitives		*/
extern WORD MAXLIG, MAXCOL;
extern WORD mousson,mous_is;

extern EVENT_STR	event;


/* globale */


static BYTE etat_souris = 0;		/* memo de l'etat souris (appuye/relache)	*/


/********************************************************
* Fonction SET_MOUSE_POSITION				*
*							*
* Fonction de positionnement du curseur de la souris	*
*							*
*********************************************************/

TYPF set_mouse_position(WORD plig, WORD pcol)
{
  if ( mous_is) 
    {
      if((plig > MAXLIG) || (pcol > MAXCOL))
     	 return(werr_desc);

      PositSouris(plig, pcol);
      mousson = TRUE;
    }
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
  if (mous_is)
    {  
      PopSouris();
      mousson = TRUE;
    }
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
  if ( mous_is)
    {
     PushSouris();
     mousson = FALSE;
  }
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




/*********************************************************
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
  WDESC_PTR wd;
  WORD bd;

     wi = WLOG[fun-1];
     wd = wi->wdesc_ptr;
     bd = wd->cad;
     if ( plig < (wd->pos_lig-bd) )
	return(FALSE);
     if ( pcol < (wd->pos_col-bd) )
	return(FALSE);
     if ( plig > (wd->pos_lig+wd->nb_lig+bd) )
	return(FALSE);
     if ( pcol > (wd->pos_col+wd->nb_col+bd) )
	return(FALSE);

  return(TRUE);
}






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
  event.event = NO_EVENT;		/* ne pas conserver cet evt */

  return(ret);
}



/**************
* APPEL C
**************/


TYPF wait_eventc(WORD masque, EVENT_PTR evnt)
{

WORD plig,pcol;
WORD s_arg,s_evnt;

  if (!mous_is)
    {	
	evnt->event = KEYBOARD;
	evnt->arg = (BYTE)x_getc();
	return(No_err);
    }  
  plig = evnt->plig;
  pcol = evnt->pcol;
  

do 
  PrlWaitEvent(evnt);	
while ((evnt->event == KEYBOARD) &&(etat_souris ==1));    

  if (evnt->event == MOUSE_UP)
	etat_souris = 0;
  if (evnt->event == MOUSE_DOWN)
	etat_souris = 1;

  if (evnt->event == KEYBOARD)
	PrlFlushEvent(); 



  if (evnt->event == MOUSE_M_W_DOWN) 
    {
	do
         {
 	  s_evnt = evnt->event;
	  s_arg = evnt->arg;
          WaitMouseEvent(evnt);
	  if (evnt->event == NO_EVENT)
	     break; 
	}
	while ( evnt->event == MOUSE_M_W_DOWN);
	evnt->event = s_evnt;
	evnt->arg = s_arg;

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
  etat_souris = 0;
/*  PrlFlushEvent(); */

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
  event.event = NO_EVENT;
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


/********************************************************
* Fonction READ_EVENT					*
*							*
* Fonction lecture  d'un evenement 			*
*							*
*							*
*********************************************************/


TYPF read_event(EVENT_PTR ev)
{

  return( WaitMouseEvent((EVENT_PTR)ev) );
  
}
/********************************************************
* Fonction RUN_MOUSE					*
*							*
* Fonction lecture  d'un evenement 			*
*							*
*							*
*********************************************************/


TYPF Run_Mouse(EVENT_PTR ev)
{
  if ( !mous_is)
    return(NO_EVENT);
  ev->event = event.event;
  ev->arg =   event.arg;
  ev->plig =  event.plig;
  ev->pcol =  event.pcol;
  event.event = NO_EVENT;
  return(ev->event);
  
}
/********************************************************
* Fonction WHO_IS_THERE					*
*							*
* Retourne le nø de la fenetre situ‚e aux coord X,Y	*					*
*							*
*							*
*********************************************************/

TYPF who_is_there(WORD plig, WORD pcol, WPTR rel_lig, WPTR rel_col)
{

  WORD nof;
  WITEM *wi;
  WDESC_PTR wd;
   
  if((plig > MAXLIG) || (pcol > MAXCOL) || (plig==0) || (pcol==0))
    return(0);

  if((wi = *(mapecran + (MAXCOL*(plig-1)) + (pcol-1))) != NULL)
    {
     /* recherche dans WLOG du nø de la fenetre */
     for(nof = 1; nof < MAXFUN; nof++)
       if(wi == WLOG[nof])
	 break;

     if(nof == MAXFUN)
       return(0);
     wd = wi->wdesc_ptr;
     *rel_lig = Invint(plig - wd->pos_lig+1);	
     *rel_col = Invint(pcol - wd->pos_col+1);
     return(nof+1);		

    }
    *rel_lig = Invint(plig);
    *rel_col = Invint(pcol);

  return(0);
}

/* fin de fichier */


