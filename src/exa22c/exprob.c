/*----------------------------------------------------------------------*/
/*																								*/
/*		E X E C U T E U R 	A . B . A . L											*/
/*		-------------------------------------										*/
/*																								*/
/*		Copyright (c) 1987,1992 Amenesik / Sologic S.A.										*/
/*																								*/
/*		Module  :	EXPROB - C															*/
/*		Version :	1.4c / 2.1d															*/
/*		Date 	:	20/10/1998																*/
/*																								*/
/*----------------------------------------------------------------------*/

/*
 *	This module contains all functions which could require
 *	modification due to portabillity problems.
 *
 *	N.B. It is an include file for EXF-C.
 */

/*
 *	X _ N P O S ( )
 *	---------------
 *
 *	Returns the current workstation id number.	
 *	
 */

#ifdef UNIX11D
#include <sys/types.h>
#include <utmp.h>
extern	EXAWORD	idbal;
extern	EXAWORD	idflg;
BINAIRE	x_npos()
{
	struct	utmp *getutent();
	struct	utmp *idabal;
	BPTR	ttyname();
	BPTR	ttyabal;

	if ( idflg == 0 ) {
		idbal = 0;
		ttyabal = ttyname(0) + 5;	/* Avoid path name portion */
		do {
			if ((idabal = getutent()) == (struct utmp SPTR) 0) {
				return(0);
				}
			if ((idabal->ut_type == LOGIN_PROCESS) || (idabal->ut_type == USER_PROCESS)) {
				idbal++;
				}
			} 
		while ( strcmp(ttyabal,idabal->ut_line) );
		idflg = 1;
		endutent();
		}
	return( (idbal - 1) );
}
#endif

EXAWORD	excwdir( rptr,rlen,mode )
BPTR	rptr;		/* Result Pointer 	 */
EXAWORD	rlen;		/* Result Length  	 */
EXAWORD	mode;		/* CURDIR = 0 CURVOL = 1 */
{

#ifdef PROLOGUE
	int	x;

/* Check for Amenesik / Sologic 3 Sous Repertoires */
/* ------------------------------------- */ 
if ( check33() == 0 ) {

	/* Not >= Amenesik / Sologic 3.3 or 3.sr */
	/* --------------------------- */
	if ( mode != 0 ) { 

		/* Attempt to read 'MNEMONIC IMPLICITE FICHIER */
		/* ------------------------------------------- */
		if ((rlen = prlvolif(rptr,rlen,1)) == MOINS_UN) {

			/* Collect and signal subsequent error */
			/* ----------------------------------- */ 
			err_val = errno; return(SOFTERROR); 
			}
		}

	/*	Fill with spaces to end of string 	*/
	/* -------------------------------------------- */	
	while ( rlen > 0 ) { *(rptr++) = IO_ESP; rlen--; } 
	return(1);
	}
else	{
	/* Amenesik / Sologic 3.3 or 3.sr Sous Repertoires */
	/* ------------------------------------- */
	if ( GetSousRep((BPTR) askbuf, 255, 1 ) == MOINS_UN ) {

		/* Collect and signal subsequent error */
		/* ----------------------------------- */ 
		err_val = errno; return(SOFTERROR);
		}

	if ( mode != 0 ) {

		/* Perform Extraction CURVOL */
		/* ------------------------- */
		if ( rlen < 4 ) { 
			err_val = 63; return(SOFTERROR); 
			}

		/* Prewipe buffer then Copy */
		/* ------------------------ */
		memset((BPTR) rptr , ' ' , rlen );
		memcpy((BPTR) rptr , (BPTR) askbuf , 4 );
		}
	else	{

		/* Perform Extraction CURDIR */
		/* ------------------------- */
		for ( x = 0; x < 255; x++ ) {
			if (( askbuf[x] == 0x000D ) || ( askbuf[x] == ' ' )) {
				askbuf[x] = ' ';
				break;
				}
			}

		/* Prewipe buffer then copy */
		/* ------------------------ */
		memset((BPTR) rptr,' ',rlen);

		if ( x <= 4 )
			return( GOODRESULT );
		x -= 4;

		/* Report Error Condition */
		/* ---------------------- */
		if ( x > rlen ) { 
			err_val = errno = 63; return(SOFTERROR); 
			}

		if ( x > 1 ) {
			memcpy((BPTR) rptr, (BPTR) &askbuf[4] ,x);
			}
		}
	return(1);
	}
#endif	/* PRL */

#ifdef	DOS
	EXAWORD	exadosvol(VOID);
	EXAWORD	exadosdir(EXAWORD,BPTR);
	EXAWORD	disque_tte,x;
	EXABYTE	lworkz[FNMAX+1];

	/* First read the current Drive ID */
	/* ------------------------------- */
	if ((disque_tte = exadosvol()) == MOINS_UN) {
		return(0);
		}

	/* Select Function CURDIR or CURVOL */
	/* -------------------------------- */	
	if ( mode == 0 )	{	/* $ = CURDIR */
		if ( exadosdir( disque_tte , (BPTR) lworkz ) == MOINS_UN ) {
			return(0);
			}
#ifdef WIN32
		x = lenuzend( (BPTR) lworkz , FNMAX );
#else
		x = lenuze( (BPTR) lworkz , 64 );
#endif
		if ( x > 0 ) {
			if ( rlen < (x + 2) ) {
				err_val = EXER_REK2SMA; return(0);
				}
			memset(rptr,' ',rlen); 		 *(rptr++) = '\\';
			memcpy(rptr,(BPTR) lworkz, x); *(rptr +x) = '\\';
			}
		else	{
			if ( rlen < 1 ) {
				err_val = EXER_REK2SMA; return(0);
				}
			memset(rptr,' ',rlen);
			*rptr = '\\';
			}
		}
	else	{			/* $ = CURVOL */

		/* Check for Buffer Too Small */
		/* -------------------------- */
		if ( rlen < 2 ) {
			err_val = EXER_REK2SMA; return(0);
			}
		else	{
			memset(rptr,' ',rlen);
			*(rptr++) = (EXABYTE) (disque_tte + 0x0040);
			*(rptr++) = ':';
			}
		}
	return(1);
#endif	/* DOS */

#ifdef UNIX
#ifdef	RT_AIX
#define	getcwd(Arg1,Arg2) GetCwd(Arg1,Arg2)
	BPTR	GetCwd();
#else
	BPTR	getcwd();
#endif
	EXAWORD	xl;
	BPTR	lcwd;
err_val = 0;
if ( (lcwd = getcwd((BPTR) 0,68)) == (BPTR) 0) { 
	err_val = EXER_REK2SMA; 
	return(SOFTERROR);
	}
else 	{
	xl = strlen(lcwd);
	/* Current directory */
	/* ----------------- */
	if ( mode == 0 ) {
		if ( xl  > rlen ) { err_val = EXER_REK2SMA; }
		else { 	if ( *(lcwd + (xl - 1)) != '/' ) {
				*(lcwd + xl) = '/'; xl += 1;
				}
			memcpy(rptr,lcwd,xl);
			memset((rptr + xl),' ',(rlen - xl));
			}
		}
	/* Current Volume ID */
	/* ----------------- */
	else	{ memset(rptr,' ',rlen);}
	}
if ( lcwd != (BPTR) 0 ) { free(lcwd); }
if ( err_val == 0 ) { return(1); }
return(SOFTERROR);
#endif

#ifdef VMS
err_val = curvoldir(rptr,rlen,mode);
if ( err_val == 0 ) { return(1); }
else		    { return(0); }
#endif

}

#ifndef PROLOGUE
/*
 *	C G E T S ( rptr )
 *	------------------
 *
 *	Accept keyboard input of initial T-code filename to the
 *	string pointed to by *rptr.
 *
 */

BPTR	cgets( rptr )
BPTR	rptr;
{
	BPTR	wptr;
	EXABYTE	c;
	EXAWORD	ml;
	ml = (EXAWORD) *rptr;	
	wptr = rptr;
	rptr += 2;
	while ( ml > 0 ) {
		c = x_getch();
		if ( c == IO_RC ) { ml = 0; }
		else {
			switch ( c ) {
				case IO_BAK : 	ml++; rptr--;
					      	x_putch(c); break;
				case IO_FOR : 	ml--; x_putch(*(rptr++));
						break;
				default	    :	*(rptr++) = c; ml--; 
						x_putch(c); break;
				}
			}
		}
	*((BPTR) (wptr + 1)) = (EXABYTE) ( ((EXAWORD) *wptr) - ml);
	*(rptr++) = (EXABYTE) 0;
	return((BPTR) (wptr +2) );
}

#endif	/* ! PRL */

/*
 *	X R E N A M E ( oldname , newname )
 *	-----------------------------------
 *
 *	Renames the file 'oldname' as 'newname'
 * 
 */

#ifndef	ABAL_CRITERIA
EXAWORD	xrename( oldname , newname )
BPTR	oldname;
BPTR	newname;
{

#ifndef PROLOGUE
	/* Check that old file does Exist */
	/* ------------------------------ */
	if (Access(oldname,0,1) != 0 ) { 
		if ( errno == 44 ) {
			return(44);
			}
		else	{
			return(40); 
			}
		}
#endif

	/* Check that new file does not Exist */
	/* ---------------------------------- */
	if (Access(newname,0,1) == 0 ) { 
#ifdef	COEXA
		(VOID) liberlox((BPTR) newname);
#endif
		return( 41 ); 
		}

#ifdef UNIX

	/* Create a new file link */
	/* ---------------------- */
	if ( link( oldname, newname ) == 0 ) {
		/* Delete the old link */
		/* ------------------- */
		if ( unlink( oldname ) == 0 ) {
			/* All Went well */
#ifdef	COEXA
			(VOID) liberlox((BPTR) newname);
#endif
			return(0);
			}
		/* Delete the New link */
		/* ------------------- */
		(VOID) unlink( newname );
#ifdef	COEXA
		(VOID) liberlox((BPTR) oldname);
#endif
		}
	return( 58 );
#endif
#ifdef DOS
	/* -------------------- */
	/*   MS or PC DOS 	*/
	/* --------------------	*/
	if ( rename( oldname , newname ) != 0 ) { return(58); }
	return(0);
#endif
#ifdef	PROLOGUE
	/* ---------------------------- */
	/*	PROLOGUE 2 and 3	*/
	/* ---------------------------- */
	if ( renfile( fidreel, newname ) != 0 ) { return(errno); }
	return(0);
#endif
}

#endif	/* ABAL_CRITERIA */

/*
 *	E X K B F W ()
 *	--------------
 *
 *	Ecriture des touches de fonction d'un Console
 *	---------------------------------------------
 *	WORKPTR2 **=> Chaine a affecter a la touche de fonction
 *	WORKLEN2 ==   Longeur de cette chaine
 *	WORKVAL1 ==   Numero de touche a programmer
 *
 *	Returns 1 OK , Zero if Error
 */

EXAWORD	exkbfw()
{
	EXAWORD	kx;

	/* Calculate length of String to Affect to Function KEY */
	/* ---------------------------------------------------- */
	worklen2 = lenuze(workptr2,worklen2);
	if ( worklen2 > 32 ) { worklen2 = 32; }

	/* Copy string  to temporary Zone */
	/* ------------------------------ */
	(VOID) memcpy((TcodeByteStack + worktop),workptr2,worklen2);
	*(TcodeByteStack + worktop + worklen2 ) = IO_NUL;

	/* Perform System function */
	/* ----------------------- */
	kx = prfo((USINT) workval1,(BPTR) (TcodeByteStack + worktop) , (USINT) worklen2);

	/* Check for Errors and UniCharacters */
	/* ---------------------------------- */
	if (( kx != MOINS_UN ) && ( workval1 <= 8 )) {
		syskey[workval1] = (EXAWORD) *(workptr2);
		}
	if ( kx == MOINS_UN ) 	{ err_val = 111; return(0); }
	else 			{ err_val = 0;   return(1); }

}

/*
 *	E X D A T W ()
 *	--------------
 *
 *	Modification de la date ou l'heure SYSTEME
 *	------------------------------------------
 */

EXAWORD	exdatw()
{
#ifdef DOS
#ifdef WIN32
extern EXAWORD datew32(EXAWORD,EXAWORD);
#else
	struct dosdate_t datwork;
	struct dostime_t timwork;
#endif /* WIN32 */
#endif /* DOS */

#ifdef PROLOGUE
	EXAWORD	dat[3];
	EXAWORD	go,x,y;
	if ( (workval1 % 4) == 0 ) { return(1); }
#endif /* PROLOGUE */

	/* Partie commune a tous les OS */
	switch (worktyp2) {
		case 0 :
		case 1 : break;
		case 2 : workval2 = bcdtoi(workptr2,worklen2); break;
		case 3 : workval2 = atoi(workptr2,worklen2);break;
		}
	worktyp2 = 1;	

#ifdef PROLOGUE
	if ( workval1 > 4 ) { go = 4; workval1 -= 4; }
	else { go = 1 ; }
	for ( y = 0, x = go; y < 3; x++, y++ ) { dat[y] = (EXAWORD) date(x); }
	dat[(workval1 - 1)] = (EXAWORD) atoi(workptr2,worklen2);
	err_val = EXER_FORBID;
	if ( go == 1 ) 	{ return( mdate(dat[0],dat[1],dat[2]) + 1); 	}
	else 		{ return( mtime(dat[0],dat[1],dat[2]) + 1); 	}  
#endif

#ifdef UNIX
	if (altdate() == MOINS_UN) 	{ err_val = EXER_FORBID; return(0); 	}
	else				{ err_val = 0; return(1);		}
#endif

#ifdef VMS
	if (altdate() == MOINS_UN) 	{ err_val = EXER_FORBID; return(0); 	}
	else				{ err_val = 0; return(1);		}
#endif

#ifdef DOS
#ifdef WIN32
	/* Implementation WIN32 */
	if (datew32(workval1,workval2) == 0) { err_val = EXER_FORBID; return(0);}
	else				     { err_val = 0; return(1);		}
#else
	/* Implementation DOS + WIN16 */
	if ( workval1 > 4 ) {
		_dos_gettime(&timwork);
		switch ( workval1 ) {
			case 5 : timwork.hour   = (EXABYTE) workval2; break;
			case 6 : timwork.minute = (EXABYTE) workval2; break;
			case 7 : timwork.second  = (EXABYTE) workval2; break;
			case 8 : timwork.hsecond  = (EXABYTE) (workval2 * 10); break;
			}		
		(VOID) _dos_settime(&timwork); return(1);
		}
	else	{ 
		_dos_getdate(&datwork);
		switch ( workval1 ) {
			case 1 : datwork.year   = workval2; break;
			case 2 : datwork.month  = (EXABYTE) workval2; break;
			case 3 : datwork.day    = (EXABYTE) workval2; break;
			}		
		(VOID) _dos_setdate(&datwork); return(1);
		}
#endif /* WIN32 */
#endif /* DOS */
}


/*
 *	C A L C S E C ( )
 *	-----------------
 *	Calculates the current second Count using DOS TIME STRUCT
 *
 */
#ifdef	DOS
#ifndef	WIN32
#ifndef	WIN16
EXALONG	calcsec()
{
	struct dostime_t nowtimer;
	EXALONG ltmvar;

	ltmvar = 0;
	_dos_gettime(&nowtimer);
	if ( nowtimer.hour > 0 ) { 
		ltmvar = nowtimer.hour;
		ltmvar *= 3600;
		}
	if ( nowtimer.minute > 0 ) { 
		ltmvar += ( ((EXALONG) nowtimer.minute ) * 60);
		}
	ltmvar += (EXALONG) nowtimer.second;
	return(ltmvar);
}
#endif
#endif
#endif


/*
 *	L L _ W A I T ( dixsec )
 *	------------------------
 *
 *	Attente de l'expiration d'un duree
 *	----------------------------------
 */

VOID ll_wait(dixsec,factor)
EXAWORD dixsec;
EXAWORD factor;	
{
#ifdef PROLOGUE
	EXABYTE	timer[8];
	BPTR	cp;
	if ( dixsec > 0 ) {
		timer[0] = 0x0080;
		cp = (BPTR) &timer[1];
		*((WPTR) cp) = ( dixsec * factor );
		cp--;
		arto(cp); wait(cp);
		}
	return;
#endif
#ifdef UNIX
	EXAWORD sec,try;
	if ( dixsec > 0 ) {
		sec = dixsec; try = 4;
		while ( (BINAIRE) sec > 0 && try > 0 ) { sec = sleep(sec); try--; }
		}
	return;
#endif
#ifdef 	DOS
#ifdef	WIN16
	/* WINDOWS 3.X */
EXTERN	void	__fastcall MTimerWait( BINAIRE );
	if ( dixsec > 0 ) {
		MTimerWait((BINAIRE) (dixsec * factor));
		}
	return;
#else
#ifdef	WIN32
	/* WINDOWS NT */
extern	void	__stdcall Sleep(unsigned long);
	unsigned long sec;
	if ( dixsec > 0 ) {
		sec = (unsigned long) dixsec;
		sec *= (unsigned long) factor;
		sec *= 100L;
		Sleep(sec);
		}
	return;
#else
	/* MSDOS */
	EXALONG	debtime,curtime,stptime;
	EXAWORD	waitctrl;
	if ( dixsec > 0 ) {
		debtime = calcsec();
		waitctrl = 0; stptime = debtime + dixsec; 
		do {
			curtime = calcsec();
			if ( curtime < debtime ) { curtime += 86400; 	}
			if ( curtime >= stptime) { return; }
			}
		while ( waitctrl == 0 );
		}
	return;

#endif	/* WIN32 */
#endif	/* WIN16 */
#endif	/* DOS */

#ifdef	VMS
	if ( dixsec > 0 ) { sleep(dixsec); }
	return;
#endif
}

extern	EXAWORD	fidperm;
extern	BPTR	fidbuff;
	
/*
 *	X _ E X E C ( fn , fa )
 *	-----------------------
 *
 *	Low level load.go operation.
 *	The value returned is ZERO if no error else Error value returned
 *	*fn	points to the file name to load and perform
 *	*fa	points to the eventual parameters to be passed
 *
 */

#ifdef	LINUX
#include "xsystem.c"
#endif

EXAWORD	x_exec(fn,fa)
BPTR	fn;
BPTR	fa;
{
	/* =-=-=-=-=-=-=-=-=-=-=-=-=-=- */
	/*	P R O L O G U E		*/
	/* =-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#ifdef PROLOGUE
	BPTR	lptr;
	EXAWORD	lerr;

	/* Establish Clean Commande initiale */
	/* --------------------------------- */
	lerr = lenuze(fa,worklen2);
	if ((lptr = (BPTR) allocate( lerr + 1 )) == (BPTR) 0) { return(114); }
	(VOID) memcpy((BPTR) lptr, (BPTR) fa , lerr); 
	*(lptr + lerr) = RETCHAR;	

	/* Check for Resident Option */
	/* ------------------------- */
	if ((fidperm & ASS_LOAD_VALID) == 0 ) {
		/* Allocate Residency Control Zone */
		/* ------------------------------- */
		if ((fidbuff = (BPTR) allocate(((8 * WORDSIZE)+17))) == (BPTR) 0) { return(ABAL_MEMORY); }
		/* Perform Load and Relocation */
		/* --------------------------- */
		if ((lerr = (EXAWORD) Chargeur((BPTR) fn,(BPTR) fidbuff)) != 0 ) { 
			(VOID) liberate((BPTR) fidbuff ); 
			(VOID) liberate((BPTR) lptr );
			errno = lerr; err_val = lerr;
			return(lerr);
			}
		/* Indicate Succesful LOAD */
		/* ----------------------- */
		fidperm |= ASS_LOAD_VALID;
		}
#ifdef	ABAL14	
	/* Watch Out For CICO PUSH Required */
	/* -------------------------------- */
	if ((worklen3 & 2) != 0) {
		prndest = 1; x_putch(IO_ESC); x_putch('>');
		}

#endif

	/* Perform Program linkage Via Call */
	/* -------------------------------- */
	lerr = ExecGo((BPTR) fidbuff,(BPTR) lptr);

#ifdef	ABAL14
	/* Watch out for CICO POP  Required */
	/* -------------------------------- */
	if ((worklen3 & 2) != 0) {
		prndest = 1; x_putch(IO_ESC); x_putch('<');
		}
#endif
	/* Check for Residancy Required */
	/* ---------------------------- */
	if (((worklen3 & 1) == 0) && ((fidperm & ASS_LOAD_VALID) != 0)) {
		DisCharge( (BPTR) fidbuff );
		liberate(fidbuff);
		fidbuff = (BPTR) 0;
		fidperm &= 0xEFFF;
		}
	/* Liberate Commande initiale Zone */
	/* ------------------------------- */
	(VOID) liberate((BPTR) lptr );
	return(lerr);
#endif

	/* =-=-=-=-=-=-=-=-=-=- */
	/*	U N I X		*/
	/* =-=-=-=-=-=-=-=-=-=- */
#ifdef UNIX
	EXAWORD	x,y;
	BPTR	fptr;
	fptr = fn; x = 0;
#ifdef	OLD_EXEC
	while (( *fptr != ' ' ) && ( *fptr != (EXABYTE) 0)) { fptr++; x++; }
#else
	while ( *fptr ) { fptr++; x++; }
#endif
#if defined(RT_AIX) || defined(LINUX)	/* 2 de plus pour mettre entre quotes */
	if ((fptr = (BPTR) malloc(worklen2 + x + 4)) == (BPTR) 0)
#else
	if ((fptr = (BPTR) malloc(worklen2 + x + 2)) == (BPTR) 0)
#endif
		return( EXER_MEMFULL );
	else	(VOID) memcpy(fptr,fn,x);
	*(fptr + x ) = ' '; x++;
	(VOID) memcpy((fptr + x),fa,worklen2);
	*(fptr + x + worklen2) = (EXABYTE) 0;
#ifdef	ABAL14
	/* Watch out for CICO PUSH Required */
	/* -------------------------------- */
	if ((worklen3 & 2) != 0) {
		prndest = 1; x_putch(IO_ESC); x_putch('>');
		}
#endif
	finterm(1);
#ifdef	LINUX
	x = system( fptr );
#else
#if defined(UNIXWARE)
	x=0; errno=0;
	x = system(fptr);
	if ( x != 0 ) {
	   	switch (errno)  {
			case	0	: x = 0; break;
			case EPERM 	: x= 58; break;
			case ENOENT 	: x= 40; break;
			case EACCES 	: x= 58; break;
			case E2BIG 	: x= 30; break;
			case ETXTBSY 	: x= 44; break;
			default 	: x= 55; break;
	     		}
	 	}
#else
	x = system(fptr); 
#endif
#endif
	initerm();
	PopCicoContext();
#ifdef	ABAL14
	/* Watch out for CICO POP  Required */
	/* -------------------------------- */
	if ((worklen3 & 2) != 0) {
		prndest = 1; x_putch(IO_ESC); x_putch('<');
		}
#endif
	free(fptr); 
	return(x);
#endif


	/* =-=-=-=-=-=-=-=-=-=- */
	/*	V M S		*/
	/* =-=-=-=-=-=-=-=-=-=- */
#ifdef VMS
	EXAWORD	x,y;
	BPTR	fptr;
	fptr = fn; x = 0;
	while (( *fptr != ' ' ) && ( *fptr != (EXABYTE) 0)) { fptr++; x++; }
	fptr = (BPTR) malloc(worklen2 + x + 2);
	if ( fptr == (BPTR) 0 ) { return(EXER_MEMFULL); }
	(VOID) memcpy(fptr,fn,x);
	*(fptr + x ) = ' '; x++;
	(VOID) memcpy((fptr + x),fa,worklen2);
	*(fptr + x + worklen2) = (EXABYTE) 0;
#ifdef	ABAL14
	/* Watch out for CICO PUSH Required */
	/* -------------------------------- */
	if ((worklen3 & 2) != 0) {
		prndest = 1; x_putch(IO_ESC); x_putch('>');
		}
#endif
	finterm(1);
	x = VMS_error(system(fptr)); 
	initerm();
#ifdef	ABAL14
	/* Watch out for CICO POP  Required */
	/* -------------------------------- */
	if ((worklen3 & 2) != 0) {
		prndest = 1; x_putch(IO_ESC); x_putch('<');
		}
#endif
	free(fptr); return(x);
#endif

	/* =-=-=-=-=-=-=-=-=-=- */
	/*	M S - D O S	*/
	/* =-=-=-=-=-=-=-=-=-=- */
#ifdef DOS
	EXAWORD	x,y;
	EXAWORD	indent;
	BPTR	cmdptr;
	BPTR	specptr;


	/* -------------------------------------------------	*/
	/* fn		==>	Command to be executed		*/
	/* fa		==>	Points to eventual Arguament	*/
	/* worklen2		Length of eventual Arguament	*/
	/* --------------------------------------------------	*/
	/* Create Command line structure for COMMAND.COM call 	*/
	/* In temporary work zone			      	*/
	/* -------------------------------------------------- 	*/
	cmdptr = (BPTR) (TcodeByteStack + worktop ); indent = 1;

// YT201098 : set the first char to the space ' ' schar
#ifdef WIN32
	cmdptr[0] = ' ';
#endif

	memcpy( (BPTR) (cmdptr + indent) ,(BPTR) "/C " , 3); indent += 3;

	/* Transfer Command name behind COMMAND.COM /C Flag */
	/* ------------------------------------------------ */
	while ( *fn != 0 ) { *(cmdptr + indent) = *(fn++); indent++; }

	/* Calculate and transfer usable length of Arguament */
	/* ------------------------------------------------- */
	if ((worklen2 = lenuze(fa,worklen2)) > 0) {
		*(cmdptr + indent) = ' '; indent++;
		memcpy( (BPTR) (cmdptr + indent) , fa , worklen2 );
		indent += worklen2;
		}

	/* Terminate Correctly for COMMAND.COM */
	/* ----------------------------------- */
	*(cmdptr + indent) = (EXABYTE) RETCHAR;

#ifndef WIN32
	/* Ensure Command length Correct and Establish */
	/* ------------------------------------------- */
	if ( indent > 128 ) 	{ return(30); 			}
	else			{ *cmdptr = (EXABYTE) indent; 	}
#endif

	/* Collect COMMAND.COM envirronment variable value */
	/* ----------------------------------------------- */
	if ((specptr = (BPTR) getenv((BPTR) "COMSPEC")) != (BPTR) 0) {
#ifdef	ABAL14
		/* Watch out for CICO PUSH Required */
		/* -------------------------------- */
		if ((worklen3 & 2) != 0) {
			prndest = 1; x_putch(IO_ESC); x_putch('>');
			}
#endif
		/* Liberate Terminal */
		/* ----------------- */
		finterm(1);
#ifdef RT_AIX
		raz_timer();
#endif
		/* Excute command via DOS FUNCTION 4B00H */
		/* ------------------------------------- */
		x = ll_loadgo((BPTR) specptr,(BPTR) cmdptr);

		/* Restart terminal */
		/* ---------------- */
		initerm();
#ifdef	ABAL14
		/* Watch out for CICO POP  Required */
		/* -------------------------------- */
		if ((worklen3 & 2) != 0) {
			prndest = 1; x_putch(IO_ESC); x_putch('<');
			}
#endif
		}
	else	{
		/* Unable to find COMSPEC */
		/* ---------------------- */
		x = MOINS_UN; errno = 2;
		}
			
	/* Handle eventuelle errors */
	/* ------------------------ */
	if ( x == MOINS_UN) {
		switch ( errno ) {
			case 1 : return(0);
			case 3 :
			case 2 : return(40);
			case 4 : return(51);
			case 5 : return(58);
			case 8 : return(27);
			case 10: return(38);
			case 11: return(36);
			}
		return(errno);
		}
	else	{
		return(0);
		}
#endif
}

