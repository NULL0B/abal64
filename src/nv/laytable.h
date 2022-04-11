//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_layout_table_h
#define _html_layout_table_h

class	html_layout_table	{

public:
	html_layout_table	*	host;	// Previous Table
	html_layout_table	*	child;	// Nested Table
	html_layout_table	*	next;	// For Quick Allocation 

	html_table_descriptor	*	table;
	html_row_descriptor	*	row;
	html_cell_descriptor	*	cell;
	html_layout_line	*	rowstart;
	html_layout_line	*	tablestart;

	int 				table_image_line;
	html_logical_image	*	table_image;
	html_logical_image	*	row_image;
	html_logical_image	*	cell_image;

	html_logical_image *		background_image();

	int	precellalign;		// Holds Alignment for Cells
	int	prerowalign;		// Holds Alignment for Rows
	int	holdalign;		// Holds Alignment for Table
	int	line_wrap;		// Allow Line Wraping In Cells
	int	left_margin;		// Left Margin Limit from Parent
	int	right_margin;		// Right Margin Limit from Parent
	int	hold_left;		// Previous Left Margin
	int	hold_right;		// Previous Right MArgin / Width
	int  *	cellcontrol;		// Cell Sizes
	int  *	cellmin;		// Cell Minimum Sizes
	int  *	cellfix;		// Cell Explicite Sized
	int  *	cellmax;		// Cell Maximum Sizes
	int  *	cellper;		// Cell Maximum Sizes
	int  *	cellbkg;		// Cell BackGrounds  
	int  *  cellrows;		// Cell RowSpan Control
	int  *  cellused;		// Cell Lines used by actual TD layout
	int  *  cellspan;		// ColSpan for  RowSpan Control
	int  *  cellback;		// BackGround Colour for Cells
	int  *  cellbord;		// BackGround Colour for Cells
	int  *  rowlines;		// Line Reached by cells of row
	int  *  cellgo;			// Layout Line of Start of Cell
	long *	cellimage;		// Current image background of cell
	int	cellindent;		// This value indicate the ROW span Factor
	int	cellcounter;		// Current Working Cell Identity
	int	cellborder;		// Add Cell Border Items
	int	maxrowlimit;		// Maximum Line Number on This Row
	int	tablecolour;		// Back Ground Colour
					// Will be used by Next Row Mechanism
	int	tableborder;		// Default Table Border Style
					// Will be used by Next Row Mechanism
	int	rowlimit;		// Working Maximum Line Number on This Row
					// Will be used by Next Row Mechanism
	int	tablelimit;		// Maximum Line Numbers in this table
					// Will be used by end of Table Mechanism
	int	rowcounter;		// Used to Control Initial Line Feed

	int	framecounter;		// Used for frame display


	html_layout_table(
		html_table_descriptor	* dptr, 
		int plm, int prm, int bfw, int bfh, int xha );
	void	oninit(
		html_table_descriptor	* dptr, 
		int plm, int prm, int bfw, int bfh, int xha );

	void	release();
	int	cell_width_detection( html_dimensions * cptr,int i, int tw, int ts );
	int	cellstart();
	int	cellwidth();

	int	getcellcolour();
	int	getcellborder();

	void	opencell( html_cell_descriptor * dptr );
	void	closecell();

	void	firstrow();
	void	nextrow();

	void	openrow( html_row_descriptor * rptr, int rid );
	void	closerow();

	int 	firstframe();
	int	nextframe();
	int	framestart();
	int	framespan(int option);

	int	framecheck( int identity, int option );

	};

#endif	// _html_layout_table_h





