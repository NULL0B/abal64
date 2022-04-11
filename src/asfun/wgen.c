#ifndef	_wgen_c
#define	_wgen_c

/************************************************************************
* Fenetrage - fcts generales affich 					*
*-----------------------------------------------------------------------*
* Source : wgen.c							*
*-----------------------------------------------------------------------*
* Version : 1.1a		    					*
* Creation    le : 15/03/1989  llb  					*
* Mise a jour le : 15/06/1990	sb  					*
*		   11/07/90    llb  corr ins_lig() et cleol()           *
*		   12.12.90    llb  wgetimpl()                          *
*                  12.08.91    llb  ARPCURS dans wposcur et showcue	*	                                                     *
*		   01.07.93    llb  corr pb winsncar sur F sans cadre   *
*		   03.09.93    LLB  WIMPL(): CURSEUR ON si F ARPCURS	*
*		   28.07.94    llb  correction winscar			*
*************************************************************************
* Fonctions			    					*
*				    					*
* - poscur	positionnement curs 					*
* - wfgen	fct generiques aff  					*
* - watb	posit attributs cour					*
* - wimpl	fenetre implicite   					*
* - wsetatb	set attributs zone  					*
************************************************************************/
#include "fundef.h"
#include <string.h>

/*
*
* 	macros de portabilite
*	---------------------
*/

#ifdef unix
#define GETWORD(val,x) { memcpy((BYTE *)&val , (BYTE *)x, sizeof(WORD));}
#define GETDWORD(val,x) { memcpy((BYTE *)&val , (BYTE *)x, sizeof(DWORD));}
#define PUTWORD(x,val) { memcpy((BYTE *)x , (BYTE *)&val, sizeof(WORD));}
#define PUTDWORD(x,val) { memcpy((BYTE *)x , (BYTE *)&val, sizeof(DWORD));}
#endif

static	WORD	useextended=0;
static	BPTR	extended[256];
static	BPTR	media[256];

/* variables globales */

extern	WORD	PRLMF;
extern	BYTE	fen_ini;
extern	APP_MV2 *desc_mv2;
extern	WITEM*	WLOG[MAXFUN];
extern	WITEM	*avp;
extern	WORD	fimpl;		/* fenetre implicite */

extern WORD gplig, gpcol, gnlig , gncol;

extern WORD win_coltxt, win_colfon, ecr_atb;
extern BYTE topvis;

/* fonctions externes */

TYPF wwrite();
extern int show_rect();
extern int get_cord();
extern int wscroll();
extern void mv2();

/* definitions : */

void wcleof();
void wcleol();
void wins_lig();
void wsup_lig();
void vert_scroll();
void wclbol();
void wsupncar();
void winsncar();

/*****************************************************************
*	WSETATB(F,ATB_VID,COL_TXT,COL_FOND,PLIG,PCOL,NLIG,NCOL)
******************************************************************/

TYPF wsetatb(f,atb_vid,col_txt,col_fon,plig,pcol,nlig,ncol)
WORD	f;
WORD	plig,pcol,nlig,ncol;
BYTE	atb_vid,col_txt,col_fon;
{
	WITEM		*wi;
	WDESC_PTR 	wd;
	WPTR		adr_atb;
	WORD		attrib,bd,l;

	if (fen_ini == 0)		/* test winit() */
       		return(werr_ini);

    	if ((f > MAXFUN) || (f < 1))
        	return(werr_inex); 	/* fenetre inexistante */
    	wi=WLOG[f-1];
    	if (wi->mere == (WITEM*)NULL)
        	return(werr_inex); 	/* fenetre inexistante */

    	wd = wi->wdesc_ptr;

    	if (( (plig+nlig-1) > wd->nb_lig) 
	||  ( (pcol+ncol-1) > wd->nb_col) 
	||  ( plig == 0 ) 
	||  ( pcol == 0 ) )
       		return(werr_desc);

    	bd = wd->cad;
    	attrib = ((col_fon << 4) + col_txt) ;
    	attrib += (atb_vid << 8);

    	adr_atb = wd->adr_atb + ( (wd->nb_col+(2*bd))*(plig-1+bd) ) + pcol-1 + bd;

    	for (l = 0 ; l < nlig ; l++ )  
	{
		wwmemset(adr_atb, attrib , ncol);
		adr_atb += (wd->nb_col + (2*bd));
    	}


    	if ( !( wd->control & INVISIBLE ) &&(wd->gel == 0)) 
	{
        	if ((PRLMF) && ( ((wi==avp) && (topvis==0)) ) ) 
		{
	    		desc_mv2->nfonc   = SETATB ;
	    		desc_mv2->inc_buf = 2 ;
	    		desc_mv2->mvlig   = plig + wd->pos_lig -1;
	    		desc_mv2->mvcol   = pcol + wd->pos_col -1;
	    		desc_mv2->mvnblig = nlig ;
	    		desc_mv2->mvnbcol = ncol ;
	    		desc_mv2->adr_text = (BPTR) &attrib;
	    		desc_mv2->adr_atb = (WPTR)NULL;
	    		mv2(desc_mv2);
		}
		else if ( (topvis==0) )
	    		show_rect(wd->pos_lig+plig-1, wd->pos_col+pcol-1, nlig, ncol);

		/* repositionner le curseur */
		if ((wd->cur==1) && ( ((wi==avp)&&(topvis==0)) || (wd->control&TOP)))
		{
	    		desc_mv2->nfonc = POSCUR;
	    		desc_mv2->mvlig = wd->pos_lig + wd->cur_lig -1;
	    		desc_mv2->mvcol = wd->pos_col + wd->cur_col -1;
	    		mv2(desc_mv2);
		}
    	}

    	return(OK);
}

/************************************************
*	WPOSCUR(F,Ligne,Colonne)		*
************************************************/

TYPF wposcur(f,lig,col)
WORD	f ,lig, col;
{
	WITEM	*wi;
	WDESC_PTR wd;

	if (fen_ini == 0)		/* test winit() */
		return(werr_ini);

   	if ((f > MAXFUN) || (f < 1))
     		return(werr_inex); 	/* fenetre inexistante */
   	wi=WLOG[f-1];
   	if (wi->mere == (WITEM*)NULL)
     		return(werr_inex); 	/* fenetre inexistante */

  	wd = wi->wdesc_ptr;
  	if (( lig > wd->nb_lig) 
	|| ( col > wd->nb_col) 
	|| ( lig == 0 ) 
	|| ( col == 0 ))
     		return(werr_desc);

  	wd->cur_lig = lig;
  	wd->cur_col = col;

  	if ((wd->cur==1)
	&& ((((wi==avp) ||(wd->control&ARPCURS)) && (topvis==0)) || (wd->control&TOP)) 
	&& (wd->gel ==0)
	&& !(wd->control&INVISIBLE)) 
    	{
		/*ENVOYER LA COMMANDE PHYSIQUE*/
     		desc_mv2->nfonc = POSCUR;
     		desc_mv2->mvlig = lig + wd->pos_lig -1;
     		desc_mv2->mvcol = col + wd->pos_col -1;
     		mv2(desc_mv2);
    	}
  	return(OK);
} 

/****************************************
*		WFGEN			*
****************************************/

TYPF wfgen(f,code)
WORD	f,code;
{
	WITEM		*wi;
	WDESC_PTR 	wd;
	char 		seq_clf[1];	/* sequence clear fenetre */
	BYTE 		aphys;		/* flag affichage physique */


	seq_clf[0] = 0x0c;

  	if (fen_ini == 0)		/* test winit() */
      		return(werr_ini);

   	if ((f > MAXFUN) || (f < 1))
     		return(werr_inex); 	/* fenetre inexistante */
   	wi=WLOG[f-1];
   	if (wi->mere == (WITEM*)NULL)
     		return(werr_inex); 	/* fenetre inexistante */

  	wd = wi->wdesc_ptr;		/* descripteur fenetre */

  	if ((wd->gel != 0) 
	|| ( wd->control & INVISIBLE) 
	|| ((topvis != 0) 
	&& (!(wd->control&TOP))) )
    		aphys = FALSE;
  	else 	aphys = TRUE;

	switch (code)
   	{
    	/* clear fenetre */
    	case CLFUN:  
		wwrite(f,1,(BPTR) seq_clf);
		break;

    	/* clear fin fenetre */
    	case CLEOF:
		wcleof(wi,aphys) ;
		break;

    	/* clear fin ligne	*/
    	case CLEOL:
		 wcleol(wi,aphys) ;
		 break;

    	/* Insertion ligne	*/
    	case INS_LIG:  
		wscroll(wd,BAS,wd->cur_lig) ; /* scroll buffer */
		if (aphys == TRUE)
			vert_scroll(wi,BAS,wd->cur_lig);
		break;

    	/* Supression  ligne  */
	case SUP_LIG:  
		wscroll(wd,HAUT,wd->cur_lig) ;/* scroll buffer */
		if (aphys == TRUE)
			vert_scroll(wi,HAUT,wd->cur_lig);
		break;

    	/* eteindre curseur */
    	case CUROF:  
		wd->cur = 0;
		if (((wi == avp)||(wd->control&ARPCURS))&&(aphys == TRUE))
		{
			desc_mv2->nfonc = HIDECUR;
		    	mv2(desc_mv2);
		}
		break;

	/* allumer curseur */
	case CURON:  
		wd->cur = 1;
		if (((wi == avp)||(wd->control&ARPCURS))&&(aphys == TRUE))
		{
			desc_mv2->nfonc = SHOWCUR;
		    	mv2(desc_mv2);
		    	repos_cur(wi);
		}
		break;

	/* scroll up */
	case SCROL_UP:
		wscroll(wd,HAUT,1);
		if (aphys == TRUE)
			vert_scroll(wi,HAUT,1);
		break;

	/* scroll down */
    	case SCROL_DW:
		wscroll(wd,BAS,1);
		if (aphys == TRUE)
			vert_scroll(wi,BAS,1);
		break;

	/* scroll droite */
    	case SCROL_DR:
		wscroll(wd,DROITE,1);
		if (aphys == TRUE)
		{
			if (wi == avp)
		      		show_rect(wd->pos_lig,wd->pos_col,wd->nb_lig,wd->nb_col);
		     	else
			{
			 	min_data(wi);
			 	show_rect(gplig,gpcol,gnlig,gncol);
			}
		}
		break;

    	/* scroll gauche */
	case SCROL_GA:
		wscroll(wd,GAUCHE,1);
		if (aphys == TRUE)
		{
			if (wi == avp)
		      		show_rect(wd->pos_lig,wd->pos_col,wd->nb_lig,wd->nb_col);
		     	else
			{
			 	min_data(wi);
			 	show_rect(gplig,gpcol,gnlig,gncol);
			}
		}
		break;

	/* suppression caractere */
	case SUP_CAR:  
		wsupncar(wi,aphys,1,1);
		break;

	/* insertion caractere */
	case INS_CAR:  
		winsncar(wi,aphys,1,1);
		break;

	/* clear fin ligne	*/
	case CLBOL:
		wclbol(wi,aphys) ;
		break;
   	}
   	return(OK);
}

BPTR	_rgb_colour(WORD i)
{
	return( extended[i] );
}

BPTR	_get_media(WORD i)
{
	return( media[i] );
}

/****************************************
*		WIMG			*
****************************************/
TYPF wimg(f,image)
WORD	f;
BPTR	image;
{
	WITEM	*wi;
	WDESC_PTR wd;
	WORD	item=0;

	if (fen_ini == 0)		/* test winit() */
		return(werr_ini);

	if ((f > MAXFUN) || (f < 1))
		return(werr_inex); 	/* fenetre inexistante */

	wi=WLOG[f-1];

	if (wi->mere == (WITEM*)NULL)
		return(werr_inex); 	/* fenetre inexistante */

	wd = wi->wdesc_ptr;		/* descripteur fenetre */

	// initialise the table of extended colours
	if (!( useextended ))
	{
		for ( item=0; item < 255; item++ ) media[item] = extended[item] = (BPTR) 0;
		useextended = 1;
	}

	// scan the table of images
	for (	item=0;
		item < 255;
		item++ )
	{
		if (!( media[ item  ] ))
			break;
		else if (!( strcmp( media[ item ], image ) ))
			break;
		else	continue;
	}

	// handle an image
	if ( item < 255 ) 
	{
		// its a new image
		if (!( media[item] ))
		{
			media[item] = allouer( strlen( image) + 1 );
			strcpy( media[item], image);
		}
		item++;
		*(wd->adr_media + ((wd->cur_lig+wd->cad-1) * (wd->nb_col * (wd->cad*2))) + (wd->cur_col+wd->cad-1)) = item;
	}
	else 	item = 0;

	// put image code in map
	// if ( item ) wimage(f,item);

	return(OK);
}


/****************************************
*		WETD			*
****************************************/
TYPF wetd(f,type,colour)
WORD	f;
WORD	type;
BPTR	colour;
{
	WITEM	*wi;
	WDESC_PTR wd;
	WORD	item=0;

	if (fen_ini == 0)		/* test winit() */
		return(werr_ini);

	if ((f > MAXFUN) || (f < 1))
		return(werr_inex); 	/* fenetre inexistante */

	wi=WLOG[f-1];

	if (wi->mere == (WITEM*)NULL)
		return(werr_inex); 	/* fenetre inexistante */

	wd = wi->wdesc_ptr;		/* descripteur fenetre */

	// initialise the table of extended colours
	if (!( useextended ))
	{
		for ( item=0; item < 255; item++ ) media[item] = extended[item] = (BPTR) 0;
		useextended = 1;
	}

	// scan the table of extended colours
	for (	item=0;
		item < 255;
		item++ )
	{
		if (!( extended[ item  ] ))
			break;
		else if (!( strcmp( extended[ item ], colour ) ))
			break;
		else	continue;
	}

	// handle an extended colour
	if ( item < 255 ) 
	{
		// its a new colour
		if (!( extended[item] ))
		{
			extended[item] = allouer( strlen( colour ) + 1 );
			strcpy( extended[item], colour );
		}
		item++;
	}
	else 	item = 0;

	// use the extended colour 
	switch ( type )
	{
	case	0 :	
		/* ste background */
		wd->cur_bg = item;
		break;
	case	1 :
		wd->cur_fg = item;
		break;
	}
	return(OK);
}

/****************************************
*		WATB			*
****************************************/

TYPF watb(f,video,col_text,col_fond)
WORD	f;
BYTE	video,col_text,col_fond;
{
	WITEM	*wi;
	WDESC_PTR wd;

	if (fen_ini == 0)		/* test winit() */
		return(werr_ini);

	if ((f > MAXFUN) || (f < 1))
		return(werr_inex); 	/* fenetre inexistante */

	wi=WLOG[f-1];

	if (wi->mere == (WITEM*)NULL)
		return(werr_inex); 	/* fenetre inexistante */

	wd = wi->wdesc_ptr;		/* descripteur fenetre */

	wd->cur_fg = wd->cur_bg = 0;	/* cancel extended RGB */
	wd->cur_atb =  ((col_fond << 4) + col_text);
	wd->cur_atb += (video << 8);
	return(OK);
}

/**********************************************
*	WIMPL()  positionnement fenetre implicite
***********************************************/

TYPF wimpl(f)
WORD	f;
{
WITEM *wi;
WDESC_PTR wd;

	if (fen_ini == 0)		/* test winit() */
      		return(werr_ini);

	if ( f != NULL)
     	{
       		if (f > MAXFUN)

	   		return(werr_inex);		/* fenetre inexistante */
       		wi=WLOG[f-1];

		if (wi->mere == (WITEM*)NULL)
			 return(werr_inex);		/* fenetre inexistante */

       		wd = wi->wdesc_ptr;		/* descripteur fenetre */

		// TODO HANDLE RGB

		win_coltxt = wd->bas_atb&0x0f;
		win_colfon = wd->bas_atb>>4;	

  		if ((wd->control&ARPCURS)&& (wd->cur==1)&& (topvis==0)) 
		{
        		desc_mv2->nfonc = POSCUR;
        		desc_mv2->mvlig = wd->pos_lig + wd->cur_lig-1;
        		desc_mv2->mvcol = wd->pos_col + wd->cur_col-1;
        		mv2(desc_mv2);
        		desc_mv2->nfonc = SHOWCUR;
			mv2(desc_mv2);
		}

		if ( wd->cur == 0) 
		{
        		desc_mv2->nfonc = HIDECUR;
			mv2(desc_mv2);
		}
    	}
    	else 
	{
		// TODO HANDLE RGB

		win_coltxt = ecr_atb&0x0f;
		win_colfon = ecr_atb>>4;	
    	}

  	fimpl = f;			/* set fenetre implicite */
  	return(OK);

}

/*****************************************************
*	WGEL()	blocage de l'affichage d'une fenetre
******************************************************/

TYPF wgel(WORD f)
{
	WITEM	*wi;
	WDESC_PTR wd;

	if (fen_ini == 0)		/* test winit() */
		return(werr_ini);

	if ((f > MAXFUN) || (f < 1))
		return(werr_inex); 	/* fenetre inexistante */

	wi=WLOG[f-1];

	if (wi->mere == (WITEM*)NULL)
		return(werr_inex); 	/* fenetre inexistante */

	wd = wi->wdesc_ptr;		/* descripteur fenetre */

	wd->gel = 1;			/* set flag GEL */
	return(OK);
}

/*****************************************************
*	WCLEOF()  Effacement fin de fenetre
******************************************************/

void wcleof(wi,aphys)
WITEM *wi;
BYTE aphys;
{
	BPTR		adr_txt;
	BPTR		adr_fgc;
	BPTR		adr_bgc;
	BPTR		adr_med;
	WPTR 		adr_atb;
	WORD 		plig, bd ;
	WDESC_PTR 	wd;
	BPTR 		buf_fill;

	wd = wi->wdesc_ptr;		/* descripteur fenetre */
	bd = wd->cad;

	adr_txt = wd->adr_text + wd->cur_col - 1 + bd +
		   ((wd->nb_col+(2*bd))*(wd->cur_lig-1+bd));
	adr_med = wd->adr_media + wd->cur_col - 1 + bd +
		   ((wd->nb_col+(2*bd))*(wd->cur_lig-1+bd));
	adr_fgc = wd->adr_fore + wd->cur_col - 1 + bd +
		   ((wd->nb_col+(2*bd))*(wd->cur_lig-1+bd));
	adr_bgc = wd->adr_back + wd->cur_col - 1 + bd +
		   ((wd->nb_col+(2*bd))*(wd->cur_lig-1+bd));
	adr_atb = wd->adr_atb + wd->cur_col - 1 + bd +
		   ((wd->nb_col+(2*bd))*(wd->cur_lig-1+bd));

	/* clear fin ligne courante */
	wmemset(adr_txt, 0x20, wd->nb_col-wd->cur_col+1);
	wmemset(adr_med, 0, wd->nb_col-wd->cur_col+1);
      	wmemset(adr_fgc, wd->bas_fg, wd->nb_col-wd->cur_col+1);
      	wmemset(adr_bgc, wd->bas_bg, wd->nb_col-wd->cur_col+1);
      	wwmemset(adr_atb, wd->bas_atb , wd->nb_col-wd->cur_col+1);

	if ( wd->cur_lig != wd->nb_lig)
   	{
     		adr_txt += wd->nb_col - wd->cur_col +1 + (2*bd) ;
     		adr_med += wd->nb_col - wd->cur_col +1 + (2*bd) ;
     		adr_fgc += wd->nb_col - wd->cur_col +1 + (2*bd) ;
     		adr_bgc += wd->nb_col - wd->cur_col +1 + (2*bd) ;
     		adr_atb += wd->nb_col - wd->cur_col +1 + (2*bd) ;

     		for ( plig = wd->cur_lig +1 ; plig <= wd->nb_lig ; plig++)
      		{
       			wmemset(adr_txt , 0x20 , wd->nb_col);
       			wmemset(adr_med , 0 , wd->nb_col);
       			wmemset(adr_fgc , wd->bas_fg, wd->nb_col);
       			wmemset(adr_bgc , wd->bas_bg, wd->nb_col);
       			wwmemset(adr_atb , wd->bas_atb ,wd->nb_col);
       			adr_txt += wd->nb_col + (2*bd);
       			adr_med += wd->nb_col + (2*bd);
       			adr_fgc += wd->nb_col + (2*bd);
       			adr_bgc += wd->nb_col + (2*bd);
       			adr_atb += wd->nb_col + (2*bd);
      		}
   	}

	/* calcul partie a afficher */

	if (aphys == TRUE)
	{
     		if ((wi == avp) || (wd->control & TOP))
		{
	   		buf_fill = desc_mv2->std_text;
	   		*buf_fill++ = ' ' ;             /* caractere remplissage new ligne */
#ifdef unix
	  		PUTWORD(buf_fill,wd->cur_atb);
#else
	   		*((WPTR)buf_fill) = wd->cur_atb; /* atb remplissage new ligne */
#endif
	   		buf_fill--;

	   		desc_mv2->nfonc   = FILL ;		/* REMPLIR FIN LIGNE */
	   		desc_mv2->adr_text = buf_fill;
	   		desc_mv2->inc_buf = 3 ;
	   		desc_mv2->mvlig   = wd->pos_lig + wd->cur_lig -1;
	   		desc_mv2->mvcol   = wd->pos_col + wd->cur_col -1;
	   		desc_mv2->mvnblig = 1 ;
	   		desc_mv2->mvnbcol = wd->nb_col - wd->cur_col +1 ;
	   		mv2(desc_mv2);

	   		if ( wd->cur_lig <= wd->nb_lig)	/* REMPLIR FIN FENETRE */
	   		{
				desc_mv2->mvlig   = wd->pos_lig + wd->cur_lig ;
				desc_mv2->mvcol   = wd->pos_col ;
				desc_mv2->mvnblig = wd->nb_lig - wd->cur_lig ;
				desc_mv2->mvnbcol = wd->nb_col ;
				mv2(desc_mv2);
	      		}
	  	}
		else
       		{
	    		min_data(wi);		/* coord data visible fenetre */
	    		plig = wd->pos_lig + wd->cur_lig -1 ;
	    		if ( plig > gplig )
	      		{
	       			gnlig -= (plig-gplig);
	       			gplig = plig;
	      		}
	   		show_rect(gplig, gpcol, gnlig, gncol);
	  	}
	}
}

/*****************************************************
*	WCLEOL()  Effacement fin de ligne
******************************************************/

void wcleol(wi,aphys)
WITEM	*wi;
BYTE 	aphys;
{
	BPTR		adr_txt;
	BPTR		adr_med;
	BPTR		adr_fgc;
	BPTR		adr_bgc;
	WPTR 		adr_atb;
	WORD 		plig ,pcol, bd;
	WDESC_PTR 	wd;
	BPTR 		buf_fill;

	wd = wi->wdesc_ptr;		/* descripteur fenetre */

 	if ( wd->cur_col != wd->nb_col)
    	{
      		bd = wd->cad;

      		adr_txt = wd->adr_text + wd->cur_col - 1 + bd +
	  	        ((wd->nb_col+(2*bd))*(wd->cur_lig-1+bd));
      		adr_med = wd->adr_media + wd->cur_col - 1 + bd +
	  	        ((wd->nb_col+(2*bd))*(wd->cur_lig-1+bd));
      		adr_fgc = wd->adr_fore + wd->cur_col - 1 + bd +
	  	        ((wd->nb_col+(2*bd))*(wd->cur_lig-1+bd));
      		adr_bgc = wd->adr_back + wd->cur_col - 1 + bd +
	  	        ((wd->nb_col+(2*bd))*(wd->cur_lig-1+bd));
      		adr_atb = wd->adr_atb + wd->cur_col - 1 + bd +
	       		((wd->nb_col+(2*bd))*(wd->cur_lig-1+bd));

      		wmemset(adr_txt , 0x20 , wd->nb_col - wd->cur_col+1);
      		wmemset(adr_med , 0 , wd->nb_col - wd->cur_col+1);
      		wmemset(adr_fgc , wd->bas_fg, wd->nb_col - wd->cur_col+1);
      		wmemset(adr_bgc , wd->bas_bg, wd->nb_col - wd->cur_col+1);
      		wwmemset(adr_atb , wd->bas_atb , wd->nb_col - wd->cur_col+1);

		/* calcul partie a afficher */

      		if (aphys == TRUE)
		{
	 		/* F en AVP : appel Gescons */
			if ((wi == avp) || ( wd->control & TOP) ) 
	   		{
				buf_fill = (BPTR)desc_mv2->std_text;
				*buf_fill++ = ' ' ;                     /* caractere remplissage fin ligne */

#ifdef unix
				PUTWORD(buf_fill,wd->bas_atb);
#else
				*((WPTR) buf_fill) = wd->bas_atb;	/* atb remplissage fin ligne */
#endif
				buf_fill--;

				desc_mv2->nfonc   = FILL ;		/* REMPLIR FIN LIGNE */
				desc_mv2->adr_atb = NULL ;
				desc_mv2->adr_text = buf_fill;
				desc_mv2->inc_buf = 3 ;
				desc_mv2->mvlig   = wd->pos_lig + wd->cur_lig -1;
				desc_mv2->mvcol   = wd->pos_col + wd->cur_col -1;
				desc_mv2->mvnblig = 1 ;
				desc_mv2->mvnbcol = wd->nb_col - wd->cur_col+1;
				mv2(desc_mv2);
	   		}
			else
	   		{
				min_data(wi);
				plig = wd->pos_lig + wd->cur_lig -1;
				pcol = wd->pos_col + wd->cur_col -1;
				gplig = max ( gplig, plig );
				gpcol = max ( gpcol, pcol );
				gnlig = 1 ;
				gncol = min( gncol , wd->nb_col - wd->cur_col + 1);
				show_rect(gplig, gpcol, gnlig, gncol);
	   		} 
		}
	}
}

/*****************************************************
*	WSUPNCAR()  Suppression ncar caracteres
*			   sur	nlg lignes
******************************************************/

void wsupncar(wi,aphys,ncar,nlg)
WITEM *wi;
BYTE aphys;
WORD ncar, nlg;

{
	BPTR adr_txt;
	BPTR adr_med;
	BPTR adr_fgc;
	BPTR adr_bgc;
	WPTR adr_atb;

	WORD bd ,nsup, i ;
	WORD plig, pcol, nlig, ncol;
	WORD cold, depl;
	WORD ilig, icol, lgf;
	WDESC_PTR wd;
	BPTR buf_fill;

	if ( nlg == 0 )  /*llb 08.04.92 cas del_car sur 1er caract fenetre */
		return;

	wd = wi->wdesc_ptr;		/* descripteur fenetre */

	plig = wd->cur_lig;
	pcol = wd->cur_col;
	nlig = wd->nb_lig;
	ncol = wd->nb_col;
	bd = wd->cad;

	lgf = plig+nlg-1;
	if (lgf > nlig) lgf = nlig;

	nsup = (ncar > ncol)? ncol:ncar;	/* limite a une ligne */

 	if (nsup)
   	{
      		adr_txt = wd->adr_text + pcol - 1 + bd +
		       ((ncol+ 2*bd )*(plig-1+bd));
      		adr_med = wd->adr_media + pcol - 1 + bd +
		       ((ncol+ 2*bd )*(plig-1+bd));
      		adr_fgc = wd->adr_fore + pcol - 1 + bd +
		       ((ncol+ 2*bd )*(plig-1+bd));
      		adr_bgc = wd->adr_back + pcol - 1 + bd +
		       ((ncol+ 2*bd )*(plig-1+bd));
      		adr_atb = wd->adr_atb + pcol - 1 + bd +
		       ((ncol+ 2*bd )*(plig-1+bd));

      		/* deplacement du nombre de caracteres a inserer */

		for (ilig = plig; ilig <= lgf ; ++ilig)
	   	{
			cold = (ilig == plig)? pcol:1;
			depl = nsup;
			for (icol = cold ; icol <= ncol ; /*icol++*/)
		  	{
				if (icol++ > ncol-nsup) depl = nsup+bd+bd;
				*(adr_txt) = *(adr_txt+depl);
				*(adr_med) = *(adr_med+depl);
				*(adr_fgc) = *(adr_fgc+depl);
				*(adr_bgc) = *(adr_bgc+depl);
				*(adr_atb) = *(adr_atb+depl);
				adr_txt++;
				adr_atb++;
		  	}
			if (ilig < lgf)
		  	{
				adr_txt +=bd+bd;
				adr_med +=bd+bd;
				adr_fgc +=bd+bd;
				adr_bgc +=bd+bd;
				adr_atb +=bd+bd;
		  	}
	   	}
      		adr_txt--;
      		adr_fgc--;
      		adr_bgc--;
      		adr_atb--;

		/* insertion des blancs */
      		for (icol=ncol-nsup+1 ; icol<=ncol ;++icol)
	 	{
	  		*(adr_txt++) = ' ';
	  		*(adr_med++) = 0;
	  		*(adr_fgc++) = wd->bas_fg;
	  		*(adr_bgc++) = wd->bas_bg;
	  		*(adr_atb++) = wd->bas_atb;
	 	}

		/* calcul partie a afficher */

      		if (aphys == TRUE)
	 	{
	  		min_data(wi);
	  		gplig = wd->pos_lig + wd->cur_lig -1;
	  		gpcol = wd->pos_col + wd->cur_col -1;

	  		gnlig = 1 ;
	  		gncol = wd->nb_col - wd->cur_col + 1;

	  		show_rect(gplig, gpcol, gnlig, gncol);

	  		if (lgf > plig)
	    		{
				gplig = wd->pos_lig + plig;
				gpcol = wd->pos_col;
				gnlig = lgf-plig;
				gncol = ncol;
				show_rect(gplig, gpcol, gnlig, gncol);
	     		};

	 		if ((wd->cur==1)
			&&  (wi==avp)
			&&  (wd->gel ==0)
			&& (!(wd->control&INVISIBLE))) 
		 	{
				/*ENVOYER LA COMMANDE PHYSIQUE */
		     		desc_mv2->nfonc = POSCUR;
		     		desc_mv2->mvlig = plig + wd->pos_lig -1;
		     		desc_mv2->mvcol = pcol + wd->pos_col -1;
		     		mv2(desc_mv2);
		 	}
	 	}

   	}
}

/*****************************************************
*	WINSNCAR() Insertion ncar blancs sur nlg lignes
******************************************************/

void winsncar(wi,aphys,ncar,nlg)
WITEM *wi;
BYTE aphys;
WORD ncar, nlg;

{

	BPTR adr_txt;
	BPTR adr_med;
	BPTR adr_fgc;
	BPTR adr_bgc;
	WPTR adr_atb;
	WORD bd;		/* nombre de caracteres cadre */
	WORD nins;		/* nombre de caracteres inseres */
	WORD nbf;		/* nombre de blancs fin de ligne */
	WORD icol,ilig;
	WORD depl;		/* nombre de caracteres a deplacer */
	WORD cold;		/* colonne debut */
	WORD lgf;		/* ligne fin d'insertion */
	WORD plig,pcol;		/* sauvegarde position insertion */
	WORD nlig,ncol;		/* sauvegarde coordonnees fenetre */
	WDESC_PTR wd;

	wd = wi->wdesc_ptr;	/* descripteur fenetre */
	bd = wd->cad;

	plig = wd->cur_lig;	/* sauvegarde position curseur */
	pcol = wd->cur_col;
	nlig = wd->nb_lig;
	ncol = wd->nb_col;

	lgf = plig+nlg-1;
	if (lgf > nlig) lgf = nlig;

	adr_txt = wd->adr_text - bd + ((ncol+ bd + bd) * (lgf+bd));
	adr_med = wd->adr_media - bd + ((ncol+ bd + bd) * (lgf+bd));

	/* nombre de blancs fin */
 	nbf = 0;			
 	while ((*(--adr_txt) == ' ')&&(nbf < ncol)) 
		++nbf;

	nins = ncar;

	if ( nins )
    	{
      		adr_fgc = wd->adr_fore - bd +
	       		((ncol+bd+bd)*(lgf+bd));
      		adr_bgc = wd->adr_back - bd +
	       		((ncol+bd+bd)*(lgf+bd));
      		adr_atb = wd->adr_atb - bd +
	       		((ncol+bd+bd)*(lgf+bd));
      		adr_txt += nins;
      		adr_med += nins;
      		adr_atb += nins;
      		adr_fgc += nins;
      		adr_bgc += nins;

      		/* deplacement du nombre de caracteres a inserer */

		for (ilig = lgf; ilig>=plig ; --ilig)
	   	{
			cold = (ilig == plig)? pcol+nins:1;
			depl = nins;
			for (icol = ncol-nbf+nins ; icol >= cold ; )
		  	{
				if (--icol < nins) depl = nins+bd+bd;
				*(adr_txt) = *(adr_txt-depl);
				*(adr_med) = *(adr_med-depl);
				*(adr_fgc) = *(adr_fgc-depl);
				*(adr_bgc) = *(adr_bgc-depl);
				*(adr_atb) = *(adr_atb-depl);
				adr_txt--;
				adr_med--;
				adr_fgc--;
				adr_bgc--;
				adr_atb--;

		  	}
			if (ilig > plig)
		  	{
				adr_txt -=bd+bd;
				adr_med -=bd+bd;
				adr_fgc -=bd+bd;
				adr_bgc -=bd+bd;
				adr_atb -=bd+bd;
				nbf = nins;
		  	}
	   	}

		/* insertion des blancs */

      		for (icol=nins;icol>0;--icol,adr_txt--,adr_atb--,adr_fgc--,adr_bgc--)
	 	{
	       		*(adr_txt) = ' ';
	       		*(adr_med) = 0;
	       		*(adr_fgc) = *(adr_fgc-icol-1);
	       		*(adr_bgc) = *(adr_bgc-icol-1);
	       		*(adr_atb) = *(adr_atb-icol-1);
	 	}

		/* calcul partie a afficher */

      		if (aphys == TRUE)
	 	{
	  		min_data(wi);
	  		gplig = wd->pos_lig + plig -1;
	  		gpcol = wd->pos_col + pcol -1;
	  		gnlig = 1 ;
	  		gncol = ncol - pcol + 1;
	  		show_rect(gplig, gpcol, gnlig, gncol);

	  		if (lgf > plig)
	    		{
				gplig = wd->pos_lig + plig;
				gpcol = wd->pos_col;
				gnlig = lgf-plig;
				gncol = ncol;
				show_rect(gplig, gpcol, gnlig, gncol);
	     		}

			/* repositionnement du curseur */

	    		if ((wd->cur==1)
			&&  (wi==avp)
			&&  (wd->gel ==0)
			&& (!(wd->control&INVISIBLE))) 
		 	{
				/*ENVOYER LA COMMANDE PHYSIQUE */
		     		desc_mv2->nfonc = POSCUR;
		     		desc_mv2->mvlig = plig + wd->pos_lig -1;
		     		desc_mv2->mvcol = pcol + wd->pos_col -1;
		     		mv2(desc_mv2);
		 	}
	 	} 
	}
} 

/*****************************************************
*	WCLBOL()  Effacement debut de ligne
******************************************************/

void wclbol(wi,aphys)
WITEM *wi;
BYTE aphys;
{
	BPTR adr_txt;
	BPTR adr_med;
	BPTR adr_fgc;
	BPTR adr_bgc;
	WPTR adr_atb;
	WORD bd;
	WDESC_PTR wd;
	BPTR buf_fill;

	wd = wi->wdesc_ptr;		/* descripteur fenetre */

	if ( wd->cur_col > 1)
    	{
      		bd = wd->cad;

      		adr_txt = wd->adr_text  + bd +
		       ((wd->nb_col+(2*bd))*(wd->cur_lig-1+bd));
      		adr_med = wd->adr_media  + bd +
		       ((wd->nb_col+(2*bd))*(wd->cur_lig-1+bd));
      		adr_fgc = wd->adr_fore  + bd +
		       ((wd->nb_col+(2*bd))*(wd->cur_lig-1+bd));
      		adr_bgc = wd->adr_back  + bd +
		       ((wd->nb_col+(2*bd))*(wd->cur_lig-1+bd));
      		adr_atb = wd->adr_atb   + bd +
	       		((wd->nb_col+(2*bd))*(wd->cur_lig-1+bd));

      		wmemset(adr_txt , 0x20 , wd->cur_col);
      		wmemset(adr_med , 0 , wd->cur_col);
      		wmemset(adr_fgc , wd->bas_fg , wd->cur_col);
      		wmemset(adr_bgc , wd->bas_bg , wd->cur_col);
      		wwmemset(adr_atb , wd->bas_atb , wd->cur_col);

		/* calcul partie a afficher */

      		if (aphys == TRUE)
		{
			if ((wi == avp) && (PRLMF== TRUE))
	   		{
				buf_fill = (BPTR) desc_mv2->std_text;
				*buf_fill = ' ' ;                     /* caractere remplissage fin ligne */
				buf_fill++;
#ifdef unix
				PUTWORD(buf_fill,wd->bas_atb);
#else
				*((WPTR) buf_fill) = wd->bas_atb;	/* atb remplissage fin ligne */
#endif
				buf_fill--;

				desc_mv2->nfonc   = FILL ;		/* REMPLIR FIN LIGNE */
				desc_mv2->adr_atb = NULL ;
				desc_mv2->adr_text = buf_fill;
				desc_mv2->inc_buf = 3 ;
				desc_mv2->mvlig   = wd->pos_lig + wd->cur_lig -1;
				desc_mv2->mvcol   = wd->pos_col ;
				desc_mv2->mvnblig = 1 ;
				desc_mv2->mvnbcol = wd->cur_col;
				mv2(desc_mv2);
	   		}
       			else
			{
	  			min_data(wi);
	  			gplig = wd->pos_lig + wd->cur_lig -1;
	  			gpcol = wd->pos_col ;
	  			gnlig = 1 ;
	  			gncol = min( gncol , wd->cur_col);
	  			show_rect(gplig, gpcol, gnlig, gncol);
	 		} 
		}
	}
}

/*****************************************************
*	VERT_SCROLL()
******************************************************/
/* scroll vertical d'une ligne a partir de la position ligne precisee.
   => INS / DEL ligne , scroll HAUT /BAS */


void vert_scroll(wi,dir,dlig)
WITEM *wi;
WORD	dir, dlig;
{
	WDESC_PTR wd;
	WORD	 plig,bd;
	WPTR	 buf_scrol;
	BPTR	 buf_fill;

	/* calcul partie a afficher */

	wd = wi->wdesc_ptr;		/* descripteur fenetre */

 	if (!(wd->control & INVISIBLE)&&(wd->gel==0))
  	{
   		if (( wi != avp) || ( !PRLMF))
      		{
			bd = wd->cad;
			min_data(wi);
			plig = wd->pos_lig + dlig -1;
			if ( plig > gplig )
	   		{
	     			gnlig -= (plig-gplig);
	     			gplig = plig;
	   		}
			show_rect(gplig, gpcol, gnlig, gncol);
      		}
    		else 
      		{
#ifdef unix
			WORD tmp;
#endif	
			buf_scrol = (WPTR) desc_mv2->std_text;
			buf_fill  = (BPTR) buf_scrol;
#ifdef unix
			tmp=1;
			PUTWORD(buf_scrol,tmp);
			PUTWORD(buf_scrol+1,dir);
#else
			*buf_scrol     = 1;			/* 1 ligne a scroller */
			*(buf_scrol+1) = dir ;			/* scroll bas ou haut */
#endif
			desc_mv2->nfonc   = GSCROLL ;
			desc_mv2->adr_text = (BPTR) buf_scrol ;
			desc_mv2->inc_buf = 4 ;
			desc_mv2->mvcol   = wd->pos_col;
			desc_mv2->mvnbcol = wd->nb_col;
			if ( dir == HAUT )
	  		{
	   			desc_mv2->mvlig = wd->pos_lig + dlig ;
	   			desc_mv2->mvnblig = wd->nb_lig - dlig ;
	  		}
			if ( dir == BAS )
	  		{
	   			desc_mv2->mvlig = wd->pos_lig + dlig -1 ;
	   			desc_mv2->mvnblig = wd->nb_lig - dlig ;
	  		}
			mv2(desc_mv2);

			*buf_fill++ = ' ' ;			/* caractere remplissage new ligne */
#ifdef unix
			PUTWORD(buf_fill,wd->cur_atb);
#else
			*((WPTR)buf_fill) = wd->cur_atb;	/* atb remplissage new ligne */
#endif
			buf_fill--;

			desc_mv2->nfonc   = FILL ;		/* REMPLIR DERNIERE LIGNE */
			desc_mv2->adr_text = buf_fill;
			desc_mv2->inc_buf = 3 ;

			desc_mv2->mvlig   = 
				(dir == BAS)
				? (wd->pos_lig + dlig -1)	/* Position ligne suivant direction */
				: (wd->pos_lig + wd->nb_lig-1);

			desc_mv2->mvcol   = wd->pos_col;
			desc_mv2->mvnblig = 1 ;
			desc_mv2->mvnbcol = wd->nb_col;
			mv2(desc_mv2);

      		}
		/* positionner curseur sur colonne 1 */

   		wd->cur_col = 1;
   		desc_mv2->nfonc = POSCUR;
   		desc_mv2->mvlig = wd->pos_lig + dlig -1;
   		desc_mv2->mvcol = wd->pos_col ;
   		mv2(desc_mv2);

 	} 
}


/**********************************************
*	WGETIMPL()  lecture numero fenetre implicite
***********************************************/

TYPF wgetimpl(f)
WPTR  f;
{
WORD f1;

	if (fen_ini == 0)
		return(werr_ini);
#ifdef IDIRECT
#ifndef OSF1
	*f = Invint(fimpl);	
#else
	f1 = Invint(fimpl);
	memcpy(f,&f1,sizeof(WORD));
#endif
#else
	*f = fimpl;
#endif
	return(OK);
}

#endif /* wgen_c */

