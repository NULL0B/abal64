/** @pkg Staff.Fred.zGuiList */ 
// ****************************************************************************
// * zList.c
// * Included in GUI module
// * List functionnalities
// ****************************************************************************

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// - Basic internal Functions
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

VOID GuiListFrame(int atcol,int atlin,int nbcol,int nblin) 
{
PTI_COMP_LIST_DESCR pList = &g_pLook->List;
  int gratcol,gratlin;
  int grnbcol,grnblin;

  gratcol = (atcol-1)*cellwidth;
  gratlin = (atlin-1)*cellheight;
  grnbcol = nbcol*cellwidth;
  grnblin = nblin*cellheight;

  if ( pList->SkinFrame.Ptr == NULL)
    {
    // Waiting ABAL level modification to suppress the THO Windows optimisation :
    // To avoid a blank zone when items of list are colored by client application,
    // I put the left border at the right of the character
    gratcol += (cellwidth-1);
    grnbcol -= (cellwidth-1);
    LookRelief( gratcol, gratlin, grnbcol, grnblin, pList->ColorReliefFrameUp, pList->ColorBGNormal, pList->ColorReliefFrameDown );
    }
  else  
    LookApplySkin( gratcol, gratlin, grnbcol, grnblin, pList->SkinFrame.Ptr, CI_SKNF_9ZONES_NOCENTER );
}



// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// - BDA APIs
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------


// ****************************************************************************
/** BdaGui_zListHoriScrollBar: (THO name) zlist_hlift - ABAL API -
    Display a horizontal scroll bar

 * @param x       IN : Scroll bar coordinate
 * @param y       IN : Scroll bar coordinate
 * @param flag    IN : 0 lists, 1 scroll bar
 * @param larg    IN
 * @param pos     IN
 * @param size    IN
 * @param state   IN : see constant CE_SCR_xxx

 * @return CE_OK

 * @author ANF
 
 */
// * VarGlob:
// ****************************************************************************
EXAWORD BDA_API BdaGui_zListHoriScrollBar(WORD x,WORD y,WORD flag,WORD larg,WORD pos,WORD size,WORD state)
{
MI_TRACE_DCL_TFN("zHScroll");
PTI_COMP_SCROLL_DESCR pScroll = &g_pLook->Scroll;
WORD        ColBGBut;
WORD        ColFGBut;
WORD        ColBGSlider;
WORD        ColFGSlider;
WORD        ColReliefB1Up;
WORD        ColReliefB1Down;
WORD        ColReliefB2Up;
WORD        ColReliefB2Down;
WORD        SkinB1Flag;
WORD        SkinB2Flag;
PTI_MEMORY  pSkinB1But  = &pScroll->SkinLeftBut;
PTI_MEMORY  pSkinB2But  = &pScroll->SkinRightBut;
PTI_MEMORY  pSkinSlider;
WORD  grx,gry;
WORD  grxBut;
WORD  grcx,grcy;

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"at (%d,%d)",x,y));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"flag=%d larg=%d pos=%d size=%d",flag,larg,pos,size));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"state=%d",state));

  SetChangeFlag();    

  // -------------------------------------------------------------------
  // - Init
  // - Oulesian parameter analyse
  // -------------------------------------------------------------------

  // The most common look
  ColFGBut    = pScroll->ColorFGButNormal;
  ColBGBut    = pScroll->ColorBGButNormal;

  ColReliefB1Up       = pScroll->ColorReliefButUp;
  ColReliefB1Down     = pScroll->ColorReliefButDown;
  ColReliefB2Up       = pScroll->ColorReliefButUp;
  ColReliefB2Down     = pScroll->ColorReliefButDown;

  SkinB1Flag       = CI_SKNF_2ZONES;
  SkinB2Flag       = CI_SKNF_2ZONES;

  ColFGSlider = pScroll->ColorFGSliderNormal;
  ColBGSlider = pScroll->ColorBGSliderNormal;
  pSkinSlider = &pScroll->SkinHSliderNormal;

  // Change the colors for specific states
  switch(state)
    {
    case CE_SCR_B1PUSH :
      // invert relief for pushed look
      ColReliefB1Up   = pScroll->ColorReliefButDown;
      ColReliefB1Down = pScroll->ColorReliefButUp;
      SkinB1Flag      = CI_SKNF_2ZONES_MIDDLE;
      break;
    case CE_SCR_B2PUSH:
      // invert relief for pushed look
      ColReliefB2Up   = pScroll->ColorReliefButDown;
      ColReliefB2Down = pScroll->ColorReliefButUp;
      SkinB2Flag      = CI_SKNF_2ZONES_MIDDLE;
      break;
    case CE_SCR_DISABLED:
      // grayed look
      ColFGBut        = pScroll->ColorFGButDisabled;
      ColBGBut        = pScroll->ColorBGButDisabled;
      ColFGSlider     = pScroll->ColorFGSliderDisabled;
      ColBGSlider     = pScroll->ColorBGSliderDisabled;
      SkinB1Flag      = CI_SKNF_2ZONES_BOTTOM;
      SkinB2Flag      = CI_SKNF_2ZONES_BOTTOM;
      pSkinSlider     = &pScroll->SkinHSliderDisabled;
      break;
    } 

  // -------------------------------------------------------------------
  // - Compute
  // -------------------------------------------------------------------
  SysHide();

  // --- Base coordinates
  grx  = (x-1)*cellwidth;
  gry  = (y-1)*cellheight;
  grcx = larg*cellwidth;
  grcy = cellheight;

  if (state==CE_SCR_HIDDEN)
    filzone(grx,gry,grcx,grcy,pScroll->ColorBGHidden);
  else
    {
    // --- Background of scroll bar
    if (pSkinSlider->Ptr==NULL)  
      LookRelief( grx, gry, grcx, grcy, pScroll->ColorReliefUp, ColBGSlider, pScroll->ColorReliefDown );
    else
      LookApplySkin( grx, gry, grcx, grcy, pSkinSlider->Ptr, CI_SKNF_3ZONES );
  
    // --- Left Button
    if (pSkinB1But->Ptr==NULL)
      {
      grxBut = grx+1;
      LookRelief( grxBut, gry+1, (cellwidth*2)-1, cellheight-2, ColReliefB1Up, ColBGBut, ColReliefB1Down);
      draw_arrow(_ARROW_LEFT, grxBut, gry+1, (cellwidth*2)-1, cellheight-2, ColFGBut);
      }
    else
      {
      grxBut = grx;
      LookApplySkinButton( grxBut, gry, grcx, grcy, pSkinB1But->Ptr, SkinB1Flag );
      }
  
    // --- Right Button
    if (pSkinB2But->Ptr==NULL)
      {
      grxBut = grx + grcx - 2*cellwidth;
      LookRelief( grxBut, gry+1, (cellwidth*2)-1, cellheight-2, ColReliefB2Up, ColBGBut, ColReliefB2Down);
      draw_arrow(_ARROW_RIGHT, grxBut, gry+1, (cellwidth*2)-1, cellheight-2, ColFGBut);
      }
    else
      {
      grxBut = grx + grcx - 2*cellwidth;
      LookApplySkinButton( grxBut, gry, grcx, grcy, pSkinB2But->Ptr, SkinB2Flag );
      }
  
    // --- Horizontal Slider
    //     (skin not implemented, because of size in pixel)

    // Oulesian parameter
    // 'size' must be extended with 2 characters
    size += (cellwidth*2);

    // FRC bug from ABAL level: pos or size can be out of range
    if (  (  (long)grx+(long)2*cellwidth+(long)pos            <= (long)grx+(long)grcx )
       && (  (long)grx+(long)2*cellwidth+(long)pos+(long)size <= (long)grx+(long)grcx )
       )
      {
      grxBut = grx + 2*cellwidth + pos;
      MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"slid %u on %u, scroll %u on %u",grxBut,size,grx,grcx));
      }
    else
      {
      MI_TRACE((CI_TRA_F_WARNING,CI_MODULE_ID,TFN,"slider overflow %u,%u",pos,size));
      grxBut = grx + 2*cellwidth;
      size=0;
      }

    if ((size) && (larg>4))
      {
      grxBut = grx + 2*cellwidth + pos;
      LookRelief( grxBut, gry+4, size, cellheight-8, pScroll->ColorReliefSliderUp, ColFGSlider, pScroll->ColorReliefSliderDown);
      }
    }

  SysShow();

MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaGui_zListVertScrollBar: (THO name) zlist_vlift - ABAL API
    Display a vertical scroll bar (except for file lists)

 * @param x       IN : Scroll bar coordinate
 * @param y       IN : Scroll bar coordinate
 * @param flag    IN
 * @param haut    IN
 * @param pos     IN
 * @param size    IN
 * @param state   IN : see constant CE_SCR_xxx

 * @return CE_OK

 * @author ANF
 
 */
// * VarGlob:
// ****************************************************************************
EXAWORD BDA_API BdaGui_zListVertScrollBar(WORD x,WORD y,WORD flag,WORD haut,WORD pos,WORD size,WORD state)
{
MI_TRACE_DCL_TFN("VScroll");
PTI_COMP_SCROLL_DESCR pScroll = &g_pLook->Scroll;
WORD        ColBGBut;
WORD        ColFGBut;
WORD        ColBGSlider;
WORD        ColFGSlider;
WORD        ColReliefB1Up;
WORD        ColReliefB1Down;
WORD        ColReliefB2Up;
WORD        ColReliefB2Down;
WORD        SkinB1Flag;
WORD        SkinB2Flag;
PTI_MEMORY  pSkinB1But  = &pScroll->SkinUpBut;
PTI_MEMORY  pSkinB2But  = &pScroll->SkinDownBut;
PTI_MEMORY  pSkinSlider;
WORD  grx,gry;
WORD  gryBut;
WORD  grySlider;
WORD  grcySlider;
WORD  grcx,grcy;
int   larg=2;

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"at (%d,%d)",x,y));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"flag=%u haut=%u pos=%u size=%u",flag,haut,pos,size));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"state=%d",state));

  SetChangeFlag();    

  // -------------------------------------------------------------------
  // - Init
  // - Oulesian parameter analyse
  // -------------------------------------------------------------------

  // The most common look
  ColFGBut    = pScroll->ColorFGButNormal;
  ColBGBut    = pScroll->ColorBGButNormal;

  ColReliefB1Up    = pScroll->ColorReliefButUp;
  ColReliefB1Down  = pScroll->ColorReliefButDown;
  ColReliefB2Up    = pScroll->ColorReliefButUp;
  ColReliefB2Down  = pScroll->ColorReliefButDown;

  SkinB1Flag       = CI_SKNF_2ZONES;
  SkinB2Flag       = CI_SKNF_2ZONES;

  ColFGSlider = pScroll->ColorFGSliderNormal;
  ColBGSlider = pScroll->ColorBGSliderNormal;
  pSkinSlider = &pScroll->SkinVSliderNormal;

  // Change the colors for specific states
  switch(state)
    {
    case CE_SCR_B1PUSH :
      // invert relief for pushed look
      ColReliefB1Up   = pScroll->ColorReliefButDown;
      ColReliefB1Down = pScroll->ColorReliefButUp;
      SkinB1Flag      = CI_SKNF_2ZONES_MIDDLE;
      break;
    case CE_SCR_B2PUSH:
      // invert relief for pushed look
      ColReliefB2Up   = pScroll->ColorReliefButDown;
      ColReliefB2Down = pScroll->ColorReliefButUp;
      SkinB2Flag      = CI_SKNF_2ZONES_MIDDLE;
      break;
    case CE_SCR_DISABLED:
      // grayed look
      ColFGBut        = pScroll->ColorFGButDisabled;
      ColBGBut        = pScroll->ColorBGButDisabled;
      ColFGSlider     = pScroll->ColorFGSliderDisabled;
      ColBGSlider     = pScroll->ColorBGSliderDisabled;
      SkinB1Flag      = CI_SKNF_2ZONES_BOTTOM;
      SkinB2Flag      = CI_SKNF_2ZONES_BOTTOM;
      pSkinSlider     = &pScroll->SkinHSliderDisabled;
      break;
    } 

  // -------------------------------------------------------------------
  // - Compute
  // -------------------------------------------------------------------
  SysHide();

  // --- Base coordinates
  grx  = (x-1)*cellwidth;
  gry  = (y-1)*cellheight;
  grcx = larg*cellwidth;
  grcy = haut*cellheight;

  // Oulesian parameter
  // When flag is set to 1, the scroll bar is shifted to an half character
  // I understand it is the case when a scroll bar is not for a list.
  // With this, it is possible to put a frame around the scroll bar to have more beautiful display.
  // les gouts et les couleurs, hein, j'vous jure.
  if (flag==1)
    grx += (cellwidth/2);

  if (state==CE_SCR_HIDDEN)
    {
    // ---------------------------------------
    // All hidden
    // ---------------------------------------
    filzone(grx,gry,grcx,grcy,pScroll->ColorBGHidden);
    }
  else if (state==CE_SCR_SLIDER)
    {
    // ---------------------------------------
    // Just the middle bar + slider
    // only if the height is correct
    // ---------------------------------------
    if (haut>2)
      {
      grySlider  = gry  + cellheight;
      grcySlider = grcy - 2*cellheight;
  
      // --- Background of scroll bar
      if (pSkinSlider->Ptr==NULL)
        {  
        filzone(grx,grySlider,grcx,grcySlider,ColBGSlider);
        filzone(grx,grySlider,1,grcySlider,pScroll->ColorReliefUp);
        filzone(grx+grcx-1,grySlider,1,grcySlider,pScroll->ColorReliefDown);
        //LookRelief( grx, gry, grcx, grcy, pScroll->ColorReliefUp, ColBGSlider, pScroll->ColorReliefDown );
        }
      else
        LookApplySkin( grx, grySlider, grcx, grcySlider, pSkinSlider->Ptr, CI_SKNF_6ZONES_V);
  
      // --- Vertical Slider
      //     (skin not implemented, because of size in pixel)

      // FRC bug from ABAL level: pos or size can be out of range
      if (  (  (long)gry+(long)cellheight+(long)pos            <= (long)gry+(long)grcy )
         && (  (long)gry+(long)cellheight+(long)pos+(long)size <= (long)gry+(long)grcy )
         )
        {
        gryBut = gry + cellheight + pos;
        MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"slid %u on %u, scroll %u on %u",gryBut,size,gry,grcy));
        }
      else
        {
        MI_TRACE((CI_TRA_F_WARNING,CI_MODULE_ID,TFN,"slider overflow %u,%u",pos,size));
        gryBut = gry + cellheight;
        size=0;
        }
  
      if ( size )
        LookRelief( grx+4, gryBut, cellwidth*larg-8, size, pScroll->ColorReliefSliderUp, ColFGSlider, pScroll->ColorReliefSliderDown);
      }
    }
  else
    {
    // ---------------------------------------
    // All visible
    // ---------------------------------------

    // --- Background of scroll bar
    if (pSkinSlider->Ptr==NULL)  
      LookRelief( grx, gry, grcx, grcy, pScroll->ColorReliefUp, ColBGSlider, pScroll->ColorReliefDown );
    else
      LookApplySkin( grx, gry, grcx, grcy, pSkinSlider->Ptr, CI_SKNF_6ZONES_V);
  
    // --- Up Button
    if (pSkinB1But->Ptr==NULL)
      {
      gryBut = gry+1;
      LookRelief( grx+1, gryBut, (cellwidth*2)-2, cellheight-1, ColReliefB1Up, ColBGBut, ColReliefB1Down);
      draw_arrow(_ARROW_LINE_UP, grx+1, gryBut, (cellwidth*2)-2, cellheight-1, ColFGBut);
      }
    else
      {
      gryBut = gry;
      LookApplySkinButton( grx, gryBut, grcx, grcy, pSkinB1But->Ptr, SkinB1Flag );
      }
  
    // --- Down button
    if (pSkinB2But->Ptr==NULL)
      {
      gryBut = gry + grcy - cellheight;
      LookRelief( grx+1, gryBut, (cellwidth*2)-2, cellheight-1, ColReliefB2Up, ColBGBut, ColReliefB2Down);
      draw_arrow(_ARROW_LINE_DOWN, grx+1, gryBut, (cellwidth*2)-2, cellheight-1, ColFGBut);
      }
    else
      {
      gryBut = gry + grcy - cellheight;
      LookApplySkinButton( grx, gryBut, grcx, grcy, pSkinB2But->Ptr, SkinB2Flag );
      }
    
    // --- Vertical Slider
    //     if the height is correct
    //     (skin not implemented, because of size in pixel)

    // FRC bug from ABAL level: pos or size can be out of range
    if (  (  (long)gry+(long)cellheight+(long)pos            <= (long)gry+(long)grcy )
       && (  (long)gry+(long)cellheight+(long)pos+(long)size <= (long)gry+(long)grcy )
       )
      {
      gryBut = gry + cellheight + pos;
      MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"slid %u on %u, scroll %u on %u",gryBut,size,gry,grcy));
      }
    else
      {
      MI_TRACE((CI_TRA_F_WARNING,CI_MODULE_ID,TFN,"slider overflow %u,%u",pos,size));
      gryBut = gry + cellheight;
      size=0;
      }

    if ( size )
      LookRelief( grx+4, gryBut, cellwidth*larg-8, size, pScroll->ColorReliefSliderUp, ColFGSlider, pScroll->ColorReliefSliderDown);
    }

  SysShow();

MI_TRACE_RETURN(0);
}

// ****************************************************************************
/** BdaGui_zLisFicScrollBar: (THO name) zlisf_lift - ABAL API - 
    Display a vertical scroll bar for file lists

 * @param x       IN : Scroll bar coordinate
 * @param y       IN : Scroll bar coordinate
 * @param haut    IN
 * @param pos     IN
 * @param state   IN : see constant CE_FSCR_xxx

 * @return CE_OK

 * @author ANF
 
 */

// * VarGlob:
// ****************************************************************************
WORD FicScrollDisplayAll(WORD x,WORD y,WORD larg,WORD haut,WORD state)
{
PTI_COMP_SCROLL_DESCR pScroll = &g_pLook->Scroll;
WORD        ColBGBut;
WORD        ColFGBut;
WORD        ColBGSlider;
WORD        ColFGSlider;
WORD        SkinButFlag;
WORD        ColReliefButUp;
WORD        ColReliefButDown;
PTI_MEMORY  pSkinBut;
PTI_MEMORY  pSkinSlider;

WORD  HasButArrow, HasButPage, HasButHome;
WORD  gryButTop , gryButBot;
WORD  gryButUp  , gryButDwn;
WORD  gryButPgUp, gryButPgDwn;

WORD  grx,gry;
WORD  grcx,grcy;

  // -------------------------------------------------------------------
  // - Init
  // -------------------------------------------------------------------
  ColReliefButUp   = pScroll->ColorReliefButUp;
  ColReliefButDown = pScroll->ColorReliefButDown;

  switch(state)
    {
    case CE_FSCR_NORMAL :
      ColFGBut    = pScroll->ColorFGButNormal;
      ColBGBut    = pScroll->ColorBGButNormal;
      SkinButFlag = CI_SKNF_2ZONES;
      ColFGSlider = pScroll->ColorFGSliderNormal;
      ColBGSlider = pScroll->ColorBGSliderNormal;
      pSkinSlider = &pScroll->SkinVSliderNormal;
      break;

    case CE_FSCR_DISABLED:
      ColFGBut    = pScroll->ColorFGButDisabled;
      ColBGBut    = pScroll->ColorBGButDisabled;
      SkinButFlag = CI_SKNF_2ZONES_BOTTOM;
      ColFGSlider = pScroll->ColorFGSliderDisabled;
      ColBGSlider = pScroll->ColorBGSliderDisabled;
      pSkinSlider = &pScroll->SkinVSliderDisabled;
      break;
    } 

  // -------------------------------------------------------------------
  // - Compute
  // -------------------------------------------------------------------
  if (haut<2)
    return CE_OK;

  SysHide();

  larg = 2;

  // --- Base coordinates
  grx  = (x-1)*cellwidth;
  gry  = (y-1)*cellheight;
  grcx = larg*cellwidth;
  grcy = haut*cellheight;

  if (state==CE_FSCR_HIDDEN)
    filzone(grx,gry,grcx,grcy,pScroll->ColorBGHidden);
  else
    {
    switch(haut)
      {
      case 2:
      case 3:
        // 2 buttons
        HasButHome  = FALSE;
        HasButPage  = FALSE;
        HasButArrow = TRUE;
        gryButUp    = gry; 
        gryButDwn   = gry+grcy-cellheight;
        break;
      case 4:
      case 5:
        // 4 buttons
        HasButHome  = FALSE;
        HasButPage  = TRUE;
        HasButArrow = TRUE;
        gryButPgUp  = gry; 
        gryButUp    = gryButPgUp + cellheight; 
        gryButPgDwn = gry+grcy-cellheight;
        gryButDwn   = gryButPgDwn-cellheight;
        break;
      case 6:
      default:
        // 6 buttons or more
        HasButHome  = TRUE;
        HasButPage  = TRUE;
        HasButArrow = TRUE;
        gryButTop   = gry; 
        gryButPgUp  = gryButTop  + cellheight; 
        gryButUp    = gryButPgUp + cellheight; 
        gryButBot   = gry+grcy-cellheight;
        gryButPgDwn = gryButBot-cellheight;
        gryButDwn   = gryButPgDwn-cellheight;
        break;
      }

    // --- Background of scroll bar
    if (pSkinSlider->Ptr==NULL)  
      LookRelief( grx, gry, grcx, grcy, pScroll->ColorReliefUp, ColBGSlider, pScroll->ColorReliefDown );
    else
      LookApplySkin( grx, gry, grcx, grcy, pSkinSlider->Ptr, CI_SKNF_3ZONES );

    // --- Arrow buttons
    if (HasButArrow)
      {
      // -- Up
      pSkinBut = &pScroll->SkinUpBut;
      if (pSkinBut->Ptr==NULL)
        {
        LookRelief( grx+1, gryButUp+1, grcx-2, cellheight-1, ColReliefButUp, ColBGBut, ColReliefButDown);
        draw_arrow(_ARROW_LINE_UP, grx+1, gryButUp+1, grcx-2, cellheight-1, ColFGBut);
        }
      else
        LookApplySkinButton( grx, gryButUp, grcx, grcy, pSkinBut->Ptr, SkinButFlag );
    
      // -- Down
      pSkinBut = &pScroll->SkinDownBut;
      if (pSkinBut->Ptr==NULL)
        {
        LookRelief( grx+1, gryButDwn+1, grcx-2, cellheight-1, ColReliefButUp, ColBGBut, ColReliefButDown);
        draw_arrow(_ARROW_LINE_DOWN, grx+1, gryButDwn+1, grcx-2, cellheight-1, ColFGBut);
        }
      else
        LookApplySkinButton( grx, gryButDwn, grcx, grcy, pSkinBut->Ptr, SkinButFlag );
      }

    // --- Page buttons
    if (HasButPage)
      {
      // -- Page Up
      pSkinBut = &pScroll->SkinPgUpBut;
      if (pSkinBut->Ptr==NULL)
        {
        LookRelief( grx+1, gryButPgUp+1, grcx-2, cellheight-1, ColReliefButUp, ColBGBut, ColReliefButDown);
        draw_arrow(_ARROW_PAGE_UP, grx+1, gryButPgUp+1, grcx-2, cellheight-1, ColFGBut);
        }
      else
        LookApplySkinButton( grx, gryButPgUp, grcx, grcy, pSkinBut->Ptr, SkinButFlag );
    
      // -- Page Down
      pSkinBut = &pScroll->SkinPgDownBut;
      if (pSkinBut->Ptr==NULL)
        {
        LookRelief( grx+1, gryButPgDwn+1, grcx-2, cellheight-1, ColReliefButUp, ColBGBut, ColReliefButDown);
        draw_arrow(_ARROW_PAGE_DOWN, grx+1, gryButPgDwn+1, grcx-2, cellheight-1, ColFGBut);
        }
      else
        LookApplySkinButton( grx, gryButPgDwn, grcx, grcy, pSkinBut->Ptr, SkinButFlag );
      }
      
    // --- Home buttons
    if (HasButHome)
      {
      // -- Top
      pSkinBut = &pScroll->SkinTopBut;
      if (pSkinBut->Ptr==NULL)
        {
        LookRelief( grx+1, gryButTop+1, grcx-2, cellheight-1, ColReliefButUp, ColBGBut, ColReliefButDown);
        draw_arrow(_ARROW_HOME, grx+1, gryButTop+1, grcx-2, cellheight-1, ColFGBut);
        }
      else
        LookApplySkinButton( grx, gryButTop, grcx, grcy, pSkinBut->Ptr, SkinButFlag );
    
      // -- Bottom
      pSkinBut = &pScroll->SkinBottomBut;
      if (pSkinBut->Ptr==NULL)
        {
        LookRelief( grx+1, gryButBot+1, grcx-2, cellheight-1, ColReliefButUp, ColBGBut, ColReliefButDown);
        draw_arrow(_ARROW_END, grx+1, gryButBot+1, grcx-2, cellheight-1, ColFGBut);
        }
      else
        LookApplySkinButton( grx, gryButBot, grcx, grcy, pSkinBut->Ptr, SkinButFlag );
      }
    }

  SysShow();

return CE_OK;
}

WORD FicScrollDisplayOneButton(WORD x,WORD y,WORD larg,WORD haut,WORD state)
{
PTI_COMP_SCROLL_DESCR pScroll = &g_pLook->Scroll;
WORD        ColBGBut;
WORD        ColFGBut;
WORD        SkinButFlag;
WORD        ColReliefButUp;
WORD        ColReliefButDown;
PTI_MEMORY  pSkinBut;

WORD  gryButTop , gryButBot;
WORD  gryButUp  , gryButDwn;
WORD  gryButPgUp, gryButPgDwn;
WORD  gryBut;
WORD  ArrowID;

WORD  grx,gry;
WORD  grcx,grcy;

  // -------------------------------------------------------------------
  // - Init
  // -------------------------------------------------------------------
  larg = 2;

  // --- Base coordinates
  grx  = (x-1)*cellwidth;
  gry  = (y-1)*cellheight;
  grcx = larg*cellwidth;
  grcy = haut*cellheight;

  // --- Coordinates of all the buttons
  switch(haut)
    {
    case 2:
    case 3:
      // 2 buttons
      gryButUp    = gry; 
      gryButDwn   = gry+grcy-cellheight;
      break;
    case 4:
    case 5:
      // 4 buttons
      gryButPgUp  = gry; 
      gryButUp    = gryButPgUp + cellheight; 
      gryButPgDwn = gry+grcy-cellheight;
      gryButDwn   = gryButPgDwn-cellheight;
      break;
    case 6:
    default:
      // 6 buttons or more
      gryButTop   = gry; 
      gryButPgUp  = gryButTop  + cellheight; 
      gryButUp    = gryButPgUp + cellheight; 
      gryButBot   = gry+grcy-cellheight;
      gryButPgDwn = gryButBot-cellheight;
      gryButDwn   = gryButPgDwn-cellheight;
      break;
    }

  // Look of the button
  ColFGBut = pScroll->ColorFGButNormal;
  ColBGBut = pScroll->ColorBGButNormal;

  switch(state)
    {
    case CE_FSCR_DWN        : 
    case CE_FSCR_UP         :
    case CE_FSCR_PGDWN      :
    case CE_FSCR_PGUP       :
    case CE_FSCR_TOP        :
    case CE_FSCR_BOT        :
      ColReliefButUp   = pScroll->ColorReliefButUp;
      ColReliefButDown = pScroll->ColorReliefButDown;
      SkinButFlag = CI_SKNF_2ZONES;
      break;
    case CE_FSCR_DWNPUSH    :  
    case CE_FSCR_UPPUSH     :
    case CE_FSCR_PGDWNPUSH  :
    case CE_FSCR_PGUPPUSH   :
    case CE_FSCR_TOPPUSH    :
    case CE_FSCR_BOTPUSH    :
      ColReliefButUp   = pScroll->ColorReliefButDown;
      ColReliefButDown = pScroll->ColorReliefButUp;
      SkinButFlag = CI_SKNF_2ZONES_MIDDLE;
      break;
    }

  switch(state)
    {
    case CE_FSCR_DWN        : 
    case CE_FSCR_DWNPUSH    :
      pSkinBut = &pScroll->SkinDownBut;
      ArrowID  = _ARROW_LINE_DOWN;
      gryBut   = gryButDwn;
      break;
    case CE_FSCR_UP         :
    case CE_FSCR_UPPUSH     :
      pSkinBut = &pScroll->SkinUpBut;
      ArrowID  = _ARROW_LINE_UP;
      gryBut   = gryButUp;
      break;
    case CE_FSCR_PGDWN      :
    case CE_FSCR_PGDWNPUSH  :
      pSkinBut = &pScroll->SkinPgDownBut;
      gryBut   = gryButPgDwn;
      ArrowID  = _ARROW_PAGE_DOWN;
      break;
    case CE_FSCR_PGUP       :
    case CE_FSCR_PGUPPUSH   :
      pSkinBut = &pScroll->SkinPgUpBut;
      gryBut   = gryButPgUp;
      ArrowID  = _ARROW_PAGE_UP;
      break;
    case CE_FSCR_TOP        :
    case CE_FSCR_TOPPUSH    :
      pSkinBut = &pScroll->SkinTopBut;
      gryBut   = gryButTop;
      ArrowID  = _ARROW_HOME;
      break;
    case CE_FSCR_BOT        :
    case CE_FSCR_BOTPUSH    :
      pSkinBut = &pScroll->SkinBottomBut;
      gryBut   = gryButBot;
      ArrowID  = _ARROW_END;
      break;
    }

  // -------------------------------------------------------------------
  // - Compute
  // -------------------------------------------------------------------
  SysHide();

  if (pSkinBut->Ptr==NULL)
    {
    LookRelief( grx+1, gryBut+1, grcx-2, cellheight-1, ColReliefButUp, ColBGBut, ColReliefButDown);
    draw_arrow(ArrowID, grx+1, gryBut+1, grcx-2, cellheight-1, ColFGBut);
    }
  else
    LookApplySkinButton( grx, gryBut, grcx, grcy, pSkinBut->Ptr, SkinButFlag );

  SysShow();

return CE_OK;
}

EXAWORD BDA_API BdaGui_zLisFicScrollBar(WORD x,WORD y,WORD larg,WORD haut,WORD state)
{
MI_TRACE_DCL_TFN("VFicScroll");
WORD ret;

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"at (%d,%d)",x,y));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"larg=%d haut=%d",larg,haut));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"state=%d",state));

  SetChangeFlag();    

  if (  (state==CE_FSCR_NORMAL)
     || (state==CE_FSCR_DISABLED)
     || (state==CE_FSCR_HIDDEN)
     )
      ret = FicScrollDisplayAll(x,y,larg,haut,state);
  else
      ret = FicScrollDisplayOneButton(x,y,larg,haut,state);

MI_TRACE_RETURN(ret);
}

// ****************************************************************************
/** BdaGui_zListTitle: (THO name) zlist_title - ABAL API -
    Display a title for lists

 * @param x       IN 
 * @param y       IN 
 * @param lg      IN
 * @param titre   IN
// *
 * @return CE_OK

 * @author ANF
 
 */
// * VarGlob:
// ****************************************************************************
EXAWORD BDA_API BdaGui_zListTitle(WORD x,WORD y,WORD lg,char FAR * titre)
{
MI_TRACE_DCL_TFN("ListTitle");
PTI_COMP_LIST_DESCR pList = &g_pLook->List;
WORD        OldColors;
int gratcol,gratlin;
int grnbcol,grnblin;
WORD i,k;

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"at (%d,%d)",x,y));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"lg=%d",lg));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"text='%s'",MI_TRA_TRUNCLG(titre,lg)));

  SetChangeFlag();    

  // -------------------------------------------------------------------
  // - Init
  // -------------------------------------------------------------------
  if (titre==NULL)
    MI_TRACE_RETURN(CE_OK);

  // -------------------------------------------------------------------
  // - Compute moving of a column
  // -------------------------------------------------------------------
  if (titre[0] == 0)
    {
    // not implemented
    MI_TRACE_RETURN_MSG(CE_OK,"moving");
    }

  // -------------------------------------------------------------------
  // - Compute Title display
  // -------------------------------------------------------------------
  gratcol = (x-1)*cellwidth;
  gratlin = (y-1)*cellheight;
  grnbcol = lg*cellwidth;
  grnblin = cellheight;
  
  // --- Display the title bar
  if (pList->SkinTitle.Ptr==NULL)
    LookRelief( gratcol, gratlin, grnbcol, grnblin, pList->ColorReliefTitleUp, pList->ColorBGTitle, pList->ColorReliefTitleDown );
  else
    LookApplySkin( gratcol, gratlin, grnbcol, grnblin, pList->SkinTitle.Ptr, CI_SKNF_3ZONES );

  // --- Display the text
  OldColors = TexSetFGBG( pList->ColorFGTitle, CI_COL_TRANSPARENT );

  // ---------------------------------------------
  // Now draw the vertical separation 
  // and at the same time why not print the text !
  // ---------------------------------------------

  for (k=0,i=0;i<lg;i++) 
    {
    // Check for title separator character
    // -----------------------------------
    if (titre[i] == '\xB3') 
      {

      // ensure not the first one
      // -----------------------------------
      if (i > 0) 
        {

        // also ensure some text to print
        if ((i - k) > 0) 
          {
          titre[i] = 0;
          TexPrintXY(pList->hFontTitle, x+k, y, (titre+k), (i-k), CI_ESC_NOCONTROL);
          titre[i] = '\xB3';
          }

        // make sure its not the last one
        if ( lg > (i+1) ) 
          {
          gratcol = (x+i-1)*cellwidth;
          if (pList->SkinTitle.Ptr==NULL)
            {
            filzone((gratcol + (cellwidth/2) - 1),gratlin,1,grnblin,pList->ColorReliefTitleDown);
            filzone((gratcol + (cellwidth/2) + 1),gratlin,1,grnblin,pList->ColorReliefTitleUp);
            }
          else
            LookApplySkinButton( gratcol, gratlin, 1, grnblin, pList->SkinTitle.Ptr, CI_SKNF_L2C1 );

          k = i+1;
          }
        }
      else  
        {
        k=1;
        }
      }
    }

  if ((i - k) > 0) 
    TexPrintXY(pList->hFontTitle, x+k, y, (titre+k), (i-k), CI_ESC_NOCONTROL);

  // -------------------------------------------------------------------
  // - Restore
  // -------------------------------------------------------------------
  TexSetFGBG(HIBYTE(OldColors),LOBYTE(OldColors));

MI_TRACE_RETURN(CE_OK);
}

