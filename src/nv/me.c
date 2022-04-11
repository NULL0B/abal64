	if (( *filename     == 'G')
	&&  ( *(filename+1) == 'E')
	&&  ( *(filename+2) == 'T')
	&&  ( *(filename+3) == ' ')) {
		filename += 4;
		method = "GET";
		}
	else if (( *filename     == 'P')
	     &&  ( *(filename+1) == 'U')
	     &&  ( *(filename+2) == 'T')
	     &&  ( *(filename+3) == ' ')) {
		filename += 4;
		method = "PUT";
		}
		
	else if (( *filename     == 'P')
	     &&  ( *(filename+1) == 'O')
	     &&  ( *(filename+2) == 'S')
	     &&  ( *(filename+3) == 'T')
	     &&  ( *(filename+4) == ' ')) {
		filename += 5;
		method = "POST";
		}
	else	method = "GET";
		


