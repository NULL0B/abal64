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
#define	COEXASTATUSF DCEXASTATUSF/* Statistics Of Coexa Table		*/
#define COEXAKILL    DCEXAKILL	 /* Destruction / Liberation of Access	*/
#define COEXACFILE   DCEXACFILE /* Destruction / Liberation of Access	*/
#define COEXADFILE   DCEXADFILE /* Destruction / Liberation of Access	*/
#define COEXARFILE   DCEXARFILE /* Rename and Lock			*/


#else				/* Not Diffusion Hence Test Version 	*/

/* --------------------- */
/* Commands Site Pilotes */
/* --------------------- */
#define	COEXAOPEN    SPEXAOPEN	 /* Commande Test for Open Possible 	*/
#define	COEXACLOSE   SPEXACLOSE	 /* Commande Close the File	   	*/
#define	COEXAPURGE   SPEXAPURGE	 /* Commande Liberate Job if Possible	*/
#define	COEXACHANGE  SPEXACHANGE /* Change File Atributs 		*/
#define	COEXASTATUS  SPEXASTATUS /* Statistics Of Coexa Table		*/
#define	COEXASTATUSF SPEXASTATUSF/* Statistics Of Coexa Table		*/
#define COEXAKILL    SPEXAKILL	 /* Destruction / Liberation of Access	*/
#define COEXACFILE   SPEXACFILE /* Destruction / Liberation of Access	*/
#define COEXADFILE   SPEXADFILE /* Destruction / Liberation of Access	*/
#define COEXARFILE   SPEXARFILE /* Rename/Lock				*/

#endif	/* ABAL_DC   */		/* Diffusion or Test Version		*/


int	lockqueue=0;		/* Message File ID			*/

/* --------------------*/
/* functions prototype */
/* --------------------*/

#ifdef	_PROTOTYPES
int	Access(char * nomfic , int perm ,int  mode );
void	liberlox(char* fnom );
int	matb(char  * fnom ,WORD exflag ,WORD cflag ,WORD wrflag);
void	PurgeLox( void );
#else
int	Access();
void	liberlox();
int	matb();
void	PurgeLox();
#endif


#endif	/* EXACCESSH */		/* Multiple inclusion Lock		*/

