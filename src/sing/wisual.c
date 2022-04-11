#ifndef	_VISUAL_C
#define	_VISUAL_C
#define	_VISUAL_ATB_MANAGER
#define	_VISUAL_STYLE_MANAGER  


/*	The function definitions	*/
/*	------------------------	*/
#include	<stdio.h>
#include	<stdlib.h>

#include "bda.h"
#include "vcico.h"
#include "stdimage.h"
#include "vimage.h"
#include "singpix.h"
#include "ansi.h"
#include "cico.c"
#include "valign.h"
#define	__VISUAL_DATE    "29/07/2005"
#ifndef	public
#define	public	
#endif
#ifndef	private
#define	private	static
#endif
#ifndef	BPTR
#define	BPTR BYTE FAR PTR
#endif
#ifndef	LPTR
#define	LPTR LONG FAR PTR
#endif
#include "vcommand.h"
#include "visilib.h"
#include "stdpsu.h"
#include "fnparser.c"
#include "vstyle.h"

#define	MAX_V_BUFFER 	1024

#ifdef	_VISUAL_ECHO
private	EXAWORD		VisualEcho=0;
#endif

private	EXAWORD		VisualLibraryStatus=0;

private	EXAWORD		ImageQuality=0;

private	STDPSUPTR	VisualBufferHeap[ MAX_V_BUFFER ];
private	EXAWORD		ActiveVisualBuffer=-1;

private  char	VersionStatus[16]={ 
	'V','E','R','S','I','O','N','_','S','T','A','T','U','S',':','2' 
	};
private	char 	LaPaterne[20] = { 
	'*','P','R','L','@','I','N','F','O','*','#',6,'1','1','a','0','0','2',0 
	};
private	char *	LaPointeur=(char*)0;
private	char 	LaVersion[8];
private	void **	XgraphPtr=(void*) 0;

private	int	use_default_style(int);
private	void	detect_default_style();

private	int	convert_integer( char * sptr )
{
	int result=0;
	int	i;
	if (!( sptr ))
		return( result );
	for ( i=0; *(sptr+i) != 0; i++ ) {
		if (( *(sptr+i) >= '0' )
		&&  ( *(sptr+i) <= '9' ))
			result = ((result*10)+( *(sptr+i) - '0' ));
		else	break;
		}
	return( result );
}

char *	getpatternversion()
{
	if (!( LaPointeur )) {
		LaVersion[0] = LaPaterne[12];
		LaVersion[1] = '.';
		LaVersion[2] = LaPaterne[13];
		LaVersion[3] = LaPaterne[14];
		if ( VersionStatus[15] != '0' ) {
			LaVersion[4] = '.';
			LaVersion[5] = LaPaterne[15];
			LaVersion[6] = '.';
			LaVersion[7] = LaPaterne[16];
			LaVersion[8] = LaPaterne[17];
			LaVersion[9] = 0;
			}
		else if ( LaPaterne[15] != '0' ) {
			LaVersion[4] = '.';
			LaVersion[5] = LaPaterne[15];
			LaVersion[6] = 0;
			}
		else	LaVersion[4] = 0;

		LaPointeur = LaVersion;
		}
	return( LaPointeur );

}

BDA	desrt;				/* library description */
extern BDA_INIT FAR PTR rt_init;	/* library signing */
extern BDA_ARG rt_arg;			/* arguments description */

#include "visual.h"
#include "vframe.h"
#include "vconf.h"
#include "vbuffer.h"

/*	Bits to complete the link	*/
/*	-------------------------	*/
public	int	_fltused=0;
public	void	_cfltcvt()	{ 	return; 	}
public	void	_cropzeros()	{ 	return; 	}
public	long	_aFftol()	{	return(0L);	}

#define	MAX_STRING_BUFFER 4096
private	char	stringbuffer[MAX_STRING_BUFFER+1];



private EXAWORD AbalVisualLiberate()
{
	return(0);
}

private EXAWORD AbalVisualInitialise(WORD mode )
{
	return(0);
}

private EXAWORD AbalVisualActivate(WORD width, WORD height, WORD style )
{
	return(0);
}

private EXAWORD AbalVisualZone(WORD x,WORD y,WORD w,WORD h,WORD style)
{
	return(0);
}

private EXAWORD AbalVisualFill(WORD x,WORD y,WORD w,WORD h,WORD pixel,WORD  mode)
{
	return(0);
}

private EXAWORD AbalVisualLine(WORD fx,WORD fy,WORD tx,WORD ty,WORD thick ,WORD pixel)
{
	return(0);
}

private EXAWORD AbalVisualFont(BPTR filename,WORD length)
{
	return(0);
}

private EXAWORD AbalVisualText(WORD x,WORD y,WORD w,WORD h,WORD fid,
			WORD fg, WORD bg, BPTR message,WORD length, WORD options)
{
	return(0);
}

private EXAWORD AbalVisualEdit(WORD x,WORD y,WORD w,WORD h,WORD fid,BPTR buffer,WORD length,WORD options)
{
	return(0);
}

private EXAWORD AbalVisualWindow(WORD x,WORD y,WORD w,WORD h,WORD fid,BPTR title,WORD length,WORD options)
{
	return(0);
}

private EXAWORD AbalVisualViewPort(WORD x,WORD y,WORD w,WORD h,WORD fid)
{
	return(0);
}

private EXAWORD AbalVisualButton(WORD x,WORD y,WORD w,WORD h,WORD fid,WORD fg, WORD bg,BPTR message,WORD length,WORD state)
{
	return(0);
}

private EXAWORD AbalVisualStyle(WORD x,WORD y,WORD w,WORD h,BPTR sptr, WORD slen, BPTR mptr, WORD mlen )
{
	return(0);
}

private EXAWORD AbalVisualCheck(WORD x,WORD y,WORD w,WORD h,WORD fid,WORD fg, WORD bg, BPTR message,WORD length,WORD state)
{
	return(0);
}

private EXAWORD AbalVisualSwitch(WORD x,WORD y,WORD w,WORD h,WORD fid,WORD fg, WORD bg, BPTR message,WORD length,WORD state)
{
	return(0);
}

private EXAWORD AbalVisualGraph(WORD x,WORD y,WORD w,WORD h,WORD fid,WORD fg, WORD bg, BPTR values,WORD length,WORD state)
{
	return(0);
}

private EXAWORD AbalVisualRadio(WORD x,WORD y,WORD w,WORD h,WORD fid,WORD fg, WORD bg, BPTR message,WORD length,WORD storage, WORD value)
{
	return(0);
}

private EXAWORD AbalVisualProgress(WORD x,WORD y,WORD w,WORD h,WORD f, WORD fg, WORD bg, WORD l,WORD v, WORD o)
{
	return(0);
}

EXAWORD AbalVisualBuffer( WORD width, WORD height )
{
	return(0);
}

EXAWORD AbalVisualPage( WORD number )
{
	return(0);
}

EXAWORD AbalVisualDrop( WORD number )
{
	return(0);
}

EXAWORD AbalVisualGet( WORD bid, WORD atx, WORD aty )
{
	return(0);
}

EXAWORD AbalVisualGetRow( WORD row, BPTR buffer, WORD length )
{
	return(0);
}

EXAWORD AbalVisualPutRow( WORD row, BPTR buffer, WORD length )
{
	return(0);
}

EXAWORD AbalVisualPutZone( WORD x, WORD y, WORD w, WORD h,BPTR buffer )
{
	return(0);
}

EXAWORD AbalVisualPut( WORD bid, WORD atx, WORD aty )
{
	return(0);
}

EXAWORD AbalVisualTransform( WORD bid, WORD cmd, WORD p1, WORD p2 )
{
	return(0);
}

EXAWORD AbalVisualColour( WORD cmd, BPTR buffer, WORD first, WORD last )
{
	return(0);
}

EXAWORD AbalVisualTable( WORD x, WORD y, WORD w, WORD h, WORD f, WORD fg, WORD bg,
		BPTR tptr, WORD tlen, BPTR vptr, WORD vlen, WORD options,BPTR fptr, WORD flen )
{
	return(0);
}

private EXAWORD AbalVisualImage(WORD x,WORD y,WORD w,WORD h,BPTR filename,WORD length, WORD options) 
{
	return(0);
}

private EXAWORD AbalVisualTabPage(WORD x,WORD y,WORD w,WORD h,WORD fid,BPTR title,WORD length,WORD offset,WORD control)
{
	return(0);
}

private EXAWORD AbalVisualSelect(
		WORD x,WORD y,WORD w,WORD h,
		WORD fid, WORD fg, WORD bg, 
		BPTR message,WORD length,BPTR iptr,WORD state)
{
	return(0);
}

private EXAWORD AbalVisualScroll(WORD x,WORD y,WORD w,WORD h,WORD fid,WORD fg, WORD bg, WORD item, WORD limit, WORD total, WORD style)
{
	return(0);
}

private EXAWORD AbalVisualPalette(BPTR filename,WORD length)
{
	return(0);
}

private EXAWORD AbalVisualFreeze()
{
	return(0);
}

private EXAWORD AbalVisualThaw(WORD x,WORD y,WORD w,WORD h)
{
	return(0);
}

private EXAWORD AbalVisualEvent(BPTR result)
{
	return(0);
}

private EXAWORD AbalVisualKey(WORD mode)
{
	return(0);
}

private EXAWORD AbalVisualControl(WORD command, BPTR buffer, WORD buflen )
{
	return(0);
}

/*	----------------------		*/
/*	Library identification		*/
/*	----------------------		*/
private	VOID FAR banniere()
{ 
	printf("\n   AbalVisual Library : VISUAL ");
	printf("\n   Version %s ",getpatternversion());

	if ( VersionStatus[15] == '2' )
		printf("\n   Provisoire du    %s",__VISUAL_DATE);

	printf("\n   Copyright (c) 2002 Amenesik / Sologic \n");
	printf("\n\t %u  %% VisualZone(x%%,y%%,w%%,h%,p%%)",_VISUAL_DLL_ZONE);
	printf("\n\t %u  %% VisualLine(x%%,y%%,x%%,y%%,n%%,p%%)",_VISUAL_DLL_LINE);
	printf("\n\t %u  %% VisualFont(fontname$,lng%%)",_VISUAL_DLL_FONT);
	printf("\n\t %u  %% VisualText(x%%,y%%,w%%,h%%,fid%%,fg%%,bg%%,msg$,lng%%,options%%)",_VISUAL_DLL_TEXT);
	printf("\n\t %u  %% VisualEdit(x%%,y%%,w%%,h%%,fid%%,buffer$?,lng%%)",_VISUAL_DLL_EDIT);
	printf("\n\t %u  %% VisualWindow(x%%,y%%,w%%,h%%,fid%%,msg$,lng%%,opt%%)",_VISUAL_DLL_WINDOW);
	printf("\n\t %u  %% VisualButton(x%%,y%%,w%%,h%%,fid%%,fg%%,bg%%,msg$,lng%%,state%%)",_VISUAL_DLL_BUTTON);
	printf("\n\t %u  %% VisualCheck(x%%,y%%,w%%,h%%,fid%%,fg%%,bg%%,msg$,lng%%,state%%)",_VISUAL_DLL_CHECK);
	printf("\n\t %u  %% VisualRadio(x%%,y%%,w%%,h%%,fid%%,fg%%,bg%%,msg$,lng%%,state%%)",_VISUAL_DLL_RADIO);
	printf("\n\t %u  %% VisualImage(x%%,y%%,w%%,h%%,filename$,lng%%)",_VISUAL_DLL_IMAGE);
	printf("\n\t %u  %% VisualTabPage(x%%,y%%,w%%,h%%,fid%%,msg$,lng%%,offset%%,state%%)",_VISUAL_DLL_TABPAGE);
	printf("\n\t %u  %% VisualSelect(x%%,y%%,w%%,h%%,fid%%,fg%%,bg%%,msg$,lng%%,item%%,state%%)",_VISUAL_DLL_SELECT);
	printf("\n\t %u  %% VisualScroll(x%%,y%%,w%%,h%%,fid%%,nombre%%)",_VISUAL_DLL_SCROLL);
	printf("\n\t %u  %% VisualPalette(filename$,lng%%)",_VISUAL_DLL_PALETTE);
	printf("\n\t %u  %% VisualInitialise(options%%)",_VISUAL_DLL_INITIALISE);
	printf("\n\t %u  %% VisualLiberate()",_VISUAL_DLL_LIBERATE);
	printf("\n\t %u  %% VisualFreeze()",_VISUAL_DLL_FREEZE);
	printf("\n\t %u  %% VisualThaw(x%%,y%%,w%%,h%%)",_VISUAL_DLL_THAW);
	printf("\n\t %u  %% VisualEvent(buffer$?)",_VISUAL_DLL_EVENT);
	printf("\n\t %u  %% VisualFill(x%%,y%%,w%%,h%%,colour%%)",_VISUAL_DLL_FILL);
	printf("\n\t %u  %% VisualKey(mode%%)",_VISUAL_DLL_KEY);
	printf("\n\t %u  %% VisualControl(option%%,buffer$?,length%%)",_VISUAL_DLL_CONTROL);
	printf("\n\t %u  %% VisualProgress(x%%,y%%,w%%,h%%,f%%,fg%%,bg%%,l%%,v%%,o%%)",_VISUAL_DLL_PROGRESS);
	printf("\n\t %u  %% VisualTable(x%%,y%%,w%%,h%%,f%%,fg%%,bg%%,tptr$,tlen%%,vptr$,vlen%%,o%%)",_VISUAL_DLL_TABLE);
	printf("\n\t %u  %% VisualColour(buffer$?,first%%,last%%)",_VISUAL_DLL_COLOUR);

	printf("\n\t %u  %% VisualBuffer(width%%,height%%)",_VISUAL_DLL_BUFFER);
	printf("\n\t %u  %% VisualPage(number%%)",_VISUAL_DLL_PAGE);
	printf("\n\t %u  %% VisualGet(number%%,x%%,y%%)",_VISUAL_DLL_GET);
	printf("\n\t %u  %% VisualGetRow(r%%,buffer$?,buflin%)",_VISUAL_DLL_GETROW);
	printf("\n\t %u  %% VisualPutRow(r%%,buffer$,buflin%)",_VISUAL_DLL_PUTROW);
	printf("\n\t %u  %% VisualPut(number%%,x%%,y%%)",_VISUAL_DLL_PUT);
	printf("\n\t %u  %% VisualDrop(number%%)",_VISUAL_DLL_DROP);
	printf("\n\t %u  %% VisualTransform(number%%,cmd%%,p1%%,p2%%)",_VISUAL_DLL_TRANSFORM);
	printf("\n\t %u  %% VisualSwitch(x%%,y%%,w%%,h%%,fid%%,fg%%,bg%%,msg$,lng%%,state%%)",_VISUAL_DLL_SWITCH);
	printf("\n\t %u  %% VisualGraph(x%%,y%%,w%%,h%%,fid%%,fg%%,bg%%,values$,lng%%,state%%)",_VISUAL_DLL_GRAPH);
	printf("\n\t %u  %% VisualActivate(width%%,height%%)\n",_VISUAL_DLL_ACTIVATE);
	return;
	
}

#ifdef	UNIX

/*	--------------------------------------		*/
/*	Elements of the CICO Access Controller		*/
/*	--------------------------------------		*/

private	struct	cico_access_controller	{

	WORD   FunctionCount;
	WORD  (*FunctionRelay[CICO_NOMBRE])();

	} CicoAccessController;


/*	--------------------------------------		*/
/*	Access Controller Basic Initialisation		*/
/*	--------------------------------------		*/

private	void	initialise_access_controller()
{
	CicoAccessController.FunctionCount = CICO_NOMBRE;

	CicoAccessController.FunctionRelay[CICO_CI] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_TPCI]	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_PRFO] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_LCFO] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_CONF] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_CO] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_MES] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_LIGNE] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_COLONNE]= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_START] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_FLUSH] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_LO] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_MIMA] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_EVENT] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_INIT] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_GRAPH] 	= (void *) 0;
  	return;
}

/*	-------------------------------------------------	*/
/* 	This function is provided to  perform redirection	*/
/*	--------------------------------------------------	*/

private	void *	redirect_access_controller( int	item,  void *	fptr )
{
	void	*	vptr=(void *) 0;
	if ((item >= 0) && ( item < CicoAccessController.FunctionCount )) {
		if ( fptr ) {
			vptr = CicoAccessController.FunctionRelay[item]; 	
			CicoAccessController.FunctionRelay[item] = fptr;
	 		}
 		}
	return( vptr );
}

private	void  	connect_access_controller( BDA_INIT * iptr, void * eptr, struct cico_access_controller * cptr )
{
	int	i;
	void *	vptr;
	
	if (!( iptr ))
		return;

	for (i=0; i < CICO_NOMBRE; i++ ) {
/*	---------------------------------------------------------------------------	*/
/*	it would be good to use an indirection to be able to overload some of these 	*/
/*	by later arriving dlls ,like printer 						*/
/*	vptr = &iptr->cico.function[i] for example					*/
/*	---------------------------------------------------------------------------	*/
		if ( i == CICO_GRAPH )
			XgraphPtr = &cptr->FunctionRelay[i];
		vptr = iptr->cico.fonction[i];
		if ( i != CICO_INIT )
			CicoAccessController.FunctionRelay[i] = vptr;
		}
	return;
}

public	int	x_conf(int i)
{
	return( (CicoAccessController.FunctionRelay[CICO_CONF])(i) );
}

public	int	x_graph( int i, struct x_graph_descriptor * dptr )
{
	void	* vptr;
	vptr = *XgraphPtr;
	CicoAccessController.FunctionRelay[CICO_GRAPH]	= vptr;
	return( (CicoAccessController.FunctionRelay[CICO_GRAPH])(i,dptr) );
}

public	int	x_event(int i)
{
	return( (CicoAccessController.FunctionRelay[CICO_EVENT])(i) );

}

#define	x_putch(i) (CicoAccessController.FunctionRelay[CICO_CO])(i)
#ifndef	x_putch
public	int	x_putch(int i)
{
	return( (CicoAccessController.FunctionRelay[CICO_CO])(i) );

}
#endif

public	int	x_col(int i)
{
	return( (CicoAccessController.FunctionRelay[CICO_COLONNE])(i) );

}

public	int	x_lin(int i)
{
	return( (CicoAccessController.FunctionRelay[CICO_LIGNE])(i) );

}
#endif

#ifdef	_VISUAL_STYLE_MANAGER
#include "vatb.c"
#endif	/* _VISUAL_STYLE_MANAGER */
	/* --------------------- */

private	int	reset_pixel_errors()	{	return( x_event(96) );	}
private	int	      pixel_errors()	{	return( x_event(97) );	}

/* 	------------------	*/
/* 	DLL initialisation	*/
/* 	------------------	*/
VOID FAR PTR InitRelais()
{ 
#ifdef	UNIX
	if (rt_init != (VOID FAR PTR) 0L)
		rt_init->ordinaire.signature = BDA_REDIRECT;
#else
	if (rt_init != (VOID FAR PTR) 0L)
		rt_init->ordinaire.signature = BDA_ORDINAIRE;
#endif

	desrt.banniere = (VOID (FAR PTR)()) banniere;
	desrt.fin = (VOID (FAR PTR)()) AbalVisualLiberate;

	desrt.nombre = _VISUAL_DLL_FUNCTION;
#ifdef	UNIX
	initialise_access_controller();
#endif

#ifdef vms
	reset_atribut_control();

	desrt.nom[_VISUAL_DLL_ZONE]	= (BYTE FAR PTR) "_AbalVisualZone";
	desrt.nom[_VISUAL_DLL_LINE]	= (BYTE FAR PTR) "_AbalVisualLine";
	desrt.nom[_VISUAL_DLL_FONT]	= (BYTE FAR PTR) "_AbalVisualFont";
	desrt.nom[_VISUAL_DLL_TEXT]	= (BYTE FAR PTR) "_AbalVisualText";
	desrt.nom[_VISUAL_DLL_EDIT]	= (BYTE FAR PTR) "_AbalVisualEdit";
	desrt.nom[_VISUAL_DLL_WINDOW]	= (BYTE FAR PTR) "_AbalVisualWindow";
	desrt.nom[_VISUAL_DLL_BUTTON]	= (BYTE FAR PTR) "_AbalVisualButton";
	desrt.nom[_VISUAL_DLL_CHECK]	= (BYTE FAR PTR) "_AbalVisualCheck";
	desrt.nom[_VISUAL_DLL_RADIO]	= (BYTE FAR PTR) "_AbalVisualRadio";
	desrt.nom[_VISUAL_DLL_IMAGE]	= (BYTE FAR PTR) "_AbalVisualImage";
	desrt.nom[_VISUAL_DLL_TABPAGE]	= (BYTE FAR PTR) "_AbalVisualTabPage";
	desrt.nom[_VISUAL_DLL_SELECT]	= (BYTE FAR PTR) "_AbalVisualSelect";
	desrt.nom[_VISUAL_DLL_SCROLL]	= (BYTE FAR PTR) "_AbalVisualScroll";
	desrt.nom[_VISUAL_DLL_PALETTE]	= (BYTE FAR PTR) "_AbalVisualPalette";
	desrt.nom[_VISUAL_DLL_INITIALISE]=(BYTE FAR PTR) "_AbalVisualInitialise";
	desrt.nom[_VISUAL_DLL_LIBERATE] = (BYTE FAR PTR) "_AbalVisualLiberate";
	desrt.nom[_VISUAL_DLL_FREEZE]   = (BYTE FAR PTR) "_AbalVisualFreeze";
	desrt.nom[_VISUAL_DLL_THAW]     = (BYTE FAR PTR) "_AbalVisualThaw";
	desrt.nom[_VISUAL_DLL_EVENT]    = (BYTE FAR PTR) "_AbalVisualEvent";
	desrt.nom[_VISUAL_DLL_FILL]     = (BYTE FAR PTR) "_AbalVisualFill";
	desrt.nom[_VISUAL_DLL_KEY ]     = (BYTE FAR PTR) "_AbalVisualKey";
	desrt.nom[_VISUAL_DLL_CONTROL]  = (BYTE FAR PTR) "_AbalVisualControl";
	desrt.nom[_VISUAL_DLL_PROGRESS] = (BYTE FAR PTR) "_AbalVisualProgress";
	desrt.nom[_VISUAL_DLL_TABLE]  	= (BYTE FAR PTR) "_AbalVisualTable";
	desrt.nom[_VISUAL_DLL_COLOUR]	= (BYTE FAR PTR) "_AbalVisualColour";
	desrt.nom[_VISUAL_DLL_BUFFER]  	= (BYTE FAR PTR) "_AbalVisualBuffer";
	desrt.nom[_VISUAL_DLL_PAGE] 	= (BYTE FAR PTR) "_AbalVisualPage";
	desrt.nom[_VISUAL_DLL_GET]  	= (BYTE FAR PTR) "_AbalVisualGet";
	desrt.nom[_VISUAL_DLL_GETROW]  	= (BYTE FAR PTR) "_AbalVisualGetRow";
	desrt.nom[_VISUAL_DLL_PUTROW]  	= (BYTE FAR PTR) "_AbalVisualPutRow";
	desrt.nom[_VISUAL_DLL_PUT]  	= (BYTE FAR PTR) "_AbalVisualPut";
	desrt.nom[_VISUAL_DLL_DROP]  	= (BYTE FAR PTR) "_AbalVisualDrop";
	desrt.nom[_VISUAL_DLL_TRANSFORM]= (BYTE FAR PTR) "_AbalVisualTransform";
	desrt.nom[_VISUAL_DLL_PUTZONE]= (BYTE FAR PTR) "_AbalVisualPutZone";
	desrt.nom[_VISUAL_DLL_SWITCH]	= (BYTE FAR PTR) "_AbalVisualSwitch";
	desrt.nom[_VISUAL_DLL_GRAPH]	= (BYTE FAR PTR) "_AbalVisualGraph";
	desrt.nom[_VISUAL_DLL_ACTIVATE] =(BYTE FAR PTR) "_AbalVisualActivate";
	desrt.nom[_VISUAL_DLL_VIEWPORT] =(BYTE FAR PTR) "_AbalVisualViewPort";
#ifdef	_VISUAL_STYLE_MANAGER
	desrt.nom[_VISUAL_DLL_STYLE] =(BYTE FAR PTR) "_AbalVisualStyle";
#endif

	/* ----- */
#else 	/* ! vms */
	/* ----- */

	desrt.reserve = (VOID FAR PTR) 0L;

	desrt.fonction[_VISUAL_DLL_ZONE]	= (WORD (FAR PTR)()) AbalVisualZone;
	desrt.fonction[_VISUAL_DLL_LINE]	= (WORD (FAR PTR)()) AbalVisualLine;
	desrt.fonction[_VISUAL_DLL_FONT]	= (WORD (FAR PTR)()) AbalVisualFont;
	desrt.fonction[_VISUAL_DLL_TEXT]	= (WORD (FAR PTR)()) AbalVisualText;
	desrt.fonction[_VISUAL_DLL_EDIT]	= (WORD (FAR PTR)()) AbalVisualEdit;
	desrt.fonction[_VISUAL_DLL_WINDOW]	= (WORD (FAR PTR)()) AbalVisualWindow;
	desrt.fonction[_VISUAL_DLL_BUTTON]	= (WORD (FAR PTR)()) AbalVisualButton;
	desrt.fonction[_VISUAL_DLL_CHECK]	= (WORD (FAR PTR)()) AbalVisualCheck;
	desrt.fonction[_VISUAL_DLL_RADIO]	= (WORD (FAR PTR)()) AbalVisualRadio;
	desrt.fonction[_VISUAL_DLL_IMAGE]	= (WORD (FAR PTR)()) AbalVisualImage;
	desrt.fonction[_VISUAL_DLL_TABPAGE]	= (WORD (FAR PTR)()) AbalVisualTabPage;
	desrt.fonction[_VISUAL_DLL_SELECT]	= (WORD (FAR PTR)()) AbalVisualSelect;
	desrt.fonction[_VISUAL_DLL_SCROLL]	= (WORD (FAR PTR)()) AbalVisualScroll;
	desrt.fonction[_VISUAL_DLL_PALETTE]	= (WORD (FAR PTR)()) AbalVisualPalette;
	desrt.fonction[_VISUAL_DLL_INITIALISE]  = (WORD (FAR PTR)()) AbalVisualInitialise;
	desrt.fonction[_VISUAL_DLL_LIBERATE]  	= (WORD (FAR PTR)()) AbalVisualLiberate;
	desrt.fonction[_VISUAL_DLL_FREEZE]      = (WORD (FAR PTR)()) AbalVisualFreeze;
	desrt.fonction[_VISUAL_DLL_THAW]        = (WORD (FAR PTR)()) AbalVisualThaw;
	desrt.fonction[_VISUAL_DLL_EVENT]      	= (WORD (FAR PTR)()) AbalVisualEvent;
	desrt.fonction[_VISUAL_DLL_FILL]      	= (WORD (FAR PTR)()) AbalVisualFill;
	desrt.fonction[_VISUAL_DLL_KEY ]      	= (WORD (FAR PTR)()) AbalVisualKey;
	desrt.fonction[_VISUAL_DLL_CONTROL ]   	= (WORD (FAR PTR)()) AbalVisualControl;
	desrt.fonction[_VISUAL_DLL_PROGRESS ]   = (WORD (FAR PTR)()) AbalVisualProgress;
	desrt.fonction[_VISUAL_DLL_TABLE ]	= (WORD (FAR PTR)()) AbalVisualTable;
	desrt.fonction[_VISUAL_DLL_COLOUR]	= (WORD (FAR PTR)()) AbalVisualColour;  
	desrt.fonction[_VISUAL_DLL_BUFFER]	= (WORD (FAR PTR)()) AbalVisualBuffer;
	desrt.fonction[_VISUAL_DLL_PAGE  ]	= (WORD (FAR PTR)()) AbalVisualPage; 
	desrt.fonction[_VISUAL_DLL_GET   ]	= (WORD (FAR PTR)()) AbalVisualGet;  
	desrt.fonction[_VISUAL_DLL_GETROW]	= (WORD (FAR PTR)()) AbalVisualGetRow;
	desrt.fonction[_VISUAL_DLL_PUTROW]	= (WORD (FAR PTR)()) AbalVisualPutRow;
	desrt.fonction[_VISUAL_DLL_PUT   ]	= (WORD (FAR PTR)()) AbalVisualPut;
	desrt.fonction[_VISUAL_DLL_DROP  ]	= (WORD (FAR PTR)()) AbalVisualDrop;
	desrt.fonction[_VISUAL_DLL_TRANSFORM]	= (WORD (FAR PTR)()) AbalVisualTransform;
	desrt.fonction[_VISUAL_DLL_PUTZONE]	= (WORD (FAR PTR)()) AbalVisualPutZone;
	desrt.fonction[_VISUAL_DLL_SWITCH]	= (WORD (FAR PTR)()) AbalVisualSwitch;
	desrt.fonction[_VISUAL_DLL_GRAPH]	= (WORD (FAR PTR)()) AbalVisualGraph;
	desrt.fonction[_VISUAL_DLL_ACTIVATE]    = (WORD (FAR PTR)()) AbalVisualActivate;
	desrt.fonction[_VISUAL_DLL_VIEWPORT]    = (WORD (FAR PTR)()) AbalVisualViewPort;
#ifdef	_VISUAL_STYLE_MANAGER
	desrt.fonction[_VISUAL_DLL_STYLE]    = (WORD (FAR PTR)()) AbalVisualStyle;
#endif

#ifdef	UNIX
	desrt.fonction[_VISUAL_DLL_FUNCTION+1]	= (WORD (FAR PTR)()) 0;
	desrt.fonction[_VISUAL_DLL_FUNCTION+2]	= (WORD (FAR PTR)()) 0;
	desrt.fonction[_VISUAL_DLL_FUNCTION+3]	= (WORD (FAR PTR)()) 0;
	desrt.fonction[_VISUAL_DLL_FUNCTION+4]	= (WORD (FAR PTR)()) 0;
	desrt.fonction[_VISUAL_DLL_FUNCTION+5]	= (WORD (FAR PTR)()) 0;
#ifdef	_VISUAL_ATB_MANAGER
	desrt.fonction[_VISUAL_DLL_FUNCTION+6]	= (WORD (FAR PTR)()) v_putch;
#else
	desrt.fonction[_VISUAL_DLL_FUNCTION+6]	= (WORD (FAR PTR)()) 0;
#endif
	desrt.fonction[_VISUAL_DLL_FUNCTION+7]	= (WORD (FAR PTR)()) 0;
	desrt.fonction[_VISUAL_DLL_FUNCTION+8]	= (WORD (FAR PTR)()) 0;
	desrt.fonction[_VISUAL_DLL_FUNCTION+9]	= (WORD (FAR PTR)()) 0;
	desrt.fonction[_VISUAL_DLL_FUNCTION+10]	= (WORD (FAR PTR)()) 0;
	desrt.fonction[_VISUAL_DLL_FUNCTION+11]	= (WORD (FAR PTR)()) 0;
	desrt.fonction[_VISUAL_DLL_FUNCTION+12]	= (WORD (FAR PTR)()) 0;
	desrt.fonction[_VISUAL_DLL_FUNCTION+13]	= (WORD (FAR PTR)()) 0;
	desrt.fonction[_VISUAL_DLL_FUNCTION+14]	= (WORD (FAR PTR)()) 0;
	desrt.fonction[_VISUAL_DLL_FUNCTION+15]	= connect_access_controller;
	desrt.fonction[_VISUAL_DLL_FUNCTION+16]	= (WORD (FAR PTR)()) 0;

	if (rt_init != (VOID FAR PTR) 0L) {
#ifdef	_VISUAL_ATB_MANAGER
		rt_init->cico.numero = (16384 | 32);
#else
		rt_init->cico.numero = 16384;
#endif
		rt_init->cico.fonction[CICO_CI]     = desrt.fonction[_VISUAL_DLL_FUNCTION+1]; 
	 	rt_init->cico.fonction[CICO_TPCI]   = desrt.fonction[_VISUAL_DLL_FUNCTION+2];
	  	rt_init->cico.fonction[CICO_PRFO]   = desrt.fonction[_VISUAL_DLL_FUNCTION+3];  	
		rt_init->cico.fonction[CICO_LCFO]   = desrt.fonction[_VISUAL_DLL_FUNCTION+4];  	
		rt_init->cico.fonction[CICO_CONF]   = desrt.fonction[_VISUAL_DLL_FUNCTION+5]; 	
		rt_init->cico.fonction[CICO_CO]     = desrt.fonction[_VISUAL_DLL_FUNCTION+6]; 	
		rt_init->cico.fonction[CICO_MES]    = desrt.fonction[_VISUAL_DLL_FUNCTION+7]; 	
		rt_init->cico.fonction[CICO_LIGNE]  = desrt.fonction[_VISUAL_DLL_FUNCTION+8]; 	
		rt_init->cico.fonction[CICO_COLONNE]= desrt.fonction[_VISUAL_DLL_FUNCTION+9]; 	
		rt_init->cico.fonction[CICO_START]  = desrt.fonction[_VISUAL_DLL_FUNCTION+10]; 	
		rt_init->cico.fonction[CICO_FLUSH]  = desrt.fonction[_VISUAL_DLL_FUNCTION+11]; 	
		rt_init->cico.fonction[CICO_LO]     = desrt.fonction[_VISUAL_DLL_FUNCTION+12]; 	
		rt_init->cico.fonction[CICO_MIMA]   = desrt.fonction[_VISUAL_DLL_FUNCTION+13];   
		rt_init->cico.fonction[CICO_EVENT]  = desrt.fonction[_VISUAL_DLL_FUNCTION+14];
		rt_init->cico.fonction[CICO_INIT]   = desrt.fonction[_VISUAL_DLL_FUNCTION+15];
		rt_init->cico.fonction[CICO_GRAPH]  = desrt.fonction[_VISUAL_DLL_FUNCTION+16];
		}
#endif

#endif /* vms */

	return((VOID FAR PTR) &desrt);

}

	/* ----------- */
#endif	/* _VISUAL_C */
	/* ----------- */


