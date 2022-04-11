#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
struct	process_node
{
	struct	process_node * next;
	struct	process_node * previous;
	int	pid;
	int	ppid;
	char 	name[64];
};

struct	process_node * ChainHead;
struct	process_node * ChainFoot;

int	remove_process_chain()
{
	char	buffer[1024];
	struct	process_node * nptr;
	while ((nptr = ChainHead) != (struct process_node *) 0)
	{
		ChainHead = nptr->next;
		free( nptr );
	}
	sprintf(buffer,"/tmp/pchain%u.tmp",getpid());
	return( system( buffer ) );
}


char *	get_token( char * iptr, char * optr, int olen )
{
	int	c;
	int	n;
	/* avoid null pointer */
	/* ------------------ */
	if (!( iptr )) 	return( iptr );

	/* remove leading space */
	/* -------------------- */
	while ( *iptr )
	{
		if (( *iptr != ' '  )
		&&  ( *iptr != '\t' ))
			break;
		else	iptr++;
	}
	if (!( *iptr )) return((char *) 0);

	for ( n=0; n < olen; n++ )
	{
		if (!( c = *(iptr++) ))
			break;
		else if ( c == ' ' )
			break;
		else if ( c == '\t' )
			break;
		else if ( c == '\n' )
			break;
		else	optr[n] = c;
	}
	optr[n] = 0;
	return( iptr );
}

int	create_process_chain()
{
	FILE * h;
	int	n;
	char	username[17];
	char	pid[17];
	char	ppid[17];
	char	buffer[16000];
	char *	bptr;
	struct	process_node * nptr;
	sprintf(buffer,"ps -ef > /tmp/pchain%u.tmp",getpid());
	ChainHead = ChainFoot = (struct process_node *) 0;
	if ( system( buffer ) == -1 )
		return( -1 );
	else
	{
		sprintf(buffer,"/tmp/pchain%u.tmp",getpid());
		if (!( h = fopen(buffer,"r")))
			return( -1 );
		else
		{
			while (!( feof( h ) ))
			{
				if (!( fgets( (bptr = buffer), 16000, h ) ))
					break;
				bptr = get_token( bptr, username, 16 );
				bptr = get_token( bptr, pid, 16 );
				bptr = get_token( bptr, ppid, 16 );
				// printf( "%s %u %u \n", username,atoi(pid),atoi(ppid) );
				if (!( nptr = malloc( sizeof( struct process_node ) ) ))
					break;
				else
				{
					nptr->pid = atoi( pid );
					nptr->ppid= atoi( ppid );
					strcpy( nptr->name, username );
					if (!( nptr->previous = ChainFoot ))
						ChainHead = nptr;
					else 	nptr->previous->next = nptr;
					ChainFoot = nptr;
				}
			}
			fclose(h);
		}
		return( 0 );
	}
}

int	parent_of( int pid )
{
	struct 	process_node * nptr;
	for ( 	nptr=ChainHead;
		nptr != (struct process_node *) 0;
		nptr = nptr->next )
		if ( nptr->pid == pid )
			return( nptr->ppid );
	return( 0 );
}

int	main( int argc, char * argv[] )
{
	int	what;
	char	buffer[1024];
	if ( argc == 1 )
		printf("\n   process chain inspector : version 1.0a.0.01\n   copyright (c) 2010 IJM \n\n");
	else if ( create_process_chain() == -1 )
		printf("\n   failure staring process chain \n");
	else
	{
		for ( what=atoi( argv[1] ); 
			what != 0; 
			what = parent_of( what ))
		{
			printf("%u ",what);
		}
		printf("\n");
		remove_process_chain();
		return(0);
	}
}

