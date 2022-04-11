//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_mc_h
#define _mc_h

extern	int	mc_errno;
int	mc_anfc(char * filename );
int	mc_open(char * filename, int options );
int	mc_creat(char * filename, int options, int recordsize , int indexsize );
int	mc_close(int handle);
int	mc_unlink(char * filename);
int	mc_delete(int handle, char * indexbuffer, int indexlen, int mq );
int	mc_insert(int handle, char * indexbuffer, int indexlen, int mq, char * buffer, int bufferlen );
int	mc_modif(int handle, char * indexbuffer, int indexlen, int mq, char * buffer, int bufferlen );
int	mc_search(int handle, char * indexbuffer, int indexlen, int mq, char * buffer, int bufferlen );
int	mc_lsearch(int handle, char * indexbuffer, int indexlen, int mq, char * buffer, int bufferlen );
int	mc_down(int handle, int mq, char * buffer, int bufferlen );
int	mc_ldown(int handle, int mq, char * buffer, int bufferlen );
int	mc_up(int handle, int mq, char * buffer, int bufferlen );
int	mc_lup(int handle, int mq, char * buffer, int bufferlen );

void	mc_setkey( char * buffer, char * nptr, int size, int type );
int	mc_setlink( char * buffer, char * linkname );

int	mc_key(	int handle, char * nptr, int size, int type );
int	mc_nkey( int handle, char * oldname,char * newname );
int	mc_rkey( int handle, char * oldname, int offset, char * newname, int size, int type );

int	mc_clink( int	handle, char * buffer, int buflen );
int	mc_link( int	handle, char * buffer, int buflen );

int	mc_posit( int handle, char * question, int qlen, int option );
int	mc_count( int handle, char * question, int qlen, int option );


#endif	/* _mc_h */


