// ****************************************************************************
// * zGlobal.h
// * Global variables for all modules
// ****************************************************************************
#ifndef _ZGLOBAL_H
#define _ZGLOBAL_H

//VAP MODIFICATION 8.12.00  11.37
//screen text & graphic constants
//Is borrowed at Jammie zGlobal.c

// Fch:08-02-2002
extern char FAR PTR  g_pLanguage;

extern unsigned char g_VgaPalette[256][4];

extern SWORD bmp_error_code;
extern SWORD window_error_code;

extern SWORD   cellheight;    // Hauteur d'1 caractère
extern SWORD   cellwidth;     // Largeur d'1 caractère
extern WORD    screencols;    // columns of text per line
extern WORD    screenlins;    // lines of text per screen

extern SWORD   g_VesaMode;    

extern BYTE  g_FontRescueBuffer[8192];

#endif
