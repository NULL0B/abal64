#ifndef	_EXREWIND_C
#define	_EXREWIND_C

/* rend un code erreur	*/

EXAWORD	sf_rewind()
{
	switch( (fidperm & NGF_TYP) ) {

		case 	NGF_SQ	:	return(EeEsq_rewind(fidreel) );

		default		:	return( ABAL_OPNOTPOSS	   );

		}
}

#endif	/* _EXREWIND_C */
	/* ----------- */

