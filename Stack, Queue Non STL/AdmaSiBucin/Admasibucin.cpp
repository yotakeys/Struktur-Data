#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */

typedef struct datanode{
    int kode;
    int harga;
}data;

typedef struct pqueueNode_t {
    data data;
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
void pqueue_push(PriorityQueue *pqueue, data value);
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

void pqueue_push(PriorityQueue *pqueue, data value)
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode = \
        (PQueueNode*) malloc (sizeof(PQueueNode));
    newNode->data = value;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }

    if (value.harga < pqueue->_top->data.harga) {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else {
        while ( temp->next != NULL && 
                temp->next->data.harga < value.harga)
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
        return pqueue->_top->data.kode;
    else return 0;
}

int main(int argc, char const *argv[])
{
    PriorityQueue myPque;
    pqueue_init(&myPque);
    int n;
    scanf("%d",&n);
    data barang;
    while(n--){
        scanf("%d %d",&barang.kode,&barang.harga);
        pqueue_push(&myPque,barang);
    }
    int cari;
    n=0;
    scanf("%d",&cari);
    while(!pqueue_isEmpty(&myPque)){
        if(pqueue_top(&myPque)==cari){
            printf("%d",n);
            return 0;
        }
        n++;
        pqueue_pop(&myPque);
    }
    printf("Barangnya gak ada beb");

    return 0;
}