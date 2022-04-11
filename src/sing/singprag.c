struct	object_pragma_values {
	int	TokenSize;
	int	IgnoreCase;
	int	EnhancedIndirect;
	} Pragmas = { 64,1,1 };

#ifdef	_PROTOTYPE_CLASS
public	int	object_pragmas()
{
	(void) 
		accept_pragmas(
			&Pragmas.TokenSize,
			&Pragmas.IgnoreCase,
			&Pragmas.EnhancedIndirect );
	draw_console();
	return(256);
}
#endif
private	void	pragma_value( FILE * h,int v )
{
	if ( v )
		fprintf(h," on\r\n");
	else	fprintf(h," off\r\n");
	return;
}

void	export_pragmas( FILE * h )
{
	fprintf( h, "#pragma ignore_case ");
	pragma_value( h, Pragmas.IgnoreCase );
	fprintf( h, "#pragma enhanced indirect ");
	pragma_value( h, Pragmas.EnhancedIndirect );
	fprintf(h,"#pragma tokensize   %u\r\n",Pragmas.TokenSize);
	return;
}


