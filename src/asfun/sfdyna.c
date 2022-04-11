/********************************************************
* Services Fenetres - Gestion des styles et langue	*
*-------------------------------------------------------*
* Source : sfdyna.c                  			*
*-------------------------------------------------------*
* Version : 1.1a                    			*
* Mise a jour le : 29/03/93 LLB				*
*
*********************************************************
* Fonctions                         			*
*                                   			*
* - get_style()	  Lire caracteristiques  style fenetre  *
* - set_style()	  Positionner stymle fenetre		*
* - wlangue()	  Positionner la langue d'utilisation	*
********************************************************/


#include "sfundef.h"


extern stf_desc stf[MAXSTF];
extern BYTE tb_style[MAXSTF];

extern BYTE * tabmes[];
extern BYTE * tablang0[];
extern BYTE * tablang1[];
extern BYTE * tablang2[];
extern BYTE * tablang3[];
extern BYTE * tablang4[];
extern BYTE * tablang5[];

/************************************************************
*
*     LECTURE STYLE FENETRE
*
*     Input: No STYLE, Descripteur Style
*
************************************************************/


TYPF	get_style( BYTE style, BPTR param /*STYL_DESC_PTR DataStyle*/ )
{
STYL_DESC_PTR DataStyle;

DataStyle = param;
  if ( (style < 1) || (style > STYLMAX+1) )
	return(werr_desc);
  if ( (style > 5) && (style < 20) )
	return(werr_desc);

  if ( style > 5)		/* 20..27 -> 5..13 */
    {
	  style -= 15;
	  if ( tb_style[style] == 0 )
		return(werr_inex);
  }
  else                          /* 1..5   -> 0..4  */
     style--;

  DataStyle->arg1 = stf[style].f_nostc;
  DataStyle->arg3 = stf[style].f_cad.colf ;
  DataStyle->arg4 = stf[style].f_cad.colc ;
  DataStyle->arg2 = stf[style].f_cad.atbc ;
  DataStyle->arg6 = stf[style].f_fond.colf;
  DataStyle->arg7 = stf[style].f_fond.colc;
  DataStyle->arg5 = stf[style].f_fond.atbc;
  DataStyle->arg8 = stf[style].f_ombre ;

  return(OK);
}/*get_style */



/************************************************************
*
*     ECRITURE STYLE FENETRE
*
*     Input: No STYLE, Descripteur Style
*
************************************************************/


TYPF	set_style( BYTE style, BPTR param /*STYL_DESC_PTR DataStyle*/ )

{
STYL_DESC_PTR DataStyle;
BYTE 	atb;

DataStyle = param;

  if ( (style < 1) || (style > STYLMAX) )
	return(werr_desc);
  if ( (style > 5) && (style < 20) )
	return(werr_desc);

  if ( style > 5)		/* 20..27 -> 5..13 */
     style -= 15;
  else                          /* 1..5   -> 0..4  */
     style --;

  /* controle validite des parametres */

  if ( DataStyle->arg1 > 3 )	/* cadre */
	return(werr_desc);

  atb = DataStyle->arg2;	/* atb cadre */
  if ((atb != 0)&&(atb !=1)&&(atb !=2)&&(atb !=4)&&(atb !=8)&&(atb !=128))
	return(werr_desc);

  if ( DataStyle->arg3 > 7 )  /* colf cadre */
	return(werr_desc);
  if ( DataStyle->arg4 > 15 )	/* colc cadre */
	return(werr_desc);

  atb = DataStyle->arg5;	/* atb fun */
  if ((atb != 0)&&(atb !=1)&&(atb !=2)&&(atb !=4)&&(atb !=8)&&(atb !=128))
	return(werr_desc);

  if ( DataStyle->arg6 > 7 )   /* colf fun  */
	return(werr_desc);
  if ( DataStyle->arg7 > 15 )   /* colc fun */
	return(werr_desc);
  if ( DataStyle->arg8 > 1 )	/* ombre */
	return(werr_desc);

  tb_style[style] = 1;
  stf[style].f_nostc     = DataStyle->arg1;
  stf[style].f_cad.colf  = DataStyle->arg3;
  stf[style].f_cad.colc  = DataStyle->arg4;
  stf[style].f_cad.atbc  = DataStyle->arg2;
  stf[style].f_fond.colf = DataStyle->arg6;
  stf[style].f_fond.colc = DataStyle->arg7;
  stf[style].f_fond.atbc = DataStyle->arg5;
  stf[style].f_ombre     = DataStyle->arg8;


  return(OK);

}/*set_style */

/************************************************************
*
*     Modification Langue
*
*     Input: No Langue
*
*	0 :Francais	
*	1: Anglais
*	2: Allemand
*	3: Espagnal
*	4: Italien
*	5: Holandais
*      16: GESMES (-> autre )			
************************************************************/


TYPF	wlangue( BYTE langue)
{
WORD i;
char *pt;

  if ( langue == 16 )	/* gesmes */
   {
	pt = tabmes[0];
        for (i=0 ; i < MAXMES ; ++i)
	{
	  tabmes[i] = pt;
	  while (*pt != EOS) pt++;
	  while (*pt == EOS) pt++;
        }
      	return(OK);
  }/*gesmes*/

/* francais */
/************/
  if ( langue == 0)	
   {
	for ( i = 0; i < MAXMES-1; i++)
	{
	  pt = tablang0[i];
	  tabmes[i+2] = pt;
	}
	return(OK);
   }

/* Anglais */
/***********/
  if ( langue == 1)
   {
	for ( i = 0; i < MAXMES-1; i++)
	{
	  pt = tablang1[i];
	  tabmes[i+2] = pt;
	}
	return(OK);
    }

/* Allemand */
/***********/

   if ( langue == 2)
    {
	for ( i = 0; i < MAXMES-1; i++)
	{
	  pt = tablang2[i];
	  tabmes[i+2] = pt;
	}
	return(OK);
     }

/* ESPAGNOL */
/************/
    if ( langue == 3)
      {
	for ( i = 0; i < MAXMES-1; i++)
	{
	  pt = tablang3[i];
	  tabmes[i+2] = pt;
	}
	return(OK);
     }

/* ITALIEN */
/***********/
    if ( langue == 4)
     {
	for ( i = 0; i < MAXMES-1; i++)
	{
	  pt = tablang4[i];
	  tabmes[i+2] = pt;
	}
	return(OK);
     }
/* HOLLANDAIS */
/**************/
    if ( langue == 5)
     {
	for ( i = 0; i < MAXMES-1; i++)
	{
	  pt = tablang5[i];
	  tabmes[i+2] = pt;
	}
	return(OK);
     }

/* autres */
 return(werr_desc);

}/*wlangue*/

/* fin de fichier */
