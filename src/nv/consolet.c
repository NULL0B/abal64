//	-----------------------------------------
//	Amenesik / Sologic Console Input / Output Functions
//	-----------------------------------------

static	int	console_ready=-1;

int	stcs_lines=0;
int	stcs_columns=0;
int	stcs_colour=0;
int	stcs_console=0;
int	stcs_pixel_x=800;
int	stcs_pixel_y=600;

extern	int	VncEnable;
extern	void	prologue();


int	consoletype()
{
	char	buffer[16];
	if ( console_ready == -1 ) {
		int	bufbytes=0;
		_asm	{
			push	ds
			push	bx
			push	cx
			lea	bx,buffer
			mov	ax,ss
			mov	ds,ax
			mov	cx,16
			mov	ax,01C01H
			call	prologue
			xor	ch,ch
			mov	bufbytes,cx
			pop	cx
			pop	bx
			pop	ds	
			}
		stcs_lines   = (buffer[0] & 0x00FF);
		stcs_columns = (buffer[1] & 0x00FF);
		stcs_colour  = (buffer[6] & 0x00FF);
		stcs_console = (buffer[7] & 0x00FF);
		if ( bufbytes < 13 ) {
			if (stcs_console != 0)
				console_ready = 0;
			else	console_ready = 1;
			}
		else 	{
			stcs_pixel_x = ((buffer[9] & 0x00FF) | ((buffer[10] & 0x00FF) << 8));
			stcs_pixel_y = ((buffer[11] & 0x00FF) | ((buffer[12] & 0x00FF) << 8));
			if ((stcs_pixel_x != 0)
			&&  (stcs_pixel_y != 0))
				console_ready = 1;
			else	console_ready = 0;
			}
		}
	return( console_ready );
}

int	console_number()
{
	return( stcs_console );
}

int	console_colour()
{
	return( stcs_colour );
}


