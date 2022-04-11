#ifndef	_AOTCESC_H
#define	_AOTCESC_H

#define _esc_SGL (_tc_GWS | 0x80) /* Store Long Int to Global Long Offset	*/
#define _esc_SLL (_tc_LWS | 0x80) /* Store Long Int to Local  Long Offset	*/
#define _esc_GLS (_tc_GIS | 0x80) /* Store Reg to Global Long Offset 		*/
#define _esc_LLS (_tc_LIS | 0x80) /* Store Reg to Global Long Offset 		*/
#define _esc_GLL (_tc_GIL | 0x80) /* Load  Reg from  Global Long Offset 	*/
#define _esc_LLL (_tc_LIL | 0x80) /* Load  Reg from  Global Long Offset 	*/

#define _esc_SGH (_tc_GWS | 0x08) /* Store Long Int to Global Long Offset	*/
#define _esc_SLH (_tc_LWS | 0x08) /* Store Long Int to Local  Long Offset	*/
#define _esc_GHS (_tc_GIS | 0x08) /* Store Reg to Global Long Offset 		*/
#define _esc_LHS (_tc_LIS | 0x08) /* Store Reg to Global Long Offset 		*/
#define _esc_GHL (_tc_GIL | 0x08) /* Load  Reg from  Global Long Offset 	*/
#define _esc_LHL (_tc_LIL | 0x08) /* Load  Reg from  Global Long Offset 	*/

#define	_esc_GEC (_tc_OEV | 0x80) /* On Global Error Call */
#define	_esc_LEC (_tc_OLE | 0x80) /* On Local Error Call */

#define	_esc_SPN	_tc_LDI		/* x01 */
#define	_esc_LIB	_tc_ANX		/* x02 */

#define	_esc_PSI	_tc_GIS		/* x13 */
#define	_esc_PSC	_tc_LIS		/* x33 */
#define _esc_PSV	_tc_GIL		/* x53 */
#define	_esc_PSR	_tc_LIL		/* x73 */

#define	_esc_SGI	_tc_OEO		/* x10 */
#define	_esc_SGR	_tc_OEP		/* x30 */
#define	_esc_SGV	_tc_SGN		/* x50 */
#define _esc_SGW	0x0070		/* x70 */
#define	_esc_CLP	_tc_LCL		/* x17 */
#define	_esc_FMT	0x00FE		/* xFE */

#define	_esc_JMT	_tc_JMR		/* x32 */
#define	_esc_GST	_tc_GSR		/* x52 */
#define	_esc_RGT	0x0042
#define	_esc_RGS	0x0062


#define	_esc_RTI	_tc_ADC		/* x28 */
#define	_esc_RTV	_tc_MDC		/* x2C */
#define	_esc_RTR	_tc_ORC		/* x2E */

#define	_esc_RTS	_tc_GCL		/* x26 */
#define	_esc_ETS	_tc_DTV		/* x27 */
#define	_esc_ETP	_tc_VPT		/* x47 */

#define	_esc_RTP	_tc_GCS		/* x46 */
#define	_esc_STP	_tc_LCS		/* x66 */

#endif
	

