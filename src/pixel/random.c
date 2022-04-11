long	random_seed=0L;

void	srandom(unsigned int v)	{ random_seed = v; return; }

unsigned int	random()
{
	unsigned long	rnd;
	random_seed = ((random_seed * 1061L) + 3251L) / 16;
	rnd = (unsigned long) ((random_seed * 32767L) / 100000L );
	return(rnd);
}


