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
    {
        fetch = (BTnode *)malloc(sizeof(BTnode));
        fetch->data = item.value;
        (*buildP)->leftchild = fetch;
        (*buildP)->data = item.opt.optchar;
        
        *buildP = (*buildP)->rightchild;
    }
    else // build the down-er tree(high priority)
    {
        fetch = (BTnode *)malloc(sizeof(BTnode));
        fetch->data = item.opt.optchar;
        fetch->rightchild = NULL;
        fetch->leftchild = NULL;
        (*buildP)->rightchild = fetch;
        *buildP = fetch;

        fetch = (BTnode *)malloc(sizeof(BTnode));
        fetch->data = item.value;
        (*buildP)->leftchild = fetch;
        
        *buildP = (*buildP)->rightchild;
    }

}
