
static	unsigned char waitbuffer[16];

void	llwait( int delay )
{
	unsigned char far * descriptor = waitbuffer;
	*(descriptor+0) = 0x080;
	*(descriptor+1) = (delay & 0x00FF);
	*(descriptor+2) = ((delay>>8) & 0x00FF);
	*(descriptor+3) = 0;
	*(descriptor+4) = 0;
	*(descriptor+5) = 0;
	*(descriptor+6) = 0;
	*(descriptor+7) = 0;

_asm	{
	push	ds			
	push	bx
	push	ax
	lds	bx,descriptor
	mov	ah,42h	
	int	110
	lds	bx,descriptor
	mov	ah,31h	
	int	110
	pop	ax
	pop	bx
	pop	ds			
	};
	return;
}

char *	PlayCtrl="\0=PlayCtrl";
void	playnote( hertz, length )
{
	if ( *PlayCtrl != 0 ) {
		speaker(hertz);
		llwait(length);
		speaker(0);
		}
	return;
}

