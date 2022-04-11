/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987, 1992  Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXERROR - H				*/
/*		Version :	2.1a					*/
/*		Date 	:	04/08/1992				*/
/*									*/
/*----------------------------------------------------------------------*/

#ifndef	_EXERROR_H	/* if not already included	*/
#define	_EXERROR_H	/* Avoid multiple inclusions	*/

/*
 *	Definition of Amenesik / Sologic Error codes
 *	----------------------------------
 */

#include "exerrcodes.h"

/*
 *	Structure de Gestion des erreurs
 *	--------------------------------
 */

#define	ERRORPTR struct errform PTR

struct errform {
	EXAWORD	err_adr;		/* Adresse d'erreur		*/
	EXAWORD	err_trp;		/* Adresse du piege d'erreur	*/
	EXAWORD	err_var;		/* Pointeur de variable d'erreur*/
	EXAWORD	err_ind;		/* Index de variable d'erreur	*/
	EXAWORD	err_and;		/* Andex de variable d'erreur	*/
	EXAWORD	err_reg;		/* Register for Reg Var's	*/
	EXAWORD	 err_flg;		/* Status of ON ERROR Goto	*/
	ERRORPTR previous;		/* Previous saved error trap	*/
};

EXAWORD check_for_error_pop();

#endif	/* _EXERROR_H */
	/* ---------- */

