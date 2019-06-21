#include "tree.h"
#include "getWord_Opt.h"
#include <stdlib.h>
typedef struct Gtree{
    BTnode * tree;
    BTnode * buildP;
}Gtree;
int inittree(Gtree * tree);
int treeGdown(Gtree * tree,word_opt item);
int treeExtra(Gtree * tree,word_opt item);
int treeGup(Gtree * tree,word_opt item);
