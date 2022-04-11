/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRMACRO.H 				*/
/*		Version :	2.1d					*/
/*		Date	:	16/02/1995				*/
/*									*/
/* --------------------------------------------------------------------	*/

#ifndef	_TRMACRO_H
#define _TRMACRO_H
#ifdef	_REDEFINE_OTR_FUNCTIONS
#define is_pragma		IsTcodePragma
#define add_definition		AddTcodeDefinition
#define liberate_definitions	LiberateTcodeDefinitions
#define initialise_definitions	InitialiseTcodeDefinitions
#define is_directive		IsTcodeDirective
#define	is_variable		IsTcodeVariable
#define	is_constant		IsTcodeConstant
#define	allocate_for_string	AllocateForTcodeString
#define	allocate_for_token 	AllocateForTcodeToken
#define	evaluate_expression     EvaluateTcodeExpression
#define allocate_for_variable	AllocateForTcodeVariable
#define allocate_for_type	AllocateForTcodeType
#define initialise_variables	InitialiseTcodeVariables
#define liberate_variables	LiberateTcodeVariables
#define allocate_for_constant	AllocateForTcodeConstant
#define generate_pause		GenerateTcodePause
#define terminate_code_block	TerminateTcodeBlock
#define generate_dimensions	GenerateTcodeDimensions
#define collect_integer		CollectTcodeInteger
#define	compare_tokens		CompareTcodeTokens
#endif

#endif	/* _TRMACRO_H */
	/* ---------- */

