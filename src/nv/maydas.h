//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_DASSV1_H
#define _DASSV1_H

#define	_DAS_BUFFER_SIZE	256

#define	_DASSV1_DIALING		0x0001		// CONNECTE	???
#define	_DASSV1_READY		0x0010		// LINE UP 	???
#define	_DASSV1_CONNECTING	0x0100		// TACHE ACTIVE ???

#define	_DASSV1_DEAD		0x0000		// PHASE DEAD	
						// PPP inactive

#define	_DASSV1_ESTABLISH	0x0001		// PHASE ESTABLISH
						// PPP establishing connection

#define	_DASSV1_AUTHENTICATE	0x0002		// PHASE AUTHENTICATE
						// PPP Authentification under way

#define	_DASSV1_NETWORK		0x0003		// PHASE NETWORD
						// PPP Connected

#define	_DASSV1_TERMINATE	0x0004		// PHASE TERMINATE
						// PPP Disconntecting

#ifdef	_DASSV1_C

extern	"C"	{

#include "bda.h"

	};
			

#define	_DASSV1_DLL_CONNECT	 0 /* %DasConnect(#?,$,$,$,$)		*/
#define	_DASSV1_DLL_DISCONNECT	 1 /* %DasDisconnect(#)			*/
#define	_DASSV1_DLL_VERSION	 2 /* %VersDasSv1($?)			*/
#define	_DASSV1_DLL_LISTPROFILES 3 /* %DasGetListProfiles($?,%?,%?)	*/
#define	_DASSV1_DLL_GETPROFILE	 4 /* %DasGetProfile($,$?,%?,#?)	*/
#define	_DASSV1_DLL_SETPROFILE	 5 /* %DasSetProfile($,$?,%?)		*/
#define	_DASSV1_DLL_DELPROFILE	 6 /* %DasDelProfile($)			*/
#define	_DASSV1_DLL_GETSTATUS	 7 /* %DasGetLineStatus(#,%?)		*/
#define	_DASSV1_DLL_GETPHASE	 8 /* %DasGetPPPPhase(#,%?)		*/


static	unsigned short int	DasSv1DllLoaded=0;
static	unsigned short int	DasSv1LibId=-1;
static	void __far *		DasSv1Pstack[5];
static 	unsigned short int 	DasSv1Wstack[5];
static	unsigned char 		DasSv1Bstack[5];
static	char *		DasSv1ProfileBuffer=(char *) 0;
static	char 		DasWorkBuffer[1024];
static	BDA_INIT	DasSv1Context;


static	unsigned char *	DasSv1LibraryName=(unsigned char *)"dassv1";
static	unsigned int    DasSv1LibraryFlag=0;

#endif

#endif	// _DASSV1_H



