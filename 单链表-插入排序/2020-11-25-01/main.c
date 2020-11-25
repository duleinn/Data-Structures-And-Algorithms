//
//  main.c
//  2020-11-25-01
//
//  Created by dulei on 2020/11/25.
//

#include <stdio.h>
#include <stdlib.h>

#define K_SIZE 10
#define TRUE 1
#define FALSE 0

typedef struct NODE {
    struct NODE *link;
    int value;
} Node;
void sll_insert_one(Node **rootp, int value);
void sll_insert_two(Node **linkp, int value);
void sll_insert_one(Node **rootp, int value) {
    Node *previous = NULL;
    Node *current = NULL;
    Node *new = NULL;
    
    current = *rootp;
    while (current != NULL && current->value < value) {
        previous = current;
        current = current->link;
    }
    
    new = malloc(sizeof(struct NODE));
    if (new == NULL) {
        exit(EXIT_FAILURE);
    }
    
    new->value = value;
    if (previous == NULL) {
        *rootp = new;
        new->link = current;
    } else {
        previous->link = new;
        new->link = current;
    }
}
void sll_insert_two(Node **linkp, int value) {
    Node *current = *linkp;
    Node *new = NULL;
    while (current != NULL && current->value < value) {
        linkp = &current->link;
        current = *linkp;
    }
    
    new = malloc(sizeof(struct NODE));
    if (new == NULL) {
        exit(EXIT_FAILURE);
    }
    
    *linkp = new;
    new->link = current;
    new->value = value;
}
int main(int argc, const char * argv[]) {
    Node *p_node = malloc(sizeof(struct NODE));
    if (p_node == NULL) {
        exit(EXIT_FAILURE);
    }
    
    p_node->value = 10;
    p_node->link = NULL;
    
    sll_insert_one(&p_node, 3);
    printf("test_func_one");
    sll_insert_two(&p_node, 2);
    printf("test_func_two");
    return 0;
}
