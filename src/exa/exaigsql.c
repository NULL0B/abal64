#ifndef	_EXAAIGSQL_C
#define	_EXAAIGSQL_C

/************************************************************* 09/03/95 ***/
/***									***/
/***	AIG pour fonctions SIMCBD de EXA vers API CRITERIA/SQ/AD    	***/
/***									***/
/**************************************************************************/
/*
 *	A I G _ S Q L  ( )
 *	------------------
 *	Performs the switching / redirection function for all of
 *	the functions in the Intersection between MC and SI and BD
 *	(Uses Amenesik / Sologic SF codes to perform the switching)
 *
 * RENVOIE UN CODE ERREUR !!!!
 *
 */

EXAWORD	aig_sql()
{
	EXAWORD erreur, clemode, cadrage, lvar;

	switch ( simcbd ) {

		/* CLOSE */
		/* ------*/
		case 0x2026 : return(Sqlsi_close(fidreel));
		case 0x2027 : return(Sqlmc_close(fidreel));
		case 0x2127 : return(Sqlbf_close(fidreel));
		case 0x2126 : return(Sqlbd_close(fidreel));

		/* OPEN */
		/* ---- */
		case 0x363E :
		case 0x2036 :
			if (!(fidreel=Sqlsi_open(fidname,fidperm, (WPTR)&erreur)))
				{ fidreel=EX_UNUSED_HANDLE; return(erreur); }
			else	{ return((EXAWORD)0); }
		case 0x203F :
		case 0x2037 :
			if (!(fidreel=Sqlmc_open(fidname,fidperm, (WPTR)&erreur)))
				{ fidreel=EX_UNUSED_HANDLE; return(erreur); }
			else	{ return((EXAWORD)0); }
		case 0x213F :
		case 0x2137 :
			if (!(fidreel=Sqlbf_open(fidname,fidperm, dbreel, (WPTR)&erreur)))
				{ fidreel=EX_UNUSED_HANDLE; return(erreur); }
			else	{ return((EXAWORD)0); }
		case 0x2136 :
		case 0x213E :
			if (!(fidreel=Sqlbd_open(fidname,fidperm, (WPTR)&erreur)))
				{ fidreel=EX_UNUSED_HANDLE; return(erreur); }
			else	{ return((EXAWORD)0); }

		/* MODIFY ATRIBUTES */
		/* ---------------  */
		case 0x201E : return(Sqlsi_matb(fidreel, fidperm));
		case 0x201F : return(Sqlmc_matb(fidreel, fidperm));
		case 0x211E : return(Sqlbd_matb(fidreel, fidperm));


		/* CREATE FILE */
		/* ----------- */
		case 0x203A :
		case 0x2032 : 
			clemode=(fmtchk & 7);
			cadrage=(clemode & 0x0006) >> 1;
			if (cadrage==3)	cadrage=2;
			lvar=clemode & 0x0001;
			if (!(fidreel=Sqlsi_create(fidname, fidperm, workval2, workval1, cadrage, lvar, (WPTR)&erreur)))
				{ fidreel=EX_UNUSED_HANDLE; return(erreur); }
			else	{ return((EXAWORD)0); }
		case 0x203B :
		case 0x2033 :
			clemode=(fmtchk & 7);
			cadrage=(clemode & 0x0006) >> 1;
			if (cadrage==3)	cadrage=2;
			lvar=clemode & 0x0001;
			if (!(fidreel=Sqlmc_create(fidname, fidperm, workval2, workval1, cadrage, lvar, (WPTR)&erreur)))
				{ fidreel=EX_UNUSED_HANDLE; return(erreur); }
			else	{ return((EXAWORD)0); }
		case 0x213B :
		case 0x2133 :
			clemode=(fmtchk & 7);
			cadrage=(clemode & 0x0006) >> 1;
			if (cadrage==3)	cadrage=2;
			lvar=clemode & 0x0001;
			if (!(fidreel=Sqlbf_create(fidname, fidperm, workval2, workval1, cadrage, lvar, dbreel, (WPTR)&erreur)))
				{ fidreel=EX_UNUSED_HANDLE; return(erreur); }
			else	{ return((EXAWORD)0); }
		case 0x213A :
		case 0x2132 :
			if (!(fidreel=Sqlbd_create(fidname, fidperm, (WPTR)&erreur)))
				{ fidreel=EX_UNUSED_HANDLE; return(erreur); }
			else	{ return((EXAWORD)0); }

		/* RENAME FILE */
		/* ----------- */
		case 0x202E : return(Sqlsi_rename(fidreel, workptr1));
		case 0x202F : return(Sqlmc_rename(fidreel, workptr1));
		case 0x212E : return(Sqlbd_rename(fidreel, workptr1));
		case 0x212F : return(Sqlbf_rename(fidreel, workptr1));


		/* DELETE FILE */
		/* ----------- */
		case 0x2022 : return(Sqlsi_unlink(fidname));
		case 0x2023 : return(Sqlmc_unlink(fidname));
#ifdef AIX_VERS
#ifdef UNIXWARE
		case 0x2123 :
			erreur = Sqlbf_unlink(fidname, dbreel, (EXAWORD) (fmtchk & 3));
			return(erreur);
#else
		case 0x2123 : return(Sqlbf_unlink(fidname, dbreel, (EXAWORD)(fmtchk & 3)));
#endif
#else  /* AIX_VERS */
		case 0x2123 : return(Sqlbf_unlink(fidname, dbreel, (EXAWORD)(fmtchk & 3)));
#endif /* AIX_VERS */
		case 0x2122 : return(Sqlbd_unlink(fidname));

		/* INSERT KEY */
		/* ---------- */
		case 0x20A2 : return(Sqlsi_insert(fidreel,si_cle,(EXABYTE)si_mq,si_buf,(EXAWORD)si_lng));
		case 0x20A3 : return(Sqlmc_insert(fidreel,si_cle,(EXABYTE)si_mq,si_buf,(EXAWORD)si_lng));
		case 0x21A3 : return(Sqlbf_insert(fidreel,si_cle,(EXABYTE)si_mq,si_buf,(EXAWORD)si_lng)); 

		/* DELETE KEY */
		/* ---------- */
		case 0x202A : return(Sqlsi_delete(fidreel,si_cle,(EXABYTE)si_mq));
		case 0x207F : return(Sqlmc_delete(fidreel,si_cle,(EXABYTE)si_mq));
		case 0x217F : return(Sqlbf_delete(fidreel,si_cle,(EXABYTE)si_mq)); 

		/* MODIFY ART/MQ */
		/* ------------- */
		case 0x20A6 : return(Sqlsi_modif(fidreel,si_cle,(EXABYTE)si_mq,si_buf,(EXAWORD)si_lng));
		case 0x20A7 : return(Sqlmc_modif(fidreel,si_cle,(EXABYTE)si_mq,si_buf,(EXAWORD)si_lng));
		case 0x21A7 : return(Sqlbf_modif(fidreel,si_cle,(EXABYTE)si_mq,si_buf,(EXAWORD)si_lng)); 


		/* SEARCH KEY/MQ */
		/* ------------- */
		case 0x2066 :
		case 0x2062 : return(error74(si_flg,Sqlsi_search(fidreel, (EXAWORD)si_ver, (EXAWORD)si_flg, si_cle, (EXABYTE)si_mq, si_buf, (EXAWORD)si_lng)));
		case 0x2053 :
		case 0x2057 : return(error74(si_flg,Sqlmc_search(fidreel, (EXAWORD)si_ver, (EXAWORD)si_flg, si_cle, (EXABYTE)si_mq, si_buf, (EXAWORD)si_lng)));
		case 0x2157 :
		case 0x2153 : return(error74(si_flg,Sqlbf_search(fidreel, (EXAWORD)si_ver, (EXAWORD)si_flg, si_cle, (EXABYTE)si_mq, si_buf, (EXAWORD)si_lng)));

		/* DOWN Ctrl MQ  */
		/* ------------  */
		case 0x206E :
		case 0x206A : return(error74(si_flg,Sqlsi_down(fidreel,(EXAWORD)si_ver,(EXAWORD)si_flg,(EXABYTE)si_mq,si_buf,(EXAWORD)si_lng)));

		case 0x206F :
		case 0x206B : return(error74(si_flg,Sqlmc_down(fidreel,(EXAWORD)si_ver,(EXAWORD)si_flg,(EXABYTE)si_mq,si_buf,(EXAWORD)si_lng)));

		case 0x216F :
		case 0x216B : return(error74(si_flg,Sqlbf_down(fidreel,(EXAWORD)si_ver,(EXAWORD)si_flg,(EXABYTE)si_mq,si_buf,(EXAWORD)si_lng)));

		/* UP   Ctrl MQ  */
		/* ------------  */
		case 0x2076 :
		case 0x2072 : return(error74(si_flg,Sqlsi_up(fidreel,(EXAWORD)si_ver,(EXAWORD)si_flg,(EXABYTE)si_mq,si_buf,(EXAWORD)si_lng)));
		case 0x2077 :
		case 0x2073 : return(error74(si_flg,Sqlmc_up(fidreel,(EXAWORD)si_ver,(EXAWORD)si_flg,(EXABYTE)si_mq,si_buf,(EXAWORD)si_lng)));
		case 0x2177 :
		case 0x2173 : return(error74(si_flg,Sqlbf_up(fidreel,(EXAWORD)si_ver,(EXAWORD)si_flg,(EXABYTE)si_mq,si_buf,(EXAWORD)si_lng)));

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
	tlo = *(bptr+16);
	thi = *(bptr+17);
	taille = (((EXAWORD)thi) << 8) | ((EXAWORD) tlo);

	/* Recupere le type de la rubrique fille */
	type = (*(bptr+18) == 0) ? 0 : 1;

	/* Cree la description dans le fichier */
	if (errno = (int)Sqlmc_ckey(hfic,(BPTR)bptr,(EXAWORD)taille,(EXAWORD)type))
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
	if (errno=(int)Sqlmc_nkey(hfic,(BPTR)bptr,(BPTR)bptr+19))
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
	tlo = *(bptr+16);
	thi = *(bptr+17);
	taille = (((EXAWORD)thi) << 8) | ((EXAWORD) tlo);

	/* Recupere l'offset de la rubrique fille par rapport a
	 * la rubrique mere.
	 */
	tlo = *(bptr+35);
	thi = *(bptr+36);
	offset = (((EXAWORD)thi) << 8) | ((EXAWORD) tlo);

	/* Recupere le type de la rubrique fille */
	type = (*(bptr+18) == 0) ? 0 : 1;

	/* Cree la description dans le fichier */
	if (errno = (int)Sqlmc_fkey(hfic,(BPTR)bptr,(BPTR)bptr+19,taille,type,offset))
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
	if (bptr == (BPTR)NULL) { errno=89; return((EXALONG)-1); }

	/* Aiguille vers une creation/suppression de lien
	 * selon le cas.
	 */
	if ((mode & 0x0008) == 0) {
		/* Lien a creer */
		if (errno = (int)Sqlmc_dcndx(hfic,bptr,blen))
			return((EXALONG)-1);
	}
	else {
		/* Lien a supprimer */
		if (errno = (int)Sqlmc_ddndx(hfic,bptr,blen))
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
	/* Aiguille vers une creation/suppression/mise a jour de lien(s)
	 * selon le cas.
	 */
	if ((mode & 0x0001) == 0) {
		/* Mettre a jour tous les liens */
		if (errno=(int)Sqlmc_updndx(hfic)) return((EXALONG)-1);
	}
	else {
		if ((mode & 0x0008) == 0) {
			/* Lien a creer */
			if (errno=(int)Sqlmc_cndx(hfic,bptr,blen)) return((EXALONG)-1);
		}
		else {
			/* Lien a supprimer */
			if (errno=(int)Sqlmc_dndx(hfic,bptr,blen)) return((EXALONG)-1);
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

	/* Determine s'il s'agit de la premiere rubrique ou de
	 * la rubrique suivante.
	 */
	type = ((mode & 0x0020) == 0) ? 1 : 0;

	/* Appelle la fonction appropriee */
	if (errno=(int)Sqlmc_lkey(hfic,bptr,blen,type)) return((EXALONG)-1);

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

	/* Determine s'il s'agit du premier lien ou
	 * du lien suivant.
	 */
	type = ((mode & 0x0020) == 0) ? 1 : 0;

	/* Appelle la fonction appropriee */
	if (errno=(int)Sqlmc_lndx(hfic,bptr,blen,type)) return((EXALONG)-1);
		
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
	if (errno = (int)Sqlmc_info(hfic,bptr,blen)) return((EXALONG)-1);
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
#ifdef RT_AIX
		errno=(int)Sqlmc_posit(hfic,bptr,FlagUnique,FlagSeq,TypePos,blen,(WPTR)&compte);
		if (errno != 0)
		   return((EXALONG)-1);
#else
		if (errno=(int)Sqlmc_posit(hfic,bptr,FlagUnique,FlagSeq,TypePos,blen,(WPTR)&compte))
			return((EXALONG)-1);
#endif

	}
	else {
		/* Denombrement */
#ifdef RT_AIX
		errno=(int)Sqlmc_count(hfic,bptr,FlagUnique,FlagSeq,blen,(EXALONG PTR)&lcompte);
		if (errno != 0)
			return((EXALONG)-1);
#else
		if (errno=(int)Sqlmc_count(hfic,bptr,FlagUnique,FlagSeq,blen,(EXALONG PTR)&lcompte))
			return((EXALONG)-1);
#endif
	}

	/* Retourne le nombre de reponses */
	if ((mode & 0x0080) == 0)
		return((EXALONG)compte);
	else
		return(lcompte);
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
	tlo = *(bptr+16);
	thi = *(bptr+17);
	taille = (((EXAWORD)thi) << 8) | ((EXAWORD) tlo);

	/* Recupere le type de la rubrique fille */
	type = (*(bptr+18) == 0) ? 0 : 1;

	/* Cree la description dans le fichier */
	if (errno=(int)Sqlbd_ckey(hfic,(BPTR)bptr,taille,type)) return((EXALONG)-1);
	return((EXALONG)0);
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
	if (errno=(int)Sqlbd_nkey(hfic,(BPTR)bptr,(BPTR)bptr+19)) return((EXALONG)-1);

	return((EXALONG)0);
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
	tlo = *(bptr+16);
	thi = *(bptr+17);
	taille = (((EXAWORD)thi) << 8) | ((EXAWORD) tlo);

	/* Recupere l'offset de la rubrique fille par rapport a
	 * la rubrique mere.
	 */
	tlo = *(bptr+35);
	thi = *(bptr+36);
	offset = (((EXAWORD)thi) << 8) | ((EXAWORD) tlo);

	/* Recupere le type de la rubrique fille */
	type = (*(bptr+18) == 0) ? 0 : 1;

	/* Cree la description dans le fichier */
	if (errno=(int)Sqlbd_fkey(hfic,(BPTR)bptr,(BPTR)bptr+19,taille,type,offset)) return((EXALONG)-1);

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
		if (errno = (int)Sqlbd_dcndx(hfic,bptr,blen)) return((EXALONG)-1);
	}
	else {
		/* Lien a supprimer */
		if (errno=(int)Sqlbd_ddndx(hfic,bptr,blen)) return((EXALONG)-1);
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

	/* Aiguille vers une creation/suppression/mise a jour de lien(s)
	 * selon le cas.
	 */
	if ((mode & 0x0001) == 0) {
		/* Mettre a jour tous les liens */
		if (errno=Sqlbd_updndx(hfic)) return((EXALONG)-1);
	}
	else {
		if ((mode & 0x0008) == 0) {
			/* Lien a creer */
			if (errno=(int)Sqlbd_cndx(hfic,bptr,blen)) return((EXALONG)-1);
		}
		else {
			/* Lien a supprimer */
			if (errno=(int)Sqlbd_dndx(hfic,bptr,blen)) return((EXALONG)-1);
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
	if (errno=(int)Sqlbd_join(hfic,bptr,blen)) return((EXALONG)-1);

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
	if (errno=(int)Sqlbd_cjoin(hfic,bptr,blen,(EXAWORD)(mode & 0x0001))) return((EXALONG)-1);

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
	if (errno=(int)Sqlbd_djoin(hfic,(BPTR)&NameZ[0])) return((EXAWORD)-1);
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
	if (errno=(int)Sqlbd_rjoin(hfic,bptr,(EXAWORD)32)) return((EXALONG)-1);
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
		if (errno=(int)Sqlbd_posit(hfic,bptr,FlagUnique,FlagSeq,TypePos,blen,(WPTR)&compte)) return((EXALONG)-1);
	}
	else {
		/* Denombrement */
		if (errno=(int)Sqlbd_count(hfic,bptr,FlagUnique,FlagSeq,blen,(EXALONG PTR)&lcompte)) return((EXALONG)-1);
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
	if (errno = (int)Sqlbd_updown(hfic,sens,lock,(WPTR)&nmarq,bptr,blen)) {
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
		if (errno=(int)Sqlbd_info(hfic,bptr,blen)) return((EXALONG)-1);
	}
	else {
		/* Statistiques sur un fichier de la base */
		if (errno=(int)Sqlbf_info(hfic,bptr,blen)) return((EXALONG)-1);
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

	/* Appelle la fonction appropriee */
	if (errno=(int)Sqlbd_lkey(hfic,bptr,blen,type)) return((EXALONG)-1);

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

	/* Appelle la fonction appropriee */
	if (errno = (int)Sqlbd_llink(hfic,bptr,blen,type)) return((EXALONG)-1);

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

	/* Appelle la fonction appropriee */
	if (errno=Sqlbd_lfile(hfic,bptr,blen,type)) return((EXALONG)-1);

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

	/* Appelle la fonction appropriee */
	if (errno=(int)Sqlbd_ljoin(hfic,bptr,blen,type)) return((EXALONG)-1);

	return((EXALONG)0);
}



#include "exngf.h"

/*
 *	M C _ K E Y ( nlog , mode , bptr , blen , func )
 *	------------------------------------------------
 *	Aiguilleur des fonctions de l'intersection entre
 *	multicritere et la base de donnees excluent des fonctions
 *	dans l'intersection avec sequentiel indexe
 */

EXALONG	mc_key( nlog , mode , bptr , blen , func, pvarid )
EX_FILE_HANDLE	nlog;	/* Numero logique fichier multicritere ou base 	*/
EXAWORD	mode;		/* Option suplimentaire de descriptor		*/
BPTR	bptr;		/* Pointer sur descripteur			*/
EXAWORD	blen;		/* Longeur de descripteur			*/
EXAWORD	func;		/* Code Fonction Type SF Amenesik / Sologic		*/
EXAWORD	pvarid;		/* Variable Descriptor for COLLECT result	*/
{
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
		case	0x21BF	: return(BD_rjoin((func & 0x00FF),nlog,bptr,(bptr + 17),mode));

		/* Denombrement+Positionnement 	*/
		/* --------------------------- 	*/
		case	0x22AB	: /* Collect From Top */
		case	0x22B3	: /* Collect From End */
			return(MC_collect(func,nlog,bptr,blen,mode,pvarid));

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




#endif	/* _EXAAIGSQL_C */
	/* ---------- */









