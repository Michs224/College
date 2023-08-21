#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct 	node*left,*right;
	int height;
};

struct node *newnode(int data){
struct  node*temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	temp->height=1;
	return temp;
}

int height(node*tree){
	if(tree==NULL){
		return 0;
	}
	
	return tree->height;
}

int max(int left, int right){
	return (left>right) ? left : right;
}

int getBalance(node* tree){
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
	
	tree->height = 1+ max(height(tree->left),height(tree->right));
	
	mid->height = 1+ max(height(mid->left),height(mid->right));
	return mid;
}

struct node*rightRotate(node*tree){
	struct node*mid=tree->left;
	struct node*bottom=mid->right;
	mid->right=tree;
	tree->left=bottom;
	
	tree->height = 1+ max(height(tree->left),height(tree->right));
	mid->height = 1+ max(height(mid->left),height(mid->right));
	return mid;
}


struct node *create(node*tree,int data){
	if(tree==NULL){
		return newnode(data);
	}
	else{
		if(data<tree->data){
			tree->left=create(tree->left,data);
		}
		else if(data>tree->data){
			tree->right=create(tree->right,data);
		}
		else{
			return tree;
		}
	}
	
	tree->height=1 +max(height(tree->left),height(tree->right));
	int balance=getBalance(tree);
	// Left rotate
	if(balance<-1 && data > tree->right->data){
	tree=leftRotate(tree);	
	}

	// Right rotate
	else if(balance>1 && data < tree->left->data){
		tree=rightRotate(tree);	
	}
	// Left Right Rotate
	else if(balance>1 && data > tree->left->data){
		tree->left=leftRotate(tree->left);
		tree=rightRotate(tree);
	}
	
	// Right Left rotate
	
	else if(balance<-1 && data < tree->right->data){
		tree->right=rightRotate(tree->right);
		tree=leftRotate(tree);
	}
	
	
	return tree;
	
}


void display(node*tree){
	if(tree!=NULL){
		display(tree->left);
		printf("%d ",tree->data);
		display(tree->right);
	}
	
	
}

void displayheightpreorder(node*tree){
	if(tree!=NULL){
	printf("%d ",tree->height);
		displayheightpreorder(tree->left);
		displayheightpreorder(tree->right);
	}
	
	
}

void displaypreorder(node*tree){
	if(tree!=NULL){
		printf("%d ",tree->data);
		displaypreorder(tree->left);
		displaypreorder(tree->right);
	}
	
	
}

int main(){
	struct node*tree=NULL;
	tree=create(tree,4);
	tree=create(tree,8);
	tree=create(tree,7);
//	tree=create(tree,20);
//	tree=create(tree,18);
	
	printf("Display : ");
	displayheightpreorder(tree);
	puts("");
	displaypreorder(tree);

	
	return 0;
}
