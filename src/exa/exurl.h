#ifndef	_EXURL_H
#define	_EXURL_H

struct	program_url	{
	char *	service;	/* service prefix 					   */
	int	port;		/* either determined by the service analysis or behind ':' */
	char *	host;		/* between "//" and "/" after service and before object	   */ 
	char *	program;	/* after the host or port over ride			   */
	char *	parameters;	/* beyond and including the '?'				   */
	char *	procedure;	/* beyond and including the '#'				   */
	};

#endif	/* _EXURL_H */
	/* -------- */


