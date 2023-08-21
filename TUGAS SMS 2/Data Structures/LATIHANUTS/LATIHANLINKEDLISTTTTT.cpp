#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node{
	struct node *next;
	int data;
};

struct node*head=NULL;


void insertbegin(int data){
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	
	if(head==NULL){
		head=temp;
	}
	else{
		temp->next=head;
		head=temp;
	}
	
}

void insertback(int data){
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	
	temp->data=data;
	temp->next=NULL;
	
	if(head==NULL){
		head=temp;
	}
	else{
		struct node*ptr=(struct node*)malloc(sizeof(struct node));
		ptr=head;
		while(ptr->next!=NULL){
			
			ptr=ptr->next;
		}
		ptr->next=temp;
		
	}
	
}

void deletebegin(){
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	struct node*temp2=(struct node*)malloc(sizeof(struct node));
	if(head==NULL){
		puts("NULL");
	}
	else{
		
		temp=head;
		head=head->next;
		free(temp);
	
	}

	
}

void deleteback(){
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	if(head==NULL){
		puts("NULL");
		
	}
	
	else if(head->next==NULL){
		head=NULL;
		free(head);
	}
	
	else{
		struct node*ptr=(struct node*)malloc(sizeof(struct node));
		struct node*pre=(struct node*)malloc(sizeof(struct node));
		ptr=head;
		while(ptr->next!=NULL){
			pre=ptr;
			ptr=ptr->next;
		}
		pre->next=NULL;
	}
	
}

void deletebebas(int val){
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	
	if(head==NULL){
		puts("NULL");
		
	}
	else if(head->data==val){
	temp=head;
	head=head->next;
	free(temp);
	}
	else{
		struct node*ptr=(struct node*)malloc(sizeof(struct node));
		ptr=head;
		struct node*pre=(struct node*)malloc(sizeof(struct node));
		
		while(ptr!=NULL){
			if(ptr->data==val){
				pre->next=ptr->next;
				return;
			}
			pre=ptr;
			ptr=ptr->next;
		}
			
		puts("Data tidak ditemukan");
	}
	
}

void display(){
	struct node*temp=head;
	
//	temp=head;
//	
	if(head==NULL){
		puts("Linked List Empty");
		return;
	}
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	
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
	
	deletebebas(9);
	display();
	puts("");
	deleteback();
	display();
	
	return 0;
}
