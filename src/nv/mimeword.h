//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_mime_words_h
#define _html_mime_words_h


#define	_MIME_TEXT_PLAIN	  0
#define	_MIME_TEXT_HTML		  1
#define	_MIME_TEXT_CSS		  2
#define	_MIME_TEXT_JAVASCRIPT	  3
#define	_MIME_TEXT_ABALSCRIPT	  4
#define	_MIME_IMAGE_BMP		  5
#define	_MIME_IMAGE_GIF		  6
#define	_MIME_IMAGE_JPEG	  7
#define	_MIME_IMAGE_MPEG	  8
#define	_MIME_AUDIO_WAV		  9
#define	_MIME_AUDIO_AVI	 	 10
#define	_MIME_MAX_TYPES		 11


#define	_MIME_ENTITY_URL	 0
#define	_MIME_CONTENT_LOCATION	 1
#define	_MIME_CONTENT_TYPE	 2
#define	_MIME_CONTENT_LENGTH	 3
#define	_MIME_LAST_MODIFIED	 4
#define	_MIME_PRAGMA		 5
#define	_MIME_NOCACHE		 6
#define	_MIME_LOCATION		 7
#define	_MIME_EXPIRES			 8
#define	_MIME_CONTENT_SCRIPT_TYPE	 9
#define	_MIME_CHARSET 			10
#define	_MIME_TRANSFER_ENCODING		11
#define	_MIME_CHUNKED 			12
#define	_MIME_CONNECTION		13
#define	_MIME_PERSIST 			14
#define	_MIME_CLOSE   			15
#define	_MIME_MAX_WORDS			16

#ifndef	_html_language_c

extern	"C"	{
	extern	char * mimekeywords[ _MIME_MAX_WORDS ];
	extern	char * mimekeytypes[ _MIME_MAX_TYPES ];
	};

#else

char * mimekeytypes[ _MIME_MAX_TYPES ] = {
	(char *) "text/plain",
	(char *) "text/html",	
	(char *) "text/css",	
	(char *) "text/javascript",
	(char *) "text/abalscript",
	(char *) "image/bmp",	
	(char *) "image/gif",	
	(char *) "image/jpeg",	
	(char *) "image/mpeg",	
	(char *) "x-audio/wav",	
	(char *) "x-audio/avi"	
	};

char * mimekeywords[ _MIME_MAX_WORDS ] = {
	(char *) "ENTITY-URL",	 
	(char *) "CONTENT-LOCATION",	
	(char *) "CONTENT-TYPE",	
	(char *) "CONTENT-LENGTH",	
	(char *) "LAST-MODIFIED",
	(char *) "PRAGMA",
	(char *) "NOCACHE",
	(char *) "LOCATION",
	(char *) "EXPIRES",
	(char *) "CONTENT-SCRIPT-TYPE",	
	(char *) "CHARSET"
#ifdef	_NV11BX
	,
	(char *) "TRANSFER-ENCODING",
	(char *) "CHUNKED",	
	(char *) "CONNECTION",
	(char *) "PERSIST",
	(char *) "CLOSE"
#endif
	};


#endif



#endif	// _html_mime_words_h







