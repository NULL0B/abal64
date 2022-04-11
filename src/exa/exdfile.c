#ifndef	_EXDFILE_C
#define _EXDFILE_C

#ifdef UNIXWARE
#include <stdio.h>
#endif

EXAWORD	sf_dfile()
{
	EXAWORD	ret_cod;

#ifdef UNIX
	EXAWORD ngf_type;
	EXAWORD	option;
	struct stat stat_buf;
#endif

/*===========================================================================*/
/*	NGF DFILE ( Nlog , [ Access specific params ] )
 *	-----------------------------------------------
 *	This function will erase the filename(s) from the current directory
 *	Errors may be due to : File already open, File inexistant
 *	Unknown access type etc.
 */

	/* Check for WRITE Option allowed */
	/* ------------------------------ */
	if ( (fidperm & NGF_R_W) == 0 )
		return( ABAL_WRITPROT );

#ifdef UNIX

	option = fidperm & NGF_TYP;

	if ((option == NGF_IO) || (option == NGF_SQ)) {

 		if (stat(fidname,&stat_buf) == 0) {
			if(S_ISDIR(stat_buf.st_mode)) {
				ret_cod =EXER_FORBID;
				return(ret_cod);
				}
			}
		else	{
			traitfilerror( MOINS_UN, errno );
			ret_cod  = errno;
			return(ret_cod);
		   	}
		}

#endif /* UNIX */

/* cb950403 : avant
**	option  = (((EXAWORD) *(fdex++)) & 0x0003);
**	linkage = (*(AssignTable + fidbd)).unlog;
**/
/* cb950403 : maintenant */
	fmtchk  = (((EXAWORD) *(fdex++)) & 0x0003);
	dbreel = (*(AssignTable + fidbd)).unlog;


	switch ( (fidperm & NGF_TYP) ) {
		case NGF_IO   :
			ret_cod=EeEad_unlink(fidname);
			break;

		case NGF_SQ   :	
			ret_cod=EeEsq_unlink(fidname);
			break;

		case NGF_SI	:
		case NGF_MC	:
		case NGF_MCBD	:
		case NGF_BD	: 
			ret_cod=aig_cri();
			break;

		default	      : 
			ret_cod = EXER_FUNCWOT;
			break;
		}

	fidreel = EX_UNUSED_HANDLE;
	return(ret_cod);
}

#endif	/* _EXDFILE_C */
	/* ---------- */

