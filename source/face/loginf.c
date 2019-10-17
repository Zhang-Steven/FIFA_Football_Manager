/********************************
Function:showregisterface
Description:娉ㄥ唽鐣岄潰
input:鏃?
return:鏃?
********************************/
#include "loginf.h"
#include "welcomf.h"
#include "login.h"
void register_face(void)
{
	
	cleardevice();
	setwritemode(COPY_PUT);
	setfillstyle(SOLID_FILL,YELLOW);
	bar(0,0,X_MAX-1,Y_MAX-1);
	setfillstyle(SOLID_FILL,GREEN);
	bar(5,5,X_MAX-5,Y_MAX-5);
	setcolor(WHITE);
	setlinestyle(0,0,3);
	circle(X_MAX,Y_MAX,60);
	line(5,190,55,190);
	line(55,190,55,290);
	line(5,290,55,290);
	line(5,140,105,140);
	line(105,140,105,340);
	line(5,340,105,340);
	line(635,190,585,190);
	line(585,190,585,290);
	line(635,290,585,290);
	line(635,140,535,140);
	line(535,140,535,340);
	line(635,340,535,340);
	line(320,5,320,475);
	setfillstyle(SOLID_FILL,YELLOW);
	/*璐﹀彿瀛椾綋浣嶇疆160锛?00瀵嗙爜瀛椾綋浣嶇疆160锛?80
	纭瀵嗙爜瀛椾綋浣嶇疆120锛?60*/
	bar(240,75,560,125);//账号
	bar(240,155,560,205);//密码
	bar(240,225,560,275);//确认密码
	bar(460,325,560,375);//注册
	showHString(160,100,"账号",2,BLACK);
	showHString(160,180,"密码",2,BLACK);
	showHString(120,260,"确认密码",2,BLACK);
	showHString(510,350,"注册",2,BLACK);
	
	
}

/***********************************
Function: log in
Description:显示登入界面及文字
input:
output:
***********************************/
void log_in_face(void)
{
   
	cleardevice();
	setwritemode(COPY_PUT);
	setfillstyle(SOLID_FILL,BLACK);
	bar(0,0,X_MAX-1,Y_MAX-1);
	/*登陆字体中心坐标320，105
	账号字体位置160，200，密码字体位置160，280*/
	setfillstyle(SOLID_FILL,YELLOW);
	bar(240,175,560,225);//账号
	bar(240,255,560,305);//密码
	bar(110,335,210,385);//注册
	bar(400,335,500,385);//登录
	showHString(320,105,"登陆",2,WHITE);
	showHString(200,200,"账号",1,WHITE);
	showHString(200,280,"密码",1,WHITE);
	showHString(160,360,"注册",1,BLACK);
	showHString(450,360,"登录",1,BLACK);
	
	
	
}

/***
                 
				         ***/
void log_in_face_manage(){
	int flag=0,pre_flag=0;//消除重复标亮
	int state;
	char username[USER_LENGTH]={0};
	char password[USER_PASSWORD]={0};
	char key_0=0;//按下登录键后的状态，1表示全部输入，2表示账号未输入，3表示密码未输入
	char key_1=0;//按下登录键后的状态，0表示已注册，1表示尚未注册
	char key_2=0;//按下登录键后的状态，账户密码匹配，0表示不正确，1表示正确
	log_in_face();
	showMouse();
	//updateGMouse();
	while(1){
		
		if(gMouse.x>=240&&gMouse.x<=560&&gMouse.y>=175&&gMouse.y<=225){
			if(gMouse.button==1){
				text_username(240,240+16*USER_LENGTH,175+22,username);
			}
		}
		else if(gMouse.x>=240&&gMouse.x<=560&&gMouse.y>=255&&gMouse.y<=305){
			if(gMouse.button==1){
				text_password(240,240+16*USER_PASSWORD,255+22,password);
			}
		}
			
	
		else if(gMouse.x>=400&&gMouse.x<=500&&gMouse.y>=335&&gMouse.y<=380)
		{
			/*pre_flag=flag;
			flag=1;*/
		   	if(gMouse.button==1){
				
				key_0=complete_login(username[0],password[0]);
				{
					if(key_0==2)
						{
							
							showHString(X_MAX/2,Y_MAX/2,"账户未输入",1,WHITE);
							delay(2000);//未完成
							log_in_face();
						}
						else if(key_0==3)
						{
							
						    showHString(X_MAX/2,Y_MAX/2,"密码未输入",1,WHITE);
							delay(2000);
							log_in_face();
						}
					if(key_0==1){
						key_1=judge_same_name(username);
						if(key_1==1){
							
							showHString(X_MAX/2,Y_MAX/2,"账户未注册",2,RED);
							delay(2000);
							log_in_face();             
						}
					}
					if(username=="admin"){
						if(password=="admin"){
							show_main_face_manage();
							break;
						}
					}
					if(key_1==0){
						key_2=right_password(username,password);
						if(key_2==0){
							
							showHString(X_MAX/2,Y_MAX/2,"密码不正确",2,RED);
							delay(2000);
							log_in_face();
						}
					}
					if(key_0==1&&key_2==1){
						
						write_user(username);
						break;
					}
					
				}
			}
		}
		else if(gMouse.x>=110&&gMouse.x<=210&&gMouse.y>=335&&gMouse.y<=385){
			/*pre_flag=flag;
			flag=1;*/
			if(gMouse.button==1){
				hideMouse();
				cleardevice();
				register_face_manage();
			}
		}
	}
	hideMouse();
	cleardevice();
	show_main_face_manage();
}

/***

					***/

void register_face_manage() {
	int flag=0,pre_flag=0;//消除重复标亮
	int state;
	char key_0=1;//成功1，账号未输入2，密码未输入3
	char key_1=1;//重名账号0，无重名1
	char key_2=1;//0密码格式不符，1符合
	char key_3=1;//0表示两次密码不相同，1表示相同
	char key_4=0;//暂时加着
	char username[USER_LENGTH]={0};
	char password[USER_PASSWORD]={0};
	char re_password[USER_PASSWORD]={0};

	register_face();
	showMouse();
	//updateGMouse();
	while(1){
		if(gMouse.x>=240&&gMouse.x<=560&&gMouse.y>=75&&gMouse.y<=125){
			if(gMouse.button==1){
				text_username(240,240+16*USER_LENGTH,75+22,username);
			}
		}

		if(gMouse.x>=240&&gMouse.x<=560&&gMouse.y>=155&&gMouse.y<=205){
			if(gMouse.button==1){
				text_password(240,240+16*USER_PASSWORD,155+22,password);
			}
		}

		if(gMouse.x>=240&&gMouse.x<=560&&gMouse.y>=225&&gMouse.y<=275){
			if(gMouse.button==1){
				text_password(240,240+16*USER_PASSWORD,225+22,re_password);
			}
		}

		if(gMouse.x>=460&&gMouse.x<=560&&gMouse.y>=325&&gMouse.y<=375){
			if(gMouse.button==1){
				/*判断是否输入完全*/
				key_0=complete_register(username[0],password[0],re_password[0]);//成功1，账号未输入2，密码未输入3，密码未确认4，身份证未输入5
				if(key_0==2){
					showHString(X_MAX/2,Y_MAX/2,"账号未输入",1,RED);
					delay(2000);
					register_face();
				}
				else if(key_0==3){
					showHString(X_MAX/2,Y_MAX/2,"密码未输入",1,RED);
					delay(2000);
					register_face();
				}
				else if(key_0==4){
					showHString(X_MAX/2,Y_MAX/2,"密码未确认",1,RED);
					delay(2000);
					register_face();
				}
				else if(key_0==0){
					showHString(X_MAX/2,Y_MAX/2,"系统错误，请找刘浩",1,RED);
					delay(2000);
					register_face();
				}
				key_1=judge_same_name(username);
				key_2=judge_password(password);
				key_3=compare_password(password,re_password);
				if(key_0==1){
					
					if(key_1==0){
						showHString(X_MAX/2,Y_MAX/2,"账号已注册",1,RED);
						delay(2000);
						register_face();
					}
				}
				if(key_1==1){
					
					if(key_2==0){
						showHString(X_MAX/2,Y_MAX/2,"密码长度不符合要求",1,RED);
						delay(2000);
						register_face();
					}
				}
				if(key_2==1){
					
					if(key_3==0){
						showHString(X_MAX/2,Y_MAX/2,"密码不相同",1,RED);
						delay(2000);
						register_face();
					}
				}
				if((key_0==1)&&(key_1==1)&&(key_2==1)&&(key_3==1)){
					write_user_inf(username,password);
					break;
				}
			}
		}
	}
	hideMouse();
	gMouse.button==0;
	cleardevice();
	log_in_face_manage();
}