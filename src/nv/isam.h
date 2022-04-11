//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_misam_h
#define _misam_h

#include "string.h"

class	standard_misam	{

	char	*	filename;
	int		handle;
	int		status;
	int		marker;
	int		recordsize;
	int		indexsize;
	int		indextype;
	char	*	buffer;
	char	*	spare;


public:
	int		creation_status;
	standard_misam(int datalen=256, int indexlen=16, int options=0 );
	~standard_misam();

	int		declare_file(char * pptr, char * nptr );
	int		declare_link(char * nptr, int  mlen   );

#ifdef	_DEBUG_ISAM
	void		showindex();
	void		showrecord();
#endif

	void		pushindex();
	void		popindex();
	void		assign_file(char * pptr, char * sptr);
	void		open_file();
	void		close_file();
	void		create_file();
	int 		locate_record();
	int 		lock_record();
	int 		next_record();
	int 		previous_record();

	int		locate_first_record( char * qptr, int qlen );

	int 		locate_first_record();
	int 		locate_last_record();
	int 		lock_first_record();
	int 		lock_last_record();
	int 		lock_next_record();
	int 		lock_previous_record();
	int		update_record();
	int 		insert_record();
	int 		modify_record();
	int 		delete_record();
		
	void		setrecord( char * dptr, int dlen );
	void		getrecord( char * dptr, int dlen );

	char * 		setindex( char * );
	void		getindex( char * );
	void		ireset( int v=0 );
	void		dreset( int v=0 );
	void		setbyte( int offset, int value );
	void		setword( int offset, int value );
	void		setlong( char * bptr, long value );
	void		setlong( int offset, long value );
	void		isetlong( int offset, long value );

	int		getbyte( int offset );
	int		getword( int offset );
	long		getlong( char * bptr );
	long		getlong( int offset );
	long		igetlong( int offset );
	long		newlong( long oldlong );
	static	int	copyflag;
	};

#endif	// _misam_h



