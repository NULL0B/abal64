/*
 *	Il suffit de choisir le nouveau ou l'ancien modele
 *	--------------------------------------------------
 */
#include "exos.h"

#ifndef ABAL_CRITERIA
#include "exoldngf.c"	/* Ancien  source EXNGF.C legerement modifie 	*/
#else
#include "exnewngf.c"	/* Nouveau source EXNGF.C pour CRITERIA		*/
#endif


/* Add-on gestion imprimante */

#ifdef WIN1632
EXAWORD GetOriginalHandle( lfh )
EXAWORD lfh;
{	return((EXAWORD)(*(AssignTable + lfh)).unlog);	}
#endif



