#include <stdio.h>
#include <ldap.h>

#define	_DEFAULT_LDAP_HOST 	"172.17.111.88"
#define	_DEFAULT_LDAP_USERNAME 	"cn=admin,ou=confAdmin"
#define	_DEFAULT_LDAP_PASSWORD 	"admin"
#define	_DEFAULT_LDAP_DOMAIN 	"ou=confAdmin"
#define	private static
#define	public	

private	LDAP *	failure(LDAP * h, int ecode)
{
	char *	sptr;

	if ( ecode != 0 ) {
		if ((sptr = ldap_err2string(ecode)) != (char *) 0)
			printf("failure : %s \n",sptr);
		}

	if ( h ) {
		ldap_unbind( h );
		}
	return((LDAP *) 0);
}

/*	---------------------------------------		*/
/*	O P E N   L D A P  ( host, user, pass )		*/
/*	---------------------------------------		*/

public	LDAP *	OpenLdap( char * host, char * credentials, char * password )
{
	LDAP	*	handle=(LDAP *) 0;
	int		mid=0;

	if (!( host )) 
		host = _DEFAULT_LDAP_HOST;

	if (!( credentials )) 
		credentials = _DEFAULT_LDAP_USERNAME;

	if (!( password )) 
		password = _DEFAULT_LDAP_PASSWORD;

	if (!( handle = ldap_init( host, LDAP_PORT ) ))
		return( failure(handle,0) );

	else if ((mid = ldap_simple_bind_s( handle, credentials, password )) != LDAP_SUCCESS )
		return( failure(handle,mid) );

	else	return( handle );
}

/*	-------------------------------		*/
/*	C L O S E   L D A P  ( handle )		*/
/*	-------------------------------		*/

public	void	CloseLdap( LDAP * handle )
{
	failure(handle,0);
	return;
}

/*	----------------------------------	*/
/*	L I S T  L D A P  ( handle, base )	*/
/*	----------------------------------	*/

public	void	AtbValueLdap( LDAP * handle, LDAPMessage * message, char * aptr )
{
	int		i;
	int		ecode;
	char	**	vptr;
	printf("\t\tatb( %s )\n",aptr);
	if (!(vptr = ldap_get_values( handle, message, aptr)))
		ldap_perror(handle,"atb error");
	else	{
		for (	i=0; *(vptr+i) != (char *) 0; i++ ) {
			printf("\t\t\t= %s \n",*(vptr+i));
			}
		ldap_value_free( vptr );
		}
	return;
}
	
public	void	AtbListLdap( LDAP * handle, LDAPMessage * message )
{
	char	*	sptr;
	BerElement * item=(BerElement *) 0;
	if ((sptr = ldap_first_attribute( handle, message, & item)) != (char *) 0 ) {
		do	{
			AtbValueLdap(handle,message,sptr);
			}
		while ((sptr = ldap_next_attribute( handle, message, item)) != (char *) 0 );
		ber_free( item,0 );
		}
	return;
}
	
		
public	LDAP *	ListLdap( LDAP * handle, char * criteria )
{
	int	nb;
	int	r;
	int	mid;
	LDAPMessage *mptr=NULL;
	LDAPMessage *message=NULL;
	char *	sptr;

	if ((mid = ldap_search_s(handle,criteria,LDAP_SCOPE_SUBTREE,"objectclass=*",NULL,0,&mptr)) != LDAP_SUCCESS)
		return( failure(handle,mid) );
	else if ((nb = ldap_count_messages(handle, mptr)) != 0) {
		if ((message = ldap_first_message( handle, mptr )) != (LDAPMessage *)0) {
			printf("\nListLdap( %s ) {\n",criteria);
			do	{
				if ((sptr = ldap_get_dn(handle,message)) != (char *) 0) {
					printf("\tdn( %s )\n",sptr);
					ldap_memfree( sptr );
					AtbListLdap(handle,message);
					}
				else	break;
				}
			while ((message = ldap_next_message( handle, message )) != (LDAPMessage *)0);
			printf("\t}\n");
			}
		}
	return(handle);
}


/*	------------	*/
/*	Test Program	*/
/*	------------	*/


int operate( int argc, char * argv[] )
{
	LDAP	*	h;
	int	i;

	if (!( h = OpenLdap( (char *) 0,(char *) 0, (char *) 0 ) ))
		return(40);
	else	{
		for (	i=1; i < argc; i++ ) {
			if (!( h = ListLdap( h, argv[i] )))
				break;
			}
		CloseLdap( h );
		return(0);	
		}
}

int	banner()
{
	printf("\n   Ldap Exploration Tool : Version 1.1a.0.01");
	printf("\n   Provisoire du 27/09/2006 ");
	printf("\n   Copyright (c) 2006 Amenesik / Sologic \n");
	printf("\n   Usage : l host user password \n\n");
	return(0);
}

int main( int argc, char * argv[] )
{
	if ( argc == 1  )
		return(banner());
	else	return(operate(argc,argv));
}


