#ifndef	_exrpcl_h
#define	_exrpcl_h

void *	open_program_client( struct program_url * url );
int	attach_program_client( void * h, struct program_url * url, char * xptr  );
int	call_program_parameters( void * h, int argc, char * argv );
int	call_program_client( void * h, int procid , char * pptr );
int	exit_program_client( void * h );
int	detach_program_client( void * h );
void *	close_program_client( void * h );

#endif	/* _exrpcl_h */
	/* --------- */


