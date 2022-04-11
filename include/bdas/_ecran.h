/*
 *
 *	File		:	_ECRAN.H
 *	Date		:	05/10/2001
 *	Who		:	Iain James Marshall
 *	What		:	Description of the CICO screen structure
 *	Why		:	Removed form _CICO.H to allow it to be
 *				shared by those that don't want _CICO.H
 *
 */


#ifndef	_ecran_h
#define	_ecran_h

/*
 *	structures de description d'ecran
 *	---------------------------------
 */

#ifndef MSDOS
typedef struct {
	BYTE *caractere;		/* caracteres			*/
	BYTE *attribut; 		/* attributs			*/
	BYTE *fond;			/* couleur de fond		*/
	BYTE *texte;			/* couleur de texte		*/
} image_st;
#endif /* MSDOS */



typedef struct ecran_struct {
	struct ecran_struct *suite;	/* ecran suivant		*/
#ifdef MSDOS
	WORD FAR *image;		/* image ecran			*/
#else
	image_st image; 		/* image ecran			*/
#endif /* MSDOS */
	BYTE ligne;			/* position ligne		*/
	BYTE colonne;			/* position colonne		*/
	BYTE jeu;			/* jeu de caractere		*/
	BYTE etat;			/* etat de l'automate           */
	BYTE attribut;			/* attribut courant		*/
#ifndef MSDOS
	BYTE fond;			/* couleur de fond		*/
	BYTE texte;			/* couleur de texte		*/
#endif /* MSDOS */
#ifdef ABALCONF
	BYTE def_char;			/* couleur de car par defaut	*/
	BYTE def_back;			/* couleur de fond par defaut	*/
#else
	BYTE defaut;			/* couleur par defaut		*/
#endif /* ABALCONF */
} ecran_st;

#endif	/* _ecran_h */

