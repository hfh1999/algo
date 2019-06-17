#include <stdio.h>
#include <stdlib.h>
typedef struct BTnode{
    struct BTnode * leftchild;
    struct BTnode * rightchild;
    int ltag;
    int rtag;
    char data;
}BTnode;
BTnode * createTree(int level);
void showtree(BTnode * root);
