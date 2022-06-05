#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */

typedef struct datanode{
    int masuk;
    int keluar;
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
int pqueue_push(PriorityQueue *pqueue, data value);
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

int pqueue_push(PriorityQueue *pqueue, data value)
{
    while(!pqueue_isEmpty(pqueue)){
        if(pqueue_top(pqueue)<=value.masuk){
            pqueue_pop(pqueue);
        }
        else break;
    }
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode = \
        (PQueueNode*) malloc (sizeof(PQueueNode));
    newNode->data = value;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue)) {
        pqueue->_top = newNode;
        pqueue->_size++;
        return 0;
    }

    if (value.keluar < pqueue->_top->data.keluar) {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else {
        while ( temp->next != NULL && 
                temp->next->data.keluar < value.keluar)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    pqueue->_size++;
    if(newNode->next!=NULL && newNode->data.keluar==newNode->next->data.keluar)return 1;
    return 0;
}

void pqueue_pop(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue)) {
        PQueueNode *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        pqueue->_size--;
        free(temp);
    }
}

int pqueue_top(PriorityQueue *pqueue) {
    if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->data.keluar;
    else return 0;
}

unsigned stack_size(PriorityQueue *stack) {
    return stack->_size;
}

int main(int argc, char const *argv[])
{
    // Buat objek Stack
    while(1){
        PriorityQueue myStack;

        // PENTING! Jangan lupa diinisialisasi
        pqueue_init(&myStack);
        data input;
        int n,k;
        scanf("%d %d",&n,&k);
        int cek=1;
        if(n==0 && k==0){
            break;
        }
        while(n--){
            scanf("%d %d",&input.masuk,&input.keluar);
            if(input.masuk==input.keluar)cek=0;
            if(pqueue_push(&myStack,input))cek=0;
            if(stack_size(&myStack)>k)cek=0;
        }
        if(cek)printf("Bisa boss\n");
        else printf("Gimana nih boss\n");
    }

    return 0;
}