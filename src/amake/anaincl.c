#ifndef	_anaincl_c
#define	_anaincl_c

struct	inclusion_item 	* liberate_inclusion(struct inclusion_item * iptr)
{
	if ( iptr ) {
		if ( iptr->name )
			liberate( iptr->name );
		liberate( iptr );
		}
	return((struct item_node *) 0);
}


struct	inclusion_item * allocate_inclusion()
{
	struct inclusion_item * iptr;
	if (!( iptr = allocate( sizeof( struct inclusion_item ) ) ))
		return( iptr );
	else	{
		iptr->name 	= (char *) 0;
		iptr->item	= (struct file_item*) 0;
		return( iptr );
		}
}

void	add_include( struct item_list * lptr, char * filename )
{
	struct	inclusion_item * iptr;

	struct	file_item * fptr;
	struct	code_item * cptr;
	struct	item_node * nptr;
	struct	item_node * mptr;
	FILE	*h;

	if ((!( lptr ))
	||  (!( lptr->current ))
	||  (!( fptr = lptr->current->contents )))
		return;

	else if (!( iptr = allocate_inclusion() ))
		return;

	else if (!( iptr->name = allocate_filename( filename ) )) {
		liberate_inclusion( iptr );
		return;
		}

	if (!( h = fopen( iptr->name, "r" ) )) {
		if (!(h = fopen((filename = add_extension(filename)),"r")))
			filename = iptr->name;
		else	{
			fclose(h);
			liberate( iptr->name );
			if (!( iptr->name = allocate_filename( filename ) )) {
				liberate_inclusion( iptr );
				return;
				}
			}
		}			
	else	fclose(h);

	if (!( nptr = allocate_item() )) {
		liberate_inclusion( iptr );
		return;
		}
	else if (!( nptr->name = allocate_filename( filename ) )) {
		liberate_item( nptr );
		liberate_inclusion( iptr );
		return;
		}
	else	{
		nptr->contents = iptr;
		nptr->type     = _include_item;
		if (!( mptr = fptr->items.current ))
			add_node(&fptr->items, nptr );
		else if ( mptr->type != _code_item )
			add_node(&fptr->items, nptr );
		else if (!( cptr = mptr->contents ))
			add_node(&fptr->items, nptr );
		else if ( cptr->state )
			add_node(&fptr->items, nptr );
		else	add_node(&cptr->items, nptr );
		return;
		}
}

#endif	/* _anaincl_c */


