#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

//the following declarations are for global variables

char username[35], newname[35];
  int i, j, pt1=0, pt2=0, huser, hcomp[3]={1,2,3};
  char ch, ch2, ch3; int len; int temp;

//funtion declarations

void gotoxy(int x, int y);
void init();
void maingame();
void startup();
void check();
void ending();

//function to move cursor to specific point on screen

void gotoxy(int x, int y)
{ printf("%c[%d;%df", 0x1B, y, x);
}

//function to initialize the player name

void init()
{ system("cls");
  gotoxy(10,10);
  printf("\nEnter your name: \n");
  scanf("%s", username);
  for(int j=0;j<strlen(username);j++)
  toupper(username[j]);
  //strcpy(newname, username);
}

//funtion to execute the ending of the game

void ending()
{    system("cls");
     gotoxy(20,19);
     printf("That's it!! So... who's the winner?\n");
     gotoxy(20,20);
     printf("********************************************");
     gotoxy(20,21);
     printf("*                                          *");
     gotoxy(20,22);
     printf("*  Your score: %d || Computer's score: %d   *", pt1, pt2);
     gotoxy(20,23);
     printf("*                                          *");
     gotoxy(20,24);
     printf("********************************************");
    
     gotoxy(20, 35);
     if(pt1>pt2)
     { printf("YOU WON! Good going..\n"); system("cls"); exit(0);  }
     else if(pt1<pt2)
     { printf("HARD LUCK! Btter luck next time!\n"); system("cls"); exit(0);  }
     else if(pt1==pt2)
     { printf("WOW! It's a tie! Do you want a tie breaker? (y/n)\n");
       scanf("%c", &ch3);
       if(ch3=='n')
       { system("cls"); exit(0); }
       else if(ch3=='y') { system("cls");
       maingame(); }
     }

}

//funtion that takes care of the main running of game. Invokes other functions

void maingame()
{  srand(time(NULL));
   ch2='c'; int k=0;
   strcpy(newname, username);
   while(k<6 && ch2=='c')
   { gotoxy(10,30);
     printf("\nROUND %d\n", k+1);
     gotoxy(10,31);
     printf("------ --\n");
     gotoxy(10,20);
     printf("%s, enter your hand: 1 for ROCK, 2 for PAPER, 3 for SCISSORS\n\n", newname);
     scanf("%d", &huser);
     gotoxy(10,40);
     //random:
     temp=rand()%3;
     printf("Computer's hand: ");
     if(temp>=0 && temp<3) {
     printf("%d", hcomp[temp]);  }
     //else goto random;
     check();
     k++;
     gotoxy(10,30);
     printf("Enter next round? Press 'c' to continue or press 'e' to exit\n\n");
     scanf("%c", &ch2);
   }

     ending();
       
}

//funtion to check for hands and increment scores

void check()
{ if((hcomp[temp]==1 && huser==2) || (hcomp[temp]==2 && huser==3) || (hcomp[temp]==3 && huser==1))
  pt1+=1;
  else if((hcomp[temp]==2 && huser==1) || (hcomp[temp]==3 && huser==2) || (hcomp[temp]==1 && huser==3))
  pt2+=1;
  else if((hcomp[temp]==1 && huser==1) || (hcomp[temp]==2 && huser==2) || (hcomp[temp]==3 && huser==3))
  { pt1+=0; pt2+=0;  }
}

//function to initiate the game's starting sequence

void startup()
{ system("cls");
  gotoxy(21,10);
  printf("ENTER to play\n");
  getchar();
  system("cls");
  printf("   ###########     ###########      ###########    \n");
  printf("   #          #    #          #    #               \n");
  printf("   #          #    #          #    #               \n");
  printf("   #          #    #          #    #               \n");
  printf("   ###########     ###########      ##########     \n");
  printf("   #         #     #                          #    \n");
  printf("   #          #    #                          #    \n");
  printf("   #          #    #                          #    \n");
  printf("   #          #    #               ###########     \n");
  printf("           ROCK  -  PAPER  -  SCISSORS             \n\n");
  printf("\n\n\n   INSTRUCTIONS: The game runs for 6 rounds. Enter your hand against the computer's to fight your way up the league!\n\n\n");
  printf("          VERSION 0.11.04 (BETA), 2018\n\n\n");
}

//main funtion that invokes all other functions

void main()
{ 
  startup();
  printf("Enter 'y' to continue or 'n' to exit\n");
  input:
  scanf("%c", &ch);
  if(ch=='n')
  { printf("\nExiting...\n");
    exit(0);
  }
  else if(ch!='y')
  { printf("Enter valid choice\n");
    goto input;
  }
  else
  init();

  system("cls");
  maingame();
  

}
  
