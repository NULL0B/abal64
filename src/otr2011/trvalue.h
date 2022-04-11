#ifndef	TRVALUE_H
#define TRVALUE_H

#ifndef	UNIX
VALUEPTR	allocate_for_value( VOID );
VALUEPTR	liberate_value( VALUEPTR );
VALUEPTR	memory_target( VALUEPTR , WORD );
VOID		value_statistics( VOID );
#else
VALUEPTR	allocate_for_value();
VALUEPTR	liberate_value();
#endif

#endif	/* TRVALUE_H */
	/* -------- */



