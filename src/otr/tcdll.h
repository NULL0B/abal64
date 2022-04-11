#ifndef	_tcdll_h
#define	_tcdll_h

/*		-------------------------				*/
/*		T C O D E _ L I B R A R Y				*/
/*		-------------------------				*/

struct	tcode_library {
	WORD		version;
	BPTR		title;
	BPTR		name;
	WORD		identity;
	WORD		alias;
	WORD		access;
	WORD		usage;		/* Usage of Library Flag	*/
	WORD		functions;	/* number of functions		*/
	WORD		options;	/* Library Options : PRELOAD (03/01/2006) */
	RELOCPTR	relocation;	/* List of Global Rellocation	*/
	TCDLFPTR	function;
	TCDLBPTR	prev;
	TCDLBPTR	next;
	};

#endif	/* _tcdll_h */


