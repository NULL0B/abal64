#ifndef	_ldsegm_h
#define	_ldsegm_h

SEGMENT	{	
	SEGMENT *	next;
	SEGMENT *	prev;
	BPTR		name;
	EXAWORD		identity;
	EXAWORD		offset;
	EXAWORD		options;
	LOCATION	tcode;
	LOCATION	stats;
	LOCATION	lvt;
	LOCATION	lct;
	LOCATION	crossref;
	EXAWORD		linkown;
	REFERENCE *	linkage;
	LOCATION	correspondance;
	MODULE	*	original;
	MODULE	*	host;
	};

XSEGMENT	{	
	XSEGMENT *	next;
	XSEGMENT *	prev;
	BPTR		name;
	BPTR		modname;
	EXAWORD		module;
	EXAWORD		number;
	EXAWORD		state;
	RELOCATION *	relocate;
	MODULE	*	client;		/* module requiring solution 	*/
	MODULE	*	host;		/* module providing solution 	*/
	SEGMENT *	segment;	/* the solution procedure	*/

	};


#endif	/* _ldsegm_h */


