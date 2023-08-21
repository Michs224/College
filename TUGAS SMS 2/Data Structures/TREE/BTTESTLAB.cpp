#include <stdio.h>
#include <stdlib.h>

struct node{
	int value;
	struct node*left,*right;
};


struct node*head=NULL;

struct node*newnode(int data){
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	temp->value=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}


struct node*insert(struct node*root,int data,char position){
	
	if(root==NULL){
		return newnode(data);
	}
	
//	if(position=='l'){
//		if(root->left==NULL){
//			root->left=newnode(data);
//			return root;
//		}
//		while(root->left!=NULL){
//			if(data < root->left->value){
//					root->left->left=insert(root->left->left,data,'l');
//			}else{
//				root->right->right=insert(root->right->right,data,'r');
//			}
//		}
//	
//	}
//	else if(position=='r'){
//		if(root->right==NULL){
//			root->right=newnode(data);
//			return root;
//		}
//		while(root->right!=NULL){
//			if(data > root->right->value){
//				root->right->right=insert(root->right->right,data,'r');
//				
//			}else{
//				root->left->left=insert(root->left->left,data,'l');
//	
//			}
//			
//		}
//		
//		
//	}
	else{
		if(position=='l'){
		if(data<root->value){
			root->left=insert(root->left,data,'l');
		}
		else if(data>root->value){
			root->right=insert(root->right,data,'r');
		}			
		}
		
		else if(position=='r'){
		if(data<root->value){
			root->left=insert(root->left,data,'l');
		}
		else if(data>root->value){
			root->right=insert(root->right,data,'r');
		}			
		}
		return root;
		}

	
	
}

struct node* insertpertama(struct node*root,int data,char position){
	if(position==' '){
		root=insert(root,data,position);
	}
	else if(position=='l'){
		root->left=insert(root->left,data,position);
	}
	else if(position=='r'){
		root->right=insert(root->right,data,position);
	}
	return root;
}

void displaypreorder(struct node*root){

	if(root!=NULL){
			printf("%d ",root->value);
			displaypreorder(root->left);
			displaypreorder(root->right);
	}
		
}
void displayinorder(struct node*root){

	if(root!=NULL){
			displayinorder(root->left);
			printf("%d ",root->value);
			
			displayinorder(root->right);
	}
		
}
void displaypostorder(struct node*root){

	if(root!=NULL){
			displaypostorder(root->left);
			displaypostorder(root->right);
			printf("%d ",root->value);
	}
		
}

int main(){
	struct node*root=NULL;
	int value;
	char position;
	
	root=insertpertama(root,10,' ');
	root=insertpertama(root,7,'l');
	root=insertpertama(root,9,'l');
	root=insertpertama(root,6,'l');
	root=insertpertama(root,100,'r');
	root=insertpertama(root,100,'r');
	root=insertpertama(root,100,'r');
	printf("Preorder: ");
	displaypreorder(root);
	puts("");
	
	printf("Inorder: ");
	displayinorder(root);
	puts("");
	
	printf("Postorder: ");
	displaypostorder(root);
	puts("");
	return 0;
}
