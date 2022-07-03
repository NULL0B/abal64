/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXMIMO.H  				*/
/*		Date 	:	28/05/1993				*/
/*		Version :	2.1a					*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXMIMO_H
#define	_EXMIMO_H

#ifdef	PROLOGUE
#define	CICOMIMO
#endif

#ifndef	WIN32

#ifndef UNIX
EXTERN	EXAWORD	activate_event_interrupt( BPTR );
EXTERN	void	inhibit_event_interrupt( VOID );
EXTERN	void	cancel_event_interrupt( VOID );
EXTERN	EXAWORD	set_event_parameter( EXAWORD, EXAWORD );
EXTERN	EXAWORD	get_event_parameter( EXAWORD );
#else
EXTERN	EXAWORD	activate_event_interrupt();
EXTERN	void	inhibit_event_interrupt();
EXTERN	void	cancel_event_interrupt();
EXTERN	EXAWORD	set_event_parameter();
EXTERN	EXAWORD	get_event_parameter();
#endif


/*	-------------------------------------------------------		*/
/*	LOW LEVEL MOUSE INPUT MOUSE OUTPUT INTERFACE PROTOTYPES		*/
/*	-------------------------------------------------------		*/
#ifndef UNIX
EXTERN	EXAWORD	init_mimo( VOID );
EXTERN	EXAWORD	activate_mimo( VOID );
EXTERN	EXAWORD	get_mimo_status( VOID );
EXTERN	EXAWORD	get_mimo( VOID );
EXTERN	EXAWORD	get_mimo_col( VOID );
EXTERN	EXAWORD	get_mimo_lin( VOID );
EXTERN	EXAWORD	get_mimo_par( VOID );
EXTERN	EXAWORD	get_mimo_mask( VOID );
EXTERN	EXAWORD	get_mimo_type( VOID );
EXTERN	EXAWORD	flush_mimo( VOID );
EXTERN	EXAWORD	inhibit_mimo( VOID );
EXTERN	EXAWORD	fin_mimo( VOID );
EXTERN	VOID	set_mimo_mask( EXAWORD );
EXTERN	VOID	save_mimo_context( BPTR );
EXTERN	VOID	restore_mimo_context( BPTR );
#else
EXTERN	EXAWORD	init_mimo();
EXTERN	EXAWORD	activate_mimo();
EXTERN	EXAWORD	get_mimo_status();
EXTERN	EXAWORD	get_mimo();
EXTERN	EXAWORD	get_mimo_col();
EXTERN	EXAWORD	get_mimo_lin();
EXTERN	EXAWORD	get_mimo_par();
EXTERN	EXAWORD	get_mimo_mask();
EXTERN	EXAWORD	get_mimo_type();
EXTERN	EXAWORD	flush_mimo();
EXTERN	EXAWORD	inhibit_mimo();
EXTERN	EXAWORD	fin_mimo();
EXTERN	VOID	set_mimo_mask();
EXTERN	VOID	save_mimo_context();
EXTERN	VOID	restore_mimo_context();
#endif


#endif	/* WIN32 */

/*	-----------------------------		*/
/*	MIMO	Interface event codes		*/
/*	-----------------------------		*/

#define	MIMO_NO_EVENT		0x0000
#define	MIMO_KEYBOARD		0x0002
#define	MIMO_MOUSE_DOWN		0x0010
#define	MIMO_MOUSE_UP		0x0020
#define	MIMO_CLICK		0x0020
#define	MIMO_DOUBLE_CLICK	0x0080
#define	MIMO_MOVE		0x0100
#define	MIMO_WHILE_DOWN		0x0200
#define	MIMO_IS_DOWN		0x0400

#define	MIMO_LEFT 		0x0001
#define	MIMO_RIGHT		0x0002
#define MIMO_MIDDLE		0x0004
#define MIMO_WHEELUP		0x0008
#define MIMO_WHEELDOWN		0x0010


#endif 	/* _EXMIMO_H */
	/* --------- */

