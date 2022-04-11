#define	ABAL31D
#include <stdio.h>
#include <malloc.h>

#define	_LINBDA_DATE	"24/02/2022"

static  char	VersionStatus[16]= { 
	'V','E','R','S','I','O','N','_','S','T','A','T','U','S',':','2' 
	};

static	char 	LaPaterne[32] = { 
	'*','P','R','L','@','I','N','F','O','*','#',6,'2','1','a','0','0','3',0
	};

static	char *	bannerman=(char *) 0;
static	char *	cproduction=(char *) 0;
static	char *	targetname=(char *) 0;
static	char *  argvzero="LINBDA";
static	char *	LaPointeur=(char*)0;
static	char 	LaVersion[16];
static	char *	trace_define=(char *) 0;
static	int	minus_r=0;		/* Inhibits things by bit field */
					/* 1 : RT ERROR syntax 		*/

static	int	explicite_numbering=0;
static	int	comment_tabulator=0;
static	int	special=0;
static	int	verbose=0;
static	int	debug=0;
static	char *	htmlname=(char *) 0;
static	FILE *	htmlfile=(FILE *) 0;
static	char *	trace_name=(char*)0;
static	int	echo=0;
static	int	function_counter=0;
static	int	state_machine=0;
static	int	maxint=16;

static	char *	function_names[256];

/*	-----------------	*/
/*	getpatternversion	*/
/*	-----------------	*/
char *	getpatternversion()
{
	if (!( LaPointeur )) 
	{
		LaVersion[0] = LaPaterne[12];
		LaVersion[1] = '.';
		LaVersion[2] = LaPaterne[13];
		LaVersion[3] = LaPaterne[14];
		if ( VersionStatus[15] != '0' ) 
		{
			LaVersion[4] = '.';
			LaVersion[5] = LaPaterne[15];
			LaVersion[6] = '.';
			LaVersion[7] = LaPaterne[16];
			LaVersion[8] = LaPaterne[17];
			LaVersion[9] = 0;
		}
		else if ( LaPaterne[15] != '0' ) 
		{
			LaVersion[4] = '.';
			LaVersion[5] = LaPaterne[15];
			LaVersion[6] = 0;
		}
		else	LaVersion[4] = 0;

		LaPointeur = LaVersion;
	}
	return( LaPointeur );
}
#ifdef	ABAL31D
#include "linface.c"
#endif

/*	--------------------	*/
/*	generate_html_header	*/
/*	--------------------	*/
static	void	generate_html_header()
{
	if ( htmlname )
	{
		if ((htmlfile = fopen( htmlname, "w" )) != (FILE *) 0)
		{
			fprintf(htmlfile,"<html><head><title>abal dynamic library documentation</title>\n");
			fprintf(htmlfile,"<link href='style.css' rel='STYLESHEET' type='text/css' media='SCREEN'>\n");
			fprintf(htmlfile,"<link href='style.css' rel='STYLESHEET' type='text/css' media='PRINT'>\n");
			fprintf(htmlfile,"</head><body><div align=center>\n");
		}
	}
	return;
}

/*	-------------------------	*/
/*	 function_html_interface	*/
/*	-------------------------	*/
void	function_html_interface( char * nptr )
{
	int	p;
	char *	fptr;
	int	c;
	int	i;
	int	t;
	int	a=0;
	nptr = step_over( nptr, &i );
	fptr = step_past( nptr, &c );
	fprintf(htmlfile,"<tr><th>%s<tr><td><p><table>",nptr);
	*(fptr++) = c;
	while (1) 
	{
		p=0;
		fptr = notwhite(fptr);
		switch ((t =  *(fptr++))) 
		{
		case	'$'	:
		case	'*'	:
			p=1;
		case	'#'	:
		case	0x0025	:
		case	'.'	:
			fptr = notwhite(fptr);
			if ( *fptr == '?' ) 
			{
				fptr++;
				p=1;
			}				
			a++;
			switch ( t ) 
			{
			case	'#'	:
			case	':'	:
			case	'&'	:
			case	0x0025	:
				fprintf(htmlfile,"<tr><th>integer parameter<td>");
				break;
			case	'*'	:
			case	'$'	:
				fprintf(htmlfile,"<tr><th>string parameter<td>");
				break;
			}
			fprintf(htmlfile,"a%u",a);
			continue;
		case	','	:
			continue;
		case	')'	:
			break;
		default		:
			break;
		}
		break;
	}
	fprintf(htmlfile,"</table><p></th><tr>");
	return;
}

/*	----------------------	*/
/*	generate_html_function	*/
/*	----------------------	*/
static	void	generate_html_function(char * sptr)
{
	if ( htmlname )
	{
		if ( htmlfile )
		{
			fprintf(htmlfile,"<p><table border=\"1\" width=\"90%c\">\n",'%');
			function_html_interface( sptr );
			fprintf(htmlfile,"</table>\n");
		}
	}
	return;
}

/*	--------------------	*/
/*	generate_html_footer	*/
/*	--------------------	*/
static	void	generate_html_footer()
{
	if ( htmlname )
	{
		if ( htmlfile )
		{
			fprintf(htmlfile,"</div></body></html>\n");
			fclose( htmlfile );
			htmlfile = (FILE *) 0;
		}
	}
	return;
}

/*	------	*/
/*	banner 	*/
/*	------	*/
int	banner(char * cptr)
{
	printf("\n   ABAL Dynamic Library Interface Generator : Version %s ",getpatternversion());
	if ( VersionStatus[15] == '2' )
		printf("\n   Provisoire du %s ",_LINBDA_DATE );
	printf("\n   Copyright (c) 2922 Amenesik / Sologic \n");
	printf("\n   Syntax : \n");
	printf("\n          %s [ -vexdfilename ]  filename\n",cptr);
	printf("\n          -bstring    : module identification information");
	printf("\n          -cfilename  : generate c interface to library");
	printf("\n          -hfilename  : generate html skeleton for library");
	printf("\n          -v          : activate messages during conversion");
	printf("\n          -e          : echo source file to std output");
	printf("\n          -x          : variable parameter count functions");
	printf("\n          -i16|32|64  : max int 32, 64 or 16*");
	printf("\n          -x1         : avec inhibition de rt_error");
	printf("\n          -dname      : generate trace information");
	printf("\n          -rname      : indicate result filename\n\n");

	return(0);
}

/*	------	*/
/*	option	*/
/*	------	*/
int	option( char * sptr )
{
	while ( *sptr ) 
	{
		switch ( *(sptr++) ) 
		{
		case	'h'	:
		case	'H'	:
			htmlname = sptr;
			return(1);
		case	't'	:
		case	'T'	:
			trace_define = sptr;
			return(1);
		case	'r'	:
		case	'R'	:
			targetname = sptr;
			return(1);

		case	'D'	:
		case	'd'	:
			debug=1;
			if ( *sptr )
				trace_name = sptr;
			return(1);

		case	'I'	:
		case	'i'	:
			maxint = atoi(sptr);
			return(1);

		case	'X'	:
		case	'x'	:
			special = 1;
			if (( *sptr >= '0' ) && ( *sptr <= '9' ))
				minus_r = ( *(sptr++) - '0' );
			continue;
		case	'C'	:
		case	'c'	:
			cproduction=sptr;
			return(1);
		case	'B'	:
		case	'b'	:
			bannerman = sptr;
			return(1);

		case	'V'	:
		case	'v'	:
			verbose = 1;
			continue;
		case	'e'	:
		case	'E'	:
			echo = 1;
			continue;
			default		:
			printf("\n*** error:incorrect option %s ***\n",sptr);
			return(0);
		}
	}
	return(1);
}

char	namebuffer[512];
char	workbuffer[1024];
char	linebuffer[1024];
int	LinDex=0;

/*	----------------	*/
/*	generate_comment	*/
/*	----------------	*/
void	generate_comment( FILE * target, char * message ) 
{ 
	int	i;
	for ( i=0; i < comment_tabulator; i++ )
		fprintf(target,"\t");

	fprintf(target,"/* %s */\n",message);
	return;
}

/*	-----------------	*/
/*	 generate_header	*/
/*	-----------------	*/
void	generate_header( FILE * target, char * namestub )
{
	int	i;
	char	workstub[256];
	state_machine=0;
	sprintf(workbuffer,"File generated by %s Version %s : %s.def -> %s.c",argvzero,getpatternversion(),namestub,namestub);
	generate_comment( target, workbuffer );
	for (i=0; *(namestub+i) != 0; i++ ) 
	{
		switch ((workstub[i] = *(namestub+i))) 
		{
		case	'/'	:
		case	'.'	:
			workstub[i] = '_';
		default		:
			continue;
		}
	}
	workstub[i] = 0;
	namestub = workstub;
	fprintf(target,"#ifndef __linbda_%s_c__\n",namestub);
	fprintf(target,"#define __linbda_%s_c__\n",namestub);

	if (!( minus_r  & 1 )) 
	{
		fprintf(target,"#include <stdio.h>\n");
		fprintf(target,"#include <setjmp.h>\n");
	}
	else if ( debug ) 
		fprintf(target,"#include <stdio.h>\n");

	fprintf(target,"#include %cldfbda.h%c\n",0x022,0x022);

	fprintf(target,"\nprivate BDA * DynamicLibrary;\n");
	fprintf(target,"\tpublic  LPBDA_INIT\trt_init;\n");
	fprintf(target,"\tpublic  BDA_INIT\tv_rt_init;\n");

	fprintf(target,"\tpublic  BDA_ARG rt_arg;\n\n");

	if (!( minus_r  & 1 )) 
	{
		generate_comment(target,"ABAL Runtime Error Trap");
		fprintf(target,"private	jmp_buf rt_error_context;\n");
		fprintf(target,"public  VOID rt_error(EXAWORD evalue) { \n");
		fprintf(target,"\tlongjmp(rt_error_context,evalue);\n");
		fprintf(target,"\treturn;\n}\n");
	}

	fprintf(target,"\nprivate int function_counter=%u;\n",(function_counter=0));

	generate_comment(target,"ABAL Word Conversions");

	fprintf(target,"public EXAWORD GetAbalInt8(char FAR PTR bptr)\n");
	fprintf(target,"{\n");
	fprintf(target,"\treturn(*bptr);\n");
	fprintf(target,"}\n\n");

	fprintf(target,"public EXAWORD GetAbalInt16(BYTE FAR PTR wptr)\n");
	fprintf(target,"{\n");
	fprintf(target,"\treturn(((*wptr<< 8)|*(wptr+1)));\n");
	fprintf(target,"}\n\n");

	fprintf(target,"public EXAWORD GetAbalInt32(BYTE FAR PTR wptr)\n");
	fprintf(target,"{\n");
	fprintf(target,"\tint length=4;\n");
	fprintf(target,"\tEXAWORD result=0;\n");
	fprintf(target,"\twhile ( length-- ) result = ((result << 8) | (*(wptr++) & 0x00FF));\n");
	fprintf(target,"\treturn(result);\n");
	fprintf(target,"}\n\n");

	fprintf(target,"public EXAWORD GetAbalInt64(BYTE FAR PTR wptr)\n");
	fprintf(target,"{\n");
	fprintf(target,"\tint length=8;\n");
	fprintf(target,"\tEXAWORD result=0;\n");
	fprintf(target,"\twhile ( length-- ) result = ((result << 8) | (*(wptr++) & 0x00FF));\n");
	fprintf(target,"\treturn(result);\n");
	fprintf(target,"}\n\n");


	fprintf(target,"public void PutAbalInt8(char FAR * wptr, EXAWORD v)\n");
	fprintf(target,"{\n\t*wptr = (v & 0x00FF);\n\treturn;\n}\n");

	fprintf(target,"public void PutAbalInt16(BYTE FAR * wptr, EXAWORD v)\n");
	fprintf(target,"{\n");
	fprintf(target,"\tint length=2;\n");
	fprintf(target,"\twhile ( length-- ) { *(wptr +length) = (v & 0x00FF); v >>= 8; }\n");
	fprintf(target,"\treturn;\n");
	fprintf(target,"}\n\n");

	fprintf(target,"public void PutAbalInt32(BYTE FAR * wptr, EXAWORD v)\n");
	fprintf(target,"{\n");
	fprintf(target,"\tint length=4;\n");
	fprintf(target,"\twhile ( length-- ) { *(wptr +length) = (v & 0x00FF); v >>= 8; }\n");
	fprintf(target,"\treturn;\n");
	fprintf(target,"}\n\n");

	fprintf(target,"public void PutAbalInt64(BYTE FAR * wptr, EXAWORD v)\n");
	fprintf(target,"{\n");
	fprintf(target,"\tint length=8;\n");
	fprintf(target,"\twhile ( length-- ) { *(wptr +length) = (v & 0x00FF); v >>= 8; }\n");
	fprintf(target,"\treturn;\n");
	fprintf(target,"}\n\n");


	fprintf(target,"#define LdfParaWord(n) (tptr[n]==1 ? GetAbalInt16(pptr[n]) : (tptr[n]==0 ? GetAbalInt8(pptr[n]) : (tptr[n]==5 ? GetAbalInt32(pptr[n]): GetAbalInt64(pptr[n]) )))\n");
	fprintf(target,"#define LdfParaByte(n) (tptr[n]==1 ? (GetAbalInt16(pptr[n])&0x00FF) : (tptr[n]==0 ? GetAbalInt8(pptr[n]):(tptr[n]==5?(GetAbalInt32(pptr[n])&0x00FF):(GetAbalInt64(pptr[n])&0x00FF))))\n");
	if ( debug ) 
	{

		fprintf(target,"\nprivate BYTE PTR function_names[256];\n");
		fprintf(target,"private char * trace_name=(char*)0;\n");
		fprintf(target,"private FILE * trace_handle=(FILE*)0;\n");
		fprintf(target,"extern long time(long*);\n\n");

		generate_comment(target,"Trace Activation");
		fprintf(target,"private void start_trace()\n");
		fprintf(target,"{\n");
		if (( trace_name != (char *) 0 )
		&&  (*trace_name != 0 ))
			fprintf(target,"\ttrace_name = %c%s%c;\n",0x0022,trace_name,0x0022);
		else	fprintf(target,"\ttrace_name = getenv(%c%s%c);\n",0x0022,(trace_define != (char *) 0 ? trace_define : "LINBDA_OUTPUT"),0x0022);
		fprintf(target,"\tif ( trace_name != (char *) 0 ) {\n");
		fprintf(target,"\t\ttrace_handle=fopen(trace_name,%cw%c);\n",0x0022,0x0022);
		fprintf(target,"\t\t}\n");
		fprintf(target,"\treturn;\n");
		fprintf(target,"}\n\n");

		generate_comment(target,"Trace Write");
		fprintf(target,"private void write_trace(char * mptr)\n");
		fprintf(target,"{\n\tif ( trace_handle != (FILE*)0) {\n");
		fprintf(target,"\t\tfprintf(trace_handle,mptr);\n");
		fprintf(target,"\t\tfprintf(trace_handle,%c%cr%cn%c);\n",0x0022,0x005C,0x005C,0x0022);
		fprintf(target,"\t\t}\n\treturn;\n");
		fprintf(target,"}\n\n");

		generate_comment(target,"Trace Result");
		fprintf(target,"private void trace_result(EXAWORD result)\n");
		fprintf(target,"{\n\tif ( trace_handle != (FILE*)0) {\n");
		fprintf(target,"\t\tfprintf(trace_handle,%cRETURN: %cu %cr%cn%c,result);\n",0x0022,0x0025,0x005C,0x005C,0x0022);
		fprintf(target,"\t\t}\n\treturn;\n");
		fprintf(target,"}\n\n");

		generate_comment(target,"Trace Call");
		fprintf(target,"private void trace_call(\n\tEXAWORD fid,\n\tEXAWORD argc,\n\tBYTE FAR tptr[],\n\tVOID FAR PTR FAR pptr[],\n\tEXAWORD FAR wptr[])\n");
		fprintf(target,"{\n\tchar * bptr;\n\tint\ti=0;\n\tint\tj=0;\n\tif ( trace_handle != (FILE*)0) {\n");
		fprintf(target,"\t\t\tfprintf(trace_handle,");
		fprintf(target,"%c[%clu] %c,time((long*)0));\n",
				0x0022, 0x0025, 0x0022);
		fprintf(target,"\t\tif ( function_names[fid] != (char *) 0) {\n");
			fprintf(target,"\t\t\tfprintf(trace_handle,");
			fprintf(target,"%c(%cs)%c,function_names[fid]);\n",
					0x0022, 0x0025, 0x0022);
		fprintf(target,"\t\t\t}\n\t\telse\t{\n");
			fprintf(target,"\t\t\tfprintf(trace_handle,");
			fprintf(target,"%c(call %cu)%c,fid);\n",
					0x0022, 0x0025, 0x0022);
		fprintf(target,"\t\t\t}\n");

		fprintf(target,"\t\tfor (i=0; i < argc; i++) {\n");
		fprintf(target,"\t\t\tswitch(tptr[i]) {\n");
		fprintf(target,"\t\t\t\tcase 0x0080 : \n");
		fprintf(target,"\t\t\t\t\tfprintf(trace_handle,%c%ct(*b=%cx)%cr%cn%c,*((bptr=pptr[i])));\n",
				0x0022,0x005C,0x0025,0x005C,0x005C,0x0022);
		fprintf(target,"\t\t\t\t\tbreak;\n");
		fprintf(target,"\t\t\t\tcase 0  : \n");
		fprintf(target,"\t\t\t\t\tfprintf(trace_handle,%c%ct(b=%cx)%cr%cn%c,*((bptr=pptr[i])));\n",
				0x0022,0x005C,0x0025,0x005C,0x005C,0x0022);
		fprintf(target,"\t\t\t\t\tbreak;\n");
		fprintf(target,"\t\t\t\tcase 0x0081 : \n");
		fprintf(target,"\t\t\t\t\tfprintf(trace_handle,%c%ct(*w=%cx)%cr%cn%c,GetAbalInt16(pptr[i]));\n",
				0x0022,0x005C,0x0025,0x005C,0x005C,0x0022);
		fprintf(target,"\t\t\t\t\tbreak;\n");
		fprintf(target,"\t\t\t\tcase 1  : \n");
		fprintf(target,"\t\t\t\t\tfprintf(trace_handle,%c%ct(w=%cx)%cr%cn%c,GetAbalInt16(pptr[i]));\n",
				0x0022,0x005C,0x0025,0x005C,0x005C,0x0022);
		fprintf(target,"\t\t\t\t\tbreak;\n");
		fprintf(target,"\t\t\t\tcase 0x0085 : \n");
		fprintf(target,"\t\t\t\t\tfprintf(trace_handle,%c%ct(*w=%cx)%cr%cn%c,GetAbalInt32(pptr[i]));\n",
				0x0022,0x005C,0x0025,0x005C,0x005C,0x0022);
		fprintf(target,"\t\t\t\t\tbreak;\n");
		fprintf(target,"\t\t\t\tcase 5  : \n");
		fprintf(target,"\t\t\t\t\tfprintf(trace_handle,%c%ct(w=%cx)%cr%cn%c,GetAbalInt32(pptr[i]));\n",
				0x0022,0x005C,0x0025,0x005C,0x005C,0x0022);
		fprintf(target,"\t\t\t\t\tbreak;\n");
		fprintf(target,"\t\t\t\tcase 0x0086 : \n");
		fprintf(target,"\t\t\t\t\tfprintf(trace_handle,%c%ct(*w=%cx)%cr%cn%c,GetAbalInt64(pptr[i]));\n",
				0x0022,0x005C,0x0025,0x005C,0x005C,0x0022);
		fprintf(target,"\t\t\t\t\tbreak;\n");
		fprintf(target,"\t\t\t\tcase 6  : \n");
		fprintf(target,"\t\t\t\t\tfprintf(trace_handle,%c%ct(w=%cx)%cr%cn%c,GetAbalInt64(pptr[i]));\n",
				0x0022,0x005C,0x0025,0x005C,0x005C,0x0022);
		fprintf(target,"\t\t\t\t\tbreak;\n");
		fprintf(target,"\t\t\t\tcase 2  : \n");
		fprintf(target,"\t\t\t\tcase 3  : \n");
		fprintf(target,"\t\t\t\tcase 0x0082 : \n");
		fprintf(target,"\t\t\t\tcase 0x0083 : \n");

		fprintf(target,"\t\t\t\t\tfprintf(trace_handle,%c%ct(*=%c);\n",
				0x0022,0x005C,0x0022);
		fprintf(target,"\t\t\t\t\tfor (bptr=pptr[i],j=0;j<wptr[i];j++) {\n");
		fprintf(target,"\t\t\t\t\t\tfprintf(trace_handle,%c%cx %c,(*(bptr+j)&0x00FF));\n",
				0x0022,0x0025,0x0022);
		fprintf(target,"\t\t\t\t\t\tif ((j %c 20) == 19) {\n",'%');
		fprintf(target,"\t\t\t\t\t\t\tfprintf(trace_handle,%c%cr%cn%c);\n",
				0x0022,0x005C,0x005C,0x0022);

		fprintf(target,"\t\t\t\t\t\t\t}\n");
		fprintf(target,"\t\t\t\t\t\t}\n");
		fprintf(target,"\t\t\t\t\tfprintf(trace_handle,%c)%cr%cn%c);\n",0x0022,0x005C,0x005C,0x0022);

		fprintf(target,"\t\t\t\t};\n");
		fprintf(target,"\t\t\t}\n");
		fprintf(target,"\t\tfprintf(trace_handle,%c%cr%cn%c);\n",0x0022,0x005C,0x005C,0x0022);
		fprintf(target,"\t\t}\n\treturn;\n");
		fprintf(target,"}\n\n");

		generate_comment(target,"Trace Closure");
		fprintf(target,"private void close_trace()\n");
		fprintf(target,"{\n\tif ( trace_handle != (FILE*)0) {\n");
		fprintf(target,"\t\tfclose(trace_handle);\n");
		fprintf(target,"\t\ttrace_handle=(FILE*)0;\n");
		fprintf(target,"\t\t}\n\treturn;\n");
		fprintf(target,"}\n\n");
	}

	generate_comment(target,"Library Information");
	fprintf(target,"public EXAWORD LdfBdaInformation(void * vptr)\n");
	fprintf(target,"{\n");
	fprintf(target,"\tprintf(\n");
	if (!( bannerman ))
		bannerman = "unspecified";
	fprintf(target,"\t\t%c%cn   Abal Dynamic Library : %s%c\n",0x0022,0x005C,bannerman,0x0022);
	fprintf(target,"\t\t);\n");
	fprintf(target,"\tprintf(\n");
	fprintf(target,"\t\t%c%cn   Copyright (c) Amenesik / Sologic %cn%cn%c\n",0x0022,0x005C,0x005C,0x005C,0x0022);
	fprintf(target,"\t\t);\n");
	fprintf(target,"\treturn(0);\n");
	fprintf(target,"}\n\n");

	generate_comment(target,"Library Destructor");
	fprintf(target,"public EXAWORD LdfBdaTerminate()\n");
	fprintf(target,"{\n");

	if ( debug ) 
	{
		fprintf(target,"\twrite_trace(%cLdfBdaTerminate()%c);\n",0x0022,0x0022);
		fprintf(target,"\tclose_trace();\n");
	}

	fprintf(target,"\tif (DynamicLibrary->fin != (VOID (FAR PTR)()) 0)\n");
	fprintf(target,"\t\t (*DynamicLibrary->fin)();\n");
	fprintf(target,"\treturn(0);\n");
	fprintf(target,"}\n\n");

	generate_comment(target,"Library Call Through");
	fprintf(target,"public EXAWORD LdfBdaExecute(\n\tEXAWORD fid,\n\tEXAWORD argc,\n\tBYTE FAR tptr[],\n\tVOID FAR PTR FAR pptr[],\n\tEXAWORD FAR wptr[],\n\tint FAR * eptr)\n");
	fprintf(target,"{\n");
	fprintf(target,"\tEXAWORD\tresult=0;\n");

	fprintf(target,"\trt_arg.c=argc; rt_arg.v=pptr;\n");
	fprintf(target,"\trt_arg.l=wptr; rt_arg.t=tptr;\n");

	if (!( minus_r  & 1 )) 
	{
		fprintf(target,"\tif ((result=setjmp(rt_error_context))!=0) {\n");
		fprintf(target,"\t\tif ( eptr != (int FAR *) 0) *eptr = result;\n");
		fprintf(target,"\t\treturn( result );\n\t\t}\n");
	}
	
	if ( debug )  
	{
		fprintf(target,"\tif ( trace_handle != (FILE*)0) {\n");
		fprintf(target,"\ttrace_call(fid,argc,tptr,pptr,wptr);\n");
		fprintf(target,"\t\t}\n");
	}
	comment_tabulator=1;

}

/*	-----------------	*/
/*	 generate_footer	*/
/*	-----------------	*/
void	generate_footer( FILE * target, char * namestub )
{
	int	i;
	char	workstub[256];
	if ( debug )  
	{
		fprintf(target,"\tif ( trace_handle != (FILE*)0) {\n");
		fprintf(target,"\t\ttrace_result( result );\n");
		fprintf(target,"\ttrace_call(fid,argc,tptr,pptr,wptr);\n");
		fprintf(target,"\t\t}\n");
	}

	fprintf(target,"\treturn(result);\n");
	fprintf(target,"}\n\n");
	comment_tabulator = 0;

	generate_comment(target,"Library Constructor");
	fprintf(target,"\npublic EXAWORD LdfBdaInitialise(\n\tBDA_INIT FAR PTR descriptor,\n\tEXAWORD dlength)\n");
	fprintf(target,"{\n\tint	i=0;\n\trt_init = descriptor;\n");
	fprintf(target,"\tfunction_counter=%u;\n",function_counter);
	
	if ( debug ) 
	{
		for (i=0; i < function_counter; i++ ) 
		{
			if (!( function_names[i] ))	
				fprintf(target,"\tfunction_names[%u] = (char*)0;\n",i);
			else	fprintf(target,"\tfunction_names[%u] = %c%s%c;\n",i,0x0022,function_names[i],0x0022);
		}
		fprintf(target,"\tstart_trace();\n");
		fprintf(target,"\twrite_trace(%cLdfBdaInitialise()%c);\n",0x0022,0x0022);
	}

	fprintf(target,"\tif (!(DynamicLibrary = InitRelais()))\n");
	fprintf(target,"\t\treturn(139);\n");
	fprintf(target,"\telse\treturn(0);\n");

	fprintf(target,"}\n\n");

	for (i=0; *(namestub+i) != 0; i++ ) 
	{
		switch ((workstub[i] = *(namestub+i))) 
		{
		case	'/'	:
		case	'.'	:
			workstub[i] = '_';
		default		:
			continue;
		}
	}
	workstub[i] = 0;
	namestub = workstub;
	fprintf(target,"#endif  /* __linbda_%s_c__ */\n",namestub);
	generate_comment( target, "End of File");
	return;
}

/*	--------	*/
/*	get_line	*/
/*	--------	*/
int	get_line( FILE * handle )
{
	int	lindent=0;
	int	c;
	while (1) 
	{
		switch ((c = fgetc(handle))) 
		{
		case	0	:
		case	-1	:
		case	0x001A	:
			linebuffer[lindent] = 0;
			if ( lindent ) 
			{
				if ( echo )
					printf("%s\n",linebuffer);
			}
			return( lindent );
		case	';'	:
			while((c = fgetc(handle)) != '\n') 
			{
				switch(c) 
				{
				case	0	:
				case	-1	:
				case	0x001A	:
					if ( lindent ) 
					{
						linebuffer[lindent] = 0;
						if ( echo )
							printf("%s\n",linebuffer);
						return( lindent );
					}
					else	return(0);
				}
			}

		case	'\n'	:
			if ( lindent ) 
			{
				linebuffer[lindent] = 0;
				if ( echo )
					printf("%s\n",linebuffer);
				return( lindent );
			}
		case	'\r'	:
			continue;

		case	'\t'	:
			c = ' ';
		default		:
			if ( lindent < 1023 ) 
			{
				if (( c != ' ' )
				||  (lindent != 0))
					linebuffer[lindent++] = c;
				continue;
			}
			else	return(0);
		}
	}
}

/*	------	*/
/*	detect	*/
/*	------	*/
int	detect( char * sptr )
{
	int	i=0;
	while ( *(sptr+i) ) 
	{
		if ( *(sptr+i) != (linebuffer[i] & 0x005F))
			return(0);
		else	i++;
	}
	return(1);
}

/*	--------------	*/
/*	next_parameter	*/
/*	--------------	*/
int	next_parameter()
{
	int	apt=0;
	while ( linebuffer[LinDex] == ' ' )
		LinDex++;

	switch ( linebuffer[LinDex++] ) 
	{
	case	')'	:
		return(-1);
	case	':'	:	/* LONG */
		apt = 5;
		break;
	case	'&'	:	/* HUGE */
		apt = 6;
		break;
	case	'$'	:	/* STRING */
		apt = 3;
		break;
	case	'#'	:	/* INT  8 */
		apt = 0;
		break;
	case	'*'	:	/* BCD ?? */
		apt = 2;
		break;
	case	0x0025	:	/* INT 16 */
		apt = 1;
		break;
	default		:
		return(-1);
	}

	while ( linebuffer[LinDex] == ' ' )
		LinDex++;

	if ( linebuffer[LinDex] == '?' ) 
	{
		LinDex++;
		apt |= 0x0080;
	}

	while ( linebuffer[LinDex] == ' ' )
		LinDex++;

	if ( linebuffer[LinDex] == ',' ) 
	{
		LinDex++;
		apt |= 16;
	}

	else if ( linebuffer[LinDex] != ')' ) 
	{
		return( -1 );
	}

	return(apt);

}

/*	-------------	*/
/*	get_explicite	*/
/*	-------------	*/
int	get_explicite()
{
	int	result=0;
	LinDex = 0;
	while ( linebuffer[LinDex] == ' ' )
		LinDex++;
	while (1) 
	{
		if ((linebuffer[LinDex] >= '0')
		&&  (linebuffer[LinDex] <= '9'))
			result = ((result * 10) + (linebuffer[LinDex++] - '0'));
		else	break;
	}
	if ( linebuffer[LinDex] = ':' )
		LinDex++;
	while ( linebuffer[LinDex] == ' ' )
		LinDex++;
	return(result);
}

/*	-----------------	*/
/*	 first_parameter	*/
/*	-----------------	*/
int	first_parameter()
{
	int	apt=-1;

	if (!( explicite_numbering ))
		LinDex = 0;

	while ( linebuffer[LinDex] == ' ' )
		LinDex++;

	switch ( linebuffer[LinDex] ) 
	{
	case	'$'	:
		apt=3;
		break;
	case	'*'	:
		apt = 2;
		break;
	default		:
		apt = -1;
	}

	for (LinDex=0; linebuffer[LinDex] != 0; LinDex++ ) 
	{
		if ( linebuffer[LinDex] == '(' ) 
		{
			LinDex++;
			if ( apt != -1 ) 
			{
				while ( linebuffer[LinDex] == ' ' )
					LinDex++;
				if ( linebuffer[LinDex] != ')' )
					apt |= 16;
				return(apt);
			}
			else	return( next_parameter() );
		}
	}
	return(-1);
}

/*	-------------	*/
/*	generate_int8	*/
/*	-------------	*/
void	generate_int8( FILE * handle, int item )
{
	fprintf(handle,"\n\t\t\t\tLdfParaByte(%u)",item);
	return;
}

/*	--------------	*/
/*	generate_int16	*/
/*	--------------	*/
void	generate_int16( FILE * handle, int item )
{
	fprintf(handle,"\n\t\t\t\tLdfParaWord(%u)",item);
	return;
}

/*	--------------	*/
/*	generate_int32	*/
/*	--------------	*/
void	generate_int32( FILE * handle, int item )
{
	fprintf(handle,"\n\t\t\t\tLdfParaLong(%u)",item);
	return;
}

/*	--------------	*/
/*	generate_int64	*/
/*	--------------	*/
void	generate_int64( FILE * handle, int item )
{
	fprintf(handle,"\n\t\t\t\tLdfParaHuge(%u)",item);
	return;
}

/*	------------	*/
/*	generate_ptr	*/
/*	------------	*/
void	generate_ptr( FILE * handle, int item )
{
	fprintf(handle,"\n\t\t\t\tpptr[%u]",item);
	return;
}

/*	----------	*/
/*	detect_num	*/
/*	----------	*/
void	detect_num()
{
	int	i;
	char *	lptr=linebuffer;
	explicite_numbering = 0;
	for (lptr=linebuffer; *lptr != 0; lptr++ )
		if ( *lptr == ',' )
			break;
	if (!( *lptr ))
		return;
	lptr++;
	while ( *lptr == ' ' )
		lptr++;

	if ((*lptr != 'n' )
	&& (*lptr != 'N' ))
		return;
	if ((*(lptr+1) != 'u' )
	&& (*(lptr+1) != 'U' ))
		return;
	if ((*(lptr+2) != 'm' )
	&& (*(lptr+2) != 'M' ))
		return;
	explicite_numbering = 1;

}

/*	---------------------	*/
/*	collect_function_name	*/
/*	---------------------	*/
static	void	collect_function_name( char * lptr, int item )
{
	if ( function_names[item] != (char *) 0)
		free( function_names[item] );

	if ((function_names[item] = malloc( strlen( lptr ) + 16)) != (char *) 0) {
		strcpy(function_names[item],lptr);
#ifdef	ABAL31D
		if ( cproduction )
			function_linterface( function_names[item] );
#endif
		}
	return;
}

/*	--------	*/
/*	put_line	*/
/*	--------	*/
int	put_line( FILE * handle )
{
	int	apt=0;
	int	rtp=0;
	int	function_number=0;
	switch ( state_machine ) 
	{
	case	0 :	/* Looking for Version */

		generate_comment( handle, linebuffer );
		if ( detect( "VERSION" ) ) 
		{
			state_machine++;
			detect_num();
			if ( explicite_numbering )
				generate_comment(handle,"Explicite Numbering");
		}
		return( state_machine );

	case	1 :	/* Looking for Runtime */

		generate_comment( handle, linebuffer );
		if ( detect( "RUNTIME" ) )
			state_machine++;
		return( state_machine );

	case	2 :	/* Looking for End     */

		if ( detect( "END" ) ) 
		{
			if ( special ) 
			{
				fprintf(handle,"\tif (fid > function_counter) result=138; else result=(*DynamicLibrary->fonction[fid])(pptr);\n");
			}
			else if (function_counter) 
			{
				fprintf(handle,"\t\tdefault\t: result=138;\n\t\tbreak;\n\t\t}\n");
				comment_tabulator=1;
			}
			generate_comment( handle, linebuffer );
			state_machine=0;
		}
		else if ( special ) 
		{
			generate_comment( handle, linebuffer );
			if ( explicite_numbering ) 
			{
				if ((function_number = get_explicite()) > function_counter)
					function_counter = function_number;
				collect_function_name( linebuffer,function_number );
			}
			else	
			{
				collect_function_name( linebuffer,function_counter );
				function_counter++;
			}
		}
		else	
		{
			/* ------------------------- */
			/* Generate switch if needed */
			/* ------------------------- */
			if (!( function_counter )) 
			{
				fprintf(handle,"\tswitch ( fid ) {\n");
				comment_tabulator=0;
			}

			/* -------------------------------------- */
			/* Detect and Collect Explicite Numbering */
			/* -------------------------------------- */
			if ( explicite_numbering ) 
			{
				if ((function_number = get_explicite()) > function_counter)
					function_counter = function_number;
			}
			else	function_number = function_counter;

			collect_function_name( linebuffer,function_number );

			fprintf(handle,"\t\tcase\t%u : ",function_number);
			generate_comment( handle, linebuffer );
			fprintf(handle,"\t\t\tresult=(*DynamicLibrary->fonction[%u])(",function_number);
			for (	rtp=0,apt=first_parameter();
				apt != -1;
				apt=next_parameter(),rtp++ ) 
			{
				if ( rtp ) 
					fprintf(handle,",");

				switch ( (apt & 0x008F) ) 
				{
				case	0 :
					generate_int8(handle,rtp);
					break;
				case	1 :
					generate_int16(handle,rtp);
					break;
				case	5:
					if ( maxint > 16 )
						generate_int32(handle,rtp);
					else	generate_int16(handle,rtp);
					break;
				case	6:
					if ( maxint < 32 )
						generate_int16(handle,rtp);
					else if ( maxint < 64 )
						generate_int32(handle,rtp);
					else	generate_int64(handle,rtp);
					break;
				case 0x0080 :
				case 0x0081 :
				case 0x0085 :
				case 0x0086 :
				case	2 :
				case 0x0082 :
				case	3 :
				case 0x0083 :
					generate_ptr(handle,rtp);
					break;
				}
			}
			fprintf(handle,"); break;\n");
			/* Post increment the function counter */
			if (!( explicite_numbering ))
				function_counter++;

		}
		return( state_machine );
	}
	return(0);
}

/*	----------	*/
/*	initialise	*/
/*	----------	*/
void	initialise()
{
	int	i;
	for (i=0; i < 256; i++)
		function_names[i] = (char *) 0;
	return;
}

/*	---------	*/
/*	terminate	*/
/*	---------	*/
void	terminate()
{
	int	i;
	for (i=0; i < 256; i++) 
	{
		if (!( function_names[i] ))
			continue;
		else	free( function_names[i] );
	}
	initialise();
	return;
}

/*	---------	*/
/*	 convert	*/
/*	---------	*/
int	convert( char * filename )
{
	int	i;
	FILE *	shandle;
	FILE *	thandle;
	
	initialise();

	strcpy( namebuffer, filename );
	strcat( namebuffer, ".def" );

	if (( shandle = fopen( namebuffer,"r" )) != (FILE *) 0) 
	{

		if ( verbose )
			printf("source file : %s \n",namebuffer);

		if (!( targetname )) 
		{
			strcpy( namebuffer, filename );
			strcat( namebuffer, ".c" );
		}
		else	
		{
			strcpy( namebuffer, targetname );
			strcat( namebuffer, ".c" );
		}

		if (( thandle = fopen( namebuffer,"w" )) != (FILE *) 0) 
		{
			if ( verbose )
				printf("target file : %s \n",namebuffer);

			generate_header( thandle, filename );

#ifdef	ABAL31D
			if ( cproduction )
				(void)open_linterface( cproduction, special );
#endif

			while ( get_line( shandle ) )
				if (!(put_line( thandle )))
					break;

			generate_footer( thandle, filename );

			generate_html_header();
			for (i=0; i <= function_counter; i++ )
				if ( function_names[i] )
					generate_html_function( function_names[i] );
			generate_html_footer();

#ifdef	ABAL31D
			if ( cproduction ) 
			{
				(void)flush_linterface();
				for (i=0; i <= function_counter; i++ )
					if ( function_names[i] )
						table_linterface( function_names[i] );
				(void)close_linterface();
			}
#endif
			fclose( thandle );
			fclose( shandle );
			terminate();
			return( 1 );

		}
		else	
		{
			fclose(shandle);
			printf("\n*** error creating : %s ***\n",namebuffer);
			terminate();
			return(0);
		}
	}
	else	
	{
		printf("\n*** error opening : %s ***\n",namebuffer);
		return(0);
	}
}

/*	---------	*/
/*	operation	*/
/*	---------	*/
int	operation( int argc, char * argv[] )
{
	int	argi;
	int	status;
	char *	aptr;
	argvzero = argv[0];
	for ( argi=1; argi < argc; argi++ ) 
	{
		if (!( aptr = argv[argi] ))
			break;

		else  if ( *aptr == '-' ) 
		{
			if (!( option( (aptr+1) )))
				break;
			else	continue;
		}
		else	
		{
			if (!( convert( aptr ) ))
				break;
			else	continue;
		}			
	}
	return(0);
}

/*	----	*/
/*	main	*/
/*	----	*/
int	main( int argc, char * argv[] )
{

	if ( argc == 1 )
		return(banner(argv[0]));
	else	return(operation(argc,argv));
}

