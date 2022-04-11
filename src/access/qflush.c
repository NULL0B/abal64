#include <stdio.h>

int	main(int argc, char * argv[] )
{

	printf("Access Message Queue Flush Utility \n");
	purge_blocked_messages();
	printf("End\n");
	return(0);
}

