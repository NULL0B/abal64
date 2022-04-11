/** @pkg Staff.Fred.zGuiCurs */ 

// ****************************************************************************
// * zCursor.c
// * Included in GUI module
// * Cursor and mouse functionnalities
// ****************************************************************************

//ANF
static char *  gUseMouse="\1USEMOUSE";

#ifndef BDA_UNIX
static    int gSpriteBufferWidth=0;
static    int gSpriteBufferHeight=0;

struct  mimo_event  {
  int e;
  int b;
  int l;
  int c;
  };

static  struct mimo_event Event;
#endif

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// - Basic internal Functions
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

// ****************************************************************************
/** GuiSetActiveCursor
 * @param string    IN : Yes=TRUE to show the caret
 * @return nothing
 * @author VAP FRC
 */
// * VarGlob:
// *   g_pLook->Caret
// ****************************************************************************
VOID GuiSetActiveCursor(WORD Yes)
{
PTI_COMP_CARET_DESCR pCaret = &g_pLook->Caret;

  if (!pCaret->IsInitialised)
    return;

  if (pCaret->IsVisible)
    {
    putzone(pCaret->GrPos.x,pCaret->GrPos.y,pCaret->GrSize.cx,pCaret->GrSize.cy,pCaret->BgCaret.Ptr);
    pCaret->IsVisible = FALSE;
    }

  if (Yes) 
    {
    pCaret->GrPos.x = (cicogetcolumn()-1)* cellwidth ;
    pCaret->GrPos.y = (cicogetline()-1)  * cellheight;

    getzone(pCaret->GrPos.x,pCaret->GrPos.y,pCaret->GrSize.cx,pCaret->GrSize.cy,pCaret->BgCaret.Ptr);
    mixzone(pCaret->GrPos.x,pCaret->GrPos.y,pCaret->GrSize.cx,pCaret->GrSize.cy,pCaret->FgCaret.Ptr);
    pCaret->IsVisible = TRUE;
    }
}


// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// - BDA APIs
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

// ****************************************************************************
/** BdaGui_zStatusMouse: (THO name) zstatusmouse - ABAL API
    Retrieve status of the mouse (position, buttons)

 * @param string    OUT : status buffer

 * @return CE_OK

 * @author ANF
 
 */
// * VarGlob:
// ****************************************************************************
WORD BDA_WINAPI BdaGui_zStatusMouse(PTRC string)
{
MI_TRACE_DCL_TFN("StatusMouse");

#ifndef BDA_UNIX
int event=0;
int work;
int i;
#endif

//MI_TRACE_BEGIN();
  if (!( *gUseMouse ))  /* If mouse disabled */
    {
    return CE_OK;
    //MI_TRACE_RETURN_MSG(CE_OK,"Dis");
   }
   
#ifndef	BDA_UNIX
  switch ( Event.e ) {

    case  _MIMO_UP  : /* Was down of click */
      if ( Event.b == 2 )
        string[1] = 10;
      else  string[1] = 0;
      Event.e = 0;
      MI_TRACE_RETURN_MSG(CE_OK,"UP");

    case  _MIMO_DOUBLE  : /* Was 1st Double Down */
      if ( Event.b == 2 )
        string[1] = 10;
      else  string[1] = 0;
      Event.e = _MIMO_CLICK;
      MI_TRACE_RETURN_MSG(CE_OK,"DBL");

    case  _MIMO_CLICK   : /* Was 1st Double Up */
      string[1] = 1;
      Event.e = _MIMO_UP;
      MI_TRACE_RETURN_MSG(CE_OK,"CLK");
    }

  for (i=0; i < 10; i++ )
    string[i]=0;

  while ((event =  test_mimo()) > _MIMO_KEYBOARD) {
    switch ((event = get_mimo())) {
      case  _MIMO_MOVE  :
        movemouse(get_mimo_col(),get_mimo_lin());
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
    movemouse((Event.c=get_mimo_col()),
        (Event.l=get_mimo_lin()));
    Event.b = get_mimo_par();
    if ( event != _MIMO_UP )
      string[1] = 1;
    work  = (int) (( ((long) (Event.c-1)) * gSpriteBufferWidth) / 140);
    string[6]=(char)((work>>8) & 0x00FF);
    string[7]=(char)(work & 0x00FF);
    string[3]=(char)(((work+1)/cellwidth)+((work+1)%cellwidth?1:0));
    work  = (int) (( ((long) (Event.l-1)) * gSpriteBufferHeight) / 140);
    string[8]=(char)((work>>8) & 0x00FF);
    string[9]=(char)(work & 0x00FF);
    string[5]=(char)(((work+1)/cellheight)+((work+1)%cellheight?1:0));
    break;
    }
#endif

//MI_TRACE_RETURN(CE_OK);
return CE_OK;
}

// ****************************************************************************
/** BdaGui_zMouseCursor: (THO name) zwin_mousecursor - ABAL API
    Select the look of the mouse cursor

 * @param type    IN : CE_MOUSE_ARROW, CE_MOUSE_BUSY, CE_MOUSE_HELP, CE_MOUSE_MOVE

 * @return CE_OK

 * @author CCDoc Administrator
 
 */
// * VarGlob:
// ****************************************************************************
WORD BDA_WINAPI BdaGui_zMouseCursor(WORD type)
{
MI_TRACE_DCL_TFN("MouseCursor");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

// ****************************************************************************
/** BdaGui_zAskCursor: (THO name) zwin_askcursor - ABAL API
    Show, hide caret
   This function is intended to show/hide carette.
   If we want to add carette handling under TwinServer - it's separate
   task, and requires a lot of work to do. Let's discuss this before.

 * @param oui    IN : 1=show, 0=hide

 * @return CE_OK

 * @author ANF
 
 */
// * VarGlob:
// ****************************************************************************
WORD BDA_WINAPI BdaGui_zAskCursor(WORD oui)
{
MI_TRACE_DCL_TFN("AskCursor");

MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"oui=%d",oui));
  SysHide();
  GuiSetActiveCursor(oui);
  SysShow();
MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaGui_zInitMouse: (THO name) zinitmouse - ABAL API
    unused function...

 * @param ? 

 * @return CE_OK

 * @author CCDoc Administrator
 
 */
// * VarGlob:
// *   Nothing
// ****************************************************************************
WORD BDA_WINAPI BdaGui_zInitMouse(PTRC string)
{
MI_TRACE_DCL_TFN("InitMouse");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

// ****************************************************************************
/** BdaGui_zShowMouse: (THO name) zshowmouse - ABAL API
    unused function...

 * @return CE_OK

 * @author CCDoc Administrator
 
 */
// * VarGlob:
// *   Nothing
// ****************************************************************************
WORD BDA_WINAPI BdaGui_zShowMouse(void)
{
MI_TRACE_DCL_TFN("ShowMouse");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

// ****************************************************************************
/** BdaGui_zHideMouse: (THO name) zinitmouse - ABAL API
    unused function...

 * @return CE_OK

 * @author CCDoc Administrator
 
 */
// * VarGlob:
// *   Nothing
// ****************************************************************************
WORD BDA_WINAPI BdaGui_zHideMouse(void)
{
MI_TRACE_DCL_TFN("HideMouse");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

