#ifndef	_JPEGFUNC_H
#define	_JPEGFUNC_H

#define	JPEGLOADER struct jpeg_loader_context
#define	JPEGPTR	   JPEGLOADER PTR

JPEGLOADER	{
	BYTE	PTR			filename;
	FILE	PTR			handle;
	struct jpeg_decompress_struct 	cinfo;	
  	JSAMPARRAY 			buffer;		
	int 				row_stride;				
  	struct jpeg_error_mgr 		pub;
	int				options;
	char				palette[256];

	};


PUBLIC WORD JpegInitialise();
PUBLIC WORD JpegLiberate();
PUBLIC WORD JpegOpen(BYTE FAR PTR,WORD,WORD,BYTE FAR PTR);
PUBLIC WORD JpegClose(WORD);
PUBLIC WORD JpegGetRow(WORD,BYTE FAR PTR,WORD);
PUBLIC WORD JpegGetWidth(WORD);
PUBLIC WORD JpegGetHeight(WORD);
PUBLIC VOID JpegSetMemory(WORD);

#endif	/* _JPEGFUNC_H */
	/* ----------- */






