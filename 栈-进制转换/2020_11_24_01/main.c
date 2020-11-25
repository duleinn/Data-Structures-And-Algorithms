//
//  main.c
//  2020_11_24_01
//
//  Created by dulei on 2020/11/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define OK 1
#define ERROR 0
#define K_INIT_SIZE 10

typedef char ElemType;
typedef struct sqStack {
    ElemType *top;
    ElemType *base;
    int statckSize;
} SqStack;

int init_stack(SqStack *stack);
int push_stack(SqStack *stack, ElemType e);
int pop_stack(SqStack *stack, ElemType *e);
long length_stack(SqStack *stack);
void clear_stack(SqStack *stack);
void destory_stack(SqStack *stack);

int init_stack(SqStack *stack)
{
    stack->base = (ElemType *)malloc(K_INIT_SIZE * sizeof(ElemType));
    if (stack->base == NULL) {
        exit(EXIT_FAILURE);
    }
    stack->top = stack->base;
    stack->statckSize = K_INIT_SIZE;
    return OK;
}

int push_stack(SqStack *stack, ElemType e)
{
    if (stack->top - stack->base >= stack->statckSize) {
        stack->base = realloc(stack->base, (stack->statckSize + 10) * sizeof(ElemType));
        if (stack->base == NULL) {
            exit(EXIT_FAILURE);
        }
        stack->statckSize = stack->statckSize+10;
    }
    
    *(stack->top) = e;
    stack->top++;
    return OK;
}

int pop_stack(SqStack *stack, ElemType *e)
{
    if (stack->top == stack->base) {
        return ERROR;
    }
    
    *e = *--(stack->top);
    return OK;
}

long length_stack(SqStack *stack)
{
    return stack->top-stack->base;
}

void clear_stack(SqStack *stack)
{
    stack->top = stack->base;
    stack->statckSize = 0;
}

void destory_stack(SqStack *stack)
{
    free(stack->base);
    stack->base = NULL;
    stack->top = NULL;
    stack->statckSize = 0;
}


int main(int argc, const char * argv[]) {
    
    SqStack stack;
    init_stack(&stack);
    
    printf("请输入二进制数\n");
    char ch;
    scanf("%c", &ch);
    while (ch != '\n') {
        push_stack(&stack, ch);
        scanf("%c", &ch);
    }
    
    int sum = 0;
    for (int i = 0; i < length_stack(&stack); i++) {
        ElemType e;
        pop_stack(&stack, &e);
        sum += (e-48) * pow(2, i);
    }
    printf("十进制总和：%d\n", sum);
    return 0;
}
