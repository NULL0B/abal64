//
//	--------------------	
//	Project	: Navigator	
//	--------------------	
//	Date	: 29/01/2001
//	--------------------
//

#ifndef	_PIXELCO_H
#define _PIXELCO_H

//	--------------------------------------------------------------
//	These functions have been added to allow application control
//	over the use of proportional fonts for text output.
//	--------------------------------------------------------------
//	These four functions output text at the graphical corrdinates
//	provided by their initial two integer parameters.
//	--------------------------------------------------------------

int 	PixelPutSat(int,int,char *);
int 	PixelPutLat(int,int,char *,int);
int 	PixelFontSat(int,int,int,char *);
int 	PixelFontLat(int,int,int,char *,int);

//	--------------------------------------------------------------
//	These two functions output text at the cico cursor position 
//	and adjust the cursor to be positioned just after the text.
//	--------------------------------------------------------------
int 	PixelToken(char *);
int 	PixelTokenL(char *, int);
int 	PixelTokenColumn();
int 	PixelTokenRow();

//	--------------------------------------------------------------
//	This sets a right margin limit for the clipping of proportional
//	text strings.
//	--------------------------------------------------------------
int	CicoFontMargin(int);

//	--------------------------------------------------------------
//	These four functions return the number of base font character
//	cells that would be occupied by the display. 
//	--------------------------------------------------------------
int	CicoFontCharacters( char *);
int	CicoFontLCharacters( char *,int);
int	CicoFontFCharacters( char *,int);
int	CicoFontLFCharacters( char *,int,int);


#endif	// _PIXELCO_H

