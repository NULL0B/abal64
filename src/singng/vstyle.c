#ifndef	_vstyle_c
#define _vstyle_c

/*
********************************************************************
* Gestion des conversions unité-physique <--> pixels
********************************************************************
*/
#ifndef	private
#define	private	static
#endif

private struct style_conv {
	int	Mode;
	int	xDpi;
	int	yDpi;
	int	Scale;
	int   cxDes;
	int   cxOri;
	int   cyDes;
	int   cyOri;
	} StyleConv = { 0 };

public	void style_set_hq( int xdpiDes, int ydpiDes, int scaleDes, int cxDes, int cxOri, int cyDes, int cyOri )
{
	StyleConv.Mode  = 1;
	StyleConv.xDpi  = xdpiDes;
	StyleConv.yDpi  = ydpiDes;
	StyleConv.Scale = scaleDes;
	StyleConv.cxDes = cxDes;
	StyleConv.cxOri = cxOri;
	StyleConv.cyDes = cyDes;
	StyleConv.cyOri = cyOri;
}

void style_set_screen( int xdpi, int ydpi )
{
	StyleConv.Mode  = 0;
	StyleConv.xDpi  = xdpi;
	StyleConv.yDpi  = ydpi;
}

#undef	_TRACE_STYLE

private	char 			*	styleclasslist=(char *) 0;
private	struct	element_style	*	ClassList=(struct element_style *) 0;
#ifdef	ABAL32A
private	struct	element_file	*	FileList=(struct element_style *) 0;
#endif
private	struct	element_style	*	StyleHeap[_MAX_STYLE];	/* a->z, A->Z */
private	int				DefaultStyle[_MAX_STYLE];
private	struct	element_style	*	ActiveStyle=(struct element_style*) 0;
private	struct	style_definition *	DefineList=(struct style_definition *) 0;
private	int	style_echo=0;
int	use_overload_style=1;

#define	_STYLE_MAX_ERROR	64

private struct	style_control	{
	FILE	*	handle;
	char	*	name;
	char	*	input;
	int		errorcounter;
	int		linecounter;
	int		bytecounter;
	int		errorline[_STYLE_MAX_ERROR+1];
	int		errorbyte[_STYLE_MAX_ERROR+1];
	int		errorcode[_STYLE_MAX_ERROR+1];
	int		ungotch;
	struct	style_control * next;
	char		token[512];
	} * StyleContext = (struct style_control *) 0;


#ifdef	ABAL32A
private	char * StyleDomain=(char *) 0;
#endif
	/* { (FILE *) 0,(char *) 0,(char *) 0, 0 }; */

public	void	handle_style_errors( int nb, char * tracefilename);

#ifdef	ABAL32A
public	char *	get_system_stylepath();
public	char *	resolve_style_domain( char * tptr );
#endif
public	struct element_style * resolve_style_class( char * tptr );
private	int	translate_style( struct element_style * sptr, char * token );
private	int	translate_align      (int * iptr);

private	void	reset_dimension( struct element_dimension * eptr )
{
#ifdef	ABAL32A
	eptr->state	= 0;
	eptr->token[0]  = 0;
#endif
	eptr->type 	= _AUTO_DIMENSION;
	eptr->value	= 0;
	return;
}

private	void	copy_value( struct element_dimension * rptr, struct element_dimension * sptr )
{
#ifdef	ABAL32A
	if ( sptr->state ) { rptr->state = 2; }
	else		   { rptr->state = 0; }
	strcpy(rptr->token,sptr->token);
#endif
	rptr->type 	= sptr->type;
	rptr->value	= sptr->value;
	return;
}

private	void	copy_colour( struct element_colour * rptr, struct element_colour * sptr )
{
#ifdef	ABAL32A
	rptr->type	= sptr->type;
#endif
	rptr->red	= sptr->red;
	rptr->green	= sptr->green;
	rptr->blue	= sptr->blue;
	rptr->entry	= sptr->entry;
	return;
}

private	void	copy_position( struct element_position * rptr, struct element_position * sptr )
{
	rptr->type 	= sptr->type;
	rptr->option 	= sptr->option;
	copy_value( &rptr->top, &sptr->top );
	copy_value( &rptr->right, &sptr->right );
	copy_value( &rptr->bottom, &sptr->bottom );
	copy_value( &rptr->left, &sptr->left );
	return;
}

private	char *	style_string( char * sptr )
{
	char *	rptr;
	if (!( sptr ))
		return( sptr );
	else if (!( rptr = allocate( strlen(sptr) + 1 ) ))
		return(rptr);
	else	{
		strcpy(rptr,sptr);
		return(rptr);
		}
}

private	void	copy_frame( struct element_frame * rptr, struct element_frame * sptr )
{
	rptr->top	= sptr->top;
	if ( sptr->topimage )
		rptr->topimage = style_string( sptr->topimage );
	rptr->left	= sptr->left;
	if ( sptr->leftimage )
		rptr->leftimage = style_string( sptr->leftimage );
	rptr->right	= sptr->right;
	if ( sptr->rightimage )
		rptr->rightimage = style_string( sptr->rightimage );
	rptr->bottom	= sptr->bottom;
	if ( sptr->bottomimage )
		rptr->bottomimage = style_string( sptr->bottomimage );

	rptr->topright	= sptr->topright;
	if ( sptr->toprightimage )
		rptr->toprightimage = style_string( sptr->toprightimage );

	rptr->right	= sptr->right;
	if ( sptr->rightimage )
		rptr->rightimage = style_string( sptr->rightimage );

	rptr->bottomright	= sptr->bottomright;
	if ( sptr->bottomrightimage )
		rptr->bottomrightimage = style_string( sptr->bottomrightimage );

	rptr->bottom	= sptr->bottom;
	if ( sptr->bottomimage )
		rptr->bottomimage = style_string( sptr->bottomimage );

	rptr->bottomleft	= sptr->bottomleft;
	if ( sptr->bottomleftimage )
		rptr->bottomleftimage = style_string( sptr->bottomleftimage );


	rptr->left	= sptr->left;
	if ( sptr->leftimage )
		rptr->leftimage = style_string( sptr->leftimage );

	rptr->topleft	= sptr->topleft;
	if ( sptr->topleftimage )
		rptr->topleftimage = style_string( sptr->topleftimage );

	return;
}

private	void	release_frame( struct element_frame * sptr )
{
	if ( sptr->topimage )
		sptr->topimage = liberate( sptr->topimage );
	if ( sptr->leftimage )
		sptr->leftimage = liberate( sptr->leftimage );
	if ( sptr->rightimage )
		sptr->rightimage = liberate( sptr->rightimage );
	if ( sptr->bottomimage )
		sptr->bottomimage = liberate( sptr->bottomimage );
	if ( sptr->toprightimage )
		sptr->toprightimage = liberate( sptr->toprightimage );
	if ( sptr->rightimage )
		sptr->rightimage = liberate( sptr->rightimage );
	if ( sptr->bottomrightimage )
		sptr->bottomrightimage = liberate( sptr->bottomrightimage );
	if ( sptr->bottomimage )
		sptr->bottomimage = liberate( sptr->bottomimage );
	if ( sptr->bottomleftimage )
		sptr->bottomleftimage = liberate( sptr->bottomleftimage );
	if ( sptr->leftimage )
		sptr->leftimage = liberate( sptr->leftimage );
	if ( sptr->topleftimage )
		sptr->topleftimage = liberate( sptr->topleftimage );
	return;
}

private	void	copy_style( struct element_style * rptr,struct element_style * sptr )
{
	copy_value( &rptr->letterspacing ,	&sptr->letterspacing  );
	copy_value( &rptr->wordspacing   ,	&sptr->wordspacing    );
	copy_value( &rptr->linespacing   ,	&sptr->linespacing    );
	copy_value( &rptr->marginsize.top,	&sptr->marginsize.top );
	copy_value( &rptr->marginsize.right,	&sptr->marginsize.right );
	copy_value( &rptr->marginsize.bottom,	&sptr->marginsize.bottom );
	copy_value( &rptr->marginsize.left,	&sptr->marginsize.left);
	copy_value( &rptr->bordersize.top,	&sptr->bordersize.top );
	copy_value( &rptr->bordersize.right,	&sptr->bordersize.right );
	copy_value( &rptr->bordersize.bottom,	&sptr->bordersize.bottom );
	copy_value( &rptr->bordersize.left,	&sptr->bordersize.left);
	copy_value( &rptr->paddingsize.top,	&sptr->paddingsize.top );
	copy_value( &rptr->paddingsize.right,	&sptr->paddingsize.right );
	copy_value( &rptr->paddingsize.bottom,	&sptr->paddingsize.bottom );
	copy_value( &rptr->paddingsize.left,	&sptr->paddingsize.left);
	copy_frame( &rptr->bordertype, 		&sptr->bordertype);
	copy_value( &rptr->textindent, 		&sptr->textindent);
	copy_value( &rptr->cellwidth,  		&sptr->cellwidth );
	copy_value( &rptr->cellheight, 		&sptr->cellheight);
	copy_value( &rptr->shadowwidth,  	&sptr->shadowwidth );
	copy_value( &rptr->shadowheight, 	&sptr->shadowheight);
	copy_colour( &rptr->textcolour, 	&sptr->textcolour );
	copy_colour( &rptr->margincolour, 	&sptr->margincolour );
	copy_colour( &rptr->shadowcolour, 	&sptr->shadowcolour );
	copy_colour( &rptr->backgroundcolour, 	&sptr->backgroundcolour );
	copy_colour( &rptr->bordercolour, 	&sptr->bordercolour );
	copy_position(&rptr->cellposition,	&sptr->cellposition);
	rptr->borderalign=			sptr->borderalign;
	rptr->rounding=				sptr->rounding;
	rptr->backgroundalign=			sptr->backgroundalign;
	rptr->marginalign=			sptr->marginalign;
	rptr->backgroundrepeat=			sptr->backgroundrepeat;
	rptr->marginrepeat=			sptr->marginrepeat;
	rptr->backgroundattach=			sptr->backgroundattach;
	rptr->textalign=			sptr->textalign;
	rptr->textfont=				sptr->textfont;
	rptr->textatribut=			sptr->textatribut;
	rptr->nature=				sptr->nature;
	if ( sptr->backgroundimage )
		rptr->backgroundimage = style_string(sptr->backgroundimage );
	if ( sptr->marginimage )
		rptr->marginimage = style_string(sptr->marginimage );
	if ( sptr->fontname )
		rptr->fontname = style_string(sptr->fontname );
	if ( sptr->alias )
		rptr->alias = style_string(sptr->alias );
	return;
}

private	void	reset_sizes( struct element_sizes * eptr )
{
	reset_dimension( &eptr->top   );
	reset_dimension( &eptr->right );
	reset_dimension( &eptr->bottom);
	reset_dimension( &eptr->left );
	return;
}

private	void	reset_types( struct element_frame * eptr )
{
	eptr->topleft		=
	eptr->bottomleft	=
	eptr->topright		=
	eptr->bottomright	=

	eptr->left 		= 
	eptr->bottom 		= 
	eptr->right 		= 
	eptr->top 		= _BORDER_NONE;

	eptr->topleftimage	=
	eptr->bottomleftimage	=
	eptr->toprightimage	=
	eptr->bottomrightimage	=
	eptr->leftimage		= 
	eptr->bottomimage 	= 
	eptr->rightimage 	= 
	eptr->topimage 		= (char *) 0;
	return;
}

private	void	reset_colour( struct element_colour * eptr )
{
#ifdef	ABAL32A
	eptr->type		= -1;
#endif
	eptr->red  		= 
	eptr->green  		= 
	eptr->blue  		= 
	eptr->entry 		= 0;
	return;
}

private	void	reset_style(struct element_style * sptr, int iscopy )
{
	reset_sizes(&sptr->marginsize);
	reset_sizes(&sptr->bordersize);
	reset_sizes(&sptr->paddingsize);
	reset_types(&sptr->bordertype);
	reset_dimension( &sptr->shadowwidth );
	reset_dimension( &sptr->shadowwidth );
	reset_dimension( &sptr->cellwidth );
	reset_dimension( &sptr->cellheight);
	reset_dimension( &sptr->textindent);
	reset_dimension( &sptr->letterspacing);
	reset_dimension( &sptr->linespacing);
	reset_dimension( &sptr->wordspacing);
	reset_colour( &sptr->textcolour);
	reset_colour( &sptr->margincolour);
	reset_colour( &sptr->shadowcolour);
	sptr->marginalign=_ALIGN_JUSTIFY;
	sptr->marginrepeat=_REPEAT_BOTH;
	reset_colour( &sptr->backgroundcolour);
	reset_colour( &sptr->bordercolour);
	sptr->cellposition.type   = _keyword_auto;
	sptr->cellposition.option = 0;
	reset_dimension( &sptr->cellposition.top );
	reset_dimension( &sptr->cellposition.right );
	reset_dimension( &sptr->cellposition.bottom );
	reset_dimension( &sptr->cellposition.left );
	sptr->rounding=-1;
	sptr->borderalign=_ALIGN_JUSTIFY;
	sptr->backgroundalign=_ALIGN_JUSTIFY;
	sptr->backgroundrepeat=_REPEAT_BOTH;
	sptr->backgroundattach=_ATTACH_SCROLL;
	sptr->textalign=_ALIGN_LEFT;
	sptr->textfont=1;
	sptr->textatribut=0;
	sptr->nature = _keyword_text;
	sptr->item=0;
	sptr->backgroundimage=
	sptr->marginimage=
	sptr->basename =
	sptr->fontname = (char *) 0;
	if (!( iscopy )) {
		sptr->filename = (char *) 0;
		sptr->owner    = (struct element_file * )0;
		}
	return;
}

private	void	release_style(struct element_style * sptr, int iscopy )
{
	if ( sptr->backgroundimage )
		liberate ( sptr->backgroundimage );		
	if ( sptr->marginimage )
		liberate ( sptr->marginimage );		
	release_frame( &sptr->bordertype );

#ifdef	ABAL32A
	if (!( iscopy )) {
		if ( sptr->filename ) { liberate( sptr->filename ); }
		}
	if ( sptr->basename ) { liberate( sptr->basename ); }
	if ( sptr->fontname ) { liberate( sptr->fontname ); }
#endif
	reset_style( sptr,iscopy );
}

private	struct	element_style *	allocate_for_style()
{
	struct	element_style *	sptr;

	if (!(sptr = allocate( sizeof( struct element_style ) ) ))
		return( sptr );
	else	{
		sptr->name 	= (char *) 0;
#ifdef	ABAL32A
		sptr->alias	= (char *) 0;
		sptr->basename 	= (char *) 0;
		sptr->filename 	= (char *) 0;
		sptr->fileline	= 0;
		sptr->applied	= 0;
		sptr->fontname 	= (char *) 0;
		sptr->owner	= (struct element_file * )0;
		sptr->derivations= 0;
#endif
		sptr->hash = 0;
		sptr->next = (struct element_style *) 0;
		sptr->previous  = (struct element_style *) 0;
		reset_style(sptr,0);
		return( sptr );
		}
}

private	void	liberate_style( struct element_style * sptr )
{
	if ( sptr ) {
		if ( sptr->name ) {
			liberate( sptr->name );
			sptr->name = (char *) 0;
			}
		release_style( sptr, 0 );
		liberate( sptr );
		}

	return;
}

public	struct	element_style *	overload_style( char * tptr )
{
	struct	element_style * sptr;
	if (!( tptr ))
		return( (struct element_style *) 0);
	else	if ( *tptr == '.' )
			tptr++;
		
	if ((sptr = resolve_style_class( tptr )) != (struct element_style *) 0) {
		if ( style_echo & 2 )
			printf("overloading style class : %s\r\n",tptr); 
		release_style( sptr, 0 );
		return( sptr );
		}
	else if (!( sptr = allocate_for_style()))
		return( sptr );
#ifdef	ABAL32A
	else if (!( sptr->name = resolve_style_domain( tptr ) )) {
#else
	else if (!(sptr->name = allocate_string( tptr ))) {
#endif
		liberate_style( sptr );
		return( (struct element_style *) 0 );
		}
	else	{
		if ( style_echo & 2 )
			printf("creating style class : %s\r\n",sptr->name); 
		sptr->hash = style_element_hash(sptr->name);
		sptr->previous = (struct element_style *) 0;
		if ((sptr->next = ClassList) != (struct element_style *) 0)
			ClassList->previous = sptr;
		ClassList  = sptr;
		return( sptr );
		}
}

void	drop_style( int item )
{
	struct	element_style *	sptr;
	if ( item >= _MAX_STYLE )
		return;
	else if (!( sptr = StyleHeap[item] ))
		return;
	else	{
		liberate_style( sptr );
		StyleHeap[item] = (struct element_style *) 0;
		return;
		}
}

int	visual_style(int atbid)
{
	struct	element_style *	sptr;
	if ( atbid >= _MAX_STYLE )
		return(_exceeding_style_limit);
	if (!(sptr = allocate_for_style()))
		return(_allocation_failure);
	else	{
		drop_style(atbid);
		StyleHeap[atbid] = sptr;
		return( 0 );
		}
}

private	void	print_style_keyvalues()
{
	int	i;

	for ( i=0; i < _max_style_keywords; i++ )
		printf("#define _keyword_%s\t\t0x00%x \r\n",_style_keyword[i],i );
	printf("#define _max_style_keywords\t\t0x00%x \r\n",i );
	return;
}

private	int	is_style_keyword(char * tptr)
{
	int	i;
	for ( i=0; i < _max_style_keywords; i++ )
		if (!( strcmp(tptr,_style_keyword[i] ) ))
			return(i);
	return(-1);
}

private	int	style_ungetch(int c)
{
	if (!( StyleContext ))
		return(0);
	else	{
		StyleContext->ungotch <<= 8;
		return((StyleContext->ungotch|=(c&0x00FF)));
		}
}

private	int	style_getch()
{
	int	c;
	if (!( StyleContext ))
		return(0);
	else if ((c= (StyleContext->ungotch & 0x00FF)) != 0)
		StyleContext->ungotch >>= 8;
	else if ( StyleContext->input ) {
		if ((c = *StyleContext->input) != 0)
			StyleContext->input++;
		if ( style_echo & 1 ) {
			if ( c == '\n' )
				printf("\r\n");
			else if ( c )
				printf("%c",(c & 0x00FF));
			}
		}
	else if ( StyleContext->handle ) {
		if (((c = fgetc( StyleContext->handle )) == -1 ) || ( c == 0x001A )) {
			if ( style_echo & 1 ) {
				printf("\r\n end of style file : %s \r\n",StyleContext->name);
				}
			fclose( StyleContext->handle );
			StyleContext->handle = (FILE *) 0;
			c = 0;
			}
		if ( style_echo & 1 ) {
			if ( c == '\n' )
				printf("\r\n");
			else if ( c )
				printf("%c",(c & 0x00FF));
			}
		switch ( c ) {
			case	'\n'	:
				StyleContext->linecounter++;
				StyleContext->bytecounter=0;
			case	'\r'	:
				break;
			case	'\t'	:
				do	{ StyleContext->bytecounter++; }
				while ((StyleContext->bytecounter % 8) != 0);
				break;
			default		:
				StyleContext->bytecounter++;
			}
		}
	else	c = 0;		
			

	return( c );
}

private	char *	current_style_file()
{
	if (!( StyleContext ))
		return("unknown");
	else if (!( StyleContext->name ))
		return("nofile");
	else	return( StyleContext->name );
}

private	void	catch_style_error(int errorcode)
{
	if ( StyleContext ) { 
		if ( StyleContext->errorcounter < _STYLE_MAX_ERROR ) {
			StyleContext->errorline[StyleContext->errorcounter] = StyleContext->linecounter;
			StyleContext->errorbyte[StyleContext->errorcounter] = StyleContext->bytecounter;
			StyleContext->errorcode[StyleContext->errorcounter] = errorcode;
			StyleContext->errorcounter++;
			}
		}
	return;
}


private	char *	style_error_string( int errorcode )
{
	switch ( errorcode ) {
		case 	_style_expected_dash		: // 30
			return( "expected '-'" );
		case 	_style_expected_colon		: // 31
			return( "expected ':'" );
		case 	_style_expected_semicolon	: // 32
			return( "expected ';'" );
		case 	_style_expected_token		: // 33
			return( "expected token" );
		case 	_style_incorrect_keyword	: // 34
			return( "incorrect keyword" );
		case 	_style_expected_url		: // 35
			return( "expected url" );
		case 	_style_expected_left_brace 	: // 36
			return( "expected '('" );
		case 	_style_expected_right_brace	: // 37
			return( "expected ')'" );
		case 	_style_undefined_class		: // 38
			return( "undefined class')'" );
		case 	_style_expected_comma		: // 39
			return( "expected ','" );
		case 	_file_not_found			: // 40
			return( "file not found" );
		case 	_style_expected_value		: // 41
			return( "expected value" );
		case 	_exceeding_style_limit		: // 103
			return( "exceeding limit" );
		case 	_allocation_failure		: // 27
			return( "allocation failure" );
		case 	_end_of_style			: // 48
			return( "end of style" );
		default					:
			return( "style parse failure" );
		}
}

private	void	trace_style_errors(struct style_control * sptr)
{
	char *	eptr;
	FILE *	h;
	int	i;
	char	efname[256];
	if (!( sptr ))
		return;
	else if (!( sptr->errorcounter ))
		return;
	
#ifdef	UNIX
	sprintf(efname,"/tmp/vstyle%u.err",getpid());
#else
	sprintf(efname,"%s","vstyle.err");
#endif
	if ((h = fopen(efname,"w")) != (FILE* ) 0) {
		for (i=0; i < sptr->errorcounter; i++ ) {
			eptr = style_error_string( sptr->errorcode[i] );
			fprintf(h,"%c%s%c %lu %u %s : %u \r\n",
				0x0022,sptr->name,0x0022,
				sptr->errorline[i]+1,sptr->errorbyte[i]+1,eptr,sptr->errorcode[i]);
			}
		fclose(h);
		handle_style_errors(sptr->errorcounter, efname );
		}
	return;
}

private	int	style_error( int v )
{
	int	c;
	char *	eptr;

	/* display the error if required */
	/* ----------------------------- */
	if ( style_echo & 1 ) {
		eptr = style_error_string( v );
		printf("\r\n** style error : %u( %s ) : %s **\r\n",v,current_style_file(),eptr);
		}

	/* allow the style error catcher to record this error */
	/* -------------------------------------------------- */
	catch_style_error(v);

	/* Scan to end of current style class to avoid error */
	/* ------------------------------------------------- */
	while ((c = style_getch()) != 0)
		if (( c == ';' ) ||  ( c == '}' ))
			break;

	return(0);
}


private	int	remove_comment()
{
	int	c;
	int	mode=0;
	while ((c = style_getch()) != 0) {
		if ( mode ) {
			if ( c == '/' )
				return( c );
			else	mode = 0;
			}
		else if ( c == '*' )
			mode = 1;

		}
	return(0);
}


private	int	style_white()
{
	int	c;
	int	cc;
	while (1) {
		switch ((c = style_getch())) {
			case	'\r'	:
			case	' '	:
			case	'\t'	:
			case	'\n'	:
				continue;
			case	'/'	:
				if ((cc = style_getch()) == '*' ) {
					if ( remove_comment() )
						continue;
					else	return(0);
					}
				else	style_ungetch(cc);
			default		:
				return((style_ungetch(c)));
			}
		}
}

private	struct	style_definition * resolve_style_define( char * nptr )
{
	struct	style_definition * dptr;
	int	h;

	if (!( DefineList ))
		return((struct style_definition *) 0);
	else if (!( nptr )) 	
		return((struct style_definition *) 0);
	else	h = style_element_hash( nptr );

	for (	dptr=DefineList;
		dptr != (struct style_definition *) 0;
		dptr = dptr->next ) {
		if ( h != dptr->hash )
			continue;
		else if (!( strcmp( dptr->name, nptr )))
			break;
		}
	return( dptr );
}

private	int	add_style_define( char * nptr ,char * vptr )
{
	struct	style_definition * dptr;
	if ((!( nptr )) || (!( vptr )))
		return(1);
	else if (!( dptr = resolve_style_define( nptr ) )) {
		if (!( dptr = allocate( sizeof( struct style_definition ) )))
			return(0);
		else 	{
			dptr->name = nptr;
			dptr->value = vptr;
			dptr->hash = style_element_hash( nptr );
			dptr->next = DefineList;
			DefineList = dptr;
			return(1);
			}
		}
	else	{
		if ( dptr->value )
			liberate( dptr->value );
		dptr->value = vptr;
		liberate( nptr );
		return(1);
		}
}

private	char *	style_token()
{
	struct	style_definition * dptr;
	int	i=0;
	int	c;
	if (!( style_white() ))
		return((char *) 0);
	while ( i < 511 ) {
		switch ((c = style_getch())) {
			case	'\r'	:
			case	' '	:
			case	'\t'	:
			case	'\n'	:
			case	0	:
				break;
			case	';'	:
			case	':'	:
			case	','	:
			case	'('	:
			case	')'	:
			case	'}'	:
			case	'{'	:
				style_ungetch(c);
				break;
			case	'-'	:
				if ( i > 0 ) {
					style_ungetch(c);
					break;
					}

			default		:
				StyleContext->token[i++] = c;
				continue;
			}
		break;
		}
	StyleContext->token[i] = 0;

	if (( dptr = resolve_style_define( StyleContext->token )) != (struct style_definition *) 0)
		strcpy( StyleContext->token, dptr->value );

	return((char *) StyleContext->token);
}

private	char *	style_url()
{
	struct	style_definition * dptr;
	int	keepwhite=0;
	int	i=0;
	int	c;
	if (!( style_white() ))
		return((char *) 0);
	while ( i < 511 ) {
		switch ((c = style_getch())) {
			case	'\r'	:
			case	'\t'	:
			case	'\n'	:
			case	0	:
				break;
			case	'('	:
			case	')'	:
				style_ungetch(c);
				break;
			case	' '	:
				if (!( keepwhite ))
					break;
			case	'{'	:
				keepwhite=1;
			default		:
				StyleContext->token[i++] = c;
				continue;
			}
		break;
		}
	StyleContext->token[i] = 0;
	if (( dptr = resolve_style_define( StyleContext->token )) != (struct style_definition *) 0)
		strcpy( StyleContext->token, dptr->value );
	return((char *) StyleContext->token);
}

private	int	style_punctuation()
{
	int	c;
	if (!( style_white() ))
		return(0);
	if (!( c = style_getch() ))
		return(0);
	if ((( c >= 'A' ) && ( c <= 'Z' ))
	||  (( c >= 'a' ) && ( c <= 'z' ))
	||  (( c >= '0' ) && ( c <= '9' ))
	||   ( c == '_' )) {
		style_ungetch(c);
		return( 0 );
		}
	else	return(c);
}

private	int	check_punctuation(int c)
{
	int	v;
	if (!( v = style_punctuation()))
		return(0);
	else if ( v == c )
		return(c);
	else	{
		style_ungetch(v);
		return( 0 );
		}
}				

private	int	is_style_open_brace() 	{	return( check_punctuation( '{' ) );	}
private	int	is_style_close_brace() 	{	return( check_punctuation( '}' ) );	}
private	int	is_style_left_bracket()	{	return( check_punctuation( '(' ) );	}
private	int	is_style_right_bracket(){	return( check_punctuation( ')' ) );	}
private	int	is_style_semi_colon() 	{	return( check_punctuation( ';' ) );	}
private	int	is_style_colon() 	{	return( check_punctuation( ':' ) );	}
private	int	is_style_dash() 	{	return( check_punctuation( '-' ) );	}
private	int	is_style_comma() 	{	return( check_punctuation( ',' ) );	}
private	int	is_style_exclaim() 	{	return( check_punctuation( '!' ) );	}


private	char	*	style_url_name()
{
	char	*	tptr;
	if (!( is_style_left_bracket() ))
		return( (char *) 0 );
	else if (!( tptr = style_url() ))
		return( tptr );
	else if (!( is_style_right_bracket() ))
		return((char *) 0);
	else	return( tptr );
}

private	int	initialise_style_string_parser(char * cptr )
{
	struct	style_control * sptr;
	if (!( sptr = allocate( sizeof(struct style_control) ) ))
		return(27);
	else	{
		sptr->input = cptr;
		sptr->handle= (FILE *) 0;
		sptr->name  = (char *) 0;
		sptr->errorcounter=0;
		sptr->bytecounter=0;
		sptr->linecounter=0;
		sptr->next  = StyleContext;
		StyleContext = sptr;
		style_ungetch(0);
		if ( is_style_open_brace() )
			return(0);
		else	return(37);
		}
}

#ifdef UNIX
#include "vresolve.c"
#endif

private	int	initialise_style_file_parser(char * filename )
{
	struct	style_control * sptr;
	if (!( sptr = allocate( sizeof(struct style_control) ) ))
		return(27);
	else	{
#ifdef UNIX
		sptr->name  = resolve_filepath( allocate_string( filename ),get_system_stylepath() );
#else
		sptr->name  = filename;
#endif
		sptr->errorcounter=0;
		sptr->bytecounter=0;
		sptr->linecounter=0;
		sptr->input = (char *) 0;
		sptr->handle= (FILE *) 0;
		if (!( sptr->handle = fopen( sptr->name, "r") )) {
			liberate( sptr );
			return(_file_not_found);
			}
		else	{
			if ( style_echo & 1 ) {
				printf("\r\n start of style file : %s \r\n",sptr->name);
				}
			sptr->next = StyleContext;
			StyleContext = sptr;
			style_ungetch(0);
			return(0);
			}
		}
}

char *	get_style_class_element(int number)
{
	int			item;
	char 			* rptr=(char *) 0;
	char 			* wptr=(char *) 0;
	struct	element_style	* sptr;

	for ( 	item=0,sptr=ClassList;
		sptr !=(struct element_style *) 0;
		sptr = sptr->next ) {
		if ( item == number )
			return( sptr->name );
		else	item++;
		}
	return((char *) 0);
}

char *	get_style_class_list(int separator)
{
	char 			* rptr=(char *) 0;
	char 			* wptr=(char *) 0;
	struct	element_style	* sptr;

	if ( styleclasslist ) {
		liberate( styleclasslist );
		styleclasslist=(char *) 0;
		}

	for ( 	sptr=ClassList;
		sptr !=(struct element_style *) 0;
		sptr = sptr->next ) {
		if (!( rptr ))
			rptr = style_string( sptr->name );
		else if (!( wptr = allocate( strlen( rptr ) + strlen( sptr->name ) + 2 )))
			break;
		else	{
			sprintf(wptr,"%s%c%s",rptr,separator,sptr->name);
			rptr = wptr;
			}
		}

	return((styleclasslist = rptr));
}


void	terminate_style_parser()
{
	struct	style_control * sptr;

	if (!( sptr = StyleContext ))
		return;
	else	{
		style_ungetch(0);
		StyleContext = sptr->next;

		if ( sptr->handle ) {
			if ( style_echo & 1 ) {
				printf("\r\n end of style file : %s \r\n",sptr->name);
				}
			fclose( sptr->handle );
			sptr->handle = (FILE * )0;
			}

		trace_style_errors(sptr);

		if ( sptr->name ) {
			liberate( sptr->name );
			sptr->name = (char *) 0;
			}
		sptr->input = (char *) 0;
		liberate( sptr );
		}
	return;
		

}


private	int	is_important()
{
	char *	tptr;
	if (!( tptr = style_token()))
		return(style_error(_style_expected_token));
	else if ( is_style_keyword(tptr) != _keyword_important )
		return(style_error(_style_incorrect_keyword));
	else	return(0);
}

private	int	style_semi_colon()
{
	int	status;
	while (1) {
		if ( is_style_semi_colon() ) {
			if ( is_style_close_brace() )
			 	return(_end_of_style);
			else	return(0);
			}
		else if ( is_style_close_brace() )
		 	return(_end_of_style);
		else if ( is_style_exclaim() ) {
			if (!(status = is_important() ))
				continue;
			else 	return( status );
			}
		else	return( style_error( _style_expected_token ) );
		}
}

private	int	convert_value	  (struct element_dimension * dptr, char * nptr)
{ 
	float	q=0.0;
	float	tmp=0.0;

#ifndef	WIN32
	/* 
	FCH portage: pour des raisons obscures, scanf("%f") plante 
	sous Windows (pb compil/link non trouvé)
	*/
	sscanf(nptr,"%f",&q);
#else
	/* FCH portage: pour des raisons obscures, 	*/
	/* scanf("%f") plante sous Windows 		*/
	/* (pb compil/link non trouvé)			*/
	q = (float)atof(nptr); 
#endif
	if (StyleConv.Mode == 0) { 
		switch ( dptr->type ) {
			case	_PC_DIMENSION	:	/* pica  dimensions 	*/
				dptr->value = (((q*_STYLE_DPI)/_STYLE_PCPI));
				dptr->type = _PIXEL_DIMENSION;
				break;

			case	_PT_DIMENSION	:	/* point dimensions 	*/
				dptr->value = (((q*_STYLE_DPI)/_STYLE_PTPI));
				dptr->type = _PIXEL_DIMENSION;
				break;

			case	_MM_DIMENSION	:	/* millimeters 		*/
				dptr->value = (((q*_STYLE_DPI)/_STYLE_MMPI));
				dptr->type = _PIXEL_DIMENSION;
				break;

			case	_CM_DIMENSION	:	/* centimeters 		*/
				dptr->value = (((q*_STYLE_DPI*10)/_STYLE_MMPI));
				dptr->type = _PIXEL_DIMENSION;
				break;

			case	_IN_DIMENSION	:	/* inchs		*/
				dptr->value = ((q * _STYLE_DPI));
				dptr->type = _PIXEL_DIMENSION;
				break;
			}
		}
	else	{
		/* Calcul pour HQ */
		/* Attention, on ne sait pas si c'est pour du x ou du y */
		/* On prend tjrs x et on suppose que y a la même proportion */
		/* A AMELIORER */

		tmp = q * StyleConv.xDpi * StyleConv.Scale / 100;

		switch ( dptr->type ) {
			case	_PC_DIMENSION	:	/* pica  dimensions 	*/
				tmp = tmp / _STYLE_PCPI;
				tmp = tmp * StyleConv.cxOri / StyleConv.cxDes;
				dptr->value = (int)tmp;
				dptr->type = _PIXEL_DIMENSION;
				break;

			case	_PT_DIMENSION	:	/* point dimensions 	*/
				tmp = tmp / _STYLE_PTPI;
				tmp = tmp * StyleConv.cxOri / StyleConv.cxDes;
				dptr->value = (int)tmp;
				dptr->type = _PIXEL_DIMENSION;
				break;

			case	_MM_DIMENSION	:	/* millimeters 		*/
				tmp = tmp / _STYLE_MMPI;
				tmp = tmp * StyleConv.cxOri / StyleConv.cxDes;
				dptr->value = (int)tmp;
				dptr->type = _PIXEL_DIMENSION;
				break;

			case	_CM_DIMENSION	:	/* centimeters 		*/
				tmp = tmp * 10 / _STYLE_MMPI;
				tmp = tmp * StyleConv.cxOri / StyleConv.cxDes;
				dptr->value = (int)tmp;
				dptr->type = _PIXEL_DIMENSION;
				break;

			case	_IN_DIMENSION	:	/* inchs		*/
				tmp = tmp;
				tmp = tmp * StyleConv.cxOri / StyleConv.cxDes;
				dptr->value = (int)tmp;
				dptr->type = _PIXEL_DIMENSION;
				break;
			}
		}

	return(0);
}

private	int	translate_style_integer  (int * iptr )
{
	char	*	vptr;
	if (!(vptr = style_token() ))
		return(style_error(_style_expected_token));
	*iptr = atoi( vptr );
	return(0);
}

private	int	translate_value	  (struct element_dimension * dptr )
{
	char	*	nptr;
	char	*	vptr;
	int		type;
	int		mode=1;

	if (!(vptr = style_token() ))
		return(style_error(_style_expected_token));
#ifdef	ABAL32A
	dptr->state=1;
	dptr->token[0] = 0;
#endif
	switch ((type = is_style_keyword( vptr ))) {
		case	_keyword_cell	:
			dptr->type = _CELL_DIMENSION;;
			dptr->value= 0;
			break;
		case	_keyword_text	:
			dptr->type = _TEXT_DIMENSION;;
			dptr->value= 0;
			break;
		case	_keyword_fixed  :
			dptr->type = _FIXED_DIMENSION;;
			dptr->value= 0;
			break;
		case	_keyword_auto	:
		case	_keyword_normal	:
			dptr->type = _AUTO_DIMENSION;;
			dptr->value= 0;
			break;
		case	-1 :
			dptr->value=0;
			strcpy(dptr->token,vptr);
			nptr = vptr;
			if ( *vptr== '-') {
				vptr++;
				mode=-1;
				}
			else	mode=1;

			while (( *vptr >= '0') && ( *vptr <= '9')) {
				dptr->value *= 10;
				dptr->value += ( *(vptr++) - '0' );
				}
			if ( *vptr == '.' ) {
				vptr++;
				while (( *vptr >= '0') && ( *vptr <= '9'))
					vptr++;
				}
			dptr->value *= mode;
			if ( *vptr == '+' )
				dptr->type = _PLUS_DIMENSION;
			else if ( *vptr == '%' ) 
				dptr->type = _PERCENT_DIMENSION;
			else if (( *vptr == 'p' ) &&  ( *(vptr+1) == 'x' )) 
				dptr->type = _PIXEL_DIMENSION;
			else if (( *vptr == 'e' ) &&  ( *(vptr+1) == 'm' )) 
				dptr->type = _ELEMENT_DIMENSION;
			else if (( *vptr == 'i' ) &&  ( *(vptr+1) == 'n' )) {
				dptr->type = _IN_DIMENSION;
				*vptr = 0;
				convert_value(dptr,nptr);
				if ( *(vptr+2) == '+' )
					dptr->type = _PLUS_DIMENSION;
				}
			else if (( *vptr == 'm' )  && ( *(vptr+1) == 'm' )) {
				*vptr = 0;
				dptr->type = _MM_DIMENSION;
				convert_value(dptr,nptr);
				if ( *(vptr+2) == '+' )
					dptr->type = _PLUS_DIMENSION;
				}
			else if (( *vptr == 'c' )  && ( *(vptr+1) == 'm' )) {
				dptr->type = _CM_DIMENSION;
				*vptr = 0;
				convert_value(dptr,nptr);
				if ( *(vptr+2) == '+' )
					dptr->type = _PLUS_DIMENSION;
				}
			else if (( *vptr == 'p' )  && ( *(vptr+1) == 't' )) {
				dptr->type = _PT_DIMENSION;
				*vptr = 0;
				convert_value(dptr,nptr);
				if ( *(vptr+2) == '+' )
					dptr->type = _PLUS_DIMENSION;
				}
			else if (( *vptr == 'p' )  && ( *(vptr+1) == 'c' )) {
				dptr->type = _PC_DIMENSION;
				*vptr = 0;
				convert_value(dptr,nptr);
				if ( *(vptr+2) == '+' )
					dptr->type = _PLUS_DIMENSION;
				}
			else	return( style_error( _style_incorrect_keyword ) ); 
		}
	return(0);
}


private	int	translate_size    (struct element_sizes * sptr)
{
	char *	tptr;
	int	type;
	int	status;
	if (!( tptr = style_token() ))
		return(style_error(_style_expected_token));
	else if ((type = is_style_keyword( tptr )) == -1)
		return( style_error( _style_incorrect_keyword ) );
	else if (!( is_style_colon()))
		return(style_error( _style_expected_colon )); 
	switch ( type ) {
		case	_keyword_top	:
			if ((status = translate_value(&sptr->top)) != 0)
				return(status);
			else	break;
		case	_keyword_right	:
			if ((status = translate_value(&sptr->right)) != 0)
				return(status);
			else	break;
		case	_keyword_bottom	:
			if ((status = translate_value(&sptr->bottom)) != 0)
				return(status);
			else	break;
		case	_keyword_left	:
			if ((status = translate_value(&sptr->left)) != 0)
				return(status);
			else	break;
		default			:
			return(_style_incorrect_keyword );
		}
	return( style_semi_colon() );
}

private	int	translate_border_width( struct element_dimension * sptr)
{
	char	*	tptr;
	int		status;
	if (!( is_style_dash() ))
		return(style_error( _style_expected_dash )); 
	else if (!(tptr = style_token() ))
		return(style_error(_style_expected_token));
	else if ( is_style_keyword(tptr) != _keyword_width )
		return( style_error( _style_expected_token ) );
	else if (!( is_style_colon() ))
		return(style_error(style_error( _style_expected_colon ))); 
	else	if ((status = translate_value(sptr)) != 0)
		return( status );
	else	return( style_semi_colon() );
}

private	int	translate_sizes    (struct element_sizes * sptr)
{
	int	status;
	if ( is_style_dash() )
		return(translate_size(sptr));
	else if (!( is_style_colon() ))
		return(style_error(_style_expected_colon )); 
	else if ((status = translate_value(&sptr->top)) != 0)
		return(status);
	else	{
		copy_value( &sptr->bottom, &sptr->top );
		copy_value( &sptr->right, &sptr->top );
		copy_value( &sptr->left, &sptr->top );
		}

	if ( is_style_semi_colon() ) {
		if ( is_style_close_brace() )
		 	return(_end_of_style);
		else	return(0);
		}
	else if ( is_style_close_brace() )
	 	return(_end_of_style);

	if (!( is_style_comma() )) 	return( style_error( _style_expected_comma ) );

	if ((status = translate_value(&sptr->right)) != 0)
		return(status);
	else	copy_value( &sptr->left, &sptr->right );

	if ( is_style_semi_colon() ) {
		if ( is_style_close_brace() )
		 	return(_end_of_style);
		else	return(0);
		}
	else if ( is_style_close_brace() )
	 	return(_end_of_style);
	if (!( is_style_comma() )) 	return( style_error( _style_expected_comma ) );

	if ((status = translate_value(&sptr->bottom)) != 0)
		return(status);
	
	if ( is_style_semi_colon() ) {
		if ( is_style_close_brace() )
		 	return(_end_of_style);
		else	return(0);
		}
	else if ( is_style_close_brace() )
	 	return(_end_of_style);

	if (!( is_style_comma() )) 	return( style_error( _style_expected_comma ) );

	else if ((status = translate_value(&sptr->left)) != 0)
		return(status);

	else	return( style_semi_colon() );

}

private	int	calculate_border_frame(struct element_style * sptr,int type,int width,int height)
{
	sptr->bordertype.top 	= sptr->bordertype.right = 
	sptr->bordertype.bottom = sptr->bordertype.left  = type;
	if ( sptr->bordersize.top.value < width ) {
		sptr->bordersize.top.value = width;
		sptr->bordersize.top.type  = _PIXEL_DIMENSION;
		}
	if ( sptr->bordersize.bottom.value < width ) {
		sptr->bordersize.bottom.value = width;
		sptr->bordersize.bottom.type  = _PIXEL_DIMENSION;
		}
	if ( sptr->bordersize.left.value < height ) {
		sptr->bordersize.left.value = height;
		sptr->bordersize.left.type  = _PIXEL_DIMENSION;
		}
	if ( sptr->bordersize.right.value < height ) {
		sptr->bordersize.right.value = height;
		sptr->bordersize.right.type  = _PIXEL_DIMENSION;
		}
	return 0;
}

private	int	translate_border_style(int * iptr, char ** sptr, int * vptr )
{
	char	*	tptr;
	int		type;
	if (!( tptr = style_token() ))
		return(style_error(_style_expected_token));
	else if ((type = is_style_keyword( tptr )) == -1)
		return( style_error( _style_incorrect_keyword ) );
	switch ( type ) {
		case	_keyword_none		:
			*iptr = type;
			break;
		case	_keyword_url		:
			*iptr = type;
			if (!( tptr = style_url_name() ))
				return( style_error( _style_expected_url ) );
			if (( vptr = *sptr) != (char *) 0)
				liberate( vptr );
			vptr = style_string( tptr );
			*sptr = vptr;
			break;
		case	_keyword_rounded	:
			*iptr = type;
			/* check for braced integer expression */
			/* providing rounding factor 1 to n ( n > 0 ) */
			if (!( is_style_left_bracket() ))
				break;			
			else if ( translate_style_integer( vptr ) )
				return( style_error( _style_expected_value ) ); 
			else if (!( is_style_right_bracket() ))
				return( style_error( _style_expected_right_brace ) ); 
			else	break;				

		case	_keyword_outset		:
		case	_keyword_inset		:
		case	_keyword_disk    	:
		case	_keyword_fill 		:
		case	_keyword_shade		:
		case	_keyword_hole    	:
		case	_keyword_edit		:
		case	_keyword_ridge		:
		case	_keyword_groove		:
		case	_keyword_convex		:
		case	_keyword_concave	:
		case	_keyword_double		:
		case	_keyword_dashed		:
		case	_keyword_solid		:
		case	_keyword_dotted		:
			*iptr = type;
			break;			
#ifdef	ABAL32A
		case	_keyword_vconvex	:
		case	_keyword_hconvex	:
		case	_keyword_vconcave	:
		case	_keyword_hconcave	:
			*iptr = type;
			break;			
#endif
		default				:
			return( style_error( _style_incorrect_keyword ) );
			
		}
	return(0);
}

private	int	translate_frame     (struct element_style * sptr)	
{
	char	*	tptr;
	int		type;

	if (!( is_style_colon() ))
		return(style_error( _style_expected_colon )); 
	else if (!( tptr = style_token() ))
		return(style_error(_style_expected_token));
	else if ((type = is_style_keyword( tptr )) == -1)
		return( style_error( _style_incorrect_keyword ) );
	switch ( type ) {
#ifdef	ABAL32A
		case	_keyword_vconvex	:
		case	_keyword_hconvex	:
		case	_keyword_vconcave	:
		case	_keyword_hconcave	:
#endif
		case	_keyword_none		:
			calculate_border_frame(sptr,type,0,0);
			break;
		case	_keyword_url		:
			if (!( tptr = style_url_name() ))
				return(  style_error(_style_expected_url ));
			calculate_border_frame(sptr,type,0,0);
			if ( sptr->bordertype.topimage )
				liberate( sptr->bordertype.topimage );
			sptr->bordertype.topimage = style_string( tptr );
			if ( sptr->bordertype.leftimage )
				liberate( sptr->bordertype.leftimage );
			sptr->bordertype.leftimage = style_string( tptr );
			if ( sptr->bordertype.bottomimage )
				liberate( sptr->bordertype.bottomimage );
			sptr->bordertype.bottomimage = style_string( tptr );
			if ( sptr->bordertype.rightimage )
				liberate( sptr->bordertype.rightimage );
			sptr->bordertype.rightimage = style_string( tptr );
			break;
		case	_keyword_rounded	:
			/* check for braced integer expression */
			/* providing rounding factor 1 to n ( n > 0 ) */
			if (!( is_style_left_bracket() ))
				break;			
			else if ( translate_style_integer( &sptr->rounding ) )
				return( style_error( _style_expected_value ) ); 
			else if (!( is_style_right_bracket() ))
				return( style_error( _style_expected_right_brace ) ); 
			else	{
				calculate_border_frame(sptr,type,0,0);
				break;				
				}
		case	_keyword_outset		:
		case	_keyword_inset		:
			calculate_border_frame(sptr,type,1,1);
			break;
		case	_keyword_disk    	:
		case	_keyword_shade		:
		case	_keyword_hole    	:
		case	_keyword_edit		:
		case	_keyword_ridge		:
		case	_keyword_groove		:
			calculate_border_frame(sptr,type,2,2);
			break;
		case	_keyword_convex		:
		case	_keyword_concave	:
			calculate_border_frame(sptr,type,1,5);
			break;
		case	_keyword_double		:
		case	_keyword_dashed		:
			calculate_border_frame(sptr,type,3,3);
			break;
		case	_keyword_solid		:
		case	_keyword_dotted		:
			calculate_border_frame(sptr,type,1,1);
			break;
		default				:
			return( style_error( _style_incorrect_keyword ) );
			
		}
	return( style_semi_colon() );
}

private	int	style_hex(char * tptr, int tlen )
{
	int	i;
	int	v;
	for (i=0,v=0; i < tlen; i++ ) {
		if ((*(tptr+i) >= '0' )
		&&  (*(tptr+i) <= '9' ))
			v = ((v * 16) + ( *(tptr+i) - '0' ));
		else if ((*(tptr+i) >= 'a' )
		     &&  (*(tptr+i) <= 'f' ))
			v = ((v * 16) + ( *(tptr+i) - 'a' ) + 10);
		else if ((*(tptr+i) >= 'A' )
		    &&  (*(tptr+i) <= 'F' ))
			v = ((v * 16) + ( *(tptr+i) - 'A' ) + 10);
		else	break;
		}
	return(v);
}

private	int	style_colour_correction( int value, int status )
{
	if ( status ) {
		switch ( value ) {
			case	1  : value =  4; break;
			case	4  : value =  1; break;
			case	9  : value = 12; break;
			case	12 : value =  9; break;

			case	3  : value =  6; break;
			case	6  : value =  3; break;
			case	11 : value = 14; break;
			case	14 : value = 11; break;
			}
		}
	return( value );
}


private	int	translate_colour    (struct element_colour	* sptr)	
{
	char	*	tptr;
	int		type;
#ifdef	TRACE_COLOURS
	int		rv=0;
	int		gv=0;
	int		bv=0;
#endif
	if (!( is_style_colon() ))
		return(style_error(_style_expected_colon)); 

	else if (!( tptr = style_token() ))
		return(style_error(_style_expected_token));

	else if ( *tptr == '#' ) {
		/* hexadecimal rgb constant */
		/* ------------------------ */
		tptr++;
		sptr->red   = style_hex(tptr,2); tptr+=2;
		sptr->green = style_hex(tptr,2); tptr+=2;
		sptr->blue  = style_hex(tptr,2); 
		sptr->entry = vga_approximation_two( sptr->red,sptr->green, sptr->blue );
		sptr->entry = style_colour_correction( sptr->entry,1 );
		return( style_semi_colon() );
		}
#ifdef	ABAL32A
	switch ((type = sptr->type = is_style_keyword( tptr ))) {
#else
	switch ((type = is_style_keyword( tptr ))) {
#endif
		case	_keyword_transparent	:
			sptr->entry = 0;
			break;
		case	_keyword_black		:
			sptr->entry = 16;
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;
		case	_keyword_navy		:
			sptr->entry = style_colour_correction((type - _keyword_black),0); 
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;
		case	_keyword_green		:
			sptr->entry = style_colour_correction((type - _keyword_black),0); 
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;
		case	_keyword_cyan		:
			sptr->entry = style_colour_correction((type - _keyword_black),0); 
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;
		case	_keyword_red		:
			sptr->entry = style_colour_correction((type - _keyword_black),0); 
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;
		case	_keyword_magenta	:
			sptr->entry = style_colour_correction((type - _keyword_black),0); 
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;
		case	_keyword_brown		:
			sptr->entry = style_colour_correction((type - _keyword_black),0); 
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;
		case	_keyword_grey		:
			sptr->entry = style_colour_correction((type - _keyword_black),0); 
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;
		case	_keyword_silver		:
			sptr->entry = style_colour_correction((type - _keyword_black),0); 
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;
		case	_keyword_blue		:
			sptr->entry = style_colour_correction((type - _keyword_black),0); 
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;
		case	_keyword_lime		:
			sptr->entry = style_colour_correction((type - _keyword_black),0); 
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;
		case	_keyword_sky		:
			sptr->entry = style_colour_correction((type - _keyword_black),0); 
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;
		case	_keyword_pink		:
			sptr->entry = style_colour_correction((type - _keyword_black),0); 
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;
		case	_keyword_purple		:
			sptr->entry = style_colour_correction((type - _keyword_black),0); 
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;
		case	_keyword_yellow		:
			sptr->entry = style_colour_correction((type - _keyword_black),0); 
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;
		case	_keyword_white		:
			sptr->entry = style_colour_correction((type - _keyword_black),0); 
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;

		case	_keyword_ihm		:
			if (!( is_style_left_bracket() ))
				return( style_error( _style_expected_left_brace ) ); 
			else if (!( tptr = style_token() ))
				return(style_error(_style_expected_token));
			else if (!( is_style_right_bracket() ))
				return( style_error( _style_expected_right_brace ) ); 
			else	sptr->entry=(atoi(tptr)+16);
			if ( sptr->entry == 255 ) { sptr->entry = 0; }
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;

		case	_keyword_rgb		:
			if (!( is_style_left_bracket() ))
				return( style_error( _style_expected_left_brace ) ); 
			else if (!( tptr = style_token() ))
				return(style_error(_style_expected_token));
			else if (!( is_style_right_bracket() ))
				return( style_error( _style_expected_right_brace ) ); 
			sptr->red   = style_hex(tptr,2); tptr+=2;
			sptr->green = style_hex(tptr,2); tptr+=2;
			sptr->blue  = style_hex(tptr,2); 
			sptr->entry = vga_approximation_two( sptr->red,sptr->green, sptr->blue );
			sptr->entry = style_colour_correction( sptr->entry,1 );
			break;

		case	_keyword_colour		:
			if (!( is_style_left_bracket() ))
				return( style_error( _style_expected_left_brace ) ); 
			else if (!( tptr = style_token() ))
				return(style_error(_style_expected_token));
			else if (!( is_style_right_bracket() ))
				return( style_error( _style_expected_right_brace ) ); 
			sptr->entry=0;
			while (( *tptr >= '0') && ( *tptr <= '9')) {
				sptr->entry *= 10;
				sptr->entry += ( *(tptr++) - '0' );
				}
			if ( sptr->entry == 255 ) { sptr->entry = 0; }
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;

		default	:
			return( style_error( _style_incorrect_keyword ));
		}
	return( style_semi_colon() );
}

private	int	translate_text_colour    (struct element_colour	* sptr)	
{
	char	*	tptr;
	int		type;
#ifdef	TRACE_COLOURS
	int		rv=0;
	int		gv=0;
	int		bv=0;
#endif

	if (!( is_style_colon() ))
		return(style_error(_style_expected_colon)); 

	else if (!( tptr = style_token() ))
		return(style_error(_style_expected_token));

	else if ( *tptr == '#' ) {
		/* hexadecimal rgb constant */
		/* ------------------------ */
		tptr++;
		sptr->red   = style_hex(tptr,2); tptr+=2;
		sptr->green = style_hex(tptr,2); tptr+=2;
		sptr->blue  = style_hex(tptr,2); 
		sptr->entry = vga_approximation_two( sptr->red,sptr->green, sptr->blue );
		sptr->entry = style_colour_correction( sptr->entry,1 );
		return( style_semi_colon() );
		}
#ifdef	ABAL32A
	switch ((type = sptr->type = is_style_keyword( tptr ))) {
#else
	switch ((type = is_style_keyword( tptr ))) {
#endif
		case	_keyword_transparent	:
			sptr->entry = 0;
			break;

		case	_keyword_black		:
			sptr->entry = 16;
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;

		case	_keyword_navy		:
			type = _keyword_red;
			sptr->entry = style_colour_correction((type - _keyword_black),1); 
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;
		case	_keyword_green		:
			sptr->entry = style_colour_correction((type - _keyword_black),1); 
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;
		case	_keyword_cyan		:
			type = _keyword_brown;
			sptr->entry = style_colour_correction((type - _keyword_black),1); 
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;
		case	_keyword_red		:
			type = _keyword_navy;
			sptr->entry = style_colour_correction((type - _keyword_black),1); 
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;
		case	_keyword_magenta	:
			sptr->entry = style_colour_correction((type - _keyword_black),1); 
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;
		case	_keyword_brown		:
			type = _keyword_cyan;
			sptr->entry = style_colour_correction((type - _keyword_black),1); 
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;
		case	_keyword_grey		:
			sptr->entry = style_colour_correction((type - _keyword_black),1); 
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;
		case	_keyword_silver		:
			sptr->entry = style_colour_correction((type - _keyword_black),1); 
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;
		case	_keyword_blue		:
			type = _keyword_pink;
			sptr->entry = style_colour_correction((type - _keyword_black),1); 
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;
		case	_keyword_lime		:
			sptr->entry = style_colour_correction((type - _keyword_black),1); 
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;
		case	_keyword_sky		:
			type = _keyword_yellow;
			sptr->entry = style_colour_correction((type - _keyword_black),1); 
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;
		case	_keyword_pink		:
			type = _keyword_blue;
			sptr->entry = style_colour_correction((type - _keyword_black),1); 
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;
		case	_keyword_purple		:
			sptr->entry = style_colour_correction((type - _keyword_black),1); 
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;
		case	_keyword_yellow		:
			type = _keyword_sky;
			sptr->entry = style_colour_correction((type - _keyword_black),1); 
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;
		case	_keyword_white		:
			sptr->entry = style_colour_correction((type - _keyword_black),1); 
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;

		case	_keyword_ihm		:
			if (!( is_style_left_bracket() ))
				return( style_error( _style_expected_left_brace ) ); 
			else if (!( tptr = style_token() ))
				return(style_error(_style_expected_token));
			else if (!( is_style_right_bracket() ))
				return( style_error( _style_expected_right_brace ) ); 
			else	sptr->entry=(atoi(tptr)+16);
			if ( sptr->entry == 255 ) { sptr->entry = 0; }
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;

		case	_keyword_rgb		:
			if (!( is_style_left_bracket() ))
				return( style_error( _style_expected_left_brace ) ); 
			else if (!( tptr = style_token() ))
				return(style_error(_style_expected_token));
			else if (!( is_style_right_bracket() ))
				return( style_error( _style_expected_right_brace ) ); 
			sptr->red   = style_hex(tptr,2); tptr+=2;
			sptr->green = style_hex(tptr,2); tptr+=2;
			sptr->blue  = style_hex(tptr,2); 
			sptr->entry = vga_approximation_two( sptr->red,sptr->green, sptr->blue );
			sptr->entry = style_colour_correction( sptr->entry, 1 );
#ifdef	TRACE_COLOURS
			printf("translate_text_colour : rgb(%02.2X%02.2X%02.2X) -> %u \r\n",sptr->red,sptr->green,sptr->blue,sptr->entry);
			get_rgb_values(sptr->entry, &rv, &gv, &bv );
			printf(" [ %02.2X%02.2X%02.2X ] \r\n",rv,gv,bv);
#endif
			break;

		case	_keyword_colour		:
			if (!( is_style_left_bracket() ))
				return( style_error( _style_expected_left_brace ) ); 
			else if (!( tptr = style_token() ))
				return(style_error(_style_expected_token));
			else if (!( is_style_right_bracket() ))
				return( style_error( _style_expected_right_brace ) ); 
			sptr->entry=0;
			while (( *tptr >= '0') && ( *tptr <= '9')) {
				sptr->entry *= 10;
				sptr->entry += ( *(tptr++) - '0' );
				}
			if ( sptr->entry == 255 ) { sptr->entry = 0; }
			get_rgb_values(sptr->entry,&sptr->red,&sptr->green,&sptr->blue );
			break;

		default	:
			return( style_error( _style_incorrect_keyword ));
		}
	return( style_semi_colon() );
}

private	int	translate_border_item(struct element_style * sptr, int item)
{
	char	*	tptr;
	int		status;
	if (!( is_style_dash() ))
		return(style_error( _style_expected_dash )); 
	else if (!(tptr = style_token() ))
		return(style_error(_style_expected_token));
	switch (  is_style_keyword(tptr) ) {

		case	_keyword_style	:
			if (!( is_style_colon() ))
				return(style_error( _style_expected_colon )); 

			switch ((item & 0xFF00) >> 8) {
				case	_keyword_top	:
					switch ( item & 0x00FF ) {
						case	_keyword_left	:
							if (( status = translate_border_style( &sptr->bordertype.topleft, &sptr->bordertype.topleftimage, &sptr->rounding )) != 0)
								return( status );
							else	break;	

						case	_keyword_right	:
							if (( status = translate_border_style( &sptr->bordertype.topright, &sptr->bordertype.toprightimage, &sptr->rounding )) != 0)
								return( status );
							else	break;	
						default		:
							return( style_error( _style_incorrect_keyword ) );
						}
					break;

				case	_keyword_bottom	:
					switch ( item & 0x00FF ) {
						case	_keyword_left	:
							if (( status = translate_border_style( &sptr->bordertype.bottomleft, &sptr->bordertype.bottomleftimage, &sptr->rounding )) != 0)
								return( status );
							else	break;	

						case	_keyword_right	:
							if (( status = translate_border_style( &sptr->bordertype.bottomright, &sptr->bordertype.bottomrightimage, &sptr->rounding )) != 0)
								return( status );
							else	break;	
						default		:
							return( style_error( _style_incorrect_keyword ) );
						}

					break;
				
				default			:


					switch ( item ) {
						case	_keyword_top	: 
							if (( status = translate_border_style( &sptr->bordertype.top, &sptr->bordertype.topimage, &sptr->rounding )) != 0)
								return( status );
							else	break;	
						case	_keyword_right	: 
							if (( status = translate_border_style( &sptr->bordertype.right, &sptr->bordertype.rightimage, &sptr->rounding  )) != 0)
								return( status );
							else	break;	
						case	_keyword_bottom	: 
							if (( status = translate_border_style( &sptr->bordertype.bottom, &sptr->bordertype.bottomimage, &sptr->rounding  )) != 0)
								return( status );
							else	break;	
						case	_keyword_left	:
							if (( status = translate_border_style( &sptr->bordertype.left, &sptr->bordertype.leftimage, &sptr->rounding  )) != 0)
								return( status );
							else	break;	
						default		:
							return( style_error( _style_incorrect_keyword ) );
						}
				}
			break;

		case	_keyword_width	:
			if (!( is_style_colon() ))
				return(style_error( _style_expected_colon )); 
			switch ( item ) {
				case	_keyword_top	: 
						if ((status = translate_value(&sptr->bordersize.top)) != 0) 
							return(status);
						else	break;
				case	_keyword_right	: 
						if ((status = translate_value(&sptr->bordersize.right)) != 0) 
							return(status);
						else	break;
				case	_keyword_bottom	: 
						if ((status = translate_value(&sptr->bordersize.bottom)) != 0) 
							return(status);
						else	break;
				case	_keyword_left	: 
						if ((status = translate_value(&sptr->bordersize.left)) != 0) 
							return(status);
						else	break;
				default		:
					return( style_error( _style_incorrect_keyword ) );
				}			
			break;
		}
	return( style_semi_colon() );
}


private	int	translate_border    (struct element_style * sptr)
{
	int	type;
	char *	tptr;
	if (!( is_style_dash() ))
		return(style_error( _style_expected_dash )); 
	else if (!( tptr = style_token() ))
 		return(style_error(_style_expected_token));
	else if ((type = is_style_keyword( tptr )) == -1)
		return( style_error( _style_incorrect_keyword ) );
	switch ( type ) {
		case	_keyword_width	: return( translate_sizes( &sptr->bordersize ) );
		case	_keyword_style	: return( translate_frame( sptr ) );
		case	_keyword_color	:
		case	_keyword_colour	: return( translate_colour( &sptr->bordercolour ) );
		case	_keyword_top	: return( translate_border_item(sptr,type) );
		case	_keyword_right	: return( translate_border_item(sptr,type) );
		case	_keyword_bottom	: return( translate_border_item(sptr,type) );
		case	_keyword_left	: return( translate_border_item(sptr,type) );
		case	_keyword_align	: return( translate_align( &sptr->borderalign ) );
		default			: return( style_error( _style_incorrect_keyword ) );
		}
}

private	int	translate_margin    (struct element_style * sptr)
{
	int	status;
	int	type;
	char *	tptr;
	if (!( is_style_dash() )) {
		if (!( is_style_colon() ))
			return(style_error( _style_expected_dash )); 
		else	{
			style_ungetch(':');
			return( translate_sizes( &sptr->marginsize ) );
			}
		}
	else if (!( tptr = style_token() ))
 		return(style_error(_style_expected_token));
	else if ((type = is_style_keyword( tptr )) == -1)
		return( style_error( _style_incorrect_keyword ) );
	switch ( type ) {
		case	_keyword_top	:
			if (!( is_style_colon()))
				return(style_error( _style_expected_colon )); 
			else if ((status = translate_value(&sptr->marginsize.top)) != 0)
				return(status);
			else	return( style_semi_colon() );
		case	_keyword_right	:
			if (!( is_style_colon()))
				return(style_error( _style_expected_colon )); 
			else if ((status = translate_value(&sptr->marginsize.right)) != 0)
				return(status);
			else	return( style_semi_colon() );
		case	_keyword_bottom	:
			if (!( is_style_colon()))
				return(style_error( _style_expected_colon )); 
			else if ((status = translate_value(&sptr->marginsize.bottom)) != 0)
				return(status);
			else	return( style_semi_colon() );
		case	_keyword_left	:
			if (!( is_style_colon()))
				return(style_error( _style_expected_colon )); 
			else if ((status = translate_value(&sptr->marginsize.left)) != 0)
				return(status);
			else	return( style_semi_colon() );
		case	_keyword_color	:
		case	_keyword_colour	: return( translate_colour( &sptr->margincolour ) );
		case	_keyword_align	: return( translate_align( &sptr->marginalign ) );
		case	_keyword_image	: return( translate_margin_image( sptr ) );
		case	_keyword_width	: return( translate_sizes( &sptr->marginsize ) );
		default			: return( style_error( _style_incorrect_keyword ) );
		}
}

private	int	translate_corner(struct element_style * sptr)
{
	int	type;
	char *	tptr;
	if (!( is_style_dash() ))
		return(style_error( _style_expected_dash )); 
	else if (!( tptr = style_token() ))
 		return(style_error(_style_expected_token));
	else if ((type = is_style_keyword( tptr )) == -1)
		return( style_error( _style_incorrect_keyword ) );
	switch ( type ) {
		case	_keyword_top	: 
			if (!( is_style_dash() ))
				return(style_error( _style_expected_dash )); 
			else if (!( tptr = style_token() ))
 				return(style_error(_style_expected_token));
			else if ((type = is_style_keyword( tptr )) == -1)
				return( style_error( _style_incorrect_keyword ) );
			switch ( type ) {
				case	_keyword_right	: 
				case	_keyword_left	: return( translate_border_item(sptr,(_keyword_top << 8) | type) );
				default			: 
					return( style_error( _style_incorrect_keyword ) );
				}
			
		case	_keyword_bottom	: 
			if (!( is_style_dash() ))
				return(style_error( _style_expected_dash )); 
			else if (!( tptr = style_token() ))
 				return(style_error(_style_expected_token));
			else if ((type = is_style_keyword( tptr )) == -1)
				return( style_error( _style_incorrect_keyword ) );
			switch ( type ) {
				case	_keyword_right	: 
				case	_keyword_left	: return( translate_border_item(sptr,(_keyword_bottom << 8) | type) );
				default			: 
					return( style_error( _style_incorrect_keyword ) );
				}
		default			: return( style_error( _style_incorrect_keyword ) );
		}
}

private	int	translate_font      (struct element_style * sptr)
{
	int	type;
	char *	tptr;
	if (!( is_style_colon() ))
		return(style_error( _style_expected_colon )); 
	else if (!( tptr = style_token() ))
		return(style_error(_style_expected_token));
	else if ((type = is_style_keyword( tptr )) == -1)
		return( style_error( _style_incorrect_keyword ) );

	switch ( type ) {

		case	_keyword_none	:
			sptr->textfont = 0;
			break;

		case	_keyword_url	:
			if (!( tptr = style_url_name() ))
				return( style_error( _style_expected_url ) );
			else if (!( sptr->textfont = visual_font( tptr, strlen(tptr) )))
				return( style_error( _file_not_found ) );
#ifdef	ABAL32A
			else if (!( sptr->fontname = allocate_string( tptr ) ))
				return( style_error( _allocation_failure ) );
#endif
			else	break;

		default	:
			return( style_error( _style_incorrect_keyword ) );
		}

	return( style_semi_colon() );
}

private	int	translate_atribut(struct element_style * sptr)
{
	int	v=0;
	char *	vptr;
	char *	tptr;
	if (!( is_style_colon() ))
		return(style_error( _style_expected_colon )); 
	while (1) {
		if (!( vptr = style_token() ))
			return(style_error(_style_expected_token));
		switch ( is_style_keyword(vptr) ) {
			case	_keyword_none		:
				sptr->textatribut = 0;
				break;
			case	_keyword_bold		:
				sptr->textatribut |= _TEXT_BOLD;
				break;
			case	_keyword_underline	:
				sptr->textatribut |= _TEXT_UNDERLINE;
				break;
			case	_keyword_overline	:
				sptr->textatribut |= _TEXT_OVERLINE;
				break;
			case	_keyword_line	:
				if (!( is_style_dash() ))
					return(style_error( _style_expected_dash )); 
				else if (!( tptr = style_token() ))
					return(style_error(_style_expected_token));
				else if ( is_style_keyword( tptr ) != _keyword_through ) 
					return(style_error(_style_expected_token));
				else	{
					sptr->textatribut |= _TEXT_STRIKE;
					break;
					}
			case	_keyword_blink	:
				sptr->textatribut |= _TEXT_BLINK;
				break;
			case	_keyword_shadow		:
				sptr->textatribut |= _TEXT_SHADOW;
				break;
			default				:
				return( style_error( _style_incorrect_keyword ) );
			}
		if (!( is_style_comma()))
			break;
		}
	return( style_semi_colon() );

}

private	int	translate_indent(struct element_dimension * vptr)
{
	int		status;
	if (!( is_style_colon() ))
		return(style_error( _style_expected_colon )); 
	else if ((status = translate_value( vptr )) != 0)
		return( status );
	else	return( style_semi_colon() );
}

private	int	translate_align      (int * iptr)
{
	char	*	tptr;
	int		type;
	if (!( is_style_colon() ))
		return(style_error( _style_expected_colon )); 
	else if (!( tptr = style_token() ))
		return(style_error(_style_expected_token));
	switch ((type = is_style_keyword( tptr ))) {
		case	_keyword_none	: *iptr = _ALIGN_NONE; 		break;
		case	_keyword_left	: *iptr = _ALIGN_LEFT; 		break;
		case	_keyword_right	: *iptr = _ALIGN_RIGHT;		break;
		case	_keyword_center	: *iptr = _ALIGN_CENTER;	break;
		case	_keyword_justify: *iptr = _ALIGN_JUSTIFY;	break;
		case	_keyword_repeat	:
		case	_keyword_tile   : *iptr = _ALIGN_JUSTIFY;	break;
		case	_keyword_makefit: *iptr = _ALIGN_STRETCH;	break;
		case	_keyword_bestfit: *iptr = _ALIGN_ADJUST;	break;
		case	_keyword_transparent	:
					*iptr |= _ALIGN_SPRITE;
					break;

		default			:
			return( style_error( _style_incorrect_keyword ) );
		}

	return( style_semi_colon() );

}

private	int	translate_vertical( int * iptr )
{
	char	*	tptr;
	int		type;
	if (!( is_style_dash() ))
		return(style_error( _style_expected_dash )); 
	else if (!( tptr = style_token() ))
		return(style_error(_style_expected_token));
	else if ((type = is_style_keyword( tptr )) != _keyword_align )
		return( style_error( _style_incorrect_keyword ) );
	else if (!( is_style_colon() ))
		return(style_error( _style_expected_colon )); 
	else if (!( tptr = style_token() ))
		return(style_error(_style_expected_token));
	switch ((type = is_style_keyword( tptr ))) {
		case	_keyword_baseline	:
		case	_keyword_sub		:
		case	_keyword_super		:
		case	_keyword_middle		:
		case	_keyword_none		:
		case	_keyword_top		:
		case	_keyword_bottom		:
		case	_keyword_text		:
			*iptr = type;
			break;
		default			:
			return( style_error( _style_incorrect_keyword ) );
		}
	return( style_semi_colon() );
}


private	int	translate_text      (struct element_style * sptr)	
{
	char	*	tptr;
	int		type;

	if (!( is_style_dash() ))
		return(style_error( _style_expected_dash )); 
	else if (!( tptr = style_token() ))
		return(style_error(_style_expected_token));
	else if ((type = is_style_keyword( tptr )) == -1)
		return( style_error( _style_incorrect_keyword ) );
	switch ( type ) {
		case	_keyword_align	:
			return( translate_align( &sptr->textalign ) );
		case	_keyword_color	:
		case	_keyword_colour	:
			return( translate_text_colour( &sptr->textcolour ) );
		case	_keyword_style		:
		case	_keyword_decoration	:
			return( translate_atribut( sptr ) );
		case	_keyword_font	:
			return( translate_font( sptr ) );
		case	_keyword_indent	:
			return( translate_indent( &sptr->textindent ) );
		default				:
			return( style_error( _style_incorrect_keyword ) );
		}
	return( style_semi_colon() );
}

#ifdef	ABAL32A
private	int	translate_shadow      (struct element_style * sptr)	
{
	char	*	tptr;
	int		type;

	if (!( is_style_dash() ))
		return(style_error( _style_expected_dash )); 
	else if (!( tptr = style_token() ))
		return(style_error(_style_expected_token));
	else if ((type = is_style_keyword( tptr )) == -1)
		return( style_error( _style_incorrect_keyword ) );
	switch ( type ) {
		case	_keyword_color	:
		case	_keyword_colour	:
			return( translate_text_colour( &sptr->shadowcolour ) );
		case	_keyword_width 	: 
			return( translate_width   (&sptr->shadowwidth   )  );
		case	_keyword_height	: 
			return( translate_height  (&sptr->shadowheight  ) );
		default			:
			return( style_error( _style_incorrect_keyword ) );
		}
	return( style_semi_colon() );
}
#endif
private	int	translate_background_image     (struct element_style * sptr)	
{
	char	*	tptr;
	int	type;

	if (!( is_style_colon() ))
		return(style_error( _style_expected_colon )); 
	else if (!( tptr = style_token() ))
		return(style_error(_style_expected_token));
	else if ((type = is_style_keyword( tptr )) == -1)
		return( style_error( _style_incorrect_keyword ) );
	switch ( type ) {
		case	_keyword_none	: 
			if ( sptr->backgroundimage ) {
				liberate( sptr->backgroundimage );
				sptr->backgroundimage = (char *) 0;
				}
			break;

		case	_keyword_url	:
			if (!( tptr = style_url_name() ))
				return( style_error( _style_expected_url ) );
			else if (!( sptr->backgroundimage = style_string( tptr ) ))
				return(style_error( _allocation_failure ));
			else	break;

		default	:
			return( style_error( _style_incorrect_keyword ) );
		}
	return( style_semi_colon() );
}

private	int	translate_margin_image     (struct element_style * sptr)	
{
	char	*	tptr;
	int	type;

	if (!( is_style_colon() ))
		return(style_error( _style_expected_colon )); 
	else if (!( tptr = style_token() ))
		return(style_error(_style_expected_token));
	else if ((type = is_style_keyword( tptr )) == -1)
		return( style_error( _style_incorrect_keyword ) );
	switch ( type ) {
		case	_keyword_url	:
			if (!( tptr = style_url_name() ))
				return( style_error( _style_expected_url ) );
			else if (!( sptr->marginimage = style_string( tptr ) ))
				return(style_error( _allocation_failure ));
			else	break;

		default	:
			return( style_error( _style_incorrect_keyword ) );
		}
	return( style_semi_colon() );
}

private	int	translate_attach     (struct element_style * sptr)	
{
	char	*	tptr;
	int		type;
	if (!( is_style_colon() ))
		return(style_error( _style_expected_colon )); 
	else if (!( tptr = style_token() ))
		return(style_error(_style_expected_token));
	else if ((type = is_style_keyword( tptr )) == -1)
		return( style_error( _style_incorrect_keyword ) );
	switch ( type ) {
		case	_keyword_fixed	:
		case	_keyword_scroll	:
			sptr->backgroundattach = type;
			break;
		default	:
			return( style_error( _style_incorrect_keyword ) );
		}
	return( style_semi_colon() );
}

private	int	translate_background(struct element_style * sptr)
{
	char	*	tptr;
	int		type;

	if (!( is_style_dash() ))
		return(style_error( _style_expected_dash )); 
	else if (!( tptr = style_token() ))
		return(style_error(_style_expected_token));
	else if ((type = is_style_keyword( tptr )) == -1)
		return( style_error( _style_incorrect_keyword ) );
	switch ( type ) {
		case	_keyword_color	:
		case	_keyword_colour	:
			return( translate_colour( &sptr->backgroundcolour ) );
		case	_keyword_image	:
			return( translate_background_image( sptr ) );
		case	_keyword_attach	:
			return( translate_attach( sptr ) );
		case	_keyword_align	:
			return( translate_align( &sptr->backgroundalign ) );
		default			:
			return( style_error( _style_incorrect_keyword ) );
		}
	return( style_semi_colon() );
}

private	int	translate_width(struct element_dimension * sptr )
{
	int	status;
	if (!( is_style_colon() ))
		return(style_error( _style_expected_colon )); 
	else if ((status = translate_value( sptr ) ) != 0)
		return( status );
	return( style_semi_colon() );
}

private	int	translate_position(struct element_position *  pptr )
{
	int		type;
	char	*	tptr;
	if (!( is_style_colon() ))
		return(style_error( _style_expected_colon )); 
	else if (!( tptr = style_token() ))
		return(style_error(_style_expected_token));
	else if ((type = is_style_keyword( tptr )) == -1)
		return( style_error( _style_incorrect_keyword ) );
	switch ( type ) {
		case	_keyword_home		:
		case	_keyword_auto		:
		case	_keyword_static		:
		case	_keyword_relative	:
		case	_keyword_absolute	:
		case	_keyword_fixed		:
			pptr->type = type;
			break;
		default			:
			return( style_error( _style_incorrect_keyword ) );
		}
	return( style_semi_colon() );
}

private	int	translate_side(struct element_dimension * sptr )
{
	int		status;
	if (!( is_style_colon() ))
		return(style_error(style_error( _style_expected_colon ))); 
	else	if ((status = translate_value(sptr)) != 0)
		return( status );
	else	return( style_semi_colon() );
}

private	int	translate_float(struct element_position *  pptr)
{
	int		type;
	char	*	tptr;
	if (!( is_style_colon() ))
		return(style_error( _style_expected_colon )); 
	else if (!( tptr = style_token() ))
		return(style_error(_style_expected_token));
	else if ((type = is_style_keyword( tptr )) == -1)
		return( style_error( _style_incorrect_keyword ) );
	switch ( type ) {
		case	_keyword_none	:
		case	_keyword_left	:
		case	_keyword_right	:
		case	_keyword_top	:
		case	_keyword_bottom	:
		case	_keyword_home	:
			pptr->option = type;
			break;
		default			:
			return( style_error( _style_incorrect_keyword ) );
		}
	return( style_semi_colon() );
}

private	int	translate_height(struct element_dimension * sptr )
{
	int	status;
	if (!( is_style_colon() ))
		return(style_error( _style_expected_colon )); 
	else if ((status = translate_value( sptr ) ) != 0)
		return( status );
	return( style_semi_colon() );
}

#ifdef	ABAL32A
int	style_class_count()
{
	int	result=0;
	struct	element_style * sptr;
	for (	sptr=ClassList;
		sptr != (struct element_style *) 0;
		sptr = sptr->next )
		result++;
	return(result);
}

int	style_file_count()
{
	int	result=0;
	struct	element_file * fptr;
	for (	fptr=FileList;
		fptr != (struct element_file *) 0;
		fptr = fptr->next )
		result++;
	return(result);
}

struct	element_style *	resolve_stylefile_number( int n )
{
	int	i=1;
	struct	element_file * fptr;
	for ( fptr=FileList; fptr != (struct element_file *) 0; fptr = fptr->next ) {
		if ( n == i )
			break;
		else	i++;
		}
	return(fptr);
}

struct	element_file *	resolve_stylefile_name( char * nptr )
{
	struct	element_file * fptr;
	if (!( nptr )) {
		return((struct element_file *) 0);
		}
	for ( fptr=FileList; fptr != (struct element_file *) 0; fptr = fptr->next ) {
		if (!( fptr->name ))
			continue;
		else if (!( strcmp( fptr->name, nptr )))
			break;
		}
	return(fptr);
}

int	style_file_members(int nbf)
{
	int	result=0;
	struct	element_file * fptr;
	struct	element_class * cptr;
	if (!( fptr = resolve_stylefile_number( nbf )))
		return(0);
	for (	cptr=fptr->first;
		cptr != (struct element_class *) 0;
		cptr = cptr->next )
		result++;
	return(result);
}


struct	element_class *	resolve_stylefile_member(struct element_file * fptr, int n )
{
	int	i=1;
	struct	element_class * cptr;
	if (!( fptr ))
		return((struct element_class *) 0);
	for ( 	cptr=fptr->first; 
		cptr != (struct element_class *) 0; 
		cptr = cptr->next ) {
		if ( n == i )
			break;
		else	i++;
		}
	return(cptr);
}

struct	element_style *	resolve_style_number( int n )
{
	int	i=1;
	struct	element_style * eptr;
	for ( eptr=ClassList; eptr != (struct element_style *) 0; eptr = eptr->next ) {
		if ( n == i )
			break;
		else	i++;
		}
	return(eptr);
}

public	char *	resolve_style_domain( char * tptr )
{
	char * qptr;
	int	i;
	if (!( tptr ))
		return(tptr);

	for (i=0; *(tptr+i) != 0; i++ ) {
		if ( *(tptr+i) == '/' )
			return( allocate_string( tptr ) );
		}

	if (!( StyleDomain ))
		return( allocate_string( tptr ) );
	else 	{
		if (( qptr = allocate( strlen( StyleDomain ) + strlen( tptr ) + 3 )) != (char *) 0)
			sprintf(qptr,"%s/%s",StyleDomain,tptr);
		return( qptr );
		}
}

#else
#define	resolve_style_domain( tptr ) allocate_string( tptr )
#endif

public	struct element_style * resolve_style_class( char * tptr )
{
	struct	element_style * eptr;
	int	h;
	char *	qptr;
	if (!( tptr ))
		return((struct element_style *) 0);
	else if (!( qptr = resolve_style_domain( tptr ) ))
		return((struct element_style *) 0);

	if ( style_echo & 2 )
		printf("resolve_class(%s)\r\n",qptr);

	h = style_element_hash( qptr );

	/* ------------------------------------------------------------------- */
	/* Scan the list of loaded style class items to locate the class named */
	/* ------------------------------------------------------------------- */
	for ( eptr=ClassList; eptr != (struct element_style *) 0; eptr = eptr->next ) {
		if ( eptr->hash != h )
			continue;
		else if (!( eptr->name ))
			continue;
		else if (!( strcmp( eptr->name, qptr ) ))
			break;
		else	continue;
		}

	if ( style_echo & 2 )
		if ( eptr ) 
			printf("   ->%s\r\n",eptr->name);	

	liberate( qptr ); 

	return( eptr );
}

int	resolve_style_height( char * sname )
{
	struct	element_style * eptr;
	if (!( eptr = resolve_style_class( sname ) ))
		return(0);
	else	return( eptr->cellheight.value );
}

int	resolve_style_width( char * sname )
{
	struct	element_style * eptr;
	if (!( eptr = resolve_style_class( sname ) ))
		return(0);
	else	return( eptr->cellwidth.value );
}

int	resolve_style_textwidth( char * sname, char * sptr, int slen )
{
	int	fid;
	struct	element_style * eptr;
	if (!( eptr = resolve_style_class( sname ) ))
		return(0);
	else if (!( fid = resolve_style_font( sname ) ))
		return(0);
	else if (!( eptr->letterspacing.state ))
		return( textsizelen( fid, sptr, slen ) );
	else 	return(( textsizelen( fid, sptr, slen) + (slen * eptr->letterspacing.value)));
}

int	resolve_style_position( char * sname, int * l, int * r, int * t, int * b)
{
	int	nb=0;
	struct	element_style * eptr;
	if (!( eptr = resolve_style_class( sname ) ))
		return(0);
	else	{
		if (eptr->cellposition.right.type  == _PIXEL_DIMENSION ) {
			*r = eptr->cellposition.right.value; nb |=1;
			}
		else	*r = -1;
		if (eptr->cellposition.left.type  == _PIXEL_DIMENSION ) {
			*l = eptr->cellposition.left.value; nb |=2;
			}
		else	*l = -1;
		if (eptr->cellposition.top.type  == _PIXEL_DIMENSION ) {
			*t = eptr->cellposition.top.value; nb |= 4;
			}
		else	*t = -1;
		if (eptr->cellposition.bottom.type  == _PIXEL_DIMENSION ) {
			*b = eptr->cellposition.bottom.value; nb |= 8;
			}
		else	*b = -1;
		return(nb);
		}
}

int	resolve_style_dimensions( char * sname, int * w, int * h )
{
	struct	element_style * eptr;
	if (!( eptr = resolve_style_class( sname ) ))
		return(0);
	else	{
		*w = eptr->cellwidth.value;
		*h = eptr->cellheight.value;
		return(1);
		}
}

int	resolve_style_fontheight( char * sname )
{
	int	h;
	struct	element_style * eptr;
	if (!( eptr = resolve_style_class( sname ) ))
		return(0);
	else if (!( eptr->textfont ))
		return(0);
	else if (!( h = guifontsize( eptr->textfont  )))
		return(0);
	else	return(((h >> 8) & 0x00FF));
}

int	resolve_style_font( char * sname )
{
	int	h;
	struct	element_style * eptr;
	if (!( eptr = resolve_style_class( sname ) ))
		return(0);
	else if (!( eptr->textfont ))
		return(0);
	else	return( eptr->textfont );
}

private	int	translate_class( struct element_style * sptr )
{

	char	*	tptr;
	struct	element_style * eptr;

	if (!( is_style_colon() ))
		return(style_error( _style_expected_colon )); 
	else if (!( tptr = style_token() ))
		return(style_error(_style_expected_token));
	else if (!( eptr = resolve_style_class( tptr ) ))
		return(style_error(_style_undefined_class));
	else	{
		/* Preserve : Owner and Filename */
		release_style( sptr, 1 );
#ifdef	ABAL32A
		sptr->basename = resolve_style_domain( tptr );
#endif
		copy_style( sptr, eptr );
		return( style_semi_colon() );
		}
}

private	int	translate_content( int * iptr, int * vptr )
{
	int		type;
	char	*	tptr;
	if (!( is_style_colon() ))
		return(style_error( _style_expected_colon )); 
	else if (!( tptr = style_token() ))
		return(style_error(_style_expected_token));
	switch (( type = is_style_keyword( tptr )) ) {
		case	_keyword_url	:
		case	_keyword_text	:
		case	_keyword_trigger:
			*iptr = type;
			/* url(integer), text(integer), trigger(integer) */
			if ( is_style_left_bracket() ) {
				if ( translate_style_integer( vptr ) )
					return( style_error( _style_expected_value ) ); 
				else if (!( is_style_right_bracket() ))
					return( style_error( _style_expected_right_brace ) );
				}
			break;
		case	_keyword_grip	:	
		case	_keyword_up	:	
		case	_keyword_down	:	
		case	_keyword_top 	:	
		case	_keyword_bottom	:
		case	_keyword_left	:	
		case	_keyword_right	:	
		case	_keyword_auto	:
		case	_keyword_none	:
			*iptr = type;
			break;
		default			:
			return(style_error(_style_expected_token));
		}
	return( style_semi_colon() );
}

private	int	translate_spacing( struct element_dimension * sptr )
{
	int		status;
	int		type;
	char	*	tptr;

	if (!( is_style_dash() ))
		return(style_error( _style_expected_dash )); 
	else if (!( tptr = style_token() ))
		return(style_error(_style_expected_token));
	else if ((type = is_style_keyword( tptr )) != _keyword_spacing )
		return( _style_incorrect_keyword );
	else if (!( is_style_colon() ))
		return(style_error( _style_expected_colon )); 
	else if ((status = translate_value( sptr )) != 0)
		return( status );
	else	return( style_semi_colon() );
}

private	int	translate_alias( struct element_style * sptr )
{
	char	*	rptr=(char*)0;
	char	*	tptr;
	char	*	wptr;

	if (!( is_style_colon() ))
		return(style_error( _style_expected_colon )); 
	else	{
		while (1) {			
			if (!( tptr = style_token() ))
				return(style_error(_style_expected_token));
			else if (!( rptr )) {
				if (!( rptr = allocate_string( tptr ) ))
					return(style_error(_allocation_failure));
				}
			else if (!( wptr = allocate( strlen( rptr ) + strlen( tptr ) + 4 ) ))
				return(style_error(_allocation_failure));
			else	{
				sprintf(wptr,"%s|%s",rptr,tptr);
				liberate( rptr );
				rptr = wptr;
				}
			if (!( is_style_comma() )) {
				sptr->alias = rptr;
				return( style_semi_colon() );
				}
			}
		}
}

/*	------------------------------------		*/
/*	t r a n s l a t e _ f i l e ( sptr )		*/
/*	------------------------------------		*/
/*		file: url(filename);			*/
/*	this construction is for use by style		*/
/*	development tools to handle the name		*/
/*	of the original file from which the 		*/
/*	style class had been read.			*/
/*	------------------------------------		*/

private	int	translate_file( struct element_style * sptr )
{
	char	*	tptr;
	int		type;

	if (!( is_style_colon() ))
		return(style_error( _style_expected_colon )); 
	else if (!( tptr = style_token() ))
		return(style_error(_style_expected_token));
	else if ((type = is_style_keyword( tptr )) == -1)
		return( style_error( _style_incorrect_keyword ) );
	else if ( type != _keyword_url )
		return( style_error( _style_incorrect_keyword ) );
	else if (!( tptr = style_url_name() ))
		return( style_error( _style_expected_url ) );
	else if (!( sptr->filename = allocate_string( tptr ) ))
		return(style_error(_allocation_failure));
	else 	return(style_semi_colon());
}

private	int	translate_style( struct element_style * sptr, char * token )
{
	int	type;
	if ((type = is_style_keyword( token )) == -1)
		return( style_error( _style_incorrect_keyword ));
	else	{
		switch ( type ) {
			case	_keyword_margin		: return( translate_margin    (sptr) );
			case	_keyword_corner		: return( translate_corner    (sptr) );
			case	_keyword_border		: return( translate_border    (sptr) );
			case	_keyword_padding	: return( translate_sizes( &sptr->paddingsize ));
			case	_keyword_text		: return( translate_text      (sptr) );	
			case	_keyword_background	: return( translate_background(sptr) );
			case	_keyword_vertical	: return( translate_vertical  (&sptr->verticalalign) );
			case	_keyword_class		: return( translate_class( sptr ) );
			case	_keyword_letter		: return( translate_spacing(&sptr->letterspacing)  );
			case	_keyword_line		: return( translate_spacing(&sptr->linespacing)  );
			case	_keyword_word		: return( translate_spacing(&sptr->wordspacing)  );
			case	_keyword_content	: return( translate_content(&sptr->nature,&sptr->item)  ); 
			case	_keyword_alias		: return( translate_alias   (sptr)  ); 
			case	_keyword_file		: return( translate_file    (sptr)  ); 
			case	_keyword_width 		: return( translate_width   (&sptr->cellwidth   )  );
			case	_keyword_height		: return( translate_height  (&sptr->cellheight  ) );
			case	_keyword_float  	: return( translate_float   (&sptr->cellposition	)  ); 
#ifdef	ABAL32A
			case	_keyword_shadow		: return( translate_shadow  (sptr) );
#endif
			/* -------------------------------------------------------- */
			/* CSS Level 2 Extensions required for Positioning Elements */
			/* -------------------------------------------------------- */
			case	_keyword_position	: return( translate_position(&sptr->cellposition	) );
			case	_keyword_top	  	: return( translate_side    (&sptr->cellposition.top	)  ); 
			case	_keyword_right  	: return( translate_side    (&sptr->cellposition.right	)  ); 
			case	_keyword_bottom 	: return( translate_side    (&sptr->cellposition.bottom	)  ); 
			case	_keyword_left   	: return( translate_side    (&sptr->cellposition.left	)  ); 

			default				: return( style_error( _style_incorrect_keyword )  );
			}
		}
}


/*	---------------------------------------------------	*/
/*		p a r s e _ v i s u a l _ s t y l e 		*/
/*	---------------------------------------------------	*/
/*	This function is called to configure or reconfigure	*/
/*	a visual style definition that may be activated	by	*/
/*	the visual atribut mechanisms				*/
/*	---------------------------------------------------	*/
private	int	parse_visual_style(char * bptr, int blen)
{
	int	atbv;
	int	status;
	char *	tptr;
	char *	mptr;
	struct	element_style *	sptr;

	if ((( atbv = *(bptr++)) >= 'a' ) &&  ( atbv <= 'z' ))
		atbv -= 'a';
	else if (( atbv >= 'A' ) &&  ( atbv <= 'Z' )) {
		atbv -= 'A'; atbv += 26;
		}
	else	return( style_error( _style_incorrect_keyword ) );

	if (!(mptr = allocate( blen + 2 )))
		return(style_error(_allocation_failure));
	else	{
		memcpy(mptr,bptr,blen);
		*(mptr+blen) = 0;
		}
	if ((status = initialise_style_string_parser( mptr )) == 0) {
		if ((status = visual_style( atbv )) == 0) {
			if (!( sptr = StyleHeap[atbv] ))
				status = 118;
			else	{
				while ((tptr = style_token()) != (char*) 0)
					if ((status = translate_style( sptr, tptr )) != 0)
						break;
				if ( status == _end_of_style ) status = 0;
				}
			}
		}
	liberate( mptr );
	terminate_style_parser();
	return( status  );
}

#ifdef	ABAL32A

private	char *	remove_string_space( char * bptr )
{
	while ( *bptr ) {
		switch ( *bptr ) {
			case	' '	:
			case	'\t'	:
			case	'\n'	:
			case	'\r'	:
				bptr++;
				continue;
			}
		break;
		}
	return( bptr );
}

private	char *	remove_string_comment( char * bptr )
{
	if (!( bptr ))	return( bptr );
	if (!( *bptr )) return( bptr );
	if (!( bptr = remove_string_space( bptr )))
		return( bptr );
	while (( *bptr == '/' ) && ( *(bptr+1) == '*' )) {
		bptr+= 2;
		while ( *bptr != 0 )  {
			if (( *bptr == '*' ) && ( *(bptr+1) == '/' )) {
				bptr+= 2;
				break;
				}
			else	bptr++;
			}
		}
	return( remove_string_space( bptr ) );
}

/*	---------------------------------------------------	*/
/*		d e f i n e _ v i s u a l _ s t y l e 		*/
/*	---------------------------------------------------	*/
/*	This function is called to configure or reconfigure	*/
/*	a style class definition outside of a class file.	*/
/*	---------------------------------------------------	*/
public	int	define_visual_style(char * bptr, int blen)
{
	int	atbv;
	int	status;
	char *	tptr;
	char *	mptr;
	char *	nptr;
	char *	wptr;
	int	wlen;
	struct	element_style *	sptr;
	
	bptr = remove_string_comment( bptr );

	while ( *bptr == ' ' ) {
		bptr++;
		blen--;
		}

	bptr = remove_string_comment( bptr );

	wptr = bptr;
	wlen = blen;
	while ((*wptr != ' ') && ( *wptr != '\t') && ( *wptr != 0 )) {
		wptr++;
		wlen--;
		}

	/* allocate style expression */
	/* ------------------------- */
	if (!(mptr = allocate( wlen + 2 )))
		return(style_error(_allocation_failure));
	else	{
		memcpy(mptr,wptr,wlen);
		*(mptr+wlen) = 0;
		}

	if (!( nptr =allocate((blen-wlen) + 2) )) {
		liberate( mptr );
		return(style_error(_allocation_failure));
		}
	else	{
		memcpy(nptr,bptr,(blen-wlen));
		*(nptr+(blen-wlen)) = 0;
		}

	if ((status = initialise_style_string_parser( mptr )) == 0) {
		if (!( sptr = overload_style( nptr ) ))
			status = 118;
		else	{
			while ((tptr = style_token()) != (char*) 0)
				if ((status = translate_style( sptr, tptr )) != 0)
					break;
			if ( status == _end_of_style ) status = 0;
			}
		}
	terminate_style_parser();
	if ( mptr ) { 	liberate( mptr );	}
	if ( nptr ) { 	liberate( nptr );	}
	return( status  );
}
#endif

struct	style_object	{
	int	vph;
	int	vpw;
	int	gfh;
	int	gfw;
	int	atx;
	int	aty;
	int	nbx;
	int	nby;
	int	tmi;
	int	lmi;
	int	length;
	char *	message;
	};

#ifdef	_TRACE_STYLE
private	void	showzone( char * message, struct style_zone * sptr)
{
	printf("%s : x=%u,y=%u,w=%u,h=%u\r\n",message,sptr->x,sptr->y,sptr->w,sptr->h);
	return;
}
#endif

#define	rgbtriad(s) get_rgb_pixel( s.red,s.green,s.blue)
#define	newrgb(s) make_rgb_pixel( s.red,s.green,s.blue)

#include "varrow.h"
#include "vtstyle.c"
#include "vvstyle.c"



/*	---------------------------------------------------	*/
/*		r e s e t _ v i s u a l _ s t y l e 		*/
/*	---------------------------------------------------	*/
/*	This function is called to terminate application of 	*/
/*	a visual style definition by the visual atribut		*/
/*	mechanisms						*/
/*	---------------------------------------------------	*/
#ifdef	_vatb_c
private	int	reset_visual_style()
{
	struct	style_object	context;
	struct	element_style *	sptr;
	char 		      * copystring=(char *) 0;
	if (!( sptr = ActiveStyle ))
		return(0);
	else	{
		context.vpw = VisEsc.vpw;
		context.vph = VisEsc.vph;
		context.gfh = VisEsc.gfh;
		context.gfw = VisEsc.gfw;
		context.lmi = VisEsc.lmi;
		context.tmi = VisEsc.tmi;
		context.atx = VisEsc.lmi+((VisEsc.atcol-1)*VisEsc.gfw);
		context.aty = VisEsc.tmi+((VisEsc.atlin-1)*VisEsc.gfh);
		context.nbx = (VisEsc.buflen*VisEsc.gfw);
		context.nby = VisEsc.gfh;

		if (!( sptr->item )) {
			context.message = VisEsc.buffer;
			context.length  = VisEsc.buflen;
			}
		else if (!( copystring = allocate( VisEsc.buflen+1 ) ))
			return(0);
		else	{
			memcpy( copystring,VisEsc.buffer, VisEsc.buflen );
			*(copystring+VisEsc.buflen) = 0;
			if (!( context.message = selection_item((sptr->item-1),copystring )))
				context.message = allocate_string( "\0" );
			context.length  = strlen( context.message );
			}
		ActiveStyle=(struct element_style *) 0;
		apply_textual_style( sptr, &context );
		if ( copystring ) {
			liberate( copystring );
			liberate( context.message );
			}
		return(1);
		}
}

/*	---------------------------------------------------	*/
/*		u s e  _ v i s u a l _ s t y l e 		*/
/*	---------------------------------------------------	*/
/*	This function is called to activate application of 	*/
/*	a visual style definition by the visual atribut		*/
/*	mechanisms						*/
/*	---------------------------------------------------	*/
private	int	use_visual_style( int item )
{
	struct	element_style *	sptr;
	if ( item >= _MAX_STYLE )
		return(0);
	else if (!( sptr = StyleHeap[item] ))
		return(0);
	else	{
		ActiveStyle = sptr;
		if ( sptr->nature == _keyword_none ) {
			VisEsc.buflen=1;
			reset_visual_atribut();
			return(0);
			}
		else	return(1);
		}
}
#endif

/*		----------------------------------------------------		*/
/*		l o a d _ v i s u a l _ s t y l e ( buffer, length )		*/
/*		----------------------------------------------------		*/
/*		This function is called to load visual style from an		*/
/*		external css file description to be reused by style		*/
/*		expressions activetool the class keyword.				*/
/*		----------------------------------------------------		*/


int	load_visual_style(char * bptr,int blen);

private	style_element_hash( char * nptr )
{
	int	h=0;
	while ( *nptr )
		h += *(nptr++);
	return((h % 57));
}

private	int	import_style()
{
	char *	nomfic;
	int	status;
	if (!( nomfic = style_token()))
		return( style_error( _style_expected_token ) );
	else if ( is_style_keyword( nomfic ) != _keyword_url )
		return( style_error( _style_expected_url ) );
	else if (!( nomfic = style_url_name() ))
		return( style_error( _style_expected_url ) );
	else if (!( is_style_semi_colon() ))
		return(style_error(_style_expected_semicolon));
	else if ((status = load_visual_style( nomfic, strlen( nomfic ))) != _end_of_style)
		return( status );
	else	return(0);
}

#ifdef	ABAL32A
void	liberate_style_file(struct element_file * fptr)
{
	struct	element_class * cptr;

	if ( fptr->name ) {
		liberate( fptr->name );
		fptr->name = (char *) 0;
		}

	while ((cptr = fptr->first) != (struct element_class*) 0) {
		fptr->first = cptr->next;
		liberate( cptr );
		}
	liberate( fptr );
	return;
}

struct	element_file * style_file_class(struct element_file * fptr, struct element_style * sptr )
{
	struct	element_class * cptr;

	/* ensure unique occurance of class in file */
	/* ---------------------------------------- */
	for (	cptr=fptr->first;
		cptr != (struct	element_class *) 0;
		cptr = cptr->next ) {
		if (!( cptr->style ))
			continue;
		else if (!( cptr->style->name ))
			continue;
		else if (!( strcmp(cptr->style->name, sptr->name ) ))
			return(fptr);
		}

	/* add class occurance to this style file */
	/* -------------------------------------- */
	if (!( cptr = allocate( sizeof( struct element_class ) ) ))
		return( fptr );
	else	{
		cptr->style= (struct element_style *) 0;
		cptr->next = cptr->previous = (struct element_class *) 0;
		if (!( cptr->previous = fptr->last ))
			fptr->first = cptr;
		else	fptr->last->next = cptr;
		fptr->last = cptr;
		cptr->style = sptr;
		return( fptr );
		}
}

/*	----------------------------------------------------------	*/
/*	s t y l e _ f i l e _ l i n k a g e ( mptr, sptr, number )	*/
/*	----------------------------------------------------------	*/
/*	This function is called during stylesheet loading to check 	*/
/*	existance of the named file MPTR and to add the style 		*/
/*	class SPTR to the list of classes.				*/
/*	Style files are of unique occurance as are class records.	*/
/*	----------------------------------------------------------	*/

struct	element_file * style_file_linkage( char * mptr, struct element_style * sptr, int number )
{
	struct	element_file * fptr;
	struct	element_class* cptr;

	int	h;
	if (!( mptr ))
		return((struct element_file *) 0);
	else	h = style_element_hash( mptr );

	/* ensure unique occurance of style file */
	/* ------------------------------------- */
	for (	fptr=FileList;
		fptr != (struct element_file *) 0;
		fptr = fptr->next ) {
		if (!( fptr->name ))
			continue;
		else if ( fptr->hash != h )
			continue;
		else if (!( strcmp( fptr->name, mptr ) )) {
			if (!( number )) {
				/* remove style class records for first usage */
				/* ------------------------------------------ */
				while ((cptr = fptr->first) != (struct element_class*) 0) {
					fptr->first = cptr->next;
					liberate( cptr );
					}
				fptr->first = 
				fptr->last  = (struct element_class *) 0;
				}
			/* add this style class record */
			/* --------------------------- */
			return( style_file_class( fptr, sptr ) );
			}
		}

	/* add new style file */
	/* ------------------ */
	if (!( fptr = allocate( sizeof( struct element_file )  ) ))
		return( fptr );
	else if (!( fptr->name = allocate_string( mptr ))) {
		liberate( fptr );
		return( (struct element_file *) 0);
		}
	else	{
		fptr->hash = h;
		fptr->first = 
		fptr->last  = (struct element_class *) 0;
		fptr->previous = (struct element_file *) 0;
		if ((fptr->next = FileList) != (struct element_file *) 0)
			FileList->previous = fptr;
		FileList    = fptr;
		/* add this style class record */
		/* --------------------------- */
		return( style_file_class(fptr,sptr) );
		}
}

public	int	set_style_domain( char * sptr )
{
	if ( StyleDomain ) {
		StyleDomain = liberate( StyleDomain );
		}
	if (( sptr  ) && ( *sptr ))
		StyleDomain = allocate_string( sptr );
	return 0;
}

public	char *	default_style_domain()
{
	return((char *) 0);
}

private	int	style_domain()
{
	char *	tptr;
	if (!( tptr = style_token()))
		return(style_error(_style_expected_token));
	else if (!( strcmp(tptr,"null" ))) 
		set_style_domain( (char *) 0 );
	else if (!( strcmp(tptr,"default" ))) 
		set_style_domain( default_style_domain() );
	else	set_style_domain( tptr );
	if (!( is_style_semi_colon() ))
		return(style_error(_style_expected_semicolon));
	else	return(0);
}

private	int	style_define()
{
	char *	tptr;
	char *	nptr;
	char *	vptr;
	if (!( tptr = style_token()))
		return(style_error(_style_expected_token));
	else if (!( nptr = allocate_string( tptr )))
		return(style_error(_allocation_failure));
	else if (!( tptr = style_token())) {
		liberate( nptr );
		return(style_error(_style_expected_token));
		}
	else if ( is_style_keyword( tptr ) == _keyword_url) {
		if (!( tptr = style_url_name() )) {
			liberate( nptr );
			return(style_error(_style_expected_url));
			}
		}
	if (!( vptr = allocate_string( tptr ))) {
		liberate( nptr );
		return(style_error(_allocation_failure));
		}
	else if (!( add_style_define( nptr, vptr ) )) {
		liberate( nptr );
		liberate( vptr );
		return(style_error(_allocation_failure));
		}
	else if (!( is_style_semi_colon() ))
		return(style_error(_style_expected_semicolon));
	else	return(0);
}

#endif

public	int	load_visual_style(char * bptr, int blen)
{
	int				number=0;
	int				holdecho;
	int				status;
	char 			*	mptr;
	struct	element_style	*	sptr=(struct element_style *) 0;
	char			*	tptr;
	char			*	eptr;

	if (!(mptr = allocate( blen + 2 )))
		return(_allocation_failure);
	else	{
		memcpy(mptr,bptr,blen);
		*(mptr+blen) = 0;
		}

#ifdef WIN32
	{
	/* meme algo que xmlform.c */
	char buf[_MAX_PATH];
	if (!( status = find_fileinlistpath_byexa( get_system_stylepath(), mptr, buf) ))
		status = find_style_byexa( mptr, buf);
	liberate(mptr);
	if (!(status))
		return(style_error(_file_not_found));
	else if (!(mptr = allocate_string(buf)))
		return(style_error(_allocation_failure));
	}
#endif

	if ((status = initialise_style_file_parser( mptr )) != 0) {
		liberate(mptr);
		return( style_error(status) );
		}

	/* collect class name tokens */
	/* ------------------------- */
	holdecho = style_echo; 
#ifdef WIN32
	if ((eptr = confgetenv("ECHOSTYLE")) != (char *) 0)
#else
	if ((eptr = getenv("ECHOSTYLE")) != (char *) 0)
#endif
		style_echo = *eptr;
	while  ((tptr = style_token()) != (char*) 0) {
		if (!( *tptr )) 
			break;
		else if (!( strcmp(tptr,"@import" ))) {
			if ((status = import_style()) != 0)
				break;
			else	continue;
			}
#ifdef	ABAL32A
		else if (!( strcmp(tptr,"@domain" ))) {
			if ((status = style_domain()) != 0)
				break;
			else	continue;
			}
		else if (!( strcmp(tptr,"@define" ))) {
			if ((status = style_define()) != 0)
				break;
			else	continue;
			}
#endif
		else if (!(sptr = overload_style(tptr))) {
			status = _allocation_failure;
			break;
			}
		else if (!( is_style_open_brace() )) {
			status = _style_expected_left_brace;;
			break;
			}
#ifdef	ABAL32A
		else if (!(sptr->filename = allocate_string( mptr ))) {
			status = _allocation_failure;
			break;
			}
		else if (!( sptr->owner = style_file_linkage( mptr, sptr, number++ ) )) {
			status = _allocation_failure;
			break;
			}
		else if ( StyleContext )
			sptr->fileline = StyleContext->linecounter;
#endif
		while ((tptr = style_token()) != (char*) 0)
			if ((status = translate_style( sptr, tptr )) != 0)
				break;
		if ( status != _end_of_style )
			break;
		}
	liberate( mptr );
	terminate_style_parser();
	style_echo = holdecho;

	if ((status) && ( status != _end_of_style ))
		style_error( status );
	return( status );
}


static	int	apply_style( int x, int y, int w , int h ,struct element_style * sptr, char * mptr, int mlen )
{
	char 			* 	copystring=(char *) 0;
	int				status=0;
	struct	style_object		context;
	context.lmi = x_event( 203); 
	context.tmi = x_event( 200);
	context.gfh = x_event( 204); 
	context.gfw = x_event( 205);
	context.vph = x_event( 208);
	context.vpw = x_event( 209);
	context.atx = x;
	context.aty = y;
	context.nbx = w;
	context.nby = h;
	if (!( sptr->item )) {
		context.message = mptr;
		context.length  = mlen;
		}
	else if (!( copystring = allocate( mlen+1 ) ))
		return(0);
	else	{
		memcpy( copystring, mptr, mlen );
		*(copystring+mlen) = 0;
		if (!( context.message = selection_item((sptr->item-1),copystring )))
			context.message = allocate_string( "\0" );
		context.length  = strlen( context.message );
		}
	status = apply_visual_style( sptr, &context );
	if ( copystring ) {
		liberate( copystring );
		liberate( context.message );
		}
	return( status );
}

int	visual_element( int x, int y, int w , int h , char * tptr, char * mptr, int mlen )
{
	int				status=0;
	int				item=0;
	int				items=0;
	char			*	vptr;
	char			*	aptr;
	char			*	cptr;
	struct	element_style	*	sptr=(struct element_style *) 0;
#ifdef	_TRACE_STYLE
	printf("visual_element(%u,%u,%u,%u, %s )\r\n",x,y,w,h,tptr);
#endif
	if (!( sptr = resolve_style_class( tptr ) ))
		return( _file_not_found );
	else if (!(aptr = sptr->alias))
		return( apply_style( x,y,w,h,sptr, mptr, mlen ) );
	else if (!( cptr = allocate_string(aptr)))
		return(27);
	else	{
		while ((vptr = selection_item(item++,cptr )) != (char *) 0) {
			items++;
			if (!( strcmp( vptr, "this" ))) {
				if ((status = apply_style( x,y,w,h,sptr, mptr, mlen )) != 0) {
					liberate( cptr );
					liberate( vptr );
					return(status);
					}
				}
			else if ((status = visual_element(x,y,w,h,vptr,mptr,mlen)) != 0 ) {
				liberate( cptr );
				liberate( vptr );
				return(78);
				}
			liberate( vptr );
			}
		liberate( cptr );
		if (!( items ))
			return(118);
		else	return(0);
		}
}	

public	void	detect_default_style()
{
	DefaultStyle[visual_window_frame]	= (resolve_style_class( "windowframe" ) ? 1 : 0 );
	DefaultStyle[visual_button_frame]	= (resolve_style_class( "buttonframe" ) ? 1 : 0 );
	DefaultStyle[visual_page_frame]		= (resolve_style_class( "pageframe" ) ? 1 : 0 );
	DefaultStyle[visual_check_frame]	= (resolve_style_class( "checkframe" ) ? 1 : 0 );
	DefaultStyle[visual_radio_frame]	= (resolve_style_class( "radioframe" ) ? 1 : 0 );
	DefaultStyle[visual_radio_frame]	= (resolve_style_class( "radioframe" ) ? 1 : 0 );
	DefaultStyle[visual_switch_frame]	= (resolve_style_class( "switchframe" ) ? 1 : 0 );
	DefaultStyle[visual_table_frame]	= (resolve_style_class( "tableframe" ) ? 1 : 0 );
	DefaultStyle[visual_progress_frame]	= (resolve_style_class( "progressframe" ) ? 1 : 0 );
	DefaultStyle[visual_outset_frame]	= (resolve_style_class( "outsetframe" ) ? 1 : 0 );
	DefaultStyle[visual_inset_frame]	= (resolve_style_class( "insetframe" ) ? 1 : 0 );
	DefaultStyle[visual_groove_frame]	= (resolve_style_class( "grooveframe" ) ? 1 : 0 );
	DefaultStyle[visual_ridge_frame]	= (resolve_style_class( "ridgeframe" ) ? 1 : 0 );
	DefaultStyle[visual_edit_frame]		= (resolve_style_class( "editframe" ) ? 1 : 0 );
	DefaultStyle[visual_form_frame]		= (resolve_style_class( "formframe" ) ? 1 : 0 );
	DefaultStyle[visual_select_frame]	= (resolve_style_class( "selectframe" ) ? 1 : 0 );
	DefaultStyle[visual_select_frameup]	= (resolve_style_class( "selectframeup" ) ? 1 : 0 );
	DefaultStyle[visual_select_framedown]	= (resolve_style_class( "selectframedown" ) ? 1 : 0 );
	DefaultStyle[visual_select_framebtn]	= (resolve_style_class( "selectframebtn" ) ? 1 : 0 );
	DefaultStyle[visual_select_framescroll]	= (resolve_style_class( "selectframescroll" ) ? 1 : 0 );
	DefaultStyle[visual_image_frame]	= (resolve_style_class( "imageframe" ) ? 1 : 0 );
	DefaultStyle[visual_vscroll_frame]	= (resolve_style_class( "vscrollframe" ) ? 1 : 0 );
	DefaultStyle[visual_hscroll_frame]	= (resolve_style_class( "hscrollframe" ) ? 1 : 0 );
	return;

}

public	void	initialise_style()
{
	int	i;
	ActiveStyle=(struct element_style*) 0;
#ifdef	ABAL32A
	FileList=(struct element_file *) 0;
	StyleDomain = (char *) 0;
#endif
	ClassList=(struct element_style*) 0;
	for (i=0; i < _MAX_STYLE; i++) {
		StyleHeap[i] = (struct element_style *) 0;
		}
	for ( i=0; i < max_default_style; i++ )
		DefaultStyle[i] = 0;
	return;
}

public	void	terminate_style()
{
	int	i;
	struct	element_style *	sptr;
#ifdef	ABAL32A
	struct	element_file  *	fptr;
#endif
	for (i=0; i < _MAX_STYLE; i++) {
		if (!( StyleHeap[i] ))
			continue;
		else 	drop_style(i);
		}
#ifdef	ABAL32A
	while ((fptr = FileList) != (struct element_file*) 0) {
		FileList = fptr->next;
		liberate_style_file( fptr );
		}
#endif
	while ((sptr = ClassList) != (struct element_style*) 0) {
		ClassList = sptr->next;
		liberate_style( sptr );
		}
#ifdef	ABAL32A
	if ( StyleDomain )
		StyleDomain = liberate( StyleDomain );
#endif
	initialise_style();
	return;
}

public	int	use_default_style( int item )
{
	if (!( use_overload_style ))
		return(0);
	if ( item < max_default_style )
		if ( DefaultStyle[ item ] )
			return(1);
	return(0);
}

private	void	release_visual_style( struct element_style * sptr )
{
	struct	element_file * fptr;
	struct	element_class * cptr;
	if (!( sptr ))
		return;
	else if (!( sptr->name ))
		return;
	if ( sptr->next )
		sptr->next->previous = sptr->previous;
	if (!( sptr->previous ))
		ClassList = sptr->next;
	else	sptr->previous->next = sptr->next;
#ifdef	ABAL32A
	if ((fptr = sptr->owner) != (struct element_file *) 0) {
		for (	cptr=fptr->first;
			cptr != (struct element_class*) 0;
			cptr = cptr->next ) {
			if (!( cptr->style ))
				continue;
			else if (!( cptr->style->name ))
				continue;
			else if (!( wildcomp( sptr->name, cptr->style->name ) )) {
				cptr->style = (struct element_style *) 0;
				if (!( cptr->next ))
					fptr->last = cptr->previous;
				else 	cptr->next->previous = cptr->previous;
				if (!( cptr->previous ))
					fptr->first = cptr->next;
				else	cptr->previous->next = cptr->next;
				liberate( cptr );
				break;
				}
			}
		}
#endif
	liberate_style( sptr );
	return;
}

public	int	drop_visual_style(char * bptr, int blen )
{
	struct	element_style *	sptr;
	struct	element_style *	nptr;
	struct	element_style *	pptr=(struct element_style *) 0;
	if (( *bptr == '*' ) && ( blen == 1 )) {
		terminate_style();
		return(0);
		}
	else if (!( blen )) {
		terminate_style();
		return(0);
		}
	else	{
		sptr = ClassList;
		while ( sptr != (struct element_style*) 0 ) {
			nptr = sptr->next;
			if (!( wildcomp(sptr->name,bptr) )) {
				release_visual_style( sptr );
				}
			sptr = nptr;
			}
		return(0);
		}
}
#ifdef	ABAL32A
public	int	drop_style_file( char * nptr, int nlen )
{
	int	elements=0;
	struct	element_class * kptr=(struct element_class *) 0;
	struct	element_class * cptr;
	struct	element_style * sptr;
	struct	element_file * 	fptr;
	if (!( nptr ))
		return(elements);
	else if (!( nlen ))
		return(elements);
	else if (!( fptr = resolve_stylefile_name( nptr ) ))
		return(elements);
	else	{
		for (	cptr=fptr->first;
			cptr != (struct element_class *) 0;
			cptr = cptr->next ) {
			if (!( sptr = cptr->style ))
				continue;
			else	{
				drop_visual_style( sptr->name, strlen( sptr->name ) );
				elements++;
				}
			}			
		while ((cptr = fptr->first) != (struct element_class *) 0) {
			fptr->first = cptr->next;
			liberate( cptr );
			}
		if ( fptr->next )
			fptr->next->previous = fptr->previous;
		if (!( fptr->previous ))
			FileList = fptr->next;
		else 	fptr->previous->next = fptr->next;
		liberate( fptr );
		return( elements );
		}

}
#endif
public	int	style_inhibit_position_home( struct element_style * sptr )
{
	if (!( sptr ))
		return(0);
	else if ( sptr->cellposition.type != _keyword_home )
		return(0);
	else	{
		sptr->cellposition.type = _keyword_auto;
		sptr->cellwidth.type    = _keyword_auto;
		sptr->cellheight.type   = _keyword_auto;
		return( _keyword_home );
		}
}

public	void	style_permit_position_home( struct element_style * sptr, int emode )
{
	if (!( sptr ))
		return;
	else if ( emode != _keyword_home )
		return;
	else	{
		sptr->cellposition.type = _keyword_home;
		sptr->cellwidth.type    = _PERCENT_DIMENSION;
		sptr->cellheight.type   = _PERCENT_DIMENSION;
		return;
		}
}

public	void	calculate_style_derivations()
{
	struct	element_style * rptr=(struct element_style *) 0;
	struct	element_style * sptr;
	struct	element_style * dptr;

	for ( 	sptr=ClassList;
		sptr !=(struct element_style *) 0;
		sptr = sptr->next ) {
		sptr->derivations= 0;
		for ( 	dptr=ClassList;
			dptr !=(struct element_style *) 0;
			dptr = dptr->next ) {
			if (!( dptr->basename ))
				continue;
			else if (!( strcmp( dptr->basename, sptr->name ) ))
				sptr->derivations++;
			}
		if (!( rptr ))
			rptr = sptr;
		else  if ( rptr->derivations < sptr->derivations )
			rptr = sptr;
		}
	return;
}

struct	element_style * first_style_class()
{
	return( ClassList );
}

#include "genstyle.c"

#endif	/* _vstyle_c */
	/* --------- */



