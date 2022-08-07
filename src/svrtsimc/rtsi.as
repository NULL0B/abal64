program "rtsi", noclr
extern proc RtSi(handle%,filename$=256,cflags%) : %
dcl	doit%
dcl	e%
dcl	t%
dcl	h%
dcl	filename$=256
dcl	jsonname$=256
dcl	buffer$=2048
dcl	keyword$=2048
arg	filename

dcl	ksize%
dcl	ktype%
dcl	rsize%

segment 0
	;** collect filename

	While ( index(filename,chr$(/0D)) <> 0 ) 
		filename = includ( index(filename,chr$(/0D)) , " ", 1)
	wend

	if ( Len$(filename) =0 )
		print=1:(/1,$),"RT MC Abal 64 : Version 1.0a"
		print=1:(/1,$,/1),"Copyright (c) 2022 Amenesik / Sologic "
		stop
	endif

	RtSi(44,filename,1) 
eseg 0
end


