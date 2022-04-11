//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_zabalid_c
#define _zabalid_c

static	char 	LaPaterne[20] = { '*','P','R','L','@','I','N','F','O','*','#',6,'1','1','a','0','0','1',0 };
static	char *	LaPointeur=(char*)0;
static	char 	LaVersion[12];


char *	getpatternversion()
{
	if (!( LaPointeur )) {
		LaVersion[0] = LaPaterne[12];
		LaVersion[1] = '.';
		LaVersion[2] = LaPaterne[13];
		LaVersion[3] = LaPaterne[14];
		LaVersion[4] = '.';
		LaVersion[5] = LaPaterne[15];
		LaVersion[6] = '.';
		LaVersion[7] = LaPaterne[16];
		LaVersion[8] = LaPaterne[17];
		LaVersion[9] = 0;
		LaPointeur = LaVersion;
		}
	return( LaPointeur );

}

#endif	// _zabalid_c





