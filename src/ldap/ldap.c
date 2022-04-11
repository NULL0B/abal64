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
	printf("\t\t%s",aptr);
	if (!(vptr = ldap_get_values( handle, message, aptr)))
		ldap_perror(handle,"atb error");
	else	{
		for (	i=0; *(vptr+i) != (char *) 0; i++ ) {
			if ( i ) printf("\t\t\t");
			printf(" = %s \n",*(vptr+i));
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

public	LDAP *	DelLdap( LDAP * handle, char * criteria )
{
	LDAPMod	* mptr=(LDAPMod *) 0;
	int	e;
	char *	sptr;

	printf("ldap_delete: %s\n",criteria);
	if ((e = ldap_delete_s( handle, criteria )) != LDAP_SUCCESS ) {
		sptr = ldap_err2string( e );
		printf("\nerror: ldap_add: %u: %s \n",e,sptr);
		}
	return( handle );		

}

public	LDAP *	AddLdap( LDAP * handle, char * criteria )
{
	LDAPMod	* mptr=(LDAPMod *) 0;
	int	e;
	char *	sptr;

	if ((e = ldap_add_s( handle, criteria, &mptr )) != LDAP_SUCCESS ) {
		sptr = ldap_err2string( e );
		printf("\nerror: ldap_add: %u: %s \n",e,sptr);
		}
	return( handle );		

}

LDAP * 	WipeLdap(LDAP *h, char * sptr)
{
	char		buffer[512];
	sprintf(buffer,"ou=confAed, ou=%s, ou=confAdmin",sptr);
	DelLdap(h,buffer);
	sprintf(buffer,"ou=confOtr, ou=%s, ou=confAdmin",sptr);
	DelLdap(h,buffer);
	sprintf(buffer,"ou=confOld, ou=%s, ou=confAdmin",sptr);
	DelLdap(h,buffer);
	sprintf(buffer,"ou=confAtr, ou=%s, ou=confAdmin",sptr);
	DelLdap(h,buffer);
	sprintf(buffer,"ou=confAld, ou=%s, ou=confAdmin",sptr);
	DelLdap(h,buffer);
	sprintf(buffer,"ou=confRuntime, ou=%s, ou=confAdmin",sptr);
	DelLdap(h,buffer);
	sprintf(buffer,"ou=confVisual, ou=%s, ou=confAdmin",sptr);
	DelLdap(h,buffer);
	sprintf(buffer,"ou=confHtml, ou=%s, ou=confAdmin",sptr);
	DelLdap(h,buffer);
	sprintf(buffer,"ou=%s, ou=confAdmin",sptr);
	DelLdap(h,buffer);
	return(h);
}


/*	------------	*/
/*	Test Program	*/
/*	------------	*/


int operate( int argc, char * argv[] )
{
	LDAP	*	h=(LDAP *) 0;
	int	i;
	int	mode='L';
	char *	host=(char *) 0;
	char *	root=(char *) 0;
	char *	pass=(char *) 0;
	char *	aptr;

	if (!( h = OpenLdap( host, root, pass ) ))
		return(40);
	else	{
		for (	i=1; i < argc; i++ ) {
			if (!( aptr = argv[i] ))
				break;
			else if ( *aptr == '-' ) {
				switch ( *(aptr+1) ) {
					case	'h'	:
					case	'H'	:
						host = (aptr+2);
						continue;
					case	'r'	:
					case	'R'	:
						root = (aptr+2);
						continue;
					case	'p'	:
					case	'P'	:
						pass = (aptr+2);
						continue;

					case	'w'	:
					case	'W'	:
						mode = 'W';
						continue;
					case	'a'	:
					case	'A'	:
						mode = 'A';
						continue;
					case	'l'	:
					case	'L'	:
						mode = 'L';
						continue;
					case	'd'	:
					case	'D'	:
						mode = 'D';
						continue;
					}
				printf("\n incorrect option : %s \n",aptr);
				break;
				}
			else if ((!( h ))
			     &&  (!( h = OpenLdap( host, root, pass ) )))
				return(40);
			else	{
				switch ( mode ) {
					case	'W'	:
						if (!( h = WipeLdap( h, argv[i] )))
							break;
						else	continue;
					case	'L'	:
						if (!( h = ListLdap( h, argv[i] )))
							break;
						else	continue;
					case	'A'	:
						if (!( h = AddLdap( h, argv[i] )))
							break;
						else	continue;
					case	'D'	:
						if (!( h = DelLdap( h, argv[i] )))
							break;
						else	continue;
					default		:
						printf("\n incorrect mode : %c  for %s \n",mode,aptr);
						break;
					}
				break;
				}
			}
		if ( h )
			CloseLdap( h );
		return(0);	
		}
}

int	banner()
{
	printf("\n   Ldap Exploration Tool : Version 1.1a.0.01");
	printf("\n   Provisoire du 08/07/2003 ");
	printf("\n   Copyright (c) 2003,2006 Amenesik / Sologic \n");
	printf("\n   Usage   : ldap [ options ] [ actions ] \n");
	printf("\n   Options : \n");
	printf("\n           -a          : add action");
	printf("\n           -l          : list actions(default)");
	printf("\n           -d          : delete actions");
	printf("\n           -w          : remove all config items");
	printf("\n           -hhostname  : specify host ");
	printf("\n           -rroot      : specify root ");
	printf("\n           -ppassword  : specify password\n\n");
	return(0);
}

int main( int argc, char * argv[] )
{
	if ( argc == 1  )
		return(banner());
	else	return(operate(argc,argv));
}


