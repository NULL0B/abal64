#include <stdio.h>
int	main(int argc, char * argv[] )
{
	FILE * s;
	FILE * r;
	int	c;
	if ( argc == 3 ) {
		if (!( s = fopen( argv[1] , "r" ))) {
			printf("source file error : %s \n",argv[1]);
			return(1);
			}
		else if (!( r = fopen( argv[2] , "w" ))) {
			fclose(s);
			printf("target file error : %s \n",argv[2]);
			return(1);
			}
		while ((c = fgetc(s)) != -1) {
			if ( c >= ' ' ) 
				fputc(c,r);
			else 	{
				switch ( c )  {
					case	'\t'	:
					case	'\r'	:
					case	'\n'	:
						fputc(c,r);
					}
				}
			}
		fclose(r);
		fclose(s);
		return(0);
		}
}

		
