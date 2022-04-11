#include <stdio.h>

#include "cryptage.c"

CRYPTAGE  coding;

char	buffer[256];

int	main( int argc, char * argv[] )
{
	long	offset=0L;
	char	*nomsrc;
	char	*nomtgt;
	char	*koding;
	int	argi;
	FILE *	hin;
	FILE *	hout;
	if ( argc < 3 )
		printf("\n   File Encryption Engine : Version 1.1a.0.01\n   Provisoire du 28/11/2000\n   Copyright (c) Amenesik / Sologic Sofwtare\n");

	else if ((koding = argv[1]) != (char *) 0) {

		for (	argi=2; argi < argc; argi+=2) {

	
			if ((nomsrc = argv[argi]) == (char *) 0)
				break;

			else if ((nomtgt = argv[argi+1]) == (char *) 0)
				break;

			printf("encryption of %s to %s\nusing %s\n",nomsrc,nomtgt,koding);

			if ( start_cryptage( & coding, koding, strlen(koding) , 1 ) != 1 )
				return(0);

			if ((hin = fopen( nomsrc, "rb" )) != (FILE *) 0) {
				if ((hout = fopen( nomtgt, "wb" )) != (FILE *) 0) {
					while (1) {
						if ( fread(buffer,1,1,hin) != 1 )
							break;
						crypt( & coding, buffer, 1 );
						if ( fwrite(buffer,1,1,hout) != 1)
							break;
						offset++;
						}
					printf("%lu bytes\n",offset);
					fclose(hout);
					}
				fclose(hin);
				}
			}
		}
	return(0);
}




