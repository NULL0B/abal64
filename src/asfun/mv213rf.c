/*
 *	CICO - Interface ECRAN / CLAVIER / IMPRIMANTE
 *	---------------------------------------------
 *
 *	Copyright (c) 2021 Amenesik / Sologic
 *
 *	mv2.c - fonctions interface ecran/clavier/imprimante
 *
 *     maj llb 23.07.92 fill_atb
 *	   llb 02.04.93 convertion caractere paragraphe
 * 	
 *	$Header: /home/Produits/Abal3/asfun/mv213rf.c,v 1.1.1.1 2003/11/04 23:40:49 root Exp $
 *
 */


#include "cico.h"
#include "_cico.h"
#include "fundef.h"

#ifdef CICO_DEBUG
#include <stdio.h>
extern FILE *DEBUG;
#endif /* fin CICO_DEBUG */

/*
 *	declaration des variables de CICO
 *	---------------------------------
 */

extern  WITEM*	*mapecran;
extern	BYTE	ecr_txt;
extern	APP_MV2 buf_mv2;

extern BOOL flag_couleur;
extern BYTE max_ligne;
extern BYTE max_colonne;
extern BYTE nb_ligne;
extern BYTE nb_colonne;
extern ecran_st *courant;

#ifdef MSDOS
extern BOOL flag_bios;
extern BYTE _page;

#ifdef dosext
/* Pour DOS mode protege */
#define HWO(x)	((x >> 8) & 0x00FF)
#define LWO(x)	(x & 0x00FF)
#pragma pack(1)
typedef struct {
	BYTE ah;
	BYTE al;
	BYTE bh;
	BYTE bl;
	BYTE ch;
	BYTE cl;
	BYTE dh;
	BYTE dl;
} AREG;
#define ARNULL	((AREG FAR *)0L)
#define AREF(x)	((AREG FAR *)&x)
extern void far int10(AREG far *,AREG far *);
#endif /* Fin DOS mode protege */
#endif /* MSDOS */

/*
 *	declaration des fonctions de CICO
 *	---------------------------------
 */

extern VOID _co_start(VOID);
extern VOID _co_flush(VOID);
extern VOID _co_pos(WORD, WORD);
extern VOID _co_cursor(BOOL);
extern VOID _co_conv(WORD);
extern VOID _co_out(WORD);
extern VOID _co_attribut(WORD);
extern VOID _co_couleur_texte(WORD);
extern VOID _co_couleur_fond(WORD);

#ifdef MSDOS
extern VOID _mapcpy(WORD FAR *, WORD FAR *, WORD);
extern VOID _maprcpy(WORD FAR *, WORD FAR *, WORD);
#endif /* MSDOS */


/*
 *	declaration des fonctions
 *	-------------------------
 */

static VOID _mv2_affiche();
static VOID _mv2_fill();
static VOID _mv2_attribut();
static VOID _mv2_scroll();
static VOID _mv2_filatb();


/* mv2 - traitement des appels MultiVue 2
 * --------------------------------------
 *
 * appel:	int mv2(desc);
 *		APP_MV2 *desc = descripteur d'appel
 *
 * retour:	non traite
 *
 */
WORD mv2(desc)
APP_MV2 *desc;
{
	_co_start();
	switch (desc->nfonc) {
	case AFFICHE:
		_mv2_affiche(desc);
		break;
	case POSCUR:
		courant->ligne = desc->mvlig - 1;
		if (courant->ligne > max_ligne)
			courant->ligne = max_ligne;
		courant->colonne = desc->mvcol - 1;
		if (courant->colonne > max_colonne)
			courant->colonne = max_colonne;
		_co_pos(courant->ligne, courant->colonne);
		break;
	case SETCUR:
		break;
	case SHOWCUR:
		_co_cursor(TRUE);
		break;
	case HIDECUR:
		_co_cursor(FALSE);
		break;
	case FILL:
		_mv2_fill(desc);
		break;
	case GSCROLL:
		_mv2_scroll(desc);
		break;
	case SETATB:
		_mv2_filatb(desc);
		break;
	case SPEC:
		break;
	}
	_co_flush();

	return (0);
}

/* _mv2_affiche - traitement de la fonction AFFICHE de MultiVue 2
 * --------------------------------------------------------------
 *
 * appel:	static VOID _mv2_affiche(desc);
 *		APP_MV2 *desc = descripteur d'appel
 *
 * retour:	rien
 *
 */
static VOID _mv2_affiche(desc)
APP_MV2 *desc;
{
	WORD ligne, colonne;
	BYTE FAR *caractere;
	WORD FAR *attribut;
	WORD trace;
	WORD increment;

#ifdef CICO_DEBUG
	printf(DEBUG,"AFFICHE\n");
#endif /* fin CICO_DEBUG */

	caractere = desc->adr_text;
	attribut = desc->adr_atb;
	increment = desc->inc_buf - desc->mvnbcol;
	_mv2_attribut(trace = *attribut);
	for (ligne = desc->mvlig - 1; ligne < desc->mvlig - 1 + desc->mvnblig; ligne++) {
		colonne = desc->mvcol - 1;
#ifdef MSDOS
		courant->ligne = ligne;
		courant->colonne = colonne;
#endif /* MSDOS */
		_co_pos(ligne, colonne);
		for (; colonne < desc->mvcol - 1 + desc->mvnbcol; colonne++) {
			if (*attribut != trace)
				_mv2_attribut(trace = *attribut);
			attribut++;
#ifdef MSDOS
			_co_pos(ligne, colonne);

/* convertion caractere paragraphe  */
 
			if (*caractere == 0xD2)
				*caractere = 0x15;
			if (*caractere == 0xEF)
				*caractere = 0xD2;
/* fin convertion 02.04.93 */
			_co_out(*caractere++);
			courant->colonne++;
#else
			if (ligne != max_ligne || colonne != max_colonne)
				_co_conv(*caractere++);
#endif /* MSDOS */
		}
		caractere += increment;
		attribut += increment;
	}
}


/* _mv2_fill - traitement de la fonction FILL de MultiVue 2
 * --------------------------------------------------------
 *
 * appel:	static VOID _mv2_fill(desc);
 *		APP_MV2 *desc = descripteur d'appel
 *
 * retour:	rien
 *
 */
static VOID _mv2_fill(desc)
APP_MV2 *desc;
{
	WORD ligne, colonne;
	WORD caractere;

	caractere = *desc->adr_text;
	_mv2_attribut(*(WORD FAR *)(desc->adr_text + 1));
	for (ligne = desc->mvlig - 1; ligne < desc->mvlig - 1 + desc->mvnblig; ligne++) {
		colonne = desc->mvcol - 1;
#ifdef MSDOS
		courant->ligne = ligne;
		courant->colonne = colonne;
#endif /* MSDOS */
	_co_pos(ligne, colonne);
		for (; colonne < desc->mvcol - 1 + desc->mvnbcol; colonne++) {
#ifdef MSDOS
			_co_pos(ligne, colonne);

/* convertion caractere paragraphe */

			if (caractere == 0xD2)
				caractere = 0x15;
			if (caractere == 0xEF)
				caractere = 0xD2;
/* fin convertion 02.04.93 */
			_co_out(caractere);
			courant->colonne++;
#else
			if (ligne != max_ligne || colonne != max_colonne)
				_co_conv(*desc->adr_text);
#endif /* MSDOS */
		}
	}
}


/* _mv2_scroll - traitement de la fonction SCROLL de MultiVue 2
 * ------------------------------------------------------------
 *
 * appel:	static VOID _mv2_scroll(desc);
 *		APP_MV2 *desc = descripteur d'appel
 *
 * retour:	rien
 *
 */
static VOID _mv2_scroll(desc)
APP_MV2 *desc;
{
#ifdef dosext
   AREG x;
#endif

	WORD ligne, colonne;
	WORD nombre;
	WORD direction;
	WORD mot;
	BYTE ligne_debut, ligne_fin, colonne_debut, colonne_fin;
	WORD ligne_nombre, colonne_nombre;

	nombre = *(WORD FAR *)desc->adr_text;
	direction = *((WORD FAR *)desc->adr_text + 1);
	ligne_nombre = desc->mvnblig;
	ligne_debut = desc->mvlig - 1;
	ligne_fin = ligne_debut + ligne_nombre - 1;
	colonne_nombre = desc->mvnbcol;
	colonne_debut = desc->mvcol - 1;
	colonne_fin = colonne_debut + colonne_nombre - 1;

	switch (direction) {
	case HAUT:
#ifdef MSDOS
		if (flag_bios == TRUE) {
#ifndef dosext
			_asm {
				mov	ah,06h
				mov	al,nombre
				mov	bh,07h
				mov	ch,ligne_debut
				mov	cl,colonne_debut
				mov	dh,ligne_fin
				mov	dl,colonne_fin
				int	10h
			}
#else
			x.ah = 0x06;
			x.al = nombre;
			x.bh = 0x07;
			x.ch = ligne_debut;
			x.cl = colonne_debut;
			x.dh = ligne_fin;
			x.dl = colonne_fin;
			int10(AREF(x),ARNULL);
#endif
		}
		for (ligne = ligne_debut; ligne <= ligne_fin - nombre; ligne++) {
			_mapcpy(courant->image + ligne * nb_colonne + colonne_debut, courant->image + (ligne + nombre) * nb_colonne + colonne_debut, colonne_nombre);
		}
#else

#endif /* MSDOS */
		break;
	case BAS:
#ifdef MSDOS
		if (flag_bios == TRUE) {
#ifndef dosext
			_asm {
				mov	ah,07h
				mov	al,nombre
				mov	bh,07h
				mov	ch,ligne_debut
				mov	cl,colonne_debut
				mov	dh,ligne_fin
				mov	dl,colonne_fin
				int	10h
			}
#else
			x.ah = 0x07;
			x.al = nombre;
			x.bh = 0x07;
			x.ch = ligne_debut;
			x.cl = colonne_debut;
			x.dh = ligne_fin;
			x.dl = colonne_fin;
			int10(AREF(x),ARNULL);
#endif
		}
		for (ligne = ligne_fin - nombre; ligne >= ligne_debut; ligne--) {
			_mapcpy(courant->image + (ligne + nombre) * nb_colonne + colonne_debut, courant->image + ligne * nb_colonne + colonne_debut, colonne_nombre);
		}
#else

#endif /* MSDOS */
		break;
	case DROITE:
#ifdef MSDOS
		for (ligne = ligne_debut; ligne <= ligne_fin; ligne++) {
			if (flag_bios == TRUE) {
				for (colonne = colonne_fin - nombre; colonne >= colonne_debut; colonne--) {
#ifndef dosext
					_asm {
						mov	ah,02h
						mov	bh,_page
						mov	dh,ligne
						mov	dl,colonne
						add	dl,nombre
						int	10h
					}
#else
					x.ah = 0x02;
					x.bh = _page;
					x.dh = ligne;
					x.dl = colonne+nombre;
					int10(AREF(x),ARNULL);
#endif

					mot = *(courant->image + ligne * nb_colonne + colonne);

#ifndef dosext
					_asm {
						mov	ax,[mot]
						mov	bl,ah
						mov	bh,_page
						mov	cx,1
						mov	ah,09h
						int	10h
					}
#else
					x.ah = 0x09;
					x.al = LWO(mot);
					x.bl = HWO(mot);
					x.bh = _page;
					x.ch = 0;
					x.cl = 1;
					int10(AREF(x),ARNULL);
#endif
				}
			}
			_maprcpy(courant->image + ligne * nb_colonne + colonne_debut + nombre, courant->image + ligne * nb_colonne + colonne_debut, colonne_nombre - nombre);
		}
#else

#endif /* MSDOS */
		break;
	case GAUCHE:
#ifdef MSDOS
		for (ligne = ligne_debut; ligne <= ligne_fin; ligne++) {
			if (flag_bios == TRUE) {
				for (colonne = colonne_debut + nombre; colonne <= colonne_fin; colonne++) {
#ifndef dosext
					_asm {
						mov	ah,02h
						mov	bh,_page
						mov	dh,ligne
						mov	dl,colonne
						sub	dl,nombre
						int	10h
					}
#else
					x.ah = 0x02;
					x.bh = _page;
					x.dh = ligne;
					x.dl = colonne-nombre;
					int10(AREF(x),ARNULL);
#endif

					mot = *(courant->image + ligne * nb_colonne + colonne);

#ifndef dosext
					_asm {
						mov	ax,[mot]
						mov	bl,ah
						mov	bh,_page
						mov	cx,1
						mov	ah,09h
						int	10h
					}
#else
					x.ah = 0x09;
					x.al = LWO(mot);
					x.bl = HWO(mot);
					x.bh = _page;
					x.ch = 0;
					x.cl = 1;
					int10(AREF(x),ARNULL);
#endif
				}
			}
			_mapcpy(courant->image + ligne * nb_colonne + colonne_debut, courant->image + ligne * nb_colonne + colonne_debut + nombre, colonne_nombre - nombre);
		}
#else

#endif /* MSDOS */
		break;
	}
}


/* _mv2_attribut - decodage d'un attribut de MultiVue 2
 * ----------------------------------------------------
 *
 * appel:	static VOID _mv2_attribut(mot);
 *		WORD mot = attribut
 *
 * retour:	rien
 *
 */
static VOID _mv2_attribut(mot)
WORD mot;
{
	BYTE attribut;
	BYTE texte;
	BYTE fond;

	attribut = mot >> 8;		/* attribut	    */
	texte = mot & 0x000f;		/* couleur de texte */
	fond = (mot & 0x00ff) >> 4;	/* couleur de fond  */
	_co_attribut(A_NORMAL);
	if (flag_couleur == FALSE) {
		if (attribut & VIDEO)
			_co_attribut(A_REVERSE);
		if (attribut & CLIGNOT)
			_co_attribut(A_BLINK);
		if (attribut & SOULIGNE)
			_co_attribut(A_UNDERLINE);
		if (attribut & SOUSINT)
			_co_attribut(A_DIM);
		if (attribut & SURINT)
			_co_attribut(A_BOLD);
	} else {
		if (attribut & CLIGNOT) {
			_co_couleur_texte(texte);
			_co_couleur_fond(fond);
			_co_attribut(A_BLINK);
		} else {
			_co_attribut(A_NORMAL);
			_co_couleur_texte(texte);
			_co_couleur_fond(fond);
		}
	}
}/*_mv2_attribut*/

/* _mv2_filatb  - remplissage zone avec un attribut 
 * ------------------------------------------------
 * appel:	static VOID _mv2_filatb(desc);
 *		APP_MV2 *desc = descripteur d'appel
 *
 * retour:	rien
 *
 

   traitement: emulation de SETATB
	fabrique la fonction AFFICHE avec les attributs et
	les coordonnees passes.
	Recherche des caracteres correspondant aux coordonnees passees.
	Utilisation du descripteur public desc_mv2.
*/


static VOID _mv2_filatb(desc)
 APP_MV2  *desc;
 {
 WDESC_PTR w;
 WITEM	*f,*t;
 WORD	l,c,lf,cf,bd;
 WORD	i,cpt,attrib;
 WORD	plig,pcol,nlig,ncol;
 BPTR   mv2_text;
 WPTR   mv2_atb;
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


 mv2_atb = buf_mv2.adr_atb;
 for ( l = 0 ; l < nlig*ncol ; l++ )
	*mv2_atb++ = attrib;

/* wwmemset(buf_mv2.adr_atb, attrib , nlig * ncol );	attribut */


/* pour chaque point du rectangle, copie du texte de la fenetre
   correspondante dans APP_MV2
*/

 mv2_text = buf_mv2.adr_text;


for ( l = plig; l < plig + nlig ; l++)
  {
   c = pcol;
   while ( c < pcol+ncol)
    {
     f = *(mapecran + ((max_colonne+1)*(l-1)) + (c-1) );
     cpt = 0;
     t = f;

/* calcul nbre colonnes meme fenetre */
     while (( t == f ) && ( c < pcol+ncol))
      {
       cpt++;
       t = *(mapecran + ((max_colonne+1)*(l-1)) + (++c -1) );
      }

     if ( f == (WITEM*)NULL )			/* fond ecran */
	  {
	    for ( lf = 0 ; lf < cpt ; lf++)
		*mv2_text++ = ecr_txt;
     }
     else
	  {
	    w = f->wdesc_ptr;
	    bd = w->cad;
	    ftext = w->adr_text;
	    lf = l - w->pos_lig + bd;		 /* ligne relative fenetre */
	    cf = ( c - cpt ) - w->pos_col +bd;	 /* colonne	 "         */



/* recopie texte 
	    wmemcpy( mv2_text , (ftext + ((w->nb_col+(2*bd))*lf) + cf),cpt );
	    mv2_text += cpt;
*/

/* recopie texte */
	    for ( i = 0; i < cpt; i++)
		*mv2_text++ = *( (ftext + ((w->nb_col+(2*bd))*lf)+cf+i) );

	   } /* else */
    } /* while c<pcol+ncol */

  } /* for l */
 _mv2_affiche(&buf_mv2); /* appel "MV2" (affichage) */
 return;

}/*_mv2_filatb*/

/* fin de fichier */

#ifndef AIX_VERS

#else /* AIX_VERS */

#endif /* AIX_VERS */
