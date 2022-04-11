#ifndef	_excallback_h
#define	_excallback_h

/*	----------------------------------------------		*/
/*	Abal VM CallBack Interface Parameter Structure 		*/
/*	----------------------------------------------		*/

struct	callback_parameter	{
	struct callback_parameter * next;	/* next parameter in list	*/
	int	type;				/* parameter type : 1,2,3	*/
	int	ivalue;				/* type 1 integer value		*/
	int	length;				/* type 2,3 string length	*/
	char *	svalue;				/* type 2,3 string value	*/
	};

/*	-----------------------------------------------		*/
/*	Abal VM CallBack Interface Procedure Invocation 	*/
/*	-----------------------------------------------		*/

struct	callback_context	{
	int	procedure;			/* number of bound procedure 	*/
	void *	pthread;			/* parent thread context	*/
	int	parameters;			/* parameter count		*/
	struct callback_parameter * first;	/* first parameter		*/
	struct callback_parameter * last;	/* last parameter		*/
	};

/*	----------------------------------------------		*/
/*	Abal VM CallBack Interface DescriptorStructure 		*/
/*	----------------------------------------------		*/

struct	exa_callback	{
	int	value;				/* value received 		*/
	void *	buffer;				/* buffer received		*/
	struct callback_context descriptor;	/* operation descriptor		*/
	};


/*	---------------------------------------------		*/
/*	Abal VM CallBack Interface Function Constants  		*/
/*	---------------------------------------------		*/

#define	EXA_CALLBACK_RESOLVE	0		/* Resolve / Bind to Procedure	*/
#define	EXA_CALLBACK_INVOKE 	1		/* Invoke Exported Procedure	*/
#define	EXA_CALLBACK_INTEGER	2		/* Set Integer Parameter Value	*/
#define	EXA_CALLBACK_NUMERIC	3		/* Set BCD Parameter		*/
#define	EXA_CALLBACK_STRING	4		/* Set String Parameter Value	*/

/*		----------------------------			*/
/*		Interface Function Prototype 			*/
/*		----------------------------			*/

int	x_callback(int f, struct exa_callback * xptr);

#endif  /* _excallback_h */
	/* ------------- */

