#ifndef	_ixconst_h
#define	_ixconst_h

#define	_USEIT_FOR_WHATEVER

/*
 *	fichiers standards
 *	------------------
 */

#undef	STDIN
#define STDIN	0

#undef	STDOUT
#define STDOUT	1

#undef	STDERR
#define STDERR	2

#ifndef	PUBLIC
#define	PUBLIC
#endif

#ifndef	PRIVATE
#define	PRIVATE static
#endif


/*
 *	constantes diverses
 *	-------------------
 */

#ifdef vms
#define ECR_CHEMIN			"SYS$MANAGER:"
#else
#define ECR_CHEMIN			"/usr/lib/cico"
#endif /* vms */

#define ECR_SIGNATURE			"CICO14"
#define ECR_LONGUEUR_SIGNATURE		6

#ifdef	_USEIT_FOR_WHATEVER
#define NEW_SIGNATURE			"CICO22"
#endif

#define ECR_LONGUEUR_ENTETE		20

#ifdef vms
#define IMP_TBL_CHEMIN			"SYS$MANAGER:"
#else
#define IMP_TBL_CHEMIN			"/usr/lib/tbl"
#endif /* vms */
#define IMP_TBL_SIGNATURE		"MP1"
#define IMP_TBL_LONGUEUR_SIGNATURE	3
#define IMP_TBL_EXTENSION		".tbl"
#define IMP_SEPARATEUR			','

#ifdef vms
#define ENV_SEPARATEUR			'|'
#else
#define ENV_SEPARATEUR			':'
#endif /* vms */
#define ENV_ECRAN			"CICO"
#define ENV_IMPRIMANTE			"LO"
#define ENV_LANGUE			"ABALANG"
#define ENV_LANGUE2			"LANG"

#ifdef SHAREDLO
#define ENV_SHAREDLO			"SHAREDLO"
#define ENV_RESETTERM			"ABALNORESET"
#endif

/*
 *	oublis de certains systemes
 *	---------------------------
 */

#ifndef O_SYNC
#define O_SYNC		0
#endif /* O_SYNC */

#ifndef SEEK_SET
#define SEEK_SET	0
#endif /* SEEK_SET */

#ifndef SEEK_CUR
#define SEEK_CUR	1
#endif /* SEEK_CUR */

#ifndef R_OK
#define R_OK		4
#endif /* R_OK */

#ifndef W_OK
#define W_OK		2
#endif /* W_OK */

#ifdef vms
#define F_SETFL 	0
#endif /* vms */

/*
 *	etats de l'automate de conversion en sortie sur un peripherique
 *	---------------------------------------------------------------
 */

#define ETAT_STANDARD		0	/* etat standard		*/
#define ETAT_ESCAPE		1	/* esc				*/
#define ETAT_POS_1		2	/* esc f			*/
#define ETAT_POS_2		3	/* esc f x			*/
#define ETAT_TRANS_1		4	/* esc T			*/
#define ETAT_TRANS_2		5	/* esc T low_BYTE		*/
#define ETAT_TRANS_3		6	/* esc T low_BYTE high_BYTE	*/
#define ETAT_DEFAUT		7	/* esc n			*/
#define ETAT_TEXTE		8	/* esc r			*/
#define ETAT_FOND		9	/* esc s			*/
#define ETAT_ESCAPE_ESCAPE	10	/* esc esc			*/
#define ETAT_Z_1		11	/* esc Z			*/
#define ETAT_Z_2		12	/* esc Z low_BYTE		*/
#define ETAT_QUICK		13	/* esc q         		*/
#define ETAT_VISUAL		100	/* esc (         		*/


/*
 *	definition des couleurs
 *	-----------------------
 */

#define FC_BLACK		0x00
#define FC_RED			0x01
#define FC_GREEN		0x02
#define FC_BROWN		0x03
#define FC_BLUE 		0x04
#define FC_MAGENTA		0x05
#define FC_CYAN 		0x06
#define FC_WHITE		0x07
#define FC_GREY 		0x08
#define FC_LIGHT_RED		0x09
#define FC_LIGHT_GREEN		0x0a
#define FC_YELLOW		0x0b
#define FC_LIGHT_BLUE		0x0c
#define FC_LIGHT_MAGENTA	0x0d
#define FC_LIGHT_CYAN		0x0e
#define FC_LIGHT_WHITE		0x0f

#define BC_BLACK		0x00
#define BC_RED			0x10
#define BC_GREEN		0x20
#define BC_BROWN		0x30
#define BC_BLUE 		0x40
#define BC_MAGENTA		0x50
#define BC_CYAN 		0x60
#define BC_GREY 		0x70
#define BC_BLINK		0x80


/*
 *	conversion en cours sur un peripherique
 *	---------------------------------------
 */

#define NO_CASE 	0xFF		/* pas de transcodage	*/
#define UPPER_CASE	0		/* en majuscule 	*/
#define LOWER_CASE	1		/* en minuscule 	*/


/*
 *	accent en cours de traitement en entree au clavier
 *	--------------------------------------------------
 */

#define NO_ACCENT	-1		/* pas d'accent en attente      */

#endif	/* _ixconst_h */

