#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define FAILED 0
#define TRUE 1
#define FALSE 0
typedef int status;
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef char SElemType;
typedef struct {       // make a description for stack
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack,*PtrStack;
status InitStack(PtrStack S);
status DestoryStack(SqStack S);
status ClearStack(SqStack S);
status  StackEmpty(SqStack S);
status push(PtrStack S,SElemType e);
status pop(PtrStack S,SElemType * e);
