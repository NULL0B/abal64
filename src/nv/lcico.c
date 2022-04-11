
short int	err_val=0;
short int	prndest=1;
unsigned char * prnptr=(unsigned char *) 0;
short int	prnleng=0;
short int	prndex=0;
short int	prnfid=0;


void	initerm()	{ return; }
void	finterm() 	{ return; }

void	x_putch(int i)
{
_asm	{
	push	cx
	mov  	ah,011h
	mov	cx,i
	int	110
	pop	cx
	}
	return;
}

int 	x_getch()
{ 
	int	c;
_asm	{
	mov  	ah,010h
	int	110
	xor	ah, ah
	mov	c,ax
	}
	return(c); 
}

int	x_kbhit()
{ 
	int	c=0;
_asm	{
	mov  	ah,011h
	int	110
	sahf
	jz	xkbf
	mov	c,1
xkbf:
	}
	return(c); 
}

void	_cfltcvt()	{ 	return; 	}
void	_cropzeros()	{ 	return; 	}

int	rexscreenwidth()	{ return( 80 ); }
int	rexscreenheight()	{ return( 25 ); }
int	rexscreencolumn()	{ return( 1 ); 	}
int	rexscreenline()		{ return( 1 ); 	}


