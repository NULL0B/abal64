#ifndef	_EXEXTEND_C
#define	_EXEXTEND_C

/* renvoie un code erreur	*****/

EXAWORD	sf_extend()
{

	/* Check for WRITE Option allowed */
	/* ------------------------------ */
	if ( (fidperm & NGF_R_W) == 0 )
		return( ABAL_WRITPROT );

	switch((fidperm & NGF_TYP)) {
		case	NGF_DV	:
		case	NGF_CM	:
		case	NGF_IM	:
		case	NGF_GR	: 
			return( ABAL_OPNOTPOSS );
#ifndef PROLOGUE			/* ?????? commentaires !!!!!!! */
		case NGF_SI   :
		case NGF_MC   :
		case NGF_BD   :
		case NGF_MCBD : 
			if ( fargset(1) == SOFTERROR )
				return( err_val );
			else	return( 0 );

#endif  /* ! PRL  */

		default :	/* IO ????	*/
			if (fargset(1) == SOFTERROR)
				return(err_val);
			return(EeEad_extend(fidreel, workval1));

		}
}

#endif	/* _EXEXTEND_C */
	/* ----------- */



