#ifndef	_TRQUAL_C
#define _TRQUAL_C

#ifdef	__QUALITY

#include <malloc.h>

#define	TRQPTR	struct quality_entry XPTR

struct	quality_entry {
	WORD	number;
	BPTR	buffer;
	TRQPTR	suivant;
	TRQPTR	precedant;
	WORD	size;
	};

static TRQPTR	QualityHeap=(TRQPTR) 0;
static		QualityCount=0;

VPTR	QC_Alloc( n )
WORD	n;
{
	VPTR	buffer;
	TRQPTR	control;
	if (((buffer = malloc( n )) != (VPTR) 0)
	&&  ( OtrStatistics )) {
		if ((control = (TRQPTR) malloc( sizeof ( struct quality_entry ) )) != (TRQPTR) 0) {
			control->precedant = (TRQPTR) 0;
			if ((control->suivant = QualityHeap) != (TRQPTR) 0)
				control->suivant->precedant = control;
			QualityHeap = control;
			control->buffer = buffer;
			control->size = n;
			control->number = ++QualityCount;
			if ( OtrOption.Special )
				sysprintf(" QC$ALLOC: %u, %u bytes )\n",control->number, control->size);
			}
		else	{
			free( buffer );
			buffer = (VPTR) 0;
			}
		}
	return( buffer );
}

VOID	QC_Free( buffer )
VPTR	buffer;
{
	TRQPTR	control;

	if (!( OtrStatistics ))
		free( buffer );
	else	{
		if ((control = QualityHeap) == (TRQPTR) 0) {
			sysprintf("( QC$FREE:Too many frees )\n");
			exit(0);
			}
		else	{
			do	{
				if ( control->buffer == buffer ) {

					if ( control->suivant != (TRQPTR) 0 )
						control->suivant->precedant = control->precedant;
					if (control->precedant != (TRQPTR) 0)
						control->precedant->suivant = control->suivant;
					else	QualityHeap = control->suivant;
					free( control );
					free( buffer );
					return;
					}
				}
			while ((control = control->suivant) != (TRQPTR) 0);
			sysprintf("(QC$FREE:No match found )\n");
			exit(0);
			}
		}
	return;
}

VOID	memory_statistics()
{
	TRQPTR	control;
	WORD	n;
	WORD	l=0;
	BPTR	mptr;
	while ((control = QualityHeap) != (TRQPTR) 0) {
		QualityHeap = control->suivant;
		sysprintf("QC$STAT:unfreed memory: number %u : size %u\n",control->number,control->size);
		mptr = control->buffer;
		for (n=0, l=0; n < control->size; n++ ) {
			sysprintf("%02.1XH ",*(mptr++));
			l++;
			if ( l == 20 ) {
				sysprintf("\n"); 
				l = 0;
				}
			}
		if ( l )
			sysprintf("\n"); 
		free( control->buffer );
		free( control );
		}
	return;
}

#endif

#endif	/* _TRQUAL_C */


