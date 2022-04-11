#ifndef	_asfun_dbox_h
#define	_asfun_dbox_h

#define DBOX_MESSAGE		1
#define DBOX_BOUTON		2
#define DBOX_R_BOUTON		3
#define DBOX_C_BOUTON		4
#define DBOX_SAISIE		5
#define DBOX_LISTE		6
#define DBOX_AIDE		7
#define DBOX_FUNFREE     	8


struct	asfun_element	{
	int	atc;		/* column position of the element */
	int	atl;		/* line   position of the element */
	int	nbc;		/* width in text columns	  */
	int	nbl;		/* height in text lines		  */
	int	type;		/* element type			  */
	int	style;		/* element style as appropriate	  */
	int	boolean;	/* check box t/f radio number	  */	
	int *	current;	/* pointer to shared radio value  */
	int	active;		/* active button number 	  */
	int	trigger;	/* trigger value for keyboard	  */
	int	position;	/* edit element cursor position	  */
	int	offset;		/* edit element start offset   	  */
	int	insert;		/* edit element start offset   	  */
	int	isfocus;	/* item is current focus item	  */
	int	etat;		/* item can be changed or not	  */
	int	items;		/* radio/check collection count	  */
	char	value[_MAX_VALUE];
	char	comment[_MAX_COMMENT];
	};

struct	asfun_dbox	{
	int	window;
	int	style;
	int	number;
	char	titre[_MAX_TITLE+1];
	int	lentit;
	int	type;		/* H or V */
	int	escape;		/* escape type 1 .... 5 */
	int	options;
	int	lenopt;
	int	lencom;
	struct  asfun_element * option[_MAX_ELEMENTS];
	};

public	void	show_dbox( struct asfun_dbox * bptr );

#endif	/* _asfun_dbox_h */
	/* ------------- */


