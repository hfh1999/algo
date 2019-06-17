#include <stdlib.h>
#define OK 1
#define FAILED 0
#define TRUE 1
#define FALSE 0
typedef int status;
/////////////////////////////////
typedef char SElemType;
typedef struct Stacknode {
    SElemType data;
    struct Stacknode * next;
}Stacknode,*NodePtr;
typedef struct {
    NodePtr top;
    int count;// the current nodes
}LinkStack;
status InitStack(LinkStack * S);
status DestoryStack(LinkStack * S);
status ClearStack(LinkStack * S);
status StackEmpty(LinkStack * S);
status GetTop(LinkStack * S,SElemType * e );
status push(LinkStack * S,SElemType e);
status pop(LinkStack * S,SElemType * e);
