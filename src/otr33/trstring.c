#ifndef	_TRSTRING_C
#define	_TRSTRING_C

#include "trstring.h"

void *	allocate( int );
void *  liberate( void * );
void *  memcpy( void *, void *, int );
void *  memset( void *, int, int );
char *  strcpy( char *, char * );
char *  strcat( char *, char * );

extern int rtl_dieze_memory( void );

#define	STRING		struct _string
#define	STRINGNODE	struct _string_node
#define	STRINGPTR	STRING *
#define	STRINGNODEPTR	STRINGNODE *
#define	WORD		unsigned short
#define	BPTR		unsigned char *
#define	public		
#define	private		static

STRINGNODE	{
	STRING		content;
	WORD		base;
	STRINGNODEPTR 	next;
	};

private	STRINGNODEPTR _StringHeap=(STRINGNODEPTR) 0;	/* Free String Nodes */
private	STRINGNODEPTR _StringList=(STRINGNODEPTR) 0;	/* Occupied Nodes    */
private	BPTR	_StringMemory=(BPTR) 0;			/* Temporary Memory  */
private	WORD	_StringUsage=0;				/* Memory Usage	     */
private	WORD	_StringProtect=0;			/* Memory Protect    */

private	WORD	lendollar( sptr, slen )
	BPTR	sptr;
	WORD	slen;
{
	if ((sptr != (BPTR) 0)
	&&  (slen > 0 )) {
		do	{
			if ( *(sptr + slen - 1) != ' ' )
				break;
			}
		while ((slen = (slen - 1)) > 0 );
		}
	return( slen );
}

private STRINGPTR allocate_string_node(n)
	WORD	  n;
{
	STRINGNODEPTR nptr;
	STRING	    * sptr=(STRINGPTR) 0;
	if ((nptr = _StringHeap) != (STRINGNODEPTR) 0)
		_StringHeap = nptr->next;
	else if ((nptr = (STRINGNODEPTR) allocate( sizeof( STRINGNODE ) )) == (STRINGNODEPTR) 0)
		return( sptr );
	nptr->next = _StringList;
	nptr->base = 0;
	_StringList = nptr;
	sptr = & nptr->content;
	sptr->value  = (BPTR) 0;
	sptr->length = 0;
	if (( _StringMemory == (BPTR) 0)
	&&  ((_StringMemory = (BPTR) allocate( rtl_dieze_memory() )) == (BPTR) 0))
		return( (STRINGPTR) 0);
	else	{
		sptr->value = (_StringMemory + _StringUsage);
		_StringUsage += n;
		sptr->length = n;
		nptr->base   = _StringProtect;
		}
	return( sptr );
}

public 	void		 liberate_string( sptr )
	STRINGPTR sptr;
{
	if ( sptr != (STRINGPTR) 0) {
		if ( sptr->value != (BPTR) 0)
			sptr->value = liberate( sptr->value );
		sptr = liberate( sptr );
		}
	return;
}

public 	STRINGPTR 	allocate_string( n )
	WORD	n;
{
	STRINGPTR sptr;
	if ((sptr = (STRINGPTR) allocate( sizeof( STRING ) )) != (STRINGPTR) 0) {
		sptr->value = (BPTR) 0;
		sptr->length= 0;
		if ((sptr->value = (BPTR) allocate( n )) != (BPTR) 0) {
			sptr->length = n;
			memset(sptr->value,' ',n);
			}
		else	{
			liberate_string( sptr );
			sptr = (STRINGPTR) 0;
			}
		}
	return( sptr );
}

public 	STRINGPTR 	temporary_string( n )
	WORD	n;
{
	STRING	    * sptr=(STRINGPTR) 0;
	if ((sptr = allocate_string_node(n)) != (STRINGPTR) 0) {
		sptr->length = n;
		memset(sptr->value,' ',n);
		}
	return( sptr );
}

public 	void		 copy_string( rptr, sptr )
	STRINGPTR rptr;
	STRINGPTR sptr;
{
	BPTR rvptr;
	BPTR svptr;
	if (( rptr != (STRINGPTR) 0)
	&&  ((rvptr = rptr->value) != (BPTR) 0)) {
		memset((rvptr = rptr->value), ' ', rptr->length );
		if (( sptr != (STRINGPTR) 0)
		&&  ((svptr = sptr->value) != (BPTR) 0))
			memcpy(rvptr,svptr,(rptr->length < sptr->length ? rptr->length : sptr->length));
		}
	return;
}

public 	void		 set_string( rptr, sptr )
	STRINGPTR rptr;
	BPTR 		 sptr;
{
	BPTR 	rvptr;
	WORD	slen;
	if (( rptr != (STRINGPTR) 0)
	&&  ((rvptr = rptr->value) != (BPTR) 0)) {
		memset((rvptr = rptr->value), ' ', rptr->length );
		if (( sptr != (BPTR) 0)
		&&  ((slen = strlen(sptr)) != 0))
			memcpy(rvptr,sptr,(rptr->length < slen ? rptr->length : slen ));
		}
	return;
}


public	WORD		len_string( sptr )
	STRINGPTR	sptr;
{
	if (sptr != (STRINGPTR) 0)
		return( sptr->length );
	else	return( 0 );
}

public	STRINGPTR	left_string( sptr, slen )
	STRINGPTR	sptr;
	WORD		slen;
{
	STRINGPTR	rptr;
	if ((rptr = temporary_string( (slen != 0 ? slen : 256 ) )) != (STRINGPTR) 0)
		if ((sptr != (STRINGPTR) 0)
		&&  (slen != 0))
			memcpy( rptr->value, sptr->value, (slen < sptr->length ? slen : sptr->length) );
	return( rptr );
}

public	void 		build_string( tptr, sptr, slen )
	STRINGPTR	tptr;
	BPTR		sptr;
	WORD		slen;
{
	BPTR		tvptr;
	if (tptr != (STRINGPTR) 0) {
		if ((tptr->value = allocate( slen )) != (BPTR) 0) {
			tptr->length = slen;
			memset((tvptr = tptr->value), ' ', slen );
			for (tvptr=tptr->value; slen > 0; slen-- ) {
				if (!( *sptr ))
					break;
				else	*(tvptr++) = *(sptr++);
				}
			}
		}
	return;
}

public	STRINGPTR	right_string( sptr, slen )
	STRINGPTR	sptr;
	WORD		slen;
{
	STRINGPTR	rptr;
	WORD		offset;
	if ((rptr = temporary_string( (slen != 0 ? slen : 256 ) )) != (STRINGPTR) 0)
		if ((sptr != (STRINGPTR) 0)
		&&  (slen != 0)) {
			if ( slen > sptr->length ) slen = sptr->length;
			offset = (sptr->length - slen );
			memcpy( rptr->value, (sptr->value + offset), slen );
			}
	return( rptr );
}

public	STRINGPTR	sub_string( sptr, offset, slen )
	STRINGPTR	sptr;
	WORD		offset;
	WORD		slen;
{
	STRINGPTR	rptr;
	if ((rptr = temporary_string( (slen != 0 ? slen : 256 ) )) != (STRINGPTR) 0)
		offset--;
		if ((sptr != (STRINGPTR) 0)
		&&  (slen != 0))
			memcpy( rptr->value, (sptr->value+offset), ((slen + offset) > sptr->length ? (sptr->length - offset) : slen) );
	return( rptr );
}

public	STRINGPTR	shl_string( sptr )
	STRINGPTR	sptr;
{
	STRINGPTR	rptr;
	WORD		length;
	BPTR		svptr;
	if (( sptr != (STRINGPTR) 0)
	&&  ((svptr = sptr->value) != (BPTR) 0)
	&&  ((length = sptr->length) != 0)) {
		if ((rptr = temporary_string( sptr->length )) != (STRINGPTR) 0) {
			while ( length ) {
				if ( *svptr != ' ' )
					break;
				else	{
					svptr++;
					length--;
					}
				}
			if ( length )
				memcpy( rptr->value, svptr, length );
			}
		}
	else 	rptr = temporary_string( 1 );

	return( rptr );
}

public	WORD		len$_string( sptr )
	STRINGPTR	sptr;
{
	BPTR		svptr;
	if ( sptr != (STRINGPTR) 0)
		return( lendollar(sptr->value,sptr->length) );
	else	return( 0 );
}

public	STRINGPTR	shr_string( sptr )
	STRINGPTR	sptr;
{
	STRINGPTR	rptr;
	WORD		length;
	BPTR		rvptr;
	if ( sptr != (STRINGPTR) 0) {
		if ((rptr = temporary_string( sptr->length )) != (STRINGPTR) 0) {
			if ((length = len$_string( sptr )) != 0) {
				rvptr = (rptr->value + (sptr->length - length));
				memcpy(rvptr,sptr->value,length);
				}	
			}
		}
	else 	rptr = temporary_string( 1 );

	return( rptr );
}

public	STRINGPTR	inv_string( sptr )
	STRINGPTR	sptr;
{
	STRINGPTR	rptr;
	WORD		length;
	WORD		offset;
	if ( sptr != (STRINGPTR) 0) {
		if ((rptr = temporary_string( sptr->length )) != (STRINGPTR) 0) {
			for ( length = sptr->length, offset = 0; length > 0; length--)
				rptr->value[offset] = sptr->value[length-1];
			}
		}
	else 	rptr = temporary_string( 1 );
	return( rptr );
}

public	STRINGPTR	large_string( sptr )
	STRINGPTR	sptr;
{
	STRINGPTR	rptr;
	WORD		svlen;
	BPTR		svptr;
	BPTR		rvptr;
	if ((  sptr != (STRINGPTR) 0)
	&&  ((svptr = sptr->value) != (BPTR) 0)
	&&  ((svlen = sptr->length) != 0)) {
		if ((rptr = temporary_string( svlen )) != (STRINGPTR) 0) {
			for (rvptr=rptr->value; svlen > 0; rvptr++,svptr++, svlen-- ) {
				if (( *svptr >= 'a' )
				&&  ( *svptr <= 'z' ))
					*rvptr = ((*svptr - 'a') + 'A');
				else	*rvptr = *svptr;
				}
			}
		}
	else	rptr = temporary_string( 1 );
	return( rptr );
}

public	STRINGPTR	small_string( sptr )
	STRINGPTR	sptr;
{
	STRINGPTR	rptr;
	WORD		svlen;
	BPTR		svptr;
	BPTR		rvptr;
	if ((  sptr != (STRINGPTR) 0)
	&&  ((svptr = sptr->value) != (BPTR) 0)
	&&  ((svlen = sptr->length) != 0)) {
		if ((rptr = temporary_string( svlen )) != (STRINGPTR) 0) {
			for (rvptr = rptr->value; svlen > 0; rvptr++, svptr++, svlen-- ) {
				if (( *svptr >= 'A' )
				&&  ( *svptr <= 'Z' ))
					*rvptr = ((*svptr - 'A') + 'a');
				else	*rvptr = *svptr;
				}
			}
		}
	else	rptr = temporary_string( 1 );
	return( rptr );
}

public	void	string_garbage_collector()
{
	STRINGNODEPTR	nptr;
	while ((nptr = _StringList) != (STRINGNODEPTR) 0) {
		if ( nptr->base < _StringProtect )
			break;
		else	{
			_StringList = nptr->next;
			nptr->next = _StringHeap;
			_StringHeap = nptr;
			}
		}
	_StringUsage = _StringProtect;
	return;
}

public	void		iof_prn_string( sptr )
	STRINGPTR	sptr;
{
	BPTR	vptr;
	WORD	vlen;
	if (( sptr != (STRINGPTR) 0)
	&&  ((vptr = sptr->value) != (BPTR) 0)
	&&  ((vlen = sptr->length) != 0))
		for ( ; vlen > 0; vlen-- )
			sysprintf("%c",*(vptr++));
	return;
}

#endif	/* _TRSTRING_C */
	/* ----------- */

