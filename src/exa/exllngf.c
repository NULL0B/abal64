#ifndef	_EXLLNGF_C
#define _EXLLNGF_C


#include "exaigcri.c"	/* aiguillage fonctions SI/MC/BD	*/
#ifdef	ABALXML
#include "exxml.c"
#endif
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
#include "exconsult.c"
#include "excore.c"	
#include "exdbam.c"
#include "exmisam.c"
#include "excrisam.c"
#ifdef	ABALSQL
#include "exsql.c"
#endif

/*									*/
/*		-------------------------------------			*/
/*		N G F _ O P E R A T I O N _ C Y C L E			*/
/*		-------------------------------------			*/
/*									*/
/*	Called from EXNGF.sf_ngf to perform actual low level NGF	*/
/*	operation, links to sf_isam for ISAM functions			*/
/*									*/

EXAWORD	AllowCloseZero=1;

EXAWORD	get_allow_close_zero()
{
	return( AllowCloseZero );
}

VOID	set_allow_close_zero(EXAWORD v)
{
	AllowCloseZero = v;
	return;
}

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
		case	_NGF_CONSULT	:	return( sf_consult()	);
		case 	_NGF_CFILE  	: 	return( sf_cfile()  	);
		case	_NGF_DFILE	:	return( sf_dfile()  	);		
		case	_NGF_RENAME	:	return( sf_rename() 	);
		case	_NGF_OPEN	:	return( sf_open()  	);
		case	_NGF_CLOSE	:	
			if ( lfh == 0 ) {
				if (!( AllowCloseZero ))
					return(0);
				}
			(VOID) sf_close();
			fidreel = EX_UNUSED_HANDLE;
			return(0);

		case	_NGF_EXTEND	:	return( sf_extend() 	);
		case	_NGF_READ	:	return( sf_read()   	);
		case	_NGF_WRITE	:	return( sf_write()  	);
		case	_NGF_REWIND   	:	return( sf_rewind()    	);
		case	_NGF_ATB	:	return( sf_ngfatb()	);

#ifdef		ABALSQL
		case	_NGF_CONNECT:
		case	_NGF_BEGIN:
		case	_NGF_COMMIT:
		case	_NGF_ROLLBACK:
		case	_NGF_PREPARE:
		case	_NGF_EXEC:
		case	_NGF_GETROWCOL:
		case	_NGF_GETCOLNAME:
		case	_NGF_FETCH:	
		case	_NGF_GETFIELD:
		case	_NGF_DROP:
		case	_NGF_BINDPARAM:
		case	_NGF_BINDCOL:			
		case	_NGF_GETSQLERROR:
		case	_NGF_GETSERVICEINFO:
			return (sf_sql(NgfTcode));
#endif
		default:
			return(sf_isam(NgfTcode));

		}
}


#endif	/* _EXLLNGF_C */
	/* ---------- */

