//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_jpeg_h
#define _html_jpeg_h

#include "vga.h"

class	bda_control;

#define	_JPEG_DLL	"jpeg"

class	html_binary_entity;

class	html_jpeg : html_vga {

	html_binary_entity * fstream;

	static	int	tempfiles;
	static	int	JpegColours;
	static	bda_control *	dll;

	static 	int JpegInitialise();
	static	int JpegLiberate();
	static 	int JpegOpen(char * filename,unsigned short int namelen, unsigned short int options);
	static	int JpegClose(unsigned short int handle);
	static	int JpegGetRow(unsigned short int handle,char * pixels,unsigned short int length);
	static	int JpegGetWidth(unsigned short int handle);
	static	int JpegGetHeight(unsigned short int handle);
	static	int JpegSetMemory(unsigned short int kilos);
	static	int JpegGetError(char * buffer,unsigned short int length);
	static	int Working;
	static	int jpegmemory;
	static	char ebuffer[81];
	static	void report_error();
	static	char * dllname;
public:
	html_jpeg( html_binary_entity * source );
	html_logical_image * parse(html_logical_image * iptr=0, int solo=0);
	static	void	setdllname( char * dllname );
	static	void	garbage_collector();
	static	int	adoption;
	static	int	admemory;
	};

#endif	// _html_jpeg_h




