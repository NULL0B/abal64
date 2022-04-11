/** @pkg Staff.Fred.jSkin */ 
// ****************************************************************************
// * zLooSkin.c
// * Included in zLook module
// * Skin and drawing management
// ****************************************************************************

struct standard_image * palette_gif_loader( char * filename );

// --- Ligne d'un modele
typedef struct
{
unsigned char*  left;
unsigned char*  center;
unsigned char*  right;
} TI_LINE, *PTI_LINE;

// --- Modèle complet
typedef struct
{
unsigned char   Id;
TI_LINE top;
TI_LINE mid;
TI_LINE bot;
TI_LINE ext;
} TI_MODEL, * PTI_MODEL;

#define NBSKIN	52

typedef struct
{
	WORD Id;
	char Name[40];
} TI_SKINFILE;

static TI_SKINFILE TabSkin[NBSKIN] = 
{ 
0xA7 , "But2Dis.gif"  ,     
0xA5 , "But2Norm.gif" ,    
0xA8 , "But2Push.gif" ,    
0xA6 , "But2Sel.gif"  ,     
0xA3 , "ButDis.gif"   ,      
0xA1 , "ButNorm.gif"  ,     
0xA4 , "ButPush.gif"  ,     
0xA2 , "ButSel.gif"   ,      
0xA9 , "ButSml.gif"   ,      
0x53 , "ChkOff.gif"   ,      
0x54 , "ChkOn.gif"    ,       
0x55 , "ChkOnBis.gif" ,    
0x61 , "Combo.gif"    ,       
0xB2 , "FraIn.gif"    ,       
0xB1 , "FraOut.gif"   ,      
0x31 , "InpH.gif"     ,        
0x32 , "InpNorm.gif"  ,     
0xB4 , "LinInH.gif"   ,      
0xB6 , "LinInV.gif"   ,      
0xB3 , "LinOutH.gif"  ,     
0xB5 , "LinOutV.gif"  ,     
0x71 , "LisNorm.gif"  ,     
0x72 , "LisTitle.gif" ,    
0x24 , "MenChild.gif" ,    
0x21 , "MenH.gif"     ,        
0x23 , "MenLine.gif"  ,     
0x22 , "MenV.gif"     ,        
0x51 , "RadOff.gif"   ,      
0x52 , "RadOn.gif"    ,        
0x89 , "ScrBBot.gif"  ,     
0x85 , "ScrBDn.gif"   ,      
0x82 , "ScrBLeft.gif" ,    
0x87 , "ScrBPgDn.gif" ,    
0x86 , "ScrBPgUp.gif" ,    
0x83 , "ScrBRigh.gif" ,    
0x88 , "ScrBTop.gif"  ,     
0x84 , "ScrBUp.gif"   ,      
0x8B , "ScrSHDis.gif" ,    
0x8A , "ScrSHNor.gif" ,    
0x8D , "ScrSVDis.gif" ,    
0x8C , "ScrSVNor.gif" ,    
0x91 , "Status.gif"   ,      
0xAA , "TabvFram.gif" ,    
0xAB , "TabvH.gif"    ,       
0xAC , "TabvV.gif"    ,       
0x62 , "Variator.gif" ,    
0x41 , "WinAct.gif"   ,      
0x44 , "WinClose.gif" ,    
0x45 , "WinHelp.gif"  ,     
0x42 , "WinInact.gif" ,    
0x43 , "WinNotit.gif" ,
0x00 , ""    
};

char  * helpskin=(char *) 0;
int   helpskins=0;



// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// - Internal Functions Dynamic Skin (intégration de l'utilitaire makeskin)
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------



// ****************************************************************************************
// * AllocCar /  FreeCar
// ****************************************************************************************
static BOOL AllocCar( unsigned char ** pCar, WORD RefH, WORD RefV)
{
int NbPixels = RefH * RefV;
*pCar = allocate(NbPixels);
return (*pCar!=NULL);
}

static void FreeCar( unsigned char ** pCar )
{
if (*pCar==NULL)
  return;
liberate( *pCar );
*pCar = NULL;
}

// ****************************************************************************************
// * AllocLine  /  FreeLine
// ****************************************************************************************
static void FreeLine( PTI_LINE pLine )
{
FreeCar(&pLine->left);
FreeCar(&pLine->center);
FreeCar(&pLine->right);
}

static BOOL AllocLine( PTI_LINE pLine, WORD RefH, WORD RefV)
{
BOOL IsOk= TRUE;
 
IsOk &= AllocCar(&pLine->left, RefH, RefV);
IsOk &= AllocCar(&pLine->center, RefH, RefV);
IsOk &= AllocCar(&pLine->right, RefH, RefV);
    
if (!IsOk)
  FreeLine(pLine);

return IsOk;    
}

// ****************************************************************************************
// * AllocModel  /  FreeModel
// ****************************************************************************************
void FreeModel( PTI_MODEL pModel)
{
FreeLine(&pModel->top);
FreeLine(&pModel->mid);
FreeLine(&pModel->bot);
FreeLine(&pModel->ext);
}

BOOL  AllocModel( PTI_MODEL pModel,  WORD RefH, WORD RefV )
{
BOOL IsOk= TRUE;

pModel->Id = 0;

IsOk &= AllocLine(&pModel->top, RefH, RefV);
IsOk &= AllocLine(&pModel->mid, RefH, RefV);
IsOk &= AllocLine(&pModel->bot, RefH, RefV);
IsOk &= AllocLine(&pModel->ext, RefH, RefV);
    
if (!IsOk)
  FreeModel(pModel);

return IsOk;    
}

// ****************************************************************************************
// * SerialiseSkinImage
// ****************************************************************************************
static WORD SerialiseSkinImage( unsigned char* pSkin, struct standard_image * iptr, WORD SkinId, WORD RefH, WORD RefV)
{
WORD r,ri;
int c;
int i;
char *  bptr;
TI_MODEL Model;

  if (!AllocModel( &Model, RefH, RefV))
	 return CE_ERR_MEMORY;

  ri=0;
  for ( r=0; r < RefV; r++ ) 
    {
    if ((bptr = connect_pixel_row( iptr->storage , (WORD)(r+ri))) == (char *) 0)
      return CE_ERR;
    for ( c=0; c < RefH; c++ ) Model.top.left  [(r*RefH)+c] = *(bptr+c);
    for ( c=0; c < RefH; c++ ) Model.top.center[(r*RefH)+c] = *(bptr+c+RefH);
    for ( c=0; c < RefH; c++ ) Model.top.right [(r*RefH)+c] = *(bptr+c+2*RefH);
    }

  ri+=RefV; 
  for ( r=0; r < RefV; r++ ) 
    {
    if ((bptr = connect_pixel_row( iptr->storage , (WORD)(r+ri))) == (char *) 0)
      return CE_ERR;
    for ( c=0; c < RefH; c++ ) Model.mid.left  [(r*RefH)+c] = *(bptr+c);
    for ( c=0; c < RefH; c++ ) Model.mid.center[(r*RefH)+c] = *(bptr+c+RefH);
    for ( c=0; c < RefH; c++ ) Model.mid.right [(r*RefH)+c] = *(bptr+c+2*RefH);
    }

  ri+=RefV; 
  for ( r=0; r < RefV; r++ ) 
    {
    if ((bptr = connect_pixel_row( iptr->storage , (WORD)(r+ri))) == (char *) 0)
      return CE_ERR;
    for ( c=0; c < RefH; c++ ) Model.bot.left  [(r*RefH)+c] = *(bptr+c);
    for ( c=0; c < RefH; c++ ) Model.bot.center[(r*RefH)+c] = *(bptr+c+RefH);
    for ( c=0; c < RefH; c++ ) Model.bot.right [(r*RefH)+c] = *(bptr+c+2*RefH);
    }

  ri+=RefV; 
  for ( r=0; r < RefV; r++ ) 
    {
    if ((bptr = connect_pixel_row( iptr->storage , (WORD)(r+ri))) == (char *) 0)
      return CE_ERR;
    for ( c=0; c < RefH; c++ ) Model.ext.left  [(r*RefH)+c]=*(bptr+c);
    for ( c=0; c < RefH; c++ ) Model.ext.center[(r*RefH)+c]=*(bptr+c+RefH);
    for ( c=0; c < RefH; c++ ) Model.ext.right [(r*RefH)+c]=*(bptr+c+2*RefH);
    }

    for (i=0; i < (RefH*RefV); i++ ) *pSkin++ = Model.top.left  [i];
    for (i=0; i < (RefH*RefV); i++ ) *pSkin++ = Model.top.center[i];
    for (i=0; i < (RefH*RefV); i++ ) *pSkin++ = Model.top.right [i];
    for (i=0; i < (RefH*RefV); i++ ) *pSkin++ = Model.mid.left  [i];
    for (i=0; i < (RefH*RefV); i++ ) *pSkin++ = Model.mid.center[i];
    for (i=0; i < (RefH*RefV); i++ ) *pSkin++ = Model.mid.right [i];
    for (i=0; i < (RefH*RefV); i++ ) *pSkin++ = Model.bot.left  [i];
    for (i=0; i < (RefH*RefV); i++ ) *pSkin++ = Model.bot.center[i];
    for (i=0; i < (RefH*RefV); i++ ) *pSkin++ = Model.bot.right [i];
    for (i=0; i < (RefH*RefV); i++ ) *pSkin++ = Model.ext.left  [i];
    for (i=0; i < (RefH*RefV); i++ ) *pSkin++ = Model.ext.center[i];
    for (i=0; i < (RefH*RefV); i++ ) *pSkin++ = Model.ext.right [i];

  FreeModel( &Model);
  return CE_OK;
}



// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// - Internal Functions
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------



// ****************************************************************************
/** FindSkinColor
    Find a color in skin

 * @param 
 * @return
 * @author
 */
// * VarGlob: 
// ****************************************************************************
WORD  FindSkinColor( char * sptr, int flags, int index )
{
MI_TRACE_DCL_TFN("FindSkinColor");
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
  MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"color %02X",ret));
  return ret;
}

// ****************************************************************************
/** PutSkinInComponent
    Copy a skin in a component

 * @param 
 * @return
 * @author
 */
// * VarGlob: 
// ****************************************************************************
VOID PutSkinInComponent( PTI_MEMORY pCompSkin, char * sptr, WORD IsDyn )
{
if (pCompSkin->Ptr!=NULL)
    ToolsReinitMemory(pCompSkin);

pCompSkin->Ptr   = sptr;
pCompSkin->IsDyn = IsDyn;
}

// ****************************************************************************
/** PutSkinInComponent
    Copy a skin in a component

 * @param 
 * @return
 * @author
 */
// * VarGlob: 
// ****************************************************************************
VOID PutSkin( char * sptr, WORD skintype )
{
MI_TRACE_DCL_TFN("PutSkin");
switch ( skintype )
  {
  // ------------------------------------------------------------------------------
  // - Menu skins
  // ------------------------------------------------------------------------------
  case 0x21:  
    // Menu Horizontal
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Menu.SkinFrameH, sptr, TRUE);
    break;

  case 0x22:
    // Menu Vertical
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
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
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Menu.SkinLine, sptr, TRUE);
    break;

  case 0x24:
    // Menu Child arrow
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Menu.SkinChild, sptr, TRUE);
    break;

  // ------------------------------------------------------------------------------
  // - Input fields
  // ------------------------------------------------------------------------------
  case 0x31:
    // Input field on 1 line
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
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
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Input.SkinFrameBigNormal, sptr, TRUE);
    break;


  // ------------------------------------------------------------------------------
  // - Window skins
  // ------------------------------------------------------------------------------
  case 0x41:
    // Window frame with active title
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Window.SkinWithTitleActive, sptr, TRUE);

    g_pLook->Window.ColorFGNormal      = FindSkinColor(g_pLook->Window.SkinWithTitleActive.Ptr, CI_SKNF_L4C1, 0);
    g_pLook->Window.ColorBGNormal      = FindSkinColor(g_pLook->Window.SkinWithTitleActive.Ptr, CI_SKNF_L2C2, 0);

    g_pLook->Window.ColorFGTitleActive = FindSkinColor(g_pLook->Window.SkinWithTitleActive.Ptr, CI_SKNF_L4C2, 0);
    g_pLook->Window.ColorBGTitleActive = FindSkinColor(g_pLook->Window.SkinWithTitleActive.Ptr, CI_SKNF_L4C2, 1);
    break;

  case 0x42:
    // Window frame with inactive title
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Window.SkinWithTitleInactive, sptr, TRUE);

    g_pLook->Window.ColorFGTitleInactive = FindSkinColor(g_pLook->Window.SkinWithTitleInactive.Ptr, CI_SKNF_L4C2, 0);
    g_pLook->Window.ColorBGTitleInactive = FindSkinColor(g_pLook->Window.SkinWithTitleInactive.Ptr, CI_SKNF_L4C2, 1);
    break;

  case 0x43:
    // Window frame without title
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Window.SkinWithoutTitle, sptr, TRUE);
    break;

  case 0x44:
    // Window close button
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Window.SkinClose, sptr, TRUE);
    break;

  case 0x45:
    // Window help button
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Window.SkinHelp, sptr, TRUE);
    break;

  // ------------------------------------------------------------------------------
  // - Radio and check button
  // ------------------------------------------------------------------------------
  case 0x51:
    // Radio off
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Radio.SkinOff, sptr, TRUE);
    break;

  case 0x52:
    // Radio on
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Radio.SkinOn, sptr, TRUE);
    break;

  case 0x53:
    // Check off
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Check.SkinOff, sptr, TRUE);
    break;

  case 0x54:
    // Check on
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Check.SkinOn, sptr, TRUE);
    break;

  case 0x55:
    // Check on bis
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Check.SkinOn2, sptr, TRUE);
    break;

  // ------------------------------------------------------------------------------
  // - Combo
  // ------------------------------------------------------------------------------
  case 0x61:
    // Combo button
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Combo.SkinButton, sptr, TRUE);
    break;

  case 0x62:
    // Variator button
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Variator.SkinVar, sptr, TRUE);
    break;

  // ------------------------------------------------------------------------------
  // - Lists
  // ------------------------------------------------------------------------------
  case 0x71:
    // List frame
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->List.SkinFrame, sptr, TRUE);

    g_pLook->List.ColorFGLine   = FindSkinColor(g_pLook->List.SkinFrame.Ptr, CI_SKNF_L4C1, 0);
    g_pLook->List.ColorBGNormal = FindSkinColor(g_pLook->List.SkinFrame.Ptr, CI_SKNF_L2C2, 0);
    break;

  case 0x72:
    // List title
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->List.SkinTitle, sptr, TRUE);

    g_pLook->List.ColorFGTitle = FindSkinColor(g_pLook->List.SkinTitle.Ptr, CI_SKNF_L4C1, 0);
    g_pLook->List.ColorBGTitle = FindSkinColor(g_pLook->List.SkinTitle.Ptr, CI_SKNF_L4C2, 0);
    break;

  // ------------------------------------------------------------------------------
  // - Scroll bars
  // ------------------------------------------------------------------------------
  case 0x82:
    // Left button
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Scroll.SkinLeftBut, sptr, TRUE);
    break;

  case 0x83:
    // Right button
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Scroll.SkinRightBut, sptr, TRUE);
    break;

  case 0x84:
    // Up button
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Scroll.SkinUpBut, sptr, TRUE);
    break;

  case 0x85:
    // Down button
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Scroll.SkinDownBut, sptr, TRUE);
    break;

  case 0x86:
    // Page Up button
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Scroll.SkinPgUpBut, sptr, TRUE);
    break;

  case 0x87:
    // Page Down button
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Scroll.SkinPgDownBut, sptr, TRUE);
    break;

  case 0x88:
    // Top button
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Scroll.SkinTopBut, sptr, TRUE);
    break;

  case 0x89:
    // Bottom button
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Scroll.SkinBottomBut, sptr, TRUE);
    break;

  case 0x8A:
    // Horizontal bar normal
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Scroll.SkinHSliderNormal, sptr, TRUE);
    break;

  case 0x8B:
    // Horizontal bar disabled
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Scroll.SkinHSliderDisabled, sptr, TRUE);
    break;

  case 0x8C:
    // Vertical bar normal
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Scroll.SkinVSliderNormal, sptr, TRUE);

    g_pLook->Scroll.ColorFGSliderNormal   = FindSkinColor(g_pLook->Scroll.SkinVSliderNormal.Ptr, CI_SKNF_L4C1, 0);
    g_pLook->Scroll.ColorBGSliderNormal   = FindSkinColor(g_pLook->Scroll.SkinVSliderNormal.Ptr, CI_SKNF_L4C1, 1);

    g_pLook->Scroll.ColorReliefSliderUp   = FindSkinColor(g_pLook->Scroll.SkinVSliderNormal.Ptr, CI_SKNF_L4C1, 2);
    g_pLook->Scroll.ColorReliefSliderDown = FindSkinColor(g_pLook->Scroll.SkinVSliderNormal.Ptr, CI_SKNF_L4C1, 3);
    break;

  case 0x8D:
    // Vertical bar disabled
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Scroll.SkinVSliderDisabled, sptr, TRUE);

    g_pLook->Scroll.ColorFGSliderDisabled = FindSkinColor(g_pLook->Scroll.SkinVSliderDisabled.Ptr, CI_SKNF_L4C1, 0);
    g_pLook->Scroll.ColorBGSliderDisabled = FindSkinColor(g_pLook->Scroll.SkinVSliderDisabled.Ptr, CI_SKNF_L4C1, 1);
    break;


  // ------------------------------------------------------------------------------
  // - Status
  // ------------------------------------------------------------------------------
  case 0x91:
    // Status line
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Status.SkinLine, sptr, TRUE);

    g_pLook->Status.ColorFG = FindSkinColor(g_pLook->Status.SkinLine.Ptr, CI_SKNF_L4C1, 0);
    g_pLook->Status.ColorBG = FindSkinColor(g_pLook->Status.SkinLine.Ptr, CI_SKNF_L2C2, 0);
    break;

  // ------------------------------------------------------------------------------
  // - Buttons
  // ------------------------------------------------------------------------------
  case 0xA1:
    // Normal button
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Button.SkinButNormal, sptr, TRUE);

    g_pLook->Button.ColorFGButNormal = FindSkinColor(g_pLook->Button.SkinButNormal.Ptr, CI_SKNF_L4C1, 0);
    g_pLook->Button.ColorBGButNormal = FindSkinColor(g_pLook->Button.SkinButNormal.Ptr, CI_SKNF_L2C2, 0);
    break;

  case 0xA2:
    // Selected button
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Button.SkinButSelected, sptr, TRUE);

    g_pLook->Button.ColorFGButSelected = FindSkinColor(g_pLook->Button.SkinButSelected.Ptr, CI_SKNF_L4C1, 0);
    g_pLook->Button.ColorBGButSelected = FindSkinColor(g_pLook->Button.SkinButSelected.Ptr, CI_SKNF_L2C2, 0);
    break;

  case 0xA3:
    // Disabled button
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Button.SkinButDisabled, sptr, TRUE);

    g_pLook->Button.ColorFGButDisabled = FindSkinColor(g_pLook->Button.SkinButDisabled.Ptr, CI_SKNF_L4C1, 0);
    g_pLook->Button.ColorBGButDisabled = FindSkinColor(g_pLook->Button.SkinButDisabled.Ptr, CI_SKNF_L2C2, 0);
    break;

  case 0xA4:
    // Pushed button
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Button.SkinButPushed, sptr, TRUE);
    break;

  case 0xA5:
    // Normal middle button
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Button.SkinBut2Normal, sptr, TRUE);
    break;

  case 0xA6:
    // Selected middle button
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Button.SkinBut2Selected, sptr, TRUE);
    break;

  case 0xA7:
    // Disabled middle button
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Button.SkinBut2Disabled, sptr, TRUE);
    break;

  case 0xA8:
    // Pushed middle button
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Button.SkinBut2Pushed, sptr, TRUE);
    break;

  case 0xA9:
    // Small button
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Button.SkinSmall, sptr, TRUE);
    break;

  case 0xAA:
    // Tabview frame
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
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
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Button.SkinHTabview, sptr, TRUE);
    break;

  case 0xAC:
    // Vertical tabview
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Button.SkinVTabview, sptr, TRUE);
    break;

  // ------------------------------------------------------------------------------
  // - Frames
  // ------------------------------------------------------------------------------
  case 0xB1:
    // Outset frame
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Frame.SkinOutset, sptr, TRUE);

    g_pLook->Frame.ColorFG = FindSkinColor(g_pLook->Frame.SkinOutset.Ptr, CI_SKNF_L4C1, 0);
    g_pLook->Frame.ColorBG = FindSkinColor(g_pLook->Frame.SkinOutset.Ptr, CI_SKNF_L4C2, 0);
    break;

  case 0xB2:
    // Inset frame
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Frame.SkinInset, sptr, TRUE);
    break;

  case 0xB3:
    // Outset horizontal line
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Frame.SkinRidgeLineH, sptr, TRUE);
    break;

  case 0xB4:
    // Inset horizontal line
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Frame.SkinGrooveLineH, sptr, TRUE);
    break;

  case 0xB5:
    // Outset vertical line
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Frame.SkinRidgeLineV, sptr, TRUE);
    break;

  case 0xB6:
    // Inset vertical line
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%02X",skintype));
    PutSkinInComponent( &g_pLook->Frame.SkinGrooveLineV, sptr, TRUE);
    break;

  default   :
    sptr = liberate( sptr );
  }
}



// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// - External Functions
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------



// ****************************************************************************
/** LookLoadSkinByImages: 
    Loads skins directly from images, without skin file

 * @return CE_OK
 * @author CCDoc Administrator
 */

// * VarGlob:
// *   g_pLook->xxxx
// ****************************************************************************
WORD LookLoadSkinByImages()
{
MI_TRACE_DCL_TFN("LookLoadSkinByImages");
WORD skincol;
WORD skinrow;
int i;
struct standard_image * iptr=(struct standard_image *) 0;
CHAR  PathFile[CI_MAXPATH];
char *  sptr;
WORD  ret = 0;

	// ------------------------------------------------------------------
	// - Initialisation
	// ------------------------------------------------------------------
	skincol = g_pTabFont->Font[g_pApp->hFontFixeRef].GrSize.cx;
   skinrow = g_pTabFont->Font[g_pApp->hFontFixeRef].GrSize.cy;

	// ------------------------------------------------------------------
	// - Load skins
	// ------------------------------------------------------------------
	for( i =0 ; i < NBSKIN ; i++)
		{
		if (ToolsFindFile(PathFile, TabSkin[i].Name, g_pApp->PathLook)==CE_OK)
			{
			iptr = palette_gif_loader(PathFile);
			if ((iptr) && (iptr->columns == skincol*3) && (iptr->rows == skinrow*4))
				{
				if (!(sptr = allocate(skincol * skinrow * 12)))
					return CE_ERR_MEMORY;

				ret = SerialiseSkinImage( sptr, iptr, TabSkin[i].Id, skincol, skinrow);
				if (ret!=CE_OK)
					{
					liberate(sptr);
					return ret;
					}

				PutSkin( sptr, TabSkin[i].Id);
				}
			}
		}

	return CE_OK;
}

// ****************************************************************************
/** LookLoadSkin: 
    Loads skins from file

 * @param nptr     IN : file name
 * @return CE_OK
 * @author CCDoc Administrator
 */

// * VarGlob:
// *   g_pLook->xxxx
// ****************************************************************************
WORD LookLoadSkin( char * nptr )
{
  MI_TRACE_DCL_TFN("LoadSkin");
  WORD skincol;
  WORD skinrow;
  WORD skintype;
  int skinskins;
  char *  sptr;
  FILE  * handle;
  int c,c1,c2,i;
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
       )
      )
      {
      fclose( handle );
      return CE_ERR_FILETYPE;
      }

  c1 = fgetc( handle );
  c2 = fgetc( handle );
 
  // Verify VersionID
  if ((c1=='1') && (c2=='2'))
      {
      // Version 12 = with comments header
      // Skip header
      for (i=5 ; i<0x40; i++)
        c = fgetc(handle);
      }

  else if ((c1=='1') && (c2=='1'))
      {
      // Version 11 = without header
      // do nothing
      }
  else
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
		liberate(sptr);
      ret = CE_ERR;
      break;
      }

    else  
		PutSkin( sptr, skintype);
    }

  fclose( handle );
  return ret;

}

// ****************************************************************************
// * ConvertSkin: 
// ****************************************************************************
static char*  ConvertSkin( char* dptr, char* sptr, int lg )
{
#if defined (BDA_UNIX) || defined(BDA_WIN32)
// UseIt-Windows
// FCH27032006 Prise en compte mode palette/truecolor

	int	 pixelsize;
	int	 i;

	if (!get_pixel_format())
		{
		pixelsize = get_pixel_size();
		for( i=0 ; i<lg ; i++)
			{
			if (sptr[i])
				put_palette_pixel( &dptr[i*pixelsize], sptr[i]);
			else
				put_logical_pixel( &dptr[i*pixelsize], 0, 0, 0 );
			}
		return dptr;
		}
	else
		return sptr;
 
#else

	return sptr;

#endif
}

// ****************************************************************************
/** LookApplySkin: 

 * @param 
 * @return nothing
 * @author CCDoc Administrator
 */

// * VarGlob:
// ****************************************************************************
void  LookApplySkin( int atcol , int atlin, int nbcol, int nblin, char * sptr, int flags )
{
MI_TRACE_DCL_TFN("ApplySkin");
int i;
int l;
int x;
int y;
int z;
WORD  FlagCol1;
WORD  FlagCol2;
WORD  FlagCol3;
char* dptr = NULL;
char* p;

#if defined (BDA_UNIX) || defined(BDA_WIN32)
// UseIt-Windows
// FCH27032006 Prise en compte mode palette/truecolor
  if (!get_pixel_format())
	 {
	 dptr = allocate(cellwidth * cellheight  * get_pixel_size());
	 if (!dptr)
		{
	   MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"err mem"));
		return;
		}
	 }
#endif

  if (nblin==cellheight)
    {
    // ---------------------------------------------------------------------
    // - Just 1 line
    // - The skin can begin at each line, depends on flags
    // ---------------------------------------------------------------------
    MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"apply 1 line %04X",flags));

    if      (flags==CI_SKNF_3ZONES)
      {
      MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"apply top"));
      FlagCol1 = CI_SKNF_L1C1;
      FlagCol2 = CI_SKNF_L1C2;
      FlagCol3 = CI_SKNF_L1C3;
      }
    else if (flags==CI_SKNF_3ZONES_MIDDLE)
      {
      MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"apply mid"));
      FlagCol1 = CI_SKNF_L2C1;
      FlagCol2 = CI_SKNF_L2C2;
      FlagCol3 = CI_SKNF_L2C3;
      sptr += (cellwidth * cellheight * 3);
      }
    else if (flags==CI_SKNF_3ZONES_BOTTOM)
      {
      MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"apply bot"));
      FlagCol1 = CI_SKNF_L3C1;
      FlagCol2 = CI_SKNF_L3C2;
      FlagCol3 = CI_SKNF_L3C3;
      sptr += (cellwidth * cellheight * 6);
      }
    else if (flags==CI_SKNF_3ZONES_EXT)
      {
      MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"apply ext"));
      FlagCol1 = CI_SKNF_L4C1;
      FlagCol2 = CI_SKNF_L4C2;
      FlagCol3 = CI_SKNF_L4C3;
      sptr += (cellwidth * cellheight * 9);
      }
    else
	   {
		liberate(dptr);
      return;  
		}

    // Left
	 p = ConvertSkin(dptr,sptr,cellwidth * cellheight);
    if ( flags & FlagCol1 )
      mixzone( atcol, atlin, cellwidth, cellheight, p );
  
    // Middles
    sptr += (cellwidth * cellheight);
	 p = ConvertSkin(dptr,sptr,cellwidth * cellheight);
    for ( i=cellwidth, l=(nbcol-cellwidth); i < l; i += cellwidth )
      if ( flags & FlagCol2 )
        mixzone( atcol+i, atlin, cellwidth,cellheight,p);
  
    // Right
    sptr += (cellwidth * cellheight);
	 p = ConvertSkin(dptr,sptr,cellwidth * cellheight);
    if ( flags & FlagCol3 )
      mixzone( atcol+i, atlin, cellwidth, cellheight, p );

    liberate(dptr);
    return;
    }

  else
    {
    // ---------------------------------------------------------------------
    // - More than 1 line
    // - The skin must begin at the 1st line
    // - can be a 9 zones
    // ---------------------------------------------------------------------
    MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"apply multi-line %04X",flags));

    // Top Left
	 p = ConvertSkin(dptr,sptr,cellwidth * cellheight);
    if ( flags & CI_SKNF_L1C1 )
      mixzone( atcol, atlin, cellwidth, cellheight, p );
  
    // Top middles
    sptr += (cellwidth * cellheight);
	 p = ConvertSkin(dptr,sptr,cellwidth * cellheight);
    for ( i=cellwidth, l=(nbcol-cellwidth); i < l; i += cellwidth )
      if ( flags & CI_SKNF_L1C2 )
        mixzone( atcol+i, atlin, cellwidth,cellheight,p);
  
    // Top right
    sptr += (cellwidth * cellheight);
	 p = ConvertSkin(dptr,sptr,cellwidth * cellheight);
    if ( flags & CI_SKNF_L1C3 )
      mixzone( atcol+i, atlin, cellwidth, cellheight, p );
  
  
    if (!( flags & 0x01F8 ))
	   {
		liberate(dptr);
      return;  
		}

    sptr += (cellwidth * cellheight);

      // --- Loop on 2nde line (if more than 2 lines) 
      for (x=cellheight, y=(nblin-cellheight); x < y; x+= cellheight) 
        {
        /* Center Left */
 	     p = ConvertSkin(dptr,sptr,cellwidth * cellheight);

        if ( flags & CI_SKNF_L2C1 )
          mixzone( atcol, atlin+x, cellwidth, cellheight, p );

        z = (cellwidth * cellheight);
	  	  p = ConvertSkin(dptr,sptr+z,cellwidth * cellheight);

        for ( i=cellwidth, l=(nbcol-cellwidth); i < l; i += cellwidth )
          if ( flags & CI_SKNF_L2C2 )
            mixzone( atcol+i, atlin+x,   cellwidth, cellheight, p );

        z *= 2;
  	  	  p = ConvertSkin(dptr,sptr+z,cellwidth * cellheight);

        if ( flags & CI_SKNF_L2C3 )
          mixzone( atcol+i, atlin+x, cellwidth, cellheight, p );
        }
    
    /* bottom left */
    sptr += (cellwidth * cellheight * 3);
	 p = ConvertSkin(dptr,sptr,cellwidth * cellheight);
    if ( flags & CI_SKNF_L3C1 )
      mixzone( atcol, atlin+x, cellwidth, cellheight, p );
  
    /* bottom middles */
    sptr += (cellwidth * cellheight);
	 p = ConvertSkin(dptr,sptr,cellwidth * cellheight);
    for ( i=cellwidth, l=(nbcol-cellwidth); i < l; i += cellwidth )
      if ( flags & CI_SKNF_L3C2 )
        mixzone( atcol+i, atlin+x, cellwidth,cellheight,p);
  
    /* bottom right */
    sptr += (cellwidth * cellheight);
	 p = ConvertSkin(dptr,sptr,cellwidth * cellheight);
    if ( flags & CI_SKNF_L3C3 )
      mixzone( atcol+i, atlin+x, cellwidth, cellheight, p );
    }
  
  liberate(dptr);
  return;

}

// ****************************************************************************
/** LookApplySkinButton: 

 * @param 
 * @return nothing
 * @author CCDoc Administrator
 */

// * VarGlob:
// ****************************************************************************
void  LookApplySkinButton( int atcol , int atlin, int nbcol, int nblin, char * sptr, int flags )
{
MI_TRACE_DCL_TFN("LookApplySkinButton");
WORD i;
WORD Mask;
WORD grx;
char* dptr = NULL;
char* p;

#if defined (BDA_UNIX) || defined(BDA_WIN32)
// UseIt-Windows
// FCH27032006 Prise en compte mode palette/truecolor
  if (!get_pixel_format())
	 {
	 dptr = allocate(cellwidth * cellheight  * get_pixel_size());
	 if (!dptr)
		{
	   MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"err mem"));
		return;
		}
	 }
#endif

  grx = atcol;
  Mask = 1;

  for (i=0 ; i<12 ; i++)
    {
	 p = ConvertSkin(dptr,sptr,cellwidth * cellheight);
    if ( flags & Mask )
      {
      mixzone( grx, atlin, cellwidth, cellheight, p );
      grx += cellwidth;
      }
    sptr += (cellwidth * cellheight);
    Mask = Mask << 1;
    }

  liberate(dptr);
}

// ****************************************************************************
/** LookRelief: 

 * @param 
 * @return nothing
 * @author CCDoc Administrator
 */

// * VarGlob:
// ****************************************************************************
void  LookRelief(int atx,int aty, int nbx, int nby, int hl, int bg, int ll )
{
  if ( bg != CI_COL_TRANSPARENT )
    filzone(atx,aty,nbx,nby,bg);
  filzone(atx,aty,nbx,1,hl);
  filzone(atx,aty,1,nby,hl);
  filzone(atx+nbx-1,aty,1,nby,ll);
  filzone(atx,aty+nby-1,nbx,1,ll);
  return;
}
