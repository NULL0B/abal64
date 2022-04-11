//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_nvid_h
#define _html_nvid_h

#define _VERNAME "NV"
#ifdef	_NV11G
#define _VERDATE "30/09/2002"
#else
#ifdef	_NV11F
#define _VERDATE "11/01/2002"
#else
#ifdef	_NV11E
#define _VERDATE "21/08/2001"
#else
#ifdef	_NV11D
#define _VERDATE "14/02/2001"
#else
#ifdef	_NV11C
#define _VERDATE "07/12/2000"
#else
#ifdef	_NV11BX
#define _VERDATE "20/06/2000"
#else
#ifdef	_NV11B
#define _VERDATE "10/08/2000"
/* #define _VERDATE "20/06/2000" */
#else
#define _VERDATE "15/03/2000"
#endif
#endif
#endif
#endif
#endif
#endif
#endif

extern	"C"	{
	char *	getpatternversion();
	void	nv_nvid();
	void	nv_usage();
	}

#endif	// _html_nvid_h



