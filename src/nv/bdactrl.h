
//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_bda_control_h
#define _bda_control_h

extern	"C" {
#include "bda.h"
	};

#ifndef	_BDA_MAX_HEAP
#define	_BDA_MAX_HEAP	5
#endif

class	bda_control {

	static	int	initialised;
	static	int	allocated[10];

	int		librarynumber;
	char *		libraryname;
	int		heapindex;
	int		workindex;
	BDA_INIT	context;
	void *		longheap[_BDA_MAX_HEAP];
	unsigned short  wordheap[_BDA_MAX_HEAP];
	unsigned char 	byteheap[_BDA_MAX_HEAP];
	char		workheap[_BDA_MAX_HEAP*2];
	int		stringdex;
	char *		stringwork;

public:	bda_control( char * nptr, int strsize=0 );
	~bda_control();
	void	reset();

	int	callfunction( int functionid );
	int	addparameter( void * vptr, int vlen, int vtype );
	int	byteresult( void * vptr );
	int	wordresult( void * vptr );
	int	bcdresult( void * vptr , int vlen );
	int	stringresult( void * vptr, int vlen );

	int	bytepointer( void * vptr );
	int	wordpointer( void * vptr );
	int	bytevalue( int v );
	int	wordvalue( int v );
	int	bcdvalue( void * vptr , int vlen );
	int	stringvalue( void * vptr, int vlen );
	int	abalstring( char * sptr, int slen , int tlen, int mode );
	void	swapbytes( short int * rptr );
	int	loaded;

	};


#endif	// _bdacontrol_h






