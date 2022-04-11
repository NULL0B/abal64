#ifndef	_tcdlf_h
#define	_tcdlf_h

/*		-------------------------------------------		*/
/*		T C O D E _ L I B R A R Y _ F U N C T I O N		*/
/*		-------------------------------------------		*/

struct	tcode_library_function {
					/* ---------------------------- */
	WORD		identity;	/* Library Function Number	*/
	BPTR		name;		/* Name of function		*/
	TCDLBPTR	library;	/* Pointer to library Node	*/
	WORD		type;		/* Return type of function	*/
	WORD		usage;		/* Usage of Function Counter	*/
	TCVARPTR	parameter;	/* List of parameters expected	*/
	TCDLFPTR	next;		/* Next function in list	*/
					/* ---------------------------- */
	};


#endif	/* _tcdlf_h */

