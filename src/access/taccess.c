#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#define __USE_LARGEFILE64 
#define	__USE_FILE_OFFSET64 
#include <sys/stat.h>

int	main(int argc, char* argv[] )
{
#ifdef	__USE_FILE_OFFSET64
static	struct stat64 buf64;
#endif
static	struct stat buf32;
	int	result;
	int	argi;
	if ( argc == 1 )
		printf("\n   Access Module Tester : Version 1.0a.0.01 \n");
	else	{
		for ( argi=1; argi < argc; argi++ ) {
			if (!( argv[argi] ))
				break;
			if ( stat(argv[argi],&buf32) < 0 ) {
				printf("stat(%s) => %u\n",argv[argi],errno);
#ifdef	__USE_FILE_OFFSET64
				if ( stat64(argv[argi],&buf64) < 0 )
					printf("stat64(%s) => %u\n",argv[argi],errno);
				else	printf("stat64 filesize : %lu\n",buf64.st_size);
#endif
				}
			else	printf("stat filesize : %lu\n",buf32.st_size);
			if ((result = Access(argv[argi],O_RDWR,0)) != 0)
				printf("error %u : access : %s\n",result,argv[argi]);
			else	printf("access : %s : ok\n",argv[argi]);
			}
		}
	liberlox(0);
	return(0);
}

