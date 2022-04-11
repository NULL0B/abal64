//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_printer_interface_h
#define _printer_interface_h

class	printer_interface {
public:
	printer_interface(int mode=0);
	virtual int 		loch(int c);
	int			outputisvalid;
	};

#endif	// _printer_interface_h


