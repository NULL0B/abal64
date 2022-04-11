#ifdef __cplusplus
extern "C" {
#endif

#ifdef _STDTYPES_H

#ifndef __CHAR_DEFINED__
typedef char                            CHAR;
#endif

#ifndef VOID
typedef void							VOID;
#endif

#ifndef FAR
#define FAR
#endif

typedef CHAR FAR *                      LPSTR;

#if !defined(WINAPI)
    #if defined(_WIN32) && (_MSC_VER >= 800)
        #define WINAPI              __stdcall
    #elif defined(WIN16)
        #define WINAPI              _far _pascal
    #else
        #define WINAPI              _far _pascal
    #endif
#endif

#endif /* _STDTYPES_H */

#ifdef WIN32
	__declspec(dllimport) VOID WINAPI Traduction(LPSTR);
#else
	VOID WINAPI Traduction(LPSTR);
#endif

#ifdef __cplusplus
}
#endif

