#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define player 60

//球员的数据结构
struct Star{
	short id;
	int price;
	unsigned char speed;
	unsigned char strength;
	char position;
	struct Star* next;
};                          
                         //未完成

void main()
{
	char id[player][3];//编号
	char price[player][8];//每个球员的价格
	char s[][4]={"73","60","65","63","54","56","58","60","58","62","65","56","76","78","74","75","80","69","74","72","75","71","68","82","81","74","73","67","68","71","79",\
	"68","74","72","73","71","75","78","74","75","84","85","68","69","72","70","74","73","76","75","73","81","85","86","84","88","84","89","85","90"};//liliang
	char sp[][4]={"75","58","62","65","65","62","56","58","60","64","68","62","72","72","72","72","78","70","65","70","70","68","64","74","72","72","70","64","68","70","78",\
	"70","72","64","71","70","68","74","72","72","80","87","70","75","70","68","72","71","78","76","74","80","84","79","80","86","88","86","84","88"};//sudu

	char po[][2]={"f","f","f","c","c","c","b","b","b","g","c","c","c","f","f","f","b","b","b","c","c","c","c","f","f","f","b","b","b","c","c","c","f","f","f","g","g","g","f","f","f","c","c","c",\
	"b","b","b","g","g","g","c","c","c","f","f","f","b","b","b","c","c","c"};//球员位置.门将：goalkeeper用g表示  前锋：Forward用f表示    中锋：Center-forward用c表示   后卫：Fullback用b表示
    FILE* fp;
	int i;
	int speedint,strengthint;

	//生成数组
	for(i=0;i<player;i++){
		speedint=atoi(s[i]);
		strengthint=atoi(sp[i]);
		itoa(i+1,id[i],10);
		itoa(100*(speedint+strengthint),price[i],10);
	}


	//结束，开始录入
	fp=fopen("C:\\TEST\\DATABASE.DAT","wb");

	fseek(fp,0L,SEEK_SET);

	for(i=0;i<60;i++)
	{
		if(fwrite(id[i],sizeof(char),3,fp)!=1)
		{
			printf("Error in writing.\n");
		       //	break;
		}
		if(fwrite(price[i],sizeof(char),8,fp)!=1)
		{
			printf("Error in writing.\n");
		       //	break;
		}
		if(fwrite(s[i],sizeof(char),4,fp)!=1)
		{
		    printf("Error in writing.\n");
		   // break;
		}
		if(fwrite(sp[i],sizeof(char),4,fp)!=1)
		{
			printf("Error in writing.\n");
		       //	break;
		}
		if(fwrite(po[i],sizeof(char),2,fp)!=1)
		{
			printf("Error in writing.\n");
		       //	break;
		}



	}

	fclose(fp);
}