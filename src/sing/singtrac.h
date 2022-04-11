#ifndef	_singtrace_h
#define	_singtrace_h

#define	__TRACE_FIRST		0x081C	/* Alt Home 	*/
#define	__TRACE_PREVIOUS	0x0812	/* Alt Page Up	*/
#define	__TRACE_WIDGET		0x085A	/* Alt Zoom	*/
#define	__TRACE_METHOD		0x080D	/* Alt Enter	*/
#define	__TRACE_NEXT		0x0803	/* Alt PageDown */
#define	__TRACE_LAST		0x0802	/* Alt End 	*/
		
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


