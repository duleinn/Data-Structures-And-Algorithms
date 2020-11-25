//
//  main.c
//  2020-11-25-02
//
//  Created by dulei on 2020/11/25.
//

#include <stdio.h>
#include <stdlib.h>

#define K_SIZE 10
#define TRUE 1
#define FALSE 0

typedef struct NODE {
    struct NODE *fwd;
    struct NODE *bwd;
    int value;
} Node;
int dll_insert(Node *rootp, int value) {
    Node *this;
    Node *next;
    Node *newNode;
    
    for (this = rootp; (next = this->fwd) != NULL; this = next) {
        if (next->value == value) {
            break;
        }
        if (next->value > value) {
            break;
        }
    }
    
    newNode = malloc(sizeof(struct NODE));
    if (newNode == NULL) {
        exit(EXIT_FAILURE);
    }
    newNode->value = value;
    
    if (next != NULL) {
        if (this != rootp) {
            newNode->fwd = next;
            newNode->bwd = this;
            this->fwd = newNode;
            next->bwd = newNode;
        } else {
            newNode->fwd = next;
            newNode->bwd = NULL;
            rootp->fwd = newNode;
            next->bwd = newNode;
        }
    } else {
        if (this != rootp) {
            newNode->fwd = NULL;
            newNode->bwd = this;
            this->fwd = newNode;
            rootp->bwd = newNode;
        } else {
            newNode->fwd = NULL;
            newNode->bwd = NULL;
            rootp->fwd = newNode;
            rootp->bwd = newNode;
        }
    }
    
    return TRUE;
}
int main(int argc, const char * argv[]) {
    return 0;
}
