/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1997 Amenesik / Sologic  		*/
/*									*/
/*		Module  :	EXOS  - H				*/
/*		Version :	1.4c / 2.1e / 3.1c 			*/
/*		Date 	:	14/0/9/2005				*/
/*									*/
/*----------------------------------------------------------------------*/
/*	11/01/2007							*/
/*	----------							*/
/*	3.2a.0.22	: AltGr in Pixel Event Handler allows national	*/
/*			  character alt map composition			*/
/*----------------------------------------------------------------------*/

#ifndef	EXOSH		/* If not already included			*/
#define	EXOSH		/* Avoid multpile inclusions			*/

#define	FixedRegisters	/* Executeur Model Statique	#regs = 64	*/

#ifdef	ABAL4
#ifndef VERSION666
#define	VERSION666
#endif
#define	ABAL_REMOTE
#ifndef	ABAL32A
#define	ABAL32A
#endif
#ifndef	_ABAL_CALLBACK
#define	_ABAL_CALLBACK
#endif
#endif
#ifdef	VERSION666
#ifdef	ABAL32A
#ifndef	_ABAL_CALLBACK
#define	_ABAL_CALLBACK	/* Allows callback of abal procedures from bda	*/ 
#endif
#else
#undef	_ABAL_CALLBACK
#endif
#else
#undef	_ABAL_CALLBACK
#endif
#define	ABAL_LONG_NAMES	/* Allow use of long names in criteria question */
#define	MOINS_UN_SHORT 0x0000FFFFL
#ifdef	VERSION666
#ifdef	ABAL64
#define	MOINS_UN16 0xFFFFFFFFFFFFFFFFL
#define	MOINS_UN32 0xFFFFFFFFFFFFFFFFL
#define	MOINS_UN64 0xFFFFFFFFFFFFFFFFL
#define	MOINS_UN_HEX MinusOne   
#else
#define	MOINS_UN16 0xFFFFFFFFL
#define	MOINS_UN32 0xFFFFFFFFL
#define	MOINS_UN_HEX MinusOne   
#endif
#else
#define	MOINS_UN_HEX 0xFFFF
#endif

#ifdef	_ABAL_CALLBACK
#undef	_ABAL_CALLBACK
#endif

#define	_ABAL_CALLBACK	1

/*			--- A T T E N T I O N ---			*/
/*									*/
/*	Modification de ce fichier peut avoir des effets de bords	*/
/*	qui concernes tous les executeurs et bien cachees		*/
/*									*/
/*	DOS, SPIX, GENIX, AIX, LSX, VMS		*/
/*	NCR, UNISYS, XENIX, XENIXIX, SUPERTEAM , HP9000	, ULTRIX	*/
/*	(NIXDORF) (ICL) (GOUPIL)					*/
/*	-----------------------------------------------------		*/

#define MODULE_COPYRIGHT    "\r\n   Copyright (c) 2021 Amenesik / Sologic"
#ifdef 	ABAL64
	#define	ABAL_Version	'5'		/* Version Major		*/
	#define	ABAL_Index	'1'		/* Version Minor		*/
	#define	ABAL_Release	'b'		/* Version Level		*/
	#define	ABAL_ProvOne	'0'		/* 				*/
	#define	ABAL_ProvTwo	'0'		/* Version Prov			*/
	#define	ABAL_ProvThree	'1'		/* Version Prov			*/
#else
#ifdef	ABAL41
	#define	ABAL_Version	'4'		/* Version Major */
	#define	ABAL_Index		'1'		/* Version Minor */
	#define	ABAL_Release	'8'		/* Version Level */
	#define	ABAL_Prov		' '		/* Version finale X.Y.Z */
//	#define	ABAL_Prov		'2'		/* Version prov 4.1.5~2 du 16/08/18: Correction TIMER avec evt souris */
//	#define	ABAL_Prov		'3'		/* Version prov 4.1.5~3 du 22/01/19: Ajout log systeme erreur 1 (EXER_DEVFAIL) */
//	#define	ABAL_Prov		'4'		/* Version prov 4.1.5~4 du 31/01/19: Ajout DATE(22), DATE(23) DATE(24) */
//	#define	ABAL_Prov		'5'		/* Version prov 4.1.5~5 du 26/02/19: Ajout trace sur ASSIGN (prltrace.ini) */
//	#define	ABAL_Prov		'5'		/* Version prov 4.1.5~5 (bis) du 25/04/19: Trace par PID exa32 (prltrace.ini) */
//	#define	ABAL_Prov		'6'		/* Version prov 4.1.5~6 du 03/05/19: ASSIGN accepte les blancs ds les noms de fichiers (risque) */
//	#define	ABAL_Prov		'7'		/* Version prov 4.1.5~7 du 10/05/19: Ajout trace sur ASSIGN (ExaSysLog) si numero logique deja utilise */
//	#define	ABAL_Prov		'1'		/* Version prov 4.1.6~2 du 24/05/19: Support 16 couleurs de fond en CiCo (texte) */
//	#define	ABAL_Prov		'2'		/* Version prov 4.1.6~2 du 17/06/19: Revision DATE(8/20/21/22) et suppression DATE(23/24) */
//	#define	ABAL_Prov		'3'		/* Version prov 4.1.6~3 du 23/07/19: Correction 100% cpu sur ASK avec debranchement sur timer + VE ERROR74=0 */
//	#define	ABAL_Prov		'4'		/* Version prov 4.1.6~4 du 04/10/19: Revision KEY automatiques et DATE(22) */
//	#define	ABAL_Prov		'5'		/* Version prov 4.1.6~5 du 16/10/19: Logs pouvant saturer /var conditionnés par la VE EXASYSLOG */
//	#define	ABAL_Prov		'6'		/* Version prov 4.1.6~6 du 23/10/19: Correction ABAL SQL CONNECT + Ajout Console et User ds les logs */
//	#define	ABAL_Prov		'7'		/* Version prov 4.1.6~7 du 05/11/19: exadb32: Nouveaux raccourci clavier pour TWeb ds Chrome: CTRL W = CTRL T */
//	#define	ABAL_Prov		'8'		/* Version prov 4.1.6~8 du 13/11/19: Synatxe KEY N et L pour les entiers longs ABAL */
//	Version PROD 4.1.6   du 19/12/19: Paquet 4.2.6~4 du 20/12/19
//	#define	ABAL_Prov		'9'		/* Version prov 4.1.6~9 du 28/02/20: Logs via la VE EXASYSLOG cibles (cf exasyslog.h) */
//	#define	ABAL_Prov		'9'		/* Version prov 4.1.6~9 du 16/06/20: Correction fct abqt() cf conso CPU si ASK + ON TIMER */
//	#define	ABAL_Prov		'1'		/* Version prov 4.1.7~1 du 27/04/20: Gestion clavier virtuel par EVENT() V1 */
//	#define	ABAL_Prov		'2'		/* Version prov 4.1.7~2 du 18/08/20: Gestion clavier virtuel par EVENT() V2 */
//	#define	ABAL_Prov		'3'		/* Version prov 4.1.7~3 du 10/12/20: Correction blocage CPU 100% sur POSIT invalide (LIKE ''a'). Err 93 remontee */
//	#define	ABAL_Prov		'4'		/* Version prov 4.1.7~4 du 15/12/20: Correction position curseur en fin de texte si masque 32768+256 */
//	#define	ABAL_Prov		'5'		/* Version prov 4.1.7~5 du 21/12/20: Gestion molette souris texte et graphique */
//	Version PROD 4.1.8   du 29/12/20: Paquet 4.2.7~1 du 29/12/20
#else
	#define	ABAL_Version	'?'		/* Version Major */
	#define	ABAL_Index		'?'		/* Version Minor */
	#define	ABAL_Release	'?'		/* Version Level */
	#define	ABAL_Prov		' '		/* Version Prov */
#endif

#endif
#define _EXA_TRACE_ALLOC		/* allows -A for alloc/lib trace */


#define MSG_ID_EXA   "*STX*3EXA     41800"
#define MSG_ID_EXADB "*STX*3EXADB   41800"

#define	ABAL31
#ifndef ABAL21
#define	ABAL21
#endif
#define	ABAL14
#define	ABAL13
#define	ABAL12
#define	ABAL11


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


#ifdef	USEIT
#undef	MMAP_OPTIMISED			/* mmap optimisation		*/
#define	EXIT_VALUE	0		/* Valeur de retour		*/
#define	IDIRECT				/* Indirect Word Storage	*/
#ifndef	UNIX
#define	UNIX				/* UNIX based OS		*/
#endif
#define	ABAL_CRITERIA			/* Uses Criteria		*/
#define	C_ISAM_410			/* Compatible C/ISAM 4.10	*/
#define	AIX_VERS			/* What the fuck does this do	*/
#define	LINUX_MNEMONICS			/* Activates the mnemonics 	*/
					/* conversion mechanisms for 	*/
					/* ALL ASSIGNED files		*/
#ifndef	LINUX
#define	LINUX				/* LINUX based OS		*/
#endif
#define	IX386				/* Unix PC like IX 386		*/
#define	LINEAR_MEM			/* Linear memory adressing	*/
#define	OS_ID		100		/* USEIT Version			*/
#define	MOINS_UN	MOINS_UN_HEX		/* Negatives OK			*/
#define	OPTIONFLAG	'-'		/* Executeur Option indicator	*/
#define LONG_FILE_HANDLES		/* File handles 32 bits		*/
#endif	/* USEIT */

#ifdef	AIX
/* AIX 5.2 : GFI portage Abal 3 */
#define	IDIRECT    			/* No Byte acces for words	*/
#define ABALSIGN
#define	HPUX				/* UNIX based OS		*/
#endif	/* AIX */

#ifdef	HPUX
/* special case intel evenbound bigendian !!!! */
#define	MSG_HX	
#define	EVENBOUND			/* No Byte acces for words	*/
#define	UNIX				/* UNIX based OS		*/
#define	ABAL_CRITERIA			/* Uses Criteria		*/
#define	C_ISAM_410			/* Compatible C/ISAM 4.10	*/
#define	AIX_VERS			/* What the fuck does this do	*/
#define	LINUX_MNEMONICS			/* Activates the mnemonics 	*/
#define	EXIT_VALUE	0		/* Valeur de retour		*/
#define	OPTIONFLAG	'-'		/* Executeur Option indicator	*/
#define LONG_FILE_HANDLES		/* File handles 32 bits		*/
#define	LINEAR_MEM			/* Linear memory adressing	*/
#define	OS_ID		400		/* USEIT Version		*/
#define	MOINS_UN	MOINS_UN_HEX	/* Negatives OK			*/
#define	OPTIONFLAG	'-'		/* Executeur Option indicator	*/
#define LONG_FILE_HANDLES		/* File handles 32 bits		*/
#endif	/* HPUX */

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
#define	MOINS_UN       MOINS_UN_HEX		/* System Error return value	*/
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
#define	MOINS_UN       MOINS_UN_HEX		/* System Error return value	*/
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
#define	MOINS_UN       MOINS_UN_HEX		/* System Error return value	*/
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
#define	MOINS_UN	MOINS_UN_HEX		/* Negatives OK			*/
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
#define	MOINS_UN	MOINS_UN_HEX		/* Negatives OK			*/
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
#define	MOINS_UN	MOINS_UN_HEX		/* Problematic negative values	*/
#define	OPTIONFLAG	'-'		/* Executeur Option indicator	*/
#endif	/* RT_AIX */

#ifdef AIX_VERS
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
#define MOINS_UN   	MOINS_UN_HEX
#define OPTIONFLAG	'-'
#endif

#endif /* AIX_VERS */

/*	Parametres de Generation : AIX IBM PS/2		*/
/*	---------------------------------------		*/

#ifdef  PS_AIX
#define	EXIT_VALUE	0		/* Valeur de retour		*/
#define	IDIRECT				/* Reduced instruction set	*/
#define	UNIX				/* UNIX based OS		*/
#define	LINEAR_MEM			/* Linear memory adressing	*/
#define	OS_ID		3		/* Operating Systeme id Code	*/
#define	MOINS_UN	MOINS_UN_HEX		/* Problematic negative values	*/
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
#define	MOINS_UN	MOINS_UN_HEX		/* Problematic negative values	*/
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
#define	MOINS_UN	MOINS_UN_HEX		/* Negatives OK			*/
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
#define	MOINS_UN	MOINS_UN_HEX		/* Negatives OK			*/
#define	OPTIONFLAG	'-'		/* Executeur Option indicator	*/
#endif	/* SIEMENS */

/*	Parametres de Generation : LSX OLIVETTI		*/
/*	---------------------------------------		*/

#ifdef	LSX
#define	EXIT_VALUE	0		/* Valeur de retour		*/
#define	UNIX				/* Unix Based OS		*/
#define	LINEAR_MEM			/* Linear memory adressing	*/
#define	OS_ID		5		/* Identity of OS		*/
#define	MOINS_UN	MOINS_UN_HEX		/* Signed values OK		*/
#define	OPTIONFLAG	'-'		/* Executeur Option indicator	*/
#endif	/* LSX */

#ifdef	ALTOS
#define LOCKFBUG			/* Lockf Bug needs O_RDWR	*/
#define	EXIT_VALUE	0		/* Valeur de retour		*/
#define	UNIX				/* Unix Based OS		*/
#define	IDIRECT				/* InDirect Word Storage	*/
#define	PROTEGE_286			/* Protected memory mode	*/ 
#define	OS_ID		7		/* Identity of OS		*/
#define	MOINS_UN	MOINS_UN_HEX		/* Signed values OK		*/
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
#define	MOINS_UN	MOINS_UN_HEX		/* Problematic negative values	*/
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
#define	MOINS_UN	MOINS_UN_HEX		/* Problematic negative values	*/
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
#define	MOINS_UN	MOINS_UN_HEX		/* Problematic negative values	*/
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
#define	MOINS_UN	MOINS_UN_HEX		/* Problematic negative values	*/
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
#define	MOINS_UN	MOINS_UN_HEX		/* Negatives OK			*/
#define	OPTIONFLAG	'-'		/* Executeur Option indicator	*/
#define LONG_FILE_HANDLES		/* File handles 32 bits		*/
#endif	/* XENIX386 */

/*	Parametres de Generation : InterActive IX 386	*/
/*	---------------------------------------------	*/

#ifdef	IX386
#ifndef	LINUX
#define	EXIT_VALUE	0		/* Valeur de retour		*/
#define	IDIRECT				/* Indirect Word Storage	*/
#define	UNIX				/* UNIX based OS		*/
#define	LINEAR_MEM			/* Linear memory adressing	*/
#define	OS_ID		4		/* SYSTEM Version		*/
#define	MOINS_UN	MOINS_UN_HEX	/* Negatives OK			*/
#define	OPTIONFLAG	'-'		/* Executeur Option indicator	*/
#define LONG_FILE_HANDLES		/* File handles 32 bits		*/
#endif
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
#define	MOINS_UN	MOINS_UN_HEX		/* Negatives OK			*/
#define	OPTIONFLAG	'-'		/* Executeur Option indicator	*/

#endif	/* UNISYS   */

#ifdef AIX_VERS

/*	Parametres de Generation : AVIION PENTIUM(DATA GENERAL)         */
/*	-----------------------------------------Compilateur GNU        */

#ifdef	AVIION  
#define LOCKFBUG			/* Lockf Bug needs O_RDWR	*/
#define	EXIT_VALUE	0		/* Valeur de retour		*/
#define	IDIRECT				/* Indirect Word Storage	*/
#define	UNIX				/* UNIX based OS		*/
#define	LINEAR_MEM			/* Linear memory adressing	*/
#define	OS_ID		4		/* SPIX Version			*/
#define	MOINS_UN	MOINS_UN_HEX		/* Negatives OK			*/
#define	OPTIONFLAG	'-'		/* Executeur Option indicator	*/
#endif	/* AVIION  */

#ifdef UNIXWARE
#define LOCKFBUG
#define EXIT_VALUE	0
#define IDIRECT
#define UNIX
#define LINEAR_MEM
#define OS_ID 		4
#define MOINS_UN	MOINS_UN_HEX
#define OPTIONFLAG	'-'
#endif	/* UNIXWARE */

#endif /* AIX_VERS */

/*	Parametres du NCR Tower		*/
/*	-----------------------		*/
#ifdef	NCR
#define	EXIT_VALUE	0		/* Valeur de retour		*/
#define	DUMBCC				/* Compiler error (*ptr %= x)	*/
#define	MOTOROLA			/* Motorola microprocesseur	*/
#define	UNIX				/* UNIX based OS		*/
#define	LINEAR_MEM			/* Linear memory adressing	*/
#define	OS_ID		8		/* NCR Tower Version		*/
#define	MOINS_UN	MOINS_UN_HEX		/* Negatives Problem short word	*/
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
#define	MOINS_UN	MOINS_UN_HEX		/* Negatives Problem short word	*/
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
#define	MOINS_UN	MOINS_UN_HEX		/* Negatives Problem short word	*/
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

