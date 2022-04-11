#include <stdio.h>

void	llmf_co( c )
short int c;
{
	printf("%c",c);
	return;
}

void	mf_message( sptr )
char * sptr;
{
	printf("%s",sptr);
	return;
}

int	unlink( fptr )
char * fptr;
{
	return(delete(fptr));
}

