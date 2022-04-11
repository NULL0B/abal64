#ifndef	_singphp_c
#define	_singphp_c


int	GenMySql=0;
extern	char *	extract_path( char * sptr );
extern	char *	path_prefix( char * filename, char * filepath );

static	void	php_class_members(FILE * h, struct form_control *  fptr, struct form_item * iptr, char * classname )
{
	int			fields=0;
	struct	data_control * 	dptr=(struct data_control *) 0;
	int			i;
	if (!(dptr = iptr->Contents.extra ))
		return;
	else if (!( fields = dptr->indexfields + dptr->datafields ))
		return;
	else	{
		fprintf(h,"\tprotected $sqlbase=NULL;\n");
		fprintf(h,"\tprotected $connection=NULL;\n");
		fprintf(h,"\tprotected $xmlparser=NULL;\n");
		fprintf(h,"\tprotected $xmethod=NULL;\n");
		fprintf(h,"\tprotected $xrecords=NULL;\n");
		fprintf(h,"\tprotected $host=%clocalhost%c;\n",__QUOTE,__QUOTE);
		fprintf(h,"\tprotected $user=%cprologue%c;\n",__QUOTE,__QUOTE);
		fprintf(h,"\tprotected $pass=%cprol%c;\n",__QUOTE,__QUOTE);
		fprintf(h,"\tpublic    $question = %c%c;\n",__QUOTE,__QUOTE);
		fprintf(h,"\tpublic    $response = 0;\n");
		fprintf(h,"\tpublic    $collection = NULL;\n");
		fprintf(h,"\tpublic    $error = 0;\n");
		fprintf(h,"\tpublic    $basename = %c%s%c;\n",__QUOTE,classname,__QUOTE);
		fprintf(h,"\tpublic    $tablename = %c%s%c;\n",__QUOTE,classname,__QUOTE);
		for (i=0; i < fields; i++ ) {
			switch ( dptr->type[i] ) {
				case	_ABAL_BYTE	: 
				case	_ABAL_WORD	: 
				case	_ABAL_LONG	: 
				case	_ABAL_BCD 	: 
					fprintf(h,"\tpublic $_%s = 0;\n",dptr->name[i]);
					break;
				case	_ABAL_STRING	: 
				default			:
					fprintf(h,"\tpublic $_%s = %c%c;\n",dptr->name[i],__QUOTE,__QUOTE);
					break;
				}
			}
		fprintf(h,"\n\tpublic function __construct($pbasename,$pfilename)\n\t{\n");
		fprintf(h,"\t$this->sqlbase   = new database;\n");
		fprintf(h,"\t$this->basename  = $pbasename;\n");
		fprintf(h,"\t$this->tablename = implode(%c_%c,explode(%c.%c,$pfilename));\n",
			__QUOTE,__QUOTE,__QUOTE,__QUOTE);
		fprintf(h,"\t$this->portions  = explode(%c:%c,$pfilename);\n",__QUOTE,__QUOTE);
		fprintf(h,"\tif ( count( $this->portions ) > 1 ) {\n");
		fprintf(h,"\t\t$this->basename = $this->portions[0]; \n");
		fprintf(h,"\t\t$this->tablename = $this->portions[1]; \n");
		fprintf(h,"\t}\n");
		fprintf(h,"\t$this->connection = $this->sqlbase->connect($this->host,$this->user,$this->pass);\n");
		fprintf(h,"\tif (!($this->connection)) { die('error connection to : ' . $this->sqlbase->error()); } \n");
		fprintf(h,"\telse { $this->sqlbase->select($this->basename, $this->connection); }\n");
		fprintf(h,"\t}\n");

		fprintf(h,"\n\tpublic function OnSaveSession()\n\t{\n");
		fprintf(h,"\t$_SESSION['question_%s'] = htmlentities($this->question,ENT_QUOTES);\n",classname);
		fprintf(h,"\t$_SESSION['response_%s'] = $this->response;\n",classname);
		fprintf(h,"\t$_SESSION['collection_%s'] = $this->collection;\n",classname);
		fprintf(h,"\t}\n");

		fprintf(h,"\n\tpublic function OnStartSession()\n\t{\n");
		fprintf(h,"\tif ( isset( $_SESSION['response_%s'] ) )\n\t{\n",classname);
			fprintf(h,"\t\t$this->response = $_SESSION['response_%s'];\n\t}\n",classname);
		fprintf(h,"\telse { $this->response = 0; }\n");
		fprintf(h,"\tif ( isset( $_SESSION['collection_%s'] ) )\n\t{\n",classname);
			fprintf(h,"\t\t$this->collection = $_SESSION['collection_%s'];\n\t}\n",classname);
		fprintf(h,"\telse { $this->collection = 0; }\n");
		fprintf(h,"\tif (( isset( $_SESSION['question_%s'] )) && ( $this->response != 0))\n\t{\n",classname);
			fprintf(h,"\t\t$this->question = html_entity_decode($_SESSION['question_%s'],ENT_QUOTES);\n\t}\n",classname);
		fprintf(h,"\telse { $this->question = %c%c; }\n",__QUOTE,__QUOTE);
		fprintf(h,"\t}\n");
		}
}

static	void	php_reset_table(FILE * h, struct form_control *  fptr, struct form_item * iptr,char * classname )
{
	int			fields=0;
	struct	data_control * 	dptr=(struct data_control *) 0;
	int			i;
	if (!(dptr = iptr->Contents.extra ))
		return;
	else if (!( fields = dptr->indexfields + dptr->datafields ))
		return;
	else	{
		fprintf(h,"\n\tpublic function OnReset()\n\t{\n");
		for (i=dptr->indexfields; i < fields; i++ ) {
			if ( dptr->first[i] )
				fprintf(h,"\t$this->_%s = array();\n",dptr->name[i]);
			else 	{
				switch ( dptr->type[i] ) {
					case	_ABAL_BYTE	: 
					case	_ABAL_WORD	: 
					case	_ABAL_LONG	: 
					case	_ABAL_BCD 	: 
						fprintf(h,"\t$this->_%s = 0;\n",dptr->name[i]);
						break;
					case	_ABAL_STRING	: 
					default			:
						fprintf(h,"\t$this->_%s = %c%c;\n",dptr->name[i],__QUOTE,__QUOTE);
						break;
					}
				}
			}
		fprintf(h,"\t}\n");
		}
}

static 	char	tolowerbuf[1024];
static	char *	strtolower(char * sptr )
{
	int	i;
	for ( i=0; *(sptr+i) != 0; i++ ) {
		if ( i > 1023 )
			break;
		else if ((*(sptr+i) >= 'A') && (*(sptr+i) <= 'Z'))
			tolowerbuf[i] = (*(sptr+i) | 0x0020);
		else	tolowerbuf[i] = *(sptr+i);
		}
	tolowerbuf[i] = 0;
	return( tolowerbuf );
}

static	char	SpecialNameBuffer[2048];

static	char *	special_sql_name( char * nptr )
{
	sprintf(SpecialNameBuffer,"_%s",nptr);
	return( SpecialNameBuffer );
}

static	char *	check_sql_name( char * nptr )
{
	if (!( strcasecmp( nptr, "DATE" ) ))
		return( special_sql_name( nptr ) );
	else if (!( strcasecmp( nptr, "TIME" ) ))
		return( special_sql_name( nptr ) );
	else if (!( strcasecmp( nptr, "GROUP" ) ))
		return( special_sql_name( nptr ) );
	else	return( nptr );
}

static	void	php_create_table(FILE * h, struct form_control *  fptr, struct form_item * iptr,char * classname )
{
	char	*		eptr;
	int			fields=0;
	struct	data_control * 	dptr=(struct data_control *) 0;
	int			i;
	if (!(dptr = iptr->Contents.extra ))
		return;
	else if (!( fields = dptr->indexfields + dptr->datafields ))
		return;
	else	{
		fprintf(h,"\n\tpublic function OnNew()\n\t{\n");
		fprintf(h,"\t$this->OnLast();\n");
		fprintf(h,"\tif (( $this->error == 78 ) || ( $this->error == 48))");
		fprintf(h,"\t{\n");
		if ( dptr->indexfields == 1 ) {
			switch ( dptr->type[0] ) {
				case	_ABAL_BYTE	: 
				case	_ABAL_WORD	: 
				case	_ABAL_LONG	: 
				case	_ABAL_BCD 	: 
					fprintf(h,"\t\t$this->_%s = 0;\n",dptr->name[0]);
					break;
				case	_ABAL_STRING	: 
				default			:
					fprintf(h,"\t\t$this->_%s = %c%c;\n",dptr->name[0],__QUOTE,__QUOTE);
					break;
				}
			}
		else	{
			fprintf(h,"\t\t// perform complex primary index reset here \n");
			}
		fprintf(h,"\t\t}\n");
		fprintf(h,"\t$this->OnReset();\n");
		if ( dptr->indexfields == 1 ) {
			switch ( dptr->type[0] ) {
				case	_ABAL_BYTE	: 
				case	_ABAL_WORD	: 
				case	_ABAL_LONG	: 
				case	_ABAL_BCD 	: 
					fprintf(h,"\t$this->_%s++;\n",dptr->name[0]);
					break;
				case	_ABAL_STRING	: 
				default			:
					fprintf(h,"\t$this->_%s = sprintf(%c%%0%u.0u%c,($this->_%s+1));\n",dptr->name[0],__QUOTE,dptr->width[0],__QUOTE,dptr->name[0]);
					break;
				}
			}
		else	{
			fprintf(h,"\t\t// perform complex primary index incrementation here \n");
			}
		fprintf(h,"\t$this->OnInsert();\n");
		fprintf(h,"\t}\n");

		fprintf(h,"\n\tpublic function OnRemove()\n\t{\n");
		fprintf(h,"\t$this->sqlbase->query(%cDROP TABLE %c . $this->tablename, $this->connection );\n",__QUOTE,__QUOTE);
		fprintf(h,"\t}\n");
		if ((eptr = getenv("SINGMYSQL")) != (char *)0)
			GenMySql = atoi( eptr );
		else	GenMySql = 0;

		fprintf(h,"\n\tpublic function OnCreate()\n\t{\n");
		fprintf(h,"\t$this->sqlbase->query(%cCREATE TABLE %c . $this->tablename . %c (",__QUOTE,__QUOTE,__QUOTE);
		for (i=0; i < fields; i++ ) {
			if ( i ) fprintf(h,", %s",check_sql_name(dptr->name[i]));
			else	 fprintf(h," %s",check_sql_name(dptr->name[i]));
			switch ( dptr->type[i] ) {
				case	_ABAL_BYTE	: fprintf(h," TINYINT"); break;
				case	_ABAL_WORD	: fprintf(h," SMALLINT"); break;
				case	_ABAL_LONG	: fprintf(h," INT"); break;
				case	_ABAL_BCD 	: fprintf(h," FLOAT(%u,%u)",((dptr->width[i]*2)-2),2); break;
				case	_ABAL_STRING	: 
					if ( dptr->width[i] > 255 )
						fprintf(h," TEXT(%u)",dptr->width[i]);
					else	fprintf(h," CHAR(%u)",dptr->width[i]);
					break;
				}
			if (( i < dptr->indexfields ) && ( dptr->indexfields == 1 )) {
				if (!( GenMySql ))
					fprintf(h," PRIMARY KEY");
				else	fprintf(h,",PRIMARY KEY(%s)",check_sql_name(dptr->name[i]));
				}
			}
		fprintf(h,")%c,$this->connection);\n",__QUOTE);
		fprintf(h,"\t}\n");
		fprintf(h,"\n\tpublic function OnDfile()\n\t{\n");
		fprintf(h,"\t$this->OnRemove();\n");
		fprintf(h,"\t}\n");
		fprintf(h,"\n\tpublic function OnCfile()\n\t{\n");
		fprintf(h,"\t$this->OnCreate();\n");
		fprintf(h,"\t}\n");
		fprintf(h,"\n\tpublic function OnAssign()\n\t{\n");
		fprintf(h,"\t}\n");
		fprintf(h,"\n\tpublic function OnRename()\n\t{\n");
		fprintf(h,"\t}\n");

		fprintf(h,"\n\tpublic function OnLink($linkdesc)\n\t{\n");
		fprintf(h,"\t}\n");

		fprintf(h,"\n\tpublic function OnClink()\n\t{\n");
		fprintf(h,"\t}\n");

		fprintf(h,"\n\tpublic function OnExportRecord($xfh)\n\t{\n");
			fprintf(h,"\t\tfprintf($xfh,%c<record>\\n%c);\n",__QUOTE,__QUOTE);
			for (i=0; i < fields; i++ ) {
				fprintf(h,"\t\tfprintf($xfh,%c<%s>%c);\n",__QUOTE,dptr->name[i],__QUOTE);
				fprintf(h,"\t\tfprintf($xfh,$this->_%s);\n",dptr->name[i]);
				fprintf(h,"\t\tfprintf($xfh,%c</%s>\\n%c);\n",__QUOTE,dptr->name[i],__QUOTE);
				}
			fprintf(h,"\t\tfprintf($xfh,%c</record>\\n%c);\n",__QUOTE,__QUOTE);
		fprintf(h,"\t}\n");

		fprintf(h,"\n\tpublic function OnExport($pnf)\n\t{\n");
			fprintf(h,"\t$xfh = fopen($pnf,%cw%c);\n",__QUOTE,__QUOTE);
			fprintf(h,"\tif (!( $xfh )) { $this->error = 46; return; }\n");
			fprintf(h,"\tfprintf($xfh, %c<file>\\n%c);\n",__QUOTE,__QUOTE);
			fprintf(h,"\t$this->OnFirst();\n");
			fprintf(h,"\twhile (( $this->error != 48 )\n");
			fprintf(h,"\t&&     ( $this->error != 78 ))\n");
			fprintf(h,"\t{\n");
			fprintf(h,"\t\t$this->OnExportRecord($xfh);\n");
			fprintf(h,"\t\t$this->OnDown();\n");
			fprintf(h,"\t}\n");
			fprintf(h,"\tfprintf($xfh,%c</file>\\n%c);\n",__QUOTE,__QUOTE);
			fprintf(h,"\tfclose($xfh);\n");
		fprintf(h,"\t}\n");

		fprintf(h,"\n\tprivate function start_tag($parser,$tag,$attributes)\n\t{\n");
			fprintf(h,"\t\tif ( strtolower($tag) == 'record' )\n");
			fprintf(h,"\t\t{\n");
				fprintf(h,"\t\t\tif ( $this->xrecords != 0 )\n");
				fprintf(h,"\t\t\t{\n");
				fprintf(h,"\t\t\t\t$this->OnInsert();\n");
				fprintf(h,"\t\t\t}\n");
				fprintf(h,"\t\t\t$this->OnReset();\n");
			fprintf(h,"\t\t}\n");
			fprintf(h,"\t\t$this->xrecords++;\n");
			fprintf(h,"\t\t$this->xmethod = strtolower($tag);\n");
		fprintf(h,"\t}\n");

		fprintf(h,"\n\tprivate function tag_data($xmlparser,$data)\n\t{\n");
			fprintf(h,"\t\tswitch ( $this->xmethod )\n");
			fprintf(h,"\t\t{\n");
			for (i=0; i < dptr->indexfields+dptr->datafields; i++ ) {
				fprintf(h,"\t\tcase '%s' : $this->_%s = $data; break; \n",
					strtolower(dptr->name[i]),dptr->name[i]);
				}
			fprintf(h,"\t\t}\n");
			fprintf(h,"\t\t$this->xmethod = NULL;\n");
		fprintf(h,"\t}\n");

		fprintf(h,"\n\tprivate function end_tag()\n\t{}\n");

		fprintf(h,"\n\tpublic function OnImport($xfilename)\n\t{\n");
			fprintf(h,"\t\t$this->xrecords=0;\n");
			fprintf(h,"\t\t$this->xmethod = NULL;\n");
			fprintf(h,"\t\t$this->xmlparser = xml_parser_create();\n");
			fprintf(h,"\t\txml_set_object($this->xmlparser, $this);\n");
			fprintf(h,"\t\txml_set_character_data_handler($this->xmlparser,'tag_data');\n");
			fprintf(h,"\t\txml_set_element_handler($this->xmlparser,'start_tag','end_tag');\n");
			fprintf(h,"\t\t$fp = fopen($xfilename, 'r');\n");
			fprintf(h,"\t\tif ( $fp != NULL )\n");
			fprintf(h,"\t\t{\n");
			fprintf(h,"\t\t\t$this->OnRemove();\n");
			fprintf(h,"\t\t\t$this->OnCreate();\n");
			fprintf(h,"\t\t\twhile ($xmldata = fread($fp, 4096))\n");
			fprintf(h,"\t\t\t\tif (!(xml_parse($this->xmlparser, $xmldata)))\n");
			fprintf(h,"\t\t\t\t\tbreak;\n");
			fprintf(h,"\t\t\tfclose($fp);\n");
			fprintf(h,"\t\t\t$this->OnInsert();\n");
			fprintf(h,"\t\t}\n");
			fprintf(h,"\t\txml_parser_free($this->xmlparser);\n");
			fprintf(h,"\t\t$this->xmlparser=NULL;\n");
		fprintf(h,"\t}\n");

		}
}

static	void	php_check_members( FILE *  h, struct form_control *  fptr, struct form_item * iptr, char * classname )
{
	int			fields=0;
	struct	data_control * 	dptr=(struct data_control *) 0;
	int			i;
	if (!(dptr = iptr->Contents.extra ))
		return;
	else if (!( fields = dptr->indexfields + dptr->datafields ))
		return;
	else	{
		fprintf(h,"\n\tpublic function OnCheck()\n\t{\n");
		for (i=0; i < fields; i++ ) {
			if ( dptr->type[i] == _ABAL_STRING ) {
				fprintf(h,"\t\tif ((!( $this->_%s )) || ( $this->_%s == %c%c )) { $this->_%s = %c %c; }\n",
					dptr->name[i],dptr->name[i],__QUOTE,__QUOTE,dptr->name[i],__QUOTE,__QUOTE);
				}
			}
		fprintf(h,"\t}\n");
		}
}

static	void	php_show_members( FILE *  h, struct form_control *  fptr, struct form_item * iptr, char * classname )
{
	int			fields=0;
	struct	data_control * 	dptr=(struct data_control *) 0;
	int			i;
	if (!(dptr = iptr->Contents.extra ))
		return;
	else if (!( fields = dptr->indexfields + dptr->datafields ))
		return;
	else	{
		fprintf(h,"\n\tpublic function OnShow($pmethodname)\n\t{\n");
		fprintf(h,"\t\tprint %c<tr><th colspan=2>%s%c . $pmethodname . %c</th></tr>\\n%c;\n",
			__QUOTE,classname,__QUOTE,__QUOTE,__QUOTE);

		fprintf(h,"\t\tprint %c<tr><th>error</th><td>%c . $this->error . %c</td></tr>\\n%c;\n",
			__QUOTE,__QUOTE,
			__QUOTE,__QUOTE
			);
		fprintf(h,"\t\tprint %c<tr><th>question</th><td>%c . $this->question . %c</td></tr>\\n%c;\n",
			__QUOTE,__QUOTE,
			__QUOTE,__QUOTE
			);
		fprintf(h,"\t\tprint %c<tr><th>response</th><td>%c . $this->response . %c</td></tr>\\n%c;\n",
			__QUOTE,__QUOTE,
			__QUOTE,__QUOTE
			);
		for (i=0; i < fields; i++ ) {
			fprintf(h,"\t\tprint %c<tr><th>%s</th><td>%c . $this->_%s . %c</td></tr>\\n%c;\n",
				__QUOTE,dptr->name[i],__QUOTE,dptr->name[i],
				__QUOTE,__QUOTE
				);
			}
		fprintf(h,"\t}\n");
		}
}

static	void	php_insert_table(FILE * h, struct form_control *  fptr, struct form_item * iptr, char * classname )
{
	int			fields=0;
	struct	data_control * 	dptr=(struct data_control *) 0;
	int			i;
	if (!(dptr = iptr->Contents.extra ))
		return;
	else if (!( fields = dptr->indexfields + dptr->datafields ))
		return;
	else	{
		fprintf(h,"\n\tpublic function OnInsert()\n\t{\n");
		fprintf(h,"\tif (!( $this->sqlbase->query(%cINSERT INTO %c . $this->tablename . %c (",__QUOTE,__QUOTE,__QUOTE);
		for (i=0; i < fields; i++ ) {
			if ( i ) fprintf(h,", %s",check_sql_name(dptr->name[i]));
			else	 fprintf(h," %s",check_sql_name(dptr->name[i]));
			}
		fprintf(h,")\n\tVALUES(");
		for (i=0; i < fields; i++ ) {
			if ( i ) fprintf(h,", '%c.$this->_%s.%c'",__QUOTE,dptr->name[i],__QUOTE);
			else	 fprintf(h," '%c.$this->_%s.%c'",__QUOTE,dptr->name[i],__QUOTE);
			}
		fprintf(h,")%c,$this->connection) )) { $this->error = 78; }\n",__QUOTE);
		fprintf(h,"\telse { $this->error = 0; }\n");
		fprintf(h,"\t}\n");
		}

}

static	void	php_first_table(FILE * h, struct form_control *  fptr, struct form_item * iptr, char * classname )
{
	int			fields=0;
	struct	data_control * 	dptr=(struct data_control *) 0;
	int			i;
	if (!(dptr = iptr->Contents.extra ))
		return;
	else if (!( fields = dptr->indexfields + dptr->datafields ))
		return;
	else	{
		fprintf(h,"\n\tpublic function OnFirst()\n\t{\n");
		if ( dptr->indexfields == 1 ) {
			fprintf(h,"\t$result = $this->sqlbase->query(%cSELECT MIN( %s ) AS %s",__QUOTE,dptr->name[0],dptr->name[0]);
			}
		else	{
			fprintf(h,"\t$result = $this->sqlbase->query(%cSELECT ",__QUOTE);
			for (i=0; i < dptr->indexfields; i++ ) {
				if ( i )
					fprintf(h,",");
				fprintf(h,"%s ",dptr->name[i]);
				}
			}
		fprintf(h," FROM %c . $this->tablename ",__QUOTE);
		if ( dptr->indexfields > 1 ) {
			fprintf(h,". %c WHERE ",__QUOTE);
			for (i=0; i < dptr->indexfields; i++ ) {
				if ( i )
					fprintf(h," AND ",dptr->name[i]);
				fprintf(h,"%s = (SELECT MIN( %s ) FROM %c . $this->tablename . %c )",
					dptr->name[i],dptr->name[i],__QUOTE,__QUOTE);
				}
			fprintf(h,"%c",__QUOTE);
			}
		fprintf(h,", $this->connection);\n",__QUOTE);
		fprintf(h,"\tif (!($row = $this->sqlbase->fetch($result))) { $this->error = 48; }\n");
		fprintf(h,"\telse\t{\n");
		for (i=0; i < dptr->indexfields; i++ ) {
			fprintf(h,"\t\t$this->_%s = $row['%s'];\n",dptr->name[i],check_sql_name(dptr->name[i]));
			}
		fprintf(h,"\t\t$this->OnSearch();\n");
		fprintf(h,"\t\t}\n");

		fprintf(h,"\t}\n");
		}

}

static	void	php_last_table(FILE * h, struct form_control *  fptr, struct form_item * iptr, char * classname )
{
	int			fields=0;
	struct	data_control * 	dptr=(struct data_control *) 0;
	int			i;
	if (!(dptr = iptr->Contents.extra ))
		return;
	else if (!( fields = dptr->indexfields + dptr->datafields ))
		return;
	else	{
		fprintf(h,"\n\tpublic function OnLast()\n\t{\n");
		if ( dptr->indexfields == 1 ) {
			fprintf(h,"\t$result = $this->sqlbase->query(%cSELECT MAX( %s ) AS %s",__QUOTE,dptr->name[0],dptr->name[0]);
			}
		else	{
			fprintf(h,"\t$result = $this->sqlbase->query(%cSELECT ",__QUOTE);
			for (i=0; i < dptr->indexfields; i++ ) {
				if ( i )
					fprintf(h,",");
				fprintf(h,"%s ",dptr->name[i]);
				}
			}
		fprintf(h," FROM %c . $this->tablename ",__QUOTE);
		if ( dptr->indexfields > 1 ) {
			fprintf(h,". %c WHERE ",__QUOTE);
			for (i=0; i < dptr->indexfields; i++ ) {
				if ( i )
					fprintf(h," AND ",dptr->name[i]);
				fprintf(h,"%s = (SELECT MAX( %s ) FROM %c . $this->tablename . %c )",
					dptr->name[i],dptr->name[i],__QUOTE,__QUOTE);
				}
			fprintf(h,"%c",__QUOTE);
			}
		fprintf(h,", $this->connection);\n",__QUOTE);
		fprintf(h,"\tif (!($row = $this->sqlbase->fetch($result))) { $this->error = 48; }\n");
		fprintf(h,"\telse\t{\n");
		for (i=0; i < dptr->indexfields; i++ ) {
			fprintf(h,"\t\t$this->_%s = $row['%s'];\n",dptr->name[i],check_sql_name(dptr->name[i]));
			}
		fprintf(h,"\t\t$this->OnSearch();\n");
		fprintf(h,"\t\t}\n");
		fprintf(h,"\t}\n");
		}

}

static	void	php_down_table(FILE * h, struct form_control *  fptr, struct form_item * iptr, char * classname )
{
	int			fields=0;
	struct	data_control * 	dptr=(struct data_control *) 0;
	int			i;
	if (!(dptr = iptr->Contents.extra ))
		return;
	else if (!( fields = dptr->indexfields + dptr->datafields ))
		return;
	else	{
		fprintf(h,"\n\tpublic function OnDown()\n\t{\n");
		fprintf(h,"\t$result = $this->sqlbase->query(%cSELECT * FROM %c . $this->tablename . %c ",__QUOTE,__QUOTE,__QUOTE);
		fprintf(h,"WHERE");
		for (i=0; i < dptr->indexfields; i++ ) {
			if ( i ) fprintf(h," AND %s > '%c.$this->_%s.%c'",dptr->name[i],__QUOTE,dptr->name[i],__QUOTE);
			else	 fprintf(h," %s > '%c.$this->_%s.%c'",dptr->name[i],__QUOTE,dptr->name[i],__QUOTE);
			}
		fprintf(h,"ORDER BY");
		for (i=0; i < dptr->indexfields; i++ ) {
			if ( i ) fprintf(h,", %s",dptr->name[i]);
			else	 fprintf(h,"  %s",dptr->name[i]);
			}
		fprintf(h,"%c,$this->connection);\n",__QUOTE);
		fprintf(h,"\tif (!($row = $this->sqlbase->fetch($result))) { $this->error = 48; }\n");
		fprintf(h,"\telse\t{\n");
		for (i=0; i < fields; i++ ) {
			fprintf(h,"\t\t$this->_%s = $row['%s'];\n",dptr->name[i],check_sql_name(dptr->name[i]));
			}
		fprintf(h,"\t\t}\n");
		fprintf(h,"\t}\n");
		}

}

static	void	php_up_table(FILE * h, struct form_control *  fptr, struct form_item * iptr, char * classname )
{
	int			fields=0;
	struct	data_control * 	dptr=(struct data_control *) 0;
	int			i;
	if (!(dptr = iptr->Contents.extra ))
		return;
	else if (!( fields = dptr->indexfields + dptr->datafields ))
		return;
	else	{
		fprintf(h,"\n\tpublic function OnUp()\n\t{\n");
		fprintf(h,"\t$result = $this->sqlbase->query(%cSELECT * FROM %c . $this->tablename . %c ",__QUOTE,__QUOTE,__QUOTE);
		fprintf(h,"WHERE");
		for (i=0; i < dptr->indexfields; i++ ) {
			if ( i ) fprintf(h," AND %s < '%c.$this->_%s.%c'",dptr->name[i],__QUOTE,dptr->name[i],__QUOTE);
			else	 fprintf(h," %s < '%c.$this->_%s.%c'",dptr->name[i],__QUOTE,dptr->name[i],__QUOTE);
			}
		fprintf(h,"ORDER BY");
		for (i=0; i < dptr->indexfields; i++ ) {
			if ( i ) fprintf(h,", %s",dptr->name[i]);
			else	 fprintf(h,"  %s",dptr->name[i]);
			}
		fprintf(h," DESC %c,$this->connection);\n",__QUOTE);
		fprintf(h,"\tif (!($row = $this->sqlbase->fetch($result))) { $this->error = 64; }\n");
		fprintf(h,"\telse\t{\n");
		for (i=0; i < fields; i++ ) {
			fprintf(h,"\t\t$this->_%s = $row['%s'];\n",dptr->name[i],check_sql_name(dptr->name[i]));
			}
		fprintf(h,"\t\t}\n");
		fprintf(h,"\t}\n");
		}

}

static	void	php_count_table(FILE * h, struct form_control *  fptr, struct form_item * iptr, char * classname )
{
	int			fields=0;
	struct	data_control * 	dptr=(struct data_control *) 0;
	int			i;
	if (!(dptr = iptr->Contents.extra ))
		return;
	else if (!( fields = dptr->indexfields + dptr->datafields ))
		return;
	else	{
		fprintf(h,"\n\tpublic function OnCount()\n\t{\n");
		fprintf(h,"\t$this->error=56;\n");
		fprintf(h,"\t}\n");
		}

}

static	void	php_posit_table(FILE * h, struct form_control *  fptr, struct form_item * iptr, char * classname )
{
	int			fields=0;
	struct	data_control * 	dptr=(struct data_control *) 0;
	int			i;
	if (!(dptr = iptr->Contents.extra ))
		return;
	else if (!( fields = dptr->indexfields + dptr->datafields ))
		return;
	else	{
		fprintf(h,"\n\tpublic function OnPosit()\n\t{\n");
		fprintf(h,"\t$this->error=56;\n");
		fprintf(h,"\t}\n");
		}

}

static	void	php_collect_table(FILE * h, struct form_control *  fptr, struct form_item * iptr, char * classname )
{
	int			fields=0;
	struct	data_control * 	dptr=(struct data_control *) 0;
	int			i;
	if (!(dptr = iptr->Contents.extra ))
		return;
	else if (!( fields = dptr->indexfields + dptr->datafields ))
		return;
	else	{
		fprintf(h,"\n\tpublic function OnCollect()\n\t{\n");
		fprintf(h,"\t$this->response = 0;\n");
		fprintf(h,"\t$this->collection = array();\n");
		fprintf(h,"\t$result = $this->sqlbase->query(%cSELECT ",__QUOTE);
		for (i=0; i < dptr->indexfields; i++ ) {
			if ( i )  fprintf(h,", ");
			fprintf(h,"%s",check_sql_name(dptr->name[i]));
			}
		fprintf(h," FROM %c . $this->tablename . %c ",__QUOTE,__QUOTE);
		fprintf(h,"WHERE %c . $this->question, $this->connection);\n",__QUOTE);
		fprintf(h,"\twhile (($row = $this->sqlbase->fetch($result)) != NULL) { \n");
		if ( dptr->indexfields > 1 ) {
			fprintf(h,"\t\t$this->collection[$this->response] = $row;\n");
			}
		else	{
			fprintf(h,"\t\t$this->collection[$this->response] = $row['%s'];\n",dptr->name[0]);
			}
		fprintf(h,"\t\t$this->response++;\n");
		fprintf(h,"\t\t}\n");
		fprintf(h,"\t}\n");
		}

}

static	void	php_distinct_table(FILE * h, struct form_control *  fptr, struct form_item * iptr, char * classname )
{
	int			fields=0;
	struct	data_control * 	dptr=(struct data_control *) 0;
	int			i;
	if (!(dptr = iptr->Contents.extra ))
		return;
	else if (!( fields = dptr->indexfields + dptr->datafields ))
		return;
	else	{
		fprintf(h,"\n\tpublic function OnDistinct($field=\"");
		for (i=0; i < dptr->indexfields; i++ ) 
		{
			if ( i )  fprintf(h,",");
			fprintf(h,"%s",check_sql_name(dptr->name[i]));
		}
		fprintf(h,"\")\n\t{\n");
		fprintf(h,"\t$this->response = 0;\n");
		fprintf(h,"\t$this->collection = array();\n");
		fprintf(h,"\t$result = $this->sqlbase->query(%cSELECT Distinct %c.$field.%c",__QUOTE,__QUOTE,__QUOTE);
		fprintf(h," FROM %c . $this->tablename . %c ",__QUOTE,__QUOTE);
		fprintf(h,"WHERE %c . $this->question, $this->connection);\n",__QUOTE);
		fprintf(h,"\twhile (($row = $this->sqlbase->fetch($result)) != NULL) { \n");
		if ( dptr->indexfields > 1 ) 
		{
			fprintf(h,"\t\t$this->collection[$this->response] = $row;\n");
		}
		else	
		{
			fprintf(h,"\t\t$this->collection[$this->response] = $row[$field];\n",dptr->name[0]);
		}
		fprintf(h,"\t\t$this->response++;\n");
		fprintf(h,"\t\t}\n");
		fprintf(h,"\t}\n");
		}

}

static	void	php_locate_table(FILE * h, struct form_control *  fptr, struct form_item * iptr, char * classname )
{
	int			fields=0;
	struct	data_control * 	dptr=(struct data_control *) 0;
	int			i;
	if (!(dptr = iptr->Contents.extra ))
		return;
	else if (!( fields = dptr->indexfields + dptr->datafields ))
		return;
	else	{
		fprintf(h,"\n\tpublic function OnLocate($n)\n\t{\n");
		fprintf(h,"\tif ( $n > $this->response ) { $this->error=103; }\n");
		fprintf(h,"\telse if ( $n <= 0 ) { $this->error=102; }\n");
		fprintf(h,"\telse { \n");
		if ( dptr->indexfields > 1 ) {
			fprintf(h,"\t\t$row = $this->collection[$n-1];\n");
			for (i=0; i < dptr->indexfields; i++ ) {
				fprintf(h,"\t\t$this->_%s = $row['%s'];\n",dptr->name[i],check_sql_name(dptr->name[i]));
				}
			}
		else	{
			fprintf(h,"\t\t$this->_%s = $this->collection[$n-1];\n",dptr->name[0]);
			}
		fprintf(h,"\t\t$this->OnSearch();\n");
		fprintf(h,"\t\t}\n");
		fprintf(h,"\t}\n");
		}

}

static	void	php_update_table(FILE * h, struct form_control *  fptr, struct form_item * iptr, char * classname )
{
	int			fields=0;
	struct	data_control * 	dptr=(struct data_control *) 0;
	int			i;
	if (!(dptr = iptr->Contents.extra ))
		return;
	else if (!( fields = dptr->indexfields + dptr->datafields ))
		return;
	else	{
		fprintf(h,"\n\tpublic function OnUpdate()\n\t{\n");
			fprintf(h,"\t\t$this->OnInsert();\n");
			fprintf(h,"\t\tif ( $this->error == 78 ) { $this->OnModif(); }\n");
		fprintf(h,"\t}\n");


		fprintf(h,"\n\tpublic function OldOnUpdate()\n\t{\n");
			
		fprintf(h,"\t$this->sqlbase->query(%cUPDATE %c . $this->tablename . %c SET",__QUOTE,__QUOTE,__QUOTE);
		for (i=dptr->indexfields; i < fields; i++ ) {
			if ( i > dptr->indexfields  ) fprintf(h,", %s = '%c.$this->_%s.%c'",check_sql_name(dptr->name[i]),__QUOTE,dptr->name[i],__QUOTE);
			else	 fprintf(h," %s = '%c.$this->_%s.%c'",check_sql_name(dptr->name[i]),__QUOTE,dptr->name[i],__QUOTE);
			}
		fprintf(h,"\n\tWHERE");
		for (i=0; i < dptr->indexfields; i++ ) {
			if ( i ) fprintf(h," AND %s = '%c.$this->_%s.%c'",check_sql_name(dptr->name[i]),__QUOTE,dptr->name[i],__QUOTE);
			else	 fprintf(h," %s = '%c.$this->_%s.%c'",check_sql_name(dptr->name[i]),__QUOTE,dptr->name[i],__QUOTE);
			}
		fprintf(h,"%c,$this->connection);\n",__QUOTE);
		fprintf(h,"\t}\n");
		}

}

static	void	php_modif_table(FILE * h, struct form_control *  fptr, struct form_item * iptr, char * classname )
{
	int			fields=0;
	struct	data_control * 	dptr=(struct data_control *) 0;
	int			i;
	if (!(dptr = iptr->Contents.extra ))
		return;
	else if (!( fields = dptr->indexfields + dptr->datafields ))
		return;
	else	{
		fprintf(h,"\n\tpublic function OnModif()\n\t{\n");
		fprintf(h,"\t$this->sqlbase->query(%cUPDATE %c . $this->tablename . %c SET",__QUOTE,__QUOTE,__QUOTE);
		for (i=dptr->indexfields; i < fields; i++ ) {
			if ( i > dptr->indexfields ) fprintf(h,", %s = '%c.$this->_%s.%c'",check_sql_name(dptr->name[i]),__QUOTE,dptr->name[i],__QUOTE);
			else	 fprintf(h," %s = '%c.$this->_%s.%c'",check_sql_name(dptr->name[i]),__QUOTE,dptr->name[i],__QUOTE);
			}
		fprintf(h,"\n\tWHERE");
		for (i=0; i < dptr->indexfields; i++ ) {
			if ( i ) fprintf(h," AND %s = '%c.$this->_%s.%c'",check_sql_name(dptr->name[i]),__QUOTE,dptr->name[i],__QUOTE);
			else	 fprintf(h," %s = '%c.$this->_%s.%c'",check_sql_name(dptr->name[i]),__QUOTE,dptr->name[i],__QUOTE);
			}
		fprintf(h,"%c,$this->connection);\n",__QUOTE);
		fprintf(h,"\t}\n");
		}

}

static	void	php_delete_table(FILE * h, struct form_control *  fptr, struct form_item * iptr, char * classname )
{
	int			fields=0;
	struct	data_control * 	dptr=(struct data_control *) 0;
	int			i;
	if (!(dptr = iptr->Contents.extra ))
		return;
	else if (!( fields = dptr->indexfields + dptr->datafields ))
		return;
	else	{
		fprintf(h,"\n\tpublic function OnDelete()\n\t{\n");
		fprintf(h,"\t$this->sqlbase->query(%cDELETE FROM %c . $this->tablename . %c ",__QUOTE,__QUOTE,__QUOTE);
		fprintf(h,"WHERE");
		for (i=0; i < dptr->indexfields; i++ ) {
			if ( i ) fprintf(h," AND %s = '%c.$this->_%s.%c'",dptr->name[i],__QUOTE,dptr->name[i],__QUOTE);
			else	 fprintf(h," %s = '%c.$this->_%s.%c'",dptr->name[i],__QUOTE,dptr->name[i],__QUOTE);
			}
		fprintf(h,"%c,$this->connection);\n",__QUOTE);
		fprintf(h,"\t}\n");
		}

}

static	void	php_search_table(FILE * h, struct form_control *  fptr, struct form_item * iptr, char * classname )
{
	int			fields=0;
	struct	data_control * 	dptr=(struct data_control *) 0;
	int			i;
	if (!(dptr = iptr->Contents.extra ))
		return;
	else if (!( fields = dptr->indexfields + dptr->datafields ))
		return;
	else	{
		fprintf(h,"\n\tpublic function OnSearch()\n\t{\n");
		fprintf(h,"\t$result = $this->sqlbase->query(%cSELECT * FROM %c . $this->tablename . %c ",__QUOTE,__QUOTE,__QUOTE);
		fprintf(h,"WHERE");
		for (i=0; i < dptr->indexfields; i++ ) {
			if ( i ) fprintf(h," AND %s = '%c.$this->_%s.%c'",check_sql_name(dptr->name[i]),__QUOTE,dptr->name[i],__QUOTE);
			else	 fprintf(h," %s = '%c.$this->_%s.%c'",check_sql_name(dptr->name[i]),__QUOTE,dptr->name[i],__QUOTE);
			}
		fprintf(h,"%c,$this->connection);\n",__QUOTE);
		fprintf(h,"\tif (!($row = $this->sqlbase->fetch($result))) { $this->error = 78; }\n");
		fprintf(h,"\telse\t{\n");
		fprintf(h,"\t\t$this->error = 0;\n");
		for (i=dptr->indexfields; i < fields; i++ ) {
			fprintf(h,"\t\t$this->_%s = $row['%s'];\n",dptr->name[i],check_sql_name(dptr->name[i]));
			}
		fprintf(h,"\t\t}\n");
		fprintf(h,"\t}\n");
		}

}

static	void	php_select_table(FILE * h, struct form_control *  fptr, struct form_item * iptr, char * classname )
{
	int			fields=0;
	struct	data_control * 	dptr=(struct data_control *) 0;
	int			i;
	if (!(dptr = iptr->Contents.extra ))
		return;
	else if (!( fields = dptr->indexfields + dptr->datafields ))
		return;
	else	{
		fprintf(h,"\n\tpublic function OnSelect()\n\t{\n");
		fprintf(h,"\t$result = $this->sqlbase->query(%cSELECT * FROM %c . $this->tablename . %c ",__QUOTE,__QUOTE,__QUOTE);
		fprintf(h,"WHERE %c . $this->question, $this->connection);\n",__QUOTE);
		fprintf(h,"\tif (!($row = $this->sqlbase->fetch($result))) { $this->error = 78; }\n");
		fprintf(h,"\telse\t{\n");
		fprintf(h,"\t\t$this->error = 0;\n");
		for (i=dptr->indexfields; i < fields; i++ ) {
			fprintf(h,"\t\t$this->_%s = $row['%s'];\n",dptr->name[i],dptr->name[i]);
			}
		fprintf(h,"\t\t}\n");
		fprintf(h,"\t}\n");
		}

}

public	void	php_generate_database_class( char * fnptr, char * classname, struct form_control * fptr , struct form_item * iptr )
{
	FILE * fh;

	if (!( fh = fopen(fnptr,"w") )) {
		liberate( fnptr );
		return;
		}
	else	{
		liberate( fnptr );
		php_start( fh );
		php_open_exclusion(fh,classname);		
		php_require(fh, "sing/database.inc" );
		php_class( fh, classname );		
		php_class_members( fh,fptr,iptr, classname );
		php_reset_table(fh,fptr,iptr,classname);
		php_create_table(fh,fptr,iptr,classname);
		php_check_members(fh,fptr,iptr,classname);
		php_show_members(fh,fptr,iptr,classname);
		php_insert_table(fh,fptr,iptr,classname);
		php_modif_table(fh,fptr,iptr,classname);
		php_update_table(fh,fptr,iptr,classname);
		php_delete_table(fh,fptr,iptr,classname);
		php_search_table(fh,fptr,iptr,classname);
		php_select_table(fh,fptr,iptr,classname);
		php_first_table(fh,fptr,iptr,classname);
		php_last_table(fh,fptr,iptr,classname);
		php_down_table(fh,fptr,iptr,classname);
		php_up_table(fh,fptr,iptr,classname);
		php_posit_table(fh,fptr,iptr,classname);
		php_count_table(fh,fptr,iptr,classname);
		php_collect_table(fh,fptr,iptr,classname);
		php_distinct_table(fh,fptr,iptr,classname);
		php_locate_table(fh,fptr,iptr,classname);
		php_endclass( fh, classname );		
		php_close_exclusion(fh,classname);		
		php_end( fh );		
		fclose( fh );
		return;
		}
}

static	void	php_database(FILE * h, struct form_control *  fptr, struct form_item * iptr, char * classname, char * pptr )
{
	FILE *	fh;
	char	cname[512];
	char *	fnptr=(char *) 0;
	char *	pnptr=(char *) 0;

	sprintf(cname,"%s%s",classname,INC_EXTENSION);

	if (!( fnptr = allocate_string( cname )))
		return;
	else if ((pnptr = extract_path( pptr )) != (char *) 0) {
		fnptr = path_prefix( fnptr, pnptr );
		liberate( pnptr );
		if (!( fnptr ))
			return;
		}

	php_require(h, cname );

	php_generate_database_class( fnptr, classname, fptr, iptr );
	return;
}

public	void	php_session( FILE * h, char * sessionname )
{
	if ( sessionname ) {
		fprintf(h,"\tsession_name(%c%s%c);\n",__QUOTE,sessionname,__QUOTE);
		}		
	fprintf(h,"\tsession_start();\n");
	return;
}
	
public	void	php_start_soap(FILE * h)
{
	fprintf(h,"\trequire(%csing/soaparser%s%c);\n",__QUOTE,INC_EXTENSION,__QUOTE);
	fprintf(h,"\t$xsp = new SoapParser;\n");
	return;
}

static	void	php_start_stream(FILE * h, struct form_control *  fptr, struct form_item * iptr, char * classname ,char * pptr )
{
	if ( h ) {
		php_start(h);
		php_start_soap(h);
		php_database( h, fptr, iptr, classname, pptr );
		// ----------------------------------------
		// this , now takes the database and table 
		// names as construction parameters
		// ----------------------------------------
		fprintf(h,"\t$%s = new %s(%c%s%c,%c%s%c);\n",php_widget_name(iptr),classname,
			__QUOTE,classname,__QUOTE,
			__QUOTE,classname,__QUOTE);
		}
	return;
}

void	php_instance_data(FILE * h, struct form_control *  fptr, struct form_item * iptr, char * classname )
{
	int			fields=0;
	struct	data_control * 	dptr=(struct data_control *) 0;
	int			i;
	if (!(dptr = iptr->Contents.extra ))
		return;
	else if (!( fields = dptr->indexfields + dptr->datafields ))
		return;
	else	{
		fprintf(h,"\t// ------------- \n");
		fprintf(h,"\t// control value \n");
		fprintf(h,"\t// ------------- \n");
		fprintf(h,"\t$soaptempfile = 0;\n");
		fprintf(h,"\t$soapfilename = %c%c;\n",__QUOTE,__QUOTE);
		fprintf(h,"\t$soapfilemethods = $names = array(%ctns:%sFirst%c=>0,%ctns:%sDown%c=>0,%ctns:%sSearch%c=>0,%ctns:%sSelect%c,%ctns:%sUp%c=>0,%ctns:%sLast%c=>0,%ctns:%sInsert%c=>1,%ctns:%sModif%c=>1,%ctns:%sUpdate%c=>1,%ctns:%sDelete%c=>1,%ctns:%sPosit%c=>0,%ctns:%sCount%c=>0,%ctns:%sCreate%c=>0,%ctns:%sRemove%c=>0,%ctns:%sNew%c=>0);\n",
			__QUOTE,classname,__QUOTE,	__QUOTE,classname,__QUOTE,
			__QUOTE,classname,__QUOTE,	__QUOTE,classname,__QUOTE,	__QUOTE,classname,__QUOTE,
			__QUOTE,classname,__QUOTE,	__QUOTE,classname,__QUOTE,	__QUOTE,classname,__QUOTE,
			__QUOTE,classname,__QUOTE,	__QUOTE,classname,__QUOTE,	__QUOTE,classname,__QUOTE,
			__QUOTE,classname,__QUOTE,	__QUOTE,classname,__QUOTE,	__QUOTE,classname,__QUOTE,
			__QUOTE,classname,__QUOTE);
		fprintf(h,"\tforeach ( $_FILES as $first ) ");
		fprintf(h,"{ $soapfilename = $first[%ctmp_name%c]; break; }\n",__QUOTE,__QUOTE);
		fprintf(h,"\tif ( $soapfilename == %c%c)\n",__QUOTE,__QUOTE);
		fprintf(h,"\t{\n");
			fprintf(h,"\t\t$rdata = implode('',file(%cphp://input%c));\n",__QUOTE,__QUOTE);
			fprintf(h,"\t\t$soapfilename = tempnam(%c/home/soap/%c,%cxphp%c);\n",__QUOTE,__QUOTE,__QUOTE,__QUOTE);
			fprintf(h,"\t\t$thand = fopen($soapfilename,%cw%c);\n",__QUOTE,__QUOTE);
			fprintf(h,"\t\tfwrite($thand,$rdata,strlen($rdata));\n");
			fprintf(h,"\t\tfclose($thand);\n");
			fprintf(h,"\t\t$soaptempfile = 1;\n");
		fprintf(h,"\t} else { header('Content-Type: text/plain'); }\n");
		return;
		}
}

static	void	php_request_data(FILE * h, struct form_control *  fptr, struct form_item * iptr )
{
	int			fields=0;
	struct	data_control * 	dptr=(struct data_control *) 0;
	int			i;
	if (!(dptr = iptr->Contents.extra ))
		return;
	else if (!( fields = dptr->indexfields + dptr->datafields ))
		return;
	else	{
		fprintf(h,"\t// ----------------------- \n");
		fprintf(h,"\t// process request message \n");
		fprintf(h,"\t// ----------------------- \n");
		fprintf(h,"\t$xsp->ParseFile($soapfilename,$soapfilemethods);\n");
		fprintf(h,"\t$%s->question = $xsp->parameters['question'];\n",php_use_widget_name(iptr));
		for (i=0; i < fields; i++ )
			fprintf(h,"\t$%s->_%s = $xsp->parameters['%s'];\n",php_use_widget_name(iptr),dptr->name[i],dptr->name[i]);
		fprintf(h,"\t$%s->OnCheck();\n",php_use_widget_name(iptr));
		return;
		}
}

static	void	php_debug_header(FILE * h)
{
	fprintf(h,"print %c<html><head><title>webservice method:%c . $xsm->method . %c</title></head><body>\\n%c;\n",__QUOTE,__QUOTE,__QUOTE,__QUOTE);
	fprintf(h,"print %c<div align=center><table border=1 width=400>%c;\n",__QUOTE,__QUOTE);
	return;
}

static	void	php_debug_footer(FILE * h)
{
	fprintf(h,"print %c</tr></table></div>\\n%c;\n",__QUOTE,__QUOTE);
	fprintf(h,"print %c</body></html>\\n%c;\n",__QUOTE,__QUOTE);
	return;
}

static	void	php_debug_method(FILE * h, struct form_control *  fptr, struct form_item * iptr, char * classname )
{
	int			fields=0;
	struct	data_control * 	dptr=(struct data_control *) 0;
	int			i;
	if (!(dptr = iptr->Contents.extra ))
		return;
	else if (!( fields = dptr->indexfields + dptr->datafields ))
		return;
	else	{

		fprintf(h,"print %c<tr><th colspan=2>%s%c . $xsp->method . %c</th></tr>\\n%c;\n",
			__QUOTE,classname,__QUOTE,__QUOTE,__QUOTE);

		fprintf(h,"print %c<tr><th>error</th><td>%c . $%s->error . %c</td></tr>\\n%c;\n",
			__QUOTE,__QUOTE,php_use_widget_name(iptr),
			__QUOTE,__QUOTE
			);
		fprintf(h,"print %c<tr><th>question</th><td>%c . $%s->question . %c</td></tr>\\n%c;\n",
			__QUOTE,__QUOTE,php_use_widget_name(iptr),
			__QUOTE,__QUOTE
			);
		fprintf(h,"print %c<tr><th>response</th><td>%c . $%s->response . %c</td></tr>\\n%c;\n",
			__QUOTE,__QUOTE,php_use_widget_name(iptr),
			__QUOTE,__QUOTE
			);

		for (i=0; i < fields; i++ ) {
			fprintf(h,"print %c<tr><th>%s</th><td>%c . $%s->_%s . %c</td></tr>\\n%c;\n",
				__QUOTE,dptr->name[i],__QUOTE,php_widget_name(iptr),dptr->name[i],
				__QUOTE,__QUOTE
				);
			}

		return;
		}
}

static	void	php_request_method(FILE * h, struct form_control *  fptr, struct form_item * iptr, char * classname )
{
	fprintf(h,"\t// ----------------------- \n");
	fprintf(h,"\t// process request methode \n");
	fprintf(h,"\t// ----------------------- \n");
	fprintf(h,"\tif ( $xsp->method == 'tns:%sFirst' ) {\n",classname);
	fprintf(h,"\t\t$%s->OnFirst();\n",php_use_widget_name(iptr));
	fprintf(h,"\t} else  if ( $xsp->method == 'tns:%sDown' ) {\n",classname);
	fprintf(h,"\t\t$%s->OnDown();\n",php_use_widget_name(iptr));
	fprintf(h,"\t} else  if ( $xsp->method == 'tns:%sSearch' ) {\n",classname);
	fprintf(h,"\t\t$%s->OnSearch();\n",php_use_widget_name(iptr));
	fprintf(h,"\t} else  if ( $xsp->method == 'tns:%sSelect' ) {\n",classname);
	fprintf(h,"\t\t$%s->OnSelect();\n",php_use_widget_name(iptr));
	fprintf(h,"\t} else  if ( $xsp->method == 'tns:%sUp' ) {\n",classname);
	fprintf(h,"\t\t$%s->OnUp();\n",php_use_widget_name(iptr));
	fprintf(h,"\t} else  if ( $xsp->method == 'tns:%sLast' ) {\n",classname);
	fprintf(h,"\t\t$%s->OnLast();\n",php_use_widget_name(iptr));
	fprintf(h,"\t} else  if ( $xsp->method == 'tns:%sInsert' ) {\n",classname);
	fprintf(h,"\t\t$%s->OnInsert();\n",php_use_widget_name(iptr));
	fprintf(h,"\t} else  if ( $xsp->method == 'tns:%sModif' ) {\n",classname);
	fprintf(h,"\t\t$%s->OnModif();\n",php_use_widget_name(iptr));
	fprintf(h,"\t} else  if ( $xsp->method == 'tns:%sUpdate' ) {\n",classname);
	fprintf(h,"\t\t$%s->OnUpdate();\n",php_use_widget_name(iptr));
	fprintf(h,"\t} else  if ( $xsp->method == 'tns:%sDelete' ) {\n",classname);
	fprintf(h,"\t\t$%s->OnDelete();\n",php_use_widget_name(iptr));
	fprintf(h,"\t} else  if ( $xsp->method == 'tns:%sPosit' ) {\n",classname);
	fprintf(h,"\t\t$%s->OnPosit();\n",php_use_widget_name(iptr));
	fprintf(h,"\t} else  if ( $xsp->method == 'tns:%sCount' ) {\n",classname);
	fprintf(h,"\t\t$%s->OnCount();\n",php_use_widget_name(iptr));
	fprintf(h,"\t} else  if ( $xsp->method == 'tns:%sCollect' ) {\n",classname);
	fprintf(h,"\t\t$%s->OnCollect();\n",php_use_widget_name(iptr));
	fprintf(h,"\t} else  if ( $xsp->method == 'tns:%sDistinct' ) {\n",classname);
	fprintf(h,"\t\t$%s->OnDistinct();\n",php_use_widget_name(iptr));
	fprintf(h,"\t} else  if ( $xsp->method == 'tns:%sLocate' ) {\n",classname);
	fprintf(h,"\t\t$%s->OnLocate(1);\n",php_use_widget_name(iptr));
	fprintf(h,"\t} else  if ( $xsp->method == 'tns:%sCreate' ) {\n",classname);
	fprintf(h,"\t\t$%s->OnCreate();\n",php_use_widget_name(iptr));
	fprintf(h,"\t} else  if ( $xsp->method == 'tns:%sRemove' ) {\n",classname);
	fprintf(h,"\t\t$%s->OnRemove();\n",php_use_widget_name(iptr));
	fprintf(h,"\t} else  if ( $xsp->method == 'tns:%sNew' ) {\n",classname);
	fprintf(h,"\t\t$%s->OnNew();\n",php_use_widget_name(iptr));
	fprintf(h,"\t}\n");
	return;
}

static	void	php_response_data(FILE * h, struct form_control *  fptr, struct form_item * iptr )
{
	int			fields=0;
	struct	data_control * 	dptr=(struct data_control *) 0;
	int			i;
	if (!(dptr = iptr->Contents.extra ))
		return;
	else if (!( fields = dptr->indexfields + dptr->datafields ))
		return;
	else	{
		fprintf(h,"\t// ------------------------ \n");
		fprintf(h,"\t// produce response message \n");
		fprintf(h,"\t// ------------------------ \n");
		fprintf(h,"\t$xsp->IntegerParameter( 'response', $%s->response );\n",php_use_widget_name(iptr));
		fprintf(h,"\t$xsp->IntegerParameter( 'error', $%s->error );\n",php_use_widget_name(iptr));
		for (i=0; i < fields; i++ ) {
			switch ( dptr->type[i] ) {
				case	_ABAL_BYTE	:
				case	_ABAL_WORD	:
				case	_ABAL_LONG	:
					fprintf(h,"\t$xsp->IntegerParameter('%s',$%s->_%s);\n",dptr->name[i],php_use_widget_name(iptr),dptr->name[i]);
					break;
				case	_ABAL_BCD	:
					fprintf(h,"\t$xsp->FloatParameter('%s',$%s->_%s);\n",dptr->name[i],php_use_widget_name(iptr),dptr->name[i]);
					break;
				case	_ABAL_STRING	:
					fprintf(h,"\t$xsp->StringParameter('%s',$%s->_%s);\n",dptr->name[i],php_use_widget_name(iptr),dptr->name[i]);
					break;
				}
			}
		fprintf(h,"\t$xsp->Serialise();\n");
		fprintf(h,"\tif ( $soaptempfile != 0 ) { unlink($soapfilename); $soaptempfile=0; }\n");
		return;
		}
}

static	void	php_close_stream( FILE * h, struct form_control *  fptr )
{
	if ( h ) {
		php_end(h);
		}
	return;
}

static	void	php_soap_server   (FILE * h, struct form_control *  fptr, struct form_item * iptr, char * classname, char * pptr)
{
	php_start_stream(h, fptr,iptr,classname, pptr );
	php_instance_data(h,fptr,iptr,classname);
	php_request_data(h,fptr,iptr);
	php_request_method(h,fptr,iptr,classname);
	php_response_data(h,fptr,iptr);
	php_close_stream( h, fptr );
	return;
}

#define	_MAX_METHOD_NAMES	16

static	void	generate_xml_message(struct form_control *  fptr, struct form_item * iptr, char * classname , char * nptr)
{
	FILE	*		h=(FILE *) 0;
	char	*		sptr=(char *) 0;
	int			i;
	int			fields=0;
	int			methods;
	char	*		mname;
	char			xbuffer[64];
	char 	*		methodname[_MAX_METHOD_NAMES] = {
		"Create","First", "Down", "Up",
		"Last",	 "Insert","Modif","Search","New",
		"Delete","Update","Posit","Count","Collect","Locate","Remove"
		};

	struct	data_control * 	dptr=(struct data_control *) 0;

	if (!(dptr = iptr->Contents.extra ))
		return;
	else if (!( fields = dptr->indexfields + dptr->datafields ))
		return;
	else	{
		for ( methods=0; methods < _MAX_METHOD_NAMES; methods++ ) {

			if (!( mname = methodname[methods] ))
				break;
			else	sprintf(xbuffer,".%s.xml",mname);

			if (!( sptr = allocate_string( nptr )))
				return;
			else if (!( sptr = enforce_extension( sptr, xbuffer )))
				return;
			else if (!(h = open_production_target(sptr,0)))
				return(-1);
			else	{
				fprintf(h,"<?xml version=%c1.0%c encoding=%cISO-8859-1%c?>\n",__QUOTE,__QUOTE,__QUOTE,__QUOTE);
				fprintf(h,"<SOAP-ENV:Envelope xmlns:SOAP-ENV=%chttp://schemas.xmlsoap.org/soap/envelope/%c SOAP-ENV:encodingStyle=%chttp://schemas.xmlsoap.org/soap/encoding/%c>\n",__QUOTE,__QUOTE,__QUOTE,__QUOTE);
				fprintf(h,"\t<SOAP-ENV:Body>\n");
				fprintf(h,"\t\t<tns:%s%s  xmlns:tns=%c%s/%s%c>\n",
					classname,mname,
					__QUOTE,WsGen.url,classname,__QUOTE
					);

				for (i=0; i < fields; i++ ) {
					fprintf(h,"\t\t\t<%s xsd:type=",dptr->name[i]);
					switch ( dptr->type[i] ) {
						case	_ABAL_BYTE	: 
						case	_ABAL_WORD	: 
						case	_ABAL_LONG	: 
							fprintf(h,"%cinteger%c"); break;
						case	_ABAL_BCD 	: 
							fprintf(h,"%cfloat%c"); break;
						case	_ABAL_STRING	: 
							fprintf(h,"%string%c"); break;
						}
					fprintf(h,"</%s>\n",dptr->name[i]);
					}

				fprintf(h,"\t\t</tns:%s%s>\n",	classname, mname );
				fprintf(h,"\t</SOAP-ENV:Body>\n");
				fprintf(h,"</SOAP-ENV:Envelope>\n");
				close_production_target( h, sptr );
				}
			}
		return;
		}
}

static	void	generate_alias_apache(struct form_control *  fptr, struct form_item * iptr, char * classname, char * nptr)
{
	FILE	*		h=(FILE *) 0;
	char	*		sptr=(char *) 0;
	int			i;
	if (!( sptr = allocate_string( nptr )))
		return;
	else if (!( sptr = enforce_extension( sptr, ".alias" )))
		return;
	else if (!(h = open_production_target(sptr,0)))
		return(-1);
	else	{
		if ( *nptr != '/' )
			fprintf(h,"\tAlias /%sFirst %c/home/httpd/html/%s%c\n",classname,__QUOTE,nptr,__QUOTE);
		else	fprintf(h,"\tAlias /%sFirst %c%s%c\n",classname,__QUOTE,nptr,__QUOTE);
		if ( *nptr != '/' )
			fprintf(h,"\tAlias /%sDown %c/home/httpd/html/%s%c\n",classname,__QUOTE,nptr,__QUOTE);
		else	fprintf(h,"\tAlias /%sDown %c%s%c\n",classname,__QUOTE,nptr,__QUOTE);
		if ( *nptr != '/' )
			fprintf(h,"\tAlias /%sUp %c/home/httpd/html/%s%c\n",classname,__QUOTE,nptr,__QUOTE);
		else	fprintf(h,"\tAlias /%sUp %c%s%c\n",classname,__QUOTE,nptr,__QUOTE);
		if ( *nptr != '/' )
			fprintf(h,"\tAlias /%sLast %c/home/httpd/html/%s%c\n",classname,__QUOTE,nptr,__QUOTE);
		else	fprintf(h,"\tAlias /%sLast %c%s%c\n",classname,__QUOTE,nptr,__QUOTE);
		if ( *nptr != '/' )
			fprintf(h,"\tAlias /%sSearch %c/home/httpd/html/%s%c\n",classname,__QUOTE,nptr,__QUOTE);
		else	fprintf(h,"\tAlias /%sSearch %c%s%c\n",classname,__QUOTE,nptr,__QUOTE);
		if ( *nptr != '/' )
			fprintf(h,"\tAlias /%sDelete %c/home/httpd/html/%s%c\n",classname,__QUOTE,nptr,__QUOTE);
		else	fprintf(h,"\tAlias /%sDelete %c%s%c\n",classname,__QUOTE,nptr,__QUOTE);
		if ( *nptr != '/' )
			fprintf(h,"\tAlias /%sUpdate %c/home/httpd/html/%s%c\n",classname,__QUOTE,nptr,__QUOTE);
		else	fprintf(h,"\tAlias /%sUpdate %c%s%c\n",classname,__QUOTE,nptr,__QUOTE);
		if ( *nptr != '/' )
			fprintf(h,"\tAlias /%sInsert %c/home/httpd/html/%s%c\n",classname,__QUOTE,nptr,__QUOTE);
		else	fprintf(h,"\tAlias /%sInsert %c%s%c\n",classname,__QUOTE,nptr,__QUOTE);
		if ( *nptr != '/' )
			fprintf(h,"\tAlias /%sModif %c/home/httpd/html/%s%c\n",classname,__QUOTE,nptr,__QUOTE);
		else	fprintf(h,"\tAlias /%sModif %c%s%c\n",classname,__QUOTE,nptr,__QUOTE);
		if ( *nptr != '/' )
			fprintf(h,"\tAlias /%sPosit %c/home/httpd/html/%s%c\n",classname,__QUOTE,nptr,__QUOTE);
		else	fprintf(h,"\tAlias /%sPosit %c%s%c\n",classname,__QUOTE,nptr,__QUOTE);
		if ( *nptr != '/' )
			fprintf(h,"\tAlias /%sCount %c/home/httpd/html/%s%c\n",classname,__QUOTE,nptr,__QUOTE);
		else	fprintf(h,"\tAlias /%sCount %c%s%c\n",classname,__QUOTE,nptr,__QUOTE);
		if ( *nptr != '/' )
			fprintf(h,"\tAlias /%sCollect %c/home/httpd/html/%s%c\n",classname,__QUOTE,nptr,__QUOTE);
		else	fprintf(h,"\tAlias /%sCollect %c%s%c\n",classname,__QUOTE,nptr,__QUOTE);
		if ( *nptr != '/' )
			fprintf(h,"\tAlias /%sLocate %c/home/httpd/html/%s%c\n",classname,__QUOTE,nptr,__QUOTE);
		else	fprintf(h,"\tAlias /%sLocate %c%s%c\n",classname,__QUOTE,nptr,__QUOTE);
		if ( *nptr != '/' )
			fprintf(h,"\tAlias /%sCreate %c/home/httpd/html/%s%c\n",classname,__QUOTE,nptr,__QUOTE);
		else	fprintf(h,"\tAlias /%sCreate %c%s%c\n",classname,__QUOTE,nptr,__QUOTE);
		if ( *nptr != '/' )
			fprintf(h,"\tAlias /%sRemove %c/home/httpd/html/%s%c\n",classname,__QUOTE,nptr,__QUOTE);
		else	fprintf(h,"\tAlias /%sRemove %c%s%c\n",classname,__QUOTE,nptr,__QUOTE);
		if ( *nptr != '/' )
			fprintf(h,"\tAlias /%sNew %c/home/httpd/html/%s%c\n",classname,__QUOTE,nptr,__QUOTE);
		else	fprintf(h,"\tAlias /%sNew %c%s%c\n",classname,__QUOTE,nptr,__QUOTE);
		close_production_target( h, sptr );
		return;
		}

}

public	void	generate_php_web_service (
	struct file_control * optr, 
	char * nptr, 
	int nlen  )
{
	FILE	*	h;

	struct	form_item    * wptr=(struct form_item    *) 0;
	struct	data_control * dptr=(struct data_control *) 0;
	struct	form_control * fptr=(struct form_control *) 0;
	
	if (!( optr )) 
		return(-1); 
	else if (!( dptr = optr->payload )) 
		return(-1); 

	limit_right_space( nptr,nlen);

	if (!( nptr = allocate_string( nptr )))
		return(-1);
	if (!( nptr = enforce_extension( nptr, PHP_EXTENSION )))
		return(-1);
	else if (!(h = open_production_target(nptr,0)))
		return(-1);
	else if (!( fptr = allocate_Form(optr->classname))) {
		close_production_target( h, nptr );
		return(-1);
		}
	else if (!( wptr = allocate_for_Widget())) {
		close_production_target( h, nptr );
		return(-1);
		}
	else if (!( wptr->Contents.format = allocate( strlen( optr->classname ) + 8 ) )) {
		close_production_target( h, nptr );
		return(-1);
		}
	else	{
		wptr->Contents.style = _DATA_FRAME;
		wptr->Contents.align = _MCFILE_FRAME;
		sprintf(wptr->Contents.format,"(%s)",optr->classname);
		wptr->Contents.name = allocate_string( optr->identity );
		wptr->Contents.payload = allocate_string( optr->filename );
		dptr->lock++;
		wptr->Contents.extra = dptr;
		reset_event_control(wptr->Contents.events,(wptr->Contents.style & _FRAME_TYPE));
		check_Widget( wptr );
		add_Widget(fptr,wptr,0);
		php_soap_server(h,fptr,wptr,optr->classname,nptr);
		close_production_target( h, nptr );
		generate_alias_apache(fptr,wptr,optr->classname,nptr);
		drop_Form( fptr );
		return;

		}
}


private	int	php_file_method( FILE * h, char * oname, char * mname, int item )
{
	if ( item ) fprintf(h,"else ");
	fprintf(h,"if ( $method == '%s' ) { $%s->On%s(); }\n",mname,oname,mname);
	return( ++item );
}

private	int	php_file_function( FILE * h, char * oname, char * mname, int item, char * pptr )
{
	if ( item ) fprintf(h,"else ");
	fprintf(h,"if ( $method == '%s' ) { $%s->On%s(%s); }\n",mname,oname,mname,pptr);
	return( ++item );
}

private	void	php_file_functions( FILE * h )
{
	fprintf(h,"print %c<tr><th colspan=2><table><tr>\\n%c;\n",__QUOTE,__QUOTE);
	fprintf(h,"print %c<td><input type=submit name=method class=submit value=\\%cFirst\\%c>\\n%c;\n",__QUOTE,__QUOTE,__QUOTE,__QUOTE);
	fprintf(h,"print %c<td><input type=submit name=method class=submit value=\\%cUp\\%c>\\n%c;\n",__QUOTE,__QUOTE,__QUOTE,__QUOTE);
	fprintf(h,"print %c<td><input type=submit name=method class=submit value=\\%cSearch\\%c>\\n%c;\n",__QUOTE,__QUOTE,__QUOTE,__QUOTE);
	fprintf(h,"print %c<td><input type=submit name=method class=submit value=\\%cSelect\\%c>\\n%c;\n",__QUOTE,__QUOTE,__QUOTE,__QUOTE);
	fprintf(h,"print %c<td><input type=submit name=method class=submit value=\\%cCollect\\%c>\\n%c;\n",__QUOTE,__QUOTE,__QUOTE,__QUOTE);
	fprintf(h,"print %c<td><input type=submit name=method class=submit value=\\%cLocate\\%c>\\n%c;\n",__QUOTE,__QUOTE,__QUOTE,__QUOTE);
	fprintf(h,"print %c<td><input type=submit name=method class=submit value=\\%cUpdate\\%c>\\n%c;\n",__QUOTE,__QUOTE,__QUOTE,__QUOTE);
	fprintf(h,"print %c<td><input type=submit name=method class=submit value=\\%cInsert\\%c>\\n%c;\n",__QUOTE,__QUOTE,__QUOTE,__QUOTE);
	fprintf(h,"print %c<td><input type=submit name=method class=submit value=\\%cDelete\\%c>\\n%c;\n",__QUOTE,__QUOTE,__QUOTE,__QUOTE);
	fprintf(h,"print %c<td><input type=submit name=method class=submit value=\\%cDown\\%c>\\n%c;\n",__QUOTE,__QUOTE,__QUOTE,__QUOTE);
	fprintf(h,"print %c<td><input type=submit name=method class=submit value=\\%cLast\\%c>\\n%c;\n",__QUOTE,__QUOTE,__QUOTE,__QUOTE);
	fprintf(h,"print %c<td><input type=submit name=method class=submit value=\\%cCreate\\%c>\\n%c;\n",__QUOTE,__QUOTE,__QUOTE,__QUOTE);
	fprintf(h,"print %c<td><input type=submit name=method class=submit value=\\%cRemove\\%c>\\n%c;\n",__QUOTE,__QUOTE,__QUOTE,__QUOTE);
	fprintf(h,"print %c<td><input type=submit name=method class=submit value=\\%cNew\\%c>\\n%c;\n",__QUOTE,__QUOTE,__QUOTE,__QUOTE);
	fprintf(h,"print %c</table>%c;\n",__QUOTE,__QUOTE);
	return;
}

void	php_indent(FILE * h, int n )
{
	int	i;
	for ( i=0; i < n; i++ )
		fprintf(h,"\t");
	return;
}


void	php_file_method_switch( FILE * h, struct form_item * iptr, int indent )
{
	int	item;
	php_indent(h,indent);
	fprintf(h,"// -----------------------\n");
	php_indent(h,indent);
	fprintf(h,"// Perform Required Method\n");
	php_indent(h,indent);
	fprintf(h,"// -----------------------\n");
	php_indent(h,indent);
	item = php_file_method( h, php_use_widget_name(iptr), "First" , (item=0) );
	php_indent(h,indent);
	item = php_file_method( h, php_use_widget_name(iptr), "Up" , item );
	php_indent(h,indent);
	item = php_file_method( h, php_use_widget_name(iptr), "Search" , item );
	php_indent(h,indent);
	item = php_file_method( h, php_use_widget_name(iptr), "Update" , item );
	php_indent(h,indent);
	item = php_file_method( h, php_use_widget_name(iptr), "Insert" , item );
	php_indent(h,indent);
	item = php_file_method( h, php_use_widget_name(iptr), "Modif" , item );
	php_indent(h,indent);
	item = php_file_method( h, php_use_widget_name(iptr), "Delete" , item );
	php_indent(h,indent);
	item = php_file_method( h, php_use_widget_name(iptr), "Modif" , item );
	php_indent(h,indent);
	item = php_file_method( h, php_use_widget_name(iptr), "Down" , item );
	php_indent(h,indent);
	item = php_file_method( h, php_use_widget_name(iptr), "Last" , item );
	php_indent(h,indent);
	item = php_file_method( h, php_use_widget_name(iptr), "Select" , item );
	php_indent(h,indent);
	item = php_file_method( h, php_use_widget_name(iptr), "Posit" , item );
	php_indent(h,indent);
	item = php_file_method( h, php_use_widget_name(iptr), "Count" , item );
	php_indent(h,indent);
	item = php_file_method( h, php_use_widget_name(iptr), "Collect" , item );
	php_indent(h,indent);
	item = php_file_function( h, php_use_widget_name(iptr), "Locate" , item,"$item" );
	php_indent(h,indent);
	item = php_file_method( h, php_use_widget_name(iptr), "Create" , item );
	php_indent(h,indent);
	item = php_file_method( h, php_use_widget_name(iptr), "Remove" , item );
	php_indent(h,indent);
	item = php_file_method( h, php_use_widget_name(iptr), "New" , item );
	return;
}

public	int	html_php_file_client( struct form_control * fptr )
{
	FILE		*	h;
	int			item=0;
	int			fields;
	struct	form_item *	iptr;
	struct	data_control * 	dptr=(struct data_control *) 0;
	char			classname[1024];
	char		*	cptr;
	char 		*	nptr;
	int			i;
	for ( 	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr=iptr->next) {
		if (!( iptr->Contents.access & _WIDGET_PUBLIC ))
			continue;
		else if ((iptr->Contents.style & _FRAME_TYPE ) != _DATA_FRAME ) 
			continue;
		else if (!( is_file_Widget( iptr ) ))
			continue;
		else if (!(dptr = iptr->Contents.extra ))
			continue;
		else if (!( fields = dptr->indexfields + dptr->datafields ))
			continue;
		else if (!( cptr = iptr->Contents.format ))
			continue;
		else if ( *(cptr++) != '(' )
			continue;
		for (i=0; i < 1023; i++ ) {
			if ((*cptr == ' ')
			||  (*cptr == '.')
			||  (*cptr == ',')
			||  (*cptr == ';')
			||  (*cptr == ':')
			||  (*cptr == ')'))
				break;
			classname[i] = *(cptr++);
			}
		classname[i] = 0;
		if (!( nptr = allocate_string( classname )))
			return(-1);
		else if (!( nptr = enforce_extension( nptr, PHP_EXTENSION )))
			return(-1);
		else if (!(h = open_production_target(nptr,0)))
			return(-1);
		else	{
			fprintf(h,"<?php\n");
			fprintf(h,"// --------------------\n");
			fprintf(h,"// PHP/HTML File Client\n");
			fprintf(h,"// --------------------\n");
			fprintf(h,"require (%c%s%s%c);\n",__QUOTE,classname,INC_EXTENSION,__QUOTE);
			fprintf(h,"$%s = new %s;\n",php_use_widget_name(iptr),classname);

			fprintf(h,"// -------------------\n");
			fprintf(h,"// Recover POST Values\n");
			fprintf(h,"// -------------------\n");
			fprintf(h,"$method   = $_POST['method'];\n");
			fprintf(h,"$%s->question = $_POST['question'];\n",php_use_widget_name(iptr));
			for ( i=0; i < fields; i++ ) {
				fprintf(h,"$%s->_%s = $_POST['_%s'];\n",php_use_widget_name(iptr),dptr->name[i],dptr->name[i]);
				}
			fprintf(h,"$%s->OnCheck();\n",php_use_widget_name(iptr));

			php_file_method_switch(h,iptr, 0 );

			fprintf(h,"// ---------------------\n");
			fprintf(h,"// Generate the Web Page\n");
			fprintf(h,"// ---------------------\n");
			fprintf(h,"print %c<html>\\n%c;\n",__QUOTE,__QUOTE);
			fprintf(h,"print %c<head>\\n%c;\n",__QUOTE,__QUOTE);
			fprintf(h,"print %c<title>class : %s File Manager</title>\\n%c;\n",__QUOTE,classname,__QUOTE);
			fprintf(h,"print %c<link href=\\%cstyle.css\\%c rel=\\%cSTYLESHEET\\%c type=\\%ctext/css\\%c media=\\%cSCREEN\\%c>\\n%c;\n",
				__QUOTE,__QUOTE,
				__QUOTE,__QUOTE,
				__QUOTE,__QUOTE,
				__QUOTE,__QUOTE,
				__QUOTE,__QUOTE);
			fprintf(h,"print %c</head>\\n%c;\n",__QUOTE,__QUOTE);
			fprintf(h,"print %c<body>\\n%c;\n",__QUOTE,__QUOTE);
			fprintf(h,"print %c<div align=center>\\n%c;\n",__QUOTE,__QUOTE);
			fprintf(h,"print %c<form method=\\%cPOST\\%c action=\\%c\\%c>\\n%c;\n",
				__QUOTE,__QUOTE,
				__QUOTE,__QUOTE,
				__QUOTE,__QUOTE);
			fprintf(h,"print %c<table width=\\%c90%%\\%c border=\\%c0\\%c>\\n%c;\n",
				__QUOTE,__QUOTE,
				__QUOTE,__QUOTE,
				__QUOTE,__QUOTE);
			fprintf(h,"print %c<tr><th colspan=2><p><h2 align=center>%s Management</h2>\\n%c;\n",
				__QUOTE,classname,__QUOTE);

			php_file_functions( h );

			// -------------------------
			// The Read Only Error Value
			// -------------------------
			fprintf(h,"print %c<tr><th width=\\%c20%%\\%c>%s\\n%c;\n",
				__QUOTE,__QUOTE,__QUOTE,"error",__QUOTE);			
			fprintf(h,"print %c<td width=\\%c40%%\\%c>\\n%c;\n",
				__QUOTE,__QUOTE,__QUOTE,__QUOTE);			
			fprintf(h,"print %c<input type=text readonly name=\\%c%s\\%c \\n%c;\n",
				__QUOTE,__QUOTE,"error",__QUOTE,__QUOTE);
			fprintf(h,"print %c value=\\%c%c . $%s->%s . %c\\%c>\\n%c;\n",
				__QUOTE,__QUOTE,__QUOTE,
				php_use_widget_name(iptr),"error",
				__QUOTE,__QUOTE,__QUOTE);

			// -----------------------------------
			// The various Index and Record fields
			// -----------------------------------
			for ( i=0; i < fields; i++ ) {
				fprintf(h,"print %c<tr><th class=\\%c%s\\%c width=\\%c20%%\\%c>%s\\n%c;\n",
					__QUOTE,__QUOTE,(i & 1 ? "oddrow" : "evenrow" ),__QUOTE,
					__QUOTE,__QUOTE,dptr->name[i],__QUOTE);			
				fprintf(h,"print %c<td class=\\%c%s\\%c width=\\%c40%%\\%c>\\n%c;\n",
					__QUOTE,__QUOTE,(i & 1 ? "oddrow" : "evenrow" ),__QUOTE,
					__QUOTE,__QUOTE,__QUOTE);			
				fprintf(h,"print %c<input type=text name=\\%c_%s\\%c \\n%c;\n",
					__QUOTE,__QUOTE,dptr->name[i],__QUOTE,__QUOTE);

				if ( dptr->type[i] == _ABAL_STRING ) {
					fprintf(h,"print %c size=%u %c;\n",
						__QUOTE,( dptr->width[i] < 80 ? dptr->width[i] : 80),__QUOTE);
					}
				fprintf(h,"print %c value=\\%c%c . $%s->_%s . %c\\%c>\\n%c;\n",
					__QUOTE,__QUOTE,__QUOTE,
					php_use_widget_name(iptr),dptr->name[i],
					__QUOTE,__QUOTE,__QUOTE);
				}

			// ------------------
			// The Question Field 
			// ------------------
			fprintf(h,"print %c<tr><th width=\\%c20%%\\%c>%s\\n%c;\n",
				__QUOTE,__QUOTE,__QUOTE,"question",__QUOTE);			
			fprintf(h,"print %c<td width=\\%c40%%\\%c>\\n%c;\n",
				__QUOTE,__QUOTE,__QUOTE,__QUOTE);			
			fprintf(h,"print %c<input type=text name=\\%c%s\\%c \\n%c;\n",
				__QUOTE,__QUOTE,"question",__QUOTE,__QUOTE);
			fprintf(h,"print %c value=\\%c%c . $%s->%s . %c\\%c>\\n%c;\n",
				__QUOTE,__QUOTE,__QUOTE,
				php_use_widget_name(iptr),"question",
				__QUOTE,__QUOTE,__QUOTE);

			fprintf(h,"print %c<tr><th colspan=2>&nbsp;\\n%c;\n",__QUOTE,__QUOTE);

			php_file_functions( h );

			fprintf(h,"print %c</table>\\n%c;\n",__QUOTE,__QUOTE);
			fprintf(h,"print %c</form>\\n%c;\n",__QUOTE,__QUOTE);
			fprintf(h,"print %c</div>\\n%c;\n",__QUOTE,__QUOTE);
			fprintf(h,"print %c</body>\\n%c;\n",__QUOTE,__QUOTE);
			fprintf(h,"print %c</html>\\n%c;\n",__QUOTE,__QUOTE);
			fprintf(h,"// ------------\n");
			fprintf(h,"// End of File \n");
			fprintf(h,"// ------------\n");
			fprintf(h,"?>");
			close_production_target( h, nptr );
			}
		}
	return(0);
}

public	void	php_generate_service( struct form_control * fptr , char * target, char * classname )
{
	struct	form_item * wptr;
	char	*	nptr;
	FILE	*	h;
	for ( 	wptr=fptr->first;
		wptr != (struct form_item *) 0;
		wptr=wptr->next) {
		if (!( wptr->Contents.access & _WIDGET_PUBLIC ))
			continue;
		else if ((wptr->Contents.style & _FRAME_TYPE ) != _DATA_FRAME ) 
			continue;
		else	break;
		}
	if (!( wptr ))
		return(-1);
	else if (!( nptr = allocate_string( target )))
		return(-1);
	else if (!( nptr = enforce_extension( nptr, PHP_EXTENSION )))
		return(-1);
	else if (!(h = open_production_target(nptr,0)))
		return(-1);
	else	{
		php_soap_server(h,fptr,wptr,classname,nptr);
		close_production_target( h, nptr );
		generate_alias_apache(fptr,wptr,classname,nptr);
		return;
		}
}

public	void	php_generate_interface( struct form_control * fptr , char * target, char * classname )
{
	return;
}


#endif	/* _singphp_c */
	/* ---------- */

