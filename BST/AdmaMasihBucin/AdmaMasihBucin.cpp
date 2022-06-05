#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct dnode_t {
    int data;
    int level;
    struct dnode_t      \
        *next,
        *prev;
} DListNode;

/* Struktur ADT Deque */
/* Implementasi didasarkan pada Doubly-Linked List */

typedef struct deque_t {
    DListNode           \
        *_head, 
        *_tail;
    unsigned _size;
} Deque;

/* DAFTAR FUNGSI YANG TERSEDIA */

DListNode* __dlist_createNode(int value,int level);
void deq_init(Deque *deque);
bool deq_isEmpty(Deque *deque);
void deq_pushBack(Deque *deque, int value,int level);

/* Definisi Fungsi */

DListNode* __dlist_createNode(int value,int level)
{
    DListNode *newNode = \
        (DListNode*) malloc (sizeof(DListNode));
    
    if (!newNode) return NULL;
    newNode->data = value;
    newNode->level = level;
    newNode->next = NULL;
    newNode->prev = NULL;

    return (DListNode*) newNode;
}

void deq_init(Deque *deque)
{
    deque->_head = deque->_tail = NULL;
    deque->_size = (unsigned) 0;
}

bool deq_isEmpty(Deque *deque) {
    return (deque->_head == NULL && \
            deque->_tail == NULL);
}

void deq_pushBack(Deque *deque, int value,int level)
{
    DListNode *newNode = __dlist_createNode(value,level);
    if (newNode) {
        deque->_size++;
        if (deq_isEmpty(deque)) {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }

        deque->_tail->next = newNode;
        newNode->prev = deque->_tail;
        deque->_tail = newNode;
    }
}


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

BSTNode* __bst__findMinNode(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    
    return currNode;
}


void __bst__inorder(BST *bst,BSTNode *root,Deque *d) {
    if (root) {
        __bst__inorder(bst,root->left,d);
        deq_pushBack(d,root->key,findlevel(bst->_root,root->key));
        __bst__inorder(bst,root->right,d);
    }
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


/**
 * Binary search tree traversal
 * - Inorder
 * - Postorder
 * - Preorder
 */

void bst_inorder(BST *bst,Deque *d) {
    __bst__inorder(bst,bst->_root,d);
}
 

 int maxDepth(BSTNode * root)
{
  // Root being null means tree doesn't exist.
  if (root == NULL)
    return 0;
  
  // Get the depth of the left and right subtree 
  // using recursion.
  int leftDepth = maxDepth(root->left);
  int rightDepth = maxDepth(root->right);

  // Choose the larger one and add the root to it.
  if (leftDepth > rightDepth)
    return leftDepth + 1;
  else
    return rightDepth + 1;
}

int itdep(Deque *d,int cari){
    DListNode *temp = d->_head;
    while(temp){
        if(temp->level==cari) return temp->data;
        temp=temp->next;
    }
}

int itbac(Deque *d,int cari){
    DListNode *temp = d->_tail;
    while(temp){
        if(temp->level==cari) return temp->data;
        temp=temp->prev;
    }
}

int main()
{
    BST set;
    bst_init(&set);
    Deque d;
    deq_init(&d);
    int n;
    scanf("%d",&n);
    while(n--){
        int temp;
        scanf("%d",&temp);
        bst_insert(&set,temp);
    }
    bst_inorder(&set,&d);
    int depth = maxDepth(set._root);
    int cek = 1;
    for(int i=depth-1;i>=0;i--){
        if(cek){
            printf("%d ",itdep(&d,i));
            cek=0;
        }else{
            printf("%d ",itbac(&d,i));
            cek=1;
        }
    }

    return 0;
}