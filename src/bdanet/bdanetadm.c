#include <stdio.h>
#include <errno.h>
#include <signal.h>

#define	UNIX

#ifdef	mono
#define EXTRA_SERVERS 0
#endif

#ifdef	multi
#undef  EXTRA_SERVERS
#undef  VERSION_DEMO
#endif

#ifdef demo
#define VERSION_DEMO
#endif

#include "blindage.c"

static	void	banner()
{
	printf("\n   Abal Bd@Net Administration Tool : Version 1.0a.0.01 ");
#ifdef	MONO
	printf(" -mono ");
#else
	printf(" -multi ");
#endif
	printf("\n   Provisoire du 21/06/2007 ");
	printf("\n   Copyright (c) 2007 Amenesik / Sologic \n");
	printf("\n   Options : \n");
#ifndef	VERSION_DEMO
	printf("\n           -t : display server process table ");
	printf("\n           -p : purge terminated process ");
	printf("\n           -i : allocate server process table ");
#endif
	printf("\n           -l : release server processes and table \n\n");

	return;
}

static	int	server_start()
{
	struct	server_control * sptr;
	int			status;

	if ((status = connect_server_memory()) != 0) {
		printf("error connecting to shared memory : %u ( %u )\n",status,errno);
		return( status );
		}

	if (!( sptr = (struct server_control *) ShmControl.base )) {
		printf("error connecting to shared memory : %u ( %u )\n",(status=752),errno);
		return( status );
		}

	return(0);
}

static	void	show_process_record( struct server_record * sptr, char * mptr )
{
	printf(":%012.1u:%012.1u:%012.1x:%012.1u:%012.12s:\n",
		sptr->process,
		sptr->port,
		sptr->flags,
		(time((long *) 0) - sptr->since),
		mptr);
	return;
}
static	int	server_trace()
{
	struct	server_control * sptr;
	int			i;
	int			status;

	if ((status = connect_server_memory()) != 0) {
		printf("error connecting to shared memory : %u ( %u )\n",status,errno);
		return( status );
		}

	if (!( sptr = (struct server_control *) ShmControl.base )) {
		printf("error connecting to shared memory : %u ( %u )\n",(status=752),errno);
		return( status );
		}

	printf(":------------+------------+------------+------------+------------+\n");
	printf(": bd@net server process table          : max=%06.1u : nb=%06.1u  :\n",sptr->limit,sptr->count);
	printf(":------------+------------+------------+------------+------------+\n");
	if ( sptr->count > 0 ) {
		printf(": PID        : PORT       : FLAGS      : SECONDS    : STATE      :\n");
		printf(":------------+------------+------------+------------+------------+\n");
		for ( i=0; i < sptr->limit; i++ ) {
			if (!( sptr->users[i].process ))
				continue;
			else if (!( kill(sptr->users[i].process,0) )) {
				show_process_record(&sptr->users[i],"active");
				}
			else	{
				show_process_record(&sptr->users[i]," ");
				}
			}
		printf(":------------+------------+------------+------------+------------+\n");
		printf(": bd@net server process table          : max=%06.1u : nb=%06.1u  :\n",sptr->limit,sptr->count);
		printf(":------------+------------+------------+------------+------------+\n");
		}
	return(0);
}

static	int	server_purge()
{
	struct	server_control * sptr;
	int			i;
	int			status;

	if ((status = connect_server_memory()) != 0) {
		printf("error connecting to shared memory : %u ( %u )\n",status,errno);
		return( status );
		}

	if (!( sptr = (struct server_control *) ShmControl.base )) {
		printf("error connecting to shared memory : %u ( %u )\n",(status=752),errno);
		return( status );
		}

	for ( i=0; i < sptr->limit; i++ ) {
		if (!( sptr->users[i].process ))
			continue;
		else if (!( kill(sptr->users[i].process,0) ))
			continue;
		else 	{
			if ( sptr->count )
				sptr->count--;
			reset_server_record(&sptr->users[i]);
			}
		}
	return(0);
}

static	int	server_close()
{
	struct	server_control * sptr;
	int	status;
	int	i;

	if ((status = connect_server_memory()) != 0) {
		printf("error connecting to shared memory : %u ( %u )\n",status,errno);
		return( status );
		}

	if (!( sptr = (struct server_control *) ShmControl.base )) {
		printf("error connecting to shared memory : %u ( %u )\n",(status=752),errno);
		return( status );
		}

	for ( i=0; i < sptr->limit; i++ ) {
		if (!( sptr->users[i].process ))
			continue;
		else if (!( kill(sptr->users[i].process,SIGTERM) ))
			continue;
		else 	{
			if ( sptr->count )
				sptr->count--;
			reset_server_record(&sptr->users[i]);
			}
		}

	if ((status = release_server_memory()) != 0) {
		printf("error releasing shared memory : %u ( %u )\n",status,errno);
		return( status );
		}
	else	return(0);

}

int main( int argc, char * argv[] )
{
	int	argi;
	char *	aptr;
	if ( argc == 1 ) {
		banner();
		return(0);
		}
	for (	argi=1;
		argi < argc;
		argi++ ) {
		if (!( aptr = argv[argi] ))
			continue;
		else if ( *(aptr++) != '-' )
			continue;
		switch ( *aptr ) {
#ifndef	VERSION_DEMO
			case	't'	:
				return(server_trace());
			case	'p'	:
				return(server_purge());
			case	'i'	:
				return(server_start());
#endif
			case	'l'	:
				return(server_close());
			default		:
				banner();
				printf("\n* * incorrect option : %s * *\n",aptr);
				return(30);
			}
		}
	return(0);
}

