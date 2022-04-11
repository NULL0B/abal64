#ifndef	_manedit_h
#define	_manedit_h

#include "element.h"
#include "document.h"

struct	manifest;
struct	node;
struct	relation;

struct	compute
{
	char *	name;
	char *	hostname;
	char * 	cores;
	char * 	speed;
	char * 	memory;
	char *	architecture;
};

struct	storage
{
	char *	name;
	char * 	size;
	char *	type;
};

struct	port
{
	struct	port * previous;
	struct	port * next;
	char * 	name;
	char * 	from;
	char * 	to;
	char *	protocol;
	char *	range;
	char * 	direction;
};

struct	ports
{
	struct port * first;
	struct port * last;
};

struct	network
{
	char * 	name;
	char *	vlan;
	char *	label;
	struct	ports portlist;
};

struct	system
{
	char *	name;
	char *	version;
};

struct	package
{
	struct	package * previous;
	struct	package * next;
	char *	name;
	char *	installation;
	char *	configuration;
	struct	ports portlist;
};

struct	infrastructure
{
	char *	name;
	struct	compute * cpu;
	struct	storage * disk;
	struct	network * card;
};

struct	packages
{
	struct	package * first;
	struct	package * last;
};

struct	image
{
	char *	name;
	char *	agent;
	struct	system * os;
	struct	packages	 packagelist;

};

struct	dependance
{
	struct	dependance * previous;
	struct	dependance * next;
	struct	relation   * parent;
	struct	node * other;
	struct	node * owner;
	char * 	expression;
	int	type;
};

struct	dependances
{
	struct	dependance * first;
	struct	dependance * last;
};

struct	node
{
	struct	node * previous;
	struct	node * next;
	struct	manifest * nested;
	char *	name;
	char *	icon;
	int	x;
	int	y;
	int	ly;
	int	dath;
	int	number;
	int	visible;
	char *	typename;
	int	access;
	int	scope;
	int	type;
	char *	category;
	struct	infrastructure * hard;
	struct	image * soft;
	struct	dependances links;
};

struct	account
{
	char * 	name;
	int	users;
};

struct	security
{
	char *	name;
	char *	level;
	char *	policy;
};	

struct	actions
{
	char *	name;
	struct	action * first;
	struct	action * last;
};

struct	action
{
	struct 	action * previous;
	struct	action * next;
	char *	name;
	char *	type;
	char *	expression;
};

struct	relation
{
	struct	relation * previous;
	struct	relation * next;
	struct	dependance * source;
	struct	dependance * target;
	char * 	expression;
};

struct	relations
{
	struct	relation * first;
	struct	relation * last;
};

struct	manifest
{
	char *	name;
	char *	ns;
	char *	filename;
	struct	node * top;
	struct	node * first;
	struct	node * last;
	struct	node * current;
	struct	account owner;
	struct	security access; 
	struct	actions  configuration;
	struct	actions  release;
	struct	actions  interface;
	struct	relations graph;
};


#endif 	/* _manedit_h */

