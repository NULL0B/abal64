#ifndef	_vldap_c
#define	_vldap_c

#include <stdio.h>
#include <ldap.h>

#define	_DEFAULT_LDAP_HOST 		"localhost"
#define	_DEFAULT_LDAP_USERNAME 		"cn=admin,ou=confAdmin"
#define	_DEFAULT_LDAP_OLDPASSWORD 	"admin"
#define	_DEFAULT_LDAP_PASSWORD 		"twin32"
#define	_DEFAULT_LDAP_DOMAIN 		"ou=confAdmin"
#define	private static
#define	public	

struct	ldap_controller	{
	LDAP		*	handle;
	LDAPMessage	*	result;
	LDAPMessage	*	message;
	BerElement 	* 	itember;
	int			error;
	int			messages;
	char		*	dn;
	char		*	atbname;
	char		*	atbvalue;
	int			synchronise;
	int			operation;
	int			pending;
	char 		*	domain;
	LDAPMod		**	modifications;
	};


private	struct ldap_controller * failure(struct ldap_controller * h, int ecode)
{
	char *	sptr;

	if ( h ) {
		if ( h->handle ) {
			ldap_unbind( h->handle );
			h->handle = (LDAP *) 0;
			}

		if ( h->atbvalue ) {
			liberate( h->atbvalue );
			h->atbvalue = (void*) 0;
			}
		if (!( ecode ))
			liberate( h );
		}

	return((struct ldap_controller * ) 0);
}

private	char ** BuildStringMatrix( char * vptr )
{
	int	i;
	int	pipecount=0;
	char *	sptr;
	char **	rptr;
	char ** root;
	for (	sptr=vptr; *sptr != 0; sptr++ )
		if ( *sptr == '|' )
			pipecount++;
	pipecount++;
	
	if (!( root = allocate( ((pipecount+1) * sizeof( char * )) ) ))
		return( root );
	else if (!( vptr = allocate_string( vptr ) )) {
		liberate( root );
		return( (char **) 0 );
		}
	else	{
		for (	sptr=vptr, rptr=root; 
			pipecount != 0; rptr++ ) {
			pipecount--;
			if (!( pipecount ))
				*rptr = allocate_string( sptr );
			else	{
				for ( i=0; *(sptr+i) != 0; i++ )
					if ( *(sptr+i) == '|' )
						break;
				*(sptr+i) = 0;
				*rptr = allocate_string(sptr);
				sptr += (i+1);
				}

			}
		*rptr = (char *) 0;
		liberate( vptr );
		return( root );
		}
}

private	void	AddLdapModif(struct ldap_controller * lptr, LDAPMod * mptr )
{
	LDAPMod ** nptr;
	LDAPMod ** optr;
	LDAPMod ** wptr;
	lptr->pending++;
	if (!( wptr = allocate( (lptr->pending + 1) * sizeof( LDAPMod * ) ) ))
		return;
	else if (( optr = lptr->modifications ) != (LDAPMod **) 0) {
		for (nptr=wptr; *optr != (LDAPMod *) 0; optr++, nptr++ )
			*nptr = *optr;
		liberate( lptr->modifications );
		}
	else	nptr = wptr;
	*(nptr++) = mptr;
	*nptr = (LDAPMod *) 0;
	lptr->modifications = wptr;
	return;
}

private	void	DropUpdate( 	LDAPMod	* mptr		)
{
	char **	sptr;
	
	if ( mptr ) {

		if ( mptr->mod_type )
			liberate( mptr->mod_type );

		if ((sptr = mptr->mod_vals.modv_strvals) != (char **) 0) {
			while ( *sptr != (char *) 0 )
				liberate( *(sptr++) );
			liberate( mptr->mod_vals.modv_strvals );
			}
		liberate( mptr );
		}
	return;
}



/*	---------------------------------------		*/
/*	O P E N   L D A P  ( host, user, pass )		*/
/*	---------------------------------------		*/
/*	Allocates and connects/binds to the indicated	*/
/*	ldap server user and password. Returns the	*/
/*	application ldap connection context/handle 	*/
/*	---------------------------------------		*/

public	struct ldap_controller * OpenLdap( char * host, char * credentials, char * password )
{
	struct ldap_controller * lptr;
	LDAP	*	handle=(LDAP *) 0;
	int		mid=0;

	if (!( lptr = allocate( sizeof( struct ldap_controller ) ) ))
		return( lptr );
	else	{
		lptr->handle 	= (LDAP *) 0;
		lptr->message 	= 
		lptr->result 	= (LDAPMessage *) 0;
		lptr->domain	=
		lptr->dn	=
		lptr->atbname	= 
		lptr->atbvalue	= (char *) 0;
		lptr->synchronise = 1;
		lptr->operation = 
		lptr->pending	= 
		lptr->error	=
		lptr->messages  = 0;
		lptr->itember	=(BerElement *) 0;
		lptr->modifications = (LDAPMod**) 0;
		}

	if (!( host )) 
		if (!( host = getenv("VLDAPHOST")))
			host = _DEFAULT_LDAP_HOST;

	if (!( credentials )) 
		if (!( credentials = getenv("VLDAPUSER") ))
			credentials = _DEFAULT_LDAP_USERNAME;

	if (!( password )) 
		if (!( password = getenv("VLDAPACCESS") ))
			password = _DEFAULT_LDAP_PASSWORD;

	if (!( lptr->handle = ldap_init( host, LDAP_PORT ) ))
		return( failure(lptr,0) );

	/* to be sure to be sure to be sure */
	/* -------------------------------- */
	if ((lptr->error = ldap_simple_bind_s( lptr->handle, credentials, password )) != LDAP_SUCCESS )
		if ((lptr->error = ldap_simple_bind_s( lptr->handle, credentials, _DEFAULT_LDAP_PASSWORD )) != LDAP_SUCCESS )
			if ((lptr->error = ldap_simple_bind_s( lptr->handle, credentials, _DEFAULT_LDAP_OLDPASSWORD )) != LDAP_SUCCESS )
				return( failure(lptr,lptr->error) );

	return( lptr );
}

/*	-------------------------------		*/
/*	C L O S E   L D A P  ( handle )		*/
/*	-------------------------------		*/
/*	Closes the logical LDAP access		*/
/*	controller releasing all memory.	*/
/*	-------------------------------		*/

public	void	CloseLdap( struct ldap_controller * lptr )
{
	if (!( lptr ))
		return;
	else	{
		DropLdapUpdate( lptr );	
		failure( lptr, 0 );
		}
	return;
}

/*	--------------------------------------		*/
/*	L D A P   A T B   V A L U E ( handle )		*/
/*	--------------------------------------		*/
/*	Returns a pipe '|' separated list of		*/
/*	values for the current named atribut		*/
/*	positioned in the application structure		*/
/*	as the current atribut value			*/
/*	--------------------------------------		*/

public	 struct ldap_controller * LdapAtbValue(struct ldap_controller * lptr )
{
	int	i;
	char *	sptr;
	char *	rptr;
	char	**	vptr;

	if (!(vptr = ldap_get_values( lptr->handle, lptr->message, lptr->atbname)))
		return( lptr );
	else	{
		sptr = rptr = (char *) 0;
		for (	i=0; *(vptr+i) != (char *) 0; i++ ) {
			if (!( rptr )) {
				if (!( sptr = allocate_string( *(vptr+i) ) ))
					break;
				}
			else if (!( sptr = allocate( strlen( rptr ) + strlen( *(vptr+i) ) + 16 ) ))
				break;
			else	{
				sprintf(sptr,"%s|%s",rptr,*(vptr+i));
				liberate( rptr );
				}
			rptr = sptr;
			}
		ldap_value_free( vptr );
		lptr->atbvalue = rptr;
		}
	return( lptr );
}

/*	---------------------------------------------		*/
/*	F I R S T    L D A P   A T B ( handle, crit )		*/
/*	---------------------------------------------		*/

public	 struct ldap_controller * FirstLdapAtb(struct ldap_controller * lptr, char * criteria )
{
	lptr->message = lptr->result   = (LDAPMessage *) 0;
	lptr->atbname = lptr->atbvalue = (char *) 0;

	if (!( lptr->handle ))
		return( failure(lptr,lptr->error) );
	else if ((lptr->error = ldap_search_s(lptr->handle,criteria,LDAP_SCOPE_SUBTREE,"objectclass=*",NULL,0,&lptr->result)) != LDAP_SUCCESS)
		return( failure(lptr,lptr->error) );
	else if (!(lptr->messages = ldap_count_messages(lptr->handle, lptr->result)))
		return( lptr );
	else if (!(lptr->message = ldap_first_message(lptr->handle, lptr->result )))
		return( lptr );
	else if (!(lptr->dn = ldap_get_dn(lptr->handle,lptr->message)))
		return( lptr );
	else if (!(lptr->atbname = ldap_first_attribute( lptr->handle, lptr->message, & lptr->itember )))
		return( lptr );
	else 	return( LdapAtbValue( lptr ) );
}


/*	-------------------------------------		*/
/*	N E X T    L D A P   A T B ( handle )		*/
/*	-------------------------------------		*/

public	 struct ldap_controller * NextLdapAtb(struct ldap_controller * lptr )
{
	if (!( lptr ))
		return( lptr );

	lptr->atbname = lptr->atbvalue = (char *) 0;

	if (!( lptr->message ))
		return( lptr );
	
	else if (!( lptr->handle ))
		return( failure(lptr,lptr->error) );
	else if (!(lptr->atbname = ldap_next_attribute( lptr->handle, lptr->message, lptr->itember )))
		return( lptr );

	else	return( LdapAtbValue( lptr ) );

}

/*	--------------------------------------------		*/
/*	D R O P     L D A P   U P D A T E ( handle )		*/
/*	--------------------------------------------		*/
public	 int	DropLdapUpdate(struct ldap_controller * lptr )
{
	LDAPMod	** mptr;
	if (( mptr = lptr->modifications) != (LDAPMod **) 0) {

		for (	;
			*mptr != (LDAPMod *) 0;
			mptr++ ) {
			DropUpdate( *mptr );
			}
		}

	if ( lptr->domain != (char *) 0 ) {
		liberate( lptr->domain );
		}

	lptr->domain 		= (char *) 0;
	lptr->operation		=
	lptr->pending 		= 0;
	lptr->modifications 	= (LDAPMod**) 0;
	return(0);
}

/*	----------------------------------------------------		*/
/*	S T A R T   L D A P   U P D A T E ( handle, domain )		*/
/*	----------------------------------------------------		*/
public	 int	StartLdapUpdate(struct ldap_controller * lptr, char * domain )
{
	if ( lptr->modifications ) { DropLdapUpdate( lptr ); }
	if ( domain ) {
		/* printf("LdapUpdate(dn=%s)\r\n",domain); */
		lptr->domain = allocate_string( domain );
		}
	lptr->operation = LDAP_MOD_REPLACE;
	return(0);
}

/*	----------------------------------------------------		*/
/*	S T A R T   L D A P   D E L E T E ( handle, domain )		*/
/*	----------------------------------------------------		*/
public	 int	StartLdapDelete(struct ldap_controller * lptr, char * domain )
{
	if ( lptr->modifications ) { DropLdapUpdate( lptr ); }
	if ( domain )
		lptr->domain = allocate_string( domain );
	lptr->operation = LDAP_MOD_DELETE;
	return(0);
}


/*	----------------------------------------------------		*/
/*	A D D  L D A P  S T R I N G  A T B ( handle, v, n )    		*/
/*	----------------------------------------------------		*/
public	 int	AddLdapStringAtb(struct ldap_controller * lptr, char * vptr, char * nptr )
{
	LDAPMod	* mptr;
	if (!( nptr ))
		return( 30 );
	if (!( mptr = allocate( sizeof( LDAPMod ) ) ))
		return(27);
	else if (!( mptr->mod_type = allocate_string( nptr ) )) {
		liberate( mptr );
		return( 27 );
		}
	else	{
		if ((mptr->mod_op = lptr->operation) != LDAP_MOD_DELETE) {
			if ((!( vptr ))
			||  (!( *vptr))) vptr = " ";
			/* printf("AddLdapStringAtb(%s=%s)\r\n",nptr,vptr); */
			if ( vptr )
				mptr->mod_vals.modv_strvals = BuildStringMatrix(vptr);
			else	mptr->mod_vals.modv_strvals = (char **) 0;
			}
		else	mptr->mod_vals.modv_strvals = (char **) 0;
		AddLdapModif( lptr, mptr );
		return(0);
		}
}


/*	----------------------------------------------------		*/
/*	A D D  L D A P    W O R D    A T B ( handle, v, n )    		*/
/*	----------------------------------------------------		*/
public	 int	AddLdapWordAtb(struct ldap_controller * lptr, int v, char * nptr )
{
	char	buffer[12];
	sprintf(buffer,"%u",v);
	return(AddLdapStringAtb(lptr, buffer, nptr ) );
}


/*	--------------------------------------------			*/
/*	F L U S H   L D A P   U P D A T E ( handle )       		*/
/*	--------------------------------------------			*/
public	 int	FlushLdapUpdate(struct ldap_controller * lptr )
{
	LDAPMod	** nptr;
	LDAPMod	* mptr;
	char * sptr;
	int	status;
	if (!( lptr ))
		return(0);
	else if (!( lptr->pending ))
		return(0);
	else if (!( lptr->domain ))
		return(0);
	else if (!( lptr->modifications ))
		return(0);
	else	{

		if ((lptr->error = ldap_modify_s( lptr->handle, lptr->domain, lptr->modifications )) != LDAP_SUCCESS ) {

			if ( lptr->operation != LDAP_MOD_DELETE ) {
				/* ------------------------------------------------------- */
				/* Not a delete operation so create the object if possible */
				/* ------------------------------------------------------- */
				if ( lptr->error == LDAP_NO_SUCH_OBJECT ) {
					if (( nptr = lptr->modifications ) != (LDAPMod **) 0)
						while ((mptr = *(nptr++)) != (LDAPMod *) 0)
							mptr->mod_op = LDAP_MOD_ADD;
					if ((lptr->error = ldap_add_s( lptr->handle, lptr->domain, lptr->modifications )) != LDAP_SUCCESS) {
						sptr = ldap_err2string( lptr->error );
						printf( "ldap error dn=%s: %s , %s\r\n",lptr->domain,sptr,"ldap_add_s");
						status = 66;
						}
					}
				else if ( lptr->error != LDAP_SUCCESS ) {
					sptr = ldap_err2string( lptr->error );
					printf( "ldap error dn=%s: %s , %s\r\n",lptr->domain,sptr,"ldap_modify_s");
					status = 66;
					}
				else	status = 0;
				}
			else if ( lptr->error != LDAP_NO_SUCH_OBJECT ) {
				sptr = ldap_err2string( lptr->error );
				printf( "ldap error dn=%s: %s , %s\r\n",lptr->domain,sptr,"ldap_modify_s(delete)");
				status = 0;
				}
			else	status = 0;
			}
		else	status = 0;
		DropLdapUpdate( lptr );
		return(status);
		}
}

public	int	DeleteLdap( struct ldap_controller * lptr, char * criteria )
{
	int	e;
	char *	sptr;

	if ((e = ldap_delete_s( lptr->handle, criteria )) != LDAP_SUCCESS ) {
		sptr = ldap_err2string( e );
		printf("\nerror: ldap_delete_s: %u: %s \n",e,sptr);
		return( e );
		}
	else 	return(0);
}



#endif	/* _vldap_c */
	/* -------- */


