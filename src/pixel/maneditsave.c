#ifndef	_maneditsave_c
#define	_maneditsave_c

/*	-------------------------------------------------------------	*/
/*			g e n e r a t e _ c o m p u t e			*/
/*	-------------------------------------------------------------	*/
private	int	generate_compute( FILE * h, struct compute * cptr )
{
	fprintf(h,"\t\t\t<compute");

	if ( cptr->name )
		fprintf(h," name=%c%s%c",0x0022,cptr->name,0x0022);

	fprintf(h," cores=%c%s%c speed=%c%s%c memory=%c%s%c",
		0x0022,(cptr->cores ? cptr->cores : "1"),0x0022,
		0x0022,(cptr->speed ? cptr->speed : "1G"),0x0022,
		0x0022,(cptr->memory ? cptr->memory : "1G"),0x0022);

	if ( cptr->architecture )
		fprintf(h," architecture=%c%s%c",0x0022,cptr->architecture,0x0022);

	if ( cptr->hostname )
		fprintf(h," hostname=%c%s%c",0x0022,cptr->hostname,0x0022);

	fprintf(h,"/>\n");
	return(0);
}

/*	-------------------------------------------------------------	*/
/*			g e n e r a t e _ s t o r a g e			*/
/*	-------------------------------------------------------------	*/
private	int	generate_storage( FILE * h, struct storage * sptr )
{
	fprintf(h,"\t\t\t<storage");
	if ( sptr->name )
		fprintf(h," name=%c%s%c",0x0022,sptr->name,0x0022);
	if ( sptr->size )
		fprintf(h," size=%c%s%c",0x0022,sptr->size,0x0022);
	if ( sptr->type )
		fprintf(h," type=%c%s%c",0x0022,sptr->type,0x0022);
	fprintf(h,"/>\n");
	return(0);
}

/*	-------------------------------------------------------------	*/
/*				g e n e r a t e _ p o r t 		*/
/*	-------------------------------------------------------------	*/
private	int	generate_port( FILE * h, struct port * pptr )
{
	fprintf(h,"\t\t\t\t<port");
	if ( pptr )
	{
		if ( pptr->name )
			fprintf(h," name=%c%s%c",0x0022,pptr->name,0x0022);

		if ( pptr->protocol )
			fprintf(h," protocol=%c%s%c",0x0022,pptr->protocol,0x0022);

		if ( pptr->to )
			fprintf(h," to=%c%s%c",0x0022,pptr->to,0x0022);

		if ( pptr->from )
			fprintf(h," from=%c%s%c",0x0022,pptr->from,0x0022);

		if ( pptr->direction )
			fprintf(h," direction=%c%s%c",0x0022,pptr->direction,0x0022);
		if ( pptr->range )

			fprintf(h," range=%c%s%c",0x0022,pptr->range,0x0022);
	}
	fprintf(h,"/>\n");
	return(0);
}

/*	-------------------------------------------------------------	*/
/*			g e n e r a t e _ n e tw o r k			*/
/*	-------------------------------------------------------------	*/
private	int	generate_network( FILE * h, struct network * nptr )
{
	struct	port * pptr;
	fprintf(h,"\t\t\t<network");
	if ( nptr->name )
		fprintf(h," name=%c%s%c",0x0022,nptr->name,0x0022);
	if ( nptr->vlan )
		fprintf(h," vlan=%c%s%c",0x0022,nptr->vlan,0x0022);
	if ( nptr->label )
		fprintf(h," label=%c%s%c",0x0022,nptr->label,0x0022);
	if (!( nptr->portlist.first ))
		fprintf(h,"/>\n");
	else
	{
		fprintf(h,">\n");
		for ( pptr=nptr->portlist.first;
			pptr != (struct port *) 0;
			pptr = pptr->next )
			generate_port( h, pptr );
		fprintf(h,"\t\t\t</network>\n");
	}
	return(0);
}

/*	-------------------------------------------------------------	*/
/*				g e n e r a t e _ i n f r a 						*/
/*	-------------------------------------------------------------	*/
private	int	generate_infra( FILE * h, struct infrastructure * hptr )
{
	fprintf(h,"\t\t<infrastructure>\n");
	if ( hptr )
	{		generate_compute(h,hptr->cpu);
		generate_storage(h,hptr->disk);
		generate_network(h,hptr->card);
	}
	fprintf(h,"\t\t</infrastructure>\n");
	return(0);
}

/*	-------------------------------------------------------------	*/
/*			g e n e r a t e _ p a c k a g e			*/
/*	-------------------------------------------------------------	*/
private	int	generate_package( FILE * h, struct package * pptr )
{
	struct	port * port;
	fprintf(h,"\t\t<package");
	if ( pptr->name )
		fprintf(h," name=%c%s%c",0x0022,pptr->name,0x0022);
	if ( pptr->installation )
		fprintf(h," installation=%c%s%c",0x0022,pptr->installation,0x0022);
	else	fprintf(h," installation=%c%s%c",0x0022,"#",0x0022);
	if ( pptr->configuration )
		fprintf(h," configuration=%c%s%c",0x0022,pptr->configuration,0x0022);
	else	fprintf(h," configuration=%c%s%c",0x0022,"#",0x0022);
	if (!( pptr->portlist.first ))
		fprintf(h,"/>\n");
	else
	{
		fprintf(h,">\n");
		for (	port=pptr->portlist.first;
			port != (struct port *) 0;
			port = port->next )
			generate_port( h, port );
		fprintf(h,"</package>\n");
	}
	return(0);
}

/*	-------------------------------------------------------------	*/
/*			g e n e r a t e _ i m a g e 			*/
/*	-------------------------------------------------------------	*/
private	int	generate_image( FILE * h, struct image * iptr )
{
	struct	package * pptr;
	fprintf(h,"\t\t<image");

	if ( iptr->name )
		fprintf(h," name=%c%s%c",0x0022,iptr->name,0x0022);
	if ( iptr->agent )
		fprintf(h," agent=%c%s%c",0x0022,iptr->agent,0x0022);

	if ((!( iptr->os )) && (!( iptr->packagelist.first)))
		fprintf(h,"/>\n");
	else
	{
		fprintf(h,">\n");
		if ( iptr->os )
		{
			fprintf(h,"\t\t\t<system name=%c%s%c/>\n",
				0x0022,"debian_with_cosacs",0x0022);
		}
		for (	pptr=iptr->packagelist.first;
			pptr != (struct package *) 0;
			pptr = pptr->next )
			generate_package( h, pptr );
		fprintf(h,"\t\t</image>\n");
	}
	return(0);
}

/*	-------------------------------------------------------------	*/
/*			g e n e r a t e _ n o d e			*/
/*	-------------------------------------------------------------	*/
private	int	generate_node( FILE * h, struct node * nptr )
{
	char	buffer [1024];
	get_node_name( buffer, nptr );

	fprintf(h,"\t<node name=%c%s%c",0x0022,buffer,0x0022);

 	if ( nptr->access )
		fprintf(h," access=%c%s%c",0x0022,"public",0x0022);
	else	fprintf(h," access=%c%s%c",0x0022,"private",0x0022);

 	if ( nptr->scope )
		fprintf(h," scope=%c%s%c",0x0022,"common",0x0022);
	else	fprintf(h," scope=%c%s%c",0x0022,"normal",0x0022);

	if (!( nptr->type ))
	{
		fprintf(h," type=%c%s%c",0x0022,"simple",0x0022);
		if ((!( nptr->hard )) && (!( nptr->soft )))
			fprintf(h,"/>\n");
		else
		{
			fprintf(h,">\n");
			if ( nptr->hard )
				generate_infra(h,nptr->hard);
			if ( nptr->soft )
				generate_image(h, nptr->soft);

			fprintf(h,"\t</node>\n");
		}
	}
	else
	{
		if (( nptr->typename ) && ( strcmp( nptr->typename, "simple" ) ))
		{
			if ( nptr->category )
				fprintf(h," category=%c%s%c",0x0022,nptr->category,0x0022);
		}
		if ( nptr->typename )
			fprintf(h," type=%c%s%c",0x0022,nptr->typename,0x0022);
		fprintf(h,"/>\n");
	}
	return(0);
}

/*	-------------------------------------------------------------	*/
/*			g e n e r a t e _ a c t i o n s			*/
/*	-------------------------------------------------------------	*/
private	int	generate_actions( FILE * h, struct actions * bptr, char * name )
{
	struct	action * aptr;
	if (!( bptr->first ))
	{
		fprintf(h,"\t<%s",name);
		if ( bptr->name )
			fprintf(h," name=%c%s%c/>\n",0x0022,bptr->name,0x0022);
		else	fprintf(h,"/>\n");
	}
	else
	{
		fprintf(h,"\t<%s",name);
		if ( bptr->name )
			fprintf(h," name=%c%s%c>\n",0x0022,bptr->name,0x0022);
		else	fprintf(h,">\n");

		for (	aptr=bptr->first;
			aptr != (struct action *) 0;
			aptr = aptr->next )
		{
			fprintf(h,"\t\t<action");
			if ( aptr->name )
				fprintf(h," name=%c%s%c",0x0022,aptr->name,0x0022);

			if ( aptr->type )
				fprintf(h," type=%c%s%c",0x0022,aptr->type,0x0022);

			if ( aptr->expression )
				fprintf(h," expression=%c%s%c",0x0022,aptr->expression,0x0022);

			fprintf(h,"/>\n");
		}
		fprintf(h,"\t</%s>\n",name);
	}
	return( 0 );
}

/*	-------------------------------------------------------------	*/
/*			s a v e _ m a n i f e s t _ m e t a		*/
/*	-------------------------------------------------------------	*/
private	int	save_manifest_meta( struct manifest * mptr, char * filename )
{
	FILE *	h;
	char 	namebuffer[2048];
	struct	node *	nptr;
	sprintf(namebuffer,"meta_%s",filename);
	if (!( h = fopen( namebuffer,"w" ) ))
		return( 46 );
	else
	{
		fprintf(h,"<manifestmeta view=%c%u%c zoom=%c%u%c x=%c%u%c y=%c%u%c>\n",
			0x0022,view,0x0022,0x0022,zoom,0x0022,0x0022,deskadjx,0x0022,0x0022,deskadjy,0x0022);
		for ( nptr=mptr->first; nptr != (struct node *) 0; nptr = nptr->next )
		{
			if (!( nptr->name ))
				continue;
			else
				fprintf(h,"<nodemeta name=%c%s%c x=%c%u%c y=%c%u%c visible=%c%u%c icon=%c%s%c/>\n",
					0x0022,nptr->name,0x0022,
					0x0022,nptr->x,0x0022,
					0x0022,nptr->y,0x0022,
					0x0022,nptr->visible,0x0022,
					0x0022,nptr->icon,0x0022);
		}
		fprintf(h,"</manifestmeta>\n");
		fclose(h);
		return(0);
	}
}

/*	-------------------------------------------------------------	*/
/*			g e n e r a t e _ m a n i f e s t		*/
/*	-------------------------------------------------------------	*/
private	int	generate_manifest( struct manifest *mptr, char * filename )
{
	FILE * h;
	struct	node * nptr;
	if (!( h = fopen( filename, "w" ) ))
		return(46);
	else
	{
		fprintf(h,"<?xml version=%c1.0%c encoding=%cUTF8%c?>\n",0x0022,0x0022,0x0022,0x0022);
		fprintf(h,"<!-- Generated by the Accords Platform Manifest Editor\n Copyright (c) 2012 Iain James Marshall -->\n");
		fprintf(h,"<manifest name=%c%s%c xmlns=%c%s%c>\n",
			0x0022,(mptr->name ? mptr->name : "noname" ),0x0022,
			0x0022,(mptr->ns ? mptr->ns : "http://www.compatibleone.fr/schemes/manifest.xsd" ),0x0022 );

		for (	nptr=mptr->first;
			nptr != (struct node *) 0;
			nptr = nptr->next )
			generate_node(h, nptr );

		generate_actions( h, &mptr->configuration, "configuration" );
		generate_actions( h, &mptr->release, "release" );
		generate_actions( h, &mptr->interface, "interface" );

		fprintf(h,"\t<account name=%c%s%c/>\n",0x0022,(mptr->owner.name ? mptr->owner.name : "any"),0x0022);

		fprintf(h,"\t<security");

		if ( mptr->access.name )
		{
			fprintf(h, " name=%c%s%c",0x0022,mptr->access.name,0x0022);
		}

		if ( mptr->access.level )
		{
			fprintf(h," level=%c%s%c",0x0022,mptr->access.level,0x0022); 	
		}

		if ( mptr->access.policy )
		{
			fprintf(h," policy=%c%s%c",0x0022,mptr->access.policy,0x0022); 
		}
		fprintf(h,"/>\n");

		fprintf(h,"</manifest>\n");

		fclose(h);
		return( save_manifest_meta(mptr, filename) );
	}	
}

#endif	/* _maneditsave_c */
	/* -------------- */
