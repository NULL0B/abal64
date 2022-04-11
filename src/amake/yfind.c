#ifndef	_yfind_c
#define	_yfind_c

char	findbuffer[256];

int	compare( char * aptr, char * bptr )
{
	while (( *aptr != 0 ) && ( *bptr != 0 ))
		if ( *(aptr++) != *(bptr++))
			return(0);
	if ( *aptr != *bptr)
		return(0);
	else	return(1);
	
}


struct	project * 	locate_project( char * nptr )
{
	struct	project * pptr;
	for (	pptr = root;
		pptr != (struct project *) 0;
		pptr = pptr->next ) {
		if (!( pptr->name ))
			continue;
		else if ( compare( pptr->name, nptr ) )
			break;
		}
	return( pptr );
}

struct	project * 	locate_any_project( struct project * pptr, char * nptr )
{
	for (	;pptr != (struct project *) 0;
		pptr = pptr->next ) {
		if (!( pptr->name ))
			continue;
		else if (!( wildcomp( pptr->name, nptr ) ))
			break;
		}
	return( pptr );
}

struct	project * 	first_project( char * nptr )
{
	return( locate_any_project( root , nptr ) );
}

struct	project * 	next_project( struct project * pptr, char * nptr )
{
	return( locate_any_project( pptr->next , nptr ) );
}
			
struct	section * 	locate_section( struct project * pptr, char * nptr )
{
	struct 	section * sptr;
	for (	sptr=pptr->root;
		sptr != (struct section *)0;
		sptr = sptr->next ) {
		if (!( sptr->name ))
			continue;
		else if ( compare( sptr->name, nptr ) )
			break;
		}
	return( sptr );
}

struct	section * 	locate_any_section( struct section * sptr, char * nptr )
{
	for (	;
		sptr != (struct section *)0;
		sptr = sptr->next ) {
		if (!( sptr->name ))
			continue;
		if ( !( wildcomp( sptr->name, nptr ) ))
			break;
		}
	return( sptr );
}

struct	section * 	locate_postfixed_section( struct project *  pptr , char * prefix, char * postfix )
{
	sprintf( findbuffer,"%s%s",prefix,postfix);
	return( locate_section( pptr, findbuffer ) );
}

struct	section * 	first_section(struct project * pptr,char * nptr )
{
	return( locate_any_section( pptr->root , nptr ) );
}

struct	section * 	next_section( struct section * sptr, char * nptr )
{
	return( locate_any_section( sptr->next , nptr ) );
}

struct	member * 	locate_member( struct section * sptr, char * nptr )
{
	struct 	member * mptr;
	for (	mptr=sptr->root;
		mptr != (struct member *)0;
		mptr = mptr->next ) {
		if (!( mptr->name ))
			continue;
		else if ( compare( mptr->name, nptr ) )
			break;
		}
	return( mptr );
}

int	locate_integer_member( struct section * sptr, char * nptr )
{
	struct 	member * mptr;
	char	*	vptr;
	int		result=0;
	if (!( mptr = locate_member( sptr, nptr ) ))
		return( -1 );
	for ( vptr=mptr->value;
		*vptr != 0;
		vptr++ ) {
		if (( *vptr >= '0' )
		&&  ( *vptr <= '9' ))
			result = ((result * 10) + (*vptr - '0'));
		else	break;
		}
	return( result );
}

struct	member * 	locate_member_item( struct section * sptr, char * nptr, int i )
{
	sprintf(findbuffer,"%s%u",nptr,i);
	return( locate_member( sptr, findbuffer ) );
}

#endif 	// _yfind_c

