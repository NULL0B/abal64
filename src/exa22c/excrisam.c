#ifndef	_EXISAM_C
#define	_EXISAM_C

/* renvoie un code erreur	*/

EXAWORD	sf_isam(NgfTcode)
EXAWORD	NgfTcode;
{
	EXAWORD	ret_cod=56;

/*==========================================================================*/
/* SISISISISISISISISISISISISISISISISISISISISISISISISISISISISISISISISISISISI */
/* SISISISISISISI                                            SISISISISISISI */
/* SISISISISISISI   S E Q U E N T I E L L E   I N D E X E    SISISISISISISI */
/* SISISISISISISI                                            SISISISISISISI */
/* SISISISISISISISISISISISISISISISISISISISISISISISISISISISISISISISISISISISI */
/*==========================================================================*/
	switch ( NgfTcode ) {

		/* Insertion d'une nouvelle cle plus article */
		/* ----------------------------------------- */

	case _NGF_INSERT :
		switch( (fidperm & NGF_TYP) ) {
			case NGF_SI   :
			case NGF_MC   :
			case NGF_MCBD :	
				if ( si_prep(1) == SOFTERROR )
					ret_cod = err_val; 
				else	
					{
					simcprep(_NGF_INSERT);
					ret_cod = aig_cri(); 
					}
				break;
			}
		break;

		/* Supression d'une cle + article ou Niveau  */
		/* ----------------------------------------- */

	case _NGF_DELETE :
		switch( (fidperm & NGF_TYP) ) {
			case NGF_SI   :
			case NGF_MC   :
			case NGF_MCBD :	
				if ( si_prep(1) == SOFTERROR )
					ret_cod = err_val;
				else
					{
					simcprep(_NGF_DELETE);
					ret_cod = aig_cri(); 
					}
				break;
			}
		break;

		/* Modification d'un article ou Niveau d'Index (Mq) */
		/* ------------------------------------------------ */

	case _NGF_MODIFY :
		switch( (fidperm & NGF_TYP) ) {
			case NGF_SI   :
			case NGF_MC   :
			case NGF_MCBD :	
				if ( si_prep(1) == SOFTERROR ) 
					ret_cod = err_val; 
				else	
					{
					simcprep(_NGF_MODIFY);
					ret_cod = aig_cri(); 
					}
				break;

			}
		break;

	/* Recherche de Cle + Article + Index */
	/* ---------------------------------- */
	case _NGF_SEARCH :
		switch( (fidperm & NGF_TYP) ) {
			case NGF_SI   :
			case NGF_MC   :
			case NGF_MCBD :	
				if ( si_prep(0) == SOFTERROR ) 
					ret_cod = err_val; 
				else	
					{
					simcprep(_NGF_SEARCH);
					ret_cod = aig_cri(); 
					}
				break;

			}
		break;

	/* Lecture Sequentielle Croissante */
	/* ------------------------------- */

	case _NGF_DOWN 	 :
		switch( (fidperm & NGF_TYP) ) {
			case NGF_SI   :
			case NGF_MC   :
			case NGF_MCBD :	
			case NGF_BD   :
				if ( si_prep(0) == SOFTERROR ) 
					ret_cod = err_val; 
				else	
					{
					simcprep(_NGF_DOWN);
					ret_cod = aig_cri(); 
					}
				break;

			}
		break;

	/* Lecture Sequentielle De-Croissante */
	/* ---------------------------------- */

	case _NGF_UP   	 :
		switch( (fidperm & NGF_TYP) ) {
			case NGF_SI   :
			case NGF_MC   :
			case NGF_MCBD :	
			case NGF_BD   :
				if ( si_prep(0) == SOFTERROR ) 
					ret_cod = err_val;
				else
					{
					simcprep(_NGF_UP);
					ret_cod = aig_cri(); 
					}
				break;
			}
		break;

	default		:	return( sf_misam( NgfTcode ) );
	}

	return(ret_cod);
}

#endif	/* _EXISAM_C */
	/* --------- */


