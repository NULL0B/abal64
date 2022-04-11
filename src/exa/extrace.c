// ****************************************************************************
// * extrace.c
// * Trace functionnality
// ****************************************************************************
#define CE_TRA_MASTERKEY    "[exa]"
#define CI_PRG_ID           "exa"
#define CI_TRA_ID_MASK_1    0x0000
#define CI_TRA_ID_MASK_2    0x0000

// La trace ABAL est autorisée, mais pas la trace interne
// on force l'activation du code
#if defined(TRACEABAL) && !defined(TRACEON)
#define TRACEON
#define TRACEON_PROVISOIRE
#endif

#include "trace.c"

// Remise en état en cas de suite éventuelle
#if defined(TRACEON_PROVISOIRE)
#undef TRACEON
#undef TRACEON_PROVISOIRE
#endif
