#ifndef	_ABAL_DATA_C
#define	_ABAL_DATA_C

#include "abaldata.h"
#include "singfile.h"

extern	char *	keyword_class;
extern	char *	keyword_endclass;
extern	char *	keyword_constructor;
extern	char *	keyword_destructor;
extern	char *	keyword_public;
extern	char *	keyword_private;
extern	char *	keyword_pointer;
extern	char *	keyword_inline;
extern	char *	keyword_function;
extern	char *	keyword_dcl;

private	void	check_file_Widget( struct form_item * iptr );

/*	------------------------------------	*/
/*	d r o p _ d a t a _ c o n t r o l ()	*/
/*	------------------------------------	*/

public	struct	data_control * drop_data_control( struct data_control * dptr )
{
	int	i;
	char *	nptr;
	if (( dptr )
	&&  (!( dptr->lock ))) {
		for ( i=0; i < dptr->fields; i++ )
			if ((nptr = dptr->name[i]) != (char *) 0)
				liberate( nptr );
		dptr = liberate( dptr );
		}
	return((struct data_control *) 0);
}

/*	----------------------		*/
/*	n a m e f i e l d s ()		*/
/*	----------------------		*/

private	int namefields (char * fptr, int first, struct data_control * dptr ) 
{
	int	c=0;
	int	v=0;
	int	i=0;
	int	fields=first;

	if (!( fptr )) return(0);
	if (!( dptr )) return(0);

	dptr->width[(fields=first)] = 8;
	dptr->type [fields] = _ABAL_BCD;
	dptr->name [fields] = (char *) 0;
	dptr->first[fields] = 0;
	dptr->second[fields] = 0;

	while ((c = *(fptr++)) != 0) {
		if ( c == ',' ) {
			if ( i ) {
				namebuffer [i] = 0;
				dptr->name [fields] = allocate_string(namebuffer);
				dptr->type [fields] = _ABAL_BCD;
				dptr->width[fields] = 8;
				dptr->first[fields] = 0;
				dptr->second[fields] = 0;
				i = 0;
				}
			fields++;
			continue;
			}
		else if ( c == ':' )
			continue;
		else if (( c == '.' ) 
		     ||  ( c == ';' )) {
			if ( i ) {
				namebuffer [i] = 0;
				dptr->name [fields] = allocate_string(namebuffer);
				dptr->type [fields] = _ABAL_BCD;
				dptr->width[fields] = 8;
				dptr->first[fields] = 0;
				dptr->second[fields] = 0;
				}
			fields++;
			break;
			}
		switch ( c ) {
			case	':'	:
				if ( i ) {
					namebuffer [i] = 0;
					dptr->name [fields] = allocate_string(namebuffer);
					i = 0;
					}
				dptr->type [fields] = _ABAL_LONG;
				dptr->width[fields] = 4;
				continue;
			case	'#'	:
				if ( i ) {
					namebuffer [i] = 0;
					dptr->name [fields] = allocate_string(namebuffer);
					i = 0;
					}
				dptr->type [fields] = _ABAL_BYTE;
				dptr->width[fields] = 1;
				continue;
			case	'$'	:
				if ( i ) {
					namebuffer [i] = 0;
					dptr->name [fields] = allocate_string(namebuffer);
					i = 0;
					}
				dptr->type [fields] = _ABAL_STRING;
				dptr->width[fields] = 15;
				continue;

			case	'='	:
				if ( i ) {
					namebuffer [i] = 0;
					dptr->name [fields] = allocate_string(namebuffer);
					i = 0;
					}
				if (!( dptr->type[fields] ))
					dptr->type [fields] = _ABAL_BCD; 

				while ( *fptr == ' ' )
					fptr++;
				v = 0;
				while(( *fptr >= '0' )
				&&    ( *fptr <= '9' ))
					v = ((v*10) + ( *(fptr++) - '0'));
				dptr->width[fields] = v;
				continue;

			case	'('	:
				if ( i ) {
					namebuffer [i] = 0;
					dptr->name [fields] = allocate_string(namebuffer);
					i = 0;
					}
				/* if (!( dptr->type[fields] )) dptr->type [fields] = _ABAL_BCD;  */

				while ( *fptr == ' ' )
					fptr++;
				v = 0;
				while(( *fptr >= '0' )
				&&    ( *fptr <= '9' ))
					v = ((v*10) + ( *(fptr++) - '0'));
				dptr->first[fields] = v;

				while ( *fptr == ' ' )
					fptr++;

				if ( *fptr == ',' ) {
					fptr++;

					while ( *fptr == ' ' )
						fptr++;
					v = 0;
					while(( *fptr >= '0' )
					&&    ( *fptr <= '9' ))
						v = ((v*10) + ( *(fptr++) - '0'));
					dptr->second[fields] = v;

					while ( *fptr == ' ' )
						fptr++;
					}
				if ( *fptr == ',' )
					fptr++;
				continue;


			case	0X0025	: /* percent */
				if ( i ) {
					namebuffer [i] = 0;
					dptr->name [fields] = allocate_string(namebuffer);
					i = 0;
					}
				dptr->type [fields] = _ABAL_WORD;
				dptr->width[fields] = 2;
				continue;

			default		:
				if (((c >= 'a' ) && ( c <= 'z' ))
				||  ((c >= 'A' ) && ( c <= 'Z' ))
				||  ((c >= '0' ) && ( c <= '9' ))
				||  ( c == '_' ))
					namebuffer[i++] = c;
				continue;
			}			


		}
	return((fields-first));
}
/*	----------------------		*/
/*	t y p e f i e l d s ()		*/
/*	----------------------		*/

private	int typefields (char * fptr, int first, struct data_control * dptr ) 
{
	int	c=0;
	int	v=0;
	int	i=0;
	int	fields=first;

	if (!( fptr )) return(0);
	if (!( dptr )) return(0);

	dptr->width[(fields=first)] = 0;
	dptr->type [fields] = 0;
	dptr->name [fields] = (char *) 0;

	while ((c = *(fptr++)) != 0) {

		if ( c == ')' ) {
			fields++;
			dptr->type [fields] = _ABAL_BYTE;
			dptr->name [fields] = (char *) 0;
			dptr->width[fields] = 0;
			break;
			}
		else if ( c == ',' ) {
			fields++;
			dptr->type [fields] = _ABAL_BYTE;
			dptr->name [fields] = (char *) 0;
			dptr->width[fields] = 0;
			continue;
			}
		if (( c >= 'a') && ( c <= 'z' )) { c -= ('a' - 'A'); }
		switch ( c ) {
			case	' '	:
			case	'('	:
				continue;
			case	'/'	:
			case	'T'	:
				continue;

			case	'H'	:
				dptr->type[fields] = 1;
				continue;

			case	'$'	:
			case	'L'	:
			case	'R'	:
				dptr->type[fields] = _ABAL_STRING;
				continue;

			case	'.'	:
				if ( dptr->type[fields] != _ABAL_STRING )
					dptr->type[fields] = _ABAL_BCD;
				dptr->width[fields]++;
				continue;
			case	'-'	:
			case	'+'	:
			case	'N'	:
			case	'Z'	:
			case 	'O'	: 
				if (!( dptr->type[fields] ))
					dptr->type[fields] = _ABAL_WORD;
				break;

			case	'Q'	:
			case	'D'	:
			case	'A'	:
			case	'C'	:
			case	'B'	:
			case	'W'	:
			case	'U'	: 
				dptr->type[fields] = _ABAL_STRING;
				break;

			default		:
				continue;
			}
		for ( v = 1; *fptr == c; fptr++ )
			v++;
		if (( *fptr >= '0' )
		&&  ( *fptr <= '9' )) {
			i = 0;
			while(( *fptr >= '0' )
			&&    ( *fptr <= '9' )) {
				i = ((i*10) + ( *(fptr++) - '0'));
				}
			v = ((v-1) + i);
			}
		dptr->width[fields] += v;
		continue;
		}
	for (i=first; i < fields; i++ ) {
		if ( dptr->type[i] == _ABAL_STRING )
			continue;
		else if (( dptr->type[i] == _ABAL_WORD )
		     &&  ( dptr->width[i] < 5 )) {
			dptr->width[i] = 2;
			continue;
			}
		dptr->type[i] = _ABAL_BCD;
		dptr->width[i] = (((dptr->width[i]+1)/2) + ((dptr->width[i]+1)&1));
		}
	return((fields-first));
}

/*	--------------------------------------------		*/
/*	a l l o c a t e _ d a t a _ c o n t r o l ()		*/
/*	--------------------------------------------		*/

private	struct	data_control * allocate_data_control()
{
	int	i;
	struct	data_control * dptr=(struct data_control *) 0;
	if (!( dptr = allocate( sizeof(struct data_control ) ) ))
		return( dptr );
	else	{
		for ( i=0; i < MAX_DATA_FIELDS; i++ ) {
			dptr->width[i] = 0;
			dptr->type [i] = _ABAL_BYTE;
			dptr->name [i] = (char *) 0;
			}
		dptr->image = (struct standard_image *) 0;
		dptr->lock   = 0;
		dptr->option = 0; 
		dptr->indexlength = dptr->datalength = 0;
		dptr->fields = dptr->indexfields = dptr->datafields = 0;
		dptr->firstfile = dptr->lastfile = (struct include_control *) 0;
		dptr->indexname = dptr->recordname = (char *) 0;
		return( dptr );
		}
}

/*	----------------------------------	*/
/*	c o l l e c t _ d a t a n a m e ()	*/
/*	----------------------------------	*/

private	char	*	collect_dataname( char ** rptr, char * sptr )
{
	int	i;
	int	n;
	char *	nptr;
	while ( *sptr == ' ' )
		sptr++;
	i=0;
	while ( *(sptr+1) ) {
		if ((( *(sptr+i) >= 'a' ) && ( *(sptr+i) <= 'z' ))
		||  (( *(sptr+i) >= 'A' ) && ( *(sptr+i) <= 'Z' ))
		||  (( *(sptr+i) >= '0' ) && ( *(sptr+i) <= '9' ))
		||  ( *(sptr+i) == '_'  )) {
			i++;
			}
		else	break;
		}
	if (!( i ))
		return( sptr );
	else 	{
		if (( nptr = *rptr ) != (char *) 0)
			liberate( nptr );
		if (!( nptr = allocate( i+1 ) )) 
			return((sptr+i));
		else	{
			for ( n=0; n < i; n++ )
				*(nptr+n) = *(sptr+n);
			*(nptr+n) = 0;
			*rptr = nptr;
			return( (sptr+i) );
			}
		}
}

/*	------------------------------------------		*/
/*	a n a l y s e _ d a t a _ c o n t r o l ()		*/
/*	------------------------------------------		*/
private	void	symbolic_data_member( FILE * h, struct data_control * dptr, int i )
{
	fprintf(h,"%s",dptr->name[i]);
	switch ( dptr->type[i] ) {
		case	_ABAL_BYTE	: fprintf(h,"#"); break;
		case	_ABAL_WORD	: fprintf(h,"%%"); break;
		case	_ABAL_LONG	: fprintf(h,":"); break;
		case	_ABAL_STRING	: fprintf(h,"$"); 
		case	_ABAL_BCD 	: fprintf(h,"=%u",dptr->width[i]); break;
		}
	if ( dptr->first[i] > 0 ) {
		fprintf(h,"(%u",dptr->first[i]);
		if ( dptr->second[i] > 0 )
			fprintf(h,",%u",dptr->second[i]);
		fprintf(h,")");
		}
	return;
}

public	int	symbolic_data_control( FILE * h, struct form_item * iptr, char * tag )
{
	struct data_control * dptr;
	int	t;
	int	i;
	char *	nptr;
	if (!( dptr = iptr->Contents.extra ))
		return(0);

	fprintf(h,"<%s>",tag);	

	if ((nptr = iptr->Contents.format) != (char *) 0)
		fprintf(h,"%s ",nptr);

	switch ((t = (iptr->Contents.align & 0x000F))) {

		case	_SIFILE_FRAME 	:
		case	_MCFILE_FRAME 	:

			if (!( dptr ))
				fprintf(h,"K=");	
			else if ( dptr->option & _A_LEFT )
				fprintf(h,"LK=");	
			else if ( dptr->option & _A_RIGHT )
				fprintf(h,"RK=");	
			else	fprintf(h,"K=");	

			fprintf(h,"%u",iptr->Contents.xlimit);

			if ( dptr->indexlength ) {
				fprintf(h," : ");
				for (i=0; i < dptr->indexfields; i++ ) {
					if ( i )
						fprintf(h,",");
					symbolic_data_member( h, dptr, i );
					}
				fprintf(h," ; ");
				}

			}
	if (( dptr )
	&&  ( dptr->option & _A_BOLD ))
		fprintf(h,"VD=");
	else	fprintf(h,"D=");

	fprintf(h,"%u",iptr->Contents.ylimit);

	if ( dptr->datalength ) {
		fprintf(h," : ");
		for (i=0; i < dptr->datafields; i++ ) {
			if ( i )
				fprintf(h,",");
			symbolic_data_member( h, dptr, i+dptr->indexfields );
			}
		fprintf(h," ; ");
		}

	fprintf(h,"</%s>\n",tag);

	return(1);

}

public	struct	data_control * analyse_data_control( char * fptr )
{
	struct	data_control * dptr=(struct data_control *) 0;
	char *	wptr=(char *) 0;
	int	mode=0;
	int	flags=0;
	int	i=0;
	int	c;
	int	v=0;

	/* valid format string provided */
	/* ---------------------------- */
	if (( wptr = fptr ) != (char *) 0) {
		/* format class name provided */
		/* -------------------------- */
		if  ( *wptr == '(' ) {
			if ((dptr = resolve_class_data((void *) 0, wptr )) != (struct data_control *) 0) {
				dptr->lock=1;
				return( dptr );
				}
			}
		}

	if (!( dptr = allocate_data_control() ))
		return( dptr );

	if  (!(wptr = fptr))  
		return(dptr);

	/* Detect and step over class name */
	/* ------------------------------- */
	if ( *wptr == '(' ) {
		wptr++;
		while ( *wptr != 0 ) {
			if ( *wptr == ')' ) {
				wptr++;
				break;
				}
			else	wptr++;
			}
		}

	/* Analyse remaining string */
	/* ------------------------ */
	while ((c = *(wptr++)) != 0) {

		switch ( c ) {

			case	'L'	:
			case	'l'	:
				dptr->option |= _A_LEFT;
				continue;

			case	'R'	:
			case	'r'	:
				dptr->option |= _A_RIGHT;
				continue;

			case	'V'	:
			case	'v'	:
				dptr->option |= _A_BOLD;
				continue;

			case	','	:
			case	' '	:
			case	'+'	:
			case	'|'	:
				continue;
			case	'K'	:
			case	'k'	:
				mode = 'I'; continue;
			case	'D'	:
			case	'd'	:
				mode = 'D'; continue;
			case	'='	:
				while ( *wptr == ' ')
					wptr++;
				v	=	0;

				while (( *wptr >= '0') && ( *wptr <= '9'))
					v = ((v * 10) + ( *(wptr++) - '0' ));

				if ( mode == 'I' ) {
					if (!( dptr->indexlength )) {
						if (!( dptr->indexlength = v )) {
							/* collect index variable name */
							/* --------------------------- */
							wptr = collect_dataname( &dptr->indexname, wptr );
							}
						}
					else	return( drop_data_control(dptr) );
					}
				else if (!( dptr->datalength )) {
					if (!( dptr->datalength = v )) {
						/* collect record variable name */
						/* ---------------------------- */
						wptr = collect_dataname( &dptr->recordname, wptr );
						}
					}
				else	return( drop_data_control(dptr) );

				continue;

			case	':'	:

				/* Detect and collect Typed or Format information */
				/* ---------------------------------------------- */
				if ( mode == 'I' ) {
					if (!( dptr->indexfields ))
						dptr->indexfields = namefields( wptr, 0, dptr );
					else	return( drop_data_control(dptr) );
					}
				else if (!( dptr->datafields ))
					dptr->datafields = namefields( wptr, dptr->indexfields, dptr );
				else	return( drop_data_control(dptr) );

				while ( *wptr ) {
					if ((c = *(wptr++)) == '.' )
						break;
					else if ( c == ';' )
						break;
					}
				continue;
			
			case	'('	:
				/* Detect and collect Typed or Format information */
				/* ---------------------------------------------- */
				if ( mode == 'I' ) {
					if (!( dptr->indexfields ))
						dptr->indexfields = typefields( wptr, 0, dptr );
					else	return( drop_data_control(dptr) );
					}
				else if (!( dptr->datafields ))
					dptr->datafields = typefields( wptr, dptr->indexfields, dptr );
				else	return( drop_data_control(dptr) );

				while ( *wptr )
					if ( *(wptr++) == ')' )
						break;
				continue;

			case	'\t'	:
			case	'\r'	:
			case	'\n'	:
			case	';'	:
				continue;


			default		:
				return( drop_data_control(dptr) );
			}

		}

	dptr->fields = dptr->indexfields + dptr->datafields;

	if (!( dptr->indexlength )) {
		for (i=0; i < dptr->indexfields; i++ ) {
			dptr->indexlength += (dptr->width[i] * ( dptr->first[i] ? dptr->first[i] : 1 ) * ( dptr->second[i] ? dptr->second[i] : 1 ));
			}
		}

	if (!( dptr->datalength )) {
		for (i=0; i < dptr->datafields; i++ ) {
			dptr->datalength += ( dptr->width[i+dptr->indexfields] 
					    *( dptr->first[i+dptr->indexfields] ? dptr->first[i+dptr->indexfields] : 1 )
					    *( dptr->second[i+dptr->indexfields] ? dptr->second[i+dptr->indexfields] : 1 ));
			}
		}
	return( dptr );
}

/*	-----------------------------------	*/
/*	c h e c k _ da t a _ w i d g e t ()	*/
/*	-----------------------------------	*/
private	int	check_file_Class( struct form_item *  iptr )
{
	char	*	fptr;
	char	*	sptr;
	char	*	wptr;
	char	*	rptr;
	struct data_control * dptr;
	int	t;
	if (!( fptr = iptr->Contents.format ))
		return(0);
	else if ( *fptr != '(' )
		return(0);
	else 	{
		sptr = fptr;
		sptr++;
		wptr = sptr;
		while ( *sptr != 0 ) {
			if ( *sptr == ')' )
				break;
			else	sptr++;
			}
		if ( *sptr != ')' )
			return(0);
		else 	{
			*sptr = 0;
			if (!(dptr = resolve_class_data((void *) 0, wptr ))) {
				sptr++;
				AddFileClass((void*)0,iptr->Contents.align, wptr, iptr->Contents.name,iptr->Contents.payload, sptr );
				}
			if (!( rptr = allocate( strlen( wptr ) + 8 ) )) {
				return(0);
				}
			sprintf(rptr,"(%s)",wptr);
			iptr->Contents.format = rptr;
			liberate( fptr );
			return(1);
			}
		}
}


public	void	check_data_widget( struct form_item * iptr )
{
	char			* fptr;
	struct	data_control 	* dptr;

	iptr->Contents.extra = drop_data_control( iptr->Contents.extra );
	iptr->Contents.xlimit = iptr->Contents.ylimit = 0;

	if (( iptr->Contents.align & 0x000F ) == _VISUAL_FRAME) {
		iptr->Contents.extra = allocate_data_control();
		}
	else if ( iptr->Contents.format != (char *) 0) {
		if ( iptr->Contents.w <= 30 ) iptr->Contents.w = 30;
		if ( iptr->Contents.h <= 40 ) iptr->Contents.h = 40;

		/* convert explicite direct file format to indirect database class format */
		/* ---------------------------------------------------------------------- */
		if (( *iptr->Contents.format != '(' ))
			check_file_Widget( iptr );
		else 	check_file_Class( iptr );

		if ((dptr = analyse_data_control( iptr->Contents.format )) != (struct data_control *) 0) {
			iptr->Contents.xlimit = dptr->indexlength;
			iptr->Contents.ylimit = dptr->datalength;
			iptr->Contents.extra = dptr;
			}
		}
	return;
}

/*	--------------------------------------------	*/
/*	a b a l _ f i l e _ m e m b e r _ n a m e ()	*/
/*	--------------------------------------------	*/

public	void	abal_file_member_name(FILE * h, struct form_item * iptr,int f )
{
	struct data_control * dptr;

	if (!(dptr = iptr->Contents.extra ))
		fprintf(h,"_m%u_%s",f,iptr->Contents.name);
	else if (!( dptr->name[f] ))
		fprintf(h,"_m%u_%s",f+1,iptr->Contents.name);
	else	fprintf(h,"_%s_%s",dptr->name[f],iptr->Contents.name);
	return;
}

public  void	redefine_file_instance(
			FILE * h, 
			char * member, 
 			struct form_item * iptr, 
			int first, int fields,
			struct data_control * dptr )
{
	int	f;
	abal_field(h,member,iptr->Contents.name);
	for (f=0; f < fields; f++ ) {
		if ( dptr->name[f+first] != (char *) 0 )
			sprintf(namebuffer,"_%s_",dptr->name[f+first]);
		else	sprintf(namebuffer,"_m%u_",f);
		abal_dcl(h,namebuffer,iptr->Contents.name,dptr->type[f+first],dptr->width[f+first],dptr->first[f+first],dptr->second[f+first]);
		}
	abal_field(h,member,iptr->Contents.name);
	return;
}

private void	reset_vmem_fields(FILE * h, struct form_item * iptr,struct data_control * dptr, int first )
{
	int	f;
	char *	nptr;
	if (!( dptr ))	return;
	for (f=0; f < dptr->datafields; f++ ) {
		if ((nptr = dptr->name[(f+first)]) != (char *) 0 )
			sprintf(namebuffer,"_%s_",nptr);
		else	sprintf(namebuffer,"_m%u_",(f+first));
		switch ( dptr->type[f+first] ) {
			case	_ABAL_BYTE	:
			case	_ABAL_WORD	:
			case	_ABAL_LONG	:
			case	_ABAL_BCD 	:
				if ( dptr->first[f+first] <= 1 ) {
					indent(h,2);
					fprintf(h,"%s%s=0",namebuffer,iptr->Contents.name);
					linefeed(h);
					}
				break;
			case	_ABAL_STRING	:
				if ( dptr->first[f+first] <= 1 ) {
					indent(h,2);
					fprintf(h,"%s%s=%c %c",namebuffer,iptr->Contents.name,0x0022,0x0022);
					linefeed(h);
					}
				break;
			}
		}
	return;
}

private	char *	abal_data_reset(FILE * h, struct form_item * iptr )
{
	struct	data_control * 	dptr;
	if (( dptr = iptr->Contents.extra) != (struct data_control *) 0)
		reset_vmem_fields( h, iptr, dptr, dptr->indexfields );

	return((char *) 0);
}


public  void	abal_vmem_instance(FILE * h, struct form_item * iptr, int t )
{
	struct	data_control * 	dptr;
	int	f;
	if (!(dptr = iptr->Contents.extra ))
		return;

	abal_dcl(h,"e_",iptr->Contents.name,_ABAL_WORD,0,0,0);
	abal_dcl(h,"h_",iptr->Contents.name,_ABAL_WORD,0,0,0);
	abal_vfield(h,dptr->datalength);
	for (f=0; f < dptr->datafields; f++ ) {
		if ( dptr->name[f] != (char *) 0 )
			sprintf(namebuffer,"_%s_",dptr->name[f]);
		else	sprintf(namebuffer,"_m%u_",f);
		abal_dcl(h,namebuffer,iptr->Contents.name,dptr->type[f],dptr->width[f],dptr->first[f],dptr->second[f]);
		}
	abal_field(h,(char *)0, (char *) 0);
	return;

}

public  void	abal_file_instance(FILE * h, struct form_item * iptr, int t )
{
	char	*		root;
	char	*		fptr;
	char	*		tptr;
	char	*		lptr;
	int			klen=32;
	int			datalength=512;
	int			xlen=5;
	int			c;
	int			f;
	int			fields=0;
	struct	data_control * 	dptr;
	int	first=0;

	if ((dptr = iptr->Contents.extra )  != (struct data_control *) 0) {
		iptr->Contents.extra = dptr;
		fields = dptr->indexfields + dptr->datafields;
		klen = dptr->indexlength;
		datalength = dptr->datalength;
		first= dptr->indexfields;
		}
	else	first = 0;

	if ( t == _MCFILE_FRAME ) { xlen += (fields*32); }

	if ( iptr->Contents.datatype == _WIDGET_POINTER )
		abal_ptr(h,"r_",iptr->Contents.name,_ABAL_STRING,datalength+klen+xlen,0,0);
	else	abal_dcl(h,"r_",iptr->Contents.name,_ABAL_STRING,datalength+klen+xlen,0,0);

	abal_field(h,"r_",iptr->Contents.name);
	abal_dcl(h,"e_",iptr->Contents.name,_ABAL_WORD,0,0,0);
	abal_dcl(h,"h_",iptr->Contents.name,_ABAL_WORD,0,0,0);

	if ( t == _MCFILE_FRAME ) {
		abal_dcl(h,"t_",iptr->Contents.name,_ABAL_STRING,(fields*32),0,0);
		abal_dcl(h,"q_",iptr->Contents.name,_ABAL_STRING,1024,0,0);
		abal_dcl(h,"n_",iptr->Contents.name,_ABAL_WORD,2,0,0);
		abal_dcl(h,"i_",iptr->Contents.name,_ABAL_WORD,2,0,0);
		abal_ptr(h,"p_",iptr->Contents.name,_ABAL_STRING,klen,2,0);
		}

	if ((dptr != (struct data_control *) 0)
	&&  (dptr->option & _A_BOLD)) {
		abal_dcl(h,"l_",iptr->Contents.name,_ABAL_WORD,0,0,0);
		}


	if ( klen ) {
		abal_dcl(h,"k_",iptr->Contents.name,_ABAL_STRING,klen,0,0);
		if ((dptr != (struct data_control *) 0)
		&&  (dptr->indexfields != 0 )) {
			redefine_file_instance(h,"k_",iptr,0,dptr->indexfields, dptr);
			abal_filler(h,dptr->indexlength);
			}
		abal_dcl(h,"m_",iptr->Contents.name,_ABAL_BYTE,0,0,0);
		}

	if ( datalength ) {
		abal_dcl(h,"b_",iptr->Contents.name,_ABAL_STRING,datalength,0,0);
		if ((dptr != (struct data_control *) 0)
		&&  (dptr->datafields != 0 )) {
			redefine_file_instance(h,"b_",iptr,dptr->indexfields,dptr->datafields, dptr);
			abal_filler(h,dptr->datalength);
			}
		}
	abal_field(h,(char*) 0,(char *) 0);
	return;
}
	
public  int	abal_data_instance(FILE * h, struct form_item * iptr )
{
	int	t;
	switch ((t = (iptr->Contents.align & 0x000F)) ) {
		case	_OBJECT_FRAME	:
			if ( iptr->Contents.datatype == _WIDGET_POINTER )
				fprintf(h,"%s %s %s",abal_payload(iptr),"pointer",iptr->Contents.name);
			else	fprintf(h,"%s %s",abal_payload(iptr),iptr->Contents.name);
			if ( method_is_valid( iptr->Contents.format ) )
				fprintf(h,"(%s)",iptr->Contents.format);
			linefeed(h);
			break;
		case	_VISUAL_FRAME	:
			if ( iptr->Contents.datatype == _WIDGET_POINTER )
				fprintf(h,"%s %s %s",abal_payload(iptr),"pointer",iptr->Contents.name);
			else	fprintf(h,"%s %s",abal_payload(iptr),iptr->Contents.name);
			fprintf(h,"(%s;%s)",widget_x_position(iptr,0),widget_y_position(iptr,0));
			linefeed(h);
			break;
		case	_VARIABLE_FRAME :
			switch ( iptr->Contents.datatype ) {
				case	_WIDGET_BYTE		:	
					abal_dcl(h,"\0",iptr->Contents.name,_ABAL_BYTE,1,0,0);
					break;
				case	_WIDGET_WORD		:	
					abal_dcl(h,"\0",iptr->Contents.name,_ABAL_BYTE,2,0,0);
					break;
				case	_WIDGET_LONG		:	
					abal_dcl(h,"\0",iptr->Contents.name,_ABAL_LONG,4,0,0);
					break;
				case	_WIDGET_FLOAT		:	
					abal_dcl(h,"\0",iptr->Contents.name,_ABAL_BCD,4,0,0);
					break;
				case	_WIDGET_NUMERIC		:	
					abal_dcl(h,"\0",iptr->Contents.name,_ABAL_BCD,8,0,0);
					break;
				case	_WIDGET_STRING		:	
					abal_dcl(h,"\0",iptr->Contents.name,_ABAL_STRING,15,0,0);
					break;
				}
			break;
		case	_VMEMORY_FRAME	:
			abal_vmem_instance(h,iptr,t);
			break;

		case	_SQFILE_FRAME	:
		case	_DBFILE_FRAME	:
		case	_SIFILE_FRAME	:
		case	_MCFILE_FRAME	:
			abal_file_instance(h,iptr,t);
		}
	return(0);
}

public	void	abal_ngf_errortrap(FILE * h, struct form_item* iptr, char * label )
{
	if (!( label ))
		label = __abal_keyword_next;
	fprintf(h,":%s,e_%s",label,iptr->Contents.name);
	return;
}

public	void	abal_ngf_instruction(FILE * h, struct form_item* iptr, char * keyword, int margin )
{
	indent(h,margin);
	fprintf(h,"%s=h_%s",keyword,iptr->Contents.name);
	return;
}

public	void	abal_ngf_assign(FILE * h, struct form_item* iptr, int margin )
{
	int	t=(iptr->Contents.align & 0x000F);
	abal_ngf_instruction(h,iptr,__abal_keyword_assign,margin);
	filename_parameter(h,abal_payload(iptr));
	switch ( t ) {
		case	_VMEMORY_FRAME	:	fprintf(h,",WR"); 	break;
		case	_SIFILE_FRAME	:	fprintf(h,",SI,WR"); 	break;
		case	_MCFILE_FRAME	:	fprintf(h,",MC,WR"); 	break;
		}
	abal_ngf_errortrap(h,iptr,(char *) 0);
	if ( t == _MCFILE_FRAME ) { fprintf(h,",t_%s",iptr->Contents.name); }
	linefeed(h);
	return;
}

public	void	abal_ngf_open(FILE * h, struct form_item* iptr, int margin )
{
	abal_ngf_instruction(h,iptr,__abal_keyword_open,margin);
	abal_ngf_errortrap(h,iptr,(char *) 0);
	linefeed(h);
	return;
}

public	void	abal_ngf_close(FILE * h, struct form_item* iptr, int margin )
{
	abal_ngf_instruction(h,iptr,__abal_keyword_close,margin);
	abal_ngf_errortrap(h,iptr,(char *) 0);
	linefeed(h);
	return;
}
public	void	abal_indexname_parameter(FILE * h, struct form_item* iptr )
{
	struct	data_control * dptr=(struct data_control *) 0;
	if ((( dptr = iptr->Contents.extra ) != (struct data_control*)0)
	&&  ( dptr->indexname != (char *) 0))
		fprintf(h,",%s",dptr->indexname);
	else	fprintf(h,",k_%s",iptr->Contents.name);
	return;
}

public	void	abal_recordname_parameter(FILE * h, struct form_item* iptr )
{
	struct	data_control * dptr=(struct data_control *) 0;
	if ((( dptr = iptr->Contents.extra ) != (struct data_control*)0)
	&&  ( dptr->recordname != (char *) 0))
		fprintf(h,",%s",dptr->recordname);
	else	fprintf(h,",b_%s",iptr->Contents.name);
	return;
}

public	void	abal_lengthname_value(FILE * h, struct form_item* iptr )
{
	fprintf(h,"l_%s",iptr->Contents.name);
	return;
}

public	void	abal_lengthname_parameter(FILE * h, struct form_item* iptr )
{
	fprintf(h,",");
	abal_lengthname_value(h,iptr);
	fprintf(h,",2");
	return;
}

private	void	abal_indexsize_value(FILE * h, struct form_item * iptr)
{
	struct	data_control * dptr=(struct data_control *) 0;
	if ((( dptr = iptr->Contents.extra ) != (struct data_control*)0)
	&&  ( dptr->indexname != (char *) 0))
		fprintf(h,"Len(%s)",dptr->indexname);
	else	fprintf(h,"%u",iptr->Contents.xlimit);
	return;
}

private	void	abal_recordsize_value(FILE * h, struct form_item * iptr)
{
	struct	data_control * dptr=(struct data_control *) 0;
	if ((( dptr = iptr->Contents.extra ) != (struct data_control*)0)
	&&  ( dptr->recordname != (char *) 0))
		fprintf(h,"Len(%s)",dptr->recordname);
	else	fprintf(h,"%u",iptr->Contents.ylimit);
	return;
}

public	void	abal_ngf_cfile(FILE * h, struct form_item* iptr, int margin )
{
	struct	data_control * 	dptr;
	int			t;
	if (!( iptr ))	return;

	t = (iptr->Contents.align & 0x000F);
	abal_ngf_instruction(h,iptr,__abal_keyword_cfile,margin);

	dptr = iptr->Contents.extra;

	switch ((t = (iptr->Contents.align & 0x000F))) {

		case	_DBFILE_FRAME	:
				break;

		case	_SQFILE_FRAME	:
			if (( dptr )
			&&  ( dptr->option & _A_BOLD ))
				fprintf(h,",VD=");
			else	fprintf(h,",D=");

			abal_recordsize_value(h,iptr);
			break;

		case	_SIFILE_FRAME 	:
		case	_MCFILE_FRAME 	:
			if (( dptr )
			&&  ( dptr->option & _A_BOLD ))
				fprintf(h,",VD=");
			else	fprintf(h,",D=");

			abal_recordsize_value(h,iptr);

			if (!( dptr ))
				fprintf(h,",K=");	
			else if ( dptr->option & _A_LEFT )
				fprintf(h,",LK=");	
			else if ( dptr->option & _A_RIGHT )
				fprintf(h,",RK=");	
			else	fprintf(h,",K=");	
			abal_indexsize_value(h,iptr);
		}

	abal_ngf_errortrap(h,iptr,(char *) 0);
	linefeed(h);
	return;
}
public	void	abal_ngf_dfile(FILE * h, struct form_item* iptr, int margin )
{
	abal_ngf_instruction(h,iptr,__abal_keyword_dfile,margin);
	abal_ngf_errortrap(h,iptr,(char *) 0);
	linefeed(h);
	return;
}

private	void	abal_search_length(FILE * h, struct form_item* iptr, int margin )
{
	abal_ngf_instruction(h,iptr,__abal_keyword_search_l,margin);
	abal_indexname_parameter(h,iptr);
	fprintf(h,",/FF");
	abal_ngf_errortrap(h,iptr,(char *) 0);
	abal_lengthname_parameter(h,iptr);
	linefeed(h);
	return;
}

private	void	abal_search_record(FILE * h, struct form_item* iptr, int margin )
{
	struct	data_control * dptr;

	abal_ngf_instruction(h,iptr,__abal_keyword_search,margin);
	abal_indexname_parameter(h,iptr);
	fprintf(h,",/FF");
	abal_ngf_errortrap(h,iptr,(char *) 0);
	abal_recordname_parameter(h,iptr);

	if ((( dptr = iptr->Contents.extra ) != (struct data_control*)0)
	&&  ( dptr->option & _A_BOLD)) {
		fprintf(h,",");
		abal_lengthname_value(h,iptr);
		}

	linefeed(h);
}

public	void	abal_ngf_search(FILE * h, struct form_item* iptr, int margin )
{
	struct	data_control * dptr;

	if ((( dptr = iptr->Contents.extra ) != (struct data_control*)0)
	&&  ( dptr->option & _A_BOLD))
		abal_search_length(h,iptr,margin);

	abal_search_record(h,iptr,margin);
	return;
}

public	void	abal_ngf_locate(FILE * h, struct form_item* iptr, int margin )
{
	struct	data_control * 	dptr;
	char *			tptr;


	/* recover member identifier */
	/* ------------------------- */
	if (!( tptr = abal_dimension()))
		tptr = "1";

	/* ensure legal dimension */
	/* ---------------------- */
	fprintf(h,"if ( %s <= n_%s )",tptr,iptr->Contents.name);
	linefeed(h);

		/* ensure valid pointer */
		/* -------------------- */
		indent(h,++margin); 
		fprintf(h,"if ( validptr(p_%s) <> 0 )",iptr->Contents.name);
		linefeed(h);

			/* position primary index value from the collection */
			/* ------------------------------------------------ */
			indent(h,++margin); 
			fprintf(h,"k_%s=p_%s(%s)",iptr->Contents.name,iptr->Contents.name,tptr);
			linefeed(h);
			abal_ngf_search(h,iptr,margin);

		/* illegal pointer error */
		/* --------------------- */
		indent(h,--margin);
		fprintf(h,"else :: e_%s=118 :: endif",iptr->Contents.name);
		linefeed(h);


	/* exceeding bounds error */
	/* ---------------------- */
	indent(h,--margin);
	fprintf(h,"else :: e_%s=103 :: endif",iptr->Contents.name);
	linefeed(h);
	
	return;
}

public	void	abal_ngf_down(FILE * h, struct form_item* iptr, int margin )
{
	struct	data_control * dptr;

	abal_ngf_instruction(h,iptr,__abal_keyword_down,margin);
	fprintf(h,",/FF");
	abal_ngf_errortrap(h,iptr,(char *) 0);
	if ((( dptr = iptr->Contents.extra ) != (struct data_control*)0)
	&&  ( dptr->option & _A_BOLD)) {
		abal_lengthname_parameter(h,iptr);
		}
	else	{
		abal_indexname_parameter(h,iptr);
		fprintf(h,",");
		abal_recordsize_value(h,iptr);
		}
	fprintf(h,"+");
	abal_indexsize_value(h,iptr);
	fprintf(h,"+1");
	linefeed(h);

	if ((( dptr = iptr->Contents.extra ) != (struct data_control*)0)
	&&  ( dptr->option & _A_BOLD)) {
		abal_search_record(h,iptr,margin);
		}
	return;
}
public	void	abal_ngf_up(FILE * h, struct form_item* iptr, int margin )
{
	struct	data_control * dptr;

	abal_ngf_instruction(h,iptr,__abal_keyword_up,margin);
	fprintf(h,",/FF");
	abal_ngf_errortrap(h,iptr,(char *) 0);
	if ((( dptr = iptr->Contents.extra ) != (struct data_control*)0)
	&&  ( dptr->option & _A_BOLD)) {
		abal_lengthname_parameter(h,iptr);
		}
	else	{
		abal_indexname_parameter(h,iptr);
		fprintf(h,",");
		abal_recordsize_value(h,iptr);
		}

	fprintf(h,"+");
	abal_indexsize_value(h,iptr);
	fprintf(h,"+1");
	linefeed(h);

	if ((( dptr = iptr->Contents.extra ) != (struct data_control*)0)
	&&  ( dptr->option & _A_BOLD)) {
		abal_search_record(h,iptr,margin);
		}
	return;
}
public	void	abal_ngf_first(FILE * h, struct form_item* iptr, int margin )
{
	indent(h,margin);
	fprintf(h,"k_%s=gener(Len(k_%s),Chr$(/00))",
		iptr->Contents.name,iptr->Contents.name);
	linefeed(h);
	abal_ngf_search(h,iptr,margin);
	abal_ngf_down(h,iptr,margin);
	return;
}
public	void	abal_ngf_last(FILE * h, struct form_item* iptr, int margin )
{
	indent(h,margin);
	fprintf(h,"k_%s=gener(Len(k_%s),Chr$(/FF))",
		iptr->Contents.name,iptr->Contents.name);
	linefeed(h);
	abal_ngf_search(h,iptr,margin);
	abal_ngf_up(h,iptr,margin);
	return;
}

public	void	abal_ngf_insert(FILE * h, struct form_item* iptr, int margin )
{
	struct	data_control * dptr;

	abal_ngf_instruction(h,iptr,__abal_keyword_insert,margin);
	abal_indexname_parameter(h,iptr);
	abal_ngf_errortrap(h,iptr,(char *) 0);
	abal_recordname_parameter(h,iptr);
	if ((( dptr = iptr->Contents.extra ) != (struct data_control*)0)
	&&  ( dptr->option & _A_BOLD)) {
		fprintf(h,",");
		abal_lengthname_value(h,iptr);
		}
	linefeed(h);
	return;
}

private	int	abal_ngf_method( struct form_item * iptr )
{
	return( (iptr->Contents.align & 0x000F) );
}

public	void	abal_ngf_posit(FILE * h, struct form_item* iptr, int margin )
{
	if ( abal_ngf_method(iptr) == _MCFILE_FRAME ) {
		abal_ngf_instruction(h,iptr,__abal_keyword_posit,margin);
		fprintf(h,",q_%s",iptr->Contents.name);
		abal_ngf_errortrap(h,iptr,(char *) 0);
		fprintf(h,",i_%s",iptr->Contents.name);
		linefeed(h);
		}
	return;
}

public	void	abal_ngf_positd(FILE * h, struct form_item* iptr, int margin )
{
	if ( abal_ngf_method(iptr) == _MCFILE_FRAME ) {
		indent(h,margin);
		fprintf(h,"%s.D=h_%s",__abal_keyword_posit,iptr->Contents.name);
		fprintf(h,",q_%s",iptr->Contents.name);
		abal_ngf_errortrap(h,iptr,(char *) 0);
		fprintf(h,",i_%s",iptr->Contents.name);
		linefeed(h);
		}
	return;
}

public	void	abal_ngf_count(FILE * h, struct form_item* iptr, int margin )
{
	if ( abal_ngf_method(iptr) == _MCFILE_FRAME ) {
		abal_ngf_instruction(h,iptr,__abal_keyword_count,margin);
		fprintf(h,",q_%s",iptr->Contents.name);
		abal_ngf_errortrap(h,iptr,(char *) 0);
		fprintf(h,",n_%s",iptr->Contents.name);
		linefeed(h);
		}
	return;
}


public	void	abal_ngf_collect(FILE * h, struct form_item* iptr, int margin )
{
	int	direction=0;

	char *	tptr;
	if ( abal_ngf_method(iptr) != _MCFILE_FRAME ) {
		remove_brackets(); 
		return;
		}
	else	{

		direction = check_direction();

		/* Detect provided collect expression */
		/* ---------------------------------- */
		if (( tptr = abal_dimension()) != (char *) 0 ) {
			fprintf(h,"q_%s = %s",iptr->Contents.name,tptr);
			linefeed(h);
			}


		/* release the current collection */
		/* ------------------------------ */	
		fprintf(h,"%s p_%s",
			__abal_keyword_remove,
			iptr->Contents.name);
		linefeed(h);

		/* calculate collection size */
		/* ------------------------- */
		abal_ngf_count(h,iptr,margin);

		/* allocate for collection storage */
		/* ------------------------------- */
		indent(h,margin++);
			fprintf(h,"if ( n_%s > 0 )",iptr->Contents.name);
		linefeed(h);
		indent(h,margin); 
		fprintf(h,"%s p_%s(Len(k_%s),n_%s)",
				__abal_keyword_create,
				iptr->Contents.name,iptr->Contents.name,iptr->Contents.name); 
		linefeed(h);

			/* collect first item */
			/* ------------------ */
			if (!( direction )) {
				abal_ngf_posit(h,iptr,margin);
				abal_ngf_down(h,iptr,margin);
				}
			else	{
				abal_ngf_positd(h,iptr,margin);
				abal_ngf_up(h,iptr,margin);
				}

			/* until collection end */
			/* -------------------- */
			indent(h,margin); 
			fprintf(h,"i_%s = 0",iptr->Contents.name);
			linefeed(h);
			indent(h,margin++); 
			fprintf(h,"while (e_%s = 0)",iptr->Contents.name); 
			linefeed(h);

				/* store the item */
				/* -------------- */
				indent(h,margin); 
				fprintf(h,"i_%s += 1 :: p_%s(i_%s) = k_%s",iptr->Contents.name,iptr->Contents.name,iptr->Contents.name,iptr->Contents.name); 
				linefeed(h);

				/* collect next item */
				/* ----------------- */
				if (!( direction ))
					abal_ngf_down(h,iptr,margin);
				else	abal_ngf_up(h,iptr,margin);

			abal_wend(h,--margin);
	
		abal_endif(h,margin);	
		}
	return;
}

public	void	abal_ngf_key(
	FILE * h, 
	struct form_item* iptr, 
	int margin,
	char *	rubname,
	int	rubtype,
	int	rubsize 
	)
{
	if ( abal_ngf_method(iptr) == _MCFILE_FRAME ) {
		abal_ngf_instruction(h,iptr,__abal_keyword_key,margin);
		fprintf(h,",%c%s%c",0x0022,rubname,0x0022);
		switch ( rubtype ) {
			case	_ABAL_BCD	: fprintf(h,",%u,B",rubsize); break;
			case	_ABAL_STRING	: fprintf(h,",%u,A",rubsize); break;	
			case	_ABAL_BYTE	: fprintf(h,",1,N"); break;
			case	_ABAL_WORD 	: fprintf(h,",2,N"); break;
			case	_ABAL_LONG 	: fprintf(h,",4,N"); break;
			}
		abal_ngf_errortrap(h,iptr,(char *) 0);
		linefeed(h);
		}
	return;
}

public	void	abal_ngf_ckey(FILE * h, struct form_item* iptr, int margin )
{
	if ( abal_ngf_method(iptr) == _MCFILE_FRAME ) {
		abal_ngf_instruction(h,iptr,__abal_keyword_ckey,margin);
		abal_ngf_errortrap(h,iptr,(char *) 0);
		linefeed(h);
		}
	return;
}

public	void	abal_ngf_link(FILE * h, struct form_item* iptr, int margin,char * rubname )
{
	if ( abal_ngf_method(iptr) == _MCFILE_FRAME ) {
		abal_ngf_instruction(h,iptr,__abal_keyword_link,margin);
		fprintf(h,",%c%s%c",0x0022,rubname,0x0022);
		abal_ngf_errortrap(h,iptr,(char *) 0);
		linefeed(h);
		}
	return;
}

public	void	abal_ngf_clink(FILE * h, struct form_item* iptr, int margin )
{
	if ( abal_ngf_method(iptr) == _MCFILE_FRAME ) {
		abal_ngf_instruction(h,iptr,__abal_keyword_clink,margin);
		abal_ngf_errortrap(h,iptr,(char *) 0);
		linefeed(h);
		}
	return;
}

public	void	abal_ngf_modif(FILE * h, struct form_item* iptr, int margin )
{
	struct	data_control * dptr;
	abal_ngf_instruction(h,iptr,__abal_keyword_modif,margin);
	abal_indexname_parameter(h,iptr);
	abal_ngf_errortrap(h,iptr,(char *) 0);
	abal_recordname_parameter(h,iptr);
	if ((( dptr = iptr->Contents.extra ) != (struct data_control*)0)
	&&  ( dptr->option & _A_BOLD)) {
		fprintf(h,",");
		abal_lengthname_value(h,iptr);
		}
	linefeed(h);
	return;
}

public	void	abal_ngf_lock(FILE * h, struct form_item* iptr, int margin )
{
	abal_repeat(h,margin);
		margin++;
		abal_ngf_instruction(h,iptr,__abal_keyword_search_m,margin);
		abal_indexname_parameter(h,iptr);
		abal_ngf_errortrap(h,iptr,(char *) 0);
		fprintf(h,",m_%s",iptr->Contents.name);
		fprintf(h,",");
		abal_recordsize_value(h,iptr);
		fprintf(h,"+1");
		linefeed(h);
		margin--;
	indent(h,margin);
	fprintf(h,"%s ( e_%s <> 74 )", __abal_keyword_until,iptr->Contents.name );
	linefeed(h);
	return;
}

public	void	abal_ngf_update(FILE * h, struct form_item* iptr, int margin )
{
	abal_ngf_insert(h,iptr,margin);
	indent(h,margin);
	fprintf(h,"if ( e_%s = 81 )",iptr->Contents.name);
	linefeed(h);
	abal_ngf_modif(h,iptr,margin+1);
	abal_endif(h,margin);
	linefeed(h);
	return;
}

public	void	abal_ngf_delete(FILE * h, struct form_item* iptr, int margin )
{
	abal_ngf_instruction(h,iptr,__abal_keyword_delete,margin);
	abal_indexname_parameter(h,iptr);
	abal_ngf_errortrap(h,iptr,(char *) 0);
	linefeed(h);
	return;
}


public	int	abal_data_member_expression( FILE * h, struct form_item * iptr, char * token )
{
	int	i;
	int	fields;
	int	f;
	struct data_control * dptr;

	if (!( dptr = iptr->Contents.extra ))
		return(0);
	else	{
		fields = (dptr->indexfields + dptr->datafields);
		for ( f=0; f < fields; f++ ) {
			if (!( dptr->name[f] ))
				continue;
			else if ( upper_compare( token, dptr->name[f] ) ) {
				abal_file_member_name(h,iptr,f);
				return(1);
				}
			}
		return(0);
		}
}

public	void	abal_data_expression( FILE* h, struct form_item * iptr , int keycode, int margin, char * token )
{
	int	direction=0;
	int	i;
	int	fields;
	int	f;
	struct data_control * dptr;
	switch ( keycode ) {
		case DATA_MEMBER_ASSIGN		:
			if (!( remove_brackets() )) break;
			abal_ngf_assign(h,iptr,margin);
			break;
		case DATA_MEMBER_OPEN		:
			if (!( remove_brackets() )) break;
			abal_ngf_open(h,iptr,margin);
			break;
		case DATA_MEMBER_CLOSE		:
			if (!( remove_brackets() )) break;
			abal_ngf_close(h,iptr,margin);
			break;
		case DATA_MEMBER_CFILE		:
			if (!( remove_brackets() )) break;
			abal_ngf_cfile(h,iptr,margin);
			break;
		case DATA_MEMBER_DFILE		:
			if (!( remove_brackets() )) break;
			abal_ngf_dfile(h,iptr,margin);
			break;
		case DATA_MEMBER_UPDATE		:
			if (!( remove_brackets() )) break;
			abal_ngf_update(h,iptr,margin);
			break;
		case DATA_MEMBER_INSERT		:
			if (!( remove_brackets() )) break;
			abal_ngf_insert(h,iptr,margin);
			break;
		case DATA_MEMBER_POSIT		:
			direction = check_direction();
			if (!( remove_brackets() )) break;
			if (!( direction ))
				abal_ngf_posit(h,iptr,margin);
			else	abal_ngf_positd(h,iptr,margin);
			break;
		case DATA_MEMBER_COLLECT		:
			abal_ngf_collect(h,iptr,margin);
			break;
		case DATA_MEMBER_COUNT		:
			if (!( remove_brackets() )) break;
			abal_ngf_count(h,iptr,margin);
			break;
		case DATA_MEMBER_MODIF		:
			if (!( remove_brackets() )) break;
			abal_ngf_modif(h,iptr,margin);
			break;
		case DATA_MEMBER_DELETE		:
			if (!( remove_brackets() )) break;
			abal_ngf_delete(h,iptr,margin);
			break;
		case DATA_MEMBER_SEARCH		:
			if (!( remove_brackets() )) break;
			abal_ngf_search(h,iptr,margin);
			break;
		case DATA_MEMBER_LOCATE		:
			abal_ngf_locate(h,iptr,margin);
			break;
		case DATA_MEMBER_LOCK		:
			if (!( remove_brackets() )) break;
			abal_ngf_lock(h,iptr,margin);
			break;
		case DATA_MEMBER_FIRST		:
			if (!( remove_brackets() )) break;
			abal_ngf_first(h,iptr,margin);
			break;
		case DATA_MEMBER_PREVIOUS	:
		case DATA_MEMBER_UP		:
			if (!( remove_brackets() )) break;
			abal_ngf_up(h,iptr,margin);
			break;
		case DATA_MEMBER_NEXT		:
		case DATA_MEMBER_DOWN		:
			if (!( remove_brackets() )) break;
			abal_ngf_down(h,iptr,margin);
			break;
		case DATA_MEMBER_LAST		:
			if (!( remove_brackets() )) break;
			abal_ngf_last(h,iptr,margin);
			break;
		case DATA_MEMBER_LENGTH		:
			fprintf(h,"l_%s",iptr->Contents.name);
			break;
		case DATA_MEMBER_QUESTION	:
			fprintf(h,"q_%s",iptr->Contents.name);
			break;
		case DATA_MEMBER_RESPONSE	:
			fprintf(h,"n_%s",iptr->Contents.name);
			break;
		case DATA_MEMBER_ERROR		:
			fprintf(h,"e_%s",iptr->Contents.name);
			break;
		case DATA_MEMBER_HANDLE		:
			fprintf(h,"h_%s",iptr->Contents.name);
			break;
		case DATA_MEMBER_INDEX		:
			fprintf(h,"k_%s",iptr->Contents.name);
			break;
		case	-1			:
			abal_data_member_expression(h,iptr,token);
			break;
		}
	return;
}

private	void	abal_ngf_keys(FILE * h, struct form_item * iptr, int margin )
{
	struct data_control * dptr;
	int	f;
	if (!(dptr = iptr->Contents.extra ))
		return;
	for (f=0; f < dptr->datafields; f++ ) {
		abal_ngf_key(
			h,iptr,margin,
			dptr->name [dptr->indexfields+f],
			dptr->type [dptr->indexfields+f],
			dptr->width[dptr->indexfields+f]);
		}
	return;
}

private	void	abal_ngf_links(FILE * h, struct form_item * iptr, int margin )
{
	struct data_control * dptr;
	int	f;
	if (!(dptr = iptr->Contents.extra ))
		return;
	indent(h,margin++);
	fprintf(h,"if (Status <> 0)");
	linefeed(h);
	abal_ngf_ckey(h,iptr,margin);
	for (f=0; f < dptr->datafields; f++ ) {
		abal_ngf_link(
			h,iptr,margin,
			dptr->name[dptr->indexfields+f]);
		}	
	abal_ngf_clink(h,iptr,margin);
	abal_endif(h,--margin);
	return;
}

public  int	abal_data_construction(FILE * h, struct form_item * iptr, int margin )
{
	int	t;
	struct data_control * dptr;
	dptr = iptr->Contents.extra;
	switch ((t = (iptr->Contents.align & 0x000F))) {
		case	_VARIABLE_FRAME		:	/* 0 variable	*/
			break;
		case	_OBJECT_FRAME		:	/* 1 structure	*/
		case	_VISUAL_FRAME		:	/* 2 visual	*/
			if ( iptr->Contents.datatype == _WIDGET_POINTER ) {
				indent(h,margin);
				fprintf(h,"%s %s",__abal_keyword_create,iptr->Contents.name);
				linefeed(h);
				}
			break;
		case	_VMEMORY_FRAME		:
			if ( dptr ) {
				indent(h,margin);
				fprintf(h,"h_%s=%u",iptr->Contents.name,dptr->datalength);
				linefeed(h);
				abal_ngf_assign(h,iptr,margin);
				abal_ngf_open(h,iptr,margin);
				indent(h,margin);
				fprintf(h,"if ( e_%s <> 0 )",iptr->Contents.name);
				linefeed(h);
				indent(h,margin+1);
				fprintf(h,"Status = 40");
				linefeed(h);
				abal_ngf_cfile(h,iptr,margin+1);
				reset_vmem_fields(h,iptr,dptr,0);
				abal_else(h,margin);
				indent(h,margin+1);
				fprintf(h,"Status = 0");
				linefeed(h);
				abal_endif(h,margin);
				}
			break;
		case	_SQFILE_FRAME		:	/* 6 sifile	*/
		case	_DBFILE_FRAME		:	/* 7 sifile	*/
		case	_SIFILE_FRAME		:	/* 3 sifile	*/
		case	_MCFILE_FRAME		:	/* 4 sifile	*/
			if ( iptr->Contents.datatype == _WIDGET_POINTER ) {
				indent(h,margin);
				fprintf(h,"%s r_%s",
					__abal_keyword_create,
					iptr->Contents.name);
				linefeed(h);
				}
			if ( t == _MCFILE_FRAME ) {
				indent(h,margin);
				fprintf(h,"n_%s=0",iptr->Contents.name);
				linefeed(h);
				indent(h,margin);
				fprintf(h,"%s p_%s",
					__abal_keyword_forget,
					iptr->Contents.name);
				linefeed(h);
				}
			indent(h,margin);
			fprintf(h,"h_%s=Event(77)",iptr->Contents.name);
			linefeed(h);
			abal_ngf_assign(h,iptr,margin);
			abal_ngf_open(h,iptr,margin);
			indent(h,margin);
			fprintf(h,"if ( e_%s <> 0 )",iptr->Contents.name);
			linefeed(h);
			indent(h,margin+1);
			fprintf(h,"Status = 40");
			linefeed(h);
			abal_ngf_cfile(h,iptr,margin+1);
			abal_else(h,margin);
			indent(h,margin+1);
			fprintf(h,"Status = 0");
			linefeed(h);
			abal_endif(h,margin);
			if ( t == _MCFILE_FRAME ) {
				abal_ngf_keys (h,iptr,margin);
				abal_ngf_links(h,iptr,margin);
				}
			break;
		}
	return(0);
}

public  int	abal_data_destruction(FILE * h, struct form_item * iptr, int margin )
{
	int	t;
	switch ((t = (iptr->Contents.align & 0x000F)) ) {
		case	_VARIABLE_FRAME		:	/* 0 variable	*/
			break;
		case	_OBJECT_FRAME		:	/* 1 structure	*/
		case	_VISUAL_FRAME		:	/* 2 visual	*/
			if ( iptr->Contents.datatype == _WIDGET_POINTER ) {
				indent(h,margin);
				fprintf(h,"%s %s",__abal_keyword_remove,iptr->Contents.name);
				linefeed(h);
				}
			break;

		case	_VMEMORY_FRAME		:	/* virtual memory 	*/
			abal_ngf_close(h,iptr,margin);
			break;

		case	_SQFILE_FRAME		:	/* 6 sifile	*/
		case	_DBFILE_FRAME		:	/* 7 sifile	*/
		case	_SIFILE_FRAME		:	/* 3 sifile		*/
		case	_MCFILE_FRAME		:	/* 4 sifile		*/
			abal_ngf_close(h,iptr,margin);
			indent(h,margin);
			fprintf(h,"Event(77)=h_%s",iptr->Contents.name);
			linefeed(h);
			if ( t == _MCFILE_FRAME ) {
				indent(h,margin);
				fprintf(h,"%s p_%s",
					__abal_keyword_forget,
					iptr->Contents.name);
				linefeed(h);
				}
			if ( iptr->Contents.datatype == _WIDGET_POINTER ) {
				indent(h,margin);
				fprintf(h,"%s r_%s",
					__abal_keyword_remove,
					iptr->Contents.name);
				linefeed(h);
				}
			break;
		}
	return(0);
}

public	void	reset_aplus_file_member( 
	FILE * h, 
	struct data_control * dptr,
	int	f
	)
{
	int	l=0;
	switch ( dptr->type[f] ) {
		case	_ABAL_BYTE	:
		case	_ABAL_WORD	:
		case	_ABAL_LONG	:
		case	_ABAL_BCD 	:
			if ( dptr->first[f] ) {
				indent(h,1);
				fprintf(h,"For __x = 1 to %u",dptr->first[f]);
				linefeed(h);
				if ( dptr->second[f] ) {
					indent(h,2);
					fprintf(h,"For __y = 1 to %u",dptr->second[f]);
					linefeed(h);
					indent(h,3);
					fprintf(h,"%s(__x,__y)=0",dptr->name[f]);
					linefeed(h);
					indent(h,2);
					fprintf(h,"Next __y");
					linefeed(h);
					}
				else	{
					indent(h,2);
					fprintf(h,"%s(__x)=0",dptr->name[f]);
					linefeed(h);
					}
				indent(h,1);
				fprintf(h,"Next __x");
				linefeed(h);
				}
			else	{
				indent(h,1);
				fprintf(h,"%s=0",dptr->name[f]);
				linefeed(h);
				}
			break;

		case	_ABAL_STRING	:
			if ( dptr->first[f] ) {
				indent(h,1);
				fprintf(h,"For __x = 1 to %u",dptr->first[f]);
				linefeed(h);
				if ( dptr->second[f] ) {
					indent(h,2);
					fprintf(h,"For __y = 1 to %u",dptr->second[f]);
					linefeed(h);
					indent(h,3);
					fprintf(h,"%s(__x,__y)=%c %c",dptr->name[f],0x0022,0x0022);
					linefeed(h);
					indent(h,2);
					fprintf(h,"Next __y");
					linefeed(h);
					}
				else	{
					indent(h,2);
					fprintf(h,"%s(__x)=%c %c",dptr->name[f],0x0022,0x0022);
					linefeed(h);
					}
				indent(h,1);
				fprintf(h,"Next __x");
				linefeed(h);
				}
			else	{
				indent(h,1);
				fprintf(h,"%s=%c %c",dptr->name[f],0x0022,0x0022);
				linefeed(h);
				}
			break;
		}
	return;

}

public	int	generate_aplus_file_member( 
	FILE * h, 
	struct data_control * dptr,
	int	f
	)
{
	int	l=0;
	switch ( dptr->type[f] ) {
		case	_ABAL_BYTE	:
			fprintf(h,"%s %s %s#",keyword_public,keyword_dcl,dptr->name[f]);
			l=1;
			break;
		case	_ABAL_WORD	:
			fprintf(h,"%s %s %s%c",keyword_public,keyword_dcl,dptr->name[f],0x0025);
			l=2;
			break;
		case	_ABAL_LONG	:
			fprintf(h,"%s %s %s:",keyword_public,keyword_dcl,dptr->name[f]);
			l=4;
			break;
		case	_ABAL_STRING	:
			fprintf(h,"%s %s %s$=%u",keyword_public,keyword_dcl,dptr->name[f],(l=dptr->width[f]));
			break;
		case	_ABAL_BCD	:
			fprintf(h,"%s %s %s=%u",keyword_public,keyword_dcl,dptr->name[f],(l=dptr->width[f]));
			break;
		default			:
			l = 0;

		}

	if ( dptr->first[f] ) {
		fprintf(h,"(%u",dptr->first[f]);
		if ( dptr->second[f] )
			fprintf(h,",%u",dptr->second[f]);
		fprintf(h,")");
		}	
	linefeed(h);
	return(l);

}

public	void	generate_aplus_file_members( 
	FILE * h, 
	struct form_item * iptr,
	struct data_control * dptr 
	)
{
	int	f;
	int	ilen=0;
	int	rlen=0;
	for ( f=0; f < dptr->indexfields; f++ )
		ilen+=generate_aplus_file_member(h,dptr,f);

	if ( ilen < dptr->indexlength ) {
		fprintf(h,"%s %s indexfiller$=%u",keyword_private,keyword_dcl,(dptr->indexlength-ilen));
		linefeed(h);
		}

	fprintf(h,"%s %s _mq#",keyword_public,keyword_dcl);
	linefeed(h);

	for ( f=0; f < dptr->datafields;  f++ )
		rlen+=generate_aplus_file_member(h,dptr,dptr->indexfields+f);

	if ( rlen < dptr->datalength ) {
		fprintf(h,"%s %s datafiller$=%u",keyword_private,keyword_dcl,(dptr->datalength-rlen));
		linefeed(h);
		}

	return;
}

public	void	generate_aplus_file_methods(
	FILE * h, 
	struct form_item * iptr,
	struct data_control * dptr 
	)
{
	int	f;

	linefeed(h);
	fprintf(h,"%s %s %s initialise:(pnomfic$)",keyword_public,keyword_inline,keyword_constructor);
	linefeed(h);
	indent(h,1); fprintf(h,"Connect(%s;%u;%s;%u)",
			dptr->name[0],dptr->indexlength,
			dptr->name[dptr->indexfields],dptr->datalength);
	linefeed(h);
	indent(h,1); fprintf(h,"Assign(pnomfic)");
	linefeed(h);
	indent(h,1); fprintf(h,"%s",__abal_keyword_end);
	linefeed(h);



	linefeed(h);
	fprintf(h,"%s %s %s terminate:(pnomfic$)",keyword_public,keyword_inline,keyword_destructor);
	linefeed(h);
	indent(h,1); fprintf(h,"Close");
	linefeed(h);
	indent(h,1); fprintf(h,"%s",__abal_keyword_end);
	linefeed(h);
	linefeed(h);

	fprintf(h,"%s %s reset:",keyword_public,keyword_function);
	linefeed(h);
	indent(h,1); fprintf(h,"Local Dcl __x%,__y%");
	linefeed(h);
	for ( f=0; f < dptr->datafields;  f++ )
		reset_aplus_file_member(h,dptr,dptr->indexfields+f);


	indent(h,1); fprintf(h,"%s",__abal_keyword_end);
	linefeed(h);


}
public	void	generate_aplus_sifile_class( FILE * h, struct form_item * iptr )
{
	linefeed(h); fprintf(h,"%s\t\tsifile_%s",keyword_class,iptr->Contents.name); 
	linefeed(h);
	fprintf(h,"(%s sifile)",keyword_public,iptr->Contents.name); 
	linefeed(h);
	generate_aplus_file_members(h, iptr, iptr->Contents.extra);	
	generate_aplus_file_methods(h, iptr, iptr->Contents.extra);	
	linefeed(h);
	fprintf(h,"%s\t\tsifile_%s",keyword_endclass,iptr->Contents.name);
	linefeed(h);
	return;
}

public	void	generate_aplus_mcfile_class( FILE * h, struct form_item * iptr )
{
	linefeed(h); fprintf(h,"%s\t\tmcfile_%s",keyword_class,iptr->Contents.name); 
	linefeed(h);
	fprintf(h,"(%s mcfile)",keyword_public,iptr->Contents.name); 
	linefeed(h);
	generate_aplus_file_members(h, iptr, iptr->Contents.extra);	
	generate_aplus_file_methods(h, iptr, iptr->Contents.extra);	
	linefeed(h);
	fprintf(h,"%s\t\tmcfile_%s",keyword_endclass,iptr->Contents.name);
	linefeed(h);
	return;
}

public	int	generate_aplus_form_members(
	FILE * h, 
	struct form_item * iptr
	)
{
	int	fields=0;
	int	fieldwidth[_MAX_FORM_FIELDS];
	int	linelength=0;
	int	nblines=0;
	int	i;

	calculate_edit_size( &iptr->Contents );
	calculate_edit_lines( &iptr->Contents, &linelength, &nblines );

	if (!( fields = calculate_form_fields(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength) ))
		return(fields);

	for (	i=0; i < fields; i++ ) {
		fprintf(h,"%s %s member%u$=%u",
			keyword_public,keyword_dcl,(i+1),fieldwidth[i]);
		linefeed(h);

		}
	return(fields);
}

public	void	generate_aplus_form_methods(
	FILE * h, 
	struct form_item * iptr,
	int	fields
	)
{
	int	i;
	linefeed(h);
	fprintf(h,"%s %s member:(nb)",keyword_public,keyword_inline);
	linefeed(h);
	indent(h,1); fprintf(h,"%s nb",__abal_keyword_select);
	linefeed(h);
	for (	i=0; i < fields; i++ ) {
		indent(h,1); fprintf(h,"%s %u",__abal_keyword_case,i+1);
		linefeed(h);
		indent(h,2); fprintf(h,"colbuffer = Alias(rowbuffer.member%u)",i+1);
		linefeed(h);
		indent(h,2); fprintf(h,"Alter colbuffer (Len(rowbuffer.member%u))",i+1);
		linefeed(h);
		}
	indent(h,1); fprintf(h,"%s",__abal_keyword_endsel);
	linefeed(h);
	linefeed(h);
	indent(h,1); fprintf(h,"%s",__abal_keyword_end);
	linefeed(h);
	return;
}

public	void	generate_aplus_table_class( FILE * h, struct form_item * iptr )
{
	int	f;
	linefeed(h); fprintf(h,"%s\t\tvisual_record_%s",keyword_class,iptr->Contents.name); 
	linefeed(h);
	f = generate_aplus_form_members(h, iptr );
	fprintf(h,"%s\t\tvisual_record_%s",keyword_endclass,iptr->Contents.name);
	linefeed(h);
	linefeed(h); fprintf(h,"%s\t\tvisual_table_%s",keyword_class,iptr->Contents.name); 
	linefeed(h);
	fprintf(h,"Inherit visual_table",keyword_public,iptr->Contents.name); 
	linefeed(h);
	fprintf(h,"%s visual_record_%s %s rowbuffer",keyword_public,iptr->Contents.name,keyword_pointer); 
	linefeed(h);
	generate_aplus_form_methods(h, iptr, f);
	linefeed(h);
	fprintf(h,"%s\t\tvisual_table_%s",keyword_endclass,iptr->Contents.name);
	linefeed(h);
	return;
}

public	void	draw_class_image(int topx, int topy,struct form_item* iptr,int editing)
{
	char *	sptr;
	char *	filename;
	struct data_control * xptr;
	struct standard_image * widget_image_loader(char *,int);
	if (!(xptr = iptr->Contents.extra )) 
		return;
	if (!( xptr->image )) {
		if (!( iptr ))
			return;
		else if (!( sptr = iptr->Contents.payload ))
			return;
		else if (!( filename = allocate_string( sptr ) ))
			return;
		else if (!( filename = enforce_extension( filename, GIF_EXTENSION ) ))
			return;
		xptr->image = widget_image_loader(filename,0);
		liberate( filename );
		if (!( xptr->image ))
			return;
		}
	image( 	topx+iptr->Contents.x, topy+iptr->Contents.y, 
		(iptr->Contents.w=xptr->image->columns), 
		(iptr->Contents.h=xptr->image->rows), 
		xptr->image,(iptr->Contents.align & 0xFFF0));
	return;
}


/*	-------------------------------		*/
/*	f i l e _ m e m b e r _ l i s t 	*/
/*	-------------------------------		*/

public	char 	*	file_member_list(struct form_item * iptr, char * rptr)
{
	int			f;
	struct data_control * 	dptr;
	char 		    *	nptr;
	char		    *	wptr;
	if (!( iptr ))
		return( rptr );
	else if (!(dptr = iptr->Contents.extra )) 
		return( rptr );
	else	{		
		switch ( iptr->Contents.align & 0x000F ) {
			case	_SQFILE_FRAME		:	/* 6 sifile		*/
			case	_DBFILE_FRAME		:	/* 7 sifile		*/
			case	_SIFILE_FRAME		:	/* 3 sifile		*/
			case	_MCFILE_FRAME		:	/* 4 sifile		*/
				/* Add all index members */
				/* -------------------- */
				for (f=0; f < dptr->indexfields; f++ ) {
					if (!( nptr =dptr->name [f]))
						continue; 
					else if (!( rptr )) {
						if (!( rptr = allocate_string( nptr ) ))
							break;
						else	continue;
						}
					else if (!( wptr = allocate( strlen( rptr ) + strlen( nptr ) + 4 ) ))
						break;
					else	{
						sprintf(wptr,"%s|%s",rptr,nptr);
						liberate( rptr );
						rptr = wptr;
						}
					}

			case	_VMEMORY_FRAME		:
				/* Add all data members */
				/* -------------------- */
				for (f=0; f < dptr->datafields; f++ ) {
					if (!( nptr =dptr->name [dptr->indexfields+f]))
						continue; 
					else if (!( rptr )) {
						if (!( rptr = allocate_string( nptr ) ))
							break;
						else	continue;
						}
					else if (!( wptr = allocate( strlen( rptr ) + strlen( nptr ) + 4 ) ))
						break;
					else	{
						sprintf(wptr,"%s|%s",rptr,nptr);
						liberate( rptr );
						rptr = wptr;
						}
					}
			case	_OBJECT_FRAME		:	/* 1 structure		*/
			case	_VARIABLE_FRAME		:	/* 0 variable		*/
			case	_VISUAL_FRAME		:	/* 2 visual		*/
			default				:
				return( rptr );

			}
		}
}

/*	----------------------------------	*/
/*	c h e c k _ f i l e _ W i d g e t	*/
/*	----------------------------------	*/

public	int	is_file_Widget( struct form_item * iptr )
{
	struct	form_control * fptr;
	if (!( iptr ))
		return(0);
	else if (!(fptr = iptr->parent))
		return(0);
	else if ((iptr->Contents.style & _FRAME_TYPE) != _DATA_FRAME)
		return(0);
	else	{
		switch ( iptr->Contents.align & 0x000F ) {
			case	_SQFILE_FRAME		:	/* 6 sifile		*/
			case	_DBFILE_FRAME		:	/* 7 sifile		*/
			case	_SIFILE_FRAME		:	/* 3 sifile		*/
			case	_MCFILE_FRAME		:	/* 4 sifile		*/
			case	_VMEMORY_FRAME		:
				return(1);
			default				:
				return(0);
			}
		}

}

private	void	check_file_Widget( struct form_item * iptr )
{
	void	*	AddFileMember(void *,char *, char *, char *, char *,char *, int );
	char	*	nptr;
	struct		form_control *	fptr;
	if (!( iptr ))
		return;
	else if ((fptr = iptr->parent) != (struct form_control *) 0)
		nptr = fptr->identifier;
	else	nptr = "unknown";		
	if ((iptr->Contents.style & _FRAME_TYPE) != _DATA_FRAME)
		return;
	else	{
		switch ( iptr->Contents.align & 0x000F ) {
			case	_SQFILE_FRAME		:	/* 6 sifile		*/
			case	_DBFILE_FRAME		:	/* 7 sifile		*/
			case	_SIFILE_FRAME		:	/* 3 sifile		*/
			case	_MCFILE_FRAME		:	/* 4 sifile		*/
			case	_VMEMORY_FRAME		:
				iptr->Contents.format = AddFileObject(	(void*) 0,
									iptr->Contents.align,
									iptr->Contents.name,	/* instance name	*/
									iptr->Contents.payload,	/* system filename	*/
									iptr->Contents.format,	/* file description	*/
									nptr );			/* form identifier	*/
				break;
				
			}
		return;
		}
}

/*	----------------------------------	*/
/*	c h e c k _ d a t a _ f o r m a t 	*/
/*	----------------------------------	*/

public	int	check_data_format( char * nptr, struct data_control * dptr, char * fptr )
{
	int	i;
	int	status=0;

	struct 	data_control * xptr =(struct data_control *) 0;
	if (!( fptr )) {
		printf("%s: illegal format string\r\n",nptr);
		status=1;
		}
	else if (!( xptr = analyse_data_control( fptr ))) {
		printf("%s: illegal format string\r\n",nptr);
		status=2;
		}
	else if ( xptr->datalength != dptr->datalength ) {
		printf("%s: unmatched data length : %u : %u \r\n",nptr,dptr->datalength,xptr->datalength);
		status=3;
		}
	else if ( xptr->indexlength != dptr->indexlength ) {
		printf("%s: unmatched index length : %u : %u \r\n",nptr,dptr->indexlength,xptr->indexlength);
		status=4;
		}
	else if ( xptr->datafields != dptr->datafields ) {
		printf("%s: unmatched data field count : %u : %u \r\n",nptr,dptr->datafields,xptr->datafields);
		status=5;
		}
	else if ( xptr->indexfields != dptr->indexfields ) {
		printf("%s: unmatched index field count : %u : %u \r\n",nptr,dptr->indexfields,xptr->indexfields);
		status=6;
		}
 
	else	{
		for (i=0; i < dptr->indexfields; i++ ) {
			if ( strcmp( dptr->name[i] , xptr->name[i] ) != 0 ) {
				printf("%s: unmatched index field names : %s : %s \r\n",nptr,dptr->name[i] , xptr->name[i] );
				status = 7; break;
				}
			else if ( dptr->type[i] != xptr->type[i] ){
				printf("%s: unmatched index field types : %x : %x \r\n",nptr,dptr->type[i] , xptr->type[i] );
				status = 8; break;
				}
			else if ( dptr->width[i] != xptr->width[i] ){
				printf("%s: unmatched index field widths : %x : %x \r\n",nptr,dptr->width[i] , xptr->width[i] );
				status = 9; break;
				}
			else if ( dptr->first[i] != xptr->first[i] ){
				printf("%s: unmatched index field first dimensions : %x : %x \r\n",nptr,dptr->first[i] , xptr->first[i] );
				status = 10; break;
				}
			else if ( dptr->second[i] != xptr->second[i] ){
				printf("%s: unmatched index field second dimensions : %x : %x \r\n",nptr,dptr->second[i] , xptr->second[i] );
				status = 11; break;
				}
			}
		if (!( status )) {
			for (i=0; i < dptr->datafields; i++ ) {
				if ( strcmp( dptr->name[i+dptr->indexfields] , xptr->name[i+dptr->indexfields] ) != 0 ){
					printf("%s: unmatched index field names : %s : %s \r\n",nptr,dptr->name[i+dptr->indexfields] , xptr->name[i+dptr->indexfields] );
					status = 12; break;
					}
				else if ( dptr->type[i+dptr->indexfields] != xptr->type[i+dptr->indexfields] ){
					printf("%s: unmatched index field types : %x : %x \r\n",nptr,dptr->type[i+dptr->indexfields] , xptr->type[i+dptr->indexfields] );
					status = 13; break;
					}
				else if ( dptr->width[i+dptr->indexfields] != xptr->width[i+dptr->indexfields] ){
					printf("%s: unmatched index field widths : %x : %x \r\n",nptr,dptr->width[i+dptr->indexfields] , xptr->width[i+dptr->indexfields] );
					status = 14; break;
					}
				else if ( dptr->first[i+dptr->indexfields] != xptr->first[i+dptr->indexfields] ){
					printf("%s: unmatched index field first dimensions : %x : %x \r\n",nptr,dptr->first[i+dptr->indexfields] , xptr->first[i+dptr->indexfields] );
					status = 15; break;
					}
				else if ( dptr->second[i+dptr->indexfields] != xptr->second[i+dptr->indexfields] ){
					printf("%s: unmatched index field second dimensions : %x : %x \r\n",nptr,dptr->second[i+dptr->indexfields] , xptr->second[i+dptr->indexfields] );
					status = 16; break;
					}
				}
			}
		}
			
	if ( xptr )
		drop_data_control(xptr);
	return(status);
}

public	int	generate_data_widget(struct form_control * fptr, char * nptr, struct form_item * iptr)
{
	struct  form_item * allocate_for_Widget();
	struct	form_item * wptr;
	if (!( fptr ))
		return( 118 );
	else if (!( iptr ))
		return( 118 );
	else if (!( wptr = allocate_for_Widget() ))
		return(27);
	else	{
		wptr->Contents.x 	= iptr->Contents.x;
		wptr->Contents.y 	= iptr->Contents.y;
		wptr->Contents.w 	= iptr->Contents.w;
		wptr->Contents.h 	= iptr->Contents.h;
		wptr->Contents.font 	= iptr->Contents.font;
		wptr->Contents.colour	= iptr->Contents.colour;
		wptr->Contents.align 	= iptr->Contents.align;
		switch ((wptr->Contents.style = iptr->Contents.style)) {
			case	_BUTTON_FRAME	:
			case	_CHECK_FRAME	:
			case	_RADIO_FRAME	:
				if (!( nptr ))
					break;
				if (!( wptr->Contents.payload = allocate_string( nptr )))
					return(27);
				else if (!( wptr->Contents.name = allocate_string( nptr )))
					return(27);
				else	break;

			case	_TAB_FRAME	:
			case	_INSET_FRAME	:
			case	_OUTSET_FRAME	:
			case	_RIDGE_FRAME	:
			case	_GROOVE_FRAME	:
			case	_DATA_FRAME	:
			case	_WINDOW_FRAME	:
			case	_TEXT_FRAME	:
				if (!( nptr ))
					break;
				else if (!( wptr->Contents.payload = allocate_string( nptr )))
					return(27);
				else	break;

			case	_EDIT_FRAME	:
				if (!( nptr ))
					break;
				if (!( wptr->Contents.name = allocate_string( nptr )))
					return(27);
				else	break;
			}
		reset_event_control(&wptr->Contents.events,(wptr->Contents.style & _FRAME_TYPE));
		check_Widget( wptr );
		add_Widget(fptr,wptr,0);
		return(0);
		}
		
}

private	int	data_pixel_width( struct data_control * dptr, int item, int fontwidth )
{
	switch ( dptr->type[item]) {
		case	_ABAL_BYTE	:
			return( (4*fontwidth)+fontwidth); 
		case	_ABAL_WORD	:
			return( (6*fontwidth)+fontwidth); 
		case	_ABAL_LONG	:
			return( (12*fontwidth)+fontwidth); 
		case	_ABAL_BCD 	:
			return( ((2*fontwidth) * dptr->width[item] )+fontwidth); 
		case	_ABAL_STRING	:
			return( (fontwidth * dptr->width[item] )+fontwidth); 
		default			:
			return(0);
		}
}

private	char	*	generate_load_action(struct form_item * iptr, struct data_control * dptr)
{
	char	*	rptr=(char *) 0;
	char	*	wptr=(char *) 0;
	char	*	nptr;
	char	work[320];
	int		f;
	int		first;
	for (first=0,f=0; f < dptr->indexfields; f++ ) {
		if (!(nptr = dptr->name[f+first] ))
			continue;
		else	{
			if ( dptr->type[f+first] == _ABAL_BCD )
			 	sprintf(work,"Dptr.%s = Fix(%s.value,0)",nptr,nptr);
			else if ( dptr->type[f+first] != _ABAL_STRING )
			 	sprintf(work,"Dptr.%s = %s.value",nptr,nptr);
			else 	sprintf(work,"Dptr.%s = %s.buffer",nptr,nptr);
			if (!( rptr ))
				rptr = allocate_string( work );
			else if (!( wptr = allocate( strlen(rptr) + strlen( work ) + 16 ) ))
				return(wptr);
			else	{
				sprintf(wptr,"%s\n%s",rptr,work);
				liberate( rptr );
				rptr = wptr;
				}
			}
		}
	sprintf(work,"Dptr.search");
	if (!( rptr ))
		rptr = allocate_string( work );
	else if (!( wptr = allocate( strlen(rptr) + strlen( work ) + 16 ) ))
		return(wptr);
	else	{
		sprintf(wptr,"%s\n%s",rptr,work);
		liberate( rptr );
		rptr = wptr;
		}
	for (first=dptr->indexfields,f=0; f < dptr->datafields; f++ ) {
		if (!(nptr = dptr->name[f+first] ))
			continue;
		else	{
			if ( dptr->type[f+first] != _ABAL_STRING )
				sprintf(work,"%s.buffer = Print(($),Conv$(Dptr.%s))",nptr,nptr);
			else	sprintf(work,"%s.buffer = Dptr.%s",nptr,nptr);
			if (!( rptr ))
				rptr = allocate_string( work );
			else if (!( wptr = allocate( strlen(rptr) + strlen( work ) + 16 ) ))
				return(wptr);
			else	{
				sprintf(wptr,"%s\n%s",rptr,work);
				liberate( rptr );
				rptr = wptr;
				}
			}
		}

	sprintf(work,"OnShow()\n");
	if (!( rptr ))
		rptr = allocate_string( work );
	else if (!( wptr = allocate( strlen(rptr) + strlen( work ) + 16 ) ))
		return(wptr);
	else	{
		sprintf(wptr,"%s\n%s",rptr,work);
		liberate( rptr );
		rptr = wptr;
		}
	return( rptr );
}

private	char	*	generate_up_action(struct form_item * iptr, struct data_control * dptr)
{
	char	*	rptr=(char *) 0;
	char	*	wptr=(char *) 0;
	char	*	nptr;
	char	work[320];
	int		f;
	int		first;
	for (first=0,f=0; f < dptr->indexfields; f++ ) {
		if (!(nptr = dptr->name[f+first] ))
			continue;
		else	{
			if ( dptr->type[f+first] == _ABAL_BCD )
			 	sprintf(work,"Dptr.%s = Fix(%s.value,0)",nptr,nptr);
			else if ( dptr->type[f+first] != _ABAL_STRING )
			 	sprintf(work,"Dptr.%s = %s.value",nptr,nptr);
			else 	sprintf(work,"Dptr.%s = %s.buffer",nptr,nptr);
			if (!( rptr ))
				rptr = allocate_string( work );
			else if (!( wptr = allocate( strlen(rptr) + strlen( work ) + 16 ) ))
				return(wptr);
			else	{
				sprintf(wptr,"%s\n%s",rptr,work);
				liberate( rptr );
				rptr = wptr;
				}
			}
		}
	sprintf(work,"Dptr.search");
	if (!( rptr ))
		rptr = allocate_string( work );
	else if (!( wptr = allocate( strlen(rptr) + strlen( work ) + 16 ) ))
		return(wptr);
	else	{
		sprintf(wptr,"%s\n%s",rptr,work);
		liberate( rptr );
		rptr = wptr;
		}
	sprintf(work,"Dptr.up");
	if (!( rptr ))
		rptr = allocate_string( work );
	else if (!( wptr = allocate( strlen(rptr) + strlen( work ) + 16 ) ))
		return(wptr);
	else	{
		sprintf(wptr,"%s\n%s",rptr,work);
		liberate( rptr );
		rptr = wptr;
		}
	for (first=0,f=0; f < dptr->indexfields; f++ ) {
		if (!(nptr = dptr->name[f+first] ))
			continue;
		else	{
			if ( dptr->type[f+first] != _ABAL_STRING )
				sprintf(work,"%s.buffer = Print(($),Conv$(Dptr.%s))",nptr,nptr);
			else	sprintf(work,"%s.buffer = Dptr.%s",nptr,nptr);
			if (!( rptr ))
				rptr = allocate_string( work );
			else if (!( wptr = allocate( strlen(rptr) + strlen( work ) + 16 ) ))
				return(wptr);
			else	{
				sprintf(wptr,"%s\n%s",rptr,work);
				liberate( rptr );
				rptr = wptr;
				}
			}
		}
	sprintf(work,"Load.Event()\n");
	if (!( rptr ))
		rptr = allocate_string( work );
	else if (!( wptr = allocate( strlen(rptr) + strlen( work ) + 16 ) ))
		return(wptr);
	else	{
		sprintf(wptr,"%s\n%s",rptr,work);
		liberate( rptr );
		rptr = wptr;
		}
	return( rptr );
}

private	char	* 	generate_down_action(struct form_item * iptr, struct data_control * dptr)
{
	char	*	rptr=(char *) 0;
	char	*	wptr=(char *) 0;
	char	*	nptr;
	char	work[320];
	int		f;
	int		first;
	for (first=0,f=0; f < dptr->indexfields; f++ ) {
		if (!(nptr = dptr->name[f+first] ))
			continue;
		else	{
			if ( dptr->type[f+first] == _ABAL_BCD )
			 	sprintf(work,"Dptr.%s = Fix(%s.value,0)",nptr,nptr);
			else if ( dptr->type[f+first] != _ABAL_STRING )
			 	sprintf(work,"Dptr.%s = %s.value",nptr,nptr);
			else 	sprintf(work,"Dptr.%s = %s.buffer",nptr,nptr);
			if (!( rptr ))
				rptr = allocate_string( work );
			else if (!( wptr = allocate( strlen(rptr) + strlen( work ) + 16 ) ))
				return(wptr);
			else	{
				sprintf(wptr,"%s\n%s",rptr,work);
				liberate( rptr );
				rptr = wptr;
				}
			}
		}
	sprintf(work,"Dptr.search");
	if (!( rptr ))
		rptr = allocate_string( work );
	else if (!( wptr = allocate( strlen(rptr) + strlen( work ) + 16 ) ))
		return(wptr);
	else	{
		sprintf(wptr,"%s\n%s",rptr,work);
		liberate( rptr );
		rptr = wptr;
		}
	sprintf(work,"Dptr.down");
	if (!( rptr ))
		rptr = allocate_string( work );
	else if (!( wptr = allocate( strlen(rptr) + strlen( work ) + 16 ) ))
		return(wptr);
	else	{
		sprintf(wptr,"%s\n%s",rptr,work);
		liberate( rptr );
		rptr = wptr;
		}
	for (first=0,f=0; f < dptr->indexfields; f++ ) {
		if (!(nptr = dptr->name[f+first] ))
			continue;
		else	{
			if ( dptr->type[f+first] != _ABAL_STRING )
				sprintf(work,"%s.buffer = Print(($),Conv$(Dptr.%s))",nptr,nptr);
			else	sprintf(work,"%s.buffer = Dptr.%s",nptr,nptr);
			if (!( rptr ))
				rptr = allocate_string( work );
			else if (!( wptr = allocate( strlen(rptr) + strlen( work ) + 16 ) ))
				return(wptr);
			else	{
				sprintf(wptr,"%s\n%s",rptr,work);
				liberate( rptr );
				rptr = wptr;
				}
			}
		}
	sprintf(work,"Load.Event()\n");
	if (!( rptr ))
		rptr = allocate_string( work );
	else if (!( wptr = allocate( strlen(rptr) + strlen( work ) + 16 ) ))
		return(wptr);
	else	{
		sprintf(wptr,"%s\n%s",rptr,work);
		liberate( rptr );
		rptr = wptr;
		}
	return( rptr );
}

private	char	*	generate_delete_action(struct form_item * iptr, struct data_control * dptr)
{
	char	*	rptr=(char *) 0;
	char	*	wptr=(char *) 0;
	char	*	nptr;
	char	work[320];
	int		f;
	int		first;
	for (first=0,f=0; f < dptr->indexfields; f++ ) {
		if (!(nptr = dptr->name[f+first] ))
			continue;
		else	{
			if ( dptr->type[f+first] == _ABAL_BCD )
			 	sprintf(work,"Dptr.%s = Fix(%s.value,0)",nptr,nptr);
			else if ( dptr->type[f+first] != _ABAL_STRING )
			 	sprintf(work,"Dptr.%s = %s.value",nptr,nptr);
			else 	sprintf(work,"Dptr.%s = %s.buffer",nptr,nptr);
			if (!( rptr ))
				rptr = allocate_string( work );
			else if (!( wptr = allocate( strlen(rptr) + strlen( work ) + 16 ) ))
				return(wptr);
			else	{
				sprintf(wptr,"%s\n%s",rptr,work);
				liberate( rptr );
				rptr = wptr;
				}
			}
		}
	sprintf(work,"Dptr.delete");
	if (!( rptr ))
		rptr = allocate_string( work );
	else if (!( wptr = allocate( strlen(rptr) + strlen( work ) + 16 ) ))
		return(wptr);
	else	{
		sprintf(wptr,"%s\n%s",rptr,work);
		liberate( rptr );
		rptr = wptr;
		}
	sprintf(work,"Load.Event()\n");
	if (!( rptr ))
		rptr = allocate_string( work );
	else if (!( wptr = allocate( strlen(rptr) + strlen( work ) + 16 ) ))
		return(wptr);
	else	{
		sprintf(wptr,"%s\n%s",rptr,work);
		liberate( rptr );
		rptr = wptr;
		}
	return( rptr );
}

private	char	*	generate_save_action(struct form_item * iptr, struct data_control * dptr)
{
	char	*	rptr=(char *) 0;
	char	*	wptr=(char *) 0;
	char	work[320];
	int		f;
	char	*	nptr;
	int		first;
	for (first=0,f=0; f < dptr->indexfields; f++ ) {
		if (!(nptr = dptr->name[f+first] ))
			continue;
		else	{
			if ( dptr->type[f+first] == _ABAL_BCD )
			 	sprintf(work,"Dptr.%s = Fix(%s.value,0)",nptr,nptr);
			else if ( dptr->type[f+first] != _ABAL_STRING )
			 	sprintf(work,"Dptr.%s = %s.value",nptr,nptr);
			else 	sprintf(work,"Dptr.%s = %s.buffer",nptr,nptr);
			if (!( rptr ))
				rptr = allocate_string( work );
			else if (!( wptr = allocate( strlen(rptr) + strlen( work ) + 16 ) ))
				return(wptr);
			else	{
				sprintf(wptr,"%s\n%s",rptr,work);
				liberate( rptr );
				rptr = wptr;
				}
			}
		}
	for (first=dptr->indexfields,f=0; f < dptr->datafields; f++ ) {
		if (!(nptr = dptr->name[f+first] ))
			continue;
		else	{
			if ( dptr->type[f+first] == _ABAL_BCD )
			 	sprintf(work,"Dptr.%s = Fix(%s.value,0)",nptr,nptr);
			else if ( dptr->type[f+first] != _ABAL_STRING )
			 	sprintf(work,"Dptr.%s = %s.value",nptr,nptr);
			else 	sprintf(work,"Dptr.%s = %s.buffer",nptr,nptr);
			if (!( rptr ))
				rptr = allocate_string( work );
			else if (!( wptr = allocate( strlen(rptr) + strlen( work ) + 16 ) ))
				return(wptr);
			else	{
				sprintf(wptr,"%s\n%s",rptr,work);
				liberate( rptr );
				rptr = wptr;
				}
			}
		}

	sprintf(work,"Dptr.update\n");
	if (!( rptr ))
		rptr = allocate_string( work );
	else if (!( wptr = allocate( strlen(rptr) + strlen( work ) + 16 ) ))
		return(wptr);
	else	{
		sprintf(wptr,"%s\n%s",rptr,work);
		liberate( rptr );
		rptr = wptr;
		}
	return( rptr );
}

private	int	generate_widget_action(struct form_item * iptr, struct data_control * dptr, int action )
{
	char *	aptr;
	if (!( iptr ))
		return(0);
	switch ((action & 0x000F)) {
		case	1  : aptr = "Exit(13)"; 			break;
		case	2  : aptr = generate_up_action(iptr,dptr); 	break;
		case	3  : aptr = generate_load_action(iptr,dptr); 	break;
		case	4  : aptr = generate_delete_action(iptr,dptr); 	break;
		case	5  : aptr = generate_save_action(iptr,dptr);	break;
		case	6  : aptr = generate_down_action(iptr,dptr); 	break;
		case	7  : aptr = "Exit(27)"; 			break;
		case	8  : aptr = "Load.Event()"; 			break;
		default	   : return(0);
		}
	switch ( (action & 0x00F0) >> 4 ) {
		case	1 :
			if (!(iptr->Contents.events.on_create= allocate_string(aptr)))
				return(27);
			else	break;

		case	2 :
			if (!(iptr->Contents.events.on_show  = allocate_string(aptr)))
				return(27);
			else	break;

		case	3 :
			if (!(iptr->Contents.events.on_get_focus = allocate_string(aptr)))
				return(27);
			else	break;

		case	0 :
		case	4 :
			if (!(iptr->Contents.events.on_event = allocate_string(aptr)))
				return(27);
			else	break;

		case	5 :
			if (!(iptr->Contents.events.on_lose_focus = allocate_string(aptr)))
				return(27);
			else	break;

		case	6 :
			if (!(iptr->Contents.events.on_lose_focus = allocate_string(aptr)))
				return(27);
			else	break;

		case	7 :
			if (!(iptr->Contents.events.on_lose_focus = allocate_string(aptr)))
				return(27);
			else	break;

		}
	switch ((action & 0x000F)) {
		case	3 :
		case	5 :	liberate( aptr );
		}
	return(0);
}

public	int	generate_data_widgets( struct form_control * fptr, struct file_control * optr, struct data_control * dptr, char * tptr, int pageitems )
{
	int	f;
	int	first;
	struct	form_item  	template;
	struct	form_item  	editlate;
	struct	form_item  	pagelate;
	int	status;
	char	* nptr;
	int	llen=0;
	int	elen=0;
	int	maxwidth=0;
	int	butwidth=0;
	int	maxlabel=0;
	int	maxitems=0;
	int	curitem;
	/* Calculate max label and max field */
	/* --------------------------------- */
	fptr->gridlock	= fptr->gridsize  = 0x0505;

	template.Contents.font 	= 2;

	for (first=0,f=0; f < dptr->indexfields; f++ ) {
		if (!(nptr = dptr->name[f+first] ))
			continue;
		maxitems++;
		if (( llen = textsizelen(template.Contents.font,nptr,strlen(nptr))) > maxlabel )
 			maxlabel = (llen + 10);
		if (( elen = data_pixel_width( dptr, (f+first), 10) ) > maxwidth )
			maxwidth = (elen+10);
		} 

	for (first=dptr->indexfields,f=0; f < dptr->datafields; f++ ) {
		if (!(nptr = dptr->name[f+first] ))
			continue;
		maxitems++;
		if (( llen = textsizelen(template.Contents.font,nptr,strlen(nptr))) > maxlabel )
 			maxlabel = (llen + 10);
		if (( elen = data_pixel_width( dptr, (f+first), 10) ) > maxwidth )
			maxwidth = (elen+10);
		}

	/* Generate Decoration */
	/* ------------------- */
	template.Contents.style = _WINDOW_FRAME;
	template.Contents.x 	= 0;
	template.Contents.y 	= 0;
	template.Contents.w 	= (maxlabel+maxwidth+(5*10));
	if ((butwidth = ((template.Contents.w - 20)/7)) < 60) {
		butwidth = 60;
		template.Contents.w = (butwidth*7)+20;
		}
	if ( pageitems ){
		template.Contents.h 	= 60+((dptr->indexfields+pageitems)*20)+100;
		}
	else	{
		template.Contents.h 	= 60+((dptr->indexfields+dptr->datafields)*20)+40;
		}
	template.Contents.colour= 0x0010;	/* Black on Transparent */
	template.Contents.align = 0x0703;	/* Center : Exit/Help/Shadow */
	template.Contents.font 	= 2;

	if ((status = generate_data_widget( fptr, tptr, &template )) != 0)
		return( status );

	template.Contents.x 	+= 10;	template.Contents.w 	-= 20; 
	template.Contents.y      = 30;
	template.Contents.h 	= (dptr->indexfields*20)+10;
	template.Contents.style = _OUTSET_FRAME;
	template.Contents.align = 0;

	if (!( pageitems )) {
		if ((status = generate_data_widget( fptr, (char *) 0, &template )) != 0)
			return( status );
		}
	
	template.Contents.y     += (template.Contents.h);

	if (( maxitems > pageitems ) &&  ( pageitems != 0 )) {
		template.Contents.h 	= (pageitems*20)+10;
		template.Contents.style = _TAB_FRAME;
		pagelate.Contents.style 	=template.Contents.style ;
		pagelate.Contents.x     	=template.Contents.x 	 ;
		pagelate.Contents.y     	=template.Contents.y 	 ;
		pagelate.Contents.w     	=template.Contents.w 	 ;
		pagelate.Contents.font  	=template.Contents.font  ;
		pagelate.Contents.h     	=template.Contents.h+70	 ;
		pagelate.Contents.align 	=template.Contents.align ;
		pagelate.Contents.colour	=template.Contents.colour;
		if ((status = generate_data_widget( fptr, (char *) 0, &pagelate )) != 0)
			return( status );
		}
	else 	{
		template.Contents.h 	= (dptr->datafields*20)+10;
		if ((status = generate_data_widget( fptr, (char *) 0, &template )) != 0)
			return( status );
		}

	template.Contents.style = _DATA_FRAME;
	template.Contents.x 	= 5;
	template.Contents.y 	= 5;
	template.Contents.w 	= 24;
	template.Contents.h 	= 32;
	template.Contents.align = optr->nature;

	if ((status = generate_data_widget( fptr, optr->filename, &template )) != 0)
		return( status );
	else if (!( fptr->last->Contents.name = allocate_string("Dptr") ))
		return(27);
	else if (!( fptr->last->Contents.format = allocate(strlen(optr->classname)+16) ))
		return(27);
	else	sprintf(fptr->last->Contents.format,"(%s)",optr->classname);

	/* Generate Text and Edit Widgets */
	/* ------------------------------ */
	template.Contents.style = _TEXT_FRAME;
	template.Contents.x 	= 20;
	if (!( pageitems ))
		template.Contents.y 	= 35;
	else	template.Contents.y 	= 35+60;

	template.Contents.w 	= maxlabel;
	template.Contents.font 	= 2;
	template.Contents.h 	= 16;
	template.Contents.align = 0x0502;	/* Left : Bold / Shadow */
	template.Contents.colour= 0x0010;	/* Black on Transparent */

	editlate.Contents.style = _EDIT_FRAME;
	editlate.Contents.font 	= 1;
	editlate.Contents.x 	= (template.Contents.w+20);
	if (!( pageitems ))
		editlate.Contents.y 	= 35;
	else	editlate.Contents.y 	= 35+60;
	editlate.Contents.w 	= 0;
	editlate.Contents.h 	= 16;
	editlate.Contents.align = 0;		/* Left : Bold / Shadow */
	editlate.Contents.colour= 0x0010;	/* Black on Transparent */

	for (first=0,f=0; f < dptr->indexfields; f++ ) {
		if (!(nptr = dptr->name[f+first] ))
			continue;
		else if ((status = generate_data_widget( fptr, nptr, &template )) != 0)
			return( status );
		else if (( status = generate_widget_action( fptr->last,dptr, 0x058 )) != 0)
			return( status );
		else	template.Contents.y += 20;

		editlate.Contents.w = data_pixel_width(dptr,f+first,10);
		if ((status = generate_data_widget( fptr, nptr, &editlate )) != 0)
			return( status );
		else	editlate.Contents.y += 20;


		}

	if (!( pageitems )) {
		template.Contents.y += 10;
		editlate.Contents.y += 10;
		}

	for (curitem=0,first=dptr->indexfields,f=0; f < dptr->datafields; f++ ) {
		if (!(nptr = dptr->name[f+first] ))
			continue;

		if (( curitem >= pageitems ) && ( pageitems > 0 )) {
			if ((status = generate_data_widget( fptr, (char *) 0, &pagelate )) != 0)
				return( status );
			curitem = 0;
			editlate.Contents.y 	= 35+60;
			template.Contents.y 	= 35+60;
			}
		else	curitem++;

		if ((status = generate_data_widget( fptr, nptr, &template )) != 0)
			return( status );
		else	template.Contents.y += 20;

		editlate.Contents.w = data_pixel_width(dptr,f+first,10);
		if ((status = generate_data_widget( fptr, nptr, &editlate )) != 0)
			return( status );
		else	editlate.Contents.y += 20;

		}

#ifdef	FUCKER
	/* Generate Edit Fields */
	/* -------------------- */
	template.Contents.style = _EDIT_FRAME;
	template.Contents.font 	= 1;
	template.Contents.x 	+= (template.Contents.w+10);
	template.Contents.y 	= 35;
	template.Contents.w 	= 0;
	template.Contents.h 	= 16;
	template.Contents.align = 0;		/* Left : Bold / Shadow */
	template.Contents.colour= 0x0010;	/* Black on Transparent */

	/* Generate Edit Fields */
	/* -------------------- */
	for (first=0,f=0; f < dptr->indexfields; f++ ) {
		if (!(nptr = dptr->name[f+first] ))
			continue;
		template.Contents.w = data_pixel_width(dptr,f+first,10);
		if ((status = generate_data_widget( fptr, nptr, &template )) != 0)
			return( status );
		else	template.Contents.y += 20;
		}

	template.Contents.y += 10;

	for (first=dptr->indexfields,f=0; f < dptr->datafields; f++ ) {
		if (!(nptr = dptr->name[f+first] ))
			continue;
		template.Contents.w = data_pixel_width(dptr,f+first,10);
		if ((status = generate_data_widget( fptr, nptr, &template )) != 0)
			return( status );
		else	template.Contents.y += 20;
		}

#endif
	/* Generate Operations */
	/* ------------------- */
	template.Contents.style = _BUTTON_FRAME;
	template.Contents.x 	= 10;
	if ( pageitems )
		template.Contents.y     = 120+((dptr->indexfields+pageitems)*20);
	else	template.Contents.y     = 60+((dptr->indexfields+dptr->datafields)*20);
	template.Contents.w 	= butwidth;
	template.Contents.h 	= 20;
	template.Contents.colour= 0x0010;	/* Black on Transparent */
	template.Contents.align = 0x0000;	/* Center : Exit/Help/Shadow */
	template.Contents.font 	= 2;

	if ((status = generate_data_widget( fptr, "Accept", &template )) != 0)
		return( status );
	else if (( status = generate_widget_action( fptr->last,dptr, 1 )) != 0)
		return( status );
	else	template.Contents.x 	+= template.Contents.w;
	if ((status = generate_data_widget( fptr, "Up", &template )) != 0)
		return( status );
	else if (( status = generate_widget_action( fptr->last,dptr, 2 )) != 0)
		return( status );
	else	template.Contents.x 	+= template.Contents.w;
	if ((status = generate_data_widget( fptr, "Load", &template )) != 0)
		return( status );
	else if (( status = generate_widget_action( fptr->last,dptr, 3 )) != 0)
		return( status );
	else	template.Contents.x 	+= template.Contents.w;
	if ((status = generate_data_widget( fptr, "Delete", &template )) != 0)
		return( status );
	else if (( status = generate_widget_action( fptr->last,dptr, 4 )) != 0)
		return( status );
	else	template.Contents.x 	+= template.Contents.w;
	if ((status = generate_data_widget( fptr, "Save", &template )) != 0)
		return( status );
	else if (( status = generate_widget_action( fptr->last,dptr, 5 )) != 0)
		return( status );
	else	template.Contents.x 	+= template.Contents.w;
	if ((status = generate_data_widget( fptr, "Down", &template )) != 0)
		return( status );
	else if (( status = generate_widget_action( fptr->last,dptr, 6 )) != 0)
		return( status );
	else	template.Contents.x 	+= template.Contents.w;
	if ((status = generate_data_widget( fptr, "Cancel", &template )) != 0)
		return( status );
	else if (( status = generate_widget_action( fptr->last,dptr, 7 )) != 0)
		return( status );

	calculate_form_triggers( fptr );

	/* Generate XML */
	/* ------------ */
	save_Form(fptr,QUICK);

	new_CameraItem(  __3D_FORM, fptr->loadname);

	/* Drop Form */
	/* --------- */
	remove_Form( fptr );


	liberate( fptr );

	return(13);

}

private	void	data_forms_options( struct form_control * fptr, int language )
{
	switch ( language ) {
		case	0	: /* program */
			fptr->isprogram   = 1;	/* production of a program		*/
			fptr->isoverlay   = 0;	/* production of a dll or overlay	*/
			break;
		case	1	: /* overlay */
			fptr->isprogram   = 1;	/* production of a program		*/
			fptr->isoverlay   = 1;	/* production of a dll or overlay	*/
			break;
		case	2	: /* module  */
			fptr->isprogram   = 0;	/* production of a program		*/
			fptr->isoverlay   = 1;	/* production of a dll or overlay	*/
			break;
		case	3	: /* include */
			fptr->isprogram   = 0;	/* production of a program		*/
			fptr->isoverlay   = 0;	/* production of a dll or overlay	*/
			break;
		}
	fptr->ispopup     = 1;	/* push pop */
	return;
}

public	int	generate_data_mask( struct file_control * optr, char * nptr, int nlen,char * tptr, int tlen, int language,int pageitems )
{
	struct	data_control * dptr=(struct data_control *) 0;
	struct	form_control * fptr=(struct form_control *) 0;
	if (!( optr )) 
		return(-1); 
	else if (!( dptr = optr->payload )) 
		return(-1); 
	else if (!( fptr = allocate_Form(nptr) ))
		return( -1 );
	else	{
		data_forms_options( fptr, language );
		return( generate_data_widgets( fptr, optr, dptr, tptr, pageitems ) );
		}
}

public	int	generate_data_page( struct file_control * optr, char * nptr, int nlen, char * tptr, int tlen,int language,int pageitems )
{
	struct	data_control * dptr=(struct data_control *) 0;
	struct	form_control * fptr=(struct form_control *) 0;
	if (!( optr )) 
		return(-1); 
	else if (!( dptr = optr->payload )) 
		return(-1); 
	else if (!( fptr = allocate_Form(nptr) ))
		return( -1 );

	else	{
		data_forms_options( fptr, language );
		return( generate_data_widgets( fptr, optr, dptr, tptr, pageitems ) );
		}
}


#endif	/* _ABAL_DATA_C */
	/* ------------ */

