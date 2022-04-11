/****************************************************************
* Services Fenetres                 				*
*---------------------------------------------------------------*
* Source : sfld.c                   				*
*---------------------------------------------------------------*
* Version : 1.1b                    				*
* Mise a jour le : 15/06/1990   sb  				*
* Modif le 21/09 : Ajout test nligt < nlig                      *
* MAJ llb  18.07.91	Modif pour Boites Dialogue              *
*	   24.07.91 	Ajout fonction list_info()              *
* MAJ EDS  20.08.91     Update appels ld_creatc avec 5 args     *
*          27.08.91	prise en compte arg sup ds ld/m_creat	*
* MAJ LLB  27.02.92	le_insert, le_delete, le_matt		*
* MAJ EDS  14.04.92	touches d'echappement			*
* MAJ EDS  04.05.92	scroll bar 				*
* MAJ EDS  07.05.92	Mouse					*
* MAJ LLB  30.04.92	corr alloc element d'une liste		*
* maj llb  28.07.92	matt_elt: completer a blanc libelle	*
* maj llb  05.11.92     le_up : exception si 1er element	*
* maj llb  01.04.93     adaptation nouveaux styles fenetre	*								*
* maj llb  28.06.93     Corr pb scroll si nbel < maxel (F_BAS)	*
* maj llb  21.07.93     Scrolling si M_W_DOWN sur cadre liste	*	
* maj llb  01.09.93     flag fl_aff dans list_vis		*
* maj llb  06.01.94     inversion lis_control lm_creat dos etendu
* maj llb  24.05.94     ld_choix: controle type argument "exit"
*	   28.07.94	LD_CHOIX: TRT PG_UP et SOR_SI_HAUT
* maj sb   28/05/98     Correction Erreur le_insert
* maj sb   06/06/98     Correction Erreur Titre
******************************************************************
* Fonctions				                        *
*                                   				*
* - ld_creat       creer liste norm 				*
* - lm_creat       creer liste mult 				*
* - le_creat       creer element    				*
* - ld_close       fermer liste     				*
* - ld_aff         afficher liste   				*
* - ld_sup         supprimer liste  				*
* - le_lect        lecture element  				*
* - le_up          element precedent				*
* - le_down        element suivant  				*
* - le_matt        modif attr elem 				*
* - ld_choix       choix element    				*
* - ld_clear       effacer liste    				*
* - list_info	   obtenir info d'une liste                     *
* - le_insert	   inserer un element				*
* - le_delete	   supprimer un element				*
*								*
****************************************************************/

#include "sfundef.h"
#include "bda.h"

#include "mouse.h"

#ifdef HPUX
#include <stdio.h>
#endif


#define LIST_EVENTS	KEYBOARD+MOUSE_UP+MOUSE_DOWN+MOUSE_D_CLICK+MOUSE_M_W_DOWN+MOUSE_IS_DOWN


#define NO_REGION	-2
#define INSIDE_LIST	-1
#define SCROLL_BARRE	M_LEFT+M_RIGHT+M_UP+M_DOWN
#define CADRE_GAUCHE	M_LEFT
#define CADRE_DROIT	M_RIGHT
#define CADRE_HAUT	M_UP
#define CADRE_BAS	M_DOWN

#define NO_SCROLLING	-1


/* le marqueur de scroll bar  (A DEPORTER ....) */

#define SCROLLING_H	256
#define SCROLLING_V	512

/* les regions du scroll  (A DEPORTER ....) */

#define NO_SCROLL	0
#define SCROLL_UP	1
#define SCROLL_P_UP	2
#define SCROLL_P_DOWN	3
#define SCROLL_DOWN	4


/* ORIENTATION  (A DEPORTER ....) */

#define HORIZONTALE	1
#define VERTICALE	2





/* variable globales pour list_info() */

extern	WITEM*   WLOG[MAXFUN];
extern GLOBAL BDA_ARG rt_arg;
extern BYTE tc[MAX_TOUCHES];

extern EVENT_STR	event;
extern BYTE tb_style[MAXSTF];		/* table styles actifs */
extern stf_desc stf[MAXSTF+1];
extern BPTR Wkup_Adress;

/***********************************************
* fonctions de listes
*    	Fonctions LD_CREAT creation d'une liste
*       simple
************************************************/

#ifdef PRL

/* version prologue */

TYPF ld_creat(ld_no,ld_de)
BYTE ld_no;
ld_desc_ptr ld_de;

{

  TYPF ld_creatc ();

  WORD ld_er, i;
  WORD cont;
  BPTR help;


  ld_de->ld_plig = Invint(ld_de->ld_plig);
  ld_de->ld_pcol = Invint(ld_de->ld_pcol);
  ld_de->ld_nlig = Invint(ld_de->ld_nlig);
  ld_de->ld_mxel = Invint(ld_de->ld_mxel);

  /* on regarde si il y a encore des arguments */

  help = NULL;
  cont = 0 ;

  if(rt_arg.c > 4)
    return(RT_err_arg);

  if(rt_arg.c > 2) {
     	if(rt_arg.t[2] == TYPE_POURCENT)
	       	cont = GetAbalWord( rt_arg.v[2] );
     	else if(rt_arg.t[2] == TYPE_DEUXPOINT)
	       	cont = GetAbalLong( rt_arg.v[2] );
       	else	return(RT_err_typ);
     	}
  if(rt_arg.c > 3)
    {
     if(rt_arg.t[3] != TYPE_CHAINE)
       return(RT_err_typ);
     if((help = f_allouer((rt_arg.l[3] + 1))) == NULL)
       return(werr_mem);
     for(i = 0; i < rt_arg.l[3] ; i++)
       help[i] = ((BPTR)rt_arg.v[3])[i];
     help[i] = 0;
    }
  ld_er = ld_creatc(ld_no,(ld_desc_ptr) ld_de, 0,cont, help);

  if(help != NULL)
    f_libere(help);

  ld_de->ld_plig = Invint(ld_de->ld_plig);
  ld_de->ld_pcol = Invint(ld_de->ld_pcol);
  ld_de->ld_nlig = Invint(ld_de->ld_nlig);
  ld_de->ld_mxel = Invint(ld_de->ld_mxel);

  return(ld_er);

}

#else

/* version unix */

TYPF ld_creat(ld_no,LD_de)
BYTE ld_no;
BPTR LD_de;

{

  WORD 	ld_er;
  WORD 	i;
  ld_desc ld_de;
  WORD cont;
  BPTR help;

  ld_de.ld_stlf = LD_de[LD_stlf];

  ld_de.ld_plig = GetAbalWord( &LD_de[LD_plig] );
  ld_de.ld_pcol = GetAbalWord( &LD_de[LD_pcol] );
  ld_de.ld_nlig = GetAbalWord( &LD_de[LD_nlig] );

  for (i=0; i<32; ++i)
    ld_de.ld_titr[i] = LD_de[LD_titr+i];

  ld_de.ld_typa = LD_de[LD_typa];
  ld_de.ld_typd = LD_de[LD_typd];
  ld_de.ld_nelh = LD_de[LD_nelh];
  ld_de.ld_pscrol = LD_de[LD_pscrol];
  ld_de.ld_cadre = LD_de[LD_cadre];

  ld_de.ld_mxel = GetAbalWord( &LD_de[LD_mxel] );

  ld_de.ld_lel = LD_de[LD_lel];
  ld_de.ld_laff = LD_de[LD_laff];
  ld_de.ld_lcom = LD_de[LD_lcom];


  /* on regarde si il y a encore des arguments */

  help = NULL;
  cont = NULL;

  if(rt_arg.c > 4)
    return(RT_err_arg);

  if(rt_arg.c > 2) {
     	if (rt_arg.t[2] == TYPE_POURCENT)
		cont = GetAbalWord( rt_arg.v[2] );
     	else if (rt_arg.t[2] == TYPE_DEUXPOINT)
		cont = GetAbalLong( rt_arg.v[2] );
       	else	return(RT_err_typ);
	}

  if(rt_arg.c > 3)
    {
     if(rt_arg.t[3] != TYPE_CHAINE)
       return(RT_err_typ);
     if((help = f_allouer((rt_arg.l[3] + 1))) == NULL)
       return(werr_mem);
     for(i = 0; i < rt_arg.l[3]; i++)
       help[i] = ((BPTR)rt_arg.v[3])[i];
     help[i] = 0;
    }
  ld_er = ld_creatc(ld_no,(ld_desc_ptr) &(ld_de.ld_stlf), 0, cont, help);

  if(help != NULL)
    f_libere(help);

  return(ld_er);

}

#endif




/**********************************
* appel C standard                *
***********************************/

TYPF ld_creatc(ld_no,ld_de,ld_type,ld_control,ld_cle)
BYTE ld_no;
ld_desc_ptr ld_de;
BYTE ld_type;        	/* 0 = simple, 1 = Multiple */
WORD ld_control;	/* definit le comportement */
BPTR ld_cle;		/* Mot cl‚ AIDE contextuelle*/

{

  /* fonctions appelees */

  TYPF bv_aff();
  TYPF add_scroll_bar();


  /* variables externes */

  extern stc_desc stc[MAXSTC];
  extern ld_tab ld[MAXLD];
  extern WDESC_APP_F fen;
  extern cof_tab co;
  extern bv_tab bvc;

  /* variables internes */

  ld_tab *lc;				/* liste cree */
  stf_desc *syf;			/* style fenetre */
  int	ld_er;				/* code erreur */
  int	i,j,k;
  WORD	mxel;
  WDESC_APP_PTR pfl;
  BYTE	laff,lcom,lel;
  BPTR	le_ptr;
  bv_desc bv_de;
  BYTE	style;
  BYTE scroll_v, scroll_h;		/* flags de scroll bar */
  WORD	o;
#ifdef AIX_VERS
#ifdef HPUX
 BYTE * titptr;
#endif
#endif /* AIX_VERS */
  /************************************
  * verification des parametres       *
  *************************************/

  /* verification init */
  if(fen_ini != 2)
    return(werr_ini);

  /* verification no de liste */

  if((ld_no == 0) || (ld_no >= MAXLD))
    return(werr_desc);
  lc = &ld[ld_no];

  if(lc->l_nofen != 0)
    return(werr_exist);

  /* verification autres parametres */
  if(ld_type > 2)
    return(werr_desc);
/*
  style = ld_de->ld_stlf;
  if(style & SFOMB)
    style -= SFOMB;
  if((style == 0) || (style > MAXSTF))
    return(werr_desc);
*/
  if((ld_de->ld_typa == 0) || (ld_de->ld_typa > 2))
    return(werr_desc);
  if((ld_de->ld_typd == 0) || (ld_de->ld_typd > 2))
    return(werr_desc);
/*if ((ld_de->ld_pscrol == 0) || (ld_de->ld_pscrol > 2)) return(werr_desc);  non utilise pour l'instant !*/

  ld_de->ld_pscrol = 1;

  if((ld_de->ld_plig == 0) || (ld_de->ld_plig > MAXLIG - 1))
    return (werr_desc);
  if((ld_de->ld_pcol == 0) || (ld_de->ld_pcol > MAXCOL - 1))
    return (werr_desc);


  if((ld_de->ld_cadre == 0) || (ld_de->ld_cadre > 2))
    return(werr_desc);

  if(ld_de->ld_nelh == 0)
    return(werr_desc);
  mxel = ld_de->ld_mxel;
  if((mxel == 0) || (mxel > MAXELL))
    return(werr_desc);

  if((ld_de->ld_lel  == 0) || (ld_de->ld_lel > 9999))
    return(werr_desc);
  if((ld_de->ld_laff == 0) || (ld_de->ld_laff >  ld_de->ld_lel) || (ld_de->ld_laff > MAXCOL -1))
    return(werr_desc);
  if(ld_de->ld_lcom > MAXCOL - 1)
    return(werr_desc);

  /*****************************************************
  *  pas d'erreur decelee : tentative creation fenetre *
  ******************************************************/

  scroll_v = ((ld_de->ld_typd == 2) && ((ld_control&SCROLL_V) != 0)) ? TRUE : FALSE;
  scroll_h = ((ld_de->ld_typd == 1) && ((ld_control&SCROLL_H) == SCROLL_H)) ? TRUE : FALSE;
  lc->l_mult = ld_type ;

  pfl = (WDESC_APP_PTR) &fen;
  pfl->Amere_nbr = 0;
  pfl->Anb_lig = ld_de->ld_nlig;
  pfl->Apos_lig = ld_de->ld_plig;
  pfl->Apos_col = ld_de->ld_pcol;

  if((lc->l_mult == 1) && !(ld_control & NO_BV)) /* lismul sans confirmation */
    {
     scroll_v = FALSE;
     scroll_h = FALSE;
     pfl->Anb_lig += 4;
    }


  /* on reserve de la place pour la scroll bar si NO_BV */

  if(pfl->Anb_lig < 2)
    scroll_v = FALSE;

  pfl->Anb_col = ((ld_de->ld_nelh)*(ld_de->ld_laff + 1));

  if(scroll_v == TRUE)
    pfl->Anb_col++;
  else
    if(scroll_h == TRUE)
      pfl->Anb_lig++;

/* style de fenetre */

	style = ld_de->ld_stlf;
	if ( (style == 0) || (style > STYLMAX) )
	    return(werr_desc);
	if ( (style > 15) && (style < 20) )
	    return(werr_desc);

	if ( style < 15)		/* 5+ombre*/
	 {
	    if ( style & SFOMB ) {
		style -= SFOMB;
		o = TRUE;
	    }
	    else
		o = FALSE;

	    --style;
	}
	else {                            /* 20.. */
	     style -=15;
	     if ( tb_style[style] == 0 )
		return(werr_inex);
	     o = stf[style].f_ombre;
	}

	syf = &(stf[style]);

     pfl->Aatb_vid = syf->f_fond.atbc;		/* attributs fond */
     pfl->Aatbcol_text = syf->f_fond.colc;
     pfl->Aatbcol_fond = syf->f_fond.colf;
     pfl->Acad_atb = syf->f_cad.atbc;		/* attributs cadre */
     pfl->Acad_text = syf->f_cad.colc;
     pfl->Acad_fond = syf->f_cad.colf;

     pfl->Acontrol = 33;			/* invisible cadre */
     if(o)
       pfl->Acontrol += OMBRE;

     k = syf->f_nostc;

     if((k > 0 ) && (k <= MAXSTC))
       {
	--k;
	for(j=0; j<8; ++j)
	  pfl->Acad_usr[j] = stc[k].trait[j];

	/* modif llb 12.02.1992 ***************
	i = 1;
	pfl->Aln_tit = 0;
	pfl->Atitre[0] = EOS;

	for(j=TAIL_TITRE;j>0;)
	  {
	   --j;
	   if((ld_de->ld_titr[j] != ' ') && (i))
	     {
	      pfl->Aln_tit = j+1;
	      i = 0;
	     }
	   pfl->Atitre[j] = ld_de->ld_titr[j];
	  }

	*****************************************/

	/* recherche EOS (C) */
	j = 0;
	while((ld_de->ld_titr[j] != EOS) && ( j < TAIL_TITRE))
	 {
	  pfl->Atitre[j] = ld_de->ld_titr[j];
	  j++;
	 };

	/* tronquer les blancs fin du message */
	if (j > 0 )
	  {
	   j--;
	   while ((pfl->Atitre[j]==' ')&&( j>=0))
	     j--;
	   j++;
	  }

	pfl->Aln_tit = j;
 	if ( j < TAIL_TITRE)
		pfl->Atitre[j] = NULL;
       }
     else
       pfl->Acontrol = 1;

  /* creation fenetre */

  if(lc->l_nofen != 0)
    return(werr_exist);
  ld_er = wcreatc((WPTR)&(lc->l_nofen),(WDESC_APP_PTR) pfl);

  if(ld_er)
    return(ld_er);

  /* on ajoute la scroll bar */
  if(scroll_v)
    add_scroll_bar(lc->l_nofen, 2);
  if(scroll_h)
    add_scroll_bar(lc->l_nofen, 1);



  /****************************************************
  *    transfert des parametres de la liste en table  *
  *****************************************************/

  lc->l_typa = ld_de->ld_typa;
  lc->l_typd = ld_de->ld_typd;
  lc->l_nelh = ld_de->ld_nelh;
  lc->l_nlig = ld_de->ld_nlig;
  lc->l_pscrol = ld_de->ld_pscrol;
  lc->l_cadre = ld_de->ld_cadre;
  lc->l_mxel = ld_de->ld_mxel;
  lc->l_lel = ld_de->ld_lel;
  lc->l_laff = ld_de->ld_laff;
  lc->l_lcom = ld_de->ld_lcom;
  lc->l_plig = ld_de->ld_plig;
  lc->l_pcol = ld_de->ld_pcol;
  lc->l_styf = ld_de->ld_stlf;
  lc->control = ld_control;    	/* arguments BD */
  if(ld_cle != (BPTR) NULL)
    wmemcpy((BPTR)lc->lis_cle, ld_cle, 8);	/* copie ptr far */
  else
    lc->lis_cle[0] = NULL;

  if(lc->l_typd == 1)
    {
     lc->l_ncolt = (lc->l_mxel)/lc->l_nlig;
     if (lc->l_ncolt * lc->l_nlig < lc->l_mxel) ++lc->l_ncolt;
     if (lc->l_ncolt < lc->l_nelh) lc->l_ncolt = lc->l_nelh;
     lc->l_nligt = lc->l_nlig;
    }
  else
    {
     lc->l_ncolt = lc->l_nelh;
     lc->l_nligt = (lc->l_mxel)/(lc->l_nelh);
     if (lc->l_nligt * lc-> l_nelh < lc->l_mxel) ++lc->l_nligt;
     if (lc->l_nligt < lc->l_nlig) lc->l_nligt = lc->l_nlig;
    }


  /************************************************
  *    init des autres valeurs                    *
  *************************************************/

  lc ->l_ferm= 2;  				/* non fermee */
  lc->l_nbel = 0;				/* pas d'element*/
  lc->l_inda = 0;				/* non affiche  */
  lc->l_indm = 0;				/* non modifie  */
  lc->l_nelv = 1;				/* pas d'el visualise */
  lc->l_nelp = 1;				/* pas d'el positionne */
  lc->l_mxel = mxel;				/* max elements */
  lc->l_nelc = 0;				/* no d'element en cours */
  lc->l_bvm  = 0;				/* no menu pour multiple */
  lc->l_bvf  = 0;				/* no fen  pour multiple */

  /* sauvegarde des attributs fenetre */

  lc->l_at.atbc = pfl->Aatb_vid; 		/* attributs fond */
  lc->l_at.colc = pfl->Aatbcol_text;
  lc->l_at.colf = pfl->Aatbcol_fond;

  /* allocation memoire table des elements */

  i = sizeof(BPTR)*(mxel+1);
  le_ptr  = (BPTR) f_allouer (i);

  if(le_ptr == (BPTR) NULL)
    {
     lc->l_nofen = 0;
     return (werr_mem);
    }

  lc->l_ptre = (BPTRPTR) le_ptr;

  /* incrustation de la boite si choix multiple */

  if((lc->l_mult == 1) && !(lc->control & NO_BV))
    {
     wposcur(lc->l_nofen,lc->l_nlig+1,1);
     for(i=0; i < pfl->Anb_col; ++i)
       wwrite(lc->l_nofen,1,(BPTR) &co.o_seph);
    }

  /* fenetre commentaires */

  lc->l_nofenc = 0;
  if(lc->l_lcom > 0)
    lscreatc((WPTR) &(lc->l_nofenc));

  return(OK);
}



/***********************************************
* fonctions de liste
*       Fonction LM_CREAT creation liste a choix multiple
*
************************************************/

#ifdef PRL

/* version prologue */

TYPF	lm_creat(ld_no,ld_de)
BYTE	ld_no;
ld_desc_ptr ld_de;

{
  /* fonctions externes */

  TYPF	ld_creatc();

  /* variables internes */

  int ld_er;			/* code erreur 				*/
  WORD cont;			/* controle comportement 		*/
  BPTR help;			/* aide contexte                        */
  WORD i;

/* debut */
	ld_de->ld_plig = Invint(ld_de->ld_plig);
	ld_de->ld_pcol = Invint(ld_de->ld_pcol);
	ld_de->ld_nlig = Invint(ld_de->ld_nlig);
	ld_de->ld_mxel = Invint(ld_de->ld_mxel);


	/* on regarde si il y a encore des arguments */

	help = NULL;
	cont = 0 ;

	if(rt_arg.c > 4)
	     return(RT_err_arg);

	if(rt_arg.c > 2)    {
	      	if(rt_arg.t[2] == TYPE_POURCENT)
		      	cont =  GetAbalWord( rt_arg.v[2] );
	     	else if(rt_arg.t[2] == TYPE_DEUXPOINT)
		      	cont =  GetAbalLong( rt_arg.v[2] );
	 	else	return(RT_err_typ);
		}
	if(rt_arg.c > 3)   {
	      if(rt_arg.t[3] != TYPE_CHAINE)
		return(RT_err_typ);
	      if((help = f_allouer((rt_arg.l[3] + 1))) == NULL)
		return(werr_mem);
	      for(i = 0; i < rt_arg.l[3] ; i++)
		help[i] = ((BPTR)rt_arg.v[3])[i];
	      help[i] = 0;
	}
	ld_er = ld_creatc(ld_no,(ld_desc_ptr) ld_de, 1,cont, help);


	if(help != NULL)
	  f_libere(help);

	ld_de->ld_plig = Invint(ld_de->ld_plig);
	ld_de->ld_pcol = Invint(ld_de->ld_pcol);
	ld_de->ld_nlig = Invint(ld_de->ld_nlig);
	ld_de->ld_mxel = Invint(ld_de->ld_mxel);

	return (ld_er);
}

#else

TYPF	lm_creat(ld_no,LD_de)
	BYTE	ld_no;
	BPTR 	LD_de;
{
TYPF ld_creatc ();

WORD 	ld_er;
WORD 	i;
ld_desc ld_de;
BYTE cont;
BPTR help;


	ld_de.ld_stlf = LD_de[LD_stlf];

	ld_de.ld_plig = GetAbalWord( &LD_de[LD_plig] );
	ld_de.ld_pcol = GetAbalWord( &LD_de[LD_pcol] );
	ld_de.ld_nlig = GetAbalWord( &LD_de[LD_nlig] );

	for (i=0;i<32;++i) 
		ld_de.ld_titr[i] = LD_de[LD_titr+i];
	ld_de.ld_typa = LD_de[LD_typa];
	ld_de.ld_typd = LD_de[LD_typd];
	ld_de.ld_nelh = LD_de[LD_nelh];
	ld_de.ld_pscrol = LD_de[LD_pscrol];
	ld_de.ld_cadre = LD_de[LD_cadre];

	ld_de.ld_mxel = GetAbalWord( &LD_de[LD_mxel] );

	ld_de.ld_lel = LD_de[LD_lel];
	ld_de.ld_laff = LD_de[LD_laff];
	ld_de.ld_lcom = LD_de[LD_lcom];


	/* on regarde si il y a encore des arguments */

	help = NULL;
	cont = NULL;

	if(rt_arg.c > 4)
	     return(RT_err_arg);

	if(rt_arg.c > 2)   {
	   	if(rt_arg.t[2] == TYPE_POURCENT)
			cont = 	GetAbalWord( rt_arg.v[2] );
	   	else if(rt_arg.t[2] == TYPE_DEUXPOINT)
			cont = 	GetAbalLong( rt_arg.v[2] );
	     	else	return(RT_err_typ);
		}
	if(rt_arg.c > 3)
	     {
	      if(rt_arg.t[3] != TYPE_CHAINE)
		return(RT_err_typ);
	      if((help = f_allouer((rt_arg.l[3] + 1))) == NULL)
		return(werr_mem);
	      for(i = 0; i < rt_arg.l[3]; i++)
		help[i] = ((BPTR)rt_arg.v[3])[i];
	      help[i] = 0;
	}
	   ld_er = ld_creatc(ld_no,(ld_desc_ptr)&(ld_de.ld_stlf), 1, cont, help);

	if(help != NULL)
	  f_libere(help);

	return(ld_er);
}

#endif

/***********************************************
* fonctions de liste
*    	Fonctions LE_CREAT creation d'un element
*
************************************************/
TYPF le_creat (ld_no,le_no,le_ataff,le_atetat,le_val,le_com)
	BYTE ld_no;
	WPTR le_no;
	BYTE le_ataff;
	BYTE le_atetat;
	BPTR le_val;
	BPTR le_com;
{
	TYPF	le_creatc( );
	int	le_er=0;
	WORD 	nole=0;

	if (!(le_er = le_creatc(ld_no,&nole,le_ataff,le_atetat,le_val,le_com))) { 
		PutAbalWord( le_no, nole );
		}
	else	{
		PutAbalWord( le_no, 0 );
		}
	return(le_er);
}

/**********************************
* appel C standard                *
***********************************/
TYPF	le_creatc(ld_no,le_no,le_ataff,le_atetat,le_val,le_com)
	BYTE ld_no;
	WPTR le_no;
	BYTE le_ataff;
	BYTE le_atetat;
	BPTR le_val;
	BPTR le_com;
{

extern	ld_tab	ld[MAXMEN];

/* variables internes */

int	ld_er;			/* code erreur */
int	i,j,k;
ld_tab  * lc;			/* liste choisi */
BPTR    el_ptr;			/* pointeur sur le descripteur element */
WORD	nelt;			/* numero option */
WORD	ilig,icol;		/* position ligne/colonne */
WORD	lel,nbel,lcom,laff;	/* valeurs en cours */
char	c;
BPTRPTR elt_ptr;               /* pointeur sur la table de sauv elements */

/************************************
* verification des parametres       *
*************************************/

/* verification init */
	if (fen_ini != 2) return(werr_ini);

/* verification liste  en cours */

	if ((ld_no == 0) || (ld_no >= MAXLD) ) return(werr_desc);
	lc = &(ld[ld_no]);
	if (lc->l_nofen == 0) return(sferr_inex);
	if (lc->l_nbel >= lc->l_mxel) {
		return(sfenr_inex);
		}
/* 30.08.93
	if ((*le_no==0) && (lc->l_ferm ==1))
		 return(sferr_open);
***********/
/* verification attributs */

	if ((le_ataff == 0) || (le_ataff > 2)) return(werr_desc);
	if ((le_atetat == 0) || (le_atetat > 2)) return(werr_desc);

/*****************************************************
*  pas d'erreur decelee : Allocation memoire         *
******************************************************/

	if ( *le_no == 0 )
		nelt = lc->l_nbel;	/* ajouter */
	else
	  {  	/* inserer */

		nelt = (*le_no)-1;
		elt_ptr = lc->l_ptre;
		elt_ptr += (lc->l_nbel)-1;

		for ( i = lc->l_nbel; i > nelt ; i--) {
			*(elt_ptr+1)  = *(elt_ptr);
			elt_ptr--;
		}
	}/*else*/

	laff = lc->l_laff;
	lel = lc->l_lel;
	lcom = lc->l_lcom;

/* allocation memoire */

	el_ptr  =  f_allouer (lel + lcom + 3);  /*llb 30.04.92*/

	if (el_ptr == (BPTR) NULL) return (werr_mem);

	elt_ptr = lc->l_ptre;
	elt_ptr += nelt;
	*(elt_ptr) = (BPTR) el_ptr;		/* rgt en table */

	*(el_ptr++) = le_ataff;		/* chgt des valeurs */
	*(el_ptr++) = le_atetat;

/*****************************************************
* sauvegarde de la valeur de l'option                *
******************************************************/

/* centrage de l'option si souhaite */

	if (lc->l_cadre == 2)
	  {
		k= laff - 1;
		while ( le_val[k] == ' ') --k;
		k = (laff-k)/2;
		if (k) --k;
		for (i = 0; i < k ; ++i) *(el_ptr++) = ' ';
		for ( ;i <= laff - k ; ++i) *(el_ptr++) = le_val[i-k] ;
		for ( ;i < lel ; ++i) *(el_ptr++) = le_val[i] ;
	  }
       else
	  {
		for (i=0; i<lel ; ++i) *(el_ptr++) = le_val[i];
	  }

/*****************************************************
* sauvegarde du commentaire fini par zero            *
******************************************************/

	if (lc->l_lcom > 0)
	  {
		for (i = 0; i < lcom; ++i) *(el_ptr++) = le_com[i];
		*(el_ptr) = 0;
	  }

	lc->l_nbel += 1;
	nelt++;
	*le_no = nelt;
	return(OK);
}

/***********************************************
* fonctions de liste
*    	Fonctions LE_LECT lecture d'un element
*
************************************************/
TYPF	le_lect(ld_no,le_no,lep_ataff,lep_atetat,le_val)
	BYTE ld_no;
	WORD le_no;
	BPTR lep_ataff;
	BPTR lep_atetat;
	BPTR le_val;
{

extern	ld_tab	ld[MAXMEN];

/* variables internes */

int	ld_er;			/* code erreur */
int	i,j,k;
ld_tab * lc;			/* liste choisi */
BPTR    el_ptr;			/* pointeur sur le descripteur element */
WORD	nelt;			/* numero option */
WORD	lel,nbel,lcom,laff;	/* valeurs en cours */
char	c;
BPTRPTR elt_ptr;               /* pointeur sur la table de sauv elements */

/************************************
* verification des parametres       *
*************************************/

/* verification init */
	if (fen_ini != 2) return(werr_ini);

/* verification liste  en cours */

	if ((ld_no == 0) || (ld_no >= MAXLD) ) return(werr_desc);

	lc = &(ld[ld_no]);
	if (lc->l_nofen == 0) return(sferr_inex);

	nelt = le_no;
	if ((nelt == 0) || (nelt > lc->l_nbel)) {
		return (sfenr_inex);
		}

/*****************************************************
*  pas d'erreur decelee : recherche des valeurs      *
******************************************************/

	elt_ptr =  lc->l_ptre;
	elt_ptr += nelt-1;
	el_ptr = *(elt_ptr);

	lc->l_nelc = nelt;

	*(lep_ataff) = *(el_ptr++);
	*(lep_atetat) = *(el_ptr++);

	if (le_val != (BPTR) NULL)
	  {
		for (i=0;i<lc->l_lel;++i) le_val[i] = *(el_ptr++);
	  }
	return(OK);

}



/***********************************************
* fonctions de liste
*    	Fonctions LE_DOWN lecture du suivant
*
************************************************/
TYPF	le_down(ld_no,le_no,lep_ataff,lep_atetat,le_val)
	BYTE ld_no;
	WPTR le_no;
	BPTR lep_ataff;
	BPTR lep_atetat;
	BPTR le_val;
{
	TYPF	le_downc();
	int	ld_er;			/* code erreur */
	WORD 	nole=0;
	if (!(ld_er = le_downc(ld_no,&nole,lep_ataff,lep_atetat,le_val) )) {
		PutAbalWord( le_no, nole );
		}
	else	{
		PutAbalWord( le_no, nole );
		}
	return(ld_er);
}

/**********************************
* appel C standard                *
***********************************/
TYPF	le_downc(ld_no,le_no,lep_ataff,lep_atetat,le_val)
	BYTE ld_no;
	WPTR le_no;
	BPTR lep_ataff;
	BPTR lep_atetat;
	BPTR le_val;
{

extern	ld_tab	ld[MAXMEN];

/* variables internes */

int	ld_er;			/* code erreur */
int	i,j,k;
ld_tab   * lc;			/* liste choisi */
BPTR    el_ptr;			/* pointeur sur le descripteur element */
WORD	nelt;			/* numero option */
BYTE    ataff,atetat;		/* valeurs en cours */
BPTRPTR elt_ptr;               /* pointeur sur la table de sauv elements */

/************************************
* verification des parametres       *
*************************************/

/* verification init */
	if (fen_ini != 2) return(werr_ini);

/* verification liste  en cours */

	if ((ld_no == 0) || (ld_no >= MAXLD) ) return(werr_desc);
	lc = &(ld[ld_no]);
	if (lc->l_nofen == 0) return(sferr_inex);

/* test des attributs demandes */
	ataff = *lep_ataff;
	atetat = *lep_atetat;

	if (ataff > 2) return(werr_desc);
	if (atetat> 2) return(werr_desc);

/* test si fin de fichier */
	nelt = lc->l_nelc;

/*****************************************************
*  pas d'erreur decelee : recherche des valeurs      *
******************************************************/
	k =0;
	while (k == 0)
	  {
		++nelt;
		if (nelt > lc->l_nbel) return(sfenr_fin);
		elt_ptr =  lc->l_ptre;
		elt_ptr += nelt-1;
		el_ptr = *(elt_ptr);

		if ((atetat == 0) || (atetat == *(el_ptr+1)))
		  {
			if ((ataff == 0) || (ataff == *el_ptr))
			  {
				*lep_ataff = *el_ptr++;
				*lep_atetat = *el_ptr++;
				if (le_val != (BPTR) NULL)
				  {
					for (i=0;i<lc->l_lel;++i) le_val[i] = *(el_ptr++);
				  }
			  	k = 1;
			  }
		   }
	    }

	lc->l_nelc = nelt;
	*le_no = nelt;
	return(OK);

}

/***********************************************
* fonctions de liste
*    	Fonctions LE_UP lecture du precedent
*
************************************************/
TYPF	le_up(ld_no,le_no,lep_ataff,lep_atetat,le_val)
	BYTE ld_no;
	WPTR le_no;
	BPTR lep_ataff;
	BPTR lep_atetat;
	BPTR le_val;
{
	TYPF    le_upc();
	int	lu_er;			/* code erreur */
	WORD 	nole=0;
	if (!(lu_er = le_upc(ld_no,&nole,lep_ataff,lep_atetat,le_val))) {
		PutAbalWord(le_no,nole);
		}
	else	{
		PutAbalWord(le_no,0);
		}
	return(lu_er);
}
/**********************************
* appel C standard                *
***********************************/

TYPF	le_upc(ld_no,le_no,lep_ataff,lep_atetat,le_val)
	BYTE ld_no;
	WPTR le_no;
	BPTR lep_ataff;
	BPTR lep_atetat;
	BPTR le_val;
{


extern	ld_tab	ld[MAXMEN];

/* variables internes */

int	ld_er;			/* code erreur */
int	i,j,k;
ld_tab  * lc;			/* liste choisi */
BPTR    el_ptr;			/* pointeur sur le descripteur element */
WORD	nelt;			/* numero option */
BYTE    ataff,atetat;		/* valeurs en cours */
BPTRPTR elt_ptr;               /* pointeur sur la table de sauv elements */

/************************************
* verification des parametres       *
*************************************/

/* verification init */
	if (fen_ini != 2) return(werr_ini);

/* verification liste  en cours */

	if ((ld_no == 0) || (ld_no >= MAXLD) ) return(werr_desc);
	lc = &(ld[ld_no]);
	if (lc->l_nofen == 0) return(sferr_inex);

/* test des attributs demandes */
	ataff = *lep_ataff;
	atetat = *lep_atetat;

	if (ataff > 2) return(werr_desc);
	if (atetat> 2) return(werr_desc);

/* test si fin de fichier */
	nelt = lc->l_nelc;

/*****************************************************
*  pas d'erreur decelee : recherche des valeurs      *
******************************************************/
	k =0;
	while (k == 0)
	  {
		if (nelt <= 1) return(sfenr_deb);	/* llb 05/11/92 */
		--nelt;
		elt_ptr =  lc->l_ptre;
		elt_ptr += nelt-1;
		el_ptr = *(elt_ptr);

		if ((atetat == 0) || (atetat == *(el_ptr+1)))
		  {
			if ((ataff == 0) || (ataff == *el_ptr))
			  {
				*lep_ataff = *el_ptr++;
				*lep_atetat = *el_ptr++;
				if (le_val != (BPTR) NULL)
				  {
					for (i=0;i<lc->l_lel;++i) le_val[i] = *(el_ptr++);
				  }
			  	k = 1;
			  }
		   }
	    }

	lc->l_nelc = nelt;
/*
	if (le_val != (BPTR) NULL)
	  {
		for (i=0;i<lc->l_lel;++i) le_val[i] = *(el_ptr++);
	  }
*/

	*le_no = nelt;
	return(OK);

}

/***********************************************
* fonctions de liste
*    	Fonctions LE_MATT mofification d'attributs
*
************************************************/
TYPF	le_matt(ld_no,le_no,le_ataff,le_atetat, le_val, le_com)
	BYTE ld_no;
	WORD le_no;
	BYTE le_ataff;
	BYTE le_atetat;

	BPTR le_val;
	BPTR le_com;
{

extern	ld_tab	ld[MAXMEN];

/* variables internes */

int	ld_er;			/* code erreur */
int	i,j,k;
ld_tab_ptr lc;			/* liste choisi */
BPTR    el_ptr;			/* pointeur sur le descripteur element */
WORD	nelt;			/* numero option */
BPTRPTR elt_ptr;               /* pointeur sur la table de sauv elements */

/************************************
* verification des parametres       *
*************************************/

/* verification init */
	if (fen_ini != 2) return(werr_ini);

/* verification liste  en cours */

	if ((ld_no == 0) || (ld_no >= MAXLD) ) return(werr_desc);
	lc = &(ld[ld_no]);
	if (lc->l_nofen == 0) return(sferr_inex);

	nelt = le_no;
	if ((nelt == 0) || (nelt > lc->l_nbel)) {
		return (sfenr_inex);
		}

	if ((le_ataff == 0) || (le_ataff > 2)) return(werr_desc);
	if ((le_atetat == 0) || (le_atetat > 2)) return(werr_desc);


	if (rt_arg.c > 6 )  		/* nbre max arguments */
		return(RT_err_arg);

	if (rt_arg.c > 4 )   		/* valeur element */
		if (rt_arg.t[4] != TYPE_CHAINE )
			return(RT_err_typ);
	if (rt_arg.c > 5 )   		/* commentaire element */
		if (rt_arg.t[5] != TYPE_CHAINE )
			return(RT_err_typ);

/*****************************************************
*  pas d'erreur decelee : recherche des valeurs      *
******************************************************/

	elt_ptr =  lc->l_ptre;
	elt_ptr += nelt-1;
	el_ptr = *(elt_ptr);

	lc->l_nelc = nelt;

	*(el_ptr++) = le_ataff;
	*(el_ptr++) = le_atetat;


	if (rt_arg.c > 4 )   		/* modifier le libelle elt */
            if ( rt_arg.l[4] >= lc->l_lel )
		for ( i = 0; i < lc->l_lel; i++ )
			*(el_ptr++) = ((BPTR)rt_arg.v[4])[i];
            else
	      {	
		for ( i = 0; i < rt_arg.l[4]; i++ )
			*(el_ptr++) = ((BPTR)rt_arg.v[4])[i];
		while ( i < lc->l_lel )
		  {
			*(el_ptr++) = ' ';
			i++;  
		  }	
	    }	

	if (rt_arg.c > 5 )   		/* modifier le commentaire  */
            if ( rt_arg.l[5] >= lc->l_lcom )
		for ( i = 0; i < lc->l_lcom; i++ )
			*(el_ptr++) = ((BPTR)rt_arg.v[5])[i];
            else
	      {	
		for ( i = 0; i < rt_arg.l[5]; i++ )
			*(el_ptr++) = ((BPTR)rt_arg.v[5])[i];
		while ( i < lc->l_lcom )
		  {
			*(el_ptr++) = ' ';
			i++;  
		  }	
	    }	

	return(OK);

}/*le_matt*/



/***********************************************
* fonctions de liste
*    	Fonctions LE_DEL: supprimer un element
*
************************************************/
TYPF	le_delete(ld_no,le_no)
	BYTE ld_no;
	WORD le_no;
{



extern	ld_tab	ld[MAXMEN];

/* variables internes */

WORD	i;
ld_tab * lc;			/* liste choisi */
BPTR    el_ptr;			/* pointeur sur le descripteur element */
BPTRPTR elt_ptr;               /* pointeur sur la table de sauv elements */
WDESC_PTR wd;			/* desc fenetre */

/************************************
* verification des parametres       *
*************************************/

/* verification init */
	if (fen_ini != 2) return(werr_ini);

/* verification liste  en cours */

	if ((ld_no == 0) || (ld_no >= MAXLD) ) return(werr_desc);

	lc = &(ld[ld_no]);
	if (lc->l_nofen == 0) return(sferr_inex);

	if ((le_no == 0) || (le_no > lc->l_nbel)) {
		return (sfenr_inex);
		}

/*****************************************************
*  pas d'erreur decelee : recherche des valeurs      *
******************************************************/

	elt_ptr =  lc->l_ptre;
	elt_ptr += le_no -1;

	f_libere(*(elt_ptr));

	for ( i = le_no;  i < lc->l_mxel ; i++) {
		*elt_ptr  = *(elt_ptr+1);
		elt_ptr++;
	}
	lc->l_nbel--;
	if ( lc->l_nelp > lc->l_nbel )
		lc->l_nelp--;

	/* test si fenetre visible */

	wd = WLOG[lc->l_nofen-1]->wdesc_ptr;
	if ( wd->control & INVISIBLE)
		return(OK);

	/*************
	 test si element supprime etait visible 
	if (( le_no >= lc->l_nelv ) &&
	    (le_no <= lc->l_nelv+(lc->l_nelh*lc->l_nlig)))

		ld_afc(ld_no,lc->l_nelv, lc->l_nelp);
	***********/
return(OK);

}/*le_delete*/

/***********************************************
* 	Fonctions LE_INS Insertion d'un element
*
************************************************/
TYPF le_insert(ld_no,le_no,le_ataff,le_atetat,le_val,le_com)
	BYTE ld_no;
	WPTR le_no;
	BYTE le_ataff;
	BYTE le_atetat;
	BPTR le_val;
	BPTR le_com;
{
	int	le_er;			/* code erreur */
	WORD 	nole=0;
	nole = GetAbalWord( le_no );
	le_er = le_creatc(ld_no,&nole,le_ataff,le_atetat,le_val,le_com);
	PutAbalWord( le_no, nole );
	return(le_er);
}

/***********************************************
* fonctions de liste
*    	Fonctions LE_CLOSE fermeture d'une liste
*
************************************************/
TYPF	ld_close(ld_no)
	BYTE ld_no;
{

extern	ld_tab	ld[MAXMEN];

/* variables internes */

int	ld_er;			/* code erreur */
int	i,j,k;
ld_tab  * lc;			/* liste choisi */
BPTR    el_ptr;			/* pointeur sur le descripteur element */
WORD	nelt;			/* numero option */
BPTRPTR elt_ptr;               /* pointeur sur la table de sauv elements */

/************************************
* verification des parametres       *
*************************************/

/* verification init */
	if (fen_ini != 2) return(werr_ini);

/* verification liste  en cours */

	if ((ld_no == 0) || (ld_no >= MAXLD) ) return(werr_desc);
	lc = &(ld[ld_no]);
	if (lc->l_nofen == 0) return(sferr_inex);

	lc->l_ferm = 1;
	return(OK);
}


/***********************************************
* fonctions de liste
*    	Fonctions LD_AFF affichage d'une liste
*
************************************************/

TYPF	ld_aff(ld_no,le_nod,le_nop)
	BYTE ld_no;
	WORD le_nod;
	WORD le_nop;
{
/* variables externes */

extern BYTE fen_ini;
extern	ld_tab	ld[MAXMEN];
TYPF	ld_afc();
TYPF    wselect(WORD);

int	ld_er;
ld_tab * lc;
WORD    neld,nelp,f;
WORD 	fl_aff;
/************************************
* verification des parametres       *
*************************************/

/* verification init */
	if (fen_ini != 2) return(werr_ini);

/* verification liste  en cours */

	if ((ld_no == 0) || (ld_no >= MAXLD) ) return(werr_desc);
	lc = &(ld[ld_no]);

	if (lc->l_nofen == 0) return(sferr_inex);

	neld = le_nod;
	if ((neld == 0) || (neld > lc->l_nbel)) {
		return (sfenr_inex);
		}

	nelp = le_nop;
	if ((nelp == 0) || (nelp > lc->l_nbel)) {
		return (sfenr_inex);
		}
	if (nelp < neld) return (werr_desc);

/******************************************
* Recuperer le type optionnel d'affichage *
******************************************/

  fl_aff = 1;

  if(rt_arg.c > 3)
    {
     	if(rt_arg.t[3] == TYPE_POURCENT)
		fl_aff = GetAbalWord( rt_arg.v[3] );
     	else if(rt_arg.t[3] == TYPE_DEUXPOINT)
		fl_aff = GetAbalLong( rt_arg.v[3] );
       	else	return(RT_err_typ);
     }

/*****************************************************
*  pas d'erreur decelee : remplissage de la fenetre  *
******************************************************/
	f = lc->l_nofen;
	wselect(f);

/*01/09/93	ld_er =ld_afc(ld_no,le_nod,le_nop, 1);*/

	ld_er =ld_afc(ld_no,le_nod,le_nop, fl_aff);
	return(ld_er);
}



TYPF	ld_afc(ld_no,le_nod,le_nop, fl_aff)
	BYTE ld_no;
	WORD le_nod;
	WORD le_nop;
	WORD fl_aff;	/* 0 Normal
			   1 Inverse
			   2 Surintens	 de  element positionne */

{
/* variables externes */

extern	ld_tab	ld[MAXMEN];
extern	WORD	bv_f;		/* fenetre boite en cours */
extern	BYTE 	bv_m;		/* menu boite en cours */
extern  BYTE	nomena;		/* menu actif */

/* fonctions utilisees */

TYPF	le_af(); 		/* affichage el 0 normal 1 positionne */
TYPF	bv_aff();
TYPF	wselect(WORD);
TYPF 	update_scroll_bar();

/* variables internes */

int	ld_er;			/* code erreur */
int	i,j,k;
ld_tab  * lc;			/* liste choisi */
BPTR    el_ptr;			/* pointeur sur le descripteur element */
WORD	neld,nelp,nelt;		/* numero option */
WORD	lel,nbel,lcom,laff;	/* valeurs en cours */
BPTRPTR elt_ptr;               /* pointeur sur la table de sauv elements */
WORD	f;			/* fenetre de la liste */
bv_desc bv_de;

WORD	rs_bvf;			/* sauvegarde des zones bv */
BYTE	rs_bvm;
WORD 	nb_it, it_top;		/* variables de scroll			*/
BYTE	ombre;


/************************************
* verification des parametres       *
*************************************/

/* verification init */
	if (fen_ini != 2) return(werr_ini);

/* verification liste  en cours */

	if ((ld_no == 0) || (ld_no >= MAXLD) ) return(werr_desc);
	lc = &(ld[ld_no]);

	if (lc->l_nofen == 0) return(sferr_inex);

	neld = le_nod;
	if ((neld == 0) || (neld > lc->l_nbel)) {
		return (sfenr_inex);
		}
	nelp = le_nop;
	if((nelp == 0) || (nelp > lc->l_nbel)) {
		return (sfenr_inex);
		}

	if (nelp < neld) return (werr_desc);

/* verif flag d'affichage */

	if(fl_aff > 2) return(werr_desc);

/*****************************************************
*  pas d'erreur decelee : remplissage de la fenetre  *
******************************************************/

/* invisible souris */
#ifdef DOS
	mouse_off();
#endif
	f = lc->l_nofen;

	ld_er = wgel(f);

	ld_er = wfgen(f,CLFUN);

	lc->l_nelv= neld;
	nelt = neld;

	if (lc->l_typa == 1)
	  {

/* affichage */
		for (j = 1 ; j <= lc->l_nlig ; ++j)
		  {
/* recherche fin d'affichage */

			k = nelt;
			while (k > lc->l_ncolt) k -= lc->l_ncolt;

			for (i=0; (i < lc->l_nelh) && (k+i <= lc->l_ncolt) ; ++i)
			  {
				ld_er = le_af(ld_no,nelt,0);
				nelt += 1;
			  }
			if (lc->l_typd == 1)
				nelt += lc->l_ncolt - lc->l_nelh;
		  }
	  }

	else
	  {

		for (j = 1 ; j <= lc->l_nelh; ++j )
		  {
/* recherche fin d'affichage */

			k = nelt;
			while (k > lc->l_nligt) k -= lc->l_nligt;

			for (i=0; (i < lc->l_nlig) && ( k+i <= lc->l_nligt) ; ++i)
			  {
				ld_er = le_af(ld_no,nelt,0);
				nelt += 1;
			  }
			if (lc->l_typd == 2)
				nelt += lc->l_nligt - lc->l_nlig;
		  }
	  }

/* positionnement de la barre de selection */

	   ld_er = le_af(ld_no, nelp, fl_aff);
	   if (ld_er != 0)
	       return(werr_desc);
	   lc->l_nelp = nelp;


/* udate de la scroll bar */
  if(lc->l_typd == 1)
    {
     nb_it = (lc->l_typa == 1) ? lc->l_ncolt : ((lc->l_nbel/lc->l_nligt)+(((lc->l_nbel%lc->l_nligt) == 0) ? 0 : 1));
     nb_it = nb_it * (lc->l_laff+1);
     it_top = (lc->l_typa == 1) ? (le_nod-1) : ((le_nod-1)/lc->l_nligt);
     it_top = max(it_top * (lc->l_laff+1), 1);
    }
  else
    {
     nb_it = (lc->l_typa == 1) ? (lc->l_nbel/lc->l_ncolt)+(((lc->l_nbel%lc->l_ncolt) == 0) ? 0 : 1) : lc->l_nbel;
     it_top = (lc->l_typa == 1) ? ((le_nod-1)/lc->l_ncolt)+1 : le_nod;
    }
  update_scroll_bar(lc->l_nofen, lc->l_typd, nb_it, it_top);

/* affichage de la fenetre a jour */
	ld_er = wvis(f);

/* affichage des bv et menu si multiple */
	if ((lc->l_mult == 1) && !(lc->control & NO_BV))
	  {
		rs_bvm = bv_m;			/* sauvegarde bv */
		rs_bvf = bv_f;
		bv_m = lc->l_bvm;
		bv_f = lc->l_bvf;

		bv_de.bv_nbc = 3;
		bv_de.bv_plig = lc->l_plig +lc->l_nlig + 1;
		j = (lc->l_nelh*lc->l_laff)/2;
		bv_de.bv_pcol = lc->l_pcol+j + 1;

		bv_de.bv_noptd = 1;
		bv_de.bv_laff = 0;
		bv_de.bv_stlf = lc->l_styf;

/* si le style de la liste est ombre, le style de la BV ne l'est pas */
		ombre = 0;
		if (lc->l_styf < 15 )
		  {
		    if 	( lc->l_styf & SFOMB)
			bv_de.bv_stlf -= SFOMB;
		}
		else	/* style = 20..27 */
		{

		 ombre = stf[(lc->l_styf-15)].f_ombre;
		 if ( ombre )
		   stf[(lc->l_styf-15)].f_ombre = 0;
	}

		bv_aff( (bv_desc_ptr) &bv_de , (BPTR) NULL, 2);

/* restituer ombre dans style */
		if ( ombre )
		    stf[(lc->l_styf-15)].f_ombre = ombre;

		lc->l_bvm = bv_m;		/* sauvegarde lm et rest bv */
		lc->l_bvf = bv_f;
		bv_m = rs_bvm;
		bv_f = rs_bvf;

	  }
  /* affichage OK, on rend la liste mouse_sensitive */
  put_item_mouse_list(lc->l_nofen);

  /* souris visible */
#ifdef DOS
  mouse_on();
#endif
  return(ld_er);
}

/********************************************************
* fonctions de listes
*    	Fonctions LE_AF affichage d'un element
*       (fonction interne)
*********************************************************/

TYPF	le_af (ld_no,nelt,type)
BYTE ld_no;			/* liste */
WORD nelt;			/* element a afficher */
BYTE type;			/* 0 normal 	 */
				/* 1 Selectionn‚ (inverse) */
				/* 2 Surintensit‚ 	   */
{

  /* variables externes */
  extern	cof_tab co;
  extern  char lispace[132];
  extern  WORD ld_plig;
  extern  WORD ld_pcol;
  extern	ld_tab	ld[MAXMEN];

  /* variables internes */

  ld_tab  * lc;
  WORD	f;			/* fenetre */
  int	ld_er;			/* code erreur */
  WORD	icol;
  int	i,j,k;
  BPTR    el_ptr;		/* pointeur sur le descripteur option */
  BPTRPTR  elt_ptr;
  BYTE	atb_ec;			/* attribut en cours */
  BYTE	inda;			/* 0 = pas a afficher */
  char c;



  lc = &(ld[ld_no]);
  f = lc->l_nofen;

  /* recherche si element a afficher et position ligne/colonne */


  j = lc->l_nelv;
  if(nelt < j)
    return(werr_desc);
  if(nelt > lc->l_nbel)
    return(werr_desc);

  inda = 0;
  ld_plig = 1;
  ld_pcol = 0;

  if(lc->l_typa == 1)
    /* affichage horizontal */
    {
     while(inda == 0)
       {

	if((nelt >= j) && (nelt < j+lc->l_nelh))
	  {
	   inda = 1;
	   ld_pcol = nelt - j;
	  }
	else
	  {
	   j += lc->l_ncolt;
	   ++ld_plig;
	   if(ld_plig > lc->l_nlig)
	     inda = 2;
	  }
       }
    }

  else
    /* affichage vertical */
    {
     while(inda == 0)
       {
	if((nelt>=j) && (nelt < j+lc->l_nlig))
	  {
	   inda = 1;
	   ld_plig = nelt - j +1;
	  }
	else
	  {
	   j += lc->l_nligt;
	   ++ld_pcol;
	   if (ld_pcol >= lc->l_nelh) inda = 2;
	  }
       }
    }

  if(inda != 1)
    return (inda);

  icol = (ld_pcol*(lc->l_laff+1)) +1;
  wposcur(f,ld_plig,icol);
  watb(f,lc->l_at.atbc,lc->l_at.colc,lc->l_at.colf);
#ifdef DOS
  mouse_off();
#endif
  if(nelt <= lc->l_nbel)
    /* element existant */
    {
     elt_ptr =  lc->l_ptre;
     elt_ptr += nelt-1;
     el_ptr = *(elt_ptr);

     /* envoi du caractere actif */
     if(*(el_ptr+1) == 1)
       {
	watb(f,co.o_actif.catbc,lc->l_at.colc,lc->l_at.colf);
	wwrite(f,1,(BPTR) &(co.o_lactif));
       }
     else
       {
	c = ' ';
	wwrite(f,1,(BPTR)&c);
       }

     /* envoi du nom d'option */
     if(type == 1)
       {
	if(*(el_ptr+1) == 1)
	  watb(f,co.o_selec.atbc,co.o_actif.ccolc,co.o_selec.colf);
	else
	  watb(f,co.o_selec.atbc,co.o_selec.colc,co.o_selec.colf);
       }
     else
       if(((*(el_ptr+1) != 1)) && ( type == 0))
	 {
	  if(*el_ptr == 2)                /* Gris‚*/
	    watb(f,co.o_grise.atbc,co.o_grise.colc,lc->l_at.colf);
	  else
	    watb(f,lc->l_at.atbc,lc->l_at.colc,lc->l_at.colf);
	 }
       else  				/* type = 2 ou Actif */
	 {
	  watb(f,co.o_actif.catbc,co.o_actif.ccolc,lc->l_at.colf);
	 }
     ld_er = wwrite(f,lc->l_laff,(BPTR) el_ptr+2);
    }
  else
    {
     ld_er = wwrite(f,(lc->l_laff)+1,(BPTR) lispace);
    }
#ifdef DOS
  mouse_on();
#endif
  return(ld_er);
}





/***********************************************
* fonctions de listes
*    	Fonctions LD_CHOIX choix d'un element
*
************************************************/

TYPF ld_choix(ld_no,lep_nod,lep_nop,le_typc,val_ptc)
BYTE ld_no;
WPTR lep_nod;
WPTR lep_nop;
BPTR le_typc;
BPTR val_ptc;


{
	TYPF  ld_choixc();


	int  lc_er;			/* code erreur */
	BYTE kexit;
	WORD noplep;
	WORD nodlep;

	nodlep = GetAbalWord( lep_nod);
	noplep = GetAbalWord( lep_nop);

	if(rt_arg.c > 6)
		return(RT_err_arg);
	if (rt_arg.c > 5) {
		if ((rt_arg.t[5] != (TYPE_CHAINE | MODIFIABLE))
		&&  (rt_arg.t[5] != (TYPE_DEUXPOINT | MODIFIABLE))
		&&  (rt_arg.t[5] != (TYPE_POURCENT | MODIFIABLE)))
			return(RT_err_typ);
		}
    	if (!(lc_er = ld_choixc(ld_no,&nodlep,&noplep,le_typc,val_ptc,(BPTR)&kexit) )) {
		PutAbalWord( lep_nod, nodlep );
		PutAbalWord( lep_nop, noplep );
		}
	else 	{
		PutAbalWord( lep_nop, 0 );
		}

	/* test si arg de sortie */
	if(rt_arg.c == 6)
		*((BPTR)rt_arg.v[5]) =  kexit;

	return(lc_er);

}





/**********************************
* appel C standard                *
***********************************/

TYPF ld_choixc(ld_no,lep_nod,lep_nop,le_typc,val_ptc,exit)
BYTE ld_no;
WPTR lep_nod;
WPTR lep_nop;
BPTR le_typc;
BPTR val_ptc;
BPTR exit;

{

  /* variables externes */
  extern ld_tab	ld[MAXMEN];
  extern WORD ld_pcol;
  extern WORD ld_plig;
  extern BYTE tc[MAX_TOUCHES];
  extern WORD bv_f;
  extern BYTE bv_m;
  extern bv_tab bvc;
  extern BYTE sa_touche;

  /* fonctions appelees */

  TYPF ld_spc();
  TYPF ld_afc();
  TYPF ld_clear();
  TYPF wselect(WORD);
  TYPF bv_int ();
  TYPF sffind_tch();

  /* variables internes */

  int	ld_er;			/* code erreur */
  int	i;
  int	j,k;
  int avl,avc,maxaf;		/* incrementation 1 ligne/1 colonne 		*/
  ld_tab  * lc;			/* liste choisi 				*/
  BPTR    el_ptr;		/* pointeurs sur le descripteur element 	*/
  BPTR	el_comptr;
  WORD	neld,nelt;		/* numero option 				*/
  WORD	lel,nbel,lcom;		/* valeurs en cours 				*/

  WORD	rs_bvf;			/* sauvegarde fenetre bv std 			*/
  BYTE	rs_bvm;			/* sauvegarde menu bv std 			*/

  BPTRPTR elt_ptr;              /* pointeur sur la table de sauv elements 	*/
  WORD	f;			/* fenetre de la liste 				*/
  BYTE	touche;			/* touche tapee 				*/
  BYTE c;			/* choix validation 				*/
  SWORD val;			/* flag de traitement				*/
  bv_desc bv_de;		/* boite de validation 				*/
  WORD nelp;			/* nø d'element pointe				*/
  SWORD w_use, h_use;		/* largeur et hauteur (utiles) de la liste	*/
  SWORD mouse_m_w_down;		/* marqueur d'etat de la liste			*/
  WORD nb_it, it_top;		/* items de scroll				*/
  SWORD mplig;			/* mouse position (ligne et colone)   		*/
  SWORD mpcol;
  SWORD region;			/* la region concernee par un event		*/
  WDESC_PTR wd;			/* descripteur fenetre de la liste		*/
  WITEM *wi;



  /************************************
  * verification des parametres       *
  *************************************/

  /* verification init */
  if (fen_ini != 2) return(werr_ini);

  /* verification liste  en cours */

  if((ld_no == 0) || (ld_no >= MAXLD))
    return(werr_desc);
  lc = &(ld[ld_no]);

  if(lc->l_nofen == 0)
    return(sferr_inex);

  neld = *lep_nod;

  if((neld == 0) || (neld > lc->l_nbel)) {
		return (sfenr_inex);
		}

  /* recup descripteur de la fenetre */
  wi = WLOG[lc->l_nofen-1];
  wd = wi->wdesc_ptr;

  /* reglage des avances 1 ligne 1 colonne */

  if(lc->l_typa == 1)
    {
     avl = lc->l_ncolt;
     avc = 1;
    }
  else
    {
     avl = 1;
     avc = lc->l_nligt;
    }

  nelt = *lep_nop;
  if((nelt < neld) || (nelt > lc->l_nbel)) {
		return (sfenr_inex);
		}

  lcom = lc->l_lcom;

  lel  = lc->l_lel;

  /* affichage */
  wselect(lc->l_nofen);
  ld_er = ld_afc(ld_no,neld,nelt, 1);
  if(ld_er)
    {
     return(ld_er);
    }
  else
    {
     lc->l_nelv = neld;
     lc->l_nelp = nelt;
    }


  /* calcul des limites de la liste */
  w_use = lc->l_nelh*(lc->l_laff+1);
  h_use = lc->l_nlig;

  /* deplacement dans la liste */

  *le_typc = 0;
  mouse_m_w_down = NO_SCROLLING;


  Wkup_in();

  while(*le_typc == 0)
    {
     nelt = lc->l_nelp;
     elt_ptr =  lc->l_ptre;
     elt_ptr += nelt-1;
     el_ptr = *(elt_ptr);

     /* affichage du commentaire */

     if(lcom != 0)
       {
	el_comptr = el_ptr;
	el_comptr += lel;
	el_comptr += 2;
	lsmessc((WORD)lc->l_nofenc,(BYTE)lcom,(BPTR) el_comptr);
       }


     touche = 255;
     val = 0;
     while((touche == 255) && (val == 0))
       {
	if(event.event == NO_EVENT)
	  wait_eventc(LIST_EVENTS, (EVENT_PTR)&event);
	if(event.event == KEYBOARD)
	  {
	   touche = event.arg;
	   val = 0;
	   event.event = NO_EVENT;
	  }
	else
	  {
	   /* il faut controler que l'evenement concerne la liste */
	   if(mouse_m_w_down == NO_SCROLLING)
	     if((f = get_item_mouse_list(event.plig, event.pcol)) == 0)
	       {
		/* si event ne concerne pas une fenetre mouse_sensitive	*/
		/* on l'ignore 						*/
/*llb18.11.93*/
		if (Wkup_Adress != NULL)
		   {
		    if ( Advise_Exa(event.event) ) {
			    val = T_ESC;
			    break;
		    }
		}
		event.event = NO_EVENT;
		continue;
	       }
	     else
	       if(f != lc->l_nofen)
		 if (event.event == MOUSE_DOWN)
		   {
	 	    if(lc->control & SOR_SI_TAB)
		          val = T_TAB;
		    else
		    {
		      if (( lc->l_mult == 1 ) && ms_inside(lc->l_nofen,event.plig,event.pcol))
		          val = T_TAB;
		      else
			{
			  val = T_ESC;
			  event.event = NO_EVENT;
		      }
		    }
		    break;
		 }/* MOUSE_DOWN */
		 else
		   {
		    event.event = NO_EVENT;
		    continue;
		   }


	   /* calcul de la region concernee par l'event */
	   mplig = event.plig - wi->wdesc_ptr->pos_lig + 1;
	   mpcol = event.pcol - wi->wdesc_ptr->pos_col + 1;
	   region = NO_REGION;
	   if(mpcol > w_use)
	     if(mpcol == w_use+1)
	       if(wd->control&SCROLLING_V)
		 region = SCROLL_BARRE;
	       else
		 region = CADRE_DROIT;
	     else
	       region = CADRE_DROIT;
	   else
	     if(mplig > h_use)
	       if(mplig == h_use+1)
		 if(wd->control&SCROLLING_H)
		   region = SCROLL_BARRE;
		 else
		   region = CADRE_BAS;
	       else
		 region = CADRE_BAS;
	     else
	       if(mpcol <= 0)
		 region = CADRE_GAUCHE;
	       else
		 if(mplig <= 0)
		   region = CADRE_HAUT;
		 else
		   region = INSIDE_LIST;

	   /* on recherche l'element (visible) concerne par l'event */
	   if(region == INSIDE_LIST)
	     if(lc->l_typa == 1)
	       nelp = ((mplig-1)*lc->l_ncolt)+((mpcol-1)/(lc->l_laff+1))+lc->l_nelv;
	     else
	       nelp = (((mpcol-1)/(lc->l_laff+1))*lc->l_nligt)+mplig+lc->l_nelv-1;

	   /* suivant l'event et la region, on interprete */

	   switch(event.event)
	     {
/*     case MOUSE_UP:
	mouse_m_w_down = NO_SCROLLING;
	event.event = NO_EVENT;
	break;
      case MOUSE_CLICK:*/

	      case MOUSE_UP:
	      case MOUSE_D_CLICK:
	      case MOUSE_DOWN:
	      case MOUSE_IS_DOWN:
		if(region == INSIDE_LIST)
		  {
		   /* test si double click */
		   if((lc->l_mult == 1) && (event.event == MOUSE_D_CLICK))
		     {
		      val = T_TAB;
		      event.event = NO_EVENT;
		      break;
		     }
		   /* test si simple click mais repetitif */
		   if((nelp == lc->l_nelp) && (lc->l_mult == 0) && (event.event == MOUSE_UP))
		     {
		      val = T_ENVOI;
		      event.event = NO_EVENT;
		      mouse_m_w_down = NO_SCROLLING;
		      break;
		     }

		   /* il faut se positionner */
		   if((nelp != lc->l_nelp) && (nelp <= lc->l_nbel))
		     {
		      ld_plig = mplig;
		      ld_pcol = mpcol;
		      nelt = nelp;
		      le_af(ld_no,lc->l_nelp,0);
		      le_af(ld_no,nelt,1);
		      lc->l_nelp = nelt;
		      elt_ptr =  lc->l_ptre;
		      elt_ptr += nelt-1;
		      el_ptr = *(elt_ptr);
		      event.event = NO_EVENT;
		     }
		   if((lc->l_mult == 1) && (event.event == MOUSE_UP) && (nelp <= lc->l_nbel))
		     {
		      val = T_ENVOI;
		      event.event = NO_EVENT;
		      mouse_m_w_down = NO_SCROLLING;
		      break;
		     }
		   if((lc->l_mult == 0) && (event.event == MOUSE_D_CLICK) && (nelp <= lc->l_nbel))
		     {
		      val = T_ENVOI;
		      event.event = NO_EVENT;
		      break;
		     }

		   event.event = NO_EVENT;
		  }
		else
		  if((region == SCROLL_BARRE) && (mouse_m_w_down == NO_SCROLLING))
		    {
		     if(lc->l_typd == 1)
		       {
			nb_it = (lc->l_typa == 1) ? lc->l_ncolt : ((lc->l_nbel/lc->l_nligt)+(((lc->l_nbel%lc->l_nligt) == 0) ? 0 : 1));
			nb_it = nb_it * (lc->l_laff+1);
			it_top = (lc->l_typa == 1) ? (lc->l_nelv-1) : ((lc->l_nelv-1)/lc->l_nligt);
			it_top = max(it_top * (lc->l_laff+1), 1);
		       }
		     else
		       {
			nb_it = (lc->l_typa == 1) ? (lc->l_nbel/lc->l_ncolt)+(((lc->l_nbel%lc->l_ncolt) == 0) ? 0 : 1) : lc->l_nbel;
			it_top = (lc->l_typa == 1) ? (((lc->l_nelv-1)/lc->l_ncolt)+1) : lc->l_nelv;
		       }
		     switch(get_scroll_bar_region(lc->l_nofen, ((wd->control&SCROLLING_V) ? VERTICALE : HORIZONTALE), nb_it, it_top, mplig, mpcol))
		       {
			case SCROLL_UP:
			  if(wd->control&SCROLLING_H)
			    val = F_GAUCHE;
			  else
			    val = F_HAUT;
			  break;

			case SCROLL_DOWN:
			  if(wd->control&SCROLLING_H)
			    val = F_DROITE;
			  else
			    val = F_BAS;
			  break;

			case SCROLL_P_UP:
			  if(wd->control&SCROLLING_H)
			    val = PG_GAUCHE;
			  else
			    val = PG_UP;
			  break;

			case SCROLL_P_DOWN:
			  if(wd->control&SCROLLING_H)
			    val = PG_DROITE;
			  else
			    val = PG_DOWN;
			  break;
		       }
		    }
/*llb21*/
		    else
		      if ( event.event == MOUSE_IS_DOWN)
			switch (region)
			{
			case CADRE_BAS:
			   val = F_BAS;
			   break;
			case CADRE_HAUT:
			   val = F_HAUT;
			   break;
			case CADRE_GAUCHE:
			   val = F_GAUCHE;
			   break;
			case CADRE_DROIT:
			   val = F_DROITE;
			   break;
			}
		event.event = NO_EVENT;
		break;


	      case MOUSE_M_W_DOWN+M_LEFT:
		if(region == CADRE_GAUCHE)
		  {
		   mouse_m_w_down = M_LEFT;
		   set_mouse_position(event.plig, wi->wdesc_ptr->pos_col-1);
		   val = F_GAUCHE;
		  }
		else
		  if((region == INSIDE_LIST) && (nelp <= lc->l_nbel) && (nelp != lc->l_nelp))
		    val = F_GAUCHE;
		event.event = NO_EVENT;
		break;

	      case MOUSE_M_W_DOWN+M_RIGHT:
		if(region == CADRE_DROIT)
		  {
		   mouse_m_w_down = M_RIGHT;
		   val = F_DROITE;
		   set_mouse_position(event.plig, wi->wdesc_ptr->pos_col+wi->wdesc_ptr->nb_col);
		  }
		else
		  if((region == INSIDE_LIST) && (nelp <= lc->l_nbel) && (nelp != lc->l_nelp))
		    val = F_DROITE;
		event.event = NO_EVENT;
		break;

	      case MOUSE_M_W_DOWN+M_UP:
		if(region == CADRE_HAUT)
		  {
		   mouse_m_w_down = M_UP;
		   set_mouse_position(wi->wdesc_ptr->pos_lig-1, event.pcol);
		   val = F_HAUT;
		  }
		else
		  if((region == INSIDE_LIST) && (nelp <= lc->l_nbel) && (nelp != lc->l_nelp))
		    val = F_HAUT;
		event.event = NO_EVENT;
		break;

	      case MOUSE_M_W_DOWN+M_DOWN:
		if(region == CADRE_BAS)
		  {
		   mouse_m_w_down = M_DOWN;
		   set_mouse_position(wi->wdesc_ptr->pos_lig+wi->wdesc_ptr->nb_lig, event.pcol);
		   val = F_BAS;
		  }
		else
		  if((region == INSIDE_LIST) && (nelp <= lc->l_nbel) && (nelp != lc->l_nelp))
		    val = F_BAS;
		event.event = NO_EVENT;
		break;

	     }/* switch(event) */


	  }
       }


     /* on teste si touche d'echappement */
     if(val == 0)
       {
	if(((lc->control&TCH_ESC) != 0) && (sffind_tch(touche) != 0))
	  {
	   *le_typc = 5;
	   *exit = touche;
	   break;
	  }
	else
	  if(touche == sa_touche)
	    {
	     val = T_AIDE;
	    }
	  else
	    if(touche == '+')
	      val = SPACE;
	    else
	      for(i = 0, val = 0; (i < MAX_TOUCHES) && (val == 0); ++i)
		if(tc[i] == touche)
		  val = i+1;
       }

     switch(val)
       {
	/* aide */
	case T_AIDE:
	  if(lc->lis_cle[0] == NULL)
	    sa_aid((BPTR) NULL );
	  else
	    sa_aid(lc->lis_cle);
	  break;

	/* blanc */
	case SPACE:
	  /* on avance systematiquement */
	  if(nelt < lc->l_nbel)
	    ++nelt;
	  else
	     if(lc->l_ferm != 1)
	       {	
		 *le_typc = 3;
		 *exit = tc[SPACE-1];
	         break;
	      }

	  le_af(ld_no,lc->l_nelp,0);
	  lc->l_nelp = nelt;

	  /* si on ne change pas de fenetre OK */
	  ld_er = le_af(ld_no,nelt,1);
	  if(ld_er == 0)
	    break;

	  /* sinon essayer de scroller dans le sens du scroll */

	  if(lc->l_typd == 2)
	    {
	     j = lc->l_nelv + avl;
	     k =  (lc->l_nlig - 1) * avl + (lc->l_nelh - 1) * avc;
	     j += k;

	     if(j <= lc->l_nligt*lc->l_ncolt)
	       {
		lc->l_nelv += avl ;
	       }
	     else
	       {
		lc->l_nelv = 1;
	       }
	    }

	  else
	    {
	     j = lc->l_nelv+avc ;
	     k =  (lc->l_nlig - 1) * avl + (lc->l_nelh - 1) * avc;
	     j += k;

	     if(j <= lc->l_nligt*lc->l_ncolt)
	       {
		lc->l_nelv += avc;
	       }
	     else
	       {
		lc->l_nelv = 1;
	       }
	    }

	  if(lc->l_ferm != 1)
	    if(lc->l_nelv + (lc->l_nlig -1) * avl + (lc->l_nelh - 1) *avc > lc->l_nbel)
	      {
	       *le_typc = 3;
	       *exit = tc[SPACE];	
	       break;
	      }
	    ld_er = ld_afc(ld_no,lc->l_nelv,nelt, 1);
	    break;

	/* back_space */
	case BACK_SP:

	  /* on recule systematiquement */
	  if(nelt > 1)
	    --nelt;
	  else
	    break;

	  le_af(ld_no,lc->l_nelp,0);
	  lc->l_nelp = nelt;

	  /* si on ne change pas de fenetre OK */
	  ld_er = le_af(ld_no,nelt,1);
	  if(ld_er == 0)
	    break;

	  /* sinon essayer de scroller dans le sens du scroll */

	  if(lc->l_typd == 2)
	    {
	     if(lc->l_nelv > avl)
	       {
		lc->l_nelv -= avl;
	       }
	     else
	       {
		lc->l_nelv = lc->l_nligt - lc->l_nlig +1;
	       }
	    }
	  else
	    {
	     if(lc->l_nelv > avc)
	       {
		lc->l_nelv -= avc;
	       }
	     else
	       {
		lc->l_nelv = lc->l_ncolt - lc->l_nelh +1;
	       }
	    }
	  ld_er = ld_afc(ld_no,lc->l_nelv,nelt, 1);
	  break;

	/* curseur bas */
	case F_BAS:

	  if(nelt + avl <= lc->l_nbel)
	    nelt += avl;
	  else
	    {
	     if(lc->l_ferm != 1)
	       {	
		 *le_typc = 3;
		 *exit = tc[F_BAS-1];
	     }	
	     break;
	    }
	  if(ld_plig < lc->l_nlig)
	    /* avancer dans la fenetre */
	    {
	     ++ ld_plig;
	     le_af(ld_no,lc->l_nelp,0);
	     le_af(ld_no,nelt,1);
	     lc->l_nelp = nelt;
	    }
	  else
	    /* test si scroll possible */
	    {
	     if(lc->l_typd == 2)
	       {
		j = lc->l_nelv + avl ;
		k =  (lc->l_nlig - 1) * avl + (lc->l_nelh - 1) * avc;
		j += k;
		if(j <= lc->l_nligt*lc->l_ncolt)
		  {
		   lc->l_nelv += avl;
		   if(lc->l_ferm != 1)
		     if(lc->l_nelv + k > lc->l_nbel)
		       {
			*le_typc = 3;
			*exit = tc[F_BAS-1];
			break;
		       }
		   ld_er = ld_afc(ld_no,lc->l_nelv,nelt, 1);

		   if(ld_er == 0)
		     {
		      lc->l_nelp = nelt;
		     }
		   else
		     {
		      lc->l_nelv -= avl;
		     }
		  }
		else
		  if(lc->l_ferm != 1)
		    if(lc->l_nelv + k > lc->l_nbel)
		      {
		       *le_typc = 3;
		       *exit = tc[F_BAS-1];
		       break;
		      }
	       }
	     }
	  break;

	/* page down */
	case PG_DOWN:
	  if(lc->l_typd == 2)
	    {
	     i = lc->l_nlig * avl;
	     k =   lc->l_nelv + i + (lc->l_nlig -1) * avl + (lc->l_nelh - 1) *avc ;
	     if(k >= lc->l_nbel)
	       {
		if(lc->l_ferm != 1)
		  {
		   *le_typc = 3;
		   *exit = tc[PG_DOWN-1];
		   break;
		  }
		else
		  while(k > lc->l_nligt * lc->l_ncolt )
		    {
		     i -= avl;
		     k -= avl;
		    }
	       }
	     lc->l_nelv += i;
	     nelt += i;
	     if(nelt > lc->l_nbel)
	       {
		if(lc->l_ferm != 1)
		  {
		   *le_typc = 3;
		   *exit = tc[PG_DOWN-1];
		   break;
		  }
		nelt = lc->l_nbel;
	       }
	     ld_er = ld_afc(ld_no,lc->l_nelv,nelt, 1);
	     if(ld_er == 0)
	       lc->l_nelp = nelt;
	     else
	       {
		lc->l_nelv -= i;
		nelt = lc->l_nelp;
		ld_er = ld_afc(ld_no,lc->l_nelv,lc->l_nelp, 1);
	       }

	    }
	  break;

	/* page up */
	case PG_UP:
	  if(lc->l_typd == 2)
	    {
	     i = lc->l_nlig  * avl;
	     while( lc->l_nelv  <= i)
	       i -= avl;
	     lc->l_nelv -= i;
	     nelt -= i;
/* llb 06.05.93 */
	     if (( lc->control & SOR_PAR_HAUT)&&(lc->l_nelp <=lc->l_nlig /*avl*/))
	      {
		*exit = tc[PG_UP-1];
		*le_typc = 6;
		break;
	     }
/* llb fin */
	     ld_er = ld_afc(ld_no,lc->l_nelv,nelt, 1);

	     if(ld_er == 0)
		lc->l_nelp = nelt;
	     else
	       {
		lc->l_nelv += i;
		nelt = lc->l_nelp;
		ld_er = ld_afc(ld_no,lc->l_nelv,lc->l_nelp, 1);
	       }
	    }
	  break;


	/* page droite */
	case PG_DROITE:
	  if(lc->l_typd == 1)
	    {
	     i = lc->l_nelh  * avc;
	     k = (lc->l_nelv + i + (lc->l_nlig -1) * avl + (lc->l_nelh - 1) *avc);
	     if(k >= lc->l_nbel)
	       if(lc->l_ferm != 1)
		 {
		  *le_typc = 3;
		  break;
		 }
	       else
		 while(k > lc->l_nligt * lc->l_ncolt)
		   {
		    i -= avc;
		    k -= avc;
		   }

	       lc->l_nelv += i;
	       nelt += i;

	       if(nelt > lc->l_nbel)
		 {
		  if(lc->l_ferm != 1)
		    {
		     *le_typc = 3;
		     *exit = tc[PG_DROITE-1];
		     break;
		    }
		  nelt = lc->l_nbel;
		 }

	       ld_er = ld_afc(ld_no,lc->l_nelv,nelt, 1);
	       if(ld_er == 0)
		 {
		  lc->l_nelp = nelt;
		 }
	       else
		 {
		  lc->l_nelv -= i;
		  nelt = lc->l_nelp;
		  ld_er = ld_afc(ld_no,lc->l_nelv,lc->l_nelp, 1);
		 }
	    }
	  break;


	/* page gauche */
	case PG_GAUCHE:
	  if(lc->l_typd == 1)
	    {
	     i = lc->l_nelh  * avc;
	     while( lc->l_nelv  <= i)
	       i -= avc;
	     lc->l_nelv -= i;
	     nelt -= i;
	     ld_er = ld_afc(ld_no,lc->l_nelv,nelt, 1);

	     if(ld_er == 0)
	       {
		lc->l_nelp = nelt;
	       }
	     else
	       {
		lc->l_nelv +=i;
		nelt = lc->l_nelp;
		ld_er = ld_afc(ld_no,lc->l_nelv,lc->l_nelp, 1);
	       }
	    }
	  break;

	/* curseur haut */
	case F_HAUT:
		  if(ld_plig > 1)
	    /* remonter dans la fenetre */
	    {
	     nelt -= avl;
	     le_af(ld_no,lc->l_nelp,0);
	     le_af(ld_no,nelt,1);
	     lc->l_nelp = nelt;
	    }
	  else
	    {
	     if(lc->l_typd == 2)
	       {
		if(lc->l_nelv > avl)
		  {
		   lc->l_nelv -= avl;
		   nelt -= avl;
		   ld_er = ld_afc(ld_no,lc->l_nelv,nelt, 1);
		   if(ld_er == 0)
		     {
		      lc->l_nelp = nelt;
		     }
		   else
		     {
		      lc->l_nelv += avl;
		     }
		  }
		  else
		   if (( lc->control & SOR_PAR_HAUT)&&(nelt <= avl))
		    {
			*exit = tc[F_HAUT-1];
			*le_typc = 6;
			break;
		   }
	     }/* typd = 2 */
	    }

	  break;

	/* curseur droit */
	case F_DROITE:
	  if(nelt + avc <= lc->l_nbel)
	    {
	     nelt += avc;
	     if(ld_pcol+1 < lc->l_nelh)
	       /* avancer dans la fenetre */
	       {
		++ld_pcol;
		le_af(ld_no,lc->l_nelp,0);
		le_af(ld_no,nelt,1);
		lc->l_nelp = nelt;
	       }
	     else
	       /* test si scroll possible */
	       {
		if(lc->l_typd == 1)
		  {
		   j = lc->l_nelv + avc;
		   k =  (lc->l_nelh - 1) * avc + (lc->l_nlig - 1) * avl;
		   j += k;
		   if(j <= lc->l_nligt*lc->l_ncolt)
		     {
		      lc->l_nelv += avc;
		      if(lc->l_ferm != 1)
			if(lc->l_nelv + i + k > lc->l_nbel)
			  {
			   *le_typc = 3;
			   *exit = tc[F_DROITE-1];
			   break;
			  }
		      ld_er = ld_afc(ld_no,lc->l_nelv,nelt, 1);
		      if(ld_er == 0)
			{
			 lc->l_nelp = nelt;
			}
		      else
			{
			 lc->l_nelv -= avc;
			}
		     }
		   else
		     if(lc->l_ferm != 1)
		       if(lc->l_nelv +j + k > lc->l_nbel)
			 {
			  *le_typc = 3;
			  *exit = tc[F_DROITE-1];
			  break;
			 }
		  }
	       }
	    }
	  break;

	/* curseur gauche */
	case F_GAUCHE:
	  if(ld_pcol > 0)
	    {
	     nelt -= avc;
	     --ld_pcol;
	     le_af(ld_no,lc->l_nelp,0);
	     le_af(ld_no,nelt,1);
	     lc->l_nelp = nelt;
	    }
	  else
	    {
	     if(lc->l_typd == 1)
	       {
		if(lc->l_nelv > avc)
		  {
		   nelt -= avc;
		   lc->l_nelv -= avc;
		   ld_er = ld_afc(ld_no,lc->l_nelv,nelt, 1);
		   if(ld_er == 0)
		     {
		      lc->l_nelp = nelt;
		     }
		   else
		     {
		      lc->l_nelv += avc;
		     }
		  }
	       }
	    }
	  break;


	/* home */
	case T_HOME:
	  nelt = lc->l_nelv;
	  le_af(ld_no,lc->l_nelp,0);
	  le_af(ld_no,nelt,1);
	  lc->l_nelp = nelt;
	  break;


	/* end */
	case T_END:
	  nelt = lc->l_nelv;
	  nelt += (lc->l_nlig - 1) * avl;
	  nelt += (lc->l_nelh - 1) * avc;
	  if(nelt > lc->l_nbel) nelt = lc->l_nbel;
	    le_af(ld_no,lc->l_nelp,0);

	  while((ld_er = le_af(ld_no,nelt,1)) != 0)
	    nelt--;
	  lc->l_nelp = nelt;

	  break;


	/* abandon */
	case T_ESC:
	  if(!(lc->control & NO_EFF))
	    {
	     ld_er = ld_clear(ld_no);
	     *le_typc = 2;
	     *exit = ESC;
	    }
	  else
	    {
	     le_af( ld_no, nelt, 2);		/* SURINT */
	     *le_typc = 2;		/* Pr‚ciser le type de sortie */
	     *exit = ESC;
	    }
	  Wkup_out();
	  return(OK);

	case SHIFT_TAB:
	  if(lc->control & SOR_SI_TAB)
	    {
	     *le_typc = 4;
	     *exit = tc[SHIFT_TAB-1];
	     break;
	    }
              

	/* tab = chgt menu */
	case T_TAB:
	  if(lc->control & SOR_SI_TAB)
	    {
	     *le_typc = 4;
	     *exit = TAB;
	     break;
	    }
	  if(lc->l_mult != 1)
	    break;
	  le_af(ld_no, nelt, 0);

	  /* en multiple appel de la validation */
	  bv_de.bv_nbc = 3;
	  bv_de.bv_plig = lc->l_plig +lc->l_nlig + 1;
	  bvc.v_pcol = (lc->l_pcol)+(lc->l_nelh*lc->l_laff + 1)/2 ;
	  bv_de.bv_noptd = 1;
	  bv_de.bv_laff = 0;
	  bv_de.bv_stlf = 1;
	  rs_bvm = bv_m;			/* rest bv lm */
	  rs_bvf = bv_f;
	  bv_m = lc->l_bvm;
	  bv_f = lc->l_bvf;

	  ld_er = bv_int((bv_desc_ptr)&bv_de, (BPTR)NULL, (BPTR)&c, 2);

	  switch(c)			/* modif 2011 */
	    {
	     case 3:
	       {
		*le_typc = 2;
		*exit = ESC;
		break;
	       }

	     case 2:
	       {
		md_aff(lc->l_bvm,1,0);
		le_af(ld_no,nelt,1);
		break;
	       }

	     case 1:
	       {
		*le_typc = 1;
		*exit = RC;
		break;
	       }
	    }
	  bv_m = rs_bvm;			/* rest bv std */
	  bv_f = rs_bvf;
	  break;


	/* envoi */
	case T_ENVOI:
	  /* en multiple on change de type */
	  if(lc->l_mult == 1)
	    {
	     i = *(++el_ptr);
	     if(i == 1)
	       *el_ptr = 2;
	     else
	       *el_ptr = 1;
	     ld_er = le_af(ld_no,nelt,1);
	     break;
	    }

	  *le_typc = 1;
	  *exit = RC;
	  break;


	/* defaut */
	default:

	  break;

       } /* switch */

    } /* while */

  *lep_nod = lc->l_nelv;
  *lep_nop = nelt;

  if((val_ptc != (BPTR) NULL) && (*le_typc != 3))
    {
     lc = &(ld[ld_no]);
     elt_ptr =  lc->l_ptre;
     elt_ptr += nelt-1;
     el_ptr = *(elt_ptr);
     el_ptr+=1;
     for(i=0; i<lel; ++i)
       val_ptc[i] = *++el_ptr;

     if(lc->control & NO_EFF)
       le_af( ld_no, nelt, 2);	/* SURINT */
     else
       ld_er = ld_clear(ld_no);
    }

  lc->l_nelc = 0;
  Wkup_out();
  return(OK);

}


/***********************************************
* fonctions de listes
*    	Fonctions LD_CLEAR effacement d'une liste
*
************************************************/

TYPF	ld_clear(ld_no)
	BYTE ld_no;
{
/* variables externes */

extern	ld_tab	ld[MAXLD];
extern	WORD	bv_f;
extern	BYTE	bv_m;

/* variables internes */

int	ld_er;			/* code erreur */
int 	i,j,k;
WORD	f;			/* fenetre en cours */
ld_tab  * lc;			/* liste choisi */



/************************************
* verification des parametres       *
*************************************/

/* verification init */
	if (fen_ini != 2) return(werr_ini);

/* verification no de liste */

	if (ld_no >= MAXLD) return(werr_desc);
	if (ld_no != 0)
		{
			f = ld[ld_no].l_nofen;
			if (f == 0) return(sferr_inex);
			i = ld_no ;
			j = ld_no ;
	   	}
	else
		{
			i = 1;
			j = MAXLD-1;
		}

	for (k=i;k<=j;++k)
	  {
		lc = &ld[k];

		if (lc->l_mult == 1)
		  {
			if (lc->l_bvm != 0)
				md_sup(lc->l_bvm);
			lc->l_bvm = 0;
			if (lc->l_bvf != 0)
				wsup(lc->l_bvf);
			lc->l_bvf = 0;
		  }

		f = lc->l_nofen;		/* fenetre liste invisible */
		ld_er = winv(f);
		if (ld_er) return(ld_er);
		lc->l_inda = 0;
		f = lc->l_nofenc;		/* fenetre commentaire inv */
		if (f) winv(f);
	  }


  /* clear OK, on rend la liste non mouse_sensitive */
  del_item_mouse_list(lc->l_nofen);

  return(OK);
}

/***********************************************
* fonctions de listes
*    	Fonctions LD_SUP suppression d'une liste
*
************************************************/
TYPF	ld_sup(ld_no)
	BYTE ld_no;
{
extern	ld_tab	ld[MAXLD];
extern	WORD	bv_f;
extern	BYTE	bv_m;
TYPF	md_sup();

/* variables internes */

int	ld_er;		/* code erreur */
int 	i,j,k,nelt;
WORD	f;			/* fenetre en cours */
ld_tab  * lc;			/* liste choisi */
BPTR    el_ptr;			/* pointeurs sur le descripteur element */
BPTRPTR elt_ptr;          /* pointeur sur la table de sauv elements */

/************************************
* verification des parametres       *
*************************************/

/* verification init */
	if (fen_ini != 2) return(werr_ini);

/* verification no de liste */

	if (ld_no >= MAXLD) return(werr_desc);
	if (ld_no != 0)
		{
			f = ld[ld_no].l_nofen;
			if (f == 0) return(sferr_inex);
			i = ld_no ;
			j = ld_no ;
	   	}
	else
		{
			i = 1;
			j = MAXLD-1;
		}

	for (k=i;k<=j;++k)

	  {
		lc = &ld[k];
		if (lc->l_nofen != 0)
		 {
			if (lc->l_mult == 1)
			  {
				if (lc->l_bvm != 0)
				md_sup(lc->l_bvm);
				lc->l_bvm = 0;
				if (lc->l_bvf != 0)
				wsup(lc->l_bvf);
				lc->l_bvf = 0;
			  }

			f = lc->l_nofen;		/* fenetre liste invisible */
			wsup(f);
			lc->l_inda = 0;
			f = lc->l_nofenc;		/* fenetre commentaire inv */
			if (f) wsup(f);
			lc->l_nofen = 0;

			elt_ptr =  lc->l_ptre;


			for (nelt=0;nelt<lc->l_nbel;++nelt)
			  {
				el_ptr = *(elt_ptr);
				f_libere ( el_ptr);
				elt_ptr += 1;
			  }

			f_libere (lc->l_ptre);
		  }

	  }

	return(OK);
}

/***********************************************
* fonctions de listes
*    	Fonctions LIST_INFO info d'une liste
*
************************************************/
TYPF	list_info(ld_no, info)
	BYTE 	ld_no;
	LD_INFO_PTR info;
{
extern	ld_tab	ld[MAXLD];
WDESC_PTR   wd;
WITEM *wi;
WORD f;
WORD cad;

/* verification init */
	if (fen_ini != 2) return(werr_ini);

/* verification no de liste */

	if ( (ld_no >= MAXLD) || (ld_no==NULL) )
		return(werr_desc);

	f  = ld[ld_no].l_nofen;
	if(f == 0)
	  return(sferr_inex);

	wi = WLOG[f-1];
	wd = wi->wdesc_ptr;
	cad = (WORD)wd->cad;
	info->ld_fun = f;                       /* No fenetre 	  */
	info->ld_plig = wd->pos_lig - cad;		/* coord. fenetre */
	info->ld_pcol = wd->pos_col - cad;
	info->ld_nlig = wd->nb_lig + (2*cad);
	info->ld_ncol = wd->nb_col + (2*cad);

	info->ld_cad = (BYTE)wd->cad;		/* AJOUT EDS le 09/08/91*/
	info->ld_fatb = wd->bas_atb;	 	/* FIN AJOUT            */

	info->ld_control = ld[ld_no].control;	/* mode fonctionnement */
	info->ld_type = (WORD)ld[ld_no].l_mult; /* liste simple ou multiple */

	if (ld[ld_no].l_ferm == 1 )
		info->ld_type |= 128;		/* liste ferm‚e*/
	info->ld_val = ld[ld_no].l_lel;		/* longueur valeur element */

	return(OK);

}/*list_info(); */

/* fin de fichier */

