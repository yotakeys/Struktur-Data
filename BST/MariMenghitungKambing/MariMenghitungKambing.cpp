#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * Node structure and
 * uniqueBST structure
 */

typedef struct bstnode_t {
    int key;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

/**
 * !!! WARNING UTILITY FUNCTION !!!
 * Recognized by prefix "__bst__"
 * ---------------------------------------------
 * Note that you better never access these functions, 
 * unless you need to modify or you know how these functions work.
 */

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

bool flag = false;
void cariSapi(BSTNode*, int);

int main()
{
    BST set;
    bst_init(&set);
    int n, x, cek;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        bst_insert(&set, x);
    }
    scanf("%d", &cek);
    cariSapi(set._root, cek);
    if(!flag)
        printf("HAiiyyaAhh SalAhh");
}

void cariSapi(BSTNode* root, int value)
{
    int tmp;
    if(root != NULL)
    {
        tmp = 0;
        // segitiga
        tmp += root->key;
        if(root->left != NULL) tmp += root->left->key;
        if(root->right != NULL) tmp += root->right->key;
        
        if(tmp == value)
        {
            flag = true;
            printf("ManTap");
            return;
        }
        
        // kiri kiri
        tmp = 0;
        tmp += root->key;
        if(root->left != NULL) tmp += root->left->key;
        if(root->left != NULL && root->left->left != NULL) tmp += root->left->left->key;
        
        if(tmp == value)
        {
            flag = true;
            printf("ManTap");
            return;
        }
        
        // kanan kanan
        tmp = 0;
        tmp += root->key;
        if(root->right != NULL) tmp += root->right->key;
        if(root->right != NULL && root->right->right != NULL) tmp += root->right->right->key;
        
        if(tmp == value)
        {
            flag = true;
            printf("ManTap");
            return;
        }
        
        // kanan kiri
        tmp = 0;
        tmp += root->key;
        if(root->right != NULL) tmp += root->right->key;
        if(root->right != NULL&& root->right->left != NULL) tmp += root->right->left->key;
        
        if(tmp == value)
        {
            flag = true;
            printf("ManTap");
            return;
        }
        
        // kiri kanan
        tmp = 0;
        tmp += root->key;
        if(root->left != NULL) tmp += root->left->key;
        if(root->left != NULL && root->left->right != NULL) tmp += root->left->right->key;
        
        if(tmp == value)
        {
            flag = true;
            printf("ManTap");
            return;
        }
    }
    if(root->right != NULL) cariSapi(root->right, value);
    if(root->left != NULL) cariSapi(root->left, value);
}