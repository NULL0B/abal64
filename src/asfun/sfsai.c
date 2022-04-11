/********************************************************
* Services Fenetres - Saisie textes 			*
*-------------------------------------------------------*
* Source : sfsai.c                  			*
*-------------------------------------------------------*
* Version : 1.1b                    			*
* Mise a jour le : 16/05/90   sb  			*
* 		   16/11/90   llb                       *
*		   traitement fenetre de 1 ligne.       *
*		   29/08/91 EDS                         *
*		   ajout param 'exit' … sftxt_modc      *
*		   pour remonter type de sortie.        *
*		   12/11/91 LLB                         *
*		   corr sftxt si fenetre sans cadre     *
*		   25/11/91 LLB                         *
*		   forcer fenetre mode page sur saisie. *
*		   13/04/92 EDS				*
*		   saisie 1 ligne scrollable.		*
* verion 1.4                            		*
*		   07/05/92 EDS	mouse			*
*		   04/05/93 llb	Controle wpsmotsc	*
*                  03/06/93 llb Exception si ctrl D   	*				DEL sur dernier caract
*		   20/09/93 llb traitement TAB != RC	*
*				dans saisie oneline 	*
*********************************************************
* Fonctions                         			*
*                                   			*
* - sfmod_txt modification texte    			*
* -                                 			*
* -                                 			*
* -                                 			*
* -                                 			*
********************************************************/


#include "sfundef.h"
#include "bda.h"

#include "mouse.h"



#define SAIS_EVENTS	KEYBOARD+MOUSE_DOWN+MOUSE_UP+MOUSE_CLICK+MOUSE_D_CLICK+MOUSE_M_W_DOWN+MOUSE_IS_DOWN


#define NO_REGION	-2
#define INSIDE_SAIS	-1
#define CADRE_GAUCHE	M_LEFT
#define CADRE_DROIT	M_RIGHT
#define CADRE_HAUT	M_UP
#define CADRE_BAS	M_DOWN




/* macro-definiton des caracteres d'un mot sous prologue */
#define est_mot(car) ( ((car>='A') && (car<='Z')) || ((car>='a') && (car<='z')) || ((car>=0x80) && (car<=0x9a)) || ((car>=0xb5) && (car<=0xbe)) || ((car>=0xc6) && (car<=0xcf)) )? (TRUE):(FALSE)

/* macro-definiton des ponctuations sous prologue */
#define est_ponc(car) ( (car =='.') || (car == '?') || (car == '!') )? (TRUE):(FALSE)


#define No_err		0

#define NOP		-1		/* no action sur la saisie	*/
#define INIT            -2		/* flag d'init de saisie	*/




/* variables globales */

extern  WORD PRLMF;
extern	BYTE    fen_ini;
extern	APP_MV2	*desc_mv2;
extern	WITEM*  WLOG[MAXFUN];
extern	WITEM   *avp;
extern	WORD	fimpl;		/* fenetre implicite */

extern WORD gplig, gpcol, gnlig, gncol;

extern GLOBAL BDA_ARG rt_arg;


extern EVENT_STR	event;


/* fonctions externes */

extern int show_rect();
extern int get_cord();
extern int wscroll();
extern void mv2();
extern void wcleof();
extern void wcleol();
extern void wins_lig();
extern void wsup_lig();
extern void vert_scroll();
extern void winsncar();
extern void wsupncar();
extern void bell();



/* variables decrites dans ce module */

TYPF wpseot();		/* position fin texte */
TYPF wpseol();	 	/* position fin ligne */
TYPF wpseop();	 	/* position fin paragr*/
TYPF wpctlg();		/* centrer ligne */
TYPF wpsmot(); 		/* position mot */
TYPF wfinsc();		/* insertion    */
TYPF wfsupc();		/* suppression  */




/***************************************************************
*	WPSEOT()
*  Recherche dernier caractere non a blanc fenetre
*  retour de la position ligne/colonne
*
****************************************************************/

TYPF wpseot (f, ptlig, ptcol)
WORD f;
WPTR ptlig;
WPTR ptcol;

{

/* variables internes */

  WITEM *wi;
  BPTR adr_txt;
  WORD plig,pcol,bd ;
  WDESC_PTR wd;
  BYTE fin;

  if(fen_ini != 2)		/* test winit() */
    return(werr_ini);

  if((f > MAXFUN) || (f < 1))
    return(werr_inex);		/* fenetre inexistante */

  wi=WLOG[f-1];
  if(wi->mere == (WITEM*)NULL)
    return(werr_inex);		/* fenetre inexistante */


  /* debut fonction */

  wd = wi->wdesc_ptr;		/* descripteur fenetre */
  bd = wd->cad;

  plig = wd->nb_lig+bd;
  pcol = wd->nb_col+bd;
  adr_txt = wd->adr_text + (plig*(pcol+bd)) - bd-1;
  fin = TRUE;

  while (( plig > bd) && (fin))
    {
     while ((pcol > bd) && (fin))
       {
	if(*adr_txt == ' ')
	  {
	   --pcol;
	   --adr_txt;
	  }
	else
	  {
	   fin = FALSE;
	  }
       }

     if(fin)
       {
	adr_txt -= 2*bd;
	--plig;
	pcol = wd->nb_col+bd;
       }
    }

  plig -= bd;
  pcol -= bd;

  *ptlig = plig;
  *ptcol = pcol;

  return(OK);
}







/***************************************************************
*	WPSEOL()
*  Recherche dernier caractere non a blanc ligne courante
*  retour de la position ligne/colonne
*
****************************************************************/

TYPF wpseol (f, ptlig, ptcol)
WORD f;
WPTR ptlig;
WPTR ptcol;

{

  /* variables internes */

  WITEM *wi;
  BPTR adr_txt;
  WORD plig,pcol,bd ;
  WDESC_PTR wd;

  if(fen_ini != 2)		/* test winit() */
    return(werr_ini);

  if((f > MAXFUN) || (f < 1))
    return(werr_inex);		/* fenetre inexistante */

  wi=WLOG[f-1];
  if(wi->mere == (WITEM*)NULL)
    return(werr_inex);		/* fenetre inexistante */


  /* debut fonction */

  wd = wi->wdesc_ptr;		/* descripteur fenetre */
  bd = wd->cad;

  plig = wd->cur_lig+bd;
  pcol = wd->nb_col+bd;
  adr_txt = wd->adr_text + (plig*(pcol+bd)) - bd-1;

  while((pcol > bd) && (*adr_txt == ' '))
    {
     --pcol;
     --adr_txt;
    }

  plig -= bd;
  pcol -= bd;


  *ptlig = plig;
  *ptcol = pcol;

  return(OK);
}






/***************************************************************
*	WPSEOP()
*  Recherche fin de paragraphe depuis la ligne courante
*  retour de la position ligne/colonne
*
****************************************************************/

TYPF wpseop(f, ptlig, ptcol)
WORD	f;
WPTR	ptlig;
WPTR	ptcol;

{

  /* variables internes */
  WITEM *wi;
  WDESC_PTR wd;
  BPTR adr_txt;
  WORD plig,pcol,bd ;
  WORD nlig,ncol;
  WORD ilig,icol;
  WORD cold;
  BYTE fin;


  if(fen_ini != 2)		/* test winit() */
    return(werr_ini);

  if((f > MAXFUN) || (f < 1))
    return(werr_inex);		/* fenetre inexistante */

  wi=WLOG[f-1];
  if(wi->mere == (WITEM*)NULL)
    return(werr_inex);		/* fenetre inexistante */


  /* debut fonction */

  wd = wi->wdesc_ptr;		/* descripteur fenetre */
  bd = wd->cad;
  plig = wd->cur_lig;
  pcol = wd->cur_col;
  nlig = wd->nb_lig;
  ncol = wd->nb_col;

  ilig = plig;
  cold = pcol;
  fin = FALSE;

  while((ilig <= nlig) && (fin == FALSE))
    {
     icol = ncol;
     adr_txt = wd->adr_text + ((ilig+bd)*(icol+bd+bd)) - bd-1;

     while((icol > cold) && (fin == FALSE))
       {
	if(*adr_txt == ' ')
	  {
	   --icol;
	   --adr_txt;
	  }
	else
	  {
	   fin = est_ponc(*adr_txt);
	   if(fin == FALSE)
	   icol = 0;
	  }
       }

     if(icol == 1)
       fin = TRUE;
     if(fin == FALSE)
       ++ilig;
     cold = 1;
    }

 *ptlig = ilig;
 *ptcol = icol;

 return(OK);
}






/***************************************************************
*	WPCTLG()
*  Centrage de la ligne positionnee
*
****************************************************************/

TYPF wpctlg (f)
WORD f;

{

  /* variables internes */

  WITEM *wi;
  BPTR adr_txt;
  WORD plig,pcol,bd,ncol;
  WDESC_PTR wd;
  WORD nbd,nbf,i;		/* nbre de blancs debut,fin,moyen */


  if(fen_ini != 2)		/* test winit() */
    return(werr_ini);

  if((f > MAXFUN) || (f < 1))
    return(werr_inex);		/* fenetre inexistante */

  wi=WLOG[f-1];
  if(wi->mere == (WITEM*)NULL)
    return(werr_inex);		/* fenetre inexistante */


  /* debut fonction */

  wd = wi->wdesc_ptr;		/* descripteur fenetre */
  bd = wd->cad;

  plig = wd->cur_lig+bd-1;
  ncol = wd->nb_col+bd;
  adr_txt = wd->adr_text + (plig*(ncol+bd)) +bd;

  pcol = bd+1;
  nbd = 0;
  nbf = 0;

  /* caracteres blancs devant */

  while((pcol < ncol) && (*adr_txt == ' '))
    {
     ++pcol;
     ++adr_txt;
     ++nbd;
    }

  /* caracteres blancs derriere */

  if(pcol < ncol)
    {
     pcol = wd->nb_col+bd;
     adr_txt = wd->adr_text + ((plig+1)*(pcol+bd)) - bd-1;

     while((pcol > bd) && (*adr_txt == ' '))
       {
	--pcol;
	--adr_txt;
	++nbf;
       }
    }
  else
     return(OK);			/* ligne blanche */

  /* test si centrage */

  if((nbd+nbf) <= 1 )
    return(OK);				/* ligne pleine */

  if(nbd == nbf)
    return(OK);				/* deja centre */

  /* que faut il faire ? */

  i =  (nbd + nbf) / 2;
  if(i == nbd)
    return(OK);				/* a peu pres centre */

  wposcur(f,wd->cur_lig,1);		/* on travaille en debut ligne */

  if(i > nbd)
    for( ; i > nbd; ++nbd)
       wfgen(f,INS_CAR);   		/* insertion des blancs */
  else
    for ( ; nbd > i; --nbd)
       wfgen(f,SUP_CAR);		/* suppression des blancs */

  return(OK);

}




/***************************************************************
*	WINSC()
*  Insertion de blancs a la position en cours
*   1er param : fenetre
*   2eme param : type
*		1 = ligne
*		2 = paragraphe
*		3 = texte
*   3eme param : nombre de caracteres
*
*  retour Ok ou impossible
*
****************************************************************/

TYPF wfinsc (f, type, n_car)
WORD f;
BYTE type;
WORD n_car;

{

/* variables internes */

  WITEM *wi;
  BPTR adr_txt;
  WORD plig,pcol,nlig,ncol,ilig,icol,l,c ;
  WDESC_PTR wd;


  if (fen_ini != 2)		/* test winit() */
    return(werr_ini);

  if ((type ==0) || (type > 3) )
    return(werr_desc);

   if ((f > MAXFUN) || (f < 1))
     return(werr_inex);		/* fenetre inexistante */

   wi=WLOG[f-1];
   if (wi->mere == (WITEM*)NULL)
     return(werr_inex);		/* fenetre inexistante */


/* debut fonction */

  wd = wi->wdesc_ptr;		/* descripteur fenetre */

  plig = wd->cur_lig;
  pcol = wd->cur_col;
  ncol = wd->nb_col;
  nlig = wd->nb_lig;

  if (n_car > ncol)
   return(werr_desc);

  switch (type)
   {
   case 1:
	wpseol(f,(WPTR)&ilig, (WPTR)&icol);
	if (icol+n_car > ncol) return(werr_desc);
	break;
   case 2:
	wpseop(f,(WPTR)&ilig, (WPTR)&icol);
	if (icol+n_car > ncol)
	   {
	    if (ilig == nlig) return(werr_desc);
	    wpseot(f, (WPTR)&l, (WPTR)&c);
	    if (l == nlig) return(werr_desc);
	    ++ilig;
	    wfgen(f,CUROF);
	    wposcur(f,ilig,1);
	    wfgen(f,INS_LIG);
	    wposcur(f,plig,pcol);
	    wfgen(f,CURON);
	   };
	break;
   case 3:
	wpseot(f,(WPTR)&ilig,(WPTR)&icol);
	if (icol+n_car > ncol)
	   {
	    if (ilig == nlig) return(werr_desc);
	    ++ilig;
	   };
	break;
    };
  winsncar((WITEM*) wi,1,n_car,ilig-plig+1);
  return(OK);

}









/***************************************************************
*	WSUPC()
*  Suppression de caractere a la position en cours
*   1er param : fenetre
*   2eme param : type
*		1 = ligne
*		2 = paragraphe
*		3 = texte
*   3eme param : nombre de caracteres
*
*  retour Ok ou impossible
*
****************************************************************/

TYPF wfsupc (f, type, n_car)
WORD f;
BYTE type;
WORD n_car;

{

  /* variables internes */
  WITEM *wi;
  BPTR adr_txt;
  WORD plig,pcol,ncol,ilig,icol ;
  WDESC_PTR wd;

  if(fen_ini != 2)		/* test winit() */
    return(werr_ini);

  if((type ==0) || (type > 3) )
    return(werr_desc);

  if((f > MAXFUN) || (f < 1))
    return(werr_inex);		/* fenetre inexistante */

  wi=WLOG[f-1];
  if(wi->mere == (WITEM*)NULL)
    return(werr_inex);		/* fenetre inexistante */


  /* debut fonction */

  wd = wi->wdesc_ptr;		/* descripteur fenetre */

  plig = wd->cur_lig;
  pcol = wd->cur_col;
  ncol = wd->nb_col;

  if(n_car > ncol)
   return(werr_desc);

  switch (type)
   {
    case 1:
      ilig = plig;
      icol = pcol;

      if((icol+n_car > ncol)&&(icol != ncol))
	return(werr_desc);
      break;

    case 2:
      wpseop(f, (WPTR)&ilig, (WPTR)&icol);
      break;

    case 3:
      wpseot(f,(WPTR)&ilig, (WPTR)&icol);
      break;
   }

  wsupncar((WITEM*) wi,1,n_car,ilig-plig+1);

  return(OK);
}





/***************************************************************
*	WPSMOT()
*  Recherche mot suivant /precedent du texte
*  retour de la position ligne/colonne
*
****************************************************************/

TYPF wpsmot(f, sens, ptlig, ptcol)
WORD f;
BYTE sens;			/* 1 suivant 2 precedent */
WPTR ptlig;
WPTR ptcol;

{

  /* variables internes */
  WITEM *wi;
  BPTR adr_txt;
  WORD pcar,maxcar,mincar ;
  WORD bd;
  BYTE mot;			/* VRAI dans un mot , faux en dehors */
  int dir;			/* direction */

  WDESC_PTR wd;



  if(fen_ini != 2)		/* test winit() */
    return(werr_ini);

  if((f > MAXFUN) || (f < 1))
    return(werr_inex);		/* fenetre inexistante */

  wi=WLOG[f-1];
  if(wi->mere == (WITEM*)NULL)
    return(werr_inex);		/* fenetre inexistante */

  if(sens == 1)
    dir = 1;
  else
    if(sens == 2)
      dir = -1;
    else
      return(werr_desc);		/* non-sens ! */


  /* debut fonction */

  wd = wi->wdesc_ptr;		/* descripteur fenetre */
  bd = wd->cad;

  if(bd)
    {
     pcar = (wd->cur_lig)*(wd->nb_col+bd+bd)+bd+wd->cur_col;
     maxcar = (wd->nb_lig+bd)*(wd->nb_col+bd+bd)-1;
     mincar = wd->nb_col + 4;
    }
  else
    {
     pcar = (wd->cur_lig-1)*(wd->nb_col)+wd->cur_col;
     maxcar = wd->nb_lig*wd->nb_col;
     mincar = 1;
    }


  adr_txt = wd->adr_text + pcar -1;

  mot = est_mot(*adr_txt);

  /* on saute le mot en cours */

  while((mot==TRUE) && (pcar >=mincar) && (pcar <= maxcar))
    {
     pcar +=dir;
     adr_txt +=dir;
     mot = est_mot(*adr_txt);
    }

  /* on saute les intermots */

  while((mot==FALSE) && (pcar >=mincar) && (pcar <= maxcar))
   {
    pcar +=dir;
    adr_txt +=dir;
    mot = est_mot(*adr_txt);
   }

  /* en arriere on saute le mot precedent */

  if(dir == -1)
   {
    while((mot==TRUE) && (pcar >=mincar) && (pcar <= maxcar))
      {
       pcar +=dir;
       adr_txt +=dir;
       mot = est_mot(*adr_txt);
      }
    if (mot == FALSE) ++pcar;
   }

  if((pcar < mincar) || (pcar >= maxcar))
    {
     *ptlig = wd->cur_lig;
     *ptcol = wd->cur_col;
    }
  else
    {
     *ptlig = pcar/(wd->nb_col+bd+bd);
     *ptcol = pcar -(*ptlig * (wd->nb_col +bd +bd ) +1 ) ;
    }

  return(OK);
}




/* la meme pour la saisie scrollable */

TYPF wpsmotsc(buff, lg_b, pos_b, sens, ptcol, lg_m)
BPTR buff;
WORD lg_b;			/* longueur buffer		*/
WORD pos_b;			/* position dans buffer		*/
BYTE sens;			/* 1 suivant 2 precedent 	*/
WORD *ptcol;
WORD *lg_m;			/* longueur mot			*/

{

  /* variables internes */
  BPTR adr_txt;
  SWORD pcar,maxcar,mincar ;
  BYTE mot;			/* VRAI dans un mot , faux en dehors */
  int dir;			/* direction */


  if(sens == 1)
    dir = 1;
  else
    if(sens == 2) {
      dir = -1;
      if (pos_b == 0)		/* controle coh‚rence */
	{ 	      	
	  *ptcol = 0; 
	  *lg_m = 0;
	  return(OK);
	}
    }
  /* debut fonction */

  pcar = pos_b;
  maxcar = lg_b;
  mincar = 0;


  adr_txt = &buff[pos_b];

  mot = est_mot(*adr_txt);

  /* on saute le mot en cours */
  while((mot == TRUE) && (pcar >= mincar) && (pcar <= maxcar))
    {
     pcar +=dir;
     adr_txt +=dir;
     mot = est_mot(*adr_txt);
    }

  /* on saute les intermots */
  while((mot == FALSE) && (pcar >= mincar) && (pcar <= maxcar))
    {
     pcar +=dir;
     adr_txt +=dir;
     mot = est_mot(*adr_txt);
    }

  /* on calcule la taille du mot */
  if(dir == 1)
    {
     *ptcol = (pcar > maxcar) ? maxcar : pcar;
     *lg_m = 0;
     while((mot == TRUE) && (pcar >= mincar) && (pcar <= maxcar))
       {
	(*lg_m)++;
	pcar +=dir;
	adr_txt +=dir;
	mot = est_mot(*adr_txt);
       }
    }

  /* en arriere on saute le mot precedent et on calcule sa taille */
  if(dir == -1)
    {
     *lg_m = 0;
     while((mot == TRUE) && (pcar >= mincar) && (pcar <= maxcar))
       {
	(*lg_m)++;
	pcar +=dir;
	adr_txt +=dir;
	mot = est_mot(*adr_txt);
       }
     if(mot == FALSE)
       ++pcar;

     *ptcol = (pcar < 0) ? 0 : pcar;
    }

  return(OK);
}





/************************************************
*
* REDRAW DU CONTENU DE LA FENETRE EN FONCTION
*
* DE LA PORTION VUE
*
*************************************************/

void refresh( f, buff, pos_w, maxbuf, ncol)
WORD f;
BPTR buff;
WORD pos_w;
WORD maxbuf;
WORD ncol;
{

  wgel(f);
  wfgen(f, 1);
  wposcur(f, 1, 1);
  wwrite(f, min(maxbuf-pos_w, ncol), &buff[pos_w]);
  wvis(f);
}






/************************************************
*
* SAISIE/MODIFICATION D'UN TEXTE DANS UNE FENETRE
*
* 	type 1 : insertion car
*	     2 : paragraphe
*	     3 : texte
*	     8 : Init saisie par text et exit
*	    32 : Sortie sur touche de fct
*
*************************************************/

/*#ifdef BOS
TYPF sftxt_mod(f, maxbuf, lgbuf, text, typins)
#else*/
TYPF sftxt_mod(f, maxbuf, lgbuf, text, typins, ret )
/*#endif*/

WORD f;			/* fenetre  			*/
WORD maxbuf;		/* taille maximale buffer 	*/
WPTR lgbuf;		/* longueur buffer renvoyee 	*/
BPTR text;		/* buffer texte 		*/
BYTE typins;            /* type insert			*/
BPTR ret;		/* type de sortie		*/

{
  TYPF sftxt_modc();


  /* variables internes */

  int stx_er;			/* code erreur */
  WORD lger;
  WORD lgret;
  BYTE kexit;

	if ( rt_arg.c > 6)
		return(RT_err_arg);

	if ( rt_arg.c > 5 ) 
		if ( rt_arg.t[5] != (TYPE_CHAINE | MODIFIABLE) )
			return(RT_err_typ);

	if (!(stx_er = sftxt_modc((WORD)f, (WORD)maxbuf, (WPTR)&lgret, (BPTR)text, (BYTE)typins, (BPTR)&kexit))) {
		PutAbalWord( lgbuf,lgret);
		}
	else	{
		PutAbalWord(lgbuf,0);
		}

	/* test si arg de sortie */

	if(rt_arg.c == 6)
		*ret = kexit;
	return(stx_er);

}





/****************************************
*					*
* appel C standard              	*
*                                       *
*****************************************/

TYPF sftxt_modc(f, maxbuf, lgbuf, text, typins, exit)

WORD f;			/* fenetre */
WORD maxbuf;		/* taille maximale buffer */
WPTR lgbuf;		/* longueur buffer renvoyee */
BPTR text;		/* buffer texte */
BYTE typins;
BPTR exit;		/* type de sortie (TAB/RC/ESC) */
{

  TYPF lscreatc();
  TYPF sf_find_tch();

  /* donnees externes */

  extern BYTE tc[MAX_TOUCHES];
  extern BYTE *tabmes[MAXMES];
  extern cof_tab co;
  extern BYTE sa_touche;
  extern BYTE a_mcd[9];


  /* donnees internes */

  BYTE car;			/* caractere entre 			*/
  SWORD val;			/* flag de traitement			*/
  SWORD i,j,k;			/* variables de travail 		*/
  WORD lbuf;			/* longueur max retour 			*/
  SWORD plig,pcol;		/* positions ligne, colonne 		*/
  SWORD nlig,ncol;		/* nombre de lignes colonnes 		*/
  SWORD pos_w;			/* position de la fenetre / au buffer	*/
  WORD sai_er;			/* code erreur 				*/
  WITEM *wi;
  BPTR adr_txt;
  WORD bd ;
  WDESC_PTR wd;
  WDESC_PTR wf;
  BYTE modins;			/* mode insertion ou non 		*/
  BYTE mesc[132];		/* status d'aide 			*/
  WORD s_fc;			/* fenetre commentaire 			*/
  WORD pml;			/* position ligne 			*/
  WORD pmc;             	/* position message colonne 		*/
  WORD pmi;			/* position message insertion 		*/
  WORD lmi;			/* longueur message insertion 		*/
  BPTR ptm;
  BYTE one_line;		/* traitement particulier 		*/
  BYTE scrolling;		/* traitement du scroll			*/
  BYTE type_ins;		/* type d'insert			*/
  BYTE scan_tch;		/* examen touches de fct		*/
  WORD memo_control;
  SWORD mouse_m_w_down;		/* marqueur d'etat de la souris		*/
  SWORD w_use, h_use;		/* largeur hauteur de la saisie		*/
  SWORD mplig, mpcol;		/* position mouse			*/
  SWORD region;			/* region de la saisie			*/


  if(fen_ini != 2)		/* test winit() */
    return(werr_ini);

  if((f > MAXFUN) || (f < 1))
    return(werr_inex);		/* fenetre inexistante */

  wi=WLOG[f-1];
  if(wi->mere == (WITEM*)NULL)
    return(werr_inex);		/* fenetre inexistante */


  type_ins =typins;
  if(type_ins&0x20)
    {
     scan_tch = TRUE;
     type_ins -= 0x20;
    }
  else
    scan_tch = FALSE;


  /* debut fonction */

  wd = wi->wdesc_ptr;		/* descripteur fenetre */
  bd = wd->cad;
  nlig = wd->nb_lig;
  ncol = wd->nb_col;
  plig = wd->cur_lig;
  pcol = wd->cur_col;
  modins = FALSE;
  scrolling = FALSE;
  one_line = (nlig == 1) ? TRUE : FALSE;
  val = NOP;


  /* Init saisie si one_line et scrolling */
  if(one_line == TRUE)
    {
     if(ncol < maxbuf)
       {
	scrolling = TRUE;
	val = T_END;
       }
     else
	scrolling = FALSE;
     if((type_ins & 0x08) != 0)
       {
	type_ins -= 0x08;
	if ( type_ins ==0)
		type_ins++;
	val = INIT;
       }

     pos_w = 0;
    }

  if((type_ins & 0x20) != 0)
    {
     type_ins -= 0x20;
     scan_tch = TRUE;
    }

  if((type_ins == 0) || (type_ins > 3))
    return(werr_desc);


  /* debut programme */

  if((sai_er = wvis(f)) != No_err)		/* fenetre visible	*/
    return(sai_er);

  if((sai_er = wselect(f)) != No_err)       	/* fenetre selectee 	*/
    return(sai_er);

  if((sai_er = wfgen(f,CURON)) != No_err) 	/* curseur visible 	*/
    return(sai_er);


  /* creation de la fenetre infos */

  s_fc = 0;
  if(one_line == FALSE)
    if((sai_er = lscreatc((WPTR) &s_fc)) == No_err)
      {
       pml = 0;
       ptm = (BPTR) (tabmes[MESMT]);
       while (*ptm) mesc[pml++] = *ptm++;
       mesc[pml++]=' ';
       ptm = (BPTR) (tabmes[MESL]);
       while (*ptm) mesc[pml++] = *ptm++;

       mesc[pml] = plig/10;
       mesc[pml+1] = (plig - (mesc[pml]*10)) +0x30;
       mesc[pml] += 0x30;

       pmc = pml+2;
       mesc[pmc++] = ' ';
       ptm = (BPTR) (tabmes[MESC]);
       while (*ptm) mesc[pmc++] = *ptm++;

       mesc[pmc] = pcol/10;
       mesc[pmc+1] = (pcol - (mesc[pmc]*10)) +0x30;
       mesc[pmc] += 0x30;

       pmi = pmc+2;
       lmi = 0;
       ptm = (BPTR) (tabmes[MESINS]);
       while (*ptm++) lmi++;
       mesc[pmi++] = ' ';

       wwrite(s_fc,pmi,(BPTR)&mesc[0]);
       watb(s_fc,co.o_selec.atbc,co.o_selec.colc,co.o_selec.colf);
       wvis(s_fc);
       wfgen(s_fc,CUROF);
       wselect(f);
       wposcur(f,plig,pcol);
      }

  /* forcer la fenetre en mode PAGE */
  memo_control = wd->control;
  if(wd->control & SCROLL)
    wd->control -= SCROLL;

  Wkup_in();

  *exit = ESC;
  mouse_m_w_down = FALSE;


  while(val != T_ESC)
    {
     switch(val)
       {

	/* NO ACTION */
	case NOP:
	  val = 0;
	  break;

	/* HOME */
	case T_HOME:
	case PG_UP:
	  if(scrolling)
	    {
	     pos_w = 0;
	     refresh(f, text, pos_w, maxbuf, ncol);
	    }
	  wposcur(f,1,1);
	  plig = 1;
	  pcol = 1;
	  val =  0;

	  break;

	/* END */
	case T_END:
	case INIT: /* init window one line */
	  if((scrolling) || (val == INIT))
	    {
	     for(i = maxbuf-1; (i >= 0) && (text[i] == ' '); i--);
	     if(i >= ncol)
	       {
		pos_w = i - ncol +1;
		refresh(f, text, pos_w, maxbuf, ncol);
		pcol = ncol;
	       }
	     else
	       {
		refresh(f, text, pos_w, maxbuf, ncol);
		pcol = i+1+ ((i == ncol-1) ? 0 : 1);
	       }
	    }
	  else
	    wpseot(f,(WPTR)&plig, (WPTR)&pcol);
	  if ((val == T_END) && (!scrolling) && ( pcol < ncol))
		pcol++;
	  wposcur(f,plig,pcol);
	  if(val == INIT)
	    val = T_ESC;
	  else
	    val = 0;
	  break;

	/* AIDE */
	case T_AIDE:
	  sa_aid((BPTR)a_mcd);
	  val = 0;
	  break;

	/* FLECHE DROITE */
	case F_DROITE:
	  if(scrolling)
	    if((pcol == ncol) && (pos_w == maxbuf - ncol))
	      bell();
	    else
	      if(pcol == ncol)
		{
		 pos_w++;
		 refresh(f, text, pos_w, maxbuf, ncol);
		}
	      else
		pcol++;
	  else
	    if(pcol == ncol)
	      if(plig == nlig)
	       {
		if ( !(one_line))	
		  bell();
	      }	
	      else
		{
		 pcol = 1;
		 ++plig;
		}
	    else
	      ++pcol;

	  wposcur(f,plig,pcol);
	  val = 0;
	  break;

	/* FLECHE GAUCHE */
	case F_GAUCHE:
	  if(scrolling)
	    if((pcol == 1) && (pos_w == 0))
	      bell();
	    else
	      if(pcol == 1)
		{
		 pos_w--;
		 refresh(f, text, pos_w, maxbuf, ncol);
		}
	      else
		pcol--;
	  else
	    if(pcol == 1)
	      {
	       if(plig == 1)
		 bell();
	       else
		 {
		  pcol = ncol;
		  --plig;
		 }
	      }
	    else
	      --pcol;

	  wposcur(f,plig,pcol);
	  val = 0;
	  break;

	/* FLECHE BAS */
	case F_BAS:
	  if(plig == nlig)
	    bell();
	  else
	    ++plig;

	  wposcur(f,plig,pcol);
	  val = 0;
	  break;

	/* FLECHE HAUT */
	case F_HAUT:
	  if(plig == 1)
	    bell();
	  else
	    --plig;

	  wposcur(f,plig,pcol);
	  val = 0;
	  break;

	/* MOT SUIVANT */
	case T_MSUIV:
	  if(scrolling)
	    {
	     wpsmotsc(text, maxbuf, pos_w+pcol-1, 1, &j, &k);
	     if(k == 0)
	       bell();
	     else
	       {
		if((j-pos_w < ncol) && (pcol+k < ncol))
		  {
		   pcol = j-pos_w+1;
		   wposcur(f, plig, pcol);
		  }
		else
		  {
		   /* on scroll */
		   if(pos_w+j > maxbuf-ncol)
		     {
		      pos_w = maxbuf-ncol;
		      refresh(f, text, pos_w, maxbuf, ncol);
		      pcol = j-pos_w+1;
		      wposcur(f, plig, pcol);
		     }
		   else
		     {
		      pos_w += j;
		      refresh(f, text, pos_w, maxbuf, ncol);
		      pcol = 1;
		      wposcur(f, plig, pcol);
		     }
		  }
	       }
	    }
	  else
	    {
	     wpsmot(f,1,(WPTR)&j, (WPTR)&k);
	     if((j==plig) && (k==pcol))
	       bell();
	     else
	       {
		plig = j;
		pcol = k;
		wposcur(f,plig,pcol);
	       }
	    }
	  val = 0;
	  break;

	/* MOT PRECEDENT */
	case T_MPREC:
	  if(scrolling)
	    {
	     wpsmotsc(text, maxbuf, pos_w+pcol-1, 2, &j, &k);
	     if(k == 0)
	       bell();
	     else
	       {
		if(j >= pos_w)
		  {
		   pcol = j-pos_w+1;
		   wposcur(f, plig, pcol);
		  }
		else
		  {
		   /* on scroll */
		   pos_w = j;
		   refresh(f, text, pos_w, maxbuf, ncol);
		   pcol = 1;
		   wposcur(f, plig, pcol);
		  }
	       }
	    }
	  else
	    {
	     wpsmot(f,2,(WPTR)&j, (WPTR)&k);
	     if((j==plig) && (k==pcol))
	       bell();
	     else
	       {
		plig = j;
		pcol = k;
		wposcur(f,plig,pcol);
	       }
	    }
	  val = 0;
	  break;

	/* EFFACE ECRAN */
	case EFECRAN:
	  if(scrolling)
	    {
	     for(pos_w = 0; pos_w < maxbuf; text[pos_w++] = ' ');
	     pos_w = 0;
	     refresh(f, text, pos_w, maxbuf, ncol);
	    }
	  else
	    wfgen(f,CLFUN);

	  val = T_HOME;
	  break;

	/* EFFACE DEBUT LIGNE */
	case EFDEBL:
	  if(scrolling)
	     for(i = pos_w+pcol-1; i >= 0; text[i--] = ' ');

	  wfgen(f,CLBOL);
	  val = 0;
	  break;

	/* EFFACE FIN DE LIGNE */
	case EFFINL:
	  if(scrolling)
	    for(i = pos_w+pcol-1; i < maxbuf; text[i++] = ' ');

	  wfgen(f,CLEOL);
	  wposcur(f, plig, pcol);
	  val = 0;
	  break;

	/* CENTRAGE */
	case CENTRE:
	  if(scrolling)
	    bell();
	  else
	   wpctlg(f);

	  val = 0;
	  break;

	/* SUPSUIV */
	case SUPSUIV:
	  wfsupc(f,type_ins, 1);
	  if(scrolling)
	    {
	     for(i = pos_w+pcol-1; i < maxbuf-1; i++)
	       text[i] = text[i+1];
	     text[i] = ' ';
	     refresh(f, text, pos_w, maxbuf, ncol);
	     wposcur(f, plig, pcol);
	    }

	  val = 0;
	  break;

	/* SUPPREC */
	case SUPPREC:
	  if(scrolling)
	    {
	     if((pos_w+pcol-1) == 0)
	       {
		bell();
		val = 0;
		break;
	       }
	     else
	       if(pcol != 1)
		 pcol--;
	       else
		 {
		  for(i = pos_w+pcol-1; i < maxbuf-1; i++)
		    text[i-1] = text[i];
		  text[i] = ' ';
		  pos_w--;
		  val = 0;
		  break;
		 }

	    }
	  else
	    if(pcol == 1)
	      if(plig == 1)
		{
		 bell();
		 val = 0;
		 break;
		}
	      else
		{
		 pcol = ncol;
		 --plig;
		}
	    else
	      --pcol;

	wposcur(f,plig,pcol);

	val = SUPSUIV;
	break;

	/* INSERTION LIGNE */
	case INSLIG:
	  wfgen(f,CUROF);
	  wpseot(f,(WPTR)&plig, (WPTR)&pcol);
	  if(plig == nlig)
	    bell();
	  else
	    wfgen(f,INS_LIG);

	  wfgen(f,CURON);
	  val = 0;
	  break;

	/* SUPPRESSION LIGNE */
	case SUPLIG:
	  if(scrolling)
	     for(i = 0; i < maxbuf; text[i++] = ' ');

	  wfgen(f,SUP_LIG);
	  val = 0;
	  break;

	/* INSERTION CARACTERE */
	case INSCAR:
	  modins = (modins == TRUE)?FALSE:TRUE;

	  if(s_fc != 0)
	    {
	     wposcur(s_fc,1,pmi+1);
	     wfgen(s_fc,CUROF);
	     if(modins == TRUE)
	       wwrite(s_fc,lmi,(BPTR) (tabmes[MESINS]));
	     else
	       wfgen(s_fc,CLEOL);

	     wselect(f);
	     wposcur(f,plig,pcol);
	    }
	  val = 0;
	  break;

	/* ENVOI */
	case T_TAB:   /* Sortie sur TAB   EDS le 30/07/91 */
	case SHIFT_TAB:
	case T_ENVOI:
	  if(one_line)
	    {
	     if ( val == T_ENVOI)
	      {
		wfgen(f,CLEOL);
		*exit = RC;
	     }	
	     else
		if ( val == T_TAB)
		    *exit = TAB;
		else
		    *exit= SHIFT_TAB;	

/*	     *exit = (val == T_TAB) ? TAB : RC;*/

	     val = T_ESC;
	     break;
	    }
	  if(modins == TRUE)
	    {
	     wpseot(f,(WPTR)&j, (WPTR)&k);
	     if(k >= pcol)
	       if(j < nlig)
		 ++j;
	       else
		 {
		  bell();
		  val = 0;
		  break;
		 }

	     if(pcol == 1)
	       wfgen(f,INS_LIG);
	     else
	       wfinsc(f,type_ins,ncol-pcol+1);
	    }

	  pcol = 1;
	  wposcur(f,plig,pcol);
	  val = F_BAS;
	  break;

	/* DEFAULT */
	default:
	  if((scan_tch == TRUE) && (sffind_tch(car) != 0))
	    {
	     if(one_line)
	       wfgen(f,CLEOL);
	     *exit = car;
	     val = T_ESC;
	     break;
	    }


	  if(modins == TRUE)
	    if(scrolling)
	      if(text[maxbuf-1] != ' ')
		{
		 bell();
		 val = 0;
		 break;
		}
	      else
		{
		 for(i = maxbuf-1; i > pos_w+pcol-1; i--)
		   text[i] = text[i-1];
		 text[i] = ' ';
		 refresh(f, text, pos_w, maxbuf, ncol);
		 wposcur(f, plig, pcol);
		}
	    else
	      if((sai_er = wfinsc(f,type_ins,1)) != No_err)
		{
		 bell();
		 val = 0;
		 break;
		}
	  wwrite(f,1,(BPTR)&car);
	  /*mouse_on();*/
	  if(scrolling)
	    text[pos_w+pcol-1] = car;

	  val = F_DROITE;
	  break;

       }/*switch*/

     if(val == 0)
       {
	if(s_fc != 0)
	  {
	   mesc[pml] = plig/10;
	   mesc[pml+1] = (plig - (mesc[pml]*10)) +0x30;
	   mesc[pml] += 0x30;

	   wfgen(s_fc,CUROF);
	   wposcur(s_fc,1,pml+1);
	   wwrite(s_fc,2,(BPTR)&mesc[pml]);

	   mesc[pmc] = pcol/10;
	   mesc[pmc+1] = (pcol - (mesc[pmc]*10)) +0x30;
	   mesc[pmc] += 0x30;
	   wposcur(s_fc,1,pmc+1);

	   wwrite(s_fc,2,(BPTR)&mesc[pmc]);

	   wselect(f);
	   wposcur(f,plig,pcol);
	  }

	/* mise en attente d'un (heureux ???) evenement */

	car = 255 ;
	while((car == 255) && (val == 0))
	  {
	   if(event.event == NO_EVENT)
	     wait_eventc(SAIS_EVENTS, (EVENT_PTR)&event);
	   if(event.event == KEYBOARD)
	     {
	      car = event.arg;
	      event.event = NO_EVENT;
	     }

	   else
	     {
	      /* il faut controler que l'evenement concerne la fenetre */

	      if(get_item_mouse_list(event.plig, event.pcol) != f)
		if(mouse_m_w_down == FALSE)
		  if /*(((event.event == MOUSE_CLICK)||*/ (event.event == MOUSE_DOWN)
		    if(one_line)
		      {
		       val = T_TAB;
		       break;
		      }
		    else
		      {
		       val = T_ESC;
		       break;
		      }
		  else
		    {
		     event.event = NO_EVENT;
		     continue;
		    }

	      /* calcul de la region concernee par l'event */

	      w_use = wd->nb_col;
	      h_use = wd->nb_lig;
	      mplig = event.plig - wd->pos_lig + 1;
	      mpcol = event.pcol - wd->pos_col + 1;
	      region = INSIDE_SAIS;
	      if(mpcol <= 0)
		region = CADRE_GAUCHE;
	      else
		{
		 if(mpcol > w_use)
		   region = CADRE_DROIT;
		 else
		   if(mplig <= 0)
		     region = CADRE_HAUT;
		   else
		     if(mplig > h_use)
		       region = CADRE_BAS;
		}

	      /* suivant l'event et la region, on interprete */
	      switch(event.event)
		{
		 case MOUSE_D_CLICK:
		 case MOUSE_DOWN:
		 case MOUSE_IS_DOWN:
		   if(region == INSIDE_SAIS)
		     {
		      /* il faut se positionner */
		      wposcur(f, mplig, mpcol);
		      plig = mplig;
		      pcol = mpcol;
		     }
		   event.event = NO_EVENT;
		   break;

		 case MOUSE_UP:
		   mouse_m_w_down = FALSE;
		   event.event = NO_EVENT;
		   break;

		 case MOUSE_M_W_DOWN+M_LEFT:
		   mouse_m_w_down = TRUE;
		   if(region == CADRE_GAUCHE)
		     {
		      set_mouse_position(((mplig <= 0)?wd->pos_lig:event.plig), wd->pos_col);
		      if(scrolling == TRUE)
			val = F_GAUCHE;
		     }
		   else
		     if(region == INSIDE_SAIS)
		       {
			wposcur(f, mplig, mpcol);
			plig = mplig;
			pcol = mpcol;
		       }
		   event.event = NO_EVENT;
		   break;

		 case MOUSE_M_W_DOWN+M_RIGHT:
		   mouse_m_w_down = TRUE;
		   if(region == CADRE_DROIT)
		     {
		      set_mouse_position(((mplig > wd->pos_lig+wd->nb_lig-1)?wd->pos_lig+wd->nb_lig-1:event.plig), wd->pos_col+wd->nb_col-1);
		      if(scrolling == TRUE)
			val = F_DROITE;
		     }
		   else
		     if(region == INSIDE_SAIS)
		       {
			wposcur(f, mplig, mpcol);
			plig = mplig;
			pcol = mpcol;
		       }
		   event.event = NO_EVENT;
		   break;

		 case MOUSE_M_W_DOWN+M_UP:
		   mouse_m_w_down = TRUE;
		   if(region == CADRE_HAUT)
		      set_mouse_position(wd->pos_lig, ((mpcol <= 0)?wd->pos_col:event.pcol));
		   else
		     if(region == INSIDE_SAIS)
		       {
			wposcur(f, mplig, mpcol);
			plig = mplig;
			pcol = mpcol;
		       }
		   event.event = NO_EVENT;
		   break;

		 case MOUSE_M_W_DOWN+M_DOWN:
		   mouse_m_w_down = TRUE;
		   if(region == CADRE_BAS)
		      set_mouse_position(wd->pos_lig+wd->nb_lig-1, ((mpcol > wd->pos_col+wd->nb_col-1)?wd->pos_col+wd->nb_col-1:event.pcol));
		   else
		     if(region == INSIDE_SAIS)
		       {
			wposcur(f, mplig, mpcol);
			plig = mplig;
			pcol = mpcol;
		       }
		   event.event = NO_EVENT;
		   break;

		}/* switch(event) */

	     }/* else */

	  }/* while */


	/* on teste si touche d'echappement */
	if(val == 0)
	  {
	   if(car == sa_touche)
	     val = T_AIDE;
	   else
	     for(i = 0, val = 0; (i<MAX_TOUCHES) && (val == 0); ++i)
	       if((tc[i] == car) && (i+1 != PG_DROITE) && (i+1 != PG_GAUCHE))
		 val = i+1;
	  }
       }/*val = 0*/

    }/*while*/

    /* restituer le mode de la fenetre control */
    wd->control = memo_control;

    /* recuperation du texte saisi */

/*llb 20/09/93: Troncate si et seulement si RC */

    if(scrolling)
      {
       if (*exit == RC)    /* mise … blanc du buffer */
	   for(i = pos_w+pcol-((pcol == ncol) ? 0 : 1); i < maxbuf; text[i++] = ' ');
       /* et calcul de la taille */
       for(i = maxbuf-1; text[i] == ' ' && i >= 0; i--);
       *lgbuf = i+1;
       Wkup_out();	
#if defined(HPUX) || defined(UNIXWARE)
	if (s_fc != 0) wsup(s_fc);
#endif	
       return(OK);
      }

    if (one_line)
      {
       j = 0;
       adr_txt = (BPTR) (wd->adr_text);
       adr_txt += (ncol * bd) + (3 * bd);
       if (*exit == RC)
	  i = pcol - ((pcol == ncol) ? 0 : 1);
       else
	  i = ncol;
/*       while ( j < (pcol - ((pcol == ncol) ? 0 : 1))) */
       while ( j < i )
	 text[j] = adr_txt[j++];

       while((text[j-1] == ' ')&&(j>0))
	j--;
       *lgbuf = j;
/**       if ((pcol==ncol) && (text[j-1]==' '))
	   (*lgbuf)--;
**/
       Wkup_out();
#if defined(HPUX) || defined(UNIXWARE)
	if (s_fc != 0) wsup(s_fc);
#endif	
       return(OK);
      }

    adr_txt = (BPTR) (wd->adr_text);
    adr_txt += ncol + bd;
    wpseot(f,(WPTR)&plig, (WPTR)&pcol);

    if(s_fc != 0)
      wsup(s_fc);

    adr_txt = (BPTR) (wd->adr_text) ;
    adr_txt += (ncol*bd)+(3*bd);
    i = 1;
    j = 0;
    wpseot(f,(WPTR)&plig,(WPTR)&pcol);

    if(s_fc != 0)
      wsup(s_fc);

    lbuf = ((plig-1)*ncol) + pcol;
    lbuf = min(lbuf, maxbuf);

    j=0; i=0;
    while(j < lbuf)
      {
       text[j++] = *adr_txt++;
       i++;
       if(i == ncol)
	 {
	  adr_txt += bd+bd; /* sauter le cadre */
	  i = 0;
	 }
      }

    *(lgbuf) = j;
    Wkup_out();
    return(OK);

}/*sftxt_modc*/



/* fin de fichier */




