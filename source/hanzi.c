#include "hanzi.h"

/***********************************************************
Function: openZiKu
Description: 打开字库
Input: thick代表字体大小
return：返回字库句柄
**********************************************************/
FILE* openZiKu(int thick){
	static FILE* ziku=NULL;
	if(thick==CLOSE_ZIKU){
		ziku=NULL;
		return NULL;
	}
	if(ziku==NULL){
		if(thick==THICK){
			ziku=fopen("C:\\TEST\\HANZI\\ziku_cu.txt","rb");
		}else {
			ziku=fopen("C:\\TEST\\HANZI\\ziku.txt","rb");	
		}
		if(ziku==NULL){
			hideMouse();
			closegraph();
			printf("the ziku file can not be opened");
			getch();
			exit(1);
		}
	}
	
	//lseek(ziku,0,SEEK_SET);
	return ziku;
}
/***********************************************************
Function: closeZiKu
Description: 关闭字库
Input: 字库句柄
return：无
**********************************************************/
void closeZiKu(FILE* ziku){
	if(ziku==NULL)return;
	fclose(ziku);
	openZiKu(CLOSE_ZIKU);
}
/***********************************************************
Function: getMat
Description: 得到汉字的点阵
Input: 汉字的编码incode，用来盛放点阵的数组bytes，粗细thick
return：无
**********************************************************/
void getMat(char incode[],char bytes[],int thick){
	unsigned char qh,wh;
	unsigned long offset;
	FILE* ziku=openZiKu(thick);
	qh=incode[0]-0xa0;
	wh=incode[1]-0xa0;
	offset=(94*(qh-1)+wh-1)*32L;
	fseek(ziku,offset,SEEK_SET);
	fread(bytes,1,32,ziku);
	//close(ziku);
}
/***********************************************************
Function: showHanZi16
Description:显示单个汉字
Input: 位置x0和y0，汉字编码incode，颜色color，粗细thick
return：无
**********************************************************/
void showHanZi16(int x0,int y0,char incode[],int color,int thick){
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
	int i,j,x,y,pos;
	char mat[32];
	getMat(incode,mat,thick);
	y=y0;
	for(i=0;i<16;i++){
		x=x0;
		pos=2*i;
		for(j=0;j<16;j++){
			if((mask[j%8]&mat[pos+j/8])!=NULL){
				putpixel(x,y,color);
			}
			x++;
		}
		y++;
	}
}
/***********************************************************
Function: showHanZiBySize
Description: 显示不同大小的汉字
Input: 位置x0和y0，汉字编码incode，颜色color，粗细thick，大小size
return：无
**********************************************************/
void showHanZiBySize(int x0,int y0,char incode[],int color,int thick,int size){
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
	int i,j,x,y,pos,num=16*size;
	char mat[32];
	getMat(incode,mat,thick);
	y=y0;
	for(i=0;i<num;i++){
		x=x0;
		pos=2*(i/size);
		for(j=0;j<num;j++){
			if((mask[(j/size)%8]&mat[pos+j/(8*size)])!=NULL){
				putpixel(x,y,color);
				//getch();
			}
			x++;
		}
		y++;
	}
}

/***********************************************************
Function: showHString
Description: 显示汉字字符串
Input: 字符串中心位置xy，字符串incode，大小size，颜色color
return：无
**********************************************************/
void showHString(int x,int y,char incode[],int size,int color){
	int i;
	x-=strlen(incode)*4*size;
	y-=8*size;
	for(i=0;incode[i]!='\0';i+=2){
		showHanZiBySize(x+8*i*size,y,&incode[i],color,THIN,size);
	}
}