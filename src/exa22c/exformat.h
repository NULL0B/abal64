/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXFORMAT.H  				*/
/*		Date 	:	20/04/1993				*/
/*		Version :	1.4c / 2.1a				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXFORMAT_H
#define	_EXFORMAT_H

#ifdef	ABAL_RTL

struct	iof_format_control	{

	EXAWORD	status;

/*	Dynamic format substition control	*/
/*	---------------------------------	*/

	EXAWORD	dynamic_item[DYNASIZE];
	EXAWORD	dynamic_index;
	EXAWORD	dynamic_limit;
	
/*	Format String analysis and operation control	*/
/*	--------------------------------------------	*/

	BPTR	current_format;
	BPTR	base_format;
	EXAWORD	format_status;
	EXAWORD	obligation;
	EXAWORD	format_check;
	EXAWORD	format_index;
	EXAWORD	format_limit;
	EXAWORD	format_length;
	EXAWORD	format_hex;

/*	BCD analysis and operation control 	*/
/*	----------------------------------	*/

	EXAWORD	bcd_sign;
	EXAWORD	bcd_real;
	EXAWORD	bcd_fraction;
	EXAWORD	bcd_power_shift;
	EXAWORD	separation;

/*	Numerical default characters		*/
/*	----------------------------		*/
	EXABYTE	nl_point;
	EXABYTE	nl_separator;
	EXABYTE	plus;
	EXABYTE	minus;
	EXABYTE	point;
	EXABYTE	separator;
	EXABYTE	space;
	EXABYTE	extrae;
	EXABYTE	extraf;

/*	ASK environment and operation controllers	*/
/*	-----------------------------------------	*/

	EXABYTE	ask_buffer[BLOCK];	/* Keyboard entry and workzone	*/
	EXAWORD	ask_count;		/* Nombre de caracteres Saisie 	*/
	EXAWORD	ask_limit;		/* Global buffer limit		*/
	EXAWORD	ask_index;		/* Current buffer pointer	*/
	BINAIRE	ask_line;		/* Initial screen line of ASK	*/
	BINAIRE	ask_column;		/* Initial ASK screen column id */
 	EXAWORD	insert_flag;		/* Insert / overwrite semaph 	*/
 	EXAWORD	ask_masks;		/* Ask mask for Input control 	*/
	EXAWORD	extended_masks;		/* ABAL 2.1a extended ASK MASK	*/
	EXAWORD	ask_colours;		/* Default ASK Colours FG|BG	*/
	EXAWORD	ask_atributs;		/* Default ASK Atribute value	*/

/*	HOTKEY management variables	*/
/*	---------------------------	*/

	EXAWORD	current_hotkey;		/* Key Last Causing Debranch	*/
 	EXAWORD	hotkey_adresse[256];	/* Matrix of jump adresses   	*/
 	EXAWORD	hotkey_character[256];	/* Keys that cause jumps     	*/
 	EXAWORD	hotkey_limit;		/* Number to test	     	*/

/*	FORMAT management variables	*/
/*	---------------------------	*/

	EXAWORD 	ask_format;		/* Current Format byte 		*/
	EXAWORD	format_god[FMTSIZE];	/*				*/
	EXAWORD	format_holder[FMTSIZE];	/* Tracking of format work	*/
	EXAWORD	format_counter[FMTSIZE];/* Maximum format count		*/

/*	GENERAL FLAGS and MASKS		*/
/*	-----------------------		*/
	EXAWORD	national_language;	/* Current National language	*/
	EXAWORD 	atb_context;		/* Current screen atributs	*/
	EXAWORD 	last_foreground;	/* Current fore ground colour	*/ 
	EXAWORD 	last_background;	/* Current back ground colour	*/
	};

#ifdef	_EXIOFUNC_C
	struct	iof_format_control	IOF;
#else
extern	struct	iof_format_control	IOF;
#endif

#define	dynamat 	IOF.dynamic_item
#define	dynadex 	IOF.dynamic_index
#define	dynamax 	IOF.dynamic_limit
#define	fmtptr		IOF.current_format
#define	fmtbase		IOF.base_format
#define	fmtflg		IOF.format_status
#define	fmtchk		IOF.format_check
#define	oblig 		IOF.obligation
#define	fmtdex		IOF.format_index 
#define	fmtmax		IOF.format_limit 
#define	fmtlen		IOF.format_length
#define	fmthex		IOF.format_hex
#define	fmtmilcount	IOF.separation
#define	fmtmil		IOF.separator
#define	askbuf		IOF.ask_buffer
#define	askmust		IOF.ask_count
#define	maxask		IOF.ask_limit
#define	abufdex		IOF.ask_index
#define	LastJumpKey	IOF.current_hotkey
#define	askjmp		IOF.hotkey_adresse
#define	asktst		IOF.hotkey_character
#define	jmpdex		IOF.hotkey_limit
#define askfmt		IOF.ask_format
#define	fmtgod		IOF.format_god
#define	fmthld		IOF.format_holder
#define	fmtcpt		IOF.format_counter
#define	askl		IOF.ask_line
#define	askc		IOF.ask_column
#define	insflg		IOF.insert_flag
#define	askcolour	IOF.ask_colours
#define	askatrib	IOF.ask_atributs
#define AtbContext	IOF.atb_context
#define	sepdec		IOF.nl_point
#define	defmil		IOF.nl_separator
#define	NationalLanguage IOF.national_language

#define	fbcdp		IOF.plus
#define	fbcdm		IOF.minus
#define	fbcdd		IOF.point
#define	zpadn		IOF.space
#define	fbcdc		IOF.bcd_sign
#define	fbcde		IOF.bcd_real
#define	fbcdf		IOF.bcd_fraction
#define	fbcdv		IOF.bcd_power_shift
#define	fbcdxe		IOF.extrae
#define	fbcdxf		IOF.extraf
#define	askmask		IOF.ask_masks
#define	LastBack	IOF.last_background
#define	LastFore	IOF.last_foreground
#define	iof_started	IOF.status
#endif

#endif 	/* _EXFORMAT_H */
	/* ----------- */ 


