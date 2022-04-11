#ifndef	_EXLLNGF_C
#define _EXLLNGF_C


#include "exaigcri.c"	/* aiguillage fonctions SI/MC/BD	*/
#include "exloadgo.c"	
#include "exchain.c"	
#include "exassign.c"
#include "excfile.c"	
#include "exdfile.c"	
#include "exopen.c"	
#include "exclose.c"	
#include "exatb.c"
#include "exrename.c"
#include "exrdwr.c"	
#include "exread.c"
#include "exwrite.c"
#include "exextend.c"
#include "exrewind.c"
#include "exfind.c"	
#include "excore.c"	
#include "exdbam.c"
#include "exmisam.c"
#include "excrisam.c"

/*									*/
/*		-------------------------------------			*/
/*		N G F _ O P E R A T I O N _ C Y C L E			*/
/*		-------------------------------------			*/
/*									*/
/*	Called from EXNGF.sf_ngf to perform actual low level NGF	*/
/*	operation, links to sf_isam for ISAM functions			*/
/*									*/


EXAWORD	ngf_operation_cycle( NgfTcode )
EXAWORD	NgfTcode;
{
	/* Select ABAL NGF function */
	/* ------------------------ */
	switch ( NgfTcode ) {

		case	_NGF_ASSIGN	:	return( sf_assign() 	);
		case	_NGF_LOADGO	:	return( sf_loadgo() 	);	
		case	_NGF_CHAIN	:	return( sf_chain()  	);
		case	_NGF_FIND	:	return( sf_find()   	);
		case	_NGF_CORE	:	return( sf_core()   	);
		case	_NGF_NAME	:	return( sf_name()   	);

		case 	_NGF_CFILE  	: 	return( sf_cfile()  	);
		case	_NGF_DFILE	:	return( sf_dfile()  	);		
		case	_NGF_RENAME	:	return( sf_rename() 	);
		case	_NGF_OPEN	:	return( sf_open()  	);
		case	_NGF_CLOSE	:	(VOID) sf_close();
						fidreel = EX_UNUSED_HANDLE;
						return(0);

		case	_NGF_EXTEND	:	return( sf_extend() 	);
		case	_NGF_READ	:	return( sf_read()   	);
		case	_NGF_WRITE	:	return( sf_write()  	);
		case	_NGF_REWIND   	:	return( sf_rewind()    	);
		case	_NGF_ATB	:	return( sf_ngfatb()	);

		default			:	return(sf_isam(NgfTcode));

		}
}


#endif	/* _EXLLNGF_C */
	/* ---------- */

