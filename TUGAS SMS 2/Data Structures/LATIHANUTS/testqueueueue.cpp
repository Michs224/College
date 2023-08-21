#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


struct queue{
	int data;
	char ukuran[30];
	struct queue*next;
	
};

queue*front=NULL;
queue*rear=NULL;

bool checkukuran(char ukuran[30]){
	char check[][100]={"Besar","Sedang","Kecil"};
	int i=0;
	while(check[i][0]!=NULL){
		if(strcmp(ukuran,check[i])==0){
			return true;
		}
		i++;
	}
	return false;
	
	
}

void insertqueue(char ukurann[30],int angka){
	struct queue*temp=(struct queue*)malloc(sizeof(struct queue));
	
	strcpy(temp->ukuran,ukurann);
	temp->data=angka;
	
	temp->next=NULL;
	
	if(front==NULL){
		front=temp;
		rear=temp;
		front->next=NULL;
		rear->next=NULL;
	}
	else{
		rear->next=temp;
		rear=temp;
		rear->next=NULL;
	}
	
	printf("Insert Success\n");
	
}


void insert(){
	char ukurann[30];
	int angka;
	do{
		
	printf("Masukkan ukuran: ");getchar();
	scanf("%[^\n]",ukurann);	
		
	}while(!checkukuran(ukurann));
	
	printf("Masukkan angka: ");scanf("%d",&angka);

	insertqueue(ukurann,angka);
}


void display(){
	struct queue*temp=front;
	
	if(front==NULL){
		puts("Queue is Empty");
	}
	else{
		int i=1;
		while(temp!=NULL){
			printf("%d. %s %d\n",i++,temp->ukuran,temp->data);
			temp=temp->next;
		}
	}
	puts("");
	
}

void servequeue(){
	struct queue*temp=(struct queue*)malloc(sizeof(struct queue));
	
	temp=front;
	
	if(front==NULL){
		puts("Queue is empty");
		return;
	}
	front=front->next;
	
	printf("%s, %d\n",temp->ukuran,temp->data);
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
		free(temp);
	}
	
}

int main(){
	int choose;
	
	do{
		
		printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
		printf("Pilih: ");
		scanf("%d",&choose);
		
		switch(choose){
			case 1:{
				insert();
				break;
			}
			
			case 2:{
				servequeue();
				break;
			}
			
			case 3:{
				display();

				break;
			}
			
			
		}
	}while(choose!=4);
	
	serveall();
	
	return 0;
}
