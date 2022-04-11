#ifndef	_ysymbol_c
#define	_ysymbol_c

#define	TYPE_UNKNOWN	0
#define	TYPE_SOURCE	1
#define	TYPE_PROGRAM 	2
#define	TYPE_MODULE 	3

struct	symbol {
	int	hash;
	int	number;
	char *	name;
	struct symbol * next;
	};
int		symbols=0;
int		sindex=0;
char *		svalues[256][2];
int		rindex=0;
char *		rvalues[256][2];
struct symbol * symbolheap=(struct symbol *) 0;

char	whoops[256];
char	tmpbuffer[256];
char	symbuffer[256];

void	substitution( char * sptr )
{
	char * rptr;

	for ( rptr=sptr; *rptr != 0; rptr++ )
		if ( *rptr == '=' )
			break;

	if ( *rptr == '=' )
		*(rptr++) = 0;

	svalues[sindex][0] = sptr;
	svalues[sindex][1] = rptr;
	sindex++;
	return;
}

void	redirection( char * sptr )
{
	char * rptr;

	for ( rptr=sptr; *rptr != 0; rptr++ )
		if ( *rptr == '=' )
			break;

	if ( *rptr == '=' )
		*(rptr++) = 0;

	rvalues[rindex][0] = sptr;
	rvalues[rindex][1] = rptr;
	rindex++;
	return;
}

int	scompare( char * tptr, char * sptr, char * rptr )
{
	while ( *sptr ) {
		if (!( *tptr )) return(0);
		else if ( *sptr != *tptr )
			return(0);
		else	{
			sptr++;
			tptr++;
			}	
		}
	strcpy( whoops, rptr );
	strcat( whoops, tptr );
	return(1);
}

char *	rcompare( char * tptr, char * sptr, char * rptr )
{
	char * optr = tptr;
	while ( *sptr ) {
		if (!( *tptr )) return((char *) 0);
		else if ( *sptr != *tptr )
			return((char *) 0);
		else	{
			sptr++;
			tptr++;
			}	
		}
	strcpy( whoops, rptr );
	strcat( whoops, optr );
	return(whoops);
}


char * redirect_filename( char * nptr )
{
	int	i;
	char *	rptr=(char *) 0;
	if ( rindex ) 
		for (i=0; i < rindex; i++ )  
			if ((rptr = rcompare( nptr, rvalues[i][0], rvalues[i][1] ) ) != (char *)0) 
				break;
	return(rptr);
}

struct symbol * locate_symbol( char * nptr )
{
	struct symbol * sptr;
	int	h;
	int	i;

	if ( sindex ) {
		for (i=0; i < sindex; i++ )  {
			if ( scompare( nptr, svalues[i][0], svalues[i][1] ) ) {
				nptr = whoops;
				break;
				}
			}
		}
	for (i=0,h=0; *(nptr+i) != 0; i++)
		h += *(nptr+i);
	for ( sptr=symbolheap;
		sptr != (struct symbol *) 0;
		sptr = sptr->next ) {
		if ( sptr->hash != h )
			continue;
		else if ( compare( sptr->name, nptr ) )
			return( sptr );
		else	continue;
		}
	if (!( sptr = allocate( sizeof( struct symbol ) ) ))
		return( sptr );
	else if (!(sptr->name = allocate( strlen( nptr ) +1 ) )) {
		liberate( sptr );
		return((struct symbol *) 0);
		}
	else	{
		strcpy( sptr->name, nptr );
		sptr->number = symbols++;
		sptr->hash = h;
		sptr->next = symbolheap;
		fprintf(Output.defhandle,"PATH%u = %s\n",sptr->number,sptr->name);
		return((symbolheap = sptr));
		}
}

char 	*	symbolic_filename( char * nptr )
{
	char *	wptr;
	struct symbol * sptr;

	if ((( fn_parser( nptr, tmpbuffer, 0x0018 )) != 0)
	&&  ((wptr = redirect_filename( tmpbuffer )) != (char *) 0))
		nptr = wptr;

	if (!( fn_parser( nptr, tmpbuffer, 0x0007 ) ))
		return( nptr );
	else if (!( sptr = locate_symbol( tmpbuffer ))) 
		return((char *) 0 );
	else if (!( fn_parser( nptr, tmpbuffer, 0x0018 ) ))
		return( nptr );
	else	{
		sprintf(symbuffer,"$(PATH%u)%s",sptr->number,tmpbuffer);
		return( symbuffer );
		}
}

char	expansion_buffer[1024];

char  *	resolve_filename( char * sptr )
{
	int	n=0;
	struct symbol * yptr;
	if ( *sptr != '$' )
		return( sptr );
	else	{
		sptr += 6;
		while (( *sptr >= '0' ) && ( *sptr <= '9' ))
			n = ((n * 10) + ( *(sptr++) - '0' ));
		if ( *sptr == ')' )
			sptr++;
		for (	yptr = symbolheap;
			yptr != (struct symbol *) 0;
			yptr = yptr->next )
			if ( yptr->number == n )
				break;
		if (!( yptr )) 	return((char *) 0 );

		sprintf(expansion_buffer,"%s%s",yptr->name,sptr);
		return( expansion_buffer );
		}
}

void	drop_symbols()
{
	struct	symbol * sptr;

	while ((sptr = symbolheap) != (struct symbol*) 0) {
		symbolheap = sptr->next;
		if ( sptr->name )
			liberate( sptr->name );
		liberate( sptr );
		}
	symbols = 0;
	return;
}


	
#endif 	// _ysymbol_c

