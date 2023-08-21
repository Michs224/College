#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>


struct node{
	char Id[10];
	char heronames[100],types[30];
	int prices;
	struct node*left,*right,*next;
};

//struct node*tree[1000]={NULL};
struct node*tree=NULL;

void displaymenu(){
	printf("Welcome to mobileGeLend,\n");
	printf("1. Show all heroes\n2. Search hero\n3. Insert new hero\n4. Delete hero\n5. Exit\n>> ");
	
}

void entercontinue(){
	printf("Press enter to continue...");getchar();
}

bool checkunique(struct node*tree,char heroname[100]){
	int check=0;
	if(tree==NULL){
		return true;
	}
	
	if(strcmp(tree->heronames,heroname)==0){
	check=1;	
	}
	else{
		if(tree->next!=NULL){
			struct node*temp=tree;
			while(temp!=NULL){
				if(strcmp(temp->heronames,heroname)==0)check=1;
				
				tree=tree->next;
			}
		}
		else{
			checkunique(tree->left,heroname);
			checkunique(tree->left,heroname);	
		}

	}
	if(check==1)return false;
	else return true;
	
	
}

struct node*searchhhh(struct node *tree,char heroname[100]){
	if(tree==NULL || strcmp(tree->heronames,heroname)==0){
		return tree;
	}
	if(tree==NULL){
		puts("No hero yet !\n");
		entercontinue();
	}
	
	if (strcmp(heroname,tree->heronames)<0){
		return searchhhh(tree->left,heroname);
	}
	else if(strcmp(heroname,tree->heronames)>0){
		return searchhhh(tree->right,heroname);
		
	}
	
	
}

void insert(struct node*tree,char id[10],char heroname[100],char type[30],int price){
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	
	strcpy(temp->Id,id);
	strcpy(temp->heronames,heroname);
	strcpy(temp->types,type);
	temp->prices=price;
	temp->left=NULL;
	temp->next=NULL;
	
	if(tree==NULL){
		tree=temp;
//		tree->left=NULL;
//		tree->right=NULL;
	}
	else{
		if(strcmp(heroname,tree->heronames)<0){
			insert(tree->left,id,heroname,type,price);
		}
		else if(strcmp(heroname,tree->heronames)>0)insert(tree->right,id,heroname,type,price);
		else{
			struct node*last=tree;
			while(last->next!=NULL){
				
				last=last->next;
			}
			last->next=temp;
			
		}
		
	}
	
	
}

void Insertnewhero(){
	char heroname[100];
	printf("insert new hero\n");
	printf("------------------------\n");
	
	do{
		printf("Input hero name [unique and minimum 5 chars]: ");getchar();gets(heroname);
		
	}while(!checkunique(tree,heroname) || strlen(heroname)<5);
	
	char type[30];
	do{
		
		printf("Input hero type [Magical | Physical] (case sensitive): ");getchar();gets(type);
	}while(strcmp(type,"Magical")!=0 && strcmp(type,"Physical")!=0);
	
	int price;
	do{
		printf("Input hero price [minimum 10000 maximum 32000]: ");getchar();scanf("%d",&price);
	}while(price<10000 || price > 32000);
	
	char id[10]={"HR"};
	for(int i=2;i<5;i++){
		int x;
		x=rand()%10;
		char numm[2]{NULL};
		itoa(x,numm,10);
		strcat(id,numm);
	}
	
	insert(tree,id,heroname,type,price);
}

void search(){
	node*ptr;
	char heroname[100];
		if(tree==NULL){
			puts("No hero yet !\n");
			entercontinue();
			return;
		}else{
			printf("Input hero ID to search ['0' to go back]: ");getchar();gets(heroname);
			if(strcmp(heroname,"0")==0)return;
			
			ptr=searchhhh(tree,heroname);
			if(ptr==NULL){
			printf("Hero %s not found !\n\n",heroname);
			}
			else{
				printf("Hero found !\n\n");
				printf("|ID           |Name          |Type          |Price          |\n");
				printf("-------------------------------------------------------------\n");
				
				while(ptr!=NULL){
					printf("|%s         |%s          |%s          |%d          |",ptr->Id,ptr->heronames,ptr->types,ptr->prices);
				}
			}
		}
}

int main(){
	int choose;
	srand(time(0));		
	do{
		system("cls");
		displaymenu();
		scanf("%d",&choose);
		
		switch(choose){
			
			case 1:{
				
				break;
			}
			case 2:{
				search();
				
				break;
			}
			case 3:{
				Insertnewhero();
				break;
			}
			case 4:{
				
				break;
			}
				
			
		}
	}while(choose!=5);
	
	
	return 0;
}
