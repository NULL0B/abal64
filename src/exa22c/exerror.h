/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987, 1992  Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXERROR - H				*/
/*		Version :	2.1a					*/
/*		Date 	:	04/08/1992				*/
/*									*/
/*----------------------------------------------------------------------*/

#ifndef	_EXERROR_H	/* if not already included	*/
#define	_EXERROR_H	/* Avoid multiple inclusions	*/

/*
 *	Definition of Amenesik / Sologic Error codes
 *	----------------------------------
 */

#define		ABAL_SUCCESS	0

#define		EXER_DEVFAIL	1
#define		EXER_DEVRDWR	2
#define		EXER_DEVPOSN	3
#define		EXER_DEVDESC	4
#define		EXER_DEVPROT	5
#define		EXER_PARAM	20
#define		EXER_TACHE22	22
#define		EXER_TACHEWOT	23
#define		EXER_TACHE24	24
#define		EXER_TACHE25	25
#define		EXER_MEMFULL	27
#define		EXER_MEMADR	28
#define		EXER_MEMOWN	29
#define		EXER_SYNTAX	30
#define		EXER_PERIPH	31
#define		EXER_NUMUNIT	32
#define		EXER_BINAIRE	36
#define		EXER_PROG2BIG	38
#define		EXER_FILEWOT	40
#define		EXER_FILEDE	41
#define		EXER_FILECL	42
#define		EXER_FILEEO	43
#define		EXER_FILEDO	44
#define		EXER_FILE18	45
#define		EXER_VOLFULL	46
#define		EXER_MOTPASS	47
#define		EXER_FILEFIN	48
#define		EXER_REPFULL	49
#define		EXER_NUMLOG	50
#define		EXER_LOGFULL	51
#define		EXER_ADRSECT	53
#define		EXER_FORMVOL	54
#define		EXER_FUNCWOT	55
#define		EXER_CONFWOT	56
#define		EXER_FORBID	58
#define		EXER_TYPEFICH	60
#define		EXER_REK2BIG	62
#define		EXER_REK2SMA	63
#define		EXER_FICHDEB	64
#define		EXER_CLE2SMA	70
#define		EXER_CLE2BIG	71
#define		EXER_FICHTROP	72
#define		EXER_MARQZERO	73
#define		EXER_CLEBLOQUE	74
#define		EXER_CLEFULL	75
#define		EXER_CLEMESS	76
#define		EXER_DATAFULL	77
#define		EXER_CLEWOT	78
#define		EXER_CLEMARQ	79
#define		EXER_CLEOFLOW	80
#define		EXER_CLEDEJA	81
#define		EXER_CLESIZE	82
#define		EXER_MCWOT	83
#define		EXER_MCTROP	84
#define		EXER_DICMESS	85
#define		EXER_RUBTROP	86
#define		EXER_RUBDEJA	87
#define		EXER_RUBWOT	88
#define		EXER_RUBFOIS	89
#define		EXER_LIENWOT	90
#define		EXER_MC2BIG	91
#define		EXER_DICDATA	92
#define		EXER_MCFUNC	93
#define		EXER_MCDESC	94
#define		EXER_MCFIN	96
#define		EXER_MCMESS	97
#define		EXER_MCSIZE	98
#define		EXER_VALWOT	99
#define		EXER_JOIN	175

/*
 *	B.A.L.   /  A.B.A.L.   Specific error codes
 *	-------------------------------------------
 *
 */

#define		ABAL_ERRSEGM	100
#define		ABAL_FINDATA	101
#define		ABAL_NDXZERO	102
#define		ABAL_NDX2BIG	103
#define		ABAL_STR4NUM	104
#define		ABAL_RETNOGSB	105
#define		ABAL_BCD2LONG	106
#define		ABAL_GSB2MANY	107
#define		ABAL_NUM2BIG	108
#define		ABAL_TCODFILE	109
#define		ABAL_BCDFORM	110
#define		ABAL_ASKID	111
#define		ABAL_FORMAT	112
#define		ABAL_VAR2BIG	113
#define		ABAL_MEMORY	114
#define		ABAL_TCODCODE	115
#define		ABAL_NUMLOG116	116
#define		ABAL_NUMLOG117	117
#define		ABAL_NOVAREXT	118
#define		ABAL_NUMLOG119	119
#define		ABAL_WRITPROT	120
#define		ABAL_NOFILENAME	121
#define		ABAL_BUF2SMALL	122
#define		ABAL_RESNOTRAP	123
#define		ABAL_RESNONEED	124
#define		ABAL_MCNOTPOSS	125
#define		ABAL_OPNOTPOSS	126
#define		ABAL_EXTVARBER	127

/*
 *	Codes d'erreur ABAL exclusive	(Pas encore normalisee !)
 *	-----------------------------	-------------------------
 */

#define		ABAL_PROCARG	128	/* Variable n'est pas permise d'etre
					 * un arguament de procedure
					 */

#define		ABAL_ARGTYPE	129	/* Variable types do not match :
					 * during appel procedure
					 */

#define		ABAL_PROCERR	130	/* Instruction illegal pedant
					 * l'execution d'un procedure
					 */

#define		ABAL_PRCMAX	131	/* Numero de procedure incorrect
					 */

#define		ABAL_PRCMESS	132	/* Debordement de table des variables
					 * du procedure pendant passage des
					 * parametres
					 */

#define		ABAL_NEGARG	133	/* Arguament de longeur / coupure
					 * pour une fonction chaine ne peut
					 * pas etre negative !
					 */

#define		ABAL_NOLOCK	134	/* Plus de lock systemes disponible 
					 * lors d'un ouerture ou creation
					 * d'un fichier sous Unix
					 */

#define		ABAL_FUSEFAIL	135	/* User Library not initialised
					 * when library function called
					 * Usually indicates incorrect
					 * library initialisation during
					 * initialisation of T-Code
					 */
  
/*
 *	Structure de Gestion des erreurs
 *	--------------------------------
 */

#define	ERRORPTR struct errform SPTR

struct errform {
	EXAWORD	err_adr;		/* Adresse d'erreur		*/
	EXAWORD	err_trp;		/* Adresse du piege d'erreur	*/
	EXAWORD	err_var;		/* Pointeur de variable d'erreur*/
	EXAWORD	err_ind;		/* Index de variable d'erreur	*/
	EXAWORD	err_and;		/* Andex de variable d'erreur	*/
	EXAWORD	err_reg;		/* Register for Reg Var's	*/
	EXAWORD	 err_flg;		/* Status of ON ERROR Goto	*/
	ERRORPTR previous;		/* Previous saved error trap	*/
};

#endif	/* _EXERROR_H */
	/* ---------- */

