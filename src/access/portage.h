#ifndef PORTAGE_H
#define    PORTAGE_H

#ifdef LINUX
#include "linux_port.h"
#endif

#ifdef	HPUX
#include "hpux_port.h"
#endif

#ifdef	AIX
#include "aix_port.h"
#endif

#ifdef	_PROTOTYPES
int	getqid();
void 	ExUserKill(int sigid );
int	killqueue(int qid );
int	openqueue(key_t msgqueue );
#else
int	getqid();
void 	ExUserKill();
int	killqueue();
int	openqueue();
#endif

#endif
