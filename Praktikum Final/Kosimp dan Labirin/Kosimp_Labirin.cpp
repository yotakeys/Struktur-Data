
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int minpath=100000;
/**
 * Node structure and
 * uniqueBST structure
 */

typedef struct bstnode_t {
    int key;
    int dist;
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

BSTNode* __bst__createNode(int value,int dist) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->dist = dist;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value,int dist) {
    if (root == NULL) 
        return __bst__createNode(value,dist);

    if (value < root->key)
        root->left = __bst__insert(root->left, value,dist);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value,dist);
    
    return root;
}

/**
 * PRIMARY FUNCTION
 * ---------------------------
 * Accessible and safe to use.
 */

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

bool bst_find(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

void bst_insert(BST *bst, int value,int dist) {
    if(!bst_find(bst,value)){
        bst->_root = __bst__insert(bst->_root, value,dist);
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
            jrk+=root->dist;
        }
            
        else if (value > root->key){
            root = root->right;
            jrk+=root->dist;
        }
        else
            return jrk;
    }
    return jrk;
}

void __bst__preorder(BST *bst,BSTNode *root,int cari) {
    if (root) {
        if(root->left == NULL&&root->right == NULL){
            BSTNode *temp = lca(bst->_root,root->key,cari);
            int now = findjrk(temp,cari) + findjrk(temp,root->key);
            if(now<minpath) minpath=now;
        }
        __bst__preorder(bst,root->left,cari);
        __bst__preorder(bst,root->right,cari);
    }
}

void bst_preorder(BST *bst,int value) {
    __bst__preorder(bst,bst->_root,value);
}

 
int main()
{
    BST set;
    bst_init(&set);
    int n,kota,jrk;
    int tny;
    int t;
    scanf("%d",&n);
    scanf("%d",&kota);
    bst_insert(&set,kota,0);
    for(int i=0;i<n-1;i++){
        scanf("%d %d",&kota,&jrk);
        bst_insert(&set,kota,jrk);
    }
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d",&tny);
        if(bst_find(&set,tny)){
        bst_preorder(&set,tny);
        printf("%d\n",minpath);
        minpath=100000;
        }else{printf("0\n");}
    }
    return 0;
}