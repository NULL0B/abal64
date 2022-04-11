#ifndef	_ymake_c
#define	_ymake_c

void	comment( FILE * h, char * prefix, char * postfix )
{
	int	i=0;
	fprintf(h,"# %s : %s\n",prefix,postfix);
	fprintf(h,"# ");
	for (	i = (strlen( prefix ) + strlen( postfix) + 3);
		i != 0;
		i-- )
		fprintf(h,"-");
	fprintf(h,"\n"	);
	return;
}

void	inclusion( FILE * h, char * nptr)
{
	fprintf(h,"! include %s\n",nptr);
	return;
}

int	build_target( struct project * pptr, struct member * tptr )
{
	struct	section * sptr;
	struct	member * mptr;
	char	*	nptr;
	int	s;
	int	tt;
	int	st;
	int	pending=0;
	int	modules=0;

	comment(Output.mfhandle,"Target",tptr->value);

	if (!( nptr = build_filename( pptr, tptr->value, &tt )))
		return( report_error( 30 ) );
	else	fprintf(Output.mfhandle,"%s:",nptr);

	if ( tt == TYPE_PROGRAM ) {
		/* detect modules */
		if (( sptr    = locate_section( pptr, tptr->value)) != (struct section *) 0)  {
			for (	modules=0,pending=0,s=0,mptr = locate_member_item(sptr,"SourceFile",s);
				mptr != (struct member *) 0;
				s++,mptr = locate_member_item(sptr,"SourceFile",s)) {
				if (!( nptr = build_filename( pptr, mptr->value, &st )))
					return( report_error( 30 ) );
				switch ( st ) {
					case	TYPE_UNKNOWN	:
					case	TYPE_MODULE	:
						modules++;
					}
				}
			}
		}

	if (( sptr    = locate_section( pptr, tptr->value)) != (struct section *) 0)  {
		for (	pending=0,s=0,mptr = locate_member_item(sptr,"SourceFile",s);
			mptr != (struct member *) 0;
			s++,mptr = locate_member_item(sptr,"SourceFile",s)) {
			if (!( nptr = build_filename( pptr, mptr->value, &st )))
				return( report_error( 30 ) );
			switch ( tt ) {
				case	TYPE_MODULE	:
					if ( st != TYPE_SOURCE )
						return( report_error( 313 ) );
					else	{
						fprintf(Output.mfhandle," '\n %s",nptr);
						break;
						}

				case	TYPE_PROGRAM	:

					switch ( st ) {
						case	TYPE_UNKNOWN	:
						case	TYPE_MODULE	:
							fprintf(Output.mfhandle," '\n %s",nptr);						
							break;
						case	TYPE_PROGRAM	:
							return( report_error( 314 ) );
						case	TYPE_SOURCE	:
							if ( modules ) {
								pending++;
								if (!( nptr = build_module_filename( pptr, mptr->value, &st )))
									return( report_error( 30 ) );
								}
							fprintf(Output.mfhandle," '\n %s",nptr);
						}
					break;
				default			:
					fprintf(Output.mfhandle," '\n %s",nptr);
				}
			}
		fprintf(Output.mfhandle,"\n");
		if (( tt == TYPE_PROGRAM )
		&&  ( pending != 0       )) {
			for (	pending=0,s=0,mptr = locate_member_item(sptr,"SourceFile",s);
				mptr != (struct member *) 0;
				s++,mptr = locate_member_item(sptr,"SourceFile",s)) {
				if (!( nptr = build_filename( pptr, mptr->value, &st )))
					return( report_error( 30 ) );
				else if ( st == TYPE_SOURCE ) {
					if (!( nptr = build_module_filename( pptr, mptr->value, &tt )))
						return( report_error( 30 ) );
					fprintf(Output.mfhandle,"%s: ",nptr);
					if (!( nptr = build_filename( pptr, mptr->value, &st )))
						return( report_error( 30 ) );
					fprintf(Output.mfhandle," %s \n",nptr);
					}
				}

			}

		}

	fprintf(Output.mfhandle,"\n");
	return(0);

}

int	convert_project( struct project * pptr )
{
	struct member * mptr;
	int	t;
	int	status;
	struct section * sptr;
	comment(Output.defhandle,"Project",pptr->name);
	comment(Output.mfhandle,"Project",pptr->name);
	if (!( sptr = first_section( pptr, "Main.Project.*") ))
		return( report_error( 200 ) );
	else	{
		set_root( pptr->name );
		for (	t=0,mptr = locate_member_item(sptr,"Target",t);
			mptr != (struct member *) 0;
			t++,mptr = locate_member_item(sptr,"Target",t)) 
			if ((status = build_target( pptr, mptr )) != 0)
				break;
		}
	fprintf(Output.mfhandle,"! make\n");
	return(0);
}
 
void	process_project( struct member * mptr )
{
	int	status;
	int	n;
	struct project 	* jptr;
	char		* nptr;
	char	token[64];

	strcpy((nptr = workbuffer), mptr->value );

	if ( *nptr == '"' ) 
		nptr++;

	for ( n=0; *(nptr+n) != 0; n++ )
		if ( *(nptr+n) == '"' )
			break;
	*(nptr+n) = 0;

	while (!(jptr = locate_project(  nptr ) )) 
		if ((status =  loadfile( nptr )) != 0 ) 
			break;
	if ( jptr ) {
		convert_project( jptr );
		}
	else	{
		sprintf(token,"error : %u",status);
		comment(Output.mfhandle, token,nptr);
		}
	return;
}

int	multi_project( struct project * pptr )
{
	struct section 	* sptr;
	struct member 	* mptr;
	int	pBegin=-1;
	int	pEnd=-1;	
	char	token[64];
	int	t,n,status;


	do	{
		if ( verbose )
			printf("Multi Project : %s\n",pptr->name);
		if ((sptr = locate_section( pptr, "Projects" )) != (struct section *) 0) {

			if ((status = open_output( pptr->name )) != 0 )
				return( status );

			comment(Output.defhandle,"Master Project",pptr->name);

			comment(Output.mfhandle,"Master Project",pptr->name);
			inclusion(Output.mfhandle,Output.defname);

			if ((( pBegin = locate_integer_member( sptr,"Begin")) != -1 )
			&&  (( pEnd = locate_integer_member( sptr,"End"))   != -1 )) {
				for ( 	t=pBegin;
					t<=pEnd;
					t++ ) {
					if (!(mptr = locate_member_item( sptr, "Project",t) ))
						continue;
					else	process_project( mptr );
					}
				}
			else	{
				for (	t=0,mptr = locate_member_item(sptr,"Project",t);
					mptr != (struct member *) 0;
					t++,mptr = locate_member_item(sptr,"Project",t))  { 
					process_project( mptr );
					}
				}

			close_output();
	
			}
		else	return( report_error( 78 ) );
		}
	while ((pptr=next_project( pptr, "*.jmp")) !=(struct project*) 0);
	return(0);
		
}

int	mono_project( struct project * pptr )
{
	int	status;
	do	{
		if ((status = open_output( pptr->name )) != 0)
			return( status );
		inclusion(Output.mfhandle,Output.defname);
		convert_project( pptr );
		close_output();
		}
	while ((pptr = next_project( pptr, "*.jrp" )) != (struct project *) 0);
	return(0);
}


int	conversion()
{
	struct	project * pptr;
	struct 	section * sptr;
	struct member *	mptr;
	FILE *	h;
	int	status;
	if ((pptr = first_project( "*.jmp" )) != (struct project *) 0) 
		status = multi_project( pptr ) ;
	else if ((pptr = first_project( "*.jrp" )) != (struct project *) 0)
		status = mono_project( pptr ) ;
		
	if (!( listfile )) 
		return( status );

	else if (!( h = fopen( listfile,"w") ))
		return( report_error( 46 ) );


	for (	pptr = root;
		pptr != (struct project *) 0;
		pptr = pptr->next ) {

		fprintf(h,"%s {\n",pptr->name); 

		for (	sptr = pptr->root;
			sptr != (struct section *) 0;
			sptr = sptr->next ) {

			fprintf(h,"\t%s {\n",sptr->name); 

			for (	mptr = sptr->root;
				mptr != (struct member *) 0;
				mptr = mptr->next ) {
				if ( mptr->name ) {
					fprintf(h,"\t\t%s = ",mptr->name);
					if ( mptr->value )
						fprintf(h,"%s\n",mptr->value);
					else	fprintf(h,"\n");
					}
				}
			fprintf(h,"\t\t}\n"); 
			}
		fprintf(h,"\t}\n");
		}
	fclose( h );
	return(status);
}

#endif	// _ymake_c

