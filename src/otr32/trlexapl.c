#ifndef	_TRLEXAPL_C
#define	_TRLEXAPL_C

struct	library_extension	{
	TCSTRUCTPTR 	class;
	struct library_extension * next;
	};

static	WORD	LibraryExtension=0;
static 	struct	library_extension *	LexRoot=(struct library_extension *) 0;
static	struct	library_extension *	LexFoot=(struct library_extension *) 0;

static	WORD	library_extension_class( class )
TCSTRUCTPTR 	class;
{
	struct	library_extension * lptr;
	if (!( lptr = allocate( sizeof( struct library_extension ) ) ))
		return( allocation_failure() );
	lptr->class = class;
	lptr->next = (struct library_extension *) 0;	/* #BG */
	if (!( LexFoot ))
		LexRoot = lptr;
	else	LexFoot->next = lptr;
	LexFoot = lptr;
	return(0);
}

static	WORD	instance_library_overlay()
{
	WORD	status;
	LibraryExtension=0;
	if ((status = start_program_or_module( _CONTEXT_PROGRAM )) != 0 )
		return( status );
	else	return( translate_end() );
}

static	WORD	instance_library_module()
{
	struct	library_extension * lptr;
	struct	library_extension * rptr;
	WORD	status;
	LibraryExtension=0;
	if (!( rptr = LexRoot ))
		return(0);
	/* Keep Debug File for Module */
	OtrOption.Symbolic |= 1;
	OtrOption.ExternCommon=1;
	if (( status = start_program_or_module( _CONTEXT_MODULE  )) != 0)
		return( status );
	while ((lptr = rptr) != (struct	library_extension *) 0) {
		rptr = lptr->next;
		if ( lptr->class ) {
			if ( OtrOption.Verbose  )
				sysprintf("Module Class : %s\n",lptr->class->name);
			if ((status = flush_module_commons( lptr->class ))!= 0)
				return(status);
			if ((status = declare_module_methods((TCVARPTR) 0,lptr->class )) != 0)
				return( status );
			}
		liberate( lptr );
		}
	return( translate_end() );
}


static	WORD	instance_library_extension()
{
/* #BG240506 Begin */
	BYTE	TcodeFileName[128];
	BYTE	identity[15];
	WORD	i=0;

	TCDLBPTR pDLT;
	TCDLBPTR pXDLT;

	terminate_tcode_production();

	strcpy(TcodeFileName, Context->TcodeFileName);
	while ( i < 15 )
		identity[i++] = *(Context->identity + i);

//	liberate_tcode_context();
	pDLT = Context->DLT;
	pXDLT = Context->XDLT;

/*	initialise_tcode_context(Context->TcodeFileName ); */
	initialise_tcode_context(TcodeFileName, identity);

	Context->DLT = pDLT;
	Context->XDLT = pXDLT;
	Context->count_DLT = 3;
/* #BG240506 End */

	switch ( LibraryExtension ) {
		case	1	:	/* overlay */
			return( instance_library_overlay() );
		case	2	:	/* module  */
			return( instance_library_module() );
		default		:
			LibraryExtension=0;
			return(0);
		}
}

#endif	/* _TRLEXAPL_C */
	/* ----------- */

