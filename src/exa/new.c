EXAWORD	get_assign_event() { return( Anfc_Mode ); }
VOID	set_assign_event(EXAWORD v) { Anfc_Mode = v; return; }

EXAWORD	new_assign_handle()	
{
	EXAWORD	i;
	for ( i=1; i < diezfic; i++ )
		if (!( (*(AssignTable + i)).direcp ))
			return(i);
	return(0);	
}

EXAWORD	drop_assign_handle( EXAWORD handle )
{
	/* Check first for correct ASSIGN and Handle */
	/* ----------------------------------------- */
	if ( check_valid_assign_handle( handle ) == SOFTERROR )
		return( SOFTERROR );

	/* Load file table information */
	/* --------------------------- */
	lfh = handle; 
	if ((err_val = loadfich()) != 0)
		return( SOFTERROR );

	sf_close(); freefich(); savefich();

	return( GOODRESULT );
}

/* HANDLE */	case 77:  if ( drop_assign_handle(v) == SOFTERROR )
				return( SOFTERROR );
			  else	break;
/* HANDLE */	case 77: return( new_assign_handle() );

