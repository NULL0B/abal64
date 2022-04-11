#ifndef _EXFIND_C
#define	_EXFIND_C

/*----------------------------------------------------------------------*/
/* This function fulfils the File search function of ABAL		*/
/* ------------------------------------------------------		*/
/*									*/
/* Syntax ABAL language							*/
/* --------------------							*/
/* FIND,<filespec>,<nument> : [&etiq,<err_var>,] <tampon> [,<longeur>]	*/
/*									*/
/* Syntax ABAL assembleur						*/
/* ----------------------						*/
/* NGF FIND (Descripteurs) [Gest_Err] NumLog ,Flag,tampon,longeur       */
/*									*/
/*----------------------------------------------------------------------*/


EXAWORD	sf_find()
{
	EXAWORD	ret_cod;
	EXAWORD	catent;
	EXABYTE	c;

	/* Clear all Errors */
	/* ---------------- */
	ret_cod = 0; err_val = 0; errno = 0;

	/* Set up arguament Frame	*/
	/* ----------------------	*/

	/* Collect Catalog entry ID  Option */
	/* -------------------------------- */
	if ( fargset(3) == SOFTERROR ) 
		ret_cod = err_val;
	else 	{
		catent = 0;
		if (( worklen3 > 0 ) && ( worktyp3 == 3 )) {
			while ( worklen3 > 0 ) {
				c = *(workptr3++); worklen3--;
				c = toupper( (c) );
				switch ( c ) {
					case ' ' : if (( catent & 1 ) != 0 )
							break;
					case 'F' : catent = (catent & 0xFFFE); break;
					case 'N' : catent = (catent | 0x0001); break;
#ifdef ABAL21
					case 'D' : catent = (catent | 0x0010); break;
					case 'I' : catent = (catent | 0x0020); break;
#endif
					default  : return(20);
					}
				}
			}
		/* Collect Result storage ARG */
		/* -------------------------- */
		if ( fargset(1) == SOFTERROR ) 
			ret_cod = err_val; 
		else 	{
			/* Collect Tampon Zone length value */
			/* -------------------------------- */
			if ( fargset(3) != SOFTERROR ) 
				worklen1 = workval3;

			/* Perform Catalogue Research now */
			/* ------------------------------ */
#ifdef PROLOGUE
			/* Allocate structure if not already done */
			/* -------------------------------------- */
			if ( (fidperm & ASS_BUFF_VALID) == 0 ) {
				if ( (fidbuff = (BPTR) allocate((USINT)  32 )) == (BPTR) 0 )
					return(ABAL_MEMORY);
				fidperm |= ASS_BUFF_VALID;
				}

			/* Copy saved catalogue descriptor to work zone */
			/* -------------------------------------------- */
			memcpy( (BPTR) exdirdesc , (BPTR) fidbuff , (USINT) 23 );
#endif	/* PRL */
			if ((catent & 0x0020) && (worklen1 < 11))
				return( 122 );
			ret_cod = dir_seek((BPTR) workptr1,worklen1,fidname,strlen(fidname),catent);
#ifdef PROLOGUE
			/* Copy work zone to save catalogue descriptor  */
			/* -------------------------------------------- */
			memcpy((BPTR) fidbuff, (BPTR) exdirdesc , (USINT) 23 );
#endif	/* PRL */
			if (ret_cod == MOINS_UN)
				ret_cod = errno; 
			}
		}
	return(ret_cod);
}

#endif	/* _EXFIND_C */
	/* --------- */
