//
//  main.c
//  2020_11_16_01
//
//  Created by dulei on 2020/11/16.
//

#include <stdio.h>
#include <stdlib.h>

struct LatinNode {
    int data;
    struct LatinNode *next;
};

void create_latin_list(struct LatinNode **latinList, int n);
void display_latin_matrix(struct LatinNode *latinList);

void create_latin_list(struct LatinNode **latinList, int n)
{
    struct LatinNode *latin = (struct LatinNode*)malloc(sizeof(struct LatinNode));
    if (latin == NULL) {
        exit(EXIT_FAILURE);
    }
    latin->data = 1;
    latin->next = latin;
    *latinList = latin;
    
    struct LatinNode *last = latin;
    for (int i = 0; i < n-1; i++) {
        struct LatinNode *node = (struct LatinNode *)malloc(sizeof(struct LatinNode));
        if (node == NULL) {
            exit(EXIT_FAILURE);
        }
        node->data = last->data+1;
        node->next = *latinList;
        last->next = node;
        
        last = node;
    }
}

void display_latin_matrix(struct LatinNode *latinList)
{
    struct LatinNode *matrix_x = latinList;
    struct LatinNode *matrix_y = latinList;
    
    do {
        matrix_x = matrix_y;
        do {
            printf("%d ", matrix_x->data);
            matrix_x = matrix_x->next;
        } while (matrix_x != matrix_y);
        
        printf("\n");
        matrix_y = matrix_y->next;
    } while (matrix_y != latinList);
}

int main(int argc, const char * argv[]) {
    struct LatinNode *latinList = NULL;
    create_latin_list(&latinList, 10);
    display_latin_matrix(latinList);
    printf("Hello, World!\n");
    return 0;
}
