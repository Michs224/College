#include <stdio.h>
#include <stdlib.h>


struct node{
	int data;
	struct node*next;
};

//struct queue{
	struct node*front;
	struct node*rear;
//};
//queue*q;

void createQueue(struct node*front,struct node*rear){
	front=NULL;
	rear=NULL;
}

struct node*insert(struct node*front,int val){
	struct node*ptr=(struct node*)malloc(sizeof(struct node));
	
	ptr->data=val;
	if(front==NULL){
		front=ptr;
		rear=ptr;
		front->next=NULL;
		rear->next=front;
//		front->next=rear->next=NULL;
	}
	else{
		rear->next=ptr;
		rear=ptr;
		rear->next=front;
		
	}
	return front;
	
	
}
struct node*deletee(struct node*q){
	struct node*ptr;
	ptr=front;
	if(front==NULL){
		printf("Queue is Empty\n");
	}
	else{
		front=front->next;
		printf("Antrian yang dipanggil/dihapus: %d\n",ptr->data);
		free(ptr);
	}
	return front;
	
	
}
int peek(struct node*q){
	if(front==NULL){
		printf("Queue is Empty\n");
		return -1;
	}
	else return front->data;
}

struct node*display(struct node*q){
	struct node*ptr;
	ptr=front;
	if(ptr==NULL){
		printf("Queue is Empty\n");
		return front;
	}
	
	do{	
	printf("%d ",ptr->data);
		ptr=ptr->next;
	}while(ptr!=front);
//	while(ptr!=rear){
//
//	}
//	printf("%d \n",ptr->data);
	return front;
}

int main(){
	node*q=(struct node*)malloc(sizeof(struct node));
	int x;
	createQueue(front,rear);
	do{
		printf("Menu:\n1. INSERT\n2. DELETE\n3. PEEK/TOP\n4. DISPLAY\n5. EXIT\n");
		printf("Pilih apa Anda??: "); scanf("%d",&x);
		switch(x){
			case 1:{
				int val;
				printf("Masukkan Datanya: "); scanf("%d",&val);
				front=insert(front,val);
				system("cls");
				break;
				
			}
				
			
			case 2:{
				q=deletee(q);
				break;
			}
				
				
			case 3:{
				int peekk=peek(front);
				if (peekk== -1){
					printf("Queue is empty\n");
				}
				else{
					printf("Antrian yang bakalan dipanggil/atau bagian teratas: %d\n",peekk);
				}
				break;
			}
			
			
				
			case 4:{
				q=display(q);
				break;
				
			}
			
				
			default:
				break;
				
		}
			
	}while(x!=5);
	printf("Exit...\n");
	
	
	
return 0;
}
