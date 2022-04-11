
/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXMCBD - C				*/
/*		Date 	:	09/01/1989				*/
/*									*/
/*----------------------------------------------------------------------*/
/*	Medium Level interface with MC/BD/MCBD functions for UNIX	*/
/*----------------------------------------------------------------------*/
/* Replaces the ASM functions which interface with MC/BD under Amenesik / Sologic */
/* -------------------------------------------------------------------- */
/*									*/
/* MC_KEY(nlog,mode,bptr,blen,func)					*/
/*									*/
/* DBPREP(Offset,Fid,Bptr,Blen)						*/
/*									*/
/* ANAJOIN(Source,Destination)						*/
/*									*/
/* KILLJOIN(NomDuJointure)						*/
/*									*/
/*----------------------------------------------------------------------*/

#include "exngf.h"

/*
 *	M C _ K E Y ( nlog , mode , bptr , blen , func )
 *	------------------------------------------------
 *	Aiguilleur des fonctions de l'intersection entre
 *	multicritere et la base de donnees excluent des fonctions
 *	dans l'intersection avec sequentiel indexe
 */

EXALONG	mc_key( nlog , mode , bptr , blen , func )
EXAWORD	nlog;		/* Numero logique fichier multicritere ou base 	*/
EXAWORD	mode;		/* Option suplimentaire de descriptor		*/
BPTR	bptr;		/* Pointer sur descripteur			*/
EXAWORD	blen;		/* Longeur de descripteur			*/
EXAWORD	func;		/* Code Fonction Type SF Amenesik / Sologic		*/
{

	switch ( func ) {
#ifdef ABALMC
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
#ifdef ABALBD
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
#endif

		/* Denombrement+Positionnement 	*/
		/* --------------------------- 	*/
		case	0x20AB	: /* Premier 	*/
		case	0x20B3	: /* Dernier 	*/
			return(MC_interrog(func,nlog,bptr,blen,mode));
#ifdef ABALBD
		case	0x21AB	: /* Premier 	*/
		case	0x21B3	: /* Dernier 	*/
			return(BD_interrog(func,nlog,bptr,blen,mode));
#endif

		/* Interogation Sequentielle	*/
		/* -------------------------	*/
#ifdef ABALBD
		case	0x21EF	: /* Suivante + blocage */
		case	0x21EB	: /* Suivante		*/
		case	0x21F7	: /* Precedante + bloc	*/
		case	0x21F3	: /* Precedante		*/
				return(DB_updown(func,nlog,bptr,blen,si_mq));
#endif


		/* Statistiques	*/
		/* ------------ */
		case	0x207B	: /* Sur un Fichier MC        	*/
				return(MC_stat(func,nlog,bptr,blen,mode));
#ifdef ABALBD
		case	0x217B	: /* Sur un Fichier MC / BD	*/
		case	0x217A	: /* Sur la Base de donnees	*/
				return(BD_stat(func,nlog,bptr,blen,mode));

		/* Liste des Rubriques	*/
		/* -------------------	*/
		case	0x215B	: return(BD_lkey(func,nlog,bptr,blen,mode));

		/* Liste des Liens	*/
		/* ---------------	*/
		case	0x215F	: return(BD_llink(func,nlog,bptr,blen,mode));
#endif
		/* Liste des Rubriques	*/
		/* -------------------	*/
		case	0x205B	: return(MC_lkey(func,nlog,bptr,blen,mode));

		/* Liste des Liens	*/
		/* ---------------	*/
		case	0x205F	: return(MC_llink(func,nlog,bptr,blen,mode));
#ifdef ABALBD
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
#endif	/* IF ABALBD */
#endif  /* IF ABALMC */

		}
	errno = ABAL_OPNOTPOSS;
	return(-1);

}

#ifdef EVENBOUND
BPTR	Ptr2Long( Ptr )
BPTR  Ptr;
{
	return( Ptr );
}

#endif

/*
 *	D B P R E P ( offset , fid , ptr , length )
 *	-------------------------------------------
 *	Preparation de la descripteur des operation d'interogation
 *	sequentielle sur une base de donnees
 *
 */

EXAWORD	dbprep( bdex , fid , bptr , blen )
EXAWORD	bdex;
EXAWORD	fid;
BPTR	bptr;
EXAWORD	blen;
{
	EXAWORD	x;
#ifdef EVENBOUND
	EXALONG	AixBug;
	EXAWORD	AixShft;
#else
	BPTR	*bptrx;
#endif

	*(si_buf + bdex++) = (EXABYTE) fid;
#ifdef EVENBOUND
	AixBug = (EXALONG) Ptr2Long( bptr );
	AixShft = 0;
	while ( AixShft < (sizeof(EXALONG) * 8) ) {
		*(si_buf + bdex) = (EXABYTE) (( AixBug >> AixShft ) & 0xFFL);
		AixShft += 8; bdex++;
		}
#else
	bptrx = (BPTR*) ( si_buf + bdex);
	*(bptrx) = bptr;
	bdex += sizeof(BPTR);
#endif
	TcodePmot( (si_buf + bdex) , blen);
	x = (EXAWORD) *si_buf; x++;
	*si_buf = (EXABYTE) x;
	return(0);
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
{
	EXAWORD	x;
	EXAWORD	c;
	/* Mise en place du Numero de ressource a blanc */
	/* -------------------------------------------- */
	*(dptr++) = (EXABYTE) 0; *(dptr++) = (EXABYTE) 0; x = 15;

#ifdef	ABAL21
	memset( (BPTR) dptr, ' ', 15 );

	c = *(sptr + slen);
	*(sptr + slen) = 0;

	/* Extract Filename portion */
	/* ------------------------ */
	x = fn_parser((BPTR) sptr, (BPTR) dptr, 8 ); 		

	*(sptr + slen) = c;
	*(dptr + x) = ' ';
#else
	
	while (( x > 0 ) && ( slen> 0 )) {
		if (( *sptr == ' ' ) || ( *sptr == FILETERM )) 
			break;
		*(dptr++) = *(sptr++); x--; slen--;
		}
	while ( x > 0 ) { *(dptr++) = ' '; x--; }
#endif
	return(1);
}

/*
 *	K I L J O I N ( jnptr )
 *	-----------------------
 *	Supression d'une Jointure de la base de donnees
 *
 */

EXAWORD	killjoin( jnptr )
BPTR	jnptr;
{
#ifdef ABALBD
	/* Remarque : (jnptr+2) to avoid the ressource id */
	/* ---------------------------------------------- */
	return(BD_jdfile(0x2123,fidreel,(jnptr+2),0x0003));
#endif
}

#ifdef ABALMC
/*
 *	E X M C _ M A T B ( fngf , nlog , ex , cop )
 *	--------------------------------------------
 *
 *	Modification des attributs d'ouverture d'une ensemble
 *	multicriteres  (fichier MC et fichier SI ! )
 *
 *	Sortie :	0  	ok attributs modifies
 *		  MOINS_UN 	Erreur dans errno
 *	
 *	ATB=nlog(MC),[ EX ] , [ C ]
 *
 */

EXAWORD	exmc_matb( fngf , nlog , ex , cop )
EXAWORD	fngf,nlog,ex,cop;
{
	if ( MC_matb(fngf,nlog,0x0010,(ex == 0 ? 0x0010 : 0 )) != -1 ) {
		if ( MC_matb(fngf,nlog,0x0080,(cop == 0 ? 0 : 0x0080)) != -1 ) {
			return(0);
			}
		}
	return(MOINS_UN);
}
#endif	/* ABALMC */

#ifdef ABALBD
/*
 *	E X B D _ M A T B ( fngf , nlog , ex ,cop )
 *	--------------------------------------------
 *
 *	Modification des attributs d'ouverture d'une ensemble
 *	Base de Donnees (La Base , Les fichiers Multicriteres et SI)
 *	
 *	Sortie :	0  	ok attributs modifies
 *		   MOINS_UN	Erreur dans errno
 *	
 *	ATB=nlog(BD),[ EX ] , [ C ]
 *
 */

EXAWORD	exbd_matb( fngf , nlog , ex , cop )
EXAWORD	fngf,nlog,ex,cop;
{
	if ( BD_matb(fngf,nlog,0x0010,(ex == 0 ? 0x0010 : 0 )) != -1 ) {
		if ( BD_matb(fngf,nlog,0x0080,(cop == 0 ? 0 : 0x0080)) != -1 ) {
			return(0);
			}
		}
	return(MOINS_UN);
}

#endif	/* ABALBD */


/*
 *	A I G _ U N I X ( ngf_code )
 *	----------------------------
 *	Performs the switching / redirection function for all of
 *	the functions in the Intersection between MC and SI and BD
 *	(Uses Amenesik / Sologic SF codes to perform the switching)
 */

EXAWORD	aig_unix( ngf_code )
EXAWORD	ngf_code;
{
	EXAWORD	flgex,flgdf,flgcp,flgwr;
	EXAWORD	flgcad,flgvar;
	EXAWORD	mcperm;
	EXAWORD	ret_cod;

	/* Semaphore Code du Cadrage Des Cles */
	/* ---------------------------------- */
	flgcad = (fmtchk & 0x0006) >> 1;
	flgvar = (fmtchk & 0x0001);

	/* Semaphores des permissions fichier */
	/* ---------------------------------- */

	/* Assign EX */
	/* --------- */
	if ( fidperm & 0x0002 ) { flgex = 1; flgwr = 1; }
	else 			{ flgex = 0; flgwr = 0; }

	/* Assign C  */
	/* --------- */
	if ( fidperm & 0x0004 ) { flgcp = 1; }
	else 			{ flgcp = 0; }

	/* Assign DF */
	/* --------- */
	if ( fidperm & 0x0008 ) { flgdf = 1; }
	else 			{ flgdf = 0; }

	/* Assign WR */
	/* --------- */	
	if ( fidperm & 0x0001 ) { flgwr = 1; }

		
	/* Calcul de la Code d'operation */
	/* ----------------------------- */
	(void) simcprep(ngf_code);

	if (( fidperm & NGF_TYP ) != NGF_SI) {
		if (( ngf_code == _NGF_OPEN) || ( ngf_code == _NGF_CFILE )) {
			if ( flgex == 0 ) { simcbd |= 0x0008; }
			}
		mcperm = 0x0002; 	 mcperm |= (flgdf  << 2);
		mcperm |= (flgcp  << 5); mcperm |= (flgvar << 4);
		mcperm |= (flgcad << 6);
		}

	switch ( simcbd ) {

		/* CLOSE FILE */
		/* ---------- */

#ifdef ABALSI
		case 0x2026 : return(si_close(fidreel));
#endif

#ifdef ABALMC
		case 0x2027 : return(MC_close((simcbd & 0x00FF),fidreel));
#endif

#ifdef ABALBD
		/* Closure of a Data Base File */
		/* --------------------------- */
		case 0x2127 : 

		/* Closure of a Data Base Dictionary */
		/* --------------------------------- */
		case 0x2126 : return(BD_close((simcbd & 0x00FF),fidreel));

#endif

		/* OPEN FILE  */
		/* ---------  */
#ifdef ABALSI
		case 0x2036 : return(exsi_open(fidname,flgex,flgcp,flgwr));
#endif

#ifdef ABALMC
		case 0x203F :
		case 0x2037 : return(MC_open((simcbd & 0x00FF),fidname,mcperm));
#endif

#ifdef ABALBD
		case 0x213F :
		case 0x2137 : return(BD_fopen((simcbd & 0x00FF),dbreel,fidname,mcperm));
		case 0x2136 :
		case 0x213E : return(BD_open((simcbd & 0x00FF),fidname,mcperm));
#endif		

		/* RENAME FILE */
		/* ----------- */

#ifdef ABALSI
#ifdef UNIX
		case 0x202E : return(si_rename(fidname,workptr1));
#endif
#ifdef VMS
		case 0x202E : return(si_rename(fidreel,workptr1));
#endif
#endif
#ifdef ABALMC
		case 0x202F : return(MC_rename(fidname,workptr1));
#endif
#ifdef ABALBD
		case 0x212E : return(BD_rename(0x002E,fidname,workptr1));
		case 0x212F : return(BD_frename(0x002F,dbreel,fidname,workptr1));
#endif
		/* MODIFY ATRIBUTES */
		/* ---------------  */
#ifdef ABALSI
		case 0x201E : return(si_matb(fidreel,flgex,flgcp));
#endif

#ifdef ABALMC
		case 0x201F : return(exmc_matb((simcbd & 0x00FF),fidreel,flgex,flgcp));
#endif

#ifdef ABALBD
		case 0x211E : return(exbd_matb((simcbd & 0x00FF),fidreel,flgex,flgcp));
#endif		

		/* CREATE FILE */
		/* ----------- */
#ifdef ABALSI
		case 0x2032 : return(si_create(fidname,workval2,workval1,flgex,flgcp,flgcad,flgvar));
#endif

#ifdef ABALMC
		case 0x203B :
		case 0x2033 : return(MC_create((simcbd & 0x00FF),fidname,workval2,workval1,mcperm));
/*========================================================================*/
/*		case 0x2033 : return(MC_create(fidname,workval2,workval1,flgex,flgcp,flgcad,flgvar,flgdf)); */
/*========================================================================*/
#endif

#ifdef ABALBD
		case 0x213B :
		case 0x2133 : return(BD_cfile((simcbd & 0x00FF),dbreel,fidname,workval2,workval1,mcperm));
		case 0x213A :
		case 0x2132 : return(BD_create((simcbd & 0x00FF),fidname,mcperm));
#endif
		/* DELETE FILE */
		/* ----------- */
#ifdef ABALSI
		case 0x2022 : return(si_unlink(fidname)); 
#endif

#ifdef ABALMC
		case 0x2023 : return(MC_unlink((simcbd & 0x00FF),fidname));
#endif

#ifdef ABALBD
		case 0x2123 : return(BD_fdfile((simcbd & 0x00FF),dbreel,fidname,(fmtchk & 3)));
		case 0x2122 : return(BD_unlink((simcbd & 0x00FF),fidname));
#endif
		/* Fonctions Sequentielle Indexe */
		/* ----------------------------- */

		/* INSERT KEY */
		/* ---------- */
#ifdef ABALSI
		case 0x20A2 : return(si_insert(fidreel,si_cle,si_mq,si_buf,si_lng));
#endif

#ifdef ABALMC
		case 0x20A3 : return(MC_insert(fidreel,si_cle,si_mq,si_buf,si_lng));
#endif

#ifdef ABALBD
		case 0x21A3 : return(BD_insert(fidreel,si_cle,si_mq,si_buf,si_lng)); 
#endif
		/* DELETE KEY */
		/* ---------- */
#ifdef ABALSI
		case 0x202A : return(si_delete(fidreel,si_cle,si_mq));
#endif

#ifdef ABALMC
		case 0x207F : return(MC_delete(fidreel,si_cle,si_mq));
#endif

#ifdef ABALBD
		case 0x217F : return(BD_delete(fidreel,si_cle,si_mq)); 
#endif
		/* MODIFY ART/MQ */
		/* ------------- */
#ifdef ABALSI
		case 0x20A6 : return(si_modif(fidreel,si_cle,si_mq,si_buf,si_lng));
#endif

#ifdef ABALMC
		case 0x20A7 : return(MC_modif(fidreel,si_cle,si_mq,si_buf,si_lng));
#endif

#ifdef ABALBD
		case 0x21A7 : return(BD_modif(fidreel,si_cle,si_mq,si_buf,si_lng)); 
#endif
		/* SEARCH KEY/MQ */
		/* ------------- */
#ifdef ABALSI
		case 0x2062 : return(si_search(fidreel,si_ver,si_flg,si_cle,si_mq,si_buf,si_lng));
#endif

#ifdef ABALMC
		case 0x2053 : return(MC_search(fidreel,si_ver,si_flg,si_cle,si_mq,si_buf,si_lng));
#endif

#ifdef ABALBD
		case 0x2157 :
		case 0x2153 : return(BD_search(fidreel,si_ver,si_flg,si_cle,si_mq,si_buf,si_lng)); 
#endif
		/* DOWN Ctrl MQ  */
		/* ------------  */
#ifdef ABALSI
		case 0x206A : return(si_down(fidreel,si_ver,si_flg,si_mq,si_buf,si_lng));
#endif

#ifdef ABALMC
		case 0x206F :
		case 0x206B : return(MC_down(fidreel,si_ver,si_flg,si_mq,si_buf,si_lng));
#endif

#ifdef ABALBD
		case 0x216F :
		case 0x216B : return(BD_down(fidreel,si_ver,si_flg,si_mq,si_buf,si_lng));
#endif

		/* UP   Ctrl MQ  */
		/* ------------  */
#ifdef ABALSI
		case 0x2072 : return(si_up(fidreel,si_ver,si_flg,si_mq,si_buf,si_lng));
#endif

#ifdef ABALMC
		case 0x2077 :
		case 0x2073 : return(MC_up(fidreel,si_ver,si_flg,si_mq,si_buf,si_lng));
#endif

#ifdef ABALBD
		case 0x2177 :
		case 0x2173 : return(DB_up(fidreel,si_ver,si_flg,si_mq,si_buf,si_lng));
#endif

		default     : errno = ABAL_OPNOTPOSS; return(-1);
		}

}


/*
 *	S F _ I N I T ( )
 *	-----------------
 *	Initialisation de la table des Codes fonctions SF Amenesik / Sologic
 *
 */

void sf_init()
{
	simcode[0] = (EXABYTE) 0x32;
	simcode[1] = (EXABYTE) 0x22;
	simcode[2] = (EXABYTE) 0x2E;
	simcode[3] = (EXABYTE) 0x36;
	simcode[4] = (EXABYTE) 0x26;
	simcode[5] = (EXABYTE) 0x60;
	simcode[6] = (EXABYTE) 0xA0;
	simcode[7] = (EXABYTE) 0xA2;
	simcode[8] = (EXABYTE) 0xA6;
	simcode[9] = (EXABYTE) 0x2A;
	simcode[10] = (EXABYTE) 0x62;
	simcode[11] = (EXABYTE) 0x6A;
	simcode[12] = (EXABYTE) 0x72;
	simcode[13] = (EXABYTE) 0x1E;
	return;

}

