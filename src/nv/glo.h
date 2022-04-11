//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_glo_h
#define _html_glo_h

#include "string.h"
#include "vga.h"
#include "piface.h"

class	bda_control;

#define	_GLO_DLL	"ljiv"

class	gui_laser : html_vga {

	static	int	underline;

	int	BufferLength;
	int	SourceLength;
	char *	RasterByte;
	char *	RasterWork;
	char *	OutputBuffer;

	printer_interface * listoutput;

	static	bda_control *	dll;

	static int DriverInitialise(char * palette, int a, int dpi, int grnbcol, int options);
	static int DriverColours();
	static int DriverConnect( char * bptr, char * wptr, char * result, int l );
	static int DriverStartRaster(char * result, int l);
	static int DriverPrintRow(char * result, int a , char * rowbuffer, int b);
	static int DriverEndRaster(char * result, int l);
	static int DriverLiberate(char * result, int l );

	int 	putlo( int c );

public:
		gui_laser( printer_interface * loptr, int dpi=300, int columns=800 );
	int	colour_count();
		~gui_laser();
	void 	printrow( char * rowbuffer );
	void	startraster();
	void	endraster();

	static	int	escapeTbugfix;
	static	int	underline_links;
	static	char *	dllname;
	static	void	setdllname( char * vptr );
};


#endif	// _html_glo_h


