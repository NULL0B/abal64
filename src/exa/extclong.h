#ifndef	_extclong_h
#define	_extclong_h
// INT 32 optimisation tcodes
#define _tc_SGL (_tc_GWS | 0x80) /* Store Long Int to Global Long Offset*/
#define _tc_SLL (_tc_LWS | 0x80) /* Store Long Int to Local  Long Offset*/
#define _tc_GLS (_tc_GIS | 0x80) /* Store Reg to Global Long Offset 	*/
#define _tc_LLS (_tc_LIS | 0x80) /* Store Reg to Global Long Offset 	*/
#define _tc_GLL (_tc_GIL | 0x80) /* Load  Reg from  Global Long Offset 	*/
#define _tc_LLL (_tc_LIL | 0x80) /* Load  Reg from  Global Long Offset 	*/
// INT 64 optimisation tcodes
#define _tc_SGH (_tc_GWS | 0x08) /* Store Huge Int to Global Long Offset*/
#define _tc_SLH (_tc_LWS | 0x08) /* Store Huge Int to Local  Long Offset*/
#define _tc_GHS (_tc_GIS | 0x08) /* Store Reg to Global Huge Offset 	*/
#define _tc_LHS (_tc_LIS | 0x08) /* Store Reg to Global Huge Offset 	*/
#define _tc_GHL (_tc_GIL | 0x08) /* Load  Reg from  Global Huge Offset 	*/
#define _tc_LHL (_tc_LIL | 0x08) /* Load  Reg from  Global Huge Offset 	*/
#endif	/* _extclong_h */

