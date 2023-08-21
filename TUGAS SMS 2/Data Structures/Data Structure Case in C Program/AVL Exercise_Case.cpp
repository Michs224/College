#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

struct node{
	int data,height,harga;
	node*left,*right;
	char type[20],nama[20];
};

struct nodee{
	int harga;
	char nama[20],type[20];
	nodee*left,*right;
};

void Menu(){
		puts("\033[31;6m+---------------------------+\033[0m");	
		puts("\033[31;6m|          \033[36;4;6mAVL Tree\033[0m         \033[31;6m|\033[0m");
		puts("\033[31;6m+---------------------------+\033[0m\n");
		printf("\033[38;2;255;165;0m1. Insertion\n2. Deletion\n3. Traversal\n4. Exit\n>> \033[0m");
}

struct node*NewNode(char nama[20],char type[20],int harga){
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	
	temp->harga=harga;
	temp->height=1;
	strcpy(temp->nama,nama);
	strcpy(temp->type,type);
	temp->right=NULL;
	temp->left=NULL;
	
	
	return temp;


}

int height(node*tree){
	if(tree==NULL){
		return 0;
	}
	
	return tree->height;
	
}

int max(int left,int right){
	return (left>right) ?  left : right;
	
}

int Balance(node*tree){
	if(tree==NULL){
		return 0;
	}
	
	return height(tree->left)-height(tree->right);
	
}


struct node*leftRotate(node*tree){
	struct node*mid=tree->right;
	struct node*bottom=mid->left;
	
	mid->left=tree;
	tree->right=bottom;
	
	tree->height=1+max(height(tree->left),height(tree->right));
	
	mid->height=1+max(height(mid->left),height(mid->right));
	return mid;
	
}

struct node*rightRotate(node*tree){
	struct node*mid=tree->left;
	struct node*bottom=mid->right;
	
	mid->right=tree;
	tree->left=bottom;
	
	tree->height=1+max(height(tree->left),height(tree->right));
	
	mid->height=1+max(height(mid->left),height(mid->right));
	
	return mid;
	
}


struct nodee*insertbst(nodee*bst,char nama[20],char type[20],int harga){
	if(bst==NULL){
		struct nodee*temp=(struct nodee*)malloc(sizeof(struct nodee));
		
		temp->harga=harga;
		strcpy(temp->nama,nama);
		strcpy(temp->type,type);
		
		temp->left=NULL;
		temp->right=NULL;
		
		return temp;
	}
	
	if(strcmp(nama,bst->nama)<0){
		bst->left=insertbst(bst->left,nama,type,harga);
	}
	else if(strcmp(nama,bst->nama)>0){
		bst->right=insertbst(bst->right,nama,type,harga);
	}
	else{
		bst->left=insertbst(bst->left,nama,type,harga);
	}
}


struct node*InsertData(node*tree,char nama[20],char type[20],int harga){
	if(tree==NULL){
		printf("\nInsert Successfully!\n");
		return NewNode(nama,type,harga);
	}
	
	if(harga<tree->harga){
		tree->left=InsertData(tree->left,nama,type,harga);
	}
	else if(harga>tree->harga){
		tree->right=InsertData(tree->right,nama,type,harga);
	}
	else{
		printf("\nData tidak boleh sama, insert gagal!\n");
		return tree;
	}
	
	tree->height=1+max(height(tree->left),height(tree->right));
	
	int x=Balance(tree);
	
	if(x<-1 && harga>tree->right->harga){//RR
		return leftRotate(tree);
	}
	if(x>1 && harga<tree->left->harga){//LL
		return rightRotate(tree);
	}
	if(x>1 && harga>tree->left->harga){//LR
		tree->left=leftRotate(tree->left);
		return rightRotate(tree);
	}
	if(x<-1 && harga<tree->right->harga){//RL
		tree->right=rightRotate(tree->right);
		return leftRotate(tree);
	}
	
	return tree;
	
}

struct node*MinValue(node*tree){
	struct node*current=tree;
	
	while(current->right!=NULL){
		
		current=current->right;
	}
	return current;
}

struct node*DeleteData(node*tree,char nama[20],char type[20],int harga,int *check){
	if(tree==NULL){
		printf("\nData tidak ditemukan!\n");
		return tree;
	}
	if(harga<tree->harga){
		tree->left=DeleteData(tree->left,nama,type,harga,check);
	}
	else if(harga>tree->harga){
		tree->right=DeleteData(tree->right,nama,type,harga,check);
	}
	else{// else if(harga=tree->harga && strcmp(nama,tree->nama)==0 && strcmp(type,tree->type)==0)
		if(tree->left==NULL || tree->right ==NULL){
			struct node*temp=(tree->left)? tree->left:tree->right;
			if(temp==NULL){
				temp=tree;
				tree=NULL;
				*check=1;
			}
			else{
				*tree=*temp;
				*check=1;
			}
			free(temp);
		}
		else{
			struct node*temp=MinValue(tree->left);
			
			tree->harga=temp->harga;
			strcpy(tree->nama,temp->nama);
			strcpy(tree->type,temp->type);
			
			tree->left=DeleteData(tree->left,temp->nama,temp->type,temp->harga,check);
		}
	}
	
	if(tree==NULL){
		return tree;
	}
	
	tree->height=1+max(height(tree->left),height(tree->right));
	int x=Balance(tree);
	
	
	if(x<-1 && Balance(tree->right)<=0){//RR
		return leftRotate(tree);
	}
	if(x<-1 && Balance(tree->right)>0){//RL
		tree->right=rightRotate(tree->right);
		return leftRotate(tree);
	}
	if(x>1 && Balance(tree->left)>=0){//LL
		return rightRotate(tree);
	}
	if(x>1 && Balance(tree->left)<0){//LR
		tree->left=leftRotate(tree->left);
		return rightRotate(tree);
	}
	
	return tree;
}

bool validasitype(char type[20],char typee[][20]){
//	char typee[100][20]={"Regular","Medium","Deluxe"};
	
	int i=0;
	while(typee[i][0]!=NULL){
		if(strcmp(type,typee[i])==0){
			return true;
		}
		i++;
	}
	
	return false;
	
}


struct nodee*searchname(nodee*bst,char nama[20],char type[20]){
	
	if(bst==NULL || (strcmp(nama,bst->nama)==0 && strcmp(type,bst->type)==0)){
	return bst;
	}
	
	if(strcmp(nama,bst->nama)<0){
			return searchname(bst->left,nama,type);
	}
	
	else if(strcmp(nama,bst->nama)>0){
		return searchname(bst->right,nama,type);
	}
	
	else{
		return searchname(bst->left,nama,type);
	}

	
}

struct node*Deletion(node*tree,nodee*bst){
	char nama[20],type[20];
	int harga;
	int check=0;
	char typee[][20]={"Regular","Medium","Deluxe"};
	
	do{
		printf("Input nama [5-25 karakter]: ");getchar();gets(nama);
		fflush(stdin);
		
	}while(strlen(nama)<5 || strlen(nama)>25);
	
	do{
		printf("Input type [Regular/Medium/Deluxe] (Case Sensitive): ");gets(type);
		fflush(stdin);
		
	}while(!validasitype(type,typee));
	
	struct nodee*ptr=searchname(bst,nama,type);
	if(ptr==NULL){
		printf("\nData tidak ditemukan\n");
		return tree;
	}
	else{
	harga=ptr->harga;		
	}
	
	tree=DeleteData(tree,nama,type,harga,&check);
	if(check==1){
		printf("\n--- %s was deleted ---\n",nama);
	}
	
	return tree;
	
}

struct node*popAll(node*tree){
	if(tree==NULL){
		return NULL;
	}
	
	tree->left=popAll(tree->left);
	tree->right=popAll(tree->right);
	free(tree);
	
	return NULL;
	
}
int count=1;
void Traversal(node*tree){
	if(tree!=NULL){
		Traversal(tree->left);
		printf("%d. %s, %s, %d\n",count++,tree->nama,tree->type,tree->harga);
		Traversal(tree->right);
	}
}


int main(){
	struct node*tree=NULL;
	struct nodee*bst=NULL;
	int choose;

	while(1){
		system("cls");
		Menu();
		scanf("%d",&choose);
		
		switch(choose){
			case 1:{
				char nama[20],type[20];
				int harga;
				char typee[][20]={"Regular","Medium","Deluxe"};
				
				do{
					printf("Input nama [5-25 karakter]: ");getchar();gets(nama);
					fflush(stdin);
					
				}while(strlen(nama)<5 || strlen(nama)>25);
				
				do{
					printf("Input type [Regular/Medium/Deluxe] (Case Sensitive): ");gets(type);
					fflush(stdin);
					
				}while(!validasitype(type,typee));
				
				do{
					printf("Input harga[10000-50000]: ");scanf("%d",&harga);
					getchar();
				}while(harga<10000 || harga > 50000);
				bst=insertbst(bst,nama,type,harga);
				tree=InsertData(tree,nama,type,harga);
				
				
//				tree=Insertion(tree,bst);
				
				puts("");
				system("pause");
				break;
			}
			case 2:{
				tree=Deletion(tree,bst);
				puts("");
				system("pause");
				break;
			}
			case 3:{
				puts("");
				count=1;
				Traversal(tree);
				puts("");
				system("pause");
				break;
			}
			case 4:{
				tree=popAll(tree);
				printf("\nThank you\n    %c%c\n",1,7);
				exit(0);
				break;
			}
			default:{
				printf("--- Input incorrect,please input again! ---\n\n");
				system("pause");
				fflush(stdin);
				break;
			}
			
		}
		
		}

	
	return 0;
}
