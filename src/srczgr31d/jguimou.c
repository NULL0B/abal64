#include "jguipix.h"
#include "jguimou.h"

/* PHL For Test */ 
static    int SpriteIsVisible=0;
static    int SpriteColumn=0;
static    int SpriteRow=0;
static    int SpriteMask=-1;

#ifdef  fucking_v0
static    int SpriteWidth=13;
static    int SpriteHeight=25;
static  unsigned char   SpriteZone[25][13];
#endif

    int SpriteBufferWidth=0;
    int SpriteBufferHeight=0;

static  int UseGuiMouse=1;
char * UseNewMouse="\1=NEWMOUSE";
static  int  NewMouseColumns=140;
static  int  NewMouseRows=140;

/* gif list of file : ptr.gif */
static  unsigned char   SpriteForm[25][13] = {
  {31,0,0,0,0,0,0,0,0,0,0,0,0},
  {31,31,0,0,0,0,0,0,0,0,0,0,0},
  {31,3,31,0,0,0,0,0,0,0,0,0,0},
  {31,3,3,31,0,0,0,0,0,0,0,0,0},
  {31,3,3,3,31,0,0,0,0,0,0,0,0},
  {31,3,3,3,3,31,0,0,0,0,0,0,0},
  {31,3,3,3,3,3,31,0,0,0,0,0,0},
  {31,3,3,3,3,3,3,31,0,0,0,0,0},
  {31,3,3,3,3,3,3,3,31,0,0,0,0},
  {31,3,3,3,3,3,3,3,3,31,0,0,0},
  {31,3,3,3,3,3,3,3,3,3,31,0,0},
  {31,3,3,3,3,3,3,31,31,31,31,31,0},
  {31,3,3,3,3,3,3,31,0,0,0,0,0},
  {31,3,3,3,31,3,3,3,31,0,0,0,0},
  {31,3,3,31,31,3,3,3,31,0,0,0,0},
  {31,3,31,0,0,31,3,3,3,31,0,0,0},
  {31,31,0,0,0,31,3,3,3,31,0,0,0},
  {31,0,0,0,0,0,31,3,3,3,31,0,0},
  {0,0,0,0,0,0,31,3,3,3,31,0,0},
  {0,0,0,0,0,0,0,31,3,3,3,31,0},
  {0,0,0,0,0,0,0,31,3,3,3,31,0},
  {0,0,0,0,0,0,0,0,31,3,3,3,31},
  {0,0,0,0,0,0,0,0,31,3,3,3,31},
  {0,0,0,0,0,0,0,0, 0,31,3,3,31},
  {0,0,0,0,0,0,0,0, 0,31,31,31,31}
  };

static  unsigned char * SpritePointer=(char*)SpriteForm;

int hidemouse() 

{
#ifdef  fucking_v0
  // FCH06042001 TwinGr/Tx compatibility
  if (!( UseGuiMouse & 2 ))
      return(0);

  if (( SpriteIsVisible   )
  &&  ( SpriteWidth  !=  0)
  &&  ( SpriteHeight !=  0)) {
    putzone(SpriteColumn, SpriteRow, SpriteWidth,SpriteHeight,(char*)SpriteZone);
    SpriteIsVisible = 0;
    return(1);
    }
  else  return((SpriteIsVisible=0));
#else
  return(0);
#endif
}

int mouseover( int tx, int ty, int nx , int ny )
{
#ifdef  fucking_v0
  // FCH06042001 TwinGr/Tx compatibility
  if (!( UseGuiMouse & 2 ))
      return(0);

  if (!( SpriteIsVisible ))
    return(0);
  else if ( SpriteColumn > (tx + nx))
    return(0);
  else if (( SpriteColumn + SpriteWidth) < tx)
    return(0);
  else if ( SpriteRow > (ty + ny))
    return(0);
  else if (( SpriteRow + SpriteHeight) < ty)
    return(0);
  else  return(1);
#else
  return(0);
#endif
}

void  mousecurser( unsigned char * iptr )
{
  if (!(SpritePointer = iptr ))
    SpritePointer = (char*) SpriteForm;
  return;
}


void  showmouse()
{
#ifdef  fucking_v0
  // FCH06042001 TwinGr/Tx compatibility
  if (!( UseGuiMouse & 2 ))
        return;

  if (!( SpriteIsVisible )) {
    if (( SpriteWidth  !=  0)
    &&  ( SpriteHeight !=  0)) {
      if (( SpriteColumn + SpriteWidth ) > SpriteBufferWidth)
        SpriteColumn = (SpriteBufferWidth - SpriteWidth);
      if (( SpriteRow + SpriteHeight ) > SpriteBufferHeight)
        SpriteRow = (SpriteBufferHeight - SpriteHeight);
      getzone(SpriteColumn, SpriteRow, SpriteWidth,SpriteHeight,(char*)SpriteZone);
      mixzone(SpriteColumn, SpriteRow, SpriteWidth,SpriteHeight,SpritePointer);
      }
    SpriteIsVisible = 1;
    }
#endif
  return;
}

void  calibrate_mouse( int fbw, int fbh )
{

  if ( *UseNewMouse ) {
  NewMouseColumns = fbw;
  NewMouseRows = fbh;
  }

  SpriteBufferWidth = fbw;
  SpriteBufferHeight= fbh;
  return;
}

void  movemouse(int c, int l)
{
#ifdef  fucking_v0
  int mode;
  int sc;
  int sr;
  // FCH06042001 TwinGr/Tx compatibility
  if (!( UseGuiMouse & 1 ))
      return;

  c--; l--;
  sc = (int) (( ((long) c) * SpriteBufferWidth) / NewMouseColumns);
  sr = (int) (( ((long) l) * SpriteBufferHeight) / NewMouseRows);
  if ((sc != SpriteColumn) || ( sr != SpriteRow)) {
  mode = hidemouse();
    SpriteColumn = sc; SpriteRow = sr;
  if ( mode )
    showmouse();
    }
#endif
  return;
}

void  initialise_mouse()
{
  // FCH06042001 TwinGr/Tx compatibility
  if ((UseGuiMouse = redirected_mici()) & 4)
      *UseNewMouse=0;
  
  if ( *UseNewMouse )
        use_new_mimo();
  else  use_old_mimo();

  init_mimo();
  activate_mimo();
  SpriteMask = get_mimo_mask();

  // FCH06042001 TwinGr/Tx compatibility
  if ( UseGuiMouse & 1 ) {
      set_mimo_mask((
      _MIMO_WHILE_DOWN |
      _MIMO_MOVE   |
      _MIMO_DOWN   |
      _MIMO_UP   |
      _MIMO_SEND_RIGHT |
      _MIMO_SEND_LEFT        ));
      mimo_move();
    } 

  SpriteColumn = SpriteRow = 0; 
  SpriteIsVisible = 0;
  return;
}

void  terminate_mouse()
{
  // FCH06042001 TwinGr/Tx compatibility
  if ( UseGuiMouse & 1) {
    (void) hidemouse();
    mimo_nomove();
    set_mimo_mask(SpriteMask);
    }
  inhibit_mimo();
  fin_mimo();
  return;
}

void disable_mouse_move()
{
if ( UseGuiMouse & 1 ) 
  {
  set_mimo_mask((
  //_MIMO_DOWN   |
  _MIMO_UP   |
  _MIMO_SEND_RIGHT |
  _MIMO_SEND_LEFT        ));
  } 
}

void enable_mouse_move()
{
if ( UseGuiMouse & 1 ) 
  {
  set_mimo_mask((
  _MIMO_WHILE_DOWN |
  _MIMO_MOVE   |
  _MIMO_DOWN   |
  _MIMO_UP   |
  _MIMO_SEND_RIGHT |
  _MIMO_SEND_LEFT        ));
  } 
}

