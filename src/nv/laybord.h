//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_layout_border_h
#define _html_layout_border_h

#define	_LAYOUT_FRAME_TOP	1
#define	_LAYOUT_FRAME_END	2
#define	_LAYOUT_FRAME_EDGE	(_LAYOUT_FRAME_TOP | _LAYOUT_FRAME_END)

#define	_LAYOUT_FRAME_ROW	4

#define	_LAYOUT_TABLE_TOP	_LAYOUT_FRAME_TOP			// 1
#define	_LAYOUT_ROW_TOP		(_LAYOUT_FRAME_TOP | _LAYOUT_FRAME_ROW) // 5
#define	_LAYOUT_ROW_END		(_LAYOUT_FRAME_END | _LAYOUT_FRAME_ROW) // 6
#define	_LAYOUT_TABLE_END	_LAYOUT_FRAME_END			// 2

#define	_LAYOUT_TABLE_LINE	0	

#endif	// _html_layout_border_h

