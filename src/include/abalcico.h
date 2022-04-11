#ifndef	_abalcico_h
#define	_abalcico_h

extern  EXAWORD	prndest;        	/* Destination to print         	*/
extern  EXAWORD	prnmode;        	/* Nature of Print Device       	*/
extern  EXAWORD	prnleng;        	/* Length of  PRINT=0 buffer    	*/
extern 	unsigned char * prnptr;		/* variable de reception pour PRINT()	*/
extern  unsigned long 	prnseek;        /* Print file seek value        	*/
extern  void * 	prnfid;               	/* CICO System file handle      	*/
extern  EXAWORD	prndex;         	/* Usage  of  PRINT=0 buffer    	*/
extern  EXAWORD	prncol;         	/* Current printer column       	*/
extern  EXAWORD prnlin;         	/* Line count and column count  	*/
extern  EXAWORD	err_val;        	/* Global ABAL Error variable   	*/

#endif	/* _abalcico_h */

