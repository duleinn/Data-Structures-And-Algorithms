//
//  main.c
//  2020_11_11_01
//
//  Created by dulei on 2020/11/11.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct CLinkList {
    int data;
    struct CLinkList *next;
} CLinkList;

void create_link_list(CLinkList **linkList);
void insert_link_list(CLinkList **linkList);
int search_link_list(CLinkList *linkList, int value);
void display_link_lish(CLinkList *linkList);

void create_link_list(CLinkList **linkList)
{
    printf("请输入结点的值:（0）代表输入完成\n");
    while (1) {
        int value;
        scanf("%d", &value);
        if (value == 0) {
            return;
        }
        
        if (*linkList == NULL) {
            struct CLinkList *node = (struct CLinkList *)malloc(sizeof(struct CLinkList));
            if (node == NULL) {
                exit(EXIT_FAILURE);
            }
            node->data = value;
            node->next = node;
            *linkList = node;
        } else {
            struct CLinkList *p_node = *linkList;
            while (p_node->next != *linkList) {
                p_node = p_node->next;
            }
            
            struct CLinkList *node = (struct CLinkList *)malloc(sizeof(struct CLinkList));
            if (node == NULL) {
                exit(EXIT_FAILURE);
            }
            node->data = value;
            node->next = *linkList;
            p_node->next = node;
        }
    }
}

void insert_link_list(CLinkList **linkList)
{
    CLinkList *p_node = *linkList;
    while (p_node->next != *linkList) {
        p_node = p_node->next;
    }
    
    struct CLinkList *node = (struct CLinkList *)malloc(sizeof(struct CLinkList));
    if (node == NULL) {
        exit(EXIT_FAILURE);
    }
    node->data = 100;
    node->next = *linkList;
    p_node->next = node;
}

int search_link_list(CLinkList *linkList, int value)
{
    struct CLinkList *p_node = linkList;
    
    int i = 1;
    while (p_node->data != value) {
        p_node = p_node->next;
        i++;
        
        if (p_node == linkList) {
            break;
        }
    }
    
    return p_node == linkList ? 0 : i;
}

void display_link_lish(CLinkList *linkList)
{
    struct CLinkList *p_node = linkList;
    do {
        printf("%d ", p_node->data);
        p_node = p_node->next;
    } while (p_node != linkList);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    struct CLinkList *linklist = NULL;
    create_link_list(&linklist);
    insert_link_list(&linklist);
    int res = search_link_list(linklist, 100);
    display_link_lish(linklist);
    printf("Hello, World!\n");
    return 0;
}
