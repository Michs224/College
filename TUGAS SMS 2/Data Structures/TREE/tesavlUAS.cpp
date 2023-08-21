#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

struct node{
	int stocks,height;
	char items[100],type[20];
	node*left,*right;
};

//struct nodee{
//	int harga;
//	char nama[20],type[20];
//	nodee*left,*right;
//};

void Menu(){
		puts("\033[31;6m+---------------------------+\033[0m");	
		puts("\033[31;6m|          \033[36;4;6mTreeMart\033[0m         \033[31;6m|\033[0m");
		puts("\033[31;6m+---------------------------+\033[0m\n");
		printf("\033[38;2;255;165;0m1. Insertion\n2. Display Inventory\n3. Search Item\n4. Delete Item\n5. Delete All\n6. Exit\n>> \033[0m");
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

//int isInteger(const char* input) {
//    if (strlen(input) == 0) {
//        return 0; // String kosong
//    }
//    
//    char* endptr;
//    strtol(input, &endptr, 10);
//    
//    if (*endptr != '\0') {
//        return 0; // Karakter tidak valid setelah bilangan
//    }
//    
//    return 1;
//}

//bool Validasi(char input[100]){
//	if(input[0]==NULL){
//		return false;
//	}
//	for(int i=0;i<strlen(input);i++){
//		if(!isdigit(input[i])) return false;
//
//	}
//	fflush(stdin);
//	return true;
//	
//}

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

struct node* newNode(char item[100],char type[20],int stock){
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	
	temp->height=1;
	temp->stocks=stock;
	strcpy(temp->items,item);
	strcpy(temp->type,type);
	temp->left=NULL;
	temp->right=NULL;
	
	return temp;
	
}

struct node*insertion(node*tree,char item[100],char type[20],int stock){
	
}

bool validasispace(char item[100]){
	int i=0;
	while(item[i]!=NULL){
		if(item[i]==' ') return false;
		i++;
	}
	
	return true;
}

bool validasitype(char type[100],char typess[][100]){
	int i=0;
	while(typess[i][0]!=NULL){
		if(strcmp(typess[i],type)==0){
			return true;
		}
		i++;
	}
	return false;
}

struct node*InsertItem(node*tree){
	char item[100]={NULL};
	char type[100]={NULL};
	char typess[][100]={"Physical","Magic","Defense"};
	int stock;
	
	do{
		printf("Masukkan nama item tanpa space [5-20]: ");fflush(stdin);
		gets(item);fflush(stdin);
		printf("%s\n",item);
		if(strlen(item)<5 || strlen(item)>20 || !validasispace(item)){
			printf("Nama item harus 5-20 karakter dan tanpa spasi\n");
		}
		
	}while(strlen(item)<5 || strlen(item)>20 || !validasispace(item));
	
	do{
		printf("Masukkan type item [Physical\Magic\Defense]: ");fflush(stdin);
		gets(type);fflush(stdin);
		if(!validasitype(type,typess)){
			printf("Masukkan type item dari type yang tersedia\n");
		}
	}while(!validasitype(type,typess));
	
	do{
		printf("Masukkan stock item: ");fflush(stdin);
		scanf("%d",&stock);fflush(stdin);
		if(stock<1 || stock>99){
			printf("Stock harus antara 1-99, masukkan ulang!\n");
		}
		
	}while(stock<1 || stock >99);
	
	tree=insertion(tree,item,type,stock);
	
	return tree;
	
	
}

void Preorder(node*tree){
	if(tree!=NULL){
		printf("	%20s|	%20s	|\n",tree->items,tree->stocks);
		Preorder(tree->left);
		Preorder(tree->right);
	}
}

void Inorder(node*tree){
	if(tree!=NULL){
		Inorder(tree->left);
		printf("	%20s|	%20s	|\n",tree->items,tree->stocks);
		Inorder(tree->right);
	}
}
void Postorder(node*tree){
	if(tree!=NULL){
		Postorder(tree->left);
		Postorder(tree->right);
		printf("	%20s|	%20s	|\n",tree->items,tree->stocks);
	}
}

void Display(node*tree){
	char stritem[6]="Item";
	char strstock[6]="Stock";
	printf("Inventory:\n");
	printf("	%20s|	%20s	|\n",stritem,strstock);
	
	printf("Preorder\n");
	Preorder(tree);
	puts("");
	
	printf("Inorder\n");
	Inorder(tree);
	puts("");
	
	printf("Postorder\n");
	Postorder(tree);
	puts("");
}

int main(){
	struct node*tree=NULL;
	int choose;
	do{
		system("cls");
		Menu();
		scanf("%d",&choose);
		switch(choose){
			case 1:{
				tree=InsertItem(tree);
				break;
			}
			case 2:{
				if(tree==NULL){
					printf("Item empty\n");
				}
				else Display(tree);
				break;
			}
			case 3:{
				
				break;
			}
			case 4:{
				
				break;
			}
			case 5:{
//				tree=DeleteAll(tree);
				if(tree==NULL){
					printf("NULL\n");
				}else printf("Masih\n");
				break;
			}
			case 6:{
				printf("Thank You\n    %c%c\nExit...\n",1,7);
				exit(0);
				break;
			}
			default:{
				printf("Invalid input!,input again");
				fflush(stdin);
				break;
			}
		}
		
	}while(choose!=5);

	return 0;
}
