void	abqt()
{
	_asm	{
		push	ax
		mov	ah,035H
#ifdef	MAIN
	int	110
#else
	call	prologue
#endif
		pop	ax
		};
	return;
}
	
static	char waitbuffer[16];
	
void	llwait( char * descriptor )
{
_asm	{
	push	ds			;** DS ==> Pile
	push	bx
	push	ax
	lds	bx,descriptor
	mov	ah,42h	
#ifdef	MAIN
	int	110
#else
	call	prologue
#endif
	lds	bx,descriptor
	mov	ah,31h	
#ifdef	MAIN
	int	110
#else
	call	prologue
#endif
	pop	ax
	pop	bx
	pop	ds			
	};
	return;
}

void	wait( int dixsec )
{
	waitbuffer[0] = 0x80;
	waitbuffer[1] = (dixsec & 0x00FF);
	waitbuffer[2] = ((dixsec >> 8) & 0x00FF);
	waitbuffer[3] = waitbuffer[4] = 
	waitbuffer[5] = waitbuffer[6] = waitbuffer[7] = 0;
	llwait( waitbuffer );
	return;
}

#ifdef	MAIN
int	integer(char * sptr)
{
	int	r=0;
	while ( *sptr ) {
		if ((*sptr >= '0') && ( *sptr <= '9'))
			r = ((r * 10) + ( *(sptr++) - '0'));
		else	break;
		}
	return( r );
}
int	main(int argc, char * argv[])
{
	if ( argc==1 )
		printf("\n   Wait : Version 1.1a.0.01 \n   Copyright (c) 2001,2006 Amenesik / Sologic \n");
	else	wait( integer( argv[1] ) );
	return(0);
}

#endif

