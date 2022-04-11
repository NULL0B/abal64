#ifndef	_http_foundation
#define	_http_foundation

;** ---------------------------------------------
;** C L A S S   :   h t t p _ f o u n d a t i o n
;** ---------------------------------------------
;** This class provides the foundation of HTTP 
;** communication and is overloaded to create the 
;** clients and servers.    
;** ---------------------------------------------

#class http_foundation( public bdanet_client )

public	dcl	handle%
public	dcl	buffer$=4096
public	dcl	path$=512
public	dcl	certificate$=512
public	dcl	privatekey$=512
public	dcl	calist$=512
public	dcl	passphrase$=64
public	dcl	tlsmode%

public	http_headers output

; ------------------------------------------
; build the basic functions library
; ------------------------------------------
public	function constructor initalise:
	Local	v$=512
	handle = -1
	v = Env("HTTP_PATH")
	If ( Len$(v) = 0 )
		path = "rest/"
	Else :: path = Print(($,"/"),v)
	Endif
	v = Env("HTTP_KEY")
	If ( Len$(v) = 0 )
		privatekey = " "
	Else :: privatekey = v
	Endif
	v = Env("HTTP_CERT")
	If ( Len$(v) = 0 )
		certificate = " "
	Else :: certificate = v
	Endif
	v = Env("HTTP_CA")
	If ( Len$(v) = 0 )
		calist = " "
	Else :: calist = v
	Endif
	v = Env("HTTP_PASS")
	If ( Len$(v) = 0 )
		passphrase = " "
	Else :: passphrase = v
	Endif
	v = Env("HTTP_TLSMODE")
	If ( Len$(v) = 0 )
		tlsmode = 5
	Else :: tlsmode = Conv%(v)
	Endif
	evalue = HttpSecurity(tlsmode,privatekey,certificate,calist,passphrase)
end

; ---------------------------
; close the server connection
; ---------------------------
public	routine	method close_server:
	evalue = HttpClose(handle,0)
	handle = -1
end	

; ---------------------------		
; close the client connection
; ---------------------------		
public	function method close_request:
	output.drop_headers
	evalue = HttpClose(handle,1)
end	

; ----------------------------------
; display the contents of the buffer
; ----------------------------------
public 	routine	method	echo_buffer:
	standard_message
end

; ----------------------------------
; displays a standard colour message
; ----------------------------------
public	routine method standard_message:
	print=1:Paint(2,0),(?LW,/1),((conf(2)-1)),buffer,Paint(7,0)
end

; --------------------------------
; displays an error colour message
; --------------------------------
public	routine method error_message:
	print=1:Paint(7,1),(?LW,/1),((conf(2)-1)),buffer,Paint(7,0)
end

; ----------------------------------
; displays an success colour message
; ----------------------------------
public	routine method success_message:
	print=1:Paint(0,2),(?LW,/1),((conf(2)-1)),buffer,Paint(7,0)
end

; ---------------------------------
; read one line from the connection
; ---------------------------------
public	routine	method	get_line:	
	evalue = HttpGetLine(handle,buffer,Len(buffer))
	echo_buffer
end

; ---------------------------------
; write one line to the connection
; ---------------------------------
public	routine	method	put_line:	
	echo_buffer
	evalue = HttpPutLine(handle,buffer,Len$(buffer))
end

; ---------------------------------------
; will be overloaded by client and server
; ---------------------------------------
public	virtual function input_header:(http_header pointer h)
end

; --------------------------------
; get an http header or empty line
; --------------------------------
public	integer function get_header:(class http_headers pointer headers)
	local http_header pointer h
	get_line
	if ( len$(buffer) = 0 )
		Exit(0)
	Else :: Create h(buffer)
		headers.add_header(h)
		input_header(h)
		Exit(1)
	Endif
end

; --------------------------
; receives the input headers
; --------------------------
public	function input_headers:(class http_headers pointer headers)
	local dcl x%
	While ( get_header(headers) <> 0 )
		x = x + 1
	Wend
end

; -------------------------------
; prepare the content type header
; -------------------------------
public	function content_type:(f$=512)
        local http_header pointer h
        Local dcl type$
        type = Parse(f,16)
        type = Includ(1," ")
        type = Shl(type)
        Select Large(type)
        Case    "PNG","JPG","JPEG","JFIF","GIF","BMP","TARGA"
                Create h("Content-Type";"image/"!type)
                output.add_header(h)
        Case    "SH","TXT","JSON","XML","HTM","HTML","CSV","CSS"
                Create h("Content-Type";"text/"!type)
                output.add_header(h)
        Default
                Create h("Content-Type";"application/octet-stream")
                output.add_header(h)
        EndSel
end

; ---------------------------------
; prepare the content length header
; ---------------------------------
public	function content_length:(f$=512)
	Local http_header pointer h
	Local Dcl work$=64
	Local Dcl fsbuf$=4
	Local Field=m,fsbuf
	Local Dcl fs:
	evalue = HttpSize(f,Len$(f),0,fsbuf) 
	work = Print(($),conv$(fs))
        Create h("Content-Length";work)
        output.add_header(h)
end

; ------------------------------
; send a single header to output
; ------------------------------
public	inline method send_header:(n,v)
	buffer = Print(($,":",X,$),n,v)
	put_line
end

; ---------------------------------------------
; send the HTTP response headers and empty line
; ---------------------------------------------
public	function output_headers:
        local http_header pointer h
	h = Alias(output.first)
	While ( validPtr(h) <> 0 )
		send_header(h.name;h.value)
		h = Alias(h.next)
	Wend
	buffer = " "
	put_line
end

; ------------------------------------------
; builds a temporary filename for body parts
; ------------------------------------------
public	string function temporary_filename:(type$)
	Local	Dcl	fn$=512
	fn = Print(($,HZ4,"-",HZ2,HZ2,"-",HZ2,HZ2,HZ2,"-",HZ4,HZ4,"-",HZ4,".",$),path,Conv%(Date(1)),Conv%(Date(2)),Conv%(Date(3)),Conv%(Date(5)),Conv%(Date(6)),Conv%(Date(7)),Event(21),Event(20),Rnd,type)
	Exit( fn )
end

; ----------------------------------
; retrieve the body from the message
; ----------------------------------
public 	string function input_body:(class http_headers pointer headers)
	Local Dcl ifn$=512
	Local http_header pointer h
        Local Dcl fs:
        Local Field=m, fs
        Local Dcl hi%
        Local Dcl lo%
	h = headers.find_header("content-length")
	if ( validptr( h ) <> 0 )
		fs = Conv(h.value)
		ifn = temporary_filename("tmp")
		evalue = HttpGetFile(handle,ifn,Len$(ifn),hi,lo)
		Exit( ifn )
	Else :: Exit( " " )
	Endif
end

; --------------------------------
; sends a file in the message body
; --------------------------------
public	inline	method output_body:(ofn$)
	evalue = HttpFile(handle,ofn,Len$(ofn),0)
end

; -----------------------------------
; declare the http authorization info
; -----------------------------------
public	String function http_basic_auth:(n$=64,s$=64)
        Local   encoded$=2048
        Local   work$=2048
        buffer = Print(($,":",$),n,s)
        evalue = HttpEncodeBase64(encoded,buffer,Len$(buffer))
        work = Print(("Basic ",$),encoded)
	Exit( work )
end

#endclass http_foundation

#endif _http_foundation

