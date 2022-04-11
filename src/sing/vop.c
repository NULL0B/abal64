
int	on_show(int atx,int aty)
{
	window(10,10,690,510,font9.value,"Sing : Version 1.0a.0.01 : Abal Forms Editor",3);
	inset_frame(20,40,670,470);
	text_frame(30,50,645,22,44,0,font3.value,"Visual Object Properties ");
	text_frame(30,90,192,16,44,0,font1.value,"Instance identifier");
	edit_frame(230,90,200,16);
	text_frame(30,110,192,16,44,0,font1.value,"Instance class          ");
	edit_frame(230,110,200,16);
	text_frame(30,130,184,16,44,0,font1.value,"Position               ");
	text_frame(190,130,32,16,44,0,font1.value," X  ");
	edit_frame(230,130,64,16);
	text_frame(300,130,32,16,44,0,font1.value," Y  ");
	edit_frame(330,130,56,16);
	text_frame(30,150,184,16,44,0,font1.value,"Dimensions             ");
	text_frame(190,150,32,16,44,0,font1.value," W  ");
	edit_frame(230,150,64,16);
	text_frame(300,150,24,16,44,0,font1.value," H ");
	edit_frame(330,150,56,16);
	text_frame(30,170,190,20,44,0,font1.value,"Font identifier        ");
	edit_frame(230,170,48,16);
	text_frame(30,190,192,16,44,0,font1.value,"Text colour             ");
	edit_frame(230,190,104,16);
	text_frame(30,210,192,16,44,0,font1.value,"Background colour       ");
	edit_frame(230,210,104,16);

	return(0);
}
