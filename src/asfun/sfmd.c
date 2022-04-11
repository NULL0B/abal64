/************************************************************************
* Services Fenetres - Menu			          		*
*-----------------------------------------------------------------------*
* Source : sfmd.c                   					*
*-----------------------------------------------------------------------*
* Version : 1.1a                    					*
* Mise a jour le : 15/06/1990   sb  					*
* Modif le 26/07/90 : wselect ds md_aff					*
* Modif le 15/11/90 : suppr fen comment+mo_aff				*
* ASFUN 1.3a								*
*		Control et cle aide dans MD_CREAT			*
* 20.01.92	style ombrage						*
* 15.04.92	EDS sortie sur touches d'echappement			*
* 12.05.92	EDS mouse						*
* 19.05.92	llb menu_way()                                  	*
* 01.04.93	llb adaptation nouveaux styles fenetre			*
* 02.09.93	llb gestion item non selectionnable (souris)		*
*		    barre sur item grises				*
* 06.10.93	llb corr gestion souris+menu(0,0)			*     
*************************************************************************
* Fonctions                         					*
*                                   					*
* - md_creat       creation menu    					*
* - mo_creat       creation option  					*
* - md_aff         affiche menu     					*
* - md_clear       efface  menu     					*
* - md_sup         suppres menu     					*
* - md_opt         choix   option   					*
* - mo_sup         suppres option   					*
* - mo_sep         separation       					*
* - mo_modif       modif option     					*
* - mo_matt        modif attributs  					*
* - mo_latt        lect. attributs  					*
************************************************************************/


#include "sfundef.h"
#include "bda.h"

#include "mouse.h"


#define MENU_EVENTS	KEYBOARD+MOUSE_UP+MOUSE_DOWN+MOUSE_M_W_DOWN+MOUSE_IS_DOWN


#define NO_REGION	-2
#define INSIDE_MENU	-1
#define SCROLL_BARRE	M_LEFT+M_RIGHT+M_UP+M_DOWN
#define CADRE_GAUCHE	M_LEFT
#define CADRE_DROIT	M_RIGHT
#define CADRE_HAUT	M_UP
#define CADRE_BAS	M_DOWN





/* variable globales pour list_info() */

extern WITEM* 		WLOG[MAXFUN];
extern GLOBAL BDA_ARG 	rt_arg;

extern EVENT_STR	event;

extern BYTE tb_style[MAXSTF];

extern BYTE last_men;
extern BPTR Wkup_Adress;



/**********************************************
* fonctions generales de gestion de la pile
***********************************************/

/**********************************************
*     Verification si pile non touchee
***********************************************/

void ver_me(md_no)
BYTE md_no;		/* menu a controler */
{

  /* variable internes */

  WORD	i;

  /* variables externes */

  extern	me_tab	me[MAXENCH];
  extern	WORD cpt_e;
  extern  WORD ind_e;


  if(cpt_e > 0)
    {
     for(i = 0; i < cpt_e; ++i)
       {
	if((me[i].me_ma == md_no) || (me[i].me_mc == md_no))
	  {
	   cpt_e = 0;
	   ind_e = 0;
	   last_men = 0;
	   break;
	  }
       }
    }

  return;
}




/**********************************************
*     Ajout d'un element dans la pile
***********************************************/

void add_me(md_na,mo_na,md_nc)
BYTE md_na;		/* menu appelant */
BYTE mo_na;		/* option appelante */
BYTE md_nc;		/* menu chaine */

{

  /* variable internes */

  WORD i;

  /* variables externes */

  extern me_tab	me[MAXENCH];
  extern WORD cpt_e;

  if(cpt_e  == MAXENCH)
    return;

  if((cpt_e > 0) && (me[cpt_e-1].me_mc != md_na))
    cpt_e = 0;		/* changement de pile */

  me[cpt_e].me_ma = md_na;
  me[cpt_e].me_oa = mo_na;
  me[cpt_e].me_mc = md_nc;
  cpt_e++;
  return;

}/*add_me*/





/***********************************************
* fonctions chemin de menus
*    	Fonctions MD_WAY
************************************************/

TYPF md_way(nivo, chemin)
BPTR nivo;
BPTR chemin;

{
  WORD i,j;
  BYTE md_no;

  extern WORD cpt_e;
  extern me_tab me[MAXENCH];
  extern md_tab md[MAXMEN];

  md_tab *mc;
  *nivo = (BYTE) cpt_e;
  if ( cpt_e > 0 )	/* COPIER LE CHEMIN */
    {
	for ( i=0 , j=0 ; i < cpt_e ; i++)
	    {
	      chemin[j++] = me[i].me_ma;
	      chemin[j++] = (me[i].me_oa)+1;
	}/*for*/
	chemin[j++] = md_no = me[i-1].me_mc;
	mc = &(md[md_no]);
	chemin[j] = mc->m_nopp;			/* derniere option selectionnee */
   }/*if*/

   return(OK);


}





/***********************************************
* fonctions de menus
*
* Fonctions MD_CREAT creation d'un menu
*
************************************************/

/* version prologue */
#ifdef PRL

TYPF md_creat(md_no,md_de)
BYTE	md_no;
md_desc_ptr md_de;

{

	int md_er,i;	/* code erreur */
	WORD cont;
	BPTR help;

	md_de->md_plig = Invint(md_de->md_plig);
	md_de->md_pcol = Invint(md_de->md_pcol);

	/* on regarde si il y a encore des arguments */

	help = NULL;
	cont = 0 ;

	if(rt_arg.c > 4) {
		return(RT_err_arg);
		}
	if(rt_arg.c > 2){
		if(rt_arg.t[2] == TYPE_POURCENT)
	     		cont = GetAbalWord( rt_arg.v[2] );
		else if(rt_arg.t[2] == TYPE_DEUXPOINT)
     			cont = GetAbalLong( rt_arg.v[2] );
		else	return(RT_err_typ);
    		}
	if(rt_arg.c > 3) {
     		if(rt_arg.t[3] != TYPE_CHAINE)
       			return(RT_err_typ);
     		if((help = f_allouer((rt_arg.l[3] + 1))) == NULL)
       			return(werr_mem);
     		for(i = 0; i < rt_arg.l[3]; i++)
       			help[i] = ((BPTR)rt_arg.v[3])[i];
     		help[i] = 0;
    		}
  	md_er = md_creatc(md_no, md_de, cont, help);

  	if(help != NULL)
    		f_libere(help);

  	md_de->md_plig = Invint(md_de->md_plig);
  	md_de->md_pcol = Invint(md_de->md_pcol);

  	return(md_er);

}

#else

/* version unix */

TYPF md_creat(md_no,MD_de)
BYTE	md_no;
BPTR	MD_de;

{

	md_desc md_de;		/* descripteur interne menu */


	  /* variables internes */
	int md_er;			/* code erreur */
	WORD i;
	WORD cont;
	BPTR help;


  	/* transfert dans le descripteur interne */

  	md_de.md_stlf = MD_de[MD_stlf];
  	md_de.md_plig = GetAbalWord(&MD_de[MD_plig]);
  	md_de.md_pcol = GetAbalWord(&MD_de[MD_pcol]);
  
	for (i = 0; i < 32; ++i)
    		md_de.md_titr[i] = MD_de[MD_titr+i];
 
	md_de.md_typm = MD_de[MD_typm];
  	md_de.md_esc  = MD_de[MD_esc];
  	md_de.md_nbel = MD_de[MD_nbel];
  	md_de.md_lel  = MD_de[MD_lel];
  	md_de.md_laff = MD_de[MD_laff];
  	md_de.md_lcom = MD_de[MD_lcom];


  	help = NULL;
  	cont = 0;
 
	if(rt_arg.c > 4) {
  		return(RT_err_arg);
  	  	}

  	if(rt_arg.c > 2) {
     		if (rt_arg.t[2] == TYPE_POURCENT)
  	   		cont =  GetAbalWord( rt_arg.v[2] );
     		else if (rt_arg.t[2] == TYPE_DEUXPOINT)
     			cont =  GetAbalLong( rt_arg.v[2] );
     		else	return(RT_err_typ);
    		}
  	if(rt_arg.c > 3) {
		if(rt_arg.t[3] != TYPE_CHAINE)
       			return(RT_err_typ);
     		if((help = f_allouer((rt_arg.l[3] + 1))) == NULL)
       			return(werr_mem);
     		for(i = 0; i < rt_arg.l[3] ; i++)
       			help[i] = ((BPTR)rt_arg.v[3])[i];
     		help[i] = 0;
    		}
  	md_er = md_creatc(md_no,(md_desc_ptr) &(md_de.md_stlf), cont, help);

  	if(help != NULL)
    		f_libere(help);

  	return(md_er);

}

#endif




/**********************************
* appel C standard                *
***********************************/

TYPF md_creatc(md_no, md_de, cont, help)
BYTE md_no;
md_desc_ptr md_de;
WORD cont;
BPTR help;

{

  extern md_tab	md[MAXMEN];
  extern stf_desc stf[MAXSTF+1];
  extern stc_desc stc[MAXSTC];
  extern WDESC_APP_F fen;

  /* variables internes */

  md_tab *mc;			/* menu cree */
  stf_desc *syf;			/* style fenetre */
  int md_er;			/* code erreur */
  int i,j,k,o;
  mo_tab_ptr mo_ptr;		/* pointeur dans buffer options */
  WORD mo_size;			/* taille a reserver pour une option */
  char *ptr_titr;
  char *ptr_titr1;
  WDESC_APP_PTR pfm;
  BYTE style;
  /************************************
  * verification des parametres       *
  *************************************/

  	/* verification init */
  	if(fen_ini != 2)
    		return(werr_ini);

  	/* verification no de menu */
	
  	if((md_no == 0) || (md_no >= MAXMEN)) {
  	  	return(werr_desc);
  	  	}
  	mc = &md[md_no];
  
  	if (mc->m_nofen != 0)
    		return(werr_exist);

  	/* verification autres parametres */
	
	  if((md_de->md_typm == 0) || (md_de->md_typm > 3))
	  	return(werr_desc);
		
	  if((md_de->md_esc  == 0) || (md_de->md_esc > 5))
	  	return(werr_desc);
		
	  if((md_de->md_pcol  == 0) || (md_de->md_pcol >= (MAXCOL - 2))) {
	  	return(werr_desc);
		}		
	  if((md_de->md_plig  == 0) || (md_de->md_plig > (MAXLIG - 1))) {
	  	return(werr_desc);
		}

	  if((md_de->md_nbel == 0) || (md_de->md_nbel > MAXOPM)) {
	  	return(werr_desc);
		}
		
	  if((md_de->md_lel  == 0) || (md_de->md_lel > 9999)) {
	  	return(werr_desc);
		}
	  if(md_de->md_laff == 0) {
	  	return(werr_desc);
		}

	  if((md_de->md_typm != 3)&&(md_de->md_laff >  md_de->md_lel) ) {
	  	return(werr_desc);
		}

	  if((md_de->md_laff > MAXCOL - 1) || (md_de->md_lcom > (MAXCOL - 1))) {
	  	return(werr_desc);
		}

  /*****************************************************
  * pas d'erreur decelee : tentative creation fenetre *
  ******************************************************/

  pfm = (WDESC_APP_PTR)&fen;
  pfm->Amere_nbr = 0;
  pfm->Apos_lig = md_de->md_plig;
  pfm->Apos_col = md_de->md_pcol;

  /* calcul du format de la fenetre */

  if((md_de->md_typm & 1) == 1 )
    {
     pfm->Anb_lig = 1;
     pfm->Anb_col = md_de->md_laff;	/* typm = 3 horiz compresse */
     if (md_de->md_typm == 1) {
	 pfm->Anb_col = md_de->md_laff;
	 ++pfm->Anb_col;
	 pfm->Anb_col = pfm->Anb_col * md_de->md_nbel; /*prov*/
     }
  }
  else	{
  	pfm->Anb_lig = md_de->md_nbel;
  	pfm->Anb_col = md_de->md_laff;++pfm->Anb_col;
  	}
  /* style de fenetre */

	style = md_de->md_stlf;
	if ( (style == 0) || (style > STYLMAX) ) {
		return(werr_desc);
		}

	if ( (style > 15) && (style < 20) ) {
		return(werr_desc);
		}

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
	     if ( tb_style[style] == 0 ) {
		return(werr_inex);
		}
	     o = stf[style].f_ombre;
	}

	syf = &(stf[style]);


/***************************************
  i = md_de->md_stlf;
  if(i & SFOMB)
    {
     i -= SFOMB;
     o = TRUE;
    }
  else
    o = FALSE;
  --i;
  syf = &(stf[i]);
************************************/


  pfm->Aatb_vid = syf->f_fond.atbc;	/* attributs fond */
  pfm->Aatbcol_text = syf->f_fond.colc;
  pfm->Aatbcol_fond = syf->f_fond.colf;

  pfm->Acad_atb = syf->f_cad.atbc;		/* attributs cadre */
  pfm->Acad_text = syf->f_cad.colc;
  pfm->Acad_fond = syf->f_cad.colf;

  if(syf->f_nostc > 0)
    {
     pfm->Acontrol = 33;			/* invisible cadre */
     k = syf->f_nostc;
     --k;
     for (j=0;j<8;++j) pfm->Acad_usr[j] = stc[k].trait[j];
    }
  else
    pfm->Acontrol = 1;
    if(o)
      pfm->Acontrol += OMBRE;

  /**************    llb 12.02.1992  titre
  i = 1;			   -----
  pfm->Aln_tit = 0;


  for(j = TAIL_TITRE; j > 0;)
    {
     --j;
     if((md_de->md_titr[j] != ' ') && (i))
       {
	pfm->Aln_tit = j+1;
	i = 0;
       }
     pfm->Atitre[j] = md_de->md_titr[j];
    }

  *****************/


  /* recherche EOS (C) */
  j = 0;
  while((md_de->md_titr[j] != EOS) && ( j < TAIL_TITRE))
    pfm->Atitre[j] = md_de->md_titr[j++];

  /* tronquer les blancs fin du message */
  if(j > 0)
    {
     j--;
     while((pfm->Atitre[j]== ' ')&&(j>=0))
       j--;
       j++;
    }
  pfm->Aln_tit = j;
  if ( j < TAIL_TITRE)
	  pfm->Atitre[j] = NULL;



  /* creation fenetre */

  if(mc->m_nofen != 0)
    return(werr_exist);
  md_er = wcreatc((WPTR)&(mc->m_nofen),(WDESC_APP_PTR) pfm);

  if(md_er)
    return(md_er);

  /************************************************
  *    transfert des parametres du menu en table  *
  *************************************************/

  mc->m_typm = md_de->md_typm;
  mc->m_esc  = md_de->md_esc;
  mc->m_nbel = md_de->md_nbel;
  mc->m_lel  = md_de->md_lel;
  mc->m_laff = md_de->md_laff;
  mc->m_lcom = md_de->md_lcom;
  mc->m_inda = 0;				/* non affiche  */
  mc->m_indm = 0;				/* non modifie  */
  mc->m_nopp = 99;				/* pas de choix */

  mc->control = cont;
  if(help != (BPTR)NULL)
    wmemcpy((BPTR)mc->men_cle , help , 8);
  else
    mc->men_cle[0] = NULL;

  /* sauvegarde des attributs fenetre */

  mc->m_at.atbc = pfm->Aatb_vid; 		/* attributs fond */
  mc->m_at.colc = pfm->Aatbcol_text;
  mc->m_at.colf = pfm->Aatbcol_fond;

  /* separation verticale de la fenetre */


  /************************************************
  *    initialisation de la table des options     *
  *************************************************/

  /* allocation memoire */

  mo_size = (sizeof(mo_tab) + mc->m_lel +mc-> m_lcom)*(mc->m_nbel);
  mo_ptr  = (mo_tab_ptr) f_allouer (mo_size);

  if(mo_ptr == (mo_tab_ptr) NULL)
    {
     mc->m_nofen = 0;
     return (werr_mem);
    }

  mc->m_ptro = mo_ptr;

  /* init a zero du type d'element */

  for(i = 0; i < mc->m_nbel; ++i)
    {
     mo_ptr->mo_type = 0;
     mo_ptr += 1;
    }

  /* init de la fenetre de status */

  mc->m_nofenc = 0;

  if(mc->m_lcom)
    lscreatc((WPTR) &(mc->m_nofenc));

  return(0);

}

/***********************************************
* fonctions de menus
*       Fonction MO_MODIF modification d'une option
*
************************************************/
TYPF    mo_modif(md_no,mo_no,mo_typ,mo_de,mo_val,mo_com)
	BYTE md_no;
	BYTE mo_no;
	BYTE mo_typ;
	mo_desc_ptr mo_de;
	BPTR mo_val;
	BPTR mo_com;
{
/* variables externes */
extern	md_tab	md[MAXMEN];
extern  cof_tab  co;

/* fonctions appelees */
TYPF	mo_aff ();

/* variables internes */

int	md_er;			/* code erreur */
int	i,j,k;
md_tab * mc;			/* menu choisi */
BPTR mo_pt;
mo_tab_ptr mo_ptr;		/* pointeur sur le descripteur option */
mo_tab_ptr mo_ptrtm;		/* pointeur sur le descripteur option */
BPTR mo_valptr;			/* pointeur sur la valeur */
BPTR mo_comptr;			/* pointeur sur le commentaire */
BYTE	nopt;			/* numero option */
WORD	ilig,icol;		/* position ligne/colonne */
WORD	f;			/* fenetre en cours */
WORD	lel,nbel,lcom,laff;	/* valeurs en cours */
BYTE	c;

/************************************
* verification des parametres       *
*************************************/

/* verification init */
	if (fen_ini != 2) return(werr_ini);

/* verification no de menu */

	if ((md_no == 0) || (md_no >= MAXMEN)) return(werr_desc);
	mc = &(md[md_no]);
	if (mc->m_nofen == 0) return(sferr_inex);
	f = mc->m_nofen;
/* verification du type */

		
	if (mo_typ > 2) {
		return(werr_desc);
		}

/* verification numero d'option */

	if ((mo_no == 0) || (mo_no > mc->m_nbel)) {
		return(werr_desc);
		}
	nopt = mo_no - 1;

/* verification attributs */
	if (mo_typ == 2)
	{
		if (mo_de->mod_eff > 4)  {
			return(werr_desc);
			}
		if ((mo_de->mod_ataff == 0) || (mo_de->mod_ataff > 2)) {
			return(werr_desc);
			}
		if ((mo_de->mod_atsel == 0) || (mo_de->mod_atsel > 3)) {
			return(werr_desc);
			}
		if ((mo_de->mod_atetat == 0) || (mo_de->mod_atetat > 3)) {
			return(werr_desc);
			}
	};

/*****************************************************
*  pas d'erreur decelee : Rangement des parametres   *
******************************************************/

	mo_ptr = mc->m_ptro;			  /* pointeur option */
	mo_ptr += nopt;

	nbel = mc->m_nbel;
	lel = mc->m_lel;
	if ( mc->m_typm == 3)
	    laff = lel;
	else
	    laff = mc->m_laff;
	lcom = mc->m_lcom;

	mo_valptr =(BPTR) mc->m_ptro;
	mo_valptr += sizeof(mo_tab)*nbel;
	mo_valptr += lel * nopt;

	mo_ptr->mo_type = mo_typ;			/* option */
	mo_ptr->mo_indm = 1;			/* modifiee */

switch (mo_typ)
{
case 2:
	mo_ptr->mo_atetat = mo_de->mod_atetat;  /* attributs passes */
	mo_ptr->mo_ataff = mo_de->mod_ataff;
	mo_ptr->mo_atsel = mo_de->mod_atsel;
	mo_ptr->mo_eff = mo_de->mod_eff;
	c = mo_de->mod_carcle;
	mo_ptr->mo_carcle = Maj(c);
	mo_ptr->mo_menc = mo_de->mod_menc;
	mo_ptr->mo_optc = mo_de->mod_optc;

/* Caractere cle defini entre Tilde */
	for (i = 0; i < laff-2; i++)
		if ((mo_val[i] == '~')&&(mo_val[i+2] == '~')) {
		    mo_ptr->mo_carcle = mo_val[i+1];
		    mo_val[i] = mo_val[i+1];
		    i++;
		    while ( i < laff-2) {
			mo_val[i] = mo_val[i+2];
			i++;
		    }
		    mo_val[i++] = ' ';
		    mo_val[i] = ' ';
		}

/* centrage de l'option en mode horizontal */
	i = 0;
	if ((mc->m_typm & 1) ==1)
	  {
	    k= laff - 1;
	    while ( (mo_val[k] == ' ') && (k > 0) ) --k;
	    mo_ptr->mo_lng = k+1;
	    if (mc->m_typm == 1) {
		k = (laff-k)/2;

		if (k > 1)  {
		    --k;
		    for (     ; i < k ; ++i) mo_valptr[i] = ' ';
		    for ( ;i <= laff - k ; ++i) mo_valptr[i] = mo_val[i-k] ;
		}
	    }
	}
	for (   ; i<lel ; ++i) mo_valptr[i] = mo_val[i];

/* trt horizontal compresse */

	if ( mc->m_typm == 3)
	    if (nopt == 0)
		mo_ptr->mo_col = 1;
	    else {
		mo_ptrtm = mc->m_ptro;		  /* pointeur option precedente*/
		mo_ptrtm += (nopt-1);
		mo_ptr->mo_col = mo_ptrtm->mo_col + mo_ptrtm->mo_lng + 2;
	    }

/*****************************************************
* sauvegarde du commentaire                          *
******************************************************/
	if (lcom > 0)
	  {
		mo_comptr =(BPTR) mc->m_ptro;
		mo_comptr += (sizeof(mo_tab))*nbel;
		mo_comptr += lel*nbel;
		mo_comptr += lcom * nopt;
		for (i = 0; i < lcom; ++i) mo_comptr[i] = mo_com[i];
	  };

	break;


case 0:
	for (i = 0; i < lel ; ++i) mo_valptr[i] = ' ';
	break;

case 1:

	for (i = 0; i < lel ; ++i) mo_valptr[i] = co.o_seph;
	break;
};
if (mo_typ != 2)
	  {
		mo_ptr->mo_atetat = 2;  /* attributs passes */
		mo_ptr->mo_ataff = 1;
		mo_ptr->mo_atsel = 2;
		mo_ptr->mo_eff = 0;
		mo_ptr->mo_carcle = ' ';
		mo_ptr->mo_menc = 0;
		mo_ptr->mo_optc = 0;
	  };

/*****************************************************
* mise a jour de la fenetre                          *
******************************************************/

/* calcul position ligne / colonne */


	if (mc->m_typm == 3) {
	    ilig = 1;
	    icol = mo_ptr->mo_col;
	    laff = mo_ptr->mo_lng;
	}
	else
	if (mc->m_typm == 1)  {
	    k = laff;
	    ilig = 1;
	    icol = (k+1) * nopt;
	    ++icol ;
	}
	else  {
	    icol = 1;
	    ilig = nopt + 1;
	}
	wposcur(f,ilig,icol);
	c = ' ';
	md_er = wwrite(f,1,(BPTR) &c);
	md_er = wwrite(f,laff,(BPTR) mo_valptr);

/* affichage de l'option */

	md_er = mo_aff(f,md_no,nopt);

/* annulation de l'option en memoire et sauvegarde si erreur */
	if (md_er)
	   {
		mo_ptr->mo_type = 0;
	   };
	ver_me(md_no);		/* verification pile non touchee */

	return(md_er);
}

/***********************************************
* fonctions de menus
*    	Fonctions MO_CREAT creation d'une option
*
************************************************/
TYPF	mo_creat(md_no,mo_no,mo_de,mo_val,mo_com)
	BYTE md_no;
	BYTE mo_no;
	mo_desc_ptr mo_de;
	BPTR mo_val;
	BPTR mo_com;
{

extern	md_tab	md[MAXMEN];

/* variables internes */

int	md_er;			/* code erreur */
md_tab * mc;			/* menu choisi */
mo_tab_ptr mo_ptr;		/* pointeur sur le descripteur option */
BYTE	nopt;			/* numero option */

/************************************
* verification des parametres       *
*************************************/

/* verification init */
	if (fen_ini != 2) return(werr_ini);

/* verification no de menu */
	if ((md_no == 0) || (md_no >= MAXMEN)) return(werr_desc);
	mc = &(md[md_no]);
	if (mc->m_nofen == 0) return(sferr_inex);

/* verification numero d'option */

	if ((mo_no == 0) || (mo_no > mc->m_nbel))  {
		return(werr_desc);
		}
	nopt = mo_no - 1;

	mo_ptr = mc->m_ptro;			  /* pointeur option */
	mo_ptr += nopt;
	if (mo_ptr->mo_type != 0) return(sfenr_exist);
	md_er = mo_modif(md_no,mo_no,2,mo_de,mo_val,mo_com);
	return(md_er);
}


/***********************************************
* fonctions de menus
*    	Fonctions MO_AFF affichage d'une option
*       (fonction interne)
************************************************/

TYPF	mo_aff (f,nomen,nopt)
	WORD      f;			/* fenetre en cours */
	BYTE nomen;			/* menu choisi */
	BYTE nopt;			/* option a afficher */
{
/* variables externes */
extern	cof_tab co;
extern  BYTE nomena;
extern	md_tab	md[MAXMEN];
extern BYTE bv_m;

/* variables internes */
int	md_er;			/* code erreur */
int	i,j,k;
mo_tab_ptr mo_ptr;		/* pointeur sur le descripteur option */
BPTR	mo_valptr;		/* pointeur sur la valeur */
BPTR	mo_comptr;		/* pointeur sur commentaire */
md_tab * mc;			/* pointeur sur table menu */
WORD	ilig,icol;		/* position ligne/colonne */
BYTE	pos_carcle;		/* position caractere cle */
BYTE	atbvid,coltxt,colfond;
BYTE	mes;
BYTE	lcom;
BYTE 	lib_lng;

	/*mouse_off();*/


	mc = &(md[nomen]);

	/* calcul pointeur sur valeur */
	/* -------------------------- */
	mo_ptr =  mc->m_ptro;
	mo_ptr += nopt; 	/* pointeur option */
	mo_valptr = (BPTR) mc->m_ptro;
	mo_valptr += sizeof(mo_tab)*mc->m_nbel;
	mo_valptr += mc->m_lel * nopt;

	/* couleur de fond fenetre */
	/* ----------------------- */
	colfond = mc->m_at.colf;
	coltxt  = mc->m_at.colc;
	atbvid  = mc->m_at.atbc;

	/* calcul position ligne / colonne */
	/* ------------------------------- */
	lib_lng = mc->m_laff;
	if (mc->m_typm == 3) {
		lib_lng = mo_ptr->mo_lng+1;
		icol = mo_ptr->mo_col;
		ilig = 1;
		}
	else if (mc->m_typm == 1) {
		k = mc->m_laff;
		ilig = 1;
		icol = (k+1) * nopt;
		++icol ;
	   	}
	else	{
		icol = 1;
		ilig = nopt + 1;
	    	};

	md_er = wposcur(f,ilig,icol);

	/* envoi du caractere chainage */
	/* --------------------------- */
	if ((mc->m_typm == 2) && (mo_ptr->mo_menc != 0)) {
		md_er = watb(f,co.o_chain.catbc,co.o_chain.ccolc,colfond);
		md_er = wwrite(f,1,(BPTR) &(co.o_chain.car));
	   	}
	else	{
		/* envoi du caractere select */
		/* ------------------------- */
		if (mo_ptr->mo_atetat == 1) {
			md_er = watb(f,co.o_actif.catbc,co.o_actif.ccolc,colfond);
			md_er = wwrite(f,1,(BPTR) &(co.o_actif.car));
		   	}
		else	{
			if (mo_ptr->mo_type != 2)
				md_er = watb(f,co.o_grise.atbc,co.o_grise.colc,colfond);
			if ((mc->m_typm == 2) && (mo_ptr->mo_type == 1))
				mes = co.o_seph;
			else	mes = ' ';
			md_er = wwrite(f,1,(BPTR)&mes);
			};
		};

	/* envoi de la valueur de l'option */
	/* ------------------------------- */
	++icol;

	/* option positionnee */
	/* ------------------ */
	if (mc->m_nopp == nopt+1) {

		/* affichage du commentaire */
		/* ------------------------ */
		if (nomen == nomena) {
			if (mo_ptr->mo_ataff == 1) {
				/* normal */
				md_er = wsetatb(f,co.o_selec.atbc,co.o_selec.colc,co.o_selec.colf,ilig,icol-1,1,lib_lng+1);
				}
			else    {
				/* grise */
				md_er = wsetatb(f,co.o_grise.atbc,co.o_grise.colc,co.o_selec.colf,ilig,icol-1,1,lib_lng+1);
				}
		 	if (mc->m_lcom != 0) {
				mo_comptr =(BPTR) mc->m_ptro;
				mo_comptr += (sizeof(mo_tab)+ mc->m_lel) * (mc->m_nbel);
				mo_comptr += ((mc->m_lcom) * nopt);
				lcom = mc->m_lcom;
				lsmessc((WORD) mc->m_nofenc,lcom,(BPTR) mo_comptr);
				};
			}

		else	{
			if (nomen != bv_m)		/*! remis le 1611 */
				md_er = wsetatb(f,co.o_actif.catbc,co.o_actif.ccolc,colfond,ilig,icol-1,1,lib_lng+1);
			};
	   	}
	else	{
		/* option non positionnee */
		/* ---------------------- */
		if ((mo_ptr->mo_ataff == 2) || (mo_ptr->mo_type == 1)) {
			atbvid = co.o_grise.atbc;
			coltxt = co.o_grise.colc;
			}
		else	{
			atbvid = mc->m_at.atbc;
			coltxt = mc->m_at.colc;
			};

		if (mo_ptr->mo_atsel == 1) {

			/* posit caractere de selection */
			/* ---------------------------- */
			pos_carcle = 0;
			for (i=0 ; ((pos_carcle == 0) && (i < lib_lng)); ++i) {
				if (mo_valptr[i] == mo_ptr->mo_carcle) 
					pos_carcle = i+1;
				};

			/* affichage debut */
			/* --------------- */
			if (pos_carcle > 1) {
				md_er = wsetatb(f,atbvid,coltxt,colfond,ilig,icol,1,pos_carcle-1);
				icol += pos_carcle -1;
				};

			/* affichage caractere de selection */
			/* -------------------------------- */
			if (pos_carcle > 0) {
				md_er = wsetatb(f,co.o_carcle.atbc,co.o_carcle.colc,colfond,ilig,icol,1,1);
				++icol;
				};

			/* affichage fin */
			/* ------------- */
			if (pos_carcle < lib_lng) {
			   	md_er = wsetatb(f,atbvid,coltxt,colfond,ilig,icol,1,lib_lng - pos_carcle);
			  	};
		    	}
		else	{
			/* non selectionnable */
			md_er = wsetatb(f,atbvid,coltxt,colfond,ilig,icol,1,lib_lng);
			}
	   	};

	/*mouse_on();*/

	return(md_er);
}

/***********************************************
* fonctions de menus
*    	Fonctions MO_CLEAR suppression d'un element
*
************************************************/
TYPF	mo_clear(md_no,mo_no)
	BYTE md_no;
	BYTE mo_no;
{
	int md_er;

	md_er =mo_modif(md_no,mo_no,0, (mo_desc_ptr) NULL, (BPTR) NULL, (BPTR) NULL);
	return(md_er);
}

/***********************************************
* fonctions de menus
*    	Fonctions MO_SEP creation d'un separateur
*
************************************************/
TYPF	mo_sep(md_no,mo_no)
	BYTE md_no;
	BYTE mo_no;
{

extern	md_tab	md[MAXMEN];

/* variables internes */

int	md_er;			/* code erreur */
md_tab  * mc;			/* menu choisi */
mo_tab_ptr mo_ptr;		/* pointeur sur le descripteur option */
BYTE	nopt;			/* numero option */

/************************************
* verification des parametres       *
*************************************/

/* verification init */
	if (fen_ini != 2) return(werr_ini);

/* verification no de menu */

	if ((md_no == 0) || (md_no >= MAXMEN)) return(werr_desc);
	mc = &(md[md_no]);
	if (mc->m_nofen == 0) return(sferr_inex);
	if (mc->m_typm != 2) return(werr_desc);	    /* uniquement verticaux */

/* verification numero d'option */

	if ((mo_no == 0) || (mo_no > mc->m_nbel)) return(werr_desc);
	nopt = mo_no - 1;

	mo_ptr = (mc->m_ptro)+nopt;

	if (mo_ptr->mo_type != 0) return(sfenr_exist);

	md_er = mo_modif(md_no,mo_no,1, (mo_desc_ptr) NULL, (BPTR) NULL, (BPTR) NULL);

	return(md_er);
 }


/***********************************************
* fonctions de menus
*    	Fonctions MD_AFF affichage d'un menu
*
************************************************/

/* fonction interne */
TYPF	md_affc(md_no,mo_no,typaf)
	BYTE md_no;
	BYTE mo_no;
	BYTE typaf;
{
/* variables externes */
extern	md_tab	md[MAXMEN];
extern	me_tab	me[MAXENCH];
extern	WORD cpt_e;
extern	WORD ind_e;
extern	BYTE nomena;

/* fonctions appelees */
TYPF	mo_aff ();

/* variables internes */

int	md_er;			/* code erreur */
int	i,j,k;
md_tab * mc;			/* menu choisi */
mo_tab_ptr mo_ptr;		/* pointeur sur le descripteur option */
BPTR	mo_valptr;		/* pointeur sur la valeur */
int	mo_size;		/* taille a reserver pour une option */
BYTE	nopt;			/* numero option */
WORD	ilig,icol;		/* position ligne/colonne */
WORD	f;			/* fenetre en cours */
BYTE	atb_ec;			/* attribut en cours */
BYTE	pos_carcle;		/* position caractere cle */
BPTR	mo_comptr;		/* pointeur commentaire */

/************************************
* verification des parametres       *
*************************************/


	/* verification no de menu */
	/* ----------------------- */
	if ((md_no == 0) || (md_no >= MAXMEN)) 
		return(werr_desc);
	mc = &(md[md_no]);
	if (mc->m_nofen == 0) 
		return(sferr_inex);
	f = mc->m_nofen;

	/* verification numero d'option */
	/* ---------------------------- */
	if (mo_no > mc->m_nbel)
		return(werr_desc);

	if (mo_no != 0) {
		nopt = (mo_no) ? mo_no-1:mc->m_nopp;
		mo_ptr = (mc->m_ptro) + nopt;
		if (mo_ptr->mo_type != 2)
			return(werr_desc);
		}

	/* modif position barre selection */
	/* ------------------------------ */
	md_er = 0;
	j = mc->m_nopp;

	mc->m_nopp = mo_no;

	if (j <= mc->m_nbel) {
	      	if (j)	md_er = mo_aff(f,md_no,j-1);
	      	else	md_er = mo_aff(f,md_no,mc->m_nbel - 1);
		}

	if (mo_no != 0)
	   	md_er = mo_aff(f,md_no,nopt);

	if (md_er)
	     return(md_er);


	/* affichage eventuel de la fenetre */
	/* -------------------------------- */
	/*mouse_off();*/

	if (nomena == md_no) {
		/*  modif du 26/07 	*/
		wselect(f);
		wselect(mc->m_nofenc);
		}
	if (mc->m_inda == 0) {
		md_er = wvis(f);
		mc->m_inda = 1;
	  	}

	if (md_er)
		return(md_er);

	if((typaf == 1) && (mo_ptr->mo_menc != 0)) {
		add_me(md_no,nopt,mo_ptr->mo_menc);
		ind_e = cpt_e;
		}

	/*mouse_on();*/

	/* affichage OK, on rend le menu mouse_sensitive */
	/* --------------------------------------------- */
	put_item_mouse_list(mc->m_nofen);

	return(OK);

}

/* fonction externe */

TYPF	md_aff(md_no,mo_no,typaf)
	BYTE md_no;
	BYTE mo_no;
	BYTE typaf;
{
	/* variables internes */
	WORD md_er;

	/* verification init */
	/* ----------------- */
	if (fen_ini != 2) return(werr_ini);

	md_er = md_affc(md_no,mo_no,typaf);

	if (typaf == 0) ver_me(md_no);		/* supprimer pile si affichage dedans */

	return(md_er);
}


/***********************************************
* fonctions de menus
*    	Fonctions MO_LATT lecture des attributs
*
************************************************/
TYPF	mo_latt(md_no,mo_no,moataff,moatsel,moatetat)
	BYTE md_no;
	BYTE mo_no;
	BPTR moataff;
	BPTR moatsel;
	BPTR moatetat;
{
extern	md_tab	md[MAXMEN];

/* variables internes */

int	md_er;			/* code erreur */
int	i,j,k;
md_tab * mc;			/* menu choisi */
mo_tab_ptr mo_ptr;		/* pointeur sur le descripteur option */
BYTE	nopt;			/* numero option */
BPTR	mo_valptr;		/* ptr sur valeur de l'option */

/************************************
* verification des parametres       *
*************************************/

/* verification init */
	if (fen_ini != 2) return(werr_ini);

/* verification no de menu */

	if ((md_no == 0) || (md_no >= MAXMEN)) return(werr_desc);
	mc = &(md[md_no]);
	if (mc->m_nofen == 0) return(sferr_inex);

/* verification numero d'option */

	if ((mo_no == 0) || (mo_no > mc->m_nbel)) return(werr_desc);
	nopt = mo_no - 1;

	mo_ptr = (mc->m_ptro) + nopt;

	if (mo_ptr->mo_type != 2) return(sfenr_inex);

/* transfert des attributs */

	*moataff = mo_ptr->mo_ataff;

	*moatsel = mo_ptr->mo_atsel;

	*moatetat = mo_ptr->mo_atetat;;

	if (rt_arg.c > 6)
		return(RT_err_arg);	/* trop d'arguments */
	if (rt_arg.c == 6 )     {
	      if(rt_arg.t[5] != TYPE_CHAINE)
			return(RT_err_typ);

		/* calcul adresse valeur de l'option */
		mo_valptr = (BPTR) mc->m_ptro ;
		mo_valptr += sizeof(mo_tab) * mc->m_nbel ;
		mo_valptr += mc->m_lel * nopt ;

		wmemcpy( rt_arg.v[5] , mo_valptr, mc->m_lel );
	}/*retourner valeur option */

	return(OK);
}



/***********************************************
* fonctions de menus
*    	Fonctions MO_MATT modification attributs
*
************************************************/
TYPF	mo_matt(md_no,mo_no,moataff,moatsel,moatetat)
	BYTE md_no;
	BYTE mo_no;
	BYTE moataff;
	BYTE moatsel;
	BYTE moatetat;
{
extern	md_tab	md[MAXMEN];
/* fonctions appelees */
TYPF	mo_aff ();

/* variables internes */

int	md_er;			/* code erreur */
int	i,j,k;
md_tab * mc;			/* menu choisi */
mo_tab_ptr mo_ptr;		/* pointeur sur le descripteur option */
BYTE	nopt;			/* numero option */
WORD	f;			/* numero fenetre */

/************************************
* verification des parametres       *
*************************************/

/* verification init */
	if (fen_ini != 2) return(werr_ini);

/* verification no de menu */

	if ((md_no == 0) || (md_no >= MAXMEN)) return(werr_desc);
	mc = &(md[md_no]);
	if (mc->m_nofen == 0) return(sferr_inex);
	f = mc->m_nofen;

/* verification numero d'option */

	if ((mo_no == 0) || (mo_no > mc->m_nbel)) return(werr_desc);
	nopt = mo_no ;

	mo_ptr = (mc->m_ptro) + nopt-1;

	if (mo_ptr->mo_type != 2) return(werr_desc);

/* verification des attributs */

	if (moatsel > 3) return(werr_desc);
	if (moataff > 2) return(werr_desc);
	if (moatetat > 2) return(werr_desc);


/* transfert des attributs */

	if (moataff)
	  {
		if (moataff != mo_ptr->mo_ataff)
		   {
			mo_ptr->mo_ataff = moataff;
			mo_ptr->mo_indm = 1;
		   };
	  };

	if (moatetat)
	  {
		if (moatetat != mo_ptr->mo_atetat)
		   {
			mo_ptr->mo_atetat = moatetat;
			mo_ptr->mo_indm = 1;
		   };
	  };

	if (moatsel)
	  {
		if (moatsel != mo_ptr->mo_atsel)
		   {
			if (moatsel == 3)
			   {
				if ((mc->m_inda == 1) && (mc->m_nopp == nopt)) return (werr_desc);
			   };
			mo_ptr->mo_atsel = moatsel;
			mo_ptr->mo_indm = 1;
		   };
	};

	if (mo_ptr->mo_indm == 1)
	   {
		md_er = mo_aff(f,md_no,nopt-1);
		if (md_er) return(md_er);
	   };

	ver_me(md_no);		/* supprimer pile si modif dedans */

	return(OK);

}


/***********************************************
* fonctions de menus
*    	Fonctions MD_CLEAR effacement d'un menu
*
************************************************/

/* fonction interne aux menus */

TYPF	md_clearc(md_no)
	BYTE md_no;
{
/* variables externes */
extern	md_tab	md[MAXMEN];
extern	me_tab	me[MAXENCH];
extern	WORD cpt_e;
extern  BYTE nomena;

/* variables internes */
WORD	f;			/* fenetre en cours */
int	md_er;			/* code erreur */

    md_er = 0;

    /*mouse_off();*/

    if (md_no != 0)  {
	f = md[md_no].m_nofen;		/* fenetre menu invisible */
	if (f == 0)
		md_er = sferr_inex;
	else
		md_er = winv(f);

	if (md_er == 0)  {
		md[md_no].m_inda = 0;
		f = md[md_no].m_nofenc;	/* fenetre commentaire inv */
		if (f) winv(f);
	}
    }
    else  {
	if ( cpt_e > 0 )  {

		nomena = me[cpt_e-1].me_mc ;
		if (nomena != 0)
			md_clearc(nomena);

		while ( (cpt_e > 0) && (me[cpt_e-1].me_mc == nomena) )
		{
			--cpt_e;
			nomena = me[cpt_e].me_ma;
			md_clearc(nomena);
		}
	}
	else  {
		nomena = me[0].me_ma;
		if ( nomena != 0)
			md_clearc(nomena);
		else
			md_er = sferr_inex;
	}
	nomena = 0;

    }/*md_no = 0*/

  /* on rend le menu nom mouse_sensitive */
  del_item_mouse_list(f);

  /*mouse_on();*/

  return(md_er);

}/*md_clearc*/

/*==========================================================*/
/* appel externe */

TYPF	md_clear(md_no)
	BYTE md_no;
{
/* variables internes */
int	md_er;			/* code erreur */

/* variables externes */
extern	WORD cpt_e;		/* pointeur de chainage */
extern	WORD ind_e;		/* pointeur de chainage */

/************************************
* verification des parametres       *
*************************************/

/* verification init */
	if (fen_ini != 2) return(werr_ini);

/* verification no de menu */

	if (md_no >= MAXMEN) return(werr_desc);

	md_er = md_clearc(md_no);

	if (md_no != 0)
	  {
		ver_me(md_no);
	  }
	else
	  {
		cpt_e = 0;
		ind_e = 0;
	  };

	return(md_er);
}




/***********************************************
* fonctions de menus
*
* Fonctions MD_SUP Suppression d'un menu
*
************************************************/

TYPF md_sup(md_no)
BYTE md_no;

{
  /* variables externes */
  extern WORD cpt_e;
  extern WORD ind_e;

  extern md_tab	md[MAXMEN];

  /* variables internes */

  int md_er;			/* code erreur */
  int i,j,k;
  WORD f;			/* fenetre en cours */
  md_tab *mc;


  /************************************
  * verification des parametres       *
  *************************************/

  /* verification init */

  if(fen_ini != 2)
    return(werr_ini);

  /* verification no de menu */

  if(md_no >= MAXMEN)
    return(werr_desc);

  if(md_no == 0)
    {
     j = 0;
     k = MAXMEN-1;
     cpt_e = 0;	/* RAZ Pile */
     ind_e = 0;
    }
  else
    {
     j = md_no;
     k = md_no;
     ver_me(md_no);	/* RAZ Pile si touchee */
    }

  for(i = j; i <= k; ++i)
    {
     mc = &(md[i]);
     f = mc->m_nofen;
     if(f == 0)
       md_er = sferr_inex;
     md_er = wsup(f);
     if(md_er == 0)
       {
	if(mc->m_nofenc != 0)
	  md_er = wsup(mc->m_nofenc);  /*!1511 */
	mc->m_nofen = 0;
	mc->m_inda = 0;
	f_libere((BPTR)mc->m_ptro);
       }
    }
  if(md_no == 0)
    md_er = 0;

  return(md_er);

}





/***********************************************
* fonctions de menus (fonction interne)
*
* Fonctions MD_OPTA selection automatique
*        1 suivante
*	 2 precedente
*
************************************************/

TYPF md_opta(codf, md_no, mo_no, md_ptc, mo_ptc)
BYTE codf;
BYTE md_no;
BYTE mo_no;
BPTR md_ptc;
BPTR mo_ptc;

{

  /* variables externes */

  extern BYTE nomena;
  extern md_tab	md[MAXMEN];
  extern me_tab	me[MAXENCH];
  extern WORD cpt_e;


  /* variables internes */

  int md_er;			/* code erreur */
  int i,j,k;
  md_tab *mc;			/* menu choisi */
  mo_tab_ptr mo_ptr;		/* pointeur sur le descripteur option */
  md_tab * mce;			/* pointeur sur menu chaine */
  mo_tab_ptr mo_ptre;		/* pointeur sur options chainees */
  BYTE nomentst;		/* no menu a tester */
  BPTR mo_valptr;		/* pointeur sur la valeur */
  BYTE nopt;			/* numero option */
  BYTE pos_carcle;		/* position caractere cle */
  BYTE touche;			/* touche tapee */
  BYTE poptc;			/* premiere option correspondante */
  BYTE ntcc;			/* nombre d'options correspondantes */
  BPTR mo_comptr;		/* pointeur sur commentaire */
  BYTE mena,opta,mench,optch;	/* pour chainages */
  BYTE sav_cpte;

  /* rangement des valeurs utiles */

  mc = &(md[md_no]);
  nopt = mo_no - 1;

  /* affichage option suivante  ou precedente */

  sav_cpte = cpt_e;	/* ceci est une bidouille pour que mo_afs n'affiche pas */
  cpt_e = 1; 		/* le sous menu chaine a l'option */

  md_er = mo_afs((BPTR)&md_no,(BPTR)&nopt,mc->m_typm,codf);
  cpt_e = sav_cpte;
  if(md_er)
    return(md_er);

  /* recherche si chainage */

  mo_ptr = (mc->m_ptro) + nopt;

  /*2808 test si menu chaine existe*/
  nomentst = mo_ptr->mo_menc ;
  if(nomentst != 0)
    {
     mce = &(md[nomentst]);
     if(mce->m_nofen == 0)
       nomentst = 0;
    }

  if(nomentst != 0)
    {
     mench = nomentst;
     optch = mo_ptr->mo_optc -1;
     nomena = mench;
     mc = &(md[md_no]);
     mce = &(md[mench]);
     mo_ptr = (mc->m_ptro)+optch;
     mo_ptre = (mce->m_ptro)+optch;

     if((mo_ptre->mo_type == 2) && (mo_ptre->mo_atsel != 3))
       md_er = md_affc(mench,optch+1,0);
     else
       md_er = sfenr_inex;

/*     if((md_er == 0) && (cpt_e >= 0) && (cpt_e < MAXENCH - 1)) */
     if((md_er == 0) && (cpt_e < MAXENCH - 1))
       {
	add_me(md_no,nopt,mench);
       }
     else
       {
	mench = md_no;
	optch = nopt;
       }
    }
  else
    {
     mench = md_no;
     optch = nopt;
    }

  *md_ptc = mench;
  *mo_ptc = optch+1;
  nomena = mench;

  return(OK);

}






/***********************************************
* fonctions de menus interne
*
* Fonctions MO_AFS affichage option suivante
*
************************************************/

TYPF mo_afs(pmdno, popt, typd, sensd)

BPTR pmdno;
BPTR popt;
BYTE typd;
BYTE sensd;

{

  /* variables externes */

  extern BYTE nomena;
  extern md_tab	md[MAXMEN];
  extern me_tab	me[MAXENCH];
  extern WORD cpt_e;


  /* variables internes */

  int md_er;				/* code erreur */
  int i,j,k;
  md_tab *mc;				/* menu choisi */
  mo_tab_ptr mo_ptr;			/* pointeur sur le descripteur option */
  BYTE	optd,mena,opta,mench,optch;	/* pour chainages */
  BYTE typemenu;
  /* debut */

  /*mouse_off();*/

  mc = &(md[*pmdno]);
  typemenu = mc->m_typm;
  if (typemenu == 3)
      typemenu = 1;
  if(typemenu  == typd)		/* llb 21/07/94 */
    {
     /* recherche de l'option suivante */
     i = 0;
     optd = *popt;
     do
       {
	i = 1;
	if(sensd == 1)
	  {
	   ++(*popt);
	   if (*popt == mc->m_nbel)
	     *popt = 0;
	  }
	else
	  if(sensd == 2)
	    {
	     if(*popt == 0)
	       *popt = (mc->m_nbel);
	     --(*popt);
	    }


	mo_ptr = (mc->m_ptro) + *popt;
	if(mo_ptr->mo_type != 2)
	  i = 0;
	if (mo_ptr->mo_atsel == 3)
	  i = 0;
       }
     while((i==0) && (*popt != optd));

     /* affichage de l'option 					*/
     /* si l'option possede un sous menu, acces a celui ci 	*/
     /* llb 20.01.92 						*/

     /* mo_ptr = option trouvee 				*/

     mench = mo_ptr->mo_menc;
     if((mench != 0) && (cpt_e == 0) && (typd == 1))
       {
	nomena = mench;
	optch = mo_ptr->mo_optc;
	md_affc(*pmdno,*popt+1,0);
	add_me(*pmdno, *popt, mench);
	*pmdno = mench;
	*popt = optch - 1;
       }
     md_er = md_affc(*pmdno,(*popt)+1,0);
     if(md_er)
       return(md_er);
    }
  else /*typd*/
    {
     if(cpt_e > 0)
       {
	mench = me[cpt_e -1].me_mc;
	if(mench == *pmdno)
	  /* si menu chaine a un autre type de menu passage au menu suivant */
	  {
	   mena = me[cpt_e -1].me_ma;
	   if(md[mena].m_typm != mc->m_typm)
	     {
	      opta = me[cpt_e -1].me_oa;
	      md_clearc(*pmdno);
	      cpt_e--;
	      md_er = md_opta((BYTE)sensd,(BYTE)mena,(BYTE)(opta+1),(BPTR)&mench,(BPTR)&optch);
	      if(md_er)
		return(md_er);
	      *pmdno = mench;
	      *popt = optch - 1;
	     }
	  }
       }
    }
  nomena = *pmdno;
  /*mouse_on();*/
  return(OK);

}



/***********************************************
* fonctions de menus
*
* Fonctions MD_OPT choix d'une option
*
************************************************/


TYPF md_opt(md_no,mo_no,md_ptc,mo_ptc,val_ptc,ret)
BYTE md_no;
BYTE mo_no;
BPTR md_ptc;
BPTR mo_ptc;
BPTR val_ptc;
BPTR ret;

{

  TYPF md_optc();

  /* variables internes */

  int stx_er;			/* code erreur */
  BYTE exit;


  stx_er = md_optc(md_no, mo_no, md_ptc, mo_ptc, val_ptc, (BPTR)&exit);

  /* test si arg de sortie */
  if(rt_arg.c == 6)
   *ret = exit;

  return(stx_er);

}




/****************************************
*					*
* appel C standard              	*
*                                       *
*****************************************/

TYPF md_optc(md_no,mo_no,md_ptc,mo_ptc,val_ptc,exit)
BYTE md_no;
BYTE mo_no;
BPTR md_ptc;
BPTR mo_ptc;
BPTR val_ptc;
BPTR exit;

{
  extern md_tab	md[MAXMEN];

  extern me_tab	me[MAXENCH];
  extern WORD cpt_e;
  extern WORD ind_e;

  extern BYTE nomena;
  extern BYTE tc[MAX_TOUCHES];
  extern BYTE sa_touche;


  /* variables internes */

  int md_er;			/* code erreur					*/
  int i,j,k;
  md_tab *mc;			/* menu choisi 					*/
  md_tab *mce;			/* menu enchaine				*/
  mo_tab_ptr mo_ptr;		/* pointeur sur le descripteur option		*/
  mo_tab_ptr mo_ptre;
  mo_tab_ptr curmo_ptr;
  BYTE nomentst;		/* test option chainee    			*/
  BPTR mo_valptr;		/* pointeur sur la valeur 			*/
  BYTE nopt;			/* numero option 				*/
  BYTE pos_carcle;		/* position caractere cle 			*/
  BYTE touche;			/* touche tapee 				*/
  SWORD  val;			/* valeur correspondante 			*/
  BYTE poptc;			/* premiere option correspondante 		*/
  BYTE ntcc;			/* nombre d'options correspondantes 		*/
  BYTE mena,opta,mench,optch;	/* pour chainages 				*/
  BYTE typd;			/* depl 1 horiz, 2 vert 			*/
  BYTE sensd;			/* sens 1=croissant, 2=decroissant 		*/
  BYTE fl_esc;			/* flag de frappe de touche d'echappement 	*/
  BYTE c;
  BYTE typc;
  BYTE memo_menu, memo_opt;	/* memo menu et option pour touche d'echappement*/
  WORD f;			/* nø fenetre du menu courant			*/
  WORD nelp;			/* nø d'element pointe				*/
  WORD sens;
  SWORD w_use, h_use;		/* largeur et hauteur (utiles) du menu		*/
  SWORD mplig;			/* mouse position (ligne et colone)   		*/
  SWORD mpcol;
  SWORD region;			/* la region concernee par un event		*/
  WORD new_m, next_m;		/* menu chaine					*/
  WORD sauv_o;			/* sauvegarde option active			*/
  WDESC_PTR wd;			/* descripteur fenetre du menu			*/
  WDESC_PTR wm;
  WORD optsav;
  BYTE curop;

  /************************************
  * verification des parametres       *
  *************************************/

  /* verification init */
  if(fen_ini != 2)
    return(werr_ini);


  /* test pour recherche pile */

  if((md_no == 0) && (mo_no == 0)) /* demande repositionnement */
    {
    if(cpt_e == 0)
       {
	if (last_men == 0)
	       return(sfenr_inex);
	 else
	   md_no = last_men;
     }
     else {
	 md_no = me[cpt_e-1].me_mc;
	 if((md_no == 0) || (md_no >= MAXMEN))
	    return(sfenr_inex);
     }
     mc = &(md[md_no]);
     mo_no = mc->m_nopp;	/* derniere option selectionnee */
  }
  else
    {
     /* llb 12.11.91  Supprimer le chainage precedent */
     if((md_no == 0) || (md_no >= MAXMEN))
       return(werr_desc);
     if(ind_e == 0)
       ver_me(md_no);		/* raz pile avant travail*/

     ind_e = 0 ;
     mc = &(md[md_no]);

    }/*else*/


  if((mo_no == 0) || (mo_no > mc->m_nbel))
    return(werr_desc);
  mench = md_no;
  optch = mo_no - 1;
  mo_ptr = (mc->m_ptro) + optch;

  if(mo_ptr->mo_type != 2)
    return (sfenr_inex);

/* llb 30.09.93 */
  if(mo_ptr->mo_atsel == 3) /* non positionnable !! */
    {
     curop = 0;
     while (curop < mc->m_nbel)
      {
	mo_ptr = (mc->m_ptro) + curop;
	if ( mo_ptr->mo_atsel ==1 )
	  break;
	curop++;
     }
     if ( curop == mc->m_nbel )
	return(werr_desc);
     optch = curop;
  }
  optsav = optch;



  /* init chemin */

  /* boucle pour les appels recursifs */

  *md_ptc = 0;
  typc = 0;
  fl_esc = FALSE;
  *exit = 0;
  new_m = 0;
  next_m = 0;


  Wkup_in();


  /* deplacement dans le menu */

  while(typc == 0)
    {
     *mo_ptc = 0;
     nomena = mench;
     md_er = md_affc(mench,optch+1,0);
     if(md_er)
       {
	nomena = 0;
	Wkup_out();	
	return(md_er);
       }

     /* test si echappement precedent, si oui on propage */
     if(fl_esc == TRUE)
       val = T_ESC;
     else
       {
	touche = 0;
	val = 0;
	while((touche == 0) && (val == 0))
	  {
	   mc = &(md[mench]);

	   /* recup descripteur de la fenetre */
	   wm = (WLOG[mc->m_nofen-1])->wdesc_ptr;

	   /* taille utile du menu */
	   w_use = wm->nb_col;
	   h_use = wm->nb_lig;

	   /* mise en attente d'un evenement */
	   if(event.event == NO_EVENT)
	     wait_eventc(MENU_EVENTS, (EVENT_PTR)&event);

	   if(event.event == KEYBOARD)
	     {
	      touche = event.arg;
	      event.event = NO_EVENT;
	     }
	   else
	     {
	      /* il faut controler que l'evenement concerne le menu courant */

	      if((f = get_item_mouse_list(event.plig, event.pcol)) == 0)
		{
		/* si event ne concerne pas une fenetre mouse_sensitive	*/
		/* on l'ignore 						*/
/*llb05.10.93:
traitement du glisse:
si MOUSE_UP sur fond ecran, on se repositionne sur l'option precedente
si MOUSE_UP sur une fenetre sensible qui n'est pas le menu, on quitte
*/

		   if (event.event == MOUSE_UP)
		      {
			curmo_ptr = mc->m_ptro+optch;
			if ((curmo_ptr->mo_type != 2) || (curmo_ptr->mo_atsel != 1))
			   {
			      mc->m_nopp = optsav+1;
			      mo_aff(mc->m_nofen, mench, optch);
			      optch = optsav;
			      mo_aff(mc->m_nofen, mench, optch);
			}
			if (curmo_ptr->mo_menc != 0)
			    md_clearc(curmo_ptr->mo_menc);	/* supprimer le sous menu affiche sur mouse_down */
		   }
		  if ( Wkup_Adress != NULL)
		    {
			if (Advise_Exa(event.event)) {
				val = T_ESC;
				break;
			}
		   }
		   event.event = NO_EVENT;
		   continue;
		}

	      wd = (WLOG[f-1])->wdesc_ptr;
	      if(f != mc->m_nofen)
		{
		 /* on se situe en dehors du menu actif */
		 /* on recherche si la fenetre pointee est un menu */
		 i = -1;
		 for(i = cpt_e-1; i >= 0; i--)
		   {
		    k = ((md_tab *)&(md[(me[i].me_ma)]))->m_nofen;
		    if((WLOG[k-1])->wdesc_ptr != wd)
		      {
		       k = ((md_tab *)&(md[(me[i].me_mc)]))->m_nofen;
		       if((WLOG[k-1])->wdesc_ptr == wd)
			 break;
		      }
		    else
		      break;
		   }

		 if(i >= 0)
		   {
		    /* la fenetre pointee appartient au menu 			*/
		    /* on teste si la fenetre est un sous menu du menu actif	*/
		    /* si oui, on passe le controle a cette mouvelle fenetre	*/
		    /* si non, on genere un ESC mais on conserve l'EVENT 	*/
		    if((me[i].me_ma == mench) && (me[i].me_oa == optch))
		      {
		       cpt_e--;
		       val = T_ENVOI;
		       break;
		      }
		    else
		      {
		       /* on ferme le faux menu chaine si existant */
		       if(mench == me[cpt_e-1].me_ma)
			 {
			  cpt_e--;
			  md_clearc(me[cpt_e].me_mc);
			 }

		       val = T_ESC;
		       next_m = 0;
		       break;
		      }
		   }
		 else
		   /* l'EVENT ne concerne pas le menu	*/
		   if(((event.event&MOUSE_M_W_DOWN) == 0) && (event.event != MOUSE_IS_DOWN))
		     {
		      /* il faut verifier qu'il ne reste pas un sous menu ouvert (non actif) 	*/
		      /* si oui, on doit le fermer puis propager l'EVENT.			*/
		      if((cpt_e != 0) && (mench == me[cpt_e-1].me_ma))
			md_clearc(me[cpt_e-1].me_mc);
			val = T_ESC;
			break;
		     }
		   else
		     {
		      if (event.event == MOUSE_UP)
			{
			 curmo_ptr = mc->m_ptro+optch;
			 if ((curmo_ptr->mo_type != 2) || (curmo_ptr->mo_atsel == 3))
			   {
			    mc->m_nopp = optsav+1;
			    mo_aff(mc->m_nofen, mench, optch);
			    optch = optsav;
			    mo_aff(mc->m_nofen, mench, optch);
			   }
			}
		      event.event = NO_EVENT;
		      continue;
		     }/*else*/
		}

	      /* calcul de la region concernee par l'event */
	      mplig = event.plig - wm->pos_lig + 1;
	      mpcol = event.pcol - wm->pos_col + 1;

	      region = NO_REGION;
	      if((mpcol <= w_use) && (mplig <= h_use) && (mpcol > 0) && (mplig > 0))
		region = INSIDE_MENU;


	      /* on recherche l'element concerne par l'event */
	      if(region == INSIDE_MENU)
		 nelp = (mc->m_typm == 1) ? (mpcol-1)/(mc->m_laff+1) : mplig-1;
	      else
		{
		 if((event.event == MOUSE_UP) && (cpt_e != 0) && (mench == me[cpt_e-1].me_ma))
		   {
		    next_m = 0;
		    md_clearc(me[cpt_e-1].me_mc);
		   }

		 event.event = NO_EVENT;
		 continue;
		}

	      /* suivant l'event et la region, on interprete */

	      switch(event.event)
		{
		 case MOUSE_UP:
		   if(region == INSIDE_MENU)
		     {
		      mo_ptr = (mc->m_ptro) + nelp;
		      next_m = 0;
		      if((mo_ptr->mo_atsel == 2) || (mo_ptr->mo_atsel == 3))
			{
/*llb 06/10/93
	  val = T_ESC; 
traitement du glisse: si UP sur une option non positionnable,
on se repositionne sur l'option precedente valide
*/
			 mc->m_nopp = optsav+1;
			 mo_aff(mc->m_nofen, mench, optch);
			 optch = optsav;
			 mo_aff(mc->m_nofen, mench, optch);
			 event.event = NO_EVENT;
			 break;
			}
		      else
			{
			 optch = nelp;
			 if(mo_ptr->mo_menc != 0)
			   cpt_e--;

			 val = T_ENVOI;
			 event.event = NO_EVENT;
			}
		     }
		   break;


		 case MOUSE_M_W_DOWN+M_LEFT:
		 case MOUSE_M_W_DOWN+M_RIGHT:
		 case MOUSE_M_W_DOWN+M_UP:
		 case MOUSE_M_W_DOWN+M_DOWN:
		 case MOUSE_DOWN:
		 case MOUSE_IS_DOWN:
		   if(region == INSIDE_MENU)
		     {
		      /* On recupere l'option et test si positionnable */
		      mo_ptr = mc->m_ptro + nelp;
		      if(((mo_ptr->mo_type != 2) || (mo_ptr->mo_atsel == 3)) && (optch != nelp))
			{
			 mc->m_nopp = nelp+1;
			 mo_aff(mc->m_nofen, mench, optch);
/* llb 02/09/93
   on sauve l'option ou a lieu le 1er M_DOWN
   pour pouvoir la restituer ensuite si M_UP sur option non selectionnable
*/
			 if ((event.event == MOUSE_DOWN)&&(mo_ptr->mo_atsel==1))
				optsav = optch;
			 optch = nelp;
			 event.event = NO_EVENT;
			 break;
			}

		      /* affichage de l'option */
		      if(nelp != optch)
			{
			 mc->m_nopp = nelp+1;
			 mo_aff(mc->m_nofen, mench, optch);
			 nomena = mench;
			 mo_aff(mc->m_nofen, mench, nelp);
			 optch = nelp;
			}

		      /* test si sous menu */
/*llb30.09.93*/
		      if (((mc->m_ptro) + nelp)->mo_atsel == 1)
			  new_m = ((mc->m_ptro) + nelp)->mo_menc;

		      if(next_m != new_m)
			{
			 if((next_m != 0) && (next_m != mench))
			   {
			    md_clearc(next_m);
			    nomena = mench;
			    next_m = 0;
			   }

			 if(new_m != 0)
			   {
			    add_me(mench,optch,new_m);
			    nomena = new_m;
			    md_affc(new_m, 0, 0);
			    next_m = new_m;
			   }
			}
		     }/* if inside */

		   event.event = NO_EVENT;
		   break;


		 default:
		   event.event = NO_EVENT;
		   break;

		}/* switch(event) */

	     }

	  }/* while(TRUE) */


	/* on teste si touche d'echappement */
	if(val == 0)
	  if(((mc->control&TCH_ESC) != 0) && (sffind_tch(touche) != 0))
	    {
	     val = T_ESC;
	     fl_esc = TRUE;
	     *exit = touche;
	     memo_menu = mench;
	     memo_opt = optch+1;
	    }
	  else
	    if((touche == ' ') || (touche == '-'))
	      {
	       if(mc->m_typm == 2)
		 val = F_BAS;
	       else
		 val = F_DROITE;
	      }
	    else
	      if(touche == sa_touche)
		val = T_AIDE;
	      else
		for(i=0, val=0; (i < MAX_TOUCHES) && (val == 0); ++i)
		  if(tc[i] == touche)
		    val = i+1;

       }/* else lf_esc == TRUE */

     switch(val)
       {
	/* curseur bas */
	case F_BAS:
	  mo_afs((BPTR) &mench,(BPTR) &optch,2,1);
	  break;

	/* curseur haut */
	case F_HAUT:
	  mo_afs((BPTR) &mench,(BPTR) &optch,2,2);
	  break;

	/* curseur droit */
	case F_DROITE:
	  mo_afs((BPTR) &mench,(BPTR) &optch,1,1);
	  break;

	/* curseur gauche */
	  case F_GAUCHE:
	  mo_afs((BPTR) &mench,(BPTR) &optch,1,2);
	  break;

	/* home */
	case T_HOME:
	  mo_ptr = mc->m_ptro;
	  if((mo_ptr->mo_type != 2) || (mo_ptr->mo_atsel == 3))
	    break;
	  optch = (mc->m_nbel)-1;
	  mo_afs((BPTR) &mench,(BPTR) &optch,mc->m_typm,1);
	  break;

	/* end */
	case T_END:
	  mo_ptr = mc->m_ptro + (mc->m_nbel - 1);
	  if((mo_ptr->mo_type != 2) || (mo_ptr->mo_atsel == 3))
	    break;
	  optch = 0;
	  mo_afs((BPTR) &mench,(BPTR) &optch,mc->m_typm,2);
	  break;

	/* abandon ou echappement */
	case T_ESC:
	  if(fl_esc == FALSE)
	    *exit = ESC;
	  if(mc->m_esc < 5)
	    {
	     switch (mc->m_esc)
	       {
		case 1:
		  md_er = md_affc(mench,optch+1,0);
		  typc = 2;
		  break;

		case 2:
		  md_er = md_clearc(mench);
		  if(md_er)
		    {
			Wkup_out();	
			return(md_er);
		   }
		  if((cpt_e > 0) && (me[cpt_e -1].me_mc == mench))
		    {
		     -- cpt_e;
		     mench = me[cpt_e].me_ma;
		     optch = me[cpt_e].me_oa;
		     optsav = optch;
		     typc = 0;
		    }
		  else
		    typc = 2;
		  break;

		case 3:
		  md_er = md_clearc(0);
		  /*	       if((cpt_e > 0) && (me[cpt_e-1].me_mc == mench))
				 md_er = md_clearc(0);
				else
				  md_er = md_clearc(mench);
		  */
		  /*2808	       if(md_er) return(md_er); */
		  typc = 2;
		  break;

		case 4:
		  typc = 2;
		  while((cpt_e > 0) && (me[cpt_e-1].me_mc == mench))
		    {
		     md_clearc(mench);
		     --cpt_e;
		     mench = me[cpt_e].me_ma;
		     optch = me[cpt_e].me_oa;
		     typc = 0;
		    }
		  break;

	       } /* switch */

	     nomena = 0;
	     *md_ptc = mench;
	     *mo_ptc = 0;

	    }/* if */

	  break;

	/* touche aide */
	case T_AIDE:
	  if(mc->men_cle[0]== NULL)	/* pas de cle aide */
	    sa_aid((BPTR) NULL);	/* -> aide defaut */
	  else
	    sa_aid(mc->men_cle);
	  break;


	default:

	  /* test des caracteres-cle */
	  /* passage en majuscules */
	  touche = Maj(touche);
	  /* scrutation des caracteres-cle */
	  i = 0;
	  poptc = MAXOPM;
	  ntcc = optch;
	  do
	    {
	     ++ntcc;
	     if(ntcc == mc->m_nbel)
	       ntcc = 0;
	     mo_ptr = (mc->m_ptro) + ntcc;
	     if((mo_ptr->mo_type == 2) && (mo_ptr->mo_atsel !=3))
	       {
		/* option selectionnable */
		c = Maj(mo_ptr->mo_carcle);
		if(c == touche)
		  {
		   ++i;
		   if(poptc == MAXOPM)
		     poptc = ntcc;
		  }
	       }
	    }
	  while (ntcc != optch);
	  if(i == 0)
	    break;
	  optch = poptc;
	  md_er = md_affc(mench,optch+1,0);
	  if(md_er)
	    {
		Wkup_out();	
		return(md_er);
	  }
	  if(i>1)
	    break;

	/* envoi */
	case T_ENVOI:
	  mo_ptr = (mc->m_ptro) + optch;
	  if(mo_ptr->mo_atsel == 2)
	    break;

	  /*2808 test si menu chaine existe*/
	  nomentst = mo_ptr->mo_menc ;
	  if(nomentst != 0)
	    {
	     mce = &(md[nomentst]);
	     if(mce->m_nofen == 0)
	       nomentst = 0;
	    }

	  if(nomentst != 0)
	    {
	     nomena = nomentst;
	     md_er = md_affc(mench,optch+1,0);
	     if(md_er !=0)
	       {
		Wkup_out();	
		return(md_er);
	     }

	     add_me(mench,optch,nomena);
	     mench = nomena;
	     optch = mo_ptr->mo_optc -1;
/*3009*/
	     optsav = optch;

	     /* controle option selectionnable */
	     mo_ptre = mce->m_ptro + optch;
	     if(mo_ptre->mo_type != 2)
	       md_er = sfenr_inex;
	     else
	     if (mo_ptre->mo_atsel ==3)	/* non selectionnable */
	       {
		  curop = 0;
		  while (curop < mce->m_nbel)
		   {
		    mo_ptre = mce->m_ptro+curop;
		    if ( mo_ptre->mo_atsel ==1 )
		       break;
		    curop++;
		  }
		  if ( curop == mc->m_nbel )
		    md_er = sfenr_inex;
		  optsav = optch = curop;
	     }/*atsel = 3 */
	     if (md_er == 0)
	       md_er = md_affc(mench,optch+1,0);

	     if(md_er)
	       {
		cpt_e--;
		mench = me[cpt_e].me_ma;
		optch = me[cpt_e].me_oa;
	       }
	     winv(mc->m_nofenc);
	    }
	  else
	    {
	     mo_ptr = (mc->m_ptro) + optch;
	     switch(mo_ptr->mo_eff)
	       {
		case 1:
		  nomena = 0;
		  md_er = md_affc(mench,optch+1,0);
		  break;

		case 2:
		  md_er = md_clearc(mench);
		  if(md_er)
		    {
			Wkup_out();	
			return(md_er);
		  }
		  if((cpt_e)  && (me[cpt_e-1].me_mc == mench))
		    {
		     cpt_e--;
		    }
		  break;

		case 3:
		  md_er = md_clearc(0);
		  /*2808  if(md_er) return(md_er); */
		  /*	  cpt_e = 0; */
		  break;

		case 4:
		  i = mench;
		  md_clearc(i);
		  while((cpt_e > 0) && (me[cpt_e-1].me_mc == i))
		    {
		     --cpt_e;
		     i = me[cpt_e].me_ma;
		     md_clearc(i);
		    }

	       } /* switch */

	     typc = 1;
	     *exit = RC;

	    } /* else */

	  break;


       } /* switch */

    } /* while */

  nomena = 0;

  /* renvoyer la valeur */

  if (( cpt_e == 0)&&(mench==md_no))	/* sortie sur racine */
	last_men = mench;
  else
	last_men = 0;
  *md_ptc = mench;
  *mo_ptc = optch+1;



  if((val_ptc != (BPTR) NULL) && (typc == 1))
    {
     mc = &md[mench];
     mo_ptr = mc->m_ptro;
     mo_valptr =(BPTR) mc->m_ptro;
     mo_valptr += sizeof(mo_tab)*(mc->m_nbel);
     mo_valptr += (mc->m_lel) * (optch);
     for(i = 0; i < mc->m_lel; ++i)
       val_ptc[i] = mo_valptr[i];
    }
  if((typc == 2) && (fl_esc == FALSE))
    *mo_ptc = 0;

  if(fl_esc == TRUE)
    {
     *md_ptc = memo_menu;
     *mo_ptc = memo_opt;
    }
  
  Wkup_out();
  return(OK);
}


/* fin de fichier */




