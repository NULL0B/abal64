#include <stdio.h>

int	main()
{
	printf("   pid             %u\n",getpid());
	printf("   uid             %u\n",getuid());
	printf("   gid             %u\n",getgid());
	printf("   euid            %u\n",geteuid());
	return;
}

