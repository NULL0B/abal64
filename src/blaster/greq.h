#ifndef	_greq_h
#define	_greq_h

#define	_SAMPLE_RATE	44100

#define	_MAX_50		_SAMPLE_RATE / 50
#define	_MAX_100	_SAMPLE_RATE / 100
#define	_MAX_200	_SAMPLE_RATE / 200
#define	_MAX_400	_SAMPLE_RATE / 400
#define	_MAX_800	_SAMPLE_RATE / 800
#define	_MAX_1600	_SAMPLE_RATE / 1600
#define	_MAX_3200	_SAMPLE_RATE / 3200
#define	_MAX_6400	_SAMPLE_RATE / 6400
#define	_MAX_12800	_SAMPLE_RATE / 12800

struct	graphic_equaliser	{
	int	mute;
	int	max50;
	int	ech50;
	int	hz50[_MAX_50];
	int	max100;
	int	ech100;
	int	hz100[_MAX_100];
	int	max200;
	int	ech200;
	int	hz200[_MAX_200];
	int	max400;
	int	ech400;
	int	hz400[_MAX_400];
	int	max800;
	int	ech800;
	int	hz800[_MAX_800];
	int	max1600;
	int	ech1600;
	int	hz1600[_MAX_1600];
	int	max3200;
	int	ech3200;
	int	hz3200[_MAX_3200];
	int	max6400;
	int	ech6400;
	int	hz6400[_MAX_6400];
	int	max12800;
	int	ech12800;
	int	hz12800[_MAX_12800];
	};


#endif	/* _gr_eq_h */
	/* -------- */

