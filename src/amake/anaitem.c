#ifndef	_anaitem_c
#define	_anaitem_c

struct	item_node * allocate_item()
{
	struct item_node * iptr;
	if (!( iptr = allocate( sizeof( struct item_node ) ) ))
		return( iptr );
	else	{
		iptr->previous = iptr->next = (struct item_node *) 0;
		iptr->name 	= (char *) 0;
		iptr->contents 	= (void *) 0;
		iptr->type 	= 0;
		return( iptr );
		}
}

struct	item_node 	* liberate_item(struct item_node * nptr)
{
	if ( nptr ) {
		switch ( nptr->type ) {
			case	_file_item	:
				nptr->contents = liberate_file((struct file_item *) nptr->contents);
				break;
			case	_code_item	:
				nptr->contents = liberate_file((struct file_item *) nptr->contents);
				break;
			case	_call_item	:
				nptr->contents = liberate_file((struct file_item *) nptr->contents);
				break;
			case	_include_item	:
				nptr->contents = liberate_file((struct file_item *) nptr->contents);
				break;
			}
		liberate( nptr );
		}
	return((struct item_node *) 0);
}

int	more_calls( struct item_node * nptr )
{
	while ( nptr ) {
		if ( nptr->type == _call_item )
			return(1);
		else	nptr = nptr->next;
		}
	return(0);
}

void	print_item( struct item_node * nptr, int margin )
{
	struct	file_item * fptr;
	struct	code_item * kptr;
	struct	call_item * cptr;
	struct	include_item * iptr;

	switch ( nptr->type ) {
		case	_file_item	:
			if (( fptr = nptr->contents ) != (struct file_item *) 0) {
				indent(margin);
				switch ( fptr->type ) {
					case	0 :
						if ( options & 1 ) {
							indent(margin);
							printf( "file     %s\n",fptr->name); 
							}
						break;
					case	1 :
						if ( options & 2 ) {
							indent(margin);
							printf( "\nprogram  %s\n",fptr->logical); 
							}
						break;
					case	2 :
						if ( options & 2 ) {
							indent(margin);
							printf( "\nmodule   %s\n",fptr->logical);
							}
						break;
					}
				print_list( &fptr->items,margin );
				}
			break;

		case	_code_item	:
			if (( kptr = nptr->contents ) != (struct code_item *) 0) {
				if ( options & 2 ) {
					if ( margin ) margin=0;
					indent(margin);
					if ( kptr->nature == _code_procedure )
						printf( "proc %s\n",kptr->name);
					else if ( kptr->nature == _code_segment )
						printf( "segment %s\n",kptr->name);
					}
				kptr->lock=1;
				print_list( &kptr->items,(margin+1) );
				kptr->lock=0;
				}
			break;

		case	_call_item	:
			if (( cptr = nptr->contents ) != (struct call_item *) 0) {
				if ( options & 2 ) {
					indent(margin);
					printf( "call %s\n",cptr->name);
					}
				if ((kptr = resolve_code(&files,cptr->name,cptr->nature)) != (struct code_item *) 0) {
					if (!( kptr->lock )) {
						kptr->lock=1;
						if ( options & 2 ) {
							if ( more_calls( nptr->next ) )
								set_margin( margin,'+' );
							else	set_margin( margin,'-' );
							}
						print_list(&kptr->items,(margin+1));
						kptr->lock=0;
						}
					}
				}
			break;

		case	_include_item	:
			if (( iptr = nptr->contents ) != (struct include_item *) 0)  {
				if ((fptr = resolve_file(&files,nptr->name)) != (struct file_item *) 0) {
					if ( options & 1 ) {
						indent(margin);
						printf("[#include %s]\n",nptr->name);
						}
					if (!( fptr->lock )) {
						fptr->lock=1;
						print_list(&fptr->items,margin);
						fptr->lock=0;
						}
					}
				else	{
					if ( options & 1 ) {
						indent(margin);
						printf("(#include %s)\n",nptr->name);
						}
					}
				}


			break;
		}
	return;
}

#endif	/* _anaitem_c */


