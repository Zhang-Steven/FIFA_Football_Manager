#ifndef __HANZI
#define __HANZI

#include<stdio.h>
#include<fcntl.h>
#include<io.h>
#include<stdlib.h>
#include<graphics.h>

#define THICK 1
#define THIN 0
#define CLOSE_ZIKU 2
#define HZ_SIZE 16
#define X_MAX 640
#define Y_MAX 480
#define SIZE 1

FILE* openZiKu(int thick);
void getMat(char incode[],char bytes[],int thick);
void showHanZi16(int x0,int y0,char incode[],int color,int thick);
void showHanZiBySize(int x0,int y0,char incode[],int color,int thick,int size);
void closeZiKu(FILE* ziku);
void showHString(int x,int y,char incode[],int size,int color);
#endif