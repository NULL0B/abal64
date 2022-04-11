private	void	copy_file_comment( struct file_control * rptr, struct file_control * sptr )
{
	int	i;
	char *	tptr;
	for (i=0; i < MAXNATLANG; i++ ) {
		if (!( sptr->document[i] ))
			continue;
		if ( rptr->document[i] )
			continue;
		rptr->document[i] = sptr->document[i];
		sptr->document[i] = (char *) 0;
		}
	return;
}













