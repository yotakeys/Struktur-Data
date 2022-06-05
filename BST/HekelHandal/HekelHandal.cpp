#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
/**
 * Node structure and
 * uniqueBST structure
 */

int maxlev=0;

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

int findlevel(BSTNode *root, int value) {
    int level=0;
    while (root != NULL) {
        if (value < root->key){
            root = root->left;
            level++;
        }
        else if (value > root->key){
            root = root->right;
            level++;
        }
        else
            return level;
    }
    return level;
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

int bst_insert(BST *bst, int value) {
    int level = findlevel(bst->_root,value);
    if(level>maxlev)maxlev=level;
    if (level>=0) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
        return level;
    }
    return level;
}


int main()
{
    BST set;
    bst_init(&set);
    int n;
    scanf("%d",&n);
    int MAX=100000;
    long long int arr[MAX];
    memset(arr,0,sizeof(arr));
    while(n--){
        int cmd,value;
        scanf("%d %d",&cmd,&value);
        if(cmd==1){
            arr[bst_insert(&set,value)]+=value;
        }
        else{
            if(value>maxlev)printf("GG EZ\n");
            else{
                printf("Level %d: %llu\n",value,arr[value]);
            }
        }
        
    }

    return 0;
}