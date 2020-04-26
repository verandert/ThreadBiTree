#include "./bitree.h"

void InitStack(stack *S)
{
    StackNode *p;
    if((p = (StackNode *)malloc(sizeof(StackNode)))){
        p->next = NULL;
        S->base = S->top = p;
        S->length = 0;
    } else {
        printf("内存分配失败！");
        exit(-1);
    }
}

//摧毁栈
void DestroyStack(stack *S)
{
    StackNode *p, *q;
    q = S->top;
    while (q != S->base)
    {
        p = q; q = q->next;
        free(p);
    }
    free(q);//与清空栈的区别
    S->top = S->base = NULL;
}

//清空栈
void ClearStack(stack *S)
{
    StackNode *p, *q;
    q = S->top;
    while (q != S->base)
    {
        p = q; q = q->next;
        free(p);
    }
    S->top = S->base;   
    S->length = 0;
}

//栈是否为空
boolean EmptyStack(stack *S)
{
    if (S->base == S->top) {return true;}
    return fasle;
}

//进栈
void Push(stack *S, void* elemtype)
{
    StackNode *p;
    if((p = (StackNode *)malloc(sizeof(StackNode)))){
        S->top->data = elemtype;
        p->next = S->top;
        S->top = p;
        S->length++;
    } else
    {
        printf("堆分配失败");
        exit(-1);
    }
    
}

//出栈
void* Pop(stack *S)
{
    if (EmptyStack(S)) {printf("空栈"); exit(-1);}
    void* data;
    StackNode *p;
    p = S->top;
    data = p->next->data; S->top = S->top->next;
    free(p);
    S->length--;
    return data;
}

//取栈顶元素，但不出栈；
void* GetTop(stack *S)
{
    return S->top->next->data;
}

