#include <stdio.h>
int	main(int argc,char * argv[])
{
	char *	eptr;
	char *	getenv();
	if (!(eptr = getenv("ABALPROCESS")))
		printf("0\n");
	else if ( *eptr != ':' )
		printf("%s\n",eptr);
	else	printf("%s\n",(eptr+1));
	return(0);
}


