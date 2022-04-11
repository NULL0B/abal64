#ifndef	UTCONSTH
#define	UTCONSTH

/*	Amake options internal representation value constants	*/
/*	-----------------------------------------------------	*/
#define _SILENCE 	0x0001	/* Silence is required		*/
#define	_INHIBIT_ACTION	0x0002	/* Display but do not execute	*/
#define	_IGNORE_ERRORS	0x0004	/* Ignore invocation errors	*/
#define	_PREPROCESS	0x0008	/* Preprocess to stdout		*/
#define	_DEBUG_DATE	0x0010	/* Debug Target/Depend dates	*/
#define	_ENVIRON	0x0020	/* Environment then internal	*/
#define	_DEFAULT_SUFFIX	0x0040	/* Use default suffixes		*/
#define	_TOUCH_TARGET	0x0080	/* Touch if exist else exec	*/
#define	_VERIFICATION	0x0100	/* Verification only		*/
#define	_FORCE_REBUILD	0x0200	/* Rebuild all targets		*/


#define	_TARGET_OK	0x1000	/* Target ok if source error	*/

#define	_INFERENCE	0x4000	/* Check default inferences	*/

#endif	/* UTCONSTH */
	/* -------- */

