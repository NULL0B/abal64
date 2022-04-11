/*
	Desc : ustdlib.c
	Proj : amake
	Copyright (c) 1993-98 Amenesik / Sologic  

	
	Modifications list :
	17/July/1998  JPH  Restructuration for WAMAKE32
*/

#include "stdtypes.h"


WORD Mstrncmp(sptr, rptr, nTaille)
BPTR	sptr;
BPTR	rptr;
WORD	nTaille;
{
	WORD	i;

	for (i = 0; i != nTaille; i++) {
		if (*sptr < *rptr)
			return MOINS_UN;
		else if (*sptr > *rptr)
			return VRAI;
		sptr++;
		rptr++;
	}
	return FAUX;
}

#ifndef PRL //SAP
WORD	Mstrlen( sptr )
BPTR	sptr;
{
	WORD	length=0;
	while ( *(sptr++) )
		length++;
	return( length );
}
		
void	Mmemset( rptr, c, l )
BPTR	rptr;
BYTE	c;
WORD	l;
{
	BPTR	tptr;
	tptr = rptr;
	for ( ; l != 0; l-- )
		*(tptr++) = c;
}
#endif //SAP

BYTE Mtoupper(c)
BYTE c;
{
	if ((c >= 'a') && (c <= 'z'))
		c &= (BYTE) 0xDF;
	return c;
}

#ifndef PRL	//SAP
BPTR	Mmemcpy( rptr, sptr, l )
BPTR	rptr;
BPTR	sptr;
WORD	l;
{
	BPTR	tptr;
	tptr = rptr;
	for ( ; l != 0; l-- )
		*(tptr++) = *(sptr++);
	return( rptr );
}

BPTR	Mstrcpy( rptr, sptr )
BPTR	rptr;
BPTR	sptr;
{
	BPTR	tptr;
	tptr = rptr;
	while ( *sptr )
		*(tptr++) = *(sptr++);
	*tptr = 0;
	return( tptr );
}

BPTR	Mstrcat( rptr, sptr )
BPTR	rptr;
BPTR	sptr;
{
	BPTR	tptr;
	tptr = rptr;
	while ( *rptr )
		rptr++;
	(void) Mstrcpy( rptr, sptr );
	return( tptr );
}

#endif //SAP

