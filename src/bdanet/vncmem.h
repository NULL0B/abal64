#ifndef	_vncmem_h
#define	_vncmem_h

extern	void * malloc(int);
extern	void   free(void *);

extern	void * allocate(int);
extern	void * liberate(void *);

#endif	/* _vncmem_h */

