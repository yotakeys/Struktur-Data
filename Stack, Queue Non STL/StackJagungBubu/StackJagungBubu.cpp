#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */

typedef struct queueNode_t {
    int data;
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
void queue_push(Queue *queue, int value);
int queue_pop(Queue *queue);

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

void queue_push(Queue *queue, int value)
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

int queue_pop(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        QueueNode *temp = queue->_front;
        queue->_front = queue->_front->next;
        int x = temp->data;
        free(temp);
        
        if (queue->_front == NULL)
            queue->_rear = NULL;
        queue->_size--;
        return x;
    }
}

int main(int argc, char const *argv[])
{
    int tc;
    scanf("%d",&tc);
    while(tc--){
        // Buat objek QueueArray
        Queue as;
        Queue bs;
        // PENTING! Jangan lupa diinisialisasi
        queue_init(&as);
        queue_init(&bs); 
        int p,a,b;
        scanf("%d %d %d",&p,&a,&b);
        int sa[a+1]={100000000},sb[b+1]={100000000};
        for(int i=1;i<=a;i++){
            int temp;
            scanf("%d",&temp);
            if(temp%2==0)queue_push(&as,temp);
            temp = temp+sa[i-1];
            if(temp<=p){
                sa[i]=temp;
            }
        }
        for(int i=1;i<=b;i++){
            int temp;
            scanf("%d",&temp);
            if(temp%2==1)queue_push(&bs,temp);
            temp = temp+sb[i-1];
            if(temp<=p){
                sb[i]=temp;
            }
        }
        int jagung =0;
        int max = 0;
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                int temp = sa[i]+sb[j];
                if(temp>p)break;
                if(temp>max){
                    max=temp;
                    jagung=i+j;
                }
            }
        }
        printf("%d jahong\n",jagung);
        if(jagung==0){
            printf("Keciaaan :<\n");
        }
        else if(jagung%2==0){
            if(queue_isEmpty(&as)){
                printf("Gak ada nih!\n");
            }
            else{
                printf("NUM =>");
                while(!queue_isEmpty(&as)){
                    printf("%d ",queue_pop(&as));
                }
                printf("\n");
            }
        }
        else{
            if(queue_isEmpty(&bs)){
                printf("Gak ada nih!\n");
            }
            else{
                printf("NUM =>");
                while(!queue_isEmpty(&bs)){
                    printf("%d ",queue_pop(&bs));
                }
                printf("\n");
            }
        }
    }

    return 0;
}