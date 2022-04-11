#ifndef	_tcvdt_h
#define	_tcvdt_h

/*		---------------------------------------			*/
/*		T C O D E _ V A R I A B L E _ T A B L E			*/
/*		---------------------------------------			*/

struct	tcode_variable_table {
					/* ---------------------------- */
	HUGE		field;		/* Current field offset		*/
	HUGE		maxfield;	/* Max Field offset		*/
	WORD		nombre;		/* Number of variables in table */
	WORD		descriptor;	/* Initial non optimised 	*/
	WORD		Descriptor;	/* final optimised		*/
	WORD		scope;		/* Global or Local Scope	*/
	TCVARPTR	firstused;	/* Root of optimised variables	*/
	TCVARPTR	lastused;	/* Foot of optimised variables	*/
	TCVARPTR	variable;	/* Most recent variable		*/
	TCVARPTR	first;		/* Initial variable		*/
					/* ---------------------------- */
	};

#endif	/* _tcvdt_h */

