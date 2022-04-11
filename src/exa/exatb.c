#ifndef	_EXATB_C
#define	_EXATB_C

/* renvoie un code erreur	*/

EXAWORD	sf_ngfatb()
{

	EXAWORD	y,z;
	EXAWORD	ret_cod;

	/* Modification des Attributs d'exploitation */
	/* ----------------------------------------- */

	/* Create Temporary Permissions Word */
	/* --------------------------------- */
	y = ((fidperm & 0xFFF9) | ( ((EXAWORD) *(fdex++)) << 1) );

	switch( (fidperm & NGF_TYP) ) {

		case NGF_IO   :
			if ((ret_cod = EeEad_matb(fidreel, y))==0)
				fidperm=y;
			break;
		case NGF_SQ   :
			if ((ret_cod = EeEsq_matb(fidreel, y))==0)
				fidperm=y;
			break;
		case NGF_SI   :
		case NGF_MC   :
		case NGF_MCBD : 
		case NGF_BD   :
			z = fidperm; 
			fidperm = y;
			if ((ret_cod = aig_cri()) != 0)
				fidperm = z; 
			break;
		default       :
#ifdef	ABAL_CRITERIA
			if ((ret_cod = EeEad_matb(fidreel , y)) == 0 )
				fidperm = y;
#else	/* ! ABAL_CRITERIA */
#ifdef COEXA
			if ((ret_cod = matb(fidname,((y & NGF_P_E) >> 1),((y & NGF_I_C) >> 2),(y & NGF_R_W))) == 0 )
				fidperm = y;
#else
			if ((ret_cod = matb(fidreel,((y & NGF_P_E) >> 1),((y & NGF_I_C) >> 2),(y & NGF_R_W))) == 0 )
				fidperm = y;
#endif
#endif
			break;

		}

	if ( ret_cod == MOINS_UN )
		return( err_val );
	else	return( ret_cod );

}
#endif	/* _EXATB_C */
	/* -------- */

