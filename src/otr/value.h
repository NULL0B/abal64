#ifndef	_VALUE_H
#define	_VALUE_H


#ifdef	SWAP_CTRL
#define VALUEPTR  BUFFERHANDLE
#define	VALUEBUF  struct macro_value XPTR
#else
#define VALUEPTR  struct macro_value XPTR 
#endif

struct macro_value {
	WORD		irite;		/* Write Offset			*/
	WORD		iread;		/* Read  Offset			*/
	VALUEPTR	next;		/* Pointer to next line		*/
	BYTE		text[TEXT_MAX];	/* Line of macro information	*/
	};

#endif	/* _VALUE_H */
	/* -------- */

