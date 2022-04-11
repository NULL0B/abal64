#include <stdio.h>

#define	private	static
#define	public

#define	allocate(a) malloc(a)
#define	liberate(a) free(a)

void *	allocate(int);
void *	liberate(void *);
int	verbose=0;
int	optimise=0;


static	char	tname[256];
static	char	sname[256];

#define	MAX_FONTS 256

struct	standard_cell	{
	int	width;		/* image width  */
	int	height;		/* image height */
	char	matrix[1];	/* image data   */
	};

struct	standard_font	{
	int			width;		/* overall width	  */
	int			height;		/* overall height	  */
	int			margin;		/* cell margin value	  */
	int			flags;		/* font options		  */
	char	*		buffer;		/* original file buffer	  */
	int			buffersize;	/* size of original buffer*/ 
	struct	standard_cell *	cell[256];	/* one for each character */
	};

struct	gigo_manager	{
	int	cursorstyle;		/* text cursor form BLOCK/LINE etc	*/
	int	foreground;		/* foreground , character colour code	*/
	int	background;		/* background	colour code		*/
	int	washground;		/* background	colour code		*/
	int	fg;			/* foreground , character colour copy	*/
	int	bg;			/* background	colour copy		*/
	int	atribut;		/* atribut bit mask			*/
	int	scrolling;		/* scrolling or paging			*/
	int	column;			/* current curser column position	*/
	int	line;			/* current curser line position		*/
	int	columns;		/* total number of columns for basefont */
	int	lines;			/* number of lines for base font	*/

	int	width;			/* Pixel Graphic Width			*/
	int	height;			/* Pixel Graphic Height in Rows		*/
	int	line_spacing;		/*	*/
	int	letter_spacing;		/*	*/
	int	tracing;		/* trace mechanism activation		*/
	int	cursing;		/* Text Cursor State			*/
	int	escapestate;		/* escape mechanism state		*/
	int	escapecharacter;	/* escaped character code		*/
	int	escapeparameter;	/* the first parameter			*/
	int	escapetransfer;		/* esc T transfer count			*/
	int	currentfont;		/* current base font id			*/
	int	workingfont;		/* current base font id			*/
	int	xmargin;		/* current base font id			*/
	int	ymargin;		/* current base font id			*/
	int	xfontwidth;		/* current base font id			*/
	int	yfontheight;		/* current base font id			*/
	int	fontwidth;		/* the base font overall width		*/
	int	fontheight;		/* and height for quick positioning	*/
	unsigned char painter[32];	/* Specialised paint colours		*/

	/* margin indentation values */ 
	int	topmargin;
	int	rightmargin;
	int	bottommargin;
	int	leftmargin;
	int	C_FORE;
	int	C_BACK;
	char 				  * fontnames[MAX_FONTS];	/* The fonts	*/
	struct  standard_font * graphicfonts[MAX_FONTS];	/* The fonts	*/

	} Gigo;

char *	sysfilename( char * nptr )
{
	return( nptr );
}

#include "stdfont.c"

#include "fontrite.c"

int	convert_font_file(int number, char * nptr  )
{
	struct standard_cell * cptr;
	struct standard_font * fptr;
	int	status;
	int	i;
	FILE * h;
	if ( verbose )
		printf("convert font file : %s \n",nptr);
	sprintf(sname,"%s",nptr);
	if (!(h = fopen(sname,"rb"))) {
		sprintf(sname,"%s.FON",nptr);
		if (!(h = fopen(sname,"rb"))) {
			sprintf(sname,"%s.fon",nptr);
			if (!(h = fopen(sname,"rb")))
				return(40);
			else	fclose(h);
			}
		else	fclose(h);
		}
	else	fclose(h);

	sprintf(tname,"%s.fmf",nptr);

	if ((status = load_font( number, sname )) != 0)
		return( status );
	else if (!( fptr = Gigo.graphicfonts[number] ))
		return(30);
	else if ((status = write_standard_font( nptr, fptr )) != 0)
		return( status );
	else	return( 0 );
}


int	setoption(char * aptr)
{
	if (( *aptr == 'v' )
	||  ( *aptr == 'V' ))
		verbose=1;
	else if (( *aptr == 'o' )
	     ||  ( *aptr == 'O' ))
		optimise=1;
	return(0);
}

int	main(int argc,char * argv[])
{
	int	argi;
	char * aptr;
	int	status;
	int	fid=0;
	if ( argc == 1 ) {
		printf("\n   Font File Convertor FON to FMF : Version 1.0a.0.01 ");
		printf("\n   Provisoire du 24/01/2004 ");
		printf("\n   Copyright (c) 2004,2006 Amenesik / Sologic \n\n");
		return(0);
		}
	else	{
		for (argi=1; argi < argc; argi++ ) {
			if (!( aptr = argv[argi] ))
				break;
			else if ( *aptr == '-' ) 
				setoption(aptr+1);
			else if ((status = convert_font_file(++fid, aptr )) != 0)
				break;
			}
		return( status );
		}
}




