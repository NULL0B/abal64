/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1995
 *	Module  : EXA
 *	Fichier : EXMAUNIX.H
 *	Version : 1.1b
 *	Date    : 18/10/95
 *	Systeme : UNIX
 *
 *	Executeur ABAL
 *
 *	[Interface methodes d'acces - Definitions privees]
 *
 */

#ifndef __EXMAUNIX_H__
#define __EXMAUNIX_H__

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			QUELQUES DEFINITIONS				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#define NULL	0
extern	BYTE	simcode[16];


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*		PRIMITIVES D'ACCES FICHIERS (LINT_ARGS)			     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#ifdef LINT_ARGS

/* Internes */

void sf_init(void);


/* Typage des fonctions de l'API FLFILE */

extern int FFbegin(LPFLCONF , FARPROC);
extern int FFend(EHANDLE);
extern EHANDLE FFopen(BYTE FAR * , int , int , LPINT);
extern EHANDLE FFcreate(BYTE FAR * , int , int , LPINT);
extern int FFclose(EHANDLE);
extern int FFaccess(BYTE FAR * , int);
extern int FFunlink(BYTE FAR *);
extern int FFatbopen(EHANDLE , int , int);
extern int FFread(EHANDLE , LSEEKTYPE , void FAR * , int , LPINT);
extern int FFwrite(EHANDLE , LSEEKTYPE , void FAR * , int , LPINT);
extern int FFextend(EHANDLE , unsigned long );
extern int FFrename(EHANDLE , BYTE FAR *);
extern EHANDLE SQopen(BYTE FAR * , int , int , LPINT , LPINT);
extern EHANDLE SQcreate(BYTE FAR * , int , int , int , LPINT);
extern int SQclose(EHANDLE);
extern int SQunlink(BYTE FAR *);
extern int SQatbopen(EHANDLE , int , int);
extern int SQread(EHANDLE , void FAR * , int);
extern int SQwrite(EHANDLE , void FAR * , int);
extern int SQmodif(EHANDLE , void FAR * , int);
extern int SQrewind(EHANDLE);
extern int SQrename(EHANDLE , BYTE FAR *);
extern int FlfileModuleIdentification(BYTE FAR * , int);


/* Typage des fonctions de l'API Criteria */

extern int IsamBegin(CRTCONF FAR *,FARPROC);
extern int IsamEnd(HCRIT);
extern HCRIT IsamCreate(LPBYTE,LPINT,LPINT,int,int,int,int,LPINT);
extern HCRIT IsamOpen(LPBYTE,int,int,int,LPINT,LPINT,LPINT);
extern int IsamClose(HCRIT);
extern int IsamUnlink(LPBYTE);
extern int IsamRename(HCRIT,LPBYTE);
extern int IsamSearch(HCRIT,int,LPBYTE,LPINT,LPBYTE,int,LPINT);
extern int IsamUpDown(HCRIT,int,int,LPINT,LPBYTE,int,LPINT);
extern int IsamInsert(HCRIT,LPBYTE,int,LPBYTE,int);
extern int IsamDelete(HCRIT,LPBYTE,int);
extern int IsamModif(HCRIT,LPBYTE,int,LPBYTE,int);
extern int IsamReadZc(HCRIT,int,LPBYTE,int);
extern int IsamWriteZc(HCRIT,LPBYTE,int);
extern int IsamAtbOpen(HCRIT,int,int);
extern HCRIT McIsamCreate(LPBYTE,LPINT,LPINT,int,int,int,int,LPINT);
extern HCRIT McIsamOpen(LPBYTE,int,int,int,LPINT,LPINT,LPINT);
extern int McIsamClose(HCRIT);
extern int McIsamUnlink(LPBYTE);
extern int McIsamRename(HCRIT,LPBYTE);
extern int McIsamSearch(HCRIT,int,LPBYTE,LPINT,LPBYTE,int,LPINT);
extern int McIsamUpDown(HCRIT,int,int,LPINT,LPBYTE,int,LPINT);
extern int McIsamInsert(HCRIT,LPBYTE,int,LPBYTE,int);
extern int McIsamDelete(HCRIT,LPBYTE,int);
extern int McIsamModif(HCRIT,LPBYTE,int,LPBYTE,int);
extern int McIsamAtbOpen(HCRIT,int,int);
extern int McIsamCkey(HCRIT,LPBYTE,int,int);
extern int McIsamNkey(HCRIT,LPBYTE,LPBYTE);
extern int McIsamFkey(HCRIT,LPBYTE,LPBYTE,int,int,int);
extern int McIsamCndx(HCRIT,LPBYTE,int);
extern int McIsamDndx(HCRIT,LPBYTE,int);
extern int McIsamDCndx(HCRIT,LPBYTE,int);
extern int McIsamDDndx(HCRIT,LPBYTE,int);
extern int McIsamUpdndx(HCRIT);
extern int McIsamLkey(HCRIT,LPBYTE,int,int);
extern int McIsamLndx(HCRIT,LPBYTE,int,int);
extern int McIsamInfo(HCRIT,LPBYTE,int);
extern int McIsamCount(HCRIT,LPBYTE,int,int,int,LPLONG);
extern int McIsamPosit(HCRIT,LPBYTE,int,int,int,int,LPINT);
extern HCRIT BdIsamCreate(LPBYTE,int,int,LPINT);
extern HCRIT BdIsamOpen(LPBYTE,int,int,int,LPINT);
extern int BdIsamClose(HCRIT);
extern int BdIsamUnlink(LPBYTE);
extern int BdIsamRename(HCRIT,LPBYTE);
extern HCRIT BdIsamCreateFile(LPBYTE,HCRIT,LPINT,LPINT,int,int,int,int,LPINT);
extern HCRIT BdIsamOpenFile(LPBYTE,HCRIT,int,int,int,LPINT,LPINT,LPINT);
extern int BdIsamCloseFile(HCRIT);
extern int BdIsamUnlinkFile(LPBYTE,HCRIT,int);
extern int BdIsamRenameFile(HCRIT,LPBYTE);
extern int BdIsamAtbOpen(HCRIT,int,int);
extern int BdIsamCkey(HCRIT,LPBYTE,int,int);
extern int BdIsamNkey(HCRIT,LPBYTE,LPBYTE);
extern int BdIsamFkey(HCRIT,LPBYTE,LPBYTE,int,int,int);
extern int BdIsamDCndx(HCRIT,LPBYTE,int);
extern int BdIsamDDndx(HCRIT,LPBYTE,int);
extern int BdIsamCndx(HCRIT,LPBYTE,int);
extern int BdIsamDndx(HCRIT,LPBYTE,int);
extern int BdIsamJoin(HCRIT,LPBYTE,int);
extern int BdIsamCjoin(HCRIT,LPBYTE,int,int);
extern int BdIsamDjoin(HCRIT,LPBYTE);
extern int BdIsamRjoin(HCRIT,LPBYTE,int);
extern int BdIsamInfo(HCRIT,LPBYTE,int);
extern int BdIsamInfoFile(HCRIT,LPBYTE,int);
extern int BdIsamLfile(HCRIT,LPBYTE,int,int);
extern int BdIsamLjoin(HCRIT,LPBYTE,int,int);
extern int BdIsamLkey(HCRIT,LPBYTE,int,int);
extern int BdIsamLlink(HCRIT,LPBYTE,int,int);
extern int BdIsamSearch(HCRIT,int,LPBYTE,LPINT,LPBYTE,int,LPINT);
extern int BdIsamInsert(HCRIT,LPBYTE,int,LPBYTE,int);
extern int BdIsamModif(HCRIT,LPBYTE,int,LPBYTE,int);
extern int BdIsamDelete(HCRIT,LPBYTE,int);
extern int BdIsamCount(HCRIT,LPBYTE,int,int,int,LPLONG);
extern int BdIsamPosit(HCRIT,LPBYTE,int,int,int,int,LPINT);
extern int BdIsamUpdndx(HCRIT);
extern int BdIsamUpDown(HCRIT,int,int,LPINT,LPBYTE,int);
extern int BdIsamUpDownFile(HCRIT,int,int,LPINT,LPBYTE,int,LPINT);
extern int IsamModuleIdentification(BYTE FAR *, int);


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*		PRIMITIVES D'ACCES FICHIERS (sans LINT_ARGS)		     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#else /* LINT_ARGS */

/* Internes */

void sf_init();


/* Typage des fonctions de l'API FLFILE */

extern int FFbegin();
extern int FFend();
extern EHANDLE FFopen();
extern EHANDLE FFcreate();
extern int FFclose();
extern int FFaccess();
extern int FFunlink();
extern int FFatbopen();
extern int FFread();
extern int FFwrite();
extern int FFextend();
extern int FFrename();
extern EHANDLE SQopen();
extern EHANDLE SQcreate();
extern int SQclose();
extern int SQunlink();
extern int SQatbopen();
extern int SQread();
extern int SQwrite();
extern int SQmodif();
extern int SQrewind();
extern int SQrename();
extern int FlfileModuleIdentification();


/* Typage des fonctions de l'API Criteria */

extern int IsamBegin();
extern int IsamEnd();
extern HCRIT IsamCreate();
extern HCRIT IsamOpen();
extern int IsamClose();
extern int IsamUnlink();
extern int IsamRename();
extern int IsamSearch();
extern int IsamUpDown();
extern int IsamInsert();
extern int IsamDelete();
extern int IsamModif();
extern int IsamReadZc();
extern int IsamWriteZc();
extern int IsamAtbOpen();
extern HCRIT McIsamCreate();
extern HCRIT McIsamOpen();
extern int McIsamClose();
extern int McIsamUnlink();
extern int McIsamRename();
extern int McIsamSearch();
extern int McIsamUpDown();
extern int McIsamInsert();
extern int McIsamDelete();
extern int McIsamModif();
extern int McIsamAtbOpen();
extern int McIsamCkey();
extern int McIsamNkey();
extern int McIsamFkey();
extern int McIsamCndx();
extern int McIsamDndx();
extern int McIsamDCndx();
extern int McIsamDDndx();
extern int McIsamUpdndx();
extern int McIsamLkey();
extern int McIsamLndx();
extern int McIsamInfo();
extern int McIsamCount();
extern int McIsamPosit();
extern HCRIT BdIsamCreate();
extern HCRIT BdIsamOpen();
extern int BdIsamClose();
extern int BdIsamUnlink();
extern int BdIsamRename();
extern HCRIT BdIsamCreateFile();
extern HCRIT BdIsamOpenFile();
extern int BdIsamCloseFile();
extern int BdIsamUnlinkFile();
extern int BdIsamRenameFile();
extern int BdIsamAtbOpen();
extern int BdIsamCkey();
extern int BdIsamNkey();
extern int BdIsamFkey();
extern int BdIsamDCndx();
extern int BdIsamDDndx();
extern int BdIsamCndx();
extern int BdIsamDndx();
extern int BdIsamJoin();
extern int BdIsamCjoin();
extern int BdIsamDjoin();
extern int BdIsamRjoin();
extern int BdIsamInfo();
extern int BdIsamInfoFile();
extern int BdIsamLfile();
extern int BdIsamLjoin();
extern int BdIsamLkey();
extern int BdIsamLlink();
extern int BdIsamSearch();
extern int BdIsamInsert();
extern int BdIsamModif();
extern int BdIsamDelete();
extern int BdIsamCount();
extern int BdIsamPosit();
extern int BdIsamUpdndx();
extern int BdIsamUpDown();
extern int BdIsamUpDownFile();
extern int IsamModuleIdentification();

#endif /* LINT_ARGS */


#endif /* __EXMAUNIX_H__ */
