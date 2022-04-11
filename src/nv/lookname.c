#include <stdio.h>
#include "domain.c"

int	main( int argc, char * argv[] )
{

	printf("\n   Domain name inspection : Version 1.1a.0.01 ");
	printf("\n   Provisoire du 17/10/2000 ");
	printf("\n   Copyright (c) 2000,2006 Amenesik / Sologic \n");
	printf("\n   Doamin : %s \n",get_domain(0));
	return(0);
}

