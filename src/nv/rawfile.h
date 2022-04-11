//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_rawfile_h
#define _rawfile_h

extern	int	_creat( char *, int );
extern	int	_open( char *, int );
extern	int	_read( int, char *, int );
extern	int	_write( int, char *, int );
extern	long	_lseek( int, long, long );
extern	int	_close( int );
extern	int 	_unlink( char * );

#endif	// _rawfile_h


