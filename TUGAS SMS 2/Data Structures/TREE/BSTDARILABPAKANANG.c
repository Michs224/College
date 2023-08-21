#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *left, *right;
};

struct Node *newNode(int value) {
	struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
	
	temp->data = value;
	temp->left = temp->right = NULL;
	return temp;
}

struct Node *insert(struct Node *node, int value) {
	if(node == NULL) {
		return newNode(value);
	} else {
		if(value < node->data) {
			node->left = insert(node->left, value);
		} else {
			node->right = insert(node->right, value);
		}
	}
	
	return node;
}

void preorder(struct Node *node) {
	if(node != NULL) {
		printf("%d ", node->data);
		preorder(node->left);
		preorder(node->right);
	}
}

void inorder(struct Node *node) {
	if(node != NULL) {
		inorder(node->left);
		printf("%d ", node->data);
		inorder(node->right);
	}
}

void postorder(struct Node *node) {
	if(node != NULL) {
		postorder(node->left);
		postorder(node->right);
		printf("%d ", node->data);
	}
}

struct Node *minValue(struct Node *node) {
	struct Node *current = node;
	
	while(current && current->left != NULL) {
		current = current->left;
	}
	printf("Node : %d\n", current->data);
	
	return current;
}

struct Node *deleteNode(struct Node *node, int value) {
	
	if(node == NULL) {
		return node;
	}
	
	if(value < node->data) {
		node->left = deleteNode(node->left, value);
	} else if(value > node->data) {
		node->right = deleteNode(node->right, value);
	} else {
		if(node->left == NULL) {
			struct Node *temp = node->right;
			free(node);
			return temp;
		} else if(node->right == NULL) {
			struct Node *temp = node->left;
			free(node);
			return temp;
		}
	
		struct Node *temp = minValue(node->right);
		
		node->data = temp->data;
		node->right = deleteNode(node->right, temp->data);
	}
	
	return node;
}
//11 7 2 4 9 8 10 15 14
//2 4 7 8 9 10 11 14 15
int main() {
	struct Node *root = NULL;
	root = insert(root, 4);
	root = insert(root, 8);
	root = insert(root, 7);
//	root = insert(root, 10);
//	root = insert(root, 8);
//	root = insert(root, 15);
//	root = insert(root, 2);
//	root = insert(root, 4);
//	root = insert(root, 14);
	
//	printf("Preorder : ");
//	preorder(root);
//	printf("\nInorder : ");
//	inorder(root);
//	printf("\nPostorder : ");
//	postorder(root);

	root = deleteNode(root, 11);
	printf("Preorder : ");
	preorder(root);
	printf("\nInorder : ");
	inorder(root);
	return 0;
}
