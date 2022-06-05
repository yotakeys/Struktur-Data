#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */

typedef struct dnode_t {
    int data;
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

DListNode* __dlist_createNode(int value);
void deq_init(Deque *deque);
bool deq_isEmpty(Deque *deque);
void deq_pushFront(Deque *deque, int value);
void deq_pushBack(Deque *deque, int value);
int  deq_front(Deque *deque);
int  deq_front2(Deque *deque);
void deq_popFront(Deque *deque);

/* Definisi Fungsi */

DListNode* __dlist_createNode(int value)
{
    DListNode *newNode = \
        (DListNode*) malloc (sizeof(DListNode));
    
    if (!newNode) return NULL;
    newNode->data = value;
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

void deq_pushFront(Deque *deque, int value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        deque->_size++;
        if (deq_isEmpty(deque)) {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }

        newNode->next = deque->_head;
        deque->_head->prev = newNode;
        deque->_head = newNode;
    }
}

void deq_pushBack(Deque *deque, int value)
{
    DListNode *newNode = __dlist_createNode(value);
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

int deq_front(Deque *deque) {
    if (!deq_isEmpty(deque)) {
        return (deque->_head->data);
    }
    return 0;
}

int deq_front2(Deque *deque) {
    if (!deq_isEmpty(deque)) {
        return (deque->_head->next->data);
    }
    return 0;
}

void deq_popFront(Deque *deque)
{
    if (!deq_isEmpty(deque)) {
        DListNode *temp = deque->_head;
        if (deque->_head == deque->_tail) {
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else {
            deque->_head = deque->_head->next;
            deque->_head->prev = NULL;
            free(temp);
        }
        deque->_size--;
    }
}

int max(int x,int y){
    if(x>y)return x;
    return y;
}

int min(int x,int y){
    if(x<y)return x;
    return y;
}

int main(int argc, char const *argv[])
{
    // Buat objek QueueArray
    Deque myQueue;

    // PENTING! Jangan lupa diinisialisasi
    deq_init(&myQueue);
    int maxi=0;
    int n,k;
    int saved=1;
    int stored[100000][2];
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        maxi=max(maxi,temp);
        deq_pushBack(&myQueue,temp);
    }
    stored[saved][0]=deq_front(&myQueue);
    stored[saved][1]=deq_front2(&myQueue);
    int solved=0;
    while(k--){
        int it;
        scanf("%d",&it);
        if(!solved){
        if(it>saved){
        int tem=saved;
        for(int i=0;i<it-tem;i++){
            int st,da;
            st=deq_front(&myQueue);
            deq_popFront(&myQueue);
            da=deq_front(&myQueue);
            deq_popFront(&myQueue);
            deq_pushBack(&myQueue,min(st,da));
            deq_pushFront(&myQueue,max(st,da));
            saved++;
            stored[saved][0]=deq_front(&myQueue);
            stored[saved][1]=deq_front2(&myQueue);
            if(st==maxi){
                solved=1;
                break;
            }
        }
        if(solved){
            if(!deq_isEmpty(&myQueue)){
            deq_popFront(&myQueue);
            saved--;
            int temp=saved;
            for(int i=0;i<n-1;i++){
                temp++;
                stored[temp][0]=maxi;
                stored[temp][1]=deq_front(&myQueue);
                deq_popFront(&myQueue);
            }
        }}
        }
        }
        if(it>saved){
            it = (it-saved)%(n-1)+saved;
        }
        printf("%d %d\n",stored[it][0],stored[it][1]);
    }
    return 0;
}