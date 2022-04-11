#include <stdio.h>
#include "vstyle.h"

int	main()
{
	int	i;
	for (i=0; i < _max_style_keywords; i++ )
		printf("#define _keyword_%s\t\t0x00%x\r\n",_style_keyword[i],i);

	return(0);
}

