#ifndef	_GET_DOMAIN_C
#define	_GET_DOMAIN_C
#include <stdio.h>
#include "domain.h"

#define	DOMAIN_FILE "is\\inet\\domain"
#define	DOMAIN_ROOT "."
#define	MAX_BUFFER_SIZE	512
static	char buffer[MAX_BUFFER_SIZE];
static	char far * domainptr=(char *) 0;
char far * get_domain(int mode)
{
	int	i;
	int	l;
	int	h;
	if ((!(mode))
	||  (!(domainptr))) {
		domainptr=(char far *) DOMAIN_ROOT;
		if ((h = open(DOMAIN_FILE,0)) >= 0) {
			if ((l = read( h, buffer, 512 )) > 0) {
				i=0;
				while ( i < l ) {
					switch ( buffer[i] ) {
						case	' '	:
						case	'.'	:
						case	'\t'	:
						case	'\n'	:
						case	'\r'	:
							i++;
							continue;
						case	0x001A	:
							break;
						default		:
							if ( buffer[i] < ' ' )
								buffer[i] = 0x001A;
							break;
						}
					break;
					}
				if ( buffer[i] != 0x001A ) {
					domainptr = & buffer[i];
					while ( i < l ) {
						if ( buffer[i] > ' ' )
							i++;
						else	break;
						}
					buffer[i] = 0;
					}
				
				}
			(void) close(h);
			}
		}
	return( domainptr );
}

#endif	/* _GET_DOMAIN_C */

