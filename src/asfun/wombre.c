/* this is a quick fix for ABAL Use It for the Demo 23/10/2001 (IJM) */

/* #define	_NO_SHADOW	1 */

/************************************
* Fenetrage - OMBRAGE	fenetres    *
*-----------------------------------*
* Source : WOMBRE.C                 *
*-----------------------------------*
* Version : 1.1a                    *
* Creation    le : 24/12/1991  llb  *
* maj		26.03.1992 llb
*************************************
* Fonctions                         *
*                                   *
* - set_ombre(f)   Ombrer une fenetre  *
* - reset_ombre(f) Clear ombre	    *
*************************************/

#include "fundef.h"

/* variables globales */

extern BYTE fen_ini;	/* flag winit */
extern BYTE edb_ini;	/* flag mem_init */
extern WORD omb_atrib;	/* attributs ombreage */


extern WITEM*  *mapecran;

extern WITEM	*avp;		/* fenetre en avant plan	*/

extern	WITEM*  WLOG[MAXFUN];

extern	WORD	MAXLIG,MAXCOL;	/* taille ecran */
extern  WORD     fimpl;		/* fenetre implicite */
extern  WORD     sav_impl;	/* sauvegarde fenetre implicite */
extern	WORD	PRLMF;

extern  BYTE topvis;

WORD is_down(WITEM*,WITEM*);


/************************************************
* 	fonction Ombrer une fenetre		*
*************************************************/


TYPF set_ombre(wi)
WITEM *wi;		/* fenetre a ombrer */
{
  WITEM* test;
  WITEM* *cur_map;
  WDESC_PTR wd;
  WORD temp,bd;
  WORD  lng, start,l;
  WORD  lng_col, start_col;
  WORD	glig,gcol,nlig,ncol;
  APP_MV2	desc_mv2;
#ifdef	_NO_SHADOW
	return(OK);
#endif
  wd = wi->wdesc_ptr;
  temp = wd->control ;
  bd = (((temp & CAD1) || (temp & CAD2) || (temp & CAD3)) ? 1 : 0);
  desc_mv2.nfonc   = SETATB ;
  desc_mv2.inc_buf = 2 ;
  desc_mv2.adr_text = (BPTR) &omb_atrib;
  desc_mv2.adr_atb = (WPTR)NULL;

 /*  calcul colonne ombre verticale
	+---------+
	|	  |x
	|         |x
	+---------+x
 */

  glig = wd->pos_lig +1 - bd;
  gcol = wd->pos_col + wd->nb_col + bd -1;

  if (gcol < MAXCOL) {

	desc_mv2.mvnbcol = 1 ;
	desc_mv2.mvcol   = gcol+1;

	if ( wi == avp )
	{
		desc_mv2.mvlig   = glig;
		desc_mv2.mvnblig = wd->nb_lig + bd;
		mv2(&desc_mv2);
	}
	else {
	   /* On ombre si: - le bord droit est visible
			   - le caractere ombrer est "sous" la fenetre courante
	      Des qu'une des deux conditions est fausse, on ombre la portion
	   */

		start = glig;
		lng = 0;
		cur_map = mapecran + (MAXCOL*(glig-1)+gcol-1);
		for ( l = 0 ; l < wd->nb_lig+bd ; l++, cur_map += MAXCOL )
		{
		    /* rechercher le debut ombre */
		    if (   ( (*cur_map==wi) ||
			   ((*cur_map!=wi)&&(l == wd->nb_lig+bd-1)) )/* un caractere de plus */
			&& (is_down(*(cur_map+1), wi)))
			lng++;			/* ombrage OK */
		    else
		    {
			if ( lng == 0 )
				start++;
			else
			{
			    desc_mv2.mvlig   = start;
			    desc_mv2.mvnblig = lng ;

			    mv2(&desc_mv2);
			    start += lng+1;
			    lng = 0;
			}
		    }
		}/*for*/
		if ( lng != 0) {
			desc_mv2.mvlig   = start;
			desc_mv2.mvnblig = lng +bd;
			mv2(&desc_mv2);
		}
	}/*else pas en AVP*/
  }/*gcol > MAXCOL*/

 /*  calcul ligne ombre horizontale

	+---------+
	|	  |
	|         |
	+---------+
	 xxxxxxxxxxx
 */

  glig = wd->pos_lig + wd->nb_lig + bd -1;
  gcol = wd->pos_col + 1 - bd;

  if (glig < MAXLIG)  {

	desc_mv2.mvnblig = 1 ;
	desc_mv2.mvlig = glig+1 ;

	if (wi == avp)
	{
		desc_mv2.mvcol   = gcol;
		desc_mv2.mvnbcol = wd->nb_col + 2*bd ;
  		if ((gcol + wd->nb_col ) == MAXCOL)
			desc_mv2.mvnbcol-- ;		/* car ombre droite hors ecran*/ 
		mv2(&desc_mv2);
	}
	else {  /* meme traitement que pour colonne */
		start = gcol;
		lng = 0;
		cur_map = mapecran + (MAXCOL*(glig-1)+gcol-1);
		for ( l = 0 ; l < wd->nb_col+bd ; l++, cur_map ++ )
		{
		    /* rechercher le debut ombre */
		    if ( (*cur_map==wi) && ( is_down(*(cur_map+MAXCOL), wi)))
			lng++;			/* ombrage OK */
		    else
		    {
			if ( lng == 0 )
				start++;
			else
			{
			    desc_mv2.mvcol   = start;
			    desc_mv2.mvnbcol = lng ;
			    mv2(&desc_mv2);
			    start += lng+1;
			    lng = 0;
			}
		    }
		}/*for*/
		if ( lng != 0) {
			desc_mv2.mvcol   = start;
			desc_mv2.mvnbcol = min((lng+bd),MAXCOL-start+1);
			mv2(&desc_mv2);
		}


	}/*else pas AVP*/
  }/*glig > MAXLIG*/
} /* set_ombre */

/************************************************
* 	fonction "DesOmbrer" une fenetre	*
*************************************************/


TYPF reset_ombre(wi)
WITEM *wi;		/* fenetre a ombrer */
{
  WDESC_PTR wd;
  WORD temp,bd;
  WORD	attrib;
#ifdef	_NO_SHADOW
	return(OK);
#endif
  wd = wi->wdesc_ptr;

  temp = wd->control ;
  bd = (((temp & CAD1) || (temp & CAD2) || (temp & CAD3)) ? 1 : 0);

 /*  supprimer ombre verticale */
  if ( (wd->pos_col+wd->nb_col +bd) <= MAXCOL )
	  show_rect( wd->pos_lig+1-bd, wd->pos_col+wd->nb_col+bd, /*plig,pcol*/
		     wd->nb_lig + bd , 1 );			  /*nlig,ncol*/

 /*  supprimer ombre horizontale */
  if ((wd->pos_lig + wd->nb_lig + bd) <= MAXLIG) {
	temp = wd->nb_col+ 2* bd;

		if ((wd->pos_col + wd->nb_col+bd ) > MAXCOL)
			temp-- ;		/* car ombre droite hors ecran*/

	show_rect(wd->pos_lig+wd->nb_lig+bd, wd->pos_col+1-bd,    /* plig,pcol */
		  1, temp );			  /* nlig,ncol */
  }
  return(OK);
}/*reset_ombre*/

/************************************************
* 	IS_DOWN(TEST,REF)			*
*************************************************
Cette fonction retourne VRAI si TEST est "sous" REF.
*/

WORD is_down(WITEM *test, WITEM *ref)
{
 WITEM *cur;
	if (test == NULL)
		return(TRUE);
	cur = ref;
	while ( cur->fsous != NULL)
	{
		if ( test == cur->fsous )
			return(TRUE);
		cur = cur->fsous;
	}
	return(FALSE);
}/*is_down*/


/* fin de fichier */
