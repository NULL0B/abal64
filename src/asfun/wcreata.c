#ifdef TSCO
#include <stdio.h>
#endif
/************************************
* Fenetrage - Creation fenetres     *
*-----------------------------------*
* Source : WCREAT.C                 *
*-----------------------------------*
* Version : 1.1a                    *
* Creation    le : 01/03/1989  llb  *
* Mise a jour le : 15/06/1990   sb  *
*		   05/11/1990  llb Fenetre "TOP"
*		   15/02/1991      WCREATC test erreur <= 0 a la place == 0
*		   26/12/1991  llb Ombrage fenetre
*		   20/04/93    llb caractere paragraphe dans titre
*************************************
* Fonctions                         *
*                                   *
* - wcreat       creation une fen   *
* - wsup         suppression fen    *
*************************************/

#include "fundef.h"

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
extern  WORD PRLMF;

/* fonctions externes */
/* ------------------ */

extern int show_rect();
extern int get_cord();
extern void mv2();
TYPF winv();
extern void wmemset();
extern void wwmemset();
extern int  mem_init();

/************************************************
* 	fonction creation d'une fenetre		*
*           sous abal                           *
*************************************************/

/* fonction prologue */

#ifdef PRL

TYPF wcreat(wnlog,wa)
WPTR		wnlog;  /* No logique fenetre a retourner */
WDESC_APP_PTR   wa;	/* ptr desc appel */
{
TYPF wcreatc();

int	cr_er;			/* code erreur retourne */
WORD    contr;

/*********************************
* Verification Init              *
*********************************/

if ( fen_ini == 0 ) {
	contr = Invint(wa->Acontrol);
	if (contr & TOP) {
	    if ((cr_er = mem_init()) != OK)
		return(cr_er);
	    edb_ini = 1;
	}
	else
    	    return(werr_ini);			/* 1 seule fenetre TOP */
}/*fen_ini == 0*/




/*********************************
* Conversion des entiers         *
*********************************/

wa->Apos_lig = Invint(wa->Apos_lig);
wa->Apos_col = Invint(wa->Apos_col);
wa->Anb_lig  = Invint(wa->Anb_lig);
wa->Anb_col  = Invint(wa->Anb_col);
wa->Acontrol = Invint(wa->Acontrol);
wa->Aln_tit  = Invint(wa->Aln_tit);

/*********************************
* Appel fonction C               *
*********************************/

cr_er = wcreatc( (WPTR) wnlog,(WDESC_APP_PTR) wa);

wa->Apos_lig = Invint(wa->Apos_lig);
wa->Apos_col = Invint(wa->Apos_col);
wa->Anb_lig  = Invint(wa->Anb_lig);
wa->Anb_col  = Invint(wa->Anb_col);
wa->Acontrol = Invint(wa->Acontrol);
wa->Aln_tit  = Invint(wa->Aln_tit);

*wnlog = Invint(*wnlog);

return(cr_er);

}

#else


/************************************************
*	fonction creation d'une fenetre         *
*	    sous abal unix			*
*************************************************/

TYPF wcreat(wnlog,wb)
WPTR	wnlog;	/* No logique fenetre a retourner */
BPTR	wb;

{
TYPF wcreatc();

int	cr_er;			/* code erreur retourne */
WORD	i, mot, contr;
WORD	nlog=0;

WDESC_APP   fena;			/* structure tampon */

/*********************************
* Verification Init              *
*********************************/

if ( fen_ini == 0 ) {
	contr = (wb[Bcontrol])*256 + wb[Bcontrol+1];
	if (contr & TOP) {
	    if ((cr_er = mem_init()) != OK)
		return(cr_er);
	    edb_ini = 1;
	}
	else
    	    return(werr_ini);			/* 1 seule fenetre TOP */
}/*fen_ini == 0*/

/*********************************
* Transfert de la structure ABAL *
**********************************/

	fena.Amere_nbr = 0;
	fena.Apos_lig =  (wb[Bpos_lig])*256 + wb[Bpos_lig+1];
	fena.Apos_col =  (wb[Bpos_col])*256 + wb[Bpos_col+1];
	fena.Anb_lig =	 (wb[Bnb_lig])*256 +  wb[Bnb_lig+1];
	fena.Anb_col =	 (wb[Bnb_col])*256 +  wb[Bnb_col+1];

	fena.Aatb_vid = wb[Batb_vid];
	fena.Aatbcol_text = wb[Batbcol_text];
	fena.Aatbcol_fond = wb[Batbcol_fond];

	fena.Acontrol = (wb[Bcontrol])*256 + wb[Bcontrol+1];
	fena.Aln_tit = (wb[Bln_tit])*256 + wb[Bln_tit+1];


	for (i=0; i< 32 ; ++i)
		fena.Atitre[i] = wb[Btitre+i];

	for (i=0; i< 8 ; ++i)
		fena.Acad_usr[i] = wb[Bcad_usr+i];

	fena.Acad_atb = wb[Bcad_atb];
	fena.Acad_text = wb[Bcad_text]; 	/* NS le 12/04/90 */
	fena.Acad_fond = wb[Bcad_fond];


/*********************************
* Appel fonction C		 *
*********************************/

cr_er = wcreatc((WPTR)&nlog ,(WDESC_APP_PTR)&fena);

PutAbalWord( wnlog, nlog );

return(cr_er);
}
#endif

/************************************************
* 	fonction creation d'une fenetre	(C)
*************************************************/

TYPF wcreatc(wnlog,wa)
WDESC_APP_PTR	     wa;	/* ptr desc appel */
WPTR		     wnlog;  /* No logique fenetre a retourner */
{
WDESC_PTR	     wc;    /* ptr wdesc a creer */
WITEM           *wi,*w;
WORD		nlog, i, lig, col, bd, t, temp;
BPTR            txt_ptr;
WPTR		atb_ptr;
BYTE		cad_type;

if (fen_ini == 0)	/* verif winit() */
   return(werr_ini);


/* test validite parametres */
/* Version 1 : test des coordonnees par rapport aux constantes MAXLIG,MAXCOL
   Version 2 : test par rapport aux parametres de la fenetre mere
*/

/* appel par abal: notation directe
		   =>conversion contenu desc appel
*/

gplig = wa->Apos_lig ;

gpcol = wa->Apos_col ;

gnlig = wa->Anb_lig ;

gncol = wa->Anb_col ;

temp = wa->Acontrol ;

bd = (((temp & CAD1) || (temp & CAD2) || (temp & CAD3)) ? 1 : 0);


if( (((short int)(gplig-bd)) <= 0) || ((gplig+bd) > MAXLIG ) ||
    (((short int)(gpcol-bd)) <= 0) || ((gpcol+bd) > MAXCOL ) ||
    (gnlig == 0) || (gncol == 0) || 
    ((gplig + gnlig +bd) > MAXLIG+1 ) ||
    ((gpcol + gncol + bd) > MAXCOL+1 ) )
 return(werr_desc);

if (wa->Amere_nbr != 0)
 return(werr_desc);


/* Recherche WITEM libre */

if ( temp & TOP)
	nlog = (MAXFUN-1);
else {
	nlog = 0;
	while ((nlog < MAXFUN) && (WLOG[nlog]->mere != 0 ))
	      nlog++;
	if ( nlog == MAXFUN)
	   return(werr_max);
}

/* Alloc descripteur fenetre + data fenetre */
wc =  (WDESC_PTR) f_allouer (sizeof(WDESC));
i = (gnlig+(2*bd)) * (gncol+(2*bd));
txt_ptr= (BPTR) f_allouer (i);
atb_ptr= (WPTR) f_allouer (2*i);

if ( (wc == (WDESC*) NULL) || (txt_ptr == (BPTR) NULL) || (atb_ptr == (WPTR) NULL) )
   return(werr_mem);

wi = WLOG[nlog] ;
wi->wdesc_ptr= wc;	/* init adresse desc fenetre */


/* init descripteur fenetre */
/* ------------------------ */

wc->mere_nbr    = 0;
wc->pos_lig     = gplig;
wc->pos_col     = gpcol;
wc->nb_lig      = gnlig;
wc->nb_col      = gncol;
/*	wc->atb_vid     = wa->Aatb_vid;
	wc->atbcol_text = wa->Aatbcol_text;
	wc->atbcol_fond = wa->Aatbcol_fond;
*/
wc->control     = temp;
wc->gel	 	= 0;
wc->adr_text = txt_ptr;
wc->adr_atb = atb_ptr;

   temp = wa->Aln_tit;
#ifdef TSCO
   fprintf(stderr,"Wcreatc Longueur Titre initial %d\n",temp);
#endif
   for ( t = 0; t < temp ; t++) 		/* recopie du titre */
     {
	wc->titre[t] = wa->Atitre[t];
#ifdef TSCO
   fprintf(stderr,"%c-",wa->Atitre[t]);
#endif
	if (( PRLMF) && (wc->titre[t] == 0xd2))
	    wc->titre[t] = 0x15;
   }	


   /* calcul longueur reelle titre : supprimer blancs en fin de chaine */
   if ( t > 0)  {
	t--;
	while ( (wc->titre[t] == ' ')&&( t>0))
	{
#ifdef TSCO
   fprintf(stderr,"-%c",wc->titre[t]);
#endif
	t--;
	}
	t++;
   }
   if ( t > wc->nb_col )
	t = wc->nb_col;
   wc->ln_tit = t;
   wc->titre[t] = NULL;
#ifdef TSCO
   fprintf(stderr,"Wcreatc Longueur Titre Recalcul‚e %d\n",wc->ln_tit);
   fprintf(stderr,"Wcreatc Titre Recalcul‚ %s\n",wc->titre);
#endif

   wc->cur_atb = ((wa->Aatbcol_fond << 4) + wa->Aatbcol_text) ;
   wc->cur_atb  += (wa->Aatb_vid << 8);
   wc->bas_atb = wc->cur_atb;


   wc->cad = bd;
   wc->cur = (( wc->control & CURSEUR) ? 1 : 0);

   /* param par defaut */

   wc->cur_lig = 1;
   wc->cur_col = 1;
   gnlig += 2*bd;
   gncol += 2*bd;

  if (( wc->control & CAD3) == CAD3)  {	/* cadre utilisateur */
	cad_type = 3;
	wc->cad_atb = ((wa->Acad_fond << 4) + wa->Acad_text) ;
	wc->cad_atb  += (wa->Acad_atb << 8);
	wc->tit_atb = wc->cad_atb;
  }
  else
  {
	wc->cad_atb = wc->tit_atb = wc->cur_atb;
	if ( (wc->control & CAD1) == CAD1 )	/* cadre simple trait */
		cad_type = 1;
	  else
	  if (( wc->control & CAD2) == CAD2)	/* cadre Double trait */
		cad_type = 2;
	  else
		cad_type = 0;
  }
  /* init data fenetre */
  /* ----------------- */
  wmemset(wc->adr_text , 0x20 , gnlig*gncol );        /* texte */
  wwmemset(wc->adr_atb , wc->cur_atb, gnlig*gncol);   /* attribut */


/* MAJ chainage superposition et affichage */
/* --------------------------------------- */

  if ( wc->control & TOP )
	wi->mere = (WITEM*) TOP;
  else {
	if (avp == (WITEM*)NULL)		/* 1ere fenetre cree */
           {
	    avp = wi;
	    wi->mere = (WITEM*) WRES;	/* reservation WITEM */
	}
        else   {
	    wi->fsous = avp;
	    avp->fsur = wi;
	    wi->mere = (WITEM*)WRES;
	    avp = wi;
        }
  }/*!=TOP*/


  if (!( wc->control & INVISIBLE )) {  /* si elle est visible */
	get_cord(wi);
	if (!(wc->control & TOP))   {
	    for ( lig = gplig ; lig < gplig+gnlig ; lig++)   /* MAJ mapecran */
	      for (col=gpcol; col < gpcol+gncol; col++)
		  *(mapecran + ( MAXCOL*((WORD)lig -1)) + (col -1)) = wi;
	}/*!= TOP*/
	else {
/* llb 17.12.93
		sav_impl = fimpl;
		fimpl = nlog+1;
* llb fin */
	}
  }/* visible*/

  /* init cadre fenetre */
  /*--------------------*/
  temp = wc->control;
  wc->control |= INVISIBLE;	/* forcer invisible pour ne rien afficher */


#ifdef TSCO
   fprintf(stderr,"Wcreatc Type Cadre %d\n",cad_type);
#else
  if ( cad_type != 0 ) {
	wcadrec( wi, cad_type, wc->cad_atb, (cad_type == 3) ? wa->Acad_usr : (BPTR)NULL);
  }

/* incrustation du titre dans le cadre */
/* ----------------------------------- */

#ifdef TSCO
   fprintf(stderr,"Wcreatc Titre Affich‚ %s\n",wc->titre);
#else
 wtitrec(wi, wc->tit_atb, wc->titre);
#endif
 wc->control = temp;	/* restituer etat invisible */

/* afficher fenetre */
/*------------------*/
  if ((!( wc->control & INVISIBLE))&&(topvis == 0))  {
	    wc = wi->wdesc_ptr ;
            desc_mv2->nfonc = AFFICHE ;
            desc_mv2->adr_atb = wc->adr_atb;
            desc_mv2->adr_text = wc->adr_text;
            desc_mv2->adr_fore = wc->adr_fore;
            desc_mv2->adr_back = wc->adr_back;
            desc_mv2->adr_media = wc->adr_media;
            desc_mv2->inc_buf = gncol ;
            desc_mv2->mvlig   = gplig ;
            desc_mv2->mvcol   = gpcol ;
            desc_mv2->mvnbcol = gncol ;
            desc_mv2->mvnblig = gnlig ;
            mv2(desc_mv2);

	    if ( wc->control & OMBRE )
		set_ombre(wi);

	    /* curseur */
	    repos_cur(wi);
  }/*topvis & VISIBLE */
  else  {  /* supprimer curseur de F->SOUS*/
        desc_mv2->nfonc = HIDECUR;
        mv2(desc_mv2);		/* set ou reset curseur */
  }

    if (wc->control & TOP)
	topvis = 1;			/* flag fenetre TOP visible */

/* retourner le No logique */

 *wnlog = ++nlog;	/* on commence a 1 */

 return(OK);

}/*wcreat*/

/************************************************
* 	fonction SUPPRESSION fenetre		*
************************************************/

TYPF wsup(f)
WORD f;
{
    WITEM	*wi,*wsur,*wsous;
    WDESC_PTR wd;

    if (fen_ini == 0)		/* test winit() */
        return(werr_ini);


    if ((f > MAXFUN) || (f < 1))
        return(werr_inex);		/* fenetre inexistante */
    wi=WLOG[f-1];
    if (wi->mere == (WITEM*)NULL)
        return(werr_inex);		/* fenetre inexistante */

    winv(f);                      /* F INVISIBLE */

    wd = wi->wdesc_ptr;
    if ( wd->control & TOP)
	edb_ini = 0;
    f_libere(wd->adr_text);
    f_libere(wd->adr_atb);
    f_libere(wd);

    if ( f == fimpl )
        fimpl = NULL;		/* implicite ecran */


    
    /* MAJ chainage */
    if (wi->mere != (WITEM*) TOP)  {
        wsous = wi->fsous;
	wsur  = wi->fsur;
	if ( wsur != (WITEM*)NULL )
            wsur->fsous = wsous;
        if ( wsous != (WITEM*)NULL )
            wsous->fsur = wsur;
        if ( avp == wi )
    	    avp = wi->fsous;		/* nouvelle en avant plan */
    }
    wi->mere = (WITEM*)NULL;
    wi->fsur = (WITEM*)NULL;
    wi->fsous = (WITEM*)NULL;
  
    /* repositionner curseur sur nouvelle F en AVP */  
    if (avp != (WITEM*)NULL)  {
        wd = avp->wdesc_ptr;
        if ( wd->cur != 0 ) {
 	    desc_mv2->nfonc = POSCUR;
            desc_mv2->mvlig = wd->pos_lig + wd->cur_lig - 1 ;
            desc_mv2->mvcol = wd->pos_col + wd->cur_col - 1 ;
            mv2(desc_mv2);			/* positionner curseur ecran */
            desc_mv2->nfonc = SHOWCUR;
            mv2(desc_mv2);		/* set curseur */
        }
    } /* AVP <> 0*/
return(OK);
} /* wsup */
/* fin de fichier */

