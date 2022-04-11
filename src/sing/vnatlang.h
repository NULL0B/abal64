#ifndef	_vnatlang_h
#define	_vnatlang_h

struct	visual_language_message {
	char	*	message[8];
	};

#ifdef __cplusplus	/* GWB le 05/06/207 */
extern "C" {
#endif
struct	visual_language_message * visual_empty_message();
#ifdef __cplusplus	/* GWB le 05/06/207 */
}
#endif

#endif	/* _vnatlang_h */

