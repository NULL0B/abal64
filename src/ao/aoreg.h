/* -------------------------------------------------------------------- */
/*									*/
/*		Project ABAL : Tcode Post optimiser			*/
/*		-----------------------------------			*/
/*									*/
/*		  Copyright (c) 1989,1991 Amenesik / Sologic s.a.			*/
/*		  --------------------------------			*/
/*									*/
/*		File	:	REGISTER.H   				*/
/*		Version :	1.4a					*/
/*		Date	:	26/09/1991				*/
/*									*/
/* -------------------------------------------------------------------- */
#ifndef	_REGISTER_H
#define	_REGISTER_H

/*

	Subject	:	Optimisation of Register usage by AO
	---------	------------------------------------

	Date	:	26/03/1991
	---------	----------


	Introduction
	------------

	Currently the translator does not perform register optimisation
	and consequently is suceptible to generate more instructions than
	are actually required to fulfill the desired operation.

	At the 'source' level the programer may need to reference certain
	sub-expressions many times in a complex expression. These repeated
	sub-expressions are generated and hence executed each time they are
	encountered, in detriment to the execution time and code size.

	Since all sub-expressions are contained in the 'logical' registers
	of the virtual machine, judicious register optimisation would offer
	an increase in execution speed and a decrease in program size by
	re-using common sub-expressions.


	Examples  :	
	-----------
		Print=1:Chr$(/b3),Space(5),Chr$(/b3)

	In this simple but frequent example the translator will generate
	the following tcode :

	xxxx:	CLF	#1, CHR$( /B3 )		; Length 6
		CLF	#2, SPACE(5)		; Length 6
		CLF	#3, CHR$( /B3 )		; Length 6
		IOF				; Length 1
			PRN	#1		; Length 2
			PRN	#2		; Length 2
			PRN	#3		; Length 2
		FIO				; Length 1

						; Total : 26 bytes

	The second 'CHR$( /B3 )' into register 3 is however redundant
	and thus could be avoided by reusing the 'CHR$( /B3 )' generated
	into register 1. The resulting tcode would be as follows :

	xxxx:	CLF	#1, CHR$( /B3 )		; Length 6
		CLF	#2, SPACE(5)		; Length 6
		IOF				; Length 1
			PRN	#1		; Length 2
			PRN	#2		; Length 2
			PRN	#1		; Length 2
		FIO				; Length 1

						; Total : 20 bytes


  	Thus 6 bytes of tcode have been saved and execution time is 
	reduced by a factor of T (where T represents the execution time
	for the 'CHR$( /B3 )' expression ).


	No consider the same technique applied to a more common example
	used frequently in screen generation algorithms :

		Print=1:Tab(1,x),Chr$(/b3),Space(5),Chr$(/b3),Space(5) '
				,Chr$(/b3),Space(5),Chr$(/b3)

	Without register optimisation 3 'SPACE(5)' expressions and 4
	'CHR$(/B3)' expressions are required as can be seen from the
	code generated below :


	xxxx:	CLF	#1, CHR$( /B3 )		; Length 6
		CLF	#2, SPACE(5)		; Length 6
		CLF	#3, CHR$( /B3 )		; Length 6
		CLF	#4, SPACE(5)		; Length 6
		CLF	#5, CHR$( /B3 )		; Length 6
		CLF	#6, SPACE(5)		; Length 6
		CLF	#7, CHR$( /B3 )		; Length 6
		IOF				; Length 1
			PRN	#1		; Length 2
			PRN	#2		; Length 2
			PRN	#3		; Length 2
			PRN	#4		; Length 2
			PRN	#5		; Length 2
			PRN	#6		; Length 2
			PRN	#7		; Length 2
		FIO				; Length 1

						; Total : 58 bytes

	Which after register optimisation :-

	xxxx:	CLF	#1, CHR$( /B3 )		; Length 6
		CLF	#2, SPACE(5)		; Length 6
		IOF				; Length 1
			PRN	#1		; Length 2
			PRN	#2		; Length 2
			PRN	#1		; Length 2
			PRN	#2		; Length 2
			PRN	#1		; Length 2
			PRN	#2		; Length 2
			PRN	#1		; Length 2
		FIO				; Length 1

						; Total : 28 bytes

	- eliminates 30 bytes of tcode, the execution of 2 'SPACE(5)'
	and 3 'CHR$(/B3)' functions. An other advantage, as yet unmentioned,
	is that the result uses only 2 registers rather than 7 registers
	which would allow the use of complex expressions which currently
	the translator would refuse due to a lack of registers to hold
	intermediate results !


	The previous 2 examples , though extremely simple, indicate clearly
	the increase in speed and the decrease in size which may result from
	this type of optimisation.

	

	Implimentation :
	----------------

	To impliment this optimisation technique the tcodes may be divided
	into 3 different groups :

		1 ) Those that do not use registers 

		2 ) Those that use Target registers to generate operands.

		3 ) Those that use Source registers to retrieve their operands.
 
	Evidently the tcodes of group 1 above cannot benifit from register
	optimisation.

	The tcodes in groups 2 and 3 will intersect giving rise to a further
	derived group :

		2+3 ) Those that use both Target and Source Registers.

	
	The basic approach for register optimisation is relativly simple
	and is as follows :

		At each new line 	- Reset register following context to
					  ensure that no carry over effects
					  are introduced.

		Tcode Group 2		- Ensure that the tcode construction
					  has not already been executed since
					  the last new line ( redundancy check)
					  and if so then the expression will 
					  be removed and thus liberate the
					  register for compacting techniques.
					  Redirect this register to that which
					  contains the identical result.

		Tcode Group 3		- Check for references to 'redirected'
					  registers and correct encountered
					  cross referencing.

	
	It can be seen from the above that 3 discreet function interfaces
	exist. This may be consolidated into one generic function call
	which checks for and performs the above operations in the indicated
	order.

	The tcode structure must be presented to the register follower before
	peep hole optimisaton to ensure coherent results.


	Register contents
	-----------------
	
	In order that the register shadowing may be efficient, different
	register contents must be recognised :

		- Terminal or First hand Results

		- Modified Terminal results

		- Intermediate or Second hand results

		- Modified Intermediate results.

	
	A terminal result is defined as the result of an expression which
	does not, in it's construction, rely upon the contents of another
	register.

	An intermediate result is defined as the result of an expression 
	which refers to previously calculated registers to arrive at it's
	value.

	Both type may have been modified by any of the Modifier Opertaions.

	Thus any Register expression may be represented by a tree structured
	graph indicating the parent factors used in it's composition.

	Redundant Register expressions may be detected by comparing the
	expression with each of the existing graphs.

	Example :	(assuming BCD type variables) 

		c = ( (a(i)+b) * b ) + ( (a(i)+b) / b )

	The following tcode is generated :

		LXI	#1, [I]		; 4
		VPT	#1, [A]		; 4
		ADV	#1, [B] , #2	; 5
		MLV	#2, [B] , #3	; 5
		LXI	#4, [I]		; 4
		VPT	#4, [A]		; 4
		ADV	#4, [B], #5	; 5
		DVV	#5, [B], #6	; 5
		ADR	#3, #6, #7	; 4
		STR	#7, [C]		; 4

					; Total 10 tcodes 44 bytes 7 registers

	This could be optimised to produce :

		LXI	#1, [I]		; 4
		VPT	#1, [A]		; 4
		ADV	#1, [B] , #2	; 5
		MLV	#2, [B] , #3	; 5
		DVV	#2, [B] , #4	; 5
		ADR	#3, #4, #5	; 4
		STR	#5, [C]		; 4

					; Total 7 tcodes 31 bytes 5 registers

	Thus a very costly indexed BCD variable addition is avoided.

*/

#define	_REG_INTEGER		0x0001
#define	_REG_CONSTANT		0x0002
#define	_REG_VARIABLE		0x0004
#define	_REG_VARPTR		0x0008
#define	_REG_REGISTER		0x0010

#ifdef	_REGISTER_C

#define	VRAI		1
#define	FAUX		0
#define	ERREUR		0xFFFF

#define	_DIEZ_REGS		255

#define	_REG_MODIFIED		0x0800
#define	_REG_REDIRECTED		0x1000
#define	_REG_OCCUPIED		0x2000
#define	_REG_PRIMARY		0x4000		
#define	_REG_SECONDARY		0x8000
#define	_REG_DIMENSIONED	(_REG_PRIMARY | _REG_SECONDARY)


#define	SHADOWPTR	struct shadow_register XPTR

#define	OPERANDPTR	struct register_operand XPTR

	struct	register_operand {

		EXAWORD	type;	/* Integer value 16 or 8 */
				/* Constant pointer	 */
				/* Variable Pointer      */
				/* Register Operand	 */

		EXAWORD	registre;

		EXAWORD	constant;

		EXAWORD	variable;

		EXAWORD	integer;

		OPERANDPTR	next;

		};

	struct	shadow_register {

		EXAWORD	current_type;	/* Terminal,Intermediate,Modified */

		EXAWORD	operation_type;	/* Tcode from which generated	  */

		EXAWORD	register_link;	/* Indicates redirected target	  */

		EXAWORD	tcode_offset;	/* Result Adresse of operation	  */

		SHADOWPTR	parent;	/* Before Modif 		  */
		SHADOWPTR	previous;	/* Copy of previous reg	*/ 
		OPERANDPTR	operand;	/* Liste	*/

		};

#endif	/* _REGISTER_C */
	/* ----------- */

#endif	/* _REGISTER_H */
	/* ----------- */


