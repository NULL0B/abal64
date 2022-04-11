#ifndef	_TRTNODE_H
#define	_TRTNODE_H

#define	TNODEPTR	struct temporary_allocation_node XPTR

struct	temporary_allocation_node {
	BPTR		value;
	WORD		state;
	TNODEPTR	next;
	TNODEPTR	prev;
	};

#ifdef	_TRTNODE_C
TNODEPTR		TnodeUsed=(TNODEPTR) 0;
TNODEPTR		TnodeFree=(TNODEPTR) 0;
#endif

#ifdef	UNIX
BPTR  		allocate_for_tnode();
TNODEPTR	allocate_tnode();
#else
BPTR    	allocate_for_tnode( WORD );
TNODEPTR	allocate_tnode( WORD );
#endif


#endif	/* _TRTNODE_H */
	/* ---------- */










