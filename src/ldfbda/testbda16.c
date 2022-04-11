#define LDF_BDA_TESTER

#include "exbda.c"

EXAWORD	err_val=0;

int	main(int argc, char * argv[]) 

{
	int	argi;
	int	retcode=0;
	int	problem=0;
	if ( argc == 1 )
#ifdef	VERSION666
		printf("\n   ABAL 32 Bit Dynamic/Shared Library Tester : Version 1.1b.0.01\n   Copyright (c) 2001,2006 Amenesik / Sologic \n\n");
#else
		printf("\n   ABAL 16 Bit Dynamic/Shared Library Tester : Version 1.1b.0.01\n   Copyright (c) 2001,2006 Amenesik / Sologic \n\n");
#endif
	else	{
		for ( argi=1; argi < argc; argi++ )  {
			if ((retcode = InitRunTime(1,argv[argi],0,(int *) 0,0,(void *) 0, 0)) != GOODRESULT) {
				problem=1;
				printf("error:%u library:%s\n",err_val,argv[argi]);
				}
			else	{
				printf("library %s ok\n",argv[argi]);
				}
			}
		}
	return(problem);
}

