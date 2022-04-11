BINAIRE	x_rand(goval)
BINAIRE	goval;
{
	BINAIRE	rnd;
	if ( goval != 0 ) { rnd_var = goval; }
	rnd_var = ((rnd_var * 1061) + 3251) / 16;
	rnd = (BINAIRE) ((rnd_var * 32767) / 100000L );
	return((rnd & 0x7FFF));
}

