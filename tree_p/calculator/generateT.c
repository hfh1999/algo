#include <stdio.h>
#include <string.h>
#include "tree.h"
#include "getWord_Opt.h"
#define MAX 100
int main (void)
{
    
}
void grammarTree(char * str)
{
    char expr[MAX];
    strcpy(expr,str);

    BTnode * bulidP;
    BTnode * tree;
    word_opt * item;
    Expr *  expression  = initW_O(str); // create a struct "W_O"
    while( getW_O(expression,item))
    {
        static int prev = 0; // previous priority
        if (item->opt.priority >= prev )
            treeGdown(tree,buildP,item);
        else if(item->opt.priority == NONE)
            treeExtra(tree,bulidP,item);
        else
            treeGup(tree,buildP,item);
        prev = item->opt.priority;
    }
}
