#ifndef	_singfmf_c
#define	_singfmf_c

/* --------------------------- */
/* file included by singform.c */
/* --------------------------- */

#define	_MAX_FONT_LABELS 16

private	int	font_labels_ready=0;

public	char *	FontLabels[_MAX_FONT_LABELS+1] = {
	(char *) 0,	(char *) 0,	(char *) 0,	(char *) 0,
	(char *) 0,	(char *) 0,	(char *) 0,	(char *) 0,
	(char *) 0,	(char *) 0,	(char *) 0,	(char *) 0,
	(char *) 0,	(char *) 0,	(char *) 0,	(char *) 0,
	(char *) 0
	};

private	int	store_font_label( int i, char * v)
{
	if (i < 1) 	
		return(102);
	else if ( i > _MAX_FONT_LABELS)
		return(103);
	else	i--;
	if ( FontLabels[i] ) {
		FontLabels[i] = liberate( FontLabels[i] );
		}
	if (( v )
	&&  (!( FontLabels[i] = allocate_string( v ) )))
		return(27);
	else	return(0);
}

public	int	initialise_font_labels()
{
	int	status;
	int	i;
	char 	buffer[64];
	if (!( font_labels_ready )) {
		if ((status = store_font_label(1,"edit")) != 0)		{ return(status); }
		if ((status = store_font_label(2,"proportional")) != 0)	{ return(status); }
		if ((status = store_font_label(3,"medium label")) != 0)	{ return(status); }
		if ((status = store_font_label(4,"large label")) != 0)	{ return(status); }
		if ((status = store_font_label(5,"medium title")) != 0)	{ return(status); }
		if ((status = store_font_label(6,"large title")) != 0)	{ return(status); }
		if ((status = store_font_label(7,"medium edit")) != 0)	{ return(status); }
		if ((status = store_font_label(8,"smallfont")) != 0)	{ return(status); }
		if ((status = store_font_label(9,"large edit")) != 0)	{ return(status); }
		for ( i=9; i < _MAX_FONT_LABELS; i++ ) {
			sprintf(buffer,"Font %02.2u",i+1);
			if ((status = store_font_label((i+1),buffer)) != 0) { return( status ); }
			}
		}
	font_labels_ready = 1;
	return(0);
}

public	void	liberate_font_labels()
{
	int	i;
	for (i=0; i < _MAX_FONT_LABELS; i++ )
		store_font_label((i+1),(char *) 0);
	font_labels_ready = 0;
	return;
}
	
public	char *	GetTextFontList()
{
	char	*	rptr=(char *) 0;
	char	*	wptr=(char *) 0;
	char	*	nptr=(char *) 0;
	int	nlen;
	int	i;
	if ( Context.FontLabelList )
		return( Context.FontLabelList );
	else if (initialise_font_labels() != 0 )
		return( TEXTFONTLIST );
	for (i=0; i < _MAX_FONT_LABELS; i++ ) {

		if (!( nptr = FontLabels[i] ))
			nlen=0;
		else	nlen=strlen(nptr);

		if ( rptr ) {
			if (!( wptr = allocate(strlen(wptr)+nlen+16) ))
				break;
			else  	{ 
				if (nlen) sprintf(wptr,"%s|%s",rptr,nptr);	
				else strcpy(wptr,rptr); 
				};
			}
		else	{
			if (!( wptr = allocate(nlen+2) ))
				break;
			else	sprintf(wptr,"%s",(nptr?nptr:"\0"));
			}
		if ( rptr )
			liberate( rptr );
		rptr = wptr;
		}
	return( ((Context.FontLabelList=rptr) ? Context.FontLabelList : TEXTFONTLIST  ) );
}

private	char	FontVectorBuffer[512];

public	char *	GetFontVector( char * nfic, int i )
{
	char	*	nptr;
	if ( i < 1 )
		return( nfic );
	else if ( i > _MAX_FONT_LABELS )
		return( nfic );
	else if (!( nptr = FontLabels[(i-1)] ))
		return( nfic );
	else	{
		sprintf(FontVectorBuffer,"%s[%u:%s",nfic,i,nptr);
		return( FontVectorBuffer );
		}
}

public	char *	UseFontVector( char * nfic )
{
	int	i;
	char *	nptr;
	if (( nptr = nfic ) != (char *) 0) {
		while ( *nptr ) {
	 		if ( *nptr == '[' )
				break;
			else	nptr++;
			}
		if ( *nptr ) {
			*(nptr++) = 0; i = 0;
			while (( *nptr >= '0' ) && ( *nptr <= '9' )) {
				i = ((i * 10) + ( *(nptr++) - '0' ));
				}
			if ( *nptr == ':' ) {
				store_font_label(i,++nptr);				
				}
			}
		}
	return( nfic );
}


public	int	GetFontLabel(int i, char * rptr, int rlen)
{
	int	x;
	char *	nptr;
	char 	buffer[64];

	sprintf(buffer,"Font %u",i);
	memset(rptr,' ',rlen);
	for (x=0; x < rlen; x++ ) {
 		if (!( buffer[x] ))
			break;
		else	*(rptr+x) = buffer[x];
		}

	if (i < 1) 	
		return(102);
	else if ( i > _MAX_FONT_LABELS)
		return(103);

	if (!( Context.FontLabelList ))
		if (initialise_font_labels() != 0 )
			return( 27 );

	if ((nptr = FontLabels[(i-1)]) != (char *) 0 ) {
		memset(rptr,' ',rlen);
		for (x=0; x < rlen; x++ ) {
	 		if (!( *(nptr+x) ))
				break;
			else	*(rptr+x) = *(nptr+x);
			}
		return(0);
		}
	else	return( 118 );
}


public	int	SetFontLabel(int n, char * v,int l )
{
	char buffer[64];
	int	x;
	int	nb;
	for (nb=0,x=0; x < l; x++ ) {
		if ( *(v+x) != ' ' )
			nb = (x+1);
		}
	for (x=0; x < nb; x++ )
		buffer[x] = *(v+x);
	buffer[x] = 0;		
	if ( Context.FontLabelList ) { 
		Context.FontLabelList = liberate( Context.FontLabelList );
		}
	return(	store_font_label(n,buffer) );
}

	
public	char *	GetFontFileList()
{
	int	nlen=0;
	int	i;
	char	*	rptr=(char *) 0;
	char	*	wptr=(char *) 0;
	char	*	nptr=(char *) 0;
	
	if ( Context.FontList ) {
		liberate( Context.FontList );
		Context.FontList = (char *) 0;
		}
	for (i=0; i < 256; i++ ) {
		if (!( nptr = guifontname(i+1) ))
			nlen=0;
		else	nlen=strlen(nptr);
		if ( rptr ) {
			if (!( wptr = allocate(strlen(wptr)+nlen+16) ))
				break;
			else  	{ 
				if (nlen) sprintf(wptr,"%s|%s",rptr,nptr);	
				else strcpy(wptr,rptr); 
				};
			}
		else	{
			if (!( wptr = allocate(nlen+2) ))
				break;
			else	sprintf(wptr,"%s",(nptr?nptr:"\0"));
			}
		if ( rptr )
			liberate( rptr );
		rptr = wptr;
		}
	return( ((Context.FontList=rptr) ? Context.FontList : "\0" ) );
}


#endif	/* _singfmf_c */
	/* ---------- */

