#ifndef	_vtype_c
#define	_vtype_c

void	put_byte(FILE * h, int v)
{
	fputc((v & 0x00FF),h);
	return;
}

void	put_word(FILE *h, int v)
{
	put_byte(h, (v & 0x00FF));
	put_byte(h, ((v & 0xFF00) >> 8));
	return;
}
 
void	put_long(FILE *h, long v)
{
	put_word(h, (int)(v & 0x0000FFFFL));
	put_word(h, (int)((v >> 16) & 0x0000FFFFL));
	return;
}
 
void	put_string(FILE *h, char * sptr)
{
	if ( sptr )
		while ( *sptr )
			put_byte( h, *(sptr++) );

	put_byte(h,0);
	return;
}

void	put_block(FILE *h, char * bptr, int blen)
{
	if ( bptr ) 
		fwrite(bptr,blen,1,h);

	return;
}

#endif	/* _vtype_c */
	/* -------- */

