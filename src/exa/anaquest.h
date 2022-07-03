/*----------------------------------------------------------------------*/
/*                                                                      */
/*            E X E C U T E U R 	A . B . A . L                   */
/*            -----------------------------------                       */
/*                                                                      */
/*	    Copyright (c) 1987,1997 Amenesik / Sologic			*/
/*                                                                      */
/*      Module  :	ANAQUEST - H                                    */
/*      Version :	5.1a                                            */ 
/*      Date 	:	19/10/2022                                      */
/*                                                                      */
/*       Analyse syntaxique du nouveau posit  - header                  */
/*----------------------------------------------------------------------*/

#ifndef _ANAQUEST_H
#define _ANAQUEST_H

/*----------------------------------------------*/
/*            INCLUDING FILES                   */
/*----------------------------------------------*/
#ifndef ABAL21
/*
#include <windows.h>
#include "crglobal.h"
#include "dbapic.h"
#include <string.h>
#include <stdlib.h>
*/

#else
/* Fichiers d'entete pour ABAL */
#include "ex.h"
#include "extypes.h"
#include "allocate.h"
#include "exwork.h"
#include "exngf.h"
#include "exfich.h"

#endif

/*----------------------------------------------*/
/*            TYPES DEFINITION                  */
/*----------------------------------------------*/
#ifdef ABAL21
/* Redefinition des types*/


/* Pour PROLOGUE*/
#ifdef PROLOGUE3
#ifndef NULL
#define NULL	((void *)0)
#endif
#endif

#ifndef U8
#define U8 EXABYTE
#endif

#ifndef S8
#define S8 EXABYTE
#endif

#ifndef U8PTR
#define U8PTR BPTR
#endif

#ifndef U16
#define U16 EXAWORD
#endif

#ifndef S16
#define S16 BINAIRE
#endif

#ifndef U16PTR
#define U16PTR EXAWORD PTR PTR
#endif

#ifndef S16PTR
#define S16PTR BINAIRE PTR
#endif

#ifndef U32
#define U32 ULONG
#endif

#ifndef U32PTR
#define U32PTR LPTR
#endif

#ifndef U64
#define U64 unsigned long long 
#endif

#ifndef U64PTR
#define U64PTR U64 PTR
#endif

/* CR_COL_CHAR : no conversion	for representation			*/
#define CR_COL_CHAR	0x0000		/* Abal Type : $		*/
#define CR_COL_STRING	0x0001		/* SQL  Type : $		*/
#define CR_COL_FLOAT 	0x0002		/* SQL  Type : Float		*/

/* CR_COL_DECI : decimal (1 to 23 digits)				*/
/*		binary representation : Cf document			*/
#define CR_COL_TIME	0x0003		/* Abal Time : $=3		*/
#define CR_COL_DECI	0x0004		/* Abal Type : BCD		*/

/* CR_COL_DATE : date							*/
/*		binary representation : YYYYMMDD   			*/
#define CR_COL_DATE	0x0005		/* Abal Type : $		*/

/* CR_COL_LONG : long							*/
#define CR_COL_LONG	0x0006		/* Abal Type : :		*/

/* CR_COL_HUGE : long							*/
#define CR_COL_HUGE	0x0007		/* Abal Type : &		*/
/*... to be completed				*/

#endif


/*----------------------------------------------*/
/* 		Constants definition	 	*/
/*----------------------------------------------*/
#ifdef ABAL21 
#define FNT_LOC	static
#endif

/* Token Types			*/
#define ANA_TOK_COL		1   		/* Operator			*/
#define ANA_TOK_OPE		2		/* What the ...			*/
#define ANA_TOK_VAL		3		/* binary value			*/
#define ANA_TOK_OBR		4		/* open bracket			*/
#define ANA_TOK_CBR		5		/* close bracket		*/


/* Relational operators		*/
#define ANA_OPR_EQ		6		/*	equal			*/
#define ANA_OPR_G		7		/*	great			*/
#define ANA_OPR_GE		8		/*	great or equal		*/
#define ANA_OPR_L		9		/*	smaller			*/
#define ANA_OPR_LE		10		/*	smaller or equal	*/
#define ANA_OPR_BT		11		/*	between			*/
#define ANA_OPR_NBT		26		/*  	not between		*/
#define ANA_OPR_NE		12		/*	not equal		*/
#define ANA_OPR_LIKE		27		/*  	like			*/
#define ANA_OPR_NLIKE		28		/*  	not like		*/
#define ANA_OPR_ESCAPE		29		/*	escape			*/

/* Logical operators		*/
#define ANA_OPL_AND		13		/*	And  			*/
#define ANA_OPL_OR 		14		/*	Or   			*/
#define ANA_OPL_NOT		15		/*	Not  			*/

/* End Of File 			*/
#define ANA_EOF			16		/*	End of file 		*/


/* Nouveautes! 			*/
#define ANA_OPL_UN		17		/*	Unitary operator 	*/
#define ANA_OPL_BIN		18		/*	Binary operator  	*/

#define ANA_KEY_WH		19		/*	Keyword WHERE 	 	*/
#define ANA_KEY_ORDER		20		/*	Keyword ORDER 	 	*/
#define ANA_KEY_BY		21		/*	Keyword BY 	 	*/
#define ANA_TOK_CO		22		/*	Commas 			*/

#define VAL			23		/*	Numerical Value  	*/
#define VAL2			24		/*	Alphanumerical Value 	*/
#define RUB			25		/*	Column			*/   

/* Errors traitments : EXA values */
#ifndef ABAL21
#define EXER_MCFUNC		93		/* Mismatched token 		*/
#define EXER_MCSIZE		98		/* Inexistant column 		*/
#define EXER_VALWOT		99		/* Numerical value incorrect 	*/
#define EXER_MEMFULL		27		/* Memory full 			*/
#endif

#define	EXER_MCOLDMETHOD	100		/* Old method quest : doesn't start whith WHERE */

#define	MAX_VALUE_SIZE		256		/* maximum size d'une valeur de critere	*/

/* Structure used as parameter */
typedef struct PARAM2{
	U16 Curlex;    	/* current token read by the lexical analyser */
	U8PTR Lign;    	/* Sentence to be analysed */
	U16 LignLength;	/* Length of the sentence to analyse	*/
	U16 Pos ;    	/* Index position in lign */
	U16 Pos0 ; 	/* Token beginning position */
	U16 Flag; 	/* if first time we pass in syntaxical analysis Flag = 1 if second time Flag = 2 */
#ifdef ABAL21	
	U16 FlagCount;	/* = 0 if anaquest called for a COUNT = 1 if called for a POSIT */
#else
	U32PTR Hdl;	/* handle of the loading file or DB */
#endif
    	/* Descriptor caracteristics */
	U16 DescLength;		/* length of the descriptor */
	U16 DescPos;		/* Current Position in the descriptor */
	U8PTR DescPtr;		/* Descriptor */

	/* Quest caracteristics */                                          
	U8 QuestType;		/* Quest Type : 1 -> WHERE CLAUSE 3 -> WHERE + ORDER BY CLAUSES */
	U16 QuestTypePos; 	/* Quest Type Position in the descriptor */

	/* Clause ( where or order by ) caracteristics */
	U16 ClauseLength; 	/* Clause Length */
	U16 ClauseLengthPos; 	/* Clause length Position in the descriptor */

	U16 Debut  ;		/* Beginning state of the current lexical diagramm */
	U16 Etat   ;    	/* Current state used in the lexical diagram */
	U8 Car	;		/* Current character read in the command lign */

	/* Current column caracteristics */
	U8 ColName[MAX_TABLE_NAME_LEN_EXT+1+MAX_RUB_NAME_LEN_EXT+1];		/* name of the column */
	U16 ColLength;		/* length of the column */
	U16 ColDecLength; 	/* Length of the column decimal part */
	U16 ColType;		/* Type of the column */

	/* Current operator caracteristics */
	U16 CurCompVal;		/* Type of the current operator (= or <> or ...) */

	/* Current value caracteristics */
	U8 CurVal[MAX_VALUE_SIZE+1]; 	/* Current value */
	U16 ValLength;		/* Length of the current value */
	U16 ValBytes;		/* Nb bytes in the Abal Descriptor for the current value */

	/* LIKE clause caracteristics */
	U8 EscBool;		/* 0 -> no ESCAPE in the LIKE clause 1 -> ESCAPE in  the LIKE clause */
	U8 EscVal[MAX_VALUE_SIZE+1];		/* Escape value */
	U8 EscChar;		/* Escape Character for a LIKE clause */

	U8 CoteType;		/* Cotes type in an alphanumerical value ( ' or " ) */

} PARAM;

/*----------------------------------------------*/
/* 		Macros definition		*/
/*----------------------------------------------*/

/* Definition de isalpha, isdigit, isalnum */
#define isalpha2(c) ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c=='_') || (c=='*'))
#define isnum2(c)   ((c >= '0' && c <= '9'))
#define isdigit2(c) (isnum2(c) || (c == '.') || (c == '-'))
#define isalnum2(c) (isalpha2(c) || isdigit2(c))

/*
#ifdef ABAL21
#define MY_atoi	 exatoi
#define MY_atol	 exatol
#endif
*/

/* Prototypes des fonctions */
#ifdef RT_AIX

S16 NPos_Synt();

FNT_LOC S16 NPos_Quest();
FNT_LOC S16 NPos_Where_Clause();
FNT_LOC S16 NPos_Order_Clause();

FNT_LOC S16 NPos_Expression();
FNT_LOC S16 NPos_Reste_Expression();
FNT_LOC S16 NPos_Critere();
FNT_LOC S16 NPos_Not_Critere ();
FNT_LOC S16 NPos_Between_Exp ();
FNT_LOC S16 NPos_Like_Exp ();
FNT_LOC S16 NPos_End_Like_Exp ();
FNT_LOC S16 NPos_Rubrique();
FNT_LOC S16 NPos_Ope_Binaire();
FNT_LOC S16 NPos_Value();
FNT_LOC S16 NPos_Value2();
FNT_LOC S16 NPos_Value3();
FNT_LOC S16 NPos_EscChar();
FNT_LOC S16 NPos_Comparateur();
#ifdef ABAL21
FNT_LOC S16 NPos_L_Rubrique();
FNT_LOC S16 NPos_Reste_L_Rubrique();
EXAWORD NewAnalyseSyntaxique();
#endif

FNT_LOC S16 NPos_Lire ();
FNT_LOC S16 NPos_Lex ();
FNT_LOC U8 NPos_NextCar ();
FNT_LOC U8 NPos_PrevCar ();
FNT_LOC void NPos_GoBack();
FNT_LOC U8 NPos_IsEndOfLine();
FNT_LOC S16 NPos_Echec();

FNT_LOC S16 NPos_CreateTokOp ();
FNT_LOC S16 NPos_CreateTokVal ();
FNT_LOC S16 NPos_CreateTokVal3 ();

FNT_LOC U16 MY_strcmp2 ();
FNT_LOC S16 NPos_NewLength ();

#else		/* RT_AIX */
 

#ifndef ABAL21
S16 NPos_Synt(U8PTR, U8PTR *, U16PTR, U16, U32PTR);
#else
S16 NPos_Synt(U8PTR, U8PTR *, U16PTR, U16, U16);
#endif

FNT_LOC S16 NPos_Quest(PARAM *, S16PTR);
FNT_LOC S16 NPos_Where_Clause(PARAM *, S16PTR);
FNT_LOC S16 NPos_Order_Clause(PARAM *, S16PTR);

FNT_LOC S16 NPos_Expression(PARAM *, S16PTR);
FNT_LOC S16 NPos_Reste_Expression(PARAM *, S16PTR);
FNT_LOC S16 NPos_Critere(PARAM *, S16PTR);
FNT_LOC S16 NPos_Not_Critere (PARAM *, S16PTR);
FNT_LOC S16 NPos_Between_Exp (PARAM*, S16PTR);
FNT_LOC S16 NPos_Like_Exp (PARAM *, S16PTR);
FNT_LOC S16 NPos_End_Like_Exp (PARAM *, S16PTR);
FNT_LOC S16 NPos_Rubrique(PARAM *, S16PTR);
FNT_LOC S16 NPos_Ope_Binaire(PARAM *, S16PTR);
FNT_LOC S16 NPos_Value(PARAM *, S16PTR);
FNT_LOC S16 NPos_Value2(PARAM *, S16PTR);
FNT_LOC S16 NPos_Value3(PARAM *, S16PTR);
FNT_LOC S16 NPos_EscChar(PARAM *, S16PTR);
FNT_LOC S16 NPos_Comparateur(PARAM *, S16PTR);
#ifdef ABAL21
FNT_LOC S16 NPos_L_Rubrique(PARAM *, S16PTR);
FNT_LOC S16 NPos_Reste_L_Rubrique(PARAM *, S16PTR);
EXAWORD NewAnalyseSyntaxique(EXAWORD);
#endif

FNT_LOC S16 NPos_Lire (PARAM *, U16, S16PTR);
FNT_LOC S16 NPos_Lex (PARAM *, S16PTR);
FNT_LOC U8 NPos_NextCar (PARAM *);
FNT_LOC U8 NPos_PrevCar (PARAM *);
FNT_LOC void NPos_GoBack(PARAM *);
FNT_LOC U8 NPos_IsEndOfLine(PARAM *);
FNT_LOC S16 NPos_Echec(PARAM *);

FNT_LOC S16 NPos_CreateTokOp (PARAM *, U16, S16PTR);
FNT_LOC S16 NPos_CreateTokVal (PARAM *, S16PTR);
FNT_LOC S16 NPos_CreateTokVal3 (PARAM *, S8, S16PTR);

FNT_LOC U16 MY_strcmp2 ( U8PTR, U8PTR );
FNT_LOC S16 NPos_NewLength (PARAM *, S16PTR);

#endif		/* NOT RT_AIX */

#endif		/* _ANAQUEST_H */

