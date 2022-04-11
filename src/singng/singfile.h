#ifndef	_singfile_h
#define	_singfile_h

#include "abaldata.h"
#include "valign.h"


struct	link_control	{
	struct	link_control	* previous;
	struct	link_control	* next;
	char			* source;
	char			* target;
	char			* name;
	char			* jointure;
	int			  nature;
	};

struct	file_control	{
	struct	file_control 	* previous;
	struct	file_control 	* next;
	char			* identity;
	char			* filename;
	char			* format;
	char			* classname;
	char			* indextype;
	char			* recordtype;
	struct	data_control	* payload;
	int			  nature;
	int			  number;
	int			  members;
	int			  doctool;
	int			  x;
	int			  y;
	int			  state;
	char *			  document[MAXNATLANG];
	};

struct	file_manager	{
	struct	file_control	*	first;
	struct	file_control	*	current;
	struct	file_control	*	last;
	struct	link_control	*	firstlink;
	struct	link_control	*	lastlink;
	struct	file_manager	*	previous;
	struct	file_manager	*	next;
	char			*	name;
	int				usage;
	};

struct	database_manager	{
	struct	file_manager	*	first;
	struct	file_manager	*	current;
	struct	file_manager	*	last;
	struct	file_control	*	CopyFile;
	};

#ifdef	_vfile_c
#ifdef __cplusplus
extern "C" {
#endif
struct	file_manager xFileManager = {
		(struct file_control *) 0,
		(struct file_control *) 0,
		(struct file_control *) 0,
		(struct	link_control *) 0,
		(struct	link_control *) 0,
	 	(struct file_manager *) 0,
	 	(struct file_manager *) 0,
		(char *) 0, 0
		};

struct	file_manager * FileManager = &xFileManager;

struct	database_manager BaseManager = {
		(struct file_manager *) 0,
		(struct file_manager *) 0,
		(struct file_manager *) 0,
		(struct file_control *) 0
		};
#ifdef __cplusplus
}
#endif
#else
#ifdef __cplusplus	/* GWB le 18/09/2007 */
extern "C" {
#endif
extern	struct	file_manager * FileManager;
extern	struct	database_manager BaseManager;
#ifdef __cplusplus
}
#endif
#endif


#endif	/* _singfile_h */


