/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1995 Amenesik / Sologic s.a.	*/
/*									*/
/*									*/
/*		File	:	TRERRORS.H				*/
/*		Version :	1.1a					*/
/*		Date	:	12/01/1995				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRERRORS_H
#define	_TRERRORS_H

#define	DEBUG

#include <stdio.h>		/* Standard IO handling routines	*/
#include <errno.h>		/* Error return definitions		*/
#include <string.h>		/* string functions */

#include "stdtypes.h"
#include "trparser.h"
#include "troption.h"
#include "trerrors.h"
#include "trabmsg.h"		
#include "trdebug.h"
#include "translat.h"	
#include "trinput.h"		
#include "trproc.h"
#include "triof.h"
#include "troutput.h"	
#include "trmethod.h"	
#include "trshadow.h"	
#include "trecho.h"		
#include "trmain.h"		
#include "trdirect.h"	

#ifdef WIN32
#include "wotrmess.h"
#include "trtrace.h"
extern int OptIdra;
#endif

#define MAX_MSG_TOKEN_SIZE	20

#ifdef	UNIX
#define	systeme(c) system(c)
BPTR	world_editor();
BPTR	world_errorfile();
BPTR	world_tracefile();
BPTR	current_error_context();
BPTR	next_error_context();
#else
BPTR	world_editor(VOID);
BPTR	world_errorfile( WORD );
BPTR	world_tracefile( WORD );
BPTR	current_error_context( VOID );
BPTR	next_error_context( VOID );
#endif

#define	FILEPTR FILE XPTR

BYTE	ErrorBuffer[256];
FILEPTR ErrorHandle=(FILEPTR) 0;
FILEPTR	DebugHandle=(FILEPTR) 0;

/*	----------------------	*/
/*	initialise_error_trace	*/
/*	----------------------	*/
VOID	initialise_error_trace()
{
	if ( ErrorHandle == (FILEPTR) 0)
		ErrorHandle = fopen( world_errorfile(1), "w" );
	return;
}

/*	----------------------	*/
/*	initialise_debug_trace	*/
/*	----------------------	*/
VOID	initialise_debug_trace()
{
	if ( DebugHandle == (FILEPTR) 0)
		DebugHandle = fopen( world_tracefile(1) , "w" );
	return;
}

/*	--------------------	*/
/*	generate_debug_trace	*/
/*	--------------------	*/
VOID	generate_debug_trace( nfic, line, level, offset )
WORD	nfic;
WORD	line;
WORD	level;
WORD	offset;
{
	initialise_debug_trace();
	symbolic_file_name( nfic, (BPTR) ErrorBuffer );
	fprintf(DebugHandle,"%s %u 1 Level %u  Offset 0x%x\n",ErrorBuffer,line,level,offset);
	return;
}

/*	-----------------	*/
/*	flush_debug_trace	*/
/*	-----------------	*/
VOID	flush_debug_trace()
{
	if ( DebugHandle != (FILEPTR) 0 ) 
	{
		fclose( DebugHandle );
		DebugHandle = (FILEPTR) 0;
	}
	return;
}

/*	--------------------	*/
/*	trace_nested_context	*/
/*	--------------------	*/
VOID	trace_nested_context()
{
	BPTR	mptr;
	if ((mptr = current_error_context()) != (BPTR) 0) 
	{
		do	
		{
			sysprintf("\tFrom : %s\n",mptr);
		}
		while ((mptr = next_error_context()) != (BPTR) 0);
	}
	else	trace_inclusion_context();
	return;
}

/*	-------------	*/
/*	error_handler	*/
/*	-------------	*/
WORD	error_handler( nbmsg, mptr, retcod )
WORD	nbmsg;
BPTR	mptr;
WORD	retcod;
{
	LONG	Line;
	WORD	Col;

	localise_error( ErrorBuffer, &Line, &Col );

	if (( OtrOption.TraceErrors != 2 ) ||  ( OtrOption.Verbose )) 
	{
#ifdef WIN32
		char Message[512];
		char ErrorMsg[512];

		if (OptIdra) 
		{
			sprintf(Message, "%s: %s : %s", imessage_text(nbmsg), mptr, GetErrorMsg(mptr, ErrorMsg, 256));
			ctOutputErrorDiagnostic2(/*0*/retcod, ErrorBuffer, Line, Col, Message, NULL);
		}
		else 	
		{
			sprintf(Message, "%s: TR: %s : %s : %s\r\n", imessage_text(nbmsg), ErrorBuffer, mptr, GetErrorMsg(mptr, ErrorMsg, 256));
			x_cprintf(Message);
		}
#else
		sysprintf("%s:TR: %s : %s\n",imessage_text(nbmsg),ErrorBuffer,mptr);
#endif
	}

	if ( OtrOption.ListFlag )
		echo_error_message( imessage_text(nbmsg),ErrorBuffer, mptr );

	if ((OtrOption.TraceErrors) && (ErrorHandle != (FILEPTR) 0)) 
	{
		if ( localise_trace_error( ErrorBuffer, nbmsg ) )
			fprintf(ErrorHandle,"%s %s \n",ErrorBuffer,mptr);
	}
	else	trace_nested_context();

	terminate_line_parser();
	set_global_error( 1 );
	if (!( OtrOption.TraceErrors )) 
	{
		OtrOption.ListFlag      = FAUX;
		OtrOption.Verbose	= FAUX;
		OtrOption.SourceTrace	= FAUX;
		OtrOption.TargetTrace	= FAUX;
	}
	if ( OtrOption.TraceErrors ) 
	{
		OtrOption.ErrorCount++;
		if ( OtrOption.ErrorCount < OtrOption.ErrorLimit )
			return(0);
		else	return( retcod );
	}
	else	return( retcod );
}

/*	-------------	*/
/*	issue_warning	*/
/*	-------------	*/
WORD	issue_warning( level )
WORD	level;
{
	LONG	Line;
	WORD	Col;

	if  ( active_warning( level ) ) 
	{
		localise_error( ErrorBuffer, &Line, &Col );

		if (( OtrOption.TraceErrors != 2 ) ||  ( OtrOption.Verbose )) 
		{
#ifdef WIN32
			char Message[512];
			char ErrorMsg[512];
			char MsgTokenBuffer[MAX_MSG_TOKEN_SIZE + 6];

			if ( *TokenBuffer ) 
			{
				if (strlen(TokenBuffer) > MAX_MSG_TOKEN_SIZE) 
				{
					strncpy(MsgTokenBuffer, TokenBuffer, MAX_MSG_TOKEN_SIZE);
					strcpy(MsgTokenBuffer + MAX_MSG_TOKEN_SIZE, " ... ");
				}
				else	strcpy(MsgTokenBuffer, TokenBuffer);
			}
			else	*MsgTokenBuffer = "\0";

			if (OptIdra) 
			{
				sprintf(Message, "W%u: '%s' : %s", level, MsgTokenBuffer, GetWarningMsg(level, ErrorMsg, 256));
				ctOutputWarningDiagnostic2(level, ErrorBuffer, Line, Col, Message, NULL);
			}
			else 
			{
				sprintf(Message, "%s: %s : W%u '%s' : %s\r\n", imessage_text(16), ErrorBuffer, level, MsgTokenBuffer, GetWarningMsg(level, ErrorMsg, 256));
				x_cprintf(Message);
			}
#else
			printf("%s: %s : W%u %s\n", imessage_text(16), ErrorBuffer, level, TokenBuffer);
			if ( OtrOption.Verbose & 32 )
				printf("<p>");
#endif
		}

		if ( OtrOption.ListFlag )
			echo_warning_message( imessage_text(16),ErrorBuffer,level, TokenBuffer);

		if ((OtrOption.TraceErrors) && (ErrorHandle != (FILEPTR) 0) && ( localise_trace_error( ErrorBuffer, 16 ) ))
			fprintf(ErrorHandle,"%s W%u %s \n",ErrorBuffer,level,TokenBuffer);
	}
	return(0);
}

/*	------------	*/
/*	syntax_error	*/
/*	------------	*/
WORD syntax_error(level)
WORD level;
{
	BYTE	buffer[1024];

	if ( *TokenBuffer ) {
		BYTE	MsgTokenBuffer[MAX_MSG_TOKEN_SIZE + 6];

		if (strlen(TokenBuffer) > MAX_MSG_TOKEN_SIZE) 
		{
			strncpy(MsgTokenBuffer, TokenBuffer, MAX_MSG_TOKEN_SIZE);
			strcpy(MsgTokenBuffer + MAX_MSG_TOKEN_SIZE, " ... ");
			sprintf(buffer,"A%u : '%s' ", level, MsgTokenBuffer);
		}
		else	sprintf(buffer,"A%u : '%s' ", level, TokenBuffer);
	}
	else	sprintf(buffer,"A%u ",level);

	return( error_handler( 3, buffer, 30 ) );
}

/*	-----------------	*/
/*	unknown_directive	*/
/*	-----------------	*/
WORD unknown_directive()    { return( error_handler( 4, TokenBuffer, 99 ) ); }

/*	-------------------	*/
/*	too_many_parameters	*/
/*	-------------------	*/
WORD too_many_parameters()  { return( syntax_error( 1040 ) );       	     }

/*	---------------------	*/
/*	not_enough_parameters	*/
/*	---------------------	*/
WORD not_enough_parameters(){ return( syntax_error( 1050 ) );                }

/*	------------------	*/
/*	allocation_failure	*/
/*	------------------	*/
WORD allocation_failure()   { return( error_handler( 7, " ", 27 ) );	     }

/*	-------------------	*/
/*	illegal_recursivity	*/
/*	-------------------	*/
WORD illegal_recursivity(aptr,id) 
BPTR	aptr;
WORD	id;
{
	strcpy(TokenBuffer,aptr);
	return( syntax_error( 5200 + id ) );	
}

/*	--------------	*/
/*	internal_error	*/
/*	--------------	*/
WORD internal_error(level)
WORD level;
{
	BYTE	buffer[64];
#ifdef	otr64
	sprintf(buffer,"S%u : %016X",level,current_tcode_offset()); 
#else
#ifdef	otr32
	sprintf(buffer,"S%u : %08.1X",level,current_tcode_offset()); 
#else
	sprintf(buffer,"S%u : %04.1X",level,current_tcode_offset()); 
#endif
#endif
	(void) error_handler( 8, buffer, 29 );
	return( level );
}

/*	----------	*/
/*	file_error	*/
/*	----------	*/
WORD file_error(level)
WORD level;
{
	BYTE	buffer[32];
	sprintf(buffer,"F%u",level); 
	return( error_handler(26, buffer, 29 ) );
}

/*	-----------------	*/
/*	target_file_error	*/
/*	-----------------	*/
WORD target_file_error( char*fnptr,int level) 
{ 
	sprintf(TokenBuffer,"F%u(%s)",level,fnptr); 
	return( error_handler(26, TokenBuffer, 29 ) );
}

/*	----------------------	*/
/*	unexpected_dieze_endif	*/
/*	----------------------	*/
WORD unexpected_dieze_endif() { return( error_handler( 9, " ", 30 ) );  }

/*	---------------------	*/
/*	unexpected_dieze_else	*/
/*	---------------------	*/
WORD unexpected_dieze_else()  { return( error_handler( 10, " ", 30 ) ); }

/*	--------------------	*/
/*	expected_dieze_endif	*/
/*	--------------------	*/
WORD expected_dieze_endif()   { return( error_handler( 11, TokenBuffer, 30 ) ); }

/*	---------------------	*/
/*	incorrect_punctuation	*/
/*	---------------------	*/
WORD incorrect_punctuation()  { return( error_handler( 17, " ", 30 ) ); }

/*	-----------------	*/
/*	expected_variable	*/
/*	-----------------	*/
WORD expected_variable()      { return( error_handler( 20, " ", 30 ) ); }

/*	------------------	*/
/*	expected_paragraph	*/
/*	------------------	*/

/*	------------------	*/
/*	expected_paragraph	*/
/*	------------------	*/
WORD expected_paragraph()     { return( error_handler( 21, " ", 30 ) ); }

/*	-------------	*/
/*	expected_file	*/
/*	-------------	*/
WORD expected_file()          { return( error_handler( 23, " ", 30 ) ); }

/*	----------------	*/
/*	expected_program	*/
/*	----------------	*/
WORD expected_program()       { return( error_handler( 24, " ", 30 ) ); }

/*	----------------	*/
/*	unmatched_braces	*/
/*	----------------	*/
WORD unmatched_braces()	      { return( syntax_error( 1060 ) ); 	}

/*	---------------------	*/
/*	incorrect_target_type	*/
/*	---------------------	*/
WORD incorrect_target_type()  { return( error_handler( 27, " ", 20 ) ); }

/*	----------------	*/
/*	target_file_busy	*/
/*	----------------	*/
WORD target_file_busy()       { return( error_handler( 29, TokenBuffer, 20 ) ); }

/*	----------------------	*/
/*	incorrect_command_line	*/
/*	----------------------	*/
WORD incorrect_command_line(token)
BPTR	token;
{
	BYTE	buffer[256];
	sprintf(buffer, "<...>%s<...>", token); 
	return( error_handler( 28, buffer, 20 ) );
}

/*	-----------------	*/
/*	open_source_error	*/
/*	-----------------	*/
WORD    open_source_error(fptr, status )
BPTR    fptr;
WORD    status;
{
	return( error_handler( 28, fptr, status ) );
}

/*	----------------------	*/
/*	symbol_already_defined	*/
/*	----------------------	*/
WORD	symbol_already_defined(token)
BPTR	token;
{
	return( error_handler( 13,token, 81 ) );
}

/*	-----------------	*/
/*	 undefined_label	*/
/*	-----------------	*/
WORD	undefined_label(token)
BPTR	token;
{
	return( error_handler( 19,token, 78 ) );
}

/*	----------------	*/
/*	expected_keyword	*/
/*	----------------	*/
WORD	expected_keyword(token)
BPTR	token;
{
	return( error_handler( 22,token, 78 ) );
}

/*	-------------------	*/
/*	incorrect_data_type	*/
/*	-------------------	*/
WORD incorrect_data_type() { return( error_handler( 14, TokenBuffer, 62 ) ); }

/*	-----------------	*/
/*	not_yet_available	*/
/*	-----------------	*/
WORD not_yet_available()   { return( error_handler( 15, TokenBuffer, 56 ) ); }

/*	------------------	*/
/*	inhibited_function	*/
/*	------------------	*/
WORD inhibited_function()  { return( error_handler( 15, TokenBuffer, 556 ) ); }

/*	------------	*/
/*	report_error	*/
/*	------------	*/
WORD	report_error( n )
WORD	n;
{
	return(n);
}

/*	-------------	*/
/*	error_message	*/
/*	-------------	*/
VOID	error_message( mptr )
BPTR	mptr;
{
	return;
}

/*	---------	*/
/*	 execute	*/
/*	---------	*/
WORD	execute( shell_command )
BPTR	shell_command;
{
#ifdef	WIN32
	/* ---- */
	/* TODO */
	/* ---- */
	return(0);
#else
	/* --------------------- */
	/* Verbalise if required */
	/* --------------------- */
	if (OtrOption.Verbose & 4 )
		sysprintf("\t%s\n",shell_command);

	return( systeme( shell_command ) );
#endif
}

/*	----------------	*/
/*	terminate_errors	*/
/*	----------------	*/
VOID	terminate_errors()
{
	trace("terminate_errors(DEB)\n");
	if ( ErrorHandle != (FILEPTR) 0 ) 
	{
		fclose( ErrorHandle );
		if ( OtrOption.TraceErrors > VRAI ) 
		{
#ifdef	UNIX
			sprintf( ErrorBuffer, "%s -t%s",world_editor(), world_errorfile(0) );
#else
			sprintf( ErrorBuffer, "%s /t%s",world_editor(), world_errorfile(0) );
#endif
			(void) execute( ErrorBuffer );
		}
	}
	trace("terminate_errors(FIN)\n");
	return;
}

	/* ----------- */
#endif 	/* _TRERRORS_H */
	/* ----------- */
