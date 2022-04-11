#ifndef	_abaljoin_c
#define	_abaljoin_c

#include "abaljoin.h"

private	void	drop_join_link( struct join_link * lptr )
{
	if ( lptr ) {
		if ( lptr->name )
			liberate( lptr->name );
		liberate( lptr );
		}
	return;
}

private	void	drop_jointure( struct join_control * jptr )
{
	struct	join_link * lptr;
	if ( jptr ) {
		if ( jptr->name )
			liberate( jptr->name );
		if ( jptr->value )
			liberate( jptr->value );
		while ((lptr = jptr->first) != (struct join_link *) 0) {
			jptr->first = lptr->next;
			drop_join_link( lptr );
			}
		liberate( jptr );
		}
	return;
}		

private	void	drop_jointure_list( struct join_list * lptr )
{
	struct	join_control * jptr;
	if ( lptr ) {
		while((jptr=lptr->first) != (struct join_control *) 0) {
			lptr->first = jptr->next;
			drop_jointure( jptr );
			}
		liberate( lptr );
		}
	return;
}

private	struct join_list * allocate_jointure_list()
{
	struct	join_list * lptr;
	if (!( lptr = allocate( sizeof( struct join_list ) ) ))
		return( lptr );
	else	{
		lptr->first = lptr->last = (struct join_control *) 0;
		return( lptr );
		}
}

private	struct	join_control * locate_jointure( struct join_list * lptr,char * name )
{
	struct	join_control * jptr;
	for (	jptr=lptr->first;
		jptr != (struct	join_control *) 0;
		jptr = jptr->next ) {
		if (!( jptr->name ))
			continue;
		else if (!( strcmp( jptr->name, name ) ))
			break;
		}
	return( jptr );
}

private	struct	join_link * locate_join_link( struct join_control * lptr,char * name )
{
	struct	join_link * kptr;
	for (	kptr=lptr->first;
		kptr != (struct	join_link *) 0;
		kptr = kptr->next ) {
		if (!( kptr->name ))
			continue;
		else if (!( strcmp( kptr->name, name ) ))
			break;
		}
	return( kptr );
}

private	void	add_join_link( struct join_list * lptr, char * jname, char * lname)
{
	struct	join_control * jptr;
	struct	join_link * kptr;
	if (!( jptr = locate_jointure( lptr, jname )))
		return;
	else if (( kptr = locate_join_link( jptr, lname )) != (struct join_link *) 0)
		return;
	else if (!( kptr = allocate( sizeof( struct join_link ) ) ))
		return;
	else	{
		kptr->previous = kptr->next = (struct	join_link *) 0;
		kptr->name = (char *) 0;
		if (!( kptr->name = allocate_string( lname ))) {
			drop_join_link( kptr );
			return;
			}
		else	{
			if (!( kptr->previous = jptr->last ))
				jptr->first = kptr;
			else	kptr->previous->next = kptr;
			jptr->last = kptr;
			}
		}
	return;
}

private	void	add_jointure(struct join_list * lptr,char * name, char * a, char * b )
{
	struct	join_control * jptr;
	char		     * wptr;
	if (!( lptr ))	return(0);
	if (!( name ))	return(0);
	if (!( a ))	return(0);
	if (!( b ))	return(0);
	if (!( jptr = locate_jointure( lptr, name ))) {
		if (!( jptr = allocate( sizeof( struct join_control ) )))
			return;
		else 	{
			jptr->name = jptr->value = (char *) 0;
			jptr->first = jptr->last = (struct join_link *) 0;
			jptr->previous = jptr->next  = (struct join_control *) 0;
			if (!( jptr->name = allocate_string( name ) )) {
				drop_jointure( jptr );
				return(27);
				}
			else if (!( jptr->value = allocate( strlen( a ) + strlen(b) + 16 ) )) {
				drop_jointure( jptr );
				return(27);
				}
			else	{
				sprintf(jptr->value,"%s=%s",a,b);
				if (!( jptr->previous = lptr->last ))
					lptr->first = jptr;
				else	jptr->previous->next = jptr;
				lptr->last = jptr;
				return(0);
				}
			}
		}
	else if (!( wptr = allocate( strlen( jptr->value ) + strlen( a ) + strlen( b ) + 16 ) ))
		return(27);
	else	{
		sprintf(wptr,"%s,%s=%s",jptr->value,a,b);
		liberate(jptr->value);
		jptr->value = wptr;
		return(0);
		}
}

public	void	generate_jointures(FILE * h, struct join_list * lptr, struct form_item * iptr, int margin )
{
	struct	join_link    * kptr;
	struct	join_control * jptr;
	char		     * wptr;
	if (!( lptr ))	return(0);
	if (!( h ))	return(0);
	for (	jptr=lptr->first;
		jptr != (struct	join_control *) 0;
		jptr = jptr->next ) {
		if (!( jptr->name ))
			continue;
		else if (!( jptr->value ))
			continue;
		else	{
			abal_ngf_instruction(h,iptr,__abal_keyword_join,margin);
			fprintf(h,"(");
			fprintf(h,"%c%s%c",__QUOTE,jptr->name,__QUOTE);
			fprintf(h,"),%c%s%c",__QUOTE,jptr->value,__QUOTE);
			abal_ngf_errortrap(h,iptr,(char *) 0);
			linefeed(h);
			for (	kptr=jptr->first;
				kptr != (struct join_link *) 0;
				kptr = kptr->next ) {
				abal_ngf_instruction(h,iptr,__abal_keyword_link,margin);
				fprintf(h,"(");
				fprintf(h,"%c%s%c",__QUOTE,jptr->name,__QUOTE);
				fprintf(h,"),%c%s%c",__QUOTE,kptr->name,__QUOTE);
				abal_ngf_errortrap(h,iptr,(char *) 0);
				linefeed(h);
				}
			}
		}
	return;
}

public	void	add_jointure_links( struct join_list * lptr, char * jname, char * cname )
{
	struct	data_control *	dptr;
	int	f;
	if (!( dptr = resolve_class_data( (void *) 0, cname )))
		return;
	else	{
		for (	f=0; f < dptr->datafields; f++ ) {
			if ( dptr->type[dptr->indexfields+f]== _ABAL_FIELD )
				continue;
			else if ( dptr->type[dptr->indexfields+f]== _ABAL_FILLER )
				continue;
			else if (!( dptr->special[dptr->indexfields+f] & 1))
				add_join_link( lptr, jname, dptr->name[f+dptr->indexfields] );
			}
		return;
		}
}

#endif	/* _abaljoin_h */
	/* ----------- */


