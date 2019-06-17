#include "stack.h"
status InitStack(PtrStack S)
{
    S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (S->base == NULL)
        return FAILED;
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}
status DestoryStack(SqStack S)
{
    free(S.base);
    return OK;
}
status ClearStack(SqStack S)
{
    S.top = S.base;
    S.stacksize = 0;
    return OK;
}
status  StackEmpty(SqStack S)
{
    if (S.top == S.base)
        return OK;
    else 
        return FAILED;
}
status push(PtrStack S,SElemType e)
{
    SElemType * nbase;
    //when stack is full!!!
    if (S->top == S->base + S->stacksize)
    {
        // enlarge the stack
        nbase=(SElemType *)realloc\
              (S->base,sizeof(SElemType)*STACKINCREMENT);
        if (!nbase)
            return FAILED;
        S->base = nbase; 
        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }
    *(S->top )= e;
    (S->top)++;
    return OK;
}
status pop(PtrStack S,SElemType *  e)
{
    if (S->top == S->base)
        return FALSE;
    (S->top)--;
   *e = *(S->top);
    return OK;
}
