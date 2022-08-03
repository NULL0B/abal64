Module	"rtsi"
#files 	128
;**	----------------
;** 	RTSI as a Module
;**	----------------

Proc	RtSi(handle%,filename$=256,cflag%) : %

;**	-----------------
;**	general variables
;**	-----------------
	Dcl	byte#
	Dcl	offset%
	Dcl	n%
	Dcl	dlen%
	Dcl	e%
	Dcl	number=8

;**	----------------------
;**	header block structure
;**	----------------------
	Dcl	header$=256
	Field=m,header
		DCL version#
		DCL version2#
		DCL version3#
		DCL seven$=7
		DCL bits#(3)
		DCL klen#
		DCL other#
		DCL zc$=50
	field=m

;**	----------
;**	data block 
;**	----------
	Dcl	sector$=256
	Field=m,sector
		Dcl	d#(256)
	Field=m,sector
		Dcl	chars#(256)
	Field=m

;**	-----------------
;**	output management
;**	-----------------
	Dcl	backname$=256
	Dcl	size%
	Field=m,size
		Dcl 	hi#
		Dcl	lo#
	Field=m
	Dcl	primary$=256
	Field=m,primary
		Dcl k#(256)
	Field=m
	Dcl	mq#
	Dcl	buffer$=32000
	Field=m,buffer
		Dcl b#(32000)
	Field=m
	EndLoc

;**	------------------------
;**	process the header block
;**	------------------------
	backname = Print(($,$),filename,".u")
	offset = 257
	gosub &first
	if ( e <> 0 ) :: Exit(e) :: endif
	gosub &infos
	if ( e <> 0 ) :: Exit(e) :: endif

;**	-------------------------------
;**	create the new file if required 
;**	-------------------------------
	if ( cflag <> 0 )
		Assign=handle,filename,SI,WR:Next,e
		Dfile=handle:Next,e
		Cfile=handle,D=dlen,K=klen:Next,e
		if ( e <> 0 ) :: Exit(e) :: endif
	Endif

;**	-----------------------------
;**	process the input data blocks
;**	-----------------------------
	while ( e = 0 )
		gosub &getlength
		if ( size = -1 ) :: Break :: Endif
		gosub &getkey
		gosub &getmq
		gosub &getdata
		Insert=handle,primary,mq:Next,e,buffer,dlen
		if ( e <> 0 ) :: Exit(e) :: endif
	wend
	Exit( 0 )

;** 	--------------------------
;**	retrieve the record length 
;** 	--------------------------
&getlength
	gosub &getbyte
	hi = byte
	gosub &getbyte
	lo = byte
	return

;**	------------------------
;** 	retrieve the primary key
;**	------------------------
&getkey
	For n = 1 to klen
		gosub &getbyte
		k(n) = byte
	Next n
	return

;**	-------------------
;**	retrieve the marker
;**	-------------------
&getmq
	gosub &getbyte
	mq = byte
	return

;**	-----------------
;**	retrieve the data
;**	-----------------
&getdata
	For n = 1 to dlen
		gosub &getbyte
		b(n) = byte
	Next n
	return

;**	-----------------
;**	get an input byte
;**	-----------------
&getbyte
	byte = 0
	if ( offset > 256 )
		gosub &next
		if ( e <> 0 )
			return
		Else :: offset = 1
		endif
	endif
	byte = d(offset)
	offset = offset + 1
	return

;**	--------------------
;**	get file information
;**	--------------------
&infos
	header = sector
	dlen = (bits(1) and /00FF) + ((bits(2) and /00FF) * 256)
	klen = -klen
	return

;**	----------------------
;**	read information block
;**	----------------------
&first
	Assign=99,backname:Next,e
	Open=99:Next,e
	if ( e = 0 )
		number = 0
		gosub &read
	endif
	return

;**	-----------------
;**	read a data block 
;**	-----------------
&next
	number = number + 1
	gosub &read
	return

;**	-------------------
;**	read an input block
;**	-------------------
&read
	read=99,/60,number:Next,e,sector,256
	return

Endproc

End

	
