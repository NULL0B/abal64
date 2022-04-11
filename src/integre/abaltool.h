#ifndef	_abaltool_h
#define	_abaltool_h

static	int	AbalToolVersion=3;

static	char *	Abal3Tools[] = {

	(char*) "aed32",
	(char*) "otr32",
	(char*) "old32",
	(char*) "agr32",

	(char*) "exa32",
	(char*) "exadb32",

	(char*) "amake32",
	(char*) "genmake",

	(char*) "ecran",
	(char*) "transbal",

	(char*) "svam.at",
	(char*) "rtam.at",

	(char*) "sing",
	(char*) "avnor"

	};

static	char *	Abal2Tools[] = {
	(char*) "aed",
	(char*) "atr",
	(char*) "ald",
	(char*) "agr",

	(char*) "exa",
	(char*) "exadb",

	(char*) "amake",
	(char*) "genmake",

	(char*) "ecran",
	(char*) "transbal",

	(char*) "svam.at",
	(char*) "rtam.at"
	};

#define	AbalToolAed   		(AbalToolVersion != 3 ? Abal2Tools[ 0] : Abal3Tools[0])
#define	AbalToolAtr   		(AbalToolVersion != 3 ? Abal2Tools[ 1] : Abal3Tools[ 1])
#define	AbalToolAld   		(AbalToolVersion != 3 ? Abal2Tools[ 2] : Abal3Tools[ 2])
#define	AbalToolAgr   		(AbalToolVersion != 3 ? Abal2Tools[ 3] : Abal3Tools[ 3])
#define	AbalToolExa   		(AbalToolVersion != 3 ? Abal2Tools[ 4] : Abal3Tools[ 4])
#define	AbalToolExadb 		(AbalToolVersion != 3 ? Abal2Tools[ 5] : Abal3Tools[ 5])
#define	AbalToolAmake 		(AbalToolVersion != 3 ? Abal2Tools[ 6] : Abal3Tools[ 6])
#define	AbalToolGenmake		(AbalToolVersion != 3 ? Abal2Tools[ 7] : Abal3Tools[ 7])
#define	AbalToolEcran 		(AbalToolVersion != 3 ? Abal2Tools[ 8] : Abal3Tools[ 8])
#define	AbalToolTransbal	(AbalToolVersion != 3 ? Abal2Tools[ 9] : Abal3Tools[ 9])
#define	AbalToolSvam  		(AbalToolVersion != 3 ? Abal2Tools[10] : Abal3Tools[10])
#define	AbalToolRtam  		(AbalToolVersion != 3 ? Abal2Tools[11] : Abal3Tools[11])
#define	AbalToolSing  		(AbalToolVersion != 3 ? Abal3Tools[12] : Abal3Tools[12])
#define	AbalToolAvnor 		(AbalToolVersion != 3 ? Abal3Tools[13] : Abal3Tools[13])

#endif	/* _abaltool_h */


