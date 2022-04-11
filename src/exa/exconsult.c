#ifndef	_EXCONSULT_C
#define	_EXCONSULT_C

EXAWORD	sf_consult()
{
	/* Consultation d'information d'un server */
	/* -------------------------------------- */
	switch( (fidperm & NGF_TYP) ) {

		case NGF_IO   	:

			if ( fargset(2) == SOFTERROR ) 
				return(err_val);

			else if ( fargset(1) == SOFTERROR ) 
				return(err_val);
			else	return( EeEad_consult(fidname,workptr2,worklen2,workptr1,worklen1) );

		default		:

			return( ABAL_OPNOTPOSS );

		}
}
#endif	/* _EXCONSULT_C */
	/* ------------ */

