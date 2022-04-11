/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1995 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRNURONE.H				*/
/*		Version :	2.1d					*/
/*		Date	:	23/02/1995				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRNURONE_H
#define	_TRNURONE_H


#define	NURONETPTR	struct otr_nural_network_class XPTR
#define	NUROBJPTR	struct otr_nural_network_object XPTR
#define	NURONEPTR	struct otr_nurone XPTR

#define	_FORWARD_LAYER	0
#define	_INPUT_LAYER	1
#define	_OUTPUT_LAYER	2
#define	_HIDDEN_LAYER	3

#define	_NATURE_SUMATE	0
#define	_NATURE_LIMITER	1
#define	_NATURE_SIGMOID 2


struct	otr_nural_network_class {
	WORD		identity;
	WORD		nature;
	WORD		mode;
	WORD		inputs;
	WORD		weights;
	WORD		nurones;
	BPTR		name;
	TCVARPTR	input;
	TCVARPTR	output;
	NURONEPTR	ilevel;
	NURONEPTR	hlevel;
	NURONEPTR	olevel;
	NURONEPTR	flevel;
	NURONETPTR	next;
	};

struct	otr_nural_network_object {
	BPTR		name;
	NURONETPTR	class;
	WORD		type;
	NUROBJPTR	next;
	};

struct	otr_nurone	{
	BPTR		name;
	WORD		identity;
	WORD		state;
	WORD		nature;
	WORD		inputs;
	NURONETPTR	class;
	TCVARPTR	input;
	TCVARPTR	output;
	NURONEPTR	next;
	NURONEPTR	prev;
	};

#ifdef	_TRNURONE_C
NURONETPTR	NuralNetworkClass=(NURONETPTR) 0;
NURONETPTR	NetworkDefine=(NURONETPTR) 0;
NUROBJPTR	NuralNetworkObject=(NUROBJPTR) 0;
#endif

#ifndef	UNIX
NURONETPTR	is_nural_network_class( BPTR );
NURONETPTR	allocate_for_network_class( VOID );
NUROBJPTR	is_nural_network_object( BPTR );
NUROBJPTR	allocate_for_network_object( VOID );
TCVARPTR	collect_typed_parameters( WORD );
#else
NURONETPTR	is_nural_network_class();
NURONETPTR	allocate_for_network_class();
NUROBJPTR	is_nural_network_object();
NUROBJPTR	allocate_for_network_object();
TCVARPTR	collect_typed_parameters();
#endif



#endif	/* _TRNURONE_H */
	/* ----------- */


