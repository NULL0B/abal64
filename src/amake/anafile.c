#ifndef	_anafile_c
#define	_anafile_c

struct	file_item 	* liberate_file(struct file_item * fptr)
{
	if ( fptr ) {
		if ( fptr->name )
			liberate( fptr->name );
		liberate_list( &fptr->items );
		liberate( fptr );
		}
	return((struct item_node *) 0);
}

struct	file_item	* resolve_file(struct item_list * lptr, char * nptr )
{
	struct	item_node * iptr;
	printf("resolve_file(%s)\r\n",nptr);
	for (	iptr=lptr->first;
		iptr != (struct item_node *) 0;
		iptr = iptr->next ) {
		if ( iptr->type != _file_item )
			continue;
		else if ( compare( iptr->name, nptr ) )
			return( (struct file_item *) iptr->contents );
		}
	return( (struct file_item *) 0 );

}

char	*	allocate_filename(char * sptr)
{
	char *	rptr;
	if (!( rptr = allocate_string( sptr )))
		return( rptr );
	else	{
		for (	sptr=rptr;
			*sptr != 0;
			sptr++) {
			switch ( *sptr ) {
				case	'#'	:
				case	'%'	:
				case	'-'	:
				case	'+'	:
					*sptr = '_';
					continue;
				default		:
					if (( *sptr >= 'A' )
					&&  ( *sptr <= 'Z' ))
						*sptr = ( *sptr + ('a' - 'A') );
				}
			}
		return( rptr );
		}
}

struct	file_item * allocate_file()
{
	struct file_item * fptr;
	if (!( fptr = allocate( sizeof( struct file_item ) ) ))
		return( fptr );
	else	{
		fptr->logical	= (char *) 0;
		fptr->type	= 0;
		fptr->name 	= (char *) 0;
		fptr->nature	= 0;
		fptr->lock	= 0;
		reset_list(&fptr->items);
		return( fptr );
		}
}

void	add_file( struct item_list * lptr, char * nptr )
{
	struct	file_item * fptr;
	struct	item_node * iptr;

	if ((iptr = allocate_item()) != (struct item_node *) 0) {
		if ((iptr->name = allocate_filename(nptr)) != (char *) 0) {
			if ((fptr = allocate_file()) != (struct file_item *) 0) {
				if ((fptr->name = allocate_filename(nptr)) != (char *) 0) {
					iptr->contents = fptr;
					iptr->type     = _file_item;
					add_node(lptr, iptr );
					return;
					}
				fptr = liberate_file( fptr );
				}
			}
		iptr = liberate_item( iptr );
		}
	return;
}
				
void	program_file(char * nptr )
{
	struct	item_node * iptr;
	struct	file_item * fptr;
	if (!(iptr=files.current))
		return;
	else if (!( fptr=iptr->contents))
		return;
	else if (fptr->type) 
		printf("error : %s already %s \r\n",fptr->name,(fptr->type == 1 ? "PROGRAM" : "MODULE"));
	else	{
		fptr->type = 1;
		fptr->logical = allocate_string( nptr );
		}
	return;
}

void	module_file(char * nptr )
{
	struct	item_node * iptr;
	struct	file_item * fptr;
	if (!(iptr=files.current))
		return;
	else if (!( fptr=iptr->contents))
		return;
	else if (fptr->type) 
		printf("error : %s already %s \r\n",fptr->name,(fptr->type == 1 ? "PROGRAM" : "MODULE"));
	else	{
		fptr->type = 2;
		fptr->logical = allocate_string( nptr );
		}
	return;
}


#endif	/* _anafile_c */


