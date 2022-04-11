#ifndef	_TRTNODE_C
#define	_TRTNODE_C

#include "trtnode.h"

VOID	release_tnode( tptr )
TNODEPTR	tptr;
{
	if ( tptr->value != (BPTR) 0 ) {
		liberate( tptr->value );
		tptr->value = (BPTR) 0;
		}
	tptr->next = TnodeFree;
	TnodeFree  = tptr;
	return;
}

VOID	release_used_tnodes()
{
	TNODEPTR	tptr;

	while ((tptr = TnodeUsed) != (TNODEPTR) 0) {
		TnodeUsed = tptr->next;
		release_tnode( tptr );
		}
	return;
}

VOID	liberate_tnodes()
{
	TNODEPTR	tptr;

	release_used_tnodes();

	while ((tptr = TnodeFree) != (TNODEPTR) 0) {
		TnodeFree = tptr->next;
		liberate( tptr );
		}
	return;
}

VOID	initialise_tnodes()
{
	TnodeFree = (TNODEPTR) 0;
	TnodeUsed = (TNODEPTR) 0;
	return;
}

TNODEPTR	allocate_tnode( taille )
WORD		taille;
{
	TNODEPTR	tptr;
	trace("allocate_tnode()\n");
	if ((tptr = TnodeFree) != (TNODEPTR) 0)
		TnodeFree = tptr->next;
	else if ((tptr = (TNODEPTR) allocate( sizeof( struct temporary_allocation_node ) )) == (TNODEPTR) 0) {
		(void) allocation_failure();
		return( (TNODEPTR) 0 );
		}
	tptr->value = (BPTR) 0;
	tptr->state = 0;
	tptr->next  = (TNODEPTR) 0;
	tptr->prev  = (TNODEPTR) 0;
	if ((tptr->value = (BPTR) allocate( (taille+64+16) )) == (BPTR) 0) {
		release_tnode( tptr );
		(void) allocation_failure();
		return( (TNODEPTR) 0 );
		}
	return( tptr );
}

BPTR	allocate_for_tnode( taille )
WORD	taille;
{
	TNODEPTR	tptr;
	trace("allocate_for_tnode()\n");
	if ((tptr = allocate_tnode( taille )) == (TNODEPTR) 0 )
		return((BPTR) 0);

	tptr->next = TnodeUsed;
	TnodeUsed  = tptr;
	return( tptr->value );
}

#endif	/* _TRTNODE_C */
	/* ---------- */


