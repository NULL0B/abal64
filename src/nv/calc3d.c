struct	coordinates {
	int	x;
	int	y;
	int	z;
	};

struct	vector {
	int	x;
	int	y;
	};

static	coordinates ThreeD[8];
static	vector	    TwoD[8];

private	coordinates Camera;
private	coordinates Largest;
private	coordinates Smallest;

/*	Directional masks 				*/
/*	These may need to be combined later on		*/

#define	_LOOKING_PZ	0x0001
#define	_LOOKING_NZ	0x0002
#define	_LOOKING_PY	0x0004
#define	_LOOKING_NY	0x0008
#define	_LOOKING_PX	0x0010
#define	_LOOKING_NX	0x0020

#define	_RIGHT_VISIBLE		0x0001
#define	_LOWER_VISIBLE		0x0002
#define	_UPPER_VISIBLE		0x0004
#define	_LEFT_VISIBLE		0x0008
#define	_FRONT_VISIBLE		0x0010
#define	_BACK_VISIBLE		0x0020

#define	_RIGHT_NOT_VISIBLE	0x00FE
#define	_LOWER_NOT_VISIBLE	0x00FD
#define	_UPPER_NOT_VISIBLE	0x00FB
#define	_LEFT_NOT_VISIBLE	0x00F7
#define	_FRONT_NOT_VISIBLE	0x00EF
#define	_BACK_NOT_VISIBLE	0x00DF

#define	_RIGHT_IS_VALID		0x00AA
#define	_LOWER_IS_VALID		0x00CC
#define	_UPPER_IS_VALID		0x0033
#define	_LEFT_IS_VALID		0x0055
#define	_FRONT_IS_VALID		0x000F
#define	_BACK_IS_VALID		0x00F0

a_x	equ	10
a_y	equ	12
b_x	equ	14
b_y	equ	16
c_x	equ	18
c_y	equ	20
d_x	equ	22
d_y	equ	24
e_x	equ	26
e_y	equ	28
f_x	equ	30
f_y	equ	32
g_x	equ	34
g_y	equ	36
h_x	equ	38
h_y	equ	40

prepare_pz_vector	proc	near

	put_tx
	put_ty
	put_tz

	put_bx
	put_ty
	put_tz

	put_tx
	put_by
	put_tz

	put_bx
	put_by
	put_tz

	put_tx
	put_ty
	put_bz

	put_bx
	put_ty
	put_bz

	put_tx
	put_by
	put_bz

	put_bx
	put_by
	put_bz
	ret
prepare_pz_vector	endp

prepare_px_vector	proc	near

	put_bz
	put_ty
	put_tx

	put_tz
	put_ty
	put_tx

	put_bz
	put_by
	put_tx

	put_tz
	put_by
	put_tx

	put_bz
	put_ty
	put_bx

	put_tz
	put_ty
	put_bx

	put_bz
	put_by
	put_bx

	put_tz
	put_by
	put_bx
	ret
prepare_px_vector	endp

vector_conversions	dw	offset _TEXT:convert_pz_vector
			dw	offset _TEXT:convert_px_vector
vector_preparation	dw	offset _TEXT:prepare_pz_vector
			dw	offset _TEXT:prepare_px_vector




;control_3dx	proc	near
;	cmp	bx,319
;	jle	c3dx1
;	mov	bx,319
;c3dx1:	cmp	bx,0
;	jge	c3dx2
;	xor	bx,bx
;c3dx2:	ret
;control_3dx	endp

;control_3dy	proc	near
;	cmp	bx,199
;	jle	c3dy1
;	mov	bx,199
;c3dy1:	cmp	bx,0
;	jge	c3dy2
;	xor	bx,bx
;c3dy2:	ret
;control_3dy	endp


;**	-------------------------------------
;**	Viewing Along the Z Axis towards Zero
;**	-------------------------------------
;**
;**	Entry	:
;**	
;**		DS		Local DS
;**		DS:SI	->	3D Vector To Convert X+0, Y+2, Z+4
;**		ES:DI   ->	2D Vector Result     X+0, Y+2
;**		DH		Current Invalid Bit Collection
;**		DL		Current Invalid Bit Flag
;**
;**	Note : 	The CX register is preserved between the X and Y
;**		factor calculations and is quite fragile !
;**

convert_pz_vector	proc	near

;**	X Component Calculation
;**	-----------------------
	mov	ax,word ptr ds:[Ex3d]		; Camera.X
	xchg	ah,al
	mov	bx,word ptr ds:[si]		; Vortex.X
	xchg	bh,bl
	sub	ax,bx				; Calculate Difference

	mov	bx,word ptr ds:[si][+4]		; Vortex.Z
	xchg	bh,bl				; Correct from ABAL WORD
	mov	cx,word ptr ds:[Ez3d]		; Camera.Z
	xchg	ch,cl				; Correct from ABAL WORD
	cmp	bx,cx				; Test for Equal Z distance
	je	pzxok				; means X factor is ready

cpzv1a:	cmp	bx,128				; Test for Excesive Weight
	jb	cpzv1b				; Ok if reasonable
	shr	bx,1				; Reduce both Point and
	shr	cx,1				; Camera values by power of 2
	jmp	cpzv1a				; and repeat till reasonable

cpzv1b:	push	dx
	imul	bx				; Calculate differentiel
	idiv	cx				; x' = x * z' / Z
	pop	dx

pzxok:	push	bx				; Save Vortex Z
	mov	bx,word ptr [FocusX]		; Center of visible X axis
	sub	bx,ax				; Adjust by x' value
	mov	es:word ptr[di],bx		; and store to result
	cmp	bx,word ptr [ClipTX]		
	jge	pzxv1				; < 0 then Invalid
	or 	dh,dl				; Set Invalid Bit
	mov	bx,word ptr [ClipTX]		; limit to lower value
	jmp short pzxval

pzxv1:	cmp	bx,word ptr [ClipBX]		; Test for upper limit 319
	jle 	pzxval				; Less so OK
	or	dh,dl				; Set invalid Bit
	mov	bx,word ptr [ClipBX]		; Limit to upper value 319

pzxval:	add	di,2				; Advance Result Pointer

;**	Adjust Zone Saver Extremities
;**	-----------------------------
	cmp	bx,word ptr ds:[Tx2d]		
	jge	cpzv1
	mov	word ptr ds:[Tx2d],bx
cpzv1:	cmp	bx,word ptr ds:[Bx2d]
	jle	cpzv2
	mov	word ptr ds:[Bx2d],bx

;**	Y Component Calculation
;**	-----------------------
cpzv2:
	mov	ax,word ptr ds:[Ey3d]		; Get Camera Y value
	xchg	ah,al				; Correct from ABAL
	mov	bx,word ptr ds:[si][+2]		; Get Vortex Y value
	xchg	bh,bl				; Correct from ABAL
	sub	ax,bx				; Calculate difference
	pop	bx				; Recover Vortex Z, Camera Z
	jz	pzyok				; No difference so OK
						; Should still be in CX !!!
	cmp	bx,cx				; Test for Equality
	je	pzyok				; Equal so Y value ready

cpzv2b:	push	dx
	imul	bx				; Perform Y differential
	idiv	cx				; calculation y' = y * z' / Z
	pop	dx

pzyok:	mov	bx,word ptr [FocusY]		; Center of Visible Y Axis
	sub	bx,ax				; Calculate Point Y value
	mov	es:word ptr[di],bx		; and store to result
	cmp	bx,word ptr [ClipTY]
	jge	pzyv2				; < 0 then Invalid
	or 	dh,dl				; Set Invalid Bit
	mov	bx,word ptr [ClipTY]		; limit to lower value
	jmp short pzyval

pzyv2:	cmp	bx,word ptr [ClipBY]		; Test for upper limit 199!320
	jle 	pzyval				; Less so OK
	or	dh,dl				; Set invalid Bit
	mov	bx,word ptr [ClipBY]		; Limit to upper value 199
pzyval:	add	di,2				; Adjust result pointer

;**	Adjust Zone Saver Extremities
;**	-----------------------------
	cmp	bx,word ptr ds:[Ty2d]
	jge	cpzv3
	mov	word ptr ds:[Ty2d],bx
cpzv3:	cmp	bx,word ptr ds:[By2d]
	jle	cpzv4
	mov	word ptr ds:[By2d],bx
cpzv4:	ret
convert_pz_vector	endp

convert_px_vector	proc	near
	mov	ax,word ptr ds:[Ez3d]		; Camera.Z
	xchg	ah,al
	mov	bx,word ptr ds:[si]		; Vortex.Z
	xchg	bh,bl
	sub	ax,bx				; Calculate Difference
	
	mov	cx,word ptr ds:[si][+4]		; Vortex.X
	xchg	ch,cl
	mov	bx,2048
	sub	bx,cx
	mov	dx,word ptr ds:[Ex3d]		; Camera.X
	xchg	dh,dl
	mov	cx,2048
	sub	cx,dx
cpxv1a:	cmp	bx,128
	jb	cpxv1b
	shr	bx,1
	shr	cx,1
	jmp	cpxv1a
cpxv1b:	imul	bx
	idiv	cx
	mov	bx,160
	sub	bx,ax
	mov	es:word ptr[di],bx
	add	di,2
	cmp	bx,word ptr ds:[Tx2d]
	jge	cpxv1
	mov	word ptr ds:[Tx2d],bx
cpxv1:	cmp	bx,word ptr ds:[Bx2d]
	jle	cpxv2
	mov	word ptr ds:[Bx2d],bx
cpxv2:	mov	ax,word ptr ds:[Ey3d]
	xchg	ah,al
	mov	bx,word ptr ds:[si][+2]
	xchg	bh,bl
	sub	ax,bx
	
	mov	cx,word ptr ds:[si][+4]		; Vortex.X
	xchg	ch,cl
	mov	bx,2048
	sub	bx,cx
	mov	dx,word ptr ds:[Ex3d]		; Camera.X
	xchg	dh,dl
	mov	cx,2048
	sub	cx,dx
cpxv2a:	cmp	bx,128
	jb	cpxv2b
	shr	bx,1
	shr	cx,1
	jmp	cpxv2a
cpxv2b:	imul	bx
	idiv	cx
	mov	bx,100
	sub	bx,ax
	mov	es:word ptr[di],bx
	add	di,2
	cmp	bx,word ptr ds:[Ty2d]
	jge	cpxv3
	mov	word ptr ds:[Ty2d],bx
cpxv3:	cmp	bx,word ptr ds:[By2d]
	jle	cpxv4
	mov	word ptr ds:[By2d],bx
cpxv4:	ret
convert_px_vector	endp

prepare_2d_result	proc	near
	push	di				; Save Result Pointer
	add	di,10				; Step over prefix
	mov	cx,8				; 8 conversions required
	xor	dx,dx				; Clear Invalid Bits
	inc	dx				; Set Invalid Bit Mask
p3dr:	push	cx				; Save Counter
	add	si,6				; Advance to first vector
	call	word ptr [ConvertVector]	; Perform Conversion
	shl	dl,1				; Advance Invalid Bit Mask
	pop	cx				; Recover Counter
	loop	p3dr				; And repeat while more
	pop	di				; Recover Result pointer
	xor	dh,0FFH				; Invert Invalid Bits
	xor	dl,dl				; Clear  Visible Bits

;**	Clip Screen saver Zone	and Detect Visibles
;**	-------------------------------------------
	mov	cx,word ptr ds:[Tx2d]
	cmp	cx,word ptr es:[di][+26]	; e.x == tx ??? Left Visible
	jne	ttx2d
	or	dl,8				; Left is Visible
ttx2d:	call	clipx
	mov	ax,cx
	mov	cx,word ptr ds:[Bx2d]
	cmp	cx,word ptr es:[di][+38]	; h.x == bx ??? Right Visible
	jne	tbx2d
	or	dl,1				; Right is Visible
tbx2d:	call	clipx
	sub	cx,ax				; Calculate Columns to Save
	inc	cx
	xchg	ah,al
	mov	word ptr es:[di],ax		; Store Result Top Left X
	xchg	ch,cl
	mov	word ptr es:[di][+4],cx		; Store Result Column Count

	mov	cx,word ptr ds:[Ty2d]
	cmp	cx,word ptr es:[di][+28]	; e.y == ty ??? Top Visible
	jne	tty2d
	or	dl,4				; Top is Visible
tty2d:	call	clipy				; Perform Screen Clipping
	mov	ax,cx
	mov	cx,word ptr ds:[By2d]
	cmp	cx,word ptr es:[di][+40]	; e.y == ty ??? Bottom Visible
	jne	tby2d
	or	dl,2				; Bottom is Visible
tby2d:	call	clipy				; Perform Screen Clipping
	sub	cx,ax				; Calculate Columns to save
	inc	cx				; Adjust from Zero
	xchg	ah,al				; Adjust for ABAL
	mov	word ptr es:[di][+2],ax		; Store Result Top Left Y
	xchg	ch,cl				; Adjust for ABAL
	mov	word ptr es:[di][+6],cx		; Store Rows to Save

	test	dh,_LEFT_IS_VALID
	jnz	final1
	and	dl,_LEFT_NOT_VISIBLE
final1:
	test	dh,_RIGHT_IS_VALID
	jnz	final2
	and	dl,_RIGHT_NOT_VISIBLE
final2:
	test	dh,_UPPER_IS_VALID
	jnz	final3
	and	dl,_UPPER_NOT_VISIBLE
final3:
	test	dh,_LOWER_IS_VALID
	jnz	final4
	and	dl,_LOWER_NOT_VISIBLE
final4:
	test	dh,_FRONT_IS_VALID
	jz	final5
	or	dl,_FRONT_VISIBLE
final5:	xor	dh,dh
	mov	word ptr es:[di][+8],dx
	ret
prepare_2d_result	endp


/* Looking Negative along Z axis towards and beyond ZERO */
/* ----------------------------------------------------- */

private	void	NZConversion()	
{
	int	vortex;
	ThreeD[0].x = ThreeD[2].x = ThreeD[4].x = ThreeD[6].x = Smallest.x;
	ThreeD[1].x = ThreeD[3].x = ThreeD[5].x = ThreeD[7].x = Largest.x;

	ThreeD[0].y = ThreeD[1].y = ThreeD[4].y = ThreeD[5].y = Smallest.y;
	ThreeD[2].y = ThreeD[3].y = ThreeD[6].y = ThreeD[7].y = Largest.y;

	ThreeD[4].z = ThreeD[5].z = ThreeD[6].z = ThreeD[7].z = Smallest.z;
	ThreeD[0].z = ThreeD[1].z = ThreeD[2].z = ThreeD[3].z = Largest.z;

	for ( vortex=0; vortex < 8; vortex++ ) {
		TwoD[vortex].x = ((ThreeD[vortex].x * ThreeD[vortex].z) / Camera.z);
		TwoD[vortex].y = ((ThreeD[vortex].y * ThreeD[vortex].z) / Camera.z);
		}
	return;
}

/* Looking Negative along Y axis towards and beyond ZERO */
/* ----------------------------------------------------- */

private	void	NYConversion()	
{
	int	vortex;
	ThreeD[0].x = ThreeD[2].x = ThreeD[4].x = ThreeD[6].x = Smallest.x;
	ThreeD[1].x = ThreeD[3].x = ThreeD[5].x = ThreeD[7].x = Largest.x;

	ThreeD[4].y = ThreeD[5].y = ThreeD[6].y = ThreeD[7].y = Smallest.y;
	ThreeD[0].y = ThreeD[1].y = ThreeD[2].y = ThreeD[3].y = Largest.y;

	ThreeD[0].z = ThreeD[1].z = ThreeD[4].z = ThreeD[5].z = Largest.z;
	ThreeD[2].z = ThreeD[3].z = ThreeD[6].z = ThreeD[7].z = Smallest.z;

	for ( vortex=0; vortex < 8; vortex++ ) {
		TwoD[vortex].x = ((ThreeD[vortex].x * ThreeD[vortex].y) / Camera.y);
		TwoD[vortex].y = ((ThreeD[vortex].z * ThreeD[vortex].y) / Camera.y);
		}
	return;
}

/* Looking Negative along Z axis towards and beyond ZERO */
/* ----------------------------------------------------- */

private	void	NXConversion()	
{
	int	vortex;
	ThreeD[4].x = ThreeD[5].x = ThreeD[6].x = ThreeD[7].x = Smallest.x;
	ThreeD[0].x = ThreeD[1].x = ThreeD[2].x = ThreeD[3].x = Largest.x;

	ThreeD[0].y = ThreeD[1].y = ThreeD[4].y = ThreeD[5].y = Smallest.y;
	ThreeD[2].y = ThreeD[3].y = ThreeD[6].y = ThreeD[7].y = Largest.y;

	ThreeD[1].z = ThreeD[3].z = ThreeD[5].z = ThreeD[7].z = Smallest.z;
	ThreeD[0].z = ThreeD[2].z = ThreeD[4].z = ThreeD[6].z = Largest.z;
	for ( vortex=0; vortex < 8; vortex++ ) {
		TwoD[vortex].x = ((ThreeD[vortex].z * ThreeD[vortex].x) / Camera.x);
		TwoD[vortex].y = ((ThreeD[vortex].y * ThreeD[vortex].x) / Camera.x);
		}
	return;
}

/* Looking Posative along Z axis away from ZERO */
/* -------------------------------------------- */

private	void	PZConversion()	
{
	int	vortex;
	ThreeD[0].x = ThreeD[2].x = ThreeD[4].x = ThreeD[6].x = Largest.x;
	ThreeD[1].x = ThreeD[3].x = ThreeD[5].x = ThreeD[7].x = Smallest.x;

	ThreeD[0].y = ThreeD[1].y = ThreeD[4].y = ThreeD[5].y = Smallest.y;
	ThreeD[2].y = ThreeD[3].y = ThreeD[6].y = ThreeD[7].y = Largest.y;

	ThreeD[4].z = ThreeD[5].z = ThreeD[6].z = ThreeD[7].z = Largest.z;
	ThreeD[0].z = ThreeD[1].z = ThreeD[2].z = ThreeD[3].z = Smallest.z

	for ( vortex=0; vortex < 8; vortex++ ) {
		TwoD[vortex].y = ((ThreeD[vortex].x * Camera.z) / ThreeD[vortex].z);
		TwoD[vortex].x = ((ThreeD[vortex].y * Camera.z) / ThreeD[vortex].z);
		}
	return;
}

/* Looking Posative along Y axis away from Zero */
/* -------------------------------------------- */

private	void	PYConversion()	
{
	int	vortex;
	ThreeD[0].x = ThreeD[2].x = ThreeD[4].x = ThreeD[6].x = Smallest.x;
	ThreeD[1].x = ThreeD[3].x = ThreeD[5].x = ThreeD[7].x = Largest.x;

	ThreeD[0].y = ThreeD[1].y = ThreeD[2].y = ThreeD[3].y = Smallest.y;
	ThreeD[4].y = ThreeD[5].y = ThreeD[6].y = ThreeD[7].y = Largest.y;

	ThreeD[0].z = ThreeD[1].z = ThreeD[4].z = ThreeD[5].z = Smallest.z;
	ThreeD[2].z = ThreeD[3].z = ThreeD[6].z = ThreeD[7].z = Largest.z;
	for ( vortex=0; vortex < 8; vortex++ ) {
		TwoD[vortex].y = ((ThreeD[vortex].x * Camera.y) / ThreeD[vortex].y);
		TwoD[vortex].x = ((ThreeD[vortex].y * Camera.y) / ThreeD[vortex].y);
		}

	return;
}

/* Looking Posative along X axis away from ZERO */
/* -------------------------------------------- */

private	void	PXConversion()	
{
	int	vortex;
	ThreeD[4].x = ThreeD[5].x = ThreeD[6].x = ThreeD[7].x = Largest.x;
	ThreeD[0].x = ThreeD[1].x = ThreeD[2].x = ThreeD[3].x = Smallest.x;

	ThreeD[0].y = ThreeD[1].y = ThreeD[4].y = ThreeD[5].y = Smallest.y;
	ThreeD[2].y = ThreeD[3].y = ThreeD[6].y = ThreeD[7].y = Largest.y;

	ThreeD[1].z = ThreeD[3].z = ThreeD[5].z = ThreeD[7].z = Largest.z;
	ThreeD[0].z = ThreeD[2].z = ThreeD[4].z = ThreeD[6].z = Smallest.z;
	for ( vortex=0; vortex < 8; vortex++ ) {
		TwoD[vortex].y = ((ThreeD[vortex].z * Camera.x) / ThreeD[vortex].x);
		TwoD[vortex].x = ((ThreeD[vortex].y * Camera.x) / ThreeD[vortex].x);
		}
	return;
}

/*	-------------------------------------------------------		*/
/*	BOOLEAN IS_VISIBLE( CAMERA, TOP CORNER, BOTTOM CORNER )		*/
/*	-------------------------------------------------------		*/

private	int	is_visible()
{
	/* ---------------------------------------------------------- */
	/* Ensure bottom corner is visible (rather primitive means !) */
	/* For the moment we assume that the camera is looking to +Z  */
	/* ---------------------------------------------------------- */
	switch ( Direction ) {
		case	_LOOKING_PZ	:
			if ( Camera.z < Largest.z )
				return(1);
			else	return(0);
		case	_LOOKING_NZ	:
			if ( Camera.z > Smallest.z )
				return(1);
			else	return(0);
		case	_LOOKING_PY	:
			if ( Camera.y < Largest.y )
				return(1);
			else	return(0);
		case	_LOOKING_NY	:
			if ( Camera.y > Smallest.y )
				return(1);
			else	return(0);
		case	_LOOKING_PX	:
			if ( Camera.x < Largest.x )
				return(1);
			else	return(0);
		case	_LOOKING_NX :
			if ( Camera.x > Smallest.x )
				return(1);
			else	return(0);
		default			:
			return( 0 );
		}
}


public	int	calc3d	(	 
	numeric     * rptr,	/* Results of Calculation	*/
	coordinates * eptr,	/* Eye or Camera Coords		*/
	coordinates * aptr,	/* Top Left Coords		*/
	coordinates * bptr,  	/* Bottom Right Coords		*/
	int	      direction)
{
	int	n;

	/* Reset Results Descriptor */
	/* ------------------------ */
	for (n=0; n < 5; n++)
		results[n] = 0;	/* Exists with es:di -> results */

	/* Set Largest and Smallest of the Coordinates in place */
	/* ---------------------------------------------------- */
	if ( aptr->x < bptr->x ) {
		Smallest.x = aptr->x; Largest.x = bptr->x;
		}
	else	{
		Smallest.x = bptr->x; Largest.x = aptr->x;
		}
	if ( aptr->y < bptr->y ) {
		Smallest.y = aptr->y; Largest.y = bptr->y;
		}
	else	{
		Smallest.y = bptr->y; Largest.y = aptr->y;
		}
	if ( aptr->z < bptr->z ) {
		Smallest.z = aptr->z; Largest.z = bptr->z;
		}
	else	{
		Smallest.z = bptr->z; Largest.z = aptr->z;
		}

	Direction = direction;
	Camera.x = eptr->x; Camera.y = eptr->y; Camera.z = eptr->z; 

	if ( is_visible()  ) {

		Largest.x = tptr->x; Largest.y = tptr->y; Largest.z = tptr->z;
		Smallest.x = bptr->x; Smallest.y = bptr->y; Smallest.z = bptr->z;

		switch ( Direction ) {
			case	_LOOKING_PZ : PZConversion(); break;
			case	_LOOKING_NZ : NZConversion(); break;
			case	_LOOKING_PY : PYConversion(); break;
			case	_LOOKING_NY : NYConversion(); break;
			case	_LOOKING_PX : PXConversion(); break;
			case	_LOOKING_NX : NXConversion(); break;
			}
		return(1);
		}
	else	return(0);
}



