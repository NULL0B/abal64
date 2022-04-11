// GWB le 21/02/2007 
// *******************************************************************************
// * strucpsu.h
// * le contenu de ce fichier ne doit pas être lu si stdpsu.h est déjà inclus
// *******************************************************************************

#if !defined(_STRUCPSU_H_) && !defined(_STDPSU_H)
#define _STRUCPSU_H_

#define	STDPSU		struct standard_pixel_storage
#define	STDPSUPTR	STDPSU*

STDPSU	{
	unsigned short		descriptor[8];
	unsigned char *	root;
	unsigned char *	current;
	unsigned short		seekbase;
	unsigned short		seeksize;
	};

#endif //_STRUCPSU_H_

