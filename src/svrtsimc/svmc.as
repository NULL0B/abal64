#user "abaljson.def"
program "svmc"
#include "json.as"
extern proc SvSi(handle%,filename$=256,rl%,kl%) : %
dcl	js%,jn%,jv%,ja%,jc%
dcl	i%
dcl	e%
dcl	h%
dcl	infos$=64
field=m,infos
dcl	rsize%
dcl	ksize%
dcl	ktype#
field=m
dcl	value$=64
dcl	jsonname$=256
dcl	filename$=256
dcl	savename$=256
dcl	keys$=8192
dcl	buffer$=1024
field=m,buffer
dcl	keyname$=50
dcl	keylen%
dcl	keytype#
dcl	keyoff%
field=m,buffer
dcl	linktype#
dcl	linkcount#
dcl	linkname$=50(20)
field=m
arg filename
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

	print=1:(/1,$,X,$),"opening file",filename
	assign=1,filename,mc,ex:next,e,keys
	open=1:next,e
	if ( e <> 0 )
		print=1:(/1,$,X,$,X,$,X,$,/1),"error",conv$(e),"opening",filename
		stop
	else
		ktype=0
		ksize=16
		rsize=256	
		read=1,/00,0:Next,e,infos
	endif
	jsonname = Print(($,$),filename,".json")
	h = createjson(jsonname,len$(jsonname))
	js = JSON_STRUCT
	ja = JSON_ARRAY
	jn = JSON_NAME
	jv = JSON_VALUE
	jc = JSON_CLOSE

	;** json file header
	e = writejson(h,js," ",0)

	;** version =1
	e = writejson(h,jn,"version",len$("version"))
	e = writejson(h,jv,"1",len$("1"))

	;** table
	e = writejson(h,jn,"table",len$("table"))
	e = writejson(h,jv,filename,len$(filename))

	;** key size
	value = print(($),conv$(ksize))
	e = writejson(h,jn,"keysize",len$("keysize"))
	e = writejson(h,jv,value,len$(value))

	;** key type
	value = print(($),conv$(ktype))
	e = writejson(h,jn,"keytype",len$("keytype"))
	e = writejson(h,jv,value,len$(value))

	;** record size
	value = print(($),conv$(rsize))
	e = writejson(h,jn,"recordsize",len$("recordsize"))
	e = writejson(h,jv,value,len$(value))

	print=1:(/1,$,X),"processing columns"
	e = writejson(h,jn,"columns",len$("columns"))
	e = writejson(h,ja," ",0)
	lkey=1,(F):next,e,buffer
	while ( e = 0 )
		print=1:(/1,$,X,$,X,HZ2),keyname,conv$(keylen),keytype
		e = writejson(h,js," ",0)
		e = writejson(h,jn,"name",len$("name"))
		e = writejson(h,jv,keyname,len$(keyname))
		value = print(($),conv$(keylen))
		e = writejson(h,jn,"size",len$("size"))
		e = writejson(h,jv,value,len$(value))
		value = print(($),conv$(keytype))
		e = writejson(h,jn,"type",len$("type"))
		e = writejson(h,jv,value,len$(value))
		value = print(($),conv$(keyoff))
		e = writejson(h,jn,"offset",len$("offset"))
		e = writejson(h,jv,value,len$(value))
		e = writejson(h,jc," ",0)
		lkey=1,(N):next,e,buffer
	wend
	e = writejson(h,jc," ",0)

	print=1:(/1,$,X),"processing indexes"
	e = writejson(h,jn,"indexes",len$("indexes"))
	e = writejson(h,ja," ",0)
	llink=1,(F):next,e,buffer
	while ( e = 0 )
		print=1:(/1,HZ2,X,HZ2),linktype,linkcount
		e = writejson(h,js," ",0)
		value = print(($),conv$(linktype))
		e = writejson(h,jn,"state",len$("state"))
		e = writejson(h,jv,value,len$(value))
		e = writejson(h,jn,"columns",len$("columns"))
		e = writejson(h,ja," ",0)
		for i = 1 to linkcount
			print=1:(/1,T,$),linkname(i)
			e = writejson(h,js," ",0)
			e = writejson(h,jn,"name",len$("name"))
			e = writejson(h,jv,linkname(i),len$(linkname(i)))
			e = writejson(h,jc," ",0)
		next i
		e = writejson(h,jc," ",0)
		e = writejson(h,jc," ",0)
		llink=1,(N):next,e,buffer
	wend
	e = writejson(h,jc," ",0)

	e = writejson(h,jn,"records",len$("records"))
	e = writejson(h,js," ",0)
	SvSi(1,filename,rsize,ksize)
	savename = Print(($,$),filename,".u")
	e = writejson(h,jn,"name",len$("name"))
	e = writejson(h,jv,savename,len$(savename))
	e = writejson(h,jc," ",0)
	e = writejson(h,jc," ",0)
	h = closejson(h)

	close=1:next,e
	stop
eseg 0
end

	
