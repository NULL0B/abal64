#ifndef	_TRDEFINE_H
#define _TRDEFINE_H

#define	DEFINEPTR	struct otr_definition XPTR
#define	STATEPTR	struct otr_state XPTR

struct	otr_definition	{
	BPTR		name;
	WORD		hash;
	WORD		scope;
	BPTR		value;
	DEFINEPTR	next;
	DEFINEPTR	prev;
	};

struct	otr_state	{
	WORD		filenumber;
	LONG		fileline;
	BPTR		token;
	WORD		state;
	WORD		number;
	STATEPTR	next;
	};

#endif	/* _TRDEFINE_H */
	/* ----------- */

