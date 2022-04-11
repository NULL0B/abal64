#ifndef	_jsptype_h
#define	_jsptype_h

#define	_BOOLEAN	0
#define	_NUMBER		1
#define	_STRING 	2
#define	_ARRAY		3
#define	_OBJECT		4

#define	_VARIABLE	5
#define	_FUNCTION	6

#define	_equal			0
#define	_not_equal		1
#define	_less_than		2
#define	_greater_than		3
#define	_less_or_equal		4
#define	_greater_or_equal	5


#define	_JSP_HASH_VALUE	57

struct operand {
	int		type;
	long		value;
	void	*	pointer;
	struct operand *	linkage;
	};

struct	variable {
	char * 	name;
	int	hash;
	struct operand  * value;
	struct variable * previous;
	struct variable * next;
	};

struct	function {
	char * 	name;
	int	hash;
	struct variable * first;
	struct variable * last;
	struct variable * variables;
	struct function * caller;
	struct function * previous;
	struct function * next;
	};

char *			allocate_string( char * );
struct function * 	locate_function( char * );
struct variable * 	locate_variable( char * );
struct operand  * 	make_integer(long);
struct operand  * 	make_string(char *);
struct operand  * 	make_variable(void *);
struct operand  * 	make_function(void *);
struct operand  * 	evaluate_term();
struct operand  * 	expression();
struct operand 	* 	evaluate( struct operand * );
struct operand 	* 	copy_operand( struct operand * );
int			store( struct variable *,struct operand * );
struct operand  * 	call_function( struct function * );
struct variable * 	locate_member(struct variable * , char * );


#endif // _jsptype_h

