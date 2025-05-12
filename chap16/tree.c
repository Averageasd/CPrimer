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
void deleteAllNodesPostOrder(Node **);

int main(void){
    Node * root = NULL;
    addNode(&root, makeNode(40));
    addNode(&root, makeNode(30));
    addNode(&root, makeNode(150));
    addNode(&root, makeNode(160));
    addNode(&root, makeNode(110));
    preOrder(root);

    printf("after deleteing all nodes :\n");
    deleteAllNodesPostOrder(&root);
    preOrder(root);

    printf("now add a bunch of nodes to rebuild the tree:\n");
    addNode(&root, makeNode(60));
    addNode(&root, makeNode(250));
    addNode(&root, makeNode(170));
    addNode(&root, makeNode(45));
    addNode(&root, makeNode(59));
    preOrder(root);
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
    Node * minRight;
    int tmpMinRightData;
    if ((*root)->data > data){
        deleteNode(&(*root)->left, data);
    }
    else if ((*root)->data < data){
        deleteNode(&(*root)->right, data);
    }
    else{

        // case 1: root right subtree is not null but left is null
        // point parent of root to right
        if ((*root)->left == NULL){
            tmp = (*root);
            (*root) = (*root)->right;
            free(tmp);
        }

        // case 2: root right subtree is null but left is not null.
        // point parent of root to left
        else if ((*root)->right == NULL){
            tmp = (*root);
            (*root) = (*root)->left;
            free(tmp);
        }

        // case 3: node you want to delete has both left and right subtrees
        // 
        else{
            minRight = (*root)->right;
            while (minRight != NULL && minRight->left != NULL){
                minRight = minRight->left;
            }
            tmpMinRightData = minRight->data;
            minRight->data = (*root)->data;
            (*root)->data = tmpMinRightData;
            deleteNode(&(*root)->right, minRight->data);

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

void deleteAllNodesPostOrder(Node ** root){
    if ((*root) == NULL){
        return;
    }

    // traverse 
    deleteAllNodesPostOrder(&(*root)->left);
    deleteAllNodesPostOrder(&(*root)->right);
    deleteNode(root,(*root)->data);
}