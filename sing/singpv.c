#ifndef	_gdtpv_c
#define	_gdtpv_c

#ifdef	ABAL32A
#define	_GDT_DATE	"25/07/2011"
#define	_GDT_DATE	"16/09/2014"
#else
#define	_GDT_DATE	"25/07/2011"
#define	_GDT_DATE	"16/09/2014"
#endif

private  char	VersionStatus[16]=
	{ 'V','E','R','S','I','O','N','_','S','T','A','T','U','S',':','2' };

#ifdef	NEWSING
public 	char 	LaPaterne[20] = { '*','P','R','L','@','I','N','F','O','*','#',6,'4','1','a','0','0','1',0 };
public 	char 	StringPaterne[20] = { '*','P','R','L','@','I','N','F','O','*','$','6','4','1','a','0','0','1',0 };
#else
#ifdef	ABALCPP 
public 	char 	LaPaterne[20] = { '*','P','R','L','@','I','N','F','O','*','#',6,'3','1','a','0','0','1',0 };
public 	char 	StringPaterne[20] = { '*','P','R','L','@','I','N','F','O','*','$','6','3','1','a','0','0','2',0 };
#else
#ifdef	ABAL32A
public 	char 	LaPaterne[20] = { '*','P','R','L','@','I','N','F','O','*','#',6,'3','1','a','0','0','1',0 };
public 	char 	StringPaterne[20] = { '*','P','R','L','@','I','N','F','O','*','$','6','3','1','a','0','0','2',0 };
#else
public 	char 	LaPaterne[20] = { '*','P','R','L','@','I','N','F','O','*','#',6,'1','1','e','0','4','0',0 };
public 	char 	StringPaterne[20] = { '*','P','R','L','@','I','N','F','O','*','$','6','1','1','e','0','4','0',0 };
#endif
#endif
#endif

private	char *	LaPointeur=(char*)0;
private	char 	LaVersion[10];
private	char *	Provisoire="\n   Provisoire du %s ";

private	char 	VersionBuffer[256];

public  char *	getpatternversion()
{
	if (!( LaPointeur )) {
		LaVersion[0] = LaPaterne[12];
		LaVersion[1] = '.';
		LaVersion[2] = LaPaterne[13];
		LaVersion[3] = LaPaterne[14];
		if ( VersionStatus[15] > '0' ) {
			LaVersion[4] = '.';
			LaVersion[5] = LaPaterne[15];
			LaVersion[6] = '.';
			LaVersion[7] = LaPaterne[16];
			LaVersion[8] = LaPaterne[17];
			LaVersion[9] = 0;
			}
		else if ( LaPaterne[15] > '0' ) {
			LaVersion[4] = '.';
			LaVersion[5] = LaPaterne[15];
			LaVersion[6] = 0;
			}
		else	LaVersion[4] = 0;
		LaPointeur = LaVersion;
		}
	return( LaPointeur );

}

public	char *	sing_version()
{
	sprintf(VersionBuffer,"version %s",getpatternversion());
	return( VersionBuffer );
}

public	char *	GetWindowVersion()
{
	sprintf(VersionBuffer,"Sing Version %c.%c%c",LaPaterne[12],LaPaterne[13],LaPaterne[14]);
	return( VersionBuffer );
}

private	int	banner()
{
#ifdef WIN32
	
	static char bufVer[512];
	static char bufMsg[1024];
	int iVer = 0;
	int iMsg = 0;

	iVer += sprintf(&bufVer[iVer],"\n   Graphical Design Tool : Version %s ",getpatternversion());
	if ( VersionStatus[15] == '2' )
		iVer += sprintf(&bufVer[iVer],Provisoire,_GDT_DATE);
	iVer += sprintf(&bufVer[iVer],"\n   Copyright (c) 2001,2014 IJM ");

	iMsg += sprintf(&bufMsg[iMsg],"\n   Syntax : \t sing [ options parameters ] \n");
	iMsg += sprintf(&bufMsg[iMsg],"\n          -i config@host         : inject configuration as host configuration entry ");
	iMsg += sprintf(&bufMsg[iMsg],"\n          -c modelname           : perform complete model production ");
	iMsg += sprintf(&bufMsg[iMsg],"\n          -lconfigname           : load specified default configuration ");
	iMsg += sprintf(&bufMsg[iMsg],"\n          -x modelname           : convert model to xml ressource \n\n");

	SingAboutBox(bufVer,bufMsg);

#else

	printf("\n   Graphical Design Tool : Version %s ",getpatternversion());

	if ( VersionStatus[15] == '2' )
		printf(Provisoire,_GDT_DATE);

	printf("\n   Copyright (c) 2001,2014 IJM \n");
	printf("\n   Production : ABAL/ABAL++/C/PHP/BiFS/LASeR/Widget \n");
	printf("\n   Syntax : \t sing [ options parameters ] \n");
	printf("\n          -i config@host         : inject configuration as host configuration entry ");
	printf("\n          -c modelname           : perform complete model production ");
	printf("\n          -lconfigname           : load specified default configuration ");
	printf("\n          -x modelname           : convert model to xml ressource \n\n");

#endif

	return(0);
}

#endif /* _gdtpv_c */



