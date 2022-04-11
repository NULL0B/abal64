#ifndef	_abalword_c
#define	_abalword_c

#define	SIZE_INT16	(sizeof( short int ))

private	int	GetInt16( char * bptr )
{
	int	v;
	v = (((*(bptr) & 0x00FF) << 8) | (*(bptr+1) & 0x00FF));
	return(v);
}

private	void	PutInt16( char * bptr, int v  )
{
	*(bptr++) = (( v & 0xFF00) >> 8);
	*(bptr++) = ( v & 0x00FF);
	return;
}

#ifdef	ABAL32
#define	SIZE_INT32	(sizeof( long int ))
private	long	GetInt32( char * bptr )
{
	long	v;
	v = ((GetInt16(bptr) & 0xFFFF) << 16);
	bptr += SIZE_INT16;
	v |= (GetInt16(bptr) & 0xFFFF);
	return( v );
}

private	void	PutInt32( char * bptr, long v )
{
	PutInt16( bptr, ((v & 0xFFFF0000) >> 16));
	bptr += SIZE_INT16;
	PutInt16( bptr, (v & 0xFFFF));
	return;
}
#endif

#ifdef	ABAL64
#define	SIZE_INT64	(sizeof( long long int ))
private	long	GetInt64( char * bptr )
{
	long	v;
	v = ((GetInt32(bptr) & 0xFFFF) << 16);
	bptr += SIZE_INT32;
	v |= (GetInt32(bptr) & 0xFFFF);
	return( v );
}

private	void	PutInt64( char * bptr, long long v )
{
	PutInt32( bptr, ((v & 0xFFFF0000) >> 16));
	bptr += SIZE_INT32;
	PutInt32( bptr, (v & 0xFFFF));
	return;
}
#endif

#endif	/* _abalword_c */

