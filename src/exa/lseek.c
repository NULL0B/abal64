#define	__USE_FILE_OFFSET64
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

typedef	long long megaword;

megaword	lseek64( int, megaword, int );
extern		int	errno;

int	main()
{
	int	h;
	int	bufsize=7777;
	int	wrote;
	char 	buffer[7777];
	megaword groffset=0;
	megaword moffset=0;
	double	offset=0;
#ifdef	__USE_FILE_OFFSET64
	printf("lseek 64 use file offset 64 is defined\r\n");
#else
	printf("lseek 64 use file offset 64 not defined\r\n");
#endif
	printf("sizeof off_t  : %u \r\n",sizeof( __off_t ));
	printf("sizeof double : %u \r\n",sizeof( double  ));
	printf("sizeof megaword : %u \r\n",sizeof( megaword  ));

	groffset = 0;
	if (( h = open("fuckingfile",O_RDWR)) < 0 ) {
		printf("fucking open failed : %u\n",errno);
		return(0);
		}
	while (1) {
		printf("seeking %x %x\n",groffset);
		if ((moffset = lseek64(h,groffset,SEEK_SET)) != groffset ) {
			printf("fucking groffset(%lx %lx) != moffset(%lx %lx)\n",groffset,moffset);
			break;
			}
		else if ((wrote = write( h, buffer, bufsize )) != bufsize ) {
			printf("fucking wrote (%u) != bufsize(%u) \n",wrote,bufsize);
			break;
			}
		else	groffset += wrote;
		}
	printf("fucking finished \n");
	close(h);
	return(0);
}

