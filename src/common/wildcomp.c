#include "stdtypes.h"

WORD	wildcomp( tptr , wptr )
BPTR	tptr;
BPTR	wptr;
{
	WORD	wlen,tlen;

	wlen = strlen(wptr); tlen = strlen(tptr);

	while (( tlen > 0 ) && (wlen > 0)) {

		switch ( *wptr ) {
			case '*' : if ( wildcomp( tptr , (wptr + 1)) == 0 ) {
					return(0);
					}
				   tptr++; tlen--;
				   continue; 
			default  : if ( *tptr != *wptr ) { return(0xFFFF); }
			case '?' : wptr++; tptr++; wlen--; tlen--; continue;
			}
		}
	if (( tlen == 0 ) && ( wlen == 0 )) { return(0); }
	if ( tlen == 0 ) {
		while ( wlen > 0 ) {
			if (( *wptr != '*' ) && ( *wptr != '?' )) { return(0xFFFF); }
			wlen--; wptr++;
			}
		return(0);
		}
	if (( wlen == 0 ) && ( *(wptr - 1) == '*')) { return(0); }
	return(0xFFFF);

}
