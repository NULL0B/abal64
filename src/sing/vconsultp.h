#ifdef __cplusplus
extern "C" {
#endif
#if defined(_vconsultpp_h) || defined(_vconsult_c)
	char *FileNameConsult="Fichier inconnu";
	int LMaxConsult=77,HMaxConsult=1;
#else
	extern char *FileNameConsult;
	extern LMaxConsult,HMaxConsult;
#endif
#ifdef __cplusplus
	}
#endif

#if defined(_vconsultpp_h) || defined(_vconsult_c)
#include <stdio.h>
FILE *fConsult=NULL;
#endif

