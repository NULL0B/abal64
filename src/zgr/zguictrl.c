/** @pkg Staff.Fred.zGuiCtrl */ 

// ****************************************************************************
// * zControl.c
// * Included in GUI module
// * Fields for Controls combobox, variator, radio, check functionnalities
// ****************************************************************************

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// - Basic internal Functions
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------


// ****************************************************************************
/** draw_arrow
    Internal function, used by BdaGui_zF1Button

 * @param focus     IN : CE_FIELDLOOK_xxx values
 * @param x         IN : Coordinate
 * @param y         IN : Coordinate

 * @return CE_OK

 * @author ANF
 
 */
// * VarGlob:
// ****************************************************************************
static  void  draw_arrow( 
  int arrow,
  int gratcol,int gratlin,
  int grnbcol,int grnblin,
  int colour )
{
  int i;
  int j;
  int l;
  int k;
  switch ( arrow ) {
    case  _ARROW_HOME :
      for (j = (grnbcol/2),l=(grnblin/4),
           i = (grnbcol/4);
           j > 0;
           j--, l++ )
        filzone(gratcol+i,gratlin+l,
          j,1, colour);
      break;  
    case  _ARROW_PAGE_UP :
      for ( l=(grnblin/2), j=1, i=(grnbcol/2), k =(grnbcol/4);
        i > k;
        i--, j+=2, l++ )
        filzone(gratcol+i,gratlin+l,
          j,1, colour);
    case  _ARROW_LINE_UP :
      for ( l=(grnblin/4), j=1, i=(grnbcol/2), k =(grnbcol/4);
        i > k;
        i--, j+=2, l++ )
        filzone(gratcol+i,gratlin+l,
          j,1, colour);
      break;

    case  _ARROW_LEFT :
      for (   i=(grnbcol/4), l = (grnblin/2),
        k=(grnblin/4), j = 1;
        l > k;
        l--, j+=2, i++)
        filzone(gratcol+i,gratlin+l,
          1,j, colour);
      break;

    case  _ARROW_RIGHT :  /* right arrow  */
      for (   i=(grnbcol/2), l = (grnblin/4),
        j=(grnblin/2);
        j > 0;
        l++, j-=2, i++)
        filzone(gratcol+i,gratlin+l,
          1,j, colour);
      break;

    case  _ARROW_END :  /* end    */
      for (k = (grnbcol/2),l=(grnblin/2),
           i = (grnbcol/4), j=1;
           j < k;
           j++, l++ )
        filzone(gratcol+i,gratlin+l,
          j,1, colour);
      break;  
    case  _ARROW_PAGE_DOWN :  /* page down  */
      for (   l=(grnblin/4),  j=(grnbcol/2), 
        i = (grnbcol/4),k =(grnbcol/4);
        j > 0;
        i++, j-=2, l++ )
        filzone(gratcol+i,gratlin+l,
          j,1, colour);
    case  _ARROW_LINE_DOWN :  /* line down  */
      for (   l=(grnblin/2),  j=(grnbcol/2), 
        i = (grnbcol/4),k =(grnbcol/4);
        j > 0;
        i++, j-=2, l++ )
        filzone(gratcol+i,gratlin+l,
          j,1, colour);
      break;

    }
  return;
}

// ****************************************************************************
/** DrawVariator
    Internal function

 * @param 

 * @return CE_OK

 * @author FRC
 
 */
// * VarGlob:
// ****************************************************************************
void  DrawVariator( int atx,int aty,int nbx,int nby, WORD ColFG, WORD ColBG )
{
PTI_COMP_VAR_DESCR pVar = &g_pLook->Variator;

  SetChangeFlag();    

  LookRelief(atx,aty,nbx,nby,pVar->ColorReliefUp,ColBG,pVar->ColorReliefDown);
  draw_arrow(_ARROW_LINE_UP  , atx+1, aty, nbx-2, nby, ColFG);
  draw_arrow(_ARROW_LINE_DOWN, atx+1, aty, nbx-2, nby, ColFG);
}

// ****************************************************************************
/** DrawCheck
    Internal function

 * @param 

 * @return CE_OK

 * @author FRC
 
 */
// * VarGlob:
// ****************************************************************************
void  DrawCheck( int atx,int aty,int nbx,int nby, WORD ColFG, WORD ColBG, int HasFocus, int Actif )
{
PTI_COMP_CHECK_DESCR pCheck = &g_pLook->Check;

  SetChangeFlag();    

  LookRelief(atx,aty,nbx,nby,pCheck->ColorReliefUp,ColBG,pCheck->ColorReliefDown);
  if ((nby > 2) && ( nbx > 2 )) 
    {
    LookRelief(atx+1,aty+1,nbx-2,nby-2,pCheck->ColorReliefUp,CI_COL_TRANSPARENT,pCheck->ColorReliefDown);
    
    if ((nby > 4) && ( nbx > 4 )) 
      {
      if (HasFocus)
        LookRelief(atx+2,aty+2,nbx-4,nby-4,ColFG,CI_COL_TRANSPARENT,ColFG);

      if ((nby > 8) && ( nbx > 8 ))
        switch(Actif)
          {
          case CE_CHECK_ON:
            filzone(atx+4,aty+4,nbx-8,nby-8,ColFG);
            break;
          case CE_CHECK_ON2:
            filzone(atx+3,aty+3,nbx-6,nby-6,ColFG);
            break;
          }
      }
    }
}

// ****************************************************************************
/** DrawRadio
    Internal function

 * @param 

 * @return CE_OK

 * @author FRC
 
 */
// * VarGlob:
// ****************************************************************************
void  DrawRadio( int atx,int aty,int nbx,int nby, WORD ColFG, WORD ColBG, int HasFocus, int IsActif )
{
PTI_COMP_RADIO_DESCR pRadio = &g_pLook->Radio;

  SetChangeFlag();    

  LookRelief(atx,aty,nbx,nby,pRadio->ColorReliefUp,ColBG,pRadio->ColorReliefDown);
  if ((nby > 2) && ( nbx > 2 )) 
    {
    LookRelief(atx+1,aty+1,nbx-2,nby-2,pRadio->ColorReliefUp,CI_COL_TRANSPARENT,pRadio->ColorReliefDown);
    
    if ((nby > 4) && ( nbx > 4 )) 
      {
      if (HasFocus)
        LookRelief(atx+2,aty+2,nbx-4,nby-4,ColFG,CI_COL_TRANSPARENT,ColFG);

      if (( IsActif ) &&  (nby > 8) && ( nbx > 8 ))
        filzone(atx+4,aty+4,nbx-8,nby-8,ColFG);
      }
    }
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// - BDA APIs
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------



// ****************************************************************************
/** BdaGui_zF1Button: (THO name) zF1button - ABAL API - 
    Displays a combo box button

 * @param focus     IN : CE_FIELDLOOK_xxx values
 * @param x         IN : Coordinate
 * @param y         IN : Coordinate

 * @return CE_OK

 * @author ANF
 
 */
// * VarGlob:
// ****************************************************************************
EXAWORD BDA_API BdaGui_zF1Button(WORD state,WORD x,WORD y)
{
MI_TRACE_DCL_TFN("F1But");
PTI_COMP_COMBO_DESCR pCombo = &g_pLook->Combo;
WORD        ColFG;
WORD        ColBG;
WORD        ColReliefUp;
WORD        ColReliefDown;
PTI_MEMORY  pSkin;
WORD        SkinFlag;
WORD        grx,gry;
WORD        grcx,grcy;

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"at (%d,%d)",x,y));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"state=%d"  ,state));

  // -------------------------------------------------------------------
  // - Init
  // -------------------------------------------------------------------

  // --- Look identification
  switch(state)
    {
    case CE_FIELDLOOK_NORMAL:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Normal"));
      ColFG         = pCombo->ColorFGButtonNormal;
      ColBG         = pCombo->ColorBGButtonNormal;
      ColReliefUp   = pCombo->ColorReliefButtonUp;
      ColReliefDown = pCombo->ColorReliefButtonDown;
      pSkin = &pCombo->SkinButton;
      SkinFlag = CI_SKNF_3ZONES;
      break;

    case CE_FIELDLOOK_FOCUSED:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Selected"));
      ColFG         = pCombo->ColorFGButtonNormal;
      ColBG         = pCombo->ColorBGButtonNormal;
      ColReliefUp   = pCombo->ColorReliefButtonDown;
      ColReliefDown = pCombo->ColorReliefButtonUp;
      pSkin = &pCombo->SkinButton;
      SkinFlag = CI_SKNF_3ZONES_MIDDLE;
      break;

    case CE_FIELDLOOK_GRAYED:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Disabled"));
      ColFG         = pCombo->ColorFGButtonDisabled;
      ColBG         = pCombo->ColorBGButtonDisabled;
      ColReliefUp   = pCombo->ColorReliefButtonUp;
      ColReliefDown = pCombo->ColorReliefButtonDown;
      pSkin = &pCombo->SkinButton;
      SkinFlag = CI_SKNF_3ZONES_BOTTOM;
      break;

    case CE_FIELDLOOK_HIDDEN:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Hidden"));
      ColBG = pCombo->ColorBGButtonHidden;
      break;

    default:
      MI_TRACE((CI_TRA_F_WARNING,CI_MODULE_ID,TFN,"state unknown"));
      break;
    }
    
  // -------------------------------------------------------------------
  // - Compute
  // -------------------------------------------------------------------
  SysHide();

  grx  = (x-1)*cellwidth;
  gry  = (y-1)*cellheight;
  grcx = 2*cellwidth;
  grcy = cellheight;

  if ( state == CE_FIELDLOOK_HIDDEN )
    filzone( grx, gry, grcx, grcy, ColBG);
  else
    {
    if ( pSkin->Ptr == NULL)
      {
      LookRelief( grx,gry, grcx,grcy, ColReliefUp, ColBG, ColReliefDown );
      draw_arrow(_ARROW_LINE_DOWN,grx,gry,grcx,grcy,ColFG);
      }
    else  
      LookApplySkinButton( grx, gry, grcx, grcy, pSkin->Ptr, SkinFlag);
    }

  SysShow();

MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaGui_zVaButton: - (THO name) zvabutton - ABAL API
    Displays a variator button

 * @param focus     IN : CE_FIELDLOOK_xxx values
 * @param x         IN : Coordinate
 * @param y         IN : Coordinate

 * @return CE_OK

 * @author CCDoc Administrator
 
 */
// * VarGlob:
// ****************************************************************************
EXAWORD BDA_API BdaGui_zVaButton(WORD state,WORD x,WORD y)
{
MI_TRACE_DCL_TFN("VaBut");
PTI_COMP_VAR_DESCR pVar = &g_pLook->Variator;
WORD        ColFG;
WORD        ColBG;
WORD        SkinFlag;
PTI_MEMORY  pSkin;
int gratcol,gratlin;
int grnbcol,grnblin;

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"at (%d,%d)",x,y));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"focus=%d",state));

  // -------------------------------------------------------------------
  // - Init
  // -------------------------------------------------------------------

  // --- Look identification
  pSkin = &pVar->SkinVar;

  switch(state)
    {
    case CE_VARIATOR_NORMAL:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Normal"));
      ColFG    = pVar->ColorFGNormal;
      ColBG    = pVar->ColorBGNormal;
      SkinFlag = CI_SKNF_3ZONES;
      break;

    case CE_VARIATOR_UP:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Selected"));
      ColFG    = pVar->ColorFGNormal;
      ColBG    = pVar->ColorBGNormal;
      SkinFlag = CI_SKNF_3ZONES_MIDDLE;
      break;

    case CE_VARIATOR_DOWN:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Disabled"));
      ColFG    = pVar->ColorFGNormal;
      ColBG    = pVar->ColorBGNormal;
      SkinFlag = CI_SKNF_3ZONES_BOTTOM;
      break;

    case CE_VARIATOR_GRAYED:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Disabled"));
      ColFG = pVar->ColorFGDisabled;
      ColBG = pVar->ColorBGDisabled;
      SkinFlag = CI_SKNF_3ZONES_EXT;
      break;

    case CE_VARIATOR_HIDDEN:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Hidden"));
      ColFG = pVar->ColorFGHidden;
      ColBG = pVar->ColorFGHidden;
      break;

    default:
      MI_TRACE((CI_TRA_F_WARNING,CI_MODULE_ID,TFN,"state unknown"));
      break;
    }

  // Coordinates
  if (pSkin->Ptr==NULL)
    {
    // Draw mode
    gratcol = (x-1)*cellwidth;
    gratlin = (y-1)*cellheight;
    grnbcol = 2*cellwidth;
    grnblin = cellheight;
    }
  else
    {
    // Skin mode
    gratcol = (x-1)*cellwidth;
    gratlin = (y-1)*cellheight;
    grnbcol = 3*cellwidth;
    grnblin = cellheight;
    }

  // -------------------------------------------------------------------
  // - Compute
  // -------------------------------------------------------------------
  SysHide();

  if (state==CE_VARIATOR_HIDDEN)
    filzone(gratcol, gratlin, grnbcol, grnblin, ColBG);
  else
    {
    if (pSkin->Ptr==NULL)
      DrawVariator(gratcol, gratlin, grnbcol, grnblin, ColFG, ColBG); 
    else
      LookApplySkinButton( gratcol, gratlin, grnbcol, grnblin, pSkin->Ptr, SkinFlag );
    }

  SysShow();

MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaGui_zCheck: (THO name) zcheck - ABAL API
     Displays a check button

 * @param focus     IN : CE_FIELDLOOK_xxx values
 * @param actif     IN : 
 * @param x         IN : Coordinate
 * @param y         IN : Coordinate
 * @param coul      IN : 
 * @param fond      IN : 

 * @return CE_OK

 * @author ANF
 
 */
// * VarGlob:
// ****************************************************************************
EXAWORD BDA_API BdaGui_zCheck(WORD state,WORD actif,WORD x,WORD y,WORD coul,WORD fond)
{
MI_TRACE_DCL_TFN("Check");
PTI_COMP_CHECK_DESCR pCheck = &g_pLook->Check;
WORD        ColFG;
WORD        ColBG;
WORD        SkinFlag;
PTI_MEMORY  pSkin;
int gratcol,gratlin;
int grnbcol,grnblin;

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"at (%d,%d)",x,y));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"colors (%d,%d)",coul,fond));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"focus=%d actif=%d",state,actif));

  // -------------------------------------------------------------------
  // - Init
  // -------------------------------------------------------------------

  // --- Activation state (on/off)
  switch(actif)
    {
    case CE_CHECK_ON:
      pSkin = &pCheck->SkinOn;
      break;
    case CE_CHECK_ON2:
      pSkin = &pCheck->SkinOn2;
      break;
    case CE_CHECK_OFF:
    default:
      pSkin = &pCheck->SkinOff;
      break;
    }
  
  // --- Look identification
  switch(state)
    {
    case CE_FIELDLOOK_NORMAL:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Normal"));
      ColFG    = pCheck->ColorFGNormal;
      ColBG    = pCheck->ColorBGNormal;
      SkinFlag = CI_SKNF_3ZONES;
      break;

    case CE_FIELDLOOK_FOCUSED:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Selected"));
      ColFG = pCheck->ColorFGSelected;
      ColBG = pCheck->ColorBGSelected;
      SkinFlag = CI_SKNF_3ZONES_MIDDLE;
      break;

    case CE_FIELDLOOK_GRAYED:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Disabled"));
      ColFG = pCheck->ColorFGDisabled;
      ColBG = pCheck->ColorBGDisabled;
      SkinFlag = CI_SKNF_3ZONES_BOTTOM;
      break;

    case CE_FIELDLOOK_HIDDEN:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Hidden"));
      ColFG = pCheck->ColorFGHidden;
      ColBG = pCheck->ColorFGHidden;
      break;

    default:
      MI_TRACE((CI_TRA_F_WARNING,CI_MODULE_ID,TFN,"state unknown"));
      break;
    }

  // Coordinates
  if (pSkin->Ptr==NULL)
    {
    // Draw mode, centered
    gratcol = ( ((x-1) * cellwidth ) -2 );
    gratlin =   ((y-1) * cellheight);
    grnbcol = (cellwidth+4);
    grnblin = cellheight;
    if ( cellheight > (cellwidth+4) ) 
      {
      grnblin -= (cellheight - (cellwidth+4));
      gratlin += ((cellheight - (cellwidth+4))/2);
      }
    }
  else
    {
    // Skin mode
    gratcol = (x-1)*cellwidth;
    gratlin = (y-1)*cellheight;
    grnbcol = 3*cellwidth;
    grnblin = cellheight;
    }

  // -------------------------------------------------------------------
  // - Compute
  // -------------------------------------------------------------------
  SysHide();

  if (state==CE_FIELDLOOK_HIDDEN)
    filzone(gratcol, gratlin, grnbcol, grnblin, ColBG);
  else
    {
    if (pSkin->Ptr==NULL)
      DrawCheck(gratcol, gratlin, grnbcol, grnblin, ColFG, ColBG, state, actif); 
    else
      LookApplySkinButton( gratcol, gratlin, grnbcol, grnblin, pSkin->Ptr, SkinFlag );
    }

  cicocurser(x+2,y);

  SysShow();

MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaGui_zRadio: (THO name) zradio - ABAL API
    Displays a radio button

 * @param focus     IN : CE_FIELDLOOK_xxx values
 * @param actif     IN : 
 * @param x         IN : Coordinate
 * @param y         IN : Coordinate
 * @param coul      IN : 
 * @param fond      IN : 

 * @return CE_OK

 * @author ANF
 
 */
// * VarGlob:
// ****************************************************************************
EXAWORD BDA_API BdaGui_zRadio(WORD state,WORD actif,WORD x,WORD y,WORD coul,WORD fond)
{
MI_TRACE_DCL_TFN("Radio");
PTI_COMP_RADIO_DESCR pRadio = &g_pLook->Radio;
WORD        ColFG;
WORD        ColBG;
WORD        SkinFlag;
PTI_MEMORY  pSkin;
int gratcol,gratlin;
int grnbcol,grnblin;

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"at (%d,%d)",x,y));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"colors (%d,%d)",coul,fond));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"focus=%d actif=%d",state,actif));

  // -------------------------------------------------------------------
  // - Init
  // -------------------------------------------------------------------

  // --- Activation state (on/off)
  switch(actif)
    {
    case CE_RADIO_ON:
      pSkin = &pRadio->SkinOn;
      break;
    case CE_RADIO_OFF:
    default:
      pSkin = &pRadio->SkinOff;
      break;
    }
  
  // --- Look identification
  switch(state)
    {
    case CE_FIELDLOOK_NORMAL:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Normal"));
      ColFG    = pRadio->ColorFGNormal;
      ColBG    = pRadio->ColorBGNormal;
      SkinFlag = CI_SKNF_3ZONES;
      break;

    case CE_FIELDLOOK_FOCUSED:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Selected"));
      ColFG = pRadio->ColorFGSelected;
      ColBG = pRadio->ColorBGSelected;
      SkinFlag = CI_SKNF_3ZONES_MIDDLE;
      break;

    case CE_FIELDLOOK_GRAYED:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Disabled"));
      ColFG = pRadio->ColorFGDisabled;
      ColBG = pRadio->ColorBGDisabled;
      SkinFlag = CI_SKNF_3ZONES_BOTTOM;
      break;

    case CE_FIELDLOOK_HIDDEN:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Hidden"));
      ColFG = pRadio->ColorFGHidden;
      ColBG = pRadio->ColorBGHidden;
      break;

    default:
      MI_TRACE((CI_TRA_F_WARNING,CI_MODULE_ID,TFN,"state unknown"));
      break;
    }

  // Coordinates
  if (pSkin->Ptr==NULL)
    {
    // Draw mode, centered
    gratcol = ( ((x-1) * cellwidth ) -2 );
    gratlin =   ((y-1) * cellheight);
    grnbcol = (cellwidth+4);
    grnblin = cellheight;
    if ( cellheight > (cellwidth+4) ) 
      {
      grnblin -= (cellheight - (cellwidth+4));
      gratlin += ((cellheight - (cellwidth+4))/2);
      }
    }
  else
    {
    // Skin mode
    gratcol = (x-1)*cellwidth;
    gratlin = (y-1)*cellheight;
    grnbcol = 3*cellwidth;
    grnblin = cellheight;
    }

  // -------------------------------------------------------------------
  // - Compute
  // -------------------------------------------------------------------
  SysHide();

  if (state==CE_FIELDLOOK_HIDDEN)
    filzone(gratcol, gratlin, grnbcol, grnblin, ColBG);
  else
    {
    if (pSkin->Ptr==NULL)
      DrawRadio(gratcol, gratlin, grnbcol, grnblin, ColFG, ColBG, state, actif); 
    else
      LookApplySkinButton( gratcol, gratlin, grnbcol, grnblin, pSkin->Ptr, SkinFlag );
    }

  cicocurser(x+2,y);
  // FRC I think it is not required: cicocolour(coul,fond);

  SysShow();

MI_TRACE_RETURN(CE_OK);
}


