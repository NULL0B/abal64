#ifndef __LKFILE_H__
#define __LKFILE_H__

#ifdef _LKFILE
#undef PRIMITIVE
#define PRIMITIVE
#endif /* _LKFILE */

#include "lkstruct.h"


#ifdef __WALD__
void AttemptToForceReadWrite(ctConstStr FilePath, int typ, int mod);
#else
#define AttemptToForceReadWrite(FilePath, typ, mod)	/* empty */
#endif


#ifdef LINT_ARGS
	PRIMITIVE VOID FileInit( Tabfic XPTR * fic, BYTE XPTR * nom, BYTE typ, Entete XPTR * ent );
	PRIMITIVE VOID FileOpen( Tabfic XPTR * fic ); 
	PRIMITIVE VOID FileResultOpen( Tabfic XPTR * source_fic, Tabfic XPTR * target_fic );
	PRIMITIVE VOID FileClose( Tabfic XPTR * fic );
	PRIMITIVE VOID FileDestroy( Tabfic XPTR * fic );
	PRIMITIVE BOOL FileIsEmpty( Tabfic XPTR * fic );
	PRIMITIVE WORD FileGetReloc( Tabfic XPTR * fic );
	PRIMITIVE WORD FileGetNumBloc( Tabfic XPTR * fic );
	PRIMITIVE WORD FileGetOffset( Tabfic XPTR * fic );
	PRIMITIVE VOID FilePutBlocOfst( Tabfic XPTR * pt , WORD bloc, WORD ofst);
	PRIMITIVE VOID FileWriteBlocForce( Tabfic XPTR * fic );
	PRIMITIVE VOID FileCopyBloc( Tabfic XPTR * source_fic, Tabfic XPTR * target_fic, WORD lg);
	PRIMITIVE VOID FileCopyBuf( Tabfic XPTR * source_fic, Tabfic XPTR * target_fic, WORD bloc, WORD lg);
	PRIMITIVE VOID FilePositBloc( Tabfic XPTR * fic, WORD num_bloc );
	PRIMITIVE VOID FileSeekBloc( Tabfic XPTR * fic, WORD off );
	PRIMITIVE VOID FileReadBloc( Tabfic XPTR * fic, Tabfic XPTR * des, WORD bloc);
	PRIMITIVE VOID FileWriteBloc( Tabfic XPTR * fic );
	PRIMITIVE VOID FilePurge( Tabfic XPTR * fic );
	PRIMITIVE VOID FileEndBloc(Tabfic XPTR * fic );
	PRIMITIVE VOID FileGetString( Tabfic XPTR * fic, BYTE XPTR * nom);
	PRIMITIVE VOID FileGetStringLg( Tabfic XPTR * fic, BYTE XPTR * nom, WORD lg);
	PRIMITIVE VOID FileGetBloc( Tabfic XPTR * source_fic, Tabfic XPTR * target_fic, WORD nb);
	PRIMITIVE BYTE FileGetByte( Tabfic XPTR * fic );
	PRIMITIVE WORD FileGetBin( Tabfic XPTR * fic );
	PRIMITIVE VOID FilePutByte( Tabfic XPTR * fic, BYTE val );
	PRIMITIVE VOID FilePutBin( Tabfic XPTR * fic, WORD val );
	PRIMITIVE VOID FilePutStringLg( Tabfic XPTR * fic, BYTE XPTR * nom, WORD lg);
	PRIMITIVE VOID FilePutString( Tabfic XPTR * fic, BYTE XPTR * nom );
	PRIMITIVE FILE XPTR * FileXfopen( BYTE XPTR * nom );
	PRIMITIVE SWORD FileXopen( BYTE XPTR * nom, WORD typ, WORD mod );
	PRIMITIVE VOID  FileSeek( Tabfic XPTR *, WORD );
	PRIMITIVE VOID  FileRead( Tabfic XPTR *, BYTE XPTR *, WORD );
	PRIMITIVE VOID  FileWrite( Tabfic XPTR *, BYTE XPTR *, WORD );
	PRIMITIVE VOID  FileInvalidateTmp( Tabfic XPTR * );
	PRIMITIVE VOID  FilePadding( Tabfic XPTR * );
	PRIMITIVE char XPTR * TranslateLongPathName(char XPTR * LongPathName);
#else 	/* LINT_ARGS */

	PRIMITIVE VOID FileInit();
	PRIMITIVE VOID FileOpen();
	PRIMITIVE VOID FileResultOpen();
	PRIMITIVE VOID FileClose();
	PRIMITIVE VOID FileDestroy();
	PRIMITIVE BOOL FileIsEmpty();
	PRIMITIVE WORD FileGetReloc();
	PRIMITIVE WORD FileGetNumBloc();
	PRIMITIVE WORD FileGetOffset();
	PRIMITIVE VOID FilePutBlocOfst();
	PRIMITIVE VOID FileWriteBlocForce();
	PRIMITIVE VOID FileCopyBloc();
	PRIMITIVE VOID FileCopyBuf();
	PRIMITIVE VOID FilePositBloc();
	PRIMITIVE VOID FileSeekBloc();
	PRIMITIVE VOID FileReadBloc();
	PRIMITIVE VOID FileWriteBloc();
	PRIMITIVE VOID FilePurge();
	PRIMITIVE VOID FileEndBloc();
	PRIMITIVE VOID FileGetString();
	PRIMITIVE VOID FileGetStringLg();
	PRIMITIVE VOID FileGetBloc();
	PRIMITIVE BYTE FileGetByte();
	PRIMITIVE WORD FileGetBin();
	PRIMITIVE VOID FilePutByte();
	PRIMITIVE VOID FilePutBin();
	PRIMITIVE VOID FilePutStringLg();
	PRIMITIVE VOID FilePutString();

	PRIMITIVE FILE XPTR * FileXfopen();
	PRIMITIVE SWORD FileXopen();
	PRIMITIVE VOID  FileSeek();
	PRIMITIVE VOID  FileRead();
	PRIMITIVE VOID  FileWrite();
	PRIMITIVE VOID  FileInvalidateTmp();
	PRIMITIVE VOID  FilePadding();
	char XPTR * TranslateLongPathName();
#endif	/* LINT_ARGS */

#endif /* _LKFILE_HE */
