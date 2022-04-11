#ifndef	_anaco_c
#define	_anaco_c

#include <stdio.h>
#include "stdgigo.h"

int	output=0;

private	struct	gigo_manager	Gigo;

private	void	newline()
{
	if ( output )
		printf("\n");
	output=0;
	return;
}


private	void	esc_push()
{
	newline();
	printf("esc > \n");
	return;
}

private	void	esc_pop()
{
	newline();
	printf("esc < \n");
	return;
}


/*	Set Mouse Mask to lb,hb		*/
/*	-----------------------		*/
private	void	esc_Z(int l, int h )
{	
	newline();
	printf("esc Z %u %u\n",l,h);
	return;
}

/*	Set Cursor position to C,L	*/
/*	--------------------------	*/
private	void	esc_f(int c, int l)
{
	newline();
	printf("esc f %u %u\n",c,l);
	return;
}

/*	switch text cursor off		*/
/* 	----------------------		*/
private	void	esc_w()
{
	newline();
	printf("esc w \n");
	return;
}

/*	switch  text cursor on		*/
/* 	----------------------		*/
private	void	esc_v()
{
	newline();
	printf("esc v \n");
	return;
}

/*	Reset atributs and colours	*/
/*	--------------------------	*/
private	void	esc_a()
{
	newline();
	printf("esc a \n");
	return;
}

/*	Activate Inverse Video		*/
/*	----------------------		*/
private	void	esc_b()
{
	newline();
	printf("esc b \n");
	return;
}

/*	Activate Blinking		*/
/*	-----------------		*/
private	void	esc_c()
{
	newline();
	printf("esc c \n");
	return;
}

/*	Activate Underline	*/
/*	------------------	*/
private	void	esc_d()
{
	newline();
	printf("esc d \n");
	return;
}

/*	Activate Halflight	*/
/*	------------------	*/
private	void	esc_e()
{
	newline();
	printf("esc e \n");
	return;
}

/*	Activate HighLight	*/
/*	------------------	*/
private	void	esc_h()
{
	newline();
	printf("esc h \n");
	return;
}

/*	Activate Compressed	*/
/*	-------------------	*/
private	void	esc_x()
{
	newline();
	printf("esc x \n");
	return;
}

/*	Activate Preferred 	*/
/*	------------------ 	*/
private	void	esc_p()
{
	newline();
	printf("esc p \n");
	return;
}

/*	Activate Italic		*/
/*	---------------		*/
private	void	esc_y()
{
	newline();
	printf("esc y \n");
	return;
}

/*	Activate Double Width : Shadow 	*/
/*	------------------------------	*/
private	void	esc_z()
{
	newline();
	printf("esc z \n");
	return;
}

/*	Activate Upper Case Conversion 	*/
/*	------------------------------	*/
private	void	esc_i()
{
	newline();
	printf("esc i \n");
	return;
}

/*	Activate Lower Case Conversion 	*/
/*	------------------------------	*/
private	void	esc_j()
{
	newline();
	printf("esc j \n");
	return;
}

/*	Set ForeGround Colour to C	*/
/*	--------------------------	*/
private	int	esc_r(int c)
{
	newline();
	printf("esc r %u \n",c);
	return( 0 );
}

/*	Set BackGround Colour to C	*/
/*	--------------------------	*/
private	int	esc_s(int c)
{
	newline();
	printf("esc s %u \n",c);
	return( 0 );
}

/*	Set Screen Wash or Erase Colour to C	*/
/*	------------------------------------	*/
private	int	esc_q(int c)
{
	newline();
	printf("esc q %u \n",c);
	return(0);
}

private	int	esc_n(int c)
{
	newline();
	printf("esc n %u \n",c);
	return(0);
}

/*	cico mode scroll	*/
/*	----------------	*/
private	void	esc_t()
{
	newline();
	printf("esc t \n");
	return;
}

/*	cico mode page 		*/
/*	--------------		*/
private	void	esc_u()
{
	newline();
	printf("esc u \n");
	return;
}

/*	cico mode block 	*/
/*	---------------		*/
private	void	esc_k()
{
	newline();
	printf("esc k \n");
	return;
}

public	int	esc_E()
{
	newline();
	printf("esc E \n");
	return( 0 );
}

public	int	esc_F()
{
	newline();
	printf("esc F \n");
	return( 0 );
}


/*	Clear to End of Line	*/
/*	--------------------	*/
private	void	esc_K()
{
	newline();
	printf("esc K \n");
	return;
}

/*	Clear to End of Page	*/
/*	--------------------	*/
private	void	esc_J()
{
	newline();
	printf("esc J \n");
	return;
}

/*	Insert Line  		*/
/*	-----------		*/
private	void	esc_L()
{
	newline();
	printf("esc L \n");
	return;
}

/*	Delete Line  		*/
/*	-----------		*/
private	void	esc_M()
{
	newline();
	printf("esc M \n");
	return;
}

/*	Insert Character	*/
/*	----------------	*/
private	void	esc_P()
{
	newline();
	printf("esc P \n");
	return;
}

/*	Delete Character	*/
/*	----------------	*/
private	void	esc_AT()
{
	newline();
	printf("esc @ \n");
	return;
}

/*	Hard Copy Graphic	*/
/*	-----------------	*/
public	int	esc_Q()
{
	newline();
	printf("esc Q \n");
	return(0);
}

/*	Transparent Mode	*/
/*	----------------	*/
public	int	esc_T()
{
	newline();
	printf("esc T %u \n",Gigo.escapetransfer);
	return;
}

public	void	co_putch(int c)
{	
	switch (Gigo.escapestate) {
		case	_ESC_normal	:	/* awaiting  escape character */
			if ( c == 27 ) {
				Gigo.escapestate = _ESC_active;
				return;
				}
			break;

		case	_ESC_active	:	/* awaiting escaped character */
			switch ((Gigo.escapecharacter = c)) {
				case	'T'	: /* transparent packet */
				case	'f'	: /* cursor positioning */
				case	'Z'	: /* mouse mask		*/
				case	'n'	: /* erase colour	*/
				case	'q'	: /* erase colour	*/
				case	's'	: /* wash colour	*/
				case	'r'	: /* Text colour	*/
				case	'('	: /* new visual atributs */
					Gigo.escapestate = _ESC_parameter;
					return;
				case	'E'	:
					esc_E();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'F'	:
					esc_F();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'u'	:
					esc_u();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'k'	:
					esc_k();
					Gigo.escapestate = _ESC_normal;
					return;
				case	't'	:
					esc_t();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'Q'	:
					esc_Q();
					Gigo.escapestate = _ESC_normal;
					return;

				case	'J'	:
					esc_J();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'K'	:
					esc_K();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'L'	:
					esc_L();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'M'	:
					esc_M();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'P'	:
					esc_P();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'@'	:
					esc_AT();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'v'	:
					esc_v();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'w'	:
					esc_w();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'a'	:
					esc_a();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'b'	:
					esc_b();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'c'	:
					esc_c();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'd'	:
					esc_d();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'e'	:
					esc_e();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'i'	:
					esc_i();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'j'	:
					esc_j();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'h'	:
					esc_h();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'x'	:
					esc_x();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'p'	:
					esc_p();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'y'	:
					esc_y();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'z'	:
					esc_z();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'>'	:
					esc_push();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'<'	:
					esc_pop();
					Gigo.escapestate = _ESC_normal;
					return;
				default		:
					Gigo.escapestate = _ESC_normal;
					return;
				}
		case	_ESC_parameter 	:	/* awaiting 1st parameter     */
			switch (Gigo.escapecharacter) {
				case	'T'	:
				case	'f'	:
				case	'Z'	:
					Gigo.escapeparameter = c;
					Gigo.escapestate = _ESC_special;
					return;

				case	'('	:
					/* these are simply filtered out */
					/* ----------------------------- */
					Gigo.escapestate = _ESC_normal;
					return;

				case	's'	:
					esc_s(c);
					Gigo.escapestate = _ESC_normal;
					return;
				case	'n'	:
					esc_n(c);
					Gigo.escapestate = _ESC_normal;
					return;
				case	'q'	:
					esc_q(c);
					Gigo.escapestate = _ESC_normal;
					return;
				case	'r'	:
					esc_r(c);
					Gigo.escapestate = _ESC_normal;
					return;
				default		:
					Gigo.escapestate = _ESC_normal;
					return;
				}
		case	_ESC_special   	:	/* awaiting 2nd parameter     */
			switch (Gigo.escapecharacter) {
				case	'T'	:
					Gigo.escapetransfer = (Gigo.escapeparameter + ((c & 0x00FF) * 256));
					Gigo.escapestate    = _ESC_transfer;
					esc_T();
					return;
					
				case	'f'	:
					Gigo.escapestate = _ESC_normal;
					esc_f(Gigo.escapeparameter,c);
					Gigo.escapestate = _ESC_normal;
					return;
				case	'Z'	:
					Gigo.escapestate = _ESC_normal;
					esc_Z(Gigo.escapeparameter,c);
					Gigo.escapestate = _ESC_normal;
					return;
				}
		case	_ESC_transfer  	:	/* performing transparent T   */
			if ( Gigo.escapetransfer ) {
				Gigo.escapetransfer--;
				}
			else	{
				Gigo.escapestate = _ESC_normal;
				}
			return;
		}
	
	/* None-escaped characters arrive here */
	/* ----------------------------------- */
	output=1;

	if ( c >= ' ' )
		printf("%c",(c&0x00FF));
	else	printf("\%02.2x",(c & 0x00FF));
	return;
}

private	int	analyse_file( char * nptr )
{
	FILE * h;
	int	c;
	if (!( h = fopen( nptr, "r" )))
		return(0);
	while ((c = fgetc(h)) > 0) {
		if ( c == 26 )
			break;
		else	co_putch((c & 0x00FF));
		}
	fclose(h);
	return(1);
}


public	int	main(int argc, char * argv[] )
{
	int	argi;
	char *	aptr;
	Gigo.escapestate = _ESC_normal;

	if ( argc == 1 ) {
		printf("\n   Co File Analyser : Version 1.0a.0.01\n   Copyright (c) 2006 Amenesik / Sologic \n\n");
		return(0);
		}

	for (argi=1; argi < argc; argi++ ) {
		if (!( aptr = argv[argi] ))
			break;
		else if ( *aptr == '-' ) {
			break;
			}
		else if (!( analyse_file( aptr ) ))
			break;
		}
	return;
}




#endif	/* _anaco_c */

