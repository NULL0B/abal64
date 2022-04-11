#include <stdio.h>

int	verbose=0;
int	isobject=0;

char	ibuffer[1024];

char *	updater="\0";
char *	source="s";
char *	target="\0";
char *	makename="makefile";
char *	trace="\0";
char *	debug="\0";
int	zapping=0;

int	banner()
{
	printf("\n   Abal makfile builder : Version 1.1a ");
	printf("\n   Provisoire du 05/07/2005 ");
	printf("\n   Copyright (c) 2005 Amenesik / Sologic \n");
	printf("\n   Syntax :");
	printf("\n          -rfilename         : specify makefilename");
	printf("\n          -sextension        : specify source extension");
	printf("\n          -ttargetpath       : specify target path");
	printf("\n          -ipath             : specify include path");
	printf("\n          -e                 : activate error trace");
	printf("\n          -ffile             : read tokens from file");
	printf("\n          -x                 : activate error trace");
	printf("\n          -u                 : update command");
	printf("\n          -z                 : dont change extensions");
	printf("\n          -zt                : force target path     ");
	printf("\n          -zs                : force source path     ");
	printf("\n          -m                 : generate debug \n\n");
	return;
}

FILE	*	h=(FILE *) 0;

int	dofile( char * aptr )
{
	int	i;
	int	status=0;

	if (!( h )) {
		if (!( h = fopen( makename, "w" ) )) {
			printf("error creating %s\n",makename);
			return(1);
			}
		fprintf(h,"# generated makefile : %s \n",makename  );
		fprintf(h,"# ------------------------------------\n" );
		if ((!( target ))
		||  (!(*target ))) {
			if (!( zapping )) {
				if (!( isobject )) {
					fprintf(h,"\n.%s.at:\n",source);
					fprintf(h,"\totr -s%s %s %s %s $*\n\n",source,trace,debug,ibuffer);
					}
				else	{
					fprintf(h,"\n.%s.o:\n",source);
					fprintf(h,"\totr -s%s %s %s %s $*\n\n",source,trace,debug,ibuffer);
					}
				}
			}
		else	{
			if (!( zapping )) {
				if (!( isobject )) {
					fprintf(h,"\n.%s.at:\n",source);
					fprintf(h,"\totr -s%s -d$@ %s %s %s $*\n\n",source,trace,debug,ibuffer);
					}
				else	{
					fprintf(h,"\n.%s.o:\n",source);
					fprintf(h,"\totr -s%s -d$@ %s %s %s $*\n\n",source,trace,debug,ibuffer);
					}
				}
			}
		}

	if ( zapping ) {
		switch ( zapping ) {
			case	1 	: 
				/* simple 1 to 1 dependance */
				/* ------------------------ */
				fprintf(h,"%s: %s\n",aptr,aptr); 
				break;

			case	't'	: 
				/* force target path to target */
				/* --------------------------- */
				while ( *(aptr+i) ) i++;
				while ( i ) {
					if ( *(aptr+i-1) == '/' )
						break;
					else	i--;
					}
				fprintf(h,"%s%s: %s\n",target,(aptr+i),aptr);
				break;

			case	's'	: 

				/* force target path to source */
				/* --------------------------- */
				/* force target path to target */
				/* --------------------------- */
				while ( *(aptr+i) ) i++;
				while ( i ) {
					if ( *(aptr+i-1) == '/' )
						break;
					else	i--;
					}
				fprintf(h,"%s: %s%s\n",aptr,target,(aptr+i));
				break;
				}
			if ( *updater ) 
				fprintf(h,"\t%s $* $@ \n",updater);

		return(0);
		}
	if (( target  )
	&&  ( *target ))
		fprintf(h,"%s",target);

	for ( i=0; *(aptr+i) != 0; i++ ) {
		if ( *(aptr+i) == '.' )
			break;
		else	fprintf(h,"%c",*(aptr+i));
		}
	if ( *(aptr+i) == '.' ) {
		if (!( isobject ))
			fprintf(h,".at: %s\n",aptr);
		else	fprintf(h,".o: %s\n",aptr);
		}
	else if (!( source )) {
		if (!( isobject ))
			fprintf(h,".at: %s\n",aptr);
		else	fprintf(h,".o: %s\n",aptr);
		}
	else	{
		if (!( isobject ))
			fprintf(h,".at: %s.%s\n",aptr,source);
		else	fprintf(h,".o: %s.%s\n",aptr,source);
		}

	return(0);
}


int	fromfile( char * nomfic )
{
	int	c;
	FILE * lf;
	int	i;
	int	status=0;
	char	token[256];
	if (!( lf = fopen( nomfic , "r" )))
		return(1);

	while (1) {
		while ((c = fgetc(lf)) > 0) {
			if (( c == ' ') || ( c == '\t' ) || ( c == '\n') || ( c == '\r' ))
				continue;
			else	break;
			}

		if ( c <= 0 ) 
			break;

		token[(i=0)] = c; i++;

		while ((c = fgetc(lf)) > 0) { 
			if (( c == ' ') || ( c == '\t' ) || ( c == '\n') || ( c == '\r' ))
				break;
			else if ( i < 255 )
				token[i++] = c;
			else	break;
			}

		if ( i == 256 ) {
			status= 2;
			break;
			}
		
		token[i++] = 0;

		if ((status = dofile( token )) != 0)
			break;

		else if ( c <= 0 )
			break;

		}
	fclose(lf);
	return( status );

}


int	main( int argc, char * argv[] )
{
	int	i;
	int	argi;
	char *	aptr;
	int	status=0;
	FILE * 	h=(FILE*)0;
	if ( argc < 3 )
		banner();
	else	{
		ibuffer[0] = 0;
		for (argi=1; argi < argc; argi++ ) {
			if (!( aptr = argv[argi]))
				break;
			else if ( *aptr == '-' ) {
				switch ( *(aptr+1) ) {
					case	'o'	:
					case	'O'	:
						isobject=1;
						continue;
					case	'r'	:
					case	'R'	:
						makename = (aptr+2);
						break;
					case	's'	:
					case	'S'	:
						source=(aptr+2);
						break;
					case	't'	:
					case	'T'	:
						target=(aptr+2);
						break;

					case	'i'	:
					case	'I'	:
						if (!( ibuffer[0] ))
							sprintf( ibuffer,"-I%s",(aptr+2));
						else	sprintf( ibuffer+strlen(ibuffer)," -I%s",(aptr+2));
						continue;

					case	'm'	:
					case	'M'	:
						debug = "-m";
						break;

					case	'f'	:
					case	'F'	:
						if (!( status = fromfile( (aptr+2) )))
							continue;
						else	return( status );
					case	'e'	:
					case	'E'	:
						trace = "-e";
						break;
					case	'x'	:
					case	'X'	:
						trace = "-x";
						break;
					case	'u'	:
					case	'U'	:
						updater = (aptr+2);
						break;

					case	'z'	:
					case	'Z'	:
						if (!( zapping=*(aptr+2) ))
							zapping=1;
						break;

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
			else  if (!( status = dofile( aptr ) ))
				continue;
			else	return( status );
			}
		if ( h ) {
			fprintf(h,"\n# eof ");
			fprintf(h,"\n# --- \n");
			fclose(h);
			}
		}
	return(0);
}


