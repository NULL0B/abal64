#ifndef	_TRCLFTOC_H
#define	_TRCLFTOC_H

#define	CLFTOCPTR	struct clftoc_context XPTR

struct	clftoc_context	{
	TNODEPTR	first;
	TNODEPTR	last;
	WORD		type;
	WORD		group;
	WORD		parameters;
	};

#endif	/* _TRCLFTOC_H */
	/* ----------- */

