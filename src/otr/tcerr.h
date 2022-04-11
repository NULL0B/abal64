#ifndef	_tcerrtrp_h
#define _tcerrtrp_h

#define	TCERRPTR struct tcode_error_trap *

struct	tcode_error_trap
{
	TCVARPTR	variable;
	WORD		label;
};

#endif	/* _tcerrtrp_h */
