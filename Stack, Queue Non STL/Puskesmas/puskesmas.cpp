#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

char penyakits[4][30]={"flu","maag","diare","pusingkebanyakantugas"};
int bnykttl[4]={0};
int caripenyakit(char x[30]){
    for(int i=0;i<4;i++){
        if(!strcmp(x,penyakits[i]))return i;
    }
}

typedef struct datapasien{
    int penyakit;
    char nama[6];
}data;

typedef struct pqueueNode_t {
    data data;
    struct pqueueNode_t *next;
} PQueueNode;

typedef struct pqueue_t {
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;

typedef struct queueNode_t {
    data data;
    struct queueNode_t *next;
} QueueNode;

typedef struct queue_t {
    QueueNode   *_front, 
                *_rear;
    unsigned _size;
} Queue;

void queue_init(Queue *queue);
bool queue_isEmpty(Queue *queue);
void queue_push(Queue *queue, data value);
void queue_pop(Queue *queue,PriorityQueue *pqueue);
int  queue_size(Queue *queue);
void pqueue_init(PriorityQueue *pqueue);
bool pqueue_isEmpty(PriorityQueue *pqueue);
void pqueue_push(PriorityQueue *pqueue, data value);
data pqueue_pop(PriorityQueue *pqueue);

void queue_init(Queue *queue)
{
    queue->_size = 0;
    queue->_front = NULL;
    queue->_rear = NULL;
}

bool queue_isEmpty(Queue *queue) {
    return (queue->_front == NULL && queue->_rear == NULL);
}

void queue_push(Queue *queue, data value)
{
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (newNode) {
        queue->_size++;
        newNode->data = value;
        newNode->next = NULL;
        
        if (queue_isEmpty(queue))                 
            queue->_front = queue->_rear = newNode;
        else {
            queue->_rear->next = newNode;
            queue->_rear = newNode;
        }
    }
}

void queue_pop(Queue *queue,PriorityQueue *pqueue)
{
    if (!queue_isEmpty(queue)) {
        QueueNode *temp = queue->_front;
        queue->_front = queue->_front->next;
        printf("Pasien atas nama %s sudah selesai konsultasi mengenai %s\n",temp->data.nama,penyakits[temp->data.penyakit]);
        free(temp);
        
        if (queue->_front == NULL)
            queue->_rear = NULL;
        queue->_size--;
        if(!pqueue_isEmpty(pqueue)){
            data x = pqueue_pop(pqueue);
            printf("Pasien atas nama %s masuk dari antrian\n",x.nama);
            queue_push(queue,x);
        }
    }
}

int queue_size(Queue *queue) {
    return queue->_size;
}

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

    if (value.penyakit > pqueue->_top->data.penyakit) {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else {
        while ( temp->next != NULL && 
                temp->next->data.penyakit >= value.penyakit)
                {
                int cek =1;
                    if(temp->next->data.penyakit == value.penyakit){
                        for(int i=0;i<6;i++){
                            if (value.nama[i] > temp->next->data.nama[i]){
                                cek=0;
                                break;
                            }else if (value.nama[i] < temp->next->data.nama[i]){
                                break;
                                }
                        }
                    }
                    if(cek){
                        temp = temp->next;
                    }
                    else break;
                }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    pqueue->_size++;
}

data pqueue_pop(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue)) {
        PQueueNode *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        data temp2 = temp->data;
        free(temp);
        pqueue->_size--;
        return temp2;
    }
}

int main(int argc, char const *argv[])
{
    PriorityQueue myPque;
    Queue dokter;

    pqueue_init(&myPque);
    queue_init(&dokter);
    int n;
    scanf("%d",&n);
    int code;
    while(scanf("%d",&code)!=EOF){
        if(code==1){
            data input;
            char penyakitin[30];
            scanf("%s %s",input.nama,penyakitin);
            input.penyakit = caripenyakit(penyakitin);
            bnykttl[input.penyakit]++;
            printf("Pasien atas nama %s terdaftar ke database\n",input.nama);
            if(queue_size(&dokter)<n){
                printf("Pasien atas nama %s langsung masuk\n",input.nama);
                queue_push(&dokter,input);
            }
            else{
                printf("Pasien atas nama %s mengantri\n",input.nama);
                pqueue_push(&myPque,input);
            }
        }
        else{
            queue_pop(&dokter,&myPque);
        }
    }
    for(int i =0;i<4;i++){
        if(!bnykttl[i])continue;
        printf("%s: %d\n",penyakits[i],bnykttl[i]);
    }
    
    return 0;
}