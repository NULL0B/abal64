/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRTCODE.H				*/
/*		Version :	2.1d					*/
/*		Date	:	20/12/1994				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRTCODE_H
#define	_TRTCODE_H

/*	---------------		*/
/*	Standard Tcodes		*/
/*	---------------		*/

#define	_tc_ESC		0x0000
#define _tc_LDI		0x0001 
#define _tc_ANX		0x0002
#define _tc_LXI		0x0003
#define _tc_AXI		0x0004
#define _tc_RAZ		0x0005
#define _tc_RET		0x0006
#define _tc_GSB		0x0007
#define _tc_ADI		0x0008
#define _tc_SBI		0x0009
#define _tc_MLI		0x000A
#define _tc_DVI		0x000B
#define _tc_MDI		0x000C
#define _tc_ANI		0x000D
#define _tc_ORI		0x000E
#define _tc_XRI		0x000F
#define _tc_OEO		0x0010
#define _tc_OLE		0x0057
#define _tc_INC		0x0011
#define _tc_JMI		0x0012
#define _tc_GIS		0x0013
#define _tc_STI		0x0014
#define _tc_CLF		0x0015
#define _tc_NEW		0x0016
#define _tc_LCL		0x0017
#define _tc_JEQI	0x0018
#define _tc_JNEI	0x0019
#define _tc_JGEI	0x001A
#define _tc_JLEI	0x001B
#define _tc_JGRI	0x001C
#define _tc_JLSI	0x001D
#define _tc_TIM		0x0020
#define _tc_LDC		0x0021	
#define _tc_DAX		0x0022
#define _tc_LXC		0x0023
#define _tc_AXC		0x0024
#define _tc_PSH		0x0025
#define _tc_GCL		0x0026
#define _tc_DTV		0x0027
#define _tc_ADC		0x0028
#define _tc_SBC		0x0029
#define _tc_MLC		0x002A
#define _tc_DVC		0x002B
#define _tc_MDC		0x002C
#define _tc_ANC		0x002D
#define _tc_ORC		0x002E
#define _tc_XRC		0x002F
#define _tc_OEP		0x0030
#define _tc_DEC		0x0031
#define _tc_LIS		0x0033
#define _tc_STC		0x0034
#define _tc_NGF		0x0035
#define _tc_TPC		0x0036
#define _tc_CNV		0x0037
#define _tc_JEQC	0x0038
#define _tc_JNEC	0x0039
#define _tc_JGEC	0x003A
#define _tc_JLEC	0x003B
#define _tc_JGRC	0x003C
#define _tc_JLSC	0x003D
#define _tc_JINC	0x003E
#define _tc_JNIC	0x003F
/* #define _tc_OEO	0x0020 */
#define _tc_OEV		0x0040
#define _tc_LDV		0x0041
#define _tc_ERA		0x0042
#define _tc_LXV		0x0043
#define _tc_AXV		0x0044
#define _tc_POP		0x0045
#define _tc_GCS		0x0046
#define _tc_VPT		0x0047
#define _tc_ADV		0x0048
#define _tc_SBV		0x0049
#define _tc_MLV		0x004A
#define _tc_DVV		0x004B
#define _tc_MDV		0x004C
#define _tc_ANV		0x004D
#define _tc_ORV		0x004E
#define _tc_XRV		0x004F
#define _tc_SGN		0x0050
#define _tc_INX		0x0051
#define _tc_GIL		0x0053
#define _tc_STV		0x0054
#define _tc_IOF		0x0055
#define _tc_NOP		0x0056
#define _tc_JEQV	0x0058
#define _tc_JNEV	0x0059
#define _tc_JGEV	0x005A
#define _tc_JLEV	0x005B
#define _tc_JGRV	0x005C
#define _tc_JLSV	0x005D
#define _tc_JINV	0x005E
#define _tc_JNIV	0x005F
#define _tc_RES		0x0060
#define _tc_LDR		0x0061
#define _tc_NGR		0x0062
#define _tc_LXR		0x0063
#define _tc_AXR		0x0064
#define _tc_LDF		0x0065
#define _tc_LCS		0x0066
#define _tc_REQ		0x0067
#define _tc_ADR		0x0068
#define _tc_SBR		0x0069
#define _tc_MLR		0x006A
#define _tc_DVR		0x006B
#define _tc_MDR		0x006C
#define _tc_ANR		0x006D
#define _tc_ORR		0x006E
#define _tc_XRR		0x006F
#define _tc_LDE		0x0070
#define _tc_DEX		0x0071
#define _tc_NGV		0x0072
#define _tc_LIL		0x0073
#define _tc_STR		0x0074
#define _tc_GWS		0x0075 
#define _tc_WHN		0x0076
#define _tc_LWS		0x0077
#define _tc_JEQR	0x0078
#define _tc_JNER	0x0079
#define _tc_JGER	0x007A
#define _tc_JLER	0x007B
#define _tc_JGRR	0x007C
#define _tc_JLSR	0x007D
#define _tc_JINR	0x007E
#define _tc_JNIR	0x007F
#define	_tc_NEWLINE	0x0080		


/*	-------------		*/
/*	Escape Tcodes		*/
/*	-------------		*/

#define	_esc_SGI		0x0010		/* LDGO.SEG BYTE	*/
#define	_esc_PSI		0x0013		/* PAUSE    WORD	*/
#define	_esc_CLP		0x0017		/* CALL	PROCEDURE	*/
#define	_esc_RTS   		0x0026		/* RET.SEG		*/
#define	_esc_ETS		0x0027		/* END.SEG		*/
#define	_esc_RTI		0x0028		/* ERROR WORD		*/
#define	_esc_RTV		0x002C		/* ERROR VARB		*/
#define	_esc_RTR		0x002E		/* ERROR REG		*/
#define	_esc_SGR		0x0030		/* LDGO.SEG EXPRESSION	*/
#define	_esc_JMR		0x0032		/* JUMP EXPRESSION	*/
#define	_esc_PSC		0x0033		/* PAUSE CONSTANT	*/
#define	_esc_RGT 		0x0042		/* EXIT			*/
#define	_esc_RTP 		0x0046		/* EXIT			*/
#define	_esc_ETP		0x0047		/* END.PROC		*/
#define	_esc_SGV		0x0050		/* LDGO.SEG VARIABLE	*/
#define	_esc_GSR		0x0052		/* GOSUB EXPRESSION	*/
#define	_esc_PSV		0x0053		/* PAUSE VARIABLE	*/
#define	_esc_RGS		0x0062		/* STOP			*/
#define	_esc_STP		0x0066		/* STOP			*/
#define	_esc_SGW		0x0070		/* LDGO.SEG WORD	*/
#define	_esc_PSR		0x0073		/* PAUSE EXPRESSION	*/

#if	otr32 || otr64

#define _esc_SGL (_tc_GWS | 0x80) /* Store Long Int to Global Long Offset*/
#define _esc_SLL (_tc_LWS | 0x80) /* Store Long Int to Local  Long Offset*/
#define _esc_GLS (_tc_GIS | 0x80) /* Store Reg to Global Long Offset 	*/
#define _esc_LLS (_tc_LIS | 0x80) /* Store Reg to Global Long Offset 	*/
#define _esc_GLL (_tc_GIL | 0x80) /* Load  Reg from  Global Long Offset 	*/
#define _esc_LLL (_tc_LIL | 0x80) /* Load  Reg from  Global Long Offset 	*/

#endif



/*	CLF TCODES	*/
/*	----------	*/
#define	_clf_ETS	0x00C7


#endif	/* _TRTCODE_H */
	/* ---------- */
