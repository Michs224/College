#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node{
	char custname[100];
	char dressname[100];
	int price;
	struct node*next;
	
};
struct node*front=NULL;
struct node*rear=NULL;	



void menu(){
	puts("BLUE DRESS SHOP CASHIER QUEUE");
	puts("#############################\n");
	printf("1. View Queue\n2. Add Customer to Queue\n3. Serve Customer\n4. Check Next Queue\n5. Check Antrian Full atau tidak\n6. Exit\n>> Input choice : ");
	
}
void view(){
	struct node*ptr=(struct node*)malloc(sizeof(struct node));
	ptr=front;
	 if(ptr==NULL){
	 	puts("Queue is Empty");
	 	return;
	 }
	 printf("\t\t--- QUEUE VIEW ---\n");
	 printf("-------+--------------------------+------------------------+--------\n");
	 printf("| No.  | Customer's Name          | Dress Name             | Price |\n");
	 printf("-------+--------------------------+------------------------+--------\n");
	 int i=0;
	 while(ptr!=NULL){
	 	 printf("| %3d  | %15s                     | %15s                   | %d    |\n",++i,ptr->custname,ptr->dressname,ptr->price);
		ptr=ptr->next;
	 }
}

void insert(char name[], char dress[], int harga){
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	strcpy(temp->custname,name);
	strcpy(temp->dressname,dress);
	temp->price=harga;
	temp->next=NULL;
	if(front==NULL){
		front=temp;
		rear=temp;
		front->next=NULL;
		rear->next=NULL;
	}
	else{
		rear->next=temp;
		rear=rear->next;
		rear->next=NULL;
	}
	
	
}

int isFull(){
	struct node*ptr=front;
	int count=0;
	while(ptr!=NULL){
		count++;
		ptr=ptr->next;
	}
	return count;
}

void addcust(){
	char name[100],dress[100];
	int pricee;
	int n;
	int count=0,valid;
	
	do{
		valid=0;
		printf("Input Customer's Name [3..20][must be in alphabets]: ");
		scanf(" %[^\n]",name);
		n=strlen(name);
		for(int i=0;i<n;i++){
			if(isalpha(name[i]) || isspace(name[i]))count++;
		}
		if(count==n)valid++;
		
		if(n>=3 && n<=20)valid++;
	}while(valid!=2);
	
	do{
		printf("Input Dress Name [3..20]: ");scanf("%[^\n]",dress);
	}while(strlen(dress)<3 || strlen(dress)>20);
	
	do{
		printf("Input Dress Price [$$50..$$999]: $$");scanf("%d",&pricee);
	}while(pricee <50 && pricee >999);
	
	int x=isFull();
	if(x==10){
	puts("--- Maximum Customer in a Queue is 10 ---");
	return;
	}
	insert(name,dress,pricee);	
	printf("--- Success to Add Customer into Queue List ---\n");
}

void servecust(){
	struct node*temp=front;
	if(front==NULL){
		puts("--- There is No Customer in Queue ---");
		return;
	}
	front=front->next;
	printf("--- %s Has Been Served ---\n",temp->custname);
	
}
void checkcust(){
	struct node*temp=front;
	if(front==NULL){
		puts("--- There is No Customer in Queue ---");
		return;
	}
	printf("--- Antrian berikutnya adalah %s, %s, %s\n",temp->custname,temp->dressname,temp->price);
	
}



int main(){
//	char x='7';
//	if(isalpha(x))puts("yeyee\n");
//	system("pause");
	int choose;
	do{
	system("cls");
	menu();
	scanf("%d",&choose);
			switch(choose){
				case 1:{
					view();
					system("pause");
					break;
				}
				case 2:{
					addcust();
					system("pause");
					break;
				}
				case 3:{
					servecust();
					system("pause");
					break;
				}
				case 4:{
					checkcust();
					system("pause");
					break;
				}
				case 5:{
					int x=isFull();
					if(x==10){
						printf("The Queue is FULL right now\n");
					}
					else{
						printf("The Queue slot exist: %d\n",10-x);
					}
					break;
				}				
			};
	
		
	}while(choose!=6);
	
	puts("Exit..\n");
	
	return 0;
}
