#ifndef	_allocate_h    
#define _allocate_h


#ifdef	UNIX

#ifndef	ALSMID
#define	ALSMID "unknown"
#endif

#define	calloc( a,b ) abalallocate(a*b,ALSMID)
#define	allocate( a ) abalallocate(a,ALSMID)
#define	liberate( a ) aballiberate(a,ALSMID)
void *	abalallocate( int, char * );
void *	aballiberate( void *, char * );

#else
void *	allocate( int );
void *	liberate( void * );
#endif

#endif /* _allocate_h */

