//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_palette_c
#define _html_palette_c

void	get_palette()
{
	int	i;
	unsigned char rv,gv,bv;
	if ( verbose )
		printf("get_palette()\n");
	for ( i=0; i < 256; i++ ) {

		_asm	{
			push	dx
			push	cx
			push	bx
			push	ax
			push	es
			push	di
			mov	bx,i		;** VGA PAlette Colour Code
			MOV     AX,1015H	;** GET RGB Register Info
			INT     10H			
			pop	di
			pop	es
			shl	dh,1
			shl	dh,1
			mov	rv,dh
			shl	ch,1
			shl	ch,1
			mov	gv,ch
			shl	cl,1
			shl	cl,1
			mov	bv,cl
			pop	ax
			pop	bx
			pop	cx
			pop	dx
			}
		VgaPalette[i][0] = rv;
		VgaPalette[i][1] = gv;
		VgaPalette[i][2] = bv;
		VgaPalette[i][3] =  0;
		if ( verbose )
			printf("%u :%u,%u,%u,%u\n",i,rv,gv,bv,0);

		}
	return;
}

void	put_palette()
{
	int	i;
	unsigned char rv,gv,bv;	

	if ( verbose )
		printf("put_palette()\n");
	for ( i=0; i < 256; i++ ) {
		rv = VgaPalette[i][0];
		gv = VgaPalette[i][1];
		bv = VgaPalette[i][2];
		if ( verbose )
			printf("%u :%u,%u,%u,%u\n",i,rv,gv,bv,0);
		_asm	{
			push	ax
			mov	bx,i
			mov	dh,rv
			shr	dh,1
			shr	dh,1
			mov	ch,gv
			shr	ch,1
			shr	ch,1
			mov	cl,bv
			shr	cl,1
			shr	cl,1
			MOV     AX,1010H	;** SET DAC Register Info
			INT     10H			
			pop	ax
			}
		}

	return;
}

void	save_palette( char * filename )
{
	int		i,v;
	FILE *		handle;
	get_palette();

	if ((handle = fopen( filename, "wb" )) != (FILE *) 0) {
		fwrite( & VgaPalette, 256 * 4, 1, handle);
		fclose( handle );
		}
	return;
}

void	load_palette( char * filename )
{
	int		i,v;
	FILE *		handle;
	if ((handle = fopen( filename, "rb" )) != (FILE *) 0) {
		fread( & VgaPalette, 256 * 4, 1, handle);
		fclose( handle );
		put_palette();
		}
	return;
}

#endif	// _html_palette_c

