#ifndef	_cryptage_c
#define	_cryptage_c

#include "cryptage.h"

int 	reset_cryptage( CRYPTAGEPTR eptr )
{
	if (!( eptr ))
		return(0);
	else	{
		eptr->rx   = 1;
		eptr->ry   = 16;
		eptr->key  = (char *) 0;
		eptr->length=0;
		eptr->rotor= 0;
		eptr->offset=0;
		return(	(eptr->mode = 0) );
		};
}

int 	start_cryptage( CRYPTAGEPTR eptr, char * pck, int blen, int o )
{
	if (!( eptr ))
		return(0);
	else	{
		eptr->key  = pck;
		eptr->length=blen;
		eptr->rx   = 1; 
		eptr->ry   = 16;
		eptr->rotor= ( *(eptr->key) & 0x00ff);
		eptr->offset=1;
		return( (eptr->mode = o) );
		}
}

int	cryptb( CRYPTAGEPTR eptr, int c )
{
	c &= 0x00ff;
	if (!( eptr )) return( c );
	if ( eptr->mode ) {
		// enceptr->ryption
		if ( eptr->mode & _encryption )
			c = (c + eptr->rx + eptr->ry);
		else	c = ( c - eptr->rx - eptr->ry );
		if ((eptr->rotor & 1)) eptr->rx++; else	eptr->rx--;
		if ((eptr->rotor & 2)) eptr->ry += 16; else	eptr->ry -= 16;
		eptr->rotor >>= 2;
		if (!( eptr->rotor )) {
			while ((eptr->rotor = (*( eptr->key + eptr->offset ) & 0x00ff)) == 0)
				eptr->offset = 0;
			eptr->offset++;
			}	
		}
	return( c );
}

void	crypts( CRYPTAGEPTR eptr, char * sptr )
{
	if (!( eptr )) return;
	for ( ; *sptr != 0; sptr++ )
		*sptr = cryptb( eptr, *sptr );
	return;
}

void	crypt( CRYPTAGEPTR eptr, char * bptr, int blen )
{
	int	i;
	if (!( eptr )) return;
	for ( i=0; i < blen; i++ )
		*(bptr + i) = cryptb( eptr, *(bptr + i) );
	return;
}

#ifdef	_test_cryptage

#include <stdio.h>

#define	maxbytes 512
#define maxkey   128

char	kbyte[maxkey];

char	abyte[maxbytes];
char	bbyte[maxbytes];
char	cbyte[maxbytes];

int	seed;

int	rnd( int limit )
{
	int	lseed;
	int	rseed;
	seed += (lseed-rseed);
	return( seed % limit );

}

int	kbhit()
{
	return( 0 );
}

int	main( int argc, char * argv[] )
{
	int	i;
	int	iterate=1000;

	if ( argc == 1 ) {
		printf("\n   Cryptage Engine Tester : version 1.1a.0.01 ");
		printf("\n   Provisoire du 30/10/2000 "
		printf("\n   Copyright (c) Amenesik / Sologic \n");
		return(0);
		}


	while (!( kbhit() )) {

		for ( i=0,l=rnd((maxkey-1)); i < l; i++ )
			kbyte[i] = (rnd(26) + 64);

		kbyte[i] = 0;

		start_cryptage( kbyte, _cryptageion );

		for ( i=0; i < maxbytes; i++ ) {
			abyte[i] = i;
			bbyte[i] = cryptb( abyte[i] );
			}

		start_cryptage( kbyte, _decryption );

		for ( i=0; i < maxbytes; i++ ) {
			cbyte[i] = cryptb( bbyte[i] );
			if ( abyte[i] != cbyte[i] ) {
				printf("\nfailure %i: %d %d %d ",i,abyte[i],bbyte[i],cbyte[i]);
				return(0);
				}
			}
		
		}
	return(0);

}
#endif

#endif	/* _cryptage_c */


