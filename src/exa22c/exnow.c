#include <stdio.h>
#include <fcntl.h>
#ifndef SEEK_SET 
#define SEEK_SET 0
#endif

main(argc,argv)
int argc;
char * argv[];
{
	int i,l,fid;
	char buffer[256];

	for ( i=1; i<argc; i++) {
		fid = open(argv[i],O_RDWR);
		if ( fid != -1 ) {
			printf("%s\n",argv[i]);
			if (( l = read(fid,buffer,256) ) > 0 ) {
				lseek(fid,0L,SEEK_SET);
				write(fid,buffer,l);
				}
			close(fid);
			}
		}
	return(0);
}

