private	int	stackitems=0;
private	int	istack[256];

extern	char 	LaPaterne[];

#define	_TABLE_ROW	256
#define	_TABLE_CELL	512

#define	_DEFAULT_FOOTER "Copyright (c) 2002,2006 Amenesik / Sologic "
#define	_DEFAULT_STYLE  "sing.css"
#define _DEFAULT_TITLE  "Untitled"

#ifdef	PROLOGUE
#define	_DEFAULT_NAVIGATOR "is\\navig\\nv.xp"
#endif
#ifdef	UNIX
#define	_DEFAULT_NAVIGATOR "mozilla"
#endif
#ifdef	WIN32
#define	_DEFAULT_NAVIGATOR "mozilla"
#endif

static	char * nv=_DEFAULT_NAVIGATOR;

static	struct	{
	int	major;
	int	minor;
	} Numerator = {0, 0};

char	hbuffer[512];

struct	sort_item {
	struct	form_item * widget;
	struct	sort_item * previous;
	struct	sort_item * next;
	int	rowspan;
	int	colspan;
	};

struct	sort_row	{
	int	y;
	int	h;
	int	columns;
	int	lock;
	struct	sort_row * previous;
	struct	sort_row * next;
	struct	sort_item * first;
	struct	sort_item * last;
	};

struct	sort_control	{
	int		   maxcolumns;
	int		   rowcount;
	struct	sort_row * firstrow;
	struct	sort_row * lastrow;
	} SortMan = { 
		0,0,
		(struct sort_row *) 0,
		(struct sort_row *) 0
		};


public 	void	html_tag( FILE * h, char * nptr )
{
	fprintf(h,"<%s>",nptr);
	return;
}

private	void	html_open_tag( FILE * h, char * nptr )
{
	fprintf(h,"<%s",nptr);
	return;
}

private	void	html_close_tag( FILE * h, char * nptr )
{
	fprintf(h,">");
	return;
}

public 	void	html_closure( FILE * h, char * nptr )
{
	fprintf(h,"</%s>",nptr);
	return;
}

private	void	html_field( FILE * h, char * nptr, char * vptr )
{
	fprintf(h," %s=",nptr);
	quoted_string(h,vptr);
	return;
}

private	void	html_int_field( FILE * h, char * nptr, int v)
{
	fprintf(h," %s=%c%u%c",nptr,0x0022,v,0x0022);
	return;
}

private	void	html_perc_field( FILE * h, char * nptr, int v)
{
	fprintf(h," %s=%c%u%c%c",nptr,0x0022,v,0x0025,0x0022);
	return;
}

public 	void	html_text( FILE * h, unsigned char * tptr )
{
	int	nbcol;
	int	character;
	if (!( tptr ))
		return;
	for (	nbcol=0; *tptr != 0; tptr++ ) {
		if (( nbcol > 80 )
		&& ( *tptr == ' ' )) {
			nbcol=0;
			linefeed(h);
			}
		else 	{
			switch ((character = ( *tptr & 0x00FF))) {
				case	0x0082		: fprintf(h,"&eacute;"); break;
				case	0x008A		: fprintf(h,"&egrave;"); break;
				case	0x00A0		: fprintf(h,"&aacute;"); break;
				case	0x0085		: fprintf(h,"&agrave;"); break;
				case	0x00A2		: fprintf(h,"&oacute;"); break;
				case	0x0095		: fprintf(h,"&ograve;"); break;
				case	0x00A3		: fprintf(h,"&uacute;"); break;
				case	0x0097		: fprintf(h,"&ugrave;"); break;
				case	0x00A1		: fprintf(h,"&iacute;"); break;
				case	0x008D		: fprintf(h,"&igrave;"); break;
				case	0x0087		: fprintf(h,"&ccedil;"); break;
				default			:
					if ( character > 127 )
						fprintf(h,"&%d;",character);
					else	fprintf(h,"%c",character);
				}
			nbcol++;
			}
		}
	if ( nbcol != 0 )
		linefeed(h);
	return;
}

public 	void	html_trigger( FILE * h, unsigned char * tptr )
{
	int	nbcol;
	int	character;
	int	trigger=0;
	if (!( tptr ))
		return;
	for (	nbcol=0; *tptr != 0; tptr++ ) {
		if (( nbcol > 80 )
		&& ( *tptr == ' ' )) {
			nbcol=0;
			linefeed(h);
			}
		else 	{
			switch ((character = ( *tptr & 0x00FF))) {
				case	'&'		:
					fprintf(h,"<u>");
					trigger=1;
					continue;
				case	0x0082		: fprintf(h,"&eacute;"); break;
				case	0x008A		: fprintf(h,"&egrave;"); break;
				case	0x00A0		: fprintf(h,"&aacute;"); break;
				case	0x0085		: fprintf(h,"&agrave;"); break;
				case	0x00A2		: fprintf(h,"&oacute;"); break;
				case	0x0095		: fprintf(h,"&ograve;"); break;
				case	0x00A3		: fprintf(h,"&uacute;"); break;
				case	0x0097		: fprintf(h,"&ugrave;"); break;
				case	0x00A1		: fprintf(h,"&iacute;"); break;
				case	0x008D		: fprintf(h,"&igrave;"); break;
				case	0x0087		: fprintf(h,"&ccedil;"); break;
				default			:
					if ( character > 127 )
						fprintf(h,"&%d;",character);
					else	fprintf(h,"%c",character);
				}
			if ( trigger ) {
				fprintf(h,"</u>");
				trigger=0;
				}
			nbcol++;
			}
		}
	if ( nbcol != 0 )
		linefeed(h);
	return;
}

public	void	html_integer(FILE * handle, int value )
{
	char	muffer[32];
	sprintf(muffer,"%u",value);
	html_text( handle, muffer);
	return;
}



private	void	html_target( FILE * handle, char * target )
{
	html_open_tag(handle,"a");
	html_field(handle,"name",target);
	html_close_tag(handle,"a");
	linefeed(handle);
	return;
}

private	void	html_anchor( FILE * handle, char * target, char * message )
{
	html_open_tag(handle,"a");
	html_field(handle,"href",target);
	html_close_tag(handle,"a");
	html_text(handle,message);
	html_closure(handle,"a");
	linefeed(handle);
	return;
}

private	void	html_frame_target_anchor( FILE * handle, char * url, char * target, char * message )
{
	html_open_tag(handle,"a");
	html_field(handle,"href",url);
	html_field(handle,"target",target);
	html_close_tag(handle,"a");
	html_text(handle,message);
	html_closure(handle,"a");
	linefeed(handle);
	return;
}

public	void	html_heading( FILE * h, int size, char * tptr )
{
	char	buffer[16];
	sprintf(buffer,"h%u",size);
	html_open_tag( h, buffer);
	html_field(h,"align","center");
	html_close_tag( h, buffer);		linefeed(h);
	html_text(h,tptr);
	html_closure( h, buffer);		linefeed(h);
	return;
}

private	void	check_open_cell( FILE * handle )
{
	if (!( stackitems ))
		fprintf(handle,"<p>\r\n");
	else	{
		if (!( istack[stackitems] & _TABLE_ROW )) {
			html_tag(handle,"tr"); linefeed(handle);
			istack[stackitems] |= _TABLE_ROW;
			}
		if (!( istack[stackitems] & _TABLE_CELL )) {
			html_tag(handle,"td"); linefeed(handle);
			istack[stackitems] |= _TABLE_CELL;
			}
		}
	return;
}

public	void	html_image( FILE * handle, char * nptr, char * mptr )
{
	int	c;
	html_open_tag(handle,"img");
	html_field(handle,"src", nptr );
	if ( mptr ) {
		fprintf(handle," usemap=%c#",0x0022);
		while ((c = *(mptr++)) != 0 ) {
			if ( c == ' ' ) c = '_';
			fprintf(handle,"%c",c);
			}
		fprintf(handle,"%c ",0x0022);
		}
	html_close_tag(handle,"img");
	linefeed(handle);
	return;
}

public	char * html_numbered_image( FILE * handle, char * nptr, int number , char * mptr )
{
	int	c;
	char *	sptr;
	if ((sptr = allocate( strlen( nptr ) + 16 )) != (char *) 0) {
		fn_parser(nptr,sptr,0x000F);
		sprintf(sptr,"%s%u",sptr,number);
		strcat(sptr,GIF_EXTENSION);
		html_image( handle, sptr, mptr );
		}
	return(sptr);
}


private	void	html_div(FILE * handle, int align )
{
	switch ( align & 0x0007 ) {
		case	_A_CENTER	:
			fprintf(handle,"<div align=center>");
			break;
		case	_A_LEFT  	:
			fprintf(handle,"<div align=left>");
			break;
		case	_A_RIGHT	:
			fprintf(handle,"<div align=right>");
			break;
		default			:			
			fprintf(handle,"<div>");
			break;
		}
	linefeed(handle);
	return;
}

private	void	html_form_widget( FILE * handle,struct form_item * iptr )
{
	int		bytes=0;
	char	*	sptr;
	int		i;
	int		n;
	int		mode=0;
	int		xfi=0;
	int		f=0;
	int		fields=0;
	int		fieldwidth[_MAX_FORM_FIELDS];
	int		linelength=0;
	int		nblines=0;
	int		fw;
	int		fh;

	if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME)
		return;

	calculate_edit_size( &iptr->Contents );
	calculate_edit_lines( &iptr->Contents, &linelength, &nblines );

	if (!( fields = calculate_form_fields(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength) ))
		return;

	fw = guifontsize(iptr->Contents.font);
	fh = (fw >> 8); fw &= 0x00FF;	

	linefeed(handle);
	fprintf(handle,"<table border=1><tr>");
	linefeed(handle);
	if (( sptr = abal_payload(iptr)) != (char *) 0) {
		for ( bytes=0,mode=0,i=0; *(sptr+i) != 0; i++ ) {
			if ( *(sptr+i) == '|' ) {
				if ( bytes ) {
					hbuffer[bytes++] = 0;
					html_text(handle,hbuffer);
					bytes=0;
					}
				mode=0;
				}
			else	{
				if (!( mode )) {
					fprintf(handle,"<th>");
					mode=1;
					}
				hbuffer[bytes++] = *(sptr+i);
				}
			}
		if ( bytes ) {
			hbuffer[bytes++] = 0;
			html_text(handle,hbuffer);
			bytes=0;
			}
		}
	for ( n=0; n < nblines; n++ ) {
		linefeed(handle);
		fprintf(handle,"<tr>");
		for ( i=0; i < fields; i++ ) {
			fprintf(handle,"<td><input type=text name=cellC%uL%u size=%u value=%c %c>",
				i,n,fieldwidth[i],0x0022,0x0022);
			linefeed(handle);
			}
		}
	fprintf(handle,"</table>");
	linefeed(handle);
	return;
}

private	void	generate_html( FILE * handle,struct form_item * iptr )
{
	int	bytes=0;
	int	i;
	char * sptr;
	switch ((iptr->Contents.style&_FRAME_TYPE)) {	
		case	_FILL_FRAME	:
			check_open_cell(handle);
			break;

		case	_INSET_FRAME	:
			check_open_cell(handle);
			break;

		case	_OUTSET_FRAME	:
			check_open_cell(handle);
			break;

		case	_GROOVE_FRAME	:
			check_open_cell(handle);
			break;

		case	_RIDGE_FRAME	:
			check_open_cell(handle);
			break;

		case	_SELECT_FRAME	:
			/* check_open_cell(handle); */
			html_open_tag(handle,"select");
			html_field(handle,"name",iptr->Contents.name);
			html_close_tag(handle,"select");
			linefeed(handle);
			if ( abal_payload(iptr) ) {
				html_tag(handle,"option");
				if (( sptr = abal_payload(iptr)) != (char *) 0) {
					for ( bytes=0,i=0; *(sptr+i) != 0; i++ ) {
						if ( *(sptr+i) == '|' ) {
							if ( bytes ) {
								hbuffer[bytes++] = 0;
								html_text(handle,hbuffer);
								bytes=0;
								}
							linefeed(handle);
			 				html_tag(handle,"option");
							}
						else	{
							hbuffer[bytes++] = *(sptr+i);
							}
						}
					if ( bytes ) {
						hbuffer[bytes++] = 0;
						html_text(handle,hbuffer);
						bytes=0;
						}
					}
				linefeed(handle);
				}
			html_closure(handle,"select");
			linefeed(handle);
			break;

		case	_FORM_FRAME	:
			html_form_widget(handle,iptr);
			break;

		case	_EDIT_FRAME	:
			/* check_open_cell(handle); */
			calculate_edit_size( &iptr->Contents );
			html_open_tag(handle,"input");
			html_field(handle,"type","text");
			html_field(handle,"name",iptr->Contents.name);
			html_int_field(handle,"size",
				( iptr->Contents.size != 0 ? iptr->Contents.size : 16 ));
			html_field(handle,"value"," ");
			html_close_tag(handle,"input");
			linefeed(handle);
			break;

		case	_TEXT_FRAME	:
			/* check_open_cell(handle); */
			html_text( handle,abal_payload(iptr) );
			break;

		case	_LINE_FRAME	:
			check_open_cell(handle);
			break;

		case	_IMAGE_FRAME	:
			/* check_open_cell(handle); */
			fprintf(handle,"<img src=%c%s%c width=%u height=%u>",0x0022,abal_payload(iptr),0x0022,iptr->Contents.w,iptr->Contents.h);
			linefeed(handle);
			break;

		case	_BUTTON_FRAME	:
			/* check_open_cell(handle); */
			switch ( iptr->Contents.datatype ) {
				case _WIDGET_OVERLAY :
				case _WIDGET_CHAIN   :
				case _WIDGET_SYSTEM  :
				case _WIDGET_LOADGO  :
					html_anchor(handle,iptr->Contents.format,abal_payload(iptr));
					break;
				case _WIDGET_MODULE  :
				default		     :
					html_open_tag(handle,"input");
					html_field(handle,"type","submit");
					html_field(handle,"name",iptr->Contents.name);
					html_int_field(handle,"size",
						( iptr->Contents.size != 0 ? iptr->Contents.size : 16 ));
					html_field(handle,"value",abal_payload(iptr));
					html_close_tag(handle,"input");
					linefeed(handle);
				}
			break;

		case	_GRAPH_FRAME	:
			break;
		case	_SWITCH_FRAME	:
		case	_CHECK_FRAME	:
			/* check_open_cell(handle); */
			html_open_tag(handle,"input");
			html_field(handle,"type","checkbox");
			html_field(handle,"name",iptr->Contents.name);
			html_close_tag(handle,"input");
			fprintf(handle, " %s ",abal_payload(iptr));
			linefeed(handle);
			break;

		case	_RADIO_FRAME	:
			/* check_open_cell(handle); */
			html_open_tag(handle,"input");
			html_field(handle,"type","radio");
			html_field(handle,"name",iptr->Contents.name);
			html_close_tag(handle,"input");
			fprintf(handle, " %s ",abal_payload(iptr));
			linefeed(handle);
			break;

		case	_TAB_FRAME	:
			check_open_cell(handle);
			istack[++stackitems] = _TAB_FRAME;
			html_open_tag(handle,"table");
			html_int_field(handle,"border",1);
			html_close_tag(handle,"table");
			linefeed(handle);
			html_tag(handle,"caption");
			html_text(handle,abal_payload(iptr));
			html_closure(handle,"caption");
			linefeed(handle);
			break;

		case	_WINDOW_FRAME	:
			check_open_cell(handle);
			istack[++stackitems] = _WINDOW_FRAME;
			html_div(handle, iptr->Contents.align & 0x0007 );
			fprintf(handle,"<table border=1 width=%u height=%u>",iptr->Contents.w,iptr->Contents.h);
			fprintf(handle,"<tr><td align=left height=24 bgcolor=navy>");
			html_text(handle,abal_payload(iptr));
			fprintf(handle,"<tr><td bgcolor=silver>");
			linefeed(handle);
			fprintf(handle,"<table border=1>");
			linefeed(handle);
			break;

		}
	return;
}

public	void	html_paragraph( FILE * handle, char * message )
{
	html_text( handle, message );
	html_tag(handle,"p");
	linefeed(handle);
	return;

}

public	void	html_open_map( FILE * h, char * target )
{
	linefeed(h);
	fprintf(h,"<map name=%c%s%c>",0x0022,target,0x0022);
	linefeed(h);
	return;
}

public	void	html_close_map( FILE * h)
{
	fprintf(h,"</map>");
	linefeed(h);
	return;
}

public	void	html_area( FILE * handle, char * target, int x, int y, int w, int h )
{
	fprintf(handle,"<area type=rect href=%c#",0x0022);
	html_anchor_trigger(handle,target);
	fprintf(handle,"%c coords=%c%u,%u,%u,%u%c>",
			0x0022,0x0022,x,y,x+w,y+h,0x0022);
	linefeed(handle);
	return;
}

public	void	html_anchor_trigger( FILE * h, char * target )
{
	if (!( target ))
		return;
	for ( ; *target != 0; target++ ) {
		if ( *target == '&' )
			continue;
		else	fprintf(h,"%c",(*target & 0x00FF));
		}
	return;
}

public	void	html_anchor_name( FILE * h, char * target )
{
	fprintf(h,"<a name=%c",0x0022);
	html_anchor_trigger(h,target);
	fprintf(h,"%c>",0x0022);
	linefeed(h);
	return;
}

public	void	open_html_definition_list( FILE * h)
{
	linefeed(h);
	html_tag(h,"dl");
	linefeed(h);
	return;
}

public	void	html_definition(FILE * h, char * n, char * d )
{
	html_tag (h,"dt class=type");
	if ( n ) {  
		html_anchor_name(h,n);
		html_tag(h,"b"); html_trigger(h,n); html_closure(h,"b"); 
		html_closure(h,"a"); 
		}
	linefeed(h);
	html_tag (h,"dd class=data"); 
	if (d)	{
		html_text(h,d); 
		html_tag(h,"p");
		}
	linefeed(h);
	return;
}

public	void	close_html_definition_list( FILE * h)
{
	linefeed(h);
	html_closure(h,"dl");
	linefeed(h);
	return;
}


public	void	html_close_toc( FILE * handle )
{
	linefeed(handle);
	html_closure(handle,"ol");
	html_closure(handle,"td");
	linefeed(handle);
	html_closure(handle,"table");
	html_closure(handle,"div");
	html_tag(handle,"p");
	linefeed(handle);
	return;
}

public	void	html_add_toc_item( FILE * handle, char * target, char * message )
{
	html_tag(handle,"li");
	html_anchor(handle,target,message);
	html_tag(handle,"br");
	linefeed(handle);
	return;
}

public	void	html_open_toc( FILE * handle )
{
	html_tag(handle,"p");
	
	html_open_tag( handle, "div" );
		html_field( handle, "align", "center" );
		html_close_tag( handle, "div" );
		linefeed(handle);

	html_open_tag( handle, "table" );
		html_field( handle, "class", "TOC" );
		html_close_tag( handle, "table" );
		linefeed(handle);

	html_tag(handle,"tr");
		html_tag(handle,"th");
		html_heading(handle,2,"Table Of Contents");
		linefeed(handle);

	html_tag(handle,"tr");
		html_tag(handle,"td");
		html_tag(handle,"ol");
		linefeed(handle);
	return;
}

public	void	html_open_section( FILE * handle, char * target, char * message,char * iname )
{
	html_target(handle,target);
	linefeed(handle);
	html_tag(handle,"p");
	linefeed(handle);
	html_open_tag( handle, "div" );
		html_field( handle, "align", "center" );
		html_close_tag( handle, "div" );
		linefeed(handle);

	html_open_tag( handle, "table" );
		html_field( handle, "class", "DS" );
		html_close_tag( handle, "table" );
		linefeed(handle);

	html_tag(handle,"tr");
		html_tag(handle,"th");
		html_heading(handle,2,message);
		linefeed(handle);

	html_tag(handle,"tr");
		html_tag(handle,"td");
		html_tag(handle,"p");
		if ( iname != (char *) 0 ) {
			html_open_tag( handle, "div" );
				html_field( handle, "align", "center" );
				html_close_tag( handle, "div" );
			html_image( handle, iname, message );
			html_closure( handle, "div" );
			html_tag(handle,"p");
			linefeed(handle);
		}
	
	html_tag(handle,"tr");
		html_tag(handle,"td");
		linefeed(handle);

	return;
}

public	void	html_close_section( FILE * handle, char * target, char * message )
{
	linefeed(handle);
	html_closure(handle,"td");
	linefeed(handle);
	html_closure(handle,"table");
	html_closure(handle,"div");
	html_tag(handle,"p"); 
	linefeed(handle);
	return;
}

public	int	close_html_document( FILE * handle,	char *	footer )
{
	char * sptr;
	
	linefeed(handle);
	html_tag(handle,"p");

	if ( not_blank( footer ) ) {
		html_open_tag( handle, "div" );
			html_field( handle, "align", "center" );
			html_close_tag( handle, "div" );
			linefeed(handle);
			html_open_tag( handle, "table" );
			html_field( handle, "class", "CRT" );
			html_close_tag( handle, "table" );
			linefeed(handle);
			html_tag(handle,"tr");
			html_tag(handle,"th");
			html_heading( handle, 3, footer );		

		html_closure(handle,"table");
		html_closure(handle,"div");
		html_tag(handle,"p");
		linefeed(handle);
		}

	// </BODY> 

	html_closure(handle,"body");

	// </HTML>

	html_closure(handle,"html");	linefeed(handle);

	return(1);
}

public	int	close_html_frameset( FILE * handle )
{
	char * sptr;
	
	linefeed(handle);

	// </FRAMESET> 

	html_closure(handle,"body");

	// </HTML>

	html_closure(handle,"html");	linefeed(handle);

	return(1);
}

public	void	html_link_style(
		FILE * handle,	
		char * url,
		char * media)

{
	char	*	sptr;

	if (!( sptr = url ))
		sptr = _DEFAULT_STYLE;
	else if ( is_blank( sptr ))
		sptr = _DEFAULT_STYLE;

	html_open_tag(handle,"link");
		html_field(handle,"href",sptr);
		html_field(handle,"type","text/css");
		html_field(handle,"rel","stylesheet");
		if ( not_blank( media ) ) {
			html_field(handle,"media",media);
			}
	html_close_tag(handle,"link");			linefeed(handle);
	return;
}


public	int	html_frame(
		FILE * 	handle,	
		char * 	url,
		char * 	name,
		int	border,
		int	margins,
		int 	scrolling )
{
	html_open_tag(handle,"frame");
	html_field(handle,"name",name);
	html_field(handle,"src",url);
	html_int_field(handle,"marginwidth",margins);
	html_int_field(handle,"marginheight",margins);
	if ( scrolling )
		html_field(handle,"scrolling","yes");
	else	html_field(handle,"scrolling","no");
	if ( border )
		html_field(handle,"frameborder","1");
	else	html_field(handle,"frameborder","0");
	html_close_tag(handle,"frame");
	linefeed(handle);
	return(1);	
}


public	int	html_frameset(
		FILE * handle,	
		int	direction,
		char *	descriptor )
{
	html_open_tag(handle,"frameset");
	if (!( direction ))
		html_field(handle,"cols",descriptor);
	else	html_field(handle,"rows",descriptor);
	html_close_tag(handle,"frameset");
	linefeed(handle);
	return(1);
}

public	int	start_html_document(
		FILE * handle,	
		char *	title, 
		char *  logo,
		char *	sstyle,
		char *	pstyle
		)
{

	// <HTML> <HEAD>

	html_tag(handle,"html");
	html_tag(handle,"head");	linefeed(handle);

	// META HTTP EQUIV

	html_open_tag(handle,"meta");
		html_field(handle,"http-equiv","Content-Type");
		html_field(handle,"content","text/html; charset=iso-8859-1");
	html_close_tag(handle,"meta");			linefeed(handle);

	// META GENERATOR

	html_open_tag(handle,"meta");
		html_field(handle,"name","generator");
		html_field(handle,"content","Amenesik / Sologic Sing Html Version 1.0a");
	html_close_tag(handle,"meta");			linefeed(handle);

	// META VERSION

	html_open_tag(handle,"meta");
		html_field(handle,"name","version");
		html_field(handle,"content",LaPaterne);
	html_close_tag(handle,"meta");			linefeed(handle);

	// LINK STYLE

	html_link_style(handle, sstyle, "screen");
	html_link_style(handle, pstyle, "print");

	// TITLE

	if ( not_blank( title ) ) {
		html_tag(handle,"title");
			html_text( handle, title );
		html_closure(handle,"title");			linefeed(handle);
		}

	// </HEAD> <BODY>

	html_closure(handle,"head"); 

	html_tag(handle,"body");			linefeed(handle);

	if ( not_blank( title ) ) {
		html_open_tag( handle, "div" );
			html_field( handle, "align", "center" );
		html_close_tag( handle, "div" );
		linefeed(handle);

		html_open_tag( handle, "table" );
			html_field( handle, "class", "DOC" );
		html_close_tag( handle, "table" );
		linefeed(handle);

		html_tag(handle,"tr");
		html_tag(handle,"th");
		html_heading( handle, 1, title );		

		if ( not_blank( logo ) ) {
			html_tag(handle,"td");
			html_open_tag( handle, "div" );
				html_field( handle, "align", "center" );
			html_close_tag( handle, "div" );
			html_image( handle, logo, (char *) 0 );		
			html_closure(handle,"div");
			}

		html_closure(handle,"table");
		html_closure(handle,"div");
		html_tag(handle,"p");	
		linefeed(handle);
		}
	else if ( not_blank( logo ) ) {
		html_open_tag( handle, "div" );
			html_field( handle, "align", "center" );
			html_close_tag( handle, "div" );
			linefeed(handle);
		html_image( handle, logo, (char *) 0 );		
		html_closure(handle,"div");
		html_tag(handle,"p");	
		linefeed(handle);
		}

	return(1);
}

public	int	start_html_frameset(
		FILE * handle,	
		char *	title, 
		int	mode,
		char *  layout,
		char *	sstyle,
		char *	pstyle
		)
{

	// <HTML> <HEAD>

	html_tag(handle,"html");
	html_tag(handle,"head");	linefeed(handle);

	// META HTTP EQUIV

	html_open_tag(handle,"meta");
		html_field(handle,"http-equiv","Content-Type");
		html_field(handle,"content","text/html; charset=iso-8859-1");
	html_close_tag(handle,"meta");			linefeed(handle);

	// META GENERATOR

	html_open_tag(handle,"meta");
		html_field(handle,"name","generator");
		html_field(handle,"content","Amenesik / Sologic Sing Html Version 1.0a");
	html_close_tag(handle,"meta");			linefeed(handle);

	// META VERSION

	html_open_tag(handle,"meta");
		html_field(handle,"name","version");
		html_field(handle,"content",LaPaterne);
	html_close_tag(handle,"meta");			linefeed(handle);

	// LINK STYLE

	html_link_style(handle, sstyle, "screen");
	html_link_style(handle, pstyle, "print");

	// TITLE

	if ( not_blank( title ) ) {
		html_tag(handle,"title");
			html_text( handle, title );
		html_closure(handle,"title");			linefeed(handle);
		}

	// </HEAD> 

	html_closure(handle,"head"); 

	// <FRAMESET>
	html_frameset(handle,mode,layout);

	return(1);
}

public	void	export_html_menu( FILE * handle )
{
	if ( start_html_document( 
			handle, 
			"Sing Html Menu", 
			(char*) 0, (char *) 0, (char *) 0) != 0 )
		(void) close_html_document( handle, "Copyright (c) 2002,2006 Amenesik / Sologic ");
	return;
}


private	void	add_row_before( struct sort_row * lptr, struct sort_item * sptr )
{
	struct	sort_row * rptr;
	if (!( rptr = allocate( sizeof( struct sort_row ) ))) {
		liberate( sptr );
		return;
		}
	SortMan.rowcount += 1;
	rptr->lock = 0;
	rptr->columns = 1;
	rptr->y  = rptr->h = 0;
	rptr->previous = rptr->next = (struct sort_row  *) 0;
	rptr->first    = rptr->last = sptr;

	if (!( rptr->previous = lptr->previous ))
		SortMan.firstrow = rptr;
	else	rptr->previous->next = rptr;
	
	if (!( rptr->next = lptr ))
		SortMan.lastrow = rptr;
	else 	rptr->next->previous = rptr;
	
	return;
}

private	struct sort_row * add_row_after( struct sort_row * lptr, struct sort_item * sptr )
{
	struct	sort_row * rptr;
	if (!( rptr = allocate( sizeof( struct sort_row ) ))) {
		liberate( sptr );
		return(rptr);
		}
	rptr->lock = 0;
	SortMan.rowcount += 1;
	rptr->columns = 1;
	rptr->y  = rptr->h = 0;
	rptr->previous = rptr->next = (struct sort_row  *) 0;
	rptr->first    = rptr->last = sptr;

	if (!( rptr->previous = lptr ))
		SortMan.firstrow = rptr;
	else	lptr->next = rptr;
	return( rptr );
}

private	void	add_to_row( struct sort_row * rptr, struct sort_item * sptr )
{
	struct	form_item *iptr;
	struct	form_item *wptr;
	struct	sort_item *cptr;
	iptr = sptr->widget;
	for ( cptr=rptr->first; cptr != (struct sort_item *) 0; cptr = cptr->next ) {
		if (!( wptr = cptr->widget ))
			continue;
		else if ( iptr->Contents.x < wptr->Contents.x ) {
			if (!( sptr->previous = cptr->previous ))
				rptr->first = sptr;
			else	sptr->previous->next = sptr;
			sptr->next = cptr;
			cptr->previous = sptr;
			return;
			}
		}
	if (!( sptr->previous = rptr->last ))
		rptr->last = sptr;
	else	rptr->last->next = sptr;
	rptr->last = sptr;
	rptr->columns++;
	if ( rptr->columns > SortMan.maxcolumns )
		SortMan.maxcolumns = rptr->columns;
	return;
}
		

private	void	calculate_row_size( struct sort_row * rptr )
{
	struct	sort_item *cptr;
	struct	form_item *wptr;
	int	h;
	rptr->y = -1; rptr->h = 0;
	for ( cptr=rptr->first; cptr != (struct sort_item *) 0; cptr = cptr->next ) {
		if (!( wptr = cptr->widget ))
			continue;
		if ((wptr->Contents.style & _FRAME_TYPE) == _SELECT_FRAME)
			h = (((guifontsize(wptr->Contents.font) >> 8) & 0x00FF)+2);
		else	h = wptr->Contents.h;

		if ( rptr->y == -1 ) {
			rptr->y = wptr->Contents.y;
			rptr->h = h;
			}
		else 	{
			if ( rptr->y > wptr->Contents.y )
				rptr->y = wptr->Contents.y;
			if ((rptr->y + rptr->h) < ( wptr->Contents.y + h ))
				rptr->h = (( wptr->Contents.y + h ) - rptr->y);
			}
		}
	return;
}

private	void	adjust_for_rowspan(struct sort_row * rptr, int y, int h )
{
	struct	sort_item *cptr;
	struct	form_item *wptr;
	int	wh;
	for ( cptr=rptr->first; cptr != (struct sort_item *) 0; cptr = cptr->next ) {
		if (!( wptr = cptr->widget ))
			continue;
		switch ((wptr->Contents.style & _FRAME_TYPE )) {
			case	_SELECT_FRAME	:
				wh = (((guifontsize(wptr->Contents.font) >> 8) & 0x00FF)+2);
				break;

			case	_TEXT_FRAME	:
			case	_EDIT_FRAME	:
			case	_CHECK_FRAME	:
			case	_RADIO_FRAME	:
			case	_SWITCH_FRAME	:
			case	_BUTTON_FRAME	:
			case	_FORM_FRAME	:
				wh = wptr->Contents.h;
				break;
			default			:
				continue;
			}
		if (( y >= wptr->Contents.y)
		&& ( (y+h) <= (wptr->Contents.y+wh)))
			cptr->rowspan++;
		}
	return;
}

private	int	check_for_rowspan(struct sort_row * rptr, int y, int h )
{
	struct	sort_item *cptr;
	struct	form_item *wptr;
	int	wh;
	for ( cptr=rptr->first; cptr != (struct sort_item *) 0; cptr = cptr->next ) {
		if (!( wptr = cptr->widget ))
			continue;
		switch ((wptr->Contents.style & _FRAME_TYPE )) {
			case	_SELECT_FRAME	:
				wh = (((guifontsize(wptr->Contents.font) >> 8) & 0x00FF)+2);
				break;

			case	_TEXT_FRAME	:
			case	_EDIT_FRAME	:
			case	_CHECK_FRAME	:
			case	_RADIO_FRAME	:
			case	_SWITCH_FRAME	:
			case	_BUTTON_FRAME	:
			case	_FORM_FRAME	:
				wh = wptr->Contents.h;
				break;
			default			:
				continue;
			}
		if ( y > (wptr->Contents.y+wh)) {
			adjust_for_rowspan(rptr,y,h);
			return(1);
			}

		}
	return(0);
}

private	void	calculate_colspan( struct sort_item * sptr )
{
	struct	form_item *wptr;
	struct	form_item *xptr;
	struct	sort_item *iptr;
	struct	sort_row  *rptr;
	int	items=0;
	if (!( wptr = sptr->widget ))
		return;
	for ( 	rptr = SortMan.firstrow;
		rptr != ( struct sort_row *) 0;
		rptr = rptr->next ) {
		if ( rptr->lock )
			continue;
		for (	items=0,iptr = rptr->first;
			iptr != (struct sort_item *) 0;
			iptr = iptr->next ) {
			if (!( xptr = iptr->widget ))
				continue;
			if (( xptr->Contents.x >= wptr->Contents.x )
			&&  ( (xptr->Contents.x+xptr->Contents.w) <= (wptr->Contents.x+wptr->Contents.w)))
				items += 1;

			}
		if ( items > sptr->colspan )
			sptr->colspan=items;
		}
	return;
}

private	void	check_for_colspan()
{
	struct	sort_item *sptr;
	struct	sort_row  *rptr;
	for ( 	rptr = SortMan.firstrow;
		rptr != ( struct sort_row *) 0;
		rptr = rptr->next ) {
		rptr->lock=1;
		for (	sptr = rptr->first;
			sptr != (struct sort_item *) 0;
			sptr = sptr->next ) {
			calculate_colspan( sptr );
			}
		rptr->lock=0;
		}
	return;
}


public	void	add_sort_item(struct form_item * iptr)
{
	struct	sort_item *sptr;
	struct	sort_row  *rptr;
	int	h;

	if (!( iptr ))
		return;
	switch ((iptr->Contents.style & _FRAME_TYPE )) {
		case	_SELECT_FRAME	:
			h = (((guifontsize(iptr->Contents.font) >> 8) & 0x00FF)+2);
			break;

		case	_TEXT_FRAME	:
		case	_EDIT_FRAME	:
		case	_CHECK_FRAME	:
		case	_RADIO_FRAME	:
		case	_SWITCH_FRAME	:
		case	_BUTTON_FRAME	:
		case	_FORM_FRAME	:
			h = iptr->Contents.h;
			break;
		default			:
			return;
		}

	if (!( sptr = allocate( sizeof( struct sort_item ) ) ))
		return;
	else	{
		sptr->colspan  = sptr->rowspan = 1;
		sptr->previous = sptr->next =(struct sort_item *) 0;
		sptr->widget   = iptr;
		for ( 	rptr = SortMan.firstrow;
			rptr != ( struct sort_row *) 0;
			rptr = rptr->next ) {

			if ( iptr->Contents.y == rptr->y ) {
				add_to_row( rptr, sptr );
				calculate_row_size( rptr );
				return;
				}
			else if ( iptr->Contents.y > rptr->y ) {
				if ( iptr->Contents.y < ( rptr->y + rptr->h)) {
					if (!( check_for_rowspan( rptr, iptr->Contents.x,h ))) {
						add_to_row( rptr, sptr );
						calculate_row_size( rptr );
						}
					else 	{
						SortMan.lastrow = add_row_after(SortMan.lastrow,sptr);
						calculate_row_size( SortMan.lastrow );
						}
					return;
					}
				}
			else if ( iptr->Contents.y < rptr->y ) {
				if (( iptr->Contents.y + h ) < rptr->y ) {
					add_row_before(rptr,sptr);
					calculate_row_size( rptr->previous );
					return;
					}
				else	{
					add_to_row( rptr, sptr );
					calculate_row_size( rptr );
					return;
					}
				}
			}
		SortMan.lastrow = add_row_after(SortMan.lastrow,sptr);
		calculate_row_size( SortMan.lastrow );
		return;
		}
}
		
private	void	drop_sort_items()
{
	struct sort_row  * rptr;
	struct sort_item * sptr;
	while ((rptr = SortMan.firstrow) != (struct sort_row *) 0) {
		SortMan.firstrow = rptr->next;
		while ((sptr = rptr->first) != (struct sort_item *) 0) {
			rptr->first = sptr->next;
			liberate( sptr );
			}
		liberate( rptr );
		}
	SortMan.maxcolumns = SortMan.rowcount = 0;
	SortMan.firstrow = SortMan.lastrow = (struct sort_row *) 0;
	return;
}		

private	int	generate_sort_items(FILE * h)
{
	int	items=0;
	struct sort_row  * rptr;
	struct sort_item * sptr;
	for (	rptr = SortMan.firstrow;
		rptr != (struct sort_row *) 0;
		rptr = rptr->next ) {
		linefeed(h);
		fprintf(h,"<tr>");
		for (	sptr = rptr->first;
			sptr != (struct sort_item *) 0;
			sptr = sptr->next ) {
			linefeed(h);
			fprintf(h,"<td");
			if ( sptr->rowspan > 1 )
				fprintf(h," rowspan=%u",sptr->rowspan);
			if ( sptr->colspan > 1 )
				fprintf(h," colspan=%u",sptr->colspan);
			fprintf(h,">");
			generate_html(h,sptr->widget);
			items++;
			}
		}
	return(items);
}		

public	void	html_form_body( FILE * handle, int mode )
{
	struct form_item * iptr;
	stackitems = 0;

	if (!( start_html_document(
			handle, Context.Form->identifier, 
			(char *) 0,	
			Context.Form->stylesheet,
			Context.Form->stylesheet
			 ) ))
		return;

	drop_sort_items();

	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else if (iptr->Contents.events.xo_show & _EVENT_IS_COND )
			continue;
		else	add_sort_item( iptr );
		}

	check_for_colspan();

	if (!(  generate_sort_items( handle ) )) {
		for (	iptr=Context.Form->first; 
			iptr != (struct form_item *) 0; 
			iptr = iptr->next )  {
			if ((!( iptr->Contents.w  ))
			||  (!( iptr->Contents.h  )))
				continue;
			else if (iptr->Contents.events.xo_show & _EVENT_IS_COND )
				continue;
			else 	generate_html(handle,iptr);
			}
		}

	while ( stackitems ) {
		switch (( istack[stackitems--] & _FRAME_TYPE )) {
			case	_INSET_FRAME :
			case	_OUTSET_FRAME :
			case	_GROOVE_FRAME :
			case	_RIDGE_FRAME :
			case	_TAB_FRAME :
				html_closure(handle,"table");
				break;
			case	_WINDOW_FRAME :
				html_closure(handle,"table");
				html_closure(handle,"table");
				html_closure(handle,"div");
				break;
			}
		}

	(void) close_html_document( handle, _DEFAULT_FOOTER );

	return;

}

public	void	html_form_page( FILE * handle, struct form_item * pptr, struct form_item * wptr )
{
	struct form_item * iptr;
	stackitems = 0;

	if (!( start_html_document(
			handle, 
			(char *) 0,
			(char *) 0,	
			Context.Form->stylesheet,
			Context.Form->stylesheet
			 ) ))
		return;

	if ( wptr ) {
		html_div(handle,wptr->Contents.align);
		fprintf(handle,"<table class=tabpage width=%u height='100%'>",wptr->Contents.w);
		linefeed(handle);
		}

	drop_sort_items();

	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else if ((iptr->Contents.style & _FRAME_TYPE) == _TAB_FRAME)
			continue;
		else if (iptr->Contents.events.xo_show & _EVENT_IS_COND )
			continue;
		else if ( pptr->Contents.page ==  iptr->Contents.page )
			add_sort_item( iptr );
		}

	check_for_colspan();

	if (!(  generate_sort_items( handle ) )) {

		for (	iptr=Context.Form->first; 
			iptr != (struct form_item *) 0; 
			iptr = iptr->next )  {
			if ((!( iptr->Contents.w  ))
			||  (!( iptr->Contents.h  )))
				continue;
			else if (!( pptr->Contents.page ))
				generate_html(handle,iptr);
			else if ((iptr->Contents.style & _FRAME_TYPE) == _TAB_FRAME)
				continue;
			else if (iptr->Contents.events.xo_show & _EVENT_IS_COND )
				continue;
			else if ( pptr->Contents.page ==  iptr->Contents.page )
				generate_html(handle,iptr);
			}
		}

	while ( stackitems ) {
		switch (( istack[stackitems--] & _FRAME_TYPE )) {
			case	_INSET_FRAME :
			case	_OUTSET_FRAME :
			case	_GROOVE_FRAME :
			case	_RIDGE_FRAME :
			case	_TAB_FRAME :
				html_closure(handle,"table");
				break;
			case	_WINDOW_FRAME :
				html_closure(handle,"table");
				html_closure(handle,"table");
				html_closure(handle,"div");
				break;
			}
		}

	if ( wptr ) {
		fprintf(handle,"</table></div>");
		linefeed(handle);
		}
	(void) close_html_document( handle, _DEFAULT_FOOTER );

	return;

}

public	void	html_form_frame( FILE * handle, struct form_item * iptr,struct form_item * wptr)
{
	if (!( iptr ))
		return;

	html_form_page( handle, iptr, wptr );
	return;

}

public	void	html_form_frameset( FILE * handle, int mode )
{
	FILE *	wh=(FILE *) 0;
	struct form_item * iptr=(struct form_item *)0;
	struct form_item * wptr=(struct form_item *)0;
	int	started=0;
	stackitems = 0;

	/* FRAMESET MASTER PAGE */
	/* -------------------- */

	if (!( start_html_frameset(
			handle, Context.Form->identifier, 
			1,"15%,85%",
			Context.Form->stylesheet,
			Context.Form->stylesheet
			 ) ))
		return;

	sprintf(hbuffer,"root_%s",Context.Form->prodname);
	html_frame( handle, hbuffer, "root",0,0,mode );
	sprintf(hbuffer,"page1_%s",Context.Form->prodname);
	html_frame( handle, hbuffer, "page",0,0,mode );

	(void) close_html_frameset( handle );

	/* FRAMESET ROOT FRAME PAGE */
	/* ------------------------ */

	sprintf(hbuffer,"root_%s",Context.Form->prodname);
	if (( wh = open_production_target(hbuffer,0)) != (FILE *) 0) {

		if (!( start_html_document(
				wh, 
				(char *) 0,
				(char *) 0,	
				Context.Form->stylesheet,
				Context.Form->stylesheet
				 ) )) {
			close_production_target(wh,hbuffer);
			return;
			}

		for (	iptr=Context.Form->first; 
			iptr != (struct form_item *) 0; 
			iptr = iptr->next )  {
			if ((!( iptr->Contents.w  ))
			||  (!( iptr->Contents.h  )))
				continue;
			else if ((iptr->Contents.style & _FRAME_TYPE) != _TAB_FRAME) {
				if ((iptr->Contents.style & _FRAME_TYPE) == _WINDOW_FRAME)
					wptr = iptr;
				continue;
				}
			if (!( started )) {
				if ( wptr ) {
					html_heading(wh,3,Context.Form->identifier);
					html_div(wh, wptr->Contents.align & 0x0007 );
					fprintf(wh,"<table class=tabhead width=%u>",wptr->Contents.w);
					fprintf(wh,"<tr>");
					linefeed(wh);
					}
				else	fprintf(wh,"<table class=tabhead><tr>");
				started++;				
				}			
			linefeed(wh);
			fprintf(wh,"<th class=tabview>");
			sprintf(hbuffer,"page%u_%s",iptr->Contents.page,Context.Form->prodname);
			html_frame_target_anchor(wh,hbuffer,"page",abal_payload(iptr));
			}
		if ( started ) {
			if ( wptr )  {
				linefeed(wh);
				fprintf(wh,"</table>");
				fprintf(wh,"</div>");
				linefeed(wh);
				}
			else	{
				linefeed(wh);
				fprintf(wh,"</table>");
				}
			started=0;
			}
		(void) close_html_document( wh, _DEFAULT_FOOTER );
		sprintf(hbuffer,"root_%s",Context.Form->prodname);
		close_production_target(wh,hbuffer);
		}

	/* FRAMESET PAGE FRAMES */
	/* -------------------- */

	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else if ((iptr->Contents.style & _FRAME_TYPE) != _TAB_FRAME) 
			continue;
		else	{
			sprintf(hbuffer,"page%u_%s",iptr->Contents.page,Context.Form->prodname);
			if (( wh = open_production_target(hbuffer,0)) != (FILE *) 0) {
				html_form_frame(wh,iptr,wptr);
				sprintf(hbuffer,"page%u_%s",iptr->Contents.page,Context.Form->prodname);
				close_production_target(wh,hbuffer);
				}
			}
		}
	return(1);

}

public	void	export_html_form( FILE * handle, int mode )
{
	struct form_item * iptr;
	stackitems = 0;

	if ( Context.Form->pages != 0 ) 
		html_form_frameset(handle,mode);
	else	html_form_body    (handle,mode);

}
		
public	void	use_navigator( char * filename )
{
	if (!(visual_help( filename )))
		draw_console();
	return;
}

public	int	use_html_navigator(char * aptr, int automatic)
{
	char	*	sptr;
	char	*	command;
	int		alen=0;
	char		xbuffer[64];

	if (!( fn_parser( aptr, xbuffer, 0x0010 ) ))
		return(0);
	if ((!( upper_compare( xbuffer, ".HTM"  ) ))
	&&  (!( upper_compare( xbuffer, ".HTML" ) )))
		return(0);
	else	{
		use_navigator( aptr );
		return(1);
		}

}


