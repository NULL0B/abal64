public	void 	expand_text_storage( char * source, int bytelen, int pixwid, int pixheight, int fid )
{
	char	*	result;
	char	*	sptr;
	int	ri,si;
	int	fh,fw;
	int	nbcol;
	int	nblin;
	int	c;
	int	l;
	if (!( fid )) fh = 0;
	else	{
		fh = guifontsize(fid);
		fw = (fh & 0x00FF);
		fh >>= 8;
		fh &= 0x00FF;
		}
	if (!( result  = allocate( bytelen + 16 ) ))
		return;
	
	sptr = source;

	for (si=0,nbcol=(pixwid/fw),nblin=(pixheight/fh),l=0; l < nblin; l++) {
		ri = (l * nbcol);
		for (c=0; c < nbcol; c++ )
			if ((si =  *(source++)) == '\n')
				break;
			else	*(result+ri+c) = si;
		for ( ; c < nbcol; c++ )
			*(result+ri+c) = ' ';
		}

	memcpy( source, result, bytelen );

	liberate( result );
	return;
}

public	void 	compress_text_storage( char * source, int bytelen, int pixwid, int pixheight, int fid )
{
	char	*	result;
	char	*	rptr;
	char	*	sptr;
	int	fh,fw;
	int	nbcol;
	int	nblin;
	int	notwhite;
	int	c;
	int	l;
	if (!( fid )) fh = 0;
	else	{
		fh = guifontsize(fid);
		fw = (fh & 0x00FF);
		fh >>= 8;
		fh &= 0x00FF;
		}
	if (!( result  = allocate( bytelen + 16 ) ))
		return;
	
	rptr = result;

	for (	nbcol=(pixwid/fw), nblin=(pixheight/fh),l=0;
		l < nblin;
		l++ ) {
		sptr = (source + (l*nbcol));
		for ( 	notwhite=0,c=0; c < nbcol; c++ ) 
			if (*(source+c) != ' ')
				notwhite=(c+1);

		for ( c=0; c < notwhite; c++)
			*(rptr++) = *(sptr + c);

		*(rptr++) = '\n';

		}
	*(result++) = 0;
	strcpy( source, result );
	liberate( result );
	return;
}

