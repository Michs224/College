#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <unistd.h>

struct node{
	int score,height;
	char username[50];
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

int getBalance(node*tree){
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

struct node* newNode(char username[50],int score){
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	
	temp->height=1;
	temp->score=score;
	strcpy(temp->username,username);
	temp->left=NULL;
	temp->right=NULL;
	
	return temp;
	
}

//struct node*insertion(node*tree,char item[100],char type[20],int stock){
//	
//}

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

//struct node*InsertItem(node*tree){
//	char item[100]={NULL};
//	char type[100]={NULL};
//	char typess[][100]={"Physical","Magic","Defense"};
//	int stock;
//	
//	do{
//		printf("Masukkan nama item tanpa space [5-20]: ");fflush(stdin);
//		gets(item);fflush(stdin);
//		printf("%s\n",item);
//		if(strlen(item)<5 || strlen(item)>20 || !validasispace(item)){
//			printf("Nama item harus 5-20 karakter dan tanpa spasi\n");
//		}
//		
//	}while(strlen(item)<5 || strlen(item)>20 || !validasispace(item));
//	
//	do{
//		printf("Masukkan type item [Physical\Magic\Defense]: ");fflush(stdin);
//		gets(type);fflush(stdin);
//		if(!validasitype(type,typess)){
//			printf("Masukkan type item dari type yang tersedia\n");
//		}
//	}while(!validasitype(type,typess));
//	
//	do{
//		printf("Masukkan stock item: ");fflush(stdin);
//		scanf("%d",&stock);fflush(stdin);
//		if(stock<1 || stock>99){
//			printf("Stock harus antara 1-99, masukkan ulang!\n");
//		}
//		
//	}while(stock<1 || stock >99);
//	
//	tree=insertion(tree,item,type,stock);
//	
//	return tree;
//}

struct node*insertion(node*tree,char username[50],int score){
	if(tree==NULL){
		printf("Success Insert\n");
		return newNode(username,score);
	}
	
	if(score<tree->score){
		tree->left=insertion(tree->left,username,score);
	}
	else if(score>tree->score){
		tree->right=insertion(tree->right,username,score);
	}
	else{
		printf("Score tidak boleh sama\n");
		return tree;
	}
	
	tree->height=1+max(height(tree->left),height(tree->right));
	int x=getBalance(tree);
	
	if(x<-1 && score > tree->right->score){//RR
		return leftRotate(tree);
	}
	if(x<-1 && score < tree->right->score){//RL
		tree->right=rightRotate(tree->right);
		return leftRotate(tree);
	}
	if(x>1 && score<tree->left->score){//LL
		return rightRotate(tree);
	}
	if(x>1 && score > tree->left->score){//LR
		tree->left=leftRotate(tree->left);
		return rightRotate(tree);
	}
	
	return tree;
	
}

struct node*successor(node*tree){
	struct node*current=tree;
	
	while(current->left!=NULL){
		current=current->left;
	}
	return current;
}

struct node*predecessor(node*tree){
	struct node*current=tree;
	
	while(current->right!=NULL){
		current=current->right;
	}
	return current;
}

struct node*deletion(node*tree,int score,int *check){
	if(tree==NULL){
		printf("Not Found\n");
		return tree;
	}
	
	if(score<tree->score){
		tree->left=deletion(tree->left,score,check);
	}
	else if(score>tree->score){
		tree->right=deletion(tree->right,score,check);
	}
	else{
		if(tree->left==NULL || tree->right==NULL){
			struct node*temp=(tree->left)?tree->left:tree->right;
			
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
			struct node*temp=predecessor(tree->left);
			
			tree->score=temp->score;
			strcpy(tree->username,temp->username);
			
			tree->left=deletion(tree->left,temp->score,check);
		}
	}
	
	if(tree==NULL){
		return tree;
	}
	
	tree->height=1+max(height(tree->left),height(tree->right));
	int x=getBalance(tree);
	
	if(x<-1 && getBalance(tree->right)<=0){//RR
		return leftRotate(tree);
	}
	if(x<-1 && getBalance(tree->right)>0){//RL
		tree->right=rightRotate(tree->right);
		return leftRotate(tree);
	}
	if(x>1 && getBalance(tree->left)>=0){//LL
		return rightRotate(tree);
	}
	if(x>1 && getBalance(tree->left)<0){//LR
		tree->left=leftRotate(tree->left);
		return rightRotate(tree);
	}
	
	return tree;

}

bool validasispacekecil(char username[50]){
	int i=0;
	while(username[i]!=NULL){
		if(username[i]==' ' || (username[i]>=65 && username[i]<=90))
		return false;
		i++;
	}
	return true;
}

struct node*InsertData(node*tree){
	char username[50];
	int score,check=0;
//	int x=pow(2,3);
//	printf("%d\n",x);
	do{
		printf("Masukkan Score dan Username dengan format <<score>> <<username>>: ");
		fflush(stdin);
		scanf("<<%d>> <<%[^>]",&score,username);
		printf("%d %s\n",score,username);
		
	}while(score<0 || score>pow(2,31) || strlen(username)<1 || strlen(username)>30 || !validasispacekecil(username));
	
	tree=insertion(tree,username,score);
	
	return tree;
	
}

struct node*DeleteData(node*tree){
	int score,check=0;
	
	do{
		printf("Masukkan Score dari Username yang ingin dihapus dengan format <<score>>: ");
		fflush(stdin);
		scanf("<<%d>>",&score);
		printf("%d\n",score);
		
	}while(score<0 || score>pow(2,31));
	tree=deletion(tree,score,&check);
	if(check==1){
		printf("Score %d deleted\n",score);
	}
	
	return tree;
}

//void Preorder(node*tree){
//	if(tree!=NULL){
//		printf("	%20s|	%20s	|\n",tree->items,tree->stocks);
//		Preorder(tree->left);
//		Preorder(tree->right);
//	}
//}
//
//void Inorder(node*tree){
//	if(tree!=NULL){
//		Inorder(tree->left);
//		printf("	%20s|	%20s	|\n",tree->items,tree->stocks);
//		Inorder(tree->right);
//	}
//}
//void Postorder(node*tree){
//	if(tree!=NULL){
//		Postorder(tree->left);
//		Postorder(tree->right);
//		printf("	%20s|	%20s	|\n",tree->items,tree->stocks);
//	}
//}

//void Display(node*tree){
//	char stritem[6]="Item";
//	char strstock[6]="Stock";
//	printf("Inventory:\n");
//	printf("	%20s|	%20s	|\n",stritem,strstock);
//	
//	printf("Preorder\n");
//	Preorder(tree);
//	puts("");
//	
//	printf("Inorder\n");
//	Inorder(tree);
//	puts("");
//	
//	printf("Postorder\n");
//	Postorder(tree);
//	puts("");
//}


int count=1,count2=1;
void Display1(node*tree){
	if(tree!=NULL){
		Display1(tree->right);
		if(count<=3){
		printf("<<%d    %d    >>	",count,tree->score);			
		}
		else return;
		count++;	
		Display1(tree->left);
	}
}

void Display2(node*tree){
	if(tree!=NULL){
		Display2(tree->right);
		if(count2<=3){
		printf("<<%d %s >>	",count2,tree->username);			
		}

		else return;
		count2++;
		Display2(tree->left);
	}
}

void Display(node*tree){
	printf("Data Rank:\n");
	Display1(tree);
	puts("");
	Display2(tree);
	puts("");
	count=1;
	count2=1;
}

struct node*Search(node*tree,int score){
	if(tree==NULL || score==tree->score){
		return tree;
	}
	if(score<tree->score){
		return Search(tree->left,score);
	}
	else if(score>tree->score){
		return Search(tree->right,score);
	}
}

struct node*SearchData(node*tree){
	int score;
	
	do{
		printf("Masukkan Score dari Username yang ingin dihapus dengan format <<score>>: ");
		fflush(stdin);
		scanf("<<%d>>",&score);
		printf("%d\n",score);
		
	}while(score<0 || score>pow(2,31));
	
	struct node*ptr=Search(tree,score);
	if(ptr==NULL){
		printf("Not Found\n");
	}
	else{
		printf("Username: %s\nScore: %d\n",ptr->username,ptr->score);
	}
	
	return tree;
}

struct node*DeleteAll(node*tree){
	if(tree==NULL){
		return NULL;
	}
	
	tree->left=DeleteAll(tree->left);
	tree->right=DeleteAll(tree->right);
	free(tree);
	
	return NULL;
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
				tree=InsertData(tree);
				system("pause");
				fflush(stdin);
				break;
			}
			case 2:{
				if(tree==NULL){
					printf("Item empty\n");
				}
				else Display(tree);
				system("pause");
				fflush(stdin);
				break;
			}
			case 3:{
				struct node*ptr=SearchData(tree);
				system("pause");
				fflush(stdin);
				break;
			}
			case 4:{
				tree=DeleteData(tree);
				system("pause");
				fflush(stdin);
				break;
			}
			case 5:{
				tree=DeleteAll(tree);
				if(tree==NULL){
					printf("NULL\n");
				}else printf("Masih\n");
				system("pause");
//				fflush(stdin);
				break;
			}
			case 6:{
				char titik[5]="....";
				printf("Thank You\n    %c%c\nExit",1,7);
				for(int i=0;i<strlen(titik);i++){
					printf("%c",titik[i]);
					sleep(1.75);
				}puts("");
				break;
			}
			default:{
				printf("Invalid input!,input again");
				fflush(stdin);
				break;
			}
		}
		
	}while(choose!=6);

	return 0;
}
