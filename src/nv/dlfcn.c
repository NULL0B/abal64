#include <stdio.h>
#include "dlfcn.h"
#include "bda.h"

static WORD LdfBdaInitialise(BDA_INIT FAR PTR dptr, WORD dlen)
{
	printf("arrival in LdfBdaInitialise\n");

	return(0);
}

static WORD LdfBdaExecute(WORD f, WORD n, BYTE FAR * aptr, VOID FAR PTR FAR * bptr, WORD FAR * vptr)
{
	printf("arrival in LdfBdaExecute(id=%u,nbarg=%u)\n",f,n);
	return(0);
}


static VOID LdfBdaTerminate()
{
	printf("arrival in LdfBdaTerminate\n");
	return;
}


void *dlopen ( char *__file, int __mode)
{
	return( __file );
}


int dlclose (void *__handle)
{
	return(0);	
}

void *dlsym (void * __handle, char * __name)
{

	if ( compare( __name, "LdfBdaInitialise" ) )
		return( LdfBdaInitialise );
	else if ( compare( __name, "LdfBdaExecute" ) )
		return( LdfBdaExecute );
	else if ( compare( __name, "LdfBdaTerminate" ) )
		return( LdfBdaTerminate );
	else	return( (void *) 0 );

}



