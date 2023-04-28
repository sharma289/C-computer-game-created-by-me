#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>

void main()
{
  int a1,b1,y1;
  int a2,y2;
  int a3,b3,y3;
  int a4,y4;
  int x,y,i;
  char move;
  int time,score,asc;
  randomize();
  start:
  a1=0,b1=0,y1=1;
  a2=0,y2=10;
  a3=0,b3=0,y3=16;
  a4=0,y4=4;
  x=40,y=22;
  time = 70, score=0,asc=50;
  textattr(15);
  clrscr();
  gotoxy(20,8);
  cout<<"               ATTENTION !!!";
  gotoxy(20,10);
  cout<<"MAKE SURE THE PROGRAM IS OPEN IN FULL SCREEN";
  gotoxy(20,11);
  cout<<"          If not press n to exit ";
  move=getch();
  if (move == 'n' || move == 'N')
   exit(0);

  clrscr();

  gotoxy(25,3);
  cout<<"        GAME INSTRUCTIONS";
  gotoxy(25,5);
  cout<<"       MOVE UPWARD    --  w";
  gotoxy(25,6);
  cout<<"       MOVE DOWNWARD  --  s";
  gotoxy(25,7);
  cout<<"       MOVE LEFT      --  a";
  gotoxy(25,8);
  cout<<"       MOVE RIGHT     --  d";
  gotoxy(25,9);
  cout<<"       EXIT           --  e";
  gotoxy(30,14);
  cout<<"PRESS ANY KEY TO START";
  getch();

  again:
  while (!kbhit())
 {
  clrscr();
  /*
  if (y1 ==1)
  {
   textattr(31);
   clrscr();
   delay(75);
   textattr(15);
   clrscr();
   }  */

  for (i=1;i<25;i++)
  {
   gotoxy(24,i);
   cout<<"I";
   gotoxy(54,i);
   cout<<"I";
   }

   gotoxy(5,10);
   cout<<"SCORE : "<<score;

   if (asc >= 0 && asc <= 40)
   {
    gotoxy(34,9);
    cout<<"SPEED UP!!!";
    asc++;
   }

   gotoxy(x,y);
   cout<<"";

  if ((a1==x&&y1==y) || (b1==x&&y1==y))
   goto over;
  if (a2==x&&y2==y)
   goto over;
  if ((a3==x&&y3==y) || (b3==x&&y3==y))
   goto over;
  if (a4==x&&y4==y)
   goto over;

  if (y1 == 1)
  {
   a1=26+random(27);
   b1=26+random(27);
   score=score+2;
   }
  if (y2 == 1)
  {
   a2=26+random(27);
   score++;
   }
  if (y3 == 1)
  {
   a3=26+random(27);
   b3=26+random(27);
   score=score+2;
   }
   if (y4 == 1)
   {
    a4=26+random(27);
    }

  if (y1 == 25)
    y1=0;
  if (y2 == 25)
    y2=0;
  if (y3 == 25)
    y3=0;
  if (y4 == 25)
    y4=0;

  if (y1 > 0)
  {
   gotoxy(a1,y1);
   cout<<"W";
   gotoxy(b1,y1);
   cout<<"V";
   }
  if (y2 > 0 && a2 > 25)
  {
   gotoxy(a2,y2);
   cout<<"X";
   if ((score>100) && (a2 >= 27 && a2 <= 35) && (y2 > 8))
    a2++;
   if ((score>100) && (a2 >= 45 && a2 <= 53) && (y2 > 8))
    a2--;
   }
  if (y3 > 0 && a3 > 25)
  {
   gotoxy(a3,y3);
   cout<<"0";
   gotoxy(b3,y3);
   cout<<"#";
   }
  if (y4 > 0 && a4 > 25)
  {
   gotoxy(a4,y4);
   cout<<"8";
   }

  if (score%120 == 0)
  {
   time=time-5;
   asc=0;
   goto again;}

  gotoxy(40,25);
  delay(time);
  nosound();
  y1++;
  y2++;
  y3++;
  y4++;

  }

  move=getch();
  if (move == 'w' && y>2)
   y=y-1;
  else if (move == 's' && y<24)
   y=y+1;
  else if (move == 'a' && x>26)
   x=x-2;
  else if (move == 'd' && x<52)
   x=x+2;
  else if (move == 'e')
   goto over;
  sound(200);
  goto again;

  over:

  for(i=0;i<20;i++)
  {
   sound(500-i*40);
   delay(16);

   }
   nosound();
  textattr(79);
  clrscr();
  gotoxy(35,9);
  cout<<"GAME OVER";
  gotoxy(30,11);
  cout<<"YOUR SCORE IS-> "<<score;
  gotoxy(29,13);
  cout<<"Press Y to play again";
  move = getch();
  if (move == 'y' || move == 'Y')
   goto start;
   sleep(1);

}
