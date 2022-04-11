#ifndef	_singdict_c
#define	_singdict_c

#include "singdict.h"

private	int	SourceLanguage=0;
private	int	DictionaryOptions=0;

private	void	liberate_dictionary_term( struct dictionary_term * dptr )
{
	int	n=0;
	int	i;
	char *	sptr;
	for (	i=0; i < MAXNATLANG; i++ ) {
		if ((sptr = dptr->normalised[i]) != (char *) 0) {
			liberate( sptr );
			}
		if ((sptr = dptr->messages[i]) != (char *) 0) { 
			if ( DictionaryOptions & 4) { printf("%u : [%s]\n",i,sptr); }
			n++;
			liberate( sptr );
			}
		}
	if ( DictionaryOptions & 4) { if ( n )  { printf("\n"); } }
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
		if ( dptr->hashcode[SourceLanguage] != thash )
			continue;
		else if (!( string_compare( dptr->normalised[SourceLanguage], nptr ) ))
			continue;
		else	break;
		}
	liberate( nptr );
	return( dptr );
}

		

public	void	initialise_dictionary(int slang,int options)
{
	int	i;
	SourceLanguage = slang;
	DictionaryOptions = options;
	for (i=0; i < DICTIONARYHASH; i++)
		dictionary[i] = (struct dictionary_term *) 0;
	return;
}

public	void	add_dictionary_term(struct form_item * iptr)
{
	int	i;
	int	j;
	struct	dictionary_term * dptr;
	if (!( dptr = locate_dictionary_term(iptr->Contents.messages[SourceLanguage]))) { 
		if (!( dptr = allocate_dictionary_term() ))
			return;
		for ( i=0; i < MAXNATLANG; i++ ) {
			if (!( iptr->Contents.messages[i])) {
				for (j=0; j < MAXNATLANG; j++ ) {
					if ( iptr->Contents.messages[j] ) {
						iptr->Contents.messages[i] = allocate_string( iptr->Contents.messages[j]);
						break;
						}
					}
				continue;
				}
			if (!( dptr->messages[i] = allocate_string( iptr->Contents.messages[i] ) )) {
				for (j=0; j < MAXNATLANG; j++ ) {
					if ( iptr->Contents.messages[j] ) {
						dptr->messages[i] = allocate_string( iptr->Contents.messages[j]);
						break;
						}
					}
				}
			}
		if ( dptr->messages[SourceLanguage] != (char *) 0 ) {
			dptr->normalised[SourceLanguage] = normalise_term( iptr->Contents.messages[SourceLanguage] );
			dptr->hashcode[SourceLanguage]   = calculate_hash( dptr->normalised[SourceLanguage], TERMHASH );
			i = calculate_hash( dptr->normalised[SourceLanguage], DICTIONARYHASH );
			if ((dptr->next = dictionary[i]) != (struct dictionary_term *) 0)
				dptr->next->previous = dptr;
			dictionary[i] = dptr;
			}
		if ( dptr->messages[SourceLanguage] )
			status_message(dptr->messages[SourceLanguage],2);
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





















