//
//  huffman.c
//  2020_12_25_01
//
//  Created by dulei on 2020/12/25.
//

#include "huffman.h"
#include "queue.h"

#include <stdlib.h>
#include <string.h>

void _traverse_tree(hmNode *node, hlTable *table, int k, char *code)
{
    if (node->lchild == NULL && node->rchild == NULL) {
        code[k] = '\0';
        
        hlNode *hlnode = (hlNode *)malloc(sizeof(hlNode));
        if (hlnode == NULL) {
            exit(EXIT_FAILURE);
        }
        hlnode->symbol = node->symbol;
        hlnode->code = malloc(sizeof(char)*strlen(code)+1);
        strcpy(hlnode->code, code);
        hlnode->next = NULL;
        
        if (table->first == NULL) {
            table->first = hlnode;
            table->last = hlnode;
        } else {
            table->last->next = hlnode;
            table->last = hlnode;
        }
    }
    
    if (node->lchild != NULL) {
        code[k] = '0';
        _traverse_tree(node->lchild, table, k+1, code);
    }
    
    if (node->rchild != NULL) {
        code[k] = '1';
        _traverse_tree(node->rchild, table, k+1, code);
    }
}


hmTree *build_tree(const char *input)
{
    int *probability = (int *)malloc(sizeof(int)*256);
    if (probability == NULL) {
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < 256; i++) {
        probability[i] = 0;
    }
    for (int i = 0; input[i] != '\0'; i++) {
        probability[(unsigned char)input[i]]++;
    }
    
    pQueue *queue =  NULL;
    init_queue(&queue);
    
    for (int i = 0; i < 256; i++) {
        if (probability[i] != 0) {
            hmNode *node = (hmNode *)malloc(sizeof(hmNode));
            node->symbol = (char)i;
            node->lchild = NULL;
            node->rchild = NULL;
            
            add_queue(queue, node, probability[i]);
        }
    }
    
    free(probability);
    
    while (queue->size != 1) {
        int priority = queue->first->priority + queue->first->next->priority;
        
        TYPE left = get_queue(queue);
        TYPE right = get_queue(queue);
        
        hmNode *node = (hmNode *)malloc(sizeof(hmNode));
        if (node == NULL) {
            exit(EXIT_FAILURE);
        }
        node->lchild = left;
        node->rchild = right;
        add_queue(queue, node, priority);
    }
    
    hmTree *hltree = (hmTree *)malloc(sizeof(hmTree));
    if (hltree == NULL) {
        exit(EXIT_FAILURE);
    }
    hltree->root = get_queue(queue);
    return hltree;
}

hlTable *build_table(hmTree *tree)
{
    hlTable *table = (hlTable *)malloc(sizeof(hlTable));
    if (table == NULL) {
        exit(EXIT_FAILURE);
    }

    table->first = NULL;
    table->last = NULL;

    char code[256];
    _traverse_tree(tree->root, table, 0, code);
    return table;
}
