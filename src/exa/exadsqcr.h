#ifndef	_EXADSQCR_H
#define	_EXADSQCR_H

/************************************************************* 14/03/95 ***/
/***									***/
/***	API NORMALISEE D'UTILISATION DES ACCES DIRECTS/SEQ/SI/MC/BD	***/
/***									***/
/***   Prototypes							***/
/***									***/
/**************************************************************************/

/*
*  Modifications:
*  08/06/00 : (#SP) EXA-15. EeEad_find - new function is declared for Client/server FIND fnct. (WIN32 only)
*/

/***************************************************************************/
/********* ACCES DIRECT ****************************************************/
/***************************************************************************/

EX_FILE_HANDLE EeEad_create(BPTR, EXAWORD, WPTR);
EXAWORD EeEad_rename(EX_FILE_HANDLE, BPTR);

#ifdef WIN32
/* #SP: 08/06/00 (begin) */
EXAWORD EeEad_find(EX_FILE_HANDLE, BPTR, BPTR);
/* #SP: 08/06/00 (end) */
#endif

EXAWORD EeEad_unlink(BPTR);
EX_FILE_HANDLE EeEad_open(BPTR, EXAWORD, WPTR);
EXAWORD EeEad_read(EX_FILE_HANDLE, BPTR, EXAWORD);
EXAWORD EeEad_write(EX_FILE_HANDLE, BPTR, EXAWORD);
EXAWORD EeEad_extend(EX_FILE_HANDLE, EXAWORD);
EXAWORD EeEad_access(BPTR, EXAWORD);
EXAWORD EeEad_matb(EX_FILE_HANDLE, EXAWORD);
EXAWORD EeEad_close(EX_FILE_HANDLE);


/***************************************************************************/
/********* ACCES SEQUENTIEL ************************************************/
/***************************************************************************/
EX_FILE_HANDLE EeEsq_create(BPTR, EXAWORD, EXAWORD, WPTR);
EXAWORD EeEsq_rename(EX_FILE_HANDLE, BPTR);
EXAWORD EeEsq_unlink(BPTR);
EX_FILE_HANDLE EeEsq_open(BPTR, EXAWORD, WPTR);
EXAWORD EeEsq_matb(EX_FILE_HANDLE, EXAWORD);
EXAWORD EeEsq_read(EX_FILE_HANDLE, BPTR, EXAWORD);
EXAWORD EeEsq_write(EX_FILE_HANDLE, BPTR, EXAWORD);
EXAWORD EeEsq_modif(EX_FILE_HANDLE, BPTR, EXAWORD);
EXAWORD EeEsq_rewind(EX_FILE_HANDLE);
EXAWORD EeEsq_close(EX_FILE_HANDLE);

/***************************************************************************/
/********* ACCES SEQUENTIEL INDEXE *****************************************/
/***************************************************************************/
EX_FILE_HANDLE EeEsi_create(BPTR, EXAWORD, EXAWORD, EXAWORD, EXAWORD, EXAWORD, WPTR);
EXAWORD EeEsi_rename(EX_FILE_HANDLE, BPTR);
EXAWORD EeEsi_unlink(BPTR);
EX_FILE_HANDLE EeEsi_open(BPTR, EXAWORD, WPTR);
EXAWORD EeEsi_matb(EX_FILE_HANDLE, EXAWORD);
EXAWORD EeEsi_close(EX_FILE_HANDLE);
EXAWORD EeEsi_writezc(EX_FILE_HANDLE, BPTR, EXAWORD);
EXAWORD EeEsi_readzc(EX_FILE_HANDLE, EXAWORD, BPTR, EXAWORD);
EXAWORD EeEsi_insert(EX_FILE_HANDLE, BPTR, EXABYTE, BPTR, EXAWORD);
EXAWORD EeEsi_delete(EX_FILE_HANDLE, BPTR, EXABYTE);
EXAWORD EeEsi_modif(EX_FILE_HANDLE, BPTR, EXABYTE, BPTR, EXAWORD);
EXAWORD EeEsi_search(EX_FILE_HANDLE, EXAWORD, EXAWORD, BPTR, EXABYTE, BPTR, EXAWORD);
EXAWORD EeEsi_down(EX_FILE_HANDLE, EXAWORD, EXAWORD, EXABYTE, BPTR, EXAWORD);
EXAWORD EeEsi_up(EX_FILE_HANDLE, EXAWORD, EXAWORD, EXABYTE, BPTR, EXAWORD);

#ifdef WIN32
EXAWORD EeEsi_criext(EX_FILE_HANDLE, BPTR, EXAWORD, BPTR, EXAWORD);
#endif


/***************************************************************************/
/********* ACCES MULTICRITERE **********************************************/
/***************************************************************************/
EX_FILE_HANDLE EeEmc_create(BPTR, EXAWORD, EXAWORD, EXAWORD, EXAWORD, EXAWORD, WPTR);
EXAWORD EeEmc_rename(EX_FILE_HANDLE, BPTR);
EXAWORD EeEmc_unlink(BPTR);
EX_FILE_HANDLE EeEmc_open(BPTR, EXAWORD, WPTR);
EXAWORD EeEmc_matb(EX_FILE_HANDLE, EXAWORD);
EXAWORD EeEmc_close(EX_FILE_HANDLE);
EXAWORD EeEmc_insert(EX_FILE_HANDLE, BPTR, EXABYTE, BPTR, EXAWORD);
EXAWORD EeEmc_delete(EX_FILE_HANDLE, BPTR, EXABYTE);
EXAWORD EeEmc_modif(EX_FILE_HANDLE, BPTR, EXABYTE, BPTR, EXAWORD);
EXAWORD EeEmc_search(EX_FILE_HANDLE, EXAWORD, EXAWORD, BPTR, EXABYTE, BPTR, EXAWORD);
EXAWORD EeEmc_down(EX_FILE_HANDLE, EXAWORD, EXAWORD, EXABYTE, BPTR, EXAWORD);
EXAWORD EeEmc_up(EX_FILE_HANDLE, EXAWORD, EXAWORD, EXABYTE, BPTR, EXAWORD);
EXAWORD EeEmc_ckey(EX_FILE_HANDLE, BPTR, EXAWORD, EXAWORD);
EXAWORD EeEmc_nkey(EX_FILE_HANDLE, BPTR, BPTR);
EXAWORD EeEmc_fkey(EX_FILE_HANDLE, BPTR, BPTR, EXAWORD, EXAWORD, EXAWORD);
EXAWORD EeEmc_updndx(EX_FILE_HANDLE);
EXAWORD EeEmc_cndx(EX_FILE_HANDLE, BPTR, EXAWORD);
EXAWORD EeEmc_dndx(EX_FILE_HANDLE, BPTR, EXAWORD);
EXAWORD EeEmc_dcndx(EX_FILE_HANDLE, BPTR, EXAWORD);
EXAWORD EeEmc_ddndx(EX_FILE_HANDLE, BPTR, EXAWORD);
EXAWORD EeEmc_lkey(EX_FILE_HANDLE, BPTR, EXAWORD, EXAWORD);
EXAWORD EeEmc_lndx(EX_FILE_HANDLE, BPTR, EXAWORD, EXAWORD);
EXAWORD EeEmc_info(EX_FILE_HANDLE, BPTR, EXAWORD);
EXAWORD EeEmc_count(EX_FILE_HANDLE, BPTR, EXAWORD, EXAWORD, EXAWORD, EXALONG PTR);
EXAWORD EeEmc_posit(EX_FILE_HANDLE, BPTR, EXAWORD, EXAWORD, EXAWORD, EXAWORD, WPTR);


/***************************************************************************/
/********* ACCES BASE DE DONNEES *******************************************/
/***************************************************************************/
EX_FILE_HANDLE EeEbd_create(BPTR, EXAWORD, WPTR);
EXAWORD EeEbd_rename(EX_FILE_HANDLE, BPTR);
EXAWORD EeEbd_unlink(BPTR);
EX_FILE_HANDLE EeEbd_open(BPTR, EXAWORD, WPTR);
EXAWORD EeEbd_matb(EX_FILE_HANDLE, EXAWORD);
EXAWORD EeEbd_close(EX_FILE_HANDLE);
EX_FILE_HANDLE EeEbf_create(BPTR, EXAWORD, EXAWORD, EXAWORD, EXAWORD, EXAWORD, EX_FILE_HANDLE, WPTR);
EXAWORD EeEbf_rename(EX_FILE_HANDLE, BPTR);
EXAWORD EeEbf_unlink(BPTR, EX_FILE_HANDLE, EXAWORD);
EX_FILE_HANDLE EeEbf_open(BPTR, EXAWORD, EX_FILE_HANDLE, WPTR);
EXAWORD EeEbf_close(EX_FILE_HANDLE);
EXAWORD EeEbf_insert(EX_FILE_HANDLE, BPTR, EXABYTE, BPTR, EXAWORD);
EXAWORD EeEbf_delete(EX_FILE_HANDLE, BPTR, EXABYTE);
EXAWORD EeEbf_modif(EX_FILE_HANDLE, BPTR, EXABYTE, BPTR, EXAWORD);
EXAWORD EeEbf_search(EX_FILE_HANDLE, EXAWORD, EXAWORD, BPTR, EXABYTE, BPTR, EXAWORD);
EXAWORD EeEbf_down(EX_FILE_HANDLE, EXAWORD, EXAWORD, EXABYTE, BPTR, EXAWORD);
EXAWORD EeEbf_up(EX_FILE_HANDLE, EXAWORD, EXAWORD, EXABYTE, BPTR, EXAWORD);
EXAWORD EeEbd_ckey(EX_FILE_HANDLE, BPTR, EXAWORD, EXAWORD);
EXAWORD EeEbd_nkey(EX_FILE_HANDLE, BPTR, BPTR);
EXAWORD EeEbd_fkey(EX_FILE_HANDLE, BPTR, BPTR, EXAWORD, EXAWORD, EXAWORD);
EXAWORD EeEbd_updndx(EX_FILE_HANDLE);
EXAWORD EeEbd_cndx(EX_FILE_HANDLE, BPTR, EXAWORD);
EXAWORD EeEbd_dndx(EX_FILE_HANDLE, BPTR, EXAWORD);
EXAWORD EeEbd_dcndx(EX_FILE_HANDLE, BPTR, EXAWORD);
EXAWORD EeEbd_ddndx(EX_FILE_HANDLE, BPTR, EXAWORD);
EXAWORD EeEbd_join(EX_FILE_HANDLE, BPTR, EXAWORD);
EXAWORD EeEbd_cjoin(EX_FILE_HANDLE, BPTR, EXAWORD, EXAWORD);
EXAWORD EeEbd_djoin(EX_FILE_HANDLE, BPTR);
EXAWORD EeEbd_rjoin(EX_FILE_HANDLE, BPTR, EXAWORD);
EXAWORD EeEbd_info(EX_FILE_HANDLE, BPTR, EXAWORD);
EXAWORD EeEbf_info(EX_FILE_HANDLE, BPTR, EXAWORD);
EXAWORD EeEbd_lfile(EX_FILE_HANDLE, BPTR, EXAWORD, EXAWORD);
EXAWORD EeEbd_ljoin(EX_FILE_HANDLE, BPTR, EXAWORD, EXAWORD);
EXAWORD EeEbd_lkey(EX_FILE_HANDLE, BPTR, EXAWORD, EXAWORD);
EXAWORD EeEbd_llink(EX_FILE_HANDLE, BPTR, EXAWORD, EXAWORD);
EXAWORD EeEbd_count(EX_FILE_HANDLE, BPTR, EXAWORD, EXAWORD, EXAWORD, EXALONG PTR);
EXAWORD EeEbd_posit(EX_FILE_HANDLE, BPTR, EXAWORD, EXAWORD, EXAWORD, EXAWORD, WPTR);
EXAWORD EeEbd_updown(EX_FILE_HANDLE, EXAWORD, EXAWORD, WPTR, BPTR, EXAWORD);

#endif	/* _EXADSQCR_C */
	/* ---------- */







