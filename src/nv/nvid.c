
//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_nvid_c
#define _html_nvid_c

#include "nvgesmes.h"

#ifdef	_WORLD_WIDE_WEB
#ifndef _NV11E
#ifndef _NV11D
#ifndef _NV11C
#ifndef	_NV11B
	static	char 	LaPaterne[16] = { '*','P','R','L','@','I','N','F','O','*','#',3,'1','1','a',0 };
#else
	static	char 	LaPaterne[16] = { '*','P','R','L','@','I','N','F','O','*','#',3,'1','1','b',0 };
#endif
#else
	static	char 	LaPaterne[16] = { '*','P','R','L','@','I','N','F','O','*','#',3,'1','1','c',0 };
#endif
#else
	static	char 	LaPaterne[16] = { '*','P','R','L','@','I','N','F','O','*','#',3,'1','1','d',0 };
#endif
#else
	static  char	VersionStatus[16]=
#ifndef	_NV11F
{ 'V','E','R','S','I','O','N','_','S','T','A','T','U','S',':','2' };
	static	char 	LaPaterne[32] = { '*','P','R','L','@','I','N','F','O','*','#',6,'1','1','e','0','1','1',0 };
#else
#ifndef	_NV11G
{ 'V','E','R','S','I','O','N','_','S','T','A','T','U','S',':','2' };
	static	char 	LaPaterne[32] = { '*','P','R','L','@','I','N','F','O','*','#',6,'1','1','f','0','0','9',0 };
#else
{ 'V','E','R','S','I','O','N','_','S','T','A','T','U','S',':','2' };
	static	char 	LaPaterne[32] = { '*','P','R','L','@','I','N','F','O','*','#',6,'1','1','g','0','0','6',0 };
#endif
#endif
#endif
#else
	static  char	VersionStatus[16]=
{ 'V','E','R','S','I','O','N','_','S','T','A','T','U','S',':','2' };
	static	char 	LaPaterne[16] = { '*','P','R','L','@','I','N','F','O','*','#',3,'1','1','a',0 };
#endif

static	char *	LaPointeur=(char*)0;
static	char 	LaVersion[16];


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

extern	"C" {
	int	UseNewMouse();
	}

void	nv_banner()
{
	printf("\n   %s : Version %s",gesmessage(_GESMES_BANNER),getpatternversion());
	if ( VersionStatus[15] == '2' )
		printf("\n   Provisoire du    %s",_VERDATE);
	if ( UseNewMouse() )
		printf("\n   Extended Mouse ",_VERDATE);
#ifdef	_NV11BX
	if ( VersionStatus[15] == '2' )
		printf("\n   HTTP 1.1 Alpha Version ");
#endif
	printf("\n   Copyright (c) 2000,2006 Amenesik / Sologic \n");
	return;
}

void	nv_usage()
{
	printf("\n   %s",_TEXT_HTML);
	printf(", %s, %s, %s",_IMAGE_BMP,_IMAGE_GIF,_IMAGE_JPEG);
	printf("\n   %s : ",gesmessage( _GESMES_USAGE ));
	printf("\n   [  -v   : %s ",gesmessage( _GESMES_OPTIONV ));
	printf("\n      -h   : %s ",gesmessage( _GESMES_OPTIONH ));
	printf("\n      -e   : %s ",gesmessage( _GESMES_OPTIONE ));
	printf("\n      -t   : %s ",gesmessage( _GESMES_OPTIONT ));
	printf("\n      -c%s : %s ",gesmessage( _GESMES_FILENAME ),gesmessage( _GESMES_OPTIONC ));
	printf("\n        %s ] \n",gesmessage( _GESMES_FILENAME ));
	return;
}




#endif	// _html_nvid_c


