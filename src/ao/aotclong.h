#ifndef	_aotclong_h
fuck me 
#define	_aotclong_h
// INT 32 optimisation tcodes
#define _esc_SGL (_tc_GWS | 0x80) /* Store Long Int to Global Long Offset	*/
#define _esc_SLL (_tc_LWS | 0x80) /* Store Long Int to Local  Long Offset	*/
#define _esc_GLS (_tc_GIS | 0x80) /* Store Reg to Global Long Offset 		*/
#define _esc_LLS (_tc_LIS | 0x80) /* Store Reg to Global Long Offset 		*/
#define _esc_GLL (_tc_GIL | 0x80) /* Load  Reg from  Global Long Offset 	*/
#define _esc_LLL (_tc_LIL | 0x80) /* Load  Reg from  Global Long Offset 	*/
// INT 64 optimisation tcodes
#define _esc_SGH (_tc_GWS | 0x08) /* Store Huge Int to Global Long Offset	*/
#define _esc_SLH (_tc_LWS | 0x08) /* Store Huge Int to Local  Long Offset	*/
#define _esc_GHS (_tc_GIS | 0x08) /* Store Reg to Global Huge Offset 		*/
#define _esc_LHS (_tc_LIS | 0x08) /* Store Reg to Global Huge Offset 		*/
#define _esc_GHL (_tc_GIL | 0x08) /* Load  Reg from  Global Huge Offset 	*/
#define _esc_LHL (_tc_LIL | 0x08) /* Load  Reg from  Global Huge Offset 	*/
#endif	/* _aotclong_h */

