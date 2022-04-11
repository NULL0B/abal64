#ifndef	_maneditload_c
#define	_maneditload_c

/*	-------------------------------------------------------------	*/
/*			l o a d _ a c t i o n s				*/
/*	-------------------------------------------------------------	*/
private	int	load_actions( struct xml_element * dptr, struct actions * lptr )
{
	struct	action * bptr;
	struct	xml_atribut * aptr;

	int		count=0;
	for ( 	;
			dptr != (struct xml_element *) 0;
			dptr = dptr->next )
	{
		if (!( dptr->name ))
			continue;
		if (!( strcmp( dptr->name,"action" )))
		{
			if (!( bptr = add_action_after( lptr ) ))
				break;
			else
			{
				count++;
				for (	aptr=dptr->firstatb;
						aptr != (struct xml_atribut *) 0;
						aptr = aptr->next )
				{
					if (!( aptr->name ))
						continue;
					else if (!( aptr->value ))
						continue;
					else if (!( strcmp( aptr->name , "name" ) ))
						bptr->name = allocate_unquoted_string( aptr->value );
					else if (!( strcmp( aptr->name , "type" ) ))
						bptr->type = allocate_unquoted_string( aptr->value );
					else if (!( strcmp( aptr->name , "expression" ) ))
						bptr->expression = allocate_unquoted_string( aptr->value );
				}
			}
		}
	}
	return( count );
}

/*	-------------------------------------------------------------	*/
/*			l o a d _ p o r t 				*/
/*	-------------------------------------------------------------	*/
private	int	load_port( struct xml_element * dptr, struct ports * nptr )
{
	struct	xml_element * eptr;
	struct	xml_atribut * aptr;
	struct	port * pptr;
	if (!( pptr = allocate( sizeof( struct port ) ) ))
		return( 0 );
	else if (!( pptr->previous = nptr->last ))
		nptr->first = pptr;
	else
		pptr->previous->next = pptr;
	nptr->last = pptr;

	for (	aptr=dptr->firstatb;
			aptr != (struct xml_atribut *) 0;
			aptr = aptr->next )
	{
		if (!( aptr->name ))
			continue;
		else if (!( aptr->value ))
			continue;
		else if (!( strcmp( aptr->name , "name" ) ))
			pptr->name = allocate_unquoted_string( aptr->value );
		else if (!( strcmp( aptr->name , "from" ) ))
			pptr->from = allocate_unquoted_string( aptr->value );
		else if (!( strcmp( aptr->name , "to" ) ))
			pptr->to = allocate_unquoted_string( aptr->value );
		else if (!( strcmp( aptr->name , "protocol" ) ))
			pptr->protocol = allocate_unquoted_string( aptr->value );
		else if (!( strcmp( aptr->name , "range" ) ))
			pptr->range = allocate_unquoted_string( aptr->value );
		else if (!( strcmp( aptr->name , "direction" ) ))
			pptr->direction = allocate_unquoted_string( aptr->value );
	}
	return( 1 );
}

/*	-------------------------------------------------------------	*/
/*			l o a d _ c o m p u t e				*/
/*	-------------------------------------------------------------	*/
private	int	load_compute( struct xml_element * dptr, struct infrastructure * nptr )
{
	struct	xml_element * eptr;
	struct	xml_atribut * aptr;
	if (!( nptr->cpu = allocate( sizeof( struct compute ) ) ))
		return( 0 );
	else
	{
		for (	aptr=dptr->firstatb;
			aptr != (struct xml_atribut *) 0;
			aptr = aptr->next )
		{
			if (!( aptr->name ))
				continue;
			else if (!( aptr->value ))
				continue;
			else if (!( strcmp( aptr->name , "name" ) ))
				nptr->cpu->name = allocate_unquoted_string( aptr->value );
			else if (!( strcmp( aptr->name , "cores" ) ))
				nptr->cpu->cores = allocate_unquoted_string( aptr->value );
			else if (!( strcmp( aptr->name , "speed" ) ))
				nptr->cpu->speed = allocate_unquoted_string( aptr->value );
			else if (!( strcmp( aptr->name , "memory" ) ))
				nptr->cpu->memory = allocate_unquoted_string( aptr->value );
			else if (!( strcmp( aptr->name , "architecture" ) ))
				nptr->cpu->architecture = allocate_unquoted_string( aptr->value );
			else if (!( strcmp( aptr->name , "hostname" ) ))
				nptr->cpu->hostname = allocate_unquoted_string( aptr->value );
		}
	}
	return( 1 );
}

/*	-------------------------------------------------------------	*/
/*			l o a d _ s t o r a g e 			*/
/*	-------------------------------------------------------------	*/
private	int	load_storage( struct xml_element * dptr, struct infrastructure * nptr )
{
	struct	xml_element * eptr;
	struct	xml_atribut * aptr;
	if (!( nptr->disk = allocate( sizeof( struct storage ) ) ))
		return( 0 );
	else
	{
		for (	aptr=dptr->firstatb;
				aptr != (struct xml_atribut *) 0;
				aptr = aptr->next )
		{
			if (!( aptr->name ))
				continue;
			else if (!( aptr->value ))
				continue;
			else if (!( strcmp( aptr->name , "name" ) ))
				nptr->disk->name = allocate_unquoted_string( aptr->value );
			else if (!( strcmp( aptr->name , "size" ) ))
				nptr->disk->size = allocate_unquoted_string( aptr->value );
		}
	}
	return( 1 );
}

/*	-------------------------------------------------------------	*/
/*			l o a d _ n e t w o r k				*/
/*	-------------------------------------------------------------	*/
private	int	load_network( struct xml_element * dptr, struct infrastructure * nptr )
{
	struct	xml_element * eptr;
	struct	xml_atribut * aptr;
	if (!( nptr->card = allocate( sizeof( struct network ) ) ))
		return( 0 );
	else
	{
		for (	aptr=dptr->firstatb;
				aptr != (struct xml_atribut *) 0;
				aptr = aptr->next )
		{
			if (!( aptr->name ))
				continue;
			else if (!( aptr->value ))
				continue;
			else if (!( strcmp( aptr->name , "name" ) ))
				nptr->card->name = allocate_unquoted_string( aptr->value );
			else if (!( strcmp( aptr->name , "vlan" ) ))
				nptr->card->vlan = allocate_unquoted_string( aptr->value );
			else if (!( strcmp( aptr->name , "label" ) ))
				nptr->card->label = allocate_unquoted_string( aptr->value );
		}
		for ( 	eptr = dptr->first;
				eptr != (struct xml_element *) 0;
				eptr = eptr->next )
		{
			if (!( eptr->name ))
				continue;
			else if (!( strcmp( eptr->name, "port" ) ))
				load_port( eptr, &nptr->card->portlist );
		}
	}
	return( 1 );
}

/*	-------------------------------------------------------------	*/
/*			l o a d _ s y s t e m				*/
/*	-------------------------------------------------------------	*/
private	int	load_system( struct xml_element * dptr, struct image * nptr )
{
	struct	xml_element * eptr;
	struct	xml_atribut * aptr;
	if (!( nptr->os = allocate( sizeof( struct system ) ) ))
		return( 0 );
	else
	{
		for (	aptr=dptr->firstatb;
				aptr != (struct xml_atribut *) 0;
				aptr = aptr->next )
		{
			if (!( aptr->name ))
				continue;
			else if (!( aptr->value ))
				continue;
			else if (!( strcmp( aptr->name , "name" ) ))
				nptr->os->name = allocate_unquoted_string( aptr->value );
			else if (!( strcmp( aptr->name , "version" ) ))
				nptr->os->version = allocate_unquoted_string( aptr->value );
		}
	}
	return( 1 );
}

/*	-------------------------------------------------------------	*/
/*			l o a d _ p a c k a g e				*/
/*	-------------------------------------------------------------	*/
private	int	load_package( struct xml_element * dptr, struct packages * nptr )
{
	struct	xml_element * eptr;
	struct	xml_atribut * aptr;
	struct	package * pptr;
	if (!( pptr = allocate( sizeof( struct package ) ) ))
		return( 0 );
	else if (!( pptr->previous = nptr->last ))
		nptr->first = pptr;
	else
		pptr->previous->next = pptr;
	nptr->last = pptr;
	for (	aptr=dptr->firstatb;
			aptr != (struct xml_atribut *) 0;
			aptr = aptr->next )
	{
		if (!( aptr->name ))
			continue;
		else if (!( aptr->value ))
			continue;
		else if (!( strcmp( aptr->name , "name" ) ))
			pptr->name = allocate_unquoted_string( aptr->value );
		else if (!( strcmp( aptr->name , "installation" ) ))
			pptr->installation = allocate_unquoted_string( aptr->value );
		else if (!( strcmp( aptr->name , "configuration" ) ))
			pptr->configuration = allocate_unquoted_string( aptr->value );
	}
	for ( 	eptr = dptr->first;
			eptr != (struct xml_element *) 0;
			eptr = eptr->next )
	{
		if (!( eptr->name ))
			continue;
		else if (!( strcmp( eptr->name, "port" ) ))
			load_port( eptr, &pptr->portlist );
	}
	return( 1 );
}

/*	-------------------------------------------------------------	*/
/*		l o a d _ i n f ra s t r u c t u r e			*/
/*	-------------------------------------------------------------	*/
private	int	load_infrastructure( struct xml_element * dptr, struct node * nptr )
{
	struct	xml_element * eptr;
	struct	xml_atribut * aptr;
	if (!( nptr->hard = allocate( sizeof( struct infrastructure ) ) ))
		return( 0 );
	else
	{
		for (	aptr=dptr->firstatb;
				aptr != (struct xml_atribut *) 0;
				aptr = aptr->next )
		{
			if (!( aptr->name ))
				continue;
			else if (!( aptr->value ))
				continue;
			else if (!( strcmp( aptr->name , "name" ) ))
				nptr->hard->name = allocate_unquoted_string( aptr->value );
		}
		for ( 	eptr = dptr->first;
				eptr != (struct xml_element *) 0;
				eptr = eptr->next )
		{
			if (!( eptr->name ))
				continue;
			else if (!( strcmp( eptr->name, "compute" ) ))
				load_compute( eptr, nptr->hard );
			else if (!( strcmp( eptr->name, "storage" ) ))
				load_storage( eptr, nptr->hard );
			else if (!( strcmp( eptr->name, "network" ) ))
				load_network( eptr, nptr->hard );
		}
	}
	return( 1 );
}

/*	-------------------------------------------------------------	*/
/*			l o a d _ i m a g e 				*/
/*	-------------------------------------------------------------	*/
private	int	load_image( struct xml_element * dptr, struct node * nptr )
{
	struct	xml_element * eptr;
	struct	xml_atribut * aptr;
	if (!( nptr->soft = allocate( sizeof( struct image ) ) ))
		return( 0 );
	else
	{
		for (	aptr=dptr->firstatb;
				aptr != (struct xml_atribut *) 0;
				aptr = aptr->next )
		{
			if (!( aptr->name ))
				continue;
			else if (!( aptr->value ))
				continue;
			else if (!( strcmp( aptr->name , "name" ) ))
				nptr->soft->name = allocate_unquoted_string( aptr->value );
			else if (!( strcmp( aptr->name , "agent" ) ))
				nptr->soft->agent = allocate_unquoted_string( aptr->value );
		}
		for ( 	eptr = dptr->first;
			eptr != (struct xml_element *) 0;
			eptr = eptr->next )
		{
			if (!( eptr->name ))
				continue;
			else if (!( strcmp( eptr->name, "system" ) ))
				load_system( eptr, nptr->soft );
			else if (!( strcmp( eptr->name, "package" ) ))
				load_package( eptr, &nptr->soft->packagelist );
		}
	}
	return( 1 );
}

/*	-------------------------------------------------------------	*/
/*		l o a d _ m a n i f e s t _ m e t a			*/
/*	-------------------------------------------------------------	*/
private	int	load_manifest_meta( struct manifest * mptr )
{
	struct	xml_element * dptr;
	struct	xml_element * eptr;
	struct	xml_atribut * aptr;
	struct	node * nptr;
	char *	vptr;
	char	namebuffer[2048];
	FILE	*	h;
	sprintf(namebuffer,"meta_%s",mptr->filename);
	if (!( dptr = document_parse_file( namebuffer ) ))
		return( 40 );
	else
	{

		if ((dptr->name) && (!( strcmp( dptr->name, "manifestmeta" ) )))
		{
			for (	aptr=dptr->firstatb;
				aptr != (struct xml_atribut *) 0;
				aptr = aptr->next )
			{
				if (!( aptr->name ))
					continue;
				else if (!( strcmp( aptr->name , "x" ) ))
				{
					if (!( vptr = allocate_unquoted_string( aptr->value ) ))
						continue;
					else
					{
						deskadjx = atoi( vptr );
						liberate( vptr );
					}
				}
				else if (!( strcmp( aptr->name , "y" ) ))
				{
					if (!( vptr = allocate_unquoted_string( aptr->value ) ))
						continue;
					else
					{
						deskadjy = atoi( vptr );
						liberate( vptr );
					}
				}
				else if (!( strcmp( aptr->name , "view" ) ))
				{
					if (!( vptr = allocate_unquoted_string( aptr->value ) ))
						continue;
					else
					{
						view = atoi( vptr );
						liberate( vptr );
					}
				}
				else if (!( strcmp( aptr->name , "zoom" ) ))
				{
					if (!( vptr = allocate_unquoted_string( aptr->value ) ))
						continue;
					else
					{
						zoom = atoi( vptr );
						liberate( vptr );
					}
				}
			}
			for (	dptr=dptr->first;
				dptr != (struct xml_element *) 0;
				dptr = dptr->next )
			{
				if (!( dptr->name ))
					continue;
				else if (!( strcmp( dptr->name, "nodemeta" ) ))
				{
					for (	aptr=dptr->firstatb;
						aptr != (struct xml_atribut *) 0;
						aptr = aptr->next )
					{
						if (!( aptr->name ))
							continue;
						else if ( strcmp( aptr->name, "name" ) != 0)
							continue;
						else if (!( vptr = allocate_unquoted_string( aptr->value ) ))
							continue;
						else if (!( nptr = resolve_manifest_node( mptr, vptr ) ))
						{
							liberate( vptr );
							continue;
						}
						else
						{
							liberate( vptr );
							for (	aptr=dptr->firstatb;
								aptr != (struct xml_atribut *) 0;
								aptr = aptr->next )
							{
								if (!( aptr->name ))
									continue;
								else if (!( strcmp( aptr->name , "x" ) ))
								{
									if (!( vptr = allocate_unquoted_string( aptr->value ) ))
										continue;
									else
									{
										nptr->x = atoi( vptr );
										liberate( vptr );
									}
								}
								else if (!( strcmp( aptr->name , "y" ) ))
								{
									if (!( vptr = allocate_unquoted_string( aptr->value ) ))
										continue;
									else
									{
										nptr->y = atoi( vptr );
										liberate( vptr );
									}
								}
								else if (!( strcmp( aptr->name , "visible" ) ))
								{
									if (!( vptr = allocate_unquoted_string( aptr->value ) ))
										continue;
									else
									{
										nptr->visible = atoi( vptr );
										liberate( vptr );
									}
								}
								else if (!( strcmp( aptr->name , "icon" ) ))
								{
									nptr->icon = allocate_unquoted_string( aptr->value );
								}
							}
						break;
						}
					}
				}
			}
		}
		dptr = document_drop( dptr );
		return(0);
	}
}

/*	-------------------------------------------------------------	*/
/*			l o a d _ m a n i f e s t			*/
/*	-------------------------------------------------------------	*/
private	int	load_manifest( struct manifest * mptr )
{
	struct	xml_element * dptr;
	struct	xml_element * eptr;
	struct	xml_atribut * aptr;
	struct	node * nptr;
	char *	vptr;
	if (!( mptr ))
		return( 118 );
	else if (!( mptr->filename ))
		return( 30 );
	else if (!( dptr = document_parse_file( mptr->filename ) ))
		return( 40 );
	else if (!( dptr->name ))
	{
		dptr = document_drop( dptr );
		return( 118 );
	}
	else if ( strcmp( dptr->name, "manifest" ) )
	{
		dptr = document_drop( dptr );
		return( 118 );
	}
	else
	{
		for (	dptr=dptr->first;
			dptr != (struct xml_element *) 0;
			dptr = dptr->next )
		{
			if (!( dptr->name ))
				continue;

			else if (!( strcmp( dptr->name, "node" ) ))
			{
				if (!( nptr = add_node_after( mptr, 0 )))
					continue;
				else
				{
					for (	aptr=dptr->firstatb;
						aptr != (struct xml_atribut *) 0;
						aptr = aptr->next )
					{
						if (!( aptr->name ))
							continue;
						else if (!( aptr->value ))
							continue;
						else if (!( vptr = allocate_unquoted_string( aptr->value ) ))
							break;
						else if (!( strcmp( aptr->name , "name" ) ))
						{
							nptr->name = vptr;
							continue;
						}
						else if (!( strcmp( aptr->name , "category" ) ))
						{
							nptr->category = vptr;
							continue;
						}
						else if (!( strcmp( aptr->name , "access" ) ))
						{
							if (!( strcasecmp( vptr,"public" ) ))
								nptr->access = 1;
							else if (!( strcasecmp( vptr,"private" ) ))
								nptr->access = 0;
						}
						else if (!( strcmp( aptr->name , "scope" ) ))
						{
							if (!( strcasecmp( vptr,"normal" ) ))
								nptr->scope = 0;
							else if (!( strcasecmp( vptr,"common" ) ))
								nptr->scope = 1;
						}
						else if (!( strcmp( aptr->name , "type" ) ))
						{
							if (!( strcasecmp( vptr,"simple" ) ))
								nptr->type = 0;
							else
							{
								nptr->type = 1;
								nptr->typename = vptr;
								continue;
							}
						}
						if ( vptr )
							liberate( vptr );
					}
					for ( 	eptr = dptr->first;
							eptr != (struct xml_element *) 0;
							eptr = eptr->next )
					{
						if (!( eptr->name ))
							continue;
						else if (!( strcmp( eptr->name, "infrastructure" ) ))
							load_infrastructure( eptr, nptr );
						else if (!( strcmp( eptr->name, "image" ) ))
							load_image( eptr, nptr );
					}
				}
			}	
			else if (!( strcmp( dptr->name, "configuration" ) ))
			{
				for (	aptr=dptr->firstatb;
					aptr != (struct xml_atribut *) 0;
					aptr = aptr->next )
				{
					if (!( aptr->name ))
						continue;
					else if (!( aptr->value ))
						continue;
					else if (!( strcmp( aptr->name , "name" ) ))
						mptr->configuration.name = allocate_unquoted_string( aptr->value );
				}
				load_actions( dptr->first, &mptr->configuration );
				continue;
			}	
			else if (!( strcmp( dptr->name, "release" ) ))
			{
				for (	aptr=dptr->firstatb;
					aptr != (struct xml_atribut *) 0;
					aptr = aptr->next )
				{
					if (!( aptr->name ))
						continue;
					else if (!( aptr->value ))
						continue;
					else if (!( strcmp( aptr->name , "name" ) ))
						mptr->release.name = allocate_unquoted_string( aptr->value );
				}
				load_actions( dptr->first, &mptr->release );
				continue;
			}	
			else if (!( strcmp( dptr->name, "interface" ) ))
			{
				for (	aptr=dptr->firstatb;
					aptr != (struct xml_atribut *) 0;
					aptr = aptr->next )
				{
					if (!( aptr->name ))
						continue;
					else if (!( aptr->value ))
						continue;
					else if (!( strcmp( aptr->name , "name" ) ))
						mptr->interface.name = allocate_unquoted_string( aptr->value );
				}
				load_actions( dptr->first, &mptr->interface );
				continue;
			}	
			else if (!( strcmp( dptr->name, "account" ) ))
			{
				for (	aptr=dptr->firstatb;
					aptr != (struct xml_atribut *) 0;
					aptr = aptr->next )
				{
					if (!( aptr->name ))
						continue;
					else if (!( aptr->value ))
						continue;
					else if (!( strcmp( aptr->name , "name" ) ))
						mptr->owner.name = allocate_unquoted_string( aptr->value );
				}
			}	
			else if (!( strcmp( dptr->name, "security" ) ))
			{
				for (	aptr=dptr->firstatb;
					aptr != (struct xml_atribut *) 0;
					aptr = aptr->next )
				{
					if (!( aptr->name ))
						continue;
					else if (!( aptr->value ))
						continue;
					else if (!( strcmp( aptr->name , "name" ) ))
						mptr->access.name = allocate_unquoted_string( aptr->value );
					else if (!( strcmp( aptr->name , "level" ) ))
						mptr->access.level = allocate_unquoted_string( aptr->value );
					else if (!( strcmp( aptr->name , "policy") ))
						mptr->access.policy = allocate_unquoted_string( aptr->value );
				}
			}	
		}			
		dptr = document_drop( dptr );
		return( load_manifest_meta( mptr ));
	}
}

#endif	/* _maneditload_c */
	/* -------------- */
