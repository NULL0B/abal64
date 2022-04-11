#ifndef	_extask_c
#define	_extask_c

#include "extask.h"

static	BYTE	thbuffer[64];

VOID	restore_stacks(  struct execution_thread PTR xptr )
{
	xptr->ip_next 	= ip_next;
	xptr->mindex  	= mindex; 
	xptr->worktop 	= worktop;
	xptr->workhold 	= workhold;
	xptr->pushtop 	= pushtop;
	xptr->pushhold 	= pushhold;
	memcpy(TcodeWordStack, xptr->ws, (diezstk * sizeof( EXAWORD )) );
	memcpy(TcodePushStack, xptr->pps, (diezstk * sizeof( EXAWORD )) );
	memcpy(TcodePtrStack, xptr->ps, (diezstk * sizeof( EXAWORD )) );
	memcpy(TcodeByteStack, xptr->bs, (diezstk * sizeof( EXAWORD )) );
	return;
}


EXAWORD	task_stack_allocation( struct execution_thread PTR xptr, EXAWORD mode )
{
	xptr->ip_next 	= ip_next;
	xptr->mindex  	= mindex;
	xptr->worktop 	= worktop;
	xptr->workhold 	= workhold;
	xptr->pushtop 	= pushtop;
	xptr->pushhold 	= pushhold;
	xptr->stackhold = StackHold;

/*	Allocation of Gosub's Stack 	*/
/*	---------------------------	*/
	if (!(mode & 1 ))
		xptr->ws = TcodeWordStack;
	else if (!(xptr->ws = (WPTR) calloc((USINT)  diezstk , sizeof(EXAWORD)))) {
		err_val = 27;
		return(SOFTERROR);
		}
	else	memcpy(xptr->ws, TcodeWordStack, (diezstk * sizeof( EXAWORD )) );

/*	Allocation of PushPop Stack 	*/
/*	---------------------------	*/
	if (!(mode & 1 ))
		xptr->pps = TcodePushStack;
	
	else if (!(xptr->pps = (WPTR) calloc((USINT)  diezstk , sizeof(EXAWORD)))) {
		err_val = 27;
		return(SOFTERROR);
		}
	else	memcpy(xptr->pps, TcodePushStack, (diezstk * sizeof( EXAWORD )) );

/*	Allocation of Pointer's Stack	*/
/*	-----------------------------	*/
	if (!(mode & 1 ))
		xptr->ps = TcodePtrStack;
	else if (!(xptr->ps = (BPTR PTR) calloc((USINT)  diezstk , (USINT) sizeof(BPTR ) ))) {
		err_val = 27;
		return(SOFTERROR);
		}
	else	memcpy(xptr->ps, TcodePtrStack, (diezstk * sizeof( BPTR )) );

/*	Allocation of Temporary WorkZone	*/
/*	--------------------------------	*/
	if (!(mode & 1 ))
		xptr->bs = TcodeByteStack;
	else if (!(xptr->bs = (BPTR ) calloc((USINT) dieztmp,(USINT) 1))) {
		err_val = 27;
		return(SOFTERROR);
		}
	else	memcpy(xptr->bs, TcodeByteStack, dieztmp );
	return( GOODRESULT );
}

struct execution_thread PTR liberate_thread(struct execution_thread PTR xptr)
{
	if ( xptr ) {

		/* liberate stacks */
		/* --------------- */
		if ( xptr->bs  ) liberate( xptr->bs );
		if ( xptr->ws  ) liberate( xptr->ws );
		if ( xptr->ps  ) liberate( xptr->ps );
		if ( xptr->pps ) liberate( xptr->pps );

		/* liberate context */
		/* ---------------- */
		liberate( xptr );
		xptr = (struct execution_thread PTR) 0;
		}
	return( xptr );
}

struct execution_thread PTR allocate_thread(EXAWORD mode)
{
	struct execution_thread PTR xptr;

	if (!( xptr = allocate( sizeof( struct execution_thread ) ) ))
		return(xptr);

	else	{
		xptr->bs	=
		xptr->ws	=
		xptr->ps	=
		xptr->pps	=
		xptr->gpt	=
		xptr->ctx	= (VPTR) 0;

		xptr->handle	= (EX_FILE_HANDLE) 0;

		xptr->previous  =
		xptr->next      = (struct execution_thread PTR) 0;

		xptr->wordsize	= WORDSIZE;
		xptr->cycles 	= 10;
		xptr->priority 	= 1;
		xptr->state	= 0;
		xptr->synchronise = 0;
		xptr->parentid	= 0;
		xptr->threadid	= 0;
		xptr->event	= 0;
		xptr->stackhold = 0;
		xptr->eventadr	= 0;

		xptr->cur_seg	=
		xptr->procid	=
		xptr->datamax	=
		xptr->datadex	=
		xptr->datapnt	=
		xptr->sicico	=
		xptr->timersem	= 0;

		if ( task_stack_allocation( xptr, mode ) != SOFTERROR )
			return( xptr );
		else	return( liberate_thread( xptr ) );
		}
}

VOID	push_all_registers(struct execution_thread PTR xptr)
{
	memcpy( xptr->dx, freg, (sizeof(EXAWORD) * WORKSIZE) );
	memcpy( xptr->fx, xreg, (sizeof(EXAWORD) * WORKSIZE) );
	memcpy( xptr->ix, ireg, (sizeof(EXAWORD) * WORKSIZE) );
	memcpy( xptr->ax, areg, (sizeof(EXAWORD) * WORKSIZE) );
	return;
}

VOID	save_thread(struct execution_thread PTR xptr)
{
	xptr->ip_next 	= ip_next;
	xptr->mindex  	= mindex; 
	xptr->worktop 	= worktop;
	xptr->workhold 	= workhold;
	xptr->pushtop 	= pushtop;
	xptr->pushhold 	= pushhold;

	xptr->libraries	= FuseCount;
	xptr->glt	= FuseBase;

	xptr->ctx 	= TcodeContext;
	xptr->gpt 	= TcodeProcTable;
	xptr->gct	= GlobalConstants;
	xptr->lct	= TcodeConstants;
	xptr->gdt	= GlobalDataTable;
	xptr->gds	= GlobalDataSegment;
	xptr->ldt	= LocalDataTable;
	xptr->lds	= LocalDataSegment;
	xptr->cs	= TcodeSegment;
	xptr->csip	= fdex;
#ifdef	VERSION666
	xptr->wordsize	= WORDSIZE;
#endif
	xptr->handle	= TcodeFileHandle;

	xptr->sicico	= sicico;
	xptr->timersem	= timersem;
	xptr->cur_seg	= cur_seg;
	xptr->procid	= procid;
	xptr->datamax	= datamax;
	xptr->datadex	= datadex;
	xptr->datapnt	= datapnt;
	xptr->stackhold = StackHold;
	xptr->eventadr	= eventadr;

	push_all_registers( xptr );

	return;
}

VOID	pop_all_registers( struct execution_thread PTR xptr)
{
	memcpy( freg, xptr->dx, (sizeof(EXAWORD) * WORKSIZE) );
	memcpy( xreg, xptr->fx, (sizeof(EXAWORD) * WORKSIZE) );
	memcpy( ireg, xptr->ix, (sizeof(EXAWORD) * WORKSIZE) );
	memcpy( areg, xptr->ax, (sizeof(EXAWORD) * WORKSIZE) );
	return;
}

VOID	restore_thread(struct execution_thread PTR xptr)
{
	ip_next 		= xptr->ip_next;
	mindex  		= xptr->mindex; 
	worktop 		= xptr->worktop;
	workhold	 	= xptr->workhold;
	pushtop 		= xptr->pushtop;
	pushhold 		= xptr->pushhold;

	TcodeByteStack 		= xptr->bs;
	TcodeWordStack 		= xptr->ws;
	TcodePtrStack 		= xptr->ps;
	TcodePushStack	 	= xptr->pps;

	TcodeContext 		= xptr->ctx;
	TcodeProcTable		= xptr->gpt;
	FuseCount 		= xptr->libraries;
	FuseBase		= xptr->glt;

	GlobalConstants		= xptr->gct;
	TcodeConstants		= xptr->lct;
	GlobalDataTable		= xptr->gdt;
	GlobalDataSegment	= xptr->gds;
	LocalDataTable		= xptr->ldt;
	LocalDataSegment	= xptr->lds;
	TcodeSegment 		= xptr->cs;
	fdex 			= xptr->csip;
#ifdef	VERSION666
	WORDSIZE		= xptr->wordsize;
#endif
	TcodeFileHandle		= xptr->handle;

	sicico 			= xptr->sicico;
	timersem		= xptr->timersem;
	cur_seg			= xptr->cur_seg;
	procid			= xptr->procid;
	datamax			= xptr->datamax;
	datadex			= xptr->datadex;
	datapnt			= xptr->datapnt;
	StackHold		= xptr->stackhold;
	eventadr		= xptr->eventadr;

	pop_all_registers( xptr );
	return;
}

static	VOID	preemption( struct execution_thread PTR xptr )
{
	ThreadMan.cycles = 0;
	if ( xptr ) { ThreadMan.next = xptr; }
	return;
}

EXAWORD	get_thread_id()
{
	if (!( ThreadMan.count ))
		return(0);
	else if (!( ThreadMan.current ))
		return(0);
	else	return( ThreadMan.current->threadid );
}

BPTR	trace_thread()
{
	if (!( ThreadMan.count ))
		return((BPTR)0);
	else if (!( ThreadMan.current ))
		return((BPTR)0);
	else	{
		sprintf(thbuffer,"th=%u",ThreadMan.current->threadid);
		return( thbuffer );
		}
}


EXAWORD	set_thread_id(EXAWORD newid)
{
	if (!( ThreadMan.count ))
		return(0);
	else if (!( ThreadMan.current ))
		return(0);
	else	{
		ThreadMan.current->threadid = newid;
		return( 0 );
		}
}

EXAWORD	get_thread_priority()
{
	if (!( ThreadMan.count ))
		return(0);
	else if (!( ThreadMan.current ))
		return(0);
	else	return( ThreadMan.current->priority );
}

EXAWORD	set_thread_priority(EXAWORD value)
{
	if (!( ThreadMan.count ))
		return(0);
	else if (!( ThreadMan.current ))
		return(0);
	else	{
		ThreadMan.current->priority = value;
		return( 0 );
		}
}

EXAWORD	get_thread_parent()
{
	if (!( ThreadMan.count ))
		return(0);
	else if (!( ThreadMan.current ))
		return(0);
	else	return( ThreadMan.current->parentid );
}

EXAWORD	set_thread_parent(EXAWORD newid)
{
	if (!( ThreadMan.count ))
		return(0);
	else if (!( ThreadMan.current ))
		return(0);
	else	{
		ThreadMan.current->parentid = newid;
		return( 0 );
		}
}

EXAWORD	get_thread_duration()
{
	if (!( ThreadMan.count ))
		return(0);
	else if (!( ThreadMan.current ))
		return(0);
	else	return( ThreadMan.current->cycles );
}

EXAWORD	set_thread_duration(EXAWORD value)
{
	if (!( ThreadMan.count ))
		return(0);
	else if (!( ThreadMan.current ))
		return(0);
	else	{
		ThreadMan.current->cycles = value;
		return( 0 );
		}
}

EXAWORD	get_thread_count()
{
	return( ThreadMan.count );
}

EXAWORD	get_thread_event()
{
	EXAWORD	status;
	if (!( ThreadMan.count ))
		return(0);
	else if (!( ThreadMan.current ))
		return(0);
	else if (!( status = ThreadMan.current->event ))
		return(0);
	else	{
		ThreadMan.current->event = 0;
		return( status );
		}
}

EXAWORD	send_thread_event(EXAWORD target)
{
	struct execution_thread PTR xptr;
	struct execution_thread PTR pptr=(struct execution_thread PTR ) 0;
	for (	xptr=ThreadMan.first;
		xptr != (struct execution_thread PTR) 0;
		xptr = xptr->next ) {
		if ( target == -1 ) {
			xptr->event = (get_thread_id()+1);
			if ( xptr->state & _THREAD_SYNC  ) { xptr->state &= ~_THREAD_SYNC; }
			if (!( pptr )) pptr = xptr;
			}
		else if ( xptr->threadid == target ) {
			if (!( xptr->state & _THREAD_SYNC )) {
				xptr->event = (get_thread_id()+1);
				if (!( pptr )) pptr = xptr;
				}
			else if ( xptr->synchronise == -1 ) {
				xptr->event = (get_thread_id()+1);
				xptr->state &= ~_THREAD_SYNC;
				if (!( pptr )) pptr = xptr;
				}
			else if ( xptr->synchronise == get_thread_id()) {
				xptr->event = xptr->synchronise;
				xptr->state &= ~_THREAD_SYNC;
				if (!( pptr )) pptr = xptr;
				}
			break;
			}
		}
	/* ----------------------------------------------- */
	/* if at least one thread event was sent 	   */
	/* and the current thread is not a priority thread */
	/* perform pre-emption				   */
	/* ----------------------------------------------- */
	if ( pptr ) {
		if ( ThreadMan.current->priority < pptr->priority )
			preemption(pptr);
		}
	return(0);
}

VOID	reset_thread_manager()
{
	ThreadMan.first   = 
	ThreadMan.last    = 
	ThreadMan.current = (struct execution_thread PTR) 0;
	ThreadMan.count	  =0;
	ThreadMan.number  =0;
	ThreadMan.cycles  =0;
	return;
}

EXAWORD		thread_not_unique(EXAWORD id)
{
	struct execution_thread PTR xptr;
	for (	xptr = ThreadMan.first;
		xptr != (struct execution_thread PTR) 0;
		xptr = xptr->next )
		if ( xptr->threadid == id )
			return(1);
	return(0);
}
 
EXAWORD		create_thread()
{
	EXAWORD	threadid=0;
	struct execution_thread PTR xptr;
	if (!( ThreadMan.first )) {
		if (!( ThreadMan.first = allocate_thread(0) )) {
			err_val = 27;
			return( SOFTERROR );
			}
		else	{
			save_thread( ThreadMan.first );
			ThreadMan.last = ThreadMan.current = ThreadMan.first;
			ThreadMan.cycles = ThreadMan.current->cycles;
			}
		}

	/* allocate a unique thread id : handle wrap around avoiding zero */
	/* -------------------------------------------------------------- */
	while ((!( threadid = ++ThreadMan.number )) || ( thread_not_unique(threadid) ));

	if (!( xptr = allocate_thread(1) )) {
		err_val = 27;
		return( SOFTERROR );
		}
	else	{
		xptr->previous = ThreadMan.last;
		xptr->threadid = threadid;
		ThreadMan.count++;
		xptr->parentid = get_thread_id();
		ThreadMan.last->next = xptr;
		ThreadMan.last = xptr;
		save_thread( xptr );
		if ( get_thread_priority() < xptr->priority )
			preemption(xptr);
		return( GOODRESULT );
		}
}

EXAWORD	synchronise_thread(EXAWORD target)
{
	struct execution_thread PTR xptr;
	if (!(xptr = ThreadMan.current ))
		return( GOODRESULT );
	else	{
		xptr->synchronise= target;
		xptr->state      |= _THREAD_SYNC;
		ThreadMan.cycles = 0;
		return( GOODRESULT );
		}
}

EXAWORD	abqt_thread(EXAWORD target)
{
	struct execution_thread PTR xptr;
	if (!(xptr = ThreadMan.current ))
		return( GOODRESULT );
	else	{
		ThreadMan.cycles = 0;
		return( GOODRESULT );
		}
}

EXAWORD	remove_thread(EXAWORD target)
{
	struct execution_thread PTR xptr;

	if (!( ThreadMan.current ))
		return( GOODRESULT );
	for (	xptr=ThreadMan.first;
		xptr != (struct execution_thread PTR) 0;
		xptr = xptr->next ) {
		if ( xptr->threadid == target ) {
			if ( xptr->threadid == ThreadMan.current->threadid ) {
				choose_thread();
				if ( xptr->threadid == ThreadMan.current->threadid )
					ThreadMan.current = (struct execution_thread PTR) 0;
				}
			if (!( xptr->previous ))
				ThreadMan.first = xptr->next;
			else	xptr->previous->next = xptr->next;
			if (!( xptr->next ))	
				ThreadMan.last = xptr->previous;
			else	xptr->next->previous = xptr->previous;
			xptr = liberate_thread(xptr);		
			ThreadMan.count--;
			if (!( ThreadMan.current )) {
				err_val = 0;
				return( SOFTERROR );
				}
			else	break;
			}
		}
	return(GOODRESULT);
}

VOID	liberate_thread_manager()
{
	EXAWORD	current;
	struct execution_thread PTR xptr;
	if (!( ThreadMan.current ))
		return;
	else	current = ThreadMan.current->threadid;
	while ((xptr = ThreadMan.first) != (struct execution_thread PTR) 0) {
		ThreadMan.first = xptr->next;
		if ( xptr->threadid != current )
			xptr = liberate_thread(xptr);		
		else	liberate( xptr );
		}
	reset_thread_manager();
}

VOID	choose_thread()
{
	int	status=0;
	struct execution_thread PTR xptr;
	if ((xptr = ThreadMan.next) != (struct execution_thread PTR) 0) {
		ThreadMan.next = (struct execution_thread PTR) 0;
		ThreadMan.current = xptr;
		return;
		}
	if (!( xptr = ThreadMan.current ))
		return;
	while (1) {
		if (!( xptr = xptr->next )) {
			if ( status )
				return;
			else	xptr = ThreadMan.first;
			}
		if (!( xptr->state & _THREAD_SYNC )) {
			ThreadMan.current = xptr;
			return;
			}
		}
}

EXAWORD	change_thread()
{
	if (!( ThreadMan.count ))
		return(0);
	else	{
		if ( fdex > TcodeSegment )
			fdex--;
		save_thread( ThreadMan.current );
		choose_thread();
		restore_thread( ThreadMan.current );
		if ( ThreadMan.current->event )
			ThreadMan.current->event = std_thread_event(ThreadMan.current->event);
		ThreadMan.cycles=ThreadMan.current->cycles;
		return(1);
		}
	return;
}

/*	---------------------------------	*/
/*		T c o d e S p a w n		*/
/*	---------------------------------	*/
/*	Entry point for ESC SPAWN tcode		*/
/*	---------------------------------	*/
EXAWORD	TcodeSpawn()
{
	return( create_thread() );
}

/*	---------------------------------	*/
/*		S p a w n E x i t  		*/
/*	---------------------------------	*/
/*	Entry point for ESC EXIT  tcode		*/
/*	---------------------------------	*/
EXAWORD	SpawnExit()
{
	return(remove_thread( get_thread_id() ));
}


#endif	/* _extask_c */
	/* --------- */



