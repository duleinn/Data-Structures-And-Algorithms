//
//  main.c
//  2020-11-26-01
//
//  Created by dulei on 2020/11/26.
//

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int ElemType;

struct StackNode {
    ElemType data;
    struct StackNode *next;
};

struct LinkStack {
    struct StackNode *top;
    int count;
};

int push_link_stack(struct LinkStack *stack, ElemType e);
int pop_link_stack(struct LinkStack *stack, ElemType  *e);
int stack_length(struct LinkStack *stack);

int push_link_stack(struct LinkStack *stack, ElemType e)
{
    struct StackNode *node = (struct StackNode *)malloc(sizeof(struct StackNode));
    if (node == NULL) {
        exit(EXIT_FAILURE);
    }
    node->data = e;
    node->next = stack->top;
    stack->top = node;
    stack->count++;
    return OK;
}

int pop_link_stack(struct LinkStack *stack, ElemType  *e)
{
    if (stack_length(stack) == 0) {
        return ERROR;
    }
    
    *e = stack->top->data;
    struct StackNode *node = stack->top;
    stack->top = stack->top->next;
    free(node);
    stack->count--;
    return OK;
}

int stack_length(struct LinkStack *stack)
{
    return stack->count;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    struct LinkStack linkStack;
    push_link_stack(&linkStack, 1);
    push_link_stack(&linkStack, 3);
    push_link_stack(&linkStack, 5);
    printf("------------------------------\n");
    ElemType e;
    pop_link_stack(&linkStack, &e);
    return 0;
}
