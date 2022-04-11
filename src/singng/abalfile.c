#ifndef	_abalfile_c
#define _abalfile_c

public 	void	export_abal_filebody( FILE * h, char * cname, char * headfile )
{
	abal_banner(h,cname);
	linefeed(h);

	if ( Abal_Config.generate_program ) {
		fprintf(h,"Program %c%s%c",0x0022,cname,0x0022);	
		linefeed(h);
		linefeed(h);
		abal_include(h,headfile);
		linefeed(h);
		linefeed(h);
		}
	else if ( Abal_Config.generate_overlay ) {
		fprintf(h,"Module %c%s%c",0x0022,cname,0x0022);	
		linefeed(h);
		linefeed(h);
		abal_include(h,headfile);
		linefeed(h);
		linefeed(h);
		}

	fprintf(h,"Proc Close_%s() : %c",cname,0x025);
	linefeed(h);
	fprintf(h,"\tDcl  Status%c",0x0025);
	linefeed(h);
	abal_endloc(h,1);
	linefeed(h);
	fprintf(h,"\tIf (ValidPtr( %s ) <> 0 )",cname);
	linefeed(h);
	fprintf(h,"\t\tif ( Hand_%s <> 0 ) ",cname);
	linefeed(h);
	fprintf(h,"\t\t\tClose=Hand_%s:Next,Error_%s",cname,cname);
	linefeed(h);
	fprintf(h,"\t\t\tHand_%s = 0",cname);
	linefeed(h);
	abal_endif(h,2);
	fprintf(h,"\t\tRemove %s",cname);
	linefeed(h);
	fprintf(h,"\t\tForget %s",cname);
	linefeed(h);
	abal_endif(h,1);
	fprintf(h,"\tExit(0)");
	linefeed(h);
	fprintf(h,"EndProc");
	linefeed(h);

	linefeed(h);
	fprintf(h,"Proc Open_%s() : %c",cname,0x025);
	linefeed(h);
	fprintf(h,"\tif ( ValidPtr( %s ) <> 0 )",cname );
	linefeed(h);
	fprintf(h,"\t\tif ( Close_%s() <> 0 ) :: Exit(50) :: Endif",cname);
	linefeed(h);
	abal_endif(h,1);
	fprintf(h,"\tCreate %s ",cname);
	linefeed(h);
	fprintf(h,"\tName_%s = %c%s%c",cname,0x0022,Context.File->filename,0x0022);
	linefeed(h);
	switch ( Context.File->filetype ) {
		case	0 :	/* sectorial 	*/
			fprintf(h,"\tAssign=Hand_%s,Name_%s,WR:Next,Error_%s",
					cname,cname,cname);
			linefeed(h);
			break;
		case	1 :
			fprintf(h,"\tAssign=Hand_%s,Name_%s,SQ,WR:Next,Error_%s",
					cname,cname,cname);
			linefeed(h);
			break;
		case	2 :
			fprintf(h,"\tAssign=Hand_%s,Name_%s,SI,WR:Next,Error_%s",
					cname,cname,cname);
			linefeed(h);
			break;
		case	3 :
			fprintf(h,"\tAssign=Hand_%s,Name_%s,MC,WR:Next,Error_%s,Keys_%s",
					cname,cname,cname,cname);
			linefeed(h);
			break;
		}

	fprintf(h,"\tOpen=Hand_%s:Next,Error_%s",cname,cname);
	linefeed(h);
	fprintf(h,"\tIf ( Error_%s = 40 )",cname);
	linefeed(h);
	fprintf(h,"\t\tCfile=Hand_%s",cname);
	switch ( Context.File->filetype ) {
		case	1 : 
		case	2 : 
		case	3 : fprintf(h,",D=%u",Context.File->recordsize); break;
		}	
	switch ( Context.File->filetype ) {
		case	2 : 
		case	3 : fprintf(h,",K=%u",Context.File->indexsize); break;
		}	
	fprintf(h,":Next,Error_%s",cname);
	linefeed(h);

	switch ( Context.File->filetype ) {
		case	3 : 
			fprintf(h,"\t\tGosub &DclKeys");
			linefeed(h);
			fprintf(h,"\t\tGosub &DclLink");
			linefeed(h);
		}	
	switch ( Context.File->filetype ) {
		case	3 : 
			abal_else(h,1);
			fprintf(h,"\t\tGosub &DclKeys");
			linefeed(h);
		}
	abal_endif(h,1);
	fprintf(h,"\tExit( Error_%s )",cname);
	linefeed(h);
	switch ( Context.File->filetype ) {
		case	3 : 
			fprintf(h,"&DclKeys");
			linefeed(h);
			fprintf(h,"\tReturn");
			linefeed(h);
			fprintf(h,"&DclLink");
			linefeed(h);
			fprintf(h,"\tReturn");
			linefeed(h);
		}
	fprintf(h,"EndProc");
	linefeed(h);
	if ( Abal_Config.generate_program ) { 
		linefeed(h);
		fprintf(h,"Segment 0");
		linefeed(h);
		if (!( Abal_Config.generate_overlay )) {
			fprintf(h,"\tIf ( Open_%s() = 0 )",cname);
			linefeed(h);
			fprintf(h,"\t\tIf ( Close_%s() <> 0 ) :: Endif",cname);
			linefeed(h);
			abal_endif(h,1);
			linefeed(h);
			}
		fprintf(h,"Eseg 0");
		linefeed(h);
		}
	if (( Abal_Config.generate_program ) 
	||  ( Abal_Config.generate_overlay )) {
		linefeed(h);
		fprintf(h,"End");
		linefeed(h);
		}
	return;
}

public 	void	export_abal_filehead( FILE * h, char * cname )
{

	abal_banner(h,cname);
	linefeed(h);

	fprintf(h,"Ptr %s$=4096",cname);		linefeed(h);
	fprintf(h,"Field=m,%s",cname);			linefeed(h);
	abal_dcl(h,"Error_",cname,_ABAL_WORD,0,0,0,NULL);
	abal_dcl(h,"Hand_",cname,_ABAL_WORD,0,0,0,NULL);
	abal_dcl(h,"Name_",cname,_ABAL_STRING,64,0,0,NULL);

	switch ( Context.File->filetype ) {
		case	0 :	/* sectorial 	*/
			abal_dcl(h,"Sect_",cname,_ABAL_BCD,8,0,0,NULL);
			abal_dcl(h,"Buff_",cname,_ABAL_STRING,256,0,0,NULL);
			break;

		case	1 :	/* sequential	*/
			abal_dcl(h,"Dlen_",cname,_ABAL_WORD,0,0,0,NULL);
			abal_dcl(h,"Numb_",cname,_ABAL_BCD,8,0,0,NULL);
			abal_dcl(h,"Buff_",cname,_ABAL_STRING,Context.File->recordsize,0,0);
			break;

		case	3 :	/* misam 	*/
			abal_dcl(h,"Keys_",cname,_ABAL_STRING,1024,0,0,NULL);
			linefeed(h);
		case	2 :	/* isam 	*/
			abal_dcl(h,"Dlen_",cname,_ABAL_WORD,0,0,0,NULL);
			abal_dcl(h,"Klen_",cname,_ABAL_WORD,0,0,0,NULL);
			abal_dcl(h,"Buff_",cname,_ABAL_STRING,Context.File->recordsize+Context.File->indexsize+3,0,0,NULL);
			fprintf(h,"Field=m,Buff_%s",cname);	linefeed(h);
			abal_dcl(h,"Rlen_",cname,_ABAL_WORD,0,0,0,NULL);
			abal_dcl(h,"Prim_",cname,_ABAL_STRING,Context.File->indexsize,0,0,NULL);
			abal_dcl(h,"Mark_",cname,_ABAL_BYTE,0,0,0,NULL);
			abal_dcl(h,"Data_",cname,_ABAL_STRING,Context.File->recordsize,0,0,NULL);
			if ( Context.File->record ) {
				fprintf(h,"Field=m,Data_%s",cname);	linefeed(h);
				export_class_members( h, Context.File->record );
				}
			break;
		case	4 :	/* database 	*/
			break;
		}

	fprintf(h,"Field=m");	linefeed(h);

	linefeed(h);
	return;
}

public 	void	export_abal_file( FILE * h, char * headname )
{
	char	*		cname;

	Abal_Config.generate_overlay = Context.File->overlay;
	Abal_Config.generate_program = Context.File->program;

	if (!( Abal_Config.cname = Context.File->identifier))
		Abal_Config.cname = "std";

	else if (!( *Abal_Config.cname ))
		Abal_Config.cname = "std";

	if (!( headname ))
		export_abal_filehead( h,Abal_Config.cname );
	else	export_abal_filebody( h,Abal_Config.cname, headname );
	return;
}


#endif /* _abalfile_c */

