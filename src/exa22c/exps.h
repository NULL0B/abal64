/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXESC - H				*/
/*		Date 	:	11.05.1988				*/
/*									*/
/*----------------------------------------------------------------------*/

#define	_esc_SPREG 	0x00	/* Store Stack Pointer into Register	*/
#define _esc_REGSP 	0x01	/* Load Stack pointer from register	*/
#define _esc_WPREG 	0x02	/* Move work pointer to register	*/
#define _esc_REGWP 	0x03	/* Load Work pointer from register	*/
#define _esc_FPREG	0x04	/* Store Far pointer index to register	*/
#define	_esc_REGFP	0x05	/* Load Far pointer index from register */
#define _esc_PSHDS 	0x06	/* Save Base Pointer value to Stack	*/
#define _esc_POPDS	0x07	/* Recover Base Segment from stack	*/
#define _esc_GENDS 	0x08	/* Allocate memory to UP		*/
#define	_esc_FREDS	0x09	/* Liberate memory of UP		*/
#define	_esc_IPOPF	0x0A	/* Pop to Istack from Fstack		*/
#define _esc_FPOPI	0x0B	/* Pop from Fstack to Istack		*/
#define _esc_VARPT	0x0C	/* Place Real Variable offset to Reg	*/
#define	_esc_MEMRD	0x0D	/* Read memory byte to register		*/
#define	_esc_MEMWR	0x0E	/* Write to memory from register	*/
#define _esc_REGDX	0x0F	/* Establish DXREG Value from Register	*/
#define	_esc_DXREG	0x10	/* Save DXREG value to register		*/
#define	_esc_REGVF	0x11	/* Verify that the value in Reg is OK	*/
				/* ie not exceeding register limit	*/
#define	_esc_REGMX	0x12	/* Get current register limit		*/
#define	_esc_FICMX	0x13	/* Get current file limit		*/
#define	_esc_STKMX	0x14	/* Get current Stack limit		*/
#define	_esc_TMPMX	0x15	/* Get current workspace limit		*/

BPTR	 EsReg;		/* User accessable Extra segment register	*/
EXAWORD   	 DxReg;		/* User accessable Integer register		*/

