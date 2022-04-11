/* -------------------------------------------------------------------- */
/* 									*/
/* 	Project :	ABAL PROJECT MAINTENANCE			*/
/* 			------------------------			*/
/* 									*/
/* 	File    :	SYSTEME.C					*/
/* 	Date    :	30/11/1990					*/
/* 	Version :	1.4a      					*/
/* 									*/
/* -------------------------------------------------------------------- */

#ifdef	UNIX
#include <stdio.h>
#include <errno.h>
#endif

#include "systemd.h"

#ifdef DOS

#define	X_DOS_MAX	2
#define	I_DOS_MAX	24
#define	SYSTEM_ERR	0x00FF


/* Internal DOS commands which require COMMAND.COM */
/* ----------------------------------------------- */
BPTR	dos_interne[24] = {
	(BPTR) "BREAK",
	(BPTR) "CD",
	(BPTR) "CHDIR",
	(BPTR) "CLS",
	(BPTR) "COPY",
	(BPTR) "CTTY",
	(BPTR) "DATE",
	(BPTR) "DEL",
	(BPTR) "DIR",
	(BPTR) "ECHO",
	(BPTR) "ERASE",
	(BPTR) "MD",
	(BPTR) "MKDIR",
	(BPTR) "PATH",
	(BPTR) "PROMPT",
	(BPTR) "REM",
	(BPTR) "REN",
	(BPTR) "RENAME",
	(BPTR) "SET",
	(BPTR) "TIME",
	(BPTR) "TYPE",
	(BPTR) "VER",
	(BPTR) "VERIFY",
	(BPTR) "VOL"
	};

BPTR	dos_extension[X_DOS_MAX] = {
	(BPTR) "EXE",
	(BPTR) "COM"
	};

BPTR	path_root;
WORD	path_term;
BYTE	extension[16];
WORD	ext_len;
BYTE	filename[128];
BYTE	command_buffer[128];

void	fill_command_buffer( aptr , bptr )
BPTR	aptr;
BPTR	bptr;
{
	WORD	i;

	i = 1;
	command_buffer[i++] = ' ';
	if ( *aptr != 0 ) {
		while ( *aptr != 0 ) command_buffer[i++] = *(aptr++);
		if ( *bptr != 0 )
			command_buffer[i++] = ' ';
		}
	while ( *bptr != 0 ) command_buffer[i++] = *(bptr++);
	command_buffer[i] = (BYTE) 0x000D;
	command_buffer[0] = (i-1);
	return;

}


WORD	execute_via_command_com( cmdptr )
BPTR	cmdptr;
{
        BPTR	comspecptr;
	WORD	erreur;

	/* Collect COMSPEC environment value */
	/* --------------------------------- */
	if ((comspecptr = (BPTR) ll_getenv((BPTR) "COMSPEC")) == (BPTR) 0) {
		return(2);
		}

	/* Prepare command buffer */
	/* ---------------------- */
	fill_command_buffer((BPTR) "/C", cmdptr );

	/* Attempt to execute and return error */
	/* ----------------------------------- */
	return(ll_system((BPTR) comspecptr, (BPTR) command_buffer ));
}

/*
 *	E X E C U T E _ W I T H _ P A T H ( pathptr , cmdptr , argptr )
 *	---------------------------------------------------------------
 *
 */

WORD	execute_with_path( pathptr , cmdptr , argptr )
BPTR	pathptr;
BPTR	cmdptr;
BPTR	argptr;
{
	WORD	opath_len;
	WORD	i;
	WORD    l;
	WORD	x;
	WORD	erreur;
	
	i = 0;

	/* Check for Path info in cmd ptr */
	/* ------------------------------ */
	if ((opath_len = fn_parser((BPTR) cmdptr,(BPTR) filename,0x0007)) == 0 ) {

		/* Copy provided path string if no path info */
		/* ----------------------------------------- */
		while ( *pathptr != 0 ) filename[i++] = *(pathptr++);

		/* Ensure path element is path separated */
		/* ------------------------------------- */
		if ( i > 0 ) {
			if ( filename[(i-1)] != '\\' ) {
				filename[i++] = '\\';
				filename[i] = (BYTE) 0;
				}
			}
		}

	/* Copy command name to command buffer */
	/* ----------------------------------- */
	while ( *cmdptr != 0 ) filename[i++] = *(cmdptr++);

	/* Terminate filename portion */
	/* -------------------------- */
	filename[i++] = 0;

	/* Copy eventual arguament to Command buffer */
	/* ----------------------------------------- */
	fill_command_buffer( (BPTR) "\0", (BPTR) argptr );

	/* Execute the constructed command */
	/* ------------------------------- */
        if ((erreur = ll_system((BPTR) filename, (BPTR) command_buffer)) != 0xFFFF) {

		/* Execution not failed : Return Exit_Value */
		/* ---------------------------------------- */
		return( erreur );
		}

	else	{
		/* Initial execution failure : test for suffixes */
		/* --------------------------------------------- */
        	if ( ext_len == 0 ) {

        		/* Attempt to load in order each of the suffixes */
        		/* --------------------------------------------- */
			for (l = 0; l < X_DOS_MAX; l++ ) {

				/* Remove any current suffix */
				/* ------------------------- */
		        	i = fn_parser((BPTR) filename, (BPTR) filename, 0x000F);
				filename[i++] = '.';

				/* Copy current suffix to filename */
				/* ------------------------------- */
				for (x = 0; x < 4; x++) {
					filename[i+x] = *((dos_extension[l]) + x);
					}

				/* Attempt to execute constructed filename */
				/* --------------------------------------- */
			        if ((erreur = ll_system((BPTR) filename, (BPTR) command_buffer)) < SYSTEM_ERR) {
					return(erreur);
					}
				}
	        	}
		}

	/* Return Error Result */
	/* ------------------- */
	if ( opath_len == 0 ) {
		return(0xFFFF);
		}
	else	{
		return( 2 );
		}
}

BYTE	WorkPathBuff[256];

/*
 *	G E T _ P A T H _ E L E M E N T ( path_mode )
 *	---------------------------------------------
 *	Returns a pointer to the next element taken from the
 *	PATH environment variable
 *
 */

BPTR	get_path_element( path_mode )
WORD	path_mode;
{
	BPTR	ThisPtr;
	WORD	i;

	/* Check for first time access */
	/* --------------------------- */
	if ( path_mode == 0 ) {

		/* Collect environment variable contents */
		/* ------------------------------------- */ 
		if (( path_root = (BPTR) ll_getenv((BPTR) "PATH" )) == (BPTR) 0) {
			return((BPTR) 0);
			}

		for ( i=0; i < 255; i++ ) {
			if ((WorkPathBuff[i] = *(path_root + i)) == 0) {
				break;
				}
			}

		WorkPathBuff[i] = 0;
		path_root = (BPTR) WorkPathBuff;
		path_term = 0;
		}

	/* Avoid NULL length path strings */
	/* ------------------------------ */
	if ( *path_root == (BYTE) 0) { return((BPTR) 0); }

	/* Replace previous terminator  */
	/* ---------------------------  */
	if ( path_term != 0 ) {
		*(path_root - 1) = path_term;
		}

	/* Point to the current element */
	/* ---------------------------- */
	ThisPtr = path_root;

	/* Scan till end of this element */
	/* ----------------------------- */
	while (( *path_root != (BYTE) 0) && ( *path_root != ';')) path_root++;

	/* Perform path string termination */
	/* ------------------------------- */
	if ( *path_root == ';' ) {
		*(path_root++) = (BYTE) 0;
		path_term = ';';
		}

	/* Return the pointer to this path element */
	/* --------------------------------------- */
	return((BPTR) ThisPtr);
}



/*
 *	I S _ B A T C H _ F I L E ( cmdptr )
 *	------------------------------------
 *	Detection of batch file to be executed by the command interpreter
 *
 */

WORD	is_batch_file( xptr )
BPTR	xptr;
{
	if ( *xptr == '.' ) xptr++;
	if ( *(xptr++) != 'B' ) return(0);
	if ( *(xptr++) != 'A' ) return(0);
	if ( *xptr != 'T' ) return(0);
	return(1);
}


/*
 *	I S _ I N T E R N A L ( cmdptr )
 *	--------------------------------
 *	Detection of internal commands for MSDOS
 *	These commands require the execution of COMMAND.COM /C
 *
 */

WORD	is_internal( cmdptr )
BPTR	cmdptr;
{
	WORD	i;
	WORD	indent;
	BPTR	wptr;
	BYTE	Majescule(BYTE);

	/* Scan internal command table for match */
	/* ------------------------------------- */
	for (i=0; i < I_DOS_MAX; i++ ) {

		/* Collect internal command pointer */
		/* -------------------------------- */
		wptr = (BPTR) dos_interne[i]; indent = 0;

		/* Compare till end of test string */
		/* ------------------------------- */
		while ( *(wptr + indent) != (BYTE) 0 ) {
			
			if ( *(wptr + indent) != Majescule(*(cmdptr + indent)) ) {
				break;
				}
			indent++;
			}

		/* If command match found */
		/* ---------------------- */
		if ( *(wptr + indent) == (BYTE) 0 ) {

			/* Ensure correct end of string */
			/* ---------------------------- */
			switch ( *(cmdptr + indent) ) {
				case ' '    :
				case 0x0009 :
				case 0x000D :
				case 0x000A :
				case 0x0000 :

					/* Indicate Internal Command */
					/* ------------------------- */
					return(1);
				}

			}

		}

	/* Scan Command string for PIPE or REDIRECTION */
	/* ------------------------------------------- */
	for ( indent=0; *(cmdptr + indent) != 0; indent++) {
		switch ( *(cmdptr + indent ) ) {
			case '<' :
			case '>' :
			case '|' : return(1);
			}
		}

	/* Indicate not an internal command */
	/* -------------------------------- */
	return(0);
}


/*
 *	S Y S T E M E ( cmdptr )
 *	------------------------
 *	Execution of a system command taking into consideration 
 *	any PATH type info available and filtering certain system
 *	specific internal commands
 *
 */

WORD	systeme( cmdptr )
BPTR	cmdptr;
{
	WORD	local_errno;
	BPTR	argptr;
	BPTR	pathptr;
	WORD	path_mode;
	WORD	arg_exist;
	WORD	l;

	/* Establish Success result */
	/* ------------------------ */
	local_errno = 0;

	/* Check for internal commands for DOS */
	/* ----------------------------------- */
	if ( is_internal( cmdptr ) != 0 ) {

		/* Perform COMMAND.COM assisted execution */
		/* -------------------------------------- */
		return(execute_via_command_com( cmdptr ));

		}

	/* Separate Command name from possible arguaments */
	/* ---------------------------------------------- */
	argptr = cmdptr; arg_exist = 0;
	while (1) {
		switch ( *argptr ) {
			case ' '    : 
			case 0x0009 : *(argptr++) = (BYTE) 0; 
				      arg_exist = 1;
				      break;
			case 0x000D :
			case 0x000A : *argptr = (BYTE) 0;
			case 0x0000 : break;
			default     : argptr++; continue;
			}
		break;
		}

	/* ---------------------------------------------------- */
	/* cmdptr points to the start of the command name	*/
	/* argptr points to the start of the arg string		*/
	/* Detect and execute via Command.Com : Batch files 	*/
	/* ---------------------------------------------------- */
	if ((ext_len = fn_parser(cmdptr, (BPTR) extension, 0x0010 )) == 4) {

		/* Detect .BAT extension match */
		/* --------------------------- */
		if ( is_batch_file((BPTR) extension) != 0 ) {

			/* Rejoin Command and Arg if separated */
			/* ----------------------------------- */
			if ( arg_exist != 0 ) {
				*(argptr - 1) = ' ';
				}
			/* Perform COMMAND.COM assisted execution */
			/* -------------------------------------- */
			return(execute_via_command_com( cmdptr ));
			
			}
		}

	/* COMMAND.COM execution selection algorithm emulation */
	/* --------------------------------------------------- */
	pathptr = (BPTR) 0; path_mode = 0;

	do	{
		/* First time through requires default PATH */
		/* ---------------------------------------- */
		if ( pathptr == (BPTR) 0 ) {

			pathptr   = (BPTR) ".\\";

			}
		else	{

			/* Establish next path element */
			/* --------------------------- */
			pathptr = get_path_element( path_mode );
			path_mode++;
			}

		/* If a valid path ptr has been found */
		/* ---------------------------------- */
		if ( pathptr != (BPTR) 0 ) {

			/* Attempt to execute the system command */
			/* ------------------------------------- */
			if ((local_errno = execute_with_path( pathptr , cmdptr , argptr )) <= SYSTEM_ERR) {

				/* Command execution error return */
				/* ------------------------------ */
				return( local_errno );
				}

			}
		}
	/* Until the path element is invalid */
	/* --------------------------------- */
	while ( pathptr != (BPTR) 0 );

	/* Command not found : Do not know how to execute */
	/* ---------------------------------------------- */
	/* Rejoin Command and Arg if separated */
	/* ----------------------------------- */
	if ( arg_exist != 0 ) {
		*(argptr - 1) = ' ';
		}
	/* Perform COMMAND.COM assisted execution */
	/* -------------------------------------- */
	return(execute_via_command_com( cmdptr ));

}
#endif

#ifdef PRL

extern WORD errno;

/*
 *	External function prototypes
 *	----------------------------
 */

BPTR	ll_malloc( WORD );
void	ll_free( BPTR );
WORD	Chargeur( BPTR , BPTR );
WORD	ExecGo( BPTR , BPTR );
void	Discharge( BPTR );

/*
 *	S Y S T E M E ( cmdptr )
 *	------------------------
 *	Version PROLOGUE
 *
 *	Performs ANFC , (TUC,INTR) , (CHGT/CHGP) , CALL , (LBSM/DCHGP)
 *
 */

WORD	systeme( cmdptr )
BPTR cmdptr;
{

	WORD	i,j,k;
	BYTE 	c;
	BYTE 	d;
	BPTR	ExecBuf;
	BPTR	ArguBuf;
	i = 0; j = 0; k = 0;

	/* Scan past Binary function name */
	/* ------------------------------ */
	while (( *(cmdptr + i) != ' ') && ( *(cmdptr + i) != 0 )) {
		i++;
		}
	if ( i == 0 ) { return(0); }

	/* Establish File Terminator */
	/* ------------------------- */	
	c =  *(cmdptr + i);
	*(cmdptr + i) = (unsigned BYTE) 0;

	if ((ExecBuf = (BPTR) ll_malloc ( 32 )) == (BPTR) 0 ) {
		return(27);
		}

	/* Attempt to Load the Executable Binary File */
	/* ------------------------------------------ */
	if ( Chargeur((BPTR) cmdptr , (BPTR) ExecBuf ) != 0 ) {
		*(cmdptr + i  ) = c; 
		ll_free((BPTR) ExecBuf);
		return(40);
		}

	if ( c == ' ' ) {
		j = 1;
		}

	/* Scan for End of Arg */
	/* ------------------- */
	while ( (*(cmdptr+i+j+k) != 0 ) && ( *(cmdptr+i+j+k) != 0x000D)) {
		k++;
		}

	d = *(cmdptr+i+j+k);
	*(cmdptr+i+j+k) = 0x000D;

	if ((ArguBuf = (BPTR) ll_malloc( (k + 1 ) )) == (BPTR) 0 ) {
		return( 27 );
		}
	memcpy( ArguBuf , (cmdptr + i + j) , (k + 1) );

	/* Attempt to Execute the Binary File */
	/* ---------------------------------- */
	errno = ExecGo((BPTR) ExecBuf, (BPTR) ArguBuf );

	/* Liberate the binary Image */
	/* ------------------------- */
	Discharge( (BPTR) ExecBuf );

	/* Replace Swapped Bytes */
	/* --------------------- */
	*(cmdptr+j+i+k) = d; 
	*( cmdptr + i ) = c; 
	return( errno );
}

#endif

#ifdef	UNIX

#ifdef	systeme
#undef	systeme
#endif

WORD	systeme( cmdptr )
BPTR	cmdptr;
{
	return( system( cmdptr ) );
}
#endif

