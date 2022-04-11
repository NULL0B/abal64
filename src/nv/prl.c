//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------

//	------------------------------------------------------------------
//	Activate either or both of the following in order to inhibit the
//	corresponding function library and use dummy stub code instead
//	------------------------------------------------------------------
// define		_INHIBIT_HTTP_STUB
// define	 	_INHIBIT_PIXEL_STUB
//	------------------------------------------------------------------

#ifndef	__prologue_system_c
#define	__prologue_system_c

#undef	DOS
#define PROLOGUE

#define	O_BINARY	0x8000


//	------------------------------------------------
//	Prototypes for external P3LLIBC memory functions
//	------------------------------------------------
unsigned short int err_val=0;

#include "gui.c"
#include "catcher.h"

extern	void	prologue();

extern	void * malloc( unsigned int nb );
extern	void   free( void * vptr );

int	TheBinMen();
void	TheStatMan(int n);

extern	int	get_mouse_error( void );
extern	void	init_mimo( void );
extern	void	fin_mimo( void );
extern	int	mimo_getch( void );
extern	int	mimo_kbhit( void );
extern  int	get_mimo_mask( void );
extern  int	get_mimo_status( void );
extern  void	set_mimo_mask( int );
#include "mimo.h"

void	abqt()
{
	_asm	{
		push	ax
		mov	ah,035H
		call	prologue
		pop	ax
		};
	return;
}
	
static	char waitbuffer[16];
	
void	llwait( char * descriptor )
{
_asm	{
	push	ds			;** DS ==> Pile
	push	bx
	push	ax
	lds	bx,descriptor
	mov	ah,42h	
	call	prologue
	lds	bx,descriptor
	mov	ah,31h	
	call	prologue
	pop	ax
	pop	bx
	pop	ds			
	};
	return;
}

void	wait( int dixsec )
{
	waitbuffer[0] = 0x80;
	waitbuffer[1] = (dixsec & 0x00FF);
	waitbuffer[2] = ((dixsec >> 8) & 0x00FF);
	waitbuffer[3] = waitbuffer[4] = 
	waitbuffer[5] = waitbuffer[6] = waitbuffer[7] = 0;
	llwait( waitbuffer );
	return;
}

#include "encode64.c"
#include "sysfont.c"

void	BugCatcher()
{
	return;
}


int	is_mouse_active() 
{
	int	status;
	status = get_mimo_status();
//	printf("ImA(%u)",status);
	return(status);
}

int	hostpathsep()	{ return( '\\' ); }

void	make_mouse_move() 
{ 
	int	mask;	
	set_mimo_mask((mask = (get_mimo_mask() | _MIMO_WHILE_DOWN /* not anymore | _MIMO_MOVE */ )));
//	printf("MmM(%x)",mask);
	return;
}

#define	_MACROVALPRL
#include "macroval.h"

int	macro_getch( int c )
{
	return( macrovalue[(c & 0x00FF)] );
}

int	is_macro( int c )
{
	int	i;
	c &= 0x00FF;
	if ( c <= 127 )
		return(c);
	else	{
		for ( i=128; i < 256; i++ )
			if (( macrovalue[i] & 0x00FF) == c )
				return(i);
		return(c);
		}
}

#include "prllo.c"


static	char * NewMouse0="\1=NEWMOUSE0";
static	char * NewMouseN="\1=NEWMOUSEN";

void	UseOldMouse()
{
	if  (!( console_number() ))
		*NewMouse0=0;
	else	*NewMouseN=0;
	return;
}

int	UseNewMouse()
{
	if  (!( console_number() ))
		return( *NewMouse0 );
	else	return( *NewMouseN );
}

void	cico_open()
{ 	
	if ( UseNewMouse() )
		use_new_mimo();
	else	use_old_mimo();
	init_mimo();
	(void) consoletype();
	activate_mimo();
	return; 
}

void	cico_close()
{
	inhibit_mimo();
	fin_mimo();
	return;   
}

int	cico_use_colour()
{
	return( console_colour() );
}

int	cico_max_lines()
{ 
	return(21);
}

void	cico_puts( char * sptr )
{ 
	int	i;
	if ( gigo != -1 )
		PixelPuts( sptr );
	else	{
		for ( ; *sptr; sptr++ ) {
			i = *sptr;
			_asm	{
				push	cx
				mov  	ah,011h
				mov	cx,i
				call	prologue
				pop	cx
				}
			}
		}
	return; 
}


void	cico_putch( int i ) 
{ 
	if ( gigo != -1 )
		PixelPutc( i );
	else	{
	if ( i == 3 ) i = 'C';
	else if ( i == 0x0012 ) i = 'R';
_asm	{
	push	cx
	mov  	ah,011h
	mov	cx,i
	call	prologue
	pop	cx
	}
		}
	return; 
}

int 	cico_event( int i)
{ 
	switch (i) {
		case	1 : 
			if ( UseNewMouse() )
				return( get_mimo_row() );
			else	return( get_mimo_lin() );

		case	2 : 
			if ( UseNewMouse() )
				return( get_mimo_column() );
			else	return( get_mimo_col() );
		case	3 : return( get_mimo_type() );
		case	4 : return( get_mimo_par() );
		default	  : return(0);         	
		}

}

static	int ungotch=0;

void	cico_ungetch( int c )
{
	ungotch = c;
	return;
}

int 	cico_getch()
{ 
	int	c;
	if ((c = ungotch) != 0)
		ungotch = 0;
	else	c = mimo_getch();
	return( c );

//_asm	{
//	mov  	ah,010h
//	call	prologue
//	xor	ah, ah
//	mov	c,ax
//	}
//	return(c); 
}

int	cico_kbhit()
{ 
	if ( ungotch )
		return(1);
	else	return(mimo_kbhit());	
}

#ifdef	_NV11D
int	last_foreground=4;
int	last_background=7;
#endif

void	cico_foreground( int c ) 
{
#ifdef	_NV11D
	last_foreground = c;
#endif
	if ( console_colour() ) {
		cico_putch(0x001B);
		cico_putch('r');
_asm	{
	mov	ax, c
	and	ax,000FH		; Mask to Legal Value
	or	al, 030h		; Mix in 30h
	cmp	al, 03Ah		; Test for supliment
	jb	fore_1			; BELOW => no supliment
	add	al, 7			; add in supliment
fore_1:	mov	c,ax
	}
		cico_putch(c);
		}
	return; 
}

void	cico_background( int c ) 
{
#ifdef	_NV11D
	last_background = c;
#endif
	if ( console_colour() ) {
		cico_putch(0x001B);
		cico_putch('s');
_asm	{
	mov	ax, c
	and	ax,000FH		; Mask to Legal Value
	or	al, 030h		; Mix in 30h
	cmp	al, 03Ah		; Test for supliment
	jb	fore_1			; BELOW => no supliment
	add	al, 7			; add in supliment
fore_1:	mov	c,ax
	}
		cico_putch(c);
		}
	return; 
}

void	cico_clear()
{
	cico_putch(0x000C);
	return;
}

void	cico_curser( int l, int c)
{ 
	cico_putch(0x001B);
	cico_putch('f');
_asm	{
	mov	ax,l
	xor	ah,ah
	add	ax,01FH
	mov	l,ax
	mov	ax,c
	xor	ah,ah
	add	ax,01FH
	mov	c,ax
	}
	cico_putch(c);
	cico_putch(l);
	return; 
}

//	---------------------------------------------------
//	C++ Allocation Functions Called from NEW and DELETE
//	---------------------------------------------------

int	trace_control=0;

FILE * trace_handle=(FILE *) 0;
long	trace_alloc;
long	trace_liber;

void	start_alloc_trace(char * mptr)
{
	if ((!( mptr ))
	||  (!( *mptr )))
		trace_control=1;

	else if ((!( trace_control)) 
	     &&  (!( trace_handle )))
		if ((trace_handle = fopen( mptr , "w" )) != (FILE *) 0)
			trace_control=1;
	return;
}
		
void	flush_alloc_trace()
{
	if ( trace_control ) {
		if ( trace_handle ) {
			fprintf(trace_handle,"end\n\n%c",0x001A);
			fclose( trace_handle );
			trace_handle = (FILE *) 0;
			}
		else if ( trace_alloc != trace_liber )
			printf("\nA=%lu,L=%lu,D=%lu\n",trace_alloc,trace_liber,trace_alloc - trace_liber);
		trace_control = 0;
		}
	return;
}

void __far* __far __cdecl _fmalloc( unsigned int n )
{
	int	i;
	int	rcs,rip;
	char * rptr;

	while ((rptr = malloc( n )) == (char *) 0)
		if ( ! ( TheBinMen() ) )
			throw_exception( 27 );

	if ( trace_control ) {
		trace_alloc++;
		if ( trace_handle ) {
			_asm	{
				push	ax
				push	bx
				mov	bx,word ptr [bp]
				mov	ax,word ptr ss:[bx][+2]
				mov	rip,ax
				mov	ax,word ptr ss:[bx][+4]
				mov	rcs,ax
				pop	bx
				pop	ax
				};

			fprintf( trace_handle, "%lu: %lx=a(%u) from %x:%x \n",trace_alloc,rptr,n,rcs,rip);
			}
		}

	(void) memset( rptr, 0, n );
//	for (i=0; i < n; i++ )
//		*(rptr +i) = 0;
	TheStatMan(1);
	return( rptr );
}

void	__far __cdecl _ffree( void __far* vptr )
{
	int	rcs,rip;
	if ( vptr ) {
		if ( trace_control ) {
			trace_liber++;
			if ( trace_handle ) {
				_asm	{
					push	ax
					mov	ax,word ptr [bp][+2]
					mov	rip,ax
					mov	ax,word ptr [bp][+4]
					mov	rcs,ax
					pop	ax
					};

				fprintf( trace_handle, "%lu: l(%lx) from %x:%x \n",trace_liber,vptr,rcs,rip);
				}
			}
		free( vptr );
		TheStatMan(0);
		}
	return;
}

#include "stdmem.c"

static	char	rawbuffer[4096];
static	int	rawoffset=0;
static	int	rawlength=0;

int	rawopen( char * nptr )
{
	rawoffset=0; rawlength=0;
	return( open( nptr, O_BINARY ) );
}

void	rawclose( int handle )
{
	close( handle );
	return;
}

static	int	rawbyte( int handle )
{
	if ( rawoffset >= rawlength ) {
		if ((rawlength = read(handle,rawbuffer,4096)) != 0)
			rawoffset = 0;
		else	return(-1);
		}
	return(( rawbuffer[rawoffset++] & 0x00FF));
}

int	rawread( int handle, char * buffer, int length )
{
	int	transfered=0;
	int	c;
	for ( transfered=0; transfered < length; transfered++ ) {
		if ((c = rawbyte(handle)) != -1)
			*(buffer++) = c;
		else	break;
		}
	return( transfered );
}

//	----------------------------------------------------------------
//		S Y S T E M _ U S E B A S E ( RPTR, NPTR, BPTR )
//	----------------------------------------------------------------
//	This function will perform Absolute/Relative Path checking
//	on the new name NPTR and the old name BPTR and return
//	the result in the ALREADY allocated zone (long enough for
//	the storage of both strings and a zero) RPTR.
//	----------------------------------------------------------------

void	system_usebase( char * rptr, char * nptr, char * bptr )
{
	int	nlen=0;
	int	blen=0;
	int	rlen=0;
	int	pathsep;
	int	i;

	// Calculate Length of New String
	// ------------------------------
	if ( nptr )
		while ( *(nptr + nlen) ) nlen++;
	else	return;

	rlen += nlen;

	// -----------------------------------------
	// First Check if NPTR is Absolute : DEVICED
	// -----------------------------------------
	if (( nlen > 3 ) 
	&&  ( *(nptr + 2) >= '0' )
	&&  ( *(nptr + 2) <= '9' )
	&&  ( ( *(nptr + 3) == '/'   )
	   || ( *(nptr + 3) == '.'   )
	   || ( *(nptr + 3) == 0x05C )))
		for (rlen=0; rlen < nlen; rlen++ ) *(rptr + rlen) = *(nptr + rlen);

	// --------------------------------------------
	// Otherwise Check if NPTR is Absolute : PATHED
	// --------------------------------------------
	else if (( *nptr == '/'   )
	     ||  ( *nptr == 0x05C ))
		for (rlen=0; rlen < nlen; rlen++ ) *(rptr + rlen) = *(nptr + rlen);

	// ---------------------------------------
	// Check if a Valid Base has been provided
	// ---------------------------------------
	else if (!( bptr ))
		for (rlen=0; rlen < nlen; rlen++ ) *(rptr + rlen) = *(nptr + rlen);

	// ------------------------------------------------------------
	// So Now locate relevant portion of the Base for concatenation
	// ------------------------------------------------------------
	else	{
		while ( *(bptr + blen) ) blen++;
		switch ((pathsep = *bptr)) {
			case	'/'	:
			case	0x005C	:
				break;
			default		:
				pathsep = 0;
				
				if (( blen > 3 )
				&&  ( *(bptr + 2) >= '0' )
				&&  ( *(bptr + 2) <= '9' )) {

					// Has a Device Is a Path Sep There
					// --------------------------------
					switch ((pathsep = *(bptr + 3))) {
						case	'.'	:
							// Check for MDx.\file
							if (( *(bptr + 4) == '/' )
							||  ( *(bptr + 4) == 0x005C ))
								pathsep = *(bptr + 4);
							// Otherwise MDx.file

						case	'/'	:
						case	0x005C	:
							break;
						default		:
							pathsep = 0;
						}
					}

				if (!( pathsep ))
					for ( i=(blen-1); i != 0; i-- )
						if (( *(bptr + i) == '/' )
						||  ( *(bptr + i) == 0x005C ))
							pathsep = *(bptr + i);
			}

		// ----------------------------------
		// If a path separator has been found
		// ----------------------------------
		if ( pathsep ) {
			// -------------------------------------
			// Special Case for MDx.FILE type syntax
			// -------------------------------------
			if ( pathsep == '.' )
				blen = 4;

			// ---------------------------------------
			// Scan backwards from the end of the Base
			// trying to find the last path separator
			// ---------------------------------------
			else	for ( blen--; blen != 0; blen-- )
					if ( *(bptr + blen) == pathsep ) {
						blen++;
						break;
						}

			// ---------------------------------------
			// Transfer the Base Portion to the Result
			// ---------------------------------------
			for (rlen=0; rlen < blen; rlen++ )
				*(rptr + rlen) = *(bptr + rlen);

			// ------------------------------------
			// Transfer the New Name to the Result
			// ------------------------------------
			for (blen = 0; blen < nlen; blen++, rlen++ )
				*(rptr + rlen) = *(nptr + blen);
			}

		// -----------------------------------------------------------
		// Otherwise no way of determining what to take so just 
		// return the new name string and keep our fingers crossed
		// -----------------------------------------------------------
		else	for (rlen=0; rlen < nlen; rlen++ ) *(rptr + rlen) = *(nptr + rlen);

		}

	// --------------------------------------------------------
	// Finally Convert Result to Correct System Type Separators
	// --------------------------------------------------------
	*(rptr+rlen) = 0;
	for ( ; *rptr; rptr++ )
		if ( *rptr == '/' )
			*rptr = 0x005C;

	return;
}

//	---------------------------	--------------------------------
//	HTTP LIBRARY STUB FUNCTIONS	( Will be replaced by HTTPFUNC )
//	---------------------------	--------------------------------
#ifdef	_INHIBIT_HTTP_STUB
#include "stubhttp.c"
#endif	// _INHIBIT_HTTP_STUB

//	----------------------------	---------------------------------
//	PIXEL LIBRARY STUB FUNCTIONS	( Will be replaced by PIXELGUI.C)
//	----------------------------	---------------------------------
#ifdef	_INHIBIT_PIXEL_STUB
#include "stubgui.c"
#endif	// _INHIBIT_PIXEL_STUB

int	HideNest=0;
void	guihide(char * mptr)
{
	int	h=HideNest;
	HideNest++;
/*	printf("Hide(%s,%u->%u)\n",mptr,h,HideNest);	*/
	if (!( h ))
		hide();
	return;
}

int 	guishow(char * mptr, int a,int b,int c,int d)
{
	int	h;
	if ((h = HideNest) > 0 )
		HideNest--;
/*	printf("Show(%s,%u->%u)(%u,%u,%u,%u)\n",mptr,h,HideNest,a,b,c,d);	*/
	if ((h) && (!(HideNest)))
		show(a,b,c,d);
	return(HideNest);
}


#endif	// _prologue_system_c


