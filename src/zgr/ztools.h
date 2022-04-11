// ****************************************************************************
// * zTools.h toolbox
// * Tools module
// ****************************************************************************
#ifndef _ZTOOLS_H
#define _ZTOOLS_H


#ifdef __cplusplus
  extern "C" {
#endif
// ----------------------------------------------------------------------------
// - Internal functions
// ----------------------------------------------------------------------------

// zTools
VOID FAR PTR allocate( int nb );
VOID FAR PTR callocate( int nb, int size );
VOID FAR PTR liberate(VOID FAR PTR vptr );

VOID ToolsAbalPutWord( WORD FAR PTR Out, WORD In );
WORD ToolsExtractInt( BYTE FAR PTR bptr );

VOID ToolsNormalizeRectangle(PTI_RECTANGLE rect);
VOID ToolsMakeRectangle(PTI_RECTANGLE rect, const PTI_POINT topleft,const PTI_SIZE size);
VOID ToolsVoidRectangle(PTI_RECTANGLE rect);
VOID ToolsIncreaseRectangle(PTI_RECTANGLE Dest, const PTI_RECTANGLE New);
WORD ToolsGetHeight(const PTI_RECTANGLE rect);
WORD ToolsGetWidth(const PTI_RECTANGLE rect);

VOID ToolsMoveRectangle(PTI_POINT a,PTI_RECTANGLE rect);
VOID ToolsInitMemory( PTI_MEMORY pStorage );
VOID ToolsReinitMemory( PTI_MEMORY pStorage );
WORD ToolsAllocMemory( PTI_MEMORY pStorage, WORD Size );

char FAR * ToolsGetZiniKey(char FAR * Value, char FAR * Key, WORD LgMax, WORD IsPathName);
WORD ToolsFindFile( char * AbsoluteFilename, const char * Filename, const char * EnvPathname);

#ifdef __cplusplus
  }
#endif

#endif
