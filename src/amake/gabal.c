#include <stdio.h>
#include <stdlib.h>

struct	generation_control	{
	int	segments;
	int	procedures;
	int	variables;
	int	constants;
	int	ismodule;
	int	instructions;
	int	external;
	} context = { 1, 1, 1, 1, 0, 0 };

void	codeblock(FILE * h)
{
	int	i;
	for (i=0; i < context.instructions; i++ ) {
		switch ((i % 7)) {
			case	0 : 
				fprintf(h,"Do :: Loop\r\n"); 
				break;
			case	1 : 
				fprintf(h,"if ( 1 = 1 ) :: Endif\r\n"); 
				break;
			case	2 : 
				fprintf(h,"while (1 < 2) :: Wend\r\n"); 
				break;
			case	3 : 
				fprintf(h,"Repeat :: Until ( 1 > 3 )\r\n"); 
				break;
			case	4 : 
				fprintf(h,"Select 4 :: Case 1 :: Case 2 :: Case 3 :: Default :: EndSel\r\n");
				break;
			case	5 : 
				fprintf(h,"Wait 5\r\n");
				break;
			case	6 : 
				fprintf(h,"Pause 6\r\n");
				break;

			}
		}
	return;		
}

void	call_external_procedures(FILE * h)
{
	int	i;
	int	n;
	int	v=0;
	int	t=0;
	int	l;
	for (	n=1,i=0,t=0,v=0; i < context.procedures; i++, v++ ) {
		fprintf(h,"Call\tP%u(",i);
		for (l=1; l < n; l++,v++ ) {
			if ( l > 1 ) fprintf(h,",");
			switch ( t ) {
				case	0 :	fprintf(h,"%u",l); 		break;
				case	1 :	fprintf(h,"%u",l); 		break;
				case	2 :	fprintf(h,"%u.%u",l,v); 	break;
				case	3 :	fprintf(h,"%c%u%u%c",0x0022,l,v,0x0022);break;
				case	4 :	fprintf(h,"%u",l);	break;
				}
			t++; if ( t > 4 ) t = 0;
			}
		fprintf(h,")\r\n");
		n++; if ( n > 20 ) n = 0;
		}
	return;
}

void	call_external_segments(FILE * h)
{
	int	i;
	int	n;
	int	v=0;
	int	t=0;
	int	l;
	for (	n=0,i=0,t=0,v=0; i < context.segments; i++, v++ )
		fprintf(h,"Ldgo.Seg S%u\r\n",i);
	return;
}

int	doit(char * nptr)
{
	int	i;
	int	n;
	int	v=0;
	int	t=0;
	int	l;
	FILE * h;
	if (!( h = fopen( nptr,"w" ) ))
		return(46);

	if ( context.ismodule )
		fprintf(h,"Module %cgenmod%c\r\n",0x0022,0x0022);
	else	fprintf(h,"Program %cgenprg%c\r\n",0x0022,0x0022);


	for (	i=0,t=0,v=0; i < context.constants; i++,v++ ) {
		switch ( t ) {
			case	0 :	fprintf(h,"Const C%u#=%u\r\n",i,v); 			break;
			case	1 :	fprintf(h,"Const C%u%=%u\r\n",i,v); 			break;
			case	2 :	fprintf(h,"Const C%u=%u.%u\r\n",i,v,v); 		break;
			case	3 :	fprintf(h,"Const C%u$=%c%u%c\r\n",i,0x0022,v,0x0022); 	break;
			case	4 :	fprintf(h,"Const C%u:=%u\r\n",i,v); 			break;
			}
		t++; if ( t > 4 ) t = 0;
		}

	for (	i=0,t=0,v=0; i < context.variables; i++,v++ ) {
		switch ( t ) {
			case	0 :	fprintf(h,"Dcl\tV%u#\r\n",i); 		break;
			case	1 :	fprintf(h,"Dcl\tV%u%%\r\n",i); 		break;
			case	2 :	fprintf(h,"Dcl\tV%u=%u\r\n",i,v); 	break;
			case	3 :	fprintf(h,"Dcl\tV%u$=%u\r\n",i,v); 	break;
			case	4 :	fprintf(h,"Dcl\tV%u:\r\n",i);	break;
			case	5 :	fprintf(h,"Ptr\tV%u#\r\n",i); 		break;
			case	6 :	fprintf(h,"Ptr\tV%u%%\r\n",i); 		break;
			case	7 :	fprintf(h,"Ptr\tV%u=%u\r\n",i,v); 	break;
			case	8 :	fprintf(h,"Ptr\tV%u$=%u\r\n",i,v); 	break;
			case	9 :	fprintf(h,"Ptr\tV%u:\r\n",i);	break;

			case	10 :	fprintf(h,"Dcl\tV%u#(%u)\r\n",i,v); 	break;
			case	11 :	fprintf(h,"Dcl\tV%u%%(%u)\r\n",i,v); 	break;
			case	12 :	fprintf(h,"Dcl\tV%u=%u(%u)\r\n",i,v,v); 	break;
			case	13 :	fprintf(h,"Dcl\tV%u$=%u(%u)\r\n",i,v,v);break;
			case	14 :	fprintf(h,"Dcl\tV%u:(%u)\r\n",i,v);	break;
			case	15 :	fprintf(h,"Ptr\tV%u#(%u)\r\n",i,v); 	break;
			case	16 :	fprintf(h,"Ptr\tV%u%%(%u)\r\n",i,v); 	break;
			case	17 :	fprintf(h,"Ptr\tV%u=%u(%u)\r\n",i,v,v); 	break;
			case	18 :	fprintf(h,"Ptr\tV%u$=%u(%u)\r\n",i,v,v);break;
			case	19 :	fprintf(h,"Ptr\tV%u:(%u)\r\n",i,v);	break;

			case	20 :	fprintf(h,"Dcl\tV%u#(%u,%u)\r\n",i,v,v); 	break;
			case	21 :	fprintf(h,"Dcl\tV%u%%(%u,%u)\r\n",i,v,v); 	break;
			case	22 :	fprintf(h,"Dcl\tV%u=%u(%u,%u)\r\n",i,v,v,v); 	break;
			case	23 :	fprintf(h,"Dcl\tV%u$=%u(%u,%u)\r\n",i,v,v,v); 	break;
			case	24 :	fprintf(h,"Dcl\tV%u:(%u,%u)\r\n",i,v,v);	break;
			case	25 :	fprintf(h,"Ptr\tV%u#(%u,%u)\r\n",i,v,v); 	break;
			case	26 :	fprintf(h,"Ptr\tV%u%%(%u,%u)\r\n",i,v,v); 	break;
			case	27 :	fprintf(h,"Ptr\tV%u=%u(%u,%u)\r\n",i,v,v,v); 	break;
			case	28 :	fprintf(h,"Ptr\tV%u$=%u(%u,%u)\r\n",i,v,v,v); 	break;
			case	29 :	fprintf(h,"Ptr\tV%u:(%u,%u)\r\n",i,v,v);	break;
			}

		t++; if ( t > 29 ) t = 0;
		}

	for (	n=1,i=0,t=0,v=0; i < context.procedures; i++, v++ ) {
		if (( context.external == 'P' ) 
		||  ( context.external == 'A' ))
			fprintf(h,"Extern\t");
		fprintf(h,"Proc\tP%u(",i);
		for (l=1; l < n; l++,v++ ) {
			if ( l > 1 ) fprintf(h,",");
			switch ( t ) {
				case	0 :	fprintf(h,"L%u#",l); 		break;
				case	1 :	fprintf(h,"L%u%%",l); 		break;
				case	2 :	fprintf(h,"L%u=%u",l,v); 	break;
				case	3 :	fprintf(h,"L%u$=%u",l,v); 	break;
				case	4 :	fprintf(h,"L%u:",l);	break;
				case	5 :	fprintf(h,"Ptr L%u#",l); 		break;
				case	6 :	fprintf(h,"Ptr L%u%%",l); 		break;
				case	7 :	fprintf(h,"Ptr L%u=%u",l,v); 	break;
				case	8 :	fprintf(h,"Ptr L%u$=%u",l,v); 	break;
				case	9 :	fprintf(h,"Ptr L%u:",l);	break;

				case	10 :	fprintf(h,"L%u#(%u)",l,v); 	break;
				case	11 :	fprintf(h,"L%u%%(%u)",l,v); 	break;
				case	12 :	fprintf(h,"L%u=%u(%u)",l,v,v); 	break;
				case	13 :	fprintf(h,"L%u$=%u(%u)",l,v,v);break;
				case	14 :	fprintf(h,"L%u:(%u)",l,v);	break;
				case	15 :	fprintf(h,"Ptr L%u#(%u)",l,v); 	break;
				case	16 :	fprintf(h,"Ptr L%u%%(%u)",l,v); 	break;
				case	17 :	fprintf(h,"Ptr L%u=%u(%u)",l,v,v); 	break;
				case	18 :	fprintf(h,"Ptr L%u$=%u(%u)",l,v,v);break;
				case	19 :	fprintf(h,"Ptr L%u:(%u)",l,v);	break;

				case	20 :	fprintf(h,"L%u#(%u,%u)",l,v,v); 	break;
				case	21 :	fprintf(h,"L%u%%(%u,%u)",l,v,v); 	break;
				case	22 :	fprintf(h,"L%u=%u(%u,%u)",l,v,v,v); 	break;
				case	23 :	fprintf(h,"L%u$=%u(%u,%u)",l,v,v,v); 	break;
				case	24 :	fprintf(h,"L%u:(%u,%u)",l,v,v);	break;
				case	25 :	fprintf(h,"Ptr L%u#(%u,%u)",l,v,v); 	break;
				case	26 :	fprintf(h,"Ptr L%u%%(%u,%u)",l,v,v); 	break;
				case	27 :	fprintf(h,"Ptr L%u=%u(%u,%u)",l,v,v,v); 	break;
				case	28 :	fprintf(h,"Ptr L%u$=%u(%u,%u)",l,v,v,v); 	break;
				case	29 :	fprintf(h,"Ptr L%u:(%u,%u)",l,v,v);	break;
				}
			t++; 
			if (( context.external == 'P' ) 
			||  ( context.external == 'A' )) {
				if ( t > 4 )
					t = 0;
				}
			else if ( t > 9 ) 
				t = 0;
			}
		n++; if ( n > 20 ) n = 0;
		fprintf(h,")\r\n");
		if (( context.external == 'P' ) 
		||  ( context.external == 'A' )) 
			continue;
		if ( context.instructions ) codeblock(h);
		fprintf(h,"EndProc\r\n");
		}

	if (( context.external == 'S' ) 
	||  ( context.external == 'A' )) {
		for (	n=0,i=0,t=0,v=0; i < context.segments; i++, v++ )
			fprintf(h,"Extern\tSegment S%u\r\n",i);
		}

	if (!( context.ismodule )) {
		fprintf(h,"Segment 0\r\n",i);
		if (( context.external == 'P' ) 
		||  ( context.external == 'A' )) 
			call_external_procedures(h);
		if (( context.external == 'S' ) 
		||  ( context.external == 'A' )) 
			call_external_segments(h);
		fprintf(h,"\tStop\r\n",i);
		fprintf(h,"Eseg 0\r\n",i);
		}

	if (( context.external != 'S' )
	&&  ( context.external != 'A' )) {
		for (	n=0,i=0,t=0,v=0; i < context.segments; i++, v++ ) {
			fprintf(h,"Segment S%u\r\n",i);
			if ( context.external == 'P' ) 
				call_external_procedures(h);
			if ( context.instructions ) codeblock(h);
			fprintf(h,"\tRet.Seg\r\n",i);
			fprintf(h,"Eseg S%u\r\n",i);
			}
		}

	fprintf(h,"End\r\n");

	fclose(h);
	return(0);
}


int	banner()
{

	printf("\n   Abal Test Program Generator : Version 1.0a.0.02 ");
	printf("\n   Provisoire du 15/12/2003 ");
	printf("\n   Copyright (c) 2003 Amenesik / Sologic \n");
	printf("\n   Syntax : \n");
	printf("\n              gabal [ options ] file\n");
	printf("\n   Options: \n");
	printf("\n        -xP|S|A        ");
	printf("\n        -mmodule       ");
	printf("\n        -ssegments     ");
	printf("\n        -pprocedures   ");
	printf("\n        -vvariables    ");
	printf("\n        -cconstants    ");
	printf("\n        -iinstructions \n\n");
	return(0);
}


int	integer(char * sptr)
{
	int	r=0;
	while (( *sptr >= '0' ) && ( *sptr <= '9' ))
		r = ((r*10) + ( *(sptr++) -'0' ));
	return(r);
}

int	main( int argc, char * argv[] )
{
	int	argi;
	char *	aptr;

	if ( argc == 1 )
		return( banner() );

	for (argi=1; argi < argc; argi++ ) {
		if (!( aptr = argv[argi] ))
			break;
		else if ( *aptr == '-' ) {
			switch ( *(aptr+1) ) {
				case	'x'	:
				case	'X'	:
					context.external = *(aptr+2);
					continue;

				case	'm'	:
				case	'M'	:
					context.ismodule = 1;
					continue;

				case	's'	:
				case	'S'	:
					context.segments = integer((aptr+2));
					continue;
				case	'v'	:
				case	'V'	:
					context.variables = integer((aptr+2));
					continue;
				case	'p'	:
				case	'P'	:
					context.procedures = integer((aptr+2));
					continue;

				case	'c'	:
				case	'C'	:
					context.constants = integer((aptr+2));
					continue;
				case	'i'	:
				case	'I'	:
					context.instructions = integer((aptr+2));
					continue;
				}
			continue;
			}
		else	doit( aptr );
		}
	return(0);

}




