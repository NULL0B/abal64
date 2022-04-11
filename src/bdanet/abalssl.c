#ifndef	_abalssl_c
#define	_abalssl_c

#ifdef  UNIX
#include <openssl/ossl_typ.h>
#include <openssl/x509v3.h>
#include <openssl/ssl.h>
#include <openssl/engine.h>
#include <openssl/tls1.h>
#endif

#ifdef  WINDOWS
#include <openssl\x509v3.h>
#include <openssl\ssl.h>
#include <openssl\engine.h>
#endif

#include "tlsconfig.h"

/*	-------------------------------------------------	*/
/*			A B A L    S S L			*/
/*	-------------------------------------------------	*/
/*								*/
/*	This file implements the various additional code	*/
/*	required for the operation of bdanet and  secure	*/
/*	socket layer connections.				*/
/*								*/
/*	-------------------------------------------------	*/

#define	_DEFAULT_KEYFILE  	"server.pem"
#define	_DEFAULT_PASSWORD 	"password"
#define _DEFAULT_CERTIFICATE    "root.pem"
#define _DEFAULT_CA_LIST        "calist.pem"
#define ENGINE_ID               "pkcs11"

PRIVATE	int	SSL_READY=0;
PRIVATE	int     bugfix=1;

PRIVATE	BPTR	SslKeyFile=(char *) 0;
PRIVATE	BPTR	SslCertFile=(char *) 0;
PRIVATE	BPTR	SslPassWord=(char *) 0;
PRIVATE	BPTR	SslCaList=(char *) 0;

/*      --------------- */
/*      tls_show_errors */
/*      --------------- */
PRIVATE	int     tls_show_errors( char * message,CONNECTIONPTR cptr)
{
        char SSL_ErrorBuf[1024];
        char buffer[2048];
        int     sslerr;
        int     errors=0;

        while ((sslerr = ERR_get_error()))
        {
                errors++;
                if ( ERR_error_string( sslerr, SSL_ErrorBuf ) )
                {
                        printf("SSL ERR(%s) : %lu : %s\n",message,(unsigned long)sslerr,SSL_ErrorBuf );
                }
        }
        return(errors);
}

/*	------------------------------------------------	*/
/*	   h t t p s _ u s e _ c e r t i f i c a t e       	*/
/*	------------------------------------------------	*/
/*	Called from the configuration and initialisation	*/
/*	options analyser to submit certificate name.		*/
/*	Returns zero to indicate success or other error.	*/
/*	------------------------------------------------	*/

PUBLIC	INT	https_use_certificate( BPTR aptr )
{
	if ((!( aptr )) || (!( *aptr )))
		return(0);

	if ( SslCertFile ) {
		liberate( SslCertFile );
		SslCertFile = (char *) 0;
		}
	if (!( SslCertFile = allocate_for_string( aptr )))
		return( 27 );
	else	return( 0  );
}

/*	------------------------------------------------	*/
/*	h t t p s _ u s e _ e n c r y p t i o n ( aptr )	*/
/*	------------------------------------------------	*/
/*	Called from the configuration and initialisation	*/
/*	options analyser to submit keyfile name.		*/
/*	Returns zero to indicate success or other error.	*/
/*	------------------------------------------------	*/

PUBLIC	INT	https_use_encryption( BPTR aptr )
{
	if ((!( aptr )) || (!( *aptr )))
		return(0);

	if ( SslKeyFile ) {
		liberate( SslKeyFile );
		SslKeyFile = (char *) 0;
		}
	if (!( SslKeyFile = allocate_for_string( aptr )))
		return( 27 );
	else	return( 0  );
}

/*	--------------------------------------------------	*/
/*	h t t p s _ u s e _ c e r t i f i c a t e ( aptr )	*/
/*	--------------------------------------------------	*/
/*	Called from the configuration and initialisation	*/
/*	options analyser to submit certification filename.	*/
/*	Returns zero to indicate success or other error.	*/
/*	--------------------------------------------------	*/

PUBLIC	INT	https_use_CA_list( BPTR aptr )
{
	if ((!( aptr )) || (!( *aptr )))
		return(0);
	if ( SslCaList ) {
		liberate( SslCaList );
		SslCaList = (char *) 0;
		}
	if (!( SslCaList = allocate_for_string( aptr )))
		return( 27 );
	else	return( 0  );
}

/*	------------------------------------------------	*/
/*	  h t t p s _ u s e _ p a s s w o r d ( aptr )		*/
/*	------------------------------------------------	*/
/*	Called from the configuration and initialisation	*/
/*	options analyser to submit password value.		*/
/*	Returns zero to indicate success or other error.	*/
/*	------------------------------------------------	*/

PUBLIC	INT	https_use_password( BPTR aptr )
{
	if ((!( aptr )) || (!( *aptr )))
		return(0);
	if ( SslPassWord ) {
		liberate( SslPassWord );
		SslPassWord = (char *) 0;
		}
	if (!( SslPassWord = allocate_for_string( aptr )))
		return( 27 );
	else	return( 0  );
}


/*	------------------------------------------------	*/
/*	   s s l s o c k e t r e a d e r ( h, b ,l )       	*/
/*	------------------------------------------------	*/
/*	This function performs all socket reading for		*/
/*	secure socket layer connections.			*/
/*	------------------------------------------------	*/

PUBLIC	INT	sslsocketreader( SSL * handle, BPTR buffer, INT length)
{
	INT	status;
	start_socket_catcher(handle,"ssl read");
	status = SSL_read( handle, buffer, length );
	close_socket_catcher(handle,"ssl read",errno);
	return( status );
}

/*	------------------------------------------------	*/
/*	   s s l s o c k e t w r i t e r ( h, b ,l )       	*/
/*	------------------------------------------------	*/
/*	This function performs all socket writing for		*/
/*	secure socket layer connections.			*/
/*	------------------------------------------------	*/

PUBLIC	INT	sslsocketwriter( SSL * handle, BPTR buffer, INT length)
{
	INT	status;
	start_socket_catcher(handle,"ssl write");
	status = SSL_write( handle, buffer, length );
	close_socket_catcher(handle,"ssl write",errno);
	return( status );
}

/*	------------------------------------------------	*/
/*	     s s l _ t c p _ r e a d b ( h, b ,l ) 	      	*/
/*	------------------------------------------------	*/
/*	This function reads and returns one byte from a		*/
/*	secure socket layer connection.				*/
/*	------------------------------------------------	*/

PUBLIC	INT	ssl_tcp_readb( SSL * handle )
{
	BYTE	c;
	if ( sslsocketreader( handle, ( BPTR) & c, 1 ) == 1 ) 
	{
		return( (c & 0x00FF) );
	}
	else	return( 0xFF00 );
}


/*	------------------------------------------------	*/
/*	     s s l _ t c p _ r e a d w ( h, b ,l ) 	      	*/
/*	------------------------------------------------	*/
/*	This function reads and returns one word from a		*/
/*	secure socket layer connection.				*/
/*	------------------------------------------------	*/

PUBLIC	INT	ssl_tcp_readw( SSL * handle )
{
	 INT	v;
	v = ssl_tcp_readb( handle );
	v <<= 8; v &= 0xFF00;
	v |= ssl_tcp_readb( handle );
	return( (v & 0xFFFF) );
}

/*	------------------------------------------------	*/
/*	     s s l _ t c p _ w r i t e ( h, b ,l ) 	      	*/
/*	------------------------------------------------	*/
/*	This function writes the buffer length block to		*/
/*	a secure socket layer connection.			*/
/*	------------------------------------------------	*/

PUBLIC 	INT 	ssl_tcp_write( SSL * handle, BPTR bptr, INT blen )
{
	blen = sslsocketwriter( handle, bptr, blen );
	return( blen );
}

/*	------------------------------------------------	*/
/*	     s s l _ t c p _ r e a d   ( h, b ,l ) 	      	*/
/*	------------------------------------------------	*/
/*	This function reads the buffer length block from	*/
/*	a secure socket layer connection.			*/
/*	------------------------------------------------	*/

PUBLIC	INT	ssl_tcp_read( SSL * handle, BPTR bptr, INT blen )
{
#define	_OPTIMISED_HTTP
#ifdef	_OPTIMISED_HTTP
	return( sslsocketreader( handle, bptr, blen ) );
#else
	while ( blen > 0 ) 
	{
		*(bptr++) = ssl_tcp_readb( handle );
		blen--;
	}
	return( blen );
#endif
}

/*	----------------------------	*/
/*		ssl_tcp_accept		*/
/*	----------------------------	*/
PUBLIC	INT	ssl_tcp_accept( SSL *	handle )
{
	INT	status;
	start_socket_catcher(handle,"ssl accept");
	status = SSL_accept( handle );
	close_socket_catcher(handle,"ssl accept",errno);
	if ( SSL_verbose ) 
	{
		printf("SSL_accept(pid=%u,h=%x) => %d \r\n",getpid(),handle,status);
	}
	return( status );
}

/*	----------------------------	*/
/*		ssl_tcp_connect		*/
/*	----------------------------	*/
PUBLIC	INT	ssl_tcp_connect( SSL *	handle )
{
	INT	status;
	if ( SSL_verbose ) 
	{
		printf("SSL_connect(pid=%u,h=%x)\r\n",getpid(),handle);
	}
	start_socket_catcher(handle,"ssl connect");
	status = SSL_connect( handle );
	close_socket_catcher(handle,"ssl connect",errno);
	return( status );
}

/*	----------------------------	*/
/*		ssl_tcp_shutdown	*/
/*	----------------------------	*/
PUBLIC	INT	ssl_tcp_shutdown( SSL *	handle )
{
	INT	status=0;
	if ( SSL_verbose ) 
	{
		printf("SSL_shutdown(pid=%u,h=%x)\r\n",getpid(),handle);
	}
	start_socket_catcher(-1,"ssl shutdown");
	SSL_shutdown(handle);
	close_socket_catcher(-1,"ssl shutdown",errno);
	SSL_free( handle );
	return( status );
}

/*	------------------------------------------------	*/
/*	c l o s e _ s s l _ c o n n e c t i o n ( cptr )     	*/
/*	------------------------------------------------	*/
/*	Performs all necessary operations required for		*/
/*	the correct closure of a secure socket connection.	*/
/*	------------------------------------------------	*/

PUBLIC	VOID	close_ssl_connection( CONNECTIONPTR	cptr )
{
	/* Check for an SSL object */
	/* ----------------------- */

	if ( cptr->newobject ) {
		ssl_tcp_shutdown(cptr->newobject);
		cptr->newobject = (VOID *) 0;
		}

	if ( cptr->object ) {
		ssl_tcp_shutdown(cptr->object);
		cptr->object = (VOID *) 0;
		}

	if ( cptr->context ) {
		SSL_CTX_free( cptr->context );
		cptr->context = (void *) 0;
		}
	return;
}

/*	--------------------------------	*/
/*	c h e c k _ s s l _ r e a d y ()	*/
/*	--------------------------------	*/
/* 	Check for SSL library ready for use 	*/
/*	--------------------------------	*/

PUBLIC	VOID	check_ssl_ready()
{
	if (!( SSL_READY )) {
	        SSL_load_error_strings();                /* readable error messages */
	        SSL_library_init();                      /* initialize library */
	        Portable_srandom(177);
		SSL_READY=1;
		}
	return;
}

/*	-----------------------------------------------------	*/
/*	s s l _ p a s s w o r d _ c a l l b a c k (b,n,rw,ud)	*/
/*	-----------------------------------------------------	*/
/*	This function implements, as its name suggests, the	*/
/*	password callback for the lowlevel SSL routines.	*/
/*	-----------------------------------------------------	*/

PRIVATE	INT	ssl_password_callback(char *buf,int num, int rwflag,void *userdata)
{
	if (!( SslPassWord ))
		return(0);
 	else if(num<strlen(SslPassWord)+1)
      		return(0);
	else	{
		strcpy(buf,SslPassWord);
		return(strlen(SslPassWord));
		}
}

/*	-----------------------------------------------------------	*/
/*	   s e t _ s s l _ c e r t i f i c a t e _ a n d _ k e y	*/
/*	-----------------------------------------------------------	*/
PRIVATE	CONNECTIONPTR	set_ssl_certificate_and_key( CONNECTIONPTR cptr, int mode )
{
	int	oof=0;
	return( cptr );
}

/*	-----------------------------------------------------------	*/
/*		t l s _ v e r i f y _ c a l l b a c k			*/
/*	-----------------------------------------------------------	*/
/*	this function will be called back at each certificate to be	*/
/*	informed as to how to proceed incase of failure and to have	*/
/*	application certificate verification performed as well.		*/
/*	-----------------------------------------------------------	*/
PRIVATE	int	tls_client_verify_callback( int preverify, X509_STORE_CTX * certificate )
{
	X509 *err_cert;
	char buf[256];
	int err, depth;
	SSL_CTX *sslctx;
	SSL *ssl;
	long mode;
	X509 *peer_cert;
	X509 *self_cert;
	int is_issuer_err;

	err_cert = X509_STORE_CTX_get_current_cert(certificate);
	err = X509_STORE_CTX_get_error(certificate);
	depth = X509_STORE_CTX_get_error_depth(certificate);
	ssl = X509_STORE_CTX_get_ex_data(certificate, SSL_get_ex_data_X509_STORE_CTX_idx());
	sslctx = SSL_get_SSL_CTX(ssl);
	mode = (long)SSL_CTX_get_app_data(sslctx);
	X509_NAME_oneline(X509_get_subject_name(err_cert), buf, 256);
	peer_cert = X509_STORE_CTX_get_current_cert(certificate);
	self_cert = SSL_get_certificate(ssl);;
	is_issuer_err = X509_check_issued(peer_cert, self_cert);

	if(!is_issuer_err && !(mode & _SSL_IS_ISSUER)) 
	{
		SSL_CTX_set_app_data(sslctx, (void*)(mode|_SSL_IS_ISSUER));
	}

	if (!preverify)
	{
		switch(err) 
		{
			/* List of possible codes at:
			 * http://www.openssl.org/docs/apps/verify.html#
			 */
		case X509_V_ERR_SELF_SIGNED_CERT_IN_CHAIN:
		case X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT:
			if(mode & _SSL_INTERNAL || mode & (_SSL_SELF_SIGNED|_SSL_ACCEPT_INVALID)) 
			{
				return 1;
			} 
			else 
			{
				printf("ERROR: Self-signed cert not allowed (%ld)\n", mode);
			}
			break;
		}
		return 0;
	}
	return(1);
}

/*	--------------------------	*/
/*	tls_server_verify_callback	*/
/*	--------------------------	*/
PRIVATE	int	tls_server_verify_callback( int preverify, X509_STORE_CTX * certificate )
{
	X509 *err_cert;
	char buf[256];
	int err, depth;
	SSL_CTX *sslctx;
	SSL *ssl;
	long mode;
	X509 *peer_cert;
	X509 *self_cert ;
	int is_issuer_err;

	err_cert = X509_STORE_CTX_get_current_cert(certificate);
	err = X509_STORE_CTX_get_error(certificate);
	depth = X509_STORE_CTX_get_error_depth(certificate);
	ssl = X509_STORE_CTX_get_ex_data(certificate,
	SSL_get_ex_data_X509_STORE_CTX_idx());
	sslctx = SSL_get_SSL_CTX(ssl);
	mode = (long)SSL_CTX_get_app_data(sslctx);
	X509_NAME_oneline(X509_get_subject_name(err_cert), buf, 256);
	peer_cert = X509_STORE_CTX_get_current_cert(certificate);
	self_cert = SSL_get_certificate(ssl);;
	is_issuer_err = X509_check_issued(peer_cert, self_cert);

	if(!is_issuer_err && !(mode & _SSL_IS_ISSUER)) 
	{
		SSL_CTX_set_app_data(sslctx, (void*)(mode|_SSL_IS_ISSUER));
	}

	if (!preverify) 
	{
		switch(err) 
		{
		/* List of possible codes at: * http://www.openssl.org/docs/apps/verify.html# */
		case X509_V_ERR_SELF_SIGNED_CERT_IN_CHAIN:
		case X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT:
			if(mode & _SSL_INTERNAL || mode & (_SSL_SELF_SIGNED|_SSL_ACCEPT_INVALID)) 
			{
				return 1;
			} 
			else 
			{
				printf("ERROR: Self-signed cert not allowed (%ld)\n", mode);
			}
			break;
		}
		return 0;
	}
	return(1);
}

/*	-----------------------------------------------------------	*/
/*		t l s _ c h e c k _ c e r t i f i c a t e		*/
/*	-----------------------------------------------------------	*/
typedef enum {
	MatchFound,
	MatchNotFound,
	NoSANPresent,
	MalformedCertificate,
	Error
} HostnameValidationResult;

PRIVATE HostnameValidationResult matches_common_name(const char *hostname, const X509 *server_cert) 
{
	int common_name_loc = -1;
	X509_NAME_ENTRY *common_name_entry = NULL;
	ASN1_STRING *common_name_asn1 = NULL;
	char *common_name_str = NULL;

	// Find the position of the CN field in the Subject field of the certificate
	common_name_loc = X509_NAME_get_index_by_NID(X509_get_subject_name((X509 *) server_cert), NID_commonName, -1);
	if (common_name_loc < 0) {
		return Error;
	}

	// Extract the CN field
	common_name_entry = X509_NAME_get_entry(X509_get_subject_name((X509 *) server_cert), common_name_loc);
	if (common_name_entry == NULL) {
		return Error;
	}

	// Convert the CN field to a C string
	common_name_asn1 = X509_NAME_ENTRY_get_data(common_name_entry);
	if (common_name_asn1 == NULL) {
		return Error;
	}
	common_name_str = (char *) ASN1_STRING_get0_data(common_name_asn1);

	// Make sure there isn't an embedded NUL character in the CN
	if ((size_t)ASN1_STRING_length(common_name_asn1) != strlen(common_name_str)) {
		return MalformedCertificate;
	}

	// Compare expected hostname with the CN
	//if (Curl_cert_hostcheck(common_name_str, hostname) == CURL_HOST_MATCH)
	if (!strcmp(common_name_str, hostname)) {
		return MatchFound;
	}
	else {
		return MatchNotFound;
	}
}

/*	--------------------------------	*/
/*	matches_subject_alternative_name	*/
/*	--------------------------------	*/
PRIVATE HostnameValidationResult matches_subject_alternative_name(const char *hostname, const X509 *server_cert) {
	HostnameValidationResult result = MatchNotFound;
	int i;
	int san_names_nb = -1;
	STACK_OF(GENERAL_NAME) *san_names = NULL;

	// Try to extract the names within the SAN extension from the certificate
	san_names = X509_get_ext_d2i((X509 *) server_cert, NID_subject_alt_name, NULL, NULL);
	if (san_names == NULL) {
		return NoSANPresent;
	}
	san_names_nb = sk_GENERAL_NAME_num(san_names);

	// Check each name within the extension
	for (i=0; i<san_names_nb; i++) 
	{
		const GENERAL_NAME *current_name = sk_GENERAL_NAME_value(san_names, i);

		if (current_name->type == GEN_DNS) 
		{
			// Current name is a DNS name, let's check it
			char *dns_name = (char *) ASN1_STRING_get0_data(current_name->d.dNSName);

			// Make sure there isn't an embedded NUL character in the DNS name
			if ((size_t)ASN1_STRING_length(current_name->d.dNSName) != strlen(dns_name)) 
			{
				result = MalformedCertificate;
				break;
			}
			else 
			{ // Compare expected hostname with the DNS name
				//if (Curl_cert_hostcheck(dns_name, hostname)
				//    == CURL_HOST_MATCH)
				if (!strcmp(dns_name, hostname)) 
				{
					result = MatchFound;
					break;
				}
			}
		}
	}
	sk_GENERAL_NAME_pop_free(san_names, GENERAL_NAME_free);

	return result;
}

/*	-----------------	*/
/*	validate_hostname	*/
/*	-----------------	*/
PRIVATE HostnameValidationResult validate_hostname(const char *hostname, X509 *cert) 
{
	HostnameValidationResult result;

	if((hostname == NULL) || (cert == NULL))
		return Error;

	// First try the Subject Alternative Names extension
	result = matches_subject_alternative_name(hostname, cert);
	if (result == NoSANPresent) 
	{
		// Extension was not found: try the Common Name
		result = matches_common_name(hostname, cert);
	}

	return result;
}

/*	---------------------	*/
/*	tls_check_certificate	*/
/*	---------------------	*/
PRIVATE	int	tls_check_certificate( X509_STORE_CTX * x509_ctx, void * arg )
{

	char cert_str[256];
	CONNECTIONPTR	cptr = (CONNECTIONPTR)arg;
	const char *host = cptr->hostname ? cptr->hostname : "undefined";
	const char *res_str = "tls_check_certificate() failed";
	HostnameValidationResult res = Error;
	SSL *ssl;
	STACK_OF(X509_NAME) *sk;
	int is_server = 0;
	int ok_so_far;
	X509 *peer_cert;

	if ( bugfix )
		return( 1 );

	if(cptr->newobject != NULL) 
	{
		ssl = cptr->newobject;
		is_server = 1;
		res = MatchFound; // FIXME: check for certificate hash ?
	} 
	else 
	{
		ssl = cptr->object;
	}

	/* This is the function that OpenSSL would call if we hadn't called
	 * SSL_CTX_set_cert_verify_callback().  Therefore, we are "wrapping"
	 * the default functionality, rather than replacing it.
	 * This is where tls_server_verify_callback() gets called. 
	 */

	ok_so_far = X509_verify_cert(x509_ctx);

	peer_cert = X509_STORE_CTX_get_current_cert(x509_ctx);

	X509_check_ca(peer_cert);

	/* In Server mode: We don't have the hostname, what should we check BTW ?
	 * This will be called for Azure self-signed certs AFAIK
	 * Maybe we could check an attribute of the certificate
	 */
	if (ok_so_far)
	{
		SSL_CTX *sslctx = SSL_get_SSL_CTX(ssl);
		int mode = (long)SSL_CTX_get_app_data(sslctx);
		if(mode & _SSL_SAME_CA)
		{
			if(!(mode & _SSL_IS_ISSUER))
			{
				return 0;
			}
		}
		if((mode & _SSL_MODES) >= _SSL_SELF_SIGNED)
		{
			if(is_server == 0)
			{
				res = validate_hostname(host, peer_cert);

				switch (res)
				{
				case MatchFound:
					res_str = "MatchFound";
					break;
				case MatchNotFound:
					res_str = "MatchNotFound";
					break;
				case NoSANPresent:
					res_str = "NoSANPresent";
					break;
				case MalformedCertificate:
					res_str = "MalformedCertificate";
					break;
				case Error:
					res_str = "Error";
					break;
				default:
					res_str = "WTF!";
					break;
				}
			}
		}
		else
		{
			/* do not complain if we accept invalid certificates */
			res=MatchFound;
		}
	}

	if (res == MatchFound)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*      ------------------------------------------------        */
/*      s e t u p _ e n g i n e (  )    			*/
/*      ------------------------------------------------        */
/*      Initialise an engine            			*/
/*      ------------------------------------------------        */

PRIVATE	ENGINE *setup_engine(const char *engine)
{
	ENGINE *e = NULL;

        if (engine)
        {
        	ENGINE_load_builtin_engines();
            	if ((e = ENGINE_by_id(engine)) == NULL)
              	{
                	tls_show_errors( "invalid engine",(CONNECTIONPTR) 0);
              		return NULL;
              	}
            	else if(!ENGINE_set_default(e, ENGINE_METHOD_ALL))
              	{
                	tls_show_errors( "can't use that engine",(CONNECTIONPTR) 0);
                	ENGINE_free(e);
                	return NULL;
              	}
            	ENGINE_free(e);
        }
        return e;
}

/*	------------------------------------------------	*/
/*	b u i l d _ s s l _ c o n t e x t ( cptr, mode )	*/
/*	------------------------------------------------	*/
/*	Builds and initialises a secure socket layer		*/
/*	control structure for both client and server 		*/
/*	operational modes.					*/
/*	------------------------------------------------	*/

PUBLIC	CONNECTIONPTR	build_ssl_context( CONNECTIONPTR cptr, INT mode, INT service)
{
	int			oof=0;
	void		*	fptr=(void *) 0;
        ENGINE 		*	e=NULL;
        EVP_PKEY 	* 	pkey=NULL;

	check_ssl_ready();

	/* ----------- */
	/* SSL OBJECT  */
	/* ----------- */
	if (!( SslKeyFile )) 
	{
		if (!( SslKeyFile = allocate_for_string( _DEFAULT_KEYFILE ) )) 
		{
			if ( SSL_verbose ) 
			{
				printf("SSL KeyFile : allocation failure\r\n");
			}
			return( close_connection( cptr ) );
		}
	}

	if (!( SslCertFile )) 
	{
		if (!( SslCertFile = allocate_for_string( _DEFAULT_CERTIFICATE ) )) 
		{
			if ( SSL_verbose ) 
			{
				printf("SSL KeyFile : allocation failure\r\n");
			}
			return( close_connection( cptr ) );
		}
	}

	if (!( SslCaList )) 
	{
		if (!( SslCaList = allocate_for_string( _DEFAULT_CA_LIST ) )) 
		{
			if ( SSL_verbose ) 
			{
				printf("SSL CaList : allocation failure\r\n");
			}
			return( close_connection( cptr ) );
		}
	}

	if (!( SslPassWord )) 
	{
		if (!( SslPassWord = allocate_for_string( _DEFAULT_PASSWORD ) )) 
		{
			if ( SSL_verbose ) 
			{
				printf("SSL PassWord : allocation failure\r\n");
			}
			return( close_connection( cptr ) );
		}
	}

        if ( mode & _SSL_COMPATIBLE )
        {
                if (!( fptr = (void *) SSLv23_method() ))
                {
                        tls_show_errors( "SSLv23_method",cptr );
			return( close_connection( cptr ) );
                }
        }
        else if (!( fptr = (void *) TLS_method() ))
        {
                tls_show_errors( "TLS_method",cptr );
		return( close_connection( cptr ) );
        }

	if (!(cptr->context = SSL_CTX_new(fptr) )) 
	{
		if ( SSL_verbose ) 
		{
			printf("SSL CTX new : failure\r\n");
		}
		return( close_connection( cptr ) );
	}

        SSL_CTX_set_mode (cptr->context, SSL_MODE_ENABLE_PARTIAL_WRITE);
        SSL_CTX_set_mode (cptr->context, SSL_MODE_AUTO_RETRY);
        SSL_CTX_set_app_data(cptr->context, (void*)(long)mode);

	/* Server Side Only */
	/* ---------------- */
        if (!( mode & _SSL_INTERNAL ))
        {
                /* ----------------------------------------------- */
                /* set the custom certificat check callback method */
                /* ----------------------------------------------- */
                SSL_CTX_set_cert_verify_callback( cptr->context, tls_check_certificate, cptr );
        }
        else
        {
                /* ------------------------------------------- */
                /* set the standard certificate check callback */
                /* ------------------------------------------- */
                SSL_CTX_set_cert_verify_callback( cptr->context, NULL, cptr );
        }

       	if ( mode & _DER_CERTIFICATE )
       	{
       	        if (!(oof=SSL_CTX_use_certificate_file( cptr->context, SslCertFile, SSL_FILETYPE_ASN1)))
       	        {
       	                tls_show_errors( "SSL_use_certificate_chain_file",cptr );
			return( close_connection( cptr ) );
       	        }
        }

	if (!(oof=SSL_CTX_use_certificate_chain_file(cptr->context, SslCaList ))) 
	{
		if ( SSL_verbose ) 
		{
			printf("SSL CTX use certificate chain file : failure \r\n");
		}
		return( close_connection( cptr ) );
	}

	SSL_CTX_set_default_passwd_cb(cptr->context,ssl_password_callback);

	if ( mode & _OPENSSL_ENGINE )
	{
                /* setup engine pkcs11 */
                if (!( e = setup_engine(ENGINE_ID) ))
			return( close_connection( cptr ) );

                else if (!( pkey = ENGINE_load_private_key(e, SslKeyFile, NULL, NULL) ))
                {
                        tls_show_errors( "ENGINE_load_private_key",cptr );
                        ENGINE_free(e);
			return( close_connection( cptr ) );
                }
                else if (!(oof = SSL_CTX_use_PrivateKey(cptr->context,pkey)))
                {
                        tls_show_errors( "SSL_CTX_use_PrivateKey",cptr );
                        ENGINE_free(e);
			return( close_connection( cptr ) );
                }
                EVP_PKEY_free(pkey);
                ENGINE_free(e);
        }
        else
        {
                if (!(oof = SSL_CTX_use_PrivateKey_file(
       				cptr->context, SslKeyFile,
				(mode & _DER_KEY ? SSL_FILETYPE_ASN1 : SSL_FILETYPE_PEM) ) ))
               	{
               	        tls_show_errors( "SSL_CTX_use_PrivateKey_file",cptr );
			return( close_connection( cptr ) );
               	}
       	}

        if ( SslCaList )
        {
                if (!(SSL_CTX_load_verify_locations(cptr->context,SslCaList, 0)))
                {
                        /* if this is not a file, try a directory */
                        if (!(SSL_CTX_load_verify_locations(cptr->context, 0, SslCaList)))
                        {
                                tls_show_errors( "SSL_CTX_load_verify_locations",cptr );
				return( close_connection( cptr ) );
                        }
                }
        }

        else if (!( mode &  _DER_CERTIFICATE ))
        {
                if (!(SSL_CTX_load_verify_locations(cptr->context,SslCertFile, 0)))
                {
                        tls_show_errors( "SSL_CTX_load_verify_locations",cptr );
			return( close_connection( cptr ) );
                }
        }

#if (OPENSSL_VERSION_NUMBER < 0x00905100L)
        SSL_CTX_set_verify_depth(cptr->context,1);
#endif
        if(!SSL_CTX_check_private_key(cptr->context)) 
	{
                printf("Private key does not match the public certificate\n");
		return( close_connection( cptr ) );
        }

        if (!( cptr->object = SSL_new( cptr->context ) ))
        {
                tls_show_errors( "SSL_new",cptr );
		return( close_connection( cptr ) );
        }
        if((mode & _SSL_MODES) >= _SSL_SAME_CA) {
                mode |= _REQUIRE_PEER;
        } else if((mode & _SSL_MODES) >= _SSL_SELF_SIGNED) {
                mode |= _REQUEST_PEER;
        } else {
                mode &= ~(_REQUIRE_PEER|_REQUEST_PEER);
        }

        if ( mode & _REQUIRE_PEER )
                SSL_set_verify( cptr->object,SSL_VERIFY_FAIL_IF_NO_PEER_CERT|SSL_VERIFY_PEER,tls_client_verify_callback);
        else if ( mode & _REQUEST_PEER )
                SSL_set_verify( cptr->object,SSL_VERIFY_PEER|SSL_VERIFY_CLIENT_ONCE,tls_client_verify_callback);
        else    SSL_set_verify( cptr->object,SSL_VERIFY_NONE,tls_client_verify_callback);

	return( cptr );
}

/*      ----------------------------------------------------------      */
/*              t l s _ v a l i d a t e _ s e r v e r                   */
/*      ----------------------------------------------------------      */
PUBLIC	int     tls_validate_server( SSL * handle, int mode )
{
        X509 *cert;
        int res;
        if(mode & _REQUIRE_PEER)
        {
                if (!( cert = SSL_get_peer_certificate(handle) ))
                {
                        printf("SSL_accept(pid=%u,h=%p) => No peer certificate %d \r\n",getpid(),handle,-1);
                        return -1;
                }
                X509_free(cert);
        }
        if ((res=SSL_get_verify_result(handle)) != X509_V_OK)
        {
                switch(res)
                {
                /* List of possible codes at: http://www.openssl.org/docs/apps/verify.html# */
                /* ------------------------------------------------------------------------ */
                case X509_V_ERR_SELF_SIGNED_CERT_IN_CHAIN:
                case X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT:
                        if(mode & _SSL_INTERNAL || mode & (_SSL_SELF_SIGNED|_SSL_ACCEPT_INVALID))
                        {
                                printf("SSL accepting self-signed cert\n");
                                return 0;
                        }
                        else
                        {
                                printf("SSL refusing self-signed cert\n");
                        }
                        break;
                }
                printf("SSL_accept(pid=%u,h=%p) => Bad peer certificate %d \r\n",getpid(),handle,res);
                return -1;
        }
        return 0;
}

/*      ----------------------------------------------------------      */
/*              t l s _ c l i e n t _ h a n d s h a k e                 */
/*      ----------------------------------------------------------      */

PUBLIC	int     tls_client_handshake( CONNECTIONPTR cptr, int mode, char * hostname )
{
        int     status;

        if (!( build_ssl_context( cptr, mode, 0 ) ))
        {
                printf( "tls_client_handshake failed due to build SSL Context failure\n" );
                return(0);
        }
        else
        {
		//security_lock( 0, "client_set_fd" );
		SSL_set_tlsext_host_name(cptr->object, hostname );
        	status = SSL_set_fd( cptr->object, cptr->socket );
        	//security_unlock( 0, "client_set_fd" );
        	if (!( status ))
        	{
        		tls_show_errors("SSL_set_fd",(CONNECTIONPTR) 0);
        	        return(0);
		}
		else if ((status = ssl_tcp_connect( cptr->object )) < 0 )
		{
			tls_show_errors("SSL_connect<0",(CONNECTIONPTR) 0);
			return(0);
		}
		else if (!( status ))
		{
			tls_show_errors("SSL_connect==0",(CONNECTIONPTR) 0);
			return(1);
		}
		else if (!( tls_validate_server( cptr->object, mode ) ))
		{
			//printf("SSL_connect(%u) handshake OK\n",mode);
			return(1);
		}
		else
		{
			tls_show_errors("incorrect client certificate",(CONNECTIONPTR) 0);
			return(0);
		}
	}
}	



#endif	/* _abalssl_c */
	/* ---------- */


