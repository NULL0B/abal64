
#ifndef	_singpack_c
#define	_singpack_c

struct	package_item	{
	struct	package_item 	* next;
	char			* filename;
	};
static struct package_item * PackageItem = (struct package_item *) 0;

static	int	PackageOption=0;
static	FILE *	PackageHandle=(FILE*)0;
static	char *	PackageName=(char *) 0;

public	void	initialise_project_package_control(char * target,int mode)
{
	char *	tptr=(char *) 0;
	PackageItem = (struct package_item *) 0;
	PackageOption= mode;
	if (method_is_valid(target)) {
		if ((PackageName = allocate_string( target )) != (char *) 0)
			PackageName = enforce_extension(PackageName,".mf");
		}
	else	PackageName=(char *) 0;
	return;
}

public	void	terminate_project_package_control()
{
	char 	* tptr;
	struct	package_item * pptr;

	if ( PackageName ) 
		if ((PackageHandle = fopen(PackageName,"w")) != (FILE*) 0)
			PackageOption=2;

	if ( PackageOption & 1 ) {
		printf("Package %s : {\r\n",PackageName);
		}
	if ( PackageOption & 2 ) {
		if ((tptr = allocate_string(PackageName)) != (char *) 0) {
#ifdef	WIN32
			if ((tptr = enforce_extension( tptr,".zip")) != (char *) 0) {
#endif
#ifdef	UNIX
			if ((tptr = enforce_extension( tptr,".tgz")) != (char *) 0) {
#endif
				fprintf(PackageHandle,"%s: ",tptr );
				liberate( tptr );
				}
			}
		}

	while (( pptr=PackageItem ) != (struct package_item *) 0) {

		if ( PackageOption & 1 )
			printf("\t%s\r\n",pptr->filename);
		if ( PackageOption & 2 )
			fprintf(PackageHandle," %c\r\n        %s",0x0027,pptr->filename);
		PackageItem = pptr->next;
		if ( pptr->filename )
			liberate( pptr->filename );
		liberate( pptr );
		}

	if ( PackageOption & 1 ) {
		printf("\t}\r\n");
		}
	if ( PackageOption & 2 ) {
#ifdef	WIN32
		fprintf(PackageHandle,"\r\n\tzip $@ $?\r\n!make\r\n");
#endif
#ifdef	UNIX
		fprintf(PackageHandle,"\r\n\ttar -czvf $@ $?\r\n!make\r\n");
#endif
		}
	if ( PackageHandle ) {
		fclose( PackageHandle );
		PackageHandle = (FILE *) 0;
		}
	if ( PackageName ) {
		liberate( PackageName );
		PackageName = (char *) 0;
		}
	PackageOption = 0;
	return;
}

private	char *	resolve_package_item( char * sptr, int mode )
{
	FILE	*	h;
	int		i;
	char *	nptr;
	char *	bptr;

	if (!( sptr ))
		return( sptr );

	else if ((h = fopen(sptr,"r")) != (FILE*) 0) {
		fclose(h);
		return(sptr);
		}

	else if (!( mode ))
		return( sptr );

	/* ------------ */
	/* its an image */
	/* ------------ */
#ifdef	WIN32
	else if ( *sptr == '\\' )
		return( sptr );
	else if ( *sptr == '.' )
		return( sptr );
#else
	else if ( *sptr == '/' )
		return( sptr );
	else if ( *sptr == '.' )
		return( sptr );
#endif
	else	{
		i=1;
		while ((nptr = resolve_imagename_by_number( i++ )) != (char *) 0) {
			bptr = allocate_string( nptr );
			fn_parser(nptr,bptr,0x0018);
			if (!( strcmp( bptr, sptr ) )) {
				liberate( sptr );
				strcpy( bptr, nptr );
				sptr = bptr;
				break;
				}
			else	liberate( bptr );
			}
		return( sptr );
		}
		

}

public	void	add_project_package_item( char * sptr, int type )
{
	struct	package_item * pptr;

	if ( sptr ) {
		if (!( sptr = resolve_package_item( sptr, type )))
			return;
		for ( pptr=PackageItem; pptr != (struct package_item *) 0; pptr = pptr->next ) {
			if (!( pptr->filename ))
				continue;
			else if (!( strcmp( pptr->filename, sptr ) )) {
				liberate( sptr );
				return;
				}
			}
		if (!( pptr = allocate( sizeof( struct package_item ) ) )) {
			liberate( sptr );
			return;
			}
		else if (!( pptr->filename = sptr )) {
			liberate( pptr );
			return;
			}
		pptr->next = PackageItem;
		PackageItem = pptr;
		}
	return;
}
#endif	/* _singpack_c */
	/* ----------- */

