#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *prev, *next;
}node;

typedef struct list{
        node  *front, *rear;
}list;

void init_dll(list*);
int isempty_dll(list);
void insertright_dll(list*, int);
void printlistLR_dll(list*);
void printlistRL_dll(list*);
int length_dll(list*);
void reverse_dll(list *);
void sort_dll(list*);
void insertsorted_dll(list *,int);
void removelist_dll(list*, int);
void freelist_dll(list*);
int search_dll(list *, int);
list listunion_dll(list, list);


void init_dll(list *l){
    l->front = NULL;
    l->rear = NULL;
}

int isempty_dll(list l){
    if(l.front == NULL)
        return 1;
    return 0;
}

void insertright_dll(list *l, int x){

    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->next = NULL;
    newnode->prev = NULL;
    newnode->data = x;

    if(isempty_dll(*l)){
        l->front = newnode;
        l->rear = newnode;
    }
    else{
        l->rear->next = newnode;
        newnode->prev = l->rear;
        l->rear = newnode;
    }
    return;
}

void printlistLR_dll(list *l){
    if(isempty_dll(*l)){
        return;
    }
    else{
        node *p;
        p = l->front;
        printf("\nFWD [");
        while(p != NULL){
            printf(" %d ", p->data);
            p = p->next;
        }
        printf("]");
    }
    return;
}

void printlistRL_dll(list *l){
    if(isempty_dll(*l)){
        return;
    }
    else{
        node *p;
        p = l->rear;
        printf("\nBWD [");
        while(p != NULL){
            printf(" %d ", p->data);
            p = p->prev;
        }
        printf("]");
    }
    return;
}

int length_dll(list *l){
    if(isempty_dll(*l)){
        return 0;
    }
    else{
        int x = 1;
        node *p;
        p = l->front;
        while(p->next != NULL){
            x++;
            p = p->next;
        }
        return x;
    }
}

void reverse_dll(list *l){
    if(isempty_dll(*l)){
        return;
    }
    else{
        int x = length_dll(l);
        int temp;
        node *p, *q;
        p = l->front;
        q = l->rear;
        if(x % 2 == 0){
            do{
                temp = p->data;
                p->data = q->data;
                q->data = temp;
                p = p->next;
                q = q->prev;
            }while(p->next != q);
        }
        else{
            while(p != q){
                temp = p->data;
                p->data = q->data;
                q->data = temp;
                p = p->next;
                q = q->prev;
            }
        }
        return;
    }
}

void sort_dll(list *l){
    node *p = l->front;
    int min = p->data;
    int exit = 1;
    while(exit){
        exit = 0;
        p = l->front;
        while(p->next != NULL){
            if(p->next->data < p->data){
                int temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
                exit = 1;
            }
            p = p->next;
        }
    }
    return;
}

void insertsort_dll(list *l,int x){
    insertright_dll(l, x);
    sort_dll(l);
    return;
}

void removelist_dll(list *l, int x){
    node *p = l->front;
    if(p->data == x){
        l->front = p->next;
        l->front->prev = NULL;
        free(p);
        return;
    }
    else if(l->rear->data == x){
        p = l->rear;
        l->rear = p->prev;
        l->rear->next = NULL;
        free(p);
        return;
    }
    else{
        p = l->front;
        while(p != NULL){
            if(p->data == x){
                p->prev->next = p->next;
                p->next->prev = p->prev;
                free(p);
            }
            p = p->next;
        }
        return;
    }
}

void freelist_dll(list *l){
    node *p = l->front->next;
    while(p != NULL){
        free(p->prev);
        p = p->next;
    }
    p = NULL;
    free(l->rear);
    l->front = NULL;
    l->rear = NULL;
    printf("The list is now empty");
    return;
}

int search_dll(list *l, int x){
    node *p = l->front;
    int index = 0;
    while(p != NULL){
        if(p->data == x){
            return index;
        }
        index++;
        p = p->next;
    }
    return -1;
}

list listunion_dll(list l1, list l2){
    l1.rear->next = l2.front;
    l2.front->prev = l1.rear;
    l1.rear = l2.rear;
    l2.front = l1.front;
    return l1;
}

void printlistRL(list *l){
    if(isempty_dll(*l)){
        return;
    }
    else{
        node *p;
        p = l->rear;
        printf("\nBWD [");
        while(p != NULL){
            printf(" %d ", p->data);
            p = p->prev;
        }
        printf("]");
    }
    return;
}

int length(list *l){
    if(isempty_dll(*l)){
        return 0;
    }
    else{
        int x = 1;
        node *p;
        p = l->front;
        while(p->next != NULL){
            x++;
            p = p->next;
        }
        return x;
    }
}

void reverse(list *l){
    if(isempty_dll(*l)){
        return;
    }
    else{
        int x = length(l);
        int temp;
        node *p, *q;
        p = l->front;
        q = l->rear;
        if(x % 2 == 0){
            do{
                temp = p->data;
                p->data = q->data;
                q->data = temp;
                p = p->next;
                q = q->prev;
            }while(p->next != q);
        }
        else{
            while(p != q){
                temp = p->data;
                p->data = q->data;
                q->data = temp;
                p = p->next;
                q = q->prev;
            }
        }
        return;
    }
}

void sort(list *l){
    node *p = l->front;
    int min = p->data;
    int exit = 1;
    while(exit){
        exit = 0;
        p = l->front;
        while(p->next != NULL){
            if(p->next->data < p->data){
                int temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
                exit = 1;
            }
            p = p->next;
        }
    }
    return;
}

void insertsorted(list *l,int x){
    insertright_dll(l, x);
    sort(l);
    return;
}

void removelist(list *l, int x){
    node *p = l->front;
    if(p->data == x){
        l->front = p->next;
        l->front->prev = NULL;
        free(p);
        return;
    }
    else if(l->rear->data == x){
        p = l->rear;
        l->rear = p->prev;
        l->rear->next = NULL;
        free(p);
        return;
    }
    else{
        p = l->front;
        while(p != NULL){
            if(p->data == x){
                p->prev->next = p->next;
                p->next->prev = p->prev;
                free(p);
            }
            p = p->next;
        }
        return;
    }
}

void freelist(list *l){
    node *p = l->front->next;
    while(p != NULL){
        free(p->prev);
        p = p->next;
    }
    p = NULL;
    free(l->rear);
    l->front = NULL;
    l->rear = NULL;
    printf("The list is now empty");
    return;
}

int search(list *l, int x){
    node *p = l->front;
    int index = 0;
    while(p != NULL){
        if(p->data == x){
            return index;
        }
        index++;
        p = p->next;
    }
    return -1;
}

list listunion(list l1, list l2){
    l1.rear->next = l2.front;
    l2.front->prev = l1.rear;
    l1.rear = l2.rear;
    l2.front = l1.front;
    return l1;
}