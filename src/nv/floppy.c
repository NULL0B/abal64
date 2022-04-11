#include <stdio.h>

#define	word	unsigned short

static word	rax=0;
static word	rbx=0;
static word	rcx=0;
static word	rdx=0;
static word	rsi=0;
static word	rdi=0;
static word	rbp=0;
static word	rflags=0;

void	showregisters(int mode)
{

	printf("\tflags : %x \n",rflags);

	if ( mode & 1 )
		printf("\tAX=%x",rax);
	if ( mode & 2 )
		printf("\tBX=%x",rbx);
	if ( mode & 4 )
		printf("\tCX=%x",rcx);
	if ( mode & 8 )
		printf("\tDX=%x",rdx);

	printf("\n");
	return;
}


int	main( int argc, char * argv[] )
{
	printf("\n   Floppy Disk Interrupt Inspector : Version 1.0a \n");

	printf("\n   function AH=00h, DL=00H : reinitialisation \n");

_asm	{
	mov	ah,0
	mov	dl,0
	int	13h
	push	ax
	pushf	
	pop	ax
	mov	rflags,ax
	pop	ax
	mov	rax,ax
	};

	showregisters(1);

	printf("\n   function AH=01h, DL=00H : read status      \n");
_asm	{
	mov	ah,1
	mov	dl,0
	int	13h
	push	ax
	pushf	
	pop	ax
	mov	rflags,ax
	pop	ax
	mov	rax,ax
	};

	showregisters(1);

	printf("\n   function AH=08h, DL=00H : disk parameters  \n");
_asm	{
	mov	ah,8
	mov	dl,0
	int	13h
	push	ax
	push	bx
	push	cx
	push	dx
	pushf	
	pop	ax
	mov	rflags,ax
	pop	ax
	mov	rdx,ax
	pop	ax
	mov	rcx,ax
	pop	ax
	mov	rbx,ax
	pop	ax
	mov	rax,ax
	};
	showregisters(0x000F);

	return(0);
}

