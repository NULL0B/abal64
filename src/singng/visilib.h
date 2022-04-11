#ifndef	_VISILIB_H
#define	_VISILIB_H

/*	Macro redefinitions 	*/
/*	-------------------	*/
#ifndef	EXAWORD
#ifdef	UNIX
#define	EXAWORD unsigned long
#else
#define	EXAWORD unsigned short
#endif
#endif

#define	VisualInitialise(a)			visual_initialise(a)
#define	VisualActivate(a,b,c) 			visual_activate(a,b,c)
#ifdef WIN32
#define	VisualTerminate()			visual_liberate()
#else
#define	VisualTerminate 			visual_liberate
#endif
#define	VisualFreeze() 				visual_freeze()
#define	VisualThaw(a,b,c,d) 			visual_thaw(a,b,c,d)
#define	VisualFill(a,b,c,d,e) 			filzone(a,b,c,d,e)
#define	VisualRect(a,b,c,d,e) 			relief(a,b,c,d,e,0,e);
#define	VisualCirc(a,b,c,d,e)			drawcircle(a,b,c,d,e,0);
#define	VisualDisc(a,b,c,d,e) 			drawcircle(a,b,c,d,e,1);
#define	VisualFrame(a,b,c,d,e) 			visual_frame(a,b,c,d,e)
#define	VisualImage(a,b,c,d,e,f,g) 		visual_image(a,b,c,d,e,g)
#define	VisualFont(a,b) 			visual_font(a,b)
#define	VisualPalette(a,b) 			visual_palette(a,b)
#define	VisualWindow(a,b,c,d,f,t,l,o)		visual_window(a,b,c,d,f,t,l,o)
#define	VisualEdit(a,b,c,d,f,z,l) 		visual_edit(a,b,c,d,f,z,l)
#define	VisualText(a,b,c,d,e,f,g,h,i,j) 	visual_text(a,b,c,d,e,f,g,h,i,j)
#define	VisualButton(a,b,c,d,e,f,g,h,i,j) 	visual_button(a,b,c,d,e,f,g,h,i,j)
#define	VisualCheck(a,b,c,d,e,f,g,h,i,j) 	visual_check(a,b,c,d,e,f,g,h,i,j)
#define	VisualSwitch(a,b,c,d,e,f,g,h,i,j) 	visual_switch(a,b,c,d,e,f,g,h,i,j)
#define	VisualGraph(a,b,c,d,e,f,g,h,i,j) 	visual_graph(a,b,c,d,e,f,g,h,i,j)
#define	VisualRadio(a,b,c,d,e,f,g,h,i,j,k) 	visual_radio(a,b,c,d,e,f,g,h,i,j,k)
#define	VisualProgress(a,b,c,d,e,f,g,h,i,j)	visual_progress(a,b,c,d,e,f,g,h,i,j)
#define	VisualTable(a,b,c,d,e,f,g,h,i,j,k) 	visual_table(a,b,c,d,e,f,g,h,i,j,k)
#define	StyledTable(a,b,c,d,e,f,g,h,i,j,k) 	styled_table(a,b,c,d,e,f,g,h,i,j,k)
#define	VisualScrollBar(a,b,c,d,e,f,g,h,i,j,k)	visual_scrollbar(a,b,c,d,e,f,g,h,i,j,k)
#define	VisualTabPage(a,b,c,d,e,f,g,h,i) 	visual_tabpage(a,b,c,d,e,f,g,h,i)
#define	VisualEvent(n) 				visual_event(n)
#define	VisualGetch() 				visual_getch()
#define	VisualKbhit() 				visual_kbhit()
#define	VisualLine(a,b,c,d,e,f) 		visual_line(a,b,c,d,e,f)
#define	VisualColour(a,b,c,d)			visual_colour(a,b,c,d)
#define	VisualViewPort(a,b,c,d,f) 		visual_viewport(a,b,c,d,f)
#define	VisualPlaySound(a) 			visual_play_sound(a)
#define	VisualHide()				visual_freeze() /* hide() */
#define	VisualShow(a,b,c,d)			visual_thaw(a,b,c,d) /* show(a,b,c,d) */

#ifndef	WIN32
EXAWORD	VisualInitialise(WORD);
EXAWORD	VisualActivate(WORD,WORD,WORD);
EXAWORD	VisualTerminate();
EXAWORD	VisualFreeze();
EXAWORD	VisualThaw(WORD,WORD,WORD,WORD);
EXAWORD	VisualLineFill(WORD,WORD,WORD,WORD,WORD,WORD);
EXAWORD	VisualFrame(WORD,WORD,WORD,WORD,WORD);
EXAWORD	VisualLine(WORD,WORD,WORD,WORD,WORD,WORD);
EXAWORD	VisualFont(BPTR,WORD);
EXAWORD	VisualPalette(BPTR,WORD);
EXAWORD	VisualWindow(WORD,WORD,WORD,WORD,WORD,BPTR,WORD,WORD);
EXAWORD	VisualEdit(WORD,WORD,WORD,WORD,WORD,BPTR,WORD);
EXAWORD	VisualImage(WORD,WORD,WORD,WORD,BPTR,WORD,WORD);
EXAWORD	VisualText(WORD,WORD,WORD,WORD, WORD,WORD,WORD, BPTR,WORD,WORD);
EXAWORD	VisualButton(WORD,WORD,WORD,WORD, WORD,WORD,WORD, BPTR,WORD,WORD);
EXAWORD	VisualCheck(WORD,WORD,WORD,WORD, WORD,WORD,WORD, BPTR,WORD,WORD);
EXAWORD	VisualRadio(WORD,WORD,WORD,WORD, WORD,WORD,WORD, BPTR,WORD,WORD,WORD);
EXAWORD	VisualSelect(WORD,WORD,WORD,WORD,WORD,WORD,WORD,BPTR,WORD,unsigned int *,WORD);
EXAWORD	VisualProgess(WORD,WORD,WORD,WORD, WORD,WORD,WORD,WORD);
EXAWORD	VisualTabPage(WORD,WORD,WORD,WORD, WORD,BPTR,WORD,WORD,WORD);
EXAWORD	VisualEvent(WORD);
EXAWORD	VisualGetch();
EXAWORD	VisualKbhit();
EXAWORD	VisualViewPort(WORD,WORD,WORD,WORD, WORD);
#endif	/* WIN32 */
#endif	/* _VISILIB_H */





