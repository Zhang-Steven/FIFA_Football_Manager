#include "mainf.h"
#include"welcomf.h"
void show_main_face(void)
{
	  int i;
	  cleardevice();
	  setwritemode(COPY_PUT);
	  setfillstyle(SOLID_FILL,BLACK);
	  bar(0,0,X_MAX-1,Y_MAX-1);
	  setfillstyle(SOLID_FILL,LIGHTGRAY);
	  bar(5,5,55,35);
	  bar(585,5,635,35);
	  setcolor(WHITE);
	  setlinestyle(0,0,2);
	  rectangle(5,45,355,375);
	  line(305,348,305,375);
	  line(255,348,255,375);
	  for(i=1;i<=10;i++)
	  {
		 line(5,55+30*i-8,355,55+30*i-8); 
	  }
	  setfillstyle(SOLID_FILL,YELLOW);
	  bar(5,400,105,450);
	  bar(125,400,225,450);
	  bar(245,400,345,450);
	  showHString(30,20,"返回",1,BLACK);
	  showHString(280,360,"上页",1,WHITE);
	  showHString(330,360,"下页",1,WHITE);
	  showHString(55,425,"球员市场",1,BLACK);
	  showHString(175,425,"管理球队",1,BLACK);
	  showHString(295,425,"参加比赛",1,BLACK);
	  showHString(610,20,"帮助",1,BLACK);
	
	  
}
void show_main_face_manage(void)
{
	int flag=0,pre_flag=0;
	int state;
	int key;
	show_main_face();
	showMouse();
	updateGMouse();
	while(1)
	{
		key=bioskey(1);
		if(gMouse.x>=5&&gMouse.x<=55&&gMouse.y>=5&&gMouse.y<=35)
		{
			if(gMouse.button==1)
			{
				hideMouse();
				cleardevice();
				WelcomeFaceManage();
			}
		}
		if(key==ESC){
			WelcomeFaceManage();
		}
	}
}