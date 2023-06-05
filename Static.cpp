#include<graphics.h>
#include<iostream>
using namespace std;
int score=700;						 //Score stored in global variable
int frame(){						//Default Screen
	cleardevice();
	settextstyle(1,HORIZ_DIR,5);
	outtextxy(120,15, "TETRIS DEMO");
	rectangle(200,80,680,680);
	settextstyle(3,HORIZ_DIR,4);
	outtextxy(40,300,"SCORE");
	char scorestr[5];
	sprintf(scorestr,"%d",score);  //Converting Score integer to string
	outtextxy(70,400,scorestr);
}
int T(int x, int y){				// T-Shaped Block
	setfillstyle(1,4);
	rectangle(x,y,x+60,y+60);
	floodfill(x+1,y+1,15);
	rectangle(x+60,y,x+120,y+60);
	floodfill(x+61,y+1,15);
	rectangle(x+120,y,x+180,y+60);
	floodfill(x+121,y+1,15);
	rectangle(x+60,y+60,x+120,y+120);
	floodfill(x+61,y+61,15);
}
int T_f(int x,int y){				// Flipped T-shaped Block
	setfillstyle(1,1);
	rectangle(x,y,x+60,y+60);
	floodfill(x+1,y+1,15);
	rectangle(x+60,y,x+120,y+60);
	floodfill(x+61,y+1,15);
	rectangle(x+120,y,x+180,y+60);
	floodfill(x+121,y+1,15);
	rectangle(x+60,y-60,x+120,y);
	floodfill(x+61,y-59,15);
}
int L(int x,int y){					//L-Shaped Block
	setfillstyle(1,2);
	rectangle(x,y,x+60,y+60);
	floodfill(x+1,y+1,15);
	rectangle(x,y+60,x+60,y+120);
	floodfill(x+1,y+61,15);
	rectangle(x,y+120,x+60,y+180);
	floodfill(x+1,y+121,15);
	rectangle(x+60,y+120,x+120,y+180);
	floodfill(x+61,y+121,15);
}
int L_v(int x, int y){		// Vertically Flipped L-Shaped Block
	setfillstyle(1,3);
	rectangle(x,y,x+60,y+60);
	floodfill(x+1,y+1,15);
	rectangle(x,y+60,x+60,y+120);
	floodfill(x+1,y+61,15);
	rectangle(x,y+120,x+60,y+180);
	floodfill(x+1,y+121,15);
	rectangle(x+60,y,x+120,y+60);
	floodfill(x+61,y+1,15);
}
int L_h(int x, int y){		// Horizontally Flipped L-Shaped Block
	setfillstyle(1,5);
	rectangle(x,y,x+60,y+60);
	floodfill(x+1,y+1,15);
	rectangle(x,y+60,x+60,y+120);
	floodfill(x+1,y+61,15);
	rectangle(x,y+120,x+60,y+180);
	floodfill(x+1,y+121,15);
	rectangle(x,y+120,x-60,y+180);
	floodfill(x-1,y+121,15);
}
int L_hv(int x, int y){			// Horizontally and Vertically Flipped L-Shaped Block
	setfillstyle(1,6);
	rectangle(x,y,x+60,y+60);
	floodfill(x+1,y+1,15);
	rectangle(x,y+60,x+60,y+120);
	floodfill(x+1,y+61,15);
	rectangle(x,y+120,x+60,y+180);
	floodfill(x+1,y+121,15);
	rectangle(x-60,y,x,y+60);
	floodfill(x-1,y+1,15);
}
int S(int x, int y){			// Square Block
	setfillstyle(1,14);
	rectangle(x,y,x+60,y+60);
	floodfill(x+1,y+1,15);
	rectangle(x+60,y,x+120,y+60);
	floodfill(x+61,y+1,15);
	rectangle(x+60,y+60,x+120,y+120);
	floodfill(x+61,y+61,15);
	rectangle(x,y+60,x+60,y+120);
	floodfill(x+1,y+61,15);
}
int Z(int x,int y){					// Z-Shaped Block
	setfillstyle(1,9);
	rectangle(x,y,x+60,y+60);
	floodfill(x+1,y+1,15);
	rectangle(x+60,y,x+120,y+60);
	floodfill(x+61,y+1,15);
	rectangle(x-60,y+60,x,y+120);
	floodfill(x-1,y+61,15);
	rectangle(x,y+60,x+60,y+120);
	floodfill(x+1,y+61,15);
}
int Z_f(int x, int y){				// Flipped Z-shaped block
	setfillstyle(1,10);
	rectangle(x,y,x+60,y+60);
	floodfill(x+1,y+1,15);
	rectangle(x+60,y,x+120,y+60);
	floodfill(x+61,y+1,15);
	rectangle(x+60,y+60,x+120,y+120);
	floodfill(x+61,y+61,15);
	rectangle(x+120,y+60,x+180,y+120);
	floodfill(x+121,y+61,15);
}
int N(int x, int y){					// N-Shaped Block
	setfillstyle(1,11);
	rectangle(x,y+120,x+60,y+180);
	floodfill(x+1,y+121,15);
	rectangle(x+60,y,x+120,y+60);
	floodfill(x+61,y+1,15);
	rectangle(x+60,y+60,x+120,y+120);
	floodfill(x+61,y+61,15);
	rectangle(x,y+60,x+60,y+120);
	floodfill(x+1,y+61,15);
}
int N_f(int x,int y){				// Flipped N-Shaped Block
	setfillstyle(1,12);
	rectangle(x,y,x+60,y+60);
	floodfill(x+1,y+1,15);
	rectangle(x+60,y+120,x+120,y+180);
	floodfill(x+61,y+121,15);
	rectangle(x+60,y+60,x+120,y+120);
	floodfill(x+61,y+61,15);
	rectangle(x,y+60,x+60,y+120);
	floodfill(x+1,y+61,15);
}
int V(int x, int y){				//Vertical Line
	setfillstyle(1,13);
	rectangle(x,y,x+60,y+60);
	floodfill(x+1,y+1,15);
	rectangle(x,y+60,x+60,y+120);
	floodfill(x+1,y+61,15);
	rectangle(x,y+120,x+60,y+180);
	floodfill(x+1,y+121,15);
}
int H(int x, int y){				// Horizontal Line
	setfillstyle(1,13);
	rectangle(x,y,x+60,y+60);
	floodfill(x+1,y+1,15);
	rectangle(x+60,y,x+120,y+60);
	floodfill(x+61,y+1,15);
	rectangle(x+120,y,x+180,y+60);
	floodfill(x+121,y+1,15);
}
int main(){
	initwindow(720,720);
	frame();
	T(200,80);
	T_f(320,140);
	L(500,80);
	L_v(200,200);
	L_h(320,200);
	L_hv(440,200);
	S(560,80);
	Z(560,260);
	Z_f(200,380);
	N(380,380);
	N_f(500,380);
	V(380,260);
	H(200,500);
	T(200,560);
	T_f(320,620);
	S(440,500);
	Z(560,560);
	L_hv(620,380);
	getch();
}
