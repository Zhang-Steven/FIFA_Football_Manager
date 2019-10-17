#include"mouse.h"

struct Mouse gMouse;
unsigned far* pVarm;
static unsigned int oldX,oldY;
static void *mouseBuffer;//������걳��

void interrupt (*oldint9)()=NULL;
void interrupt (*oldint1c)()=NULL;

int busy1c=0;
static unsigned char near stack_1c[0x1000]={0};
static unsigned sp_1c,ss_1c;

static unsigned mouseShape[]={
   /*  Cursor Mask  */
     0x001E,      /*  0001111000000000   */
     0x0012,      /*  0001001000000000   */
     0x0012,      /*  0001001000000000   */
     0x0012,      /*  0001001000000000   */
     0x0012,      /*  0001001000000000   */
     0xFF13,      /*  0001001111111111   */
     0x4912,      /*  0001001001001001   */
     0x4912,      /*  0001001001001001   */
     0x49F2,      /*  1111001001001001   */
     0x0190,      /*  1001000000000001   */
     0x0190,      /*  1001000000000001   */
     0x0190,      /*  1001000000000001   */
     0x0180,      /*  1000000000000001   */
     0x0180,      /*  1000000000000001   */
     0x0180,      /*  1000000000000001   */
     0xFFFF       /*  1111111111111111   */
};
/***********************************************************
Function: initMouse
Description: ��ʼ�����
Input:��
return����
**********************************************************/
void initMouse(){
	union REGS regs;
	regs.x.ax=0;
	int86(51,&regs,&regs);
	if(regs.x.ax==0){
		closegraph();
		printf("the mouse initial is failed");
		getch();
	}
	regs.x.ax=7;
	regs.x.cx=0;
	regs.x.dx=640-16;
	int86(51,&regs,&regs);
	regs.x.ax=8;
	regs.x.cx=0;
	regs.x.dx=480-1;
	int86(51,&regs,&regs);
	mouseBuffer=malloc(134);
	oldint1c=getvect(0x1c);
	gMouse.x=320;
	gMouse.y=240;
	gMouse.isShow=0;
}
/***********************************************************
Function: showMouse
Description: �Զ���ʾ��꣨�����жϣ�
Input: ��
return����
**********************************************************/
void showMouse(){
	if(gMouse.isShow)return;
	gMouse.isShow=0;
	installInt(newint1c,0x1c);
}
/***********************************************************
Function: hideMouse
Description: �Զ�������꣨�ָ��жϣ�
Input: ��
return����
**********************************************************/
void hideMouse(){
	if(gMouse.isShow==0)return;
	installInt(oldint1c,0x1c);
	putimage(gMouse.x,gMouse.y,mouseBuffer,COPY_PUT);
	gMouse.isShow=0;
}
/***********************************************************
Function: readMouse
Description: ��ȡ�����Ϣ
Input: ���ṹ��ָ��mouse
return����
**********************************************************/
void readMouse(struct Mouse* mouse){
	union REGS regs;
	regs.x.ax=3;
	int86(51,&regs,&regs);
	mouse->x=regs.x.cx;
	mouse->y=regs.x.dx;
	mouse->button=regs.x.bx;
}
/***********************************************************
Function: updateGMouse
Description: ����ȫ�������Ϣ
Input: ��
return����
**********************************************************/
void updateGMouse(){
	_AX = 3;
  geninterrupt(0x33);
  gMouse.x=_CX&0xfff8;
  gMouse.y=_DX;
  gMouse.button=_BX;
}
/***********************************************************
Function: printMouse
Description: ��ʾ���
Input: ��
return: ��
**********************************************************/
void printMouse(){
	unsigned i;
	pVarm=(unsigned far*)(0xa0000000+80*gMouse.y+(gMouse.x>>3));
	if(gMouse.isShow){
		putimage(oldX,oldY,mouseBuffer,COPY_PUT);
	}
	getimage(gMouse.x,gMouse.y,gMouse.x+15,gMouse.y+15,mouseBuffer);
	oldX=gMouse.x;
	oldY=gMouse.y;
	gMouse.isShow=1;
	outportb(0x3c4,0x02);
	outportb(0x3c5,WHITE);
	for(i=0;i<16;i++){
		*(pVarm+40*i)=mouseShape[i];
	}
	outport(0x3c4,0xff02);
}

void interrupt newint1c(){             //�µ��ж�
	if(busy1c==0){
		busy1c=1;
		disable();
		sp_1c=_SP;
		ss_1c=_SS;
		_SP=(unsigned)0x1000-2;//&stack_1c[0x1000-2];
		_SS=(unsigned)stack_1c;
		enable();
		
		updateGMouse();
		printMouse();
		
		disable();
		_SP=sp_1c;
		_SS=ss_1c;
		enable();
		busy1c=0;
	}
}


/***********************************************************
Function: installInt
Description: ��װ�ж�
Input: faddr�������жϺ���,intNum���ж�����ֵ
return����
**********************************************************/
void installInt(void interrupt (*faddr)(),char intNum){
	disable();
	setvect(intNum,faddr);
	enable();
}