#include <stdio.h>
#include <signal.h>
#include <errno.h>

int	event=0;

void	ccatcher(int s)
{
	event++;
	return;
}

void	pcatcher(int s)
{
	event++;
	return;
}

int	main(int argc, char * argv[] )
{
	int	n;
	int	x;
	int	child;
	if ( argc == 1 ) {
		printf("\n   Forked Process Signal to Signal Tester \n   usage : speed iterations\n\n");
		return(0);
		}
	else if (!( n = atoi( argv[1] ) )) {
		printf("\n   Forked Process Signal to Signal Tester \n   usage : speed iterations\n\n");
		return(0);
		}
	else	{
		switch ((child = fork())) {
			case	-1 : 
				printf("\n error : fork : %u \n",errno);
				return(errno);
			case	0  :

				/* child process */
				signal(SIGUSR1,ccatcher);
				while(1) {
					pause();
					printf("C %u \n",event);
					signal(SIGUSR1,ccatcher);
					kill(getppid(),SIGUSR2);
					}

			default	   :
				signal(SIGUSR2,pcatcher);
				sleep(1);
				/* parent process */
				for (x=0; x < n; x++ ) {
					printf("s %u \n",event);
					signal(SIGUSR2,pcatcher);
					kill(child,SIGUSR1);
					pause();
					printf("s %u \n",event);
					}
				return(0);
			}
		}
}



	








