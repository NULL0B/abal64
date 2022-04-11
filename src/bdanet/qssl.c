#include <openssl/ssl.h>
#include <openssl/bio.h>
#include <signal.h>

void *	bio_err = (void*) 0;

void	sigpipe_handler (int sid )
{
	printf("sig pipe handle : %u\n",sid);
	return;
}

SSL_CTX * initialise_ctx(char * passwd, char *keyfile)
{
	SSL_METHOD * method;
	SSL_CTX    * ctx;
	if (!( bio_err )) {
		SSL_library_init();
		SSL_load_error_strings();
		bio_err = BIO_new_fp(stderr,BIO_NOCLOSE);
		}
	signal(SIGPIPE,sigpipe_handler);
	method = SSLv23_method();
	ctx    = SSL_CTX_new(method);
	return( ctx );
}

int	main(int argc, char * argv[])
{
	SSL_CTX * ctx;
	if (!( ctx = initialise_ctx("passwd","keyfile")))
		return(0);
	else	
}

