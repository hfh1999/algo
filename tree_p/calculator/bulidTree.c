#include "tree.h"
#include "getWord_Opt.h"
#include <stdlib.h>
BTnode * inittree(void);
int treeGdown(BTnode * tree,BTnode * buildP,word_opt item);
int treeExtra(BTnode * tree,BTnode * buildP,word_opt item);
int treeGup(BTnode * tree,BTnode * buildP,word_opt item);
BTnode * inittree(void) // init the grammar tree;
{
    BTnode * retTree;
    retTree = (BTnode *)malloc(sizeof(BTnode));
    retTree->leftchild = NULL;
    retTree->rightchild = NULL;
    return retTree;
}

int treeGdown(BTnode * tree,BTnode ** buildP,word_opt item)
{
    BTnode * fetch;
    if( *buildP != NULL  )
        fetch = (BTnode *)malloc(sizeof(BTnode));
        fetch->itemp=(word_opt *)malloc(sizeof(word_opt));
        *()

}
