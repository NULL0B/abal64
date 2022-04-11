//	--------------------------------------------------
//	Allow keyboard but without wait
//	-------------------------------
	if ( test_character() ) {
		testkbd = 1;
		(void) cico_function( get_character() );
		}
