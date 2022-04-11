#ifndef	_TRACE_H
#define	_TRACE_H

#ifdef	_TRACE_C
PUBLIC	INT	TraceHandle=0;
PUBLIC	INT	trace_active=0;
PUBLIC	BPTR  	TraceName=(BPTR) 0;
#else
EXTERN	INT	TraceHandle;
EXTERN	INT	trace_active;
EXTERN	BPTR  	TraceName;
#endif

PUBLIC	VOID	activate_trace( BPTR );
PUBLIC	VOID	trace_puts( BPTR );
PUBLIC	VOID	trace_putw( INT  );
PUBLIC	VOID	trace_putl( LONG );
PUBLIC	VOID	trace_line( VOID );
PUBLIC	VOID	terminate_trace( VOID );

#endif  /* TRACE_H */
	/* ------- */
