#include<stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<time.h>
#include <string.h>

typedef struct node
{

char name[50];
int id;
long long int phoneNo;
long int aadharcard;
char address[50];
char city[50];
char state[20];
struct node * next;
}NODE; // creating a node

NODE* createcustomer()
{
	char name[50];
	int id;
	long long int phoneNo;
	long int aadharcard;
	char address[50];
	char city[50];
	char state[20];


	printf("enter name:\n");
	scanf("%s",name);
	printf("enter phoneNo: \n");
	scanf("%lld", &phoneNo);
	printf("enter aadharcard: \n");
	scanf("%ld", &aadharcard);
	printf("enter address: \n");
	scanf("%s", address);
	printf("enter city: \n");
	scanf("%s", city);
	printf("enter state of the customer: \n");
	scanf("%s", state);

	NODE *newnode= malloc(sizeof(NODE));
	newnode->id = id;
	strcpy(newnode->name, name);
	newnode->phoneNo=phoneNo;
	newnode->aadharcard=aadharcard;
	strcpy(newnode->address,address);
	strcpy(newnode->city, city);
	strcpy(newnode->state, state);
	newnode->next=NULL;


	return newnode;
}
void insertcustomer(NODE **head)
{
	NODE *newnode=createcustomer();
	NODE *p=*head;


	if(*head==NULL)
		*head=newnode;
	else
	{
		while(p->next!=NULL)
			p=p->next;

		p->next=newnode;
	}

}
void display(NODE *head,long long int phoneNo)
{

	printf("\n enter customer phonenumber \n");
	scanf("%lld",&phoneNo);
	while(head!=NULL)
	{
		if(head->phoneNo!=phoneNo)
			printf("Phone number is not registered\n");

		else if(head->phoneNo==phoneNo)
		{

			printf("\n customer details \n");
			printf("\n name : %s",head->name);
			printf("\n phone number: %lld",head->phoneNo);
			printf("\n Aadharcard number: %ld", head->aadharcard);
			printf("\n address: %s %s %s",head->address,head->city, head->state);
			printf("\n-----------------------------------------------\n");

		}
		head=head->next;

	}


}

// delete customer

void deletecustomer(NODE **head,long long int phoneNo)
{

	NODE *p=*head,*q=*head;
	printf("\n enter customer phonenumber \n");
	scanf("%lld",&phoneNo);
	if(*head==NULL)
		printf("list is empty\n");
	else if (p->phoneNo==phoneNo)
	{
		*head = p->next;
		free(p);
		p = NULL;
	}
	else {
		while(p->phoneNo !=phoneNo)
		{
			q=p;
			p=p->next;
		}
		q->next=p->next;
		free(q);
		q=NULL;
	}
}



float generate_bill(NODE **head,long long int phoneNo,int unit,char usage[])
{

	NODE *p=*head;
    printf("enter the customer phone number\n");
    scanf("%lld",&phoneNo);
	if(p->phoneNo==phoneNo)
	{
		printf("industrial/domestic?\n");
		scanf("%s",usage);
		printf("enter the no of units used\n");
		scanf("%d",&unit);
		printf("tax is 9 percent  of the total bill\n");
		if(usage=="domestic")
		{
			for(int unit=0;unit<50;)
			{
				float price;
				price =unit*4.15;
				price=price+(price*0.09);
				printf("tax is:%f\n",0.09*price);
				return price;

			}
			for(int unit=50;unit<100;){
				float price;
				price =unit*5.60;
				price=price+(price*0.09);
				printf("tax is:%f\n",0.09*price);
				return price;

			}
			for(int unit=100;unit<200;)
			{
				float price;
				price =unit*7.15;
				price=price+(price*0.09);
				printf("tax is:%f\n",0.09*price);
				return price;

			}
			for(unit>200;;)
			{
				float price;
				price =unit*8.20;
				price=price+(price*0.09);
				printf("tax is:%f\n",0.09*price);
				return price;

			}
		}
		else
		{
			float price;
			price =unit*6.30;
			price=price+(price*0.9);
			printf("tax is:%f\n",0.09*price);
			return price;

		}
	}
	p=p->next;

}
void pauseCustomer(NODE **head,int m,long long int phoneNo)
{

	NODE *p=*head;
	time_t t = time(NULL);
	float price;

    struct tm tm = *localtime(&t);
    //printf("date: %d-%02d-%02d \n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
	printf("enter the customer phone number\n");
    scanf("%lld",&phoneNo);
	if(p->phoneNo==phoneNo)
	{

		printf("enter number months subcription to be paused\n");
		scanf("%d",&m);

		if(m<=12)
		{
			if(tm.tm_mon+1+(m)>12)
			{
			price=(m)*3.75;
			printf("date subscription will be resumed : %d-%02d-%02d \n", tm.tm_year + 1900+1, tm.tm_mon + 1+(m)-12, tm.tm_mday);
			printf("amount paused %f\n",price);
			}
			else
			{
			price=(m)*3.75;
			printf("date subscription will be resumed : %d-%02d-%02d \n", tm.tm_year + 1900, tm.tm_mon + 1+(m), tm.tm_mday);
			printf("amount when paused %f\n",price);
			}
		}
		printf("subscription can not be paused for more than tweleve months\n");
	}
	p=p->next;
}

int main ()
{
    int choice , n , i ,m;
    long long int phoneNo;
	int unit;
	float price;
    char usage[20];
    NODE *head;

     printf("          MENU          \n");
    printf("\n 1.create a new customer");
    printf("\n 2.display existing list");
    printf("\n 3.delete customer");
    printf("\n 4.generate bill");
	printf("\n 5.pause subscription");
    printf("\n 6.exit\n");
    scanf("%d",&choice);

    do{


        switch(choice)
        {
            case 1:insertcustomer(&head);//if you are passing the address of a pointer as the argument, then paramter should be a double pointer
                   break;

            case 2:display(head,phoneNo);
                   break;

            case 3:deletecustomer(&head, phoneNo);
				   break;


            case 4:price=generate_bill(&head,phoneNo,unit,usage);
				   printf("the cost of the electricity this month:%f",price);
                   break;

            case 5:pauseCustomer(&head,m,phoneNo);//NODE **head,int m,long long int phoneNo
				   break;
            case 6:exit(0);
            default:
            printf("wrong choice\n");


        }

    printf("          MENU          \n");
    printf("\n 1.create a new customer");
    printf("\n 2.display existing list");
    printf("\n 3.delete customer");
    printf("\n 4.generate bill");
	printf("\n 5.pause subscription");
    printf("\n 6.exit\n");
    scanf("%d",&choice);
    }
	while(choice<7);


    return 0;
}
