#ifndef _abalmail_h
#define _abalmail_h

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <setjmp.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include "bda.h"
#include "unicode.h"
#include "allocate.h"

#define	_MIME_UTF8 "utf-8"

struct mime_element
{
        struct mime_element * previous;
        struct mime_element * next;
	int	type;
        char *  parameter;
        char *  filename;
};

struct mime_message
{
	struct mime_message * previous;
	struct mime_message * next;
        char *  name;
        char *  from;
        char *  to;
        char *  cc;
        char *  bcc;
        char *  subject;
        char *  body;
        char *  parameter;
        char *  boundary;
	int	type;
        struct  mime_element * first;
        struct  mime_element * last;
};

#endif	/* _abalmail_h */

