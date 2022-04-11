#ifndef	_singdict_c
#define	_singdict_c

#include "singdict.h"

private	void	liberate_dictionary_term( struct dictionary_term * dptr )
{
	int	i;
	char *	sptr;
	for (	i=0; i < MAXNATLANG; i++ ) {
		if ((sptr = dptr->normalised[i]) != (char *) 0)
			liberate( sptr );
		if ((sptr = dptr->messages[i]) != (char *) 0)
			liberate( sptr );
		}
	liberate( dptr );
	return;

}

private	struct dictionary_term * allocate_dictionary_term()
{
	int	i;
	struct	dictionary_term * dptr;
	i = sizeof( struct dictionary_term );
	if (( dptr = allocate( sizeof( struct dictionary_term ) )) != (struct dictionary_term*)0) {
		dptr->next = dptr->previous = (struct dictionary_term *) 0;
		for (	i=0; i < MAXNATLANG; i++ ) {
			dptr->normalised[i] = dptr->messages[i] = (char *) 0;
			dptr->hashcode[i] = 0;
			}
		}
	return( dptr );
}

private	char *	normalise_term( char * mptr )
{
	char	*nptr;
	char	*sptr;
	char	*rptr;
	if (( nptr = allocate_string(mptr)) != (char *) 0) {
		sptr=mptr;
		rptr = nptr;
		while ( *sptr != 0 ) {
			if ( *sptr == '&' )
				sptr++;
			else if (( *sptr >='a' ) && ( *sptr <= 'z' ))
				*(rptr++) = (*(sptr++) - ('a' - 'A'));
			else	*(rptr++) = *(sptr++);
			}
		*rptr=0;
		}
	return( nptr );
}

private	int	calculate_hash( char * sptr, int n )
{
	int	r=0;
	while ( *sptr ) r += *(sptr++);
	return( r % n );
}


private	struct dictionary_term * locate_dictionary_term(char * mptr )
{
	struct	dictionary_term * dptr=(struct dictionary_term*) 0;
	char	*	nptr;
	int		dhash;
	int		thash;
	if (!( mptr ))
		return( dptr );
	if (!( nptr = normalise_term( mptr )))
		return( dptr );
	dhash = calculate_hash( nptr, DICTIONARYHASH );
	thash = calculate_hash( nptr, TERMHASH );
	for (	dptr = dictionary[dhash];
		dptr != (struct dictionary_term *) 0;
		dptr = dptr->next ) {
		if ( dptr->hashcode[0] != thash )
			continue;
		else if (!( string_compare( dptr->normalised[0], nptr ) ))
			continue;
		else	break;
		}
	liberate( nptr );
	return( dptr );
}

		

public	void	initialise_dictionary()
{
	int	i;
	for (i=0; i < DICTIONARYHASH; i++)
		dictionary[i] = (struct dictionary_term *) 0;
	return;
}

public	void	add_dictionary_term(struct form_item * iptr)
{
	int	i;
	struct	dictionary_term * dptr;
	if (!( dptr = locate_dictionary_term(iptr->Contents.messages[0]))) { 
		if (!( dptr = allocate_dictionary_term() ))
			return;
		for ( i=0; i < MAXNATLANG; i++ ) {
			if (!( iptr->Contents.messages[i]))
				continue;
			else if (!( dptr->messages[i] = allocate_string( iptr->Contents.messages[i] ) ))
				break;
			}
		if ( dptr->messages[0] != (char *) 0 ) {
			dptr->normalised[0] = normalise_term( iptr->Contents.messages[0] );
			dptr->hashcode[0]   = calculate_hash( dptr->normalised[0], TERMHASH );
			i = calculate_hash( dptr->normalised[0], DICTIONARYHASH );
			if ((dptr->next = dictionary[i]) != (struct dictionary_term *) 0)
				dptr->next->previous = dptr;
			dictionary[i] = dptr;
			}
		if ( dptr->messages[0] )
			status_message(dptr->messages[0],2);
		if ( dptr->messages[1] )
			status_message(dptr->messages[1],3);
		}
	else 	{
		for ( i=0; i < MAXNATLANG; i++ ) {
			if (!( dptr->messages[i] ))
				continue;
			else if ( iptr->Contents.messages[i] != (char *) 0)
				continue;
			else if (!(iptr->Contents.messages[i] = allocate_string( dptr->messages[i] )))
				break;
			}
		}
	return;
}

public	void	terminate_dictionary()
{
	int	i;
	struct	dictionary_term * dptr;
	for (i=0; i < DICTIONARYHASH; i++) {
		while ((dptr = dictionary[i]) != (struct dictionary_term *) 0) {
			dictionary[i] = dptr->next;
			liberate_dictionary_term( dptr );
			}
		}
	return;
}

#endif	/* _singdict_c */





















