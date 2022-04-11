#ifndef	_youtput_c
#define	_youtput_c

char	filebuffer[256];

void	drop_symbols();

struct	yabal_output	{
	FILE	*	mfhandle;
	FILE	*	defhandle;
	char	*	mfname;
	char	*	defname;
	} Output = { (FILE*)0,(FILE*) 0, (char *) 0, (char *) 0 };

char	*	make_filename( char * froot, char * fext )
{
	char * sptr;
	if (!( fn_parser( froot,filebuffer,0x000F )))
		return((char *) 0);
	else	{
		strcat(filebuffer,fext);
		if (( sptr = allocate( strlen( filebuffer) + 1 )) != (char *) 0)
			strcpy( sptr, filebuffer );
		return( sptr );
		}
}

void	reset_output()
{
	Output.mfname = Output.defname = (char *) 0;
	Output.mfhandle = Output.defhandle = (FILE *) 0;
	drop_symbols();
	return;
}


void	underscored_token( FILE * h, char * sptr )
{
	int	c;
	while ((c = (*(sptr++) & 0x00FF)) != 0 ) {
		if ((( c >= 'A' ) && ( c <= 'Z' ))
		||  (( c >= 'a' ) && ( c <= 'z' ))
		||  (( c >= '0' ) && ( c <= '1' )))
			fprintf(h,"%c",c);
		else	fprintf(h,"_");
		}
	return;
}

int	open_output( char * froot )
{
	reset_output();

	if (!( Output.mfname = make_filename( froot, ".mf" )))
		return(report_error(27));
	else if (!( Output.defname = make_filename( froot, ".def" )))
		return(report_error(27));
	else if (!( Output.defhandle = fopen( Output.defname, "w") ))
		return(report_error(46));
	else if (!( Output.mfhandle = fopen( Output.mfname, "w") ))
		return(report_error(46));
	else	{

		fprintf(Output.defhandle,"! ifndef ");
		underscored_token(Output.defhandle,Output.defname);		
		fprintf(Output.defhandle,"\n");

		underscored_token(Output.defhandle,Output.defname);		
		fprintf(Output.defhandle," = true ");
		fprintf(Output.defhandle,"\n");

		if (!( including )) {
			comment(Output.defhandle,"ABAL 32","Standard Definitions");
			fprintf(Output.defhandle,"otr = otr32 -a -o -m\n");
			fprintf(Output.defhandle,"old = old32 -a -m   \n\n");
			fprintf(Output.defhandle,".s.o:\n");
				fprintf(Output.defhandle,"\t$(otr) -d$@ $*\n");
			fprintf(Output.defhandle,".as.o:\n");
				fprintf(Output.defhandle,"\t$(otr) -d$@ $*\n");
				fprintf(Output.defhandle,".s.at:\n");
				fprintf(Output.defhandle,"\t$(otr) -d$@ $*\n");
			fprintf(Output.defhandle,".as.at:\n");
				fprintf(Output.defhandle,"\t$(otr) -d$@ $*\n");
			fprintf(Output.defhandle,".o.at:\n");
				fprintf(Output.defhandle,"\t$(old) -d$@ $?\n\n! make \n\n");
			}
		else	inclusion( Output.defhandle,including );
		return( 0 );
		}
}

void	close_output()
{
	if ( Output.mfhandle ) {
		fprintf(Output.mfhandle,"\n\n# end of file\n\n");
		fclose(Output.mfhandle);
		if ( Output.mfname )
			liberate( Output.mfname );
		}

	if ( Output.defhandle ) {
		fprintf(Output.defhandle,"! endif\n");
		fprintf(Output.defhandle,"\n\n# end of file\n\n");
		fclose(Output.defhandle);
		if ( Output.defname )
			liberate( Output.defname );
		}

	reset_output();
	return;
}

#endif	// _youtput_c

