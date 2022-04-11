#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int     jpg_close();
int     jpg_create( char * filename, unsigned int w, unsigned int h, int tc, int ps, unsigned char * palette );
int     jpg_row(int r, unsigned char * rowbuffer, int rl );

int	throw_exception(int v)
{
	exit(v);
}


int	main(int argc, char * argv[])
{
	int	r;
	char buffer[120];
	jpg_create("est.jpg",40,100,1,0,(char *) 0);
	for (r=0; r < 100; r++ ) {
		memset(buffer,r,80);
		jpg_row(r,buffer,40);
		}
	jpg_close();
	return(0);
}

