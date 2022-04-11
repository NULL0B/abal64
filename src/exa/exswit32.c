/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R   A B A L				*/
/*		----------------------------				*/
/*									*/
/*		Copyright (c) 1987,1996 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXSWIT32.C	 			*/
/*		Version :	3.1a					*/
/*		Date 	:	03/12/2002				*/
/*									*/
/*----------------------------------------------------------------------*/
/* NB This is an include file for both EXMOTOR-C and EXDBMOTO-C		*/
/*----------------------------------------------------------------------*/
/* This file has been copied from EXSWIT.C and modified for all 32 bit	*/
/* instructions								*/
/*----------------------------------------------------------------------*/

/* ESCAPE (SEQUENCE) EXTENSION : ABAL 3 : 32 Bit Codes
 * ---------------------------------------------------
 */

case _tc32_GIS	: 
	balputw( freg [ *fdex ] , (GlobalDataSegment + (TcodeWord32( (fdex + 1)))));
	fdex += (WORD32SIZE + 1); break;
case _tc32_LIS	: 
	balputw( freg [ *fdex ] , (LocalDataSegment + (TcodeWord32( (fdex + 1)))));
	fdex += (WORD32SIZE + 1); break;


case _tc32_GIL	:
	freg [ (e = *fdex) ] = balgetw( ( GlobalDataSegment + (TcodeWord32( (fdex + 1) ) ) ));
	xreg [e] = IMMEDIAT;
	fdex += (WORD32SIZE + 1); continue;
case _tc32_LIL	:
	freg [ (e = *fdex) ] = balgetw( ( LocalDataSegment + (TcodeWord32( (fdex + 1)) ) ));
	xreg [e] = IMMEDIAT;
	fdex += (WORD32SIZE + 1); continue;
case _tc32_GCL	:
	if ( ExFlgSgn == 0 ) {
		freg [ (e = *fdex) ] = (BINAIRE) ReadSchar( ( GlobalDataSegment + (TcodeWord32( (fdex + 1) ) ) ));
		}
	else	{
		ExFlgSgn = 0;
		freg [ (e = *fdex) ] = (EXAWORD) *((BPTR) ( GlobalDataSegment + (TcodeWord32( (fdex + 1) ) ) ));
		}
	xreg [e] = CHARONLY;
	fdex += (WORD32SIZE + 1); continue;
case _tc32_LCL	:
	if ( ExFlgSgn == 0 ) {
		freg [ (e = *fdex) ] = (BINAIRE) ReadSchar( ( LocalDataSegment + (TcodeWord32( (fdex + 1)) ) ));
		}
	else	{
		ExFlgSgn = 0;
		freg [ (e = *fdex) ] = (EXAWORD) *((BPTR) ( LocalDataSegment + (TcodeWord32( (fdex + 1)) ) ));
		}
	xreg [e] = CHARONLY;
	fdex += (WORD32SIZE + 1); continue;
case _tc32_GCS	:
	*((CPTR) (GlobalDataSegment + (TcodeWord32( (fdex + 1) )))) = (char)( freg [ *fdex ]);
	fdex += (WORD32SIZE + 1); break;
case _tc32_LCS	:
	*((CPTR) (LocalDataSegment + (TcodeWord32( (fdex + 1) )))) = (char)( freg [ *fdex ]);
	fdex += (WORD32SIZE + 1); break;

 /* LOAD REGISTER IMMEDIATE VALUE #REGISTER IVALUE
  * -----------------------------------------------
  * Loads the Immediate integer value IVALUE into the register #REGISTER
  * and sets the status field to 0 indicating an Integer value.
  */
case _tc32_LDI	:
	freg [ (e = (EXAWORD) *fdex) ] = TcodeWord32( (fdex + 1) );
	xreg [ e ] = IMMEDIAT; fdex += ( WORD32SIZE + 1);  continue;

 /* LOAD 1st Index REGISTER IMMEDIATE VALUE #REGISTER IVALUE
  * --------------------------------------------------------
  * Loads the Immediate integer value IVALUE into the 1st index field 
  * of the register #REGISTER .
  */
case _tc32_LXI	:
	ireg [(e = *fdex)] = TcodeWord32( (fdex + 1)); 
	fdex += (WORD32SIZE + 1); 
	if ( xreg [e] & PTRSTATUS ) {	xreg [ e ] = VARIABLE; }
	continue;

 /* LOAD 2nd Index REGISTER IMMEDIATE VALUE #REGISTER IVALUE
  * --------------------------------------------------------
  * Loads the Immediate integer value IVALUE into the 2nd index field 
  * of the register #REGISTER .
  */
case _tc32_AXI	:
	areg [(e = *fdex)] = TcodeWord32( (fdex + 1)); 
	fdex += (WORD32SIZE + 1); 
	if ( xreg [e] & PTRSTATUS ) {	xreg [ e ] = VARIABLE; }
	continue;

/* GOSUB &ADRESSE
 * --------------
 * Transfers control to the adresse &ADRESSE and saves the current adresse
 * on the stack for the return.
 */
case	_tc32_GSB	:

	if (ip_next >= diezstk) { err_val = ABAL_GSB2MANY; tcode = SOFTERROR; }
	else	{
		ip_hold [ (ip_next++) ] = (EXAWORD) (fdex + 2 - TcodeSegment); 
		fdex = (BPTR) (TcodeSegment + TcodeWord32( fdex));
		}
	continue;


/* GOTO	IVALUE
 * -----------
 * Unconditional jump to the adresse represented by IVALUE
 */
case _tc32_JMI	:	fdex = (BPTR) (TcodeSegment + TcodeWord32( fdex));
			continue;

/* STORE IVALUE to [VARPTR]
 * ------------------------
 * Saves the immediate value IVALUE to the variable pointed by
 * [VARPTR] with automatic type conversion if necessary.
 */ 
case _tc32_STI	:	/* STORE Integer to Variable */
	e = TcodeWord32(fdex); fdex += WORD32SIZE;
ITOVARB:
	if ( (tcode = TcodeWord32( fdex )) & ISLOCAL ) {
		workptr2 = LocalDataTable + ( tcode & TOGLOBAL );
		workptr1 = LocalDataSegment;
		}
	else	{
		workptr2 = GlobalDataTable + tcode;
		workptr1 = GlobalDataSegment;
		}
	fdex += WORD32SIZE;
	switch ( TcodeWord32( workptr2 ) ) {
		case	0x0068 :
		case	0x0060 : /* #(x,y)	*/
			CheckAreg( 0 , workptr2 );
			workptr1 += ( (areg [0] - 1) * (TcodeWord32( (workptr2 + (2 * WORD32SIZE)))));
		case	0x0048 :
		case	0x0040 : /* #(x)	*/
			CheckIreg( 0 , workptr2 );
			workptr1 += (ireg [0] - 1);
		case	0x0008 :
		case	0x0000 : /* #		*/
			*((CPTR) (workptr1 + (TcodeWord32( (workptr2 + WORD32SIZE))))) = (char) e; continue;
		case	0x0069 :
		case	0x0061 : /* %(x,y)	*/
			CheckAreg( 0 , workptr2 );
			workptr1 += ( ((areg [0] - 1) * 2) * (TcodeWord32( (workptr2 + (2 * WORD32SIZE)))));
		case	0x0049 :
		case	0x0041 : /* %(x)	*/
			CheckIreg( 0 , workptr2 );
			workptr1 += ((ireg [0] - 1) * 2);
		case	0x0009 :
		case	0x0001 : 
			balputw( e , ( workptr1 + (TcodeWord32( (workptr2 + WORD32SIZE) ) ) )); continue;
		case	0x006A :
		case	0x0062 : /* BCD(x,y)	*/
			CheckAreg( 0 , (workptr2 + WORD32SIZE));
			workptr1 += ( ((areg [0] - 1) * (TcodeWord32( (workptr2 + ( 2 * WORD32SIZE))))) * (TcodeWord32( (workptr2 + (3 * WORD32SIZE)))));
		case	0x004A :
		case	0x0042 : /* BCD(x) 	*/
			CheckIreg( 0 , (workptr2 + WORD32SIZE));
			workptr1 += ((ireg [0] - 1) * (TcodeWord32( (workptr2 + ( 2 * WORD32SIZE)))));
		case	0x000A :
		case	0x0002 : /* BCD 	*/
			(VOID) itobcd(e,(workptr1 + (TcodeWord32( (workptr2 + WORD32SIZE)))),TcodeWord32( (workptr2 + (2 * WORD32SIZE)))); continue;
		default	  :
			workval2 = (BINAIRE) e; worktyp2 = VARB_INT16;
			worktyp1 = tcode; workval1 = 0;
			if ((tcode = varbsetw()) != SOFTERROR) { VarbXfer(1); }
		}
		break;

 /* LOAD REGISTER CONSTANT #REGISTER {CONPTR}
  * -----------------------------------------
  * Loads the constant pointer {CONPTR} into the register #REGISTER
  * and sets the status field to 1 indicating a Constant.
  */
case _tc32_LDC	:
	tcode = (EXAWORD) *(fdex++);
	freg [tcode] = TcodeWord32( fdex);
	xreg [tcode] = KONSTANT;
	fdex += WORD32SIZE;
	continue;

/* LOAD 1st INDEX of #REGISTER {CONPTR}
 * ------------------------------------
 * Loads the 1st index field of register #REGISTER with the integer
 * result of the constant pointed to by {CONPTR}
 */
case _tc32_LXC	:
	e = (EXAWORD) *(fdex++);
	workptr2 = (TcodeConstants + TcodeWord32( fdex )); 
	fdex += WORD32SIZE;
KONINDEX:
	if ((worklen2 = (EXAWORD) *(workptr2++)))
		ireg [e] = (EXAWORD) atoi( workptr2, worklen2 );
	else if (((worklen2 = (EXAWORD) *(workptr2++)) & 0x0080)) {
		workptr2 = (GlobalConstants + TcodeWord32((workptr2))); 
		goto KONINDEX;
		}
	else	ireg [e] = (EXAWORD) bcdtoi( workptr2, worklen2 );

	if ( xreg [e] & PTRSTATUS ) {	xreg [ e ] = VARIABLE; }
	continue;


/* LOAD 2nd INDEX of #REGISTER {CONPTR}
 * ------------------------------------
 * Loads the 2nd index field of register #REGISTER with the integer
 * result of the constant pointed to by {CONPTR}
 */
case _tc32_AXC	:
	e = (EXAWORD) *(fdex++);
	workptr2 = (TcodeConstants + TcodeWord32( fdex )); fdex += WORD32SIZE;
KONANDEX:
	if ((worklen2 = (EXAWORD) *(workptr2++)))
		areg [e] = (EXAWORD) atoi( workptr2, worklen2 );
	else if (((worklen2 = (EXAWORD) *(workptr2++)) & 0x0080)) {
		workptr2 = (GlobalConstants + TcodeWord32((workptr2))); 
		goto KONANDEX;
		}
	else	areg [e] = (EXAWORD) bcdtoi( workptr2, worklen2 );
	if ( xreg [e] & PTRSTATUS ) {	xreg [ e ] = VARIABLE; }
	continue;

/* DATA READ (Read=0,Varptr)
 * -------------------------
 *	Reads the next DATA item into the variable specified
 *	and advances the DATA pointer.
 */

case _tc32_DTV	:
	tcode = TcodeWord32( fdex); fdex += WORD32SIZE;
	tcode = argsetw(5,tcode);
	if ( tcode != SOFTERROR ) {tcode = getdata();}
	break;

/* STORE CONSTANT VARIABLE {CONPTR} [VARPTR]
 * -----------------------------------------
 * Stores the value of the constant pointed by {CONPTR} to the variable
 * pointed to by [VARPTR] with automatic type conversion if necessary.
 */

case _tc32_STC	:	/* STO CON / VAR */
	tcode = SOFTERROR;
	workptr2 = (TcodeConstants + TcodeWord32( fdex )); 
	fdex += WORD32SIZE;
	while (1) {
		if ((worklen2 = (EXAWORD) *(workptr2++)))
			worktyp2 = VARB_STR;			
		else if (((worklen2 = (EXAWORD) *(workptr2++)) & 0x0080)) {
			workptr2 = (GlobalConstants + TcodeWord32((workptr2))); 
			continue;
			}
		else	worktyp2 = VARB_BCD;
		break;
		}

	worktyp1 = TcodeWord32( fdex ); fdex += WORD32SIZE; workval1 = 0;
	if ((tcode = varbsetw()) != SOFTERROR) { VarbXfer(1); }
	continue;

 /* OP [VARPTR] &ETIQUETTE 
  * Transfers control to etiquette due to keyboard ready test and stores
  * the key value in the variable [VARPTR] if VARPTR <> 0.
  */

case _tc32_OPV	:
	tcode = TcodeWord32( fdex); fdex += WORD32SIZE;
	if ( tcode == 0 ) {
		if (opb()) { fdex = TcodeSegment + TcodeWord32( fdex); }
		else { fdex += WORD32SIZE; }
		tcode = 1;
		}
	else {
		if ( opb() ) {
			fdex = TcodeSegment + TcodeWord32( fdex);
			workval2 = x_getch();
			}
		else {  fdex += WORD32SIZE; workval2 = 0;	}
		worktyp2 = VARB_INT16; worktyp1 = tcode; workval1 = 0;
		if ((tcode = varbsetw()) != SOFTERROR) { VarbXfer(1); }
		continue;
		}
	break;


 /* ON ERROR [VARPTR] &ETIQUETTE 
  * Transfers control to etiquette due to an error condition, and stores
  * the error value in the variable [VARPTR] if VARPTR <> 0.
  */

case _tc32_OER	:
	tcode = (EXAWORD) *(fdex++); 
	tcode = trapgest(1,TcodeWord32(fdex),tcode,0);
	fdex += WORD32SIZE;
	continue;

case _tc32_OLE	:
	tcode = TcodeWord32(fdex); fdex += WORD32SIZE;
	tcode = trapgest(tcode,TcodeWord32(fdex),0,0);
	fdex += WORD32SIZE;
	continue;

case _tc32_OEV	:
	tcode = TcodeWord32(fdex); fdex += WORD32SIZE;
	tcode = trapgest(tcode,TcodeWord32(fdex),0,0);
	fdex += WORD32SIZE;
	continue;

case _tc32_OEO	:
	tcode = TcodeWord32(fdex); fdex += WORD32SIZE;
	tcode = trapgest(tcode,TcodeWord32(fdex),0,1);
	fdex += WORD32SIZE;
	continue;

/* LOAD REGISTER VARIABLE #REGISTER [VARPTR]
 * -----------------------------------------
 * This function may result in one of two conditions.
 * If the variable pointed by [VARPTR] is an integer EXABYTE or WORD32SIZE then
 * its value will by loaded into the register #REGISTER, and the status
 * will be set to 0. Otherwise the pointer [VARPTR] will be loaded and
 * the status will be set to 2 to indicate the variable pointer.
 */
case _tc32_LDV	:
	e = *(fdex++);
	if ( (tcode = TcodeWord32( fdex )) & ISLOCAL ) {
		workptr2 = LocalDataTable + ( tcode & TOGLOBAL );
		workptr1 = LocalDataSegment;
		}
	else	{
		workptr2 = GlobalDataTable + tcode;
		workptr1 = GlobalDataSegment;
		}
	fdex += WORD32SIZE;
	switch ( TcodeWord32( workptr2 ) ) {
		case	0x0068 :
		case	0x0060 : /* #(x,y)	*/
			CheckAreg( e , workptr2 );
			workptr1 += ( (areg [e] - 1) * (TcodeWord32( (workptr2 + (2 * WORD32SIZE)))));
		case	0x0048 :
		case	0x0040 : /* #(x)	*/
			CheckIreg( e , workptr2 );
			workptr1 += (ireg [e] - 1);
		case	0x0008 :
		case	0x0000 : /* #		*/
			if ( ExFlgSgn == 0 ) {
				xreg [e] = CHARONLY;
				freg [e] = (EXAWORD) ( (BINAIRE) ReadSchar( (workptr1 + (TcodeWord32( (workptr2 + WORD32SIZE)))))); continue;
				}
			else	{
				ExFlgSgn = 0;
				xreg [e] = IMMEDIAT;
				freg [e] = ( (EXAWORD) *((BPTR) (workptr1 + (TcodeWord32( (workptr2 + WORD32SIZE)))))); continue;
				}
		case	0x0069 :
		case	0x0061 : /* %(x,y)	*/
			CheckAreg( e , workptr2 );
			workptr1 += ( ((areg [e] - 1) * 2) * (TcodeWord32( (workptr2 + (2 * WORD32SIZE)))));
		case	0x0049 :
		case	0x0041 : /* %(x)	*/
			CheckIreg( e , workptr2 );
			workptr1 += ((ireg [e] - 1) * 2);
		case	0x0009 :
		case	0x0001 : 
			xreg [e] = IMMEDIAT;
			freg [e] = (EXAWORD) balgetw( ( workptr1 +    (TcodeWord32( (workptr2 + WORD32SIZE) ) ) )); continue;
		case	0x006A :
		case	0x006B :
		case	0x004A :
		case	0x004B :
		case	0x000A :
		case	0x000B :
		case	0x0002 : /* BCD 	*/
		case	0x0003 : /* STR 	*/
		case	0x0042 : /* BCD(x) 	*/
		case	0x0043 : /* STR(x)	*/
		case	0x0062 : /* BCD(x,y)	*/
		case	0x0063 : /* STR(x,y)	*/
			xreg [e] = VARIABLE;
			freg [e] = tcode; 
			continue;
		default	  :
			worktyp1 = tcode; workval1 = e;
			freg [e] = tcode;
			xreg [e] = VARIABLE;
			if (varbset1() != SOFTERROR) {
				switch ( worktyp1 ) {
					case VARB_INT8  :
						xreg [e] = CHARONLY; 
						freg [e] = workval1;
						continue;
					case VARB_INT16 :
						xreg [e] = IMMEDIAT; 
						freg [e] = workval1;
						continue;
					}
				}
			else	{ tcode = SOFTERROR; }
		}
	continue;

/* LOAD 1st INDEX REGISTER with VARIABLE #REGISTER [VARPTR]
* --------------------------------------------------------
* This function loads the integer value of the variable [VARPTR]
* into the 1st index register of #REGISTER.
*/

case _tc32_LXV	:

/* LOAD 2nd INDEX REGISTER with VARIABLE #REGISTER [VARPTR]
 * --------------------------------------------------------
 * This function loads the integer value of the variable [VARPTR]
 * into the 2nd index register of #REGISTER.
 */
case _tc32_AXV	:
	fadj = WORD32SIZE; e = 0;
	worktyp3 = TcodeWord32( (fdex + 1) );
VARBNDX:
	ExFlgSgn = 1;
	if ( worktyp3 & ISLOCAL ) {
		workptr3 = LocalDataTable + ( worktyp3 & TOGLOBAL );
		workptr2 = LocalDataSegment;
		}
	else	{ 
		workptr3 = GlobalDataTable + worktyp3;
		workptr2 = GlobalDataSegment;
		}
	switch ( (worktyp2 = (TcodeWord32( workptr3 ))) ) {
		case	0x0068 :
		case	0x0060 : /* #(x,y)	*/
				CheckAreg( e , workptr3 );
				workptr2 += ( (areg [e] - 1) * (TcodeWord32( (workptr3 + (2 * WORD32SIZE)))));
		case	0x0048 :
		case	0x0040 : /* #(x)	*/
				CheckIreg( e , workptr3 );
				workptr2 += (ireg [e] - 1);
		case	0x0008 :
		case	0x0000 : /* #		*/
				workval2 = ( (EXAWORD) *((BPTR) (workptr2 + (TcodeWord32( (workptr3 + WORD32SIZE)))))); 
				worktyp2 = VARB_INT16;
				break;
		case	0x0069 :
		case	0x0061 : /* %(x,y)	*/
				CheckAreg( e , workptr3 );
				workptr2 += ( ((areg [e] - 1) * WORD32SIZE) * (TcodeWord32( (workptr3 + (2 * WORD32SIZE)))));
		case	0x0049 :
		case	0x0041 : /* %(x)	*/
				CheckIreg( e , workptr3 );
				workptr2 += ((ireg [e] - 1) * WORD32SIZE);
		case	0x0009 :
		case	0x0001 : 
				workval2 = balgetw( ( workptr2 + (TcodeWord32( (workptr3 + WORD32SIZE) ) ) )); 
				break;
		case	0x006A :
		case	0x006B :
		case	0x0063 :
		case	0x0062 : /* STR ou BCD (x,y)	*/
				CheckAreg( e , (workptr3 + WORD32SIZE));
				workptr2 += ( ((areg [e] - 1) * (TcodeWord32( (workptr3 + ( 2 * WORD32SIZE))))) * (TcodeWord32( (workptr3 + (3 * WORD32SIZE)))));
		case	0x004A :
		case	0x004B :
		case	0x0043 :
		case	0x0042 : /* STR ou BCD(x) 	*/
				CheckIreg( e , (workptr3 + WORD32SIZE));
				workptr2 += ((ireg [e] - 1) * (TcodeWord32( (workptr3 + ( 2 * WORD32SIZE)))));
		case	0x000A :
		case	0x000B :
		case	0x0003 :
		case	0x0002 : /* STR ou BCD 	*/
				worklen2 = TcodeWord32( (workptr3 + ( 2 * WORD32SIZE)) );
				workptr2 += (TcodeWord32( (workptr3 + WORD32SIZE)));
WVAL2SET:
				if (( worktyp2 & VARB_ISOL ) == 2) {
					workval2 = bcdtoi( workptr2,worklen2);
					}
				else	{
					workval2 = atoi( workptr2,worklen2);
					}
				break;
		default		: worktyp2 = worktyp3; workval2 = e;
				  if ( varbset2() == SOFTERROR ) { goto CALCWHAT; }
				  if ((( worktyp2 & VARB_ISOL ) < 2 ) 
				  ||  (( worktyp2 & VARB_ISOL ) ==5 )) { break; }
				  goto WVAL2SET;
		}

	ExFlgSgn = 0;
	e = (EXAWORD) *fdex; fdex += ( fadj + 1);
	if ( tcode & 4 ) {	areg [e] = workval2;	}
	else		 {	ireg [e] = workval2;	}
	if ( xreg [e] & PTRSTATUS ) {	xreg [ e ] = VARIABLE; }
	continue;
	

/* 
 * Chargement du registre #REG avec VARPTR
 * ---------------------------------------
 * Contrairement a l'operation LDV cette operation n'essai pas
 * d'evaluer le pointeur de variable en integer avant le chargement
 * du registre.
 *	Resultat	Freg [ reg ] = VARPTR
 *			Xreg [ reg ] = 2
 *			Ireg [ reg ] and Areg [ reg ] restent inchanges
 */

case _tc32_VPT	:
	tcode = (EXAWORD) *(fdex++);
	freg [tcode] = TcodeWord32( fdex);
	xreg [tcode] = VARIABLE;
	fdex += WORD32SIZE;
	continue;


/* GOTO [VARPTR]
 * -------------
 * Transfers control direct to the adresse indicated by the integer values
 * of the variable [VARPTR].
 */
case _tc32_JMV	:
	e = valvar(TcodeWord32( fdex),0);
	fdex = (BPTR) (TcodeSegment + (EXAWORD) e);
	continue;

/* STORE [VARPTR1] to [VARPTR2]
 * ----------------------------
 * Duplicates the value of variable [VARPTR1] into the variable
 * pointed to by [VARPTR2] with automatic type conversion if needed.
 */
case _tc32_STV	:
	tcode = TcodeWord32( fdex);
	fdex += WORD32SIZE;
	tcode = varcpy(tcode,TcodeWord32( fdex),0,0);
	fdex += WORD32SIZE; 
	break;

/* RESUME [&etiquette]
 * -------------------
 * Allows the continuation after error handling at the adresse supplied
 */
case _tc32_REQ	:	tcode = trapwork( TcodeWord32(fdex) );	continue;

case _tc32_JEQI 	:
	if ( ( xreg [ (e = *fdex) ] & 0x0803 ) != IMMEDIAT ) { goto SWITXXXX; }
	if (((BINAIRE) freg [ e ]) == ((BINAIRE)(TcodeWord32( (fdex + 1) ))) ) { fdex = TcodeSegment + (TcodeWord32( (fdex + (WORD32SIZE + 1)))); continue; }
	fdex += ((2 * WORD32SIZE) + 1);
	continue;
case _tc32_JNEI	:
	if ( ( xreg [ (e = *fdex) ] & 0x0803 ) != IMMEDIAT ) { goto SWITXXXX; }
	if (((BINAIRE) freg [ e ]) != ((BINAIRE)(TcodeWord32( (fdex + 1) ))) ) { fdex = TcodeSegment + (TcodeWord32( (fdex + (WORD32SIZE + 1)))); continue; }
	fdex += ((2 * WORD32SIZE) + 1);
	continue;
case _tc32_JGRI	:
	if ( ( xreg [ (e = *fdex) ] & 0x0803 ) != IMMEDIAT ) { goto SWITXXXX; }
	if ( ((BINAIRE) freg [ e ]) > ((BINAIRE) (TcodeWord32( (fdex + 1) ))) ) { fdex = TcodeSegment + (TcodeWord32( (fdex + (WORD32SIZE + 1)))); continue; }
	fdex += ((2 * WORD32SIZE) + 1);
	continue;
case _tc32_JLSI	:
	if ( ( xreg [ (e = *fdex) ] & 0x0803 ) != IMMEDIAT ) { goto SWITXXXX; }
	if ( ((BINAIRE) freg [ e ]) < ((BINAIRE) (TcodeWord32( (fdex + 1) ))) ) { fdex = TcodeSegment + (TcodeWord32( (fdex + (WORD32SIZE + 1)))); continue; }
	fdex += ((2 * WORD32SIZE) + 1);
	continue;
case _tc32_JLEI	:
	if ( ( xreg [ (e = *fdex) ] & 0x0803 ) != IMMEDIAT ) { goto SWITXXXX; }
	if ( ((BINAIRE) freg [ e ]) <= ((BINAIRE) (TcodeWord32( (fdex + 1) ))) ) { fdex = TcodeSegment + (TcodeWord32( (fdex + (WORD32SIZE + 1)))); continue; }
	fdex += ((2 * WORD32SIZE) + 1);
	continue;
case _tc32_JGEI	:
	if ( ( xreg [ (e = *fdex) ] & 0x0803 ) != IMMEDIAT ) { goto SWITXXXX; }
	if ( ((BINAIRE) freg [ e ]) >= ((BINAIRE) (TcodeWord32( (fdex + 1) ))) ) { fdex = TcodeSegment + (TcodeWord32( (fdex + (WORD32SIZE + 1)))); continue; }
	fdex += ((2 * WORD32SIZE) + 1);
	continue;

/*==========================================================================*/
/* CALCULATE #REGISTER1 IVALUE #REGISTER2
 * --------------------------------------
 * Evaluates the expression between the contents of #REGISTER1 and
 * the immediate value IVALUE. The result is stored wrt REGISTER2 
 * and the operand data types. If INTEGER calculation is performed
 * then the target register will contain an integer result. For string
 * and BCD calculations the target register will contain a temporary
 * descriptor pointer to the result.
 *	SREG , INTEGER , DREG
 */

case	_tc32_ADI	:
	if ( (xreg [ (e = *fdex) ] & 0x0803) != IMMEDIAT ) { goto SWITXXXX; }
 	freg [(tcode = *(fdex + (WORD32SIZE + 1)))] = ((BINAIRE) freg [ e ] + (BINAIRE) (TcodeWord32( (fdex + 1) )));
	xreg [tcode] = IMMEDIAT; fdex += (2 * WORD32SIZE);
	continue;
case	_tc32_SBI	:
	if ( (xreg [ (e = *fdex) ] & 0x0803) != IMMEDIAT ) { goto SWITXXXX; }
 	freg [(tcode = *(fdex + (WORD32SIZE + 1)))] = ((BINAIRE) freg [ e ] - (BINAIRE) (TcodeWord32( (fdex + 1) )));
	xreg [tcode] = IMMEDIAT; fdex += (2 * WORD32SIZE);
	continue;
case	_tc32_MLI	:
	if ( (xreg [ (e = *fdex) ] & 0x0803) != IMMEDIAT ) { goto SWITXXXX; }
 	freg [(tcode = *(fdex + (WORD32SIZE + 1)))] = ((BINAIRE) freg [ e ] * (BINAIRE) (TcodeWord32( (fdex + 1) )));
	xreg [tcode] = IMMEDIAT; fdex += (2 * WORD32SIZE);
	continue;
case	_tc32_DVI	:
	if ( (xreg [ (e = *fdex) ] & 0x0803) != IMMEDIAT ) { goto SWITXXXX; }
	if ( (workval1 = (TcodeWord32( (fdex + 1) ))) == 0 )   { err_val = 102; tcode = 0; continue; }
	freg [(tcode = *(fdex + (WORD32SIZE + 1)))] = ( (BINAIRE) freg [ e ] / workval1);
	xreg [tcode] = IMMEDIAT; fdex += (2 * WORD32SIZE);
	continue;
case	_tc32_ANI	:
	if ( (xreg [ (e = *fdex) ] & 0x0803) != IMMEDIAT ) { goto SWITXXXX; }
	freg [(tcode = *(fdex + (WORD32SIZE + 1)))] = ( freg [ e ] & (TcodeWord32( (fdex + 1) )));
	xreg [tcode] = IMMEDIAT;  fdex += (2 * WORD32SIZE);
	continue;
case	_tc32_ORI	:
	if ( (xreg [ (e = *fdex) ] & 0x0803) != IMMEDIAT ) { goto SWITXXXX; }
	freg [(tcode = *(fdex + (WORD32SIZE + 1)))] = ( freg [ e ] | (TcodeWord32( (fdex + 1) )));
	xreg [tcode] = IMMEDIAT;  fdex += (2 * WORD32SIZE);
	continue;
case	_tc32_XRI	:
	if ( (xreg [ (e = *fdex) ] & 0x0803) != IMMEDIAT ) { goto SWITXXXX; }
	freg [(tcode = *(fdex + (WORD32SIZE + 1)))] = ( freg [ e ] ^ (TcodeWord32( (fdex + 1) )));
	xreg [tcode] = IMMEDIAT; fdex += (2 * WORD32SIZE);
	continue;
case	_tc32_MDI	:
/*
 *	if ( (xreg [ (e = *fdex) ] & 0x0803) != IMMEDIAT ) { goto SWITXXXX; }
 *	if ( (workval1 = (TcodeWord32( (fdex + 1) ))) == 0 )   { err_val = 102; tcode = 0; continue; }
 *	freg [(tcode = *(fdex + (WORD32SIZE + 1)))] = ( (BINAIRE) freg [ e ] % workval1);
 *	freg [tcode] = abs( freg [tcode] );
 *	xreg [tcode] = IMMEDIAT; fdex += (2 * WORD32SIZE);
 *	continue;
 */
SWITXXXX:
	worktyp2 = VARB_INT16; workval2 = (BINAIRE) TcodeWord32(( fdex + 1 )); 
	fadj = WORD32SIZE; goto SREGEVAL;

/* CALCULATE #REGISTER1 {CONPTR} #REGISTER2
 * ----------------------------------------
 * Evaluates the expression between the contents of #REGISTER1 and
 * the constant pointer {CONPTR}. The result is stored wrt REGISTER2.
 */
case 0x0038	:
case 0x0039	:
case 0x003A	:
case 0x003B	:
case 0x003C	:
case 0x003D	:
case 0x003E	:
case 0x003F	:

case	_tc32_ADC	:
case	_tc32_SBC	:
case	_tc32_MLC	:
case	_tc32_DVC	:
case	_tc32_MDC	:
case	_tc32_ANC	:
case	_tc32_ORC	:
case	_tc32_XRC	:

	workptr2 = (TcodeConstants + TcodeWord32( (fdex + 1) )); fadj = WORD32SIZE;
KONEVAL:
	while (1) {
		if ((worklen2 = (EXAWORD) *(workptr2++)))
			worktyp2 = VARB_STR;			
		else if (((worklen2 = (EXAWORD) *(workptr2++)) & 0x0080)) {
			workptr2 = (GlobalConstants + TcodeWord32((workptr2))); 
			continue;
			}
		else	worktyp2 = VARB_BCD;
		break;
		}

	goto SREGEVAL;

/* CALCULATE #REGISTER1 [VARPTR] #REGISTER2
 * ----------------------------------------
 * Evaluates the expression between the contents of #REGISTER1 and
 * the constant pointer [VARPTR]. The result is stored wrt REGISTER2.
 */
case 0x0058	:
case 0x0059	:
case 0x005A	:
case 0x005B	:
case 0x005C	:
case 0x005D	:
case 0x005E	:
case 0x005F	:

case	_tc32_ADV	:
case	_tc32_SBV	:
case	_tc32_MLV	:
case	_tc32_DVV	:
case	_tc32_MDV	:
case	_tc32_ANV	:
case	_tc32_ORV	:
case	_tc32_XRV	:

	worktyp3 = TcodeWord32( (fdex + 1) ); fadj = WORD32SIZE; e = 0;
VARBEVAL:
	if ( worktyp3 & ISLOCAL ) {
		workptr3 = LocalDataTable + ( worktyp3 & TOGLOBAL );
		workptr2 = LocalDataSegment;
		}
	else	{ 
		workptr3 = GlobalDataTable + worktyp3;
		workptr2 = GlobalDataSegment;
		}
	switch ( (worktyp2 = (TcodeWord32( workptr3 ))) ) {
		case	0x0068 :
		case	0x0060 : /* #(x,y)	*/
				CheckAreg( e , workptr3 );
				workptr2 += ( (areg [e] - 1) * (TcodeWord32( (workptr3 + (2 * WORD32SIZE)))));
		case	0x0048 :
		case	0x0040 : /* #(x)	*/
				CheckIreg( e , workptr3 );
				workptr2 += (ireg [e] - 1);
		case	0x0008 :
		case	0x0000 : /* #		*/
				workval2 = ( (BINAIRE) ReadSchar( (workptr2 + (TcodeWord32( (workptr3 + WORD32SIZE)))))); 
				worktyp2 = VARB_INT16;
				goto SREGEVAL;
		case	0x0069 :
		case	0x0061 : /* %(x,y)	*/
				CheckAreg( e , workptr3 );
				workptr2 += ( ((areg [e] - 1) * WORD32SIZE) * (TcodeWord32( (workptr3 + (2 * WORD32SIZE)))));
		case	0x0049 :
		case	0x0041 : /* %(x)	*/
				CheckIreg( e , workptr3 );
				workptr2 += ((ireg [e] - 1) * WORD32SIZE);
		case	0x0009 :
		case	0x0001 : 
				workval2 = balgetw( ( workptr2 + (TcodeWord32( (workptr3 + WORD32SIZE) ) ) )); 
				goto SREGEVAL;
		case	0x006A :
		case	0x006B :
		case	0x0063 :
		case	0x0062 : /* STR ou BCD (x,y)	*/
				CheckAreg( e , (workptr3 + WORD32SIZE));
				workptr2 += ( ((areg [e] - 1) * (TcodeWord32( (workptr3 + ( 2 * WORD32SIZE))))) * (TcodeWord32( (workptr3 + (3 * WORD32SIZE)))));
		case	0x004A :
		case	0x004B :
		case	0x0043 :
		case	0x0042 : /* STR ou BCD(x) 	*/
				CheckIreg( e , (workptr3 + WORD32SIZE));
				workptr2 += ((ireg [e] - 1) * (TcodeWord32( (workptr3 + ( 2 * WORD32SIZE)))));
		case	0x000A :
		case	0x000B :
		case	0x0003 :
		case	0x0002 : /* STR ou BCD 	*/
				worklen2 = TcodeWord32( (workptr3 + ( 2 * WORD32SIZE)) );
				workptr2 += (TcodeWord32( (workptr3 + WORD32SIZE)));
				if ( e > 0 ) {
					lreg [e] = worklen2;
					xreg [e] = ((worktyp2 & VARB_ISOL ) | PTRSTATUS);
					preg [e] = workptr2;
					}
				goto SREGEVAL;
		default		: worktyp2 = worktyp3; workval2 = e;
				  if ( varbset2() == SOFTERROR ) {
					goto CALCWHAT;
					}
				goto SREGEVAL;
		}

SREGEVAL:
	e = (EXAWORD) *fdex; fdex += (fadj + 1 );
	switch ( xreg [ e ] ) {
		case CHARONLY  :
		case IMMEDIAT  :
			workval1 = freg [ e ]; worktyp1 = 1;
			goto DOCALC;
		case KONSTANT  :
			workptr1 = (TcodeConstants + freg [ e ]);
			while (1) {
				if ((worklen1 = (EXAWORD) *(workptr1++)))
					worktyp1 = VARB_STR;			
				else if (((worklen1 = (EXAWORD) *(workptr1++)) & 0x0080)) {
					workptr1 = (GlobalConstants + TcodeWord32((workptr1))); 
					continue;
					}
				else	worktyp1 = VARB_BCD;
				break;
				}
			goto DOCALC;
		case PTRSTR    :
			worktyp1 = VARB_STR;
			worklen1 = lreg [e];
			workptr1 = preg [e];
			goto DOCALC; 
		case PTRBCD    :
			worktyp1 = VARB_BCD;
			worklen1 = lreg [e];
			workptr1 = preg [e];
			goto DOCALC; 
		case VARIABLE  :
			worktyp3 = freg [ e ]; 
			if ( worktyp3 & ISLOCAL ) {
				workptr3 = LocalDataTable + ( worktyp3 & TOGLOBAL );
				workptr1 = LocalDataSegment;
				}
			else	{ 
				workptr3 = GlobalDataTable + worktyp3;
				workptr1 = GlobalDataSegment;
				}
			switch ( (worktyp1 = (TcodeWord32( workptr3 ))) ) {
				case	0x0068 :
				case	0x0060 : /* #(x,y)	*/
						CheckAreg( e , workptr3 );
						workptr1 += ( (areg [e] - 1) * (TcodeWord32( (workptr3 + (2 * WORD32SIZE)))));
				case	0x0048 :
				case	0x0040 : /* #(x)	*/
						CheckIreg( e , workptr3 );
						workptr1 += (ireg [e] - 1);
				case	0x0008 :
				case	0x0000 : /* #		*/
						workval1 = ( (BINAIRE) ReadSchar( (workptr1 + (TcodeWord32( (workptr3 + WORD32SIZE)))))); 
						worktyp1 = VARB_INT16;
						goto DOCALC;
				case	0x0069 :
				case	0x0061 : /* %(x,y)	*/
						CheckAreg( e , workptr3 );
						workptr1 += ( ((areg [e] - 1) * WORD32SIZE) * (TcodeWord32( (workptr3 + (2 * WORD32SIZE)))));
				case	0x0049 :
				case	0x0041 : /* %(x)	*/
						CheckIreg( e , workptr3 );
						workptr1 += ((ireg [e] - 1) * WORD32SIZE);
				case	0x0009 :
				case	0x0001 : 
						workval1 = balgetw( ( workptr1 + (TcodeWord32( (workptr3 + WORD32SIZE) ) ) )); 
						goto DOCALC;
				case	0x006A :
				case	0x006B :
				case	0x0063 :
				case	0x0062 : /* STR ou BCD (x,y)	*/
						CheckAreg( e , (workptr3 + WORD32SIZE) );
						workptr1 += ( ((areg [e] - 1) * (TcodeWord32( (workptr3 + ( 2 * WORD32SIZE))))) * (TcodeWord32( (workptr3 + (3 * WORD32SIZE)))));
				case	0x004A :
				case	0x004B :
				case	0x0043 :
				case	0x0042 : /* STR ou BCD(x) 	*/
						CheckIreg( e , (workptr3 + WORD32SIZE));
						workptr1 += ((ireg [e] - 1) * (TcodeWord32( (workptr3 + ( 2 * WORD32SIZE)))));
				case	0x000A :
				case	0x000B :
				case	0x0003 :
				case	0x0002 : /* STR ou BCD 	*/
						worklen1 = TcodeWord32( (workptr3 + ( 2 * WORD32SIZE)) );
						workptr1 += (TcodeWord32( (workptr3 + WORD32SIZE)));
						lreg [e] = worklen1;
						xreg [e] = ((worktyp1 & VARB_ISOL ) | PTRSTATUS);
						preg [e] = workptr1;
						goto DOCALC;
				default		: worktyp1 = freg [(workval1 = e)]; 
						  if ( varbset1() == SOFTERROR ) { goto CALCWHAT; }
				}
			goto DOCALC;
		case TEMPDESC  :
			workptr1 = (TcodeByteStack + freg [ e ]);
			worktyp1 = TcodeWord32( workptr1 );
			worklen1 = TcodeWord32( (workptr1 + WORD32SIZE) );
			workptr1 += ( 2 * WORD32SIZE );
		}

DOCALC:
if (( tcode & 0x0010 ) == 0 ) { /* Alors Calculs */
			   	/* ------------- */
	switch ( worktyp1 & VARB_ISOL ) {
		case VARB_INT8	:
		case VARB_INT16	:
			switch ( worktyp2 & VARB_ISOL ) {
				case VARB_INT8	:
				case VARB_INT16	:
				  switch (tcode & 0x0007)	{
					case	0 : workval1 += workval2; break;
					case	1 : workval1 -= workval2; break;
					case	2 : workval1 *= workval2; break;
					case	3 : if ( workval2 != 0) { workval1 /= workval2; break; }
						    else { err_val = ABAL_NDXZERO; tcode = 0; continue; }
					case	4 : if ( workval2 == 0) { err_val = ABAL_NDXZERO; tcode = 0; continue; }
						    if ( workval1 < 0 ) { workval1 *= -1; }
						    if ( workval2 < 0 ) { workval2 *= -1; }
						    workval1 = (BINAIRE)((EXAWORD)workval1 % (EXAWORD)workval2); break;
					case	5 : workval1 &= (EXAWORD) workval2; break;
					case	6 : workval1 |= (EXAWORD) workval2; break;
					case	7 : workval1 ^= (EXAWORD) workval2; break;
					} /* End case */
				  tcode = (EXAWORD) *(fdex++);
				  if ( tcode == 0 ) { tcode = e; } 
				  freg [ tcode ] = workval1;
				  xreg [ tcode ] = IMMEDIAT;
				  continue;
				case VARB_BCD   :
					worklen1 = 4;
					PileCheck( worklen1 );
					(VOID) itobcd(workval1,(TcodeByteStack + worktop),BCDMAX);
					workptr1 = (TcodeByteStack + worktop);
					worklen1 = 4; worktop += 4;
					goto DOBCD;
				case VARB_STR   :
					worklen1 = 6;
					PileCheck( worklen1 );
					(VOID) itoa(workval1,(TcodeByteStack + worktop),BCDMAX*2);
					workptr1 = (TcodeByteStack + worktop);
					worktop += 6;
					goto DOSTR;
				}	
			goto CALCWHAT;
		case VARB_STR :
			switch ( worktyp2 & VARB_ISOL ) {
				case VARB_INT8	:
				case VARB_INT16 :
					worklen2 = 6;
					PileCheck( worklen2 );
					(VOID) itoa(workval2,(TcodeByteStack + worktop),6);
					workptr2 = (TcodeByteStack + worktop);
					worktop += 6;
					goto DOSTR;
				case VARB_BCD   :
					worklen2 = (BCDMAX * 2); 
					PileCheck( worklen2 );
					(VOID) bcdtoa( workptr2,worklen2,(TcodeByteStack + worktop),(BCDMAX * 2));
					workptr2 = (TcodeByteStack + worktop);
					worktop += (BCDMAX * 2);
				case VARB_STR :
DOSTR:
					e = (EXAWORD) *(fdex++);		/* Collect register ID		*/
					if ( e != 0 ) {
						worklen3 = (worklen2 + worklen1);	/* Calculate result length 	*/
						PileCheck( worklen3 );			/* Check temporary zone		*/
						freg [ e ] = worktop;			/* Store TEMPDESC offset	*/
						xreg [ e ] = TEMPDESC;			/* indicate TEMPDESC		*/
						workptr3 = (TcodeByteStack + worktop);	/* Calculate result pointer	*/
						TcodePmot( workptr3 , VARB_STR);	/* Create string descriptor	*/
						TcodePmot( (workptr3 + WORD32SIZE),worklen3);	/* Store  string length    	*/
						workptr3 += (2 * WORD32SIZE);			/* Adjust Result pointer	*/
						worktop  += (worklen3 + (2 * WORD32SIZE));	/* Adjust stack pointer		*/
						}
					else	{ workptr3 = workptr1; worklen3 = worklen1; }
					tcode = strcalc( tcode & 7 );
					goto CALCEXIT;
					}
		case VARB_BCD :
			switch ( worktyp2 & VARB_ISOL ) {
				case VARB_INT8	:
				case VARB_INT16 :
					PileCheck( 4 );
					(VOID) itobcd(workval2,(TcodeByteStack + worktop),BCDMAX);
					workptr2 = (TcodeByteStack + worktop);
					worklen2 = 4; worktop += 4;
					goto DOBCD;
				case VARB_STR :
					worklen2 = BCDMAX;
					PileCheck( worklen2 );
					(VOID) atobcd( workptr2,(TcodeByteStack + worktop), BCDMAX,worklen2); 
					workptr2 = (TcodeByteStack + worktop); worktop += BCDMAX;
				case VARB_BCD :
DOBCD:
					e = (EXAWORD) *(fdex++);		/* Collect register ID		*/
					if ( e != 0 ) {
						worklen3 = BCDMAX;			/* Calculate result length 	*/
						PileCheck( worklen3 );			/* Check temporary zone		*/
						freg [ e ] = worktop;			/* Store TEMPDESC offset	*/
						xreg [ e ] = TEMPDESC;			/* indicate TEMPDESC		*/
						workptr3 = (TcodeByteStack + worktop);	/* Calculate result pointer	*/
						TcodePmot( workptr3 , VARB_BCD);	/* Create string descriptor	*/
						TcodePmot( (workptr3 + WORD32SIZE),worklen3);	/* Store  string length    	*/
						workptr3 += (2 * WORD32SIZE);			/* Adjust Result pointer	*/
						worktop  += (BCDMAX + (2 * WORD32SIZE));	/* Adjust stack pointer		*/
						}
					else	{ workptr3 = workptr1; worklen3 = worklen1; }
					if (TempZone() != SOFTERROR) { 
						tcode = bcdcalc( tcode & 7 );
						}
					else	{ tcode = SOFTERROR; }
					goto CALCEXIT;
					}
		}	
CALCEXIT:
	ExFlgSgn = 0;
	break;
INDEX2BIG:
	ExFlgSgn = 0;
	err_val = ABAL_NDX2BIG;
	tcode   = SOFTERROR;
	continue;
INDEXZERO:
	ExFlgSgn = 0;
	err_val = ABAL_NDXZERO;
	tcode   = SOFTERROR;
	continue;
CALCWHAT:
	if ( err_val == 0 ) {
		err_val = 777;
		}
	ExFlgSgn = 0;
	tcode 	= SOFTERROR;
	continue;
	}
else	{	/* Alors Compare */
		/* ------------- */

	switch ( worktyp1 & VARB_ISOL) {
		case VARB_INT8	:
		case VARB_INT16 :
			switch ( worktyp2 & VARB_ISOL) {
				case VARB_STR : workval2 = atoi  (workptr2,worklen2); break;
				case VARB_BCD : workval2 = bcdtoi(workptr2,worklen2);
				}
			tcode = compint((tcode & 7),workval2,workval1);
			continue;
		case VARB_BCD   :
			switch ( worktyp2 & VARB_ISOL) {
				case VARB_STR   : 
					PileCheck( BCDMAX );
					atobcd(workptr2,(TcodeByteStack + worktop),BCDMAX,worklen2);
					workptr2 = (TcodeByteStack + worktop); worklen2 = BCDMAX; 
					worktop += BCDMAX; break;
				case VARB_INT8  :
				case VARB_INT16 : 
					PileCheck( BCDMAX );
			 		itobcd(workval2,(workptr2 = (TcodeByteStack + worktop)),(worklen2 = BCDMAX));
				}
#ifndef INTELASM1
			if ( compbcd((tcode & 7),workptr1,workptr2) != 0) { 
				fdex = (TcodeSegment + TcodeWord32( fdex ));
				}
			else	{ fdex += WORD32SIZE; }
#else
			if ( bcdcomp((tcode & 7)) != 0) { fdex = (TcodeSegment + TcodeWord32( fdex )); }
			else	{ fdex += WORD32SIZE; }
#endif
			tcode = 1;
			continue;
		case VARB_STR   :
			switch ( worktyp2 & VARB_ISOL) {
				case VARB_INT8	:
				case VARB_INT16 :
					PileCheck( worklen1 );
					itoa(workval2,(TcodeByteStack + worktop),worklen1);
					workptr2 = (TcodeByteStack + worktop);
					worktop += worklen1;  worktyp2 = VARB_STR; break;
				case VARB_BCD   : 
					PileCheck( 24 );
					bcdtoa(workptr2,worklen2,(TcodeByteStack + worktop),24);
					workptr2 = (TcodeByteStack + worktop); worklen2 = 24;
					worktop += 24;  worktyp2 = VARB_STR;
				}
			tcode = compstr((tcode & 7)); 
			continue;
		}
	}
	continue;

/* NEGATE [VARPTR]
 * ---------------
 */
				case _tc32_NGV	:
					tcode = negwork(0,TcodeWord32( fdex));
					fdex += WORD32SIZE; break;



case _tc32_GWS :

	balputw( (TcodeWord32( (fdex) )), (GlobalDataSegment + (TcodeWord32( (fdex + WORD32SIZE)))));
	fdex += (2 * WORD32SIZE);
	continue;

case _tc32_LWS :

	balputw( (TcodeWord32( (fdex) )), (LocalDataSegment + (TcodeWord32( (fdex + WORD32SIZE)))));
	fdex += (2 * WORD32SIZE);
	continue;

/* STORE #REGISTER to [VARPTR]
 * ---------------------------
 * Stores the result of evaluation of the contents of #REGISTER to
 * the variable pointed to by [VARPTR]
 */
case _tc32_STR	:
	
	switch ( xreg [(e = (EXAWORD) *(fdex++))] ) {
		case CHARONLY :
		case IMMEDIAT :
			e = freg [e]; goto ITOVARB;
		case VARIABLE : 
			tcode = varcpy(freg [e],TcodeWord32( fdex),e,0);
			fdex += WORD32SIZE;
			break;	
		case PTRSTR   :
			workptr2 = preg [e]; worklen2 = lreg [e];
			worktyp2 = VARB_STR; 
			worktyp1 = TcodeWord32( fdex ); fdex += WORD32SIZE;
			workval1 = 0;
			if ((tcode = varbsetw()) != SOFTERROR) { VarbXfer(1); }
			continue;
		case PTRBCD   :
			workptr2 = preg [e]; worklen2 = lreg [e];
			worktyp2 = VARB_BCD; 
			worktyp1 = TcodeWord32( fdex ); fdex += WORD32SIZE;
			workval1 = 0;
			if ((tcode = varbsetw()) != SOFTERROR) { VarbXfer(1); }
			continue;
		case TEMPDESC :
			workptr2 = (TcodeByteStack + freg [e]);
			worktyp2 = TcodeWord32( workptr2 );
			worklen2 = TcodeWord32( (workptr2 + WORD32SIZE) );
			workptr2 += (2 * WORD32SIZE); 
			worktyp1 = TcodeWord32( fdex ); fdex += WORD32SIZE;
			workval1 = 0;
			if ((tcode = varbsetw()) != SOFTERROR) { VarbXfer(1); }
			continue;
		}
		break;

EXVRBCNV:

	/*       Destination  H  : Source    L      	*/
	/*	----------------  -------------		*/
	switch ( (worktyp1 << 4) | worktyp2 )	{
		case 0x0000 :   *workptr1 = (EXABYTE) workval2; break;
		case 0x0001 :	*workptr1 = (EXABYTE) workval2; break;
		case 0x0002 :   *workptr1 = (EXABYTE) bcdtoi(workptr2,worklen2);
				break;
		case 0x0003 :	*workptr1 = (EXABYTE) atoi(workptr2,worklen2);
				break;
		case 0x0010 :	
		case 0x0011 :	balputw((EXAWORD) workval2,workptr1); break;
		case 0x0012 :	balputw((EXAWORD) bcdtoi(workptr2,worklen2),workptr1);
				break;
		case 0x0013 :	balputw((EXAWORD) atoi(workptr2,worklen2),workptr1);
				break;
		case 0x0020 :	
		case 0x0021 :	tcode = itobcd(workval2,workptr1,worklen1); break;
		case 0x0022 :	

			e = 0; err_val = ABAL_NUM2BIG; 
			if ( worklen1 < worklen2 ) { workptr2 = (BPTR) Squeeze(workptr2,worklen2); }
			while ((worklen1 > 0) && (worklen2 > 0)) {
				if ( e == 0 ) {
					switch ( *workptr2 & 0x00F0 ) {
						case 0x00A0 :
						case 0x00F0 : e = 1;
						}
					switch ( *workptr2 & 0x000F ) {
						case 0x000A :
						case 0x000F : e = 1;
						}
					}
				*(workptr1++) = *(workptr2++);
				worklen1--; worklen2--;
				}
			while ( worklen1 > 0 ) { *(workptr1++) = (EXABYTE) 0x00FF; worklen1--; }
			if ( worklen2 == 0 ) 	{ tcode = 1; break; }
			else			{ 
				if ((e != 0 ) || (( *workptr2 & 0x00F0 ) > 0x0090 ))  { tcode = 1; break; }
				else { tcode = e; }
				}	
			break;
		case 0x0023 : tcode = atobcd(workptr2,workptr1,worklen1,worklen2); break;
		case 0x0030 :	
		case 0x0031 : if ( e == 1 ) {
				PileCheck( 12 );
				workptr3 = (TcodeByteStack + worktop);
				worktop += 12;
				itoa(workval2,workptr3,12);
				tcode = str0fill();
				}
			      else { itoa(workval2,workptr1,worklen1); tcode = 1; }
			      break;
		case 0x0032 : if ( e == 1 ) {
				PileCheck( worklen1 );
				workptr3 = (TcodeByteStack + worktop);
				worktop += worklen1;
				bcdtoa(workptr2,worklen2,workptr3,worklen1);
				tcode = str0fill();
				}
			      else { bcdtoa(workptr2,worklen2,workptr1,worklen1); 
				     (VOID) numclean();
				     tcode = 1;
				     }
				break;
		case 0x0033 :	xmemcpy(0x0020); break;
		default	    :	tcode = SOFTERROR; err_val = 444; continue;
		}
	break;

/* WHEN <Event condition>
 * ----------------------
 * Declaration and management of Event conditions and operations.
 * (EVENT conditions are local to Segments and procedures, they are stacked 
 * wrt code unit due to LDGO.SEG and CALL and destacked by RET.SEG and EXIT
 *
 *	WHN	Eventcode [,&etiquette_d'evenment]
 */
case _tc32_WHN	: 
	switch ((tcode = (EXAWORD) *(fdex++))) {
		case _ec_STOP:  ip_next--;
		case _ec_RAZ :	timersem &= EVENT_SEMOFF; 
				tcode = 1;
				continue;
		case _ec_DCL :	eventadr  = TcodeWord32( fdex ); 
				fdex += WORD32SIZE;
				if ( (timersem & EVENT_EXIST) == 0) {
					timersem &= EVENT_SEMOFF;
					timersem |= EVENT_SEMON;
					}
				continue;
		case _ec_START: if ((timersem & EVENT_EXIST ) == 0) {
					timersem &= EVENT_SEMOFF;
					fdex = (TcodeSegment + ip_hold [--ip_next]) - 1;
					continue;
					}
				timersem &= EVENT_SEMOFF;
				timersem |= EVENT_ACTIF;
		case _ec_FAUX : timersem |= EVENT_OVER;
				fdex = (TcodeSegment + ip_hold [--ip_next]) - 1;
				continue;
		case _ec_HALT : timersem |= EVENT_EXIST;
				continue;

		default	      : 
#ifdef	ABAL21
				if ( tcode & _ec_EXTERN ) {
					switch ((tcode & 0x003F)) {
						case _ec_POP   :
						case _ec_CALLI :
						case _ec_CALLV :
						case _ec_GOTO  :
						case _ec_GOSUB : activate_external_event( tcode, (TcodeWord32((fdex))));
								 if ((tcode & 0x003F) != _ec_POP)	fdex += WORD32SIZE;
								 continue;
						
						case _ec_RAZ   : disactivate_external_event();
								 continue;

						default        :
							tcode = SOFTERROR; 
							err_val = 56;
						}
					continue;
					}
#endif
				tcode = SOFTERROR; err_val = 56;
				continue;
		}


/*----------------------------------------------------------------------------*/
/* Remarque : La fin du SWITCH CASE se trouve dans le fichier niveau MOINS_UN */
/*----------------------------------------------------------------------------*/
#include "exgoto.h"	/* Redefine all subsequent GOTO jumps	*/
/*----------------------------------------------------------------------------*/

