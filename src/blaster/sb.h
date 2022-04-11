#ifndef	_SB_H
#define	_SB_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#ifdef	ABALAUDIO
#include <sys/soundcard.h>
#endif
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <signal.h>

#include	"bda.h"
#include	"catcher.h"

#define	__DRIVER_NAME	"SB"
#define	__DRIVER_DATE	"12/10/2004"
#define __DRIVER_MAJOR 	'1'
#define __DRIVER_MINOR 	'1'
#define __DRIVER_INDEX 	'a'

#define	MAX_BUFFER_SIZE 0x8000
#define	MAX_TRACKS	32

/*	--------------------------	*/
/*	Sound Blaster Mixer Levels 	*/
/*	--------------------------	*/
#define	__SB_VOICE_LEVEL	0x0004
#define	__SB_MIC_LEVEL		0x000A
#define	__SB_MASTER_LEVEL	0x0022
#define	__SB_FM_LEVEL		0x0026
#define	__SB_CD_LEVEL		0x0028
#define	__SB_LINE_LEVEL		0x002E

#define	__SB_RECORD_SOURCE	0x000C

#define	PRIVATE	static
#define	PUBLIC	
#define	EXTERN	extern
#define	BPTR	char * 

BDA	desrt;				/* library description */
EXTERN BDA_INIT FAR PTR rt_init;	/* library signing */
EXTERN BDA_ARG rt_arg;			/* arguments description */

/*	---------------------------	*/
/*	Sound management structures	*/
/*	---------------------------	*/
#include "greq.h"

struct	control_master	{
	int	left;
	int	right;
	int	graphic[9][2];
	struct 	graphic_equaliser eql;
	struct 	graphic_equaliser eqr;
	} Master = { 0,0,0,0 };


struct	control_message	{
	long	type;
	int	track;
	int	item;
	int	value;
	int	extra;
	char	nomfic[256];
	};

struct	track_control	{
	char		    *	name;
	struct	wave_handle * 	sample;
	int			active;
	int			pan;
	int			solo;
	int			mute;
	int			left;
	int			right;
	int			level;
	int			loop;
	};


#ifdef LINT_ARGS

	VOID FAR PTR InitRelais(VOID);
PRIVATE	VOID FAR banniere(VOID);
EXTERN	VOID rt_error(WORD);

#else

	VOID FAR PTR InitRelais();
PRIVATE	VOID FAR banniere();
EXTERN	VOID rt_error();

#endif /* LINT_ARGS */


	/* ----------- */
#endif	/* _SB_H */
	/* ----------- */

