#ifndef	_EXCFILE_C
#define _EXCFILE_C

/* renvoie un code erreur, fidreel renseigne	*/

/* ici, y a pas de simcprep ???? */

EXAWORD	sf_cfile()
{
	EXAWORD	z, erreur;

/*	NGF CREATE ( Nlog , [ access method specific params ] )
 *	-------------------------------------------------------
 *	This function will create any of the 5 basic file types wrt
 *	file type declared in the relevant ASSIGN function.
 *	Errors may be due to : No write permission, File already exists,
 *	Unable to create a device/ressource or unsupported file access
 *	types.
 */

	if ( (fidperm & NGF_R_W) == 0 ) {
		/* fidperm |= NGF_R_W; */
		return( ABAL_WRITPROT );
		}
	fmtchk = (EXAWORD) *(fdex++);	/* Collect extra descriptor */
	workval1 = 0; workval2 = 0; errno = 0; fidreel = EX_UNUSED_HANDLE;
	z = 0;

	/* Establish Data and Key Lengths */
	/* ------------------------------ */
	if ( fargset(1) != SOFTERROR ) { 
		z |= 0x0010; 
		if ( fargset(2) != SOFTERROR ) 
			z |= 0x0020;
		}
	else	{ 
		workval1 = 0; 
		z |= 0x0010; 
		}

	errno = EXER_SYNTAX;	/* Default Error Code */
	switch( (fidperm & NGF_TYP) ) {
#ifdef	ABALXML
		case NGF_XML :
			fidreel = 0;
			if ((errno = AbalXmlCfile( fidname, fidperm, & fidbuff)) != 0) 
				break;
			else	{
				fidreel=1;
				errno = 0;
				break;
				}
#endif
		case NGF_SQ   : 
			if ( z & 0x0010 ) {
				if ( workval1 == 0 ) 
					workval1 = 256; 
				if (!(fidreel=EeEsq_create(fidname, (EXAWORD)workval1, fidperm, (WPTR)&erreur))) { 
					fidreel=EX_UNUSED_HANDLE; 
					errno=err_val=(int)erreur; 
					}
				}
			break;

		case NGF_IO   : 
			if (!(fidreel=EeEad_create(fidname, fidperm, (WPTR)&erreur)))
				{ fidreel=EX_UNUSED_HANDLE; errno=(int)erreur; }
			break;

		case NGF_SI	:
		case NGF_MC	:
		case NGF_MCBD	:
		case NGF_BD	: 
			errno=(int)aig_cri();
			break;

		default	      :	return(EXER_FUNCWOT);
		}

	if ( fidreel == EX_UNUSED_HANDLE) 
		return( errno );
	else 	return( 0 );

}

#endif	/* _EXCFILE_C */
	/* ---------- */



