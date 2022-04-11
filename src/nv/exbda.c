#ifndef	_exbda_c
#define	_exbda_c

#include "dlfcn.h"
#include "bda.h"

void * 	malloc(int n);
void	free(void*v);

extern	int	debug;

void *	allocate(int n )
{
	return( malloc(n) );
}

void *	liberate(void * p)
{
	if ( p )
		free(p);
	return((void *) 0);
}
char *	allocate_string(char * sptr)
{
	char * rptr;
	if (( rptr = allocate( strlen(sptr) + 1 ))!=(char *) 0)
		strcpy(rptr,sptr);
	return(rptr);
}

		

#define	GOODRESULT	1
#define	SOFTERROR	0
#define	HARDERROR	0xFFFF

#define	BPTR BYTE PTR

extern	WORD	err_val;

struct	ex_ldf_bda	{
	BPTR	name;
	WORD	number;
	WORD	nature;
	VOID *	handle;
	WORD (*initialise)();
	WORD (*execute)();
	VOID (*terminate)();
	};

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

static	bda_result( WORD evalue, struct ex_ldf_bda * cptr )
{
	if (!( err_val = evalue ))
		return( GOODRESULT );
	else	{
		if ( cptr )
			cptr = release_context( cptr );
		return( SOFTERROR );
		}
}

WORD InitRunTime(	WORD handle, BPTR filename, WORD option, 			
			BDA_INIT PTR descriptor,WORD descsize )
{
	struct ex_ldf_bda *	context;
	int			status=0;
	if ( debug )
		printf("InitRunTime(%u,%s)\n",handle,filename);

	/* Allocate Dynamic Library Control Structure */
	/* ------------------------------------------ */
	if (!(context = allocate( sizeof( struct ex_ldf_bda ) )))
		return( bda_result(27,context) );

	/* Allocate for storage of Library Name */
	/* ------------------------------------ */
	else if (!(context->name = allocate_string(filename))) 
		return( bda_result(27,context) );

	/* Attempt to load the Dynamic library */
	/* --------------------------------------
	else if (!(context->handle = dlopen( context->name, 
		(context->nature = ( ! option ? RTLD_LOCAL : RTLD_GLOBAL )))) 
		return( bda_result(135,context) );

	/* Attempt to locate the Library Initialisation Function */
	/* ----------------------------------------------------- */
	else if (!(context->initialise = dlsym( context->handle, "LdfBdaInitialise")))
		return( bda_result(136,context) );

	/* Attempt to locate the Library Execution Interface Function */
	/* ---------------------------------------------------------- */
	else if (!(context->execute = dlsym( context->handle, "LdfBdaExecute")))
		return( bda_result(137,context) );

	/* Attempt to locate the Library Liberation Function */
	/* ------------------------------------------------- */
	else if (!(context->terminate = dlsym( context->handle, "LdfBdaTerminate")))
		return( bda_result(138,context) );

	/* Call through to the library initialisation function */
	/* --------------------------------------------------- */
	else if ((status = (*context->initialise)(descriptor,descsize)) != 0)
		return( bda_result( status, context ) );

	/* Store the context to Dynamic Library Table and return SUCCESS */
	/* ------------------------------------------------------------- */
	else	{
		LdfBdaTable[(context->number =handle)] = context;
		return( bda_result( 0, (struct ex_ldf_bda *) 0) );
		}
	
}

WORD CallRunTime(WORD handle, WORD nbfunction, WORD argc, BPTR pptr , BPTR lptr , BPTR tptr )
{
	struct ex_ldf_bda *	context;

	/* Validate handle parameter */
	/* ------------------------- */
	if ((handle < 0) || (handle >= MAX_BDA))
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
	else 	return( (*context->execute) (nbfunction, argc, pptr, lptr, tptr) );
}

WORD FinRunTime(WORD handle)
{
	struct ex_ldf_bda *	context;

	/* Validate handle parameter */
	/* ------------------------- */
	if ((handle < 0) || (handle >= MAX_BDA))
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


#endif	/* _exbda_c */



