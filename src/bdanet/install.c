#include <stdio.h>

char	pathbuf[1024];
char	command[1024];

int	installation( char * cptr, char * mptr, char * lptr )
{
	int	i;
	int	l=0;

	for (l=0,i=0; i < 1024; i++ ) {
		if (!( pathbuf[i] = *(cptr+i) ))
			break;
		else if (pathbuf[i] != '/' )
			continue;
		else	l = (i+1);
		}
	pathbuf[l]=0;
	strcat( pathbuf, mptr );
	strcat( pathbuf, "/" );
	strcat( pathbuf, lptr );
	strcat( pathbuf, "/" );

	printf("\nInstallation of BdaNet 1.1c diffusion 2 for Useit \n");

	/* create path if necessary */
	/* ------------------------ */
	printf("Creation or Checking Directory /home/bdanet\n");
	system("mkdir /home/bdanet 2>/dev/null");

	/* Change into directory */
	/* --------------------- */
	chdir("/home/bdanet");

	/* Copy Dynamic libraries to their destination */
	/* ------------------------------------------- */
	printf("Copying dynamic libraries to /lib\n");
	sprintf(command,"cp %sbdanet*.so /lib -f",pathbuf);
	if ( system(command) != 0 ) {
		printf("Installation of BdaNet 1.1c diffusion 2 for Useit .......... ..... [FAILED]\n");
		return(1);
		}
	else	{
		printf("Copying documentation to /home/bdanet\n");
		sprintf(command,"cp %s*.htm /home/bdanet -f",pathbuf);
		system(command);
		sprintf(command,"cp %s*.css /home/bdanet -f",pathbuf);
		system(command);
		sprintf(command,"cp %s*.gif /home/bdanet -f",pathbuf);
		system(command);

		/* Copy Examples to the destination */
		/* -------------------------------- */
		printf("Copying example package to /home/bdanet\n");
		sprintf(command,"cp %sexample*.zip /home/bdanet -f",pathbuf);
		if ( system(command) != 0 ) {
			printf("Installation of BdaNet 1.1c diffusion 2 for Useit .......... ..... [FAILED]\n");
			return(2);
			}
		else	{
			printf("Installation of BdaNet 1.1c diffusion 2 for Useit .......... ..... [OK]\n");
			printf("Run mozilla file:///home/bdanet/bdanet.htm to consult the documentation\n");
			return(0);
			}
		}
}

int	main(int argc, char * argv[] )
{
	if ( argc != 3 ) {
		printf("\n   Installation of BdaNet 1.1c for UseIt");
		printf("\n   Copyright (c) Amenesik / Sologic ");
		printf("\n   Usage : ");
		printf("\n         /mnt/cdrom/install [ runtime | dev ] [ en | fr ]\n\n ");
		return( 0);
		}
	else	{
		return( installation(argv[0],argv[1],argv[2]) );
		}
}


