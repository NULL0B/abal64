#include "trace.h"

// =============================================================================
// = CONSTANTES pour TRACE
// =============================================================================
// On détourne l'utilisation de CI_MODULE_ID pour tracer le type d'API
// Ceci permet de mettre des filtres dans la trace:
// 0x01FF toutes fonctions générales
// 0x8000 est toujours réservé pour la trace applicative (ABAL)
// =============================================================================

#define ID_OS		0	// 0x0001	1 << 0
#define ID_KERNEL	1	// 0x0002	1 << 1

#ifdef TRACEON
#define MI_TRACE_DCL_MODULE_ID(a)    static const unsigned short CI_MODULE_ID = (1<<(a))
#define MI_TRACE_DCL_MODULE_ID_ALL() static const unsigned short CI_MODULE_ID = 0x01FF
#else
#define MI_TRACE_DCL_MODULE_ID(a)    static const unsigned short CI_MODULE_ID = 0
#define MI_TRACE_DCL_MODULE_ID_ALL() static const unsigned short CI_MODULE_ID = 0
#endif

// Personalisation...
#define MSG_BEGIN			"-- Begin"
#define MSG_END			"-- End %d (%04Xh)"
