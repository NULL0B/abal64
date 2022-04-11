#ifndef	_ldfile_h
#define	_ldfile_h

NAMES * resolve_filename( MODULE * mptr, EXAWORD number );
EXAWORD	resolve_filenumber( MODULE * mptr, EXAWORD number );
VOID	buffer_putq( MODULE * mptr );
EXAWORD	buffer_getq( MODULE * mptr );
VOID	buffer_putb( MODULE * mptr, BYTE c );
EXAWORD	buffer_getb( MODULE * mptr );
VOID	buffer_putw( MODULE * mptr, EXAWORD v );
EXAWORD	buffer_getw( MODULE * mptr );
private	EXAWORD	load_buffer( MODULE * mptr, FILE * handle, EXAWORD sector );
private	EXAWORD	buffer_start( MODULE * mptr, FILE * handle, LOCATION * lptr);
EXAWORD	open_debug_source( MODULE * mptr );
EXAWORD	open_tcode_source( MODULE * mptr );
EXAWORD	open_debug( MODULE * mptr );
EXAWORD	open_tcode( MODULE * mptr );
EXAWORD	close_tcode( MODULE * mptr );
EXAWORD	close_debug( MODULE * mptr );
EXAWORD	tcode_flush( MODULE * mptr );
EXAWORD	debug_flush( MODULE * mptr );


#endif	/* _ldfile_h */

