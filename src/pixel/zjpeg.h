#ifndef	_standard_jpeg_h
#define	_standard_jpeg_h

#include "vimage.h"

//	JPEG Options Bit Values
//	-----------------------


//	The percentage trace option when set will cause the navigator
//	Jpeg Client Object to display the progression of JPEG image
//	loading as a percentage value in the status box ( if this is visible )
//	Otherwise no progression trace will be displayed and the image will
//	be decomressed silently.

#define	_JPEG_SOLO   		0x0200

#define	_JPEG_VERBOSE		0x0100

//	NO QUANTIZING	This flag will inhibit the quantizing mechanism
//	and all associated optional flags such as dithering smoothing
//	and colour count.
//	consequently 24 bit colour components may be returned but these
//	will be approximated to the courrent palette which is an
//	extremly slow process !


#define	_JPEG_NOQUANT		0x0080


//	The PALETTE option indicates to NV that each document will possess 
//	an individual palette of colours.

#define	_JPEG_PALETTE		0x0040

//	The PROTECT option indicates that the 32 basic colours, 
//			Text compatible 0  to 15
//		and 	Grey Scale	16 to 31
//	are to be protected. consequntly if quantizing then only 256 - 32
//	colours will be available.

#define	_JPEG_PROTECT		0x0020


//	The FS DITHER and ORDERED bits work together to define the
//	Dither type to be selected when colour quantizing is active.
//	Value	018	: ORDERED takes preference over FS
//	Value	008	: ORDERED
//	Value	010	: FS DITHERING
//	Other valuse where both FS and ORDERED are cleared will select
//	no dithering (which is fast but very messy).

#define	_JPEG_FSDITHER		0x0010
#define	_JPEG_ORDERED		0x0008

//	DCT IFAST	This is a speed optimisation and reqiures that
//	fast integer methods are to be used for quantization.
//	Other wise slower but more precise integer methods will be used.

#define	_JPEG_DCTIFAST	0x0004

//	NOSMOOTH	This speed optimisation requires that no colour
//	smoothing be performed during quantising colours.

#define	_JPEG_NOSMOOTH	0x0002

//	ONEPASS		This speed option requires that only ONE pass be
//	made during quantizing otherwise TWO passes will be performed.

#define	_JPEG_ONEPASS 	0x0001

#define	_JPEG_DEFAULT (_JPEG_FSDITHER | _JPEG_PROTECT | _JPEG_PALETTE )


int			initialise_jpeg( char * );
struct standard_image * parse_jpeg(struct standard_image * );
void			terminate_jpeg();
struct standard_image * jpeg_loader(char *);
void			jpeg_options( int );

void	set_image_quality(int v);
int	get_image_quality();

#endif	/* _standard_jpeg_h */


