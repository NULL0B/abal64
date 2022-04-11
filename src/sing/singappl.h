#ifndef	_singappl_h
#define	_singappl_h

struct	application_parameters {
	int	validate;
	int	quality;
	int	visible;
	int	build;
	int	productiontype;
	int	language;
	int	isdocument;
	int	makefile;
	int	imagetype;
	char *	target;
	char *	document;
	char *	makename;
	char *	databasename;
	char *	palettename;
	char *	template;
	char *	modules;
	char * formulaires;	/* source directory for original xml resources 	*/
	char * src_product;	/* temporary directory for source production	*/
	char * obj_product;	/* temporary directory for binary production	*/
	char * components;	/* list of component projects requiring loading	*/
	struct file_manager * database;
	char * stylesheet;
	};


#endif	/* _singappl_h */
	/* ----------- */

