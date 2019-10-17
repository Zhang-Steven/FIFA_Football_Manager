      #include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define player 60

//球员的数据结构
struct Star{
	short id;
	int price;
	unsigned char speed[4];
	unsigned char strength[4];
	char position;
	struct Star* next;
}; 
                         //未完成

void main()
{
	short id[player];//编号
	short*q;
	char*p;
	int*temp;
	char s[][4]={"73","60","65","63","54","56","58","60","58","62","65","56","76","78","74","75","80","69","74","72","75","71","68","82","81","74","73","67","68","71","79",\
	"68","74","72","73","71","75","78","74","75","84","85","68","69","72","70","74","73","76","75","73","81","85","86","84","88","84","89","85","90"};//liliang
	char sp[][4]={"75","58","62","65","65","62","56","58","60","64","68","62","72","72","72","72","78","70","65","70","70","68","64","74","72","72","70","64","68","70","78",\
	"70","72","64","71","70","68","74","72","72","80","87","70","75","70","68","72","71","78","76","74","80","84","79","80","86","88","86","84","88"};//sudu
	int price[player];//每个球员的价格 
	char po[]={'f','f','f','c','c','c','b','b','b','g','c','c','c','f','f','f','b','b','b','c','c','c','c','f','f','f','b','b','b','c','c','c','f','f','f','g','g','g','f','f','f','c','c','c',\
	'b','b','b','g','g','g','c','c','c','f','f','f','b','b','b','c','c','c'};//球员位置.门将：goalkeeper用g表示  前锋：Forward用f表示    中锋：Center-forward用c表示   后卫：Fullback用b表示
    FILE*fp;
	int i;
	for(i=0;i<player;i++)
	{
		id[i]=i+1;
		price[i]=100*(atoi(s[i])+atoi(sp[i]));
	}	
	q=id;
	p=po;
	temp=price;
	//
	
	//
	if((fp=fopen("C:\\TEST\\database.dat","wb+"))==NULL);
	{
	    printf("Can not open the file.\n");
		getch();
	}
	fseek(fp,0L,SEEK_SET);
	for(i=0;i<60;i++)
	{
		if(fwrite(q,sizeof(short),1,fp)!=1)
			printf("Error in writing.\n");
		else
			q++;
	}
	for(i=0;i<60;i++)
	{   
		if(fwrite(s[i],sizeof(char),4,fp)!=1)
		    printf("Error in writing.\n");
		if(fwrite(sp[i],sizeof(char),4,fp)!=1)
			printf("Error in writing.\n");
		
	}
	for(i=0;i<60;i++){
		if(fwrite(temp,sizeof(int),1,fp)!=1)
			printf("Error in writing.\n");
		else
			temp++;
		if(fwrite(p,sizeof(char),1,fp)!=1)
			printf("Error in writing.\n");
		else
			p++;
	}
	
	fclose(fp);
}