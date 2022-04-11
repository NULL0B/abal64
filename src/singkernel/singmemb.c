
/*	Member Methods	*/
/*	--------------	*/

public	struct forms_method * liberate_Method(struct forms_method * mptr)
{
	if ( mptr ) {
		if ( mptr->name )
			liberate( mptr->name );
		if ( mptr->klass )
			liberate( mptr->klass );
		if ( mptr->signature )
			liberate( mptr->signature );
		if ( mptr->text )
			liberate( mptr->text );
		liberate( mptr );
		}
	return((struct forms_method*) 0);
}

public	void	drop_Method( struct form_control * fptr, struct forms_method * mptr )
{
	if (!( mptr->previous ))
		fptr->rootmethod = mptr->next;
	else	mptr->previous->next = mptr->next;
	if (!( mptr->next ))
		fptr->lastmethod = mptr->previous;
	else	mptr->next->previous = mptr->previous;

	liberate_Method( mptr );

}


public	void	add_Method( struct form_control * fptr, struct forms_method * mptr )
{
	if ((!( mptr )) || (!( fptr )))
		return;
	else	mptr->parent = fptr;
	if (!( mptr->previous = fptr->lastmethod )) {
		if (!( mptr->number ))
			mptr->number = 1;
		fptr->rootmethod = mptr;
		}
	else	{
		fptr->lastmethod->next = mptr;
		if (!( mptr->number ))
			mptr->number = (fptr->lastmethod->number+1);	
		}
	fptr->lastmethod = mptr;
	fptr->method_count++;
	return;
}

public	struct forms_method * allocate_for_Method()
{
	struct forms_method * mptr;
	if (!( mptr = allocate( sizeof( struct forms_method ) ) ))
		return( mptr );
	else	{
		mptr->name = 
		mptr->klass= 
		mptr->signature =
		mptr->text = (char *) 0;
		mptr->number = 0;
		mptr->type   = 0;
		mptr->previous =
		mptr->next     = (struct forms_method *) 0;
		mptr->parent   = (struct form_control *) 0;
		return( mptr );
		}
}


struct	forms_method * locate_Method( int number )
{
	struct form_control *	fptr;
	struct forms_method *	mptr;

	if (!(fptr = Context.Form ))
		return;
	for ( 	mptr = fptr->rootmethod;
		mptr != (struct forms_method *) 0;
		mptr = mptr->next ) {
		if ( mptr->number == number )
			break;
		}
	return( mptr );
}

struct	forms_method * is_forms_Method( char * nptr )
{
	struct form_control *	fptr;
	struct forms_method *	mptr;

	if (!(fptr = Context.Form ))
		return(0);
	for ( 	mptr = fptr->rootmethod;
		mptr != (struct forms_method *) 0;
		mptr = mptr->next ) {
		if (!( mptr->name ))
			continue;
		else if (!( strcmp( mptr->name, nptr ) ))
			return( mptr );
		}
	return( (struct forms_method *) 0 );
}

public	void	drop_forms_method(int id)
{
	struct	forms_method * mptr;
	if (( mptr = locate_Method( id ) ) != (struct forms_method *) 0)
		drop_Method( Context.Form, mptr );
	return;
}

private	void	inspect_forms_method( struct forms_method * mptr, int newmethod )
{
	int	rtype=0;
	int	ispub=0;
	int	isptr=0;
	int	isfunc=0;

	if (!( mptr ))
		return;
	else	{
		if ( mptr->type & _METHOD_PUBLIC )
			ispub = 1;
		else	ispub = 0;
		if ( mptr->type & _METHOD_POINTER )
			isptr = 1;
		else	isptr = 0;
		if (!( mptr->type & _METHOD_FUNCTION ))
			isfunc=1;
		else if (!( mptr->type & _METHOD_VIRTUAL  ))
			isfunc=2;
		else if (!( mptr->type & _METHOD_OVERLOAD ))
			isfunc=3;
		else	isfunc=4;

		rtype = mptr->type & _METHOD_TYPE;
		}

	if ( accept_forms_method(
		&ispub,
		&isptr,&rtype,&mptr->klass,
		&isfunc,&mptr->name,&mptr->signature,&mptr->text) != 27 ) {
		mptr->type = rtype;
		if ( ispub ) mptr->type |= _METHOD_PUBLIC;
		if ( isptr ) mptr->type |= _METHOD_POINTER;
		switch ( isfunc ) {
			case	1 : break;
			case	2 : mptr->type |= _METHOD_FUNCTION; break;
			case	3 : mptr->type |= (_METHOD_FUNCTION|_METHOD_VIRTUAL);  break;
			case	4 : mptr->type |= (_METHOD_FUNCTION|_METHOD_OVERLOAD); break;
			}
		if ( newmethod )
			add_Method( Context.Form, mptr );
		else if (!( mptr->name ))
			drop_Method( Context.Form, mptr );
		}
	return;
}

public	void	edit_forms_method(int id)
{
	struct	forms_method * mptr;
	int	newmethod=0;
	if (!( mptr = locate_Method( id ) )) {
		if (!( mptr = allocate_for_Method() ))
			return;
		else	{
			newmethod=1;
			mptr->parent = Context.Form;
			}
		}
	inspect_forms_method( mptr,newmethod );
	return;
}

int	forms_method_editor( struct form_control *fptr, char * method, int nbline )
{
	struct	forms_method * mptr;
	int	rtype=0;
	int	ispub=0;
	int	isptr=0;
	int	status=0;

	for (	mptr=fptr->rootmethod;
		mptr != (struct forms_method *) 0;
		mptr = mptr->next ) {
		if (!( upper_compare( mptr->name, method ) ))
			continue;
		else	break;
		}

	if (!( mptr ))
		return( 27 );

	else	{
		if ( mptr->type & _METHOD_PUBLIC )
			ispub = 1;
		else	ispub = 0;
		if ( mptr->type & _METHOD_POINTER )
			isptr = 1;
		else	isptr = 0;
		rtype = mptr->type & _METHOD_TYPE;
		}

	if ((status = accept_forms_method(
		&ispub,&isptr,&rtype,
		&mptr->klass,/*FCH_SING*/0,/*FCH_SING*/0,mptr->signature,&mptr->text)) != 27 ) {
		mptr->type = rtype;
		if ( ispub ) mptr->type |= _METHOD_PUBLIC;
		if ( isptr ) mptr->type |= _METHOD_POINTER;
		}
	return( status );
}

void	get_forms_method_information(int item,char * rptr,int rlen, char * nptr, int nlen, char * pptr, int plen, char * tptr, int tlen )
{
	int	i;
	char		    * 	sptr;
	struct forms_method *	mptr;

	if (( mptr = locate_Method( item )) != (struct forms_method *) 0) {
		if ( rptr ) {
			/* decypher return type */
			/* -------------------- */
			switch ( (mptr->type & _METHOD_TYPE) ) {
				case	_METHOD_VOID	: sptr = "void"; break;
				case	_METHOD_BYTE	: sptr = "byte"; break;
				case	_METHOD_WORD	: sptr = "word"; break;
				case	_METHOD_NUMERIC	: sptr = "numeric"; break;
				case	_METHOD_STRING	: sptr = "string"; break;
				case	_METHOD_LONG	: sptr = "long"; break;
				case	_METHOD_CLASS	: sptr = mptr->klass; break;
				default			: sptr = " "; break;
				}

			/* transfer return type */
			/* -------------------- */
			for (i=0; i < rlen; i++ ) {
				if (!( *(sptr+i) )) 
					break;
				else	*(rptr+i) = *(sptr+i);
				}
			for (; i < rlen; i++ )
				*(rptr+i) = ' ';
			}

		/* transfer name */
		/* ------------- */
		if ( nptr ) {
			if ((sptr = mptr->name) != (char *) 0) {
				for (i=0; i < nlen; i++ ) {
					if (!( *(sptr+i) )) 
						break;
					else	*(nptr+i) = *(sptr+i);
					}
				}
			else	i = 0;
			for (; i < nlen; i++ )
				*(nptr+i) = ' ';
			}

		/* transfer signature */
		/* ------------------ */
		if ( pptr ) {
			if ((sptr = mptr->signature) != (char *) 0) {
				for (i=0; i < plen; i++ ) {
					if (!( *(sptr+i) )) 
						break;
					else	*(pptr+i) = *(sptr+i);
					}
				}
			else	i = 0;
			for (; i < plen; i++ )
				*(pptr+i) = ' ';
			}

		/* transfer text */
		/* ------------- */
		if ( tptr ) {
			if ((sptr = mptr->text) != (char *) 0) {
				for (i=0; i < tlen; i++ ) {
					if (!( *(sptr+i) )) 
						break;
					else	*(tptr+i) = *(sptr+i);
					}
				}
			else 	i =0;

			for (; i < tlen; i++ )
				*(tptr+i) = ' ';
			}
		}
	else	{
		/* reset all */
		/* --------- */
		if ( rptr )
			for (i=0; i < rlen; i++ )
				*(rptr+i) = ' ';
		if ( nptr )
			for (i=0; i < nlen; i++ )
				*(nptr+i) = ' ';
		if ( pptr )
			for (i=0; i < plen; i++ )
				*(pptr+i) = ' ';
		if ( tptr )
			for (i=0; i < tlen; i++ )
				*(tptr+i) = ' ';
		}
	return;
}

void	store_to_Method( char ** rptr, char * sptr, int slen )
{
	int	blen;
	int	i;
	char *	bptr;
	if (!( rptr ))
		return;
	if ((bptr = *rptr) != (char *)0 ) {
		liberate( bptr );
		*rptr = (char *) 0;
		}
	if (!( sptr ))
		return;
		
	for ( i=0,blen=0; i < slen; i++ )
		if (*(sptr+i) != ' ')
			blen = (i+1);
	if ( blen ) {
		if (!( bptr = allocate( (blen +1) )))
			return;
		for ( i=0; i < blen; i++ )
			*(bptr+i) = *(sptr+i);
		*(bptr+i) = 0;
		*rptr = bptr;
		}
	return;
}

void	put_forms_method_information(int item,char * rptr,int rlen, char * nptr, int nlen, char * pptr, int plen, char * tptr, int tlen )
{
	struct forms_method *	mptr;

	if (!( mptr = locate_Method( item ))) {
		if (!( mptr = allocate_for_Method() ))
			return;
		else	{
			mptr->parent = Context.Form;
			mptr->number = item;
			add_Method( Context.Form, mptr );
			}
		}
	store_to_Method( &mptr->name     , nptr, nlen );
	store_to_Method( &mptr->signature, pptr, plen );
	store_to_Method( &mptr->text     , tptr, tlen );
	return;
}


/*	Data Members	*/
/*	------------	*/


public	struct forms_data_member * liberate_Member(struct forms_data_member * mptr)
{
	if ( mptr ) {
		if ( mptr->name )
			liberate( mptr->name );
		if ( mptr->klass )
			liberate( mptr->klass );
		if ( mptr->construction )
			liberate( mptr->construction );
		liberate( mptr );
		}
	return((struct forms_data_member*) 0);
}

public	void	drop_Member( struct form_control * fptr, struct forms_data_member * mptr )
{
	if (!( mptr->previous ))
		fptr->rootmethod = mptr->next;
	else	mptr->previous->next = mptr->next;
	if (!( mptr->next ))
		fptr->lastmethod = mptr->previous;
	else	mptr->next->previous = mptr->previous;

	liberate_Member( mptr );

}


public	void	add_Member( struct form_control * fptr, struct forms_data_member * mptr )
{
	if ((!( mptr )) || (!( fptr )))
		return;
	else	mptr->parent = fptr;
	if (!( mptr->previous = fptr->lastmember )) {
		if (!( mptr->number ))
			mptr->number = 1;
		fptr->rootmember = mptr;
		}
	else	{
		fptr->lastmember->next = mptr;
		if (!( mptr->number ))
			mptr->number = (fptr->lastmember->number+1);	
		}
	fptr->lastmember = mptr;
	fptr->member_count++;
	return;
}

public	struct forms_data_member * allocate_for_Member()
{
	struct forms_data_member * mptr;
	if (!( mptr = allocate( sizeof( struct forms_data_member ) ) ))
		return( mptr );
	else	{
		mptr->name = 
		mptr->klass= 
		mptr->construction = (char *) 0;
		mptr->number = 0;
		mptr->type   = 0;
		mptr->size   = 0;
		mptr->first  = 0;
		mptr->second = 0;
		mptr->previous =
		mptr->next     = (struct forms_data_member *) 0;
		mptr->parent   = (struct form_control *) 0;
		return( mptr );
		}
}

public	struct	forms_data_member * get_forms_member(int number)
{
	struct form_control *	fptr;
	struct forms_data_member *	mptr;

	if (!(fptr = Context.Form ))
		return;
	for ( 	mptr = fptr->rootmember;
		mptr != (struct forms_member *) 0;
		mptr = mptr->next ) {
		if ( mptr->number == number )
			break;
		}
	return( mptr );
}


public	void	put_forms_member(int number, char * nptr, int nlen, int size,int first,int second)
{
	int	i;
	int	nouveau=0;
	struct forms_data_member *	mptr;
	if (!( mptr = get_forms_member( number ))) { 
		if (!( mptr = allocate_for_Member()))
			return( mptr );
		else	nouveau=1;
		}
	else	nouveau=0;

	mptr->size = size;
	mptr->first= first;
	mptr->second= second;
	if ( mptr->name )
		liberate( mptr->name );
	if (!( mptr->name = allocate( nlen+1 )))
		return;
	else	{
		for (i=0; i < nlen; i++ ) {
			if ( *(nptr+i) == ' ' )
				break;
			else	*(mptr->name+i) = *(nptr+i);
			}
		*(mptr->name+i)=0;
		}
	if ( nouveau ) {
		mptr->number = number;
		add_Member( Context.Form, mptr );
		}
	return;

}

