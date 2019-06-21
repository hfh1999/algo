#include <stdio.h>
#include <string.h>
#include "getWord_Opt.h"
#include "buildTree.h"
#define MAX_EXPR 100
int main (void)
{
    
}
void grammarTree(char * str)
{
    char expr[MAX_EXPR];
    strcpy(expr,str);

    Gtree tree;
    word_opt * item;
    Expr *  expression  = initW_O(str); // create a struct "W_O"
    while( getW_O(expression,item))
    {
        static int prev = 0; // previous priority
        BTnode * tree;
        if(inittree(&tree) == 0)
            printf("error:Init grammar tree.\n");
        BTnode * buildP = tree; //buildP is a tool pointer;

        if (item->opt.priority >= prev )
            treeGdown(&tree,*item);
        else if(item->opt.priority == NONE)
            treeExtra(&tree,*item);
        else
            treeGup(&tree,*item);
        prev = item->opt.priority;
    }
}
