#ifndef	_sf_h
#define	_sf_h

/*	   SF Function codes 		*/
/*	-----------------------		*/
#define	_DEBUG

#define	_SF_			0x2000
#define	_SF2_			0x2100

#define	_SF_OPEN_EXCLUSIVE	(_SF_ | 0x0034)
#define	_SF_OPEN_SHARED		(_SF_ | 0x003C)
#define	_SF_CREATE_EXCLUSIVE	(_SF_ | 0x0030)
#define	_SF_CREATE_SHARED	(_SF_ | 0x0038)
#define	_SF_CLOSE		(_SF_ | 0x0024)
#define	_SF_DELETE		(_SF_ | 0x0020)
#define	_SF_READ		(_SF_ | 0x0060)
#define	_SF_WRITE		(_SF_ | 0x00A0)

/*	SF Error Codes			*/
/*	--------------			*/
#define	_MEMORY_ERROR		27
#define	_SF_INCORRECT		55
#define	_SF_NOT_FOUND		40
#define	_SF_LOCKED   		44
#define	_SF_DATALOST 		63

/*	SF Public Interface Functions	*/
/*	-----------------------------	*/
int	open_sf( char *, int );			/* name, sf_code 			*/
int	close_sf( int );			/* handle				*/
int	read_sf(int, int, char *, int, long );	/* handle, code,buffer,length,sector 	*/
int	write_sf(int, int, char *, int, long );	/* handle, code,buffer,length,sector 	*/


#endif	/* _sf_h */


