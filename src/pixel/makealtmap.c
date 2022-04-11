#include <stdio.h>
int	main()
{
	FILE * h;
	int	i;
	char 	buffer[256];
	if (!( h = fopen("iso8859-2.altmap","w"))
		return(1);
	else	{
		for (i=0; i < 256; i++)
			buffer[i] = 0;
		}
}
		
