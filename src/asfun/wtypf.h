/***************************************************
* PROTOTYPAGE DES FONCTIONS DE BASE FENETRAGE	   *
*						   *
* le 08 03 1990 sb				   *
****************************************************/
#ifndef	_wtypf_h
#define	_wtypf_h
 
/****************************************************
* prototypage des fonctions externes		    *
*****************************************************/
#define	ALSMID "asfun"
#include "allocate.h"

#ifdef	VERSION666
#define allouer(x)	/* malloc(x) */  abalallocate(x,"asfun")
#define libere(x)	/* free(x)   */  aballiberate(x,"asfun")
#else
#define allouer(x)	malloc(x) 
#define libere(x)	free(x)   
#endif
#ifdef PROL

#define f_allouer(x)  _fmalloc(x)
#define f_libere(x)   _ffree(x) 

#ifdef MSDOS

#define bell()		x_bell()
#define x_getc()	x_getch()

#else

#define x_getc()	getch()

#endif /* MSDOS */

#else

#ifdef	VERSION666
#define f_allouer(x)	/* malloc(x) */  allocate(x)
#define f_libere(x)	/* free(x)   */  liberate(x)
#else
#define f_allouer(x)	malloc(x)
#define f_libere(x)	free(x)
#endif

#define x_getc()	x_getch()
#define bell()		x_bell()

#ifdef AIX_VERS
#ifdef AVIION
WORD Access(BPTR,WORD,WORD);
#endif

#endif /* AIX_VERS */
#endif /* PROL */


/****************************************************
* macro-definitions				    *
*****************************************************/

#define min(a,b)	(((a) < (b)) ? (a) : (b))	/* minimum	  */
#define max(a,b)	(((a) > (b)) ? (a) : (b))	/* maximum	  */

#define Maj(c) ((c< 'a') || (c> 'z')) ? c : c-32        /* majuscules     */

#ifndef OSF1
#define Invint(i) ((i << 8) | (i >> 8)) 		/* inversion uint */
#else
#ifdef Invint
#undef Invint
#endif
#define Invint Invintosf1
#endif

/****************************************************
*  PROTOTYPAGE DES FONCTIONS DE FENETRAGE STANDARD  *
*****************************************************/

#ifdef PROL

TYPF winit(BYTE,BYTE,BYTE,BYTE,BYTE);
TYPF wend ();

#ifdef MSDOS
TYPF wcreat (WPTR ,BPTR);
#else
TYPF wcreat (WPTR ,WDESC_APP_PTR );
#endif

TYPF wwrite (WORD, WORD, BPTR);
TYPF wselect (WORD);
TYPF winv (WORD);
TYPF wgel (WORD);
TYPF wvis (WORD);
TYPF wsup (WORD);
TYPF wposcur (WORD, WORD, WORD);
TYPF wfgen (WORD, WORD);
TYPF watb (WORD, BYTE, BYTE, BYTE);
TYPF wimpl (WORD);
TYPF wcreatc (WPTR, WDESC_APP_PTR);
TYPF wsetatb(WORD, BYTE, BYTE, BYTE, WORD, WORD, WORD, WORD);
TYPF wgetimpl(WPTR);
TYPF wmove(WORD,WORD,WORD);
TYPF wexit(WORD);
TYPF wrefresh();
TYPF swcreat(WPTR, WORD, WORD, WORD, WORD);
TYPF wcadre(WORD, BYTE);
TYPF wtitre(WORD, BYTE, BYTE, BYTE);
#ifdef MSDOS
TYPF wfinfo(WORD, BPTR);
#else
TYPF wfinfo(WORD, WDESC_APP_PTR);
#endif
#else					/* definitions unix */

TYPF winit();
TYPF wend();
TYPF wcreat();
TYPF wwrite();
TYPF wselect(WORD);
TYPF winv(WORD);
TYPF wgel(WORD);
TYPF wvis(WORD);
TYPF wsup(WORD);
TYPF wposcur();
TYPF wfgen();
TYPF watb();
TYPF wimpl();
TYPF wcreatc();
TYPF wsetatb();
void wmemset();
void wmemcpy();
void wwmemset();
void wimemcpy();
TYPF wgetimpl();
TYPF wmove();
TYPF wexit();
TYPF wrefresh();
TYPF swcreat();
TYPF wcadre();
TYPF wtitre();
TYPF wfinfo();
#endif /* PROL */

/* fin du source */

#endif	/* _wtypf_h */
	/* -------- */

