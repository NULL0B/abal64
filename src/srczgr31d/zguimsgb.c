/** @pkg Staff.Fred.zGuiMsgb */ 
// ****************************************************************************
// * zMsgbox.c
// * Included in GUI module
// * Message boxes functionnalities
// ****************************************************************************

#define CI_PARSE_NBLINE 3
typedef struct
  {
  WORD  NbLine;
  WORD  MaxLen;
  char* Line[CI_PARSE_NBLINE];
  WORD  Len [CI_PARSE_NBLINE];
  } TI_PARSE, *PTI_PARSE;

PTI_SCREENHOLDER mbox_bg=0;

#define CI_MSGBUF_LEN 241
static  BYTE  MessageBuffer[CI_MSGBUF_LEN];  // Buffer for storing messages



// ****************************************************************************
// * GuiInitialiseMBoxSystem
// ****************************************************************************
int GuiInitialiseMBoxSystem(int x1,int y1,int x2,int y2){
  TI_RECTANGLE a;
  a.x1=x1;
  a.x2=x2;
  a.y1=y1;
  a.y2=y2;
  mbox_bg=allocate_screenholder(&a);
  if(!mbox_bg) return CE_ERR_MEMORY;
  return CE_OK;
}

// ****************************************************************************
// * GuiDestroyMBoxSystem
// ****************************************************************************
void GuiDestroyMBoxSystem(){
  free_screenholder(mbox_bg);
}

// ****************************************************************************
/** copymessage - copies message to be displayed into internal buffer
 * @param mptr        IN  message text
 * @param lg          IN  message length

 * @return new size of the message (message may be truncated)

 * @author CCDoc Administrator
 
 */
// * VarGlob:
// ****************************************************************************
// ANF
int copymessage( char * mptr, int lg )
{
  if ( lg >= CI_MSGBUF_LEN ) lg = CI_MSGBUF_LEN-1;
  memcpy(MessageBuffer,mptr,lg);
  MessageBuffer[lg]=0;
  return(lg);
}

// ****************************************************************************
/** ParseLine - Parse a messagebox message (with crlf to separate 3 lines)
 * @param p                 IN  message text
 * @param MaxLenRequested   IN  message max length
 * @param Parse             OUT Parse structure pointing on the message

 * @return nothing

 * @author CCDoc Administrator
 */
// ****************************************************************************
void ParseLine( char* p, WORD MaxLenRequested, PTI_PARSE Parse)
{
  MI_TRACE_DCL_TFN("ParseLine");
  register WORD Etat;
  register WORD Len;

  Etat  = 1;
  while(Etat)
    {
    MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"Etat=%d Len=%d",Etat,Len));
    
    switch(Etat)
      {
      case 1: // --- Initialisation
        Parse->NbLine = 0; // During loop NbLine is used as index, not as length
        Parse->MaxLen = 0;
        Etat     = 2;
        break;

      case 2: // --- Begin Line
        Parse->Line[Parse->NbLine]=p;
        Len  = 0;
        Etat = 3;
        break;

      case 3: // --- Parse normal
        if      (*p=='\0') 
          Etat = 5;
        else if ((*p=='\x0D') || (*p=='\x0A'))
          {
          p++; 
          Etat=4; 
          }
        else if (Len>=MaxLenRequested)
          {
          p++; 
          Etat=6; 
          }
        else
          {
          p++; 
          Len++;
          }
        break;

      case 6: // --- Parse during out of length
        if      (*p=='\0') 
          Etat = 5;
        else if ((*p=='\x0D') || (*p=='\x0A'))
          {
          p++; 
          Etat=4; 
          }
        else
          p++; 
        break;

      case 4: // --- Parse during 0D/0A found
        if ((*p=='\x0D') || (*p=='\x0A'))
          p++;   
        Etat = 5;
        break;

      case 5: // --- End of line
        Parse->Len[Parse->NbLine] = Len;
        if (Len>Parse->MaxLen) 
          Parse->MaxLen = Len;
        
        if ((*p=='\0')||(Parse->NbLine==CI_PARSE_NBLINE-1)) 
          Etat = 0;
        else
          {
          Parse->NbLine++;
          Etat = 2;
          }
        break;
      }
    }
    
  Parse->NbLine++; // Now, NbLine is not an index, but a length
  
  MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"fin"));
  }

// ****************************************************************************
// * zzzgetch
// ****************************************************************************
int zzzgetch()
{
  int c;
  while(1) 
    {
    if ((c = mimo_getch()) != 256)
      return(c);
    else if(get_mimo_type() == _MIMO_MOVE)
      continue;
    else  return(256);
    }
  /* IJM 08-02-2002 was simply  return( mimo_getch() ); but now the mouse moves we get alot of move events */
}

// ****************************************************************************
/** MessageBox - main function used for displaying various message boxes

 * @param mptr        IN  message text
 * @param flags          IN

 * @return CE_OK

 * @author CCDoc Administrator
 
 */
// * VarGlob:
// ****************************************************************************
// ANF
static  int MessageBox( char * mptr, int flags )
{
MI_TRACE_DCL_TFN("MsgBox");
  WORD mimocolumn;
  WORD mimoline;
  int mimoparam;
  int mimoevent;
  int b;
  WORD bw;
  WORD ww;
  int c;
  int atcol;
  int atlin;
  int buttons=0;
  int butcol[6];
  int butval[6];
  char *  butmes[6];
  int bindex=0;
//  int oldmousemask = get_mimo_mask();
  int ret;
  TI_RECTANGLE Rect;
  WORD old_fg;
  WORD DisplayInNormalState; 
  int  bindexMemo;
  WORD      i;      // Fch:08-02-2002 Compute for 3 lines message
  TI_PARSE  Parse;

  flush_mimo();

  while (mimo_kbhit())
    mimo_getch();

  old_fg=TexGetFG();  
  for (b=0; b < 6; b++ ) {
      butmes[b] = 0;
      butcol[b] = butval[b] =0;
      }

  // Count the number of buttons to be displayed
  // -------------------------------------------
  if ( flags & MB_YES )    butval[buttons++]=IDYES;
  if ( flags & MB_NO )     butval[buttons++]=IDNO;
  if ( flags & MB_OK )     butval[buttons++]=IDOK;
  if ( flags & MB_CANCEL ) butval[buttons++]=IDCANCEL;
  if ( flags & MB_ABANDON) butval[buttons++]=IDABANDON;

  // Calculate button width required
  // -------------------------------
  bw = (buttons * 10);

  // Calculate real message length
  // -----------------------------
  ParseLine( mptr, screencols-4-5, &Parse);

  // Calculate window width and coordinates
  // --------------------------------------
  ww = (Parse.MaxLen < bw) ? buttons*10 : Parse.MaxLen+5 ;
  atcol= ((screencols-(ww+2))/2);
  atlin=((screenlins/2) - 4);

  MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"(%d,%d) ww=%d lines=%d",atcol,atlin,ww,Parse.NbLine));

  recapture_screen(mbox_bg); 

  // Draw the window (with empty title)
  // ----------------------------------
  SysHide();

  GuiWindowInternal( CI_WINSTA_FRAME_TITLE, atcol, atlin , ww+4, 8, 15,7, " ", 1, 0);
  TexSetFG(CI_COL_BLACK);

  for( i=0 ; i<Parse.NbLine ; i++)
    {
    MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"Len=%d",Parse.Len[i]));
    TexPrintXY(g_pApp->hFontFixeRef, atcol+1+4,atlin+1+i,Parse.Line[i], Parse.Len[i], 0);
    }
  
  DrawIcon(atcol+1,atlin+1,flags);  

  // Position curser to first button
  // -------------------------------
  if ( bw < ww )
    atcol += (((ww - bw)/2)+4);
  else  
    atcol += 3;

  atlin+=5;

  // Allow display of the four possible buttons
  // ------------------------------------------
  if ( flags & MB_YES ) {
    butcol[IDYES] = atcol;
    butmes[IDYES] = (*g_pLanguage==0) ? "Oui" : "Yes"; // Fch:08-02-2002 multilangue
    zButton_Internal(  CE_BUTTONLOOK_NORMAL, CE_BUTTONTYPE_BIG, butcol[IDYES], atlin,
                       CI_COL_CHOOSEN_BY_ZLOOK, butmes[IDYES], MB_WIDTH, butmes[IDYES]);
    atcol += 10;
    }

  if ( flags & MB_NO ) {
    butcol[IDNO] = atcol;
    butmes[IDNO] = (*g_pLanguage==0) ? "Non" : "No";  // Fch:08-02-2002 multilangue
    zButton_Internal(  CE_BUTTONLOOK_NORMAL, CE_BUTTONTYPE_BIG, butcol[IDNO], atlin,
                       CI_COL_CHOOSEN_BY_ZLOOK, butmes[IDNO], MB_WIDTH, butmes[IDNO]);
    atcol += 10;
    }

  if ( flags & MB_OK ) {
    butcol[IDOK] = atcol;
    butmes[IDOK] = "O.K";
    zButton_Internal(  CE_BUTTONLOOK_NORMAL, CE_BUTTONTYPE_BIG, butcol[IDOK], atlin,
                       CI_COL_CHOOSEN_BY_ZLOOK, butmes[IDOK], MB_WIDTH, butmes[IDOK]);
    atcol += 10;
    }

  if ( flags & MB_CANCEL ) {
    butcol[IDCANCEL] = atcol;
    butmes[IDCANCEL] = "Cancel";
    zButton_Internal(  CE_BUTTONLOOK_NORMAL, CE_BUTTONTYPE_BIG, butcol[IDCANCEL], atlin,
                       CI_COL_CHOOSEN_BY_ZLOOK, butmes[IDCANCEL], MB_WIDTH, butmes[IDCANCEL]);
    atcol += 10;
    }

  if ( flags & MB_ABANDON ) {
    butcol[IDABANDON] = atcol;
    butmes[IDABANDON] = "Abandon";
    zButton_Internal(  CE_BUTTONLOOK_NORMAL, CE_BUTTONTYPE_BIG, butcol[IDABANDON], atlin,
                       CI_COL_CHOOSEN_BY_ZLOOK, butmes[IDABANDON], MB_WIDTH, butmes[IDABANDON]);
    atcol += 10;
    }

	/* ---------------------------------------------- */
	/* IJM : 19/11/2004 				  */
	/* ---------------------------------------------- */
	/* This was SysShow but since screener gets lost  */
	/* it is necessary to force the display of dialog */
	/* message boxs otherwise user is blind !!!	  */
	/* ---------------------------------------------- */
	SysFlush();

  // Await keyboard entry of required type
  // -------------------------------------
  
  //FCH10032004 Il faut tester le flag pour mettre le focus sur le 2nd bouton
  if ( flags & MB_DEFBUTTON2 )
  	  bindex = 1;
  	  
  disable_mouse_move();

  while (1) 
    {
    SysHide();
    zButton_Internal(  CE_BUTTONLOOK_FOCUSED ,CE_BUTTONTYPE_BIG,
        butcol[butval[bindex]],atlin,
        CI_COL_CHOOSEN_BY_ZLOOK,
        butmes[butval[bindex]],MB_WIDTH,butmes[butval[bindex]]);
    SysShow();
    
    c = zzzgetch();
       
    DisplayInNormalState = FALSE; 
    bindexMemo = bindex;

    //while (  ((c = zzzgetch()) == 256)
    //      && ((mimoevent = get_mimo_type()) != _MIMO_UP)
    //      );  

    // ------------------------------------------------------
    // Mouse event management
    // if click inside a button, simulate a CR keyboard
    // else loop
    // ------------------------------------------------------
    if (c==256)
      {
      mimoevent = get_mimo_type();

      // FCH-IJM19102001 on ne traite que les evt bouton relâché, 
      // les autres evt sont ignorés 
      //if (mimoevent != _MIMO_UP)
      //    continue;

      mimoparam = get_mimo_par();
      mimoline  = get_mimo_lin();
      mimocolumn= get_mimo_col();

      for ( b=0; b < buttons; b++) 
        {
        GuiGetButtonRectangle( &Rect, butcol[butval[b]], atlin, MB_WIDTH, CE_BUTTONTYPE_BIG);  
        
        if (  (mimoline   >= Rect.y1) && (mimoline   <= Rect.y2)
           && (mimocolumn >= Rect.x1) && (mimocolumn <= Rect.x2)
           )
          {
          bindex = b;
          //if ( mimoparam != 2 ) FC22052003 test évitant des remontées parasites
          if ( mimoparam == 1 ) 
            c = CI_KEY_CR;
          break;
          }
        }

      if (c!=CI_KEY_CR)
        continue;
      }

    // ------------------------------------------------------
    // Move focus by keyboard
    // ------------------------------------------------------
    switch ( c ) 
      {
      case  CI_KEY_HOME:
        bindex = 0;
        DisplayInNormalState = TRUE; 
        break;

      case  CI_KEY_END:
        DisplayInNormalState = TRUE; 
        bindex = buttons-1;
        break;

      case  CI_KEY_TAB:
      case  CI_KEY_RIGHT:
      case  CI_KEY_PGDOWN:
      case  CI_KEY_DOWN:
      case  ' ':
        bindex++;
        if ( bindex >= buttons )
          bindex = 0;
        DisplayInNormalState = TRUE; 
        break;

      case  CI_KEY_SHTAB:
      case  CI_KEY_LEFT:
      case  CI_KEY_PGUP:
      case  CI_KEY_UP:
        if (!( bindex  ))
          bindex = buttons;
        bindex--;
        DisplayInNormalState = TRUE; 
        break;

      case  CI_KEY_CR  :
        c = *( butmes[butval[bindex]] );
        break;

      case  CI_KEY_ESC :
        if ( flags & MB_CANCEL )
          c = 'C';
        else if ( flags & MB_ABANDON )
          c = 'A';
        else if ( flags & MB_OK )
          c = 'O';
        break;
      }

    if (DisplayInNormalState) 
      {
      SysHide();
      zButton_Internal(  CE_BUTTONLOOK_NORMAL,CE_BUTTONTYPE_BIG,
          butcol[butval[bindexMemo]],atlin,
          CI_COL_CHOOSEN_BY_ZLOOK,
          butmes[butval[bindexMemo]],MB_WIDTH,butmes[butval[bindexMemo]]);
      SysShow();
      continue;  
      }

    // ------------------------------------------------------
    // A button is pressed
    // ------------------------------------------------------
    switch ( c ) {
      case  'Y' :
      case  'y' :
        if ( ( flags & MB_YES ) && (*g_pLanguage==1) )  // Fch:08-02-2002 multilangue
          {
          SysHide();
          zButton_Internal(CE_BUTTONLOOK_CLICK,CE_BUTTONTYPE_BIG,butcol[IDYES],atlin,CI_COL_CHOOSEN_BY_ZLOOK," ",MB_WIDTH," ");
          SysShow();
          ret = IDYES;
          break;
          }
        else  continue;
      case  'N' :
      case  'n' :
        if ( flags & MB_NO ) 
          {
          SysHide();
          zButton_Internal(CE_BUTTONLOOK_CLICK,CE_BUTTONTYPE_BIG,butcol[IDNO],atlin,CI_COL_CHOOSEN_BY_ZLOOK," ",MB_WIDTH," ");
          SysShow();
          ret = IDNO;
          break;
          }
        else  continue;
      case  'O' :
      case  'o' :
        if ( flags & MB_OK ) 
          {
          SysHide();
          zButton_Internal(CE_BUTTONLOOK_CLICK,CE_BUTTONTYPE_BIG,butcol[IDOK],atlin,CI_COL_CHOOSEN_BY_ZLOOK," ",MB_WIDTH," ");
          SysShow();
          ret = IDOK;
          break;
          }
        else if ( ( flags & MB_YES ) && (*g_pLanguage==0) )  // Fch:08-02-2002 multilangue 
          {
          SysHide();
          zButton_Internal(CE_BUTTONLOOK_CLICK,CE_BUTTONTYPE_BIG,butcol[IDYES],atlin,CI_COL_CHOOSEN_BY_ZLOOK," ",MB_WIDTH," ");
          SysShow();
          ret = IDYES;
          break;
          }
        else  continue;
      case  'C' :
      case  'c' :
        if ( flags & MB_CANCEL ) 
          {
          SysHide();
          zButton_Internal(CE_BUTTONLOOK_CLICK,CE_BUTTONTYPE_BIG,butcol[IDCANCEL],atlin,CI_COL_CHOOSEN_BY_ZLOOK," ",MB_WIDTH," ");
          SysShow();
          ret = IDCANCEL;
          break;
          }
        else  continue;
      case  'A' :
      case  'a' :
        if ( flags & MB_ABANDON ) 
          {
          SysHide();
          zButton_Internal(CE_BUTTONLOOK_CLICK,CE_BUTTONTYPE_BIG,butcol[IDABANDON],atlin,CI_COL_CHOOSEN_BY_ZLOOK," ",MB_WIDTH," ");
          SysShow();
          ret = IDOK;
          break;
          }
        else  continue;
      default   :
        continue;
      }
    break;
    }
  enable_mouse_move();

refresh_screen(mbox_bg);
// old version: zSysPop_Internal();
//set_mimo_mask( oldmousemask ); 
//flush_mimo();
TexSetFG(old_fg);
return ret;
}


// ****************************************************************************
/** BdaGui_zMesErr - (THO name) zmesserr - ABAL API - (Windows only)
  * Message box for error messages

 * @param message     IN
 * @param lg          IN

 * @return CE_OK

 * @author ANF
 
 */
// * VarGlob:
// ****************************************************************************
WORD BDA_WINAPI BdaGui_zMesErr(PTRC message,WORD lg)
{
MI_TRACE_DCL_TFN("MesErr");

MI_TRACE_BEGIN();
  lg = copymessage( message,lg );
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"lg=%d",lg));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"'%s'",MessageBuffer));
 
  MessageBox(MessageBuffer,MB_OK|MB_ICONEXCLAMATION);

MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaGui_zMesYesNo: (THO name) zmesyesno - ABAL API - (Windows only)
    Message box for Yes/No response

 * @param message     IN
 * @param lg          IN
 * @param actif       IN

 * @return 0=Yes, 1=No
 * @author ANF
 
 */
// * VarGlob:
// ****************************************************************************
WORD BDA_WINAPI BdaGui_zMesYesNo(PTRC message,WORD lg,WORD actif)
{
MI_TRACE_DCL_TFN("MesYN");
SWORD rep;

MI_TRACE_BEGIN();

  lg = copymessage( message,lg );
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"lg=%d",lg));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"'%s'",MessageBuffer));

  switch (actif) {
    case 1 :
      rep=MessageBox( MessageBuffer,
        MB_YESNO|MB_ICONQUESTION);
      break;
    case 2 :
      rep=MessageBox( MessageBuffer,
        MB_YESNO|MB_ICONQUESTION|MB_DEFBUTTON2);
      break;
    case 3 :
      rep=MessageBox( MessageBuffer,
        MB_OKCANCEL|MB_ICONQUESTION);
      break;
    case 4 :
      rep=MessageBox( MessageBuffer,
        MB_OKABANDON|MB_ICONQUESTION);
      break;
    }
  // Reinit_Mouse();
  if (rep == IDYES || rep == IDOK)
    MI_TRACE_RETURN(0);
  else  
    MI_TRACE_RETURN(1);
}

// ****************************************************************************
/** BdaGui_zMesYesNoCancel: (THO name) zmesync - ABAL API - (Windows only)
    Message box for Yes/No/Cancel response

 * @param message     IN
 * @param lg          IN

// * Return:
 * @param 0=Yes, 1=Cancel, 2=No

 * @author CCDoc Administrator
 
 */
// * VarGlob:
// ****************************************************************************
WORD BDA_WINAPI BdaGui_zMesYesNoCancel(PTRC message,WORD lg)
{
MI_TRACE_DCL_TFN("MesYNC");
SWORD rep;

MI_TRACE_BEGIN();

  lg = copymessage( message,lg );
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"lg=%d",lg));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"'%s'",MessageBuffer));

  rep=MessageBox(MessageBuffer,MB_YESNOCANCEL|MB_ICONQUESTION);
  switch (rep) {
    case IDYES :
      rep=0;
      break;
    case IDNO :
      rep=2;
      break;
    case IDCANCEL :
      rep=1;
      break;
    }
  // Reinit_Mouse();

MI_TRACE_RETURN(rep);
}

// ****************************************************************************
/** BdaGui_zMesVal: (THO name) zmesval - ABAL API - (Windows only)
    Message box for message and value

 * @param message     IN
 * @param lg          IN

 * @return CE_OK
 * @author ANF
 
 */

// * VarGlob:
// ****************************************************************************
WORD BDA_WINAPI BdaGui_zMesVal(PTRC message,WORD lg)
{
MI_TRACE_DCL_TFN("MesVal");

MI_TRACE_BEGIN();
  lg = copymessage( message,lg );
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"lg=%d",lg));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"'%s'",MessageBuffer));

  MessageBox(MessageBuffer,MB_OK|MB_ICONASTERISK);

MI_TRACE_RETURN(CE_OK);
}
