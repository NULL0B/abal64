/* -------------------------------------------------------------------- */
/*									*/
/*		Project ABAL : Tcode Post optimiser			*/
/*		-----------------------------------			*/
/*									*/
/*		  Copyright (c) 1989,1991 Amenesik / Sologic s.a.			*/
/*		  --------------------------------			*/
/*									*/
/*		File	:	LABEL.H   				*/
/*		Version :	1.4a					*/
/*		Date	:	06/10/1991				*/
/*									*/
/* -------------------------------------------------------------------- */
#ifndef	_LABEL_H
#define	_LABEL_H

#define	LABEL      struct etiquette XPTR
#define BACKPATCH  struct forwardref XPTR
#define ALIASSE	   struct aliasse XPTR

struct	aliasse {
	EXAWORD	old_offs;
	EXAWORD	new_offs;
	ALIASSE suite;
	};


extern	BPTR tcGKT;	/* Global constant table pointer		*/
extern	EXAWORD tcGKL;	/* Global constant table length			*/

struct  etiquette {
	EXAWORD		source;
	EXAWORD		target;
	LABEL		suite;
	};

struct 	forwardref {
	EXAWORD		source;
	BPTR		target;
	BACKPATCH	suite;
	};

#ifdef	_LABEL_C

BACKPATCH	FwdTree;	/* Points to List of Back patch adresses    */
LABEL		AdrTree;	/* Point to Base of TCode adresses	    */
EXAWORD		NewGkl;		/* Actual used length of New Constant table */
ALIASSE         Aliasse;

#endif	/* _LABEL_C */
	/* -------- */

#endif	/* _LABEL_H */
	/* -------- */



