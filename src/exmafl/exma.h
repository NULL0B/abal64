/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1995
 *	Module  : EXA
 *	Fichier : EXMA.H
 *	Version : 1.1b
 *	Date    : 18/10/95
 *	Systeme : Windows 3 / NT / MS-DOS / Unix
 *
 *	Executeur ABAL
 *
 *	[Interface methodes d'acces - Definitions privees]
 *
 */

#ifndef __EXMA_H__
#define __EXMA_H__


/* Inclusions des types dependant de l'OS */

#ifdef WIN16
#include "exmtwin.h"
#endif
#ifdef WIN32
#include "exmtwin.h"
#endif
#ifdef DOS
#include "exmtdos.h"
#endif
#ifdef ISUNIX
#include "exmtunix.h"
#endif


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*		QUELQUES DEFINITIONS INPENDANTES DE L'OS		     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* Quelques macros */

#define ERR(a)		{ e = a ; goto err; }


/* Quelques types de donnees */

typedef DWORD EHANDLE;
typedef DWORD HCRIT;
typedef BYTE FLCONF;
typedef BYTE CRTCONF;
typedef FLCONF FAR * LPFLCONF;


/* Structure de description d'une signature de DLL */

#include "flstruct.h"

#define CRIT_compatible	0 	/* indice de compatibilite : 1 octet */
#define CRIT_ver	1	/* version+release : 1 octet */
#define CRIT_indice	2	/* indice de correction : 1 octet */
#define CRIT_dedicat	3	/* cle de cryptage pour dedicat */
#define CRIT_IdPart1	5	/* identifiant appelant */
#define CRIT_IdPart2	9	/* identifiant appelant (suite) */
#define CRIT_cnx	13	/* handle de connexion */
#define CRIT_fill	17 	/* reserve pour extensions : 90 octets */
#define CONF_SIZE	105


/* Structure de description d'un entete de fichier sequentiel */

struct _sqform {
	WORD		SQxx_rec;
	WORD		SQsz_rec;		/* longueur enregistrement */
	DWORD		SQnb_rec;		/* nombre d'enregistrements */
	DWORD		SQrd_rec;		/* position de lecture */
	DWORD		SQwr_rec;		/* position d'ecriture */
};
typedef struct _sqform SQFORM;
typedef SQFORM FAR * LPSQFORM;


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*		QUELQUES DEFINITIONS DEPENDANT DE L'OS			     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#ifdef WIN16
#include "exmawin.h"
#endif
#ifdef WIN32
#include "exmawin.h"
#endif
#ifdef DOS
#include "exmados.h"
#endif
#ifdef ISUNIX
#include "exmaunix.h"
#endif


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			QUELQUES DONNEES 				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* Donnees internes */

static EHANDLE AD_cnx;
static HCRIT MA_cnx;


/* Donnees externes importees */

extern LSEEKTYPE fidseek;
extern WORD fidinfo1,fidinfo2;


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*		DEFINITIONS DES PRIMITIVES (avec LINT_ARGS)		     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#ifdef LINT_ARGS
WORD NOTFASTCALL si_init(void);
void NOTFASTCALL si_fin(void);

EX_FILE_HANDLE NOTFASTCALL EeEad_create(BPTR, WORD, WPTR);
WORD NOTFASTCALL EeEad_rename(EX_FILE_HANDLE, BPTR);
WORD NOTFASTCALL EeEad_unlink(BPTR);
EX_FILE_HANDLE NOTFASTCALL EeEad_open(BPTR, WORD, WPTR);
WORD NOTFASTCALL EeEad_read(EX_FILE_HANDLE, BPTR, WORD);
WORD NOTFASTCALL EeEad_write(EX_FILE_HANDLE, BPTR, WORD);
WORD NOTFASTCALL EeEad_extend(EX_FILE_HANDLE, WORD);
WORD NOTFASTCALL EeEad_access(BPTR, WORD);
WORD NOTFASTCALL EeEad_matb(EX_FILE_HANDLE, WORD);
WORD NOTFASTCALL EeEad_close(EX_FILE_HANDLE);

EX_FILE_HANDLE NOTFASTCALL EeEsq_create(BPTR, WORD, WORD, WPTR);
WORD NOTFASTCALL EeEsq_rename(EX_FILE_HANDLE, BPTR);
WORD NOTFASTCALL EeEsq_unlink(BPTR);
EX_FILE_HANDLE NOTFASTCALL EeEsq_open(BPTR, WORD, WPTR);
WORD NOTFASTCALL EeEsq_matb(EX_FILE_HANDLE, WORD);
WORD NOTFASTCALL EeEsq_read(EX_FILE_HANDLE, BPTR, WORD);
WORD NOTFASTCALL EeEsq_write(EX_FILE_HANDLE, BPTR, WORD);
WORD NOTFASTCALL EeEsq_modif(EX_FILE_HANDLE, BPTR, WORD);
WORD NOTFASTCALL EeEsq_rewind(EX_FILE_HANDLE);
WORD NOTFASTCALL EeEsq_close(EX_FILE_HANDLE);

EX_FILE_HANDLE NOTFASTCALL EeEsi_create(BPTR, WORD, WORD, WORD, WORD, WORD, WPTR);
WORD NOTFASTCALL EeEsi_rename(EX_FILE_HANDLE, BPTR);
WORD NOTFASTCALL EeEsi_unlink(BPTR);
EX_FILE_HANDLE NOTFASTCALL EeEsi_open(BPTR, WORD, WPTR);
WORD NOTFASTCALL EeEsi_matb(EX_FILE_HANDLE, WORD);
WORD NOTFASTCALL EeEsi_close(EX_FILE_HANDLE);
WORD NOTFASTCALL EeEsi_writezc(EX_FILE_HANDLE, BPTR, WORD);
WORD NOTFASTCALL EeEsi_readzc(EX_FILE_HANDLE, WORD, BPTR, WORD);
WORD NOTFASTCALL EeEsi_insert(EX_FILE_HANDLE, BPTR, BYTE, BPTR, WORD);
WORD NOTFASTCALL EeEsi_delete(EX_FILE_HANDLE, BPTR, BYTE);
WORD NOTFASTCALL EeEsi_modif(EX_FILE_HANDLE, BPTR, BYTE, BPTR, WORD);
WORD NOTFASTCALL EeEsi_search(EX_FILE_HANDLE, WORD, WORD, BPTR, BYTE, BPTR, WORD);
WORD NOTFASTCALL EeEsi_down(EX_FILE_HANDLE, WORD, WORD, BYTE, BPTR, WORD);
WORD NOTFASTCALL EeEsi_up(EX_FILE_HANDLE, WORD, WORD, BYTE, BPTR, WORD);

EX_FILE_HANDLE NOTFASTCALL EeEmc_create(BPTR, WORD, WORD, WORD, WORD, WORD, WPTR);
WORD NOTFASTCALL EeEmc_rename(EX_FILE_HANDLE, BPTR);
WORD NOTFASTCALL EeEmc_unlink(BPTR);
EX_FILE_HANDLE NOTFASTCALL EeEmc_open(BPTR, WORD, WPTR);
WORD NOTFASTCALL EeEmc_matb(EX_FILE_HANDLE, WORD);
WORD NOTFASTCALL EeEmc_close(EX_FILE_HANDLE);
WORD NOTFASTCALL EeEmc_insert(EX_FILE_HANDLE, BPTR, BYTE, BPTR, WORD);
WORD NOTFASTCALL EeEmc_delete(EX_FILE_HANDLE, BPTR, BYTE);
WORD NOTFASTCALL EeEmc_modif(EX_FILE_HANDLE, BPTR, BYTE, BPTR, WORD);
WORD NOTFASTCALL EeEmc_search(EX_FILE_HANDLE, WORD, WORD, BPTR, BYTE, BPTR, WORD);
WORD NOTFASTCALL EeEmc_down(EX_FILE_HANDLE, WORD, WORD, BYTE, BPTR, WORD);
WORD NOTFASTCALL EeEmc_up(EX_FILE_HANDLE, WORD, WORD, BYTE, BPTR, WORD);
WORD NOTFASTCALL EeEmc_ckey(EX_FILE_HANDLE, BPTR, WORD, WORD);
WORD NOTFASTCALL EeEmc_nkey(EX_FILE_HANDLE, BPTR, BPTR);
WORD NOTFASTCALL EeEmc_fkey(EX_FILE_HANDLE, BPTR, BPTR, WORD, WORD, WORD);
WORD NOTFASTCALL EeEmc_updndx(EX_FILE_HANDLE);
WORD NOTFASTCALL EeEmc_cndx(EX_FILE_HANDLE, BPTR, WORD);
WORD NOTFASTCALL EeEmc_dndx(EX_FILE_HANDLE, BPTR, WORD);
WORD NOTFASTCALL EeEmc_dcndx(EX_FILE_HANDLE, BPTR, WORD);
WORD NOTFASTCALL EeEmc_ddndx(EX_FILE_HANDLE, BPTR, WORD);
WORD NOTFASTCALL EeEmc_lkey(EX_FILE_HANDLE, BPTR, WORD, WORD);
WORD NOTFASTCALL EeEmc_lndx(EX_FILE_HANDLE, BPTR, WORD, WORD);
WORD NOTFASTCALL EeEmc_info(EX_FILE_HANDLE, BPTR, WORD);
WORD NOTFASTCALL EeEmc_count(EX_FILE_HANDLE, BPTR, WORD, WORD, WORD, LONG SPTR);
WORD NOTFASTCALL EeEmc_posit(EX_FILE_HANDLE, BPTR, WORD, WORD, WORD, WORD, LPINT);

EX_FILE_HANDLE NOTFASTCALL EeEbd_create(BPTR, WORD, WPTR);
WORD NOTFASTCALL EeEbd_rename(EX_FILE_HANDLE, BPTR);
WORD NOTFASTCALL EeEbd_unlink(BPTR);
EX_FILE_HANDLE NOTFASTCALL EeEbd_open(BPTR, WORD, WPTR);
WORD NOTFASTCALL EeEbd_matb(EX_FILE_HANDLE, WORD);
WORD NOTFASTCALL EeEbd_close(EX_FILE_HANDLE);
EX_FILE_HANDLE NOTFASTCALL EeEbf_create(BPTR, WORD, WORD, WORD, WORD, WORD, EX_FILE_HANDLE, WPTR);
WORD NOTFASTCALL EeEbf_rename(EX_FILE_HANDLE, BPTR);
WORD NOTFASTCALL EeEbf_unlink(BPTR, EX_FILE_HANDLE, WORD);
EX_FILE_HANDLE NOTFASTCALL EeEbf_open(BPTR, WORD, EX_FILE_HANDLE, WPTR);
WORD NOTFASTCALL EeEbf_close(EX_FILE_HANDLE);
WORD NOTFASTCALL EeEbf_insert(EX_FILE_HANDLE, BPTR, BYTE, BPTR, WORD);
WORD NOTFASTCALL EeEbf_delete(EX_FILE_HANDLE, BPTR, BYTE);
WORD NOTFASTCALL EeEbf_modif(EX_FILE_HANDLE, BPTR, BYTE, BPTR, WORD);
WORD NOTFASTCALL EeEbf_search(EX_FILE_HANDLE, WORD, WORD, BPTR, BYTE, BPTR, WORD);
WORD NOTFASTCALL EeEbf_down(EX_FILE_HANDLE, WORD, WORD, BYTE, BPTR, WORD);
WORD NOTFASTCALL EeEbf_up(EX_FILE_HANDLE, WORD, WORD, BYTE, BPTR, WORD);
WORD NOTFASTCALL EeEbd_ckey(EX_FILE_HANDLE, BPTR, WORD, WORD);
WORD NOTFASTCALL EeEbd_nkey(EX_FILE_HANDLE, BPTR, BPTR);
WORD NOTFASTCALL EeEbd_fkey(EX_FILE_HANDLE, BPTR, BPTR, WORD, WORD, WORD);
WORD NOTFASTCALL EeEbd_updndx(EX_FILE_HANDLE);
WORD NOTFASTCALL EeEbd_cndx(EX_FILE_HANDLE, BPTR, WORD);
WORD NOTFASTCALL EeEbd_dndx(EX_FILE_HANDLE, BPTR, WORD);
WORD NOTFASTCALL EeEbd_dcndx(EX_FILE_HANDLE, BPTR, WORD);
WORD NOTFASTCALL EeEbd_ddndx(EX_FILE_HANDLE, BPTR, WORD);
WORD NOTFASTCALL EeEbd_join(EX_FILE_HANDLE, BPTR, WORD);
WORD NOTFASTCALL EeEbd_cjoin(EX_FILE_HANDLE, BPTR, WORD, WORD);
WORD NOTFASTCALL EeEbd_djoin(EX_FILE_HANDLE, BPTR);
WORD NOTFASTCALL EeEbd_rjoin(EX_FILE_HANDLE, BPTR, WORD);
WORD NOTFASTCALL EeEbd_info(EX_FILE_HANDLE, BPTR, WORD);
WORD NOTFASTCALL EeEbf_info(EX_FILE_HANDLE, BPTR, WORD);
WORD NOTFASTCALL EeEbd_lfile(EX_FILE_HANDLE, BPTR, WORD, WORD);
WORD NOTFASTCALL EeEbd_ljoin(EX_FILE_HANDLE, BPTR, WORD, WORD);
WORD NOTFASTCALL EeEbd_lkey(EX_FILE_HANDLE, BPTR, WORD, WORD);
WORD NOTFASTCALL EeEbd_llink(EX_FILE_HANDLE, BPTR, WORD, WORD);
WORD NOTFASTCALL EeEbd_count(EX_FILE_HANDLE, BPTR, WORD, WORD, WORD, LONG SPTR);
WORD NOTFASTCALL EeEbd_posit(EX_FILE_HANDLE, BPTR, WORD, WORD, WORD, WORD, LPINT);
WORD NOTFASTCALL EeEbd_updown(EX_FILE_HANDLE, WORD, WORD, WPTR, BPTR, WORD);

#else	/* LINT_ARGS */


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*		DEFINITIONS DES PRIMITIVES (sans LINT_ARGS)		     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

WORD NOTFASTCALL si_init();
void NOTFASTCALL si_fin();

EX_FILE_HANDLE NOTFASTCALL EeEad_create();
WORD NOTFASTCALL EeEad_rename();
WORD NOTFASTCALL EeEad_unlink();
EX_FILE_HANDLE NOTFASTCALL EeEad_open();
WORD NOTFASTCALL EeEad_read();
WORD NOTFASTCALL EeEad_write();
WORD NOTFASTCALL EeEad_extend();
WORD NOTFASTCALL EeEad_access();
WORD NOTFASTCALL EeEad_matb();
WORD NOTFASTCALL EeEad_close();

EX_FILE_HANDLE NOTFASTCALL EeEsq_create();
WORD NOTFASTCALL EeEsq_rename();
WORD NOTFASTCALL EeEsq_unlink();
EX_FILE_HANDLE NOTFASTCALL EeEsq_open();
WORD NOTFASTCALL EeEsq_matb();
WORD NOTFASTCALL EeEsq_read();
WORD NOTFASTCALL EeEsq_write();
WORD NOTFASTCALL EeEsq_modif();
WORD NOTFASTCALL EeEsq_rewind();
WORD NOTFASTCALL EeEsq_close();

EX_FILE_HANDLE NOTFASTCALL EeEsi_create();
WORD NOTFASTCALL EeEsi_rename();
WORD NOTFASTCALL EeEsi_unlink();
EX_FILE_HANDLE NOTFASTCALL EeEsi_open();
WORD NOTFASTCALL EeEsi_matb();
WORD NOTFASTCALL EeEsi_close();
WORD NOTFASTCALL EeEsi_writezc();
WORD NOTFASTCALL EeEsi_readzc();
WORD NOTFASTCALL EeEsi_insert();
WORD NOTFASTCALL EeEsi_delete();
WORD NOTFASTCALL EeEsi_modif();
WORD NOTFASTCALL EeEsi_search();
WORD NOTFASTCALL EeEsi_down();
WORD NOTFASTCALL EeEsi_up();

EX_FILE_HANDLE NOTFASTCALL EeEmc_create();
WORD NOTFASTCALL EeEmc_rename();
WORD NOTFASTCALL EeEmc_unlink();
EX_FILE_HANDLE NOTFASTCALL EeEmc_open();
WORD NOTFASTCALL EeEmc_matb();
WORD NOTFASTCALL EeEmc_close();
WORD NOTFASTCALL EeEmc_insert();
WORD NOTFASTCALL EeEmc_delete();
WORD NOTFASTCALL EeEmc_modif();
WORD NOTFASTCALL EeEmc_search();
WORD NOTFASTCALL EeEmc_down();
WORD NOTFASTCALL EeEmc_up();
WORD NOTFASTCALL EeEmc_ckey();
WORD NOTFASTCALL EeEmc_nkey();
WORD NOTFASTCALL EeEmc_fkey();
WORD NOTFASTCALL EeEmc_updndx();
WORD NOTFASTCALL EeEmc_cndx();
WORD NOTFASTCALL EeEmc_dndx();
WORD NOTFASTCALL EeEmc_dcndx();
WORD NOTFASTCALL EeEmc_ddndx();
WORD NOTFASTCALL EeEmc_lkey();
WORD NOTFASTCALL EeEmc_lndx();
WORD NOTFASTCALL EeEmc_info();
WORD NOTFASTCALL EeEmc_count();
WORD NOTFASTCALL EeEmc_posit();

EX_FILE_HANDLE NOTFASTCALL EeEbd_create();
WORD NOTFASTCALL EeEbd_rename();
WORD NOTFASTCALL EeEbd_unlink();
EX_FILE_HANDLE NOTFASTCALL EeEbd_open();
WORD NOTFASTCALL EeEbd_matb();
WORD NOTFASTCALL EeEbd_close();
EX_FILE_HANDLE NOTFASTCALL EeEbf_create();
WORD NOTFASTCALL EeEbf_rename();
WORD NOTFASTCALL EeEbf_unlink();
EX_FILE_HANDLE NOTFASTCALL EeEbf_open();
WORD NOTFASTCALL EeEbf_close();
WORD NOTFASTCALL EeEbf_insert();
WORD NOTFASTCALL EeEbf_delete();
WORD NOTFASTCALL EeEbf_modif();
WORD NOTFASTCALL EeEbf_search();
WORD NOTFASTCALL EeEbf_down();
WORD NOTFASTCALL EeEbf_up();
WORD NOTFASTCALL EeEbd_ckey();
WORD NOTFASTCALL EeEbd_nkey();
WORD NOTFASTCALL EeEbd_fkey();
WORD NOTFASTCALL EeEbd_updndx();
WORD NOTFASTCALL EeEbd_cndx();
WORD NOTFASTCALL EeEbd_dndx();
WORD NOTFASTCALL EeEbd_dcndx();
WORD NOTFASTCALL EeEbd_ddndx();
WORD NOTFASTCALL EeEbd_join();
WORD NOTFASTCALL EeEbd_cjoin();
WORD NOTFASTCALL EeEbd_djoin();
WORD NOTFASTCALL EeEbd_rjoin();
WORD NOTFASTCALL EeEbd_info();
WORD NOTFASTCALL EeEbf_info();
WORD NOTFASTCALL EeEbd_lfile();
WORD NOTFASTCALL EeEbd_ljoin();
WORD NOTFASTCALL EeEbd_lkey();
WORD NOTFASTCALL EeEbd_llink();
WORD NOTFASTCALL EeEbd_count();
WORD NOTFASTCALL EeEbd_posit();
WORD NOTFASTCALL EeEbd_updown();

#endif /* LINT_ARGS */

#endif /* __EXMA_H__ */
