#include "buildTree.h"
int  inittree(Gtree * tree) // init the grammar tree;
{
    tree->tree = (BTnode *)malloc(sizeof(BTnode));
    tree->tree->leftchild = NULL;
    tree->tree->rightchild = NULL;
    tree->buildP = tree->tree;
    return 1;
}

int treeGdown(Gtree * tree,word_opt item)
{
    BTnode * fetch;
    fetch = (BTnode *)malloc(sizeof(BTnode)); //new two nodes
    fetch->data = item.value;
    (tree->buildP)->leftchild = fetch;
    fetch = (BTnode *)malloc(sizeof(BTnode));
    (tree->buildP)->rightchild = fetch;
    (tree->buildP)->data = item.opt.optchar;
    return 1;
}
int treeGup(Gtree * tree,word_opt item)
{
    BTnode * fetch;
    tree->buildP->data = item.value; //fill with num
    fetch = (BTnode *)malloc(sizeof(BTnode));
    fetch->data = item.opt.optchar;
    fetch->leftchild = tree->tree;
    tree->tree = fetch;
    fetch = (BTnode *)malloc(sizeof(BTnode));
    tree->tree->rightchild = fetch;//connect new nodes
    tree->buildP = fetch;//fresh the buildP position

    return 1;
}
int treeExtra(Gtree * tree,word_opt item)//when item is a end-item ,do the extra affair
{
    tree->buildP->data = item.value;
    return 1;
}
