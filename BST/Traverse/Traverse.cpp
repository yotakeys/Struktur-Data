#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int count=0;

typedef struct pqueueNode_t {
    int data;
    int jml;
    int level;
    struct pqueueNode_t *next;
} PQueueNode;

/* Struktur ADT PriorityQueue menggunakan Linked List */

// Prioritas default: nilai minimum
typedef struct pqueue_t {
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;

/* Function prototype */

void pqueue_init(PriorityQueue *pqueue);
bool pqueue_isEmpty(PriorityQueue *pqueue);
void pqueue_push(PriorityQueue *pqueue, int value,int level,int jml);
void pqueue_pop(PriorityQueue *pqueue);
int  pqueue_top(PriorityQueue *pqueue);

/* Function definition below */

void pqueue_init(PriorityQueue *pqueue)
{
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

bool pqueue_isEmpty(PriorityQueue *pqueue) {
    return (pqueue->_top == NULL);
}

void pqueue_push(PriorityQueue *pqueue, int value,int level,int jml)
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode = \
        (PQueueNode*) malloc (sizeof(PQueueNode));
    newNode->data = value;
    newNode->level = level;
    newNode->jml = jml;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }

    if (level < pqueue->_top->level) {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else {
        while ( temp->next != NULL && 
                temp->next->level <= level)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void pqueue_pop(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue)) {
        PQueueNode *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}

int pqueue_top(PriorityQueue *pqueue) {
    if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->data;
    else return 0;
}

/**
 * Node structure and
 * uniqueBST structure
 */

typedef struct bstnode_t {
    int key;
    int jml;
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
    newNode->jml = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root,int value) {
    if (root == NULL) 
        return __bst__createNode(value);
    if (value < root->key){
        root->left = __bst__insert(root->left, value);
    }
    else if (value > root->key){
        root->right = __bst__insert(root->right, value);
    }
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

void __bst__inorder(BST *bst,BSTNode *root,PriorityQueue *p) {
    if (root) {
        __bst__inorder(bst,root->left,p);
        for(int i=1;i<=root->jml;i++){
            printf("%d ", root->key);
        }
        pqueue_push(p,root->key,findlevel(bst->_root,root->key),root->jml);
        __bst__inorder(bst,root->right,p);
    }
}

void __bst__postorder(BSTNode *root) {
    if (root) {
        __bst__postorder(root->left);
        __bst__postorder(root->right);
        for(int i=1;i<=root->jml;i++){
            printf("%d ", root->key);
        }
    }
}

void __bst__preorder(BSTNode *root) {
    if (root) {
        for(int i=1;i<=root->jml;i++){
            printf("%d ", root->key);
        }
        __bst__preorder(root->left);
        __bst__preorder(root->right);
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
    if(bst->_root!=NULL){
        BSTNode *temp = __bst__search(bst->_root, value);
        if (temp!= NULL && temp->key == value) {
            temp->jml++;
        }else{
            bst->_root = __bst__insert(bst->_root, value);
            bst->_size++;
        }
    }else{
         bst->_root = __bst__insert(NULL, value);
    }
}
/**
 * Binary search tree traversal
 * - Inorder
 * - Postorder
 * - Preorder
 */

void bst_inorder(BST *bst,PriorityQueue *p) {
    __bst__inorder(bst,bst->_root,p);
}

void bst_postorder(BST *bst) {
    __bst__postorder(bst->_root);
}

void bst_preorder(BST *bst) {
    __bst__preorder(bst->_root);
}

void allpque(PriorityQueue *p){
    PQueueNode *temp = p->_top;
    while(temp){
        for(int i=0;i<temp->jml;i++){
            printf("%d ",temp->data);
        }
        temp = temp->next;
    }
}
 
int main()
{
    int n;
    scanf("%d",&n);
    while(n--){
        BST set;
        bst_init(&set);
        PriorityQueue p;
        pqueue_init(&p);
        char num[20];
        while(1){
            scanf("%s",num);
            if(strcmp(num,"STOP")==0) break;
            int x = atoi(num);
            bst_insert(&set,x);
        }
        printf("Pre-order: ");
        bst_preorder(&set);
        printf("\n");
        printf("In-order: ");
        bst_inorder(&set,&p);
        printf("\n");
        printf("Post-order: ");
        bst_postorder(&set);
        printf("\n");
        printf("Level-order: ");
        allpque(&p);
        printf("\n");
    }
    return 0;
}