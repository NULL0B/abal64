//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_ppp_stats_h
#define _ppp_stats_h



struct ppp_stats {
	int	ulen;
	int	num_voie;
	char name[10];
	int status;     
	int phase;
	void	* sc;		/* struct ppp_softc far * sc; */
	void	* got;		/* struct ipcp_options far * got;  */
	void	* his;		/* struct ipcp_options far * his; */
	};

#endif	// _ppp_stats_h



