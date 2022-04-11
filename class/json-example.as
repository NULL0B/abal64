#user "abaljson.def"
program "jsonparser"
#include "json.as"
dcl	type%
dcl	input%
dcl	output%
dcl	filename$=1024
dcl	newname$=1024
dcl	buffer$=2048
segment 0
	print=1:($,/1),"START ABAL JSON PARSER TEST"
	filename = "input.json"
	input = openjson(filename,len$(filename))
	newname = "output.json"
	output = createjson(newname,len$(newname))
	if ( input > 0 )
		print=1:($,/1),"OPEN  JSON : OK"
		if ( output > 0 )
			print=1:($,/1),"CREATE JSON : OK"
		else
			print=1:($,/1),"CREATE JSON : FAIL"
		endif
		while ( input > 0 )

			type = readjson(input,buffer,len(buffer))
			select ( type )
			case	JSON_NULL
				print=1:($,/1),"READ  JSON : NULL"
				input = closejson(input)
				output = closejson(output)
				print=1:($,/1),"CLOSE JSON : OK"
				input = 0
			case	JSON_NAME
				print=1:($,X,$,/1),"READ  JSON : NAME  =",buffer
				type = writejson(output,type,buffer,len$(buffer));
			case	JSON_VALUE
				print=1:($,X,$,/1),"READ  JSON : VALUE =",buffer
				type = writejson(output,type,buffer,len$(buffer));
			case	JSON_STRUCT
				print=1:($,/1),"READ  JSON : STRUCT"
				type = writejson(output,type,buffer,len$(buffer));
			case	JSON_ARRAY
				print=1:($,/1),"READ  JSON : ARRAY"
				type = writejson(output,type,buffer,len$(buffer));
			case	JSON_CLOSE
				print=1:($,/1),"READ  JSON : CLOSE"
				type = writejson(output,type,buffer,len$(buffer));
			case	JSON_ERROR
				print=1:($,/1),"READ  JSON : ERROR"
			endsel
		wend
	else
		print=1:($,/1),"OPEN JSON : FAIL "
	endif
	print=1:($,/1),"END ABAL JSON PARSER TEST"
eseg 0
end


