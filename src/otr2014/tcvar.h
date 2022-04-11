#ifndef	_tcvar_h
#define	_tcvar_h

/*		      ---------------------------			*/
/*		      T	C O D E _ V A R I A B L E			*/
/*		      ---------------------------			*/

struct	tcode_variable {
					/* ---------------------------- */
	WORD		descriptor;	/* Final Real Descriptor	*/
	WORD		identity;	/* Initial descriptor		*/
	WORD		nature;		/* Internal External		*/
	BPTR		name;		/* variable name		*/
	WORD		hash;		/* Variable Hash identity	*/
	HUGE		offset;		/* offset in DS of storage	*/
	WORD		host;		/* Host variable for PTR redef	*/
	WORD		master;		/* Master Structure Variable	*/
	WORD		usage;		/* variable descriptor size	*/
	WORD		body;		/* DCL/PROC/SEGM/USER/CODE 	*/
	WORD		access;		/* 1 : Writable, 0 Const	*/
	VPTR		firstdim;	/* First dimension value	*/
	VPTR		secondim;	/* Second dimension value	*/
	VPTR		class;		/* Class of structured variable */
	TCTEXTPTR	construction;	/* Construction parameters	*/
	RELOCPTR	relocation;	/* Rellocation information	*/
	TCVDTPTR	vdt;		/* Pointer to parent table 	*/
	TCTYPPTR	type;		/* Pointer to type context	*/
	TCVARPTR	parent;		/* Pointer to original entry	*/
	TCVARPTR	overloads;	/* Pointer to original entry	*/
	TCVARPTR	link;		/* Optimised variable list next	*/
	TCVARPTR	next;		/* Next original variable	*/
	TCVARPTR	prev;		/* Previous original variable	*/
	WORD		module;		/* indicates module for extern	*/
					/* ---------------------------- */
	};

#endif	/* _tcvar_h */

