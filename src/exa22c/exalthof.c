static EXAWORD	AskCount;

void trace_open_files()
{
	EXAWORD	holdlfh=lfh;
	EXAWORD	nombre=0;

	/* Liberate all other File Entries */
	/* ------------------------------- */
	for ( lfh = 1; lfh <= diezfile; lfh++ ) {
		if (( (*(AssignTable + lfh)).permf  & NGF_R_W  )
		&&  ( (*(AssignTable + lfh)).unlog  != EX_UNUSED_HANDLE ))
			nombre++;
		}

	if ( nombre )
		AskCount++;

	lfh = holdlfh;
	return;	
}
void flush_trace_open_files()
{
	if ( AskCount != 0 ) {
		x_clear();
		x_cprintf((BPTR) "Number of Asks with files open : "); intvisi( AskCount );
		}
	return;
}
void init_trace_open_files()
{
	AskCount = 0;
	return;
}
