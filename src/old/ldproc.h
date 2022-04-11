#ifndef	_ldproc_h
#define	_ldproc_h

PROCEDURE	{	
	PROCEDURE *	next;
	PROCEDURE *	prev;
	BPTR		name;
	EXAWORD		identity;
	LOCATION	tcode;
	LOCATION	stats;
	LOCATION	lvt;
	LOCATION	lct;
	EXAWORD		options;
	LOCATION	crossref;
	EXAWORD		linkown;
	REFERENCE *	linkage;
	LOCATION	correspondance;
	BYTE		returntype;
	BYTE		parameters;
	BPTR		signature;
	MODULE	*	host;
	MODULE	*	original;
	};


XPROCEDURE	{	
	XPROCEDURE *	next;
	XPROCEDURE *	prev;
	BPTR		name;
	BPTR		modname;
	EXAWORD		module;
	EXAWORD		state;
	RELOCATION *	relocate;
	BYTE		returntype;
	BYTE		parameters;
	BPTR		signature;
	MODULE	*	client;		/* module requiring solution 	*/
	MODULE	*	host;		/* module providing solution 	*/
	PROCEDURE *	procedure;	/* the solution procedure	*/
	};


#endif	/* _ldproc_h */

