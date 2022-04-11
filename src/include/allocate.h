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
#ifdef	_PROTOTYPES
void *	abalallocate( int, char * );
void *	aballiberate( void *, char * );
#else
void *	abalallocate();
void *	aballiberate();
#endif
#else
void *	allocate( int );
void *	liberate( void * );
#endif
char * allocate_string(char *);

#endif /* _allocate_h */
