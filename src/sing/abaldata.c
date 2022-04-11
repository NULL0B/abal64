#ifndef	_abaldata_c
#define	_abaldata_c

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

#define	MAXAEDBUFFERSIZE 1024

private	void	abal_base_instance( FILE * h, struct form_item * iptr, struct	data_control * dptr );
private	char *	abal_basefile_stub( struct form_item * iptr, int item );
public	void	abal_basefile_expression(FILE * h, struct form_item * iptr,int f, char * bfname, char * token );
private	void	abal_basefile_locate( FILE * h, struct form_item * iptr, int i, int margin, int lock );
public	void	abal_ngf_read(FILE * h, struct form_item* iptr, int margin );
public	void	abal_ngf_write(FILE * h, struct form_item* iptr, int margin );
private	char *	abal_data_reset(FILE * h, struct form_item * iptr );
private	int	abal_ngf_method( struct form_item * iptr );
public	struct  form_item * allocate_for_Widget();

private	int	use_new_collect=-1;

public	void	edit_database_helptext(struct file_control * fptr )
{
	int	i;
	for (i=0; i < MAXNATLANG; i++) { transcode_accents(&fptr->document[i],1); }
	accept_help_messages(
		&fptr->document[0],	/* english 	*/
		&fptr->document[1],	/* french  	*/
		&fptr->document[2],	/* italien 	*/
		&fptr->document[3],	/* spanish 	*/
		&fptr->document[4],	/* german  	*/
		&fptr->document[5],	/* dutch   	*/
		&fptr->document[6],	/* portugese 	*/
		&fptr->document[7]	/* other	*/
		);
	for (i=0; i < MAXNATLANG; i++) { transcode_accents(&fptr->document[i],2); }
	return;
}

int	dataProductionLanguage=_GENERATE_ABAL;
int	dataProductionModel=0;

int	get_data_production_model()
{
	return( dataProductionModel );
}

int	set_data_production_model(int v)
{
	dataProductionModel = v;
	return(v);
}

int	get_data_production_language()
{
	return( dataProductionLanguage );
}

int	set_data_production_language(int v)
{
	if ( SingConf->expert_user )
		dataProductionLanguage =v;
#ifdef	ABAL34A
	if ( v == 3 )
		dataProductionLanguage =_GENERATE_PHP;
	if ( v == 4 )
		dataProductionLanguage =_GENERATE_BIFS;
	if ( v == 5 )
		dataProductionLanguage =_GENERATE_XMTA;
	if ( v == 6 )
		dataProductionLanguage =_GENERATE_LASER;
#endif
	else	dataProductionLanguage =(v+_GENERATE_BAL);
	return(dataProductionLanguage);
}

private	void	check_file_Widget( struct form_item * iptr );

/*	------------------------------------	*/
/*	d r o p _ d a t a _ c o n t r o l ()	*/
/*	------------------------------------	*/
static	int	data_allocations=0;
static	int	data_liberations=0;

public	struct	data_control * drop_data_control( struct data_control * dptr )
{
	int	i;
	char *	nptr;
	if ( dptr ) {
		if ( dptr->lock )
			dptr->lock--;
		else	{
			dptr->fields = dptr->indexfields+dptr->datafields;
			for ( i=0; i < dptr->fields; i++ )
				if ((nptr = dptr->name[i]) != (char *) 0)
					liberate( nptr );
			data_liberations++;
			dptr = liberate( dptr );
			}
		}
	return((struct data_control *) 0);
}

public	void	delete_database_item( struct data_control * dptr, int item )
{
	char	*	nptr;
	int		i;

	if ( item < dptr->indexfields ) {

		/* release the current item */
		/* ------------------------ */
		if ((nptr = dptr->name[item]) != (char *) 0)
			liberate( nptr );

		/* transfer subsequent items back */
		/* ------------------------------ */
		for (i=item; i < dptr->indexfields; i++) {
			dptr->name[i] = dptr->name[i+1];
			dptr->type[i] = dptr->type[i+1];
			dptr->width[i] = dptr->width[i+1];
			dptr->first[i] = dptr->first[i+1];
			dptr->second[i] = dptr->second[i+1];
			dptr->special[i] = dptr->special[i+1];
			dptr->decimal[i] = dptr->decimal[i+1];
			}
		/* reset the final record */
		/* ---------------------- */
		dptr->name[i]   = (char *) 0;
		dptr->type[i]   = dptr->width[i]  = dptr->first[i]  = 
				  dptr->special[i] = dptr->second[i] = 
				  dptr->decimal[i] = 0;


		}
	else if ( dptr->datafields != 0 ) {

		/* release the current item */
		/* ------------------------ */
		if ((nptr = dptr->name[item]) != (char *) 0)
			liberate( nptr );

		/* adjust by index items */
		/* --------------------- */
		item -= dptr->indexfields;

		/* transfer subsequent items back */
		/* ------------------------------ */
		for (i=item; i < dptr->datafields; i++) {
			dptr->name[i+dptr->indexfields] = dptr->name[i+dptr->indexfields+1];
			dptr->type[i+dptr->indexfields] = dptr->type[i+dptr->indexfields+1];
			dptr->width[i+dptr->indexfields] = dptr->width[i+dptr->indexfields+1];
			dptr->first[i+dptr->indexfields] = dptr->first[i+dptr->indexfields+1];
			dptr->second[i+dptr->indexfields] = dptr->second[i+dptr->indexfields+1];
			dptr->special[i+dptr->indexfields] = dptr->special[i+dptr->indexfields+1];
			dptr->decimal[i+dptr->indexfields] = dptr->decimal[i+dptr->indexfields+1];
			}
		/* reset the final record */
		/* ---------------------- */
		dptr->name[i+dptr->indexfields]   = (char *) 0;
		dptr->type[i+dptr->indexfields]   = 
		dptr->width[i+dptr->indexfields]  = 
		dptr->first[i+dptr->indexfields]  = 
		dptr->second[i+dptr->indexfields] = 0;
		dptr->special[i+dptr->indexfields] = 0;
		dptr->decimal[i+dptr->indexfields] = 0;
		dptr->datafields--;
		}
	return;
}

public	int	insert_database_item( struct data_control * dptr, int item )
{
	char	*	nptr;
	int		i;
	int		n;
	if ( item >= dptr->indexfields ) {
		item -= dptr->indexfields;
		for (i=dptr->datafields; i > item; i-- ) {
			dptr->name[i+dptr->indexfields] = dptr->name[i+dptr->indexfields-1];
			dptr->type[i+dptr->indexfields] = dptr->type[i+dptr->indexfields-1];
			dptr->width[i+dptr->indexfields] = dptr->width[i+dptr->indexfields-1];
			dptr->first[i+dptr->indexfields] = dptr->first[i+dptr->indexfields-1];
			dptr->second[i+dptr->indexfields] = dptr->second[i+dptr->indexfields-1];
			dptr->special[i+dptr->indexfields] = dptr->special[i+dptr->indexfields-1];
			dptr->decimal[i+dptr->indexfields] = dptr->decimal[i+dptr->indexfields-1];
			}
		dptr->datafields++;
		/* reset the final record */
		/* ---------------------- */
		dptr->name[i+dptr->indexfields]   = (char *) 0;
		dptr->type[i+dptr->indexfields]   = 
		dptr->width[i+dptr->indexfields]  = 
		dptr->first[i+dptr->indexfields]  = 
		dptr->second[i+dptr->indexfields] = 0;
		dptr->special[i+dptr->indexfields] = 0;
		dptr->decimal[i+dptr->indexfields] = 0;
		}
	else 	{
		for (i=(dptr->indexfields+dptr->datafields); i > item; i-- ) {
			dptr->name[i] = dptr->name[i-1];
			dptr->type[i] = dptr->type[i-1];
			dptr->width[i] = dptr->width[i-1];
			dptr->first[i] = dptr->first[i-1];
			dptr->second[i] = dptr->second[i-1];
			dptr->special[i] = dptr->special[i-1];
			dptr->decimal[i] = dptr->decimal[i-1];
			}
		dptr->indexfields++;
		/* reset the final record */
		/* ---------------------- */
		dptr->name[i]   = (char *) 0;
		dptr->type[i]   = 
		dptr->width[i]  = 
		dptr->first[i]  = 
		dptr->second[i] = 0;
		dptr->special[i] = 0;
		dptr->decimal[i] = 0;
		}
	return(item);
}


/*	----------------------		*/
/*	n a m e f i e l d s ()		*/
/*	----------------------		*/

private	int namefields (char * fptr, int first, struct data_control * dptr ) 
{
	int	c=0;
	int	v=0;
	int	i=0;
	int	dtype=_ABAL_BCD;
	int	fields=first;

	if (!( fptr )) return(0);
	if (!( dptr )) return(0);

	dptr->width[(fields=first)] = 8;
	dptr->type [fields] = _ABAL_BCD;
	dptr->name [fields] = (char *) 0;
	dptr->first[fields] = 0;
	dptr->second[fields] = 0;
	dptr->special[fields] = 0;
	dptr->decimal[fields] = 0;


	while ((c = *(fptr++)) != 0) {
		if ( c == ' ' )
			continue;
		else if ( c == '@' ) {
			i = 0;
			while ((c = *(fptr++)) != ',') {
				if ( c == '(' ) break;
				else if ( c == ';' ) break;
				if (((c >= 'a' ) && ( c <= 'z' ))
				||  ((c >= 'A' ) && ( c <= 'Z' ))
				||  ((c >= '0' ) && ( c <= '9' ))
				||  ( c == '_' ) || ( c == '/' ))
					namebuffer[i++] = c;
				}
			if ( i ) {
				namebuffer [i] = 0;
				dptr->name [fields] = allocate_string(namebuffer);
				dptr->type [fields] = _ABAL_FIELD;
				dptr->width[fields] = 0;
				dptr->first[fields] = 0;
				dptr->second[fields] = 0;
				dptr->special[fields] = 1;
				dptr->decimal[fields] = 0;
				i = 0;
				}
			if ( c == '(' ) {
				/* field=F,variable(dimension) */
				while ( *fptr == ' ' ) fptr++;
				v = 0;
				while(( *fptr >= '0' )
				&&    ( *fptr <= '9' ))
					v = ((v*10) + ( *(fptr++) - '0'));
				while ( *fptr == ' ' ) fptr++;
				dptr->first[fields] = v;
				if ( *fptr == ',') {
					fptr++;
					while ( *fptr == ' ' ) fptr++;
					v = 0;
					while(( *fptr >= '0' )
					&&    ( *fptr <= '9' ))
						v = ((v*10) + ( *(fptr++) - '0'));
					while ( *fptr == ' ' ) fptr++;
					dptr->second[fields] = v;
					}
				if ( *fptr == ')' ) fptr++;
				while ((c = *(fptr++)) != ',');
				}
			fields++;
			dptr->special[fields] = 0;
			continue;
			}
		else if ( c == '*' ) {
			i = 0;
			while ((c = *(fptr++)) != ',') {
				if ( c == ';' ) break;
				if (((c >= 'a' ) && ( c <= 'z' ))
				||  ((c >= 'A' ) && ( c <= 'Z' ))
				||  ((c >= '0' ) && ( c <= '9' ))
				||  ( c == '_' ) || ( c == '/' ))
					namebuffer[i++] = c;
				}
			if ( i ) {
				namebuffer [i] = 0;
				dptr->name [fields] = allocate_string("filler");
				dptr->type [fields] = _ABAL_FILLER;
				dptr->width[fields] = atoi(namebuffer);
				dptr->first[fields] = 0;
				dptr->second[fields] = 0;
				dptr->special[fields] = 1;
				dptr->decimal[fields] = 0;
				i = 0;
				}
			fields++;
			dptr->special[fields] = 0;
			continue;
			}
		else if ( c == ',' ) {
			if ( i ) {
				namebuffer [i] = 0;
				dptr->name [fields] = allocate_string(namebuffer);
				if ((dptr->type [fields] = dtype) != _ABAL_BCD) {
					dtype = _ABAL_BCD;
					dptr->width[fields] = 0;
					}
				else	dptr->width[fields] = 8;
				dptr->first[fields] = 0;
				dptr->second[fields] = 0;
				i = 0;
				}
			fields++;
			dptr->special[fields] = 0;
			continue;
			}
/*		-----------------------------------	*/
/*		this inhibits use of 32 bit integer	*/
/*		-----------------------------------	*/
/*		else if ( c == ':' ) continue;		*/
/*		-----------------------------------	*/
		else if (( c == '.' ) 
		     ||  ( c == ';' )) {
			if ( i ) {
				namebuffer [i] = 0;
				dptr->name [fields] = allocate_string(namebuffer);
				if ((dptr->type [fields] = dtype) != _ABAL_BCD) {
					dtype = _ABAL_BCD;
					dptr->width[fields] = 0;
					}
				else	dptr->width[fields] = 8;
				dptr->first[fields] = 0;
				dptr->second[fields] = 0;
				}
			fields++;
			dptr->special[fields] = 0;
			break;
			}
		switch ( c ) {
			case	'?'	:
				dptr->special[fields] |= 2;
				continue;
			case	'!'	:
				dptr->special[fields] |= 1;
				continue;
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

				if ( *fptr == '.' ) {
					fptr++;
					v = 0;
					while(( *fptr >= '0' )
					&&    ( *fptr <= '9' ))
						v = ((v*10) + ( *(fptr++) - '0'));
					dptr->decimal[fields] = v;
					}
				continue;

			case	'('	:
				if ( i ) {
					namebuffer [i] = 0;
					dptr->name [fields] = allocate_string(namebuffer);
					i = 0;
					}

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


			case	'/'	:	/* class / object separator */
				dtype = _ABAL_OBJ;
				namebuffer[i++] = ' ';
				continue;

			default		:
				if (((c >= 'a' ) && ( c <= 'z' ))
				||  ((c >= 'A' ) && ( c <= 'Z' ))
				||  ((c >= '0' ) && ( c <= '9' ))
				||  ( c == '_' ) || ( c == '/' ))
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


public	void	show_data_control_statistics()
{
	printf("\nSing File Control : Allocations = %u, Liberations = %u \n",data_allocations,data_liberations);
	return;
}

private	struct	data_control * allocate_data_control()
{
	int	i;
	struct	data_control * dptr=(struct data_control *) 0;
	if (!( dptr = allocate( sizeof(struct data_control ) ) ))
		return( dptr );
	else	{
		for ( i=0; i < MAX_DATA_FIELDS; i++ ) {
			dptr->width[i] 	 =
			dptr->first[i]   =
			dptr->second[i]  =
			dptr->offset[i]  =
			dptr->decimal[i] = 0;
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
		data_allocations++;
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
		||  ( *(sptr+i) == '/'  ) || ( *(sptr+i) == '_'  )) {
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
	int	c;
	char *	cptr;
	if ( dptr->special[i] & 1 )
		fprintf(h,"!");
	if ( dptr->special[i] & 2 )
		fprintf(h,"?");
	if ( dptr->type[i]  == _ABAL_OBJ ) {
		for ( cptr=dptr->name[i]; *cptr != 0; cptr++ ) {
			if ((c = *cptr) == ' ')
				c = '/';
			fprintf(h,"%c",c);
			}		
		}
	else	{
		fprintf(h,"%s",dptr->name[i]);
		switch ( dptr->type[i] ) {
			case	_ABAL_BYTE	: fprintf(h,"#"); break;
			case	_ABAL_WORD	: fprintf(h,"%%"); break;
			case	_ABAL_LONG	: fprintf(h,":"); break;
			case	_ABAL_STRING	: fprintf(h,"$"); 
			case	_ABAL_BCD 	: 
				fprintf(h,"=%u",dptr->width[i]); 
				if ( dptr->decimal[i] )
					fprintf(h,".%u",dptr->decimal[i]); 
				break;
			}
		}
	if ( dptr->first[i] > 0 ) {
		fprintf(h,"(%u",dptr->first[i]);
		if ( dptr->second[i] > 0 )
			fprintf(h,",%u",dptr->second[i]);
		fprintf(h,")");
		}
	return;
}

public	int	include_modext_data( FILE * h, struct form_item * iptr )
{
	struct data_control * dptr;

	switch ((iptr->Contents.align & 0x000F)) {

		case	_SIFILE_FRAME 	:
		case	_MCFILE_FRAME 	:

			if (!( dptr = iptr->Contents.extra ))
				return(0);
			else if (!( dptr->option & _A_LINE ))
				return(0);
			else	{
				abal_include(h,"modext.inc");
				abal_include(h,"modext.xtn");
				return(1);
				}

		default		:
			return( 0 );
		}
}

/*	--------------------------------------------		*/
/*	s y m b o l i c _ d a t a _ c o n t r o l ()		*/
/*	--------------------------------------------		*/
/*	Called for production of XML source for XML		*/
/*	forms ressources					*/
/*	--------------------------------------------		*/

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
			else	{
				if ( dptr->option & _A_LINE )
					fprintf(h,"XK=");
				else if ( dptr->option & _A_LEFT )
					fprintf(h,"LK=");	
				else if ( dptr->option & _A_RIGHT )
					fprintf(h,"RK=");	
				else	fprintf(h,"K=");	

				}

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

	fprintf(h,"%u",dptr->datalength );

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

public	int	check_file_class( char * sptr, char * nptr )
{
	if (!( sptr ))
		return(0);
	else if (!( nptr ))
		return(0);

	if ( *(sptr++) != '(' )
		return(0);

	while ( *sptr == ' ' ) sptr++;

	while (( *sptr != 0 ) && ( *nptr != 0 ))
		if ( *(sptr++) != *(nptr++) )
			return(0);
	if ( *sptr == *nptr )
		return(1);
	while ( *sptr == ' ' ) 
		sptr++;
	if ( *sptr != ')' ) 
		return(0);
	else if (( *nptr == 0 ) || ( *nptr == ' ' ))
		return(1);
	else	return(0);
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
				dptr->lock++;
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

			case	'M'	:
			case	'm'	: /* Gestion du marker requise */
					  /* ------------------------- */
				dptr->option |= _A_SHADOW;
				continue;

			case	'L'	: /* Left aligned primary index */
			case	'l'	: /* -------------------------- */
				dptr->option |= _A_LEFT;
				continue;

			case	'R'	: /* Right aligned primary index */
			case	'r'	: /* --------------------------- */
				dptr->option |= _A_RIGHT;
				continue;

			case	'X'	: /* Modext option activation */
			case	'x'	: /* ------------------------ */
				dptr->option |= _A_LINE;
				continue;

			case	'V'	: /* Variable Data */
			case	'v'	: /* ------------- */
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
					if ((c = *(wptr++)) == ';' )
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


public	int	check_data_widget( struct form_item * iptr )
{
	struct	form_control 	* fptr;
	struct	data_control 	* dptr;
	char			* sptr;

	iptr->Contents.extra = drop_data_control( iptr->Contents.extra );
	iptr->Contents.xlimit = iptr->Contents.ylimit = 0;

	if (( iptr->Contents.align & 0x000F ) == _VISUAL_FRAME) {

		/* Limit Component Datatype as required */
		/* ------------------------------------ */
		switch (iptr->Contents.datatype) {
			case	_WIDGET_POINTER	:
			case	_WIDGET_CLASS	:
			case	_WIDGET_MODULE	:
			case	_WIDGET_OVERLAY	:
			case	_WIDGET_IFRAME	:
				break;
			default			:
				iptr->Contents.datatype = _WIDGET_CLASS;
				break;
			}
		/* detect and resolve component class or form name in payload */
		/* ---------------------------------------------------------- */
		if ( method_is_valid(( sptr = iptr->Contents.payload)) ) {
			if (!(fptr = locate_form_control( sptr ) ))
				return(0);

			/* Auto-Detection of Component Type */
			/* -------------------------------- */
			if ( iptr->Contents.datatype != _WIDGET_IFRAME )
			{
				if ( fptr->isoverlay ) {					
					if (!( fptr->isprogram ))
						iptr->Contents.datatype = _WIDGET_MODULE;
					else	iptr->Contents.datatype = _WIDGET_OVERLAY;
					}
			}
				
			/* Avoid Image Handling if Compiling */
			/* --------------------------------- */
			if (!( Context.compiling )) {
				draw_Form( fptr,0 );
				form_Image( fptr,0 );
				}
			if ((dptr = allocate_data_control()) != (struct data_control *) 0)
				dptr->image = fptr->image;
			}
		else	{
			dptr = allocate_data_control();
			}
		iptr->Contents.extra = dptr;
		return(1);
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
	return(1);
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
		if ( dptr->type[f+first] == _ABAL_FIELD ) {
			switch ((iptr->Contents.align & 0x000F)) {
				case	_VMEMORY_FRAME	:
					abal_vfield_dimensioned_member( h, dptr->datalength, namebuffer,dptr->first[f+first],dptr->second[f+first] );
					break;
				default			:
					dimensioned_abal_field(h,namebuffer,iptr->Contents.name,dptr->first[f+first],dptr->second[f+first]);
					break;
				}
			}
		else if ( dptr->type[f+first] == _ABAL_FILLER )
			abal_filler(h,dptr->width[f+first]);
		else	abal_dcl(h,namebuffer,iptr->Contents.name,dptr->type[f+first],dptr->width[f+first],dptr->first[f+first],dptr->second[f+first],NULL);
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
				else 	{
					indent(h,2);
					fprintf(h,"For  __pi = 1 To %u",dptr->first[f+first]);
					linefeed(h);
					if ( dptr->second[f+first] <= 1 ) {
						indent(h,3);
						fprintf(h,"%s%s(__pi)=0",namebuffer,iptr->Contents.name);
						linefeed(h);
						}
					else	{
						indent(h,3);
						fprintf(h,"For  __si = 1 To %u",dptr->second[f+first]);
						linefeed(h);
						indent(h,4);
						fprintf(h,"%s%s(__pi,__si)=0",namebuffer,iptr->Contents.name);
						linefeed(h);
						indent(h,3);
						fprintf(h,"Next __si");
						linefeed(h);
						}
					indent(h,2);
					fprintf(h,"Next __pi");
					linefeed(h);
					}
				break;
			case	_ABAL_STRING	:
				if ( dptr->first[f+first] <= 1 ) {
					indent(h,2);
					fprintf(h,"%s%s=%c %c",namebuffer,iptr->Contents.name,0x0022,0x0022);
					linefeed(h);
					}
				else	{
					indent(h,2);
					fprintf(h,"For  __pi = 1 To %u",dptr->first[f+first]);
					linefeed(h);
					if ( dptr->second[f+first] <= 1 ) {
						indent(h,3);
						fprintf(h,"%s%s(__pi)=%c %c",namebuffer,iptr->Contents.name,0x0022,0x0022);
						linefeed(h);
						}
					else	{
						indent(h,3);
						fprintf(h,"For  __si = 1 To %u",dptr->second[f+first]);
						linefeed(h);
						indent(h,4);
						fprintf(h,"%s%s(__pi,__si)=%c %c",namebuffer,iptr->Contents.name,0x0022,0x0022);
						linefeed(h);
						indent(h,3);
						fprintf(h,"Next __si");
						linefeed(h);
						}
					indent(h,2);
					fprintf(h,"Next __pi");
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

	abal_dcl(h,"e_",iptr->Contents.name,_ABAL_WORD,0,0,0,NULL);
	abal_dcl(h,"h_",iptr->Contents.name,_ABAL_WORD,0,0,0,NULL);
	abal_vfield(h,dptr->datalength);
	for (f=0; f < dptr->datafields; f++ ) {
		if ( dptr->name[f] != (char *) 0 )
			sprintf(namebuffer,"_%s_",dptr->name[f]);
		else	sprintf(namebuffer,"_m%u_",f);
		abal_dcl(h,namebuffer,iptr->Contents.name,dptr->type[f],dptr->width[f],dptr->first[f],dptr->second[f],NULL);
		}
	abal_field(h,(char *)0, (char *) 0);
	return;

}

public	void	html_file_agent( FILE * h , struct form_item * iptr )
{
	int	f;
	struct	data_control * 	dptr;

	if (!(dptr = iptr->Contents.extra ))
		return;

	if ( dptr->indexfields ) {
		for (f=0; f < dptr->indexfields; f++ ) {
			if (!( dptr->name[f] ))
				continue;
			else if ( dptr->first[f] )
				continue;
			else if ( dptr->second[f] )
				continue;
			fprintf(h,"Case %c%s.%s%c",0x0022,iptr->Contents.name,dptr->name[f],0X0022);
			linefeed(h);
			switch ( dptr->type[f] ) {
				case	_ABAL_BYTE	:
				case	_ABAL_WORD	:
				case	_ABAL_LONG	:
				case	_ABAL_BCD 	:
					fprintf(h,"LineBuffer=Print(($,$),LineBuffer,Conv$(_%s_%s))",dptr->name[f],iptr->Contents.name);
					linefeed(h);
					break;
				case	_ABAL_STRING	:
					fprintf(h,"LineBuffer=Print(($,$),LineBuffer,_%s_%s)",dptr->name[f],iptr->Contents.name);
					linefeed(h);
					break;
				}
			}
		}

	if ( dptr->datafields ) {
		for (f=0; f < dptr->datafields; f++ ) {
			if (!( dptr->name[f+dptr->indexfields] ))
				continue;
			else if ( dptr->first[f+dptr->indexfields] )
				continue;
			else if ( dptr->second[f+dptr->indexfields] )
				continue;
			fprintf(h,"Case %c%s.%s%c",0x0022,iptr->Contents.name,dptr->name[f+dptr->indexfields],0X0022);
			linefeed(h);
			switch ( dptr->type[f+dptr->indexfields] ) {
				case	_ABAL_BYTE	:
				case	_ABAL_WORD	:
				case	_ABAL_LONG	:
				case	_ABAL_BCD 	:
					fprintf(h,"LineBuffer=Print(($,$),LineBuffer,Conv$(_%s_%s))",dptr->name[f+dptr->indexfields],iptr->Contents.name);
					linefeed(h);
					break;
				case	_ABAL_STRING	:
					fprintf(h,"LineBuffer=Print(($,$),LineBuffer,_%s_%s)",dptr->name[f+dptr->indexfields],iptr->Contents.name);
					linefeed(h);
					break;
				}
			}
		}
	return;

}

public	int	is_database_Widget( struct form_item * iptr )
{
	struct	form_control * fptr;
	if (!( iptr ))
		return(0);
	else if (!(fptr = iptr->parent))
		return(0);
	else if ((iptr->Contents.style & _FRAME_TYPE) != _DATA_FRAME)
		return(0);
	else if (( iptr->Contents.align & 0x000F) != _DBFILE_FRAME )
		return(0);
	else	return(1);
}

public	int	is_basefile_of_Widget( struct form_item * iptr, char * nptr )
{
	struct	data_control * dptr;
	if (!( is_database_Widget( iptr ) ))
		return(0);
	else if (!( nptr ))
		return(0);
	else if (!( dptr = iptr->Contents.extra ))
		return(0);
	else	return( is_db_basefile( dptr, nptr ) );
}

public  int	abal_file_instance(FILE * h, struct form_item * iptr, int t )
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

	if ( iptr->Contents.access & _WIDGET_EXTERN ) {
		/* its an external item */
		fprintf(h,"Extern Field=m");
		linefeed(h);
		}

	if ((dptr = iptr->Contents.extra )  != (struct data_control *) 0) {
		iptr->Contents.extra = dptr;
		fields = dptr->indexfields + dptr->datafields;
		klen = dptr->indexlength;
		datalength = dptr->datalength;
		first= dptr->indexfields;
		}
	else	first = 0;

	if (!( fields ))
		fields = 8;

	/* --------------------------------------------------- */
	/* these values will need to be adjusted if more file  */
	/* structure control members are added. IJM March 2008 */
	/* --------------------------------------------------- */
	switch ( t ) {
		case	_ADFILE_FRAME	:	
			xlen =   14; 
			if ( datalength ) {
				if ( datalength % 256 ) {
					dptr->datalength = (((datalength / 256) + 1) * 256);
					datalength = dptr->datalength;
					}
				}
			break;
		case	_SQFILE_FRAME	:	xlen =    6; break;
		case	_SIFILE_FRAME	:	xlen =   30; break;
		case	_MCFILE_FRAME	:
			xlen = (1024 + 26 +1 + (fields*32)); 
			break;
		case	_DBFILE_FRAME	:
			xlen = (4096 + 30);
			break;
		}
	/* --------------------------------------------------- */

	if ( iptr->Contents.datatype == _WIDGET_POINTER )
		abal_ptr(h,"r_",iptr->Contents.name,_ABAL_STRING,datalength+klen+xlen,0,0);
	else	abal_dcl(h,"r_",iptr->Contents.name,_ABAL_STRING,datalength+klen+xlen,0,0,NULL);

	abal_field(h,"r_",iptr->Contents.name);
	abal_dcl(h,"h_",iptr->Contents.name,_ABAL_WORD,0,0,0,NULL);

	if ( t == _MCFILE_FRAME ) {
		abal_dcl(h,"t_",iptr->Contents.name,_ABAL_STRING,(fields*32) ,0,0,NULL);
		abal_dcl(h,"q_",iptr->Contents.name,_ABAL_STRING,1024,0,0,NULL);
		abal_dcl(h,"d_",iptr->Contents.name,_ABAL_WORD,0,0,0,NULL);
		}
	else if ( t == _DBFILE_FRAME ) {
		abal_dcl(h,"q_",iptr->Contents.name,_ABAL_STRING,4096,0,0,NULL);
		}

	if (( t == _MCFILE_FRAME )
	||  ( t == _DBFILE_FRAME ) 
	||  ( t == _SIFILE_FRAME )) {
		abal_dcl(h,"n_",iptr->Contents.name,_ABAL_LONG,2,0,0,NULL);
		abal_dcl(h,"i_",iptr->Contents.name,_ABAL_LONG,2,0,0,NULL);
		abal_ptr(h,"p_",iptr->Contents.name,_ABAL_STRING,(klen ? klen : 5),2,0);
		if ( t == _DBFILE_FRAME ) {
			abal_dcl(h,"pl_",iptr->Contents.name,_ABAL_WORD,2,0,0,NULL);
			abal_dcl(h,"rp_",iptr->Contents.name,_ABAL_WORD,2,0,0,NULL);
			abal_dcl(h,"new_",iptr->Contents.name,_ABAL_WORD,2,0,0,NULL);
			}
		abal_ptr(h,"s_",iptr->Contents.name,_ABAL_BYTE,1,2,0);
		if ( t == _SIFILE_FRAME ) {
			abal_ptr(h,"pp_",iptr->Contents.name,_ABAL_STRING,klen,2,0);
			}
		}
	if ( t == _ADFILE_FRAME ) {
		abal_dcl(h,"s_",iptr->Contents.name,_ABAL_BCD,8,0,0,NULL);
		}

	abal_dcl(h,"e_",iptr->Contents.name,_ABAL_WORD,0,0,0,NULL);
	abal_dcl(h,"l_",iptr->Contents.name,_ABAL_WORD,0,0,0,NULL);

	if ( klen ) {
		abal_dcl(h,"k_",iptr->Contents.name,_ABAL_STRING,klen,0,0,NULL);
		if ((dptr != (struct data_control *) 0)
		&&  (dptr->indexfields != 0 )) {
			redefine_file_instance(h,"k_",iptr,0,dptr->indexfields, dptr);
			abal_filler(h,dptr->indexlength);
			}
		abal_dcl(h,"m_",iptr->Contents.name,_ABAL_BYTE,0,0,0,NULL);
		}

	if ( datalength ) {
		if ( t != _DBFILE_FRAME ) {
			abal_dcl(h,"b_",iptr->Contents.name,_ABAL_STRING,datalength,0,0,NULL);
			if ((dptr != (struct data_control *) 0)
			&&  (dptr->datafields != 0 )) {
				redefine_file_instance(h,"b_",iptr,dptr->indexfields,dptr->datafields, dptr);
				abal_filler(h,dptr->datalength);
				}
			}
		}

	if ( iptr->Contents.access & _WIDGET_EXTERN ) {
		/* its an external item */
		fprintf(h,"Extern Field End");
		linefeed(h);
		}
	else	abal_field(h,(char*) 0,(char *) 0);

	if ( t == _DBFILE_FRAME ) {
		abal_base_instance( h, iptr, dptr );
		}
	return(fields);
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
			if (( iptr->Contents.datatype == _WIDGET_CLASS   )
			||  ( iptr->Contents.datatype == _WIDGET_POINTER )) {
				if ( iptr->Contents.datatype == _WIDGET_POINTER )
					fprintf(h,"%s %s %s",abal_payload(iptr),"pointer",iptr->Contents.name);
				else	fprintf(h,"%s %s",abal_payload(iptr),iptr->Contents.name);
				fprintf(h,"(%s;%s)",widget_x_position(iptr,0),widget_y_position(iptr,0));
				linefeed(h);
				}
			else if (iptr->Contents.datatype == _WIDGET_OVERLAY ) { 	
				abal_dcl(h,"b_",iptr->Contents.name,_ABAL_STRING,1024,0,0,NULL);
				instance_widget_overlay(h,iptr,overlay_interface_count(iptr));
				}
			break;
		case	_VARIABLE_FRAME :
			switch ( iptr->Contents.datatype ) {
				case	_WIDGET_BYTE		:	
					abal_dcl(h,"\0",iptr->Contents.name,_ABAL_BYTE,1,0,0,NULL);
					break;
				case	_WIDGET_WORD		:	
					abal_dcl(h,"\0",iptr->Contents.name,_ABAL_BYTE,2,0,0,NULL);
					break;
				case	_WIDGET_LONG		:	
					abal_dcl(h,"\0",iptr->Contents.name,_ABAL_LONG,4,0,0,NULL);
					break;
				case	_WIDGET_FLOAT		:	
					abal_dcl(h,"\0",iptr->Contents.name,_ABAL_BCD,4,0,0,NULL);
					break;
				case	_WIDGET_NUMERIC		:	
					abal_dcl(h,"\0",iptr->Contents.name,_ABAL_BCD,8,0,0,NULL);
					break;
				case	_WIDGET_STRING		:	
					abal_dcl(h,"\0",iptr->Contents.name,_ABAL_STRING,15,0,0,NULL);
					break;
				}
			break;
		case	_VMEMORY_FRAME	:
			abal_vmem_instance(h,iptr,t);
			break;

		case	_ADFILE_FRAME	:
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
		case	_VMEMORY_FRAME	:	break;
		case	_SIFILE_FRAME	:	fprintf(h,",SI"); 	break;
		case	_MCFILE_FRAME	:	fprintf(h,",MC"); 	break;
		case	_SQFILE_FRAME	:	fprintf(h,",SQ"); 	break;
		case	_DBFILE_FRAME	:	fprintf(h,",DB"); 	break;
		}

	if (!( iptr->Contents.align & _A_SHADOW ))
		fprintf(h,",WR");

	if (( iptr->Contents.align & _A_LINE ))
		fprintf(h,",EX");

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

public	void	abal_markername_parameter(FILE * h, struct form_item* iptr, int mode )
{
	struct	data_control * dptr=(struct data_control *) 0;
	if (!( dptr = iptr->Contents.extra )) {
		if ( mode )
			fprintf(h,",/FF");
		}
	else if (!( dptr->option & _A_SHADOW )) {
		if ( mode )
			fprintf(h,",/FF");
		}
	else	fprintf(h,",m_%s",iptr->Contents.name);
	return;
}

public	void	abal_recordname_parameter(FILE * h, struct form_item* iptr )
{
	struct	data_control * dptr=(struct data_control *) 0;
	if (!( dptr = iptr->Contents.extra ))
		return;
	else  if ( dptr->recordname != (char *) 0)
		fprintf(h,",%s",dptr->recordname);
	else if (!( iptr->Contents.ylimit ))
		return;
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
	struct	data_control * dptr=(struct data_control *) 0;
	if (!( dptr = iptr->Contents.extra ))
		return;
	else 	{
		fprintf(h,",");
		abal_lengthname_value(h,iptr);
		fprintf(h,",2");
		}

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
	if (!( dptr = iptr->Contents.extra ))
		return;
	else if ( dptr->recordname != (char *) 0)
		fprintf(h,"Len(%s)",dptr->recordname);
	else if (!(iptr->Contents.ylimit))
		fprintf(h,"0");
	else	fprintf(h,"%u",iptr->Contents.ylimit);
	return;
}

private	void	abal_recordlength_value(FILE * h, struct form_item * iptr)
{
	struct	data_control * dptr=(struct data_control *) 0;
	if (( dptr = iptr->Contents.extra ) != (struct data_control*)0) {
		if ((iptr->Contents.align & 0x000F) == _ADFILE_FRAME)
			fprintf(h,"l_%s",iptr->Contents.name);
		else if ( dptr->option & _A_BOLD )
			fprintf(h,"l_%s",iptr->Contents.name);
		else if (!(iptr->Contents.ylimit))
			fprintf(h,"0");
 		else	fprintf(h,"%u",iptr->Contents.ylimit);
		}
	else	fprintf(h,"0");
	return;
}

private	void	abal_sector_value(FILE * h, struct form_item * iptr)
{
	struct	data_control * dptr=(struct data_control *) 0;
	if (( dptr = iptr->Contents.extra ) != (struct data_control*)0) {
		if ((iptr->Contents.align & 0x000F) == _ADFILE_FRAME)
			fprintf(h,"s_%s",iptr->Contents.name);
		}
	return;
}

private	void	abal_lengthrecord_value(FILE * h, struct form_item * iptr)
{
	struct	data_control * dptr=(struct data_control *) 0;
	fprintf(h,",e_%s,(",iptr->Contents.name);
	if (( dptr = iptr->Contents.extra ) != (struct data_control*)0) {
		if ( dptr->option & _A_BOLD )
			fprintf(h,"l_%s",iptr->Contents.name);
		else if (!(iptr->Contents.ylimit))
			fprintf(h,"0");
 		else	fprintf(h,"%u",iptr->Contents.ylimit);
		}
	else	fprintf(h,"0");
	fprintf(h,"+%u+5)",iptr->Contents.xlimit);
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

		case	_ADFILE_FRAME	:
		case	_DBFILE_FRAME	:
				break;

		case	_SQFILE_FRAME	:
			fprintf(h,",D=");
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
	char *	tptr;
	switch ((iptr->Contents.align & 0x000F)) {
		case	_MCFILE_FRAME	:
			if (!( tptr = abal_dimension()))
				break;
			else if ((( *tptr == 'S' ) || ( *tptr == 's' )) && (( *(tptr+1) == 'I' ) || ( *(tptr+1) == 'i' )) && (!( *(tptr+2) )) ) {
				iptr->Contents.align &= 0xFFF0;
				iptr->Contents.align |= _SIFILE_FRAME;
				abal_ngf_assign(h,iptr,margin);
				iptr->Contents.align &= 0xFFF0;
				iptr->Contents.align |= _MCFILE_FRAME;
				abal_ngf_instruction(h,iptr,__abal_keyword_dfile,margin);
				abal_ngf_errortrap(h,iptr,(char *) 0);
				linefeed(h);
				abal_ngf_assign(h,iptr,margin);
				return;
				}
			else	break;

		default			:
			remove_brackets();
			break;
		}

	/* DFILE standard toute methodes */
	/* ----------------------------- */
	abal_ngf_instruction(h,iptr,__abal_keyword_dfile,margin);
	abal_ngf_errortrap(h,iptr,(char *) 0);
	linefeed(h);
	return;
}

public	void	abal_ngf_rename(FILE * h, struct form_item* iptr, int margin )
{
	char *	tptr;

	abal_ngf_instruction(h,iptr,__abal_keyword_rename,margin);
	if (( tptr = abal_dimension()) != (char *) 0)
		filename_parameter(h,tptr);
	else	filename_parameter(h,abal_payload(iptr));
	abal_ngf_errortrap(h,iptr,(char *) 0);
	linefeed(h);
	return;
}

public	void	abal_ngf_atb(FILE * h, struct form_item* iptr, int margin, int parsing )
{
	char *	tptr;
	abal_ngf_instruction(h,iptr,__abal_keyword_atb,margin);
	if ( parsing ) {
		if (( tptr = abal_dimension()) != (char *) 0)
			fprintf(h,",%s",tptr);
		}
	abal_ngf_errortrap(h,iptr,(char *) 0);
	linefeed(h);
	return;
}

private	void	abal_search_length(FILE * h, struct form_item* iptr, int margin )
{
	abal_ngf_instruction(h,iptr,__abal_keyword_search_l,margin);
	abal_indexname_parameter(h,iptr);
	abal_markername_parameter(h,iptr,1);
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
	abal_markername_parameter(h,iptr,1);
	abal_ngf_errortrap(h,iptr,(char *) 0);
	abal_recordname_parameter(h,iptr);

	if ((( dptr = iptr->Contents.extra ) != (struct data_control*)0)
	&&  ( dptr->option & _A_BOLD)) {
		fprintf(h,",");
		abal_lengthname_value(h,iptr);
		}

	linefeed(h);
}

private	void	abal_basefile_record(FILE * h, struct form_item* iptr, int margin )
{
	struct	data_control * dptr;
	abal_ngf_instruction(h,iptr,__abal_keyword_record,margin);
	abal_ngf_errortrap(h,iptr,(char *) 0);
	fprintf(h,",e_%s,Len(k_%s)+Len(b_%s)+5",
		iptr->Contents.name,iptr->Contents.name,iptr->Contents.name);
	linefeed(h);
	return;
}

public	void	abal_ngf_lock(FILE * h, struct form_item* iptr, int margin )
{
	if (( iptr->Contents.align & 0x000F) == _ADFILE_FRAME ) {
		abal_ngf_read(h,iptr,margin);
		return;
		}
	abal_repeat(h,margin);
		margin++;
		abal_ngf_instruction(h,iptr,__abal_keyword_search_m,margin);
		abal_indexname_parameter(h,iptr);
		abal_markername_parameter(h,iptr,1);
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

public	void	abal_ngf_search(FILE * h, struct form_item* iptr, int margin )
{
	struct	data_control * dptr;

	if (( iptr->Contents.align & 0x000F) == _ADFILE_FRAME ) {
		abal_ngf_read(h,iptr,margin);
		return;
		}

	if ((( dptr = iptr->Contents.extra ) != (struct data_control*)0)
	&&  ( dptr->option & _A_BOLD))
		abal_search_length(h,iptr,margin);

	abal_search_record(h,iptr,margin);
	return;
}

public	void	abal_ngf_searchm(FILE * h, struct form_item* iptr, int margin )
{
	abal_ngf_instruction(h,iptr,__abal_keyword_search_m,margin);
	abal_indexname_parameter(h,iptr);
	abal_markername_parameter(h,iptr,1);
	abal_ngf_errortrap(h,iptr,(char *) 0);
	fprintf(h,",m_%s",iptr->Contents.name);
	fprintf(h,",");
	abal_recordsize_value(h,iptr);
	fprintf(h,"+1");
	linefeed(h);
	return;

}

public	void	abal_ngf_locate(FILE * h, struct form_item* iptr, int margin )
{
	struct	data_control * 	dptr;
	char *			tptr;
	int			lock;
	int			nnn=0;
	char *			bfname;
	int			t;

	lock = check_lock();

	/* recover member identifier */
	/* ------------------------- */
	if (!( tptr = abal_expression()))
		tptr = "1";

	/* ensure legal dimension */
	/* ---------------------- */
	fprintf(h,"if ( ");
	abal_macro_conversion( h, tptr, iptr->Contents.name );
	fprintf(h," <= n_%s )",iptr->Contents.name);
	linefeed(h);

		/* ensure valid pointer */
		/* -------------------- */
		indent(h,++margin); 
		fprintf(h,"if ( ValidPtr(p_%s) <> 0 )",iptr->Contents.name);
		linefeed(h);

			/* position primary index value from the collection */
			/* ------------------------------------------------ */
			switch ((t = abal_ngf_method(iptr))) {
				case	_SIFILE_FRAME	:
				case	_MCFILE_FRAME	:
					indent(h,++margin); 
					fprintf(h,"k_%s=p_%s(",iptr->Contents.name,iptr->Contents.name);
					abal_macro_conversion( h, tptr, iptr->Contents.name );
					fprintf(h,")");
					linefeed(h);
	
					switch ( lock ) {
						case	'L'	:	abal_ngf_lock(h,iptr,margin);		break;
						case	'M' 	:	abal_ngf_searchm(h,iptr,margin);	break;
						default		:	abal_ngf_search(h,iptr,margin);		break;
		
						}
					break;

				case	_DBFILE_FRAME	:

					indent(h,margin); fprintf(h,"rp_%s = 1",iptr->Contents.name); linefeed(h);
					nnn = 0;
					while ((bfname = abal_basefile_stub( iptr, nnn )) != (char *) 0) {
						indent(h,margin);
						fprintf(h,"k_%s_%s= Move(p_%s(",bfname,iptr->Contents.name,iptr->Contents.name);
						abal_macro_conversion( h, tptr, iptr->Contents.name );
						fprintf(h,"),rp_%s,Len(k_%s_%s))",iptr->Contents.name,bfname,iptr->Contents.name);
						linefeed(h);
						abal_basefile_locate(h,iptr,nnn,margin,lock);
						indent(h,margin); fprintf(h,"rp_%s += Len(k_%s_%s)",
							iptr->Contents.name,
							bfname, iptr->Contents.name );
						linefeed(h);
						nnn++;
						}
					break;

				}

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

	if (( iptr->Contents.align & 0x000F) == _ADFILE_FRAME ) {
		indent(h,margin);   fprintf(h,"s_%s += (l_%s / 256)",iptr->Contents.name,iptr->Contents.name);
		linefeed(h);
		abal_ngf_read(h,iptr,margin);
		linefeed(h);
		return;
		}
	if ((( dptr = iptr->Contents.extra ) != (struct data_control*)0)
	&&  ( dptr->option & _A_BOLD))
		abal_ngf_instruction(h,iptr,__abal_keyword_down_l,margin);
	else	abal_ngf_instruction(h,iptr,__abal_keyword_down,margin);
	abal_markername_parameter(h,iptr,1);
	abal_ngf_errortrap(h,iptr,(char *) 0);
	if (( iptr->Contents.align & 0x000F) != _DBFILE_FRAME ) {
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
			indent(h,margin);fprintf(h,"if (( e_%s = 0 ) or ( e_%s = 63 ))",iptr->Contents.name,iptr->Contents.name); linefeed(h);
			abal_search_record(h,iptr,margin);
			indent(h,margin); fprintf(h,"Endif"); linefeed(h);
			}
		}
	else	linefeed(h);
	return;
}
public	void	abal_ngf_up(FILE * h, struct form_item* iptr, int margin )
{
	struct	data_control * dptr;

	if (( iptr->Contents.align & 0x000F) == _ADFILE_FRAME ) {
		indent(h,margin++); fprintf(h,"if ( s_%s > 0 )",iptr->Contents.name);
		linefeed(h);
		indent(h,margin);   fprintf(h,"s_%s -= (l_%s / 256)",iptr->Contents.name,iptr->Contents.name);
		linefeed(h);
		abal_ngf_read(h,iptr,margin);
		indent(h,--margin); fprintf(h,"Else :: e_%s = 64 :: Endif",iptr->Contents.name);
		linefeed(h);
		return;
		}
	if ((( dptr = iptr->Contents.extra ) != (struct data_control*)0)
	&&  ( dptr->option & _A_BOLD))
		abal_ngf_instruction(h,iptr,__abal_keyword_up_l,margin);
	else	abal_ngf_instruction(h,iptr,__abal_keyword_up,margin);
	abal_markername_parameter(h,iptr,1);
	abal_ngf_errortrap(h,iptr,(char *) 0);

	if (( iptr->Contents.align & 0x000F) != _DBFILE_FRAME ) {
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
			indent(h,margin);fprintf(h,"if (( e_%s = 0 ) or ( e_%s = 63 ))",iptr->Contents.name,iptr->Contents.name); linefeed(h);
			abal_search_record(h,iptr,margin+1);
			indent(h,margin); fprintf(h,"Endif"); linefeed(h);
			}
		}
	else	linefeed(h);
	return;
}
public	void	abal_ngf_first(FILE * h, struct form_item* iptr, int margin )
{
	if (( iptr->Contents.align & 0x000F) == _ADFILE_FRAME ) {
		indent(h,margin);   fprintf(h,"s_%s = 0",iptr->Contents.name);
		linefeed(h);
		abal_ngf_read(h,iptr,margin);
		return;
		}
	else	{
		indent(h,margin);
		fprintf(h,"k_%s=gener(Len(k_%s),Chr$(/00))",
			iptr->Contents.name,iptr->Contents.name);
		linefeed(h);
		abal_ngf_search(h,iptr,margin);
		abal_ngf_down(h,iptr,margin);
		}
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

	switch ((iptr->Contents.align & 0x000F)) {
		case	_ADFILE_FRAME	:
			abal_ngf_write(h,iptr,margin);
			return;
		case	_SIFILE_FRAME	:
		case	_MCFILE_FRAME	:
		case	_DBFILE_FRAME	:
			abal_ngf_instruction(h,iptr,__abal_keyword_insert,margin);
			abal_indexname_parameter(h,iptr);
			abal_markername_parameter(h,iptr,0);
			break;
		case	_SQFILE_FRAME	:
			abal_ngf_instruction(h,iptr,__abal_keyword_write,margin);
			break;
		}
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

public	void	abal_ngf_read(FILE * h, struct form_item* iptr, int margin )
{
	struct	data_control * dptr;

	switch ((iptr->Contents.align & 0x000F)) {
		case	_ADFILE_FRAME	:
			abal_ngf_instruction(h,iptr,__abal_keyword_read,margin);
			fprintf(h,",/60,s_%s",iptr->Contents.name);
			abal_ngf_errortrap(h,iptr,(char *) 0);
			abal_recordname_parameter(h,iptr);
			fprintf(h,",");
			abal_lengthname_value(h,iptr);
			linefeed(h);
			break;


		case	_SQFILE_FRAME	:
			abal_ngf_instruction(h,iptr,__abal_keyword_read,margin);
			abal_ngf_errortrap(h,iptr,(char *) 0);
			abal_recordname_parameter(h,iptr);
			if ((( dptr = iptr->Contents.extra ) != (struct data_control*)0)
			&&  ( dptr->option & _A_BOLD)) {
				fprintf(h,",");
				abal_lengthname_value(h,iptr);
				}
			linefeed(h);
			break;
		}
	return;
}

public	void	abal_ngf_write(FILE * h, struct form_item* iptr, int margin )
{
	struct	data_control * dptr;

	switch ((iptr->Contents.align & 0x000F)) {
		case	_ADFILE_FRAME	:
			abal_ngf_instruction(h,iptr,__abal_keyword_write,margin);
			fprintf(h,",/A0,s_%s",iptr->Contents.name);
			abal_ngf_errortrap(h,iptr,(char *) 0);
			abal_recordname_parameter(h,iptr);
			fprintf(h,",");
			abal_lengthname_value(h,iptr);
			linefeed(h);
			break;

		case	_SQFILE_FRAME	:
			abal_ngf_instruction(h,iptr,__abal_keyword_write,margin);
			abal_ngf_errortrap(h,iptr,(char *) 0);
			abal_recordname_parameter(h,iptr);
			if ((( dptr = iptr->Contents.extra ) != (struct data_control*)0)
			&&  ( dptr->option & _A_BOLD)) {
				fprintf(h,",");
				abal_lengthname_value(h,iptr);
				}
			linefeed(h);
			break;
		}
	return;
}

public	void	abal_ngf_backspace(FILE * h, struct form_item* iptr, int margin )
{
	struct	data_control * dptr;

	switch ((iptr->Contents.align & 0x000F)) {
		case	_SQFILE_FRAME	:
			abal_ngf_instruction(h,iptr,__abal_keyword_backspace,margin);
			abal_ngf_errortrap(h,iptr,(char *) 0);
			linefeed(h);
			break;
		}
	return;
}

private	int	abal_ngf_method( struct form_item * iptr )
{
	return( (iptr->Contents.align & 0x000F) );
}

public	void	abal_ngf_posit(FILE * h, struct form_item* iptr, int margin )
{
	switch ( abal_ngf_method(iptr) ) {
		case	_MCFILE_FRAME 	:
		case	_DBFILE_FRAME	:	
		abal_ngf_instruction(h,iptr,__abal_keyword_posit,margin);
		fprintf(h,",q_%s",iptr->Contents.name);
		abal_ngf_errortrap(h,iptr,(char *) 0);
		fprintf(h,",i_%s",iptr->Contents.name);
		linefeed(h);
		}
	return;
}

public	void	abal_ngf_posit_j(FILE * h, struct form_item* iptr, int margin, char * jptr )
{
	switch ( abal_ngf_method(iptr) ) {
		case	_DBFILE_FRAME 	:
			abal_ngf_instruction(h,iptr,__abal_keyword_posit,margin);
			if ( jptr ) {
				fprintf(h,"(%c%s%c)",__QUOTE,jptr,__QUOTE);
				}
			fprintf(h,",q_%s",iptr->Contents.name);
			abal_ngf_errortrap(h,iptr,(char *) 0);
			fprintf(h,",i_%s",iptr->Contents.name);
			linefeed(h);
			break;
		case	_MCFILE_FRAME	:	
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
	switch ( abal_ngf_method(iptr) ) {
		case	_MCFILE_FRAME 	:
		case	_DBFILE_FRAME	:
		indent(h,margin);
		fprintf(h,"%s.D=h_%s",__abal_keyword_posit,iptr->Contents.name);
		fprintf(h,",q_%s",iptr->Contents.name);
		abal_ngf_errortrap(h,iptr,(char *) 0);
		fprintf(h,",i_%s",iptr->Contents.name);
		linefeed(h);
		}
	return;
}

public	void	abal_ngf_positd_j(FILE * h, struct form_item* iptr, int margin, char * jptr )
{
	switch ( abal_ngf_method(iptr) ) {
		case	_MCFILE_FRAME 	:
			indent(h,margin);
			fprintf(h,"%s.D=h_%s",__abal_keyword_posit,iptr->Contents.name);
			fprintf(h,",q_%s",iptr->Contents.name);
			abal_ngf_errortrap(h,iptr,(char *) 0);
			fprintf(h,",i_%s",iptr->Contents.name);
			linefeed(h);
			break;
		case	_DBFILE_FRAME	:
			indent(h,margin);
			fprintf(h,"%s.D=h_%s",__abal_keyword_posit,iptr->Contents.name);
			if ( jptr ) {
				fprintf(h,"(%c%s%c)",__QUOTE,jptr,__QUOTE);
				}
			fprintf(h,",q_%s",iptr->Contents.name);
			abal_ngf_errortrap(h,iptr,(char *) 0);
			fprintf(h,",i_%s",iptr->Contents.name);
			linefeed(h);
		}
	return;
}

public	void	abal_new_collect(FILE * h, struct form_item* iptr, int margin )
{
	switch ( abal_ngf_method(iptr) ) {
		case	_MCFILE_FRAME 	:
		case	_DBFILE_FRAME	:
		abal_ngf_instruction(h,iptr,__abal_keyword_collect,margin);
		fprintf(h,",q_%s",iptr->Contents.name);
		abal_ngf_errortrap(h,iptr,(char *) 0);
		fprintf(h,",n_%s,p_%s",iptr->Contents.name,iptr->Contents.name);
		linefeed(h);
		}
	return;
}

public	void	abal_new_collectd(FILE * h, struct form_item* iptr, int margin )
{
	switch ( abal_ngf_method(iptr) ) {
		case	_MCFILE_FRAME 	:
		case	_DBFILE_FRAME	:
		indent(h,margin);
		fprintf(h,"%s.D=h_%s",__abal_keyword_collect,iptr->Contents.name);
		fprintf(h,",q_%s",iptr->Contents.name);
		abal_ngf_errortrap(h,iptr,(char *) 0);
		fprintf(h,",n_%s,p_%s",iptr->Contents.name,iptr->Contents.name);
		linefeed(h);
		}
	return;
}

public	void	abal_ngf_count(FILE * h, struct form_item* iptr, int margin )
{
	switch ( abal_ngf_method(iptr) ) {
		case	_MCFILE_FRAME 	:
		case	_DBFILE_FRAME	:
		abal_ngf_instruction(h,iptr,__abal_keyword_count,margin);
		fprintf(h,",q_%s",iptr->Contents.name);
		abal_ngf_errortrap(h,iptr,(char *) 0);
		fprintf(h,",n_%s",iptr->Contents.name);
		linefeed(h);
		}
	return;
}

public	void	abal_ngf_count_j(FILE * h, struct form_item* iptr, int margin, char * jptr )
{
	switch ( abal_ngf_method(iptr) ) {
		case	_DBFILE_FRAME	:
			abal_ngf_instruction(h,iptr,__abal_keyword_count,margin);
			if ( jptr ) {
				fprintf(h,"(%c%s%c)",__QUOTE,jptr,__QUOTE);
				}
			fprintf(h,",q_%s",iptr->Contents.name);
			abal_ngf_errortrap(h,iptr,(char *) 0);
			fprintf(h,",n_%s",iptr->Contents.name);
			linefeed(h);
			break;
		case	_MCFILE_FRAME 	:
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
	char *	jptr=(char *) 0;
	int	nnn;
	int	t;
	int	direction=0;
	char *	bfname;
	char *	tptr;
	char *	eptr;

	/* -------------------------------------------- */
	/* allow inhibition of the new deported collect */
	/* -------------------------------------------- */
	if ( use_new_collect == -1 )  {
		if (!( eptr = getenv( "NEWCOLLECT" ) ))
			use_new_collect = 1;
		else 	use_new_collect = atoi( eptr );
		}

	switch ((t = abal_ngf_method(iptr))) {


		case	_DBFILE_FRAME	:

		case	_SIFILE_FRAME	:
		case	_MCFILE_FRAME	:
			break;
		default			:
			remove_brackets(); 
			return;
		}

	if ((direction = check_direction()) & 2) {
		if ( t == _DBFILE_FRAME )
			jptr = abal_get_jointure(h);
		else	jptr = (char *) 0;
		}
	else	jptr = (char *) 0;

	/* Detect provided collect expression */
	/* ---------------------------------- */
	if (( tptr = abal_expression()) != (char *) 0 ) {

		switch ( t ) {

			case	_MCFILE_FRAME	:
			case	_DBFILE_FRAME	:

				fprintf(h,"q_%s = ",iptr->Contents.name);
				abal_macro_conversion( h, tptr, iptr->Contents.name );
				linefeed(h);

			}
		}


	switch ( t ) {

		case	_SIFILE_FRAME	:

			/* clear error variable since no count */
			/* ----------------------------------- */	
			fprintf(h,"e_%s = 0",iptr->Contents.name);
			linefeed(h);

			/* release the current collection */
			/* ------------------------------ */	
			indent(h,margin);
			fprintf(h,"%s p_%s",__abal_keyword_remove,iptr->Contents.name);
			linefeed(h);

			indent(h,margin);
			fprintf(h,"%s s_%s",__abal_keyword_remove,iptr->Contents.name);
			linefeed(h);

			/* Reset count variable */
			/* -------------------- */
			indent(h,margin);
			fprintf(h,"n_%s=10",iptr->Contents.name);
			linefeed(h);

			break;

		case	_MCFILE_FRAME	:
		case	_DBFILE_FRAME	:

			/* release the current collection */
			/* ------------------------------ */	
			indent(h,margin);
			fprintf(h,"%s p_%s",__abal_keyword_remove,iptr->Contents.name);
			linefeed(h);

			indent(h,margin);
			fprintf(h,"%s s_%s",__abal_keyword_remove,iptr->Contents.name);
			linefeed(h);

			/* Reset count variable */
			/* -------------------- */
			indent(h,margin);
			fprintf(h,"n_%s=0",iptr->Contents.name);
			linefeed(h);

			if ( use_new_collect ) {

				/* calculate collection size */
				/* ------------------------- */
				if ( direction )
					abal_new_collectd( h,iptr, margin );
				else 	abal_new_collect(h,iptr,margin);
				indent(h,margin++);
				fprintf(h,"if ( e_%s = 56 )",iptr->Contents.name);
				linefeed(h);
	
				}

			abal_ngf_count_j(h,iptr,margin,jptr);

			break;

		}


	/* allocate for collection storage */
	/* ------------------------------- */
	indent(h,margin++);
		fprintf(h,"if (( e_%s = 0 ) and ( n_%s > 0 ))",iptr->Contents.name,iptr->Contents.name);
	linefeed(h);

	indent(h,margin); 
	if ( t == _DBFILE_FRAME	 ) {
		fprintf(h,"%s p_%s(pl_%s,n_%s)",
			__abal_keyword_create,
			iptr->Contents.name,iptr->Contents.name,iptr->Contents.name); 
		}
	else	{
		fprintf(h,"%s p_%s(Len(k_%s),n_%s)",
			__abal_keyword_create,
			iptr->Contents.name,iptr->Contents.name,iptr->Contents.name); 
		}
	linefeed(h);
	indent(h,margin); 
		fprintf(h,"%s s_%s(n_%s)",
			__abal_keyword_create,
			iptr->Contents.name,iptr->Contents.name); 
	linefeed(h);

	switch ( t ) {

		case	_SIFILE_FRAME	:

			if (!( direction & 1 ))
				abal_ngf_first(h,iptr,margin);
			else	abal_ngf_last(h,iptr,margin);
			break;

		case	_MCFILE_FRAME	:
		case	_DBFILE_FRAME	:

			/* collect first item */
			/* ------------------ */
			if (!( direction & 1 )) {
				abal_ngf_posit_j(h,iptr,margin,jptr);
				abal_ngf_down(h,iptr,margin);
				}
			else	{
				abal_ngf_positd_j(h,iptr,margin,jptr);
				abal_ngf_up(h,iptr,margin);
				}
			break;

		}

		/* until collection end */
		/* -------------------- */
		indent(h,margin); 
		fprintf(h,"i_%s = 0",iptr->Contents.name);
		linefeed(h);
		indent(h,margin++); 
		fprintf(h,"while (e_%s = 0)",iptr->Contents.name); 
		linefeed(h);

			/* Generate Expression if Provided */
			/* ------------------------------- */
			switch ( t ) {

				case	_SIFILE_FRAME	:

					if ( tptr ) {
						indent(h,margin++);
						fprintf(h,"if ( ");
						abal_macro_conversion( h, tptr, iptr->Contents.name );
						fprintf(h," )");
						linefeed(h);
						}
				}

			/* increment item */
			/* -------------- */
			indent(h,margin); 
			fprintf(h,"i_%s += 1",iptr->Contents.name);
			linefeed(h);

			switch ( t ) {

				case	_SIFILE_FRAME	:
					indent(h,margin++); 
					fprintf(h,"if ( i_%s > n_%s )",iptr->Contents.name,iptr->Contents.name);
					linefeed(h);
						indent(h,margin);
						fprintf(h,"%s pp_%s(Len(k_%s),n_%s+10)",
							__abal_keyword_create,
							iptr->Contents.name,iptr->Contents.name,iptr->Contents.name); 
						linefeed(h);
						indent(h,margin);
						fprintf(h,"pp_%s(1) = Move(p_%s(1),1,(Len(k_%s)*n_%s))",
							iptr->Contents.name, iptr->Contents.name,
							iptr->Contents.name,iptr->Contents.name); 
						linefeed(h);

						/* release the current collection */
						/* ------------------------------ */	
						indent(h,margin);
						fprintf(h,"%s p_%s",__abal_keyword_remove,iptr->Contents.name);
						linefeed(h);

						indent(h,margin);
						fprintf(h,"p_%s = Alias(pp_%s(1))",
							iptr->Contents.name,iptr->Contents.name); 
						linefeed(h);

						indent(h,margin--);
						fprintf(h,"n_%s += 10",iptr->Contents.name); 
						linefeed(h);
						indent(h,margin);
						fprintf(h,"%s p_%s(Len(k_%s),n_%s)",
							__abal_keyword_alter,
							iptr->Contents.name,iptr->Contents.name,iptr->Contents.name); 
						linefeed(h);

					abal_endif(h,margin);	
					break;
				}	

			/* store the item */
			/* -------------- */
			switch ( t ) {
				case	_SIFILE_FRAME	:
				case	_MCFILE_FRAME	:

					indent(h,margin);
					fprintf(h,"p_%s(i_%s) = k_%s",iptr->Contents.name,iptr->Contents.name,iptr->Contents.name); 
					linefeed(h);
					break;

				case	_DBFILE_FRAME	:
					indent(h,margin); fprintf(h,"rp_%s = 1",iptr->Contents.name); linefeed(h);
					nnn = 0;
					while ((bfname = abal_basefile_stub( iptr, nnn++ )) != (char *) 0) {
						indent(h,margin);
						fprintf(h,"p_%s(i_%s) = Includ(rp_%s,k_%s_%s,Len(k_%s_%s))",
							iptr->Contents.name,
							iptr->Contents.name,
							iptr->Contents.name,
							bfname, iptr->Contents.name,
							bfname, iptr->Contents.name );
						linefeed(h);
						indent(h,margin); fprintf(h,"rp_%s += Len(k_%s_%s)",
							iptr->Contents.name,
							bfname, iptr->Contents.name );
						linefeed(h);
						}
					break;
				}

			switch ( t ) {

				case	_SIFILE_FRAME	:
					if ( tptr ) {
						abal_endif(h,margin);	
						}
				}

			/* collect next item */
			/* ----------------- */
			if (!( direction & 1 ))
				abal_ngf_down(h,iptr,margin);
			else	abal_ngf_up(h,iptr,margin);

		abal_wend(h,--margin);
	
		switch ( t ) {
			case	_SIFILE_FRAME	:
				indent(h,margin--);
				fprintf(h,"n_%s = i_%s",iptr->Contents.name,iptr->Contents.name); 
				linefeed(h);
			}

	abal_endif(h,margin--);	

	if ( use_new_collect ) {
		switch (t) {
			case	_MCFILE_FRAME 	:
			case	_DBFILE_FRAME	:
			abal_endif(h,margin--);	
			}
		}

	/* Liberate the eventual expression /
	/* -------------------------------- */
	if ( tptr ) { liberate( tptr ); }
	if ( jptr ) { liberate( jptr ); }
	return;
}

public	void	abal_ngf_key(
	FILE * h, 
	struct form_item* iptr, 
	int margin,
	char *	rubname,
	int	rubtype,
	int	rubsize,
	int	rubdec
	)
{
	if ( abal_ngf_method(iptr) == _MCFILE_FRAME ) {
		abal_ngf_instruction(h,iptr,__abal_keyword_key,margin);
		fprintf(h,",%c%s%c",0x0022,rubname,0x0022);
		switch ( rubtype ) {
			case	_ABAL_BCD	: 
				fprintf(h,",%u,B",rubsize);
				if ( rubdec )
					fprintf(h,",%u",rubdec);
				break;
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

public	void	abal_ngf_nkey(
	FILE * h, 
	struct form_item* iptr, 
	int margin,
	char *	tptr
	)
{
	if ( abal_ngf_method(iptr) == _MCFILE_FRAME ) {
		abal_ngf_instruction(h,iptr,__abal_keyword_nkey,margin);
		fprintf(h,",");
		abal_macro_conversion( h, tptr, iptr->Contents.name );
		abal_ngf_errortrap(h,iptr,(char *) 0);
		linefeed(h);
		}
	return;
}

public	void	abal_ngf_ex_key(
	FILE * h, 
	struct form_item* iptr, 
	int margin,
	char *	tptr
	)
{
	if ( abal_ngf_method(iptr) == _MCFILE_FRAME ) {
		abal_ngf_instruction(h,iptr,__abal_keyword_key,margin);
		fprintf(h,",");
		abal_macro_conversion( h, tptr, iptr->Contents.name );
		abal_ngf_errortrap(h,iptr,(char *) 0);
		linefeed(h);
		}
	return;
}

public	void	abal_ngf_fkey(
	FILE * h, 
	struct form_item* iptr, 
	int margin,
	char *	rubname
	)
{
	if ( abal_ngf_method(iptr) == _MCFILE_FRAME ) {
		abal_ngf_instruction(h,iptr,__abal_keyword_fkey,margin);
		if ( rubname ) { fprintf(h,",%c%s%c",0x0022,rubname,0x0022); }
		abal_ngf_errortrap(h,iptr,(char *) 0);
		linefeed(h);
		}
	return;
}

public	void	abal_ngf_rkey(
	FILE * h, 
	struct form_item* iptr, 
	int margin
	)
{
	if ( abal_ngf_method(iptr) == _MCFILE_FRAME ) {
		abal_ngf_instruction(h,iptr,__abal_keyword_rkey,margin);
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

public	void	abal_modext_link(
	FILE * h, 
	struct form_item* iptr, 
	int margin,
	char *	rubname,
	int	rubtype,
	int	rubsize 
	)
{
	if ( abal_ngf_method(iptr) == _MCFILE_FRAME ) {
		indent(h,margin);
		switch ( rubtype ) {
			case	_ABAL_BCD	:  
				fprintf(h,"_extNewBcd(h_%s,%c%s%c,1,%u,0",iptr->Contents.name,0x0022,rubname,0x0022,rubsize);
				break;
			case	_ABAL_STRING	: 
				fprintf(h,"_extNewAlpha(h_%s,%c%s%c,1,%u",iptr->Contents.name,0x0022,rubname,0x0022,rubsize);
				break;
			case	_ABAL_BYTE	: 
				fprintf(h,"_extNewNum1(h_%s,%c%s%c,1",iptr->Contents.name,0x0022,rubname,0x0022);
				break;
			case	_ABAL_WORD 	: 
				fprintf(h,"_extNewNum2(h_%s,%c%s%c,1",iptr->Contents.name,0x0022,rubname,0x0022);
				break;
			case	_ABAL_LONG 	: 
				fprintf(h,"_extNewNum3(h_%s,%c%s%c,1",iptr->Contents.name,0x0022,rubname,0x0022);;
				break;
			}
		fprintf(h,",e_%s)",iptr->Contents.name);
		linefeed(h);
		}
	return;
}

public	void	abal_ngf_link(FILE * h, struct form_item* iptr, int margin,char * rubname )
{
	switch ( abal_ngf_method(iptr) ) {
		case	_MCFILE_FRAME 	:
		case	_DBFILE_FRAME 	:
			abal_ngf_instruction(h,iptr,__abal_keyword_link,margin);
			if ( *rubname != 0x0022 )
				fprintf(h,",%c%s%c",0x0022,rubname,0x0022);
			else	fprintf(h,",%s",rubname);
			abal_ngf_errortrap(h,iptr,(char *) 0);
			linefeed(h);
		}
	return;
}

public	void	abal_ngf_clink(FILE * h, struct form_item* iptr, int margin )
{
	switch ( abal_ngf_method(iptr) ) {
		case	_MCFILE_FRAME 	:
		case	_DBFILE_FRAME 	:
			abal_ngf_instruction(h,iptr,__abal_keyword_clink,margin);
			abal_ngf_errortrap(h,iptr,(char *) 0);
			linefeed(h);
		}
	return;
}

public	void	abal_ngf_modif(FILE * h, struct form_item* iptr, int margin )
{
	struct	data_control * dptr;
	if (( iptr->Contents.align & 0x000F) == _ADFILE_FRAME ) {
		abal_ngf_write(h,iptr,margin);
		return;
		}
	abal_ngf_instruction(h,iptr,__abal_keyword_modif,margin);
	switch ((iptr->Contents.align & 0x000F)) {
		case	_SIFILE_FRAME	:
		case	_MCFILE_FRAME	:
		case	_DBFILE_FRAME	:
			abal_indexname_parameter(h,iptr);
			abal_markername_parameter(h,iptr,0);
			break;
		}
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

public	void	abal_ngf_update(FILE * h, struct form_item* iptr, int margin )
{
	switch ((iptr->Contents.align & 0x000F)) {
		case	_SIFILE_FRAME	:
		case	_MCFILE_FRAME	:
		case	_DBFILE_FRAME	:
			abal_ngf_insert(h,iptr,margin);
			indent(h,margin);
			fprintf(h,"if ( e_%s = 81 )",iptr->Contents.name);
			linefeed(h);
			abal_ngf_modif(h,iptr,margin+1);
			abal_endif(h,margin);
			linefeed(h);
			break;
		case	_SQFILE_FRAME	:
			abal_ngf_modif(h,iptr,margin+1);
			break;
		case	_ADFILE_FRAME 	:
			abal_ngf_write(h,iptr,margin);
			break;
		}
	return;
}

public	void	abal_ngf_delete(FILE * h, struct form_item* iptr, int margin )
{
	abal_ngf_instruction(h,iptr,__abal_keyword_delete,margin);
	abal_indexname_parameter(h,iptr);
	abal_markername_parameter(h,iptr,1);
	abal_ngf_errortrap(h,iptr,(char *) 0);
	linefeed(h);
	return;
}


public	int	abal_data_member_expression( FILE * h, struct form_item * iptr, char * token )
{
	int	c;
	int	fields;
	int	f;
	char *	bfname;
	struct data_control * dptr;

	if (!( dptr = iptr->Contents.extra ))
		return(0);
	else	{
		fields = (dptr->indexfields + dptr->datafields);
		for ( f=0; f < fields; f++ ) {
			if (!( dptr->name[f] ))
				continue;
			else if ( dptr->type[f]  != _ABAL_OBJ ) {
				if ( upper_compare( token, dptr->name[f] ) ) {
					abal_file_member_name(h,iptr,f);
					return(1);
					}
				else	continue;
				}
			else if (!(bfname = abal_basefile_stub( iptr, f )))
				continue;
			else if (!( upper_compare( token, bfname ) )) 
				continue;
			else if ((c = parser_getch()) != '.' ) {
				abal_syntax_error(h,iptr->Contents.name,112);
				return(1);
				}
			else if (!( token = abal_get_token(1))) {
				abal_syntax_error(h,iptr->Contents.name,112);
				return(1);
				}
			else	{
				abal_basefile_expression(h,iptr,f,bfname,token);
				return(1);
				}
			}
		return(0);
		}
}

public	void	abal_data_expression( FILE* h, struct form_item * iptr , int keycode, int margin, char * token )
{
	char *	tptr;
	int	direction=0;
	int	i;
	int	fields;
	int	f;
	struct data_control * dptr;
	switch ( keycode ) {
		case DATA_MEMBER_ONREMOVE	:
			if (!( remove_brackets() )) break;
			abal_data_destruction(h, iptr, margin );
			break;

		case DATA_MEMBER_ONCREATE	:
			if (!( remove_brackets() )) break;
			abal_data_construction(h, iptr, margin );
			break;

		case DATA_MEMBER_ASSIGN		:
			if (!( remove_brackets() )) break;
			abal_ngf_assign(h,iptr,margin);
			break;
		case DATA_MEMBER_RENAME 	:
			abal_ngf_rename(h,iptr,margin);
			break;

		case DATA_MEMBER_ATB 		:	
			abal_ngf_atb(h,iptr,margin,1);
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
			if (!( direction & 1 ))
				abal_ngf_posit(h,iptr,margin);
			else	abal_ngf_positd(h,iptr,margin);
			break;

		case DATA_MEMBER_RKEY			:
			if (!( remove_brackets() )) break;
			abal_ngf_rkey(h,iptr,margin);
			break;

		case DATA_MEMBER_CKEY			:
			if (!( remove_brackets() )) break;
			abal_ngf_ckey(h,iptr,margin);
			break;

		case DATA_MEMBER_NKEY			:
			if (( tptr = abal_expression()) != (char *) 0 )
				abal_ngf_nkey(h,iptr,margin,tptr);
			break;

		case DATA_MEMBER_FKEY			:
			tptr = abal_dimension();
			abal_ngf_fkey(h,iptr,margin,tptr);
			break;

		case DATA_MEMBER_KEY			:
			if (( tptr = abal_expression()) != (char *) 0 )
				abal_ngf_ex_key(h,iptr,margin,tptr);
			break;

		case DATA_MEMBER_LINK			:
			if (( tptr = abal_dimension()) != (char *) 0 )
				abal_ngf_link(h,iptr,margin,tptr);
			break;
		case DATA_MEMBER_CLINK			:
			if (!( remove_brackets() )) break;
			abal_ngf_clink(h,iptr,margin);
			break;
		case DATA_MEMBER_COLLECT		:
			abal_ngf_collect(h,iptr,margin);
			break;
		case DATA_MEMBER_COUNT		:
			if (!( remove_brackets() )) break;
			abal_ngf_count(h,iptr,margin);
			break;
		case DATA_MEMBER_RECORD		:
			if (!( remove_brackets() )) break;
			abal_basefile_record(h,iptr,margin);
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
			switch ((iptr->Contents.align & 0x000F)) {
				case	_SQFILE_FRAME	:
					abal_ngf_backspace(h,iptr,margin);
					abal_ngf_backspace(h,iptr,margin);
					abal_ngf_read(h,iptr,margin);
					break;
				case	_ADFILE_FRAME	:
				case	_DBFILE_FRAME	:
				case	_SIFILE_FRAME	:
				case	_MCFILE_FRAME	:
					abal_ngf_up(h,iptr,margin);
				}
			break;
		case DATA_MEMBER_NEXT		:
		case DATA_MEMBER_DOWN		:
			if (!( remove_brackets() )) break;
			switch ((iptr->Contents.align & 0x000F)) {
				case	_SQFILE_FRAME	:
					abal_ngf_read(h,iptr,margin);
					break;
				case	_ADFILE_FRAME	:
				case	_DBFILE_FRAME	:
				case	_SIFILE_FRAME	:
				case	_MCFILE_FRAME	:
					abal_ngf_down(h,iptr,margin);
					break;
				}
			break;
		case DATA_MEMBER_LAST		:
			if (!( remove_brackets() )) break;
			abal_ngf_last(h,iptr,margin);
			break;

		case DATA_MEMBER_SECTOR		:
			abal_sector_value(h,iptr);
			break;

		case DATA_MEMBER_LENGTH		:
			abal_recordlength_value(h,iptr);
			break;

		case DATA_MEMBER_FLAG			:
			fprintf(h,"s_%s",iptr->Contents.name);
			break;

		case DATA_MEMBER_DIRECTION		:
			fprintf(h,"d_%s",iptr->Contents.name);
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
		case DATA_MEMBER_MARKER		:
			fprintf(h,"m_%s",iptr->Contents.name);
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

/*	-----------------------------------------------------------	*/
/*		a b a l _ d a t a _ i n s t r u c t i o n		*/
/*	-----------------------------------------------------------	*/
/*	called from code production routines for the generation of	*/
/*	a particular file instruction.					*/
/*	-----------------------------------------------------------	*/
public	void	abal_data_instruction( FILE* h, struct form_item * iptr , int keycode, int margin, char * tptr, int option )
{
	int	direction=0;
	int	i;
	int	fields;
	int	f;
	switch ( keycode ) {
		/* ----------------------- */
		/* file level instructions */
		/* ----------------------- */
		case DATA_MEMBER_ONREMOVE	:
			abal_data_destruction(h, iptr, margin );
			break;
		case DATA_MEMBER_ONCREATE	:
			abal_data_construction(h, iptr, margin );
			break;
		case DATA_MEMBER_ASSIGN		:
			abal_ngf_assign(h,iptr,margin);
			break;
		case DATA_MEMBER_RENAME 	:
			abal_ngf_rename(h,iptr,margin);
			break;
		case DATA_MEMBER_ATB 		:	
			abal_ngf_atb(h,iptr,margin,1);
			break;
		case DATA_MEMBER_OPEN		:
			abal_ngf_open(h,iptr,margin);
			break;
		case DATA_MEMBER_CLOSE		:
			abal_ngf_close(h,iptr,margin);
			break;
		case DATA_MEMBER_CFILE		:
			if (!( remove_brackets() )) break;
			abal_ngf_cfile(h,iptr,margin);
			break;
		case DATA_MEMBER_DFILE		:
			abal_ngf_dfile(h,iptr,margin);
			break;

		/* ----------------------- */
		/*   sequential  indexed   */
		/* ----------------------- */
		case DATA_MEMBER_UPDATE		:
			abal_ngf_update(h,iptr,margin);
			break;
		case DATA_MEMBER_INSERT		:
			abal_ngf_insert(h,iptr,margin);
			break;
		case DATA_MEMBER_MODIF		:
			abal_ngf_modif(h,iptr,margin);
			break;
		case DATA_MEMBER_DELETE		:
			abal_ngf_delete(h,iptr,margin);
			break;
		case DATA_MEMBER_SEARCH		:
			abal_ngf_search(h,iptr,margin);
			break;

		case DATA_MEMBER_RKEY			:
			abal_ngf_rkey(h,iptr,margin);
			break;
		case DATA_MEMBER_CKEY			:
			abal_ngf_ckey(h,iptr,margin);
			break;
		case DATA_MEMBER_NKEY			:
			abal_ngf_nkey(h,iptr,margin,tptr);
			break;
		case DATA_MEMBER_FKEY			:
			abal_ngf_fkey(h,iptr,margin,tptr);
			break;
		case DATA_MEMBER_KEY			:
			abal_ngf_ex_key(h,iptr,margin,tptr);
			break;

		case DATA_MEMBER_LINK			:
			abal_ngf_link(h,iptr,margin,tptr);
			break;
		case DATA_MEMBER_CLINK			:
			abal_ngf_clink(h,iptr,margin);
			break;
		case DATA_MEMBER_POSIT		:
			if (!( option & 1 ))
				abal_ngf_posit(h,iptr,margin);
			else	abal_ngf_positd(h,iptr,margin);
			break;
		case DATA_MEMBER_COLLECT		:
			abal_ngf_collect(h,iptr,margin);
			break;
		case DATA_MEMBER_COUNT		:
			abal_ngf_count(h,iptr,margin);
			break;

		case DATA_MEMBER_RECORD		:
			abal_basefile_record(h,iptr,margin);
			break;

		case DATA_MEMBER_LOCATE		:
			abal_ngf_locate(h,iptr,margin);
			break;
		case DATA_MEMBER_LOCK		:
			abal_ngf_lock(h,iptr,margin);
			break;
		case DATA_MEMBER_FIRST		:
			abal_ngf_first(h,iptr,margin);
			break;
		case DATA_MEMBER_PREVIOUS	:
		case DATA_MEMBER_UP		:
			switch ((iptr->Contents.align & 0x000F)) {
				case	_SQFILE_FRAME	:
					abal_ngf_backspace(h,iptr,margin);
					abal_ngf_backspace(h,iptr,margin);
					abal_ngf_read(h,iptr,margin);
					break;
				case	_ADFILE_FRAME	:
				case	_DBFILE_FRAME	:
				case	_SIFILE_FRAME	:
				case	_MCFILE_FRAME	:
					abal_ngf_up(h,iptr,margin);
				}
			break;
		case DATA_MEMBER_NEXT		:
		case DATA_MEMBER_DOWN		:
			switch ((iptr->Contents.align & 0x000F)) {
				case	_SQFILE_FRAME	:
					abal_ngf_read(h,iptr,margin);
					break;
				case	_ADFILE_FRAME	:
				case	_DBFILE_FRAME	:
				case	_SIFILE_FRAME	:
				case	_MCFILE_FRAME	:
					abal_ngf_down(h,iptr,margin);
					break;
				}
			break;
		case DATA_MEMBER_LAST		:
			abal_ngf_last(h,iptr,margin);
			break;

		}
	return;
}

public	int	abal_php_array_index( FILE *h);
public	int	php_file_member( FILE * h, struct form_item * iptr, char * token )
{
	struct data_control * dptr;
	int	i;
	if (!( dptr = iptr->Contents.extra ))
		return(0);

	for (	i=0; i < dptr->datafields + dptr->indexfields; i++ ) {
		if (!( dptr->name[i] ))
			continue;
		else if (!( strcmp( dptr->name[i] , token ) )) {
			if (!( dptr->first[i] ))
				break;
			else	{
				fprintf(h,"_%s",token);
				return( abal_php_array_index(h) );
				}
			}
		}
	return(0);
}

public	void	abal_php_data_expression( FILE* h, struct form_item * iptr , int keycode, int margin, char * token )
{
	int	direction;
	switch ( keycode ) {
		case DATA_MEMBER_ONREMOVE	:
		case DATA_MEMBER_ONCREATE	:
			if (!( remove_brackets() )) break;
			fprintf(h,"->%s()",token);
			break;			
		case DATA_MEMBER_UPDATE		:
			if (!( remove_brackets() )) break;
			fprintf(h,"->OnUpdate();\n");
			break;			

		case DATA_MEMBER_RENAME 	:
			fprintf(h,"->On%s",token);
			break;			

		case DATA_MEMBER_IMPORT 	:
			fprintf(h,"->On%s",token);
			break;			

		case DATA_MEMBER_EXPORT 	:
			fprintf(h,"->On%s",token);
			break;			

		case DATA_MEMBER_ASSIGN		:
		case DATA_MEMBER_ATB 		:	
		case DATA_MEMBER_OPEN		:
		case DATA_MEMBER_CLOSE		:
		case DATA_MEMBER_CFILE		:
		case DATA_MEMBER_DFILE		:
		case DATA_MEMBER_INSERT		:
		case DATA_MEMBER_POSIT		:
		case DATA_MEMBER_RKEY		:
		case DATA_MEMBER_CKEY		:
		case DATA_MEMBER_NKEY		:
		case DATA_MEMBER_FKEY		:
		case DATA_MEMBER_KEY		:
		case DATA_MEMBER_CLINK		:
		case DATA_MEMBER_COUNT		:
		case DATA_MEMBER_RECORD		:
		case DATA_MEMBER_MODIF		:
		case DATA_MEMBER_DELETE		:
		case DATA_MEMBER_SEARCH		:
		case DATA_MEMBER_LOCK		:
		case DATA_MEMBER_FIRST		:
		case DATA_MEMBER_PREVIOUS	:
		case DATA_MEMBER_UP		:
		case DATA_MEMBER_NEXT		:
		case DATA_MEMBER_DOWN		:
		case DATA_MEMBER_LAST		:
			if (!( remove_brackets() )) break;
			fprintf(h,"->On%s()",token);
			break;			

		case DATA_MEMBER_LINK		:
			fprintf(h,"->On%s",token);
			break;			

		case DATA_MEMBER_COLLECT	:
			direction = (check_direction()&2);
			if (!( remove_brackets() )) break;
			fprintf(h,"->On%s()",token);
			break;			

		case DATA_MEMBER_WINDOW		:
			fprintf(h,"->OnWindow");
			break;			

		case DATA_MEMBER_DISTINCT	:
			fprintf(h,"->On%s",token);
			break;			

		case DATA_MEMBER_LOCATE		:
			fprintf(h,"->On%s",token);
			break;			

		case DATA_MEMBER_SECTOR		:
		case DATA_MEMBER_LENGTH		:
		case DATA_MEMBER_FLAG		:
		case DATA_MEMBER_DIRECTION	:


		case DATA_MEMBER_HANDLE		:
		case DATA_MEMBER_MARKER		:
		case DATA_MEMBER_INDEX		:
			fprintf(h,"->%s",token);
			break;
		case DATA_MEMBER_QUESTION	:
			fprintf(h,"->question");
			break;
		case DATA_MEMBER_RESPONSE	:
			fprintf(h,"->response");
			break;
		case DATA_MEMBER_ERROR		:
			fprintf(h,"->error");
			break;
		case	-1			:
			fprintf(h,"->_%s",token);
			break;
		}
	return;
}

private	void	abal_ngf_keys(FILE * h, struct form_item * iptr, int margin )
{
	char	fillname[64];
	struct data_control * dptr;
	int	j;
	int	f;
	int	l;
	int	fieldsize=0;
	if (!(dptr = iptr->Contents.extra ))
		return;
	abal_ngf_rkey(h,iptr,margin);
	for (f=0; f < dptr->datafields; f++ ) {
		if ( dptr->type[dptr->indexfields+f]== _ABAL_FIELD ) {
			abal_ngf_fkey(
				h,iptr,margin,
				dptr->name [dptr->indexfields+f]);
			for (j=0; j < f; j++ ) {
				if (!( strcmp(
					dptr->name [dptr->indexfields+j],
					dptr->name [dptr->indexfields+f]) )) {
					fieldsize= dptr->width[dptr->indexfields+j];
					break;
					}
				}
			continue;
			}
		else if ( dptr->type[dptr->indexfields+f]== _ABAL_FILLER ) {
			sprintf(fillname,"RFILL%u",dptr->indexfields+f);
			abal_ngf_key(
				h,iptr,margin,fillname,_ABAL_STRING,
				(l=dptr->width[dptr->indexfields+f]),
				dptr->decimal[dptr->indexfields+f]
				);
			}
		else if (!( dptr->first[dptr->indexfields+f] )) {
			abal_ngf_key(
				h,iptr,margin,
				dptr->name [dptr->indexfields+f],
				dptr->type [dptr->indexfields+f],
				(l=dptr->width[dptr->indexfields+f]),
				dptr->decimal[dptr->indexfields+f]
				);
			}
		else if (!( dptr->second[dptr->indexfields+f] )) {
			abal_ngf_key(
				h,iptr,margin,
				dptr->name [dptr->indexfields+f],
				dptr->type [dptr->indexfields+f],
				(l=dptr->width[dptr->indexfields+f]*dptr->first[dptr->indexfields+f]),
				dptr->decimal[dptr->indexfields+f]
				);
			}
		else	{
			abal_ngf_key(
				h,iptr,margin,
				dptr->name [dptr->indexfields+f],
				dptr->type [dptr->indexfields+f],
				(l=dptr->width[dptr->indexfields+f]*dptr->first[dptr->indexfields+f]*dptr->second[dptr->indexfields+f]),
				dptr->decimal[dptr->indexfields+f]
				);
			}
		if ( fieldsize ) {
			if ( fieldsize > l )
				fieldsize -= l;
			else	{
				fieldsize=0;
				abal_ngf_fkey( h,iptr,margin,(char *) 0);
				}
			}
			
		}
	return;
}

private	void	abal_modext_keys(FILE * h, struct form_item * iptr, int margin )
{
	struct data_control * dptr;
	int	f;

	if (!(dptr = iptr->Contents.extra ))
		return;

	/* test if modext keys are required */
	/* -------------------------------- */
	if (!( dptr->option & _A_LINE ))
		return;

	for (f=0; f < dptr->indexfields; f++ ) {
		if (!( dptr->first[f] )) {
			abal_ngf_key(
				h,iptr,margin,
				dptr->name [f],
				dptr->type [f],
				dptr->width[f],
				dptr->decimal[f]
				);
			}
		else if (!( dptr->second[f] )) {
			abal_ngf_key(
				h,iptr,margin,
				dptr->name [f],
				dptr->type [f],
				dptr->width[f]*dptr->first[f],
				dptr->decimal[f]
				);
			}
		else	{
			abal_ngf_key(
				h,iptr,margin,
				dptr->name [f],
				dptr->type [f],
				dptr->width[f]*dptr->first[f]*dptr->second[f],
				dptr->decimal[f]
				);
			}
		}
	return;
}

private	void	abal_modext_links(FILE * h, struct form_item * iptr, int margin )
{
	struct data_control * dptr;
	int	f;
	if (!(dptr = iptr->Contents.extra ))
		return;
	if (!( dptr->option & _A_LINE ))
		return;

	for (f=0; f < dptr->indexfields; f++ ) {
		if (!( dptr->first[f] )) {
			abal_modext_link(
				h,iptr,margin,
				dptr->name [f],
				dptr->type [f],
				dptr->width[f]);
			}
		else if (!( dptr->second[f] )) {
			abal_modext_link(
				h,iptr,margin,
				dptr->name [f],
				dptr->type [f],
				dptr->width[f]*dptr->first[f]);
			}
		else	{
			abal_modext_link(
				h,iptr,margin,
				dptr->name [f],
				dptr->type [f],
				dptr->width[f]*dptr->first[f]*dptr->second[f]);
			}
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
		if ( dptr->type[dptr->indexfields+f]== _ABAL_FIELD )
			continue;
		else if ( dptr->type[dptr->indexfields+f]== _ABAL_FILLER )
			continue;
		else if (!( dptr->special[dptr->indexfields+f] & 1 )) {
			abal_ngf_link(
				h,iptr,margin,
				dptr->name[dptr->indexfields+f]);
			}
		}	
	abal_ngf_clink(h,iptr,margin);
	abal_modext_links(h,iptr,margin);
	abal_endif(h,--margin);
	return;
}

private	void	abal_mc_links_and_keys(FILE * h, struct form_item * iptr, int margin )
{
	abal_ngf_keys (h,iptr,margin);
	abal_ngf_links(h,iptr,margin);
	abal_modext_keys (h,iptr,margin);
	return;
}

private	void	abal_file_pointer_construction(FILE * h, struct form_item * iptr, int margin )
{
	if ( iptr->Contents.datatype == _WIDGET_POINTER ) {
		indent(h,margin);
		fprintf(h,"%s r_%s",
			__abal_keyword_create,
			iptr->Contents.name);
		linefeed(h);
		}
	return;
}

private	void	abal_file_simc_construction(FILE * h, struct form_item * iptr, int margin )
{
	int t = (iptr->Contents.align & 0x000F);
	if (( t == _MCFILE_FRAME ) 
	||  ( t == _SIFILE_FRAME )) {
		indent(h,margin);
		fprintf(h,"n_%s=0",iptr->Contents.name);
		linefeed(h);
		indent(h,margin); fprintf(h,"%s p_%s",__abal_keyword_forget,iptr->Contents.name);
		linefeed(h);
		indent(h,margin); fprintf(h,"%s s_%s",__abal_keyword_forget,iptr->Contents.name);
		linefeed(h);
		indent(h,margin);
		fprintf(h,"m_%s=/FF",iptr->Contents.name);
		linefeed(h);
		}
	if ( t == _MCFILE_FRAME ) {
		indent(h,margin);
		fprintf(h,"q_%s=%c %c",iptr->Contents.name,__QUOTE,__QUOTE);
		linefeed(h);
		}
	return;
}

private	void	abal_file_handle_construction(FILE * h, struct form_item * iptr, int margin )
{
	indent(h,margin);
	fprintf(h,"h_%s=Event(77)",iptr->Contents.name);
	linefeed(h);
	return;
}

public  int	abal_ngf_open_create(FILE * h, struct form_item * iptr, int margin )
{
	abal_ngf_open(h,iptr,margin);
	indent(h,margin);
	fprintf(h,"if ( e_%s <> 0 )",iptr->Contents.name);
	linefeed(h);
		indent(h,margin+1);
		fprintf(h,"Status = e_%s",iptr->Contents.name);
		linefeed(h);
		if (!( iptr->Contents.align & _A_BOLD )) {
			abal_ngf_cfile(h,iptr,margin+1);
			}
	abal_else(h,margin);
		indent(h,margin+1);
		fprintf(h,"Status = 0");
		linefeed(h);
	abal_endif(h,margin);
	return;
}

#include "abaldb.c"
public  int	abal_data_construction(FILE * h, struct form_item * iptr, int margin )
{
	int	fixex=0;
	int	t;
	char	*		cptr;
	struct data_control * dptr;
	dptr = iptr->Contents.extra;
	switch ((t = (iptr->Contents.align & 0x000F))) {
		case	_VARIABLE_FRAME		:	/* 0 variable	*/
			break;
		case	_OBJECT_FRAME		:	/* 1 structure	*/
		case	_VISUAL_FRAME		:	/* 2 visual	*/

			switch( iptr->Contents.datatype ) {

				case	_WIDGET_OVERLAY	:
					indent(h,1);
					fprintf(h,"b_%s=",iptr->Contents.name);
					if ( method_is_valid((cptr = iptr->Contents.format )) ) {
						abal_macro_conversion( h, cptr, iptr->Contents.name );
						}
					else	{
						fprintf(h,"%c %c",0x0022,0x0022);
						}
					linefeed(h);

					attach_widget_overlay(h,iptr);

					linefeed(h);
					break;

				case	_WIDGET_MODULE	:
					indent(h,margin);
					fprintf(h,"%sOnCreate(",abal_payload(iptr));
					if ( method_is_valid((cptr = iptr->Contents.format )) ) {
						abal_macro_conversion( h, cptr, iptr->Contents.name );
						}
					fprintf(h,")");
					
					linefeed(h);
					break;

				case	_WIDGET_POINTER :
					indent(h,margin);
					fprintf(h,"%s %s",__abal_keyword_create,iptr->Contents.name);
					linefeed(h);
					break;

				}
			break;
		case	_VMEMORY_FRAME		:
			if ( iptr->Contents.access & _WIDGET_EXTERN )
				break;
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
				fprintf(h,"Status = e_%s",iptr->Contents.name);
				linefeed(h);
				if (!( iptr->Contents.align & _A_BOLD )) {
					abal_ngf_cfile(h,iptr,margin+1);
					reset_vmem_fields(h,iptr,dptr,0);
					}
				abal_else(h,margin);
				indent(h,margin+1);
				fprintf(h,"Status = 0");
				linefeed(h);
				abal_endif(h,margin);
				}
			break;

		case	_DBFILE_FRAME		:	/* 7 sifile	*/
			if ( iptr->Contents.access & _WIDGET_EXTERN )
				break;
			abal_file_pointer_construction(h,iptr,margin);
			abal_file_handle_construction(h,iptr,margin);
			abal_db_assign(h,iptr,margin);
			abal_ngf_open(h,iptr,margin);
			indent(h,margin);
			fprintf(h,"if ( e_%s <> 0 )",iptr->Contents.name);
			linefeed(h);
			indent(h,margin+1);
			fprintf(h,"new_%s = e_%s",iptr->Contents.name,iptr->Contents.name);
			linefeed(h);
			if (!( iptr->Contents.align & _A_LINE )) {
				fixex = 1;
				iptr->Contents.align |= _A_LINE;
				abal_db_assign(h,iptr,margin);
				iptr->Contents.align &= ~_A_LINE;
				}
			if (!( iptr->Contents.align & _A_BOLD )) {
				abal_ngf_cfile(h,iptr,margin+1);
				}
			abal_else(h,margin);
			indent(h,margin+1);
			fprintf(h,"new_%s = 0",iptr->Contents.name);
			linefeed(h);
			abal_endif(h,margin);	
			abal_db_file_keys(h,iptr,margin);
			indent(h,margin);
			fprintf(h,"if ( new_%s <> 0)",iptr->Contents.name);
			linefeed(h);
			abal_db_jointures(h,iptr,margin+1);
			if ( fixex ) {
				abal_ngf_atb(h,iptr,margin,0);
				}
			indent(h,margin); fprintf(h,"Endif"); linefeed(h);
			break;

		case	_ADFILE_FRAME		:	/* 6 sifile	*/
		case	_SQFILE_FRAME		:	/* 6 sifile	*/
		case	_SIFILE_FRAME		:	/* 3 sifile	*/
		case	_MCFILE_FRAME		:	/* 4 sifile	*/
			if ( iptr->Contents.access & _WIDGET_EXTERN )
				break;
			abal_file_pointer_construction(h,iptr,margin);
			abal_file_simc_construction(h,iptr,margin);
			abal_file_handle_construction(h,iptr,margin);
			if ( t == _ADFILE_FRAME ) {
				indent(h,margin);
				fprintf(h,"l_%s = %u",iptr->Contents.name,dptr->datalength);
				linefeed(h);
				}
			abal_ngf_assign(h,iptr,margin);
			abal_ngf_open_create(h,iptr,margin);
			if ( t == _MCFILE_FRAME ) {
				abal_mc_links_and_keys(h,iptr,margin);
				}
			break;
		}
	return(0);
}

public  int	abal_data_destruction(FILE * h, struct form_item * iptr, int margin )
{
	char	*	cptr;
	int		t;
	switch ((t = (iptr->Contents.align & 0x000F)) ) {
		case	_VARIABLE_FRAME		:	/* 0 variable	*/
			break;
		case	_OBJECT_FRAME		:	/* 1 structure	*/
		case	_VISUAL_FRAME		:	/* 2 visual	*/
			switch( iptr->Contents.datatype ) {

				case	_WIDGET_OVERLAY	:
					detach_widget_overlay(h,iptr);
					break;

				case	_WIDGET_MODULE	:
					indent(h,margin);
					fprintf(h,"%sOnRemove(",abal_payload(iptr));
					if ( method_is_valid((cptr = iptr->Contents.format )) ) {
						abal_macro_conversion( h, cptr, iptr->Contents.name );
						}
					fprintf(h,")");
					linefeed(h);
					break;

				case	_WIDGET_POINTER :
					indent(h,margin);
					fprintf(h,"%s %s",__abal_keyword_remove,iptr->Contents.name);
					linefeed(h);
					}
			break;

		case	_VMEMORY_FRAME		:	/* virtual memory 	*/
			if ( iptr->Contents.access & _WIDGET_EXTERN )
				break;
			abal_ngf_close(h,iptr,margin);
			break;

		case	_DBFILE_FRAME		:	/* 7 sifile	*/
			if ( iptr->Contents.access & _WIDGET_EXTERN )
				break;
			abal_database_destruction(h,iptr,margin);
			abal_ngf_close(h,iptr,margin);
			indent(h,margin);
			fprintf(h,"Event(77)=h_%s",iptr->Contents.name);
			linefeed(h);
			break;

		case	_SQFILE_FRAME		:	/* 6 sifile	*/
		case	_SIFILE_FRAME		:	/* 3 sifile		*/
		case	_MCFILE_FRAME		:	/* 4 sifile		*/
			if ( iptr->Contents.access & _WIDGET_EXTERN )
				break;
			abal_ngf_close(h,iptr,margin);
			indent(h,margin);
			fprintf(h,"Event(77)=h_%s",iptr->Contents.name);
			linefeed(h);
			if (( t == _MCFILE_FRAME ) 
			||  ( t == _SIFILE_FRAME )) {
				indent(h,margin);
				fprintf(h,"if ( ValidPtr(p_%s) <> 0 ) :: %s p_%s :: Endif",
					iptr->Contents.name,
					__abal_keyword_remove,
					iptr->Contents.name);
				linefeed(h);
				}
			if ( iptr->Contents.datatype == _WIDGET_POINTER ) {
				indent(h,margin);
				fprintf(h,"if ( ValidPtr(r_%s) <> 0 ) :: %s r_%s :: Endif",
					iptr->Contents.name,
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
	calculate_form_lines( iptr, &linelength, &nblines );

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

private	void	default_class_image( int atx, int aty, int nbx, int nby )
{
	visual_frame  ( atx,aty,nbx, nby , _RIDGE_FRAME );
	return;
}

public	void	draw_class_image(int topx, int topy,struct form_item* iptr,int editing)
{
	char *	sptr;
	char *	filename;
	struct data_control * xptr;
	struct standard_image * widget_image_loader(char *,int);
	if (!( iptr ))
		return;
	else if (!(xptr = iptr->Contents.extra )) {
		default_class_image( 	
			topx+iptr->Contents.x, topy+iptr->Contents.y, 
			iptr->Contents.w,iptr->Contents.h);
		return;
		}
	else if (!( xptr->image )) {
		default_class_image( 	
			topx+iptr->Contents.x, topy+iptr->Contents.y, 
			iptr->Contents.w,iptr->Contents.h);
		return;
		}
	drawimage( 	topx+iptr->Contents.x, topy+iptr->Contents.y, 
		(iptr->Contents.w=xptr->image->columns), 
		(iptr->Contents.h=xptr->image->rows), 
		xptr->image,(_A_SHADOW | (iptr->Contents.align & 0xFFF0)));

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
	int	v;
	struct	form_control * fptr;
	if (!( iptr ))
		return(0);
	else if (!(fptr = iptr->parent))
		return(0);
	else if ((iptr->Contents.style & _FRAME_TYPE) != _DATA_FRAME)
		return(0);
	else	{
		switch ((v = (iptr->Contents.align & 0x000F))) {
			case	_ADFILE_FRAME		:	/* 8 adfile		*/
			case	_SQFILE_FRAME		:	/* 6 sqfile		*/
			case	_DBFILE_FRAME		:	/* 7 dbfile		*/
			case	_SIFILE_FRAME		:	/* 3 sifile		*/
			case	_MCFILE_FRAME		:	/* 4 mcfile		*/
			case	_OCCI_FRAME		:	/* 10 OCCI  		*/
			case	_OCCI_MIRROR		:	/* 11 MIRROR		*/
			case	_PHP_REPLICATE		:
			case	_VMEMORY_FRAME		:
				return(v);
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
			case	_ADFILE_FRAME		:	/* 8 adfile		*/
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

public	int	generate_data_widget(
		struct file_control * optr, 
		struct form_control * fptr, 
		char * nptr, 
		struct form_item * iptr)
{
	char * yptr;
	struct  form_item * allocate_for_Widget();
	struct	form_item * wptr;
	if (!( fptr ))
		return( 118 );
	else if (!( iptr ))
		return( 118 );
	else if (!( wptr = allocate_for_Widget() ))
		return(27);
	else	{
		if (!( nptr )) 
			yptr = (char *) 0;
		else if (!( optr ))
			yptr = allocate_string( nptr );
		else if (!( yptr = allocate( strlen( nptr ) + strlen( optr->identity ) + 1 ) ))
			return( 27 );
		else	sprintf(yptr,"%s%s",optr->identity,nptr);

		wptr->Contents.x 	= iptr->Contents.x;
		wptr->Contents.y 	= iptr->Contents.y;
		wptr->Contents.w 	= iptr->Contents.w;
		wptr->Contents.h 	= iptr->Contents.h;
		wptr->Contents.font 	= iptr->Contents.font;
		wptr->Contents.colour	= iptr->Contents.colour;
		wptr->Contents.align 	= iptr->Contents.align;
		if ( iptr->Contents.stylesheet ) {
			if (!( wptr->Contents.stylesheet = allocate_string( iptr->Contents.stylesheet )))
				return(27);
			}
		switch ((wptr->Contents.style = iptr->Contents.style)) {
			case	_BUTTON_FRAME	:
			case	_CHECK_FRAME	:
			case	_RADIO_FRAME	:
				if (!( nptr ))
					break;
				if (!( wptr->Contents.payload = allocate_string( nptr )))
					return(27);
				else if (!( wptr->Contents.name = allocate_string( yptr )))
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
				else if ( *nptr == '_' )
					nptr++;
				if (!( wptr->Contents.payload = allocate_string( nptr )))
					return(27);
				else	break;

			case	_FORM_FRAME	:
			case	_EDIT_FRAME	:
			case	_SCROLL_FRAME	:
			case	_SWITCH_FRAME	:
				if (!( nptr ))
					break;
				if (!( wptr->Contents.name = allocate_string( yptr )))
					return(27);
				else	break;
			}
		reset_event_control(wptr->Contents.events,(wptr->Contents.style & _FRAME_TYPE));
		if ( iptr->Contents.events->on_create )
			wptr->Contents.events->on_create = allocate_string(iptr->Contents.events->on_create); 
		check_Widget( wptr );
		add_Widget(fptr,wptr,0);
		if ( yptr )
			liberate( yptr );
		return(0);
		}
		
}

private	struct	multi_lingual_message_list {
	char	*	msg[8];
	} MultiMessageList = { 
		(char *) 0,(char *) 0,(char *) 0,(char *) 0,
		(char *) 0,(char *) 0,(char *) 0,(char *) 0 
		};

private	struct	multi_lingual_message_list * multi_message_list( char * en, char * fr, char * it, char * es, char * de, char * nl, char * pt, char * xx )
{
	MultiMessageList.msg[0] = en;
	if (!( MultiMessageList.msg[1] = fr ))
		MultiMessageList.msg[1] = en;
	if (!( MultiMessageList.msg[2] = es ))
		MultiMessageList.msg[2] = en;
	if (!( MultiMessageList.msg[3] = de ))
		MultiMessageList.msg[3] = en;
	if (!( MultiMessageList.msg[4] = it ))
		MultiMessageList.msg[4] = en;
	if (!( MultiMessageList.msg[5] = nl ))
		MultiMessageList.msg[5] = en;
	if (!( MultiMessageList.msg[6] = pt ))
		MultiMessageList.msg[6] = en;
	if (!( MultiMessageList.msg[7] = xx ))
		MultiMessageList.msg[7] = en;
	return( &MultiMessageList );
}

private	struct	multi_lingual_message_list * multiple_messages( char * en )
{
	MultiMessageList.msg[0] = en;
	MultiMessageList.msg[1] = en;
	MultiMessageList.msg[2] = en;
	MultiMessageList.msg[3] = en;
	MultiMessageList.msg[4] = en;
	MultiMessageList.msg[5] = en;
	MultiMessageList.msg[6] = en;
	MultiMessageList.msg[7] = en;
	return( &MultiMessageList );
}

public	int	generate_multi_data_widget(
		struct file_control * optr, 
		struct form_control * fptr, 
		struct	multi_lingual_message_list * mptr,
		struct form_item * iptr)
{
	int	l;
	char *	nptr;
	struct	form_item * wptr;
	int	status;
	form_national_language(fptr,0);
	if ((status = generate_data_widget( optr, fptr, mptr->msg[0] , iptr )) != 0)
		return(status);
	else if (!( wptr = fptr->last ))
		return(118);
	else	{
		for (l=1; l < MAXNATLANG; l++ ) {
			if ((nptr = mptr->msg[l]) != (char *) 0) {
				form_national_language(fptr,l);
				wptr->Contents.payload = allocate_string( nptr );
				}
			}
		form_national_language(fptr,0);
		return(0);
		}
}

private	void	generate_multiple_payloads( struct form_control * fptr, struct form_item * iptr, char * vptr )
{
	int	l;
	for (l=0; l < MAXNATLANG; l++ ) {
		form_national_language(fptr,l);
		iptr->Contents.payload = allocate_string( vptr );
		}
	form_national_language(fptr,0);
	return;
}

private	int	data_pixel_width( struct data_control * dptr, int item, int fontwidth )
{
	int	dwidth;
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
			if (( dwidth = ((fontwidth * dptr->width[item] )+fontwidth)) > 400)
				return(400);
			else	return( dwidth );

		default			:
			return(0);
		}
}

private	char	*	generate_abal_load_action(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	char	*	rptr=(char *) 0;
	char	*	wptr=(char *) 0;
	char	*	nptr;
	char	work[MAXAEDBUFFERSIZE];
	int		f;
	int		first;
	for (first=0,f=0; f < dptr->indexfields; f++ ) {
		if (!(nptr = dptr->name[f+first] ))
			continue;
		else	{
			if ( dptr->type[f+first] == _ABAL_BCD )
			 	sprintf(work,"%s.%s = Fix(%s.value,%u);",optr->identity,nptr,nptr,dptr->decimal[f+first]);
			else if ( dptr->type[f+first] != _ABAL_STRING )
			 	sprintf(work,"%s.%s = %s.value;",optr->identity,nptr,nptr);
			else 	sprintf(work,"%s.%s = %s.buffer;",optr->identity,nptr,nptr);
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
	sprintf(work,"%s.Search();",optr->identity);
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
				sprintf(work,"%s.buffer = Print(($),Conv$(%s.%s));",nptr,optr->identity,nptr);
			else	sprintf(work,"%s.buffer = %s.%s;",nptr,optr->identity,nptr);
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

	sprintf(work,"OnShow();\n");
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

private	char	*	generate_js_load_action(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	char	*	rptr=(char *) 0;
	char	*	wptr=(char *) 0;
	char	*	nptr;
	char	work[MAXAEDBUFFERSIZE];
	int		f;
	int		first;
	for (first=0,f=0; f < dptr->indexfields; f++ ) {
		if (!(nptr = dptr->name[f+first] ))
			continue;
		else	{
			if ( dptr->type[f+first] == _ABAL_BCD )
			 	sprintf(work,"%s.%s = Math.round(%s.value);",optr->identity,nptr,nptr);
			else if ( dptr->type[f+first] != _ABAL_STRING )
			 	sprintf(work,"%s.%s = %s.value;",optr->identity,nptr,nptr);
			else 	sprintf(work,"%s.%s = %s.buffer;",optr->identity,nptr,nptr);
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
	sprintf(work,"%s.Search();",optr->identity);
	if (!( rptr ))
		rptr = allocate_string( work );
	else if (!( wptr = allocate( strlen(rptr) + strlen( work ) + 16 ) ))
		return(wptr);
	else	{
		sprintf(wptr,"%s\n%s",rptr,work);
		liberate( rptr );
		rptr = wptr;
		}
	for (first=0,f=0; f < dptr->datafields; f++ ) {
		if (!(nptr = dptr->name[f+first] ))
			continue;
		else	{
			if ( dptr->type[f+first] != _ABAL_STRING )
				sprintf(work,"%s.buffer = %s.%s.toString();",nptr,optr->identity,nptr);
			else	sprintf(work,"%s.buffer = %s.%s;",nptr,optr->identity,nptr);
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

	sprintf(work,"OnShow();\n");
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

private	char	*	generate_abal_up_action(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	char	*	rptr=(char *) 0;
	char	*	wptr=(char *) 0;
	char	*	nptr;
	char	work[MAXAEDBUFFERSIZE];
	int		f;
	int		first;
	for (first=0,f=0; f < dptr->indexfields; f++ ) {
		if (!(nptr = dptr->name[f+first] ))
			continue;
		else	{
			if ( dptr->type[f+first] == _ABAL_BCD )
			 	sprintf(work,"%s.%s = Fix(%s.value,%u);",optr->identity,nptr,nptr,dptr->decimal[f+first]);
			else if ( dptr->type[f+first] != _ABAL_STRING )
			 	sprintf(work,"%s.%s = %s.value;",optr->identity,nptr,nptr);
			else 	sprintf(work,"%s.%s = %s.buffer;",optr->identity,nptr,nptr);
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
	sprintf(work,"%s.Search();",optr->identity);
	if (!( rptr ))
		rptr = allocate_string( work );
	else if (!( wptr = allocate( strlen(rptr) + strlen( work ) + 16 ) ))
		return(wptr);
	else	{
		sprintf(wptr,"%s\n%s",rptr,work);
		liberate( rptr );
		rptr = wptr;
		}
	sprintf(work,"%s.Up();",optr->identity);
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
				sprintf(work,"%s.buffer = Print(($),Conv$(%s.%s));",nptr,optr->identity,nptr);
			else	sprintf(work,"%s.buffer = %s.%s;",nptr,optr->identity,nptr);
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
	sprintf(work,"%sLoad.Event();\n",optr->identity);
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

private	char	*	generate_js_up_action(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	char	*	rptr=(char *) 0;
	char	*	wptr=(char *) 0;
	char	*	nptr;
	char	work[MAXAEDBUFFERSIZE];
	int		f;
	int		first;
	for (first=0,f=0; f < dptr->indexfields; f++ ) {
		if (!(nptr = dptr->name[f+first] ))
			continue;
		else	{
			if ( dptr->type[f+first] == _ABAL_BCD )
			 	sprintf(work,"%s.%s = Math.round(%s.value);",optr->identity,nptr,nptr);
			else if ( dptr->type[f+first] != _ABAL_STRING )
			 	sprintf(work,"%s.%s = %s.value;",optr->identity,nptr,nptr);
			else 	sprintf(work,"%s.%s = %s.buffer;",optr->identity,nptr,nptr);
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
	sprintf(work,"%s.Search();",optr->identity);
	if (!( rptr ))
		rptr = allocate_string( work );
	else if (!( wptr = allocate( strlen(rptr) + strlen( work ) + 16 ) ))
		return(wptr);
	else	{
		sprintf(wptr,"%s\n%s",rptr,work);
		liberate( rptr );
		rptr = wptr;
		}
	sprintf(work,"%s.Up();",optr->identity);
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
				sprintf(work,"%s.buffer = %s.%s.toString();",nptr,optr->identity,nptr);
			else	sprintf(work,"%s.buffer = %s.%s;",nptr,optr->identity,nptr);
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
	sprintf(work,"%sLoad.Event();\n",optr->identity);
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

private	char 	*	activate_load_action(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	char	*	rptr=(char *) 0;
	char		work[MAXAEDBUFFERSIZE];
	sprintf(work,"%sLoad.Event();\n",optr->identity);
	return( allocate_string( work ) );
}

	
private	char	* 	generate_abal_down_action(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	char	*	rptr=(char *) 0;
	char	*	wptr=(char *) 0;
	char	*	nptr;
	char	work[MAXAEDBUFFERSIZE];
	int		f;
	int		first;
	for (first=0,f=0; f < dptr->indexfields; f++ ) {
		if (!(nptr = dptr->name[f+first] ))
			continue;
		else	{
			if ( dptr->type[f+first] == _ABAL_BCD )
			 	sprintf(work,"%s.%s = Fix(%s.value,%u);",optr->identity,nptr,nptr,dptr->decimal[f+first]);
			else if ( dptr->type[f+first] != _ABAL_STRING )
			 	sprintf(work,"%s.%s = %s.value;",optr->identity,nptr,nptr);
			else 	sprintf(work,"%s.%s = %s.buffer;",optr->identity,nptr,nptr);
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
	sprintf(work,"%s.Search();",optr->identity);
	if (!( rptr ))
		rptr = allocate_string( work );
	else if (!( wptr = allocate( strlen(rptr) + strlen( work ) + 16 ) ))
		return(wptr);
	else	{
		sprintf(wptr,"%s\n%s",rptr,work);
		liberate( rptr );
		rptr = wptr;
		}
	sprintf(work,"%s.Down();",optr->identity);
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
				sprintf(work,"%s.buffer = Print(($),Conv$(%s.%s));",nptr,optr->identity,nptr);
			else	sprintf(work,"%s.buffer = %s.%s;",nptr,optr->identity,nptr);
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
	sprintf(work,"%sLoad.Event();\n",optr->identity);
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

private	char	* 	generate_js_down_action(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	char	*	rptr=(char *) 0;
	char	*	wptr=(char *) 0;
	char	*	nptr;
	char	work[MAXAEDBUFFERSIZE];
	int		f;
	int		first;
	for (first=0,f=0; f < dptr->indexfields; f++ ) {
		if (!(nptr = dptr->name[f+first] ))
			continue;
		else	{
			if ( dptr->type[f+first] == _ABAL_BCD )
			 	sprintf(work,"%s.%s = Math.round(%s.buffer);",optr->identity,nptr,nptr);
			else if ( dptr->type[f+first] != _ABAL_STRING )
			 	sprintf(work,"%s.%s = %s.value;",optr->identity,nptr,nptr);
			else 	sprintf(work,"%s.%s = %s.buffer;",optr->identity,nptr,nptr);
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
	sprintf(work,"%s.Search();",optr->identity);
	if (!( rptr ))
		rptr = allocate_string( work );
	else if (!( wptr = allocate( strlen(rptr) + strlen( work ) + 16 ) ))
		return(wptr);
	else	{
		sprintf(wptr,"%s\n%s",rptr,work);
		liberate( rptr );
		rptr = wptr;
		}
	sprintf(work,"%s.Down();",optr->identity);
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
				sprintf(work,"%s.buffer = %s.%s.toString();",nptr,optr->identity,nptr);
			else	sprintf(work,"%s.buffer = %s.%s;",nptr,optr->identity,nptr);
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
	sprintf(work,"%sLoad.Event();\n",optr->identity);
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

private	char	*	generate_abal_delete_action(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	char	*	rptr=(char *) 0;
	char	*	wptr=(char *) 0;
	char	*	nptr;
	char	work[MAXAEDBUFFERSIZE];
	int		f;
	int		first;
	for (first=0,f=0; f < dptr->indexfields; f++ ) {
		if (!(nptr = dptr->name[f+first] ))
			continue;
		else	{
			if ( dptr->type[f+first] == _ABAL_BCD )
			 	sprintf(work,"%s.%s = Fix(%s.value,%u);",optr->identity,nptr,nptr,dptr->decimal[f+first]);
			else if ( dptr->type[f+first] != _ABAL_STRING )
			 	sprintf(work,"%s.%s = %s.value;",optr->identity,nptr,nptr);
			else 	sprintf(work,"%s.%s = %s.buffer;",optr->identity,nptr,nptr);
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
	sprintf(work,"%s.Delete();",optr->identity);
	if (!( rptr ))
		rptr = allocate_string( work );
	else if (!( wptr = allocate( strlen(rptr) + strlen( work ) + 16 ) ))
		return(wptr);
	else	{
		sprintf(wptr,"%s\n%s",rptr,work);
		liberate( rptr );
		rptr = wptr;
		}
	sprintf(work,"%sLoad.Event();\n",optr->identity);
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

private	char	*	generate_js_delete_action(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	char	*	rptr=(char *) 0;
	char	*	wptr=(char *) 0;
	char	*	nptr;
	char	work[MAXAEDBUFFERSIZE];
	int		f;
	int		first;
	for (first=0,f=0; f < dptr->indexfields; f++ ) {
		if (!(nptr = dptr->name[f+first] ))
			continue;
		else	{
			if ( dptr->type[f+first] == _ABAL_BCD )
			 	sprintf(work,"%s.%s = Math.round(%s.value);",optr->identity,nptr,nptr);
			else if ( dptr->type[f+first] != _ABAL_STRING )
			 	sprintf(work,"%s.%s = %s.value;",optr->identity,nptr,nptr);
			else 	sprintf(work,"%s.%s = %s.buffer;",optr->identity,nptr,nptr);
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
	sprintf(work,"%s.Delete();",optr->identity);
	if (!( rptr ))
		rptr = allocate_string( work );
	else if (!( wptr = allocate( strlen(rptr) + strlen( work ) + 16 ) ))
		return(wptr);
	else	{
		sprintf(wptr,"%s\n%s",rptr,work);
		liberate( rptr );
		rptr = wptr;
		}
	sprintf(work,"%sLoad.Event();\n",optr->identity);
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

private	char	*	generate_abal_save_action(
struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	char	*	rptr=(char *) 0;
	char	*	wptr=(char *) 0;
	char	work[MAXAEDBUFFERSIZE];
	int		f;
	char	*	nptr;
	int		first;
	for (first=0,f=0; f < dptr->indexfields; f++ ) {
		if (!(nptr = dptr->name[f+first] ))
			continue;
		else	{
			if ( dptr->type[f+first] == _ABAL_BCD )
			 	sprintf(work,"%s.%s = Fix(%s.value,%u);",optr->identity,nptr,nptr,dptr->decimal[f+first]);
			else if ( dptr->type[f+first] != _ABAL_STRING )
			 	sprintf(work,"%s.%s = %s.value;",optr->identity,nptr,nptr);
			else 	sprintf(work,"%s.%s = %s.buffer;",optr->identity,nptr,nptr);
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
			 	sprintf(work,"%s.%s = Fix(%s.value,%u);",optr->identity,nptr,nptr,dptr->decimal[f+first]);
			else if ( dptr->type[f+first] != _ABAL_STRING )
			 	sprintf(work,"%s.%s = %s.value;",optr->identity,nptr,nptr);
			else 	sprintf(work,"%s.%s = %s.buffer;",optr->identity,nptr,nptr);
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

	sprintf(work,"%s.Update();\n",optr->identity);
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

private	char	*	generate_js_save_action(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	char	*	rptr=(char *) 0;
	char	*	wptr=(char *) 0;
	char	work[MAXAEDBUFFERSIZE];
	int		f;
	char	*	nptr;
	int		first;
	for (first=0,f=0; f < dptr->indexfields; f++ ) {
		if (!(nptr = dptr->name[f+first] ))
			continue;
		else	{
			if ( dptr->type[f+first] == _ABAL_BCD )
			 	sprintf(work,"%s.%s = Math.round(%s.value);",optr->identity,nptr,nptr);
			else if ( dptr->type[f+first] != _ABAL_STRING )
			 	sprintf(work,"%s.%s = %s.value;",optr->identity,nptr,nptr);
			else 	sprintf(work,"%s.%s = %s.buffer;",optr->identity,nptr,nptr);
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
			 	sprintf(work,"%s.%s = Math.round(%s.value);",optr->identity,nptr,nptr);
			else if ( dptr->type[f+first] != _ABAL_STRING )
			 	sprintf(work,"%s.%s = %s.value;",optr->identity,nptr,nptr);
			else 	sprintf(work,"%s.%s = %s.buffer;",optr->identity,nptr,nptr);
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

	sprintf(work,"%s.Update();\n",optr->identity);
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

private char *	generate_up_action(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	switch( get_data_production_language() )
	{
	case	_GENERATE_PHP	:
	case	_GENERATE_BAL	:
	case	_GENERATE_ABAL	:
		return( generate_abal_up_action( iptr, dptr, optr ) );
	case	_GENERATE_LASER	:
	case	_GENERATE_BIFS 	:
		return( generate_js_up_action( iptr, dptr, optr ) );
	case	_GENERATE_C	:
	case	_GENERATE_CPP 	:
	default				:
		return(allocate_string(" "));
	}
}

private char *	generate_load_action(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	switch( get_data_production_language() )
	{
	case	_GENERATE_PHP	:
	case	_GENERATE_BAL	:
	case	_GENERATE_ABAL	:
		return( generate_abal_load_action( iptr, dptr, optr ) );
	case	_GENERATE_LASER	:
	case	_GENERATE_BIFS 	:
		return( generate_js_load_action( iptr, dptr, optr ) );
	case	_GENERATE_C	:
	case	_GENERATE_CPP 	:
	default				:
		return(allocate_string(" "));
	}
}

private char *	generate_delete_action(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	switch( get_data_production_language() )
	{
	case	_GENERATE_PHP	:
	case	_GENERATE_BAL	:
	case	_GENERATE_ABAL	:
		return( generate_abal_delete_action( iptr, dptr, optr ) );
	case	_GENERATE_LASER	:
	case	_GENERATE_BIFS 	:
		return( generate_js_delete_action( iptr, dptr, optr ) );
	case	_GENERATE_C	:
	case	_GENERATE_CPP 	:
	default				:
		return(allocate_string(" "));
	}
}

private char *	generate_save_action(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	switch( get_data_production_language() )
	{
	case	_GENERATE_PHP	:
	case	_GENERATE_BAL	:
	case	_GENERATE_ABAL	:
		return( generate_abal_save_action( iptr, dptr, optr ) );
	case	_GENERATE_LASER	:
	case	_GENERATE_BIFS 	:
		return( generate_js_save_action( iptr, dptr, optr ) );
	case	_GENERATE_C	:
	case	_GENERATE_CPP 	:
	default				:
		return(allocate_string(" "));
	}
}

private char *	generate_down_action(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	switch( get_data_production_language() )
	{
	case	_GENERATE_PHP	:
	case	_GENERATE_BAL	:
	case	_GENERATE_ABAL	:
		return( generate_abal_down_action( iptr, dptr, optr ) );
	case	_GENERATE_LASER	:
	case	_GENERATE_BIFS 	:
		return( generate_js_down_action( iptr, dptr, optr ) );
	case	_GENERATE_C	:
	case	_GENERATE_CPP 	:
	default				:
		return(allocate_string(" "));
	}
}

private	char	*	join_text( char * lptr, char * rptr)
{
	char	*	wptr;
	if (!( rptr ))
		return( lptr );
	else if (!( lptr ))
		return( allocate_string( rptr ) );
	else if (!( wptr = allocate( strlen(lptr) + strlen( rptr ) + 8 ) ))
		return( wptr );
	else 	{
		sprintf(wptr,"%s%s",lptr,rptr);
		liberate( lptr );
		return( wptr );
		}
}

private	char	*	generate_abal_list_show(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	char	*	label=(char *) 0;
	int		item=0;
	char	*	wptr=(char *) 0;
	char		wbuffer[MAXAEDBUFFERSIZE];
	sprintf(wbuffer,"\tDcl l%c,n%c\n",0x0025,0x0025);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\tthis.buffer = %c %c\n",__QUOTE,__QUOTE);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\tif ( Len$(%s.Question) = 0)\n",optr->identity);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );

	if ((label = extract_db_filename(iptr->Contents.payload,0)) != (char *) 0) {
		sprintf(wbuffer,"\t\t%s.Question = %c%s > ' '%c\n",optr->identity,__QUOTE,label,__QUOTE);
			if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
		sprintf(wbuffer,"\t\t%s.Collect()\n",optr->identity);
			if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
		}

	sprintf(wbuffer,"\tEndif\n",optr->identity);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );


	sprintf(wbuffer,"\tFor l = 1 to this.lines\n");
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\tn = l + %sVSB.value\n",optr->identity);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\t%s.Locate(n)\n",optr->identity);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\tif ( %s.Error = 0)\n",optr->identity);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );

	sprintf(wbuffer,"\t\t\tthis.line(l)\n");
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );

	while ((label = extract_db_filename(iptr->Contents.payload,item++)) != (char *) 0) {
		sprintf(wbuffer,"\t\t\tthis.column(%u) = %s.%s\n",item,optr->identity,label);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
		}

	sprintf(wbuffer,"\t\tEndif\n",optr->identity);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\tNext l\n");
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\tthis.OnShow()\n");
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );

	/* ---------------------------------- */
	/* table cursor not generated for PHP */
	/* ---------------------------------- */
	switch( get_data_production_language() )
	{
	case	_GENERATE_PHP	:
		break;
	default			:
		sprintf(wbuffer,"\t%sCursor.x = this.x\n",optr->identity);
			if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
		sprintf(wbuffer,"\t%sCursor.w = this.w\n",optr->identity);
			if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
		sprintf(wbuffer,"\t%sCursor.y = (this.y+(this.line*this.fontheight))\n",optr->identity);
			if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
		sprintf(wbuffer,"\t%sCursor.h = this.fontheight\n",optr->identity);
			if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
		sprintf(wbuffer,"\t%sCursor.OnShow()\n",optr->identity);
			if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	}
	return( wptr );
}

private	char	*	generate_js_list_show(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	char	*	label=(char *) 0;
	int		item=0;
	char	*	wptr=(char *) 0;
	char		wbuffer[MAXAEDBUFFERSIZE];
	sprintf(wbuffer,"\tvar l=0;\n\tvar n=0;\n");
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\tthis.buffer = %c %c;\n",__QUOTE,__QUOTE);
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\tif ( %s.Question.length == 0) {\n",optr->identity);
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );

	if ((label = extract_db_filename(iptr->Contents.payload,0)) != (char *) 0) {
		sprintf(wbuffer,"\t\t%s.Question = %c%s > ' '%c;\n",optr->identity,__QUOTE,label,__QUOTE);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
		sprintf(wbuffer,"\t\t%s.Collect();\n",optr->identity);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
		}

	sprintf(wbuffer,"\t}\n",optr->identity);
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );

	sprintf(wbuffer,"\tfor (l=1; l <= this.lines; l++) {\n");
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );

	sprintf(wbuffer,"\t\tn = l + Math.round(%sVSB.value);\n",optr->identity);
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );

	sprintf(wbuffer,"\t\t\tthis.line(l);\n");
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );

	sprintf(wbuffer,"\t\tif ( n <= %s.Response) {\n",optr->identity);
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );

	sprintf(wbuffer,"\t\t%s.Locate(n);\n",optr->identity);
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );

	sprintf(wbuffer,"\t\tif ( %s.Error == 0) {\n",optr->identity);
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );

	while ((label = extract_db_filename(iptr->Contents.payload,item++)) != (char *) 0) {
		sprintf(wbuffer,"\t\t\tthis.column(%u) = %s.%s;\n",item,optr->identity,label);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
		}
	sprintf(wbuffer,"\t\t} else { \n",optr->identity);
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );

	item=0;

	while ((label = extract_db_filename(iptr->Contents.payload,item++)) != (char *) 0) {
		sprintf(wbuffer,"\t\t\tthis.column(%u) = %c %c;\n",item,0x0022,0x0022);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
		}

	sprintf(wbuffer,"\t\t}\n",optr->identity);
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );

	sprintf(wbuffer,"\t\t} else { \n",optr->identity);
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );

	item=0;
	while ((label = extract_db_filename(iptr->Contents.payload,item++)) != (char *) 0) {
		sprintf(wbuffer,"\t\t\tthis.column(%u) = %c %c;\n",item,0x0022,0x0022);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
		}
	sprintf(wbuffer,"\t\t}\n",optr->identity);
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );

	sprintf(wbuffer,"\t}\n");
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );

	sprintf(wbuffer,"\tthis.OnShow();\n");
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );

	return( wptr );
}

private	char	*	generate_c_list_show(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	char	*	label=(char *) 0;
	int		item=0;
	char	*	wptr=(char *) 0;
	char		wbuffer[MAXAEDBUFFERSIZE];
	sprintf(wbuffer,"\tint l=0;\n\t int n=0;\n");
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\tthis.buffer = %c %c;\n",__QUOTE,__QUOTE);
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\tif ( strlen(%s.Question) == 0) {\n",optr->identity);
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );

	if ((label = extract_db_filename(iptr->Contents.payload,0)) != (char *) 0) {
		sprintf(wbuffer,"\t\t%s.Question = %c%s > ' '%c;\n",optr->identity,__QUOTE,label,__QUOTE);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
		sprintf(wbuffer,"\t\t%s.Collect();\n",optr->identity);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
		}

	sprintf(wbuffer,"\t}\n",optr->identity);
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );

	sprintf(wbuffer,"\tfor (l=1; l <= this.lines; l++) {\n");
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\tn = (l + %sVSB.value);\n",optr->identity);
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\t%s.Locate(n);\n",optr->identity);
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\tif ( %s.Error == 0) {\n",optr->identity);
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );

	sprintf(wbuffer,"\t\t\tthis.line(l);\n");
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );

	while ((label = extract_db_filename(iptr->Contents.payload,item++)) != (char *) 0) {
		sprintf(wbuffer,"\t\t\tthis.column(%u) = %s.%s;\n",item,optr->identity,label);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
		}

	sprintf(wbuffer,"\t\t}\n",optr->identity);
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t}\n");
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\tthis.OnShow();\n");
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	return( wptr );
}

private	char	*	generate_list_show(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	switch( get_data_production_language() )
	{
	case	_GENERATE_PHP	:
	case	_GENERATE_BAL	:
	case	_GENERATE_ABAL	:
		return( generate_abal_list_show( iptr, dptr, optr ) );
	case	_GENERATE_LASER	:
	case	_GENERATE_BIFS 	:
		return( generate_js_list_show( iptr, dptr, optr ) );
	case	_GENERATE_C	:
	case	_GENERATE_CPP 	:
		return( generate_c_list_show( iptr, dptr, optr ) );
	default				:
		return(allocate_string(" "));
	}
}

private	char	*	generate_abal_list_event(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	int		f;
	char	*	nptr;
	int		item=0;
	char 	*	label=(char *) 0;
	char	*	wptr=(char *) 0;
	char		wbuffer[MAXAEDBUFFERSIZE];
	sprintf(wbuffer,"\tDcl l%c,n%c\n",0x0025,0x0025);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\tl = this.line\n");
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\tif ( l > 0 )\n");
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\tthis.Show\n");
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\tn = l + %sVSB.value\n",optr->identity);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\t%s.Locate(n)\n",optr->identity);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\tif ( %s.Error = 0)\n",optr->identity);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );

	/* scan index tables and affect interface edit fields */
	for (f=0; f < dptr->indexfields; f++ ) {
		if (!( nptr = dptr->name[f] ))
			continue;
		if ( dptr->type[f] != _ABAL_STRING ) {
			sprintf(wbuffer,"\t\t\t%s%s.buffer = Print(($),Conv$(%s.%s))\n",
				optr->identity, nptr, optr->identity,nptr);
			}
		else	{
			sprintf(wbuffer,"\t\t\t%s%s.buffer = %s.%s\n",
				optr->identity, nptr, optr->identity,nptr);
			}
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
		}

	sprintf(wbuffer,"\t\t\tExit(13)\n");
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );

	sprintf(wbuffer,"\t\tEndif\n");
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\tElse\n");
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\tSelect this.column\n");
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );

	item = 0;
	while ((label = extract_db_filename(iptr->Contents.payload,item++)) != (char *) 0) {
		sprintf(wbuffer,"\t\tCase %u :: %s.Question = %c%s > ' '%c\n",
			item,	optr->identity,__QUOTE,label,__QUOTE);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
		}

	sprintf(wbuffer,"\t\tEndSel\n");
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\tif ( %s.Direction <> this.column )\n",optr->identity);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\t\t%s.Direction = this.column\n",optr->identity);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\t\t%s.Collect()\n",optr->identity);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\tElse\n");
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\t\t%s.Direction = 0\n",optr->identity);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\t\t%s.Collect.D()\n",optr->identity);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\tEndif\n");
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\tthis.Show()\n");
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\t%sVSB.Show()\n",optr->identity);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\tEndif\n");
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	return( wptr );
}

private	char	*	generate_js_list_event(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	char 	*	prefix="\0";
	int		f;
	char	*	nptr;
	int		item=0;
	char 	*	label=(char *) 0;
	char	*	wptr=(char *) 0;
	char		wbuffer[MAXAEDBUFFERSIZE];
	sprintf(wbuffer,"\tvar l=0;\n\tvar n=0;\n");
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\tl = Number(this.line);\n");
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\tif ( l > 0 ) {\n");
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\tthis.Show();\n");
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\tn = l + Math.round(%sVSB.value);\n",optr->identity);
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\t%s.Locate(n);\n",optr->identity);
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\tif ( %s.Error == 0){\n",optr->identity);
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );

	/* scan index tables and affect interface edit fields */
	for (f=0; f < dptr->indexfields; f++ ) {
		if (!( nptr = dptr->name[f] ))
			continue;
		else	{
			sprintf(wbuffer,"\t\t\t%s%s.buffer = %s.%s;\n",
				optr->identity, nptr, optr->identity,nptr);
			}
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
		}

	sprintf(wbuffer,"\t\t\treturn(13);\n");
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );

	sprintf(wbuffer,"\t\t}\n");
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t} else {\n");
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );

	item = 0;
	while ((label = extract_db_filename(iptr->Contents.payload,item++)) != (char *) 0) {
		if ( item > 1 )
			prefix = "else ";
		else	prefix = "\0";
		sprintf(wbuffer,"\t\t%sif ( Number(this.column) == %u ) %s.Question = %c%s > ' '%c;\n",
			prefix, item,	optr->identity,__QUOTE,label,__QUOTE);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
		}

	sprintf(wbuffer,"\t\tif ( %s.Direction != this.column ) {\n",optr->identity);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\t\t%s.Direction = this.column;\n",optr->identity);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\t\t%s.Collect();\n",optr->identity);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\t} else {\n");
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\t\t%s.Direction = 0;\n",optr->identity);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\t\t%s.Collect();\n",optr->identity);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\t}\n");
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\tthis.Show();\n");
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\t%sVSB.Show();\n",optr->identity);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t}\n");
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	return( wptr );
}

private	char	*	generate_c_list_event(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	char 	*	prefix="\0";
	int		f;
	char	*	nptr;
	int		item=0;
	char 	*	label=(char *) 0;
	char	*	wptr=(char *) 0;
	char		wbuffer[MAXAEDBUFFERSIZE];
	sprintf(wbuffer,"\tint l=0;\n\tint n=0;\n");
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\tl = this.line;\n");
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\tif ( l > 0 ) {\n");
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\tthis.Show();\n");
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\tn = ( l + %sVSB.value );\n",optr->identity);
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\t%s.Locate(n);\n",optr->identity);
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\tif ( %s.Error == 0){\n",optr->identity);
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );

	/* scan index tables and affect interface edit fields */
	for (f=0; f < dptr->indexfields; f++ ) {
		if (!( nptr = dptr->name[f] ))
			continue;
		else	{
			sprintf(wbuffer,"\t\t\t%s%s.buffer = %s.%s;\n",
				optr->identity, nptr, optr->identity,nptr);
			}
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
		}

	sprintf(wbuffer,"\t\t\treturn(13);\n");
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );

	sprintf(wbuffer,"\t\t}\n");
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t} else {\n");
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );

	item = 0;
	while ((label = extract_db_filename(iptr->Contents.payload,item++)) != (char *) 0) {
		if ( item )
			prefix = "else ";
		else	prefix = "\0";
		sprintf(wbuffer,"\t\t%sif ( this.coloumn == %u ) %s.Question = %c%s > ' '%c;\n",
			prefix, item,	optr->identity,__QUOTE,label,__QUOTE);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
		}

	sprintf(wbuffer,"\t\tif ( %s.Direction != this.column ) {\n",optr->identity);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\t\t%s.Direction = this.column;\n",optr->identity);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\t\t%s.Collect();\n",optr->identity);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\t} else {\n");
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\t\t%s.Direction = 0;\n",optr->identity);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\t\t%s.Collect();\n",optr->identity);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\t}\n");
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\tthis.Show();\n");
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t\t%sVSB.Show();\n",optr->identity);
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\t}\n");
		if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	return( wptr );
}

private	char	*	generate_list_event(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	switch( get_data_production_language() )
	{
	case	_GENERATE_PHP	:
	case	_GENERATE_BAL	:
	case	_GENERATE_ABAL	:
		return( generate_abal_list_event( iptr, dptr, optr ) );
	case	_GENERATE_LASER	:
	case	_GENERATE_BIFS 	:
		return( generate_js_list_event( iptr, dptr, optr ) );
	case	_GENERATE_C	:
	case	_GENERATE_CPP 	:
		return( generate_c_list_event( iptr, dptr, optr ) );
	default				:
		return(allocate_string(" "));
	}
}


private	char	*	generate_scroll_create(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	char	*	wptr=(char *) 0;
	char		wbuffer[MAXAEDBUFFERSIZE];
	sprintf(wbuffer,"\tthis.value=0\n");
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\tthis.limit = %sFileList.lines\n",optr->identity);
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\tthis.max = this.value\n");
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	return( wptr );
}

private	char	*	generate_abal_scroll_event(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	char	*	wptr=(char *) 0;
	char		wbuffer[MAXAEDBUFFERSIZE];
	sprintf(wbuffer,"\t%sFileList.Show()\n",optr->identity);
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	return( wptr );
}

private	char	*	generate_js_scroll_event(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	char	*	wptr=(char *) 0;
	char		wbuffer[MAXAEDBUFFERSIZE];
	sprintf(wbuffer,"\t%sFileList.Show();\n",optr->identity);
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	return( wptr );
}

private	char	*	generate_c_scroll_event(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	char	*	wptr=(char *) 0;
	char		wbuffer[MAXAEDBUFFERSIZE];
	sprintf(wbuffer,"\t%sFileList.Show();\n",optr->identity);
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	return( wptr );
}

private	char	*	generate_scroll_event(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	switch( get_data_production_language() )
	{
	case	_GENERATE_PHP	:
	case	_GENERATE_BAL	:
	case	_GENERATE_ABAL	:
		return( generate_abal_scroll_event( iptr, dptr, optr ) );
	case	_GENERATE_LASER	:
	case	_GENERATE_BIFS 	:
		return( generate_js_scroll_event( iptr, dptr, optr ) );
	case	_GENERATE_C	:
	case	_GENERATE_CPP 	:
		return( generate_c_scroll_event( iptr, dptr, optr ) );
	default				:
		return(allocate_string(" "));
	}
}


private	char	*	generate_abal_scroll_show(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	char	*	wptr=(char *) 0;
	char		wbuffer[MAXAEDBUFFERSIZE];
	sprintf(wbuffer,"\tthis.max = %s.Response\n",optr->identity);
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\tif ( this.max < this.limit ) :: this.max = this.limit :: Endif\n");
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\tthis.OnShow()\n");
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	return( wptr );
}

private	char	*	generate_js_scroll_show(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	char	*	wptr=(char *) 0;
	char		wbuffer[MAXAEDBUFFERSIZE];
	sprintf(wbuffer,"\tthis.max = %s.Response;\n",optr->identity);
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\tif ( this.max < this.limit ) { this.max = this.limit; }\n");
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\tthis.OnShow();\n");
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	return( wptr );
}

private	char	*	generate_c_scroll_show(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	char	*	wptr=(char *) 0;
	char		wbuffer[MAXAEDBUFFERSIZE];
	sprintf(wbuffer,"\tthis.max = %s.Response;\n",optr->identity);
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\tif ( this.max < this.limit ) { this.max = this.limit; }\n");
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	sprintf(wbuffer,"\tthis.OnShow();\n");
	if (!( wptr = join_text(wptr,wbuffer) )) return( wptr );
	return( wptr );
}

private	char	*	generate_scroll_show(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	switch( get_data_production_language() )
	{
	case	_GENERATE_PHP	:
	case	_GENERATE_BAL	:
	case	_GENERATE_ABAL	:
		return( generate_abal_scroll_show( iptr, dptr, optr ) );
	case	_GENERATE_LASER	:
	case	_GENERATE_BIFS 	:
		return( generate_js_scroll_show( iptr, dptr, optr ) );
	case	_GENERATE_C	:
	case	_GENERATE_CPP 	:
		return( generate_c_scroll_show( iptr, dptr, optr ) );
	default				:
		return(allocate_string(" "));
	}
}

private	char	*	generate_accept_action(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	switch( get_data_production_language() )
	{
	case	_GENERATE_PHP	:
	case	_GENERATE_BAL	:
	case	_GENERATE_ABAL	:
		return( allocate_string( "Exit(13);" ) );
	case	_GENERATE_LASER	:
	case	_GENERATE_BIFS 	:
	case	_GENERATE_C	:
	case	_GENERATE_CPP 	:
		return( allocate_string( "return(13);" ) );
	default				:
		return(allocate_string(" "));
	}
}

private	char	*	generate_abort_action(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	switch( get_data_production_language() )
	{
	case	_GENERATE_PHP	:
	case	_GENERATE_BAL	:
	case	_GENERATE_ABAL	:
		return( allocate_string( "Exit(27);" ) );
	case	_GENERATE_LASER	:
	case	_GENERATE_BIFS 	:
	case	_GENERATE_C	:
	case	_GENERATE_CPP 	:
		return( allocate_string( "return(27);" ) );
	default				:
		return(allocate_string(" "));
	}
}

private	char	*	generate_create_action(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	char	*	wptr=(char *) 0;
	char		wbuffer[MAXAEDBUFFERSIZE];
	sprintf(wbuffer,"\t%s.OnCreate();\n",optr->identity);
	if (!( wptr = join_text(wptr,wbuffer) )) 
		return( wptr );
	else	return( wptr );
}

private	char	*	generate_export_action(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	char	*	wptr=(char *) 0;
	char		wbuffer[MAXAEDBUFFERSIZE];
	sprintf(wbuffer,"\t{ %s.OnExport(.buffer); }\n",optr->identity);
	if (!( wptr = join_text(wptr,wbuffer) )) 
		return( wptr );
	else	return( wptr );
}

private	char	*	generate_import_action(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	char	*	wptr=(char *) 0;
	char		wbuffer[MAXAEDBUFFERSIZE];
	sprintf(wbuffer,"\t{ %s.OnImport(.buffer); }\n",optr->identity);
	if (!( wptr = join_text(wptr,wbuffer) )) 
		return( wptr );
	else	return( wptr );
}

private	char	*	generate_remove_action(struct form_item * iptr, struct data_control * dptr, struct file_control * optr)
{
	char	*	wptr=(char *) 0;
	char		wbuffer[MAXAEDBUFFERSIZE];
	sprintf(wbuffer,"\t%s.OnRemove();\n",optr->identity);
	if (!( wptr = join_text(wptr,wbuffer) )) 
		return( wptr );
	else	return( wptr );
}

private	int	generate_widget_action(struct form_item * iptr, struct data_control * dptr, int action, struct file_control * optr )
{
	char *	aptr;
	if (!( iptr ))
		return(0);
	switch ((action & 0x00FF)) {
		case	1  : aptr = generate_accept_action(iptr,dptr,optr);	break;
		case	2  : aptr = generate_up_action(iptr,dptr,optr); 	break;
		case	3  : aptr = generate_load_action(iptr,dptr,optr); 	break;
		case	4  : aptr = generate_delete_action(iptr,dptr,optr); 	break;
		case	5  : aptr = generate_save_action(iptr,dptr,optr);	break;
		case	6  : aptr = generate_down_action(iptr,dptr,optr); 	break;
		case	7  : aptr = generate_abort_action(iptr,dptr,optr);	break;
		case	8  : aptr = activate_load_action(iptr,dptr,optr);	break;
		case	9  : aptr = generate_list_show(iptr, dptr, optr);	break;
		case	10 : aptr = generate_list_event(iptr, dptr, optr);	break;
		case	11 : aptr = generate_scroll_create(iptr, dptr, optr);	break;
		case	12 : aptr = generate_scroll_event(iptr, dptr, optr);	break;
		case	13 : aptr = generate_scroll_show(iptr, dptr, optr);	break;
		case	14 : aptr = generate_create_action(iptr, dptr, optr);	break;
		case	15 : aptr = generate_remove_action(iptr, dptr, optr);	break;
		case	16 : aptr = generate_export_action(iptr, dptr, optr);	break;
		case	17 : aptr = generate_import_action(iptr, dptr, optr);	break;
		default	   : return(0);
		}
	switch ( (action & 0x0F00) >> 8) {
		case	1 :
			if (!(iptr->Contents.events->on_create= allocate_string(aptr)))
				return(27);
			else	break;

		case	2 :
			if (!(iptr->Contents.events->on_show  = allocate_string(aptr)))
				return(27);
			else	break;

		case	3 :
			if (!(iptr->Contents.events->on_get_focus = allocate_string(aptr)))
				return(27);
			else	break;

		case	0 :
		case	4 :
			if (!(iptr->Contents.events->on_event = allocate_string(aptr)))
				return(27);
			else	break;

		case	5 :
			if (!(iptr->Contents.events->on_lose_focus = allocate_string(aptr)))
				return(27);
			else	break;

		case	6 :
			if (!(iptr->Contents.events->on_lose_focus = allocate_string(aptr)))
				return(27);
			else	break;

		case	7 :
			if (!(iptr->Contents.events->on_lose_focus = allocate_string(aptr)))
				return(27);
			else	break;
		}

	switch ((action & 0x00FF)) {
		case	 1 :
		case	 3 :
		case	 5 :
		case	 7 :
		case	 9 :
		case	10 :
		case	11 :
		case	12 :
		case	13 :
		case	14 :
		case	15 :
		case	16 :
		case	17 :
			 liberate( aptr );
		}
	return(0);
}


private	void	terminate_data_form( struct form_control * fptr )
{
	/* Calculate max label and max field */
	/* --------------------------------- */
	fptr->gridlock	= fptr->gridsize  = 0x0505;

	calculate_form_triggers( fptr );

	/* Generate XML */
	/* ------------ */
	save_Form(fptr,QUICK,(char *)0);

	new_CameraItem(Context.Camera,  __3D_FORM, fptr->loadname);

	/* Drop Form */
	/* --------- */
	remove_Form( fptr );

	liberate( fptr );

	return;
}

private	struct	data_form_control	{
	struct	form_item  	template;
	struct	form_item  	editlate;
	struct	form_item  	formlate;
	struct	form_item  	filelate;
	struct	form_item  	pagelate;
	struct	form_item	cursor;
	int	totlabel;
	int	totwidth;
	int	maxwidth;
	int	butwidth;
	int	maxlabel;
	int	maxitems;
	} DFC;

struct	generator_control
{
	int	font;
	int	height;
	int	width;
	int	align;
	int	colour;
	int	interline;
	char *	style;
};


private	struct	generator_control Label =  
{ 
	2,
	16,
	10,
	0x0501, 
	0x010,
	20,
	"editlabel" 
};

private	struct	generator_control	Edit  = 
{ 
	1,
	16,
	10,
	0, 
	0x0010,
	20, 
	"displayframe" 
};


private	void	reset_data_form_control()
{
	DFC.editlate.Contents.events = &DFC.editlate.Contents.abal_events;
	reset_event_control(DFC.editlate.Contents.events,0);
	DFC.template.Contents.events = &DFC.template.Contents.abal_events;
	reset_event_control(DFC.template.Contents.events,0);
	DFC.pagelate.Contents.events = &DFC.pagelate.Contents.abal_events;
	reset_event_control(DFC.pagelate.Contents.events,0);
	DFC.filelate.Contents.events = &DFC.filelate.Contents.abal_events;
	reset_event_control(DFC.filelate.Contents.events,0);
	DFC.formlate.Contents.events = &DFC.formlate.Contents.abal_events;
	reset_event_control(DFC.formlate.Contents.events,0);
	DFC.cursor.Contents.events = &DFC.cursor.Contents.abal_events;
	reset_event_control(DFC.cursor.Contents.events,0);

	DFC.template.Contents.datatype = 0;
	DFC.pagelate.Contents.datatype = 0;
	DFC.editlate.Contents.datatype = 0;
	DFC.filelate.Contents.datatype = 0;
	DFC.formlate.Contents.datatype = 0;
	DFC.cursor.Contents.datatype   = 1;
	DFC.formlate.Contents.align    = 1025;

	DFC.template.Contents.font 	= 2;
	DFC.formlate.Contents.font 	= 1;
	DFC.editlate.Contents.font 	= 1;

	DFC.totlabel=0;
	DFC.totwidth=0;
	DFC.maxwidth=0;
	DFC.butwidth=0;
	DFC.maxlabel=0;
	DFC.maxitems=0;

	return;
}

public	int	generate_data_form_window( 
	struct file_control * optr, 
	struct data_control * dptr, 
	struct form_control * fptr, 
	char * tptr, int pageitems )
{
	DFC.template.Contents.style = _WINDOW_FRAME;
	DFC.template.Contents.x 	= 0;
	DFC.template.Contents.y 	= 0;
	DFC.template.Contents.colour= 0x0010;	/* Black on Transparent */
	DFC.template.Contents.align = 0x0703;	/* Center : Exit/Help/Shadow */
	DFC.template.Contents.font 	= 2;

	return( generate_multi_data_widget(optr, fptr, 
		multiple_messages(tptr), &DFC.template ));
}
	
public	int	generate_data_form_frame( 
	struct file_control * optr, 
	struct data_control * dptr, 
	struct form_control * fptr, 
	char * tptr, int pageitems )
{
	DFC.template.Contents.x += 10;	
	DFC.template.Contents.w -= 20; 
	DFC.template.Contents.y = 30;
	DFC.template.Contents.h = (dptr->indexfields * Edit.interline)+10;
	DFC.template.Contents.style = _OUTSET_FRAME;
	DFC.template.Contents.align = 0;

	if (!( pageitems ))
		return( generate_data_widget(optr, fptr, (char *) 0, &DFC.template ) );
	else	return( 0 );
}

public	int	generate_data_form_page( 
	struct file_control * optr, 
	struct data_control * dptr, 
	struct form_control * fptr, 
	char * tptr, int pageitems )
{
	DFC.template.Contents.y     += (DFC.template.Contents.h);

	if (( DFC.maxitems > pageitems ) &&  ( pageitems != 0 )) {
		DFC.template.Contents.h 	= (pageitems*Edit.interline)+10;
		DFC.template.Contents.style = _TAB_FRAME;
		DFC.pagelate.Contents.style 	=DFC.template.Contents.style ;
		DFC.pagelate.Contents.x     	=DFC.template.Contents.x;
		DFC.pagelate.Contents.y     	=DFC.template.Contents.y;
		DFC.pagelate.Contents.w     	=DFC.template.Contents.w;
		DFC.pagelate.Contents.font  	=DFC.template.Contents.font;
		DFC.pagelate.Contents.h     	=DFC.template.Contents.h+70;
		DFC.pagelate.Contents.align 	=DFC.template.Contents.align;
		DFC.pagelate.Contents.colour	=DFC.template.Contents.colour;
		return( generate_data_widget(optr, fptr, (char *) 0, &DFC.pagelate ) );
		}
	else 	{
		DFC.template.Contents.h 	= (dptr->datafields*Edit.interline)+10;
		return( generate_data_widget(optr, fptr, (char *) 0, &DFC.template ) );
		}
}

public	int	generate_data_form_table( 
	struct file_control * optr, 
	struct data_control * dptr, 
	struct form_control * fptr, 
	char * labels, char * format, int pageitems )
{
	int	status;

	DFC.formlate.Contents.x	= (DFC.template.Contents.x + 20);	
	DFC.formlate.Contents.y = (DFC.template.Contents.y + 30);	
	DFC.formlate.Contents.style = _FORM_FRAME;

	DFC.cursor.Contents.x = DFC.formlate.Contents.x;
	DFC.cursor.Contents.y = DFC.formlate.Contents.y+24;
	DFC.cursor.Contents.w = DFC.formlate.Contents.w;
	DFC.cursor.Contents.h = 24;
	DFC.cursor.Contents.style = _FILL_FRAME;


	if (!( format ))
		return(118);
	else if (!( labels ))
		return(118);
	else if ((status = generate_data_widget(
			optr, fptr, 
			"FileList",
			&DFC.formlate )) != 0)
		return( status );
	else if (!( fptr->last->Contents.format = allocate_string( format ) ))
		return( 27 );
	else	{
		fptr->last->Contents.align = 1;
		generate_multiple_payloads( fptr, fptr->last, labels );
		}

	if ((status = generate_data_widget(
		optr, fptr, (char *) 0,	&DFC.cursor )) != 0)
		return(status);
	else if (!( fptr->last->Contents.name = allocate( strlen( "Cursor" ) + strlen( optr->identity) + 8 ) ))
		return(27);
	else	{
		sprintf(fptr->last->Contents.name,"%sCursor",optr->identity);
		fptr->last->Contents.align = 1;
		}

	/* ------------------------------------ */
	/*    table scroll component widget	*/
	/* ------------------------------------ */
	DFC.formlate.Contents.x += (DFC.formlate.Contents.w + 2);
	DFC.formlate.Contents.w  = 20;
	DFC.formlate.Contents.style = _SCROLL_FRAME;
	DFC.formlate.Contents.align = 0x0003;	/* Both */

	if ((status = generate_data_widget(optr, fptr, "VSB", &DFC.formlate )) != 0)
		return( status );
	else	return( 0 );
}


public	int	abal_data_fileindex_edit( 
	struct file_control * optr, 
	struct data_control * dptr, 
	struct form_control * fptr, 
	char * nptr, char * kptr, int fmlen)
{
	int	status;

	DFC.editlate.Contents.style 	= _EDIT_FRAME;
	DFC.editlate.Contents.x 	= 20;
	DFC.editlate.Contents.y 	= 30;
	DFC.editlate.Contents.w 	= ((10*fmlen)+2);
	DFC.editlate.Contents.h 	= Edit.height;
	DFC.editlate.Contents.align 	= Edit.align;
	DFC.editlate.Contents.font	= Edit.font;

	if ((status = generate_multi_data_widget(optr, fptr, multiple_messages(optr->filename), &DFC.editlate )) != 0)
		return( status );
	else if (!( fptr->last->Contents.name = allocate( strlen( nptr ) + strlen( optr->identity ) + 8 ) ))
		return(27);
	else if (!( fptr->last->Contents.format = allocate( strlen( kptr ) + 8 ) ))
		return( 27 );
	else	{
		fptr->last->Contents.datatype = _WIDGET_STRING;
		fptr->last->Contents.interfaceitem = 1;
		fptr->last->Contents.events->xo_get_focus 	= _FUNCTION_NOT_FOCUS;
		fptr->last->Contents.events->xo_show  		= _FUNCTION_AND_FOCUS;
		fptr->last->Contents.events->xo_event 		= _FUNCTION_NOT_FOCUS;
		sprintf(fptr->last->Contents.name,"%s%s",optr->identity,nptr);
		sprintf(fptr->last->Contents.format,"(%s)",kptr);
		return(0);
		}
}

public	int	generate_data_form_file( 
	struct file_control * optr, 
	struct data_control * dptr, 
	struct form_control * fptr, 
	char * tptr, int pageitems )
{
	int	status;
	DFC.filelate.Contents.style = _DATA_FRAME;
	DFC.filelate.Contents.x 	= 5;
	DFC.filelate.Contents.y 	= 5;
	DFC.filelate.Contents.w 	= 24;
	DFC.filelate.Contents.h 	= 32;
	DFC.filelate.Contents.align = optr->nature;

	if ((status = generate_multi_data_widget(optr, fptr, multiple_messages(optr->filename), &DFC.filelate )) != 0)
		return( status );
	else if (!( fptr->last->Contents.name = allocate_string((optr->identity ? optr->identity : "Dptr")) ))
		return(27);
	else if (!( fptr->last->Contents.format = allocate(strlen(optr->classname)+16) ))
		return(27);
	else	{
		sprintf(fptr->last->Contents.format,"(%s)",optr->classname);
		return(0);
		}
}

private	int	abal_file_datatype_size(
		struct data_control * dptr,
		int f, char * fptr, int maxwidth)
{
	int	txlen;
	int	fmlen;
	txlen = strlen( dptr->name[f] );
	switch (dptr->type[f]) {
		case	_ABAL_BYTE	:
			strcpy(fptr,"N3Z");
			fmlen = 4;
			break;
		case	_ABAL_WORD	:
			strcpy(fptr,"N5Z");
			fmlen = 6;
			break;
		case	_ABAL_LONG	:
			strcpy(fptr,"N9Z");
			fmlen = 10;
			break;
		case	_ABAL_BCD	:
			if ((fmlen = (dptr->width[f] * 2)-1) > maxwidth)
				fmlen = maxwidth;
			sprintf(fptr,"-N%uZ",(fmlen > 3 ? fmlen - 3 : 1));
			break;
		case	_ABAL_STRING	:
			if ((fmlen = dptr->width[f]) > maxwidth)
				fmlen = maxwidth;
			sprintf(fptr,"W%u",fmlen);
			break;
		default			:
			strcpy(fptr,"E");
			fmlen = 0;
		}
	if ( fmlen > txlen )
		return( fmlen );
	else if ( txlen > maxwidth )
		return(maxwidth);
	else	return( txlen );
}

private	char * abal_file_datatype_format( char * lptr, char * nptr )
{
	char *	wptr;
	if (!( nptr ))
		return( lptr );
	else if (!( lptr )) {
		if (!( lptr = allocate( strlen(nptr) + 3 ) ))
			return( lptr );
		else	{
			sprintf(lptr,"(%s",nptr);
			return( lptr );
			}
		}
	else if (!( wptr = allocate( strlen(lptr) + strlen(nptr) + 3 ) ))
		return( lptr );
	else if ( *nptr != ')' ) {
		sprintf(wptr,"%s,%s",lptr,nptr);
		liberate( lptr );
		return( wptr );
		}
	else	{
		sprintf(wptr,"%s%s",lptr,nptr);
		liberate( lptr );
		return( wptr );
		}

}

private	char	* abal_file_datatype_label( char * lptr, char * nptr )
{
	char *	wptr;
	if (!( nptr ))
		return( lptr );
	else if (!( lptr )) {
		return( allocate_string( nptr ) );
		}
	else if (!( wptr = allocate( strlen(lptr) + strlen(nptr) + 3 ) ))
		return( lptr );
	else	{
		sprintf(wptr,"%s|%s",lptr,nptr);
		liberate( lptr );
		return( wptr );
		}
}

public	int	generate_data_filelist( 
	struct form_control * fptr, 
	struct file_control * optr, 
	struct data_control * dptr, 
	char * tptr, int pageitems, int listcolumns, int maxcol )
{
	int	status;
	char	* lptr=(char *) 0;
	char	* kptr=(char *) 0;
	int	fmlen=0;
	int	templen;
	char	fbuffer[64];
	char	* nptr;
	int	f;
	int	first=0;
	int	llen=0;
	int	elen=0;
	int	fw;
	int	fh;
	int	include_index_information=0;
	if (!( fptr ))		return;
	else if (!( optr ))	return;
	else if (!( dptr ))	return;
	else 	{
		if (!( pageitems ))
			pageitems = 24;	/* lines per list */
		if (!( listcolumns ))
			listcolumns = 80; /* max width of entire list in columns */
		if (!( maxcol ))
			maxcol = 24; /* max width of an individual column */
		}
	reset_data_form_control();

	if (!( DFC.template.Contents.font ))
		return(30);
	else if (!( fw = guifontsize( DFC.formlate.Contents.font ) ))
		return(30);
	else 	{
		fh = (fw >> 8);
		fw = (fw & 0x00FF);
		}

	/* scan index record members and calculate column control information */
	/* ------------------------------------------------------------------ */
	for (f=0; f < dptr->indexfields; f++ ) {
		if (!( dptr->special[f] & 2 ))
			continue;
		if (!( nptr = dptr->name[f] ))
			continue;
		templen = abal_file_datatype_size(dptr,f,fbuffer,maxcol);
		if ((fmlen + templen) < listcolumns) {
			fmlen += templen;
			lptr = abal_file_datatype_label(lptr,nptr);
			kptr = abal_file_datatype_format(kptr,fbuffer);
			}
		else	break;
		}
	/* scan data record members and calculate column control information */
	/* ----------------------------------------------------------------- */
	if ( fmlen < listcolumns ) {
		for (first=dptr->indexfields,f=0; f < dptr->datafields; f++ ) {
			if (!( dptr->special[f+first] & 2 ))
				continue;
			if (!( nptr = dptr->name[f+first] ))
				continue;
			templen = abal_file_datatype_size(dptr,f+first,fbuffer,maxcol);
			if ((fmlen + templen) < listcolumns) {
				fmlen += templen;
				lptr = abal_file_datatype_label(lptr,nptr);
				kptr = abal_file_datatype_format(kptr,fbuffer);
				}
			else	break;
			}
		}

	if (!( kptr ))
		kptr=allocate_string("(E)");
	else	kptr = abal_file_datatype_format(kptr,")");

	if ( fmlen < listcolumns )
		listcolumns = fmlen;

	DFC.formlate.Contents.align = 0x0403;	/* Center : Relief */
	DFC.formlate.Contents.h 	= (((pageitems+1)*fh)+4);
	DFC.template.Contents.h		= DFC.formlate.Contents.h + 50;
	DFC.formlate.Contents.w 	= ((listcolumns*fw)+4);
	DFC.template.Contents.w		= DFC.formlate.Contents.w + 60;

	generate_data_form_window( optr, dptr, fptr, tptr, pageitems );
	generate_data_form_file  ( optr, dptr, fptr, tptr, pageitems );

	/* scan index members and generate interface edit fields */
	/* ----------------------------------------------------- */
	for (first=0,f=0; f < dptr->indexfields; f++ ) {

		if (!( nptr = dptr->name[f+first] ))
			continue;

		templen = abal_file_datatype_size(dptr,f+first,fbuffer,maxcol);

		if ((status = abal_data_fileindex_edit( optr, dptr, fptr, nptr, fbuffer, templen )) != 0)
			return( status );

		}


	generate_data_form_table ( optr, dptr, fptr, lptr, kptr, pageitems );

	/* table forms method event control */
	fptr->last->previous->previous->Contents.events->xo_get_focus 	= _FUNCTION_NOT_FOCUS;
	fptr->last->previous->previous->Contents.events->xo_show  	= _EVENT_IS_FUNCTION;
	fptr->last->previous->previous->Contents.events->xo_event 	= _FUNCTION_AND_FOCUS;

	/* forms show method */
	if (( status = generate_widget_action( fptr->last->previous->previous,dptr, 0x0209,optr )) != 0)
		return( status );
	/* forms event method */
	else if (( status = generate_widget_action( fptr->last->previous->previous,dptr, 0x040A,optr )) != 0)
		return( status );

	/* table cursor method event control */
	fptr->last->previous->Contents.events->xo_create  	= _EVENT_IS_OTHER;
	fptr->last->previous->Contents.events->xo_show  	= _EVENT_IS_COND;
	fptr->last->previous->Contents.events->xo_get_focus 	= _FUNCTION_NOT_FOCUS;
	fptr->last->previous->Contents.events->xo_event 	= _FUNCTION_NOT_FOCUS;

	/* scrollbar method event control */
	fptr->last->Contents.events->xo_event 			= _FUNCTION_AND_FOCUS;

	/* scrollbar create method */
	if (( status = generate_widget_action( fptr->last,dptr, 0x010B,optr )) != 0)
		return( status );
	/* scrollbar event method */
	else if (( status = generate_widget_action( fptr->last,dptr, 0x040C,optr )) != 0)
		return( status );
	/* scrollbar show method */
	else if (( status = generate_widget_action( fptr->last,dptr, 0x020D,optr )) != 0)
		return( status );

	terminate_data_form( fptr );

	return(13);
}

public	int	generate_data_widgets( 
	struct form_control * fptr, 
	struct file_control * optr, 
	struct data_control * dptr, 
	char * tptr, int pageitems )
{
	char	crebuf[256];
	int	f;
	int	first;
	int	status;
	char	* nptr;
	int	llen=0;
	int	elen=0;
	int	curitem;
	int	fw=0;
	int	fh=0;

	if (!( fptr ))		return;
	else if (!( optr ))	return;
	else if (!( dptr ))	return;

	reset_data_form_control();

	/* ----------------- */
	/* set the edit font */
	/* ----------------- */
	Edit.font = Context.Item.font;

	if (!( fw = guifontsize( Edit.font ) ))
		return(30);
	else 	
	{
		fh = (fw >> 8);
		fw = (fw & 0x00FF);
	}

	Edit.width  = fh;
	Edit.height = fh;
	Edit.interline = ( fh + (fh / 4) );
	Label.interline = Edit.interline;

	for (first=0,f=0; f < dptr->indexfields; f++ ) {
		if (!(nptr = dptr->name[f+first] ))
			continue;
		DFC.maxitems++;
		if (( llen = textsizelen(DFC.template.Contents.font,nptr,strlen(nptr))) > DFC.maxlabel )
 			DFC.maxlabel = (llen + 10);
		if (( elen = data_pixel_width( dptr, (f+first), 10) ) > DFC.maxwidth )
			DFC.maxwidth = (elen+10);
		} 

	for (first=dptr->indexfields,f=0; f < dptr->datafields; f++ ) {
		if (!(nptr = dptr->name[f+first] ))
			continue;
		DFC.maxitems++;
		if (( llen = textsizelen(DFC.template.Contents.font,nptr,strlen(nptr))) > DFC.maxlabel )
 			DFC.maxlabel = (llen + 10);
		if (( elen = data_pixel_width( dptr, (f+first), 10) ) > DFC.maxwidth )
			DFC.maxwidth = (elen+10);
		}

	DFC.template.Contents.w  = (DFC.maxlabel+DFC.maxwidth+(5*10));
	if ((DFC.butwidth = ((DFC.template.Contents.w - 20)/7)) < 60) {
		DFC.butwidth = 60;
		DFC.template.Contents.w = (DFC.butwidth*7)+20;
		}
	if ( pageitems > dptr->datafields )
		pageitems = 0;

	if ( pageitems )
	{
		DFC.template.Contents.h 	= 80+((dptr->indexfields+pageitems)*Edit.interline)+100;
	}
	else	
	{
		DFC.template.Contents.h 	= 80+((dptr->indexfields+dptr->datafields)*Edit.interline)+40;
	}

	generate_data_form_window( optr, dptr, fptr, tptr, pageitems );
	generate_data_form_frame ( optr, dptr, fptr, tptr, pageitems );
	generate_data_form_page  ( optr, dptr, fptr, tptr, pageitems );
	generate_data_form_file  ( optr, dptr, fptr, tptr, pageitems );

	/* ------------------------------ */
	/* Generate Text and Edit Widgets */
	/* ------------------------------ */
	DFC.template.Contents.style = _TEXT_FRAME;
	DFC.template.Contents.x 	= 20;

	if (!( pageitems ))
		DFC.template.Contents.y 	= 35;
	else	DFC.template.Contents.y 	= 35+60;

	DFC.template.Contents.w 	= DFC.maxlabel;
	DFC.template.Contents.font 	= Label.font; 		/* 2*/
	DFC.template.Contents.h 	= Label.height; 	/* 16 */
	DFC.template.Contents.align 	= Label.align; 		/* 0x0502 Left : Bold / Shadow */
	DFC.template.Contents.colour	= Label.colour;		/* 0x0010 Black on Transparent */

	if ( method_is_valid( fptr->stylesheet ) )
		DFC.template.Contents.stylesheet = Label.style;	/* "editlabel"	*/

	DFC.editlate.Contents.style = _EDIT_FRAME;
	DFC.editlate.Contents.x 	= (DFC.template.Contents.w+20);
	if (!( pageitems ))
		DFC.editlate.Contents.y 	= 35;
	else	DFC.editlate.Contents.y 	= 35+60;

	DFC.editlate.Contents.w 		= 0;
	DFC.editlate.Contents.font 		= Edit.font;	/* 1;				*/
	DFC.editlate.Contents.h 		= Edit.height;	/* 16;				*/
	DFC.editlate.Contents.align 		= Edit.align;	/* 0 Left : Bold / Shadow 	*/
	DFC.editlate.Contents.colour		= Edit.colour;	/* 0x0010 Black on Transparent 	*/
	DFC.editlate.Contents.datatype 		= _WIDGET_STRING;
	if ( method_is_valid( fptr->stylesheet ) )
		DFC.editlate.Contents.stylesheet = Edit.style;	/* "displayframe" 		*/

	for (first=0,f=0; f < dptr->indexfields; f++ ) {
		if (!(nptr = dptr->name[f+first] ))
			continue;
		else if ((status = generate_multi_data_widget((struct file_control *) 0, fptr, multiple_messages(nptr), &DFC.template )) != 0)
			return( status );
		else	DFC.template.Contents.y += Label.interline; /* 20 */
		DFC.editlate.Contents.w = data_pixel_width(dptr,f+first,10);
		if ((status = generate_multi_data_widget((struct file_control *) 0, fptr, multiple_messages(nptr), &DFC.editlate )) != 0)
			return( status );
		else if (( status = generate_widget_action( fptr->last,dptr, 0x0508,optr )) != 0)
			return( status );
		else	DFC.editlate.Contents.y += Edit.interline; /* 20 */

		}

	if (!( pageitems )) 
	{
		DFC.template.Contents.y += Label.interline;
		DFC.editlate.Contents.y += Edit.interline;
	}

	for (curitem=0,first=dptr->indexfields,f=0; f < dptr->datafields; f++ ) {
		if (!(nptr = dptr->name[f+first] ))
			continue;

		if (( curitem >= pageitems ) && ( pageitems > 0 )) {
			if ((status = generate_data_widget((struct file_control *) 0, fptr, (char *) 0, &DFC.pagelate )) != 0)
				return( status );
			curitem = 0;
			DFC.editlate.Contents.y 	= 35+60;
			DFC.template.Contents.y 	= 35+60;
			}
		else	curitem++;

		if ((status = generate_multi_data_widget(optr, fptr, multiple_messages(nptr), &DFC.template )) != 0)
			return( status );
		else	DFC.template.Contents.y += Label.interline; /* 20 */

		DFC.editlate.Contents.w = data_pixel_width(dptr,f+first,10);
		/* obtain initial value from file */
		DFC.editlate.Contents.events->on_create=crebuf;
		sprintf(crebuf,"\tthis.buffer=%s.%s",(optr->identity ? optr->identity : "Dptr"),nptr);
		if ((status = generate_multi_data_widget((struct file_control *) 0,  fptr, multiple_messages(nptr), &DFC.editlate )) != 0)
			return( status );
		else	DFC.editlate.Contents.y += Edit.interline; /* 20 */

		if (!( fptr->last->Contents.format = allocate( 20 ) ))
			break;
		else	sprintf(fptr->last->Contents.format,"(W%u)",dptr->width[f+first] );
		DFC.editlate.Contents.events->on_create=(char*)0;

		}

	DFC.template.Contents.stylesheet = (char *) 0;
	DFC.editlate.Contents.stylesheet = (char *) 0;

	/* Generate Operations */
	/* ------------------- */
	DFC.template.Contents.style 	= _BUTTON_FRAME;
	DFC.template.Contents.x 	= 10;
	if ( pageitems )
		DFC.template.Contents.y = 120+((dptr->indexfields+pageitems)*Edit.interline);
	else	DFC.template.Contents.y = 60+((dptr->indexfields+dptr->datafields)*Edit.interline);
	DFC.template.Contents.w 	= DFC.butwidth;
	DFC.template.Contents.h 	= 40;
	DFC.template.Contents.colour	= 0x0010;	/* Black on Transparent */
	DFC.template.Contents.align 	= 0x0000;	/* Center : Exit/Help/Shadow */
	DFC.template.Contents.font 	= 2;

	switch( get_data_production_language() )
	{
	case	_GENERATE_BAL	:
	case	_GENERATE_ABAL	:
		if ((status = generate_multi_data_widget(optr, fptr, 
			multi_message_list("Accept","Valider",(char *) 0,(char *) 0,(char *) 0,(char *) 0,(char *) 0,(char *) 0) 
			,&DFC.template )) != 0)
			return( status );
		else if (( status = generate_widget_action( fptr->last,dptr, 1,optr )) != 0)
			return( status );
		else	DFC.template.Contents.x 	+= DFC.template.Contents.w;
		break;
	case	_GENERATE_PHP	:
	case	_GENERATE_LASER	:
	case	_GENERATE_BIFS 	:
		if ((status = generate_multi_data_widget(optr, fptr, 
			multi_message_list("Remove","Detruire",(char *) 0,(char *) 0,(char *) 0,(char *) 0,(char *) 0,(char *) 0) 
			,&DFC.template )) != 0)
			return( status );
		else if (( status = generate_widget_action( fptr->last,dptr, 15,optr )) != 0)
			return( status );
		else	DFC.template.Contents.x 	+= DFC.template.Contents.w;
		break;
	}
	if ((status = generate_multi_data_widget(optr, fptr, 
			multi_message_list("Up","Pr‚c‚dant",(char *) 0,(char *) 0,(char *) 0,(char *) 0,(char *) 0,(char *) 0) 
			, &DFC.template )) != 0)
		return( status );
	else if (( status = generate_widget_action( fptr->last,dptr, 2,optr )) != 0)
		return( status );
	else	DFC.template.Contents.x 	+= DFC.template.Contents.w;
	if ((status = generate_multi_data_widget(optr, fptr, 
			multi_message_list("Load","Charger",(char *) 0,(char *) 0,(char *) 0,(char *) 0,(char *) 0,(char *) 0) 
			, &DFC.template )) != 0)
		return( status );
	else if (( status = generate_widget_action( fptr->last,dptr, 3,optr )) != 0)
		return( status );
	else	DFC.template.Contents.x 	+= DFC.template.Contents.w;
	if ((status = generate_multi_data_widget(optr, fptr, 
			multi_message_list("Delete","Supprimer",(char *) 0,(char *) 0,(char *) 0,(char *) 0,(char *) 0,(char *) 0) 
			, &DFC.template )) != 0)
		return( status );
	else if (( status = generate_widget_action( fptr->last,dptr, 4,optr )) != 0)
		return( status );
	else	DFC.template.Contents.x 	+= DFC.template.Contents.w;
	if ((status = generate_multi_data_widget(optr, fptr, 
			multi_message_list("Save","Sauver",(char *) 0,(char *) 0,(char *) 0,(char *) 0,(char *) 0,(char *) 0) 
			, &DFC.template )) != 0)
		return( status );
	else if (( status = generate_widget_action( fptr->last,dptr, 5,optr )) != 0)
		return( status );
	else	DFC.template.Contents.x 	+= DFC.template.Contents.w;
	if ((status = generate_multi_data_widget(optr, fptr, 
			multi_message_list("Down","Suivant",(char *) 0,(char *) 0,(char *) 0,(char *) 0,(char *) 0,(char *) 0) 
			, &DFC.template )) != 0)
		return( status );
	else if (( status = generate_widget_action( fptr->last,dptr, 6,optr )) != 0)
		return( status );
	else	DFC.template.Contents.x 	+= DFC.template.Contents.w;
	switch( get_data_production_language() )
	{
	case	_GENERATE_BAL	:
	case	_GENERATE_ABAL	:
		if ((status = generate_multi_data_widget(optr, fptr, 
				multi_message_list("Cancel","Abandoner",(char *) 0,(char *) 0,(char *) 0,(char *) 0,(char *) 0,(char *) 0) 
				, &DFC.template )) != 0)
			return( status );
		else if (( status = generate_widget_action( fptr->last,dptr, 7,optr )) != 0)
			return( status );
		else	break;

	case	_GENERATE_PHP	:
	case	_GENERATE_LASER	:
	case	_GENERATE_BIFS 	:
		if ((status = generate_multi_data_widget(optr, fptr, 
				multi_message_list("Create","Cr‚er",(char *) 0,(char *) 0,(char *) 0,(char *) 0,(char *) 0,(char *) 0) 
				, &DFC.template )) != 0)
			return( status );
		else if (( status = generate_widget_action( fptr->last,dptr, 14,optr )) != 0)
			return( status );
		else	break;



	}
	terminate_data_form( fptr );
	return(13);

}

private	void	data_forms_options( struct form_control * fptr, int language )
{
	fptr->language = get_data_production_language();
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

	/* default forms options */
	/* --------------------- */
	fptr->formflags |= _FORM_INTERNATIONAL;
	fptr->formflags |= _FORM_COMMANDLINE;
	fptr->formflags |= _FORM_MULTILINGUAL;
	fptr->formflags |= _FORM_ESC;
	fptr->formflags |= _FORM_PAGE_UP;
	fptr->formflags |= _FORM_PAGE_DOWN;
	fptr->formflags |= _FORM_TAB;
	fptr->formflags |= _FORM_RC;
	fptr->formflags |= _FORM_UP;
	fptr->formflags |= _FORM_DOWN ;

	/* default mouse options */
	/* --------------------- */
	fptr->mimoflags |= _MIMO_KEYBOARD;
	fptr->mimoflags |= _MIMO_SEND_LEFT;
	fptr->mimoflags |= _MIMO_SEND_RIGHT;
	fptr->mimoflags |= _MIMO_SEND_WHEEL;
	fptr->mimoflags |= _MIMO_DOWN;
	fptr->mimoflags |= _MIMO_UP;
	fptr->mimoflags |= _MIMO_WHILE_DOWN;

	fptr->ispopup     = 1;	/* push pop 		*/
	fptr->isdynamic   = 1;	/* dynamic positioning 	*/
	fptr->stylesheet  = application_style_sheet();
	return;
}

public	int	generate_database_widgets( struct file_control * optr, struct data_control * dptr, char * tptr, int pageitems, char * namelist  )
{
	int	i;
	int	n;
	char *	nptr;
	char *	stubname;
	struct	form_control * fptr;
	struct	data_control * xptr;
	struct	file_control   fc;
	char *	rootname;
	char	classname[512];
	char	formname[512];
	char	rootpath[512];
	/* collect the rootname : the database name with eventual path */
	if (!( rootname = extract_db_filename( namelist, 0)))
		return(0);
	else	{
		rootpath[0] = 0;
		fn_parser(rootname,rootpath,0x0007);
		}
	for (i=0; i < dptr->datafields; i++ ) {
		if (!( nptr = dptr->name[i] ))
			continue;
		else	{
			for ( n=0; *(nptr+n) != 0; n++ ) {
				if ((classname[n] = *(nptr+n)) == ' ' )
					break;
				else if (classname[n] == '/' )
					break;
				}
			classname[n] = 0;
			while ( *(nptr+n) == ' ' ) n++;
			nptr += n;
			if (!( xptr = resolve_class_data((void*)0, classname ) ))
				continue;
			else if (!( stubname = extract_db_filename( namelist, (i+1) )))
				continue;
			strcpy(formname,stubname);
			strcat(formname,"mask");
			if (!( fptr = allocate_Form(formname) ))
				continue;
			else	{
				data_forms_options( fptr, 1 );
				fc.classname = classname;
				fc.identity  = nptr;
				if ( strlen(rootpath) != 0 ) {
					if (!( fc.filename = allocate( strlen( rootpath ) + strlen( stubname ) + 8 )))
						break;
					else	sprintf(fc.filename,"%s%s",rootpath,stubname);
					}
				else if (!( fc.filename = allocate_string( stubname )))
					break;
				fc.nature = _MCFILE_FRAME;
				generate_data_widgets( fptr, &fc, xptr, tptr, pageitems );
				liberate( fc.filename );
				}
			}
		}
	return;
}

public	int	generate_database_filelist( struct file_control * optr, struct data_control * dptr, char * tptr, int pageitems, char * namelist, int listcolumns, int maxcol  )
{
	int	i;
	int	n;
	char *	nptr;
	char *	stubname;
	struct	form_control * fptr;
	struct	data_control * xptr;
	struct	file_control   fc;
	char *	rootname;
	char	classname[512];
	char	formname[512];
	char	rootpath[512];
	/* collect the rootname : the database name with eventual path */
	if (!( rootname = extract_db_filename( namelist, 0)))
		return(0);
	else	{
		rootpath[0] = 0;
		fn_parser(rootname,rootpath,0x0007);
		}
	for (i=0; i < dptr->datafields; i++ ) {
		if (!( nptr = dptr->name[i] ))
			continue;
		else	{
			for ( n=0; *(nptr+n) != 0; n++ ) {
				if ((classname[n] = *(nptr+n)) == ' ' )
					break;
				else if (classname[n] == '/' )
					break;
				}
			classname[n] = 0;
			while ( *(nptr+n) == ' ' ) n++;
			nptr += n;
			if (!( xptr = resolve_class_data((void*)0, classname ) ))
				continue;
			else if (!( stubname = extract_db_filename( namelist, (i+1) )))
				continue;
			strcpy(formname,stubname);
			strcat(formname,"list");
			if (!( fptr = allocate_Form(formname) ))
				continue;
			else	{
				data_forms_options( fptr, 1 );
				fc.classname = classname;
				fc.identity  = nptr;
				if ( strlen(rootpath) != 0 ) {
					if (!( fc.filename = allocate( strlen( rootpath ) + strlen( stubname ) + 8 )))
						break;
					else	sprintf(fc.filename,"%s%s",rootpath,stubname);
					}
				else if (!( fc.filename = allocate_string( stubname )))
					break;
				fc.nature = _MCFILE_FRAME;
				generate_data_filelist( fptr, &fc, xptr, tptr, pageitems, listcolumns, maxcol );
				liberate( fc.filename );
				}
			}
		}
	return;
}

public	int	generate_data_list( 
	struct file_control * optr, 
	char * nptr, 
	int nlen,
	char * tptr, 
	int tlen, 
	int language,
	int pageitems,
	int listcolumns,
	int maxcolumns )
{
	struct	data_control * dptr=(struct data_control *) 0;
	struct	form_control * fptr=(struct form_control *) 0;
	set_data_production_model( language );
	if (!( optr )) 
		return(-1); 
	else if (!( dptr = optr->payload )) 
		return(-1); 
	limit_right_space( nptr,nlen);
	limit_right_space( tptr,tlen);
	if ( optr->nature == _DBFILE_FRAME )
		return( generate_database_filelist( optr, dptr, tptr, pageitems, nptr, listcolumns, maxcolumns ) );
	else if (!( fptr = allocate_Form(nptr) ))
		return( -1 );
	else	{
		data_forms_options( fptr, language );
		return( generate_data_filelist( fptr, optr, dptr, tptr, pageitems, listcolumns, maxcolumns ) );
		}
}

public	int	generate_data_mask( 
	struct file_control * optr, 
	char * nptr, 
	int nlen,
	char * tptr, 
	int tlen, 
	int language,
	int pageitems )
{
	struct	data_control * dptr=(struct data_control *) 0;
	struct	form_control * fptr=(struct form_control *) 0;
	if (!( optr )) 
		return(-1); 
	else if (!( dptr = optr->payload )) 
		return(-1); 
	limit_right_space( nptr,nlen);
	limit_right_space( tptr,tlen);
	if ( optr->nature == _DBFILE_FRAME )
		return( generate_database_widgets( optr, dptr, tptr, pageitems, nptr ) );
	else if (!( fptr = allocate_Form(nptr) ))
		return( -1 );
	else	{
		data_forms_options( fptr, language );
		return( generate_data_widgets( fptr, optr, dptr, tptr, pageitems ) );
		}
}

public	int	generate_data_page( 
	struct file_control * optr, 
	char * nptr, 
	int nlen, 
	char * tptr, 
	int tlen,
	int language,int pageitems )
{
	struct	data_control * dptr=(struct data_control *) 0;
	struct	form_control * fptr=(struct form_control *) 0;
	if (!( optr )) 
		return(-1); 
	else if (!( dptr = optr->payload )) 
		return(-1); 
	limit_right_space( nptr,nlen);
	limit_right_space( tptr,tlen);
	if (!( fptr = allocate_Form(nptr) ))
		return( -1 );

	else	{
		data_forms_options( fptr, language );
		return( generate_data_widgets( fptr, optr, dptr, tptr, pageitems ) );
		}
}

public	int	is_file_instance_user( struct form_item * iptr, char * sptr )
{
	struct form_control * fptr;
	if (!( iptr ))
		return(0);
	else if ((iptr->Contents.style & _FRAME_TYPE) != _DATA_FRAME)
		return(0);
	else	{
		switch ( iptr->Contents.align & 0x000F ) {
			case	_SQFILE_FRAME		:	/* 6 sqfile		*/
			case	_DBFILE_FRAME		:	/* 7 dbfile		*/
			case	_SIFILE_FRAME		:	/* 3 sifile		*/
			case	_MCFILE_FRAME		:	/* 4 mcfile		*/
			case	_OCCI_FRAME		:	/* 10 OCCI  		*/
			case	_OCCI_MIRROR		:	/* 11 MIRROR		*/
			case	_PHP_REPLICATE		:
			case	_VMEMORY_FRAME		:
				return( check_file_class( iptr->Contents.format, sptr ) );
			default				:
				return(0);
			}
		}
}

public	void	list_database(char * fn,int nl)
{
	FILE *	h;
	int	i;
	int	l;
	char *	listname;
	if (!( listname = allocate(nl+1)))
		return;
	for (i=0; i < nl; i++ ) {
		if ((*(listname+i) = *(fn+i)) != ' ')
			l = i;
		}
	*(listname+l+1)=0;
	if (!(h = open_production_target(listname,1))) {
		liberate( listname );
		return;
		}
	else	{
		print_database_records(h);
		close_production_target(h,listname);
		liberate( listname );
		return;
		}
}

private	struct	wegen_parameters {
	char	*	url;
	char 	*	wsname;
	char 	*	agentname;
	int		genws;
	int		genagent;
	int		geniface;
	int		domenu;
	} WsGen = {
	(char *) 0,
	(char *) 0,
	(char *) 0,
	1,1,1,0
	};

#include "abalsoap.c"
#include "abalwsdl.c"
#include "phplang.c"
#include "phpform.c"
#include "reactform.c"
#include "nodeform.c"
#include "phpfile.c"
#include "singlsl.c"
#include "androform.c"
#include "androws.c"
#include "andropage.c"

public	void	generate_data_web_service( struct file_control * optr )
{
	if ( vwsgen(	&WsGen.url,
			&WsGen.wsname,
			&WsGen.agentname,
			&WsGen.genws,
			&WsGen.genagent,
			&WsGen.geniface,
			&WsGen.domenu
			) != 27 ) {

		/* ------------------------------------------ */
		/* generate server side web service component */
		/* ------------------------------------------ */
		switch ( WsGen.genws 	) {
			case	0 :
				/* none */
				/* ---- */
				break;
			case	1 :
				/* wasp / soap */
				/* ----------- */
				generate_soap_web_service(optr, WsGen.wsname, strlen(WsGen.wsname) );
				break;
			case	2 :
				/* php / soap */
				/* ---------- */ 
				generate_php_web_service(optr, WsGen.wsname, strlen(WsGen.wsname) );
				break;
			}

		/* ------------------------------------------ */
		/* generate  client  web  service descritpion */
		/* ------------------------------------------ */
		switch ( WsGen.geniface ) {
			case	0 :
				/* none */
				/* ---- */
				break;
			case	1 :
				generate_wsdl_web_service(optr, WsGen.wsname, strlen(WsGen.wsname) );	
				break;
			case	2 :
				/* wsdl */
				/* ---- */
				break;
			}

		/* ------------------------------------------ */
		/* generate  the  web  service  client source  */
		/* ------------------------------------------ */
		switch ( WsGen.genagent ) {
			case	0 :
				/* none */
				/* ---- */
				break;
			case	1 :	
				generate_lsl_soap_client (optr, WsGen.wsname, strlen(WsGen.wsname) );	
				break;
			case	2 :
				/* html */
				/* ---- */
				generate_html_soap_client (optr, WsGen.wsname, strlen(WsGen.wsname) );	
				break;
			}
		}
	return;
}

public	void	export_form_web_service( struct form_control * fptr )
{
	if ( vwsgen(	&WsGen.url,
			&WsGen.wsname,
			&WsGen.agentname,
			&WsGen.genws,
			&WsGen.genagent,
			&WsGen.geniface,
			&WsGen.domenu
			) != 27 ) {

		/* ------------------------------------------ */
		/* generate server side web service component */
		/* ------------------------------------------ */
		switch ( WsGen.genws 	) {
			case	0 :
				/* none */
				/* ---- */
				break;
			case	1 :
				/* wasp / soap */
				/* ----------- */
				soap_generate_service(fptr, fptr->prodname, fptr->identifier );
				soap_generate_interface(fptr, fptr->prodname, fptr->identifier );
				break;
			case	2 :
				/* php / soap */
				/* ---------- */ 
				php_generate_service(fptr, fptr->prodname, fptr->identifier );
				php_generate_interface(fptr, fptr->prodname, fptr->identifier );
				break;
			}

		/* ------------------------------------------ */
		/* generate  client  web  service descritpion */
		/* ------------------------------------------ */
		switch ( WsGen.geniface ) {
			case	0 :
				/* none */
				/* ---- */
				break;
			case	1 :
				wsdl_generate_interface(fptr,fptr->prodname, fptr->identifier );
				break;
			case	2 :
				/* wsdl */
				/* ---- */
				break;
			}

		/* ------------------------------------------ */
		/* generate  the  web  service  client source  */
		/* ------------------------------------------ */
		switch ( WsGen.genagent ) {
			case	0 :
				/* none */
				/* ---- */
				break;
			case	1 :	
				lsl_generate_soap_client (fptr, fptr->prodname, fptr->identifier );
				break;
			case	2 :
				/* html */
				/* ---- */
				/* html_generate_soap_client (fptr,fptr->prodname, fptr->identifier ); */
				html_php_file_client( fptr );
				break;
			}
		}
	return;
}





#endif	/* _ABAL_DATA_C */
	/* ------------ */




