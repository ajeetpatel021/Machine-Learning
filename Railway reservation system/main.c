#include <stdio.h>
#include <stdlib.h>
#include"rlyres.h"
#include"conio2.h"

int main()
{
    int choice;
    int ti;


    passenger* ptr;


add_trains();
    while(1)
    {
        choice=enterchoice();
        if(choice==9)
            exit(0);
        switch(choice)
        {

        case 1:
            {
clrscr();
             view_train();
             break;
             }

        case 2:
             {
                clrscr();
                 ptr=get_passenger_details();
                if(ptr!=NULL)
                {
                     ti=book_ticket(*ptr);
                 if(ti==-1)
                    printf("Booking Failed");
                    break;
                }

break;
}

        case 3:
            {
                clrscr();

                 ti=accept_ticket_no();
                  if(ti!=0)
                  {
                      view_ticket(ti);

                  }

break;

            }

        case 4:
            {

clrscr();
                 char* mob_no=accept_mobile_no();
                 if(mob_no==NULL)
                    break;

              int *ti_no=get_ticket_no(mob_no);
              if(ti_no==NULL)
                break;
              printf("\nYOUR TICKET NO IS:%d",*ti_no);
              getch();
              break;


            }



        case 5:
            {


            clrscr();
            view_all_booking();
            break;
            }
        case 6:
            {  clrscr();
             char* train_no=accept_train_no();
             view_train_bookings(train_no);

            break;
            }
        case 7:
            {  clrscr();

               ti=accept_ticket_no();
               int temp=cancel_ticket(ti);
               if(temp==1)
               {
                   printf("NO BOOKING HAS BEEN FOUND TO TICKET NO: %d",ti);
                   getch();
                   break;
               }
               else
                printf("\nTICKET HAS BEEN CANCELED SUCCESSFULLY");
                getch();
                break;



            }



        case 8:
            {
                clrscr();
              char *tr_no=accept_train_no();
           int check=cancel_train(tr_no);
           if(check==0)
            printf("\nNo train is found with this no %s",tr_no);
           else
            printf("\nTRAIN %s HAS BEEN CANCELED SUCCESSFULY",tr_no);
           getch();

            break;
            }

        default:
            textcolor(LIGHTRED);
            printf("wrong choice! please try again\n");
            getch();
            clrscr();
        }

    }


    return 0;
}
