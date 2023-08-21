#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct queue{
	char memberships[30],names[30];
	int prior;
	struct queue*next;
};
queue*front=NULL;
//queue*rear=NULL;

void display(){
		struct queue*temp=front;
		puts("============================");
		puts("SUNIB Restaurant Reservation");
		puts("============================\n");
		
		puts("Waiting Line: ");
		if(front==NULL){
			puts("Queue is empty\n");
		}
		else{
		int i=0;
		while(temp!=NULL){
			printf("%d. %s\n",++i,temp->names);
			temp=temp->next;
		}
		puts("");			
		}

		
		printf("1. Add Customer to Queue\n2. Serve One\n3. Serve All\n4. Dismiss Queue\n0. Exit\n");
}

int prior(char member[30]){
//	char membership[][100]={
//							"VVIP",
//							"VIP",
//							"Member",
//							"Guest"
//				
//	}
	
	if(strcmp(member,"VVIP")==0)return 1;
	else if(strcmp(member,"VIP")==0)return 2;
	else if(strcmp(member,"Member")==0)return 3;
	else if(strcmp(member,"Guest")==0)return 4;
}

void insert(){
	char member[30],name[30];
	struct queue*temp=(struct queue*)malloc(sizeof(struct queue));
	printf("Membership and Name: ");
	
	scanf("%s %[^\n]",member,name);
	printf("%s %s\n",member,name);
	system("pause");
//	fflush(stdin);
	strcpy(temp->memberships,member);
	strcpy(temp->names,name);
	
	int p=prior(member);
	printf("%d\n",p);
	system("pause");
	temp->prior=p;
	
	temp->next=NULL;
	
	
	if(front==NULL){
		front=temp;
//		rear=temp;
//		front->next=NULL;
//		rear->next=NULL;
	}
	else if(p<front->prior){
		temp->next=front;
		front=temp;
	}
	else {
		struct queue*pre=(struct queue*)malloc(sizeof(struct queue));
		struct queue*ptr=(struct queue*)malloc(sizeof(struct queue));
		ptr=front;
		while(ptr->next!=NULL && p>=ptr->next->prior){
			ptr=ptr->next;
		}
		if(ptr->next==NULL){
			ptr->next=temp;
		}
		else{
		temp->next=ptr->next;
		ptr->next=temp;
			
		}
		
	}
	
	
}

void serveone(){
	struct queue*temp=(struct queue*)malloc(sizeof(struct queue));
	temp=front;
	
	if(front==NULL){
		puts("Queue is empty");
		return;
	}
	
	front=front->next;
	if(temp->prior==1){
		printf("Attention! %s is being served at VVIP table\n",temp->names);
	}
	else if(temp->prior==2){
		printf("Attention! %s is being served at the VIP table\n",temp->names);
	}
	else if(temp->prior==3){
		printf("Attention! Member %s is being served at regular table\n",temp->names);
	}
	else if(temp->prior==4){
		printf("Attention! Guest %s is being served at a regular table\n",temp->names);
	}
	free(temp);
	
	
}

void serveall(){
	struct queue*temp=(struct queue*)malloc(sizeof(struct queue));
	
	if(front==NULL){
		puts("Queue is empty");
		return;
	}
	while(front!=NULL){
	temp=front;
	front=front->next;
	if(temp->prior==1){
		printf("Attention! %s is being served at VVIP table\n",temp->names);
	}
	else if(temp->prior==2){
		printf("Attention! %s is being served at the VIP table\n",temp->names);
	}
	else if(temp->prior==3){
		printf("Attention! Member %s is being served at regular table\n",temp->names);
	}
	else if(temp->prior==4){
		printf("Attention! Guest %s is being served at a regular table\n",temp->names);
	}
	free(temp);		
		
	}

	
	
}

void deleteall(){
	
	struct queue*temp=(struct queue*)malloc(sizeof(struct queue));
	
	
//	if(front==NULL){
//		puts("Queue is empty");
//		return;
//	}
	while(front!=NULL){
	temp=front;
	front=front->next;
	free(temp);
	}

	
}

int main(){

	int  choose;
	
	do{
//		system("cls");
		display();
		printf("Input Menu Number: ");scanf("%d",&choose);
		
		switch(choose){
			
			case 1:{
				insert();
				break;
			}
			
			case 2:{
				serveone();
				
				break;
			}
			case 3:{
				
				serveall();
				break;
			}
			case 4:{
				printf("End of the day!\n");
				serveall();
				break;
			}
		}
	
		
	}while(choose!=0);
	
	serveall();
	
	return 0;
}
