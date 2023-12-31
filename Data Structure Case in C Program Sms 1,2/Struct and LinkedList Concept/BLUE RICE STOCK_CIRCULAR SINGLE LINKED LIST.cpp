#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct node{
	char type[100];
	int weight;
	int stockrice;
	
	struct node*next;
};
struct node*start=NULL;
//struct node{
//	char type[100];
//}rice;



struct node *menu(struct node *start){
		struct node*temp=(struct node*)malloc(sizeof(struct node));
		temp=start;
//		int x;
		printf("BLUE RICE STOCK\n");
		printf("---------------\n\n");
		
		printf("  Rice Stock (STACK)\n");
//		while(temp!=NULL){
//			printf("  [ %-20s | %3d kg<s> ]\n",temp->type,temp->weight);
//
//			temp=temp->next;
//		}
//		printf("\n");

//		printf("\n\n");
//		printf("Option:\n1. Stock Rice Sack\n2. Sell Rice Sack\n3. Exit\n");
//		printf("Choose: ");scanf("%d",&x);
		return start;
}

void display(struct node *start){
		struct node*temp=(struct node*)malloc(sizeof(struct node));
		temp=start;
		printf("BLUE RICE STOCK\n");
		printf("---------------\n\n");
		
		printf("  Rice Stock (STACK)\n");
		if(temp==NULL){
			printf("The Rice Storage is Empty\n\n");
			return;
		}
		else{
			do{
			printf("  [ %-20s | %3d kg<s> ]\n",temp->type,temp->weight);
			temp=temp->next;
		}while(temp!=start);
		}

		
		printf("\n");
//		return start;
}


int n=3;
char typerice[4][10]={"long", "medium", "short"};
//strcpy(typerice[0],"long");
//strcpy(typerice[1],"medium");
//strcpy(typerice[2],"short");

struct node *insert(struct node *start, char type[],int weight){
	node *new_node=(struct node*)malloc(sizeof(struct node));
	node *ptr=(struct node*)malloc(sizeof(struct node));
	strcpy(new_node->type,type);
	new_node->weight=weight;
	
	if(start==NULL){
		new_node->next=new_node;
		start=new_node;
	}
	else {
		printf("%s\n",start->type);
		ptr=start;
		while(ptr->next!=start){
			ptr=ptr->next;
		}
		ptr->next=new_node;
		new_node->next=start;
		start=new_node;

	}
	
	return start;
	
	
}

//struct node *display(struct node *start){
//	node *ptr=(struct node *)malloc(sizeof(struct node));
//	ptr=start;
//	if(ptr==NULL){
//		printf("Double linked list is empty\n");
//		return start;
//	}
//	else{
//		while(ptr!=NULL){
//			printf("%d ",ptr->angka);
//			ptr=ptr->next;
//		}printf("\n");
//		return start;
//	}
//}

struct node *stockrice(struct node*start){
	int check=0;	
	char type[100];
	int weight;
	int stock;
	do{
	
		printf("Input Rice Type (long/medium/short) grain: "); scanf("%s",type);
		for(int i=0;i<n;i++){
			if(strcmp(typerice[i],type)==0){
				check=1;
			}		
		}
	
		if(check==0){
			printf("The type of the rice must be 'long','medium', or'short', please input again\n");
		}
			
	}while(check==0);
	
	
	do{
		printf("Input Weight of The Rice Stock [10..100 kg(s)]: "); scanf("%d",&weight);
		if(weight<10 || weight >100){
			printf("The weight must be between 10 kilograms, please input again!\n");
			system("cls");
		}
	}while(weight<10 || weight >100);
	
	
	struct node*temp=(struct node*) malloc(sizeof(struct node));
	temp=start;
	int jumlah=0;

	while(temp!=start){
		jumlah++;
		temp=temp->next;
	}
	
	if(jumlah==10){
		system("cls");
		printf("The Rice Storage is Full\n");
		return start;
	}
	strcat(type," grain");
	start=insert(start,type,weight);
	system("cls");
	printf("--- Add Rice Sack Success ---\n\n");
	return start;
	
	
}

struct node *sellrice_delete_belakang(struct node *start){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	struct node *pre=(struct node*)malloc(sizeof(struct node));
	temp=start;
//	pre=start;
	if(temp==NULL){
			return start;
		}
	else if(temp->next==start){
		temp=NULL;
		start=temp;
		return start;
	}
	else {
	while(temp->next!=start) {
	pre=temp;
	temp=temp->next;	
	}
	pre->next=start;
	printf("--- Sell Rice Sack Success ---\n\n");
	free(temp);
	return start;
	}

	
}

int main(){
	int x;
	char again='y';
	int pertama=0;
	do{
		system("cls");
		if(pertama!=1) start=menu(start);
		else display(start);
		printf("\n");
		printf("Option:\n1. Stock Rice Sack\n2. Sell Rice Sack\n3. Exit\n");
		printf(">> Input Choice: ");scanf("%d",&x);
		switch(x){
			case 1:
				start=stockrice(start);
				display(start);
				pertama=1;
				printf("Do you want to do it again? (y/n): "); scanf(" %c",&again);	
				break;
			case 2:
				start=sellrice_delete_belakang(start);
				display(start);
				pertama=1;
				printf("Do you want to do it again? (y/n): "); scanf(" %c",&again);
				break;
			case 3:
				printf("Exit...\n");
				exit(0);
				break;
			default:
				system("cls");
				printf("Invalid input!\n");
				system("pause");
				break;
				
		}
		
	}while(again!='n');
	system("cls");
	printf("Exit...\n");
	return 0;
}
