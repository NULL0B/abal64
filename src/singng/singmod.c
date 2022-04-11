#ifndef	_SINGMOD_C
#define	_SINGMOD_C

private	int onload(struct model_node * nptr,int option) { return(0); }
private	int onshow(struct model_node * nptr,int option) { return(0); }
private	int onedit(struct model_node * nptr,int option) { return(0); }
private	int onprod(struct model_node * nptr,int option) { return(0); }
private	int onsave(struct model_node * nptr,int option) { return(0); }
private	int ondrop(struct model_node * nptr,int option) { return(0); }

public	struct model_node *	allocate_model()
{
	struct model_node * nptr=(struct model_node *) 0;

	if (!( nptr = allocate( sizeof( struct model_node ) ) ))
		return(nptr);
	else	{
		nptr->previous	=
		nptr->next 	= (struct model_node *) 0;
		nptr->nature 	= 0;
		nptr->name 	= (char *) 0;
		nptr->contents	= (void *) 0;
		nptr->onload    = onload;
		nptr->onshow    = onshow;
		nptr->onedit    = onedit;
		nptr->onprod    = onprod;
		nptr->onsave    = onsave;
		nptr->ondrop    = ondrop;
		return( nptr );
		}
}

public	struct model_node *	add_model_node( int type, void * value, char * token )
{
	struct model_node * nptr=(struct model_node *) 0;

	if (!( value ))
		return(nptr);
	else if (!( nptr = allocate( sizeof( struct model_node ) ) ))
		return(nptr);
	else	{
		nptr->nature 	= type;
		nptr->contents	= value;
		nptr->name = allocate_string( token );
		if ((nptr->previous  = Context.ModelHeap) != (struct model_node *) 0)
			nptr->previous->next = nptr;
		nptr->next = (struct model_node *) 0;
		return( nptr );
		}
}

public	void		drop_model_node( struct model_node * nptr )
{
	if (!( nptr ))
		return;
	if ( nptr->next )
		nptr->next->previous = nptr->previous;
	if (!( nptr->previous ))
		Context.ModelHeap = nptr->next;
	nptr->previous = nptr->next = (struct model_node *) 0;
	nptr->contents = (void *) 0;
	nptr->nature   = 0;
	if ( nptr->name )
		nptr->name = liberate( nptr->name );
	nptr = liberate( nptr );
	return;
}


public	int	use_model_node( struct model_node * nptr )
{
	if (!( nptr ))
		return( 0 );
	else if (!( nptr->contents ))
		return( 0 );
	else	{
		switch ( nptr->nature ) {
			case	_IMAGE_MODEL	:
				return( edit_Image( nptr->name, (struct standard_image **) &nptr->contents ) );
			case	_FONT_MODEL	:
			case	_FORM_MODEL	:
			case	_FILE_MODEL	:
			case	_CLASS_MODEL	:
			default			:
				return(0);
			}
		}
}

#endif	/* _SINGMOD_C */



