#ifndef	_ldvarb_h
#define	_ldvarb_h

VARIABLE	
{
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

FIELD		
{
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

#define	ABAL_INT8	0
#define	ABAL_INT16	1
#define	ABAL_BCD	2
#define	ABAL_STRING	3
#define	ABAL_INT32	5
#define	ABAL_INT64	6
#define	VARBTYPE	7

#endif	/* _ldvarb_h */

