/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1992 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXMACRO.H  				*/
/*		Version :	1.2a / 1.5a				*/
/*		Date 	:	04/08/1992				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXMACRO_H
#define	_EXMACRO_H


#define	unknown_tcode_error err_val = EXER_FUNCWOT; return( SOFTERROR );


/*	I N D E X C H E C K ( IndexVal , LimitPtr )		*/
/*	-------------------------------------------		*/
/*	Controle de debordement des indices d'un tableau	*/
/*								*/
/*	EXAWORD	IndexVal	: Valeur a controller		*/
/*	BPTR	LimitPtr	: Pointeur sur limite		*/
/*	------------------------------------------------	*/

#define	IndexCheck( IndexVal , LimitPtr ) { \
	if ( IndexVal > Tcodeword( LimitPtr ) ) { \
		err_val = ABAL_NDX2BIG; return(SOFTERROR); \
		} \
	if ( IndexVal == 0 ) { \
		err_val = ABAL_NDXZERO; return(SOFTERROR); \
		} \
	}

#ifdef	ABAL21

#define	PtrIndexCheck( IndexVal , LimitPtr ) { \
	if ( IndexVal > Tcodeword( LimitPtr ) ) { \
		err_val = ABAL_NDX2BIG; return((BPTR) 0); \
		} \
	if ( IndexVal == 0 ) { \
		err_val = ABAL_NDXZERO; return((BPTR) 0); \
		} \
	}
#endif

/*	E X T M P C H E C K ( AllocLen )			*/
/*	--------------------------------			*/
/*	Controle de debordement de l'espace de travail		*/
/*	des descripteurs temporaire et les QuickMalloc		*/
/*								*/
/*	EXAWORD	AllocLen	: Valeur d'alloc requise	*/
/*	------------------------------------------------	*/

#define StackCheck( AllocLen ) { \
	if (( worktop + AllocLen ) > dieztmp ) { \
		err_val = ABAL_MEMORY; return(SOFTERROR); \
		} \
	}

/*	C H E C K I R E G ( Reg , Wptr )			*/
/*	--------------------------------			*/
/*	Controle de validite  du registre d'index 1er Dimension */
/*	(Used in Motor() only !! )				*/

#define CheckIreg( Reg , Wptr ) { \
	if ( ireg [ Reg ] > Tcodeword( (Wptr + (2 * WORDSIZE))) ) { \
				goto INDEX2BIG; \
				} \
	if ( ireg [ Reg ] == 0 ) { \
				goto INDEXZERO; \
				} \
	}

/*	C H E C K A R E G ( Reg , Wptr )			*/
/*	--------------------------------			*/
/*	Controle de validite  du registre d'index 2em Dimension */
/*	(Used in Motor() only !! )				*/

#define CheckAreg( Reg , Wptr ) { \
	if ( areg [ Reg ] > Tcodeword( (Wptr + (3 * WORDSIZE))) ) { \
				goto INDEX2BIG; \
				} \
	if ( areg [ Reg ] == 0 ) { \
				goto INDEXZERO; \
				} \
	}


/*	P I L E C H E C K ( Alloc )			*/
/*	---------------------------			*/
/*	Stack check macro for MOTOR()			*/
/*	-----------------------------			*/

#define	PileCheck( alloc ) { \
	if (( worktop + alloc ) >= dieztmp ) { \
		err_val = ABAL_MEMORY; tcode = SOFTERROR; goto CALCEXIT; \
		} \
	}


/*	V A R B X F E R ( How )				*/
/*	-----------------------				*/

#define	VarbXfer( How ) { \
	e = How; \
	goto  EXVRBCNV; \
	}


#endif	/* _EXMACRO_H */
	/* ---------- */
