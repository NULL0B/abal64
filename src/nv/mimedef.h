//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_mime_definitions_h
#define _html_mime_definitions_h

#include "mimeword.h"

#define	_TEXT_HTML		mimekeytypes[_MIME_TEXT_HTML]
#define	_TEXT_CSS 		mimekeytypes[_MIME_TEXT_CSS]
#define	_TEXT_JAVASCRIPT	mimekeytypes[_MIME_TEXT_JAVASCRIPT]
#define	_TEXT_ABALSCRIPT	mimekeytypes[_MIME_TEXT_ABALSCRIPT]
#define	_TEXT_PLAIN		mimekeytypes[_MIME_TEXT_PLAIN]
#define	_IMAGE_GIF		mimekeytypes[_MIME_IMAGE_GIF]
#define	_IMAGE_BMP		mimekeytypes[_MIME_IMAGE_BMP]
#define	_IMAGE_JPEG		mimekeytypes[_MIME_IMAGE_JPEG]
#define	_IMAGE_MPEG		mimekeytypes[_MIME_IMAGE_MPEG]
#define	_AUDIO_WAV		mimekeytypes[_MIME_AUDIO_WAV]
#define	_AUDIO_AVI		mimekeytypes[_MIME_AUDIO_AVI]

#define	_ENTITY_URL		mimekeywords[_MIME_CONTENT_LOCATION]
#define	_CONTENT_LOCATION	mimekeywords[_MIME_CONTENT_LOCATION]
#define	_CONTENT_TYPE		mimekeywords[_MIME_CONTENT_TYPE]
#define	_CONTENT_LENGTH		mimekeywords[_MIME_CONTENT_LENGTH]
#define	_LAST_MODIFIED		mimekeywords[_MIME_LAST_MODIFIED]
#define	_PRAGMA			mimekeywords[_MIME_PRAGMA]
#define	_NOCACHE		mimekeywords[_MIME_NOCACHE]
#define	_LOCATION		mimekeywords[_MIME_LOCATION]
#define	_EXPIRES 		mimekeywords[_MIME_EXPIRES]
#define	_CONTENT_SCRIPT_TYPE	mimekeywords[_MIME_CONTENT_SCRIPT_TYPE]
#define	_CHARSET 		mimekeywords[_MIME_CHARSET]

#ifdef	_NV11BX
#define	_TRANSFER_ENCODING	mimekeywords[_MIME_TRANSFER_ENCODING]
#define	_CHUNKED 		mimekeywords[_MIME_CHUNKED]
#define	_CONNECTION		mimekeywords[_MIME_CONNECTION]
#define	_PERSIST 		mimekeywords[_MIME_PERSIST]
#define	_CLOSE	 		mimekeywords[_MIME_CLOSE]
#endif

#endif	// _html_mime_definitions_h







