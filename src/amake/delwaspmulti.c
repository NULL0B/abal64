#include <stdio.h>
char	buffer[4096];
char *	productname="BDANET MULTI FOR USE IT";
int	productnumber=31;
int	main()
{
	printf("\ndisinistallation of bda@net version multiserver\n");
	sprintf(buffer,"delnamecode %c%s%c ",0x0022,productname,0x0022);
	system(buffer);
	printf("completed\n");
	return(0);
}

