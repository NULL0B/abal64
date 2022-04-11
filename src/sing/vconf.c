#ifndef	_visual_config_c
#define	_visual_config_c

#include <stdio.h>

#include "vconf.h"

#ifdef	SYSTEM_LDAP
#include "vldap.c"
#endif

private	struct configuration_node * NodeHeap=(struct configuration_node *) 0;
public	char * system_fontpath=(char* )0;
public	char * system_stylepath=(char* )0;
public	char * system_imagepath=(char* )0;
public	char * system_navigator=(char* )0;
public	char * system_docpath=(char* )0;
public	char * system_palette=(char* )0;
public 	char	fontbuffer[256];

#define	confAdmin "confAdmin"
#define	confStandard "languageAbal"
#define	_VISUAL_LDAP_ROOT " ou=languageAbal, ou=confAdmin"


private	int 	cfc( char * aptr, char * bptr )
{
	while (( *aptr ) && ( *bptr )) {
		if ( *aptr != *bptr )
			break;
		else	{
			aptr++;
			bptr++;
			}
		}
	if ( *aptr != *bptr )
		return(0);
	else	return(1);
}

private	int	gcn( FILE * h, char * rptr )
{
	int	i;
	int	c;
	for (	i=0; i < MAX_CONF_NAME; i++ ) {
		switch  (( c = fgetc(h))) {
			case	0	:
			case	-1	:
				return(48);
			case	'='	:
				break;
			default		:
				*(rptr+i) = c;
				continue;
			}
		break;
		}
	*(rptr+i) = 0;
	if ( c != '=' )
		return(30);
	else	return(0);
}

public	char *	get_system_stylepath()
{
	if ( system_stylepath )
		return( system_stylepath );
#ifdef WIN32
	else return( confgetenv( "STYLEPATH" ) );
#else
	else 	return( getenv( "STYLEPATH" ) );
#endif
}

public	char *	get_system_palette()
{
	if ( system_palette )
		return( system_palette );
#ifdef WIN32
	else 	return( confgetenv( "PALETTE" ) );
#else
	else 	return( getenv( "PALETTE" ) );
#endif
}

public	int	configuration_value( char * nptr, char * vptr )
{
	struct configuration_node * iptr;

	/* Detect and replace existing values */
	/* ---------------------------------- */
	for (	iptr=NodeHeap;
		iptr != (struct configuration_node*) 0;
		iptr = iptr->next ) {
		if ( cfc( iptr->name , nptr ) ) {
			if ( iptr->value )
				iptr->value = liberate( iptr->value );
			if (!( iptr->value = allocate_string( vptr )))
				return(27);
			else	return(0);
			}
		}
	/* Add a New Variable */
	/* ------------------ */
	if (( iptr = allocate( sizeof( struct configuration_node ))) != (struct configuration_node *) 0) {
		if ((iptr->name = allocate_string( nptr )) != (char *) 0 ) {
			if ((iptr->value = allocate_string( vptr )) != (char *) 0 ) {
				iptr->next = NodeHeap;
				NodeHeap = iptr;
				return(0);
				}
			iptr->name = liberate( iptr->name );
			}
		iptr = liberate( iptr );
		}
	return( 27 );
}

public	int	prefixed_configuration_value( char * pptr, char * nptr, char * vptr )
{
	int	status=0;
	char *	rptr;
	if (!( nptr )) 
		return(30);
	else if (!( pptr ))
		return( configuration_value( nptr, vptr ) );
	else if (!( rptr = allocate( strlen( pptr ) + strlen( nptr ) + 8 ) ))
		return( 27 );
	else	{
		sprintf(rptr,"%s.%s",pptr,nptr);
		status = configuration_value( rptr, vptr );
		liberate( rptr );
		return( status );
		}
}


private	int	gcv( FILE * h, char * nptr, char * rptr )
{
	int	i;
	int	c;
	for (	i=0; i < MAX_CONF_VALUE; i++ ) {
		switch (( c = fgetc(h))) {
			case	'\r'	:
				continue;
			case	0	:
			case	-1	:
			case	'\n'	:
				break;
			case	'\t'	:
				c = ' ';
			default		:
				*(rptr+i) = c;
				continue;
			}
		*(rptr+i) = 0;
		return( configuration_value(nptr, rptr) );
		}
	return(63);
}


public	char	*	configuration_item( char * tptr )
{
	struct configuration_node * nptr;

	for (	nptr=NodeHeap;
		nptr != (struct configuration_node*) 0;
		nptr = nptr->next ) {
		if ( cfc( nptr->name , tptr ) )
			return( nptr->value );
		}
	return((char *) 0);
}

public	int		configuration_integer( char * tptr )
{
	char *	sptr;
	int	result=0;
	if (!( sptr = configuration_item( tptr ) ))
		return(0);
	else 	{
		while ( *sptr ) {
			if (( *sptr >= '0' ) && ( *sptr <='9')) 
				result = ((result*10) + (*(sptr++)-'0'));
			else	break;
			}
		return( result );
		}	
}

#ifdef	SYSTEM_LDAP
public	int	load_from_ldap( 
	struct	ldap_controller * lptr,
	char * criteria, 
	char * prefix 
	)
{
	int	i=0;
	if (( lptr = FirstLdapAtb( lptr,criteria )) != (struct ldap_controller *) 0) {
		do	{
			if (!( lptr->atbname ))
				break;
			if ( prefixed_configuration_value( prefix, lptr->atbname, lptr->atbvalue ) != 0 )
				break;
			else	i++;
			}
		while (( lptr = NextLdapAtb( lptr )) != (struct ldap_controller *) 0);
		}
	return(i);		
}

public	int	load_visual_ldap( char * hptr, char * nptr, char * pptr )
{
	char	*		bptr;
	struct	ldap_controller * lptr;
	char	*		confRoot=(char *) 0;
	if (!( confRoot = allocate_string( _VISUAL_LDAP_ROOT ))) 
		return( 27 );
	else if (!( lptr = OpenLdap( hptr, (char *) 0, (char *) 0 ) )) {
		liberate( confRoot );
		return(40);
		}
	else 	{
		if ((bptr = allocate( 1024 )) != (char *) 0) {
			sprintf(bptr,"ou=confVisual, ou=conf%s, %s",nptr,confRoot);
			load_from_ldap( lptr, bptr, pptr );
			liberate( bptr );
			}
		CloseLdap( lptr );
		return(0);
		}
}

public	int	load_document_ldap( char * hptr, char * nptr, char * pptr )
{
	char	*		bptr;
	struct	ldap_controller * lptr;
	char	*		confRoot=(char *) 0;
	if (!( confRoot = allocate_string( _VISUAL_LDAP_ROOT ))) 
		return( 27 );
	if (!( lptr = OpenLdap( hptr, (char *) 0, (char *) 0 ) )) {
		liberate( confRoot );
		return(40);
		}
	if ((bptr = allocate( 1024 )) != (char *) 0) {
		sprintf(bptr,"ou=confHtml, ou=conf%s, %s",nptr,confRoot);
		load_from_ldap( lptr, bptr, pptr );
		liberate( bptr );
		CloseLdap( lptr );
		return(0);
		}
}

#endif

public	int		configuration_test( char * rootname )
{
	FILE	*	h;
	char	*	nbuffer;
	char	*	vbuffer;
	int		status;
	char	*	nptr;

	if (!(  nptr = allocate( strlen( rootname ) + 16 ) ))
		return( 27 );
	else 	sprintf(nptr,"%s.cfg",rootname);

	if (!(h = fopen( nptr, "r")))
		return(0);
	else	{
		fclose(h);
		return(1);
		}
}


public	int		configuration_load( char * rootname )
{
	FILE	*	h;
	char	*	nbuffer;
	char	*	vbuffer;
	int		status;
	char	*	nptr;

	if (!(  nptr = allocate( strlen( rootname ) + 16 ) ))
		return( 27 );
	else 	sprintf(nptr,"%s.cfg",rootname);

	if ((h = fopen( nptr, "r")) != (FILE*)0) {
		if ((nbuffer = allocate( MAX_CONF_NAME+1 )) != (char *) 0) {
			if ((vbuffer = allocate( MAX_CONF_VALUE+1 )) != (char *) 0) {
				while (!(status = gcn( h, nbuffer )))
					if ((status = gcv( h,nbuffer,  vbuffer )) != 0)
						break;
				if ( status == 48 ) status=0;
				vbuffer = liberate( vbuffer );
				}
			else	status=27;
			nbuffer = liberate( nbuffer );
			}
		else	status=27;
		fclose( h );
		}
	else	status=40;
	liberate( nptr );
	return(status);
}

public	int		configuration_save( char * fptr )
{
	FILE	*	h;
	int		status;
	struct configuration_node * nptr;

	if ((h = fopen( fptr, "w")) != (FILE*)0) {

		for (	nptr=NodeHeap;
			nptr != (struct configuration_node*) 0;
			nptr = nptr->next ) {
			fprintf(h,"%s=%s\r\n",nptr->name,nptr->value);
			}
#ifndef	UNIX
		fputc(0x001A,h);
#endif
		fclose( h );
		}
	else	status=40;
	return(status);
}

public	void	configuration_drop( void )
{
	struct configuration_node * nptr;

	while ((nptr=NodeHeap) != (struct configuration_node*) 0) {
		NodeHeap = nptr->next;
		if ( nptr->name )
			nptr->name = liberate( nptr->name );
		if ( nptr->value )
			nptr->value = liberate( nptr->value );
		nptr = liberate( nptr );
		}

	return;
}

#endif	/* _visual_config_c */



