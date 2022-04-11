#include <stdio.h>

#define _default_numeral	"0 0 moveto 0 750 lineto 750 750 lineto 750 0 lineto closepath stroke"
#define _default_lowercase	"0 0 moveto 0 550 lineto 550 550 lineto 550 0 lineto closepath fill"
#define _default_uppercase	"0 0 moveto 0 750 lineto 750 750 lineto 750 0 lineto closepath fill"
#define _default_lowercircle	"400 400 350 0 360 arc stroke"

#define _0_default_numeral	_default_numeral
#define _1_default_numeral	_default_numeral
#define _2_default_numeral	_default_numeral
#define _3_default_numeral	_default_numeral
#define _4_default_numeral	_default_numeral
#define _5_default_numeral	_default_numeral
#define _6_default_numeral	_default_numeral
#define _7_default_numeral	_default_numeral
#define _8_default_numeral	_default_numeral
#define _0_default_numeral	_default_numeral

#define _a_default_lowercase	_default_lowercircle
#define _b_default_lowercase	_default_lowercase
#define _c_default_lowercase	_default_lowercircle
#define _d_default_lowercase	_default_lowercase
#define _e_default_lowercase	_default_lowercircle
#define _f_default_lowercase	_default_lowercase
#define _g_default_lowercase	_default_lowercase
#define _h_default_lowercase	_default_lowercase
#define _i_default_lowercase	_default_lowercase
#define _j_default_lowercase	_default_lowercase
#define _k_default_lowercase	_default_lowercase
#define _l_default_lowercase	_default_lowercase
#define _m_default_lowercase	_default_lowercase
#define _n_default_lowercase	_default_lowercase
#define _o_default_lowercase	_default_lowercircle
#define _p_default_lowercase	_default_lowercase
#define _q_default_lowercase	_default_lowercase
#define _r_default_lowercase	_default_lowercase
#define _s_default_lowercase	_default_lowercase
#define _t_default_lowercase	_default_lowercase
#define _u_default_lowercase	_default_lowercase
#define _v_default_lowercase	_default_lowercase
#define _w_default_lowercase	_default_lowercase
#define _x_default_lowercase	_default_lowercase
#define _y_default_lowercase	_default_lowercase
#define _z_default_lowercase	_default_lowercase

#define _A_default_uppercase	_default_uppercase
#define _B_default_uppercase	_default_uppercase
#define _C_default_uppercase	_default_uppercase
#define _D_default_uppercase	_default_uppercase
#define _E_default_uppercase	_default_uppercase
#define _F_default_uppercase	_default_uppercase
#define _G_default_uppercase	_default_uppercase
#define _H_default_uppercase	_default_uppercase
#define _I_default_uppercase	_default_uppercase
#define _J_default_uppercase	_default_uppercase
#define _K_default_uppercase	_default_uppercase
#define _L_default_uppercase	_default_uppercase
#define _M_default_uppercase	_default_uppercase
#define _N_default_uppercase	_default_uppercase
#define _O_default_uppercase	_default_uppercase
#define _P_default_uppercase	_default_uppercase
#define _Q_default_uppercase	_default_uppercase
#define _R_default_uppercase	_default_uppercase
#define _S_default_uppercase	_default_uppercase
#define _T_default_uppercase	_default_uppercase
#define _U_default_uppercase	_default_uppercase
#define _V_default_uppercase	_default_uppercase
#define _W_default_uppercase	_default_uppercase
#define _X_default_uppercase	_default_uppercase
#define _Y_default_uppercase	_default_uppercase
#define _Z_default_uppercase	_default_uppercase

char *	numeral[] = {
	_0_default_numeral,	_1_default_numeral,
	_2_default_numeral,	_3_default_numeral,
	_4_default_numeral,	_5_default_numeral,
	_6_default_numeral,	_7_default_numeral,
	_8_default_numeral,	_0_default_numeral
	};

char *	lowercase[] = {
	_a_default_lowercase,	_b_default_lowercase,
	_c_default_lowercase,	_d_default_lowercase,
	_e_default_lowercase,	_f_default_lowercase,
	_g_default_lowercase,	_h_default_lowercase,
	_i_default_lowercase,	_j_default_lowercase,
	_k_default_lowercase,	_l_default_lowercase,
	_m_default_lowercase,	_n_default_lowercase,
	_o_default_lowercase,	_p_default_lowercase,
	_q_default_lowercase,	_r_default_lowercase,
	_s_default_lowercase,	_t_default_lowercase,
	_u_default_lowercase,	_v_default_lowercase,
	_w_default_lowercase,	_x_default_lowercase,
	_y_default_lowercase,	_z_default_lowercase
	};

char *	uppercase[] = {
	_A_default_uppercase,	_B_default_uppercase,
	_C_default_uppercase,	_D_default_uppercase,
	_E_default_uppercase,	_F_default_uppercase,
	_G_default_uppercase,	_H_default_uppercase,
	_I_default_uppercase,	_J_default_uppercase,
	_K_default_uppercase,	_L_default_uppercase,
	_M_default_uppercase,	_N_default_uppercase,
	_O_default_uppercase,	_P_default_uppercase,
	_Q_default_uppercase,	_R_default_uppercase,
	_S_default_uppercase,	_T_default_uppercase,
	_U_default_uppercase,	_V_default_uppercase,
	_W_default_uppercase,	_X_default_uppercase,
	_Y_default_uppercase,	_Z_default_uppercase
	};

char	buffer[2048];

int	semigraph=0;

void	generate_semigraph(FILE * h, int i)
{
	/* symbols requiring full vertical bar */
	/* ----------------------------------- */
	switch ( i ) {
		/* Double bars */
		/* ----------- */
		case	0x00B9	:
		case	0x00BA	:
		case	0x00B6	:
		case	0x00CC	:
		case	0x00CE	:
			fprintf(h,"400 0 moveto 400 1000 lineto stroke\n");
			fprintf(h,"600 0 moveto 600 1000 lineto stroke\n");
			break;

		/* Single bars */
		/* ----------- */
		case	0x00B3	:
		case	0x00B4	:
		case	0x00B5	:
		case	0x00C3	:
		case	0x00C5	:
		case	0x00C6	:
		case	0x00C7	:
		case	0x00D7	:
		case	0x00D8	:
			fprintf(h,"500 0 moveto 500 1000 lineto stroke\n");
			break;

		}

	/* symbols requiring full horizontal bar */
	/* ------------------------------------- */
	switch ( i ) {
		/* Double bars */
		/* ----------- */
		case	0x00CA	:
		case	0x00CB	:
		case	0x00CD	:
		case	0x00CE	:
		case	0x00CF	:
			fprintf(h,"0 400 moveto 1000 400 lineto stroke\n");
			fprintf(h,"0 600 moveto 1000 600 lineto stroke\n");
			break;

		/* Single bars */
		/* ----------- */
		case	0x00C1	:
		case	0x00C2	:
		case	0x00C4	:
		case	0x00C5	:
		case	0x00D7	:
			fprintf(h,"0 500 moveto 1000 500 lineto stroke\n");
			break;

		}

	/* symbols requiring left half */
	/* --------------------------- */
	switch ( i ) {
		/* Double bars */
		/* ----------- */
		case	0x00B5	:
		case	0x00B8	:
		case	0x00B9	:
		case	0x00BB	:
		case	0x00BC	:
		case	0x00BE	:
			fprintf(h,"0 400 moveto 500 400 lineto stroke\n");
			fprintf(h,"0 600 moveto 500 600 lineto stroke\n");
			break;

		/* Single bars */
		/* ----------- */
		case	0x00B4	:
		case	0x00B6	:
		case	0x00B7	:
		case	0x00BD	:
		case	0x00BF	:
		case	0x00D0	:
		case	0x00D2	:
		case	0x00D9	:
			fprintf(h,"0 500 moveto 500 500 lineto stroke\n");
			break;

		/* Single bars */
		/* ----------- */
		}

	/* symbols requiring right half */
	/* ---------------------------- */
	switch ( i ) {
		/* Double bars */
		/* ----------- */
		case	0x00C6	:
		case	0x00C8	:
		case	0x00C9	:
		case	0x00CC	:
		case	0x00D4	:
		case	0x00D5	:
			fprintf(h,"500 400 moveto 1000 400 lineto stroke\n");
			fprintf(h,"500 600 moveto 1000 600 lineto stroke\n");
			break;

		/* Single bars */
		/* ----------- */
		case	0x00C0	:
		case	0x00C3	:
		case	0x00D0	:
		case	0x00D3	:
		case	0x00D6	:
		case	0x00DA	:
			fprintf(h,"500 500 moveto 1000 500 lineto stroke\n");
			break;
		}

	/* symbols requiring upper half */
	/* ---------------------------- */
	switch ( i ) {
		/* Double bars */
		/* ----------- */
		case	0x00BC	:
		case	0x00BD	:
		case	0x00C8	:
		case	0x00CA	:
		case	0x00D0	:
		case	0x00D3	:
			fprintf(h,"400 1000 moveto 400 500 lineto stroke\n");
			fprintf(h,"600 1000 moveto 600 500 lineto stroke\n");
			break;
		/* Single bars */
		/* ----------- */
		case	0x00BE	:
		case	0x00C0	:
		case	0x00C1	:
		case	0x00CF	:
		case	0x00D4	:
		case	0x00D9	:
			fprintf(h,"500 1000 moveto 500 500 lineto stroke\n");
		}

	/* symbols requiring lower half */
	/* ---------------------------- */
	switch ( i ) {
		/* Double bars */
		/* ----------- */
		case	0x00BB	:
		case	0x00C9	:
		case	0x00CB	:
		case	0x00D2	:
		case	0x00D6	:
			fprintf(h,"400 500 moveto 400 0 lineto stroke\n");
			fprintf(h,"600 500 moveto 600 0 lineto stroke\n");
			break;
		/* Single bars */
		/* ----------- */
		case	0x00B8	:
		case	0x00BF	:
		case	0x00C2	:
		case	0x00D1	:
		case	0x00D5	:
		case	0x00DA	:
			fprintf(h,"500 500 moveto 500 0 lineto stroke\n");
			break;
		}
	/* full symbols */
	/* ------------ */
	switch ( i ) {
		case	0x00DB	:
			fprintf(h,"0 0 moveto 0 1000 lineto 1000 1000 lineto 1000 0 lineto closepath fill\n");
			break;
		case	0x00DC	:
			fprintf(h,"0 0 moveto 0 500 lineto 1000 500 lineto 1000 0 lineto closepath fill\n");
			break;
		case	0x00DD	:
			fprintf(h,"0 0 moveto 0 1000 lineto 500 1000 lineto 500 0 lineto closepath fill\n");
			break;
		case	0x00DE	:
			fprintf(h,"500 0 moveto 500 1000 lineto 1000 1000 lineto 1000 0 lineto closepath fill\n");
			break;
		case	0x00DF	:
			fprintf(h,"0 500 moveto 0 1000 lineto 1000 1000 lineto 1000 500 lineto closepath fill\n");
			break;
		
		}
	return;
}

int	action(char * nptr)
{
	int	i;
	FILE * h;
	sprintf(buffer,"%s.ps",nptr);
	if (!( h = fopen(buffer, "w")))
		return(failure(46));
	else	{

		/* define a dictionary to receive the font */
		/* --------------------------------------- */
		fprintf(h,"/%s 10 dict def\n%s begin\n",nptr,nptr);

		/* Define the basic member items */
		/* ----------------------------- */
		fprintf(h,"\t/FontType 3 def \n");
		fprintf(h,"\t/FontMatrix [ .001 0 0 .001 0 0 ] def\n");
		fprintf(h,"\t/FontBBox [ 0 0 1000 1000 ] def\n");

		/* Define the encoding table */
		/* ------------------------- */
		fprintf(h,"\t/Encoding 256 array def\n");

		fprintf(h,"\t0 1 255 { Encoding exch /.notdef put } for\n");
		for ( i='0'; i <= '9'; i++ ) fprintf(h,"\tEncoding %u /letter%c put\n",i,i);
		for ( i='a'; i <= 'z'; i++ ) fprintf(h,"\tEncoding %u /letter%c put\n",i,i);
		for ( i='A'; i <= 'Z'; i++ ) fprintf(h,"\tEncoding %u /letter%c put\n",i,i);
		if ( semigraph ) {
			for ( i=0x00B3; i <= 0x00DF; i++ ) fprintf(h,"\tEncoding %u /symbol%02.2x put\n",i,i);
			}

		/* Define the character drawing procedures */
		/* --------------------------------------- */
		fprintf(h,"\t/CharProcs 3 dict def CharProcs begin\n");

		fprintf(h,"\t\t/.notdef {} def \n");
		for ( i='0'; i <= '9'; i++ ) fprintf(h,"\t\t/letter%c { %s } def \n",i,numeral[i-'0']);
		for ( i='a'; i <= 'z'; i++ ) fprintf(h,"\t\t/letter%c { %s } def \n",i,lowercase[i-'a']);
		for ( i='A'; i <= 'Z'; i++ ) fprintf(h,"\t\t/letter%c { %s } def \n",i,uppercase[i-'A']);
		if ( semigraph ) {
			for ( i=0x00B3; i <= 0x00DF; i++ ) {
				fprintf(h,"\t\t/symbol%02.2x {\n",i);
				generate_semigraph(h,i);
				fprintf(h," } def \n");
				}
			}
		fprintf(h,"\tend\n");


		/* Define the Character Build Procedure */
		/* ------------------------------------ */
		fprintf(h,"\t/BuildChar {\n");

		fprintf(h,"\t\t1000 0 \n");
		fprintf(h,"\t\t0 0 750 750 \n");
		fprintf(h,"\t\tsetcachedevice \n");
		fprintf(h,"\t\texch begin \n");
		fprintf(h,"\t\tEncoding exch get \n");
		fprintf(h,"\t\tCharProcs exch get \n");
		fprintf(h,"\t\tend exec \n");
		fprintf(h,"\t} def \n");
		fprintf(h,"end\n\n\n");

		fprintf(h,"/ExampleFont %s definefont pop\n",nptr);

		fprintf(h,"/ExampleFont findfont 12 scalefont setfont\n");
		fprintf(h,"74 240 moveto (0123456789) show\n");

		fprintf(h,"/ExampleFont findfont 14 scalefont setfont\n");
		fprintf(h,"74 200 moveto (abcdefghijklmnopqrstuvwxyz) show\n");

		fprintf(h,"/ExampleFont findfont 16 scalefont setfont\n");
		fprintf(h,"74 160 moveto (ABCDEFGHIJKLMNOPQRSTUVWXYZ) show\n\n");

		if ( semigraph ) {
			fprintf(h,"/ExampleFont findfont 16 scalefont setfont\n");
			fprintf(h,"74 400 moveto (³´µ¶·¸¹º»¼½¾¿ÀÁÂÃÄÅÆÇÈÉ) show\n");
			fprintf(h,"74 460 moveto (ÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞß) show\n\n");
			}
		fclose(h);
		return(0);
		}
}

int	failure(int v )
{
	printf("\nfailure : %u \n",v);
	return(v);
}

int	option(char * aptr)
{
	switch ( *(aptr++) ) {
		case	'g'	:
			semigraph = 1;
			return(0);
		}
	return(failure(30));
}

int	operation( int argc, char * argv[] )
{
	int	status=0;
	int	argi;
	char *	aptr;
	for (argi=1; argi < argc; argi++) {
		if (!( aptr = argv[argi] ))
			break;
		else if ( *aptr == '-' ) {
			if (!(status = option((aptr+1))))
				continue;
			else	break;
			}
		else if (!(status = action(aptr)))
			continue;
		else	break;
		}
	return(status);
}


int	banner()
{
	printf("\n   PostScript Font Builder : Version 1.0a.0.01 ");
	printf("\n   Provisoire du 04/08/2005 ");
	printf("\n   Copyright (c) 2005,2006 Amenesik / Sologic \n");
	return(0);
}


int	main( int argc, char * argv[] )
{
	if ( argc == 1 )
		return( banner() );
	else	return( operation(argc,argv));
}

