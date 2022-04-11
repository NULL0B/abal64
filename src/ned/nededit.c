#ifndef	_nededit_c
#define	_nededit_c

#define	_EDITOR_INITIALISE 1
#define	_EDITOR_CONFIGURE  2

/*	-----------------------------------------------		*/
/*	Abal Editor,  Aed,  BDA Dynamic Library Package		*/
/*	-----------------------------------------------		*/

#include <stdio.h>
#include <setjmp.h>
#include <malloc.h>
#include "bda.h"
BDA	desrt;
void _cfltcvt() { return; }
void _cropzeros() { return; }

#include <signal.h>

#include "xgraph.h"
#include "edmouse.c"
#include "edstub.c"
#include "nedcico.c"

/*	---------------------------------------		*/
/*	Global Editor Library Control Variables		*/
/*	---------------------------------------		*/
static	int	DllEditorFontId=1;
static	int	DllEditorActive=0;
static	char *	DllCommandString=(char *) 0;
static	int	DllCommandLength= 0;

/*	---------------------------------------		*/
/*	Exteral Editor Kernal Control Variables		*/
/*	---------------------------------------		*/
extern	unsigned long	maxnumlgn;
extern	unsigned char 	boolcor;
extern	unsigned char 	flg_insert;
extern	unsigned char 	flg_indent;

/*	--------------------------------------		*/
/*	Abal Long Data Type Handling Functions 		*/
/*	--------------------------------------		*/
static void	AbalPutLong(BYTE FAR PTR wptr, long v)
{
	*(wptr+3) = (v & 0x00FF);
	*(wptr+2) = ((v & 0x00FF00)   >> 8);
	*(wptr+1) = ((v & 0x00FF0000) >> 16);
	*(wptr+0) = ((v & 0xFF000000) >> 24);
	return;
}

static unsigned long AbalGetLong(BYTE FAR PTR wptr)
{
	return((((*wptr)<< 24) | (*(wptr+1) << 16)  | (*(wptr+2) << 8)| *(wptr+3)));
}

/*	---------------------------------------		*/
/*	Editor Kernal Relays  and  Dummy Values 	*/
/*	---------------------------------------		*/
int	control_fork()			{	return(fork());	}
void	system_failure( char * mptr)	{	return;		}
int	test_initialise_hardware()	{	return(0);	}
int	open_console()			{	return(0);	}
int	close_console()			{	return(0);	}
int	select_cico_ecran()		{	return(0);	}
int	panic()				{	return(0);	}
int	consoletype()			{	return(2);	}
int	finterm()			{	return(0);	}
int	initerm()			{	return(0);	}
int	set_desktop_name(char * nptr)	{	return(0);	}
int	set_desktop_icon(char * nptr)	{	return(0);	}
static 	void	banniere()		{	return;		}

/*	---------------------------------------		*/
/*	CICO / GIGO Colour Relay  :  FG, BG, WG   	*/
/*	---------------------------------------		*/
int	cicocolours( int f, int b, int w )
{
	cicocolour(f,b);
	washgr(31);
	return(0);
}

/*	---------------------------------------		*/
/*	 Graphical Editor Window Configuration     	*/
/*	---------------------------------------		*/
static	void	Dll_EditorConfigure(int x, int y, int w, int h)
{
	int	fontwidth;
	int	fontheight;
	char	workbuffer[256];
	use_base_font(DllEditorFontId);
	fontwidth  = guifontsize(DllEditorFontId);
	fontheight = (fontwidth >> 8);
	fontwidth  &= 0x00FF;
	cicowindow(x,y,w-(fontwidth*2),h);
	sprintf(workbuffer,"%u:%u:%u:%u:0:%u:0:0:0",x,y,w,h,DllEditorFontId);
	editor_window_connection( workbuffer );	
	return;
}

/*	------------------------------------	*/
/*		editorOnCommand()		*/
/*	------------------------------------	*/
/*	This function will be called back 	*/
/*	from the internal editor Command	*/
/*	Window function in order to get the	*/
/*	command line string. The Escape Key	*/
/*	will signal no value returned.		*/
/*	------------------------------------	*/
int	editorOnCommand(char * nptr, int l )
{
	int	x;
	char *	sptr;
	int	slen;
	if (!(sptr = DllCommandString ))
		return( 27 );
	else if (!( slen = DllCommandLength ))
		return( 27 );
	else	{
		/* Reset these now to avoid recursion */
		/* ---------------------------------- */
		DllCommandString = (char *) 0;
		DllCommandLength = 0;
		/* Transfer Value to Buffer */
		/* ------------------------ */
		for (x=0; x < l; x++ ) {
			if ( x < slen ) {
				*(nptr+x) = *(sptr+x);
				}
			else	{
				*(nptr+x) = 0;
				return( 13 );
				}
			}
		/* Value Incorrect : String Too Long */
		/* --------------------------------- */
		return(27);
		}
}

/*	-------------------------------------------------------------------	*/
/*										*/
/*	E D I T O R   L I B R A R Y   I N T E R F A C E   F U N C T I O N S	*/
/*										*/
/*	-------------------------------------------------------------------	*/

/*	-----------------------		*/
/* 	% EditorInitialise($,%) 	*/
/*	-----------------------		*/
static int Dll_EditorInitialise(char * a1,int a2)
{
	int 	x;
	int	c;
	if ( DllEditorActive & _EDITOR_INITIALISE )
		return(30);

	DllCommandString = (char *) 0;
	DllCommandLength = 0;
	switch ( x_conf(66) ) {
		case	1	:
			editorOnGraphic();
			break;
		case	0	:
			editorOnText();
			break;
		}
	for ( x=0; x < a2; x++ ) {
		switch ((c = *(a1++))) {
			case	' '	:
				continue;
			default		:
				return(31);
			}
		}
	DllEditorActive |= _EDITOR_INITIALISE;
	return(0);
}

/* ------------------------------- */
/* 	% EditorCommand($,%) 	   */
/* ------------------------------- */
/* returns 27 to indicate closure  */
/* ------------------------------- */
static int Dll_EditorCommand(char * a1,int a2)
{
	int	status;

	if (!( 	DllEditorActive & _EDITOR_CONFIGURE ))
		return(30);

	DllCommandString = a1;
	DllCommandLength = a2;
	status = editorCommandWindow();
	DllCommandString = (char *) 0;
	DllCommandLength = 0;
	return((status ? 27 : 0));
}

/*	----------------------		*/
/* 	% EditorGetStatus($,%) 		*/
/*	----------------------		*/
static int Dll_EditorGetStatus(char * bptr, int blen )
{
	char	*	nptr=(char *) 0;
	unsigned long	lptr=0L;
	unsigned long	tptr=0L;
	unsigned long	eptr=0L;
	int		items=0;
	int		flags=0;
	if (!( 	DllEditorActive & _EDITOR_CONFIGURE ))
		return(30);

	if ( flg_insert )
		flags |= 1;
	if ( boolcor )
		flags |= 2;
	if ( flg_indent )
		flags |= 4;
	editorGetPosition( &nptr, &lptr, &tptr, &eptr );
	eptr = maxnumlgn;
	if ( blen >= 4 ) {
		AbalPutLong( bptr, lptr );
		bptr += 4;
		items++;
		if ( blen >= 8 ) {
			AbalPutLong( bptr, tptr );
			items++;
			bptr += 4;
			if ( blen >= 8 ) {
				AbalPutLong( bptr, eptr );
				bptr += 4;
				items++;
				if ( blen >= 12 ) {
					AbalPutLong( bptr, flags );
					bptr += 4;
					items++;
					}
				}
			}
		}
	return(0);
}

/*	----------------------		*/
/* 	% EditorSetStatus($,%) 		*/
/*	----------------------		*/
static int Dll_EditorSetStatus(char * bptr, int blen )
{
	unsigned long	lptr=0L;
	unsigned long	tptr=0L;
	unsigned long	eptr=0L;
	unsigned long	fptr=0L;
	if (!( 	DllEditorActive & _EDITOR_CONFIGURE ))
		return(30);
	else if ((!( bptr )) || ( blen < 16 )) {
		return(31);
		}
	else	{
		lptr = AbalGetLong(bptr); bptr += sizeof( unsigned long );
		tptr = AbalGetLong(bptr); bptr += sizeof( unsigned long );
		tptr = AbalGetLong(bptr); bptr += sizeof( unsigned long );
		fptr = AbalGetLong(bptr); bptr += sizeof( unsigned long );
		editorOnSeek(0,tptr);
		editorOnSeek(0,lptr);
		if ( fptr & 4 )	flg_indent = 1;	else	flg_indent = 0;
		if ( fptr & 2 ) boolcor = 1;	else	boolcor = 0;
		if ( fptr & 1 ) flg_insert = 1; else	flg_insert = 0; 
		return(0);
		}
}

/*	---------------------		*/
/* 	% EditorFileName($,%) 		*/
/*	---------------------		*/
static int Dll_EditorFileName(char * bptr, int blen )
{
	char	*	nptr=(char *) 0;
	long		lptr=0L;
	long		tptr=0L;
	long		eptr=0L;
	int		items=0;
	int		nlen = 0;
	int		x;
	if (!( 	DllEditorActive & _EDITOR_CONFIGURE ))
		return(30);
	for (x=0; x < blen; x++ )
		*(bptr+x) = ' ';
	editorGetPosition( &nptr, &lptr, &tptr, &eptr );
	if (!( nptr )) return(0);
	nlen = strlen( nptr );
	for (x = 0; x < nlen; x++ ) {
		if ( x < blen )
			*(bptr+x) = *(nptr+x);
		else	break;
		}
	return((nlen > blen ? 63 : 0));
}

/*	---------------------		*/
/* 	% EditorSeekLine(%) 		*/
/*	---------------------		*/
static int Dll_EditorSeekLine(int a1 )
{
	if (!( 	DllEditorActive & _EDITOR_CONFIGURE ))
		return(30);
	else	{
		editorOnSeek(0,a1);
		return(0);
		}
}

/*	---------------------		*/
/* 	% EditorSearch($,%,%)		*/
/*	---------------------		*/
static int Dll_EditorSearch(char * a1,int a2,int a3)
{
	char *	sptr;
	if (!( 	DllEditorActive & _EDITOR_CONFIGURE ))
		return(30);
	else if (!( a2 ))
		return(31);
	else if (!( sptr = malloc( a2 + 1 ) ))
		return(27);
	else	{
		memcpy(sptr, a1, a2);
		*(sptr+a2) = 0;
		editorOnSearch( sptr, (a3 & 1 ? 1 : 0) , ( a3 & 2 ? 1 : 0 ));
		free(sptr);
		return(0);
		}
}

/*	--------------------------	*/
/* 	% EditorReplace($,%,$,%,%) 	*/
/*	--------------------------	*/
static int Dll_EditorReplace(char * a1,int a2,char * a3, int a4,int a5)
{
	char *	sptr;
	char *	rptr;
	if (!( 	DllEditorActive & _EDITOR_CONFIGURE ))
		return(30);
	else if ((!( a2 )) || (!( a4 )))
		return(31);
	else if (!( sptr = malloc( a2 + 1 ) ))
		return(27);
	else if (!( rptr = malloc( a4 + 1 ) )) {
		free( rptr );
		return(27);
		}
	else	{
		memcpy(sptr, a1, a2);
		*(sptr+a2) = 0;
		memcpy(rptr, a3, a4);
		*(rptr+a4) = 0;
		editorOnReplace( sptr, rptr, (a5 & 1 ? 1 : 0) , ( a5 & 2 ? 1 : 0 ), (a5 & 4 ? 1 : 0));
		free(sptr);
		free(rptr);
		return(0);
		}
}

/*	-------------------	*/
/* 	% EditorInsert($,%)	*/
/*	-------------------	*/
static int Dll_EditorInsert(char * a1,int a2)
{
	char *	sptr;
	if (!( 	DllEditorActive & _EDITOR_CONFIGURE ))
		return(30);
	else if (!( a2 ))
		return(31);
	else if (!( sptr = malloc( a2 + 1 ) ))
		return(27);
	else	{
		memcpy(sptr, a1, a2);
		*(sptr+a2) = 0;
		editorOnUseString( sptr);
		free(sptr);
		return(0);
		}
}

/*	-------------------	*/
/* 	% EditorFont($,%)	*/
/*	-------------------	*/
static int Dll_EditorFont(char * a1,int a2)
{
	int	fh;
	char *	sptr;
	if (!( 	DllEditorActive & _EDITOR_CONFIGURE ))
		return(30);
	else if (!( a2 ))
		return(31);
	else if (!( sptr = malloc( a2 + 1 ) ))
		return(27);
	else	{
		memcpy(sptr, a1, a2);
		*(sptr+a2) = 0;
		if ((fh = standard_load_font( sptr )) > 0)
			DllEditorFontId = fh;
		else	DllEditorFontId = 1;
		free(sptr);
		return(0);
		}
	return(0);
}

/*	-------------------------------		*/
/* 	% EditorOpen($,%, %,%,%,% ) 	*/
/*	-------------------------------		*/
static int Dll_EditorOpen(char * a1,int a2,int a3,int a4,int a5,int a6)
{
	char	nomfic[512];
	char *	argv[3];
	int	argc=0;

	if (!( 	DllEditorActive & _EDITOR_INITIALISE ))
		return(30);

	if (( a5 != 0 ) && ( a6 != 0)) {
		Dll_EditorConfigure(a3,a4,a5,a6);
		}

	memcpy(nomfic,a1,a2);
	nomfic[a2] = 0;
	argv[argc++] = "aed";
	argv[argc++] = nomfic;
	argv[argc] = (char *) 0;
	if ( editorOnCreate( argc, argv ) == 1 ) {
		DllEditorActive |= _EDITOR_CONFIGURE;
		return(0);
		}
	else	{
		DllEditorActive &= ~_EDITOR_CONFIGURE;
		return(31);
		}
}

/*	---------------		*/
/* 	% EditorShow(%) 	*/
/*	---------------		*/
static int Dll_EditorShow(int a1)
{
	if (!( 	DllEditorActive & _EDITOR_CONFIGURE ))
		return(30);
	else	{
		use_base_font(DllEditorFontId);
		return( editorOnShow() );
		}
}

/*	-------------------	*/
/* 	% EditorGetFocus(%)	*/
/*	-------------------	*/
static int Dll_EditorGetFocus(int a1)
{
	if (!( 	DllEditorActive & _EDITOR_CONFIGURE ))
		return(30);
	else	{
		use_base_font(DllEditorFontId);
		return( editorOnGetFocus() );
		}
}

/*	----------------	*/
/* 	% EditorEvent(%)	 */
/*	----------------	*/
static int Dll_EditorEvent(int a1)
{
	if (!( 	DllEditorActive & _EDITOR_CONFIGURE ))
		return(30);
	else	{
		use_base_font(DllEditorFontId);
		return( editorOnUseEvent( a1 ) );
		}
}

/*	--------------------		*/
/* 	% EditorLoseFocus(%)	 	*/
/*	--------------------		*/
static int Dll_EditorLoseFocus(int a1)
{
	if (!( 	DllEditorActive & _EDITOR_CONFIGURE ))
		return(30);
	else	{
		return( editorOnLoseFocus() );
		}
}

/*	---------------		*/
/* 	% EditorHide(%) 	*/
/*	---------------		*/
static int Dll_EditorHide(int a1)
{
	if (!( 	DllEditorActive & _EDITOR_CONFIGURE ))
		return(30);
	else	{
		use_base_font(DllEditorFontId);
		return( editorOnHide() );
		return(0);
		}
}

/*	---------------		*/
/* 	% EditorClose(%) 	*/
/*	---------------		*/
static int Dll_EditorClose(int a1)
{
	if (!( 	DllEditorActive & _EDITOR_CONFIGURE ))
		return(30);
	else	{
		DllEditorActive &= ~_EDITOR_CONFIGURE;
		editorOnQuit();
		return( editorOnRemove() );
		}
}

/*	---------------		*/
/* 	% EditorLiberate() 	*/
/*	---------------		*/
static int Dll_EditorLiberate()
{
	if (!( 	DllEditorActive & _EDITOR_INITIALISE ))
		return(30);
	else	{
		DllEditorActive &= ~_EDITOR_INITIALISE;
		return(0);
		}
}

/*	---------------		*/
/*	  InitRelais()		*/
/*	---------------		*/
VOID FAR PTR InitRelais()
{
	if (rt_init != (VOID FAR PTR) 0L)
	rt_init->ordinaire.signature = BDA_REDIRECT;
	desrt.banniere = (VOID (FAR PTR)()) banniere;
	desrt.fin = (VOID (FAR PTR)()) 0L;

	/* --------------------------------- */
	/* library interface function relays */
	/* --------------------------------- */
	desrt.fonction[0] = (EXAWORD (FAR PTR)()) Dll_EditorInitialise;
	desrt.fonction[1] = (EXAWORD (FAR PTR)()) Dll_EditorOpen;
	desrt.fonction[2] = (EXAWORD (FAR PTR)()) Dll_EditorShow;
	desrt.fonction[3] = (EXAWORD (FAR PTR)()) Dll_EditorGetFocus;
	desrt.fonction[4] = (EXAWORD (FAR PTR)()) Dll_EditorEvent;
	desrt.fonction[5] = (EXAWORD (FAR PTR)()) Dll_EditorLoseFocus;
	desrt.fonction[6] = (EXAWORD (FAR PTR)()) Dll_EditorHide;
	desrt.fonction[7] = (EXAWORD (FAR PTR)()) Dll_EditorClose;
	desrt.fonction[8] = (EXAWORD (FAR PTR)()) Dll_EditorLiberate;
	desrt.fonction[9] = (EXAWORD (FAR PTR)()) Dll_EditorCommand;
	desrt.fonction[10] = (EXAWORD (FAR PTR)()) Dll_EditorGetStatus;
	desrt.fonction[11] = (EXAWORD (FAR PTR)()) Dll_EditorSetStatus;
	desrt.fonction[12] = (EXAWORD (FAR PTR)()) Dll_EditorFileName;
	desrt.fonction[13] = (EXAWORD (FAR PTR)()) Dll_EditorSeekLine;
	desrt.fonction[14] = (EXAWORD (FAR PTR)()) Dll_EditorSearch;
	desrt.fonction[15] = (EXAWORD (FAR PTR)()) Dll_EditorReplace;
	desrt.fonction[16] = (EXAWORD (FAR PTR)()) Dll_EditorInsert;
	desrt.fonction[17] = (EXAWORD (FAR PTR)()) Dll_EditorFont;
	desrt.fonction[18] = (EXAWORD (FAR PTR)()) Dll_EditorConfigure;
	desrt.nombre = 19;

	/* --------------------------------- */
	/* exa/bda interface function relays */
	/* --------------------------------- */
	desrt.fonction[desrt.nombre+1]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[desrt.nombre+2]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[desrt.nombre+3]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[desrt.nombre+4]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[desrt.nombre+5]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[desrt.nombre+6]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[desrt.nombre+7]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[desrt.nombre+8]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[desrt.nombre+9]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[desrt.nombre+10]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[desrt.nombre+11]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[desrt.nombre+12]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[desrt.nombre+13]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[desrt.nombre+14]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[desrt.nombre+15]	= connect_access_controller;
	desrt.fonction[desrt.nombre+16]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[desrt.nombre+17]	= (EXAWORD (FAR PTR)()) 0;

	/* --------------------------------- */
	/* cico /  interface function relays */
	/* --------------------------------- */
	if (rt_init != (VOID FAR PTR) 0L) {
		rt_init->cico.numero = 16384;		/* graphical redirection */
		rt_init->cico.fonction[CICO_CI]     = desrt.fonction[desrt.nombre+1]; 
	 	rt_init->cico.fonction[CICO_TPCI]   = desrt.fonction[desrt.nombre+2];
	  	rt_init->cico.fonction[CICO_PRFO]   = desrt.fonction[desrt.nombre+3];  	
		rt_init->cico.fonction[CICO_LCFO]   = desrt.fonction[desrt.nombre+4];  	
		rt_init->cico.fonction[CICO_CONF]   = desrt.fonction[desrt.nombre+5]; 	
		rt_init->cico.fonction[CICO_CO]     = desrt.fonction[desrt.nombre+6]; 	
		rt_init->cico.fonction[CICO_MES]    = desrt.fonction[desrt.nombre+7]; 	
		rt_init->cico.fonction[CICO_LIGNE]  = desrt.fonction[desrt.nombre+8]; 	
		rt_init->cico.fonction[CICO_COLONNE]= desrt.fonction[desrt.nombre+9]; 	
		rt_init->cico.fonction[CICO_START]  = desrt.fonction[desrt.nombre+10]; 	
		rt_init->cico.fonction[CICO_FLUSH]  = desrt.fonction[desrt.nombre+11]; 	
		rt_init->cico.fonction[CICO_LO]     = desrt.fonction[desrt.nombre+12]; 	
		rt_init->cico.fonction[CICO_MIMA]   = desrt.fonction[desrt.nombre+13];   
		rt_init->cico.fonction[CICO_EVENT]  = desrt.fonction[desrt.nombre+14];
		rt_init->cico.fonction[CICO_INIT]   = desrt.fonction[desrt.nombre+15];
		rt_init->cico.fonction[CICO_GRAPH]  = desrt.fonction[desrt.nombre+16];
		rt_init->cico.fonction[CICO_CALLBACK] = desrt.fonction[desrt.nombre+17];
		}

	return((VOID FAR PTR) &desrt);
}


#endif	/* _nededit_c */
	/* ---------- */

