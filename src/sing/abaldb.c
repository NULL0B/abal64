#ifndef	_abaldb_c
#define	_abaldb_c

#include "abaljoin.c"

private	char *	extract_db_filename( char * sptr, int number )
{
	char *	rptr;
	char *	tptr;
	int	i=0;
	if (!( sptr ))
		return( sptr );
	else if (!( sptr = allocate_string( sptr )))
		return( sptr );
	else	rptr = sptr;

	while ( i < number ) {
		while ( *sptr )
			if ( *(sptr++) == '|' ) 
				break;
		if (!( *sptr ))
			break;
		i++;
		}
	/* not enough strings */
	if (i < number ) {
		liberate( rptr );
		return((char *) 0);
		}
	tptr = sptr;
	while ( *sptr ) {
		if ( *sptr == '|' ) 
			break;
		else	sptr++;
		}
	if ( *sptr == '|' )
		*sptr = 0;
	sptr = allocate_string( tptr );
	liberate( rptr );
	return( sptr );
}

public	void	abal_db_assign(FILE * h, struct form_item* iptr, int margin )
{
	int	t=(iptr->Contents.align & 0x000F);
	char	* filename;
	if (!( filename = extract_db_filename( abal_payload(iptr), 0)))
		return;
	abal_ngf_instruction(h,iptr,__abal_keyword_assign,margin);
	filename_parameter(h,filename);
	liberate( filename );
	switch ( t ) {
		case	_VMEMORY_FRAME	:	break;
		case	_SIFILE_FRAME	:	fprintf(h,",SI"); 	break;
		case	_MCFILE_FRAME	:	fprintf(h,",MC"); 	break;
		case	_SQFILE_FRAME	:	fprintf(h,",SQ"); 	break;
		case	_DBFILE_FRAME	:	fprintf(h,",DB"); 	break;
		}

	if (!( iptr->Contents.align & _A_SHADOW ))
		fprintf(h,",WR");

	if (( iptr->Contents.align & _A_LINE ))
		fprintf(h,",EX");

	abal_ngf_errortrap(h,iptr,(char *) 0);
	if ( t == _MCFILE_FRAME ) { fprintf(h,",t_%s",iptr->Contents.name); }
	linefeed(h);
	return;
}

public	void	abal_ngf_file(FILE * h, struct form_item* iptr, int margin, char * basename, int number )
{
	char	* filename;
	if (!( filename = extract_db_filename( abal_payload(iptr), (number+1))))
		return;
	abal_ngf_instruction(h,iptr,__abal_keyword_file,margin);
	filename_parameter(h,filename);
	liberate( filename );
	fprintf(h,",MC(h_%s)",basename);
	if (!( iptr->Contents.align & _A_SHADOW ))
		fprintf(h,",WR");

	if (( iptr->Contents.align & _A_LINE ))
		fprintf(h,",EX");

	abal_ngf_errortrap(h,iptr,(char *) 0);
	fprintf(h,",t_%s",iptr->Contents.name);
	linefeed(h);
	return;
}

private	void	abal_base_instance( FILE * h, struct form_item * iptr, struct	data_control * dptr )
{
	struct	file_control * fptr;
	struct	data_control * xptr;
	char *	holdname=(char *) 0;
	char	classname[256];
	char	wname[256];
	char *	nptr;
	int	a;
	int	n;
	int	i;
	if (!( h ))
		return;
	else if (!( iptr ))
		return;
	else if (!( dptr ))
		return;
	else if (!( holdname = iptr->Contents.name ))
		return;
	else	a = iptr->Contents.align;
	for (	i=0; i < dptr->datafields; i++ ) {
		if ( dptr->type[i+dptr->indexfields] != _ABAL_OBJ )
			continue;
		else if (!( nptr = dptr->name[i+dptr->indexfields] ))
			continue;
		else 	{
			for ( n=0; *(nptr+n) != 0; n++ ) {
				if ((classname[n] = *(nptr+n)) == ' ' )
					break;
				else if (classname[n] == '/' )
					break;
				}
			classname[n] = 0;
			if (!( xptr = resolve_class_data((void*)0, classname ) )) {
				abal_syntax_error(h,classname,78);
				break;
				}
			else	{
				iptr->Contents.extra = xptr;
				iptr->Contents.align &= ~0x000F;
				iptr->Contents.align |= _MCFILE_FRAME; 
				iptr->Contents.xlimit = xptr->indexlength;
				iptr->Contents.ylimit = xptr->datalength;
				while ( *(nptr+n) == ' ' ) n++;
				sprintf(wname,"%s_%s",(nptr+n),holdname);
				iptr->Contents.name = wname;
				abal_file_instance(h,iptr,_MCFILE_FRAME);
				}
			}
		}
	iptr->Contents.xlimit = 
	iptr->Contents.ylimit = 0;
	iptr->Contents.extra = (void *) dptr;
	iptr->Contents.align = a;
	iptr->Contents.name  = holdname;
	return;
}

private	char *	abal_basefile_stub( struct form_item * iptr, int item )
{
	char	*	nptr;
	int		n=0;
	struct	data_control * dptr;
	if (!( iptr ))
		return((char*) 0);
	else if (!( dptr = iptr->Contents.extra ))
		return((char*) 0);
	else if ( item >= dptr->datafields )
		return((char*) 0);
	else if ( dptr->type[item+dptr->indexfields] != _ABAL_OBJ )
		return((char*) 0);
	else if (!( nptr = dptr->name[item+dptr->indexfields] ))
		return((char*) 0);
	else	{
		for (	n=0; *(nptr+n) != 0; n++ )
			if (*(nptr+n) == ' ' )
				break;
		while ( *(nptr+n) == ' ' ) n++;
		return( (nptr+n) );
		}	
}

public	struct data_control * abal_basefile_structure(FILE * h, struct form_item * iptr,int i )
{
	struct	data_control * dptr;
	struct	data_control * xptr;
	char	classname[256];
	char *	nptr;
	int	n;
	char	wname[256];

	if (!( iptr ))
		return((struct data_control *) 0);
	else if (!( dptr = iptr->Contents.extra ))
		return((struct data_control *) 0);
	else if ( dptr->type[i] != _ABAL_OBJ )
		return((struct data_control *) 0);
	else if (!( nptr = dptr->name[i] ))
		return((struct data_control *) 0);
	else 	{
		for ( n=0; *(nptr+n) != 0; n++ )
			if ((classname[n] = *(nptr+n)) == ' ' )
				break;
		classname[n] = 0;
		if (!( xptr = resolve_class_data((void*)0, classname ) )) 
			abal_syntax_error(h,classname,78);
		return( xptr );
		}
}

public	void	abal_basefile_expression(FILE * h, struct form_item * iptr,int f, char * bfname, char * token )
{
	struct data_control * dptr;
	struct data_control * xptr;
	int	keyword;
	int	a;
	char * holdname;
	char	wname[256];
	char *	nptr;

	if (!( iptr ))
		return;
	else if (!( dptr = iptr->Contents.extra ))
		return;
	else if (!( holdname = iptr->Contents.name ))
		return;
	else	a = iptr->Contents.align;

	if (!( xptr = abal_basefile_structure(h,iptr, f) ))
		return;
	else	{
		/* create datafile widget */
		iptr->Contents.extra = xptr;
		iptr->Contents.align &= ~0x000F;
		iptr->Contents.align |= _MCFILE_FRAME; 
		iptr->Contents.xlimit = xptr->indexlength;
		iptr->Contents.ylimit = xptr->datalength;
		sprintf(wname,"%s_%s",bfname,holdname);
		iptr->Contents.name = wname;
		if (!( abal_data_member_expression( h, iptr , token ) )) {
			if ((keyword = is_data_member( token, 1 )) != -1)
				abal_data_expression(h, iptr, keyword, 1,token );
			else	abal_syntax_error( h, token, 12 );
			}
		/* restore database control widget */
		iptr->Contents.xlimit = 
		iptr->Contents.ylimit = 0;
		iptr->Contents.extra = (void *) dptr;
		iptr->Contents.align = a;
		iptr->Contents.name  = holdname;
		return;
		}
}

private	void	abal_db_assign_files(FILE * h, struct form_item * iptr, int margin )
{
	struct	data_control * dptr;
	struct	file_control * fptr;
	struct	data_control * xptr;
	char *	holdname=(char *) 0;
	char	classname[256];
	char	wname[256];
	char *	nptr;
	int	a;
	int	n;
	int	i;
	if (!( h ))
		return;
	else if (!( iptr ))
		return;
	else if (!( dptr = iptr->Contents.extra ))
		return;
	else if (!( holdname = iptr->Contents.name ))
		return;
	else	a = iptr->Contents.align;
	/* initialise collect table */
	/* ------------------------ */
	indent(h,margin); fprintf(h,"pl_%s = 0",holdname); linefeed(h);
	for (	i=0; i < dptr->datafields; i++ ) {
		if ( dptr->type[i+dptr->indexfields] != _ABAL_OBJ )
			continue;
		else if (!( nptr = dptr->name[i+dptr->indexfields] ))
			continue;
		else 	{
			for ( n=0; *(nptr+n) != 0; n++ )
				if ((classname[n] = *(nptr+n)) == ' ' )
					break;
			classname[n] = 0;
			if (!( xptr = resolve_class_data((void*)0, classname ) )) {
				abal_syntax_error(h,classname,78);
				break;
				}
			else	{
				iptr->Contents.extra = xptr;
				iptr->Contents.align &= ~0x000F;
				iptr->Contents.align |= _MCFILE_FRAME; 
				iptr->Contents.xlimit = xptr->indexlength;
				iptr->Contents.ylimit = xptr->datalength;
				while ( *(nptr+n) == ' ' ) n++;
				sprintf(wname,"%s_%s",(nptr+n),holdname);
				iptr->Contents.name = wname;
				abal_file_simc_construction(h,iptr,margin);
				abal_file_handle_construction(h,iptr,margin);
				abal_ngf_file(h,iptr,margin,holdname,i);				
				indent(h,margin);
				/* adjust database collect table for primary index size */
				/* ---------------------------------------------------- */
				fprintf(h,"pl_%s += Len(k_%s)",holdname,wname);
				linefeed(h);
				}
			}
		}
	iptr->Contents.xlimit = 
	iptr->Contents.ylimit = 0;
	iptr->Contents.extra = (void *) dptr;
	iptr->Contents.align = a;
	iptr->Contents.name  = holdname;
	return;
}

private	void	abal_db_file_keys( FILE * h, struct form_item * iptr, int margin )
{
	struct	data_control * dptr;
	struct	file_control * fptr;
	struct	data_control * xptr;
	char *	holdname=(char *) 0;
	char	classname[256];
	char	wname[256];
	char *	nptr;
	int	a;
	int	n;
	int	i;
	if (!( h ))
		return;
	else if (!( iptr ))
		return;
	else if (!( dptr = iptr->Contents.extra ))
		return;
	else if (!( holdname = iptr->Contents.name ))
		return;
	else	a = iptr->Contents.align;
	for (	i=0; i < dptr->datafields; i++ ) {
		if ( dptr->type[i+dptr->indexfields] != _ABAL_OBJ )
			continue;
		else if (!( nptr = dptr->name[i+dptr->indexfields] ))
			continue;
		else 	{
			for ( n=0; *(nptr+n) != 0; n++ )
				if ((classname[n] = *(nptr+n)) == ' ' )
					break;
			classname[n] = 0;
			if (!( xptr = resolve_class_data((void*)0, classname ) )) {
				abal_syntax_error(h,classname,78);
				break;
				}
			else	{
				iptr->Contents.extra = xptr;
				iptr->Contents.align &= ~0x000F;
				iptr->Contents.align |= _MCFILE_FRAME; 
				iptr->Contents.xlimit = xptr->indexlength;
				iptr->Contents.ylimit = xptr->datalength;
				while ( *(nptr+n) == ' ' ) n++;
				sprintf(wname,"%s_%s",(nptr+n),holdname);
				iptr->Contents.name = wname;
				abal_file_simc_construction(h,iptr,margin);
				abal_file_handle_construction(h,iptr,margin);
				abal_ngf_file(h,iptr,margin,holdname,i);				
				indent(h,margin);
				/* adjust database collect table for primary index size */
				/* ---------------------------------------------------- */
				fprintf(h,"pl_%s += Len(k_%s)",holdname,wname);
				linefeed(h);
				abal_ngf_open_create(h,iptr,margin);
				abal_mc_links_and_keys(h,iptr,margin);
				abal_basefile_record(h,iptr,margin);
				}
			}
		}
	iptr->Contents.xlimit = 
	iptr->Contents.ylimit = 0;
	iptr->Contents.extra = (void *) dptr;
	iptr->Contents.align = a;
	iptr->Contents.name  = holdname;
	return;
}


private	void	abal_basefile_locate( FILE * h, struct form_item * iptr, int i, int margin, int lock )
{
	struct	data_control * dptr;
	struct	data_control * xptr;
	char *	holdname=(char *) 0;
	char	wname[256];
	char	classname[256];
	char *	nptr;
	int	a;
	int	n;
	if (!( h ))
		return;
	else if (!( iptr ))
		return;
	else if (!( dptr = iptr->Contents.extra ))
		return;
	else if (!( holdname = iptr->Contents.name ))
		return;
	else	a = iptr->Contents.align;

	if ( dptr->type[i] != _ABAL_OBJ )
		return;
	else if (!( nptr = dptr->name[i] ))
		return;
	else 	{
		for ( n=0; *(nptr+n) != 0; n++ )
			if ((classname[n] = *(nptr+n)) == ' ' )
				break;
		classname[n] = 0;
		if (!( xptr = resolve_class_data((void*)0, classname ) )) {
			abal_syntax_error(h,classname,78);
			return;
			}
		else	{
			iptr->Contents.extra = xptr;
			iptr->Contents.align &= ~0x000F;
			iptr->Contents.align |= _MCFILE_FRAME; 
			iptr->Contents.xlimit = xptr->indexlength;
			iptr->Contents.ylimit = xptr->datalength;
			while ( *(nptr+n) == ' ' ) n++;
			sprintf(wname,"%s_%s",(nptr+n),holdname);
			iptr->Contents.name = wname;

			switch ( lock ) {
				case	'L'	:	abal_ngf_lock(h,iptr,margin);		break;
				case	'M' 	:	abal_ngf_searchm(h,iptr,margin);	break;
				default		:	abal_ngf_search(h,iptr,margin);		break;
				}
			iptr->Contents.xlimit = 
			iptr->Contents.ylimit = 0;
			iptr->Contents.extra = (void *) dptr;
			iptr->Contents.align = a;
			iptr->Contents.name  = holdname;
			return;
			}
		}
}

public	void	abal_db_jointures( FILE * h, struct form_item * iptr, int margin )
{
	int	jointures=0;
	int	i;
	int	si;
	int	ti;
	int	state=2;
	struct	data_control * dptr;
	char	classname[256];
	char *	nptr;
	int	n;
	char *	sclass;
	char *	tclass;
	char *	smember;
	char *	tmember;
	struct	link_control * lptr;
	struct	join_list * jlist;
	if (!( h ))
		return;
	else if (!( iptr ))
		return;
	else if (!( dptr = iptr->Contents.extra ))
		return;
	else if (!( jlist = allocate_jointure_list() ))
		return;
	for ( 	lptr  = FileManager->firstlink;
		lptr != (struct link_control *) 0;
		lptr = lptr->next ) {
		if (!( lptr->source ))
			continue;
		else if (!( lptr->target ))
			continue;
		else if ( lptr->inhibit )
			continue;
		else if (!( sclass = allocate_string(lptr->source)))
			break;
		else if (!( tclass = allocate_string(lptr->target)))
			break;
		for ( si=0; *(sclass+si) != 0; si++ )
			if ( *(sclass+si) == '.' )
				break;
		*(sclass+si) = 0; smember = (sclass+si+1);
		for ( ti=0; *(tclass+ti) != 0; ti++ )
			if ( *(tclass+ti) == '.' )
				break;
		*(tclass+ti) = 0; tmember = (tclass+ti+1);
		for ( i=0; i < dptr->datafields; i++ ) {
			if ( dptr->type[i] != _ABAL_OBJ )
				continue;
			else if (!( nptr = dptr->name[i] ))
				continue;
			for ( n=0; *(nptr+n) != 0; n++ )
				if ((classname[n] = *(nptr+n)) == ' ' )
					break;
			classname[n] = 0;
			if (!( strcmp( classname, sclass )))
				state &= ~1;
			if (!( strcmp( classname, tclass )))
				state &= ~2;
			if (!( state ))
				break;
			}
		if (!( state )) {
			add_jointure( jlist, lptr->jointure, smember, tmember );
			add_jointure_links( jlist, lptr->jointure, sclass );
			add_jointure_links( jlist, lptr->jointure, tclass );
			jointures++;
			}
		if ( sclass ) sclass = liberate( sclass );
		if ( tclass ) tclass = liberate( tclass );
		}
	if ( jointures ) {
		generate_jointures(h,jlist,iptr,margin);
		abal_ngf_instruction(h,iptr,__abal_keyword_cjoin,margin);
		abal_ngf_errortrap(h,iptr,(char *) 0);
		linefeed(h);
		}
	drop_jointure_list(jlist);
	return;
}

public	void	abal_database_destruction( FILE * h, struct form_item * iptr, int margin )
{
	struct	data_control * dptr;
	struct	file_control * fptr;
	struct	data_control * xptr;
	char *	holdname=(char *) 0;
	char	classname[256];
	char	wname[256];
	char *	nptr;
	int	a;
	int	n;
	int	i;
	if (!( h ))
		return;
	else if (!( iptr ))
		return;
	else if (!( dptr = iptr->Contents.extra ))
		return;
	else if (!( holdname = iptr->Contents.name ))
		return;
	else	a = iptr->Contents.align;

	for (	i=dptr->datafields; i > 0; i-- ) {
		if ( dptr->type[i-1] != _ABAL_OBJ )
			continue;
		else if (!( nptr = dptr->name[i-1] ))
			continue;
		else 	{
			for ( n=0; *(nptr+n) != 0; n++ )
				if ((classname[n] = *(nptr+n)) == ' ' )
					break;
			classname[n] = 0;
			if (!( xptr = resolve_class_data((void*)0, classname ) )) {
				abal_syntax_error(h,classname,78);
				break;
				}
			else	{
				iptr->Contents.extra = xptr;
				iptr->Contents.align &= ~0x000F;
				iptr->Contents.align |= _MCFILE_FRAME; 
				iptr->Contents.xlimit = xptr->indexlength;
				iptr->Contents.ylimit = xptr->datalength;
				while ( *(nptr+n) == ' ' ) n++;
				sprintf(wname,"%s_%s",(nptr+n),holdname);
				iptr->Contents.name = wname;
				abal_data_destruction(h,iptr,margin);
				}
			}
		}
	iptr->Contents.xlimit = 
	iptr->Contents.ylimit = 0;
	iptr->Contents.extra = (void *) dptr;
	iptr->Contents.align = a;
	iptr->Contents.name  = holdname;
	return;
}

public	int	is_db_basefile( struct data_control * dptr, char * sptr )
{
	int	i;
	char *	nptr;
	int	n;
	char	classname[256];

	if (!( sptr ))
		return( 0 );
	else if (!( dptr ))
		return( 0 );
	for ( i=0; i < dptr->datafields; i++ ) {
		if ( dptr->type[i] != _ABAL_OBJ )
			continue;
		else if (!( nptr = dptr->name[i] ))
			continue;
		for ( n=0; *(nptr+n) != 0; n++ )
			if ((classname[n] = *(nptr+n)) == ' ' )
				break;
		classname[n] = 0;
		if (!( strcmp( classname, sptr )))
			return(1);
		}
	return(0);
}

#endif	/* _abaldb_c */
	/* --------- */

