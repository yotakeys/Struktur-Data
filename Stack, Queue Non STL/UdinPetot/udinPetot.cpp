#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* Struktur Node */

typedef struct datanode{
    char nama[10];
    int t2;
}data;

typedef struct queueNode_t {
    data data;
    struct queueNode_t *next;
} QueueNode;

/* Struktur ADT Queue */

typedef struct queue_t {
    QueueNode   *_front, 
                *_rear;
    unsigned _size;
} Queue;

/* Function prototype */

void queue_init(Queue *queue);
bool queue_isEmpty(Queue *queue);
void queue_push(Queue *queue, data value);
void queue_pop(Queue *queue);
void  queue_front(Queue *queue);
int cek(Queue *queue);

/* Function definition below */

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

void queue_pop(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        QueueNode *temp = queue->_front;
        queue->_front = queue->_front->next;
        printf("%s sudah selesai dilayani\n",temp->data.nama);
        free(temp);
        
        if (queue->_front == NULL)
            queue->_rear = NULL;
        queue->_size--;
    }
}

int queue_frontt2(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        return (queue->_front->data.t2);
    }
    return (int)0;
}

void queue_front(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        printf("%s sedang dilayani\n",queue->_front->data.nama);
    }
}

int cek(Queue *queue){
    QueueNode *temp = queue->_front;
    int total=0;
    while(temp){
        total+=temp->data.t2;
        temp=temp->next;
    }
    return total;
}

void mintanama(Queue *queue){
    QueueNode *temp = queue->_front;
    if(!temp){
        printf("KOSONG\n");
        return;
    }
    while(temp){
        printf("%s\n",temp->data.nama);
        temp=temp->next;
    }
}

void minfrontt2(Queue *q,int time){
    q->_front->data.t2-=time;
}

int main(int argc, char const *argv[])
{
    // Buat objek QueueArray
    Queue udin;
    Queue petot;
    // PENTING! Jangan lupa diinisialisasi
    queue_init(&udin);
    queue_init(&petot);
    int gilir=1;
    int ceks=0;
    data input;
    while(1){
        int t1;
        char cmd[10];
        scanf("%d %s",&t1,cmd);
        if(t1==0 && strcmp(cmd,"STOP")==0)break;
        else if(strcmp(cmd,"ANTRI")==0){
            int t2;
            scanf("%s %d",input.nama,&input.t2);
            if(gilir){
                if((cek(&udin)-t1)<60){
                    queue_push(&udin,input);
                    gilir=0;
                }
                else{
                    printf("%s tidak jadi mengantri\n",input.nama);
                }
            }
            else{
                if((cek(&petot)-t1)<60){
                    queue_push(&petot,input);
                    gilir=1;
                }
                else{
                    printf("%s tidak jadi mengantri\n",input.nama);
                }
            }

        }
        else{
            int waktu1 = t1-ceks;
            int waktu2=waktu1;
            ceks=t1;
            printf("UDIN\n");
            if(waktu1>=queue_frontt2(&udin)){
            while(waktu1>=queue_frontt2(&udin)){
                if(waktu1==0||queue_frontt2(&udin)==0)break;
                waktu1-=queue_frontt2(&udin);
                queue_pop(&udin);
            }
            }
            else{
                printf("Tidak ada yang selesai dilayani\n");
            }
            if(queue_isEmpty(&udin)){
                printf("Tidak ada yang sedang dilayani\n");
            }
            else{
                queue_front(&udin);
                minfrontt2(&udin,waktu1);
            }


            // petot

            printf("PETOT\n");
            if(waktu2>=queue_frontt2(&petot)){
            while(waktu2>=queue_frontt2(&petot)){
                if(waktu2==0 || queue_frontt2(&petot)==0)break;
                waktu2-=queue_frontt2(&petot);
                queue_pop(&petot);
            }
            }
            else{
                printf("Tidak ada yang selesai dilayani\n");
            }
            if(queue_isEmpty(&petot)){
                printf("Tidak ada yang sedang dilayani\n");
            }
            else{
                queue_front(&petot);
                minfrontt2(&petot,waktu2);
            }
        }
    }
    printf("UDIN\n");
    mintanama(&udin);
    printf("PETOT\n");
    mintanama(&petot);
    
    return 0;
}