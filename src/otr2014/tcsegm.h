#ifndef	_tcsegm_h
#define	_tcsegm_h

/*		-------------------------				*/
/*		T C O D E _ S E G M E N T				*/
/*		-------------------------				*/

struct	tcode_segment {
	WORD		identity;
	BPTR		name;
	WORD		mode;		/* Explicite or Implicite */
	WORD		offset;
	WORD		options;
	WORD		prototype;	/* forward referenced	*/
	XREFPTR		crossref;
	WORD		sector_XRF;
	TCBLKPTR	details;
	struct tcode_correspondance symbolic;
	TCSEGPTR	next;
	};

#endif	/* _tcsegm_h */

