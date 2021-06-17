#include<time.h>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<dos.h>
#include<stdlib.h>
static int x=1;
#define pos gotoxy(33,x++)
#define ln  printf(".......................");
COORD coord={0,0};
void gotoxy(int x,int y);
void gotoxy(int x,int y)
{
coord.X=x;
coord.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void delay(unsigned int mseconds)
{
clock_t goal=mseconds+clock();
while(goal>clock());
}
void setcolor(int ForgC)
{
WORD wColor;
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO csbi;
if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
{
wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
SetConsoleTextAttribute(hStdOut, wColor);
}
return;
}
void sett();
int t=30;
int c=0;
char name[15];
void getscore(int score,int speed,int level);
void startgame();
void scorecard();
void About_us();
void help();
void rectangle(int x,int y,int l,int b)
{
int i,m;
gotoxy(x,y);
printf("%c",201);
for(i=x+1;i<l-1;i++)
{
gotoxy(i,y);
printf("%c",205);
}
gotoxy(i,y);
printf("%c",187);
for (m=y+1;m<b;m++)
{
gotoxy(x,m);
for(i=x;i<l;i++)
{
if(i==x||i==l-1)
{
gotoxy(i,m);
printf("%c",186);
}
}
}
gotoxy(x,m);
printf("%c",200);
for(i=x+1;i<l-1;i++)
{
gotoxy(i,m);
printf("%c",205);
}
gotoxy(i,m);printf("%c",188);
}
int main()
{int ch;
time_t t;
time(&t);
x=1;
system("cls");
pos;
setcolor(14) ;
printf("welcome to typing game ");
setcolor(15) ;
pos;
printf("%s",ctime(&t));
pos;
ln pos;
if(c==0)
{
printf("Enter player's name::");
gets(name);
}
c++;
pos;
ln pos;
printf("#..MAIN MENU..#");pos;
ln
pos;
printf("1.startgame");
pos;
printf("2.scorecard");
pos;
printf("3.Set the time limit::");
pos;
printf("4.Help");
pos;
printf("5.About us");
pos;
printf("0.exit");
pos;
printf("Enter your choice::");
scanf("%d",&ch);
pos;
switch(ch)
{case 1:startgame();
break;
case 2:scorecard();
break;
case 3:sett();
main();
case 4:help();
break;
case 5:About_us();
break;
case 0:system("cls");
gotoxy(17,10);
printf("This Game is created by \nMohanraj S\nNaveen\nNeithhala\nNarendran");
delay(1000);
exit(1);
default:main();
}
getch();
}
void startgame()
{
int score=0,level=1,mode=100,count=0;
clock_t begin;int time_spent,speed;
int r,letter,ch;
rectangle(0,0,70,15);
delay(500);
system("cls");
srand(time(NULL));
x=2;
pos;
setcolor(9);
printf("select the Mode");
pos;
ln
pos;
printf("1.Easy mode");
pos;
printf("2.Normal mode");
pos;
printf("3.hard mood");
pos;
printf("4.Back to main menu");
pos;
scanf("%d",&level);
if(level==4)
main();
else
{
if(level==1)
mode=65;
if(level==2)
mode=97;
if(level==3)
mode=120;
begin=clock();
while(1)
{
system("cls");
time_spent=(int)(clock()-begin)/CLOCKS_PER_SEC;
if(time_spent>=t)
break;
r=rand()%1000;
r=r%26+mode;
gotoxy(20,8);
printf("....Type the following character.... \t\t\tThat is following upcoming letters.......");
gotoxy(36,11) ;
printf(" %c",r);
letter=getch();
if(letter!=r)
break;
else
{
count++;
score=score+10;
gotoxy(28,9);
printf("score=%d",score);
gotoxy(37,9);
printf("time_spent=%d sec",time_spent);
if(level==1)
delay(400);
if(level==2)
delay(200);
if(level==3)
delay(100);
}
}
gotoxy(26,x);
delay(400);
setcolor(5);
++x;
pos;
speed=(count*60)/time_spent ;
if(time_spent<t-1)
printf("You  are looser!loser!loser!Game Over!");
else
{
setcolor(15);
printf("Times up !Game over!");
pos;
setcolor(9);
if((speed>=40)&&(speed<=50))
{
printf("Good Work !Keep it up!");
pos;
printf("You got silver medal");
}
else
if(speed>50)
{
printf("Nice work! You got Gold medal");
}
else
printf("Sorry no medal !you need practise..");
}
pos;
printf("Total score is ::%d",score);
pos;
printf("Your net speed=%d letter per minute",speed);
getscore(score,speed,level);
++x;
pos;
printf("1.# play again #");
pos;
printf("2.# main menu #");
pos;
printf("3.exit");
pos;
printf("Enter your choice::");
scanf("%d",&ch);
switch(ch)
{
case 1:startgame();
break;
case 2:main();
break;
case 3:system("cls");
gotoxy(17,10);
printf("This game is game is created by \nMohanraj\nNaveen\nNeithhala\nNarendran");
delay(1000);
exit(1);
default:
pos;
printf("wrong choice!!!!!");
pos;
main();
}
}
}
void sett()
{
int ch;
system("cls");
setcolor(11);
x=5;
pos;
printf("Set the time limit for game in minute::");
pos;
ln
pos;
printf("press 0 for half minute");
pos;
printf("press 1 for 1 minute");
pos;
printf("press 2 for 2 minute");
pos;
scanf("%d",&ch);
switch(ch)
{
case 0:t=30;
break;
case 1:t=60;
break;
case 2:t=120;
break;
default:main();
}
}
void help()
{
system("cls");
gotoxy(7,5);
setcolor(9);
printf("#......Rules of the Game......#");
gotoxy(7,6);
printf("=>Enter your name as player name");
gotoxy(7,7);
printf("=>Set the time limit under option 3 in main menu(default limit is 30 sec)");
gotoxy(7,8);
printf("=>select the level and get started :");
gotoxy(7,9);
printf("=>Characters are displayed and you have to type them as fast as you can..");
gotoxy(7,10);
printf("=>Avoid incorrect typing otherwise game will be over..");
getch();main();
}
void About_us()
{system("cls");
gotoxy(7,7);
printf("Hello everyone,\nThis is EIE 1st Year students\nGCT\nCoimbatore.\n\nMohanraj\n\tNaveen\n\t\tNeithhala\n\t\t\tNarendran");
printf("\n\n.Be enjoy while playing this game.\nI think it would be better....thanks...");
getch();
main();
}
void getscore(int score,int speed,int level)
{
FILE *a;
a=fopen("file.txt","a");
pos;
if(a==NULL)
printf("error in opening file");
fprintf(a,"\nname=%s   score=%d    speed=%d    level=%d",name,score,speed,level);
fclose(a);
pos;
printf("scorecard updated");
}
void scorecard()
{int ch;
FILE *a;
system("cls");
x=3;
printf("\t\t\t....The scores are...\n");
a=fopen("file.txt","r");
while((ch=fgetc(a))!=EOF)
{
printf("%c",ch);
}
getch();
main();
}

