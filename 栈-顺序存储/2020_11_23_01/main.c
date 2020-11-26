//
//  main.c
//  2020_11_23_01
//
//  Created by dulei on 2020/11/23.
//

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define K_INIT_SIZE 100

typedef int ElemType;

typedef struct {
    ElemType *top;
    ElemType *base;
    int stackSize;
} sqStack;

int init_sql_stack(sqStack *stack);
int push_sql_stack(sqStack *stack, ElemType e);
int pop_sql_stack(sqStack *stack, ElemType *e);
int clear_sql_stack(sqStack *stack);
int destroy_sql_stack(sqStack *stack);

int init_sql_stack(sqStack *stack)
{
    stack->base = (ElemType *)malloc(K_INIT_SIZE * sizeof(ElemType));
    if (stack->base == NULL) {
        exit(EXIT_FAILURE);
    }
    stack->top = stack->base;
    stack->stackSize = K_INIT_SIZE;
    return TRUE;
}

int push_sql_stack(sqStack *stack, ElemType e)
{
    if (stack->top - stack->base >= stack->stackSize) {
        stack->base = (ElemType *)realloc(stack->base, (K_INIT_SIZE+10) * sizeof(ElemType));
        if (stack->base == NULL) {
            exit(EXIT_FAILURE);
        }
        stack->stackSize = stack->stackSize+10;
    }
    *(stack->top) = e;
    stack->top++;
    return TRUE;
}

int pop_sql_stack(sqStack *stack, ElemType *e)
{
    if (stack->top == stack->base) {
        return FALSE;
    }
    *e = *--(stack->top);
    return TRUE;
}

int clear_sql_stack(sqStack *stack)
{
    stack->top = stack->base;
    return TRUE;
}

int destroy_sql_stack(sqStack *stack)
{
    free(stack->base);
    stack->base = NULL;
    stack->top = NULL;
    stack->stackSize = 0;
    return TRUE;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    sqStack stack;
    init_sql_stack(&stack);
    push_sql_stack(&stack, 1012);
    push_sql_stack(&stack, 1013);
    
    ElemType e;
    pop_sql_stack(&stack, &e);
    
    push_sql_stack(&stack, 1011);
    
    destroy_sql_stack(&stack);
    printf("Hello, World!\n");
    return 0;
}
