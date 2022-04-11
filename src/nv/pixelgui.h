//
//	------------------	----------------------------
//	Project	: JavAbal	Compiler and Virtual Machine	
//	------------------	----------------------------
//	Date	: 18/09/97
//	------------------	----------------------------
//

#ifndef	_PIXELGUI_H
#define _PIXELGUI_H

#define	_GUI_HILITE	28
#define	_GUI_LOLITE	20
#define	_GUI_BACKGR	24

//	------------------------------------		
//	Prototypes of Functions in PIXEL.ASM		
//	------------------------------------		

void	PixelPutc( int );
void	PixelPuts( char * );

int 	initialise_for_gui( int );
void	liberate_for_gui( void );
int	initialisepixel( int );
int	putblock( int, int, int, int, char * );
int	putpixel( int, int, int );
int	getpixel( int, int );
void	liberatepixel( void );
int	putzone(int,int,int,int,char *);
int	getzone(int,int,int,int,char *);
int	swapzone(int,int,int,int,char *);
int	mixzone(int,int,int,int,char *);
int	filzone(int,int,int,int,int);
int	addzone(int,int,int,int,char *);
int	subzone(int,int,int,int,char * );
int	putzoom(int,int,int,int,int,char *);
int	mixzoom(int,int,int,int,char *);
#ifndef	_PROTO_USERWARE
#define	_PROTO_USERWARE
int	userware( int, int, char * );
#endif
int	hardware( void );
int	testware( void );
int	andzone(int,int,int,int,int);
int	orzone(int,int,int,int,int);
int	xorzone(int,int,int,int,int);
int	traceln(int,int,int,int,int);
int	cicofont( char * );
int	cicocurser( int, int );
int	cicocolour( int, int );
int	cicotext( char *, int );
#ifndef _three_d_c
int	calc3d( void );
int	draw3d( void );
int	fill3d( void );
int	wire3d( void );
int	map3d( void );
int	clip3d( void );
int	focus3d( void );
int	push3d( void );
int	pop3d( void );
#endif
int	cicosetstyle( int );
int	hardcolumns( void );
int	hardrows( void );
int	commitware( void );
int	shareware( int, int, int, int, char * );
int	pushware( void );
int	popware( void );
int	commitzone( void );
int	extractzone( void );
int	cicomargin( int, int );
int	cicoshadow( int );
int	getpalette( void );
int	loadfont( void );
int	swapfont( void );

// 	---------------------------------------------------------------------
// 	CalcZone ( column, line, columns, rows, buffer )
// 	---------------------------------------------------------------------
// 		   @arg1				: First Text Column
// 			   @arg2			: First Text Line
// 				  @arg3			: Text Column Count
// 					  @arg4		: Text Line Count
// 						 @arg5	: Result Buffer
// 	---------------------------------------------------------------------
// 	This funtion calculates a pixel storage buffer descriptor which
// 	is placed in the buffer object pointed to by the final parameter.
// 	This buffer will be an ABAL++ type Object with the following structure :
// 
// 	Buffer		+0	Total Width  in Pixels
// 			+2	Total Height in Pixels
// 			+4	Number of Buffers needed
// 			+6	Number of Pixel Rows Per Buffer
// 			+8	Initial Pixel Column
// 			+A	Initial Pixel Row   
// 
//	or a Matrix of short integers !!!! ( for JVM 'C' usage )
///

int	calczone( int, int, int, int, short int * );
int	calcbuff( short int * );
int	getcodesegment( void );
int	basefontcolumns( void );
int	basefontlines( void );
int	get_base_font_width( void );
int	get_base_font_height( void );
int	makeimagefit( void );
void	loadguifont( int, char *, int );
int	guifontsize(int);
int 	use_base_font( int );
int	fonted_text( int, char * );
int	cicopalette( int, int );
int	cicoatribut( int );
void	hide();
int 	show(int,int,int,int);

	// ------------///
#endif	// _PIXELGUI_H	
	// ------------///



