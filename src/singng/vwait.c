#ifndef	_vwait_c
#define	_vwait_c

void	visual_abqt()
{
#if   defined(UNIX)
#elif defined(WIN32)
#else
	_asm	{
		push	ax
		mov	ah,035H
		int	110
		pop	ax
		};
	
#endif
	return;
}
	
static	char waitbuffer[16];

void	visual_wait( int dixsec )
{
#if   defined(UNIX)
	usleep(dixsec*10);
#elif defined(WIN32)
	Sleep(dixsec*100);
#else
	waitbuffer[0] = 0x80;
	waitbuffer[1] = (dixsec & 0x00FF);
	waitbuffer[2] = ((dixsec >> 8) & 0x00FF);
	waitbuffer[3] = waitbuffer[4] = 
	waitbuffer[5] = waitbuffer[6] = waitbuffer[7] = 0;
	llwait( waitbuffer );
#endif
	return;
}
#endif	/* _vwait_c */




