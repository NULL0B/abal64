#ifndef VTHOLOGIC_H
#define VTHOLOGIC_H

	void InitialiseWindowSystem();
	void DestroyWindowSystem();

	int CreateNewWindow(WORD x1,WORD y1,WORD x2,WORD y2);
	//int DestroyActiveWindow();

  int DestroyCurrentWindow();
  	
	void LoadAndAssociateStandardBitmaps(char* EnvPath);
	void DestroyStandardBitmaps();
	
	TI_RECTANGLE GetActiveWindowCoo();
	void PileWindow(int flag,int no, WORD x1,WORD y1,WORD x2,WORD y2);
	int GetWindowID();
	void SetChangeFlag();
	void LoadStandardIcons(char* EnvPath);
	void DestroyStandardIcons();
	void move_it(WORD x,WORD y,WORD ll,WORD hh,WORD nx,WORD ny);
	extern WORD window_counter;

#endif
