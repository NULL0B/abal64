#ifndef	_EXAIGCRI_C
#define	_EXAIGCRI_C
 
/************************************************************* 09/03/95 ***/
/***								        ***/
/***	AIG pour fonctions SIMCBD de EXA vers API CRITERIA/SQ/AD        ***/
/***								        ***/
/**************************************************************************/

#define	_DEFAULT_YOUSLEEP 50

static	int 	yousleep=-1;

EXAWORD	get_yousleep()
{
	char	*yptr;
	char    *getenv(char *);
	if ( yousleep == -1 ) {
		if (!( yptr = getenv("ERROR74") ))
			yousleep = _DEFAULT_YOUSLEEP;
		else	{
			for (yousleep =0; *yptr != 0; yptr++ ) {
				if (( *yptr >= '0' ) && ( *yptr <= '9'))
					yousleep = ((yousleep * 10) + ( *yptr - '0' ));
				else	break;
				}
			}
		}
	return( yousleep );
}

VOID	set_yousleep(EXAWORD v)	{	yousleep=v; return;	}

EXAWORD	error74( int flag, int status )
{
	int	sleepcount;
	if (( status == 74 )
	&&  ((sleepcount = get_yousleep()) > 0))
		usleep( sleepcount );

	return( status );
}

#ifdef	UNIX
VOID	abqt()
{
	(void) error74(1,74);
	return;
}
#endif

/*
 *	A I G _ C R I  ( )
 *	------------------
 *	Performs the switching / redirection function for all of
 *	the functions in the Intersection between MC and SI and BD
 *	(Uses Amenesik / Sologic SF codes to perform the switching)
 *
 * RENVOIE UN CODE ERREUR !!!!
 *
 */

#include "exngf.h"

#define	LONG_NAMES_COMPATIBILITY_ERROR  66

EXABYTE  DetectLongNamesSupport()
{
	EXABYTE  info[1]={0};
	bSystemLongNames=0;

#ifndef COMPATIBLE_CRI35
	/* Function added for Criteria 3.6 with long name support */
	/* ------------------------------------------------------ */
	if ((EeE_IsamInfo(fidname,info) != 0) || (*info==1)) {
		bSystemLongNames=1;
		}
#endif
	return bSystemLongNames;
}



EXAWORD	aig_cri()
{
	EXAWORD    erreur, clemode, cadrage, lvar;

	switch ( simcbd ) { 

		/* CLOSE */
		/* ------*/
		case 0x2026 : return(EeEsi_close(fidreel));
		case 0x2027 : return(EeEmc_close(fidreel));
		case 0x2127 : return(EeEbf_close(fidreel));
		case 0x2126 : return(EeEbd_close(fidreel));

		/* OPEN */
		/* ---- */
		case 0x363E :
		case 0x2036 :
			if (!(fidreel=EeEsi_open(fidname,fidperm, (WPTR)&erreur))) { 
				fidreel=EX_UNUSED_HANDLE; return(erreur); 
				}
			else	{
				return((EXAWORD)0); 
      				}

		case 0x203F :
		case 0x2037 :
      
			bSystemLongNames=0;
			if (!(fidreel=EeEmc_open(fidname,fidperm, (WPTR)&erreur))) {
        			fidreel=EX_UNUSED_HANDLE; 
				return(erreur); 
      				}
			else	{ 
				DetectLongNamesSupport();
				if (bUserLongNames && !bSystemLongNames) {
					EeEmc_close(fidreel);
					fidreel=EX_UNUSED_HANDLE;
					return (LONG_NAMES_COMPATIBILITY_ERROR);
					}
				return((EXAWORD)0); 
				}

		case 0x213F :
		case 0x2137 :
			bSystemLongNames=0;
			if (!(fidreel=EeEbf_open(fidname,fidperm, dbreel, (WPTR)&erreur))) {
				fidreel=EX_UNUSED_HANDLE; 
				return(erreur); 
				}
			else	{
				DetectLongNamesSupport();
        			if (bUserLongNames && !bSystemLongNames) {
					EeEbf_close(fidreel);
					fidreel=EX_UNUSED_HANDLE;
					return (LONG_NAMES_COMPATIBILITY_ERROR);
					}
				return((EXAWORD)0); 
				}

		case 0x2136 :
		case 0x213E :
			bSystemLongNames=0;
			if (!(fidreel=EeEbd_open(fidname,fidperm, (WPTR)&erreur))){
				fidreel=EX_UNUSED_HANDLE; return(erreur); 
				}
			else	{
        			DetectLongNamesSupport();
        			if (bUserLongNames && !bSystemLongNames){
          				EeEbd_close(fidreel);
          				fidreel=EX_UNUSED_HANDLE;
          				return (LONG_NAMES_COMPATIBILITY_ERROR);
        				}
        			return((EXAWORD)0); 
      			}

		/* MODIFY ATRIBUTES */
		/* ---------------  */
		case 0x201E : return(EeEsi_matb(fidreel, fidperm));
		case 0x201F : return(EeEmc_matb(fidreel, fidperm));
		case 0x211E : return(EeEbd_matb(fidreel, fidperm));


		/* CREATE FILE */
		/* ----------- */
		case 0x203A :
		case 0x2032 : 
			clemode=(fmtchk & 7);
			cadrage=(clemode & 0x0006) >> 1;
			if (cadrage==3)	cadrage=2;
			lvar=clemode & 0x0001;
			if (!(fidreel=EeEsi_create(fidname, fidperm, workval2, workval1, cadrage, lvar, (WPTR)&erreur))){
				fidreel=EX_UNUSED_HANDLE; 
				return(erreur); 
      				}
			else	return((EXAWORD)0); 

		case 0x203B :
		case 0x2033 :
			bSystemLongNames=0;
			clemode=(fmtchk & 7);
			cadrage=(clemode & 0x0006) >> 1;
			if (cadrage==3)	cadrage=2;
			lvar=clemode & 0x0001;
      			if (!(fidreel=EeEmc_create(fidname, fidperm, workval2, workval1, cadrage, lvar, (WPTR)&erreur))){
				fidreel=EX_UNUSED_HANDLE; 
				return(erreur); 
				}
			else	{
        			DetectLongNamesSupport();
        			if (bUserLongNames && !bSystemLongNames){
          				EeEmc_close(fidreel);
          				EeEmc_unlink(fidname);
          				fidreel=EX_UNUSED_HANDLE;
          				return (LONG_NAMES_COMPATIBILITY_ERROR);
        				}
        			return((EXAWORD)0); 
      				}


		case 0x213B :
		case 0x2133 :
			bSystemLongNames=0;
			clemode=(fmtchk & 7);
			cadrage=(clemode & 0x0006) >> 1;
			if (cadrage==3)	cadrage=2;
			lvar=clemode & 0x0001;
			if (!(fidreel=EeEbf_create(fidname, fidperm, workval2, workval1, cadrage, lvar, dbreel, (WPTR)&erreur))){
				fidreel=EX_UNUSED_HANDLE; 
				return(erreur); 
      				}
			else	{ 
        			DetectLongNamesSupport();
        			if (bUserLongNames && !bSystemLongNames){
          				EeEbf_close(fidreel);
          				EeEbf_unlink(fidname, dbreel, (EXAWORD)(fmtchk & 3));
          				fidreel=EX_UNUSED_HANDLE;
          				return (LONG_NAMES_COMPATIBILITY_ERROR);
        				}
        			return((EXAWORD)0); 
      				}

		case 0x213A :
		case 0x2132 :
      			bSystemLongNames=0;
			if (!(fidreel=EeEbd_create(fidname, fidperm, (WPTR)&erreur))){
        			fidreel=EX_UNUSED_HANDLE; return(erreur); 
				}
			else	{
        			DetectLongNamesSupport();
        			if (bUserLongNames && !bSystemLongNames){
	          			EeEbd_close(fidreel);
	          			EeEbd_unlink(fidname);
	          			fidreel=EX_UNUSED_HANDLE;
	          			return (LONG_NAMES_COMPATIBILITY_ERROR);
	        			}
			        return((EXAWORD)0); 
      				}

		/* RENAME FILE */
		/* ----------- */
		case 0x202E : return(EeEsi_rename(fidreel, workptr1));
		case 0x202F : return(EeEmc_rename(fidreel, workptr1));
		case 0x212E : return(EeEbd_rename(fidreel, workptr1));
		case 0x212F : return(EeEbf_rename(fidreel, workptr1));


		/* DELETE FILE */
		/* ----------- */
		case 0x2022 : return(EeEsi_unlink(fidname));
		case 0x2023 : return(EeEmc_unlink(fidname));
		case 0x2123 : return(EeEbf_unlink(fidname, dbreel, (EXAWORD)(fmtchk & 3)));
		case 0x2122 : return(EeEbd_unlink(fidname));

		/* INSERT KEY */
		/* ---------- */
		case 0x20A2 : return(EeEsi_insert(fidreel,si_cle,(EXABYTE)si_mq,si_buf,(EXAWORD)si_lng));
		case 0x20A3 : return(EeEmc_insert(fidreel,si_cle,(EXABYTE)si_mq,si_buf,(EXAWORD)si_lng));
		case 0x21A3 : return(EeEbf_insert(fidreel,si_cle,(EXABYTE)si_mq,si_buf,(EXAWORD)si_lng)); 

		/* DELETE KEY */
		/* ---------- */
		case 0x202A : return(EeEsi_delete(fidreel,si_cle,(EXABYTE)si_mq));
		case 0x207F : return(EeEmc_delete(fidreel,si_cle,(EXABYTE)si_mq));
		case 0x217F : return(EeEbf_delete(fidreel,si_cle,(EXABYTE)si_mq)); 

		/* MODIFY ART/MQ */
		/* ------------- */
		case 0x20A6 : return(EeEsi_modif(fidreel,si_cle,(EXABYTE)si_mq,si_buf,(EXAWORD)si_lng));
		case 0x20A7 : return(EeEmc_modif(fidreel,si_cle,(EXABYTE)si_mq,si_buf,(EXAWORD)si_lng));
		case 0x21A7 : return(EeEbf_modif(fidreel,si_cle,(EXABYTE)si_mq,si_buf,(EXAWORD)si_lng)); 


		/* SEARCH KEY/MQ */
		/* ------------- */
		case 0x2066 :
		case 0x2062 : return(error74(si_flg,EeEsi_search(fidreel, (EXAWORD)si_ver, (EXAWORD)si_flg, si_cle, (EXABYTE)si_mq, si_buf, (EXAWORD)si_lng)));
		case 0x2053 :
		case 0x2057 : return(error74(si_flg,EeEmc_search(fidreel, (EXAWORD)si_ver, (EXAWORD)si_flg, si_cle, (EXABYTE)si_mq, si_buf, (EXAWORD)si_lng)));
		case 0x2157 :
		case 0x2153 : return(error74(si_flg,EeEbf_search(fidreel, (EXAWORD)si_ver, (EXAWORD)si_flg, si_cle, (EXABYTE)si_mq, si_buf, (EXAWORD)si_lng)));

		/* DOWN Ctrl MQ  */
		/* ------------  */
		case 0x206E :
		case 0x206A : return(error74(si_flg,EeEsi_down(fidreel,(EXAWORD)si_ver,(EXAWORD)si_flg,(EXABYTE)si_mq,si_buf,(EXAWORD)si_lng)));

		case 0x206F :
		case 0x206B : return(error74(si_flg,EeEmc_down(fidreel,(EXAWORD)si_ver,(EXAWORD)si_flg,(EXABYTE)si_mq,si_buf,(EXAWORD)si_lng)));

		case 0x216F :
		case 0x216B : return(error74(si_flg,EeEbf_down(fidreel,(EXAWORD)si_ver,(EXAWORD)si_flg,(EXABYTE)si_mq,si_buf,(EXAWORD)si_lng)));

		/* UP   Ctrl MQ  */
		/* ------------  */
		case 0x2076 :
		case 0x2072 : return(error74(si_flg,EeEsi_up(fidreel,(EXAWORD)si_ver,(EXAWORD)si_flg,(EXABYTE)si_mq,si_buf,(EXAWORD)si_lng)));
		case 0x2077 :
		case 0x2073 : return(error74(si_flg,EeEmc_up(fidreel,(EXAWORD)si_ver,(EXAWORD)si_flg,(EXABYTE)si_mq,si_buf,(EXAWORD)si_lng)));
		case 0x2177 :
		case 0x2173 : return(error74(si_flg,EeEbf_up(fidreel,(EXAWORD)si_ver,(EXAWORD)si_flg,(EXABYTE)si_mq,si_buf,(EXAWORD)si_lng)));

		case	_NGF_XUSER : /* 0x0012 */
			      return(EeEsi_criext(fidreel, si_buf, (EXAWORD)si_lng, workptr1, (EXAWORD)workval3));

		default     : return(ABAL_OPNOTPOSS);
		}

}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*		FONCTIONS INTERNES MULTICRITERES			     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* --------------------------------------------------------------------------
 *
 * FCT MC_ckey
 *
 *	Declaration d'une nouvelle rubrique.
 *
 *	E/ code fonction type SF Amenesik / Sologic
 *	   numero logique du fichier
 *	   pointeur sur le descripteur Amenesik / Sologic
 *	   longueur du descripteur
 *	   option supplementaire du descripteur
 *	S/ compte-rendu : 0L si Ok, -1L si probleme, errno renseigne
 *
 */

static  char  szRubDesc[RUB_DESC_LEN_EXT*2+1];


BPTR  PrepareRubDesc(BPTR desc,EXABYTE code,EXAWORD desc_len){
  int i;
  BPTR  pDesc=desc;
  int	pos=0;

  if (!bUserLongNames && bSystemLongNames){
    strncpy(szRubDesc,desc,MAX_RUB_NAME_LEN_STD>desc_len ? desc_len:MAX_RUB_NAME_LEN_STD);
    pDesc=szRubDesc;
    for (i=MAX_RUB_NAME_LEN_STD;i<MAX_RUB_NAME_LEN_EXT;i++){
    	pDesc[i]=' ';
    	}
    switch (code){
    case 1:
      // {Name[16] Info[4]} -> {Name[50] Info[4]}  //for CKEY
      for (i=MAX_RUB_NAME_LEN_STD;i<RUB_DESC_LEN_STD && i<desc_len;i++){
        pDesc[MAX_RUB_NAME_LEN_EXT+i-MAX_RUB_NAME_LEN_STD]=desc[i];
      }
      break;
    case 2:
      // {Name[16] Info[3] NewName[16] Sup[2]} -> {Name[50] Info[3] Name[50] Sup[2]} //for FKEY
      for (i=MAX_RUB_NAME_LEN_STD;i<RUB_DESC_LEN_STD-1 && i<desc_len;i++){
        pDesc[MAX_RUB_NAME_LEN_EXT+i-MAX_RUB_NAME_LEN_STD]=desc[i];
      }
		pos=MAX_RUB_NAME_LEN_EXT+i-MAX_RUB_NAME_LEN_STD;
		for (i=0;i<MAX_RUB_NAME_LEN_EXT;i++){
			if (i<MAX_RUB_NAME_LEN_STD) pDesc[pos+i]=desc[i+RUB_DESC_LEN_STD-1];
			else pDesc[pos+i]=' ';
		}
		pos+=i;
      for (i=0;i<2;i++) pDesc[pos+i]=desc[i+MAX_RUB_NAME_LEN_STD+RUB_DESC_LEN_STD-1];
		break;
    case 3:
      // {Name[16] Info[3] NewName[16]} -> {Name[50] Info[3] Name[50]}
      for (i=MAX_RUB_NAME_LEN_STD;i<RUB_DESC_LEN_STD-1 && i<desc_len;i++){
        pDesc[MAX_RUB_NAME_LEN_EXT+i-MAX_RUB_NAME_LEN_STD]=desc[i];
      }
		pos=MAX_RUB_NAME_LEN_EXT+i-MAX_RUB_NAME_LEN_STD;
		for (i=0;i<MAX_RUB_NAME_LEN_EXT;i++){
			if (i<MAX_RUB_NAME_LEN_STD) pDesc[pos+i]=desc[i+RUB_DESC_LEN_STD-1];
			else pDesc[pos+i]=' ';
		}
      break;
    default:
      break;
    }
  }
  return pDesc;
}


EXALONG MC_ckey(func,hfic,bptr,blen,mode)
EXAWORD func;
EX_FILE_HANDLE hfic;
BPTR bptr;
EXAWORD blen;
EXAWORD mode;
{ 
  EXABYTE tlo,thi;
  EXAWORD taille;
  EXABYTE type;

	/* Recupere la longueur de la rubrique */

	if (bUserLongNames){
		tlo = *(bptr+RUB_LEN_OFFSET_EXT);
	    	thi = *(bptr+RUB_LEN_OFFSET_EXT+1);
	  	}
	else	{
		tlo = *(bptr+RUB_LEN_OFFSET_STD);
	    	thi = *(bptr+RUB_LEN_OFFSET_STD+1);
	  	}

	taille = (((EXAWORD)thi) << 8) | ((EXAWORD) tlo);

	/* Recupere le type de la rubrique fille */

	if (bUserLongNames)  type = (*(bptr+RUB_TYPE_OFFSET_EXT) == 0) ? 0 : 1;
	else type = (*(bptr+RUB_TYPE_OFFSET_STD) == 0) ? 0 : 1;

	bptr=PrepareRubDesc(bptr,1,blen);

	/* Cree la description dans le fichier */
	if (errno = (int)EeEmc_ckey(hfic,(BPTR)bptr,(EXAWORD)taille,(EXAWORD)type))
		return((EXALONG)-1);
	else	return((EXALONG)0);
}

/* --------------------------------------------------------------------------
 *
 * FCT MC_nkey
 *
 *	Renommer une rubrique existante.
 *
 *	E/ code fonction type SF Amenesik / Sologic
 *	   numero logique du fichier
 *	   pointeur sur le descripteur Amenesik / Sologic
 *	   longueur du descripteur
 *	   option supplementaire du descripteur
 *	S/ compte-rendu : 0L si Ok, -1L si probleme, errno renseigne
 *
 */
EXALONG MC_nkey(func,hfic,bptr,blen,mode)
EXAWORD func;
EX_FILE_HANDLE hfic;
BPTR bptr;
EXAWORD blen;
EXAWORD mode;
{ 
	/* Cree la description dans le fichier */

	bptr=PrepareRubDesc(bptr,3,blen);
	if (errno=(int)EeEmc_nkey(hfic,(BPTR)bptr,(BPTR)bptr+(bSystemLongNames ? (RUB_DESC_LEN_EXT-1):(RUB_DESC_LEN_STD-1))))
		return((EXALONG)-1);
	return((EXALONG)0);
}

/* --------------------------------------------------------------------------
 *
 * FCT MC_fkey
 *
 *	Redefinition d'une rubrique existante.
 *
 *	E/ code fonction type SF Amenesik / Sologic
 *	   numero logique du fichier
 *	   pointeur sur le descripteur Amenesik / Sologic
 *	   longueur du descripteur
 *	   option supplementaire du descripteur
 *	S/ compte-rendu : 0L si Ok, -1L si probleme, errno renseigne
 *
 */
EXALONG MC_fkey(func,hfic,bptr,blen,mode)
EXAWORD func;
EX_FILE_HANDLE hfic;
BPTR bptr;
EXAWORD blen;
EXAWORD mode;
{
  EXAWORD taille,offset;
  EXABYTE tlo,thi,type;

	/* Recupere la longueur de la rubrique fille */
	/* ----------------------------------------- */
	if (bUserLongNames){
		tlo = *(bptr+RUB_LEN_OFFSET_EXT);
		thi = *(bptr+RUB_LEN_OFFSET_EXT+1);
		}
	else	{
		tlo = *(bptr+RUB_LEN_OFFSET_STD);
		thi = *(bptr+RUB_LEN_OFFSET_STD+1);
		}
	taille = (((EXAWORD)thi) << 8) | ((EXAWORD) tlo);

	/* Recupere l'offset de la rubrique fille par rapport a la rubrique mere. */
	/* ---------------------------------------------------------------------- */
	if (bUserLongNames){
		tlo = *(bptr+RUB_DESC_LEN_EXT+MAX_RUB_NAME_LEN_EXT-1);
		thi = *(bptr+RUB_DESC_LEN_EXT+MAX_RUB_NAME_LEN_EXT);
		}
	else	{
		tlo = *(bptr+RUB_DESC_LEN_STD+MAX_RUB_NAME_LEN_STD-1);
		thi = *(bptr+RUB_DESC_LEN_STD+MAX_RUB_NAME_LEN_STD);
		}
	offset = (((EXAWORD)thi) << 8) | ((EXAWORD) tlo);

	/* Recupere le type de la rubrique fille */
	/* ------------------------------------- */
	if (bUserLongNames)  type = (*(bptr+RUB_TYPE_OFFSET_EXT) == 0) ? 0 : 1;
	else type = (*(bptr+RUB_TYPE_OFFSET_STD) == 0) ? 0 : 1;

	/* Cree la description dans le fichier */
	/* ----------------------------------- */
	bptr=PrepareRubDesc(bptr,2,blen);
	if (errno = (int)EeEmc_fkey(hfic,(BPTR)bptr,(BPTR)bptr+(bSystemLongNames ? (RUB_DESC_LEN_EXT-1):(RUB_DESC_LEN_STD-1)),taille,type,offset))
		return((EXALONG)-1);
	return((EXALONG)0L);
}

/* --------------------------------------------------------------------------
 *
 * FCT MC_link
 *
 *	Description d'un lien en creation/suppression.
 *
 *	E/ code fonction type SF Amenesik / Sologic
 *	   numero logique du fichier
 *	   pointeur sur le descripteur Amenesik / Sologic
 *	   longueur du descripteur
 *	   option supplementaire du descripteur
 *	S/ compte-rendu : 0L si Ok, -1L si probleme, errno renseigne
 *
 */
EXALONG MC_link(func,hfic,bptr,blen,mode)
EXAWORD func;
EX_FILE_HANDLE hfic;
BPTR bptr;
EXAWORD blen;
EXAWORD mode;
{

	/* Controle qu'au moins un nom d'index est transmis */
	/* ------------------------------------------------ */
	if (bptr == (BPTR)NULL) { errno=89; return((EXALONG)-1); }

	/* Aiguille vers une creation/suppression de lien selon le cas. */
	/* ------------------------------------------------------------ */
	if ((mode & 0x0008) == 0) {

		/* Lien a creer */
		/* ------------ */
		if (errno = (int)EeEmc_dcndx(hfic,bptr,blen))
			return((EXALONG)-1);
		}
	else 	{

		/* Lien a supprimer */
		/* ---------------- */
		if (errno = (int)EeEmc_ddndx(hfic,bptr,blen))
			return((EXALONG)-1);
		}

	return((EXALONG)0);
}

/* --------------------------------------------------------------------------
 *
 * FCT MC_clink
 *
 *	Creation/suppression d'un lien.
 *
 *	E/ code fonction type SF Amenesik / Sologic
 *	   numero logique du fichier
 *	   pointeur sur le descripteur Amenesik / Sologic
 *	   longueur du descripteur
 *	   option supplementaire du descripteur
 *	S/ compte-rendu : 0L si Ok, -1L si probleme, errno renseigne
 *
 */
EXALONG MC_clink(func,hfic,bptr,blen,mode)
EXAWORD func;
EX_FILE_HANDLE hfic;
BPTR bptr;
EXAWORD blen;
EXAWORD mode;
{
	/* Aiguille vers une creation/suppression/mise a jour de lien(s) selon le cas. */
	/* --------------------------------------------------------------------------- */
	if ((mode & 0x0001) == 0) {
		/* Mettre a jour tous les liens */
		if (errno=(int)EeEmc_updndx(hfic)) return((EXALONG)-1);
		}
	else 	{
		if ((mode & 0x0008) == 0) {
			/* Lien a creer */
			if (errno=(int)EeEmc_cndx(hfic,bptr,blen)) return((EXALONG)-1);
			}
		else 	{
			/* Lien a supprimer */
			if (errno=(int)EeEmc_dndx(hfic,bptr,blen)) return((EXALONG)-1);
			}
		}

	return((EXALONG)0);
}

/* --------------------------------------------------------------------------
 *
 * FCT MC_lkey
 *
 *	Recuperation de la liste des rubriques d'un fichier.
 *
 *	E/ code fonction type SF Amenesik / Sologic
 *	   numero logique du fichier
 *	   pointeur sur le descripteur Amenesik / Sologic
 *	   longueur du descripteur
 *	   option supplementaire du descripteur
 *	S/ compte-rendu : 0L si Ok, -1L si probleme, errno renseigne
 *
 */
EXALONG MC_lkey(func,hfic,bptr,blen,mode)
EXAWORD func;
EX_FILE_HANDLE hfic;
BPTR bptr;
EXAWORD blen;
EXAWORD mode;
{
  EXAWORD type;

	/* Determine s'il s'agit de la premiere rubrique ou de la rubrique suivante. */
	/* ------------------------------------------------------------------------- */
	type = ((mode & 0x0020) == 0) ? 1 : 0;

	if (bUserLongNames) type|=2;

	/* Appelle la fonction appropriee */
	/* ------------------------------ */
	if (errno=(int)EeEmc_lkey(hfic,bptr,blen,type)) return((EXALONG)-1);

	return((EXALONG)0);
}

/* --------------------------------------------------------------------------
 *
 * FCT MC_llink
 *
 *	Recuperation de la liste des liens d'un fichier.
 *
 *	E/ code fonction type SF Amenesik / Sologic
 *	   numero logique du fichier
 *	   pointeur sur le descripteur Amenesik / Sologic
 *	   longueur du descripteur
 *	   option supplementaire du descripteur
 *	S/ compte-rendu : 0 si Ok, 0xFFFF si probleme, errno renseigne
 *
 */
EXALONG MC_llink(func,hfic,bptr,blen,mode)
EXAWORD func;
EX_FILE_HANDLE hfic;
BPTR bptr;
EXAWORD blen;
EXAWORD mode;
{
  EXAWORD type;

	/* Determine s'il s'agit du premier lien ou du lien suivant. */
	/* --------------------------------------------------------- */
	type = ((mode & 0x0020) == 0) ? 1 : 0;

	if (bUserLongNames) type|=2;

	/* Appelle la fonction appropriee */
	/* ------------------------------ */
	if (errno=(int)EeEmc_lndx(hfic,bptr,blen,type)) return((EXALONG)-1);
		
	return((EXALONG)0);
}

/* --------------------------------------------------------------------------
 *
 * FCT MC_stat
 *
 *	Recuperation de statistiques sur un fichier.
 *
 *	E/ code fonction type SF Amenesik / Sologic
 *	   numero logique du fichier
 *	   pointeur sur le descripteur Amenesik / Sologic
 *	   longueur du descripteur
 *	   option supplementaire du descripteur
 *	S/ compte-rendu : 0L si Ok, -1L si probleme, errno renseigne
 *
 */
EXALONG MC_stat(func,hfic,bptr,blen,mode)
EXAWORD func;
EX_FILE_HANDLE hfic;
BPTR bptr;
EXAWORD blen;
EXAWORD mode;
{
	/* Appelle la fonction appropriee */
	/* ------------------------------ */
	if (errno = (int)EeEmc_info(hfic,bptr,blen)) return((EXALONG)-1);
	return((EXALONG)0);
}

/* --------------------------------------------------------------------------
 *
 * FCT MC_interrog
 *
 *	Interrogation (denombrement/positionnement) sur un fichier.
 *
 *	E/ code fonction type SF Amenesik / Sologic
 *	   numero logique du fichier
 *	   pointeur sur le descripteur Amenesik / Sologic
 *	   longueur du descripteur
 *	   option supplementaire du descripteur
 *	S/ compte-rendu : nb records si Ok, -1L si probleme, errno renseigne
 *
 */
EXALONG MC_interrog(func,hfic,bptr,blen,mode)
EXAWORD func;
EX_FILE_HANDLE hfic;
BPTR bptr;
EXAWORD blen;
EXAWORD mode;
{
  EXAWORD TypePos;
  EXAWORD FlagUnique;
  EXAWORD FlagSeq;
  EXAWORD compte;
  EXALONG lcompte;

	/* Determine le type de positionnement : premier/dernier */
	TypePos = (func == 0x20AB) ? 0 : 1;

	/* Puis le type de traitement des doublons */
	FlagUnique = ((mode & 0x0020) == 0) ? 0 : 1;

	/* Puis le type de recherche sequentielle/selective */
	FlagSeq = ((mode & 0x0040) == 0) ? 0 : 1;

	/* Aiguille au POSIT ou au COUNT selon le cas */
	if ((mode & 0x0080) == 0) {
		/* Positionnement */
		if (errno=(int)EeEmc_posit(hfic,bptr,FlagUnique,FlagSeq,TypePos,blen,(WPTR)&compte))
			return((EXALONG)-1);
		}
	else 	{
		/* Denombrement */
		if (errno=(int)EeEmc_count(hfic,bptr,FlagUnique,FlagSeq,blen,(EXALONG SPTR)&lcompte))
			return((EXALONG)-1);
		}

	/* Retourne le nombre de reponses */
	if ((mode & 0x0080) == 0)
		return((EXALONG)compte);
	else	return(lcompte);
}


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*		FONCTIONS INTERNES BASE DE DONNEES			     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* --------------------------------------------------------------------------
 *
 * FCT BD_ckey
 *
 *	Declaration d'une nouvelle rubrique.
 *
 *	E/ code fonction type SF Amenesik / Sologic
 *	   numero logique du fichier
 *	   pointeur sur le descripteur Amenesik / Sologic
 *	   longueur du descripteur
 *	   option supplementaire du descripteur
 *	S/ compte-rendu : 0L si Ok, -1L si probleme, errno renseigne
 *
 */
EXALONG BD_ckey(func,hfic,bptr,blen,mode)
EXAWORD func;
EX_FILE_HANDLE hfic;
BPTR bptr;
EXAWORD blen;
EXAWORD mode;
{
  EXABYTE tlo,thi;
  EXAWORD taille;
  EXABYTE type;

	/* Recupere la longueur de la rubrique */
	/* ----------------------------------- */
	if (bUserLongNames)  type = ( (*(bptr+RUB_TYPE_OFFSET_EXT) == 0) ? 0 : 1);
	else type = (*(bptr+RUB_TYPE_OFFSET_STD) == 0) ? 0 : 1;

	if (bUserLongNames){
		tlo = *(bptr+RUB_LEN_OFFSET_EXT);
    		thi = *(bptr+RUB_LEN_OFFSET_EXT+1);
		}
	else	{
	  	tlo = *(bptr+RUB_LEN_OFFSET_STD);
   	 	thi = *(bptr+RUB_LEN_OFFSET_STD+1);
  		}
	taille = (((EXAWORD)thi) << 8) | ((EXAWORD) tlo);

	if (bUserLongNames) (  type = (*(bptr+RUB_TYPE_OFFSET_EXT) == 0) ? 0 : 1);
	else type = (*(bptr+RUB_TYPE_OFFSET_STD) == 0) ? 0 : 1;

	bptr=PrepareRubDesc(bptr,1,blen);

	/* Cree la description dans le fichier */
	/* ----------------------------------- */
	if (errno=(int)EeEbd_ckey(hfic,(BPTR)bptr,taille,type)) 
		return((EXALONG)-1);
	else	return((EXALONG)0);
}

/* --------------------------------------------------------------------------
 *
 * FCT BD_nkey
 *
 *	Renommer une rubrique existante.
 *
 *	E/ code fonction type SF Amenesik / Sologic
 *	   numero logique du fichier
 *	   pointeur sur le descripteur Amenesik / Sologic
 *	   longueur du descripteur
 *	   option supplementaire du descripteur
 *	S/ compte-rendu : 0L si Ok, -1L si probleme, errno renseigne
 *
 */
EXALONG BD_nkey(func,hfic,bptr,blen,mode)
EXAWORD func;
EX_FILE_HANDLE hfic;
BPTR bptr;
EXAWORD blen;
EXAWORD mode;
{

	/* Cree la description dans le fichier */
	/* ----------------------------------- */
	bptr=PrepareRubDesc(bptr,3,blen);
	if (errno=(int)EeEbd_nkey(hfic,(BPTR)bptr,(BPTR)bptr+(bSystemLongNames ? (RUB_DESC_LEN_EXT-1):(RUB_DESC_LEN_STD-1)))) 
		return((EXALONG)-1);
	else 	return((EXALONG)0);
}

/* --------------------------------------------------------------------------
 *
 * FCT BD_fkey
 *
 *	Redefinition d'une rubrique existante.
 *
 *	E/ code fonction type SF Amenesik / Sologic
 *	   numero logique du fichier
 *	   pointeur sur le descripteur Amenesik / Sologic
 *	   longueur du descripteur
 *	   option supplementaire du descripteur
 *	S/ compte-rendu : 0L si Ok, -1L si probleme, errno renseigne
 *
 */
EXALONG BD_fkey(func,hfic,bptr,blen,mode)
EXAWORD func;
EX_FILE_HANDLE hfic;
BPTR bptr;
EXAWORD blen;
EXAWORD mode;
{
  EXAWORD taille,offset;
  EXABYTE tlo,thi,type;

	/* Recupere la longueur de la rubrique fille */
	/* ----------------------------------------- */
	if (bUserLongNames){
	  	tlo = *(bptr+RUB_LEN_OFFSET_EXT);
    		thi = *(bptr+RUB_LEN_OFFSET_EXT+1);
  		}
	else	{
	  	tlo = *(bptr+RUB_LEN_OFFSET_STD);
    		thi = *(bptr+RUB_LEN_OFFSET_STD+1);
  		}
	taille = (((EXAWORD)thi) << 8) | ((EXAWORD) tlo);

	/* Recupere l'offset de la rubrique fille par rapport a la rubrique mere. */
	/* ---------------------------------------------------------------------- */
	if (bUserLongNames){
	  	tlo = *(bptr+RUB_DESC_LEN_EXT+MAX_RUB_NAME_LEN_EXT-1);
    		thi = *(bptr+RUB_DESC_LEN_EXT+MAX_RUB_NAME_LEN_EXT);
  		}
	else	{
	  	tlo = *(bptr+RUB_DESC_LEN_STD+MAX_RUB_NAME_LEN_STD-1);
    		thi = *(bptr+RUB_DESC_LEN_STD+MAX_RUB_NAME_LEN_STD);
  		}
	offset = (((EXAWORD)thi) << 8) | ((EXAWORD) tlo);

	/* Recupere le type de la rubrique fille */
	/* ------------------------------------- */
	if (bUserLongNames)  type = (*(bptr+RUB_TYPE_OFFSET_EXT) == 0) ? 0 : 1;
	else type = (*(bptr+RUB_TYPE_OFFSET_STD) == 0) ? 0 : 1;

	bptr=PrepareRubDesc(bptr,2,blen);
	if (errno=(int)EeEbd_fkey(hfic,(BPTR)bptr,
                    ((BPTR)bptr+(bSystemLongNames ? (RUB_DESC_LEN_EXT-1):(RUB_DESC_LEN_STD-1))),
					taille,type,offset)) return((EXALONG)-1);

	return((EXALONG)0);
}

/* --------------------------------------------------------------------------
 *
 * FCT BD_link
 *
 *	Description d'un lien en creation/suppression.
 *
 *	E/ code fonction type SF Amenesik / Sologic
 *	   numero logique du fichier
 *	   pointeur sur le descripteur Amenesik / Sologic
 *	   longueur du descripteur
 *	   option supplementaire du descripteur
 *	S/ compte-rendu : 0L si Ok, -1L si probleme, errno renseigne
 *
 */
EXALONG BD_link(func,hfic,bptr,blen,mode)
EXAWORD func;
EX_FILE_HANDLE hfic;
BPTR bptr;
EXAWORD blen;
EXAWORD mode;
{

	/* Controle qu'au moins un nom d'index est transmis */
	if (bptr == (BPTR)NULL) { errno=89; return((EXALONG)-1); }

	if ((mode & 0x0008) == 0) {
		/* Lien a creer */
		if (errno = (int)EeEbd_dcndx(hfic,bptr,blen)) return((EXALONG)-1);
		}
	else 	{
		/* Lien a supprimer */
		if (errno=(int)EeEbd_ddndx(hfic,bptr,blen)) return((EXALONG)-1);
		}

	return((EXALONG)0);
}

/* --------------------------------------------------------------------------
 *
 * FCT BD_clink
 *
 *	Creation/suppression d'un lien.
 *
 *	E/ code fonction type SF Amenesik / Sologic
 *	   numero logique du fichier
 *	   pointeur sur le descripteur Amenesik / Sologic
 *	   longueur du descripteur
 *	   option supplementaire du descripteur
 *	S/ compte-rendu : 0L si Ok, -1L si probleme, errno renseigne
 *
 */
EXALONG BD_clink(func,hfic,bptr,blen,mode)
EXAWORD func;
EX_FILE_HANDLE hfic;
BPTR bptr;
EXAWORD blen;
EXAWORD mode;
{

	/* Aiguille vers une creation/suppression/mise a jour de lien(s) selon le cas.  */
	if ((mode & 0x0001) == 0) {
		/* Mettre a jour tous les liens */
		if (errno=EeEbd_updndx(hfic)) return((EXALONG)-1);
		}
	else 	{
		if ((mode & 0x0008) == 0) {
			/* Lien a creer */
			if (errno=(int)EeEbd_cndx(hfic,bptr,blen)) return((EXALONG)-1);
			}
		else 	{
			/* Lien a supprimer */
			if (errno=(int)EeEbd_dndx(hfic,bptr,blen)) return((EXALONG)-1);
			}
		}

	return((EXALONG)0);
}

/* --------------------------------------------------------------------------
 *
 * FCT BD_join
 *
 *	Description d'une jointure.
 *
 *	E/ code fonction type SF Amenesik / Sologic
 *	   numero logique du fichier
 *	   pointeur sur le descripteur Amenesik / Sologic
 *	   longueur du descripteur
 *	   option supplementaire du descripteur
 *	S/ compte-rendu : 0L si Ok, -1L si probleme, errno renseigne
 *
 */
EXALONG BD_join(func,hfic,bptr,blen,mode)
EXAWORD func;
EX_FILE_HANDLE hfic;
BPTR bptr;
EXAWORD blen;
EXAWORD mode;
{

	/* Controle qu'au moins un nom de jointure est transmis */
	if (bptr == (BPTR)NULL) { errno=175; return((EXALONG)-1); }

	/* Description de la jointure a creer */
	if (errno=(int)EeEbd_join(hfic,bptr,blen)) return((EXALONG)-1);

	return((EXALONG)0);
}

/* --------------------------------------------------------------------------
 *
 * FCT BD_cjoin
 *
 *	Creation d'une jointure.
 *
 *	E/ code fonction type SF Amenesik / Sologic
 *	   numero logique du fichier
 *	   pointeur sur le descripteur Amenesik / Sologic
 *	   longueur du descripteur
 *	   option supplementaire du descripteur
 *	S/ compte-rendu : 0L si Ok, -1L si probleme, errno renseigne
 *
 */
EXALONG BD_cjoin(func,hfic,bptr,blen,mode)
EXAWORD func;
EX_FILE_HANDLE hfic;
BPTR bptr;
EXAWORD blen;
EXAWORD mode;
{

	/* Creation d'une ou de toutes les jointures */
	if (errno=(int)EeEbd_cjoin(hfic,bptr,blen,(EXAWORD)(mode & 0x0001))) return((EXALONG)-1);

	return((EXALONG)0);
}

/* --------------------------------------------------------------------------
 *
 * FCT killjoin
 *
 *	Suppression d'une jointure.
 *
 *	E/ pointeur sur le nom de la jointure
 *	S/ compte-rendu : 0L si Ok, -1L si probleme, errno renseigne
 *
 */
EXAWORD killjoin(Name)
BPTR Name;
{
  EX_FILE_HANDLE hfic;
  EXABYTE NameZ[32];
  EXAWORD i;
  EXABYTE c;

	/* Retrouve le descripteur vers le fichier */
	hfic = fidreel;

	/* Recopie le nom de la jointure et le termine par un nul */
	for (i = 0 ; i < 16 ; i++) {
		c = *(Name+i+2);
		if ((c == ' ') || (c == '\0'))
			break;
		NameZ[i] = c;
		}
	NameZ[i] = '\0';

	/* Suppression d'une jointure */
	if (errno=(int)EeEbd_djoin(hfic,(BPTR)&NameZ[0])) return((EXAWORD)-1);
	return((EXAWORD)0);
}

/* --------------------------------------------------------------------------
 *
 * FCT BD_rjoin
 *
 *	Renommage d'une jointure.
 *
 *	E/ code fonction type SF Amenesik / Sologic
 *	   numero logique du fichier
 *	   pointeur sur le descripteur Amenesik / Sologic
 *	   pointeur sur le nouveau nom de la jointure
 *	   option supplementaire du descripteur
 *	S/ compte-rendu : 0L si Ok, -1L si probleme, errno renseigne
 *
 */
EXALONG BD_rjoin(func,hfic,bptr,NewName,mode)
EXAWORD func;
EX_FILE_HANDLE hfic;
BPTR bptr;
BPTR NewName;
EXAWORD mode;
{

	/* Creation d'une ou de toutes les jointures */
	if (errno=(int)EeEbd_rjoin(hfic,bptr,(EXAWORD)32)) return((EXALONG)-1);
	return((EXALONG)0);
}

/* --------------------------------------------------------------------------
 *
 * FCT BD_interrog
 *
 *	Interrogation (denombrement/positionnement) sur une base.
 *
 *	E/ code fonction type SF Amenesik / Sologic
 *	   numero logique du fichier
 *	   pointeur sur le descripteur Amenesik / Sologic
 *	   longueur du descripteur
 *	   option supplementaire du descripteur
 *	S/ compte-rendu : nb records si Ok, -1L si probleme, errno renseigne
 *
 */
EXALONG BD_interrog(func,hfic,bptr,blen,mode)
EXAWORD func;
EX_FILE_HANDLE hfic;
BPTR bptr;
EXAWORD blen;
EXAWORD mode;
{
  EXAWORD TypePos;
  EXAWORD FlagUnique;
  EXAWORD FlagSeq;
  EXAWORD compte;
  EXALONG lcompte;

	/* Determine le type de positionnement : premier/dernier */
	TypePos = (func == 0x21AB) ? 0 : 1;

	/* Puis le type de traitement des doublons */
	FlagUnique = ((mode & 0x0020) == 0) ? 0 : 1;

	/* Puis le type de recherche sequentielle/selective */
	FlagSeq = ((mode & 0x0040) == 0) ? 0 : 1;

	/* Aiguille au POSIT ou au COUNT selon le cas */
	if ((mode & 0x0080) == 0) {
		/* Positionnement */
		if (errno=(int)EeEbd_posit(hfic,bptr,FlagUnique,FlagSeq,TypePos,blen,(WPTR)&compte)) return((EXALONG)-1);
		}
	else 	{
		/* Denombrement */
		if (errno=(int)EeEbd_count(hfic,bptr,FlagUnique,FlagSeq,blen,(EXALONG SPTR)&lcompte)) return((EXALONG)-1);
		}

	/* Retourne le nombre de reponses */
	if ((mode & 0x0080) == 0)
		return((EXALONG)compte);
	else
		return(lcompte);
}

/* --------------------------------------------------------------------------
 *
 * FCT DB_updown
 *
 *	Interrogation sequentielle sur une base.
 *
 *	E/ code fonction type SF Amenesik / Sologic
 *	   numero logique du fichier
 *	   pointeur sur le descripteur Amenesik / Sologic
 *	   longueur du descripteur
 *	   marqueur
 *	S/ compte-rendu : 0L si Ok, -1L si probleme, errno renseigne
 *
 */
EXALONG DB_updown(func,hfic,bptr,blen,marq)
EXAWORD func;
EX_FILE_HANDLE hfic;
BPTR bptr;
EXAWORD blen;
EXAWORD marq;
{
  EXAWORD nmarq;
  EXAWORD sens;
  EXAWORD lock;


	/* Prepare les parametres de la recherche */
	nmarq = (EXAWORD)marq;
	sens  = ((func == 0x21EF) || (func == 0x21EB)) ? 1 : -1;
	lock  = ((func == 0x21EF) || (func == 0x21F7)) ? 1 : 0;

	/* Effectue la recherche */
	if (errno = (int)EeEbd_updown(hfic,sens,lock,(WPTR)&nmarq,bptr,blen)) {
		return((EXALONG)-1);
		}
	return((EXALONG)0);
}

/* --------------------------------------------------------------------------
 *
 * FCT BD_stat
 *
 *	Recuperation de statistiques sur un fichier/sur la base.
 *
 *	E/ code fonction type SF Amenesik / Sologic
 *	   numero logique du fichier
 *	   pointeur sur le descripteur Amenesik / Sologic
 *	   longueur du descripteur
 *	   option supplementaire du descripteur
 *	S/ compte-rendu : 0L si Ok, -1L si probleme, errno renseigne
 *
 */
EXALONG BD_stat(func,hfic,bptr,blen,mode)
EXAWORD func;
EX_FILE_HANDLE hfic;
BPTR bptr;
EXAWORD blen;
EXAWORD mode;
{


	/* Appelle la fonction appropriee */
	if (func == 0x217A) {
		/* Statistiques sur la base */
		if (errno=(int)EeEbd_info(hfic,bptr,blen)) return((EXALONG)-1);
		}
	else 	{
		/* Statistiques sur un fichier de la base */
		if (errno=(int)EeEbf_info(hfic,bptr,blen)) return((EXALONG)-1);
		}

	return((EXALONG)0);
}

/* --------------------------------------------------------------------------
 *
 * FCT BD_lkey
 *
 *	Recuperation de la liste des rubriques d'une base.
 *
 *	E/ code fonction type SF Amenesik / Sologic
 *	   numero logique du fichier
 *	   pointeur sur le descripteur Amenesik / Sologic
 *	   longueur du descripteur
 *	   option supplementaire du descripteur
 *	S/ compte-rendu : 0L si Ok, -1L si probleme, errno renseigne
 *
 */
EXALONG BD_lkey(func,hfic,bptr,blen,mode)
EXAWORD func;
EX_FILE_HANDLE hfic;
BPTR bptr;
EXAWORD blen;
EXAWORD mode;
{
  EXAWORD type;

	/* Determine s'il s'agit de la premiere rubrique ou de
	 * la rubrique suivante.
	 */
	type = ((mode & 0x0020) == 0) ? 1 : 0;
	if (bUserLongNames) type|=2;

	/* Appelle la fonction appropriee */
	if (errno=(int)EeEbd_lkey(hfic,bptr,blen,type)) return((EXALONG)-1);

	return((EXALONG)0);
}

/* --------------------------------------------------------------------------
 *
 * FCT BD_llink
 *
 *	Recuperation de la liste des liens d'une base.
 *
 *	E/ code fonction type SF Amenesik / Sologic
 *	   numero logique du fichier
 *	   pointeur sur le descripteur Amenesik / Sologic
 *	   longueur du descripteur
 *	   option supplementaire du descripteur
 *	S/ compte-rendu : 0L si Ok, -1L si probleme, errno renseigne
 *
 */
EXALONG BD_llink(func,hfic,bptr,blen,mode)
EXAWORD func;
EX_FILE_HANDLE hfic;
BPTR bptr;
EXAWORD blen;
EXAWORD mode;
{
  EXAWORD type;

	/* Determine s'il s'agit du premier lien ou
	 * du lien suivant.
	 */
	type = ((mode & 0x0020) == 0) ? 1 : 0;
	if (bUserLongNames) type|=2;

	/* Appelle la fonction appropriee */
	if (errno = (int)EeEbd_llink(hfic,bptr,blen,type)) return((EXALONG)-1);

	return((EXALONG)0);
}

/* --------------------------------------------------------------------------
 *
 * FCT BD_lfile
 *
 *	Recuperation de la liste des fichiers d'une base.
 *
 *	E/ code fonction type SF Amenesik / Sologic
 *	   numero logique du fichier
 *	   pointeur sur le descripteur Amenesik / Sologic
 *	   longueur du descripteur
 *	   option supplementaire du descripteur
 *	S/ compte-rendu : 0L si Ok, -1L si probleme, errno renseigne
 *
 */
EXALONG BD_lfile(func,hfic,bptr,blen,mode)
EXAWORD func;
EX_FILE_HANDLE hfic;
BPTR bptr;
EXAWORD blen;
EXAWORD mode;
{
  EXAWORD type;

	/* Determine s'il s'agit du premier fichier ou
	 * du fichier suivant.
	 */
	type = ((mode & 0x0020) == 0) ? 1 : 0;
	if (bUserLongNames) type|=2;

	/* Appelle la fonction appropriee */
	if (errno=EeEbd_lfile(hfic,bptr,blen,type)) return((EXALONG)-1);

	return((EXALONG)0);
}

/* --------------------------------------------------------------------------
 *
 * FCT BD_ljoin
 *
 *	Recuperation de la liste des jointures d'une base.
 *
 *	E/ code fonction type SF Amenesik / Sologic
 *	   numero logique du fichier
 *	   pointeur sur le descripteur Amenesik / Sologic
 *	   longueur du descripteur
 *	   option supplementaire du descripteur
 *	S/ compte-rendu : 0L si Ok, -1L si probleme, errno renseigne
 *
 */
EXALONG BD_ljoin(func,hfic,bptr,blen,mode)
EXAWORD func;
EX_FILE_HANDLE hfic;
BPTR bptr;
EXAWORD blen;
EXAWORD mode;
{
  EXAWORD type;

	/* Determine s'il s'agit de la premiere jointure ou
	 * d'une jointure suivante.
	 */
	type = ((mode & 0x0020) == 0) ? 1 : 0;
	if (bUserLongNames) type|=2;

	/* Appelle la fonction appropriee */
	if (errno=(int)EeEbd_ljoin(hfic,bptr,blen,type)) return((EXALONG)-1);

	return((EXALONG)0);
}



//#include "exngf.h"

/*
 *	M C _ K E Y ( nlog , mode , bptr , blen , func )
 *	------------------------------------------------
 *	Aiguilleur des fonctions de l'intersection entre
 *	multicritere et la base de donnees excluent des fonctions
 *	dans l'intersection avec sequentiel indexe
 */

EXALONG	mc_key( nlog , mode , bptr , blen , func )
EX_FILE_HANDLE	nlog;	/* Numero logique fichier multicritere ou base 	*/
EXAWORD	mode;		/* Option suplimentaire de descriptor		*/
BPTR	bptr;		/* Pointer sur descripteur			*/
EXAWORD	blen;		/* Longeur de descripteur			*/
EXAWORD	func;		/* Code Fonction Type SF Amenesik / Sologic		*/
{
#ifdef	_EXA_MICKEY
	/* ----------------------------------------------------------------------------------- */
	/* This allows debug tracing of all MC KEY calls for KEY/LINK/POSIT/COUNT instructions */
	/* ----------------------------------------------------------------------------------- */
	BPTR	eptr;
	EXAWORD	i;
	if ((eptr = getenv("EXAMICKEY")) != (char *) 0) {
		if ( *eptr == '1' ) {
			printf("MICKEY: h=%u, op=%4.4X, mode=%x, blen=%u : \r\n",nlog,func,mode,blen);
			for ( i=0; i < blen; i++ ) 
				printf("%02.2X ",*(bptr+i));
			printf("\r\n");
			}			
		}
#endif
	switch ( func ) {
		/* Description des Rubriques */
		/* ------------------------- */
		case	0x20BB	:
				switch ( mode ) {

					/* Declaration d'une Rubrique 	*/
					/* -------------------------- 	*/
					case 0 : return(MC_ckey(func,nlog,bptr,blen,mode));
	
					/* Renommer une Rubrique	*/
					/* -------------------------- 	*/
					case 8 : return(MC_nkey(func,nlog,bptr,blen,mode));

					/* Redefinition d'une Rubrique  */
					/* --------------------------- 	*/
					case 1 : return(MC_fkey(func,nlog,bptr,blen,mode));
					}
				break;

		/* Description d'un Lien */
		/* --------------------- */
		case	0x20AF	: return(MC_link(func,nlog,bptr,blen,mode));

		/* Creation des Liens	 */
		/* ------------------	 */
		case	0x20B7	: return(MC_clink(func,nlog,bptr,blen,mode));

		/* Description des Rubriques */
		/* ------------------------- */
		case	0x21BB	:
				switch ( mode ) {

					/* Declaration d'une Rubrique 	*/
					/* -------------------------- 	*/
					case 0 : return(BD_ckey(func,nlog,bptr,blen,mode));
	
					/* Renommer une Rubrique	*/
					/* -------------------------- 	*/
					case 8 : return(BD_nkey(func,nlog,bptr,blen,mode));

					/* Redefinition d'une Rubrique  */
					/* --------------------------- 	*/
					case 1 : return(BD_fkey(func,nlog,bptr,blen,mode));
					}
				break;

		/* Description d'un Lien */
		/* --------------------- */
		case	0x21AF	: return(BD_link(func,nlog,bptr,blen,mode));

		/* Creation des Liens	 */
		/* ------------------	 */
		case	0x21B7	: return(BD_clink(func,nlog,bptr,blen,mode));

		/* Description d'une Jointure	*/
		/* --------------------------	*/
		case	0x21AE	: return(BD_join(func,nlog,bptr,blen,mode));

		/* Creation des Jointures  	*/
		/* ----------------------	*/
		case	0x21B6	: return(BD_cjoin(func,nlog,bptr,blen,mode));

		/* Renommer une Jointure  	*/
		/* ---------------------	*/
		case	0x21BF	: return(BD_rjoin((func & 0x00FF),nlog,bptr,
                      (bptr + (bSystemLongNames ? (MAX_RUB_NAME_LEN_EXT+1):(MAX_RUB_NAME_LEN_STD+1))),mode)); 

		/* Denombrement+Positionnement 	*/
		/* --------------------------- 	*/
		case	0x20AB	: /* Premier 	*/
		case	0x20B3	: /* Dernier 	*/
			return(MC_interrog(func,nlog,bptr,blen,mode));

		case	0x21AB	: /* Premier 	*/
		case	0x21B3	: /* Dernier 	*/
			return(BD_interrog(func,nlog,bptr,blen,mode));

		/* Interogation Sequentielle	*/
		/* -------------------------	*/
		case	0x21EF	: /* Suivante + blocage */
		case	0x21EB	: /* Suivante		*/
		case	0x21F7	: /* Precedante + bloc	*/
		case	0x21F3	: /* Precedante		*/
				return(DB_updown(func,nlog,bptr,blen,(EXABYTE)si_mq));


		/* Statistiques	*/
		/* ------------ */
		case	0x207B	: /* Sur un Fichier MC        	*/
				return(MC_stat(func,nlog,bptr,blen,mode));
		case	0x217B	: /* Sur un Fichier MC / BD	*/
		case	0x217A	: /* Sur la Base de donnees	*/
				return(BD_stat(func,nlog,bptr,blen,mode));

		/* Liste des Rubriques	*/
		/* -------------------	*/
		case	0x215B	: return(BD_lkey(func,nlog,bptr,blen,mode));

		/* Liste des Liens	*/
		/* ---------------	*/
		case	0x215F	: return(BD_llink(func,nlog,bptr,blen,mode));

		/* Liste des Rubriques	*/
		/* -------------------	*/
		case	0x205B	: return(MC_lkey(func,nlog,bptr,blen,mode));

		/* Liste des Liens	*/
		/* ---------------	*/
		case	0x205F	: return(MC_llink(func,nlog,bptr,blen,mode));

		/* Liste des Fichiers/Jointures */
		/* ----------------------------	*/
		case	0x215E	:		
			switch ( mode & 7 ) {

				/* Liste des fichiers */
				/* ------------------ */
				case 0x0003 :
				return(BD_lfile(func,nlog,bptr,blen,mode));

				/* Liste des Jointures */
				/* ------------------- */
				case 0x0007 :
				return(BD_ljoin(func,nlog,bptr,blen,mode));
				}

		}
	errno = ABAL_OPNOTPOSS;
	return(-1);

}

/*
 *	A N A J O I N ( Sptr , Dptr )
 *	-----------------------------
 *	Analyse et mise en place d'un nom de jointure
 *	(Remarque : Pas d'erreur possible rends toujours 1 : Fichier)
 */

EXAWORD	anajoin( sptr , dptr, slen )
BPTR	sptr;
BPTR	dptr;
EXAWORD slen;
{
	EXAWORD	x;
	EXAWORD	c;
	/* Mise en place du Numero de ressource a blanc */
	/* -------------------------------------------- */
	*(dptr++) = (EXABYTE) 0; *(dptr++) = (EXABYTE) 0; x = 15;

	memset( (BPTR) dptr, ' ', 15 );

	c = *(sptr + slen);
	*(sptr + slen) = 0;

	/* Extract Filename portion */
	/* ------------------------ */
	x = fn_parser((BPTR) sptr, (BPTR) dptr, 8 ); 		

	*(sptr + slen) = c;
	*(dptr + x) = ' ';
	return(1);
}




#endif	/* _EXAIGCRI_C */
	/* ---------- */








