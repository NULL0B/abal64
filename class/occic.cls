#ifndef	_occi_client
#define	_occi_client

#class  occi_client( public http_client )

private	Dcl	username$=64
private	Dcl	password$=64

public	http_response pointer response
public	http_client pointer client

; -------------------------
; initialise the EDI client
; -------------------------
public  inline constructor initialise:( u$, s$ )
	Forget response
	Forget client
        credentials( u; s )
end

; ------------------------
; terminate the EDI client
; ------------------------
public  inline destructor terminate:( u$, s$ )
	release_response
	release_client
end

; ---------------------------------
; set the authorization credentials
; ---------------------------------
public  inline method credentials:( n$, s$ )
	username = n
	password = s
end

; -------------------------------
; ensure the http client released
; -------------------------------
private	routine method release_client:
	if ( ValidPtr(client) <> 0 )
		Remove client
	Endif
end

; --------------------------------------
; ensure the previous response released
; --------------------------------------
private	routine method release_response:
	if ( ValidPtr(response) <> 0 )
		Remove response
	Endif
end

; -------------------------------
; ensure the http client is ready
; -------------------------------
private	routine method check_client:
	if ( ValidPtr(client) = 0 )
		Create client
	Endif
	client.authorize(username; password)
end

; ----------------------------------------------
; sends the document request to the URL endpoint
; ----------------------------------------------
public  function method send:( url$=1024, document$=512 )
	local http_response pointer response
	check_client
	release_response	
	client.authorize(username; password)
	response = client.request("POST";url;document)
end

#endclass occi_client

#endif	_occi_client
