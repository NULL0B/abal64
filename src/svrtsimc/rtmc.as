#user "abaljson.def"

program "jsonparser"

#include "json.as"

extern proc RtSi(handle%,filename$=256,cflags%) : %

dcl	doit%
dcl	e%
dcl	t%
dcl	h%
dcl	keystorage$=32000
dcl	filename$=256
dcl	jsonname$=256
dcl	buffer$=2048
dcl	keyword$=2048
arg	filename

dcl	version%
dcl	ksize%
dcl	ktype%
dcl	rsize%
dcl	table$=256

dcl	tempname$=256
dcl	keyname$=50
dcl	keytype%
dcl	keysize%
dcl	keyoffset%

dcl	linktype%
dcl	linkname$=50
dcl	linkparts$=4096

proc	CreateFile()
	Print=1:("ASSIGN=1,",$,"MC,WR,EX",/1),filename
	if ( doit <> 0 ) 
		Assign=44,filename,MC,WR,EX:Next,e,keystorage 
		Dfile=44:Next,e
	endif
	Select ktype
	Case	0
		Print=1:("CFILE=1,D=",$,",K=",$,/1),conv$(rsize),conv$(ksize)
		if ( doit <> 0 ) :: Cfile=44,D=rsize,K=ksize:Next,e :: endif
	Case	1
		Print=1:("CFILE=1,D=",$,",LK=",$,/1),conv$(rsize),conv$(ksize)
		if ( doit <> 0 ) :: Cfile=44,D=rsize,LK=ksize:Next,e :: endif
	Case	2
		Print=1:("CFILE=1,D=",$,",RK=",$,/1),conv$(rsize),conv$(ksize)
		if ( doit <> 0 ) :: Cfile=44,D=rsize,RK=ksize:Next,e :: endif
	EndSel
endproc

proc	CreateKeys()
	Print=1:($,/1),"CKEY=1"
	if ( doit <> 0 ) :: CKey=44:Next,e :: endif
endproc

proc	CreateKey()
	Print=1:("KEY=1,",$,",",$,",",$,/1),keyname,conv$(keysize),chr$(keytype)
	if ( doit <> 0 ) 
		Select Chr$(keytype)
		Case	"A"	:: Key=44,keyname,keysize,A:Next,e 
		Case	"B"	:: Key=44,keyname,keysize,B:Next,e 
		Case	"N"	:: Key=44,keyname,keysize,N:Next,e 
		Case	"D"	:: Key=44,keyname,keysize,D:Next,e 
		Case	"T"	:: Key=44,keyname,keysize,T:Next,e 
		Case	"L"	:: Key=44,keyname,keysize,L:Next,e 
		Case	"F"	:: Key=44,keyname,keysize,F:Next,e 
		Case	"H"	:: Key=44,keyname,keysize,H:Next,e 
		Case	"S"	:: Key=44,keyname,keysize,S:Next,e 
		EndSel
		print=1:e,tabv(1)
	endif

endproc

proc	CreateLinks()
	Print=1:($,/1),"CLINK=1"
	if ( doit <> 0 ) :: Clink=44:Next,e :: endif
endproc

proc	CreateLink()
	Print=1:("LINK=1,",$,/1),linkparts
	if ( doit <> 0 ) :: Link=44,linkparts:Next,e :: endif
endproc

segment 0
	;** collect filename

	While ( index(filename,chr$(/0D)) <> 0 ) 
		filename = includ( index(filename,chr$(/0D)) , " ", 1)
	wend

	if ( Len$(filename) =0 )
		print=1:(/1,$),"SV MC Abal 64 : Version 1.0a"
		print=1:(/1,$,/1),"Copyright (c) 2022 Amenesik / Sologic "
		stop
	endif

	jsonname = print(($,$),filename,".json")
	h = openjson(jsonname,len$(jsonname))

	if ( h > 0 )
		doit = 1
		while ( h > 0 )
			gosub &getjson
			select ( t )
			case	JSON_NULL, JSON_CLOSE
				print=1:($,/1),"EOF"
				h = closejson(h)
				h = 0
			case	JSON_STRUCT
				Select Large(keyword)
				Case	"RECORDS"
					gosub &records
				EndSel
			case	JSON_NAME
				keyword = Large(buffer)
			case	JSON_ARRAY
				Select Large(keyword)
				Case	"COLUMNS"
					CreateFile()
					gosub &columns
					CreateKeys()
				Case	"INDEXES"
					gosub &indexes
					CreateLinks()
				Default
					print=1:($,/1),"EOF"
					h = closejson(h)
					h = 0
				EndSel
			case	JSON_VALUE
				Select Large(keyword)
				Case	"VERSION"
					version = conv%(buffer)
				Case	"KEYSIZE"
					ksize = conv%(buffer)
				Case	"KEYTYPE"
					ktype = conv%(buffer)
				Case	"RECORDSIZE"
					rsize = conv%(buffer)
				Case	"TABLE"
					table = buffer
				Default
					print=1:($,/1),"EOF"
					h = closejson(h)
					h = 0
				EndSel
			default
				print=1:($,E,/1),"???",t
				h = closejson(h)
				h = 0
			endsel
		wend
	else
		print=1:($,/1),"error creating JSON file"
	endif
	stop
&getjson
	t = readjson(h,buffer,len(buffer))
	return
&showtype
	select t
	case	JSON_NAME
		print=1:"NAME",tabv(1)
	case	JSON_VALUE
		print=1:"VALUE",tabv(1)
	case	JSON_ARRAY
		print=1:"ARRAY",tabv(1)
	case	JSON_STRUCT
		print=1:"STRUCT",tabv(1)
	case	JSON_CLOSE
		print=1:"CLOSE",tabv(1)
	default	
		print=1:t,tabv(1)
	Endsel
	return
&columns
	while ( h > 0 )
		gosub &getjson
		select ( t )
		case	JSON_CLOSE
			return
		case	JSON_STRUCT
			gosub &getcolumn
		endsel
	wend
	return
&getcolumn
	while ( h > 0 )
		gosub &getjson
		select ( t )
		case	JSON_STRUCT
		case	JSON_CLOSE
			CreateKey()
			return
		case	JSON_NAME
			tempname = buffer
		case	JSON_VALUE
			Select Large(tempname)
			Case	"NAME"
				keyname = buffer
			Case	"SIZE"
				keysize = Conv%(buffer)
			Case	"TYPE"
				keytype = Conv%(buffer)
			Case	"OFFSET"
				keyoffset = Conv%(buffer)
			Endsel
		endsel
	wend
	return
&indexes
	while ( h > 0 )
		gosub &getjson
		select ( t )
		case	JSON_CLOSE
			return
		case	JSON_STRUCT
			gosub &getindex
		endsel
	wend
	return
&getindex
	while ( h > 0 )
		gosub &getjson
		select ( t )
		case	JSON_CLOSE
			return
		case	JSON_NAME
			tempname = buffer
		case	JSON_ARRAY
			Select Large(tempname)
			case	"COLUMNS"
				gosub &getlink
			EndSel
		EndSel
	wend
	return
&getlink
	linkparts = " "
	while ( h > 0 )
		gosub &getjson
		select ( t )
		case	JSON_CLOSE
			CreateLink()
			return
		case	JSON_STRUCT
			gosub &getpart
		endsel
	wend
	return
&getpart
	while ( h > 0 )
		gosub &getjson
		select ( t )
		Case	JSON_CLOSE
			return
		case	JSON_NAME
			tempname = buffer
		case	JSON_VALUE
			Select Large(tempname)
			Case	"NAME"
				if ( len$(linkparts) = 0 )
					linkparts = buffer
				else :: linkparts = Print(($,",",$),linkparts,buffer)
				endif
			endsel
		endsel
	wend
	return
&records
	while ( h > 0 )
		gosub &getjson
		select ( t )
		case	JSON_CLOSE
			return
		case	JSON_NAME
			tempname = buffer
		case	JSON_VALUE
			Select Large(tempname)
			Case	"NAME"
				if ( doit <> 0 ) :: RtSi(44,filename,0) :: endif
			EndSel
		endsel
	wend
	return
eseg 0
end


