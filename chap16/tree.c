#include <stdio.h>
#include <stdlib.h>

typedef struct TrNode{
    int data;
    struct TrNode * left;
    struct TrNode * right;
} Node;

void addNode(Node **, Node *);
Node * makeNode(int);
void addNodeRec(Node *, Node *);
void preOrder(Node * root);
void deleteNode(Node ** root, int data);

int main(void){
    Node * root = NULL;
    addNode(&root, makeNode(60));
    addNode(&root, makeNode(120));
    printf("address root points to %p\n", root);
    printf("address left points to %p\n", root->left);
    printf("address right points to %p\n", root->right);
    printf("address of root %p\n", &root);
    root = root->right;
    printf("address root points to %p\n", root);
    printf("address left points to %p\n", root->left);
    printf("address right points to %p\n", root->right);
    printf("address of root %p\n", &root);
    printf("address of right %p\n", &root->right);
    printf("address of left %p\n", &root->left);

    // addNode(&root, makeNode(190));
    // addNode(&root, makeNode(100));

    // preOrder(root);

    // printf("--------------after deleting 190--------------\n");
    // deleteNode(&root, 190);
    // preOrder(root);
    return 0;
}

void addNode(Node ** root, Node * newNode){
    if (*(root) == NULL){
        *(root) = newNode;
        return;
    }
    if ((*root)->data == newNode->data){
        printf("Node with value %d already in tree.\n", newNode->data);
        return;
    }
    addNodeRec(*root, newNode);
}

Node * makeNode(int data){
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void addNodeRec(Node * root, Node * newNode){
    if (newNode->data > root->data){
        if (root->right == NULL){
            root->right = newNode;
        }
        else{
            addNodeRec(root->right, newNode);
        }
    }
    else if (newNode-> data < root->data){
        if (root->left == NULL){
            root->left = newNode;
        }
        else{
            addNodeRec(root->left, newNode);
        }
    }
}

void deleteNode(Node ** root, int data){
    Node * tmp;
    if ((*root)->data > data){
        deleteNode(&(*root)->left, data);
    }
    else if ((*root)->data < data){
        deleteNode(&(*root)->right, data);
    }
    else{

        // case 1: root right subtree is not null but left is null
        if ((*root)->left == NULL){
            tmp = (*root);
            (*root) = (*root)->right;
            free(tmp);
        }

        else if ((*root)->right == NULL){
            tmp = (*root);
            (*root) = (*root)->left;
            free(tmp);
        }
    }
}

void preOrder(Node * root){
    if (root == NULL){
        return;
    }
    printf("%d\n",root->data);
    preOrder(root->left);
    preOrder(root->right);
}