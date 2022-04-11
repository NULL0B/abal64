/************************************
* Fenetrage - Deplacer fenetres     *
*-----------------------------------*
* Source : WMOVE.C                  *
*-----------------------------------*
* Version : 1.1a                    *
* Creation    le : 19/07/1991  llb  *
* MAJ:	01.04.93 llb
*	Styles dans SWCREAT
*
*************************************
* Fonctions                         *
*                                   *
* - wmove       deplacer une fen    *
* - swcreat     creation simple fenetre
* - wfinfo	Information fenetre *
*************************************/

#include "sfundef.h"
#include "bda.h"

/* variables globales */

extern BYTE fen_ini;	/* flag winit */
extern BYTE edb_ini;	/* flag mem_init */

extern WITEM*  *mapecran;
extern	APP_MV2	*desc_mv2;

extern WITEM	*avp;		/* fenetre en avant plan	*/

extern	WITEM*  WLOG[MAXFUN];

extern	WORD	MAXLIG,MAXCOL;	/* taille ecran */
extern  WORD     fimpl;		/* fenetre implicite */
extern  WORD     sav_impl;	/* sauvegarde fenetre implicite */


extern	WORD gplig, gpcol, gnlig, gncol;

extern  BYTE topvis;

extern	GLOBAL BDA_ARG rt_arg;
extern	WDESC_APP_F fen;	/* descripteur creation fenetre */

extern  stf_desc stf[MAXSTF+1]; /* table des styles fenetre */
extern  stc_desc stc[MAXSTC];	/* table des cadres fenetre */
extern BYTE tb_style[MAXSTF];

/************************************************
* 	fonction deplacer une fenetre		*
*************************************************/

/* fonction prologue */

TYPF wmove( f, NewLig, NewCol)
WORD	f;  		/* fenetre a deplacer */
WORD    NewLig;
WORD 	NewCol;
{
  WORD temp,bd;
  WDESC_PTR wd;
  WITEM	*wi;


/*********************************
* Verification Init              *
*********************************/


  if (fen_ini == 0)   			/* test winit() */
	return(werr_ini);

  if ((f > MAXFUN) || (f < 1))
	return(werr_inex);		/* fenetre inexistante */
  wi=WLOG[f-1];
  if (wi->mere == (WITEM*)NULL)
	return(werr_inex);		/* fenetre inexistante */

  wd = wi->wdesc_ptr;



/* test validite parametres */

  gplig = NewLig ;
  gpcol = NewCol ;
  gnlig = wd->nb_lig ;
  gncol = wd->nb_col ;

  temp = wd->control ;

  bd = (((temp & CAD1) || (temp & CAD2) || (temp & CAD3)) ? 1 : 0);


  if( (((short int)(gplig-bd)) <= 0) || ((gplig+bd) > MAXLIG ) ||
      (((short int)(gpcol-bd)) <= 0) || ((gpcol+bd) > MAXCOL ) ||
      (gnlig == 0) || (gncol == 0) ||
      ((gplig + gnlig +bd) > MAXLIG+1 ) ||
      ((gpcol + gncol + bd) > MAXCOL+1 ) )
  return(werr_desc);

  if ( wd->control & INVISIBLE) {
	 wd->pos_lig = NewLig;		/* set new position */
	 wd->pos_col = NewCol;
	 return(OK);
  }
  winv(f);
  wd->pos_lig = NewLig;
  wd->pos_col = NewCol;
  wvis(f);
  return(OK);

} /* wmove */

/********************************************************
* 	fonction CREATION SIMPLIFIEE de fenetre		*
********************************************************/


TYPF	swcreat(f, plig,pcol,nlig,ncol)

WPTR	f;
WORD	plig;
WORD	pcol;
WORD	nlig;
WORD	ncol;
{
	BYTE	style;
	WORD	control;
	BYTE	titre[33],i;
	int	coder;
	WORD	nlog;
	BPTR temp;

	if(rt_arg.c > 8)
	 	return(RT_err_arg);

	titre[0] = 0;		/** chaine nulle **/
	control = 6;
	style = 1;

	if (rt_arg.c > 5) {
		if(rt_arg.t[5] == TYPE_DIESE)
			style = GetAbalByte( rt_arg.v[5] );
		else if (rt_arg.t[5] == TYPE_POURCENT)
			style = GetAbalWord( rt_arg.v[5] );
		else if (rt_arg.t[5] == TYPE_DEUXPOINT)
			style = GetAbalLong( rt_arg.v[5] );
		else	return(RT_err_typ);
		}
	if (rt_arg.c > 6)   {
		if(rt_arg.t[6] == TYPE_DIESE)
			control = GetAbalByte( rt_arg.v[6] );
		else if (rt_arg.t[6] == TYPE_POURCENT)
			control = GetAbalWord( rt_arg.v[6] );
		else if (rt_arg.t[6] == TYPE_DEUXPOINT)
			control = GetAbalLong( rt_arg.v[6] );
		else	return(RT_err_typ);
		}
	if (rt_arg.c > 7)   {
		if(rt_arg.t[7] != TYPE_CHAINE)
			return(RT_err_typ);
		if ( rt_arg.l[7] > 0 ) 	{
			for ( i = 0; i < rt_arg.l[7]; i++ )
				titre[i] = ((BPTR)rt_arg.v[7])[i];
			/*calcul longueur titre */
			i = rt_arg.l[7]-1;
			while (( titre[i] == ' ')&& (i>=0))
				i--;
			titre[++i] = 0;			/** fin chaine **/
		}
		else
			titre[0] = 0;		/*pas de titre merde !!!!!! */
	}


	coder = swcreatc(&nlog, plig, pcol, nlig, ncol, style, control, (BPTR)titre);
#ifdef IDIRECT
	nlog = Invint(nlog);
	memcpy(f,&nlog,sizeof(WORD));
#else
	memcpy(f,&nlog,sizeof(WORD));
#endif
	return coder;

} /*swcreat*/

TYPF	swcreatc(f, plig,pcol,nlig,ncol,style,control,titre)

WPTR	f;
WORD	plig;
WORD	pcol;
WORD	nlig;
WORD	ncol;
WORD	control;
BYTE	style;
BPTR    titre;
{
WDESC_APP_PTR	wd;
WORD		i,j,k,o;
stf_desc	*syf;

	wd = (WDESC_APP_PTR) &fen;
	wd->Amere_nbr = 0;
	wd->Apos_lig = plig;
	wd->Apos_col = pcol;
	wd->Anb_lig = nlig;
	wd->Anb_col = ncol;

/* style de fenetre */

	if ( (style < 1) || (style > STYLMAX) )
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

	wd->Aatb_vid = syf->f_fond.atbc;	/* attributs fond */
	wd->Aatbcol_text = syf->f_fond.colc;
	wd->Aatbcol_fond = syf->f_fond.colf;

	wd->Acad_atb = syf->f_cad.atbc;		/* attributs cadre */
	wd->Acad_text = syf->f_cad.colc;
	wd->Acad_fond = syf->f_cad.colf;

	if ( o )  control += OMBRE;

	if (syf->f_nostc > 0)			/* fenetre avec cadre */
	 {
	    control += CAD3;			/* invisible cadre usr */
	    k = syf->f_nostc;
	    --k;
	    for ( j=0 ; j < 8 ; ++j)
		wd->Acad_usr[j] = stc[k].trait[j];
	 }
	wd->Acontrol = control;
/* titre */
	i = 0;
	while ( titre[i] != 0 )
		wd->Atitre[i] = titre[i++];
	wd->Aln_tit = i;
	for (  ; i <TAIL_TITRE ; i++)
		wd->Atitre[i] = ' ';

/* creation fenetre */

#ifdef SPARC
        o = wcreatc(f,(WDESC_APP_PTR) wd);
        return(o);
#else
	return ( wcreatc(f,(WDESC_APP_PTR) wd));
#endif

}/*swcreatc*/
/****************************************
* 	fonction INFO fenetre		*
*****************************************/

#ifdef PRL
TYPF wfinfo( f, wr)
WORD	f;  		/* fenetre a deplacer */
WDESC_APP_PTR	wr;

{
  WORD i;
  WDESC_PTR wd;
  WITEM	*wi;


/*********************************
* Verification Init              *
*********************************/


  if (fen_ini == 0)   			/* test winit() */
	return(werr_ini);

  if ((f > MAXFUN) || (f < 1))
	return(werr_inex);		/* fenetre inexistante */
  wi=WLOG[f-1];
  if (wi->mere == (WITEM*)NULL)
	return(werr_inex);		/* fenetre inexistante */

  wd = wi->wdesc_ptr;

  wr->Amere_nbr = 0;
  wr->Apos_lig = Invint(wd->pos_lig);
  wr->Apos_col = Invint(wd->pos_col);
  wr->Anb_lig = Invint(wd->nb_lig);
  wr->Anb_col = Invint(wd->nb_col);

  wr->Aatb_vid = (BYTE) (wd->bas_atb >> 8);
  wr->Aatbcol_text = (BYTE) (wd->bas_atb & 0x0f);
  wr->Aatbcol_fond = (BYTE) (wd->bas_atb >> 4 );
  wr->Acontrol =  Invint(wd->control);

  wr->Aln_tit  =  Invint(wd->ln_tit);
  for ( i = 0; i < wd->ln_tit ; i++ )
	wr->Atitre[i] = wd->titre[i];
  for ( ; i < TAIL_TITRE; i++)
	wr->Atitre[i] = ' ';		/* completer a blanc*/

  for ( i = 0; i < 8; i++)
	wr->Acad_usr[i] = wd->cadre[i];
  wr->Acad_atb = (BYTE) (wd->cad_atb >> 8);
  wr->Acad_text = (BYTE) (wd->cad_atb & 0x0f);
  wr->Acad_fond = (BYTE) (wd->cad_atb >> 4 );

  wr->reserve = 0;


#else	/* dos/unix */


TYPF wfinfo( f, wb)
WORD	f;  		/* fenetre a deplacer */
BPTR	wb;

{
  WORD i;
  WDESC_PTR wd;
  WITEM	*wi;

/*********************************
* Verification Init              *
*********************************/


  if (fen_ini == 0)   			/* test winit() */
	return(werr_ini);

  if ((f > MAXFUN) || (f < 1))
	return(werr_inex);		/* fenetre inexistante */
  wi=WLOG[f-1];
  if (wi->mere == (WITEM*)NULL)
	return(werr_inex);		/* fenetre inexistante */

  wd = wi->wdesc_ptr;
/*********************************
* Transfert de la structure ABAL *
**********************************/


	wb[Bmere_nbr]   =0;
	wb[Bmere_nbr+1] = 0;
	wb[Bpos_lig] = (BYTE) (wd->pos_lig>>8);
	wb[Bpos_lig+1] = (BYTE) (wd->pos_lig);
	wb[Bpos_col] = (BYTE) (wd->pos_col>>8);
	wb[Bpos_col+1] = (BYTE) (wd->pos_col);
	wb[Bnb_lig]  = (BYTE) (wd->nb_lig>>8);
	wb[Bnb_lig+1]  = (BYTE) (wd->nb_lig);
	wb[Bnb_col]  = (BYTE) (wd->nb_col>>8);
	wb[Bnb_col+1]  = (BYTE) (wd->nb_col);

	wb[Batb_vid]    = (BYTE) (wd->bas_atb >> 8);
	wb[Batbcol_text]= (BYTE) (wd->bas_atb & 0x0f);
	wb[Batbcol_fond]= (BYTE) (wd->bas_atb >> 4 );

	wb[Bcontrol]  = (BYTE) (wd->control>>8);
	wb[Bcontrol+1] = (BYTE) (wd->control);
	wb[Bln_tit]    = (BYTE) (wd->ln_tit>>8);
	wb[Bln_tit+1]  = (BYTE) wd->ln_tit;

	for (i=0; i< wd->ln_tit ; i++)
		wb[Btitre+i] = wd->titre[i];
	for ( ; i < TAIL_TITRE; i++)
		wb[Btitre+i] = ' ';		/* completer a blanc*/

	for (i=0; i< 8 ; ++i)
		wb[Bcad_usr+i] = wd->cadre[i];

	wb[Bcad_atb]  = (BYTE) (wd->cad_atb >> 8);
	wb[Bcad_text] = (BYTE) (wd->cad_atb & 0x0f);
	wb[Bcad_fond] = (BYTE) (wd->cad_atb >> 4 );
	wb[Breserve] = 0;
	wb[Breserve+1] = 0;
#endif

  return(OK);
}/*wfinfo*/

/* fin de fichier */
