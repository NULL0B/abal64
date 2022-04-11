#ifndef	_ldfile_c
#define	_ldfile_c

#include "fnparser.c"

#ifndef WIN32

/* Implementation in WOTR.C for Windows */
int is_target_file_busy(BPTR FileName)
{      
#ifdef PROLOGUE
	/* TwinServer: Open with exclusive flag is not available with P3LLIBC (OK with PCRTL). */
	if (access(FileName, 0) == 0)
	{
		char  TmpFile[LGMXNOM];
		int	Lg;

		strcpy(TmpFile, FileName);
		Lg = strlen(TmpFile);
		/* Replace the last char by @. */
		TmpFile[Lg-1] = '@';

		if (rename(FileName, TmpFile) != 0)
			return 1;
		else
			rename(TmpFile, FileName);
	}
#else
  // UseIt: To be implemented
	return(0);
#endif

  return 0;
}
#endif

BPTR		module_filename( BPTR nptr )
{
	fn_parser(nptr,workbuffer,0x000F);
	strcat(workbuffer,".o" );
	return( allocate_string( workbuffer ) );
}

BPTR		program_filename( BPTR nptr )
{
	fn_parser(nptr,workbuffer,0x000F);
	strcat(workbuffer,".at" );
	return( allocate_string( workbuffer ) );
}

BPTR		debug_filename( BPTR nptr )
{
	fn_parser(nptr,workbuffer,0x000F);
	strcat(workbuffer,".dbg" );
	return( allocate_string( workbuffer ) );
}

BPTR		symbolic_filename( BPTR nptr )
{
	fn_parser(nptr,workbuffer,0x000F);
	strcat(workbuffer,".dbo" );
	return( allocate_string( workbuffer ) );
}

EXAWORD	open_tcode( MODULE * mptr )
{
	if (!( mptr->atname = module_filename( mptr->rootname ))) 
		return( 27 );
	else	{
		if ( Linker.sourcetrace ) {
			sprintf(ErrorBuffer, "file : %s", mptr->atname);
			issue_message(4, ErrorBuffer);
		}
		if (!(mptr->athandle = fopen( mptr->atname, "rb" ))) 
			return( 40 );
		else if (!( read_tcode( mptr->athandle, 0, mptr->atheader, 256 ) )) 
			return( 53 );
		else	return( 0  );
		}
}

EXAWORD	open_debug( MODULE * mptr )
{
	if (!( mptr->dbname = symbolic_filename( mptr->rootname ))) 
		return( 27 );
	else	{
		if ( Linker.sourcetrace ) {
			sprintf(ErrorBuffer, "file : %s", mptr->dbname);
			issue_message(4, ErrorBuffer);
		}
		if (!(mptr->dbhandle = fopen( mptr->dbname, "rb" ))) 
			return( 40 );
		else if (!( read_tcode( mptr->dbhandle, 0, mptr->dbheader, 256 ) )) 
			return( 53 );
		else	return( 0  );
		}
}

EXAWORD	build_debug( MODULE * mptr )
{
	EXAWORD	status;

	build_header( mptr, mptr->dbheader, 1 );
#ifdef ABAL32DBG
	build_headerex( mptr, mptr->dbheaderex, 1 );
#endif

	status = write_tcode( mptr->dbhandle, 0, mptr->dbheader, 256 );
#ifdef ABAL32DBG
	if (!status)
		status = write_tcode( mptr->dbhandle, 1, mptr->dbheaderex, 256 );
#endif
	return status;
}

EXAWORD	build_tcode( MODULE * mptr )
{
	EXAWORD	status;

	build_header( mptr, mptr->atheader, 1 );	/*BGI 0? */
#ifdef ABAL32DBG
	build_headerex( mptr, mptr->atheaderex, 0 );
#endif

	status = write_tcode( mptr->athandle, 0, mptr->atheader, 256 );
#ifdef ABAL32DBG
	if (!status)
		status = write_tcode( mptr->athandle, 1, mptr->atheaderex, 256 );
#endif
	return status;
}

VOID	flush_tcode( MODULE * mptr ) 
{
	if( Linker.targettrace )
		issue_message(5, "Tcode Header");

	build_header( mptr, mptr->atheader, 0 );
	build_header( mptr, mptr->dbheader, 1 );
#ifdef ABAL32DBG
	build_headerex( mptr, mptr->atheaderex, 0 );
	build_headerex( mptr, mptr->dbheaderex, 1 );
#endif

	lock_headers( mptr );
	(void) write_tcode( mptr->dbhandle, 0, mptr->dbheader, 256 );
	(void) write_tcode( mptr->athandle, 0, mptr->atheader, 256 );
#ifdef ABAL32DBG
	(void) write_tcode( mptr->dbhandle, 1, mptr->dbheaderex, 256 );
	(void) write_tcode( mptr->athandle, 1, mptr->atheaderex, 256 );
#endif
	return;
}

EXAWORD	create_tcode( MODULE * mptr ) 
{
	if (!( mptr->atname = program_filename( mptr->rootname ))) 
		return( 27 );
	else	{
		if ( Linker.targettrace ) {
			sprintf(ErrorBuffer, "file : %s", mptr->atname);
			issue_message(5, ErrorBuffer);
		}
		
		if (is_target_file_busy(mptr->atname)) {
			sprintf(ErrorBuffer, "file : %s", mptr->atname);
			issue_error(11, ErrorBuffer);
			return( 46 );
		}

		if (!(mptr->athandle = fopen( mptr->atname, "wb" ))) 
			return( 46 );
		else	return( build_tcode( mptr ) );
		}
}

EXAWORD	create_debug( MODULE * mptr ) 
{
	if (!( mptr->dbname = debug_filename( mptr->rootname ))) 
		return( 27 );
	else 	{
		if ( Linker.targettrace ) {
			sprintf(ErrorBuffer, "file : %s", mptr->dbname);
			issue_message(5, ErrorBuffer);
		}
		if (!(mptr->dbhandle = fopen( mptr->dbname, "wb" ))) 
			return( 46 );
		else	return( build_debug( mptr ) );
		}
}

EXAWORD	close_tcode( MODULE * mptr ) 
{
	if ( mptr->atname ) {
		if ( mptr->athandle ) {
			fclose( mptr->athandle );
			mptr->athandle = (FILE*)0;
			}
		liberate( mptr->atname );
		mptr->atname = (BPTR) 0;
		}
	return(0);
}


EXAWORD	close_debug( MODULE * mptr ) 
{
	if ( mptr->dbname ) {
		if ( mptr->dbhandle ) {
			fclose( mptr->dbhandle );
			mptr->dbhandle = (FILE*)0;
			}
		liberate( mptr->dbname );
		mptr->dbname = (BPTR) 0;
		}
	return(0);
}

EXAWORD	open_tcode_source( MODULE * mptr )
{
	if ( Linker.atsource ) {
		if ( Linker.atsource->unique == mptr->unique )
			return( 0 );
		else	close_tcode( Linker.atsource );
		}
	return(open_tcode((Linker.atsource = mptr)));
}

EXAWORD	open_debug_source( MODULE * mptr )
{
	if ( Linker.dbsource ) {
		if ( Linker.dbsource->unique == mptr->unique )
			return( 0 );
		else	close_debug( Linker.dbsource );
		}
	return(open_debug((Linker.dbsource = mptr)));
}



#endif	/* _ldfile_c */


