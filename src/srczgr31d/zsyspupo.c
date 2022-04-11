/** @pkg Staff.Fred.zSysPupo */ 
#include"vthologi.h"
// ****************************************************************************
// * zPushpop.c
// * Included in System module
// * Push/pop window functionnalities
// ****************************************************************************
// ANF
typedef struct  push_control  {
  struct push_control * previous;
  STDPSUPTR storage;
  } TI_PushControl, * PTI_PushControl;


PTI_PushControl   PushHeap=(PTI_PushControl) 0;



// ****************************************************************************
/** zSysPush_Internal: internal function, called from BdaSys_zPush 
  to avoid direct API function call

 * @return:
   CE_OK                 
   CE_ERR_MEMORY  
          
 * @author ANF
 
 */
// * VarGlob: 
// ****************************************************************************
WORD zSysPush_Internal(WORD x1,WORD y1,WORD x2,WORD y2,WORD sha)
{
  int gratcol,gratlin,grnbcol,grnblin;

  PTI_PushControl pptr;

  if ( x2 > x1 ){ gratcol = x1;   grnbcol = ((x2 - x1)+1); }
  else    { gratcol = x2;  grnbcol = ((x1 - x2)+1); }
  if ( y2 > y1 ){ gratlin = y1;  grnblin = ((y2 - y1)+1); }
  else    { gratlin = y2;  grnblin = ((y1 - y2)+1); }

  if ( gratlin > 1 ) { gratlin--; grnblin++; }
  gratcol = ((gratcol -1) * cellwidth);
  gratlin = ((gratlin -1) * cellheight);
  grnbcol *= cellwidth;
  grnblin *= cellheight;
 
  SysHide();  
 
  /* These are necessary in order to save combo frames which decrement
   * their legal zone start coordinates to gx-1 and gy-1 and increase
   * their legal dimensions to nx+2 and ny+2 : IJM 22/11/2000 */

  if ( gratcol ) { gratcol--; grnbcol+=2; }
  if ( gratlin ) { gratlin--; grnblin+=2; }

  if (( pptr = (PTI_PushControl) allocate( sizeof( TI_PushControl ) )) != (PTI_PushControl) 0 ) {

    pptr->previous = PushHeap;
    PushHeap = pptr;

    if ((pptr->storage  = (STDPSUPTR) allocate_graphic_storage( 
      gratcol,gratlin,
      grnbcol, grnblin 
      )) != (STDPSUPTR) 0) 
      capture_pixel_storage( pptr->storage );

    }else{
        SysShow();
        return CE_ERR_MEMORY;
    }

  SysShow(); 

return(CE_OK);
}



// ****************************************************************************
/** BdaSys_zPush: (THO name) zzpush - ABAL API - 
    Memorize the background, to create a new window

 * @param x1      IN  
 * @param y1      IN  
 * @param x2      IN  
 * @param y2      IN  
 * @param sha     IN  

 * @return:
   CE_OK                 
   CE_ERR_MEMORY  
            
 * @author ANF
 
 */
// * VarGlob: 
// ****************************************************************************
// ANF
WORD BDA_WINAPI BdaSys_zPush(WORD x1,WORD y1,WORD x2,WORD y2,WORD sha)
{
MI_TRACE_DCL_TFN("Push");
WORD bad=0;

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"at (%d,%d),(%d,%d)",x1,y1,x2,y2));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"sha=%d",sha));
	SysHide();
    window_error_code=0;
	bad=CreateNewWindow(x1,y1,x2,y2);
	SysShow();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"BAD=%d",bad));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"ID_WINDOW=%d",GetWindowID()));
MI_TRACE_RETURN(window_error_code);
}

// ****************************************************************************
/** zSysPop_Internal: - internal function, called from BdaSys_zPop
  to avoid direct API function calls

 * @param Nothing

 * @return: CE_OK     
            
 * @author ANF
 
 */
// * VarGlob: 
// ****************************************************************************
WORD zSysPop_Internal()
{
MI_TRACE_DCL_TFN("zSysPop_Int");
PTI_PushControl pptr;
  SysHide();
  if ((pptr = PushHeap) != (PTI_PushControl) 0) {
    if ( pptr->storage != (STDPSUPTR) 0 ) {
      MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"in"));
      refresh_pixel_storage( pptr->storage );
      pptr->storage = (STDPSUPTR) liberate_pixel_storage( (STDPSUPTR) pptr->storage );
      }
    PushHeap = PushHeap->previous;
    pptr = liberate( pptr );
    }
  SysShow();
return CE_OK;
}


// ****************************************************************************
/** BdaSys_zPop: (THO name) zzpop - ABAL API - 
    release the memorized background

 * @param Nothing

 * @return: CE_OK     
            
 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
// ANF
WORD BDA_WINAPI BdaSys_zPop()
{
MI_TRACE_DCL_TFN("Pop");

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"ID_WINDOW=%d",GetWindowID()));

  SysHide();
  DestroyCurrentWindow();
  SysShow();

MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaSys_zWinImpl: (THO name) zwin_impl - ABAL API
    Define a clipping rectangle (not used in original Zdll)

 * @param x1      IN  
 * @param y1      IN  
 * @param x2      IN  
 * @param y2      IN  

 * @return: CE_OK

 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
WORD BDA_WINAPI BdaSys_zWinImpl(WORD x1,WORD y1,WORD x2,WORD y2)
{
MI_TRACE_DCL_TFN("WinImpl");

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"at (%d,%d),(%d,%d)",x1,y1,x2,y2));

MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaSys_zWinSetStack: (THO name) zzwin_setpile - ABAL API - 
    Search in the list of windows, and memorize/release windows

 * @param flag    IN  
 * @param no      IN  
 * @param x1      IN  
 * @param y1      IN  
 * @param x2      IN  
 * @param y2      IN  

 * @return: CE_OK

 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
WORD BDA_WINAPI BdaSys_zWinSetStack(WORD flag,WORD no,WORD x1,WORD y1,WORD x2,WORD y2)
{
MI_TRACE_DCL_TFN("WinSetStack");

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"at (%d,%d),(%d,%d)",x1,y1,x2,y2));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"flag=%d",flag));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"no=%d",no));
   SysHide();	
	 PileWindow(flag,no,  x1, y1, x2, y2);
	 SysShow();
MI_TRACE_RETURN(CE_OK);
}

