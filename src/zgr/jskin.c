/** @pkg Staff.Fred.jSkin */ 
// ****************************************************************************
// * jSkin.c
// * Skin management
// ****************************************************************************

#if defined(__linux__) || defined(UNIX)
#include "wdef.h"
#else
#if defined(BDA_ABAL2)
#include "wdef.h"
#else
#include "bda.h"
#endif
#endif

#include "ztrace.h"
#include "jstdpsu.h"
#include"jguipix.h"
#include"zext.h"
#include"zint.h"
#include "zintctx.h"
#include"jskin.h"
#include"ztools.h"
#include"zglobal.h"
#include "zglobctx.h"

char  * helpskin=(char *) 0;
int   helpskins=0;


// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// - Internal Functions
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

WORD  FindSkinColor( char * sptr, int flags, int index )
{
WORD ret;
WORD i;
WORD Mask;
WORD Step = cellwidth * cellheight;

  Mask = 1;

  for (i=0 ; i<12 ; i++)
    {
    if ( flags & Mask )
      break;
    sptr += Step;
    Mask = Mask << 1;
    }

  ret = sptr[index];
  MI_TRACE((CI_TRA_INFO4,"SKIN","color %02X",ret));
  return ret;
}

VOID PutSkinInComponent( PTI_MEMORY pCompSkin, char * sptr, WORD IsDyn )
{
if (pCompSkin->Ptr!=NULL)
    ToolsReinitMemory(pCompSkin);
pCompSkin->Ptr   = sptr;
pCompSkin->IsDyn = IsDyn;
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// - External Functions
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------


// ****************************************************************************
/** zloadskin: 
    Loads skins from file

 * @param nptr     IN : file name
 * @return CE_OK
 * @author CCDoc Administrator
 */

// * VarGlob:
// *   g_pLook->xxxx
// ****************************************************************************
WORD zloadskin( char * nptr )
{
#ifdef TRACEON
  const char FAR PTR tfn="load";
#endif
  WORD skincol;
  WORD skinrow;
  WORD skintype;
  int skinskins;
  char *  sptr;
  FILE  * handle;
  int status = 0;
  int c;
  WORD  ret = 0;

  // ------------------------------------------------------------------
  // - Initialisation
  // ------------------------------------------------------------------

  // Open file
  if ((handle = fopen( nptr, "rb")) == (FILE *) 0) 
    return CE_ERR_FILEOPEN;

  // Verify ID
  if (!(   ((c = fgetc( handle )) == 's' )
       &&  ((c = fgetc( handle )) == 'K' )
       &&  ((c = fgetc( handle )) == 'n' )
       &&  ((c = fgetc( handle )) == '1' )
       &&  ((c = fgetc( handle )) == '1' )
       )
      )
      {
      fclose( handle );
      return CE_ERR_FILETYPE;
      }
 
  // Verify coherence with reference font
  skincol = fgetc( handle );
  skinrow = fgetc( handle );
  if (   (skincol != g_pTabFont->Font[g_pApp->hFontFixeRef].GrSize.cx)
     ||  (skinrow != g_pTabFont->Font[g_pApp->hFontFixeRef].GrSize.cy)
     )
      {
      fclose( handle );
      return CE_ERR_FILETYPE;
      }

  // ------------------------------------------------------------------
  // - Load skins
  // ------------------------------------------------------------------
  while ((skintype=fgetc( handle )) > 0) 
    {
    if (!(skinskins=fgetc( handle )))
      {
      // ?? void
      ret = CE_ERR;
      break;
      }

    else if (!(sptr = allocate((skinskins * skincol * skinrow))))
      {
      ret = CE_ERR_MEMORY;
      break;
      }

    else if ( (int)fread(sptr,(skincol * skinrow),skinskins,handle) != skinskins)
      {
      // ?? file broken
      ret = CE_ERR;
      break;
      }

    else  
      {
      switch ( skintype ) 
        {
        // ------------------------------------------------------------------------------
        // - Menu skins
        // ------------------------------------------------------------------------------
        case 0x21:  
          // Menu Horizontal
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Menu.SkinFrameH, sptr, TRUE);
          break;

        case 0x22:
          // Menu Vertical
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Menu.SkinFrameV, sptr, TRUE);

          g_pLook->Menu.ColorBGNormal   = FindSkinColor(g_pLook->Menu.SkinFrameV.Ptr, CI_SKNF_L2C2, 0);
          g_pLook->Menu.ColorBGSelected = FindSkinColor(g_pLook->Menu.SkinFrameV.Ptr, CI_SKNF_L4C2, 0);

          g_pLook->Menu.ColorFGNormal   = FindSkinColor(g_pLook->Menu.SkinFrameV.Ptr, CI_SKNF_L4C1, 0);
          g_pLook->Menu.ColorFGSelected = FindSkinColor(g_pLook->Menu.SkinFrameV.Ptr, CI_SKNF_L4C1, 1);
          g_pLook->Menu.ColorFGDisabled = FindSkinColor(g_pLook->Menu.SkinFrameV.Ptr, CI_SKNF_L4C1, 2);
          g_pLook->Menu.ColorFGHotKey   = FindSkinColor(g_pLook->Menu.SkinFrameV.Ptr, CI_SKNF_L4C1, 3);
          break;

        case 0x23:
          // Menu Line
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Menu.SkinLine, sptr, TRUE);
          break;

        case 0x24:
          // Menu Child arrow
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Menu.SkinChild, sptr, TRUE);
          break;

        // ------------------------------------------------------------------------------
        // - Input fields
        // ------------------------------------------------------------------------------
        case 0x31:
          // Input field on 1 line
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Input.SkinFrameH, sptr, TRUE);

          g_pLook->Input.ColorFGNormal    = FindSkinColor(g_pLook->Input.SkinFrameH.Ptr, CI_SKNF_L4C1, 0);
          g_pLook->Input.ColorFGSelected  = FindSkinColor(g_pLook->Input.SkinFrameH.Ptr, CI_SKNF_L4C1, 1);
          g_pLook->Input.ColorFGDisabled  = FindSkinColor(g_pLook->Input.SkinFrameH.Ptr, CI_SKNF_L4C1, 2);
          g_pLook->Input.ColorFGHidden    = FindSkinColor(g_pLook->Input.SkinFrameH.Ptr, CI_SKNF_L4C1, 3);

          g_pLook->Input.ColorBGNormal    = FindSkinColor(g_pLook->Input.SkinFrameH.Ptr, CI_SKNF_L4C2, 0);
          g_pLook->Input.ColorBGSelected  = FindSkinColor(g_pLook->Input.SkinFrameH.Ptr, CI_SKNF_L4C2, 1);
          g_pLook->Input.ColorBGDisabled  = FindSkinColor(g_pLook->Input.SkinFrameH.Ptr, CI_SKNF_L4C2, 2);
          g_pLook->Input.ColorBGHidden    = FindSkinColor(g_pLook->Input.SkinFrameH.Ptr, CI_SKNF_L4C2, 3);
        
 
          break;

        case 0x32:
          // Input field multi-line in normal look
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Input.SkinFrameBigNormal, sptr, TRUE);
          break;


        // ------------------------------------------------------------------------------
        // - Window skins
        // ------------------------------------------------------------------------------
        case 0x41:
          // Window frame with active title
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Window.SkinWithTitleActive, sptr, TRUE);

          g_pLook->Window.ColorFGNormal      = FindSkinColor(g_pLook->Window.SkinWithTitleActive.Ptr, CI_SKNF_L4C1, 0);
          g_pLook->Window.ColorBGNormal      = FindSkinColor(g_pLook->Window.SkinWithTitleActive.Ptr, CI_SKNF_L2C2, 0);
 
          g_pLook->Window.ColorFGTitleActive = FindSkinColor(g_pLook->Window.SkinWithTitleActive.Ptr, CI_SKNF_L4C2, 0);
          g_pLook->Window.ColorBGTitleActive = FindSkinColor(g_pLook->Window.SkinWithTitleActive.Ptr, CI_SKNF_L4C2, 1);
          break;

        case 0x42:
          // Window frame with inactive title
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Window.SkinWithTitleInactive, sptr, TRUE);

          g_pLook->Window.ColorFGTitleInactive = FindSkinColor(g_pLook->Window.SkinWithTitleInactive.Ptr, CI_SKNF_L4C2, 0);
          g_pLook->Window.ColorBGTitleInactive = FindSkinColor(g_pLook->Window.SkinWithTitleInactive.Ptr, CI_SKNF_L4C2, 1);
          break;

        case 0x43:
          // Window frame without title
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Window.SkinWithoutTitle, sptr, TRUE);
          break;

        case 0x44:
          // Window close button
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Window.SkinClose, sptr, TRUE);
          break;

        case 0x45:
          // Window help button
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Window.SkinHelp, sptr, TRUE);
          break;

        // ------------------------------------------------------------------------------
        // - Radio and check button
        // ------------------------------------------------------------------------------
        case 0x51:
          // Radio off
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Radio.SkinOff, sptr, TRUE);
          break;

        case 0x52:
          // Radio on
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Radio.SkinOn, sptr, TRUE);
          break;

        case 0x53:
          // Check off
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Check.SkinOff, sptr, TRUE);
          break;

        case 0x54:
          // Check on
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Check.SkinOn, sptr, TRUE);
          break;

        case 0x55:
          // Check on bis
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Check.SkinOn2, sptr, TRUE);
          break;

        // ------------------------------------------------------------------------------
        // - Combo
        // ------------------------------------------------------------------------------
        case 0x61:
          // Combo button
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Combo.SkinButton, sptr, TRUE);
          break;

        // ------------------------------------------------------------------------------
        // - Lists
        // ------------------------------------------------------------------------------
        case 0x71:
          // List frame
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->List.SkinFrame, sptr, TRUE);

          g_pLook->List.ColorFGLine   = FindSkinColor(g_pLook->List.SkinFrame.Ptr, CI_SKNF_L4C1, 0);
          g_pLook->List.ColorBGNormal = FindSkinColor(g_pLook->List.SkinFrame.Ptr, CI_SKNF_L2C2, 0);
          break;

        case 0x72:
          // List title
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->List.SkinTitle, sptr, TRUE);

          g_pLook->List.ColorFGTitle = FindSkinColor(g_pLook->List.SkinTitle.Ptr, CI_SKNF_L4C1, 0);
          g_pLook->List.ColorBGTitle = FindSkinColor(g_pLook->List.SkinTitle.Ptr, CI_SKNF_L4C2, 0);
          break;

        // ------------------------------------------------------------------------------
        // - Scroll bars
        // ------------------------------------------------------------------------------
        case 0x82:
          // Left button
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Scroll.SkinLeftBut, sptr, TRUE);
          break;

        case 0x83:
          // Right button
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Scroll.SkinRightBut, sptr, TRUE);
          break;

        case 0x84:
          // Up button
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Scroll.SkinUpBut, sptr, TRUE);
          break;

        case 0x85:
          // Down button
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Scroll.SkinDownBut, sptr, TRUE);
          break;

        case 0x86:
          // Page Up button
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Scroll.SkinPgUpBut, sptr, TRUE);
          break;

        case 0x87:
          // Page Down button
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Scroll.SkinPgDownBut, sptr, TRUE);
          break;

        case 0x88:
          // Top button
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Scroll.SkinTopBut, sptr, TRUE);
          break;

        case 0x89:
          // Bottom button
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Scroll.SkinBottomBut, sptr, TRUE);
          break;

        case 0x8A:
          // Horizontal bar normal
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Scroll.SkinHSliderNormal, sptr, TRUE);
          break;

        case 0x8B:
          // Horizontal bar disabled
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Scroll.SkinHSliderDisabled, sptr, TRUE);
          break;

        case 0x8C:
          // Vertical bar normal
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Scroll.SkinVSliderNormal, sptr, TRUE);

          g_pLook->Scroll.ColorFGSliderNormal = FindSkinColor(g_pLook->Scroll.SkinVSliderNormal.Ptr, CI_SKNF_L4C1, 0);
          g_pLook->Scroll.ColorBGSliderNormal = FindSkinColor(g_pLook->Scroll.SkinVSliderNormal.Ptr, CI_SKNF_L2C2, 0);
          break;

        case 0x8D:
          // Vertical bar disabled
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Scroll.SkinVSliderDisabled, sptr, TRUE);

          g_pLook->Scroll.ColorFGSliderDisabled = FindSkinColor(g_pLook->Scroll.SkinVSliderDisabled.Ptr, CI_SKNF_L4C1, 0);
          g_pLook->Scroll.ColorBGSliderDisabled = FindSkinColor(g_pLook->Scroll.SkinVSliderDisabled.Ptr, CI_SKNF_L2C2, 0);
          break;


        // ------------------------------------------------------------------------------
        // - Frames
        // ------------------------------------------------------------------------------
        case 0x91:
          // Status line
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Status.SkinLine, sptr, TRUE);

          g_pLook->Status.ColorFG = FindSkinColor(g_pLook->Status.SkinLine.Ptr, CI_SKNF_L4C1, 0);
          g_pLook->Status.ColorBG = FindSkinColor(g_pLook->Status.SkinLine.Ptr, CI_SKNF_L2C2, 0);
          break;

        // ------------------------------------------------------------------------------
        // - Buttons
        // ------------------------------------------------------------------------------
        case 0xA1:
          // Normal button
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Button.SkinButNormal, sptr, TRUE);

          g_pLook->Button.ColorFGButNormal = FindSkinColor(g_pLook->Button.SkinButNormal.Ptr, CI_SKNF_L4C1, 0);
          g_pLook->Button.ColorBGButNormal = FindSkinColor(g_pLook->Button.SkinButNormal.Ptr, CI_SKNF_L2C2, 0);
          break;

        case 0xA2:
          // Selected button
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Button.SkinButSelected, sptr, TRUE);

          g_pLook->Button.ColorFGButSelected = FindSkinColor(g_pLook->Button.SkinButSelected.Ptr, CI_SKNF_L4C1, 0);
          g_pLook->Button.ColorBGButSelected = FindSkinColor(g_pLook->Button.SkinButSelected.Ptr, CI_SKNF_L2C2, 0);
          break;

        case 0xA3:
          // Disabled button
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Button.SkinButDisabled, sptr, TRUE);

          g_pLook->Button.ColorFGButDisabled = FindSkinColor(g_pLook->Button.SkinButDisabled.Ptr, CI_SKNF_L4C1, 0);
          g_pLook->Button.ColorBGButDisabled = FindSkinColor(g_pLook->Button.SkinButDisabled.Ptr, CI_SKNF_L2C2, 0);
          break;

        case 0xA4:
          // Pushed button
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Button.SkinButPushed, sptr, TRUE);
          break;

        case 0xA5:
          // Normal middle button
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Button.SkinBut2Normal, sptr, TRUE);
          break;

        case 0xA6:
          // Selected middle button
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Button.SkinBut2Selected, sptr, TRUE);
          break;

        case 0xA7:
          // Disabled middle button
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Button.SkinBut2Disabled, sptr, TRUE);
          break;

        case 0xA8:
          // Pushed middle button
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Button.SkinBut2Pushed, sptr, TRUE);
          break;

        case 0xA9:
          // Small button
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Button.SkinSmall, sptr, TRUE);
          break;

        case 0xAA:
          // Tabview frame
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Button.SkinTabviewFrame, sptr, TRUE);

          g_pLook->Button.ColorFGTabFront    = FindSkinColor(g_pLook->Button.SkinTabviewFrame.Ptr, CI_SKNF_L4C1, 0);
          g_pLook->Button.ColorFGTabBack     = FindSkinColor(g_pLook->Button.SkinTabviewFrame.Ptr, CI_SKNF_L4C1, 1);
          g_pLook->Button.ColorFGTabDisabled = FindSkinColor(g_pLook->Button.SkinTabviewFrame.Ptr, CI_SKNF_L4C1, 2);
          g_pLook->Button.ColorFGTabSelected = FindSkinColor(g_pLook->Button.SkinTabviewFrame.Ptr, CI_SKNF_L4C1, 3);

          g_pLook->Button.ColorBGTabFront    = FindSkinColor(g_pLook->Button.SkinTabviewFrame.Ptr, CI_SKNF_L4C2, 0);
          g_pLook->Button.ColorBGTabBack     = FindSkinColor(g_pLook->Button.SkinTabviewFrame.Ptr, CI_SKNF_L4C2, 1);
          g_pLook->Button.ColorBGTabDisabled = FindSkinColor(g_pLook->Button.SkinTabviewFrame.Ptr, CI_SKNF_L4C2, 2);
          g_pLook->Button.ColorBGTabSelected = FindSkinColor(g_pLook->Button.SkinTabviewFrame.Ptr, CI_SKNF_L4C2, 3);
          break;

        case 0xAB:
          // Horizontal tabview
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Button.SkinHTabview, sptr, TRUE);
          break;

        case 0xAC:
          // Vertical tabview
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Button.SkinVTabview, sptr, TRUE);
          break;

        // ------------------------------------------------------------------------------
        // - Frames
        // ------------------------------------------------------------------------------
        case 0xB1:
          // Outset frame
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Frame.SkinOutset, sptr, TRUE);

          g_pLook->Frame.ColorFG = FindSkinColor(g_pLook->Frame.SkinOutset.Ptr, CI_SKNF_L4C1, 0);
          g_pLook->Frame.ColorBG = FindSkinColor(g_pLook->Frame.SkinOutset.Ptr, CI_SKNF_L4C2, 0);
          break;

        case 0xB2:
          // Inset frame
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Frame.SkinInset, sptr, TRUE);
          break;

        case 0xB3:
          // Outset horizontal line
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Frame.SkinRidgeLineH, sptr, TRUE);
          break;

        case 0xB4:
          // Inset horizontal line
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Frame.SkinGrooveLineH, sptr, TRUE);
          break;

        case 0xB5:
          // Outset vertical line
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Frame.SkinRidgeLineV, sptr, TRUE);
          break;

        case 0xB6:
          // Inset vertical line
          MI_TRACE((CI_TRA_INFO4,"SKIN","%02X",skintype));
          PutSkinInComponent( &g_pLook->Frame.SkinGrooveLineV, sptr, TRUE);
          break;

        default   :
          sptr = liberate( sptr );
        }
      }
    }
  
  fclose( handle );
  return ret;

}

// ****************************************************************************
/** apply_skin: 

 * @param 
 * @return nothing
 * @author CCDoc Administrator
 */

// * VarGlob:
// ****************************************************************************
void  apply_skin( int atcol , int atlin, int nbcol, int nblin, char * sptr, int flags )
{
  int i;
  int l;
  int x;
  int y;
  int z;
WORD  FlagCol1;
WORD  FlagCol2;
WORD  FlagCol3;

  if (nblin==cellheight)
    {
    // ---------------------------------------------------------------------
    // - Just 1 line
    // - The skin can begin at each line, depends on flags
    // ---------------------------------------------------------------------
    MI_TRACE((CI_TRA_INFO4,"SKIN","apply 1 line %04X",flags));

    if      (flags==CI_SKNF_3ZONES)
      {
    MI_TRACE((CI_TRA_INFO4,"SKIN","apply top"));
      FlagCol1 = CI_SKNF_L1C1;
      FlagCol2 = CI_SKNF_L1C2;
      FlagCol3 = CI_SKNF_L1C3;
      }
    else if (flags==CI_SKNF_3ZONES_MIDDLE)
      {
    MI_TRACE((CI_TRA_INFO4,"SKIN","apply mid"));
      FlagCol1 = CI_SKNF_L2C1;
      FlagCol2 = CI_SKNF_L2C2;
      FlagCol3 = CI_SKNF_L2C3;
      sptr += (cellwidth * cellheight * 3);
      }
    else if (flags==CI_SKNF_3ZONES_BOTTOM)
      {
    MI_TRACE((CI_TRA_INFO4,"SKIN","apply bot"));
      FlagCol1 = CI_SKNF_L3C1;
      FlagCol2 = CI_SKNF_L3C2;
      FlagCol3 = CI_SKNF_L3C3;
      sptr += (cellwidth * cellheight * 6);
      }
    else if (flags==CI_SKNF_3ZONES_EXT)
      {
      MI_TRACE((CI_TRA_INFO4,"SKIN","apply ext"));
      FlagCol1 = CI_SKNF_L4C1;
      FlagCol2 = CI_SKNF_L4C2;
      FlagCol3 = CI_SKNF_L4C3;
      sptr += (cellwidth * cellheight * 9);
      }
    else
      return;  

    // Left
    if ( flags & FlagCol1 )
      mixzone( atcol, atlin, cellwidth, cellheight, sptr );
  
    // Middles
    sptr += (cellwidth * cellheight);
    for ( i=cellwidth, l=(nbcol-cellwidth); i < l; i += cellwidth )
      if ( flags & FlagCol2 )
        mixzone( atcol+i, atlin, cellwidth,cellheight,sptr);
  
    // Right
    sptr += (cellwidth * cellheight);
    if ( flags & FlagCol3 )
      mixzone( atcol+i, atlin, cellwidth, cellheight, sptr );

    return;
    }

  else
    {
    // ---------------------------------------------------------------------
    // - More than 1 line
    // - The skin must begin at the 1st line
    // - can be a 9 zones
    // ---------------------------------------------------------------------
    MI_TRACE((CI_TRA_INFO4,"SKIN","apply multi-line %04X",flags));

    // Top Left
    if ( flags & CI_SKNF_L1C1 )
      mixzone( atcol, atlin, cellwidth, cellheight, sptr );
  
    // Top middles
    sptr += (cellwidth * cellheight);
    for ( i=cellwidth, l=(nbcol-cellwidth); i < l; i += cellwidth )
      if ( flags & CI_SKNF_L1C2 )
        mixzone( atcol+i, atlin, cellwidth,cellheight,sptr);
  
    // Top right
    sptr += (cellwidth * cellheight);
    if ( flags & CI_SKNF_L1C3 )
      mixzone( atcol+i, atlin, cellwidth, cellheight, sptr );
  
  
    if (!( flags & 0x01F8 ))
      return;

    sptr += (cellwidth * cellheight);

      // --- Loop on 2nde line (if more than 2 lines) 
      for (x=cellheight, y=(nblin-cellheight); x < y; x+= cellheight) 
        {
        /* Center Left */
        if ( flags & CI_SKNF_L2C1 )
          mixzone( atcol, atlin+x, cellwidth, cellheight, sptr );
        z = (cellwidth * cellheight);
        for ( i=cellwidth, l=(nbcol-cellwidth); i < l; i += cellwidth )
          if ( flags & CI_SKNF_L2C2 )
            mixzone( atcol+i, atlin+x,   cellwidth, cellheight, sptr+z );
        z *= 2;
        if ( flags & CI_SKNF_L2C3 )
          mixzone( atcol+i, atlin+x, cellwidth, cellheight, (sptr+z) );
        }
    
    /* bottom left */
    sptr += (cellwidth * cellheight * 3);
    if ( flags & CI_SKNF_L3C1 )
      mixzone( atcol, atlin+x, cellwidth, cellheight, sptr );
  
    /* bottom middles */
    sptr += (cellwidth * cellheight);
    for ( i=cellwidth, l=(nbcol-cellwidth); i < l; i += cellwidth )
      if ( flags & CI_SKNF_L3C2 )
        mixzone( atcol+i, atlin+x, cellwidth,cellheight,sptr);
  
    /* bottom right */
    sptr += (cellwidth * cellheight);
    if ( flags & CI_SKNF_L3C3 )
      mixzone( atcol+i, atlin+x, cellwidth, cellheight, sptr );
    }
  
  return;

}

void  apply_skinButton( int atcol , int atlin, int nbcol, int nblin, char * sptr, int flags )
{
WORD i;
WORD Mask;
WORD grx;

  grx = atcol;
  Mask = 1;

  for (i=0 ; i<12 ; i++)
    {
    if ( flags & Mask )
      {
      mixzone( grx, atlin, cellwidth, cellheight, sptr );
      grx += cellwidth;
      }
    sptr += (cellwidth * cellheight);
    Mask = Mask << 1;
    }
}

