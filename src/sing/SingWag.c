#ifndef	_singwag_c
#define	_singwag_c

int	ActiveAgentImages=1;
int	decalagex=0;
int	decalagey=0;

#define	_SING_APPLICATION_WINDOW "toolbar=no,menubar=no,resizeable=no,statusbar=1"
#define	_SING_BROWSER_WINDOW	 "toolbar=1,menubar=1,scrollbars=1,location=1,resizeable=1,statusbar=1,scrollbars=1"

#include "vstyle.h"

private	void	simple_area_over_and_out( FILE * h, struct form_item * iptr );
private	void	prefix_javascript_widget_create( FILE * h, struct form_control * fptr, char * prefix, int page );
private	void	prefix_javascript_widget_events( FILE * h, struct form_control * fptr, int oldmode, char * prefix );
private	void	prefix_simple_form_style( FILE * h, struct form_control * fptr, int wx, int wy, int pageid, char * prefix );
private	int	prefix_simple_widget_cells(  FILE * h, struct form_control * fptr, int pageid, char * prefix );

private	char *	current_widget_prefix="\0";
private	char	PrefixedWidget[256];
private	char *	set_widget_prefix(char * sptr)
{
	char * rptr=current_widget_prefix;
	current_widget_prefix = sptr;
	return( rptr );
}

private	char *	prefixed_widget_name( struct form_item * iptr )
{
	if (!( iptr ))
		return("\0");
	else if (!( iptr->Contents.name ))
		return("\0");
	else	{
		sprintf(PrefixedWidget,"%s%s",current_widget_prefix,iptr->Contents.name);
		return( PrefixedWidget );
		}
}


private	int	simple_js_event( struct form_item * iptr )
{
	int	jsevent=0;

	if (( iptr->Contents.events->xo_event & _EVENT_IS_OTHER ) &&  ( method_is_valid( iptr->Contents.events->on_event ) ))
		jsevent=1;
	else	jsevent=0;

	if ( method_is_valid( iptr->Contents.events->on_lose_focus ) )
		jsevent |=2;

	return( jsevent );
}

private	int	simple_preload_event( FILE * h, char * iname )
{
	if (!( h ))
		return(50);
	else if ( iname ) {
		fprintf(h," onload=%c_SingPreloadImages('%s')%c",__QUOTE,iname,__QUOTE);
		}
	return(0);
}

private	void	js_close_method(h)
{
	indent(h,1); fprintf(h,"}"); linefeed(h);
	return;
}

private	int	javascript_image_preload( FILE * h )
{
	if (!( h ))	return(50);

	linefeed(h); 
	fprintf(h,"function _SingPreloadImages() {");
 	linefeed(h); 
		indent(h,1);  fprintf(h,"var d=document;"); linefeed(h);
		indent(h,1);  fprintf(h,"if(d.images) {"); linefeed(h);
			indent(h,2);  fprintf(h,"if(!d.WPI) { d.WPI=new Array(); }"); linefeed(h);
			indent(h,2);  fprintf(h,"var i,j=d.WPI.length,a=WasaPreloadImages.arguments;"); linefeed(h);
			indent(h,2);  fprintf(h,"for(i=0; i<a.length; i++) {"); linefeed(h);
				indent(h,3);  fprintf(h,"if (a[i].indexOf(%c#%c)!=0) {",__QUOTE,__QUOTE); linefeed(h);
					indent(h,4);  fprintf(h,"d.WPI[j]=new Image;"); linefeed(h);
 					indent(h,4);  fprintf(h,"d.WPI[j++].src=a[i];");linefeed(h);
					indent(h,4); fprintf(h,"}"); linefeed(h);
				indent(h,3); fprintf(h,"}"); linefeed(h);
			indent(h,2); fprintf(h,"}"); linefeed(h);
	js_close_method(h);
	return(0);
}

private	int	simple_table_events( FILE * handle,struct form_item * iptr )
{
	int	jsevent=0;

	jsevent = simple_js_event( iptr );

	/* --------------------------------------------------------------- */
	/* special hidden input members required for operation ofthe table */
	/* --------------------------------------------------------------- */
	linefeed(handle);
	if ( jsevent & 1 ) {
		html_open_tag(handle,"input");
		html_field(handle,"type","hidden");
		fprintf(handle," name=%sEvent",prefixed_widget_name(iptr));
		fprintf(handle," value=%c0,0%c",__QUOTE,__QUOTE);
		html_close_tag(handle,"input");
		linefeed(handle);
		}
	if ( jsevent & 2 ) {
		html_open_tag(handle,"input");
		html_field(handle,"type","hidden");
		fprintf(handle," name=%sLoseFocus",prefixed_widget_name(iptr));
		fprintf(handle," value=%c0,0%c",__QUOTE,__QUOTE);
		html_close_tag(handle,"input");
		linefeed(handle);
		}
	return( jsevent );
}

private	void	simple_scrollbar_sizes( struct form_item * iptr, int * iy, int * ih )
{
	if ( iptr->Contents.h > iptr->Contents.w ) {
		if (!( iptr->Contents.align & 3 )) {
			*ih = iptr->Contents.h;
			*iy = (iptr->Contents.y+2);
			}
		else if (( iptr->Contents.align & 3 ) == 3) {
			*ih = (iptr->Contents.h-(iptr->Contents.w*2));
			*iy = (iptr->Contents.y+2+iptr->Contents.w);
			}
		else	{
			*ih = (iptr->Contents.h-iptr->Contents.w);
			*iy = (iptr->Contents.y+2+iptr->Contents.w);
			}
		}
	else	{
		if (!( iptr->Contents.align & 3 )) {
			*ih = iptr->Contents.w;
			*iy = (iptr->Contents.x+2);
			}
		else if (( iptr->Contents.align & 3 ) == 3) {
			*ih = (iptr->Contents.w-(iptr->Contents.h*2));
			*iy = (iptr->Contents.x+2+iptr->Contents.h);
			}
		else	{
			*ih = (iptr->Contents.w-iptr->Contents.h);
			*iy = (iptr->Contents.x+2+iptr->Contents.h);
			}
		}
	return;
}

private	void	simple_new_scrollclick( FILE * h, struct form_item * iptr )
{
	int	zy;
	int	zs;
	simple_scrollbar_sizes( iptr, &zy, &zs );
	fprintf(h,"function %sClickEvent(e) {",prefixed_widget_name(iptr));	linefeed(h);
	indent(h,1);	fprintf(h,"var posbar  = 0;"); linefeed(h);
	indent(h,1);	fprintf(h,"var sbvalue = 0;"); linefeed(h);
	indent(h,1);	fprintf(h,"var sbmax   = <widget name=%s.max>;",prefixed_widget_name(iptr)); 
			linefeed(h);
	indent(h,1);	fprintf(h,"var sblimit = <widget name=%s.limit>;",prefixed_widget_name(iptr)); 
			linefeed(h);
	indent(h,1);	fprintf(h,"if (sbmax < sblimit) { sbmax=sblimit; }"); linefeed(h);
	indent(h,1);	fprintf(h,"if (!e) var e = window.event;"); linefeed(h);
	if ( iptr->Contents.h > iptr->Contents.w ) {
		/* vertical scrollbar */
		indent(h,1);	fprintf(h,"if (e.pageX || e.pageY) {"); linefeed(h);
		indent(h,2);	fprintf(h,"posbar = e.pageY;"); linefeed(h);
		indent(h,2);	fprintf(h,"}"); linefeed(h);
		indent(h,1);	fprintf(h,"else if (e.clientX || e.clientY) {"); linefeed(h);
		indent(h,2);	fprintf(h,"posbar = e.clientY + document.body.scrollTop"); linefeed(h);
		indent(h,2);	fprintf(h," + document.documentElement.scrollTop;"); linefeed(h);
		indent(h,2);	fprintf(h,"}"); linefeed(h);
		indent(h,1);	fprintf(h,"posbar -= %sBarTop;",prefixed_widget_name(iptr));
		linefeed(h);
		}
	else	{
		/* horizontal scrollbar */
		indent(h,1);	fprintf(h,"if (e.pageX || e.pageY) {"); linefeed(h);
		indent(h,2);	fprintf(h,"posbar = e.pageX;"); linefeed(h);
		indent(h,2);	fprintf(h,"}"); linefeed(h);
		indent(h,1);	fprintf(h,"else if (e.clientX || e.clientY) {"); linefeed(h);
		indent(h,2);	fprintf(h,"posbar = e.clientX + document.body.scrollLeft"); linefeed(h);
		indent(h,2);	fprintf(h," + document.documentElement.scrollLeft;"); linefeed(h);
		indent(h,2);	fprintf(h,"}"); linefeed(h);
		indent(h,1);	
		indent(h,1);	fprintf(h,"posbar -= %sBarTop;",prefixed_widget_name(iptr));
		linefeed(h);
		}

	indent(h,1);	fprintf(h,"if ( posbar < 0 ) { posbar=0; }");	linefeed(h);
	indent(h,1);	fprintf(h,"if ((sbvalue = Math.round((posbar * sbmax) / %u)) > (sbmax - sblimit)) { sbvalue = (sbmax-sblimit); }",zs);
			linefeed(h);
	indent(h,1);	fprintf(h,"document.forms[0].%s.value=sbvalue;",prefixed_widget_name(iptr));	linefeed(h);
	indent(h,1);	fprintf(h,"_SingChainForm('%sBar.Event');",prefixed_widget_name(iptr));		linefeed(h);
	indent(h,1);	fprintf(h,"return(false);");			linefeed(h);
	js_close_method(h);
	return;
}

private	void	simple_new_scrolldown( FILE * h, struct form_item * iptr )
{
	int	zs;
	int	zy;
	simple_scrollbar_sizes( iptr, &zy, &zs );
	fprintf(h,"var %sBarTop=%u;",prefixed_widget_name(iptr),zy); linefeed(h);
	fprintf(h,"var Is%sBarDown=0;",prefixed_widget_name(iptr));	linefeed(h);
	fprintf(h,"function %sBarDown(e,mode) {",prefixed_widget_name(iptr));	linefeed(h);
	indent(h,1);	fprintf(h,"var posbar  = 0;"); linefeed(h);
	indent(h,1);	fprintf(h,"var sbmax   = <widget name=%s.max>;",prefixed_widget_name(iptr)); 
			linefeed(h);
	indent(h,1);	fprintf(h,"var sblimit = <widget name=%s.limit>;",prefixed_widget_name(iptr)); 
			linefeed(h);
	indent(h,1);	fprintf(h,"var sbh = 0;"); linefeed(h);
	indent(h,1); 	fprintf(h,"var v = _SingLocateObject('%s_bar');",prefixed_widget_name(iptr));
			linefeed(h);
	indent(h,1);	fprintf(h,"if (sbmax < sblimit) { sbmax=sblimit; }"); linefeed(h);
	if ( iptr->Contents.h > iptr->Contents.w ) {
		indent(h,1);
		fprintf(h,"sbh = Math.round((sblimit*%u)/sbmax);",zs);
		linefeed(h);
		}
	else	{
		indent(h,1);
		fprintf(h,"sbh = Math.round((sblimit*%u)/sbmax);",zs);
		linefeed(h);
		}

	indent(h,1);	fprintf(h,"if ( mode ) { Is%sBarDown=1; }",prefixed_widget_name(iptr));
			linefeed(h);
	indent(h,1);	fprintf(h,"else if (!( Is%sBarDown )) { return(false); }",prefixed_widget_name(iptr));
			linefeed(h);

	indent(h,1);	fprintf(h,"if (!e) var e = window.event;"); linefeed(h);
	if ( iptr->Contents.h > iptr->Contents.w ) {
		/* vertical scrollbar */
		indent(h,1);	fprintf(h,"if (e.pageX || e.pageY) {"); linefeed(h);
		indent(h,2);	fprintf(h,"posbar = e.pageY;"); linefeed(h);
		indent(h,2);	fprintf(h,"}"); linefeed(h);
		indent(h,1);	fprintf(h,"else if (e.clientX || e.clientY) {"); linefeed(h);
		indent(h,2);	fprintf(h,"posbar = e.clientY + document.body.scrollTop"); linefeed(h);
		indent(h,2);	fprintf(h," + document.documentElement.scrollTop;"); linefeed(h);
		indent(h,2);	fprintf(h,"}"); linefeed(h);
		}
	else	{
		/* horizontal scrollbar */
		indent(h,1);	fprintf(h,"if (e.pageX || e.pageY) {"); linefeed(h);
		indent(h,2);	fprintf(h,"posbar = e.pageX;"); linefeed(h);
		indent(h,2);	fprintf(h,"}"); linefeed(h);
		indent(h,1);	fprintf(h,"else if (e.clientX || e.clientY) {"); linefeed(h);
		indent(h,2);	fprintf(h,"posbar = e.clientX + document.body.scrollLeft"); linefeed(h);
		indent(h,2);	fprintf(h," + document.documentElement.scrollLeft;"); linefeed(h);
		indent(h,2);	fprintf(h,"}"); linefeed(h);
		}
	indent(h,1);	fprintf(h,"if ( posbar < %sBarTop ) { posbar=0; }",prefixed_widget_name(iptr));	linefeed(h);
	
	indent(h,1);	fprintf(h,"else	{");	linefeed(h);
		indent(h,2);	fprintf(h,"posbar -= %sBarTop;",prefixed_widget_name(iptr)); linefeed(h);
		indent(h,2);	fprintf(h,"if ( posbar > (%u-sbh) ) { posbar = (%u-sbh); }",zs,zs);
		indent(h,2);	fprintf(h,"}");	linefeed(h);

	if ( iptr->Contents.h > iptr->Contents.w ) {
		indent(h,1);	
		fprintf(h,"v.style.top  = (posbar+%sBarTop);",prefixed_widget_name(iptr));	
		linefeed(h);
		}
	else	{
		indent(h,1);
		fprintf(h,"v.style.left = (posbar+%sBarTop);",prefixed_widget_name(iptr));
		linefeed(h);
		}

	if ( ActiveAgentImages ) {
		indent(h,1);
		fprintf(h,"v.style.border = '1px dotted silver';");
		linefeed(h);
		}

	indent(h,1);	fprintf(h,"return(false);");			linefeed(h);
	js_close_method(h);
	return;
}

private	void	simple_new_scrollbutton( FILE * h, struct form_item * iptr, char * button )
{
	fprintf(h,"function %s%sEvent(e) {",prefixed_widget_name(iptr),button);
	linefeed(h);
	indent(h,1);
		fprintf(h,"if (!e) var e = window.event;"); 
		linefeed(h);
	indent(h,1);
		fprintf(h,"if ( Is%sBarDown != 0 ) {",prefixed_widget_name(iptr)); 
		linefeed(h);

		indent(h,2);
			fprintf(h,"%sClickEvent(e);",prefixed_widget_name(iptr)); 
			linefeed(h);

		indent(h,2); fprintf(h,"}"); 			linefeed(h);

	indent(h,1); fprintf(h,"else\t{"); 		linefeed(h);

		indent(h,2); 
			fprintf(h,"_SingChainForm('%s%s.Event');",prefixed_widget_name(iptr),button);
			linefeed(h);
		indent(h,2); fprintf(h,"}");			linefeed(h);

	indent(h,1); fprintf(h,"return(false);");	linefeed(h);
	js_close_method(h);
	return;
}

private	void	simple_new_scrollbuttons( FILE * h, struct form_item * iptr )
{
	if ( iptr->Contents.align & 1 ) {
		simple_new_scrollbutton(h, iptr, "Up" );
		}
	if ( iptr->Contents.align & 2 ) {
		simple_new_scrollbutton(h, iptr, "Down" );
		}
	return;
}

/*	-------------------------------------------------------------		*/
/*	j a v a s c r i p t  _  a p p l i c a t i o n  _  w i n d o w 		*/
/*	-------------------------------------------------------------		*/
/*										*/
/*	Creates an exact fit, no bells, no whistles javascript window		*/
/*	of the required name, position and size. This function is of 		*/
/*	use when screen size restriction parameter has been checked 		*/
/*	in the web agent html production parameters dislog box.      		*/
/*										*/
/*	-------------------------------------------------------------		*/

private	void	javascript_application_window(
			FILE * h, 
			struct form_control * fptr, 
			struct form_item * wptr
			)
{
	fprintf(h,"function _SingApplicationWindow() {"); linefeed(h);
		javascript_reposition_window(h,wptr);
		indent(h,1); fprintf(h,"window.open('#','_SingAw_%s','",fptr->identifier);
		if ( decalagex )
			fprintf(h,"left=%u,",decalagex);
		else	fprintf(h,"left='+xoffs+',");
		if ( decalagey )
			fprintf(h,"top=%u,",decalagey);
		else	fprintf(h,"top='+yoffs+',");
		fprintf(h,"width=%u,height=%u,%s');",
			wptr->Contents.w,wptr->Contents.h,_SING_APPLICATION_WINDOW
			);
		linefeed(h);
		js_close_method(h);
		
	return;
}

/*	-------------------------------------------------------------		*/
/*	  j a v a s c r i p t  _  n a v i g a t o r  _  w i n d o w 		*/
/*	-------------------------------------------------------------		*/
/*										*/
/*	Creates a full screen window with all the bells and whistles 		*/
/*	top,left aligned of the required name.   This function is of 		*/
/*	use when screen size restriction parameter has been checked 		*/
/*	in the web agent html production parameters dislog box.      		*/
/*										*/
/*	-------------------------------------------------------------		*/
private	void	javascript_navigator_window(
			FILE * h, 
			struct form_control * fptr, 
			struct form_item * wptr
			)
{
	fprintf(h,"function _SingNavigatorWindow() {"); linefeed(h);
		indent(h,1); fprintf(h,"window.open('#','_SingNw_%s','",fptr->identifier);
		fprintf(h,"left=0,top=0,");
		fprintf(h,"width='+screen.width+',");
		fprintf(h,"height='+screen.height+'%s');",_SING_BROWSER_WINDOW);
		linefeed(h);
		js_close_method(h);
	return;
}

private	void	javascript_define_window(FILE * h, struct form_item * wptr)
{
	struct	form_control * fptr;
	if (!( wptr ))
		return;
	else if (!( fptr = wptr->parent ))
		return;	

	else	{	
		/* ------------------------------------------------------------------ */
		/* This expression gives us a handy boolean variable that we can test */
		/* to check to see if we are in a W3C DOM compatible browser or not.  */
		/* ------------------------------------------------------------------ */
		fprintf(h,"var _SingW3cDom_ = document.getElementsByTagName && document.createElement;");
		linefeed(h);

		if ( Restriction ) {

			/* ----------------------------------------------------	*/
			/* This has been a long battle ........................	*/
			/* Bernard has reminded me to document it since it is	*/
			/* an unusual bit of code.				*/	
			/* We want to run in a window of exact size without all	*/
			/* the usual bells and whistles, thats the aim anyway.	*/
			/* First problem : getting the window to the right size	*/
			/* and the right position. There are so many different	*/
			/* ways but only this one works for all browsers almost.*/
			/* Second problem getting rid of the Bells and Whistles	*/
			/* The solution to the above problems is the creation of*/
			/* a new window activetool window.open but this raises the	*/
			/* Third problem of getting rid of the original window.	*/
			/* To do so it is necessary to name it and reopen it	*/
			/* and let the use handle the window closure dialogbox	*/
			/* ---------------------------------------------------- */

			javascript_application_window(h,fptr,wptr);
			javascript_navigator_window(h,fptr,wptr);

			/* ---------------------------------------------------- */
			/* If we have not attained the desired window condition */
			/* ---------------------------------------------------- */
			fprintf(h,"if (( window.name != '_SingAw_%s') ",fptr->identifier);
			fprintf(h,"&&  ( window.name != '_SingNw_%s')) { ",fptr->identifier);
			linefeed(h);

			indent(h,1);
			fprintf(h,"if  ( window.name == '_sing_') { self.close(); }");
			linefeed(h);
			
			/* --------------------------------------------------------------- */
			/* Rename the current window and reopen it ( to make it closable ) */
			/* --------------------------------------------------------------- */
			indent(h,1); fprintf(h,"else { window.name = '_sing_'; window.open('#','_sing_'); }");
			linefeed(h);

			/* ----------------------------------------------------------- */
			/* Create the newly sized and tuned window of the desired name */ 
			/* ----------------------------------------------------------- */
			indent(h,1); fprintf(h,"_SingApplicationWindow();"); linefeed(h);

			indent(h,1);	fprintf(h,"}");	linefeed(h);

			/* ---------------------------------------------------- */
			/* 		Close the parent window. 		*/
			/*    ( this may require confirmation by the user )	*/
			/* ---------------------------------------------------- */
			fprintf(h,"else { window.opener.close(); }");
			linefeed(h);
			}
		else if ( wptr->Contents.align & _A_BOLD ) {
			javascript_navigator_window(h,fptr,wptr);
			/* -------------------------------------------------- */
			/* For the exit button to work we must open ourselves */
			/* -------------------------------------------------- */
			fprintf(h,"if ( window.name != '_SingNw_%s') {",fptr->identifier);
			indent(h,1);
			fprintf(h,"if  ( window.name == '') { ");
			linefeed(h);
			indent(h,2); fprintf(h,"window.name = '_sing_'; window.open('#','_sing_');");
			linefeed(h);
			indent(h,2); fprintf(h,"}");
			linefeed(h);
			indent(h,1); fprintf(h,"_SingNavigatorWindow();"); linefeed(h);
			fprintf(h,"} else { window.opener.close(); }");
			linefeed(h);
			}
		}
	return;
}

private	void	javascript_resize_window(FILE * h, struct form_item * wptr)
{
	if ( wptr ) {

		indent(h,1);
		fprintf(h,"if ( window.innerWidth ) {");
		linefeed(h);
			indent(h,2);
			fprintf(h,"window.innerWidth=%u;",wptr->Contents.w /* +15 */ );
			linefeed(h);
			indent(h,2);
			fprintf(h,"window.innerHeight=%u;",wptr->Contents.h /* +25 */);
			linefeed(h);
		indent(h,2);
		fprintf(h,"}");
		linefeed(h);
#ifdef	MICROSOFT_IE_HAS_NO_BUGS
		indent(h,1);
		fprintf(h,"else {");
		linefeed(h);
			indent(h,2);
			fprintf(h,"window.resizeTo(screen.width,screen.height);");
			linefeed(h);
			indent(h,2);
			fprintf(h,"var tempw=screen.width-document.body.clientWidth;");
			linefeed(h);
			indent(h,2);
			fprintf(h,"var temph=screen.height-document.body.clientHeight;");
			linefeed(h);
			indent(h,2);
			fprintf(h,"window.resizeTo(%u+tempw,%u+temph); ",wptr->Contents.w,wptr->Contents.h);
			linefeed(h);
		indent(h,2);
		fprintf(h,"}");
		linefeed(h);
#endif
		}
	return;
}

private	void	javascript_position_window(FILE * h, struct form_item * wptr)
{
	indent(h,1);
	fprintf(h,"window.moveTo(0,0);");
	linefeed(h);
	return;
}

private	void	javascript_reposition_window(FILE * h, struct form_item * wptr)
{
	if ( wptr ) {

		switch ((wptr->Contents.align & 7)) {
			case	0	:
				/* explicite x,y positioning */
				/* ------------------------- */	
				indent(h,1);
				fprintf(h,"var xoffs=%u;",decalagex);
				linefeed(h);
				indent(h,1);
				fprintf(h,"var yoffs=%u;",decalagey);
				linefeed(h);
				break;
			case	1 	:
				/* h-align right : v-align middle */
				/* ------------------------------ */
				indent(h,1);
				fprintf(h,"if ( screen.width > %u ) {",wptr->Contents.w);
				linefeed(h);
					indent(h,2);
					fprintf(h,"var xoffs=screen.width-%u;",wptr->Contents.w);
					linefeed(h);
					indent(h,2);
				indent(h,1);
				fprintf(h,"} else { var xoffs=0; } ");
				linefeed(h);
				indent(h,1);
				fprintf(h,"if ( screen.height > %u ) {",wptr->Contents.h);
				linefeed(h);
					indent(h,2);
					fprintf(h,"var yoffs=(screen.height-%u)/2;",wptr->Contents.h);
					linefeed(h);
				indent(h,2);
				fprintf(h,"} else { var yoffs=0; } ");
				linefeed(h);
				break;

			case	2 	:	
				/* h-align: left, v-align: middle */
				/* ------------------------------ */ 
				indent(h,1);
				fprintf(h,"var xoffs=%u;",decalagex);
				linefeed(h);
				indent(h,1);
				fprintf(h,"if ( screen.height > %u ) {",wptr->Contents.h);
				linefeed(h);
					indent(h,2);
					fprintf(h,"var yoffs=(screen.height-%u)/2;",wptr->Contents.h);
					linefeed(h);
				indent(h,2);
				fprintf(h,"} else { var yoffs=0; } ");
				linefeed(h);
				break;
			case	3 	:
			case	4	:
				/* justified or centered : v/h-align: center */
				/* ----------------------------------------- */
				indent(h,1);
				fprintf(h,"if ( screen.width > %u ) {",wptr->Contents.w);
				linefeed(h);
					indent(h,2);
					fprintf(h,"var xoffs=(screen.width-%u)/2;",wptr->Contents.w);
					linefeed(h);
					indent(h,2);
				indent(h,1);
				fprintf(h,"} else { var xoffs=0; } ");
				linefeed(h);
				indent(h,1);
				fprintf(h,"if ( screen.height > %u ) {",wptr->Contents.h);
				linefeed(h);
					indent(h,2);
					fprintf(h,"var yoffs=(screen.height-%u)/2;",wptr->Contents.h);
					linefeed(h);
				indent(h,2);
				fprintf(h,"} else { var yoffs=0; } ");
				linefeed(h);
				break;
			}
		}
	return;
}

private	void	old_javascript_reposition_window(FILE * h, struct form_item * wptr)
{
	if ( wptr ) {
		indent(h,1);
		fprintf(h,"if ( window.innerWidth ) {");
		linefeed(h);
		switch ((wptr->Contents.align & 7)) {
			case	0	:	
				indent(h,2);
				fprintf(h,"window.moveTo(%u,%u);",decalagex,decalagey);
				linefeed(h);
				break;

			case	1 	:
				indent(h,2);
				fprintf(h,"if ( screen.width > %u ) {",wptr->Contents.w);
				linefeed(h);
					indent(h,3);
					fprintf(h,"if ( screen.height > %u ) {",wptr->Contents.h);
					linefeed(h);
						indent(h,4);
						fprintf(h,"window.moveTo((screen.width-%u),((screen.height-%u)/2))",wptr->Contents.w,wptr->Contents.h);
						linefeed(h);
					indent(h,3);
					fprintf(h,"} else { window.moveTo((screen.width-%u),0); } ",wptr->Contents.w);
					linefeed(h);
				indent(h,2);
				fprintf(h,"} else { window.moveTo(0,((screen.height-%u)/2)); } ",wptr->Contents.h);
				linefeed(h);
				break;

			case	2 	:	
				indent(h,2);
				fprintf(h,"if ( screen.height > %u ) {",wptr->Contents.h);
				linefeed(h);
					indent(h,3);
					fprintf(h,"window.moveTo(0,((screen.height-%u)/2))",wptr->Contents.w,wptr->Contents.h);
					linefeed(h);
				indent(h,2);
				fprintf(h,"} else { window.moveTo(0,0); } ",wptr->Contents.w);
				linefeed(h);
				break;
			case	3 	:
			case	4	:
				indent(h,2);
				fprintf(h,"if ( screen.width > %u ) {",wptr->Contents.w);
				linefeed(h);
					indent(h,3);
					fprintf(h,"if ( screen.height > %u ) {",wptr->Contents.h);
					linefeed(h);
						indent(h,4);
						fprintf(h,"window.moveTo(((screen.width-%u)/2),((screen.height-%u)/2));",wptr->Contents.w,wptr->Contents.h);
						linefeed(h);
					indent(h,3);
					fprintf(h,"} else { window.moveTo(((screen.width-%u)/2),0); } ",wptr->Contents.w);
					linefeed(h);
				indent(h,2);
				fprintf(h,"} else { window.moveTo(0,((screen.height-%u)/2)); } ",wptr->Contents.h);
				linefeed(h);
				break;
			}
		indent(h,1);
		fprintf(h,"}");
		linefeed(h);
		}
	return;
}

private	void	javascript_size_window(FILE * h, struct form_item * wptr)
{
	if ( wptr ) {
		indent(h,1);
		fprintf(h,"window.resizeTo(screen.width,screen.height);");
		linefeed(h);
		}
	return;
}

private	void	javascript_hide_bars(FILE * h,struct form_item * wptr )
{
	indent(h,1);	fprintf(h,"if ( window.toolbar ) { window.toolbar.visible=false; }");
	linefeed(h);
	indent(h,1);	fprintf(h,"if ( window.menubar ) { window.menubar.visible=false; }");
	linefeed(h);
	indent(h,1);	fprintf(h,"if ( window.locationbar ) { window.locationbar.visible=false; }");
	linefeed(h);
	indent(h,1);	fprintf(h,"if ( window.personalbar ) { window.personalbar.visible=false; }");
	linefeed(h);
	indent(h,1);	fprintf(h,"if ( window.statusbar  )  { window.statusbar.visible=false;   }");
	linefeed(h);
	indent(h,1);	fprintf(h,"if ( window.scrollbars  ) { ");
	linefeed(h);
	indent(h,2);	fprintf(h,"if (( screen.width < %u ) || ( screen.height < %u )) {",
				wptr->Contents.w,wptr->Contents.h);
	linefeed(h);
	indent(h,3);		fprintf(h,"window.scrollbars.visible=true;");
	linefeed(h);
	indent(h,2);	fprintf(h,"} else { window.scrollbars.visible=false; }");
	linefeed(h);
	indent(h,1);	fprintf(h,"}");
	linefeed(h);
}	

private	void	javascript_show_bars(FILE * h)
{
	indent(h,1);	fprintf(h,"if ( window.toolbar ) { window.toolbar.visible=true; }");
	linefeed(h);
	indent(h,1);	fprintf(h,"if ( window.menubar ) { window.menubar.visible=true; }");
	linefeed(h);
	indent(h,1);	fprintf(h,"if ( window.locationbar ) { window.locationbar.visible=true; }");
	linefeed(h);
	indent(h,1);	fprintf(h,"if ( window.personalbar ) { window.personalbar.visible=true; }");
	linefeed(h);
	indent(h,1);	fprintf(h,"if ( window.scrollbars  ) { window.scrollbars.visible=true;  }");
	linefeed(h);
	indent(h,1);	fprintf(h,"if ( window.statusbar  )  { window.statusbar.visible=true;   }");
	linefeed(h);
	return;
}

private	void	javascript_history_manager(FILE * h,struct form_control * fptr)
{
	/* -------------------------------------------- */
	/* No cookie enforcement ... No history manager */
	/* -------------------------------------------- */
	if (!( fptr->weboptions & 64 ))		return;

	/* -------------------------------------------- */
	/* 	Browser History Management Functions	*/
	/* -------------------------------------------- */

	fprintf(h,"var _SingHistoryBack=false;");	linefeed(h);
	fprintf(h,"var _SingHistoryNext=false;");	linefeed(h);
	fprintf(h,"function _SingHistoryCatcher() {");		linefeed(h);
		indent(h,1);	
		fprintf(h,"return( alert('This history operation may devalidate your application session') );");	
		linefeed(h);
		js_close_method(h);

	fprintf(h,"function _SingHistoryManager() {");	linefeed(h);
		indent(h,1); fprintf(h,"_SingHistoryBack=history.back;");	linefeed(h);
		indent(h,1); fprintf(h,"_SingHistoryNext=history.forward;");	linefeed(h);
		indent(h,1); fprintf(h,"history.back=_SingHistoryCatcher;");	linefeed(h);
		indent(h,1); fprintf(h,"history.forward=_SingHistoryCatcher;");	linefeed(h);
		js_close_method(h);
	return;
}

private	void	javascript_restriction(FILE * h, struct form_item  * wptr)
{
	struct	form_control * fptr;
	if (!( wptr ))
		return;
	else if (!( fptr = wptr->parent ))
		return;

	fprintf(h,"function _SingBrowserShow() {");	linefeed(h);
		indent(h,1);	fprintf(h,"return(false);"); linefeed(h);
		js_close_method(h);
		
	if ( wptr->Contents.align & _A_LINE ) {
		fprintf(h,"function _SingBrowserHelp() {");	linefeed(h);
			indent(h,1);	fprintf(h,"return(false);"); linefeed(h);
			js_close_method(h);
		}

	if ( wptr->Contents.align & _A_BOLD ) {
		fprintf(h,"function _SingBrowserExit() {");	linefeed(h);
			indent(h,1);	fprintf(h,"window.close();"); linefeed(h);
			indent(h,1);	fprintf(h,"return(false);"); linefeed(h);
			js_close_method(h);
		}

	if ( Restriction ) {

		fprintf(h,"function _SingBrowserChange() {");	linefeed(h);
			indent(h,1);	fprintf(h,"if ( window.name == '_SingAw_%s' ) { _SingNavigatorWindow(); }",fptr->identifier);	 
			linefeed(h);
			indent(h,1);	fprintf(h,"else if ( window.name == '_SingNw_%s') { _SingApplicationWindow(); }",fptr->identifier);
			linefeed(h);
			js_close_method(h);

		}

	return;
}

private	void	javascript_on_over(FILE * h)
{
	fprintf(h,"function OnOver(v) {");					linefeed(h);
		indent(h,1);	fprintf(h,"v.style.color='blue';");		linefeed(h);
		indent(h,1);	fprintf(h,"v.style.border='1px solid black';");	linefeed(h);
		js_close_method(h);
	return;
}
			
private	void	javascript_on_out(FILE * h)
{
	fprintf(h,"function OnOut(v) {");					linefeed(h);
		indent(h,1);	fprintf(h,"v.style.color='black';");		linefeed(h);
		indent(h,1);	fprintf(h,"v.style.border='none';");		linefeed(h);
		js_close_method(h);
	return;
}

private	void	javascript_area_over(FILE * h)
{
	fprintf(h,"function AreaOver(v) {");					linefeed(h);
		indent(h,1); 	fprintf(h,"var vv = _SingLocateObject(v);");		linefeed(h);
		indent(h,1);	fprintf(h,"vv.style.color='blue';");		linefeed(h);
		indent(h,1);	fprintf(h,"vv.style.border='1px solid black';");linefeed(h);
		js_close_method(h);
	return;
}
			
private	void	javascript_area_out(FILE * h)
{
	fprintf(h,"function AreaOut(v) {");					linefeed(h);
		indent(h,1); 	fprintf(h,"var vv = _SingLocateObject(v);");		linefeed(h);
		indent(h,1);	fprintf(h,"vv.style.color='black';");		linefeed(h);
		indent(h,1);	fprintf(h,"vv.style.border='1px solid white';");linefeed(h);
		js_close_method(h);
	return;
}

						
private	void	javascript_on_hint(FILE * h)
{
	fprintf(h,"function _SingOnHint(v) {");					linefeed(h);
		indent(h,1);	fprintf(h,"window.status=v;"); 			linefeed(h);
		js_close_method(h);
	return;
}

private	void	javascript_onerror_form(FILE * h,struct form_control * fptr)
{
	/* ----------------------------------------------------- */
	/* global error catching function handle javascript bugs */
	/* ----------------------------------------------------- */
	fprintf(h,"function _SingOnErrorGoto(msg,url,l) {");			linefeed(h);
		indent(h,1);	fprintf(h,"return(true);");			linefeed(h);
		js_close_method(h);

	fprintf(h,"onerror=_SingOnErrorGoto;");				linefeed(h);
	return;
}

private	void	javascript_cookie_form(FILE * h, struct form_control * fptr)
{
#ifdef	ABAL32A
	if ( fptr->weboptions & 64 ) {

		fprintf(h,"function _SingCheckCookies() {");			linefeed(h);
		
		/* ----------------------------------------- */
		/* check and alert for cookies to be enabled */
		/* ----------------------------------------- */
		indent(h,1);	fprintf(h,"var UaWb=navigator;");			linefeed(h);
		indent(h,1);	fprintf(h,"if ( UaWb.cookieEnabled != true ) {");	linefeed(h);
		indent(h,2);	
		if ( fptr->formflags & _MULTILINGUAL ) {
			switch ( fptr->natlang ) {
				case	0 :
					fprintf(h,"alert('This site requires that cookies be activated for your browser');");
					break;
				case	1 :
					fprintf(h,"alert('Vous devez activez les cookies pour visiter ce site');");
					break;
				default	 :
					fprintf(h,"alert('This site requires that cookies be activated for your browser');");
					break;
				}
			}
		else	{
			fprintf(h,"alert('This site requires that cookies be activated for your browser');");
			linefeed(h);
			}
		indent(h,2);	
			fprintf(h,"}");	linefeed(h);

		js_close_method(h);
		}
#endif
	return;
}

private	void	javascript_locate_object(FILE * h)
{
	/* ------------------- */
	/* Locate Named Object */
	/* ------------------- */
	fprintf(h,"function _SingLocateObject(name) {");	linefeed(h);
	indent(h,1);
		fprintf(h,"var obj = false;");
		linefeed(h);
	indent(h,1);
		fprintf(h,"if (document.getElementById) {");
		fprintf(h," obj = document.getElementById(name);");
		fprintf(h," }");
		linefeed(h);
	indent(h,1);
	  	fprintf(h,"else if (document.all) {");
		fprintf(h," obj = document.all[name];");
		fprintf(h," }");
		linefeed(h);
	indent(h,1);
	  	fprintf(h,"else if (document.layers) {");
		fprintf(h," obj = document.layers[name];");
		fprintf(h," }");
		linefeed(h);
	indent(h,1);
		fprintf(h,"return( obj );");
		linefeed(h);
	js_close_method(h);
	return;
}

private	void	javascript_hyperlink_form(FILE * h)
{
	fprintf(h,"function _SingHyperLink(hrf) {");	linefeed(h);
		indent(h,1); fprintf(h,"window.open(hrf,'_sing_hyperlink','%s');",_SING_BROWSER_WINDOW); linefeed(h);
		js_close_method(h);
	return;
}

private	void	javascript_submit_form(FILE * h)
{
	/* ---------------------------------------------------- */
	/* global submit function to chain between forms models */
	/* ---------------------------------------------------- */
	fprintf(h,"function _SingChainForm(v) {");					linefeed(h);
		indent(h,1);	fprintf(h,"document.forms[0].Method.value=v;"); linefeed(h);
		indent(h,1);	fprintf(h,"document.forms[0].target=%c_top%c;",__QUOTE,__QUOTE);	linefeed(h);
		indent(h,1);	fprintf(h,"document.forms[0].submit();");	linefeed(h);
		indent(h,1);	fprintf(h,"return(false);");			linefeed(h);
		js_close_method(h);
	return;
}

private	void	javascript_loadgo_form(FILE * h)
{
	/* ------------------------------------------------------ */
	/* global submit function for loadgo operation form links */
	/* ------------------------------------------------------ */
	fprintf(h,"function _SingLoadGoForm(v) {");					linefeed(h);
		indent(h,1);	fprintf(h,"document.forms[0].Method.value=v;"); linefeed(h);
		indent(h,1);	fprintf(h,"document.forms[0].target=%c_blank%c;",__QUOTE,__QUOTE);	linefeed(h);
		indent(h,1);	fprintf(h,"document.forms[0].submit();");	linefeed(h);
		indent(h,1);	fprintf(h,"return(false);");			linefeed(h);
		js_close_method(h);
	return;
}

private	void	javascript_widget_events( FILE * h, struct form_control * fptr, int oldmode )
{
	struct	form_control * vfptr;
	char	* sptr;
	struct	form_item * iptr;
	struct	form_item * wptr=(struct form_item *) 0;

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else if (iptr->Contents.events->xo_show & _EVENT_IS_COND )
			continue;
		else if (!(iptr->Contents.events->xo_event & _EVENT_IS_OTHER ))
			continue;

		if (( iptr->Contents.style & _FRAME_TYPE )  == _WINDOW_FRAME ) {
			if (!( wptr ))
				wptr = iptr;
			continue;
			}
		else	{
			switch ( ( iptr->Contents.style & _FRAME_TYPE ) ) {
				case	_SELECT_FRAME	:
					if ( method_is_valid( iptr->Contents.events->on_lose_focus )) {
						fprintf(h,"function %sChange(v) {",prefixed_widget_name(iptr));	linefeed(h);
						indent(h,1);	fprintf(h,"document.forms[0].%sLoseFocus.value=v;",prefixed_widget_name(iptr));	linefeed(h);
						indent(h,1);	fprintf(h,"document.forms[0].submit();");	linefeed(h);
						js_close_method(h);
						}
					continue;

				case	_FORM_FRAME	:
					if ( method_is_valid( iptr->Contents.events->on_event )) {
						fprintf(h,"function %sClick(v) {",prefixed_widget_name(iptr));	linefeed(h);
						indent(h,1);	fprintf(h,"document.forms[0].%sEvent.value=v;",prefixed_widget_name(iptr));	linefeed(h);
						indent(h,1);	fprintf(h,"document.forms[0].submit();");	linefeed(h);
						indent(h,1);	fprintf(h,"return(false);");			linefeed(h);
						js_close_method(h);
						}
					if ( method_is_valid( iptr->Contents.events->on_lose_focus )) {
						fprintf(h,"function %sChange(v) {",prefixed_widget_name(iptr));	linefeed(h);
						indent(h,1);	fprintf(h,"document.forms[0].%sLoseFocus.value=v;",prefixed_widget_name(iptr));	linefeed(h);
						indent(h,1);	fprintf(h,"document.forms[0].submit();");	linefeed(h);
						js_close_method(h);
						}
					continue;
				case	_SCROLL_FRAME	:
					if ( oldmode ) {
						if ( method_is_valid( iptr->Contents.events->on_event )) {
							fprintf(h,"function %sMouseDown(v) {",prefixed_widget_name(iptr));	linefeed(h);
							indent(h,1);	fprintf(h,"%sBar.style.posLeft = window.event.clientX;",prefixed_widget_name(iptr));
							linefeed(h);
							indent(h,1);	fprintf(h,"%sBar.style.posTop  = window.event.clientY;",prefixed_widget_name(iptr));
							linefeed(h);
							indent(h,1);	fprintf(h,"return(false);");			linefeed(h);
							js_close_method(h);
							}
						}
					else	{
						simple_new_scrolldown(h,iptr);
						simple_new_scrollclick(h,iptr);
						simple_new_scrollbuttons(h,iptr);
						}
					continue;
				case	_DATA_FRAME	:
					if (( iptr->Contents.align & 0x000F ) != _VISUAL_FRAME)
						continue;
					else if ( iptr->Contents.datatype != _WIDGET_OVERLAY )
						continue;
					else if (!( method_is_valid((sptr = abal_payload( iptr )) ) ))
						continue;
					else if (!( vfptr = locate_form_control( sptr ) ))
						continue;
					else	prefix_javascript_widget_events(h,vfptr,oldmode,iptr->Contents.name);

				default			:
					continue;
				}
			}
		}
	return;
}

private	void	prefix_javascript_widget_events( FILE * h, struct form_control * fptr, int oldmode, char * prefix )
{
	char * pptr;
	pptr = set_widget_prefix( prefix );
	javascript_widget_events( h, fptr, oldmode );
	set_widget_prefix( pptr );
	return;
}

private	void	javascript_widget_create( FILE * h, struct form_control * fptr, int page )
{
	struct	form_item * iptr;
	struct	form_item * wptr=(struct form_item *) 0;
	int	ih;
	int	iy;
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (( iptr->Contents.page ) && ( iptr->Contents.page != page ))
			continue;
		switch ( ( iptr->Contents.style & _FRAME_TYPE ) ) {
			case	_SWITCH_FRAME	:
				fprintf(h,"function %sCreate(v) {",prefixed_widget_name(iptr)); linefeed(h);
				indent(h,1);	
					fprintf(h,"var thisvalue   = <widget name=%s.value>;",prefixed_widget_name(iptr)); 
					linefeed(h);
				indent(h,1);
					fprintf(h,"if (!( thisvalue )) { "); 
					linefeed(h);
				indent(h,2);
						fprintf(h,"v.style.color='white';");
						linefeed(h);
				indent(h,2);
						fprintf(h,"v.style.backgroundColor='");
						html_rgb_colour(h,((iptr->Contents.colour & 0xFF00) >> 8));
						fprintf(h,"';");
						linefeed(h);
				indent(h,2);
						fprintf(h,"}");
						linefeed(h);
				indent(h,1);
					fprintf(h,"else {");
					linefeed(h);
				indent(h,2);	
						fprintf(h,"v.style.color='white';");
						linefeed(h);
				indent(h,2);	
						fprintf(h,"v.style.backgroundColor='");
						html_rgb_colour(h,(iptr->Contents.colour & 0x00FF));
						fprintf(h,"';");
				indent(h,2);	
						fprintf(h,"}");
						linefeed(h);
				js_close_method(h);
				continue;

			case	_SCROLL_FRAME	:
				simple_scrollbar_sizes( iptr, &iy,&ih );
				fprintf(h,"function %sCreate(v) {",prefixed_widget_name(iptr)); linefeed(h);
				indent(h,1);	
					fprintf(h,"var sbh=0;");
					linefeed(h);
				indent(h,1);	
					fprintf(h,"var sbmax   = <widget name=%s.max>;",prefixed_widget_name(iptr)); 
					linefeed(h);
				indent(h,1);
					fprintf(h,"var sblimit = <widget name=%s.limit>;",prefixed_widget_name(iptr)); 
					linefeed(h);
				indent(h,1);
					fprintf(h,"var sbvalue = <widget name=%s.value>;",prefixed_widget_name(iptr)); 
					linefeed(h);
				indent(h,1);	
					fprintf(h,"if (sbmax < sblimit) { sbmax=sblimit; }"); 
					linefeed(h);
				indent(h,1);
					fprintf(h,"sbh = Math.round((sblimit*%u)/sbmax);",ih);
					linefeed(h);

				indent(h,1);
					fprintf(h,"if ( sbh < 5 ) { sbh=6; }");
					linefeed(h);

				indent(h,1);
					if ( iptr->Contents.h > iptr->Contents.w )
						fprintf(h,"v.style.top  = (Math.round((sbvalue*(%u-sbh))/(sbmax-sblimit))+%sBarTop);",ih,prefixed_widget_name(iptr));
					else	fprintf(h,"v.style.left = (Math.round((sbvalue*(%u-sbh))/(sbmax-sblimit))+%sBarTop);",ih,prefixed_widget_name(iptr));
					linefeed(h);
				indent(h,1);
					if ( iptr->Contents.h > iptr->Contents.w )
						fprintf(h,"v.style.height = sbh;");
					else	fprintf(h,"v.style.width  = sbh;");
					linefeed(h);

				js_close_method(h);
				continue;
			}
		}


	fprintf(h,"var %sAllowRemove=false;",fptr->identifier); linefeed(h);
	fprintf(h,"function %sRemove() {",fptr->identifier); linefeed(h);
		indent(h,1);
		fprintf(h,"if (%sAllowRemove == false) {",fptr->identifier); 
		linefeed(h);
		indent(h,2);
		fprintf(h,"return( confirm('are you sure to want to leave this document') );");
		linefeed(h);
		indent(h,1);
		fprintf(h,"} else { return( true ); }");
		linefeed(h);
		js_close_method(h);

	fprintf(h,"function %sCreate() {",fptr->identifier); linefeed(h);

	if ( fptr->weboptions & 64 ) {
		indent(h,1); fprintf(h,"_SingCheckCookies();"); 	    		linefeed(h);
		indent(h,1); fprintf(h,"_SingHistoryManager();"); 	    		linefeed(h);
		}

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (( iptr->Contents.page ) && ( iptr->Contents.page != page ))
			continue;
		switch ( ( iptr->Contents.style & _FRAME_TYPE ) ) {
			case	_SWITCH_FRAME	:
				indent(h,1); 
					fprintf(h,"var %sv = _SingLocateObject('%s');",
						prefixed_widget_name(iptr),prefixed_widget_name(iptr));
					linefeed(h);
				indent(h,1); 
					fprintf(h,"%sCreate(%sv);",
						prefixed_widget_name(iptr),prefixed_widget_name(iptr));
					linefeed(h);
				continue;
			case	_SCROLL_FRAME	:
				indent(h,1); 
					fprintf(h,"var %sv = _SingLocateObject('%s_bar');",
						prefixed_widget_name(iptr),prefixed_widget_name(iptr));
					linefeed(h);
				indent(h,1); 
					fprintf(h,"%sCreate(%sv);",
						prefixed_widget_name(iptr),prefixed_widget_name(iptr));
					linefeed(h);
				continue;
			}
		}

	indent(h,1);
		fprintf(h,"if ( window.focus ) { window.focus(); }");
		linefeed(h);

	js_close_method(h);

	return;
}

private	void	prefix_javascript_widget_create( FILE * h, struct form_control * fptr, char * prefix,int page )
{
	char * rptr = set_widget_prefix( prefix );
	javascript_widget_create( h,fptr,page );
	set_widget_prefix( rptr );
	return;
}


private	void	open_widget_division(FILE * h, struct form_item * iptr )
{
	if ((iptr->Contents.style & _FRAME_TYPE) != _RADIO_FRAME) {
		fprintf(h,"<div id=%c%s%c>",
			__QUOTE,prefixed_widget_name(iptr),__QUOTE);
		}
	else	{
		fprintf(h,"<div id=%c%s_%u%c>",
			__QUOTE,prefixed_widget_name(iptr),iptr->Contents.radio,__QUOTE);
		}
	return;
}

private	void	close_widget_division(FILE * h, struct form_item * iptr )
{
	fprintf(h,"</div>\n");
	return;
}

private	void	simple_click_division(FILE * h, struct form_item * iptr )
{
	if ((iptr->Contents.style & _FRAME_TYPE) != _RADIO_FRAME) {
		fprintf(h,"<div id=%c%s%c ",
			__QUOTE,prefixed_widget_name(iptr),__QUOTE);
		}
	else	{
		fprintf(h,"<div id=%c%s_%u%c ",
			__QUOTE,prefixed_widget_name(iptr),iptr->Contents.radio,__QUOTE);
		}

	html_submit_field(h,iptr,(char *) 0,"Event");			
	simple_area_over_and_out(h,iptr);
	fprintf(h,">&nbsp;");
	close_widget_division(h,iptr);
	return;
}

private	void	scroll_click_division(FILE * h, struct form_item * iptr )
{
	if (!( ActiveAgentImages )) {
		fprintf(h,"<div id=%c%s_tray%c ",__QUOTE,prefixed_widget_name(iptr),__QUOTE);
		html_scroll_submit_field(h,iptr,(char *) 0,"Event",6);			
		fprintf(h,">&nbsp;</div>");
		linefeed(h);
		}
	fprintf(h,"<div id=%c%s_bar%c ",__QUOTE,prefixed_widget_name(iptr),__QUOTE);
	html_scroll_submit_field(h,iptr,(char *) 0,"Event",7);			
	fprintf(h,">&nbsp;</div>");
	linefeed(h);
	return;
}

private	void	message_click_division(FILE * h, struct form_item * iptr )
{
	char	*	sptr;
	if ((iptr->Contents.style & _FRAME_TYPE) != _RADIO_FRAME) {
		fprintf(h,"<div id=%c%s%c ",
			__QUOTE,prefixed_widget_name(iptr),__QUOTE);
		}
	else	{
		fprintf(h,"<div id=%c%s_%u%c ",
			__QUOTE,prefixed_widget_name(iptr),iptr->Contents.radio,__QUOTE);
		}
	html_submit_field(h,iptr,(char *) 0,"Event");			
	fprintf(h,">");
	if (( sptr = abal_payload(iptr)) != (char *) 0);
		fprintf(h,"%s",sptr);
	close_widget_division(h,iptr);
	return;
}

private	void	simple_href(FILE * h, struct form_item * iptr)
{
	char	*	sptr;
	if (!( method_is_valid( sptr = iptr->Contents.format ) ))
		return;
	else	{
		fprintf(h," href=%c",__QUOTE);
		if ( *sptr != _UNQUOTED_STRING )
			html_anchor_trigger(h,sptr);
		else	html_unquoted_string(h,sptr);
		fprintf(h,"%c",__QUOTE);
		}
}

private	void	simple_href_division(FILE * h, struct form_item * iptr)
{
	if ( iptr->Contents.format ) {		
		fprintf(h,"<a class=noborder click='_SingBrowserShow(true)'");
		simple_href( h, iptr );
		fprintf(h,">");
		}
	if ((iptr->Contents.style & _FRAME_TYPE) != _RADIO_FRAME) {
		fprintf(h,"<div id=%c%s%c>",__QUOTE,prefixed_widget_name(iptr),__QUOTE);
		}
	else	{
		fprintf(h,"<div id=%c%s_%u%c>",	__QUOTE,prefixed_widget_name(iptr),iptr->Contents.radio,__QUOTE);
		}
	fprintf(h,"&nbsp;</div>");
	if ( iptr->Contents.format ) 
		fprintf(h,"</a>");	
	linefeed(h);
	return;
}

private	void	simple_edit_href_division(FILE * h, struct form_item * iptr)
{
	if (!( Restriction )) {
		fprintf(h,"<a class=noborder ");
		fprintf(h," href=%c<widget name=%s.buffer>%c>",__QUOTE,prefixed_widget_name(iptr),__QUOTE);
		fprintf(h,"<div id=%c%s%c>",__QUOTE,prefixed_widget_name(iptr),__QUOTE);
		fprintf(h,"<widget name=%s.buffer></div></a>",prefixed_widget_name(iptr));
		linefeed(h);
		}
	else	{
		fprintf(h,"<a class=noborder onclick='_SingHyperLink(%c<widget name=%s.buffer>%c);'",__QUOTE,prefixed_widget_name(iptr),__QUOTE);
		fprintf(h," href=%c#%c>",__QUOTE,__QUOTE);
		fprintf(h,"<div id=%c%s%c>",__QUOTE,prefixed_widget_name(iptr),__QUOTE);
		fprintf(h,"<widget name=%s.buffer></div></a>",prefixed_widget_name(iptr));
		linefeed(h);
		}
	return;
}

private	void	simple_image_division(FILE * h, struct form_item * iptr, char * nptr)
{
	char	*	iname;
	fprintf(h,"<div id=%c%s%c>",	__QUOTE,prefixed_widget_name(iptr),__QUOTE);
	server_interface_record(nptr,_WSI_IMAGE,0);
	if (( iname = allocate_string( nptr )) != (char *) 0) {
		if (( iname = normalise_url( iname )) != (char *) 0) {
			fprintf(h,"<img src=%c%s%c alt=%c%s%c width=%u height=%u>",
				__QUOTE,iname,__QUOTE,
				__QUOTE,iname,__QUOTE,
				iptr->Contents.w,iptr->Contents.h);
			liberate( iname );
			}
		}
	fprintf(h,"</div>");
	linefeed(h);
	return;
}

private	void	simple_text_division(FILE * h, struct form_item * iptr, char * nptr )
{
	fprintf(h,"<div id=%c%s%c>",__QUOTE,prefixed_widget_name(iptr),__QUOTE);
	if ( nptr  )
		fprintf(h,"%s",nptr );
	fprintf(h,"</div>");
	linefeed(h);
	return;
}

private	void	simple_edit_division(FILE * h, struct form_item * iptr )
{
	struct	form_control * fptr;

	/* -------------------------------------------------------------------------- */
	/* When Realtime Image Production has been activated, since the edit requires */
	/* no interactive operation, we can rely solely on the shown version of data  */
	/* IJM 9/8/2007 :3.2a.0.11 						      */
	/* -------------------------------------------------------------------------- */
	if (!( ActiveAgentImages )) {
		fprintf(h,"<div id=%c%s%c>",__QUOTE,prefixed_widget_name(iptr),__QUOTE);
		fprintf(h,"<widget name=%s.buffer>",prefixed_widget_name(iptr));
		fprintf(h,"</div>");
		linefeed(h);
		}
	return;
}

private	void	simple_widget_position( FILE * handle, int x, int y, int w, int h, char * metrics)
{
	fprintf(handle,"position: absolute; left: %u%s; top: %u%s; right: auto; bottom: auto; width: %u%s; height: %u%s; ",
		x,metrics,y,metrics,w,metrics,h,metrics );
	return;
}

private	void	simple_window_position( FILE * handle, int x, int y, int w, int h, char * metrics)
{
	fprintf(handle,"position: relative; width: %u%s; height: %u%s; ",
		w,metrics,h,metrics );
	return;
}

private	void	simple_widget_xyposition( FILE * handle, int x, int y, int w, int h, char * metrics)
{
	fprintf(handle,"position: absolute; left: %u%s; top: %u%s; ",
		x,metrics,y,metrics,w,metrics,h,metrics );
	return;
}

private	void	simple_visual_script( FILE * h, struct form_control * fptr, struct form_item * wptr, int page )
{
	html_open_script(h,(char *) 0);
	javascript_define_window(h,wptr);
	javascript_onerror_form(h,fptr);
	javascript_cookie_form(h,fptr);
	javascript_history_manager(h,fptr);
	javascript_locate_object(h);
	javascript_hyperlink_form(h);
	javascript_submit_form(h);
	javascript_loadgo_form(h);
	javascript_image_preload(h);
	javascript_on_hint( h );
	javascript_restriction(h,wptr);

	javascript_on_over( h );
	javascript_on_out( h );
	javascript_area_over( h );
	javascript_area_out( h );

	prefix_javascript_widget_events(h,fptr,0,"\0");
	prefix_javascript_widget_create(h,fptr,"\0",page);
	html_close_script(h,(char *) 0);
}

private	void	css_background_colour(FILE * h, char * cptr )
{
	fprintf(h," background-color: %s;",cptr);
	return;
}

private	void	css_background_image(FILE * h, char * cptr )
{
	server_interface_record(cptr,_WSI_IMAGE);
	fprintf(h," background-image: url(%s);",cptr);
	return;
}

private	void	css_text_colour(FILE * h, char * cptr )
{
	fprintf(h," text-color: %s;",cptr);
	return;
}

private	void	css_border_colour(FILE * h, char * cptr )
{
	fprintf(h," border-color: %s;",cptr);
	return;
}

private	void	css_border_style(FILE * h, char * cptr )
{
	fprintf(h," border-style: %s;",cptr);
	return;
}

private	void	css_rgb_colour( int colourid, char * buffer )
{
	int	rvalue=0;
	int	gvalue=0;
	int	bvalue=0;
	get_rgb_values((colourid & 0x00FF),&rvalue,&gvalue,&bvalue );
	sprintf(buffer,"#%02.2X%02.2X%02.2X",(rvalue&0x00FF),(gvalue&0x00FF),(bvalue&0x00FF));
	return;
}

private	int	css_value( FILE * h, struct element_dimension * vptr, char * tagname, int a )
{
	switch ( vptr->type ) {
		case	_PIXEL_DIMENSION	: 
			fprintf(h," %s: %upx;",tagname,vptr->value-a);
			return(1);

		case	_IN_DIMENSION	: 
			fprintf(h," %s: %uin;",tagname,vptr->value-a);
			return(1);

		case	_MM_DIMENSION	: 
			fprintf(h," %s: %umm;",tagname,vptr->value-a);
			return(1);

		case	_CM_DIMENSION	: 
			fprintf(h," %s: %ucm;",tagname,vptr->value-a);
			return(1);

		case	_PT_DIMENSION	: 
			fprintf(h," %s: %upt;",tagname,vptr->value-a);
			return(1);
		}
	return(0);
}

private	void	css_style_width( FILE * h, struct element_style * sptr, int a, int w, int hh, char * metric)
{
	if (!( css_value( h, &sptr->cellwidth, "width",a) ))
		fprintf(h," width: %u%s;",w,metric);
	fprintf(h," height: %u%s;",hh,metric);

	return;
}

private	void	css_style_height( FILE * h, struct element_style * sptr,int a, int w, int hh, char * metric)
{
	fprintf(h," width: %u%s;",w,metric);
	if (!( css_value( h, &sptr->cellheight, "height",a) ))
		fprintf(h," height: %u%s;",hh,metric);
	return;
}

private	void	simple_styled_margin(FILE * h, struct element_style * sptr )
{
	if ( sptr->marginsize.top.type == _PIXEL_DIMENSION )
		fprintf(h," margin-top: %upx;", sptr->marginsize.top.value );
	if ( sptr->marginsize.right.type == _PIXEL_DIMENSION )
		fprintf(h," margin-right: %upx;", sptr->marginsize.left.value );
	if ( sptr->marginsize.bottom.type == _PIXEL_DIMENSION )
		fprintf(h," margin-bottom: %upx;", sptr->marginsize.bottom.value );
	if ( sptr->marginsize.left.type == _PIXEL_DIMENSION )
		fprintf(h," margin-left: %upx;", sptr->marginsize.left.value );
	return;
}

private	void	simple_styled_border(FILE * h, struct element_style * sptr )
{
	css_border_style(h,"none");
	return;
}

private	void	simple_styled_padding(FILE * h, struct element_style * sptr )
{
	if ( sptr->paddingsize.top.type == _PIXEL_DIMENSION )
		fprintf(h," padding-top: %upx;", sptr->paddingsize.top.value );
	if ( sptr->paddingsize.right.type == _PIXEL_DIMENSION )
		fprintf(h," padding-right: %upx;", sptr->paddingsize.left.value );
	if ( sptr->paddingsize.bottom.type == _PIXEL_DIMENSION )
		fprintf(h," padding-bottom: %upx;", sptr->paddingsize.bottom.value );
	if ( sptr->paddingsize.left.type == _PIXEL_DIMENSION )
		fprintf(h," padding-left: %upx;", sptr->paddingsize.left.value );
	return;
}

private	void	simple_styled_text_font( FILE * h, int font )
{
	int	fh;
	int	fw;
	if (!( font ))
		return;
	else if (!( fw = guifontsize( font ) ))
		return;
	else if (!( fh = ((fw & 0xFF00) >> 8) ))
		return;
	else	{
		fprintf(h," font: %u%s;",html_scale_quantity(fh-(fh/4)),_metrics);
		return;
		}
}

private	void	simple_styled_text_colour( FILE * h, struct element_colour * sptr )
{
	char 	buffer[64];
#ifdef	ABAL32A
	switch ( sptr->type ) {
		case _keyword_none	:					break;
		case _keyword_black	: css_text_colour(h, "black"); 		break;
		case _keyword_navy	: css_text_colour(h, "navy"); 		break;
		case _keyword_green	: css_text_colour(h, "green"); 		break;
		case _keyword_cyan	: css_text_colour(h, "cyan"); 		break;
		case _keyword_red	: css_text_colour(h, "red"); 		break;
		case _keyword_magenta	: css_text_colour(h, "magenta"); 	break;
		case _keyword_brown	: css_text_colour(h, "brown"); 		break;
		case _keyword_grey	: css_text_colour(h, "grey"); 		break;
		case _keyword_silver	: css_text_colour(h, "silver"); 	break;
		case _keyword_blue	: css_text_colour(h, "blue"); 		break;
		case _keyword_lime	: css_text_colour(h, "lime"); 		break;
		case _keyword_sky	: css_text_colour(h, "sky"); 		break;
		case _keyword_pink	: css_text_colour(h, "pink"); 		break;
		case _keyword_purple	: css_text_colour(h, "purple"); 	break;
		case _keyword_yellow	: css_text_colour(h, "yellow"); 	break;
		case _keyword_white	: css_text_colour(h, "white"); 		break;
		case _keyword_ihm	:
		case _keyword_colour	:
			css_rgb_colour(sptr->entry,buffer);
			css_text_colour(h,buffer);
			break;

		case _keyword_rgb	: 
			sprintf(buffer,"#%02.2X%02.2X%02.2X",(sptr->red&0x00FF),(sptr->green&0x00FF),(sptr->blue&0x00FF));
			css_text_colour(h,buffer);
			break;
		}
#endif
	return;
}

private	void	simple_styled_wash_colour( FILE * h, struct element_colour * sptr )
{
	char 	buffer[64];
#ifdef	ABAL32A
	switch ( sptr->type ) {
		case _keyword_none	:					break;
		case _keyword_black	: css_background_colour(h, "black"); 		break;
		case _keyword_navy	: css_background_colour(h, "navy"); 		break;
		case _keyword_green	: css_background_colour(h, "green"); 		break;
		case _keyword_cyan	: css_background_colour(h, "cyan"); 		break;
		case _keyword_red	: css_background_colour(h, "red"); 		break;
		case _keyword_magenta	: css_background_colour(h, "magenta"); 	break;
		case _keyword_brown	: css_background_colour(h, "brown"); 		break;
		case _keyword_grey	: css_background_colour(h, "grey"); 		break;
		case _keyword_silver	: css_background_colour(h, "silver"); 	break;
		case _keyword_blue	: css_background_colour(h, "blue"); 		break;
		case _keyword_lime	: css_background_colour(h, "lime"); 		break;
		case _keyword_sky	: css_background_colour(h, "sky"); 		break;
		case _keyword_pink	: css_background_colour(h, "pink"); 		break;
		case _keyword_purple	: css_background_colour(h, "purple"); 	break;
		case _keyword_yellow	: css_background_colour(h, "yellow"); 	break;
		case _keyword_white	: css_background_colour(h, "white"); 		break;
		case _keyword_ihm	:
		case _keyword_colour	:
			css_rgb_colour(sptr->entry,buffer);
			css_background_colour(h,buffer);
			break;

		case _keyword_rgb	: 
			sprintf(buffer,"#%02.2X%02.2X%02.2X",(sptr->red&0x00FF),(sptr->green&0x00FF),(sptr->blue&0x00FF));
			css_background_colour(h,buffer);
			break;
		}
#endif
	return;
}

private	void	simple_styled_background(FILE * h, struct element_style * sptr )
{
	simple_styled_wash_colour(h, &sptr->backgroundcolour );
	if ( sptr->backgroundimage ) {
		css_background_image( h, sptr->backgroundimage );
		}
	return;
}

private	void	simple_styled_text(FILE * h, struct element_style * sptr )
{
	simple_styled_text_font(h, sptr->textfont );
	simple_styled_text_colour(h, &sptr->textcolour );
	return;
}

private	void	simple_cell_style( FILE * h,struct form_item * iptr, int c, int l )
{
	int	fg;
	int	bg;
	char 	fgs[64];
	char 	bgs[64];
	char 	ogs[64];

	if (!( iptr ))
		return;
	else	{
		simple_styled_text_font(h, iptr->Contents.font );
		fg = (iptr->Contents.colour & 0x00FF);
		css_rgb_colour(fg,fgs);
		switch ( iptr->Contents.align & 7 ) {
			case	2 :
			case	3 :
			case	5 :
			case	7 :
				bg = ((iptr->Contents.colour & 0xFF00) >> 8);
				if ( bg ) og = (bg-1);
				else	  og = 0;
				break;
			case	0 :
			case	1 :
			case	4 :
			case	6 :
				bg = standard_white;
				if ( bg ) og = (bg-1);
				else	  og = 0;
				break;

			}
		css_rgb_colour(bg,bgs);
		css_rgb_colour(og,ogs);
		}
	switch ( iptr->Contents.align & 7 ) {
		case	0 :
		case	2 :
			/* white or plain colour */
			css_background_colour(h,bgs);
			css_text_colour(h,fgs);
			break;
		case	1 :
		case	3 :
			/* zoned or colour zoned */
			if (!(l & 1)) {
				css_background_colour(h,bgs);
				css_text_colour(h,fgs);
				}
			else	{
				css_background_colour(h,ogs);
				css_text_colour(h,fgs);
				}
			break;
		case	4 :
		case	5 :
			/* columned or colour columned */
			if (!(c & 1)) {
				css_background_colour(h,ogs);
				css_text_colour(h,fgs);
				}
			else	{
				css_background_colour(h,bgs);
				css_text_colour(h,fgs);
				}
			break;
		case	6 :
		case	7 :
			/* chequered or colour chequered */
			if (!(l & 1)) {
				if (!(c & 1)) {
					css_background_colour(h,bgs);
					css_text_colour(h,fgs);
					}
				else	{
					css_background_colour(h,ogs);
					css_text_colour(h,fgs);
					}
				}
			else	{
				if (!(c & 1)) {
					css_background_colour(h,ogs);
					css_text_colour(h,fgs);
					}
				else	{
					css_background_colour(h,bgs);
					css_text_colour(h,fgs);
					}
				}
			break;
		}
#ifdef	WHATTHE
	if (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )) {
		css_border_style(h,"none");
		}
#else
		css_border_style(h,"none");
#endif
	return;
}

private	void	simple_table_style( FILE * h,struct form_item * iptr, int wx, int wy )
{
	struct element_style * sptr;
	struct element_style * resolve_style_class( char * tptr );
	int		jsevent=0;
	int		framewidth=1;
	int		l;
	int		f=0;
	int		fields=0;
	int		fieldwidth[_MAX_FORM_FIELDS];
	int		linelength=0;
	int		nblines=0;
	int		xh=1;
	int		hh;
	int		fw;
	int		fh;
	int		atx;
	int		aty;
	int		cstyle=0;
	char *		sname;

	if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME)
		return;

	/* avoid generating un-necessary style */
	/* ----------------------------------- */
	if (( ActiveAgentImages )
	&&  (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )))
		return;

	calculate_edit_size( &iptr->Contents );
	calculate_form_lines( iptr, &linelength, &nblines );

	if (!( fields = calculate_form_fields(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength) ))
		return;

	if (!( method_is_valid( iptr->Contents.format ) ))
		cstyle = 0;
	else	cstyle = styled_table_columns( iptr->Contents.format, "tabledata" );

	fw = guifontsize(iptr->Contents.font);
	fh = (fw >> 8); fw &= 0x00FF;	

	if (!( iptr->Contents.special & 1 )) {
		framewidth = 1; xh = 0;
		}
	else	{
		framewidth = 0,
		xh = 1;
		}
	jsevent = simple_js_event( iptr );

	if ( jsevent & 1 ) {
		/* Generate Table Header Cell Style */
		/* -------------------------------- */
		atx = iptr->Contents.x+framewidth; aty = iptr->Contents.y+(framewidth*2);

		for (f=0; f < fields; f++ ) {
			fprintf(h,"#%s_h%u { ",prefixed_widget_name(iptr),(f+1));
			simple_widget_position(h,atx,aty,(fieldwidth[f]*fw),fh,_metrics );
			fprintf(h," border-style: none;");
			fprintf(h," }\n");
			atx += ((fieldwidth[f]*fw)+framewidth);
			}
		}

	/* Generate Table Data   Cell Style */
	/* -------------------------------- */
	atx = iptr->Contents.x+framewidth; aty = iptr->Contents.y+(framewidth*2);

	for ( l = 0; l < nblines; l++ ) {
		atx = iptr->Contents.x+(framewidth*2); 
		aty += (fh+xh);
		for (f=0; f < fields; f++ ) {
			fprintf(h,"#%s_c%ul%u { ",prefixed_widget_name(iptr),(f+1),(l+1));
				simple_widget_position(h,atx,aty,((fieldwidth[f]*fw)-framewidth),fh,_metrics );
			/* detect explicite cell style */
			if (( f < cstyle ) 
			&&  ((sname = styled_table_column( f )) != (char *) 0)
			&&  ((sptr  = resolve_style_class( sname )) != (struct style_element *) 0)) {
				simple_styled_margin(h, sptr );
				simple_styled_border(h, sptr );
				simple_styled_padding(h, sptr );
				simple_styled_background(h, sptr );
				simple_styled_text(h, sptr );
				}
			else	{
				simple_cell_style(h, iptr, f, l );
				}
			fprintf(h," }\n");
			atx += ((fieldwidth[f]*fw));
			}
		}
	return;
}

private	void	simple_table_cells( FILE * h,struct form_item * iptr )
{
	int		l;
	int		f=0;
	int		fields=0;
	int		fieldwidth[_MAX_FORM_FIELDS];
	int		linelength=0;
	int		nblines=0;
	int		fw;
	int		fh;
	int		atx;
	int		aty;
	int		jsevent=0;

	if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME)
		return;

	calculate_edit_size( &iptr->Contents );
	calculate_form_lines( iptr, &linelength, &nblines );

	if (!( fields = calculate_form_fields(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength) ))
		return;

	jsevent = simple_table_events( h, iptr );

	if ( jsevent & 1 ) {
		/* table needs column header event zones */
		/* ------------------------------------- */
		for (f=0; f < fields; f++ ) {
			if (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )) {
				fprintf(h,"<div id=%c%s_h%u%c",__QUOTE,prefixed_widget_name(iptr),(f+1),__QUOTE);
				fprintf(h," onclick=%c%sClick('%u,0');%c",__QUOTE,prefixed_widget_name(iptr),(f+1),__QUOTE);
				fprintf(h,">&nbsp;</div>\n");
				}
			}
		}

	/* Generate Table Data   Cell Style */
	/* -------------------------------- */
	for ( l = 0; l < nblines; l++ ) {
		for (f=0; f < fields; f++ ) {
			if (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )) {
				fprintf(h,"<div id=%c%s_c%ul%u%c",__QUOTE,prefixed_widget_name(iptr),(f+1),(l+1),__QUOTE);
				if ( jsevent & 1 ) {
					fprintf(h," onclick=%c%sClick('%u,%u');%c",__QUOTE,prefixed_widget_name(iptr),(f+1),(l+1),__QUOTE);
					fprintf(h," onmouseover=%cOnOver(this)%c",__QUOTE,__QUOTE);
					fprintf(h," onmouseout=%cOnOut(this)%c",__QUOTE,__QUOTE);
					}
				fprintf(h,"><widget name=%s(%u,%u)></div>\n",prefixed_widget_name(iptr),f+1,l+1);
				}
			else	{
				fprintf(h,"<input id=%c%s_c%ul%u%c name=%c%s(%u,%u)%c type=text",
					__QUOTE,prefixed_widget_name(iptr),(f+1),(l+1),__QUOTE,
					__QUOTE,prefixed_widget_name(iptr),(f+1),(l+1),__QUOTE);
				if ( jsevent & 1 ) {
					fprintf(h," onclick=%c%sClick('%u,%u');%c",__QUOTE,prefixed_widget_name(iptr),(f+1),(l+1),__QUOTE);
					}
				if ( jsevent & 2 ) {
					fprintf(h," onchange=%c{ %sChange('%u,%u'); }%c",__QUOTE,prefixed_widget_name(iptr),(f+1),(l+1),__QUOTE);
					}
				fprintf(h," value=%c<widget name=%s(%u,%u)>%c",
					__QUOTE,prefixed_widget_name(iptr),(f+1),(l+1),__QUOTE);
				fprintf(h,">\n");
				}
			}
		}
	return;
}

private	int	simple_dynamic_window( FILE * h, struct form_item * iptr, char * metrics )
{
	struct	form_control * fptr;
	if (!( iptr ))
		return(0);
	else if (!( fptr = iptr->parent ))
		return(0);
	else if (!( fptr->resizeauto ))
		return(0);
	else	{
		fprintf(h,"position: relative; ");
		fprintf(h,"width: 100%c; ",0x0025);
		fprintf(h,"height: 100%c; ",0x0025);
		fprintf(h," }\n");
		fprintf(h,"#i_%s { ",prefixed_widget_name(iptr));
		fprintf(h,"position: relative; ");
		if (!( iptr->Contents.wResize ))
			fprintf(h,"width: %u%s; ",iptr->Contents.w,metrics);
		else	fprintf(h,"width: 100%c; ",0x0025);

		if (!( iptr->Contents.hResize ))
			fprintf(h,"height: %u%s; ",iptr->Contents.h,metrics);
		else	fprintf(h,"height: 100%c; ",0x0025);

		return(1);
		}
}

private	int	simple_dynamic_widget( FILE * h, struct form_item * iptr, char * metrics )
{
	struct	form_control * fptr;
	if (!( iptr ))
		return(0);
	else if (!( fptr = iptr->parent ))
		return(0);
	else if (!( fptr->resizeauto ))
		return(0);
	else	{
		fprintf(h,"position: relative; ");
		if (!( iptr->Contents.wResize ))
			fprintf(h,"width: %u%s; ",iptr->Contents.w,metrics);
		else	fprintf(h,"width: 100%c; ",0x0025);

		if (!( iptr->Contents.hResize ))
			fprintf(h,"height: %u%s; ",iptr->Contents.h,metrics);
		else	fprintf(h,"height: 100%c; ",0x0025);

		return(1);
		}
}

private	void	simple_window_style( FILE * h, struct form_item * iptr, int wx, int wy )
{
	int	fw;
	int	fh;
	int	nl;
	struct	form_control * fptr;

	if (!( iptr ))	return;
	if (!( h    ))	return;
	if (!( fptr = iptr->parent )) return;

	fw = guifontsize(iptr->Contents.font);
	fh = (fw >> 8); fw &= 0x00FF;	

	fprintf(h,"#sing { background-color: silver; 0px; margin: 0px; padding: 0px; }");
	linefeed(h);

	fprintf(h,"#%s { ",prefixed_widget_name(iptr));
		if (!( simple_dynamic_window(h, iptr, _metrics) )) {
			simple_window_position(h, 
				wx+iptr->Contents.x, wy+iptr->Contents.y,
				iptr->Contents.w, iptr->Contents.h, _metrics);
			}
		fprintf(h," }\n");
#ifdef	USING_COPYRIGHT_ETC
	fprintf(h,"#%s__copyright { ",current_widget_prefix );
		simple_widget_position(h, 
			iptr->Contents.x+100, iptr->Contents.y+iptr->Contents.h,
			iptr->Contents.w-200, __CopyrightBarSize, _metrics);
		css_background_colour(h,"white");
		css_text_colour(h,"black");
		css_border_colour(h,"black");
		css_border_style(h, "solid");
		fprintf(h," border-width: 1px;");
		fprintf(h," text-align: center;");
		fprintf(h," }\n");
	fprintf(h,"#%s__show { ",current_widget_prefix);
		simple_widget_position(h, 
			iptr->Contents.x+, iptr->Contents.y+iptr->Contents.h,
			100, __CopyrightBarSize, _metrics);
		css_background_colour(h,"blue");
		css_text_colour(h,"yellow");
		css_border_colour(h,"black");
		css_border_style(h, "solid");
		fprintf(h," border-width: 1px;");
		fprintf(h," text-align: center;");
		fprintf(h," }\n");

	fprintf(h,"#%s__hide { ",current_widget_prefix);
		simple_widget_position(h, 
			iptr->Contents.x+iptr->Contents.w-100, iptr->Contents.y+iptr->Contents.h,
			100, __CopyrightBarSize, _metrics);
		css_background_colour(h,"red");
		css_text_colour(h,"white");
		css_border_colour(h,"black");
		css_border_style(h, "solid");
		fprintf(h," border-width: 1px;");
		fprintf(h," text-align: center;");
		fprintf(h," }\n");
#endif
	if ((!( current_widget_prefix )) || (!( *current_widget_prefix ))) {
		/* excluded for component windows */
		if ( fptr->formflags & _MULTILINGUAL ) {
			for (nl=0; nl < MAXNATLANG; nl++ ) {
				fprintf(h,"#%s__change%u { ",current_widget_prefix,nl+1);
					simple_widget_position(h, 
						(iptr->Contents.x+iptr->Contents.w)-((fh*3)+11)-((fh+4)*(MAXNATLANG-nl)), 
						iptr->Contents.y+4,fh,fh, _metrics);
					css_border_style(h, "none");
					fprintf(h," }\n");
				}
			}
		}
	return;
}



private	void	simple_scroll_style( FILE * h, struct form_item * iptr, int wx, int wy )
{
	struct element_style * sfptr=(struct element_style *) 0;
	struct element_style * sbptr=(struct element_style *) 0;
	int	x;
	int	y;
	int	w;
	int	hh;

	if ( iptr->Contents.h > iptr->Contents.w ) {
		/* vertical scroll bar */
		sfptr = resolve_style_class( "vscrollframe");
		sbptr = resolve_style_class( "vscrollbar");
		switch ( iptr->Contents.align & 3 ) {
			case	0 :
				x = iptr->Contents.x;
				y = iptr->Contents.y;
				w = iptr->Contents.w-_WINDOW_ADJUST;
				hh = iptr->Contents.h;
				break;
			case	1 :
				x = iptr->Contents.x;
				y = (iptr->Contents.y+iptr->Contents.w);
				w = iptr->Contents.w-_WINDOW_ADJUST;
				hh = (iptr->Contents.h-iptr->Contents.w);
				break;
			case	2 :
				x = iptr->Contents.x;
				y = iptr->Contents.y;
				w = iptr->Contents.w-_WINDOW_ADJUST;
				hh = (iptr->Contents.h-iptr->Contents.w);
				break;
			case	3 :
				x = iptr->Contents.x;
				y = (iptr->Contents.y+iptr->Contents.w)-2;
				w = iptr->Contents.w-_WINDOW_ADJUST;
				hh = (iptr->Contents.h-(iptr->Contents.w*2));
				break;
			}
		}
	else	{
		/* horizontal scroll bar */
		sfptr = resolve_style_class( "hscrollframe");
		sbptr = resolve_style_class( "hscrollbar");
		switch ( iptr->Contents.align & 3 ) {
			case	0 :
				x = iptr->Contents.x;
				y = iptr->Contents.y;
				w = iptr->Contents.w;
				hh = iptr->Contents.h-_WINDOW_ADJUST;
				break;
			case	1 :
				x = (iptr->Contents.x+iptr->Contents.h);
				y = iptr->Contents.y;
				hh = iptr->Contents.h-_WINDOW_ADJUST;
				w = (iptr->Contents.w-iptr->Contents.h);
				break;
			case	2 :
				x = iptr->Contents.x;
				y = iptr->Contents.y;
				hh = iptr->Contents.h-_WINDOW_ADJUST;
				w = (iptr->Contents.w-iptr->Contents.h);
				break;
			case	3 :
				x = (iptr->Contents.x+iptr->Contents.h)-2;
				y = iptr->Contents.y;
				hh = iptr->Contents.h-_WINDOW_ADJUST;
				w = (iptr->Contents.w-(iptr->Contents.h*2));
				break;
			}
		}

	if (!( ActiveAgentImages )) {
		fprintf(h,"#%s_tray { ",prefixed_widget_name(iptr));

		if (!( sfptr )) {
			simple_widget_position(h,wx+x, wy+y,w,hh,_metrics);
			}
		else	{
			simple_widget_xyposition(h,wx+x, wy+y,w,hh,_metrics);
			}

		if (!( ActiveAgentImages )) {
			css_border_style(h, "inset");
			fprintf(h," border-width: 1px;");
			css_background_colour(h,"gray");
			}
		else	{
			css_border_style(h, "none");
			fprintf(h," border-width: 0px;");
			}

		if ( sfptr ) {
	
			/* -2 to adjust eventual style width/height by border width */
			/* -------------------------------------------------------- */
			if ( iptr->Contents.h > iptr->Contents.w )
				css_style_width (h, sfptr,2,w,hh,_metrics );
			else	css_style_height(h, sfptr,2,w,hh,_metrics );

			simple_styled_margin(h, sfptr );
			simple_styled_padding(h, sfptr );

			if (!( ActiveAgentImages )) simple_styled_background(h,sfptr);

			}
		fprintf(h," }\n");
		}

	fprintf(h,"#%s_bar { ",prefixed_widget_name(iptr));
		if (!( sbptr )) {
			simple_widget_position(h,wx+x+2, wy+y+2,w-3,hh-3,_metrics);
			}
		else	{
			simple_widget_xyposition(h,wx+x+1, wy+y,w,hh,_metrics);
			}

		if (!( ActiveAgentImages ))
		 	css_border_style(h, "outset");
		else	css_border_style(h, "none");

		fprintf(h," border-width: 1px;");

		if (!( ActiveAgentImages ))
			css_background_colour(h,"silver");

		if ( sbptr ) {
			/* -4 to adjust eventual style width/height by border width */
			/* -------------------------------------------------------- */
			if ( iptr->Contents.h > iptr->Contents.w )
				css_style_width (h, sbptr,4,w-3,hh-3, _metrics );
			else	css_style_height(h, sbptr,4,w-3,hh-3, _metrics );
			simple_styled_margin(h, sbptr );
			simple_styled_padding(h, sbptr );

			if (!( ActiveAgentImages ))
				simple_styled_background(h,sbptr);
			}
		fprintf(h," }\n");
	return;
}

private	void	simple_form_style( FILE * h, struct form_control * fptr, int wx, int wy, int pageid )
{
	int			fg;
	int			bg;
	int			x;
	int			y;
	int			w;
	int			hh;
	char	* metrics=_metrics;
	struct	form_item * iptr;
	struct	form_control *	vfptr;
	char	*		sptr;

	/* this is from the window and causes problems when not zero ... */
	wx = wy = 0;

	for (	iptr = fptr->first;
		iptr != (struct form_control *) 0;
		iptr = iptr->next ) {
		if (( iptr->Contents.page ) && ( iptr->Contents.page != pageid ) && (( iptr->Contents.style & _FRAME_TYPE )!= _TAB_FRAME))
			continue;
		else if ((!( iptr->Contents.w )) || (!( iptr->Contents.h )))
			continue;

		fg = (iptr->Contents.colour & 0x00FF);
		bg = ((iptr->Contents.colour & 0xFF00) >> 8);

		switch (( iptr->Contents.style & _FRAME_TYPE )) {

			case	_TEXT_FRAME	:
				if ( iptr->Contents.datatype == _WIDGET_HYPERLINK ) {
					fprintf(h,"#%s { ",prefixed_widget_name(iptr));
					simple_widget_position(h, 
						wx+iptr->Contents.x, wy+iptr->Contents.y,
						iptr->Contents.w+2, iptr->Contents.h+2, _metrics);
					html_text_style(h,iptr,fg,bg,1);
					fprintf(h," }\n");
					}
				continue;
			case	_IMAGE_FRAME	:
				if ( iptr->Contents.datatype == _WIDGET_HYPERLINK ) {
					fprintf(h,"#%s { ",prefixed_widget_name(iptr));
					simple_widget_position(h, 
						wx+iptr->Contents.x, wy+iptr->Contents.y,
						iptr->Contents.w+2, iptr->Contents.h+2, _metrics);
					fprintf(h," }\n");
					}
				continue;

			case	_TAB_FRAME	:
				fprintf(h,"#%s { ",prefixed_widget_name(iptr));
				simple_widget_position(h, 
					wx+iptr->Contents.x+iptr->Contents.adjust, wy+iptr->Contents.y,
					iptr->Contents.xlimit, iptr->Contents.ylimit, _metrics);
				fprintf(h," }\n");
				break;


			case	_SWITCH_FRAME	:
				fprintf(h,"#%s { ",prefixed_widget_name(iptr));
				simple_widget_position(h, 
					wx+iptr->Contents.x, wy+iptr->Contents.y,
					iptr->Contents.w, iptr->Contents.h, _metrics);
				fprintf(h," background-color: white;");
				fprintf(h," border-color: green;");
				fprintf(h," border-style: solid;");
				fprintf(h," border-width: 1px;");
				fprintf(h," text-align: center;");
				fprintf(h," }\n");
				break;


			case	_CHECK_FRAME	:
				fprintf(h,"#%s { ",prefixed_widget_name(iptr));
				simple_widget_position(h, 
					wx+iptr->Contents.x-_WINDOW_ADJUST , wy+iptr->Contents.y-_WINDOW_ADJUST ,
					iptr->Contents.h, iptr->Contents.h, _metrics);
				fprintf(h," }\n");
				break;

			case	_WINDOW_FRAME	:
				simple_window_style(h,iptr,wx,wy);
				break;

			case	_SELECT_FRAME	:
				fprintf(h,"#%s { ",prefixed_widget_name(iptr));
				simple_widget_position(h, 
					wx+iptr->Contents.x, wy+iptr->Contents.y,
					iptr->Contents.w+2, iptr->Contents.ylimit+2, _metrics);
					simple_styled_text_font(h,iptr->Contents.font);
				fprintf(h," }\n");
				break;

			case	_FORM_FRAME	:
				simple_table_style( h, iptr, wx, wy );
				break;

			case	_BUTTON_FRAME	:
				fprintf(h,"#%s { ",prefixed_widget_name(iptr));
				simple_widget_position(h, 
					wx+iptr->Contents.x, wy+iptr->Contents.y,
					iptr->Contents.w, iptr->Contents.h, _metrics);
				fprintf(h," }\n");
				break;

			case	_EDIT_FRAME	:
				fprintf(h,"#%s { ",prefixed_widget_name(iptr));
				simple_widget_position(h, 
					wx+iptr->Contents.x, wy+iptr->Contents.y,
					iptr->Contents.w+2, iptr->Contents.h+2, _metrics);
				if (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS ))
					html_text_style(h,iptr,fg,bg,1);
				else	{
					fprintf(h," border-color: gray;");
					fprintf(h," background-color: white; ");
					fprintf(h," border-style: solid;");
					fprintf(h," border-width: 1%s;",_metrics);
					html_text_style(h,iptr,fg,bg,1);
					}
				fprintf(h," }\n");
				break;

			case	_RADIO_FRAME	:
				fprintf(h,"#%s_%u { ",prefixed_widget_name(iptr),iptr->Contents.radio);
				simple_widget_position(h, 
					wx+iptr->Contents.x-_WINDOW_ADJUST , wy+iptr->Contents.y-_WINDOW_ADJUST ,
					iptr->Contents.h, iptr->Contents.h, _metrics);
				fprintf(h," }\n");
				break;
			case	_SCROLL_FRAME	:
				simple_scroll_style(h, iptr, wx, wy );
				break;

			case	_DATA_FRAME	:

				if (( iptr->Contents.align & 0x000F ) != _VISUAL_FRAME)
					continue;
				else if ( iptr->Contents.datatype != _WIDGET_OVERLAY )
					continue;
				else if (!( method_is_valid((sptr = abal_payload( iptr )) ) ))
					continue;
				else if (!( vfptr = locate_form_control( sptr ) ))
					continue;
				else	prefix_simple_form_style(h,vfptr,wx+iptr->Contents.x,wy+iptr->Contents.y,0,iptr->Contents.name);

			default			:
				continue;

			}
		}
	return;
}

private	void	prefix_simple_form_style( FILE * h, struct form_control * fptr, int wx, int wy, int pageid, char * prefix )
{
	char *	rptr;
	rptr = set_widget_prefix( prefix );
	simple_form_style( h, fptr, wx,wy,pageid );
	set_widget_prefix( rptr );
	return;
}


private	void	simple_visual_style( FILE * h, struct form_control * fptr, struct form_item * wptr, int pageid )
{
	int	wx=0;
	int	wy=0;
	struct	element_style * sptr;

	if ( wptr ) { wx = wptr->Contents.x; wy = wptr->Contents.y; }

	if ( method_is_valid( fptr->clearscreen ) ) {
		if ((sptr = resolve_style_class( fptr->clearscreen )) != (struct element_style *) 0) {
			fprintf(h,"body.%s {",fptr->clearscreen );
			simple_styled_margin(h, sptr );
			simple_styled_border(h, sptr );
			simple_styled_padding(h, sptr );
			simple_styled_background(h, sptr );
			fprintf(h,"}\n");
			}
		}

	prefix_simple_form_style( h,fptr,wx,wy,pageid,"\0");
	return;
}

private	void	simple_area_event(FILE * handle,struct form_item * iptr, int x,int y,int w, int h,char * prefix,int option)
{
	html_open_tag(handle,"area");
		html_field(handle,"shape","rect");
		if ( method_is_valid( abal_payload(iptr) ) )
			html_field(handle,"alt",abal_payload(iptr));
		if (!( prefix ))
			html_scroll_submit_field(handle,iptr,prefix,"Event",0);			
		else if ( option & 1 )
			html_submit_field(handle,iptr,prefix,"Event");			
		else	{
			fprintf(handle," onclick=%c%s%sEvent(event);%c",__QUOTE,prefixed_widget_name(iptr),prefix,__QUOTE );
			fprintf(handle," onmouseup=%c%s%sEvent(event);%c",__QUOTE,prefixed_widget_name(iptr),prefix,__QUOTE );
			}
		fprintf(handle," coords=%c%u,%u,%u,%u%c",__QUOTE,x,y,w,h,__QUOTE);
	fprintf(handle,">");
	linefeed(handle);
	return;
}

private	void	simple_area_over_and_out( FILE * h, struct form_item * iptr )
{
	return;
	fprintf(h," onmouseover=%cAreaOver('%s');%c",__QUOTE,prefixed_widget_name(iptr),__QUOTE);
	fprintf(h," onmouseout=%cAreaOut('%s');%c",__QUOTE,prefixed_widget_name(iptr),__QUOTE);
	return;
}

private	void	simple_area_cursor( FILE * handle )
{
	fprintf(handle," style=%ccursor: pointer;%c",__QUOTE,__QUOTE);
	fprintf(handle," href=%c#%c",__QUOTE,__QUOTE);
	return;
}

private	void	simple_table_area( FILE * h, struct form_item * iptr )
{
	int		framewidth=1;
	int		l;
	int		f=0;
	int		fields=0;
	int		fieldwidth[_MAX_FORM_FIELDS];
	int		linelength=0;
	int		nblines=0;
	int		xh=1;
	int		hh;
	int		fw;
	int		fh;
	int		atx;
	int		aty;

	calculate_edit_size( &iptr->Contents );
	calculate_form_lines( iptr, &linelength, &nblines );

	if (!( fields = calculate_form_fields(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength) ))
		return;

	fw = guifontsize(iptr->Contents.font);
	fh = (fw >> 8); fw &= 0x00FF;	

	if (!( iptr->Contents.special & 1 )) {
		framewidth = 1; xh = 0;
		}
	else	{
		framewidth = 0,
		xh = 1;
		}

	/* Generate Table Head Area Map */
	/* ---------------------------- */
	atx = iptr->Contents.x+framewidth; 
	aty = iptr->Contents.y+(framewidth*2);
	for (f=0; f < fields; f++ ) {
		if (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )) {
			html_open_tag(h,"area");
			html_field(h,"shape","rect");
			fprintf(h," alt=%ch%u%c",__QUOTE,(f+1),__QUOTE);
			fprintf(h," coords=%c%u,%u,%u,%u%c",__QUOTE,atx,aty,atx+((fieldwidth[f]*fw)-framewidth),aty+fh,__QUOTE);
			fprintf(h," onclick=%c%sClick('%u,0');%c",__QUOTE,prefixed_widget_name(iptr),(f+1),__QUOTE);
			simple_area_cursor(h);
			fprintf(h,">");
			linefeed(h);
			atx += ((fieldwidth[f]*fw));
			}
		}

	/* Generate Table Data Area Map */
	/* ---------------------------- */
	atx = iptr->Contents.x+framewidth; 
	aty = iptr->Contents.y+(framewidth*2);

	for ( l = 0; l < nblines; l++ ) {
		atx = iptr->Contents.x+(framewidth*2); 
		aty += (fh+xh);
		for (f=0; f < fields; f++ ) {
			html_open_tag(h,"area");
			html_field(h,"shape","rect");
			fprintf(h," alt=%cc%u,l%u%c",__QUOTE,(f+1),(l+1),__QUOTE);
			fprintf(h," coords=%c%u,%u,%u,%u%c",__QUOTE,atx,aty,atx+((fieldwidth[f]*fw)-framewidth),aty+fh,__QUOTE);
			fprintf(h," onclick=%c%sClick('%u,%u');%c",__QUOTE,prefixed_widget_name(iptr),(f+1),(l+1),__QUOTE);
			simple_area_cursor(h);
			fprintf(h,">");
			linefeed(h);
			atx += ((fieldwidth[f]*fw));
			}
		}
	return;
}


private	void	agent_window_exit_event(FILE * h, struct form_item * iptr, int fw, int fh )
{
	int	x;
	int	y;
	if (!( iptr ))	return;
	else	{
		x = iptr->Contents.x;
		y = iptr->Contents.y;
		}
	abal_window_style_info( "windowexit", iptr, fh, 1 );
	html_open_tag(h,"area");
	html_field(h,"shape","rect");
	html_field(h,"title","close browser window and exit");
	simple_area_over_and_out( h, iptr );
	fprintf(h," onclick=%c_SingBrowserExit();%c ",__QUOTE,__QUOTE);
	simple_area_cursor(h);
	fprintf(h,"coords=%c%u,%u,%u,%u%c",
		__QUOTE,
		get_window_style_x()-x, get_window_style_y()-y,
		get_window_style_xx()-x, get_window_style_yy()-y,
		__QUOTE);
	fprintf(h,">");
	linefeed(h);
	return;
}

private	void	agent_window_help_event(FILE * h, struct form_item * iptr, int fw, int fh )
{
	int	x;
	int	y;
	if (!( iptr ))	return;
	else	{
		x = iptr->Contents.x;
		y = iptr->Contents.y;
		}
	abal_window_style_info( "windowhelp", iptr, fh, 2 );
	html_open_tag(h,"area");
	html_field(h,"shape","rect");
	html_field(h,"title","activate contextual help linkage");
	simple_area_over_and_out( h, iptr );
	fprintf(h," onclick=%c_SingBrowserHelp();%c ",__QUOTE,__QUOTE);
	simple_area_cursor(h);
	fprintf(h,"coords=%c%u,%u,%u,%u%c",
		__QUOTE,
		get_window_style_x()-x, get_window_style_y()-y,
		get_window_style_xx()-x, get_window_style_yy()-y,
		__QUOTE);
	fprintf(h,">");
	linefeed(h);
	return;
}

private	void	simple_agent_window_events(FILE * handle, struct form_item * iptr )
{
	int	f;
	int	fw;
	int	fh;
	struct	form_control * fptr;

	/* no widget or no parent form : no window event */
	/* --------------------------------------------- */
	if ((!( iptr )) || (!( fptr = iptr->parent )))
		return;

	/* no focus and no event : no window event */
	/* --------------------------------------- */
	if ((!( iptr->Contents.events->xo_event & _EVENT_IS_FOCUS ))
	&&  (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )))
		return;

	/* no font information : no window event */
	/* ------------------------------------- */
	if (!( f = iptr->Contents.font ))
		return;
	else if (!( fh = guifontsize(f) ))
		return;
	else if (!( fw = (fh & 0x00FF) ))
		return;
	else	fh = ((fh >>= 8) & 0x00FF);

	/* ------------------------------------------ */
	/* Generate the appropriate Window Event Type */
	/* ------------------------------------------ */
	if ( iptr->Contents.align & _A_BOLD ) {	
		agent_window_exit_event(handle, iptr, fw, fh );
		}
	if ( iptr->Contents.align & _A_LINE ) {
		agent_window_help_event(handle, iptr,fw, fh );
		}
	return;
}

private	void	simple_window_area_events( FILE * h, struct form_item * iptr )
{
	if ( Restriction ) {
		html_open_tag(h,"area");
		html_field(h,"shape","rect");
		html_field(h,"title","activate or hide browser control bars");
		simple_area_over_and_out( h, iptr );
		fprintf(h," onclick=%c_SingBrowserChange();%c ",__QUOTE,__QUOTE);
		simple_area_cursor(h);
		fprintf(h,"coords=%c%u,%u,%u,%u%c",
			__QUOTE,
			3, 3,
			iptr->Contents.x+13,
			iptr->Contents.y+13,__QUOTE);
		fprintf(h,">");
		linefeed(h);
		}
	return;
}

private	void	simple_hyperlink_restriction(FILE * h, struct form_item * iptr)
{
	char *	sptr;
	if ( method_is_valid( (sptr = iptr->Contents.format) ) ) {
		fprintf(h," onclick=%c_SingHyperLink('",__QUOTE);
		if ( *sptr != _UNQUOTED_STRING )
			html_anchor_trigger(h,sptr);
		else	html_unquoted_string(h,sptr);
		fprintf(h,"');%c",__QUOTE);
		}

	fprintf(h," href=%c#%c",__QUOTE,__QUOTE);
	return;
}

private	void	simple_image_map( FILE * h, struct form_control * fptr, int pageid )
{
	int			x;
	int			y;
	int			w;
	int			hh;
	struct	form_item 	* iptr;
	struct	form_item 	* wptr=(struct form_item *) 0;
	html_open_map( h, fptr->identifier );
	for (	iptr = fptr->first;
		iptr != (struct form_control *) 0;
		iptr = iptr->next ) {
		if (( iptr->Contents.page ) && ( iptr->Contents.page != pageid ) && (( iptr->Contents.style & _FRAME_TYPE )!= _TAB_FRAME))
			continue;
		else if ((!( iptr->Contents.w )) || (!( iptr->Contents.h )))
			continue;

		switch (( iptr->Contents.style & _FRAME_TYPE )) {

			case	_WINDOW_FRAME	:
				wptr = iptr;
				simple_window_area_events(h,iptr);
				simple_agent_window_events(h,iptr);
				continue;
				
			case	_FORM_FRAME	:
				if (!( ActiveAgentImages ))
					continue;
				else if ( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )
					continue;
				else if (!( iptr->Contents.events->xo_event & _EVENT_IS_FOCUS ))
					continue;
				else	{
					simple_table_area(h,iptr);
					continue;
					}
			case	_TAB_FRAME	:	
				html_open_tag(h,"area");
				html_field(h,"shape","rect");
				if ( method_is_valid( abal_payload(iptr) ) )
					html_field(h,"alt",abal_payload(iptr));
				simple_area_over_and_out( h, iptr );

				html_submit_field(h,iptr,(char *) 0,"Event");			
				simple_area_cursor(h);
				fprintf(h,"coords=%c%u,%u,%u,%u%c",
					__QUOTE,
					iptr->Contents.x+iptr->Contents.adjust, 
					iptr->Contents.y,
					iptr->Contents.x+iptr->Contents.adjust+iptr->Contents.xlimit, 
					iptr->Contents.y+iptr->Contents.ylimit,
					__QUOTE);
				fprintf(h,">");
				linefeed(h);
				continue;
			case	_SCROLL_FRAME	:
				if ( iptr->Contents.h > iptr->Contents.w ) {
					/* vertical scroll bar */
					switch ( iptr->Contents.align & 3 ) {
						case	0 :
							x = iptr->Contents.x;
							y = iptr->Contents.y;
							w = iptr->Contents.w;
							hh = iptr->Contents.h;
							break;
						case	1 :
							simple_area_event(h,iptr,iptr->Contents.x,iptr->Contents.y,iptr->Contents.x+iptr->Contents.w,iptr->Contents.y+iptr->Contents.w,"Up",0);
							x = iptr->Contents.x;
							y = (iptr->Contents.y+iptr->Contents.w);
							w = iptr->Contents.w;
							hh = (iptr->Contents.h-iptr->Contents.w);
							break;
						case	2 :
							x = iptr->Contents.x;
							y = iptr->Contents.y;
							w = iptr->Contents.w;
							hh = (iptr->Contents.h-iptr->Contents.w);
							simple_area_event(h,iptr,iptr->Contents.x,iptr->Contents.y+iptr->Contents.h-iptr->Contents.w,iptr->Contents.x+iptr->Contents.w,iptr->Contents.y+iptr->Contents.h,"Down",0);
							break;
						case	3 :
							simple_area_event(h,iptr,iptr->Contents.x,iptr->Contents.y,iptr->Contents.x+iptr->Contents.w,iptr->Contents.y+iptr->Contents.w,"Up",0);
							x = iptr->Contents.x;
							y = (iptr->Contents.y+iptr->Contents.w);
							w = iptr->Contents.w;
							hh = (iptr->Contents.h-(iptr->Contents.w*2));
							simple_area_event(h,iptr,iptr->Contents.x,iptr->Contents.y+iptr->Contents.h-iptr->Contents.w,iptr->Contents.x+iptr->Contents.w,iptr->Contents.y+iptr->Contents.h,"Down",0);
							break;
						}
					}
				else	{
					/* horizontal scroll bar */
					switch ( iptr->Contents.align & 3 ) {
						case	0 :
							x = iptr->Contents.x;
							y = iptr->Contents.y;
							w = iptr->Contents.w;
							hh = iptr->Contents.h;
							break;
						case	1 :
							simple_area_event(h,iptr,iptr->Contents.x,iptr->Contents.y,iptr->Contents.x+iptr->Contents.h,iptr->Contents.y+iptr->Contents.h,"Up",0);
							x = (iptr->Contents.x+iptr->Contents.h);
							y = iptr->Contents.y;
							hh = iptr->Contents.h;
							w = (iptr->Contents.w-iptr->Contents.h);
							break;
						case	2 :
							x = iptr->Contents.x;
							y = iptr->Contents.y;
							hh = iptr->Contents.h;
							w = (iptr->Contents.w-iptr->Contents.h);
							simple_area_event(h,iptr,iptr->Contents.x+iptr->Contents.w-iptr->Contents.h,iptr->Contents.y,iptr->Contents.x+iptr->Contents.w,iptr->Contents.y+iptr->Contents.h,"Down",0);
							break;
						case	3 :
							simple_area_event(h,iptr,iptr->Contents.x,iptr->Contents.y,iptr->Contents.x+iptr->Contents.h,iptr->Contents.y+iptr->Contents.h,"Up",0);
							x = (iptr->Contents.x+iptr->Contents.h);
							y = iptr->Contents.y;
							hh = iptr->Contents.h;
							w = (iptr->Contents.w-(iptr->Contents.h*2));
							simple_area_event(h,iptr,iptr->Contents.x+iptr->Contents.w-iptr->Contents.h,iptr->Contents.y,iptr->Contents.x+iptr->Contents.w,iptr->Contents.y+iptr->Contents.h,"Down",0);
							break;
						}
					}
				if ( ActiveAgentImages ) {
					simple_area_event(h,iptr,x,y,x+w,y+hh,"Click",0);
					}
				continue;

			case	_BUTTON_FRAME	:	

				html_open_tag(h,"area");
				html_field(h,"shape","rect");

				if ( method_is_valid( abal_hint(iptr) ) )
					html_field(h,"title",abal_hint(iptr));

				if ( method_is_valid( abal_payload(iptr) ) )
					html_field(h,"alt",abal_payload(iptr));

				simple_area_over_and_out( h, iptr );

				switch ( iptr->Contents.datatype ) {
					case _WIDGET_HYPERLINK 	:
						if ( Restriction )
							simple_hyperlink_restriction(h,iptr);
						else 	simple_href(h,iptr);
						break;
					default			:
						html_submit_field(h,iptr,(char *) 0,"Event");			
						break;
					}
				simple_area_cursor(h);
				if ( wptr ) {
					fprintf(h,"coords=%c%u,%u,%u,%u%c",
						__QUOTE,
						iptr->Contents.x, iptr->Contents.y,
						iptr->Contents.x+iptr->Contents.w,
						iptr->Contents.y+iptr->Contents.h,__QUOTE);
					}
				else	{
					fprintf(h,"coords=%c%u,%u,%u,%u%c",
						__QUOTE,
						iptr->Contents.x, iptr->Contents.y,
						iptr->Contents.x+iptr->Contents.w,
						iptr->Contents.y+iptr->Contents.h,__QUOTE);
					}
				fprintf(h,">");
				linefeed(h);
				continue;
			}
		}
	html_close_map( h );
	return;
}

private	char *	simple_form_image_name( char * nptr, int pageid, char * prefix )
{
	char			* iname;
	char 			* ipath;
	int			i;

	if ( ActiveAgentImages ) {
		return(allocate_string("<widget name=SessionImage>"));
		}
	else if (!(iname = allocate( strlen( nptr ) + 64 ))) {
		return( iname );
		}
	else	{
		if (!( pageid ))
			strcpy(iname,nptr);
		else	sprintf(iname,"page%u_%s",pageid,nptr);
		if ( prefix )
			iname = path_prefix( iname, prefix );
		if (( ipath = allocate( 1024 )) != (char *) 0) {
			getcwd(ipath,1023);
			if ( strlen(ipath) > 1 ) {
#ifdef	UNIX
				strcat(ipath,"/");
#else
				strcat(ipath,"\\");
#endif
				strcat(ipath,iname);
				}
			liberate(iname);
			}
		else	ipath = iname;
#ifdef	WIN32
		/* Windows requires Device to be removed */
		/* ------------------------------------- */
		if (!( iname = allocate_string( ipath )))
			return( ipath );
		else	{
			fn_parser(ipath,iname,0x001C );
			liberate( ipath );
			/* Convert back to forward slash */
			/* ----------------------------- */
			for (i=0; *(iname+i) != 0; i++ )
				if ( *(iname+i) == '\\' )
					*(iname+i) = '/';
			return(iname);
			}
#else
		return( ipath );
#endif
		}
}

private	int	simple_form_image(  FILE * h, struct form_control * fptr, struct form_item * wptr, char * nptr, int pageid, char * prefix )
{
	char			* iname;
	/* ---------------------- */
	/* form image instruction */
	/* ---------------------- */
	if (!( iname = simple_form_image_name( nptr, pageid, prefix ) ))
		return(0);
	else	{
		fprintf(h,"<img ");
		if (!( fptr->resizeauto )) 
			fprintf(h,"class=noborder");
		else if (!( wptr ))
			fprintf(h,"class=noborder");
		else	fprintf(h,"id=i_%s",prefixed_widget_name(wptr));
		fprintf(h," src=%c%s%c alt=%c%s%c",
			__QUOTE,iname,__QUOTE,
			__QUOTE,fptr->identifier,__QUOTE);
		fprintf(h," usemap=%c#%s%c",__QUOTE,fptr->identifier,__QUOTE);
			
		fprintf(h,">");
		if (!( ActiveAgentImages )) {
			server_interface_record(iname,_WSI_IMAGE);
			}
		if ( iname ) {
			liberate( iname );
			}
		return(0);
		}
}

private	void	simple_form_edit( FILE * h, struct form_item * iptr )
{
	int		linelength=0;
	int		nblines=0;

	if (!( iptr ))
		return;
	if ( iptr->Contents.datatype == _WIDGET_HYPERLINK )
		simple_edit_href_division(h, iptr);
	else if ( iptr->Contents.datatype == _WIDGET_KONSTANT )
		simple_edit_division(h, iptr);
	else	{
		calculate_edit_size( &iptr->Contents );
		calculate_form_lines( iptr, &linelength, &nblines );
		/* test for multi line edit field */
		if ( nblines > 1 ) {
			fprintf(h,"<textarea id=%c%s%c name=%s ",
				__QUOTE,prefixed_widget_name(iptr),
				__QUOTE,prefixed_widget_name(iptr) );
			html_int_field(h,"cols",linelength);
			html_int_field(h,"rows",nblines);
			if (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS ))
				fprintf(h," readonly ");			
			else	html_standard_change(h,iptr);
			html_close_tag(h,"textarea");
			linefeed(h);
			fprintf(h,"<widget name=%s.buffer>",prefixed_widget_name(iptr));
			linefeed(h);
			html_closure(h,"textarea");
			linefeed(h);
			}
		else	{
			/* single line edit field */
			/* ---------------------- */
			fprintf(h,"<input id=%c%s%c name=%s type=text",
				__QUOTE,prefixed_widget_name(iptr),__QUOTE,
				prefixed_widget_name(iptr));
			if (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS ))
				fprintf(h," readonly ");			
			else	html_standard_change(h,iptr);
			fprintf(h," value=%c<widget name=%s.buffer>%c",
				__QUOTE,prefixed_widget_name(iptr),__QUOTE);
			fprintf(h,">\n");
			}
		}
	return;
}

private	int	simple_widget_cells(  FILE * h, struct form_control * fptr, int pageid )
{
	char	* sptr;
	struct	form_item * iptr;
	struct	form_control * vfptr;
	for (	iptr = fptr->first;
		iptr != (struct form_control *) 0;
		iptr = iptr->next ) {

		if (( iptr->Contents.page ) && ( iptr->Contents.page != pageid ) && (( iptr->Contents.style & _FRAME_TYPE )!= _TAB_FRAME))
			continue;

		else if ((!( iptr->Contents.w )) || (!( iptr->Contents.h )))
			continue;

		else if (iptr->Contents.events->xo_show & _EVENT_IS_COND )
			continue;

		switch (( iptr->Contents.style & _FRAME_TYPE )) {

			case	_IMAGE_FRAME	:
				if ( iptr->Contents.datatype == _WIDGET_HYPERLINK ) 
					if ( method_is_valid( abal_payload(iptr) ) )
						simple_image_division(h,iptr,abal_payload( iptr ) );
				continue;

			case	_TEXT_FRAME	:
				if ( iptr->Contents.datatype == _WIDGET_HYPERLINK )
					if ( method_is_valid( abal_payload(iptr) ) )
						simple_text_division(h,iptr,abal_payload(iptr));
				continue;

			case	_TAB_FRAME	:	
				/* needs trigger zone */
				continue;
				simple_click_division(h,iptr);
				continue;

			case	_SCROLL_FRAME	:
				/* needs position zone */
				html_open_tag(h,"input");
				html_field(h,"type","hidden");
				html_field(h,"name",prefixed_widget_name(iptr) );
				fprintf(h," value=%c<widget name=%s.value>%c",__QUOTE,prefixed_widget_name(iptr),__QUOTE);
				html_close_tag(h,"input");
				linefeed(h);
				scroll_click_division(h,iptr);
				continue;

			case	_BUTTON_FRAME	:
				/* needs trigger zone */
				continue; 	
				switch ( iptr->Contents.datatype ) {
					case _WIDGET_HYPERLINK 	:
						simple_href_division(h,iptr);
						continue;
					default			:
						simple_click_division(h,iptr);
						continue;
					}

			case	_EDIT_FRAME	:
				/* needs form edit */
				simple_form_edit( h, iptr );
				continue;
			case	_CHECK_FRAME	:
				/* needs form check */
				fprintf(h,"<input id=%c%s%c name=%s type=checkbox",
					__QUOTE,prefixed_widget_name(iptr),__QUOTE,
					prefixed_widget_name(iptr));
				fprintf(h," <widget name=%s> ",prefixed_widget_name(iptr));
				html_standard_change(h,iptr);
				fprintf(h,">\n");
				continue;
			case	_RADIO_FRAME	:
				/* needs form radio */
				fprintf(h,"<input id=%c%s_%u%c name=%s type=radio value='%u'",
					__QUOTE,prefixed_widget_name(iptr),iptr->Contents.radio,__QUOTE,
					prefixed_widget_name(iptr),iptr->Contents.radio);
				fprintf(h," <widget name=%s%u> ",prefixed_widget_name(iptr),iptr->Contents.radio);
				fprintf(h,">\n");
				continue;
			case	_SWITCH_FRAME	:
				/* needs form switch */
				message_click_division(h,iptr);
				continue;
			case	_SELECT_FRAME	:
				/* needs form select */
				fprintf(h,"<select id=%c%s%c name=%s",
					__QUOTE,prefixed_widget_name(iptr),__QUOTE,
					prefixed_widget_name(iptr));
				html_standard_change(h,iptr);
				fprintf(h,">\n");
				if ( abal_payload(iptr) ) {
					fprintf(h,"<widget name=%s>\n",prefixed_widget_name(iptr));
					}
				fprintf(h,"</select>\n");
				continue;
			case	_FORM_FRAME	:
				/* needs form table */
				if (( ActiveAgentImages )
				&&  (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS ))) {
					(void) simple_table_events( h, iptr );
					continue;
					}
				else 	simple_table_cells( h, iptr );
				continue;
			case	_DATA_FRAME	:
				if (( iptr->Contents.align & 0x000F ) != _VISUAL_FRAME)
					continue;
				else if ( iptr->Contents.datatype != _WIDGET_OVERLAY )
					continue;
				else if (!( method_is_valid((sptr = abal_payload( iptr )) ) ))
					continue;
				else if (!( vfptr = locate_form_control( sptr ) ))
					continue;
				else	prefix_simple_widget_cells(h,vfptr,pageid,iptr->Contents.name);
			default			:
				continue;
			}
		}
	return;
}

private	int	prefix_simple_widget_cells(  FILE * h, struct form_control * fptr, int pageid, char * prefix )
{
	char * pptr;
	pptr = set_widget_prefix( prefix );
	simple_widget_cells(h,fptr,pageid);
	set_widget_prefix( pptr );
	return;
}


private	int	simple_html_image_form(  FILE * h, struct form_control * fptr, struct form_item * wptr, char * nptr, int pageid, char * prefix )
{
	char 			* iname;
	int			  i;
	struct	form_item 	* iptr;
	char			* mptr;
	int			  c;
	/* -------------------------------- */
	/* document header, title and style */
	/* -------------------------------- */
	fprintf(h,"<html>\n<head>\n<title>%s</title>\n",fptr->identifier);

#ifdef	_NOT_REQUIRED
	if ( method_is_valid( fptr->stylesheet) ) {
		html_open_tag(h,"link");
			html_field(h,"href",fptr->stylesheet);
			html_field(h,"type","text/css");
			html_field(h,"rel","stylesheet");
			html_field(h,"media","screen");
		html_close_tag(h,"link");
		linefeed(h);
		}
#endif
	/* ------------------------------ */
	/* generate widget identity style */
	/* ------------------------------ */
	html_open_tag(h,"style");
	html_field(h,"media","screen");
	html_field(h,"type","text/css");
	html_close_tag(h,"style");
	linefeed(h);
		fprintf(h,"a.noborder   { border-style: none; border-width: 0px; }\n");
		fprintf(h,"img.noborder { border-style: none; border-width: 0px; }\n");
		simple_visual_style(h,fptr,wptr,pageid);	
	html_closure(h,"style");
	linefeed(h);
	simple_visual_script(h,fptr,wptr,pageid);	
	fprintf(h,"</head>\n",fptr->identifier);

	/* --------------------------------------- */
	/* eventual background or body style class */
	/* --------------------------------------- */
	if (!( method_is_valid( fptr->clearscreen ) )) {
		fprintf(h,"<body id=%csing%c ",__QUOTE,__QUOTE);
		}
	else	{
		fprintf(h,"<body id=%csing%c class=%c%s%c",__QUOTE,__QUOTE,__QUOTE,fptr->clearscreen,__QUOTE);
		}

	fprintf(h," onload='%sCreate();'",fptr->identifier,fptr->identifier);

	fprintf(h,">");

	linefeed(h);
	html_open_tag(h,"form");
	html_field(h,"name",fptr->identifier);
	html_field(h,"action",fptr->prodname);
	html_field(h,"enctype","application/x-www-form-urlencoded");
	html_field(h,"method","GET");
	html_close_tag(h,"form");
	linefeed(h);

	/* apply form alignment */
	/* -------------------- */
	if ( wptr ) {
		switch ((wptr->Contents.align & 7)) {
			case	0	:	break;
			case	1 	:	fprintf(h,"<div align=right>");
						linefeed(h);
			case	2 	:	fprintf(h,"<div align=left>");
						linefeed(h);
			case	3 	:
			case	4	:	fprintf(h,"<div align=center>");
						linefeed(h);
			}

		fprintf(h,"<div id=%s><div align=left>",prefixed_widget_name(wptr));	
		}

	simple_form_image( h, fptr, wptr, nptr, pageid, prefix );

	/* ------------------------------------------------------- */
	/* Microsoft IE does not allow user click on empty div !!! */
	/* so all push buttons and tab buttons must be area mapped */
	/* ------------------------------------------------------- */

	simple_image_map( h, fptr, pageid );

	if ( wptr ) {	
#ifdef	USING_COPYRIGHT_ETC
		if ( Restriction ) {
			fprintf(h,"<div id=__show onclick=%c_SingBrowserShow(false);%c>",__QUOTE,__QUOTE);
			fprintf(h,"<i>%s</i>",_DEFAULT_BROWSER_SHOW);
			fprintf(h,"</div>\n");	
			fprintf(h,"<div id=__copyright>");
			fprintf(h,"<i>%s</i>",_DEFAULT_COPYRIGHT);
			fprintf(h,"</div>\n");	
			fprintf(h,"<div id=__hide onclick=%c_SingBrowserHide();%c>",__QUOTE,__QUOTE);
			fprintf(h,"<i>%s</i>",_DEFAULT_BROWSER_HIDE);
			fprintf(h,"</div>\n");	
			}
#endif
		if ( Restriction ) {
			}
		if ( fptr->formflags & _FORM_MULTILINGUAL ) {
			for ( i=0; i < MAXNATLANG; i++ ) {
				fprintf(h,"<div id=__change%u>",i+1);
				html_forms_national_flag(h,fptr,i);
				fprintf(h,"</div>\n");	
				}
			}
		}

	prefix_simple_widget_cells( h, fptr, pageid, "\0" );

	html_open_tag(h,"input");
	html_field(h,"type","hidden");
	html_field(h,"name","Method");
	fprintf(h," value=%c %c",__QUOTE,__QUOTE);
	html_close_tag(h,"input");
	linefeed(h);

	if ( wptr ) { fprintf(h,"</div></div>\n");	}

	/* close form alignment */
	/* -------------------- */
	if ( wptr ) {
		switch ((wptr->Contents.align & 7)) {
			case	0	:
				break;
			case	1 	:	
			case	2 	:	
			case	3 	:
			case	4	:
				fprintf(h,"</div>");
				linefeed(h);
			}
		}

	html_closure(h,"form");

	/* --------------- */
	/* end of document */
	/* --------------- */
	fprintf(h,"</body>\n</html>\n");


	return(0);
}

private	int	simple_html_image_tabset(  FILE * h, struct form_control * fptr, struct form_item * wptr, char * nptr )
{
	int	i;
	FILE *	wh;
	char	hbuffer[256];
	char *	pnptr;
	int	pageholder;
	if (!( fptr )) return(0);
	pageholder=fptr->page_number;
	for (	i=1; i <= fptr->pages; i++ ) {
		if (!( fptr->formflags &_MULTILINGUAL )) {
			sprintf(hbuffer,"page%u_%s",i,fptr->prodname);
			if ((pnptr = use_product_directory( hbuffer )) != (char *) 0) {
				if (( wh = open_production_target(pnptr,0)) != (FILE *) 0) {
					simple_html_image_form( wh, fptr, wptr, nptr, i,(char *) 0 );
					sprintf(hbuffer,"page%u_%s",i,fptr->prodname);
					close_production_target(wh,pnptr);
					}
				liberate( pnptr );
				}
			}
		}
	fptr->page_number=pageholder;
	return(0);
}

public	int	export_html_image_form(  FILE * h, int mode, int automatic, int restrikt, int parametric, int points )
{
	int	i;
	int	autotrad=0;
	struct	form_control 	* fptr;
	struct	form_item 	* wptr;
	struct	form_item 	* iptr;
	char			* xptr;
	char			* nptr;
	int	holder;
	char *	natfic=(char *) 0;
	char	*	inptr;
	FILE	*	wh;
	int	pageholder;

	set_parametrics( points, parametric );

	WSI.lock = 0;
	GenerateDebug = 0;
	decalagex = decalagey = 0;
	if ( restrikt & 1 )
		Restriction = 1;
	else	Restriction = 0;
	if ( restrikt & 2 )
		ActiveAgentImages = 1;
	else	ActiveAgentImages = 0;

	if (!( fptr = Context.Form ))
		return(0);
	else if (!( inptr = allocate_string( fptr->prodname )))
		return(0);

	if ((xptr = image_extension( form_imagetype( fptr ) )) != (char *) 0)
		inptr = enforce_extension(inptr,xptr);

	generate_form_images(fptr, inptr );
	/* ----------------------------- */
	/* locate eventual window widget */
	/* ----------------------------- */
	for (	wptr=fptr->first;
		wptr != (struct form_item *) 0;
		wptr = wptr->next ) 
		if ((wptr->Contents.style & _FRAME_TYPE) == _WINDOW_FRAME)
			break;

	if (!( open_server_description(Context.Form,1)))
		return(0);

	/* ----------------------------------------------------- */
	/* Check for and recalculate window with left/top margin */
	/* ----------------------------------------------------- */
	if ( wptr )  {
		decalagex= wptr->Contents.x;
		decalagey= wptr->Contents.y;
		if ((decalagex != 0) || ( decalagey != 0)) {
			for (	iptr=fptr->first;
				iptr != (struct form_item *) 0;
				iptr = iptr->next ) {
				iptr->Contents.x -= decalagex;
				iptr->Contents.y -= decalagey;
				}
			}
		}

	if (!( fptr->formflags &_MULTILINGUAL )) {
		if (!( fptr->pages ))
			simple_html_image_form(h,fptr,wptr,inptr, 0,(char *) 0 );
		else	simple_html_image_tabset(h,fptr,wptr,inptr);
		}
	else	{
		fprintf(h,"<html><head><title>%s</title></head>\n",fptr->identifier);
		fprintf(h,"<body><p><ol>");
		fprintf(h,"<li><a href=%cen/%s%c>English</a>",__QUOTE,fptr->prodname,__QUOTE);
		fprintf(h,"<li><a href=%cfr/%s%c>Fran&ccedil;ais</a>",__QUOTE,fptr->prodname,__QUOTE);
		fprintf(h,"<li><a href=%cde/%s%c>Deutsch</a>",__QUOTE,fptr->prodname,__QUOTE);
		fprintf(h,"<li><a href=%cit/%s%c>Italiano</a>",__QUOTE,fptr->prodname,__QUOTE);
		fprintf(h,"<li><a href=%ces/%s%c>Espagnol</a>",__QUOTE,fptr->prodname,__QUOTE);
		fprintf(h,"<li><a href=%cnl/%s%c>Nederlands</a>",__QUOTE,fptr->prodname,__QUOTE);
		fprintf(h,"<li><a href=%cpt/%s%c>Portugues</a>",__QUOTE,fptr->prodname,__QUOTE);
		fprintf(h,"<li><a href=%cxx/%s%c>Other</a>",__QUOTE,fptr->prodname,__QUOTE);
		fprintf(h,"</ol><p></body></html>\n");
		holder = fptr->natlang;
		for (	fptr->natlang=0; fptr->natlang < MAXNATLANG; fptr->natlang++ ) {
			switch ( fptr->natlang ) {
				case	0 : nptr = "en"; break;
				case	1 : nptr = "fr"; break;
				case	2 : nptr = "it"; break;
				case	3 : nptr = "es"; break;
				case	4 : nptr = "de"; break;
				case	5 : nptr = "nl"; break;
				case	6 : nptr = "pt"; break;
				default	  : nptr = "xx"; break;
				}
			mkdir(nptr,0664);
			if (( natfic = allocate( strlen( nptr ) + strlen( fptr->prodname ) + 64 ) ) != (char *) 0) {
				if (!( fptr->pages )) {
					sprintf(natfic,"%s/%s",nptr,fptr->prodname);
					if (( wh = open_production_target(natfic,0)) != (FILE *) 0) {
						simple_html_image_form(wh,fptr,wptr,inptr,0,nptr);
						close_production_target(wh,natfic);
						}
					}
				else	{
					pageholder=fptr->page_number;
					for (	i=1; i <= fptr->pages; i++ ) {
						sprintf(natfic,"%s/page%u_%s",nptr,i,fptr->prodname);
						if (( wh = open_production_target(natfic,0)) != (FILE *) 0) {
							simple_html_image_form(wh,fptr,wptr,inptr,i,nptr);
							close_production_target(wh,natfic);
							}
						}
					fptr->page_number=pageholder;
					}
				liberate( natfic );
				}
			}
		fptr->natlang = holder;
		}

	/* Release Image Name */
	/* ------------------ */
	liberate( inptr );

	if ( wptr )  {
		/* Reposition the thing */
		if ((decalagex != 0) || ( decalagey != 0)) {
			for (	iptr=fptr->first;
				iptr != (struct form_item *) 0;
				iptr = iptr->next ) {
				iptr->Contents.x += decalagex;
				iptr->Contents.y += decalagey;
				}
			}
		}

	close_server_description();

	/* ---------------------------------------------------------------- */
	/* Start Production of Html Document NOT Wasa Interface Description */
	/* ---------------------------------------------------------------- */
	if ( mode & 1 ) {
		generate_web_agent( fptr, automatic, GenerateDebug, 1 );
		if (!( automatic & _INHIBIT_PROPERTIES )) {
			autotrad = abal_production_parameters(fptr);
			}
		}


	return(autotrad);
}
			
#endif	/* _singwag_c */
	/* ---------- */


