#ifndef	_singname_h
#define	_singname_h

#define	NUL_EXTENSION		"\0"

#define	CLASS_EXTENSION		".cls"
#define	MODEL_EXTENSION		".sng"
#define	DATABASE_EXTENSION	".sgf"
#define	PROJECT_EXTENSION	".3d"

#define	BMP_EXTENSION		".bmp"
#define	GIF_EXTENSION		".gif"
#define	JPG_EXTENSION		".jpg"
#define	PNG_EXTENSION		".png"
#define	WAV_EXTENSION		".wav"

#define	XML_EXTENSION		".xml"
#define	C_EXTENSION		".c"
#define	H_EXTENSION		".h"
#define	CPP_EXTENSION		".cpp"
#ifdef	UNIX
#define	OBJ_EXTENSION		".o"
#else
#define	OBJ_EXTENSION		".obj"
#endif

#ifdef	UNIX
#define	EXE_EXTENSION		".out"
#define	ERR_EXTENSION		".err"
#else
#ifdef	PROLOGUE
#define	EXE_EXTENSION		".xp"
#define	ERR_EXTENSION		".e"
#else
#define	EXE_EXTENSION		".exe"
#define	ERR_EXTENSION		".err"
#endif
#endif

#define	AS_EXTENSION		".as"
#define	S_EXTENSION		".s"
#define	AT_EXTENSION		".at"
#define	O_EXTENSION		".o"
#define	APL_EXTENSION		".apl"
#define	DBG_EXTENSION		".dbg"
#define	DBO_EXTENSION		".dbo"
#define	EXT_EXTENSION		".ext"

#define	JAV_EXTENSION		".java"
#define	CLA_EXTENSION		".class"

#define	HTM_EXTENSION		".htm"
#define	CSS_EXTENSION		".css"
#define	JS_EXTENSION		".js"

#define	COB_EXTENSION		".cob"

#define	MF_EXTENSION		".mf"
#define	LF_EXTENSION		".lf"

#ifndef	public
#define	public
#endif

#ifdef __cplusplus	/* GWB le 11/12/2007 */
extern "C" {
#endif

public	int	detect_extension( char * , char * );
public	char * 	verify_extension( char *, char * );
public	char * 	enforce_extension( char *, char * );
public	char *	relative_filename( char *, char * );
public	char *	path_prefix( char *, char * );

#ifdef __cplusplus	/* GWB le 11/12/2007 */
}
#endif
#endif	/* _singname_h */

