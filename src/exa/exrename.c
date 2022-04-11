#ifndef	_EXRENAME_C
#define	_EXRENAME_C

/*** renvoie un code erreur	****/


/*	NGF RENAME ( Oldname , Newname )
 *	--------------------------------
 *	Renames the file(s) indicated by Nlog as Newname
 *	Errors should be self-evident. (Duplicate or illegal names or
 *	illegal acess etc ).
 */

EXAWORD	sf_rename()
{

	EXAWORD ReturnCode;

	/* Check for WRITE Option allowed */
	/* ------------------------------ */
	if ( (fidperm & NGF_R_W) == 0 )
		return(ABAL_WRITPROT);
	/* Check for EXCLUSIVE Option     */
	/* ------------------------------ */
	else if ((fidperm & NGF_P_E) == 0 )
		return(44); 

	/* Collect NewName Arguament      */
	/* ------------------------------ */
	if ( fargset(1) == SOFTERROR )
		return(err_val);
#ifdef WIN32
	else	worklen2 = lenuzend(workptr1,worklen1);
#else
	else	worklen2 = lenuze(workptr1,worklen1);
#endif

	if (( worktop + worklen2 ) > dieztmp )
		return(114);
	else	workptr2 = (TcodeByteStack + worktop);

	if ( worklen2 > 0 )
		(VOID) memcpy( workptr2 , workptr1 , (USINT) worklen2 );

	*(workptr2 + worklen2) = FILETERM;
	workptr1 = workptr2; 
	worklen1 = worklen2;

	switch ((fidperm  & NGF_TYP)) {

		case NGF_IO   : 
			ReturnCode=EeEad_rename(fidreel, workptr1);
			break;

		case NGF_SQ   : 
			ReturnCode=EeEsq_rename(fidreel, workptr1);
			break;

		case NGF_SI   :
		case NGF_MC   :
		case NGF_BD   :
		case NGF_MCBD : 
			simcprep(_NGF_RENAME);
			ReturnCode=aig_cri();
			break;

		default	     : 
			return(EXER_FUNCWOT);
		}

	/* Check for RENAME errors */
	/* ----------------------- */
	if (!ReturnCode)
		{
		/* Ensure ABAL knows the new file name */
		/* ----------------------------------- */
		liberate_for_assign(fidurl);	/* #BG 06/02/12 au lieu de fidname */
		if ( set_file_name() == SOFTERROR ) 
			ReturnCode = err_val; 
		}

	return(ReturnCode);
}

#endif	/* _EXRENAME_C */
	/* ----------- */

