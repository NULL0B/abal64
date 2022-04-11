#ifndef	_SINGABAL_H
#define	_SINGABAL_H

#include "abaltype.h"

#define	_OVL_PRECONST		1
#define	_OVL_POSTDEST		2
#define	_OVL_ONCREATE		3
#define	_OVL_ONREMOVE		4
#define	_OVL_ONHIDE		5
#define	_OVL_ONSHOW		6
#define	_OVL_ONEVENT		7
#define	_OVL_ONFOCUS		8
#define	_OVL_ONEXEC		9
#define	_OVL_ONATTACH		10
#define	_OVL_ONDETACH		11
#define	_OVL_ONLOSE		12
#define	_OVL_POSITIONAT		13

#define	_OVL_METHODS		12

#include "soapform.h"

#define	_PRINTER_PRECONST	1
#define	_PRINTER_POSTDEST	2
#define	_PRINTER_CREATE		3
#define	_PRINTER_OPEN		4
#define	_PRINTER_ROW   		5
#define	_PRINTER_PAGE  		6
#define	_PRINTER_FLUSH 		7
#define	_PRINTER_REMOVE		8
#define	_PRINTER_STATUS		9
#define	_PRINTER_MARGINS	10
#define	_PRINTER_CONTROL	11

#define	_PRINTER_METHODS	11

#define	_OVL_PREFIX		"o_"
#define	_IMT_PREFIX		"m_"
#define	_BUF_PREFIX		"b_"


struct	abal_configuration	{
	int	generate_program;
	int	generate_overlay;
	int	page_control;
	int	actions;
	int	action;
	int	members;
	char *	cname;
	char *	input_method;
	char *	error_method;
	int	newstdin;
	int	newstderr;
	int	newstdout;
	char	Special[256];	/* Used to Build a Module Prefix for Methods */
	};
#ifdef	_SINGABAL_C
struct	 abal_configuration Abal_Config = { 
	1, 0, 0, 6,0, 0, (char *) 0 ,(char *) 0, (char *) 0, 0 , 0, 0
	};
#else
extern	struct	 abal_configuration Abal_Config;
#endif

struct	translator_configuration	{
	int		verbose;
	int		debug;
	int		liste;
	int		trace;
	int		optimise;
	int		compact;
	};

#ifdef	UNIX
#define	_STANDARD_ATR "/opt/prologue/bin/atr"
#define	_STANDARD_OTR "/opt/prologue/bin/otr"
#define	_STANDARD_AED "/opt/prologue/bin/aed"
#define	_STANDARD_ALD "/opt/prologue/bin/ald"
#else
#define	_STANDARD_ATR "is.atr.xp"
#define	_STANDARD_OTR "is.otr.xp"
#define	_STANDARD_AED "is.aed.xp"
#define	_STANDARD_ALD "is.ald.xp"
#endif

#ifdef __cplusplus	/* GWB le 03/09/2007 */
extern "C" {
#endif

extern	char * keyword_include;
extern	char * keyword_user;
extern	char * keyword_use;
extern	char * keyword_this;
extern	char * keyword_exit;
extern	char * system_printer;
extern	char * keyword_onshow;
extern	char * keyword_onhide;
extern	char * keyword_onevent;
extern	char * keyword_oncreate;
extern	char * keyword_onremove;
extern	char * keyword_onfocus;
extern	char * keyword_FormResize;
extern	char *	keyword_w_BaseResize;
extern	char *	keyword_h_BaseResize;
extern	char	namebuffer[];
extern	char	workbuffer[];
extern	struct	screen_control	Context;
extern	char *	font_name[];
extern	int	TargetBiosMode;
extern	int	TargetBiosWidth;
extern	int	TargetBiosHeight;
extern	int	WindowCol;
extern	int	WindowRow;
#define	_STANDARD_RGB	system_palette
extern	int	SignatureItems;
extern	char	Signature[512];

#ifdef __cplusplus	/* GWB le 03/09/2007 */
}
#endif

#endif	/* _SINGABAL_H */
	/* ----------- */

