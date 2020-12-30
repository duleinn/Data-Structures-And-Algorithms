//
//  queue.h
//  2020_12_25_01
//
//  Created by dulei on 2020/12/25.
//

#ifndef queue_h
#define queue_h

#include <stdio.h>
#include "huffman.h"

typedef hmNode *TYPE;

typedef struct _pQueueNode {
    TYPE val;
    unsigned int priority;
    struct _pQueueNode *next;
} pQueueNode;

typedef struct _pQueue {
    pQueueNode *first;
    unsigned int size;
} pQueue;

void init_queue(pQueue **queue);
void add_queue(pQueue *queue, TYPE val, int priority);
TYPE get_queue(pQueue *queue);

#endif /* queue_h */
