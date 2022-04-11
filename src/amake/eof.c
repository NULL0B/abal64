#include <stdio.h>

char	buffer[256];
int	verbose=0;
int	echo=0;
int	doit=0;
int	banner()
{
	printf("\n   EOF : End Of File Fixer : Version 1.0a ");
	printf("\n   Provisoire du 02/10/2003 ");
	printf("\n   Copyright (c) 2003 Amenesik / Sologic \n");
	return;
}

int	main( int argc, char * argv[] )
{
	int	argi;
	char *	aptr;
	FILE * 	sh;
	FILE * 	th;
	int	c;
	if ( argc == 1 )
		banner();
	else	{
		for (argi=1; argi < argc; argi++ ) {
			if (!( aptr = argv[argi]))
				break;
			else if ( *aptr == '-' ) {
				switch ( *(aptr+1) ) {
					case	'Y'	:
					case	'y'	:
						doit=1; break;
					case	'e'	:
					case	'E'	:
						echo=1; break;
					case	'v'	:
					case	'V'	:
						verbose=1;
						break;
					default		:
						printf("syntax error : %s\n",aptr);
						return(30);
					}
				continue;
				}
			else if (!( sh = fopen(aptr,"r"))) {
				printf("error opening %s\n",aptr);
				return(1);
				}
			else if (!( th = fopen("eof.tmp","w"))) {
				printf("error creating eof.tmp\n");
				fclose(sh);
				return(2);
				}
			else	{
				if ( verbose ) 	printf("eof %s\n",aptr);
				while ((c = fgetc(sh)) != -1) {
					if ( c == 0x001A )
						break;
					if ( c == '\r' )
						continue;
					else	{
						if ( echo ) printf("%c",(c & 0x00FF));
						fprintf(th,"%c",(c & 0x00FF));
						}
					}
				if ( echo ) printf("\n");
				fprintf(th,"\n");
				fclose(th);
				fclose(sh);
				if ( doit )
					sprintf(buffer,"mv %s %s","eof.tmp",aptr);
				else	sprintf(buffer,"rm eof.tmp");
				if ( verbose ) printf("%s\n",buffer);
				system(buffer);
				}
			}
		}
	return(0);
}

