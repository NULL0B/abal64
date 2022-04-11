//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_nvid_c
#define _html_nvid_c

static	char 	LaPaterne[16] = { '*','P','R','L','@','I','N','F','O','*','#',3,'1','1','a',0 };
static	char *	LaPointeur=(char*)0;
static	char 	LaVersion[8];


char *	getpatternversion()
{
	if (!( LaPointeur )) {
		LaVersion[0] = LaPaterne[12];
		LaVersion[1] = '.';
		LaVersion[2] = LaPaterne[13];
		LaVersion[3] = LaPaterne[14];
		LaVersion[4] = 0;
		LaPointeur = LaVersion;
		}
	return( LaPointeur );

}

#endif	// _html_nvid_c





