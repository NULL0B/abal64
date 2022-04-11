/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1994 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXLINDA - C				*/
/*		Date 	:	07/03/1994				*/
/*		Version :	2.1b 					*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXLINDA_C
#define	_EXLINDA_C

#ifdef	ABAL21
#ifndef	DOS
#define	ABALMT
#endif
#endif

#include "exlinda.h"	/* Include module specific definitions header	*/

/*
 *	This source describes all functions required for the management
 *	of ABAL++ application threads.
 *
 *	task_identity = EVENT(10)	:	Create Thread 
 *	EVENT(10) = task_identity	:	Kill Thread
 *	task_identity = EVENT(11)	:	Identity of current thread
 *	EVENT(11) = task_identity	:	Send interrupt to thread
 *	KBF(1000+task_identity) = msg	:	Send message to thread
 *	msg = KBF(1000+task_identity)	:	Receive message from thread
 *
 *	EVENT(3) = options		:	Set options mask :
 *						1  Wait(1) or Test(0) Message  
 *						2  No Error on IpcRecv
 *
 *	EVENT(4) = semaphore_id		:	Raise semaphore
 *	EVENT(5) = semaphore_id		:	Drop semaphore
 *	EVENT(6) = semaphore_id		: 	Wait till semaphore drops
 *
 *	The following semaphores are used by the executer to manage shared
 *	ressources :
 *	
 *			0	:	IPC Message Send and Receive
 *			1	:	Memory Allocation and Liberation
 *			2	:	Dynamic Library Function Calls
 *			3	:	ASK Instruction and Keyboard usage
 *
 */	

EXTERN	EXAWORD	EventChannel;

#ifdef	UNIX
#ifndef	VMS			/* ------------------------------------ */
#include "exmtunix.c"		/* Unix Task and Semaphore functions	*/
#else				/* ------------------------------------ */
#include "exmtvms.c"		/* VMS Task and Semaphore functions     */
#endif				/* ------------------------------------ */
#endif

EXAWORD	LowLevelSpawn()
{
#ifdef	ABALMT
	return( low_level_spawn() );
#else
	err_val = 56;
	return( MOINS_UN );
#endif
}

EXAWORD	LowLevelKill(int chid)
{
#ifdef	ABALMT
	return( low_level_kill(chid) );
#else
	err_val = 56;
	return( MOINS_UN );
#endif
}

EXAWORD	allocation_flag;
EXAWORD	allocation_counter=0;
EXAWORD	liberation_counter=0;
EXAWORD	allocation_tracer=0;

EXAWORD	get_allocation_tracer()
{
	return( allocation_tracer );
}

EXAWORD	get_allocation_counter()
{
	EXAWORD	temp;
	temp = allocation_counter;
	allocation_counter = 0;
	return( temp );
}

EXAWORD	get_liberation_counter()
{
	EXAWORD	temp;
	temp = liberation_counter;
	liberation_counter = 0;
	return( temp );
}

VOID	initialise_mallocate()
{
	BPTR	mptr;
	allocation_flag = 0;
#ifdef	PROLOGUE
#ifdef	ABAL21
	mptr = (BPTR) "2ALLOCATE";
#else
	mptr = (BPTR) "1ALLOCATE";
#endif
	allocation_flag = (EXAWORD) *mptr;
#endif
	return;
}

#ifdef	PROLOGUE
VPTR	allocate( nombre )
EXAWORD	nombre;
{
	BPTR	rptr;
#ifndef	PROLOGUE2
	BPTR	mallocate( EXAWORD );
#endif
#ifdef	ABALMT
	VOID	IpcRaise( EXAWORD );
	VOID	IpcDrop( EXAWORD );
	IpcRaise(_SEMAPHORE_ALSM);
#endif

#ifndef	PROLOGUE2
	if ( allocation_flag == '2' )
		rptr = mallocate( nombre );
	else
#endif
		rptr = malloc( nombre );
	allocation_tracer++;
	allocation_counter++;
#ifdef	ABALMT
	IpcDrop(_SEMAPHORE_ALSM);
#endif
	return( rptr );
}

VOID	liberate( xptr )
VPTR	xptr;
{
#ifndef	PROLOGUE2
	VOID	mliberate( VPTR );
#endif
#ifdef	ABALMT
	VOID	IpcRaise( EXAWORD );
	VOID	IpcDrop( EXAWORD );
	IpcRaise(_SEMAPHORE_ALSM);
#endif

#ifndef	PROLOGUE2
	if ( allocation_flag == '2' )
		mliberate( xptr );
	else
#endif
		free( xptr );
	allocation_tracer--;
	liberation_counter++;

#ifdef	ABALMT
	IpcDrop(_SEMAPHORE_ALSM);
#endif
	return;
}
#endif

VOID	AffectResult(desc,Result_Register,value)
EXAWORD	desc;
EXAWORD	Result_Register;
EXAWORD	value;
{
	if ((desc & 0x0060) == 0x0060) {
		freg [Result_Register] = value;
		xreg [Result_Register] = 0;
		}
	else	{
		/* Select Result Data Type */
		/* ----------------------- */
		switch (( worktyp1 & 0x0003 )) {
			case 0 : *workptr1 = (EXABYTE) value; break;
			case 1 : balputw(value,workptr1);  break;
			}
		}
	return;
}

VOID	reset_task_manager()
{
#ifdef	ABALMT
	TaskManager = (LINDAPTR) 0;
	reset_parent_identity();
#endif
	return;
}

VOID	initialise_task_control()
{
#ifdef	ABALMT
	reset_task_manager();
	if ((TaskManager = allocate( sizeof( struct abal_linda ) )) != (LINDAPTR) 0) {
		TaskManager->TaskHeap = (TASKPTR) 0;	
		TaskManager->IpcHeap  = (IPCPTR)  0;
		TaskManager->IpcRoot  = (IPCPTR)  0;
		TaskManager->Semaphores = (BPTR) 0;
		if ((TaskManager->Semaphores = allocate( (MaxIpcSem+_SEMAPHORES_EXA) )) != (BPTR) 0)
			memset( TaskManager->Semaphores, 0, (MaxIpcSem+_SEMAPHORES_EXA) );
		}
#endif
	return;
}

VOID	liberate_task_control(int mode)
{
#ifdef	ABALMT
	TASKPTR		ltask;
	IPCPTR		lipc;
	BPTR		lsem;
	LINDAPTR	lman;

	if ( TaskManager != (LINDAPTR) 0 ) {
		/* Liberate IPC Tasks */
		/* ------------------ */
		while (( ltask = TaskManager->TaskHeap ) != (TASKPTR) 0 ) {
			TaskManager->TaskHeap = ltask->next;
			if ( mode )
				low_level_kill( ltask->identity );
			if ( ltask->child_ss != (BPTR) 0) {
				liberate_tcode_stacks( ltask->child_ss ); 
				free( ltask->child_ss );
				}
			liberate( ltask );
			}
		/* Liberate IPC Messages */
		/* --------------------- */
		while (( lipc = TaskManager->IpcHeap ) != (IPCPTR) 0 ) {
			TaskManager->IpcHeap = lipc->next;
			if ( lipc->message != (BPTR) 0)
				liberate( lipc->message );
			liberate( lipc );
			}
		if ( TaskManager->Semaphores != (BPTR) 0) {
			lsem = TaskManager->Semaphores;
			TaskManager->Semaphores = (BPTR) 0;
			liberate( lsem );
			}
		lman = TaskManager;
		TaskManager = (LINDAPTR) 0;
		liberate( lman );
		}
#endif
	return;
}

TASKPTR	create_task_entry()
{
	TASKPTR	ltask;

	/* Allocate Task control structure */
	/* ------------------------------- */
	if ((ltask = allocate( sizeof( struct abal_task ) )) != (TASKPTR) 0) {
		ltask->previous = (TASKPTR) 0;
		if ( TaskManager->TaskHeap != (TASKPTR) 0 )
			TaskManager->TaskHeap->previous = ltask;
		ltask->next = TaskManager->TaskHeap;
		ltask->child_ss = (BPTR) 0;
		TaskManager->TaskHeap    = ltask;
		}
	else	err_val = 27;
	return( ltask );
}

EXAWORD	event_spawn()
{
#ifdef	ABALMT
	EXAWORD	childid=0;
#ifndef	UNIX
	BPTR	get_child_stack();
#endif
	TASKPTR	ltask=(TASKPTR) 0;

	if ((ltask = create_task_entry()) == (TASKPTR) 0)
		return( MOINS_UN );

	/* Generate child (child = 0)   */
	/* ---------------------------- */
	switch ((childid = LowLevelSpawn())) {

		/* Error Return         */
		/* -------------------- */
		case MOINS_UN 	:

			/* Store Error Result to destination */
			/* --------------------------------- */
			if ((TaskManager->TaskHeap = TaskManager->TaskHeap->next) != (TASKPTR) 0)
				TaskManager->TaskHeap->previous = (TASKPTR) 0;
			liberate( ltask );
			return( MOINS_UN );
			
		/* Child Process Return */
		/* -------------------- */
		case 0 		: 

			/* Forget the Current Task Context Image */
			/* ------------------------------------- */
#ifdef	UNIX
			liberate_task_control(0);
#endif
			/* Allocate all virtual stacks */
			/* --------------------------- */
			if ( tcode_stack_allocation(0) == SOFTERROR ) {
				(void) LowLevelKill(0);
				return( MOINS_UN );
				}
			return( 0 );

		default         :

			/* Establish Parent Return value */
			/* ----------------------------- */
			ltask->identity = childid;
#ifndef	UNIX
			ltask->child_ss = get_child_stack();
#endif
			return( childid );

		}

#else
		err_val = 56;
		return( MOINS_UN );
#endif
}

TASKPTR	locate_task_control( childid )
EXAWORD	childid;
{
	TASKPTR	ltask;

	if ((ltask = TaskManager->TaskHeap) != (TASKPTR) 0) {
		do 	{
			if ( ltask->identity == childid )
				break;
			}
		while ((ltask = ltask->next) != (TASKPTR) 0);
 		}
	return( ltask );
}

VOID	release_semaphores( childid )
EXAWORD	childid;
{
#ifdef	ABALMT
	EXAWORD	i;
	BPTR	sptr;

	if ((sptr = TaskManager->Semaphores) != (BPTR) 0) {
		if ( childid == 0 )
			childid = get_parent_identity();
		childid++; childid &= 0x00FF;
		for ( i= 0; i < (MaxIpcSem+_SEMAPHORES_EXA); i++ )
			if ( *(sptr+i) == childid )
				*(sptr+i) = 0;
		}
#endif
	return;
}

EXAWORD	event_kill( childid )
int	childid;
{
#ifdef	ABALMT
	EXAWORD	lerror;
	TASKPTR	ltask=(TASKPTR) 0;

	if ( childid != 0 ) {
		if ((ltask = locate_task_control( childid )) == (TASKPTR) 0 )
			return( GOODRESULT );

		}

	/* DO NOT ALLOW PARENT TO COMMIT SUICIDE */
	/* ------------------------------------- */
	if (( childid == 0 ) && ( get_parent_identity() == 0 ))
		return( GOODRESULT );

	/* Release all semaphores for this TASK */
	/* ------------------------------------ */
	release_semaphores( childid );

	/* Perform low level operation and return status */
	/* --------------------------------------------- */
	lerror = LowLevelKill( childid );

	if ( ltask != (TASKPTR) 0 ) {
		if ( ltask->previous != (TASKPTR) 0) 
			ltask->previous->next = ltask->next;
		else	TaskManager->TaskHeap = ltask->next;
		if ( ltask->next != (TASKPTR) 0)
			ltask->next->previous = ltask->previous;
		if ( ltask->child_ss != (BPTR) 0) {
			liberate_tcode_stacks( ltask->child_ss ); 
			free( ltask->child_ss );
			}
		liberate( ltask );
		}


	return( GOODRESULT );
#else
	err_val = 56;
	return( SOFTERROR );
#endif
}
#ifdef	ABAL21
VOID	ensure_parent()
{
#ifndef	DOS
	if ( get_parent_identity() == 0 )
		return;
#endif
	LowLevelKill(0);
	return;
}
#endif
VOID	IpcRaise( semaphid )
EXAWORD	semaphid;
{
#ifdef	ABALMT
	if (( TaskManager != (LINDAPTR) 0 )
	&&  ( TaskManager->Semaphores != (BPTR) 0 )) {
		semaphid %= (MaxIpcSem+_SEMAPHORES_EXA);
		low_level_raise((BPTR)( TaskManager->Semaphores + semaphid) );
		}
#endif
	return;
}
VOID	IpcIncrement(semaphid )
EXAWORD	semaphid;
{
#ifdef	ABALMT
	if (( TaskManager != (LINDAPTR) 0 )
	&&  ( TaskManager->Semaphores != (BPTR) 0 )) {
		semaphid %= (MaxIpcSem+_SEMAPHORES_EXA);
		TaskManager->Semaphores[semaphid]++;
		}
#endif
	return;
}

VOID	IpcDrop( semaphid )
EXAWORD	semaphid;
{
#ifdef	ABALMT
	if (( TaskManager != (LINDAPTR) 0 )
	&&  ( TaskManager->Semaphores != (BPTR) 0 )) {
		semaphid %= (MaxIpcSem+_SEMAPHORES_EXA);
		low_level_drop((BPTR)( TaskManager->Semaphores + semaphid) );
		}
#endif
	return;
}
VOID	IpcDecrement(semaphid )
EXAWORD	semaphid;
{
#ifdef	ABALMT
	if (( TaskManager != (LINDAPTR) 0 )
	&&  ( TaskManager->Semaphores != (BPTR) 0 )) {
		semaphid %= (MaxIpcSem+_SEMAPHORES_EXA);
		TaskManager->Semaphores[semaphid]--;
		}
#endif
	return;
}

VOID	IpcSynch( semaphid )
EXAWORD	semaphid;
{
#ifdef	ABALMT
	if (( TaskManager != (LINDAPTR) 0 )
	&&  ( TaskManager->Semaphores != (BPTR) 0 )) {
		semaphid %= (MaxIpcSem+_SEMAPHORES_EXA);
		low_level_synch((BPTR)( TaskManager->Semaphores + semaphid ));
		}
#endif
	return;
}

VOID	raise_db_entry()
{
#ifdef	ABALMT
	IpcRaise(_SEMAPHORE_DEBUG);
#endif
}

VOID	drop_db_entry()
{
#ifdef	ABALMT
	IpcDrop(_SEMAPHORE_DEBUG);
#endif
}

EXAWORD	IpcSend( destin, bptr, blen )
EXAWORD	destin;
BPTR	bptr;
EXAWORD	blen;
{
#ifdef	ABALMT
	IPCPTR	lipc;
	TASKPTR	ltask;
	if ((destin != 0)
	&&  ((ltask = locate_task_control( destin )) == (TASKPTR) 0)) {
		err_val = 23;
		return( SOFTERROR );
		}
	if ((lipc = allocate( sizeof( struct abal_ipc ))) != (IPCPTR) 0) {
		if ((lipc->message = allocate( blen )) != (BPTR) 0) {
			memcpy( lipc->message, bptr, blen );
			lipc->length   = blen;
			lipc->receiver = destin;
			lipc->sender   = get_parent_identity();
			IpcRaise(_SEMAPHORE_IPC);
			if ((lipc->next = TaskManager->IpcHeap) != (IPCPTR) 0)
				TaskManager->IpcHeap->previous = lipc;
			else	TaskManager->IpcRoot = lipc;
			lipc->previous = (IPCPTR) 0;
			TaskManager->IpcHeap = lipc;
			IpcDrop(_SEMAPHORE_IPC);
			return( GOODRESULT );
			}
		liberate( lipc );
		}
	err_val = 27;
	return( SOFTERROR );
#else
	err_val = 56;
	return( SOFTERROR );
#endif
}

#ifdef	ABALMT
VOID	remove_message( lipc )
IPCPTR	lipc;
{
	if ( lipc == (IPCPTR) 0)
		return;
	if ( lipc->next == (IPCPTR) 0) {
		if ((TaskManager->IpcRoot = lipc->previous) == (IPCPTR) 0)
			TaskManager->IpcHeap = (IPCPTR) 0;
		else	lipc->previous->next = (IPCPTR) 0;
		}
	else	{
		if ((lipc->next->previous = lipc->previous) != (IPCPTR) 0)
			lipc->previous->next = lipc->next;
		else	TaskManager->IpcHeap = lipc->next;
		}
	if ( lipc->message != (BPTR) 0)
		liberate( lipc->message );
	liberate( lipc );
	return;
}
#endif


EXAWORD	IpcRecv( sender, bptr, blen, mode )
EXAWORD	sender;
BPTR	bptr;
EXAWORD	blen;
EXAWORD	mode;	/* 1 : Wait , 0 : No Wait ie Test */
{
#ifdef	ABALMT
	TASKPTR	ltask;
	IPCPTR	lipc;
	EXAWORD	whoami = get_parent_identity();
	EXAWORD	lerr=0;

	if ((sender != 0) && (sender != MOINS_UN)
	&&  ((ltask = locate_task_control( sender )) == (TASKPTR) 0)) {
		err_val = 23;
		return( SOFTERROR  );
		}
	while ( 1 ) {
		IpcRaise(_SEMAPHORE_IPC);
		if ((lipc = TaskManager->IpcRoot) != (IPCPTR) 0) {
			do	{
				if (( lipc->receiver == whoami )
				&&  (( sender == MOINS_UN )
				||   ( lipc->sender == sender ))) {
					if ( blen != 0 )
						memset( bptr, ' ', blen );
					else	{
						blen = lipc->length;
						TcodePmot((bptr-2),blen);
						}
					if ( blen < lipc->length )
						lerr = 63;
					else	blen = lipc->length;
					memcpy( bptr, lipc->message, blen );
					remove_message( lipc );					
					IpcDrop(_SEMAPHORE_IPC);
					if (((err_val = lerr) != 0) && (!(EventChannel & 2)))
						return( SOFTERROR );
					else	return( blen );
					}
				}
			while ((lipc = lipc->previous) != (IPCPTR) 0);
			}
		IpcDrop(_SEMAPHORE_IPC);
		ll_wait(1,1);
		if ( ! mode ) {
			if ( EventChannel & 2 ) { 
				memset( bptr, ' ', blen );
				return( GOODRESULT );
				}
			else	{
				err_val = 48;
				return( SOFTERROR );
				}
			}
		}
			
#else
	err_val = 56;
	return( SOFTERROR );
#endif
}


VOID	IpcInterrupt( jobid )
EXAWORD	jobid;
{
#ifdef	ABALMT
	TASKPTR	ltask;
	if (( jobid != 0 )
	&&  ((ltask = locate_task_control( jobid )) != (TASKPTR) 0))
		low_level_interrupt( ltask->child_ss );
#endif
	return;
}

#endif	/* _EXLINDA_C */
	/* ---------- */
