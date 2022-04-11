//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_zone_descriptor_h
#define	_html_zone_descriptor_h

class	html_zone_descriptor 	{

public:

	html_zone_descriptor(int nbc=64, int nbl=16 );

	char	* buffer;
	int	  zonecolumns;
	int	  zonelines;
	int	  zoneline;
	int	  zonecolumn;
	int	  zonefore;
	int	  zoneback;
	int	  zoneatcol;
	int	  zoneatlin;


	};

#endif 	// _html_zone_descriptor_h

