#include <stdio.h>
#include "encode64.c"
char	result[256];

int	main()
{
	char * sptr;

	sptr = "Aladdin:open sesame";
	encode_base64( result,sptr,strlen(sptr) );
	printf(" Base64 coding of %s\n%s\nQWxhZGRpbjpvcGVuIHNlc2FtZQ==\n",sptr,result);
	return(0);
}



