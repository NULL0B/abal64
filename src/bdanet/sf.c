#ifndef	_sf_c
#define	_sf_c

#include "sf.h"

#ifdef	_DEBUG
extern	int	verbose;
extern	int	debug;
#endif

static	char	descriptor[256];

int	open_sf( char * nptr, int mode )
{
	int	i;
	int	handle=-1;
#ifdef	_DEBUG
	if ( debug )
		printf("open_sf(%s,%u)\n",nptr,mode);
#endif
	for (i=0; *(nptr+i) != 0; i++)
		descriptor[(i+32)] = *(nptr+i);
	descriptor[(i+32)] = ' ';
	descriptor[(i+33)] = 0;

	_asm	{
		mov	dx,offset descriptor
		mov	bx,dx
		add	bx,32
		mov	ah,01H
		int	110
		sahf
		jns	onyva
whoops:		xor	ah,ah
		jmp	canevaplus
onyva:		
		mov	bx,dx
		mov	ax,mode
		int	110
		sahf
		jnz	whoops		
		mov	cl,ch
		xor	ch,ch
		mov	handle,cx
canevaplus:	
		}
	
	return(handle);;
}


int	close_sf( int handle )
{
	int	status=0;
	if ( handle != -1) {
#ifdef	_DEBUG
		if ( debug )
			printf("close_sf(%u)\n",handle);
#endif
		_asm	{
			mov	bx,offset descriptor
			mov	ax,handle
			mov	ds:[bx],al
			mov	ax,_SF_CLOSE
			int	110
			xor	ah,ah
			mov	status,ax		
			}
		}
	return(status);
}

int	read_sf( int handle, int sf_code, char * buffer, int plength, long offset)
{
	int	status=0;
	int	option=(int)offset;
	if ( handle != -1) {
#ifdef	_DEBUG
		if ( debug )
			printf("read_sf(%u,%x,%u,%lu)\n",handle,sf_code,plength,offset);
#endif
		descriptor[0] = (handle & 0x00FF);
		
		_asm	{
			mov	bx,offset descriptor
			mov	ax,handle
			mov	byte ptr ds:[bx],al
			push	es
			push	di
			les	di,buffer
			mov	word ptr ds:[bx][+1],di
			mov	word ptr ds:[bx][+3],es
			pop	di
			pop	es
			mov	ax,plength
			mov	word ptr ds:[bx][+5],ax
			mov	ax,option
			mov	word ptr ds:[bx][+7],ax
			mov	word ptr ds:[bx][+9],0
			mov	ax,sf_code
			int	110
			xor	ah,ah
			mov	status,ax		
			}
		}
	return(status);
}

int	write_sf( int handle, int sf_code, char * buffer, int plength, long offset)
{
#ifdef	_DEBUG
	if ( debug )
		printf("write_sf(%u,%x,%u,%lu)\n",handle,sf_code,plength,offset);
#endif
	return( read_sf( handle, sf_code, buffer, plength, offset ) );
}

#endif	/* _sf_c */


