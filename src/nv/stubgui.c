#ifndef	_stub_gui_c
#define _stub_gui_c

int	initialisepixel( int mode )	
{	
	return(0); 	
}
void	liberatepixel()
{	
	return; 	
}

void	pixeltaskswitch()	{ return; }
void	loadguifont( int number, char  * buffer, int maxsize ) { return; }
int	guifontsize( int number ) { return( 0 ); } /* No Rows , No Columns */
int 	use_base_font( int number ) { return(number); }
int 	cicofont( char  * fptr){ return(0); }
int	cicocurser( int c, int l )	{ return( (c | (l << 8)) ); }
int	cicocolour( int f, int b )	{ return( (f | (b << 8)) ); }
int	cicopalette(int a, int b )	{ return( b ); }

int	putpixel(int c,int r, int v)	{ return( v ); }
int	getpixel(int c,int r)		{ return( ((c*r) & 0x00FF) ); }

int 	filzone(int a,int b, int c , int d, int e) { return(0); }
int	putzone(int a, int b, int c, int d, char  * e) {	return(0); }
int 	getzone(int a,int b, int c , int d, char  * e) { return(0); }
int 	putzoom(int a,int b, int c , int d,int f, char  * e) { return(0); }

int 	addzone(int a,int b, int c , int d, char  * e ) { return(0); }
int 	subzone(int a,int b, int c , int d, char  * e ) { return(0); }
int 	mixzone(int a,int b, int c , int d, char  * e) { return(0); }

int 	xorzone(int a,int b, int c , int d, int e ) { return(0); }
int 	andzone(int a,int b, int c , int d, int e ) { return(0); }
int 	orzone(int a,int b, int c , int d, int e ) { return(0); }


int	cicoshadow ( int svalue ) { return( svalue ); }
int	cicoatribut( int avalue ) { return( avalue ); }

int	testware()				{	return(0); 	}
int	hardware()				{	return(0); 	}
int	userware(int a, int b, char  * c)	{	return(0); 	}

#endif	// _stub_gui_c



