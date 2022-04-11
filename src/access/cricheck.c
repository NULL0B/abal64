#include <stdio.h>
#include <errno.h>
#include <signal.h>

static	char	tempname[256];
static	char	buffer[2049];

static	int	echo=0;
static	int	verbose=0;
static	int	killer=0;
static	int	yes=1;
static	int	total=0;
static	int	silence=0;

static	int	banner(int argc, char * argv[] )
{
	printf("\n   Abal Criteria / Access Session Check Utility : Version 1.0a ");
	printf("\n   Provisoire du 10/09/2007 ");
	printf("\n   Copyright (c) 2007 Amenesik / Sologic  \n");
	printf("\n   usage : cricheck [ options ] \n");
	printf("\n   options {                    ");
	printf("\n           -t : test only, no correction performed");
	printf("\n           -v : display informational messages ");
	printf("\n           -s : inhibit all messages ");
	printf("\n           -k : use SIGKILL not SIGTERM ");
	printf("\n           -e : echo trace record information ");
	printf("\n           }                    \n");
	printf("\n   this utility may be used for verification of abal/criteria ");
	printf("\n   processes and access file management record release. \n\n");
	return(0);
}

static	int	failure(char * message)
{
	if (!( silence )) {
		printf("\n** error : %u : %s **\n",errno,message);
		}
	return(1);
}

static	int	option(char * sptr)
{
	if ( *sptr  == 'v' ) {
		verbose = 1;
		silence = 0;
		return(0);
		}
	else if ( *sptr == 'k' ) {
		killer = 1;
		return(0);
		}
	else if ( *sptr == 'e' ) {
		echo = 1;
		return(0);
		}
	else if ( *sptr == 's' ) {
		silence = 1;
		verbose = 0;
		return(0);
		}
	else if ( *sptr == 't' ) {
		yes = 0;
		return(0);
		}
	else	return( failure("incorrect option" ) );
}

static	int	getcriline(FILE * h)
{
	int	c;
	int	i=0;
	while ( i < 2048 ) {
		if ((c = fgetc(h)) <= 0 )
			break;
		else if ( c == '\r' )
			continue;
		else if ( c == '\n' )
			break;
		else if ( c == '\t' )
			c = ' ';
		buffer[i++] = c;
		}
	buffer[i] = 0;
	return(i);		
}

static	int	missing_process( int process, char * nptr )
{
	if (!( kill(process,0) )) 
		return(0);
	else 	{
		if (!( silence )) { printf("missing  process : %s ( pid = %u ) \n",nptr, process ); }
		return(process);
		}
}

static	int	shoot_process( int process, char * nptr )
{
	char	command[256];
	if (!( yes ))
		return(0);
	if (!(silence)) {
		printf("stoping process : %s ( pid = %u ) \n",nptr, process );
		}

	if (!( killer )) {	
		kill(process,SIGTERM);
		}
	else	{
		kill(process,SIGKILL);
		}
	total++;
	return(0);
}

static	int	flush_access( int process, char * nptr )
{
	char	command[256];
	if (!( yes ))
		return(0);
	sprintf(command,"/opt/prologue/bin/access -p%u",process);
	if (!(silence))
		printf("releasing records for %s : %s \n",nptr,command);

	return( system( command ) );
}

static	int	postexec(int missing, int other)
{
	return(0);
}

static	int	analysis()
{
	int	exapid;
	int	cripid;
	char * bptr=buffer;

	if ( echo )
		printf( "%s\n",bptr);

	if    ( *bptr == '|' )	
		bptr++;		/* remove separator 	*/
	while ( *bptr == ' ' )	
		bptr++;		/* step over space	*/

	while (( *bptr ) && ( *bptr != '|' ))	
		bptr++;		/* seek   separator 	*/
	if    ( *bptr == '|' )	
		bptr++;		/* remove separator 	*/
	else	return(0);	/* nothing to do	*/

	while ( *bptr == ' ' )	
		bptr++;		/* step over space	*/

	if (!( exapid = atoi( bptr )))
		return(0);	/* whoops no exa	*/

	while (( *bptr ) && ( *bptr != '|' ))	
		bptr++;		/* seek   separator 	*/

	if    ( *bptr == '|' )	
		bptr++;		/* remove separator 	*/
	else	return(0);	/* nothing to do	*/

	while (( *bptr ) && ( *bptr != '|' ))	
		bptr++;		/* seek   separator 	*/

	if    ( *bptr == '|' )	
		bptr++;		/* remove separator 	*/
	else	return(0);	/* nothing to do	*/

	while ( *bptr == ' ' )	
		bptr++;		/* step over space	*/

	if (!( cripid = atoi( bptr )))
		return(0);	/* whoops no exa	*/

	/* ------------ */	
	/* Test for Exa */
	/* ------------ */	
	if (!( missing_process(exapid,"client"))) {

		/* ----------------- */	
		/* Test for Criteria */
		/* ----------------- */	
		if (!( missing_process(cripid,"server") )) {
			if ( verbose ) { printf("client process ( pid = %u ) : ok \n",exapid ); }
			if ( verbose ) { printf("server process ( pid = %u ) : ok \n",cripid ); }
			}
		else	{
			/* ----------------------------------------- */
			/* Criteria is Missing so Blow Exa or Crinet */
			/* ----------------------------------------- */
			shoot_process( exapid, "client" );
			flush_access( exapid, "client" );
			flush_access( cripid, "server" );
			postexec(exapid,cripid);
			}
		}
	else	{
		/* ----------------------------------------- */
		/* Exa or Crinet is Missing so Blow Criteria */
		/* ----------------------------------------- */
		shoot_process( cripid, "server" );
		flush_access( cripid, "server" );
		flush_access( exapid, "client" );
		postexec(cripid,exapid);
		}

	return(0);

}


static	int	operation(int argc, char * argv[] )
{
	FILE	* h;
	int	status;
	int	argi;
	char *	aptr;
	int	started=0;

	for (argi=1; argi < argc; argi++ ) {
		if (!( aptr = argv[argi] ))
			continue;
		else if ( *aptr != '-' )
			continue;
		else if ((status = option( (aptr+1) )))
			return(status);
		else	continue;
		}

	/* ---------------------- */
	/* Dump the Criteria Core */
	/* ---------------------- */
	strcpy(buffer,"criteria -t > /dev/null");
	if ((status = system(buffer)) < 0) {
		return( failure(buffer) );
		}

	/* ------------------------ */
	/* Duplicate the file Quick */
	/* ------------------------ */
	sprintf(tempname,"/tmp/cc%u.tmp",getpid());
	sprintf(buffer,"mv /tmp/criteriacore %s",tempname);
	if (( status = system( buffer )) < 0 )
		return( failure(buffer) );

	/* ---------------------------------------------- */
	/* Scan the Criteria Trace File for Valid Records */
	/* ---------------------------------------------- */
	if (( h = fopen(tempname,"r")) != (FILE* ) 0) {
		while ( getcriline(h) != 0 ) {
			if ( buffer[0] != '|' )
				continue;
			else if ( buffer[1] == '-' )
				continue;
			else if (!( started )) {
				started=1;
				continue;
				}
			else if ((status = analysis()) != 0)
				break;
			else	continue;
			}
		fclose(h);

		if ( total ) {
			/* ------------------------ */
			/* Ensure Criteria Table OK */
			/* ------------------------ */
			sprintf(buffer,"criteria -n");
			if (( status = system( buffer )) < 0 )
				failure(buffer);
			}
		}
	else	{
		failure( tempname );
		}
	
	/* ------------------------- */
	/* Delete the Duplicate File */
	/* ------------------------- */
	sprintf(buffer,"rm %s",tempname);
	if (( status = system( buffer )) < 0 )
		return( failure(buffer) );
	else	return( 0 );
}


int	main(int argc, char * argv[] )
{
	if ( argc == 1 )
		return(banner(argc,argv) );
	else	return( operation(argc,argv ) );
}






