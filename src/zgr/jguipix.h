//
//  ------------------  ----------------------------
//  Project : JavAbal Compiler and Virtual Machine  
//  ------------------  ----------------------------
//  Date  : 18/09/97
//  ------------------  ----------------------------
//

#ifndef _PIXELGUI_H
#define _PIXELGUI_H

#define _GUI_HILITE 28
#define _GUI_LOLITE 20
#define _GUI_BACKGR 24

//  ------------------------------------    
//  Prototypes of Functions in PIXEL.ASM    
//  ------------------------------------    

void  PixelPutc( int );
void  PixelPuts( char * );

int   initialise_for_gui( int );
void  liberate_for_gui( void );
int initialisepixel( int );
int putblock( int, int, int, int, char * );
int putpixel( int, int, int );
int getpixel( int, int );
int liberatepixel( void );
unsigned int putzone(unsigned int,unsigned int,unsigned int,unsigned int,char *);
unsigned int getzone(unsigned int,unsigned int,unsigned int,unsigned int,char *);
unsigned int swapzone(unsigned int,unsigned int,unsigned int,unsigned int,char *);
unsigned int mixzone(unsigned int,unsigned int,unsigned int,unsigned int,char *);
unsigned int filzone(unsigned int,unsigned int,unsigned int,unsigned int,unsigned int);
unsigned int addzone(unsigned int,unsigned int,unsigned int,unsigned int,char *);
unsigned int subzone(unsigned int,unsigned int,unsigned int,unsigned int,char * );
unsigned int putzoom(unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,char *);
unsigned int mixzoom(unsigned int,unsigned int,unsigned int,unsigned int,char *);
unsigned int andzone(unsigned int,unsigned int,unsigned int,unsigned int,unsigned int);
unsigned int orzone(unsigned int,unsigned int,unsigned int,unsigned int,unsigned int);
unsigned int xorzone(unsigned int,unsigned int,unsigned int,unsigned int,unsigned int);
unsigned int traceln(unsigned int,unsigned int,unsigned int,unsigned int,unsigned int);

#if defined	(BDA_UNIX) || defined (BDA_WIN32)
// traductions de noms de fonctions différent sous Twin et Linux
#define cicocurser(a,b) cicocursor(a,b)
#define cicogetcolumn   x_col
#define cicogetline     x_lin
#define cicofont(a)
#endif

#if defined	(BDA_TWIN16)
int cicofont( char * );
#endif

int cicocurser( int, int );
int cicocolour( int, int );
int cicotext( char *, int );

#if defined(BDA_WIN32)
unsigned short cicogetcolumn(void);
unsigned short cicogetline(void);
#else
int cicogetcolumn(void);
int cicogetline(void);
#endif

#ifndef _three_d_c
int calc3d( void );
int draw3d( void );
int fill3d( void );
int wire3d( void );
int map3d( void );
int clip3d( void );
int focus3d( void );
int push3d( void );
int pop3d( void );
#endif
int cicosetstyle( int );
int hardcolumns( void );
int hardrows( void );
int commitware( void );
int shareware( int, int, int, int, char * );
int pushware( void );
int popware( void );
int commitzone( void );
int extractzone( void );
int cicomargin( int, int );
int cicoshadow( int );
int getpalette( void );
int loadfont( void );
int swapfont( void );

//  ---------------------------------------------------------------------
//  CalcZone ( column, line, columns, rows, buffer )
//  ---------------------------------------------------------------------
//       @arg1        : First Text Column
//         @arg2      : First Text Line
//          @arg3     : Text Column Count
//            @arg4   : Text Line Count
//             @arg5  : Result Buffer
//  ---------------------------------------------------------------------
//  This funtion calculates a pixel storage buffer descriptor which
//  is placed in the buffer object pointed to by the final parameter.
//  This buffer will be an ABAL++ type Object with the following structure :
// 
//  Buffer    +0  Total Width  in Pixels
//      +2  Total Height in Pixels
//      +4  Number of Buffers needed
//      +6  Number of Pixel Rows Per Buffer
//      +8  Initial Pixel Column
//      +A  Initial Pixel Row   
// 
//  or a Matrix of short integers !!!! ( for JVM 'C' usage )
///

int calczone( int, int, int, int, short int * );
int calcbuff( short int * );
int getcodesegment( void );
int basefontcolumns( void );
int basefontlines( void );
int get_base_font_width( void );
int get_base_font_height( void );
int makeimagefit( void );
void loadguifont( int, char *, int );
int guifontsize(int);
int use_base_font( int );
int fonted_text( int, char * );
int cicopalette( int, int );
int cicoatribut( int );

int textlength( unsigned char * string, int length );
int PixelPutLength ( unsigned char * string, unsigned short int length );
int PixelPutCat ( int column, int row, unsigned char c );


//  --------------------------------------------------------------
//  These functions have been added to allow application control
//  over the use of proportional fonts for text output.
//  --------------------------------------------------------------
//  These four functions output text at the graphical corrdinates
//  provided by their initial two integer parameters.
//  --------------------------------------------------------------

int   PixelPutSat(int,int,char *);
int   PixelPutLat(int,int,char *,int);
int   PixelFontSat(int,int,int,char *);
int   PixelFontLat(int,int,int,char *,int);
int   PixelFontCat(int column, int row, int fontid, unsigned char c );

//  --------------------------------------------------------------
//  These two functions output text at the cico cursor position 
//  and adjust the cursor to be positioned just after the text.
//  --------------------------------------------------------------
int   PixelToken(char *);
int   PixelTokenL(char *, int);
int   PixelTokenColumn();
int   PixelTokenRow();

//  --------------------------------------------------------------
//  This sets a right margin limit for the clipping of proportional
//  text strings.
//  --------------------------------------------------------------
int CicoFontMargin(int);
int SetCicoPixelColumn(int);

//  --------------------------------------------------------------
//  These four functions return the number of base font character
//  cells that would be occupied by the display. 
//  --------------------------------------------------------------
int CicoFontCharacters( char *);
int CicoFontLCharacters( char *,int);
int CicoFontFCharacters( char *,int);
int CicoFontLFCharacters( char *,int,int);

//  --------------------------------------------------------------
//  FCH06042001
//  new function to ensure Twingr/Twintx compatibility
//  (see Jamie)
//  --------------------------------------------------------------
int redirected_mici(void);

void  cico_redirection(void* rt_init );
void  vgapalette( char * pptr, int i, int j );

//  --------------------------------------------------------------
//  FCH02102002
//  new function for hide/show
//  (see Jamie)
//  --------------------------------------------------------------
int	show( int, int, int, int);
void hide();

#if defined(BDA_UNIX) || defined(BDA_WIN32)
int	get_pixel_size();
int	put_palette_pixel(char * rptr, int v );
int	get_pixel_format();
int	put_logical_pixel( void * vptr, int r, int g, int b );
#endif

  // ------------///
#endif  // _PIXELGUI_H  
  // ------------///



