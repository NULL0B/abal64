#ifndef	_http_server
#define	_http_server

;** -------------------------------------
;** C L A S S   :   h t t p _ s e r v e r 
;** -------------------------------------
;** This class provides the basic Server
;** and may be derived by overloading the
;** GET, POST, PUT, DELETE and HEAD relay
;** -------------------------------------

#class http_server( public http_foundation )

public	dcl	port%
public	dcl	timeout%
public	dcl	command$=8
public	dcl	object$=4096
public  dcl     provided$=256
public  dcl     required$=256

; -----------------------------------
; check the authorization if required
; -----------------------------------
private	integer function check_authorisation:
        if ( Len$(required) > 0 )
                if ( Len$(provided) = 0 )
                        Exit(401)
                Else
                        if ( provided != required )
                                Exit(403)
                        Endif
                Endif
        Endif
        Exit(200)
end

; ------------------------------------------
; build the server object with port, timeout
; and mode then go online awaiting requests
; ------------------------------------------
public	inline constructor init:(p%,t%)
	port = p
	timeout = t
	online
end

; -------------------------------------
; attempt to open the server connection
; -------------------------------------
private	routine	method open_server:
	handle = HttpOpenServer(port,tcp)
end

; -------------------------------------
; attempt to accept a client connection
; -------------------------------------
private	routine method accept_request:
	evalue = HttpAccept(handle,timeout)
end

; ------------------------------
; online operational server loop
; ------------------------------
public routine	method online:
	if ( port > 0 )
		open_server
		if ( handle <> -1 )
			Do
				accept_request
				if ( evalue = 0 )
					process_request 
					close_request
				endif
				op break, evalue
			Loop
		else
			print=1:("failure : ",E,/1),HttpGetError
		endif
		close_server
	endif
end

; -----------------------------------
; intercept authorization information
; -----------------------------------
public  overload function input_header:(class http_header pointer h)
	Select Large(h.name)
	Case	"AUTHORIZATION"
		provided = h.value
	Endsel
end

; ------------------------------------
; receive and process a client request
; ------------------------------------
public function method process_request:
	local	http_request pointer q
	get_line
	Create q(buffer)
	input_headers(q.headers)
	Select check_authorisation
	Case 	200	
		q.body = input_body(q.headers)
		select large(q.command)
		case	"GET"
			http_server_get(q)
		case	"POST"
			http_server_post(q)
		case	"PUT"
			http_server_put(q)
		case	"DELETE"
			http_server_delete(q)
		case	"HEAD"
			http_server_head(q)
		default	
			http_server_response(405;"Incorrect Method")
		EndSel
	Case	401
	        http_server_response(401;"Not authorized")
	Case	403
	        http_server_response(403;"Forbidden")
	EndSel
	Remove q
end

; ----------------------------------------------------
; return the http response line version status message
; ----------------------------------------------------
public	inline http_server_response:(status%,msg$)
	buffer = print(("HTTP/1.1",X,Z3,X,$),status,msg)
	if ( status < 400 )
		success_message
	else :: error_message
	endif
	evalue = HttpPutLine(handle,buffer,Len$(buffer))
	http_server_headers
	output_headers
end

; ---------------------------
; prepares the server headers
; ---------------------------
public	virtual function http_server_headers:
	output.header("Server";"ABAL64/5.1a/RESTS")
	output.header("Cache-Control";"no-cache")
	output.header("Date";"Mon, 6 Jun 2021 08:11:00 GMT")
end

; -----------------------------
; handle the http GET operation
; -----------------------------
public	virtual function method http_server_get:(http_request pointer q)
	Assign=1,q.object:next,evalue
	Open=1:Next,evalue
	if ( evalue <> 0 )
		http_server_response(404;"Not Found ")
	Else ::	Close=1:Next,evalue
		content_length(q.object)
		content_type(q.object)
		http_server_response(200;"OK")
		output_body(q.object)
	Endif
end

; ------------------------------
; handle the http POST operation
; ------------------------------
public	virtual function method http_server_post:(http_request pointer q)
	http_server_response(400;"Bad Request")
end

; -----------------------------
; handle the http PUT operation
; -----------------------------
public	virtual function method http_server_put:(http_request pointer q)
	http_server_post(q)
end

; --------------------------------
; handle the http DELETE operation
; --------------------------------
public	virtual function method http_server_delete:(http_request pointer q)
	http_server_response(400;"Bad Request")
end

; ------------------------------
; handle the http HEAD operation
; ------------------------------
public	virtual function method http_server_head:(http_request pointer q)
	Assign=1,q.object:next,evalue
	Open=1:Next,evalue
	if ( evalue <> 0 )
		http_server_response(404;"Not Found")
	Else ::	Close=1:Next,evalue
		http_server_response(200;"OK")
	Endif
end

; --------------------------------
; set the HTTP BASIC authorization
; --------------------------------
public  virtual function method http_server_auth:(n$=64, s$=64)
        required = http_basic_auth(n;s)
end

#endclass http_server

#endif _http_server

