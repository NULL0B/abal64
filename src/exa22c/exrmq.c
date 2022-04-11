int	killqueue( qid )
int	qid;
{
	int qid;

	if (( qid = msgget((key_t) 13, 0)) != -1 ) {
		if ( msgctl(qid,IPC_RMID,"  ") != 0 ) {
			return( FAILURE );
			}
		else	{
			return(SUCCESS);
			}
		}
	else	{
		return(FAILURE);
		}
}

