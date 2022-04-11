/************************************
* Fenetrage - Modifier le cadre fenetres     *
*-----------------------------------*
* Source : WCADRE.C                 *
*-----------------------------------*
* Version : 1.1a                    *
* Creation    le : 29/01/1992  llb  *
* MAJ		   30/04/92	llb corr affichage cadre bas
*		   07.09.92	llb controle si titre > nbcol
*****************************************
* Fonctions                         	*
*                                   	*
* - wcadre 				*
****************************************/

#include "sfundef.h"
#include "bda.h"

/* variables globales */

extern BYTE fen_ini;	/* flag winit */
extern WITEM*  *mapecran;
extern	APP_MV2	*desc_mv2;
extern WITEM	*avp;		/* fenetre en avant plan	*/
extern	WITEM*  WLOG[MAXFUN];
extern	WORD	MAXLIG,MAXCOL;	/* taille ecran */
extern	WORD gplig, gpcol, gnlig, gncol;
extern GLOBAL BDA_ARG rt_arg;
extern stc_desc stc[MAXSTC];


/* fonctions externes */

extern int show_rect();
extern void mv2();
extern void wmemset();
extern void wwmemset();

/* proto */

TYPF wcadrec(WITEM*, BYTE, WORD, BPTR);
TYPF wtitrec(WITEM*, WORD, BPTR);

/*************************************************
*	fonction modifier la cadre d'une fenetre *                           *
*************************************************/

/* fonction prologue */

TYPF wcadre(f, cad_type )	/*[cadatb,cadtxt,cadfon,caduser]*/

WORD	f;  		/* No logique fenetre */
BYTE	cad_type;	/* type de cadre (1, 2 ou 3) */

{

	BYTE	cadatb,cadtxt,cadfon;
	WORD    i,cad_atrib;	/* atb cadre code MV2 */

	BYTE	carcad[8];
	BPTR	cadusr;
	BPTR temp;

	WITEM 	  *wi;

	/* Verification Init */
	if (fen_ini == 0)
		return(werr_ini);

	if ((f > MAXFUN) || (f < 1))
		/* fenetre inexistante */
		return(werr_inex);

	wi=WLOG[f-1];

	if (wi->mere == (WITEM*)NULL)
		/* fenetre inexistante */
		return(werr_inex);


	if(rt_arg.c > 6)
		return(RT_err_arg);

	/* init valeurs par defaut */
	cadusr = ( BPTR) NULL;
	cad_atrib = 0;

	if(rt_arg.c > 2)    
	{
		if(rt_arg.c < 5)		/* si 2, 3 et 4 obligatoires */
              	     return(RT_err_arg);
		if(rt_arg.t[2] == TYPE_DIESE)
			cadatb = GetAbalByte( rt_arg.v[2] );
		else if (rt_arg.t[2] == TYPE_POURCENT)
			cadatb = GetAbalWord( rt_arg.v[2] );
		else if (rt_arg.t[2] == TYPE_DEUXPOINT)
			cadatb = GetAbalLong( rt_arg.v[2] );
		else	return(RT_err_typ);
	}
	if(rt_arg.c > 3)    
	{
		if(rt_arg.t[3] == TYPE_DIESE)
			cadtxt = GetAbalByte( rt_arg.v[3] );
		else if (rt_arg.t[3] == TYPE_POURCENT)
			cadtxt = GetAbalWord( rt_arg.v[3] );
		else if (rt_arg.t[3] == TYPE_DEUXPOINT)
			cadtxt = GetAbalLong( rt_arg.v[3] );
		else	return(RT_err_typ);
	}
	if(rt_arg.c > 4)    
	{
		if(rt_arg.t[4] == TYPE_DIESE)
			cadfon = GetAbalByte( rt_arg.v[4] );
		else if (rt_arg.t[4] == TYPE_POURCENT)
			cadfon = GetAbalWord( rt_arg.v[4] );
		else if (rt_arg.t[4] == TYPE_DEUXPOINT)
			cadfon = GetAbalLong( rt_arg.v[4] );
		else	return(RT_err_typ);
	}
	cad_atrib = (cadfon << 4) + cadtxt ;
	cad_atrib  += cadatb << 8;

	if(rt_arg.c > 5)   
	{
		/* caduser */
		if(rt_arg.t[5] != TYPE_CHAINE)
		    return(RT_err_typ);
		if (rt_arg.l[5] != 8 )  	/* 8 caracteres obligatoires */
			return(werr_desc);
		if ( cad_type == 3) 
		{
			for (i = 0; i < 8 ; i++)
				carcad[i] = ((BPTR)rt_arg.v[5])[i];
			cadusr = carcad;		/* init PTR */
		}
	}

	return( wcadrec( wi,cad_type, cad_atrib,cadusr));

} 

/************************************************
* 	fonction interne cadre  fenetre	(C)
*************************************************/

TYPF wcadrec(wi ,cad_type, cadatb, cadusr)
WITEM*	 	wi;		/* ptr desc fenetre */
BYTE		cad_type;	/* style de cadre ( 1..3)*/
WORD		cadatb;
BPTR		cadusr;
{
	WDESC_PTR	wd;
	WORD		i, nbc;
	BPTR            txt_ptr;
	BPTR            fgc_ptr;
	BPTR            bgc_ptr;
	WPTR		atb_ptr;
	WORD		plig,pcol,nlig,ncol;

	wd = wi->wdesc_ptr;

	if ( cadatb != 0 )
		wd->cad_atb = cadatb;

	if (wd->cad == 0 )		/* on ne change pas le cadre 	*/
		return(werr_desc);	/* d'une fenetre sans cadre !!! */

	plig = wd->pos_lig ;
	pcol = wd->pos_col ;
	nlig = wd->nb_lig ;
	ncol = wd->nb_col ;

#ifdef AIX_VERS
	if  (cad_type <= 1 )	/* cadre simple trait */
#else
	if  (cad_type == 1 )	/* cadre simple trait */
#endif /* AIX_VERS */
		for (i=0 ; i < 8; i++)
			wd->cadre[i] = stc[0].trait[i];
	else if ( cad_type == 2 )	/* cadre Double trait */
		for (i=0 ; i < 8; i++)
			wd->cadre[i] = stc[1].trait[i];

	else for ( i = 0 ; i < 8 ; i++)
      		wd->cadre[i] = cadusr[i];	/* cadre type 3 */

	txt_ptr = wd->adr_text;
	fgc_ptr = wd->adr_fore;
	bgc_ptr = wd->adr_back;
	atb_ptr = wd->adr_atb;

	*(txt_ptr++) = wd->cadre[0];                  /* coin haut gauche */

	if ( wd->ln_tit == 0) 
	{
		wmemset( txt_ptr, wd->cadre[1] , ncol);		/* cadre haut 	*/
		wmemset( fgc_ptr, wd->cad_fg   , ncol+2);	/* cadre haut 	*/
		wmemset( bgc_ptr, wd->cad_bg   , ncol+2);	/* cadre haut 	*/
		wwmemset(atb_ptr, wd->cad_atb  , ncol+2);	/* atributs	*/
 	}
	else 	
	{
		nbc = wd->ln_tit;
		if ( nbc > wd->nb_col )
			nbc = wd->nb_col-1;				/* corr 07.09.92 		      	*/
		nbc = ((wd->nb_col - nbc + 1 )/2); 			/* nbre colonnes avant et apres titre 	*/
		wmemset( txt_ptr, wd->cadre[1] , nbc);			/* cadre avant titre			*/
		wmemset( (txt_ptr+wd->ln_tit+nbc), wd->cadre[1] , nbc);   /* cadre apres titre 			*/
		wmemset(fgc_ptr, wd->cad_fg, nbc+1);
		wmemset(fgc_ptr+wd->ln_tit+nbc+1, wd->cad_fg, nbc+1);
		wmemset(bgc_ptr, wd->cad_bg, nbc+1);
		wmemset(bgc_ptr+wd->ln_tit+nbc+1, wd->cad_bg, nbc+1);
		wwmemset(atb_ptr, wd->cad_atb  , nbc+1);
		wwmemset(atb_ptr+wd->ln_tit+nbc+1, wd->cad_atb  , nbc+1);
	}

	txt_ptr += ncol;
	fgc_ptr += (ncol+2);
	bgc_ptr += (ncol+2);
	atb_ptr += (ncol+2);

	*(txt_ptr++) = wd->cadre[2];			/* coin haut droit  	*/

	for ( i = 0 ; i < nlig ; i++) 
	{
	 	*(txt_ptr) = wd->cadre[7];		/* bord gauche 		*/
	 	txt_ptr += (ncol+1);
	 	*(txt_ptr++) = wd->cadre[3];		/* bord droit  		*/

		*(fgc_ptr) = wd->cad_fg;
	 	fgc_ptr += (ncol+1);
		*(fgc_ptr++) = wd->cad_fg;

		*(bgc_ptr) = wd->cad_bg;
	 	bgc_ptr += (ncol+1);
		*(bgc_ptr++) = wd->cad_fg;

	 	*(atb_ptr) = wd->cad_atb;		/* atb cadre gauche 	*/
	 	atb_ptr += (ncol+1);
	 	*(atb_ptr++) = wd->cad_atb;		/* atb cadre droit 	*/
	}

	wmemset(fgc_ptr , wd->cad_fg, ncol+2 );   	/* attribut cadre bas 	*/
	wmemset(bgc_ptr , wd->cad_bg , ncol+2 );   	/* attribut cadre bas 	*/
	wwmemset(atb_ptr , wd->cad_atb , ncol+2 );   	/* attribut cadre bas 	*/

	*(txt_ptr++) = wd->cadre[6];			/* coin bas gauche 	*/
	wmemset( txt_ptr, wd->cadre[5] , ncol);
	txt_ptr += ncol;
	*(txt_ptr) = wd->cadre[4];			/* coin bas droit  	*/

    	/* afficher le cadre */

    	if (!( wd->control & INVISIBLE )) 
	{
		/* si elle est visible 	*/
       		show_rect( plig-1, pcol-1, 1, ncol+2 );		/* haut   		*/
       		show_rect( plig , pcol+ncol, nlig, 1 );       	/* droit  		*/
       		show_rect( plig+nlig, pcol-1, 1, ncol+2 ); 	/* bas    		*/
		show_rect( plig, pcol-1, nlig, 1 );       	/* gauche 		*/
    	}
 	return(OK);

}

/*************************************************
*	fonction modifier le titre d'une fenetre *
*************************************************/

/* fonction prologue */


TYPF wtitre(f, tit_atb, tit_txt, tit_fon )	/*[titre]*/

WORD	f;  			/* No logique fenetre */
BYTE	tit_atb;		/* atb n&b titre */
BYTE	tit_txt, tit_fon;	/* couleur texte et fonf titre */

{

	BYTE	titre[TAIL_TITRE+1];
	BPTR	tit_ptr;
	WORD    lntit,i, tit_atrib;	/* atb cadre code MV2 */
	WORD	l;
	WITEM 	  *wi;
	BYTE *	tptr;

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


	if (rt_arg.c > 5)
		return(RT_err_arg);

	tit_ptr = (BPTR) NULL;		/* param par defaut */

	tit_atrib   = (tit_fon << 4) + tit_txt ;
	tit_atrib  |= tit_atb << 8;

	if(rt_arg.c > 4)   {		/* titre */

		if(rt_arg.t[4] != TYPE_CHAINE)
		    return(RT_err_typ);
		else if (!(tptr = rt_arg.v[4]))
		    return(RT_err_typ);

		lntit = min(rt_arg.l[4], TAIL_TITRE);
		
		for (i = 0; i < lntit ; i++)
			titre[i] = *(tptr+i);

		for (l=0,i=0; i < lntit; i++ )
			if ( titre[i] != ' ' )
				l = i;
			
		titre[(l+1)] = NULL;	/* EOS*/
		tit_ptr = titre;
		}
    	

	return( wtitrec( wi, tit_atrib, tit_ptr) );

} /*wtitre*/


/************************************************
* 	Modifier le titre (C)
*************************************************/

TYPF wtitrec(wi, titatb, new_titre)
WITEM		*wi;
WORD		titatb;
BPTR		new_titre;

{

	WDESC_PTR	wd;				/* ptr desc fenetre */
	WORD		pcol, ncol,lnt, nbc,start, i;
	BPTR            txt_ptr;
	WPTR		atb_ptr;


	wd = wi->wdesc_ptr;


	/* incrustation du titre dans le cadre */
	/* ----------------------------------- */

	if (wd->cad == 0 )	 	/* pas de titre si pas de cadre */
		return(werr_desc);

	wd->tit_atb = titatb; 	/* nouvel attribut */


	if ( new_titre != (BPTR) NULL ) {
		lnt = 0;
		while ( (*new_titre != NULL ) && ( lnt < TAIL_TITRE ))
			wd->titre[lnt++] = *(new_titre++);
		wd->titre[lnt] = NULL;
		if ( lnt > wd->nb_col)
			lnt = wd->nb_col;
		start  = ((wd->nb_col - lnt)+1)/2;

		if ( lnt < wd->ln_tit ) {	/* nouveau titre plus court */

			nbc = ((wd->nb_col - wd->ln_tit) +1)/2;
			pcol = nbc;
			ncol = wd->ln_tit;			/* reafficher ancien titre */
			for ( i = 0 ; i <= start-nbc ; i++) {
				*(wd->adr_text +nbc +i+1) = wd->cadre[1];    /* cadre avant titre*/
				*(wd->adr_text +nbc +ncol -i) = wd->cadre[1];    /* cadre apres titre*/
				*(wd->adr_atb +nbc +i+1) = wd->cad_atb;
				*(wd->adr_atb +nbc +ncol -i) = wd->cad_atb;
				}
			}
		else 	{	/* nouveau titre plus grand */
			pcol = start;
			ncol = lnt;
			}
		wd->ln_tit = lnt;
		txt_ptr = (wd->adr_text + start + 1);
		atb_ptr = (wd->adr_atb + start + 1);	/* positionner les attributs */
		for ( i = 0 ; i < lnt ; i++) {
			*txt_ptr++ = wd->titre[i];
			*atb_ptr++ = titatb;
			}
    		}/* new_titre != 0 */
	else 	{
		ncol = wd->ln_tit;			/* set longueur atb */
		pcol  = (((wd->nb_col - ncol) +1)/2);        /* set debut atb */
		atb_ptr = (wd->adr_atb + pcol + 1);	/* positionner les attributs */
		for ( i=0; i < ncol; i++ )
			*atb_ptr++ = titatb;
    		}
		
	/* afficher le titre */
	/*-------------------*/
	if ( !(wd->control & INVISIBLE))
		show_rect( (wd->pos_lig-1) ,(wd->pos_col+pcol), 1, ncol );

	repos_cur(wi);
	return(OK);

}/*wcadrec*/



/* fin de fichier */

