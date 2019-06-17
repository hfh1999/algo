// not so strong realization for a link stack
#include "stack2.h"  
status InitStack(LinkStack *S)
{
   S->top = NULL; 
   S->count = 0;
   return OK;
}
status push(LinkStack * S,SElemType e)
{
    Stacknode * fetch;
    fetch = (Stacknode *)malloc(sizeof(Stacknode));
    fetch->data = e;
    fetch->next = S->top;
    S->top = fetch;
    S->count ++;
    return OK;
}
status pop(LinkStack * S,SElemType * e)
{
    Stacknode * fetch;
    if (S->top == NULL)
        return FALSE;
    fetch = S->top;
    S->top = S->top->next;
    *e = fetch->data;
    free(fetch);
    S->count --;
    return OK;
}
status GetTop(LinkStack * S,SElemType * e)
{
    if(S->top == NULL)
        return FALSE;
    *e = S->top->data;
    return OK;
}
status ClearStack(LinkStack * S)
{
    Stacknode * fetch;
    fetch = S->top;
    while (fetch != NULL)//free every node
    {
        S->top =S->top->next;
        free(fetch);
        fetch = S->top;
    }
    return OK;
}
status StackEmpty(LinkStack * S)
{
    if (S->top == NULL)
        return TRUE;//this is empty
    else
        return FALSE;// that's not a empty stack
}
