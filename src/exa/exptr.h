/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1997 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXPTR.H   				*/
/*		Version :	2.1a					*/
/*		Date 	:	20/05/1997				*/
/*									*/
/*----------------------------------------------------------------------*/

/* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 * 14/05/97 : correction bug Wexa 32bits - retire le test de la validite
 *             du pointeur dans macro resolve_pointer_member pour compatibilité
 *             avec wexa 16 bits (A.M.)
 * 20/05/97 : Ajout du champs ValidityFlag dans la structure dynamic_control
 *            pour verifier la validite du pointeur alloue (A.M.)
 *
 */

#ifndef	_EXPTR_H
#define	_EXPTR_H

/*	--------------------------------------------		*/
/*	Prototypes for POINTER get and put functions		*/
/*	--------------------------------------------		*/
#ifndef	UNIX
#ifndef VMS
#define	TcodeGetPointer( gadr )       ( *gadr ? *((BPTR PTR) (gadr + 1)) : (BPTR) 0 ) 
#define	TcodePutPointer( padr, ptr )  *((BPTR PTR) (padr + 1)) = ptr
#endif
#endif
#ifndef	DOS
#ifndef PROLOGUE
extern	BPTR	TcodeGetPointer();
extern	void	TcodePutPointer();
#endif
#endif

/*	Dynamic Allocation control structure	*/
/*	------------------------------------	*/

#define	DYNOPTR	struct dynamic_control PTR
#define	PREFIX_SIZE	( sizeof( struct dynamic_control ) - 1 )

#define MAGICWORD 0x6666

struct	dynamic_control	{
	DYNOPTR	next;			/* Pointer to next element			*/
	DYNOPTR	previous;		/* Pointer to previous element			*/
	EXAWORD	ValidityFlag;		/* Flag de validite de la structure		*/
	EXAWORD	usage;			/* Usage counter for this zone			*/
#ifdef	ABAL64
	EXAWORD	value;			/* The Logical value of the pointer		*/
#endif
	EXABYTE	text[1];		/* Text of allocated object			*/
	};

/*	--------------------		*/
/*	Constant Definitions		*/
/*	--------------------		*/
#define	ABALPTRSIZE			(sizeof(BPTR) + sizeof(EXABYTE))
#define	REFERENCED_POINTER		0x0001
#define	ALLOCATED_POINTER		0x0003
#define	CONSTANT_POINTER		0
#define PROCEDURE_POINTER		0x0005
#define SEGMENT_POINTER			0x0009
#define USER_POINTER			0x0011
#define PROGRAM_POINTER			0x0085		/* PROC PTR with natural pointer value 	*/
#ifdef	ABAL64
#define	PROGRAM_OFFSET			0x0020		/* PROC PTR with offset pointer value	*/
#define OFFSET_POINTER			PROGRAM_POINTER | PROGRAM_OFFSET
#endif

#ifdef	ABAL_REMOTE
#define REMOTE_POINTER			0x00C5
#endif
#ifdef	ABAL64
#define INDEXED_ALIAS			0
#endif

/*	---------------------------	*/
/*	Pointer manipulation macros	*/
/*	---------------------------	*/

#define	raz_pointer_variable( a ) 	memset( a , 0, PTRSIZE )

#define	ensure_valid_ptr( ptr_to_test ) { \
	if ( ptr_to_test == (BPTR) 0 ) { \
		err_val = 118; \
		return( SOFTERROR ); \
		} \
	}

#ifndef WIN32

#define	resolve_pointer_member( descriptor, memoire, vtype ) { \
	if ( vtype & ISMEMBER ) { \
		memoire = resolve_member((Tcodeword((descriptor)))); \
		ensure_valid_ptr( memoire ); \
		if ( vtype & ISPOINTER ) \
			memoire  = TcodeGetPointer(( memoire + (Tcodeword((descriptor + WORDSIZE))))); \
		else	memoire += Tcodeword((descriptor + WORDSIZE)); \
		ensure_valid_ptr( memoire ); \
		descriptor += (2 * WORDSIZE); \
		} \
	else	{ \
		memoire    = resolve_pointer( descriptor, memoire, vtype, reg ); \
		ensure_valid_ptr( memoire ); \
		descriptor += WORDSIZE; \
		} \
	}

#else

#define	resolve_pointer_member( descriptor, memoire, vtype ) { \
	if ( vtype & ISMEMBER ) { \
		memoire = resolve_member((Tcodeword((descriptor)))); \
		ensure_valid_ptr( memoire ); \
		if ( vtype & ISPOINTER ) \
			memoire  = TcodeGetPointer(( memoire + (Tcodeword((descriptor + WORDSIZE))))); \
		else	memoire += Tcodeword((descriptor + WORDSIZE)); \
		ensure_valid_ptr( memoire ); \
		descriptor += (2 * WORDSIZE); \
		} \
	else	{ \
		memoire    = resolve_pointer( descriptor, memoire, vtype, reg ); \
		descriptor += WORDSIZE; \
		} \
	}

#endif
	/* -------- */
#endif	/* _EXPTR_H */
	/* -------- */
