#ifndef	_singprod_c
#define	_singprod_c
#include <errno.h>
#include <sys/stat.h>
#define	MAX_PRODUCTION	10

static	PermissionControl=-1;

private	struct	production_control	{
	FILE	*	handle[MAX_PRODUCTION];
	char	*	realname[MAX_PRODUCTION];
	char	*	tempname[MAX_PRODUCTION];
	} NameControl;


private	char *	PerformLock=(char *) 0;
private	char *	PerformUnLock=(char *) 0;

public	void	initialise_production_control()
{
	int	i;
	for ( i=0; i < MAX_PRODUCTION; i++ ) {
		NameControl.realname[i] = NameControl.tempname[i] = (char * ) 0;
		NameControl.handle[i] = (FILE *) 0;
		}
	return;
}


private	void	reset_production_control(int i)
{
	if ( NameControl.handle[i] )
		fclose(NameControl.handle[i]);
	if ( NameControl.realname[i] )
		liberate( NameControl.realname[i] );
	if ( NameControl.tempname[i] )
		liberate( NameControl.tempname[i] );
	NameControl.realname[i] = NameControl.tempname[i] = (char * ) 0;
	NameControl.handle[i] = (FILE *) 0;
	return;
}
	
public	void	release_production_control()
{
	int	i;
	for ( i=0; i < MAX_PRODUCTION; i++ ) {
		reset_production_control(i);
		}
	return;
}

public	void	set_standard_lock_unlock(char * lptr, char * uptr )
{
	if ( PerformLock ) {
		liberate( PerformLock );
		PerformLock = (char *) 0;
		}
	if ( lptr ) {
		PerformLock = allocate_string( lptr );
		}

	if ( PerformUnLock ) {
		liberate( PerformUnLock );
		PerformUnLock = (char *) 0;
		}
	if ( uptr ) {
		PerformUnLock = allocate_string( uptr );
		}
}

public	int	standard_file_unlock( char * nptr, int type )
{
	char	* xptr;
	char	* sptr;
	if ((!( sptr = PerformUnLock )) && (!( sptr = configuration_item("UNLOCKFILE"))))
		return(0);
	else if (!( xptr = allocate( strlen(nptr) + 64 )))
		return(27);
	else	{
		sprintf(xptr,"%s %s",sptr,nptr);
		if (system(xptr)== -1)
			system_failure( xptr );

		liberate( xptr );
		return(0);
		}
}

public	int	standard_file_lock( char * nptr, int type )
{
	char	* xptr;
	char	* sptr;
	if ((!( sptr = PerformLock )) && (!( sptr = configuration_item("LOCKFILE"))))
		return(0);
	else if (!( xptr = allocate( strlen(nptr) + 64 )))
		return(27);
	else	{
		sprintf(xptr,"%s %s",sptr,nptr);
		if ( system(xptr) == -1)
			system_failure( xptr );

		liberate( xptr );
		return(0);
		}
}

public	int	standard_file_permission( char * nptr, int type )
{
	char *	eptr;
	FILE * h;
	struct stat fileperms;
	int	status;

#ifdef	WIN32
	
	if ( PermissionControl == -1 ) {
		if (!( eptr = confgetenv("SINGPERM"))) 
			PermissionControl = 0;
		else	PermissionControl = 1;
		}

	if ( PermissionControl & 1 )
	{
		if ((status = stat( nptr, &fileperms )) != -1) 
			return (fileperms.st_mode & _S_IWRITE) ? 1 : 0;
		else
			return 1;
	}

	return(1);

#else
	if ( PermissionControl == -1 ) {
		if (!( eptr = confgetenv("SINGPERM")))
			PermissionControl = 0;
		else	PermissionControl = 1;
		}
#ifdef	ROOTROOT
	if ( getuid() == 0 ) {
		if ( PermissionControl & 1 )
			printf("permission(%s) : root\r\n",nptr);
		return(1);
		}
#endif

	if ((status = stat( nptr, &fileperms )) != -1) {
		if (fileperms.st_uid == getuid()) {
			if ( PermissionControl & 1 )
				printf("file permission(%s) : user %u\r\n",nptr,fileperms.st_mode & S_IWUSR);
			if ( fileperms.st_mode & S_IWUSR )
				return(1);
			}
		if (fileperms.st_gid == getgid()) {
			if ( PermissionControl & 1 )
				printf("file permission(%s) : group %u\r\n",nptr,fileperms.st_mode & S_IWGRP);
			if ( fileperms.st_mode & S_IWGRP )
				return(1);
			}
		if ( PermissionControl & 1 )
			printf("file permission(%s) : other %u\r\n",nptr,fileperms.st_mode & S_IWOTH);
		if ( fileperms.st_mode & S_IWOTH )
			return(1);
		else	return(0);
		}
	else	{
		if ( PermissionControl & 1 )
			printf("permission(%s) : no stat\r\n",nptr);
		return(1);
		}
#endif
}


/*	--------------------------------------------------------------		*/
/*	o p e n _ p r o d u c t i o n _ t a r g e t ( filename, mode )		*/
/*	--------------------------------------------------------------		*/

public	FILE *	open_production_target(
	char *	filename,
	int	mode )		/* 0 : ASCII, 1, BINARY */
{
	FILE	*	h=(FILE *) 0;
	int		i;
	char		tempname[64];

	if (!( filename )) 
		return((FILE*) 0);

	else if (!( *filename ))
		return((FILE*) 0);

	else 	{
		while (!( standard_file_permission( filename, 0 ) )) 
			if ( report_accept_error( "write protection failure", filename ) == 27 )
				return((FILE*) 0);
		}

	/* Locate a free production target */
	/* ------------------------------- */
	for (	i=0; i < MAX_PRODUCTION; i++ )
		if (!( NameControl.handle[i] ))
			break;

	/* Too many nested production targets */
	/* ---------------------------------- */
	if (( i >= MAX_PRODUCTION )) 
		return((FILE *) 0);
	else	reset_production_control(i);

#ifdef	UNIX
	while (1) {
		if ( Access( filename, 0, 1 ) != 0 )
			break;
		else if ( errno != 44 )
			break;
		else if ( fileshare_failure( filename ) != 27 )
			continue;
		else	return( (FILE *) 0 );
		}
#endif
	/* Allocate storage for real file name */
	/* ----------------------------------- */
	if (!( NameControl.realname[i] = allocate_string( filename )))
		return((FILE *) 0);

#ifdef	UNIX
	/* Allocate Storage for Temporary filename */
	/* --------------------------------------- */
	unique_filename( tempname );

	if (!( NameControl.tempname[i] = allocate_string( tempname ) ))
		return((FILE *) 0);

	/* Attempt to create temporary work file */
	/* ------------------------------------- */
	while (!(h = fopen(tempname,(mode & 1 ? "wb" : "w"))))
		if ( creation_failure( tempname ) == 27 )
			break;

	(void) Access( tempname, 0, 1 );
#else
	/* Attempt to create temporary work file */
	/* ------------------------------------- */
	while (!(h = fopen(filename,(mode & 1 ? "wb" : "w"))))
		if ( creation_failure( filename ) == 27 )
			break;
#endif
	return((NameControl.handle[i] = h));

}

/*	---------------------	*/
/*	s i n g _ r e n a m e 	*/
/*	---------------------	*/
private	void	unix_sing_rename( char * src, char * tgt )
{
	char	buffer[2048];
	sprintf(buffer,"mv %s %s",src,tgt);
	system( buffer );
	return;
}

/*	------------------------------------------------------------------	*/
/*	c l o s e _ p r o d u c t i o n _ t a r g e t ( handle, filename )	*/
/*	------------------------------------------------------------------	*/

public	void	close_production_target( FILE * h, char * nptr )
{
	FILE *	wh=(FILE*)0;
	int	i;
	char *	wptr;
	/* Locate the production control entry for this name */
	/* ------------------------------------------------- */
	for (i=0; i < MAX_PRODUCTION; i++ ) 
		if ( string_compare( NameControl.realname[i], nptr ) )
			break;

	/* whoooopsss ...	*/
	/* -------------------- */
	if (( i >= MAX_PRODUCTION )) return;

	if ( NameControl.handle[i] != (FILE *) 0 ) 
	{
		fflush(h);
		fclose(h);
		NameControl.handle[i] = (FILE *) 0;
#ifdef	UNIX
		liberlox(NameControl.tempname[i]);
		liberlox(NameControl.realname[i]);
		if ((wptr = allocate( strlen(NameControl.tempname[i])+strlen(NameControl.realname[i])+64)) != (char *) 0) 
		{
			if ((wh = fopen(NameControl.realname[i],"r")) != (FILE *) 0) 
			{
				fclose(wh);
				sprintf(wptr,"%s.bak",NameControl.realname[i]);
				unix_sing_rename( NameControl.realname[i], wptr );
			}
				
			unix_sing_rename( NameControl.tempname[i],NameControl.realname[i] );
			liberate( wptr );
		}
#endif
	}
	reset_production_control(i);
	return;
}

/*	-----------------------------------------	*/
/*	 Inclusion of standard production methods	*/
/*	-----------------------------------------	*/
#include "vtype.c"


#endif	/* _singprod_c */
	/* ----------- */

