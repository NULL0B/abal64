/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1990 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXLINDA - H				*/
/*		Date 	:	07/05/1990				*/
/*		Version :	1.5a 					*/
/*									*/
/*----------------------------------------------------------------------*/

#ifndef  EXLINDAH	/* If not already included			*/

#define  EXLINDAH	/* Avoid multiple inclusions			*/
#include "ex.h"		/* Include general definitions			*/

#define	TASKPTR		struct abal_task SPTR
#define	IPCPTR		struct abal_ipc  SPTR
#define LINDAPTR	struct abal_linda SPTR

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
