#ifndef	_http_request
#define _http_request

#class 	http_request

public  dcl     command$=16
public  dcl     version$=16
public  dcl     object$=8192

public	dcl	body$=512

public	http_headers headers

public	function constructor build:(buffer$=4096)
        command = left(buffer,index(buffer," "))
        buffer  = includ(1,Space(index(buffer," ")))
        buffer  = shl(buffer)
        object  = Left(buffer,index(buffer," "))
        buffer  = includ(1,Space(index(buffer," ")))
        buffer  = shl(buffer)
	version = buffer
end

public	function constructor drop:(buffer$=4096)
	headers.drop_headers
end

#endclass http_request

#endif 	_http_request

