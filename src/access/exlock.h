/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXLOCK - H				*/
/*		Date 	:	28/09/1989				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	EXLOCKH			/* If not already included		*/
#define	EXLOCKH			/* Avoid multiple inclusions		*/
/* --------------------- */
/* Commands Site Pilotes */
/* --------------------- */
#define	SPEXAOPEN	0x01	/* Commande Test for Open Possible 	*/
#define	SPEXACLOSE	0x02	/* Commande Close the File	   	*/
#define	SPEXACFILE	0x03	/* Test/Create/Lock                	*/
#define	SPEXAPURGE	0x04	/* Commande Liberate Job if Possible	*/
#define	SPEXADFILE	0x05	/* Lock/Unlink/Unlock 		   	*/
#define	SPEXARFILE	0x07	/* Rename/Lock	 		   	*/
#define	SPEXACHANGE	0x08	/* Change File Atributs 		*/
#define	SPEXASTATUS 	0x10	/* Statistics Of Coexa Table		*/
#define	SPEXASTATUSF	0x11	/* Statistics Of Coexa Table		*/
#define SPEXAKILL	0x20	/* Destruction / Liberation of Access	*/
#define SPEXAFPURGE	0x40	/* Liberation of locked Files           */



#define COEXAMPURGE	0x50	/* Liberation of lost messages          */
#undef	COEXAMPURGE		/* for the moment 			*/

/* --------------------- */
/* Commands diffusion	 */
/* --------------------- */
#define	DCEXAOPEN	0x81	/* Commande Test for Open Possible 	*/
#define	DCEXACLOSE	0x82	/* Commande Close the File	   	*/
#define	DCEXACFILE	0x83	/* Test/Create/Lock       	   	*/
#define	DCEXAPURGE	0x84	/* Commande Liberate Job if Possible	*/
#define	DCEXADFILE	0x85	/* Lock/Unlink/Unlock     	   	*/
#define	DCEXARFILE	0x87	/* Rename/Lock	 		   	*/
#define	DCEXACHANGE	0x88	/* Change File Atributs 		*/
#define	DCEXASTATUS 	0x90	/* Statistics Of Coexa Table		*/
#define	DCEXASTATUSF	0x91	/* Statistics Of Coexa Table		*/
#define DCEXAKILL	0xA0	/* Destruction / Liberation of Access	*/
#define DCEXAFPURGE	0xC0	/* Liberation of locked Files           */

#define	COEXASHARELOCK	1	/* Commande Sharelock requested		*/
#define	COEXAEXCLUSIVE	2	/* Commande Exclusive locking request	*/

#define	COEXALOCKTYPE	3
#define	COEXALOCKSHIFT	2	

#define	GETPROCESS	0xBB
#define	DROPPROCESS	0xCC
#define	MSGQSIZE	0xDD

#define	SUCCESS	0

#define	MAXLOCKNAME	259

struct exapadd {
	int 	lock_mode;	/* Opening Mode to Attempt		*/
	int	lock_func;	/* Function to Be Performed		*/
	int	lock_owner;	/* Process ID requesting Operation	*/
	long	lock_inode;	/* Unique INODE on			*/
	long	lock_dnode;	/* Unique Device			*/
	char    lock_name[MAXLOCKNAME];      /* file name (DEG)                      */  
	}; 


static	char	COREFILE[]="/tmp/accesscore";

#endif	/* EXLOCKH */		/* Multiple exclusion definition	*/
