//
//  main.c
//  2020_11_05_01
//
//  Created by dulei on 2020/11/5.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

typedef struct Node {
    ElemType data;
    struct Node *next;
} Node;

typedef struct Node *LinkList;

Status initList(LinkList *L);
Status createListHead(LinkList *L, int n);
Status createListTail(LinkList *L, int n);
Status getElem(LinkList L, int n, ElemType *e);
Status insertList(LinkList *L, int n, ElemType e);
Status insertListV2(LinkList *L, int n, ElemType e);
Status deleteList(LinkList *L, int n, ElemType *e);
Status deleteListV2(LinkList *L, int n, ElemType *e);
Status clearList(LinkList *L);

Status initList(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(struct Node));
    if (*L == NULL) {
        exit(EXIT_FAILURE);
    }
    
    (*L)->next = NULL;
    (*L)->data = 0;
    return OK;
}

Status createListHead(LinkList *L, int n)
{
    *L = (LinkList)malloc(sizeof(struct Node));
    (*L)->next = NULL;
    
    srand((unsigned int)time(0));
    for (int i = 0; i < n; i++) {
        LinkList node = (LinkList)malloc(sizeof(struct Node));
        if (node == NULL) {
            exit(EXIT_FAILURE);
        }
        node->data = rand()%100+1;
        node->next = (*L)->next;
        (*L)->next = node;
        (*L)->data++;
    }
    return OK;
}

Status createListTail(LinkList *L, int n)
{
    *L = (LinkList)malloc(sizeof(struct Node));
    if (*L == NULL) {
        exit(EXIT_FAILURE);
    }
    (*L)->next = NULL;
    
    srand((unsigned int)time(0));
    LinkList r = *L;
    for (int i = 0; i < n; i++) {
        LinkList node = (LinkList)malloc(sizeof(struct Node));
        if (node == NULL) {
            exit(EXIT_FAILURE);
        }
        node->data = rand()%100+1;
        r->next = node;
        r = node;
        (*L)->data++;
    }
    r->next = NULL;
    return OK;
}

Status getElem(LinkList l, int n, ElemType *e)
{
    if (n < 1 || n > l->data) {
        return ERROR;
    }
    
    int i = 1;
    LinkList node = l->next;
    while (node != NULL && i < n) {
        node = node->next;
        i++;
    }
    if (node == NULL) {
        return ERROR;
    }
    
    *e = node->data;
    return OK;
}

Status insertList(LinkList *L, int n, ElemType e)
{
    if (n < 1 || n > (*L)->data) {
        return ERROR;
    }
    
    LinkList p_node = *L;
    int i = 1;
    while (p_node != NULL && i < n) {
        p_node = p_node->next;
        i++;
    }
    
    LinkList node = (LinkList)malloc(sizeof(struct Node));
    if (node == NULL) {
        exit(EXIT_FAILURE);
    }
    node->data = e;
    
    node->next = p_node->next;
    p_node->next = node;
    (*L)->data++;
    return OK;
}

Status insertListV2(LinkList *L, int n, ElemType e)
{
    if (n < 1 || n > (*L)->data) {
        return ERROR;
    }
    
    LinkList *p_node = &(*L)->next;
    int i = 1;
    while (*p_node != NULL && i < n) {
        p_node = &(*p_node)->next;
        i++;
    }
    
    LinkList node = (LinkList)malloc(sizeof(struct Node));
    if (node == NULL) {
        exit(EXIT_FAILURE);
    }
    node->data = e;
    node->next = *p_node;
    *p_node = node;
    (*L)->data++;
    return OK;
}

Status deleteList(LinkList *L, int n, ElemType *e)
{
    if (n < 1 || n > (*L)->data) {
        return ERROR;
    }
    
    int i = 1;
    LinkList temp = *L;
    while (temp != NULL && i < n) {
        temp = temp->next;
        i++;
    }
    
    LinkList delNode = temp->next;
    *e = delNode->data;
    
    temp->next = delNode->next;
    free(delNode);
    (*L)->data--;
    return OK;
}

Status deleteListV2(LinkList *L, int n, ElemType *e)
{
    if (n < 1 || n > (*L)->data) {
        return ERROR;
    }
    
    LinkList *p_node = &(*L)->next;
    int i = 1;
    while (i < n) {
        p_node = &(*p_node)->next;
        i++;
    }
    
    LinkList delNode = *p_node;
    *e = delNode->data;
    *p_node = (*p_node)->next;
    free(delNode);
    (*L)->data--;
    return OK;
}

Status clearList(LinkList *L)
{
    LinkList delNode = (*L)->next;
    for (int i = 0; i < (*L)->data; i++) {
        LinkList temp = delNode;
        delNode = delNode->next;
        free(temp);
    }
    
    (*L)->next = NULL;
    (*L)->data = 0;
    return OK;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    LinkList L;
    createListHead(&L, 5);
    
//    ElemType e;
//    getElem(L, 1, &e);
    
//    insertList(&L, 1, 89);
//    insertListV2(&L, 0, 100);
    
    insertListV2(&L, 5, 150);
    
//    ElemType e;
//    deleteList(&L, 5, &e);
    
    ElemType e;
    deleteListV2(&L, 1, &e);
    
    clearList(&L);
    printf("Hello, World!\n");
    return 0;
}
