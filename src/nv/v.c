#include <stdio.h>
int	main(int argc, char * argv[])
{
	FILE * h;

	if ((h = fopen("visual.def","w")) != (FILE*) 0) {
		fprintf(h,"Version 1\n");
		fprintf(h,"\nRuntime %cvisual%c\n",0x0022,0x0022);
		fprintf(h,"\n%% VisualZone(x%%,y%%,w%%,h%,p%%)");
		fprintf(h,"\n%% VisualLine(x%%,y%%,x%%,y%%,p%%)");
		fprintf(h,"\n%% VisualFont(fontname$,length%%)");
		fprintf(h,"\n%% VisualText(x%%,y%%,w%%,h%%,fid%%,message$,length%%)");
		fprintf(h,"\n%% VisualEdit(x%%,y%%,w%%,h%%,fid%%,buffer$?,length%%)");
		fprintf(h,"\n%% VisualWindow(x%%,y%%,w%%,h%%,fid%%,message$,length%%)");
		fprintf(h,"\n%% VisualButton(x%%,y%%,w%%,h%%,fid%%,message$,length%%,state%%)");
		fprintf(h,"\n%% VisualCheck(x%%,y%%,w%%,h%%,fid%%,message$,length%%,state%%)");
		fprintf(h,"\n%% VisualRadio(x%%,y%%,w%%,h%%,fid%%,message$,length%%,state%%)");
		fprintf(h,"\n%% VisualImage(x%%,y%%,w%%,h%%,filename$,length%%)");
		fprintf(h,"\n%% VisualTabView(x%%,y%%,w%%,h%%,fid%%,message$,length%%,state%%)");
		fprintf(h,"\n%% VisualSelect(x%%,y%%,w%%,h%%,fid%%,message$,length%%,state%%)");
		fprintf(h,"\n%% VisualScroll(x%%,y%%,w%%,h%%,fid%%,nombre%%)");
		fprintf(h,"\n%% VisualPalette(filename$,length%%)");
		fprintf(h,"\n%% VisualInitialise(options%%)");
		fprintf(h,"\n%% VisualLiberate()");
		fprintf(h,"\nEnd\n");
		fclose(h);
		}
	return(0);
}





