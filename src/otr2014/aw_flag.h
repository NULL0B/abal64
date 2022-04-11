//---------------------------------------------------------------------------
// Project      : BSA-PROTECTION
// Version      : 1.0
// Author       : I.Nichiporovich (IN) (Minsk)
// Creation     : 07.96
// Module       : Header flag file
//---------------------------------------------------------------------------

#ifndef  __AW_FLAG_H
#define  __AW_FLAG_H

#ifdef __cplusplus
extern "C" {
#endif

extern char * CopyRight;
extern char * ProjectName;

#define ProtSignLength    16  // Max length of signature
#define ProtNmbrLength    20  // Max length of serial number
#define ProtRsrvLength     8  // Reserved number of bytes
#define ProtNameLength    48  // Max length of user name
#define ProtBsnmLength    64  // Length of the BIOS name
#define ProtBsdtLength     8  // Length of the BIOS data

#define ProtCodeNumber    10  // Number of legal product codes

#ifdef __cplusplus
}
#endif

#endif

// END OF FILE ==============================================================
