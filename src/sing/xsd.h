#ifndef	_xsd_h
#define	_xsd_h

static	char *	xsd_keywords[] = {
	(char *)	"xsd:schema",
	(char *)	"xsd:element",
	(char *)	"xsd:attribute",
	(char *)	"xsd:simpleType",
	(char *)	"xsd:complexType",
	(char *)	"xsd:simpleContent",
	(char *)	"xsd:complexContent",
	(char *)	"xsd:sequence",
	(char *)	"xsd:choice",
	(char *)	"xsd:restriction",
	(char *)	"xsd:any",
	(char *)	"xsd:enumeration",
	(char *)	"xsd:anyAttribute",
	(char *)	"xsd:pattern",
	(char *)	"xsd:extension",
	(char *)	"xsd:length",
	(char *)	"xsd:maxLength",
	(char *)	"xsd:minLength",
	(char *)	"xsd:inclusive",
	(char *)	"xsd:maxInclusive",
	(char *)	"xsd:minInclusive",
	(char *)	"xsd:exclusive",
	(char *)	"xsd:maxExclusive",
	(char *)	"xsd:minExclusive",
	(char *)	"xsd:whiteSpace",
	(char *)	"xsd:fractionDigits",
	(char *)	"xsd:totalDigits"
	};

#define	_xsd_schema		0x0000
#define	_xsd_element		0x0001
#define	_xsd_attribute		0x0002
#define	_xsd_simpleType		0x0003
#define	_xsd_complexType	0x0004
#define	_xsd_simpleContent	0x0005
#define	_xsd_complexContent	0x0006
#define	_xsd_sequence		0x0007
#define	_xsd_choice		0x0008
#define	_xsd_restriction	0x0009
#define	_xsd_pattern		0x000A
#define	_xsd_enumeration	0x000B
#define	_xsd_extension		0x000C
#define	_xsd_any		0x000D
#define	_xsd_anyAttribute	0x000E
#define	_xsd_length		0x000F
#define	_xsd_maxLength		0x0010
#define	_xsd_minLength		0x0011
#define	_xsd_inclusive		0x0012
#define	_xsd_maxInclusive	0x0013
#define	_xsd_minInclusive	0x0014
#define	_xsd_exclusive		0x0015
#define	_xsd_maxExclusive	0x0016
#define	_xsd_minExclusive	0x0017
#define	_xsd_whiteSpace		0x0018
#define	_xsd_fractionDigits	0x0019
#define	_xsd_totalDigits	0x001A
#define	_xsd_max		0x001B

struct	xsd_list	{
	int	nature;	/* sequence or choice */
	struct 	xsd_element 	* first;
	struct 	xsd_element 	* last;
	};

struct	xsd_type	{
	struct 	xsd_type 	* previous;
	struct 	xsd_type 	* next;
	int		  nature;	/* simple types or complex */
	char	 	* name;
	struct xsd_list * detail;
	};

	

struct	xsd_element	{
	struct 	xsd_element 	* previous;
	struct 	xsd_element 	* next;
	char			* name;
	struct	xsd_type	* type;
	};


struct	xsd_schema	{
	char	*	name;
	struct	xsd_element	*	efirst;
	struct	xsd_element	*	elast;
	struct	xsd_type	*	tfirst;
	struct	xsd_type	*	tlast;
	};

#endif	/* _xsd_h */
	/* ------ */



