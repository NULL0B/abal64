/* -------------------------------------------------------------------- */
/*									*/
/*		Project ABAL : Tcode Post optimiser			*/
/*		-----------------------------------			*/
/*									*/
/*		  Copyright (c) 1989,1991 Amenesik / Sologic s.a.			*/
/*		  --------------------------------			*/
/*									*/
/*		File	:	AOMACRO.C   				*/
/*		Version :	1.4a					*/
/*		Date	:	24/09/1991				*/
/*									*/
/* -------------------------------------------------------------------- */
#ifndef	_AOMACRO_H
#define	_AOMACRO_H

#define	IS_LOCALE		0x8000
#define	TO_GLOBAL		0x7FFF
#define	CONVERTED_ENTRY		0x0080
#define	FIRST_DIMENSION		0x0040
#define	SECOND_DIMENSION	0x0020
#define	INTEGER_TYPE		0xFF77
#define	TCODE_NEWLINE		0x0080
#define	REMOVE_NEWLINE		0x007F
#define	tc_CMP_JMP		0x0038

/*	---------------------------------------------------		*/
/*	Definition of Macros Used to enhance source clarity 		*/
/*	---------------------------------------------------		*/
#define	TC_GDT	( newGDT != (BPTR) 0 ? newGDT : tcGDT )
#define	TC_LDT	( newLDT != (BPTR) 0 ? newLDT : tcLDT )

#define	IOF_CONSTANT	(( ((EXAWORD) *(sptr + si)) & 0x0060) == 0x0020)
#define	IOF_VARIABLE	(( ((EXAWORD) *(sptr + si)) & 0x0060) == 0x0040)
#define	IOF_REGISTER	(( ((EXAWORD) *(sptr + si)) & 0x0060) == 0x0060)
#define	IOF_NORMAL	(( ((EXAWORD) *(sptr + si)) & 0x0080) == 0x0000)
#define	IOF_SPECIAL	(( ((EXAWORD) *(sptr + si)) & 0x0080) != 0x0000)

#define	CLF_X_CONSTANT(indent)	 (( ((EXAWORD) *(sptr + si + indent)) & 0x0060) == 0x0020)
#define	CLF_X_VARIABLE(indent)	 (( ((EXAWORD) *(sptr + si + indent)) & 0x0060) == 0x0040)
#define	CLF_X_REGISTER(indent)	 (( ((EXAWORD) *(sptr + si + indent)) & 0x0060) == 0x0060)

#define	CLF_Y_CONSTANT(indent)	 (( ((EXAWORD) *(sptr + si + indent)) & 0x0006) == 0x0002)
#define	CLF_Y_VARIABLE(indent)	 (( ((EXAWORD) *(sptr + si + indent)) & 0x0006) == 0x0004)
#define	CLF_Y_REGISTER(indent)	 (( ((EXAWORD) *(sptr + si + indent)) & 0x0006) == 0x0006)

#endif	/* _AOMACRO_H */
	/* ---------- */

