program "xml-parser"

#include "xml.as"

dcl	e%
dcl	started%
dcl	input$=1024
dcl	output$=1024

dcl	version$=64
dcl	charset$=64
dcl	style$=1024
dcl	element$=256

dcl	buffer$=2048
field=m,buffer
	dcl	type%
	dcl	length%
	dcl	value$=2044
field=m

segment 0
	print=1:($,/1),"START ABAL XML PARSER TEST"
	input = "input.xml"
	Assign=1,input,XML:next,e
	Open=1:Next,e
	if ( e = 0 )
		print=1:($,/1),"OPEN XML : OK"
		output = "output.xml"
		Assign=2,output,XML,WR:next,e
		Cfile=2:Next,e
		if ( e = 0 )
			print=1:($,/1),"CREATE XML : OK"
			Read=1,XML_READ,0:Next,e,buffer,Len(buffer)
			While ( e = 0 )
				select ( type )
				case	XML_OPEN
					if ( started = 0 )
						Read=1,XML_READ_VERSION,0:Next,e,version,len(version)
						print=1:($,X,$,/1),"READ  XML VERSION = ",version
						Write=2,XML_WRITE_VERSION,0:Next,e,version,len$(version)
						Read=1,XML_READ_CHARSET,0:Next,e,charset,len(charset)
						print=1:($,X,$,/1),"READ  XML CHARSET = ",charset
						Write=2,XML_WRITE_CHARSET,0:Next,e,charset,len$(charset)
						Read=1,XML_READ_STYLE,0:Next,e,style,len(style)
						print=1:($,X,$,/1),"READ  XML STYLE   = ",style
						Write=2,XML_WRITE_STYLE,0:Next,e,style,len$(style)
						started = 1
					endif
					print=1:($,X,$,/1),"READ  XML : OPEN ELEMENT =",value
					element = value
					Write=2,XML_WRITE,0:Next,e,buffer,Len(buffer)
				case	XML_NAME
					print=1:($,X,$,/1),"READ  XML : ATB NAME =",value
					Write=2,XML_WRITE,0:Next,e,buffer,length+4
				case	XML_VALUE
					print=1:($,X,$,/1),"READ  XML : ATB VALUE =",value
					Write=2,XML_WRITE,0:Next,e,buffer,length+4
				case	XML_CLOSE
					print=1:($,X,$,/1),"READ  XML : CLOSE ELEMENT =",value
					Write=2,XML_WRITE,0:Next,e,buffer,length+4
				case	XML_TEXT
					print=1:($,X,$,/1),"READ  XML : ELEMENT TEXT =",value
					Write=2,XML_WRITE,0:Next,e,buffer,length+4
				endsel
				buffer = " " :: type = 0 :: length = 0
				Read=1,/60,0:Next,e,buffer,Len(buffer)
			wend
			Close=2:Next,e
			Close=1:Next,e
		else
			print=1:($,X,$,/1),"CREATE XML : FAIL",output
		endif
	else
		print=1:($,X,$,/1),"OPEN XML : FAIL ",input
	endif

	print=1:($,/1),"END ABAL XML PARSER TEST"
eseg 0
end


