#ifndef	_EXWRITE_C
#define	_EXWRITE_C

EXAWORD	sf_write()
{
	/* Check for WRITE Option allowed */
	/* ------------------------------ */
	if ( (fidperm & NGF_R_W) == 0 ) 
		return( ABAL_WRITPROT   );
	else	return( sf_read_write() );
}

#endif	/* _EXWRITE_C */
	/* ---------- */

