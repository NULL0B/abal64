#ifndef	_SING_TYPE_C
#define _SING_TYPE_C

static int ungotc=-1;

void	unget_byte(int c)
{
	ungotc = c;
	return;
}

int	get_byte(FILE * h)
{
	int	c;
	if ((c = ungotc) != -1)
		ungotc = -1;
	else 	c = fgetc(h);
	return((c & 0xFF));
}

int	get_word(FILE * h)
{
	int	r=0;
	r = get_byte(h);
	r |=  (get_byte(h) << 8);
	return(r);
}

char *	get_string(FILE * h)
{
	char *	mptr;
	int	i=0;
	int	n;
	char *	sptr;
	char * allocate_string( char * );

	if (!(sptr = Context.string_buffer ))
		if (!(sptr = (Context.string_buffer = allocate((Context.string_buffer_length = 8192)))))
			return( sptr );

	while ((*(sptr+i) = get_byte(h)) != 0) {
		if (*( sptr + i) == '\n' ) {
			/* whoops */
			*(sptr+i) = 0;
			break;
			}
		i++;
		if ( i < Context.string_buffer_length )
			continue;
		else if (!( mptr = (Context.string_buffer = allocate((Context.string_buffer_length+8192))))) {
			Context.string_buffer = sptr;
			i = 0;
			break;
			}
		else	{
			memcpy(mptr, sptr, i);
			liberate( sptr );
			sptr = mptr;
			Context.string_buffer_length += 8192;
			}
		}
							
	if (!( i ))
		return( (char *) 0 );
	else	return( allocate_string( sptr ) );
}

int	get_buffer(FILE * h,char * bptr, int blen)
{
	int	i;
	int	x;
	for (i=0; i < 1024; i++ )
		if (!( workbuffer[i] = get_byte(h) ))
			break;
	workbuffer[i] = 0;

	if ((!( bptr )) || (!( blen )))
		return(0);

	for ( x=0; x < i; x++ ) {
		if ( x < blen )
			*(bptr+x) = workbuffer[x];
		else	break;
		}
	*(bptr+x)=0;
	return(i);
}

char *	get_string_length(FILE * h,int l)
{
	int	i;
	char	*	sptr;
	for (i=0; i < 1024; i++ )
		if (!( workbuffer[i] = get_byte(h) ))
			break;
	if (!( i ))
		return((char *) 0);
	else if (!( sptr = allocate( l+1 )))
		return(sptr);
	else	{
		for (i=0; i < l; i++ )
			if (!( *(sptr + i) = workbuffer[i] ))
				break;
		*(sptr+l) = 0;
		return( sptr );
		}
}

char *	get_filename(FILE * h)
{
	int	i;
	for (i=0; i < 1024; i++ )
		if (!( workbuffer[i] = get_byte(h) ))
			break;
	if (!( i ))
		return(" \0");
	else	return( allocate_string( workbuffer ) );
}

#endif	/* _SING_TYPE_C */


