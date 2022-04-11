#ifndef	_anacode_c
#define	_anacode_c

struct	code_item 	* liberate_code(struct code_item * cptr)
{
	if ( cptr ) {
		if ( cptr->name )
			liberate( cptr->name );
		liberate_list( & cptr->items );
		liberate( cptr );
		}
	return((struct item_node *) 0);
}

struct	code_item	* resolve_code(struct item_list * lptr, char * codename, int codetype )
{
	struct	inclusion_item * uptr;

	struct	code_item * kptr;
	struct	file_item * fptr;
	struct	item_node * iptr;
	struct	item_node * nptr;
	printf("resolve_code(%s,%u)\r\n",codename,codetype);
	for (	iptr=lptr->first;
		iptr != (struct item_node *) 0;
		iptr = iptr->next ) {
		switch ( iptr->type ) {
			case	_include_item :
				if (!( uptr = iptr->contents ))
					continue;
				else if ((!( fptr = uptr->item ))
				     && (!( fptr = resolve_file( &files, uptr->name ) )))
					continue;
				lptr = &fptr->items;
				for (	nptr=lptr->first;
					nptr != (struct item_node *) 0;
					nptr = nptr->next ) {
					if ( nptr->type != _code_item )
						continue;
					else if (!( kptr = nptr->contents ))
						continue;
					else if ( kptr->nature != codetype )
						continue;
					else if ( compare( kptr->name, codename ) ) {
						printf("found code\r\n");
						return( (struct code_item *) kptr );
						}
					}
				continue;
			case	_code_item	:
				if (!( kptr = iptr->contents ))
					continue;
				else if ( kptr->nature != codetype )
					continue;
				else if ( compare( kptr->name, codename ) ) {
					printf("found code\r\n");
					return( (struct code_item *) kptr );
					}
				else	continue;

			}
		}
	printf("failure\r\n");
	return( (struct code_item *) 0 );


}

struct	code_item * allocate_code()
{
	struct code_item * cptr;
	if (!( cptr = allocate( sizeof( struct code_item ) ) ))
		return( cptr );
	else	{
		cptr->name 	= (char *) 0;
		cptr->nature	= 0;
		cptr->state	= 0;
		cptr->parent	= (struct file_item *) 0;
		cptr->lock	= 0;
		reset_list(&cptr->items);
		return( cptr );
		}
}

void	add_code( struct item_list * lptr, char * nptr, int type )
{
	struct	file_item * fptr;
	struct	code_item * cptr;
	struct	item_node * iptr;
	if ((!( lptr ))
	||  (!( lptr->current ))
	||  (!( fptr = lptr->current->contents )))
		return;
	if ((iptr = allocate_item()) != (struct item_node *) 0) {
		if ((iptr->name = allocate_string(nptr)) != (char *) 0) {
			if ((cptr = allocate_code()) != (struct code_item *) 0) {
				if ((cptr->name = allocate_string(nptr)) != (char *) 0) {
					cptr->nature	= type;
					iptr->contents	= cptr;
					iptr->type	= _code_item;
					cptr->parent	= fptr;
					add_node(&fptr->items, iptr );
					return;
					}
				cptr = liberate_code( cptr );
				}
			}
		iptr = liberate_item( iptr );
		}
	return;
}
				
void	close_code( struct item_list * lptr )
{
	struct	file_item * fptr;
	struct	code_item * cptr;
	struct	item_node * nptr;
	if ((!( lptr ))
	||  (!( lptr->current ))
	||  (!( fptr = lptr->current->contents )))
		return;
	if ((!( lptr = & fptr->items ))
	||  (!( nptr = lptr->current )))
		return;
	if ( nptr->type != _code_item )
		return;
	else if (!( cptr = nptr->contents))
		return;
	cptr->state = 1;
	return;
}

#endif	/* _anacode_c */


