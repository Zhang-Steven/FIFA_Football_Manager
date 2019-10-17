#ifndef __DEFINE_
#define __DEFINE_


#define THICK 1
#define THIN 0
#define CLOSE_ZIKU 2
#define HZ_SIZE 16
#define X_MAX 640
#define Y_MAX 480
#define SIZE 1

//data文件宏定义
#define RECORD_NUM 6
#define COUNTRY_NUM 5
#define STAR_NUM 10
#define DEFAULT_OWN_STAR_NUM 0x05
#define DEFAULT_MONEY 400
#define PLAYER_NUM 5
#define USER_LENGTH 13
#define USER_PASSWORD 17
#define USER_NUM 12
#define STAR_NAME 320
#define MAX_STAR 60
#define USERDATA "C:\\TEST\\UserInfo.dat"
#define USERFILE "C:\\TEST\\usernow.dat"
#define DATABASE "C:\\TEST\\DATABASE.dat"
#define PLAYERHZ "C:\\TEST\\playerHZ.dat"


#define LB_MASK 0x0001
#define RB_MASK 0x0002
#define ESC 0x11b

#define MOUSE_SIZE_X 16//鼠标大小
#define MOUSE_SIZE_Y 16




//全局变量-----源中断地址
extern void interrupt (*oldint9)();
extern void interrupt (*oldint1c)();
extern int busy1c;


extern struct Mouse gMouse;
extern unsigned far* pVarm;//指向varm的指针


extern unsigned Cursor[4][32];



#endif