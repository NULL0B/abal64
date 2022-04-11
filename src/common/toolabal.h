// ***********************************************************************************************
// * ToolAbal.h
// ***********************************************************************************************

#ifndef TOOLABAL_H
#define TOOLABAL_H

#ifdef __cplusplus
  extern "C" {
#endif

char * ToolAbal_CreateStrC(unsigned int iRtArg);
void ToolAbal_DeleteStrC(char * sCstr);
WORD ToolAbal_SwapBytes(WORD * pwNumb);
unsigned long ToolAbal_GetLongFromRtArg(WORD iRtArg, unsigned long DefaultValue, BOOL IsSigned);
BOOL ToolAbal_SetLongToRtArg(WORD iRtArg, unsigned long dwValue);
WORD ToolAbal_ConvertAbalWord( BYTE* wptr);

#ifdef __cplusplus
  }
#endif

#if defined(BDA_WIN32)
#define ToolAbal_WORD(w)  (*(WORD*)(w))
#else
#define ToolAbal_WORD(w)  (ToolAbal_ConvertAbalWord((BYTE*)(w))) 
#endif

#endif
