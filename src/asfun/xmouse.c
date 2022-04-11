#ifndef	_xmouse_c
#define	_xmouse_c

/****************************************************************
* Services Fenetres                 				*
*---------------------------------------------------------------*
* Source : xmouse.c                   				*
*---------------------------------------------------------------*
* Version : 1.1b                    				*
* Mise a jour le :						*
* 22/02/94  LLB Emulation fonctions souris pour UNIX		*
*****************************************************************
* Version for EXA 2.1f.0.15 onwards : Linux/UseIt/X11		*
* Modification 							*
* 03/01/2002 IJM Activation of mouse for ASFUN for LINUX/X11	*
*****************************************************************
* Fonctions				                        *
*                                   				*
*								*
****************************************************************/

#include "sfundef.h"
#include "bda.h"
#include "mouse.h"

/* les etats de la souris */

#define DOWN	1
#define UP	2

TYPF wait_eventc(WORD masque, EVENT_PTR evnt);
		
#define	LINUX_X11

#ifdef	LINUX_X11
extern	int	x_event(int);
#define	get_mimo_event()x_getch()
#define activate_mimo() x_event(0)
#define	get_mimo_type()	x_event(1)
#define	get_mimo_par()	x_event(2)
#define	get_mimo_lin()	x_event(3)
#define	get_mimo_col()	x_event(4)
#define	get_mimo_mask()	x_event(5)
#define	flush_mimo()	x_event(6)

static	void 	asfun_mimo_mask(int v)
{
	x_putch(27);
	x_putch('Z');
	x_putch((v & 0x00FF));
	x_putch(((v >> 8) & 0x00FF));
	return;
}
#endif

/* attente pour MOUSE_CLICK */

BYTE *rep1[] = {"MOUSE"};

WORD TIME_CLICK = 512;
WORD TIME_D_CLICK = 512;

BYTE *rep2[] = {"TIME"};

/* codes erreur */

#define No_err	0

/* Variables externes */

#ifndef	GRASFUN
extern WITEM* *mapecran;
extern WITEM* WLOG[MAXFUN];
extern WORD mouse_item_list[];		/* le tableau des fenetres mouse_sensitives		*/
extern WORD MAXLIG, MAXCOL;
extern WORD mousson,mous_is;
extern EVENT_STR	event;
#endif

/* globale */

/* memo de l'etat souris (appuye/relache)	*/

static BYTE etat_souris = 0;

WORD InitSouris() 
{
#ifdef	LINUX_X11
	return(x_event(0));
#else
	return(56);
#endif
}

VOID PopSouris()
{
	return;
}

WORD Advise_Exa()
{
	return(0);
}

WORD StateSouris()
{
	return(0);
}

TYPF Wkup_in()
{
	return(No_err);
}

TYPF Wkup_out()
{
	return(No_err);
}

/********************************************************
* Fonction SET_MOUSE_POSITION				*
*							*
* Fonction de positionnement du curseur de la souris	*
*							*
*********************************************************/

TYPF set_mouse_position(WORD plig, WORD pcol)
{
#ifndef	GRASFUN
#ifdef	LINUX_X11
	if ( mous_is) 
    	{
      		if((plig > MAXLIG) || (pcol > MAXCOL))
     	 		return(werr_desc);
      		mousson = TRUE;
    	}
#endif
#endif
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
#ifndef	GRASFUN
#ifdef LINUX_X11
	if (mous_is)
    	{  
      		mousson = TRUE;
    	}
#endif
#endif
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
#ifndef	GRASFUN
#ifdef LINUX_X11
	if ( mous_is) 
	{
		mousson = FALSE;
	}
#endif
#endif
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

#ifndef	GRASFUN
	if((nof < fen_ini) || (nof >= MAXFUN))
		return(werr_desc);

	mouse_item_list[nof-1] = TRUE;
#endif
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

#ifndef	GRASFUN

	if((nof < fen_ini) || (nof >= MAXFUN))
		return(werr_desc);

	mouse_item_list[nof-1] = FALSE;
#endif

	return(No_err);
}

/********************************************************
* Fonction GET_ITEM_MOUSE_LIST				*
*							*
* Retourne le nø de la fenetre mouse_sensitive situee	*
* sous la souris					*
*							*
*							*
*********************************************************/

TYPF get_item_mouse_list(WORD plig, WORD pcol)
{
	WORD nof;
	WITEM *wi;

#ifndef	GRASFUN

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
#endif
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

#ifndef	GRASFUN
	wi = WLOG[fun-1];
	wd = wi->wdesc_ptr;
	bd = wd->cad;
	if ( plig < (wd->pos_lig-bd) )
		return(FALSE);
	else if ( pcol < (wd->pos_col-bd) )
		return(FALSE);
	else if ( plig > (wd->pos_lig+wd->nb_lig+bd) )
		return(FALSE);
	else if ( pcol > (wd->pos_col+wd->nb_col+bd) )
		return(FALSE);
#endif
	return(TRUE);
}

/********************************************************
* Fonction WAIT_EVENT					*
*							*
* Fonction d'attente d'un evenement 			*
*							*
*							*
*********************************************************/

#ifdef	LINUX_X11
static	int WaitMouseEvent(EVENT_PTR eptr)
{
	int	e;

	if ((e = get_mimo_event()) == 256) 
	{
		eptr->event = get_mimo_type();
		eptr->arg   = get_mimo_par();
		eptr->plig  = get_mimo_lin();
		eptr->pcol  = get_mimo_col();
	}
	else	
	{
		eptr->event = KEYBOARD;
		eptr->arg   = e;
	}

	return(0);
}
#endif

TYPF wait_event(WORD masque, EVENT_PTR ev)
{
	WORD ret;

	/* Fonctions */

#ifndef	GRASFUN
	ret = wait_eventc(masque, (EVENT_PTR)&event);

	ev->event = Invint(event.event);
	ev->arg = Invint(event.arg);
	ev->plig = Invint(event.plig);
	ev->pcol = Invint(event.pcol);
	/* ne pas conserver cet evt */
	event.event = NO_EVENT;		
#endif
	return(ret);
}

/**************
* APPEL C
**************/

TYPF wait_eventc(WORD masque, EVENT_PTR evnt)
{

	WORD plig,pcol;
	WORD s_arg,s_evnt;

#ifdef	LINUX_X11
	WORD	oldmask;
	if (!mous_is) 
	{
#endif
		evnt->event = KEYBOARD;
		evnt->arg =   x_getch();
		return(No_err);

#ifdef	LINUX_X11
	}  

	plig = evnt->plig;
	pcol = evnt->pcol;

	oldmask = get_mimo_mask();

	asfun_mimo_mask(masque);

	WaitMouseEvent(evnt);	

	if (evnt->event == KEYBOARD)
		flush_mimo();
		
	else	
	{

		if (evnt->event == MOUSE_UP)
			etat_souris = 0;
			
		else if (evnt->event == MOUSE_DOWN)
			etat_souris = 1;

		else if (evnt->event == MOUSE_M_W_DOWN) 
		{
			do	
			{
	        		s_evnt = evnt->event;
		  		s_arg = evnt->arg;
	          		WaitMouseEvent(evnt);
		  	}
			while ( evnt->event == MOUSE_M_W_DOWN);
		
			evnt->event = s_evnt;
			evnt->arg = s_arg;
			//   ** calcul du sens **
		 	if (plig > evnt->plig)
		 		evnt->event += M_UP;
		     	else if (plig < evnt->plig)
			 	evnt->event += M_DOWN;
		       	else if (pcol > evnt->pcol)
			   	evnt->event += M_LEFT;
			else 	evnt->event += M_RIGHT;
	     	}
	}		

	asfun_mimo_mask(oldmask);
	return(No_err);

#endif

} 

/********************************************************
* Fonction FLUSH_EVENT					*
*							*
* Fonction de RAZ de la structure d'evenement		*
*							*
********************************************************/

TYPF flush_event(EVENT_PTR ev)
{
	WORD ret;
#ifdef	LINUX_X11
	TYPF flush_eventc();
	ret = flush_eventc((EVENT_PTR)&event);
	ev->event = Invint(event.event);
#endif
	return(ret);
}

/**************
* APPEL C
**************/

#ifdef	LINUX_X11
TYPF flush_eventc(EVENT_PTR evnt)
{

	evnt->event = NO_EVENT;
	etat_souris = 0;
	flush_mimo();     	

	return(No_err);
}
#endif 

/********************************************************
* Fonction GET_EVENT					*
*							*
* Fonction de transfert de event ASFUN -> event APPLI 	*
*							*
*							*
*********************************************************/

TYPF get_event(EVENT_PTR ev)
{
#ifdef	LINUX_X11
	ev->event = Invint(event.event);
	ev->arg = Invint(event.arg);
	ev->plig = Invint(event.plig);
	ev->pcol = Invint(event.pcol);
	event.event = NO_EVENT;
#endif
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
#ifdef	KEEP_THIS
	event.event = Invint(ev->event);
	event.arg = Invint(ev->arg);
	event.plig = Invint(ev->plig);
	event.pcol = Invint(ev->pcol);
#endif
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
#ifdef	LINUX_X11
	return( WaitMouseEvent((EVENT_PTR)ev) );
#else    
	return(No_err);
#endif  
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
#ifdef	LINUX_X11
	if ( !mous_is)
		return(NO_EVENT);

	ev->event = event.event;
	ev->arg =   event.arg;
	ev->plig =  event.plig;
	ev->pcol =  event.pcol;
	event.event = NO_EVENT;
	return(ev->event);
#else
	return(NO_EVENT);
#endif
}

/********************************************************
* Fonction WHO_IS_THERE					*
*							*
* Retourne le nø de la fenetre situ‚e aux coord X,Y	*					*
*							*
*							*
*********************************************************/

TYPF who_is_there(plig, pcol, rel_lig,rel_col)
WORD plig;
WORD pcol;
WPTR rel_lig;
WPTR rel_col;
{
	WORD nof;
	WITEM *wi;
	WDESC_PTR wd;
	WORD rlig=plig;
	WORD rcol=pcol;
	 
	if((plig > MAXLIG) || (pcol > MAXCOL) || (plig==0) || (pcol==0))
		return(0);

	if ((wi = *(mapecran + (MAXCOL*(plig-1)) + (pcol-1))) != NULL) 
	{

		/* recherche dans WLOG du nø de la fenetre */
		/* --------------------------------------- */
		for (nof = 1; nof < MAXFUN; nof++)
			 if(wi == WLOG[nof])
				break;

		if(nof == MAXFUN)
			return(0);

		wd = wi->wdesc_ptr;

		rlig = plig - wd->pos_lig+1;
		PutAbalWord( rel_lig, rlig );

		rcol = pcol - wd->pos_col+1;
		PutAbalWord( rel_col, rcol );

		return(nof+1);		
	}

	PutAbalWord( rel_lig, rlig );
	PutAbalWord( rel_col, rcol );
	return(0);
}

#endif	/* _xmouse_c */
