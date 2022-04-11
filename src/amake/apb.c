#include <stdio.h>

/*	---------------------	*/
/*	ABAL PRODUCT BUILDER	*/
/*	---------------------	*/
#ifdef	GCC
#define	compiler_name "gcc"
#else
#define	compiler_name "cc"
#endif
static	char	*	productname=(char *) 0;
static	int		productnumber=0;
static	char	*	kompiler=(char *) compiler_name;
static	char	*	directory  =(char *) 0;
static	char	*	product_name  =(char *) 0;
static	char	*	source_package=(char *) 0;
static	char	*	target_package=(char *) 0;
static	char	*	preinstall=(char *) 0;
static	char	*	install=(char *) 0;
static	char	*	postinstall=(char *) 0;
static	int		verbose=0;
static	int		keeper=0;
static	char		command[2048];
static	int		physikal=0;
static	int		inhibit_generation=0;
static	int		debug=0;

static	int	build_image_matrix( FILE * t, char * nomfic )
{
	FILE * h;
	int	c;
	int	columns=0;
	int	rows=0;
	int	bytes=0;
	if ( physikal )
		return(0);
	else if (!( h = fopen( nomfic, "rb" ) ))
		return(40);
	else 	{
		
		fprintf(t,"unsigned char binary_image[] = {");
		while (( c = fgetc( h )) != -1 ) {
			if ( bytes++ )
				fprintf(t,",");
			if (!( columns++ ))
				fprintf(t,"\n\t");
			fprintf(t,"0x0%x",(c & 0x00FF));
			if ( columns > 64 )
				columns=0;
			}
		fprintf(t,"\n\t};\n\n");
		fprintf(t,"unsigned int image_size=%u;\n\n",bytes);
		fclose(h);
		return( 0 );
		}
}

static	int	copy_image_matrix( FILE * t, char * nomfic )
{
	FILE * h;
	int	c;
	int	columns=0;
	int	rows=0;
	int	bytes=0;

	if (!( physikal ))
		return(0);

	if ( verbose ) { printf("concatenating image   : %s\n",nomfic); }

	if (!( h = fopen( nomfic, "rb" ) ))
		return(40);
	else 	{
		while (( c = fgetc( h )) != -1 )
			fputc((c & 0x00FF),t);
		fclose(h);
		return( 0 );
		}
}


static	int	physical_builder(
			char * tptr,	/* target package filename */
			char * sptr, 	/* package source filename */
			char * bptr	/* binary package to encapsulate */
			)
{
	FILE	*	r;
	FILE	*	s;
	int	c;

	if ( verbose ) { printf("concatenating product : %s\n",product_name); }

	if (!( s = fopen(tptr,"rb"))) {
		if ( verbose ) { printf("error opening : %s\n",tptr); }
		return( 40 );
		}
	else if (!( r = fopen("./apb.join.out","wb") )) {
		if ( verbose ) { printf("error creating temporary file\n"); }
		fclose(s);
		return( 46 );
		}
	while ((c = fgetc(s)) != -1)
		fputc(c,r);

	fclose(s);	
	fprintf(r,"[*(+</{--%s--}/>+)*] " ,sptr);
	copy_image_matrix(r,bptr);
	fclose(r);	
	sprintf(command,"mv ./apb.join.out %s ",tptr );
	system(command);	
	sprintf(command,"chmod +x %s ",tptr );
	system(command);	
	return(0);
}

static	int	build_product_source( char * nomfic )
{
	FILE	*	t;
	int	status;
	if ( verbose ) { printf("creating product source file : %s\n",nomfic); }
	if (!( t = fopen( nomfic,"w") )) { return( 58 ); }
	if ( verbose ) { printf("writing product source image : %s\n",source_package); }

	fprintf(t,"#include <stdio.h>\n");
	fprintf(t,"unsigned char * directory=%c%s%c;\n",0x0022,directory,0x0022);
	fprintf(t,"unsigned char * target_name=%c%s%c;\n",0x0022,target_package,0x0022);
	fprintf(t,"unsigned char * source_name=%c%s%c;\n",0x0022,source_package,0x0022);
	fprintf(t,"unsigned char * source_file=%c%s%c;\n",0x0022,nomfic,0x0022);
	fprintf(t,"unsigned char * product_name=%c%s%c;\n",0x0022,product_name,0x0022);
	fprintf(t,"unsigned char * semicolon=%c;%c;\n",0x0022,0x0022);
	fprintf(t,"unsigned char * space    =%c %c;\n",0x0022,0x0022);
	if ( productname != (char *) 0 ) {
		fprintf(t,"unsigned char * productname=%c%s%c;\n",0x0022,productname,0x0022);
		}
	if ( productnumber != 0 ) {
		fprintf(t,"unsigned int    productnumber=%u;\n",productnumber);
		}

	fprintf(t,"unsigned int    control  =1;\n");
	if ( physikal ) {
		fprintf(t,"unsigned char * payload=%c[*(+</{--%s--}/>+)*]%c;\n" ,0x0022,nomfic,0x0022);
		fprintf(t,"unsigned int    payload_offset=1;\n");
		}
	if ( preinstall )
		fprintf(t,"unsigned char * preinstall=%c%s%c;\n" ,0x0022,preinstall,0x0022);
	else	fprintf(t,"unsigned char * preinstall=(char *)0;\n");

	if ( install )
		fprintf(t,"unsigned char * install=%c%s%c;\n"    ,0x0022,install,0x0022);
	else	fprintf(t,"unsigned char * install=(char *)0;\n");

	if ( postinstall )
		fprintf(t,"unsigned char * postinstall=%c%s%c;\n",0x0022,postinstall,0x0022);
	else	fprintf(t,"unsigned char * postinstall=(char *) 0;\n");

	if (( status = build_image_matrix(t, source_package )) != 0) {
		if ( verbose ) { printf("/* error : %u : build_image_matrix : %s */\n",status,source_package); }
		fprintf(t,"/* error : %u : build_image_matrix : %s */\n",status,source_package);
		}
	else	{
		fprintf(t,"static char buffer[2048];\n");
		fprintf(t,"static int option(char * aptr)\n");
		fprintf(t,"{\n");
		fprintf(t,"\tif ((*aptr == '-') && (*(aptr+1) =='i')) { control=0; return(1); }\n");
		fprintf(t,"\tif ((*aptr != '-') || (*(aptr+1) !='v')) { return(0); }\n");
		fprintf(t,"\tprintf(%cProduct Name    : %%s\\n%c,product_name);\n",0x0022,0x0022);
		fprintf(t,"\tprintf(%cGeneration      : %%s\\n%c,source_file);\n",0x0022,0x0022);
		if ( directory ) {
			fprintf(t,"\tprintf(%cDirectory       : %%s\\n%c,directory);\n",0x0022,0x0022);
			}
		fprintf(t,"\tprintf(%cProduct Source  : %%s\\n%c,source_name);\n",0x0022,0x0022);
		fprintf(t,"\tprintf(%cProduct Target  : %%s\\n%c,target_name);\n",0x0022,0x0022);
		if ( preinstall ) {
			fprintf(t,"\tprintf(%cPreInstall      : %%s\\n%c,preinstall);\n",0x0022,0x0022);
			}
		fprintf(t,"\tprintf(%cInstallation    : %%s\\n%c,install);\n",0x0022,0x0022);
		if ( postinstall ) {
			fprintf(t,"\tprintf(%cPostInstall     : %%s\\n%c,postinstall);\n",0x0022,0x0022);
			}
		fprintf(t,"\treturn(0);\n");
		fprintf(t,"}\n\n");

		if ( physikal ) {
			/* generate payload detection function */
			/* ---------------------------------- */
			fprintf(t,"static FILE * payload_detect(char * aptr)\n");
			fprintf(t,"{\n");
			fprintf(t,"\tFILE * h=(FILE*)0;\n");
			fprintf(t,"\tint    i=0;\n");
			fprintf(t,"\tint    v=0;\n");
			fprintf(t,"\tint pass=0;\n");
			fprintf(t,"\tif (!(h = fopen(aptr,%crb%c))) { return(h); }\n",0x0022,0x0022);
			fprintf(t,"\twhile(1) {\n");
			fprintf(t,"\t\tpayload_offset++;\n");
			fprintf(t,"\t\tif ((v = fgetc(h)) == -1) { break; }\n");
			fprintf(t,"\t\telse if (!( payload[i] )) { if (!( v )) { i=0; continue; } else { return(h); } }\n");
			fprintf(t,"\t\telse if ((v & 0x00FF) != payload[i]) { i=0; continue; }\n");
			fprintf(t,"\t\telse { i++; continue; }\n");
			fprintf(t,"\t\t}\n");
			fprintf(t,"\tfclose(h);\n");
			fprintf(t,"\treturn((FILE *)0);\n");
			fprintf(t,"}\n");
			}

		fprintf(t,"int main(int argc,char * argv[])\n");
		fprintf(t,"{\n");
		fprintf(t,"\tFILE * h=(FILE*)0;\n");
		if ( physikal )
			fprintf(t,"\tFILE * bh=(FILE*)0;\n");
		fprintf(t,"\tint    i=0;\n");
		fprintf(t,"\tif ( argc != 1 ) { if (!( option(argv[1]))) return(0); }\n");
		fprintf(t,"\tif ( geteuid() ) { printf(%cSuper user mode required for the installation of this package\\n%c); return(0); }\n",0x0022,0x0022);

		if ( physikal )
			fprintf(t,"\tif (!( bh = payload_detect(argv[0]) )) { return(0); }\n"); 

		fprintf(t,"\tprintf(%cproduct installation : %%s\\n%c,argv[0]);\n",0x0022,0x0022);

		if ( directory ) {
			fprintf(t,"\tstrcpy(buffer,%cmkdir %c);\n",0x0022,0x0022);
			fprintf(t,"\tstrcat(buffer,directory);\n");
			fprintf(t,"\tstrcat(buffer,%c 2>/dev/null %c);\n",0x0022,0x0022);
			fprintf(t,"\tsystem(buffer);\n");
			}
		fprintf(t,"\tif (!(h = fopen(target_name,%cwb%c))) { return(1); }\n",0x0022,0x0022);
		if (!( physikal )) {
			fprintf(t,"\twhile (i < image_size) { fputc((binary_image[i++]&0x00FF),h); }\n");
			}
		else	{
			fprintf(t,"\twhile ((i = fgetc(bh)) != -1) { fputc((i & 0x00FF),h); }\n");
			fprintf(t,"\tfclose(bh);\n");
			}
		fprintf(t,"\tfclose(h);\n");
		fprintf(t,"\tbuffer[0]=0;\n");
		fprintf(t,"\tif ( preinstall )  {\n");
		fprintf(t,"\t\tstrcat(buffer,preinstall);\n");
		fprintf(t,"\t\tstrcat(buffer,semicolon );\n\t}\n");

		fprintf(t,"\tif ( install )  {\n");
		fprintf(t,"\t\tstrcat(buffer,install);\n");
		fprintf(t,"\t\tstrcat(buffer,space);\n");
		fprintf(t,"\t\tstrcat(buffer,target_name);\n");
		fprintf(t,"\t\tstrcat(buffer,semicolon );\n\t}\n");

		fprintf(t,"\tif (( postinstall ) && ( control ))  {\n");
		fprintf(t,"\t\tstrcat(buffer,postinstall);\n");
		fprintf(t,"\t\tstrcat(buffer,semicolon );\n\t}\n");
		fprintf(t,"\tsystem(buffer);\n");

		if (( productname != (char *) 0 )
		&&  ( productnumber != 0        )) {
			fprintf(t,
				"\tsprintf(buffer,%caddnamecode -f %cc%cs%cc -c %cu %c,0x0022,productname,0x0022,productnumber);\n",
				0x0022,	0x0025,0x0025,0x0025,0x0025,0x0022
				);
			fprintf(t,"\tsystem(buffer);\n");
			fprintf(t,"\tprintf(%cDo not forget to install and validate the end-user product license.%cn%c);\n",0x0022,0x005C,0x0022);
			}

		fprintf(t,"\treturn(0);\n");
		fprintf(t,"}\n");
		}
	fprintf(t,"\n/*end of file*/\n\n");
	fclose(t);
	return(status);
}

static	int	compile_product_source( char * nomfic )
{

	if ( verbose ) { printf("compiling product : %s\n",product_name); }

	if (!( product_name )) {
		printf("error: you must supply the -x option\n");
		return(1);
		}
	else	{
		if ( debug )
			sprintf(command,"%s -g -ggdb -o %s %s",kompiler,product_name,nomfic );
		else	sprintf(command,"%s -o %s %s",kompiler,product_name,nomfic );
		if (!( system( command ) )) {
			if (!( keeper )) { unlink( nomfic ); }
			if ( verbose ) { printf("product %s compile : ok\n",product_name); }
			return(0);
			}
		else 	{
			if ( verbose )
				printf("\n compile error : %s \n",command);
			return(4);
			}
		}
}

static	int	product_builder( char * nptr )
{
	int	status;
	FILE *	t;
	char	buffer[256];

	if (!( target_package )) {
		printf("error: you must supply the -t option\n");
		return(1);
		}
	else if (!( source_package )) {
		printf("error: you must supply the -s option\n");
		return(2);
		}
	else if (!( install )) {
		printf("error: you must supply the -i option\n");
		return(1);
		}

	else if (((!( productname )) && (   productnumber  ))
	     ||  ((   productname  ) && (!( productnumber )))) {
		printf("error: you must supply either both or neither options -k and -n \n");
		return(1);
		}

	sprintf(buffer,"./apb%x.c",time((long*)0));

	if ((status = build_product_source( buffer )) != 0)
		return( status );
	else if ( inhibit_generation )
		return( 0 );
	else if ((status = compile_product_source(buffer)) != 0)
		return(status);
	else if (!( physikal ))
		return( 0 );
	else if ((status = physical_builder(
			product_name,
			buffer,
			source_package
			)) != 0)
		return( status );
	else	return( 0 );
}

static	int	option( char * aptr )
{
	switch ( *aptr ) {
		case	'v'	:	verbose=1; 			return(0);
		case	'c'	:	kompiler  	= (aptr+1);	return(0);
		case	'd'	:	directory 	= (aptr+1);	return(0);
		case	'b'	:	preinstall	= (aptr+1);	return(0);
		case	'i'	:	install		= (aptr+1);	return(0);
		case	'a'	:	postinstall	= (aptr+1);	return(0);
		case	's'	:	source_package	= (aptr+1);	return(0);
		case	't'	:	target_package	= (aptr+1);	return(0);
		case	'z'	:	keeper=1;			return(0);
		case	'p'	:	physikal=1;			return(0);
		case	'g'	:	debug=1;			return(0);
		/* ------------------------------------------------------------- */
		/* these two allow protection management to be added to the pack */
		/* ------------------------------------------------------------- */
		case	'k'	:	productnumber = atoi((aptr+1));	return(0);
		case	'n'	:	productname   	= (aptr+1);	return(0);

		default		:	if ( verbose ) { 
						printf("incorrect option %s \n",aptr); 
						}
					return(30);
		}
}

int	banner()
{
	printf("\n   Abal Product Builder : Version 2.1a.0.01\n   Copyright (c) 2003,2007 Amenesik / Sologic \n\n");
	printf("Syntax : \n");
	printf("\tapb\t-ssource\n\t\t[-kproductcode]\n\t\t[-nproductname]\n\t\t-ccompiler\n\t\t-ttarget\n\t\t[-bpreinstall]\n\t\t-iinstall\n\t\t[-apostinstall]\n\t\t[ -p -g ]\n\t\t product \n\n");
	return(0);
}

int	main(int  argc, char * argv[] )
{
	int	argi;
	char *	aptr;
	int	status;
	if ( argc == 1 ) 
		return( banner() );
	else	{
		for ( argi=1; argi < argc; argi++ ) {
			if (!( aptr = argv[argi] ))
				break;
			else if ( *aptr == '-' ) {
				if (!(status = option( (aptr+1) ) ))
					continue;
				else	break;
				}
			else if (!(status = product_builder((product_name= aptr)) ))
				continue;
			else	break;
			}
		return( status );
		}
}


