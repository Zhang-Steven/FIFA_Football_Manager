#ifndef __MOUSE
#define __MOUSE

#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#include"define.h"
//#include"tools.h"
//#include"int.h"


//全局变量-----源中断地址
extern void interrupt (*oldint9)();
extern void interrupt (*oldint1c)();


struct Mouse{
	unsigned int x,y;
	unsigned int button;
	int isShow;
};

extern struct Mouse gMouse;
extern unsigned far* pVarm;//指向varm的指针


extern unsigned Cursor[4][32];

void setGraphicMouse(int x,int y,unsigned pattern);
//下面是楼上函数的简化版
void setPatternMouse(int pattern);

void initMouse(void);
void showMouse(void);
void hideMouse(void);
void readMouse(struct Mouse* mouse);

extern int busy1c;
void interrupt newint1c();
//中断安装程序
void installInt(void interrupt (*faddr)(),char intNum);



#endif