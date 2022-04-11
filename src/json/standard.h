#ifndef	_standard_h
#define	_standard_h

//      ------------------------------------------
//
//      Copyright (c) 2021 Amenesik SARL
//
//      Iain James MArshall <ijm@amenesik.com>
//
//      ------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#ifdef  ABALREDHAT
#include <uuid.h>
#else
#include <uuid/uuid.h>
#endif
#include <pthread.h>
#include <wait.h>

#ifndef public
#define public
#endif

#ifndef private
#define private static
#endif

#ifndef interface
#define interface public
#endif

#define whitespace(c) ((c == ' ') || (c == '\t') || (c == '\r') || (c == '\n'))

#endif	/* _standard_h */
