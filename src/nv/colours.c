#include <stdio.h>

int	main( argc, argv )
int	argc;
char *	argv[];
{
	int		i;
	unsigned char	rv;
	unsigned char	gv;
	unsigned char	bv;
	char	*	aptr;
	int	max=256;
	if ( argc > 1 )
		for (	aptr=argv[1],max=0;
			*aptr != 0;
			max = ((max *10) + ( *(aptr++) - '0' )));


	printf("\nstatic unsigned char VgaPalette[%u][3] = {\n",max);
	for ( i=0; i < max; i++ ) {

	_asm	{
		push	dx
		push	cx
		push	bx
		push	ax
		push	es
		push	di
		mov	bx,i			;** VGA PAlette Colour Code
		MOV     AX,1015H		;** GET RGB Register Info
		INT     10H			
		pop	di
		pop	es
		mov	rv,dh
		mov	gv,ch
		mov	bv,cl
		pop	ax
		pop	bx
		pop	cx
		pop	dx
		}

		printf("\t0x%02.1X, 0x%02.1X, 0x%02.1X",rv,gv,bv);

		if ( i < 255 )
			printf(", /* %u */\n",i);
		else	printf("  /* %u */\n",i);

		}
	printf("\t};\n");
	return(0);
}




