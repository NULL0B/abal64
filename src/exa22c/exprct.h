/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987, 1992  Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXPRCT.H  				*/
/*		Version :	2.1a					*/
/*		Date 	:	04/08/1992				*/
/*									*/
/*----------------------------------------------------------------------*/

#ifndef	_EXPRCT_H
#define _EXPRCT_H

#define POINTER sizeof(BPTR)

/*	--------------------------------------				*/
/*	Description of Procedure Control Table				*/
/*	--------------------------------------				*/

struct  procform {

		BPTR	code_segment;	/* Procedure Code Segment	*/
		BPTR	table_segment;	/* Procedure variable table	*/
		BPTR	data_segment;	/* Procedure Data Segment	*/
		EXAWORD	code_length;	/* Procedure Code length	*/
		EXAWORD	options;	/* Procedure Options word	*/
#ifdef	ABAL21
		BPTR	const_segment;	/* Local Constant table		*/
		EXAWORD	code_sector;	/* Procedure Code Adress Sector */
		EXAWORD	data_length;	/* Procedure Data Length	*/
		EXAWORD	data_sector;	/* Procedure Data Adress Sector */
		EXAWORD	const_sector;	/* Local Constant Table Sector	*/
		EXAWORD	const_length;	/* Local Constant Table Length	*/
		EXAWORD	callers;	/* Usage counter of callers	*/
#endif	

};

#ifdef	ABAL21

#define	OVLOBJPTR struct overlay_object SPTR

struct	overlay_object	{
	EX_FILE_HANDLE	handle;
	BPTR		variables;
	BPTR		descriptors;
	BPTR		constants;
	EXAWORD		procmaxid;
	BPTR		procedures;
	BPTR		libraries;
	EXAWORD		nbdll;
	BPTR		ipt;
	VPTR		master;
	EXAWORD		islocal;
	};

#endif

	/* --------- */
#endif	/* _EXPRCT_H */
	/* --------- */
