#ifndef	_EXDBAM_C
#define	_EXDBAM_C

EXAWORD	sf_dbam(NgfTcode)
EXAWORD	NgfTcode;
{

#ifdef ABALBD

/*==========================================================================*/
/* BDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBD */
/* BDBDBDBDBDBDBD                                            BDBDBDBDBDBDBD */
/* BDBDBDBDBDBDBD        B A S E  de  D O N N E E S          BDBDBDBDBDBDBD */
/* BDBDBDBDBDBDBD                                            BDBDBDBDBDBDBD */
/* BDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBD */
/*==========================================================================*/

	switch ( NgfTcode ) {

		case	_NGF_RECORD	:  return( bdrecord() );
		case	_NGF_JOIN	: 
			/* Check for WRITE Option allowed */
			/* ------------------------------ */
			if ( (fidperm & NGF_R_W) == 0 ) 
				return( ABAL_WRITPROT );
			else	return( dcljoin() );

		case	_NGF_CJOIN	: 
			/* Check for WRITE Option allowed */
			/* ------------------------------ */
			if ( (fidperm & NGF_R_W) == 0 ) 
				return( ABAL_WRITPROT );
			else	return( makejoin() );

		case	_NGF_DJOIN	: 
			/* Check for WRITE Option allowed */
			/* ------------------------------ */
			if ( (fidperm & NGF_R_W) == 0 ) 
				return( ABAL_WRITPROT );
			else	return( suprjoin() );

		case	_NGF_RJOIN	: 
			/* Check for WRITE Option allowed */
			/* ------------------------------ */
			if ( (fidperm & NGF_R_W) == 0 ) 
				return( ABAL_WRITPROT );
			else	return( namejoin() );

		case	_NGF_LJOIN	: return( rubrlst(0x205E,7) );
		case	_NGF_LFILE	: return( rubrlst(0x205E,3) );

		default			: return( 56 );
		}

/*==========================================================================*/
#else
	return( 56 );

#endif	/* ABALBD	Fonctions Niveaux Base de donnees 	*/

}

#endif	/* _EXDBAM_C */
	/* --------- */

