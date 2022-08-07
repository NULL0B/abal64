program "svsi",noclr
extern proc SvSi(handle%,filename$=256,rl%,kl%,kt%) : %
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
dcl	filename$=256
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
	assign=1,filename,si,ex:next,e
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
	SvSi(1,filename,rsize,ksize,ktype)
	close=1:next,e
	stop
eseg 0
end

	
