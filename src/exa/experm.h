/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1990 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXPERM - H				*/
/*		Version :	1.4a					*/
/*		Date 	:	01/06/1990				*/
/*									*/
/*----------------------------------------------------------------------*/

/*	ASSIGN option mask values		*/
/*	-------------------------		*/

#ifndef	EXPERMH		/* If not already included			*/
#define	EXPERMH		/* Avoid multiple inclusions			*/


/*	Values programable via the ASSIGN statement 			*/
/*	-------------------------------------------			*/

#define		NGF_R_W			0x0001	/* Read write flag 	*/
						/* Established by WR	*/

#define		NGF_P_E			0x0002  /* Partage blockage	*/
						/* Established by EX	*/

#define		NGF_I_C			0x0004  /* Immediate / Copie	*/
						/* Established by C	*/

#define		NGF_I_D			0x0008	/* Immediate / Diferee	*/
						/* Established by DF	*/

#define		NGF_TYP			0x00F0	/* Niveau d'access	*/
						/* Access method MASK	*/

#define		NGF_DV			0x0010	/* Raw device		*/

#ifdef	ABAL_LONG_NAMES
#define		NGF_LN			0x8000	/* Long Names mode	*/
#endif

/*		FILE ACCESS METHODS		*/
/*		-------------------		*/
#define		NGF_IO			0x0000	/* Direct access Sector */
#define		NGF_SQ			0x0020	/* Sequential 		*/
#define		NGF_SI			0x0040	/* Sequential indexed	*/
#define		NGF_MC			0x0060  /* Multicritere		*/
#define		NGF_BD			0x0080	/* Base de donnees	*/
#define		NGF_MCBD		0x00E0	/* MC under BD control	*/
#ifdef	ABALSQL
#define		NGF_SQL			0x00C0	/* API Abal SQL native	*/
#endif

#ifdef	ABALXML
#define		NGF_XML			0x00A0	/* XML SOURCE     	*/
#endif

/*		DEVICE TYPES			*/
/*		------------			*/
#define		NGF_IM			0x0050	/* Printer file		*/
#define		NGF_GR			0x0030	/* Graphical System 	*/
#define		NGF_CM			0x0070	/* Communication (IPC)	*/

/*	Values used internally by the Executeur (Systeme Dependant)	*/
/*	-----------------------------------------------------------	*/

#define		ASS_NAME_VALID		0x0100	/* File name zone has  been allocated   	*/
#define		ASS_BUFF_VALID		0x0200	/* Print or MC Buffer has been allocated	*/
#define		ASS_BASE_VALID		0x0400	/* Data Base Structure has been allocated	*/
#define		ASS_VIRT_VALID		0x0800	/* A Virtuel memory operation has been performed on file	*/
#define		ASS_LOAD_VALID		0x1000	/* A executable image is currently loaded	*/

#ifdef	ABAL21
#define		ASS_PRINT_FILE		0x2000	/* A Print File Action	*/
#endif

/*	0x4000	unused		*/

#define		ASS_FIND_VALID		0x8000	/* A FIND operation has been performed	*/

#endif	/* ! EXPERMH */

