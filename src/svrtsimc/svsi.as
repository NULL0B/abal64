Module	"svsi"
#files  128
;**	----------------
;** 	SVVI as a Module
;**	----------------

Proc	SvSi(handle%,filename$=256,rl%,kl%) : %

;**	-----------------
;**	general variables
;**	-----------------
	Dcl	byte#
	Dcl	offset%
	Dcl	n%
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

;**	-----------------------------
;**	Process the Records to Output
;**	-----------------------------
	Close=handle:Next,e
	Down=handle,/FF:Next,e,buffer,rl+kl+1
	While ( e = 0 )
		gosub &putlength
		gosub &putkey
		gosub &putmq
		gosub &putdata
		Down=handle,/FF:Next,e,buffer,rl+kl+1
	Wend
	gosub &next
	Exit( 0 )

;** 	--------------------------
;**	store the record length 
;** 	--------------------------
&putlength
	size = rl
	byte = hi
	gosub &putbyte
	byte = lo
	gosub &putbyte
	return

;**	------------------------
;** 	store the primary key
;**	------------------------
&putkey
	For n = 1 to kl
		byte = b(n)
		gosub &putbyte
	Next n
	return

;**	-------------------
;**	store the marker
;**	-------------------
&putmq
	byte = b(kl+1)
	gosub &putbyte
	return

;**	-----------------
;**	store the data
;**	-----------------
&putdata
	For n = 1 to rl
		byte = b(kl+n+1)
		gosub &putbyte
	Next n
	return

;**	-----------------
;**	get an input byte
;**	-----------------
&putbyte
	if ( offset > 255 )
		gosub &next
		if ( e <> 0 )
			return
		Else :: offset = 0
		endif
	endif
	offset = offset + 1
	d(offset) = byte
	return

;**	--------------------
;**	use file information
;**	--------------------
&infos
	bits(1) = rl and /00FF
	bits(2) = ((rl/256) and /00FF)
	klen = kl
	klen = -klen
	sector = header
	return

;**	-----------------------
;**	write information block
;**	-----------------------
&first
	Assign=99,backname,WR,EX:Next,e
	Open=99:Next,e
	if ( e = 0 ) :: Dfile=99:Next,e :: Endif
	Cfile=99:Next,e
	if ( e = 0 )
		gosub &reset
		gosub &infos
		number = 0
		gosub &write
	endif
	return

;** 	-----------------------
;**	reset the sector buffer
;** 	-----------------------
&reset
	sector = gener(256,Chr$(0))
	offset = 0
	return

;**	------------------
;**	write a data block 
;**	------------------
&next
	number = number + 1
	gosub &write
	return

;**	-------------------
;**	read an input block
;**	-------------------
&write
	write=99,/A0,number:Next,e,sector,256
	gosub &reset
	return

Endproc

End

	
