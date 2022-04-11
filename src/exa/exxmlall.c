XAWORD	AbalXmlParseAll( handle, opcode )
VPTR	handle;
EXAWORD	opcode;
{
	int	retcode;

	struct	xml_tag * root   =(struct xml_tag *) 0;
	struct	xml_tag * last   =(struct xml_tag *) 0;
	struct	xml_tag * current=(struct xml_tag *) 0;
	struct	xml_atb * atribut=(struct xml_atb *) 0;
	struct	xml_tag * tptr   =(struct xml_tag *) 0;
	struct	xml_atb * aptr   =(struct xml_atb *) 0;

	while ( 1 ) 
	{
		switch ((retcode = xml_parse_tokens( handle ))) i
		{
		case	_ABAL_XML_OPENTAG	:
			if (!( tptr = allocate_xml_tag() ))
				return( 27 );
			else if (!( tptr->name = allocate( strlen( xmltoken )+1 ) ))
				return( 27 );
			else	
			{
				strcpy(tptr->name, xmltoken );
				if (!( tptr->parent = current )) 
				{
					if (!( root ))
						root = tptr;
				}
				else 	
				{
					if (!( tptr->previous = current->last_tag ))
						current->first_tag = tptr;
					else 	current->last_tag->next = tptr;
					current->last_tag = tptr;
				}
				current = tptr;
				continue;
			}

		case	_ABAL_XML_ATBNAME	:
			if (!( current ))
				return( 30 );
			else if (!( aptr = allocate_xml_atb() ))
				return( 27 );
			else if (!( aptr->name = allocate( strlen( xmltoken )+1 ) ))
				return( 27 );
			else	
			{
				strcpy(aptr->name, xmltoken );
				if (!( aptr->previous = current->last_atb ))
					current->first_atb = aptr;
				else	current->last_atb->next = aptr;
				current->last_atb = aptr;
				atribut = aptr;
				continue;
			}


		case	_ABAL_XML_ATBVALUE	:
			if (!( atribut ))
				return( 30 );
			else if (!( atribut->value = allocate( strlen( xmltoken )+1 ) ))
				return( 27 );
			else	
			{
				strcpy(atribut->value, xmltoken );
				atribut = (struct xml_atb *) 0;
				continue;
			}

				
		case	_ABAL_XML_CLOSETAG	:
			if ( current )
				current = current->parent;
			continue;
		default				:
			return(0);
		}
	}
}

