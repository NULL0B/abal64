#ifndef	_VALUE_H
#define	_VALUE_H


#ifdef	SWAP_CTRL
#define VALUEPTR  BUFFERHANDLE
#define	VALUEBUF  struct macro_value XPTR
#else
#define VALUEPTR  struct macro_value XPTR 
#endif

struct macro_value {
	EXAWORD		irite;		/* Write Offset			*/
	EXAWORD		iread;		/* Read  Offset			*/
	VALUEPTR	next;		/* Pointer to next line		*/
	EXABYTE		text[TEXT_MAX];	/* Line of macro information	*/
	};

#endif	/* _VALUE_H */
	/* -------- */

