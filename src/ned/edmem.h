/*---------------------------------------------------------------EDNOY.H -----
 *
 *	Editeur de textes ABAL	  -	Copyright Amenesik / Sologic s.a. (c) 1989
 *
 *		   Definitions du noyau de l'editeur
 *
 *		      Revision 2.K du 20/03/2000
 *
 *--------------------------------------------------------------------------*/

#ifndef	_edmem_h
#define	_edmem_h

#ifdef	ver2K
#define	ver2Kalloc
#define	verGraphic
/* On change ces deux ci a fin de permettre comme meme pas mal de plus */

#define NBMXLIG	64	/* nb max de lignes montees en memoire */
#ifdef	PROLOGUE
#define _LGLIGNE 640  	/* lg max d'une ligne en memoire */
#else
#define _LGLIGNE 2048  	/* lg max d'une ligne en memoire */
#endif
#else

#define NBMXLIG	24	/* nb max de lignes montees en memoire */
#define LGLIGNE 320 	/* lg max d'une ligne en memoire */

#endif

#ifdef	ver2Kalloc

#ifdef	_edvideo_c
/* global */ WORD   LGLIGNE=_LGLIGNE;		/* _LGLIGNE */
/* global */ BYTE * AedMemory=(BYTE *) 0;	/* [NBMXLIG][LGLIGNE]; 	*/
/* global */ BYTE * lgntemp=(BYTE *) 0;		/* [LGLIGNE];		*/
#else
extern WORD   LGLIGNE;		/* _LGLIGNE */
extern BYTE * AedMemory;	/* [NBMXLIG][LGLIGNE]; 	*/
extern BYTE * lgntemp;		/* [LGLIGNE];		*/

#endif

#define	adrmemlin(nblin) 	(BYTE *) (AedMemory + ((nblin) * LGLIGNE))
#define	adrmemcol(nblin,nbcol) 	(BYTE *) (AedMemory + ((nblin) * LGLIGNE) + (nbcol))

#define	getmemchar(nblin,nbcol) *(AedMemory + ((nblin) * LGLIGNE) + (nbcol))
#define	putmemchar(nblin,nbcol,character) *(AedMemory + ((nblin) * LGLIGNE) + (nbcol)) = (character)

#else

/* global */ BYTE mem[NBMXLIG][LGLIGNE];
/* global */ BYTE lgntemp[LGLIGNE];

#define	adrmemlin(nblin) 	mem[nblin]
#define	adrmemcol(nblin,nbcol) 	&mem[nblin][nbcol]

#define	getmemchar(nblin,nbcol) mem[nblin][nbcol]
#define	putmemchar(nblin,nbcol,character) mem[nblin][nbcol] = (character)

#endif



#endif	/* _edmem_h */



