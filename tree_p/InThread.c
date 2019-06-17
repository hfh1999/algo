#include <stdio.h>
#include "include/tree.h"
#define VISIT(DATA) printf("%d :",DATA)
void InThread(BTnode * intree,BTnode ** pre);
void search(BTnode * intree);
int main (void)
{
    BTnode * tree = createTree(3);
    showtree(tree);

    //InThread
    BTnode * Pre = NULL; // the first
    if(tree != NULL)
    {
        InThread(tree,&Pre);
        Pre->rightchild = NULL;
        Pre->rtag = 1;
    }

    //visit all node
    search(tree);
}
void InThread(BTnode * intree,BTnode ** pre)
{
    if(intree == NULL)
        return;
    InThread(intree->leftchild,pre);
    if(intree->leftchild == NULL)
    {
        intree->leftchild = *pre;
        intree->ltag = 1;
    }
    if(intree->rightchild == NULL && (*pre)->rtag == 1 )
    {
        (*pre)->rightchild = intree;
        intree->ltag = 1;
    }
        *pre = intree; // move the pre pointer;
    InThread(intree->rightchild,pre);
}
void search(BTnode * intree)
{
        
}
