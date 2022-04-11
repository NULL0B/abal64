//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_script_entities_h
#define _html_script_entities_h


#define	_SCRIPT_VOID	0
#define	_SCRIPT_BYTE	1
#define	_SCRIPT_WORD	2
#define	_SCRIPT_STRING	3
#define	_SCRIPT_LONG	4
#define	_SCRIPT_ENTITY	5

//	----------------------------------------------------------------------
//	Heirarchy of script classes
//	----------------------------------------------------------------------
//
//	script_value			values provide type and list control
//		|	
//	script_variable			variables with name and value
//		|
//	script_function			with parameters variables and instructions
//
//	----------------------------------------------------------------------

class	standard_script_value	{

public:	standard_script_value();

	~standard_script_value();

	standard_script_value * operation( int opcode, standard_script_value * loperand, standard_script_value * roperand );
	void			affectation( standard_script_value * v );
	void			release();

	int			type;
	long			value;
	standard_script_value * prev;
	standard_script_value * next;

	static	standard_script_value * working;
	static	standard_script_value * waiting;

	static	standard_script_value * allocate();
	static	void			liberate( standard_script_value * operand );
	static	int			garbage_collection();
	};

class	standard_script_variable : public standard_script_value {
public:	standard_script_variable(char * nptr=0);
	~standard_script_variable();
	static	int	calculate_hash(char * sptr);
	char		* name;
	int		  hash;
	};

class	standard_script_function  : public standard_script_variable {
public:	standard_script_function(char * nptr=0);
	~standard_script_function();
	standard_script_value 	 * evaluation( standard_script_value * values );
	standard_script_variable * first_parameter;
	standard_script_variable * last_parameter;
	html_text_descriptor 	 * instructions;

	};

class	standard_script_engine	{

public:	standard_script_engine();
	~standard_script_engine();

	standard_script_variable * fvariable;
	standard_script_variable * lvariable;
	standard_script_function * ffunction;
	standard_script_function * lfunction;
	
	};


#endif	// _html_script_entities_h



