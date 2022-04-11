#ifdef WIN32

/* New trace system */

#define CE_TRA_MASTERKEY    "[otr]"
#define CI_PRG_ID           "otr"
#define CI_TRA_ID_MASK_1    0xFF00	// Noyau
#define CI_TRA_ID_MASK_2    0x00FF	// OS dépendant

#include "trace.c"

#else	/* WIN32 */

#ifdef	strcpy
#undef  strcpy

char *	tracestrcpy( char * r, char * s )
{
	strcpy(r,s);
	sysprintf("tracestrcpy(0x%lx <- 0x%lx) : %s\r\n",r,s,r);
	return( r );
}

#endif

#ifdef	strcat
#undef  strcat

char *	tracestrcat( char * r, char * s )
{
	strcat(r,s);
	sysprintf("tracestrcat(0x%lx <- 0x%lx) : %s\r\n",r,s,r);
	return( r );
}

#endif


#endif	/* WIN32 */
















