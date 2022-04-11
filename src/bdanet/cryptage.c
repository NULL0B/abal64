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
		eptr->key  = 0;
		eptr->rotor= 0;
		return(	(eptr->mode = 0) );
		};
}

int 	start_cryptage( CRYPTAGEPTR eptr, char * pck, int blen, int o )
{
	int	i=0;
	if (!( eptr ))
		return(0);
	else	{
		while (( *pck != 0 ) && ( *pck != ' '))
			i += *(pck++);
		eptr->key  = i;
		eptr->rx   = 1; 
		eptr->ry   = 16;
		eptr->rotor= eptr->key;
		return( (eptr->mode = o) );
		}
}

int	cryptb( CRYPTAGEPTR eptr, int c )
{
	c &= 0x00ff;
	if (!( eptr )) return( c );
	if ( eptr->mode ) {
		if ( eptr->mode == _encryption ) {
			c = (c + eptr->rx + eptr->ry);
			}
		else if ( eptr->mode == _decryption ) {
			c = ( c - eptr->rx - eptr->ry );
			}
		if ((eptr->rotor & 1)) 
			eptr->rx +=1;
		else	eptr->rx -=1;
		if ((eptr->rotor & 2)) 
			eptr->ry += 16; 
		else	eptr->ry -= 16;
		eptr->rotor >>= 2;
		if (!( eptr->rotor ))
			eptr->rotor = eptr->key;
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

void	abal_crypt( CRYPTAGEPTR eptr, char * bptr, int blen )
{
	int	i;
	if (!( eptr )) return;
	for ( i=0; i < blen; i++ )
		*(bptr + i) = cryptb( eptr, *(bptr + i) );
	return;
}

#endif	/* _cryptage_c */



