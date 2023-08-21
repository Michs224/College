#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//CircularSingleLinkedList

struct node{
	char produk[100];
	int harga;
	struct node*next;
};
node*data=NULL;

void insertdep(node**data,char produk[],int harga){
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	strcpy(temp->produk,produk);
	temp->harga=harga;
//	temp->next=temp;

	struct node*ptr=(struct node*)malloc(sizeof(struct node));
	ptr=*data;
	if(*data==NULL){
		temp->next=temp;
		*data=temp;
//	printf("ajja\n");
	}
	else{
		while(ptr->next!=*data){
			ptr=ptr->next;
		}
		ptr->next=temp;
		temp->next=*data;
		*data=temp;

	}

//	printf("insertdep\n");
	
}

void insertToIndex(char produk[], int harga,int loc){
	struct node*nodee=(struct node*)malloc(sizeof(struct node));
	strcpy(nodee->produk,produk);
	nodee->harga=harga;
	
	int count=0;
	struct node*current=(struct node*)malloc(sizeof(struct node));
	struct node*sebcurrent=(struct node*)malloc(sizeof(struct node));
	current=data;
	while(current->next!=data && count!=2){
		sebcurrent=current;
		count++;
		current=current->next;
		
	}
	sebcurrent->next=nodee;
	nodee->next=current;
	
}

void insertbel(node**data,char produk[],int harga){
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	struct node*ptr=(struct node*)malloc(sizeof(struct node));
	strcpy(temp->produk,produk);
	temp->harga=harga;
//	temp->next=temp;
	
	ptr=*data;
	if(*data==NULL){
		temp->next=temp;
		*data=temp;
		return;
	}

	while(ptr->next!=*data){
		ptr=ptr->next;
	}
	ptr->next=temp;
	temp->next=*data;
//	*data=temp;
//		printf("insertbel\n");
}

void deletedep(node**data){
	struct node*ptr=(struct node*)malloc(sizeof (struct node));
	ptr=*data;
	if(*data==NULL){
		puts("NULL");
		return;
	}

	while(ptr->next!=*data){
		ptr=ptr->next;
	}
	*data=(*data)->next;
	ptr->next=*data;
}

void deletebel(node**data){
	struct node*pre=(struct node*)malloc(sizeof(struct node));
	struct node*last=(struct node*)malloc(sizeof(struct node));
	last=*data;
	if(*data==NULL){
		puts("NULL");
		return;
	}
	else if(last->next==*data){
		*data=NULL;
	}
	else{
	while(last->next!=*data){
		pre=last;
		last=last->next;
	}
	pre->next=*data;		
	}

//last=NULL;
//	free(last);
}

void deletebebas(node**data,char produk[],int harga){
	struct node*pre=(struct node*)malloc(sizeof(struct node));
	struct node*ptr=(struct node*)malloc(sizeof(struct node));
	ptr=*data;
	if(*data==NULL){
		puts("NULL");
		return;
	}
	else if(strcmp((*data)->produk,produk)==0 && (*data)->harga==harga){
//		deletedep(data);
		while(ptr->next!=*data){
		ptr=ptr->next;
		}
		*data=(*data)->next;
		ptr->next=*data;
		
		return;
	}
	else{
	while(ptr->next!=*data || strcmp(ptr->produk,produk)==0){
		if(strcmp(ptr->produk,produk)==0){
			printf("sama\n");
			if(ptr->harga==harga){
			pre->next=ptr->next;
			return;
			}
			printf("tidaksama\n");		
		}
		pre=ptr;
		ptr=ptr->next;		
	
	}		
	}

//	while(ptr->next!=*data && ptr->harga!=harga){ //// BIASANYA GINI AJA
//		pre=ptr;
//		ptr=ptr->next;
//	}
//	pre->next=ptr->next;
	puts("Data tidak ditemukan\n");
	
}


void display(node*data){
	struct node*ptr=(struct node*)malloc(sizeof(struct node));
	ptr=data;
	if(data==NULL){
		puts("NULL");
		return;
	}
	
	int i=0;
	
	do{	
		printf("%d. %s, %d\n",++i,ptr->produk,ptr->harga);
		ptr=ptr->next;
	}while(ptr!=data);

//	while(data!=){
//
//	}
	
	
}

int main(){
	
	insertdep(&data,"Earphone",80000);
	insertdep(&data,"Headphone",70000);
	
	insertdep(&data,"TWS",60000);
	
	insertdep(&data,"Bluetooth Speaker",250000);
	insertbel(&data,"Headshet",150000);
	insertToIndex("Stick PS",50000,2);
	printf("insertdepan selesai\n");
	display(data);
	puts("");
	deletedep(&data);
	deletebel(&data);display(data);
	puts("");
	display(data);
	
	deletebebas(&data,"TWS",60000);
	puts("");
	display(data);
	deletebebas(&data,"Earphone",80000);
	puts("");
	display(data);
//	deletebebas(&data,"TWS",60000);
//	puts("");
//	display(data);
	
	return 0;
}
