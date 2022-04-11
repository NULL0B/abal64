/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRLABELS.H				*/
/*		Version :	2.1d					*/
/*		Date	:	08/12/1994				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRLABELS_H
#define	_TRLABELS_H

#define	LABELPTR	struct otr_label XPTR

struct	otr_label	{
	BPTR		name;
	WORD		hash;
	WORD		number;
	WORD		user;
	WORD		adresse;
	LABELPTR	next;
	};

#ifdef	_TRLABELS_C
LABELPTR	LabelHeap=(LABELPTR) 0;
LABELPTR	FreeLabels=(LABELPTR) 0;
#endif

/*	Function Prototypes	*/
/*	-------------------	*/

#ifndef	UNIX
WORD	tcode_labels( VOID );
VOID	liberate_label( LABELPTR );
LABELPTR	allocate_for_label( BPTR );
WORD	release_labels( VOID );
LABELPTR	is_label( BPTR );
WORD	use_explicite_label( BPTR, WORD );
WORD	show_use_explicite_label( BPTR, WORD );
WORD	add_explicite_label( BPTR );
VOID	terminate_labels( VOID );
VOID	initialise_labels( VOID );
#else
VOID	initialise_labels();
VOID	terminate_labels();
WORD	use_explicite_label();
WORD	add_explicite_label();
#endif

#endif	/* _TRLABELS_H */
	/* ----------- */
