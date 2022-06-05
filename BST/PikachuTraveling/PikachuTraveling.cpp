
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
/**
 * PRIMARY FUNCTION
 * ---------------------------
 * Accessible and safe to use.
 */

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

BSTNode *lca(BSTNode* root, int n1, int n2)
{
    while (root != NULL)
    {

        if (root->key > n1 && root->key > n2)
        root = root->left;
 
        else if (root->key < n1 && root->key < n2)
        root = root->right;
 
        else break;
    }
    return root;
}

int findjrk(BSTNode *root, int value) {
    int jrk=0;
    while (root != NULL) {
        if (value < root->key){
            root = root->left;
            jrk++;
        }
            
        else if (value > root->key){
            root = root->right;
            jrk++;
        }
        else
            return jrk;
    }
    return jrk;
}
 
int main()
{
    BST set;
    bst_init(&set);
    int n;
    scanf("%d",&n);
    while(n--){
        int temp;
        scanf("%d",&temp);
        bst_insert(&set,temp);
    }
    scanf("%d",&n);
    while(n--){
        int n1,n2;
        scanf("%d %d",&n1,&n2);
        BSTNode *buyut = lca(set._root,n1,n2);
        printf("%d\n",findjrk(buyut,n1)+findjrk(buyut,n2));
    }
    return 0;
}