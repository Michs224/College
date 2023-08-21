#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node{
	int data,height;
	node*left,*right;
};


void Menu(){
		puts("\033[31;6m+---------------------------+\033[0m");	
		puts("\033[31;6m|          \033[36;4;6mAVL Tree\033[0m         \033[31;6m|\033[0m");
		puts("\033[31;6m+---------------------------+\033[0m\n");
		printf("\033[38;2;255;165;0m1. Insertion\n2. Deletion\n3. Traversal\n4. Exit\n>> \033[0m");
}

struct node*NewNode(int data){
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	
	temp->data=data;
	temp->height=1;
	temp->left=NULL;
	temp->right=NULL;
	
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

bool Validasi(char input[100]){
	if(input[0]==NULL){
		return false;
	}
	for(int i=0;i<strlen(input);i++){
		if(!isdigit(input[i])) return false;

	}
	fflush(stdin);
	return true;
	
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

struct node*InsertData(node*tree,int value){
	if(tree==NULL){
		printf("\n--- Insert Successfull! ---\n");
		return NewNode(value);
	}
	
	else{
		if(value<tree->data){
			tree->left=InsertData(tree->left,value);
			
		}
		else if(value>tree->data){
			tree->right=InsertData(tree->right,value);
		}
		else {
			printf("\n--- Insert Failed! ---\n");
			printf("The data already exists, it can't be the same!\n");
			return tree;	
		}
		
	}

	tree->height=1+max(height(tree->left),height(tree->right));

	int x=Balance(tree);
	
	if(x<-1 && value>tree->right->data){//RR, LeftRotate
		return leftRotate(tree);
	}
	if(x>1 && value<tree->left->data){//LL,RightRotate
		return rightRotate(tree);
	}
	if(x<-1 && value<tree->right->data){//RL, RL Rotate
		tree->right=rightRotate(tree->right);
		return leftRotate(tree);
		
	}
	if(x>1 && value >tree->left->data){//LR,LR Rotate
		tree->left=leftRotate(tree->left);
		return rightRotate(tree);
	}
	
	return tree;
}

struct node*MinValue(node*tree){
	struct node*current=tree;
	while(current->left!=NULL){
		current=current->left;
	}
	return current;
}

struct node*DeleteData(node*tree,int value,int *check){
	if(tree==NULL){
		printf("\nData not found!\n");
		return tree;
	}
	else{
		if(value<tree->data){
			tree->left=DeleteData(tree->left,value,check);
		}
		else if(value>tree->data){
			tree->right=DeleteData(tree->right,value,check);
		}
		else{
			//VERSI 1
//			if(tree->left==NULL){
//				struct node*temp=tree->right;
//				free(tree);
////				printf("\n--- Value %d was deleted ---\n", value);
//				*check=1;
//				return temp;
//			}
//			else if(tree->right==NULL){
//				struct node*temp=tree->left;
//				free(tree);
//				*check=1;
////				printf("\n--- Value %d was deleted ---\n", value);
//				return temp;
//			}

			//VERSI 2
			if(tree->left==NULL || tree->right==NULL){
				struct node*temp=(tree->left)? tree->left:tree->right;
				//No Child
				if(temp==NULL){
					temp=tree;
					tree=NULL;
					free(temp);
					*check=1;
				}
				//One Child
				else{
					
					*tree=*temp;
					free(temp);
					*check=1;
				}
			}
			else{
				//Successor
				struct node*temp=MinValue(tree->right);
				
				tree->data=temp->data;
				
				tree->right=DeleteData(tree->right,temp->data,check);
			
			}		   	 
			
			

			
		}
	}
	
	//LANJUTAN VERSI 2
	if(tree==NULL){
		return tree;
	}
	
	tree->height=1+max(height(tree->left),height(tree->right));
	
	int x=Balance(tree);
	
	
	if(x>1 && Balance(tree->left)>=0){//LL, R Rotate
		return rightRotate(tree);
	}
	if(x>1 && Balance(tree->left)<0){// LR, LR Rotate
		tree->left=leftRotate(tree->left);
		return rightRotate(tree);
	}
	if(x<-1 && Balance(tree->right)<=0){//RR, L Rotate
		return leftRotate(tree);
	}
	if(x<-1 && Balance(tree->right)>0){//RL, RL Rotate
		tree->right=rightRotate(tree->right);
		return leftRotate(tree);
	}
	
	
	return tree;
}

struct node*Insertion(node*tree){
	char input[1000000];

	do{
		printf("Insert: ");fflush(stdin);
		fgets(input,sizeof(input),stdin);
		input[strcspn(input,"\n")]='\0';

	}while(!Validasi(input));
	
	int value=atoi(input);
	
	tree=InsertData(tree,value);
	
	return tree;
}

struct node*Deletion(node*tree){
	char input[1000000];
	int check=0;
	if(tree==NULL){
		puts("\nData is empty!");
		return tree;
	}
	do{
		printf("Delete: ");fflush(stdin);
		fgets(input,sizeof(input),stdin);
		input[strcspn(input,"\n")]='\0';

	}while(!Validasi(input));
	
	int value=atoi(input);
	
	tree=DeleteData(tree,value,&check);
	if(check==1){
		printf("\n--- Value %d was deleted ---\n",value);
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

void Preorder(node*tree){
	if(tree!=NULL){
		printf("%d ",tree->data);
		Preorder(tree->left);
		Preorder(tree->right);
	}
}

void Inorder(node*tree){
	if(tree!=NULL){
		Inorder(tree->left);
		printf("%d ",tree->data);
		Inorder(tree->right);
	}
}

void Postorder(node*tree){
	if(tree!=NULL){
		Postorder(tree->left);
		Postorder(tree->right);
		printf("%d ",tree->data);
	}
}

void Traversal(node*tree){
	if(tree==NULL){
		puts("\nData is empty!");
		return;
	}
	puts("");
	printf("Preorder : ");
	Preorder(tree);
	puts("");
	
	printf("Inorder : ");
	Inorder(tree);
	puts("");
	
	printf("Postorder : ");
	Postorder(tree);
	puts("");
}


int main(){
	struct node*tree=NULL;
	
	
	int choose;

	while(1){
	
		system("cls");
		Menu();
		scanf("%d",&choose);
		
		switch(choose){
			case 1:{
				tree=Insertion(tree);
				puts("");
				system("pause");
				break;
			}
			case 2:{
				tree=Deletion(tree);
				puts("");
				system("pause");
				break;
			}
			case 3:{
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
