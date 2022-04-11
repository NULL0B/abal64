//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_ansi_h
#define _html_ansi_h


class	ansi_iso_character_set	{

public:
	static	unsigned char A2P[256];
	static	unsigned char P2A[256];

	static	int AnsiToCico( int c );
	static	int CicoToAnsi( int c );

	};

extern "C" {
	int	macro_getch( int c );
	};

#endif	// _html_ansi_h



