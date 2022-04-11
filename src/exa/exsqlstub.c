#ifndef	_exsqlstub_c
#define	_exsqlstub_c

int MASQL_getStmtColName(EX_FILE_HANDLE HdleConn, EX_FILE_HANDLE HdleStmt, int NumCol, BYTE PTR ColName, int LgColName)
{
	return( SOFTERROR );
}

int MASQL_getStmtColumns(EX_FILE_HANDLE HdleConn, EX_FILE_HANDLE HdleStmt, int* pNbColumns)
{
	return( SOFTERROR );
}

int MASQL_clear(EX_FILE_HANDLE HdleConn, EX_FILE_HANDLE HdleStmt)
{
	return( SOFTERROR );
}

int MASQL_disconnect(EX_FILE_HANDLE HdleConn)
{
	return( SOFTERROR );
}

int MASQL_connect(BYTE PTR ConnInfos, int LgConnInfos, EX_FILE_HANDLE* pHdleConn)
{
	return( SOFTERROR );
}

int MASQL_beginTrans(EX_FILE_HANDLE HdleConn, int Level)
{
	return( SOFTERROR );
}

int MASQL_commitTrans(EX_FILE_HANDLE HdleConn)
{
	return( SOFTERROR );
}

int MASQL_rollbackTrans(EX_FILE_HANDLE HdleConn)
{
	return( SOFTERROR );
}

int MASQL_prepare(EX_FILE_HANDLE HdleConn, BYTE PTR QryName, int LgName, BYTE PTR Query, int LgQuery, int NbParams, int FormatRes, EX_FILE_HANDLE* pHdleStmt)
{
	return( SOFTERROR );
}

int MASQL_execPrepared(EX_FILE_HANDLE HdleConn, EX_FILE_HANDLE HdleStmt, int FormatRes)
{
	return( SOFTERROR );
}

int MASQL_exec(EX_FILE_HANDLE HdleConn, BYTE PTR Query, int LgQuery, int FormatRes, EX_FILE_HANDLE* pHdleStmt)
{
	return( SOFTERROR );
}

int MASQL_bindParam(EX_FILE_HANDLE HdleConn, EX_FILE_HANDLE HdleStmt, int NumParam, BYTE PTR AdrParam, int TypeParam, int LengthParam, int LgDec, BYTE PTR AdrExt, int TypeExt, int LengthExt)

{
	return( SOFTERROR );
}

int MASQL_getStmtRows(EX_FILE_HANDLE fidreel, EX_FILE_HANDLE handle, int * NbRow)
{
	return( SOFTERROR );
}

int MASQL_bindCol(EX_FILE_HANDLE HdleConn, EX_FILE_HANDLE HdleStmt, int NumCol, BYTE PTR AdrCol, int TypeCol, int LengthCol, int LgDec, BYTE PTR AdrExt, int TypeExt, int LengthExt)
{
	return( SOFTERROR );
}

int MASQL_fetchRowNum(EX_FILE_HANDLE HdleConn, EX_FILE_HANDLE HdleStmt, int NumRow)
{
	return( SOFTERROR );
}

int MASQL_fetchRow(EX_FILE_HANDLE HdleConn, EX_FILE_HANDLE HdleStmt, int Sens)
{
	return( SOFTERROR );
}

int MASQL_getValue(EX_FILE_HANDLE HdleConn, EX_FILE_HANDLE HdleStmt, int NumRow, int NumCol, BYTE PTR AdrCol, int TypeCol, int LengthCol, int LgDec, BYTE PTR AdrExt, int TypeExt, int LengthExt)
{
	return( SOFTERROR );
}

int MASQL_getSqlErrorMessage(EX_FILE_HANDLE HdleConn, BYTE PTR ErrorMsg, int LgErrorMsg)
{
	return( SOFTERROR );
}

int MASQL_getInfosVersion(EX_FILE_HANDLE HdleConn, int TypeInfos, BYTE PTR Infos, int LgInfos)
{
	return( SOFTERROR );
}


#endif /* _exsqlstub_c */

