/** @pkg Staff.Fred.zGraDraw */ 

// ****************************************************************************
/** zDraw.c: Included in Graphic module Drawing functionnalities */
// ****************************************************************************


// ****************************************************************************
/** BdaImg_arc: ABAL API
    Draw an arc

 * @param x1      IN
 * @param y1      IN
 * @param x2      IN
 * @param y2      IN
 * @param xs      IN
 * @param ys      IN
 * @param xe      IN
 * @param ye      IN

 * @return: CE_OK 

 * @author CCDoc Administrator
 
 */
// * VarGlob:
// ****************************************************************************
WORD BDA_WINAPI BdaImg_arc(WORD x1,WORD y1,WORD x2,WORD y2,WORD xs,WORD ys,WORD xe,WORD ye)
{
MI_TRACE_DCL_TFN("arc");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

// ****************************************************************************
/** BdaImg_ellipse: ABAL API
    Draw an ellipse

 * @param x1      IN
 * @param y1      IN
 * @param x2      IN
 * @param y2      IN

 * @return: CE_OK:

 * @author CCDoc Administrator
 
 */
// * VarGlob:
// ****************************************************************************
WORD BDA_WINAPI BdaImg_ellipse(WORD x1,WORD y1,WORD x2,WORD y2)
{
MI_TRACE_DCL_TFN("ellipse");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

// ****************************************************************************
/** BdaImg_trapez: ABAL API
    Draw a trapez

 * @param x1      IN
 * @param y1      IN
 * @param x2      IN
 * @param y2      IN
 * @param x3      IN
 * @param y3      IN
 * @param x4      IN
 * @param y4      IN

 * @return: CE_OK:

 * @author CCDoc Administrator
 
 */
// * VarGlob:
// ****************************************************************************
WORD BDA_WINAPI BdaImg_trapez(WORD x1,WORD y1,WORD x2,WORD y2,WORD x3,WORD y3,WORD x4,WORD y4)
{
MI_TRACE_DCL_TFN("trapez");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

// ****************************************************************************
/** BdaImg_roundrect: ABAL API
    Draw a rectangle with round corners

 * @param x1          IN
 * @param y1          IN
 * @param x2          IN
 * @param y2          IN
 * @param EllipsLarg  IN
 * @param EllipsHaut  IN

 * @return: CE_OK:

 * @author CCDoc Administrator
 
 */
// * VarGlob:
// ****************************************************************************
WORD BDA_WINAPI BdaImg_roundrect(WORD x1,WORD y1,WORD x2,WORD y2, WORD EllipsLarg,WORD EllipsHaut)
{
MI_TRACE_DCL_TFN("roundrect");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

// ****************************************************************************
/** BdaImg_rectangle: ABAL API
    Draw a rectangle

 * @param x1          IN
 * @param y1          IN
 * @param x2          IN
 * @param y2          IN

 * @return: CE_OK:

 * @author CCDoc Administrator
 
 */
// * VarGlob:
// ****************************************************************************
WORD BDA_WINAPI BdaImg_rectangle(WORD x1,WORD y1,WORD x2,WORD y2)
{
PTI_COMP_DRAW_DESCR pDraw = &g_pLook->Draw;
WORD  grx;
WORD  gry;
WORD  grcx;
WORD  grcy;
WORD  Size;

MI_TRACE_DCL_TFN("rectangle");
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"(%d,%d) - (%d,%d)",x1,y1,x2,y2));

if (  (x1>=g_pApp->GrScreenWidth)
   || (y1>=g_pApp->GrScreenHeight) 
   || (x2>=g_pApp->GrScreenWidth)
   || (y2>=g_pApp->GrScreenHeight)
   )
   MI_TRACE_RETURN(CE_ERR);

grx  = (x1<=x2) ? x1    : x2;
grcx = (x1<=x2) ? x2-x1 : x1-x2;
gry  = (y1<=y2) ? y1    : y2;
grcy = (y1<=y2) ? y2-y1 : y1-y2;

if (  (grcx >= pDraw->PenSize)
   && (grcy >= pDraw->PenSize)
   )
   Size = pDraw->PenSize;
else
   Size = 1;

Size=1;
   
if (pDraw->BrushType!=CI_BRUSH_TRANSPARENT)
   filzone( grx,gry,grcx,grcy,pDraw->BrushColor);
   
filzone( grx          , gry          , grcx     , Size, pDraw->PenColor );
filzone( grx          , gry          , Size     , grcy, pDraw->PenColor );
filzone( grx          , gry+grcy-Size, grcx     , Size, pDraw->PenColor );
filzone( grx+grcx-Size, gry          , Size     , grcy, pDraw->PenColor );

MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaImg_line: ABAL API
    Draw a line

 * @param x1          IN
 * @param y1          IN
 * @param x2          IN
 * @param y2          IN

 * @return: CE_OK:

 * @author CCDoc Administrator
 
 */
// * VarGlob:
// ****************************************************************************
WORD BDA_WINAPI BdaImg_line(WORD x1,WORD y1,WORD x2,WORD y2)
{
MI_TRACE_DCL_TFN("line");
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"(%d,%d) - (%d,%d)",x1,y1,x2,y2));

if (  (x1>=g_pApp->GrScreenWidth)
   || (y1>=g_pApp->GrScreenHeight) 
   || (x2>=g_pApp->GrScreenWidth)
   || (y2>=g_pApp->GrScreenHeight)
   )
   MI_TRACE_RETURN(CE_ERR);

MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaImg_point: ABAL API
    Draw a point (taille = 1 pixel)

 * @param x          IN
 * @param y          IN

 * @return: CE_OK:

 * @author CCDoc Administrator
 
 */
// * VarGlob:
// ****************************************************************************
WORD BDA_WINAPI BdaImg_point(WORD x,WORD y)
{
PTI_COMP_DRAW_DESCR pDraw = &g_pLook->Draw;
MI_TRACE_DCL_TFN("point");
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"(%d,%d)",x,y));

if (  (x>=g_pApp->GrScreenWidth)
   || (y>=g_pApp->GrScreenHeight) 
   )
   MI_TRACE_RETURN(CE_ERR);

filzone( x, y, 1,1, pDraw->PointColor );

MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaImg_pen: ABAL API
    Select a pen

 * @param type       IN
 * @param larg       IN
 * @param r          IN
 * @param g          IN
 * @param b          IN

 * @return: CE_OK:

 * @author CCDoc Administrator
 
 */
// * VarGlob:
// ****************************************************************************
WORD BDA_WINAPI BdaImg_pen(WORD type,WORD larg,WORD r,WORD g,WORD b)
{
PTI_COMP_DRAW_DESCR pDraw = &g_pLook->Draw;
MI_TRACE_DCL_TFN("pen");

MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"type=%d",type));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"larg=%d",larg));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"rvb=%d,%d,%d",r,g,b));

pDraw->PenType = type;
pDraw->PenSize = larg;

MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaImg_brush: ABAL API
    Select a brush

 * @param type       IN
 * @param r          IN
 * @param g          IN
 * @param b          IN

 * @return: CE_OK:

 * @author CCDoc Administrator
 
 */
// * VarGlob:
// ****************************************************************************
WORD BDA_WINAPI BdaImg_brush(WORD type,WORD r,WORD g,WORD b)
{
MI_TRACE_DCL_TFN("brush");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

// ****************************************************************************
/** BdaImg_color - ABAL API
    Define the current color for text or lines

 * @param r          IN
 * @param g          IN
 * @param b          IN

 * @return: CE_OK:

 * @author CCDoc Administrator
 
 */
// * VarGlob:
// ****************************************************************************
WORD BDA_WINAPI BdaImg_color(WORD r,WORD g,WORD b)
{
MI_TRACE_DCL_TFN("color");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

// ****************************************************************************
/** BdaImg_getcolor: ABAL API (Windows only)
  * Retrieves the current color of the specified Windows display element. 

 * @param jeu         IN  : Windows Display element
 * @param no          IN  : CE_COLOR_RED, CE_COLOR_GREEN, CE_COLOR_BLUE

 * @return: R,G or B value

 * @author CCDoc Administrator
 
 */
// * VarGlob:
// ****************************************************************************
WORD BDA_WINAPI BdaImg_getcolor(WORD jeu,WORD no)
{
MI_TRACE_DCL_TFN("getcolor");
MI_TRACE_VOID(0);
return 0;
}

