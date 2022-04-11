public	int visual_liberate()
{
	configuration_drop();
	terminate_mouse();
	if (!( liberatepixel() ))
		cicopalette(0,16);
	cancel_replay_record();
	release_images();
	return(0);
}


