#ifndef	_singfile_h
#define	_singfile_h

struct 	file_control {
	char	*	loadname;
	char	*	prodname;
	int		language;
	int		program;
	int		overlay;
	int		handle;
	char	*	identifier;
	char	*	filename;
	int		filetype;
	int		recordsize;
	int		indexsize;
	char	*	secondary;
	struct standard_image * image;
	int		doctool;
	char	*	document;
	long		savestamp;
	long		loadstamp;
	char	*	recordclass;
	struct standard_class * record;
	struct form_control *  dataform;
	char	*	indexclass;
	struct standard_class * index;
	struct form_control *  indexform;
	char	*	dependance;
	char	*	construction;
	int		isvariable;
	int		indexalign;
	struct	treeview * treenode;
	void		 * host;
	};

public	struct file_control * 	allocate_File(char * nptr);
public	struct file_control * 	liberate_File(struct file_control * fptr );
public	int 			edit_File(struct file_control ** ffptr,int mode);
public	struct file_control * 	load_File(char * nptr,int mode);
public	void	save_File(struct file_control * fptr, int mode );
public	void	export_File(struct file_control * fptr,int mode);
public	int	document_File( FILE * h,struct file_control * fptr,int automatic, int report );

#endif  /* _singfile_h */
	/* ----------- */


