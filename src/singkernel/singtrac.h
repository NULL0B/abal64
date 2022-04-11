#ifndef	_singtrace_h
#define	_singtrace_h

#define	__TRACE_FIRST		'TF'
#define	__TRACE_PREVIOUS	0x0016	/* Ctrl V */
#define	__TRACE_WIDGET		0x001A	/* Ctrl Z */
#define	__TRACE_METHOD		0x000D	/* Ctrl M */
#define	__TRACE_NEXT		0x0014	/* Ctrl T */
#define	__TRACE_LAST		'TL'

struct	abal_trace	{
	int	type;
	char *	filename;
	int	fileline;
	int	column;
	char *	message;
	char *	expression;
	struct 	form_item * member;
	struct	abal_trace * previous;
	struct	abal_trace * next;
	};

#endif 	/* _singtrace_h */


