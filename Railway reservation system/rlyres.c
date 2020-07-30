#include<stdio.h>
#include"conio2.h"
#include"rlyres.h"
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<ctype.h>


int enterchoice()
{
    int choice,i;
    clrscr();
    textcolor(YELLOW);
    gotoxy(40,2);
    printf("RAILWAY RESERVATION SYSTEM\n");
    for(i=0;i<=80;i++)
        printf(" _");


    printf("\n\t\tSELECT AN OPTION\n");
    printf("\t\t1-VIEW TRAINS\n\t\t2-BOOK TICKET\n\t\t3-VIEW TICKET\n\t\t4-SEARCH TICKET NO\n\t\t5-VIEW ALL BOOKINGS\n\t\t6-VIEW TRAIN BOOKINGS\n\t\t7-CANCEL TICKET\n\t\t8-CANCEL TRAIN\n\t\t9-Quite");
    printf("\nENTER YOUR CHOICE:");
    scanf("%d",&choice);
    return choice;
}
void add_trains()
{

    FILE *fp=fopen("d:\\myproject\\alltrains.dat","rb");
    gotoxy(10,24);
    textcolor(DARKGRAY);
    if(fp==NULL)
    {
        train alltrains[4]={
    {"123","BPL","GWA",2100,1500},
    {"456","BPL","DEL",1560,1135},
    {"345","HBJ","AGR",4500,3360},
    {"555","HBJ","PPI",6000,5500}};

      fp=fopen("d:\\myproject\\database\\alltrains.dat","wb");
      fwrite(alltrains,4*sizeof(train),1,fp);
      fclose(fp);
      }
      else
      {
          fclose(fp);
      }
}
void view_train()
{

    int i;

clrscr();
   textcolor(YELLOW);

    gotoxy(10,2);
    printf("\t\tTRAIN NO\tFROM\t\tTO\t\tFIRTS AC FAIR\t\tSECOND AC FAIR\n");
for(i=0;i<80;i++)
        printf(" _");
        printf("\n");
        FILE *fp=fopen("d:\\myproject\\database\\alltrains.dat","rb");
        if(fp==NULL)
        {
            printf("file not present in the directory");
            exit(1);
        }

        train trains;


            while(fread(&trains,sizeof(train),1,fp)==1)
            {   delay(50);
                printf("\n\t\t\t%s\t\t%s\t\t%s \t\t%d \t\t\t%d\n\n",trains.train_no,trains.from,trains.to,trains.fac_fare,trains.sac_fare);

            }
             textcolor(DARKGRAY);
             gotoxy(2,22);
            printf("press any KEY to go to the main menu\n");
            fclose(fp);
            getch();
}
int check_train_no(char* p)
{
   FILE* fp=fopen("d:\\myproject\\database\\alltrains.dat","rb");
   train tr;
   while(fread(&tr,sizeof(train),1,fp)==1)
   {
       if(strcmp(tr.train_no,p)==0)
       {
           fclose(fp);
           return 1;

       }



}
fclose(fp);
      return 0;

}


 passenger* get_passenger_details()
    {
        clrscr();
        gotoxy(69,1);
        textcolor(LIGHTGREEN);
        printf("PRESS 0 TO EXIT");
        gotoxy(1,1);
        textcolor(YELLOW);
        static passenger psn;


        //accepting name
        printf("Enter Passenger name:");
        fflush(stdin);
        fgets(psn.p_name,20,stdin);
        char* pos;
        pos=strchr(psn.p_name,'\n');
        *pos='\0';
        if(strcmp(psn.p_name,"0")==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
                printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Reservation Cancelled!");
            getch();
            textcolor(YELLOW);
            return NULL;
        }


        //accepting gender
            int valid;
            printf("Enter gender(M/F):");
            do
            {
            valid=1;
            fflush(stdin);
            scanf("%c",&psn.gender);
            if(psn.gender=='0')
            {
                textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("\t\t\t\t\t\t\t");
                gotoxy(1,25);
                printf("Reservation Cancelled!");
                getch();
                textcolor(YELLOW);
                return NULL;
            }
            if(psn.gender!='M' && psn.gender!='F')
            {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Error! Gender should be M or F (in uppercase)");
            valid=0;
            getch();
            gotoxy(19,2);
            printf(" \b");
            textcolor(YELLOW);
            }
            }while(valid==0);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,3);

            //acceptingtrain no and train no cheking
            printf("Enter train no:\n");
            gotoxy(16,3);
            fflush(stdin);

            do{
                    gets(psn.train_no);

            if(strcmp(psn.train_no,"0")==0)
            {
                textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("\t\t\t\t\t\t\t");
                gotoxy(1,25);
                printf("Reservation Cancelled!");
                getch();
                textcolor(YELLOW);
                return NULL;
            }
            valid=check_train_no(psn.train_no);

             if(valid==0)
               {

                gotoxy(1,25);
                textcolor(LIGHTRED);
             printf("Invalid Train No! Please Enter a Valid Train No!!");
               textcolor(YELLOW);
               gotoxy(16,3);
               printf("      \b\b\b\b\b\b");
               }
    }while(valid==0);
    gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,4);

              //travelling class

                printf("Enter your travelling class(F/S):");

               do{
                    valid=1;
               scanf("%c",&psn.p_class);
                 if(psn.p_class=='0')
            {
                 textcolor(LIGHTRED);
                 gotoxy(1,25);
                printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Reservation Cancelled!");
            getch();
            textcolor(YELLOW);
            return NULL;
            }
            if(psn.p_class!='F' && psn.p_class!='S')
            {
                valid=0;
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Error! class should be F or S (in uppercase)");

            gotoxy(34,4);
            printf("   \b\b\b");
            textcolor(YELLOW);

            }}while(valid==0);
             gotoxy(1,25);
                printf("\t\t\t\t\t\t\t");

            textcolor(YELLOW);
                gotoxy(1,5);


             printf("Enter Mobile No:");
             fflush(stdin);


         do{
            fgets(psn.mob_no,12,stdin);
            pos=strchr(psn.mob_no,'\n');
            if(pos!=NULL)
             *pos='\0';

            if(strcmp(psn.mob_no,"0")==0)
            {
                 textcolor(LIGHTRED);
                 gotoxy(1,25);
                printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Reservation Cancelled!");
            getch();
            textcolor(YELLOW);
            return NULL;
            }
            valid=check_mob_no(psn.mob_no);
            if(valid==0)
            {
                textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("invalid mobile no! it should be 10 digits and does not contain alphnumeric digits");
                gotoxy(17,5);
                printf("          \b\b\b\b\b\b\b\b\b\b");
                textcolor(YELLOW);
                }
               /* if(valid==-1)
                {
                    textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("This mobile number is already takken...!!\nPLEASE ENTER ANOTHER NUMBER");
                gotoxy(17,5);
                printf("          \b\b\b\b\b\b\b\b\b\b");
                textcolor(YELLOW);
                }*/


                }while(valid==0||valid==-1);
gotoxy(1,25);
printf("\t\t\t\t\t\t");
gotoxy(1,6);
                //address
                printf("Enter address:");
            fflush(stdin);
            fgets(psn.address,20,stdin);
            pos=strchr(psn.address,'\n');
            *pos='\0';
            if(strcmp(psn.address,"0")==0)
            {
                textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("\t\t\t\t\t\t\t");
                gotoxy(1,25);
                printf("Reservation Cancelled!");
                getch();
                textcolor(YELLOW);
                return NULL;
            }
            gotoxy(1,7);
            fflush(stdin);

            printf("Enter your age:");
            do{
                    valid=1;
                    scanf("%d",&psn.age);
             if(psn.age==0)
            {
                textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("\t\t\t\t\t\t\t");
                gotoxy(1,25);
                printf("Reservation Cancelled!");
                getch();
                textcolor(YELLOW);
                return NULL;
            }
            if(psn.age<0)
            {valid=0;
                gotoxy(1,25);
                textcolor(LIGHTRED);
                printf("invalid Age!! age should be positive");
                gotoxy(16,7);
                printf("       \b\b\b\b\b\b\b");
                textcolor(YELLOW);
            }
}while(valid==0);

                return &psn;
    }



int check_mob_no(char* p_mob)
{
if(strlen(p_mob)!=10)
   return 0;
   while(*p_mob!='\0')
   {
       if(isdigit(*p_mob)==0)
        return 0;
   p_mob++;
   }
 /*  FILE* fp=fopen("d:\\myproject\\database\\allbookings.dat","rb+");
   passenger pr;

   while(fread(&pr,sizeof(pr),1,fp)==1)
   {
       if(strcmp(p_mob,pr.mob_no)==0)
       { fclose(fp);
        return -1;
       }


   }

   fclose(fp);*/
   return 1;

}
int get_booked_ticket_count(char* train_no,char tc)
{

    FILE *fp=fopen("d:\\myproject\\database\\allbookings.dat","rb");
    if(fp==NULL)
        return 0;
    passenger pr;
    int count=0;
    while(fread(&pr,sizeof(passenger),1,fp)==1)
    {
        if(strcmp(train_no,pr.train_no)==0&&tc==pr.p_class)
            count++;
    }
    fclose(fp);
    return count;


}
int last_ticket_no()
{

    FILE* fp=fopen("d:\\myproject\\database\\allbookings.dat","rb");
    if(fp==NULL)
        return 0;
    passenger pr;
    fseek(fp,-1*sizeof(pr),SEEK_END);
    fread(&pr,sizeof(pr),1,fp);
    fclose(fp);
    return pr.ticketno;

}
int book_ticket(passenger pr)
{
    int count;
    int tc_no,i;

    count=get_booked_ticket_count(pr.train_no,pr.p_class);
    if(count==3)
    {textcolor(WHITE);
        printf("ALL SEATS ARE FULL IN TRAIN NO-%s IN class-%c\npress any key to go to main menu.",pr.train_no,pr.p_class);
        getch();
        return -1;
    }

        tc_no=last_ticket_no()+1;
        pr.ticketno=tc_no;

        FILE* fp=fopen("d:\\myproject\\database\\allbookings.dat","ab");
        if(fp==NULL)
        {

        textcolor(LIGHTRED);
            printf("File can not be opened");
            return -1;
 }
        fwrite(&pr,sizeof(pr),1,fp);
        clrscr();

          textcolor(YELLOW);

    gotoxy(1,1);
    printf("\t\tTRAIN NO\tCLASS\t\tpassenger Name\t\tMOBILE NO\t\tADDRESS\n");
for(i=0;i<80;i++)
        printf(" _");
        printf("\n");
    printf("\n\t\t%s\t\t%c\t\t%s\t\t %s\t\t%s\n\n",pr.train_no,pr.p_class,pr.p_name,pr.mob_no,pr.address);
    textcolor(WHITE);
     printf("ticket booked successfully\nTicket no:%d",pr.ticketno);
     printf("\npress any key to go to main menu");
     getch();


        fclose(fp);

 return tc_no;
}
void view_ticket(int ti)
{
    clrscr();
     passenger pr;
      int i,found=1;
   FILE *fp=fopen("d:\\myproject\\database\\allbookings.dat","rb");
   if(fp==NULL)
   {printf("\nNO BOOKINGS DONE YET");
   getch();
   exit(1);
   }




   while(fread(&pr,sizeof(pr),1,fp)==1)
   {
       if(ti==pr.ticketno)
       {

           found=0;
           textcolor(YELLOW);

    gotoxy(1,1);
    printf("\tTRAIN NO\tCLASS\t\tpassenger Name\t\tMOBILE NO\t\tADDRESS\t\t\tTICKET NO\n");
for(i=0;i<80;i++)
        printf(" _");
        printf("\n");
    printf("\n\t%s\t\t%c\t\t%s\t\t %s\t\t%s\t\t%d\n\n",pr.train_no,pr.p_class,pr.p_name,pr.mob_no,pr.address,pr.ticketno);
    textcolor(WHITE);
    printf("\nPRESS ANY KEY TO GO TO MAIN MENU");
    getch();


       }


   }
   if(found==1)

   {
           textcolor(LIGHTRED);
           gotoxy(1,25);
        printf("INVALID TICKET NUMBER PLEASE CHECK");
        textcolor(WHITE);
        printf("\npress any key to go to main menu");
        getch();
       }
     fclose(fp);
     }


   //accept train no
   int accept_ticket_no()
   {
   int ticket_no;
   int found=0;
   gotoxy(60,1);
   textcolor(GREEN);
   printf("PRESS 0 TO CANCEL");
   textcolor(YELLOW);
   gotoxy(1,1);

        printf("ENTER TICKET NO:");
        while(found==0)
        {
           found=1;

        scanf("%d",&ticket_no);
        if(ticket_no==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("process has been canceled");
            exit(0);


        }
        if(ticket_no<0)
        { found=0;
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("TICKET NUMBER SHOULD BE POSITIVE");
               gotoxy(17,1);
        printf("   \b\b\b");
        textcolor(YELLOW);

        }

        }
        return ticket_no;


   }
//ticket cancel
int cancel_ticket(int ticket_no)
{

    passenger p;
    int found=1;
    FILE* fp1=fopen("d:\\myproject\\database\\allbookings.dat","rb");
    {
        if(fp1==NULL)
        {

            textcolor(LIGHTRED);
            printf("no bookings done yet\n");

            return -1;
        }
    }
    FILE* fp2=fopen("d:\\myproject\\database\\temp.dat","wb+");
    while(fread(&p,sizeof(passenger),1,fp1)==1)
    {
        if(ticket_no!=p.ticketno)
        {

            fwrite(&p,sizeof(passenger),1,fp2);


        }
        else
            found=0;

    }
    fclose(fp1);
    fclose(fp2);
    if(found==1)
        remove("d:\\myproject\\database\\temp.dat");
    else
    {

        remove("d:\\myproject\\database\\allbookings.dat");
        rename("d:\\myproject\\database\\temp.dat","d:\\myproject\\database\\allbookings.dat");

    }
    fclose(fp1);
    fclose(fp2);
    return found;
}
int* get_ticket_no(char* mob)
{
     static passenger p;
     int found=0;
    FILE*fp=fopen("d:\\myproject\\database\\allbookings.dat","rb+");
    if(fp==NULL)
    {
        printf("no bookings done yet");
        exit(1);
    }

    while(fread(&p,sizeof(p),1,fp)==1)
    {

        if(strcmp(mob,p.mob_no)==0)
        { found=1;
        fclose(fp);
            return &p.ticketno;
        }



    }
    if(found==0)
    {

    textcolor(LIGHTRED);
    gotoxy(1,25);
    printf("ticket with this number is not found");
    getch();
    fclose(fp);
    return NULL;

    }
    fclose(fp);
    return &p.ticketno;

}

char* accept_mobile_no()
{  static char mob_no[12];
    int valid;
    char *pos;
     gotoxy(60,1);
   textcolor(GREEN);
   printf("PRESS 0 TO CANCEL");
   textcolor(YELLOW);
   gotoxy(1,1);



       printf("Enter your Mobile No:");
             fflush(stdin);


         do{
            fgets(mob_no,12,stdin);
            pos=strchr(mob_no,'\n');
            if(pos!=NULL)
             *pos='\0';

            if(strcmp(mob_no,"0")==0)
            {
                 textcolor(LIGHTRED);
                 gotoxy(1,25);
                printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Cancelled!");
            getch();
            textcolor(YELLOW);
            return NULL;
            }
            valid=check_mob_no(mob_no);
            if(valid==0)
            {
                textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("invalid mobile no! it should be 10 digits");
                gotoxy(22,1);
                printf("          \b\b\b\b\b\b\b\b\b\b");
                textcolor(YELLOW);
                }}while(valid==0);
                return mob_no;



}


void view_all_booking()
{
    passenger pr;
    int i;
    FILE*fp=fopen("d:\\myproject\\database\\allbookings.dat","rb+");
      gotoxy(1,1);
    printf("\tTRAIN NO\tCLASS\t\tpassenger Name\t\tMOBILE NO\t\tADDRESS\t\tTICKET NO\n");
for(i=0;i<80;i++)
        printf(" _");
        printf("\n");
    while(fread(&pr,sizeof(pr),1,fp)==1)
   {

           textcolor(YELLOW);


    printf("\n\t%s\t\t%c\t\t%s\t\t %s\t\t%s\t\t%d\n\n",pr.train_no,pr.p_class,pr.p_name,pr.mob_no,pr.address,pr.ticketno);

   } textcolor(WHITE);
    printf("\nPRESS ANY KEY TO GO TO MAIN MENU");
    fclose(fp);
    getch();
}
char* accept_train_no()
{
    int valid=1;
    static char pr[10];
    printf("Enter train no:\n");

            gotoxy(16,1);
            fflush(stdin);

            do{
                    gets(pr);

            if(strcmp(pr,"0")==0)
            {
                textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("\t\t\t\t\t\t\t");
                gotoxy(1,25);
                printf("Cancelled!");
                getch();
                textcolor(YELLOW);
                exit(0);
            }
            valid=check_train_no(pr);

             if(valid==0)
               {

                gotoxy(1,25);
                textcolor(LIGHTRED);
             printf("Invalid Train No! Please Enter a Valid Train No!!");
               textcolor(YELLOW);
               gotoxy(16,1);
               printf("      \b\b\b\b\b\b");
               }
    }while(valid==0);

    return pr;


}

void view_train_bookings(char *tr_no)
{
    FILE*fp=fopen("d:\\myproject\\database\\allbookings.dat","rb+");
   int i;
   int found=0;
   passenger pr;
      gotoxy(1,1);
    printf("\tTRAIN NO\tCLASS\t\tpassenger Name\t\tMOBILE NO\t\tADDRESS\t\tTICKET NO\n");
for(i=0;i<80;i++)
        printf(" _");
        printf("\n");
    while(fread(&pr,sizeof(pr),1,fp)==1)
   {


       if(strcmp(tr_no,pr.train_no)==0)
       {   found=1;
           textcolor(YELLOW);
    printf("\n\t%s\t\t%c\t\t%s\t\t %s\t\t%s\t\t%d\n\n",pr.train_no,pr.p_class,pr.p_name,pr.mob_no,pr.address,pr.ticketno);

   }

   }

     if(found==0)
            printf("NO BOOKINGS FOUND IN THIS TRAIN");
     textcolor(WHITE);

    printf("\nPRESS ANY KEY TO GO TO MAIN MENU");
    fclose(fp);
    getch();


}

int cancel_train(char *tr_no)
{

    train tr;
    passenger pr;
     int found=0;
     int found1=1;

    FILE* fp1=fopen("d:\\myproject\\database\\alltrains.dat","rb+");
    if(fp1==NULL)
    {
        printf("no bookings done yet..");
        return -1;

    }
    FILE* fp2=fopen("d:\\myproject\\database\\temp.dat","wb+");
   FILE* fp3=fopen("d:\\myproject\\database\\allbookings.dat","rb+");
   FILE* fp4=fopen("d:\\myproject\\database\\temp1.dat","wb+");


    while(fread(&tr,sizeof(tr),1,fp1)==1)
    {

        if(strcmp(tr_no,tr.train_no)!=0)
        {
            fwrite(&tr,sizeof(tr),1,fp2);

        }
        else
        {
            found=1;

        }


    }
    while(fread(&pr,sizeof(pr),1,fp3)==1)
    {

        if(strcmp(tr_no,pr.train_no)!=0)
        {

            fwrite(&pr,sizeof(pr),1,fp4);

        }
        else
        {
            found1=1;
        }



    }



    fclose(fp1);
        fclose(fp2);
    fclose(fp3);
     fclose(fp4);


    if(found==0)
    {
        remove("d:\\myproject\\database\\temp.dat");

    }
    else
    {
        remove("d:\\myproject\\database\\alltrains.dat");
        rename("d:\\myproject\\database\\temp.dat","d:\\myproject\\database\\alltrains.dat");
    }

    //ticket cancelling
    if(found1==0)
        remove("d:\\myproject\\database\\temp1.dat");
    else
    {
        remove("d:\\myproject\\database\\allbookings.dat");
        rename("d:\\myproject\\database\\temp1.dat","d:\\myproject\\database\\allbookings.dat");
    }



        return found;





}







