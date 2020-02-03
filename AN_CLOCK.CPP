#include<graphics.h>
#include <stdlib.h>
#include<string.h>
#include <stdio.h>
#include <conio.h>
#include<dos.h>
#include<math.h>
void disp_clock(int x,int y,int ra)
{
	int p1,h;
	float t1,th1,k1,l1;
	int x1,y1;
	char q[10];
	setlinestyle(0,1,1);
	setfillstyle(1,BLUE);
	fillellipse(x,y,ra,ra);
	setfillstyle(1,RED);
	fillellipse(x,y,ra-25,ra-25);
	setcolor(YELLOW);
	p1=ra-10;
	for(h=0;h<12;h++)
	{
		t1=270+(h*30);
		th1=t1*(3.1416/180);
		k1=cos(th1);
		l1=sin(th1);
		x1=x+(p1*k1);
		y1=y+(p1*l1);
	      //	line(x,y,x1,y1);
		if(h==0)
		{
			strcpy(q,"12");
		}
		else
		{
		sprintf(q,"%d ",h);
		}
		outtextxy(x1,y1,q);

	}
}
void main()
{
	struct  time t;
	int gdriver = DETECT, gmode, errorcode;
	int x,y,x1,x2,x3,y1,y2,y3,s,m,h;
	int rad = 150;
	float th1,th2,th3,t1,t2,t3;
	int a,p1,f1,f2,f3;
	char q[20];
	float k1,k2,k3,l1,l2,l3;
	gettime(&t);
	initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(1);
	}
	x=getmaxx()/2;
	y=getmaxy()/2;
	f1=rad-20;
	f2=rad-40;
	f3=rad-80;
	while(!kbhit())
	{
		disp_clock(x,y,rad);
		gettime(&t);
		s=t.ti_sec;
		h=t.ti_hour;
		m=t.ti_min;
		h=h%12;
		sprintf(q,"%d:%d:%d ",h,m,s);
		outtextxy(10,10,q);
		t1=270+(s*6);
		th1=t1*(3.1416/180);
		k1=cos(th1);
		l1=sin(th1);
		x1=x+(f1*k1);
		y1=y+(f1*l1);
		setcolor(BLACK);
		setlinestyle(0,1,3);
		line(x,y,x1,y1);
		t2=270+(m*6);
		th2=t2*(3.1416/180);
		k2=cos(th2);
		l2=sin(th2);
		x2=x+(f2*k2);
		y2=y+(f2*l2);
		setcolor(GREEN);
		line(x,y,x2,y2);
		t3=270+(h*30)+(m/12)*6;
		th3=t3*(3.1416/180);
		k3=cos(th3);
		l3=sin(th3);
		x3=x+(f3*k3);
		y3=y+(f3*l3);
		setcolor(WHITE);
		setlinestyle(0,1,50);
		line(x,y,x3,y3);
		delay(1000);
		cleardevice();
	}
	getch();
}


