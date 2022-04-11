long	random_seed=0L;

void	srandom(int v)	{ random_seed = v; return; }

int	random()
{
	int	rnd;
	random_seed = ((random_seed * 1061) + 3251) / 16;
	rnd = (int) ((random_seed * 32767) / 100000L );
	return(rnd);
}






