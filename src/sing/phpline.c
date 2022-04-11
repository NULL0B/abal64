#ifndef	_phpline_c
#define	_phpline_c

#define	MAX_NESTED_THINGS	64
private	char * 	php_widget_name( struct form_item * iptr );
public	char *	php_use_widget_name( struct form_item * iptr );
public  void    abal_php_payload( FILE * h, struct form_item * iptr, int comma );

public	char *	php_use_widget_name( struct form_item * iptr )
{
	return( iptr->Contents.name );
}

private	int	abal_php_error_handler( FILE * h );

struct	try_catcher	{
	int		items;
	char	*	label[MAX_NESTED_THINGS];
	char	*	variable[MAX_NESTED_THINGS];
	} TryCatch = { 0 };

struct	php_variable  {
	char * name;
	int	type;
	int	size;
	int	first;
	int	second;
	int	pointer;
	char *	classname;
	struct php_variable * previous;
	struct php_variable * next;
	};

private	struct	php_control  {
	struct php_variable * 	first;
	struct php_variable * 	last;
	int			fornext;
	int		      	default_terminator;
	int		      	terminator;
	int			braces;
	int			conditional;
	int			selecting;
	int			select_cases;
	char		      	operand[256];
	int			select_case[MAX_NESTED_THINGS];

	} PhpCtrl = { 
		(struct php_variable *) 0,
		(struct php_variable *) 0,
		0,';', ';', 0,0,0,0
		};

private	char *	php_get_token( int mode )
{
	int	c;
	char *	wptr=(char *) 0;
	char *	rptr=(char *) 0;
	char *	sptr=(char *) 0;
	char * 	tptr=(char *) 0;
	if (!( tptr = abal_get_token( mode ) ))
		return( tptr );
	else if ( *tptr != '"' )
		return(tptr);
	else if (!( sptr = allocate_string( tptr ) ))
		return( tptr );
	else if (!( rptr = tptr ))
		return( tptr );
	else if (!( wptr = sptr ))
		return( tptr );
	else	{
		while ( *sptr ) {
			if (( c = *(sptr++)) == '\\' )
				*(rptr++) = '\\';
			*(rptr++) = c;
			}
		*(rptr++) = 0;
		liberate( wptr );
		return( tptr );
		}
}

private	void	php_line_termination(FILE * h)
{
	int	v=PhpCtrl.terminator;

	switch ( PhpCtrl.fornext ) {
		case	0 :
			break;
		case	1 :
			fprintf(h,"; $%s++ ",PhpCtrl.operand);
		case	2 :
			fprintf(h,")");
			break;
		}

	while ( PhpCtrl.braces ) {
		fprintf(h,"%c",')');
		PhpCtrl.braces--;
		}

	if( PhpCtrl.selecting )
		fprintf(h," ) ");

	fprintf(h,"%c",v);
	PhpCtrl.terminator = PhpCtrl.default_terminator;
	PhpCtrl.fornext = 0;
	PhpCtrl.braces  = 0;
	PhpCtrl.conditional = 0;
	PhpCtrl.selecting = 0;
	PhpCtrl.operand[0] = 0;
	return;
}

private	int	php_set_termination(int c)
{
	int	v = PhpCtrl.terminator;
	PhpCtrl.terminator = c;
	return( v );
}

private	int	php_set_default_termination(int c)
{
	int	holder = PhpCtrl.default_terminator;
	PhpCtrl.default_terminator = c;
	return(holder);
}

private	int	php_format_count( int c, char **pptr )
{
	int	v=0;
	char *	sptr;
	if (!( c )) 
		return(0);
	else if (!( pptr ))
		return( 0 );
	else 	sptr = *pptr;

	if ( *sptr == c )
	{
		v=1;
		while ( *sptr == c )
		{
			v++;
			sptr++;
		}
	}
	else if ((*sptr <= '0' ) || ( *sptr >= '9' ))
		return(1);
	else
	{
		for ( v=0; *sptr != 0; sptr++ ) 
		{
			if ((*sptr <= '0' ) || ( *sptr >= '9' ))
				break;
			else	v = ((v*10) + (*(sptr++) - '0'));
		}
	}
	*pptr = sptr;
	return( v );
}

private	void	abal_php_print_to_printf( FILE * h, char * sptr )
{
	int	v;
	int	items=0;
	int	c;

	if (!( sptr )) 
		return( sptr );
	else if ( *(sptr++) != '(' )
		return;

	fprintf(h,"%c",__QUOTE);

	while ((c = *(sptr++)) != 0) {
		if ( c == ')' )
			break;
		else if ( c == ',' )
			continue;
		else if ( c == '"' ) {
			while ((c = *(sptr++)) != 0) {
				if ( c == '"' )
					break;
				else	fprintf(h,"%c",c);
				}
			continue;
			}
		else	{
			switch ( c ) {
				case	'/'	:
					fprintf(h,"\\r");
				case	'X'	:
				case	'T'	:
				case	'\\'	:
					v = php_format_count( c, &sptr );
					for ( ; v != 0; v-- ) {
						switch ( c ) {
							case	'X'	: 
								fprintf(h," ");
								break;
							case	'/'	: 
								fprintf(h,"\\n");
								break;
							case	'T'	:
								fprintf(h,"\\t");
							}
						}						
					continue;

				case	'$'	:
					fprintf(h,"%cs",0x0025);
					continue;
				case	'-'	:
				case	'+'	:
				case	'N'	:
					v = php_format_count( c, &sptr );
					switch ( c ) {
						case	'-'	:
						case	'+'	:
							fprintf(h,"%c0%u.1d",0x0025,v);
							continue;
						case	'N'	:
							fprintf(h,"%c0%u.1u",0x0025,v);
							continue;
						}
					continue;

				case	'Z'	:
				case	'O'	:
				case	'I'	:

				case	'A'	:
				case	'B'	:
				case	'C'	:
				case	'D'	:
				case	'W'	:
				case	'U'	:
					v = php_format_count( c, &sptr );
					switch ( c ) {
						case	'Z'	:
						case	'O'	:
						case	'I'	:
							fprintf(h,"%c0%u.%uu",0x0025,v,v);
							continue;
						case	'A'	:
						case	'B'	:
						case	'C'	:
						case	'D'	:
						case	'W'	:
						case	'U'	:
							fprintf(h,"%c0%u.%us",0x0025,v,v);
							continue;
						}
				}

			}
		}
	fprintf(h,"%c",__QUOTE);
	return;
}

private	char *	abal_php_convert_print( FILE * h, char * tptr )
{
	char	abuffer[8192];
	int	a=0;
	int	c;
	if ((c = abal_get_punctuation()) !=  '(') {
		if ( c ) parser_ungetch();
		return( tptr );
		}
	else	{
		fprintf(h,"sprintf(");
		if ((c = abal_get_punctuation()) !=  '(') {
			if ( c ) parser_ungetch();
			fprintf(h,"%c(E)%c",__QUOTE,__QUOTE);
			}
		else	{
			abuffer[a++] = c;
			while ((c = parser_getch()) != ')' )
				abuffer[a++] = c;
			abuffer[a++] = ')';
			abuffer[a++] = 0;
			abal_php_print_to_printf(h,abuffer);
			}
		return( (char *) 0);
		}
}

private	char *	abal_php_form_line( FILE * h, struct form_item * iptr )
{
	int	c;
	switch ((c = abal_get_punctuation()))
	{
		case	'='	:
			fprintf(h,"$this->%s->setLine(",php_widget_name(iptr));
			PhpCtrl.braces++;				
			break;
		case	'('	:
			fprintf(h,"$this->%s->setLine(",php_widget_name(iptr));
			break;
		default		:
			if ( c ) parser_ungetch();
			fprintf(h,"$this->%s->getLineValue()",php_widget_name(iptr));
	}
	return((char *)0);
}

private	char *	abal_php_form_column( FILE * h, struct form_item * iptr )
{
	int	c;
	char	*	tptr;
	if ((c = abal_get_punctuation()) !=  '(') {
		if ( c ) parser_ungetch();
		fprintf(h,"$this->%s->getColumnValue()",php_widget_name(iptr));
		}
	else	{
		if (( tptr = php_get_token(0)) != (char *) 0) {
			if ((c = abal_get_punctuation()) !=  ')') {
				if ( c ) parser_ungetch();
				return( (char *) 0 );
				}
			else if ((c = abal_get_punctuation()) !=  '=') {
				if ( c ) parser_ungetch();
				fprintf(h,"$this->%s->getColumn(",php_widget_name(iptr));
				fprintf(h,"%s)",tptr);
				}
			else 	{
				fprintf(h,"$this->%s->setColumn(",php_widget_name(iptr));
				fprintf(h,"%s",tptr);
				fprintf(h,",");
				PhpCtrl.braces++;				
				}
			}
		}
	return((char *)0);
}

private	char *	abal_php_form_fontsize( FILE * h, struct form_item * iptr )
{
	int	c;
	char	*	tptr;
	if ((c = abal_get_punctuation()) !=  '(') {
		if ( c ) parser_ungetch();
		fprintf(h,"$this->%s->getFontSize(1)",php_widget_name(iptr));
		}
	else	{
		if (( tptr = php_get_token(0)) != (char *) 0) {
			if ((c = abal_get_punctuation()) !=  ')') {
				if ( c ) parser_ungetch();
				return( (char *) 0 );
				}
			else if ((c = abal_get_punctuation()) !=  '=') {
				if ( c ) parser_ungetch();
				fprintf(h,"$this->%s->getFontSize(",php_widget_name(iptr));
				fprintf(h,"%s)",tptr);
				}
			else 	{
				fprintf(h,"$this->%s->setFontSize(",php_widget_name(iptr));
				fprintf(h,"%s",tptr);
				fprintf(h,",");
				PhpCtrl.braces++;				
				}
			}
		}
	return((char *)0);
}

private	char *	abal_php_form_flag( FILE * h, struct form_item * iptr )
{
	int	c;
	char	*	tptr;
	if ((c = abal_get_punctuation()) !=  '(') {
		if ( c ) parser_ungetch();
		fprintf(h,"$this->%s->getFlagValue()",php_widget_name(iptr));
		}
	else	{
		if (( tptr = php_get_token(0)) != (char *) 0) {
			if ((c = abal_get_punctuation()) !=  ')') {
				if ( c ) parser_ungetch();
				return( (char *) 0 );
				}
			else if ((c = abal_get_punctuation()) !=  '=') {
				if ( c ) parser_ungetch();
				fprintf(h,"$this->%s->getFlag(",php_widget_name(iptr));
				fprintf(h,"%s)",tptr);
				}
			else 	{
				fprintf(h,"$this->%s->setFlag(",php_widget_name(iptr));
				fprintf(h,"%s",tptr);
				fprintf(h,",");
				PhpCtrl.braces++;				
				}
			}
		}
	return((char *)0);
}

private char *  abal_php_form_help( FILE * h, struct form_item * iptr )
{
        int     c;
        char    *       tptr;
        if ((c = abal_get_punctuation()) !=  '(') {
                if ( c ) parser_ungetch();
                fprintf(h,"$this->%s->getHelpValue()",php_widget_name(iptr));
                }
        else    {
                if (( tptr = php_get_token(0)) != (char *) 0) {
                        if ((c = abal_get_punctuation()) !=  ')') {
                                if ( c ) parser_ungetch();
                                return( (char *) 0 );
                                }
                        else if ((c = abal_get_punctuation()) !=  '=') {
                                if ( c ) parser_ungetch();
                                fprintf(h,"$this->%s->getHelp(",php_widget_name(iptr));
                                fprintf(h,"%s)",tptr);
                                }
                        else    {
                                fprintf(h,"$this->%s->setHelp(",php_widget_name(iptr));
                                fprintf(h,"%s",tptr);
                                fprintf(h,",");
                                PhpCtrl.braces++;
                                }
                        }
                }
        return((char *)0);
}

private	struct php_variable * locate_php_variable( char * tptr )
{
	struct	php_variable * vptr;
	for ( 	vptr=PhpCtrl.first;
		vptr != (struct php_control *) 0;
		vptr = vptr->next )
		if (!( strcmp( tptr, vptr->name ) ))
			break;
	return( vptr );
}

private	struct php_variable * allocate_php_variable( char * tptr )
{
	struct	php_variable * vptr;
	if (!( vptr = allocate( sizeof( struct php_variable ) ) ))
		return((struct php_variable *) 0);
	else if (!( vptr->name = allocate_string( tptr ))) {
		liberate( vptr );
		return((struct php_variable *) 0);
		}
	else 	{
		vptr->previous = vptr->next = (struct php_variable *) 0;
		vptr->size = 8;
		vptr->first = 0;
		vptr->second = 0;
		vptr->pointer = 0;
		vptr->classname = (char *) 0;
		if (!( vptr->previous = PhpCtrl.last ))
			PhpCtrl.first = vptr;
		else	PhpCtrl.last->next  = vptr;
		PhpCtrl.last = vptr;
		return( vptr );
		}
}

private	int	php_abal_dcl( FILE * h, int mode, int isp )
{
	struct	php_variable * vptr;
	int	c;
	char *	tptr;
	char *	wptr;
	while (( tptr = php_get_token(0)) != (char *) 0) {
		if (!( vptr = allocate_php_variable( tptr ) ))
			break;
		else	{
			vptr->pointer = isp;
			switch ( *(vptr->name+(strlen(vptr->name)-1)) ) {
				case	'%'	: 
					vptr->type = 1;
					vptr->size = 2;
					*(vptr->name+(strlen(vptr->name)-1)) = 0;
					break;
				case	'#'	: 
					vptr->type = 0;
					vptr->size = 1;
					*(vptr->name+(strlen(vptr->name)-1)) = 0;
					break;
				case	'$'	: 
					vptr->type = 3;
					vptr->size = 15;
					*(vptr->name+(strlen(vptr->name)-1)) = 0;
					break;
				case	':'	: 
					vptr->type = 5;
					vptr->size = 4;
					*(vptr->name+(strlen(vptr->name)-1)) = 0;
					break;
				default		:
					vptr->type = 2;
					vptr->size = 8;
					break;
				}
			// printf(" php variable %s \r\n",vptr->name);
			while (1) {
				if (!( c = not_white_space() ))
					break;
				else if (!( c = parser_getch() ))
					break;
				switch ( c ) {
					case	'%'	:
						vptr->type = 1; continue;
					case	':'	:
						vptr->type = 5; continue;
					case	'#'	:
						vptr->type = 0; continue;
					case	'$'	:
						vptr->type = 3; continue;
					case	'='	:
						if (!( wptr = php_get_token(0)))
							break;
						else	{
							vptr->size = atoi( wptr );
							continue;
							}
					case	'('	:
						if (!( wptr = php_get_token(0)))
							break;
						else	{
							vptr->first = atoi( wptr );
							if (!( c = not_white_space() ))
								break;
							else if (!( c = parser_getch() ))
								break;
							else if ( c == ')' )
								continue;
							else if ( c != ',' )
								break;
							else if (!( wptr = php_get_token(0)))
								break;
							else	{
								vptr->first = atoi( wptr );
								continue;
								}
							}
					case	')'	:
						continue;
					}
				break;
				}
			}	
		}
	return(1);
}

private	int	php_abal_instance_member( FILE * h, char * tptr )
{
	int	c;

	fprintf(h,"$%s->",tptr);

	if (!( tptr = php_get_token(0) ))
		return(0);

	fprintf(h,"%s",tptr);

	c = abal_get_punctuation();

	if ( c ) parser_ungetch();

	if ( c == '(' ) {
		(void) abal_php_invocation_parameters( h );
		}
	return(1);
}
	
private	int	php_abal_variable( FILE * h, char * tptr )
{
	int	c;
	struct	php_variable * vptr;
	for ( 	vptr=PhpCtrl.first;
		vptr != (struct php_control *) 0;
		vptr = vptr->next ) {
		if (!( strcmp( tptr, vptr->name ) )) {
			if (!( vptr->classname )) {
				fprintf(h,"$%s",tptr);
				if ( vptr->first )
					abal_php_array_index( h );
				}
			else if ((c = parser_getch()) != '.' ) {
				if ( c ) parser_ungetch();
				}
			else if (!( php_abal_instance_member( h, tptr )))
				return(0);
			return(1);
			}
		}
	return(0);
}

private	int	php_forms_member( FILE * h,struct form_control * fptr, char * tptr, int mode )
{
	struct	forms_data_member * mptr;
	struct	php_variable * vptr;
	for ( 	mptr=fptr->rootmember;
		mptr != (struct forms_method *) 0;
		mptr = mptr->next ) {
		if (!( strcmp( tptr, mptr->name ) )) {
			if ( mode )
				fprintf(h,"$this->%s",tptr);
			else	fprintf(h,"->%s",tptr);
			return(1);
			}
		}
	return(0);
}

private	int	php_forms_method( FILE * h,struct form_control * fptr, char * tptr, int mode )
{
	int	c;
	char * 	sptr;
	struct	forms_method * mptr;
	struct	php_variable * vptr;
	for ( 	mptr=fptr->rootmethod;
		mptr != (struct forms_method *) 0;
		mptr = mptr->next ) 
	{
		if (!( strcmp( tptr, mptr->name ) )) 
		{
			if ( mode )
				fprintf(h,"$this->%s",tptr);
			else	fprintf(h,"->%s",tptr);
			if ((c = parser_getch()) == '(' )
			{
				if (!(sptr=mptr->signature))
					fprintf(h,"($psn");
				else
				{
					while ( *sptr )
					{
						if ( *sptr != ' ' )
							break;
						else	sptr++;
					}
					if (!( *sptr ))
						fprintf(h,"($psn");
					else	fprintf(h,"($psn,");
				}
			}
			else
			{
				if ( c ) parser_ungetch();
				fprintf(h,"($psn)");
			}
			return(1);
		}
	}
	return(0);
}

private	int	php_abal_for( FILE * h )
{
	char *	tptr;
	if (!( tptr = php_get_token(0)))
		return(0);

	fprintf(h,"for ( $%s",tptr);
	strcpy(PhpCtrl.operand, tptr );
	php_set_termination('{');
	PhpCtrl.fornext=1;
	return(1);
}

private	int	php_abal_for_to( FILE * h )
{
	fprintf(h,"; $%s <= ",PhpCtrl.operand);
	return(1);
}

private	int	php_abal_for_step( FILE * h )
{
	fprintf(h,"; $%s  = $%s ",PhpCtrl.operand,PhpCtrl.operand);
	PhpCtrl.fornext=2;
	return(1);
}

private	void	remove_try_catcher( int i )
{
	int	x;
	if (( TryCatch.items ) && ( i < TryCatch.items )) {
		if ( TryCatch.label[i] ) 	liberate( TryCatch.label[i] );
		if ( TryCatch.variable[i] );	liberate( TryCatch.variable[i] );
		while ( (i+1) < TryCatch.items ) {
			TryCatch.label[i] = TryCatch.label[i+1];
			TryCatch.variable[i] = TryCatch.variable[i+1];
			}
		TryCatch.label[i] = TryCatch.variable[i] = (char *) 0;
		TryCatch.items--;
		}
	return;
}


private	int	abal_php_error_handler( FILE * h )
{
	char *	tptr;
	int	c;
	/* --------------------------------- */
	/* [On] [Local] ERROR GOTO LABEL,VAR */
	/* --------------------------------- */
	/* must be converted to Try / Catch  */
	/* --------------------------------- */
	if (!( tptr = php_get_token(0) ))
		return(1);
	else if ( upper_compare( tptr, "ABORT" ) )
		return(1);
	else if (!( upper_compare( tptr, "GOTO" ) )) 
		return(1);
	else if ((c = parser_getch()) != '&' )
		return(1);
	else if (!( tptr = php_get_token(0) ))
		return(1);
	else if (!( TryCatch.label[TryCatch.items] = allocate_string( tptr ) ))
		return(1);
	else if ((c = parser_getch()) != ',' )
		return(1);
	else if (!( tptr = php_get_token(0) ))
		return(1);
	else if (!( TryCatch.variable[TryCatch.items] = allocate_string( tptr ) ))
		return(1);
	else	{
		TryCatch.items++;
		fprintf(h,"try {");
		linefeed(h);
		return(1);
		}
}

#include "phpclass.c"
#include "phpngf.c"

private	int	abal_php_clf_event( FILE * h )
{
	int	c;
	char *	xx;
	if ((c = abal_get_punctuation()) !=  '(') {
		if ( c ) parser_ungetch();
		fprintf(h,"$this->abal->abal_event");
		return(1);
		}
	else if (!( xx = abal_php_expression(")",&c) )) {
		fprintf(h,"$this->abal->abal_event");
		return(1);
		}
	else if ((c = abal_get_punctuation()) !=  ')') {
		fprintf(h,"$this->abal->abal_event");
		return(1);
		}
	else if ((c = abal_get_punctuation()) !=  '=') {
		if ( c ) parser_ungetch();
		fprintf(h,"$this->abal->abal_event(%s)",xx);
		return(1);
		}
	else	{
		fprintf(h,"$this->abal->abal_setevent(%s,",xx);
		liberate( xx );
		if (!( xx = abal_php_expression(":",&c) ))
			fprintf(h,"0)");
		else	{
			fprintf(h,"%s)",xx);
			liberate( xx );
			}
		return(1);
		}

}

private	int	abal_php_endif( FILE * h )
{
	php_set_termination('}');
	return(1);
}

private	int	php_filter_forms_keyword( FILE * h, char * tptr, struct forms_control * fptr, int mode )
{
	if ( php_abal_variable( h, tptr ) )
		return(1);
	else if ( php_forms_method( h, fptr, tptr,mode ) )
		return(1);
	else if ( php_forms_member( h, fptr, tptr,mode ) )
		return(1);
	else	return(0);
}
private	int	php_filter_abal_keyword( FILE * h, char * tptr )
{
	int	keyword=0;
	int	i;
	int	c;
	if ( php_filter_forms_keyword( h, tptr, Context.Form,1 ) )
		return(1);
	/* ----------------------------- */
	/* Abal Declarative Instructions */
	/* ----------------------------- */
	else if ( upper_compare( tptr, "DCL" ) ) {
		return( php_abal_dcl(h,1,0) );
		}
	else if ( upper_compare( tptr, "PTR" ) ) {
		return( php_abal_dcl(h,1,1) );
		}
	else if ( upper_compare( tptr, "FIELD" ) ) {
		while (( c = parser_getch()) != 0);
		return(1);
		}
	/* --------------------------- */
	/* Abal Iterative Instructions */
	/* --------------------------- */
	else if ( upper_compare( tptr, "SELECT" ) ) {
		PhpCtrl.select_case[++PhpCtrl.select_cases] = 0;
		fprintf(h,"switch (");
		PhpCtrl.selecting=1;
		php_set_termination('{');
		return(1);
		}
	else if ( upper_compare( tptr, "CASE" ) ) {
		if ( PhpCtrl.select_case[PhpCtrl.select_cases]++ ) {
			fprintf(h,"break;");
			linefeed(h);
			}
		fprintf(h,"case ");
		php_set_termination(':');
		return(1);
		}
	else if ( upper_compare( tptr, "DEFAULT" ) ) {
		if ( PhpCtrl.select_case[PhpCtrl.select_cases]++ ) {
			fprintf(h,"break;");
			linefeed(h);
			}
		fprintf(h,"default ");
		return(1);
		}
	else if ( upper_compare( tptr, "ENDSEL" ) ) {
		if( PhpCtrl.select_cases )
			PhpCtrl.select_cases--;
		fprintf(h,"}");
		linefeed(h);
		return(1);
		}
	else if ( upper_compare( tptr, "IF" ) ) {
		fprintf(h,"if ");
		PhpCtrl.conditional = 1;
		php_set_termination('{');
		return(1);
		}
	else if ( upper_compare( tptr, "ELSE" ) ) {
		fprintf(h,"}");
		linefeed(h);
		fprintf(h,"\telse ");
		php_set_termination('{');
		return(1);
		}
	else if ( upper_compare( tptr, "ENDIF" ) ) {
		return( abal_php_endif( h ) );
		}
	else if ( upper_compare( tptr, "FOR" ) ) {
		return( php_abal_for( h ) );
		}
	else if ( upper_compare( tptr, "TO" ) ) {
		return( php_abal_for_to( h ) );
		}
	else if ( upper_compare( tptr, "STEP" ) ) {
		return( php_abal_for_step( h ) );
		}
	else if ( upper_compare( tptr, "NEXT" ) ) {
		while (( c = parser_getch()) != 0);
		php_set_termination('}');
		return(1);
		}
	else if ( upper_compare( tptr, "WHILE" ) ) {
		fprintf(h,"while ");
		PhpCtrl.conditional = 1;
		php_set_termination('{');
		return(1);
		}
	else if ( upper_compare( tptr, "WEND" ) ) {
		php_set_termination('}');
		return(1);
		}
	else if ( upper_compare( tptr, "DO" ) ) {
		fprintf(h,"while (1)");
		php_set_termination('{');
		return(1);
		}
	else if ( upper_compare( tptr, "LOOP" ) ) {
		php_set_termination('}');
		return(1);
		}
	else if ( upper_compare( tptr, "BREAK" ) ) {
		fprintf(h,"break");
		return(1);
		}
	else if ( upper_compare( tptr, "REPEAT" ) ) {
		fprintf(h,"do");
		php_set_termination('{');
		return(1);
		}
	else if ( upper_compare( tptr, "UNTIL" ) ) {
		fprintf(h,"}");
		linefeed(h);
		PhpCtrl.conditional = 1;
		fprintf(h,"\twhile  ");
		php_set_termination(';');
		return(1);
		}
	else if ( upper_compare( tptr, "EXIT" ) ) {
		fprintf(h,"return");
		return( 1);
		}
	else if ( upper_compare( tptr, "AND" ) ) {
		if ( PhpCtrl.conditional  )
			fprintf(h," && ");
		else	fprintf(h," & ");
		return( 1);
		}
	else if ( upper_compare( tptr, "OR" ) ) {
		if ( PhpCtrl.conditional  )
			fprintf(h," || ");
		else	fprintf(h," | ");
		return( 1);
		}
	/* ------------------------ */
	/* Common Library Functions */
	/* ------------------------ */
	else if ( upper_compare( tptr, "FIX" ) ) {
		fprintf(h,"$this->abal->abal_fix");
		return( 1);
		}
	else if ( upper_compare( tptr, "ROUN" ) ) {
		fprintf(h,"$this->abal->abal_round");
		return( 1);
		}
	else if ( upper_compare( tptr, "PRINT" ) ) {
		if (  abal_php_convert_print( h, tptr ) )
			return(0);
		else	return(1);
		}
	else if ( upper_compare( tptr, "LEN$" ) ) {
		fprintf(h,"$this->abal->abal_len");
		return( 1);
		}
	else if ( upper_compare( tptr, "CONV$" ) ) {
		fprintf(h,"$this->abal->abal_conv");
		return( 1);
		}
	else if ( upper_compare( tptr, "CONV:" ) ) {
		fprintf(h,"$this->abal->abal_conv");
		return( 1);
		}
	else if ( upper_compare( tptr, "CONV\%" ) ) {
		fprintf(h,"$this->abal->abal_conv");
		return( 1);
		}
	else if ( upper_compare( tptr, "CONV#" ) ) {
		fprintf(h,"$this->abal->abal_conv");
		return( 1);
		}
	else if ( upper_compare( tptr, "CHR$" ) ) {
		fprintf(h,"$this->abal->abal_chr");
		return( 1);
		}
	else if ( upper_compare( tptr, "CONV" ) ) {
		fprintf(h,"$this->abal->abal_conv");
		return( 1);
		}
	else if ( upper_compare( tptr, "INDEX" ) ) {
		fprintf(h,"$this->abal->abal_index");
		return( 1);
		}
	else if ( upper_compare( tptr, "INCLUD" ) ) {
		fprintf(h,"$this->abal->abal_includ");
		return( 1);
		}
	else if ( upper_compare( tptr, "CREATE" ) )
		return( abal_php_clf6( h, tptr ) );
	else if ( upper_compare( tptr, "REMOVE" ) )
		return( abal_php_clf6( h, tptr ) );
	else if ( upper_compare( tptr, "FORGET" ) )
		return( abal_php_clf6( h, tptr ) );
	else if ( upper_compare( tptr, "ATTACH" ) )
		return( abal_php_clf6( h, tptr ) );
	else if ( upper_compare( tptr, "DETACH" ) )
		return( abal_php_clf6( h, tptr ) );
	else if ( upper_compare( tptr, "SHL" ) ) {
		fprintf(h,"$this->abal->abal_shl");
		return( 1);
		}
	else if ( upper_compare( tptr, "SHR" ) ) {
		fprintf(h,"$this->abal->abal_shr");
		return( 1);
		}
	else if ( upper_compare( tptr, "EVENT" ) ) {
		return( abal_php_clf_event(h) );
		}
	else if ( upper_compare( tptr, "SPACE" ) ) {
		fprintf(h,"$this->abal->abal_space");
		return( 1);
		}
	else if ( upper_compare( tptr, "GENER" ) ) {
		fprintf(h,"$this->abal->abal_gener");
		return( 1);
		}
	else if ( upper_compare( tptr, "SUBSTR" ) ) {
		fprintf(h,"$this->abal->abal_substr");
		return( 1);
		}
	else if ( upper_compare( tptr, "LEFT" ) ) {
		fprintf(h,"$this->abal->abal_left");
		return( 1);
		}
	else if ( upper_compare( tptr, "LARGE" ) ) {
		fprintf(h,"$this->abal->abal_large");
		return( 1);
		}
	else if ( upper_compare( tptr, "SMALL" ) ) {
		fprintf(h,"$this->abal->abal_small");
		return( 1);
		}
	else if ( upper_compare( tptr, "MOD" ) ) {
		fprintf(h,"$this->abal->abal_mod");
		return( 1);
		}
	else if ( upper_compare( tptr, "DATE" ) ) {
		fprintf(h,"$this->abal->abal_date");
		return( 1);
		}
	else if ( upper_compare( tptr, "DAYS" ) ) {
		fprintf(h,"$this->abal->abal_days");
		return( 1);
		}
	else if ( upper_compare( tptr, "RIGHT" ) ) {
		fprintf(h,"$this->abal->abal_right");
		return( 1);
		}
	else if ( upper_compare( tptr, "ENV" ) ) {
		fprintf(h,"$this->abal->abal_env");
		return( 1);
		}
	else if ( upper_compare( tptr, "PARSE" ) ) {
		fprintf(h,"$this->abal->abal_parse");
		return( 1);
		}

	else if ((keyword = is_abal_ngf( tptr )) > 0)
		return( abal_php_ngf( h, tptr, keyword-1 ) );
	else if ((keyword = is_abal_class( tptr )) > 0)
		return( abal_php_class_instance( h, tptr, keyword-1 ) );

	else if ( upper_compare( tptr, "FIRSTPAGE" ) ) {
		fprintf(h,"$this->firstpage");
		return( 1);
		}
	else if ( upper_compare( tptr, "RESPONSEFILE" ) ) {
		fprintf(h,"$this->responseFile");
		return( 1);
		}
	else if ( upper_compare( tptr, "CLIENTREDIRECT" ) ) {
		fprintf(h,"$this->clientRedirect");
		return( 1);
		}
	else if ( upper_compare( tptr, "ARGV" ) ) {
		fprintf(h,"$this->ArgV");
		abal_php_array_index( h );
		return( 1);
		}
	else if ( upper_compare( tptr, "ON" ) )
		return(1);
	else if ( upper_compare( tptr, "LOCAL" ) )
		return(1);
	else if ( upper_compare( tptr, "ERROR" ) ) {
		return( abal_php_error_handler( h ) );
		}
	else 	{
		for ( i=0; i < TryCatch.items; i++ ) {
			if ( upper_compare( TryCatch.label[i] , tptr ) ) {
				fprintf(h,"}");
				linefeed(h);
				fprintf(h,"\tcatch ( Exception $%s ) {}",TryCatch.variable[i]);
				linefeed(h);
				remove_try_catcher(i);
				return(1);
				}
			}
		return(0);
		}
}

private	int	abal_php_consume_method( FILE * h )
{
	char * tptr;
	int	c;
	int	braces=0;
	int	quoting=0;
	if ((c = abal_get_punctuation()) !=  '(') {
		if ( c ) parser_ungetch();
		return( 1 );
		}
	else	{
		braces=1;
		while (braces) {
			if ((c = abal_get_punctuation())) {
				if ( quoting ) {
					if ( c == '"' )
						quoting = 0;
					}
				else if ( c == '"' )
					quoting = c;
				else if ( c == "(" )
					braces++;
				else if ( c == ')' ) {
					if ( braces )
						braces--;
					}
				}
			else if (!( tptr = abal_get_token(0) ))
				break;
			}
		return( 0 );
		}
}

private	int	abal_php_convert_member( FILE * h, char * mptr )
{
	switch ( detect_forms_special_method( mptr ) ) {
		case	_FORMS_STDINPUT		:
		case	_FORMS_STDERROR		:
		case	_FORMS_ONHINT		:
		case	_FORMS_ONPAGE		:
		case	_FORMS_ONESCAPE		:
		case	_FORMS_ONENTER		:
		case	_FORMS_ONDEFAULT	:
		case	_FORMS_ONPREVIEW	:
		case	_FORMS_ONPRECONSTR	:
		case	_FORMS_ONPOSTDESTR	:
		case	_FORMS_POSITIONAT	:	return( abal_php_consume_method(h) );

		default				:	return(1);
		}
}

private	char *	abal_php_argv( FILE * h, char * tptr )
{
	char *	sptr;
	int	c;
	if ((c = abal_get_punctuation()) !=  '(') 
	{
		if ( c ) parser_ungetch();
		return( tptr );
	}
	else if (( sptr = php_get_token(0)) != (char *) 0) 
	{
		return((char *) 0 );
	}
	else if ((c = abal_get_punctuation()) !=  ')') 
	{
		if ( c ) parser_ungetch();
		return((char *) 0 );
	}
	else
	{
		fprintf(h,"$ArgV[%s-1]",sptr);
		return((char *) 0);
	}
}

private	int	abal_php_widget_method( FILE * h, char * tptr )
{
	if ( upper_compare( tptr, "ONSHOW" ) )
	{
		fprintf(h,"->ishidden = 0;\n");
		return(1);
	}
	else if ( upper_compare( tptr, "ONHIDE" ) )
	{
		fprintf(h,"->ishidden = 1;\n");
		return(2);
	}
	else if ( upper_compare( tptr, "ONEVENT" ) ) 
		return(3);
	else if ( upper_compare( tptr, "ONFOCUS" ) ) 
		return(4);
	else if ( upper_compare( tptr, "ONLOSE" ) ) 
		return(5);
	else if ( upper_compare( tptr, "ONCREATE" ) ) 
		return(6);
	else if ( upper_compare( tptr, "ONREMOVE" ) ) 
		return(7);
	else	return(0);
}

private	struct form_item * abal_php_locate_widget( char * tptr, struct form_control * fptr )
{
	struct	form_item * iptr;
	if ((iptr = locate_widget( tptr, fptr )) != (struct form_item *) 0)
		return( iptr );
	else if (!( method_is_valid( fptr->extends ) ))
		return( iptr );
	else if (!( fptr = locate_form_control( fptr->extends ) ))
		return( iptr );
	else	return( abal_php_locate_widget( tptr, fptr ) );
}

private	char *	abal_php_convert_token( FILE * h, char * tptr )
{
	char	*	fnptr;
	struct form_control * ffptr;
	struct form_control * fptr;
	struct form_item * iptr;
	int	i;
	int		c;
	int		n;

	/* ------------------------------------- */
	/* Convert "this" to current widget name */
	/* ------------------------------------- */
	if (( LineParser.thisname )
	&&  ( string_compare( tptr, keyword_this) ))
		tptr = LineParser.thisname;

	if ( upper_compare( tptr,"#PHP" ) ) {
		set_line_parser(0);
		return( (char *) 0);
		}

	/* Filter Special Methods */
	/* ---------------------- */
	if ( php_filter_abal_keyword(h, tptr ) ) {
		return( (char *) 0);
		}
	else if ( upper_compare( tptr, "VISUALCONTROL" ) ) {
		fprintf(h,"$this->OnControl");
		return((char *) 0);
		}
	else if ( upper_compare( tptr, "PAGENUMBER" ) ) {
		fprintf(h,"$this->pagenumber");
		return((char *) 0);
		}
	else if ( upper_compare( tptr, "NATIONALLANGUAGE" ) ) {
		fprintf(h,"$this->language");
		return((char *) 0);
		}
	else if ( upper_compare( tptr, "ENDLOC" ) ) {
		return((char *) 0);
		}
	else if ( upper_compare( tptr, "ARGV" ) ) {
		return( abal_php_argv(h, tptr) );
		}
	else if ( upper_compare( tptr, "KEYCODE" ) ) {
		if ((c = parser_getch()) != 0) 
			parser_ungetch();
		if ( c != '.' ) {
			fprintf(h,"$this->formKeyCode");
			return((char *) 0);
			}
		}
	else if ( upper_compare( tptr, "ONSHOW" ) ) {
		(void) remove_brackets();
		return((char *) 0);
		}
	else if ( upper_compare( tptr, "ONHIDE" ) ) {
		(void) remove_brackets();
		return((char *) 0);
		}
	else if ( upper_compare( tptr, "ONEVENT" ) ) {
		(void) remove_brackets();
		return((char *) 0);
		}
	/* -------------------------- */
	/* Resolve Widget name tokens */
	/* -------------------------- */
	if (!( iptr = abal_php_locate_widget( tptr,Context.Form ) ))
		return( tptr );

	/* --------------------------- */
	/* Ensure parent form is valid */
	/* --------------------------- */
	else if (!( fptr = iptr->parent ))
		return( tptr );

	else	{

		if ((c = parser_getch()) != '.' ) {
			if ( c ) parser_ungetch();
			}
		else if (!( tptr = php_get_token(0) )) {
			abal_syntax_error(h,php_widget_name(iptr),12);
			return( tptr );
			}
		else if ((iptr->Contents.style & _FRAME_TYPE) == _DATA_FRAME) {
			fprintf(h,"$this->%s",php_widget_name(iptr));
			if (!( is_file_Widget( iptr ) )) {
				/* we got a component e.member type expression */
				/* ------------------------------------------- */
				if (!( strcasecmp( tptr, "SCALE" ) ))
					fprintf(h,"->scale");
				else 
				switch ((i = is_visual_member( tptr,1 ))) {
					case	VISUAL_MEMBER_X	:
						fprintf(h,"->x"); break;
					case	VISUAL_MEMBER_Y	:
						fprintf(h,"->y"); break;
					case	VISUAL_MEMBER_W	:
						fprintf(h,"->w"); break;
					case	VISUAL_MEMBER_H	:
						fprintf(h,"->h"); break;
					case	VISUAL_MEMBER_BUFFER	:
						fprintf(h,"->buffer"); break;
					default	:
						if (!( abal_php_convert_member(h, tptr ) ))
							return( (char *) 0 );
						else if (( n = abal_php_widget_method( h, tptr ) ) != 0)
						{
							abal_php_consume_method(h);
							return((char *) 0);
						}
						else if (!( fnptr = abal_payload(iptr) )) 
						{
							fprintf(h,"->On%s",tptr);
							return((char *) 0);
						}
						else if (!(ffptr = locate_form_control( fnptr ) ))
						{
							fprintf(h,"->On%s",tptr);
							return((char *) 0);
						}
						else if ( php_filter_forms_keyword( h, tptr, ffptr,0 ) )
						{
							abal_php_consume_method(h);
							return((char *) 0);
						}
						else
						{
							fprintf(h,"->On%s",tptr);
							return((char *) 0);
						}

					}
				}
			else	{
				/* we got a file.widget type expression */
				/* ------------------------------------ */
				if ((i = is_data_member( tptr, 1 )) != -1)
					abal_php_data_expression(h, iptr,i, 1,tptr );
				else if ( upper_compare( tptr, "ONNEW" ) )
					fprintf(h,"->OnNew");
				else if ( upper_compare( tptr, "ONEXPORT" ) )
					fprintf(h,"->OnExport");
				else if ( upper_compare( tptr, "ONIMPORT" ) )
					fprintf(h,"->OnImport");
				else if ( upper_compare( tptr, "ONDISTINCT" ) )
					fprintf(h,"->OnDistinct");
				else if (!( strcasecmp( tptr, "COLLECTION" ) ))
					fprintf(h,"->collection");
				else if (!( strcasecmp( tptr, "PAGES" ) ))
					fprintf(h,"->pages");
				else if (!( strcasecmp( tptr, "PAGE" ) ))
					fprintf(h,"->page");
				else if (!( strcasecmp( tptr, "OFFSET" ) ))
					fprintf(h,"->offset");
				else if (!( strcasecmp( tptr, "LIMIT" ) ))
					fprintf(h,"->limit");
				else if ( php_file_member(h, iptr, tptr ) )
					return((char*)0);
				else	fprintf(h,"->_%s",tptr);
				}
			}
		else	{
			/* we got a widget.member type expression */
			/* -------------------------------------- */
			if (!( strcasecmp( tptr, "TARGET" ) ))
				fprintf(h,"$this->%s->target",php_widget_name(iptr));
			else if (!( strcasecmp( tptr, "SCALE" ) ))
				fprintf(h,"$this->%s->scale",php_widget_name(iptr));
			else if (!( strcasecmp( tptr, "LABEL" ) ))
				fprintf(h,"$this->%s->label",php_widget_name(iptr));
			else if (!( strcasecmp( tptr, "ITALIC" ) ))
				fprintf(h,"$this->%s->italic",php_widget_name(iptr));
			else if (!( strcasecmp( tptr, "BOLD" ) ))
				fprintf(h,"$this->%s->isbold",php_widget_name(iptr));
			else if (!( strcasecmp( tptr, "SHADOW" ) ))
				fprintf(h,"$this->%s->shadow",php_widget_name(iptr));
			else if (!( strcasecmp( tptr, "SHADOWCOLOR" ) ))
				fprintf(h,"$this->%s->shadowcolor",php_widget_name(iptr));
			else if (!( strcasecmp( tptr, "SHADOWCOLOUR" ) ))
				fprintf(h,"$this->%s->shadowcolor",php_widget_name(iptr));
			else if (!( strcasecmp( tptr, "RADIUS" ) ))
				fprintf(h,"$this->%s->radius",php_widget_name(iptr));
			else if (!( strcasecmp( tptr, "DIRECTION" ) ))
				fprintf(h,"$this->%s->direction",php_widget_name(iptr));
			else if (!( strcasecmp( tptr, "INPUTZONE" ) ))
				fprintf(h,"$this->%s->inputzone",php_widget_name(iptr));
			else if (!( strcasecmp( tptr, "CONTENT" ) ))
				fprintf(h,"$this->%s->setContent",php_widget_name(iptr));
			else if (!( strcasecmp( tptr, "NATURE" ) ))
				fprintf(h,"$this->%s->setNature",php_widget_name(iptr));
			else if (!( strcasecmp( tptr, "ALIGN" ) ))
				fprintf(h,"$this->%s->OnAlign",php_widget_name(iptr));
			else if (!( strcasecmp( tptr, "UPLOAD" ) ))
			{
				fprintf(h,"$this->%s",php_widget_name(iptr));
				fprintf(h,"Upload($psn)");
				(void) remove_brackets();
			}
			else 
			switch ((i = is_visual_member( tptr,1 ))) {
				case	VISUAL_MEMBER_X	:
					fprintf(h,"$this->%s",php_widget_name(iptr));
					fprintf(h,"->x"); break;
				case	VISUAL_MEMBER_Y	:
					fprintf(h,"$this->%s",php_widget_name(iptr));
					fprintf(h,"->y"); break;
				case	VISUAL_MEMBER_W	:
					fprintf(h,"$this->%s",php_widget_name(iptr));
					fprintf(h,"->w"); break;

				case	VISUAL_MEMBER_H	:
					fprintf(h,"$this->%s",php_widget_name(iptr));
					fprintf(h,"->h"); break;

				case	VISUAL_MEMBER_BUFFER	:
					if ( iptr->Contents.style == _FORM_FRAME )
					{
						if ((c = parser_getch()) == '=' ) 
						{
							php_get_token(0);
							fprintf(h,"$this->%s->OnReset()",php_widget_name(iptr));
							break;
						}
					}
					fprintf(h,"$this->%s",php_widget_name(iptr));
					fprintf(h,"->buffer"); 
					break;

				case	VISUAL_MEMBER_VALUE	:
					fprintf(h,"$this->%s",php_widget_name(iptr));
					if ( iptr->Contents.style == _EDIT_FRAME )
						fprintf(h,"->buffer"); 
					else	fprintf(h,"->value");
					break;

				case	VISUAL_MEMBER_MAX	:
					fprintf(h,"$this->%s",php_widget_name(iptr));
					fprintf(h,"->max"); break;

				case	VISUAL_MEMBER_OFFSET	:
					fprintf(h,"$this->%s",php_widget_name(iptr));
					fprintf(h,"->offset"); break;

				case	VISUAL_MEMBER_LIMIT	:
					fprintf(h,"$this->%s",php_widget_name(iptr));
					fprintf(h,"->limit"); break;

				case	VISUAL_MEMBER_COLUMNS	:
					fprintf(h,"$this->%s",php_widget_name(iptr));
					fprintf(h,"->columns"); break;

				case	VISUAL_MEMBER_LINES	:
					fprintf(h,"$this->%s",php_widget_name(iptr));
					fprintf(h,"->lines"); break;

				case	VISUAL_MEMBER_FONTSIZE	:
					if ( iptr->Contents.style == _FORM_FRAME )
						return( abal_php_form_fontsize(h,iptr) );
					else
					{
						fprintf(h,"$this->%s->fontsize",php_widget_name(iptr));
						break;
					}

				case	VISUAL_MEMBER_COLUMN	:
					return( abal_php_form_column(h,iptr) );

				case	VISUAL_MEMBER_BUBBLE	:
					return( abal_php_form_help(h,iptr) );

				case	VISUAL_MEMBER_FLAG	:
					return( abal_php_form_flag(h,iptr) );

				case	VISUAL_MEMBER_LINE	:
					return( abal_php_form_line( h,iptr ) );

				case	VISUAL_MEMBER_FONTWIDTH	:
					fprintf(h,"$this->%s",php_widget_name(iptr));
					fprintf(h,"->fw"); break;
					
				case	VISUAL_MEMBER_FONTHEIGHT :
					fprintf(h,"$this->%s",php_widget_name(iptr));
					fprintf(h,"->fh"); break;

				case	VISUAL_MEMBER_RESET	:
					(void) remove_brackets();
					fprintf(h,"$this->%s->OnReset()",php_widget_name(iptr ));
					break;
				case	VISUAL_MEMBER_FONT	:
				case	VISUAL_MEMBER_FG	:
				case	VISUAL_MEMBER_BG	:
					break;
				case	VISUAL_MEMBER_SHOW	:
					(void) remove_brackets();
					if ( php_can_show() ) 
					{
						fprintf(h,"$this->%sShow($psn.%c_%s%c)",
							php_widget_name(iptr),
							__QUOTE,php_widget_name(iptr),__QUOTE);
					}
					break;

				case	VISUAL_MEMBER_ONSHOW	:
					(void) remove_brackets();
					if ( php_can_show() ) 
					{
						fprintf(h,"$this->%s->OnShow($psn.%c_%s%c)",
							php_widget_name(iptr),
							__QUOTE,php_widget_name(iptr),__QUOTE);
					}
					break;
				case	VISUAL_MEMBER_EVENT 	:
					fprintf(h,"$this->%s",php_widget_name(iptr));
					fprintf(h,"Event($psn)");
					(void) remove_brackets();
					break;

				case	VISUAL_MEMBER_CREATE	:
					fprintf(h,"$this->%s",php_widget_name(iptr));
					fprintf(h,"Create($psn)");
					(void) remove_brackets();
					break;
				case	VISUAL_MEMBER_REMOVE	:
					fprintf(h,"$this->%s",php_widget_name(iptr));
					fprintf(h,"Remove($psn)");
					(void) remove_brackets();
					break;
				case	VISUAL_MEMBER_HIDE  	:
					fprintf(h,"$this->%s",php_widget_name(iptr));
					fprintf(h,"Hide($psn)");
					(void) remove_brackets();
					break;
				case	VISUAL_MEMBER_ONHIDE	:
					(void) remove_brackets();
					if ( php_can_show() ) {
						fprintf(h,"$this->%s->OnHide($psn.%c_%s%c)",
							php_widget_name(iptr),
							__QUOTE,php_widget_name(iptr),__QUOTE);
						}
					break;

				case	VISUAL_MEMBER_GETFOCUS	:
				case	VISUAL_MEMBER_LOSEFOCUS	:
					(void) remove_brackets();
					break;

				default	:
					fprintf(h,"$this->%s",php_widget_name(iptr));
					fprintf(h,"->%s",tptr);
				}
			}
		return((char *) 0);
		}

}

public	int	abal_php_method_line( FILE * h, char * eptr, int l, char * hptr, int * feeder, int term )
{
	int	punctuate=1;
	int	c;
	int	holder=0;
	int	older=0;
	char *	tptr;

	if ( upper_compare( eptr,"#ENDPHP" ) ) {
		set_line_parser(1);
		return(0);
		}
	else if (!( use_line_parser() )) {
		fprintf(h,"%s\n",eptr);
		return(0);
		}

	if ( feeder ) *feeder = 0;
	if (!( initialise_line_parser( eptr, hptr ) )) 
		return(0);
	else	initialise_line_folding();
	holder = php_set_default_termination( term );
	older = php_set_termination( term );
	while (1) {
		if ((c = abal_get_punctuation())) {
			punctuate++;
			if( c == 0x0027 )
				break;
			if ( c == '&' )
 				continue;
			if ( c == '!' )
				c = '.';
			if ( c == ':' ) {
				if ((c = abal_get_punctuation()) != ':') {
					if ( c ) parser_ungetch();
					fprintf(h,"%c",':');
					continue;
					}
				else	{
					php_line_termination(h);
					continue;
					}
				}
			else if (!( PhpCtrl.conditional )) {
				fprintf(h,"%c",c);
				continue;
				}
			else if (( c == '<' ) || ( c == '>' )) {
				fprintf(h,"%c",c);
				if ((c = abal_get_punctuation()) != 0) {
					if (( c == '=') || ( c == '>' ))
						fprintf(h,"%c",c);
					else	parser_ungetch();
					}
				continue;
				}
			else if ( c == '=' ) {
				fprintf(h,"%c=",c);
				continue;
				}
			else	{
				fprintf(h,"%c",c);
				continue;
				}
			}
		else if (!( tptr = php_get_token(0) ))
			break;
		else 	{
			if (!( punctuate ))
				fprintf(h," ");
			punctuate = 0;
			if (!(tptr =  abal_php_convert_token(h,tptr) ))
				continue;
			else 	fprintf(h,"%s",tptr);
			}
		}
	if ( feeder ) *feeder = 1;
	if( c != 0x0027 ) {
		if ( term != ' ' )
			php_line_termination(h);
		}
	holder = php_set_default_termination( holder );
	php_set_termination( older );
	return(LineParser.status);
}

public	int	abal_php_array_index( FILE * h )
{
	int	punctuate=1;
	int	c;
	int	braces=1;
	char *	tptr;

	if (( c = abal_get_punctuation()) != '(' )
		return(0);
	else	fprintf(h,"[");
	while (1) {
		if ((c = abal_get_punctuation())) {
			punctuate++;
			if ( c == ')' ) {
				if ( braces )
					braces--;
				if (!( braces ))
					break;
				else	{
					fprintf(h,"%c",c);
					continue;
					}
				}
			else if ( c == '(' ) {
				braces++;
				fprintf(h,"%c",c);
				continue;
				}
			if ( c == '!' )
				c = '.';
			if ( c == ':' ) {
				if ((c = abal_get_punctuation()) != ':') {
					if ( c ) parser_ungetch();
					fprintf(h,"%c",':');
					continue;
					}
				else	{
					if ( c ) parser_ungetch();
					parser_ungetch();
					break;
					}
				}
			fprintf(h,"%c",c);
			continue;
			}
		else if (!( tptr = php_get_token(0) ))
			break;
		else 	{
			if (!( punctuate ))
				fprintf(h," ");
			punctuate = 0;
			if (!(tptr =  abal_php_convert_token(h,tptr) ))
				continue;
			else 	fprintf(h,"%s",tptr);
			}
		}
	fprintf(h,"]");
	return(0);
}

public	int	abal_php_invocation_parameters( FILE * h )
{
	int	punctuate=1;
	int	c;
	int	braces=1;
	char *	tptr;

	if (( c = abal_get_punctuation()) != '(' )
		return(0);
	else	fprintf(h,"(");
	while (1) {
		if ((c = abal_get_punctuation())) {
			punctuate++;
			if ( c == ')' ) {
				if ( braces )
					braces--;
				if (!( braces ))
					break;
				else	{
					fprintf(h,"%c",c);
					continue;
					}
				}
			else if ( c == '(' ) {
				braces++;
				fprintf(h,"%c",c);
				continue;
				}
			if ( c == '!' )
				c = '.';
			else if ( c == ';' )
				c = ',';
			else if ( c == ':' ) {
				if ((c = abal_get_punctuation()) != ':') {
					if ( c ) parser_ungetch();
					fprintf(h,"%c",':');
					continue;
					}
				else	{
					if ( c )parser_ungetch();
					parser_ungetch();
					break;
					}
				}
			fprintf(h,"%c",c);
			continue;
			}
		else if (!( tptr = php_get_token(0) ))
			break;
		else 	{
			if (!( punctuate ))
				fprintf(h," ");
			punctuate = 0;
			if (!(tptr =  abal_php_convert_token(h,tptr) ))
				continue;
			else 	fprintf(h,"%s",tptr);
			}
		}
	fprintf(h,")");
	return(0);
}

public	int	abal_php_macro_conversion( FILE * h, char * sptr, char * hptr )
{
	int	feeder=0;
	int	status;
	if (!( push_line_parser() )) {
		return((status =27));
		}
	else	{
		status = abal_php_method_line( h, sptr, strlen(sptr), hptr, &feeder, ' ' );
		(void) pop_line_parser();
		return( status );
		}
}

private	void	abal_php_start_method( FILE * h )
{
	PhpCtrl.first = PhpCtrl.last = (struct php_variable *) 0;
	PhpCtrl.terminator = ';';
	PhpCtrl.fornext = 0;
	PhpCtrl.operand[0] = 0;
	set_line_parser(1);
	return;
}

private	void	abal_php_end_method( FILE * h )
{
	struct php_variable * vptr;
	while ((vptr = PhpCtrl.first) != (struct php_variable *) 0) 
	{
		PhpCtrl.first = vptr->next;
		liberate( vptr->name );
		liberate( vptr );
	}
	set_line_parser(1);
	return;
}

public	int	abal_php_method_body( FILE * h,char * eptr, char * hptr,int margin)
{
	int	n;
	int	i;
	int	c;
	char *	lptr;
	int	status=0;
	int	feeder=0;

	if (!( eptr ))	{ return(status); }

	abal_php_start_method(h);

	while ( *eptr != 0 ) {
		feeder=0;
		/* avoid empty lines */
		if (( *eptr == '\n' ) 
		||  ( *eptr == '\r' )) {
			eptr++;
			continue;
			}
		else	{
			/* scan till end of line or zero */
			/* ----------------------------- */
			for (	i=0,lptr = eptr;
				*eptr != 0;
				eptr++ ) {
				if (( *eptr == '\n' ) 
				||  ( *eptr == '\r' ))
					break;
				else	i++;
				}
			c = *eptr; *eptr = 0;
			for (n=0; *(lptr+i) != 0; n++ ) {
				if ( *(lptr+i) == ';' )
					break;
				else if ( *(lptr+i) == ' ' )
					continue;
				else if ( *(lptr+i) == '\t' )
					continue;
				else	break;
				}

			if ( *(lptr+n) != ';' ) {
				indent(h,margin);
				status = abal_php_method_line(h,lptr,i,hptr,&feeder,';');
				}
			else	{
				feeder = status=0;
				}
			*eptr = c;
			if ( feeder ) linefeed(h);
			if ( status ) break;
			}
		}
	abal_php_end_method(h);
	return(status);
}

#endif	/* _phpline_c */
	/* ---------- */

