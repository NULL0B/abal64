#ifndef	_EXNGF_C
#define	_EXNGF_C

#include "exngf.h"
#include "exasyslog.h"

#ifndef ABAL_CRITERIA
#include "exoldngf.c"	/* Ancien  source EXNGF.C legerement modifie 	*/
#else
#include "exnewngf.c"	/* Nouveau source EXNGF.C pour CRITERIA		*/
#endif

#ifdef WIN1632
EXAWORD GetOriginalHandle( lfh )
EXAWORD lfh;
{	return((EXAWORD)(*(AssignTable + lfh)).unlog);	}
#endif

#endif	/* _EXNGF_C */

