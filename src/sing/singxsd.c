#ifndef	_sing_xsd_c
#define	_sing_xsd_c

void	xsd_simple_type( FILE * handle, char * nptr, int type, int occurs )
{
	switch ( type ) 
	{
	case	_ABAL_BYTE	: 
	case	_ABAL_WORD	: 
	case	_ABAL_LONG	: 
	case	_ABAL_BCD 	: 
		laser_indent(handle);
		fprintf(handle,"<xs:element name=%c%s%c type=%c%s%c",
			0x0022,nptr,0x0022,
			0x0022,"xsd:integer",0x0022);
		break;
	case	_ABAL_STRING	: 
	default			:
		laser_indent(handle);
		fprintf(handle,"<xs:element name=%c%s%c type=%c%s%c",
			0x0022,nptr,0x0022,
			0x0022,"xsd:string",0x0022);
		break;
	}
	if ( occurs )
	{
		fprintf(handle," maxOccurs=%c%u%c",0x0022,occurs,0x0022);
	}
	fprintf(handle,"/>\n");
	return;
}

/*	-------------------------------------------	*/
/*	      	x s d _ p r o d u c t i o n 		*/
/*	-------------------------------------------	*/
int	xsd_production( struct form_item * iptr, char * url )
{
	char *	nptr;
	FILE *	handle;
	char *	databasename;
	char *	classname;
	char *	filename;
	struct	data_control * 	dptr;
	int	nature;
	int	fields;
	int	i;

	if (!( nature = is_file_Widget( iptr ) ))
		return(55);
	else if (!(dptr = iptr->Contents.extra ))
		return(118);
	else if (!( fields = dptr->indexfields + dptr->datafields ))
		return(102);
	else if (!( classname = resolve_widget_file_class( iptr ) ))
		return(118);
	else if (!( nptr = allocate_string( classname ) ))
		return(27);
	else if (!( nptr = enforce_extension( nptr, XSD_EXTENSION ) ))
		return(27);
	else if (!( handle = open_production_target( nptr, 0) ))
		return(46);
	else
	{
		fprintf(handle,"<xs:schema targetNamespace=%c%s/%s%s%c>\n",
			0x0022,url,classname,XSD_EXTENSION,0x0022);

		mpeg_enter();
			laser_indent(handle);
			fprintf(handle,"<xs:element name=%c%s%c type=%c%s%c/>\n",
				0x0022,classname,0x0022,
				0x0022,classname,0x0022);

			laser_indent(handle);
			fprintf(handle,"<xs:complexType name=%c%s%c>\n", 0x0022,classname,0x0022);
			mpeg_enter();
			laser_indent(handle);
			fprintf(handle,"<xs:sequence>\n");
			mpeg_enter();

				/* ------------------- */
				/* standard File Field */
				/* ------------------- */
				xsd_simple_type(handle,_FILE_METHOD,_ABAL_STRING,1);
				xsd_simple_type(handle,_FILE_NAME,_ABAL_STRING,1);
				xsd_simple_type(handle,_FILE_HANDLE,_ABAL_WORD,1);
				xsd_simple_type(handle,_FILE_ERROR,_ABAL_WORD,1);
				xsd_simple_type(handle,_RECORD_LENGTH,_ABAL_WORD,1);

				/* ------------------- */
				/* fields by File Type */
				/* ------------------- */
				switch ( nature )
				{
				case	_ADFILE_FRAME		:
					xsd_simple_type(handle,_FILE_SECTOR,_ABAL_WORD,1);
				case	_SQFILE_FRAME		:
				case	_VMEMORY_FRAME		:
					break;
				case	_DBFILE_FRAME		:
					xsd_simple_type(handle,_RECORD_QUESTION,_ABAL_STRING,1);
					xsd_simple_type(handle,_COLLECT_COUNT,_ABAL_WORD,1);
					xsd_simple_type(handle,_COLLECT_ITEM,_ABAL_WORD,1);
					break;

				case	_MCFILE_FRAME		:
					xsd_simple_type(handle,_COLLECT_TABLE,_ABAL_STRING,1);
					xsd_simple_type(handle,_RECORD_QUESTION,_ABAL_STRING,1);
					xsd_simple_type(handle,_RECORD_DIRECTION,_ABAL_WORD,1);

				case	_SIFILE_FRAME		:
					xsd_simple_type(handle,_COLLECT_COUNT,_ABAL_WORD,1);
					xsd_simple_type(handle,_COLLECT_ITEM,_ABAL_WORD,1);
					xsd_simple_type(handle,_RECORD_INDEX,_ABAL_STRING,1);
					xsd_simple_type(handle,_RECORD_MARKER,_ABAL_WORD,1);
				}

				/* ------------------- */
				/* File Record Fields  */
				/* ------------------- */
				for (i=0; i < fields; i++ )
				{
					xsd_simple_type( handle, dptr->name[i],dptr->type[i], dptr->first[i] );
				}

			mpeg_leave();
			laser_indent(handle);
			fprintf(handle,"<xs:sequence>\n");
			mpeg_leave();
			laser_indent(handle);
			fprintf(handle,"</xs:complexType>\n");

		mpeg_leave();
		fprintf(handle,"</xs:schema>\n");
		close_production_target( handle, nptr );
		liberate( nptr );
		return(0);
	}
}

/*	-------------------------------------------	*/
/*	      	     e x p o r t _ x s d 	   	*/
/*	-------------------------------------------	*/
int	export_xsd( struct form_control * fptr, char * url )
{
	char	* fnptr;
	struct form_control * ffptr;
	struct	form_item * iptr;
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		if ( iptr->Contents.style != _DATA_FRAME )
			continue;
		else if ( is_file_Widget( iptr ) )
			xsd_production( iptr, url );
		else if (( iptr->Contents.align & 0x000F) != _VISUAL_FRAME)
			continue;
		else if (!( fnptr = abal_payload(iptr) )) 
			return;
		else if (!(ffptr = locate_form_control( fnptr ) ))
			return;
		else	export_xsd( ffptr, url );
	}
	return(0);
}

	/* ----------- */
#endif	/* _sing_xsd_c */
	/* ----------- */

