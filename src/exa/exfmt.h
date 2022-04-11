/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXFMT - H				*/
/*		Version :	2.1a					*/
/*		Date 	:	22/09/1993				*/
/*									*/
/*----------------------------------------------------------------------*/

#ifndef	EXFMTH		/* If not already included		*/
#define	EXFMTH		/* Avoid multiple inclusions		*/
#ifdef 	OPTIMISEUR
#define	ABAL13		/* Optimiser uses level 3 ABAL		*/
#define	ABAL14		/* Optimiser uses level 4 ABAL		*/
#define	ABAL21		/* Optimiser uses level 5 ABAL		*/
#endif
/*	Format code string control	*/
/*	--------------------------	*/

#define	FMT_SEP	0x0000		/* , Separateur des elements	*/
#define	FMT_DEB	0x00FE		/*    Debut de nouveau format	*/ 
#define	FMT_FIN	0x00FF		/*    Fin de format		*/

/*	Character type control masks	*/
/*	----------------------------	*/

#define	FMT_D	0x0001		/* Dn Alpha n non-oblig		*/
#define FMT_A	0x0081		/* An Alpha n Oblig		*/
#define	FMT_N	0x0002		/* Nn Numeric n non-oblig	*/
#define	FMT_Z	0x0082		/* Zn Numeric n Oblig		*/
#define	FMT_C	0x0003		/* Cn Alphanum n non-oblig	*/
#define	FMT_B	0x0083		/* Bn Alphanum n Oblig		*/
#define	FMT_W	0x000F		/* Wn Any character n non-oblig	*/
#define	FMT_U	0x008F		/* Un Any character n Oblig	*/

#ifdef	ABAL14			/* ---------------------------- */
#define	FMT_O	0x0092		/* Format N if none else Z	*/ 
#endif				/* ---------------------------- */

#define	FMT_K	0x0080		/* K	scroll inside length	*/

#define	FMT_V	0x0008		/* V  Virgule interne		*/
#define	FMT_P	0x0088		/* .  Virgule a saisir affich	*/

/*	Format Action codes		*/
/*	-------------------		*/

#define	FMT_PR	0x0020		/* "Libelle" a afficher		*/
#define	FMT_LF	0x0021		/* /n	n Linefeeds		*/
#define	FMT_TAB	0x0022		/* Tn	n Tabulations		*/
#define	FMT_ESP	0x0023		/* Xn	n Spaces		*/
#define	FMT_ATB	0x0024		/* \n   Attribute Video n	*/

/*	Format Environment codes	*/
/*	------------------------	*/

#define	FMT_ZER	0x0040		/* *	Padd Zeros		*/
#define	FMT_JL	0x0041		/* L 	Justifie Left		*/
#define	FMT_JR	0x0042		/* R	Justifie Right		*/
#define	FMT_JJ	0x0043		/* J	Justifie Centree	*/
#define	FMT_SGN	0x0042		/* + FL  Speciale Value for ASK */
#define	FMT_POS	0x0044		/* +	Both signs		*/
#define	FMT_NEG	0x0045		/* -	Only negative signs	*/
#define	FMT_PNG	0x0046		/* 	Only postive signs	*/
#define	FMT_MIL	0x0047		/* S  Separateur milliers	*/
#define	FMT_MCH	0x0048		/* S(c) Separateur milliers 	*/
#define	FMT_ZCH	0x0049		/* *(c) Padd Zeros character	*/
#define	FMT_STR	0x0050		/* E Format Libre		*/
#define	FMT_CUT	0x0051		/* F No fill to end of zone	*/
#define	FMT_DOL 0x0052		/* $	Print len$(string)	*/
#define	FMT_DCH	0x0053		/* $(c) Print until character or*/
				/*	End of string !		*/ 
#define	FMT_DYN	0x0054		/* ?	Use next variable as to */
				/*      fullfill the next FMT   */
				/*	filter requirements	*/
#ifdef	ABAL14			/* ---------------------------- */
#define FMT_INH	0x0055		/* If Zero then Padd like *	*/
#define	FMT_MNB	0x0056		/* Separation count format	*/
#define	FMT_H	0x0057		/* Hexadecimal Format for # / %	*/
#endif				/* ---------------------------- */

#ifdef	ABAL21
#define	FMT_PCH 0x0058		/* .(c)	Set decimal separator	*/
#define	FMT_Q	0x0059		/* Use Ask Colour/Atb in Print  */
#endif

#ifndef	OPTIMISEUR
#ifndef	ABAL_RTL
extern	BPTR	fmtbase;
#endif
#endif

#endif	/* ! EXFMTH */
