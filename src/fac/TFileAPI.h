// ***********************************************************************************************
// * TFileAPI.cpp
// ***********************************************************************************************

#ifndef TEXTFILEAPI_H
#define TEXTFILEAPI_H

// --- Constantes pour deplacement dans les fichiers texte
//     (ChangeLine et ChangeAndReadLine)
#define  F_SCROLL_NO    0
#define  F_SCROLL_NEXT  1
#define  F_SCROLL_PREV  2
#define  F_SCROLL_FIRST 3
#define  F_SCROLL_LAST  4

#ifdef __cplusplus
struct STextFile {
  TTextFile * pDescriptor;
};
#else
#define STextFile void 
#endif


#ifdef __cplusplus
  extern "C" {
#endif

short int CreateTextFile(char * sFileName,WORD wFlags,STextFile * pDescriptor);
short int OpenTextFile(char * sFileName,WORD wFlags,STextFile * pDescriptor);
short int SaveTextFile(STextFile * pDescriptor);
short int CloseTextFile(STextFile * pDescriptor);
short int FileCopy(char * sSrcFileName,char * sDstFileName);
short int FileMove(char * sOldFileName,char * sNewFileName);
short int FileDelete(char * sFileName);
BOOL DoesFileExist(char * sFileName);
short int ReadLn(STextFile * pDescriptor,WORD* pwBufLen,char * sBuffer);
short int WriteLn(STextFile * pDescriptor,WORD wBufLen,char * sBuffer);
short int GetLineLen(STextFile * pTextFile,WORD * pLength);

short int ReadNChars(STextFile * pDescriptor,WORD wQuant,char * sTxt);
short int WriteNChars(STextFile * pDescriptor,WORD wQuant,char * sTxt);
short int DeleteNChars(STextFile * pDescriptor,WORD wQuant,char * sTxt);

short int AddLine(STextFile * pDescriptor,WORD wLen,char * sBuffer);
short int InsertLine(STextFile * pDescriptor,WORD wLen,char * sBuffer);
short int DeleteLine(STextFile * pDescriptor);

short int Seek(STextFile * pTextFile,DWORD dwRow,DWORD dwCol);

short int GetRow(STextFile * pTextFile,DWORD * pRow);
short int GetCol(STextFile * pTextFile,DWORD * pCol);
short int GetLinesQuant(STextFile * pTextFile,DWORD * pQuant);
short int GetFilePos(STextFile * pTextFile,BYTE * pbPosRow,BYTE * pbPosCol,BYTE * pbPosFile);
short int WasFileModified(STextFile * pDescriptor,WORD * pwWasModified);
short int ToggleInsState(STextFile * pDescriptor);
short int GetInsState(STextFile * pDescriptor,WORD * pwIsInsertMode);
short int GetAttributes(STextFile * pTextFile,BYTE * pbFileAttributes);
short int SetAttributes(STextFile * pTextFile,BYTE bFileAttributes);
short int GetLibVersion();
short int GetErrMsg(WORD wErrNumb,WORD wBufLen,char * sBuffer);
short int GetSizeFile(STextFile * pTextFile,DWORD * pValue);
short int FileGetAttribute(char * sFileName,BYTE * pbFileAttributes);
short int FileSetAttribute(char * sFileName,BYTE bFileAttributes);
short int GetBinFileSize(char * sFileName,DWORD * pValue);

short int ChangeLine(STextFile * pTextFile, WORD Mode);
short int ChangeThenReadLineExpand(STextFile * pTextFile,WORD LgTab, WORD LgBuf, char * sBuffer, WORD* pLgFin, int Mode);

#ifdef __cplusplus
  }
#endif

#endif
