#ifndef	_VISUAL_C
#define	_VISUAL_C
#define	_VISUAL_ATB_MANAGER
#define	_VISUAL_STYLE_MANAGER  
#define	_VISUAL_ECHO 1
/*	The function definitions	*/
/*	------------------------	*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

#include "bda.h"

#ifdef WIN32
#ifndef	BPTR
#define	BPTR BYTE FAR PTR
#endif
#ifndef	WPTR
#define	WPTR WORD FAR PTR
#endif
#ifndef	LPTR
#define	LPTR LONG FAR PTR
#endif

#include "rgraphapi.h"
#include "vobjapi.h"
#include "banapi.h"
#include "visualtrace.h"
#include "vimage.h"
#include "stdimage.h"
#include "printhq.h"
#else

#define	VERSION666

#ifndef	BPTR
#define	BPTR BYTE FAR PTR
#endif
#ifndef	LPTR
#define	LPTR LONG FAR PTR
#endif

#include "vcico.h"
#include "stdimage.h"
#include "trace.h"
#include "vimage.h"
#include "singpix.h"
#include "ansi.h"
#include "cico.c"
#include "excallb.h"
#endif


#include "valign.h"
#define	__VISUAL_DATE    "07/07/2007"
#ifndef	public
#define	public	
#endif
#ifndef	private
#define	private	static
#endif

#include "vcommand.h"
#include "visilib.h"
#include "fnparser.c"
#include "vstyle.h"

#define CI_MODULE_ID 0x0002

#define	MAX_V_BUFFER 	1024

#ifdef WIN32
#include "strucpsu.h" //FCH
#include "wincicoapi.h" //FCH
#else
#include "stdpsu.h"
#endif

private	VOID	terminate_style();
private	VOID	initialise_style();
private	EXAWORD	activate_visual_buffer();
private	int	define_visual_atribut( char * buffer, int buflen );

#ifdef	_VISUAL_ECHO
private	EXAWORD		VisualEcho=0;
#endif

private	EXAWORD		VisualFreezeControl=1;
private	EXAWORD		VisualLibraryStatus=0;

private	EXAWORD		ImageQuality=0;
private	char		StyleName[512];
private	EXAWORD		StyleErrorCount=0;
private	EXAWORD		StyleErrorTrace=1;

extern	int	use_overload_style;

struct	visualbuffer {
	STDPSUPTR	buffer;
	int		x;
	int		y;
	int		width;
	int		height;
	int		font;
	int		column;
	int		row;
	int		foreground;
	int		background;
	};

#ifdef WIN32
struct visualbuffer  *  /* STDPSUPTR */ VisualBufferHeap[ MAX_V_BUFFER ];
EXAWORD		ActiveVisualBuffer=-1;
#else
private	struct visualbuffer  *  /* STDPSUPTR */ VisualBufferHeap[ MAX_V_BUFFER ];
private	EXAWORD		ActiveVisualBuffer=-1;
#endif

#ifndef WIN32
private  char	VersionStatus[16]={ 
	'V','E','R','S','I','O','N','_','S','T','A','T','U','S',':','2' 
	};
private	char 	LaPaterne[20] = { 
	'*','P','R','L','@','I','N','F','O','*','#',6,'1','1','a','0','0','2',0 
	};
private	char *	LaPointeur=(char*)0;
private	char 	LaVersion[8];

private	void **	XgraphPtr=(void*) 0;
int (* XgraphRelay)(int, struct x_graph_descriptor *) = 0;

int	control_fork()
{
	return( fork() );
}
int	system_failure(char * mptr)
{
	printf("\r\nsystem(%s) : failure : %u \r\n",mptr,errno);
	return(0);
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

#endif

/*	-------------------------------------		*/
/*	Example of Abal Application Call Back		*/
/*	-------------------------------------		*/
private	int	application_callback(char * procname)
{
	int	status;
	struct exa_callback S;
	S.buffer = procname;
	if ((status = x_callback(EXA_CALLBACK_RESOLVE,&S)) != 0)
		return(status);
	else 	return( x_callback( EXA_CALLBACK_INVOKE,&S ) );
}


private	int	reset_pixel_errors()	{	return( x_event(96) );	}
private	int	      pixel_errors()	{	return( x_event(97) );	}

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

BDA	desrt;				/* library description */
#ifdef WIN32
extern LPBDA_INIT rt_init;		/* library signing */
#else
extern BDA_INIT FAR PTR rt_init;	/* library signing */
#endif
extern BDA_ARG		rt_arg;	/* arguments description */

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


#include "vstring.c"
#include "guimouse.h"

private	void	visual_configuration()
{
	char	*	vptr;

	if ((vptr = configuration_item( "REPLAY" )) != (char *) 0)
		activate_replay( vptr );
	else if ((vptr = configuration_item( "RECORD" )) != (char *) 0)
		activate_record( vptr );
	return;
}


/* _VISUAL_STYLE_MANAGER */
/* --------------------- */
#ifdef	WIN32
#ifdef	_VISUAL_STYLE_MANAGER
#include "vatb.c"
#endif
#endif

/*	---------------------------------------------------------------		*/
/*	Functions Required for the Correct interpretation of LDAP Fonts		*/
/*	---------------------------------------------------------------		*/
char	*	GetFontVector( char * nptr, int i )
{
	return( nptr );
}

char 	*	UseFontVector( char * nptr )
{
	char	*	rptr;

	if (( rptr = nptr ) != (char *) 0) {
		while ( *nptr ) {
			if ( *nptr == '[' )
				*nptr = 0;
			else	nptr++;
			}
		}
	return( rptr );
}


/*	--------------------------------------		*/
/*	A b a l V i s u a l L i b e r a t e () 		*/
/*	--------------------------------------		*/
private	struct	visualbuffer * allocate_visual_buffer()
{
	struct visualbuffer * vptr;
	if (!( vptr = allocate( sizeof( struct visualbuffer ) )))
		return(vptr);
	else	{
		vptr->buffer = (STDPSUPTR) 0;
		vptr->x = vptr->y = vptr->width = vptr->height = 0;
		vptr->font = 0;
		vptr->column = vptr->row = vptr->foreground = vptr->background = 0;
		return( vptr );
		}
}

public	void	handle_style_errors( int nb, char * tracefilename)
{
#ifdef	UNIX
	char *	cptr;
	char * eptr;
#endif

	if (!( nb ))	
		return;
	else if (!( StyleErrorTrace ))
		StyleErrorCount += nb;
	else if (!( tracefilename ))
		StyleErrorCount += nb;
#ifdef	UNIX
	else if (!( eptr = "aed" ))
		StyleErrorCount += nb;
	else if (!(cptr = allocate( (strlen( tracefilename ) + strlen( eptr ) + 16 ) ) ))
		StyleErrorCount += nb;
	else	{
		sprintf(cptr,"%s -t%s",eptr,tracefilename);
		system( cptr );
		liberate( cptr );
		}
#endif
	return;
}


private	struct	visualbuffer * release_visual_buffer( struct visualbuffer * vptr )
{
	if ( vptr ) {
		visual_drop( vptr->buffer );
		liberate( vptr );
		}
	return( (struct visualbuffer *) 0 );
}

private EXAWORD AbalVisualLiberate()
{
	BPTR	eptr;
	EXAWORD	retcode;
	WORD		i;
	struct visualbuffer * vptr;
	STDPSUPTR	pptr;

	MI_TRACE_DCL_TFN("VisualLiberate");
	MI_TRACE_BEGIN();

#ifdef	_VISUAL_ECHO
	if ( VisualEcho & 2 ) {
		printf("VisualLiberate()\r\n");
		}
#endif	

	if ( VisualLibraryStatus ) {
		if ((eptr = getenv("VISUALSVG")) != (BPTR) 0)
			terminate_svg(eptr);
		VisualLibraryStatus=0;
		for ( i=0; i < MAX_V_BUFFER; i++ ) {
			if (!( vptr = VisualBufferHeap[i] ))
				continue;
			else	VisualBufferHeap[i] = release_visual_buffer( vptr );
			}		

#ifdef	_VISUAL_STYLE_MANAGER 
		terminate_style();
#endif

		retcode = VisualTerminate();
		MI_TRACE_RETURN(retcode);
	}
	else
		MI_TRACE_RETURN(VisualLibraryStatus);

}

/*	-----------------------------------------------------	*/
/*	A b a l V i s u a l I n i t i a l i s e (   mode    )	*/
/*	-----------------------------------------------------	*/

private EXAWORD AbalVisualInitialise(WORD mode )
{
	BPTR	eptr;
	EXAWORD	retcode;
	WORD	i;
	MI_TRACE_DCL_TFN("VisualInitialise");
	MI_TRACE_BEGIN();
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN mode=%02Xh",mode));

	if (!x_conf(66))
	{
		MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"Err GRAPHOFF"));
		MI_TRACE_RETURN(56);
	}

	if (!( VisualLibraryStatus )) 
	{
		if ((eptr = getenv("VISUALSVG")) != (BPTR) 0)
			initialise_svg(eptr);
		for ( i=0; i < MAX_V_BUFFER; i++ )
			VisualBufferHeap[i] = (struct visualbuffer *) 0;

		ActiveVisualBuffer = -1;

		visual_configuration();

#ifdef	_VISUAL_STYLE_MANAGER 
		initialise_style();
#endif

#ifdef	_VISUAL_ECHO
		if ( VisualEcho & 2 ) {
			printf("VisualInitialise(%u)\r\n",mode);
			}
#endif	
		ImageQuality = (mode & 0x0600);
		VisualLibraryStatus=1;
		retcode = VisualInitialise( mode );
		MI_TRACE_RETURN(retcode);
	}
	else	
	{
		cicopalette(0,0);
	 	initialise_mouse();
		MI_TRACE_RETURN(0);
	}
}


/*	-----------------------------------------------------	*/
/*	A b a l V i s u a l A c t i v a t e ( width, height )	*/
/*	-----------------------------------------------------	*/

private EXAWORD AbalVisualActivate(WORD width, WORD height, WORD style)
{
	BPTR	eptr;
	EXAWORD	retcode;
	WORD	i;
	MI_TRACE_DCL_TFN("VisualActivate");
	MI_TRACE_BEGIN();
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN w=%d h=%d s=%d",width,height,style));
	if (!x_conf(66))
	{
		MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"Err GRAPHOFF"));
		MI_TRACE_RETURN(56);
	}

	if (!( VisualLibraryStatus )) 
	{
		if ((eptr = getenv("VISUALSVG")) != (BPTR) 0)
			initialise_svg(eptr);
		for ( i=0; i < MAX_V_BUFFER; i++ )
			VisualBufferHeap[i] = (struct visualbuffer *) 0;

		ActiveVisualBuffer = -1;

		visual_configuration();

#ifdef	_VISUAL_STYLE_MANAGER 
		initialise_style();
#endif

#ifdef	_VISUAL_ECHO
		if ( VisualEcho & 2 ) {
			printf("VisualActivate(%u,%u)\r\n",width,height);
			}
#endif	

		ImageQuality = 512;
		VisualLibraryStatus = 2;
		retcode = VisualActivate( width, height, style );
		MI_TRACE_RETURN(retcode);
		}
	else	{
		cicopalette(0,0);
	 	initialise_mouse();
		MI_TRACE_RETURN(0);
		}
}

#include "styled.c"

/*	---------------------------------------		*/
/*	A b a l V i s u a l Z o n e (x,y,w,h,s)		*/
/*	---------------------------------------		*/

private EXAWORD AbalVisualZone(WORD x,WORD y,WORD w,WORD h,WORD style)
{
	int	status=0;
	EXAWORD	retcode;
	MI_TRACE_DCL_TFN("VisualZone");
	MI_TRACE_BEGIN();
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN x=%d y=%d w=%d h=%d s=%d",x,y,w,h,style));
#ifdef	_VISUAL_ECHO
	if ( VisualEcho & 2 ) {
		printf("VisualZone(%u,%u,%u,%u,%u)\r\n",x,y,w,h,style);
		}
#endif	
	reset_pixel_errors();
	switch (( style & 0x00FF) ) {
		case	_OUTSET_FRAME	:
			styled_outset_frame(x,y,w,h,style);
			break;
		case	_INSET_FRAME	:
			styled_inset_frame(x,y,w,h,style);
			break;
		case	_GROOVE_FRAME	:
			styled_groove_frame(x,y,w,h,style);
			break;
		case	_RIDGE_FRAME	:
			styled_ridge_frame(x,y,w,h,style);
			break;
		case	_EDIT_FRAME	:
			styled_edit_frame(x,y,w,h,style);
			break;
		}

	retcode = pixel_errors();
	MI_TRACE_RETURN(retcode);
}


/*	---------------------------------------		*/
/*	A b a l V i s u a l F i l l (x,y,w,h,s)		*/
/*	---------------------------------------		*/

private EXAWORD AbalVisualFill(WORD x,WORD y,WORD w,WORD h,WORD pixel,WORD  mode)
{
	EXAWORD	retcode;
	MI_TRACE_DCL_TFN("VisualFill");
	MI_TRACE_BEGIN();
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN x=%d y=%d w=%d h=%d p=%d m=%d",x,y,w,h,pixel,mode));

#ifdef	_VISUAL_ECHO
	if ( VisualEcho & 2 ) {
		printf("VisualFill(%u,%u,%u,%u,%u,%u)\r\n",x,y,w,h,pixel,mode);
		}
#endif	
	reset_pixel_errors();
	visual_filzone(x,y,w,h,pixel,mode );
	retcode = pixel_errors();
	MI_TRACE_RETURN(retcode);
}

/*	---------------------------------------		*/
/*	A b a l V i s u a l L i n e (x,y,x,y,s)		*/
/*	---------------------------------------		*/

private EXAWORD AbalVisualLine(WORD fx,WORD fy,WORD tx,WORD ty,WORD thick ,WORD pixel)
{
	EXAWORD	retcode;
	MI_TRACE_DCL_TFN("VisualLine");
	MI_TRACE_BEGIN();
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN fx=%d fy=%d tx=%d ty=%d t=%d p=%d",fx,fy,tx,ty,thick,pixel));
#ifdef	_VISUAL_ECHO
	if ( VisualEcho & 2 ) {
		printf("VisualLine(%u,%u,%u,%u,%u,%u)\r\n",fx,fy,tx,ty,thick,pixel);
		}
#endif	
	reset_pixel_errors();
	VisualLine(fx,fy,tx,ty,thick,pixel);
	retcode = pixel_errors();
	MI_TRACE_RETURN(retcode);
}


/*	---------------------------------------		*/
/*	A b a l V i s u a l F o n t ( name,len)		*/
/*	---------------------------------------		*/

private EXAWORD AbalVisualFont(BPTR filename,WORD length)
{
	EXAWORD	retcode;
	MI_TRACE_DCL_TFN("VisualFont");
	MI_TRACE_BEGIN();
 
	filename = terminate_string(filename,length);
#ifdef	_VISUAL_ECHO
	if ( VisualEcho & 2 ) {
		printf("VisualFont(%c%s%c,%u)\r\n",0x0022,filename,0x0022,length);
		}
#endif	
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN name='%s'",MI_TRA_TRUNCLG(filename,length) ));
	retcode = VisualFont(filename,length);
	MI_TRACE_RETURN(retcode);
}


private EXAWORD AbalVisualText(WORD x,WORD y,WORD w,WORD h,WORD fid,
			WORD fg, WORD bg, BPTR message,WORD length, WORD options)
{
	MI_TRACE_DCL_TFN("VisualText");
	MI_TRACE_BEGIN();
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN x=%d y=%d w=%d h=%d",x,y,w,h));
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN fid=%d fg=%d bg=%d op=%d",fid,fg,bg,options));

	message = terminate_string(message,length);

#ifdef	_VISUAL_ECHO
	if ( VisualEcho & 2 ) {
		printf("VisualText(%u,%u,%u,%u, %u, %u,%u, %c%s%c, %u, %u )\r\n",
				x,y,w,h,fid,fg,bg,
				0x0022,message,0x0022,length,options);
		}
#endif	
	VisualText(x,y,w,h,fid,fg,bg,message,length,options);

	MI_TRACE_RETURN(0);
}

private EXAWORD AbalVisualEdit(WORD x,WORD y,WORD w,WORD h,WORD fid,BPTR buffer,WORD length,WORD options)
{
	char	*	stuffer;
	int		status;
	int		hmask;
	MI_TRACE_DCL_TFN("VisualEdit");
	MI_TRACE_BEGIN();
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN x=%d y=%d w=%d h=%d",x,y,w,h));
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN fid=%d",fid));

	stuffer = terminate_string(buffer,length);

#ifdef	_VISUAL_ECHO
	if ( VisualEcho & 2 ) {
		printf("VisualEdit(%u,%u,%u,%u, %u, %c%s%c, %u, %u )\r\n",
				x,y,w,h,fid,
				0x0022,buffer,0x0022,length,options);
		}
#endif	
	reset_pixel_errors();
	hmask = set_edit_mask(options);
	if ((status=VisualEdit(x,y,w,h,fid,stuffer,length)) != 27)
		memcpy(buffer,stuffer,length);
	hmask = set_edit_mask(hmask);
	MI_TRACE_RETURN(status);
}

private EXAWORD AbalVisualWindow(WORD x,WORD y,WORD w,WORD h,WORD fid,BPTR title,WORD length,WORD options)
{
	EXAWORD	retcode;
	MI_TRACE_DCL_TFN("VisualWindow");
	MI_TRACE_BEGIN();
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN x=%d y=%d w=%d h=%d",x,y,w,h));
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN fid=%d op=%d",fid,options));

	title = terminate_string(title,length);

#ifdef	_VISUAL_ECHO
	if ( VisualEcho & 2 ) {
		printf("VisualWindow(%u,%u,%u,%u, %u, %c%s%c, %u, %u )\r\n",
				x,y,w,h,fid,
				0x0022,title,0x0022,length,options);
		}
#endif	
	reset_pixel_errors();
	styled_visual_window(x,y,w,h,fid,title,length,options);
	retcode = pixel_errors();
	MI_TRACE_RETURN(retcode);
}


struct	viewport_control {
	WORD	X;
	WORD	Y;
	WORD	W;
	WORD	H;
	WORD	FID;
	} VPC = { 0,0,0,0,0 };


private EXAWORD AbalVisualViewPort(WORD x,WORD y,WORD w,WORD h,WORD fid)
{
	MI_TRACE_DCL_TFN("VisualViewPort");
	MI_TRACE_BEGIN();
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN x=%d y=%d w=%d h=%d",x,y,w,h));
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN fid=%d",fid));

#ifdef	_VISUAL_ECHO
	if ( VisualEcho & 2 ) {
		printf("VisualViewPort(%u,%u,%u,%u, %u )\r\n",
				x,y,w,h,fid);
		}
#endif
	
	VisualViewPort((VPC.X=x),(VPC.Y=y),(VPC.W=w),(VPC.H=h),(VPC.FID=fid));

	MI_TRACE_RETURN(0);
}

private EXAWORD AbalVisualButton(WORD x,WORD y,WORD w,WORD h,WORD fid,WORD fg, WORD bg,BPTR message,WORD length,WORD state)
{
	EXAWORD	retcode;
	MI_TRACE_DCL_TFN("VisualButton");
	MI_TRACE_BEGIN();
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN x=%d y=%d w=%d h=%d",x,y,w,h));
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN fid=%d fg=%d bg=%d state=%d",fid,fg,bg,state));

	message = terminate_string(message,length);
	length = clip_string( message,length );
#ifdef	_VISUAL_ECHO
	if ( VisualEcho & 2 ) {
		printf("VisualButton(%u,%u,%u,%u, %u, %u,%u, %c%s%c, %u, %u )\r\n",
				x,y,w,h,fid,fg,bg,
				0x0022,message,0x0022,length,state);
		}
#endif	
	reset_pixel_errors();
	styled_visual_button(x,y,w,h,fid,fg,bg,message,length,state);
	retcode = pixel_errors();
	MI_TRACE_RETURN(retcode);
}

#ifdef	_VISUAL_STYLE_MANAGER
private EXAWORD AbalVisualStyle(WORD x,WORD y,WORD w,WORD h,BPTR sptr, WORD slen, BPTR mptr, WORD mlen )
{
	int	i;
	EXAWORD	retcode;
	MI_TRACE_DCL_TFN("VisualStyle");
	MI_TRACE_BEGIN();
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN x=%d y=%d w=%d h=%d",x,y,w,h));

	for (i=0; i < slen; i++ ) {
		switch ((StyleName[i] = *(sptr+i))) {
			case	' '	:
			case	0	:
				break;
			default		:
				continue;
			}
		}
	StyleName[i] = 0;
	sptr = StyleName;	
	mptr = terminate_string( mptr, mlen );

#ifdef	_VISUAL_ECHO
	if ( VisualEcho & 2 ) {
		printf("VisualStyle(%u,%u,%u,%u, %c%s%c, %u )\r\n",x,y,w,h,0x0022,sptr,0x0022,slen );
		}
#endif	
	MI_TRACE((CI_TRA_F_DUMP,CI_MODULE_ID,TFN,"sptr:",sptr,slen));
	MI_TRACE((CI_TRA_F_DUMP,CI_MODULE_ID,TFN,"mptr:",mptr,mlen));
	VisualHide();
	retcode = visual_element( x,y,w,h, sptr, mptr, mlen );
	VisualShow(x,y,w,h);
	MI_TRACE_RETURN(retcode);
}
#endif

private EXAWORD AbalVisualCheck(WORD x,WORD y,WORD w,WORD h,WORD fid,WORD fg, WORD bg, BPTR message,WORD length,WORD state)
{
	EXAWORD	retcode;
	MI_TRACE_DCL_TFN("VisualCheck");
	MI_TRACE_BEGIN();
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN x=%d y=%d w=%d h=%d",x,y,w,h));
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN fid=%d fg=%d bg=%d state=%d",fid,fg,bg,state));

	message = terminate_string( message, length );

#ifdef	_VISUAL_ECHO
	if ( VisualEcho & 2 ) {
		printf("VisualCheck(%u,%u,%u,%u, %u, %u,%u, %c%s%c, %u, %u )\r\n",
				x,y,w,h,fid,fg,bg,
				0x0022,message,0x0022,length,state);
		}
#endif	
	reset_pixel_errors();
	styled_visual_check(x,y,w,h,fid,fg,bg,message,length,state);
	retcode = pixel_errors();
	MI_TRACE_RETURN(retcode);
}

private EXAWORD AbalVisualSwitch(WORD x,WORD y,WORD w,WORD h,WORD fid,WORD fg, WORD bg, BPTR message,WORD length,WORD state)
{
	EXAWORD	retcode;
	MI_TRACE_DCL_TFN("VisualSwitch");
	MI_TRACE_BEGIN();
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN x=%d y=%d w=%d h=%d",x,y,w,h));
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN fid=%d fg=%d bg=%d state=%d",fid,fg,bg,state));

	message = terminate_string( message, length );

#ifdef	_VISUAL_ECHO
	if ( VisualEcho & 2 ) {
		printf("VisualSwitch(%u,%u,%u,%u, %u, %u,%u, %c%s%c, %u, %u )\r\n",
				x,y,w,h,fid,fg,bg,
				0x0022,message,0x0022,length,state);
		}
#endif	
	reset_pixel_errors();
	styled_visual_switch(x,y,w,h,fid,fg,bg,message,length,state);
	retcode = pixel_errors();
	MI_TRACE_RETURN(retcode);
}

private EXAWORD AbalVisualGraph(WORD x,WORD y,WORD w,WORD h,WORD fid,WORD fg, WORD bg, BPTR values,WORD length,WORD state)
{
	EXAWORD	retcode;
	MI_TRACE_DCL_TFN("VisualGraph");
	MI_TRACE_BEGIN();
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN x=%d y=%d w=%d h=%d",x,y,w,h));
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN fid=%d fg=%d bg=%d state=%d",fid,fg,bg,state));

#ifdef	_VISUAL_ECHO
	if ( VisualEcho & 2 ) {
		printf("VisualGraph(%u,%u,%u,%u, %u, %u,%u, %u, %u )\r\n",
				x,y,w,h,fid,fg,bg,length,state);
		}
#endif	
	reset_pixel_errors();
	VisualGraph(x,y,w,h,fid,fg,bg,values,length,state);
	retcode = pixel_errors();
	MI_TRACE_RETURN(retcode);
}

private EXAWORD AbalVisualRadio(WORD x,WORD y,WORD w,WORD h,WORD fid,WORD fg, WORD bg, BPTR message,WORD length,WORD storage, WORD value)
{
	EXAWORD	retcode;
	MI_TRACE_DCL_TFN("VisualRadio");
	MI_TRACE_BEGIN();
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN x=%d y=%d w=%d h=%d",x,y,w,h));
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN fid=%d fg=%d bg=%d storage=%d value=%d",fid,fg,bg,storage,value));

	message = terminate_string( message, length );

#ifdef	_VISUAL_ECHO
	if ( VisualEcho & 2 ) {
		printf("VisualRadio(%u,%u,%u,%u, %u, %u,%u, %c%s%c, %u, %u,%u )\r\n",
				x,y,w,h,fid,fg,bg,
				0x0022,message,0x0022,length,storage,value);
		}
#endif	
	reset_pixel_errors();
	styled_visual_radio(x,y,w,h,fid,fg,bg,message,length,storage,value);
	retcode = pixel_errors();
	MI_TRACE_RETURN(retcode);
}

private EXAWORD AbalVisualProgress(WORD x,WORD y,WORD w,WORD h,WORD f, WORD fg, WORD bg, EXAWORD l,EXAWORD v, WORD o)
{
	EXAWORD	retcode;
	MI_TRACE_DCL_TFN("VisualProgress");
	MI_TRACE_BEGIN();
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN x=%d y=%d w=%d h=%d",x,y,w,h));
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN fg=%d bg=%d l=%d v=%d o=%d",fg,bg,l,v,o));

#ifdef	_VISUAL_ECHO
	if ( VisualEcho & 2 ) {
		printf("VisualProgress(%u,%u,%u,%u, %u, %u,%u, %u,%u, %u )\r\n",
				x,y,w,h,f,fg,bg,l,v,o);
		}
#endif	
	reset_pixel_errors();
	styled_visual_progress(x,y,w,h,f,fg,bg,l,v,o);
	retcode = pixel_errors();
	MI_TRACE_RETURN(retcode);
}

/*
 *	-------------------------------------------------------------------
 *
 *	--------------------	-------------------------------
 *	INTERFACE FUNCTION :	VISUAL BUFFER ( width, height )
 *	--------------------	-------------------------------
 *
 *	Allocates a pixel capture buffer mechanism of the w*h dimensions
 *	and returns a none zero buffer identifier to show Success or ZERO
 *	to indicate (usually memory allocation) Failure.
 *
 *	-------------------------------------------------------------------
 */

EXAWORD AbalVisualBuffer( WORD width, WORD height )
{
	WORD	i;
	struct	visualbuffer * vptr;
	MI_TRACE_DCL_TFN("VisualBuffer");
	MI_TRACE_BEGIN();
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN w=%d h=%d",width,height));
	
#ifdef	_VISUAL_ECHO
	if ( VisualEcho & 2 ) {
		printf("VisualBuffer(%u,%u)\r\n",width,height);
		}
#endif
	for (i=0; i < MAX_V_BUFFER; i++ )
		if (!( VisualBufferHeap[i] ))
			break;
	if ( i < MAX_V_BUFFER ) {
		if (!( vptr = allocate_visual_buffer()))
			MI_TRACE_RETURN(-1);
		else if (!( vptr->buffer = visual_buffer(0,0, width, height ) )) {
			release_visual_buffer( vptr );
			MI_TRACE_RETURN(-1);
			}		
		else	{
			VisualBufferHeap[i] = vptr;
			MI_TRACE_RETURN((i+1));
			}
		}
	else	
		MI_TRACE_RETURN( -1 );
}

/*
 *	-------------------------------------------------------------------
 *
 *		--------------------	-------------------
 *		INTERFACE FUNCTION :	VISUAL PAGE ( bid )
 *		--------------------	-------------------
 *
 *	Establishs the buffer mechanism identified by bid as the current 
 *	output catching mechanism. All pixel output will be caught and
 *	made available for pixel input.
 *
 *	Returns the buffer id or ZERO if none.
 *
 *	This function will disactivate any current buffer output mechanism
 *	prior to attempting its operation.
 *
 *	The buffer id ZERO indicates return to screen output !
 *	
 *	-------------------------------------------------------------------
 */

private	VOID	cico_visual_page( struct visualbuffer * vptr )
{
	vptr->column = x_col(1);
	vptr->row    = x_lin(1);
	vptr->foreground = x_conf(17);
	vptr->background = x_conf(18);
	return;
}

private	VOID	close_visual_page( struct visualbuffer * vptr )
{
	if ( vptr ) {
		if ( vptr->font != 0 ) {
			cico_visual_page(vptr);
			}
		if ( vptr->buffer ) {
			cancel_pixel_capture(vptr->buffer);
			}
		}
	return;
}

private	VOID	push_freeze_state()
{
	if ( VisualFreezeControl ) { 
		x_event( 300 ); 
		}
	return;
}
private	VOID	pop_freeze_state()
{
	if ( VisualFreezeControl ) { 
		x_event( 301 );
		}
	return;
}

EXAWORD AbalVisualPage( WORD number )
{
	struct	visualbuffer * vptr;
	MI_TRACE_DCL_TFN("VisualPage");
	MI_TRACE_BEGIN();
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN number=%d",number));

#ifdef	_VISUAL_ECHO
	if ( VisualEcho & 2 ) {
		printf("VisualPage(%u)\r\n",number);
		}
#endif
	if ( ActiveVisualBuffer != -1 ) {
		if ((vptr = VisualBufferHeap[ActiveVisualBuffer]) != (struct visualbuffer*) 0) {
			close_visual_page(vptr);
			}
		ActiveVisualBuffer = -1;
		VisualViewPort(0,0,0,0,0);
		if (!( number )) {
			pop_freeze_state();
			}
		}
	else	{
		if ( number ) {
			push_freeze_state();
			}
		}
	if (( number > 0 ) &&  ( number <= MAX_V_BUFFER )) {
		ActiveVisualBuffer=(number-1);
		if ( activate_visual_buffer() )
			return( number );
		else	return(0);
		}
	else	
		MI_TRACE_RETURN(0);
}

/*
 *	-------------------------------------------------------------------
 *
 *		--------------------	-------------------
 *		INTERFACE FUNCTION :	VISUAL DROP ( bid )
 *		--------------------	-------------------
 *	
 *	Disactivates and current active buffer and liberates the
 *	buffer identified by bid.
 *	
 *	Returns bid if ok otherwise zero to indicate failure.
 *
 *	-------------------------------------------------------------------
 */

EXAWORD AbalVisualDrop( WORD number )
{
	struct	visualbuffer * vptr; 
	MI_TRACE_DCL_TFN("VisualDrop");
	MI_TRACE_BEGIN();
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN number=%d",number));

#ifdef	_VISUAL_ECHO
	if ( VisualEcho & 2 ) {
		printf("VisualDrop(%u)\r\n",number);
		}
#endif
	if ( ActiveVisualBuffer != -1 ) {
		if ((vptr = VisualBufferHeap[ActiveVisualBuffer]) != (struct visualbuffer*) 0) {
			close_visual_page(vptr);
			}
		ActiveVisualBuffer = -1;
		}
	if (( number > 0 ) &&  ( number <= MAX_V_BUFFER )) {
		if (!( vptr = VisualBufferHeap[(number-1)] ))
			MI_TRACE_RETURN(0);
		else	{
			VisualBufferHeap[(number-1)] = release_visual_buffer( vptr );
			MI_TRACE_RETURN(number);
			}
		}
	else if ( number == 0 ) {
		for ( number=1; number <= MAX_V_BUFFER; number++ )
			AbalVisualDrop( number );
		MI_TRACE_RETURN(0);
		}
	else	
		MI_TRACE_RETURN(0);
}


/*
 *	--------------------	----------------------------
 *	INTERFACE FUNCTION :	VISUAL GET ( bid, atx, aty )
 *	--------------------	----------------------------
 *	
 *	Captures pixels to the buffer identified by bid from the pixel top 
 *	left corner atx,aty of the current Visual Buffer mechanism or from
 *	the Screen if none active, 
 *	
 *	Pixel coordinate values are numbered from 0 to N. 
 *
 *	Returns an indication of its status
 *
 *	-------------------------------------------------------------------
 */

EXAWORD AbalVisualGet( WORD bid, WORD atx, WORD aty )
{
	struct	visualbuffer * vptr;
	STDPSUPTR	pptr;
	MI_TRACE_DCL_TFN("VisualGet");
	MI_TRACE_BEGIN();
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN bid=%d x=%d y=%d",bid,atx,aty));
	
#ifdef	_VISUAL_ECHO
	if ( VisualEcho & 2 ) {
		printf("VisualGet(%u,%u,%u)\r\n",bid,atx,aty);
		}
#endif
	/* BID numbering from 1 please */
	/* --------------------------- */
	if (( bid < 1 ) || ( bid > MAX_V_BUFFER ))
		MI_TRACE_RETURN(0);

	/* No need to peform Get to/from oneself */
	/* ------------------------------------- */
	else if ((bid-1) == ActiveVisualBuffer)
		MI_TRACE_RETURN(0);

	/* Failure on invalid buffer control */
	/* --------------------------------- */
	else if (!( vptr = VisualBufferHeap[ (bid-1) ] )) 
		MI_TRACE_RETURN( 0 );
	else if (!( pptr = vptr->buffer ))
		MI_TRACE_RETURN(0);	
	else if ( visual_buffer_get( pptr, atx, aty ) )
		MI_TRACE_RETURN( bid );
	else	
		MI_TRACE_RETURN( 0 );
}


/*
 *	--------------------	--------------------------------------
 *	INTERFACE FUNCTION :	VISUAL GET ROW ( row, result, length )
 *	--------------------	--------------------------------------
 *	
 *	Returns a row of pixels into result up to length from the current
 *	Visual Buffer mechanism or from the Screen if none active.
 *	
 *	Rows are numbered from 1 to N for ABAL convenience
 *
 *	Returns confirmation of the row number or ZERO if failure.
 *
 *	-------------------------------------------------------------------
 */

EXAWORD AbalVisualGetRow( WORD row, BPTR buffer, WORD length )
{
	struct	visualbuffer * vptr;
	STDPSUPTR	pptr;
	MI_TRACE_DCL_TFN("VisualGetRow");
	MI_TRACE_BEGIN();
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN row=%d",row));

#ifdef	_VISUAL_ECHO
	if ( VisualEcho & 2 ) {
		printf("VisualGetRow(%u,%u)\r\n",row,length);
		}
#endif
	/* Row numbering from 1 please */
	/* --------------------------- */
	if ( row == 0 )
		MI_TRACE_RETURN( 0 );

	/* Check for no buffer active : get from screen */
	/* -------------------------------------------- */
	else if ( ActiveVisualBuffer == -1 )
		getzone( 0,(row-1),length,1, buffer);

	/* Failure on invalid buffer control */
	/* --------------------------------- */
	else if (!( vptr = VisualBufferHeap[ ActiveVisualBuffer ] ))
		MI_TRACE_RETURN( 0 );
	else if (!( pptr = vptr->buffer ))
		MI_TRACE_RETURN(0);	

	/* Collect from buffer mechanisms */
	/* ------------------------------ */
	else	collect_pixel_row( pptr, 0, (row-1), length, buffer );

	/* Success */
	/* ------- */
	MI_TRACE_RETURN( row );
}

/*
 *	--------------------	--------------------------------------
 *	INTERFACE FUNCTION :	VISUAL PUT ROW ( row, source, length )
 *	--------------------	--------------------------------------
 *	
 *	Outputs a row of pixels from source up to length into the current
 *	Visual Buffer mechanism or into the Screen if none active.
 *	
 *	Rows are numbered from 1 to N for ABAL convenience
 *
 *	Returns confirmation of the row number or ZERO if failure.
 *
 *	-------------------------------------------------------------------
 */

EXAWORD AbalVisualPutRow( WORD row, BPTR buffer, WORD length )
{
	struct	visualbuffer * vptr;
	BPTR		bptr;
	STDPSUPTR	pptr;
	MI_TRACE_DCL_TFN("VisualPutRow");
	MI_TRACE_BEGIN();
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN row=%d",row));

#ifdef	_VISUAL_ECHO
	if ( VisualEcho & 2 ) {
		printf("VisualPutRow(%u,%u)\r\n",row,length);
		}
#endif
	/* Row numbering from 1 please */
	/* --------------------------- */
	if ( row == 0 )
		MI_TRACE_RETURN( 0 );


	/* Check for no buffer active : get from screen */
	/* -------------------------------------------- */
	else if ( ActiveVisualBuffer == -1 )
		putzone( 0,(row-1),length,1, buffer);

	/* Failure on invalid buffer control */
	/* --------------------------------- */
	else if (!( vptr = VisualBufferHeap[ ActiveVisualBuffer ] ))
		MI_TRACE_RETURN( 0 );
	else if (!( pptr = vptr->buffer ))
		MI_TRACE_RETURN(0);	

	/* Collect row buffer from buffer mechanisms */
	/* ----------------------------------------- */
	else if (!( bptr = connect_pixel_row( pptr, (row-1) ) ))
		MI_TRACE_RETURN(0);

	/* and fill it from the source buffer */
	/* ---------------------------------- */
	else	memcpy( bptr, buffer, length );

	/* Success */
	/* ------- */
	MI_TRACE_RETURN( row );
}

EXAWORD AbalVisualPutZone( WORD x, WORD y, WORD w, WORD h,BPTR buffer )
{
	MI_TRACE_DCL_TFN("VisualPutZone");
	MI_TRACE_BEGIN();
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN x=%d y=%d w=%d h=%d",x,y,w,h));

#ifdef	_VISUAL_ECHO
	if ( VisualEcho & 2 ) {
		printf("VisualPutZone(%u,%u,%u,%u)\r\n",x,y,w,h);
		}
#endif
	putzone(x,y,w,h,buffer);
	MI_TRACE_RETURN(0);
}

/*
 *	--------------------	----------------------------
 *	INTERFACE FUNCTION :	VISUAL PUT ( bid, atx, aty )
 *	--------------------	----------------------------
 *	
 *	Outputs the contents of the buffer identified by bid at the
 *	pixel top left corner position identifier by atx,aty to the 
 *	current Visual Buffer mechanism or to the Screen if none active.
 *	
 *	Pixel coordinate values are numbered from 0 to N. 
 *
 *	Returns an indication of its status
 *
 *	-------------------------------------------------------------------
 */

EXAWORD AbalVisualPut( WORD bid, WORD atx, WORD aty )
{
	struct	visualbuffer * vptr;
	STDPSUPTR	pptr;
	MI_TRACE_DCL_TFN("VisualPut");
	MI_TRACE_BEGIN();
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN bid=%d x=%d y=%d",bid,atx,aty));

#ifdef	_VISUAL_ECHO
	if ( VisualEcho & 2 ) {
		printf("VisualPut(%u,%u,%u)\r\n",bid,atx,aty);
		}
#endif
	/* BID numbering from 1 please */
	/* --------------------------- */
	if (( bid < 1 ) || ( bid > MAX_V_BUFFER ))
		MI_TRACE_RETURN(bid);

	/* No need for this */
	/* ---------------- */
	else if ((bid-1) == ActiveVisualBuffer)
		MI_TRACE_RETURN(0);

	/* Failure on invalid buffer control */
	/* --------------------------------- */
	else if (!( vptr = VisualBufferHeap[ (bid-1) ] ))
		MI_TRACE_RETURN( 0 );
	else if (!( pptr = vptr->buffer ))
		MI_TRACE_RETURN(0);	

	else if (!( visual_buffer_put( pptr, atx, aty ) ))
		MI_TRACE_RETURN( 0);
	else	
		MI_TRACE_RETURN( bid );

}

/*
 *	--------------------	------------------------------------
 *	INTERFACE FUNCTION :	VISUAL TRANSFORM (bid, cmd, p1, p2 )
 *	--------------------	------------------------------------
 *	
 *	Performs transformation described by cmd on buffer identified
 *	by bid activetool operation dependant parameters p1 and p2
 *
 *	0 :	Rotate	p1 distance, 90, 180, 270
 *	1 :	Reflect	p1 direction 0:vertical axis, 1:horizontal axis
 *	2 :	Resize  p1,p2 provides new coordinates for cut or fill
 *	3 :	Makefit p1,p2 provides new coordinates for squash or stretc
 *	4 :	Colour  p1 0,1,2 r,g,b p2 value ( signed byte )
 *
 */

#include "vreflect.c"

private	void	resize_stdpsu( int atx,int aty, int nbx, int nby , STDPSUPTR vptr )
{
	struct standard_image 	image;
	image.rows    = vptr->descriptor[1];
	image.columns = vptr->descriptor[0];
	image.storage = vptr;
	image.users   = 1;
	image.palette = NULL;
	image.format  = vptr->descriptor[6];
	drawimage( atx, aty, nbx, nby, &image, 0);
}

private	void	makefit_stdpsu( int atx,int aty, int nbx, int nby , STDPSUPTR vptr )
{
	struct standard_image 	image;
	image.rows    = vptr->descriptor[1];
	image.columns = vptr->descriptor[0];
	image.storage = vptr;
	image.users   = 1;
	image.palette = NULL;
	image.format  = vptr->descriptor[6];
	drawimage( atx, aty, nbx, nby, &image, 5);
}




EXAWORD AbalVisualTransform( WORD bid, WORD cmd, WORD p1, WORD p2 )
{
	struct	visualbuffer * vptr;
	WORD		vbh;
	STDPSUPTR	pptr;
	STDPSUPTR	rptr;
	EXAWORD	retcode;

	MI_TRACE_DCL_TFN("VisualTransform");
	MI_TRACE_BEGIN();
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN bid=%d cmd=%d p1=%d p2=%d",bid,cmd,p1,p2));

#ifdef	_VISUAL_ECHO
	if ( VisualEcho & 2 ) {
		printf("VisualTransform(%u,%u,%u,%u)\r\n",bid,cmd,p1,p2);
		}
#endif
	if ( ActiveVisualBuffer != -1 ) {
		if ((vptr = VisualBufferHeap[ActiveVisualBuffer]) != (struct visualbuffer*) 0) {
			close_visual_page(vptr);
			}
		ActiveVisualBuffer = -1;
		}

	/* BID numbering from 1 please */
	/* --------------------------- */
	if (( bid < 1 ) || ( bid > MAX_V_BUFFER ))
		MI_TRACE_RETURN(56);

	/* Failure on invalid buffer control */
	/* --------------------------------- */
	else if (!( vptr = VisualBufferHeap[ (bid-1) ] ))
		MI_TRACE_RETURN(56);
	else if (!( pptr = vptr->buffer ))
		MI_TRACE_RETURN( 56 );

	switch ( cmd ) {

		case	_TRANSFORM_ROTATE	:
			if ( p1 == 180 )
				{
				retcode = vrotate180( pptr );
				MI_TRACE_RETURN( retcode );
				}
			else if (!( rptr = allocate_graphic_storage( 0,0,pptr->descriptor[1],pptr->descriptor[0] ) ))
				MI_TRACE_RETURN(27);
			else 	{
				if ( p1 == 90 )
					p1 = vrotate(1, rptr, pptr  );
				else	p1 = vrotate(0, rptr, pptr  );
				if (!( p1 )) {
					pptr = liberate_pixel_storage( pptr );
					vptr->buffer = rptr;
					vbh = vptr->height;
					vptr->width = vptr->height;
					vptr->height= vbh;
					}
				else	rptr = liberate_pixel_storage( rptr );
				MI_TRACE_RETURN( p1 );
				}

		case	_TRANSFORM_REFLECT	:

			switch ( p1 ) {
				case	0	: return( visual_reflect_v( pptr ) );
				case	1	: return( visual_reflect_h( pptr ) );
				default		: return( 55 );
				}


		case	_TRANSFORM_COLOUR	:
			switch ( p1 ) {
				case	0	: return( visual_hue( pptr, (p2 & 0x00FF), 0, 0 ) );
				case	1	: return( visual_hue( pptr, 0, (p2 & 0x00FF), 0 ) );
				case	2	: return( visual_hue( pptr, 0, 0, (p2 & 0x00FF) ) );
				default		: return( 55 );
				}
		case	_TRANSFORM_RESIZE	:
			if ((!( p1 )) || (!( p2 )))
				return(118);
			else if (!( rptr = allocate_graphic_storage( 0,0,p1, p2 ) ))
				return(27);
			else	{
				background_pixel_capture( rptr );
				resize_stdpsu(0,0,p1,p2,pptr);
				pptr = liberate_pixel_storage( pptr );
				vptr->buffer = rptr;
				vptr->width = p1;
				vptr->height= p2;
				cancel_pixel_capture(rptr);
				if ( ActiveVisualBuffer != -1 )
					activate_visual_buffer();
				return(0);
				}


		case	_TRANSFORM_MAKEFIT	:

			if ((!( p1 )) || (!( p2 )))
				return(118);
			else if (!( rptr = allocate_graphic_storage( 0,0,p1, p2 ) ))
				return(27);
			else	{
				background_pixel_capture( rptr );
				makefit_stdpsu(0,0,p1,p2,pptr);
				pptr = liberate_pixel_storage( pptr );
				vptr->buffer = rptr;
				vptr->width = p1;
				vptr->height= p2;
				cancel_pixel_capture(rptr);
				if ( ActiveVisualBuffer != -1 )
					activate_visual_buffer();
				return(0);
				}


		default				:

			MI_TRACE_RETURN( 55 );

		}

}

/*
 *	--------------------	-------------------------------------------
 *	INTERFACE FUNCTION :	VISUAL COLOUR  ( cmd, buffer, first, last )
 *	--------------------	-------------------------------------------
 *	
 *	Performs the indicated colour operation activetool the buffer from the
 *	the first to last colour map entries.
 *
 *	-------------------------------------------------------------------
 *	Commands ARE :	0	Get colours
 *			1	Put colours
 *			2	Get Red Value
 *			3	Get Green Value
 *			4	Get Blue Value
 *			5	Put Red Value
 *			6	Put Green Value
 *			7	Put Blue Value
 *	-------------------------------------------------------------------
 *	others MAY be:	8	Increment Red
 *			9	Increment Green
 *			10	Increment Blue
 *			11	Decrement Red
 *			12	Decrement Green
 *			13	Decrement Blue
 *	-------------------------------------------------------------------
 *	Returns the status of the requested operation which may fail 
 *	due to an incorrect command.
 *	-------------------------------------------------------------------
 */

EXAWORD AbalVisualColour( WORD cmd, BPTR buffer, WORD first, WORD last )
{
	int	result;
	MI_TRACE_DCL_TFN("VisualColour");
	MI_TRACE_BEGIN();
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN cmd=%d first=%d last=%d",cmd,first,last));

	result = VisualColour( cmd, buffer, first, last ) ;
	MI_TRACE_RETURN(result);
}


EXAWORD AbalVisualTable( WORD x, WORD y, WORD w, WORD h, WORD f, WORD fg, WORD bg,
		BPTR tptr, WORD tlen, BPTR vptr, WORD vlen, WORD options,BPTR fptr, WORD flen )
{
	EXAWORD	lfocus=0;
	EXAWORD	retcode;
	MI_TRACE_DCL_TFN("VisualTable");
	MI_TRACE_BEGIN();
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN x=%d y=%d w=%d h=%d",x,y,w,h));

	tptr = terminate_string( tptr, tlen);

#ifdef	_VISUAL_ECHO
	if ( VisualEcho & 2 ) {
		printf("VisualTable(%u,%u,%u,%u, %u, %u,%u, %c%s%c,%u )\r\n",
			x,y,w,h,f,fg,bg,
			0x0022,tptr,0x0022,tlen);
		}
#endif	
	reset_pixel_errors();
	styled_visual_table(x,y,w,h,f,fg,bg,tptr,vptr,options,fptr);
	retcode = pixel_errors();
	MI_TRACE_RETURN(retcode);
}

private EXAWORD AbalVisualImage(WORD x,WORD y,WORD w,WORD h,BPTR filename,WORD length, WORD options) 
{
	EXAWORD	retcode;
	MI_TRACE_DCL_TFN("VisualImage");
	MI_TRACE_BEGIN();
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN x=%d y=%d w=%d h=%d",x,y,w,h));

	filename = terminate_string(filename,length);
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN name='%s'",MI_TRA_TRUNCLG(filename,length) ));
	clip_string( filename,length);
		
#ifdef	_VISUAL_ECHO
	if ( VisualEcho & 2 ) {
		printf("VisualImage(%u,%u,%u,%u, %c%s%c,%u, %u)\r\n",
			x,y,w,h,
			0x0022,filename,0x0022,length,options);
		}
#endif	
	reset_pixel_errors();
	VisualImage(x,y,w,h,filename,length,options );
	retcode = pixel_errors();
	MI_TRACE_RETURN(retcode);
}


private EXAWORD AbalVisualTabPage(WORD x,WORD y,WORD w,WORD h,WORD fid,BPTR title,WORD length,WORD offset,WORD control)
{
	EXAWORD	retcode;
	MI_TRACE_DCL_TFN("VisualTabPage");
	MI_TRACE_BEGIN();
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN x=%d y=%d w=%d h=%d",x,y,w,h));

	title = terminate_string( title, length );
#ifdef	_VISUAL_ECHO
	if ( VisualEcho & 2 ) {
		printf("VisualTabPage(%u,%u,%u,%u, %u, %c%s%c,%u, %u,%u)\r\n",
			x,y,w,h,fid,
			0x0022,title,0x0022,length,offset,control);
		}
#endif	
	reset_pixel_errors();
	styled_visual_tabpage(x,y,w,h,fid,title,length,offset,control);
	retcode = pixel_errors();
	MI_TRACE_RETURN(retcode);
}

private EXAWORD AbalVisualSelect(
		WORD x,WORD y,WORD w,WORD h,
		WORD fid, WORD fg, WORD bg, 
		BPTR message,WORD length,BPTR iptr,WORD state)
{
	unsigned int	item;
	int	keycode;
	MI_TRACE_DCL_TFN("VisualSelect");
	MI_TRACE_BEGIN();
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN x=%d y=%d w=%d h=%d",x,y,w,h));

	message = terminate_string( message, length );
	if ((item = AbalGetWord( iptr )) > 0)
		item--;

#ifdef	_VISUAL_ECHO
	if ( VisualEcho & 2 ) {
		printf("VisualSelect(%u,%u,%u,%u, %u, %u,%u, %c%s%c,%u, %u,%u)\r\n",x,y,w,h,fid,fg,bg,
			0x0022,message,0x0022,length,item,state);
		}
#endif	
	keycode = styled_visual_select(x,y,w,h,fid,fg,bg,message,length,&item,state);

	if ( keycode != 27 ) {
		item++;
		AbalPutWord( iptr, item );
		}
	MI_TRACE_RETURN( keycode );
}


private EXAWORD AbalVisualScroll(WORD x,WORD y,WORD w,WORD h,WORD fid,WORD fg, WORD bg, EXAWORD item, EXAWORD limit, EXAWORD total, WORD style)
{
	MI_TRACE_DCL_TFN("VisualScroll");
	MI_TRACE_BEGIN();
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN x=%u y=%u w=%u h=%u",x,y,w,h));
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN fid=%u fg=%u bg=%u",fid,fg,bg));
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN  item=%lu limit=%lu total=%lu style=%u",item,limit,total,style));

#ifdef	_VISUAL_ECHO
	if ( VisualEcho & 2 ) {
		printf("VisualScroll(%u,%u,%u,%u, %u, %u,%u, %u,%u,%u , %u)\r\n",x,y,w,h,fid,fg,bg,item,limit,total,style);
		}
#endif	
	styled_visual_scroll(x,y,w,h,fid,fg,bg,item,limit,total,style);
	MI_TRACE_RETURN(0);
}

private EXAWORD AbalVisualPalette(BPTR filename,WORD length)
{
	BPTR	sptr;
	EXAWORD	retcode;
	MI_TRACE_DCL_TFN("VisualPalette");
	MI_TRACE_BEGIN();

	filename = terminate_string(filename,length);
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN name='%s'",MI_TRA_TRUNCLG(filename,length) ));
#ifdef	_VISUAL_ECHO
	if ( VisualEcho & 2 ) {
		printf("VisualPalette(%c%s%c,%u)\r\n",0x0022,filename,0x0022,length);
		}
#endif	
	reset_pixel_errors();
	if (!(  strcmp( filename, "PALETTE" ))) {
		if (!( sptr = get_system_palette() ))
			sptr = filename;
		else	length = strlen( sptr );	
		}
	else if (!( sptr = configuration_item( filename )))
		sptr = filename;
	else	length = strlen( sptr );	

	VisualPalette(sptr,length);
	retcode = pixel_errors();
	MI_TRACE_RETURN(retcode);
}

private EXAWORD AbalVisualFreeze()
{
	MI_TRACE_DCL_TFN("VisualFreeze");
	MI_TRACE_BEGIN();

#ifdef	_VISUAL_ECHO
	if ( VisualEcho & 2 ) {
		printf("VisualFreeze()\r\n");
		}
#endif	
	freeze_control(0);
	VisualFreeze();
	MI_TRACE_RETURN(0);
}

private EXAWORD AbalVisualThaw(WORD x,WORD y,WORD w,WORD h)
{
	EXAWORD	retcode;
	MI_TRACE_DCL_TFN("VisualThaw");
	MI_TRACE_BEGIN();
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN x=%d y=%d w=%d h=%d",x,y,w,h));

#ifdef	_VISUAL_ECHO
	if ( VisualEcho & 2 ) {
		printf("VisualThaw(%u,%u,%u,%u)\r\n",x,y,w,h);
		}
#endif	
	reset_pixel_errors();
	VisualThaw(x,y,w,h);
	freeze_control(1);
	retcode = pixel_errors();
	MI_TRACE_RETURN(retcode);
}

private	VOID	PutAbalWord( BPTR rptr, WORD v )
{
	*(rptr+1) = (v & 0x00FF);
	*(rptr)   = ((v>>8) & 0x00FF);
	return;
}

private EXAWORD AbalVisualEvent(BPTR result)
{
	WORD	v;
	WORD	e;
	WORD	c;
	WORD	l;
	MI_TRACE_DCL_TFN("VisualEvent");
	MI_TRACE_BEGIN();

	e = VisualEvent(1);
	PutAbalWord(result,e);
	v = VisualEvent(2);
	PutAbalWord(result+2,v);
	if (((l = VisualEvent(7)) != 0)
	||  (e != _MIMO_UP ))
		PutAbalWord(result+4,l);
	if (((c = VisualEvent(6)) != 0)
	||  (e != _MIMO_UP ))
		PutAbalWord(result+6,c);
	// printf("VisualEvent(%u,%u,%u,%u)\r\n",e,v,c,l);
	MI_TRACE_RETURN(256);
}

private EXAWORD AbalVisualKey(WORD mode)
{
	EXAWORD retcode;
	MI_TRACE_DCL_TFN("VisualKey");
	MI_TRACE_BEGIN();
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN mode=%d",mode));

	switch ( mode ) {
		case	0 :	
			retcode = VisualKbhit();
			MI_TRACE_RETURN( retcode );

		case 	2 :	
			if (!( VisualKbhit() )) 
				break;

		case	1 :	
			retcode = VisualGetch();
			MI_TRACE_RETURN( retcode );
		}

	MI_TRACE_RETURN(-1);
}

#ifdef	UNIX
#include "vclip.c"
#endif

private EXAWORD AbalVisualControl(WORD command, BPTR buffer, WORD buflen )
{
	EXAWORD retcode;
	struct	visualbuffer * vbptr;
	struct	standard_image * iptr;
	STDPSUPTR	pptr;
	char	*	vptr;
	char	*	nptr;
	int	i;
	int		fontid;
	char 	*	nomfic;
	int		status;
	int		iwidth;
	int		iheight;
#ifdef WIN32
	char buftmp[10];
#endif

#ifdef UNIX
	char *	standard_font_name(int);
#endif

	MI_TRACE_DCL_TFN("VisualControl");
	MI_TRACE_BEGIN();
	MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN cmd=%d",command));

#ifdef	_VISUAL_ECHO
	if ( VisualEcho & 2 ) {
		printf("VisualControl(%u)\r\n",command);
		}
#endif	
	switch ( command ) {
		case	_VISUAL_VERSION		:	/* 0 */
#ifdef WIN32
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_VERSION"));
			vptr = Banner_GetVersionID( buftmp, Banner_GetVersionStatus());
			if ( buflen < strlen(buftmp) )
				MI_TRACE_RETURN(63);
#else
			if (!( vptr = getpatternversion() ))
				return(56);
			else if ( buflen < strlen(vptr ) )
				return(63);
#endif
			else	{
				memset(buffer,' ',buflen );
				while ( *vptr )
					*(buffer++) = *(vptr++);
				MI_TRACE_RETURN(0);
				}

		case	_VISUAL_CONFIG		:	/* 1 */
			buffer = terminate_string(buffer,buflen);
			terminate_configuration();
			set_configuration_name( buffer );
			initialise_configuration( buffer );
			MI_TRACE_RETURN(0);
			break;

		case	_VISUAL_RECORD 		:
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_RECORD"));
			buffer = terminate_string(buffer,buflen);
			retcode = activate_record( buffer );
			MI_TRACE_RETURN( retcode );

		case	_VISUAL_REPLAY 		:
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_REPLAY"));
			buffer = terminate_string(buffer,buflen);
			retcode = activate_replay( buffer );
			MI_TRACE_RETURN( retcode );

		
		case	_VISUAL_BUFFERWIDTH	:
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_BUFFERWIDTH"));
			if (!(i = convert_integer( buffer )))
				if (!( i = buflen ))
					MI_TRACE_RETURN(0);
			if ((i >= 1 ) && ( i <= MAX_V_BUFFER)) {
				if (!( vbptr = VisualBufferHeap[(i-1)] ))
					MI_TRACE_RETURN(0);
				else if (!( pptr = vbptr->buffer ))
					MI_TRACE_RETURN(0);
				else	
					MI_TRACE_RETURN( pptr->descriptor[0] );
				}
			else	
				MI_TRACE_RETURN(0);

		case	_VISUAL_TEXTLENGTH	:
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_TEXTLENGTH"));
			fontid=buflen;
			buflen = rt_arg.l[1];
			buffer = terminate_string(buffer,buflen);
			retcode = textsizelen(fontid, buffer, buflen );
			MI_TRACE_RETURN( retcode );

		case	_VISUAL_BUFFERHEIGHT	:
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_BUFFERHEIGHT"));
			if (!(i = convert_integer( buffer )))
				if (!( i = buflen ))
					MI_TRACE_RETURN(0);
			if ((i >= 1 ) && ( i <= MAX_V_BUFFER)) {
				if (!( vbptr = VisualBufferHeap[(i-1)] ))
					MI_TRACE_RETURN(0);
				else if (!( pptr = vbptr->buffer ))
					MI_TRACE_RETURN(0);
				else	
					MI_TRACE_RETURN( pptr->descriptor[1] );
				}
			else	
				MI_TRACE_RETURN( 0 );

		case	_VISUAL_FONTWIDTH	:
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_FONTWIDTH"));
			if (!(i = convert_integer( buffer )))
				if (!( i = buflen ))
					MI_TRACE_RETURN(0);
			if (!( i = guifontsize(i) ))
				MI_TRACE_RETURN(0);
			else	MI_TRACE_RETURN( i & 0x00FF );

		case	_VISUAL_FONTHEIGHT	:
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_FONTHEIGHT"));
			if (!(i = convert_integer( buffer )))
				if (!( i = buflen ))
					MI_TRACE_RETURN(0);
			if (!( i = guifontsize(i) ))
				MI_TRACE_RETURN(0);
			else	MI_TRACE_RETURN(( i >> 8) & 0x00FF );

		case	_VISUAL_TRACE  		:
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_TRACE"));
			buffer = terminate_string(buffer,buflen);
			printf("%s\r\n",buffer);
			MI_TRACE_RETURN(0);

		case	_VISUAL_TITLE 		:
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_TITLE"));
			buffer = terminate_string(buffer,buflen);
			windowtitle( buffer );
			MI_TRACE_RETURN(0);

		case	_VISUAL_ICON 		:
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_ICON"));
			buffer = terminate_string(buffer,buflen);
			windowicon( buffer );
			MI_TRACE_RETURN(0);

		case	_VISUAL_HELP 		:
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_HELP"));
			buffer = terminate_string(buffer,buflen);
			retcode = visual_help( buffer );
			MI_TRACE_RETURN( retcode );

		case	_VISUAL_HOTKEY	:
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_HOTKEY"));
			visual_hotkeys( buffer, buflen );
			MI_TRACE_RETURN(0);

		case	_VISUAL_SETKEYS	:
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_SETKEYS"));
			retcode = visual_edit_keys( 1, buffer, buflen );
			MI_TRACE_RETURN( retcode );

		case	_VISUAL_GETKEYS	:
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_GETKEYS"));
			retcode = visual_edit_keys( 0, buffer, buflen );
			MI_TRACE_RETURN( retcode );

		case	_VISUAL_SETEDIT	:
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_SETEDIT"));
			retcode = visual_edit_keys( 3, buffer, buflen );
			MI_TRACE_RETURN( retcode );

		case	_VISUAL_GETEDIT	:
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_GETEDIT"));
			retcode = visual_edit_keys( 2, buffer, buflen );
			MI_TRACE_RETURN( retcode );

		case	_VISUAL_LANGUAGE	:
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_LANGUAGE"));
			retcode = visual_national_language((buflen-1)) + 1;
			MI_TRACE_RETURN( retcode );

		case	_VISUAL_TRIGGER	:
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_TRIGGER"));
			retcode = visual_trigger_code(buffer,buflen);
			MI_TRACE_RETURN( retcode );

		case	_VISUAL_PUSHVIEWPORT	:
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_PUSHVIEWPORT"));
			if( buflen >= 16 ) {
				AbalPutWord( buffer,      5      );
				AbalPutWord( (buffer+2),  VPC.X  );
				AbalPutWord( (buffer+4),  VPC.Y  );
				AbalPutWord( (buffer+6),  VPC.W  );
				AbalPutWord( (buffer+8),  VPC.H  );
				AbalPutWord( (buffer+10), VPC.FID);
				AbalPutWord( (buffer+12), 0 );
				AbalPutWord( (buffer+14), 0 );
				MI_TRACE_RETURN(0);
				}
			else	MI_TRACE_RETURN( 62 );

		case	_VISUAL_POPVIEWPORT	:
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_POPVIEWPORT"));
			if( buflen >= 16 ) {
				VPC.X   = AbalGetWord( (buffer+2) );
				VPC.Y   = AbalGetWord( (buffer+ 4) );
				VPC.W   = AbalGetWord( (buffer+ 6) );
				VPC.H   = AbalGetWord( (buffer+ 8) );
				VPC.FID = AbalGetWord( (buffer+10) );
				VisualViewPort(VPC.X,VPC.Y,VPC.W,VPC.H,VPC.FID);
				MI_TRACE_RETURN(0);
				}
			else	MI_TRACE_RETURN( 62 );

		case	_VISUAL_PAGEVIEWPORT	:
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_PAGEVIEWPORT"));
			if (!(i = (ActiveVisualBuffer+1)))
				MI_TRACE_RETURN(0);
			if ((i >= 1 ) && ( i <= MAX_V_BUFFER)) {
				if (!( vbptr = VisualBufferHeap[(i-1)] ))
					MI_TRACE_RETURN(0);
				else	{
					vbptr->x 	= VPC.X;
					vbptr->y 	= VPC.Y;
					vbptr->width	= VPC.W;
					vbptr->height	= VPC.H;
					vbptr->font	= VPC.FID;
					cico_visual_page(vbptr);
					MI_TRACE_RETURN(i);
					}
				}
			else	MI_TRACE_RETURN(0);

		case	_VISUAL_IMAGENAME	:
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_IMAGENAME"));
			if (!(i = convert_integer( buffer )))
				MI_TRACE_RETURN(102);
			memset(buffer,' ',buflen);
			if (!(nptr = resolve_imagename_by_number( i )))
				MI_TRACE_RETURN(40);
			for (i=0; i < buflen; i++) {
				if (!( *(nptr+i) ))
					break;
				else 	*(buffer+i) =  *(nptr+i);
				}
			if (!( *(nptr+i) ))
				MI_TRACE_RETURN(0);	
			else	MI_TRACE_RETURN(63);
	
		case	_VISUAL_FONTNAME	:
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_FONTNAME"));
			if (!(i = convert_integer( buffer )))
				MI_TRACE_RETURN(102);
			memset(buffer,' ',buflen);
			if (!(nptr = standard_font_name( i )))
				MI_TRACE_RETURN(40);
			for (i=0; i < buflen; i++) {
				if (!( *(nptr+i) ))
					break;
				else 	*(buffer+i) =  *(nptr+i);
				}
			if (!( *(nptr+i) ))
				MI_TRACE_RETURN(0);	
			else	MI_TRACE_RETURN(63);

		case	_VISUAL_IMAGEWIDTH	:
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_IMAGEWIDTH"));
			if (!(i = convert_integer( buffer )))
				if (!( i = buflen ))
					MI_TRACE_RETURN(0);
			if (!(iptr = resolve_image_by_number( i )))
				MI_TRACE_RETURN(0);
			else	MI_TRACE_RETURN(iptr->columns);
		
		case	_VISUAL_IMAGEHEIGHT	:
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_IMAGEHEIGHT"));
			if (!(i = convert_integer( buffer )))
				if (!( i = buflen ))
					MI_TRACE_RETURN(0);
			if (!(iptr = resolve_image_by_number( i )))
				MI_TRACE_RETURN(0);
			else	MI_TRACE_RETURN(iptr->rows);

		case	_VISUAL_IMAGECOUNT	:
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_IMAGECOUNT"));
			retcode = image_heap_count();
			MI_TRACE_RETURN( retcode );

		case	_VISUAL_IMAGEINFO	:
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_IMAGEINFO"));
			if ( buflen < 4)
				MI_TRACE_RETURN( 122 );
			else	{
				buflen -= 4;
				nomfic = terminate_string((buffer+4),buflen);
				if ((status = visual_image_info( nomfic, &iwidth, &iheight )) != 0)
					MI_TRACE_RETURN( status );
				else	{
					AbalPutWord( buffer,      iwidth );
					AbalPutWord( (buffer+2),  iheight);
					MI_TRACE_RETURN( 0 );
					}
				}

		case	_VISUAL_TABLEFOCUS 	:
			retcode = visual_table_focus( buflen );
			MI_TRACE_RETURN( retcode );

		case	_VISUAL_DROPIMAGE	:
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_DROPIMAGE"));
			buffer = terminate_string(buffer,buflen);
			retcode = imageheap_drop_item(buffer);
			MI_TRACE_RETURN( retcode );

#ifdef	_VISUAL_ATB_MANAGER
		case	_VISUAL_ATRIBUT		:
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_ATRIBUT"));
			MI_TRACE((CI_TRA_F_DUMP,CI_MODULE_ID,TFN,"buffer:",buffer,buflen));
			retcode = define_visual_atribut(buffer,buflen);
			MI_TRACE_RETURN( retcode );
#endif

		case	_VISUAL_PAGE		:
			return( ActiveVisualBuffer + 1 );

		case	_VISUAL_EDITLIN		:
			return( get_visual_editline() );
		case	_VISUAL_EDITCOL		:
			return( get_visual_editcol() );

#ifdef	_VISUAL_STYLE_MANAGER
		case	_VISUAL_STYLEHEIGHT	:
			buffer = terminate_string(buffer,buflen);
			return( resolve_style_height( buffer ) );
		case	_VISUAL_STYLEWIDTH	:
			buffer = terminate_string(buffer,buflen);
			return( resolve_style_width( buffer ) );
		case	_VISUAL_STYLEFONT 	:
			buffer = terminate_string(buffer,buflen);
			return( resolve_style_font( buffer ) );

		case	_VISUAL_DROPSTYLE	:
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_DROPSTYLE"));
			MI_TRACE((CI_TRA_F_DUMP,CI_MODULE_ID,TFN,"buffer:",buffer,buflen));
			buffer = terminate_string(buffer,buflen);
			status = drop_visual_style(buffer,buflen);
			detect_default_style();
			MI_TRACE_RETURN( status );

		case	_VISUAL_STYLE 		:
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_STYLE"));
			MI_TRACE((CI_TRA_F_DUMP,CI_MODULE_ID,TFN,"buffer:",buffer,buflen));
			status = load_visual_style(buffer,buflen);
			detect_default_style();
			MI_TRACE_RETURN( status );
#ifdef	ABAL32A
		case	_VISUAL_DOMAIN		:
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_DOMAIN"));
			MI_TRACE((CI_TRA_F_DUMP,CI_MODULE_ID,TFN,"buffer:",buffer,buflen));
			buffer = terminate_string(buffer,buflen);
			status = set_style_domain(buffer);
			detect_default_style();
			MI_TRACE_RETURN( status );
	
		case	_VISUAL_CLASS 		:
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_CLASS"));
			MI_TRACE((CI_TRA_F_DUMP,CI_MODULE_ID,TFN,"buffer:",buffer,buflen));
			buffer = terminate_string(buffer,buflen);
			status = define_visual_style(buffer,buflen);
			detect_default_style();
			MI_TRACE_RETURN( status );
#endif	
#endif

#ifdef	_VISUAL_ECHO
		case	_VISUAL_ECHO		:
			VisualEcho = buflen;
			return(0);
#endif

#ifdef	_VISUAL_SAVEBMP
		case	_VISUAL_SAVEBMP		:
			buffer = terminate_string(buffer,buflen);
			return( visual_screen_capture( buffer, 0 ) );
#endif
#ifdef	_VISUAL_SAVEGIF
		case	_VISUAL_SAVEGIF		:
			buffer = terminate_string(buffer,buflen);
			return( visual_screen_capture( buffer, 1 ) );
#endif
#ifdef	_VISUAL_SAVEJPG
		case	_VISUAL_SAVEJPG		:
			buffer = terminate_string(buffer,buflen);
			return( visual_screen_capture( buffer, 2 ) );
#endif
#ifdef	_VISUAL_SAVEPNG
		case	_VISUAL_SAVEPNG		:
			buffer = terminate_string(buffer,buflen);
			return( visual_screen_capture( buffer, 3 ) );
#endif

		case	_VISUAL_CONVISO		:
			/* Conversion of an ISO 8859-1 string to the internal equivalent */
			/* ------------------------------------------------------------- */
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_CONVISO"));
			MI_TRACE((CI_TRA_F_DUMP,CI_MODULE_ID,TFN,"buffer:",buffer,buflen));
#ifdef WIN32
			status = ConvAnsiToOem_byexa(buffer,buflen);
			MI_TRACE_RETURN( status );
#else
			for ( i=0; i < buflen; i++ )
				*(buffer+i) =  ansi_iso_character_set[  ( *(buffer+i) & 0x00FF ) ];
			MI_TRACE_RETURN(0);
#endif

		case	_VISUAL_CONVPRL		:
			/* Conversion of a prologue string to the iso ansi equivalent */
			/* ------------------------------------------------------------- */
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_CONVPRL"));
			MI_TRACE((CI_TRA_F_DUMP,CI_MODULE_ID,TFN,"buffer:",buffer,buflen));
#ifdef WIN32
			status = ConvOemToAnsi_byexa(buffer,buflen);
			MI_TRACE_RETURN( status );
#else
			for ( i=0; i < buflen; i++ )
				*(buffer+i) =  prologue_character_set[  ( *(buffer+i) & 0x00FF ) ];
			MI_TRACE_RETURN(0);
#endif

#ifdef	_VISUAL_STATUS
		case	_VISUAL_STATUS	:
				return( VisualLibraryStatus );
#endif
#ifdef	_VISUAL_DEFAULT
		case	_VISUAL_DEFAULT	:
			i = use_overload_style;
			use_overload_style = buflen;
			return( i );
#endif

		case	999			:
			buffer = terminate_string( buffer, buflen);
			printf("vc(999 t=%lu) : %s \r\n",time((long*) 0),buffer);
			break;

#ifdef	UNIX
		case  _VISUAL_GETCLIP :
			status = visual_get_clipboard( buffer, buflen );
			return( status );

		case  _VISUAL_SETCLIP :
			status = visual_put_clipboard( buffer, buflen );
			return( status );
#endif
#ifdef WIN32
		case  _VISUAL_GETCLIP :
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_GETCLIP"));
			MI_TRACE((CI_TRA_F_DUMP,CI_MODULE_ID,TFN,"buffer:",buffer,buflen));
			/* FCH22042005 
			Gestion dynamique du charset. On fait la conversion par rapport
			à la police de base courante
			*/
			status = ClipboardGet_byexa(buffer,buflen,x_event(EVT_CHARSET));
			MI_TRACE_RETURN( status );

		case  _VISUAL_SETCLIP :
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_SETCLIP"));
			MI_TRACE((CI_TRA_F_DUMP,CI_MODULE_ID,TFN,"buffer:",buffer,buflen));
			/* FCH22042005 
			Gestion dynamique du charset. On fait la conversion par rapport
			à la police de base courante
			*/
			status = ClipboardSet_byexa(buffer,buflen,x_event(EVT_CHARSET));
			MI_TRACE_RETURN( status );

		case  _VISUAL_GETCLIP_NOCONV :
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_GETCLIP_NOCONV"));
			MI_TRACE((CI_TRA_F_DUMP,CI_MODULE_ID,TFN,"buffer:",buffer,buflen));
			status = ClipboardGetNoConv_byexa(buffer,buflen);
			MI_TRACE_RETURN( status );

		case  _VISUAL_SETCLIP_NOCONV :
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_SETCLIP_NOCONV"));
			MI_TRACE((CI_TRA_F_DUMP,CI_MODULE_ID,TFN,"buffer:",buffer,buflen));
			status = ClipboardSetNoConv_byexa(buffer,buflen);
			MI_TRACE_RETURN( status );

		/*
		------------------------------------------------------------------------------------------
		- _VISUAL_PRN_BUFFER
		- Impression du buffer courant (sélectionné par un VisualPage)
		- 
		- %  nolog (IN) : no logique imprimante
		- %  Mode  (IN) : 0 = Impression
		-                 1 = Prévisualisation à l'écran
		- %  zoom  (IN) : (si mode 1) zoom d'affichage en pourcentage
		- 
		- retour       : 0 si OK
		------------------------------------------------------------------------------------------
		*/
		case  _VISUAL_PRN_BUFFER :
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_PRN_BUFFER"));
			{
			struct	visualbuffer * vptr;
			STDPSUPTR	pptr;
			WORD NoLog;
			WORD Mode;
			WORD Zoom;

			if( buflen >= 2 )
				{
				NoLog = AbalGetWord( (buffer) );
				Mode  = (buflen >=4) ? AbalGetWord(buffer+2) : 0;			
				Zoom  = (buflen >=6) ? AbalGetWord(buffer+4) : 0;			
				}
			else	
				MI_TRACE_RETURN( 62 );

			/* Failure on invalid buffer control */
			/* --------------------------------- */
			/* On ne peut être appelé que si un VisualPage a eu lieu avant */

			if ( ActiveVisualBuffer == -1 )
				MI_TRACE_RETURN( 56 );
			else if (!( vptr = VisualBufferHeap[ ActiveVisualBuffer ] ))
				MI_TRACE_RETURN( 0 );
			else if (!( pptr = vptr->buffer ))
				MI_TRACE_RETURN(0);	

			status = printhq_buffer( NoLog, pptr, Mode, Zoom);
			
			/* Restitue le background positionné par VisualPage */
			/* mais potentiellement cassé par printhq_buffer      */
			background_pixel_capture(pptr); 
			}
			MI_TRACE_RETURN( status );

		case	_VISUAL_PLAYSOUND	:
			MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"_VISUAL_PLAYSOUND"));
			buffer = terminate_string(buffer,buflen);
			retcode = VisualPlaySound(buffer);
			MI_TRACE_RETURN( retcode );
#endif
		case	666			: 
			/* test call back */
			buffer = terminate_string(buffer,buflen);
			return( application_callback( buffer ) );

		default				:
			MI_TRACE_RETURN(56);
		}
	MI_TRACE_RETURN(0);
}

/*	----------------------		*/
/*	Library identification		*/
/*	----------------------		*/
private	VOID FAR banniere()
{ 
#ifdef WIN32
	char buftmp[80];

	printf("\n   AbalVisual Library : VISUAL ");
	printf("\n   Version %s ",Banner_GetVersionID(buftmp,Banner_GetVersionStatus()) );

	printf("\n %s\n",Banner_GetInternalName(buftmp));
#else
	printf("\n   AbalVisual Library : VISUAL ");
	printf("\n   Version %s ",getpatternversion());

	if ( VersionStatus[15] == '2' )
		printf("\n   Provisoire du    %s",__VISUAL_DATE);

	printf("\n   Copyright (c) 2002,2007 Amenesik / Sologic \n");
#endif
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
	printf("\n\t %u  %% VisualActivate(width%%,height%%,style%%)\n",_VISUAL_DLL_ACTIVATE);
	return;
	
}

#ifdef UNIX

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

int	(*x_graph_relay)(int, struct x_graph_descriptor*);

private	void *	redirect_access_controller( int	item,  void *	fptr )
{
	void	*	vptr=(void *) 0;
	if ((item >= 0) && ( item < CicoAccessController.FunctionCount )) {
		if ( fptr ) {
			vptr = CicoAccessController.FunctionRelay[item]; 	
			if ( item == CICO_GRAPH )
				x_graph_relay = vptr;
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
		{
			XgraphPtr = &cptr->FunctionRelay[i];
			XgraphRelay = *XgraphPtr;
		}
		vptr = iptr->cico.fonction[i];
		if ( i != CICO_INIT )
			CicoAccessController.FunctionRelay[i] = vptr;
		}
	return;
}

#include "voverload.c"
#define	x_putch(i) (CicoAccessController.FunctionRelay[CICO_CO])(i)
#ifdef	_voverload_c
#include "vsvg.c"
#endif

public	int	x_conf(int i)
{
	return( (CicoAccessController.FunctionRelay[CICO_CONF])(i) );
}

public	int	x_callback( int i, struct exa_callback * v )
{
	return( (CicoAccessController.FunctionRelay[CICO_CALLBACK])(i,v) );
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

public	int	xgr_prfo(int i, char * c, int l )
{
	return( (CicoAccessController.FunctionRelay[CICO_PRFO])(i,c,l) );
}

public	int	xgr_lcfo(int i, char * c, int l )
{
	return( (CicoAccessController.FunctionRelay[CICO_LCFO])(i,c,l) );
}

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

/* _VISUAL_STYLE_MANAGER */
/* --------------------- */
#ifndef	WIN32
#ifdef	_VISUAL_STYLE_MANAGER
#include "vatb.c"
#endif
#endif

#endif

static	EXAWORD	activate_visual_buffer()
{
	struct	visualbuffer * vptr;
	if (!(vptr = VisualBufferHeap[ActiveVisualBuffer])) {
		ActiveVisualBuffer = -1;
		return(0);
		}
	else	{
		background_pixel_capture(vptr->buffer);
		VisualViewPort(vptr->x,vptr->y,vptr->width,vptr->height,vptr->font);
		if ( vptr->font != 0 ) {
			x_pos(vptr->column,vptr->row);
			x_paint(vptr->foreground,vptr->background);
			}
		return(1);		
		}
}


/* 	------------------	*/
/* 	DLL initialisation	*/
/* 	------------------	*/
VOID FAR PTR InitRelais()
{ 
	char *	eptr;
	MI_TRACE_DCL_TFN("InitRelais");
	MI_TRACE_BEGIN();

#if defined(WIN32)
	eptr = confgetenv("VISUALFREEZE");
#else
	eptr = getenv("VISUALFREEZE");
#endif

	if (eptr) {
		VisualFreezeControl = atoi(eptr);
		}
	
#ifdef	UNIX
	if ((eptr = getenv("STYLETRACE"))) {
		StyleErrorTrace=atoi(eptr);
		}
	if ((eptr = getenv("VISUALECHO"))) {
		VisualEcho = atoi(eptr);
		}
	if (rt_init != (VOID FAR PTR) 0L)
		rt_init->ordinaire.signature = BDA_REDIRECT;
#else
	if (rt_init != (VOID FAR PTR) 0L)
		rt_init->ordinaire.signature = BDA_CICO;
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

#ifdef WIN32

	desrt.fonction[_VISUAL_DLL_ZONE]	= (void*) AbalVisualZone;
	desrt.fonction[_VISUAL_DLL_LINE]	= (void*) AbalVisualLine;
	desrt.fonction[_VISUAL_DLL_FONT]	= (void*) AbalVisualFont;
	desrt.fonction[_VISUAL_DLL_TEXT]	= (void*) AbalVisualText;
	desrt.fonction[_VISUAL_DLL_EDIT]	= (void*) AbalVisualEdit;
	desrt.fonction[_VISUAL_DLL_WINDOW]	= (void*) AbalVisualWindow;
	desrt.fonction[_VISUAL_DLL_BUTTON]	= (void*) AbalVisualButton;
	desrt.fonction[_VISUAL_DLL_CHECK]	= (void*) AbalVisualCheck;
	desrt.fonction[_VISUAL_DLL_RADIO]	= (void*) AbalVisualRadio;
	desrt.fonction[_VISUAL_DLL_IMAGE]	= (void*) AbalVisualImage;
	desrt.fonction[_VISUAL_DLL_TABPAGE]	= (void*) AbalVisualTabPage;
	desrt.fonction[_VISUAL_DLL_SELECT]	= (void*) AbalVisualSelect;
	desrt.fonction[_VISUAL_DLL_SCROLL]	= (void*) AbalVisualScroll;
	desrt.fonction[_VISUAL_DLL_PALETTE]	= (void*) AbalVisualPalette;
	desrt.fonction[_VISUAL_DLL_INITIALISE]  = (void*) AbalVisualInitialise;
	desrt.fonction[_VISUAL_DLL_LIBERATE]  	= (void*) AbalVisualLiberate;
	desrt.fonction[_VISUAL_DLL_FREEZE]      = (void*) AbalVisualFreeze;
	desrt.fonction[_VISUAL_DLL_THAW]        = (void*) AbalVisualThaw;
	desrt.fonction[_VISUAL_DLL_EVENT]      	= (void*) AbalVisualEvent;
	desrt.fonction[_VISUAL_DLL_FILL]      	= (void*) AbalVisualFill;
	desrt.fonction[_VISUAL_DLL_KEY ]      	= (void*) AbalVisualKey;
	desrt.fonction[_VISUAL_DLL_CONTROL ]   	= (void*) AbalVisualControl;
	desrt.fonction[_VISUAL_DLL_PROGRESS ]   = (void*) AbalVisualProgress;
	desrt.fonction[_VISUAL_DLL_TABLE ]	= (void*) AbalVisualTable;
	desrt.fonction[_VISUAL_DLL_COLOUR]	= (void*) AbalVisualColour;  
	desrt.fonction[_VISUAL_DLL_BUFFER]	= (void*) AbalVisualBuffer;
	desrt.fonction[_VISUAL_DLL_PAGE  ]	= (void*) AbalVisualPage; 
	desrt.fonction[_VISUAL_DLL_GET   ]	= (void*) AbalVisualGet;  
	desrt.fonction[_VISUAL_DLL_GETROW]	= (void*) AbalVisualGetRow;
	desrt.fonction[_VISUAL_DLL_PUTROW]	= (void*) AbalVisualPutRow;
	desrt.fonction[_VISUAL_DLL_PUT   ]	= (void*) AbalVisualPut;
	desrt.fonction[_VISUAL_DLL_DROP  ]	= (void*) AbalVisualDrop;
	desrt.fonction[_VISUAL_DLL_TRANSFORM]	= (void*) AbalVisualTransform;
	desrt.fonction[_VISUAL_DLL_PUTZONE]	= (void*) AbalVisualPutZone;
	desrt.fonction[_VISUAL_DLL_SWITCH]	= (void*) AbalVisualSwitch;
	desrt.fonction[_VISUAL_DLL_GRAPH]	= (void*) AbalVisualGraph;
	desrt.fonction[_VISUAL_DLL_ACTIVATE]    = (void*) AbalVisualActivate;
	desrt.fonction[_VISUAL_DLL_VIEWPORT]    = (void*) AbalVisualViewPort;
#ifdef	_VISUAL_STYLE_MANAGER
	desrt.fonction[_VISUAL_DLL_STYLE]    = (void*) AbalVisualStyle;
#endif

#else

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
	desrt.fonction[_VISUAL_DLL_FUNCTION+17]	= (WORD (FAR PTR)()) 0;

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
		rt_init->cico.fonction[CICO_CALLBACK] = desrt.fonction[_VISUAL_DLL_FUNCTION+17];
		}
#endif

#endif /* vms */

	MI_TRACE_RETURN((VOID FAR PTR) &desrt);
}

	/* ----------- */
#endif	/* _VISUAL_C */
	/* ----------- */


