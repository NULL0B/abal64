#ifndef	_http_response
#define _http_response

#class 	http_response

public  dcl     status%
public  dcl     version$=16
public  dcl     message$=8192
public	dcl	body$=512

public	http_headers headers

public	function constructor build:(buffer$=4096)
	version = Left(buffer,Index(buffer," "))
        buffer  = Includ(1,Space(Index(buffer," ")))
        buffer  = Shl(buffer)
        status  = Conv%(Left(buffer,Index(buffer," ")))
        buffer  = Includ(1,Space(Index(buffer," ")))
        buffer  = Shl(buffer)
        message = buffer
end

public	function edit:
	Local	e%
	if ( Len$(body) > 0 )
		Assign=1,"vi":Next,e
		Load.Go=1,body:Next,e
	Endif
end

public	function constructor drop:(buffer$=4096)
	headers.drop_headers
end

#endclass http_response

#endif 	_http_response

