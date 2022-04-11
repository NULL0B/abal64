#include <stdio.h>


void	banner()
{
	printf("\n   wDoc2Xt : Doc to Text Convertor : version 1.1a");
	printf("\n   Provisoire du 18/05/2000 ");
	printf("\n   Copyright (c) 2000,2006 Amenesik / Sologic \n");
	return;
}

unsigned char 	buffer[256];
unsigned char 	iname[256];
unsigned char 	oname[256];

unsigned int	maxwidth=78;

FILE	* ihandle=(FILE *) 0;
FILE	* ohandle=(FILE *) 0;


void process_file( char * nptr )
{
	int	indent=0;
	int	c;
	int	i;
	int	status=1;
	int	started=0;

	strcpy( iname, nptr ); strcat( iname, ".doc" );

	if ((ihandle = fopen( iname, "rb")) != (FILE *) 0) {

		strcpy( oname, nptr ); strcat( oname, ".txt" );

		if ((ohandle = fopen( oname, "wb")) != (FILE *) 0) {

//			printf("conversion of %s to %s\n",iname,oname);

			// Position to 7th sector !
			for (i=0; i < 6; i++ )
				(void) fread( buffer, 256, 1, ihandle );

			while (status) {

				switch ((c = fgetc( ihandle ))) {
					case	0 	:
					case	-1	:
					case	0x001A 	:
						fputc('\r',ohandle);
						fputc('\n',ohandle);
						fputc(0x001a,ohandle);
						status = 0; continue;
					case	0x0009	:
						indent++;
						continue;
					case	0x0008	:
						if ( indent )
							indent--;
						continue;
					case	0x000D	:
						fputc('\r',ohandle);
						fputc('\n',ohandle);
						started=0;
						continue;
					default		:
						if (!( started )) {
							for ( i=0; i < indent; i++ ) {
								fputc('\t',ohandle);
								started += 8;
								}
							}
						fputc((c&0x00FF),ohandle);
						started++;
						if (( c == ' ' )
						&&  ( started > maxwidth )) {
							fputc('\r',ohandle);
							fputc('\n',ohandle);
							started=0;
							}
						continue;
					}
				}

			fclose( ohandle );

			}
//		else 	printf("error creating output %s\n",oname);

		fclose( ihandle);
		}

//	else 	printf("error opening input %s\n",iname);

	return;
}


int	main( int argc, char * argv[] )
{
	int	argi;

	if ( argc == 1 )
		banner();
	else for ( argi=1; argi < argc; argi++ )
		process_file( argv[argi] );

	return(0);
}

