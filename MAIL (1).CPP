#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

struct message
 {
  char from[20],to[20];
  char mail[100];
 };


struct user
 {
	char username[20],password[20];
 }u,a;

void menu();

void signin()
 {
  FILE *f;
  clrscr();
  int flag=0;
  char users[20],pass[20],ch;
  printf("\n\n\n                     _______________SIGNIN_________________");
  printf("\n\n      Enter the username:");
  gets(users);
  printf("\n      Enter the password:");
  gets(pass);
  printf("\n\n           ");
  f=fopen("user.dat","rb");
	while(fread(&u,sizeof(u),1,f)==1)
	 {
	  if(check(users,pass)==1)
		{
		 for(int j=0;j<2;++j)
	{
	 for(int i=0;i<3;++i)
	  {
		printf(".");
		sleep(1)
		}
	 for(int k=0;k<3;k++)
	  printf("\b");
	 printf("      ");
	 printf("\b\b\b\b\b\b");
	}
		 printf("\n\n             Login Successful!");
		 flag=1;
		 break;
		}
	 }
	fclose(f);
	if(flag==0)
	 {
		for(int i=0;i<6;++i)
	{
	 printf(".");
	 sleep(1);
	}
	  printf("Invalid Credentials.Pls Try Again Later!!!");
	  sleep(1);
	  menu();
	 }
	else
	loginp();
 }

signup()
 {
  FILE *f;
  char repass[20];
  printf("\n\n\n               ______________SIGNUP_____________");
  printf("\n           Enter the username:");
  gets(u.username);
  printf("\n           Enter the password:");
  gets(u.password);
  printf("\n           Re-Enter the password:");
  gets(repass);
  printf("         ");
  if(strcmp(u.password,repass)!=0)
	 {
		for(int j=0;j<3;++j)
	{
	 for(int i=0;i<6;++i)
	  {
		printf(".");
		sleep(1);
		}
	 for(int k=0;k<6;k++)
	  printf("\b");
	 printf("      ");
	 printf("\b\b\b\b\b\b");
	}
	  printf("\n\n         Passwords Dont match!!");
	  signup();
	 }
  else
	 {
	  for(int i=0;i<5;++i)
	{
	 printf(".");
	 sleep(1);
	}
	  f=fopen("user.dat","ab");
	  fwrite(&u,sizeof(u),1,f);
	  fclose(f);
	  printf("\n     Account Created!!");
	  sleep(1);
	  menu();
	 }
 }


int check(char u[20],char p[20])
 {
  if(strcmp(u,u.username)==0&&strcmp(p,u.password)==0)
		return 1;
	 else
		return 0;
 }


void getmail()
{
  FILE *f;
  int flag=0;
  char str[20];
  printf("\n\nEnter the reciever's address:");
  gets(str);
  f=fopen("user.dat","r");
  while(fread(&a,sizeof(a),1,f)==1)
	{
	 if(strcmp(a.username,str)==0)
	  {
		flag=1;
		break;
		}
	}
  fclose(f);
  if(flag==0)
	{
	 printf("Invalid reciever name");
	 loginp();
	}
  else
	{
	 message m;
	 printf("\n Enter the message");
	 gets(m.mail);
	 strcpy(m.from,u.username);
	 strcpy(m.to,a.username);
	 f=fopen("mail.dat","ab");
	 fwrite(&m,sizeof(m),1,f);
	 fclose(f);
	 printf("Your message has been sent! ");
	 loginp();
	}
 }




void loginp()
 {
  printf("\n\n\n\n ");
  for(int k=0;k<8;k++)
	{
	 printf("_________");
	 sleep(1);
	}
  sleep(1);
	 int choice;
	 printf("                    WELCOME:");puts(u.username);printf("\n\n\n\n");
	 printf("  1.INBOX\n  2.OUTBOX\n  3.COMPOSE\n  4.SIGNOUT\n\n\n\n     : ");
	 scanf("%d",&choice);
	 switch(choice)
		{
	 case 1:
	  inbox();
	  break;
	 case 2:
	  outbox();
	  break;
	 case 3:
	  getmail();
	  break;
	 case 4:
		 printf("\n\n\n\n ");
		 for(int k=0;k<8;k++)
		  {
			printf("_________");
			sleep(1);
		  }
		printf("\n\n\n   Signing Out");
		for(int j=0;j<3;++j)
		 {
		  for(int i=0;i<6;++i)
			{
			 printf(".");
			 sleep(1);
			}
		  for(int k=0;k<6;k++)
			 printf("\b");
			 pritf("      ");
			 printf("\b\b\b\b\b\b");
		  if(j==2)
			printf("......");
		 }
	  sleep(1);
	  menu();
	  break;
	 default:
	  printf("Invalid choice");
	  loginp();
  }
 }


void inbox()
 {
  FILE *f;
  message m;
  int ch,i=1,flag=0;
  f=fopen("mail.dat","r");
  printf("\n\n\n               ____________________INBOX__________________\n\n\n");
  while(fread(&m,sizeof(m),1,f)==1)
	{
	 if(strcmp(m.to,u.username)==0)
	  {
		printf("     ");printf("%d",i);printf(".From:");printf("%s",m.from);printf(":");
		 for(int c=0;c<10;c++)
			{
			 if(c==0)
			  {
				printf("    ");printf("%c",m.mail[c]);
			  }
			 printf("%c",m.mail[c]);
			}
		  printf("\n");
		i++;
	  }
	}
  printf("\n     ");printf("%d",i);printf(".GO TO HOME PAGE\n\n");
  printf("\n      Enter your choice:");
  scanf("%d",%&ch);
  if(ch==i)
	 loginp();
  i=1;
  fclose(f);
  f=fopen("mail.dat","r");
  while(fread(&m,sizeof(m),1,f)==1)
	{
	 if(strcmp(m.to,u.username)==0)
	  {
		if(i==ch)
		 {
		  flag=1;
		  break;
		 }
		else
		 i++;
	  }
	}
  if(flag==1)
	{
	 printf("\n\n\n                   ");
	 printf("From:");puts(m.from);printf("\n                    ");puts(m.mail);
	 fclose(f);
	 inbox();
	 }
	else
	 {
	  printf("\nInvalid choice");
	  loginp();
	 }

  }

void outbox()
 {
  FILE *f;
  message m;
  int ch,i=1,flag=0;
  f=fopen("mail.dat","r");
  printf("\n\n\n                  ____________________OUTBOX__________________\n\n\n");
  while(fread(&m,sizeof(m),1,f)==1)
	{
	 if(strcmp(m.from,u.username)==0)
	  {
		printf("     ");printf("%d",i);printf(".To:");puts(m.to);printf(":");
		for(int c=0;c<10;c++)
		 {
		  if(c==0)
			{
			 printf("      ");
			 printf("%c",m.mail[c]);
			}
		  printf("%d",m.mail[c]);
		 }
		printf("\n");
		i++;
	  }
	}
  printf("\n     ");printf("%d",i);printf(".GO TO HOME PAGE\n\n");
  printf("\n     Enter your choice:");
  scanf("%d",&ch);
  if(ch==i)
	 loginp();
  i=1;
  fclose(f);
  f=fopen("mail.dat","rb");
	while(fread(&m,sizeof(m),1,f)==1)
	{
	 if(strcmp(m.from,u.username)==0)
	  {
		if(i==ch)
		 {
		  flag=1;
		  break;
		 }
		 else
		  i++;
	  }
	 }
  if(flag==1)
	 {
	  printf("\n\n\n\n    \n");
	  printf("To:");puts(m.to);printf("\n\n        ");puts(m.mail);
	  fclose(f);
	  outbox();
	 }
	else
	{
	 cout<<"\nInvalid choice";
	 loginp();
	}
  fclose(f);
}

void menu()
 {
	 int ch;
	 printf("\n\n\n\n                 _______________SSTM MAIL______________");
	 printf("\n\n        1.SIGNIN\n        2.SIGNUP\n        3.EXIT\n\n\n        Enter your choice:");
	 scanf("%d",&ch);
	 switch(ch)
	{
		case 1:
		 signin();
		 break;
		case 2:
		 signup();
		 break;
		case 3:
		 exit(0);
		default:
		 printf("\nInvalid choice\n");
		 menu();
	}
 }

void main()
 {
  menu();
 }