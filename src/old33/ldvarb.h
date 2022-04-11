#ifndef	_ldvarb_h
#define	_ldvarb_h

VARIABLE	{
	VARIABLE *	next;
	VARIABLE *	prev;
	BPTR		name;
	EXAWORD		copy;
	EXAWORD		identity;
	EXAWORD		type;
	EXAWORD		length;
	EXAWORD		first;
	EXAWORD		second;
	EXAWORD		offset;
	RELOCATION *	relocate;
	MODULE	*	host;
	};

FIELD		{
	FIELD	*	next;
	FIELD	*	prev;
	EXAWORD		module;
	BPTR		modname;
	BPTR		name;
	BYTE		nature;	/* 0x0010 entry is present */
	EXAWORD		state;
	EXAWORD		entry;	/* specific item */
	EXAWORD		loword;
	EXAWORD		hiword;
	LOCATION	xvt;
	ItemList( VARIABLE, members );
	MODULE	 *	client;
	MODULE	 *	host;
	ItemList( SOLUTION, solution );

	};


#endif	/* _ldvarb_h */

