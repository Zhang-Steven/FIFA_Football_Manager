#ifndef __INFO
#define __INFO

#include<stdio.h>
#include<io.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<time.h>
#include<sys/stat.h>
#include<graphics.h>
#include"define.h"




//球员的数据结构
typedef struct Star{
	char name[10];
	char id[3];
	char price[8];
	char speed[4];
	char strength[4];
	char position[2];
	struct Star* next;
}Star;                          //未完成

//球队经理统计信息的数据结构
typedef struct Manager {
	char username[USER_LENGTH];
	long int money;
	char id[MAX_STAR][3];//已有球员的id
	char speed_offset[MAX_STAR][3];//训练的速度偏移量
	char strength_offset[MAX_STAR][3];//训练的力量偏移量
	char status[MAX_STAR][2];//是否在训练的标记
	int win;
	int total_match;
	        //未完成
}Manager;

typedef struct UserInfo{
	char username[USER_LENGTH];
	char password[USER_PASSWORD];
}User;

//读取球员中文名字
void ReadStarName(int id,char* incode);

//读取球员信息，储存到链表star中**重要！！！！
void LoadStarData(int *id,Star* star);

//读取当前账号的已拥有球员ID信息，并输出ID个数，并将ID存入二维数组
int LoadUserStarID(int id[MAX_STAR]);

//读取球员市场的信息，并生成市场链表，输入参数是当前用户已有球员的id二维数组
void LoadMarketData(int *id,Star* star);

//初始化存档信息，方便后期数据调用
void InitManager(Manager manager);



#endif






