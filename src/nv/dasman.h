//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_distant_access_manager_h
#define _distant_access_manager_h

#include "dascfg.h"

#define	_DAS_BUFFER_SIZE	1024

#define	_DAS_DLL_FILENAME	"dassv1"	// Executable library filename
#define	_DAS_DLL_STRINGSPACE	256		// Size of space required for
						// ABAL Data Type Conversions

#define	_DAS_DLL_VERSION	0
#define	_DAS_DLL_CONNECT	1 
#define	_DAS_DLL_DISCONNECT	2 
#define	_DAS_DLL_LISTPROFILES 	3 
#define	_DAS_DLL_GETPROFILE	4 
#define	_DAS_DLL_SETPROFILE	5 
#define	_DAS_DLL_DELPROFILE	6 
#define	_DAS_DLL_GETSTATUS	10
#define	_DAS_DLL_GETPHASE	11

#define	_DASSV1_DIALING		0x0001		// CONNECTE	???
#define	_DASSV1_READY		0x0010		// LINE UP 	???
#define	_DASSV1_CONNECTING	0x0100		// TACHE ACTIVE ???

#define	_DASSV1_DEAD		0x0000		// PHASE DEAD	
#define	_DASSV1_ESTABLISH	0x0001		// PHASE ESTABLISH
#define	_DASSV1_AUTHENTICATE	0x0002		// PHASE AUTHENTICATE
#define	_DASSV1_NETWORK		0x0003		// PHASE NETWORD
#define	_DASSV1_TERMINATE	0x0004		// PHASE TERMINATE

class	bda_control;
class	html_message_animator;

class	distant_access_manager : public distant_access_configuration {

	int	linestatus;
	int	dasloaded;
	int	dasconnected;

	short int	buffersize;

	char *  dasbuffer;

	bda_control * dll;

	int	InitDassv1();
	int	FinDassv1();

	int	DasConnect( char * hptr, char * pptr, char * nptr, char * uptr, char * wptr);  
	int	DasDisconnect( char * hptr );  
	int	DasGetProfile( char * pptr,char * bptr, short int  * blen, char * hptr);
	int	DasGetLineStatus( char * hptr, short int * result );
	int	DasGetPPPPhase( char * hptr, short int * result );

	int	user_intervention( html_message_animator * aptr, char * mptr );

public:
	distant_access_manager();
	~distant_access_manager();
	int	await_status();
	void	wait(int nbsec);

	};




#endif	// _distant_access_manager_h


