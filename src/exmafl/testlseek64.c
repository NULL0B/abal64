#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define	seektype long long

int	main()
{
	int	h;
	if ((h = creat("bigfile",0666)) == -1) 
		printf("cannot create bigfile\n");
	else	{
		close(h);
		if ((h = open64("bigfile",O_RDWR)) ==-1)
			printf("cannot open64 bigfile\n");
		else	{
			if ( lseek64(h,(seektype)0,SEEK_END) == (seektype) -1)
				printf("cannot lseek64 beyond end of empty file\n");
			close(h);
			}
		}
	return(0);
}

