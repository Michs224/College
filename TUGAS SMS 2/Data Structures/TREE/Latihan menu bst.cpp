#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
//AKU HACKER 
struct node{
	char pcode[10];
	int price;
	struct node*left,*right;
	
};

//node*tree=NULL;

struct node*newnode(node*tree,char phonecode[10],int price){
	node*temp=(struct node*)malloc(sizeof(struct node));
	temp->price=price;
	strcpy(temp->pcode,phonecode);
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

struct node*search(node*tree,char phonecode[10]){
	if(tree==NULL || strcmp(phonecode,tree->pcode)==0){
		return tree;
	}
	if(strcmp(phonecode,tree->pcode)<0){
		return search(tree->left,phonecode);
	}
	else if(strcmp(phonecode,tree->pcode)>0){
		return search(tree->right,phonecode);
	}
	
}
struct node*insert(node*tree,char phonecode[10],int price,int level){
	
	if(tree==NULL){
		printf("---Add New Phone Success---\n");
		return newnode(tree,phonecode,price);
	}
//	if(strcmp(tree->pcode,phonecode)==0){
//		printf("---Add New Phone Failure---\n");
//		printf("""Err : Phone Code Already Exists\n""");
//		return tree;
//	}
	if(level==4){
		printf("---Maximum Tree Level is 4---\n");
		return tree;
	}
	else{
		if(strcmp(phonecode,tree->pcode)<0){
		tree->left=insert(tree->left,phonecode,price,++level);
		}
		else if(strcmp(phonecode,tree->pcode)>0){
		tree->right=insert(tree->right,phonecode,price,++level);
		}
		else if(strcmp(tree->pcode,phonecode)==0){
		printf("---Add New Phone Failure---\n");
		printf("""Err : Phone Code Already Exists\n""");
		}	
	}
	return tree;
}

bool pcodevalid(char phonecode[10]){
	int check=0;
	for(int i=1;i<strlen(phonecode);i++){
		if(i==1 && phonecode[i]>='1' && phonecode[i]<='9')check++;
		else if(i!=1 && phonecode[i]>='0' && phonecode[i]<='9')check++;
	}
	if(check==4)return true;
	else return false;
}

struct node*Add(node*tree){
	char phonecode[10];
	int price;
	
	do{
		printf("Input Phone Code N[1-9][0-9][0-9][0-9]: ");
		fflush(stdin);
		gets(phonecode);
//		printf("%s %d\n",phonecode,strlen(phonecode));
//		system("pause");
	}while(!pcodevalid(phonecode));
	
	do{
		printf("Input Phone Price [$50..$999]: $");
		scanf("%d",&price);
		
	}while(price<50 || price >999);
	
	tree=insert(tree,phonecode,price,0);
	system("pause");
	system("cls");
	return tree;
}

struct node *deleteall(node*tree){
	if(tree==NULL){
		return NULL;
		
	}
	
	tree->left=deleteall(tree->left);
	tree->right=deleteall(tree->right);
	free(tree);		
	
	return NULL;
}

int isempty(node*tree,int jlh){
	
	if(tree==NULL){
		return jlh;
	}else{
		isempty(tree->left,jlh++);
		isempty(tree->right,jlh++);
	}
	return jlh;

}

struct node*minValue(struct node *tree){
	struct node*temp=tree;
	while(temp->left!=NULL){
		temp=temp->left;
	}
	return temp;
}

struct node *deletee(struct node *tree,char phonecode[10]){
	
	struct node*cur,*parent,*suc,*psuc,*ptr;
	if(tree==NULL){
		return tree;
	}
	if(strcmp(phonecode,tree->pcode)<0){
		tree->left=deletee(tree->left,phonecode);
	}
	else if(strcmp(phonecode,tree->pcode)>0){
		tree->right=deletee(tree->right,phonecode);
	}
	else{
		if(tree->left==NULL){
			struct node*temp;
			temp=tree->right;
			free(tree);
			return temp;
		}
		else if(tree->right==NULL){
			struct node*temp;
			temp=tree->left;
			free(tree);
			return temp;
		}
		struct node *temp=minValue(tree->right);
		strcpy(tree->pcode,temp->pcode);
		tree->price=temp->price;
//		tree->data=temp->data;
		tree->right=deletee(tree->right,temp->pcode);
	}
	return tree;
}

struct node*Delete(node*tree){
	char phonecode[10];
	int price;
	
	do{
		printf("Input Phone Code N[1-9][0-9][0-9][0-9]: ");
		fflush(stdin);
		gets(phonecode);
//		printf("%s %d\n",phonecode,strlen(phonecode));
//		system("pause");
	}while(!pcodevalid(phonecode));
	
	tree=deletee(tree,phonecode);
}

void Postorder(node*tree){
	
	if(tree!=NULL){
		Postorder(tree->left);
		Postorder(tree->right);
		printf("- %s [ $ %d ]\n",tree->pcode,tree->price);
	}

}

void Preorder(node*tree){
	
	if(tree!=NULL){
		printf("- %s [ $ %d ]\n",tree->pcode,tree->price);
		Preorder(tree->left);
		Preorder(tree->right);
		
	}
}

void Inorder(node*tree){
	
	if(tree!=NULL){
		Inorder(tree->left);
		printf("- %s [ $ %d ]\n",tree->pcode,tree->price);
		Inorder(tree->right);
		
	}
}

struct node*Update(node*tree){
	char phonecode[10];
	int price;
	do{
		printf("Input Phone Code N[1-9][0-9][0-9][0-9]: ");
		fflush(stdin);
		gets(phonecode);
//		printf("%s %d\n",phonecode,strlen(phonecode));
//		system("pause");
	}while(!pcodevalid(phonecode));
	
	node*temp=search(tree,phonecode);
	if(tree==NULL){
		printf("---Phone Code is Not Found---\n");
	}
	else{
		printf("Phone Code		: %s\n",temp->pcode);
		printf("Phone Price		: $ %d\n",temp->price);
		
		do{
		printf("Input Phone Price [$50..$999]: $");
		scanf("%d",&price);
		
		}while(price<50 || price >999);
		temp->price=price;
		
		printf("\n---- Update Phone Price Success ---\n");
	}
	return tree;
}

int main(){
	node*tree=NULL;
	int choose;
	
	do{
		printf("NOKIYEM CELLULAR PHONE\n");
		printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n");
		printf("1. Add New Phone\n2. Update Phone Price\n3. Delete Phone\n4. InOrder, PreOrder, PostOrder\n5. Exit\n\n>> Input choice : ");
		scanf("%d",&choose);
		
		switch(choose){
			case 1:{
				tree=Add(tree);
				break;
			}
			case 2:{
				tree=Update(tree);
				system("pause");
				system("cls");
				break;
			}
			case 3:{
				tree=Delete(tree);
				system("pause");
				system("cls");
				break;
			}
			case 4:{
				if(tree==NULL){
					printf("--- There is No Phone in The Tree ---\n");
				}else{
				printf("Preorder:\n");
				Preorder(tree);
				puts("\n");
				printf("Inorder:\n");
				Inorder(tree);
				puts("\n");
				printf("Postorder:\n");
				Postorder(tree);
				puts("\n");					
				}
				system("pause");
				system("cls");

				break;
			}
		}
	}while(choose!=5);
	
	tree=deleteall(tree);
//	int jlh=0;
//	int x=isempty(tree,jlh);
//	
//	if(x==0){
//		printf("NULL\n");
//	}else{
//		printf("Masih ada\n");
//	}
//	system("pause");
	return 0;
}
