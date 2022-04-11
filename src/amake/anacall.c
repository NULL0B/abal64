#ifndef	_anacall_c
#define	_anacall_c


struct	call_item 	* liberate_call(struct call_item * cptr)
{
	if ( cptr ) {
		if ( cptr->name )
			liberate( cptr->name );
		liberate( cptr );
		}
	return((struct item_node *) 0);
}

struct	call_item * allocate_call()
{
	struct call_item * cptr;
	if (!( cptr = allocate( sizeof( struct call_item ) ) ))
		return( cptr );
	else	{
		cptr->name 	= (char *) 0;
		cptr->item	= (struct code_item*) 0;
		return( cptr );


		}
}

void	add_call( struct item_list * lptr, char * codename, int codetype )
{
	struct	file_item * fptr;
	struct	call_item * kptr;
	struct	code_item * cptr;
	struct	item_node * nptr;
	struct	item_node * mptr;

	if ((!( lptr ))
	||  (!( lptr->current ))
	||  (!( fptr = lptr->current->contents ))) {
		return;
		}
	else if (!( kptr = allocate_call() )) {
		return;
		}
	else if (!( kptr->name = allocate_string( codename ) )) {
		liberate_call( kptr );
		return;
		}
	else if (!( nptr = allocate_item() )) {
		liberate_call( kptr );
		return;
		}
	else if (!( nptr->name = allocate_string( codename ) )) {
		liberate_item( nptr );
		liberate_call( kptr );
		return;
		}
	else	{
		kptr->nature   = codetype;
		nptr->contents = kptr;
		nptr->type     = _call_item;
		if (!( mptr = fptr->items.current )) {
			add_node(&fptr->items, nptr );
			}
		else if ( mptr->type != _code_item ) {
			add_node(&fptr->items, nptr );
			}
		else if (!( cptr = mptr->contents )) {
			add_node(&fptr->items, nptr );
			}
		else if ( cptr->state ) {
			add_node(&fptr->items, nptr );
			}
		else	{
			add_node(&cptr->items, nptr );
			}
		return;
		}
}

#endif	/* _anacall_c */


