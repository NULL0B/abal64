
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


public	int	forms_method_count()
{
	struct form_control *	fptr;

	if (!(fptr = Context.Form ))
		return(0);
	else	return( fptr->method_count );
}


public	int	forms_member_count()
{
	struct form_control *	fptr;

	if (!(fptr = Context.Form ))
		return(0);
	return( fptr->member_count );
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
		mptr->hash   = -1;
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

struct	forms_method * insert_Method( int number )
{
	struct form_control *	fptr;
	struct forms_method *	mptr;
	struct forms_method *	yptr;

	if (!(fptr = Context.Form ))
		return;
	for ( 	mptr = fptr->rootmethod;
		mptr != (struct forms_method *) 0;
		mptr = mptr->next ) {
		if ( mptr->number == number )
			break;
		}

	if (!( yptr = allocate_for_Method()))
		return( yptr );

	else if (!( mptr )) {
		if (!( yptr->previous = fptr->lastmethod )) {
			if (!( yptr->number ))
				yptr->number = 1;
			fptr->lastmethod = 
			fptr->rootmethod = yptr;
			}
		else	{
			fptr->lastmethod->next = yptr;
			if (!( yptr->number ))
				yptr->number = (fptr->lastmethod->number+1);	
			fptr->lastmethod = yptr;
			}
		}
	else	{
		if (!( yptr->previous = mptr->previous ))
			fptr->rootmethod = yptr;
		else	mptr->previous->next = yptr;
		mptr->previous = yptr;
		yptr->next     = mptr;
		yptr->number   = mptr->number;
		while ( mptr ) {
			mptr->number++;
			mptr = mptr->next;
			}
		}
	return( yptr );
}

struct	forms_method * is_forms_Method( char * nptr, struct form_control * fptr  )
{
	struct forms_method *	mptr;

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

void	copy_forms_method(int id)
{
	struct	forms_method * mptr;
	struct	forms_method * nptr;

	/* drop current copied method if valid */
	/* ----------------------------------- */
	if (( mptr = Context.CopiedMethod) != (struct forms_method *) 0)
		liberate_Method( mptr );

	Context.CopiedMethod = (struct forms_method *) 0;

	if (( mptr = locate_Method( id ) ) != (struct forms_method *) 0) {
		if (( nptr = allocate_for_Method()) != (struct forms_method *) 0) {
			if ( mptr->name ) {
				store_to_Method( &nptr->name     , mptr->name, strlen(mptr->name));
				}
			if ( mptr->signature ) {	
				store_to_Method( &nptr->signature, mptr->signature, strlen(mptr->signature));
				}
			if ( mptr->text ) {	
				store_to_Method( &nptr->text     , mptr->text, strlen(mptr->text));
				}
			if ( mptr->klass ) {
				store_to_Method( &nptr->klass    , mptr->klass, strlen(mptr->klass));
				}
			nptr->type = mptr->type;
			Context.CopiedMethod=nptr;
			}
		}
	return;

}

public	int	inspect_forms_method( struct forms_method * mptr, int newmethod )
{
	int	status=0;
	int	rtype=0;
	int	ispub=0;
	int	isptr=0;
	int	isfunc=0;
	int	isext=0;

	if (!( mptr ))
		return(0);
	else	{
		if ( mptr->type & _METHOD_PUBLIC )
			ispub = 1;
		else	ispub = 0;
		if ( mptr->type & _METHOD_EXTERN )
			isext = 1;
		else	isext = 0;
		if ( mptr->type & _METHOD_POINTER )
			isptr = 1;
		else	isptr = 0;
		if (!( mptr->type & _METHOD_FUNCTION ))
			isfunc=1;
		else if ((!( mptr->type & _METHOD_VIRTUAL  )) && (!( mptr->type & _METHOD_OVERLOAD )))
			isfunc=2;
		else if (!( mptr->type & _METHOD_OVERLOAD ))
			isfunc=3;
		else	isfunc=4;

		rtype = mptr->type & _METHOD_TYPE;
		}

	if ((status = accept_forms_method(
		&ispub,&isext,
		&isptr,&rtype,&mptr->klass,
		&isfunc,&mptr->name,&mptr->signature,&mptr->text)) != 27 ) {
		mptr->type = rtype;
		if ( ispub ) mptr->type |= _METHOD_PUBLIC;
		if ( isext ) mptr->type |= _METHOD_EXTERN;
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
	return(status);
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
	else	return((status = inspect_forms_method( mptr, 0 )));
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
				case	_METHOD_BYTE	: sptr = "int8"; break;
				case	_METHOD_WORD	: sptr = "int16"; break;
				case	_METHOD_NUMERIC	: sptr = "bcd"; break;
				case	_METHOD_STRING	: sptr = "string"; break;
				case	_METHOD_LONG	: sptr = "int32"; break;
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
			/* Add pointer symbol */
			/* ------------------ */
			if ( mptr->type & _METHOD_POINTER ) {
				sptr = " ptr";
				for (; i < rlen; i++ ) {
					if (!( *sptr )) 
						break;
					else	*(rptr+i) = *(sptr++);
					}
				}

			/* clear to end of string */
			/* ---------------------- */
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

	if (!( mptr = insert_Method( item ))) {
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

int	valid_copied_method()
{
	if (!( Context.CopiedMethod))
		return(0);
	else	return(1);
}

void	paste_forms_method(int id)
{
	struct forms_method *	mptr;
	struct forms_method *	nptr;
	if (( mptr = Context.CopiedMethod) != (struct forms_method *) 0) {
		put_forms_method_information(
			id,
			(char *)0,0,
			mptr->name,(mptr->name ? strlen(mptr->name) : 0),
			mptr->signature,( mptr->signature ? strlen(mptr->signature) : 0),
			mptr->text,( mptr->text ? strlen(mptr->text) : 0)
			);
		if (( nptr = locate_Method( id ) ) != (struct forms_method *) 0)
			nptr->type = mptr->type;
		if ( mptr->klass ) {
			store_to_Method( &nptr->klass , mptr->klass,strlen(mptr->klass) );
			}
		}
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
	int i;
	struct forms_data_member * dptr=NULL;

	if ((!( mptr )) || (!( fptr )))
		return;
	else	mptr->parent = fptr;

	if ((mptr->number) && (mptr->number < fptr->member_count)) {
		for ( 	dptr = fptr->rootmember;
			dptr != (struct forms_member *) 0;
			dptr = dptr->next ) {
			if ((dptr->next) && (dptr->next->number>mptr->number)) {
				mptr->next=dptr->next;
				mptr->previous=dptr;
				dptr->next->previous=mptr;
				dptr->next=mptr;
				break;
				}
			}
		}

	if (dptr==NULL) {
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
		}

	mptr->number_sort=mptr->number;
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
		mptr->comment=	
		mptr->construction = (char *) 0;
		mptr->number = 0;
		mptr->number_sort=0;
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


public	void	put_forms_member(int number, char * nptr, int nlen, int type, int size,int first,int second,char *comment,int lcomment)
{
	int	i;
	int	nouveau=0;
	struct forms_data_member *	mptr;
	if (!( mptr = get_forms_member( number ))) { 
		if (!( mptr = allocate_for_Member()))
			return;
		else	nouveau=1;
		}
	else	nouveau=0;
	mptr->type = type;
	mptr->size = size;
	mptr->first= first;
	mptr->second= second;
	if ( mptr->name )
		liberate( mptr->name );
	if (mptr->comment) 
		liberate(mptr->comment);
	if (!( mptr->name = allocate( nlen+1 )))
		return;
	if (!(mptr->comment = allocate(lcomment+1))) {
		liberate(mptr->name); 
		return;	
		} 
	else	{
		for (i=0; i < nlen; i++ ) {
			if ( *(nptr+i) == ' ' )
				break;
			else	*(mptr->name+i) = *(nptr+i);
			}
		*(mptr->name+i)=0;
		if (lcomment) {
			for (i=lcomment-1; (i) && (comment[i]<=' ') && (comment[i]>=0); i--);
			if ((comment[i]>' ') || (comment[i]<0)) i++;
			if (i) memcpy(mptr->comment,comment,i);
			}
		else	i=0;
		*(mptr->comment+i)=0;
		}
	if ( nouveau ) {
		mptr->number = number;
		mptr->number_sort=number;
		add_Member( Context.Form, mptr );
		}
	return;

}

public	void	insert_forms_member_item(int number)
{
	struct forms_data_member *dptr;

	if ((dptr=get_forms_member(number))!= NULL) {
		for (;dptr != (struct forms_member *) 0;
			dptr = dptr->next ) {
				dptr->number++;
				dptr->number_sort++;
			}
		put_forms_member(number,NULL,0,0,0,0,0,NULL,0);
		}
}

public	void	delete_forms_member_item(int number)
{
	struct forms_data_member *dptr;
	struct form_control *	fptr;


	if (!(fptr = Context.Form ))
		return;
	if ((dptr=get_forms_member(number))!= NULL) {
		drop_Member(fptr,dptr);
		for (	dptr=get_forms_member(number+1);
			dptr != (struct forms_member *) 0;
			dptr = dptr->next ) {
			dptr->number--;
			dptr->number_sort--;
			}
		fptr->member_count--;
		}
}

public void sort_data_member(int typtri)
{
	struct form_control *	fptr;
	struct forms_data_member *	mptr,*cptr;
	int i;
	static int last_sort=0;

	if (last_sort==typtri) 
		return;
	else if (!(fptr = Context.Form ))
		return;
	else if (!( fptr->rootmember ))
		return;

	for (	mptr = fptr->rootmember;
		mptr != (struct forms_member *) 0;
		mptr = mptr->next ) { 
		mptr->number_sort = 0; 
		}

	for (	i=1;
		i<=fptr->lastmember->number;
		i++) {
		cptr=NULL;
		mptr = fptr->rootmember;
		 for (	mptr = fptr->rootmember;
			mptr != (struct forms_member *) 0;
			mptr = mptr->next ) {
			if ((!mptr->number_sort) 
			&&  (compare_member(mptr,cptr,typtri)<0)) 
				cptr=mptr; 
			}
		if (cptr) 
			cptr->number_sort=i;
		}
	last_sort=typtri;
}

int compare_member(struct forms_data_member *first,struct forms_data_member *second,int typtri)
{
	if (second==NULL) return(-1);
	if (first==NULL) return(1);
	switch (typtri)
		{
		case 1	:	
			return(stricmp(first->name,second->name));
		case -1	:
			return(stricmp(second->name,first->name));
		case 2	:	
			if (first->type<second->type) return(-1);
			if (first->type>second->type) return(1);
			return(stricmp(first->name,second->name));
		case -2	:
			if (first->type<second->type) return(1);
			if (first->type>second->type) return(-1);
			return(stricmp(second->name,first->name));
		case 3	:
			if (first->size<second->size) return(-1);
			if (first->size>second->size) return(1);
			return(stricmp(first->name,second->name));
		case -3	:
			if (first->size<second->size) return(1);
			if (first->size>second->size) return(-1);
			return(stricmp(second->name,first->name));
		case 4	:
			if (first->first<second->first) return(-1);
			if (first->first>second->first) return(1);
			return(stricmp(first->name,second->name));
		case -4	:
			if (first->first<second->first) return(1);
			if (first->first>second->first) return(-1);
			return(stricmp(second->name,first->name));
		case 5:
			if (first->second<second->second) return(-1);
			if (first->second>second->second) return(1);
			return(stricmp(first->name,second->name));
		case -5	:
			if (first->second<second->second) return(1);
			if (first->second>second->second) return(-1);
			return(stricmp(second->name,first->name));
		case 6	:
			if ((!second->comment) && (!first->comment))
				return(stricmp(first->name,second->name));
			if (!second->comment) return(-1);
			if (!first->comment) return(1);
			if (!strlen(second->comment)) return(-1);
			if (!strlen(first->comment)) return(1);
			if (stricmp(first->comment,second->comment)<0) return(-1);
			if (stricmp(second->comment,first->comment)<0) return(1);
			return(stricmp(first->name,second->name));
		case -6	:
			if ((!second->comment) && (!first->comment))
				return(stricmp(second->name,first->name));
			if (!second->comment) return(1);
			if (!first->comment) return(-1);
			if (!strlen(second->comment)) return(1);
			if (!strlen(first->comment)) return(-1);
			if (stricmp(first->comment,second->comment)<0) return(1);
			if (stricmp(second->comment,first->comment)<0) return(-1);
			return(stricmp(second->name,first->name));
		case 0	:
		default	:
			if (first->number<second->number)
				return(-1);
			else
				return(1);
	}
}

struct	forms_data_member * duplicate_Member( struct forms_data_member * mptr)
{
	struct	forms_data_member * nptr;
	if (!( nptr = allocate_for_Member()))
		return( nptr );
	else	{
		if ( mptr->name ) {
			nptr->name = allocate_string( mptr->name );
			}
		if ( mptr->klass ) {
			nptr->klass= allocate_string( mptr->klass );
			}
		if ( mptr->comment ) {
			nptr->comment=allocate_string(mptr->comment);
			}
		if ( mptr->construction ) {
			nptr->construction = allocate_string(mptr->construction);
			}
		nptr->number = 0;
		nptr->number_sort=0;
		nptr->type   = mptr->type;
		nptr->size   = mptr->size;
		nptr->first  = mptr->first;
		nptr->second = mptr->second;
		return( nptr );
		}
}

void	copy_forms_member(int id)
{
	struct	forms_data_member * mptr;
	struct	forms_data_member * nptr;

	/* drop current copied method if valid */
	/* ----------------------------------- */
	if (( mptr = Context.CopiedMember) != (struct forms_data_member *) 0)
		liberate_Member( mptr );

	Context.CopiedMember = (struct forms_data_member *) 0;

	if (!( mptr = get_forms_member( id )))
		return;
	else	{
		Context.CopiedMember = duplicate_Member( mptr );
		return;
		}
}

int	valid_copied_member()
{
	if (!( Context.CopiedMember))
		return(0);
	else	return(1);
}

void	paste_forms_member(int id)
{
	struct	form_control * fptr;
	struct	forms_data_member * mptr;
	struct	forms_data_member * nptr;
	if (!( mptr = Context.CopiedMember))
		return;
	else if (!( fptr = Context.Form ))
		return;
	else if (!( nptr = duplicate_Member( mptr )))
		return;
	else	{
		if (!( mptr = fptr->lastmember )) {
			nptr->number = nptr->number_sort=1;
			}
		else	{
			nptr->number = nptr->number_sort=(mptr->number+1);
			}
		add_Member( Context.Form, nptr );
		return;
		}
}

