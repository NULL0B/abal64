#ifndef	_blindage_c
#define	_blindage_c

#ifndef	EXTRA_SERVERS
#define	EXTRA_SERVERS	256
#endif

#ifdef	UNIX

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int	ServerFailure=0;

int	protection_failure();

struct	server_record	{
	int	process;
	int	port;
	int	since;
	int	flags;
	};

struct	server_control	{
	int	limit;
	int	count;
	struct	server_record users[1];
	};

static	struct	shm_control	{
	char *	base;
	key_t	key;
	int	size;
	int	flags;
	int	id;
	int	max;
	} ShmControl = 
		{
		(char *) 0, 
		(key_t) 0x0000abda, 
		(sizeof( struct server_control ) + (sizeof( struct server_record ) * (1024-1))), 
		0x001FF, 
		-1,
		EXTRA_SERVERS
		};

static	int	release_server_memory()
{
	int	status;
	struct	server_control * sptr;

	if (!( sptr = (struct server_control *) ShmControl.base ))
		return( 752 );

	if ( ShmControl.id != -1 ) {
		status = shmctl(ShmControl.id, IPC_RMID, (struct shmid_ds *) 0);
		ShmControl.id = -1;
		if ( status != -1 )
			return(0);
		else	return(755);
		}
	return(0);
}

static	void	reset_server_record(struct server_record * sptr )
{
	sptr->process = 
	sptr->port    = 
	sptr->since   = 
	sptr->flags   = 0;
	return;
}

static	int	connect_server_memory()
{
	int	i;
	struct	server_control * sptr;
	int	p=getpid();
	int	resetmem=0;
	if (!( ShmControl.base )) {

		if (( ShmControl.id = shmget( ShmControl.key,ShmControl.size, ShmControl.flags )) == -1) {
			if (( ShmControl.id = shmget( ShmControl.key,ShmControl.size, ShmControl.flags | IPC_CREAT | IPC_EXCL )) == -1)
				return(750);
			else	resetmem=1;
			}
		if ((ShmControl.base = shmat(ShmControl.id,0L,0L)) == -1) {
			ShmControl.base = (char *) 0;
			return(751);
			}
		}

	if (!( sptr = (struct server_control *) ShmControl.base ))
		return( 752 );

	else if ( resetmem ) {
		sptr->limit = EXTRA_SERVERS;
		sptr->count = 0;
		for (i=0; i < EXTRA_SERVERS; i++ ) {
			reset_server_record(&sptr->users[i]);
			}
		}
	return(0);
}

static	int	release_server_record(int param,int flags)
{	
	int	status;
	int	i;
	struct	server_control * sptr;
	int	p=getpid();

	if ((status = connect_server_memory()) != 0)
		return( status );

	if (!( sptr = (struct server_control *) ShmControl.base ))
		return( 752 );

	/* ------------------------------------- */
	/* locate this pid in the table of users */
	/* ------------------------------------- */
	for (i=0; i < sptr->limit; i++ ) {
		if ( sptr->users[i].process != p )
			continue;
		else if ((param != 0) && ( sptr->users[i].port != param ))
			continue;
		else if ((flags != 0) && ( sptr->users[i].flags != flags ))
			continue;
		else	{
			if ( sptr->count ) sptr->count--;
			reset_server_record(&sptr->users[i]);
			if ((!(param)) || (!( flags )))
				continue;
			else	break;
			}
		}
	return(0);
}

static	int	server_limit_failure(int param,int flags)
{	
	int	status;
	int	i;
	struct	server_control * sptr;
	int	p=getpid();

	if ((status = connect_server_memory()) != 0)
		return( status );

	if (!( sptr = (struct server_control *) ShmControl.base ))
		return( 752 );

	/* ------------------------------------- */
	/* locate this pid in the table of users */
	/* ------------------------------------- */
	for (i=0; i < sptr->limit; i++ ) {
		if ( sptr->users[i].process == p )
			return(0);
		else if (!( sptr->users[i].process ))
			continue;
		else if (!( kill(sptr->users[i].process,0) ))
			continue;
		else 	{
			if ( sptr->count )
				sptr->count--;
			reset_server_record(&sptr->users[i]);
			}
		}

	/* ------------------- */
	/* locate a free entry */
	/* ------------------- */
	for (i=0; i < sptr->limit; i++ )
		if (!( sptr->users[i].process ))
			break;

	/* --------------------- */
	/* check limit and store */
	/* --------------------- */
	if ( i < sptr->limit ) {
		sptr->count++;
		sptr->users[i].process = p;
		sptr->users[i].port    = param;
		sptr->users[i].since   = time((long*) 0);
		sptr->users[i].flags   = flags;
		return(0);	
		}
	else	return( 753 );
}

#else
static	int	server_limit_failure()	{	return(0);	}
#endif

static	int	MaxServerCounter=200;
static	int	MaxDemoCounter=200;

int	protection_failure()	
{
#ifndef	VERSION_DEMO
	return(ServerFailure);	
#else
	return(0);
#endif
}

static	int	InternetAddressDecode(int opcode,int p1, int p2)
{
	int	status=0;
	switch ( opcode ) {

		case	0 : /* test open server limit */
#ifndef	VERSION_DEMO
			if ((status = protection_failure()) != 0)
				return(status);
			else if ((status = server_limit_failure(p1,p2)) != 0)
				return(status);
			else
#endif
				return(0);

		case 	3 : /* close open server */
#ifndef	VERSION_DEMO
			if ((status = protection_failure()) != 0)
				return(status);
			else if ((status = release_server_record(p1,p2)))
				return( status );
			else
#endif
				return(0);

		case	1 : /* test demo counter      */
#ifdef	VERSION_DEMO
			if (!( MaxDemoCounter ))
				return(746);
			else	
#endif
				return(0);

		case	2 : /* decrement demo counter */
#ifdef	VERSION_DEMO
			if (!( MaxDemoCounter ))
				return(746);
			else	{
				MaxDemoCounter--;
				return(0);
				}
#else
			return(0);
#endif
		default	  :
			return(745);
		}
}

#ifdef	TEST_PROTECTION
static	int	InternetAddressTestDecode(int opcode,int p1, int p2) { return(0); }
static int	(*gps)(int,int,int)=InternetAddressTestDecode;
#else
static int	(*gps)(int,int,int)=InternetAddressDecode;
#endif

#endif	/* _blindage_c */
	/* ----------- */

