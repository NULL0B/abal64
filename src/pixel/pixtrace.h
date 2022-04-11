#ifndef	_pixel_tracing_h
#define	_pixel_tracing_h

#ifndef	_PIXEL_TRACING
#define	_PIXEL_TRACING
#endif

#ifdef	_PIXEL_TRACING

#define	CheckColumn(a,b,s) {		\
	if (( a >= XGC.width   )	\
	||  ((a+b) > XGC.width )) {	\
		XGC.trace_error_count++;\
		return;			\
		}			\
	}

#define	CheckCoordinates(a,b,w,h,s) { 	\
	if (( a >= XGC.width  )		\
	||  ( b >= XGC.height )		\
	||  ( (a+w) > XGC.width )	\
	||  ( (b+h) > XGC.height)) {	\
		XGC.trace_error_count++;\
		return;			\
		}			\
	}

#define	ClipRow(a,b,s) {		\
	if ( a >= XGC.height  ) {	\
		XGC.trace_error_count++;\
		return;			\
		}			\
	else if ((a+b) < a) {		\
		XGC.trace_error_count++;\
		return;			\
		}			\
	else if ((a+b) > XGC.height) {	\
		XGC.trace_error_count++;\
		b = (XGC.height-a);	\
		}			\
	}

#define	ClipColumn(a,b,o,s) {		\
	if ( a >= XGC.width  ) {	\
		XGC.trace_error_count++;\
		return;			\
		}			\
	else if ((a+b) < a) {		\
		XGC.trace_error_count++;\
		return;			\
		}			\
	else if ((a+b) > XGC.width) {	\
		XGC.trace_error_count++;\
		o = (b-(XGC.width-a));	\
		b = (XGC.width-a);	\
		}			\
	else	o = 0;			\
	}

#define	ClipCoordinates(a,b,w,h,s) { 	\
	if (( a >= XGC.width  )		\
	||  ( b >= XGC.height )) {	\
		XGC.trace_error_count++;\
		return;			\
		}			\
	if ((a+w) < a) {		\
		XGC.trace_error_count++;\
		return;			\
		}			\
	if ((b+h) < b) {		\
		XGC.trace_error_count++;\
		return;			\
		}			\
	if ((a+w) > XGC.width ) { 	\
		XGC.trace_error_count++;\
		w = (XGC.width - a);	\
		}			\
	if  ((b+h) > XGC.height) { 	\
		XGC.trace_error_count++;\
		h = (XGC.height-b);	\
		}			\
	}
#define	ClipTargetCoordinates(a,b,w,h,s) { 	\
	if (( a >= XGC.softwidth  )		\
	||  ( b >= XGC.softheight )) {	\
		XGC.trace_error_count++;\
		return;			\
		}			\
	if ((a+w) < a) {		\
		XGC.trace_error_count++;\
		return;			\
		}			\
	if ((b+h) < b) {		\
		XGC.trace_error_count++;\
		return;			\
		}			\
	if ((a+w) > XGC.softwidth ) { 	\
		XGC.trace_error_count++;\
		w = (XGC.softwidth - a);	\
		}			\
	if  ((b+h) > XGC.softheight) { 	\
		XGC.trace_error_count++;\
		h = (XGC.softheight-b);	\
		}			\
	}
#else
#define	CheckColumn(a,b,s)
#define	ClipRow(a,b,s)
#define	CheckCoordinates(a,b,c,d,e)
#define	ClipCoordinates(a,b,c,d,e)
#define	trace_message(m)
#endif
#endif	/* _pixel_tracing_h */

