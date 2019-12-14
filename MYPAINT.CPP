

// Programmer :: Dadaso Ankush Sawant
// Project    :: Paint in C - Graphics

#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream.h>

#define ENTER 13

// for rectangle

int rectx1[50];
int recty1[50];
int rectx2[50];
int recty2[50];
int rectst[50];

// for circle

int circlex[50];
int circley[50];
int circlerad[50];
int circlest[50];

// for line

int linex1[50];
int liney1[50];
int linex2[50];
int liney2[50];
int linest[50];

//for pixel

int pixx[50];
int pixy[50];
int pixst[50];

//for color

int clsx[50];
int clsy[50];
int clsc[50];
int clsst[50];

void input();
void design()
{
	rectangle(10,10,100,30); //first
	outtextxy(35,16,"a:Save");
	rectangle(110,10,200,30);
	outtextxy(120,16,"b:Save as");
	rectangle(210,10,300,30);
	outtextxy(235,16,"c:Open");
	rectangle(310,10,400,30);
	outtextxy(325,16,"d:Shapes");
	rectangle(410,10,500,30);
	outtextxy(425,16,"e:Color");
	rectangle(510,10,600,30);  //last
	outtextxy(525,16,"f:Erase");
	rectangle(0,2,639,469);

	setfillstyle(SOLID_FILL,0);
      //floodfill(8,8,WHITE);
	putpixel(8,8,RED);
	line(0,42,640,42);
}


void seeStatus(int st,int i)
{
	design();
	if(st==1)
	{
		line(linex1[i],liney1[i],linex2[i],liney2[i]);
	}
	else if(st==2)
	{
		circle(circlex[i],circley[i],circlerad[i]);
	}
	else if(st==3)
	{
		rectangle(rectx1[i],recty1[i],rectx2[i],recty2[i]);
	}
	else if(st==4)
	{
		setfillstyle(SOLID_FILL,clsc[i]);
		floodfill(clsx[i],clsy[i],WHITE);
	}
	else if(st==5)
	{
		putpixel(clsx[i],clsy[i],YELLOW);
	}
}

void printByStatus()
{
	int m;
	for(m=0; m<50; m++) // for line
	{
		if(linest[m]==1)
		seeStatus(1,m);
	}


	for(m=0; m<50; m++) // for circle
	{
		if(circlest[m]==1)
		seeStatus(2,m);
	}

	for(m=0; m<50; m++)  // for rectangle
	{
		if(rectst[m]==1)
		seeStatus(3,m);
	}

	for(m=0; m<50; m++)    // for color
	{
		if(clsst[m]==1)
		seeStatus(4,m);
	}

	for(m=0; m<50; m++)   // for pixel /* for pencile
	{
		if(pixst[m]==1)
		seeStatus(50,m);
	}
}


void drawLine(int i)
{
	int m;
	linest[i]=1;
	linex1[i]=300;
	liney1[i]=350;
	linex2[i]=500;
	liney2[i]=350;
	char ch;
	while(1)
	{
		printByStatus();
		ch=getch();
		cleardevice();
		switch(ch)
		{
			case '1':
				  line(linex1[i]--,liney1[i]++,linex2[i],liney2[i]);
				  break;

			case '2': line(linex1[i],liney1[i]++,linex2[i],liney2[i]++);
				  break;

			case '3': line(linex1[i],liney1[i],linex2[i]++,liney2[i]++);
				  break;

			case '4': line(linex1[i]--,liney1[i],linex2[i]--,liney2[i]);
				  break;

			case '5': line(linex1[i],liney1[i],linex2[i],liney2[i]);
				  break;

			case '6': line(linex1[i]++,liney1[i],linex2[i]++,liney2[i]);
				  break;

			case '7': line(linex1[i]--,liney1[i]--,linex2[i],liney2[i]);
				  break;

			case '8': line(linex1[i],liney1[i]--,linex2[i],liney2[i]--);
				  break;

			case '9': line(linex1[i],liney1[i],linex2[i]++,liney2[i]--);
				  break;

			case 27:  exit(1);

			case 26:  line(linex1[i]--,liney1[i],linex2[i]++,liney2[i]);
				  break;

			case 1 :  line(linex1[i]++,liney1[i],linex2[i]--,liney2[i]);
				  break;

			case ENTER : seeStatus(1,i);
				     return;

			default :  input();
		}
		line(linex1[i],liney1[i],linex2[i],liney2[i]);
	}
}


void drawCircle(int i)
{
	int m;
	char ch;
	circlest[i]=1;
	circlex[i]=300;
	circley[i]=300;
	circlerad[i]=20;
	while(1)
	{
		printByStatus();
		ch=getch();
		cleardevice();
//		circle(x,y,rad);
		switch(ch)
		{
			case '1':circle(circlex[i]++,circley[i]++,circlerad[i]);

				  break;

			case '2': circle(circlex[i],circley[i]++,circlerad[i]);
				  break;

			case '3': circle(circlex[i]++,circley[i]--,circlerad[i]);
				  break;

			case '4': circle(circlex[i]--,circley[i],circlerad[i]);
				  break;

			case '6': circle(circlex[i]++,circley[i],circlerad[i]);
				  break;

			case '5': circle(circlex[i],circley[i],circlerad[i]);
				  break;

			case '7': circle(circlex[i]--,circley[i]--,circlerad[i]);
				  break;

			case '8': circle(circlex[i],circley[i]--,circlerad[i]);
				  break;
			case '9': circle(circlex[i]++,circley[i]--,circlerad[i]);
				  break;

			case 27:  exit(1);

			case 26:  circle(circlex[i],circley[i],circlerad[i]++);
				  break;

			case 1 :  circle(circlex[i],circley[i],circlerad[i]--);
				  break;


			case ENTER : seeStatus(2,i);
				     return;

			default :  input();
		}

		circle(circlex[i],circley[i],circlerad[i]);
	}
}

void drawRectangle(int i)
{
	int m;
	rectst[i]=1;
	rectx1[i]=200;
	recty1[i]=200;
	rectx2[i]=300;
	recty2[i]=250;
	char ch;
	while(1)
	{
		printByStatus();
		ch=getch();
		cleardevice();
		switch(ch)
		{
			case '1':
				  rectangle(rectx1[i]--,recty1[i]++,rectx2[i]--,recty2[i]++);
				  break;

			case '2': rectangle(rectx1[i],recty1[i]++,rectx2[i],recty2[i]++);
				  break;

			case '3': rectangle(rectx1[i]++,recty1[i]++,rectx2[i]++,recty2[i]++);
				  break;

			case '4': rectangle(rectx1[i]--,recty1[i],rectx2[i]--,recty2[i]);
				  break;

			case '5': rectangle(rectx1[i],recty1[i],rectx2[i],recty2[i]);
				  break;


			case '6': rectangle(rectx1[i]++,recty1[i],rectx2[i]++,recty2[i]);
				  break;

			case '7': rectangle(rectx1[i]--,recty1[i]--,rectx2[i]--,recty2[i]--);
				  break;

			case '8': rectangle(rectx1[i],recty1[i]--,rectx2[i],recty2[i]--);
				  break;

			case '9': rectangle(rectx1[i]++,recty1[i]--,rectx2[i]++,recty2[i]--);
				  break;

			case 27:  exit(1);

			case 26:  rectangle(rectx1[i]--,recty1[i],rectx2[i]++,recty2[i]);
				  break;

			case 1 :  rectangle(rectx1[i]++,recty1[i],rectx2[i]--,recty2[i]);
				  break;

			case 24 : rectangle(rectx1[i],recty1[i]--,rectx2[i],recty2[i]++);
				  break;

			case 19 :  rectangle(rectx1[i],recty1[i]++,rectx2[i],recty2[i]--);
				  break;

			case ENTER : seeStatus(3,i);
					return ;

			default :  input();
		}
		rectangle(rectx1[i],recty1[i],rectx2[i],recty2[i]);
	}
}



void Pencile(int i)
{
	char ch;
	int m;
	pixx[i]=300;
	pixy[i]=300;
	pixst[i]=1;
	while(1)
	{
		printByStatus();
		ch=getch();
//		cleardevice();
		switch(ch)
		{
			case '1': putpixel(pixx[i]--,pixy[i]++,YELLOW);
				  break;

			case '2': putpixel(pixx[i],pixy[i]++,YELLOW);
				  break;

			case '3': putpixel(pixx[i]++,pixy[i]++,YELLOW);
				  break;

			case '4': putpixel(pixx[i]--,pixy[i],YELLOW);
				  break;

			case '5': putpixel(pixx[i],pixy[i],YELLOW);
				  break;

			case '6': putpixel(pixx[i]++,pixy[i],YELLOW);
				  break;

			case '7': putpixel(pixx[i]--,pixy[i]--,YELLOW);
				  break;

			case '8': putpixel(pixx[i],pixy[i]--,YELLOW);
				  break;

			case '9': putpixel(pixx[i]++,pixy[i]--,YELLOW);
				  break;


			case 27:  exit(1);

			case 26:  putpixel(pixx[i],pixy[i],YELLOW);
				  break;

			case 1 :  putpixel(pixx[i],pixy[i],YELLOW);
				  break;

			case ENTER :  seeStatus(3,i);
					return ;

			default :  input();

		}

		putpixel(pixx[i],pixy[i],YELLOW);
	}
}



void shapes()
{
	printByStatus();
	rectangle(310,60,639,160);
	line(420,60,420,160);
	line(530,60,530,160);
	line(310,110,639,110);
	//writing objects inside the blocks
	//line
	line(315,80,400,80);
	//circle
	circle(450,85,20);
	//rectangle
	rectangle(550,70,620,100);
	//arc
	arc(350,150,0,180,20);
	//ellipse
   //	ellipse(455,140,0,360,30,20);

	outtextxy(455,140,"Pencile");

	design();
	static int lcnt=0,rcnt=0,ccnt=0,pcnt=0;
	char ch=getch();
	switch(ch)
	{

		case '1':  drawLine(lcnt++);
			   break;

		case '2':  drawCircle(ccnt++);
			   break;

		case '3':  drawRectangle(rcnt++);
			   break;

		case '4':  //drawArc();
			   break;

		case '5':  Pencile(pcnt++);
			   break;

		case 27: exit(1);

		default :  input();
	}
	design();
	shapes();
}

void colors(int i)
{
	int m,j,z,clr,t;
	for(m=1,j=10,clr=1,z=16,t=0; t<=15; m++,j=j+40,clr++,z=z+40,t++)
	{
		setfillstyle(SOLID_FILL,clr);
		rectangle(j,50,30+j,70);
		floodfill(z,53,WHITE);
	}
	char ch;

	clsx[i]=60;
	clsy[i]=300;
	int cv;
	outtextxy(12,120,"Enter color value n then enter:");
	gotoxy(3,10);
	scanf("%d",&cv);
	clsc[i]=cv;
	while(1)
	{
		ch=getch();
		cleardevice();
		printByStatus();
		switch(ch)
		{
			case '1': putpixel(clsx[i]--,clsy[i]++,YELLOW);
				  break;

			case '2': putpixel(clsx[i],clsy[i]++,YELLOW);
				  break;

			case '3': putpixel(clsx[i]++,clsy[i]++,YELLOW);
				  break;

			case '4': putpixel(clsx[i]--,clsy[i],YELLOW);
				  break;

			case '5': putpixel(clsx[i],clsy[i],YELLOW);
				  break;

			case '6': putpixel(clsx[i]++,clsy[i],YELLOW);
				  break;

			case '7': putpixel(clsx[i]--,clsy[i]--,YELLOW);
				  break;

			case '8': putpixel(clsx[i],clsy[i]--,YELLOW);
				  break;

			case '9': putpixel(clsx[i]++,clsy[i]--,YELLOW);
				  break;


			case 27:  exit(1);

			case 26:  putpixel(clsx[i],clsy[i],YELLOW);
				  break;

			case 1 :  putpixel(clsx[i],clsy[i],YELLOW);
				  break;

			case ENTER :
				   setfillstyle(SOLID_FILL,clsc[i]);
				   floodfill(clsx[i],clsy[i],WHITE);
				   clsst[i]=1;
				   colors(++i);

			default :  input();

		}
		putpixel(clsx[i],clsy[i],YELLOW);
	}


}

void save()
{
	char *fname;
	printf("\n\n\n\n\n\n\n\n\n\nEnter file Name : ");
	gets(fname);
     //	sprintf("");

	ofstream fout;
	char lv=3;
	fout.open(fname,ios::app | ios::binary);
	fout<<"//Programmer :"<<lv<<lv<<"Dadaso Sawant"<<lv<<lv<<lv<<endl;
	fout<<"//Use MyPaint created by SawantDA "<<lv<<lv<<lv<<endl<<endl;
	fout<<"#include<graphics.h>"<<endl;
	fout<<"#include<conio.h>"<<endl;
	fout<<"#include<dos.h>"<<endl;
	fout<<"#include<stdlib.h>"<<endl<<endl;
	fout<<"void main()"<<endl;
	fout<<"{"<<endl;
	fout<<"  int gd=DETECT,gm;"<<endl;
	char ch=34;
	fout<<"  initgraph(&gd,&gm,"<<ch<<"C:\\\\TC\\\\BGI "<<ch<<");"<<endl;

	int i;
	char arr[100];
	for(i=0; i<5; i++)
	{
		if(linest[i]==1)
		{
			sprintf(arr,"  line(%d,%d,%d,%d);",linex1[i],liney1[i],linex2[i],liney2[i]);
			fout<<arr<<endl;
		}
	}


	for(i=0; i<50; i++)
	{
		if(circlest[i]==1)
		{
			sprintf(arr,"  circle(%d,%d,%d);",circlex[i],circley[i],circlerad[i]);
			fout<<arr<<endl;
		}
	}

	for(i=0; i<50; i++)
	{
		if(rectst[i]==1)
		{
			sprintf(arr,"  rectangle(%d,%d,%d,%d);",rectx1[i],recty1[i],rectx2[i],recty2[i]);
			fout<<arr<<endl;
		}
	}

	for(i=0; i<50; i++)
	{
		if(clsst[i]==1)
		{
			sprintf(arr,"  setfillstyle(SOLID_FILL,%d);",clsc[i]);
			fout<<arr<<endl;
			sprintf(arr,"  floodfill(%d,%d,WHITE);",clsx[i],clsy[i]);
			fout<<arr<<endl;
		}
	}

	fout<<"  getch();"<<endl;
	fout<<"  closegraph();"<<endl;
	fout<<"}";
	fout.close();
	outtextxy(200,280,"Saved . . . . .");
}


void input() //tak
{
	int m;
	static int ccnt=0;
	while(1)
	{
		printByStatus();
		switch(getch())
		{
			case 'a' : save();
				 break;

			case 'b' : //saveas();
				 break;

			case 'c' : //open();
				 break;

			case 'd' :shapes();
				 break;

			case 'e' : colors(ccnt++);
				 break;

			case 'f' : //eraser();
				 break;

			case 27:exit(1);

			case 19 : save();
				break;
		}
	}
}


void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	design();
	input();
	getch();
	closegraph();
}

