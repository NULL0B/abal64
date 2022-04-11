/** @pkg Staff.Fred.zGuiBut */ 
// ****************************************************************************
// * zButton.c
// * Included in GUI module
// * Button controls functionnalities
// ****************************************************************************


// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// - Basic internal Functions
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

const int BUTTON_SHIFT=2;

VOID    GuiTabviewFrame(int atcol,int atlin,int nbcol,int nblin) 
{
PTI_COMP_BUTTON_DESCR pButton = &g_pLook->Button;
int gratcol,gratlin;
int grnbcol,grnblin;

  gratcol = (atcol-1) * cellwidth;
  gratlin = (atlin-1) * cellheight;
  grnbcol = nbcol * cellwidth;
  grnblin = nblin * cellheight;

  if ( pButton->SkinTabviewFrame.Ptr == NULL)
    {
    // Tabview needs special handling to leave room for the tabs
    grnbcol -= (cellwidth-1);
    gratlin += (cellheight-1);
    grnblin -= (cellheight-1);
    
    LookRelief( gratcol, gratlin, grnbcol, grnblin, pButton->ColorReliefUp  , CI_COL_TRANSPARENT, pButton->ColorReliefDown);
    }
  else  
    LookApplySkin( gratcol, gratlin, grnbcol, grnblin, pButton->SkinTabviewFrame.Ptr, CI_SKNF_9ZONES_NOCENTER );

}

VOID GuiButtonTabviewFrame(int x, int y, int cx, int cy, WORD ColBG, WORD State, WORD IsHTabview, WORD SkinFlag) 
{
PTI_COMP_BUTTON_DESCR pButton = &g_pLook->Button;
PTI_MEMORY            pSkin;
int grx,gry;
int grcx,grcy;

  // Oulesiamism on coordinates:
  // in text mode, we see x begins x-1 and cx begins cx+2 to display a frame
  // To have the same size, I do the same...
  grx = (x-2)*cellwidth;
  gry = (y-1)*cellheight;
  grcx= (cx+2)*cellwidth;
  grcy= cy*cellheight;

  if (State==CE_TABVIEWLOOK_HIDDEN)
    {
    filzone( grx,gry,grcx,grcy,ColBG);
    return;
    }

  pSkin = (IsHTabview) ? &pButton->SkinHTabview : &pButton->SkinVTabview;

  if ( pSkin->Ptr == NULL)
    {
    if (IsHTabview)
      {
      filzone( grx+1     , gry+1     , grcx-2, grcy-2, ColBG);                     // center
      filzone( grx       , gry       , grcx  , 1     , pButton->ColorReliefUp);    // top
      filzone( grx       , gry       , 1     , grcy  , pButton->ColorReliefUp);    // left
      filzone( grx+grcx-1, gry       , 1     , grcy  , pButton->ColorReliefDown);  // right
      
      if      (State==CE_TABVIEWLOOK_BACK)
        filzone( grx     , gry+grcy-1, grcx  , 1     , pButton->ColorReliefUp);    // bottom
      else if (State==CE_TABVIEWLOOK_FRONT)  
        filzone( grx     , gry+grcy-1, grcx  , 1     , ColBG);                     // bottom
      }
    else
      {
      filzone( grx+1     , gry+1     , grcx-2, grcy-2, ColBG);                     // center
      filzone( grx       , gry       , grcx  , 1     , pButton->ColorReliefUp);    // top
      filzone( grx       , gry+grcy-1, grcx  , 1     , pButton->ColorReliefDown);  // bottom
      filzone( grx+grcx-1, gry       , 1     , grcy  , pButton->ColorReliefDown);  // right

      if      (State==CE_TABVIEWLOOK_BACK)
        filzone( grx     , gry     , 1     , grcy  , pButton->ColorReliefDown);   // left
      else if (State==CE_TABVIEWLOOK_FRONT)  
        filzone( grx     , gry     , 1     , grcy  , ColBG);                      // left
      }
    }
  else  
    LookApplySkin( grx, gry, grcx, grcy, pSkin->Ptr, SkinFlag );
}

VOID GuiSmallButtonFrame(int x, int y, int cx, int cy, WORD ColBG, WORD State, WORD SkinFlag) 
{
PTI_COMP_BUTTON_DESCR pButton = &g_pLook->Button;
int grx,gry;
int grcx,grcy;

  // Oulesiamism on coordinates:
  // in text mode, we see x begins x-1 and cx begins cx+2 to display a frame
  // To have the same size, I do the same...
  grx = (x-2)*cellwidth;
  gry = (y-1)*cellheight;
  grcx= (cx+2)*cellwidth;
  grcy= cy*cellheight;
  if (State==CE_BUTTONLOOK_HIDDEN)
    {
    filzone( grx,gry,grcx,grcy,ColBG);
    return;
    }

  if ( pButton->SkinSmall.Ptr == NULL)
    {
    grx  += (cellwidth/2);
    grcx -= (cellwidth);

    if (State==CE_BUTTONLOOK_PUSHED)
      LookRelief( grx, gry, grcx, grcy, pButton->ColorReliefDown, ColBG, pButton->ColorReliefUp );
    else
      LookRelief( grx, gry, grcx, grcy, pButton->ColorReliefUp, ColBG, pButton->ColorReliefDown );
    }
  else  
    LookApplySkin( grx, gry, grcx, grcy, pButton->SkinSmall.Ptr, SkinFlag );
}

VOID  GuiGetButtonRectangle( PTI_RECTANGLE pRect, WORD x, WORD y, WORD cx, WORD Type )
{
pRect->x1 = x-1;
pRect->y1 = (Type==CE_BUTTONTYPE_MIDDLE) ? y-1 : y-Type/2 ;
pRect->x2 = x+cx+1;
pRect->y2 = (Type==CE_BUTTONTYPE_MIDDLE) ? y : y+Type/2;
}

VOID GuiGetGrButtonRectangle( PTI_RECTANGLE pRect, WORD x, WORD y, WORD cx, WORD Type ){
    switch(Type){
        case CE_BUTTONTYPE_SMALL:  
            pRect->x1 = (x-2)*cellwidth;
            pRect->y1 = (y-1)*cellheight;
            pRect->x2=pRect->x1+(cx+2)*cellwidth;
            pRect->y2=pRect->y1+cellheight;
        break;

        case CE_BUTTONTYPE_MIDDLE:  
            pRect->x1 = (x-2)*cellwidth + cellwidth/2;         
            pRect->y1 = (y-2)*cellheight;                      
            pRect->x2=pRect->x1+(cx+2)*cellwidth - cellwidth;          
            pRect->y2=pRect->y1+ 2*cellheight;
        break;
        case CE_BUTTONTYPE_BIG:
            pRect->x1 = (x-2)*cellwidth;
            pRect->x2= pRect->x1+(cx+2)*cellwidth;
            pRect->y1=(y-2)*cellheight+cellheight/2;
            pRect->y2=pRect->y1+2*cellheight;
        break;    
        default:
            pRect->x1 = (x-2)*cellwidth;
            pRect->y1 = (y-1-Type/2)*cellheight;
            pRect->x2= pRect->x1+(cx+2)*cellwidth;
            pRect->y2=pRect->y1+(Type+1)*cellheight;
            pRect->y1+=cellheight/2;
            pRect->y2-=cellheight/2;
        break;    
    }  
    pRect->x1+=BUTTON_SHIFT;
    pRect->y1+=BUTTON_SHIFT;
    pRect->x2-=BUTTON_SHIFT;
    pRect->y2-=BUTTON_SHIFT;
}

VOID  GuiInternalButtonFrame( WORD x, WORD y, WORD cx, WORD Type, WORD ColBG, WORD State, PTI_MEMORY pSkin )
{
PTI_COMP_BUTTON_DESCR pButton = &g_pLook->Button;
WORD grx,gry;
WORD grcx,grcy;

  if (State==CE_BUTTONLOOK_HIDDEN)
    {
    if (Type==CE_BUTTONTYPE_MIDDLE)  
      {
      grx = (x-2)*cellwidth;
      gry = (y-2)*cellheight;
      grcx= (cx+2)*cellwidth;
      grcy= 2*cellheight;
      }
    else
      {
      grx = (x-2)*cellwidth;
      gry = (y-1-Type/2)*cellheight;
      grcx= (cx+2)*cellwidth;
      grcy= (Type+1)*cellheight;
      }
    filzone( grx,gry,grcx,grcy,ColBG);
    return;
    }

  if ( pSkin->Ptr == NULL)
    {
    if (Type==CE_BUTTONTYPE_MIDDLE)  
      {
      grx = (x-2)*cellwidth + cellwidth/2;
      gry = (y-2)*cellheight;
      grcx= (cx+2)*cellwidth - cellwidth;
      grcy= 2*cellheight;
      }
    else
      {
      grx = (x-2)*cellwidth         + cellwidth/2;
      gry = (y-1-Type/2)*cellheight + cellheight/2;
      grcx= (cx+2)*cellwidth        - cellwidth;
      grcy= (Type+1)*cellheight     - cellheight;
      }

    if (State==CE_BUTTONLOOK_PUSHED)
      LookRelief( grx, gry, grcx, grcy, pButton->ColorReliefDown  , ColBG, pButton->ColorReliefUp);
    else
      LookRelief( grx, gry, grcx, grcy, pButton->ColorReliefUp  , ColBG, pButton->ColorReliefDown);
    }
  else
    {
    if (Type==CE_BUTTONTYPE_MIDDLE)  
      {
      grx = (x-2)*cellwidth;
      gry = (y-2)*cellheight;
      grcx= (cx+2)*cellwidth;
      grcy= 2*cellheight;
      LookApplySkin( grx, gry, grcx, grcy, pSkin->Ptr, CI_SKNF_3ZONES | CI_SKNF_3ZONES_BOTTOM );
      }
    else
      {
      grx = (x-2)*cellwidth;
      gry = (y-1-Type/2)*cellheight;
      grcx= (cx+2)*cellwidth;
      grcy= (Type+1)*cellheight;
      LookApplySkin( grx, gry, grcx, grcy, pSkin->Ptr, CI_SKNF_9ZONES );
      }
    }
}

VOID  GuiButtonFrame( WORD x, WORD y, WORD cx, WORD cy)
{
PTI_COMP_BUTTON_DESCR pButton = &g_pLook->Button;
WORD grx,gry;
WORD grcx,grcy;

  if ( pButton->SkinButNormal.Ptr == NULL)
    {
    grx = (x-1)*cellwidth  + cellwidth/2;
    gry = (y-1)*cellheight + cellheight/2;
    grcx= cx*cellwidth     - cellwidth;
    grcy= cy*cellheight    - cellheight;
    LookRelief( grx, gry, grcx, grcy, pButton->ColorReliefUp  , CI_COL_TRANSPARENT, pButton->ColorReliefDown);
    }
  else
    {
    grx = (x-1)*cellwidth;
    gry = (y-1)*cellheight;
    grcx= cx*cellwidth;
    grcy= cy*cellheight;
    LookApplySkin( grx, gry, grcx, grcy, pButton->SkinButNormal.Ptr, CI_SKNF_9ZONES_NOCENTER );
    }
}


// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// - Internal functions
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------



// ****************************************************************************
/** zButton_Internal: internal function, called from BdaGui_zButton
  to avoid direct API function call

 * @author ANF
 
 */
// * VarGlob:
// ****************************************************************************
void zButton_Internal(WORD State,WORD t,WORD x,WORD y,WORD c,char FAR * text,WORD lg,char FAR * cle)
{
MI_TRACE_DCL_TFN("IntBut");
PTI_COMP_BUTTON_DESCR pButton = &g_pLook->Button;
WORD  ColFG;
WORD  ColBG;
PTI_MEMORY  pSkin;
WORD  OldColors;
WORD  xLib;
WORD  LgLib;
char  lib[32];
WORD  i;
WORD  save_t;
WORD image_lenght=0;
TI_RECTANGLE but_coo;

  // -------------------------------------------------------------------
  // - Init
  // -------------------------------------------------------------------

  // --- Text initialisation -------------
  //     truncation of original text
  //     copy in 'lib' with blank padding and removing oulesian characters

  // Trunc 
  if ( lg>31) 
    lg = 31;

  // Copy 'text' parameter in 'lib', removing oulesian characters 
  for (i=0; i < lg; i++ ) 
    {
    if (!(lib[i] = text[i]))
      break;

    if ((text[i]=='\xFF') || (text[i]=='\xFE')) 
      lib[i] = ' ';
    } 

  // Text coordinates for 'lib'
  LgLib = i;
  xLib  = x + (lg-LgLib)/2;

  // Padding with blank
  while ( i < lg )
    lib[i++] = ' ';

  lib[lg]=0;

  // --- Look identification
  switch(State)
    {
    case CE_BUTTONLOOK_NORMAL:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Normal"));
      ColFG = (c==CI_COL_CHOOSEN_BY_ZLOOK) ? pButton->ColorFGButNormal : c ;
      ColBG = pButton->ColorBGButNormal;
      pSkin = (t==0) ? &pButton->SkinBut2Normal : &pButton->SkinButNormal;
      break;

    case CE_BUTTONLOOK_FOCUSED:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Selected"));
      ColFG = (c==CI_COL_CHOOSEN_BY_ZLOOK) ? pButton->ColorFGButSelected : c ;
      ColBG = pButton->ColorBGButSelected;
      pSkin = (t==0) ? &pButton->SkinBut2Selected : &pButton->SkinButSelected;
      break;

    case CE_BUTTONLOOK_PUSHED:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Pushed"));
      ColFG = (c==CI_COL_CHOOSEN_BY_ZLOOK) ? pButton->ColorFGButNormal : c ;
      ColBG = pButton->ColorBGButNormal;
      pSkin = (t==0) ? &pButton->SkinBut2Pushed : &pButton->SkinButPushed;
      break;

    case CE_BUTTONLOOK_GRAYED:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Disabled"));
      ColFG = pButton->ColorFGButDisabled;
      ColBG = pButton->ColorBGButDisabled;
      pSkin = (t==0) ? &pButton->SkinBut2Disabled : &pButton->SkinButDisabled;
      break;

    case CE_BUTTONLOOK_HIDDEN:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Hidden"));
      ColBG = pButton->ColorBGHidden;
      break;
    }

  // -------------------------------------------------------------------
  // - Compute
  // -------------------------------------------------------------------
  SysHide();


  if (State==CE_BUTTONLOOK_CLICK)
    {
    // Special process for our internal message boxes
    OldColors = TexSetFGBG(c,CI_COL_TRANSPARENT);
    GuiInternalButtonFrame( x, y, lg, t, CI_COL_TRANSPARENT, CE_BUTTONLOOK_PUSHED, &pButton->SkinButPushed );
    SysWait(2);
    GuiInternalButtonFrame( x, y, lg, t, CI_COL_TRANSPARENT, CE_BUTTONLOOK_NORMAL, &pButton->SkinButNormal );
    SysWait(2);
    }
  else
    {
    OldColors = TexSetFGBG(ColFG,CI_COL_TRANSPARENT);
    GuiInternalButtonFrame( x, y, lg, t, ColBG, State, pSkin );

    if (State!=CE_BUTTONLOOK_HIDDEN)
      {
      save_t=t; 
      switch(t)
        {
        case  CE_BUTTONTYPE_BIG   : 
                save_t=3; 
        break;
        case  CE_BUTTONTYPE_MIDDLE: save_t=2; break;
        } 
     // to draw text & image simultaneously       
     // image_lenght=DrawAssociatedImage(&but_coo,text,save_t,lg);
     // if(image_lenght!=0)
     //   {
     //   for(i=0;i<LgLib;i++)
     //     {
     //     if(lib[i]!='_') break;
     //     LgLib--;
     //     }
     //   if(i>=image_lenght)
     //     TexPrintButtonCaption(pButton->hFont, xLib+i, y, &lib[i], LgLib, cle, ColFG, (t==CE_BUTTONTYPE_MIDDLE), (State==CE_BUTTONLOOK_PUSHED) );
     //   }
     // else*/
        GuiGetGrButtonRectangle(&but_coo,x,y,lg,t);
        image_lenght=DrawAssociatedImage(&but_coo,lib,save_t,LgLib);//text,save_t,lg);
        if(!image_lenght)
        TexPrintButtonCaption(pButton->hFont, xLib, y, lib, LgLib, cle, ColFG, (t==CE_BUTTONTYPE_MIDDLE), (State==CE_BUTTONLOOK_PUSHED) );
      }
    }
  SysShow();

  // -------------------------------------------------------------------
  // - Restore
  // -------------------------------------------------------------------
  TexSetFGBG(HIBYTE(OldColors),LOBYTE(OldColors));

}


// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// - BDA APIs
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------



// ****************************************************************************
/** BdaGui_zButton: (THO name) zbutton - ABAL API
    Displays a big button

 * @param State     IN : CE_BUTTONLOOK_xxx values
 * @param t         IN : Size
 * @param x         IN : Coordinate
 * @param y         IN : Coordinate
 * @param c         IN : Color
 * @param text      IN : Title of button
 * @param lg        IN : Size of text
 * @param cle       IN : ?

 * @return CE_OK

 * @author ANF
 
 */
// * VarGlob:
// ****************************************************************************
EXAWORD BDA_API BdaGui_zButton(WORD State,WORD t,WORD x,WORD y,WORD c,char FAR * text,WORD lg,char FAR * cle)
{
MI_TRACE_DCL_TFN("But");

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"state=%d at (%d,%d)",State,x,y));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"type=%d"   ,t));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"color=%d"  ,c));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"lg=%d"     ,lg));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"text='%s'" ,MI_TRA_TRUNCLG(text,lg)));
  SetChangeFlag();    
  zButton_Internal( State, t, x, y, c, text, lg, cle);

MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaGui_zSmallButton: (THO name) zsmallbutton - ABAL API
    Displays a small button

 * @param State     IN : CE_BUTTONLOOK_xxx values
 * @param t         IN : Size
 * @param x         IN : Coordinate
 * @param y         IN : Coordinate
 * @param c         IN : Color
 * @param text      IN : Title of button
 * @param lg        IN : Size of text
 * @param cle       IN : ?

 * @return CE_OK
 
 * @author ANF
 
 */
// * VarGlob:
// ****************************************************************************
EXAWORD BDA_API BdaGui_zSmallButton(WORD State,WORD x,WORD y,WORD c,char FAR * text,WORD lg,char FAR * cle)
{
MI_TRACE_DCL_TFN("SmlBut");
PTI_COMP_BUTTON_DESCR pButton = &g_pLook->Button;
WORD  ColFG;
WORD  ColBG;
WORD  SkinFlag;
WORD  OldColors;
WORD  xLib;
WORD  LgLib;
char  lib[32];
WORD i;
TI_RECTANGLE but_coo;

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"state=%d at (%d,%d)",State,x,y));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"color=%d"  ,c));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"lg=%d"     ,lg));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"text='%s'" ,MI_TRA_TRUNCLG(text,lg)));

  SetChangeFlag();    

  // -------------------------------------------------------------------
  // - Init
  // -------------------------------------------------------------------

  // --- Initialisations -----------------
  //     truncation of original text
  //     copy in 'lib' with blank padding
  // -------------------------------------

  // Trunc 
  if ( lg>31) 
    lg = 31;

  // Copy 'text' parameter in 'lib', removing oulesian characters 
  for (i=0; i < lg; i++ )
    {
    if (!(lib[i] = text[i]))
      break;
    }

  // Text coordinates for 'lib'
  LgLib = i;
  xLib  = x + (lg-LgLib)/2;

  // Padding with blank
  while ( i < lg )
    lib[i++] = ' ';

  lib[lg]=0;

  // --- Look identification
  switch(State)
    {
    case CE_BUTTONLOOK_NORMAL:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Normal"));
      ColFG         = c;
      ColBG         = pButton->ColorBGButNormal;
      SkinFlag = CI_SKNF_3ZONES;
      break;

    case CE_BUTTONLOOK_FOCUSED:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Selected"));
      ColFG         = c;
      ColBG         = pButton->ColorBGButSelected;
      SkinFlag = CI_SKNF_3ZONES_MIDDLE;
      break;

    case CE_BUTTONLOOK_PUSHED:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Pushed"));
      ColFG         = c;
      ColBG         = pButton->ColorBGButNormal;
      SkinFlag = CI_SKNF_3ZONES_EXT;
      break;

    case CE_BUTTONLOOK_GRAYED:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Disabled"));
      ColFG         = pButton->ColorFGButDisabled;
      ColBG         = pButton->ColorBGButDisabled;
      SkinFlag = CI_SKNF_3ZONES_BOTTOM;
      break;

    case CE_BUTTONLOOK_HIDDEN:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Hidden"));
      ColBG = pButton->ColorBGHidden;
      break;
    }

  // -------------------------------------------------------------------
  // - Compute
  // -------------------------------------------------------------------
  SysHide();

  OldColors = TexSetFGBG(ColFG,CI_COL_TRANSPARENT);
  GuiSmallButtonFrame( x, y, lg, 1, ColBG, State, SkinFlag); 

  if (State!=CE_BUTTONLOOK_HIDDEN) 
    {
    GuiGetGrButtonRectangle(&but_coo,x,y,lg,CE_BUTTONTYPE_SMALL);
    if(!DrawAssociatedImage(&but_coo,lib,1,LgLib))
      TexPrintButtonCaption( pButton->hFontSmall, xLib, y, lib, LgLib, cle, ColFG, FALSE, (State==CE_BUTTONLOOK_PUSHED) );
    }

  SysShow();

  // -------------------------------------------------------------------
  // - Restore
  // -------------------------------------------------------------------
  TexSetFGBG(HIBYTE(OldColors),LOBYTE(OldColors));

MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaGui_zTabview: (THO name) ztabview - ABAL API
    Displays a small button

 * @param State     IN : CE_TABVIEWLOOK_xxx values
 * @param verti     IN : ? - NOT USED
 * @param x         IN : Coordinate
 * @param y         IN : Coordinate
 * @param c         IN : Color
 * @param text      IN : Title of button
 * @param lg        IN : Size of text
 * @param cle       IN : ?

 * @return CE_OK

 * @author ANF
 
 */
// * VarGlob:
// ****************************************************************************
EXAWORD BDA_API BdaGui_zTabview(WORD State,WORD verti,WORD x,WORD y,WORD c,char FAR * text,WORD lg,char FAR * cle)
{
MI_TRACE_DCL_TFN("Tabview");
PTI_COMP_BUTTON_DESCR pButton = &g_pLook->Button;
WORD  ColFG;
WORD  ColBG;
WORD  SkinFlag;
WORD  OldColors;
TI_RECTANGLE but_coo;

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"state=%d at (%d,%d)",State,x,y));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"verti=%d"  ,verti));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"color=%d"  ,c));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"lg=%d"     ,lg));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"text='%s'" ,MI_TRA_TRUNCLG(text,lg)));

  SetChangeFlag();    

  // -------------------------------------------------------------------
  // - Init
  // -------------------------------------------------------------------

  // --- Look identification
  switch(State)
    {
    case CE_TABVIEWLOOK_BACK:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Back"));
      ColFG         = pButton->ColorFGTabBack;
      ColBG         = pButton->ColorBGTabBack;
      SkinFlag = CI_SKNF_3ZONES;
      break;

    case CE_TABVIEWLOOK_FOCUSED:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Selected"));
      ColFG         = pButton->ColorFGTabSelected;
      ColBG         = pButton->ColorBGTabSelected;
      SkinFlag = CI_SKNF_3ZONES_MIDDLE;
      break;

    case CE_TABVIEWLOOK_GRAYED:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Disabled"));
      ColFG         = pButton->ColorFGTabDisabled;
      ColBG         = pButton->ColorBGTabDisabled;
      SkinFlag = CI_SKNF_3ZONES_BOTTOM;
      break;

    case CE_TABVIEWLOOK_FRONT:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Front"));
      ColFG         = pButton->ColorFGTabFront;
      ColBG         = pButton->ColorBGTabFront;
      SkinFlag = CI_SKNF_3ZONES_EXT;
      break;

    case CE_TABVIEWLOOK_HIDDEN:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Hidden"));
      ColBG = pButton->ColorBGHidden;
      break;
    }

  // -------------------------------------------------------------------
  // - Compute
  // -------------------------------------------------------------------
  SysHide();

  OldColors = TexSetFGBG(ColFG,CI_COL_TRANSPARENT);
  GuiButtonTabviewFrame(x,y,lg,1, ColBG, State, verti, SkinFlag) ;

  if (State!=CE_BUTTONLOOK_HIDDEN) 
    {
    GuiGetGrButtonRectangle(&but_coo,x,y,lg,CE_BUTTONTYPE_SMALL);
    if(!DrawAssociatedImage(&but_coo,text,CE_BUTTONTYPE_SMALL,lg))
      TexPrintButtonCaption( pButton->hFontSmall, x, y, text, lg, cle, ColFG, FALSE, (State==CE_TABVIEWLOOK_BACK));
    }

   SysShow();

  // -------------------------------------------------------------------
  // - Restore
  // -------------------------------------------------------------------
  TexSetFGBG(HIBYTE(OldColors),LOBYTE(OldColors));

MI_TRACE_RETURN(CE_OK);
}


