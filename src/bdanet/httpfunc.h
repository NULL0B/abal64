#ifndef	_HTTPFUNC_H
#define	_HTTPFUNC_H

#define	_HTTP_ABAL_FAILURE 0xFFFF
#define	_HTTP_ABAL_SUCCESS 0

WORD	HttpInitialise(BYTE PTR,WORD);
WORD	HttpLiberate();
WORD	HttpOpenServer(WORD,WORD);
WORD	HttpOpenClient(BYTE PTR,WORD,WORD);
WORD	HttpClose(WORD,WORD);
WORD	HttpAccept(WORD,WORD);
WORD	HttpCommand(WORD,BYTE PTR);
WORD	HttpProxyCommand(WORD,BYTE PTR,BYTE PTR);
WORD	HttpGet(WORD,BYTE PTR,WORD);
WORD	HttpPut(WORD,BYTE PTR,WORD);
WORD	HttpGetLine(WORD,BYTE PTR,WORD);
WORD	HttpGetString(WORD,BYTE PTR,WORD);
WORD	HttpPutLine(WORD,BYTE PTR,WORD);
WORD	HttpGetAddress(WORD,BYTE PTR,WORD);
VOID	HttpSetConversion( WORD );
WORD	HttpTranscode( WORD );
WORD	HttpSetHost(WORD, BYTE PTR );
WORD	HttpSetType(BYTE PTR );
WORD	HttpPost(WORD, BYTE PTR );
WORD	HttpKeepAlive(WORD, WORD );
WORD	HttpOpenConnection(BYTE PTR,WORD,WORD,LONG);
LONG	HttpIpAddress(WORD);
VOID	HttpContentLength(WORD,BYTE PTR);
VOID	HttpSetAuthorize( BYTE PTR );
VOID	HttpProxyAuthorize( BYTE PTR );
WORD	HttpClear();
WORD	HttpCryptage(WORD,BYTE PTR,WORD, WORD );
WORD	HttpGetMajor();
WORD	HttpGetMinor();
WORD	HttpVersion();
WORD	HttpError();
WORD	HttpPutResponse(WORD,WORD,BYTE PTR,WORD);
WORD	HttpPutFile(WORD,BYTE PTR,WORD,WORD);
WORD	HttpFailure( WORD evalue );
WORD	HttpConfigure(BYTE PTR pptr,WORD plen);
WORD	HttpGetFile(WORD handle, BYTE PTR filename,WORD length, unsigned long bytes);
WORD	HttpLoadTable( BYTE PTR bptr, WORD blen );
WORD	HttpSelect(WORD handle, WORD timeout);
WORD	HttpReadTable( BYTE PTR bptr, WORD blen );
WORD	HttpPutByte(WORD handle, WORD value);
WORD	HttpSuccess();
WORD	HttpSetHeader(WORD handle, BYTE PTR header);
WORD	HttpDuplicate(WORD handle);

unsigned long	HttpFileSize(BYTE PTR filename, WORD length, WORD mode);

#endif 	/* _HTTPFUNC_H */
	/* ----------- */

