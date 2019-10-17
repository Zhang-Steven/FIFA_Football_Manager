#include "mouse.h"
#include "hanzi.h"
#include "data.h"
#include "welcomf.h"
#include <graphics.h>

int main () {
	int driver=VGA;
	int mode=VGAHI;
	int id=1;
	//char incode[STAR_NAME];
	initgraph(&driver,&mode,"C:\\BORLANDC\\BGI");
	clrscr();
    //ReadStarName(id,incode);
    //showHString(X_MAX/2,Y_MAX/2,incode,1,WHITE);
	//showHString(100,100,"уехЩ",2,WHITE);
	WelcomeFaceManage();
	
	getch();
	
}