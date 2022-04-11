/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1992 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXWORK.H  				*/
/*		Date 	:	12/11/1992				*/
/*		Version :	1.4c / 2.1a				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXDNGF_C
#define	_EXDNGF_C

/*	----------------------------		*/
/*	Variables du Gestion du S.I.		*/
/*	----------------------------		*/

BPTR 		si_cle;
BPTR		si_buf;
int		si_lng;
int		si_flg;
int		si_ver;
EXAWORD		si_mq;
EXAWORD		simcbd;

#ifdef	DOS
EXABYTE		simcode[16] = {
		0x32, 0x22, 0x2E, 0x36, 0x26, 0x60, 0xA0, 0xA2,
		0xA6, 0x2A, 0x62, 0x6A, 0x72, 0x1E, 0x00, 0x00
		};
#else
EXABYTE		simcode[16];
#endif

/*	--------------------------------	*/
/*	Gestion des fichiers en general	*/
/*	--------------------------------	*/

EX_FILE_HANDLE	fidreel = EX_UNUSED_HANDLE;	/* #BG 29/03/12 Initialisation pas indispensable */
EXAWORD		fidperm;
EXAWORD		fidbd;
#ifdef AIX_VERS
#ifdef SPARC
EXAWORD		fidmc1;
#else
EXAWORD		fidmc;
#endif
#else /* AIX_VERS */
EXAWORD		fidmc;		// fidmc & 0x00FF = Nombre de rubriques ds le buffer MC
#endif /* AIX_VERS */
EXAWORD		fidblen;
EXAWORD		fidinfo1;
EXAWORD		fidinfo2;
BPTR 		fidbuff;
BPTR		fidbase;
/* #BG 06/02/12 ABALSQL */
BPTR		fidurl; 
BPTR		fidserv;
BPTR		fidhost;
BPTR		fidport;
BPTR		fidname;
BPTR		fidoption;
PSQL_STATMENT	fidstmtlst;

#ifdef	ABAL_LONG_NAMES
EXABYTE	bSystemLongNames;
EXABYTE	bUserLongNames;
#endif

#ifdef	ABAL_LAN
VPTR		fidnetwork;
#endif

EXAWORD		lfh;
EX_FILE_HANDLE	dbreel;

#ifdef	PRL_SF
LSEEKTYPE	fidseek;
#else
#ifdef	ABAL_CRITERIA
LSEEKTYPE	fidseek;
#endif
#endif

/*	---------------------------------------		*/
/*	Variables de la Gestion du Multicritere		*/
/*	---------------------------------------		*/

BPTR 		rubr_base;
EXAWORD		rubr_max;
EXABYTE		joinwork[18];

	/* --------- */
#endif	/* _EXDNGF_C */
	/* --------- */
