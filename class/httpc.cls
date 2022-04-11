#ifndef	_http_client
#define	_http_client

;** -------------------------------------
;** C L A S S   :   h t t p _ c l i e n t
;** -------------------------------------
;** This class provides the basic Client
;** and may be derived by overloading the
;** GET, POST, PUT, DELETE and HEAD relay
;** -------------------------------------

#class	http_client( public http_foundation )

public	dcl	url$=4096
public	dcl	challenge$=256
public	dcl	service$
public	dcl	hostname$=1024
public	dcl	host$=1024
public	dcl	object$=4096
public	dcl	port%
public	dcl	status%
public	dcl	message$=80

; -----------------------------------
; build the object : three variations
; -----------------------------------

; ----------------------------------------------
; for calling the request method
; ----------------------------------------------
public	strict function constructor initialise:

end

; ----------------------------------------------
; for GET, DELETE and HEAD requests with no BODY
; ----------------------------------------------
public	strict function constructor initialise:(v$,u$=1024)
	Local	http_response pointer a
	a = request(v;u;" ")
	if ( ValidPtr(a) <> 0 )	
		Remove a
	Endif
end

; ----------------------------------------------
; for POST and PUT requests with BODY file
; ----------------------------------------------
public	strict function constructor initialise:(v$,u$=1024,bf$=512)
	Local	http_response pointer a
	a = request(v;u;bf)
	if ( ValidPtr(a) <> 0 )	
		Remove a
	Endif
end

; --------------------------------------------------
; delete the object : three corresponding variations
; --------------------------------------------------
public	strict destructor function liberate:

end

public	strict destructor function liberate:(v$,u$=1024)

end

public	strict destructor function liberate:(v$,u$=1024,bf$=512)

end

; -----------------------
; launch the HTTP request
; -----------------------
public	class http_response pointer function request:(v$,u$=1024,f$=512)
	Local	http_response pointer a
	Select ( Large(v) )
	Case	"GET"	::	Exit( http_client_get(u) )
	Case	"POST"	::	Exit( http_client_post(u;f) )
	Case	"PUT"	::	Exit( http_client_put(u;f) )
	Case	"DELETE"::	Exit( http_client_delete(u) )
	Case	"HEAD"	::	Exit( http_client_head(u) )
	Default		::	Forget a :: Exit( a )
	EndSel
end

; ----------------------
; open the client handle 
; ----------------------
private	routine	open_client:
	parse_url(url)
	if ( Small(service) = "http" )
		handle = HttpOpenClient(url;Len$(url);tcp )
	Else :: if ( Small(service) = "https" )
			handle = HttpOpenClient(url;Len$(url);tls )
		Else :: handle = HttpOpenClient(url;Len$(url);tcp )
		Endif
	Endif
end

; ------------------------
; send the request headers 
; ------------------------
private	function send_headers:
	local http_header pointer h
	output.header("Host";host)
	output.header("User-Agent";"ABAL64/5.1a/RESTC")
	output.header("Accept";"*/*")
	output.header("Accept-Encoding";"identity")
	output.header("Connection";"close")
	If ( Len$(challenge) <> 0 )
		output.header("Authorization",challenge)
	Endif
	output_headers
end

; -------------------------------------
; prepare the headers for handling body
; -------------------------------------
private	integer function prepare_body:(f$=512)
	Local	Dcl	e%
	if ( Len$(f) > 0 )
        	Assign=1,f:next,e
        	Open=1:Next,e
        	if ( e <> 0 )
			status = 600
        	        Exit(0)
        	Else :: Close=1:Next,e
			content_length(f)
			content_type(f)
			Exit(1)
        	Endif
	Else ::	Status = 601
		Exit(0)
	Endif
end

; -------------------------------------------
; parse url to service, host, port and object
; -------------------------------------------
public	function parse_url:(purl$=1024)
	Local Dcl	i%
	reset_url
	i = Index(purl,":")
	if ( i > 0 )
		service = Small(Left(purl,i-1))
		Select service
		Case	"http"  :: port = 80
		Case	"https" :: port = 443
		Default		:: port = 0
		EndSel
		purl = Space(Index(purl,":")+2)
		purl = Shl(purl)
		if ( Index(purl,":") <> 0 )
			hostname = Left(purl,Index(purl,":")-1)
			purl = Space(Index(purl,":"))
			purl = Shl(purl)
			port = Conv(purl)
			host = Print(($,":",$),hostname,Conv$(port))
			if ( Index(purl,"/") <> 0 )
				purl = Space(Index(purl,"/")-1)
				object = Shl(purl)
			Else ::	object = "/"
			Endif
		Else :: if ( Index(purl,"/") <> 0 )
				hostname = Left(purl,Index(purl,"/")-1)
				purl = Includ(1,Space(Index(purl,":")-1))
				object = Shl(purl)
			Else :: hostname = purl
				object = "/"
			Endif
			host = hostname
		Endif
	Endif
end

; ----------------------------------
; reset the fields of the parsed url
; ----------------------------------
private	routine reset_url:
	service = " "
	hostname = " "
	object = " "
	port = 0
end

; --------------------------------------
; retrieve the response line from server
; --------------------------------------
public	class http_response pointer function method get_response:
	local http_response pointer r
	get_line
	Create r(buffer)
	buffer = Includ(1,Space(Index(buffer," ")))
	buffer = Shl(buffer)
	status = Conv%(Left(buffer,Index(buffer," ")))
	buffer = Includ(1,Space(Index(buffer," ")))
	buffer = Shl(buffer)
	message= buffer
	input_headers(r.headers)
	Exit( r )
end

; --------------------------------------
; send the http request line and headers
; --------------------------------------
public	inline method send_request:(v$)
	buffer = Print(($,X,$,X,$),v,object,"HTTP/1.1")
	put_line
	send_headers
end

; --------------------
; launch a GET request
; --------------------
public	virtual class http_response pointer function method http_client_get:(u$=4096)
	Local http_response pointer a
	url = u
	open_client
	send_request("GET")
	a = get_response
	if ( ValidPtr(a) <> 0 )
		if ( a.status = 200 )
			a.body = input_body(a.headers)
		Endif
	Endif
	close_request	
	Exit( a )
end

; ---------------------
; launch a POST request
; ---------------------
public	virtual class http_response pointer function method http_client_post:(u$=4096,f$=512)
	Local http_response pointer a
	url = u
	open_client
	if ( prepare_body(f) != 0 )
		send_request("POST")
		output_body(f)
		a = get_response
	Endif
	close_request	
	Exit( a )
end

; --------------------
; launch a PUT request
; --------------------
public	virtual class http_response pointer function method http_client_put:(u$=4096,f$=512)
	Local http_response pointer a
	url = u
	open_client
	if ( prepare_body(f) != 0 )
		send_request("PUT")
		output_body(f)
		a = get_response
	endif
	close_request	
	Exit( a )
end

; -----------------------
; launch a DELETE request
; -----------------------
public	virtual class http_response pointer function method http_client_delete:(u$=4096)
	Local http_response pointer a
	url = u
	open_client
	send_request("DELETE")
	a = get_response
	close_request	
	Exit( a )
end

; ---------------------
; launch a HEAD request
; ---------------------
public	virtual class http_response pointer function method http_client_head:(u$=4096)
	Local http_response pointer a
	url = u
	open_client
	send_request("HEAD")
	a = get_response
	close_request	
	Exit( a )
end

; --------------------------------
; set the HTTP BASIC authorization
; --------------------------------
public	inline method authorize:(n$=64, s$=64)
	challenge = http_basic_auth(n;s)
	evalue = HttpAuthorise(challenge,Len$(challenge))
end

#endclass http_client

#endif 	_http_client

