#include "welcomf.h"

/***********************************
Function:showwelcomeface
Description:鏄剧ず娆㈣繋鐣岄潰鍙婃枃瀛?
return:鏃?
***********************************/
void ShowWelcomeFace(void)
{


	int d[]={420,5,635,5,635,475,220,475,420,5};

	cleardevice();
    setwritemode(COPY_PUT);
	//鐢诲妗?
	setfillstyle(SOLID_FILL,YELLOW);
	bar(0,0,X_MAX-1,Y_MAX-1);
	//鐢昏冻鐞冨満
	setfillstyle(SOLID_FILL,GREEN);
	bar(5,5,X_MAX-5,Y_MAX-5);
	setcolor(WHITE);
	setlinestyle(0,0,3);
	circle(X_MAX,Y_MAX,60);
	line(5,190,55,190);
	line(55,190,55,290);
	line(5,290,55,290);
	line(5,140,105,140);
	line(105,140,105,340);
	line(5,340,105,340);
	circle(320,240,60);
	setfillstyle(SOLID_FILL,BLUE);
	fillpoly(4,d);
	setfillstyle(SOLID_FILL,YELLOW);
	bar(480,200,580,250);
	bar(400,360,500,410);
	showHString(167,30,"球队管理系统",3,RED);
	showHString(530,225,"登录",2,BLACK);
	showHString(450,380,"关于",2,BLACK);

	
	
	

}

/***
                 
				                         ***/
void WelcomeFaceManage(){
	int flag=0,pre_flag=0;//消除重复标亮
	int state;
	extern Manage manage;//存档数据结构
	ShowWelcomeFace();
	initMouse();
	showMouse();
	updateGMouse();
	while(1){
		
	
		if(gMouse.x>=480&&gMouse.x<=580&&gMouse.y>=200&&gMouse.y<=250)
		{
			/*pre_flag=flag;
				flag=1;*/
			if(gMouse.button==1){
				hideMouse();
				cleardevice();
				log_in_face_manage();
			}
			
		}
	}
	//后续功能未完成
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
