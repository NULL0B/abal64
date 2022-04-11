#include <stdio.h>
#include "guipixel.h"

void	wait(int n)
{
	return;
}

int	main(int argc, char * argv[] )
{
	int	biosmode=0;
	int	atx;
	int	aty;
	int	nbx;
	int	nby;
	int	maxc;
	int	maxr;
	int	pixel=1;

	printf("\ntwinternet graphics library demonstration\n");
	for ( biosmode=0; biosmode < 5; biosmode++ ) {

		printf("initialisepixel(%u | 256)\n",biosmode);
		switch ( biosmode ) {
			case	0 : printf("characteristcs : %u x %u x 256 colours\n",maxc=320,maxr=200); break;
			case	1 : printf("characteristcs : %u x %u x 256 colours\n",maxc=640,maxr=400); break;
			case	2 : printf("characteristcs : %u x %u x 256 colours\n",maxc=640,maxr=480); break;
			case	3 : printf("characteristcs : %u x %u x 256 colours\n",maxc=800,maxr=600); break;
			case	4 : printf("characteristcs : %u x %u x 256 colours\n",maxc=1024,maxr=786); break;
			case	5 : printf("characteristcs : %u x %u x 256 colours\n",maxc=1200,maxr=1024); break;
			}

		wait(5);

		if ( initialisepixel((biosmode | 256)) == biosmode) {


			for ( 	nby=2,nbx=2,atx=(maxc/2),aty=(maxr/2);
				atx >= 0;
				atx--, nbx +=2 ) {
				
				filzone( atx,	aty, nbx, nby, pixel );
				pixel++;
				pixel &= 0x00FF;
				if ( aty > 0 ) {
					aty --;
					nby += 2;
					}
				}
				
			wait(2);
			liberatepixel();
			wait(2);
			printf("liberatepixel()\n");
			}
		else	printf("error:cannot start graphics mode %u\n",biosmode);
	


		wait(2);

		}

	return(0);
}
 

