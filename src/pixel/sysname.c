
	int	i;
	char *	rptr;
	strcpy((rptr = this.buffer),"*"); rptr += strlen(rptr);
	if ((i=notwhite(foundry.buffer,foundry.size)) != 0) {
		memcpy(rptr,foundry.buffer,i);
		*(rptr+i) = 0;
		}
	strcat(rptr,"-");rptr += strlen(rptr);

	switch ( family.value ) {
		case	 0 : strcat(rptr,"*"); break;
		case	 1 : strcat(rptr,"charter"); break;
		case	 2 : strcat(rptr,"courier"); break;
		case	 3 : strcat(rptr,"helvetica"); break;
		case	 4 : strcat(rptr,"gothic"); break;
		case	 5 : strcat(rptr,"new century schoolbook"); break;
		case	 6 : strcat(rptr,"times"); break;
		case	 7 : strcat(rptr,"symbol"); break;
		case	 8 : strcat(rptr,"utopia"); break;
		case	 9 : strcat(rptr,"luxi moni"); break;
		case	10 : strcat(rptr,"luxi serif"); break;
		case	11 : strcat(rptr,"lucida"); break;
		case	12 : strcat(rptr,"lucidabright"); break;
		case	13 : strcat(rptr,"lucidatypewriter"); break;
		case	14 : strcat(rptr,"newspaper"); break;
		case	15 : strcat(rptr,"terminal"); break;
		case	16 : strcat(rptr,"fixed"); break;
		case	17 : strcat(rptr,"arial"); break;
		}
	strcat(rptr,"-");rptr += strlen(rptr);

	switch ( weight.value ) {
		case	0 : strcat(rptr,"*"); break;
		case	1 : strcat(rptr,"medium"); break;
		case	2 : strcat(rptr,"bold"); break;
		case	3 : strcat(rptr,"black"); break;
		case	4 : strcat(rptr,"regular"); break;
		}
	strcat(rptr,"-");rptr += strlen(rptr);

	switch ( slant.value ) {
		case	0 : strcat(rptr,"*"); break;
		case	1 : strcat(rptr,"r"); break;
		case	2 : strcat(rptr,"i"); break;
		case	3 : strcat(rptr,"o"); break;
		}
	strcat(rptr,"-");rptr += strlen(rptr);

	switch ( setwidth.value ) {
		case	0 : strcat(rptr,"*"); break;
		case	1 : strcat(rptr,"normal"); break;
		case	2 : strcat(rptr,"condensed"); break;
		case	3 : strcat(rptr,"narrow"); break;
		case	4 : strcat(rptr,"double width"); break;
		}
	strcat(rptr,"-");rptr += strlen(rptr);

	if ((i=notwhite(pixels.buffer,pixels.size)) != 0) {
		memcpy(rptr,pixels.buffer,i);
		*(rptr+i) = 0;
		}
	else	strcat(rptr,"*");
	strcat(rptr,"-");rptr += strlen(rptr);

	if ((i=notwhite(points.buffer,points.size)) != 0) {
		memcpy(rptr,points.buffer,i);
		*(rptr+i) = 0;
		}
	else	strcat(rptr,"*");
	strcat(rptr,"-");rptr += strlen(rptr);

	switch ( hresdpi.value ) {
		case	0 : strcat(rptr,"*"); break;
		case	1 : strcat(rptr,"75"); break;
		case	2 : strcat(rptr,"100"); break;
		case	3 : strcat(rptr,"120"); break;
		case	4 : strcat(rptr,"150"); break;
		case	5 : strcat(rptr,"200"); break;
		case	6 : strcat(rptr,"240"); break;
		case	7 : strcat(rptr,"300"); break;
		}
	strcat(rptr,"-");rptr += strlen(rptr);

	switch ( vresdpi.value ) {
		case	0 : strcat(rptr,"*"); break;
		case	1 : strcat(rptr,"75"); break;
		case	2 : strcat(rptr,"100"); break;
		case	3 : strcat(rptr,"120"); break;
		case	4 : strcat(rptr,"150"); break;
		case	5 : strcat(rptr,"200"); break;
		case	6 : strcat(rptr,"240"); break;
		case	7 : strcat(rptr,"300"); break;
		}
	strcat(rptr,"-");rptr += strlen(rptr);

	switch ( spacing.value ) {
		case	0 : strcat(rptr,"*"); break;
		case	1 : strcat(rptr,"m"); break;
		case	2 : strcat(rptr,"p"); break;
		}
	strcat(rptr,"-");rptr += strlen(rptr);

	if ((i=notwhite(average.buffer,average.size)) != 0) {
		memcpy(rptr,average.buffer,i);
		*(rptr+i) = 0;
		}
	else	strcat(rptr,"*");
	strcat(rptr,"-");rptr += strlen(rptr);

	if ((i=notwhite(charset.buffer,charset.size)) != 0) {
		memcpy(rptr,charset.buffer,i);
		*(rptr+i) = 0;
		}
	else	strcat(rptr,"*");

