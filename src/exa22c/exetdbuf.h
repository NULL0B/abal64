/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1992 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	BUFFERS.H				*/
/*		Version :	1.1a					*/
/*		Date	:	13/10/1992				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_BUFFERS_H
#define _BUFFERS_H

#define	BUFFERHANDLE	struct user_buffer_handle SPTR
#define BCNODEPTR	struct buffer_control_node SPTR
#define	SWAPPED_IN	-1L
#define SWAPPED_OUT	0x0001
#define	BUFFER_LOCK	0x0002
#define	_AUTO_SWAP_OUT	0x0001

/*
 *	User buffer handle structure (UBH) allocated to provide
 *	user access to a buffer control node text area.
 */
struct	user_buffer_handle	{
	long		swapnode;	/* Offset in swap file of text 	*/
	BCNODEPTR	bcnode;		/* Pointer to atributed BCN	*/
	};

/*
 *	Buffer Control Node (BCN) structure, allocated to provide
 *	a control node for the management of a user requested text
 *	buffer.
 */	
 
struct	buffer_control_node	{

	BUFFERHANDLE	user;	 	/* Pointer to atributed UBH	 */
	BCNODEPTR	next;		/* Pointer to Next BCN in queue	 */
	BCNODEPTR	previous;	/* Pointer to previous queue BCN */
	EXABYTE		text[1];	/* User text area matrix	 */
	};

#ifdef	_BUFFERS_C

/*
 *	Buffer Control Table (BCT) structure which maintains the current
 *	status of the buffer control systeme.
 */

struct	buffer_control_table	{
	BCNODEPTR	oldest;		/* Least recently atributed BCN	*/
	BCNODEPTR	newest;		/* Most recently atributed BCN	*/
#ifndef	SLOW_SPEED
	BUFFERHANDLE	HandleHeap;	/* Pre-allocation handle list	*/
#endif
	BPTR		swapname;	/* Name of Swap file		*/
	long		swapnode;	/* Next free swap node offset	*/
	int		swaphandle;	/* Swap file handle		*/
	int		maxswapnode;	/* Swap file size in nodes	*/
	EXAWORD		handles;	/* current count of active UBHs	*/
	EXAWORD		maxhandles;	/* greatest number of UBHs	*/
	EXAWORD		usage;		/* Count of current active BCNs	*/
	EXAWORD		textsize;	/* User text area size		*/
	EXAWORD		limit;		/* Maximum number of BCNs	*/
	EXAWORD		lowlimit;	/* Minimum number of BCNs	*/
	EXAWORD		options;	/* Option control word		*/
	} BufferControl;	

#endif	/* _BUFFERS_C */
	/* ---------- */


#ifdef	CHECK_PROTO_ARGS

EXAWORD		initialise_buffer_control( BPTR, EXAWORD , EXAWORD, EXAWORD );
void		liberate_buffer_controller( void );
BUFFERHANDLE	allocate_buffer( void );
void		release_buffer( BUFFERHANDLE );
VPTR		revalidate_buffer( BUFFERHANDLE );

#else

EXAWORD		initialise_buffer_control(); 	/* BPTR, EXAWORD , EXAWORD 	*/
void		liberate_buffer_controller();	/* void 		*/
BUFFERHANDLE	allocate_buffer();		/* void 		*/
void		release_buffer();		/* BUFFERHANDLE 	*/
VPTR		revalidate_buffer();		/* BUFFERHANDLE 	*/

#endif	/* CHECK_PROTO_ARGS */
	/* ---------------- */

#define	validate_buffer( ubh ) ( ubh->swapnode == SWAPPED_IN ? ubh->bcnode->text : revalidate_buffer( ubh ) )

#endif	/* _BUFFERS_H */
	/* ---------- */
	
