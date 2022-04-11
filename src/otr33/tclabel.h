#ifndef	_tclabel_h
#define	_tclabel_h

/*		-------------------------------				*/
/*		T C O D E _ D A T A _ L A B E L				*/
/*		-------------------------------				*/

#define	TCLABEL	struct tcode_data_label
#define	TCLABELPTR TCLABEL XPTR

struct	tcode_data_label {
	WORD		value;		/* offset into data space	*/
	BPTR		name;		/* Label name			*/
	WORD		field;		/* Field M or E of data space	*/
	TCLABELPTR	prev;		/* Previous item		*/
	TCLABELPTR	next;		/* Next Item			*/
	};

#endif	/* _tclabel_h */


