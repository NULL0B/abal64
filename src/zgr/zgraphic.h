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
EXAWORD BDA_API BdaImg_zBmpLoad(WORD bmp_no,char FAR * bmp_nom,WORD bmp_mode);
EXAWORD BDA_API BdaImg_zBmpFree(WORD bmp_no);
EXAWORD BDA_API BdaImg_zDllBitmapLoad(char FAR * dll_nom);
EXAWORD BDA_API BdaImg_zDllBitmapFree();
EXAWORD BDA_API BdaImg_zButtonBitmap(WORD bout_type,char FAR * bout_lib,char FAR * bit_nom,WORD larg);
EXAWORD BDA_API BdaImg_zButtonBmp(WORD bout_type,char FAR * bout_lib,WORD bmp_no,WORD larg);
EXAWORD BDA_API BdaImg_zBitmap(char FAR * bit_nom,WORD x,WORD y,WORD larg,WORD haut);
EXAWORD BDA_API BdaImg_zBmp(WORD bmp_no,WORD x,WORD y,WORD larg,WORD haut);
EXAWORD BDA_API BdaImg_zBmp2(WORD bmp_no,WORD olarg,WORD ohaut,WORD x,WORD y,WORD larg,WORD haut);
EXAWORD BDA_API BdaImg_ScreenSaver();

// zGraDraw
EXAWORD BDA_API BdaImg_arc(WORD x1,WORD y1,WORD x2,WORD y2,WORD xs,WORD ys,WORD xe,WORD ye);
EXAWORD BDA_API BdaImg_ellipse(WORD x1,WORD y1,WORD x2,WORD y2);
EXAWORD BDA_API BdaImg_trapez(WORD x1,WORD y1,WORD x2,WORD y2,WORD x3,WORD y3,WORD x4,WORD y4);
EXAWORD BDA_API BdaImg_roundrect(WORD x1,WORD y1,WORD x2,WORD y2, WORD EllipsLarg,WORD EllipsHaut);
EXAWORD BDA_API BdaImg_rectangle(WORD x1,WORD y1,WORD x2,WORD y2);
EXAWORD BDA_API BdaImg_line(WORD x1,WORD y1,WORD x2,WORD y2);
EXAWORD BDA_API BdaImg_point(WORD x,WORD y);
EXAWORD BDA_API BdaImg_pen(WORD type,WORD larg,WORD r,WORD g,WORD b);
EXAWORD BDA_API BdaImg_brush(WORD type,WORD r,WORD g,WORD b);
EXAWORD BDA_API BdaImg_color(WORD r,WORD g,WORD b);
EXAWORD BDA_API BdaImg_getcolor(WORD jeu,WORD no);

// ----------------------------------------------------------------------------
// - Internal functions
// ----------------------------------------------------------------------------

#ifdef __cplusplus
	}
#endif

#endif
