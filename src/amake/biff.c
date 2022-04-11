#include <stdio.h>
int	verbose=0;

int	get_word( FILE * h )
{
	int	v1;
	int	v2;
	if ((v1 = fgetc(h)) == -1)
		return(v1);
	else if ((v2 = fgetc(h)) == -1)
		return(v2);
	else 	return((((v2 & 0x00FF) << 8) | (v1 & 0x00FF)));
}

/*	-------------------	*/
/*	O L E   : functions	*/
/*	-------------------	*/

int	ole_operation(char * nomfic )
{
	FILE *	h;
	int	type;
	int	length;
	char	header[0x0200];

	if (!(h = fopen(nomfic,"rb")))
		return(40);
	else	{
		if ( verbose )
			printf("OLE FILE: %s \n",nomfic);

		fread(header,0x0200,1,h);

		fclose(h);
		return(0);
		}
}

/*	-------------------	*/
/*	B I F F : functions	*/
/*	-------------------	*/

int	biff_record( FILE * h, int type, int length)
{
	int	i;
	int	c;
	if ( verbose )
		printf("BIFF: %04.4X : %u : \n",type,length);

	switch ( type ) {
		case	-1 :	return( -1 );
		default	   :
			for ( i=0; i < length; i++ )
				c = fgetc(h);
			return(0);
		}
}

int	biff_header( FILE * h, int * type, int * length)
{
	int	v;
	*type = 0;
	*length = 0;
	if ((v = get_word(h)) == -1)
		return( v );
	else	*type = (v&0xFFFF);
	if ((v = get_word(h)) == -1)
		return( v );
	else	*length = (v&0xFFFF);
	return(0);
}


int	biff_operation(char * nomfic )
{
	FILE *	h;
	int	type;
	int	length;
	if (!(h = fopen(nomfic,"rb")))
		return(40);
	else	{
		if ( verbose )
			printf("BIFF FILE: %s \n",nomfic);

		while (( biff_header( h, &type, &length ) !=-1 )
		&&     ( biff_record( h,  type,  length ) !=-1 ));
		if ( verbose )
			printf("EOF : %s \n",nomfic);
		fclose(h);
		}
}

int	operation(char * nomfic )
{

	FILE *	h;
	int	c;
	int	type;
	int	length;
	if (!(h = fopen(nomfic,"rb")))
		return(40);
	else	{
		/* Detect OLE magic number */
		/* ----------------------- */
		if (((c = fgetc(h)) == 0x0D0)
		&&  ((c = fgetc(h)) == 0x0CF)
		&&  ((c = fgetc(h)) == 0x011)
		&&  ((c = fgetc(h)) == 0x0E0)
		&&  ((c = fgetc(h)) == 0x0A1)
		&&  ((c = fgetc(h)) == 0x0B1)
		&&  ((c = fgetc(h)) == 0x01A)
		&&  ((c = fgetc(h)) == 0x0E1)) {
			fclose(h);
			return( ole_operation( nomfic ) );
			}
		else	{
			fclose(h);
			return( biff_operation( nomfic ) );
			}
		}
}


int	doit(int argc, char * argv[] )
{
	int	status=0;
	int	argi;
	char *	aptr;
	for ( argi=1; argi < argc; argi++ ) {
		if (!( aptr = argv[argi] ))
			break;
		else if ( *aptr == '-' ) {
			switch ( *(aptr+1) ) {
				case	'v'	:
					verbose=1;
					continue;
				default		:
					return( 30 );
				}
			}
		else if ((status = operation( aptr )) != 0)
			return( status );
		}
	return(0);
}

int	banner()
{
	printf("\n   BIFF : Binary File Format Analyser : Version 1.0a.0.01 ");
	printf("\n   Provisoire du 29/10/2004 ");
	printf("\n   Copyright (c) Amenesik / Sologic \n\n");
	return(0);
}

int	main(int argc, char * argv[] )
{
	if ( argc == 1 )
		return( banner() );
	else	return( doit(argc,argv) );
}


