#ifndef	_TRAPL_C
#define	_TRAPL_C

#include <stdio.h>		/* Standard IO handling routines	*/
#ifdef	WIN32
#include <io.h>
#endif
#include <errno.h>		/* Error return definitions		*/
#include <fcntl.h>		
#include <string.h>
	
#include "stdtypes.h"
#include "translat.h"
#include "trproc.h"
#include "trparser.h"
#include "trsyntax.h"
#include "trerrors.h"
#include "trsymbol.h"
#include "troption.h"
#include "trtables.h"
#include "trexpres.h"
#include "trlabels.h"
#include "triter.h"
#include "trtree.h"
#include "trmethod.h"
#include "trmember.h"
#include "trcommon.h"
#include "trclass.h"
#include "trinput.h"
#include "trdebug.h"
#include "trapl.h"
#include "trabal.h"	
#include "triof.h"
#include "troutput.h"
#include "fnparser.h"
#include "trldf.h"
#include "trecho.h"


EXTERN	BYTE	TokenBuffer[];
EXTERN	WORD	TokenHash;


#ifndef	UNIX
#else
TCDLBPTR	locate_dynamic_library();
COMETHODPTR	allocate_special_method();
TCMBDATAPTR	allocate_structure_data();
TCMBCONSTPTR	allocate_structure_const();
#endif

WORD			is_member_library( class )
	TCSTRUCTPTR	class;
{
	return( class->access & _MEMBER_LIBRARY );
}

VOID			set_member_library( class )
	TCSTRUCTPTR	class;
{
	class->access |= _MEMBER_LIBRARY;
	return;
}

		
/*	------------------------	-----------------		*/
/*	ABAL++ OTR : VERSION 2.2	APL LOW LEVEL I/O   		*/
/*	------------------------	-----------------		*/
#ifdef	ABAL33A
#include "trlexapl.c"
#endif
#include "traplio.c"

/*	------------------------	--------------------		*/
/*	ABAL++ OTR : VERSION 2.2	APL SYMBOL MANAGMENT		*/
/*	------------------------	--------------------		*/

#include "trdbgapl.c"

/*	------------------------	-------------------------   	*/
/*	ABAL++ OTR : VERSION 2.2	APL CLASS LIBRARY LOADING   	*/
/*	------------------------	-------------------------   	*/

#include "trgetapl.c"

/*	------------------------	----------------------------	*/
/*	ABAL++ OTR : VERSION 2.2	APL CLASS LIBRARY GENERATION	*/
/*	------------------------	----------------------------	*/

#include "trputapl.c"


#endif	/* _TRAPL_C */
	/* -------- */



