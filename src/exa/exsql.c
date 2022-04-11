#ifndef	_EXSQL_C
#define	_EXSQL_C

/*==========================================================================*/
/* SQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQL */
/* SQLSQLSQLSQLSQL                                          SQLSQLSQLSQLSQL */
/* SQLSQLSQLSQLSQL              ABAL SQL NATIF              SQLSQLSQLSQLSQL */
/* SQLSQLSQLSQLSQL                                          SQLSQLSQLSQLSQL */
/* SQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQL */
/*==========================================================================*/

/* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 * 01/02/12 : (#BG) Creation.
 */

#include "exsqlstub.c"

/* --------------------------------------------------------------------------
 *	Rappels sur les types
 * --------------------------------------------------------------------------
 *
 * Correspondance des  types SQLpgres/Abal
 * Type SQLpgres     Type Abal
 * integer           :  
 * character(n)      $(n)  
 * date              $(10)                 
 * smallint          %  
 * numeric(n,d)      BCD
 * smallint          # 
 * 
 * Types Abal pour l'Executeur (cf kernel\exvtype.h)
 * VARB_INT8	0x0000		#
 * VARB_INT16	0x0001		%
 * VARB_BCD	0x0002		Bcd
 * VARB_STR	0x0003		$
 * VARB_FOUR	0x0004		#
 * VARB_INT32	0x0005		%%	ou :
 * VARB_INT64	0x0006		::	ou &
 */

/* --------------------------------------------------------------------------
 *	Definitions et prototypes
 * --------------------------------------------------------------------------
 */

#include "exsql.h"


/* --------------------------------------------------------------------------
 *	Impementation des ordres NGF SQL
 * --------------------------------------------------------------------------
 */

EXAWORD sql_close(EX_FILE_HANDLE HdleConn)
{
	PSQL_STATMENT	pSqlStmt = (PSQL_STATMENT)fidstmtlst;
	int	Ret = 0;

	// Fermeture des requetes en cours (liberation si succes et avec traitement d'erreur)
	while(pSqlStmt != (PSQL_STATMENT)NULL)
	{
		fidstmtlst = pSqlStmt->Next;
		Ret = MASQL_clear(fidreel, pSqlStmt->HdleStmt);
		if (!Ret)
			free(pSqlStmt);
		else
			break;
		pSqlStmt = (PSQL_STATMENT)fidstmtlst;
	}

	// Deconnexion de la base
	if (!Ret)
		if (Ret = MASQL_disconnect(HdleConn) == 0)
			fidreel = EX_UNUSED_HANDLE;

	return (EXAWORD)Ret;
}


/* --------------------------------------------------------------------------

	FCT sf_sql

	Aiguillage selon le code NGF

	E/ 
	S/ Code retour : 
*/
EXAWORD	sf_sql(EXAWORD opcode)
{
	EXAWORD	Ret = 0;

	switch (opcode)
	{
		case _NGF_CONNECT:
			return ((EXAWORD)sql_connect());

		case _NGF_BEGIN:
			return ((EXAWORD)sql_begin());

		case _NGF_COMMIT:
			return ((EXAWORD)sql_commit());

		case _NGF_ROLLBACK:
			return ((EXAWORD)sql_rollback());

		case _NGF_PREPARE:
			return ((EXAWORD)sql_prepare());

		case _NGF_EXEC:
			return ((EXAWORD)sql_exec());

		case _NGF_GETROWCOL:
			return ((EXAWORD)sql_getrowcol());

		case _NGF_GETCOLNAME:
			return ((EXAWORD)sql_getcolname());

		case _NGF_FETCH:	
			return ((EXAWORD)sql_fetch());

		case _NGF_GETFIELD:
			return ((EXAWORD)sql_getfield());

		case _NGF_DROP:
			return ((EXAWORD)sql_drop());

		case _NGF_BINDPARAM:
			return ((EXAWORD)sql_bindparam());

		case _NGF_BINDCOL:
			return ((EXAWORD)sql_bindcol());

		case _NGF_GETSQLERROR:
			return ((EXAWORD)sql_getsqlerror());

		case _NGF_GETSERVICEINFO:
			return ((EXAWORD)sql_getserviceinfo());

		default			: 	
			return(56);
	}

	return Ret;
}


/* --------------------------------------------------------------------------

	FCT sql_connect

	Traitement de _NGF_CONNECT

	E/ 
	S/ Code retour : 
*/
int sql_connect()
{
	char ConnInfos[MAX_SQL_BUF];
	EX_FILE_HANDLE HdleConn;
	BPTR ptr;
	int bAdrIP = 1;
	int Ret = 0;

	// Une seule connexion geree à la fois!
	if (fidreel != EX_UNUSED_HANDLE)
	{
		if ((Ret = MASQL_disconnect(fidreel)) == 0)
			fidreel = EX_UNUSED_HANDLE;
		else
			return Ret;
	}

	// Parametre 1 (IN): Options
	if (fargset(1) == SOFTERROR)  
		return(err_val);
	else if (worktyp1 != VARB_STR)
		return (EXABSQLerr_InvalidAbalParamType);
	else
	{
		// Longueur effective
		worklen1 = lenuse(workptr1, worklen1);

		// Suppression des eventuels espaces en debut de chaine
		while ((worklen1 > 0) && (*workptr1 == ' ')) 
		{ 
			workptr1++; 
			worklen1--; 
		}
	}

	if (fidhost == (BPTR)0)
		// Assignation non effectue!
		return (EXABSQLerr_InvalidAssignation);

	memset(ConnInfos, '\0', MAX_SQL_BUF);

	// host/hostaddr
	for (ptr = fidhost; *ptr != '\0'; ptr++)
	{
		if ((*ptr != '.') && ((*ptr < '0') || (*ptr > '9')))
			// Pas une adresse IP
			bAdrIP = 0;
			break;
	}
	if (bAdrIP)
		strcpy(ConnInfos, "hostaddr=");	//IP
	else
		strcpy(ConnInfos, "host=");		//Nom
	strcat(ConnInfos, fidhost);

	// port
	if (fidport != (BPTR)0)
	{
		strcat(ConnInfos, ";port=");
		strcat(ConnInfos, fidport);
	}

	// dbname
	strcat(ConnInfos, ";dbname=");
	strcat(ConnInfos, fidname);

	// options
	// TODO: Merge options/fidoptions
	if (worklen1)
	{
		strcat(ConnInfos, ";");
		strncpy(ConnInfos + strlen(ConnInfos), workptr1, worklen1);
	}
	else if (fidoption !=(BPTR)0)
	{
		strcat(ConnInfos, ";");
		strcat(ConnInfos, fidoption);
	}

	// Appel de la methode d'acces SQL
	Ret = MASQL_connect(ConnInfos, strlen(ConnInfos), (void*)&HdleConn);
	if (!Ret || (Ret == ABSQLerr_SqlError))
	{
		// Le handle est quand même valide pour interroger postgres avec MASQL_getsqlerror()!
		fidreel = HdleConn;
	}

	return(Ret);
}


/* --------------------------------------------------------------------------

	FCT sql_begin

	Traitement de _NGF_BEGIN

	E/ 
	S/ Code retour : 
*/
int sql_begin()
{
	BPTR pBuf;
	int LgBuf = 0;
	int Level = 0;
	int Ret = 0;

	if (fidreel == EX_UNUSED_HANDLE)
		return (EXABSQLerr_InvalidConnexionHandle);

	// Parametre 1, optionnel (IN): Level
	if ( fargset(1) != SOFTERROR )
	{
		if (worktyp1 == VARB_STR)
		{
			if ((LgBuf = GetStrParam(workptr1, worklen1, &pBuf)) == 0)
				return (EXABSQLerr_InvalidAbalParamValue);

			if (!cstrcmpi(pBuf, ISOLATION_LEVEL_1))
				Level = ISOLATION_LEVEL_1_ID;
			else if (!cstrcmpi(pBuf, ISOLATION_LEVEL_2))
				Level = ISOLATION_LEVEL_2_ID;
			else if (!cstrcmpi(pBuf, ISOLATION_LEVEL_3))
				Level = ISOLATION_LEVEL_3_ID;
			else if (!cstrcmpi(pBuf, ISOLATION_LEVEL_4))
				Level = ISOLATION_LEVEL_4_ID;

			free(pBuf);
		}
		else if (worktyp1 == VARB_BCD)
			Level = bcdtoi(workptr1, worklen1);
		else
			Level = workval1;
	}
	else
		Level = ISOLATION_LEVEL_3_ID;

	if (!Level || Level > ISOLATION_LEVEL_4_ID)
		return (EXABSQLerr_InvalidAbalParamValue);

	Ret = MASQL_beginTrans(fidreel, Level);

	return Ret;
}


/* --------------------------------------------------------------------------

	FCT sql_commit

	Traitement de _NGF_COMMIT

	E/ 
	S/ Code retour : 
*/
int sql_commit()
{
	int Ret = 0;

	if (fidreel == EX_UNUSED_HANDLE)
		return (EXABSQLerr_InvalidConnexionHandle);

	Ret = MASQL_commitTrans(fidreel);

	return Ret;
}


/* --------------------------------------------------------------------------

	FCT sql_rollback

	Traitement de _NGF_ROLLBACK

	E/ 
	S/ Code retour : 
*/
int sql_rollback()
{
	int Ret = 0;

	if (fidreel == EX_UNUSED_HANDLE)
		return (EXABSQLerr_InvalidConnexionHandle);

	Ret = MASQL_rollbackTrans(fidreel);

	return Ret;
}


/* --------------------------------------------------------------------------

	FCT sql_prepare

	Traitement de _NGF_PREPARE

	E/ 
	S/ Code retour : 
*/
int sql_prepare()
{
	BPTR pQueryName;
	int LgQueryName = 0;
	BPTR pQuery;
	int LgQuery = 0;
	int NbParams = 0;
	EX_FILE_HANDLE HdleStmt = 0;
	int Ret = 0;

	if (fidreel == EX_UNUSED_HANDLE)
		return (EXABSQLerr_InvalidConnexionHandle);

	// Parametre 1 (IN): Query name
	if ( fargset(1) == SOFTERROR )  
		return(err_val);
	else if (worktyp1 != VARB_STR)
		return (EXABSQLerr_InvalidAbalParamType);
	else if ((LgQueryName = GetStrParam(workptr1, worklen1, &pQueryName)) == 0)
		return (EXABSQLerr_InvalidAbalParamValue);

	// Parametre 2 (IN): Query
	if ( fargset(1) == SOFTERROR )  
		return(err_val);
	else if (worktyp1 != VARB_STR)
		return (EXABSQLerr_InvalidAbalParamType);
	else if ((LgQuery = GetStrParam(workptr1, worklen1, &pQuery)) == 0)
		return (EXABSQLerr_InvalidAbalParamValue);

	// Parametre 3 (OUT): Handle de requete
	if (fargset(0) == SOFTERROR)  
		return(err_val);
	else if ((worktyp1 != VARB_INT32) && (worktyp1 != VARB_INT64))
		return (EXABSQLerr_InvalidAbalParamType);

	// Parametre 4, optionnel (IN): Nombre de parametres (pas exploité actuellement)
	if ( fargset(2) != SOFTERROR )
	{
		if (worktyp2 == VARB_STR)
			return (EXABSQLerr_InvalidAbalParamType);
		else if (worktyp2 == VARB_BCD)
			NbParams = bcdtoi(workptr2, worklen2);
		else
			NbParams = workval2;
	}

	Ret = MASQL_prepare(fidreel, pQueryName, LgQueryName, pQuery, LgQuery, NbParams, FORMAT_RES_BIN, &HdleStmt);

	if (!Ret)
	{
		balputl(HdleStmt, workptr1);
		AddSqlStatement(HdleStmt);
	}

	free(pQuery);
	free(pQueryName);

	return Ret;
}


/* --------------------------------------------------------------------------

	FCT sql_exec

	Traitement de _NGF_EXEC

	Dans le cas d'une requete preparee, si le nombre de parametres est insuffisant,
	MASQL_execPrepared() retournera une erreur.

	E/ 
	S/ Code retour : 
*/
int sql_exec()
{
	int ExecType;
	char* pQuery;
	int LgQuery = 0;
	EX_FILE_HANDLE HdleStmt = 0;
	int FormatRes = FORMAT_RES_TEXT;
	int Ret = 0;

	if (fidreel == EX_UNUSED_HANDLE)
		return (EXABSQLerr_InvalidConnexionHandle);

	// Parametre 0 (IN) auto-genere par OTR: Type de requete preparee ou non
	if ( fargset(1) == SOFTERROR )  
		return(err_val);

	if (workval1 == 0)
	{
		// Requete non preparee

		// Parametre 1 (IN): Query
		if ( fargset(1) == SOFTERROR )  
			return(err_val);
		else if (worktyp1 != VARB_STR)
			return (EXABSQLerr_InvalidAbalParamType);
		else if ((LgQuery = GetStrParam(workptr1, worklen1, &pQuery)) == 0)
			return (EXABSQLerr_InvalidAbalParamValue);

		// Parametre 2 (OUT): Handle de requete
		if (fargset(0) == SOFTERROR)  
			return(err_val);
		else if ((worktyp1 != VARB_INT32) && (worktyp1 != VARB_INT64))
			return (EXABSQLerr_InvalidAbalParamType);

		// Parametre 3, optionnel en syntaxe Abal mais auto-genere par OTR (IN): Format du résultat (0/1)
		if (fargset(2) == SOFTERROR)  
			return (err_val);
		else
			FormatRes = workval2;
		if ((FormatRes != 0) && (FormatRes != 1))
			return (EXABSQLerr_InvalidAbalParamValue);

		Ret = MASQL_exec(fidreel, pQuery, LgQuery, FormatRes, &HdleStmt);

		if (!Ret)
		{
			balputl(HdleStmt, workptr1);
			AddSqlStatement(HdleStmt);
		}

		free(pQuery);
	}
	else if (workval1 == 1)
	{
		// Requete preparee
		
		BPTR pParam;
		int ParamType;
		int ParamLgType;
		int ParamValue;
		int ParamLgOrDec = -1;
		int NumParam = 0;

		// Parametre 1 (IN): Handle de requete
		if ( fargset(1) == SOFTERROR )  
			return(err_val);
		else if ((worktyp1 != VARB_INT32) && (worktyp1 != VARB_INT64))
			return (EXABSQLerr_InvalidAbalParamType);
		else
			HdleStmt = workval1;

		// Parametre 2 (IN), optionnel en syntaxe Abal mais auto-genere par OTR: Format du résultat (0/1)
		if (fargset(1) == SOFTERROR)  
			return(err_val);
		else
			FormatRes = workval1;

		// Parametres suivants (IN): Parametres de la requete
		while(fargset(1) != SOFTERROR)
		{
			if ((Ret = GetParamInfo(&pParam, &ParamType, &ParamLgType, &ParamValue, &ParamLgOrDec, PARAM_IN)) != 0)
				return Ret;

			// Le parametre doit etre passe au format binaire qqst le format du resultat,
			// c'est a dire adresse de la variable + type + longueur.
			// Les valeurs SQL NULL ne peuvent etre gerees dans le cadre d'un EXEC avec BINDPARAM implicites.
			if ((Ret = MASQL_bindParam(fidreel, HdleStmt, NumParam++, pParam, ParamType, ParamLgType, ParamLgOrDec, NULL, 0, 0)) != 0)
				return Ret;
		}

		Ret = MASQL_execPrepared(fidreel, HdleStmt, FormatRes);
	}
	else
		return (EXABSQLerr_InvalidAbalParamValue);

	return Ret;
}


/* --------------------------------------------------------------------------

	FCT sql_getrowcol

	Traitement de _NGF_GETROWCOL

	E/ 
	S/ Code retour : 
*/
int sql_getrowcol()
{
	EX_FILE_HANDLE HdleStmt = 0;
	int NbRow = 0;
	int NbCol = 0;
	int Ret = 0;

	if (fidreel == EX_UNUSED_HANDLE)
		return (EXABSQLerr_InvalidConnexionHandle);

	// Parametre 1 (IN): Handle de requete
	if (GetHandleStatement(&HdleStmt) != 0)
		return (EXABSQLerr_InvalidStmtHandle);

	if ((Ret = MASQL_getStmtRows(fidreel, HdleStmt, &NbRow)) != 0)
		return Ret;

	// Parametre 2 (OUT): Nombre de lignes
	if (fargset(0) == SOFTERROR)  
		return(err_val);

	switch (worktyp1)
	{
		case VARB_FOUR:
		case VARB_INT8:
			return (EXABSQLerr_InvalidAbalParamType);

		case VARB_INT16:
			if (NbRow < 0xFFFF)
			{
				balputw((unsigned short)NbRow, workptr1);
			}
			else
				return (EXABSQLerr_NumOverflow);
			break;

		case VARB_INT32:
			balputl((unsigned long)NbRow, workptr1);
			break;

		case VARB_INT64:
			balput64((unsigned long long)NbRow, workptr1);
			break;

		case VARB_BCD:
			ltobcd((unsigned long)NbRow, workptr1, worklen1);
			break;

		case VARB_STR:
			itoa((unsigned long)NbRow, workptr1, worklen1);
			break;
	}

	if ((Ret = MASQL_getStmtColumns(fidreel, HdleStmt, &NbCol)) != 0)
		return Ret;

	// Parametre 3 (OUT): Nombre de colonnes
	if (fargset(0) == SOFTERROR)  
		return(err_val);

	switch (worktyp1)
	{
		case VARB_FOUR:
		case VARB_INT8:
			return (EXABSQLerr_InvalidAbalParamType);

		case VARB_INT16:
			if (NbCol < 0xFFFF)
			{
				balputw((unsigned short)NbCol, workptr1);
			}
			else
				return (EXABSQLerr_NumOverflow);
			break;

		case VARB_INT32:
			balputl((unsigned long)NbCol, workptr1);
			break;

		case VARB_INT64:
			balput64((unsigned long long)NbCol, workptr1);
			break;

		case VARB_BCD:
			ltobcd((unsigned long)NbCol, workptr1, worklen1);
			break;

		case VARB_STR:
			itoa((unsigned long)NbCol, workptr1, worklen1);
			break;
	}

	return Ret;
}


/* --------------------------------------------------------------------------

	FCT sql_getcolname

	Traitement de _NGF_GETCOLNAME

	E/ 
	S/ Code retour : 
*/
int sql_getcolname()
{
	EX_FILE_HANDLE HdleStmt = 0;
	int NumCol = -1;
	BPTR pBuf;
	int LgBuf;
	int Ret = 0;

	if (fidreel == EX_UNUSED_HANDLE)
		return (EXABSQLerr_InvalidConnexionHandle);

	// Parametre 1 (IN): Handle de requete
	if (GetHandleStatement(&HdleStmt) != 0)
		return (EXABSQLerr_InvalidStmtHandle);

	// Parametre 2 (IN): Numero de colonne
	if (fargset(1) == SOFTERROR)  
		return(err_val);
	else if (worktyp1 == VARB_STR)	// 3
		return (EXABSQLerr_InvalidAbalParamType);
	else if (worktyp1 == VARB_BCD)
		NumCol = bcdtoi(workptr1, worklen1) - 1;
	else
		NumCol = workval1 - 1;
	
	if (NumCol < 0)
		return (EXABSQLerr_InvalidAbalParamValue);

	// Parametre 3 (OUT): Buffer de reception
	if (fargset(0) == SOFTERROR)  
		return(err_val);
	else if (worktyp1 != VARB_STR)	// 3
		return (EXABSQLerr_InvalidAbalParamType);
	else
		LgBuf = worklen1;

	// Parametre 4, optionnel (IN): Longueur effective du buffer de reception
	if ( fargset(2) != SOFTERROR )
		if (worktyp2 == VARB_STR)	// 3
			return (EXABSQLerr_InvalidAbalParamType);
		else if (worktyp2 == VARB_BCD)
			LgBuf = bcdtoi(workptr2, worklen2);
		else
			LgBuf = workval2;

	if ((pBuf = allocate(LgBuf + 1)) == NULL)
		return (EXER_MEMFULL);

	if ((Ret = MASQL_getStmtColName(fidreel, HdleStmt, NumCol, (char*)pBuf, LgBuf)) != 0)
		return Ret;

	// Copie du nom dans la variable Abal
	memset(workptr1, ' ', worklen1);
	memcpy(workptr1, pBuf, strlen(pBuf));
	free(pBuf);

	return Ret;
}


/* --------------------------------------------------------------------------

	FCT sql_fetch

	Traitement de _NGF_FETCH

	E/ 
	S/ Code retour : 
*/
int sql_fetch()
{
	EX_FILE_HANDLE HdleStmt = 0;
	int Sens = 0;
	int NbCol = 0;
	int NumCol = 0;
	BPTR pCol;
	int ColType;
	int ColLgType;
	int ColValue;
	int ColLgOrDec;
	int Ret = 0;

	if (fidreel == EX_UNUSED_HANDLE)
		return (EXABSQLerr_InvalidConnexionHandle);

	// Parametre 1 (IN): Handle de requete
	if (GetHandleStatement(&HdleStmt) != 0)
		return (EXABSQLerr_InvalidStmtHandle);

	// Parametre 2 (IN): Sens
	if ( fargset(1) == SOFTERROR )  
		return(err_val);
	
	if (worktyp1 == VARB_STR)
	{
		BPTR pValue;
		int LgValue = 0;

		if ((LgValue = GetStrParam(workptr1, worklen1, &pValue)) == 0)
			return (EXABSQLerr_InvalidAbalParamValue);

		if (!cstrcmpi(pValue, FETCH_FIRST))
			Sens = FETCH_FIRST_ID;
		else if (!cstrcmpi(pValue, FETCH_LAST))
			Sens = FETCH_LAST_ID;
		else if (!cstrcmpi(pValue, FETCH_NEXT))
			Sens = FETCH_NEXT_ID;
		else if (!cstrcmpi(pValue, FETCH_PRIOR))
			Sens = FETCH_PRIOR_ID;

		free(pValue);
	}
	else if (worktyp1 == VARB_BCD)
		Sens = bcdtoi(workptr1, worklen1);
	else
		Sens = workval1;

	if (!Sens || Sens > FETCH_PRIOR_ID)
		return (EXABSQLerr_InvalidAbalParamValue);

	// Parametres suivants (OUT): Resultats
	while(fargset(0) != SOFTERROR)
	{
		if ((Ret = GetParamInfo(&pCol, &ColType, &ColLgType, &ColValue, &ColLgOrDec, PARAM_OUT)) != 0)
			return Ret;

		if (ColType == ABAL_TY_DECIMAL)
			// On ne doit pas tenir compte du nombre de décimales courant du BCD pour une valeur résultat!
			ColLgOrDec = -1;

		// Verifier la coherence des types suivant que le resultat est attendu au format TEXT ou BIN
		// => Fait par la librarie SQLpgres.

		// Le service SQLpgres n'ajoute pas de \0 final a la valeur resultat, donc on peut passer directement
		// workptr1/worklen1 sans allouer un buffer intermediaire avec un octet de plus.
		// Les valeurs SQL NULL ne peuvent etre gerees dans le cadre d'un FETCH avec BINDCOL implicites.
		if ((Ret = MASQL_bindCol(fidreel, HdleStmt, NumCol++, pCol, ColType, ColLgType, ColLgOrDec, NULL, 0, 0)) != 0)
			return Ret;
	}

	Ret = MASQL_fetchRow(fidreel, HdleStmt, Sens);

	return Ret;
}


/* --------------------------------------------------------------------------

	FCT sql_getfield

	Traitement de _NGF_GETFIELD

	E/ 
	S/ Code retour : 
*/
int sql_getfield()
{
	EX_FILE_HANDLE HdleStmt = 0;
	int NumRow = -1;
	int NumCol = -1;
	BPTR pCol;
	int ColType;
	int ColLgType;
	int ColValue;
	int ColLgOrDec;
	int ColLgOrDec2;
	BPTR pExt = NULL;
	int ExtType = -1;
	int ExtLgType = 0;
	int ExtValue = 0;
	int ExtLgOrDec = -1;
	int Ret = 0;

	if (fidreel == EX_UNUSED_HANDLE)
		return (EXABSQLerr_InvalidConnexionHandle);

	// Parametre 1 (IN): Handle de requete
	if (GetHandleStatement(&HdleStmt) != 0)
		return (EXABSQLerr_InvalidStmtHandle);

	// Parametre 2 (IN): Numero de ligne
	if (fargset(1) == SOFTERROR)  
		return(err_val);
	else if (worktyp1 == VARB_STR)
		return (EXABSQLerr_InvalidAbalParamType);
	else if (worktyp1 == VARB_BCD)
		NumRow = bcdtoi(workptr1, worklen1) - 1;
	else
		NumRow = workval1 - 1;
	
	if (NumRow < 0)
		return (EXABSQLerr_InvalidAbalParamValue);

	// Parametre 3 (IN): Numero de colonne
	if (fargset(1) == SOFTERROR)  
		return(err_val);
	else if (worktyp1 == VARB_STR)
		return (EXABSQLerr_InvalidAbalParamType);
	else if (worktyp1 == VARB_BCD)
		NumCol = bcdtoi(workptr1, worklen1) - 1;
	else
		NumCol = workval1 - 1;
	
	if (NumCol < 0)
		return (EXABSQLerr_InvalidAbalParamValue);

	// Paramètre 4, optionnel (OUT): Resultat pour le champ
	if (fargset(0) != SOFTERROR)
		if ((Ret = GetParamInfo(&pCol, &ColType, &ColLgType, &ColValue, &ColLgOrDec, PARAM_OUT)) != 0)
			return Ret;

	// Parametre 5, optionnel (IN):
	// Longueur effective du parametre si le parametre 3 est une chaine (>=0)
	// Nombre de décimales explicite si le parametre 3 est un BCD (>=0)
	// Ignore si valeur -1
	if ( fargset(1) != SOFTERROR )
	{
		// Recuperation de la valeur...
		if (worktyp1 == VARB_STR)
			return (EXABSQLerr_InvalidAbalParamType);
		else if (worktyp1 == VARB_BCD)
			ColLgOrDec2 = bcdtoi(workptr1, worklen1);
		else
			ColLgOrDec2 = workval1;

		// ...qui doit etre positive ou nulle
		if (ColLgOrDec2 != -1)
		{
			if (ColLgOrDec2 >= 0)
				ColLgOrDec = ColLgOrDec2;
			else
				return (EXABSQLerr_InvalidAbalParamValue);
		}
	}
	else if (ColType == ABAL_TY_DECIMAL)
		// On ne doit pas tenir compte du nombre de décimales courant du BCD pour une valeur résultat!
		ColLgOrDec = -1;

	// Paramètre 6, optionnel (OUT): Gestion des valeurs SQL NULL, ffu
	// Permet de savoir que la valeur retournee par GETFIELD est une valeur SQL NULL: "NULL" si type chaine ou -1 si type numerique
	// Ce parametre doit donc etre initialise avec une valeur differente de "NULL" ou -1 avant l'appel a GETFIELD.
	if (fargset(0) != SOFTERROR)
		if ((Ret = GetParamInfo(&pExt, &ExtType, &ExtLgType, &ExtValue, &ExtLgOrDec, PARAM_OUT)) != 0)
			return Ret;

	Ret = MASQL_getValue(fidreel, HdleStmt, NumRow, NumCol, pCol, ColType, ColLgType, ColLgOrDec, pExt, ExtType, ExtLgType);

	return Ret;
}


/* --------------------------------------------------------------------------

	FCT sql_drop

	Traitement de _NGF_DROP

	E/ 
	S/ Code retour : 
*/
int sql_drop()
{
	EX_FILE_HANDLE HdleStmt = 0;
	int Ret = 0;

	if (fidreel == EX_UNUSED_HANDLE)
		return (EXABSQLerr_InvalidConnexionHandle);

	// Parametre 1 (IN): Handle de requete
	if (GetHandleStatement(&HdleStmt) != 0)
		return (EXABSQLerr_InvalidStmtHandle);

	Ret = MASQL_clear(fidreel, HdleStmt);

	if (!Ret)
		Ret = LiberateSqlStatement(HdleStmt);

	return Ret;
}


/* --------------------------------------------------------------------------

	FCT sql_bindparam

	Traitement de _NGF_BINDPARAM

	E/ 
	S/ Code retour : 
*/
int sql_bindparam()
{
	EX_FILE_HANDLE HdleStmt = 0;
	int NumParam = 0;
	BPTR pParam;
	int ParamType;
	int ParamLgType;
	int ParamValue;
	int ParamLgOrDec = -1;
	int ParamLgOrDec2 = -1;
	BPTR pExt = NULL;
	int ExtType = -1;
	int ExtLgType = 0;
	int ExtValue = 0;
	int ExtLgOrDec = -1;
	int Ret = 0;

	if (fidreel == EX_UNUSED_HANDLE)
		return (EXABSQLerr_InvalidConnexionHandle);

	// Parametre 1 (IN): Handle de requete
	if (GetHandleStatement(&HdleStmt) != 0)
		return (EXABSQLerr_InvalidStmtHandle);

	// Parametre 2 (IN): Numero de colonne
	if (fargset(1) == SOFTERROR)  
		return(err_val);
	else if (worktyp1 == VARB_STR)
		return (EXABSQLerr_InvalidAbalParamType);
	else if (worktyp1 == VARB_BCD)
		NumParam = bcdtoi(workptr1, worklen1) - 1;
	else
		NumParam = workval1 - 1;
	
	if (NumParam < 0)
		return (EXABSQLerr_InvalidAbalParamValue);

	// Parametre 3 (IN): Parametre de la requete pour la colonne
	if (fargset(1) == SOFTERROR)
		return(err_val);
	else if ((Ret = GetParamInfo(&pParam, &ParamType, &ParamLgType, &ParamValue, &ParamLgOrDec, PARAM_IN)) != 0)
		return Ret;

	// Parametre 4, optionnel (IN):
	// Longueur effective du parametre si le parametre 3 est une chaine (>0)
	// Nombre de décimales explicite si le parametre 3 est un BCD (>=0)
	if ( fargset(1) != SOFTERROR )
	{
		// Recuperation de la valeur...
		if (worktyp1 == VARB_STR)
			return (EXABSQLerr_InvalidAbalParamType);
		else if (worktyp1 == VARB_BCD)
			ParamLgOrDec2 = bcdtoi(workptr1, worklen1);
		else
			ParamLgOrDec2 = workval1;

		// ...qui doit etre strictement positive si c'est une longueur de chaine,
		// positive ou nulle si c'est un nombre de decimales
		if (ParamLgOrDec2 != -1)
		{
			if (((ParamType == ABAL_TY_FIXCHAR) && (ParamLgOrDec2 > 0)) || ((ParamType == ABAL_TY_DECIMAL) && (ParamLgOrDec2 >= 0)))
				ParamLgOrDec = ParamLgOrDec2;
			else
				return (EXABSQLerr_InvalidAbalParamValue);
		}
	}

	// Paramètre 5, optionnel (IN): Gestion des valeurs SQL NULL, ffu
	// Pour indiquer une valeur SQL NULL: "NULL" si type chaine ou -1 si type numerique
	// Permet d'indiquer que la valeur du parametre est une valeur SQL NULL: "NULL" si type chaine ou -1 si type numerique
	// Si ce parametre vaut "NULL" ou -1, les parametres 3 et 4 sont ignores.
	if (fargset(1) != SOFTERROR)
		if ((Ret = GetParamInfo(&pExt, &ExtType, &ExtLgType, &ExtValue, &ExtLgOrDec, PARAM_IN)) != 0)
			return Ret;

	// Le parametre doit etre passe au format binaire qqst le format du resultat,
	// c'est a dire type + adresse de la variable.
	Ret = MASQL_bindParam(fidreel, HdleStmt, NumParam, pParam, ParamType, ParamLgType, ParamLgOrDec, pExt, ExtType, ExtLgType);
	return Ret;
}

/* --------------------------------------------------------------------------

	FCT sql_bindcol

	Traitement de _NGF_BINDCOL

	E/ 
	S/ Code retour : 
*/
int sql_bindcol()
{
	EX_FILE_HANDLE HdleStmt = 0;
	int NumCol = 0;
	BPTR pCol;
	int ColType;
	int ColLgType;
	int ColValue;
	int ColLgOrDec;
	int ColLgOrDec2;
	BPTR pExt = NULL;
	int ExtType = -1;
	int ExtLgType = 0;
	int ExtValue = 0;
	int ExtLgOrDec = -1;
	int Ret = 0;

	if (fidreel == EX_UNUSED_HANDLE)
		return (EXABSQLerr_InvalidConnexionHandle);

	// Parametre 1 (IN): Handle de requete
	if (GetHandleStatement(&HdleStmt) != 0)
		return (EXABSQLerr_InvalidStmtHandle);

	// Parametre 2 (IN): Numero de colonne
	if (fargset(1) == SOFTERROR)  
		return(err_val);
	else if (worktyp1 == VARB_STR)
		return (EXABSQLerr_InvalidAbalParamType);
	else if (worktyp1 == VARB_BCD)
		NumCol = bcdtoi(workptr1, worklen1) - 1;
	else
		NumCol = workval1 - 1;
	
	if (NumCol < 0)
		return (EXABSQLerr_InvalidAbalParamValue);

	// Parametre 3 (OUT): Resultat pour la colonne
	if (fargset(0) == SOFTERROR)
		return(err_val);
	else if ((Ret = GetParamInfo(&pCol, &ColType, &ColLgType, &ColValue, &ColLgOrDec, PARAM_OUT)) != 0)
		return Ret;

	// Parametre 4, optionnel (IN):
	// Longueur effective du parametre si le parametre 3 est une chaine (>=0)
	// Nombre de décimales explicite si le parametre 3 est un BCD (>=0)
	if ( fargset(1) != SOFTERROR )
	{
		// Recuperation de la valeur...
		if (worktyp1 == VARB_STR)
			return (EXABSQLerr_InvalidAbalParamType);
		else if (worktyp1 == VARB_BCD)
			ColLgOrDec2 = bcdtoi(workptr1, worklen1);
		else
			ColLgOrDec2 = workval1;

		// ...qui doit etre strictement positive si c'est une longueur de chaine,
		// positive ou nulle si c'est un nombre de decimales
		if (ColLgOrDec2 != -1)
		{
			if (((ColType == ABAL_TY_FIXCHAR) && (ColLgOrDec2 > 0)) || ((ColType == ABAL_TY_DECIMAL) && (ColLgOrDec2 >= 0)))
				ColLgOrDec = ColLgOrDec2;
			else
				return (EXABSQLerr_InvalidAbalParamValue);
		}
	}
	else if (ColType == ABAL_TY_DECIMAL)
		// On ne doit pas tenir compte du nombre de décimales courant du BCD pour une valeur résultat!
		ColLgOrDec = -1;

	// Paramètre 5, optionnel (OUT): Gestion des valeurs SQL NULL, ffu
	// Permet de savoir que la valeur retournee par FETCH ou GETFIELD est une valeur SQL NULL: "NULL" si type chaine ou -1 si type numerique
	// Ce parametre doit donc etre initialise avec une valeur differente de "NULL" ou -1 avant l'appel a GETFIELD.
	// Si ce parametre retour vaut "NULL" ou -1, les parametres 3 et 4 ne sont pas affectes.
	if (fargset(0) != SOFTERROR)
		if ((Ret = GetParamInfo(&pExt, &ExtType, &ExtLgType, &ExtValue, &ExtLgOrDec, PARAM_OUT)) != 0)
			return Ret;

	Ret = MASQL_bindCol(fidreel, HdleStmt, NumCol, pCol, ColType, ColLgType, ColLgOrDec, pExt, ExtType, ExtLgType);
	
	return Ret;
}


/* --------------------------------------------------------------------------

	FCT sql_getsqlerror

	Traitement de _NGF_GETSQLERROR

	E/ 
	S/ Code retour : 
*/
int sql_getsqlerror()
{
	BPTR 	pBuf;
	BPTR	ptr1;
	BPTR	ptr2;
	int Lg;
	int Ret = 0;

	if (fidreel == EX_UNUSED_HANDLE)
		return (EXABSQLerr_InvalidConnexionHandle);

	// Parametre 1 (OUT): Buffer de reception
	if ( fargset(0) == SOFTERROR )  
		return(err_val);
	else if (worktyp1 != VARB_STR)
		return (EXABSQLerr_InvalidAbalParamType);

	// Parametre 2, optionnel (IN): Longueur du buffer
	if ( fargset(2) != SOFTERROR )
		if (worktyp2 == VARB_STR)
			return (EXABSQLerr_InvalidAbalParamType);
		else if (worktyp2 == VARB_BCD)
			Lg = bcdtoi(workptr2, worklen2);
		else
			Lg = workval2;

	if ((pBuf = allocate(Lg + 1)) == NULL)
		return (EXER_MEMFULL);

	Ret = MASQL_getSqlErrorMessage(fidreel, pBuf, Lg);

	memset(workptr1, ' ', worklen1);

	if (strlen(pBuf) < Lg)
		Lg = strlen(pBuf);

	// Formatage du texte: Postgres envoie 0xOa sans 0x0d ce qui provoque un affichage incorrect avec l'Exécuteur.
	ptr2 = workptr1;
	for (ptr1 = pBuf; (ptr1 < pBuf + Lg) && (ptr2 < workptr1 + worklen1); ptr1++)
	{
		if (*ptr1 == 0x0a)
		{
			*ptr2 = 0x0d;
			ptr2++;
		}
		*ptr2 = *ptr1;
		ptr2++;
	}

	free(pBuf);

	return Ret;
}


/* --------------------------------------------------------------------------

	FCT sql_getserviceinfo

	Traitement de _NGF_GETSERVICEINFO

	E/ 
	S/ Code retour : 
*/
int sql_getserviceinfo()
{
	BPTR pBuf;
	int LgBuf = 0;
	int TypeInfos = 0;
	int Ret = 0;

	if (fidreel == EX_UNUSED_HANDLE)
		return (EXABSQLerr_InvalidConnexionHandle);

	// Parametre 1 (IN): TypeInfos
	if ( fargset(1) == SOFTERROR )  
		return(err_val);
	
	if (worktyp1 == VARB_STR)
	{
		if ((LgBuf = GetStrParam(workptr1, worklen1, &pBuf)) == 0)
			return (EXABSQLerr_InvalidAbalParamValue);

		if (!cstrcmpi(pBuf, GETSERVICEINFO_1))
			TypeInfos = GETSERVICEINFO_1_ID;
		else if (!cstrcmpi(pBuf, GETSERVICEINFO_2))
			TypeInfos = GETSERVICEINFO_2_ID;
		else if (!cstrcmpi(pBuf, GETSERVICEINFO_3))
			TypeInfos = GETSERVICEINFO_3_ID;
		else if (!cstrcmpi(pBuf, GETSERVICEINFO_4))
			TypeInfos = GETSERVICEINFO_4_ID;
		else if (!cstrcmpi(pBuf, GETSERVICEINFO_5))
			TypeInfos = GETSERVICEINFO_5_ID;
		else if (!cstrcmpi(pBuf, GETSERVICEINFO_6))
			TypeInfos = GETSERVICEINFO_6_ID;

		free(pBuf);
	}
	else
		TypeInfos = workval1;

	if (!TypeInfos)
		return (EXABSQLerr_InvalidAbalParamValue);

	// Parametre 2 (OUT): Buffer de reception
	if ( fargset(0) == SOFTERROR )  
		return(err_val);
	else if (worktyp1 != VARB_STR)
		return (EXABSQLerr_InvalidAbalParamType);

	// Parametre 3, optionnel (IN): Longueur du buffer
	if ( fargset(2) != SOFTERROR )
		if (worktyp2 == VARB_STR)
			return (EXABSQLerr_InvalidAbalParamType);
		else if (worktyp1 == VARB_BCD)
			worklen1 = bcdtoi(workptr2, worklen2);
		else
			worklen1 = workval2;

	if ((pBuf = allocate(worklen1+1)) == NULL)
		return (EXER_MEMFULL);

	Ret = MASQL_getInfosVersion(fidreel, TypeInfos, pBuf, worklen1);

	if (!Ret)
	{
		memset(workptr1, ' ', worklen1);
		memcpy(workptr1, pBuf, strlen(pBuf));
	}
	free(pBuf);

	return Ret;
}


/* --------------------------------------------------------------------------
 *	Fonctions de traitement specifique
 * --------------------------------------------------------------------------
 */

static int GetStrParam(BPTR workptr, int worklen, BPTR* ppBuf)
{
	// Longueur effective
	worklen = lenuse(workptr, worklen);

	// Suppression des eventuels espaces en debut de chaine
	while ((worklen > 0) && (*workptr == ' ')) 
	{ 
		workptr++; 
		worklen--; 
	}

	if (worklen)
	{
		if ((*ppBuf = allocate(worklen + 1)))
		{
			strncpy(*ppBuf, workptr, worklen);
			(*ppBuf)[worklen] = '\0';
			return worklen;
		}
	}

	return 0;
}


static int GetHandleStatement(EX_FILE_HANDLE* pHdleStmt)
{
	if ( fargset(1) == SOFTERROR )  
		return(err_val);
	else if ((worktyp1 != VARB_INT32) && (worktyp1 != VARB_INT64))
		return (EXABSQLerr_InvalidAbalParamType);
	else
		*pHdleStmt = workval1;
	return 0;
}


/* --------------------------------------------------------------------------

	FCT GetParamInfo

	Traitement des parametres

	Si InOut = PARAM_IN
		- les constantes numériques (#,%,:) (nommées ou non) sont refusees car l'ordre des octets est inverse
		  sous workptr par rapport a celui d'une variable, ce qui permet d'avoir un seul traitement
		  des parametres ds la lib. SQLpgres.
		- les constantes BCD et chaines de caracteres ($) (nommées ou non) sont acceptees .
	Si InOut = PARAM_OUT
		Toutes les constantes sont naturellement refusees!
		- les constantes chaines et BCD provoquent deja une erreur 115 au niveau de fargset(0).
		- les constantes numeriques (#,%,:) sont refusées ici.

	E/	InOut: Parametre d'Entree ou Sortie

	S/	ppVar: Pointeur sur la variable Abal
		pType: Type de la variable au sens de la librairie SQLpgrs
		pLgType: Longueur de declaration de la variable
		pValue: Valeur si type numerique
		pLgOrDec: Longueur de la variable (dcl) si type $
		         ou nombre de decimales si type BCD (suivant la valeur courante!)

		Code retour : 0 si OK
*/
static int GetParamInfo(BPTR* ppVar, int* pType, int* pLgType, int* pValue, int* pLgOrDec, int InOut)
{
	EXAWORD BcdEval;

	// Refuser toutes les constantes numeriques
	if ((worktyp1 == VARB_INT32) 
	||  (worktyp1 == VARB_INT64) 
	||  (worktyp1 == VARB_INT16) 
   	||  (worktyp1 == VARB_INT8) 
	||  (worktyp1 == VARB_FOUR))
	{
		if ((gldesc == IMMEDIAT) ||	/* 0: Immediate integer 16/32 bits */
			(gldesc == KONSTANT))	/* 1: Constant pointer */
		{
			// C'est une constante!
			return (EXABSQLerr_InvalidAbalParamType);
		}
	}

	*pLgOrDec = 0;

	switch (worktyp1)
	{
		case VARB_FOUR:
		case VARB_INT8:
			*ppVar = workptr1;
			*pType = ABAL_TY_TINYINT;
			*pLgType = ABAL_MAX_LG_TINYINT;
			*pValue = workval1;
			*pLgOrDec = worklen1;
			break;

		case VARB_INT16:
			*ppVar = workptr1;
			*pType = ABAL_TY_SMALLINT;
			*pLgType = ABAL_MAX_LG_SMALLINT;
			*pValue = workval1;
			*pLgOrDec = worklen1;
			break;

		case VARB_INT32:
			*ppVar = workptr1;
			*pType = ABAL_TY_INTEGER;
			*pLgType = ABAL_MAX_LG_INTEGER;
			*pValue = workval1;
			*pLgOrDec = worklen1;
			break;

		case VARB_INT64:
			*ppVar = workptr1;
			*pType = ABAL_TY_LARGEINT;
			*pLgType = ABAL_MAX_LG_LARGEINT;
			*pValue = workval1;
			*pLgOrDec = worklen1;
			break;

		case VARB_BCD:
			*ppVar = workptr1;
			*pType = ABAL_TY_DECIMAL;
			*pLgType = worklen1;	// Nombre d'octets suivant la declaration
			*pValue = bcdtoi(workptr1, worklen1);

			// Attention: le nombre de decimales n'a de sens que pour un BCD affecté d'une valeur, sinon 0!
			BcdEval = bcdeval(workptr1, worklen1);
			*pLgOrDec = BcdEval & 0x000000FF;
			if (!(*pLgOrDec))
				*pLgOrDec = -1;	// Indetermine
			break;

		case VARB_STR:
			*ppVar = workptr1;
			*pType = ABAL_TY_FIXCHAR;
			*pLgType = worklen1;
			*pValue = 0;
			if (InOut == PARAM_IN)
				*pLgOrDec = worklen1;
			else
				*pLgOrDec = worklen1;
			break;
			
		default:
			return (EXABSQLerr_InvalidAbalParamType);
	}
	
	return 0;
}


static int AddSqlStatement(EX_FILE_HANDLE HdleStmt)
{
	PSQL_STATMENT	pSqlStmt;

	if ((pSqlStmt = allocate(sizeof(SQL_STATMENT))) == NULL)
		return (EXER_MEMFULL);

	pSqlStmt->HdleStmt = HdleStmt;

	if (fidstmtlst == (BPTR)NULL)
	{
		pSqlStmt->Next = (BPTR)NULL;
		fidstmtlst = (BPTR)pSqlStmt;
	}
	else
	{
		pSqlStmt->Next = fidstmtlst;
		fidstmtlst = (BPTR)pSqlStmt;
	}

	return 0;
}


static int LiberateSqlStatement(EX_FILE_HANDLE HdleStmt)
{
	PSQL_STATMENT	pSqlStmt = (PSQL_STATMENT)fidstmtlst;
	PSQL_STATMENT	pSqlStmtPrev = (PSQL_STATMENT)NULL;
	int Ret = EXER_MEMFULL;

	while(pSqlStmt != (PSQL_STATMENT)NULL)
	{
		if (pSqlStmt->HdleStmt == HdleStmt)
		{
			if (pSqlStmtPrev != (PSQL_STATMENT)NULL)
				pSqlStmtPrev->Next = pSqlStmt->Next;
			else
				fidstmtlst = pSqlStmt->Next;
			free(pSqlStmt);
			Ret = 0;
			break;
		}

		pSqlStmtPrev = pSqlStmt;
		pSqlStmt = (PSQL_STATMENT)pSqlStmt->Next;
	}

	return Ret;
}

static int LiberateAllSqlStatement(void)
{
	PSQL_STATMENT	pSqlStmt = (PSQL_STATMENT)fidstmtlst;

	while(pSqlStmt != (PSQL_STATMENT)NULL)
	{
		fidstmtlst = pSqlStmt->Next;
		free(pSqlStmt);
		pSqlStmt = (PSQL_STATMENT)fidstmtlst;
	}

	if (fidstmtlst == (BPTR)NULL)
		return 0;
	else
		return (EXER_MEMFULL);
}

#endif	/* _EXSQL_C */
	/* -------- */

