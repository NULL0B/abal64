#ifndef	_wwrite_c
#define	_wwrite_c
/************************************
* Fenetrage - Ecriture en fenetre   *
*-----------------------------------*
* Source : WWRITE.C                 *
*-----------------------------------*
* Version : 1.1b                    *
* Creation    le : 07/03/1989  llb  *
* Mise a jour le : 15/06/1990   sb  *
*  		   20/04/93    llb
		   caract Ò
*************************************
* Fonctions                         *
*                                   *
* - wwrite     ecriture en fenetre  *
* -                                 *
* -                                 *
* -                                 *
*************************************/

#include "fundef.h"

/* variables globales */

extern	WORD	PRLMF;
extern  BYTE	 fen_ini;
extern  WITEM*   *mapecran;
extern	APP_MV2	 *desc_mv2;
extern  WITEM	 *avp;		/* fenetre en avant plan	*/
extern	WITEM*   WLOG[MAXFUN];
extern	WORD gplig;		/* position ligne   	*/
extern	WORD gpcol;		/* position colonne 	*/
extern	WORD gnlig;		/* nombre lignes 	*/
extern	WORD gncol;		/* nombre colonnes 	*/
extern BYTE topvis;

/* fonctions externes */

extern int show_rect();
extern void mv2();
extern void wscroll();
extern void bell();

TYPF wwritec( f, mes)
WORD f;
BPTR mes;
{
	int ln;
	BPTR mes_tamp;

	mes_tamp = mes;
	ln = 0 ;
	while ( *mes_tamp++ != NULL )
		ln++;
	return( wwrite( f , ln ,mes) );
}

TYPF	wwrite(f,ln,mes)
WORD	f;              /* No fenetre     */
short int ln; 		/* taille message */
BPTR    mes;		/* mwessage       */
{
	WITEM	*wi;
	WDESC_PTR wd;
	WORD	tg,td,th,tb,tecr,bd,rlig,rcol,full;
	BPTR   text_ptr;
	BPTR   media_ptr;
	BPTR   fore_ptr;
	BPTR   back_ptr;
	WPTR   atb_ptr;
	BYTE   curcar;

	if (fen_ini == 0)
	return(werr_ini);		/* test winit() */

 	if ((f > MAXFUN) || (f < 1))
     		return(werr_inex);	/* fenetre inexistante */
 	wi=WLOG[f-1];
   	if (wi->mere == (WITEM*)NULL)
     		return(werr_inex);	/* fenetre inexistante */

 	if (ln < 1) 
		return(werr_desc);

	tecr = 0;                      	/* flag ecriture physique 		*/
	full = 0;			/* flag ecriture fenetre complete	*/
	wd = wi->wdesc_ptr;
	gplig = wd->cur_lig;            /* Attention: pos fenetre = pos ecran 	*/
	gpcol = wd->cur_col;
	gnlig = wd->nb_lig;
	gncol = wd->nb_col;
	th = tb = gplig;		/* Trace Haut = Trace Bas = ligne courante */
	tg = td = gpcol;		/* Trace Gauche=Trace Droit = col courante */
	bd = wd->cad;			/* indicateur cadre 			   */


	while (ln != NULL)
   	{
     		if ( (BYTE) *mes >= 0x20 )
		{

			/* caractere dans buffer fenetre */
	 		tecr |= 1;
			/* Trace ecriture reelle */
	 		curcar = *mes++;
#ifdef PRL
	 		if ( (PRLMF) && (curcar == 0xd2))
	     			curcar = 0x15;
#endif
	 		*( wd->adr_text + ((gncol+(2*bd))*(bd+gplig-1)) + (gpcol+bd-1) ) = curcar;
	 		*( wd->adr_fore + ((gncol+(2*bd))*(bd+gplig-1)) + (gpcol+bd-1) ) = wd->cur_fg;
	 		*( wd->adr_back + ((gncol+(2*bd))*(bd+gplig-1)) + (gpcol+bd-1) ) = wd->cur_bg;
	 		*( wd->adr_atb + ((gncol+(2*bd))*(bd+gplig-1)) + (gpcol+bd-1) ) = wd->cur_atb;
	 		ln--;

	 		if ( gpcol == gncol)	/* trt fin de ligne */
	    		{
	     			gpcol = 1;
	     			if ( gplig == gnlig)   	/* trt derniere ligne */
				{
					if ( wd->control & SCROLL ) /* si mode scroll */
		   			{
		    				wscroll(wd,HAUT,1);
		    				full |= 1;		/* afficher fenetre entiere */
		   			}
					else
		   				gplig = 1 ;		/* trt mode page */
				}
	     			else
	       				gplig++;			/* debut ligne suivante */
	    		}
	 		else
	    			gpcol++;			/* colonne + 1 */

		}
     		else 
		{
	 	switch (*mes)
	   	{
	    		/* curseur bas */
	    		case 5 :
	    		case 0xA:
		    		if (gplig == gnlig)
				{
		       			if ( wd->control & SCROLL ) /* si mode scroll */
			  		{
			   			wscroll(wd,HAUT,1);
			   			full |= 1;	/* afficher fenetre entiere */
			  		}
		       			else
			  			gplig = 1 ;		/* trt mode page */
				}
		    		else
					gplig ++;
			      break;

	    		/* curseur droit */
	    		case 6 :
		    		if ( gpcol == wd->nb_col)
		       		{
					gpcol = 1;
					if ( gplig == wd->nb_lig)
					{
			   			if ( wd->control & SCROLL ) /* si mode scroll */
			     			{
			      				wscroll(wd,HAUT,1);
			      				full |= 1;   	/* afficher fenetre entiere */
			     			}
			   			else
			     				gplig = 1 ;		/* trt mode page */
					}
					else
			   			gplig++;	/* passer ligne suivante */
		       		}
		    		else
					gpcol++;
		    		break;

	    		/* bell */
	    		case 7 : 
				bell();
		      		break;

	    		/* back space */
	    		case 8 : 
				if (gpcol == 1)
				{
		       			if (gplig == 1)
					{
			  			if ( wd->control & SCROLL ) /* si mode scroll */
			    			{
			     				wscroll(wd,BAS,1);
			     				full |= 1;	/* afficher fenetre entiere */
			    			}
			   			else /* mode page */
			    			{
			     				gpcol = gncol;
			     				gplig = gnlig;
			    			}
					}
		       			else  /* pas ligne 1 */
			  		{
			   			gpcol = wd->nb_col;
			   			gplig--;
			  		}
				}
		     		else  /* pas colonne 1 */
					gpcol--;
		     		break;

	     		/* TAB */
	     		case 9 : 
				gpcol = (((gpcol+LTAB)/LTAB)*LTAB)+1 ;
		      		if ( gpcol > gncol )
			 	{
			   		gpcol = 1;
			   		if ( gplig == gnlig )
					{
			      			if ( wd->control & SCROLL ) /* si mode scroll */
						{
							wscroll(wd,HAUT,1);
				 			full |= 1;	/* afficher fenetre entiere */
						}
			      			else
							gplig = 1 ;		/* trt mode page */
					}
			   		else
			      			gplig++;
			  	}
		       		break;

	     		/* curseur haut */
	     		case 0x0B:	
				if ( gplig == 1 )
				{
			  		if ( wd->control & SCROLL ) /* si mode scroll */
			    		{
			     			wscroll(wd,BAS,1);
			     			full |= 1; 		/* afficher fenetre entiere */
			    		}
			  		else
			    			gplig = gnlig;		/* mode page */
				}
				else
			   		gplig--;
				break;

	     		/* RC */
	     		case 0x0D: 
				gpcol = 1;
				break;

	     		/* HOME */
	     		case 0x1C: 
				gpcol = gplig = 1;
				break;
	     		/* CLEAR */
	     		case 0x0C:
				wd->cur_atb = wd->bas_atb;

				/* RAZ contenu fenetre */
				tecr |= 1;		/* Trace ecriture reelle */

				text_ptr = wd->adr_text+((wd->nb_col+(2*bd))*bd)+bd ;
				media_ptr = wd->adr_media+((wd->nb_col+(2*bd))*bd)+bd ;
				fore_ptr = wd->adr_fore+((wd->nb_col+(2*bd))*bd)+bd ;
				back_ptr = wd->adr_back+((wd->nb_col+(2*bd))*bd)+bd ;
				atb_ptr = wd->adr_atb + ((wd->nb_col+(2*bd))*bd)+bd ;
				for ( gplig = 1 ; gplig <= gnlig ; gplig++)
			   	{
			    		wmemset(text_ptr,0x20, wd->nb_col);
			    		wmemset(media_ptr,0, wd->nb_col);
			    		wmemset(fore_ptr,wd->cur_fg, wd->nb_col);
			    		wmemset(back_ptr,wd->cur_bg, wd->nb_col);
			    		wwmemset(atb_ptr,wd->cur_atb, wd->nb_col);
 			    		media_ptr += wd->nb_col + (2*bd);	
 			    		text_ptr += wd->nb_col + (2*bd);	
 			    		fore_ptr += wd->nb_col + (2*bd);	
 			    		back_ptr += wd->nb_col + (2*bd);	
			    		atb_ptr += wd->nb_col + (2*bd);	
			   	}
				gplig = gpcol = 1; /* position curseur */
				full |= 1;	/* afficher fenetre entiere */
				break;

	   		}
	   		mes++;
	   		ln--;
		} 

   		/* calcul position dernier caractere (gplig-1,gpcol-1) */

   		if ( full == 0)
     		{
      			if (gpcol ==1)
	 		{
	  			rcol = gncol;
	  			rlig = ((gplig == 1) ? gnlig : gplig-1);
	 		}
       			else
	 		{
	  			rcol = gpcol-1;
	  			rlig = gplig;
	 		}
       			tg = min(tg,rcol);		/* Trace Gauche */
       			td = max(td,rcol);		/* Trace Droite */
       			th = min(th,rlig);		/* Trace Haut   */
       			tb = max(tb,rlig);		/* Trace Bas	*/
   		}
 	}

 	wd->cur_lig = gplig;		/* MAJ curseur fenetre */
 	wd->cur_col = gpcol;

 	if (!(wd->control & INVISIBLE)&&(wd->gel==0))
   	{
    		if ( (tecr != 0) || (full != 0) )	/* ecriture reelle */
      		{
			if ( full == 0 )
	   		{
	    			tb = tb - th +1;		/* nbre de lignes a ecrire */
	    			td = td - tg +1;		/* nbre de colonnes a ecrire */
	    			th +=wd->pos_lig -1;       /* ligne debut		*/
	    			tg +=wd->pos_col -1;	/* colonne debut */
	   		}
			else   /* fenetre complete */
	   		{
	    			th = wd->pos_lig;
	    			tg = wd->pos_col;
	    			tb = gnlig;
	    			td = gncol;
	  		}

			if ( ( wi != avp ) && (!(wd->control&TOP)) )
	 		{
           			min_data(wi);	/* rect mini a l'ecran */
				/* test intersection existe */

	   			if ( (gplig > (th+tb)) 
				||   (gpcol > (tg+td)) 
				||  ((gplig+gnlig) <= th)  
				|| ((gpcol+gncol) <= tg) )
	   				return(OK); 
	 		}
			else 
          		{
	    			gplig = wd->pos_lig;
	    			gpcol = wd->pos_col;
	    			gnlig = wd->nb_lig;
	    			gncol = wd->nb_col;	
	  		}

			gnlig = (min( tb , gnlig) );
			gncol = (min( td , gncol) );
			gplig = max( th , gplig);
			gpcol = max( tg , gpcol);

			if ((topvis==0) &&( wi != avp ))
                		show_rect( gplig,gpcol,gnlig,gncol );
        
			if ( ((topvis==0)&&(wi==avp)) || (wd->control&TOP)) 
			{
	        		bd = wd->cad;
     	        		desc_mv2->nfonc = AFFICHE ;
                		desc_mv2->adr_atb = wd->adr_atb + 
					((wd->nb_col+(2*bd))*(gplig-(wd->pos_lig-bd))) +
					(gpcol - (wd->pos_col-bd)) ;
 
 	        		desc_mv2->adr_text = wd->adr_text +
					((wd->nb_col+(2*bd))*(gplig-(wd->pos_lig-bd))) +
					(gpcol - (wd->pos_col-bd)) ;

 	        		desc_mv2->adr_media = wd->adr_media +
					((wd->nb_col+(2*bd))*(gplig-(wd->pos_lig-bd))) +
					(gpcol - (wd->pos_col-bd)) ;

 	        		desc_mv2->adr_fore = wd->adr_fore +
					((wd->nb_col+(2*bd))*(gplig-(wd->pos_lig-bd))) +
					(gpcol - (wd->pos_col-bd)) ;

 	        		desc_mv2->adr_back = wd->adr_back +
					((wd->nb_col+(2*bd))*(gplig-(wd->pos_lig-bd))) +
					(gpcol - (wd->pos_col-bd)) ;

	        		desc_mv2->inc_buf = wd->nb_col + (2*bd);
   	        		desc_mv2->mvlig = gplig ;
     	        		desc_mv2->mvcol = gpcol ;
     	        		desc_mv2->mvnblig = gnlig ;
     	        		desc_mv2->mvnbcol = gncol ;
				/* positionner curseur ecran */
                		mv2(desc_mv2);	
			}
      		}

    		if ( ((wd->cur != 0)&&((wi==avp)||(wd->control&ARPCURS))&&(topvis==0)) || (wd->control&TOP) )  
		{
        		desc_mv2->nfonc = POSCUR;
        		desc_mv2->mvlig = wd->pos_lig + wd->cur_lig-1;
        		desc_mv2->mvcol = wd->pos_col + wd->cur_col-1;
        		mv2(desc_mv2);
    		}

	} 

 	return(OK);
} 

#endif /* _wwrite_c */
