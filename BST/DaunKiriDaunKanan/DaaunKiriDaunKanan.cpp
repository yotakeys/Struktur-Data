#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100000
int count = 0;

typedef struct bstnode_t {
    int key;
    struct bstnode_t *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode* __bst__createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value) {
    if (root == NULL) 
        return __bst__createNode(value);
    if (value < root->key)
        root->left = __bst__insert(root->left, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);
    
    return root;
}

BSTNode* __bst__search(BSTNode *root, int value) {
    while (root != NULL) {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

BSTNode* __bst__findMinNode(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    
    return currNode;
}

BSTNode* __bst__remove(BSTNode *root, int value) {
    if (root == NULL) return NULL;

    if (value > root->key) 
        root->right = __bst__remove(root->right, value);
    else if (value < root->key) 
        root->left = __bst__remove(root->left, value);
    else {
        
        if (root->left == NULL) {
            BSTNode *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL) {
            BSTNode *leftChild = root->left;
            free(root);
            return leftChild;
        }

        BSTNode *temp = __bst__findMinNode(root->right);
        root->key     = temp->key;
        root->right   = __bst__remove(root->right, temp->key);
    }
    return root;
}

void __bst__postorder(BSTNode *root) {
    if (root) {
        __bst__postorder(root->left);
        __bst__postorder(root->right);
        printf("%d ", root->key);
        count++;
    }
}

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool bst_find(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

void bst_remove(BST *bst, int value) {
    if (bst_find(bst, value)) {
        bst->_root = __bst__remove(bst->_root, value);
        bst->_size--;
    }
}

int main()
{
    BST set;
    bst_init(&set);
    int t, x, space = 0;
    char str[20], cek[20];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", str);
        if(!strcmp(str, "isi"))
        {
            scanf("%d", &x);
            if(x > 0)
                bst_insert(&set, x);
        }
        else{
            if(space > 0)
                printf("==============================\n");
            scanf("%s", cek);
            if(set._root == NULL)
            {
                printf("Isi dulu dong @_@\n");
            }
            else if(set._root->right == NULL && set._root->left == NULL)
            {
                printf("Belum tumbuh nih %dnya :(\n", set._root->key);
            }
            else{
                printf("     left : ");
                __bst__postorder(set._root->left);
                if(!count)
                    printf("Kok gk tumbuh yah :<");
                count = 0;
                printf("\n");
                printf("root: %d\n", set._root->key);
                printf("     right: ");
                __bst__postorder(set._root->right);
                if(!count)
                    printf("Kok gk tumbuh yah :<");
                count = 0;
                printf("\n");
            }
            space++;
        }
    }
}