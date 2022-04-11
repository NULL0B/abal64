#ifndef	_vsvg_c
#define	_vsvg_c

#include "exmpegs.h"

char	SvgWorkBuffer[8192];

FILE * 	SvgHandle=(FILE*)0;
int	SvgSocket=-1;

int	svg_flush()
{
	if ( SvgSocket != -1 )
		puts_mpeg_client( SvgSocket, SvgWorkBuffer );
	if ( SvgHandle )
		fprintf(SvgHandle,"%s",SvgWorkBuffer);
	return(0);
}

void	svg_colour( char * bptr, int x )
{
	int	r=0;
	int	g=0;
	int	b=0;
	get_rgb_values(x & 0x00FF,&r,&g,&b);	
	sprintf(bptr,"rgb(%u,%u,%u)",r,g,b);
	return;

}
public	int	svg_fill_item( int x, int y, int w , int h, int colour )
{
	char	buffer[256];
	svg_colour(buffer, colour);
	sprintf(SvgWorkBuffer,"<g><rect x=%c%u%c y=%c%u%c width=%c%u%c height=%c%u%c fill=%c%s%c/></g>\n",
		0x0022,x,0x0022,
		0x0022,y,0x0022,
		0x0022,w,0x0022,
		0x0022,h,0x0022,
		0x0022,buffer,0x0022);
	return(svg_flush());
}

public	int	svg_xfill_item( int x, int y, int w , int h, int colour )
{
	char	buffer[256];
	svg_colour(buffer, colour);
	sprintf(SvgWorkBuffer,"<g><rect x=%c%u%c y=%c%u%c width=%c%u%c height=%c%u%c fill=%c%s%c/></g>\n",
		0x0022,x,0x0022,
		0x0022,y,0x0022,
		0x0022,w,0x0022,
		0x0022,h,0x0022,
		0x0022,buffer,0x0022);
	return(svg_flush());
}

public	int	svg_circle_item( int x, int y, int w , int h, int colour, int length )
{
	char	buffer[256];
	svg_colour(buffer, colour);
	sprintf(SvgWorkBuffer,"<g><circle cx=%c%u%c cy=%c%u%c r=%c%u%c fill=%c%s%c stroke=%c%s%c/></g>\n",
		0x0022,x+(w/2),0x0022,
		0x0022,y+(h/2),0x0022,
		0x0022,(w < h ? w/2 : h/2),0x0022,
		0x0022,buffer,0x0022,
		0x0022,buffer,0x0022);
	return(svg_flush());
}

public	int	svg_roundfill_item( int x, int y, int w , int h, int colour )
{
	char	buffer[256];
	svg_colour(buffer, colour);
	sprintf(SvgWorkBuffer,"<g><rect x=%c%u%c y=%c%u%c width=%c%u%c height=%c%u%c fill=%c%s%c/></g>\n",
		0x0022,x,0x0022,
		0x0022,y,0x0022,
		0x0022,w,0x0022,
		0x0022,h,0x0022,
		0x0022,buffer,0x0022);
	return(svg_flush());
}

public	int	svg_roundframe_item( int x, int y, int w , int h, int colour)
{
	char	buffer[256];
	svg_colour(buffer, colour);
	sprintf(SvgWorkBuffer,"<g><rect x=%c%u%c y=%c%u%c width=%c%u%c height=%c%u%c fill=%c%s%c/></g>\n",
		0x0022,x,0x0022,
		0x0022,y,0x0022,
		0x0022,w,0x0022,
		0x0022,h,0x0022,
		0x0022,buffer,0x0022);
	return(svg_flush());
}

public	int	svg_line_item( int x, int y, int w , int h, int colour )
{
	return(svg_flush());
}

private	char	iri_buffer[2048];

private	char *	svg_iri( char * sptr )
{
	int	i;
	if ( *sptr == '/' )
		sprintf(iri_buffer,"%s%s","file://",sptr);
	else  if ( *sptr == '.' )
		sprintf(iri_buffer,"%s%s","file:///",sptr);
	else 
	{
		for ( i=0; *(sptr+i) != 0; i++ )
			if ( *(sptr+i) == ':' )
				break;
		if ( *(sptr+i) == ':' )
			sprintf(iri_buffer,"%s",sptr);
		else	sprintf(iri_buffer,"%s%s","file:///./",sptr);
	}
	return( iri_buffer );
}

int	svg_pattern_counter=0;

public	int	svg_image_item( int x, int y, int w , int h, void * vptr, int options)
{
	char	work[64];
	char * imagename;
	struct	standard_image * iptr;
	if (!( iptr = vptr ))
		return(0);
	else if (!( imagename = iptr->name ))
		return( 0 );
	else
	{
		switch ( options & 7 )
		{
		case	_A_NONE	:
			sprintf(SvgWorkBuffer,"<g><image x=%c%u%c y=%c%u%c width=%c%upx%c height=%c%upx%c xlink:href=%cfile://%s%c/></g>\n",
			0x0022,x,0x0022,
			0x0022,y,0x0022,
			0x0022,w,0x0022,
			0x0022,h,0x0022,
			0x0022,svg_iri(imagename),0x0022);
			return(svg_flush());
			break;
		case	_A_LEFT	:
			sprintf(SvgWorkBuffer,"<g><image preserveAspectRatio='xMinYMid slice' x=%c%u%c y=%c%u%c width=%c%upx%c height=%c%upx%c xlink:href=%cfile://%s%c/></g>\n",
			0x0022,x,0x0022,
			0x0022,y,0x0022,
			0x0022,w,0x0022,
			0x0022,h,0x0022,
			0x0022,svg_iri(imagename),0x0022);
			return(svg_flush());
			break;
		case	_A_RIGHT :
			sprintf(SvgWorkBuffer,"<g><image preserveAspectRatio='xMaxYMid slice' x=%c%u%c y=%c%u%c width=%c%upx%c height=%c%upx%c xlink:href=%cfile://%s%c/></g>\n",
			0x0022,x,0x0022,
			0x0022,y,0x0022,
			0x0022,w,0x0022,
			0x0022,h,0x0022,
			0x0022,svg_iri(imagename),0x0022);
			return(svg_flush());
			break;
		case	_A_CENTER :
			sprintf(SvgWorkBuffer,"<g><image preserveAspectRatio='xMidYMid slice' x=%c%u%c y=%c%u%c width=%c%upx%c height=%c%upx%c xlink:href=%cfile://%s%c/></g>\n",
			0x0022,x,0x0022,
			0x0022,y,0x0022,
			0x0022,w,0x0022,
			0x0022,h,0x0022,
			0x0022,svg_iri(imagename),0x0022);
			return(svg_flush());
			break;
		case	_I_MAKEFIT :
		case 	_I_BESTFIT :
			sprintf(SvgWorkBuffer,"<g><image preserveAspectRatio='xMidYMid meet' x=%c%u%c y=%c%u%c width=%c%upx%c height=%c%upx%c xlink:href=%cfile://%s%c/></g>\n",
			0x0022,x,0x0022,
			0x0022,y,0x0022,
			0x0022,w,0x0022,
			0x0022,h,0x0022,
			0x0022,svg_iri(imagename),0x0022);
			return(svg_flush());
			break;

		case	_I_TILE :
			sprintf(work,"_p%u",++svg_pattern_counter);
			sprintf(SvgWorkBuffer,"<defs><pattern id=%c%s%c x=%c%u%c y=%c%u%c width=%c%u%c height=%c%u%c>\n", 
				0x0022,work,0x0022,
				0x0022,0,0x0022,
				0x0022,0,0x0022,
				0x0022,iptr->columns,0x0022,
				0x0022,iptr->rows,0x0022);
			(void)svg_flush();

			sprintf(SvgWorkBuffer,"<image x=%c%u%c y=%c%u%c width=%c%upx%c height=%c%upx%c xlink:href=%c%s%c/>\n",
				0x0022,0,0x0022,
				0x0022,0,0x0022,
				0x0022,iptr->columns,0x0022,
				0x0022,iptr->rows,0x0022,
				0x0022,svg_iri(imagename),0x0022);

			strcat(SvgWorkBuffer,"</pattern></defs>\n");
			(void)svg_flush();

			sprintf(SvgWorkBuffer,"<g><rect x=%c%u%c y=%c%u%c width=%c%upx%c height=%c%upx%c fill=%curl(#%s)%c/></g>\n",
				0x0022,x,0x0022,
				0x0022,y,0x0022,
				0x0022,w,0x0022,
				0x0022,h,0x0022,
				0x0022,work,0x0022);
			(void)svg_flush();
			break;
		
		}	
		return(0);
	}
}

static	int	svgfg=0;
static	int	svgbg=0;

public	int	svg_print_colour( int foregr, int backgr )
{
	svgfg = foregr; //& 0x00FF;
	svgbg = backgr; //& 0x00FF;
	return(0);
}

public	int	svg_text_item(  int x, int y, int font, char * buffer, int length, int w, int h, int value )
{
	char	work[256];
	int	fw = guifontsize(font);
	int	fh = ((fw & 0xFF00) >> 8);
	int	fheight;
	fw &= 0x00FF;
	svg_colour(work, svgfg );
	fheight = ((fh * 4) / 5);
 	sprintf(SvgWorkBuffer,"<g><text x=%c%u%c y=%c%u%c font-size=%c%u%c fill=%c%s%c>%s</text></g>\n",
		0x0022,x,0x0022,
		0x0022,y+((fh*5)/6),0x0022,
		0x0022,fheight,0x0022,
		0x0022,work,0x0022,buffer);
	return(svg_flush());
}

public	void	initialise_svg(char * SvgName)
{
	struct mpeg_url uptr;
	int	w;
	int	h;
	if ((!( SvgHandle )) && ( SvgSocket == -1 ))
	{
		if ( analyse_mpeg_url( &uptr, SvgName ) != 0 )
			return;
		else if (!( uptr.port ))
		{
			if (!( SvgHandle = fopen( SvgName, "w" ) ))
				return;
		}
		else if (( SvgSocket = open_mpeg_client( SvgName )) == -1)
			return;
		
		h = x_event(208);
		w = x_event(209);
		*XgraphPtr = overload_x_graph;
		set_overload_interface(1,svg_fill_item);
		set_overload_interface(2,svg_xfill_item);
		set_overload_interface(3,svg_circle_item);
		set_overload_interface(4,svg_roundfill_item);
		set_overload_interface(5,svg_roundframe_item);
		set_overload_interface(6,svg_line_item);
		set_overload_interface(7,svg_image_item);
		set_overload_interface(8,svg_print_colour);
		set_overload_interface(9,svg_text_item);
		overload.status = 7;
		sprintf(SvgWorkBuffer,"<?xml version=%c%s%c?>\n",
			0x0022,"1.0",0x0022);
		(void)svg_flush();
#ifdef	SVG12_ETC_ETC
		sprintf(SvgWorkBuffer,"<svg xmlns=%c%s%c xmlns:xlink=%c%s%c width=%c%u%c height=%c%u%c viewBox=%c%u %u %u %u%c version=%c%s%c baseProfile=%c%s%c>\n",
			0x0022,"http://www.w3.org/2000/svg",0x0022,
			0x0022,"http://www.w3.org/1999/xlink",0x0022,
			0x0022,w,0x0022,
			0x0022,h,0x0022,
			0x0022,0,0,w,h,0x0022,
			0x0022,"1.2",0x0022,
			0x0022,"tiny",0x0022);
		(void)svg_flush();
#else
		sprintf(SvgWorkBuffer,"<svg xmlns=%c%s%c\n\txmlns:xlink=%c%s%c\n\twidth=%c%upx%c height=%c%upx%c\n\tversion=%c%s%c>\n",
			0x0022,"http://www.w3.org/2000/svg",0x0022,
			0x0022,"http://www.w3.org/1999/xlink",0x0022,
			0x0022,w,0x0022,
			0x0022,h,0x0022,
			0x0022,"1.1",0x0022);
		(void)svg_flush();

#endif
	}
	return;
}

public	void	terminate_svg(char * SvgName)
{
	if ( SvgHandle )
	{
		sprintf(SvgWorkBuffer,"</svg>\n");
		(void)svg_flush();
		if ( SvgHandle )
		{
			fclose( SvgHandle );
			SvgHandle = (FILE *) 0;
		}
		if ( SvgSocket != -1 )
		{
			SvgSocket = close_mpeg_client( SvgSocket );
		}
		overload.status = 0;
		*XgraphPtr = XgraphRelay;
	}
	return;
}



	/* ------- */
#endif 	/* _vsvg_c */
	/* ------- */

