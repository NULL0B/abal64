#ifndef	_TRGENRTL_H
#define	_TRGENRTL_H

#ifndef	UNIX
BPTR		generate_pointer_vector( TCVARPTR );
BPTR		TypePrefixed( BPTR, WORD );
BPTR		TypedExpression( WORD );
BPTR		RtlProcedurePointer(VOID);
BPTR		IntegerExpression( VOID );
BPTR		rtlbcd_constant( BPTR );
BPTR		rtlstring_constant( BPTR );
BPTR		BcdExpression( VOID );
BPTR		StringExpression( VOID );
BPTR		NewBcdRegister( VOID );
BPTR		NewStringRegister( WORD );
BPTR		EvaluateExpression( VOID );
BPTR		IntegerOperation( WORD, BPTR, BPTR );
BPTR		StringOperation( WORD, BPTR, BPTR );
BPTR		BcdOperation( WORD, BPTR, BPTR );
BPTR		EvaluateComparison(WORD,BPTR,BPTR,BPTR,WORD,WORD);
BPTR		c_integer_operand( RESULTPTR );
BPTR		generate_string_constant( TCCONPTR );
BPTR		variable_rvalue( TCVARPTR  );
BPTR		variable_svalue( TCVARPTR  );
BPTR		generate_variable_name( TCVARPTR  );
BPTR		generate_pointer_adresse( TCVARPTR );
BPTR		VariableArithmetic( WORD, TCVARPTR, BPTR );
BPTR		open_rtlclf(BPTR);
BPTR		add_rtlclf(BPTR,BPTR,WORD);
BPTR		add_rtlclf_format(BPTR,BPTR,WORD);
BPTR		close_rtlclf(BPTR);
#else
BPTR		generate_pointer_vector();
BPTR		TypePrefixed();
BPTR		TypedExpression();
BPTR		IntegerExpression();
BPTR		BcdExpression();
BPTR		StringExpression();
BPTR		EvaluateExpression();
BPTR		NewBcdRegister();
BPTR		NewStringRegister();
BPTR		IntegerOperation();
BPTR		StringOperation();
BPTR		BcdOperation();
BPTR		EvaluateComparison();
BPTR		c_integer_operand();
BPTR		generate_string_constant();
BPTR		variable_rvalue();
BPTR		variable_svalue();
BPTR		generate_variable_name();
BPTR		generate_pointer_adresse();
BPTR		VariableArithmetic();
BPTR		open_rtlclf();
BPTR		add_rtlclf();
BPTR		add_rtlclf_format();
BPTR		close_rtlclf();
BPTR		rtlbcd_constant();
BPTR		rtlstring_constant();
BPTR		RtlProcedurePointer();
#endif

#endif	/* _TRGENRTL_H */
	/* ----------- */







