/* --------------------------------------------------------------------	*/
/*	          							*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1991,1995 Amenesik / Sologic s.a.	*/
/*									*/
/*									*/
/*		File	:	TRUSER.C				*/
/*		Version :	2.1d					*/
/*		Date	:	21/02/1995				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef _TRUSER_C
#define _TRUSER_C

#include "trbda.h"
#include "truser.h"

BYTE	DllTrBuffer[512];
WORD	DllTrIndex=0;

/*	--------------	*/
/*	CallTranslator	*/
/*	--------------	*/
static	WORD	CallTranslator( function )
WORD	function;
{
	if ( DllStatus != MOINS_UN ) 
	{
		DllTypes[DllParameters]    = 0;
		DllLengths[DllParameters]  = 0;
		DllPointers[DllParameters] = (BPTR) 0;
		return( CallRunTime( 0, function, DllParameters,(BPTR)  DllTypes,(BPTR XPTR)  DllPointers,(WPTR)  DllLengths) );
	}
	else	return( 135 );
}

/*	-------------	*/
/*	no_parameters	*/
/*	-------------	*/
static	VOID	no_parameters()
{
	DllParameters = 0;
	return;
}

/*	------------	*/
/*	next_pointer	*/
/*	------------	*/
static	VOID	next_pointer( nptr )
BPTR	nptr;
{
	DllPointers[DllParameters] = nptr;
	DllLengths [DllParameters] = (strlen(nptr)+1);
	DllTypes[DllParameters++ ] = 0x0083;
	return;
}

/*	-------------	*/
/*	first_pointer	*/
/*	-------------	*/
static	VOID	first_pointer( nptr )
BPTR	nptr;
{
	no_parameters();
	next_pointer( nptr );
	return;
}

/*	-------------------------	*/
/*	translator_initialisation	*/
/*	-------------------------	*/
WORD	translator_initialisation( filename )
BPTR	filename;
{
	WORD	status;
	DllTrIndex = 0;
	if ( Options.Verbose & 2 )
		sysprintf("InitRunTime : otrdll \n");
	if ((DllStatus  = InitRunTime( 0, "otrdll", 0, DllDescriptor, sizeof(BDA_INIT))) != 0) 
	{
		first_pointer( filename );
		if ((status = CallTranslator( _TRUSER_INITIALISE )) != 0)
			return( status );
		else	
		{
			translator_options( filename );
			first_pointer( TokenZone );
			status = CallTranslator( _TRUSER_OPTIONS );
			TokenZone[0] = 0;
			return( status );
		}
	}
	else	
	{
		DllStatus = MOINS_UN;
		return(135);
	}
}

/*	------------------------	*/
/*	 translator_termination 	*/
/*	------------------------	*/
WORD	translator_termination( )
{
	if ( DllStatus != MOINS_UN ) 
	{
		no_parameters();
		(void) CallTranslator( _TRUSER_LIBERATE  );
		if ( Options.Verbose & 2 )
			sysprintf("FinRunTime : otr \n");
		(void) FinRunTime( 0 );
		DllStatus = MOINS_UN;
	}
	return( 0 );
}

/*	---------------------	*/
/*	translate_instruction	*/
/*	---------------------	*/
static	WORD	translate_instruction( iptr )
BPTR	iptr;
{
	if ( Options.Verbose & 2 )
		sysprintf("translate_instruction: %s",iptr);
	first_pointer( iptr );
	(void) CallTranslator( _TRUSER_LINE );
	return(0);
}

/*	--------------	*/
/*	translate_byte	*/
/*	--------------	*/
VOID	translate_byte( c )
WORD	c;
{
	DllTrBuffer[DllTrIndex++] = c;
	if (( c == '\n' ) || ( c == 0 ) || (DllTrIndex > 510)) 
	{
		DllTrBuffer[DllTrIndex++] = 0;
		translate_instruction( DllTrBuffer );
		DllTrIndex = 0;
	}
	return;
}

/*	-------------------------	*/
/*	translator_identification	*/
/*	-------------------------	*/
VOID	translator_identification()
{
	sysprintf("   ABAL++ Object Translator Version 2.2a \n");
	return;
}

static	BYTE	TTGBUF[64];

/*	------------------	*/
/*	enter_global_field	*/
/*	------------------	*/
static VOID	enter_global_field()
{
	translate_instruction("Field=(S)\r\n\0");
	translate_instruction("Field=G\r\n\0");
	return;
}

/*	---------------------	*/
/*	verify_common_startup	*/
/*	---------------------	*/
int 	verify_common_startup()
{
	if (( Options.UsingDLL )
	&& (!( Options.UsingDLL & 0x1000 ))) 
	{
		sprintf(TTGBUF,"Dcl X1_error_value%c\r\n",'%');
		translate_instruction( TTGBUF );
		sprintf(TTGBUF,"Dcl X2_error_value%c\r\n",'%');
		translate_instruction( TTGBUF );
		Options.UsingDLL |= 0x1000;
	}
	return(0);
}

/*	-------------------------	*/
/*	translate_to_global_field	*/
/*	-------------------------	*/
WORD	translate_to_global_field(mode)
WORD	mode;
{
	enter_global_field();
	if (!( Options.UsingDLL & mode )) 
	{
		if ( mode == 0x1000 )	i
			/* First time Common */
			(void) verify_common_startup();
		/* 0x2000 : First Time IFT */
	}
	Options.UsingDLL |= mode;
	return( VRAI );
}

/*	-------------------------	*/
/*	restore_translation_field	*/
/*	-------------------------	*/
WORD	restore_translation_field()
{
	first_pointer("Field=(R)\r\n\0");
	(void) CallTranslator( _TRUSER_LINE );
	return( VRAI );
}

	/* --------- */
#endif	/* _TRUSER_C */
	/* --------- */

