#ifndef	_allocate_h    
#define _allocate_h
#ifdef	UNIX
#ifdef	FAR
#undef FAR
#endif
#define FAR 
#ifndef	ALSMID
#define	ALSMID "unknown"
#endif
#define	calloc( a,b ) abalallocate(a*b,ALSMID)
#define	allocate( a ) abalallocate(a,ALSMID)
#define	liberate( a ) aballiberate(a,ALSMID)
void *	abalallocate( int, char * );
void *	aballiberate( void *, char * );
char *	allocate_string(char *);
#else
void *	allocate( int );
void *	liberate( void * );
char *	allocate_string(char *);
#endif
#endif /* _allocate_h */

