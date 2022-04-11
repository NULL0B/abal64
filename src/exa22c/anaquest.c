/*----------------------------------------------------------------------*/
/*                                                                      */
/*            E X E C U T E U R 	A . B . A . L                       */
/*            -----------------------------------                       */
/*                                                                      */
/*	    Copyright (c) 1987,1997 Amenesik / Sologic                         */
/*                                                                      */
/*      Module  :	ANAQUEST - C                                        */
/*      Version :	1.4c                                                */ 
/*      Date 	:	18/04/1997                                          */
/*                                                                      */
/*       Analyse syntaxique du nouveau posit                            */
/*----------------------------------------------------------------------*/
/* Mises a jour :
 * ------------
 * 11/03/97 : Creation du source (V.R.)
 * 18/04/97 : Correction bug fn NPos_Lire - pb de return (A.M.)
 *
 */



#include "anaquest.h"
/*#include "anafunc.h"*/

static	EXAWORD	MaxRubrLength=16;

#define	BUG_FIX		0
#define	BUG_FIX2	RUB_DESC_LEN_EXT


#define	MAX_RUBR_LEN MaxRubrLength

#ifdef ABAL21

/*
 *	N e w A n a l y s e S y n t a x i q u e ()
 *	------------------------------------------
 *	Procedure to acces to New analysis of the request
 *
 *	Returns : ZERO     : descriptor OK
 *			  else     : error code
 *
 */
#ifndef AIX_VERS
EXAWORD NewAnalyseSyntaxique(FlagCount)
	EXAWORD FlagCount;
#else /* AIX_VERS */
EXAWORD NewAnalyseSyntaxique(EXAWORD FlagCount)
#endif /* AIX_VERS */
{
	U8PTR	NewDescriptor;
	U16		NewLengh;
	S16		RetVal;
	BPTR	BuffQuestion;

	/* detect long names support */
	/* ------------------------- */
	MaxRubrLength = ( bSystemLongNames  ? RUB_DESC_LEN_EXT : RUB_DESC_LEN_STD);

	/* Allocate memory and a bit more */
	/* ------------------------------ */
	if (!( BuffQuestion=(BPTR)allocate((EXAWORD)(worklen1+BUG_FIX+1)) )) {
		return (EXER_MEMFULL);
		}

	/* Clean the zone and set up underspill correction */
	/* ----------------------------------------------- */
	memset((BPTR)BuffQuestion,0,(worklen1+BUG_FIX));
	BuffQuestion += (BUG_FIX/2);

	/* Duplicate the Question */
	/* ---------------------- */
	memcpy((BPTR)BuffQuestion,(BPTR)workptr1,(USINT)worklen1);

	/* Primary analysis may fail for old type expressions */
	/* -------------------------------------------------- */
	RetVal=NPos_Synt(BuffQuestion, &NewDescriptor, &NewLengh, FlagCount, (U16)1);
	if(RetVal!=ABAL_SUCCESS){
		BuffQuestion -= (BUG_FIX/2);
		liberate(BuffQuestion);
		return ((EXAWORD)RetVal);
		}

	/* Teste si le descripteur n'est pas trop long */
	/* ------------------------------------------- */
	if(NewLengh>worklen2){
		BuffQuestion -= (BUG_FIX/2);
		liberate(BuffQuestion);
		return( EXER_MEMFULL );		/* OUT OF MEMORY */
		}
	
	/* Re-analyse the Question */
	/* ----------------------- */
	RetVal=NPos_Synt(BuffQuestion, &NewDescriptor, &NewLengh, FlagCount, (U16)2);

	/* Readust to avoid underspill correction */
	/* -------------------------------------- */
	BuffQuestion -= (BUG_FIX/2);

	liberate(BuffQuestion);

	if(RetVal!=ABAL_SUCCESS){
		return ((EXAWORD)RetVal);
		}

	/* -------------------- */
	/*     Descriptor OK    */
	/* -------------------- */
	/* copie du descripteur */
	/* -------------------- */
	worklen2=NewLengh; memcpy((BPTR)workptr2,(BPTR)NewDescriptor,(USINT)NewLengh);

	liberate(NewDescriptor);

	return( ABAL_SUCCESS);
}

#endif

/**************************************************************/
/************ Lexical and syntaxical analysis *****************/
/**************************************************************/
             
/*-------------------------------------------------------------*/
/* Procedure which analyse the posit command lign, and create  */
/* the descritor                                               */
/* INPUT : - CmdLine : posit command lign                      */
/*         - Descriptor : descriptor used in criteria          */ 
/*		   - FlagCount : 0 -> COUNT							   */
/*						 1 -> POSIT							   */
/*		   - FlagP : 
				-> 1 : calculate descriptor length
				-> 2 : create the decsriptor					*/
/* OUTPUT : the error code                                     	*/
/*	   	- 0 : error in reading the command lign            		*/
/*      - 1 : descriptor has ben built coorectly            	*/
/*--------------------------------------------------------------*/
#ifndef ABAL21
S16 NPos_Synt(CmdLine, Descriptor, LengthP,  FlagP, HdlP)
#else
S16 NPos_Synt(CmdLine, Descriptor, LengthP, FlagCount, FlagP)
#endif

/* Voir les types a retourner!!!!!!!!!!!!!! */
	U8PTR CmdLine;
	U8PTR *Descriptor;
	U16PTR LengthP;
#ifdef ABAL21
	U16 FlagCount;
#endif
	U16 FlagP;
#ifndef ABAL21
	U32PTR HdlP;
#endif
	
{
	S16 Err;
	
    /* Structure used in a lot of functions */
    PARAM GlobStruct;
    
	Err = 0;
	
	/*  Variables initialisation */
	GlobStruct.Pos = 0;
	GlobStruct.Pos0 = 0;
	GlobStruct.Debut = 0;
	GlobStruct.Flag = 0;
	GlobStruct.Etat = 0;
	GlobStruct.DescLength = 0;
	GlobStruct.DescPos = 0;
	GlobStruct.QuestType = 0;
	GlobStruct.QuestTypePos = 0;
	GlobStruct.ClauseLength = 0;
	GlobStruct.ClauseLengthPos = 0;
	GlobStruct.ColLength = 0;

#ifndef ABAL21
	GlobStruct.Hdl = HdlP; 
#else
	GlobStruct.FlagCount = FlagCount;
#endif
	GlobStruct.EscBool = 0;
	/* If flagP=1, it's the first time we pass in the fonction
		-> we calculate the length of the descriptor
	   If flagP=2, it's the second time we pass in the fonction
		-> we allocate the descritor, and create it */
	if (FlagP == 1) 
		{
		/* Initialisation of the DescLength */
		GlobStruct.DescLength = bSystemLongNames ? POSIT_DESC_LEN_EXT : POSIT_DESC_LEN_STD;
		GlobStruct.Flag = FlagP;

		}
	else if (FlagP == 2) 
		{
		GlobStruct.DescLength = *LengthP;
		GlobStruct.Flag = FlagP;

		/* Memory allocation for the descriptor */
		if (!(GlobStruct.DescPtr = (U8PTR) allocate ((GlobStruct.DescLength+BUG_FIX2))))
			return(EXER_MEMFULL);

		memset(GlobStruct.DescPtr, 0, GlobStruct.DescLength);	


		/************************************************/
		/* Creation of the first part of the descriptor */
		/************************************************/

		/* Number of criterion : always = 1 */
		/* -------------------------------- */
		GlobStruct.DescPtr[GlobStruct.DescPos++] = (U8)1;

		/* Column names : always = "   " */
		/* ----------------------------- */
		memset(GlobStruct.DescPtr+GlobStruct.DescPos, ' ', (bSystemLongNames ? MAX_RUB_NAME_LEN_EXT : MAX_RUB_NAME_LEN_STD)); 
		GlobStruct.DescPos += (bSystemLongNames ? MAX_RUB_NAME_LEN_EXT : MAX_RUB_NAME_LEN_STD); 

		/* Operator : always = 0 */
		/* --------------------- */
		GlobStruct.DescPtr[GlobStruct.DescPos++] = (U8)0;

		/* Length of value : always = 1 */
		/* ---------------------------- */
		GlobStruct.DescPtr[GlobStruct.DescPos++] = (U8)1;

		/* Value : always = 1 */
		/* ------------------ */
		GlobStruct.DescPtr[GlobStruct.DescPos++] = (U8)1;

		/* Descriptor index : always = 0 */
		/* ----------------------------- */
		GlobStruct.DescPtr[GlobStruct.DescPos++] = (U8)0;

		/* Descriptor length (2 octets) */
		/* ---------------------------- */
		balputw ( (GlobStruct.DescLength-(bSystemLongNames ? (POSIT_DESC_SIZE_OFS_EXT) : (POSIT_DESC_SIZE_OFS_STD))) , (GlobStruct.DescPtr+GlobStruct.DescPos) );
		GlobStruct.DescPos += 2;

		/* Type : created later */
		/* -------------------- */
		GlobStruct.QuestTypePos = GlobStruct.DescPos++;

		}
	else 
		{
		return(EXER_MCFUNC);
		}

	GlobStruct.Lign=(BPTR)CmdLine;
	GlobStruct.LignLength=worklen1;
	
	/* we get the first lexical element of the quest */
	if (! (GlobStruct.Curlex = NPos_Lex(&GlobStruct, &Err)))
		goto error;

	/* we analyse the input lign = the quest */
	if(NPos_Quest(&GlobStruct, &Err))
		goto error;
	
	/* we test if we reached the end of the input lign */
	if (GlobStruct.Curlex != ANA_EOF) 
		{
		Err = EXER_MCFUNC;
		goto error;
		}

	if (GlobStruct.Flag == 2) 
		{
		/* Refresh of  Quest Type */
		GlobStruct.DescPtr[GlobStruct.QuestTypePos] = (U8)GlobStruct.QuestType;
		}
	*Descriptor = GlobStruct.DescPtr;

	*LengthP = GlobStruct.DescLength;

	return(0);   
	
error :        

	if(GlobStruct.Flag==2)
		{
		liberate(GlobStruct.DescPtr);
		GlobStruct.DescPtr = 0;   
		}
	return(Err);
}             
             

/*-------------------------------------------------------------*/
/* Recognize a Quest */
/*-------------------------------------------------------------*/
FNT_LOC S16 NPos_Quest (Par, Err) 
	PARAM *Par;                 
	S16PTR Err;
{
	S16 FlagNewPosit = 0;

	/* on rend possible les questions commencant par un ORDER BY */

	if (Par->Curlex == ANA_KEY_WH)
		{
		/* La question commence par un WHERE -> on doit lire une clause WHERE
		si erreur dans la clause, WEXA teste s'il ne s'agit pas d'un ancien POSIT
		avec une rubrique WHERE */

		/* on sait qu'on a un nouveau posit!*/
		FlagNewPosit = 1;

		if (NPos_Where_Clause(Par, Err)<0)
			return(-1);

		}
			
#ifdef ABAL21  
	/* si on a un posit -> ORDER BY autorise */
	/* sinon erreur 93 */
	if (Par->Curlex == ANA_KEY_ORDER)	
		{
		/* pfi le 11/02/99 : desormais, le ORDER BY est permis sur un COUNT...	*/
		/* il s'agit d'un POSIT ou d'un COUNT -> ORDER BY autorise */
		FlagNewPosit = 1;

		if (NPos_Order_Clause(Par, Err)<0)
			return(-1);
		}
#endif

	if (FlagNewPosit == 1)
		/* Le premier token est un WHERE ou un ORDER BY -> NewPosit! */
		return(0);
	else
		/* Le premier token n'est ni un WHERE, NI un ORDER BY -> Ancien POSIT */
		{
		*Err = EXER_MCOLDMETHOD;
		return(-1);
		}

}

/*--------------------------------------------------------------*/
/* Recognize a WHERE clause 					*/
/*--------------------------------------------------------------*/
FNT_LOC S16 NPos_Where_Clause (Par, Err) 
	PARAM *Par;                        
	S16PTR Err;
{
	if (Par->Flag == 1) {
		/* Length of the WHERE CLAUSE */
		Par->DescLength += 2;
		}
	if (Par->Flag == 2)
		{
		/* Descriptor creation */
		Par->QuestType = 1;
		Par->ClauseLength = 2; 
		Par->ClauseLengthPos = Par->DescPos;

		Par->DescPos += 2;
		}

	
	if (NPos_Lire(Par, ANA_KEY_WH, Err)<0)
		return(-1);  
	if (NPos_Expression(Par, Err)<0)
		return(-1);

	if (Par->Flag == 2)
		/* Length of WHERE clause refresh */
		balputw ( Par->ClauseLength , (Par->DescPtr+Par->ClauseLengthPos) );
	
	return(0);
}

#ifdef ABAL21
/*-------------------------------------------------------------*/
/* Recognize an ORDER BY clause */
/*-------------------------------------------------------------*/
FNT_LOC S16 NPos_Order_Clause (Par, Err)
	PARAM *Par;                        
	S16PTR Err;
 {
	if (Par->Flag == 1)
	/* Length of hte ORDER BY clause */
		Par->DescLength += 3;

	if (Par->Flag == 2) 
		{
		/* Descriptor Creation */
		Par->QuestType += 2;
		Par->ClauseLength = 3;
		Par->ClauseLengthPos = Par->DescPos;

		Par->DescPos +=3; /* for clause length and number of column */
		}


	if (NPos_Lire(Par, ANA_KEY_ORDER, Err)<0)
		return(-1);
	if (NPos_Lire(Par, ANA_KEY_BY, Err)<0)
		return(-1);
	if (NPos_L_Rubrique(Par, Err)<0)
		return(-1);

	if (Par->Flag == 2) 
		{
		/* Length of ORDER BY clause refresh */
		balputw ( Par->ClauseLength , (Par->DescPtr+Par->ClauseLengthPos) );
		/* Number of column */
		/* balputw ( (Par->ClauseLength/20) , (Par->DescPtr+Par->ClauseLengthPos+2) );*/
		Par->DescPtr[Par->ClauseLengthPos+2] = 0;
		}
		
	return(0);
}
#endif


/*-------------------------------------------------------------*/
/* Recognize an expression */
/*-------------------------------------------------------------*/
FNT_LOC S16 NPos_Expression (Par, Err)
	PARAM *Par;                      
	S16PTR Err;
 {

	if (Par->Curlex == ANA_TOK_OBR) 
		{
		/* Opennig bracket */
		if (Par->Flag == 1)
			/* we add length of the openning bracket token */
			Par->DescLength += 1;

		/* Create descriptor */
		if (Par->Flag == 2) 
			{
			/* token Type : openning bracket -> 4 */
			Par->DescPtr[Par->DescPos++] = (U8)4;
			/* Clause length refresh */
			Par->ClauseLength += 1;
			}

		if (NPos_Lire(Par, ANA_TOK_OBR, Err)<0)
			return(-1);
		if (NPos_Expression (Par, Err)<0)
			return(-1);
		if (NPos_Lire(Par, ANA_TOK_CBR, Err)<0)
			return(-1);

		if (Par->Flag == 1)
			/* we add length of the closing bracket */
			Par->DescLength += 1;

		/* Create descriptor */
		if (Par->Flag == 2) 
			{
			/* token type : closing bracket -> 8*/
			Par->DescPtr[Par->DescPos++] = (U8)8;
			/* Clause Length refresh */
			Par->ClauseLength += 1;
			}

		}

	else if (Par->Curlex == ANA_OPL_NOT) 
		{
		/* Logical operator */
		if (Par->Flag == 1)
			/* we add length of the operator token
			   Token Type :     1 +
			   Operator Type :  1 +
			   Operator Value : 1 */
			Par->DescLength += 3;

		if (Par->Flag == 2) 
			{
			/* Descriptor creation */
			if (NPos_CreateTokOp (Par, ANA_OPL_NOT, Err)<0)
				return(-1);
			}	
        
        if (NPos_Lire(Par, ANA_OPL_NOT, Err)<0)
			return(-1);
		if (NPos_Expression (Par, Err)<0)
			return(-1);
		}

	else 
		{
		if(NPos_Critere (Par, Err)<0)
			return(-1);
    	}
    
	if(NPos_Reste_Expression (Par, Err)<0)
			return(-1);

	return(0);
}

/*-------------------------------------------------------------*/
/* Recognize the rest of an expression */
/*-------------------------------------------------------------*/
FNT_LOC S16 NPos_Reste_Expression (Par, Err)
	PARAM *Par; 
	S16PTR Err;
 {

	if (Par->Curlex == ANA_OPL_OR  ||  Par->Curlex == ANA_OPL_AND) 
		{
		if(NPos_Ope_Binaire (Par, Err)<0)
			return(-1);
		if(NPos_Expression (Par, Err)<0)
			return(-1);
		if(NPos_Reste_Expression (Par, Err)<0)
			return(-1);
		}

	return(0);
}

/*-------------------------------------------------------------*/
/* Recognize a criterion */
/*-------------------------------------------------------------*/
FNT_LOC S16 NPos_Critere (Par, Err)
	PARAM *Par;
	S16PTR Err;
 {

	if(NPos_Rubrique (Par, Err)<0)
		return(-1);


	if (NPos_Comparateur (Par, Err) >=0 )
		{
		if (NPos_Value (Par, Err)<0)
			return(-1);
		}
	else if (Par->Curlex == ANA_OPR_BT)
		{
		/* Comparator operator (between) */
		if (Par->Flag == 1)
			/* we add length of the operator token
			   Token Type :     1 +
			   Operator Type :  1 +
			   Operator Value : 1 */
			Par->DescLength += 3;

		if (Par->Flag == 2) 
			{
			/* Descriptor creation */
			if(NPos_CreateTokOp(Par, ANA_OPR_BT, Err)<0)
				return(-1);     
			}	

		if (NPos_Between_Exp (Par, Err)<0)
			return(-1);
		}
	else if (Par->Curlex == ANA_OPR_LIKE)
		{
		/* Comparator operator (between) */
		if (Par->Flag == 1)
			/* we add length of the operator token
			   Token Type :     1 +
			   Operator Type :  1 +
			   Operator Value : 1 */
			Par->DescLength += 3;

		if (Par->Flag == 2) 
			{
			/* Descriptor creation */
			if(NPos_CreateTokOp(Par, ANA_OPR_EQ, Err)<0)
				return(-1);     
			}	

		if (NPos_Like_Exp (Par, Err)<0)
			return(-1);

		}
	else if (Par->Curlex == ANA_OPL_NOT)
		{
		/*if (NPos_Lire (Par, ANA_OPL_NOT, Err)<0)
			return(-1);
		if (NPos_Reste_Critere (Par, Err)<0)
			return(-1);*/
		if (NPos_Not_Critere (Par, Err)<0)
			return(-1);
		}
	else
		{
		*Err = EXER_MCFUNC;
		return(-1);
		}

	return(0);
}

/*-------------------------------------------------------------*/
/* Recognize a negative criterion							   */
/*-------------------------------------------------------------*/
FNT_LOC S16 NPos_Not_Critere (Par, Err)
	PARAM *Par;                    
	S16PTR Err;
 {
	 if (NPos_Lire (Par, ANA_OPL_NOT, Err)<0)
		 return(-1);

	 if (Par->Curlex == ANA_OPR_BT)
		{
		 /* Comparator operator (not between) */
		if (Par->Flag == 1)
			/* we add length of the operator token
			   Token Type :     1 +
			   Operator Type :  1 +
			   Operator Value : 1 */
			Par->DescLength += 3;

		if (Par->Flag == 2) 
			{
			/* Descriptor creation */
			if(NPos_CreateTokOp(Par, ANA_OPR_NBT, Err)<0)
				return(-1);     
			}	

		 if (NPos_Between_Exp (Par, Err)<0)
			return(-1);
		}
	 else if (Par->Curlex == ANA_OPR_LIKE)
		{
		 /* Comparator operator (not like <-> different) */
		if (Par->Flag == 1)
			/* we add length of the operator token
			   Token Type :     1 +
			   Operator Type :  1 +
			   Operator Value : 1 */
			Par->DescLength += 3;

		if (Par->Flag == 2) 
			{
			/* Descriptor creation */
			if(NPos_CreateTokOp(Par, ANA_OPR_NE, Err)<0)
				return(-1);     
			}	

		 if (NPos_Like_Exp (Par, Err)<0)
			 return(-1);
		}
	 else
		{
		 *Err=EXER_MCFUNC;
		 return(-1);
		}

	 return(0);
	
 }
  

/*-------------------------------------------------------------*/
/* Recognize a between expression							 */
/*-------------------------------------------------------------*/
FNT_LOC S16 NPos_Between_Exp (Par, Err)
	PARAM *Par;                    
	S16PTR Err;
 {
	if (NPos_Lire (Par, ANA_OPR_BT, Err)<0)
		return(-1);
	if (NPos_Value (Par, Err)<0)
		return(-1);
	if (NPos_Lire (Par, ANA_OPL_AND, Err)<0)
		return(-1);
	if (NPos_Value (Par, Err)<0)
		return(-1);

	return(0);
 }

/*-------------------------------------------------------------*/
/* Recognize a like expression								   */
/*-------------------------------------------------------------*/
FNT_LOC S16 NPos_Like_Exp (Par, Err)
	PARAM *Par;                    
	S16PTR Err;
 {
	if (NPos_Lire (Par, ANA_OPR_LIKE, Err) <0)
		return(-1);
	if (NPos_Value3 (Par, Err)<0)
		return(-1);
	if (NPos_End_Like_Exp (Par, Err)<0)
		return(-1);
	
	return(0);
 }


/*-------------------------------------------------------------*/
/* Recognize the end of a like expression					   */
/*-------------------------------------------------------------*/
FNT_LOC S16 NPos_End_Like_Exp (Par, Err)
	PARAM *Par;                    
	S16PTR Err;
 {
	if (Par->Curlex == ANA_OPR_ESCAPE)
		{
		
		Par->EscBool = 1;
		/* le calcul de longueur de la nouvealle chaine se fera apres lecture de char */
		if (NPos_Lire (Par, ANA_OPR_ESCAPE, Err)<0)
			return(-1);
		if (NPos_EscChar (Par, Err)<0)
			return(-1);
		
		/* On effectue ce calcul dans les deux cas (flag=1 et flag=2) car
		   d'un appel a l'autre de la fonction AnaSynt, on ne memorise
		   pas les nouvelles longueurs */
		if (NPos_NewLength(Par, Err)<0)
			return(-1);

		if (Par->Flag == 1)
			{
			Par->DescLength += (3 + Par->ValLength);
			}
		if (Par->Flag == 2)
			{
			if (NPos_CreateTokVal3 (Par, 1, Err) < 0)
				return(-1);
			}
		}
	else
		{
		/* flag = 1 -> calcul de la longueur de la nouvealle chaine */
		/* flag = 2 -> on met a jour le descripteur avec la nouvelle chaine que l'on calcul */
		
		/* On effectue ce calcul dans les deux cas (flag=1 et flag=2) car
		   d'un appel a l'autre de la fonction AnaSynt, on ne memorise
		   pas les nouvelles longueurs */
		if (NPos_NewLength(Par, Err)<0)
			return(-1);

		if (Par->Flag == 1)
			{
			Par->DescLength += (3 + Par->ValLength);
			}
		if (Par->Flag == 2)
			{
			if (NPos_CreateTokVal3 (Par, 0, Err) < 0)
				return(-1);
			}

		}

	Par->EscBool = 0;

	return(0);

 }	

/*-------------------------------------------------------------*/
/* Recognize a column */
/*-------------------------------------------------------------*/
FNT_LOC S16 NPos_Rubrique (Par, Err)
	PARAM *Par;                    
	S16PTR Err;
 {
	EXAWORD	exaColLength;
	EXAWORD	exaColType;


/* local variables */
	U16 error;
#ifndef ABAL21
	static U8	name[MAX_TABLE_NAME_LEN_EXT+1+MAX_RUB_NAME_LEN_EXT+1];
	U16PTR posi;
	U16PTR t2;
#endif
	U16 i;
#ifdef ABAL21
	EXAWORD IndexRubrique;
#endif
	BPTR	tableName=(BPTR)0;
	BPTR	colName=(BPTR)Par->ColName;
	BPTR	p=colName;
	EXABYTE  colType=0;

	if (Par->Curlex == RUB) 
		{
		if (bUserLongNames){
			for (i=0;i<strlen((BPTR)Par->ColName);i++,p++){
				if (*p=='.'){
					tableName=colName;
					colName=(p+1);
					break;
					}
				}
			}
		if (Par->Flag == 1)
			{
			/* we add the length of the column token
				Token Type (1 ) +
				Name (16 ) +
				Type (1  )) +
				Length (2)) */
			if (!bSystemLongNames){
				Par->DescLength += (RUB_DESC_LEN_STD);
				}
			else	{
				if (tableName)	Par->DescLength += MAX_TABLE_NAME_LEN_EXT+1;
				Par->DescLength += (RUB_DESC_LEN_EXT);
				}
			}

		/* we get the column caracteristics :
			length
			type
			value
		   They are used to test coherency of the values */  

		Par->ColLength=0;
		if (!GetColumn(fidreel,tableName,(EXAWORD)(colName-tableName-1),
							colName,strlen(colName),&exaColLength,&exaColType)) error = 1;
		else	{
			colType = exaColType;
			Par->ColLength = exaColLength;
			error=0;
    			Par->ColType=colType & 0x0F;
			Par->ColDecLength = colType >> 4 ;
    			}

#ifdef	ABAL0	/* bastard */
#ifndef ABAL21		   
		error=CRIDB_ListCol((HCRITE)Par->Hdl, CR_FIRST, (BPTR)name, (LPWORD)&posi, (LPWORD)&(Par->ColLength), (LPWORD)&(Par->ColType), (LPWORD)&(Par->ColDecLength), (LPWORD)&t2);
		while (!error)
			{
			if (!strcmp(Par->ColName, name)) break;
			error=CRIDB_ListCol((HCRITE)Par->Hdl, CR_NEXT, (BPTR)name, (LPWORD)&posi, (LPWORD)&(Par->ColLength), (LPWORD)&(Par->ColType), (LPWORD)&(Par->ColDecLength), (LPWORD)&t2);
			}
#else	
		IndexRubrique=rubrctrl((BPTR)Par->ColName,(EXAWORD)strlen((BPTR)Par->ColName));		
		if(IndexRubrique!=MOINS_UN){ /* Rubrique trouvee */ 
			Par->ColLength=*(rubr_base + 20*IndexRubrique + RUBLENG);
			/* Pour les types BCD, 4 bits de poids forts contiennent 
			 * eventuellement le nb de decimales
			 */
			Par->ColType=(*(rubr_base + 20*IndexRubrique + RUBTYPE)) & 0x0F;
			Par->ColDecLength = (*(rubr_base + 20*IndexRubrique + RUBTYPE)) >> 4 ;
			error=0;
			}
		else
			error=IndexRubrique;
#endif		
#endif		/* bastard */

		if(error) {
			/* Column doesn't exist, or there were a problem in read the file or DB */
			/* -------------------------------------------------------------------- */
			*Err = EXER_MCSIZE;
			return(-1);
			}

		if (Par->Flag == 2)  {

			/***********************/
			/* Descriptor creation */
			/***********************/
			if (!bSystemLongNames){
				/* --------------- */
				/* OLD SHORT NAMES */
				/* --------------- */
				/* Token Type : Column -> 0 */
				Par->DescPtr[Par->DescPos++] = (U8)0;
				/* Column Name */
				for (i=0; i<MAX_RUB_NAME_LEN_STD; i++) {
					if (i<(U16)strlen((BPTR)(Par->ColName)))
						Par->DescPtr[Par->DescPos+i] = (U8)(Par->ColName[i]);
					else	Par->DescPtr[Par->DescPos+i] = ' ';
					}
				Par->DescPos += MAX_RUB_NAME_LEN_STD;

				/* Column type (1 octet) */
				Par->DescPtr[Par->DescPos++] = (U8)0;

				/* Column length (2 octets) */
				balputw ( Par->ColLength , (Par->DescPtr+Par->DescPos) );
				Par->DescPos += 2;

				/* Clause Length refresh */
				Par->ClauseLength += (RUB_DESC_LEN_STD);
				}
			else	{
				/* -------------- */
				/* NEW LONG NAMES */
				/* -------------- */
				if (tableName) {

					/* Token Type : Table -> 6 */
					Par->DescPtr[Par->DescPos++] = (U8)6;

					/* Column Name */
					for (i=0,p=tableName; i<MAX_TABLE_NAME_LEN_EXT; i++,p++) {
						if (p<colName && *p!='.') 
							Par->DescPtr[Par->DescPos+i] = (U8)(Par->ColName[i]);
						else 	Par->DescPtr[Par->DescPos+i] = ' ';
						}

					Par->DescPos += MAX_TABLE_NAME_LEN_EXT;

					/* Clause Length refresh */
					Par->ClauseLength += (MAX_TABLE_NAME_LEN_EXT+1);
					}

				/* Token Type : Column -> 0 */
				Par->DescPtr[Par->DescPos++] = (U8)0;
				/* Column Name (16 octets) */
				for (i=0; i<MAX_RUB_NAME_LEN_EXT; i++) {
					if (i<(U16)strlen((BPTR)(colName)))
						Par->DescPtr[Par->DescPos+i] = (U8)(colName[i]);
					else	Par->DescPtr[Par->DescPos+i] = ' ';	
					}
				Par->DescPos += MAX_RUB_NAME_LEN_EXT;
				/* Column type (1 octet) */
				Par->DescPtr[Par->DescPos++] = (U8)0;
				/* Column length (2 octets) */
				balputw ( Par->ColLength , (Par->DescPtr+Par->DescPos) );
				Par->DescPos += 2;
				/* Clause Length refresh */
				Par->ClauseLength += (RUB_DESC_LEN_EXT);
				}
			}

		if(NPos_Lire(Par, RUB, Err)<0)
			return(-1);
		}
	else
		{
		*Err = EXER_MCSIZE;
		return (-1);  
		}

	return(0);
}

/*-------------------------------------------------------------*/
/* Recognize the rest of an expression */
/*-------------------------------------------------------------*/
FNT_LOC S16 NPos_Ope_Binaire (Par, Err)
		PARAM *Par;                   
		S16PTR Err;
 {

	/* Logical operator */
	if (Par->Flag == 1)
		/* we add length of the operator token
			Token Type :     1 +
			Operator Type :  1 +
			Operator Value : 1 */
		Par->DescLength += 3;

	if (Par->Flag == 2)
		{
		/* Descriptor creation */
		if(NPos_CreateTokOp(Par, Par->Curlex, Err)<0)
			return(-1);    
		}	

	if (Par->Curlex == ANA_OPL_OR)
		{
		if(NPos_Lire(Par, ANA_OPL_OR, Err)<0)
			return(-1);               
		}	
	else if (Par->Curlex == ANA_OPL_AND)
		{
		if(NPos_Lire(Par, ANA_OPL_AND, Err)<0)
			return(-1);                
		}		
	else 
		{
		*Err = EXER_MCFUNC;
		return(-1);
		}

	return(0);

}
/*--------------------------------------------------------------*/
/* Recognize a value 						*/
/* Numerical value or alphanumerical value between simple cotes */
/*--------------------------------------------------------------*/
FNT_LOC S16 NPos_Value (Par, Err)
	PARAM *Par;                 
	S16PTR Err;
 {

	/* Each time pass in this fonction, we calculate the length if the
	   value token -> length of value used for descriptor refresh 
		Token type : 1 octet
		Value length : 2 octets
		Value : x octets (x depends on the column length */

	switch (Par->ColType)
		{
		/* Alphanumerical values */
		case CR_COL_CHAR :
#ifndef ABAL21
		case CR_COL_BIN :
		case CR_COL_DATE :
#endif
			if (Par->CurCompVal == ANA_OPR_EQ || Par->CurCompVal == ANA_OPR_NE)
				{
				/* The value has to be modified for CRITERIA -> the length too!! */
				/* Meme calcul que pour une LIKE clause sans ESCAPE */
				if (NPos_NewLength(Par, Err)<0)
					return(-1);
				}
			/* 12/10/98 removed by pfi	*/
			/*
			else
				Par->ValLength = strlen(Par->CurVal);
			*/
			break;
		/* Numerical values */
		default :
			Par->ValLength = Par->ColLength;
			/* 13/10/98 added by pfi	*/
			Par->ValBytes = Par->ColLength;
		}

	if (Par->Flag == 1)
		{
		/* Refresh of the desc length decsriptor */	
		Par->DescLength += 3 + Par->ValLength;
		}

	if (Par->Flag == 2) 
		{
		/* Create the descriptor */
		if(NPos_CreateTokVal(Par, Err)<0)
			return(-1);
		}

	
	if (Par->Curlex == VAL) 	
		{
		if(NPos_Lire(Par, VAL, Err)<0)
			return(-1);       
		}	
	else if (Par->Curlex == VAL2) 
		{
		if(NPos_Lire(Par, VAL2, Err)<0)
			return(-1);               
		}	
	else
		{
		*Err = EXER_MCFUNC;
		return(-1);
		}

	return(0);
}

/*--------------------------------------------------------------*/
/* Recognize a value 											*/
/* Only alphanumerical value between simple or double cotes		*/
/*--------------------------------------------------------------*/
FNT_LOC S16 NPos_Value2 (Par, Err)
	PARAM *Par;                  
	S16PTR Err;
 {

	/* The first time pass in this fonction, we calculate the length if the
	   value token
		Token type   : 1 octet
		Value length : 2 octets
		Value : x octets (x depends on the column length */
	if (Par->Flag == 1)
        Par->DescLength += 3 + Par->ColLength;

	if (Par->Flag == 2) 
       	{
		/* Create the descriptor */
		if(NPos_CreateTokVal(Par, Err)<0)
			return(-1);
		}
	
	if (Par->Curlex == VAL2) 
		{
		if(NPos_Lire(Par, VAL2, Err)<0)
			return(-1);         
		}	
	else
		{
		*Err = EXER_MCFUNC;
		return(-1);
		}

	return(0);
}

/*--------------------------------------------------------------*/
/* Recognize and refresh a value in a like expression			*/
/* Only alphanumerical value between simple cotes		  		*/
/*--------------------------------------------------------------*/
FNT_LOC S16 NPos_Value3 (Par, Err)
	PARAM *Par;                  
	S16PTR Err;
 {

	/* The associated column type must be alphanumerical */	
#ifdef ABAL21
	 if (Par->ColType!=CR_COL_CHAR)
#else
	 if ((Par->ColType!=CR_COL_CHAR) & (Par->ColType!=CR_COL_BIN) & (Par->ColType!=CR_COL_DATE))
#endif
		{
		 *Err = EXER_MCFUNC;
		 return(-1);
		}	
	
	/* le calcul de longueur du descripteur et sa mise a jour
	 se font a la lecture du escape */

	if(NPos_Lire(Par, VAL2, Err)<0)
		 return(-1);

	return(0);
}

/*-------------------------------------------------------------*/
/* Recognize an Escape character (in a LIKE expression)		   */
/*-------------------------------------------------------------*/
FNT_LOC S16 NPos_EscChar (Par, Err) 
	PARAM *Par;                       
	S16PTR Err;
{
	if ((Par->Curlex == VAL2) & (Par->CoteType == '\'') & (strlen((BPTR)Par->EscVal) == 1))	
		{	
		if (NPos_Lire (Par, VAL2, Err)<0)
			return(-1);
		}
	else 
		{
		*Err = EXER_MCFUNC;
		return(-1);
		}
	return(0);
}


/*-------------------------------------------------------------*/
/* Recognize a comparator */
/*-------------------------------------------------------------*/
FNT_LOC S16 NPos_Comparateur (Par, Err) 
	PARAM *Par;                       
	S16PTR Err;
{
	/* on teste si curlex est bien un operateur de comparaison */
	switch(Par->Curlex)
		{
		case ANA_OPR_EQ :
		case ANA_OPR_NE :
		case ANA_OPR_L :
		case ANA_OPR_LE :
		case ANA_OPR_G :
		case ANA_OPR_GE :
			Par->CurCompVal = Par->Curlex;
			break;
		default:
			*Err=EXER_MCFUNC;
			return(-1);
		}


	/* Comparator operator */
	if (Par->Flag == 1)
		/* we add length of the operator token
		   Token Type :     1 +
		   Operator Type :  1 +
		   Operator Value : 1 */
		   Par->DescLength += 3;

	if (Par->Flag == 2) 
		{
		/* Descriptor creation */
		if(NPos_CreateTokOp(Par, Par->Curlex, Err)<0)
			return(-1);   
		}	

	if (Par->Curlex == ANA_OPR_EQ)
		{
		if(NPos_Lire(Par, ANA_OPR_EQ, Err)<0)
			return(-1);
		}
	else if (Par->Curlex == ANA_OPR_NE)
		{
		if(NPos_Lire(Par, ANA_OPR_NE, Err)<0)
			return(-1);
		}
	else if (Par->Curlex == ANA_OPR_LE) 
		{
		if(NPos_Lire(Par, ANA_OPR_LE, Err)<0)
			return(-1);
		}
	else if (Par->Curlex == ANA_OPR_L) 
		{
		if(NPos_Lire(Par, ANA_OPR_L, Err)<0)
			return(-1);
		}
	else if (Par->Curlex == ANA_OPR_GE) 
		{
		if(NPos_Lire(Par, ANA_OPR_GE, Err)<0)
			return(-1);
		}
	else if (Par->Curlex == ANA_OPR_G)  
		{
		if(NPos_Lire(Par, ANA_OPR_G, Err)<0)
			return(-1);
		}

	return(0);
}
#ifdef ABAL21

/*-------------------------------------------------------------*/
/* Recognize a column list */
/*-------------------------------------------------------------*/
FNT_LOC S16 NPos_L_Rubrique (Par, Err) 
	PARAM *Par;             
	S16PTR Err;
{

	if (Par->Curlex != ANA_EOF) 
		{
		if(NPos_Rubrique (Par, Err)<0)
			return(-1);
		if(NPos_Reste_L_Rubrique (Par, Err)<0)
			return(-1);
		}

	return(0);
}

/*-------------------------------------------------------------*/
/* Recognize the rest of a column list */
/*-------------------------------------------------------------*/
FNT_LOC S16 NPos_Reste_L_Rubrique (Par, Err)
	PARAM *Par;                            
	S16PTR Err;
 {

	if (Par->Curlex != ANA_EOF) 
		{
		if (Par->Curlex == ANA_TOK_CO) 
			{
			if(NPos_Lire(Par, ANA_TOK_CO, Err)<0)
				return(-1);                
			}	
		
		if(NPos_L_Rubrique (Par, Err)<0)
			return(-1);
		}

	return(0);
}
#endif

/*-------------------------------------------------------------*/
/* Procedure which read and analyse the next token in the      */
/* command lign                                                */
/* INPUT :	- Par : Parameter structure						   */
/*			- TokType									       */
/* OUTPUT:	- Error code or TokType						       */
/*			0 -> error in lexical analyse        			   */
/*			else -> OK!!			       					   */
/*-------------------------------------------------------------*/
FNT_LOC S16 NPos_Lire(Par, TokType, Err)
	PARAM *Par;
	U16 TokType;                       
	S16PTR Err;

{
	if (Par->Curlex == TokType) 
		{
		if (!(Par->Curlex = NPos_Lex (Par, Err)))
			/* if there's a problem in lexical analyse -> Curlex = 0 */
			return(-1);
		}
	else
		{
		*Err = EXER_MCFUNC;
		return(-1);
		}

	return(0);
} /* Lire(Par, TokType)*/

/*--------------------------------------------------------------*/
/*  This function read the next token of the command lign, and 	*/
/*  analyse it. 					      						*/
/* INPUT :	- Par : Parameter Structure							*/
/* OUTPUT : 	- U16 Error or TokType if every thing is OK!   	*/
/*							     								*/
/* This is the diagram used to analyse the allowed tokens.     	*/
/* Each number is a state used in the "CASE"		       		*/
/*							       */
/* 	0 __ = __ 1 			return (ANA_OPR_EQ);
	|___ < __ 2 __ > __ 5		return (ANA_OPR_NE);
	|	  |___ = __ 6 		return (ANA_OPR_LE);
	|	  |_ else _ 7		return (ANA_OPR_L);
	|___ > __ 3 __ = __ 8   	return (ANA_OPR_GE);
	|         |_ else _ 9		return (ANA_OPR_G);
	|__ \0 __ 4			return (ANA_EOF);
	|_ else _ 			Echec();


	10__ ( __ 13			return (ANA_OPR_OBR);
	|_ else _			Echec();

	11__ ) __ 14			return (ANA_OPR_CBR);
	|_ else _			Echec();

	12__ , __ 15            	return (ANA_OPR_CO);
	|_ else _			Echec();

	16__ ' __ 17_ AlNu _ 17
	|	   |__ ' ___ 20		Stock(); return(VAL);
	|	   |_ else _ 		Echec();
	|__ Al __ 18_ AlNu _ 18
	|	   |__   ___ 21         Test keywords; Stock(); return(Test Result);
	|	   |_ else 		Echec();
	|__ Nu __ 19__ Nu __ 19
	|	   |__   ___ 22         Stock(); return(VAL);
	|          |_ else _ 		Echec();
	|_ else _			Echec();

	24__ \0 _ 25			Return(ANA_EOF);
	|_ else _			Echec();

	26__   __ 26
	|_ else _ 			Echec();

	27_______			Return(0) -> lexical error               */

/*-------------------------------------------------------------*/
FNT_LOC S16 NPos_Lex (Par, Err)
	PARAM *Par;     
	S16PTR Err;
{
	static U8 Name[MAX_TABLE_NAME_LEN_EXT + 1 + MAX_RUB_NAME_LEN_EXT + 1]; 
	U16 	i; 
	U8 	FirstCar;
	U16	nMaxColName=bUserLongNames ? MAX_RUB_NAME_LEN_EXT:MAX_RUB_NAME_LEN_STD;

	Par->Etat = 0; Par->Debut = Par->Etat;
	Par->Pos0 = Par->Pos;
	while (1) 
		{
		switch (Par->Etat) 
			{
			/* Operator test */
			case 0 :
				Par->Debut = 0;
				Par->Car = NPos_NextCar(Par);
				if ( Par->Car == '=' ) Par->Etat = 1;
				else if ( Par->Car == '<' ) Par->Etat = 2;
				else if ( Par->Car == '>' ) Par->Etat = 3;
				else if ( Par->Car == '\0') Par->Etat = 4;
				else Par->Etat = NPos_Echec(Par); 
				break;
			case 1 :                                                    
				return (ANA_OPR_EQ);
			case 2 :
				Par->Car = NPos_NextCar(Par);
				if ( Par->Car == '>' ) Par->Etat = 5;
				else if ( Par->Car == '=' ) Par->Etat = 6;
				else 
					{
					Par->Etat = 7; 
					Par->Car = NPos_PrevCar(Par);
					}
				break;
			case 3 :
				Par->Car = NPos_NextCar(Par);
				if ( Par->Car == '=' ) Par->Etat = 8;
				else
					{
					Par->Etat = 9; 
					Par->Car = NPos_PrevCar(Par);
					}
				break;
			case 4 :       /* fin de fichier : ANA_EOF*/
				return (ANA_EOF);
			case 5 :       /* <> */
				return (ANA_OPR_NE);
			case 6 :       /* <= */
				return (ANA_OPR_LE);
			case 7 :       /* <  */
				return (ANA_OPR_L);
			case 8 :       /* >= */
				return (ANA_OPR_GE);
			case 9 :       /* >  */
				return (ANA_OPR_G);
		  /* symboles '(' , ')' , ','  */
			case 10 : /* openning bracket */
				Par->Debut = 10;
				Par->Car = NPos_NextCar(Par);
				if (Par->Car == '(') Par->Etat = 13;
				else Par->Etat = NPos_Echec(Par); 
				break;
			case 11 : /* closing bracket */
				Par->Debut = 11;
				Par->Car = NPos_NextCar(Par);
				if (Par->Car == ')') Par->Etat = 14;
				else Par->Etat = NPos_Echec(Par); 
				break;
			case 12 : /* Commas */
				Par->Debut = 12;
				Par->Car = NPos_NextCar(Par);
				if (Par->Car == ',') Par->Etat = 15;
				else Par->Etat = NPos_Echec(Par); 
				break;
			case 13 : /* '(' */
				return (ANA_TOK_OBR);
			case 14 : /* ')' */
				return (ANA_TOK_CBR);
			case 15 : /* ',' */
				return (ANA_TOK_CO);

		/* value et column test
		 If a value or a column is longer than 10 caracters, we have to
		 tronc it */
			case 16 :  /* Value */
				Par->Debut = 16;
				Par->Car = NPos_NextCar(Par);
				if ((Par->Car == '\'') || (Par->Car == '"')) 
					{
					FirstCar = Par->Car;
					Par->CoteType = FirstCar;
					Par->Etat = 17;
					}
				else if (isalpha2(Par->Car)) Par->Etat = 18;
				else if (isdigit2(Par->Car)) Par->Etat = 19;
				else Par->Etat = NPos_Echec(Par); 
				break;
			case 17 :    /* alphanumerical value */
				Par->Car = NPos_NextCar(Par);
				if (Par->Car == FirstCar) Par->Etat = 20;
				else if (Par->Car == '\0' && NPos_IsEndOfLine(Par)) Par->Etat = 27;
				else Par->Etat = 17;
				break;
			case 18  :    /* column name */
				Par->Car = NPos_NextCar(Par);

				if (isalnum2(Par->Car)){
					Par->Etat = 18; 
					if (bUserLongNames && Par->Car=='.'){
						nMaxColName=MAX_TABLE_NAME_LEN_EXT+1+MAX_RUB_NAME_LEN_EXT;
						}
					}

				else {
					Par->Car = NPos_PrevCar(Par);
					Par->Etat = 21;
				}
				break;
			case 19 :     /* numerical value */
				Par->Car = NPos_NextCar(Par);
				if (isdigit2(Par->Car)) Par->Etat = 19;
				else  
					{
					Par->Etat = 22;
					Par->Car = NPos_PrevCar(Par);
					}
				break;
			case 20 :
				/* we memorize the alphanumerical value, whithout cotes */
				i=Par->Pos - Par->Pos0 - 2;
				if (Par->EscBool == 0)
					/* on lit une veritable valeur et pas un caractere d'ESCAPE */
					{
					memcpy (Par->CurVal, Par->Lign+Par->Pos0+1, i);
					Par->CurVal[i]='\0';
					/* 12/10/98 : modif pfi	*/
					/* Par->ValLength = strlen(Par->CurVal); */
					Par->ValLength = i;
					/* 13/10/98 added by pfi	*/
					Par->ValBytes = i;
					}
				else
					/* on lit un caractere d'ESCAPE -> longueur = 1 */
					{
					memcpy (Par->EscVal, Par->Lign+Par->Pos0+1, i);
					Par->EscVal[i]='\0';
					}
				
				return(VAL2);
			case 22 :
				/* we memorize the numerical value */
				i=Par->Pos - Par->Pos0 ;
				memcpy (Par->CurVal, Par->Lign+Par->Pos0, i);
				Par->CurVal[i]='\0';
				
				return(VAL);
			case 21 :
				/* Tester s'il s'agit d'un AND, OR, NOT. SINON : */
				/* stocker la valeur alphanumerique en tronquant a 10 caracteres */
				/* we memorize the value */

				/* we test the length of the column name */
				/* It can't be bigger than 16 / 32  */
				if ((Par->Pos - Par->Pos0) > nMaxColName)
					{
					Par->Etat = 27;
					break;
					}

                i = Par->Pos - Par->Pos0;
                memcpy (Name, Par->Lign+Par->Pos0, i);
                Name[i] = '\0';			
                                          
				if (!MY_strcmp2((U8PTR)Name, "AND")) return(ANA_OPL_AND);
				else if (!MY_strcmp2((U8PTR)Name, "OR")) return (ANA_OPL_OR);
				else if (!MY_strcmp2((U8PTR)Name, "NOT")) return (ANA_OPL_NOT);
				else if (!MY_strcmp2((U8PTR)Name, "WHERE")) return (ANA_KEY_WH);
				else if (!MY_strcmp2((U8PTR)Name, "ORDER")) return (ANA_KEY_ORDER);
				else if (!MY_strcmp2((U8PTR)Name, "BY")) return (ANA_KEY_BY);
				else if (!MY_strcmp2((U8PTR)Name, "BETWEEN")) return (ANA_OPR_BT);
				else if (!MY_strcmp2((U8PTR)Name, "LIKE")) return (ANA_OPR_LIKE);
				else if (!MY_strcmp2((U8PTR)Name, "ESCAPE")) return (ANA_OPR_ESCAPE);
				else 
					{
					strcpy((BPTR)(Par->ColName), (BPTR)Name);
					return(RUB);
					}   		/* If blank read the next character */
			 case 24 :
				Par->Debut = 24;
				Par->Car = NPos_NextCar(Par);
				if (Par->Car == ' ') Par->Etat = 24;
				else 
					{
					Par->Car = NPos_PrevCar(Par);
					Par->Pos0 = Par->Pos;
					Par->Etat = 0;
					Par->Debut = Par->Etat;
					}
				break;
			/* Test if End Of File */
			 case 25 :
				Par->Car = NPos_NextCar(Par);
				if (Par->Car == '\0') Par->Etat = 26;
				else Par->Etat = NPos_Echec(Par); 
				break;
			 case 26 :
				Par->Debut = 16;
				return(ANA_EOF);

			/* Failure of the lexical analyser */
			  case 27 :
				Par->Debut = 27; 
				*Err = EXER_MCFUNC;
				return(0);
			  default :  
			  	*Err = EXER_MCFUNC;
				return(0);

		 	} /* end switch */
		} /* end while */
} /* AnaLex(Par) */

 

/*--------------------------------------------------------------*/
/* Give the next input character;                               */
/* INPUT :	- Par : Parameter structure					      	*/
/* OUTPUT :	- next character                                    */
/*--------------------------------------------------------------*/
FNT_LOC U8 NPos_NextCar (Par)
	PARAM *Par;
{
	U8 c;

	c = Par->Lign[Par->Pos];

	(Par->Pos)++;

	return(c);

} /* NPos_NextCar (Par) */

/*-------------------------------------------------------------*/
/* Give the previous input character                           */
/* INPUT :	- Par : Parameter structure						   */
/* OUTPUT :	- prev character                                   */
/*-------------------------------------------------------------*/
FNT_LOC U8 NPos_PrevCar (Par)
	PARAM *Par;
{
	U8 c;

	c = Par->Lign[Par->Pos];

	(Par->Pos)--;

	return(c);

} /* NPos_PrevCar (Par) */

/*--------------------------------------------------------------*/
/* Procedure which reinitialise the index position according to	*/
/* the variable Debut 					      				 	*/
/* INPUT :	- Par : parameter structure							*/
/* OUTPUT :	void                                           		*/
/*--------------------------------------------------------------*/
FNT_LOC void  NPos_GoBack(Par)
	PARAM *Par;
{
	Par->Pos = Par->Pos0;

}

/*-------------------------------------------------------------*/
/* returns whether it is the end of the command line           */
/* INPUT :	- Par : Parameter structure							   */
/* OUTPUT :	- 1 : End of Command Line                          */
/*				  0 : Not end of Command Line								*/
/*-------------------------------------------------------------*/
FNT_LOC U8 NPos_IsEndOfLine (Par)
	PARAM *Par;
{
	if ( Par->Pos >= Par->LignLength )
		return(1);
	else
		return(0);
} /* NPos_IsEndOfLine (Par) */

/*-------------------------------------------------------------*/
/* Go to the next diagram, giving back his initial state       */
/*-------------------------------------------------------------*/
FNT_LOC S16 NPos_Echec(Par)
	PARAM *Par;
{
	switch (Par->Debut) 
		{
		case 0 :
			NPos_GoBack(Par); return(10);
		case 10 :
			NPos_GoBack(Par); return(11);
		case 11 :
			NPos_GoBack(Par); return(12);
		case 12 :
			NPos_GoBack(Par); return(16);
		case 16 :
			NPos_GoBack(Par); return(24);
		case 24 :
			NPos_GoBack(Par); return(26);
		case 26 :
			NPos_GoBack(Par); return(27);
		default :
			NPos_GoBack(Par); return(27);
		} /* end switch */
}                      

/****************************************************************/
/********* Descriptor creation	*********************************/
/****************************************************************/


/*--------------------------------------------------------------*/
/* This function is used for the creation of the operator 		*/
/* tokens.														*/
/* INPUT :  - Par : Parameter structure							*/
/*			- TokVal : token value								*/
/* OUTPUT : - code error 												*/
/*--------------------------------------------------------------*/
FNT_LOC S16 NPos_CreateTokOp (Par, TokVal, Err)   
	PARAM *Par;
	U16 TokVal;   
	S16PTR Err;
{
	U8 OpType;
	U8 OpVal;

	/* ClauseLength refresh */
	Par->ClauseLength += 3;

	/* Token Type : operator -> 1 */
	Par->DescPtr[Par->DescPos++] = (U8)1;

	switch (TokVal) 
		{
		case ANA_OPR_EQ :
			OpType = (U8)0; OpVal = (U8)13; break;
		case ANA_OPR_G :
			OpType = (U8)0; OpVal = (U8)5; break;
		case ANA_OPR_GE :
			OpType = (U8)0; OpVal = (U8)17; break;
		case ANA_OPR_L :
			OpType = (U8)0; OpVal = (U8)9; break;
		case ANA_OPR_LE :
			OpType = (U8)0; OpVal = (U8)21; break;
		case ANA_OPR_NE :
			OpType = (U8)0; OpVal = (U8)25; break;
		case ANA_OPR_BT :
			OpType = (U8)0; OpVal = (U8)30; break;
		case ANA_OPR_NBT :
			OpType = (U8)0; OpVal = (U8)34; break;
		case ANA_OPL_AND :
			OpType = (U8)1; OpVal = (U8)1; break;
		case ANA_OPL_OR :
			OpType = (U8)1; OpVal = (U8)2; break;
		case ANA_OPL_NOT :
			OpType = (U8)1; OpVal = (U8)4; break;
		default :       
			*Err = EXER_MCFUNC;
			return(-1);
		}

	/* Operator type (1 octet) */
	Par->DescPtr[Par->DescPos++] = (U8)OpType;
	/* Operator Value (1 octet) */
	Par->DescPtr[Par->DescPos++] = (U8)OpVal;

	return(0);
}

/*--------------------------------------------------------------*/
/* This function is used for the creation of the value	 		*/
/* tokens.														*/
/* INPUT : Par : Parameter structure							*/
/* OUTPUT : Error Code											*/
/*--------------------------------------------------------------*/
FNT_LOC S16 NPos_CreateTokVal (Par, Err) 
	PARAM *Par;                        
	S16PTR Err;
{
	U16 i;
	U16 ValLen;
	U16 Val;
	U16PTR ValPtr;
	U8 c;

	i=0;

	/* Token Type (1 octet) : value -> 2 */
	Par->DescPtr[Par->DescPos++] = (U8)2; 
	
	

	switch (Par->ColType)
		{

		/* alphanumerical value */
		case CR_COL_CHAR :
#ifndef ABAL21		
		case CR_COL_BIN :
		case CR_COL_DATE :
#endif			
			
			/* Token length (2 octets) : ValLen */
			ValLen = Par->ValLength;
			balputw ( ValLen , (Par->DescPtr+Par->DescPos) );
			Par->DescPos += 2;

			if (Par->CurCompVal == ANA_OPR_EQ || Par->CurCompVal == ANA_OPR_NE)
				{
				/* the value is modified for CRITERIA */
				/* 12/10/98 modified by pfi	*/
				/*
				while ((c=Par->CurVal[i])!='\0' & i<256)
				*/
				while (i<Par->ValBytes)
					{
					c=Par->CurVal[i];
					switch(c)
						{
						case '*':
						case '#':
						case '!':
						case '\\':
							Par->DescPtr[Par->DescPos] = '\\';
							Par->DescPos += 1;
							Par->DescPtr[Par->DescPos] = c;
							Par->DescPos += 1;
							break;
						default :
							Par->DescPtr[Par->DescPos] = c;
							Par->DescPos += 1;
						}
					i++;
					}
				}
			else
				{
				/* The value is simply copied in the descriptor */
				/* Value (ValLen octets) */
				for (i=0; i<ValLen; i++)      
					{
					/* 12/10/98 removed by pfi	*/
					/*	if (i<(U16)strlen((BPTR)(Par->CurVal)))	*/
						Par->DescPtr[Par->DescPos+i] = Par->CurVal[i];
					/*
					else
						Par->DescPtr[Par->DescPos+i] = ' ';
					*/
					}
				Par->DescPos += ValLen;
				}
			
			break;

#ifndef ABAL21	
		/* unsigned tiny int (1 octet) */
		case CR_COL_UTINY :
		/* unsigned small int (2 octets) */
		case CR_COL_USINT :	
			/* Converted value (1 octet) */
		/* BCD (x octets) */
#endif
		case CR_COL_DECI :
			
			/* Token length (2 octets) : ValLen */
			ValLen = Par->ColLength;
			balputw	( ValLen , (Par->DescPtr+Par->DescPos) );
			Par->DescPos += 2;

			switch (Par->ColLength) 
				{

				case 1 :
					/* Converted Value (1 octet) */
					Val = (U16)MY_atoi((U8PTR)(Par->CurVal), (EXAWORD)(strlen((BPTR)(Par->CurVal))));
					Par->DescPtr[Par->DescPos++] = (U8)Val;
					break;

				case 2 :
			
					/* Converted Value (2 octets) */
					Val = (U16)MY_atoi((U8PTR)Par->CurVal, (EXAWORD)(strlen(Par->CurVal)));
					ValPtr = &Val;
					balputw ( Val , (Par->DescPtr+Par->DescPos) );
					Par->DescPos += 2;
					break;

				default : 

					/* Test coherency of the value */
#ifndef ABAL21
					if(TestBcdType(Par->CurVal, Par->ColLength, Par->ColDecLength, Err)<0)
						return(-1);
#endif

					/* Converted value (ValLen octets) */
					/* BCD coherency has already been tested ! */
			
/* VR le 130598 */
/* Inversion des 2 derniers parametres */
					/* atobcd((BPTR)(Par->CurVal),(BPTR)(Par->DescPtr+Par->DescPos), (EXAWORD)strlen(Par->CurVal), (EXAWORD)(Par->ColLength));   */
					atobcd((BPTR)(Par->CurVal),(BPTR)(Par->DescPtr+Par->DescPos), (EXAWORD)(Par->ColLength), (EXAWORD)strlen(Par->CurVal));  
/* VR fin */
#ifdef ABAL21	
					bcdfix((BPTR)Par->DescPtr+Par->DescPos, (BPTR)Par->DescPtr+Par->DescPos, (EXAWORD)(Par->ColLength), (EXAWORD)(Par->ColLength), (EXAWORD)(Par->ColDecLength), 1); 
#endif		
					Par->DescPos += Par->ColLength;
					break;
				}
				break;
		default :                                                              
			*Err = EXER_MCFUNC;
			return(-1);
		}

	/* ClauseLength refresh */
	Par->ClauseLength += (3+ValLen); 
	return(0);

}                                                                                                                                                    
 
/*--------------------------------------------------------------*/
/* This function is used for the creation of the value3 		*/
/* tokens (in a like clause).														*/
/* INPUT : Par : Parameter structure							*/
/* OUTPUT : Error Code											*/
/*--------------------------------------------------------------*/
FNT_LOC S16 NPos_CreateTokVal3 (Par, EscBool, Err) 
	PARAM *Par;                        
	S8 EscBool;
	S16PTR Err;
{
	U16 i;
	U16 ValLen;
	S16 EscFlag;
	U8 c;

	EscFlag = 1;
	i=0;

	/* Token Type (1 octet) : value -> 2 */
	Par->DescPtr[Par->DescPos++] = (U8)2; 
	
	/* Token length (2 octets) : ValLen */
	ValLen = Par->ValLength;
	balputw ( ValLen , (Par->DescPtr+Par->DescPos) );
	Par->DescPos += 2;	

	/* Descriptor refresh */
	if (EscBool==0)
		{
			/* 12/10/98 modified by pfi	*/
			/*
			while ((c=Par->CurVal[i])!='\0' & i<256)
			*/
			while (i<Par->ValBytes)
				{
				c=Par->CurVal[i];
				switch(c)
					{
					case '*':
					case '#':
					case '!':
					case '\\':
						Par->DescPtr[Par->DescPos] = '\\';
						Par->DescPos += 1;
						Par->DescPtr[Par->DescPos] = c;
						Par->DescPos += 1;
						break;
					case '%':
						Par->DescPtr[Par->DescPos] = '*';
						Par->DescPos += 1;
						break;
					case '_':
						Par->DescPtr[Par->DescPos] = '!';
						Par->DescPos += 1;
						break;
					default:
						Par->DescPtr[Par->DescPos] = c;
						Par->DescPos += 1;
						break;
					}
					i++;
				}
		}
	else
		/* on a un tueur de jocker */
		{
			/* 12/10/98 modified by pfi	*/
			/*
		while ((c=Par->CurVal[i])!='\0' & i<256)
			*/
			while (i<Par->ValBytes)
			{
			c=Par->CurVal[i];
			if (c == Par->EscVal[0])
				EscFlag *= -1;
			else if (c == '*' || c == '#' || c == '!' || c == '\\')
				{
				/* si on a trouve un tueur de jocker avant, il ne sert a rien! */
				EscFlag = 1;
				Par->DescPtr[Par->DescPos] = '\\';
				Par->DescPos += 1;
				Par->DescPtr[Par->DescPos] = c;
				Par->DescPos += 1;
				}
			else if (c == '%')
				{
				if (EscFlag == -1)
					{
					/* on a un tueur de jocker devant le caractere */
					Par->DescPtr[(Par->DescPos)++] = '%';

					/*Par->DescPos += 1;*/
					}
				else
					{
					Par->DescPtr[Par->DescPos] = '*';
					Par->DescPos += 1;
					}
				EscFlag = 1;
				}
			else if (c == '_')
				{
				if (EscFlag == -1)
					{
					/* on a un tueur de jocker */
					Par->DescPtr[Par->DescPos] = '_';
					Par->DescPos += 1;
					}
				else
					{
					/* on a un tueur de jocker */
					Par->DescPtr[Par->DescPos] = '!';
					Par->DescPos += 1;
					}
				EscFlag = 1;
				}
			else
				{
				EscFlag = 1;
				Par->DescPtr[Par->DescPos] = c;
				Par->DescPos += 1;
				}
			i++;
			}
		}
	/* ClauseLength refresh */
	Par->ClauseLength += (3+ValLen); 
	return(0);
}

/*----------------------------------------------------------------*/
/* Compare deux chaines de charcteres sans tenir compte des		  */
/* majuscules et minuscules										  */
/* INPUT :	- U8PTR chaine1										  */
/*			- U8PTR chaine2										  */
/* OUPUT :	- 0 -> OK!!											  */
/*			- 1 -> chaines differentes							  */
/*----------------------------------------------------------------*/
U16 MY_strcmp2 (chaine1, chaine2)
	U8PTR chaine1;
	U8PTR chaine2;
{
	U8 l1, l2, c1, c2;
	U16 i;

	l1 = strlen(chaine1);
	l2 = strlen(chaine2);

	if (l1 != l2)
		return (1);

	for(i=0; i<l1; i++)
		{
		c1 = chaine1[i];
		c2 = chaine2[i];

		if (c1 >= 'a' && c1 <= 'z')
			/* on le passe en majuscule */
			c1 = c1 - 32;
		if (c2 >= 'a' && c2 <= 'z')
			/* on le passe ne majuscule */
			c2 = c2 - 32;

		if (c1 != c2)
			return(1);
		}

	return(0);
}

/*-------------------------------------------------------------*/
/*    */
/*-------------------------------------------------------------*/
FNT_LOC S16 NPos_NewLength (Par, Err)
	PARAM *Par;
	S16PTR Err;
 {

	U16 i;
	U16 NLength = 0;
	U8 c;

	i=0;
	if (Par->EscBool==0)
		{
		/* on ne traite pas les tueurs de jockers */
		/* 12/10/98 modified by pfi	*/
		/*
		while ((c=Par->CurVal[i]) != '\0' & i<256)
		*/
		while (i<Par->ValBytes)
			{
			c=Par->CurVal[i];
			switch (c)
				{
				case '*' :
				case '#' :
				case '!' :
				case '\\' :
					NLength += 2;
					break;
				default :
					NLength += 1;
					break;
				}
			i++;
			}
		
		if (i>=256)
			{
			*Err=EXER_MCFUNC;
			return(-1);
			}
		}
	else
		{
		/* on traite les tueurs de jockers */
		/* 12/10/98 modified by pfi	*/
		/*
		while ((c=Par->CurVal[i]) != '\0' & i<256)
		*/
		while (i<Par->ValBytes)
			{
			c=Par->CurVal[i];
			if (c == Par->EscVal[0])
				NLength += 0;
			else if (c == '*' || c == '#' || c == '!')
				NLength += 2;
			else 
				NLength += 1;
			
			i++;
			}
		
		if (i>=256)
			{
			*Err=EXER_MCFUNC;
			return(-1);
			}
		}

	Par->ValLength = NLength;
	return(0);

 }

