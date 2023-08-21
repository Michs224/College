#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node {
    char code[6];
    int price;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(char code[], int price) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->code, code);
    newNode->price = price;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertPhone(Node* root, char code[], int price) {
    if (root != NULL && root->left != NULL && root->right != NULL) {
        printf("--- Maximum Tree Level is 4 ---\n");
        return root;
    }
    
    if (root == NULL) {
        printf("--- Add New Phone Success ---\n");
        return createNode(code, price);
    }

    if (strcmp(code, root->code) == 0) {
        printf("--- Add New Phone Failure ---\n");
        printf("Err : Phone Code Already Exists\n");
        return root;
    }

    if (strcmp(code, root->code) < 0)
        root->left = insertPhone(root->left, code, price);
    else
        root->right = insertPhone(root->right, code, price);

    return root;
}

Node* searchPhone(Node* root, char code[]) {
    if (root == NULL || strcmp(code, root->code) == 0)
        return root;
    
    if (strcmp(code, root->code) < 0)
        return searchPhone(root->left, code);
    
    return searchPhone(root->right, code);
}

void updatePhonePrice(Node* root, char code[], int newPrice) {
    Node* phone = searchPhone(root, code);
    if (phone != NULL) {
        printf("--- Update Phone Price Success ---\n");
        printf("\n");
        phone->price = newPrice;
    } else {
        printf("--- Phone Code is Not Found ---\n");
    }
}

void printPhone(Node* phone) {
    printf("- %s [$ %d]\n", phone->code, phone->price);
}

void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printPhone(root);
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(Node* root) {
    if (root != NULL) {
        printPhone(root);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printPhone(root);
    }
}

void deleteTree(Node* root) {
    if (root == NULL)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

int main() {
    Node* root = NULL;

    int menu;
    char code[6];
    int price, newPrice;

    do {
    	printf("\n");
        printf("NOKIYEM CELULLAR PHONE\n");
        printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
        printf(" \n");
        printf("1. Add New Phone\n");
        printf("2. Update Phone Price\n");
        printf("3. InOrder, PreOrder, PostOrder\n");
        printf("4. Exit\n");
        printf(" \n");
		printf(">> Input choice : ");
        scanf("%d", &menu);
        printf("\n\n");

        switch (menu) {
            case 1: {
			    while (1) {
			        printf("Input Phone Code (N[1-9][0-9][0-9][0-9]): ");
			        scanf("%s", code);
			
			        if (strlen(code) != 5 || code[0] != 'N' || code[1] < '1' || code[1] > '9' || code[2] < '0' || code[2] > '9' || code[3] < '0' || code[3] > '9' || code[4] < '0' || code[4] > '9') 
			        {
			            printf("Invalid phone code. Please enter a valid phone code (N1000 - N9999).\n");
			            continue;
			        }
			
			        while (1) {
			            printf("Input Phone Price ($50 - $999): $ ");
			            scanf("%d", &price);
			
			            if (price < 50 || price > 999) {
			                printf("Invalid phone price. Please enter a valid phone price ($50 - $999).\n");
			                continue;
			            }
			
			            root = insertPhone(root, code, price);
			            break;
			        }
			
			        break;
			    }
			    break;
			}
            case 2: {
			    while (1) {
			        printf("Enter phone code to update price: ");
			        scanf("%s", code);
			
			        if (strlen(code) != 5 || code[0] != 'N' || code[1] < '1' || code[1] > '9' || code[2] < '0' || code[2] > '9' || code[3] < '0' || code[3] > '9' || code[4] < '0' || code[4] > '9') {
			            printf("Invalid phone code. Please enter a valid phone code (N1000 - N9999).\n");
			        } else {
			            Node* phoneToUpdate = searchPhone(root, code);
			            if (phoneToUpdate != NULL) {
			                printf("Phone Code\t: %s\n", phoneToUpdate->code);
			                printf("Phone Price\t: $%d\n", phoneToUpdate->price);
			
			                while (1) {
			                    printf("Enter new phone price ($50 - $999): ");
			                    scanf("%d", &newPrice);
			
			                    if (newPrice < 50 || newPrice > 999) {
			                        printf("Invalid phone price. Please enter a valid phone price ($50 - $999).\n");
			                    } else {
			                        updatePhonePrice(root, code, newPrice);
			                        break;
			                    }
			                }
			            } else {
			                printf("--- Phone Code is Not Found ---\n");
			            }
			            break;
			        }
			    }
			    break;
			}
		

            case 3:
                if (root == NULL) {
                    printf("--- There is No Phone in The Tree ---\n");
                } else {
                    printf("-- InOrder Traversal --\n");
                    inOrderTraversal(root);

                    printf("\n-- PreOrder Traversal --\n");
                    preOrderTraversal(root);

                    printf("\n-- PostOrder Traversal --\n");
                    postOrderTraversal(root);

                    printf("\n");
                }
                break;
            case 4:
                deleteTree(root);
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (menu != 4);

    return 0;
}
