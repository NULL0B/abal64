// ***********************************************************************************************
// * StrmAPI.cpp
// ***********************************************************************************************

#include "bda.h"
#include "FacTrace.h"

#include "CstExt.h"
#include "Table.h"
#include "StrmAPI.h"
#include "Strm.h"

#define CI_MODULE_ID 0x0001

extern "C" TI_TABLE   g_Table[CI_TABLE_SIZE];

// ****************************************************************************
// * StrmGetFree
// * renvoie le 1er numéro logique disponible
// ****************************************************************************
short StrmGetFree(WORD* pNoLog)
{
MI_TRACE_DCL_TFN("StrmGetFree");
int	i;
MI_TRACE_BEGIN();

//for (*pNoLog=0; *pNoLog<CI_TABLE_SIZE; (*pNoLog)++) {
for (i=0; i < CI_TABLE_SIZE; i++ ) {
	if ((!g_Table[i].ObjStrm) && (!g_Table[i].ObjMem)) {
		*pNoLog = i;
		MI_TRACE_RETURN(NO_ERRORS);
		}
	}
*pNoLog = i;
MI_TRACE_RETURN(ERR_BAD_NO);
}

// ****************************************************************************
// * StrmCloseAll
// ****************************************************************************
void StrmCloseAll(void)
{
MI_TRACE_DCL_TFN("StrmCloseAll");
short i;
MI_TRACE_BEGIN();

for (i=0 ; i<CI_TABLE_SIZE ; i++)
	{
	if (g_Table[i].ObjStrm)
		{
		((CStreamBin*)g_Table[i].ObjStrm)->Close();
		delete ((CStreamBin*)g_Table[i].ObjStrm);
		g_Table[i].ObjStrm = NULL;
		g_Table[i].IsLine  = 0;
		}
	}

MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,TFN,"-- End"));
}

// ****************************************************************************
// * StrmOpen
// ****************************************************************************
short StrmOpen(WORD NoLog, char * sFileName, WORD wFlags)
{
MI_TRACE_DCL_TFN("StrmOpen");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN Fic=%s",sFileName));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN Flag=%04X",wFlags));

if ((NoLog>=CI_TABLE_SIZE) || (g_Table[NoLog].ObjStrm) || (g_Table[NoLog].ObjMem))
   MI_TRACE_RETURN(ERR_PARAM);

if (wFlags & CE_F_LINE)
   {
   g_Table[NoLog].ObjStrm = (CStreamLine*) new CStreamLine;
   g_Table[NoLog].IsLine  = TRUE;
   }
else
   {
   g_Table[NoLog].ObjStrm = (CStreamBin*) new CStreamBin;
   g_Table[NoLog].IsLine  = FALSE;
   }

if (!g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(ERR_MEM);

ret = ((CStreamBin*)g_Table[NoLog].ObjStrm)->Open(sFileName,wFlags);

if (ret!=NO_ERRORS)
   {
   delete ((CStreamBin*)g_Table[NoLog].ObjStrm);
   g_Table[NoLog].ObjStrm = NULL;
   g_Table[NoLog].IsLine  = 0;
   }

MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmClose
// ****************************************************************************
short StrmClose(WORD NoLog)
{
MI_TRACE_DCL_TFN("StrmClose");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(ERR_PARAM);

ret = ((CStreamBin*)g_Table[NoLog].ObjStrm)->Close();

delete ((CStreamBin*)g_Table[NoLog].ObjStrm);
g_Table[NoLog].ObjStrm = NULL;
g_Table[NoLog].IsLine  = 0;

MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmSave
// ****************************************************************************
short StrmSave(WORD NoLog)
{
MI_TRACE_DCL_TFN("StrmSave");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(ERR_PARAM);

ret = ((CStreamBin*)g_Table[NoLog].ObjStrm)->Save();

MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmWriteByte
// ****************************************************************************
short StrmWriteByte(WORD NoLog, BYTE Car)
{
MI_TRACE_DCL_TFN("StrmWriteByte");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN Car=%02X",Car));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(ERR_PARAM);

ret = ((CStreamBin*)g_Table[NoLog].ObjStrm)->Write(Car);

MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmReadByte
// ****************************************************************************
short StrmReadByte(WORD NoLog, BYTE* pCar)
{
MI_TRACE_DCL_TFN("StrmReadByte");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(ERR_PARAM);

ret = ((CStreamBin*)g_Table[NoLog].ObjStrm)->Read(pCar);

MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT Car=%02X",*pCar));
MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmWriteBuf
// ****************************************************************************
short StrmWriteBuf(WORD NoLog, const BYTE* Buf, long LgBuf, long* pLg)
{
MI_TRACE_DCL_TFN("StrmWriteBuf");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN @Buf=%08lX",(DWORD)Buf));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN LgBuf=%ld",LgBuf));
MI_TRACE((CI_TRA_F_DUMP ,CI_MODULE_ID,TFN,"IN Buf",Buf,LgBuf));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(ERR_PARAM);

ret = ((CStreamBin*)g_Table[NoLog].ObjStrm)->Write(Buf,LgBuf,pLg);

MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT Lg=%ld",*pLg));
MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmReadBuf
// ****************************************************************************
short StrmReadBuf(WORD NoLog, BYTE* Buf, long LgBuf, long* pLg)
{
MI_TRACE_DCL_TFN("StrmReadBuf");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN @Buf=%08lX",(DWORD)Buf));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN LgBuf=%ld",LgBuf));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(ERR_PARAM);

ret = ((CStreamBin*)g_Table[NoLog].ObjStrm)->Read(Buf,LgBuf,pLg);

MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT Lg=%ld",*pLg));
MI_TRACE((CI_TRA_F_DUMP ,CI_MODULE_ID,TFN,"OUT Buf",Buf,(ret==NO_ERRORS)?*pLg:0 ));
MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmFindByte
// ****************************************************************************
short StrmFindByte(WORD NoLog, BYTE Car, BOOL SeekAfter)
{
MI_TRACE_DCL_TFN("StrmFindByte");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN Car=%02X",Car));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN After=%d",SeekAfter));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(ERR_PARAM);

ret = ((CStreamBin*)g_Table[NoLog].ObjStrm)->Find(Car,SeekAfter);

MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmFindBuf
// ****************************************************************************
short StrmFindBuf(WORD NoLog, const BYTE* Buf, long LgBuf, BOOL SeekAfter)
{
MI_TRACE_DCL_TFN("StrmFindBuf");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN @Buf=%08lX",(DWORD)Buf));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN LgBuf=%ld",LgBuf));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN After=%d",SeekAfter));
MI_TRACE((CI_TRA_F_DUMP ,CI_MODULE_ID,TFN,"IN Buf",Buf,LgBuf));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(ERR_PARAM);

ret = ((CStreamBin*)g_Table[NoLog].ObjStrm)->Find(Buf,LgBuf,SeekAfter);

MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmFindByteInCollection
// ****************************************************************************
short StrmFindByteInCollection(WORD NoLog, const BYTE* Buf, long LgBuf, unsigned char* pc, BOOL SeekAfter)
{
MI_TRACE_DCL_TFN("StrmFindByteInCol");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN @Buf=%08lX",(DWORD)Buf));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN LgBuf=%ld",LgBuf));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN After=%d",SeekAfter));
MI_TRACE((CI_TRA_F_DUMP ,CI_MODULE_ID,TFN,"IN Buf",Buf,LgBuf));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(ERR_PARAM);

ret = ((CStreamBin*)g_Table[NoLog].ObjStrm)->FindInCollection(Buf,LgBuf,pc,SeekAfter);

MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmSeek
// ****************************************************************************
short StrmSeek(WORD NoLog, long Offset, WORD Origin)
{
MI_TRACE_DCL_TFN("StrmSeek");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN Offset=%ld",Offset));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN Origin=%d",Origin));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(ERR_PARAM);

ret = ((CStreamBin*)g_Table[NoLog].ObjStrm)->Seek(Offset,Origin);

MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmTell
// ****************************************************************************
short StrmTell(WORD NoLog, long* pOffset )
{
MI_TRACE_DCL_TFN("StrmTell");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(ERR_PARAM);

*pOffset = ((CStreamBin*)g_Table[NoLog].ObjStrm)->Tell();
ret = (*pOffset==-1) ? ERR_READ : NO_ERRORS;

MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT Offset=%ld",*pOffset));
MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmFileSize
// ****************************************************************************
short StrmFileSize(WORD NoLog, long* pSize)
{
MI_TRACE_DCL_TFN("StrmFileSize");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(ERR_PARAM);

*pSize = ((CStreamBin*)g_Table[NoLog].ObjStrm)->GetFileSize();
ret = (*pSize==-1) ? ERR_READ : NO_ERRORS;
   
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT Offset=%ld",*pSize));
MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmGetError
// ****************************************************************************
short StrmGetError(WORD NoLog)
{
MI_TRACE_DCL_TFN("StrmGetError");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(0);

ret = ((CStreamBin*)g_Table[NoLog].ObjStrm)->GetError();

MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmClearError
// ****************************************************************************
short StrmClearError(WORD NoLog)
{
MI_TRACE_DCL_TFN("StrmClearError");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(0);

ret = ((CStreamBin*)g_Table[NoLog].ObjStrm)->ClearError();

MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmEof
// ****************************************************************************
short StrmEof(WORD NoLog)
{
MI_TRACE_DCL_TFN("StrmEof");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(FALSE);

ret = ((CStreamBin*)g_Table[NoLog].ObjStrm)->Eof();
MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmLnAnalyse
// ****************************************************************************
short StrmLnAnalyse(WORD NoLog)
{
MI_TRACE_DCL_TFN("StrmLnAnalyse");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(ERR_PARAM);

if (!g_Table[NoLog].IsLine)
   MI_TRACE_RETURN(ERR_BAD_CALL);

ret = ((CStreamLine*)g_Table[NoLog].ObjStrm)->LnAnalyse();
MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmLnWrite
// ****************************************************************************
short StrmLnWrite(WORD NoLog, const BYTE* Buf, long LgBuf, long* pLg)
{
MI_TRACE_DCL_TFN("StrmLnWrite");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN @Buf=%08lX",(DWORD)Buf));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN LgBuf=%ld",LgBuf));
MI_TRACE((CI_TRA_F_DUMP ,CI_MODULE_ID,TFN,"IN Buf",Buf,LgBuf));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(ERR_PARAM);

if (!g_Table[NoLog].IsLine)
   MI_TRACE_RETURN(ERR_BAD_CALL);

ret = ((CStreamLine*)g_Table[NoLog].ObjStrm)->LnWrite(Buf,LgBuf,pLg);

MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT Lg=%ld",*pLg));
MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmLnRead
// ****************************************************************************
short StrmLnRead(WORD NoLog, BYTE* Buf, long LgBuf, long* pLg)
{
MI_TRACE_DCL_TFN("StrmLnRead");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN @Buf=%08lX",(DWORD)Buf));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN LgBuf=%ld",LgBuf));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(ERR_PARAM);

if (!g_Table[NoLog].IsLine)
   MI_TRACE_RETURN(ERR_BAD_CALL);

ret = ((CStreamLine*)g_Table[NoLog].ObjStrm)->LnRead(Buf,LgBuf,pLg);

MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT Lg=%ld",*pLg));
MI_TRACE((CI_TRA_F_DUMP ,CI_MODULE_ID,TFN,"OUT Buf",Buf,(ret==NO_ERRORS)?*pLg:0 ));
MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmLnReadSec
// ****************************************************************************
short StrmLnReadSec(WORD NoLog, BYTE* Buf, long LgBuf, long* pLg)
{
MI_TRACE_DCL_TFN("StrmLnReadSec");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN @Buf=%08lX",(DWORD)Buf));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN LgBuf=%ld",LgBuf));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(ERR_PARAM);

if (!g_Table[NoLog].IsLine)
   MI_TRACE_RETURN(ERR_BAD_CALL);

ret = ((CStreamLine*)g_Table[NoLog].ObjStrm)->LnReadSection(Buf,LgBuf,pLg);

MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT Lg=%ld",*pLg));
MI_TRACE((CI_TRA_F_DUMP ,CI_MODULE_ID,TFN,"OUT Buf",Buf,(ret==NO_ERRORS)?*pLg:0 ));
MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmLnFindSec
// ****************************************************************************
short StrmLnFindSec(WORD NoLog, BYTE* Buf, long LgBuf, short IsCaseSens)
{
MI_TRACE_DCL_TFN("StrmLnFindSec");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN @Buf=%08lX",(DWORD)Buf));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN LgBuf=%ld",LgBuf));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN IsCaseSens=%d",IsCaseSens));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(ERR_PARAM);

if (!g_Table[NoLog].IsLine)
   MI_TRACE_RETURN(ERR_BAD_CALL);

ret = ((CStreamLine*)g_Table[NoLog].ObjStrm)->LnFindSection(Buf,LgBuf,IsCaseSens);

MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmLnReadKey
// ****************************************************************************
short StrmLnReadKey(WORD NoLog, BYTE* Buf, long LgBuf, long* pLgBuf, BYTE* Val, long LgVal, long* pLgVal)
{
MI_TRACE_DCL_TFN("StrmLnReadKey");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN @Key=%08lX",(DWORD)Buf));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN LgKey=%ld",LgBuf));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN @Val=%08lX",(DWORD)Val));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN LgVal=%ld",LgVal));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(ERR_PARAM);

if (!g_Table[NoLog].IsLine)
   MI_TRACE_RETURN(ERR_BAD_CALL);

ret = ((CStreamLine*)g_Table[NoLog].ObjStrm)->LnReadKey(Buf,LgBuf,pLgBuf,Val,LgVal,pLgVal);

MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT LgKey=%ld",*pLgBuf));
MI_TRACE((CI_TRA_F_DUMP ,CI_MODULE_ID,TFN,"OUT Key",Buf,(ret==NO_ERRORS)?*pLgBuf:0 ));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT LgVal=%ld",*pLgVal));
MI_TRACE((CI_TRA_F_DUMP ,CI_MODULE_ID,TFN,"OUT Val",Val,(ret==NO_ERRORS)?*pLgVal:0 ));
MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmLnFindKey
// ****************************************************************************
short StrmLnFindKey(WORD NoLog, BYTE* Key, long LgKey, BYTE* Val, long LgVal, long* pLgVal, short IsCaseSens)
{
MI_TRACE_DCL_TFN("StrmLnFindSec");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN @Key=%08lX",(DWORD)Key));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN LgKey=%ld",LgKey));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN @Val=%08lX",(DWORD)Val));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN LgVal=%ld",LgVal));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN IsCaseSens=%d",IsCaseSens));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(ERR_PARAM);

if (!g_Table[NoLog].IsLine)
   MI_TRACE_RETURN(ERR_BAD_CALL);

ret = ((CStreamLine*)g_Table[NoLog].ObjStrm)->LnFindKey(Key, LgKey, Val, LgVal, pLgVal, IsCaseSens);

MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT LgVal=%ld",*pLgVal));
MI_TRACE((CI_TRA_F_DUMP ,CI_MODULE_ID,TFN,"OUT Val",Val,(ret==NO_ERRORS)?*pLgVal:0 ));
MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmLnSeek
// ****************************************************************************
short StrmLnSeek(WORD NoLog, long Offset, WORD Origin)
{
MI_TRACE_DCL_TFN("StrmLnSeek");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN Offset=%ld",Offset));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN Origin=%d",Origin));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(ERR_PARAM);

if (!g_Table[NoLog].IsLine)
   MI_TRACE_RETURN(ERR_BAD_CALL);

ret = ((CStreamLine*)g_Table[NoLog].ObjStrm)->LnSeek(Offset,Origin);
MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmLnTell
// ****************************************************************************
short StrmLnTell(WORD NoLog, long* pOffset)
{
MI_TRACE_DCL_TFN("StrmLnTell");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(ERR_PARAM);

if (!g_Table[NoLog].IsLine)
   MI_TRACE_RETURN(ERR_BAD_CALL);

*pOffset = ((CStreamLine*)g_Table[NoLog].ObjStrm)->LnTell();
ret = (*pOffset==-1) ? ERR_READ : NO_ERRORS;

MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT Offset=%ld",*pOffset));
MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmLnFileSize
// ****************************************************************************
short StrmLnFileSize(WORD NoLog, long* pLines)
{
MI_TRACE_DCL_TFN("StrmLnFileSize");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(ERR_PARAM);

if (!g_Table[NoLog].IsLine)
   MI_TRACE_RETURN(ERR_BAD_CALL);

*pLines = ((CStreamLine*)g_Table[NoLog].ObjStrm)->LnGetFileSize();
ret = (*pLines==-1) ? ERR_READ : NO_ERRORS;

MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT Offset=%ld",*pLines));
MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmLnLength
// ****************************************************************************
short StrmLnLength(WORD NoLog, long* pSizeLines)
{
MI_TRACE_DCL_TFN("StrmLnLength");
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(ERR_PARAM);

if (!g_Table[NoLog].IsLine)
   MI_TRACE_RETURN(ERR_BAD_CALL);

*pSizeLines = ((CStreamLine*)g_Table[NoLog].ObjStrm)->LnGetLength();

MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT Offset=%ld",*pSizeLines));
MI_TRACE_RETURN(NO_ERRORS);
}

// ****************************************************************************
// * StrmLnMaxLength
// ****************************************************************************
short StrmLnMaxLength(WORD NoLog, long* pSize)
{
MI_TRACE_DCL_TFN("StrmLnMaxLength");
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(ERR_PARAM);

if (!g_Table[NoLog].IsLine)
   MI_TRACE_RETURN(ERR_BAD_CALL);

*pSize = ((CStreamLine*)g_Table[NoLog].ObjStrm)->LnGetMaxLengthLine();

MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT Offset=%ld",*pSize));
MI_TRACE_RETURN(NO_ERRORS);
}

// ****************************************************************************
// * StrmLnEof
// ****************************************************************************
short StrmLnEof(WORD NoLog)
{
MI_TRACE_DCL_TFN("StrmLnEof");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(FALSE);

if (!g_Table[NoLog].IsLine)
   MI_TRACE_RETURN(FALSE);

ret = ((CStreamLine*)g_Table[NoLog].ObjStrm)->LnEof();
MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmLnSetExpandTab
// ****************************************************************************
short StrmLnSetExpandTab(WORD NoLog, WORD LgTab)
{
MI_TRACE_DCL_TFN("StrmLnSetExpandTab");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN LgTab=%d",LgTab));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(ERR_PARAM);

if (!g_Table[NoLog].IsLine)
   MI_TRACE_RETURN(ERR_BAD_CALL);

ret = ((CStreamLine*)g_Table[NoLog].ObjStrm)->LnSetExpandTab(LgTab);
ret = (ret==-1) ? ERR_BAD_CALL : NO_ERRORS;

MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmLnGetExpandTab
// ****************************************************************************
short StrmLnGetExpandTab(WORD NoLog, WORD* pLgTab)
{
MI_TRACE_DCL_TFN("StrmLnGetExpandTab");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(ERR_PARAM);

if (!g_Table[NoLog].IsLine)
   MI_TRACE_RETURN(ERR_BAD_CALL);

*pLgTab = ((CStreamLine*)g_Table[NoLog].ObjStrm)->LnGetExpandTab();
ret = (*pLgTab==(WORD)-1) ? ERR_READ : NO_ERRORS;

MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT Tab=%ld",*pLgTab));
MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmLnSetPad
// ****************************************************************************
short StrmLnSetPad(WORD NoLog, WORD IsPad)
{
MI_TRACE_DCL_TFN("StrmLnSetPad");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN Pad=%d",IsPad));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(ERR_PARAM);

if (!g_Table[NoLog].IsLine)
   MI_TRACE_RETURN(ERR_BAD_CALL);

ret = ((CStreamLine*)g_Table[NoLog].ObjStrm)->LnSetPad(IsPad);
ret = (ret==-1) ? ERR_BAD_CALL : NO_ERRORS;

MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmLnGetPad
// ****************************************************************************
short StrmLnGetPad(WORD NoLog, WORD* pIsPad)
{
MI_TRACE_DCL_TFN("StrmLnGetPad");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(ERR_PARAM);

if (!g_Table[NoLog].IsLine)
   MI_TRACE_RETURN(ERR_BAD_CALL);

*pIsPad = ((CStreamLine*)g_Table[NoLog].ObjStrm)->LnGetPad();
ret = (*pIsPad==(WORD)-1) ? ERR_READ : NO_ERRORS;

MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT Pad=%ld",*pIsPad));
MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmLnSetFormFeed
// ****************************************************************************
short StrmLnSetFormFeed(WORD NoLog, WORD IsFormFeed)
{
MI_TRACE_DCL_TFN("StrmLnSetFormFeed");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN FormFeed=%d",IsFormFeed));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(ERR_PARAM);

if (!g_Table[NoLog].IsLine)
   MI_TRACE_RETURN(ERR_BAD_CALL);

ret = ((CStreamLine*)g_Table[NoLog].ObjStrm)->LnSetFormFeed(IsFormFeed);
ret = (ret==-1) ? ERR_BAD_CALL : NO_ERRORS;

MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmLnGetFormFeed
// ****************************************************************************
short StrmLnGetFormFeed(WORD NoLog, WORD* pIsFormFeed)
{
MI_TRACE_DCL_TFN("StrmLnGetFormFeed");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(ERR_PARAM);

if (!g_Table[NoLog].IsLine)
   MI_TRACE_RETURN(ERR_BAD_CALL);

*pIsFormFeed = ((CStreamLine*)g_Table[NoLog].ObjStrm)->LnGetFormFeed();
ret = (*pIsFormFeed==(WORD)-1) ? ERR_READ : NO_ERRORS;

MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT FormFeed=%ld",*pIsFormFeed));
MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmLnFileFormat
// ****************************************************************************
short StrmLnFileFormat(WORD NoLog, WORD* pIsCr, WORD* pIsCtrlz )
{
MI_TRACE_DCL_TFN("StrmLnFileFormat");
short ret = NO_ERRORS;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(ERR_PARAM);

if (!g_Table[NoLog].IsLine)
   MI_TRACE_RETURN(ERR_BAD_CALL);

ret = ((CStreamLine*)g_Table[NoLog].ObjStrm)->LnGetFileFormat(pIsCr,pIsCtrlz);

MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT Cr=%d",*pIsCr));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT Ctrlz=%d",*pIsCtrlz));
MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmLnIsLast
// ****************************************************************************
short StrmLnIsLast(WORD NoLog)
{
MI_TRACE_DCL_TFN("StrmLnIsLast");
short ret = NO_ERRORS;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(FALSE);

if (!g_Table[NoLog].IsLine)
   MI_TRACE_RETURN(FALSE);

ret = ((CStreamLine*)g_Table[NoLog].ObjStrm)->LnIsLastLine();

MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * StrmLnInfoLine
// ****************************************************************************
short StrmLnInfoLine(WORD NoLog, long* pOffset, long* pSize)
{
MI_TRACE_DCL_TFN("StrmLnInfoLine");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",NoLog));

if ((NoLog>=CI_TABLE_SIZE) || !g_Table[NoLog].ObjStrm)
   MI_TRACE_RETURN(ERR_PARAM);

if (!g_Table[NoLog].IsLine)
   MI_TRACE_RETURN(ERR_BAD_CALL);

*pOffset = ((CStreamLine*)g_Table[NoLog].ObjStrm)->LnTell();
*pSize   = ((CStreamLine*)g_Table[NoLog].ObjStrm)->LnGetLengthLine();

ret = ((*pOffset==-1) || (*pSize==-1)) ? ERR_READ : NO_ERRORS;

MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT Cr=%d",*pOffset));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT Ctrlz=%d",*pSize));
MI_TRACE_RETURN(ret);
}

