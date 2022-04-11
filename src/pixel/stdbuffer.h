#ifndef	_stdbuffer_h
#define	_stdbuffer_h

/*	------------------------------------------------------	*/
/*	This file describes a simple buffer handling structure 	*/
/*	for use in special cases where output buffering needs	*/
/*	to be detected and saved, eg error tracing.		*/
/*	------------------------------------------------------	*/

struct	standard_buffer	{
	int	columns;
	int	rows;
	void *	storage;
	};

#endif	/* _stdbuffer_h */
	/* ------------ */

