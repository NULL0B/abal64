#ifndef	_vbuffer_h
#define	_vbuffer_h

public	void *	visual_buffer(int x,int y, int w, int h );
public	void * visual_drop( void * vptr);
public	int	visual_buffer_get(STDPSUPTR pptr, int atx, int aty );
public	int	visual_buffer_put(STDPSUPTR pptr, int atx, int aty );
public	int	visual_buffer_show(STDPSUPTR pptr, int atx, int aty, int nbx, int nby );

#endif	/* _vbuffer_h */
	/* ---------- */

