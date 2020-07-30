#ifndef RLYRES_H_INCLUDED
#define RLYRES_H_INCLUDED
struct train
{
    char train_no[10];
    char from[10];
    char to[10];
    int fac_fare;
    int sac_fare;
}; typedef struct train train;
struct passenger
{
    char p_name[20];
    char gender;
    char train_no[10];
    int age;
    char mob_no[12];
    char p_class;
    int ticketno;
    char address[20];

};
typedef struct passenger passenger;
int enterchoice();
void add_trains();
void view_train();
int book_ticket(struct passenger);
int* get_ticket_no(char*);
void view_ticket(int);
void view_all_booking();
void view_booking(char*);
int canel_ticket(int);
int cancel_train(char*);
int check_train_no(char*);
passenger* get_passenger_details();
int get_booked_ticket_count(char*,char);
int last_ticket_no();
int check_mob_no(char*);
char* accept_train_no();
int accept_ticket_no();
int search_ticket_no(char*);
char* accept_mobile_no();
void view_train_bookings(char*);


#endif // RLYRES_H_INCLUDED
