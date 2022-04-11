#include <stdio.h>

#define	SOFTERROR	0

int	debug=1;



int	compare(char * aptr, char * bptr)
{
	while (( *aptr != 0 ) && ( * bptr != 0 ))
		if ( *aptr != *bptr )
			return(0);
	
	if ( *aptr != *bptr )
		return(0);
	else	return(1);
}
	
	
int	err_val=0;

char	buffer[256];

int main(int argc, char * argv[] )
{
	int	i;
	int	handle=1;
	int	status;
	printf("\n   Linux DLL Load Module Test");
	printf("\n   Provisoire du 31/08/2001");
	printf("\n   Copyright (c) 2001,2006 Amenesik / Sologic \n");


	if ( InitRunTime(handle,"testbda",0, buffer, 256 ) != SOFTERROR ) {

		for (i=0; i < 10; i++ )
			status = CallRunTime(handle,i,0,buffer,buffer,buffer);

		(void) FinRunTime(handle);


		}

	return(0);

}

