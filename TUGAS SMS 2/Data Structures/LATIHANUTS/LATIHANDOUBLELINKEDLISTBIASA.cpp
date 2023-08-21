#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node{
	struct node *next,*prev;
	int data;
};

struct node*head=NULL;


void insertbegin(int data){
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	
	temp->data=data;

	if(head==NULL){	

	temp->prev=NULL;
	temp->next=NULL;
		head=temp;
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
		}
		else{
			struct node*ptr=(struct node*)malloc(sizeof(struct node));
			ptr=head;
			while(ptr->next!=NULL){
				ptr=ptr->next;
			}
			ptr->next=temp;
			temp->prev=ptr;
	
			temp->next=NULL;
			
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
	struct node*ptr=(struct node*)malloc(sizeof(struct node));
	ptr=head;
	struct node*pre=(struct node*)malloc(sizeof(struct node));
	while(ptr->next!=NULL){
		pre=ptr;
		ptr=ptr->next;
	}
	pre->next=NULL;
	free(ptr);
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
		head->prev=NULL;
		free(temp);
		
	}
	else{
		struct node*ptr=(struct node*)malloc(sizeof(struct node));
		ptr=head;
		struct node*pre=(struct node*)malloc(sizeof(struct node));
		
		while(ptr!=NULL){
			if(ptr->data==val){
				if(ptr->next!=NULL){
					pre->next=ptr->next;
					ptr->next->prev=pre;
					free(ptr);
				}
				else{
					pre->next=NULL;
					free(ptr);
				}
				return;
			}
			pre=ptr;
			ptr=ptr->next;
		}
		
	}
	
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
	display();//
	puts("");

deleteback();
display();
puts("");	

deletebebas(9);
display();
puts("");

	
	
	return 0;
}
