#include "data.h"
#include <strlib.h>

//璇诲彇鐞冨憳鐨勫悕瀛楋紝鍌ㄥ瓨鍒癷ncode涓?
void ReadStarName(int id,char* incode){
	FILE* file;
	long offset;
	file=fopen(PLAYERHZ,"rb");
	if(file==NULL){
		closegraph();
		printf("the player hz error\n");
		getch();
		exit(-1);
	}
	offset=(id-1)*STAR_NAME;
	fseek(file,offset,SEEK_SET);
	fread(incode,1,4,file);
	fclose(file);
	
}

//根据档案里的id，进行未拥有球员链表的生成
void LoadMarketData(int *id,Star* star){         //注：star一定是未拥有球员
	FILE* file;
	FILE* hz;
	Star* temp=star;
	int number=0,i,current;//用于计数有多少个球员，current是debug用参量
	int lim,length;//计算数据库里有多少球员，同时length表示文件有多大字节
	long int offset;//偏移量
	star=(Star*)malloc(sizeof(Star));//鍒涘缓澶磋妭鐐?
       //	Star* temp=star;
	file=fopen(DATABASE,"rb");
	hz=fopen(PLAYERHZ,"rb");
	if(hz==NULL){
		settextjustify(LEFT_TEXT,TOP_TEXT);    
		settextstyle(GOTHIC_FONT,HORIZ_DIR,1);	
		outtextxy(10,10,"Can't open file PLAYERHZ !Press any key to quit...");
		getch();
		exit(1);
	}
	if(file==NULL){
		settextjustify(LEFT_TEXT,TOP_TEXT);    
		settextstyle(GOTHIC_FONT,HORIZ_DIR,1);	
		outtextxy(10,10,"Can't open file DATABASE !Press any key to quit...");
		delay(3000);
		exit(1);
	}
	if(id==NULL){
		settextjustify(LEFT_TEXT,TOP_TEXT);    
		settextstyle(GOTHIC_FONT,HORIZ_DIR,1);	
		outtextxy(10,10,"ERROR:input id missing...");
		delay(3000);
		exit(1);
	}
	fseek(file,0L,SEEK_SET);
	fseek(hz,0L,SEEK_SET);
	//现在确定数据库共有多少球员，以免数据溢出
	fseek(hz,0L,SEEK_END);
	length=ftell(hz);
	lim=length/10;
	fseek(hz,0L,SEEK_SET);
	
	for(i=0;i<=lim;i++){
		if(id==NULL){
			break;
		}
		if(i==*id){
			offset=10;
			fseek(hz,offset,SEEK_CUR);
			offset=3+8+4+4+2;
			fseek(file,offset,SEEK_CUR);
			id++;
			continue;
		}
		else{
			Star* data=(Star*)malloc(sizeof(Star));
			fread(data->name,1,10,hz);
			fread(data->id,1,3,file);
			fread(data->price,1,8,file);
			fread(data->speed,1,4,file);
			fread(data->strength,1,4,file);
			fread(data->position,1,2,file);
			
			data->next=NULL;
			temp->next=data;
			temp=temp->next;
			
			id++;
		}
	}
	fclose(file);
	fclose(hz);
}

//用于生成档案里的已有球员id数组
int LoadUserStarID(int id[MAX_STAR]){
	int i,length,count,star_num=0;//star_num是输出的变量，记录已有球员个数
	long int offset;//文件的偏移量
	char temp[3];//用于存放读取的id信息
	char username[USER_LENGTH];//用户名
	char search_username[USER_LENGTH];//查找到的用户名
	FILE* fp;
	FILE* data;
	if((fp=fopen(USERFILE,"rb"))==NULL){
		settextjustify(LEFT_TEXT,TOP_TEXT);    
		settextstyle(GOTHIC_FONT,HORIZ_DIR,1);	
		outtextxy(10,10,"Can't open file USERFILE !Press any key to quit...");
		delay(3000);
		exit(1);
	}
	if((fp=fopen(USERDATA,"rb"))==NULL){
		settextjustify(LEFT_TEXT,TOP_TEXT);    
		settextstyle(GOTHIC_FONT,HORIZ_DIR,1);	
		outtextxy(10,10,"Can't open file USERDATA !Press any key to quit...");
		delay(3000);
		exit(1);
	}
	
	fseek(data,0L,SEEK_SET);
	fseek(fp,0L,SEEK_SET);
	fseek(data,0L,SEEK_END);
	length=ftell(data);//计算总共有多少账户
	count=length/(sizeof(User)+3*MAX_STAR);
	fread(username,1,USER_LENGTH,fp);
	
	for(i=0;i<count;i++){
		offset=i*(sizeof(User)+3*MAX_STAR);//寻找目前以登陆的账户，方便查找id信息
		fseek(data,offset,SEEK_SET);
		fread(search_username,1,USER_LENGTH,data);
		if(strcmp(username,search_usernme)==0){
			break;
		}
	}
	
	if(i>=count){
		settextjustify(LEFT_TEXT,TOP_TEXT);    
		settextstyle(GOTHIC_FONT,HORIZ_DIR,1);	
		outtextxy(10,10,"User file no found!!!");
		delay(3000);
		exit(1);
	}
	
	offset=i*(sizeof(User)+3*MAX_STAR)+sizeof(User);
	fseek(data,offset,SEEK_SET);
	for(i=0;i<MAX_STAR;i++){
		fread(temp,1,3,data);
		if(temp=="\0"){
			break;//如果读到空数据，退出循环
		}
		else {
			id[i]=atoi(temp);
			star_num++;
		}
	}
	
	if(i>=MAX_STAR){
		settextjustify(LEFT_TEXT,TOP_TEXT);    
		settextstyle(GOTHIC_FONT,HORIZ_DIR,1);	
		outtextxy(10,10,"Unknown error!!FUck!");
		delay(3000);
		exit(1);
	}
	
	fclose(fp);
	fclose(data);
	return star_num;

}

//将已拥有球员链接成链表
void LoadStarData(int *id,Star* star){
	FILE* file;
	FILE* hz;
	Star* temp=star;
	int number=0,i,current;//用于计数有多少个球员，current是debug用参量
	int lim,length;//计算数据库里有多少球员，同时length表示文件有多大字节
	long int offset;//偏移量
	star=(Star*)malloc(sizeof(Star));//鍒涘缓澶磋妭鐐?
       //	Star* temp=star;
	file=fopen(DATABASE,"rb");
	hz=fopen(PLAYERHZ,"rb");
	if(hz==NULL){
		settextjustify(LEFT_TEXT,TOP_TEXT);    
		settextstyle(GOTHIC_FONT,HORIZ_DIR,1);	
		outtextxy(10,10,"Can't open file PLAYERHZ !Press any key to quit...");
		getch();
		exit(1);
	}
	if(file==NULL){
		settextjustify(LEFT_TEXT,TOP_TEXT);    
		settextstyle(GOTHIC_FONT,HORIZ_DIR,1);	
		outtextxy(10,10,"Can't open file DATABASE !Press any key to quit...");
		delay(3000);
		exit(1);
	}
	if(id==NULL){
		settextjustify(LEFT_TEXT,TOP_TEXT);    
		settextstyle(GOTHIC_FONT,HORIZ_DIR,1);	
		outtextxy(10,10,"ERROR:input id missing...");
		delay(3000);
		exit(1);
	}
	fseek(file,0L,SEEK_SET);
	fseek(hz,0L,SEEK_SET);
	//现在确定数据库共有多少球员，以免数据溢出
	fseek(hz,0L,SEEK_END);
	length=ftell(hz);
	lim=length/10;
	fseek(hz,0L,SEEK_SET);
	
	for(i=0;i<=lim;i++){
		if(id==NULL){
			break;
		}
		if(i!=*id){
			offset=10;
			fseek(hz,offset,SEEK_CUR);
			offset=3+8+4+4+2;
			fseek(file,offset,SEEK_CUR);
			id++;
			continue;
		}
		else{
			Star* data=(Star*)malloc(sizeof(Star));
			fread(data->name,1,10,hz);
			fread(data->id,1,3,file);
			fread(data->price,1,8,file);
			fread(data->speed,1,4,file);
			fread(data->strength,1,4,file);
			fread(data->position,1,2,file);
			
			data->next=NULL;
			temp->next=data;
			temp=temp->next;
			
			id++;
		}
	}
	fclose(file);
	fclose(hz);
}

void InitManager(Manager manager){
	int i;
	

}