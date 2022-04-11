#ifndef	_abalcico_h
#define	_abalcico_h

#ifndef	_ixcico_c
#define	SCOPE extern
#else
#define	SCOPE 
#endif

SCOPE int	prndest;        	/* Destination to print         	*/
SCOPE int	prnmode;        	/* Nature of Print Device       	*/
SCOPE int	prnleng;        	/* Length of  PRINT=0 buffer    	*/
SCOPE unsigned char * prnptr;		/* variable de reception pour PRINT()	*/
SCOPE unsigned long 	prnseek;        /* Print file seek value        	*/
SCOPE void * 	prnfid;               	/* CICO System file handle      	*/
SCOPE int	prndex;         	/* Usage  of  PRINT=0 buffer    	*/
SCOPE int	prncol;         	/* Current printer column       	*/
SCOPE int	prnlin;         	/* Line count and column count  	*/
SCOPE int	err_val;        	/* Global ABAL Error variable   	*/

#endif	/* _abalcico_h */

