//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_stub_http_c
#define _stub_http_c

static	char	GetSet[256];
static	char	PutSet[256];
static	int 	TransCode=0;

	int 	TranscodeByte( c )
	int 	c;
{
	int	i;
	if (!( TransCode )) {
		for ( i=0; i < 256; i++ ) {
			GetSet[i] = i;
			PutSet[i] = i;
			}

		GetSet[0x00A9] = '‡';	PutSet['‡'] = 0x00A9;
		GetSet[0x00E9] = '‚';	PutSet['‚'] = 0x00E9;
		GetSet[0x00E0] = '…';	PutSet['…'] = 0x00E0;
		GetSet[0x00E8] = 'Š';	PutSet['Š'] = 0x00E8;
		GetSet[0x00EC] = '';	PutSet[''] = 0x00EC;
		GetSet[0x00F2] = '•';	PutSet['•'] = 0x00F2;
		GetSet[0x00F9] = '—';	PutSet['—'] = 0x00F9;

		TransCode=1;
		}
	return( GetSet[(c & 0x00FF)] );
}

int	HttpInitialise(char * optr,int l) { 	/* printf("\nHttpInitialise(%s)\n",optr); */ return(0); 	}
int	HttpLiberate()			  { 	/* printf("\nHttpLiberate\n"); */ return(0); 	}
int	HttpOpenServer(int a,int b)	  { 	/* printf("\nHttpOpenServer\n"); */ return(-1); 	}
int	HttpOpenClient(char * nptr,int l,int m) {	/* printf("\nHttpOpenClient(%s)\n",nptr); */ return(-1);	}
int	HttpClose(int h,int n)		  {	/* printf("\nHttpClose\n"); */ return(0);	}
int	HttpAccept(int a,int b)		  {	/* printf("\nHttpAccept\n"); */ return(0);	}
int	HttpCommand(int a,char *b)	  {	/* printf("\nHttpCommand\n"); */ return(0);	}
int	HttpProxyCommand(int a,char *b,char *c)	  {	/* printf("\nHttpProxyCommand\n"); */ return(0);	}
int	HttpGet(int s,char *b,int l)	  {	/* printf("\nHttpGet\n"); */ return(0);	}		
int	HttpPut(int s,char *b,int l)	  {	/* printf("\nHttpPut\n"); */ return(0);	}
int	HttpGetLine(int s,char *b,int l)  {	/* printf("\nHttpGetLine\n"); */ return(0);	}
int	HttpGetString(int s,char *b,int l){	/* printf("\nHttpGetString\n"); */ return(0);	}
int	HttpPutLine(int s,char *b,int l)  {	/* printf("\nHttpPutLine\n"); */ return(0);	}
int	HttpGetAddress(int s,char *b,int l){	/* printf("\nHttpGetAddress\n"); */ return(0);	}
int	HttpSetHost(int s,char *b)	  {	/* printf("\nHttpSetHost(%u,%s)\n",s,b); */ return(0);	}

#endif	// _stub_http_c

