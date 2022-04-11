#ifndef	_TRRTLTOC_H
#define	_TRRTLTOC_H

#define	_RTL_PTR	"*"
#define	_RTL_GOSUB	"rtl_gosub"
#define	_RTL_RETURN	"rtl_return"
#define	_RTL_THROW	"rtl_throw"
#define	_RTL_GOTO	"goto"
#define	_RTL_SWITCH	"switch"
#define	_RTL_CASE  	"case"

#define	rtl_space 		rtl_putb(' ')
#define	rtl_equals 		rtl_putb('=')
#define	rtl_comma 		rtl_putb(',')
#define	rtl_semicolon 		rtl_putb(';')
#define	rtl_colon 		rtl_putb(':')
#define	rtl_leftbrace 		rtl_putb('(')
#define	rtl_rightbrace		rtl_putb(')')
#define	rtl_leftaccolade 	rtl_putb('{')
#define	rtl_rightaccolade	rtl_putb('}')
#define	rtl_leftsquare 		rtl_putb('[')
#define	rtl_rightsquare		rtl_putb(']')
#define	rtl_percent   		rtl_putb(0x0025)
#define	rtl_quote     		rtl_putb(0x0022)
#define	rtl_backslash 		rtl_putb(0x005C)

#define	_RTL_INT8	"char"
#define	_RTL_INT16	"short"
#define	_RTL_FLOAT	"float"
#define	_RTL_DOUBLE	"double"
#define	_RTL_STRING	"struct _string"

#define	rtl_int8 		rtl_puts(_RTL_INT8)
#define	rtl_int16		rtl_puts(_RTL_INT16)
#define	rtl_float		rtl_puts(_RTL_FLOAT)
#define	rtl_double 		rtl_puts(_RTL_DOUBLE)
#define	rtl_string		rtl_puts(_RTL_STRING)

#endif	/* _TRRTLTOC_H */
	/* ----------- */


