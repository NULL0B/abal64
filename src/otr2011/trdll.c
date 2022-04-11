/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1995 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRDLL.C   				*/
/*		Version :	2.1d					*/
/*		Date	:	16/02/1995				*/
/*									*/
/* --------------------------------------------------------------------	*/

#ifndef	_TRDLL_C
#define	_TRDLL_C

#include	"trhost.h"
#include	<stdio.h>
#include	<stdlib.h>
#include	"trbda.h"
#include	"trdll.h"

/*
 *	I N I T  R E L A I S ()
 *	-----------------------
 *
 */

VOID FAR PTR InitRelais()
{ 
  if (rt_init != (BDA_INIT FAR PTR) 0L)
	rt_init->ordinaire.signature = BDA_ORDINAIRE;

  desrt.banniere = (VOID (FAR PTR)()) translator_identification;
  desrt.fin = (VOID (FAR PTR)()) 0L;

  desrt.nombre = 5;

#ifdef 	vms

	desrt.nom[0] = (BYTE FAR PTR) "_translator_initialisation";
	desrt.nom[1] = (BYTE FAR PTR) "_translator_termination";
	desrt.nom[2] = (BYTE FAR PTR) "_translate_line";
	desrt.nom[3] = (BYTE FAR PTR) "_translator_options";
	desrt.nom[4] = (BYTE FAR PTR) "_translate_file";
	desrt.nom[5] = (BYTE FAR PTR) "_translate_block";

#else /* ! vms */

	desrt.reserve = (VOID FAR PTR) 0L;

#ifdef FCT_ENTETE	/* i.e. UNIX and EXTENDED DOS */
			/* -------------------------- */

	desrt.fonction[0] = (SWORD (FAR PTR)()) dll_translator_initialisation;
	desrt.fonction[1] = (VOID  (FAR PTR)()) dll_translator_termination;
	desrt.fonction[2] = (SWORD (FAR PTR)()) dll_translate_line;
	desrt.fonction[3] = (SWORD (FAR PTR)()) dll_translator_options;
	desrt.fonction[4] = (SWORD (FAR PTR)()) dll_translate_file;
	desrt.fonction[5] = (SWORD (FAR PTR)()) dll_translate_block;

#else  	/* ! FCT_ENTETE  i.e. PROLOGUE et MS/DOS */
	/* ------------------------------------- */

	desrt.fonction[0] = (WORD (FAR PTR)()) translator_initialisation;
	desrt.fonction[1] = (WORD (FAR PTR)()) translator_termination;
	desrt.fonction[2] = (WORD (FAR PTR)()) translate_line;
	desrt.fonction[3] = (WORD (FAR PTR)()) translator_options;
	desrt.fonction[4] = (WORD (FAR PTR)()) translate_file;
	desrt.fonction[5] = (WORD (FAR PTR)()) translate_block;

#endif /* FCT_ENTETE */

#endif	/* VMS */

  return((VOID FAR PTR) &desrt);
}

#ifdef	FCT_ENTETE

SWORD PASCAL FAR  dll_translator_initialisation(a)
BYTE FAR PTR a[];
{
	return( translator_initialisation( a[0] ) );

}

SWORD PASCAL FAR dll_translator_termination()
{
	return( translator_termination() );
}

SWORD PASCAL FAR dll_translate_line(a)
BYTE FAR PTR a[];
{
	return( translate_line( a[0] ) );
}

SWORD PASCAL FAR dll_translator_options( a )
BYTE FAR PTR a[];
{
	return( translator_options( a[0] ) );

}

SWORD PASCAL FAR dll_translate_file(a)
BYTE FAR PTR a[];
{
	return( translate_file( a[0], a[1] ) );
}

SWORD PASCAL FAR dll_translate_block(a)
BYTE FAR PTR a[];
{
	return( translate_block( a[0] ) );
}

#endif	/* FCT_ENTETE */
	/* ---------- */

#ifdef	WORD
#undef 	WORD
#endif

#ifdef	BYTE
#undef  BYTE
#endif

#ifdef	LONG
#undef  LONG
#endif

#include "trmain.c"

WORD	systeme( )
{
	return(0);
}


#endif	/* _TRDLL_C */
	/* -------- */

