
/************************************************
* Service fenetre - Boite de dialogue     	*
*-----------------------------------------------*
* Source : SFBD.C                         	*
*-----------------------------------------------*
* Version :                               	*
* Creation : 16/07/91   EDS/CERVIX        	*
*						*
* Modifications :				*
*  - le 14/02/92 EDS				*
*    modif interface ABAL R_bouton et C_bouton, *
*    integration styles de fenetres ombrees.	*
*  - le 27/04/92 EDS				*
*    prise en compte des touches d'echappement	*
*  - le 29/10/92 LLB				*
*    Shift TAB dans BD				*
*   -le 30/09/93 LLB	 			*
*    argument bd_next dans BD_USE()		*
*    wselect(bd) si invisible			*
*************************************************
* Fonctions :                             	*
*        					*
*	- bd_creat	Creation dialogue	*
*	- bd_creatc				*
*						*
*	- bd_insert	Insert d'un element	*
*	- bd_insertc				*
*						*
*	- bd_use	Gestion du dialogue	*
*	- bd_usec				*
*						*
*	- bd_close	Fermeture du dialogue	*
*	- bd_closec				*
*						*
*	- bd_sup 	Destruction dialogue	*
*	- bd_supc				*
*						*
*	- bd_putdata	Transfert APPLI -> BD	*
*	- bd_putdatac				*
*						*
*	- bd_getdata	Transfert BD -> APPLI	*
*	- bd_getdatac				*
*                                         	*
*                                         	*
************************************************/



#if defined(BOS) || defined(OSF1) 
#include <varargs.h>
#define MAXARGS 100
#else
#include <stdarg.h> 
#endif

#include "sfbd.h"
#include "mouse.h"


extern GLOBAL BDA_ARG rt_arg;

extern TB_STR TB_BOX[];

extern EVENT_STR	event;
extern BYTE tb_style[MAXSTF];
extern	WITEM*   WLOG[MAXFUN];


/* definition des indices des arg dans rt_arg pour create */


#define NB_ARG_MIN_CREAT 6	/* Nb arg mini pour fct BD_CREAT	*/

#define Crt_i_nol	0	/* Nø logique boite			*/
#define Crt_i_pli	1	/* position ligne			*/
#define Crt_i_pco	2	/* position colonne			*/
#define Crt_i_nli	3	/* nb lignes 				*/
#define Crt_i_nco	4	/* nb colonnes 				*/
#define Crt_i_sty	5	/* style fenetre			*/
#define Crt_i_tit	6	/* titre dialogue			*/
#define Crt_i_dim	7	/* dimension boite			*/

/* PROTO fonctions internes */

TYPF bd_creatc();
#ifdef AIX_VERS
#if !defined(SPARC) && !defined(AVIION)
TYPF bd_insertc();
#endif
#else  /* AIX_VERS */
TYPF bd_insertc();
#endif /* AIX_VERS */
TYPF bd_usec();
TYPF bd_closec();
TYPF bd_supc();
TYPF bd_putdatac();
TYPF bd_getdatac();

BYTE next_elem();
BYTE prev_elem();
VOID calc_elem();
BYTE find_elem_on_mouse();

WORD init_message(), init_bouton(), init_r_bouton(), init_c_bouton();
WORD init_liste(), init_saisie(), init_aide();
WORD init_fun();
TYPF trait_bouton(), trait_r_bouton(), trait_c_bouton(), trait_liste();
TYPF trait_saisie(), trait_aide();
TYPF trait_fun();

/*-------------------------------------------------
   Fonction de creation d'une boite de dialogue
   APPEL ABAL

   Entree : ()

   On recupere les arguments dans la structure rt_arg

	- bd   : ptr sur nø logique dialogue
	- plig : position ligne du dialogue
	- pcol : position colonne
	- nlig : nb de lignes du dialogue
	- ncol : nb de colonnes
	- style: style de la fenetre du dialogue
	- [titre]: titre de la fenetre du dialog


   Sortie :

	- code


   Traitement :

	recuperation des arguments
	appel fonction C
	FIN

  -----------------------------------------------*/

TYPF bd_creat()
{
  /* variables locales */

  WPTR bd;			/* ptr sur no logique */
  WORD plig, pcol, nlig, ncol;	/* Coordonnees et taillle dialog */
  WORD style;			/* style dialog */
  BYTE titre[TAIL_TITRE+1];	/* titre dialog */
  BPTR temp;
  WORD i, ret;
  WORD dim;
  /* fonctions */

  TYPF bd_creatc();


  /* TRAITEMENT */
  /**************/

  /* recuperation et des arguments */

  /* test sur le nombre */

  if(rt_arg.c < NB_ARG_MIN_CREAT)
    return(Bd_err_arg);


  /* ptr nø logique */

  if(rt_arg.t[Crt_i_nol] != (TYPE_POURCENT | MODIFIABLE))
    return(Bd_err_typ);
  bd = rt_arg.v[Crt_i_nol];


  /* position et taille */

  if((rt_arg.t[Crt_i_pli] != TYPE_POURCENT) || (rt_arg.t[Crt_i_pco] != TYPE_POURCENT) ||
     (rt_arg.t[Crt_i_nli] != TYPE_POURCENT) || (rt_arg.t[Crt_i_nco] != TYPE_POURCENT))
    return(Bd_err_typ);

#ifdef AIX_VERS
#ifdef SPARC
  temp = (BPTR)rt_arg.v[Crt_i_pli];
  plig = (WORD)((*temp << 8) + *(temp + 1));
  temp = (BPTR)rt_arg.v[Crt_i_pco];
  pcol = (WORD)((*temp << 8) + *(temp + 1));
  temp = (BPTR)rt_arg.v[Crt_i_nli];
  nlig = (WORD)((*temp << 8) + *(temp + 1));
  temp = (BPTR)rt_arg.v[Crt_i_nco];
  ncol = (WORD)((*temp << 8) + *(temp + 1));
#else
#if dosext || unix
  plig = *(WPTR)rt_arg.v[Crt_i_pli];
  pcol = *(WPTR)rt_arg.v[Crt_i_pco];
  nlig = *(WPTR)rt_arg.v[Crt_i_nli];
  ncol = *(WPTR)rt_arg.v[Crt_i_nco];
#else
  temp = (BPTR)rt_arg.v[Crt_i_pli];
  plig = (WORD)((*temp << 8) + *(temp + 1));
  temp = (BPTR)rt_arg.v[Crt_i_pco];
  pcol = (WORD)((*temp << 8) + *(temp + 1));
  temp = (BPTR)rt_arg.v[Crt_i_nli];
  nlig = (WORD)((*temp << 8) + *(temp + 1));
  temp = (BPTR)rt_arg.v[Crt_i_nco];
  ncol = (WORD)((*temp << 8) + *(temp + 1));
#endif
#endif
#else  /* AIX_VERS */
#if dosext || unix
  plig = *(WPTR)rt_arg.v[Crt_i_pli];
  pcol = *(WPTR)rt_arg.v[Crt_i_pco];
  nlig = *(WPTR)rt_arg.v[Crt_i_nli];
  ncol = *(WPTR)rt_arg.v[Crt_i_nco];
#else
  temp = (BPTR)rt_arg.v[Crt_i_pli];
  plig = (WORD)((*temp << 8) + *(temp + 1));
  temp = (BPTR)rt_arg.v[Crt_i_pco];
  pcol = (WORD)((*temp << 8) + *(temp + 1));
  temp = (BPTR)rt_arg.v[Crt_i_nli];
  nlig = (WORD)((*temp << 8) + *(temp + 1));
  temp = (BPTR)rt_arg.v[Crt_i_nco];
  ncol = (WORD)((*temp << 8) + *(temp + 1));
#endif
#endif /* AIX_VERS */

  /* style */

  if(rt_arg.t[Crt_i_sty] == TYPE_DIESE)
    style = *((BPTR)rt_arg.v[Crt_i_sty]);
  else
    if(rt_arg.t[Crt_i_sty] == TYPE_POURCENT)
      {
#ifdef AIX_VERS
#ifdef SPARC
       temp = (BPTR)rt_arg.v[Crt_i_sty];
       style = (WORD)((*temp << 8) + *(temp + 1));
#else
#if dosext ||unix
       style = *(WPTR)rt_arg.v[Crt_i_sty];
#else
       temp = (BPTR)rt_arg.v[Crt_i_sty];
       style = (WORD)((*temp << 8) + *(temp + 1));
#endif
#endif
#else  /* AIX_VERS */
#if dosext ||unix
       style = *(WPTR)rt_arg.v[Crt_i_sty];
#else
       temp = (BPTR)rt_arg.v[Crt_i_sty];
       style = (WORD)((*temp << 8) + *(temp + 1));
#endif
#endif /* AIX_VERS */
      }
    else
      return(Bd_err_sty);

  /* controle et recuperation du titre */

  dim = 0;	/* valeur defaut */

  if(rt_arg.c == NB_ARG_MIN_CREAT) /* pas de titre */
      titre[0] = 0;
  else
    {
     if(rt_arg.t[Crt_i_tit] != TYPE_CHAINE)
       return(Bd_err_typ);
     if(rt_arg.l[Crt_i_tit] > TAIL_TITRE)
       return(Bd_err_tit);
     for(i = 0; i < rt_arg.l[Crt_i_tit]; i++)
       titre[i] = ((BPTR)rt_arg.v[Crt_i_tit])[i];
     titre[i] = 0;

    /* controle et recuperation dimension */

    if(rt_arg.c == NB_ARG_MIN_CREAT+2) /* dimension*/
      {
	if(rt_arg.t[Crt_i_dim] != TYPE_POURCENT)
	    return(Bd_err_typ);
#ifdef AIX_VERS
#ifdef SPARC
	  temp = (BPTR)rt_arg.v[Crt_i_dim];
	  dim = (WORD)((*temp << 8) + *(temp + 1));
#else
#if dosext || unix
	  dim = *(WPTR)rt_arg.v[Crt_i_dim];
#else
	  temp = (BPTR)rt_arg.v[Crt_i_dim];
	  dim = (WORD)((*temp << 8) + *(temp + 1));
#endif
#endif
#else  /* AIX_VERS */
#if dosext || unix
	  dim = *(WPTR)rt_arg.v[Crt_i_dim];
#else
	  temp = (BPTR)rt_arg.v[Crt_i_dim];
	  dim = (WORD)((*temp << 8) + *(temp + 1));
#endif
#endif /* AIX_VERS */
	if (dim >2)
	    return(Bd_err_sty);

      }
  }/* else titre*/

  /* Appel de la fonction C */


  ret = bd_creatc(bd, plig, pcol, nlig, ncol, style, titre, dim);

#ifdef IDIRECT
  temp = (BPTR)bd;
#ifndef OSF1
  *bd= (WORD)((*temp << 8) + *(temp + 1));
#else
  i=Invint(*bd);
  memcpy(bd,&i,sizeof(WORD));
#endif
#endif

  return(ret);
}





/*-------------------------------------------------
   Fonction de creation d'une boite de dialogue
   APPEL C

   Entree :

	- bd   : adresse de stockage nø logique dialog
	- plig : position ligne du dialogue
	- pcol : position colonne
	- nlig : nb de lignes du dialogue
	- ncol : nb de colonnes
	- style: style de la fenetre du dialogue
	- titre: titre de la fenetre du dialog


   Sortie :

	- code


   Traitement :

	verif creation dialog possible (dans TB_BOX)
	controle des arguments (taille et position dialogue)
	creation fenetre
	allocation boite de dialogue
	stockage dans TB_BOX
	FIN

  -----------------------------------------------*/

TYPF bd_creatc(bd,plig,pcol,nlig,ncol,style,titre,dim)
WPTR bd;
WORD plig;
WORD pcol;
WORD nlig;
WORD ncol;
WORD style;
BPTR titre;
WORD dim;
{

  /* variables locales */

  BYTE i_free;			/* indice place libre dans TB_BOX	*/
  WORD length;			/* longeur du titre 			*/
  WORD ret;			/* variable de retour fonction		*/
  WORD i;
  WDESC_APP df;			/* descripteur fenetre 			*/
  B_DIAL_PTR bd_ptr;		/* pointeur sur boite de dialog 	*/
  stf_desc *style_f;		/* ptr sur descripteur de stryle	*/
  BYTE bdomb;

  /* variables externes */

  extern stf_desc stf[MAXSTF+1];
  extern stc_desc stc[MAXSTC];

  /* fonctions */


  /* TRAITEMENT */
  /**************/

  /* verification init */



  if(fen_ini != 2)
    return(werr_ini);


  /* recherche place libre dans TB_BOX */

  for(i_free = 0; i_free < MAX_DIAL; i_free++)
    if(TB_BOX[i_free].no_log == 0)
      break;

  if(i_free == MAX_DIAL)
    return(Bd_err_max); /* il n'y a plus d'entree dispo */


  /* controle taille et position */

  if((plig <= 0) || (pcol <= 0) ||
     ((plig+nlig) > MAXLIG) || ((pcol+ncol) > MAXCOL))
    return(Bd_err_pos);


  /* controle taille titre */

  for(length = 0; titre[length] != 0; length++);
  if((length > ncol) || (length > TAIL_TITRE))
    return(Bd_err_tit);

  /* controle type */
/* style de fenetre */

	if ( (style == 0) || (style > STYLMAX) )
	    return(Bd_err_sty);
	if ( (style > 15) && (style < 20) )
	    return(Bd_err_sty);

	if ( style < 15)		/* 5+ombre*/
	 {
	    if ( style & SFOMB ) {
		style -= SFOMB;
		bdomb = TRUE;
	    }
	    else
		bdomb = FALSE;

	}
	else {                            /* 20.. */
	     style -=14;
	     if ( tb_style[style-1] == 0 )
		return(Bd_err_sty);
	     bdomb = stf[style-1].f_ombre;
	}

	style_f = &(stf[style-1]);
/*
  if(((style & ~SFOMB) <= 0) || ((style & ~SFOMB) > MAXSTF))
    return(Bd_err_sty);
*/

  /* initialisation du descripteur de la fenetre */

  df.Amere_nbr = 0;
  df.Apos_lig = plig;
  df.Apos_col = pcol;
  df.Anb_lig = nlig;
  df.Anb_col = ncol;
  strcpy(df.Atitre, titre);
  df.Aln_tit = length;

  /* initialisation du style de la fenetre */

/*  style_f = &(stf[style ~ SFOMB)-1]); */

  df.Aatb_vid = style_f->f_fond.atbc;
  df.Aatbcol_text = style_f->f_fond.colc;
  df.Aatbcol_fond = style_f->f_fond.colf;

  df.Acad_atb = style_f->f_cad.atbc;
  df.Acad_text = style_f->f_cad.colc;
  df.Acad_fond = style_f->f_cad.colf;

  df.Acontrol = ARPCURS + INVISIBLE + CURSEUR + ((BYTE)1 << (style_f->f_nostc + 2));
  if(bdomb)
    df.Acontrol += OMBRE;

  /* test si cadre user, si oui on l'initialise avec stc */
  if(style_f->f_nostc == MAXSTC)
    for(i = 0; i < 8; i++)
      df.Acad_usr[i] = stc[2].trait[i];


  /* creation fenetre */

  if((ret = wcreatc(bd, &df)) != No_err)
    return(ret);  /* Erreur en creation de fenetre, on propage le code erreur */


  /* Creation et initialisation de la boite */


    if((bd_ptr = (B_DIAL_PTR)f_allouer(sizeof(B_DIAL))) == NULL)
      return(werr_mem);

    if ( dim == 0)	/* 32 elem, D_BOX = 512 */
    {
	if((bd_ptr->bd_aig = (AIG_PTR)f_allouer(MAX_ELEM*sizeof(AIG_))) == NULL)
	  {
	    f_libere(bd_ptr);
	    return(werr_mem);
	}
	if((bd_ptr->data_box = (BPTR)f_allouer(DIM_DATA_BOX)) == NULL)
	  {
	    f_libere(bd_ptr->bd_aig);
	    f_libere(bd_ptr);
	    return(werr_mem);
	}
	if((bd_ptr->data_box_c = (BPTR)f_allouer(DIM_DATA_BOX)) == NULL)
	  {
	    f_libere(bd_ptr->data_box);
	    f_libere(bd_ptr->bd_aig);
	    f_libere(bd_ptr);
	    return(werr_mem);
	}
    }/* dim = 0 */

    if ( dim == 1)	/* 64 elem, D_BOX = 1024 */
    {
	if((bd_ptr->bd_aig = (AIG_PTR)f_allouer(MAX_ELEM1*sizeof(AIG_))) == NULL)
	  {
	    f_libere(bd_ptr);
	    return(werr_mem);
	}
	if((bd_ptr->data_box = (BPTR)f_allouer(DIM_DATA_BOX1)) == NULL)
	  {
	    f_libere(bd_ptr->bd_aig);
	    f_libere(bd_ptr);
	    return(werr_mem);
	}
	if((bd_ptr->data_box_c = (BPTR)f_allouer(DIM_DATA_BOX1)) == NULL)
	  {
	    f_libere(bd_ptr->data_box);
	    f_libere(bd_ptr->bd_aig);
	    f_libere(bd_ptr);
	    return(werr_mem);
	}
    }/* dim = 1 */

    if ( dim == 2)	/* 128 elem, D_BOX = 2048 */
    {
	if((bd_ptr->bd_aig = (AIG_PTR)f_allouer(MAX_ELEM2*sizeof(AIG_))) == NULL)
	  {
	    f_libere(bd_ptr);
	    return(werr_mem);
	}
	if((bd_ptr->data_box = (BPTR)f_allouer(DIM_DATA_BOX2)) == NULL)
	  {
	    f_libere(bd_ptr->bd_aig);
	    f_libere(bd_ptr);
	    return(werr_mem);
	}
	if((bd_ptr->data_box_c = (BPTR)f_allouer(DIM_DATA_BOX2)) == NULL)
	  {
	    f_libere(bd_ptr->data_box);
	    f_libere(bd_ptr->bd_aig);
	    f_libere(bd_ptr);
	    return(werr_mem);
	}
    }/* dim = 2 */




  bd_ptr->x = pcol;
  bd_ptr->y = plig;
  bd_ptr->w = ncol;
  bd_ptr->h = nlig;
  bd_ptr->nb_elem = 0;
  bd_ptr->stf_bd = style_f;	/*(BYTE)(style & ~SFOMB);*/
  bd_ptr->i_data = 0;
  bd_ptr->fl_aff = FALSE;
  
  (bd_ptr->bd_equiv).nb_eq = 0;
/*llb21  (bd_ptr->bd_equiv).aig_bd_eq = (BPTR)&bd_ptr->bd_aig;*/
  (bd_ptr->bd_equiv).aig_bd_eq = bd_ptr->bd_aig;

   if ( dim ==0 ) {
  	bd_ptr->len_box = DIM_DATA_BOX;
	bd_ptr->max_elem = MAX_ELEM;
   }
   else
   if ( dim ==1 ) {
	bd_ptr->len_box = DIM_DATA_BOX1;
	bd_ptr->max_elem = MAX_ELEM1;
   }
   else	{

  	bd_ptr->len_box = DIM_DATA_BOX2;
	bd_ptr->max_elem = MAX_ELEM2;
   }

  /* stockage de la boite dans TB_BOX */

  TB_BOX[i_free].dial = bd_ptr;
#ifdef AIX_VERS
#ifdef SPARC
  memcpy(&(TB_BOX[i_free].no_log),bd,sizeof(WORD));
#else
  TB_BOX[i_free].no_log = *bd;
#endif
#else  /* AIX_VERS */
  TB_BOX[i_free].no_log = *bd;
#endif /* AIX_VERS */

  /* creation du dialogue terminee ... */

  return(No_err);


} /*BD_CREATC*/








/* definition des indices des arg dans rt_arg pour insert */

#define NB_ARG_MIN_INS	4	/* nb arg. mini pour insertion		*/

#define Ins_i_nol	0	/* indice Nø logique boite 		*/
#define Ins_i_typ	3	/* indice type element 			*/
#define Ins_i_pli	1	/* indice position ligne 		*/
#define Ins_i_pco	2	/* indice position colonne 		*/



#define NB_ARG_MESSAGE	5	/* nb d'arguments des messages		*/

#define Mes_i_lib	4	/* libelle message			*/



#define NB_ARG_BOUTON	6	/* nb d'argumentrs pour un bouton 	*/

#define Bt_i_title	4	/* indice du titre dans rt_arg 		*/
#define Bt_i_code	5	/* indice du code */



#define NB_ARG_R_BOUT	7 	/* nb arg. pour radio-boutons 		*/

#define RB_i_nb		4	/* indice nombre de R_boutons		*/
#define RB_i_size       5	/* indice taille des R_boutons		*/
#define RB_i_str	6	/* indice chaine			*/


#define NB_ARG_C_BOUT	8	/* nb arg. pour check-boutons		*/

#define CB_i_typ	4	/* indice du type de check_bouton 	*/
#define CB_i_nb		5	/* indice nombre de C_boutons		*/
#define CB_i_size       6	/* indice taille des C_boutons		*/
#define CB_i_str	7	/* indice de la chaine des libelles	*/



#define NB_ARG_LISTE	5	/* nb d'arguments pour les listes 	*/

#define Li_i_nol	4	/* indice nø liste 			*/


#define NB_ARG_SAISIE	6	/* nb d'arguments des saisies		*/

#define Sai_i_nco	4	/* indice nb de colonnes de la saisie	*/

#define	Sai_i_nca	5	/* indice nb de caracteres de la saisie	*/



#define NB_ARG_AIDE	5	/* nb d'arguments de l'aide		*/

#define Aid_i_lib	4	/* libelle message			*/


#define NB_ARG_FUN	5	/* nb d'arguments pour funfree	 	*/

#define Fun_i_nol	4	/* indice nø fenetre 			*/




/*-------------------------------------------------------
   Fonction d'ajout d'un element a une boite de dialogue
   APPEL ABAL

   Entree : ()

   On recupere les arguments dans la structure rt_arg

	- nlog  : Nø logique du dialog
	- typ_e : type de l'element a ajouter
	- plig  : position ligne de l'element (relatif dialogue)
	- pcol  : position colonne

   Attention : les args specifiques, sont recuperes par les fonctions
	       d'initialisation.

   Sortie :

	- code


   Traitement :

	recuperation et controle des arguments
	appel fonction C

	FIN

  --------------------------------------------------------*/


TYPF bd_insert()
{

  /* variables locales */

  WORD nb;			/* nombre de radio ou check		*/
  WORD size;			/* taille libelle radio ou check	*/
  BYTE type;			/* type check bouton			*/
  WORD i, j, k;
  WORD nlog;			/* no logique dialogue 			*/
  WORD typ_e;			/* type de l'element 			*/
  WORD plig, pcol;		/* Coordonnees element 			*/
  BYTE *lib;			/* chaine 				*/
  WORD val_word, val_word1;	/* 2 words				*/
  BPTR tab_bouton[MAX_BOUT_R_C];/* libelle des radio et check boutons	*/
  WORD ret; 			/* code retour 				*/
  BPTR temp;

#ifdef AIX_VERS
#ifdef AVIION
  TYPF bd_insertc(WORD,WORD,WORD, ...);
#else
  TYPF bd_insertc();
#endif
#else  /* AIX_VERS */
  TYPF bd_insertc();
#endif /* AIX_VERS */

  /* TRAITEMENT */
  /**************/

  /* on teste le nb min d'arguments */

  if(rt_arg.c < NB_ARG_MIN_INS)
    return(Bd_err_arg);

  /* on recupere le nø de la boite */

  if(rt_arg.t[Ins_i_nol] != TYPE_POURCENT)
    return(Bd_err_typ);

#ifdef AIX_VERS
#ifdef SPARC
  temp = (BPTR)rt_arg.v[Ins_i_nol];
  nlog = (WORD)((*temp << 8) + *(temp + 1));
#else
#if dosext || unix
  nlog = *(WPTR)rt_arg.v[Ins_i_nol];
#else
  temp = (BPTR)rt_arg.v[Ins_i_nol];
  nlog = (WORD)((*temp << 8) + *(temp + 1));
#endif
#endif
#else /* AIX_VERS */
#if dosext || unix
  nlog = *(WPTR)rt_arg.v[Ins_i_nol];
#else
  temp = (BPTR)rt_arg.v[Ins_i_nol];
  nlog = (WORD)((*temp << 8) + *(temp + 1));
#endif
#endif /* AIX_VERS */

  /* on recupere les arg communs */

  /* type element */

  if(rt_arg.t[Ins_i_typ] != TYPE_POURCENT)
   return(Bd_err_typ);
#ifdef AIX_VERS
#ifdef SPARC
  temp = (BPTR)rt_arg.v[Ins_i_typ];
  typ_e = (WORD)((*temp << 8) + *(temp + 1));
#else
#if dosext || unix
  typ_e = *(WPTR)rt_arg.v[Ins_i_typ];
#else
  temp = (BPTR)rt_arg.v[Ins_i_typ];
  typ_e = (WORD)((*temp << 8) + *(temp + 1));
#endif
#endif
#else  /* AIX_VERS */
#if dosext || unix
  typ_e = *(WPTR)rt_arg.v[Ins_i_typ];
#else
  temp = (BPTR)rt_arg.v[Ins_i_typ];
  typ_e = (WORD)((*temp << 8) + *(temp + 1));
#endif
#endif /* AIX_VERS */
  /* position element */

  if((rt_arg.t[Ins_i_pli] != TYPE_POURCENT) || (rt_arg.t[Ins_i_pco] != TYPE_POURCENT))
    return(Bd_err_typ);

#ifdef AIX_VERS
#ifdef SPARC
  temp = (BPTR)rt_arg.v[Ins_i_pli];
  plig = (WORD)((*temp << 8) + *(temp + 1));
  temp = (BPTR)rt_arg.v[Ins_i_pco];
  pcol = (WORD)((*temp << 8) + *(temp + 1));
#else
#if dosext || unix
  plig = *(WPTR)rt_arg.v[Ins_i_pli];
  pcol = *(WPTR)rt_arg.v[Ins_i_pco];
#else
  temp = (BPTR)rt_arg.v[Ins_i_pli];
  plig = (WORD)((*temp << 8) + *(temp + 1));
  temp = (BPTR)rt_arg.v[Ins_i_pco];
  pcol = (WORD)((*temp << 8) + *(temp + 1));
#endif
#endif
#else  /* AIX_VERS */
#if dosext || unix
  plig = *(WPTR)rt_arg.v[Ins_i_pli];
  pcol = *(WPTR)rt_arg.v[Ins_i_pco];
#else
  temp = (BPTR)rt_arg.v[Ins_i_pli];
  plig = (WORD)((*temp << 8) + *(temp + 1));
  temp = (BPTR)rt_arg.v[Ins_i_pco];
  pcol = (WORD)((*temp << 8) + *(temp + 1));
#endif
#endif /* AIX_VERS */

  /* on recupere les arguments specifiques et appel fonction C */

  switch(typ_e & ~E_INTERACTIF & ~E_INTERACTIF2)
   {
    case MESSAGE:
      if(rt_arg.c != NB_ARG_MESSAGE)
	return(Bd_err_arg);

      /* recuperation du libelle */

      if(rt_arg.t[Mes_i_lib] != TYPE_CHAINE)
	return(Bd_err_typ);
#ifndef AIX_VERS
      if((lib = allouer((rt_arg.l[Mes_i_lib]) + 1)) == NULL)
#else /* AIX_VERS */
      temp = rt_arg.l[Mes_i_lib];
      temp +=1;
      lib = allouer(temp);
      if (lib  == NULL)
#endif /* AIX_VERS */
	return(werr_mem);
#ifndef AIX_VERS
     for(i = 0; i < rt_arg.l[Mes_i_lib]; i++)
#else /* AIX_VERS */
     for(i = 0; i < temp-1; i++)
#endif /* AIX_VERS */
       lib[i] = ((BPTR)rt_arg.v[Mes_i_lib])[i];
     lib[i] = 0;

      /* appel fonction C */

      ret = bd_insertc(nlog, plig, pcol, typ_e, lib);
      break;

    case BOUTON:

      if(rt_arg.c != NB_ARG_BOUTON)
	return(Bd_err_arg);

      /* recuperation du libelle */

      if(rt_arg.t[Bt_i_title] != TYPE_CHAINE)
	return(Bd_err_typ);
      if((lib = allouer((rt_arg.l[Bt_i_title]) + 1)) == NULL)
 	 return(werr_mem);
      for(i = 0; i < rt_arg.l[Bt_i_title]; i++)
        lib[i] = ((BPTR)rt_arg.v[Bt_i_title])[i];
      lib[i] = 0;

      /* recuperation du code retour */

      if(rt_arg.t[Bt_i_code] != TYPE_POURCENT)
	return(Bd_err_typ);

#ifdef AIX_VERS
#ifdef SPARC
      temp = (BPTR)rt_arg.v[Bt_i_code];
      val_word = (WORD)((*temp << 8) + *(temp + 1));
#else
#if dosext || unix
      val_word = *(WPTR)rt_arg.v[Bt_i_code];
#else
      temp = (BPTR)rt_arg.v[Bt_i_code];
      val_word = (WORD)((*temp << 8) + *(temp + 1));
#endif
#endif
#else  /* AIX_VERS */
#if dosext || unix
      val_word = *(WPTR)rt_arg.v[Bt_i_code];
#else
      temp = (BPTR)rt_arg.v[Bt_i_code];
      val_word = (WORD)((*temp << 8) + *(temp + 1));
#endif
#endif /* AIX_VERS */

      /* Appel fonction C */

      ret = bd_insertc(nlog, plig, pcol, typ_e, lib, val_word);
      libere(lib);
      break;

    case R_BOUTON:

      /* on recupere le nombre des libelles */
      if(rt_arg.t[RB_i_nb] == TYPE_DIESE)
 	     nb = *((BPTR)rt_arg.v[RB_i_nb]);
      else
	if(rt_arg.t[RB_i_nb] == TYPE_POURCENT)
#ifdef AIX_VERS
#ifdef SPARC
	    {
	     temp = (BPTR)rt_arg.v[RB_i_nb];
	     nb  = (WORD)((*temp << 8) + *(temp + 1));
	    }
#else
#if dosext || unix
	     nb = *(WPTR)rt_arg.v[RB_i_nb];
#else
	    {
	     temp = (BPTR)rt_arg.v[RB_i_nb];
	     nb  = (WORD)((*temp << 8) + *(temp + 1));
	    }
#endif
#endif
#else  /* AIX_VERS */
#if dosext || unix
	     nb = *(WPTR)rt_arg.v[RB_i_nb];
#else
	    {
	     temp = (BPTR)rt_arg.v[RB_i_nb];
	     nb  = (WORD)((*temp << 8) + *(temp + 1));
	    }
#endif
#endif /* AIX_VERS */
	else
	  return(Bd_err_typ);

      /* puis la taille */
      if(rt_arg.t[RB_i_size] == TYPE_DIESE)
	      size = *((BPTR)rt_arg.v[RB_i_size]);
      else
	if(rt_arg.t[RB_i_size] == TYPE_POURCENT)
#ifdef AIX_VERS
#ifdef SPARC
	   {
	     temp = (BPTR)rt_arg.v[RB_i_size];
	     size  = (WORD)((*temp << 8) + *(temp + 1));
	   }
#else
#if dosext || unix
	     size = *(WPTR)rt_arg.v[RB_i_size];
#else
	   {
	     temp = (BPTR)rt_arg.v[RB_i_size];
	     size  = (WORD)((*temp << 8) + *(temp + 1));
	   }
#endif
#endif
#else  /* AIX_VERS */
#if dosext || unix
	     size = *(WPTR)rt_arg.v[RB_i_size];
#else
	   {
	     temp = (BPTR)rt_arg.v[RB_i_size];
	     size  = (WORD)((*temp << 8) + *(temp + 1));
	   }
#endif
#endif /* AIX_VERS */
	else
	  return(Bd_err_typ);


      /* suivant la valeur de size, on decoupe ou non la chaine des libelles */
      if(size == 0)
	{
	 /* Appel C */

	 /* test du nombre d'argument */
	 if((rt_arg.c < NB_ARG_R_BOUT+1) || (rt_arg.c > NB_ARG_R_BOUT+MAX_BOUT_R_C-1))
	   return(Bd_err_arg);

	 for(i = 0; i < nb; i++)
	  if(rt_arg.t[RB_i_str+i] != TYPE_CHAINE)
	    return(Bd_err_typ);
	  else
	    {
	     if((temp = f_allouer((rt_arg.l[RB_i_str+i]) + 1)) == NULL)
	       return(werr_mem);

	     for(j = 0; j < rt_arg.l[RB_i_str+i]; j++)
	       temp[j] = ((BPTR)rt_arg.v[RB_i_str+i])[j];
	     temp[j] = 0;
	     tab_bouton[i] = temp;
	    }
	}
      else
	{
	 /* Appel ABAL */

	 /* test du nombre d'arguments */
	 if(rt_arg.c != NB_ARG_R_BOUT)
	   return(Bd_err_arg);

	 if((rt_arg.t[RB_i_str] != TYPE_CHAINE) || ((rt_arg.l[RB_i_str]) < (nb*size)))
	   return(Bd_err_arg);

	 for(i = 0, k = 0; (i < nb) && (k < rt_arg.l[RB_i_str]); i++, k += size)
	   {
	    if((temp = f_allouer(size + 1)) == NULL)
	      return(werr_mem);
	    for(j = 0; j < size; j++)
	      temp[j] = ((BPTR)rt_arg.v[RB_i_str])[j+k];
	    temp[j] = 0;
	    tab_bouton[i] = temp;
	   }
	}

      /* appel fonction C */
      ret = bd_insertc(nlog, plig, pcol, typ_e, (BPTR)tab_bouton, (WORD)i);
      for(k = 0; k < i; k++)
	f_libere(tab_bouton[k]);

      break;


    case C_BOUTON:

      /* on recupere le nombre des libelles */

      if(rt_arg.t[CB_i_nb] == TYPE_DIESE)
          nb = *((BPTR)rt_arg.v[CB_i_nb]);
      else		
	if(rt_arg.t[CB_i_nb] == TYPE_POURCENT)
#ifdef AIX_VERS
#ifdef SPARC
	    {
	     temp = (BPTR)rt_arg.v[CB_i_nb];
	     nb  = (WORD)((*temp << 8) + *(temp + 1));
	    }
#else
#if dosext || unix
	     nb = *(WPTR)rt_arg.v[CB_i_nb];
#else
	    {
	     temp = (BPTR)rt_arg.v[CB_i_nb];
	     nb  = (WORD)((*temp << 8) + *(temp + 1));
	    }
#endif
#endif
#else  /* AIX_VERS */
#if dosext || unix
	     nb = *(WPTR)rt_arg.v[CB_i_nb];
#else
	    {
	     temp = (BPTR)rt_arg.v[CB_i_nb];
	     nb  = (WORD)((*temp << 8) + *(temp + 1));
	    }
#endif
#endif /* AIX_VERS */
	else
	  return(Bd_err_typ);

      /* puis la taille */
      if(rt_arg.t[CB_i_size] == TYPE_DIESE)
	   size = *((BPTR)rt_arg.v[CB_i_size]);
      else
	if(rt_arg.t[CB_i_size] == TYPE_POURCENT)
#ifdef AIX_VERS
#ifdef SPARC
	  {
	   temp = (BPTR)rt_arg.v[CB_i_size];
	   size = (WORD)((*temp << 8) + *(temp + 1));
	  }
#else
#if dosext || unix
	   size = *(WPTR)rt_arg.v[CB_i_size];
#else
	  {
	   temp = (BPTR)rt_arg.v[CB_i_size];
	   size = (WORD)((*temp << 8) + *(temp + 1));
	  }
#endif
#endif
#else  /* AIX_VERS */
#if dosext || unix
	   size = *(WPTR)rt_arg.v[CB_i_size];
#else
	  {
	   temp = (BPTR)rt_arg.v[CB_i_size];
	   size = (WORD)((*temp << 8) + *(temp + 1));
	  }
#endif
#endif /* AIX_VERS */
	else
	  return(Bd_err_typ);

      /* type check_bouton */

      if(rt_arg.t[CB_i_typ] == TYPE_DIESE)
	   type = *((BPTR)rt_arg.v[CB_i_typ]);
      else
	if(rt_arg.t[CB_i_typ] == TYPE_POURCENT)
#ifdef AIX_VERS
#ifdef SPARC
	  {
	   temp = (BPTR)rt_arg.v[CB_i_typ];
	   type = (WORD)((*temp << 8) + *(temp + 1));
	  }
#else
#if dosext || unix
	   type = *(WPTR)rt_arg.v[CB_i_typ];
#else
	  {
	   temp = (BPTR)rt_arg.v[CB_i_typ];
	   type = (WORD)((*temp << 8) + *(temp + 1));
	  }
#endif
#endif
#else  /* AIX_VERS */
#if dosext || unix
	   type = *(WPTR)rt_arg.v[CB_i_typ];
#else
	  {
	   temp = (BPTR)rt_arg.v[CB_i_typ];
	   type = (WORD)((*temp << 8) + *(temp + 1));
	  }
#endif
#endif /* AIX_VERS */
	else
	  return(Bd_err_typ);

      /* suivant la valeur de size, on decoupe ou non la chaine des libelles */
      if(size == 0)
	{
	 /* Appel de C */
	 if((rt_arg.c < NB_ARG_C_BOUT) || (rt_arg.c > NB_ARG_C_BOUT+MAX_BOUT_R_C-1))
	   return(Bd_err_arg);

	 for(i = 0; i < nb; i++)
	   if(rt_arg.t[CB_i_str+i] != TYPE_CHAINE)
	     return(Bd_err_typ);
	   else
	     {
	      if((temp = f_allouer((rt_arg.l[CB_i_str+i]) + 1)) == NULL)
		return(werr_mem);

	      for(j = 0; j < rt_arg.l[CB_i_str+i]; j++)
		temp[j] = ((BPTR)rt_arg.v[CB_i_str+i])[j];
	      temp[j] = 0;
	      tab_bouton[i] = temp;
	     }
	}
      else
	{
	 /* Appel ABAL */

	 /* test du nombre d'arguments */
	 if(rt_arg.c != NB_ARG_C_BOUT)
	   return(Bd_err_arg);

	 if((rt_arg.t[CB_i_str] != TYPE_CHAINE) || ((rt_arg.l[CB_i_str]) < (nb*size)))
	   return(Bd_err_arg);

	 for(i = 0, k = 0; (i < nb) && (k < rt_arg.l[CB_i_str]); i++, k += size)
	   {
	    if((temp = f_allouer(size + 1)) == NULL)
	      return(werr_mem);
	    for(j = 0; j < size; j++)
	      temp[j] = ((BPTR)rt_arg.v[CB_i_str])[j+k];
	    temp[j] = 0;
	    tab_bouton[i] = temp;
	   }
	}

      /* appel fonction C */

      ret = bd_insertc(nlog, plig, pcol, typ_e, (BPTR)tab_bouton, (WORD)i, (WORD)type);

      for(k = 0; k < i; k++)
	f_libere(tab_bouton[k]);

      break;


    case LISTE:


      if(rt_arg.c != NB_ARG_LISTE)
	return(Bd_err_arg);

      /* recup nø liste */

      if(rt_arg.t[Li_i_nol] != TYPE_POURCENT)
	return(Bd_err_typ);
#ifdef AIX_VERS
#ifdef SPARC
      temp = (BPTR)rt_arg.v[Li_i_nol];
      val_word = (WORD)((*temp << 8) + *(temp + 1));
#else
#if dosext || unix
      val_word = *(WPTR)rt_arg.v[Li_i_nol];
#else
      temp = (BPTR)rt_arg.v[Li_i_nol];
      val_word = (WORD)((*temp << 8) + *(temp + 1));
#endif
#endif
#else  /* AIX_VERS */
#if dosext || unix
      val_word = *(WPTR)rt_arg.v[Li_i_nol];
#else
      temp = (BPTR)rt_arg.v[Li_i_nol];
      val_word = (WORD)((*temp << 8) + *(temp + 1));
#endif
#endif /* AIX_VERS */
      /* appel fonction C */

      ret = bd_insertc(nlog, plig, pcol, typ_e, val_word);

      break;

    case SAISIE:


      if(rt_arg.c != NB_ARG_SAISIE)
	return(Bd_err_arg);

      /* recup nb colonnes */

      if(rt_arg.t[Sai_i_nco] != TYPE_POURCENT)
	return(Bd_err_typ);

#ifdef AIX_VERS
#ifdef SPARC
      temp = (BPTR)rt_arg.v[Sai_i_nco];
      val_word = (WORD)((*temp << 8) + *(temp + 1));
#else
#if dosext || unix
      val_word = *(WPTR)rt_arg.v[Sai_i_nco];
#else
      temp = (BPTR)rt_arg.v[Sai_i_nco];
      val_word = (WORD)((*temp << 8) + *(temp + 1));
#endif
#endif
#else  /* AIX_VERS */
#if dosext || unix
      val_word = *(WPTR)rt_arg.v[Sai_i_nco];
#else
      temp = (BPTR)rt_arg.v[Sai_i_nco];
      val_word = (WORD)((*temp << 8) + *(temp + 1));
#endif
#endif /* AIX_VERS */
      /* recup nb caracteres */

      if(rt_arg.t[Sai_i_nca] != TYPE_POURCENT)
	return(Bd_err_typ);
#ifdef AIX_VERS
#ifdef SPARC
      temp = (BPTR)rt_arg.v[Sai_i_nca];
      val_word1 = (WORD)((*temp << 8) + *(temp + 1));
#else
#if dosext || unix
      val_word1 = *(WPTR)rt_arg.v[Sai_i_nca];
#else
      temp = (BPTR)rt_arg.v[Sai_i_nca];
      val_word1 = (WORD)((*temp << 8) + *(temp + 1));
#endif
#endif
#else  /* AIX_VERS */
#if dosext || unix
      val_word1 = *(WPTR)rt_arg.v[Sai_i_nca];
#else
      temp = (BPTR)rt_arg.v[Sai_i_nca];
      val_word1 = (WORD)((*temp << 8) + *(temp + 1));
#endif
#endif /* AIX_VERS */
      /* appel fonction C */

      ret = bd_insertc(nlog, plig, pcol, typ_e, val_word, val_word1);
      break;

    case AIDE:

      if(rt_arg.c != NB_ARG_AIDE)
	return(Bd_err_arg);

      /* recuperation du libelle */

      if(rt_arg.t[Aid_i_lib] != TYPE_CHAINE)
	return(Bd_err_typ);
      if((lib = allouer((rt_arg.l[Aid_i_lib]) + 1)) == NULL)
	return(werr_mem);
      for(i = 0; i < rt_arg.l[Aid_i_lib]; i++)
	lib[i] = ((BPTR)rt_arg.v[Aid_i_lib])[i];
      lib[i] = 0;

      /* appel fonction C */

      ret = bd_insertc(nlog, plig, pcol, typ_e, lib);
      libere(lib);
      break;

    case FUNFREE:

      if(rt_arg.c != NB_ARG_FUN)
	return(Bd_err_arg);

      /* recup nø fenetre */

      if(rt_arg.t[Fun_i_nol] != TYPE_POURCENT)
	return(Bd_err_typ);

#ifdef AIX_VERS
#ifdef SPARC
      temp = (BPTR)rt_arg.v[Fun_i_nol];
      val_word = (WORD)((*temp << 8) + *(temp + 1));
#else
#if dosext || unix
      val_word = *(WPTR)rt_arg.v[Fun_i_nol];
#else
      temp = (BPTR)rt_arg.v[Fun_i_nol];
      val_word = (WORD)((*temp << 8) + *(temp + 1));
#endif
#endif
#else  /* AIX_VERS */
#if dosext || unix
      val_word = *(WPTR)rt_arg.v[Fun_i_nol];
#else
      temp = (BPTR)rt_arg.v[Fun_i_nol];
      val_word = (WORD)((*temp << 8) + *(temp + 1));
#endif
#endif /* AIX_VERS */
      /* appel fonction C */

      ret = bd_insertc(nlog, plig, pcol, typ_e, val_word);
      break;




    default:
      ret = Bd_err_type;

   }/*switch*/

  /* Termine */

  return(ret);


}/*BD_INSERT*/







/*-------------------------------------------------------
   Fonction d'ajout d'un element a une boite de dialogue
   APPEL C

   Entree :

	- nlog  : Nø logique du dialog
	- plig  : position ligne de l'element (relatif)
	- pcol  : position colonne
	- typ_e : type de l'element a ajouter

   Les arguments specifiques sont passes en VA_ARG.


   Sortie :

	- code


   Traitement :

	recuperation boite de dialog
	verif ajout d'un element possible
	recuperation et controle des arguments
	initialisation de l'element

	FIN

  --------------------------------------------------------*/

#ifdef OSF1
TYPF bd_insertc(va_alist)
	va_dcl;
{	/* variables locales */
	WORD nlog;
	WORD plig;
	WORD pcol;
	WORD typ_e;
#else /* NOT OSF1 */
#ifndef AIX_VERS
#ifdef SCO
TYPF bd_insertc(WORD nlog,WORD plig,WORD pcol,WORD typ_e,...)
#else /* SCO */
TYPF bd_insertc(nlog,plig,pcol,typ_e)
WORD nlog;
WORD plig;
WORD pcol;
WORD typ_e;
#endif /* NOT SCO */


#else /* AIX_VERS */
#ifdef R4000
TYPF bd_insertc(nlog,plig,pcol,typ_e,va_alist)
WORD nlog;
WORD plig;
WORD pcol;
WORD typ_e;
va_dcl
#else /* NOT R4000 */
#if defined(SPARC) || defined(AVIION) || defined(UNIXWARE)
TYPF bd_insertc(WORD nlog, WORD plig, WORD pcol, WORD typ_e, ...)
#else 
TYPF bd_insertc(nlog,plig,pcol,typ_e)
WORD nlog;
WORD plig;
WORD pcol;
WORD typ_e;
#endif /* SPARC ... */
#endif /* R4000 */
#endif /* AIX_VERS */
#endif /* OSF1 */
{
  /* variables locales */
  va_list l_arg;		/* liste des parametres 		*/
  BYTE nb, i_elem, caract;
  WORD size;			/* taille valeur d'une liste		*/
  WORD w_d, h_d;		/* largeur et hauteur du dialogue 	*/
  B_DIAL_PTR b_cour_ptr;	/* ptr sur boite courante 		*/
  DATA_ELEM_PTR elem_ptr;	/* ptr sur data_elem de l'element 	*/
  WORD val_byte, val_byte2;	/* un byte et un autre byte		*/
  WORD val_word;		/* un word				*/
  BPTR lib;                   	/* un ptr chaine			*/
  BPTR *tab_ptr;		/* un pointeur sur tableau de ptr	*/
  WORD ret;
  WORD i;

  /* TRAITEMENT */
  /**************/


  /* verification init */

  if(fen_ini != 2)
    return(werr_ini);

  /* init liste arguments */

#ifdef OSF1
	/* recup premiers arguments */
	va_start(l_arg);
	nlog = (WORD) va_arg(l_arg,WORD);
	plig = (WORD) va_arg(l_arg,WORD);
	pcol = (WORD) va_arg(l_arg,WORD);
	typ_e = (WORD) va_arg(l_arg,WORD);
#else
#ifdef BOS
  va_start(l_arg);
#else
  va_start(l_arg, typ_e);
#endif
#endif

  /* recherche pointeur sur boite de dialogue */

  for(nb = 0; nb < MAX_DIAL; nb++)
    if(TB_BOX[nb].no_log == nlog)
      break;

  if((nb == MAX_DIAL) || (nlog <= 0))
    return(Bd_err_nobd);  /* boite non trouvee */
  b_cour_ptr = TB_BOX[nb].dial;

  /* on regarde si insert possible */

/*llb19  if(b_cour_ptr->nb_elem == MAX_ELEM) */
  if(b_cour_ptr->nb_elem == b_cour_ptr->max_elem )
    return(Bd_err_maxel);

  /* verification position element */

  if((plig <= 0) || (pcol <= 0) ||
     (plig > b_cour_ptr->h) || (pcol > b_cour_ptr->w))
    return(Bd_err_pos);


  /* initialisation de la struct DATA_ELEM de l'element */

  if((elem_ptr = (DATA_ELEM_PTR)f_allouer(sizeof(DATA_ELEM))) == NULL)
    return(werr_mem);

  elem_ptr->x = pcol;
  elem_ptr->y = plig;
  elem_ptr->o_v = b_cour_ptr->y;
  elem_ptr->o_h = b_cour_ptr->x;
  elem_ptr->data_ptr = &(b_cour_ptr->data_box)[b_cour_ptr->i_data];
  elem_ptr->v_g = 0; elem_ptr->v_d = 0; elem_ptr->v_h = 0; elem_ptr->v_b = 0;
  elem_ptr->equi_c = (EQUIV_PTR)&(b_cour_ptr->bd_equiv);

  i_elem = b_cour_ptr->nb_elem;
  (b_cour_ptr->bd_aig[i_elem]).dat_elem = elem_ptr;

  /* initialisation du mode (interactif ou non) */

  
  if (typ_e & E_INTERACTIF)
	  elem_ptr->mode_inter = ACTIF;
  else
  if (typ_e & E_INTERACTIF2)
	  elem_ptr->mode_inter = ACTIF2;
  else
	  elem_ptr->mode_inter = INACTIF;

  /* initialisation de l'element */

  w_d = b_cour_ptr->w;
  h_d = b_cour_ptr->h;

  switch(typ_e & ~E_INTERACTIF & ~E_INTERACTIF2)
   {
    case MESSAGE:
      lib = va_arg(l_arg, BPTR);
      va_end(l_arg);

      if((ret = init_message(nlog, elem_ptr, w_d, h_d, lib)) != No_err)
	break;
      (b_cour_ptr->bd_aig[i_elem]).traitement = NULL; /* pas de traitement */

      break;

    case BOUTON:
      lib = va_arg(l_arg, BPTR);
      val_byte = (WORD) va_arg(l_arg, int);
      va_end(l_arg);

      /* initialisation du bouton */

      if((ret = init_bouton(nlog, elem_ptr, w_d, h_d, lib, val_byte)) != No_err)
	break;
      (b_cour_ptr->bd_aig[i_elem]).traitement = (void_ptr)trait_bouton;

      elem_ptr->mode_inter = ACTIF;

      /* update table equivalence clavier pour le bouton */

      if((caract = ((DESC_BOUTON_PTR)elem_ptr->desc_elem)->car_ex) != 0)
        {
	 ((b_cour_ptr->bd_equiv).tab_eq[(b_cour_ptr->bd_equiv).nb_eq]).car = Maj(caract);
	 ((b_cour_ptr->bd_equiv).tab_eq[(b_cour_ptr->bd_equiv).nb_eq]).no_elem = i_elem + 1;
	 (b_cour_ptr->bd_equiv).nb_eq += 1;
	}

      /* update data_box */

      b_cour_ptr->i_data += Nb_data_bouton;
      break;

    case R_BOUTON:
      tab_ptr = (BPTR *)va_arg(l_arg, BPTR);	/* ptr sur table des lib*/
      val_byte = (BYTE)va_arg(l_arg, int);	/* nb de radio_boutons	*/

      va_end(l_arg);

      /* controle nb de radio_boutons */

      if(val_byte > MAX_BOUT_R_C)
	return(Bd_err_pos);

      /* initalisation du radio_bouton */

      if((ret = init_r_bouton(nlog, b_cour_ptr->stf_bd, elem_ptr, w_d, h_d, (BYTE)val_byte, (BPTR)tab_ptr)) != No_err)
	break;
      (b_cour_ptr->bd_aig[i_elem]).traitement =(void_ptr)trait_r_bouton;

      /* update data_box */

      b_cour_ptr->i_data += Nb_data_r_bouton;
      break;


    case C_BOUTON:
      tab_ptr = (BPTR *)va_arg(l_arg, BPTR);	/* ptr sur table des lib*/
      val_byte = (BYTE)va_arg(l_arg, int);	/* nb de check_boutons	*/
      val_byte2 = (BYTE)va_arg(l_arg, int);	/* type check_bouton	*/

      va_end(l_arg);

      /* controle nb de check_boutons */

      if(val_byte > MAX_BOUT_R_C)
	return(Bd_err_pos);

      /* initialisation du check_bouton */

      if((ret = init_c_bouton(nlog, b_cour_ptr->stf_bd, elem_ptr, w_d, h_d, (BYTE)val_byte2, (BYTE)val_byte, (BPTR)tab_ptr)) != No_err)
	break;
      (b_cour_ptr->bd_aig[i_elem]).traitement = (void_ptr)trait_c_bouton;

      /* update data_box */

      b_cour_ptr->i_data += Nb_data_c_bouton;
      break;

    case LISTE:

      val_word = (WORD)va_arg(l_arg, int);
      va_end(l_arg);

      /* initialisation de la liste */

      if((ret = init_liste(nlog, elem_ptr, b_cour_ptr->x, b_cour_ptr->y, w_d, h_d, &size, val_word)) != No_err)
	break;
      (b_cour_ptr->bd_aig[i_elem]).traitement = (void_ptr)trait_liste;
      /* update data_box */

      b_cour_ptr->i_data += Nb_data_liste + ((size - 1) * sizeof(BYTE));

      break;

    case SAISIE:

      val_byte = (WORD)va_arg(l_arg, int);
      val_byte2 = (WORD)va_arg(l_arg, int);
      va_end(l_arg);

      /* initialisation de la saisie */

      if((ret = init_saisie(nlog, b_cour_ptr->stf_bd, elem_ptr, b_cour_ptr->x, b_cour_ptr->y, w_d, h_d, val_byte, val_byte2)) != No_err)
	break;
      (b_cour_ptr->bd_aig[i_elem]).traitement = (void_ptr)trait_saisie;

      /* initialisation ptr sur copie de la saisie dans copie de data_box */

      ((DESC_SAISIE_PTR)elem_ptr->desc_elem)->sauve_sais = &(b_cour_ptr->data_box_c[b_cour_ptr->i_data + I_val_saisie]);


      /* update data_box */

      b_cour_ptr->i_data += Nb_data_saisie + ((val_byte2 - 1) * sizeof(BYTE));

      break;



    case AIDE:
      lib = va_arg(l_arg, BPTR);
      va_end(l_arg);

      /* initialisation du bouton d'aide */

      if((ret = init_aide(nlog, elem_ptr, w_d, h_d, lib)) != No_err)
	break;
      (b_cour_ptr->bd_aig[i_elem]).traitement = (void_ptr)trait_aide;

      elem_ptr->mode_inter = INACTIF;

      /* update table equivalence clavier pour le bouton d'aide */

      if((caract = ((DESC_AIDE_PTR)elem_ptr->desc_elem)->car_ex) != 0)
	{
	 ((b_cour_ptr->bd_equiv).tab_eq[(b_cour_ptr->bd_equiv).nb_eq]).car = Maj(caract);
      	 ((b_cour_ptr->bd_equiv).tab_eq[(b_cour_ptr->bd_equiv).nb_eq]).no_elem = i_elem + 1;
      	 (b_cour_ptr->bd_equiv).nb_eq += 1;
	}

      break;



    case FUNFREE:

      val_word = (WORD)va_arg(l_arg, int);
      va_end(l_arg);

      /* initialisation de la fenetre */

      if((ret = init_fun(nlog, elem_ptr, b_cour_ptr->x, b_cour_ptr->y, w_d, h_d, val_word)) != No_err)
	break;
      (b_cour_ptr->bd_aig[i_elem]).traitement = (void_ptr)trait_fun;

      /* update data_box */

      b_cour_ptr->i_data += Nb_data_f_free;

      break;




    default:
      ret = Bd_err_type;

   }/*switch*/

  /* on verifie que la data_box ne deborde pas */
  /* si debordement, on libere la place des data_elem du dernier element */
/*llb19*/
  if((ret == No_err) && (b_cour_ptr->i_data >= b_cour_ptr->len_box /*DIM_DATA_BOX*/))
    if(((b_cour_ptr->bd_aig[i_elem]).dat_elem)->desc_elem != NULL)
      {
       lib = (BPTR)(((b_cour_ptr->bd_aig[i_elem]).dat_elem)->desc_elem);
       f_libere(lib);
       ret = Bd_err_data;
      }


  /* on verifie qu'il n'y a pas d'erreur */

  if(ret != No_err)
    {
     f_libere(elem_ptr);
     return(ret);
    }

  /* on met a jour le nb d'elements */

  b_cour_ptr->nb_elem += 1;

  /* termine */

  return(No_err);

}/*BD_INSERTC*/





/* definition des indices des arg dans rt_arg pour dialog */

#define NB_ARG_DIAL	3

#define Dia_i_nol	0		/* indice nø logique boite 	*/
#define Dia_i_elem	1		/* indice nø element 		*/
#define Dial_i_exit	2		/* indice var de sortie		*/
#define Dial_i_prov	3		/* indice var de provenace	*/


/*-------------------------------------------------------
   Fonction dialogue
   APPEL ABAL

   Entree : ()

   On recupere les arguments dans la structure rt_arg

	- nlog  : Nø logique du dialog
	- elem  : element actif
	- exit	: adresse variable de sortie


   Sortie :

	- code


   Traitement :

	recuperation et controle des arguments
	appel fonction C

	FIN

  --------------------------------------------------------*/

TYPF bd_use()
{


  /* variables locales */

  WORD nlog;			/* no logique dialogue 			*/
  WORD elem;			/* nø de l'element actif		*/
  WPTR exit;
  WORD ret;
  BPTR temp;
  WPTR prov_exit;
  WORD prov;

#ifdef AIX_VERS
#ifdef SPARC
  short sortie;
#endif
#endif /* AIX_VERS */
  /* TRAITEMENT */
  /**************/

  /* on teste le nb min d'arguments */

  if(rt_arg.c < NB_ARG_DIAL)
    return(Bd_err_arg);

  /* on recupere le nø de la boite */

  if(rt_arg.t[Dia_i_nol] != TYPE_POURCENT)
    return(Bd_err_typ);

#ifdef AIX_VERS
#ifdef SPARC
  temp = (BPTR)rt_arg.v[Dia_i_nol];
  nlog = (WORD)((*temp << 8) + *(temp + 1));
#else
#if dosext || unix
  nlog = *(WPTR)rt_arg.v[Dia_i_nol];
#else
  temp = (BPTR)rt_arg.v[Dia_i_nol];
  nlog = (WORD)((*temp << 8) + *(temp + 1));
#endif
#endif
#else  /* AIX_VERS */
#if dosext || unix
  nlog = *(WPTR)rt_arg.v[Dia_i_nol];
#else
  temp = (BPTR)rt_arg.v[Dia_i_nol];
  nlog = (WORD)((*temp << 8) + *(temp + 1));
#endif
#endif /* AIX_VERS */
  /* on recupere le nø de l'element actif */

  if(rt_arg.t[Dia_i_elem] != TYPE_POURCENT)
   return(Bd_err_typ);

#ifdef AIX_VERS
#ifdef SPARC
  temp = (BPTR)rt_arg.v[Dia_i_elem];
  elem = (WORD)((*temp << 8) + *(temp + 1));
#else
#if dosext || unix
  elem = *(WPTR)rt_arg.v[Dia_i_elem];
#else
  temp = (BPTR)rt_arg.v[Dia_i_elem];
  elem = (WORD)((*temp << 8) + *(temp + 1));
#endif
#endif
#else  /* AIX_VERS */
#if dosext || unix
  elem = *(WPTR)rt_arg.v[Dia_i_elem];
#else
  temp = (BPTR)rt_arg.v[Dia_i_elem];
  elem = (WORD)((*temp << 8) + *(temp + 1));
#endif

#endif /* AIX_VERS */
  /* l'adresse de retour */

  if(rt_arg.t[Dial_i_exit] != (TYPE_POURCENT | MODIFIABLE))
    return(Bd_err_typ);
  exit = rt_arg.v[Dial_i_exit];

  if(rt_arg.c == NB_ARG_DIAL+1)		/** arg optionnel prov_exit */
    {
	  if ( (rt_arg.t[Dial_i_prov] != (TYPE_POURCENT | MODIFIABLE))
	     &&(rt_arg.t[Dial_i_prov] != (TYPE_DIESE | MODIFIABLE)) )
	    return(Bd_err_typ);
/*	  prov_exit = rt_arg.v[Dial_i_prov];*/
  }
/****
  else
	prov_exit = &prov;

****/
  prov_exit = &prov;

  /* Appel fonction C */

  ret = bd_usec(nlog ,elem, exit, prov_exit);
  temp = (BPTR)exit;
#ifdef AIX_VERS
#ifdef SPARC
  sortie = (WORD)((*temp << 8) + *(temp + 1));
  memcpy(exit,&sortie,sizeof(WORD));
#else
  *exit= (WORD)((*temp << 8) + *(temp + 1));
#endif
#else  /* AIX_VERS */
  *exit= (WORD)((*temp << 8) + *(temp + 1));
#endif /* AIX_VERS */

  if(rt_arg.c == NB_ARG_DIAL+1)		/* arg optionnel prov_exit */
    {
     if  (rt_arg.t[Dial_i_prov] == (TYPE_POURCENT | MODIFIABLE))
	 *(WPTR)rt_arg.v[Dial_i_prov] = prov;
     else	
	 *(BPTR)rt_arg.v[Dial_i_prov] = (BYTE)prov;
  }

  return(ret);

}/*BD_USE*/






/*-------------------------------------------------------
   Fonction dialogue
   APPEL C

   Entree :

	- nol   : Nø logique du dialog
	- elem  : element actif


   Sortie :

	- code


   Traitement :


	FIN

  --------------------------------------------------------*/



TYPF bd_usec(nol,elem,exit,prov_exit)
WORD nol;
WORD elem;
WPTR exit;
WPTR prov_exit;
{

  /* variables */


  BYTE elem_c, sauv_elem;	/* element courant et precedent		*/
  BYTE elem_m;
  BYTE fl_action;		/* flag de traitement type ACTION	*/
  B_DIAL_PTR b_cour_ptr;        /* ptr sur boite courante 		*/
  WORD nb;
  SWORD ret, (* f_trait)();
  WITEM	*wi;
  WDESC_PTR wd;
#ifdef AIX_VERS
#ifdef SPARC
  WORD sortie;
#endif
#endif /* AIX_VERS */

  /* TRAITEMENT */
  /**************/

  /* verification init */

  if(fen_ini != 2)
    return(werr_ini);

  /* recherche pointeur sur boite de dialog */

  for(nb = 0; nb < MAX_DIAL; nb++)
    if(TB_BOX[nb].no_log == nol)
      break;

  if((nb == MAX_DIAL) || (nol <= 0))
    return(Bd_err_nobd);  /* boite non trouvee */
  b_cour_ptr = TB_BOX[nb].dial;

  /* recherche si existe element */

  if((elem <= 0) || (elem > b_cour_ptr->nb_elem))
    return(Bd_err_noel);

  /* affichage de la fenetre si non fait (interaction) et gel du dialogue 	*/
  /* RAZ des events si premiere utilisation 					*/

   wi=WLOG[nol-1];
   wd = wi->wdesc_ptr;		/* descripteur fenetre */
   if (wd->control & INVISIBLE)
      wselect(nol);

  wfgen(nol, 11);
  if(b_cour_ptr->fl_aff == FALSE)
    {
     wvis(nol);
     b_cour_ptr->fl_aff = TRUE;
     event.event = NO_EVENT;
    }

  wgel(nol);

  /* activation de la boite de dialogue : INIT de tous les elements */


  for(nb = 0; nb < b_cour_ptr->nb_elem; nb++)
    {
     f_trait = (SWORD (*)())((b_cour_ptr->bd_aig[nb]).traitement);
     if(f_trait != NULL)
       if ((ret = (* f_trait)(nol, INIT, (b_cour_ptr->bd_aig[nb]).dat_elem, prov_exit)) != No_err)
	 return(ret);
    }

  /* Verification ouverture dialogue possible				*/
  /* on teste la presence d'un element en mode interaction et actif 	*/

  for(nb = 0; nb < b_cour_ptr->nb_elem; nb++)
    if((((b_cour_ptr->bd_aig[nb]).dat_elem)->etat == ACTIF) &&
       (((b_cour_ptr->bd_aig[nb]).dat_elem)->mode_inter == ACTIF))
      break;
  if(nb == b_cour_ptr->nb_elem)
    {
     bd_closec(nol);
     return(Bd_err_nonact);
    }

  /* on sauvegarde data_box dans data_box_c */

  for(nb = 0; nb < b_cour_ptr->i_data; nb++)
    b_cour_ptr->data_box_c[nb] = b_cour_ptr->data_box[nb];


  /* on effectue le calcul des relations de voisinage */
/*llb19*/
  calc_elem(b_cour_ptr->bd_aig, b_cour_ptr->nb_elem, b_cour_ptr->max_elem);

  /* degel du dialogue */
  wvis(nol);

  /* affichage OK, on rend le dialogue mouse_sensitive */
  put_item_mouse_list(nol);

  /* appel de la fonction de traitement de l'element actif 			*/
  /* on teste si un element est pointe par la souris (retour d'interaction)	*/

  if((event.event != NO_EVENT) && (event.event != KEYBOARD))
    if((elem_m = find_elem_on_mouse(b_cour_ptr, (EVENT_PTR)&event)) != 0)
      elem_c = elem_m - 1;
    else
      {
       elem_c = elem - 1;
       event.event = NO_EVENT;
      }
  else
    {
      elem_c = elem - 1;
      ret = D_SUIVANT;
  }

  fl_action = FALSE;
  sauv_elem = elem_c;

  Wkup_in();
  while(1)
    {
     f_trait = (SWORD (*)())((b_cour_ptr->bd_aig[elem_c]).traitement);
     if((f_trait != NULL) &&
	(((b_cour_ptr->bd_aig[elem_c]).dat_elem)->etat == ACTIF))
       {
	ret = (* f_trait)(nol, ((fl_action == TRUE) ? ACTION : TRAIT), (b_cour_ptr->bd_aig[elem_c]).dat_elem, prov_exit);
	fl_action = FALSE;

	switch(ret)
	  {
	   case VALIDER:
	     bd_closec(nol);
#ifdef AIX_VERS
#ifdef SPARC
	     memcpy(exit,&ret,sizeof(WORD));	
#else
	     *exit = ret;
#endif
#else  /* AIX_VERS */
	     *exit = ret;
#endif /* AIX_VERS */
	     Wkup_out();	
	     return(No_err);

	   case D_ESCAPE:
	   case ANNULER:
	     /* on restaure data_box */

	     for(nb = 0; nb < b_cour_ptr->i_data; nb++)
	       b_cour_ptr->data_box[nb] = b_cour_ptr->data_box_c[nb];

	     bd_closec(nol);
#ifdef AIX_VERS
#ifdef SPARC
	     sortie = ANNULER;	
	     memcpy(exit,&sortie,sizeof(WORD));
#else
	     *exit = ANNULER;
#endif
#else  /* AIX_VERS */
	     *exit = ANNULER;
#endif /* AIX_VERS */
	     Wkup_out();
	     return(No_err);

	   case D_SUIVANT:
	   case D_PRECEDENT:
	     /* on regarde si la sortie est provoquee par la mouse 	*/

	     if((event.event != NO_EVENT) && (event.event != KEYBOARD))
	       /* on recherche l'element situe sous la souris		*/
	       /* si on ne trouve pas, on reactive l'element courant	*/

	       if((elem_m = find_elem_on_mouse(b_cour_ptr, (EVENT_PTR)&event)) != 0)
		 {
		  elem_c = elem_m - 1;
		  break;
		 }
	       else
		 {
		  event.event = NO_EVENT;
		  break;
		 }

	     event.event = NO_EVENT;
	     if ( ret == D_SUIVANT)
		elem_c = next_elem(b_cour_ptr, elem_c);
	     else
		elem_c = prev_elem(b_cour_ptr, elem_c);

	     break;

	   case D_GAUCHE:
	     elem_c = (b_cour_ptr->bd_aig[elem_c].dat_elem)->v_g - 1;
	     break;

	   case D_DROIT:
	     elem_c = (b_cour_ptr->bd_aig[elem_c].dat_elem)->v_d - 1;
	     break;

	   case D_HAUT:
	     elem_c = (b_cour_ptr->bd_aig[elem_c].dat_elem)->v_h - 1;
	     break;

	   case D_BAS:
	     elem_c = (b_cour_ptr->bd_aig[elem_c].dat_elem)->v_b - 1;
	     break;

	   case D_INTERACTION:
#ifdef AIX_VERS
#ifdef SPARC
	     sortie = -(elem_c+1);
	     memcpy(exit,&sortie,sizeof(WORD));
#else	
	     *exit = -(elem_c + 1);
#endif
#else  /* AIX_VERS */
	     *exit = -(elem_c + 1);
#endif /* AIX_VERS */
	     Wkup_out();	
	     return(No_err);

	   case D_OLD:
	     elem_c = sauv_elem;
	     break;

	   default:

	     /* test si sortie sur un bouton */

	     if(ret > 0)
	       {
#ifdef AIX_VERS
#ifdef SPARC
		memcpy(exit,&ret,sizeof(WORD));
#else
		*exit = ret;
#endif
#else  /* AIX_VERS */
		*exit = ret;
#endif /* AIX_VERS */
		Wkup_out();
		return(No_err);
	       }

	     /* test si sortie sur equivalence caractere */

	     if((ret < D_EQUIV) && (ret >= (D_EQUIV - b_cour_ptr->nb_elem )))
	       {
		sauv_elem = elem_c;
		elem_c = -(ret - D_EQUIV + 1);
		fl_action = TRUE;
		break;
	       }
	     else
	       /* test si touche d'echappement */

	       if((ret < D_TCH_ESC) && (ret >= (D_TCH_ESC - NB_MAX_TCH_ESC - 1)))
		 {
#ifdef AIX_VERS
#ifdef SPARC
 		  sortie = -(((-(ret - D_TCH_ESC)) << 8) + elem_c + 1);
		  memcpy(exit,&sortie,sizeof(WORD));
#else
		  *exit = -(((-(ret - D_TCH_ESC)) << 8) + elem_c + 1);
#endif
#else  /* AIX_VERS */
		  *exit = -(((-(ret - D_TCH_ESC)) << 8) + elem_c + 1);
#endif /* AIX_VERS */
		  Wkup_out();
		  return(No_err);
		 }
	       else {
		   Wkup_out();
		   return(Bd_err_non_imp);
		}
	  }/*SWITCH*/

	}
     else
	if ( ret == D_SUIVANT)
		elem_c = next_elem(b_cour_ptr, elem_c);
	else
		elem_c = prev_elem(b_cour_ptr, elem_c);

    }/*WHILE*/

}/*BD_USEC*/





/*-------------------------------------------------------
   Fonction de service next_elem

   Description :
    Recherche du prochain element a activer

   Entree :

	- b_cour_ptr : ptr sur table d'aiguillage
	- elem_c     : element courant actif


   Sortie :

	- element suivant a activer


  --------------------------------------------------------*/


BYTE next_elem(b_cour_ptr,elem_c)
B_DIAL_PTR b_cour_ptr;
BYTE elem_c;
{
  if((elem_c+1) > b_cour_ptr->nb_elem-1)
    return(0);

  return(elem_c+1);

}/* NEXT_ELEM */


/*-------------------------------------------------------
   Fonction de service prev_elem

   Description :
    Recherche de l'element precedent a activer

   Entree :

	- b_cour_ptr : ptr sur table d'aiguillage
	- elem_c     : element courant actif


   Sortie :

	- element precedent a activer


  --------------------------------------------------------*/


BYTE prev_elem(b_cour_ptr, elem_c)
B_DIAL_PTR b_cour_ptr;
BYTE elem_c;
{
  if(elem_c == 0)
    return(b_cour_ptr->nb_elem-1);
  return(elem_c-1);

}/*PREV_ELEM*/







/*-------------------------------------------------------
   Fonction de service find_elem_on_mouse

   Description :
    Recherche de l'element situe sous la souris

   Entree :

	- b_cour_ptr : ptr sur table d'aiguillage
	- event      : dernier evenement


   Sortie :

	- element+1 a activer ou 0


  --------------------------------------------------------*/


BYTE find_elem_on_mouse(B_DIAL_PTR b_cour_ptr, EVENT_PTR event)
{
  BYTE i;
  SWORD x_m, y_m;   	/* coordonnees souris (relatives)		*/
  DATA_ELEM_PTR dat;


  /* on teste si la souris est dans le dialogue */
  y_m = event->plig - b_cour_ptr->y + 1;
  x_m = event->pcol - b_cour_ptr->x + 1;

  if((y_m < 0) || (x_m <= 0) || (y_m > b_cour_ptr->h) || (x_m > b_cour_ptr->w))
    return(0);

  /* on est dans le dialogue, on cherche l'element */

  for(i = 0; i <  b_cour_ptr->nb_elem; i++)
    {
     dat = (b_cour_ptr->bd_aig[i]).dat_elem;
     if((dat->etat == ACTIF) &&
	(y_m >= dat->y) && (x_m >= dat->x) &&
	(y_m < (dat->y+dat->h)) && (x_m < (dat->x+dat->w)))
       return(i+1);
    }

  return(0);

}



/* definition des structures necessaires au calcul du voisinage des elements */


typedef struct {
		WORD n_el;  	/* nø element voisin			*/
		WORD dist;	/* distance				*/
	       } VOISIN;



typedef struct {
		VOISIN gauche;
		VOISIN droite;
		VOISIN haut;
		VOISIN bas;
	       } VOISINAGE;




/*-------------------------------------------------------
   Fonction de service calc_elem

   Description :
     Calcul des relations de voisinage entre les differents
     elements d'un dialogue


   Entree :

	- tab_elem : table d'aiguillage du dialogue
	- nb_elem  : nombre d'elements du dialogue


   Sortie :


  --------------------------------------------------------*/

VOID calc_elem(tab_elem,nb_elem,max_elem)
AIG_PTR tab_elem;
BYTE nb_elem;
WORD max_elem;
{
  BYTE i, j;
  WORD elem;
  WORD x0i, y0i, x1i, y1i, x0j, y0j, x1j, y1j;
  DATA_ELEM_PTR elem_i;
  DATA_ELEM_PTR elem_j;

/*  VOISINAGE tab_dir[MAX_ELEM2];*/	/* tablo dimension max */
  VOISINAGE FAR * tab_dir;			/* tablo dimension max */

  tab_dir = f_allouer(sizeof(VOISINAGE)*MAX_ELEM2);




/*llb19  for(i = 0; i < MAX_ELEM; i++)*/
  for(i = 0; i < max_elem; i++)
    {

     tab_dir[i].gauche.n_el = 0;
     tab_dir[i].droite.n_el = 0;
     tab_dir[i].haut.n_el = 0;
     tab_dir[i].bas.n_el = 0;

     tab_dir[i].gauche.dist = 0;
     tab_dir[i].droite.dist = 0;
     tab_dir[i].haut.dist = 0;
     tab_dir[i].bas.dist = 0;
/*
     tab_dir[i]->gauche->n_el = 0;
     tab_dir[i]->droite->n_el = 0;
     tab_dir[i]->haut->n_el = 0;
     tab_dir[i]->bas->n_el = 0;

     tab_dir[i]->gauche->dist = 0;
     tab_dir[i]->droite->dist = 0;
     tab_dir[i]->haut->dist = 0;
     tab_dir[i]->bas->dist = 0;
*/
    }



  for(i = 0; i < nb_elem; i++)
    {
     elem_i = tab_elem[i].dat_elem;

     /* test si element actif */

    if(elem_i->etat != ACTIF)
       continue;

     x0i = elem_i->x; y0i = elem_i->y;
     x1i = x0i + elem_i->w - 1;
     y1i = y0i + elem_i->h - 1;


     /* on regarde pour les n-i elements suivants */

     for(j = i + 1; j < nb_elem; j++)
       {
	elem_j = tab_elem[j].dat_elem;

	/* test si element actif */

	if(elem_j->etat != ACTIF)
	  continue;

	x0j = elem_j->x; y0j = elem_j->y;
	x1j = x0j + elem_j->w - 1;
	y1j = y0j + elem_j->h - 1;

	/* on regarde sur l'horizontale */

	if((y0i <= y1j) && (y1i >= y0j))
	  {
	  if(x0i < x0j)
	    {
	     /* l'element j est a la droite de l'element i */
	     /* est il le seul et le plus plus proche ? */

	     if((tab_dir[i].droite).n_el == 0)
	       {
		tab_dir[i].droite.n_el = j;
		tab_dir[i].droite.dist = x0j - x1i;
	       }
	     else
	       if(tab_dir[i].droite.dist > (x0j - x1i))
		 {
		  tab_dir[i].droite.n_el = j;
		  tab_dir[i].droite.dist = x0j - x1i;
		 }
	    }
	  else
	    {
	     /* l'element j est a la gauche de l'element i */
	     /* est il le seul et le plus plus proche ? */

	     if(tab_dir[i].gauche.n_el == 0)
	       {
		tab_dir[i].gauche.n_el = j;
		tab_dir[i].gauche.dist = x0i - x1j;
	       }
	     else
	       if(tab_dir[i].gauche.dist > (x0i - x1j))
		 {
		  tab_dir[i].gauche.n_el = j;
		  tab_dir[i].gauche.dist = x0i - x1j;
		 }
	    }

	 /* deux elements ne peuvent etre sur la meme ligne et
	    la meme colonne, donc on arrete. */
	 continue;

	 }/* fin horizontale */


	/* on regarde sur la verticale */

	if((x0i <= x1j) && (x1i >= x0j))
	  {
	  if(y0i < y0j)
	    {
	     /* l'element j est au dessous de l'element i */
	     /* est il le seul et le plus plus proche ? */

	     if(tab_dir[i].bas.n_el == 0)
	       {
		tab_dir[i].bas.n_el = j;
		tab_dir[i].bas.dist = y0j - y1i;
	       }
	     else
	       if(tab_dir[i].bas.dist > (y0j - y1i))
		 {
		  tab_dir[i].bas.n_el = j;
		  tab_dir[i].bas.dist = y0j - y1i;
		 }
	    }
	  else
	    {
	     /* l'element j est au dessus de l'element i */
	     /* est il le seul et le plus plus proche ? */

	     if(tab_dir[i].haut.n_el == 0)
	       {
		tab_dir[i].haut.n_el = j;
		tab_dir[i].haut.dist = y0i - y1j;
	       }
	     else
	       if(tab_dir[i].haut.dist > (y0i - y1j))
		 {
		  tab_dir[i].haut.n_el = j;
		  tab_dir[i].haut.dist = y0i - y1j;
		 }
	    }

	 }/* fin verticale */

       }/*FOR J*/


	/* on possede a present les elements voisins (les + proches) de i,
	   on procede a la mise a jours des vis a vis */

	elem = tab_dir[i].gauche.n_el;
	if(elem > i)
	  {
	   tab_dir[i].gauche.n_el += 1;
	   if(tab_dir[elem].droite.n_el == 0)
	     {
	      tab_dir[elem].droite.n_el = i + 1;
	      tab_dir[elem].droite.dist = tab_dir[i].gauche.dist;
	     }
	  }


	elem = tab_dir[i].droite.n_el;
	if(elem > i)
	  {
	   tab_dir[i].droite.n_el += 1;
	   if(tab_dir[elem].gauche.n_el == 0)
	     {
	      tab_dir[elem].gauche.n_el = i + 1;
	      tab_dir[elem].gauche.dist = tab_dir[i].droite.dist;
	     }
	  }


	elem = tab_dir[i].haut.n_el;
	if(elem > i)
	  {
	   tab_dir[i].haut.n_el += 1;
	   if(tab_dir[elem].bas.n_el == 0)
	     {
	      tab_dir[elem].bas.n_el = i + 1;
	      tab_dir[elem].bas.dist = tab_dir[i].haut.dist;
	     }
	  }


	elem = tab_dir[i].bas.n_el;
	if(elem > i)
	  {
	   tab_dir[i].bas.n_el += 1;
	   if(tab_dir[elem].haut.n_el == 0)
	     {
	      tab_dir[elem].haut.n_el = i + 1;
	      tab_dir[elem].haut.dist = tab_dir[i].bas.dist;
	     }
	  }


    }/*FOR I*/

    /* on sauvegarde ces relations de (bon ???) voisinage */

    for(i = 0; i < nb_elem; i++)
      {
       elem_i = tab_elem[i].dat_elem;

       elem_i->v_g = tab_dir[i].gauche.n_el;
       elem_i->v_d = tab_dir[i].droite.n_el;
       elem_i->v_h = tab_dir[i].haut.n_el;
       elem_i->v_b = tab_dir[i].bas.n_el;

      }
   f_libere(tab_dir);

}/*CALC_ELEM*/






/* definition des indices des arg dans rt_arg pour bd_close */

#define NB_ARG_CLOSE	1

#define Close_i_nol	0		/* indice nø logique boite 	*/




/*-------------------------------------------------------
   Fonction bd_close : fermeture d'un dialogue
   APPEL ABAL

   Entree : ()

   On recupere les arguments dans la structure rt_arg

	- nlog  : Nø logique du dialog


   Sortie :

	- code


   Traitement :

	recuperation et controle des arguments
	appel fonction C

	FIN

  --------------------------------------------------------*/

TYPF bd_close()
{


  /* variables locales */

  WORD nlog;			/* no logique dialogue 			*/
  BPTR temp;


  /* fonctions */
  /* TRAITEMENT */
  /**************/

  /* on teste le nb min d'arguments */

  if(rt_arg.c < NB_ARG_CLOSE)
    return(Bd_err_arg);

  /* on recupere le nø de la boite */

  if(rt_arg.t[Close_i_nol] != TYPE_POURCENT)
    return(Bd_err_typ);

#ifdef AIX_VERS
#ifdef SPARC
  temp = (BPTR)rt_arg.v[Close_i_nol];
  nlog = (WORD)((*temp << 8) + *(temp + 1));
#else
#if dosext || unix
  nlog = *(WPTR)rt_arg.v[Close_i_nol];
#else
  temp = (BPTR)rt_arg.v[Close_i_nol];
  nlog = (WORD)((*temp << 8) + *(temp + 1));
#endif
#endif
#else  /* AIX_VERS */
#if dosext || unix
  nlog = *(WPTR)rt_arg.v[Close_i_nol];
#else
  temp = (BPTR)rt_arg.v[Close_i_nol];
  nlog = (WORD)((*temp << 8) + *(temp + 1));
#endif
#endif /* AIX_VERS */
  /* Appel fonction C */

  return(bd_closec(nlog));

}/*BD_CLOSE*/





/*-------------------------------------------------------
   Fonction bd_closec

   Description :
     fermeture d'un dialogue

   Entree :

	- nol  : Nø logique du dialog


   Sortie :

	- code


   Traitement :

	FIN

  --------------------------------------------------------*/


TYPF bd_closec(nol)
WORD nol;
{

  /* variables */

  BYTE nb;
  B_DIAL_PTR b_cour_ptr;	/* ptr sur boite courante 		*/
  WORD ret, (* f_trait)();


  /* TRAITEMENT */
  /**************/


  /* verification init */

  if(fen_ini != 2)
    return(werr_ini);

  /* recherche pointeur sur boite de dialog */

  for(nb = 0; nb < MAX_DIAL; nb++)
    if(TB_BOX[nb].no_log == nol)
      break;

  if((nb == MAX_DIAL) || (nol <= 0))
    return(Bd_err_nobd);  /* boite non trouvee */
  b_cour_ptr = TB_BOX[nb].dial;

  /* test si dialogue ouvert */

  if(b_cour_ptr->fl_aff == FALSE)
    return(No_err);

  /* on ferme la boite de dialogue : FIN de tous les elements */
  wgel(nol);
  for(nb = 0; nb < b_cour_ptr->nb_elem; nb++)
    {
    f_trait = (WORD (*)())((b_cour_ptr->bd_aig[nb]).traitement);
    if(f_trait != NULL)
      if ((ret = (* f_trait)(nol, FIN, (b_cour_ptr->bd_aig[nb]).dat_elem)) != No_err)
	return(ret);
    }

  b_cour_ptr->fl_aff = FALSE;

  /* on rend le dialogue non mouse_sensitive */
  del_item_mouse_list(nol);
  winv(nol);
  return(No_err);
}





/* definition des indices des arg dans rt_arg pour bd_kill */

#define NB_ARG_KILL	1

#define Kill_i_nol	0		/* indice nø logique boite 	*/




/*-------------------------------------------------------
   Fonction bd_sup : desctruction d'un dialogue
   APPEL ABAL

   Entree : ()

   On recupere les arguments dans la structure rt_arg

	- nlog  : Nø logique du dialog


   Sortie :

	- code


   Traitement :

	recuperation et controle des arguments
	appel fonction C

	FIN

  --------------------------------------------------------*/

TYPF bd_sup()
{


  /* variables locales */

  WORD nlog;			/* no logique dialogue 			*/
  BPTR temp;


  /* TRAITEMENT */
  /**************/

  /* on teste le nb min d'arguments */

  if(rt_arg.c < NB_ARG_KILL)
    return(Bd_err_arg);

  /* on recupere le nø de la boite */

  if(rt_arg.t[Kill_i_nol] != TYPE_POURCENT)
    return(Bd_err_typ);
#ifdef AIX_VERS
#ifdef SPARC
  temp = (BPTR)rt_arg.v[Kill_i_nol];
  nlog = (WORD)((*temp << 8) + *(temp + 1));
#else
#if dosext || unix
  nlog = *(WPTR)rt_arg.v[Kill_i_nol];
#else
  temp = (BPTR)rt_arg.v[Kill_i_nol];
  nlog = (WORD)((*temp << 8) + *(temp + 1));
#endif
#endif
#else  /* AIX_VERS */
#if dosext || unix
  nlog = *(WPTR)rt_arg.v[Kill_i_nol];
#else
  temp = (BPTR)rt_arg.v[Kill_i_nol];
  nlog = (WORD)((*temp << 8) + *(temp + 1));
#endif
#endif /* AIX_VERS */
  /* Appel fonction C */

  return(bd_supc(nlog));

}/*BD_SUP*/







/*-------------------------------------------------------
   Fonction bd_supc : desctruction d'un dialogue
   APPEL C

   Entree :

	- nlog  : Nø logique du dialog


   Sortie :

	- code


   Traitement :


	FIN

  --------------------------------------------------------*/

TYPF bd_supc(nol)
WORD nol;
{


  /* variables */

  BYTE nb;
  BYTE i_bd;			/* indice dans tb_box du dialogue 	*/
  B_DIAL_PTR b_cour_ptr;        /* ptr sur boite courante 		*/
  WORD ret, (* f_trait)();


  /* TRAITEMENT */
  /**************/


  /* verification init */

  if(fen_ini != 2)
    return(werr_ini);

  /* recherche pointeur sur boite de dialog */

  for(i_bd = 0; i_bd < MAX_DIAL; i_bd++)
    if(TB_BOX[i_bd].no_log == nol)
      break;

  if((i_bd == MAX_DIAL) || (nol <= 0))
    return(Bd_err_nobd);  /* boite non trouvee */
  b_cour_ptr = TB_BOX[i_bd].dial;

  /* on ferme la boite */

  if((ret = bd_closec(nol)) != No_err)
    return(ret);

  /* on tue la boite de dialogue : KILL de tous les elements */
  /* et recup place memoire des data_elem */

  for(nb = 0; nb < b_cour_ptr->nb_elem; nb++)
    {
    f_trait = (WORD (*)())((b_cour_ptr->bd_aig[nb]).traitement);
    if(f_trait != NULL)
      if ((ret = (* f_trait)(nol, KILL, (b_cour_ptr->bd_aig[nb]).dat_elem)) != No_err)
	return(ret);
    if((b_cour_ptr->bd_aig[nb]).dat_elem != NULL)
      f_libere((b_cour_ptr->bd_aig[nb]).dat_elem);
    }

  wsup(nol);

  /* on retire le dialogue de TB_BOX */

  TB_BOX[i_bd].no_log = 0;

  /* recup memoire du dialogue */

  f_libere(b_cour_ptr->bd_aig);
  f_libere(b_cour_ptr->data_box);
  f_libere(b_cour_ptr->data_box_c);

  f_libere(b_cour_ptr);

  return(No_err);

}/*BD_SUPC*/







#define NB_ARG_PUT	2


#define Put_i_nol	0		/* indice nø logique boite 	*/
#define Put_i_data	1		/* indice nø element 		*/



/*-------------------------------------------------------
   Fonction de transfert data application -> dialogue
   APPEL ABAL

   Entree : ()

   On recupere les arguments dans la structure rt_arg

	- nlog  : Nø logique du dialog
	- data  : ptr sur tableau de data


   Sortie :

	- code


   Traitement :

	recuperation et controle des arguments
	appel fonction C

	FIN

  --------------------------------------------------------*/

TYPF bd_putdata()
{

  /* variables locales */

  WORD nlog;			/* no logique dialogue 			*/
  BPTR data;			/* ptr sur tableau de data		*/
  BPTR temp;


  /* TRAITEMENT */
  /**************/

  /* on teste le nb d'arguments */

  if(rt_arg.c != NB_ARG_PUT)
    return(Bd_err_arg);

  /* on recupere le nø de la boite */

  if(rt_arg.t[Put_i_nol] != TYPE_POURCENT)
    return(Bd_err_typ);

#ifdef AIX_VERS
#ifdef SPARC
  temp = (BPTR)rt_arg.v[Put_i_nol];
  nlog = (WORD)((*temp << 8) + *(temp + 1));
#else
#if dosext || unix
  nlog = *(WPTR)rt_arg.v[Put_i_nol];
#else
  temp = (BPTR)rt_arg.v[Put_i_nol];
  nlog = (WORD)((*temp << 8) + *(temp + 1));
#endif
#endif
#else  /* AIX_VERS */
#if dosext || unix
  nlog = *(WPTR)rt_arg.v[Put_i_nol];
#else
  temp = (BPTR)rt_arg.v[Put_i_nol];
  nlog = (WORD)((*temp << 8) + *(temp + 1));
#endif
#endif /* AIX_VERS */
  /* on recupere l'adresse du tableau de data */

  if(rt_arg.t[Put_i_data] != TYPE_CHAINE)
   return(Bd_err_typ);
  data = rt_arg.v[Put_i_data];


  /* Appel fonction C */

  return(bd_putdatac(nlog, data));

}/*BD_PUTDATA*/






/*-------------------------------------------------------
   Fonction de transfert data application -> dialogue
   APPEL C

   Entree :

	- nol   : Nø logique du dialog
	- tab   : ptr sur tableau de data


   Sortie :

	- code


   Traitement :


	FIN

  --------------------------------------------------------*/

TYPF bd_putdatac(nol,tab)
WORD nol;
BPTR tab;
{

  /* variables locales */

  WORD nb;
  B_DIAL_PTR b_cour_ptr;	/* ptr sur boite courante 		*/



  /* TRAITEMENT */
  /**************/


  /* verification init */

  if(fen_ini != 2)
    return(werr_ini);

  /* recherche pointeur sur boite de dialog */

  for(nb = 0; nb < MAX_DIAL; nb++)
    if(TB_BOX[nb].no_log == nol)
      break;

  if((nb == MAX_DIAL) || (nol <= 0))
    return(Bd_err_nobd);  /* boite non trouvee */
  b_cour_ptr = TB_BOX[nb].dial;


  /* recopie de tab dans data_box de dialogue */

  for(nb = 0; nb < b_cour_ptr->i_data; nb++)
    b_cour_ptr->data_box[nb] = tab[nb];

  return(No_err);



}/*BD_PUTDATAC*/








#define NB_ARG_GET	2


#define Get_i_nol	0		/* indice nø logique boite 	*/
#define Get_i_data	1		/* indice nø element 		*/



/*-------------------------------------------------------
   Fonction de transfert data dialogue -> application
   APPEL ABAL

   Entree : ()

   On recupere les arguments dans la structure rt_arg

	- nlog  : Nø logique du dialog
	- data  : ptr sur tableau de data


   Sortie :

	- code


   Traitement :

	recuperation et controle des arguments
	appel fonction C

	FIN

  --------------------------------------------------------*/

TYPF bd_getdata()
{

  /* variables locales */

  WORD nlog;			/* no logique dialogue 			*/
  BPTR data;			/* ptr sur tableau de data		*/
  BPTR temp;


  /* TRAITEMENT */
  /**************/

  /* on teste le nb d'arguments */

  if(rt_arg.c != NB_ARG_GET)
    return(Bd_err_arg);

  /* on recupere le nø de la boite */

  if(rt_arg.t[Get_i_nol] != TYPE_POURCENT)
    return(Bd_err_typ);

#ifdef AIX_VERS
#ifdef SPARC
  temp = (BPTR)rt_arg.v[Get_i_nol];
  nlog = (WORD)((*temp << 8) + *(temp + 1));
#else
#if dosext || unix
  nlog = *(WPTR)rt_arg.v[Get_i_nol];
#else
  temp = (BPTR)rt_arg.v[Get_i_nol];
  nlog = (WORD)((*temp << 8) + *(temp + 1));
#endif
#endif
#else  /* AIX_VERS */
#if dosext || unix
  nlog = *(WPTR)rt_arg.v[Get_i_nol];
#else
  temp = (BPTR)rt_arg.v[Get_i_nol];
  nlog = (WORD)((*temp << 8) + *(temp + 1));
#endif
#endif /* AIX_VERS */
  /* on recupere l'adresse du tableau de data */

  if(rt_arg.t[Get_i_data] != (TYPE_CHAINE | MODIFIABLE))
   return(Bd_err_typ);
  data = rt_arg.v[Get_i_data];


  /* Appel fonction C */

  return(bd_getdatac(nlog, data));

}/*BD_GETDATA*/






/*-------------------------------------------------------
   Fonction de transfert data dialogue -> application
   APPEL C

   Entree :

	- nol   : Nø logique du dialog
	- tab   : ptr sur tableau de data


   Sortie :

	- code


   Traitement :


	FIN

  --------------------------------------------------------*/


TYPF bd_getdatac(nol,tab)
WORD nol;
BPTR tab;
{

  /* variables locales */

  WORD nb;
  B_DIAL_PTR b_cour_ptr;	/* ptr sur boite courante 		*/



  /* TRAITEMENT */
  /**************/


  /* verification init */

  if(fen_ini != 2)
    return(werr_ini);

  /* recherche pointeur sur boite de dialog */

  for(nb = 0; nb < MAX_DIAL; nb++)
    if(TB_BOX[nb].no_log == nol)
      break;

  if((nb == MAX_DIAL) || (nol <= 0))
    return(Bd_err_nobd);  /* boite non trouvee */
  b_cour_ptr = TB_BOX[nb].dial;


  /* recopie de tab dans data_box de dialogue */

  for(nb = 0; nb < b_cour_ptr->i_data; nb++)
    tab[nb] = b_cour_ptr->data_box[nb];


  return(No_err);

}/*BD_GETDATAC*/


 
