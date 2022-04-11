#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int	aval[200];

int	integer(char * sptr)
{
	int	r=0;
	while ( *sptr ) {
		if (( *sptr >= '0' ) && ( *sptr <= '9'))
			r = ((r*10) + (*(sptr++) - '0'));
		else	break;
		}
	return( r );
}
		
int	WaitForChild(int jobid)
{
	int	status=0;
	while (1) {

		/* Await child completion */

		printf( "waitpid(%u)\n",jobid);
		
		if ( waitpid( jobid, & status, 0 ) == -1 ) {
			printf( "waitpid(%u) failure(%d)\n",jobid, -1);
			if ( errno == ECHILD ) {
				printf( "waitpid(%u) ECHILD\n",jobid);
				return(-1);
				} 
			if ( errno != EINTR ) {
				printf( "waitpid(%u) ERRNO=%d\n",jobid,errno);
				return(-1);
				}
			else	printf( "waitpid(%u) EINTR\n",jobid);
			}
		else	{
			if ( WIFEXITED(status) ) {
				status = WEXITSTATUS(status);
				printf("waitpid(%u) exit(%d)\n",jobid,status);
				}
			else if ( WIFSIGNALED(status) ) {
				status = WTERMSIG(status);	
				printf("waitpid(%u) signal(%d)\n",jobid,status);
				}
			else	{
				printf("waitpid(%u) status(%d)",jobid,status);
				}	
			return(status);
			}
		}

}

int	sleeper( int cadal ) 
{
	sleep(1);
	printf("bidh mi(%u) a'cadail(%u)\n",getpid(),cadal);
	sleep(cadal);
	printf("beir am bas mi(%u) a-nis\n",getpid());
	exit(cadal);
}

int	fuckup()
{
	sleep(1);
	printf("s'e mearachd(%u) a bh'annam(%u)\n",errno,getpid());
	return(-1);
} 

int	faire( int aireamh )
{
	sleep(1);
	printf("bidh mi(%u) a'cumail faire air(%u)\n",getpid(),aireamh);
	return( WaitForChild(aireamh) );
	
}

int	childmain()
{
	int	jobi;
	int	jobs;
	int	cadal;
	int	jobid;
	sleep(1);
	printf("\noriginal child(%u) staring \n",getpid());
	if (!( jobs = aval[0] ))
		sleep(5);
	else	{
		for ( jobi=0; jobi < jobs; jobi++ ) {
			if (!( cadal = aval[(jobi+1)] ))
				cadal = 1;

			switch( fork() ) {
				case	0 :
				switch ((jobid = fork())) {
					case	0	:
						return( sleeper(cadal) );
					case	-1	:
						return( fuckup() );
					default		:
						return( faire(jobid) );

					}
				case	-1 :
					return(fuckup() );
				}

			}
		sleep(200);
		}
	exit(0);

}





int	xmain(int argc, char * argv[] )
{
	int	argi;
	char *	aptr;
	int	jobs;
	int	pid;
	for ( argi=0; argi < 200 ; argi++ ) aval[argi] = 0;
	signal( SIGCLD,SIG_IGN);
	for ( argi=1; argi < argc; argi++ ) {
		if (!( aptr = argv[argi] )) 
			break;
		else	aval[argi-1] = integer( aptr );
		}
	switch ((pid = fork())) {
		case	0	:
			return(childmain());
		case	-1	:
			printf("\ninitial fork() failure : %d\n",errno);
			return(0);
		default		:
			printf("\ninitial parent(%u) waiting original child(%u)\n",getpid(),pid);
			return( WaitForChild( pid ) );
		}
	return(0);
}

int	banner()
{
	printf("\n   FORK/WAIT probe \n");
	printf("\n   usage : nbproc waitcounts\n");
	return(0);
}

int	main(int argc, char * argv[] )
{
	if ( argc == 1 )
		return( banner() );
	else	return( xmain(argc,argv) );
}


