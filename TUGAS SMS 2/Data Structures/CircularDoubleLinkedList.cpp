#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//CircularDoubleLinkedList

struct node{
	char produk[100];
	int harga;
	struct node*prev,*next;
};
node*data=NULL;


void insertdep(node**data,char produk[],int harga){
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	strcpy(newnode->produk,produk);
	newnode->harga=harga;
	if(*data==NULL){
		newnode->prev=newnode;
		newnode->next=newnode;
		*data=newnode;
		printf("qwqw\n");
	}
	else{
		struct node*last=(struct node*)malloc(sizeof(struct node));
		last=*data;
		while(last->next!=*data){
			last=last->next;
		}
		last->next=newnode;
		newnode->next=*data;
		newnode->prev=last;
		(*data)->prev=newnode;
		*data=newnode;
			printf("qwqw\n");
	}
}

void insertbel(node**data,char produk[],int harga){
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	strcpy(newnode->produk,produk);
	newnode->harga=harga;
//	newnode->next=NULL;
	if(*data==NULL){
		newnode->next=newnode;
		newnode->prev=newnode;
		*data=newnode;
	}
	else{
	struct node*last=(struct node*)malloc(sizeof(struct node));
	last=*data;
		while(last->next!=*data){
			last=last->next;
		}
		last->next=newnode;
		newnode->prev=last;
		newnode->next=*data;
		(*data)->prev=newnode;

	}
}

void deletedep(node**data){
//	struct node*last=(struct node*)malloc(sizeof(struct node));
	if(*data==NULL){
		puts("NULL");
	}
	else{
		struct node*last=(struct node*)malloc(sizeof(struct node));
		struct node*pre=(struct node*)malloc(sizeof(struct node));
		last=*data;
		while(last->next!=*data){
			pre=last;
			last=last->next;
		}
		(*data)=(*data)->next;
		last->next=*data;
		(*data)->prev=last;
		
	}
}

void deletebel(node**data){
	struct node*pre=(struct node*)malloc(sizeof(struct node));
	struct node*ptr=(struct node*)malloc(sizeof(struct node));
	ptr=*data;
	if(*data==NULL){
		puts("NULL");
				
	}
	else{
		while(ptr->next!=*data){
			pre=ptr;
			ptr=ptr->next;
		}
		pre->next=*data;
		(*data)->prev=pre;
//		pre->next=NULL;// gak harus pakek ini
//		ptr->prev->next=NULL;////bisa si kalo langsung akhir kalu nggk gk bisa, kayak kalo dari deletebebas

	}
}

void deletebebas(node**data,char produk[],int harga){
	if(*data==NULL){
		puts("NULL");
		return;
	}
	else if(strcmp((*data)->produk,produk)==0 && (*data)->harga==harga){
		struct node*last=(struct node*)malloc(sizeof(struct node));
		last=*data;
		while(last->next!=*data){
			last=last->next;
		}

		(*data)=(*data)->next;
		last->next=*data;
		(*data)->prev=last;
		return;
	}
	else{
		struct node*ptr=(struct node*)malloc(sizeof(struct node));
		ptr=*data;
		struct node*pre=(struct node*)malloc(sizeof(struct node));
		while(ptr->next!=*data || strcmp(ptr->produk,produk)==0){
			if(strcmp(ptr->produk,produk)==0){
				if(ptr->harga==harga){
					if(ptr->next!=*data){
						pre->next=ptr->next;
						ptr->next->prev=pre;
					return;						
					}
					else if(ptr->next==*data){
						pre->next=ptr->next;
						return;
					}
				

				}
				
			}
			pre=ptr;
			ptr=ptr->next;
		}
	
	}
	puts("Tidak ditemukan");
	
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

	
	
}


int main(){
	insertdep(&data,"Earphone",80000);
	insertdep(&data,"Headphone",70000);
	
	insertdep(&data,"TWS",60000);
	
	insertdep(&data,"Bluetooth Speaker",250000);
	insertbel(&data,"Headshet",150000);
//	insertToIndex("Stick PS",50000,2);
	printf("insertdepan selesai\n");
	display(data);
	puts("");
	deletedep(&data);
	deletebel(&data);
	puts("");
	display(data);
	
	deletebebas(&data,"TWS",60000);
	puts("");
	display(data);
	deletebebas(&data,"Earphone",80000);
	puts("");
	display(data);
	
	
	return 0;
}
