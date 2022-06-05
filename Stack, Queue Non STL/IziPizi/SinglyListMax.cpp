#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */

typedef struct snode_t {
    int data;
    struct snode_t *next;
} SListNode;

/* Struktur ADT SinglyList */

typedef struct slist_t {
    unsigned _size;
    SListNode *_head;
} SinglyList;

/* DAFTAR FUNGSI YANG TERSEDIA */

void slist_init(SinglyList *list);
bool slist_isEmpty(SinglyList *list);
void slist_pushFront(SinglyList *list, int value);

/* Function definition below */

void slist_init(SinglyList *list) 
{
    list->_head = NULL;
    list->_size = 0;
}

bool slist_isEmpty(SinglyList *list) {
    return (list->_head == NULL);
}

void slist_pushFront(SinglyList *list, int value) 
{
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;

        if (slist_isEmpty(list)) newNode->next = NULL;
        else newNode->next = list->_head;
        list->_head = newNode;
    }
}

int carimax(SinglyList *kambing){
    int max = 0;
    SListNode *temp = kambing->_head;
    while(temp){
        if(temp->data>max){
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}

int main(int argc, char const *argv[])
{
    // Buat objek SinglyList
    SinglyList kumpulankambing;

    // PENTING! Jangan lupa diinisialisasi
    slist_init(&kumpulankambing);
    int n;
    scanf("%d",&n);
    if(n==0){
        printf("Oiya lupa gapunya kambing, hehe");
    }
    else{
        for(int i=0;i<n;i++){
            int smnt;
            scanf("%d",&smnt);
            slist_pushFront(&kumpulankambing,smnt);
        }
        int terberat = carimax(&kumpulankambing);
        printf("%d\n",terberat);
    }

 
    return 0;
}