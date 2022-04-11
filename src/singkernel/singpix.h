#ifndef	_SINGPIX_H
#define	_SINGPIX_H

#ifndef WIN32
#include "stdtypes.h"
#endif

int 	xorzone(int atx,int aty, int nbx, int nby, int colour );
int 	filzone(int atx,int aty, int nbx, int nby, int colour );
int 	xfilzone(int atx,int aty, int nbx, int nby, int colour );
int	putzone(int atx,int aty, int nbx, int nby, char * buffer );
int	getzone(int atx,int aty, int nbx, int nby, char * buffer );

#endif	/* _SING_PIX_H */

