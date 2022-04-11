/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	TCODE2 - H				*/
/*		Version :	1.4c / 2.1a				*/
/*		Date 	:	19/04/1993				*/
/*									*/
/*----------------------------------------------------------------------*/

#ifndef	EXTCODE2H	/* if not already included	*/
#define	EXTCODE2H	/* Avoid multiple inclusions	*/

/*	Structure du premier BLOC du fichier traduit -T			*/
/*	-----------------------------------------------			*/

EXABYTE	trad_ver;		/* Version de Traducteur   	00	*/
EXABYTE	trad_ind;		/* Indice Traducteur     	01	*/
EXABYTE	trad_typ;		/* Marquer ABAL ='2'     	02	*/
EXABYTE	trad_nom[15];		/* Nom du fichier source 	03	*/
EXABYTE	trad_opt;		/* Options de traducteur	12
				   Bit 0	Debug / Nodebug
				   Bit 1	Clear / Noclear
				   Bit 2	Commande initial ou pas 
				   Bit 3	Vidange de clavier EXIT */
EXABYTE	trad_perm;		/* Permissions de la Traducteur	13
				   Bit 7	Executable Oui/Non	*/

#ifndef	ABAL_RTL
EXAWORD		adr_arg;	/* Adr Variable de reception Commande Init  14*/
EXAWORD		adr_tcg;	/* Adresse table constantes globales 16	*/
EXAWORD		lng_tcg;	/* Longeur de table 		18	*/

EXAWORD		adr_tvg;	/* Adr Table variable Globales 	1A	*/
EXAWORD		lng_tvg;	/* Longeur de table 		1C	*/

#ifdef	ABAL21
EXAWORD		meg_tfu;
#endif

EXAWORD		adr_tfu;	/* Adr de table fonctions utilisateur 1E */
EXAWORD		lng_tfu;	/* Longeur de table 		20	*/

EXAWORD		adr_tsg;	/* Adr table des segments	22	*/
EXAWORD		lng_tsg;	/* Longeur de table 		24	*/

EXAWORD		adr_tpr;	/* Adr table des procedures 	26	*/
EXAWORD		lng_tpr;	/* Longeur de table 		28	*/

EXAWORD		adr_npr;	/* Adr table des noms procedures 2A	*/
EXAWORD		l_max_vls;	/* Longeur max tables Var Local  2C	*/
EXAWORD		adr_usr;	/* Sector table fonctions USER	 	*/
EXAWORD		lng_usr;	/* Length of table fonctions USER	*/

	/* ---------- */
#endif	/* ! ABAL_RTL */
	/* ---------- */

/* 
 * These only concern the translator / Link editor
 * -----------------------------------------------
 * EXAWORD	tprocext	   Table external procedures	  2E	
 * EXAWORD	trelogvar	   Rellocation table of variables 30	
 * EXAWORD	trelogcon	   Rellocation table constants	  32	
 */

/*
 *	Executeur workspace control values
 *	----------------------------------
 *
 *	Directive	Default value
 *	
 *	#registers		50	
 *	#files			64
 *	#memtemp		2048 (octets)
 *	#stack			256  (levels)
 *	#local			256  (octets)
 */

EXAWORD		diezreg;	/* Maximum number of registers		*/
EXAWORD		diezfic;	/* Maximum number of files		*/
EXAWORD		dieztmp;	/* Maximum size of tempory workspace	*/
EXAWORD		diezstk;	/* Maximum Stack size			*/
EXAWORD		diezlds;	/* Maximum Local Variable Quick Alloc	*/

#ifdef	ABAL14
EXAWORD		diezmin;	/* Taille minimum des allocation malloc	*/
#endif	/* ABAL14 */

#ifdef	ABAL21
EXAWORD		DiezePageSize;	/* Extended Memory Page Size		*/
EXAWORD		DiezeSwapSize;	/* Swap Buffer Maximum Count		*/
EXAWORD		DiezeEtendu;	/* Extended Memory Options Flags	*/ 
#endif	/* ABAL21 */

EXAWORD		CompatibleBal;	/* Request for Strict BAL Compatible	*/

#endif	/* ! EXTCODE2H */
