#include <stdio.h>
#include <sys/time.h>

int	main()
{
	struct timeval T;
	gettimeofday(&T,0);
	printf("%u.%u\n",T.tv_sec,T.tv_usec);
	return(0);
}


