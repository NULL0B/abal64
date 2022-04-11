/************************************
* Fenetrage - fonctions diverses    *
*-----------------------------------*
* Source : WREQUI.C		    *
*-----------------------------------*
* Version : 1.1b		    *
* Creation    le : 03/03/1989  llb  *
* Mise a jour le : 15/06/1990	sb  *
*************************************
* Fonctions			    *
*				    *
* - show_rect	affichage intersect *
* - min_rect	rectangle min affic *
* - wscroll	scrolling fenetre   *
* - get_cord	coordonnees ecran   *
* - min_data			    *
*************************************/

#include "fundef.h"

/* variables globales */

extern WITEM*		*mapecran;
extern APP_MV2	*desc_mv2;

extern WITEM	*avp;		/* fenetre en avant plan	*/

extern	WITEM*	WLOG[MAXFUN];

extern	WORD	MAXLIG,MAXCOL;	/* taille ecran */
extern	char	ecr_txt;	/* caractere fond ecran */
extern	WORD	ecr_atb;	/* attribut fond ecran */


extern	WORD gplig;
extern	WORD gpcol;
extern	WORD gnlig;
extern	WORD gncol;


/****************************************
Fonctions externes
------------------
*/
extern	void mv2();



/****************************************
*	SHOWRECT			*
*****************************************
* DESCRIPTION: a partir des coordonnees du rectangle relatif a la vue,
		construction du descripteur MV2, suivant MAPECRAN.
*/

int show_rect(plig,pcol,nlig,ncol)
WORD	plig,pcol,nlig,ncol;
{
	WDESC_PTR w;
	WITEM	*f,*t;
	WORD	l,c,lf,cf,bd;
	WORD	i,cpt,attrib;
	BPTR mv2_text;
	BPTR ftext;
	WPTR mv2_atb;
	WPTR fatb;

	/* controle */
	if ((nlig==0) || (ncol == 0))
		return(0);


	/* preparation descripteur appel MV2 */

	desc_mv2->nfonc   = AFFICHE;
	desc_mv2->mvlig   = plig;
	desc_mv2->mvcol   = pcol;
	desc_mv2->mvnblig = nlig;
	desc_mv2->mvnbcol = ncol;
	desc_mv2->inc_buf = ncol;

	desc_mv2->adr_text = desc_mv2->std_text;
	desc_mv2->adr_atb  = desc_mv2->std_atb;

	/* init var locales */

	mv2_text = desc_mv2->adr_text;
	mv2_atb  = desc_mv2->adr_atb;

	/* pour chaque point du rectangle, copie du texte + attribut de la fenetre
   	 * correspondante dans APP_MV2
	 */

	for ( l = plig; l < plig + nlig ; l++) {
   		c = pcol;
   		while ( c < pcol+ncol) {
			f = *(mapecran + (MAXCOL*(l-1)) + (c-1) );
			cpt = 0;
			t = f;
		/* calcul nbre colonnes meme fenetre */
	     		while (( t == f ) && ( c < pcol+ncol)) {
				cpt++;
				t = *(mapecran + (MAXCOL*(l-1)) + (++c -1) );
				}

     			if ( f == (WITEM*)NULL ) {			/* fond ecran */
	  			wmemset(mv2_text, ecr_txt, cpt);		/* texte */
	    			mv2_text += cpt;
	    			wwmemset(mv2_atb, ecr_atb , cpt);	/* attribut */
	    			mv2_atb += cpt;
	  			}
      			else	{
	    			w = f->wdesc_ptr;
	    			bd = w->cad;
	    			ftext = w->adr_text;
	    			fatb = w->adr_atb;
	    			lf = l - w->pos_lig + bd;		 /* ligne relative fenetre */
	    			cf = ( c - cpt ) - w->pos_col +bd;	 /* colonne	 "         */
				/* recopie texte */
				wmemcpy( mv2_text , (ftext + ((w->nb_col+(2*bd))*lf) + cf),cpt );
				mv2_text += cpt;
				/* recopie attribut */
	    			wmemcpy( mv2_atb , (fatb + ((w->nb_col+(2*bd))*lf) + cf),cpt*2 );
	    			mv2_atb += cpt;

	   			} /* else */
    			} /* while c<pcol+ncol */

  		} /* for l */

	mv2(desc_mv2); /* appel "MV2" (affichage) */

	return(OK);

 }/*show_rect*/

/*********************************************
*	min_rect()			     *
**********************************************

cette fonction	calcule le rectangle physique
minimum de la fenetre visible a l'ecran, cadre compris.
(appel wwrite,winv)
*/

int min_rect(f)
 WITEM	*f;
{
 WORD  t,lh,lb,cg,cd,l,c;


 get_cord(f);		/* coord fenetre sur ecran */

/* calcul ligne haute */

 lh = 0;
 t  = 0;
     for ( l = gplig ; l < (gplig+gnlig) ; l++)
       {
	for ( c = gpcol ; c < (gpcol+gncol) ; c++)
	  if( (*(mapecran+(MAXCOL*(l-1))+c-1)) == f)
	    {
	     t++;
	     break;
	    }
	if ( t == 0)
	   lh++;
	else
	   break;
       }/*for l= */

/* calcul ligne basse */

 lb = 0;
 t = 0;
    for ( l = (gplig+gnlig-1) ; l >= gplig ; l--)
       {
	for ( c = gpcol ; c < (gpcol+gncol) ; c++)
	  if( (*(mapecran+(MAXCOL*(l-1))+c-1)) == f)
	    {
	      t++;
	      break;
	     }
	if ( t == 0)
	   lb++;
	else
	   break;
       }/* for */

/* calcul colonne gauche */

 cg = 0;
 t  = 0;
    for ( c = gpcol ; c < (gpcol+gncol) ; c++)
      {
       for ( l = gplig ; l < (gplig+gnlig) ; l++)
	  if( (*(mapecran+(MAXCOL*(l-1))+c-1)) == f)
	    {
	      t++;
	      break;
	    }
	if ( t == 0)
	   cg++;
	else
	   break;
       }/*for*/

/* calcul colonne droite */

 cd = 0;
 t  = 0;
    for ( c = (gpcol+gncol-1) ; c >= gpcol ; c--)
      {
       for ( l = gplig ; l < (gplig+gnlig) ; l++)
	  if( (*(mapecran+(MAXCOL*(l-1))+c-1)) == f)
	   {
	    t++;
	    break;
	   }
	if ( t == 0)
	   cd++;
	else
	   break;
       }/*for*/

 gplig += lh;
 gpcol += cg;
 gnlig -= lb+lh;
 gncol -= cd+cg;

 if (( cg == cd) && (cg!=0))
    gncol = 0;
 if ((lh == lb) && (lh !=0))
    gnlig = 0;

 return(OK);
}/*minrect()*/

 /***************************************************************
 *	MIN_DATA()
 ****************************************************************
cette fonction	calcule le rectangle physique
minimum de la fenetre visible a l'ecran, cadre NON compris.
*/
 void	min_data(wi)
 WITEM	*wi;
 {
   WDESC_PTR wd;
   WORD bd;

   wd = wi->wdesc_ptr;
   bd = wd->cad;

   min_rect(wi);
   if ( bd != 0 )	/* supprimer cadre dans les coord. fenetre */
	{
	 if ( gpcol == wd->pos_col-1)
	   {
	     gpcol++;		/* sauter cadre gauche */
	     gncol--;		/* 1 colonne de moins */
	   }
	 if ( gplig == wd->pos_lig-1)
	   {
	     gplig++;		/* sauter cadre gauche */
	     gnlig--;		/* 1 colonne de moins */
	   }
	 if ( gnlig == wd->nb_lig+1)
	     gnlig--;		/* supprimer cadre bas */
	 if (gncol == wd->nb_col+1)
	     gncol--;		/* supprimer cadre droit */
	}/*bd*/
}/*min_data()*/



 /***************************************************************
 *	Obtenir les coordonnees physiques de F sur l'ecran      *
 ****************************************************************/

 int	get_cord(f)
 WITEM	*f;
 {
  WDESC_PTR w;
  WORD	bd;

  w = f->wdesc_ptr;
  bd = w->cad;

  /* calcul coord. physique de la fenetre sur la vue. */
    gplig = w->pos_lig - bd;
    gpcol = w->pos_col -bd;
    gnlig = w->nb_lig + (2*bd);
    gncol = w->nb_col + (2*bd);

} /*get_cord */

 /***************************************************************
 *		SCROLL D'UNE FENETRE                            *
 ****************************************************************/

 void wscroll(wd,dir,start)
 WDESC_PTR wd;		/* descripteur de la fenetre	*/
 WORD	dir;		/* direction du scroll		*/
 WORD start;		/* position ligne depart	*/
 {
  WORD l,c,bd,ncol;
  BPTR dest;
  BPTR src;
  WPTR atb_dest;
  WPTR atb_src;

  bd = wd->cad;
  ncol = wd->nb_col + (2*bd);
  switch (dir)
     {
    case HAUT:
      for ( l = start ; l < wd->nb_lig ; l++)
       {
	 src = (BPTR) wd->adr_text +  (ncol*(bd+l)) + bd;
	 dest = src - ncol;
	 wmemcpy(dest,src,wd->nb_col);				/* texte */

	 wmemcpy(wd->adr_atb + (ncol*(bd+l-1)) + bd,		/* attributs */
		wd->adr_atb + (ncol*(bd+l)) + bd, 2*wd->nb_col);
       }/* for l */

       /* remplir nouvelle ligne (derniere de la fenetre)*/

       wmemset(wd->adr_text +
		 (ncol*(wd->nb_lig+bd-1)) + bd, 0x20 , wd->nb_col);
       wwmemset(wd->adr_atb +
		 (ncol*(wd->nb_lig+bd-1)) + bd, wd->bas_atb , wd->nb_col);

       break;
    case BAS:
      for ( l = wd->nb_lig ; l > start ; l--)
       {
	 src = wd->adr_text +  (ncol*(bd+l-2)) + bd;
	 dest = src + ncol;
	 wmemcpy(dest,src,wd->nb_col);			/* texte */

	 wmemcpy(wd->adr_atb + (ncol*(bd+l-1)) + bd,	    /* attribut */
		wd->adr_atb + (ncol*(bd+l-2)) + bd, 2*wd->nb_col);

       }
       /* remplir nouvelle ligne */
       wmemset(wd->adr_text + (ncol*(bd+start-1)) + bd , 0x20 , wd->nb_col);
       wwmemset(wd->adr_atb + (ncol*(bd+start-1)) + bd, wd->bas_atb , wd->nb_col);

       break;

    case DROITE:
      for ( l = 0 ; l < wd->nb_lig ; l++)
       {
	 src = wd->adr_text +  (ncol*(bd+l)) + bd;
	 dest = src+1;
	 wimemcpy(dest,src,wd->nb_col-1);		/* move texte */
	 *src = ' ';
	 atb_src =  wd->adr_atb + (ncol*(bd+l)) + bd;
	 atb_dest = atb_src+1;
	 wimemcpy(atb_dest,atb_src,(wd->nb_col-1)*2);		/* move attributs */
	 *atb_src = wd->bas_atb;
/*	 *(wd->adr_atb + (ncol*(bd+l)) + bd) = wd->bas_atb;*/
       }/* for l */
       break;
    case GAUCHE:
      for ( l = 0 ; l < wd->nb_lig ; l++)
       {
	 dest = wd->adr_text +	(ncol*(bd+l)) + bd;
	 src = dest+1;
	 wmemcpy(dest,src,wd->nb_col-1);		/* move texte */
	 *(dest + wd->nb_col-1) = 0x20;
	 atb_src = wd->adr_atb + (ncol*(bd+l)) + bd + 1;
	 atb_dest = atb_src-1;
	 wmemcpy(atb_dest,atb_src,(wd->nb_col-1)*2);	/* move attributs */
/*	 *atb_src = wd->bas_atb;*/
	 *(wd->adr_atb + (ncol*(bd+l))+bd+wd->nb_col-1) = wd->bas_atb;
       }/* for l */
       break;

       }/* switch */
} /* wscroll */
