//
//  queue.c
//  2020_12_25_01
//
//  Created by dulei on 2020/12/25.
//

#include "queue.h"
#include <stdlib.h>

void init_queue(pQueue **queue)
{
    (*queue) = (pQueue *)malloc(sizeof(pQueue));
    if ((*queue) == NULL) {
        exit(EXIT_FAILURE);
    }
    (*queue)->first = NULL;
    (*queue)->size = 0;
}

void add_queue(pQueue *queue, TYPE val, int priority)
{
    pQueueNode *node = (pQueueNode *)malloc(sizeof(pQueueNode));
    if (node == NULL) {
        exit(EXIT_FAILURE);
    }

    node->priority = priority;
    node->val = val;
    
    if (queue->size == 0 || queue->first == NULL) {
        node->next = NULL;
        queue->first = node;
        queue->size++;
        return;
    }
    
    pQueueNode **p_node = &queue->first;
    while (*p_node != NULL && node->priority > (*p_node)->priority) {
        p_node = &(*p_node)->next;
    }
    node->next = *p_node;
    *p_node = node;
    queue->size++;
}

TYPE get_queue(pQueue *queue)
{
    if (queue->size == 0 || queue->first == NULL) {
        return NULL;
    }
    
    pQueueNode *node = queue->first;
    queue->first = node->next;
    queue->size--;
    return node->val;
}
