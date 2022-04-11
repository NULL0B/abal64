/************************************
* Fenetrage - visualisation fenetres*
*-----------------------------------*
* Source : WVIS.C                   *
*-----------------------------------*
* Version : 1.1b                    *
* Creation    le : 09/03/1989  llb  *
* Mise a jour le : 15/06/1990   sb  *
*		   04.07.90    llb : Pb curseur WVIS/WINV du 30.04.90 non pris en compte
*		   06.11.90    llb : Fenetre TOP
* version 1.2c
*		   18.12.91    llb : degel fenetre de wselect ne reaffiche pas la fenetre
* version 1.3a
*		   08.01.1992  llb : ombrage fenetres
*                  03.02.92    llb : repos_cur
*************************************
* Fonctions                         *
*                                   *
* - wvis      visualisation fenetre *
* - winv      fenetre invisible     *
* - wselect   fenetre avant-plan    *
*************************************/

#include "fundef.h"

/* variables globales */

extern  BYTE     fen_ini;
extern  WITEM*   *mapecran;
extern	APP_MV2	 *desc_mv2;

extern  WITEM	 *avp;		/* fenetre en avant plan	*/

extern	WITEM*   WLOG[MAXFUN];

extern	WORD	MAXCOL,MAXLIG;

extern	WORD    fimpl;
extern	WORD    sav_impl;


extern	WORD gplig, gpcol, gnlig, gncol;

extern 	BYTE topvis;

/* fonctions externes */

extern int show_rect();
extern int min_rect();
extern mv2();

void repos_cur();

/****************************************
* 	fonction WINV()			*
****************************************/

TYPF winv(f)
 WORD	f;
{
 WDESC_PTR wd;
 WITEM	*wi,*wc,*wt;
 WORD	l,c,bd;
 WORD	lh,lb,cg,cd;
 WORD	trouve;

 if (fen_ini == 0)   			/* test winit() */
    return(werr_ini);

 if ((f > MAXFUN) || (f < 1))
     return(werr_inex);		/* fenetre inexistante */

 
wi=WLOG[f-1];
 if (wi->mere == (WITEM*)NULL)
     return(werr_inex);		/* fenetre inexistante */

 wd = wi->wdesc_ptr;

 if ((wd->control & INVISIBLE))
    return(NULL);		/* fenetre invisible */
 wd->control |= INVISIBLE;	/* set flag invisible */
 wd->gel = 0;			/* degel fenetre */


 /* traitement fenetre TOP */


 if (wd->control & TOP) {
     	show_rect(1,1,MAXLIG,MAXCOL);
	topvis = 0;

/* llb	17/12/93
	fimpl = sav_impl;
   llb fin **/
	repos_cur(wi);
	return(OK);
 }/*top*/

 if ( wd->control & OMBRE)
	reset_ombre(wi);

 if ( wi != avp )
     min_rect(wi);		/* retour = rectangle physique de travail */
 else
     get_cord(wi);		/* fenetre complete */

 for ( l =gplig ; l < gplig+gnlig ; l++)
   for ( c = gpcol; c < gpcol+gncol ; c++ )

   {
    wc = *(mapecran + (MAXCOL*(l-1)) + (c-1));
    if ( wc == wi )

   /* ici, recherche fenetre sous WI */
      {
       trouve = NULL;
       while ( (wc->fsous != (WITEM*)NULL) && ( trouve == NULL))
	  {
	   wc = wc->fsous;
	   wd = wc->wdesc_ptr;
	   if (!( wd->control & INVISIBLE))
	     {
	      bd = wd->cad;
	  /* test intersection */
	      if (  ((wd->pos_lig -bd) <= l) &&
		    ((wd->pos_lig + wd->nb_lig + bd) > l) &&
		    ((wd->pos_col -bd) <= c) &&
		    ((wd->pos_col + wd->nb_col + bd) > c) )
		 {
		  *(mapecran + (MAXCOL*(l-1)) + (c-1)) = wc;
		  trouve = 1;
		 }
	      }/* F visible */
	   } /* while */
	if ( trouve == NULL ) /* rien sous la fenetre */
	   *(mapecran + (MAXCOL*(l-1)) + (c-1)) = NULL;
       } /*if ( wc == wi )*/
  } /* for */

  if ( topvis == 0) {
      show_rect(gplig,gpcol,gnlig,gncol) ;	/* afficher " sous F " */

      /* repositionner les ombres eventuellement effacees */
      /*==================================================*/
      if ( avp != (WITEM*)NULL)
	{
	  wt = avp;
	  while ( wt != (WITEM*) NULL )
	    {
	       wd = wt->wdesc_ptr;
	       if (( wd->control & OMBRE)&&(!(wd->control & INVISIBLE)))
		 {
		    /* test intersection ombre et fenetre rectangle reaffiche */

		    bd = wd->cad;

		    lh = wd->pos_lig - bd ;	 	/* position ligne haut */
		    lb = wd->pos_lig+wd->nb_lig+bd+1;     /* position ligne ombre bas */

		    cg = wd->pos_col - bd ;		/* position colonne gauche */
		    cd = wd->pos_col+wd->nb_col+bd;     /* position colonne ombre vertic */

		    if ( (gplig > lb) || (gplig+gnlig < lh) || (gpcol > cd) || (gpcol+gncol < cg))
			;
		    else
			set_ombre(wt);
		 }
		 wt = wt->fsous;
	  }/*while*/

      }/*avp != 0*/


      /* traitement du curseur */
      /* ======================*/
      repos_cur(wi);

  }/*topvis*/

  return(OK);
 } /* winv */

/****************************************
*	fonction WVIS()			*
****************************************/

TYPF wvis(f)
WORD	f;
{
WDESC_PTR wd;
WITEM	*wi,*wc,*wt;
WORD  l,c,bd;


    if (fen_ini == 0)   			/* test winit() */
        return(werr_ini);

    if ((f > MAXFUN) || (f < 1))
        return(werr_inex);		/* fenetre inexistante */
 
 
    wi=WLOG[f-1];
    if (wi->mere == (WITEM*)NULL)
        return(werr_inex);		/* fenetre inexistante */

    wd = wi->wdesc_ptr;
 
    if ((!(wd->control & INVISIBLE))&&(wd->gel==0))
        return(OK);		/* fenetre deja visible */

    wd->control &= VISIBLE;	/* reset flag invisible */
    wd->gel = 0;			/* degel fenetre */


/* traitement fenetre TOP */

    if ( wd->control & TOP) {
        bd = wd->cad;
        desc_mv2->nfonc = AFFICHE ;
        desc_mv2->adr_text = wd->adr_text ;
        desc_mv2->adr_media = wd->adr_media ;
        desc_mv2->adr_fore = wd->adr_fore ;
        desc_mv2->adr_back = wd->adr_back ;
        desc_mv2->adr_atb = wd->adr_atb ;
        desc_mv2->inc_buf = wd->nb_col + 2*bd;

        desc_mv2->mvlig = wd->pos_lig - bd;
        desc_mv2->mvcol = wd->pos_col -bd;
        desc_mv2->mvnblig = wd->nb_lig + (2*bd);
        desc_mv2->mvnbcol = wd->nb_col + (2*bd) ;
        mv2(desc_mv2);
        if (wd->cur == 0)
            desc_mv2->nfonc = HIDECUR;
        else  {
            desc_mv2->nfonc = POSCUR;
	    desc_mv2->mvlig = wd->pos_lig + wd->cur_lig-1;
	    desc_mv2->mvcol = wd->pos_col + wd->cur_col-1;
	    mv2(desc_mv2);			/* positionner curseur ecran */
	    desc_mv2->nfonc = SHOWCUR;
	}
        mv2(desc_mv2);
/** llb 17/12/93 
	sav_impl = fimpl;
	fimpl = f;
**/
	topvis = 1;
	return(OK);
    }/*TOP*/


    get_cord(wi);			/* coord physiques fenetre */

    for ( l =gplig ; l < gplig+gnlig ; l++)
	for ( c = gpcol; c < gpcol+gncol ; c++ )
	{
		wc = *(mapecran + (MAXCOL*(l-1)) + (c-1));
		wt = avp;
		while (( wt != wc) && ( wt != wi))
			wt = wt->fsous;
		if ( wt == wi )
			*(mapecran + (MAXCOL*(l-1)) + (c-1)) = wi;
	} /* for l */

/* calcul rectangle mini a afficher */

    if ( topvis == 0)  {
 	if ( wi != avp )  {
        	min_rect(wi);			/* rect mini a l'ecran */
		show_rect(gplig,gpcol,gnlig,gncol) ;	/* afficher */
        }
        else  {	 /* afficher fenetre entiere */
	    bd = wd->cad;
	    desc_mv2->nfonc = AFFICHE ;
	    desc_mv2->adr_text = wd->adr_text ;
	    desc_mv2->adr_media = wd->adr_media ;
	    desc_mv2->adr_fore = wd->adr_fore ;
	    desc_mv2->adr_back = wd->adr_back ;
	    desc_mv2->adr_atb = wd->adr_atb ;
	    desc_mv2->inc_buf = wd->nb_col + 2*bd;

	    desc_mv2->mvlig = wd->pos_lig - bd;
	    desc_mv2->mvcol = wd->pos_col -bd;
	    desc_mv2->mvnblig = wd->nb_lig + (2*bd);
	    desc_mv2->mvnbcol = wd->nb_col + (2*bd) ;
	    mv2(desc_mv2);			/* positionner curseur ecran */

	}

	for ( wt = wi ; wt != avp ; wt = wt->fsur )
	    if ((wt->wdesc_ptr->control & OMBRE )&&(!(wt->wdesc_ptr->control & INVISIBLE)))
		set_ombre(wt);

	if ((avp->wdesc_ptr->control & OMBRE)&&(!(avp->wdesc_ptr->control & INVISIBLE)))
		set_ombre(avp);

	repos_cur(wi);



    }/*topvis*/


    return(OK);
}/* wvis */


/************************************************
*	fonction SELECTION d'une fenetre 	*
************************************************/

TYPF wselect(f)
WORD f;
{
  WITEM	*wi,*wsur,*wsous;
  WDESC_PTR wd;
  WORD	l,c,lh,lb,cg,cd,t,bd;
  WORD  omb;

  if (fen_ini == 0)   			/* test winit() */
    return(werr_ini);

  if ((f > MAXFUN) || (f < 1))
     return(werr_inex);		/* fenetre inexistante */
  wi=WLOG[f-1];
  if (wi->mere == (WITEM*)NULL)
     return(werr_inex);		/* fenetre inexistante */

/* reset flag GEL */
   wd = wi->wdesc_ptr;

  if ( wi == avp)
     if (wd->gel == 0)
         return(OK);		/* fenetre deja en avant plan */
     else
     {	 
       wvis(f);
       return(OK);
     }

/* noter si fenetres "sur" sont ombrees" */
   omb = FALSE;
   wsur = avp;
   while ( wsur != wi )  {
	if ( wsur->wdesc_ptr->control & OMBRE ) {
		omb = TRUE;
		break;
	}
	wsur = wsur->fsous;
   }



/* MAJ chainage */
  if ( wd->gel != 0)    	/* version 1.2c corr dit 1628 */
	 wvis(f);

  wsur  = wi->fsur;
  wsous = wi->fsous;
  if ( wsur !=(WITEM*)NULL )
     wsur->fsous = wsous;
  if (wsous != (WITEM*)NULL )
    wsous->fsur = wsur;
  wi->fsur = (WITEM*)NULL;
  avp->fsur = wi;
  wi->fsous = avp;
  avp = wi;

/* Retour si fenetre invisible */

 if (wd->control & INVISIBLE)
    return(OK);		/* fenetre invisible */

/* calcul rectangle mini a afficher */

  get_cord(wi);

/* calcul ligne haute */

lh = 0;
t  = 0;
     for ( l = gplig ; l < (gplig+gnlig) ; l++)
       {
	for ( c = gpcol ; c < (gpcol+gncol) ; c++)
	  if( (*(mapecran+(MAXCOL*(l-1))+c-1)) != wi)
	    {
	     t++;
	     break;
	    }
	if ( t == 0)
	   lh++;
	else
	   break;
       }/*for l= */

if (t != 0) 

{

/* calcul ligne basse */

lb = 0;
t = 0;
    for ( l = (gplig+gnlig-1) ; l >= gplig ; l--)
       {
	for ( c = gpcol ; c < (gpcol+gncol) ; c++)
          if( (*(mapecran+(MAXCOL*(l-1))+c-1)) != wi)
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
	  if( (*(mapecran+(MAXCOL*(l-1))+c-1)) != wi)
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
	  if( (*(mapecran+(MAXCOL*(l-1))+c-1)) != wi)
	   {
	    t++;
	    break;
	   }
	if ( t == 0)
	   cd++;
	else
	   break;
       }/*for*/



/* MAJ MAPECRAN */


  for ( l=gplig ; l < gplig+gnlig ; l++)
    for (c=gpcol; c < gpcol+gncol; c++)
       *(mapecran + (MAXCOL*(l -1)) + (c -1)) = wi;
} /* t!=0 */

 /* afficher fenetre */

if ( topvis == 0) {

    if (  t != 0) {
	if ( cd == gncol )
	    cd  = 0;
        if ( lb == gnlig )
   	    lb = 0;
	lb = gnlig - lb - lh;
	cd = gncol - cd - cg;
	lh += gplig;
	cg += gpcol;

     /* elargir le rectangle a afficher si les fenetres "sur" sont ombrees"   */
	if (omb)
	  {
	    if ( (lh+lb) < (gplig+gnlig) ) lb++;
	    if ( lh > gplig )
		{ lh--; lb++; }
	    if ( (cg+cd) < (gpcol+gncol) ) cd++;
	    if ( cg > gpcol )
	 	{ cg--; cd++; }
 	  }
    }/*t!=0*/
    else	/* on affiche quand meme la fenetre complete car elle   */
		/* peut etre ombree et t=0				*/
	if (omb) 
	{
	     lh = gplig; cg = gpcol;
	     lb = gnlig; cd = gncol;
	     t++;	
        }/* omb && t==0 */
if ( t != 0 )
{
     bd = wd->cad;
     desc_mv2->nfonc = AFFICHE ;
     desc_mv2->adr_atb = wd->adr_atb +
			((wd->nb_col+(2*bd))*(lh-(wd->pos_lig-bd))) +
			(cg - (wd->pos_col-bd)) ;

     desc_mv2->adr_text = wd->adr_text +
			((wd->nb_col+(2*bd))*(lh-(wd->pos_lig-bd))) +
			(cg - (wd->pos_col-bd)) ;

     desc_mv2->adr_media = wd->adr_media +
			((wd->nb_col+(2*bd))*(lh-(wd->pos_lig-bd))) +
			(cg - (wd->pos_col-bd)) ;

     desc_mv2->adr_fore = wd->adr_fore +
			((wd->nb_col+(2*bd))*(lh-(wd->pos_lig-bd))) +
			(cg - (wd->pos_col-bd)) ;

     desc_mv2->adr_back = wd->adr_back +
			((wd->nb_col+(2*bd))*(lh-(wd->pos_lig-bd))) +
			(cg - (wd->pos_col-bd)) ;

     desc_mv2->inc_buf = wd->nb_col + (2*bd);

     desc_mv2->mvlig = lh ;
     desc_mv2->mvcol = cg ;
     desc_mv2->mvnblig = lb ;
     desc_mv2->mvnbcol = cd ;
     mv2(desc_mv2);			/* positionner curseur ecran */
   }
    }/*topvis*/

  if (wd->control & OMBRE )
	set_ombre(wi);

 if (topvis == 0 )
	repos_cur(wi);

 return(OK);
}/*wselect*/

/************************************************
*	fonction REPOS_CUR		 	*
************************************************/

void repos_cur(wi)
WITEM	*wi;
{
  WDESC_PTR wd;

	wd = wi->wdesc_ptr;

	if ( wi == avp )  {
	   	if ((wd->cur == 0)||(wd->control & INVISIBLE))
        		desc_mv2->nfonc = HIDECUR;
	   	else  	{
        		desc_mv2->nfonc = POSCUR;

			desc_mv2->mvlig = wd->pos_lig + wd->cur_lig-1;
			desc_mv2->mvcol = wd->pos_col + wd->cur_col-1;

			mv2(desc_mv2);			/* positionner curseur ecran */
			desc_mv2->nfonc = SHOWCUR;
	   		}
	   	mv2(desc_mv2);
		}	/*avp*/
	else	{
		/* repositionner curseur sur F en AVP */
	    	if (avp != (WITEM*)NULL)  {
	        	wd = avp->wdesc_ptr;
     			if (( wd->cur != 0 ) && (!(wd->control & INVISIBLE)))  {
	            		desc_mv2->ncons = 0;
		            	desc_mv2->nfonc = POSCUR;
		            	desc_mv2->mvlig = wd->pos_lig + wd->cur_lig - 1 ;
	       		    	desc_mv2->mvcol = wd->pos_col + wd->cur_col - 1 ;
       		    		mv2(desc_mv2);		/* positionner curseur ecran */
         	    		desc_mv2->nfonc = SHOWCUR;
         	    		mv2(desc_mv2);		/* set curseur */
       				}
	    		} /* AVP <> 0*/
		}

	return;

}/*repos_cur*/

/* fin de fichier */


