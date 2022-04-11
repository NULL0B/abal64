/****************************************
* Services Fenetres - Boites Valid  	*
*---------------------------------------*
* Source : sfbv.c                   	*
*---------------------------------------*
* Version : 1.1b                    	*
* Mise a jour le : 			*
* 15/06/1990   sb  			*
* 23/04/1992  EDS  ajout arg md_opt   	*
* 18/05/1992  EDS  gestion MOUSE	*
* 01/04/93    LLB  Styles fenetre	*
*****************************************
* Fonctions                         	*
*                                   	*
* - bvstd boite validation standard 	*
* - bvspc boite validation specif   	*
*                                   	*
****************************************/


/* modif le 8/8/1990 plig < MAXLIG - 2 */

#include "sfundef.h"
#include "mouse.h"

extern BYTE tb_style[MAXSTF];


extern EVENT_STR	event;




/**********************************************
* Boite de validation standard
***********************************************/

TYPF	bv_std(bv_nc,bv_ret)
	BYTE bv_nc;
	BPTR bv_ret;
{
/* fonctions externes */
TYPF bv_int();

/* variables externes */
	extern bv_tab bvc;
	extern WORD bv_f;
	extern BYTE bv_m;
/* variables internes */
	bv_desc		bv_de;	/* descripteur de boite */
	WORD		bv_er;
	int i,j,k;

/* corps de la fonction */
	bv_de.bv_nbc = bv_nc;
	bv_de.bv_stlf = 1;
	bv_de.bv_laff = 0;
	bv_de.bv_plig = bvc.v_plig;
	bv_de.bv_pcol = 0;
	bv_de.bv_noptd = *bv_ret;

	bv_er = bv_int( (bv_desc_ptr)&bv_de, (BPTR) NULL, (BPTR) bv_ret ,1);
	if (bv_er)
	  {
		if (bv_m) md_sup(bv_m);
		if (bv_f) wsup(bv_f);
	  };
	bv_f = 0;
	bv_m = 0;
	return(bv_er);
}



/**********************************************
* Boite de validation specifique
***********************************************/

TYPF	bv_spc(BV_de,bv_mes,bv_ret)
	BPTR BV_de;
	BPTR bv_mes;
	BPTR bv_ret;
{
/* variables internes */
int	bv_er;			/* code erreur */
bv_desc bv_de;			/* code interne */


	bv_de.bv_nbc = BV_de[BV_nbc];
	bv_de.bv_noptd = BV_de[BV_noptd];
	bv_de.bv_stlf = BV_de[BV_stlf];
	bv_de.bv_plig = BV_de[BV_plig] * 256 + BV_de[BV_plig+1];
	bv_de.bv_pcol = BV_de[BV_pcol] * 256 + BV_de[BV_pcol+1] ;
	bv_de.bv_laff = BV_de[BV_laff];

	bv_er = bv_spcc((bv_desc_ptr) &(bv_de.bv_nbc),bv_mes,bv_ret);

	return (bv_er);
}

/**********************************
* appel C standard                *
***********************************/
TYPF	bv_spcc(bv_de,bv_mes,bv_ret)
	bv_desc_ptr bv_de;
	BPTR bv_mes;
	BPTR bv_ret;
{
	extern WORD bv_f;
	extern BYTE bv_m;
	int bv_er;
	TYPF bv_int();

	bv_er = bv_int( (bv_desc_ptr)bv_de, (BPTR) bv_mes, (BPTR) bv_ret , 1);
	if (bv_m) md_sup(bv_m);
	if (bv_f) wsup(bv_f);
	bv_f = 0;
	bv_m = 0;

	return(bv_er);
}

/*********************************************
* Boite de validation : Affichage
**********************************************/
TYPF	bv_aff(bv_de,bv_mes,bv_type)
	bv_desc_ptr bv_de;
	BPTR bv_mes;
	BYTE bv_type;
{

/* variables externes */
	extern BYTE fen_ini;
	extern stf_desc stf[MAXSTF+1];
	extern stc_desc stc[MAXSTC];
	extern md_tab md[MAXMEN];
	extern char * tabmes[MAXMES];
	extern char tc[MAX_TOUCHES];

/* variables internes */
	WORD		bv_er;
	WDESC_APP  	fbv;		/* descripteur fenetre gen */
	int i,j,k,bv_nl,bv_nc,bv_pl,bv_pc;
	BYTE typc,menc,optc;		/* retour du menu */
	BYTE nbch,laff,nbc_m,lmes;
	extern WORD bv_f;			/* fenetre, menu */
	extern BYTE bv_m;
	BYTE bv_posm;
	BPTR pt;
	BPTR ptt;
	stf_desc *	syf;
	md_desc		bv_md;		/* descripteur menu */
	mo_desc		bv_mo;		/* descripteur option */
	WORD lgmv,lgmo,lgmn,lgma,lgmmax;
	char bufo[80];
	BYTE	style, styl_omb, styl_cad;
	WORD	o;			/* flag interne ombre */
/************************************
* verification des parametres       *

*************************************/

/* verification init */

	if (fen_ini != 2) return(werr_ini);

	if ((bv_de->bv_nbc == 0) || (bv_de->bv_nbc > 3)) return(werr_desc);
/*
	style = bv_de->bv_stlf;
	if ( style & SFOMB )
		style -= SFOMB;
	if (( style == 0) || (style > MAXSTF)) return(werr_desc);
*/
	if (bv_de->bv_laff > MAXCOL -1) return(werr_desc);
	if ((bv_type == 0) || (bv_type > 2)) return(werr_desc);

	if (bv_type == 1)
		{
			if (bv_f != 0) return(werr_desc);
			if (bv_m != 0) return(werr_desc);
		}
	else
	        {
		  if ((bv_f != 0) && (bv_m != 0))	/* modif 8/11/90 */
		    {
			wselect(bv_f);
			wvis(bv_f);
			wselect(md[bv_m].m_nofen);
			bv_er = md_aff(bv_m,1,0);
			return(bv_er);
		    };
		};

/*****************************************************
* calcul de la largeur de la boite                   *
******************************************************/

	laff = bv_de->bv_laff;
	if ((laff == 0) && (bv_mes != (BPTR) NULL)) return(werr_desc);

	if ((bv_type != 2 ) && (laff != 0))
		lmes = laff;
	else
		lmes = 0;
		ptt = bv_mes;

/*****************************************************
*  pas d'erreur decelee : tentative creation fenetre *
******************************************************/

	bv_pl = bv_de->bv_plig;
	if ((bv_pl == 0) || (bv_pl > MAXLIG - 2)) return(werr_desc);

/*****************************************************
* Calcul de la largeur de la boite de validation     *
******************************************************/

	lgmv = 0;
	for (pt = tabmes[MESV] ; *pt  ; ++pt) lgmv++;

	lgmo = 0;
	for (pt = tabmes[MESO] ; *pt  ; ++pt) lgmo++;
	lgmmax = lgmo;

	lgmn = 0;
	for (pt = tabmes[MESN] ; *pt  ; ++pt) lgmn++;
	if (lgmn > lgmmax) lgmmax = lgmn ;

	lgma = 0;
	for (pt = tabmes[MESA] ; *pt  ; ++pt) lgma++;
	if (lgma>lgmmax) lgmmax = lgma;
	--lgmmax;

	bv_nc =  3*(lgmmax+2); /* taille */ /* remis le 1911 */

	bv_pc = bv_de->bv_pcol;

	if (bv_pc == 0)
			bv_pc = (MAXCOL - bv_nc)/2 +1;	    /* centrage */

	if (bv_type == 2)
		   {
			bv_pc = bv_pc - (bv_nc/2) ;
			if (bv_pc == 0) bv_pc++;
		   };

	if (bv_de->bv_laff > bv_nc) return(werr_desc);


/* parametres fenetre */

	fbv.Amere_nbr = 0;
	fbv.Apos_lig = bv_pl;
	fbv.Apos_col = bv_pc;
	fbv.Anb_lig = 3;
	fbv.Anb_col = bv_nc;
	fbv.Aln_tit = 0;

/* style de fenetre */

	style = bv_de->bv_stlf;
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

	fbv.Aatb_vid = syf->f_fond.atbc;	/* attributs fond */
	fbv.Aatbcol_text = syf->f_fond.colc;
	fbv.Aatbcol_fond = syf->f_fond.colf;
	fbv.Acad_atb = syf->f_cad.atbc;		/* attributs cadre */
	fbv.Acad_text = syf->f_cad.colc;
	fbv.Acad_fond = syf->f_cad.colf;
	if ((syf->f_nostc > 0) && (bv_type !=2))
		 {
		    fbv.Acontrol =  33;			/* invisible cadre */
		    k = syf->f_nostc;
		    if ((k) && (k <= MAXSTC))
		     {
			   --k;
			   for (j=0;j<8;++j) fbv.Acad_usr[j] = stc[k].trait[j];
		     }
		    else
			fbv.Acontrol = 1;
	}
	else
		   fbv.Acontrol = 1;
/*	    }
	else
		fbv.Acontrol = 1;
*/
	if ( o )
		fbv.Acontrol += OMBRE;

/* creation fenetre */

	bv_f = 0;
	bv_er = wcreatc((WPTR)&bv_f,(WDESC_APP_PTR)&fbv);
	if (bv_er) return(bv_er);

/**********************************
* incrustation du message         *
***********************************/


/* choix du message a envoyer */

	nbch = bv_de->bv_nbc;

	if (bv_mes == (BPTR) NULL)
	   {
		if (nbch == 1)
		   {
			ptt = tabmes[MESSTV];
		   }
		else
		   {
			if (nbch == 2)
			  {
				ptt = tabmes[MESST2];
			  }
			else
			  {
				ptt = tabmes[MESST3];
			  };
		  };
	   }
	else
		ptt = bv_mes;

/* longueur du message */

	if ((laff == 0) || (bv_type == 2))
		{
			lmes = 1;
			for (pt = ptt ; *pt  ; ++pt) lmes++;
			if (laff == 0) laff = lmes;
		};

/* positionnement */

	if (lmes > bv_nc -1)
	   {
		bv_posm = 1;
	   }
	else
	   {
		bv_posm = (bv_nc - lmes) / 2;
		if (bv_posm*2 < (bv_nc - lmes)) bv_posm ++;
		bv_posm ++; 
	   };
	
	if (bv_posm > 1)
		bv_er = wposcur(bv_f,1,bv_posm);

/* envoi */

	bv_er = wwrite(bv_f,lmes,(BPTR) ptt);
	if (bv_er) return(bv_er);

/* visualisation */
	wvis(bv_f);
/*	if (bv_type != 2) bv_er = wvis(bv_f); */

/* creation du menu horizontal */

	for (bv_m = 1; bv_m <= MAXMEN ; ++ bv_m)
		if ( md[bv_m].m_nofen == 0) break;
	if (bv_m > MAXMEN) return(werr_desc);

	/* chargement du style specifique */
	/* modification du style courant pour la creation du menu : */
	/* pas de cadre, pas d'ombre */

	styl_omb = stf[style].f_ombre;		/* sauver courant */
	styl_cad = stf[style].f_nostc;
	stf[style].f_ombre = 0;                   /* pas de cadre */
	stf[style].f_nostc = 0;                 /* pas d'ombre */

	
	bv_md.md_stlf = bv_de->bv_stlf;		/*MAXXSTF+1;*/


	if ((bv_md.md_stlf>5)&&(bv_de->bv_stlf<15))
		bv_md.md_stlf -= SFOMB;		/* pas d'ombre dans le menu */

	bv_md.md_plig = bv_pl+2;
  	bv_md.md_typm = 1;
 	bv_md.md_esc  = 2;
 	bv_md.md_nbel = nbch;
 	bv_md.md_laff = lgmmax;
 	bv_md.md_lel = lgmmax;
 	bv_md.md_lcom = 0;

 /* centrage du menu */
	nbc_m = (lgmmax+1)*nbch;		/*!*/

	if (bv_nc < laff)
	   {
		bv_nc = laff;
/*
		i = (laff - nbc_a)/(nbch+1);
		if ((i) && (nbch > 1))
		   {
			nbc_o += i;
			nbc_a += i * nbch;
			nbc_m += i * nbch;
		   };
*/
	   };


	i =  (bv_nc - nbc_m)/2+1 ;

	bv_md.md_pcol = bv_pc + i;
	if (bv_md.md_pcol > 1) -- bv_md.md_pcol;
	bv_er = md_creatc(bv_m,(md_desc_ptr)&bv_md, NULL, (BPTR) NULL);

/* restituer caract. style  */
	stf[style].f_ombre = styl_omb;
	stf[style].f_nostc = styl_cad;
	if (bv_er) return (bv_er);

	bv_mo.mod_atetat = 2;
	bv_mo.mod_atsel = 1;
	bv_mo.mod_ataff = 1;
	bv_mo.mod_eff = 1;
	bv_mo.mod_optc = 0;
	bv_mo.mod_menc = 0;

 /* chargement des options */
	switch (nbch)
	  {
	case 1:
		pt = tabmes[MESV];
		bv_mo.mod_carcle = *pt;		/*0;*/

		for (i=0;i<lgmv;++i) bufo[i] = *++pt;
		for (   ;i<lgmmax ;++i) bufo[i] = ' ';
		bv_er = mo_creat(bv_m,1,(mo_desc_ptr)&bv_mo,(BPTR) bufo, (BPTR) bufo);

		break;

	case 2:
		pt = tabmes[MESO];
		bv_mo.mod_carcle = *pt;		/*0x00;*/

		for (i=0;(i<lgmo) && (*pt);++i) bufo[i] = *++pt;
		for (   ;i<lgmmax ;++i) bufo[i] = ' ';
		bv_er = mo_creat(bv_m,1,(mo_desc_ptr)&bv_mo,(BPTR) bufo, (BPTR) bufo);


		pt = tabmes[MESN];
		bv_mo.mod_carcle = *pt;		/*0x00;*/

		for (i=0;(i<lgmn) && (*pt) ;++i) bufo[i] = *++pt;
		for (   ;i<lgmmax ;++i) bufo[i] = ' ';
		bv_er = mo_creat(bv_m,2,(mo_desc_ptr)&bv_mo,(BPTR) bufo, (BPTR) bufo);


		break;

	case 3:
		pt = tabmes[MESO];
		bv_mo.mod_carcle = *pt;		/*0x00;*/

		for (i=0;(i<lgmo) && (*pt) ;++i) bufo[i] = *++pt;
		for (   ;i<lgmmax ;++i) bufo[i] = ' ';
		bv_er = mo_creat(bv_m,1,(mo_desc_ptr)&bv_mo,(BPTR) bufo, (BPTR) bufo);


		pt = tabmes[MESN];
		bv_mo.mod_carcle = *pt; 	/*(bv_type == 2) ? tc[T_TAB-1] : 0x00;*/

		for (i=0;(i<lgmn) && (*pt) ;++i) bufo[i] = *++pt;
		for (   ;i<lgmmax ;++i) bufo[i] = ' ';
		bv_er = mo_creat(bv_m,2,(mo_desc_ptr)&bv_mo,(BPTR) bufo, (BPTR) bufo);


		pt = tabmes[MESA];
		bv_mo.mod_carcle = *pt;	/*0x00;*/

		for (i=0;(i<lgma) && (*pt) ;++i) bufo[i] = *++pt;
		for (   ;i< lgmmax ;++i) bufo[i] = ' ';
		bv_er = mo_creat(bv_m,3,(mo_desc_ptr)&bv_mo,(BPTR) bufo, (BPTR) bufo);


		break;
	   };


	bv_er = md_aff(bv_m,1,0);

	return(bv_er);
}

/******************************************************
* Boite de validation : Choix d'une option (fonction c)
*******************************************************/

TYPF	bv_int(bv_de,bv_mes,bv_ret,bv_type)
bv_desc_ptr bv_de;
BPTR bv_mes;
BPTR bv_ret;
BYTE bv_type;

{

  /* fonctions appelees */
  TYPF bv_aff( );


  /* variables externes */
  extern WORD bv_f;			/* fenetre, menu */
  extern BYTE bv_m;


  /* variables internes */
  WORD bv_er;
  int i,j,k;
  BYTE typc,menc,optc;			/* retour du menu */
  BYTE nbch,laff,nbc_m,nbc_o,nbc_a;
  BYTE bv_posm;
  BYTE exit;


  /*************************************
  * affichage de la boite              *
  **************************************/

  if(bv_type != 2)
    {
     bv_er = bv_aff((bv_desc_ptr)bv_de,(BPTR)bv_mes,bv_type);
     if(bv_er)
       return(bv_er);
    }

  /* choix de l'utilisateur */
  do
    {
     event.event = NO_EVENT;
     bv_er = md_opt(bv_m,bv_de->bv_noptd,(BPTR)&menc,(BPTR)&optc,(BPTR)NULL, (BPTR)&exit);
     if(bv_er)
       return(bv_er);

     if((optc == 0) && (bv_de->bv_noptd == 3))
       {
	optc = 3;
	typc = 1;
       }

    } while (optc == 0) ;

  if((bv_type == 1) || (optc == 3))
    {
     if(bv_m != 0)
       md_sup(bv_m);

     if(bv_f != 0)
       wsup(bv_f);
     bv_m = 0;
     bv_f = 0;
    }

  *bv_ret = optc;

  return(OK);

} /*bv_int()*/

/* fin de fichier */

