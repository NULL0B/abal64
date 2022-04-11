/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1992 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXFICH.H  				*/
/*		Version :	1.3c / 2.1a				*/
/*		Date 	:	04/08/1992				*/
/*									*/
/*----------------------------------------------------------------------*/

/*
 * 17/08/2000 : (#SP)long names support (WIN32 only) 
 */


#ifndef	_EXFICH_H		/* If not already included	*/
#define	_EXFICH_H		/* Avoid multiple inclusions	*/

/*	Gestion des Rubriques Multi-critere	*/
/*	-----------------------------------	*/

#define	  RUBNAME	0		/* Offset of Rubrique Name	*/
#define	  RUBLENG	16		/* Offset of rubrique length	*/
#define	  RUBTYPE	18		/* Offset of rubrique Type	*/
#define	  RUBSTAT	19		/* Rubrique management Ctrl	*/

#define   MAX_RUB_NAME_LEN_STD  16
#define   MAX_RUB_NAME_LEN_EXT  50

#define   RUB_DESC_LEN_STD  20
#define   RUB_DESC_LEN_EXT  54
#define   N_INTERNAL_RUBS   2

#define   RUB_POS_OFFSET_STD  (MAX_RUB_NAME_LEN_STD+2)
#define   RUB_POS_OFFSET_EXT  (MAX_RUB_NAME_LEN_EXT+2)

#define   RUB_LEN_OFFSET_STD  (MAX_RUB_NAME_LEN_STD)
#define   RUB_LEN_OFFSET_EXT  (MAX_RUB_NAME_LEN_EXT)

#define   RUB_TYPE_OFFSET_STD  (MAX_RUB_NAME_LEN_STD+2)
#define   RUB_TYPE_OFFSET_EXT  (MAX_RUB_NAME_LEN_EXT+2)

#define   RUB_CTRL_OFFSET_STD  (MAX_RUB_NAME_LEN_STD+3)
#define   RUB_CTRL_OFFSET_EXT  (MAX_RUB_NAME_LEN_EXT+3)

#define   MAX_TABLE_NAME_LEN_STD  8
#define   MAX_TABLE_NAME_LEN_EXT  30

#define   POSIT_DESC_LEN_STD  (MAX_RUB_NAME_LEN_STD+8)
#define   POSIT_DESC_LEN_EXT  (MAX_RUB_NAME_LEN_EXT+8)

#define   POSIT_DESC_SIZE_OFS_STD  (MAX_RUB_NAME_LEN_STD+5)
#define   POSIT_DESC_SIZE_OFS_EXT  (MAX_RUB_NAME_LEN_EXT+5)


#define   TABLE_NAME_OFS  3
#define   TABLE_DESC_LEN_STD  22
#define   TABLE_DESC_LEN_EXT  56

#define   LIST_RUB_FIRST_STD	0  
#define   LIST_RUB_FIRST_EXT	2
#define   LIST_RUB_NEXT_STD	1  
#define   LIST_RUB_NEXT_EXT	3

#define   JOIN_TOKEN_LEN_STD	(MAX_RUB_NAME_LEN_STD*2+1)
#define   JOIN_TOKEN_LEN_EXT	((1+MAX_RUB_NAME_LEN_EXT+MAX_TABLE_NAME_LEN_EXT)*2+1)

#define   JOIN_ANFC_DESC_LEN_STD	(17+1)
#define   JOIN_ANFC_DESC_LEN_EXT	(17+1)

#define   FIC_BUFFMC_LEN			540	// 27 rubriques en mode noms courts (27*20), 10 rubriques en mode noms longs (10*54)

/* #BG 08/03/12 */
#ifdef ABALSQL

/*	ABALSQL Statement descriptor structure */
/*	-------------------------------------- */

struct _SQL_STATMENT {
	EX_FILE_HANDLE	HdleStmt;
	EXAWORD			ffu;
	BPTR				Next;
};

typedef struct _SQL_STATMENT SQL_STATMENT;
typedef SQL_STATMENT* PSQL_STATMENT;
#endif

/*	File management descriptor structure	*/
/*	------------------------------------	*/

struct	fichdt {
	BPTR	url;	/* Pointeur vers l'URL complete ou le nom de fichier assigne */
					/* FREE for all file types	   */
					/* #BG 06/02/12 ABALSQL */

	BPTR	service;	/* Pointeur ds url vers le nom du service de methodes d'acces */
	BPTR	host;		/* Pointeur ds url vers le nom du host */
	BPTR	port;		/* Pointeur ds url vers le numero de port */
	BPTR	direcp;		/* Pointeur ds url vers le nom du fichier */
	BPTR	option;		/* Pointeur ds url vers les options liees au service */

	BPTR	asptr;			/* Pointeur suplementaire	   */
					/* NGF_IM : May be due to MALLOC   */
					/* NGF_MCX: May be due to Malloc (#BG 09/09/19 instead Never)   */
					/* NGF_BD : Allways due to MALLOC  */

	EX_FILE_HANDLE unlog;		/* Numero logique reel du fichier  */

	EXAWORD	permf;			/* Droits d'exploitation	   */

/*	FILE ASSIGN RIGHTS
 *	------------------
 *	
 *	Part 1 : as declared in Source 
 *	------------------------------
 *	7	6	5	4	3	2	1	0
 *-------------------------------------------------------------------------
 *
 *     Device / File Type     Dev/File  DF      C	EX	WR
 *
 *	Part 2 : Gestion interne
 *	------------------------
 *
 *	BIT
 *	---
 *	8	: File entry Valid and used
 *	9	: DIRECP needs FREE
 *	10	: ASPTR  needs FREE
 *	11	: BDEXT  needs FREE
 *
 *-------------------------------------------------------------------------
 */

	EXAWORD	aslen;			/* Valeur suplementaire		   */
							/* Allways usable length of ASPTR  */

	EXAWORD	dblog;			/* Data base linkage number	   */

	EXAWORD	mcext;			/* Multicritere Key counter	   */
					/* Or BD Record counter		   */

	BPTR	bdext;			/* Point to BD file semaphores	   */
					/* NGF_BD : Always due to MALLOC   */
#ifdef	PRL_SF
	EXALONG	LSeek;			/* LSeek Storage Value		   */
#endif	
	EXAWORD	enrdata;		/* Data Length of Enregistrement   */
	EXAWORD	enrcle;			/* Key Length			   */
#ifdef	ABAL_LAN
	VPTR	network_info;
#endif

#ifdef 	ABAL_LONG_NAMES
	EXABYTE  bUserLongNamesMode;
	EXABYTE  bSystemLongNamesMode;
#endif

#ifdef ABALSQL
	PSQL_STATMENT stmtlst;
#endif
};

#endif	/* _EXFICH_H */
	/* --------- */
