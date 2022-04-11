#include <stdio.h>
int	main( int argc, char * argv[] )
{
	FILE * h;
	int	c;
	char *	s;
	int	o=0;
	char *	fn=(char *) 0;
	if ( argc != 3 )
		return(0);
	else	{
		fn = argv[1];
		s = argv[2];
		o = 0;
		while (( *s >= '0' ) && ( *s <= '9' ))
			o = (( o * 10) + ( *(s++) - '0' ));
		if (!( h = fopen(fn,"r")))
			printf("\nerror : file not found : %s \n",fn);
		else 	{
			fseek(h,o,SEEK_SET);
			printf("file : %s, offset : %lu { ",fn,o);
			while ((c = fgetc(h)) != -1) {
				printf("%c",c);
				if ( c == '\n' )
					break;
				}
			fclose(h);
			printf(" } \n");
			}
		}
	return(0);
}


