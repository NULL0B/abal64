#ifndef	_exdll_h
#define	_exdll_h

#include "xmlparse.h"
#include "exos.h"
#include "extypes.h"
#include "exvtype.h"

struct	abal_program_handle 	{
	int	(*stop) (struct abal_program_handle *);
	int	(*procedure) (struct abal_program_handle *,int);
	int	(*segment) (struct abal_program_handle *,int);
	int	(*parameter) (struct abal_program_handle *,int,int,void *);
	char *	(*result) (struct abal_program_handle *,int *, int*);
	int	(*resolve)(struct abal_program_handle *, char *);
	int	(*interface)(struct abal_program_handle *, char *, char *, char *);
	int	(*xmlparser)( char * filename, struct xml_relay * interfaceitem, void * application );
	int	(*parametertype)(struct abal_program_handle *, char **, int , int );
	int	procedures;
	int	segments;
	int	registers;
	char *	program;
	};

struct	abal_program_handle *	LoadAbalProgram( char* program, int options );

EXAWORD	resolve_callback_procedure( char * );
EXAWORD	argset(EXAWORD,EXAWORD,EXAWORD);

#endif	/* _exdll_h */
	/* -------- */


