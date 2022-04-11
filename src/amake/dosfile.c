#include <stdio.h>

char	buffer[1024];

int	fuckit(char * nfic )
{
	FILE * s;
	FILE * t;
	int	c;
	
	if (!( s = fopen( nfic, "r" )))
		return(40);
	else if (!( t = fopen("merde.out","w") ))
		return(46);
	else	{
		printf("%s\n",nfic);
		while ((c = fgetc(s)) != -1) {
			if ( c == '\n' )
				fputc('\r',t);
			fputc(c,t);
			}
		fputc(0x001A,t);
		fclose(s);
		fclose(t);
		sprintf(buffer,"mv merde.out %s -f",nfic);
		system( buffer );
		return(0);
		}
}



int	main(int argc, char * argv[] )
{
	int	status=0;
	int	argi;
	char *	aptr;
	for ( argi=1; argi < argc; argi++ ) { 
		if (!( aptr = argv[argi] ))
			break;
		else if (!(status = fuckit(aptr) ))
			continue;
		else	break;
		}
	return(status);
}

