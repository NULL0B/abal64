#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

void	mf_message( mptr )
char * mptr;
{
	printf("%s",mptr);
	return;
}

void	llmf_co( c )
int	c;
{
	printf("%c",c);
	return;
}

void	llmf_close( nlog )
int	nlog;
{
	close( nlog );
	return;

}

int	llmf_open( fnom , perm )
char * fnom;
int	perm;
{
	return( open(fnom,O_RDONLY) );
}


int	rename(oldname,newname)
const char * oldname;
const char * newname;
{
	if ( link(oldname,newname) != -1 ) {
		unlink( oldname );
		return(0);
		}
	return(-1);
}

void	touche( nptr )
char * nptr;
{
	int l,fid;
	char buffer[256];

	if ((fid = open(nptr ,O_RDWR)) != -1 ) {
		if (( l = read(fid,buffer,256) ) > 0 ) {
			lseek(fid,0L,SEEK_SET);
			write(fid,buffer,l);
			}
		close(fid);
		}
	return;
}
void	start_xallocate()
{
	return;
}
void	flush_xallocate(n)
{
	return;
}


