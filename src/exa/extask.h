#ifndef	_extask_h
#define	_extask_h

struct	execution_thread	{

	struct	execution_thread PTR	previous;
	struct	execution_thread PTR	next;

	EXAWORD		dx[WORKSIZE];		/* Registre de data		*/
	EXAWORD		fx[WORKSIZE];		/* Registre de status		*/
	EXAWORD		ix[WORKSIZE];		/* Registre d'index		*/
	EXAWORD		ax[WORKSIZE];		/* Registre d'index		*/

	VPTR		bs;			/* Byte Stack			*/
	VPTR		ws;			/* Word Stack			*/
	VPTR		ps;			/* Pointer Stack		*/
	VPTR		pps;			/* Push Pop Stack		*/
	VPTR		gpt;			/* Procedure Table		*/
	VPTR		ctx;			/* Global Context		*/

	EX_FILE_HANDLE 	handle;

	EXAWORD		wordsize;		/* Tcode word size of thread	*/
	EXAWORD		threadid;		/* identity of this thread	*/
	EXAWORD		parentid;		/* Threadid of parent		*/
	EXAWORD		event;			/* Event received from thread	*/
	
	EXAWORD		ip_next;
	EXAWORD		mindex; 
	EXAWORD		worktop; 
	EXAWORD		workhold;
	EXAWORD		pushtop;
	EXAWORD		pushhold;
	EXAWORD		sicico;
	EXAWORD		timersem;
	EXAWORD		eventadr;
	EXAWORD		stackhold;

	EXAWORD		cur_seg;
	EXAWORD		procid;
	EXAWORD		datamax;
	EXAWORD		datapnt;
	EXAWORD		datadex;

	EXAWORD		libraries;
	BPTR		glt;			/* global library table		*/
	BPTR		gct;			/* global constant table	*/
	BPTR		lct;			/* local constant table		*/
	BPTR		gds;			/* global sata segment		*/
	BPTR		gdt;			/* global data table		*/
	BPTR		lds;			/* local data segment		*/
	BPTR		ldt;			/* local data table		*/
	BPTR		cs;			/* code segment base 		*/
	BPTR		csip;			/* code segment instruction 	*/

	EXAWORD		flags;			/* execution control flags	*/

	EXAWORD		cycles;			/* instruction count / duration	*/
	EXAWORD		priority;		/* thread selection priority	*/
	EXAWORD		state;			/* current thread state		*/
	EXAWORD		synchronise;		/* task id on which to wait	*/
	};

#define	_THREAD_SYNC	1		/* thread state value for synchornisation */

struct	execution_thread PTR allocate_thread(EXAWORD mode);
struct	execution_thread PTR liberate_thread(struct execution_thread PTR xptr);
EXAWORD	task_stack_allocation( struct execution_thread PTR xptr, EXAWORD mode );
VOID	save_thread( struct execution_thread PTR xptr );
VOID	restore_thread( struct execution_thread PTR xptr );
VOID	reset_thread_manager();
VOID	choose_thread();
EXAWORD	change_thread();

struct	thread_manager	{
	EXAWORD				number;
	EXAWORD				count;
	EXAWORD				cycles;
	struct	execution_thread PTR	first;
	struct	execution_thread PTR	last;
	struct	execution_thread PTR	current;
	struct	execution_thread PTR	next;
	} ThreadMan =  {
		0,0,0,
		(struct	execution_thread PTR) 0,
		(struct	execution_thread PTR) 0,
		(struct	execution_thread PTR) 0,
		(struct	execution_thread PTR) 0,
		(struct	execution_thread PTR) 0
		};

EXTERN	struct fusework PTR 	FuseBase;
EXTERN	EXAWORD			FuseCount;
extern	struct procform PTR	TcodeProcTable;
extern	OVLOBJPTR		TcodeContext;

#endif	/* _extask_h */
	/* --------- */

