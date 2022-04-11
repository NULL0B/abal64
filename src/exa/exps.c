/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987 Amenesik / Sologic S.A.		*/
/*									*/
/*		Module  :	EXESC - C				*/
/*		Date 	:	11.05.1988				*/
/*									*/
/*----------------------------------------------------------------------*/

#include "exesc.h"

UBINAIR	echapp(tcode,e)
UBINAIR	tcode,e;
{
	switch ( tcode ) {
		case _esc_SPREG : freg [e] = ip_next; xreg [e] = 0; break;
		case _esc_REGSP : ip_next = freg [e]; break;
		case _esc_WPREG : freg [e] = worktop; xreg [e] = 0; break;
		case _esc_REGWP : worktop = freg [e]; break;
		case _esc_FPREG : freg [e] = mindex;  xreg [e] = 0; break;
		case _esc_REGFP : mindex  = freg [e]; break;
		case _esc_PSHDS : if ( mindex >= diezstk ) { err_val = ABAL_GSB2MANY; return(0); }
				  switch ( e ) {
					case 0 : minder [mindex++] = GlobalDataSegment; break;
					case 1 : minder [mindex++] = LocalDataSegment; break;
					case 2 : minder [mindex++] = TcodeConstants; break;
					case 3 : minder [mindex++] = EsReg; break;
					case 4 : minder [mindex++] = TcodeSegment; break;
					case 5 : minder [mindex++] = TcodeByteStack; break;
					case 6 : minder [mindex++] = (EXBPTR) ip_hold; break;
					case 7 : minder [mindex++] = (EXBPTR) minder;  break;
					default: break;
					}
				  break;
		case _esc_POPDS : if ( mindex == 0 ) { err_val = 105; return(0); }
				   switch ( e ) {
					case 0 : GlobalDataSegment = minder [--mindex]; break;
					case 1 : LocalDataSegment = minder [--mindex]; break;
					case 2 : TcodeConstants = minder [--mindex]; break;
					case 3 : EsReg = minder [--mindex]; break;
					case 4 : err_val = 56; return(0);
					case 5 : TcodeByteStack = minder [--mindex]; break;
					case 6 : TcodeWordStack   = (UBINAIR *) minder [--mindex]; break;
					case 7 : TcodePtrStack	   = (EXABYTE **) minder [--mindex]; break;
					default: break;
					}
				  break;
		case _esc_GENDS : EsReg = (EXBPTR) calloc( freg [e] , 1 ); 
				  if ( EsReg == (EXBPTR) 0 ) { err_val = EXER_MEMFULL; return(0); }
				  break;			
		case _esc_FREDS : liberate(EsReg); break;
		case _esc_IPOPF : break;
		case _esc_FPOPI : break;
		case _esc_VARPT : break;

		case _esc_MEMRD : freg [e] = (BINAIRE) *((EXBPTR) (EsReg + freg [ DxReg ])); xreg [e] = 0; break;
		case _esc_MEMWR : *((EXBPTR) (EsReg + freg[ DxReg ])) = (char) freg [e]; break;
		case _esc_REGDX : DxReg = freg [e]; break;
		case _esc_DXREG : freg [e] = DxReg; xreg [e] = 0; break;
		case _esc_REGVF :
			if ( freg [e] >= diezreg ) {
				err_val = EXER_DEVFAIL;
				sprintf(SysLogBuffer, "Error: echapp failed, freg[e]=%d, diezreg=%d, err_val=%d", freg[e], diezreg, err_val);
				ExaSysLog(CheckExaSysLog, SysLogBuffer);
				return(0); 
			}
			break;
		case _esc_REGMX : freg [e] = diezreg; xreg [e] = 0; break;
		case _esc_FICMX : freg [e] = diezfic; xreg [e] = 0; break;
		case _esc_STKMX : freg [e] = diezstk; xreg [e] = 0; break;
		case _esc_TMPMX : freg [e] = dieztmp; xreg [e] = 0; break;
		default 	: break;
		}
	return(1);
}
