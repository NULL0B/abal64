#ifndef	_gdtpv_c
#define	_gdtpv_c


#define	_GDT_DATE	"23/11/2004"

private  char	VersionStatus[16]=
	{ 'V','E','R','S','I','O','N','_','S','T','A','T','U','S',':','2' };
public 	char 	LaPaterne[20] = { '*','P','R','L','@','I','N','F','O','*','#',6,'1','1','a','0','4','6',0 };
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

private	int	banner()
{
	printf("\n   Graphical Design Tool : Version %s ",getpatternversion());

	if ( VersionStatus[15] == '2' )
		printf(Provisoire,_GDT_DATE);

	printf("\n   Copyright (c) 2001,2006 Amenesik / Sologic \n");
	printf("\n   Syntax : \t sing [ options parameters ] \n");
	printf("\n          -i config@host         : inject configuration as host configuration entry ");
	printf("\n          -c modelname           : perform complete model production ");
	printf("\n          -lconfigname           : load specified default configuration ");
	printf("\n          -x modelname           : convert model to xml ressource \n\n");

	return(0);
}

#endif /* _gdtpv_c */


