#ifdef	DEBUG_TRACE_ACTIVE
#define	trace( m ) if (OtrOption.Special) sysprintf( m )
#else
#define	trace( m )
#endif
