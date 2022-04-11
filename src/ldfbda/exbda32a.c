#ifndef	_exbda_c
#define	_exbda_c

#include <dlfcn.h>
#include "bda.h"

static	char * default_library_path=(char *) "/lib";

#define	ALSMID "exbda"
#include "allocate.h"

extern	EXAWORD err_val;

char *	getenv(char *);

static int	compare_dll_names( char * aptr, char * bptr )
{
	int	i;
	for ( i=0; *(aptr+i) != 0; i++ ) {
		if (!( *(bptr+i) ))
			break;
		else if ( *(aptr+i) != *(bptr+i) )
			break;
		}
	if ( *(aptr+i) != *(bptr+i) )
		return(0);
	else	return(1);
}

char *	allocate_for_bdaname(char * sptr)
{
	char * rptr;
#ifdef	VERSION666
	if (( rptr = allocate( (strlen(sptr) + strlen("32.so") + strlen(default_library_path) + 16) )) !=( char *) 0)
		sprintf(rptr,"%s/%s32.so",default_library_path,sptr);
#else
	if (( rptr = allocate( (strlen(sptr) + strlen(".so") + strlen(default_library_path) + 16) )) !=( char *) 0)
		sprintf(rptr,"%s/%s.so",default_library_path,sptr);
#endif
	return(rptr);
}


#define	GOODRESULT	1
#define	SOFTERROR	0
#define	HARDERROR	0xFFFF
#define	MAX_BDA_SO	256

#define	BPTR BYTE PTR

extern	EXAWORD	err_val;

struct	ex_ldf_bda	{
	BPTR	name;
	BPTR	program;
	EXAWORD	number;
	EXAWORD	nature;
	EXAWORD	users;
	BDA_INIT PTR descriptor;
	VOID *	handle;
	EXAWORD (*initialise)();
	EXAWORD (*execute)();
	VOID 	(*terminate)();
	VOID 	(*information)();
	};



int	get_dl_option()
{
	if ( getenv("BDADLGLOBAL") != (char*) 0)
		return( RTLD_NOW | RTLD_GLOBAL );
	else	return( RTLD_NOW );
}

struct ex_ldf_bda PTR LdfBdaTable[MAX_BDA_SO] = {
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	};

static	struct ex_ldf_bda * release_context( struct ex_ldf_bda * cptr )
{
	if ( cptr ) {
		if ( cptr->name )
			cptr->name = liberate( cptr->name );
		if ( cptr->program )
			cptr->program = liberate( cptr->program );
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

#ifdef 	_DEBUG_ASFUN_BDA

extern	WORD	AsfunLdfBdaInitialise();
extern	WORD	AsfunLdfBdaExecute();
extern	WORD	AsfunLdfBdaTerminate();
#endif

/* #define _DEBUG_VISUAL_BDA */
#ifdef 	_DEBUG_VISUAL_BDA

extern	WORD	VisualLdfBdaInitialise();
extern	WORD	VisualLdfBdaExecute();
extern	WORD	VisualLdfBdaTerminate();
#endif

/* #define _DEBUG_TTY_BDA */
#ifdef 	_DEBUG_TTY_BDA

extern	WORD	TTYLdfBdaInitialise();
extern	WORD	TTYLdfBdaExecute();
extern	WORD	TTYLdfBdaTerminate();
#endif

EXAWORD CheckRunTime(	EXAWORD uhandle, 
			BPTR filename, 
			EXAWORD option, 			
			EXAWORD PTR xhandle,
			BPTR progname, 
			BDA_INIT PTR descriptor,
			EXAWORD descsize )
{
	struct ex_ldf_bda *	context;
	int			status=0;
	char *			sleepcounter;
	int			lhandle=0;
	char *			tempname;
	/* Scan Table to find a matching entry */
	if (!( tempname = allocate_for_bdaname( filename ) ))
		return(bda_result(27,0));
	for ( lhandle=0; lhandle < MAX_BDA_SO; lhandle++ ) {
		if (!( context = LdfBdaTable[lhandle] ))
			continue;
		else if ( compare_dll_names( tempname, context->name ) ) {
			*xhandle = lhandle;
			memcpy( descriptor, context->descriptor, descsize );
			context->users++;
			break;
			}
		}
	return(1);
}

EXAWORD InitRunTime(	EXAWORD uhandle, 
			BPTR filename, 
			EXAWORD option, 			
			EXAWORD PTR xhandle,
			BPTR progname, 
			BDA_INIT PTR descriptor,
			EXAWORD descsize )
{
	struct ex_ldf_bda *	context;
	int			status=0;
	char *			sleepcounter;
	int			lhandle=0;
	char *			tempname;
	/* Scan Table to find a matching entry */
	if (!( tempname = allocate_for_bdaname( filename ) ))
		return(bda_result(27,0));
	for ( lhandle=0; lhandle < MAX_BDA_SO; lhandle++ ) {
		if (!( context = LdfBdaTable[lhandle] ))
			continue;
		else if ( compare_dll_names( tempname, context->name ) ) {
			*xhandle = lhandle;
			memcpy( descriptor, context->descriptor, descsize );
			context->users++;
			return( BDA_ORDINAIRE  /* descriptor->cico.signature : whoops asfun et z */  );
			}
		}
	/* Scan Table to find a free entry */
	for ( lhandle=0; lhandle < MAX_BDA_SO; lhandle++ )
		if (!( LdfBdaTable[lhandle] ))
			break;
	if ( lhandle >= MAX_BDA_SO )
		return(bda_result(138,0));

	/* Allocate Dynamic Library Control Structure */
	/* ------------------------------------------ */
	if (!(context = allocate( sizeof( struct ex_ldf_bda ) )))
		return( bda_result(27,context) );

	context->program = (BPTR) 0;
	if (!( context->name = tempname )) 
		return( bda_result(27,context) );
	/* Allocate for storage of Library Program */
	/* --------------------------------------- */
	else if (!(context->program = allocate_for_bdaname((progname != (BPTR) 0 ? progname : filename)))) 
		return( bda_result(27,context) );

	/* Attempt to load the Dynamic library */
	/* ----------------------------------- */
	else if (!(context->handle = dlopen( 
			context->program,
			get_dl_option() ))) {
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
	else if (!( context->information = dlsym( context->handle, "LdfBdaInformation"))) {
		return( bda_result(0,(context=release_context(context))) );
		}
	else	{
		(*context->information)((void*) 0);
		return( bda_result(0,(context=release_context(context))) );
		}
#else
	/* ------------------------------------------------------------------------------ */
	/* A cause des bugs dans dl open il va falloir lister toutes les symbols chez lui */
	/* et les symboles chez moi et s'il y un, seulement un qui a le meme non il va se */
	/* faire jeter en erreur 135 mais pour faire ca ca nest pas mon boulot c'est le   */
	/* boulot de dlopen !!! cunt !!!						  */
	/* ------------------------------------------------------------------------------ */
#ifdef	FAIRE_LE_BOULOT_DE_DLOPEN
	if ((status = FaireLeBoulotDeDlOpen( context->handle )) != 0)
		return( bda_result( status, context ) );
#endif
	
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
		LdfBdaTable[lhandle] = context;
		context->number = uhandle;
		*xhandle = lhandle;
		context->users = 1;
		context->descriptor = descriptor;
		return( descriptor->cico.signature );
		}
#endif
}

EXAWORD CallRunTime(
		EXAWORD handle, 
		EXAWORD nbfunction, 
		EXAWORD argc, BYTE FAR bptr[], 
		VOID FAR PTR FAR pptr[], 
		EXAWORD FAR wptr[] )
{
	struct ex_ldf_bda *	context;
	EXAWORD			result;

	/* Clear the Error Variable */
	err_val = 0;

	/* Validate handle parameter */
	/* ------------------------- */
	if (handle >= MAX_BDA_SO)
		return( bda_result( 138, (struct ex_ldf_bda *) 0) );

	/* Validate Table Entry */
	/* -------------------- */
	else if (!( context = LdfBdaTable[handle] ))
		return( bda_result( 138, (struct ex_ldf_bda *) 0) );

	/* Validate Context Interface */
	/* -------------------------- */
	else if (!( context->execute ))
		return( bda_result( 138, (struct ex_ldf_bda *) 0));

	/* Execute required function */
	/* ------------------------- */
	else 	return((result = (*context->execute) (nbfunction, argc, bptr, pptr, wptr, &err_val)) );
}

EXAWORD RunTimeUsers(EXAWORD handle)
{
	struct ex_ldf_bda *	context;

	/* Validate handle parameter */
	/* ------------------------- */
	if (handle >= MAX_BDA_SO)
		return( -1 );

	/* Validate Table Entry */
	/* -------------------- */
	else if (!( context = LdfBdaTable[handle] ))
		return( -1 );

	return( context->users );
}

EXAWORD FinRunTime(EXAWORD handle)
{
	struct ex_ldf_bda *	context;

	/* Validate handle parameter */
	/* ------------------------- */
	if (handle >= MAX_BDA_SO)
		return( bda_result( 138, (struct ex_ldf_bda *) 0) );

	/* Validate Table Entry */
	/* -------------------- */
	else if (!( context = LdfBdaTable[handle] ))
		return( bda_result( 138, (struct ex_ldf_bda *) 0) );

	if ( context->users )
		context->users--;

	if ( context->users )
		return( GOODRESULT );
		
	/* Validate Destructor Interface */
	/* ----------------------------- */
	if (!( context->terminate ))
		return( bda_result( 138, context ) );
	else	{
		/* Perform Destruction */
		/* ------------------- */
		(*context->terminate)();
		LdfBdaTable[handle] = (void*) 0;
		return( bda_result(0,(context=release_context(context))) );
		}

}

#endif	/* _exbda_c */



