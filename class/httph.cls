#class http_header

public	http_header pointer previous
public	http_header pointer next
public	name$=256
public	value$=4096

public	strict function constructor init:(buffer$=4096)
	name = Large(Left(buffer,Index(buffer,":")-1))
	buffer = Includ(1,Space(Index(buffer,":")))
	value = Shl(buffer)	
end

public	strict function constructor init:(n$=256,v$=4096)
	name = n
	value = v
end

#endclass

#class http_headers 

public	http_header pointer first
public	http_header pointer last

public	inline constructor initialise:
	Forget first
	Forget last
end

public	inline	destructor terminate:
	drop_headers
end

; -----------------------------------
; add the provided header to the list
; -----------------------------------
public	function	add_header:(class http_header pointer h)
        if ( ValidPtr(first) = 0 )
                first = Alias(h)
        Else :: last.next = Alias(h)
	Endif
	h.previous = Alias(last)
        last = Alias(h)
end

; ---------------------------
; release the list of headers
; ---------------------------
public	function	drop_headers:
        local http_header pointer h
        while ( ValidPtr(first) <> 0 )
                h = Alias(first)
                first = Alias(h.next)
                Remove h
        wend
        Forget last
        Forget first
end

; -----------------------------------------------
; create and add the requested header information
; -----------------------------------------------
public	integer function header:(n$=256,v$=4096)
	local http_header pointer h
	Create h(n;v)
	add_header(h)
end

; --------------------------
; finds the requested header
; --------------------------
public class http_header pointer function find_header:(n$=256)
	local http_header pointer h
	h = Alias( first )
	While ( ValidPtr( h ) <> 0 )
		if ( Large(h.name) = Large(n) )
			Break
		Else ::	h = Alias( h.next )
		Endif
	Wend
	Exit( h )
end

#endclass http_headers

