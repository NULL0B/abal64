/**********************************/
/*          TFile.h               */
/* Support of text files handling */
/*            v.1.00              */
/**********************************/

#ifndef TEXTFILE_H
#define TEXTFILE_H

enum linerdr_state {lnrdr_unknown_err, lnrdr_eol_err, lnrdr_str_toolong_err, lnrdr_eof, lnrdr_OK};

///////////////////
class TLineReader {
///////////////////
private:
  linerdr_state lnrdrState;

  BOOL   IsAccumUse;   /* Accumulator was used                                               */
  char * sFbuffer;     /* A work buffer                                                      */
  DWORD  dwFbuf_len;   /* Length of the sFbuffer                                             */
  char * sFcurr;       /* A current point in the sFbuffer                                    */
  char * sFend;        /* An end of the sFbuffer                                             */
  char * sFstr_beg;    /* Begin of the current string in the sFbuffer                        */
  char * sFaccum;      /* An accumulator for save of the first part of the curr str          */
  DWORD  dwFaccum_len; /* The accumulator's current length                                   */
  int iFFileHandle;    /* A handle of the entry file                                         */

  BOOL FSaveAccum();
  char * FSetCurrStr(DWORD & dwLen);
  BOOL FLoadBuf();

public:
  TLineReader(DWORD dwMaxBufLen);
  ~TLineReader();
  char * GetNextStr(DWORD & dwLen);
  void SetFileHandle(int iFileHnd);
  linerdr_state GetState();
}; // class TLineReader


////////////////
struct SString {
////////////////
  char sSign[2]; // "ST"

  BOOL IsModified; // String was modified
  BOOL IsMemAlloc; // Memory was allocated (it wasn't used Memory Mapped Files)
  BOOL IsClearNew; // Clear new allocated bytes

  DWORD dwLen;   // Current used space
  DWORD dwAlloc; // Allocated space
  DWORD dwStep;  // Step of dwAlloc increment
  char * sTxt;

  SString();
//  SString(char * sStrTxt);
  SString(DWORD dwLength,char * sStrTxt,BOOL withMemAlloc=TRUE);
  ~SString();
  void ZeroingItem();
  void DeleteTxt();
  void AllocTxt();
  void ClearTxtPart();
  void ExtendAlloc(DWORD dwLimit=0);
  void SetStrAlloc(WORD wLength,char * sStrTxt);
  void SetString(char * sStrTxt);
  void SetString(DWORD dwLength,char * sStrTxt);
//  char & operator[](DWORD dwOffset);
  char ReadChr(DWORD dwOfs);
  void WriteChr(DWORD dwOfs,char chrNew);
  void InsertChr(DWORD dwOfs,char chrNew);
  char DeleteChr(DWORD dwOfs);
};

/*
bit  description
 0    1 = BEGIN
 1    1 = END
 2    1 = OUTSIDE

 all bits = 0: [not BEGIN + not END + not OUTSIDE] => INTERMEDIATE
*/
enum posflag_type {pf_INTERMEDIATE=0, pf_BEGIN, pf_END, pf_BEGIN_END, pf_OUTSIDE};

/////////////////
class TTextFile {
/////////////////
private:
  char sFsign[2];     // "TF" signature

  BOOL IsModified;         // Text has been modified
//      BOOL IsFileBeg;    // TRUE, if it was reached the begin of the file
//      BOOL IsFileEnd;    // TRUE, if it was reached the end of the file
//      BOOL IsEndOfLine;  // TRUE, if it was reached the end of the line
  BOOL IsInsertMode;       // TRUE, if insert mode is switched on
  BOOL IsReadPermiss;      // Permissions for Read
  BOOL IsWritePermiss;     // Permissions for Write
  BOOL IsBinFile;          // Either Bin or Text file
  WORD ModeOpen;           // Open/Create Mode 

  char * sFFileName;
  int iFFileHnd;
  TList * pFTxtLst;   // All text or current text buffer (SString *)
  
  DWORD dwFrow;
  DWORD dwFcol;
  TLineReader * pFLineReader;
//  TMMFile * pFMMFile;
  posflag_type posRow;
  posflag_type posCol;
  posflag_type posFile;

// For BinFile only:
  char * sFbin_contents; // With 0-terminator
  DWORD  dwFbin_size;    // Without 0-terminator

  void FZeroingItem();
  short int FSetFileName(char * sFileName);
  short int FLoadBinFile();
  short int FLoadText(WORD wFlags);
  short int FSaveBinFile();
  short int FSaveTextFile();
  short int FCloseFile();
  short int FNextLine();
  short int FPrevLine();
  short int FFirstLine();
  short int FLastLine();
  short int FNextChar(DWORD dwStrLen);
  short int FCheckRow(WORD wLen,char * sBuffer);
//  void FCheckPlaceBits();

  void FTreatPermissFlags(WORD * wFlags);
  void FTreatBinFlags(WORD * pwFlags);
  void FTreatModeFlags(WORD * pwFlags);
  WORD FGetPortableOpenMode();
  BOOL FSetPortableOpenFlag(WORD* pFlag);

  BOOL FDoCont(short int * shiResult);
  DWORD FGetCurrLen();
  void FInitPosFlags();
  posflag_type FSetRCPos(DWORD dwItem,DWORD dwLimit);
//  BOOL FIsColStateBeg();
//  BOOL FIsColStateEnd(SString * pTxtStr);
//  BOOL FIsColStateOut(SString * pTxtStr);
  posflag_type FSetFilePos();
  void FSetPosFlags();
  BOOL FIsValidPtr(void * pPtr);

public:
  TTextFile();
//  TTextFile(char * sTxtFileName,DWORD dwBeginOfs,DWORD dwBufLen);
  ~TTextFile();
  short int CreateTextFile(char * sFileName,WORD wFlags);
  short int OpenTextFile(char * sFileName,WORD wFlags);
  short int SaveTextFile();
  short int ReadLn(WORD wLen,char * sBuffer, WORD* pwLineLen );
  short int WriteLn(WORD wLen,char * sBuffer);
  short int ReadChar(char * pchrTxt);
  short int ReadNChars(char * sTxt,WORD wQuant);
  short int GetLineLen(DWORD * pdwLength);
  short int WriteChar(char chrTxt);
  short int WriteNChars(char * sTxt,WORD wQuant);
  short int DeleteChar(char * pchrTxt);
  short int DeleteNChars(char * sTxt,WORD wQuant);
  short int AddLine(WORD wLen,char * sBuffer);
  short int InsertLine(WORD wLen,char * sBuffer);
  short int DeleteLine();
  short int Seek(DWORD dwRow,DWORD dwCol);
  DWORD GetRow();
  DWORD GetCol();
  DWORD GetLinesQuant();
  BOOL WasFileModified();
  short int ToggleInsState();
  BOOL GetInsState();
  short int GetFilePos(BYTE * pbPosRow,BYTE * pbPosCol,BYTE * pbPosFile);
  short int GetAttributes(BYTE * pbFileAttributes);
  short int SetAttributes(BYTE bFileAttributes);
  short int GetFileSize(DWORD * pdwFileSize);

  short int NextLine();
  short int PrevLine();
  short int FirstLine();
  short int LastLine();


}; // class TTextFile

#endif // TEXTFILE_H

