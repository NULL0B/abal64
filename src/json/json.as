#user "abaljson.def"
program "jsonparser"

dcl	t%
dcl	h%
dcl	o%
dcl	filename$=1024
dcl	output$=1024
dcl	buffer$=2048

segment 0
	print=1:($,/1),"START ABAL JSON PARSER TEST"
	filename = "test.json"
	output = "output.json"
	h = openjson(filename,len$(filename))
	o = createjson(output,len$(output))

	if ( h > 0 )
		print=1:($,/1),"OPEN  JSON : OK"
		if ( o > 0 )
			print=1:($,/1),"CREATE JSON : OK"
		else
			print=1:($,/1),"CREATE JSON : FAIL"
		endif
		while ( h > 0 )

			t = readjson(h,buffer,len(buffer))
			select ( t )
			case	0 
				print=1:($,/1),"READ  JSON : NULL"
				h = closejson(h)
				o = closejson(o)
				print=1:($,/1),"CLOSE JSON : OK"
				h = 0
			case	1
				print=1:($,X,$,/1),"READ  JSON : NAME  =",buffer
				t = writejson(o,t,buffer,len$(buffer));
			case	2
				print=1:($,X,$,/1),"READ  JSON : VALUE =",buffer
				t = writejson(o,t,buffer,len$(buffer));
			case	3
				print=1:($,/1),"READ  JSON : STRUCT"
				t = writejson(o,t,buffer,len$(buffer));
			case	4
				print=1:($,/1),"READ  JSON : ARRAY"
				t = writejson(o,t,buffer,len$(buffer));
			case	5
				print=1:($,/1),"READ  JSON : CLOSE"
				t = writejson(o,t,buffer,len$(buffer));
			case	6
				print=1:($,/1),"READ  JSON : ERROR"
			endsel
		wend
	else
		print=1:($,/1),"OPEN JSON : FAIL "
	endif

	print=1:($,/1),"END ABAL JSON PARSER TEST"
eseg 0
end


