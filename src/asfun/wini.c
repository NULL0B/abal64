#ifndef	_wini_c
#define	_wini_c

/************************************
* Fenetrage - Intialisations        *
*-----------------------------------*
* Source : WINI.C                   *
*-----------------------------------*
* Version : 1.2a                    *
* Cibles : prologue , unix          *
* Creation    le : 28/02/1989  llb  *
* Mise a jour le : 25/01/1990   sb  *
* 		   05/11/1990  llb	adapt exadb
* 		   03/06/1991  dlr	adaptation machine non 8086 IDIRECT set_fond
*		   11.10.91    llb	wexit(), wrefresh() 	
*		   05.11.92    llb	trt couleur fimpl
*		   20.04.93    llb      caract paragraphe fond ecran
*************************************
* Fonctions                         *
*                                   *
* - winit        initialisation     *
* - wend         fin                *
* - wexit	 set ecran mode scroll
* - wrefresh	 reset ecran ASFUN
*
*************************************/

#include "fundef.h"

/* variables globales */

WORD	PRLMF;
BYTE	fen_ini = 0;	/* flag winit() effectue	*/
BYTE	edb_ini = 0;	/* flag winit() effectue par fenetre TOP */
WITEM*	WLOG[MAXFUN];	/* table des No logique fenetre */
WITEM	*avp;		/* ptr fenetre en avant plan 	*/
WITEM	*start_witem;	/*debut zone WITEM 		*/
WITEM*   *mapecran;	/* topologie fenetres sur ecran */
APP_MV2 *desc_mv2;	/* pointeur buffer travail appel MV2	*/
APP_MV2 buf_mv2;	/* buffer MV2 */
WORD	fimpl=0;	/* fenetre implicite D.L.R 		*/
WORD	sav_impl;	/* sauvegarde fenetre implicite (Debug) */
WORD 	exit_impl;	/* sauvegarde fimpl exit/refresh 	*/
WORD	MAXLIG,MAXCOL;	/* taille ecran	*/
WORD	SBARCOL;	/* Status bar columns	*/
WORD	SBARLIG;	/* Status bar line	*/
WORD	COULEUR;	/* type ecran 		*/
BYTE	ecr_txt = ' '; /* caractere fond ecran */
WORD	ecr_atb = 7;   /* attribut fond ecran */
WORD	win_coltxt = VERT;
WORD	win_colfon = NOIR;
WORD	color_impl = FALSE;

/* variables globales pour eviter les passages parametres par adresse */

WORD	gplig;		/* position ligne 	*/
WORD	gpcol;		/* position colonne	*/
WORD	gnlig;		/* nombre lignes 	*/
WORD	gncol;		/* nombre colonnes	*/

BYTE	topvis = 0;	/* flag fenetre TOP visible */

/* fonctions externes */

TYPF wsup(WORD);		/* suppression fenetre  */
TYPF emco_ini();	/* init emco */
TYPF emco_fin();	/* restitution detournement CICO */
TYPF get_cons();	/* obtenir taille ecran */		
extern void AFICAR();
extern void mv2();

WORD mem_init();
void set_fond();
static void clear_ecr();

#ifdef OSF1

/******************************************
*	Invintosf1
*******************************************

fonction d'inversion d'entiers alors que l'origine n'est pas cadree
*/

unsigned short Invintosf1(ent)
unsigned short ent;
{
	unsigned char  * pt1;
	unsigned char  * pt2;
	unsigned short res;
	pt1 = (unsigned char *) &ent;
	pt2 = (unsigned char *) &res;
	*pt2 = *(pt1+1);
	*(pt2+1) = *(pt1);
	return (res);
}


#endif

/******************************************
*	WINIT
*******************************************

fonction d'init de la runtime.
- Init chainage de superposition des fenetres
- Init mapecran
- init descripteur d'appel MV2
*/

#include "checkws.h"

TYPF winit(fonc,car,atbvid,coltxt,colfon)
BYTE fonc,car,atbvid,coltxt,colfon;
{
	WORD coder = OK;

	if ( (fen_ini != 0) && (edb_ini ==0))
	{
		/* winit deja effectuee */
		return(werr_ini);
	}

  	/* test mem_init deja effectuee */
  	if ( edb_ini == 0 )  
      		if ((coder = mem_init()) != OK)
          		return(coder);

  	if (( fonc & 8) == 8) 
	{
		fonc -= 8;
		color_impl = TRUE;
	}

	set_fond(fonc,car,atbvid,coltxt,colfon);
	return(OK);

} 

/******************************************
*	MEM_INIT()
*******************************************
- Init chainage de superposition des fenetres
- Init mapecran
 Cette fonction est appelee par winit (appel = 0) ou par WCREAT(appel=1) 
 si EXADB
*/

WORD mem_init()
{
	/* externes appeles */
	extern APP_MV2 buf_mv2;


	/* donnees internes */

	WORD i;
	WITEM*   *map_ptr;
	WITEM 	*f;

	BPTR	ptr_mv2txt;
	WPTR	ptr_mv2atb;
	WORD	surf;			/* surface max de l'ecran */

	/* debut de fonction */

	/* Alloc zone chainage de superposition */

	start_witem = (WITEM*) allouer( MAXFUN*sizeof(WITEM) );

	if (start_witem == (WITEM*)NULL)
	      return(werr_mem);

	fimpl = 0;	/* fenetre implicite */


	/* Alloc MAPECRAN */
	/* -------------  */

	get_cons();	/* => init MAXLIG , MAXCOL et COULEUR */


	surf = MAXCOL*MAXLIG;
	mapecran = (WITEM**) allouer (surf*sizeof(WITEM*));

	if (mapecran == (WITEM**)NULL)
	      return(werr_mem);

	desc_mv2 = (APP_MV2*) &buf_mv2;
	ptr_mv2txt =  f_allouer(surf);
	ptr_mv2atb =  f_allouer (2*surf);

	if ( (ptr_mv2txt == (BPTR) NULL ) || (ptr_mv2atb == (WPTR) NULL))
	      return(werr_mem);


	/* initialisation de la zone de chainage */
	/* => WITEM libre		 */
	/* Initialisation WLOG	*/

	for ( f = start_witem, i=0 ; i < MAXFUN ; f++,i++)
	{
		f->mere  = (WITEM*)NULL;
		f->fsur  = (WITEM*)NULL;
		f->fsous = (WITEM*)NULL;
		f->fille = (WITEM*)NULL;
		WLOG[i] =  f ;
	}

	/* initialisation de mapecran (RAZ) */

	for ( map_ptr = mapecran ; map_ptr < (mapecran+surf) ; map_ptr++)
	       *map_ptr = (WITEM*)NULL ;

 	/* initialisation emulation CO */

	if ( emco_ini() != OK)
		return(werr_ini);

	desc_mv2->adr_text = ptr_mv2txt;
	desc_mv2->adr_atb  = ptr_mv2atb;

	desc_mv2->std_text = ptr_mv2txt;
	desc_mv2->std_atb  = ptr_mv2atb;

	desc_mv2->ln_desc = sizeof(APP_MV2);	/* init taille desc_mv2 */
	desc_mv2->ncons   = NULL;
	desc_mv2->reserve = NULL;
	fen_ini = 1;

	return(OK);
}

/******************************************
*	SET_FOND()
*******************************************
- positionnement fond d'ecran
*/

void set_fond(fonc,car,atbvid,coltxt,colfon)
BYTE	fonc;
BYTE	car;
BYTE	atbvid;
BYTE	coltxt;
BYTE	colfon;

{
	BPTR	ptr_mv2txt;

	/* Traitement parametres d'appel:

		fonc = 0 : rien
		       1 : clear ecran
		       2 : fill
		       4 : curseur OFF
		       8 : sauvegarde ecran (non implemente)
	*/

	/* blocage scroll ecran PRINCIPAL SEULEMENT */


    	ptr_mv2txt =  desc_mv2->adr_text;

    	if (fonc&2) 
	{
#ifdef PRL
		/* llb 20/04/93 */
		if ((PRLMF)&&(car == 0xd2))
			car = 0x15;
#endif
        	*ptr_mv2txt = car;	
#ifdef IDIRECT
        	*(ptr_mv2txt + 1) = ((colfon<<4)+coltxt) ;
        	*(ptr_mv2txt + 2) = atbvid ;
        	ecr_atb =  *(ptr_mv2txt+1);	
#else
        	*(ptr_mv2txt + 2) = ((colfon<<4)+coltxt) ;
        	*(ptr_mv2txt + 1) = atbvid ;
        	ecr_atb =  *(ptr_mv2txt+2);	
#endif 

		win_coltxt = ecr_atb&0x0f;
		win_colfon = ecr_atb>>4;

        	ecr_txt =  car;
     	}

	AFICAR(ESCAPE);
  	AFICAR('u');

    	if (topvis==0) {

		// test for clear screen option
		if (fonc&1)
		{
        		AFICAR(0x0c);
		}

		// test for hide cursor option
		if (fonc&4)  
		{
            		desc_mv2->nfonc = HIDECUR;
            		mv2(desc_mv2);
    		}

		// test for fill screen option
		if (fonc&2)   
		{	
        		desc_mv2->nfonc = FILL;
			desc_mv2->inc_buf = 3;
			desc_mv2->mvlig = 1;
			desc_mv2->mvcol = 1;
			desc_mv2->mvnblig = MAXLIG;
			desc_mv2->mvnbcol = MAXCOL;
			mv2(desc_mv2);
    		}
    	}
}

/******************************************
*	WEND()
*******************************************
trt: supprimer toutes les fenetres crees
*/

TYPF wend()
{
	extern APP_MV2 * desc_mv2;
	int 	  nlog;
	WITEM 	  *wi;
	WDESC_PTR wd;

	/* check if windows are active */

	if (fen_ini == 0) return(werr_ini);

	for ( nlog = 0 ; nlog < MAXFUN ; nlog++)
	{
		if ( WLOG[nlog]->mere != (WITEM*)NULL )  
		{
			wi = WLOG[nlog];
			wd = wi->wdesc_ptr;
        		if (!(wd->control & TOP))
	    			wsup(nlog+1);
		}
	}

	/* liberer contexte EMCO */

	if (edb_ini == 0)  
	{
		emco_fin();

		desc_mv2->nfonc = SHOWCUR;
		mv2(desc_mv2);

		clear_ecr();

		fen_ini = 0;			/* RAZ flag INIT */

		libere(start_witem);
		libere(mapecran);

		f_libere(desc_mv2->adr_text);
	
		f_libere(desc_mv2->adr_atb);

	}

	return(OK);

} 

/*	---------	*/
/*	clear_ecr	*/
/*	---------	*/
static void clear_ecr()
{
	 AFICAR(ESCAPE);
	 AFICAR('t'); 			 /* mode scroll */
#ifdef PROL
	 AFICAR(ESCAPE);		/* se positionner sur ligne 25 	*/
	 AFICAR('f');
	 AFICAR(0x20);			/* colonne 1 */
	 AFICAR(0X20+24); 		/* LIGNE 25 */
	 AFICAR(ESCAPE);
	 AFICAR('a');
	 AFICAR(0x0c);
	 AFICAR(ESCAPE);		/* se positionner sur ligne 1 */
	 AFICAR('f');
	 AFICAR(0x20);			/* colonne 1 */
	 AFICAR(0X20); 			/* ligne 1   */
#endif
	AFICAR(ESCAPE);
	AFICAR('a');
	AFICAR(0x0c);			/* clear ecran */
	return;
} 

/******************************************
*	WEXIT()
*******************************************
trt: positionner l'ecran en mode scroll 
Clear ecran si code = 1
*/

TYPF	wexit(code)
WORD	code;
{
	/* This function requires that winit or sf_init has been performed */
	/* --------------------------------------------------------------- */
	if (fen_ini == 0)	return(werr_ini);

	/* Apparantly WINIT or SF_INT has occured */
	/* -------------------------------------- */
	exit_impl = fimpl;	fimpl = 0;		

	if ( code == 1 )
		clear_ecr();	

	else if ( code == 0 ) 
	{
		/* mode scroll */
		AFICAR(ESCAPE);
		AFICAR('t'); 
	}

	desc_mv2->nfonc = SHOWCUR;
	mv2(desc_mv2);	
	return(NULL);
}

/******************************************
*	WREFRESH()
*******************************************
trt: 	positionner l'ecran en mode page 
	afficher image ASFUN
*/

TYPF	wrefresh()
{

WITEM		*wt;
WDESC_PTR	wd;

	/* This function requires that winit or sf_init has already been performed */
	/* ----------------------------------------------------------------------- */
	if (fen_ini == 0) return(werr_ini);

	/* restituer fenetre implicite */
	fimpl = exit_impl;	
	
	/* eteindre le curseur */
	desc_mv2->nfonc = HIDECUR;
        mv2(desc_mv2);		

	/* set ecran en mode page */
	AFICAR(ESCAPE);
	AFICAR('u');		

	/* affiche image */
	show_rect(1,1,MAXLIG,MAXCOL);	

      	/* repositionner les ombres eventuellement effacees */
	if ( avp != (WITEM*)NULL)
	{
		wt = avp;
	  	while ( wt != (WITEM*) NULL )
	    	{
	       		wd = wt->wdesc_ptr;
	       		if (( wd->control & OMBRE)&&(!(wd->control & INVISIBLE)))
				set_ombre(wt);
		 	wt = wt->fsous;
	  	}
	}

	if (avp != (WITEM*)NULL)  
	{	
		/* positionner curseur sur F AVP */
		wd = avp->wdesc_ptr;
     		if (( wd->cur != 0 ) && (!(wd->control & INVISIBLE)))
		{
			/* positionner curseur ecran */
	        	desc_mv2->ncons = 0;	
	        	desc_mv2->nfonc = POSCUR;
	            	desc_mv2->mvlig = wd->pos_lig + wd->cur_lig - 1 ;
       		    	desc_mv2->mvcol = wd->pos_col + wd->cur_col - 1 ;
       		    	mv2(desc_mv2);		
			/* activate curseur */
         	    	desc_mv2->nfonc = SHOWCUR;
         	    	mv2(desc_mv2);		
       		}
	}
	return(NULL);
} 

#endif	/* _wini_c */

