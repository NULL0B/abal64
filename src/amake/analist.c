#ifndef	_analist_c
#define	_analist_c


void	print_list( struct item_list * lptr, int margin );

void	reset_list( struct item_list * lptr )
{
	lptr->first = lptr->last = lptr->current = (struct item_list*)0;
	return;
}

void	liberate_list(struct item_list * lptr)
{
	struct	item_node * nptr;
	if (!( lptr ))
		return;
	while ((nptr = lptr->first) != ( struct item_node *) 0) {
		lptr->first = nptr->next;
		liberate_item( nptr );
		}
	reset_list( lptr );
	return;
}


void	print_list( struct item_list * lptr, int margin )
{
	struct	item_node * nptr;
	for ( 	nptr=lptr->first;
		nptr != (struct item_node *) 0;
		nptr = nptr->next ) {
		print_item(nptr,margin);
		}
	return;
}

void	add_node( struct item_list * lptr, struct item_node * nptr)
{
	if (!( lptr ))
		return;
	else if (!( nptr ))
		return;
	if (!( nptr->previous = lptr->last ))
		lptr->first = nptr;
	else	lptr->last->next = nptr;
	lptr->current = lptr->last = nptr;
	return;
}

int	program_list(struct item_list * lptr)
{
	int	programs=0;
	struct	file_item * fptr;
	struct	item_node * nptr;
	for ( 	nptr=lptr->first;
		nptr != (struct item_node *) 0;
		nptr = nptr->next ) {
		if (!( fptr = nptr->contents ))
			continue;
		else if (fptr->type != 1)
			continue;
		else	{
			reset_margins();
			print_item(nptr,0);
			reset_margins();
			programs++;
			}
		}
	return(programs);
}

int	module_list(struct item_list * lptr)
{
	struct	file_item * fptr;
	struct	item_node * nptr;
	int	modules=0;
	for ( 	nptr=lptr->first;
		nptr != (struct item_node *) 0;
		nptr = nptr->next ) {
		if (!( fptr = nptr->contents ))
			continue;
		else if (fptr->type != 2)
			continue;
		else	{
			reset_margins();
			print_item(nptr,0);
			reset_margins();
			modules++;
			}
		}
	return(modules);
}



#endif	/* _anacall_c */











