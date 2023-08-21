#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//SingleLinkedList

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
	temp->next=NULL;
	
	if(*data==NULL){
		*data=temp;
	}
	else{
		temp->next=*data;
		*data=temp;
//		(*data)->next=temp;
	}
	
}

void insertbel(node**data,char produk[],int harga){
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	struct node*last=(struct node*)malloc(sizeof(struct node));
	strcpy(temp->produk,produk);
	temp->harga=harga;
	temp->next=NULL;
	
	last=*data;
	if(*data==NULL){
		*data=temp;
		return;
	}
	while(last->next!=NULL){
		last=last->next;
	}
	last->next=temp;
	
}

void deletedep(node**data){
	if(*data==NULL){
		puts("NULL");
		return;
	}
	(*data)=(*data)->next;
}

void deletebel(node**data){
	struct node*pre=(struct node*)malloc(sizeof(struct node));
	struct node*last=(struct node*)malloc(sizeof(struct node));
	last=*data;
	if(*data==NULL){
		puts("NULL");
		return;
	}
	while(last->next!=NULL){
		pre=last;
		last=last->next;
	}
pre->next=NULL;
//last=NULL;
//	free(last);
}

void deletebebas(node**data,char produk[],int harga){
	struct node*pre=(struct node*)malloc(sizeof(struct node));
	struct node*ptr=(struct node*)malloc(sizeof(struct node));
	ptr=*data;
//	printf("hapusdepan\n");
	if(*data==NULL){
		puts("NULL");
		return;
	}
	else if(strcmp(ptr->produk,produk)==0 && ptr->harga==harga){
		printf("hapusdepan\n");
//		deletedep(data);
		ptr=ptr->next;
		*data=ptr;
//		(*data)=(*data)->next;
		
		return;
	}
	else{
	while(ptr!=NULL){//bisa juga gk pakek || strcmp(ptr->produk,produk karena linkedlist biasa .tapi harus ptr->next!=NULL
		if(strcmp(ptr->produk,produk)==0){
			if(ptr->harga==harga){
//				pre=ptr;
				pre->next=ptr->next;
//				*data=pre;
				return;
			}
//			printf("tidaksama\n");		
		}	
	
		pre=ptr;
		ptr=ptr->next;		
		
	}
		
	}

	puts("Data tidak ditemukan");
	
}


void display(node*data){
	if(data==NULL){
		puts("NULL");
		return;
	}
	int i=0;
	while(data!=NULL){
		printf("%d. %s, %d\n",++i,data->produk,data->harga);
		data=data->next;
	}
	
	
}

int main(){
	
	insertdep(&data,"Earphone",80000);
	insertdep(&data,"Headphone",70000);
	insertdep(&data,"TWS",60000);
	insertdep(&data,"Bluetooth Speaker",250000);
	insertbel(&data,"Headshet",150000);
	
	display(data);
	
	deletedep(&data);
	deletebel(&data);
	puts("");
	display(data);
	
	deletebebas(&data,"TWS",80000);
	deletebebas(&data,"Headphone",70000);
	puts("");
	display(data);
	
	deletebebas(&data,"Earphone",80000);
	puts("");
	display(data);
	
	return 0;
}
