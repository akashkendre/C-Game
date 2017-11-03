#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>

int currRow=3,currCol=3;
int puzzArr[4][4];
int arr[16];
//int hour,minute,second;
int totalMoves=0,level=0;
const int desiredMoves=200;

void init();
void pri();
void rec();
void movePosition(int);
void swap(int,int);

void design();
void displaybox();
void print_goal();
void fill();
void displayMoves();
void gameover();
void level2check();
void printmoves();
int isDone();
int getInvcount();
int IsSolvable();

struct pos
{
int h,v;
}p[4][4];

/*Random Numbers are generated through this function*/
void setRandomValues()
{
	int ran,i,k=0,a[15],j;
	for(i=0;i<15;i++)
	{
		a[i]=0;
	}

	while(k!=15)
	{
		int flag=1;

		ran=rand()%15+1;
		for(i=0;i<15;i++)
		{
			if(a[i]==ran)
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			a[k++]=ran;
		}
	}
	i=0;
	j=0;
	k=0;


		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				puzzArr[i][j]=a[k++];
				if(i==3&&j==3)
				{
					puzzArr[i][j]=0;

				}
			}

		}

}


void main()
{       int gd = DETECT,gm;
	char inputKey,ch ;
	//int i;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	//line(0,0,0,479);
	//line(639,0,639,479);
	do
	 {design();
	  ch=getch();
	 }while(ch!='\r');
	level:
	cleardevice();
	do
	{randomize();
	setRandomValues();
	settextstyle(8,HORIZ_DIR,3);
	outtextxy(250,205,"LOADING...");
	setcolor(WHITE);
	rectangle(150,190,450,260);
	rectangle(155,195,445,255);
	}while(!IsSolvable());
	setbkcolor(1);
	setfillstyle(SOLID_FILL,9);
	bar(0,0,450,479);
	setfillstyle(SOLID_FILL,3);
	bar(30,50,300,280);
	fill();
	init();
	rec();pri();print_goal();
	gotoxy(3,5);
	//i=getInvcount();
	//printf("%d",i);
	settextstyle(2,HORIZ_DIR,5);
	outtextxy(5,30,"Press Esc to Exit");
	settextstyle(1,HORIZ_DIR,1);
	setcolor(RED);
	outtextxy(100,2,"15 NUMBER PUZZLE GAME");
	setfillstyle(SOLID_FILL,1);
	bar(10,320,440,400);
	displayMoves();
	gotoxy(14,23);
	printf("%d",totalMoves);
	do{
	inputKey=getch();

	switch(inputKey)
	{
	case 77:
	  movePosition(4);
	  setfillstyle(SOLID_FILL,9);
	  setfillstyle(SOLID_FILL,3);
	  bar(30,50,300,280);
	  fill();
	  init();
	  rec();
	  pri();
	  gotoxy(14,23);
	  printf("%d",totalMoves);
	if(level==1)
	{printmoves();
	level2check();
	}
	  break;
	case 75:
	   movePosition(6);
	   setfillstyle(SOLID_FILL,3);
	   bar(30,50,300,280);
	   fill();
	   init();
	   rec();
	   pri();
	   gotoxy(14,23);
	   printf("%d",totalMoves);
	if(level==1)
	{printmoves();
	level2check();
	}
	break;
	case 80:
	   movePosition(8);
	   setfillstyle(SOLID_FILL,3);
	   bar(30,50,300,280);
	   fill();
	   init();
	   rec();
	   pri();
	   gotoxy(14,23);
	   printf("%d",totalMoves);
	   if(level==1)
	   {printmoves();
	   level2check();
	   }
	  break;
	case 72:
	   movePosition(2);
	   setfillstyle(SOLID_FILL,3);
	   bar(30,50,300,280);
	   fill();
	   init();
	   rec();
	   pri();
	   gotoxy(14,23);
	   printf("%d",totalMoves);
	   if(level==1)
	   {printmoves();
	    level2check();
	    }
	    break;
       }

       if(isDone())
       {delay(500);
	level++;
	cleardevice();
	gameover();
	if(level==1)
	  {totalMoves=0;
	   goto level;
	  }
	}

       }while(inputKey!=27);




//	getch();
	exit(1);

}
 void rec()
 {
     int i,j,k;  setcolor(RED);
     for(i=0;i<200;i+=50)
     for(j=0;j<240;j+=60)
     rectangle(j+100,i+100,j+50,i+60);
 }
 void pri()
  {
	int x,y,i,j;
	for( x=0,i=6;x<4;x++,i+=3)
	{
	for(y=0,j=10;y<4;y++,j+=7)
	{       if(puzzArr[x][y]==0)
		{
		  continue;
		}
	       gotoxy(p[x][y].h,p[x][y].v);
	       printf("%d",puzzArr[x][y]);
}
}
}


void init()
 {
     int x,y,i,j;
 for( x=0,i=6;x<4;x++,i+=3)
 {
 for(y=0,j=10;y<4;y++,j+=7)
 {
 p[x][y].h=j; p[x][y].v=i;
 }
 }
 }
 void movePosition(int Key)
 {
    int row=currRow,col=currCol,flag=0;
    setfillstyle(SOLID_FILL,1);
    bar(270,340,370,365);
    settextstyle(8,HORIZ_DIR,1);
    setcolor(15);

    if(Key==6&&currCol>0)      //LEFT
    {

	  currCol--;
	  swap(row,col);
	  totalMoves++;
	  outtextxy(292,340,"LEFT");
	  flag=1;
    }
    if(Key==4&&currCol<3)//RIGHT
    {
	  currCol++;
	  swap(row,col);
	  totalMoves++;
	  outtextxy(300,340,"RIGHT");
	  flag=1;
    }

    if(Key==2&&currRow>0)  //UP
    {
       currRow--;
       swap(row,col);
       totalMoves++;
       outtextxy(295,340,"UP");
       flag=1;
    }
    if(Key==8&&currRow<3)  //DOWN
    {
       currRow++;
       swap(row,col);
       totalMoves++;
       outtextxy(305,340,"DOWN");
       flag=1;
    }

    if(flag==0)
     {  setcolor(12);
	outtextxy(285,340,"INVALID");
     }

 }

 void swap(int preRow,int preCol)
 {
    int preValue,curValue;
    preValue=puzzArr[preRow][preCol];
    curValue=puzzArr[currRow][currCol];
    puzzArr[preRow][preCol]=curValue;
    puzzArr[currRow][currCol]=preValue;
 }

void design()
{int i,j,c=1;
setbkcolor(1);
setcolor(GREEN);
settextstyle(10,HORIZ_DIR,2);
outtextxy(100,2,"15 NUMBER PUZZLE GAME");

gotoxy(2,6);
printf("The next screen will have a 4X4 grid where numbers are in a random order");
gotoxy(2,7);
printf("Your task is to arrange these numbers in ascending order by using up,down,left");
gotoxy(2,8);
printf("and right arrow keys");

setcolor(15);
gotoxy(12,10);
printf("You have to arrange in this order");

for(j=12;j<20;j+=2)
for(i=20;i<40&&c<16;i+=5,c++)
{gotoxy(i,j);
printf("%d",c);
}
for(j=172;j<292;j+=30)
for(i=145;i<305;i+=40)
{rectangle(i,j,i+30,j+25);
}

setcolor(14);
settextstyle(8,HORIZ_DIR,3);
outtextxy(60,300,"----------BEST OF LUCK--------");
displaybox();

setcolor(128+4);
settextstyle(7,HORIZ_DIR,3);
outtextxy(180,370,"Press Enter to continue");

}

void displaybox()
{int i;
gotoxy(2,22);
for(i=2;i<80;i++)
{printf("%c",177);
}
gotoxy(2,23);
printf("%c",177);
gotoxy(2,24);
printf("%c",177);
gotoxy(2,25);
for(i=0;i<4;i++)
printf("%c\n ",177);

for(i=2;i<80;i++)
{printf("%c",177);
}
gotoxy(1,23);
for(i=0;i<6;i++)
printf(" %c\t\t\t\t\t\t\t\t\t      %c\n",177,177);

}

void print_goal()
{int i,j;
setcolor(15);
//line(0,0,0,479);
//line(639,0,639,479);
line(450,0,450,500);
settextstyle(8,HORIZ_DIR,2);
outtextxy(480,5,"YOUR GOAL");
for(j=40;j<220;j+=45)
for(i=460;i<640;i+=45)
rectangle(i,j,i+40,j+40);
settextstyle(6,HORIZ_DIR,2);
outtextxy(475,50,"1");
outtextxy(520,50,"2");
outtextxy(560,50,"3");
outtextxy(610,50,"4");
outtextxy(475,90,"5");
outtextxy(520,90,"6");
outtextxy(560,90,"7");
outtextxy(610,90,"8");
outtextxy(475,135,"9");
outtextxy(510,135,"10");
outtextxy(555,135,"11");
outtextxy(600,135,"12");
outtextxy(465,180,"13");
outtextxy(510,180,"14");
outtextxy(555,180,"15");


}


void fill()
{int i,j;
setfillstyle(SOLID_FILL,1);

for(i=0;i<200;i+=50)
for(j=0;j<240;j+=60)
{bar(j+100,i+100,j+50,i+60);
}

}

void displayMoves()
{int i;
gotoxy(4,21);
for(i=2;i<24;i++)
printf("%c",205);
gotoxy(3,21);
printf("%c",201);
for(i=22;i<25;i++)
{gotoxy(3,i);
printf("%c",186);
}
gotoxy(3,25);
printf("%c",200);
gotoxy(4,25);
for(i=2;i<24;i++)
printf("%c",205);
gotoxy(26,21);
printf("%c",187);
gotoxy(26,22);
printf("%c",186);
gotoxy(26,23);
printf("%c",186);
gotoxy(26,24);
printf("%c",186);
gotoxy(26,25);
printf("%c",188);
gotoxy(7,22);
printf("NUMBER OF MOVES:");
gotoxy(30,21);
printf("%c",201);
for(i=0;i<20;i++)
printf("%c",205);
printf("%c",187);
gotoxy(30,25);
printf("%c",200);
for(i=0;i<20;i++)
printf("%c",205);
printf("%c",188);
for(i=22;i<25;i++)
{gotoxy(30,i);
 printf("%c",186);
}
for(i=22;i<25;i++)
{gotoxy(51,i);
printf("%c",186);
}

}


int isDone()
{int isequence=1,i,j;
for(j=0;j<4;j++)
{for(i=0;i<4;i++)
{if(puzzArr[j][i]!=isequence)
     return 0;

if(isequence==15)
return 1;

isequence++;
}
}

}

void gameover()
{int i;
char message[50],levelmess[20],ch,levelbox[20],m1[40],m2[40];
i=totalMoves;
cleardevice();
setbkcolor(1);
//line(0,0,0,479);
//line(639,0,639,479);
setcolor(WHITE);
rectangle(70,120,570,300);
rectangle(75,125,565,295);
setfillstyle(SOLID_FILL,11);
floodfill(130,200,WHITE);
settextstyle(8,HORIZ_DIR,3);
sprintf(levelmess,"LEVEL %d CLEARED",level);
outtextxy(200,80,levelmess);
settextstyle(4,HORIZ_DIR,4);
setcolor(2);
outtextxy(150,130,"CONGRATULATIONS");
gotoxy(20,15);
settextstyle(3,HORIZ_DIR,1);
if(level==2)
{sprintf(message,"You have completed the game in %d moves",i);
setcolor(WHITE);
settextstyle(2,HORIZ_DIR,6);
outtextxy(3,3,"Press any key to exit");
setcolor(1);
outtextxy(130,200,message);
if(kbhit)
   exit(0);
getch();
}
else
{sprintf(message,"You have completed the LEVEL %d in %d moves",level,i);
 setcolor(1);
 settextstyle(2,HORIZ_DIR,6);
 outtextxy(130,200,message);
 settextstyle(2,HORIZ_DIR,6);
 setcolor(RED);
 outtextxy(200,250,"Press Enter to Continue");
 getch();
 cleardevice();
 setbkcolor(1);
 //line(0,0,0,479);
 //line(639,0,639,479);
 setcolor(WHITE);
 rectangle(70,120,570,300);
 rectangle(75,125,565,295);
 setfillstyle(SOLID_FILL,11);
 floodfill(130,200,WHITE);
 setfillstyle(SOLID_FILL,1);
 bar(475,155,515,175);
 setcolor(RED);
 settextstyle(3,HORIZ_DIR,2);
 sprintf(levelbox,"Do you want to play level %d(Y/N):",level);
 outtextxy(130,150,levelbox);
 gotoxy(62,11);
 ch=getch();
 printf("%c",ch);
 if(ch=='y')
    {delay(1000);
     cleardevice();
     //line(0,0,0,479);
     //line(639,0,639,479);
     setcolor(WHITE);
     rectangle(70,120,570,300);
     rectangle(75,125,565,295);
     setfillstyle(SOLID_FILL,11);
     floodfill(130,200,WHITE);
     setcolor(RED);
     settextstyle(2,HORIZ_DIR,6);
     sprintf(m1,"Now in Level %d you have to complete the game",level);
     sprintf(m2,"in less than %d moves",desiredMoves);
     outtextxy(100,170,m1);
     outtextxy(190,185,m2);
     setcolor(WHITE);
     settextstyle(2,HORIZ_DIR,6);
     setcolor(1);
     outtextxy(180,220,"Press any key to proceed");
     getch();
     }else{exit(0);}
}
}

void level2check()
{char c;
if(totalMoves>desiredMoves)
 { cleardevice();
do
{setbkcolor(1);
//line(0,0,0,479);
//line(639,0,639,479);
setcolor(WHITE);
rectangle(70,120,570,300);
rectangle(75,125,565,295);
setfillstyle(SOLID_FILL,11);
floodfill(130,200,WHITE);
settextstyle(2,HORIZ_DIR,6);
outtextxy(3,3,"Press ESC key to exit");
setcolor(12);
settextstyle(4,HORIZ_DIR,5);
outtextxy(200,50,"GAMEOVER");
setcolor(RED);
settextstyle(8,HORIZ_DIR,4);
outtextxy(180,150,"LEVEL 2 FAILED!");
setcolor(1);
settextstyle(6,HORIZ_DIR,2);
outtextxy(150,210,"You have taken more than 200 moves");
}while((c=getch())!=27);

}
}

int getInvcount()
{int i,j,invcount=0,n=0;
for(i=0;i<4;i++)
  for(j=0;j<4;j++)
    { arr[n]=puzzArr[i][j];
      n++;
    }

for(i=0;i<4*4-1;i++)
{
  for(j=i+1;j<4*4;j++)
   {//count pairs(i,j) such that i appears
    //before j,but i>j
     if(arr[j]&&arr[i]&&arr[i]>arr[j])
	invcount++;
   }
}

return invcount;

}

int IsSolvable()
{//Count Inversions in given puzzle
int invcount;
invcount=getInvcount();
//If Inversion count is even
//return true
if(invcount%2==0)
    return 1;
else
    return 0;
}

void printmoves()
{int k;
setcolor(WHITE);
rectangle(460,300,630,400);
rectangle(465,305,625,395);
gotoxy(61,21);
printf("REMAINING MOVES:");
gotoxy(67,23);
k=desiredMoves-totalMoves;

printf("%03d",k);


}