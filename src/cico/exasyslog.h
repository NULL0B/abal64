#ifndef	_exasyslog_h
#define	_exasyslog_h

// -------------------------------------------------
// MISSING FILE : Reconstructed and Deduced Contents
// -------------------------------------------------

#ifdef	UNIX
#define	REALSYSLOG
#include <syslog.h>
#else
#undef 	REALSYSLOG
#endif

#define SYSLOG_ASSIGN		0x001
#define SYSLOG_ASSIGN_OPEN	0x002
#define SYSLOG_LOAD		0x004
#define SYSLOG_PROC		0x008
#define SYSLOG_CHILD		0x010
#define SYSLOG_CICO		0x020

#define	EXA_SYSLOG_CRITICAL	1
#define	EXA_SYSLOG_ERROR	2
#define	EXA_SYSLOG_WARNING	3
#define	EXA_SYSLOG_INFO		5	

#define	IsExaSysLog() 		 (SYSLOG_ASSIGN | SYSLOG_ASSIGN_OPEN | SYSLOG_LOAD | SYSLOG_PROC | SYSLOG_CHILD)

#include "extypes.h"

#ifdef	_EXMAIN_C
EXABYTE	SysLogBuffer[512];
BPTR	TFN=(BPTR) 0;

/*	---------	*/
/*	ExaSysLog	*/
/*	---------	*/
VOID	ExaSysLog(EXAWORD level, BPTR buffer)
{
#ifdef	REALSYSLOG
	openlog("exa64",LOG_CONS|LOG_PID, LOG_USER);
	switch ( level )
	{
	case	EXA_SYSLOG_CRITICAL	:
		syslog(LOG_CRIT,"%s",buffer);
		break;
	case	EXA_SYSLOG_ERROR	:
		syslog(LOG_ERR,"%s",buffer);
		break;
	case	EXA_SYSLOG_WARNING	:
		syslog(LOG_WARNING,"%s",buffer);
		break;
	case	EXA_SYSLOG_INFO		:
	default				:
		syslog(LOG_INFO,"%s",buffer);
		break;
	}
	closelog();
#else
	FILE	*	h;
	if ((h = fopen("/tmp/syslog.exa","a")) != (FILE *) 0)
	{
		fprintf(h,"%lu:exa:%u:syslog:%u:message:%s\n",time(NULL),getpid(),level,buffer);
		fclose(h);
	}
#endif
}

/*	--------------	*/
/*	CheckExaSysLog	*/
/*	--------------	*/
EXAWORD	CheckExaSysLog()
{
	return(1);
}

#else
extern EXABYTE	SysLogBuffer[512];
extern BPTR	TFN;
#endif

#endif /* _exasyslog_h */

