/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1990 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXHEAD - C				*/
/*		Date 	:	06/02/1990				*/
/*		Version :	1.2c (Amenesik / Sologic 3 Diffusion)		*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXSEMAPH_H
#define	_EXSEMAPH_H

#define	_SEMAPHORE_IPC 	 0	/* Protects IPC Send and receive	*/
#define	_SEMAPHORE_ALSM	 1	/* Protects Memory Allocation		*/
#define	_SEMAPHORE_CICO	 2	/* Protects Console Input Output	*/
#define	_SEMAPHORE_DLL 	 3	/* Protects Dynamic Libraries		*/
#define	_SEMAPHORE_DEBUG 4	/* Protects Debugger			*/

#define	_SEMAPHORES_EXA	 5	/* Protects Internal Semaphores		*/

#define	_MAX_SEMAPHORES	64	/* Default Number of Semaphores		*/

#endif	/* _EXSEMAPH_H */
	/* ----------- */

