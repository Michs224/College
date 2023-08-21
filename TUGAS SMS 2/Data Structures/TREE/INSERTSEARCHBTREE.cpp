#include <stdio.h>
#include <stdlib.h>

#define MAX 3
#define MIN 2

struct BTreeNode {
  int item[MAX + 1], count;
  struct BTreeNode *linker[MAX + 1];
};

struct BTreeNode *root=NULL;

struct BTreeNode *createNode(int item, struct BTreeNode *child) {
  struct BTreeNode *newNode;
  newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
  newNode->item[1] = item;
  newNode->count = 1;
  newNode->linker[0] = root;
  newNode->linker[1] = child;
  return newNode;
}

void addValToNode(int item, int pos, struct BTreeNode *node,struct BTreeNode *child) {
  int j = node->count;
  while (j > pos) {
    node->item[j + 1] = node->item[j];
    node->linker[j + 1] = node->linker[j];
    j--;
  }
  node->item[j + 1] = item;
  node->linker[j + 1] = child;
  node->count++;
}

void splitNode(int item, int *pval, int pos, struct BTreeNode *node,struct BTreeNode *child, struct BTreeNode **newNode) {
  int median, j;
//	printf("pos %d\n",pos);
  if (pos > MIN)
    median = MIN + 1;
  else
    median = MIN;
  *newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
  j = median + 1;
  while (j <= MAX) {
    (*newNode)->item[j - median] = node->item[j];
    (*newNode)->linker[j - median] = node->linker[j];
    j++;
  }
  node->count = median;
  (*newNode)->count = MAX - median;
	
	printf("item, pos - median: %d %d\n",item,pos-median);
  if (pos <= MIN) {
    addValToNode(item, pos, node, child);
  } else {
  	
    addValToNode(item, pos - median, *newNode, child);
  }
  *pval = node->item[node->count];
  (*newNode)->linker[0] = node->linker[node->count];
  node->count--;
}

int setValueInNode(int item, int *pval,struct BTreeNode *node, struct BTreeNode **child) {
  int pos;
  if (node==NULL) {
    *pval = item;
    *child = NULL;
    return 1;
  }

  if (item < node->item[1]) {
    pos = 0;
  } else {
  	pos=node->count;
  	while(item<node->item[pos] && pos > 1)pos--;

//    for (pos = node->count;(item < node->item[pos] && pos > 1); pos--);
//    printf("Pos: %d\n",pos);
    if (item == node->item[pos]) {
      printf("Duplicates not allowed\n");
      return 0;
    }
  }
  if (setValueInNode(item, pval, node->linker[pos], child)) {
//  	printf("count: %d, item: %d\n",node->count,item);
    if (node->count < MAX) {
      addValToNode(*pval, pos, node, *child);
    } else {
      splitNode(*pval, pval, pos, node, *child, child);
      return 1;
    }
  }
  return 0;
}


void insertion(int item) {
  int flag, i;
  struct BTreeNode *child;

  flag = setValueInNode(item, &i, root, &child);
//  printf("Flag: %d\n",flag);
  if (flag==1)
    root = createNode(i, child);
}


void searching(int item, int *pos, struct BTreeNode *myNode) {
  if (myNode==NULL) {
    return;
  }

  if (item < myNode->item[1]) {
    *pos = 0;
  } else {
//  	printf("count: %d\n",myNode->count);
//  	system("pause");
    for (*pos = myNode->count;(item < myNode->item[*pos] && *pos > 1); (*pos)--);
    
    if (item == myNode->item[*pos]) {
      printf("%d present in B-tree\n", item);
      return;
    }
  }
  searching(item, pos, myNode->linker[*pos]);
  return;
}


void Preorder(struct BTreeNode *myNode) {
  int i;
  if (myNode!=NULL) {
    for (i = 0; i < myNode->count; i++) {
	printf("%d ", myNode->item[i + 1]);
      Preorder(myNode->linker[i]);
      
    }
    Preorder(myNode->linker[i]);
  }
}

void Inorder(struct BTreeNode *myNode) {
  int i;
  if (myNode!=NULL) {
    for (i = 0; i < myNode->count; i++) {
      Inorder(myNode->linker[i]);
	  printf("%d ", myNode->item[i + 1]);
      
    }
    Inorder(myNode->linker[i]);
  }
}

void Postorder(struct BTreeNode *myNode) {
  if (myNode != NULL) {
    int i;
    for (i = 0; i < myNode->count; i++) {
      Postorder(myNode->linker[i]);
    }
    Postorder(myNode->linker[i]);
    for (i = 1; i <= myNode->count; i++) {
      printf("%d ", myNode->item[i]);
    }
  }
}

void Traversal(struct BTreeNode *myNode){
	printf("Preorder: ");
	Preorder(root);
	puts("");
	
	printf("Inorder: ");
	Inorder(root);
	puts("");
	
	printf("Postorder: ");
	Postorder(root);
	puts("");
	
}

int main() {
  int item, ch;

  insertion(8);
  insertion(10);
  insertion(12);
 insertion(11);
//  insertion(15);
//
//  insertion(17);


  Traversal(root);
  puts("");
	searching(8,&ch,root);
	searching(11,&ch,root);
	searching(15,&ch,root);
  
}
