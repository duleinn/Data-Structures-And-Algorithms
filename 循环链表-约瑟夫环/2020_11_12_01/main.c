//
//  main.c
//  2020_11_12_01
//
//  Created by dulei on 2020/11/12.
//

#include <stdio.h>
#include <stdlib.h>

//约瑟夫环

struct Node {
    int data;
    struct Node *next;
};

void create_link_list(struct Node **linkList, int n);
void display_link_list(struct Node *linkList);
void create_link_list(struct Node **linkList, int n)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if (node == NULL) {
        exit(EXIT_FAILURE);
    }
    node->data = 1;
    node->next = node;
    *linkList = node;
    
    struct Node *temp = *linkList;
    for (int i = 0; i < n-1; i++) {
        struct Node *p_node = (struct Node *)malloc(sizeof(struct Node));
        if (p_node == NULL) {
            exit(EXIT_FAILURE);
        }
        
        p_node->next = *linkList;
        p_node->data = temp->data+1;
        temp->next = p_node;
        temp = p_node;
    }
}

void display_link_list(struct Node *linkList)
{
    struct Node *p_node = linkList;
    while (1) {
        printf("%d ", p_node->data);
        p_node = p_node->next;
        
        if (p_node == linkList) {
            printf("\n");
            return;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int n = 41;
    int m = 3;
    struct Node *linkList = NULL;
    create_link_list(&linkList, n);
    display_link_list(linkList);

    
    m = n % m;
    struct Node *node = linkList;
    while (node != node->next) {
        for (int i = 1; i < m; i++) {
            node = node->next;
        }
        
        struct Node *temp = node->next;
        node->next = temp->next;
        printf("%d->", temp->data);
        free(temp);
        
        node = node->next;
    }
    printf("%d\n", node->data);
    printf("Hello, World!\n");
    return 0;
}
