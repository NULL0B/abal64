#ifndef _libinxsql_h
#define _libinxsql_h

/*      ------------------------------------------------        */
/*                                                              */
/*      INXSQL : Database Client Library for ABAL and D3        */
/*                                                              */
/*      ------------------------------------------------        */
/*                                                              */
/*           Copyright (c) 2014-2021 Amenesik SARL              */
/*                                                              */
/*          Iain James Marshall  <ijm@amenesik.com>             */
/*                                                              */
/*      ------------------------------------------------        */

#ifndef	public
#define	public
#endif

#ifndef	XSBASE
#define	XSBASE void 
#endif

#ifndef	XSFILE
#define	XSFILE void 
#endif

public	int	IsamBegin(unsigned char * buffer, unsigned int callback) 	;
public	int	IsamEnd(void * vptr);
public	void * 	IsamCreate(char * n, int * i, int * d, int x, int c, int a, int v, int * e);
public	int	IsamClose(void * h);
public	void *	IsamOpen(char * n, int x, int c, int w, int * i, int * d, int * e);
public	int	IsamUnlink(char * filename);
public	int	IsamRename(XSFILE * h, char * newname);
public	int	IsamInfo(XSFILE * h,char * bptr, int blen);
public	int	IsamAtbOpen(XSFILE * h, int x, int c);
public	int	IsamInsert(XSFILE * h,char * iptr, int mq, char * rptr, int l);
public	int	IsamModif(XSFILE * h,char * iptr, int mq, char * rptr, int l);	
public	int	IsamDelete(XSFILE * h,char * iptr, int mq );
public	int	IsamSearch(XSFILE * h, int lock, char * iptr, int * mptr, char * rptr, int dlen, int * rlen);
public	int	IsamUpDown(XSFILE * h, int dir, int lock, int * mptr, char * rptr, int dlen, int * rlen);	
public	int	IsamWriteZc(XSFILE * h);
public	int	IsamReadZc(XSFILE * h);
public	int	IsamCriExt(XSFILE * h);	
public	void *  McIsamCreate(char * n, int * i, int * d, int x, int c, int a, int v, int * e);
public	int	McIsamClose(void * h); 	
public	void *	McIsamOpen(char * n, int x, int c, int w, int * i, int * d, int * e);
public	int	McIsamUnlink(char * filename);
public	int	McIsamRename(XSFILE * h, char * newname);
public	int	McIsamAtbOpen(XSFILE * h, int x, int c);
public	int	McIsamInfo(XSFILE * h,char * bptr, int blen);
public	int	McIsamInsert(XSFILE * h,char * iptr, int mq, char * rptr, int l); 	
public	int	McIsamModif(XSFILE * h,char * iptr, int mq, char * rptr, int l); 	
public	int	McIsamDelete(XSFILE * h,char * iptr, int mq );
public	int	McIsamSearch(XSFILE * h, int lock, char * iptr, int * mptr, char * rptr, int dlen, int * rlen); 	
public	int	McIsamUpDown(XSFILE * h, int dir, int lock, int * mptr, char * rptr, int dlen, int * rlen);	
public	int	McIsamCkey(XSFILE * h,char * nptr, int length, int type);
public	int	McIsamNkey(XSFILE * h,char * oldname,char * newname);
public	int	McIsamFkey(XSFILE * h,char * parent, char * child, int length,int type, int offset);
public	int	McIsamCndx(XSFILE * h, char * descriptor,int length);
public	int	McIsamDndx(XSFILE * h, char * descriptor,int length);	
public	int	McIsamDCndx(XSFILE * h, char * descriptor,int length);
public	int	McIsamDDndx(XSFILE * h, char * descriptor,int length); 	
public	int	McIsamLkey( XSFILE * h, char * dptr, int dlen, int option);
public	int	McIsamLndx( XSFILE * h, char * dptr, int dlen, int option);
public	int	McIsamUpdndx(XSFILE * h); 
public	int	McIsamQuery(struct xs_file * h, char * qptr, int qlen );
public	int	McIsamCount(XSFILE * h,char * dptr,int uni,int seq,int dlen, int * response );
public	int	McIsamPosit(XSFILE * h,char * dptr,int uni,int seq,int last, int dlen, int * response );
public	int	McIsamCollect(XSFILE *fptr, char *dptr, int dlen, int uni, int seq, int mode, int last, int *lgcle, 
		char *outbuf, int *outlen, int *response);
public	int	McIsamSelect(XSFILE *fptr, char *dptr, int dlen, char * kptr, int klen, char **outbuf, int * outlen, int *response);

public	void * BdIsamCreate(char * nptr, int cp, int ex, int * e);
public	void * BdIsamOpen(char * nptr, int cp, int ex, int wr, int * e);
public	int	BdIsamClose(void * handle);
public	int	BdIsamUnlink(char * nptr);	
public	int	BdIsamRename(void * h, char * nptr); 	
public	int	BdIsamAtbOpen(XSBASE * h, int ex, int c); 
public	void *  BdIsamCreateFile( char * n, XSBASE * bptr, int * i, int * d, int x, int c, int a, int v, int * e);
public	void *	BdIsamOpenFile(char * n, XSBASE * bptr, int x, int c, int w, int * i, int * d, int * e);
public	int	BdIsamCloseFile(XSFILE * h);
public	int	BdIsamUnlinkFile(char * filename, XSBASE * bptr, int option);
public	int	BdIsamRenameFile(XSFILE * h, char * newname);
public	int	BdIsamInfoFile(XSFILE * h,char * bptr, int blen);
public	int	BdIsamSearch(XSFILE * h, int lock, char * iptr, int * mptr, char * rptr, int dlen, int * rlen); 	
public	int	BdIsamInsert(XSFILE * h,char * iptr, int mq, char * rptr, int l);
public	int	BdIsamDelete(XSFILE * h,char * iptr, int mq );
public	int	BdIsamModif(XSFILE * h,char * iptr, int mq, char * rptr, int l);	
public	int	BdIsamUpDown(XSBASE * h, int dir, int lock, int * marq, char * dptr, int dlen);
public	int	BdIsamUpDownFile(XSFILE * h, int dir, int lock, int * mptr, char * rptr, int dlen, int * rlen);  	
public	int	BdIsamCkey(XSFILE * h,char * nptr, int length, int type);
public	int	BdIsamNkey(XSFILE * h,char * oldname,char * newname);
public	int	BdIsamFkey(XSFILE * h,char * parent, char * child, int length,int type, int offset); 	
public	int	BdIsamCndx(XSFILE * h, char * descriptor,int length);
public	int	BdIsamDndx(XSFILE * h, char * descriptor,int length);	
public	int	BdIsamDCndx(XSFILE * h, char * descriptor,int length);
public	int	BdIsamDDndx(XSFILE * h, char * descriptor,int length);	
public	int	BdIsamUpdndx(XSFILE * h);
public	int	BdIsamCount(XSBASE * h,char * dptr,int uni,int seq,int dlen, int * response );
public	int	BdIsamPosit(XSBASE * h,char * dptr,int uni,int seq,int last, int dlen, int * response );
public	int	BdIsamJoin(XSBASE * h, char * dptr, int dlen);
public	int	BdIsamCjoin(XSBASE * h, char * dptr, int dlen, int type); 	
public	int	BdIsamDjoin(XSBASE * h, char * name);
public	int	BdIsamRjoin(XSBASE * h, char * dptr, int dlen);
public	int	BdIsamInfo(XSBASE * h,char * bptr, int blen);
public	int	BdIsamLfile(XSBASE * h, char * dptr, int dlen, int option);
public	int	BdIsamLjoin(XSBASE * h, char * dptr, int dlen, int option);
public	int	BdIsamLkey(XSFILE * h, char * dptr, int dlen, int option);
public	int	BdIsamLlink(XSFILE * h, char * dptr, int dlen, int option);

#endif	/* _libinxsql_h */
