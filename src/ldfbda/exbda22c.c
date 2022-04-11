#ifndef	_exbda_c
#define	_exbda_c

#include <dlfcn.h>
#include "bda.h"

static	char * default_library_path=(char *) "/lib";

void *	allocate(int);
void *	liberate(void *);

char *	allocate_string(char * sptr)
{
	char * rptr;
	if (( rptr = allocate( (strlen(sptr) + strlen(".so") + strlen(default_library_path) + 16) )) !=( char *) 0)
		sprintf(rptr,"%s/%s.so",default_library_path,sptr);
	return(rptr);
}

		

#define	GOODRESULT	1
#define	SOFTERROR	0
#define	HARDERROR	0xFFFF

#define	BPTR EXABYTE PTR

extern	EXAWORD	err_val;

struct	ex_ldf_bda	{
	BPTR	name;
	EXAWORD	number;
	EXAWORD	nature;
	VOID *	handle;
	EXAWORD (*initialise)();
	EXAWORD (*execute)();
	VOID (*terminate)();
	};



int	get_dl_option()
{
	if ( getenv("BDADLGLOBAL") != (char*) 0)
		return( RTLD_NOW | RTLD_GLOBAL );
	else	return( RTLD_NOW );
}

struct ex_ldf_bda PTR LdfBdaTable[MAX_BDA] = {
	0,0,0,0,0,0,0,0,0,0
	};

static	struct ex_ldf_bda * release_context( struct ex_ldf_bda * cptr )
{
	if ( cptr ) {
		if ( cptr->name )
			cptr->name = liberate( cptr->name );
		if ( cptr->handle )
			dlclose( cptr->handle );
		cptr = liberate( cptr );
		}
	return( (struct ex_ldf_bda *) 0 );
}

static	bda_result( EXAWORD evalue, struct ex_ldf_bda * cptr )
{
	if (!( err_val = evalue ))
		return( GOODRESULT );
	else	{
		if ( cptr )
			cptr = release_context( cptr );
		return( SOFTERROR );
		}
}

/* #define _DEBUG_ASFUN_BDA */
#ifdef 	_DEBUG_ASFUN_BDA

extern	EXAWORD	AsfunLdfBdaInitialise();
extern	EXAWORD	AsfunLdfBdaExecute();
extern	EXAWORD	AsfunLdfBdaTerminate();
#endif

/* #define _DEBUG_TTY_BDA */
#ifdef 	_DEBUG_TTY_BDA

extern	EXAWORD	TTYLdfBdaInitialise();
extern	EXAWORD	TTYLdfBdaExecute();
extern	EXAWORD	TTYLdfBdaTerminate();
#endif

char * getenv(char *);

EXAWORD InitRunTime(	EXAWORD handle, BPTR filename, EXAWORD option, 			
			BDA_INIT PTR descriptor,EXAWORD descsize )
{
	struct ex_ldf_bda *	context;
	int			status=0;
	char *			sleepcounter;
	
	/* Allocate Dynamic Library Control Structure */
	/* ------------------------------------------ */
	if (!(context = allocate( sizeof( struct ex_ldf_bda ) )))
		return( bda_result(27,context) );

	/* Allocate for storage of Library Name */
	/* ------------------------------------ */
	else if (!(context->name = allocate_string(filename))) 
		return( bda_result(27,context) );

#ifdef _DEBUG_ASFUN_BDA
	if ( strcmp(filename,"asfun") == 0 ) {
		context->initialise = AsfunLdfBdaInitialise;
		context->execute    = AsfunLdfBdaExecute;
		context->terminate  = AsfunLdfBdaTerminate;
		context->handle     = 0;
		}
#endif
#ifdef	_DEBUG_TTY_BDA
	else if ( strcmp(filename,"tty") == 0 ) {
		context->initialise = TTYLdfBdaInitialise;
		context->execute    = TTYLdfBdaExecute;
		context->terminate  = TTYLdfBdaTerminate;
		context->handle     = 0;
		}

#endif	

	
	/* Attempt to load the Dynamic library */
	/* ----------------------------------- */
	else if (!(context->handle = dlopen( context->name, get_dl_option() ))) {
#ifdef	LDF_BDA_TESTER
		printf("\nerror::dlopen(%s)::%s\n",context->name, dlerror());
#else
		if ((sleepcounter = getenv("SHOWDLERROR")) != (char *) 0) {
			printf("\r\nDlError(%s) after dlopen(%s) : %s\r\n\r\n",dlerror(),filename);
			sleep(atoi(sleepcounter));
			}
#endif
		return( bda_result(135,context) );
		}

	/* Attempt to locate the Library Initialisation Function */
	/* ----------------------------------------------------- */
	else if (!(context->initialise = dlsym( context->handle, "LdfBdaInitialise"))) {
#ifdef	LDF_BDA_TESTER
		printf("\nerror::dlsym(%s,%s)::%s\n",context->name,"LdfBdaInitialise",dlerror());
#else
		if ((sleepcounter = getenv("SHOWDLERROR")) != (char *) 0) {
			printf("\r\nDlError(%s) after dlsym(LdfBdaInitialise)\r\n\r\n",dlerror());
			sleep(atoi(sleepcounter));
			}
#endif
		return( bda_result(136,context) );
		}

	/* Attempt to locate the Library Execution Interface Function */
	/* ---------------------------------------------------------- */
	else if (!(context->execute = dlsym( context->handle, "LdfBdaExecute"))) {
#ifdef	LDF_BDA_TESTER
		printf("\nerror::dlsym(%s,%s)::%s\n",context->name,"LdfBdaExecute",dlerror());
#else
		if ((sleepcounter = getenv("SHOWDLERROR")) != (char *) 0) {
			printf("\r\nDlError(%s) after dlsym(LdfBdaExecute)\r\n\r\n",dlerror());
			sleep(atoi(sleepcounter));
			}
#endif
		return( bda_result(137,context) );
		}

	/* Attempt to locate the Library Liberation Function */
	/* ------------------------------------------------- */
	else if (!(context->terminate = dlsym( context->handle, "LdfBdaTerminate"))) {
#ifdef	LDF_BDA_TESTER
		printf("\nerror::dlsym(%s,%s)::%s\n",context->name,"LdfBdaTerminate",dlerror());
#else
		if ((sleepcounter = getenv("SHOWDLERROR")) != (char *) 0) {
			printf("\r\nDlError(%s) after dlsym(LdfBdaTerminate)\r\n\r\n",dlerror());
			sleep(atoi(sleepcounter));
			}
		return( bda_result(138,context) );
#endif
		}
		
		
#ifdef	LDF_BDA_TESTER
	return( bda_result(0,(context=release_context(context))) );
#else
	/* ---------------------------------------------------- */
	/* ALL LIBRARIES ARRIVE HERE TO DO THIS BIT			    */
	/* ---------------------------------------------------- */

	/* Call through to the library initialisation function */
	/* --------------------------------------------------- */
	if ((status = (*context->initialise)(descriptor,descsize)) != 0) {
		if ((sleepcounter = getenv("SHOWDLERROR")) != (char *) 0) {
			printf("\r\n  status(%u) after context->initialise \r\n\r\n",status);
			sleep(atoi(sleepcounter));
			}
		return( bda_result( status, context ) );
		}

	else	{
		/* Store the context to Dynamic Library Table and return SUCCESS */
		/* ------------------------------------------------------------- */
		LdfBdaTable[(context->number =handle)] = context;
		return( descriptor->cico.signature );
		}
#endif
}

EXAWORD CallRunTime(EXAWORD handle, EXAWORD nbfunction, EXAWORD argc, EXABYTE FAR bptr[], VOID FAR PTR FAR pptr[], EXAWORD FAR wptr[] )
{
	struct ex_ldf_bda *	context;

	/* Validate handle parameter */
	/* ------------------------- */
	if (handle >= MAX_BDA)
		return( bda_result( 138, (struct ex_ldf_bda *) 0) );

	/* Validate Table Entry */
	/* -------------------- */
	else if (!( context = LdfBdaTable[handle] ))
		return( bda_result( 138, (struct ex_ldf_bda *) 0) );

	/* Validate Context Interface */
	/* -------------------------- */
	else if (!( context->execute ))
		return( bda_result( 138, (struct ex_ldf_bda *) 0) );

	/* Execute required function */
	/* ------------------------- */
	else 	return( (*context->execute) (nbfunction, argc, bptr, pptr, wptr) );
}

EXAWORD FinRunTime(EXAWORD handle)
{
	struct ex_ldf_bda *	context;

	/* Validate handle parameter */
	/* ------------------------- */
	if (handle >= MAX_BDA)
		return( bda_result( 138, (struct ex_ldf_bda *) 0) );

	/* Validate Table Entry */
	/* -------------------- */
	else if (!( context = LdfBdaTable[handle] ))
		return( bda_result( 138, (struct ex_ldf_bda *) 0) );

	/* Validate Destructor Interface */
	/* ----------------------------- */
	else if (!( context->terminate ))
		return( bda_result( 138, context ) );
	else	{
		/* Perform Destruction */
		/* ------------------- */
		(*context->terminate)();
		return( bda_result(0,(context=release_context(context))) );
		}

}

#ifdef	LDF_BDA_TESTER
int	main(int argc, char * argv[]) 
{
	int	argi;
	int	retcode=0;
	if ( argc == 1 )
		printf("\n   ABAL Dynamic/Shared Library Tester : Version 1.1a\n   Copyright (c) 2001,2006 Amenesik / Sologic \n\n");
	else	{
		for ( argi=1; argi < argc; argi++ )  {
			if ((retcode = InitRunTime(1,argv[argi],0,(void *) 0, 0)) != GOODRESULT) {
				printf("error:%u library:%s\n",err_val,argv[argi]);
				}
			else	{
				printf("library %s ok\n",argv[argi]);
				}
			}
		}
	return(0);
}
#endif
#endif	/* _exbda_c */



