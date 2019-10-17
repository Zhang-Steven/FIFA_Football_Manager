#include "login.h"
#include "loginf.h"
#include "data.h"

/***
	用户输入用户名，将数据传给word
                                            ***/
void text_username(int x1,int x2,int y1,char *word)
{
	int length=(x2-x1)/16;
	char i=0;
	char t;
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	setcolor(WHITE);
	settextstyle(SMALL_FONT,HORIZ_DIR,8);
	settextjustify(LEFT_TEXT,BOTTOM_TEXT);
	line(x1+8,y1+4,x1+8+10,y1+4);
	while(1)
	{
		t=bioskey(0);//读取键值
		if(i<length)
		{
			if(t!='\n'
				&&t!='\r'
				&&t!=' '
				&&t!=033)//Esc
			{
				if(t!='\b')
				{
					*(word+i)=t;
					*(word+i+1)='\0';
					bar(x1+8+i*15,y1+4,x1+18+i*15,y1+4);//遮盖光标
					outtextxy(x1+8+i*15,y1,word+i);//输出t字符
					i++;
					line(x1+8+i*15,y1+4,x1+18+i*15,y1+4);
				}
				else if(t=='\b'&&i>0)//退格键
				{
					bar(x1+8+i*15,y1+4,x1+18+i*15,y1+4);//遮盖光标
					bar(x1-8+i*15,y1-16,x1+7+i*15,y1+6);//遮盖文字
					i--;//减少一个字数
					line(x1+8+i*15,y1+4,x1+18+i*15,y1+4);//绘制光标
					*(word+i)='\0';
					*(word+i+1)='\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL,LIGHTGRAY);
				bar(x1+8+i*15,y1+4,x1+18+i*15,y1+4);//遮盖光标
				break;
			}
		}
		else if(i>=length)
		{
			if(t!='\n'
				&&t!='\r'
				&&t!=' '
				&&t!=033)//Esc
			{
				if(t=='\b'&&i>0)//退格键
				{
					bar(x1+8+i*15,y1+4,x1+18+i*15,y1+4);//遮盖光标
					bar(x1-8+i*15,y1-16,x1+7+i*15,y1+6);//遮盖文字
					i--;//减少一个字数
					line(x1+8+i*15,y1+4,x1+18+i*15,y1+4);//绘制光标
					*(word+i)='\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL,LIGHTGRAY);
				bar(x1+8+i*15,y1+4,x1+18+i*15,y1+4);//遮盖光标
				break;
			}
		}
	}
}	

/***
		用户输入密码（隐蔽形式），将数据传给word
                                    ***/
void text_password(int x1,int x2,int y1,char *word)
{
	int length=(x2-x1)/16;
	char i=0;
	char t;
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	setcolor(WHITE);
	settextstyle(SMALL_FONT,HORIZ_DIR,8); //HORIZ_DIR表示从左到右显示
	settextjustify(LEFT_TEXT,BOTTOM_TEXT);
	line(x1+8,y1+4,x1+8+10,y1+4);
	while(1)
	{
		t=bioskey(0);//读取键值
		if(i<length)
		{
			if(t!='\n'
				&&t!='\r'
				&&t!=' '
				&&t!=033)//033表示Esc
			{
				if(t!='\b')
				{
					*(word+i)=t;
					*(word+i+1)='\0';
					bar(x1+8+i*15,y1+4,x1+18+i*15,y1+4);//遮盖光标
					outtextxy(x1+8+i*15,y1,"*");//输出*字符
					i++;
					line(x1+8+i*15,y1+4,x1+18+i*15,y1+4);
				}
				else if(t=='\b'&&i>0)//退格键
				{
					bar(x1+8+i*15,y1+4,x1+18+i*15,y1+4);//遮盖光标
					bar(x1-8+i*15,y1-16,x1+7+i*15,y1+6);//遮盖文字
					i--;//减少一个字数
					line(x1+8+i*15,y1+4,x1+18+i*15,y1+4);//绘制光标
					*(word+i)='\0';
					*(word+i+1)='\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL,YELLOW);
				bar(x1+8+i*15,y1+4,x1+18+i*15,y1+4);//遮盖光标
				break;
			}
		}
		else if(i>=length)
		{
			if(t!='\n'
				&&t!='\r'
				&&t!=' '
				&&t!=033)//Esc
			{
				if(t=='\b'&&i>0)//退格键
				{
					bar(x1+8+i*15,y1+4,x1+18+i*15,y1+4);//遮盖光标
					bar(x1-8+i*15,y1-16,x1+7+i*15,y1+6);//遮盖文字
					i--;//减少一个字数
					line(x1+8+i*15,y1+4,x1+18+i*15,y1+4);//绘制光标
					*(word+i)='\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL,LIGHTGRAY);
				bar(x1+8+i*15,y1+4,x1+18+i*15,y1+4);//遮盖光标
				break;
			}
		}
	}
}	

/*函数功能：判断密码是否合乎要求
  返回值：0表示长度不合乎要求，1表示合乎要求*/
char judge_password(char password[])
{
	int i;
	int flag=1;
	for(i=0;i<6;i++)
	{
		if(password[i]=='\0')//若密码长度小于6，则长度错误
		{
			flag=0;
			break;
		}
	}
	return flag;
}

 /*函数功能：判断两次输入的密码是否相同
   返回值：0表示不相同，1表示相同*/
char compare_password(char key1[],char key2[])
{
	int i;
	int flag=0;
	for(i=0;i<13;i++)
	{
		if(key1[i]!=key2[i])
		{
			flag=0;
			break;
		}
		if(key1[i]=='\0')
		{
			flag=1;
			break;
		}
	}
	return flag;
}
  
/*函数功能：判断注册的账号是否与已有账号重名
  返回值：0表示重名，1表示不重名
  函数功能：判断登录账号是否已经注册
  返回值：0表示已注册，1表示尚未注册*/
char judge_same_name(char account[])
{
	FILE *fp;
	User *u=NULL;
	int i,j;
	int flag=1;
	int length;
	if((fp=fopen("C:\\TEST\\UserInfo.dat","rb+"))==NULL)
	{
		printf("\nC:\\TEST\\UserInfo.dat error file");
		delay(3000);
		exit(1);//打开失败，退出程序
	}
	fseek(fp,0,SEEK_END);
	length=ftell(fp)/sizeof(User);
	for(i=0;i<length;i++)
	{
		if((u=(User*)malloc(sizeof(User)))==NULL)
		{
			printf("memory error JudgeSameName");
			delay(3000);
			exit(1);//分配空间不足，退出程序
		}
		fseek(fp,i*(sizeof(User)+3*MAX_STAR),SEEK_SET);
		fread(u,sizeof(User),1,fp);
		for(j=0;j<USER_LENGTH;j++)
		{
			if(u->username[j]!=account[j])
			{
				break;
			}
			if(account[j]=='\0')
			{
				j=USER_LENGTH;
				break;
			}
		}
		if(j==USER_LENGTH)
		{
			flag=0;
			break;
		}
		free(u);
		u=NULL;
	}
	if(u!=NULL)
	{
		free(u);
		u=NULL;
	}
	if(fclose(fp) != 0)//关闭文件
	{
		printf("\nError in closing file UserInfo.");
		delay(3000);
		exit(1);
	}
	return flag;
}

/*函数功能：将本次登录的账号写入文件*/
void write_user(char account[])
{
	FILE *fp;
	if ((fp = fopen("C:\\TEST\\usernow.dat", "rb+")) == NULL)
	{
		printf("C:\\TEST\\usernow.dat file error\n");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_SET);
	fwrite(account, sizeof(char), 13, fp);
	if(fclose(fp) != 0)//关闭文件
	{
		printf("\nError in closing file usernow.");
		delay(3000);
		exit(1);
	}
}


/*函数功能：判断账号密码是否匹配
  返回值：0表示不正确，1表示正确*/
char right_password(char account[],char key[])
{
	FILE *fp;
	User *u=NULL;
	int i,j,k=0;
	int flag=0;
	int length;
	if((fp=fopen("C:\\TEST\\UserInfo.dat","rb+"))==NULL)
	{
		printf("\nC:\\TEST\\UserInfo.dat error file");
		delay(3000);
		exit(1);//打开失败，退出程序
	}
	fseek(fp,0,SEEK_END);
	length=ftell(fp)/(sizeof(User)+3*MAX_STAR);
	for(i=0;i<length;i++)
	{
		if((u=(User*)malloc(sizeof(User)))==NULL)
		{
			printf("memory error RightPassword");
			delay(3000);
			exit(1);//分配空间不足，退出程序
		}
		fseek(fp,i*(sizeof(User)+3*MAX_STAR),SEEK_SET);
		fread(u,sizeof(User),1,fp);
		for(j=0;j<13;j++)
		{
			if(u->username[j]!=account[j])
			{
				break;
			}
			if(account[j]=='\0')
			{
				k=1;//存在此账户
				break;
			}
		}
		if(k==1)
		{
			for(j=0;j<13;j++)
			{
				if(u->password[j]!=key[j])
				{
					flag=0;
					break;
				}
				if(key[j]=='\0')
				{
					flag=1;
					break;
				}
			}
			break;
		}
		free(u);
		u=NULL;
	}
	if(u!=NULL)
	{
		free(u);
	}
	if(fclose(fp) != 0)//关闭文件
	{
		printf("\nError in closing file UserInfo.");
		delay(3000);
		exit(1);
	}
	return flag;
}

/*函数功能：判断是否输入完整 （用于账户注册）
  返回值：1表示全部输入，2表示账号未输入，3表示密码未输入，4表示未确认密码，5表示身份证号未输入*/
char complete_register(char account,char key1,char key2)
{
	if(account=='\0')
	{
		return 2;
	}
	if(key1=='\0')
	{
		return 3;
	}
	if(key2=='\0')
	{
		return 4;
	}

	return 1;
}

/*函数功能：判断是否输入完整 （用于账户登录）
  返回值：1表示全部输入，2表示账号未输入，3表示密码未输入*/
char complete_login(char account,char key)
{
	if(account=='\0')
	{
		return 2;
	}
	if(key=='\0')
	{
		return 3;
	}
	return 1;
}

/*函数功能：判断是否输入完整 （用于管理员登录）
  返回值：1表示全部输入，2表示密码未输入*/
char complete_admin(char key)
{
	if(key=='\0')
	{
		return 2;
	}
	return 1;
}

/*函数功能：将注册信息写入文件*/
void write_user_inf(char account[],char key[])
{
	FILE *fp;
	User *u;
	int i;
	char count[MAX_STAR][3];
	for(i=0;i<MAX_STAR;i++){
		strcpy(count[i],"\0");
	}
	if((fp=fopen("C:\\TEST\\UserInfo.dat","rb+"))==NULL)
	{
		printf("\nC:\\TEST\\UserInfo.dat error file");
		delay(3000);
		exit(1);//打开失败，退出程序
	}
	if((u=(User*)malloc(sizeof(User)))==NULL)
	{
		printf("memory error WrUserInf");
		delay(3000);
		exit(1);//分配空间不足，退出程序
	}
	for(i=0;i<USER_LENGTH;i++)
	{
		u->username[i]=account[i];
	}
	for(i=0;i<USER_PASSWORD;i++)
	{
		u->password[i]=key[i];
	}
	fseek(fp,0,SEEK_END);
	fwrite(u,sizeof(User),1,fp);
	free(u);
	for(i=0;i<MAX_STAR;i++){
		if(i<=10){
			itoa(i+1,count[i],10);
		}
		fwrite(count[i],sizeof(char),3,fp); //初始化账号中已有球员,全是中国队的
		//count++;
	}
	
	if(fclose(fp) != 0)//关闭文件
	{
		printf("\nError in closing file UserInfo.");
		delay(3000);
		exit(1);
	}
}

/*函数功能：将新密码写入文件*/
/*void user_change_password(char account[],char key[])
{
	FILE *fp;
	User *u=NULL;
	int i,j,k=0;
	int length;
	int passwordlength;
	if((fp=fopen("C:\\TEST\\UserInfo.dat","rb+"))==NULL)
	{
		printf("\nC:\\TEST\\UserInfo.dat error file");
		delay(3000);
		exit(1);//打开失败，退出程序
	}
	fseek(fp,0,SEEK_END);
	length=ftell(fp)/sizeof(User);
	for(i=0;i<length;i++)
	{
		if((u=(User*)malloc(sizeof(User)))==NULL)
		{
			printf("memory error RightPassword");
			delay(3000);
			exit(1);//分配空间不足，退出程序
		}
		fseek(fp,i*sizeof(User),SEEK_SET);
		fread(u,sizeof(User),1,fp);
		for(j=0;j<12;j++)
		{
			if(u->username[j]!=account[j])
			{
				break;
			}
			if(account[j]=='\0')
			{
				k=1;//存在此账户
				break;
			}
		}
		if(k==1)
		{
			for(j=0;j<13;j++)
			{
				if(key[j]=='\0')
				{
					passwordlength=j+1;
					break;
				}
			}
			for(j=0;j<passwordlength;j++)
			{
				u->password[j]=key[j];
			}
			for(j=passwordlength;j<13;j++)
			{
				u->password[j]='\0';
			}
		}
		fseek(fp,i*sizeof(User),SEEK_SET);
		fwrite(u,sizeof(User),1,fp);
		free(u);
		u=NULL;
	}
	if(u!=NULL)
	{
		free(u);
	}
	if(fclose(fp) != 0)//关闭文件
	{
		printf("\nError in closing file UserInfo.");
		delay(3000);
		exit(1);
	}
}  */



