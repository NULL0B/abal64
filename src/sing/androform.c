/*	Android Forms Production for SING	*/
/*	---------------------------------	*/
/*	Copyright (c) 2015 Amenesik		*/
/*	---------------------------------	*/
/*	Author	  Iain James Marshall		*/
/*	---------------------------------	*/

#ifndef	_androform_c
#define	_androform_c

#include "androfile.h"
#include "androform.h"

/* ---------------------------------------------- */
/* set the default options controlling production */
/* ---------------------------------------------- */
private	struct android_options	AndroidOption = 
{ 
	(char *) 0,
	0,	/* use sql cipher	*/
	0,	/* inherit not extends	*/
	16,	/* android version 	*/
	1,	/* use camera		*/
	0,	/* use gps		*/
	1, 	/* use files		*/
	_ABSOLUTE_LAYOUT, 
	1,	/* Network Devices 	*/
	1,	/* Near Field Devices 	*/	
	AMENESIK_DOMAIN,
	"AppTheme",
	"ic_launcher",
	"v1.0",
	10,
	0	/* visual style */
};

private	char 	AndroColourMap[256];
private	struct	android_import * importRoot=(struct android_import *) 0;
private	int	android_member_events( FILE * h, char * domain, struct form_control * fptr );
private	int	android_basemember_events( FILE * h, char * domain, char * extends );
private	int	android_member_call_hide( FILE * h, char * domain,struct form_control * fptr );
private	int	android_member_call_show( FILE * h, char * domain,struct form_control * fptr );
public  struct forms_method * detect_forms_method( struct form_control * fptr, char * nptr );
private	void	android_method_body( FILE * h, char * sptr );
private	void	generate_forms_activity( FILE * h, struct form_control * fptr, int mode );
private	void	android_forms_layouts( FILE * h, char * domain, struct form_control * fptr, char * pathroot, char * rootpath );
private	void	release_android_activities();
private	int	unique_android_activity( char * sptr );


private	void	android_warning( struct form_control* fptr, char * m1, char * m2, char * m3 )
{

	printf("ANDROID:WARNING: Form %s: %s %s %s ***\r\n",fptr->identifier,m1,m2,m3);
	return;
}

/*	-----------------------------------	*/
/*	a n d r o i d _ x m l _ h e a d e r	*/
/*	-----------------------------------	*/
private	void	android_xml_header(FILE * h)
{
	fprintf(h,"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n");
	return;
}

/*	------------------------------------	*/
/*	a n d r o i d _ n l _ p a y l o a d 	*/
/*	------------------------------------	*/
private	char *	android_nl_payload( struct form_item * iptr, int nl )
{
	struct	form_control * fptr;
	int	holder=0;
	char *	result = (char *) 0;
	if (!( fptr = iptr->parent ))
		return( abal_payload( iptr ) );
	else 
	{
		holder = fptr->natlang;
		fptr->natlang = nl;
		result = abal_payload( iptr );
		fptr->natlang = holder;
		if (!( result ))
			return(abal_payload( iptr ) );
		else	return( result );
	}
}

/*	---------------------------------------------		*/
/*	a n d r o i d _ c h e c k _ d i r e c t o r y 		*/
/*	---------------------------------------------		*/
private	int	android_check_directory( char * path )
{
	char *	sptr;
	char *	rptr;
	int	c;
	if (!( path ))
		return(0);
	else if (!( rptr = allocate_string( path ) ))
		return( 0 );
	else
	{
		sptr = rptr;
		while (1)
		{
			if (( *sptr == '/' ) || ( *sptr == 0 ))
			{
				c = *sptr;
				*sptr = 0;
				mkdir( rptr, 0666 );
				*sptr = c;
				if (!( c )) break;
			}
			sptr++;
		}
		liberate( rptr );
		return(0);
	}
}

/*      ----------------------------------------------------------      */
/*      	a n d r o i d _ w i d g e t _ l a b e l                 */
/*      ----------------------------------------------------------      */
private int     android_widget_label( struct form_item * iptr )
{
        switch ((iptr->Contents.style & _FRAME_TYPE))
        {
        case    _SELECT_FRAME   :
		return( 3 );
        case    _SWITCH_FRAME   :
		return(2);
        case    _FORM_FRAME     :
        case    _IMAGE_FRAME    :
        case    _TEXT_FRAME     :
        case    _BUTTON_FRAME   :
        case    _CHECK_FRAME    :
        case    _RADIO_FRAME    :
        case    _WINDOW_FRAME   :
        case    _TAB_FRAME      :
                return( 1 );
        default                 :
                return( 0 );
        }
}

/*	---------------------------------	*/
/*	a n d r o i d _ c u t p o i n t   	*/
/*	---------------------------------	*/
/*	cuts a string at the first '.'		*/
/*	---------------------------------	*/
private	void	android_cutpoint( char * rptr )
{
	int	i;
	for ( i=0; *(rptr+i) != 0; i++ )
		if ( *(rptr+i) == '.' )
			*(rptr+i) = 0;
	return;
}

/*	---------------------------------	*/
/*	a n d r o i d _ l o w e r c a s e 	*/
/*	---------------------------------	*/
/*	transforms a string to lower case	*/
/*	---------------------------------	*/
private	void	android_lowercase( char * rptr, char * sptr, char * tptr )
{
	int	c;
	if ( sptr )
	{
	while ((c = *(sptr++)) != 0 )
	{
		if (( c >= 'A' ) && ( c <= 'Z' ))
			c = ((c - 'A') + 'a');
		*(rptr++) = c;	
	}
	}
	if ( tptr )
	{
	while ((c = *(tptr++)) != 0 )
	{
		if (( c >= 'A' ) && ( c <= 'Z' ))
			c = ((c - 'A') + 'a');
		*(rptr++) = c;	
	}
	}
	*(rptr++) = 0;
	return;
}

/*	---------------------------------------		*/
/*	a n d r o i d _ w i n d o w _ t i t l e 	*/
/*	---------------------------------------		*/
private	char *	android_window_title( struct form_control * fptr )
{
	struct	form_item * iptr;
	for ( 	iptr=fptr->first;
		iptr != (struct form_item * )0;
		iptr = iptr->next)
		if (( iptr->Contents.style & _FRAME_TYPE) == _WINDOW_FRAME)
			return( abal_payload( iptr ) );
	return( (char *) 0 );
}

/*	---------------------------------------------		*/
/*	a n d r o i d _ l a y o u t _ t e x t v i e w 		*/
/*	---------------------------------------------		*/
private	void android_layout_textview( FILE * h, struct form_item * iptr, int align )
{
	int	fw;
	int	fh;
	int	fg;
	int	bg;
	/* ---------------- */
	/* set text colours */
	/* ---------------- */
	bg = (iptr->Contents.colour & 0x00FF); fg = (bg & 0x00FF); bg >>= 8;
	if ( bg ) fprintf(h," android:background=\"@color/rgb%u\"",bg);
	fprintf(h," android:textColor=\"@color/rgb%u\"",fg);
	/* --------------------------------------- */
	/* set text size decoration and alignement */
	/* --------------------------------------- */
	fw = guifontsize(iptr->Contents.font);
       	fh = (fw >> 8); fw &= 0x00FF;

	fprintf(h," android:textSize=\"%udp\"",fh);

	if ( align & _A_BOLD )
		fprintf(h," android:textStyle=\"bold\"");
	if ( align & _A_SHADOW )
		fprintf(h," android:textStyle=\"italic\"");
	switch (( align & 7))
	{
	case	_A_CENTER	:
	case	_A_JUSTIFY	:
		fprintf(h," android:gravity=\"center_horizontal\"");
		break;
	case	_A_RIGHT 	:
		fprintf(h," android:gravity=\"end\"");
		break;
	case	_A_LEFT	:
	default		:
		fprintf(h," android:gravity=\"start\"");
		break;
	}
	return;
}

/*	------------------------------------------------	*/
/*	  g e n e r a t e_ a n d r o i d _ l a y o u t		*/
/*	------------------------------------------------	*/
private	int	generate_android_layout( FILE * h, struct form_control * fptr, char * domain )
{
	int 	layout;
	struct	form_item * iptr;
	char *	pptr;
	char *	scale=(char *) 0;
	int	fw;
	int	fh;
	int	fg;
	int	bg;
	int	colcount=0;
	int	rowcount=0;
        struct window_control Window;
	char	buffer[2048];
	int	adjust=10;
	char *	fnptr;
	struct	forms_method * mptr;
	if ((mptr = detect_forms_method( fptr, _JAVA_SCROLL)) != (struct forms_method *) 0)
		layout = _SCROLL_LAYOUT;
	else if ((mptr = detect_forms_method( fptr, _JAVA_FIXED)) != (struct forms_method *) 0)
		layout = _ABSOLUTE_LAYOUT;
	else if ((mptr = detect_forms_method( fptr, _JAVA_LINEAR)) != (struct forms_method *) 0)
		layout = _LINEAR_LAYOUT;
	else if ((mptr = detect_forms_method( fptr, _JAVA_RELATIVE)) != (struct forms_method *) 0)
		layout = _RELATIVE_LAYOUT;
	else	layout = AndroidOption.handle_layout;

	form_Dimensions( &Window, fptr );

	android_xml_header(h);
	switch ( layout )
	{
	case	_LINEAR_LAYOUT	:
		fprintf(h,"<LinearLayout\n");
		fprintf(h,"xmlns:android=\"http://schemas.android.com/apk/res/android\" \n");
		fprintf(h,"android:layout_width=\"match_parent\" \n");
	    	fprintf(h,"android:layout_height=\"match_parent\"  \n");
		if ( Window.w > Window.h )
	    		fprintf(h,"android:orientation=\"vertical\"  \n");
		else 	fprintf(h,"android:orientation=\"vertical\"  \n");
		fprintf(h,">\n");
		break;
	case	_RELATIVE_LAYOUT	:
		fprintf(h,"<RelativeLayout \n");
		fprintf(h,"xmlns:android=\"http://schemas.android.com/apk/res/android\" \n");
		fprintf(h,"android:layout_width=\"match_parent\" \n");
	    	fprintf(h,"android:layout_height=\"match_parent\"  \n");
		fprintf(h,"android:paddingLeft=\"@dimen/activity_horizontal_margin\" \n");
	    	fprintf(h,"android:paddingRight=\"@dimen/activity_horizontal_margin\" \n");
	    	fprintf(h,"android:paddingTop=\"@dimen/activity_vertical_margin\" \n");
	    	fprintf(h,"android:paddingBottom=\"@dimen/activity_vertical_margin\"  \n");
		fprintf(h,">\n");
		break;
	case	_SCROLL_LAYOUT	:
		fprintf(h,"<ScrollView \n");
		fprintf(h,"xmlns:android=\"http://schemas.android.com/apk/res/android\" \n");
		fprintf(h,"android:layout_width=\"fill_parent\" \n");
	    	fprintf(h,"android:layout_height=\"fill_parent\"  \n");
	    	fprintf(h,"android:layout_centerInParent=\"true\"\n");
		fprintf(h,">\n");
		fprintf(h,"<AbsoluteLayout \n");
		fprintf(h,"xmlns:android=\"http://schemas.android.com/apk/res/android\" \n");
		fprintf(h,"android:layout_width=\"%udp\"\n",Window.w);
	    	fprintf(h,"android:layout_height=\"%udp\"\n",Window.h);
	    	fprintf(h,"android:layout_centerInParent=\"true\"\n");
		fprintf(h,">\n");
		break;
	case	_ABSOLUTE_LAYOUT	:
		fprintf(h,"<RelativeLayout \n");
		fprintf(h,"xmlns:android=\"http://schemas.android.com/apk/res/android\" \n");
		fprintf(h,"android:layout_width=\"fill_parent\" \n");
	    	fprintf(h,"android:layout_height=\"fill_parent\"  \n");
		if ( method_is_valid(fptr->clearscreen))
		{
		   	fprintf(h,"android:background=\"@color/%s\" \n",fptr->clearscreen);
		}
	    	fprintf(h,"android:layout_centerInParent=\"true\"\n");
		fprintf(h,">\n");
		fprintf(h,"<AbsoluteLayout \n");
		fprintf(h,"xmlns:android=\"http://schemas.android.com/apk/res/android\" \n");
		fprintf(h,"android:layout_width=\"%udp\"\n",Window.w);
	    	fprintf(h,"android:layout_height=\"%udp\"\n",Window.h);
	    	fprintf(h,"android:layout_centerInParent=\"true\"\n");
		fprintf(h,">\n");

	}

	/* ----------------------------------- */
	/* set edit field vertical adjustment  */
	/* to pull them back up towards labels */
	/* ----------------------------------- */
	adjust = 10;

	/* --------------------------- */
	/* Process the list of widgets */
	/* --------------------------- */
	for ( 	iptr = fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		switch ((iptr->Contents.style & _FRAME_TYPE))
		{
		/* ---------------- */
		/* control elements */
		/* ---------------- */
		case	_BUTTON_FRAME :
			/* 0 : Framed Text, 1: Framed Image, 2: Unframed Text, 3: Unframed Image */
			/* ------------------- */
			/* is it a text button */
			/* ------------------- */
			if (!( iptr->Contents.align & 1))
			{
				if ( iptr->Contents.align & 2)
				{
					/* Unframed Text */
					fprintf(h,"<TextView android:id=\"@+id/%s%s\"",fptr->identifier,iptr->Contents.name); 
					android_layout_textview( h, iptr,_A_LEFT|_A_BOLD );
				}
				else
					/* Framed Text */
				{ 
					fprintf(h,"<Button android:id=\"@+id/%s%s\"",fptr->identifier,iptr->Contents.name); 
					if ( AndroidOption.visualStyle )
					{
						fprintf(h," style=\"@style/visualbutton\"" );
						fprintf(h," android:background=\"@drawable/visualbutton\"" );
					}
				}

				if (( layout == _ABSOLUTE_LAYOUT )
				|| ( layout == _SCROLL_LAYOUT ))
				{
					fprintf(h," android:layout_x=\"%udp\"\n",iptr->Contents.x);
					fprintf(h," android:layout_y=\"%udp\"\n",iptr->Contents.y);
					fprintf(h," android:layout_width=\"%udp\"\n",iptr->Contents.w);
					fprintf(h," android:layout_height=\"%udp\"\n",iptr->Contents.h);
				}
				else
				{ fprintf(h," android:layout_width=\"wrap_content\" android:layout_height=\"wrap_content\""); } 

				if ( iptr->Contents.events->xo_show & _EVENT_IS_COND )
				{ fprintf(h," android:visibility=\"invisible\""); }

				if (method_is_valid( iptr->Contents.events->on_event ) )
				{ fprintf(h," android:onClick=\"%sEvent\"",iptr->Contents.name); }

				fprintf(h," android:text=\"@string/%s%sLabel\"/>\n",fptr->identifier,iptr->Contents.name);
			}
			/* ------------------ */
			/* or an image button */
			/* ------------------ */
			else
			{
				if ( iptr->Contents.align & 2)
					/* Unframed Image */
				{ fprintf(h,"<ImageView android:id=\"@+id/%s%s\"",fptr->identifier,iptr->Contents.name); }
				else
					/* Framed Image */
				{ fprintf(h,"<Button android:id=\"@+id/%s%s\"",fptr->identifier,iptr->Contents.name); }

				if (( layout == _ABSOLUTE_LAYOUT )
				|| ( layout == _SCROLL_LAYOUT ))
				{
					fprintf(h," android:layout_x=\"%udp\"\n",iptr->Contents.x);
					fprintf(h," android:layout_y=\"%udp\"\n",iptr->Contents.y);
					fprintf(h," android:layout_width=\"%udp\"\n",iptr->Contents.w);
					fprintf(h," android:layout_height=\"%udp\"\n",iptr->Contents.h);
				}
				else
				{ fprintf(h," android:layout_width=\"wrap_content\" android:layout_height=\"wrap_content\""); }
				if ( iptr->Contents.events->xo_show & _EVENT_IS_COND )
				{ fprintf(h," android:visibility=\"invisible\""); }
				if (method_is_valid( iptr->Contents.events->on_event ) )
				{ fprintf(h," android:onClick=\"%sEvent\"",iptr->Contents.name); }
				android_lowercase( buffer, abal_payload( iptr ), "\0");
				android_cutpoint( buffer );
				fprintf(h," android:src=\"@drawable/%s\"/>\n",buffer);
			}
			break;

		case	_CHECK_FRAME	:
			fprintf(h,"<CheckBox android:id=\"@+id/%s%s\"",fptr->identifier,iptr->Contents.name);
			if ( AndroidOption.visualStyle )
			{
				fprintf(h," style=\"@style/visualcheck\"" );
				fprintf(h," android:background=\"@drawable/visualcheck\"" );
			}
			if (( layout == _ABSOLUTE_LAYOUT )
			|| ( layout == _SCROLL_LAYOUT ))
			{
				fprintf(h," android:layout_x=\"%udp\"\n",iptr->Contents.x);
				fprintf(h," android:layout_y=\"%udp\"\n",iptr->Contents.y);
				fprintf(h," android:layout_width=\"%udp\"\n",iptr->Contents.w);
				fprintf(h," android:layout_height=\"wrap_content\"\n");
			}
			else
			{
				fprintf(h," android:layout_width=\"wrap_content\" android:layout_height=\"wrap_content\"");
			}
			if ( iptr->Contents.events->xo_show & _EVENT_IS_COND )
			{ fprintf(h," android:visibility=\"invisible\""); }
			if (method_is_valid( iptr->Contents.events->on_event ) )
				fprintf(h," android:onClick=\"%sEvent\"",iptr->Contents.name);
			fprintf(h," android:text=\"@string/%s%sLabel\"/>\n",fptr->identifier,iptr->Contents.name);
			break;

		case	_RADIO_FRAME	:
			fprintf(h,"<RadioButton android:id=\"@+id/%s%s\"",fptr->identifier,iptr->Contents.name);
			if (( layout == _ABSOLUTE_LAYOUT )
			|| ( layout == _SCROLL_LAYOUT ))
			{
				fprintf(h," android:layout_x=\"%udp\"\n",iptr->Contents.x);
				fprintf(h," android:layout_y=\"%udp\"\n",iptr->Contents.y-adjust);
				fprintf(h," android:layout_width=\"%udp\"\n",iptr->Contents.w);
				fprintf(h," android:layout_height=\"wrap_content\"\n");
			}
			else
			{
				fprintf(h," android:layout_width=\"wrap_content\" android:layout_height=\"wrap_content\"");
			}
			if ( iptr->Contents.events->xo_show & _EVENT_IS_COND )
			{ fprintf(h," android:visibility=\"invisible\""); }
			if (method_is_valid( iptr->Contents.events->on_event ) )
				fprintf(h," android:onClick=\"%sEvent\"",iptr->Contents.name);
			fprintf(h," android:text=\"@string/%s%sLabel\"/>\n",fptr->identifier,iptr->Contents.name);
			break;

		case	_SWITCH_FRAME	:
			fprintf(h,"<ToggleButton android:id=\"@+id/%s%s\"",fptr->identifier,iptr->Contents.name);
			if ( AndroidOption.visualStyle )
			{
				fprintf(h," style=\"@style/visualswitch\"" );
				fprintf(h," android:background=\"@drawable/visualswitch\"" );
			}
			if (( layout == _ABSOLUTE_LAYOUT )
			|| ( layout == _SCROLL_LAYOUT ))
			{
				fprintf(h," android:layout_x=\"%udp\"\n",iptr->Contents.x);
				fprintf(h," android:layout_y=\"%udp\"\n",iptr->Contents.y-adjust);
				fprintf(h," android:layout_width=\"%udp\"\n",iptr->Contents.w);
				fprintf(h," android:layout_height=\"%udp\"\n",iptr->Contents.h);
			}
			else
			{
				fprintf(h," android:layout_width=\"wrap_content\" android:layout_height=\"wrap_content\"");
			}
			if ( iptr->Contents.events->xo_show & _EVENT_IS_COND )
			{ fprintf(h," android:visibility=\"invisible\""); }
			if (method_is_valid( iptr->Contents.events->on_event ) )
				fprintf(h," android:onClick=\"%sEvent\"",iptr->Contents.name);
			fprintf(h," android:textOn=\"@string/%s%sOnLabel\"",fptr->identifier,iptr->Contents.name);
			fprintf(h," android:textOff=\"@string/%s%sOffLabel\"/>",fptr->identifier,iptr->Contents.name);
			break;

		case	_SELECT_FRAME	:
			fprintf(h,"<Spinner android:id=\"@+id/%s%s\"",fptr->identifier,iptr->Contents.name);
			if ( AndroidOption.visualStyle )
			{
				fprintf(h," style=\"@style/visualselect\"" );
				fprintf(h," android:background=\"@drawable/visualselect\"" );
			}
			if (( layout == _ABSOLUTE_LAYOUT )
			|| ( layout == _SCROLL_LAYOUT ))
			{
				fprintf(h," android:layout_x=\"%udp\"\n",iptr->Contents.x);
				fprintf(h," android:layout_y=\"%udp\"\n",iptr->Contents.y-adjust);
				fprintf(h," android:layout_width=\"%udp\"\n",iptr->Contents.w);
				fprintf(h," android:layout_height=\"wrap_content\"\n");
			}
			else
			{
				fprintf(h," android:layout_width=\"wrap_content\" android:layout_height=\"wrap_content\"");
			}
			if ( iptr->Contents.events->xo_show & _EVENT_IS_COND )
			{ fprintf(h," android:visibility=\"invisible\""); }
			fprintf(h,"/>\n");
			break;

		/* ------------------- */
		/* data input elements */
		/* ------------------- */
		case	_EDIT_FRAME	:
			calculate_edit_lines(iptr,&colcount,&rowcount);
			fprintf(h,"<EditText android:id=\"@+id/%s%s\"",fptr->identifier,iptr->Contents.name);

			if ( AndroidOption.visualStyle )
			{
				fprintf(h," style=\"@style/visualedit\"" );
				fprintf(h," android:background=\"@drawable/visualedit\"" );
			}

			if ( method_is_valid( ( pptr = abal_payload( iptr ) ) )  != 0 )
			{
				fprintf(h," android:hint=\"@string/%s%sHint\"",fptr->identifier,iptr->Contents.name);
			}
			if (( layout == _ABSOLUTE_LAYOUT )
			|| ( layout == _SCROLL_LAYOUT ))
			{
				fprintf(h," android:layout_x=\"%udp\"\n",iptr->Contents.x);
				fprintf(h," android:layout_y=\"%udp\"\n",iptr->Contents.y-adjust);
				fprintf(h," android:layout_width=\"%udp\"\n",iptr->Contents.w);
				if ( rowcount > 1 )
					fprintf(h," android:layout_height=\"%udp\"\n",iptr->Contents.h);
				else	fprintf(h," android:layout_height=\"wrap_content\"\n");
			}
			else
			{ fprintf(h," android:layout_width=\"wrap_content\" android:layout_height=\"wrap_content\""); }
			if ( iptr->Contents.align & _A_LINE )
			{ fprintf(h," android:inputType=\"textPassword\""); }
			if ( rowcount > 1 )
			{
				fprintf(h," android:inputType=\"textMultiLine\"");
				fprintf(h," android:lines=\"%u\"",rowcount);
			}
			else
			{ 
				fprintf(h," android:singleLine=\"true\""); 
			}
			if ( iptr->Contents.events->xo_show & _EVENT_IS_COND )
			{ fprintf(h," android:visibility=\"invisible\""); }
			fprintf(h,"/>\n");
			break;
		/* ---------------- */
		/* complex elements */
		/* ---------------- */
		case	_FORM_FRAME	:
			fprintf(h,"<ListView android:id=\"@+id/%s%s\"",fptr->identifier,iptr->Contents.name);
			if (( layout == _ABSOLUTE_LAYOUT )
			|| ( layout == _SCROLL_LAYOUT ))
			{
				fprintf(h," android:layout_x=\"%udp\"\n",iptr->Contents.x);
				fprintf(h," android:layout_y=\"%udp\"\n",iptr->Contents.y-adjust);
				fprintf(h," android:layout_width=\"%udp\"\n",iptr->Contents.w);
				fprintf(h," android:layout_height=\"%udp\"\n",iptr->Contents.h);
			}
			else
			{
				fprintf(h," android:layout_width=\"wrap_content\" android:layout_height=\"wrap_content\"");
			}
			if ( iptr->Contents.events->xo_show & _EVENT_IS_COND )
			{ fprintf(h," android:visibility=\"invisible\""); }

			fprintf(h," android:padding=\"10dp\"\n");
			if ( AndroidOption.visualStyle )
			{
				fprintf(h," style=\"@style/visualtable\"" );
				fprintf(h," android:background=\"@drawable/visualtable\"\n");
			}
			else
			{
				fprintf(h," android:background=\"@drawable/tableborder\"\n");
			}
			fprintf(h,"/>\n");
			break;
		case	_DATA_FRAME	:
			if ( is_file_Widget( iptr ) )
        	              	continue;
			else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
				continue;
			else if (( iptr->Contents.datatype != _WIDGET_OVERLAY )
			     &&  ( iptr->Contents.datatype != _WIDGET_MODULE  ))
				continue;
			else if (!( fnptr = abal_payload(iptr) ))
                       		continue;
			else if ( strncmp( fnptr, "android:", strlen( "android:" ) ) != 0)
				continue;
			else if (!( strcmp( fnptr, "android:calendar" )))
			{
				fprintf(h,"<CalendarView android:id=\"@+id/%s%s\"",fptr->identifier,iptr->Contents.name);
				if (( layout == _ABSOLUTE_LAYOUT )
				|| ( layout == _SCROLL_LAYOUT ))
				{
					fprintf(h," android:layout_x=\"%udp\"\n",iptr->Contents.x);
					fprintf(h," android:layout_y=\"%udp\"\n",iptr->Contents.y);
					fprintf(h," android:layout_width=\"%udp\"\n",iptr->Contents.w);
					fprintf(h," android:layout_height=\"%udp\"\n",iptr->Contents.h);
				}
				else
				{
					fprintf(h," android:layout_width=\"wrap_content\" android:layout_height=\"wrap_content\"");
				}
				if ( AndroidOption.visualStyle )
				{
					fprintf(h," style=\"@style/calendar\"" );
					fprintf(h," android:background=\"@drawable/calendar\"\n");
				}
				if (method_is_valid( iptr->Contents.events->on_event ) )
					fprintf(h," android:onClick=\"%sEvent\"",iptr->Contents.name);
				fprintf(h," android:shownWeekCount=\"4\"");
				fprintf(h,"/>\n");
			}
			else if (!( strcmp( fnptr, "android:date" )))
			{
				fprintf(h,"<DatePicker android:id=\"@+id/%s%s\"",fptr->identifier,iptr->Contents.name);
				if (( layout == _ABSOLUTE_LAYOUT )
				|| ( layout == _SCROLL_LAYOUT ))
				{
					fprintf(h," android:layout_x=\"%udp\"\n",iptr->Contents.x);
					fprintf(h," android:layout_y=\"%udp\"\n",iptr->Contents.y);
					fprintf(h," android:layout_width=\"%udp\"\n",iptr->Contents.w);
					fprintf(h," android:layout_height=\"%udp\"\n",iptr->Contents.h);
				}
				else
				{
					fprintf(h," android:layout_width=\"wrap_content\" android:layout_height=\"wrap_content\"");
				}
				if ( AndroidOption.visualStyle )
				{
					fprintf(h," style=\"@style/datepicker\"" );
					fprintf(h," android:background=\"@drawable/datepicker\"\n");
				}
				if (method_is_valid( iptr->Contents.events->on_event ) )
					fprintf(h," android:onClick=\"%sEvent\"",iptr->Contents.name);
				fprintf(h," android:shownWeekCount=\"4\"");
				fprintf(h,"/>\n");
			}
			else if (!( strcmp( fnptr, "android:MapFragment" )))
			{
				fprintf(h,"<fragment");
				fprintf(h," xmlns:android=\"%s\"","http://schemas.android.com/apk/res/android");
				fprintf(h," xmlns:map=\"%s\"","http://schemas.android.com/apk/res-auto");
				fprintf(h," xmlns:tools=\"%s\"","http://schemas.android.com/tools");
				fprintf(h," android:id=\"@+id/%s%s\"",fptr->identifier,iptr->Contents.name);
				if (( layout == _ABSOLUTE_LAYOUT )
				|| ( layout == _SCROLL_LAYOUT ))
				{
					fprintf(h," android:layout_x=\"%udp\"\n",iptr->Contents.x);
					fprintf(h," android:layout_y=\"%udp\"\n",iptr->Contents.y);
					fprintf(h," android:layout_width=\"%udp\"\n",iptr->Contents.w);
					fprintf(h," android:layout_height=\"%udp\"\n",iptr->Contents.h);
				}
				else
				{
					fprintf(h," android:layout_width=\"wrap_content\" android:layout_height=\"wrap_content\"");
				}
				fprintf(h," android:name=\"%s\"","com.google.android.gms.maps.SupportMapFragment");
				fprintf(h," tools:context=\"%s.%s\"/>\n",domain,fptr->identifier); 

			}
			else if (!( strcmp( fnptr, "android:time" )))
			{
				fprintf(h,"<TimePicker android:id=\"@+id/%s%s\"",fptr->identifier,iptr->Contents.name);
				if (( layout == _ABSOLUTE_LAYOUT )
				|| ( layout == _SCROLL_LAYOUT ))
				{
					fprintf(h," android:layout_x=\"%udp\"\n",iptr->Contents.x);
					fprintf(h," android:layout_y=\"%udp\"\n",iptr->Contents.y);
					fprintf(h," android:layout_width=\"%udp\"\n",iptr->Contents.w);
					fprintf(h," android:layout_height=\"%udp\"\n",iptr->Contents.h);
				}
				else
				{
					fprintf(h," android:layout_width=\"wrap_content\" android:layout_height=\"wrap_content\"");
				}
				if ( AndroidOption.visualStyle )
				{
					fprintf(h," style=\"@style/timepicker\"" );
					fprintf(h," android:background=\"@drawable/timepicker\"\n");
				}
				if (method_is_valid( iptr->Contents.events->on_event ) )
					fprintf(h," android:onClick=\"%sEvent\"",iptr->Contents.name);
				fprintf(h," android:shownWeekCount=\"4\"");
				fprintf(h,"/>\n");
			}
			// ----------------------------------------------------	
			// Custome Android Component in Class File of Same Name
			// ----------------------------------------------------	
			else
			{
				// step over android prefix
				fnptr += strlen( "android:" );
				fprintf(h,"<%s.%s android:id=\"@+id/%s%s\"",AndroidOption.master,fnptr,fptr->identifier,iptr->Contents.name);
				if (( layout == _ABSOLUTE_LAYOUT )
				|| ( layout == _SCROLL_LAYOUT ))
				{
					fprintf(h," android:layout_x=\"%udp\"\n",iptr->Contents.x);
					fprintf(h," android:layout_y=\"%udp\"\n",iptr->Contents.y);
					fprintf(h," android:layout_width=\"%udp\"\n",iptr->Contents.w);
					fprintf(h," android:layout_height=\"%udp\"\n",iptr->Contents.h);
				}
				else
				{
					fprintf(h," android:layout_width=\"wrap_content\" android:layout_height=\"wrap_content\"");
				}
				if (method_is_valid( iptr->Contents.events->on_event ) )
					fprintf(h," android:onClick=\"%sEvent\"",iptr->Contents.name);
				fprintf(h,"/>\n");
			}
			break;

		/* ------------------- */
		/* decorative elements */
		/* ------------------- */
		case	_PROGRESS_FRAME	:
			fprintf(h,"<ProgressBar android:id=\"@+id/%s%s\"",fptr->identifier,iptr->Contents.name);
			if (( layout == _ABSOLUTE_LAYOUT )
			|| ( layout == _SCROLL_LAYOUT ))
			{
				fprintf(h," android:layout_x=\"%udp\"\n",iptr->Contents.x);
				fprintf(h," android:layout_y=\"%udp\"\n",iptr->Contents.y);
				fprintf(h," android:layout_width=\"%udp\"\n",iptr->Contents.w);
				fprintf(h," android:layout_height=\"wrap_content\"\n");
			}
			else
			{
				fprintf(h," android:layout_width=\"wrap_content\" android:layout_height=\"wrap_content\"");
			}
			if ( iptr->Contents.events->xo_show & _EVENT_IS_COND )
			{ fprintf(h," android:visibility=\"invisible\""); }
			fprintf(h," style=\"@android:style/Widget.ProgressBar.Horizontal\"/>\n");
			break;
		case	_TEXT_FRAME	:
			fprintf(h,"<TextView android:id=\"@+id/%s%s\"",fptr->identifier,iptr->Contents.name);
			if (( layout == _ABSOLUTE_LAYOUT )
			|| ( layout == _SCROLL_LAYOUT ))
			{
				fprintf(h," android:layout_x=\"%udp\"\n",iptr->Contents.x);
				fprintf(h," android:layout_y=\"%udp\"\n",iptr->Contents.y);
				fprintf(h," android:layout_width=\"%udp\"\n",iptr->Contents.w);
				fprintf(h," android:layout_height=\"wrap_content\"\n");
			}
			else
			{
				fprintf(h," android:layout_width=\"wrap_content\" android:layout_height=\"wrap_content\"");
			}
			if ( iptr->Contents.events->xo_show & _EVENT_IS_COND )
			{ fprintf(h," android:visibility=\"invisible\""); }
			else if ( iptr->Contents.events->xo_hide & _EVENT_IS_POP )
			{ fprintf(h," android:visibility=\"invisible\""); }

			android_layout_textview( h, iptr, iptr->Contents.align );
			fprintf(h," android:text=\"@string/%s%sLabel\"/>\n",fptr->identifier,iptr->Contents.name);
			break;

        	case    _IMAGE_FRAME    :
			fprintf(h,"<ImageView android:id=\"@+id/%s%s\"",fptr->identifier,iptr->Contents.name);
			if (( layout == _ABSOLUTE_LAYOUT )
			|| ( layout == _SCROLL_LAYOUT ))
			{
				fprintf(h," android:layout_x=\"%udp\"\n",iptr->Contents.x);
				fprintf(h," android:layout_y=\"%udp\"\n",iptr->Contents.y);
				fprintf(h," android:layout_width=\"%udp\"\n",iptr->Contents.w);
				fprintf(h," android:layout_height=\"%udp\"\n",iptr->Contents.h);
			}
			else
			{ fprintf(h," android:layout_width=\"wrap_content\" android:layout_height=\"wrap_content\""); }
			switch (iptr->Contents.align) 
			{
			case	_I_MAKEFIT	:
				scale = "fitXY";break;
			case	_A_NONE	:
				scale = "center";break;
			case	_A_CENTER	:
				scale = "fitCenter";break;
			case	_A_LEFT		:
				scale = "fitStart";break;
			case	_A_RIGHT	:
				scale = "fitEnd";break;
			case	_I_TILE  	:
				scale = "matrix";break;
			case	_I_COVER  	:
				scale = "centerCrop";break;
			case	_I_BESTFIT	:
				scale = "centerInside";break;
			default	:	scale = (char *) 0;
			}
			if ( scale )
			{ fprintf(h," android:scaleType=\"%s\"",scale); }
			if ( iptr->Contents.events->xo_show & _EVENT_IS_COND )
			{ fprintf(h," android:visibility=\"invisible\""); }
			android_lowercase( buffer, abal_payload( iptr ), "\0");
			android_cutpoint( buffer );
			fprintf(h," android:src=\"@drawable/%s\"/>\n",buffer);
			break;
		}

	}
	switch ( layout )
	{
	case	_LINEAR_LAYOUT	:
		fprintf(h,"</LinearLayout>\n");
		break;
	case	_RELATIVE_LAYOUT:
		fprintf(h,"</RelativeLayout>\n");
		break;
	case	_SCROLL_LAYOUT:
		fprintf(h,"</AbsoluteLayout>\n");
		fprintf(h,"</ScrollView>\n");
		break;
	case	_ABSOLUTE_LAYOUT:
		fprintf(h,"</AbsoluteLayout>\n");
		fprintf(h,"</RelativeLayout>\n");
		break;
	}
	fclose(h);
	return(1);
}

/*	--------------------------------------------	*/
/*	g e n e r  a t e _ t a b l e _ l a y o u t s 	*/
/*	--------------------------------------------	*/
private	int	generate_table_layouts( FILE * hh, struct form_control * fptr, char * domain, char * rootpath )
{
	struct	form_item * iptr;
	char 	filename[2048];
	FILE*	h;
	int	fh,fw;
        char    value[32];
        char *  buffer=(char *) 0;
        int     linelength, nblines,i,fields;
        int     fieldwidth[_MAX_FORM_FIELDS];

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		if (( iptr->Contents.style & _FRAME_TYPE ) != _FORM_FRAME )
			continue;
		else
		{
        		calculate_edit_size( &iptr->Contents );
        		calculate_form_lines( iptr, &linelength, &nblines );

        		if (!( fields = calculate_form_fields(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength) ))
        		        continue;

			android_lowercase(filename,fptr->identifier,iptr->Contents.name);
			
			if (!( h = create_android_file( hh, domain ,fptr, rootpath, filename,"xml" ) ))
				continue;
			else
			{
			        fw = guifontsize(iptr->Contents.font);
        			fh = (fw >> 8); fw &= 0x00FF;

				fprintf(h,"<LinearLayout\n");
				fprintf(h,"xmlns:android=\"http://schemas.android.com/apk/res/android\"\n");
				fprintf(h,"android:layout_width=\"match_parent\"\n");
	    			fprintf(h,"android:layout_height=\"match_parent\"\n");
	    			fprintf(h,"android:orientation=\"horizontal\"\n");
				fprintf(h,">\n");
				for ( i=1; i <= fields; i++ )
				{
					fprintf(h,"<TextView android:id=\"@+id/%s%sColumn%u\"\n",
						fptr->identifier,iptr->Contents.name,i);
					fprintf(h,"\tandroid:textSize=\"%udp\"\n",fh+2);
					fprintf(h,"\tandroid:gravity=\"left\"\n");
					if (!( fieldwidth[i-1] ))
						fprintf(h,"\tandroid:layout_width=\"wrap_content\"\n");
					else	fprintf(h,"\tandroid:layout_width=\"%udp\"\n",fieldwidth[i-1]*fw);
					fprintf(h,"\tandroid:layout_height=\"wrap_content\"/>\n");
				}
				fprintf(h,"</LinearLayout>\n");
				fclose(h);
				continue;
			}
		}
	}
	return(1);
}

/*	-------------------------------------------	*/
/*	r e s o l v e _ a n d r o i d _ n a t u r e	*/
/*	-------------------------------------------	*/
private	int	resolve_android_nature( struct form_control * fptr )
{
	if (!( fptr->isprogram ))
	{
		if (!( fptr->isoverlay ))
			return(0);	/* just a base class description */
		else	return(1);	/* module single instance	 */
	}
        else if (!( fptr->isoverlay ))
		return(2);		/* just an initial application	*/
	else	return(3);		/* overay multiple instance	*/
}

/*	------------------------------------------------	*/
/*	g e n e r a t e_ a n d r o i d _ a c t i v i t y	*/
/*	------------------------------------------------	*/
private	void	generate_android_activity( FILE * h, struct form_control * fptr, int go )
{
	struct	forms_method * mptr;
        fprintf(h,"<activity");
        fprintf(h," android:name=\".%s\"",fptr->identifier);
	switch ( resolve_android_nature( fptr ) )
	{
	case	0	:	/* CLASS   */
		break;
	case	1	:	/* MODULE  */
		fprintf(h," android:launchMode=\"singleInstance\" ");
		break;
	case	2	:	/* PROGRAM */
		fprintf(h," android:launchMode=\"singleTop\" ");
		break;
	case	3	:	/* OVERLAY */
		fprintf(h," android:launchMode=\"standard\" ");
		break;
	}
	/* ---------------------------------- */
	/* detect and handle orientation lock */
	/* ---------------------------------- */
	if (( mptr = detect_forms_method(fptr,_JAVA_ORIENTATION)) != (struct forms_method *) 0)
		fprintf(h," android:screenOrientation=\"%s\" ",(mptr->name + strlen(_JAVA_ORIENTATION)));

	/* ------------------------------- */
	/* detect declared parent activity */
	/* ------------------------------- */
	if (!( go ))
		if ((mptr = detect_forms_method(fptr, _JAVA_PARENT)) !=(struct forms_method *) 0)
			fprintf(h," android:parentActivityName=\"%s\"",(mptr->name+strlen(_JAVA_PARENT)));

        fprintf(h," android:label=\"@string/%sAppName\">\n",fptr->identifier);
	if ( go )
	{
        	fprintf(h,"<intent-filter>\n");
        	fprintf(h,"<action android:name=\"android.intent.action.MAIN\"/>\n");
        	fprintf(h,"<category android:name=\"android.intent.category.LAUNCHER\"/>\n");
       		fprintf(h,"</intent-filter>\n");
	}
	if ( AndroidOption.handle_nfd )
	{
		if ( fptr->mimoflags & _MIMO_KEYBOARD )
		{
			/* ------------------------------------------------ */
			/* a near field device must expose an intent filter */
			/* ------------------------------------------------ */
			if ((mptr = detect_forms_method( fptr, _NDEF_EVENT )) != (struct forms_method *) 0)
			{
				fprintf(h,"<intent-filter>\n");
	    			fprintf(h,"<action android:name=\"android.nfc.action.NDEF_DISCOVERED\"/>\n");
	    			fprintf(h,"<category android:name=\"android.intent.category.DEFAULT\"/>\n");
	    			fprintf(h,"<data android:mimeType=\"text/plain\"/>\n");
				fprintf(h,"</intent-filter>\n");
			}
			/* ------------------------------------------------ */
			/* a near field device must expose an intent filter */
			/* ------------------------------------------------ */
			if ((mptr = detect_forms_method( fptr, _TECH_EVENT )) != (struct forms_method *) 0)
			{
				fprintf(h,"<intent-filter>\n");
	    			fprintf(h,"<action android:name=\"android.nfc.action.TECH_DISCOVERED\"/>\n");
	    			fprintf(h,"<category android:name=\"android.intent.category.DEFAULT\"/>\n");
				fprintf(h,"</intent-filter>\n");
	    			fprintf(h,"<meta-data android:name=\"android.nfc.action.TECH_DISCOVERED\" android:resource=\"@xml/nfc\"/>\n");
			}
			/* ------------------------------------------------ */
			/* a near field device must expose an intent filter */
			/* ------------------------------------------------ */
			if ((mptr = detect_forms_method( fptr, _TAG_EVENT )) != (struct forms_method *) 0)
			{
				fprintf(h,"<intent-filter>\n");
	    			fprintf(h,"<action android:name=\"android.nfc.action.TAG_DISCOVERED\"/>\n");
	    			fprintf(h,"<category android:name=\"android.intent.category.DEFAULT\"/>\n");
				fprintf(h,"</intent-filter>\n");
			}
		}
	}
	/* ------------------------------------ */
	/* the one that wants to find something */
	/* ------------------------------------ */
	if (( mptr = detect_forms_method( fptr, _JAVA_SEARCH )) != (struct forms_method *) 0)
	{
	    	fprintf(h,"<meta-data android:name=\"android.app.default_searchable\" android:value=\".%s\"/>\n",
			/* the portion behind the SEARCH PREFIX should be the target activity name */
			(mptr->name + strlen( _JAVA_SEARCH ) + 1));
	}
	/* ----------------------------------------- */
	/* the one that does the looking and showing */
	/* ----------------------------------------- */
	if (( mptr = detect_forms_method( fptr, _JAVA_FINDER )) != (struct forms_method *) 0)
	{
		fprintf(h,"<intent-filter>\n");
		fprintf(h,"<action android:name=\"android.intent.action.SEARCH\" />\n");
		fprintf(h,"</intent-filter>\n");
	    	fprintf(h,"<meta-data android:name=\"android.app.searchable\" android:resource=\"@xml/searchable\"/>\n");
	}
        fprintf(h,"</activity>\n");
	return;
}

/*	------------------------------------------------	*/
/*	g e n e r a t e_ a n d r o i d _ m a n i f e s t	*/
/*	------------------------------------------------	*/
private	int	generate_android_manifest( FILE * h, char * domain, struct form_control * fptr )
{
	struct	forms_mthod * mptr;
	release_android_activities();
	android_xml_header(h);
	fprintf(h,"<manifest xmlns:android=\"http://schemas.android.com/apk/res/android\" ");
	fprintf(h," android:versionName=\"%s\" android:versionCode=\"%u\" ",AndroidOption.versionName,AndroidOption.versionCode);
	fprintf(h," package=\"%s.%s\">\n",domain,fptr->identifier);
	fprintf(h,"<uses-sdk android:minSdkVersion=\"%u\"/>\n",AndroidOption.version);
	fprintf(h,"<uses-permission android:name=\"android.permission.WRITE_EXTERNAL_STORAGE\" />\n");

	if ((mptr = detect_forms_method( fptr, _JAVA_WAKELOCK )) != (struct forms_method * ) 0)
	{ fprintf(h,"<uses-permission android:name=\"android.permission.WAKE_LOCK\" />\n"); }

	if ((mptr = detect_forms_method( fptr, _JAVA_RECORD )) != (struct forms_method * ) 0)
	{ fprintf(h,"<uses-permission android:name=\"android.permission.RECORD_AUDIO\" />\n"); }

	if ((mptr = detect_forms_method( fptr, _JAVA_GPS)) != (struct forms_method *) 0)
	{ fprintf(h,"<uses-permission android:name=\"android.permission.ACCESS_FINE_LOCATION\" />\n"); }

	if ( AndroidOption.handle_nfd )
	{
		fprintf(h,"<uses-permission android:name=\"android.permission.NFC\" />\n");
		fprintf(h,"<uses-feature android:name=\"android.hardware.nfc\" android:required=\"true\" />\n");
	}
	if ( AndroidOption.handle_camera )
	{
		fprintf(h,"<uses-permission android:name=\"android.permission.CAMERA\" />\n");
		fprintf(h,"<uses-feature android:name=\"android.hardware.camera\" android:required=\"true\" />\n");
		if ( AndroidOption.handle_gps )
		{
			fprintf(h,"<uses-permission android:name=\"android.permission.ACCESS_FINE_LOCATION\" />\n");
		}
	}
	if ( AndroidOption.handle_network )
	{
		fprintf(h,"<uses-permission android:name=\"android.permission.INTERNET\" />\n");
		fprintf(h,"<uses-permission android:name=\"android.permission.ACCESS_NETWORK_STATE\" />\n");
	}
	fprintf(h,"<application");
        fprintf(h," android:allowBackup=\"true\"");
        fprintf(h," android:icon=\"@mipmap/%s\"",AndroidOption.icon);
        fprintf(h," android:label=\"@string/%sAppName\"",fptr->identifier);
        fprintf(h," android:theme=\"@style/%s\">\n",AndroidOption.style);

	if ( AndroidOption.apiKey )
	{
		fprintf(h,"\t<meta-data android:name=\"com.google.android.geo.API_KEY\" android:value=\"%s\"/>\n",AndroidOption.apiKey);
	}

	generate_forms_activity( h, fptr,1 );
	fprintf(h,"</application>\n");
	fprintf(h,"</manifest>\n");
	fclose(h);
	return(1);
}

/*	---------------------------------------------	*/
/*	u n i q u e _ a n d r o i d _ a c t i v i t y	*/
/*	---------------------------------------------	*/
private	struct	android_activity * ActivityHeap=(struct android_activity *) 0;

private	int	unique_android_activity( char * sptr )
{
	struct	android_activity * aptr;
	for (	aptr = ActivityHeap;
		aptr != (struct android_activity *) 0;
		aptr = aptr->next )
	{
		if (!( aptr->name ))
			continue;
		else if (!( strcmp( aptr->name, sptr ) ))
			return(0);
		else	continue;
	}
	if (!( aptr = allocate ( sizeof( struct android_activity ) ) ))
		return( 0 );
	else if (!( aptr->name = allocate_string( sptr ) ))
		return( 0 );
	else
	{
		printf("unique(%s)\r\n",sptr);
		aptr->next = ActivityHeap;
		ActivityHeap = aptr;
		return( 1 );
	}
}

/*	---------------------------------------------------	*/
/*	r e l e a s e _ a n d r o i d _ a c t i v i t i e s	*/
/*	---------------------------------------------------	*/
private	void	release_android_activities()
{
	printf("release unique\r\n");
	struct	android_activity * aptr;
	while (( aptr = ActivityHeap) !=(struct android_activity *) 0)
	{
		ActivityHeap = aptr->next;
		if ( aptr->name )
			liberate( aptr->name );
		liberate( aptr );
	}
	return;
}

/*	---------------------------------------------		*/
/*	g e n e r a t e _ f o r m s _ a c t i v i t y		*/
/*	---------------------------------------------		*/
private	void	generate_forms_activity( FILE * h, struct form_control * fptr, int mode )
{
	struct	form_item * iptr;
	struct	form_control * ffptr;
	char *	fnptr;

	/* -------------------- */
	/* eliminate duplicates */
	/* -------------------- */
	if (!( unique_android_activity( fptr->identifier ) ))	
		return;

	/* ---------------------------------- */
	/* generate the activity for the form */
	/* ---------------------------------- */
	else	generate_android_activity( h, fptr,mode );

	/* --------------------------------- */
	/* for all visual overlay components */
	/* --------------------------------- */
	for ( 	iptr = fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		switch ((iptr->Contents.style & _FRAME_TYPE))
		{
		case	_BUTTON_FRAME	:
			if ((  iptr->Contents.datatype != _WIDGET_CHAIN	)
			&&  (  iptr->Contents.datatype != _WIDGET_LOADGO)) 
				continue;
			else if (!( method_is_valid( fnptr = iptr->Contents.format ) ))
				continue;
			else if (!( strncmp( fnptr, "android:", strlen("android:")) ))
				continue;
			else if (!( ffptr = locate_form_control( fnptr ) ))
				continue;
			else	generate_forms_activity( h, ffptr, 0 );
			continue;
		case	_DATA_FRAME	:
			if ( is_file_Widget( iptr ) )
                       		continue;
			if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
				continue;
			else if (( iptr->Contents.datatype != _WIDGET_OVERLAY )
			     &&  ( iptr->Contents.datatype != _WIDGET_MODULE  ))
				continue;
			if (!( fnptr = abal_payload(iptr) ))
                        	continue;
			/* filter out android specific components */
			else if (!( strncmp( fnptr, "android:", strlen("android:")) ))
				continue;
			printf("component(%s)\r\n",fnptr);
			if (!( ffptr = locate_form_control( fnptr ) ))
				continue;
			else
			{
				generate_forms_activity( h, ffptr, 0 );
				continue;
			}
		}
	}
	return;
}

/*	-----------------------------------------	*/
/*	 a n d r o i d _ j a v a _ c o m m e n t	*/
/*	-----------------------------------------	*/
private	void	android_java_comment(FILE * h, char * one, char * two )
{
	int	l;
	int	i;
	l = ((strlen((one?one:""))+strlen((two?two:"")))*2);
	fprintf(h,"\n// "); for ( i=0; i < l; i++ ) fprintf(h,"-");
	fprintf(h,"\n// ");
	if ( one ) while ( *one ) fprintf(h," %c",*(one++)); 
	if ( two ) while ( *two ) fprintf(h," %c",*(two++)); 
	fprintf(h,"\n// "); for ( i=0; i < l; i++ ) fprintf(h,"-");
	fprintf(h,"\n");
	return;
}

/*	---------------------------------------		*/
/*	a n d r o i d _ c l a s s _ f o o t e r 	*/
/*	---------------------------------------		*/
private	int	android_class_footer( FILE * h, char * domain,char * package )
{
	fprintf(h,"\n}\n");

	android_java_comment( h, "End of File: ", package );
	return(0);
}

/*	--------------------------------------------	*/
/*	r es e t _ i m p o r t e d _ p a c k a g e s	*/
/*	--------------------------------------------	*/
private	void	reset_imported_packages()
{
	struct	android_import * iptr;
	while ((iptr=importRoot) != (struct android_import *) 0)
	{
		importRoot = iptr->next;
		if ( iptr->name )
			liberate( iptr->name );
		liberate( iptr );
	}
	return;
}

/*	-------------------------------------		*/
/*	a n d r o i d _ j a v a _ i m p o r t		*/
/*	-------------------------------------		*/
private	int	android_java_import( FILE * h, char * package )
{
	struct	android_import * iptr;
	for (	iptr=importRoot;
		iptr != (struct android_import *) 0;
		iptr = iptr->next )
		if (!( strcmp( iptr->name, package ) ))
			return( 0 );
	if (!( iptr = allocate( sizeof( struct android_import ) ) ))
		return( 0 );
	else if (!( iptr->name = allocate_string( package ) ))
		return( 0 );
	else
	{
		iptr->next = importRoot;
		importRoot = iptr;
		fprintf(h,"import %s;\n",package);
		return(1);
	}
}

/*	---------------------------------------		*/
/*	a n d r o i d _ j a v a _ p a c k a g e		*/
/*	---------------------------------------		*/
private	int	android_java_package( FILE * h, char * domain,char * package )
{
	reset_imported_packages();
	android_java_comment( h,"Android Java Class : ",package);

	fprintf(h,"package %s.%s;\n",domain,package);

	return(1);
}

/*	---------------------------------------		*/
/*	a n d r o i d _ c l a s s _ h e a d e r		*/
/*	---------------------------------------		*/
private	int	android_class_header( FILE * h, char * domain,char * package, struct form_control * fptr )
{
	struct	forms_method * mptr;

	/* ------------------ */
	/* define the package */
	/* ------------------ */
	android_java_package( h, domain, package );

	/* ----------------------------- */
	/* declare the imported packages */
	/* ----------------------------- */
        android_java_import(h,"java.io.*");
        android_java_import(h,"java.util.*");
        android_java_import(h,"java.text.*");
        android_java_import(h,"java.net.*");
        android_java_import(h,"java.security.*");
        android_java_import(h,"javax.crypto.Mac");
        android_java_import(h,"javax.crypto.spec.SecretKeySpec");
	if ( AndroidOption.sqlcipher & 1 )
		android_java_import( h, "net.sqlcipher.database.SQLiteDatabase" );
	android_java_import(h,"android.support.v7.app.ActionBarActivity");
        android_java_import(h,"android.content.*");
        android_java_import(h,"android.media.*");
        android_java_import(h,"android.net.*");
        android_java_import(h,"android.os.*");
        android_java_import(h,"android.text.Html");
        android_java_import(h,"android.view.*");
        android_java_import(h,"android.graphics.*");
	android_java_import(h,"android.widget.CalendarView");
	android_java_import(h,"android.widget.CalendarView.OnDateChangeListener");
	android_java_import(h,"android.widget.Toast");
	android_java_import(h,"android.text.InputType");

	if ( AndroidOption.sqlcipher & 2 )
		android_java_import(h,"android.database.CursorWindow");
		
	if ( AndroidOption.handle_nfd )
		android_java_import(h,"android.nfc.*");
	if ( AndroidOption.widgets[ _TEXT_FRAME ] ) 
		android_java_import(h,"android.widget.TextView");
	if ( AndroidOption.widgets[ _IMAGE_FRAME ] )
	{
		android_java_import(h,"android.widget.ImageView");
		android_java_import(h,"android.graphics.*");
	}
	if ( AndroidOption.widgets[ _EDIT_FRAME ] )
		android_java_import(h,"android.widget.EditText");
	if ( AndroidOption.widgets[ _FORM_FRAME ] )
	{
		android_java_import(h,"android.widget.ListView");
		android_java_import(h,"android.widget.AdapterView");
		android_java_import(h,"android.widget.ArrayAdapter");
		android_java_import(h,"android.widget.SimpleCursorAdapter");
		android_java_import(h,"android.database.sqlite.SQLiteCursor");
		if ( AndroidOption.sqlcipher & 1 )
			android_java_import(h,"net.sqlcipher.CrossProcessCursorWrapper");
		else	android_java_import(h,"android.database.CrossProcessCursorWrapper");
	}
	if ( AndroidOption.widgets[ _RADIO_FRAME ] )
		android_java_import(h,"android.widget.RadioButton");
	if ( AndroidOption.widgets[ _CHECK_FRAME ] )
		android_java_import(h,"android.widget.CheckBox");
	if ( AndroidOption.widgets[ _SWITCH_FRAME ] )
		android_java_import(h,"android.widget.ToggleButton");
	if ( AndroidOption.widgets[ _SELECT_FRAME ] )
	{
		android_java_import(h,"android.widget.Spinner");
		android_java_import(h,"android.widget.AdapterView");
		if (!( AndroidOption.widgets[ _FORM_FRAME ] ))
			android_java_import(h,"android.widget.ArrayAdapter");
	}
	if ( AndroidOption.widgets[ _BUTTON_FRAME ] )
	{
		android_java_import(h,"android.widget.Button");
		android_java_import(h,"android.widget.ImageButton");
		if (!( AndroidOption.widgets[ _IMAGE_FRAME ] ))
		{
			android_java_import(h,"android.widget.ImageView");
			android_java_import(h,"android.graphics.*");
		}
		if (!( AndroidOption.widgets[ _TEXT_FRAME ] ))
			android_java_import(h,"android.widget.TextView");
	}
	if ( AndroidOption.widgets[ _PROGRESS_FRAME ] )
		android_java_import(h,"android.widget.ProgressBar");

	/* ----------------------------------------- */
	/* classes required for search bar operation */
	/* ----------------------------------------- */
	if ((( mptr = detect_forms_method( fptr, _JAVA_SEARCH )) != (struct forms_method *) 0)
	||  (( mptr = detect_forms_method( fptr, _JAVA_FINDER )) != (struct forms_method *) 0))
	{
		android_java_import(h,"android.app.SearchManager");
		android_java_import(h,"android.widget.SearchView");
	}

	/* ----------------------------------------- */
	/* classes required for map manageroperation */
	/* ----------------------------------------- */
	if ((mptr = detect_forms_method( fptr, _JAVA_MAP )) != (struct forms_method *) 0)
	{
                android_java_import(h,"android.support.v4.app.FragmentActivity");
                android_java_import(h,"android.os.Bundle");
                android_java_import(h,"com.google.android.gms.maps.CameraUpdateFactory");
                android_java_import(h,"com.google.android.gms.maps.GoogleMap");
                android_java_import(h,"com.google.android.gms.maps.OnMapReadyCallback");
                android_java_import(h,"com.google.android.gms.maps.SupportMapFragment");
                android_java_import(h,"com.google.android.gms.maps.model.LatLng");
                android_java_import(h,"com.google.android.gms.maps.model.Marker");
                android_java_import(h,"com.google.android.gms.maps.model.MarkerOptions");
	}
	if ((mptr = detect_forms_method( fptr, _JAVA_GPS )) != (struct forms_method *) 0)
	{
		android_java_import(h,"android.location.Location");
		android_java_import(h,"android.location.LocationManager");
		android_java_import(h,"android.location.LocationListener");
	}
	
	return(0);
}

/*	---------------------------------------		*/
/*	a n d r o i d _ c l a s s _ i m p o r t		*/
/*	---------------------------------------		*/
private	int	android_class_import( FILE * h, char * domain, struct form_control * fptr )
{
	struct	form_item * iptr;
	struct	data_control * dptr;
	int	fields=0;
	char	classname[1024];
	char	package[2048];
	for ( 	iptr = fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		switch ((iptr->Contents.style & _FRAME_TYPE))
		{
		case	_DATA_FRAME	:
			if ( AndroidOption.handle_files )
			{
				if (!( is_file_Widget( iptr ) ))
                       			continue;
				else if (!( dptr = android_database_description( iptr, classname, &fields ) ))
					continue;
				else	continue;
			}
		}
	}
	return(0);
}

/*	---------------------------------------		*/
/*	a n d r o i d _ l i s t _ e l e m e n t		*/
/*	---------------------------------------		*/
private	char * 	android_list_element( char * sptr, char * rptr )
{
	int	i=0;
	int	c;
	/* detect empty string */
	if (!( sptr )) return( sptr );
	/* remove preceeding white space */
	while (( *sptr == ' ' ) || ( *sptr == '\r' ) || ( *sptr == '\t' ) || ( *sptr == '\n' )) sptr++;
	/* scan source to find terminator */
	while ((c =*(sptr++)) != 0)
	{
		if (c == ',') 
			break;
		else if (c == ';') 
			break;
		else if ( *sptr == ' ' ) 
			break;
		else if ( *sptr == '\r' ) 
			break;
		else if ( *sptr == '\t' ) 
			break;
		else if ( *sptr == '\n' )
			break;
		else
		{
			*(rptr+i) = c;
			i++;
		}
	}
	/* terminate result string */
	*(rptr+i) = 0;
	/* remove trailing white space */
	while (( *sptr == ' ' ) || ( *sptr == '\r' ) || ( *sptr == '\t' ) || ( *sptr == '\n' )) sptr++;
	/* handle exit conditions */	
	if (!( i )) 
		return( (char *) 0 );
	else	return( sptr );
}

/*	-------------------------------------		*/
/*	d e t e c t _ f o r m s _ m e t h o d 		*/
/*	-------------------------------------		*/
public  struct forms_method * detect_forms_method( struct form_control * fptr, char * nptr )
{
	struct	forms_method * mptr;
	for (	mptr=fptr->rootmethod;
		mptr != (struct forms_method *) 0;
		mptr = mptr->next )
	{
		if (!( mptr->name ))
			continue;
		else if (!( strncasecmp( mptr->name, nptr, strlen(nptr) ) ))
			break;
		else	continue;
	}
	return( mptr );
}

/*	-------------------------------------	*/
/*	a n d r o i d _ t h r e a d _ n a m e	*/
/*	-------------------------------------	*/
private	char *	android_thread_name( char * sptr )
{
	if (!( strncasecmp( sptr, _JAVA_ASYNC, strlen( _JAVA_ASYNC ) ) ))
		return((sptr + strlen( _JAVA_ASYNC ) ));
	else	return( sptr );
}

/*	-----------------------------------------	*/
/*	a n d r o i d _ t h r e a d _ m e t h o d	*/
/*	-----------------------------------------	*/
private struct forms_method *	android_thread_method( struct form_control * fptr, struct forms_method * xptr, char * sptr )
{
	char 	signature[1024];
	char *	name;
	struct	forms_method * mptr;
	if (!( name = android_thread_name( xptr->name )))
		return((struct forms_method *) 0);
	else	sprintf(signature,"%s%s",sptr, name);
	
	for ( mptr = fptr->rootmethod;
		mptr != (struct forms_method * ) 0;
		mptr = mptr->next )
		if (!( strcasecmp( signature, mptr->name ) ))
			break;
	return( mptr );
}

/*	-----------------------------------------	*/
/*	a n d r o i d _ m e t h o d _ r e t u r n	*/
/*	-----------------------------------------	*/
private	void	android_method_return( FILE * h, struct forms_method * mptr )
{
	switch ( (mptr->type & _METHOD_TYPE) ) 
	{
	case    _METHOD_VOID    : fprintf(h," void" );  break;
	case    _METHOD_BYTE    : fprintf(h," char" );  break;
	case    _METHOD_LONG 	: fprintf(h," long" );  break;
	case    _METHOD_WORD    : fprintf(h," int" );   break;
	case    _METHOD_NUMERIC : fprintf(h," Float" ); break;
	case    _METHOD_STRING  : fprintf(h," String"); break;
	case    _METHOD_CLASS   : fprintf(h," %s",mptr->klass); break;
	}
	return;	                
}

/*	---------------------------------------		*/
/*	a n d r o i d _  f o r m _ m e t h o d s	*/
/*	---------------------------------------		*/
private	int	android_forms_methods( FILE * h, char * domain, struct form_control * fptr )
{
	struct	forms_method * mptr;
	struct	forms_method * mmptr;
	char	parameter[1024];
	int	i;
	for (	mptr=fptr->rootmethod;
		mptr != (struct forms_method *) 0;
		mptr = mptr->next )
	{
		if (!( mptr->name ))
			continue;
		else if (!( strcasecmp( mptr->name, _JAVA_IMPORT ) ))
			continue;
		else if (!( strcasecmp( mptr->name, _JAVA_CIPHER ) ))
			continue;
		else if (!( strcasecmp( mptr->name, _JAVA_SQLITE ) ))
			continue;
		else if (!( strcasecmp( mptr->name, _SING_CIPHER ) ))
			continue;
		else if (!( strncasecmp( mptr->name, _JAVA_SEARCH, strlen( _JAVA_SEARCH ) ) ))
			continue;
		else if (!( strncasecmp( mptr->name, _JAVA_FINDER, strlen( _JAVA_FINDER ) ) ))
			continue;
		else if (!( strncasecmp( mptr->name, _JAVA_PARENT, strlen( _JAVA_PARENT ) ) ))
			continue;
		else if (!( strncasecmp( mptr->name, _JAVA_MAP   , strlen( _JAVA_MAP    ) ) ))
			continue;
		else if (!( strncasecmp( mptr->name, _JAVA_ORIENTATION, strlen( _JAVA_ORIENTATION ) ) ))
			continue;
		else if (!( strncasecmp( mptr->name, _JAVA_DOMAIN, strlen( _JAVA_DOMAIN ) ) ))
			continue;
		else if (!( strncasecmp( mptr->name, _JAVA_VERSION,strlen( _JAVA_VERSION) ) ))
			continue;
		else if (!( strncasecmp( mptr->name, _JAVA_WAKELOCK ,strlen( _JAVA_WAKELOCK) ) ))
			continue;
		else if (!( strncasecmp( mptr->name, _JAVA_RECORD   ,strlen( _JAVA_RECORD) ) ))
			continue;
		else if (!( strncasecmp( mptr->name, _JAVA_MEMBER, strlen( _JAVA_MEMBER ) ) ))
			continue;
		else if (!( strncasecmp( mptr->name, _JAVA_BEFORE, strlen( _JAVA_BEFORE ) ) ))
			continue;
		else if (!( strncasecmp( mptr->name, _JAVA_AFTER , strlen( _JAVA_AFTER  ) ) ))
			continue;
		else if (!( strncasecmp( mptr->name, _JAVA_DURING, strlen( _JAVA_DURING ) ) ))
			continue;
		else if (!( strncasecmp( mptr->name, _JAVA_SCROLL, strlen( _JAVA_SCROLL ) ) ))
			continue;
		else if (!( strncasecmp( mptr->name, _JAVA_FIXED, strlen( _JAVA_FIXED ) ) ))
			continue;
		else if (!( strncasecmp( mptr->name, _JAVA_VISUAL, strlen( _JAVA_VISUAL ) ) ))
			continue;
		else if (!( strncasecmp( mptr->name, _JAVA_LINEAR, strlen( _JAVA_LINEAR) ) ))
			continue;
		else if (!( strncasecmp( mptr->name, _JAVA_RELATIVE, strlen( _JAVA_RELATIVE) ) ))
			continue;
		else if (!( strncasecmp( mptr->name, _JAVA_API_KEY, strlen( _JAVA_API_KEY ) ) ))
			continue;
		else if (!( strncasecmp( mptr->name, _JAVA_ASYNC, strlen( _JAVA_ASYNC) ) )) 
		{
			/* ------------------------------------ */
			/* handle background thread main method */
			/* ------------------------------------ */
			printf("thread(%s)\r\n",mptr->name);
			android_java_comment( h, fptr->identifier,mptr->name);
			/* ---------------------------------- */
			/* background thread class definition */
			/* ---------------------------------- */
			fprintf(h,"private class %s extends AsyncTask<%s> {\n",
				android_thread_name( mptr->name ), 
				(method_is_valid(mptr->signature)?mptr->signature:"void, void, void"));			
			/* ----------------------------- */
			/* background thread members def */
			/* ----------------------------- */
			if ((mmptr = android_thread_method( fptr, mptr, _JAVA_MEMBER)) != (struct forms_method *) 0)
			{
				android_method_body( h, mmptr->text );
			}
			/* ------------------------------ */
			/* background thread construction */
			/* ------------------------------ */
			if ((mmptr = android_thread_method( fptr, mptr, _JAVA_BEFORE )) != (struct forms_method *) 0)
			{
				fprintf(h,"\tprotected");
				android_method_return(h,mmptr);
				fprintf(h," onPreExecute()\n\t{\n");
				android_method_body( h, mmptr->text );
				fprintf(h,"\t}\n");
			}
			/* ----------------------------- */
			/* background thread main method */
			/* ----------------------------- */
			strcpy(parameter,mptr->signature);
			for ( i=0; parameter[i] != 0; i++ )
			{
				if ( parameter[i]== ',' )
				{
					parameter[i]= 0;
					break;
				}
			}	
			fprintf(h,"\tprotected");
			android_method_return(h,mptr);
			fprintf(h," doInBackground(%s... params)\n\t{\n",parameter);
			android_method_body( h, mptr->text );
			fprintf(h,"\t}\n");
			/* --------------------------- */
			/* background thread reporting */
			/* --------------------------- */
			if ((mmptr = android_thread_method( fptr, mptr, _JAVA_DURING )) != (struct forms_method *) 0)
			{
				fprintf(h,"\tprotected");
				android_method_return(h,mmptr);
				fprintf(h," onProgressUpdate(%s)\n\t{\n",(mmptr->signature?mmptr->signature:"\0"));
				android_method_body( h, mmptr->text );
				fprintf(h,"\t}\n");
			}
			/* ---------------------------- */
			/* background thread completion */
			/* ---------------------------- */
			if ((mmptr = android_thread_method( fptr, mptr, _JAVA_AFTER )) != (struct forms_method *) 0)
			{
				fprintf(h,"\tprotected");
				android_method_return(h,mmptr);
				fprintf(h," onPostExecute(%s)\n\t{\n",(mmptr->signature?mmptr->signature:"\0"));
				android_method_body( h, mmptr->text );
				fprintf(h,"\t}\n");
			}
			fprintf(h,"}\n");
		}
		else
		{
			printf("method(%s)\r\n",mptr->name);
			android_java_comment( h, fptr->identifier,mptr->name);
			if ( mptr->type & _METHOD_OVERLOAD )
			{
				if ( mptr->type & _METHOD_PUBLIC )
					fprintf(h,"@Override\npublic");
				else	fprintf(h,"@Override\nprotected");
			}
			else if ( mptr->type & _METHOD_PUBLIC )
				fprintf(h,"public");
			else	fprintf(h,"private");

			if ( mptr->type & _METHOD_EXTERN )
				fprintf(h," static");

			android_method_return( h, mptr );

			fprintf(h," %s(%s)\n{\n",mptr->name,( method_is_valid(mptr->signature)? mptr->signature : "\0"));
			android_method_body( h, mptr->text );
			fprintf(h,"}\n");
		}
	}
}

/*	-------------------------------------------------	*/
/*	a n d r o i d _ b a s e f o r m s _ m e t h o d s	*/
/*	-------------------------------------------------	*/
private	int	android_baseforms_methods( FILE * h, char * domain,char * extends )
{
	struct	form_control * fptr;
	if (!( AndroidOption.inherit ))
		return(1);
	if (!( method_is_valid( extends ) ))
		return(1);
	else if (!( fptr = locate_form_control( extends ) ))
		return(1);
	else 	return(	android_forms_methods( h, domain, fptr ) );
}

/*	---------------------------------------		*/
/*	a n d r o i d _  f o r m _ i m p o r t		*/
/*	---------------------------------------		*/
private	int	android_form_import( FILE * h, char * domain, struct form_control * fptr )
{
	struct	forms_method * mptr;
	char *	rptr;
	char *	sptr;
	char *	tptr;
	char 	token[4096];
	for (	mptr=fptr->rootmethod;
		mptr != (struct forms_method *) 0;
		mptr = mptr->next )
	{
		if (!( mptr->name ))
			continue;
		else if (!( strcasecmp( mptr->name, _JAVA_IMPORT ) ))
		{
			if (!( sptr = mptr->text ))
				continue;
			else if (!( method_is_valid( sptr) ))
				continue;
			else if (!( sptr = allocate_string( sptr ) ))
				continue;
			else
			{
				rptr = sptr;
				while ((sptr = android_list_element(sptr, token )) != (char *) 0 )
				{
					printf("import(%s)\r\n",token);
					android_java_import( h, token );
				}
				sptr = liberate( sptr );
				continue;
			}
		}
		else	continue;
	}
	return(0);
}

#include "androfile.c"

/*	-----------------------------------------------	*/
/*	a n d r o i d _ c l a s s _ d e f i n i t i o n	*/
/*	-----------------------------------------------	*/
private	int	android_class_definition( FILE * h, char * domain, char * classname, char * extends, char * interface )
{
	/* -------------------------- */	
	/* start the class definition */
	/* -------------------------- */	
	if (!( method_is_valid( interface ) ))
		fprintf(h,"public class %s extends %s \n{\n",
			classname,(extends?extends:"ActionBarActivity"));
	else	fprintf(h,"public class %s extends %s implements %s \n{\n",
			classname,(extends?extends:"ActionBarActivity"),interface);
	return(0);
}
	
/*	---------------------------------------------		*/
/*	a n d r o i d _ d e r i v e d _ m e m b e r s 		*/
/*	---------------------------------------------		*/
private	int	android_derived_members( FILE * h, char * domain,struct form_control * fptr )
{
	int	i;
	struct	form_item * iptr;
	struct	data_control * dptr;
	int	fields=0;
	char *	fnptr;
	char	classname[1024];
	for ( 	iptr = fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		switch ((iptr->Contents.style & _FRAME_TYPE))
		{
		case	_DATA_FRAME	:
			if ( is_file_Widget( iptr ) )
			{
				if (!( dptr = android_database_description( iptr, classname, &fields ) ))
					continue;
				else
				{
					fprintf(h,"public %s %s;\n",classname,iptr->Contents.name);
					continue;
				}
			}
			else if (( iptr->Contents.align & 0x000F) == _OBJECT_FRAME )
			{
				fprintf(h,"public %s %s=null;\n",iptr->Contents.format,iptr->Contents.name);
				continue;
			}
			else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
				continue;
			else if (( iptr->Contents.datatype != _WIDGET_OVERLAY )
			     &&  ( iptr->Contents.datatype != _WIDGET_MODULE  ))
				continue;
			else if (!( fnptr = abal_payload(iptr) ))
                       		continue;
			else if ( strncmp( fnptr, "android:", strlen("android:") ) != 0 )
				continue;
			else if (!( strcmp( fnptr, "android:calendar" ) ))
			{
				fprintf(h,"public CalendarView %s;\n",iptr->Contents.name);
			}
			else if (!( strcmp( fnptr, "android:time" ) ))
			{
				fprintf(h,"public TimePicker %s;\n",iptr->Contents.name);
			}
			else if (!( strcmp( fnptr, "android:date" ) ))
			{
				fprintf(h,"public DatePicker %s;\n",iptr->Contents.name);
			}
			else if (!( strcmp( fnptr, "android:MapFragment" ) ))
			{
				fprintf(h,"public SupportMapFragment %s;\n",iptr->Contents.name);
			}
			// android custom view
			else 
			{
				fprintf(h,"public %s %s;\n",(fnptr+strlen("android:")),iptr->Contents.name);
			}
			continue;
		case	_TEXT_FRAME	:
			fprintf(h,"public TextView %s;\n",iptr->Contents.name);
			break;
		case	_IMAGE_FRAME	:
			fprintf(h,"public ImageView %s;\n",iptr->Contents.name);
			break;
		case	_BUTTON_FRAME	:
			fprintf(h,"public String %sBuffer;\n",iptr->Contents.name);
			switch ( ( iptr->Contents.align & 3) )
			{
			case	0	:
				fprintf(h,"public Button %s;\n",iptr->Contents.name);
				break;
			case	1	:
				fprintf(h,"public Button %s;\n",iptr->Contents.name);
				break;
			case	2	:
				fprintf(h,"public TextView %s;\n",iptr->Contents.name);
				break;
			case	3	:
				fprintf(h,"public ImageView %s;\n",iptr->Contents.name);
				break;
			}
			break;
		case	_EDIT_FRAME	:
			fprintf(h,"public EditText %s;\n",iptr->Contents.name);
			break;
		case	_FORM_FRAME	:
			fprintf(h,"public String[] %sSource;\n",iptr->Contents.name);
			fprintf(h,"public int[] %sTarget;\n",iptr->Contents.name);
			fprintf(h,"public ListView %s;\n",iptr->Contents.name);
			break;
		case	_SELECT_FRAME	:
			fprintf(h,"public Spinner %s;\n",iptr->Contents.name);
			fprintf(h,"public int %sValue;\n",iptr->Contents.name);
			break;
		case	_SWITCH_FRAME	:
			fprintf(h,"public ToggleButton %s;\n",iptr->Contents.name);
			break;
		case	_CHECK_FRAME	:
			fprintf(h,"public CheckBox %s;\n",iptr->Contents.name);
			break;
		case	_RADIO_FRAME	:
			fprintf(h,"public RadioButton %s;\n",iptr->Contents.name);
			break;
		case	_PROGRESS_FRAME	:
			fprintf(h,"public ProgressBar %s;\n",iptr->Contents.name);
			break;
		}

	}
	return(1);
}

/*	-------------------------------------------------	*/
/*	a n d r o i d _ b a s e c l a s s _ m e m b e r s	*/
/*	-------------------------------------------------	*/
private	int	android_baseclass_members( FILE * h, char * domain, char * extends )
{
	struct	form_control * fptr;
	if (!( AndroidOption.inherit ))
		return(1);
	if (!( method_is_valid( extends ) ))
		return(1);
	else if (!( fptr = locate_form_control( extends ) ))
		return(1);
	else 	return(	android_derived_members( h, domain, fptr ) );
}

/*	-----------------------------------------	*/
/*	a n d r o i d _ c l a s s _ m e m b e r s	*/
/*	-----------------------------------------	*/
private	int	android_class_members( FILE * h, char * domain,struct form_control * fptr )
{
	int	i;
	char *	type;
	struct	forms_data_member * mptr;
	struct	forms_method * mmptr;

	// ----------------------------------
	// generate forms parameter reception
	// ----------------------------------
	fprintf(h,"public Intent argV;\n");
	for ( i=1; i <= fptr->argvcount; i++ )
		fprintf(h,"public String ARGV%u=\"%s.ARGV%u\";\n",i,domain,i);

	if ((mptr = detect_forms_method( fptr, _JAVA_GPS)) != (struct forms_method *) 0)
	{
		fprintf(h,"public Location currentLocation = null;\n");
		fprintf(h,"public LocationManager locationManager = null;\n");
		fprintf(h,"public LocationListener locationListener = null; \n");
	}

	// ----------------------
	// generate forms members 
	// ----------------------
	for ( 	mptr = fptr->rootmember; 
		mptr != (struct forms_data_member *) 0; 
		mptr = mptr->next )
	{
		switch ( mptr->type )
		{
		case	_ABAL_BYTE	: type = "byte";	break; 
		case	_ABAL_WORD	: type = "int";		break;
		case	_ABAL_LONG	: type = "long";	break;
		case	_ABAL_STRING	: type = "String";	break;
		default			: continue;
		}
		if ( mptr->first > 1 )
			fprintf(h,"public %s[] %s = new %s[%u];\n",type,mptr->name,type,mptr->first);
		else if ( mptr->type != _ABAL_STRING )
			fprintf(h,"public %s %s =0;\n",type,mptr->name);
		else	fprintf(h,"public %s %s =\"\";\n",type,mptr->name);
	}

	/* ---------------------------------------------- */
	/* finder methods need to receive search criteria */
	/* ---------------------------------------------- */
	if ((mmptr = detect_forms_method(fptr, _JAVA_FINDER )) != (struct forms_method *) 0)
	{
		fprintf(h,"public String searchCriteria=\"\";\n");
	}

	// -------------------------------------
	// generate inherited base class members
	// -------------------------------------
	if ( method_is_valid( fptr->extends ) != 0 )
		android_baseclass_members( h, domain, fptr->extends );

	// -----------------------------
	// generate forms widget members
	// -----------------------------
	android_derived_members( h, domain, fptr );
	return( 1 );
}

/*	-------------------------------------	*/
/*	a n d r o i d _ m e t h o d _ b o d y 	*/
/*	-------------------------------------	*/
private	void	android_method_body( FILE * h, char * sptr )
{
	int	c;
	int	last=0;
	if ( h )
	{
		if ( sptr)
		{
			/* -------------------------------------------------------- */
			/* output method text while removing unnecessary line feeds */
			/* -------------------------------------------------------- */
			while (( c = *(sptr++)) != 0)
			{
				if ( c == '\r' )
					continue;
				else if ( c != '\n' )
					fprintf(h,"%c",c);
				else if ( last != '\n' )
					fprintf(h,"\n");
				last = c;
			}
			/* --------------------------------------------- */
			/* detect last character and line feed if needed */
			/* --------------------------------------------- */
			if ( last != '\n' )
				fprintf(h,"\n");
		}
	}
	return;
}

/*	-----------------------------------------	*/
/*	a n d r o i d _ m e m b e r _ c r e a t e 	*/
/*	-----------------------------------------	*/
private	int	android_member_create( FILE * h, char * domain,struct form_control * fptr )
{
	struct	form_item * iptr;
	for ( 	iptr = fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		if (method_is_valid( iptr->Contents.events->on_create ) )
		{
			android_java_comment(h,iptr->Contents.name,"Create");
			fprintf(h,"private void %sCreate()\n{\n",iptr->Contents.name);
			android_method_body( h, iptr->Contents.events->on_create );
			switch (( iptr->Contents.style & _FRAME_TYPE ))
			{
			case	_FORM_FRAME	:
				fprintf(h,"\t%s.setAdapter( %sAdapter );\n",iptr->Contents.name,iptr->Contents.name);
				fprintf(h,"\t%s.setOnItemClickListener(new AdapterView.OnItemClickListener() {",iptr->Contents.name);
				fprintf(h,"\t\t@Override\n");
				fprintf(h,"\t\tpublic void onItemClick(AdapterView<?> l, View v, int position, long id ) {\n");
				/* ------------------------------------- */
				/* invoke the table/list vent if defined */
				/* ------------------------------------- */
				if (method_is_valid( iptr->Contents.events->on_event) )
				{
					fprintf(h,"\t\t\t%sEvent(v,position);\n", iptr->Contents.name);
				}
				fprintf(h,"\t\t}});\n");
				break;
			}
			fprintf(h,"}\n");
		}
	}
	return(1);
}

/*	--------------------------------------	*/
/*	a n d r o i d _ m e m b e r _ s h o w 	*/
/*	--------------------------------------	*/
private	int	android_member_show( FILE * h, char * domain,struct form_control * fptr )
{
	struct	form_item * iptr;
	for ( 	iptr = fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		switch ((iptr->Contents.style & _FRAME_TYPE))
		{
		case	_TEXT_FRAME	:
			if ( iptr->Contents.events->xo_hide & _EVENT_IS_POP )
			{
				android_java_comment(h,iptr->Contents.name,"Show");
				fprintf(h,"private void %sShow()\n{\n",iptr->Contents.name);
				if ( method_is_valid( iptr->Contents.events->on_show ) )
					android_method_body( h, iptr->Contents.events->on_show );
				fprintf(h,"\tToast.makeText(getApplicationContext(),%s.getText().toString(),Toast.LENGTH_LONG).show();\n",
					iptr->Contents.name,iptr->Contents.name);
				fprintf(h,"}\n");
				break;
			}

		case	_IMAGE_FRAME	:
		case	_EDIT_FRAME	:
		case	_FORM_FRAME	:
		case	_RADIO_FRAME	:
		case	_CHECK_FRAME	:
		case	_SWITCH_FRAME	:
		case	_SELECT_FRAME	:
		case	_BUTTON_FRAME	:
		case	_PROGRESS_FRAME	:
			if (method_is_valid( iptr->Contents.events->on_show ) )
			{
				android_java_comment(h,iptr->Contents.name,"Show");
				fprintf(h,"private void %sShow()\n{\n",iptr->Contents.name);
				android_method_body( h, iptr->Contents.events->on_show );
				fprintf(h,"}\n");
			}
			continue;
		}
	}
	return(1);
}

/*	--------------------------------------	*/
/*	a n d r o i d _ m e m b e r _ h i d e 	*/
/*	--------------------------------------	*/
private	int	android_member_hide( FILE * h, char * domain,struct form_control * fptr )
{
	struct	form_item * iptr;
	for ( 	iptr = fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		switch ((iptr->Contents.style & _FRAME_TYPE))
		{
		case	_TEXT_FRAME	:
		case	_IMAGE_FRAME	:
		case	_EDIT_FRAME	:
		case	_FORM_FRAME	:
		case	_RADIO_FRAME	:
		case	_CHECK_FRAME	:
		case	_SWITCH_FRAME	:
		case	_SELECT_FRAME	:
		case	_BUTTON_FRAME	:
		case	_PROGRESS_FRAME	:
			if (method_is_valid( iptr->Contents.events->on_hide ) )
			{
				android_java_comment(h,iptr->Contents.name,"Hide");
				fprintf(h,"private void %sHide()\n{\n",iptr->Contents.name);
				android_method_body( h, iptr->Contents.events->on_hide );
				fprintf(h,"}\n");
			}
			continue;
		}
	}
	return(1);
}

/*	-----------------------------------------	*/
/*	a n d r o i d _ m e m b e r _ r e m o v e 	*/
/*	-----------------------------------------	*/
private	int	android_member_remove( FILE * h, char * domain,struct form_control * fptr )
{
	struct	form_item * iptr;
	for ( 	iptr = fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		if (method_is_valid( iptr->Contents.events->on_remove) )
		{
			android_java_comment(h,iptr->Contents.name,"Remove");
			fprintf(h,"private void %sRemove()\n{\n",iptr->Contents.name);
			android_method_body( h, iptr->Contents.events->on_remove );
			fprintf(h,"}\n");
		}
	}
	return(0);
}

/*	--------------------------------------	*/
/*	a n d r o i d _ c a l l _ c r e a t e	*/
/*	--------------------------------------	*/
private	void	android_call_create( FILE * h, struct form_item * iptr )
{
	fprintf(h,"\t%sCreate();\n",iptr->Contents.name);
	return;
}

/*	--------------------------------------	*/
/*	a n d r o i d _ c a l l _ s h o w 	*/
/*	--------------------------------------	*/
private	void	android_call_show( FILE * h, struct form_item * iptr )
{
	fprintf(h,"\t%sShow();\n",iptr->Contents.name);
	return;
}

/*	--------------------------------------	*/
/*	a n d r o i d _ c a l l _ h i d e 	*/
/*	--------------------------------------	*/
private	void	android_call_hide( FILE * h, struct form_item * iptr )
{
	fprintf(h,"\t%sHide();\n",iptr->Contents.name);
	return;
}

/*	--------------------------------------	*/
/*	a n d r o i d _ c a l l _ r e m o v e	*/
/*	--------------------------------------	*/
private	void	android_call_remove( FILE * h, struct form_item * iptr )
{
	fprintf(h,"\t%sRemove();\n",iptr->Contents.name);
	return;
}

/*	-----------------------------------------------------------	*/
/*	a n d r o i d _ i m p l i c i t e _ c o n s t r u c t i o n	*/
/*	-----------------------------------------------------------	*/
private	void	android_implicite_construction( FILE * h, struct form_control * fptr, struct form_item * iptr, char * nature )
{
        int     linelength, nblines,i,fields;
        int     fieldwidth[_MAX_FORM_FIELDS];
	char *	sep="\0";
	/* ------------------------------------------- */
	/* implicite construction connection to widget */
	/* ------------------------------------------- */
	if (!( strcasecmp( nature, "MapFragment" ) ))
	{
		fprintf(h,"\ttry\n\t{\n");
		fprintf(h,"\t%s = (Support%s) getSupportFragmentManager().findFragmentById(R.id.%s%s);\n",iptr->Contents.name,nature,fptr->identifier,iptr->Contents.name);
		fprintf(h,"\t%s.getMapAsync(this);\n",iptr->Contents.name);
		fprintf(h,"\t} catch ( Exception e ) { String S=\"\"; }\n");
	}
	else
	{
		fprintf(h,"\t%s = (%s) findViewById(R.id.%s%s);\n",iptr->Contents.name,nature,fptr->identifier,iptr->Contents.name);
	}
	switch ( iptr->Contents.style & _FRAME_TYPE )
	{
	case	_BUTTON_FRAME	:
		fprintf(h,"\t%sBuffer = \"\";\n",iptr->Contents.name);
		break;
	case	_FORM_FRAME 	:
        	calculate_edit_size( &iptr->Contents );
        	calculate_form_lines( iptr, &linelength, &nblines );

        	if (!( fields = calculate_form_fields(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength) ))
			break;
		fprintf(h,"\t%sTarget = new int[] {",iptr->Contents.name);
		for ( sep="\0", i=1; i <= fields; i++ )
		{
			fprintf(h,"%sR.id.%s%sColumn%u",sep,fptr->identifier,iptr->Contents.name,i);
			sep=",";
		}
		fprintf(h,"};\n");
		break;
	case	_EDIT_FRAME	:
		if (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS ))
		{ 
			fprintf(h,"\t%s.setFocusable(false);\n",iptr->Contents.name); 
			fprintf(h,"\t%s.setFocusableInTouchMode(false);\n",iptr->Contents.name); 
			fprintf(h,"\t%s.setClickable(false);\n",iptr->Contents.name); 
			fprintf(h,"\t%s.setLongClickable(false);\n",iptr->Contents.name); 
			fprintf(h,"\t%s.setCursorVisible(false);\n",iptr->Contents.name); 
		}
	}
	return;
}

/*	----------------------------------------------------------	*/
/*	a n d r o i d _ c a l e n d a r _  c o n s t r u c t i o n	*/
/*	----------------------------------------------------------	*/
private	void	android_calendar_construction( FILE * h, struct form_control * fptr, struct form_item * iptr )
{
	int	r=0;
	int	g=0;
	int	b=0;
	int	fg;
	int	bg;
	/* ----------------------------------------------- */
	/* calendar has bug is first day not set to sunday */
	/* ----------------------------------------------- */
	fprintf(h,"\t%s.setFirstDayOfWeek(Calendar.SUNDAY);\n",iptr->Contents.name);
	/* ---------------------------------------- */
	/* set the selected week back ground colour */
	/* ---------------------------------------- */
	bg = (iptr->Contents.colour & 0x00FF); fg = (bg & 0x00FF); bg >>= 8;
	if ( bg )
	{
		get_rgb_values(bg,&r,&g,&b);
		fprintf(h,"\t%s.setSelectedWeekBackgroundColor(0x20%02.2x%02.2x%02.2x);\n",iptr->Contents.name,r,g,b);
	}	
	else	 fprintf(h,"\t%s.setSelectedWeekBackgroundColor(0x20E8E8E8);\n",iptr->Contents.name);
	get_rgb_values(fg,&r,&g,&b);
	fprintf(h,"\t%s.setFocusedMonthDateColor(0xff%02.2x%02.2x%02.2x);\n",iptr->Contents.name,r,g,b);
	fprintf(h,"\t%s.setUnfocusedMonthDateColor(0xff808080);\n",iptr->Contents.name);
	if ( iptr->Contents.events->xo_event & _EVENT_IS_FOCUS )
	{
		fprintf(h,"\t%s.setOnDateChangeListener( new OnDateChangeListener() {\n",iptr->Contents.name);
		fprintf(h,"\t\tpublic void onSelectedDayChange(CalendarView view, int year, int month, int day ){\n");
		fprintf(h,"\t\t\t%sEvent(view);\n",iptr->Contents.name);
		fprintf(h,"\t\t}\n\t} );\n");
	}
	return;
}

/*	---------------------------------------------------------	*/
/*	 a n d r o i d _ s p i n n e r _ c o n s t r u c t i o n	*/
/*	---------------------------------------------------------	*/
private	void	android_spinner_construction( FILE * h, struct form_control * fptr, struct form_item * iptr )
{
	/* -------------------------- */
	/* set the default value to 1 */
	/* -------------------------- */
	fprintf(h,"\t%sValue = 1;\n",iptr->Contents.name);

	/* ------------------------------------------- */
	/* set the click listener for this select item */
	/* ------------------------------------------- */
	fprintf(h,"\t%s.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {\n",iptr->Contents.name);
	fprintf(h,"\t\tpublic void onItemSelected(AdapterView<?> parent, View view, int pos, long id)\n\t\t{\n");
	fprintf(h,"\t\t\t%sValue = pos;\n",iptr->Contents.name);
	/* --------------------------------- */
	/* invoke explicite event if defined */
	/* --------------------------------- */
	if ( method_is_valid( iptr->Contents.events->on_event ) != 0)
	{ fprintf(h,"\t\t\t%sEvent(view);\n", iptr->Contents.name); }
	fprintf(h,"\t\t}\n");
	fprintf(h,"\t\tpublic void onNothingSelected(AdapterView<?> parent) {}\n");
	fprintf(h,"\t});\n");

	/* ----------------------------------------- */
	/* build the string adapter for this spinner */
	/* ----------------------------------------- */
	fprintf(h,"\tArrayAdapter<CharSequence> adapter%s = ArrayAdapter.createFromResource(this,R.array.%s%s, android.R.layout.simple_spinner_item);\n",
		iptr->Contents.name,fptr->identifier,iptr->Contents.name);
	fprintf(h,"\tadapter%s.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);\n",iptr->Contents.name);
	fprintf(h,"\t%s.setAdapter(adapter%s);\n",iptr->Contents.name,iptr->Contents.name);
	fprintf(h,"\t%s.setSelection(%sValue);\n",iptr->Contents.name,iptr->Contents.name);
}

/*	---------------------------------------------------------	*/
/*	a n d r o i d _ e x p l i c i t e _ d e s t r u c t i o n	*/
/*	---------------------------------------------------------	*/
private	void	android_explicite_destruction( FILE * h, struct form_item * iptr )
{
	/* --------------------------------------------- */
	/* explicite construction connection if provided */
	/* --------------------------------------------- */
	if (method_is_valid( iptr->Contents.events->on_remove ) ) 
	{ 
		android_call_remove( h, iptr ); 
	}
	return;
}

/*	-----------------------------------------------------------	*/
/*	a n d r o i d _ e x p l i c i t e _ c o n s t r u c t i o n	*/
/*	-----------------------------------------------------------	*/
private	void	android_explicite_construction( FILE * h, struct form_item * iptr )
{
	/* --------------------------------------------- */
	/* explicite construction connection if provided */
	/* --------------------------------------------- */
	if (method_is_valid( iptr->Contents.events->on_create ) ) 
	{ 
		android_call_create( h, iptr ); 
	}
	return;
}
/*	---------------------------------------------------	*/
/*	a n d r o i d _ m e m b e r _ d e s t r u c t i o n	*/
/*	---------------------------------------------------	*/
private	int	android_member_destruction( FILE * h, char * domain,struct form_control * fptr )
{
	struct	form_item * iptr;
	struct	data_control * dptr;
	int	fields=0;
	char *	sptr;
	char	classname[1024];
	for ( 	iptr = fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		switch ((iptr->Contents.style & _FRAME_TYPE))
		{
		case	_TEXT_FRAME	:
		case	_IMAGE_FRAME	:
		case	_EDIT_FRAME	:
		case	_FORM_FRAME	:
		case	_RADIO_FRAME	:
		case	_CHECK_FRAME	:
		case	_SWITCH_FRAME	:
		case	_SELECT_FRAME	:
		case	_BUTTON_FRAME	:
		case	_PROGRESS_FRAME	:
			android_explicite_destruction(h,iptr);
			continue;
		case	_DATA_FRAME	:
			android_explicite_destruction(h,iptr);
			if ( AndroidOption.handle_files )
			{
				if (!( is_file_Widget( iptr ) ))
                       			continue;
				else if (!( dptr = android_database_description( iptr, classname, &fields ) ))
					continue;
				else	fprintf(h,"\t%s.OnDestroy();\n",iptr->Contents.name);
			}
			continue;
		}
	}
	return(0);
}

/*	-----------------------------------------------------	*/
/*	a n d r o i d _ m e m b e r _ c o n s t r u c t i o n	*/
/*	-----------------------------------------------------	*/
private	int	android_member_construction( FILE * h, char * domain,struct form_control * fptr )
{
	struct	form_item * iptr;
	char *	fnptr;
	struct	data_control * dptr;
	int	fields=0;
	char *	sptr;
	char	classname[1024];
	for ( 	iptr = fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		switch ((iptr->Contents.style & _FRAME_TYPE))
		{
		case	_IMAGE_FRAME	:
			android_implicite_construction(h,fptr, iptr,"ImageView");
			android_explicite_construction(h,iptr);
			continue;
		case	_TEXT_FRAME	:
			android_implicite_construction(h,fptr, iptr,"TextView");
			android_explicite_construction(h,iptr);
			continue;
		case	_CHECK_FRAME	:
			android_implicite_construction(h,fptr,iptr,"CheckBox");
			android_explicite_construction(h,iptr);
			continue;
		case	_RADIO_FRAME	:
			android_implicite_construction(h,fptr,iptr,"RadioButton");
			android_explicite_construction(h,iptr);
			continue;
		case	_EDIT_FRAME	:
			android_implicite_construction(h,fptr,iptr,"EditText");
			android_explicite_construction(h,iptr);
			continue;
		case	_SWITCH_FRAME	:
			android_implicite_construction(h,fptr,iptr,"ToggleButton");
			android_explicite_construction(h,iptr);
			continue;
		case	_BUTTON_FRAME	:
			switch (( iptr->Contents.align & 3))
			{
			case	0:
				android_implicite_construction(h,fptr,iptr,"Button");
				break;
			case	1:
				android_implicite_construction(h,fptr,iptr,"Button");
				break;
			case	2:
				android_implicite_construction(h,fptr,iptr,"TextView");
				break;
			case	3:
				android_implicite_construction(h,fptr,iptr,"ImageView");
				break;
			}
			android_explicite_construction(h,iptr);
			continue;
		case	_SELECT_FRAME	:
			android_implicite_construction(h,fptr,iptr,"Spinner");
			android_spinner_construction(h,fptr,iptr);
			android_explicite_construction(h,iptr);
			continue;
		case	_PROGRESS_FRAME	:
			android_implicite_construction(h,fptr,iptr,"ProgressBar");
			android_explicite_construction(h,iptr);
			continue;
		case	_FORM_FRAME	:
			android_implicite_construction(h,fptr,iptr,"ListView");
			android_explicite_construction(h,iptr);
			continue;
		case	_DATA_FRAME	:
			if ( AndroidOption.handle_files )
			{
				if ( is_file_Widget( iptr ) )
				{
					if (!( dptr = android_database_description( iptr, classname, &fields ) ))
						continue;
					else
					{
						/* ----------------------------------------------- */
						/* The OCCI MIRROR uses the FILE constructor below */
						/* ----------------------------------------------- */
						if ((iptr->Contents.align & 0x000F) == _OCCI_FRAME )
						{
							fprintf(h,"\t%s = new %s(", iptr->Contents.name, classname);
							sptr = "http://127.0.0.1";
							fprintf(h,"\"%s\"",sptr);
							if (!( sptr = abal_payload( iptr ) ))
								sptr ="myfilename";
							fprintf(h,",\"%s\");\n",sptr);
						}
						else
						{
							fprintf(h,"\t%s = new %s(getFilesDir().getPath(),", iptr->Contents.name, classname);
							if (!( sptr = application_databasename() ))
								sptr = "mydatabase";
							fprintf(h,"\"%s\"",sptr);
							if (!( sptr = abal_payload( iptr ) ))
								sptr ="myfilename";
							fprintf(h,",\"%s\");\n",sptr);
						}
						android_explicite_construction(h,iptr);
						continue;
					}
				}
				else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
					continue;
				else if (( iptr->Contents.datatype != _WIDGET_OVERLAY )
				     &&  ( iptr->Contents.datatype != _WIDGET_MODULE  ))
					continue;
				else if (!( fnptr = abal_payload(iptr) ))
                       			continue;
				else if ( strncmp( fnptr, "android:", strlen("android:") ) != 0 )
					continue;
				else if (!( strcmp( fnptr, "android:calendar" ) ))
				{
					android_implicite_construction(h,fptr,iptr,"CalendarView");
					android_calendar_construction(h,fptr,iptr);
					android_explicite_construction(h,iptr);
				}
				else if (!( strcmp( fnptr, "android:time" ) ))
				{
					android_implicite_construction(h,fptr,iptr,"TimePicker");
					android_explicite_construction(h,iptr);
				}
				else if (!( strcmp( fnptr, "android:date" ) ))
				{
					android_implicite_construction(h,fptr,iptr,"DatePicker");
					android_explicite_construction(h,iptr);
				}
				else if (!( strcmp( fnptr, "android:MapFragment" ) ))
				{
					android_implicite_construction(h,fptr,iptr,"MapFragment");
					android_explicite_construction(h,iptr);
				}
				// android custom view
				else 
				{
					android_implicite_construction(h,fptr,iptr,(fnptr+strlen("android:")));
					android_explicite_construction(h,iptr);
				}
			}
			continue;
		}
	}
	return(0);
}

/*	-------------------------------------------------------------	*/
/*	a n d r o i d _ b a s e m e m b e r _ c o n s t r u c t i o n	*/
/*	-------------------------------------------------------------	*/
private	int	android_basemember_construction( FILE * h, char * domain, char * extends )
{
	struct form_control * fptr;
	if (!( AndroidOption.inherit ))
		return(1);
	if (!( method_is_valid( extends ) ))
		return(1);
	else if (!( fptr = locate_form_control( extends ) ))
		return(1);
	else 	return( android_member_construction( h, domain, fptr ) );
}

/*	-------------------------------------------------------------	*/
/*	a n d r o i d _ b a s e m e m b e r _ d e s t r u c t i o n	*/
/*	-------------------------------------------------------------	*/
private	int	android_basemember_destruction( FILE * h, char * domain, char * extends )
{
	struct form_control * fptr;
	if (!( AndroidOption.inherit ))
		return(1);
	if (!( method_is_valid( extends ) ))
		return(1);
	else if (!( fptr = locate_form_control( extends ) ))
		return(1);
	else 	return( android_member_destruction( h, domain, fptr ) );
}

/*	-------------------------------------------------------------	*/
/*	a n d r o i d _ b a s e m e m b e r _ c r e a t e 		*/
/*	-------------------------------------------------------------	*/
private	int	android_basemember_create( FILE * h, char * domain, char * extends )
{
	struct form_control * fptr;
	if (!( AndroidOption.inherit ))
		return(1);
	if (!( method_is_valid( extends ) ))
		return(1);
	else if (!( fptr = locate_form_control( extends ) ))
		return(1);
	else 	return( android_member_create( h, domain, fptr ) );
}

/*	-------------------------------------------------------------	*/
/*	a n d r o i d _ b a s e m e m b e r _ r e m o v e		*/
/*	-------------------------------------------------------------	*/
private	int	android_basemember_remove( FILE * h, char * domain, char * extends )
{
	struct form_control * fptr;
	if (!( AndroidOption.inherit ))
		return(1);
	if (!( method_is_valid( extends ) ))
		return(1);
	else if (!( fptr = locate_form_control( extends ) ))
		return(1);
	else 	return( android_member_remove( h, domain, fptr ) );
}

/*	-------------------------------------------------------------	*/
/*	a n d r o i d _ b a s e m e m b e r _ s h o w 			*/
/*	-------------------------------------------------------------	*/
private	int	android_basemember_show( FILE * h, char * domain, char * extends )
{
	struct form_control * fptr;
	if (!( AndroidOption.inherit ))
		return(1);
	if (!( method_is_valid( extends ) ))
		return(1);
	else if (!( fptr = locate_form_control( extends ) ))
		return(1);
	else 	return( android_member_show( h, domain, fptr ) );
}

/*	-------------------------------------------------------------	*/
/*	a n d r o i d _ b a s e m e m b e r _ c a l l _ s h o w 	*/
/*	-------------------------------------------------------------	*/
private	int	android_basemember_call_show( FILE * h, char * domain, char * extends )
{
	struct form_control * fptr;
	if (!( AndroidOption.inherit ))
		return(1);
	if (!( method_is_valid( extends ) ))
		return(1);
	else if (!( fptr = locate_form_control( extends ) ))
		return(1);
	else 	return( android_member_call_show( h, domain, fptr ) );
}

/*	-------------------------------------------------------------	*/
/*	a n d r o i d _ b a s e m e m b e r _ h i d e 			*/
/*	-------------------------------------------------------------	*/
private	int	android_basemember_hide( FILE * h, char * domain, char * extends )
{
	struct form_control * fptr;
	if (!( AndroidOption.inherit ))
		return(1);
	if (!( method_is_valid( extends ) ))
		return(1);
	else if (!( fptr = locate_form_control( extends ) ))
		return(1);
	else 	return( android_member_hide( h, domain, fptr ) );
}

/*	-------------------------------------------------------------	*/
/*	a n d r o i d _ b a s e m e m b e r _ c a l l _ h i d e 	*/
/*	-------------------------------------------------------------	*/
private	int	android_basemember_call_hide( FILE * h, char * domain, char * extends )
{
	struct form_control * fptr;
	if (!( AndroidOption.inherit ))
		return(1);
	if (!( method_is_valid( extends ) ))
		return(1);
	else if (!( fptr = locate_form_control( extends ) ))
		return(1);
	else 	return( android_member_call_hide( h, domain, fptr ) );
}

/*	-------------------------------------	*/
/*	a n d r o i d _ m e m b e r _ h i d e 	*/
/*	-------------------------------------	*/
private	int	android_member_call_hide( FILE * h, char * domain,struct form_control * fptr )
{
	struct	form_item * iptr;
	for ( 	iptr = fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		switch ((iptr->Contents.style & _FRAME_TYPE))
		{
		case	_TEXT_FRAME	:
		case	_IMAGE_FRAME	:
		case	_EDIT_FRAME	:
		case	_FORM_FRAME	:
		case	_RADIO_FRAME	:
		case	_CHECK_FRAME	:
		case	_SWITCH_FRAME	:
		case	_SELECT_FRAME	:
		case	_BUTTON_FRAME	:
		case	_PROGRESS_FRAME	:
			/* ---------------------------------------- */
			/* explicite display suppliment if provided */
			/* ---------------------------------------- */
			if (method_is_valid( iptr->Contents.events->on_hide ) ) 
			{ 
				android_call_hide( h, iptr ); 
			}
		}
	}
	return(0);
}

/*	-------------------------------------	*/
/*	a n d r o i d _ m e m b e r _ s h o w 	*/
/*	-------------------------------------	*/
private	int	android_member_call_show( FILE * h, char * domain,struct form_control * fptr )
{
	struct	form_item * iptr;
	for ( 	iptr = fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		switch ((iptr->Contents.style & _FRAME_TYPE))
		{
		case	_TEXT_FRAME	:
			/* ------------------------------------------------------------------------ */
			/* these TEXTS are pop up toast messages and must not call show from create */
			/* ------------------------------------------------------------------------ */
			if ( iptr->Contents.events->xo_hide & _EVENT_IS_POP )
				continue;
		case	_IMAGE_FRAME	:
		case	_EDIT_FRAME	:
		case	_FORM_FRAME	:
		case	_RADIO_FRAME	:
		case	_CHECK_FRAME	:
		case	_SWITCH_FRAME	:
		case	_SELECT_FRAME	:
		case	_BUTTON_FRAME	:
		case	_PROGRESS_FRAME	:
			/* ---------------------------------------- */
			/* explicite display suppliment if provided */
			/* ---------------------------------------- */
			if (method_is_valid( iptr->Contents.events->on_show ) ) 
			{ 
				android_call_show( h, iptr ); 
			}
		}
	}
	return(0);
}

/*	-------------------------------------	*/
/*	d e t e c t _ a n d r o i d _ m e n u	*/
/*	-------------------------------------	*/
private	void	detect_android_menu( FILE * h, struct form_control * fptr )
{
	struct	forms_method * mptr;
	struct	forms_method * mmptr;
	char *	target;
	struct	form_control * ffptr;
	/* ---------------------------------------------- */
	/* detect that the form uses the menu search view */
	/* ---------------------------------------------- */
	if ((mptr = detect_forms_method( fptr, _JAVA_SEARCH )) != (struct forms_method *) 0)
	{
		/* ------------------------------------------------- */
		/* check the legality of the SEARCH/FINDER relations */
		/* ------------------------------------------------- */
		target = (mptr->name + strlen(_JAVA_SEARCH) + 1 );
		if (!( ffptr = locate_form_control( target ) ))
			android_warning( fptr, "cannot find form", target, "for search target" );
		else if (!(mmptr = detect_forms_method( ffptr, _JAVA_FINDER )))
			android_warning( fptr, target, "needs method",_JAVA_FINDER );
		else
		{
			/* ------------------------------------- */
			/* generate the search menu construction */
			/* ------------------------------------- */
			android_java_comment(h,fptr->identifier,"onCreateOptionsMenu");
			fprintf(h,"@Override public boolean onCreateOptionsMenu(Menu menu)\n{\n");
			fprintf(h,"\tMenuInflater inflater = getMenuInflater();\n");
			fprintf(h,"\tinflater.inflate(R.menu.options_menu,menu);\n");
			fprintf(h,"\tSearchManager sm = (SearchManager) getSystemService(Context.SEARCH_SERVICE);\n");
			fprintf(h,"\tSearchView sv = (SearchView) menu.findItem(R.id.actionBarSearch).getActionView();\n");
			fprintf(h,"\tComponentName target = new ComponentName(getApplicationContext(), %s.class);\n",
				(mptr->name+strlen(_JAVA_SEARCH)+1));
			fprintf(h,"\tsv.setSearchableInfo(sm.getSearchableInfo(target));\n");
			fprintf(h,"\treturn super.onCreateOptionsMenu(menu);\n");
			fprintf(h,"}\n");
		}

		/* ------------------------------------------------------- */
		/* generate the event catcher to perform the required work */
		/* ------------------------------------------------------- */
		if ( method_is_valid( mptr->text ) )
		{
			fprintf(h,"public boolean onOptionsItemSelected(MenuItem item)\n{\n");
			fprintf(h,"\tswitch (item.getItemId())\n\t{\n");
			fprintf(h,"\tcase R.id.actionBarSearch:\n");
			fprintf(h,"\t\t%s();\n",_JAVA_SEARCH);
			fprintf(h,"\t\treturn true;\n");
			fprintf(h,"\tdefault: return super.onOptionsItemSelected(item);\n");
			fprintf(h,"\t}\n");
			fprintf(h,"}\n");

			/* -------------------------------------------- */
			/* generate the specialised search event caller */
			/* -------------------------------------------- */
			fprintf(h,"private void %s()\n{\n",_JAVA_SEARCH);
				android_method_body(h, mptr->text );
			fprintf(h,"}\n");
		}

	}

	return;
}

/*	---------------------------------------------		*/
/*	a n d r o i d _ m a p _ c o n s t r u c t o r		*/
/*	---------------------------------------------		*/
private	void	android_map_constructor( FILE * h, struct form_control * fptr, struct form_item * iptr )
{	
	fprintf(h,"\tMapFragment mapFragment = (MapFragment) getFragmentManager();\n");
	fprintf(h,"\tif ( mapFragment != null )\n\t{\n");
	fprintf(h,"\t\tmapFragment.findFragmentById(R.id.%s%s);\n",fptr->identifier,iptr->Contents.name);
	fprintf(h,"\t\tmapFragment.OetMapAsync(this);\n\t}\n");
	return;
}


/*	---------------------------------------------		*/
/*	a n d r o i d _ g p s _ c o n s t r u c t o r		*/
/*	---------------------------------------------		*/
private	void	android_gps_constructor( FILE * h, struct form_control * fptr )
{	
	fprintf(h,"\tlocationManager = (LocationManager) this.getSystemService(Context.LOCATION_SERVICE);\n");
	fprintf(h,"\tif ( locationManager != null )\n\t{\n");
	fprintf(h,"\t\tlocationListener = new LocationListener() {\n");
    	fprintf(h,"\t\t\tpublic void onLocationChanged(Location location) { SingAndroidGps(location); }\n");
    	fprintf(h,"\t\t\tpublic void onStatusChanged(String provider, int status, Bundle extras) {}\n");
    	fprintf(h,"\t\t\tpublic void onProviderEnabled(String provider) {}\n");
    	fprintf(h,"\t\t\tpublic void onProviderDisabled(String provider) {}\n");
  	fprintf(h,"\t\t};\n");
	fprintf(h,"\t\tlocationManager.requestLocationUpdates(LocationManager.GPS_PROVIDER, 0, 0, locationListener);\n");
	fprintf(h,"\t\tcurrentLocation = locationManager.getLastKnownLocation(LocationManager.GPS_PROVIDER);\n");
	fprintf(h,"\t}\n");
	return;
}
/*	-----------------------------------------------		*/
/*	a n d r o i d _ m a p _ c o n s t r u c t i o n 	*/
/*	-----------------------------------------------		*/
private	void	android_map_construction( FILE * h, struct form_control * fptr )
{	
	struct	form_item * iptr;
	char *	fnptr;
	return;
	for ( 	iptr = fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		if (( iptr->Contents.style & _FRAME_TYPE) != _DATA_FRAME)
			continue;
		else if ( is_file_Widget( iptr ) )
			continue;
		else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
			continue;
		else if (( iptr->Contents.datatype != _WIDGET_OVERLAY )
		     &&  ( iptr->Contents.datatype != _WIDGET_MODULE  ))
			continue;
		else if (!( fnptr = abal_payload(iptr) ))
			continue;
		else if ( strncmp( fnptr, "android:", strlen( "android:" ) ) != 0)
			continue;
		else if (!( strcasecmp( fnptr, "android:MapFragment" )))
			android_map_constructor( h, fptr, iptr );
	}
	return;
}

/*	---------------------------------------		*/
/*	a n d r o i d _ c l a s s _ e v e n t s 	*/
/*	---------------------------------------		*/
private	int	android_class_events( FILE * h, char * domain,struct form_control * fptr, int mainmode )
{
	struct	form_item * iptr;
	struct	forms_method * mptr;


	/* ------------------------------ */
	/* overload the class constructor */
	/* ------------------------------ */
	if ( AndroidOption.sqlcipher & 1 )
	{
		fprintf(h,"public void OnLoadLibraries()\n{\n");
		fprintf(h,"\tSQLiteDatabase.loadLibs(this);\n");
		fprintf(h,"}\n");
	}
	android_java_comment(h,fptr->identifier,"onCreate");
	fprintf(h,"@Override protected void onCreate(Bundle savedInstanceState)\n{\n");
	if ( mainmode & 1 )
	{
		if ( AndroidOption.sqlcipher & 1 )
		{
			fprintf(h,"\tOnLoadLibraries();\n");
		}
	}
	fprintf(h,"\tsuper.onCreate(savedInstanceState);\n");
	if ( mainmode & 1 )
	{
		fprintf(h,"\tStrictMode.ThreadPolicy policy = new StrictMode.ThreadPolicy.Builder().permitAll().build();\n");
		fprintf(h,"\tStrictMode.setThreadPolicy(policy);\n");
	}

	/* ------------------------- */
	/* always receive the intent */
	/* ------------------------- */
	fprintf(h,"\targV = getIntent();\n");

	/* ------------------------------------------------ */
	/* activate back button to chain to parent activity */
	/* ------------------------------------------------ */
	if (!( mainmode & 1 ))
		if (( mptr = detect_forms_method( fptr, _JAVA_PARENT )) != (struct forms_method *) 0)
			fprintf(h,"\tgetSupportActionBar().setDisplayHomeAsUpEnabled(true);\n");

	if (!( mainmode & 2 ))
	{ fprintf(h,"\tsetContentView(R.layout.%s);\n",fptr->identifier); }

	/* --------------------------------------------- */
	/* detect the presence of a Finder Target Widget */
	/* --------------------------------------------- */
	if ((mptr = detect_forms_method( fptr, _JAVA_FINDER )) != (struct forms_method *) 0)
	{
		fprintf(h,"\tif ( Intent.ACTION_SEARCH.equals(argV.getAction()) )\n\t{\n");
		fprintf(h,"\t\tsearchCriteria = argV.getStringExtra(SearchManager.QUERY);\n\t}\n");
	}

	/* ------------------------------ */
	/* detect presence of map manager */
	/* ------------------------------ */
	if ((mptr = detect_forms_method( fptr, _JAVA_MAP )) != (struct forms_method *) 0)
		android_map_construction( h, fptr );

	/* ------------------------------ */
	/* detect presence of GPS manager */
	/* ------------------------------ */
	if ((mptr = detect_forms_method( fptr, _JAVA_GPS )) != (struct forms_method *) 0)
		android_gps_constructor( h, fptr );

	/* --------------------- */
	/* build all the widgets */
	/* --------------------- */
	android_basemember_construction(h,domain,fptr->extends);
	android_member_construction(h,domain,fptr);

	android_basemember_call_show(h,domain,fptr->extends);
	android_member_call_show(h,domain,fptr);
	fprintf(h,"}\n");

	// ------------------------------
	// Handle the Map Ready Call back
	// ------------------------------
	if ((mptr = detect_forms_method( fptr, _JAVA_MAP )) != (struct forms_method *) 0)
	{
		android_java_comment(h,fptr->identifier,"onMapReady");
		fprintf(h,"@Override public void onMapReady(GoogleMap map)\n{\n");
			android_method_body(h, mptr->text );
		fprintf(h,"}\n");

	}

	/* ------------------------------- */
	/* detect and handle search option */
	/* ------------------------------- */
	detect_android_menu(h,fptr);

	/* ------------------------------ */
	/* overload the class destructor  */
	/* ------------------------------ */
	android_java_comment(h,fptr->identifier,"onDestroy");
	fprintf(h,"@Override protected void onDestroy()\n{\n");
	android_member_call_hide(h,domain,fptr);
	android_basemember_call_hide(h,domain,fptr->extends);
	android_member_destruction(h,domain,fptr);
	android_basemember_destruction(h,domain,fptr->extends);
	fprintf(h,"\tsuper.onDestroy();\n");
	fprintf(h,"}\n");

	/* --------------------------- */
	/* generate the create methods */
	/* --------------------------- */
	android_basemember_create( h, domain, fptr->extends );
	android_member_create( h, domain, fptr );

	/* ------------------------- */
	/* generate the show methods */
	/* ------------------------- */
	android_basemember_show( h, domain, fptr->extends );
	android_member_show( h, domain, fptr );

	/* -------------------------- */
	/* generate the event methods */
	/* -------------------------- */
	android_basemember_events( h, domain, fptr->extends );
	android_member_events( h, domain, fptr );

	/* ------------------------- */
	/* generate the hide methods */
	/* ------------------------- */
	android_basemember_hide( h, domain, fptr->extends );
	android_member_hide( h, domain, fptr );

	/* --------------------------- */
	/* generate the remove methods */
	/* --------------------------- */
	android_basemember_remove( h, domain, fptr->extends );
	android_member_remove( h, domain, fptr );

	return(1);
}

/*	-----------------------------------------	*/
/*	a n d r o i d _ m e m b e r _ e v e n t s 	*/
/*	-----------------------------------------	*/
private	int	android_member_events( FILE * h, char * domain, struct form_control * fptr )
{
	struct	form_item * iptr;
	char *	fnptr;

	/* ---------------- */
	/* generate methods */
	/* ---------------- */
	for ( 	iptr = fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		switch ((iptr->Contents.style & _FRAME_TYPE))
		{
		case	_EDIT_FRAME	:
		case	_RADIO_FRAME	:
		case	_CHECK_FRAME	:
		case	_SWITCH_FRAME	:
		case	_SELECT_FRAME	:
		case	_PROGRESS_FRAME	:
		case	_IMAGE_FRAME	:
		case	_TEXT_FRAME	:
			if (method_is_valid( iptr->Contents.events->on_event ) )
			{
				android_java_comment(h,iptr->Contents.name,"Event");
				fprintf(h,"public void %sEvent(View view)\n{\n",iptr->Contents.name);
				android_method_body( h, iptr->Contents.events->on_event );
				fprintf(h,"}\n");
			}
			break;
		case	_DATA_FRAME	:
			if ( is_file_Widget( iptr ) )
        	              	continue;
			else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
				continue;
			else if (( iptr->Contents.datatype != _WIDGET_OVERLAY )
			     &&  ( iptr->Contents.datatype != _WIDGET_MODULE  ))
				continue;
			else if (!( fnptr = abal_payload(iptr) ))
               	       		continue;
			else if ( strncmp( fnptr, "android:", strlen("android:") ) != 0 )
				continue;
			else if (!(method_is_valid( iptr->Contents.events->on_event ) ))
				continue;
			else if ((!( strcmp( fnptr, "android:calendar" ) ))
			     ||  (!( strcmp( fnptr, "android:time" ) ))
			     ||  (!( strcmp( fnptr, "android:date" ) )))
			{
				android_java_comment(h,iptr->Contents.name,"Event");
				fprintf(h,"public void %sEvent(View view)\n{\n",iptr->Contents.name);
				android_method_body( h, iptr->Contents.events->on_event );
				fprintf(h,"}\n");
			}
			// android custom view
			else 
			{
				android_java_comment(h,iptr->Contents.name,"Event");
				fprintf(h,"public void %sEvent(View view)\n{\n",iptr->Contents.name);
				android_method_body( h, iptr->Contents.events->on_event );
				fprintf(h,"}\n");
			}
			break;

		case	_FORM_FRAME	:
			if (method_is_valid( iptr->Contents.events->on_event ) )
			{
				android_java_comment(h,iptr->Contents.name,"Event");
				fprintf(h,"public void %sEvent(View view,int line)\n{\n",iptr->Contents.name);
				/* ----------------------------------------------------------- */
				/* check for EVENT options indicating Database Cursor Handling */
				/* ----------------------------------------------------------- */
				if ( iptr->Contents.events->xo_event & _EVENT_IS_FOCUS )
				{
					if (AndroidOption.sqlcipher & 1)
					{	
						fprintf(h,"\tCrossProcessCursorWrapper c=(CrossProcessCursorWrapper) %s.getItemAtPosition(line);\n",
							iptr->Contents.name);
					}
					else
					{
						fprintf(h,"\tSQLiteCursor c=(SQLiteCursor) %s.getItemAtPosition(line);\n",
							iptr->Contents.name);
					}
				}
				android_method_body( h, iptr->Contents.events->on_event );
				fprintf(h,"}\n");
			}
			break;
		case	_BUTTON_FRAME	:
			android_java_comment(h,iptr->Contents.name,"Event");
			fprintf(h,"public void %sEvent(View view)\n{\n",iptr->Contents.name);
			/* ------------------------------ */
			/* generate the event method body */
			/* ------------------------------ */
			if (method_is_valid( iptr->Contents.events->on_event ) )
			{
				android_method_body( h, iptr->Contents.events->on_event );
			}

			/* ---------------------------------------- */
			/* generate the button target specific code */
			/* ---------------------------------------- */
			switch ( iptr->Contents.datatype )
			{
			case	_WIDGET_CHAIN	:
				android_java_comment(h,"Chain to Activity: ",iptr->Contents.format);
				fprintf(h,"\tgetIntent().setFlags(Intent.FLAG_ACTIVITY_NO_HISTORY);\n");
				fprintf(h,"\tIntent intent = new Intent(this,%s.class);\n",iptr->Contents.format);
				fprintf(h,"\tintent.putExtra(ARGV1,%sBuffer);\n",iptr->Contents.name);
				fprintf(h,"\tstartActivity(intent);\n");
				fprintf(h,"\tthis.finish();\n");
				break;
			case	_WIDGET_LOADGO	:
				/* -------------------------- */
				/* handle the chain operation */
				/* -------------------------- */
				android_java_comment(h,"LOADGO Activity: ",iptr->Contents.format);
				fprintf(h,"\tgetIntent().setFlags(Intent.FLAG_ACTIVITY_NO_HISTORY);\n");
				fprintf(h,"\tIntent intent = new Intent(this,%s.class);\n",iptr->Contents.format);
				fprintf(h,"\tintent.putExtra(ARGV1,%sBuffer);\n",iptr->Contents.name);
				fprintf(h,"\tstartActivity(intent);\n");
				break;
			}
			fprintf(h,"}\n");
		}
	}
	return(1);
}

/*	-------------------------------------------------	*/
/*	a n d r o i d _ b a s e m e m b e r _ e v e n t s 	*/
/*	-------------------------------------------------	*/
private	int	android_basemember_events( FILE * h, char * domain, char * extends )
{
	struct form_control * fptr;
	if (!( AndroidOption.inherit ))
		return(1);
	if (!( method_is_valid( extends ) ))
		return(1);
	else if (!( fptr = locate_form_control( extends ) ))
		return(1);
	else 	return( android_member_events( h, domain, fptr ) );
}

/*	---------------------------------------		*/
/*	a n d r o i d _ c l a s s _ r e s u m e 	*/
/*	---------------------------------------		*/
/*	this will be needed for applications		*/
/*	that use Near Field Devices			*/
/*	---------------------------------------		*/
private	int	android_class_resume( FILE * h, char * domain,struct form_control * fptr )
{
	struct	forms_method * mptr;
	fprintf(h,"protected void onResume()\n{\n");
	fprintf(h,"\tsuper.onResume();\n");
	fprintf(h,"\tIntent intent = getIntent();\n");
	fprintf(h,"\tif (NfcAdapter.ACTION_NDEF_DISCOVERED.equals(intent.getAction()))\n\t{\n");
	fprintf(h,"\t\tParcelable[] rawMsgs = intent.getParcelableArrayExtra(NfcAdapter.EXTRA_NDEF_MESSAGES);\n");
	fprintf(h,"\t\tif (rawMsgs != null)\n\t\t{\n");
	fprintf(h,"\t\t\tNdefMessage[] msgs = new NdefMessage[rawMsgs.length];\n");
	fprintf(h,"\t\t\tfor (int i = 0; i < rawMsgs.length; i++)\n\t\t\t{\n");
	fprintf(h,"\t\t\t\tmsgs[i] = (NdefMessage) rawMsgs[i];\n");
	fprintf(h,"\t\t\t}\n");	
	/* ------------------------------------------------------------- */
	/* detect forms method named like OnNdefEvent or Silently Ignore */
	/* ------------------------------------------------------------- */
	if ((mptr = detect_forms_method( fptr, _NDEF_EVENT )) != (struct forms_method *) 0)
		fprintf(h,"\t\t\t%s( msgs );\n",mptr->name);
	fprintf(h,"\t\t}\n");
	fprintf(h,"\t}\n");
	fprintf(h,"\telse if (NfcAdapter.ACTION_TECH_DISCOVERED.equals(intent.getAction()))\n\t{\n");
	fprintf(h,"\t\tTag tagFromIntent =  intent.getParcelableExtra(NfcAdapter.EXTRA_TAG);\n");
	if ((mptr = detect_forms_method( fptr, _TECH_EVENT )) != (struct forms_method *) 0)
		fprintf(h,"\t\t\t%s( tagFromIntent );\n",mptr->name);
	fprintf(h,"\t}\n");
	fprintf(h,"\telse if (NfcAdapter.ACTION_TAG_DISCOVERED.equals(intent.getAction()))\n\t{\n");
	fprintf(h,"\t\tTag tagFromIntent =  intent.getParcelableExtra(NfcAdapter.EXTRA_TAG);\n");
	if ((mptr = detect_forms_method( fptr, _TAG_EVENT )) != (struct forms_method *) 0)
		fprintf(h,"\t\t\t%s( tagFromIntent );\n",mptr->name);
	fprintf(h,"\t}\n");
	fprintf(h,"}\n");
	return(0);
}

/*	-----------------------------------------	*/
/*	a n d r o i d _ c o u n t _ w i d g e t s	*/
/*	-----------------------------------------	*/
private	void	android_count_widgets( struct form_control * fptr )
{
	struct	form_item * iptr;
	int	i;
	/* ----------------------- */
	/* count widget occurences */
	/* ----------------------- */
	for ( i=0; i < _MAX_WIDGETS; i++) 
		AndroidOption.widgets[i] = 0;
	for ( iptr = fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
		AndroidOption.widgets[(iptr->Contents.style & _FRAME_TYPE)] += 1;
	return;
}

/*	-----------------------------------------	*/
/*	g e n e r a t e_ a n d r o i d _ cl a s s 	*/
/*	-----------------------------------------	*/
private	int	generate_android_class( FILE * h, char * domain,struct form_control * fptr, char * packname, int mainmode )
{
	char	*	baseclass="ActionBarActivity";
	char 	*	interface=(char *) 0;
	struct	forms_method * mptr;
	android_count_widgets(fptr);
	android_class_header(h,domain,packname,fptr);
	android_class_import(h,domain,fptr);
	android_form_import(h,domain,fptr);
	if ( AndroidOption.handle_nfd )
	{
		if ( fptr->mimoflags & _MIMO_KEYBOARD )
		{
		}
	}
	if ( method_is_valid( fptr->extends ) != 0 )
	{
		baseclass = fptr->extends;
	}

	if ((mptr = detect_forms_method(fptr, _JAVA_MAP )) != (struct forms_method *) 0)
	{
		interface = "OnMapReadyCallback";
		if (!( baseclass ))
			baseclass = "FragmentActivity";
	}
	else	interface = (char *) 0;

	android_class_definition(h,domain,fptr->identifier, baseclass,interface);
	android_class_members(h,domain,fptr);
	android_class_events(h,domain,fptr,mainmode);
	android_baseforms_methods(h,domain,fptr->extends);
	android_forms_methods(h,domain,fptr);
	if ( AndroidOption.handle_nfd )
	{
		if ( fptr->mimoflags & _MIMO_KEYBOARD )
		{
			android_class_resume( h, domain, fptr );
		}
	}
	android_class_footer(h,domain,fptr->identifier);
	fclose(h);
	return(1);
}

/*	-------------------------------------------------	*/
/*	g e n e r a t e _ a n d r o i d _ d a t a b a s e 	*/
/*	-------------------------------------------------	*/
private	int	generate_android_database( FILE * h, char * domain, struct form_control * fptr, char * pathroot, char * package )
{
	struct	form_item * iptr;

	for ( 	iptr = fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		if (( iptr->Contents.style & _FRAME_TYPE ) != _DATA_FRAME )
			continue;
		else if (!( is_file_Widget( iptr ) ))
                        continue;
		else	android_database_class( h, domain, fptr, iptr, pathroot, package,AndroidOption.sqlcipher );
	}
	return(1);
}

/*	---------------------------------	*/
/*	a n d r o i d _ c h a r a c t e r	*/
/*	---------------------------------	*/
private	int	unicode(int c )
{
	return((0x00C080 | ( c &  0x003F ) | (( c & 0x07C0 ) << 2)));
}

private	int	unicode_android_character( int c )
{
	switch ( c & 0x00FF )
	{
        case    0x0085 /* '<85>' */     : return(unicode(224));
        case    0x00A0 /* ' ' */        : return(unicode(225));
        case    0x0083 /* '<83>' */     : return(unicode(226));
        case    0x008A /* '<8a>' */     : return(unicode(232));
        case    0x0082 /* '<82>' */     : return(unicode(233));
        case    0x0088 /* '<88>' */     : return(unicode(234));
        case    0x008D /* '<8d>' */     : return(unicode(236));
        case    0x00A1 /* ' ' */        : return(unicode(237));
        case    0x008C /* '<8c>' */     : return(unicode(238));
        case    0x0095 /* '<95>' */     : return(unicode(242));
        case    0x00A2 /* ' ' */        : return(unicode(243));
        case    0x0093 /* '<93>' */     : return(unicode(244));
        case    0x0097 /* '<97>' */     : return(unicode(249));
        case    0x00A3 /* '   */        : return(unicode(250));
        case    0x0096 /* '<96>' */     : return(unicode(251));
        case    0x0087 /* '<87>' */     : return(unicode(231));
        case    0x0081 /* '<81>' */     : return(unicode(252));
        case    0x0084 /* '<84>' */     : return(unicode(228));
        case    0x0094 /* '<94>' */     : return(unicode(246));
        case    0x009A /* 'U' */        : return(unicode(220));
        case    0x008E /* 'A' */        : return(unicode(196));
        case    0x0099 /* 'O' */        : return(unicode(214));
	default				: return( c );
	}
}

/*	---------------------------------	*/
/*	a n d r o i d _ c h a r a c t e r	*/
/*	---------------------------------	*/
private	int	ascii_android_character( int c )
{
	switch ( c & 0x00FF )
	{
        case    0x0085 /* '<85>' */     : return('a');
        case    0x00A0 /* ' ' */        : return('a');
        case    0x0083 /* '<83>' */     : return('a');
        case    0x008A /* '<8a>' */     : return('e');
        case    0x0082 /* '<82>' */     : return('e');
        case    0x0088 /* '<88>' */     : return('e');
        case    0x008D /* '<8d>' */     : return('i');
        case    0x00A1 /* '¡' */        : return('i');
        case    0x008C /* '<8c>' */     : return('i');
        case    0x0095 /* '<95>' */     : return('o');
        case    0x00A2 /* '¢' */        : return('o');
        case    0x0093 /* '<93>' */     : return('o');
        case    0x0097 /* '<97>' */     : return('u');
        case    0x00A3 /* '£' */        : return('u');
        case    0x0096 /* '<96>' */     : return('u');
        case    0x0087 /* '<87>' */     : return('c');
        case    0x0081 /* '<81>' */     : return('u');
        case    0x0084 /* '<84>' */     : return('a');
        case    0x0094 /* '<94>' */     : return('o');
        case    0x009A /* 'U' */        : return('U');
        case    0x008E /* 'A' */        : return('A');
        case    0x0099 /* 'O' */        : return('O');
	default				: return( c );
	}
}

/*	---------------------------------	*/
/*	a n d r o i d _ c h a r a c t e r	*/
/*	---------------------------------	*/
private	int	android_character( int c )
{
	switch ( c & 0x00FF )
	{
        case    0x0085 /* '<85>' */     : return('à');
        case    0x00A0 /* ' ' */        : return('a');
        case    0x0083 /* '<83>' */     : return('â');
        case    0x008A /* '<8a>' */     : return('è');
        case    0x0082 /* '<82>' */     : return('é');
        case    0x0088 /* '<88>' */     : return('ê');
        case    0x008D /* '<8d>' */     : return('i');
        case    0x00A1 /* '¡' */        : return('i');
        case    0x008C /* '<8c>' */     : return('î');
        case    0x0095 /* '<95>' */     : return('o');
        case    0x00A2 /* '¢' */        : return('o');
        case    0x0093 /* '<93>' */     : return('ô');
        case    0x0097 /* '<97>' */     : return('ù');
        case    0x00A3 /* '£' */        : return('u');
        case    0x0096 /* '<96>' */     : return('û');
        case    0x0087 /* '<87>' */     : return('ç');
        case    0x0081 /* '<81>' */     : return('ü');
        case    0x0084 /* '<84>' */     : return('ä');
        case    0x0094 /* '<94>' */     : return('ö');
        case    0x009A /* 'U' */        : return('Ü');
        case    0x008E /* 'A' */        : return('Ä');
        case    0x0099 /* 'O' */        : return('Ö');
	default				: return( c );
	}
}

/*	----------------------------------------	*/
/*	a n d r o i d _ s t r i n g _ v a l u e		*/
/*	----------------------------------------	*/
private	void	android_string_value(FILE * h, char * value )
{
	int	c;
	while ((c = *(value++)) != 0)
	{
		c &= 0x00FF;
		if ( c == 0X0027 )
			fprintf(h,"%c%c",'\\',c);
		else
		{
			c = unicode_android_character( c );
			if ( c & 0xFF00 )
				fprintf(h,"%c",((c & 0xFF00) >> 8));
			fprintf(h,"%c",(c & 0x00FF));
		}	
	}
	return;
}

/*	---------------------------	*/
/*	a n d r o i d _ s t r i n g	*/
/*	---------------------------	*/
private	void	android_string(FILE * h, char * prefix, char * name, char * extra, char * value )
{
	fprintf(h,"<string name=\"%s%s%s\">",prefix,name,extra);
	android_string_value(h,value);
	fprintf(h,"</string>\n");
	return;
}

/*	---------------------------------------------	*/
/*	 o p e n _ a n d r o i d _ r e s o u r c e s 	*/
/*	---------------------------------------------	*/
private	void	open_android_resources( FILE * h )
{
	android_xml_header(h);
	fprintf(h,"<resources>\n");
	android_string(h,"","action","_settings","Settings");
	return;
}

/*	-----------------------------------------	*/
/*	a n d r o i d _ w i d g e t _ c o l o u r 	*/
/*	-----------------------------------------	*/
private	void	android_widget_colour( FILE * h, int c )
{
	int	r=0;
	int	g=0;
	int	b=0;
	if (!( AndroColourMap[ (c & 0x00FF) ] ))
	{
		get_rgb_values(c,&r,&g,&b);
		printf("color(rgb%u,%u,%u,%u)\r\n",c,r,g,b);
		fprintf(h,"<color name=\"rgb%u\">#%02.2x%02.2x%02.2x</color>\n",c&0x00FF,r&0x00FF,g&0x00FF,b&0x00FF);	
		AndroColourMap[ (c & 0x00FF) ] = 1;
	}
	return;
}

/*	-------------------------------------	*/
/*	a n d r o i d _ f o r m _ c o l o u r 	*/
/*	-------------------------------------	*/
private	void	android_form_colours( FILE * h, struct form_control * fptr)
{
	struct	form_control * ffptr;
	char *	fnptr;
	struct form_item * iptr;
	for ( 	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		switch ( (iptr->Contents.style & _FRAME_TYPE) )
		{
		case	_DATA_FRAME	:
			if ( is_file_Widget( iptr ) )
        	        	continue;
			else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
				continue;
			else if (( iptr->Contents.datatype != _WIDGET_OVERLAY )
			     &&  ( iptr->Contents.datatype != _WIDGET_MODULE  ))
				continue;
			else if (!( fnptr = abal_payload(iptr) ))
                       		break;
			else if (!( ffptr = locate_form_control( fnptr ) ))
                       		break;
			else
			{
				android_form_colours( h, ffptr );
				break;
			}
		default			:
			android_widget_colour( h, ((iptr->Contents.colour & 0x00FF00) >> 8) );
			android_widget_colour( h, (iptr->Contents.colour & 0x00FF) );
			break;
		}
	}
	return;
}


/*	-----------------------------------	*/
/*	a n d r o i d _ c o l o u r _ m a p 	*/
/*	-----------------------------------	*/
private	void	android_colour_map( FILE * h, struct form_control * fptr )
{
	printf("colourmap(%s)\r\n",fptr->identifier);
	memset(AndroColourMap,0,256);
	android_form_colours( h, fptr );
	return;
}

/*	---------------------------------------------	*/
/*	c l o s e _ a n d r o i d _ r e s o u r c e s 	*/
/*	---------------------------------------------	*/
private	void	close_android_resources( FILE * h )
{

	fprintf(h,"</resources>\n");
	fclose(h);
	return;
}

/*	---------------------------------------		*/
/*	a n d r o i d _ s w i t c h _ l a b e l 	*/
/*	---------------------------------------		*/
private	void	android_switch_label( FILE * h, struct form_control * fptr, struct form_item * iptr, int nl )
{
	char *	onptr=(char *) 0;
	char *	offptr=(char *) 0;
	char *	sptr;
	char *	rptr;
	char * 	tptr;

	if (!( sptr = allocate_string( android_nl_payload( iptr, nl ) ) ))
		return;
	else	rptr = sptr;	

	onptr = sptr;
	tptr = sptr;
	while ( *tptr != 0 )
	{
		if( *tptr == '|' )
		{
			*(tptr++) = 0;
			offptr = tptr;
			break;
		}
		else	tptr++;
	}

	android_string(h,fptr->identifier,iptr->Contents.name,"OnLabel",onptr);
	android_string(h,fptr->identifier,iptr->Contents.name,"OffLabel",(offptr?offptr:onptr));
	liberate( rptr );
	return;
}

/*	---------------------------------------		*/
/*	a n d r o i d _ s e l e c t _ l a b e l 	*/
/*	---------------------------------------		*/
private	void	android_select_label( FILE * h, struct form_control * fptr, struct form_item * iptr, int nl )
{
	char *	sptr;
	char *	rptr;
	char * 	tptr;
	if (!( sptr = allocate_string( android_nl_payload( iptr, nl ) ) ))
		return;
	else	rptr = sptr;	
	fprintf(h,"<string-array name=\"%s%s\">\n",fptr->identifier,iptr->Contents.name);
	while ( *sptr )
	{
		tptr = sptr;
		while ( *tptr != 0 )
		{
			if( *tptr == '|' )
			{
				*(tptr++) = 0;
				break;
			}
			else	tptr++;
		}
		fprintf(h,"<item>");
		android_string_value(h,sptr);
		fprintf(h,"</item>\n");
		sptr = tptr;
	}	
	fprintf(h,"</string-array>\n");
	liberate( rptr );
	return;
}

/*	-----------------------------------------	*/
/*	g e n e r a t e _ a n d r o i d _ m e n u 	*/
/*	-----------------------------------------	*/
private	void	generate_android_menu( FILE * h, char * domain, struct form_control * fptr, char * pathroot, int nl )
{
	FILE *	hh;
	char 	rootpath[2048];

	sprintf(rootpath,"%s/%s",pathroot,"res/menu");

	if (!( hh = create_android_file( h, domain ,fptr, rootpath, "options_menu","xml" ) ))
		return;

	android_xml_header(hh);
	fprintf(hh,"<menu\n\txmlns:android=\"http://schemas.android.com/apk/res/android\"\n");
	fprintf(hh,"\txmlns:myapp=\"http://schemas.android.com/apk/res-auto\">\n");
	fprintf(hh,"<item\n\tandroid:id=\"@+id/actionBarSearch\"\n");
	fprintf(hh,"\tandroid:title=\"@string/search%s\"\n",fptr->identifier);
	fprintf(hh,"\tandroid:icon=\"@drawable/ic_search\"\n");
	fprintf(hh,"\tmyapp:showAsAction=\"collapseActionView|ifRoom\"\n");
	fprintf(hh,"\tmyapp:actionViewClass=\"android.widget.SearchView\" />\n");
	fprintf(hh,"</menu>\n");
	fclose(hh);

	sprintf(rootpath,"%s/%s",pathroot,"res/xml");

	if (!( hh = create_android_file( h, domain ,fptr, rootpath, "searchable","xml" ) ))
		return;

	android_xml_header(hh);
	fprintf(hh,"<searchable xmlns:android=\"http://schemas.android.com/apk/res/android\"\n");
        fprintf(hh,"\tandroid:label=\"@string/%sAppName\"/>\n",fptr->identifier);
	fclose(hh);
	return;

}

/*	------------------------------------------------	*/
/*	 g e n e r a t e_ a n d r o i d _ s t r i n g s		*/
/*	------------------------------------------------	*/
private	int	generate_android_strings( FILE * h, struct form_control * fptr, int nl)
{
	struct	form_item * iptr;
	char *	fnptr;
	char *	pptr;
	struct form_control * ffptr;
	char *	title;
	if (!( unique_android_activity( fptr->identifier )))
		return(1);
	if (!( title = android_window_title( fptr )))
		title = fptr->identifier;
	android_string(h,fptr->identifier,"App","Name",title);
	for ( 	iptr = fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		switch ( android_widget_label( iptr ) )
		{
		case	1	:
			android_string(h,fptr->identifier,iptr->Contents.name,"Label",android_nl_payload(iptr,nl));
			break;
		case	2	:
			android_switch_label( h, fptr, iptr,nl );
			break;
		case	3	:	/* 2 or more */
			android_select_label( h, fptr, iptr,nl );
		}
		switch ( iptr->Contents.style & _FRAME_TYPE )
		{
		case	_EDIT_FRAME	:
			if ( method_is_valid( ( pptr = android_nl_payload( iptr,nl ) ) )  != 0 )
				android_string(h,fptr->identifier,iptr->Contents.name,"Hint",pptr);
			break;
		case	_BUTTON_FRAME	:
			switch ( iptr->Contents.datatype )
			{
			case	_WIDGET_CHAIN	:
			case	_WIDGET_LOADGO	:
			case	_WIDGET_MODULE 	:
			case	_WIDGET_OVERLAY	:
				if (!( fnptr = abal_payload(iptr) ))
                        		break;
				else if (!( ffptr = locate_form_control( fnptr ) ))
                        		break;
				else	android_string(h,fptr->identifier,iptr->Contents.name,"Target",fnptr);
				break;
			}
			break;
		}
	}
	return(1);
}

/*	-------------------------------------	*/
/*	c r e a t e _ a n d r o i d _ f i l e 	*/
/*	-------------------------------------	*/
private	FILE *	create_android_file( FILE * h, char * domain, struct form_control * fptr, char* path, char * name, char * suffix )
{
	char 	buffer[2048];
	
	sprintf(buffer,"%s/%s.%s",path,name,suffix);
	android_check_directory( path );
	fprintf(h,"\t,{\"androidfile\": \"%s\"}\n",buffer);
	return( fopen( buffer, "w" ) );
}

/*	-----------------------------------------------		*/
/*	g e n e r a t e _ a n d r o i d _ l a y o u t s 	*/
/*	-----------------------------------------------		*/
private	void	generate_android_layouts( FILE * h, char * domain, struct form_control * fptr, char * pathroot )
{
	char 	rootpath[2048];
	sprintf(rootpath,"%s/%s",pathroot,"res/layout");
	release_android_activities();
	android_forms_layouts( h, domain, fptr,pathroot, rootpath );
	return;
}

/*	-----------------------------------------	*/
/*	a n d r o i d _ f o r m s _ l a y o u t s 	*/
/*	-----------------------------------------	*/
private	void	android_forms_layouts( FILE * h, char * domain, struct form_control * fptr, char * pathroot, char * rootpath )
{
	FILE * hh;
	struct	form_item * iptr;
	struct	form_control * ffptr;
	char *	fnptr;
	int	layout;
	/* ------------------------ */
	/* generate the main layout */
	/* ------------------------ */
	if (!( unique_android_activity( fptr->identifier ) ))
		return;
	else if (!( hh = create_android_file( h, domain ,fptr,rootpath, fptr->identifier,"xml" ) ))
		return;
	else if (!( generate_android_layout( hh, fptr, domain ) ))
		return;
	else if (!( generate_table_layouts( h, fptr, domain, rootpath ) ))
		return;
	else
	{
		/* --------------------------------- */
		/* for all visual overlay components */
		/* --------------------------------- */
		for ( 	iptr = fptr->first;
			iptr != (struct form_item *) 0;
			iptr = iptr->next )
		{
			switch ((iptr->Contents.style & _FRAME_TYPE))
			{
			case	_BUTTON_FRAME	:
				if ((  iptr->Contents.datatype != _WIDGET_CHAIN	)
				&&  (  iptr->Contents.datatype != _WIDGET_LOADGO)) 
					continue;
				else if (!( method_is_valid( fnptr = iptr->Contents.format ) ))
					continue;
				else if (!( strncmp( fnptr, "android:", strlen("android:")) ))
					continue;
				else if (!( ffptr = locate_form_control( fnptr ) ))
					continue;
				else
				{
					android_forms_layouts( h, domain, ffptr, pathroot , rootpath );
					continue;
				}

			case	_DATA_FRAME	:
				if ( is_file_Widget( iptr ) )
        	               		continue;
				else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
					continue;
				else if (( iptr->Contents.datatype != _WIDGET_OVERLAY )
				     &&  ( iptr->Contents.datatype != _WIDGET_MODULE  ))
					continue;
				else if (!( fnptr = abal_payload(iptr) ))
                        		continue;
				else if (!( strncmp( fnptr, "android:", strlen("android:")) ))
					continue;
				else if (!( ffptr = locate_form_control( fnptr ) ))
					continue;
				{
					android_forms_layouts( h, domain, ffptr, pathroot , rootpath );
					continue;
				}
			}
		}
		return;
	}
}

/*	-----------------------------------------------		*/
/*	n a t i o n a l _ a n d r o i d _ s t r i n g s		*/
/*	-----------------------------------------------		*/
private	int	national_android_strings( FILE * h, struct form_control * fptr, int nl )
{
	int	result;
	if ( fptr->formflags & _INTERNATIONAL ) { store_payloads(fptr); }
	result = generate_android_strings( h, fptr, nl );
	if ( fptr->formflags & _INTERNATIONAL ) { reload_payloads(fptr); }
	return( result );
}

/*	---------------------------------------------		*/
/*	g e n e r a t e _ a n d r o i d _ v a l u e s 		*/
/*	---------------------------------------------		*/
private	void	generate_android_values( FILE * h, char * domain, struct form_control * fptr, char * pathroot, int nl )
{
	FILE * hh;	
	struct	form_item * iptr;
	struct	form_control * ffptr;
	char *	fnptr;
	char 	rootpath[2048];

	/* ------------------------------------------------ */
	/* generate the menu search view in case its needed */
	/* ------------------------------------------------ */
	generate_android_menu( h, domain, fptr, pathroot, nl );

	switch ( nl )
	{
	case	1	:
		sprintf(rootpath,"%s/%s",pathroot,"res/values-fr");
		break;
	case	2	:
		sprintf(rootpath,"%s/%s",pathroot,"res/values-de");
		break;
	default		:
		sprintf(rootpath,"%s/%s",pathroot,"res/values");
		break;
	}
	
	if (!( hh = create_android_file( h, domain ,fptr, rootpath, "strings","xml" ) ))
		return;
	open_android_resources( hh );
	android_string(hh,"search",fptr->identifier,"","Search");
	android_colour_map( hh, fptr );
	generate_android_strings( hh, fptr, nl );
	/* --------------------------------- */
	/* for all visual overlay components */
	/* --------------------------------- */
	for ( 	iptr = fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		switch ((iptr->Contents.style & _FRAME_TYPE))
		{
		case	_BUTTON_FRAME	:
			if ((  iptr->Contents.datatype != _WIDGET_CHAIN	)
			&&  (  iptr->Contents.datatype != _WIDGET_LOADGO)) 
				continue;
			else if (!( method_is_valid( fnptr = iptr->Contents.format ) ))
				continue;
			else if (!( strncmp( fnptr, "android:", strlen("android:")) ))
				continue;
			else if (!( ffptr = locate_form_control( fnptr ) ))
				continue;
			else if (!( national_android_strings( hh, ffptr, nl ) ))
				continue;
			else	continue;
		case	_DATA_FRAME	:
			if ( is_file_Widget( iptr ) )
                       		continue;
			else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
				continue;
			else if (( iptr->Contents.datatype != _WIDGET_OVERLAY )
			     &&  ( iptr->Contents.datatype != _WIDGET_MODULE  ))
				continue;
			else if (!( fnptr = abal_payload(iptr) ))
                       		continue;
			else if (!( ffptr = locate_form_control( fnptr ) ))
				continue;
			else if (!( national_android_strings( hh, ffptr, nl ) ))
				continue;
			else	continue;
		}
	}
	close_android_resources( hh );
	return;
}

/*	---------------------------------------------		*/
/*	g e n e r a t e _ a n d r o i d _ t a b l e s 		*/
/*	---------------------------------------------		*/
private	void	generate_android_tables( FILE * h, char * domain, struct form_control * fptr, char * pathroot )
{
	FILE * hh;	
	struct	form_item * iptr;
	struct	form_control * ffptr;
	char *	fnptr;
	if (!( generate_android_database( h, domain, fptr, pathroot, fptr->identifier ) ))
		return;
	else
	{
		/* ------------------------------------------- */
		/* watch out for database tables in extensions */
		/* ------------------------------------------- */
		if ( method_is_valid( fptr->extends ) )
		{
			if (!( ffptr = locate_form_control( fptr->extends ) ))
				return;
			else if (!( generate_android_database( h, domain, ffptr, pathroot, fptr->identifier ) ))
				return;
		}

		/* --------------------------------- */
		/* for all visual overlay components */
		/* --------------------------------- */
		for ( 	iptr = fptr->first;
			iptr != (struct form_item *) 0;
			iptr = iptr->next )
		{
			switch ((iptr->Contents.style & _FRAME_TYPE))
			{
			case	_DATA_FRAME	:
				if ( is_file_Widget( iptr ) )
        	               		continue;
				else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
					continue;
				else if (( iptr->Contents.datatype != _WIDGET_OVERLAY )
				     &&  ( iptr->Contents.datatype != _WIDGET_MODULE  ))
					continue;
				else if (!( fnptr = abal_payload(iptr) ))
                        		continue;
				else if (!( ffptr = locate_form_control( fnptr ) ))
					continue;
				else if (!( generate_android_database( h, domain, ffptr, pathroot, fptr->identifier ) ))
					continue;
				else	continue;
			}
		}
		return;
	}
}

/* 	-----------------------------------------------		*/
/*	g e n e r a t e _ a n d r o i d _ l i c e n s e 	*/
/* 	-----------------------------------------------		*/
private	int	generate_android_license( FILE * h, char * domain )
{
	FILE * hh;
	int	c;

        if ((hh = fopen( "license.txt", "r")) != (FILE *) 0)
        {
                while ((c = fgetc(hh)) != -1)
                        fputc(c,h);
                fclose(hh);
        }
	return(1);

}

/*	-----------------------------------------------		*/
/*	g e n e r a t e _ a n d r o i d _ c l a s s e s 	*/
/*	-----------------------------------------------		*/
private	void	generate_android_classes( FILE * h, char * domain, struct form_control * fptr,char* pathroot )
{
	FILE * hh;	
	struct	form_item * iptr;
	struct	form_control * ffptr;
	char *	fnptr;
	char 	rootpath[2048];
	int	i;

	sprintf(rootpath,"%s/%s",pathroot,"java");
	strcat(rootpath,"/");	
	strcat(rootpath,domain);	
	strcat(rootpath,"/");	
	strcat(rootpath,fptr->identifier);	
	for ( i = 0; rootpath[i]!= 0; i++ )
		if ( rootpath[i] == '.' )
			rootpath[i] = '/';

	if (!( hh = create_android_file( h, domain ,fptr, rootpath,fptr->identifier,"java" ) ))
		return;
	else if (!( generate_android_license( hh, domain ) ))
		return;
	else if (!( generate_android_class( hh, domain,fptr, fptr->identifier,1 ) ))
		return;
	else	
	{
		/* ------------------------------------- */
		/* handle case of base class inheritance */
		/* ------------------------------------- */
		if (!( AndroidOption.inherit ))
		{
			if ( method_is_valid( fptr->extends ) != 0 )
			{
				if (!( ffptr = locate_form_control( fptr->extends ) ))
					return;
				else if (!( hh = create_android_file(h,domain,ffptr,rootpath,ffptr->identifier,"java" ) ))
					return;
				else if (!( generate_android_license( hh, domain ) ))
					return;
				else if (!( generate_android_class( hh, domain,ffptr, fptr->identifier,2 ) ))
					return;
			}
		}

		/* --------------------------------- */
		/* for all visual overlay components */
		/* --------------------------------- */
		for ( 	iptr = fptr->first;
			iptr != (struct form_item *) 0;
			iptr = iptr->next )
		{
			switch ((iptr->Contents.style & _FRAME_TYPE))
			{
			case	_BUTTON_FRAME	:
				if ((  iptr->Contents.datatype != _WIDGET_CHAIN	)
				&&  (  iptr->Contents.datatype != _WIDGET_LOADGO)) 
					continue;
				else if (!( method_is_valid( fnptr = iptr->Contents.format ) ))
					continue;
				else if (!( strncmp( fnptr, "android:", strlen("android:")) ))
					continue;
				else if (!( ffptr = locate_form_control( fnptr ) ))
					continue;
				else if (!( hh = create_android_file(h,domain,ffptr,rootpath,ffptr->identifier,"java" ) ))
					continue;
				else if (!( generate_android_license( hh, domain ) ))
					return;
				else if (!( generate_android_class( hh, domain,ffptr, fptr->identifier,0 ) ))
					continue;
				else	continue;

			case	_DATA_FRAME	:
				if ( is_file_Widget( iptr ) )
        	               		continue;
				else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
					continue;
				else if (( iptr->Contents.datatype != _WIDGET_OVERLAY )
				     &&  ( iptr->Contents.datatype != _WIDGET_MODULE  ))
					continue;
				else if (!( fnptr = abal_payload(iptr) ))
                        		continue;
				else if (!( ffptr = locate_form_control( fnptr ) ))
					continue;
				else if (!( hh = create_android_file(h,domain,ffptr,rootpath,ffptr->identifier,"java" ) ))
					continue;
				else if (!( generate_android_license( hh, domain ) ))
					return;
				else if (!( generate_android_class( hh, domain,ffptr, fptr->identifier,0 ) ))
					continue;
				else	continue;
			}
		}
		return;
	}
}

/*      ----------------------------------------------------------      */
/*                      e x p o r t _ android _ f o r m                 */
/*      ----------------------------------------------------------      */
/*      called from the top level production routines to generate       */
/*      a android app form.                                             */
/*      ----------------------------------------------------------      */
public  void    export_android_form( FILE * h, int webagent, char * soaphost, int restriction, int contextual, int autotrad, char * prodname )
{
        struct  form_control    * fptr;
	struct	forms_method 	* mptr;
	FILE * hh;
	char	pathroot[2048];
	char *	vptr;

	/* ------------------------------------------------------------ */
	/* This currently does nothing but has been integrated into the */
	/* SING code production suite for ulterior use.			*/
	/* ------------------------------------------------------------ */
        if (!( fptr = Context.Form ))
                return;
        else if (!( fptr->identifier ))
                return;
	/* --------------------------------- */
	/* should be program and not overlay */
	/* --------------------------------- */
        else if (!( fptr->isprogram ))
		return;
        else if ( fptr->isoverlay )
		return;
	else
	{
		/* ------------------------------*/	
		/* detect the application version*/
		/* ------------------------------*/	
		if ((mptr = detect_forms_method( fptr, _JAVA_VISUAL)) != (struct forms_method *) 0)
			AndroidOption.visualStyle = 1;
		if ((mptr = detect_forms_method( fptr, _JAVA_API_KEY)) != (struct forms_method *) 0)
			AndroidOption.apiKey = allocate_string( (mptr->name + strlen( _JAVA_API_KEY)) );

		/* -------------------------------------------- */
		/* Layout can be SCROLLED or FIXED ( ABSOLUTE )	*/
		/* -------------------------------------------- */
		if ((mptr = detect_forms_method( fptr, _JAVA_SCROLL)) != (struct forms_method *) 0)
			AndroidOption.handle_layout = _SCROLL_LAYOUT;
		else if ((mptr = detect_forms_method( fptr, _JAVA_FIXED)) != (struct forms_method *) 0)
			AndroidOption.handle_layout = _ABSOLUTE_LAYOUT;
		else if ((mptr = detect_forms_method( fptr, _JAVA_LINEAR)) != (struct forms_method *) 0)
			AndroidOption.handle_layout = _LINEAR_LAYOUT;
		else if ((mptr = detect_forms_method( fptr, _JAVA_RELATIVE)) != (struct forms_method *) 0)
			AndroidOption.handle_layout = _RELATIVE_LAYOUT;
		else	AndroidOption.handle_layout = _ABSOLUTE_LAYOUT;

		if ((mptr = detect_forms_method( fptr, _JAVA_VERSION)) != (struct forms_method *) 0)
		{
			AndroidOption.versionCode = 0;
			AndroidOption.versionName = (mptr->name + strlen(_JAVA_VERSION));
			for ( 	vptr=AndroidOption.versionName;
				*vptr != 0;
				vptr++ )
			{
				if (( *vptr >= '0' ) && ( *vptr <= '9'))
				{
					AndroidOption.versionCode *= 16;
					AndroidOption.versionCode += (*vptr - '0');	
				}
				else if (( *vptr >= 'a' ) && ( *vptr <= 'f'))
				{
					AndroidOption.versionCode *= 16;
					AndroidOption.versionCode += (*vptr - 'a');	
					AndroidOption.versionCode += 10;
				}
				else if (( *vptr >= 'A' ) && ( *vptr <= 'F'))
				{
					AndroidOption.versionCode *= 16;
					AndroidOption.versionCode += (*vptr - 'A');	
					AndroidOption.versionCode += 10;
				}
			}
		}
		else
		{
			
			AndroidOption.versionCode = 16;
			AndroidOption.versionName = "v1.0";
		}

		/* ----------------------------- */	
		/* detect the application domain */
		/* ----------------------------- */	
		if ((mptr = detect_forms_method( fptr, _JAVA_DOMAIN )) != (struct forms_method *) 0)
			AndroidOption.domain = (mptr->name+ strlen( _JAVA_DOMAIN ));
		else	AndroidOption.domain = AMENESIK_DOMAIN;

		/* -------------------------------- */
		/* start the application production */
		/* -------------------------------- */
		reset_database_helper();
		printf("program: %u, overlay: %u\r\n",Abal_Config.generate_program,Abal_Config.generate_overlay);
		fprintf(h,"{ \"androidform\":");
		fprintf(h,"{ \"identifier\":\"%s\", \"domain\":\"%s\", \"files\": \n\t[\n",fptr->identifier,AndroidOption.domain);
		fprintf(h,"\t{\"androidfile\": \"%s\"}\n",fptr->prodname);
		sprintf(AndroidOption.master,"%s.%s",AndroidOption.domain,fptr->identifier );
	}

	/* ----------------------------------- */
	/* detect database encryption required */
	/* ----------------------------------- */
	if ((mptr = detect_forms_method( fptr, _JAVA_CIPHER )) != (struct forms_method *) 0)
		AndroidOption.sqlcipher = 1;
	else if ((mptr = detect_forms_method( fptr, _JAVA_SQLITE )) != (struct forms_method *) 0)
		AndroidOption.sqlcipher = 0;
	else if ((mptr = detect_forms_method( fptr, _SING_CIPHER )) != (struct forms_method *) 0)
		AndroidOption.sqlcipher = 2;
	else 	AndroidOption.sqlcipher = 0;

	sprintf(pathroot,"%s/src/main",fptr->identifier);

	if (!( hh = create_android_file( h, AndroidOption.domain ,fptr, pathroot, "AndroidManifest", "xml") ))
		return;
	else if (!( generate_android_manifest( hh, AndroidOption.domain, fptr ) ))
		return;
	else	
	{
		release_android_activities();
		generate_android_layouts( h, AndroidOption.domain, fptr,pathroot );
		release_android_activities();
		generate_android_values( h, AndroidOption.domain, fptr,pathroot,0 );
		release_android_activities();
		generate_android_values( h, AndroidOption.domain, fptr,pathroot,1 );
		release_android_activities();
		generate_android_tables( h, AndroidOption.domain, fptr,pathroot );
		generate_android_classes( h, AndroidOption.domain, fptr,pathroot );
		fprintf(h,"\t]}}\n");
		return;
	}
}


	/* ------------ */
#endif	/* _androform_c */
	/* ------------ */

