#include <stdio.h>
#include <fcntl.h>
void * malloc(int);
void	free(void *);

int	wordsize=0;
int	verbose=0;
int	debug=0;
int	allowed=0;

unsigned	int	tcgetw(char * mptr )
{
	int	r;
	r = (*(mptr++) & 0x00FF);
	r += ((*(mptr++) & 0x00FF) << 8);
	return(r);
}

unsigned	long	tcgetl(char * mptr )
{
	unsigned 	long r;
	r = tcgetw(mptr);
	r += (tcgetw((mptr+2)) << 16);
	return(r);
}

unsigned long tcodeword(char * wptr)
{
	switch ( wordsize ) {
		case	2 :	return( tcgetw( wptr ) );
		case	4 :	return( tcgetl( wptr ) );
		default	  :	return(0);
		}
}

static	int	preload(char * aptr , char * bptr )
{
	int	h;
	char		nptr[256];
	int		n;
	int	x;
	unsigned	int	sector;
	unsigned	int	length;
	FILE 		* 	hptr;
	char			wptr[256];
	char 		*	tptr;
	char 		*	sptr;
	int			modified=0;
	int			nombre;
	int			functions=0;
	int			preload=0;
	int			match=0;
	int			nlog=0;
	int			mode=1;
	if ( *bptr != '-' )
		mode = 1;
	else	{
		mode=0;
		bptr++;
		}
	if (!( hptr = fopen( aptr, "rb" ))) {
		printf("\n** error opening file : %s **\n",aptr);
		return(0);
		}
	else	{
		if (( verbose ) || ( debug )) {
			printf("\nchecking file %s for %s \n",aptr,bptr);
			}
		if ( fread( wptr, 256, 1, hptr ) > 0) {
			switch ( *wptr ) {
				case	'1'	:
				case	'2'	:
					wordsize=2;
					sector = tcgetw((wptr+((24*wordsize)+20)));
					length = tcgetw((wptr+((25*wordsize)+20)));
					break;
				case	'3'	:				
					wordsize=4;
					sector = tcgetl((wptr+((24*wordsize)+20)));
					length = tcgetl((wptr+((25*wordsize)+20)));
					break;
				default	:
					fclose(hptr);
					printf("** incorrect tcode version : %c **\n",*wptr);
					return(1);
				}
			if (( verbose ) || ( debug )) {
				printf("version : %c.%c.%c \nwordsize: %u \n",*wptr,*(wptr+1),*(wptr+2),wordsize);
				}
			if ( length > 0 ) {
				if (( verbose ) || ( debug )) {
					printf("dynamic library table at sector %lu length %lu \n",sector,length);
					}
				fseek(hptr,(sector * 256),SEEK_SET);
				if (!(tptr = malloc((length * 256)))) {
					fclose(hptr);
					printf("** memory allocation failure : %u bytes **\n",(length*256));
					return(1);
					}
				else if ( fread(tptr,(length*256),1,hptr) <= 0 ) {
					fclose(hptr);
					printf("** error reading dynamic library table **\n");
					return(1);
					}
				else	{	
					sptr = tptr;
					nombre = tcodeword(tptr); tptr += wordsize;
					if (( verbose ) || ( debug )) {
						printf("library count : %u \n",(nombre& 0x00FF));
						}
					for ( n=0; n < nombre; n++ ) {
						x = 0;
						while ((*(nptr+x) = *(tptr+x)) != 0)
							x++;

						if (( verbose ) || ( debug )) {
							printf("library : %s",nptr);
							}
						functions = *(tptr+x+1);
						/* printf(" %u ",functions); */
						preload = *(tptr+x+2);
						/* printf(" %u ",preload); */
						if (( verbose ) || ( debug )) {
							if ( preload ) 
								printf(",preload ");
							}
						match = strcmp( nptr, bptr );
						if (( verbose ) || ( debug )) {
							if (!( match ))
								printf(" : match\n");
							else	printf(" \n");
							}
						if (!( match )) {
							*(tptr+x+2) = mode;
							modified=1;
							}
						h = x + 19;
						if ( debug ) {
							for ( x=0; x < h; x++ )
								printf("%02.2X ",(*(tptr+x) & 0X00FF));
							printf("\n");
							}
						tptr += h;
						}					
					if ( modified ) {
						if (( verbose ) || ( debug )) {
							if ( allowed )
								printf("dynamic library table modified\n");
							else 	printf("dynamic library table would be modified. use option -y to confirm \n");
							}
						if ( allowed ) {
							if ((nlog = open( aptr , O_RDWR, 0 )) > 0) {
								lseek(nlog,(sector*256),SEEK_SET);
								if ( write(nlog,sptr,(length*256)) != (length*256 )) 
									printf("** error writing to file %s **\n",aptr);
								close(nlog);
								}
							else	{
								fclose(hptr);
								printf("** error opening file %s for output **\n",aptr);
								return(1);
								}
							}
						}
					free(sptr);
					}
				}
			else if (( verbose ) || ( debug )) {
				printf("no dynamic library table\n");
				}
			}
		fclose(hptr);	
		return(1);
		}
}

void	banner()
{
	printf("\n   Abal 3 Dynamic Library Preload Patch Utility : Version 3.1a.0.01");
	printf("\n   Provisoire du 16/05/2006 ");
	printf("\n   Copyright (c) 2006 Amenesik / Sologic \n ");
	printf("\n   Syntax : ");
	printf("\n          bdapreload library_name options program_names     ");
	printf("\n   Options:       -v                activate messages    ");
	printf("\n                  -d                debug table entries  ");
	printf("\n                  -y                confirm modification ");
	printf("\n   Example: ");
	printf("\n          bdapreload asfun -v *.at     mark asfun for preload ");
	printf("\n          bdapreload -asfun -v *.at    unmark asfun for preload ");
	printf("\n          bdapreload asfun -v -y *.at  confirm mark asfun for preload \n\n");
	return;
}

int main(int argc, char * argv[] )
{
	int	argi;
	char *	aptr;
	char *	bptr;
	if ( argc < 3 )
		banner();
	else if (!( bptr = argv[1] ))
		return(0);
	for ( argi=2; argi < argc; argi++ ) {
		if (!( aptr = argv[argi] ))
			break;
		else if ( *aptr == '-' ) {
			switch ( *(aptr+1) ) {
				case	'y' : allowed=1; continue;
				case	'v' : verbose=1; continue;
				case	'd' : debug=1; continue;
				default	    :
					printf("incorrect option : %s \n",aptr);
					break;
				}
			}
		else  if (!( preload( aptr, bptr )))
			return(1);
		else	continue;
		}
	return(0);
}

