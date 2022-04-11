#ifndef	_vstring_c
#define	_vstring_c

#define	MAX_STRING_BUFFER 4096

/* ------------------------------------ */
/* Abal to C string convertor variables */
/* ------------------------------------ */

private	int	vstringlength=0;
private	char *	vstringbuffer=(char *) 0;

public	VOID	allocation_failure( int nb ) { return; } 

/* -------------------------------- */
/* String Buffer Release Mechanisms */
/* -------------------------------- */
VOID	release_vstring_control()
{
	if ( vstringbuffer ) {
		liberate( vstringbuffer );
		}
	vstringbuffer = (char *) 0;
	vstringlength = 0;
	return;
}

private	int	check_vstring_buffer( int slen )
{
	char *	rptr;

	while (1) {
		/* Detect invalid buffer and allocate */
		/* ---------------------------------- */
		if (!( vstringbuffer)) {
			vstringlength = MAX_STRING_BUFFER;
			if ( slen > vstringlength )
				vstringlength = slen;
			if (!( vstringbuffer = allocate( (vstringlength+1) )))
				return( 0 );
			}
		/* Detect string buffer overflow and handle */
		/* ---------------------------------------- */
		if ( slen > vstringlength ) {
			release_vstring_control();
			continue;
			}
		else	return(1);
		}
}

/* --------------------------------- */
/* Convert and Terminate Abal String */
/* --------------------------------- */
BPTR	terminate_string( BPTR sptr, int slen )
{
	int	i;

	if (!( check_vstring_buffer( slen )))
		return( (char *) 0 );

	for (i=0; i < slen; i++ ) {
		if ( i < vstringlength )
			*(vstringbuffer+i) = *(sptr+i);
		else	break;
		}
	*(vstringbuffer+i) = 0;
	return( vstringbuffer );
}

int	clip_string( BPTR sptr, int slen )
{
	int	i;
	int	l;
	for (i=0,l=0; i < slen; i++ ) {
		if (( *(sptr+i) != ' ' )
		&&  ( *(sptr+i) != 0   ))
			l = (i+1);
		}
	*(sptr+l) = 0;
	return(l);
}

BPTR	prefix_string(BPTR pptr, BPTR sptr, int slen )
{
	int	i=0;
	int	j=0;
	if (!( pptr )) {
		if (!( check_vstring_buffer(slen) ))
			return((char *) 0);
		}
	else if (!(check_vstring_buffer(slen+strlen(pptr))))
		return((char *) 0);
	else	{
		for (i=0; *(pptr+i) != 0; i++ )
			*(vstringbuffer+i) = *(pptr+i);
		}

	for (j=0; j < slen; j++ ) {
		if ( (i+j) < vstringlength )
			*(vstringbuffer+(i+j)) = *(sptr+j);
		else	break;
		}
	*(vstringbuffer+(i+j)) = 0;
	return( vstringbuffer );
}

#endif	/* _vstring_c */
	/* ---------- */

