//
//  main.c
//  2020_12_02_01
//
//  Created by dulei on 2020/12/2.
//

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define Error 0

typedef int ElemType;
typedef int Status;

struct QNode {
    ElemType data;
    struct QNode *next;
};

typedef struct {
    struct QNode *front;
    struct QNode *rear;
} LinkQueue;

Status init_queue(LinkQueue **queue);
Status insert_queue(LinkQueue *queue, ElemType e);
Status delete_queue(LinkQueue *queue, ElemType *e);
Status destory_queue(LinkQueue *queue);

Status init_queue(LinkQueue **queue)
{
    *queue = (LinkQueue *)malloc(sizeof(LinkQueue));
    if (*queue == NULL) {
        exit(EXIT_FAILURE);
    }
    
    (*queue)->front = NULL;
    (*queue)->rear = NULL;
    return OK;
}

Status insert_queue(LinkQueue *queue, ElemType e)
{
    struct QNode *q_node = (struct QNode *)malloc(sizeof(struct QNode));
    if (q_node == NULL) {
        exit(EXIT_FAILURE);
    }
    q_node->data = e;
    q_node->next = NULL;
    
    if (queue->front == NULL) {
        queue->front = q_node;
    }
    
    if (queue->rear == NULL) {
        queue->rear = q_node;
    } else {
        queue->rear->next = q_node;
        queue->rear = q_node;
    }
    
    return OK;
}

Status delete_queue(LinkQueue *queue, ElemType *e)
{
    if (queue->front == queue->rear) {
        return Error;
    }
    
    struct QNode *p = queue->front;
    *e = p->data;
    queue->front = p->next;
    if (p == queue->rear) {
        queue->rear = queue->front;
    }
    free(p);
    return OK;
}

Status destory_queue(LinkQueue *queue)
{
    while (queue->front != NULL) {
        struct QNode *temp  = queue->front;
        queue->front = temp->next;
        free(temp);
    }
    queue->front = queue->rear = NULL;
    return OK;
}

int main(int argc, const char * argv[]) {
    LinkQueue *link_queue = NULL;
    init_queue(&link_queue);
    insert_queue(link_queue, 1);
    insert_queue(link_queue, 2);
    insert_queue(link_queue, 3);
    
    ElemType e;
    delete_queue(link_queue, &e);
    delete_queue(link_queue, &e);
    
    destory_queue(link_queue);
    printf("Hello, World!\n");
    return 0;
}
