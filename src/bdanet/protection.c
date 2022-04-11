#include <errno.h>

#ifndef	EXTRA_SERVERS
#define	EXTRA_SERVERS	256
#endif

#define	MAX_CONN_PROT	16
#define	NB_ACCES	EXTRA_SERVERS

#ifdef	CLIENT_VERSION
#define	CODE_CLIENT	32
#endif

#define	CODE_BDANET	31

#define	PROT_VERSION_BDANET	"3.2"

static	short	NbAccesRestants=0;
static	int	ProductCode=0;
extern	int	ServerFailure;

#ifdef VERSION_DEMO
/*	----------------------------	*/
/*	Version Demo : No Protection	*/
/*	----------------------------	*/
/*	 Product Limited Elsewhere	*/
/*	----------------------------	*/
int	protConnect()		{	return(1);	}
int	protDisconnect()	{	return(0);	}
int	protLoadPgm( short i, char * v, short * n, int p, int * e )
{
	*e = 0;
	*n = 1;
	return(0);
}

int	protUnloadPgm( short i, char * v, short * n, int p, int * e )
{
	*e = 0;
	*n = 1;
	return(0);
}

#else	/* ! VERSION_DEMO */

#define	ABAL32X

extern	int	protConnect();
extern	int	protDisconnect();
extern	int	protLoadPgm( short i, char * v, short * n, int p, int * e );
extern	int	protUnloadPgm( short i, char * v, short * n, int p, int * e );
extern	int	protAccessNumber(short i, char * v, int n, int * e);

#endif


long	UseProtection(int * Jeton,int mode)
{
	int 	socketProt=-1;
	int 	cpt=0;
	long 	errConn = 0;
	short 	nbAcces = 1;
	long 	ErrProt = 0;
	int 	RetourProt = 0;	
	char *	qptr;
	int	i;

	while ( (cpt < MAX_CONN_PROT) && (socketProt == -1)) {
		if ((socketProt = protConnect()) == -1) {
			/* Connexion non etablie */
			if ( (errno == EISCONN)	|| (errno == ECONNREFUSED)) {
				/* Quelqu'un est deja connecte */
				usleep(6);
				cpt++;
				}
			else	{
				cpt = MAX_CONN_PROT;
				errConn = 221;
				}
			}
		}

	if (socketProt == -1) {
		/* Connexion refusee */
		return((long)221);
		}

	if ( mode ) {
#ifdef	CLIENT_VERSION
		if (!(RetourProt = protLoadPgm((ushort)(ProductCode = CODE_CLIENT), (char *)PROT_VERSION_BDANET, (short *)&nbAcces, (pid_t)getpid(), (int *)&ErrProt))) {
			*Jeton = mode;
			ServerFailure = errConn = 0;
			}
		else
#endif
		if ((RetourProt = protLoadPgm((ushort)(ProductCode = CODE_BDANET), (char *)PROT_VERSION_BDANET, (short *)&nbAcces, (pid_t)getpid(), (int *)&ErrProt)) != 0)
			ServerFailure = errConn = 221;
		else	{
			*Jeton = mode;
			ServerFailure = errConn = 0;
			}
		}
	else if ( ProductCode != 0 ) {
		if ((RetourProt = protUnloadPgm((ushort)ProductCode, (char *)PROT_VERSION_BDANET, (short *)&nbAcces, (pid_t)getpid(), (int *)&ErrProt)) != 0)
			errConn = 221;
		else	*Jeton = mode;
		ProductCode = 0;
		}

	if (protDisconnect() != 0)
		errConn = 221;

	return( errConn );
}


