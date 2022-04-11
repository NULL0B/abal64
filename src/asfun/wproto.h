/* WPROTO.H */

#ifndef	_wproto_h
#define	_wproto_h

/****************************************************
*  PROTOTYPAGE DES FONCTIONS DE FENETRAGE STANDARD  *
*****************************************************/
#include "wtypf.h"
#ifndef OSF1
#ifdef AIX_VERS
#ifndef SPARC
#endif /* AIX_VERS */
#include <stdarg.h>
#endif
#ifdef AIX_VERS
#endif
#endif /* AIX_VERS */
/****************************************************
* PROTOTYPAGE DES FONCTIONS INTERNES		    *
*****************************************************/
#ifdef PROL

TYPF	wcreatc(WPTR,WDESC_APP_PTR);    	/* creer une fenetre */
TYPF	wwritec(WORD,BPTR);    			/* ecrire dans une fenetre */
TYPF 	swcreatc(WPTR,WORD,WORD,WORD,WORD,BYTE,WORD,BPTR);

TYPF	md_opta(BYTE,BYTE,BYTE,BPTR,BPTR);  /* selection automatique option*/
TYPF	mo_afs(BPTR,BPTR,BYTE,BYTE);	    /* affichage option suivante */

TYPF	sfaidg(BPTR,BPTR);		    /* aide chapitres/sous-chapitres */



/****************************************************
* PROTOTYPAGE DES FONCTIONS C			    *
*****************************************************/

/* fonctions menus */
TYPF	md_creatc(BYTE,md_desc_ptr,WORD,BPTR);

/* fonctions de listes */
TYPF	ld_creatc(BYTE,ld_desc_ptr,BYTE,WORD,BPTR);
TYPF	le_creatc(BYTE,WPTR,BYTE,BYTE,BPTR,BPTR);
TYPF	le_downc(BYTE,WPTR,BPTR,BPTR,BPTR);
TYPF	le_upc(BYTE,WPTR,BPTR,BPTR,BPTR);
TYPF	ld_choixc(BYTE,WPTR,WPTR,BPTR,BPTR,BPTR);


/* boites */
TYPF	bv_spcc(bv_desc_ptr,BPTR,BPTR);

/* saisie de textes */
TYPF	sftxt_modc(WORD,WORD,WPTR,BPTR,BYTE,BPTR);


TYPF	lscreatc(WPTR);			/* creer un statut   */
TYPF	lsmessc(WORD,BYTE,BPTR);
TYPF	list_info(BYTE,LD_INFO_PTR);
TYPF	wmove(WORD,WORD,WORD);

/* Boites de dialogue */

TYPF 	bd_creatc(WPTR, WORD, WORD, WORD, WORD, WORD, BPTR, WORD);
#ifdef AIX_VERS
#ifndef AVIION
#endif /* AIX_VERS */
TYPF 	bd_insertc(WORD, WORD, WORD, WORD, ...);
#ifdef AIX_VERS
#endif
#endif /* AIX_VERS */
TYPF 	bd_usec(WORD, WORD, WPTR, WPTR);
TYPF 	bd_closec(WORD);
TYPF 	bd_supc(WORD);
TYPF 	bd_putdatac(WORD, BPTR);
TYPF 	bd_getdatac(WORD, BPTR);

/****************************************************
*  FONCTIONS SERVICE FENETRE			    *
*****************************************************/
/* initialisations */
TYPF	sfinit(BPTR);
TYPF	sfend();

/* touche d'echappement */
TYPF 	sfset_tch_esc(BYTE,BPTR);
TYPF 	sffind_tch(BYTE);

/* fonctions status */
/********************/
TYPF	lsacti();
TYPF	lsmess(BYTE,BYTE,BPTR);
TYPF	lsclear();
TYPF	lsdesac();

/* fonctions menus */
/*******************/
#ifdef MSDOS
TYPF	md_creat(BYTE,BPTR);
TYPF	mo_creat(BYTE,BYTE,BPTR,BPTR,BPTR);
TYPF	mo_modif(BYTE,BYTE,BYTE,BPTR,BPTR,BPTR);
#else
TYPF	md_creat(BYTE,md_desc_ptr);
TYPF	mo_creat(BYTE,BYTE,mo_desc_ptr,BPTR,BPTR);
TYPF	mo_modif(BYTE,BYTE,BYTE,mo_desc_ptr,BPTR,BPTR);
#endif

TYPF	mo_sep(BYTE,BYTE);
TYPF	mo_latt(BYTE,BYTE,BPTR,BPTR,BPTR);
TYPF	mo_matt(BYTE,BYTE,BYTE,BYTE,BYTE);
TYPF	mo_clear(BYTE,BYTE);
TYPF	md_aff(BYTE,BYTE,BYTE);
TYPF	md_opt(BYTE,BYTE,BPTR,BPTR,BPTR,BPTR, ...);
TYPF	md_clear(BYTE);
TYPF	md_sup(BYTE);
TYPF	md_way(BPTR,BPTR);


/* fonctions de listes */
/***********************/

#ifdef MSDOS
TYPF	ld_creat(BYTE,BPTR);
TYPF	lm_creat(BYTE,BPTR);
#else
TYPF	ld_creat(BYTE,ld_desc_ptr);
TYPF	lm_creat(BYTE,ld_desc_ptr);
#endif
TYPF	le_creat(BYTE,WPTR,BYTE,BYTE,BPTR,BPTR);
TYPF	le_lect(BYTE,WORD,BPTR,BPTR,BPTR);
TYPF	le_down(BYTE,WPTR,BPTR,BPTR,BPTR);
TYPF	le_up(BYTE,WPTR,BPTR,BPTR,BPTR);
TYPF	le_matt(BYTE,WORD,BYTE,BYTE,BPTR,BPTR);
TYPF	ld_close(BYTE);
TYPF	ld_aff(BYTE,WORD,WORD);
TYPF	ld_choix(BYTE,WPTR,WPTR,BPTR,BPTR, ...);
TYPF	ld_clear(BYTE);
TYPF	ld_sup(BYTE);
TYPF	le_insert(BYTE,WPTR,BYTE,BYTE,BPTR,BPTR);
TYPF	le_delete(BYTE,WORD);


/* boites de validation */
/************************/
TYPF	bv_spc(BPTR,BPTR,BPTR);
TYPF	bv_std(BYTE,BPTR);

/* saisie de textes */
/********************/
TYPF sftxt_mod(WORD,WORD,WPTR,BPTR,BYTE,BPTR, ...);

/* aide */
/********/
TYPF	sa_activ(BYTE,BPTR);
TYPF	sa_aid(BPTR);
TYPF	sa_aiddef(BPTR);
TYPF	sa_desac();


/* Boites de dialogue */
/**********************/
TYPF 	bd_creat();	/* WPTR, WORD, WORD, WORD, WORD, BYTE, ...);*/
TYPF 	bd_insert();	/*WORD, WORD, WORD, WORD, ...);*/
TYPF 	bd_use();	/*WORD, BYTE);*/
TYPF 	bd_sup();	/*WORD);*/
TYPF	bd_close();	/*WORD);*/
TYPF 	bd_putdata();	/*WORD, BPTR);*/
TYPF 	bd_getdata(); 	/*WORD, BPTR);*/

/* mouse et scroll_bars */
/*************************/
TYPF set_mouse_position(WORD, WORD);
TYPF mouse_on();
TYPF mouse_off();
TYPF put_item_mouse_list(WORD);
TYPF del_item_mouse_list(WORD);
TYPF get_item_mouse_list(WORD, WORD);
TYPF ms_inside(WORD,WORD,WORD);
TYPF wait_event(WORD, BPTR);
TYPF get_event(BPTR);
TYPF put_event(BPTR);
TYPF flush_event(BPTR);
TYPF add_scroll_bar(WORD, BYTE);
TYPF del_scroll_bar(WORD, BYTE);
TYPF update_scroll_bar(WORD, BYTE, WORD, WORD);
TYPF get_scroll_bar_region(WORD, BYTE, WORD, WORD, WORD, WORD);
TYPF read_event(BPTR);
TYPF PrlFlushEvent();
TYPF who_is_there(WORD, WORD, WPTR, WPTR);


/* styles fenetres */
/*******************/
#ifdef MSDOS
TYPF get_style(BYTE, BPTR);
TYPF set_style(BYTE, BPTR);
#else
TYPF get_style(BYTE, STYL_DESC_PTR);
TYPF set_style(BYTE, STYL_DESC_PTR);
#endif

/* Langue 		     */
/*****************************/
TYPF wlangue(BYTE);


#else


TYPF	wcreatc();   	/* creer une fenetre */
TYPF	swcreatc();   	/* creer une fenetre */

TYPF	md_opta();	/* selection automatique option*/
TYPF	mo_afs();	/* affichage option suivante */

TYPF	sfaidg();	/* aide chapitres/sous-chapitres */



/****************************************************
* PROTOTYPAGE DES FONCTIONS C			    *
*****************************************************/

/* fonctions menus */
TYPF	md_creatc();

TYPF	wcreatc();    /* creer une fenetre */
/* fonctions de listes */
TYPF	ld_creatc();
TYPF	le_creatc();
TYPF	le_downc();
TYPF	le_upc();
TYPF	ld_choixc();

/* boites */
TYPF	bv_spcc();

/* saisie de textes */
TYPF	sftxt_modc();


TYPF	lscreatc();			/* creer un statut   */
TYPF	lsmessc();

/****************************************************
*  FONCTIONS SERVICE FENETRE			    *
*****************************************************/

/* initialisations */
TYPF	sfinit();
TYPF	sfend();

/* fonctions status */
TYPF	lsacti();
TYPF	lsmess();
TYPF	lsclear();
TYPF	lsdesac();

/* fonctions menus */
TYPF	md_creat();
TYPF	mo_creat();
TYPF	mo_sep();
TYPF	mo_modif();
TYPF	mo_latt();
TYPF	mo_matt();
TYPF	mo_clear();
TYPF	md_aff();
TYPF	md_opt();
TYPF	md_clear();
TYPF	md_sup();
TYPF	md_way();

/* fonctions de listes */
TYPF	ld_creat();
TYPF	lm_creat();
TYPF	le_creat();
TYPF	le_lect();
TYPF	le_down();
TYPF	le_up();
TYPF	le_matt();
TYPF	ld_close();
TYPF	ld_aff();
TYPF	ld_choix();
TYPF	ld_clear();
TYPF	ld_sup();

/* boites */
TYPF	bv_spc();
TYPF	bv_std();

/* saisie de textes */
TYPF sftxt_mod();

/* aide */

TYPF	sa_activ();
TYPF	sa_aid();
TYPF	sa_aiddef();
TYPF	sa_desac();


#endif


/* fin de fichier */

#endif	/* _wproto_h */
	/* --------- */


