#ifndef	_tcproc_h
#define	_tcproc_h

/*		-----------------------------				*/
/*		T C O D E _ P R O C E D U R E				*/
/*		-----------------------------				*/

struct	tcode_procedure {
	WORD		identity;
	BPTR		name;
	WORD		hash;
	WORD		mode;		/* Explicite or Implicite */
	WORD		options;
	WORD		function;
	WORD		status;
	WORD		module;
	XREFPTR		crossref;
	WORD		sector_XRF;
	RELOCPTR	relocation;
	VPTR		class;
	VPTR		member;
	TCTYPPTR	result;
	TCVARPTR	parameter;
	TCBLKPTR	details;
	struct tcode_correspondance symbolic;
	TCPRCPTR	next;
	TCVARPTR	extcall;
	WORD		extitem;
	};

#endif	/* _tcproc_h */

