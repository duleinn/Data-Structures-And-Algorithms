//
//  huffman.h
//  2020_12_25_01
//
//  Created by dulei on 2020/12/25.
//

#ifndef huffman_h
#define huffman_h

#include <stdio.h>

typedef struct _hmNode {
    char symbol;
    struct _hmNode *lchild;
    struct _hmNode *rchild;
} hmNode;

typedef struct _hlTree {
    hmNode *root;
} hmTree;

typedef struct _hlNode {
    char symbol;
    char *code;
    struct _hlNode *next;
} hlNode;

typedef struct _hlTable {
    struct _hlNode *first;
    struct _hlNode *last;
} hlTable;

hmTree *build_tree(const char *input);
hlTable *build_table(hmTree *tree);

#endif /* huffman_h */
