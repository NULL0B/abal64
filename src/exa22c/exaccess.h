/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXACCESS - H				*/
/*		Date 	:	28/09/1989				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	EXACCESSH		/* Ensure not already included		*/

#define	EXACCESSH		/* Avoid multiple inclusions		*/

#ifdef	ABAL_DC			/* If Diffusion Version			*/
/* --------------------- */
/* Commands diffusion	 */
/* --------------------- */
#define	COEXAOPEN    DCEXAOPEN	 /* Commande Test for Open Possible 	*/
#define	COEXACLOSE   DCEXACLOSE	 /* Commande Close the File	   	*/
#define	COEXAPURGE   DCEXAPURGE	 /* Commande Liberate Job if Possible	*/
#define	COEXACHANGE  DCEXACHANGE /* Change File Atributs 		*/
#define	COEXASTATUS  DCEXASTATUS /* Statistics Of Coexa Table		*/
#define COEXAKILL    DCEXAKILL	 /* Destruction / Liberation of Access	*/
#if defined(RT_AIX) || defined(UNIXWARE) ||defined(LINUX)
#define	COEXAFPURGE  DCEXAFPURGE /* Commande Liberate Job if Possible	*/
#endif

#else				/* Not Diffusion Hence Test Version 	*/

/* --------------------- */
/* Commands Site Pilotes */
/* --------------------- */
#define	COEXAOPEN    SPEXAOPEN	 /* Commande Test for Open Possible 	*/
#define	COEXACLOSE   SPEXACLOSE	 /* Commande Close the File	   	*/
#define	COEXAPURGE   SPEXAPURGE	 /* Commande Liberate Job if Possible	*/
#define	COEXACHANGE  SPEXACHANGE /* Change File Atributs 		*/
#define	COEXASTATUS  SPEXASTATUS /* Statistics Of Coexa Table		*/
#define COEXAKILL    SPEXAKILL	 /* Destruction / Liberation of Access	*/
#if defined(RT_AIX) || defined(UNIXWARE) ||defined(LINUX)
#define	COEXAFPURGE  SPEXAFPURGE /* Commande Liberate Job if Possible	*/
#endif

#endif	/* ABAL_DC   */		/* Diffusion or Test Version		*/

#endif	/* EXACCESSH */		/* Multiple inclusion Lock		*/

