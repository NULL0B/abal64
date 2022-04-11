/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 2003 Amenesik / Sologic  .			*/
/*									*/
/*									*/
/*		File	:	TRCOMETH.H				*/
/*		Version :	3.01					*/
/*		Date	:	28/08/03				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRCOMETH_H
#define	_TRCOMETH_H

#ifndef	UNIX
TCVARPTR	exception_variable( BPTR );
WORD	exception_method_active( VOID );
RESULTPTR	exception_operand(VOID );
TCVARPTR	instance_exception_variable( BPTR );
WORD	activate_explicite_exception( EXCEPTIONPTR );
#else

#endif


#endif 	/* _TRCOMETH_H */

