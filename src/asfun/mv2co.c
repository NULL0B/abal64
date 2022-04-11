/**********************************************
* fichier:	MV2CO.C
* description: Fonction MV2
*
* creation:	06.03.89 llb
* maj		08.11.89
*
* version 1.3a	26.12.1991 llb mv2(SETATB)
		
**********************************************/

#include "fundef.h"

extern	void AFICAR();
extern	WORD COULEUR;
extern	WORD PRLMF;		/* flag systeme MF */

extern  WORD	MAXCOL;
extern	APP_MV2	buf_mv2;
extern  WITEM*	*mapecran;
extern	BYTE	ecr_txt;


extern void mv2_mf(APP_MV2 *);

int	mv2(desc)
APP_MV2 *desc;
{
 if (PRLMF)
   mv2_mf(desc);		/* appel direct relais MF */
 else
	/* emulation CO classique */

  switch (desc->nfonc)
  {
   case AFFICHE: affiche(desc);
		 break;

   case POSCUR:  poscur(desc);
		 break;

   case SHOWCUR: AFICAR(ESCAPE);
		 AFICAR('v');
		 break;

   case HIDECUR: AFICAR(ESCAPE);
		 AFICAR('w');
		 break;

   case FILL:	fill(desc);
		break;

   case SETATB:	fill_atb(desc);
		break;	

  }

 }/*mv2*/

/********************************
*	AFFICHE 		*
********************************/

int affiche(desc)
APP_MV2 *desc;
{
 WORD	l,c;
 BPTR	text;
 WPTR   atb;
 WORD	trace;
 WORD	inc_buffer;

 text =  desc->adr_text;
 atb  =  desc->adr_atb;
 inc_buffer = desc->inc_buf - desc->mvnbcol;
 trace = *(atb);
 setatb(0);
 setatb(trace);

 for ( l = desc->mvlig ; l < desc->mvlig + desc->mvnblig ; l ++)
   {
    c = desc->mvcol;
    posit(l,c); /* positionnement en debut de ligne */

    for (  ; c < desc->mvcol+desc->mvnbcol ; c++)
      {
	if ( *atb != trace )
	   {
	    setatb(0);			/* reset attributs */
	    setatb(*atb);		 /* set nouvel attribut */
	    trace = *atb;
	   }
	atb++;
	AFICAR(*text++);
      }
    text += inc_buffer;
    atb  += inc_buffer;

   }/* for l = */
} /* affiche */

/********************************
*	POSCUR			*
********************************/

int	poscur(desc)
APP_MV2 *desc;
{
 WORD	l,c;
 l = desc->mvlig;
 c = desc->mvcol;
 AFICAR(ESCAPE);
 AFICAR('f');
 AFICAR( (char)c + 0x1f);
 AFICAR( (char)l + 0x1f);
}/*poscur*/


/********************************
*	FILL			*
********************************/
int fill(desc)
APP_MV2  *desc;
{
 WORD	l,c;
 BPTR	text;
 WPTR	atb;

 text = desc->adr_text;
 setatb(0);
 setatb(*(text+1));

 for ( l = desc->mvlig ; l < desc->mvlig + desc->mvnblig ; l ++)
   {
    c = desc->mvcol;
    posit(l,c); /* positionnement en debut de ligne */

    for (  ; c < desc->mvcol+desc->mvnbcol ; c++)
	AFICAR(*text);
   }/*for l*/
}/* fill */

/********************************
*	ROUTINES		*
********************************/

int posit(l,c)

WORD l,c;
{
 AFICAR(ESCAPE);
 AFICAR('f');
 AFICAR( (char)c + 0x1f);
 AFICAR( (char)l + 0x1f);
 }/*posit*/



int setatb(atb)
WORD atb;
{
 BYTE	colt,colf,vid;


 vid = atb>>8;			/* attribut video */
 colt = atb & 15;		/* couleur texte  */
 colf = (BYTE)atb>>4;		/* couleur fond   */

/* video d'abord */

if ( COULEUR == 0 )
  {
   if ( vid == 0)
     {	AFICAR(ESCAPE) ; AFICAR('a'); }
   if  (vid & VIDEO)
     { AFICAR(ESCAPE) ; AFICAR('b'); }
   if  (vid & CLIGNOT)
     { AFICAR(ESCAPE) ; AFICAR('c'); }
   if  (vid & SOULIGNE)
     { AFICAR(ESCAPE) ; AFICAR('d'); }
   if ( vid & SOUSINT )
     { AFICAR(ESCAPE) ; AFICAR('e'); }
   if ( vid & SURINT)
     { AFICAR(ESCAPE) ; AFICAR('h'); }
  }
/* la couleur */

 else
  {
       if ( vid & CLIGNOT )
	 { AFICAR(ESCAPE) ; AFICAR('c'); }
       else
	 { AFICAR(ESCAPE) ; AFICAR('a'); } /*reset clignotant */
       AFICAR(ESCAPE);
       AFICAR('s');
       AFICAR( (colf<10) ? (colf+0x30) : colf+55 );	/* couleur fond */

       AFICAR(ESCAPE);
       AFICAR('r');
       AFICAR( (colt<10) ? (colt+0x30) : colt+55 );	/* couleur TEXTE */

   } /* COULEUR */
}/* setatb()*/

#ifdef PROL 
void bell()
{
 AFICAR(7);
}
#endif


/********************************
*	FILL_ATB		*
********************************/
/* trt: emulation de SETATB
	fabrique la fonction AFFICHE avec les attributs et
	les coordonn‚es pass‚s.
	Recherche des caractŠres correspondant aux coordonn‚es pass‚es.
	Utilisation du descripteur public desc_mv2.
*/


 int fill_atb(desc)
 APP_MV2  *desc;
 {
 WDESC_PTR w;
 WITEM	*f,*t;
 WORD	l,c,lf,cf,bd;
 WORD	i,cpt,attrib;
 WORD	plig,pcol,nlig,ncol;
 BPTR   mv2_text;
 BPTR   ftext;

 /* preparation descripteur appel MV2 */

 buf_mv2.nfonc   = AFFICHE;
 buf_mv2.inc_buf = desc->mvnbcol;
 attrib = *(WPTR)desc->adr_text;


 buf_mv2.adr_text = buf_mv2.std_text;
 buf_mv2.adr_atb = buf_mv2.std_atb;

 /* init var locales */

 plig = desc->mvlig;
 pcol = desc->mvcol;
 nlig = desc->mvnblig;
 ncol = desc->mvnbcol;

 buf_mv2.mvlig = plig;
 buf_mv2.mvcol = pcol;
 buf_mv2.mvnblig = nlig;
 buf_mv2.mvnbcol = ncol;


 wwmemset(buf_mv2.adr_atb, attrib , nlig * ncol );	/* attribut */


/* pour chaque point du rectangle, copie du texte de la fenetre
   correspondante dans APP_MV2
*/

 mv2_text = buf_mv2.adr_text;

for ( l = plig; l < plig + nlig ; l++)
  {
   c = pcol;
   while ( c < pcol+ncol)
    {
     f = *(mapecran + (MAXCOL*(l-1)) + (c-1) );
     cpt = 0;
     t = f;

/* calcul nbre colonnes meme fenetre */
     while (( t == f ) && ( c < pcol+ncol))
      {
       cpt++;
       t = *(mapecran + (MAXCOL*(l-1)) + (++c -1) );
      }

     if ( f == (WITEM*)NULL )			/* fond ecran */
	  {
	    wmemset(mv2_text, ecr_txt, cpt);		/* texte */
	    mv2_text += cpt;
     }
     else
	  {
	    w = f->wdesc_ptr;
	    bd = w->cad;
	    ftext = w->adr_text;
	    lf = l - w->pos_lig + bd;		 /* ligne relative fenetre */
	    cf = ( c - cpt ) - w->pos_col +bd;	 /* colonne	 "         */

/* recopie texte */
	    wmemcpy( mv2_text , (ftext + ((w->nb_col+(2*bd))*lf) + cf),cpt );
	    mv2_text += cpt;

	   } /* else */
    } /* while c<pcol+ncol */

  } /* for l */
 mv2(&buf_mv2); /* appel "MV2" (affichage) */
 return(OK);

}/*fill_atb*/

/* fin de fichier */
