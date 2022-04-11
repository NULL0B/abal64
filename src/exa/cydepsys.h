





/*								26/06/95 
-------------------------------------------------------------------------------

  				CRITERIA 3.3

  	CYDEPSYS.H 			 	ctes os-dependant
						macros os-dependent

-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
*/


/* implementation MS-DOS en multisession bidon				*/
#ifdef ISDOSSRV
#include "cydossys.h"		/* -->> define 	ISDOS			*/
				/*		CLIENT_SERVEUR		*/
				/*		ISDOSWIN		*/
#endif

/* implementation MS-DOS en mode station				*/
#ifdef ISDOSSTA
#include "cydossys.h"		/* -->> define 	ISDOS			*/
				/*		ISDOSWIN		*/
#endif



/* implementation Amenesik / Sologic en client serveur / reseau			*/
#ifdef ISPRLSRV
#include "cyprlsys.h"		/* -->> define 	ISPRL			*/
				/*		CLIENT_SERVEUR		*/
#endif

/* implementation Windows 3.1 en client serveur NON RESEAU (disparaitra */
/*				a terme pour etre remplacee par ISW31STA*/
/*		sera conservee en interne pour debug CLIENT_SERVEUR	*/
#ifdef ISW31SRV
#include "cyw16sys.h"		/* -->> define 	ISWIN			*/
#endif				/*		WIN31			*/
				/*		CLIENT_SERVEUR		*/
				/*		ISDOSWIN		*/


/* implementation Windows 3.1 en mode station RESEAU 			*/
#ifdef ISW31STA
#include "cyw16sys.h"		/* -->> define 	ISWIN			*/
#endif				/*		WIN31			*/
				/*		ISDOSWIN		*/

/* implementation Warp        en mode station RESEAU 			*/
#ifdef ISWARSTA
#include "cyw16sys.h"		/* -->> define 	ISWIN			*/
#endif				/*		WIN31			*/
				/*		ISDOSWIN		*/


/* implementation Windows NT (3.1) en client serveur NON RESEAU 	*/
/*	sera reecrite en SERVICE avec PIPE NOMMES pour fonctionner	*/
/*	en reseau							*/
#ifdef ISWNTSRV
#include "cywntsys.h"		/* -->> define 	ISWIN			*/
#endif				/*		WINNT			*/
				/*		CLIENT_SERVEUR		*/
				/*		ISDOSWIN		*/


/* Implementation UNIX en client serveur 				*/
#ifdef ISUNXSRV
#include "cyunxsys.h"
#endif

/* Implementation Windows NT (3.5) sous la forme d'un SERVICE. 		*/
/* C'est un programme de type CONSOLE (interface de type texte).	*/
/* Mode 32 bits. 													*/

#ifdef ISANTSRV
#include "cyantsys.h"
#endif


#ifdef NETWARE
#include "cyntwsys.h"
#endif

/* Implementation UNIX / AIX en client serveur 				*/
#ifdef ISAIXSRV
#include "cyaixsys.h"
#endif


/* Implementation sous Power PC sous NT					*/
#ifdef IPSV
#include "cyppcsys.h"
#endif
