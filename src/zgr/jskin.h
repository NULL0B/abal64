//VAP HEADER 12.12.00 20.46

#ifndef JSKIN_H
#define JSKIN_H
#include"zglobal.h"
WORD	zloadskin( char * nptr );
void	apply_skin( int atcol , int atlin, int nbcol, int nblin, char * sptr, int flags );
void  apply_skinButton( int atcol , int atlin, int nbcol, int nblin, char * sptr, int flags );
WORD  find_skinColor( char * sptr, int flags, int index );

extern char	*	helpskin;

#endif
