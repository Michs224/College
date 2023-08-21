#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//DoubleLinkedList

struct node{
	char produk[100];
	int harga;
	struct node*prev,*next;
};
node*data=NULL,*tail=NULL;


void insertdep(node**data,char produk[],int harga){
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	strcpy(newnode->produk,produk);
	newnode->harga=harga;
	
	if(*data==NULL){
		newnode->prev=NULL;
		newnode->next=NULL;
		*data=newnode;
		tail=newnode;
	}
	
	else{
//		struct node*last=(struct node*)malloc(sizeof(struct node));
//		last=*data;
//		while(last->next!=NULL){
//			last=last->next;
//		}
//		last->next=newnode;
//		(*data)->prev=newnode;
		newnode->next=*data;
		newnode->prev=NULL;//
		(*data)->prev=newnode;
		*data=newnode;
	}
	
}

void insertbel(node**data,char produk[],int harga){
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	strcpy(newnode->produk,produk);
	newnode->harga=harga;
//	newnode->next=NULL;
	if(*data==NULL){
		newnode->next=NULL;
		newnode->prev=NULL;
		*data=newnode;
	}
	else{
	struct node*last=(struct node*)malloc(sizeof(struct node));
	last=*data;
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=newnode;
		newnode->next=NULL;
		newnode->prev=last;
//		printf("%d\n",newnode->harga);
//		(*data)->prev=newnode;
	}
}

void deletedep(node**data){
//	struct node*last=(struct node*)malloc(sizeof(struct node));
	if(*data==NULL){
		puts("NULL");
	}
	else{
//		struct node*last=(struct node*)malloc(sizeof(struct node));
//		while(last->next!=*data){
//			last=last->next;
//		}

		(*data)=(*data)->next;
//		last->next=*data;
			(*data)->prev=NULL;
	}
}

void deletebel(node**data){
	struct node*pre=(struct node*)malloc(sizeof(struct node));
	struct node*ptr=(struct node*)malloc(sizeof(struct node));
	ptr=*data;
	if(*data==NULL){
		puts("NULL");
		return;
				
	}
	else{
		
		while(ptr->next!=NULL){
			pre=ptr;
			ptr=ptr->next;
		}
		pre->next=ptr->next;
//		pre->next=NULL;// gak harus pakek ini
//		ptr->prev->next=NULL;////bisa si kalo langsung akhir kalu nggk gk bisa, kayak kalo dari deletebebas

	}
}

void deletebebas(node**data,char produk[],int harga){
	if(*data==NULL){
		puts("NULL");
	}
	else if(strcmp((*data)->produk,produk)==0 && (*data)->harga==harga){
		(*data)=(*data)->next;
		(*data)->prev=NULL;
		return;
	}
	else{
		struct node*ptr=(struct node*)malloc(sizeof(struct node));
		ptr=*data;
		struct node*pre=(struct node*)malloc(sizeof(struct node));
		while(ptr!=NULL){
			if(strcmp(ptr->produk,produk)==0){
				if(ptr->harga==harga){
					if(ptr->next!=NULL){
					pre->next=ptr->next;
					ptr->next->prev=pre;
									
					}
					else{
						pre->next=NULL;
						
					}
					free(ptr);
					return;
				}
				
			}
			pre=ptr;
			ptr=ptr->next;
		}
	
	}
	puts("Tidak ditemukan");
	
}


void display(node*data){
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	temp=data;
	if(data==NULL){
		puts("NULL");
		return;
	}
	int i=0;
	while(temp!=NULL){
		printf("%d. %s, %d\n",++i,temp->produk,temp->harga);
		temp=temp->next;
	}
	puts("");
	struct node*temp1=tail;
	if(data=NULL){
		puts("NULL");
		return;
	}
	int j=0;
	while(temp1!=NULL){
		printf("%d. %s, %d\n",++j,temp1->produk,temp1->harga);
		temp1=temp1->prev;
	}
	
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
//	puts("");
//	deletedep(&data);
//	deletebel(&data);
//	puts("");
//	display(data);
//	
//	deletebebas(&data,"TWS",60000);
//	puts("");
//	display(data);
//	deletebebas(&data,"Earphone",80000);
//	puts("");
//	display(data);
	
	
	return 0;
}
