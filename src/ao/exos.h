/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1997 Amenesik / Sologic  			*/
/*									*/
/*		Module  :	EXOS  - H				*/
/*		Version :	1.4c / 2.1e				*/
/*		Date 	:	05/03/1997				*/
/*									*/
/*----------------------------------------------------------------------*/

#ifndef	EXOSH		/* If not already included			*/
#define	EXOSH		/* Avoid multpile inclusions			*/

#define	FixedRegisters	/* Executeur Model Statique	#regs = 64	*/

/*			--- A T T E N T I O N ---			*/
/*									*/
/*	Modification de ce fichier peut avoir des effets de bords	*/
/*	qui concernes toutes les executeurs et bien cachees		*/
/*									*/
/*	PROLOGUE2, PROLOGUE3, DOS, SPIX, GENIX, AIX, LSX, VMS		*/
/*	NCR, UNISYS, XENIX, XENIXIX, SUPERTEAM , HP9000	, ULTRIX	*/
/*	(NIXDORF) (ICL) (GOUPIL)					*/
/*	-----------------------------------------------------		*/

#ifdef	ABAL21	/* VERSION 2.1 */
		/* ----------- */
#define	ABAL_Version	'2'		/* Version Major		*/
#define	ABAL_Index	'1'		/* Version Minor		*/
#define	ABAL_Niveaux	'e'		/* Version Level		*/
#define	ENV_Version	'1'		/* Version Major		*/
#define	ENV_Index	'1'		/* Version Minor		*/
#define	ENV_Niveaux	'b'		/* Version Level		*/

#define MSG_ID_EXA   "*STX*3EXA     21e00"
#define MSG_ID_EXADB "*STX*3EXADB   21e00"

#define	ABAL14
#define	ABAL13
#define	ABAL12
#define	ABAL11

#else
#ifdef	ABAL14	/* VERSION 1.4 */
		/* ----------- */
#define	ABAL_Version	'1'		/* Version Major		*/
#define	ABAL_Index	'4'		/* Version Minor		*/
#define	ABAL_Niveaux	'e'		/* Version Level		*/
#define	ENV_Version	'1'		/* Version Major		*/
#define	ENV_Index	'1'		/* Version Minor		*/
#define	ENV_Niveaux	'a'		/* Version Level		*/

#define MSG_ID_EXA   "*STX*3EXA     14e00"
#define MSG_ID_EXADB "*STX*3EXADB   14e00"

#else

#ifdef	ABAL13	/* VERSION 1.3 */
		/* ----------- */
#define	ABAL_Version	'1'		/* Version Major		*/
#define	ABAL_Index	'3'		/* Version Minor		*/
#define	ABAL_Niveaux	'd'		/* Version Level		*/
#define	ENV_Version	'1'		/* Version Major		*/
#define	ENV_Index	'1'		/* Version Minor		*/
#define	ENV_Niveaux	'a'		/* Version Level		*/

#define MSG_ID_EXA   "*STX*3EXA     13d00"
#define MSG_ID_EXADB "*STX*3EXADB   13d00"

#else


#ifdef	ABAL12	/* VERSION 1.2 */
		/* ----------- */
#define	ABAL_Version	'1'		/* Version Major		*/
#define	ABAL_Index	'2'		/* Version Minor		*/
#define	ABAL_Niveaux	'g'		/* Version Level		*/
#define	ENV_Version	'1'		/* Version Major		*/
#define	ENV_Index	'1'		/* Version Minor		*/
#define	ENV_Niveaux	'a'		/* Version Level		*/

#define MSG_ID_EXA   "*STX*3EXA     12g00"
#define MSG_ID_EXADB "*STX*3EXADB   12g00"

#endif	/* ABAL12 */
#endif	/* ABAL13 */
#endif  /* ABAL14 */
#endif  /* ABAL21 */	

/*	------------------------------------------		*/
/*	Standard Executer model definition switchs		*/
/*	------------------------------------------		*/
#define ABALSF		/* Systeme de fichiers			*/
#define ABALSQ		/* Acces Sequentiel			*/
#define	ABALSI		/* Sequentiel indexe			*/
#define ABALLV		/* Longeur Variable			*/
#define	ABALCLP		/* Appels procedures			*/
#define	ABALRTP		/* Retour des procedures		*/
#define	ABALME		/* Memoire etendu			*/


/*	Parametres de Generation : PROLOGUE 2		*/
/*	-------------------------------------		*/

#ifdef PROLOGUE2
#define	PRL_SF				/* Amenesik / Sologic File Syteme Calls	*/
#define	INTELASM1			/* 1st Level Optimised ASM	*/
#define	EXIT_VALUE	0		/* Valeur de retour		*/
#define	PROLOGUE			/* Amenesik / Sologic base operating OS	*/
#define	INTEL				/* Intel Microprocessors	*/
#define	IDIRECT				/* Indirect word storage	*/
#define ABALBIG				/* Use Explicite FAR pointers 	*/
#define	OS_ID		0		/* Operating Systeme id Code	*/
#define	MOINS_UN       0xFFFF		/* System Error return value	*/
#define	OPTIONFLAG	'/'		/* Executeur Option indicator	*/
#ifdef	ABAL14
#define	BUF_CICO
#endif
#endif /* PRL2 */

/*	Parametres de Generation : PROLOGUE 3		*/
/*	-------------------------------------		*/

#ifdef PROLOGUE3
#define	PRL_SF				/* Amenesik / Sologic File Syteme Calls	*/
#define	INTELASM1			/* 1st Level Optimised ASM	*/
#define	EXIT_VALUE	0		/* Valeur de retour		*/
#define	PROLOGUE			/* Amenesik / Sologic base operating OS	*/
#define	INTEL				/* Intel Microprocessors	*/
#define	IDIRECT				/* Indirect word storage	*/
#define ABALBIG				/* Use Explicite FAR pointers 	*/
#define	OS_ID		0		/* Operating Systeme id Code	*/
#define	MOINS_UN       0xFFFF		/* System Error return value	*/
#define	PROTEGE_286			/* Protected mode memory	*/
#define	OPTIONFLAG	'/'		/* Executeur Option indicator	*/
#ifdef	ABAL14
#define	BUF_CICO
#endif
#endif /* PRL3 */

/*	Parametres de Generation : MS-DOS    		*/
/*	----------------------------------   		*/

#ifdef	DOS

#ifdef	WIN16	/* Windows 16 bits */
#define	ABALLAN				/* DOS Local Area Networking	*/
#define	PRL_SF				/* Amenesik / Sologic File Syteme Calls	*/
#define	INTELASM1			/* 1st Level Optimised ASM	*/
#define	EXIT_VALUE	0		/* Valeur de retour		*/
#define	INTEL				/* Intel Microprocessors	*/
#define	IDIRECT				/* Indirect word storage	*/
#define	OS_ID		257		/* Operating Systeme id Code	*/
#define ABALBIG				/* Use Explicite FAR pointers 	*/
#define	MOINS_UN       0xFFFF		/* System Error return value	*/
#define	PROTEGE_286			/* Protected mode memory	*/
#define	OPTIONFLAG	'/'		/* Executeur Option indicator	*/
#define	O_SYNC		0		/* Declarationo O_SYNC		*/
#define	BUF_CICO			/* Bufferised CICO for MSDOS	*/
#else
#ifdef	WIN32
#define	ABALLAN				/* DOS Local Area Networking	*/
#define	PRL_SF				/* Amenesik / Sologic File Syteme Calls	*/
#define	EXIT_VALUE	0		/* Valeur de retour		*/
#define	INTEL				/* Intel Microprocessors	*/
#define	IDIRECT				/* Indirect word storage	*/
#define	OS_ID		258		/* Operating Systeme id Code	*/
#define	MOINS_UN       0xFFFF		/* System Error return value	*/
#define	LINEAR_MEM			/* Protected mode memory	*/
#define	OPTIONFLAG	'/'		/* Executeur Option indicator	*/
#define	O_SYNC		0		/* Declarationo O_SYNC		*/
#define	BUF_CICO			/* Bufferised CICO for MSDOS	*/
#else
#define	ABALLAN				/* DOS Local Area Networking	*/
#define	PRL_SF				/* Amenesik / Sologic File Syteme Calls	*/
#define	INTELASM1			/* 1st Level Optimised ASM	*/
#define	EXIT_VALUE	0		/* Valeur de retour		*/
#define	INTEL				/* Intel Microprocessors	*/
#define	IDIRECT				/* Indirect word storage	*/
#define	OS_ID		1		/* Operating Systeme id Code	*/
#define ABALBIG				/* Use Explicite FAR pointers 	*/
#define	MOINS_UN       0xFFFF		/* System Error return value	*/
#define	PROTEGE_286			/* Protected mode memory	*/
#define	OPTIONFLAG	'/'		/* Executeur Option indicator	*/
#define	O_SYNC		0		/* Declarationo O_SYNC		*/
#define	BUF_CICO			/* Bufferised CICO for MSDOS	*/
#endif	/* WIN32 */
#endif	/* WIN16 */
#endif 	/* DOS   */

/*	Parametres de Generation : SPIX DPS2000		*/
/*	---------------------------------------		*/

#ifdef	SPIX
#define	EXIT_VALUE	0		/* Valeur de retour		*/
#define	DUMBCC				/* Compiler error (*ptr %= x)	*/
#define	MOTOROLA			/* Motorola microprocesseur	*/
#define	UNIX				/* UNIX based OS		*/
#define	LINEAR_MEM			/* Linear memory adressing	*/
#define	OS_ID		2		/* SPIX Version			*/
#define	MOINS_UN	0xFFFF		/* Negatives OK			*/
#define	OPTIONFLAG	'-'		/* Executeur Option indicator	*/
#endif	/* SPIX */

/*	Parametres de Generation : SUPER TEAM (Spixish) */
/*	----------------------------------------------- */

#ifdef	SUPERTEAM
#define	EXIT_VALUE	0		/* Valeur de retour		*/
#define	DUMBCC				/* Compiler error (*ptr %= x)	*/
#define	MOTOROLA			/* Motorola microprocesseur	*/
#define	UNIX				/* UNIX based OS		*/
#define	LINEAR_MEM			/* Linear memory adressing	*/
#define	OS_ID		11		/* SUPERTEAM Version		*/
#define	MOINS_UN	0xFFFF		/* Negatives OK			*/
#define	OPTIONFLAG	'-'		/* Executeur Option indicator	*/
#endif	/* SUPERTEAM */

/*	Parametres de Generation : AIX IBM 6150		*/
/*	---------------------------------------		*/

#ifdef  RT_AIX
#define	EXIT_VALUE	0		/* Valeur de retour		*/
#define	RISC				/* Reduced instruction set	*/
#define	EVENBOUND			/* No Byte acces for words	*/
#define	UNIX				/* UNIX based OS		*/
#define	LINEAR_MEM			/* Linear memory adressing	*/
#define	OS_ID		3		/* Operating Systeme id Code	*/
#define	MOINS_UN	0xFFFF		/* Problematic negative values	*/
#define	OPTIONFLAG	'-'		/* Executeur Option indicator	*/
#endif	/* RT_AIX */

/*	Parametres de Generation : SUN SOLARIS SPARC
/*	--------------------------------------------  */
#ifdef SPARC
#define ABALSIGN
#define EXIT_VALUE 	0
#define RISC
#define EVENBOUND
#define UNIX
#define LINEAR_MEM
#define OS_ID		71
#define MOINS_UN   	0xFFFF
#define OPTIONFLAG	'-'
#endif

/*	Parametres de Generation : AIX IBM PS/2		*/
/*	---------------------------------------		*/

#ifdef  PS_AIX
#define	EXIT_VALUE	0		/* Valeur de retour		*/
#define	IDIRECT				/* Reduced instruction set	*/
#define	UNIX				/* UNIX based OS		*/
#define	LINEAR_MEM			/* Linear memory adressing	*/
#define	OS_ID		3		/* Operating Systeme id Code	*/
#define	MOINS_UN	0xFFFF		/* Problematic negative values	*/
#define	OPTIONFLAG	'-'		/* Executeur Option indicator	*/
#endif	/* PS_AIX */

/*	Parametres de Generation : HEWLETT PACKARD HP9000 etc	*/
/*	-----------------------------------------------------	*/
/*	Unix Systeme V : Mixture AT/T and BSD			*/
/*	Machine        : Achitecture RISC Hewlet Packard	*/
/*								*/

#ifdef HP9000
#define	EXIT_VALUE	0		/* Valeur de retour		*/
#define	RISC				/* Reduced instruction set	*/
#define	EVENBOUND			/* No Byte acces for words	*/
#define	UNIX				/* UNIX based OS		*/
#define	LINEAR_MEM			/* Linear memory adressing	*/
#define	OS_ID		10		/* Operating Systeme id Code	*/
#define	MOINS_UN	0xFFFF		/* Problematic negative values	*/
#define	OPTIONFLAG	'-'		/* Executeur Option indicator	*/
#endif	/* HP9000 */

/*	Parametres de Generation : GENIX FORUM		*/
/*	--------------------------------------		*/

#ifdef	GENIX
#define	EXIT_VALUE	0		/* Valeur de retour		*/
#define	DUMBCC				/* Compiler error (*ptr %= x)	*/
#define	IDIRECT				/* Indirect Word Storage	*/
#define	NSC32000			/* Motorola microprocesseur	*/
#define	UNIX				/* UNIX based OS		*/
#define	LINEAR_MEM			/* Linear memory adressing	*/
#define	OS_ID		4		/* SPIX Version			*/
#define	MOINS_UN	0xFFFF		/* Negatives OK			*/
#define	OPTIONFLAG	'-'		/* Executeur Option indicator	*/
#endif	/* GENIX */

/*	Parametres de Generation : SIEMENS		*/
/*	----------------------------------		*/

#ifdef	SIEMENS
#define	EXIT_VALUE	0		/* Valeur de retour		*/
#define	IDIRECT				/* Indirect Word Storage	*/
#define	NSC32000			/* Motorola microprocesseur	*/
#define	UNIX				/* UNIX based OS		*/
#define	LINEAR_MEM			/* Linear memory adressing	*/
#define	OS_ID		4		/* SPIX Version			*/
#define	MOINS_UN	0xFFFF		/* Negatives OK			*/
#define	OPTIONFLAG	'-'		/* Executeur Option indicator	*/
#endif	/* SIEMENS */

/*	Parametres de Generation : LSX OLIVETTI		*/
/*	---------------------------------------		*/

#ifdef	LSX
#define	EXIT_VALUE	0		/* Valeur de retour		*/
#define	UNIX				/* Unix Based OS		*/
#define	LINEAR_MEM			/* Linear memory adressing	*/
#define	OS_ID		5		/* Identity of OS		*/
#define	MOINS_UN	0xFFFF		/* Signed values OK		*/
#define	OPTIONFLAG	'-'		/* Executeur Option indicator	*/
#endif	/* LSX */

#ifdef	ALTOS
#define LOCKFBUG			/* Lockf Bug needs O_RDWR	*/
#define	EXIT_VALUE	0		/* Valeur de retour		*/
#define	UNIX				/* Unix Based OS		*/
#define	IDIRECT				/* InDirect Word Storage	*/
#define	PROTEGE_286			/* Protected memory mode	*/ 
#define	OS_ID		7		/* Identity of OS		*/
#define	MOINS_UN	0xFFFF		/* Signed values OK		*/
#define	OPTIONFLAG	'-'		/* Executeur Option indicator	*/
#define	O_SYNC		020		/* Option Copie / Securite	*/
#endif	/* ALTOS */

/*	Parametres de Generation : VMS VAX DIGITAL	*/
/*	------------------------------------------	*/

#ifdef VMS
#include <stsdef>
#define	EXIT_VALUE	STS$M_INHIB_MSG	/* Valeur de retour		*/
#define	OS_ID		6		/* Identity of the OS		*/
#define	IDIRECT				/* Indirect word storage	*/
#define	LINEAR_MEM			/* Linear memory adressing	*/
#define	MOINS_UN	0xFFFF		/* Problematic negative values	*/
#define	BUF_CICO			/* Bufferised Console I/O	*/
#define	OPTIONFLAG	'/'		/* Executeur Option indicator	*/

/* Redefinition of Direct acces file functions */
/* ------------------------------------------- */
#define	Access(Xarg1,Xarg2,Xarg3)	Maccess(Xarg1,Xarg2,Xarg3)
#define	open(Xarg1,Xarg2)		Mopen(Xarg1,Xarg2)
#define	creat(Xarg1,Xarg2)		Mcreat(Xarg1,Xarg2)
#define	close(Xarg1)			Mclose(Xarg1)
#define	read(Xarg1,Xarg2,Xarg3)		Mread(Xarg1,Xarg2,Xarg3)
#define	write(Xarg1,Xarg2,Xarg3)	Mwrite(Xarg1,Xarg2,Xarg3)
#define	lseek(Xarg1,Xarg2,Xarg3)	Mlseek(Xarg1,Xarg2,Xarg3)

#define STARTLOG '['			/* Debut Chemin Logique	*/
#define STOPLOG  ']'			/* Fin Chemin Logique 	*/
#define	ABALSPOOL			/* VMS uses CICO Spool	*/
#define	ABALPS
#endif	/* VMS */

/*	Parametres de Generation : ULTRIX VAX or DEC DIGITAL	*/
/*	----------------------------------------------------	*/

#ifdef VAX_ULTRIX
#define	UNIX				/* Unix Type OS			*/
#define	EXIT_VALUE	0		/* Valeur de retour		*/
#define	OS_ID		66		/* Identity of the OS		*/
#define	IDIRECT				/* Indirect word storage	*/
#define	LINEAR_MEM			/* Linear memory adressing	*/
#define	MOINS_UN	0xFFFF		/* Problematic negative values	*/
#define	OPTIONFLAG	'-'		/* Executeur Option indicator	*/
#endif	/* VAX_ULTRIX */

#ifdef DEC_ULTRIX
#define	UNIX				/* Unix Type OS			*/
#define	EXIT_VALUE	0		/* Valeur de retour		*/
#define	OS_ID		67		/* Identity of the OS		*/
#define	IDIRECT				/* Indirect word storage	*/
#define	EVENBOUND			/* Memory alignement required	*/
#define	RISC				/* Architecture RISC		*/
#define	LINEAR_MEM			/* Linear memory adressing	*/
#define	MOINS_UN	0xFFFF		/* Problematic negative values	*/
#define	OPTIONFLAG	'-'		/* Executeur Option indicator	*/
#endif	/* DEC_ULTRIX */

#ifdef PRIME_RISC
#define ABALSIGN			/* Problem with signed bytes	*/
#define	UNIX				/* Unix Type OS			*/
#define	EXIT_VALUE	0		/* Valeur de retour		*/
#define	OS_ID		67		/* Identity of the OS		*/
#define	IDIRECT				/* Indirect word storage	*/
#define	EVENBOUND			/* Memory alignement required	*/
#define	RISC				/* Architecture RISC		*/
#define	LINEAR_MEM			/* Linear memory adressing	*/
#define	MOINS_UN	0xFFFF		/* Problematic negative values	*/
#define	OPTIONFLAG	'-'		/* Executeur Option indicator	*/
#endif	/* PRIME_RISC */

/*	Parametres de Generation : XENIX 386		*/
/*	------------------------------------		*/

#ifdef	XENIX386
#define LOCKFBUG			/* Lockf Bug needs O_RDWR	*/
#define	EXIT_VALUE	0		/* Valeur de retour		*/
#define	IDIRECT				/* Indirect Word Storage	*/
#define	UNIX				/* UNIX based OS		*/
#define	LINEAR_MEM			/* Linear memory adressing	*/
#define	OS_ID		4		/* SPIX Version			*/
#define	MOINS_UN	0xFFFF		/* Negatives OK			*/
#define	OPTIONFLAG	'-'		/* Executeur Option indicator	*/
#endif	/* XENIX386 */

/*	Parametres de Generation : InterActive IX 386	*/
/*	---------------------------------------------	*/

#ifdef	IX386
#define	EXIT_VALUE	0		/* Valeur de retour		*/
#define	IDIRECT				/* Indirect Word Storage	*/
#define	UNIX				/* UNIX based OS		*/
#define	LINEAR_MEM			/* Linear memory adressing	*/
#define	OS_ID		4		/* SPIX Version			*/
#define	MOINS_UN	0xFFFF		/* Negatives OK			*/
#define	OPTIONFLAG	'-'		/* Executeur Option indicator	*/
#endif	/* IX386 */

/*	Parametres de Generation : UNISYS386		*/
/*	------------------------------------		*/

#ifdef	UNISYS  
#define LOCKFBUG			/* Lockf Bug needs O_RDWR	*/
#define	EXIT_VALUE	0		/* Valeur de retour		*/
#define	IDIRECT				/* Indirect Word Storage	*/
#define	UNIX				/* UNIX based OS		*/
#define	LINEAR_MEM			/* Linear memory adressing	*/
#define	OS_ID		4		/* SPIX Version			*/
#define	MOINS_UN	0xFFFF		/* Negatives OK			*/
#define	OPTIONFLAG	'-'		/* Executeur Option indicator	*/

#endif	/* UNISYS   */

/*	Parametres de Generation : AVIION PENTIUM(DATA GENERAL)         */
/*	-----------------------------------------Compilateur GNU        */

#ifdef	AVIION  
#define LOCKFBUG			/* Lockf Bug needs O_RDWR	*/
#define	EXIT_VALUE	0		/* Valeur de retour		*/
#define	IDIRECT				/* Indirect Word Storage	*/
#define	UNIX				/* UNIX based OS		*/
#define	LINEAR_MEM			/* Linear memory adressing	*/
#define	OS_ID		4		/* SPIX Version			*/
#define	MOINS_UN	0xFFFF		/* Negatives OK			*/
#define	OPTIONFLAG	'-'		/* Executeur Option indicator	*/

#endif	/* UNISYS   */

/*	Parametres du NCR Tower		*/
/*	-----------------------		*/
#ifdef	NCR
#define	EXIT_VALUE	0		/* Valeur de retour		*/
#define	DUMBCC				/* Compiler error (*ptr %= x)	*/
#define	MOTOROLA			/* Motorola microprocesseur	*/
#define	UNIX				/* UNIX based OS		*/
#define	LINEAR_MEM			/* Linear memory adressing	*/
#define	OS_ID		8		/* NCR Tower Version		*/
#define	MOINS_UN	0xFFFF		/* Negatives Problem short word	*/
#define	OPTIONFLAG	'-'		/* Executeur Option indicator	*/
#endif	/* NCR  */

/*	Parametres du NIXDORF TARGON	*/
/*	----------------------------	*/
#ifdef	NIXDORF
#define	EXIT_VALUE	0		/* Valeur de retour		*/
#define	MOTOROLA			/* Motorola microprocesseur	*/
#define	UNIX				/* UNIX based OS		*/
#define	LINEAR_MEM			/* Linear memory adressing	*/
#define	OS_ID		8		/* NCR Tower Version		*/
#define	MOINS_UN	0xFFFF		/* Negatives Problem short word	*/
#define	OPTIONFLAG	'-'		/* Executeur Option indicator	*/
#endif	/* NIXDORF */

/*	Parametres de PHILLIPS P9050	*/
/*	----------------------------	*/
#ifdef	P9050
#define	EXIT_VALUE	0		/* Valeur de retour		*/
#define	MOTOROLA			/* Motorola microprocesseur	*/
#define	UNIX				/* UNIX based OS		*/
#define	LINEAR_MEM			/* Linear memory adressing	*/
#define	OS_ID		8		/* NCR Tower Version		*/
#define	MOINS_UN	0xFFFF		/* Negatives Problem short word	*/
#define	OPTIONFLAG	'-'		/* Executeur Option indicator	*/
#endif	/* P9050 */

/*	ESTABLISH SYSTEM MODEL TYPE	*/
/*	---------------------------	*/
#ifdef	UNIX				/* If Unix has been selected	*/

#ifdef	ABAL21				/* If Version 2.1		*/
#define	ABAL14				/* Include all of ABAL V 1.4	*/
#endif

#ifdef  ABAL14				/* If Version 1.4		*/
#define ABAL13				/* Include all of ABAL V 1.3	*/
#define ABALPS				/* Activate USER librarys	*/
#endif  /* ABAL14 */

#ifdef  ABAL13				/* If Version 1.3		*/
#define ABAL12				/* Include all of ABAL V 1.2	*/
#define ABALMC				/* Activate MC			*/
#define ABALBD				/* and BD access methods	*/
#endif  /* ABAL13 */

#ifdef  ABAL12
#define ABAL11				/* Include all of ABAL V 1.1	*/
#define ABALMSG				/* Activate IPC Messagerie	*/
#define	COEXA				/* Ensure ACCESS model		*/
#define BUF_CICO			/* Ensure CICO bufferised	*/
#define	ABALSPOOL			/* Activate SPOOL handling	*/
#endif  /* ABAL12 */

#endif	/* UNIX   */

/*	PROLOGUE and DOS		*/
/*	----------------		*/
#ifndef UNIX
#ifndef VMS				/* ---------------------------- */
#ifdef	ABAL21
#define	ABAL14				/* Inclusion of Version 1.4	*/
#endif
#define	ABALMC				/* MC BD PS always for PRL/DOS	*/
#define ABALBD				/* ---------------------------- */
#define ABALPS
#endif /* !VMS  */
#endif /* !UNIX */

#endif	/* ! EXOSH */

