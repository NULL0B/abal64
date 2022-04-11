#ifndef	UTBIBH
#define	UTBIBH

/*	Function Redefinitions		*/
/*	----------------------		*/

#ifdef	VMS
#define	creat(a,b) Mcreat(a,b)
#define open(a,b) Mopen(a,b)
#define lseek(a,b,c)Mlseek(a,b,c)
#define read(a,b,c) Mread(a,b,c)
#define write(a,b,c) Mwrite(a,b,c)
#define close(a) Mclose(a)
#endif

#ifndef	UNIX
#ifndef	VMS
#ifndef	PRL

#define	memcpy(arg1,arg2,arg3) Mmemcpy(arg1,arg2,arg3)
#define memset(arg1,arg2,arg3) Mmemset(arg1,arg2,arg3)
#define strcpy(arg1,arg2) Mstrcpy(arg1,arg2)
#define strcat(arg1,arg2) Mstrcat(arg1,arg2)
#define strlen(arg1) Mstrlen(arg1)
#define open(arg1,arg2) llmf_open(arg1,arg2)
#define close(arg1) llmf_close(arg1)
#define creat(arg1,arg2) llmf_creat(arg1,arg2)
#define unlink(arg1) llmf_unlink(arg1)

#ifdef DOS
#define read(arg1,arg2,arg3) Mread(arg1,arg2,arg3)
#define write(arg1,arg2,arg3) Mwrite(arg1,arg2,arg3)
#define lseek(arg1,arg2,arg3) Mlseek(arg1,arg2,arg3)
#endif

#ifdef PRL
#ifndef	LISTFILE
#define read(arg1,arg2,arg3) llmf_read(arg1,lptr->sector,arg2,arg3)
#define write(arg1,arg2,arg3) llmf_write(arg1,lptr->sector,arg2,arg3)
#else
#define read(arg1,arg2,arg3) llmf_read(arg1,OutStream.stream_block,arg2,arg3)
#define write(arg1,arg2,arg3) llmf_write(arg1,OutStream.stream_block,arg2,arg3)
#endif
#endif
#endif

/*	Function ProtoTypes 	*/
/* 	-------------------	*/
#ifndef	VPTR
#define VPTR void XPTR
#endif

void	Mmemcpy(BPTR,BPTR,EXAWORD);
void	Mmemset(BPTR,EXAWORD,EXAWORD);
void	Mstrcpy(BPTR,BPTR);
EXAWORD	Mstrlen(BPTR);

EXAWORD	llmf_open(BPTR,EXAWORD);
EXAWORD	llmf_close(EXAWORD);
EXAWORD	llmf_creat(BPTR,EXAWORD);
EXAWORD	llmf_unlink(BPTR);

#ifdef	DOS
EXAWORD	rename(BPTR,BPTR);
EXAWORD	Mread(EXAWORD,BPTR,EXAWORD);
#endif

#ifdef	PRL
EXAWORD	rename(EXAWORD,BPTR);
EXAWORD	llmf_read(EXAWORD,EXAWORD,BPTR,EXAWORD);
EXAWORD	llmf_write(EXAWORD,EXAWORD,BPTR,EXAWORD);
#endif

#endif
#endif
#endif

