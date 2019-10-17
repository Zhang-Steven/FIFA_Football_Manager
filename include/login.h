#ifndef _LOGIN_H_
#define _LOGIN_H_

#include<stdio.h>
#include<io.h>
#include"mouse.h"

 /*函数功能：判断密码是否合乎要求
  返回值：0表示长度不合乎要求，1表示合乎要求*/
char judge_password(char password[]);
 /*函数功能：判断两次输入的密码是否相同
   返回值：0表示不相同，1表示相同*/
char compare_password(char key1[],char key2[]);
/*
  函数功能：判断登录账号是否已经注册
  返回值：0表示已注册，1表示尚未注册*/
char judge_same_name(char account[]);
/*函数功能：判断是否输入完整 （用于账户注册）
  返回值：1表示全部输入，2表示账号未输入，3表示密码未输入，4表示未确认密码，5表示身份证号未输入*/
char complete_register(char account,char key1,char key2);
/*函数功能：判断账号密码是否匹配
	0表示不正确，1表示正确*/
char right_password(char account[],char key[]);
/*函数功能：判断是否输入完整 （用于账户登录）
  返回值：1表示全部输入，2表示账号未输入，3表示密码未输入*/
char complete_login(char account,char key);
/*函数功能：判断是否输入完整 （用于管理员登录）
  返回值：1表示全部输入，2表示密码未输入*/
char complete_admin(char key);
/*函数功能：将注册信息写入文件*/
void write_user_inf(char account[],char key[]);
/*函数功能：将新密码写入文件*/ 
void text_username(int x1,int x2,int y1,char *word);
/*函数功能：输入密码等需要隐藏的信息*/
void text_password(int x1,int x2,int y1,char *word);
/*函数功能：将本次登录的账号写入文件*/
void write_user(char account[]);


#endif