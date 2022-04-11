// ****************************************************************************
// * zGraphic.h
// * Graphic module
// ****************************************************************************
#ifndef _ZGRAPHIC_H
#define _ZGRAPHIC_H

#ifdef __cplusplus
	extern "C" {
#endif
// ----------------------------------------------------------------------------
// - BDA functions
// ----------------------------------------------------------------------------
// zGraImg
WORD BDA_WINAPI BdaImg_zBmpLoad(WORD bmp_no,PTRC bmp_nom,WORD bmp_mode);
WORD BDA_WINAPI BdaImg_zBmpFree(WORD bmp_no);
WORD BDA_WINAPI BdaImg_zDllBitmapLoad(PTRC dll_nom);
WORD BDA_WINAPI BdaImg_zDllBitmapFree();
WORD BDA_WINAPI BdaImg_zButtonBitmap(WORD bout_type,PTRC bout_lib,PTRC bit_nom,WORD larg);
WORD BDA_WINAPI BdaImg_zButtonBmp(WORD bout_type,PTRC bout_lib,WORD bmp_no,WORD larg);
WORD BDA_WINAPI BdaImg_zBitmap(PTRC bit_nom,WORD x,WORD y,WORD larg,WORD haut);
WORD BDA_WINAPI BdaImg_zBmp(WORD bmp_no,WORD x,WORD y,WORD larg,WORD haut);
WORD BDA_WINAPI BdaImg_zBmp2(WORD bmp_no,WORD olarg,WORD ohaut,WORD x,WORD y,WORD larg,WORD haut);
WORD BDA_WINAPI BdaImg_ScreenSaver();

// zGraDraw
WORD BDA_WINAPI BdaImg_arc(WORD x1,WORD y1,WORD x2,WORD y2,WORD xs,WORD ys,WORD xe,WORD ye);
WORD BDA_WINAPI BdaImg_ellipse(WORD x1,WORD y1,WORD x2,WORD y2);
WORD BDA_WINAPI BdaImg_trapez(WORD x1,WORD y1,WORD x2,WORD y2,WORD x3,WORD y3,WORD x4,WORD y4);
WORD BDA_WINAPI BdaImg_roundrect(WORD x1,WORD y1,WORD x2,WORD y2, WORD EllipsLarg,WORD EllipsHaut);
WORD BDA_WINAPI BdaImg_rectangle(WORD x1,WORD y1,WORD x2,WORD y2);
WORD BDA_WINAPI BdaImg_line(WORD x1,WORD y1,WORD x2,WORD y2);
WORD BDA_WINAPI BdaImg_point(WORD x,WORD y);
WORD BDA_WINAPI BdaImg_pen(WORD type,WORD larg,WORD r,WORD g,WORD b);
WORD BDA_WINAPI BdaImg_brush(WORD type,WORD r,WORD g,WORD b);
WORD BDA_WINAPI BdaImg_color(WORD r,WORD g,WORD b);
WORD BDA_WINAPI BdaImg_getcolor(WORD jeu,WORD no);

// ----------------------------------------------------------------------------
// - Internal functions
// ----------------------------------------------------------------------------

#ifdef __cplusplus
	}
#endif

#endif
