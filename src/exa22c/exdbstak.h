#ifndef	_EXDBSTAK_H
#define	_EXDBSTAK_H

#define	STACKPTR struct stack_analysis SPTR

struct	stack_analysis {
	EXAWORD		type;
	EXAWORD		identity;
	EXAWORD		offset;
	STACKPTR	next;
	STACKPTR	previous;
	};
	
#ifdef	_EXDBSTAK_C

static	EXAWORD		MaxStack;
static	STACKPTR	TopStack;
static	STACKPTR	EndStack;
static	EXAWORD		CurrentType;
static	EXAWORD		CurrentBlock;

#define	trace_segment(i,o) if (allocate_for_stack(0,i,o) == 0) return;
#define	trace_procedure(i,o) if (allocate_for_stack(1,i,o) == 0) return;

EXTERN	EXABYTE	trad_ver;		/* AT Traductor Version Flag	*/
EXTERN	EXAWORD	StackHold;		/* Gosub Stack protection	*/

#endif	

VOID	trace_stack();

#endif	/* _EXDBSTAK_H */
	/* ----------- */

