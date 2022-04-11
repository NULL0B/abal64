#ifndef	_SINGREL_H
#define	_SINGREL_H

#include "palet.h"

#include "vframe.h"

#ifdef	_SINGREL_C
int	transparent=0;
int	standard_black		=_DEFAULT_GUI_BLACK;
int	standard_lolight	=_DEFAULT_GUI_DARK_LOW;
int	standard_lomid		=_DEFAULT_GUI_DARK;
int	standard_backwash	=_DEFAULT_GUI_NEUTRAL;
int	standard_himid		=_DEFAULT_GUI_LIGHT;
int	standard_hilight	=_DEFAULT_GUI_LIGHT_HIGH;
int	standard_white		=_DEFAULT_GUI_WHITE;
int	standard_text		=_DEFAULT_GUI_FG_TITLE;
int	standard_title		=_DEFAULT_GUI_BG_TITLE;
int	standard_focus		=_DEFAULT_GUI_FOCUS;
int	standard_grayed		=_DEFAULT_GUI_GRAYED;
#else
#ifdef __cplusplus	/* GWB le 05/06/207 */
extern "C" {
#endif

extern int transparent		; /*  0	*/
extern int standard_black	; /*  _DEFAULT_GUI_BLACK */
extern int standard_lolight	; /*  _DEFAULT_GUI_DARK_LOW */
extern int standard_lomid	; /*  _DEFAULT_GUI_DARK */
extern int standard_backwash	; /*  _DEFAULT_GUI_NEUTRAL */
extern int standard_himid	; /*  _DEFAULT_GUI_LIGHT */
extern int standard_hilight	; /*  _DEFAULT_GUI_LIGHT_HIGH */
extern int standard_white	; /*  _DEFAULT_GUI_WHITE */
extern int standard_text	; /*  _DEFAULT_GUI_FG_TITLE */
extern int standard_title	; /*  _DEFAULT_GUI_BG_TITLE */
extern int standard_focus	; /*  _DEFAULT_GUI_FOCUS */
extern int standard_grayed	; /*  =_DEFAULT_GUI_GRAYED */

#ifdef __cplusplus	/* GWB le 05/06/207 */
}
#endif

#endif

#endif	/* _SINGREL_H */

