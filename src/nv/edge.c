#include <stdio.h>

int	maxwidth=64;
int	recursive=0;
int	nombre;

void * 	malloc(int);
void	free(void *);

int	integer( char * sptr )
{
	int	r=0;
	while ((*sptr >= '0') && ( *sptr <= '9'))
		r = ((r * 10) + (*(sptr++) - '0'));
	return(r);
}

void	indented( char * mptr, int w )
{
	int	i;
	int	l;
	printf("%s",mptr);
	if ( w ) {
		for (l = strlen( mptr ); l < w; l++ )
			printf("%c",32);
		}
	return;
}

void	linefeed()
{
	printf("\n");
}
	

void	formated(char * sptr, char * mptr, int w )
{
	int	i;
	int	l;
	int	sl=0;
	int	ml=0;
	int	tl=0;
	if ( sptr ) {
		printf("%s\\",sptr);
		sl = strlen(sptr)+1;
		}
	if ( mptr ) {
		printf("%s",mptr);
		ml = strlen(mptr);
		}
	if ( w ) {
		tl = ml + sl;
		for (; tl < w; tl++ )
			printf("%c",32);
		}
	return;
}

int 	getword( char * bptr )
{
	return((*bptr + ( *(bptr+1) << 8)));
}

long	getlong( char * bptr )
{
	long	r=0L;
	int	i;
	i = getword(bptr);
	r = (long) getword((bptr+2));
	r = ((r  << 16) + i);
	return( r );
}
 

int	research( char * start )
{
	char *	dirptr;
	int	access=0;
	short int	dosfirst(char *,char *,short int);
	short int	dosnext(char *);
	char	buffer[32];
	char *	cataptr=(char *) 0;
	char *	nameptr=(char *) 0;
	int	status=0;
	int	d;
	if ((cataptr = malloc( 64 )) != (char *) 0) {
		if (( nameptr = malloc( strlen( start ) + strlen("*.*") + 16 )) != (char *) 0) {
			sprintf(nameptr,"%s\\%s",start,"*.*");
			if ( dosfirst(cataptr,nameptr,0x00F7) == 0 ) {
				do	{
					access = *(cataptr+21);
					if (!( access & 8 )) { /* ! volume label */
						formated( start, (cataptr+0x001E), maxwidth );
						if ( access & 16)
							indented("[DIR]",0);
						else	{
							if ( access & 1 )
								indented("R",0);
							else	indented("-",0);
							if ( access & 2 )
								indented("H",0);
							else	indented("-",0);
							if ( access & 4 )
								indented("S",0);
							else	indented("-",0);
							if ( access & 16)
								indented("D",0);
							else	indented("-",0);
							if ( access & 32)
								indented("A",0);
							else	indented("-",0);
							}
						/* File size */
						indented(" ",2);
						if (!( access & 16)) {
							sprintf(buffer,"%lu",getlong((cataptr+26)));
							indented(buffer,12);
							}
						else	indented(" ",12);
						d = getword( (cataptr+24) );
						sprintf(buffer,"%02.1u.%02.1u.%u",
							(d & 0x001F),
							((d >> 5) & 0x000F),
							(((d>>9)&0x003F)+1980));
						indented(buffer,12);
						d = getword( (cataptr+22) );
						sprintf(buffer,"%02.1u:%02.1u:%02.1u",
							((d>>11)&0x001F),
							((d >> 5) & 0x003F),
							((d & 0x001F) << 1));
						indented(buffer,12);
						linefeed();
						if ((( access & 16) != 0)
						&&  (recursive != 0  )
						&&  (*(cataptr+0x001E) != '.')) {
							if ((dirptr = malloc(strlen(start) + strlen((cataptr+0x001E)) + 16)) != (char *) 0) {
								sprintf(dirptr,"%s\\%s",start,(cataptr+0x001E));
								status = research( dirptr );
								free( dirptr );
								if ( status ) break;
								}
							else	{
								status = 27;
								break;
								}
							}
						}
					}
				while (dosnext(cataptr) == 0);
				}
			free( nameptr );
			}
		else	status = 27;
		free( cataptr );
		}
	else	status = 27;

	return(status);

}

int	option( char * aptr )
{
	while ( *aptr ) {
		switch ( *(aptr++) ) {
			case	'w'	:
			case	'W'	:
				maxwidth=integer( aptr );
				return(0);
			case	'r'	:
			case	'R'	:
				recursive=1;
				continue;
					
			default		:
				return(30);
			}
		}
	return(0);
}

int	operation( int argc, char * argv[] )
{
	int	argi;
	char *	argp;
	for ( argi=1; argi < argc; argi++ ) {
		if ((argp = argv[argi]) == (char *) 0)
			break;
		else if (( *argp != '-' )
		     &&  ( *argp != '/' )) {
			if (research(argp))
				break;
			else	continue;
			}
		else if ( option( (argp+1) ) )
			break;
		else	continue;
		}
	return(0);
}

int	banner()
{
	printf("\n   Disk Catalog List Utility : Version 1.1a");
	printf("\n   Copyright (c) 2000 I.J.Marshall \n");
	printf("\n   /W<int>   minimum path length");
	printf("\n   /R        recursive analysis\n");
	return(0);
}

int	main( int argc, char * argv[] )
{
	if ( argc == 1 )
		return(banner());
	else	return(operation( argc, argv ));
}


