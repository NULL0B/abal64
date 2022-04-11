
				/* ----------------------------	*/
#ifndef	TCODELENH		/* Ensure not already included	*/
#define	TCODELENH		/* Avoid multiple inclusions	*/
				/* ----------------------------	*/

/*	Tcode sequence lengths		*/
/*	----------------------		*/
/*	NB length 0 means variable	*/
/*	length defined by args		*/

#define    _ln_ESC	0
#define    _ln_IOF	0
#define    _ln_NGF	0
#define    _ln_CLF	0
#define    _ln_LDF	0
#define    _ln_TIM	0
#define    _ln_WHN	0
#define    _ln_NOP	1
#define    _ln_RAZ	1
#define    _ln_NEW	1
#define    _ln_RET	1
#define    _ln_RES	1
#define    _ln_ERA	1
#define    _ln_SGN	1
#define    _ln_INC	2
#define    _ln_DEC	2
#define    _ln_INX	2
#define    _ln_DEX	2
#define    _ln_ANX	2
#define    _ln_DAX	2
#define    _ln_PSH	2
#define    _ln_POP	2
#define    _ln_NGR	2
#define    _ln_DTR	2
#define    _ln_JMR	2
#define    _ln_JMV	3
#define    _ln_GSB	3
#define    _ln_JMI	3
#define    _ln_REQ	3
#define    _ln_LDR	3
#define    _ln_LXR	3
#define    _ln_AXR	3
#define    _ln_NGV	3
#define    _ln_DTV	3
#define    _ln_CNV	3
#define    _ln_C2R	4
#define    _ln_LDV	4
#define    _ln_LDC	4
#define    _ln_LDI	4
#define    _ln_LXV	4
#define    _ln_LXC	4
#define    _ln_LXI	4
#define    _ln_AXV	4
#define    _ln_AXC	4
#define    _ln_AXI	4
#define    _ln_STR	4
#define    _ln_ADR	4
#define    _ln_SBR	4
#define    _ln_MLR	4
#define    _ln_DVR	4
#define    _ln_MDR	4
#define    _ln_ANR	4
#define    _ln_ORR	4
#define    _ln_XOR	4
#define    _ln_GIL	4
#define    _ln_GIS	4
#define    _ln_LIL	4
#define    _ln_LIS	4
#define    _ln_GCL	4
#define    _ln_GCS	4
#define    _ln_LCL	4
#define    _ln_LCS	4
#define    _ln_OER	4
#define    _ln_V2R	4
#define    _ln_R2R	4
#define    _ln_OPR	4
#define    _ln_VPT	4
#define    _ln_ADI	5
#define    _ln_SBI	5
#define    _ln_MLI	5
#define    _ln_DVI	5
#define    _ln_MDI	5
#define    _ln_ANI	5
#define    _ln_ORI	5
#define    _ln_XRI	5
#define    _ln_ADC	5
#define    _ln_SBC	5
#define    _ln_MLC	5
#define    _ln_DVC	5
#define    _ln_MDC	5
#define    _ln_ANC	5
#define    _ln_ORC	5
#define    _ln_XRC	5
#define    _ln_ADV	5
#define    _ln_SBV	5
#define    _ln_MLV	5
#define    _ln_DVV	5
#define    _ln_MDV	5
#define    _ln_ANV	5
#define    _ln_ORV	5
#define    _ln_XRV	5
#define    _ln_STI	5
#define    _ln_STV	5
#define    _ln_STC	5
#define    _ln_JEQR	5
#define    _ln_JNER	5
#define    _ln_JGRR	5
#define    _ln_JLSR	5
#define    _ln_JGER	5
#define    _ln_JLER	5
#define    _ln_JINR	5
#define    _ln_JNIR	5
#define    _ln_OEV	5
#define    _ln_OPV	5
#define    _ln_JEQV	6
#define    _ln_JNEV	6
#define    _ln_JGRV	6
#define    _ln_JLSV	6
#define    _ln_JGEV	6
#define    _ln_JLEV	6
#define    _ln_JINV	6
#define    _ln_JNIV	6
#define    _ln_JEQC	6
#define    _ln_JNEC	6
#define    _ln_JGRC	6
#define    _ln_JLSC	6
#define    _ln_JGEC	6
#define    _ln_JLEC	6
#define    _ln_JINC	6
#define    _ln_JNIC	6
#define    _ln_JEQI	6
#define    _ln_JNEI	6
#define    _ln_JGRI	6
#define    _ln_JLSI	6
#define    _ln_JGEI	6
#define    _ln_JLEI	6
#define    _ln_GVP	8
#define    _ln_LVP	8

/*	Tcode length table (ordered wrt tcode values)	*/
/*	---------------------------------------------	*/

EXAWORD	CodeLen[128] = {

    _ln_ESC,_ln_LDI,_ln_ANX,_ln_LXI,_ln_AXI,_ln_RAZ,_ln_RET,_ln_GSB,
    _ln_ADI,_ln_SBI,_ln_MLI,_ln_DVI,_ln_MDI,_ln_ANI,_ln_ORI,_ln_XRI,
    _ln_GVP,_ln_INC,_ln_JMI,_ln_GIS,_ln_STI,_ln_CLF,_ln_NEW,_ln_LCL,
    _ln_JEQI,_ln_JNEI,_ln_JGEI,_ln_JLEI,_ln_JGRI,_ln_JLSI,_ln_DTR,_ln_OER,

    _ln_TIM,_ln_LDC,_ln_DAX,_ln_LXC,_ln_AXC,_ln_PSH,_ln_GCL,_ln_DTV,
    _ln_ADC,_ln_SBC,_ln_MLC,_ln_DVC,_ln_MDC,_ln_ANC,_ln_ORC,_ln_XRC,
    _ln_LVP,_ln_DEC,_ln_JMR,_ln_LIS,_ln_STC,_ln_NGF,_ln_OPV,_ln_CNV,
    _ln_JEQC,_ln_JNEC,_ln_JGEC,_ln_JLEC,_ln_JGRC,_ln_JLSC,_ln_JINC,_ln_JNIC,

    _ln_OEV,_ln_LDV,_ln_ERA,_ln_LXV,_ln_AXV,_ln_POP,_ln_GCS,_ln_VPT,
    _ln_ADV,_ln_SBV,_ln_MLV,_ln_DVV,_ln_MDV,_ln_ANV,_ln_ORV,_ln_XRV,
    _ln_SGN,_ln_INX,_ln_JMV,_ln_GIL,_ln_STV,_ln_IOF,_ln_NOP,_ln_OPR,
    _ln_JEQV,_ln_JNEV,_ln_JGEV,_ln_JLEV,_ln_JGRV,_ln_JLSV,_ln_JINV,_ln_JNIV,

    _ln_RES,_ln_LDR,_ln_NGR,_ln_LXR,_ln_AXR,_ln_LDF,_ln_LCS,_ln_REQ,
    _ln_ADR,_ln_SBR,_ln_MLR,_ln_DVR,_ln_MDR,_ln_ANR,_ln_ORR,_ln_XOR,
    _ln_C2R,_ln_DEX,_ln_NGV,_ln_LIL,_ln_STR,_ln_R2R,_ln_WHN,_ln_V2R,
    _ln_JEQR,_ln_JNER,_ln_JGER,_ln_JLER,_ln_JGRR,_ln_JLSR,_ln_JINR,_ln_JNIR

	};

#endif
