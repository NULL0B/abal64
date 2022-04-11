#ifndef	_stub_si_c
#define	_stub_si_c

#include <stdio.h>
int	_prlerrno=0;

static	int	handles[10] = {
	0,0,0,0,0,
	0,0,0,0,0
	};

static	int	handle=0;


int	si_open(char * nptr, int mode )
{
	int	h;
	for ( 	h=0;
		h< 10;
		h++ )
		if (!( handles[h] ))
			break;
	if ( h >= 10 )
		return( -1 );
	else	{
		handles[h] = 1;
		return(h);
		}
}

int	si_creat(char * nptr, int a, int b, int c)
{
	int	h;
	for ( 	h=0;
		h< 10;
		h++ )
		if (!( handles[h] ))
			break;
	if ( h >= 10 )
		return( -1 );
	else	{
		handles[h] = 1;
		return(h);
		}
}

int	si_close(int h)
{
	if (( h != -1 )
	&&  ( handles[h] != 0 ))
		handles[h] = 0;
	return(0);
}
	
int	si_unlink(char * nptr)
{
	return(0);
}

int	si_delete(int h, char * kptr, int marker )
{
	return(0);
}

int	si_insert(int h, char * kptr, int marker, char * bptr, int blen )
{
	return(0);
}
int	si_modif(int h, char * kptr, int marker , char * bptr, int blen )
{
	return(0);
}
int	si_search(int h, char * kptr, int marker , char * bptr, int blen )
{
	return(0);
}
int	si_lsearch(int h, char * kptr, int marker, char * bptr, int blen )
{
	return(0);
}
int	si_down(int h, int marker, char * bptr, int blen )
{
	return(0);
}
int	si_ldown(int h, int marker, char * bptr, int blen )
{
	return(0);
}
int	si_up(int h, int marker, char * bptr, int blen )
{
	return(0);
}
int	si_lup(int h, int marker, char * bptr, int blen )
{
	return(0);
}

#endif	// _stub_si_c






