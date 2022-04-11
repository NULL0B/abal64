/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1995 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRDLL.H   				*/
/*		Version :	2.1d					*/
/*		Date	:	16/02/1995				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRDLL_H
#define	_TRDLL_H

BDA	desrt;				/* description de la bibliotheque */
extern BDA_INIT FAR PTR rt_init; 	/* signature de la bibliotheque */
extern BDA_ARG rt_arg;			/* description des arguments */

#ifdef 	LINT_ARGS

	SWORD FAR	translator_initialisation( BYTE FAR PTR );
	SWORD FAR	translator_termination( VOID );
	SWORD FAR	translator_identification( VOID );
	SWORD FAR	translator_options( BYTE FAR PTR );
	SWORD FAR	translate_line( BYTE FAR PTR );
	SWORD FAR	translate_file( BYTE FAR PTR, BYTE FAR PTR );
	SWORD FAR	translate_block( BYTE FAR PTR );

	VOID  FAR PTR 	InitRelais(VOID);
static	VOID  FAR 	banniere(VOID);
extern	VOID 		rt_error(WORD);

#ifdef FCT_ENTETE
SWORD PASCAL FAR 	dll_translator_initialisation( BYTE FAR PTR [] );
SWORD PASCAL FAR 	dll_translator_termination( VOID );
VOID  PASCAL FAR 	dll_translator_identification( VOID );
SWORD PASCAL FAR 	dll_translator_options( BYTE FAR PTR [] );
SWORD PASCAL FAR 	dll_translate_line( BYTE FAR PTR [] );
SWORD PASCAL FAR 	dll_translate_file( BYTE FAR PTR [] );
SWORD PASCAL FAR 	dll_translate_block( BYTE FAR PTR [] );
#endif /* FCT_ENTETE */

	/* ----------- */
#else	/* ! LINT_ARGS */
	/* ----------- */

	SWORD  	FAR 	translator_initialisation();
	SWORD  	FAR 	translator_termination();
	VOID   	FAR 	translator_identification();
	SWORD  	FAR 	translator_options();
	SWORD  	FAR 	translate_line();
	SWORD  	FAR 	translate_file();
	SWORD  	FAR 	translate_block();

/* static SWORD FAR 	myatoi(); */
	VOID 	FAR PTR InitRelais();
static	VOID 	FAR 	banniere();
extern	VOID 	    	rt_error();

#ifdef FCT_ENTETE
SWORD PASCAL FAR 	dll_translator_initialisation();
SWORD PASCAL FAR 	dll_translator_termination();
VOID  PASCAL FAR 	dll_translator_identification();
SWORD PASCAL FAR 	dll_translator_options();
SWORD PASCAL FAR 	dll_translate_line();
SWORD PASCAL FAR 	dll_translate_file();
SWORD PASCAL FAR 	dll_translate_block();
#endif /* FCT_ENTETE */

#endif /* LINT_ARGS */

#endif	/* _TRDLL_H */
	/* -------- */


