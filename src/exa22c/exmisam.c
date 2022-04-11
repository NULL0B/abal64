#ifndef	_EXMISAM_C
#define	_EXMISAM_C

/*==========================================================================*/
/* MCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMC */
/* MCMCMCMCMCMCMC                                            MCMCMCMCMCMCMC */
/* MCMCMCMCMCMCMC        M U L T I  -  C R I T E R E         MCMCMCMCMCMCMC */
/* MCMCMCMCMCMCMC                                            MCMCMCMCMCMCMC */
/* MCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMC */
/*==========================================================================*/

EXAWORD	sf_misam(NgfTcode)
EXAWORD	NgfTcode;
{
#ifdef ABALMC

	EXAWORD	ngfop;
	EXAWORD	lerr;

	switch ( NgfTcode ) {

	case	_NGF_KEY	: 	return( rubrdcl() );

	case	_NGF_CKEY	: 
		/* Check for WRITE Option allowed */
		/* ------------------------------ */
		if ( (fidperm & NGF_R_W) == 0 ) 
			return( ABAL_WRITPROT );
		else	return( rubrdef() );

	case	_NGF_NKEY	: 
		/* Check for WRITE Option allowed */
		/* ------------------------------ */
		if ( (fidperm & NGF_R_W) == 0 ) 
			return( ABAL_WRITPROT );
		else	return( rubrnom() );

	case	_NGF_FKEY	: 	return( rubrfld() );
	case	_NGF_RKEY	: 	return( rubrraz() );
	case	_NGF_LKEY	: 	return( rubrlst(0x205B,0) );  

	case	_NGF_LINK	: 
		/* Check for WRITE Option allowed */
		/* ------------------------------ */
		if ( (fidperm & NGF_R_W) == 0 ) 
			return( ABAL_WRITPROT );
		else	return( linkwork(0x20AF,0) );

	case	_NGF_CLINK	: 
		/* Check for WRITE Option allowed */
		/* ------------------------------ */
		if ( (fidperm & NGF_R_W) == 0 ) 
			return( ABAL_WRITPROT );
		else	return( linkwork(0x20B7,1) );

	case	_NGF_LLINK	: 	return( rubrlst(0x205F,0) );
	case	_NGF_COUNT	: 	
	case	_NGF_POSIT	:
		return((lerr = intero(0x20A3,NgfTcode & 1)));

	case	_NGF_STATS	: 
		if (((fidperm & NGF_TYP) & NGF_MC) == NGF_MC) 
			ngfop = 0x207B;
		else 	ngfop = 0x207A;
		return( rubrlst(ngfop,0) );

	default			:	return( sf_dbam(NgfTcode) );
	}

#else
	return( 56 );
#endif

}

#endif	/* _EXMISAM_C */
	/* ---------- */



