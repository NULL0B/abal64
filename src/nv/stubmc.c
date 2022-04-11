#ifndef	_stub_mc_c
#define	_stub_mc_c

int	mc_errno=0;
int	mc_anfc(char * filename )	{ return(0); }
int	mc_open(char * filename, int options )	{ return(0); }
int	mc_creat(char * filename, int options, int recordsize , int indexsize )	{ return(0); }
int	mc_close(int handle)	{ return(0); }
int	mc_unlink(char * filename)	{ return(0); }
int	mc_delete(int handle, char * indexbuffer, int indexlen, int mq )	{ return(0); }
int	mc_insert(int handle, char * indexbuffer, int indexlen, int mq, char * buffer, int bufferlen )	{ return(0); }
int	mc_modif(int handle, char * indexbuffer, int indexlen, int mq, char * buffer, int bufferlen )	{ return(0); }
int	mc_search(int handle, char * indexbuffer, int indexlen, int mq, char * buffer, int bufferlen )	{ return(0); }
int	mc_lsearch(int handle, char * indexbuffer, int indexlen, int mq, char * buffer, int bufferlen )	{ return(0); }
int	mc_down(int handle, int mq, char * buffer, int bufferlen )	{ return(0); }
int	mc_ldown(int handle, int mq, char * buffer, int bufferlen )	{ return(0); }
int	mc_up(int handle, int mq, char * buffer, int bufferlen )	{ return(0); }
int	mc_lup(int handle, int mq, char * buffer, int bufferlen )	{ return(0); }

void	mc_setkey( char * buffer, char * nptr, int size, int type )	{ return; }
int	mc_setlink( char * buffer, char * linkname )	{ return(0); }

int	mc_key(	int handle, char * nptr, int size, int type )	{ return(0); }
int	mc_nkey( int handle, char * oldname,char * newname )	{ return(0); }
int	mc_rkey( int handle, char * oldname, int offset, char * newname, int size, int type )	{ return(0); }

int	mc_clink( int	handle, char * buffer, int buflen )	{ return(0); }
int	mc_link( int	handle, char * buffer, int buflen )	{ return(0); }

int	mc_posit( int handle, char * question, int qlen, int option )	{ return(0); }
int	mc_count( int handle, char * question, int qlen, int option )	{ return(0); }


#endif	// _stub_mc_c

