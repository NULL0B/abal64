
#include "mouse.h"
#include "jMouse.h"
#include "jGuiMou.h"

char *  oldmimomover=(char *) 0;
void *  set_mimo_mover( void * );

extern char * UseNewMouse;

int MouseReady=0;

struct  mimo_event  {
  int e;
  int b;
  int l;
  int c;
  };

static  struct mimo_event Event;

VOID zzshowmouse()
{
  showmouse();
  return;
}

VOID zzhidemouse()
{
  hidemouse();
  return;
}

VOID  zMouseMover( unsigned short int * descriptor )
{
  unsigned short int etype = descriptor[0];
  //unsigned short int epara = descriptor[1];
  unsigned short int atlin = descriptor[2];
  unsigned short int atcol = descriptor[3];

  if ( etype > _MIMO_KEYBOARD ) {

    if (!( *UseNewMouse ))
      movemouse( atcol, atlin );

    if ( etype & _MIMO_MOVE )
      descriptor[0] = 0;

    else  {
      if (!( *UseNewMouse )) {  
        descriptor[2] =((((atlin-1) * screenlins) / 140)+1);
        descriptor[3] =((((atcol-1) * screencols) / 140)+1);
        }
      }
    }
//  return(0);
}

SWORD zzinitmouse(char FAR * string)
{
  if (!( MouseReady )) {
  Event.e = Event.b = Event.c = Event.l = 0;
  initialise_mouse();
    oldmimomover = set_mimo_mover(zMouseMover);
    }
  MouseReady++;
  return(0);
}

VOID  zzendmouse()
{
  if ( MouseReady )
    MouseReady--;
  if (!( MouseReady )) {
  if ( oldmimomover ) {
      (void) set_mimo_mover( oldmimomover );
      oldmimomover = (void *) 0;
      }
    terminate_mouse();
    }
  return;
}

static char *  usemouse="\0USEMOUSE";

int xget_mimo_col()
{
  int v;
#ifdef  _MOUSE_TRACING
  TraceFunc("xget_mimo_col");
#endif
  v = get_mimo_col();
#ifdef  _MOUSE_TRACING
  TraceInt( v );
#endif
  return( v );
}
int xget_mimo_lin()
{
  int v;
#ifdef  _MOUSE_TRACING
  TraceFunc("xget_mimo_lin");
#endif
  v = get_mimo_lin();
#ifdef  _MOUSE_TRACING
  TraceInt( v );
#endif
  return( v );
}
int xget_mimo_par()
{
  int v;
#ifdef  _MOUSE_TRACING
  TraceFunc("xget_mimo_par");
#endif
  v = get_mimo_par();
#ifdef  _MOUSE_TRACING
  TraceInt( v );
#endif
  return( v );
}
int xtest_mimo()
{
  int v;
#ifdef  _MOUSE_TRACING
  TraceFunc("xtest_mimo");
#endif
  v = test_mimo();
#ifdef  _MOUSE_TRACING
  TraceInt( v );
#endif
  return( v );
}

int xget_mimo()
{
  int v;
#ifdef  _MOUSE_TRACING
  TraceFunc("xget_mimo");
#endif
  v = get_mimo();
#ifdef  _MOUSE_TRACING
  TraceInt( v );
#endif
  return( v );
}

VOID zzstatusmouse(char FAR * string)
{
  int event=0;
  int work;
  int i;

  
  if (!( *usemouse ))
    return;

  switch ( Event.e ) {

    case  _MIMO_UP  : /* Was down of click */
      if ( Event.b == 2 )
        string[1] = 10;
      else  string[1] = 0;
      Event.e = 0;
      return;

    case  _MIMO_DOUBLE  : /* Was 1st Double Down */
      if ( Event.b == 2 )
        string[1] = 10;
      else  string[1] = 0;
      Event.e = _MIMO_CLICK;
      return;

    case  _MIMO_CLICK   : /* Was 1st Double Up */
      string[1] = 1;
      Event.e = _MIMO_UP;
      return;

    }

  for (i=0; i < 10; i++ )
    string[i]=0;

  while ((event =  xtest_mimo()) > _MIMO_KEYBOARD) {
    switch ((event = xget_mimo())) {
      case  _MIMO_MOVE  :
        movemouse(xget_mimo_col(),xget_mimo_lin());
        continue;
      case  _MIMO_CLICK :
        Event.e = _MIMO_UP;
        break;
      case  _MIMO_DOUBLE  :
        Event.e = event;
        break;
      case  _MIMO_DOWN  :
      case  _MIMO_UP    :
      case  _MIMO_WHILE_DOWN:
        Event.e = 0;
        break;
      }
    movemouse((Event.c=xget_mimo_col()),
        (Event.l=xget_mimo_lin()));
    Event.b = xget_mimo_par();
    if ( event != _MIMO_UP )
      string[1] = 1;
    work  = (int) (( ((long) (Event.c-1)) * SpriteBufferWidth) / 140);
    string[6]=(char)((work>>8) & 0x00FF);
    string[7]=(char)(work & 0x00FF);
    string[3]=(char)(((work+1)/cellwidth)+((work+1)%cellwidth?1:0));
    work  = (int) (( ((long) (Event.l-1)) * SpriteBufferHeight) / 140);
    string[8]=(char)((work>>8) & 0x00FF);
    string[9]=(char)(work & 0x00FF);
    string[5]=(char)(((work+1)/cellheight)+((work+1)%cellheight?1:0));
    break;
    }
  return;
}



