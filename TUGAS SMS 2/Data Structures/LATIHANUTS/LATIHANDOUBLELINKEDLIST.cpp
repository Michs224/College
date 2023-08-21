#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node{
	struct node *next,*prev;
	int data;
};

struct node*head=NULL,*tail=NULL;


void insertbegin(int data){
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	
	temp->data=data;

	if(head==NULL){	

	temp->prev=NULL;
	temp->next=NULL;
		head=temp;
		tail=temp;
	}
	else{
		temp->prev=NULL;
		temp->next=head;
		head->prev=temp;
		head=temp;
		
	}
	
	
}

void insertback(int data){
		struct node*temp=(struct node*)malloc(sizeof(struct node));
		
		temp->data=data;
		
		if(head==NULL){
			temp->prev=NULL;
			temp->next=NULL;
			head=temp;
			tail=temp;
		}
		else{
			temp->next=NULL;
			temp->prev=tail;
			tail->next=temp;
			tail=temp;
		}
	
}

void deletebegin(){
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	
	if(head==NULL){
		puts("NULL");
		
	}
	else{
		temp=head;
		head=head->next;
		head->prev=NULL;
		free(temp);
	}
}

void deleteback(){
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	if(head==NULL){
		puts("NULL");
	}
	else{
		tail->prev->next=NULL;
	}
	
}

void deletebebas(int val){

	
}

void display(){
	struct node*temp=head;
	
	if(head==NULL){
		puts("Linked List Empty");
		return;
	}
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	
//	puts("");
//	struct node*temp1=tail;
//	
//	if(head==NULL){
//		puts("Linked List Empty");
//		return;
//	}
//	while(temp1!=NULL){
//		printf("%d ",temp1->data);
//		temp1=temp1->prev;
//	}
}

int main(){
	insertbegin(5);
	insertbegin(3);
	insertbegin(6);
	display();
	
	puts("");
	insertback(9);
	insertback(10);
	insertback(20);
	display();
	puts("");
	
	deletebegin();
	deletebegin();
	display();
	puts("");
	
	deleteback();
	display();
	puts("");

	
	
	return 0;
}
