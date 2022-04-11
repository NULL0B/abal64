#ifndef GRAPIL_H
#define GRAPIL_H

	int LoadImage(char * pImageFileName, unsigned char ForceLoad, void * pImage);
	void * CloneImage(void * pImage);
	int DropImage(void * pImage);
	int LoadFontM(char * pFontName, unsigned char ForceLoad, void * pFont);
	int DropFont(void * pFont);
	int LoadPalette(void * pPalette);

#endif
