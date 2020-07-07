#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

char ch[10][130]={"Shantinagar Ground","Sankhamul Ground","Tinkune Ground","Chabahil Ground","Maitidevi Ground"};
char name[32][100]={'\0'};
char number[32][2]={'\0'};
int num1[32]={0};
int trno;
void bus();//for list of bus
void name_number(int booking,char numstr[100]);
void booking();//for booking the tickets
int read_number(int trno);//for reading the number from the file
void read_name(int trno);//for reading the name from the file
void status();//for printing the status by user input
void status_1(int trno);//for printing the status while booking ticket
void cancle();
void login();

int main()
{
	login();
    int num,i;
    do{
    system("cls");
    printf("\n\n\n");
  printf("\t\t\t\t       ========================================\n");
    printf("========================================= WELCOME TO FUTSAL MANGEMENT SYSTEM ==========================================\n");
    printf("\t\t\t\t       ========================================\n\n\n");
    printf("(1) View Available Grounds\t");
    printf("(2) Book Ground");
    printf("\t   ");
    printf("(3) Cancel Booking\t");
    printf("(4) Ground Status\t");
    printf("(5) Exit\n\n");
    printf("========================================================================================================================\n");
    printf("========================================================================================================================\n\n");
    printf("\n");
    printf("Choose from above list:-\t");
    scanf("%d",&num);
    switch(num)
    {
    case 1:
        bus();//for list of bus
        getch();
        break;

    case 2:
        booking();//for booking the tickets
        break;
    case 3:
        cancle();
        break;
    case 4:
        status();
        break;
    }
    }while(num != 5);
    system("CLS");
    printf("\t==========================================================================================================\n");
    printf("\t\t\t\t\t====The System is now exiting====\t\t\t\t\t\t\n");
    printf("\t==========================================================================================================\n\n\n\n\n\n");
    printf("\t\t\t\tThe System is created by Rezin Shrestha and Anish Pokhrel\t\t\t\t");
    printf("\t\t\t\t\tThank You For Using Our System\t\t\t\t");
    getch();
    return 0;

}


void bus()
{
    system("cls");
    printf("\n\n\n");
    printf("===========================================\n");
    printf("             List Of Grounds\n");
    printf("===========================================\n\n");
    printf("(1)\t  %s\n",ch[0]);
    printf("\n");
    printf("(2)\t  %s\n",ch[1]);
    printf("\n");
	printf("(3)\t  %s\n",ch[2]);
    printf("\n");
	printf("(4)\t  %s\n",ch[3]);
	printf("\n");
	printf("(5)\t  %s\n",ch[4]);
	printf("===========================================\n\n");
}

void booking()
{

    int i=0;
    char numstr[100];
system("cls");
/*printf("Enter the Bus number:--->");
scanf("%d",&trno);
system("cls");
printf("===============================================\n\n\n");*/ //for selecting coach
printf("=============================================================================\n");
printf("=========================== Ground Booking System ===========================\n");//for selecting coach
printf("=============================================================================\n\n");
bus();
printf("\n\nSelect the Ground:\t");
scanf("%d",&trno);
system("cls");
printf("=============================================================================\n");
printf("=========================== Ground Booking System ===========================\n");//for selecting coach
printf("=============================================================================\n");
printf("\n\n\n");
printf("You are going to book ground no-> %d -> %s\n",trno,ch[trno-1]);
printf("\nPress any key to continue...\n");
getch();
status_1(trno);
 FILE *f1, *fopen();//for reading the seats from the user.
 char str1[80]="32",str2[4],str3[4];
 int seat1,seat2,booking=0;
if(trno == 1)
{
 f1 = fopen("tr1.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}else if(trno == 2)
{
 f1 = fopen("tr2.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}else if(trno == 3)
{
 f1 = fopen("tr3.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}
else if(trno == 4)
{
 f1 = fopen("tr4.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}
else if(trno == 5)
{
 f1 = fopen("tr5.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}
seat1=atoi(str1);//covert the string into number
if(seat1 <= 0)
{
 printf("No any shifts available at the moment. Please try again later :) ");
}else
{
printf("\nAvailable Shifts:\t%d\n",seat1);
printf("\nYou want to book how many shifts?\n");
scanf("%d",&booking);
printf("\n");

seat1=seat1-booking;
itoa(trno,numstr,10);
name_number(booking,numstr);
printf("\n\t\t\t\tThe Total Booking Amount = %d",1200*booking);
printf("\n\n\t\t\t\t\t 'Thank You' \n");
getch();
itoa(seat1, str1, 10);
//for reading the seats from the user.
if(trno == 1)
{
 f1 = fopen("tr1.txt","w");
 fputs(str1,f1);
 fclose(f1);
}
else if(trno == 2)
{
 f1 = fopen("tr2.txt","w");
 fputs(str1,f1);
  fclose(f1);
}
else if(trno == 3)
{
 f1 = fopen("tr3.txt","w");
 fputs(str1,f1);
  fclose(f1);
}
else if(trno == 4)
{
 f1 = fopen("tr4.txt","w");
 fputs(str1,f1);
  fclose(f1);
}
else if(trno == 5)
{
 f1 = fopen("tr5.txt","w");
 fputs(str1,f1);
 fclose(f1);
}
}
}



void name_number(int booking,char numstr[100])
{
char tempstr[100],tempstr1[12]="status",tempstr2[12]="number";
int number;
    FILE *a,*b;
    int i=0;
   strcat(numstr,".txt");
   strcat(tempstr1,numstr);
   strcat(tempstr2,numstr);
   a = fopen(tempstr1,"a");//for open the file to write the name in the file
   b = fopen(tempstr2,"a");//for open the file for writing the number in the file
for(i=0; i<booking; i++)//for entering the person name and seat number in the file
{
    printf("============================Enter the details for Shift number %d============================\n\n\n",i+1);
      printf("\t\t\t\tPlease select the shift:\t");
      scanf("%d",&number);
      printf("\t\t\t\tEnter the name of person to book for ground:\t");
      scanf("%s",name[number-1]);
    printf("\n============================================================================================\n\n");
    printf("\n");
      itoa(number, tempstr, 10);
      fprintf(a,"%s ",name[number-1]);
      fprintf(b,"%s ",tempstr);

}
fclose(a);
fclose(b);
}



int read_number(int trno)//for putting the numeric value in the array
{
char tempstr[100],tempstr2[12]="number";
FILE *a,*b;
char numstr[100];
int i=0,j=0,k;
itoa(trno,numstr,10);
strcat(numstr,".txt");
strcat(tempstr2,numstr);
a = fopen(tempstr2,"a+");//for open the file to write the name in the file
   while(!feof(a))
   {
      number[i][j] = fgetc(a);

      if(number[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
      j++;
      }
   }
   k=i;
   for(i=0; i<k; i++)
   {
       num1[i] = atoi(number[i]);
   }
   fclose(a);
   return k;
}


void read_name(int trno)//for putting the numeric value in the array
{
char tempstr1[12]="status";
FILE *b;
char numstr[100];
int i=0,j=0,k=0;
itoa(trno,numstr,10);
strcat(numstr,".txt");
strcat(tempstr1,numstr);
b = fopen(tempstr1,"a+");//for open the file to write the name in the file
   while(!feof(b))
   {
      name[i][j] = fgetc(b);

      if(name[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
        j++;
      }

   }
   name[i][j]='\0';
   k=i;
   fclose(b);
}

void status()
{
system("cls");
printf("=========================== Status Of Ground For Futsal Booking ===========================\n\n\n");
    int i,trno,index=0,j;
    bus();
    printf("You want the information for which ground?\n");
    scanf("%d",&trno);
    printf("Your Ground Number is %d -> %s\n",trno,ch[trno-1]);
    status_1(trno);
    getch();
    /*j=read_number(trno);
    read_name(trno);
    printf("____________________________________________________________________________________________________________________\n");
    printf("                                      Bus.no-->%d---->%s                                                            \n",trno,ch[trno-1]);
    printf("____________________________________________________________________________________________________________________\n");
    char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<8; i++)
    {
        printf("\t\t\t\t");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
            }
            printf("\n");
    }*/
}

void status_1(int trno)
{
    system("cls");
    printf("======================== Your Ground Number is %d -> %s ========================\n",trno,ch[trno-1]);
    printf("=========================== Status Of Ground For Futsal Booking ===========================\n");
    printf("===========================================================================================\n");
    printf("=========================================Shifts============================================\n");
    printf("===========================================================================================\n");
    printf("\n\t 1. 08:00-09:00 \t 2. 09:00-10:00 \t 3. 10:00-11:00 ");
    printf("\n\t 4. 11:00-12:00 \t 5. 12:00-01:00 \t 6. 01:00-02:00 ");
    printf("\n\t 7. 02:00-03:00 \t 8. 03:00-04:00 \t 9. 04:00-05:00 ");
    printf("\n\t 10. 05:00-06:00 \t 11. 06:00-07:00 \t 12. 07:00-08:00 \n");
    printf("===========================================================================================\n");
    printf("====================================Available Shifts=======================================\n");
    printf("===========================================================================================\n\n");
    int i,index=0,j;
    j=read_number(trno);
    read_name(trno);
    char tempname[13][10]={"Empty ","Empty","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<4; i++)
    {
        printf("\t\t\t\t");
        for(j=0; j<3; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
          }
            printf("\n");

    }
    printf("============================================================================================\n\n\n");
}


void cancle()
{
 int seat_no,i,j;
 char numstr[100],tempstr2[15]="number",tempstr1[15]="status";
 system("cls");
 bus();
 printf("Cancle the booking for which ground?\n");
 scanf("%d",&trno);
 itoa(trno,numstr,10);
 strcat(numstr,".txt");
 strcat(tempstr1,numstr);
 strcat(tempstr2,numstr);
 read_number(trno);
 read_name(trno);
 status_1(trno);
 printf("Enter the shift number:\t");
 scanf("%d",&seat_no);
 FILE *a,*b;
 a = fopen(tempstr1,"w+");
 b = fopen(tempstr2,"w+");
 for(i=0; i<32; i++)
 {
     if(num1[i] == seat_no)
     {
         for(j=0; j<32; j++)
         {
             if(num1[j] != seat_no && num1[j] != 0)
             {
                 fprintf(b,"%d ",num1[j]);
                 fprintf(a,"%s",name[j]);
             }
             else if(num1[j] == seat_no && num1[j] != 0)
             {
                 strcpy(name[j],"Empty ");
             }
         }
     }
 }
fclose(a);
fclose(b);
printf("\n\n");
    printf("=============================================================================================================\n");
 printf("\t\t\t\tCancellation for this shift has been done successfully \t\t\t\n");
    printf("=============================================================================================================\n");
    getch();
}


void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="admin";
    char pass[10]="welcome";
    do
{
	system("cls");
    printf("\n  ==============================================================================  ");
    printf("\n  =========================  Please Login To Continue  =========================  ");
    printf("\n  ==============================================================================  \n");
    printf(" \n                                   USERNAME:");
	scanf("%s", &uname);
	printf(" \n                                   PASSWORD:");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword);
		if(strcmp(uname,"admin")==0 && strcmp(pword,"welcome")==0)
	{
	printf("\n\n");
	    printf("\n===================================================================================\n");
	printf("\n                          You are successfully logged in\n");
	 printf("\n===================================================================================\n");
	printf("                       Welcome To Futsal Management System");
	 printf("\n===================================================================================\n");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n                             LOGIN IS UNSUCESSFUL");
		a++;

		getch();//holds the screen

	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\n        Sorry you have entered the wrong username or password. Please try again");

		exit(-1);
		getch();

		}

		system("cls");
}
