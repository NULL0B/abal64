/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1992 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXIOF.H  				*/
/*		Date 	:	16/11/1992				*/
/*		Version :	1.4c / 2.1a				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXIOF_H
#define	_EXIOF_H

#ifndef	_EXIOFUNC_C
#define	IOF_SCOPE extern
#else
#define	IOF_SCOPE
#endif	

IOF_SCOPE	EXAWORD	askaction;
IOF_SCOPE	EXAWORD	DollarLength;
IOF_SCOPE	EXAWORD	actioncol,actionlin;
IOF_SCOPE	EXAWORD	AskActionFlag;
IOF_SCOPE	EXAWORD	AskDynamic;
IOF_SCOPE	BPTR	AskActionFdex;
IOF_SCOPE	BPTR	AskActionFormat;	

IOF_SCOPE	EXAWORD	xsign;			/* Sign Character	*/
IOF_SCOPE	EXAWORD	xdigit;			/* Excess J L digits	*/
IOF_SCOPE	EXAWORD	ydigit;			/* Second BCD digit	*/
IOF_SCOPE	EXAWORD bcdphc;			/* BCD Digit phase ctrl */
IOF_SCOPE	EXAWORD	dgfl;			/* Leading Zero Flag	*/

IOF_SCOPE	BINAIRE	head,tail;		/* Real Digit Counters	*/
IOF_SCOPE	BINAIRE	hfill,tfill;		/* Fill Digit Counters	*/
IOF_SCOPE	BINAIRE	saute;			/* Lost digit counter	*/
IOF_SCOPE	EXABYTE	PowerZone[BCDMAX];	/* Format V Conversions	*/
IOF_SCOPE	EXAWORD	ll_ask_flag;		/* LL ASK function state*/
IOF_SCOPE	EXAWORD	abufbig;		/* Askbuffer suage flag */

#ifdef	ABAL14				
IOF_SCOPE	EXAWORD	InhibitZero;	
#endif					

IOF_SCOPE	EXAWORD	AskFont;
IOF_SCOPE	EXAWORD	PrintFont;
IOF_SCOPE	EXAWORD	IofFontHolder;
IOF_SCOPE	EXAWORD	BackGroundMask;
IOF_SCOPE	EXAWORD	ForeGroundMask;


#endif	/* _EXIOF_H */
	/* -------- */

