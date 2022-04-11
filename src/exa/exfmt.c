/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1997 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXFMT - C				*/
/*		Version	:	1.4a					*/
/*		Date 	:	24/03/1997				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_exfmt_c
#define	_exfmt_c
/* ---------------------------------------------------- */
/* Check for FORMAT V Calculation underway ** MACRO **	*/
/* ---------------------------------------------------- */
#define TerminateFormatV() { \
	if ( fbcdc & 1 ) {	/* FMT_V Waiting */	\
		/* Calculate power displacement */	\
		/* ---------------------------- */	\
		y = fbcde - fbcdv;			\
		/* Adjust for negative powers */	\
		/* -------------------------- */	\
		if ( (BINAIRE) y < 0 ) { y--; }		\
		/* Generate format V format code */	\
		/* ----------------------------- */	\
		*(wptr++) = (EXABYTE) FMT_V;		\
		*(wptr++) = (EXABYTE) ( y & 0x00FF);	\
		nlen -= 2;				\
		}					\
	/* Reset FMT_V Control */			\
	/* ------------------- */			\
	fbcde = 0; fbcdv = 0; fbcdc = 0;		\
	}				

/*
 *	ABALFMT	( fptr )
 *	----------------
 *	Generates a new format code string from an old format code string.
 *
 */
 
BPTR	abalfmt(fptr)
BPTR	fptr;
{
	EXAWORD	xtrl,x;
	BPTR	nptr,wptr;

/*	Allocate dynamic string zone	*/
/*	----------------------------	*/
if ((nptr = (BPTR) allocate(256)) == (BPTR) 0) {
	err_val = 27; 
	return((BPTR) 0); 
	}

wptr = nptr;

/*	Place header byte		*/
/*	-----------------		*/
*(wptr++) = (EXABYTE) 0x00FE; xtrl = 0;

do 	{
	/* Transcode string until end of string */
	/* ------------------------------------ */
	switch ((EXAWORD) *(fptr++) ) {
		case	0  : 	x = FMT_U; break;
		case 	1  : 	x = FMT_A; break;
		case	2  :	x = FMT_N; break;
		case	3  : 	x = FMT_Z; break;
		case	4  : 	x = FMT_V; break;
		case	5  : 	*(wptr++) = (EXABYTE) FMT_P; continue;
		case	6  :    x = FMT_PNG; break;
		case	7  : 	x = FMT_NEG; break;
		case	8  : 	*(wptr++) = (EXABYTE) FMT_STR; continue;
		case	9  : 	x = FMT_LF; break;
		case	10 : 	x = FMT_ESP; break;
		case	11 : 	*(wptr++) = FMT_JL; continue;
		case	12 : 	*(wptr++) = FMT_PR;
				x = (EXAWORD) *(fptr++);
				*(wptr++) = (EXABYTE) x;
				while ( x > 0 ) { *(wptr++) = *(fptr++); x--;}
				continue;
		case	13 :	*(wptr++) = FMT_SEP; continue;
		case	14 :	x = FMT_W; break;
		case	15 :	x = FMT_B; break;
		case	16 :	x = FMT_C; break;
		case	17 :	x = FMT_D; break;
		case	18 :	*(wptr++) = (EXABYTE) FMT_ZER; continue;
		case	19 :	*(wptr++) = (EXABYTE) FMT_MIL; continue;
		case	20 :	x = FMT_MCH; break;
		case	25 :	*(wptr++) = (EXABYTE) FMT_CUT; continue;
		case 0x00FF : 	*(wptr++) = (EXABYTE) FMT_FIN; xtrl = 1; 
				continue;
		default	   :	err_val = ABAL_FORMAT; *(wptr++) = FMT_FIN;
				return(0);
		}
	*(wptr++) = (EXABYTE) x;	/* Save format Code 		*/
	*(wptr++) = *(fptr++);	/* Tranfer optional arguament 	*/ 
	}
while ( xtrl == 0 );
return(nptr);
}

#include "exatofmt.c"
#include "exfmtoa.c"

#endif	/* _exfmt_c */
	/* -------- */



