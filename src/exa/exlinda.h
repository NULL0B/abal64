/*
 *
 *		E X E C U T E U R 	A . B . A . L
 *		-------------------------------------
 *
 *		Copyright (c) 1987,2002 Amenesik / Sologic  .
 *
 *		Module  :	EXLINDA.H
 *		Version :	2.2b
 *		Date 	:	16/12/2002
 */
 
/* Mises a jour :
 * ------------
 *	------------ 2.2b -------------------------------------------------
 */

#ifndef  EXLINDAH	/* If not already included			*/

#define  EXLINDAH	/* Avoid multiple inclusions			*/
#include "ex.h"		/* Include general definitions			*/

#define	TASKPTR		struct abal_task PTR
#define	IPCPTR		struct abal_ipc  PTR
#define LINDAPTR	struct abal_linda PTR

extern	EXAWORD	MaxIpcSem;

struct	abal_task {
	TASKPTR	next;
	TASKPTR	previous;
	int	identity;
	BPTR	child_ss;
	};

struct	abal_ipc {
	IPCPTR 	next;
	IPCPTR	previous;
	int	sender;
	int	receiver;
	EXAWORD	length;
	BPTR	message;
	};

struct	abal_linda {
	TASKPTR	TaskHeap;
	IPCPTR	IpcHeap;
	IPCPTR	IpcRoot;
	BPTR	Semaphores;
	};

LINDAPTR	TaskManager;


#endif   /* ! EXLINDAH */
	 /* ---------- */
